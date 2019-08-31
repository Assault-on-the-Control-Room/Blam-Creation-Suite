#pragma once

/*
   This file has been generated by IDA.
   It contains local type definitions from
   the type library 'MCC-Win64-Shipping.exe'
*/

#define __int8 char
#define __int16 short
#define __int32 int
#define __int64 long long

#include "input_types.h"

struct _RTL_CRITICAL_SECTION_DEBUG;
struct IGameEngine;
struct GameEvents_vftbl;
struct GameEvents;
struct s_game_launch_data;

typedef void(NullSubFunc)();
typedef __int64(ZeroSubFunc)();

/* 514 */
struct /*VFT*/ IGameEngine_vtbl
{
	__int64(__fastcall *InitGraphics)(IGameEngine *, ID3D11Device *, ID3D11DeviceContext *, IDXGISwapChain *, IDXGISwapChain *);
	__int64(__fastcall *InitThread)(IGameEngine *, class IGameEngineHost *, s_game_launch_data *);
	__int64(__fastcall *Member02)(IGameEngine *, int, _QWORD *);
	__int64(__fastcall *Destructor)(IGameEngine *);
	void(__fastcall *Member04)();
	void(__fastcall *Member05)();
	void(__fastcall *Member06)();
	void(__fastcall *Member07)();
	void(__fastcall *Member08)();
	__int64(__fastcall *Member09)(IGameEngine *, const char *);
	__int64(__fastcall *Member10)();
};

/* 17 */
//typedef unsigned int DWORD;

/* 515 */
struct IGameEngine
{
	IGameEngine_vtbl *__vftable;
	DWORD unknown0;
	float unknown1;
	char unknown2[454];

	void InitGraphics(ID3D11Device *pID3D11Device, ID3D11DeviceContext *pContext, IDXGISwapChain *pSwapChain, IDXGISwapChain *pSwapChainFallback)
	{
		__vftable->InitGraphics(this, pID3D11Device, pContext, pSwapChain, pSwapChainFallback);
	}
	void InitThread(IGameEngineHost* gameEngineHostCallback, s_game_launch_data *gameLaunchData)
	{
		__vftable->InitThread(this, gameEngineHostCallback, gameLaunchData);
	}
};

struct c_game_engine_variant;
struct __declspec(align(8)) c_game_engine_variant_vtbl
{
	__int64(__fastcall *Member00)(c_game_engine_variant *);
	void *Member01;
	void(__fastcall *Member02)(c_game_engine_variant *);
	__int64(__fastcall *Member03)(c_game_engine_variant *);
	void *Member04;
	void *Member05;
	void *Member06;
	void *Member07;
	void *Member08;
	void *Member09;
	void *Member10;
	void *Member11;
	void(__fastcall *initialize_for_new_map)(c_game_engine_variant *, __int64, c_game_engine_variant **);
	void *Member13;
	void *Member14;
	__int64(__fastcall *Member15)(c_game_engine_variant *);
	void *Member16;
	__int64(__fastcall *Member17)(c_game_engine_variant *, _QWORD, _QWORD);
	void *Member18;
	void *Member19;
	void *Member20;
	void *Member21;
	unsigned __int8(__fastcall *Member22)(c_game_engine_variant *, __int64, __int64 *, unsigned __int64);
};

struct c_game_engine_variant
{
	c_game_engine_variant_vtbl *__vftable /*VFT*/;
	BYTE data[64504];
};

struct s_game_variant
{
	DWORD game_engine_index;
	c_game_engine_variant game_engine_variant;
};

struct s_map_variant
{
	BYTE data[55724];
};

struct ISaveFilmMetadata;
struct /*VFT*/ ISaveFilmMetadata_vtbl
{
	__int64(__fastcall *Member00)(ISaveFilmMetadata *);
	__int64(__fastcall *Member01)(ISaveFilmMetadata *);
	__int64(__fastcall *GetMapId)(ISaveFilmMetadata *);
	BYTE *(__fastcall *Member03)(ISaveFilmMetadata *);
	BYTE *(__fastcall *Member04)(ISaveFilmMetadata *);
	BYTE *(__fastcall *Member05)(ISaveFilmMetadata *);
	void(__fastcall *Free)(ISaveFilmMetadata *);
};
struct ISaveFilmMetadata
{
	ISaveFilmMetadata_vtbl *__vftable /*VFT*/;
	BYTE data[128936];
};

