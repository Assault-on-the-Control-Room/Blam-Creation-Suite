#include "opusframework-private-pch.h"

bool GameLauncher::s_gameManuallyKilled = false;
bool GameLauncher::s_hideWindowOnStartup = false;
GameLauncher::CurrentState GameLauncher::s_currentState = GameLauncher::CurrentState::eInactive;
GameLauncher::GameLaunchCallback* GameLauncher::s_gameLaunchCallback = nullptr;
GameLauncher::GameShutdownCallback* GameLauncher::s_gameShutdownCallback;
GameInterface* GameLauncher::s_pCurrentGameInterface = nullptr;
IGameEngine* GameLauncher::s_pHaloReachEngine = nullptr;
char* GameLauncher::s_pTerminationFlag = nullptr;
e_map_id g_LaunchMapId = _map_id_ff45_corvette;
e_game_mode g_LaunchGameMode = _game_mode_survival;
e_campaign_difficulty_level g_LaunchCampaignDifficultyLevel = _campaign_difficulty_level_normal;
const char* g_LaunchHopperGameVariant = nullptr;
const char* g_LaunchHopperMapVariant = nullptr;

HaloGameID GameLauncher::GetCurrentGameID()
{
	if (s_pCurrentGameInterface)
	{
		return s_pCurrentGameInterface->GetHaloGameID();
	}
	return HaloGameID::NotSet;
}

void GameLauncher::LaunchGame()
{
	// make sure the runtime information is in a valid state before trying to run another game
	assert(s_pHaloReachEngine == nullptr);
	assert(s_pCurrentGameInterface != nullptr);
	assert(s_pCurrentGameInterface->GetHaloGameID() != HaloGameID::NotSet);

	// #TODO: Game specific version of this!!!
	if (s_gameLaunchCallback != nullptr)
	{
		s_gameLaunchCallback(s_pCurrentGameInterface->GetHaloGameID());
	}

	__int64 createGameEngineResult = s_pCurrentGameInterface->CreateGameEngine(&s_pHaloReachEngine);
	assert(s_pHaloReachEngine);

	GameContext gameContext = {};
	SetupGameContext(gameContext);

	s_pHaloReachEngine->InitGraphics(GameRender::s_pDevice, GameRender::s_pDeviceContext, GameRender::s_pSwapChain, GameRender::s_pSwapChain);

	IGameEngineHost gameEngineHost = IGameEngineHost();

	// useful for testing if the gameenginehostcallback vftable is correct or not
	static constexpr bool kBogusGameEngineHostCallbackVFT = false;
	if constexpr (kBogusGameEngineHostCallbackVFT)
	{
		void*& pGameEngineHostVftable = *reinterpret_cast<void**>(&gameEngineHost);
		static char data[sizeof(void*) * 1024] = {};
		memset(data, -1, sizeof(data));
		static constexpr size_t kNumBytesToCopyFromExistingVFT = 0;
		memcpy(data, pGameEngineHostVftable, kNumBytesToCopyFromExistingVFT);
		pGameEngineHostVftable = data;
	}

	HANDLE hMainGameThread = s_pHaloReachEngine->InitThread(&gameEngineHost, &gameContext);

	CustomWindow::SetPostMessageThreadId(hMainGameThread);

	while (true)
	{
		switch (s_currentState)
		{
		case GameLauncher::CurrentState::eWaitingToRun:
		case GameLauncher::CurrentState::eRunning:
		case GameLauncher::CurrentState::eInactive:
			Update();
			continue;
		}
		break;
	}

	WaitForSingleObject(hMainGameThread, INFINITE);

	if (s_gameShutdownCallback)
	{
		s_gameShutdownCallback(s_pCurrentGameInterface->GetHaloGameID());
	}

	s_pHaloReachEngine->Destructor();
	//free(pHaloReachEngine);
	//free(pHaloReachDataAccess);

	// reset runtime information after we've destroyed the engine
	s_pCurrentGameInterface = nullptr;
	s_pHaloReachEngine = nullptr;
}

