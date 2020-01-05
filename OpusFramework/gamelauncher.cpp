#include "opusframework-private-pch.h"

bool GameLauncher::s_gameManuallyKilled = false;
bool GameLauncher::s_hideWindowOnStartup = false;
GameLauncher::CurrentState GameLauncher::s_currentState = GameLauncher::CurrentState::eInactive;
GameLauncher::GameLaunchCallback* GameLauncher::s_gameLaunchCallback = nullptr;
GameLauncher::GameShutdownCallback* GameLauncher::s_gameShutdownCallback;
std::atomic<int> GameLauncher::s_uiStackLength = 0;

GameInterface* GameLauncher::s_pCurrentGameInterface = nullptr;
IGameEngine* GameLauncher::s_pHaloReachEngine = nullptr;
char* GameLauncher::s_pTerminationFlag = nullptr;
e_game_mode g_LaunchGameMode = _game_mode_survival;
e_campaign_difficulty_level g_LaunchCampaignDifficultyLevel = _campaign_difficulty_level_normal;
LPCSTR g_LaunchGameVariant = "";
bool g_GameVariantIsHopper = false;
LPCSTR g_LaunchMapVariant = "";
bool g_MapVariantIsHopper = false;
LPCSTR g_SavedFilm = nullptr;
MapInfoManager* GameLauncher::s_pMapInfoManager = nullptr;
const MapInfo* GameLauncher::s_pSelectedMapInfo[underlying_cast(SelectedGameModeMapInfoIndex::Count)] = {};

BuildVersion GameLauncher::GetCurrentbuildVersion()
{
	if (s_pCurrentGameInterface)
	{
		return s_pCurrentGameInterface->GetBuildVersion();
	}
	return BuildVersion::NotSet;
}

void GameLauncher::CheckSteamAPI()
{
	{
		FILE* pAppIDFile = fopen("steam_appid.txt", "w");
		assert(pAppIDFile);
		constexpr const char* pAppId = "976730";
		fwrite(pAppId, sizeof(char), strlen(pAppId), pAppIDFile);
		fclose(pAppIDFile);
	}

	bool steamAPIInitResult = SteamAPI_Init();
	if (!steamAPIInitResult)
	{
		MessageBox(NULL, "Fatal Error - Steam failed to initialize", "Fatal Error", MB_OK | MB_ICONWARNING);
		exit(1);
	}
}

void GameLauncher::InitMapInfoManager()
{
	s_pMapInfoManager = new MapInfoManager("haloreach/maps/info");
}

void GameLauncher::DeinitMapInfoManager()
{
	delete s_pMapInfoManager;
}

void GameLauncher::LaunchGame()
{
	// make sure the runtime information is in a valid state before trying to run another game
	assert(s_pHaloReachEngine == nullptr);
	assert(s_pCurrentGameInterface != nullptr);
	assert(s_pCurrentGameInterface->GetBuildVersion() != BuildVersion::NotSet);

	// #TODO: Game specific version of this!!!
	if (s_gameLaunchCallback != nullptr)
	{
		s_gameLaunchCallback(EngineVersion::HaloReach, s_pCurrentGameInterface->GetBuildVersion());
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
		s_gameShutdownCallback(EngineVersion::HaloReach, s_pCurrentGameInterface->GetBuildVersion());
	}

	s_pHaloReachEngine->Destructor();
	//free(pHaloReachEngine);
	//free(pHaloReachDataAccess);

	// reset runtime information after we've destroyed the engine
	//s_pCurrentGameInterface = nullptr;
	s_pHaloReachEngine = nullptr;
}

static thread_local WNDENUMPROC s_lpEnumFunc = nullptr;
static thread_local bool s_processedCustomWindow = false;
BOOL EnumWindowsSort(HWND hWnd, LPARAM lParam)
{
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
}