struct IMapVariant;
struct /*VFT*/ IMapVariant_vtbl
{
	__int64(__fastcall *GetMCCMapId)(IMapVariant *);
	bool(__fastcall *Member01)(IMapVariant *);
	BYTE *(__fastcall *Member02)(IMapVariant *);
	BYTE *(__fastcall *Member03)(IMapVariant *);
	__int64(__fastcall *Member04)(IMapVariant *, wchar_t *);
	__int64(__fastcall *Member05)(IMapVariant *, wchar_t *);
	BYTE *(__fastcall *Member06)(IMapVariant *, struct s_unknown *);
	bool(__fastcall *Member07)(IMapVariant *, struct s_unknown *);
	bool(__fastcall *Member08)(IMapVariant *, struct s_unknown *);
	bool(__fastcall *Member09)(IMapVariant *, struct content_item_map_variant *, size_t *);
	void(__fastcall *Free)(IMapVariant *);
};
struct IMapVariant
{
	IMapVariant_vtbl *__vftable /*VFT*/;
	s_map_variant MapVariant;
	BYTE data[29484];
};

struct IGameVariant;
struct /*VFT*/ IGameVariant_vtbl
{
	BYTE *(__fastcall *Member00)(IGameVariant *);
	BYTE *(__fastcall *Member01)(IGameVariant *);
	__int64(__fastcall *Member02)(IGameVariant *, wchar_t *);
	__int64(__fastcall *Member03)(IGameVariant *, wchar_t *);
	BYTE *(__fastcall *Member04)(IGameVariant *);
	__int64(__fastcall *Member05)(IGameVariant *);
	__int64(__fastcall *Member06)(IGameVariant *, struct s_unknown *);
	bool(__fastcall *IsSandboxVariant)(IGameVariant *);
	char(__fastcall *Member08)(IGameVariant *);
	__int64(__fastcall *Member09)(IGameVariant *);
	IGameVariant *(__fastcall *Create)(IGameVariant *);
	__int64(__fastcall *Member11)(IGameVariant *, struct s_unknown *, struct s_unknown *);
	__int64(__fastcall *Member12)(IGameVariant *, struct s_unknown *, struct s_unknown *);
	bool(__fastcall *Member13)(IGameVariant *, struct s_unknown *, struct s_unknown *);
	bool(__fastcall *Member14)(IGameVariant *, struct s_unknown *, struct s_unknown *);
	bool(__fastcall *Member15)(IGameVariant *, struct s_unknown *, struct s_unknown *);
	bool(__fastcall *Member16)(IGameVariant *, struct s_unknown *);
	bool(__fastcall *Member17)(IGameVariant *, struct s_unknown *);
	bool(__fastcall *Member18)(IGameVariant *, struct content_item_game_variant *, size_t *);
	void(__fastcall *Free)(IGameVariant *);
};
struct IGameVariant
{
	IGameVariant_vtbl *__vftable /*VFT*/;
	s_game_variant GameVariant;
	BYTE data[22060];
};

struct IDataAccess;
struct IDataAccess_vtbl
{
	struct IMapVariant *(__fastcall *CreateMapVariantFromFile)(IDataAccess *, /*struct content_item_map_variant **/char *, size_t);
	struct IMapVariant *(__fastcall *CreateMapVariantFromMCCMapId)(IDataAccess *, __int64);
	struct IMapVariant *(__fastcall *CreateMapVariant)(IDataAccess *, struct s_map_variant *);
	struct IGameVariant *(__fastcall *CreateGameVariantFromFile)(IDataAccess *, /*struct content_item_game_variant **/char *, size_t);
	struct IGameVariant *(__fastcall *CreateGameVariant)(IDataAccess *, struct s_game_variant *);
	bool (__fastcall *Member05)(IDataAccess *, struct s_unknown *, void *);
	struct ISaveFilmMetadata *(__fastcall *CreateSaveFilmMetadataFromFile)(IDataAccess *, /*struct content_item_film_description **/char *, size_t);
	void (__fastcall *Free)(IDataAccess *);
};