typedef BOOL(EnumWindowsFunc)(WNDENUMPROC lpEnumFunc, LPARAM lParam);
EnumWindowsFunc* EnumWindowsPointer = nullptr;
BOOL EnumWindowsHook(
	WNDENUMPROC lpEnumFunc,
	LPARAM      lParam
)
{
	static thread_local WNDENUMPROC s_lpEnumFunc = nullptr;
	static thread_local bool s_processedCustomWindow = false;

	assert(s_lpEnumFunc == nullptr);
	assert(EnumWindowsPointer != nullptr);

	s_lpEnumFunc = lpEnumFunc;

	auto callback = [](HWND hWnd, LPARAM lParam) {

		bool isExcluded = false;
		isExcluded |= hWnd == GetConsoleWindow();
		isExcluded |= hWnd == SplashScreen::GetWindowHandle();

		if (hWnd == CustomWindow::GetWindowHandle())
		{
			s_processedCustomWindow = true;
		}

		if (isExcluded)
		{
			return TRUE;
		}

		return s_lpEnumFunc(hWnd, lParam);
	};

	auto result = EnumWindowsPointer(callback, lParam);
	s_lpEnumFunc = nullptr;
	return result;
}

void GameLauncher::Init(HINSTANCE hInstance, LPSTR lpCmdLine)
{

#ifdef _DEBUG
	bool isDebug = true;
#else
	bool isDebug = false;
#endif

	if (GameLauncher::HasCommandLineArg("-hidesplash"))
	{
		SplashScreen::Create();
		s_hideWindowOnStartup = true;
	}

	if ((GameLauncher::HasCommandLineArg("-showconsole") || isDebug) && !GameLauncher::HasCommandLineArg("-hideconsole"))
	{
		AllocConsole();
		FILE* pStdOut = freopen("CONOUT$", "w", stdout);
		assert(pStdOut);
		SetConsoleTitleA("Opus");
	}

	if (GameLauncher::HasCommandLineArg("-waitfordebugger"))
	{
		WriteLineVerbose("Waiting for debugger to attach");
		while (!IsDebuggerPresent()) { Sleep(1); }
		WriteLineVerbose("Debugger attached");
	}

	static bool patchedEnumWindows = false;
	if (!patchedEnumWindows)
	{
		init_detours();
		create_dll_hook("USER32.dll", "EnumWindows", EnumWindowsHook, EnumWindowsPointer);
		patchedEnumWindows = true;
		end_detours();
	}

	LoadSettings(); // #TODO: Replace with UI
	CustomWindow::Init();
	GameRender::Init(hInstance);
	InitSockets();

	{
		float horizontalSensitivity = Settings::ReadFloatValue(SettingsSection::Controls, "HorizontalSensitivity", 1.0f);
		float verticalSensitivity = Settings::ReadFloatValue(SettingsSection::Controls, "VerticalSensitivity", 1.0f);
		MouseInput::SetSensitivity(horizontalSensitivity, verticalSensitivity);
	}

	CustomWindow::SetOnDestroyCallback(GameLauncher::Terminate);
}

void GameLauncher::Deinit()
{
	DeinitSockets();
	GameRender::Deinit();
	CustomWindow::Deinit();

	// when debugging make sure to manually quit the game
	// this keeps the console window open
#if _DEBUG
	while (s_gameManuallyKilled == false)
	{
		if (GetAsyncKeyState(VK_F11))
		{
			s_gameManuallyKilled = true;
		}
	}
#endif
}

void GameLauncher::RegisterTerminationValue(char& rTerminationReference)
{
	s_pTerminationFlag = &rTerminationReference;
}

bool GameLauncher::HasCommandLineArg(const char* pArgument)
{
	return strstr(GetCommandLineA(), pArgument) != 0;
}

void GameLauncher::Terminate()
{
	if (s_pTerminationFlag != nullptr)
	{
		*s_pTerminationFlag = true;
		s_gameManuallyKilled = true;
	}
}

void GameLauncher::RegisterGameLaunchCallback(HaloGameID gameID, GameLaunchCallback gameLaunchCallback)
{
	// #TODO: Multiple game versions!!!
	s_gameLaunchCallback = gameLaunchCallback;
}

void GameLauncher::RegisterGameShutdownCallback(HaloGameID gameID, GameShutdownCallback gameShutdownCallback)
{
	s_gameShutdownCallback = gameShutdownCallback;
}