typedef BOOL(EnumWindowsFunc)(WNDENUMPROC lpEnumFunc, LPARAM lParam);
EnumWindowsFunc* EnumWindowsPointer = nullptr;
BOOL EnumWindowsHook(
	WNDENUMPROC lpEnumFunc,
	LPARAM      lParam
)
{
	assert(s_lpEnumFunc == nullptr);
	assert(EnumWindowsPointer != nullptr);

	s_processedCustomWindow = false;
	s_lpEnumFunc = lpEnumFunc;

	BOOL result = EnumWindowsPointer(EnumWindowsSort, lParam);
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

	if ((GameLauncher::HasCommandLineArg("-showconsole") || isDebug) && !GameLauncher::HasCommandLineArg("-hideconsole"))
	{
		AllocConsole();
		FILE* pStdOut = freopen("CONOUT$", "w", stdout);
		assert(pStdOut);
		SetConsoleTitleA("Opus");
	}

	if (GameLauncher::HasCommandLineArg("-hidesplash"))
	{
		SplashScreen::Create();
		s_hideWindowOnStartup = true;
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

	InitMapInfoManager();
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
	DeinitMapInfoManager();
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




typedef DWORD (TlsAllocFunc)();
static TlsAllocFunc* TlsAllocPtr = nullptr;
DWORD TlsAllocHook()
{
	DWORD tlsAllocResult = TlsAllocPtr();

	WriteLineVerbose("TlsAlloc> %d", tlsAllocResult);

	return tlsAllocResult;
}

void GameLauncher::SetupGlobalHooks()
{
	create_dll_hook("Kernel32.dll", "TlsAlloc", TlsAllocHook, TlsAllocPtr);
}

bool GameLauncher::HasCommandLineArg(LPCSTR pArgument)
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

void GameLauncher::EnsureBink2Win64IsLoaded(const char* pLibName, const char* pFallbackDir)
{
	HMODULE hModule = GetModuleHandleA(pLibName);
	if (!hModule)
	{
		hModule = LoadLibraryA(pLibName);

		// use fallback if 
		if (!hModule && pFallbackDir[0])
		{
			char fallbackPath[MAX_PATH] = {};
			sprintf(fallbackPath, "%s\\%s", pFallbackDir, pLibName);
			hModule = GetModuleHandleA(fallbackPath);
			if (!hModule)
			{
				hModule = LoadLibraryA(fallbackPath);
			}
		}
	}
	if (!hModule)
	{
		MessageBox(CustomWindow::GetWindowHandle(), pLibName, "failed to load library", MB_ICONERROR);
	}
	assert(hModule);
}

void GameLauncher::RegisterGameLaunchCallback(EngineVersion engineVersion, GameLaunchCallback gameLaunchCallback)
{
	// #TODO: Multiple game versions!!!
	s_gameLaunchCallback = gameLaunchCallback;
}

void GameLauncher::RegisterGameShutdownCallback(EngineVersion engineVersion, GameShutdownCallback gameShutdownCallback)
{
	s_gameShutdownCallback = gameShutdownCallback;
}

const MapInfo* GameLauncher::GetDefaultMapSelection(SelectedGameModeMapInfoIndex gameModeMapInfoIndex)
{
	int previousMapID = Settings::ReadIntegerValue(SettingsSection::Launch, s_kpMapInfoSettingsName[underlying_cast(gameModeMapInfoIndex)], -1);
	for (const MapInfo& rMapInfo : s_pMapInfoManager->m_mapInfo)
	{
		if (rMapInfo.GetMapID() == previousMapID)
		{
			return &rMapInfo;
		}
	}

	return nullptr;
}

void GameLauncher::LoadSettings()
{
	for (underlying(SelectedGameModeMapInfoIndex) i = 0; i < underlying_cast(SelectedGameModeMapInfoIndex::Count); i++)
	{
		s_pSelectedMapInfo[i] = GetDefaultMapSelection(static_cast<SelectedGameModeMapInfoIndex>(i));
	}

	char pLaunchGameModeBuffer[256] = {};
	Settings::ReadStringValue(SettingsSection::Launch, "GameMode", pLaunchGameModeBuffer, sizeof(pLaunchGameModeBuffer), "");
	g_LaunchGameMode = string_to_game_mode(pLaunchGameModeBuffer);

	char pLaunchCampaignDifficultyLevelBuffer[256] = {};
	Settings::ReadStringValue(SettingsSection::Launch, "DifficultyLevel", pLaunchCampaignDifficultyLevelBuffer, sizeof(pLaunchCampaignDifficultyLevelBuffer), "normal");
	g_LaunchCampaignDifficultyLevel = string_to_campaign_difficulty_level(pLaunchCampaignDifficultyLevelBuffer);

	LPCSTR pDefaultHopperGameVariant = "";
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
	static char pLaunchGameVariantBuffer[256] = {};
	uint32_t LaunchGameVariantLength = Settings::ReadStringValue(SettingsSection::Launch, "GameVariant", pLaunchGameVariantBuffer, sizeof(pLaunchGameVariantBuffer), pDefaultHopperGameVariant);
	if (LaunchGameVariantLength > 0)
	{
		g_LaunchGameVariant = pLaunchGameVariantBuffer;
	}
	else
	{
		g_LaunchGameVariant = "";
	}

	g_GameVariantIsHopper = Settings::ReadBoolValue(SettingsSection::Launch, "GameVariantIsHopper", false);

	// #TODO: This must persist outside of the read
	static char pLaunchMapVariantBuffer[256] = {};
	uint32_t LaunchMapVariantLength = Settings::ReadStringValue(SettingsSection::Launch, "MapVariant", pLaunchMapVariantBuffer, sizeof(pLaunchMapVariantBuffer), "");
	if (LaunchMapVariantLength > 0)
	{
		g_LaunchMapVariant = pLaunchMapVariantBuffer;
	}
	else
	{
		g_LaunchMapVariant = "";
	}

	g_MapVariantIsHopper = Settings::ReadBoolValue(SettingsSection::Launch, "MapVariantIsHopper", false);
}

void CreateSwapchainAndBackbuffer(IDXGISwapChain1*& pSwapchain, ID3D11RenderTargetView*& pBackBuffer)
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
	if (hInstance == NULL)
		hInstance = GetModuleHandle(NULL);
	if (lpCmdLine == nullptr)
		lpCmdLine = GetCommandLineA();

	GameLauncher::Init(hInstance, lpCmdLine);

	LoadSettings();
	s_pCurrentGameInterface = &rGameInterface;
	SetState(CurrentState::eMainMenu);

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
	const MapInfo*& rpSelectedMapInfo = GetSelectedMapInfoByGameMode(g_LaunchGameMode);

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
		playerCount = 1;
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

		if (rGameContext.SessionInfo.IsHost)
		{
			NetworkManager::CreateServerConnection();

			SetConsoleTitleA("Opus | HOST");

			assert(s_pSelectedMapInfo != nullptr);
			rGameContext.MapId = static_cast<e_map_id>(rpSelectedMapInfo->GetMapID());
			rGameContext.CampaignDifficultyLevel = g_LaunchCampaignDifficultyLevel;

			LoadGameVariant(s_pCurrentGameInterface->GetDataAccess(), g_LaunchGameVariant, *reinterpret_cast<s_game_variant*>(rGameContext.GameVariantBuffer), true);
			LoadMapVariant(s_pCurrentGameInterface->GetDataAccess(), g_LaunchMapVariant, *reinterpret_cast<s_map_variant*>(rGameContext.MapVariantBuffer), true);
			//LoadPreviousGamestate("gamestate", rGameContext);
			LoadSavedFilmMetadata(g_SavedFilm, rGameContext);

			rGameContext.SessionInfo.LocalMachineID = HostAddress; // this is set
			rGameContext.SessionInfo.HostAddress = HostAddress;
		}
		else
		{
			NetworkManager::CreateClientConnection();

			rGameContext.SessionInfo.LocalMachineID = ClientAddress; // this is set
			rGameContext.SessionInfo.HostAddress = HostAddress;
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
		DebugUI::RegisterCallback(DrawMainMenu);
		break;
	case CurrentState::eWaitingToRun:
		break;
	case CurrentState::eRunning:
	{
		DebugUI::UnregisterCallback(DrawMainMenu);
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

// TODO: replace `c_file_reference` with `IFileAccess`
struct c_file_reference
{
	LPCSTR pFileName;
	FILE* pFile;
	char* pBuffer;
	size_t bufferSize;

	c_file_reference(LPCSTR pPath)
	{
		pFileName = pPath;
	}

	bool open_file()
	{
		pFile = fopen(pFileName, "rb");
		if (pFile)
		{
			fseek(pFile, 0, SEEK_END);
			bufferSize = ftell(pFile);
			fseek(pFile, 0L, SEEK_SET);
			pBuffer = new char[bufferSize];
			memset(pBuffer, 0x00, bufferSize);

			fseek(pFile, 0L, SEEK_SET);
			size_t totalBytesRead = 0;
			do
			{
				size_t bytesToRead = bufferSize - totalBytesRead;
				fseek(pFile, static_cast<long>(totalBytesRead), SEEK_SET);
				size_t bytesRead = fread(pBuffer + totalBytesRead, 1, bytesToRead, pFile);
				totalBytesRead += bytesRead;
			} while (totalBytesRead < bufferSize);

			return true;
		}

		return false;
	}

	void close_file()
	{
		if (pFile)
		{
			bufferSize = 0;
			free(pBuffer);
			fclose(pFile);
		}
	}

	template<typename T>
	void read_type(T* value, long offset = 0)
	{
		assert(pFile);
		*value = *(T*)&pBuffer[offset];
	}

	void read_int8(__int8* value, long offset = 0)
	{
		read_type(value, offset);
	}

	void read_uint8(unsigned __int8* value, long offset = 0)
	{
		read_type(value, offset);
	}

	void read_int16(__int16* value, long offset = 0, bool swapEndian = false)
	{
		__int16 out = *value;
		read_type(&out, offset);
		*value = swapEndian ? (out >> 8) | (out << 8) : out;
	}

	void read_uint16(unsigned __int16* value, long offset = 0, bool swapEndian = false)
	{
		unsigned __int16 out = *value;
		read_type(&out, offset);
		*value = swapEndian ? (out >> 8) | (out << 8) : out;
	}

	void read_int32(__int32* value, long offset = 0, bool swapEndian = false)
	{
		__int32 out = *value;
		read_type(&out, offset);
		*value = swapEndian ? ((out >> 24) & 0xff) | ((out << 8) & 0xff0000) | ((out >> 8) & 0xff00) | ((out << 24) & 0xff000000) : out;
	}

	void read_uint32(unsigned __int32* value, long offset = 0, bool swapEndian = false)
	{
		unsigned __int32 out = *value;
		read_type(&out, offset);
		*value = swapEndian ? ((out >> 24) & 0xff) | ((out << 8) & 0xff0000) | ((out >> 8) & 0xff00) | ((out << 24) & 0xff000000) : out;
	}

	void read_string(std::string* value, size_t length, long offset = 0)
	{
		assert(pFile);
		*value = &pBuffer[offset];
	}

	void read_string_long(std::wstring* value, size_t length, long offset = 0, bool swapEndian = false)
	{
		assert(pFile);
		*value = (wchar_t*)&pBuffer[swapEndian ? offset + 1 : offset];
	}

	void read_string_long_as_string(std::string* value, size_t length, long offset = 0, bool swapEndian = false)
	{
		std::wstring out; read_string_long(&out, length, offset, swapEndian);
		*value = std::string(out.begin(), out.end());
	}

	void read_string_as_string_long(std::wstring* value, size_t length, long offset = 0)
	{
		std::string out; read_string(&out, length, offset);
		*value = std::wstring(out.begin(), out.end());
	}
};

struct c_file_array
{
	struct s_file_info
	{
		std::string Path = {};
		std::string Name = {};
		std::string Desc = {};
		int Type = {};

		bool Match(LPCSTR pStr)
		{
			return !!(strstr(Path.c_str(), pStr) != 0 || strstr(Name.c_str(), pStr) != 0 || strstr(Desc.c_str(), pStr) != 0);
		}

		bool Match(int type)
		{
			return type == Type;
		}
	};

	s_file_info* pFiles = {};
	int Count = 0;

	c_file_array(LPCSTR pDir, LPCSTR pExtension, int (*pReadInfoFunction)(LPCSTR pName, std::string* name, std::string* desc, LPCSTR path))
	{
		if (!pFiles || !Count)
		{
			if (std::filesystem::exists(pDir))
			{
				pFiles = new s_file_info[std::distance(std::filesystem::directory_iterator(pDir), std::filesystem::directory_iterator())];

				int i = 0;
				for (const std::filesystem::directory_entry& rDirectoryEntry : std::filesystem::directory_iterator(pDir))
				{
					if (rDirectoryEntry.path().extension().compare(pExtension) == 0)
					{
						pFiles[i].Path = rDirectoryEntry.path().filename().replace_extension().string();
						pFiles[i].Type = pReadInfoFunction(pFiles[i].Path.c_str(), &pFiles[i].Name, &pFiles[i].Desc, rDirectoryEntry.path().string().c_str());

						while (pFiles[i].Desc.find("|n") != std::string::npos)
							pFiles[i].Desc.replace(pFiles[i].Desc.find("|n"), _countof("|n") - 1, "\n");
						i++;
					}
				}
				Count = i;
			}
		}
	}

	LPCSTR GetPath(int index)
	{
		LPCSTR result = "";
		if (index >= 0 && index < Count)
		{
			result = pFiles[index].Path.c_str();
		}

		return result;
	}
	LPCSTR GetPath(LPCSTR pStr)
	{
		LPCSTR result = "";
		for (int i = 0; i < Count; i++)
		{
			if (pFiles[i].Match(pStr))
			{
				result = pFiles[i].Path.c_str();
			}
		}

		return result;
	}

	LPCSTR GetName(int index)
	{
		LPCSTR result = "";
		if (index >= 0 && index < Count)
		{
			result = pFiles[index].Name.c_str();
		}

		return result;
	}
	LPCSTR GetName(LPCSTR pStr)
	{
		LPCSTR result = "";
		if (pStr)
		{
			for (int i = 0; i < Count; i++)
			{
				if (pFiles[i].Match(pStr))
				{
					result = pFiles[i].Name.c_str();
				}
			}
		}

		return result;
	}

	LPCSTR GetDesc(int index)
	{
		LPCSTR result = "";
		if (index >= 0 && index < Count)
		{
			result = pFiles[index].Desc.c_str();
		}

		return result;
	}
	LPCSTR GetDesc(LPCSTR pStr)
	{
		LPCSTR result = "";
		for (int i = 0; i < Count; i++)
		{
			if (pFiles[i].Match(pStr))
			{
				result = pFiles[i].Desc.c_str();
			}
		}

		return result;
	}

	int GetType(int index)
	{
		int result = -1;
		if (index >= 0 && index < Count)
		{
			result = pFiles[index].Type;
		}

		return result;
	}
	int GetType(LPCSTR pStr)
	{
		int result = -1;
		for (int i = 0; i < Count; i++)
		{
			if (pFiles[i].Match(pStr))
			{
				result = pFiles[i].Type;
			}
		}

		return result;
	}

	bool Match(int type)
	{
		bool result = false;
		for (int i = 0; i < Count; i++)
		{
			if (pFiles[i].Match(type))
			{
				result = true;
			}
		}
		return result;
	}
	bool Match(LPCSTR pStr)
	{
		bool result = false;
		for (int i = 0; i < Count; i++)
		{
			if (pFiles[i].Match(pStr))
			{
				result = true;
			}
		}
		return result;
	}
};

LPCSTR Format(LPCSTR fmt, ...)
{
	static char* buffer;

	va_list args;
	va_start(args, fmt);

	buffer = new char[1024];
	memset(buffer, 0, 1024);

	vsprintf(buffer, fmt, args);

	va_end(args);

	return buffer;
}

int ReadMapInfo(LPCSTR pName, std::string* name, std::string* desc, LPCSTR pPath)
{
	char pFileName[MAX_PATH + 1] = {};
	snprintf(pFileName, MAX_PATH, "%s\\maps\\info\\%s.mapinfo", GameLauncher::s_pCurrentGameInterface->GetEngineName().c_str(), pName);
	pFileName[MAX_PATH] = 0;

	c_file_reference filo(pFileName);
	int mapId = -1;
	if (filo.open_file())
	{
		filo.read_string_long_as_string(name, 64, 0x44, true);
		filo.read_string_long_as_string(desc, 256, 0x344, true);

		filo.read_int32(&mapId, 0x3C, true);
		filo.close_file();
	}

	return mapId;
}

void GetVariantInfo(char* pBuffer, std::string* name, std::string* desc)
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

int ReadGameVariant(LPCSTR pName, std::string* name, std::string* desc, LPCSTR pPath)
{
	g_GameVariantIsHopper = strstr(pPath, "hopper_") != 0;

	static s_game_variant gameVariant;
	GameLauncher::LoadGameVariant(GameLauncher::s_pCurrentGameInterface->GetDataAccess(), pName, gameVariant);

	int result = gameVariant.game_engine_index;

	GetVariantInfo(gameVariant.game_engine_variant.data, name, desc);

	if (!(*name).c_str()[0])
	{
		*name = pName;
	}

	return result;
}

int ReadMapVariant(LPCSTR pName, std::string* name, std::string* desc, LPCSTR pPath)
{
	g_MapVariantIsHopper = strstr(pPath, "hopper_") != 0;
	static s_map_variant mapVariant;
	GameLauncher::LoadMapVariant(GameLauncher::s_pCurrentGameInterface->GetDataAccess(), pName, mapVariant);

	int result = *reinterpret_cast<int*>(&mapVariant.data[0x2C]);
	GetVariantInfo(mapVariant.data, name, desc);

	return result;
}

int ReadSavedFilm(LPCSTR pName, std::string* name, std::string* desc, LPCSTR pPath)
{
	IDataAccess* pDataAccess = GameLauncher::s_pCurrentGameInterface->GetDataAccess();
	char* out_data = { 0 };

	c_file_reference filo(pPath);
	if (filo.open_file())
	{
		out_data = pDataAccess->SaveFilmMetadataCreateFromFile(filo.pBuffer, static_cast<int>(filo.bufferSize))->data;

		filo.read_string_long_as_string(name, 256, 0xC0);
		filo.read_string_long_as_string(desc, 256, 0x1C0);

		filo.close_file();
	}

	return -1;
}

void RenderHoveredTooltip(LPCSTR pText)
{
	if (ImGui::IsItemHovered())
	{
		ImGui::BeginTooltip();
		ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
		ImGui::Text(pText);
		ImGui::PopTextWrapPos();
		ImGui::EndTooltip();
	}
}

void GameLauncher::SelectSavedFilm()
{
	static c_file_array official_saved_films = c_file_array(Format("%s\\AppData\\LocalLow\\MCC\\Temporary\\UserContent\\%s\\Movie\\", GetUserprofileVariable(), GameLauncher::s_pCurrentGameInterface->GetEngineName().c_str()), ".mov", &ReadSavedFilm);
	static c_file_array saved_films = c_file_array(Format("%s\\Temporary\\autosave\\", GameLauncher::s_pCurrentGameInterface->GetEngineName().c_str()), ".film", &ReadSavedFilm);

	static LPCSTR last_official_saved_film = "";
	static LPCSTR last_saved_film = "";

	static bool savedFilmIsOfficial = false;
	c_file_array& rFiles = savedFilmIsOfficial ? official_saved_films : saved_films;
	LPCSTR& pLast = savedFilmIsOfficial ? last_official_saved_film : last_saved_film;
	const char* pLabel = savedFilmIsOfficial ? "(OFFICIAL)" : "###SAVED FILM";

	if (g_SavedFilm != rFiles.GetPath(pLast))
	{
		g_SavedFilm = rFiles.GetPath(pLast);
	}

	if (ImGui::Button("SAVED FILM  ") || GetKeyState('F') & 0x80)
	{
		savedFilmIsOfficial = !savedFilmIsOfficial;
		Sleep(50);
	}
	ImGui::SameLine();

	if (ImGui::BeginCombo(pLabel, rFiles.GetDesc(pLast)))
	{
		for (int i = 0; i < rFiles.Count; i++)
		{
			if (rFiles.GetName(i))
			{
				bool selected = rFiles.GetName(i) == rFiles.GetName(pLast);
				if (ImGui::Selectable(rFiles.GetDesc(i), &selected))
				{
					pLast = rFiles.GetPath(i);
				}

				RenderHoveredTooltip(rFiles.GetName(i));
			}
		}

		ImGui::EndCombo();
	}

	if (savedFilmIsOfficial)
	{
		last_official_saved_film = pLast;
	}
	else
	{
		last_saved_film = pLast;
	}
}

void GameLauncher::SelectGameMode()
{
	if (GameLauncher::HasCommandLineArg("-showallmodes"))
	{
		LPCSTR s_pCurrentGameModeStr = game_mode_to_string(g_LaunchGameMode);
		if (ImGui::BeginCombo("###MODE", s_pCurrentGameModeStr))
		{
			for (int i = 0; i < e_game_mode::k_number_of_game_modes; i++)
			{
				LPCSTR pGameModeStr = game_mode_to_string(static_cast<e_game_mode>(i));
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
	else
	{
		LPCSTR s_pCurrentGameModeStr = game_mode_to_string(g_LaunchGameMode);
		if (ImGui::BeginCombo("###MODE", s_pCurrentGameModeStr))
		{
			for (underlying(SelectedGameModeMapInfoIndex) i = 0; i < underlying_cast(SelectedGameModeMapInfoIndex::Count); i++)
			{
				if (static_cast<SelectedGameModeMapInfoIndex>(i) == SelectedGameModeMapInfoIndex::Unknown)
				{
					continue;
				}

				e_game_mode gameMode = SelectedGameModeMapInfoIndexToGameMode(static_cast<SelectedGameModeMapInfoIndex>(i));
				LPCSTR pGameModeStr = game_mode_to_string(gameMode);
				if (pGameModeStr)
				{
					bool selected = s_pCurrentGameModeStr == pGameModeStr;
					if (ImGui::Selectable(pGameModeStr, &selected))
					{
						g_LaunchGameMode = gameMode;
						Settings::WriteStringValue(SettingsSection::Launch, "GameMode", (char*)game_mode_to_string(g_LaunchGameMode));
					}
				}
			}

			ImGui::EndCombo();
		}
	}
}

bool GameLauncher::IsMapInfoCompadibleWithGameMode(e_game_mode gameMode, const MapInfo& rMapInfo)
{
	switch (gameMode)
	{
	case _game_mode_campaign:
		if (!rMapInfo.IsCampaign()) return false;
		break;
	case _game_mode_multiplayer:
		if (!rMapInfo.IsMultiplayer()) return false;
		break;
	case _game_mode_survival:
		if (!rMapInfo.IsFirefight()) return false;
		break;
	}
	return true;
}

const MapInfo* GameLauncher::GetFirstSuitableGameModeMapInfo(e_game_mode gameMode)
{
	for (const MapInfo& rMapInfo : s_pMapInfoManager->m_mapInfo)
	{
		if (IsMapInfoCompadibleWithGameMode(g_LaunchGameMode, rMapInfo))
		{
			return &rMapInfo;
		}
	}
	return nullptr;
}

void GameLauncher::SaveSelectedMap(e_game_mode gameMode, const MapInfo* pMapInfo)
{
	switch (gameMode)
	{
	case _game_mode_campaign:
		Settings::WriteIntegerValue(SettingsSection::Launch, s_kpMapInfoSettingsName[underlying_cast(SelectedGameModeMapInfoIndex::Campaign)], pMapInfo ? pMapInfo->GetMapID() : -1);
		break;
	case _game_mode_multiplayer:
		Settings::WriteIntegerValue(SettingsSection::Launch, s_kpMapInfoSettingsName[underlying_cast(SelectedGameModeMapInfoIndex::Multiplayer)], pMapInfo ? pMapInfo->GetMapID() : -1);
		break;
	case _game_mode_survival:
		Settings::WriteIntegerValue(SettingsSection::Launch, s_kpMapInfoSettingsName[underlying_cast(SelectedGameModeMapInfoIndex::Firefight)], pMapInfo ? pMapInfo->GetMapID() : -1);
		break;
	default:
		Settings::WriteIntegerValue(SettingsSection::Launch, s_kpMapInfoSettingsName[underlying_cast(SelectedGameModeMapInfoIndex::Unknown)], pMapInfo ? pMapInfo->GetMapID() : -1);
		break;
	}
}

GameLauncher::SelectedGameModeMapInfoIndex GameLauncher::GameModeToSelectedGameModeMapInfoIndex(e_game_mode gameMode)
{
	switch (gameMode)
	{
	case _game_mode_campaign:
		return SelectedGameModeMapInfoIndex::Campaign;
		break;
	case _game_mode_multiplayer:
		return SelectedGameModeMapInfoIndex::Multiplayer;
		break;
	case _game_mode_survival:
		return SelectedGameModeMapInfoIndex::Firefight;
		break;
	default:
		return SelectedGameModeMapInfoIndex::Unknown;
		break;
	}
}

e_game_mode GameLauncher::SelectedGameModeMapInfoIndexToGameMode(SelectedGameModeMapInfoIndex selectedGameModeMapInfoIndex)
{
	switch (selectedGameModeMapInfoIndex)
	{
	case SelectedGameModeMapInfoIndex::Campaign:
		return _game_mode_campaign;
		break;
	case SelectedGameModeMapInfoIndex::Multiplayer:
		return _game_mode_multiplayer;
		break;
	case SelectedGameModeMapInfoIndex::Firefight:
		return _game_mode_survival;
		break;
	default:
		return _game_mode_none;
	}
}

const MapInfo*& GameLauncher::GetSelectedMapInfoBySelectedGameModeMapInfoIndex(SelectedGameModeMapInfoIndex selectedGameModeMapInfoIndex)
{
	const MapInfo*& rpSelectedMapInfo = s_pSelectedMapInfo[underlying_cast(selectedGameModeMapInfoIndex)];
	return rpSelectedMapInfo;
}

const MapInfo*& GameLauncher::GetSelectedMapInfoByGameMode(e_game_mode gameMode)
{
	return GetSelectedMapInfoBySelectedGameModeMapInfoIndex(GameModeToSelectedGameModeMapInfoIndex(g_LaunchGameMode));
}

void GameLauncher::SelectMap()
{
	const MapInfo*& rpSelectedMapInfo = GetSelectedMapInfoByGameMode(g_LaunchGameMode);

	if (!rpSelectedMapInfo || rpSelectedMapInfo && !IsMapInfoCompadibleWithGameMode(g_LaunchGameMode, *rpSelectedMapInfo))
	{
		rpSelectedMapInfo = GetFirstSuitableGameModeMapInfo(g_LaunchGameMode);
		SaveSelectedMap(g_LaunchGameMode, rpSelectedMapInfo);
	}

	const char* pSelectedLevelName = "<no level selected>";
	if (rpSelectedMapInfo)
	{
		pSelectedLevelName = rpSelectedMapInfo->GetFriendlyName();
	}

	if (ImGui::BeginCombo("###MAP", pSelectedLevelName))
	{
		// #TODO: Make a nice and beautiful interface to this for multi-game
		for (const MapInfo& rMapInfo : s_pMapInfoManager->m_mapInfo)
		{
			if (!IsMapInfoCompadibleWithGameMode(g_LaunchGameMode, rMapInfo))
			{
				continue;
			}

			bool isSelected = rpSelectedMapInfo == &rMapInfo;
			const char* pCurrentLevelFriendlyName = rMapInfo.GetFriendlyName();

			if (ImGui::Selectable(pCurrentLevelFriendlyName, &isSelected))
			{
				rpSelectedMapInfo = &rMapInfo;
				SaveSelectedMap(g_LaunchGameMode, rpSelectedMapInfo);
			}
			RenderHoveredTooltip(rMapInfo.GetFriendlyDescription());
		}

		ImGui::EndCombo();
	}
}

void GameLauncher::SelectDifficulty()
{
	if (g_LaunchGameMode == e_game_mode::_game_mode_campaign || g_LaunchGameMode == e_game_mode::_game_mode_survival)
	{
		LPCSTR pCurrentDifficultyStr = campaign_difficulty_level_to_string(g_LaunchCampaignDifficultyLevel);
		if (ImGui::BeginCombo("###DIFFICULTY", pCurrentDifficultyStr))
		{
			for (e_campaign_difficulty_level difficulty = e_campaign_difficulty_level::_campaign_difficulty_level_easy; difficulty < k_number_of_campaign_difficulty_levels; reinterpret_cast<int&>(difficulty)++)
			{
				LPCSTR pDifficultyStr = campaign_difficulty_level_to_string(difficulty);
				if (pDifficultyStr)
				{
					bool selected = pDifficultyStr == pCurrentDifficultyStr;
					if (ImGui::Selectable(pDifficultyStr, &selected))
					{
						g_LaunchCampaignDifficultyLevel = static_cast<e_campaign_difficulty_level>(difficulty);
						Settings::WriteStringValue(SettingsSection::Launch, "DifficultyLevel", (char*)campaign_difficulty_level_to_string(g_LaunchCampaignDifficultyLevel));
					}
				}
			}

			ImGui::EndCombo();
		}
	}
}

void GameLauncher::SelectGameVariant()
{
	if (g_LaunchGameMode == e_game_mode::_game_mode_campaign)
	{
		return;
	}

	assert(GameLauncher::s_pCurrentGameInterface != nullptr);

	static c_file_array hopperGameVariantsFileArray(Format("%s\\hopper_game_variants", GameLauncher::s_pCurrentGameInterface->GetEngineName().c_str()), ".bin", &ReadGameVariant);
	static c_file_array gameVariantsFileArray(Format("%s\\game_variants", GameLauncher::s_pCurrentGameInterface->GetEngineName().c_str()), ".bin", &ReadGameVariant);

	static LPCSTR pLastSelectedHopperGameVariant = g_LaunchGameVariant;
	static LPCSTR pLastSelectedGameVariant = g_LaunchGameVariant;

	c_file_array& rFileArray = g_GameVariantIsHopper ? hopperGameVariantsFileArray : gameVariantsFileArray;
	LPCSTR& rpLastSelectedVariant = g_GameVariantIsHopper ? pLastSelectedHopperGameVariant : pLastSelectedGameVariant;
	const char* pVariantLabel = g_GameVariantIsHopper ? "(HOPPER)###GAME VARIANT" : "###GAME VARIANT";

	if (rpLastSelectedVariant[0] && g_LaunchGameVariant != rpLastSelectedVariant)
	{
		g_LaunchGameVariant = rpLastSelectedVariant;
		Settings::WriteStringValue(SettingsSection::Launch, "GameVariant", (LPSTR)g_LaunchGameVariant);
		Settings::WriteBoolValue(SettingsSection::Launch, "GameVariantIsHopper", g_GameVariantIsHopper);
	}

	if (ImGui::Button("GAME VARIANT") || GetKeyState('G') & 0x80)
	{
		g_GameVariantIsHopper = !g_GameVariantIsHopper;
		Sleep(50);
	}
	ImGui::SameLine();

	if (ImGui::BeginCombo(pVariantLabel, rFileArray.GetName(rpLastSelectedVariant)))
	{
		for (int i = 0; i < rFileArray.Count; i++)
		{
			int shouldShow = g_LaunchGameMode == e_game_mode::_game_mode_multiplayer && rFileArray.GetType(i) == _game_engine_type_sandbox;
			shouldShow |= g_LaunchGameMode == e_game_mode::_game_mode_multiplayer && rFileArray.GetType(i) == _game_engine_type_megalo;
			shouldShow |= g_LaunchGameMode == e_game_mode::_game_mode_campaign && rFileArray.GetType(i) == _game_engine_type_campaign;
			shouldShow |= g_LaunchGameMode == e_game_mode::_game_mode_survival && rFileArray.GetType(i) == _game_engine_type_survival;

			if (rFileArray.GetName(i) && shouldShow)
			{
				bool selected = rFileArray.GetName(i) == rFileArray.GetName(g_LaunchGameVariant);
				if (ImGui::Selectable(rFileArray.GetName(i), &selected))
				{
					rpLastSelectedVariant = rFileArray.GetPath(i);
				}

				RenderHoveredTooltip(rFileArray.GetDesc(i));
			}
		}

		ImGui::EndCombo();
	}

	if (g_GameVariantIsHopper)
	{
		pLastSelectedHopperGameVariant = rpLastSelectedVariant;
	}
	else
	{
		pLastSelectedGameVariant = rpLastSelectedVariant;
	}
}

void GameLauncher::SelectMapVariant()
{
	if (g_LaunchGameMode != e_game_mode::_game_mode_multiplayer)
	{
		return;
	}

	static c_file_array hopperMapVariantsFileArray(Format("%s\\hopper_map_variants", GameLauncher::s_pCurrentGameInterface->GetEngineName().c_str()), ".mvar", &ReadMapVariant);
	static c_file_array mapVariantsFileArray(Format("%s\\map_variants", GameLauncher::s_pCurrentGameInterface->GetEngineName().c_str()), ".mvar", &ReadMapVariant);

	static LPCSTR pLastSelectedHopperMapVariant = g_LaunchMapVariant;
	static LPCSTR pLastSelectedMapVariant = g_LaunchMapVariant;

	c_file_array& rFileArray = g_MapVariantIsHopper ? hopperMapVariantsFileArray : mapVariantsFileArray;
	LPCSTR& rpLastSelectedVariant = g_MapVariantIsHopper ? pLastSelectedHopperMapVariant : pLastSelectedMapVariant;
	const char* pVariantLabel = g_MapVariantIsHopper ? "(HOPPER)###MAP VARIANT" : "###MAP VARIANT";

	if (g_LaunchMapVariant != rpLastSelectedVariant)
	{
		g_LaunchMapVariant = rpLastSelectedVariant;
		Settings::WriteStringValue(SettingsSection::Launch, "MapVariant", (LPSTR)g_LaunchMapVariant);
		Settings::WriteBoolValue(SettingsSection::Launch, "MapVariantIsHopper", g_MapVariantIsHopper);
	}

	if (ImGui::Button("MAP VARIANT ") || GetKeyState('M') & 0x80)
	{
		g_MapVariantIsHopper = !g_MapVariantIsHopper;
		Sleep(50);
	}
	ImGui::SameLine();

	LPCSTR lastMapName = rFileArray.GetName(rpLastSelectedVariant);
	if (!lastMapName || strlen(lastMapName) == 0)
	{
		rpLastSelectedVariant = nullptr;
		lastMapName = "<Default Variant>";
	}
	if (ImGui::BeginCombo(pVariantLabel, lastMapName))
	{
		bool defaultDelected = false;
		if (ImGui::Selectable("<Default Variant>", &defaultDelected))
		{
			rpLastSelectedVariant = nullptr;
		}

		for (int i = 0; i < rFileArray.Count; i++)
		{
			//int shouldShow = rFileArray.GetType(i) == map_id_to_engine_specific(g_LaunchMapId);
			int shouldShow = 1; // #TODO: Determine what type of file this is and use MapInfo/s_pSelectedMapInfo to determine if it should show

			if (rFileArray.GetName(i) && shouldShow)
			{
				bool selected = rFileArray.GetName(i) == rFileArray.GetName(g_LaunchMapVariant);
				if (ImGui::Selectable(rFileArray.GetName(i), &selected) && !defaultDelected)
				{
					rpLastSelectedVariant = rFileArray.GetPath(i);
				}

				RenderHoveredTooltip(rFileArray.GetDesc(i));
			}
		}

		ImGui::EndCombo();
	}

	if (g_MapVariantIsHopper)
	{
		pLastSelectedHopperMapVariant = rpLastSelectedVariant;
	}
	else
	{
		pLastSelectedMapVariant = rpLastSelectedVariant;
	}
}

void GameLauncher::DrawMainMenu()
{
	float width = static_cast<float>(GetSystemMetrics(SM_CXSCREEN));
	float height = static_cast<float>(GetSystemMetrics(SM_CYSCREEN));

	static ImVec2 nextWindowSize = ImVec2(width * 0.98f, height * 0.94f);
	ImGui::SetNextWindowPosCenter(ImGuiCond_FirstUseEver);
	ImGui::SetNextWindowSize(nextWindowSize, ImGuiCond_FirstUseEver);

	static bool isWindowOpen = true;
	int windowFlags = 0;
	//windowFlags |= ImGuiWindowFlags_MenuBar;
	windowFlags |= ImGuiWindowFlags_NoCollapse;
	windowFlags |= ImGuiWindowFlags_NoTitleBar;
	windowFlags |= ImGuiWindowFlags_NoMove;
	windowFlags |= ImGuiWindowFlags_NoResize;
	windowFlags |= ImGuiWindowFlags_NoSavedSettings;
	//windowFlags |= ImGuiWindowFlags_AlwaysAutoResize;

	if (!ImGui::Begin("MAIN MENU", &isWindowOpen, windowFlags))
	{
		// Early out if the window is collapsed, as an optimization.
		ImGui::End();
		return;
	}

	SelectSavedFilm();

	ImGui::Separator();

	//if (g_LaunchGameMode != e_game_mode::_game_mode_multiplayer)
	//{
	//	ImGui::PushItemWidth((width / 100) * 25 * 0.938f);
	//}
	//else
	//{
	//	ImGui::PushItemWidth((width / 100) * 25 * 1.415f);
	//}
	SelectGameMode();
	//ImGui::SameLine();
	SelectMap();

	//if (g_LaunchGameMode != e_game_mode::_game_mode_multiplayer)
	//{
	//	ImGui::SameLine();
	//}
	SelectDifficulty();
	//ImGui::PopItemWidth();

	ImGui::Separator();

	SelectGameVariant();
	SelectMapVariant();

	static ImVec2 gridButtonSize = ImVec2(nextWindowSize.x / 5, nextWindowSize.y / 16);

	ImGui::SetCursorPos(ImVec2(gridButtonSize.x * 0.35f, gridButtonSize.y * 8));
	static bool hasAutostarted = false;
	if (ImGui::Button("START GAME", gridButtonSize) || (GameLauncher::HasCommandLineArg("-autostart") && !hasAutostarted) || GetKeyState(VK_RETURN) & 0x80)
	{
		g_SavedFilm = nullptr;
		hasAutostarted = true;
		SetState(CurrentState::eWaitingToRun);
	}

	ImGui::SetCursorPos(ImVec2(gridButtonSize.x * 0.35f, gridButtonSize.y * 9.1f));
	if (ImGui::Button("PLAY FILM", gridButtonSize) || GetKeyState('P') & 0x80)
	{
		SetState(CurrentState::eWaitingToRun);
	}

	ImGui::SetCursorPos(ImVec2(gridButtonSize.x * 0.35f, gridButtonSize.y * 14));
	if (ImGui::Button("QUIT TO DESKTOP", gridButtonSize) || GetKeyState(VK_ESCAPE) & 0x80)
	{
		exit(0);
	}



	ImGui::End();
}

void GameLauncher::DrawPauseMenu()
{
	if (!s_pHaloReachEngine)
		return;

	MouseInput::SetMode(MouseMode::UI);

	float width = static_cast<float>(GetSystemMetrics(SM_CXSCREEN));
	float height = static_cast<float>(GetSystemMetrics(SM_CYSCREEN));

	ImGui::SetNextWindowPosCenter(ImGuiCond_FirstUseEver);
	ImGui::SetNextWindowSize(ImVec2(width / 1.5f, height / 1.5f), ImGuiCond_FirstUseEver);

	static bool isWindowOpen = true;
	int windowFlags = 0;
	windowFlags |= ImGuiWindowFlags_MenuBar;
	windowFlags |= ImGuiWindowFlags_NoCollapse;
	windowFlags |= ImGuiWindowFlags_NoTitleBar;
	windowFlags |= ImGuiWindowFlags_NoMove;
	windowFlags |= ImGuiWindowFlags_NoResize;
	windowFlags |= ImGuiWindowFlags_NoSavedSettings;
	//windowFlags |= ImGuiWindowFlags_AlwaysAutoResize;

	static ImVec2 gridButtonSize = ImVec2((width / 1.5f) / 5, (height / 1.5f) / 16);

	if (!ImGui::Begin("PAUSE MENU", &isWindowOpen, windowFlags))
	{
		// Early out if the window is collapsed, as an optimization.
		ImGui::End();
		return;
	}

	static bool isPaused = false;

	while (!isPaused && GetKeyState(VK_ESCAPE) & 0x80)
	{
		Sleep(1);
	}

	if (s_pHaloReachEngine)
	{
		if (!isPaused)
		{
			s_pHaloReachEngine->UpdateEngineState(eEngineState::Pause);
			isPaused = true;
		}

		if (ImGui::Button("RETURN TO GAME", gridButtonSize) || GetKeyState(VK_ESCAPE) & 0x80)
		{
			isPaused = false;
		}

		if (g_LaunchGameMode == e_game_mode::_game_mode_campaign)
		{
			if (ImGui::Button("REVERT TO LAST SAVE", gridButtonSize))
			{
				s_pHaloReachEngine->UpdateEngineState(eEngineState::RevertToLastSave);
				isPaused = false;
			}
		}

		if (g_LaunchGameMode == e_game_mode::_game_mode_multiplayer || g_LaunchGameMode == e_game_mode::_game_mode_survival)
		{
			if (ImGui::Button("END ROUND", gridButtonSize))
			{
				s_pHaloReachEngine->UpdateEngineState(eEngineState::EndRound);
				isPaused = false;
			}
		}

		if (g_LaunchGameMode == e_game_mode::_game_mode_campaign || g_LaunchGameMode == e_game_mode::_game_mode_survival)
		{
			if (ImGui::Button("RESTART GAME", gridButtonSize))
			{
				s_pHaloReachEngine->UpdateEngineState(eEngineState::RestartLevel);
				isPaused = false;
			}
		}

		if (ImGui::Button("RETURN TO MAINMENU", gridButtonSize))
		{
			s_pHaloReachEngine->UpdateEngineState(eEngineState::EndGame);
			isPaused = false;
		}

		if (!isPaused)
		{
			s_pHaloReachEngine->UpdateEngineState(eEngineState::Unpause);
			DebugUI::UnregisterCallback(GameLauncher::DrawPauseMenu);
			MouseInput::SetMode(MouseMode::Exclusive);
			DebugUI::Hide();
		}
	}

	ImVec2 mouseSensitivity = MouseInput::GetSensitivity();
	static float MouseSensitivityX = mouseSensitivity.x;
	static float MouseSensitivityY = mouseSensitivity.y;

	if (ImGui::InputFloat("Mouse Sensitivity X", &MouseSensitivityX, 0.01f, 0.1f, "%.3f"))
	{
		if (MouseSensitivityX > 1.0f) MouseSensitivityX = 1.0f;
		if (MouseSensitivityX < 0.0f) MouseSensitivityX = 0.0f;
	}

	if (ImGui::InputFloat("Mouse Sensitivity Y", &MouseSensitivityY, 0.01f, 0.1f, "%.3f"))
	{
		if (MouseSensitivityY > 1.0f) MouseSensitivityY = 1.0f;
		if (MouseSensitivityY < 0.0f) MouseSensitivityY = 0.0f;
	}

	if (MouseSensitivityX != mouseSensitivity.x || MouseSensitivityY != mouseSensitivity.y)
	{
		MouseInput::SetSensitivity(MouseSensitivityX, MouseSensitivityY);
	}

	ImGui::End();
}

void GameLauncher::InitSockets()
{
	WSADATA wsaData = {};
	// Initialize Winsock
	int WSAStartupResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (WSAStartupResult != 0)
	{
		FATAL_ERROR("WSAStartup failed with error: %d\n", WSAStartupResult);
	}
}

void GameLauncher::DeinitSockets()
{

}

void GameLauncher::LoadMapVariant(IDataAccess* pDataAccess, const char* pVariantName, s_map_variant& rMapVariant, bool print)
{
	memset(&rMapVariant, 0, sizeof(rMapVariant));

	if (pVariantName)
	{
		char pFileName[MAX_PATH] = {};
		if (g_MapVariantIsHopper)
		{
			sprintf(pFileName, "%s\\hopper_map_variants\\%s.mvar", s_pCurrentGameInterface->GetEngineName().c_str(), pVariantName);
		}
		else
		{
			sprintf(pFileName, "%s\\map_variants\\%s.mvar", s_pCurrentGameInterface->GetEngineName().c_str(), pVariantName);
		}
		pFileName[MAX_PATH - 1] = 0;

		c_file_reference filo(pFileName);
		if (filo.open_file())
		{
			if (print)
			{
				WriteLineVerbose("Loading map variant [%s]", pFileName);
			}

			rMapVariant = pDataAccess->MapVariantCreateFromFile(filo.pBuffer, static_cast<int>(filo.bufferSize))->MapVariant;
			filo.close_file();
			return;
		}
	}

	// fallback to use map ID
	{
		const MapInfo*& rpSelectedMapInfo = GetSelectedMapInfoByGameMode(g_LaunchGameMode);

		if (print)
		{
			WriteLineVerbose("Creating map variant for '%s'", rpSelectedMapInfo->GetFriendlyName());
		}

		rMapVariant = pDataAccess->MapVariantCreateFromMapID(rpSelectedMapInfo->GetMapID())->MapVariant;
	}
}

void GameLauncher::LoadGameVariant(IDataAccess* pDataAccess, const char* pVariantName, s_game_variant& rGameVariant, bool print)
{
	memset(&rGameVariant, 0, sizeof(rGameVariant));
	if (pVariantName == nullptr)
	{
		return;
	}

	char pFileName[MAX_PATH] = {};
	if (g_GameVariantIsHopper)
	{
		sprintf(pFileName, "%s\\hopper_game_variants\\%s.bin", s_pCurrentGameInterface->GetEngineName().c_str(), pVariantName);
	}
	else
	{
		sprintf(pFileName, "%s\\game_variants\\%s.bin", s_pCurrentGameInterface->GetEngineName().c_str(), pVariantName);
	}
	pFileName[MAX_PATH - 1] = 0;

	c_file_reference filo(pFileName);
	if (filo.open_file())
	{
		if (print)
		{
			WriteLineVerbose("Loading game variant [%s]", pFileName);
		}
		rGameVariant = pDataAccess->GameVariantCreateFromFile(filo.pBuffer, static_cast<int>(filo.bufferSize))->GameVariant;
		filo.close_file();
	}
}

// TODO: Test, and fix if broke
void GameLauncher::LoadPreviousGamestate(const char* pGamestateName, GameContext& gameContext)
{
	char pFileName[MAX_PATH] = {};
	sprintf(pFileName, "%s.hdr", pGamestateName);
	pFileName[MAX_PATH - 1] = 0;

	char* pGameStateBuffer = {};
	size_t gameStateSize = {};

	c_file_reference filo(pFileName);
	if (filo.open_file())
	{
		pGameStateBuffer = new char[filo.bufferSize];
		memset(pGameStateBuffer, 0x00, filo.bufferSize);
		pGameStateBuffer = filo.pBuffer;

		gameContext.GameMode = e_game_mode::_game_mode_campaign;
		gameContext.GameStateHeaderSize = filo.bufferSize;
		gameContext.pGameStateHeader = pGameStateBuffer;

		filo.close_file();
	}
}

void GameLauncher::LoadSavedFilmMetadata(const char* pSavedFilmName, GameContext& gameContext)
{
	if (!pSavedFilmName)
		return;

	static LPCSTR pFileName = "";
	if (!PathFileExists(pFileName = Format("%s\\Temporary\\autosave\\%s.film", s_pCurrentGameInterface->GetEngineName().c_str(), pSavedFilmName)))
	{
		if (!PathFileExists(pFileName = Format("%s\\Temporary\\autosave\\%s.mov", s_pCurrentGameInterface->GetEngineName().c_str(), pSavedFilmName)))
		{
			if (!PathFileExists(pFileName = Format("%s\\AppData\\LocalLow\\HaloMCC\\Temporary\\UserContent\\%s\\Movie\\%s.mov", GetUserprofileVariable(), s_pCurrentGameInterface->GetEngineName().c_str(), pSavedFilmName)))
			{
				pFileName = Format("%s\\AppData\\LocalLow\\MCC\\Temporary\\UserContent\\%s\\Movie\\%s.mov", GetUserprofileVariable(), s_pCurrentGameInterface->GetEngineName().c_str(), pSavedFilmName);
			}
		}
	}

	if (pFileName)
	{
		WriteLineVerbose("Loading saved film [%s]", pFileName);
	}

	gameContext.SavedFilmPath = pFileName;
}