struct IDataAccess
{
	IDataAccess_vtbl* __vftable /*VFT*/;
	void* c_heap_allocation;
	void* function1;
	void* c_heap_allocation_size;
	void* function3;

	__int64 CreateMapVariantFromFile(char* content_item_map_variant, size_t file_length)
	{
		return (__int64)__vftable->CreateMapVariantFromFile(this, content_item_map_variant, file_length);
	}
	__int64 CreateGameVariantFromFile(char* content_item_game_variant, size_t file_length)
	{
		return (__int64)__vftable->CreateGameVariantFromFile(this, content_item_game_variant, file_length);
	}
};

/* 4 */
typedef struct _GUID GUID;

/* 23 */
typedef _RTL_CRITICAL_SECTION_DEBUG* PRTL_CRITICAL_SECTION_DEBUG;


/* 28 */
typedef void* HANDLE;

/* 29 */
typedef unsigned __int64 ULONG_PTR;


/* 520 */
struct __declspec(align(8)) UnknownType0
{
	QWORD qword0;
	QWORD* qword1;
	QWORD* qword2;
	DWORD dword0;
	DWORD dword1;
	QWORD qword4;
	QWORD* qword5;
	QWORD* qword6;
	DWORD dword2;
	DWORD dword3;
	DWORD dword4;
	DWORD dword5;
};

/* 519 */
struct GameEvents
{
	GameEvents_vftbl* vftbl;
	_WORD word0;
	_WORD word1;
	GUID guid;
	__unaligned __declspec(align(1)) _QWORD qword0;
	__unaligned __declspec(align(1)) _QWORD qword1;
	__unaligned __declspec(align(1)) _QWORD qword2;
	__unaligned __declspec(align(1)) _QWORD qword3;
	__unaligned __declspec(align(1)) _QWORD qword4;
	__unaligned __declspec(align(1)) _QWORD qword5;
	__unaligned __declspec(align(1)) _QWORD qword6;
	__unaligned __declspec(align(1)) _QWORD qword7;
	_DWORD dword0;
	_DWORD dword1;
	_DWORD dword2;
	_RTL_CRITICAL_SECTION rtlCriticalSection;
	_QWORD qword8;
	UnknownType0 unknownStruct;
	_QWORD qword9;
	_QWORD qwordA;
	_QWORD qwordB;
};

