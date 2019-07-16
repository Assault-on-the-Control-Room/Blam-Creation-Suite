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

struct _RTL_CRITICAL_SECTION_DEBUG;
struct IGameEngine;
struct GameEvents_vftbl;
struct GameEvents;
struct GameEngineHostCallback_vftbl;
struct GameEngineHostCallback;

typedef void(NullSubFunc)();

/* 514 */
struct __declspec(align(8)) IGameEngine_vftbl
{
	void(__fastcall* InitGraphics)(IGameEngine*, __int64, __int64, __int64, __int64);
	void(__fastcall* InitThread)(IGameEngine*, GameEngineHostCallback*, __int64);
	void* Member02;
	void* Member03;
	void* Member04;
	void* Member05;
	void* Member06;
	void* Member07;
	void* Member08;
	void* Member09;
	void* Member10;
};

/* 17 */
//typedef unsigned int DWORD;

/* 515 */
struct IGameEngine
{
	IGameEngine_vftbl* vftbl;
	DWORD unknown0;
	float unknown1;
	char unknown2[454];

	void InitGraphics(__int64 a1, __int64 a2, __int64 /*IDXGISwapChain **/pSwapChain, __int64 a4)
	{
		vftbl->InitGraphics(this, a1, a2, pSwapChain, a4);
	}
	void InitThread(GameEngineHostCallback* gameEngineHostCallback, __int64 a2)
	{
		vftbl->InitThread(this, gameEngineHostCallback, a2);
	}
};

/* 516 */
struct GameEngineHostCallback_vftbl
{
	NullSubFunc* Member00;
	NullSubFunc* Member01;
	NullSubFunc* Member02;
	NullSubFunc* Member03;
	NullSubFunc* Member04;
	void(__fastcall* WriteGameState)(GameEngineHostCallback*, LPVOID, size_t);
	NullSubFunc* Member06;
	NullSubFunc* Member07;
	NullSubFunc* Member08;
	NullSubFunc* Member09;
	NullSubFunc* Member10;
	NullSubFunc* Member11; // DataAccessGameVariant
	NullSubFunc* Member12; // DataAccessMapVariant
	NullSubFunc* Member13;
	NullSubFunc* Member14;
	NullSubFunc* Member15;
	NullSubFunc* Member16;
	NullSubFunc* Member17;
	NullSubFunc* Member18;
	NullSubFunc* Member19;
	NullSubFunc* Member20;
	NullSubFunc* Member21;
	NullSubFunc* Member22;
	NullSubFunc* Member23;
	NullSubFunc* Member24;
	NullSubFunc* Member25;
	NullSubFunc* Member26;
	NullSubFunc* Member27;
	NullSubFunc* Member28;
	NullSubFunc* Member29;
	NullSubFunc* Member30;
	NullSubFunc* Member31;
	NullSubFunc* Member32;
	NullSubFunc* Member33;
	NullSubFunc* Member34;
	NullSubFunc* Member35;
	NullSubFunc* Member36;
	NullSubFunc* Member37;
	NullSubFunc* Member38;
	NullSubFunc* Member39;
	NullSubFunc* Member40;
	NullSubFunc* Member41;
	NullSubFunc* Member42;
};

/* 517 */
struct __declspec(align(8)) GameEngineHostCallback
{
	GameEngineHostCallback_vftbl* vftbl;
	GameEvents* pGameEvents;
	QWORD data1[5863];
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
	NullSubFunc* Member00;
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

/* 523 */
#pragma pack(push, 1)
struct GameLauncher
{
	_DWORD dword0;
	_DWORD dword1;
	char unknownStruct0[177976];
	_DWORD dword2;
	_DWORD dword3;
	_QWORD qword0;
	_QWORD qword1;
	char unknownStruct1[48];
	_QWORD qword2;
	_QWORD qword3;
	_QWORD qword4;
	_DWORD dword4;
	_DWORD dword5;
	_QWORD qword5;
	_QWORD qword6;
	_WORD word0;
	_WORD word1;
	_WORD word2;
	_WORD word3;
	_QWORD qword7;
	_DWORD dword6;
	_DWORD dword7;
};
#pragma pack(pop)


struct struct_b1_memzero
{
	struct_b1_memzero(size_t size)
	{
		memset(this, 0, size);
	}
};

#pragma pack(push, 1)
struct __cppobj struct_b1 : struct_b1_memzero
{
	struct_b1()
		: struct_b1_memzero(sizeof(struct_b1))
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

		//------------------------------------------------------------
		//-----------       Created with 010 Editor        -----------
		//------         www.sweetscape.com/010editor/          ------
		//
		// File    : C:\Users\User\Desktop\output.bin
		// Address : 177240 (0x2B458)
		// Size    : 544 (0x220)
		//------------------------------------------------------------
		unsigned char gap2B460Data[544] = {
			0x02, 0x97, 0x79, 0x37, 0xB8, 0xBA, 0x98, 0xED, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0xC0, 0x51, 0xA8, 0x31, 0xFE, 0x01, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
		};
		static_assert(sizeof(gap2B460) == sizeof(gap2B460Data), "This should match");
		memcpy(gap2B460, gap2B460Data, sizeof(gap2B460));

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

	_DWORD unknown0 COLOR0;
	_BYTE gameVariantData[173 * 1024] COLOR1;
	_DWORD dword2B40C COLOR2;
	unsigned int unsigned2B410 COLOR3;
	_BYTE gap2B414[28] COLOR4;
	_QWORD qword2B430 COLOR5;
	_DWORD dword2B438 COLOR0;
	_DWORD dword2B43C COLOR1;
	const char* unknownQword0 COLOR2;
	_QWORD unknownQword1 COLOR3;
	_QWORD a COLOR4;
	_QWORD b COLOR5;
	_BYTE gap2B460[544] COLOR0;
	_BYTE byte2B680[16] COLOR1;
	wchar_t languageString[0x55] COLOR4;
	_BYTE unknown6bytes1[6] COLOR5;
	HMODULE phinstance__2B748 COLOR0;
	_DWORD dword2B750 COLOR1;
	_DWORD dword2B754 COLOR2;
	_BYTE gap2B758[64] COLOR3;
	_QWORD pqword2B798 COLOR4;
	_DWORD dword2B7A0 COLOR5;
	_QWORD qword2B7A8 COLOR0;
};
#pragma pack(pop)


