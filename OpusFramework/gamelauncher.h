#pragma once

class GameLauncher
{
public:
	enum class CurrentState
	{
		eInactive,
		eMainMenu,
		eWaitingToRun,
		eRunning,
		eFinished
	};

	enum class SelectedGameModeMapInfoIndex
	{
		Campaign,
		Multiplayer,
		Firefight,
		Unknown,
		Count
	};

	typedef void(GameLaunchCallback)(EngineVersion engineVersion, BuildVersion buildVersion);
	typedef void(GameShutdownCallback)(EngineVersion engineVersion, BuildVersion buildVersion);

	static void Init(HINSTANCE hInstance, LPSTR lpCmdLine);
	static void Deinit();
	static void RegisterTerminationValue(char& rTerminationReference);

	static void SetupGlobalHooks();
	static bool HasCommandLineArg(const char* pArgument);
	static void Terminate();
	static void EnsureBink2Win64IsLoaded(const char* pLibName, const char* pFallbackDir = "");
	static void RegisterGameLaunchCallback(EngineVersion engineVersion, GameLaunchCallback gameLaunchCallback);
	static void RegisterGameShutdownCallback(EngineVersion engineVersion, GameShutdownCallback gameShutdownCallback);
	static void LoadSettings();
	static int Run(HINSTANCE hInstance, LPSTR lpCmdLine, GameInterface& rGameInterface);
	static void SetupGameContext(GameContext& gameContext);
	static void LaunchGame();
	static void SetState(CurrentState state);
	static void Update();
	static void Render();
	static void BeginRender();
	static void EndRender();
	static void DrawMainMenu();
	static void DrawPauseMenu();

	static const MapInfo* GetDefaultMapSelection(SelectedGameModeMapInfoIndex gameModeMapInfoIndex);
	static void SelectGameMode();
	static bool IsMapInfoCompadibleWithGameMode(e_game_mode gameMode, const MapInfo& rMapInfo);
	static const MapInfo* GetFirstSuitableGameModeMapInfo(e_game_mode gameMode);
	static void SaveSelectedMap(e_game_mode gameMode, const MapInfo* pMapInfo);
	static SelectedGameModeMapInfoIndex GameModeToSelectedGameModeMapInfoIndex(e_game_mode gameMode);
	static e_game_mode SelectedGameModeMapInfoIndexToGameMode(SelectedGameModeMapInfoIndex selectedGameModeMapInfoIndex);
	static const MapInfo*& GetSelectedMapInfoBySelectedGameModeMapInfoIndex(SelectedGameModeMapInfoIndex selectedGameModeMapInfoIndex);
	static const MapInfo*& GetSelectedMapInfoByGameMode(e_game_mode gameMode);
	static void SelectMap();
	static void SelectDifficulty();
	static void SelectGameVariant();
	static void SelectMapVariant();
	static void SelectSavedFilm();

	static void InitSockets();
	static void DeinitSockets();

	static void CheckSteamAPI();
	static void InitMapInfoManager();
	static void DeinitMapInfoManager();

	static void LoadMapVariant(IDataAccess* pDataAccess, const char* pVariantName, s_map_variant& out_variant, bool print = false);
	static void LoadGameVariant(IDataAccess* pDataAccess, const char* pVariantName, s_game_variant& out_variant, bool print = false);
	static void LoadPreviousGamestate(const char* pFileName, GameContext& gameContext);
	static void LoadSavedFilmMetadata(const char* pSavedFilmName, GameContext &gameContext);
	static char* s_pTerminationFlag;
	BuildVersion GetCurrentbuildVersion();
	static bool s_gameManuallyKilled;
	static bool s_hideWindowOnStartup; 

	static CurrentState s_currentState;
	// #TODO: Implement a map and vector for this!!!
	static GameLaunchCallback* s_gameLaunchCallback;
	static GameShutdownCallback* s_gameShutdownCallback;
	static GameInterface* s_pCurrentGameInterface;
	static IGameEngine* s_pHaloReachEngine;
	static std::atomic<int> s_uiStackLength;
	static MapInfoManager* s_pMapInfoManager;

	static const MapInfo* s_pSelectedMapInfo[underlying_cast(SelectedGameModeMapInfoIndex::Count)];
	static constexpr const char* s_kpMapInfoSettingsName[underlying_cast(SelectedGameModeMapInfoIndex::Count)] = { "LastCampaignMap", "LastMultiplayerMap", "LastSurvivalMap", "LastUnknownGamemodeMap" };
};