/* 518 */
struct __declspec(align(8)) GameEvents_vftbl
{
	NullSubFunc* AchievementEarned;
	NullSubFunc* AshesToAshes;
	NullSubFunc* Assist;
	NullSubFunc* AudioLogClaimed;
	NullSubFunc* Base;
	NullSubFunc* Betrayal;
	__int64(__fastcall* BIFactControllerSettings)(GameEvents*, unsigned __int64*, GUID*, _QWORD, __int64, _DWORD, int, int);
	NullSubFunc* BIFactDeepLinkRecieve;
	void(__fastcall* BIFactDeepLinkSend)(GameEvents*, _QWORD*, GUID*, _QWORD*, __int64*);
	NullSubFunc* BIFactDualWield;
	NullSubFunc* BIFactGameSession;
	NullSubFunc* BIFactLoadout;
	NullSubFunc* BIFactMatchmaking;
	NullSubFunc* BIFactMatchmakingDetails;
	NullSubFunc* BIFactMedia;
	NullSubFunc* BirdOfPrey;
	NullSubFunc* BitsAndPiecesDestroyed;
	NullSubFunc* BroadcastingAssist;
	NullSubFunc* BroadcastingDeath;
	NullSubFunc* BroadcastingHeartbeat;
	NullSubFunc* BroadcastingKill;
	NullSubFunc* BroadcastingMatchEnd;
	NullSubFunc* MultiplayerRoundEnd;
	NullSubFunc* MultiplayerRoundStart;
	NullSubFunc* BroadcastingMatchStart;
	NullSubFunc* BroadcastingMedal;
	NullSubFunc* BroadcastingPlayerJoined;
	NullSubFunc* BroadcastingPlayerLeft;
	NullSubFunc* BroadcastingPlayerSpawn;
	NullSubFunc* BroadcastingPlayerSwitchedTeams;
	NullSubFunc* BroadcastingScore;
	void(__fastcall* BroadcastingStart)(GameEvents*, _QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _QWORD, _QWORD, _DWORD, _QWORD);
	NullSubFunc* ChallengeCompleted;
	NullSubFunc* ClassicModeSwitched;
	NullSubFunc* CleverGirl;
	NullSubFunc* ClueClaimed;
	NullSubFunc* CompletionCount;
	NullSubFunc* Customization;
	NullSubFunc* DashboardContext;
	NullSubFunc* Death;
	NullSubFunc* DollFound;
	NullSubFunc* EliteWin;
	NullSubFunc* EnemyDefeated;
	NullSubFunc* FriendsBestedOnHeroLeaderboard;
	NullSubFunc* GameProgress;
	NullSubFunc* GameVarSaved;
	NullSubFunc* HelloNurse;
	NullSubFunc* InGamePresence;
	NullSubFunc* ISeeYou;
	NullSubFunc* Joinability;
	NullSubFunc* Lobby;
	NullSubFunc* MainMenuPresence;
	NullSubFunc* MapVarSaved;
	NullSubFunc* MatchmakingHopper;
	NullSubFunc* MediaUsage;
	NullSubFunc* MeldOfferPresented;
	NullSubFunc* MeldOfferResponded;
	NullSubFunc* MeldPageAction;
	NullSubFunc* MeldPageView;
	NullSubFunc* MissionCompleted;
	NullSubFunc* MortardomWraithsKilled;
	NullSubFunc* MultiplayerGameEngine;
	NullSubFunc* MultiplayerRoundEnd_0;
	NullSubFunc* MultiplayerRoundStart_0;
	NullSubFunc* NappersCaught;
	NullSubFunc* NewsStoryRead;
	NullSubFunc* ObjectiveEnd;
	NullSubFunc* ObjectiveStart;
	NullSubFunc* PageAction;
	NullSubFunc* PageView;
	NullSubFunc* PhantomHunter;
	NullSubFunc* PigsCanFly;
	NullSubFunc* PlayerCheckedInToday;
	NullSubFunc* PlayerDefeated;
	NullSubFunc* PlayerGameResults;
	NullSubFunc* PlayerGameResultsDamageStat;
	NullSubFunc* PlayerGameResultsGriefingStats;
	NullSubFunc* PlayerGameResultsInterestStats;
	NullSubFunc* PlayerGameResultsMedal;
	NullSubFunc* PlayerSessionEnd;
	NullSubFunc* PlayerSessionPause;
	NullSubFunc* PlayerSessionResume;
	NullSubFunc* PlayerSessionStart;
	NullSubFunc* PlayerSpawned;
	NullSubFunc* PlaylistCompleted;
	NullSubFunc* PlaylistProgress;
	NullSubFunc* RankedStatsDNFInfo;
	NullSubFunc* RankedStatsOverride;
	NullSubFunc* RankedStatsPenalty;
	NullSubFunc* RankedStatsUpdate;
	NullSubFunc* RankedUpSpartanIv;
	NullSubFunc* RealtimeFlagCaptured;
	NullSubFunc* RealtimeMedal;
	NullSubFunc* RealtimePilotedVehicle;
	NullSubFunc* RivalID;
	NullSubFunc* SectionEnd;
	NullSubFunc* SectionStart;
	NullSubFunc* SectionStats;
	NullSubFunc* SessionSizeUpdate;
	NullSubFunc* SizeIsEverything;
	NullSubFunc* SkeetShooter;
	NullSubFunc* SkullClaimed;
	NullSubFunc* SpartanOpsMissionCompleted;
	NullSubFunc* TerminalFound;
	NullSubFunc* TicketsEarned;
	NullSubFunc* TitleCompleted;
	NullSubFunc* TitleLaunched;
	NullSubFunc* ValhallaSign;
	NullSubFunc* ViewOffer;
	NullSubFunc* VIPStatusEarned;
	NullSubFunc* WhatAboutTanksDestroyed;
	NullSubFunc* WonWarGame;
	NullSubFunc* ZanzibarSign;
	NullSubFunc* EnemyDefeated_0;
	NullSubFunc* Member114;
	NullSubFunc* Member115;
	NullSubFunc* Member116;
	NullSubFunc* Member117;
	NullSubFunc* Member118;
	NullSubFunc* Member119;
	__int64(__fastcall* Member120)(GameEvents*, _QWORD);
	NullSubFunc* Member121;
	GUID* (__fastcall* GetGuid)(GameEvents*, GUID*);
	NullSubFunc* Member123;
	NullSubFunc* Member124;
	NullSubFunc* Member125;
};