void GameLauncher::LoadSettings()
{
	char pLaunchMapNameBuffer[256] = {};
	Settings::ReadStringValue(SettingsSection::Launch, "Map", pLaunchMapNameBuffer, sizeof(pLaunchMapNameBuffer), "ff45_corvette");
	g_LaunchMapId = string_to_map_id(pLaunchMapNameBuffer);

	char pLaunchGameModeBuffer[256] = {};
	Settings::ReadStringValue(SettingsSection::Launch, "GameMode", pLaunchGameModeBuffer, sizeof(pLaunchGameModeBuffer), "");
	g_LaunchGameMode = string_to_game_mode(pLaunchGameModeBuffer);

	char pLaunchCampaignDifficultyLevelBuffer[256] = {};
	Settings::ReadStringValue(SettingsSection::Launch, "DifficultyLevel", pLaunchCampaignDifficultyLevelBuffer, sizeof(pLaunchCampaignDifficultyLevelBuffer), "normal");
	g_LaunchCampaignDifficultyLevel = string_to_campaign_difficulty_level(pLaunchCampaignDifficultyLevelBuffer);

	const char* pDefaultHopperGameVariant = "";
	switch (g_LaunchGameMode)
	{
		break;
	case _game_mode_campaign:
		pDefaultHopperGameVariant = "campaign_default_054";
		break;
	case _game_mode_multiplayer:
		pDefaultHopperGameVariant = "slayer_054";
		break;
	case _game_mode_survival:
		pDefaultHopperGameVariant = "ff_firefight_054";
		break;
	}

	// #TODO: This must persist outside of the read
	static char pLaunchHopperGameVariantBuffer[256] = {};
	uint32_t LaunchHopperGameVariantLength = Settings::ReadStringValue(SettingsSection::Launch, "HopperGameVariant", pLaunchHopperGameVariantBuffer, sizeof(pLaunchHopperGameVariantBuffer), pDefaultHopperGameVariant);
	if (LaunchHopperGameVariantLength > 0)
	{
		g_LaunchHopperGameVariant = pLaunchHopperGameVariantBuffer;
	}
	else
	{
		g_LaunchHopperGameVariant = nullptr;
	}

	// #TODO: This must persist outside of the read
	static char pLaunchHopperMapVariantBuffer[256] = {};
	uint32_t LaunchHopperMapVariantLength = Settings::ReadStringValue(SettingsSection::Launch, "HopperMapVariant", pLaunchHopperMapVariantBuffer, sizeof(pLaunchHopperMapVariantBuffer), "");
	if (LaunchHopperMapVariantLength > 0)
	{
		g_LaunchHopperMapVariant = pLaunchHopperMapVariantBuffer;
	}
	else
	{
		g_LaunchHopperMapVariant = nullptr;
	}
}

void CreateSwapchainAndBackbuffer(IDXGISwapChain*& pSwapchain, ID3D11RenderTargetView*& pBackBuffer)
{
	if (!pSwapchain)
	{
		GameRender::CreateSwapchain(pSwapchain);
	}

	// get the address of the back buffer
	ID3D11Texture2D* pBackBufferTexture;
	pSwapchain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBufferTexture);

	// use the back buffer address to create the render target
	GameRender::s_pDevice->CreateRenderTargetView(pBackBufferTexture, NULL, &pBackBuffer);
	pBackBufferTexture->Release();

	// set the render target as the back buffer
	GameRender::s_pDeviceContext->OMSetRenderTargets(1, &pBackBuffer, NULL);
}




ID3D11RenderTargetView* s_pMenuBackBuffer;    // global declaration

int GameLauncher::Run(HINSTANCE hInstance, LPSTR lpCmdLine, GameInterface& rGameInterface)
{
	s_pCurrentGameInterface = &rGameInterface;
	SetState(CurrentState::eMainMenu);

	GameLauncher::Init(hInstance, lpCmdLine);
	//GameLauncher::LaunchGame("haloreach.dll");

	CreateSwapchainAndBackbuffer(GameRender::s_pSwapChain, s_pMenuBackBuffer);

	while (true)
	{
		SplashScreen::Destroy();
		Update();
		Render();
	}
	GameLauncher::Deinit();
	return 0;
}