/* 20 */
typedef unsigned __int16 WORD;


/* 25 */
typedef _LIST_ENTRY LIST_ENTRY;



/* 522 */
struct UnknownStringType
{
	char data[48];
};

enum e_campaign_difficulty_level : int
{
	_campaign_difficulty_level_easy,
	_campaign_difficulty_level_normal,
	_campaign_difficulty_level_heroic,
	_campaign_difficulty_level_legendary,

	k_number_of_campaign_difficulty_levels,
};


enum e_map_id : int
{
	// TODO: add other games

	// reach
	_map_id_m05 = 178,
	_map_id_m10,
	_map_id_m20,
	_map_id_m30,
	_map_id_m35,
	_map_id_m45,
	_map_id_m50,
	_map_id_m52,
	_map_id_m60,
	_map_id_m70,
	_map_id_m70_a,
	_map_id_m70_bonus,
	_map_id_50_panopticon,
	_map_id_70_boneyard,
	_map_id_45_launch_station,
	_map_id_30_settlement,
	_map_id_52_ivory_tower,
	_map_id_35_island,
	_map_id_20_sword_slayer,
	_map_id_45_aftship,
	_map_id_dlc_slayer,
	_map_id_dlc_invasion,
	_map_id_dlc_medium,
	_map_id_condemned,
	_map_id_trainingpreserve,
	_map_id_cex_beaver_creek,
	_map_id_cex_damnation,
	_map_id_cex_timberland,
	_map_id_cex_prisoner,
	_map_id_cex_hangemhigh,
	_map_id_cex_headlong,
	_map_id_forge_halo,
	_map_id_ff50_park,
	_map_id_ff45_corvette,
	_map_id_ff20_courtyard,
	_map_id_ff60_icecave,
	_map_id_ff70_holdout,
	_map_id_ff60_ruins,
	_map_id_ff10_prototype,
	_map_id_ff30_waterfront,
	_map_id_ff_unearthed,
	_map_id_cex_ff_halo,

	k_number_of_map_ids
};

enum e_game_mode : int
{
	_game_mode_none,

	_game_mode_campaign,
	_game_mode_multiplayer,

	// we assume these
	//_game_mode_map_editor,
	//_game_mode_saved_film,

	_game_mode_survival = 5,

	k_number_of_game_modes,
};

typedef uint64_t XnkId;
struct XnkAddr
{
	int maybeip;
	uint8_t Data[20];
};

struct s_game_launch_data_memzero
{
	s_game_launch_data_memzero()
	{

	}
	s_game_launch_data_memzero(size_t size)
	{
		memset(this, 0, size);
	}
};

struct s_party_data
{
	XnkId SquadId;
	XnkId LocalId;
	bool IsHost; // if client, is false
	__declspec(align(8)) struct
	{
		XnkId PeerIds[17];
		uint32_t PeerCount; // if client, is 0
	};
	__declspec(align(8)) struct
	{
		XnkAddr PlayerIds[16];
		int64_t PlayerCount; // if client, is 0
	};
	XnkId HostId; // if client, is LocalId
};
static constexpr size_t PartyData_HostId_Offset = offsetof(s_party_data, s_party_data::HostId);
static_assert(PartyData_HostId_Offset == 0x230);
static constexpr size_t PartyDataSize = sizeof(s_party_data);
static_assert(PartyDataSize == 0x238);

#pragma pack(push, 1)
struct __cppobj s_game_launch_data : s_game_launch_data_memzero
{
	s_game_launch_data(const s_game_launch_data& original)
		: pGameHandle(GetModuleHandleA("HaloReach.dll"))
	{

	}

	s_game_launch_data()
		: s_game_launch_data_memzero(sizeof(s_game_launch_data))
		, pGameHandle(GetModuleHandleA("HaloReach.dll"))
		//, unknown0(1)
		////gap0
		//, dword2B40C(182)
		//, unsigned2B410(0)
		////gap2B414
		//, qword2B430(0)
		//, dword2B438(0)
		//, dword2B43C(0)
		//, unknownQword0(0)
		//, unknownQword1(0)
		//, a()
		//, b(1)
		////gap2B460
		////byte2B680
		//, languageString(L"en-US")
		////unknown6bytes1
		////phinstance__2B748
		//, dword2B750(1525022720)
		//, dword2B754(32763)
		////gap2B758
		////pqword2B798
		//, dword2B7A0(812910640)
		//, qword2B7A8(47244641008)
	{


		//memset(gameVariantData, 0, sizeof(gameVariantData));
		//memset(gap2B414, 0, sizeof(gap2B414));
		//memset(gap2B460, 0, sizeof(gap2B460));
		//memset(byte2B680, 0, sizeof(byte2B680));
		//memset(gap2B758, 0, sizeof(gap2B758));

		//unsigned char byte2B4E4Data[16][0x18] =
		//{
		//	{ 0xC0, 0x51, 0xA8, 0x31, 0xFE, 0x01, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
		//	{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
		//	{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
		//	{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
		//	{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
		//	{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
		//	{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
		//	{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
		//	{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
		//	{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
		//	{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
		//	{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
		//	{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
		//	{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
		//	{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
		//	{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }
		//};
		//static_assert(sizeof(byte2B4E4) == sizeof(byte2B4E4Data), "This should match");
		//memcpy(byte2B4E4, byte2B4E4Data, sizeof(byte2B4E4));

		//FILE* pFile = fopen("C:\\!MCC\\output2.bin", "r");
		//fread(this, 1, sizeof(this), pFile);
		//fclose(pFile);

	}

#ifdef ZEROONEZERO
#define COLOR0 <bgcolor=0xFF0000>
#define COLOR1 <bgcolor=0x00FF00>
#define COLOR2 <bgcolor=0x0000FF>
#define COLOR3 <bgcolor=0xFF00FF>
#define COLOR4 <bgcolor=0x00FFFF>
#define COLOR5 <bgcolor=0xFFFF00>
#else
#define COLOR0
#define COLOR1
#define COLOR2
#define COLOR3
#define COLOR4
#define COLOR5
#endif

	int32_t GameMode = _game_mode_campaign;
	union
	{
		uint8_t GameVariantBuffer[115 * 1024] = {};
		s_game_variant halo_reach_game_variant;
	};
	union
	{
		uint8_t MapVariantBuffer[58 * 1024] = {};
		s_map_variant halo_reach_map_variant;
	};
	// [180330500, mcc_id_to_reach_map_id,   https://pastebin.com/r3ihQagj]
	// [180330BD0, mcc_id_to_reach_map_name, https://pastebin.com/Qx72e0G6]
	e_map_id MapId = _map_id_m35;
	e_campaign_difficulty_level CampaignDifficultyLevel = _campaign_difficulty_level_easy;
	int16_t CampaignInsertionPoint = 0;
	uint16_t : 16;
	uint64_t : 64;
	int8_t GameSkullFlags[16] = {};
	uint8_t* pGameStateHeader = nullptr;
	size_t GameStateHeaderSize = 0;
	const char* SavedFilmPath = nullptr;

	s_party_data PartyData;