void GameLauncher::SetupGameContext(GameContext& rGameContext)
{
	rGameContext.pGameHandle = GetModuleHandle("HaloReach.dll");
	char byte2B678Data[] = { 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
	memcpy(rGameContext.byte2B678, byte2B678Data, sizeof(byte2B678Data)); // what the hell is this?

	{
		uint64_t SquadAddress = 0x2F385E2E95D4F33E;
		uint64_t HostAddress = 0xDEADBEEFDEADBEEF;
		uint64_t ClientAddress = 0xCAFEBABECAFEBABE;

		{
			int ipv4_address = 0;
			inet_pton(AF_INET, "10.255.0.2", &ipv4_address);
			ipv4_address = htonl(ipv4_address);
			ClientAddress = ipv4_address;
		}
		{
			int ipv4_address = 0;
			inet_pton(AF_INET, "10.255.0.1", &ipv4_address);
			ipv4_address = htonl(ipv4_address);
			HostAddress = ipv4_address;
		}

		rGameContext.SessionInfo.SquadAddress = SquadAddress; // this is set
		rGameContext.SessionInfo.IsHost = !strstr(GetCommandLineA(), "-client"); // if client, is false

		rGameContext.GameMode = g_LaunchGameMode;



		int playerCount = GameLauncher::HasCommandLineArg("-multiplayer") ? 2 : 1;
		rGameContext.SessionInfo.PeerIdentifierCount = playerCount;
		rGameContext.SessionInfo.SessionMembership.Count = playerCount;

		rGameContext.SessionInfo.PeerIdentifiers[0] = 0;
		rGameContext.SessionInfo.PeerIdentifiers[1] = 1;
		{
			rGameContext.SessionInfo.SessionMembership.Members[0].MachineIdentifier = 0;
			rGameContext.SessionInfo.SessionMembership.Members[0].Team = 0;
			rGameContext.SessionInfo.SessionMembership.Members[0].PlayerAssignedTeam = 0;
			rGameContext.SessionInfo.SessionMembership.Members[0].SecureAddress = HostAddress;
		}
		if (rGameContext.SessionInfo.SessionMembership.Count > 1)
		{
			rGameContext.SessionInfo.SessionMembership.Members[1].MachineIdentifier = 0;
			rGameContext.SessionInfo.SessionMembership.Members[1].Team = 0;
			rGameContext.SessionInfo.SessionMembership.Members[1].PlayerAssignedTeam = 0;
			rGameContext.SessionInfo.SessionMembership.Members[1].SecureAddress = ClientAddress;
		}
		if (rGameContext.SessionInfo.SessionMembership.Count > 2)
		{
			FATAL_ERROR("Too many people need to add more data");
		}


		struct sockaddr_in sa;
		inet_pton(AF_INET, "88.98.242.148", &sa.sin_addr);
		struct sockaddr_in sa2;
		inet_pton(AF_INET, "5.67.168.178", &sa2.sin_addr);
		GameContext context1;
		GameContext context2;
		FILE* pPlayer1 = fopen("gamecontext-player1.bin", "rb");
		FILE* pPlayer2 = fopen("gamecontext-player2.bin", "rb");
		assert(pPlayer1);
		assert(pPlayer2);
		fread(&context1, 1, sizeof(context1), pPlayer1);
		fread(&context2, 1, sizeof(context2), pPlayer2);
		static_assert(sizeof(context1) == 178248, "shit");



		if (rGameContext.SessionInfo.IsHost)
		{
			NetworkManager::CreateServerConnection();

			SetConsoleTitleA("Opus | HOST");

			rGameContext.MapId = g_LaunchMapId;
			rGameContext.CampaignDifficultyLevel = g_LaunchCampaignDifficultyLevel;

			rGameContext.SessionInfo = context1.SessionInfo;

			//LoadHopperGameVariant(s_pCurrentGameInterface->GetDataAccess(), g_LaunchHopperGameVariant, *reinterpret_cast<s_game_variant*>(rGameContext.GameVariantBuffer));
			//LoadHopperMapVariant(s_pCurrentGameInterface->GetDataAccess(), g_LaunchHopperMapVariant, *reinterpret_cast<s_map_variant*>(rGameContext.MapVariantBuffer));
			//LoadPreviousGamestate("gamestate.hdr", rGameContext);

			//rGameContext.SessionInfo.LocalMachineID = HostAddress; // this is set
			//rGameContext.SessionInfo.HostAddress = HostAddress;
		}
		else
		{
			NetworkManager::CreateClientConnection();

			rGameContext.SessionInfo = context2.SessionInfo;

			//rGameContext.SessionInfo.LocalMachineID = ClientAddress; // this is set
			//rGameContext.SessionInfo.HostAddress = HostAddress;
		}

	}
}

void GameLauncher::SetState(CurrentState state)
{
	if (s_currentState == state)
	{
		return;
	}

	s_currentState = state;

	switch (state)
	{
	case CurrentState::eInactive:
		break;
	case CurrentState::eMainMenu:
		DebugUI::RegisterCallback(DrawMenu);
		break;
	case CurrentState::eWaitingToRun:
		break;
	case CurrentState::eRunning:
	{
		DebugUI::UnregisterCallback(DrawMenu);
		DebugUI::Hide();
		LaunchGame();
	}
	break;
	case CurrentState::eFinished:
		break;
	}
}

void GameLauncher::Update()
{
	CustomWindow::Update();

	switch (GameLauncher::s_currentState)
	{
	case CurrentState::eRunning:

		break;
	case CurrentState::eWaitingToRun:
		SetState(CurrentState::eRunning);
		break;
	case CurrentState::eInactive:
	case CurrentState::eFinished:
		SetState(CurrentState::eMainMenu);
		break;
	case CurrentState::eMainMenu:
		MouseInput::SetMode(MouseMode::UI);
		DebugUI::Show();
		break;
	}

	Sleep(1); // prevent 100% CPU
}

void GameLauncher::Render()
{
	BeginRender();
	DebugUI::RenderFrame();
	EndRender();
}

void GameLauncher::BeginRender()
{
	// clear the back buffer to a deep blue
	float clearColor[] = { 0.0f, 0.2f, 0.4f, 1.0f };
	GameRender::s_pDeviceContext->ClearRenderTargetView(s_pMenuBackBuffer, clearColor);
}

void GameLauncher::EndRender()
{
	GameRender::s_pSwapChain->Present(0, 0);
}

void GameLauncher::SelectGameMode()
{
	const char* s_pCurrentGameModeStr = game_mode_to_string(g_LaunchGameMode);
	if (ImGui::BeginCombo("GameMode", s_pCurrentGameModeStr))
	{
		for (int i = 1; i < e_game_mode::k_number_of_game_modes; i++)
		{
			const char* pGameModeStr = game_mode_to_string(static_cast<e_game_mode>(i));
			if (pGameModeStr)
			{
				bool selected = s_pCurrentGameModeStr == pGameModeStr;
				if (ImGui::Selectable(pGameModeStr, &selected))
				{
					g_LaunchGameMode = static_cast<e_game_mode>(i);
					Settings::WriteStringValue(SettingsSection::Launch, "GameMode", (char*)game_mode_to_string(g_LaunchGameMode));
				}
			}
		}

		ImGui::EndCombo();
	}
}

static size_t get_file_size(FILE* pFile)
{
	assert(pFile);
	fseek(pFile, 0, SEEK_END);
	size_t variantSize = ftell(pFile);
	fseek(pFile, 0L, SEEK_SET);
	return variantSize;
}

static void read_file_to_buffer(FILE* pFile, char* pBuffer, size_t length, long offset = 0L)
{
	assert(pFile);
	fseek(pFile, offset, SEEK_SET);

	size_t totalBytesRead = 0;
	do
	{
		size_t bytesToRead = length - totalBytesRead;
		fseek(pFile, offset + static_cast<long>(totalBytesRead), SEEK_SET);
		size_t bytesRead = fread(pBuffer + totalBytesRead, 1, bytesToRead, pFile);
		totalBytesRead += bytesRead;
	} while (totalBytesRead < length);

}

template<typename T>
void file_read_type(char* pFilename, T& value, long offset)
{
	FILE* pFile = fopen(pFilename, "rb");
	if (pFile)
	{
		read_file_to_buffer(pFile, (char*)&value, sizeof(T), offset);
		fclose(pFile);
	}
}

void file_read_string_long(char* pFilename, std::string* value, size_t length, long offset)
{
	FILE* pFile = fopen(pFilename, "rb");
	if (pFile)
	{
		char* pBuffer = (char*)alloca(length);
		memset(pBuffer, 0x00, length);
		read_file_to_buffer(pFile, pBuffer, length, offset);
		fclose(pFile);

		for (size_t i = 0; i < length; i++)
		{
			char* cur = &pBuffer[i];
			if (cur[0] && !cur[1])
			{
				*value += cur;
			}
		}
	}
}

int read_map_info(const char* pName, std::string* name, std::string* desc)
{
	char pFilename[MAX_PATH] = {};
	sprintf(pFilename, "maps\\info\\%s.mapinfo", pName);
	pFilename[MAX_PATH - 1] = 0;

	file_read_string_long(pFilename, name, 64, 0x44);
	file_read_string_long(pFilename, desc, 256, 0x344);

	int mapId = -1;
	file_read_type(pFilename, mapId, 0x3C);

	return ((mapId >> 24) & 0xff) | ((mapId << 8) & 0xff0000) | ((mapId >> 8) & 0xff00) | ((mapId << 24) & 0xff000000);
}

void GameLauncher::SelectMap()
{
	std::string curName, curDesc;
	read_map_info(map_id_to_string(g_LaunchMapId), &curName, &curDesc);

	const char* pCurrentMapStr = curName.c_str();
	if (ImGui::BeginCombo("Map", pCurrentMapStr))
	{
		for (e_map_id mapId = e_map_id::_map_id_m05; mapId < k_number_of_map_ids; reinterpret_cast<int&>(mapId)++)
		{
			std::string name, desc;
			read_map_info(map_id_to_string(mapId), &name, &desc);

			const char* pMapStr = name.c_str();
			if (pMapStr[0])
			{
				bool selected = pMapStr == pCurrentMapStr;
				if (ImGui::Selectable(pMapStr, &selected))
				{
					g_LaunchMapId = static_cast<e_map_id>(mapId);
					Settings::WriteStringValue(SettingsSection::Launch, "Map", (char*)map_id_to_string(g_LaunchMapId));
				}
			}
		}

		ImGui::EndCombo();
	}
}

void GameLauncher::SelectDifficulty()
{
	if (g_LaunchGameMode == e_game_mode::_game_mode_campaign || g_LaunchGameMode == e_game_mode::_game_mode_survival)
	{
		const char *pCurrentDifficultyStr = campaign_difficulty_level_to_string(g_LaunchCampaignDifficultyLevel);
		if (ImGui::BeginCombo("Difficulty", pCurrentDifficultyStr))
		{
			for (e_campaign_difficulty_level difficulty = e_campaign_difficulty_level::_campaign_difficulty_level_easy; difficulty < k_number_of_campaign_difficulty_levels; reinterpret_cast<int &>(difficulty)++)
			{
				const char *pDifficultyStr = campaign_difficulty_level_to_string(difficulty);
				if (pDifficultyStr)
				{
					bool selected = pDifficultyStr == pCurrentDifficultyStr;
					if (ImGui::Selectable(pDifficultyStr, &selected))
					{
						g_LaunchCampaignDifficultyLevel = static_cast<e_campaign_difficulty_level>(difficulty);
						Settings::WriteStringValue(SettingsSection::Launch, "DifficultyLevel", (char *)campaign_difficulty_level_to_string(g_LaunchCampaignDifficultyLevel));
					}
				}
			}

			ImGui::EndCombo();
		}
	}
}

struct s_path_array
{
	char StringsBuffer[2024][MAX_PATH];
	int Count = 0;

	const char* LastDirectory = "";

	void Reset()
	{
		ZeroMemory(StringsBuffer, sizeof(StringsBuffer));
		Count = 0;
	}

	void Add(LPCSTR pPath)
	{
		assert(Count < _countof(StringsBuffer));
		strcpy(StringsBuffer[Count++], pPath);
	}

	void AddFrom(LPCSTR pDir, bool recursive = false)
	{
		if (LastDirectory == pDir)
			return;

		if (recursive)
		{
			for (const auto& dirEntry : std::filesystem::recursive_directory_iterator(pDir))
				Add(dirEntry.path().filename().replace_extension().string().c_str());
		}
		else
		{
			for (const auto& dirEntry : std::filesystem::directory_iterator(pDir))
				Add(dirEntry.path().filename().replace_extension().string().c_str());
		}

		LastDirectory = pDir;
	}

	const char* At(int index)
	{
		return index < Count ? StringsBuffer[index] : "";
	}
};

void get_variant_info(char*pBuffer, std::string *name, std::string *desc)
{
	for (size_t i = 0; i < 256; i++)
	{
		char* nameCur = &pBuffer[0x80 + i];
		if (nameCur[0] && !nameCur[1])
		{
			*name += nameCur;
		}
		char* descCur = &pBuffer[0x180 + i];
		if (descCur[0] && !descCur[1])
		{
			*desc += descCur;
		}
	}
}

e_game_engine_type read_game_variant(const char* pName, std::string* name, std::string* desc)
{
	static s_game_variant gameVariant;
	GameLauncher::LoadHopperGameVariant(GameLauncher::s_pCurrentGameInterface->GetDataAccess(), pName, gameVariant, false);

	e_game_engine_type result = gameVariant.game_engine_index;

	get_variant_info(gameVariant.game_engine_variant.data, name, desc);

	if (!(*name).c_str()[0])
	{
		*name = pName;
	}

	return result;
}

int read_map_variant(const char* pName, std::string *name, std::string *desc)
{
	static s_map_variant mapVariant;
	GameLauncher::LoadHopperMapVariant(GameLauncher::s_pCurrentGameInterface->GetDataAccess(), pName, mapVariant, false);

	int result = *reinterpret_cast<int *>(&mapVariant.data[0x2C]);
	get_variant_info(mapVariant.data, name, desc);

	return result;
}

void GameLauncher::SelectGameVariant()
{
	static s_path_array files = s_path_array();
	files.AddFrom("hopper_game_variants");

	bool isCampaign = g_LaunchGameMode == e_game_mode::_game_mode_campaign;
	bool isMultiplayer = g_LaunchGameMode == e_game_mode::_game_mode_multiplayer;
	bool isFirefight = g_LaunchGameMode == e_game_mode::_game_mode_survival;

	std::string curName, curDesc;
	int curEngineIndex = read_game_variant(g_LaunchHopperGameVariant, &curName, &curDesc);

	const char* pCurrentGameVariantStr = curName.c_str();
	if (ImGui::BeginCombo("Game Variant", pCurrentGameVariantStr))
	{
		for (int i = 0; i < files.Count; i++)
		{
			std::string name, desc;
			e_game_engine_type engineIndex = read_game_variant(files.At(i), &name, &desc);
			const char* pGameVariantStr = name.c_str();

			int shouldShow = isCampaign && engineIndex == _game_engine_type_campaign;
			shouldShow |= isMultiplayer && engineIndex == _game_engine_type_megalo;
			shouldShow |= isFirefight && engineIndex == _game_engine_type_survival;

			if (pGameVariantStr[0] && shouldShow)
			{
				bool selected = pGameVariantStr == pCurrentGameVariantStr;
				if (ImGui::Selectable(pGameVariantStr, &selected))
				{
					g_LaunchHopperGameVariant = files.At(i);
					Settings::WriteStringValue(SettingsSection::Launch, "HopperGameVariant", (char*)g_LaunchHopperGameVariant);
				}
			}
		}

		ImGui::EndCombo();
	}
}

void GameLauncher::SelectMapVariant()
{
	static s_path_array files = s_path_array();
	files.AddFrom("hopper_map_variants");

	if (g_LaunchGameMode == e_game_mode::_game_mode_multiplayer)
	{
		std::string curName, curDesc;
		int curMapId = read_map_variant(g_LaunchHopperMapVariant, &curName, &curDesc);
		const char* pCurrentMapVariantStr = curName.c_str();
		if (ImGui::BeginCombo("Map Variant", curMapId == map_id_to_engine_specific(g_LaunchMapId) ? pCurrentMapVariantStr : ""))
		{
			for (int i = 0; i < files.Count; i++)
			{
				std::string name, desc;
				int mapId = read_map_variant(files.At(i), &name, &desc);
				const char* pMapVariantStr = name.c_str();

				if (pMapVariantStr[0] && mapId == map_id_to_engine_specific(g_LaunchMapId))
				{
					bool selected = files.At(i) == pCurrentMapVariantStr;
					if (ImGui::Selectable(pMapVariantStr, &selected))
					{
						g_LaunchHopperMapVariant = files.At(i);
						Settings::WriteStringValue(SettingsSection::Launch, "HopperMapVariant", (char*)g_LaunchHopperMapVariant);
					}
				}
			}

			ImGui::EndCombo();
		}
	}
}

void GameLauncher::DrawMenu()
{
	ImGui::SetNextWindowPos(ImVec2(17, 4), ImGuiCond_FirstUseEver);
	ImGui::SetNextWindowSize(ImVec2(1876, 1000), ImGuiCond_FirstUseEver);

	// Main body of the Demo window starts here.
	static bool isReachDebugWindowOpen = true;
	int windowFlags = 0;
	windowFlags |= ImGuiWindowFlags_MenuBar;
	windowFlags |= ImGuiWindowFlags_NoCollapse;
	windowFlags |= ImGuiWindowFlags_NoTitleBar;
	windowFlags |= ImGuiWindowFlags_NoMove;
	windowFlags |= ImGuiWindowFlags_NoResize;
	windowFlags |= ImGuiWindowFlags_NoSavedSettings;
	//windowFlags |= ImGuiWindowFlags_AlwaysAutoResize;

	if (!ImGui::Begin("Main Menu", &isReachDebugWindowOpen, windowFlags))
	{
		// Early out if the window is collapsed, as an optimization.
		ImGui::End();
		return;
	}

	SelectGameMode();
	SelectMap();
	SelectDifficulty();
	SelectGameVariant();
	SelectMapVariant();

	static bool hasAutostarted = false;
	if (ImGui::Button("Start game") || (GameLauncher::HasCommandLineArg("-autostart") && !hasAutostarted))
	{
		hasAutostarted = true;
		SetState(CurrentState::eWaitingToRun);
	}

	if (ImGui::Button("Exit to Desktop"))
	{
		exit(0);
	}



	ImGui::End();
}

void GameLauncher::InitSockets()
{
	WSADATA wsaData = {};
	// Initialize Winsock
	auto WSAStartupResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (WSAStartupResult != 0)
	{
		FATAL_ERROR("WSAStartup failed with error: %d\n", WSAStartupResult);
	}
}

void GameLauncher::DeinitSockets()
{

}

void GameLauncher::LoadHopperMapVariant(IDataAccess* pDataAccess, const char* pHopperMapVariantName, s_map_variant& out_map_variant, bool print)
{
	char pFilename[MAX_PATH] = {};
	sprintf(pFilename, "hopper_map_variants\\%s.mvar", pHopperMapVariantName);
	pFilename[MAX_PATH - 1] = 0;

	FILE* pVariantFile = fopen(pFilename, "rb");
	if (pVariantFile)
	{
		if (print)
		{
			WriteLineVerbose("Loading map variant [%s]", pFilename);
		}

		size_t variantSize = get_file_size(pVariantFile);
		char* pVariantBuffer = (char*)alloca(variantSize);
		memset(pVariantBuffer, 0x00, variantSize);
		read_file_to_buffer(pVariantFile, pVariantBuffer, variantSize);
		fclose(pVariantFile);

		out_map_variant = pDataAccess->MapVariantCreateFromFile(pVariantBuffer, static_cast<int>(variantSize))->MapVariant;
	}
}

void GameLauncher::LoadHopperGameVariant(IDataAccess* pDataAccess, const char* pHopperGameVariantName, s_game_variant& out_game_variant, bool print)
{
	char pFilename[MAX_PATH] = {};
	sprintf(pFilename, "hopper_game_variants\\%s.bin", pHopperGameVariantName);
	pFilename[MAX_PATH - 1] = 0;

	FILE* pVariantFile = fopen(pFilename, "rb");
	if (pVariantFile)
	{
		if (print)
		{
			WriteLineVerbose("Loading game variant [%s]", pFilename);
		}

		size_t variantSize = get_file_size(pVariantFile);
		char* pVariantBuffer = (char*)alloca(variantSize);
		memset(pVariantBuffer, 0xFF, variantSize);
		read_file_to_buffer(pVariantFile, pVariantBuffer, variantSize);
		fclose(pVariantFile);

		out_game_variant = pDataAccess->GameVariantCreateFromFile(pVariantBuffer, static_cast<int>(variantSize))->GameVariant;
	}
}

void GameLauncher::LoadPreviousGamestate(const char* pFilename, GameContext& gameContext)
{
	FILE* pGameStateFile = fopen(pFilename, "rb");
	if (pGameStateFile)
	{
		size_t gameStateSize = get_file_size(pGameStateFile);
		char* pGameStateBuffer = new char[gameStateSize];
		memset(pGameStateBuffer, 0x00, gameStateSize);
		read_file_to_buffer(pGameStateFile, pGameStateBuffer, gameStateSize);
		fclose(pGameStateFile);

		gameContext.pGameStateHeader = reinterpret_cast<uint8_t*>(pGameStateBuffer);
		gameContext.GameStateHeaderSize = gameStateSize;
	}
}