	uint8_t byte2B678[8] = {
		0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	};
	const wchar_t *GamePath = nullptr;
	wchar_t Locale[88] = L"en-US";
	uint32_t dword2B738 = 1;
	uint32_t dword2B73C = 1;
	HMODULE pGameHandle = 0;
	uint32_t EngineIndex0 = 6;
	uint32_t EngineIndex1 = 6;
	uint8_t unknownStruct2B750[48] = {}; // changes
	uint64_t qword2B780 = 0;
	uint64_t qword2B788 = 0;
	struct RallyPointLoader* pRallyPointLoader = nullptr; // changes // WARNING: this is needed for MCC to run don't overwrite
	uint32_t dword2B798 = 11;
	uint32_t dword2B79C = 0;
	uint64_t qword2B7A0 = 0; // changes
	uint64_t qword2B7A8 = 0;
	uint8_t byte2B7B0 = 0;
	uint8_t byte2B7B1 = 0;
	uint16_t word2B7B2 = 0;
	uint16_t word2B7B4 = 0;
	uint16_t word2B7B6 = 0;
	uint64_t qword2B7B8 = 0; // changes
	uint32_t dword2B7C0 = 0;
	uint32_t dword2B7C4 = 0;
};
#pragma pack(pop)
static constexpr size_t s_game_launch_data_size = sizeof(s_game_launch_data);
static_assert(s_game_launch_data_size == 0x2B7C8, "");
static_assert(offsetof(s_game_launch_data, s_game_launch_data::pGameHandle) == 0x2B740, "");

struct s_game_launcher
{
	_DWORD dword0;
	_DWORD dword4;
	s_game_launch_data GameLaunchData;
};
static_assert(sizeof(s_game_launcher) == 0x2B7D0, "");

enum e_load_state
{
	_load_state_initial,
	_load_state_create_local_squad,
	_load_state_select_game_mode,
	_load_state_saved_film,
	_load_state_campaign,
	_load_state_previous_game_state,
	_load_state_multiplayer,
	_load_state_survival,
	_load_state_wait_for_party,
	_load_state_join_remote_squad,
	_load_state_unused,
	_load_state_start_game,
	_load_state_terminate,

	k_number_of_load_states,
	k_load_state_invalid = -1,
};

enum e_peer_property
{
	_peer_property_none,
	_peer_property_network_configuration_unavailable,
	_peer_property_file_manifest_unavailable,
	_peer_property_banhammer_unavailable,
	_peer_property_player_stats_unavailable,
	_peer_property_lsp_stats_unavailable,
	_peer_property_master_hopper_file_unavailable,
	_peer_property_hopper_specific_file_unavailable,
	_peer_property_network_configuration_pending,
	_peer_property_file_manifest_pending,
	_peer_property_dlc_map_manifest_pending,
	_peer_property_dlc_enumeration_pending,
	_peer_property_banhammer_pending,
	_peer_property_player_stats_pending,
	_peer_property_lsp_stats_pending,
	_peer_property_master_hopper_file_pending,
	_peer_property_hopper_specific_file_pending,
	_peer_property_no_map_selected,
	_peer_property_no_game_selected,
	_peer_property_map_load_failure,
	_peer_property_map_load_precaching,
	_peer_property_invalid_film_selected,
	_peer_property_no_film_selected,
	_peer_property_too_many_teams,
	_peer_property_all_observers,
	_peer_property_too_many_for_local_coop,
	_peer_property_too_many_for_net_coop,
	_peer_property_incompatible_for_net_coop,
	_peer_property_account_not_online_enabled,
	_peer_property_all_profiles_must_by_live_gold,
	_peer_property_must_be_connect_to_live,
	_peer_property_must_be_in_a_live_lobby,
	_peer_property_invalid_hopper,
	_peer_property_squad_too_large,
	_peer_property_squad_too_small,
	_peer_property_too_many_local_players,
	_peer_property_too_few_local_players,
	_peer_property_non_local_players_exist,
	_peer_property_games_played_too_low,
	_peer_property_games_played_too_high,
	_peer_property_grade_too_low,
	_peer_property_grade_too_high,
	_peer_property_access_bit_not_set,
	_peer_property_unpaid_in_paid_hopper,
	_peer_property_paid_in_unpaid_hopper,
	_peer_property_guest_not_allowed,
	_peer_property_player_missing_files,
	_peer_property_player_missing_required_maps,
	_peer_property_player_banned_from_matchmaking,
	_peer_property_matchmaking_ban_quitting,
	_peer_property_not_yet_start_time,
	_peer_property_end_time_has_passed,
	_peer_property_arena_hopper_no_longer_available,
	_peer_property_hd_required_for_playlist,
	_peer_property_custom_games_are_disabled,
	_peer_property_multiplayer_split_screen,
	_peer_property_no_live_in_live_lobby,
	_peer_property_must_have_live_for_alpha,
	_peer_property_only_one_player_in_theater_alpha,
	_peer_property_theater_too_many_players,
	_peer_property_theater_must_have_hard_drive,
	_peer_property_theater_leader_must_be_host,
	_peer_property_theater_all_not_compatible,
	_peer_property_too_many_players_in_forge,
	_peer_property_user_content_not_permitted,
	_peer_property_coop_player_missing_hdd,
	_peer_property_coop_player_hdd_mismatch,
	_peer_property_coop_player_language_mismatch,
	_peer_property_invalid_film_language,
	_peer_property_controller_not_attached,
	_peer_property_survival_too_many_players,
	_peer_property_queued_join_expected,
	_peer_property_map_and_game_incompatible,

	k_number_of_peer_properties
};

enum e_scenario_type : int
{
	_scenario_type_none,
	_scenario_type_campaign,
	_scenario_type_multiplayer,
	_scenario_type_mainmenu,
	_scenario_type_shared,
	_scenario_type_shared_campaign,
	_scenario_type_unused5,
	_scenario_type_unused6,

	k_number_of_scenario_types,
};

struct s_game_options
{
	e_scenario_type scenario_type;
	BYTE game_simulation[8];
	WORD frame_limit;
	WORD unknownE;
	BYTE game_instance[8];
	DWORD random_seed;
	DWORD language;
	BYTE campaign_id;
	DWORD determinism_version;
	BYTE game_variant[0xFC04];
	DWORD map_id;
	BYTE unknownFC30[4];
	char scenario_path[260];
	BYTE unknownFE94[129];
	BYTE game_is_playtest;
	BYTE unknownFF16[18];
	DWORD campaign_difficulty;
	BYTE unknownFF2C[299];
	BYTE map_variant[0xD9AC];
	BYTE unknown1DA03[4345];
};
static_assert(sizeof(s_game_options) == 0x1E9A0, "");

struct s_game_state_header
{
	DWORD* unknown0;
	char source_file[256];
	char build[32];
	DWORD unknown108;
	BYTE unknown10C[4];
	s_game_options game_options;
	BYTE scenario_game_state[24];
	BYTE unknown24C90[64];
};
static_assert(sizeof(s_game_state_header) == 0x1EB28, "");

struct s_game_globals
{
	BYTE unknown0[16];
	s_game_options game_options;
	BYTE unknown1E9B0[1584];
};
static_assert(sizeof(s_game_globals) == 0x1EFE0, "");

template<typename T>
struct point3d
{
	T X, Y, Z;
};

template<typename T>
struct vector3d
{
	T I, J, K;
};

struct s_camera
{
	point3d<float> Position;
	point3d<float> PositionShift;
	float Look;
	float LookShift;
	float Depth;
	float FOVRadians;
	vector3d<float> Forward;
	vector3d<float> Up;
	vector3d<float> Direction;

	//...

	bool Compare(s_camera* camera)
	{
		auto position = Position.X != camera->Position.X || Position.Y != camera->Position.Y || Position.Z != camera->Position.Z;
		auto positionShift = PositionShift.X != camera->PositionShift.X || PositionShift.Y != camera->PositionShift.Y || PositionShift.Z != camera->PositionShift.Z;
		auto look = Look != camera->Look;
		auto lookShift = LookShift != camera->LookShift;
		auto depth = Depth != camera->Depth;
		auto fovRadians = FOVRadians != camera->FOVRadians;
		auto forward = Forward.I != camera->Forward.I || Forward.J != camera->Forward.J || Forward.K != camera->Forward.K;
		auto up = Up.I != camera->Up.I || Up.J != camera->Up.J || Up.K != camera->Up.K;
		auto direction = Direction.I != camera->Direction.I || Direction.J != camera->Direction.J || Direction.K != camera->Direction.K;

		return position || positionShift || look || lookShift || depth || fovRadians || forward || up || direction;
	}
};

struct s_player_control_globals
{
	BYTE unknown0[0x94];
	float hLookAngle;
	float vLookAngle;
	BYTE unknown9C[0x894];
};
static_assert(sizeof(s_player_control_globals) == 0x930, "");

struct s_director_globals
{
	BYTE unknown0[0x6F0];
};
static_assert(sizeof(s_director_globals) == 0x6F0, "");