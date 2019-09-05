#pragma once

/*
   This file has been generated by IDA.
   It contains local type definitions from
   the type library 'haloreach.dll'
*/

struct c_network_session;
struct c_network_session_parameter_base_vtbl;

/* 369 */
enum e_network_session_class
{
	_network_session_class_none = 0x0,
	_network_session_class_offline = 0x1,
	_network_session_class_system_link = 0x2,
	_network_session_class_xbox_live = 0x3,
	k_network_session_class_count = 0x4,
};

/* 70 */
typedef unsigned __int8 BYTE;

/* 367 */
#pragma pack(push, 1)
struct s_network_session_peer
{
	_QWORD machine_identifier;
	DWORD unknown8;
	BYTE unknownC[340];
};
#pragma pack(pop)
static_assert(sizeof(s_network_session_peer) == 352, "s_network_session_peer invalid size");

/* 365 */
#pragma pack(push, 1)
struct s_network_session_player
{
	int desired_configuration_version;
	_QWORD player_identifier;
	int peer_index;
	char unknown10[16];
	wchar_t player_name[32];
	char unknown60[4];
	wchar_t service_tag[6]; // not sure if 6 bytes big
	char unknownA0[104];
	wchar_t player_name2[32];
};
#pragma pack(pop)
static_assert(sizeof(s_network_session_player) == 0x118, "s_network_session_player invalid size");

/* 366 */
struct c_network_session_membership
{
	c_network_session* m_session;
	int m_baseline_update_number;
	int m_leader_peer_index;
	int m_host_peer_index;
	int unknown14;
	int m_private_slot_count;
	int m_public_slot_count;
	__int64 m_friends_only;
	int m_peer_count;
	int m_valid_peer_mask;
	s_network_session_peer m_peers[17];
	int m_player_count;
	int m_valid_player_mask;
	s_network_session_player m_players[16];
	int m_player_sequence_number;
	int unknown291C;
	BYTE m_incremental_update_buffers[10460];
	int m_incremental_updates[17];
	int unknown5240;
	int m_local_peer_index;
	BYTE unknown5248[1120];
};

/* 370 */
enum e_network_session_parameter_type
{
	_network_session_parameter_type_session_size = 0x0,
	_network_session_parameter_type_life_cycle = 0x1,
	_network_session_parameter_type_privacy_mode = 0x2,
	_network_session_parameter_type_ui_game_mode = 0x3,
	_network_session_parameter_type_start_mode = 0x4,
	_network_session_parameter_type_end_game = 0x5,
	_network_session_parameter_type_map = 0x6,
	_network_session_parameter_type_initial_participants = 0x7,
	_network_session_parameter_type_game_instance = 0x8,
	_network_session_parameter_type_random_seed = 0x9,
	_network_session_parameter_type_language = 0xA,
	_network_session_parameter_type_determinism_version = 0xB,
	_network_session_parameter_type_simulation_protocol = 0xC,
	_network_session_parameter_type_campaign_difficulty = 0xD,
	_network_session_parameter_type_active_skulls = 0xE,
	_network_session_parameter_type_campaign_metagame_scoring = 0xF,
	_network_session_parameter_type_campaign_insertion_point = 0x10,
	_network_session_parameter_type_game_variant = 0x11,
	_network_session_parameter_type_map_variant = 0x12,
	_network_session_parameter_type_saved_film = 0x13,
	_network_session_parameter_type_game_start_status = 0x14,
	_network_session_parameter_type_countdown_timer = 0x15,
	_network_session_parameter_type_requested_remote_join_data = 0x16,
	_network_session_parameter_type_remote_join_data = 0x17,
	_network_session_parameter_type_active_roster_outgoing_join_request = 0x18,
	_network_session_parameter_type_active_roster_outgoing_join_data = 0x19,
	_network_session_parameter_type_active_roster_incoming_join_data = 0x1A,
	_network_session_parameter_type_matchmaking_arbitration_nonce = 0x1B,
	_network_session_parameter_type_matchmaking_host_selected = 0x1C,
	_network_session_parameter_type_matchmaking_hopper_list = 0x1D,
	_network_session_parameter_type_matchmaking_requested_hopper = 0x1E,
	_network_session_parameter_type_matchmaking_hopper = 0x1F,
	_network_session_parameter_type_matchmaking_abort_requested = 0x20,
	_network_session_parameter_type_matchmaking_search_preference = 0x21,
	_network_session_parameter_type_matchmaking_progress = 0x22,
	_network_session_parameter_type_matchmaking_progress_search_criteria = 0x23,
	_network_session_parameter_type_matchmaking_assembly_peer_evict_mask = 0x24,
	_network_session_parameter_type_matchmaking_rematch_data = 0x25,
	_network_session_parameter_type_matchmaking_hopper_statistics = 0x26,
	_network_session_parameter_type_matchmaking_tip = 0x27,
	_network_session_parameter_type_matchmaking_messaging = 0x28,
	_network_session_parameter_type_matchmaking_voting_results = 0x29,
	_network_session_parameter_type_matchmaking_voting_rounds = 0x2A,
	_network_session_parameter_type_matchmaking_voting_descriptions = 0x2B,
	_network_session_parameter_type_matchmaking_game_configuration = 0x2C,
	_network_session_parameter_type_synchronous_out_of_sync = 0x2D,
	_network_session_parameter_type_request_campaign_quit = 0x2E,
	_network_session_parameter_type_leader_properties = 0x2F,
	_network_session_parameter_type_synchronous_halt_state = 0x30,
	_network_session_parameter_type_speculative_migration = 0x31,
	_network_session_parameter_type_voice_repeater = 0x32,
	_network_session_parameter_type_scoreboard_quality = 0x33,
	_network_session_parameter_type_network_quality = 0x34,
	k_network_session_parameter_type_count = 0x35,
};

/* 371 */
struct c_network_session_parameter_base
{
	c_network_session_parameter_base_vtbl* __vftable /*VFT*/;
	e_network_session_parameter_type m_type;
	int baseDataC;
	const char* m_name;
	c_network_session* m_session;
	int baseData20;
	int baseData24;
	float baseData28;
	float baseData2C;
	BYTE baseData30[80];
	BYTE m_state_flags;
	BYTE baseData81[7];
};

/* 372 */
struct __cppobj c_network_session_parameter_session_size : c_network_session_parameter_base
{
	BYTE unknown0[4];
	DWORD max_players;
	BYTE unknown8[8];
};

/* 373 */
struct __cppobj c_network_session_parameter_life_cycle : c_network_session_parameter_base
{
	BYTE data[24];
};

/* 374 */
struct __cppobj c_network_session_parameter_privacy_mode : c_network_session_parameter_base
{
	BYTE data[8];
};

/* 375 */
struct __cppobj c_network_session_parameter_ui_game_mode : c_network_session_parameter_base
{
	BYTE data[8];
};

/* 376 */
struct __cppobj c_network_session_parameter_map : c_network_session_parameter_base
{
	BYTE data[496];
};

/* 377 */
struct __cppobj c_network_session_parameter_initial_participants : c_network_session_parameter_base
{
	BYTE m_data[4344];
	BYTE m_requested_data[4344];
};

/* 378 */
struct __cppobj c_network_session_parameter_game_instance : c_network_session_parameter_base
{
	BYTE data[16];
};

/* 379 */
struct __cppobj c_network_session_parameter_random_seed : c_network_session_parameter_base
{
	BYTE data[8];
};

/* 380 */
struct __cppobj c_network_session_parameter_language : c_network_session_parameter_base
{
	BYTE data[8];
};

/* 381 */
struct __cppobj c_network_session_parameter_determinism_version : c_network_session_parameter_base
{
	BYTE data[8];
};

/* 382 */
struct __cppobj c_network_session_parameter_simulation_protocol : c_network_session_parameter_base
{
	BYTE data[8];
};

/* 383 */
struct __cppobj c_network_session_parameter_campaign_difficulty : c_network_session_parameter_base
{
	BYTE data[8];
};

/* 384 */
struct __cppobj c_network_session_parameter_active_skulls : c_network_session_parameter_base
{
	BYTE data[8];
};

/* 385 */
struct __cppobj c_network_session_parameter_campaign_metagame_scoring : c_network_session_parameter_base
{
	BYTE data[8];
};

/* 386 */
struct __cppobj c_network_session_parameter_campaign_insertion_point : c_network_session_parameter_base
{
	BYTE data[8];
};

/* 387 */
struct __cppobj c_network_session_parameter_start_mode : c_network_session_parameter_base
{
	BYTE data[8];
};

/* 388 */
struct __cppobj c_network_session_parameter_game_variant : c_network_session_parameter_base
{
	BYTE data[170112];
};

/* 389 */
struct __cppobj c_network_session_parameter_map_variant : c_network_session_parameter_base
{
	BYTE data[168928];
};

/* 390 */
struct __cppobj c_network_session_parameter_saved_film : c_network_session_parameter_base
{
	BYTE data[1104];
};

/* 391 */
struct __cppobj c_network_session_parameter_game_start_status : c_network_session_parameter_base
{
	BYTE data[40];
};

/* 392 */
struct __cppobj c_network_session_parameter_countdown_timer : c_network_session_parameter_base
{
	BYTE data[48];
};

/* 393 */
struct __cppobj c_network_session_parameter_requested_remote_join_data : c_network_session_parameter_base
{
	BYTE data[128];
};

/* 4 */
typedef struct _GUID GUID;

/* 394 */
struct s_network_session_remote_session_join_data
{
	BYTE unknown0[36];
	GUID GUID24;
	BYTE unknown34[12];
};

/* 395 */
struct __cppobj c_network_session_parameter_remote_join_data : c_network_session_parameter_base
{
	s_network_session_remote_session_join_data m_data;
	s_network_session_remote_session_join_data m_requested_data;
};

/* 396 */
struct __cppobj c_network_session_parameter_active_roster_outgoing_join_request : c_network_session_parameter_base
{
	BYTE data[64];
};

/* 397 */
struct __cppobj c_network_session_parameter_active_roster_outgoing_join_data : c_network_session_parameter_base
{
	BYTE data[9472];
};

/* 398 */
struct __cppobj c_network_session_parameter_active_roster_incoming_join_data : c_network_session_parameter_base
{
	BYTE data[24];
};

/* 399 */
struct __cppobj c_network_session_parameter_matchmaking_arbitration_nonce : c_network_session_parameter_base
{
	BYTE data[16];
};

/* 400 */
struct __cppobj c_network_session_parameter_matchmaking_host_selected : c_network_session_parameter_base
{
	BYTE data[8];
};

/* 401 */
struct __cppobj c_network_session_parameter_matchmaking_hopper_list : c_network_session_parameter_base
{
	BYTE data[4528];
};

/* 402 */
struct __cppobj c_network_session_parameter_matchmaking_requested_hopper : c_network_session_parameter_base
{
	BYTE data[8];
};

/* 403 */
struct __cppobj c_network_session_parameter_matchmaking_hopper : c_network_session_parameter_base
{
	BYTE data[232];
};

/* 404 */
struct __cppobj c_network_session_parameter_end_game : c_network_session_parameter_base
{
	BYTE data[8];
};

/* 405 */
struct __cppobj c_network_session_parameter_matchmaking_abort_requested : c_network_session_parameter_base
{
	BYTE data[8];
};

/* 406 */
struct __cppobj c_network_session_parameter_matchmaking_search_preference : c_network_session_parameter_base
{
	BYTE data[8];
};

/* 407 */
struct __cppobj c_network_session_parameter_matchmaking_progress : c_network_session_parameter_base
{
	BYTE data[112];
};

/* 408 */
struct __cppobj c_network_session_parameter_matchmaking_progress_search_criteria : c_network_session_parameter_base
{
	BYTE data[40];
};

/* 409 */
struct __cppobj c_network_session_parameter_matchmaking_assembly_peer_evict_mask : c_network_session_parameter_base
{
	BYTE data[8];
};

/* 410 */
struct __cppobj c_network_session_parameter_matchmaking_rematch_data : c_network_session_parameter_base
{
	BYTE data[1288];
};

/* 411 */
struct __cppobj c_network_session_parameter_matchmaking_hopper_statistics : c_network_session_parameter_base
{
	BYTE data[16];
};

/* 412 */
struct __cppobj c_network_session_parameter_matchmaking_tip : c_network_session_parameter_base
{
	BYTE data[8];
};

/* 413 */
struct __cppobj c_network_session_parameter_synchronous_out_of_sync : c_network_session_parameter_base
{
	BYTE data[8];
};

/* 414 */
struct __cppobj c_network_session_parameter_matchmaking_messaging : c_network_session_parameter_base
{
	BYTE data[24];
};

/* 415 */
struct __cppobj c_network_session_parameter_matchmaking_voting_results : c_network_session_parameter_base
{
	BYTE data[56];
};

/* 416 */
struct __cppobj c_network_session_parameter_matchmaking_voting_rounds : c_network_session_parameter_base
{
	BYTE data[5072];
};

/* 417 */
struct __cppobj c_network_session_parameter_matchmaking_voting_descriptions : c_network_session_parameter_base
{
	BYTE data[504];
};

/* 418 */
struct __cppobj c_network_session_parameter_matchmaking_game_configuration : c_network_session_parameter_base
{
	BYTE data[48];
};

/* 419 */
struct __cppobj c_network_session_parameter_request_campaign_quit : c_network_session_parameter_base
{
	BYTE data[16];
};

/* 420 */
struct __cppobj c_network_session_parameter_leader_properties : c_network_session_parameter_base
{
	BYTE data[128];
};

/* 421 */
struct __cppobj c_network_session_parameter_synchronous_halt_state : c_network_session_parameter_base
{
	BYTE data[152];
};

/* 422 */
struct __cppobj c_network_session_parameter_speculative_migration : c_network_session_parameter_base
{
	BYTE data[16];
};

/* 423 */
struct __cppobj c_network_session_parameter_voice_repeater : c_network_session_parameter_base
{
	BYTE data[680];
};

/* 424 */
struct __cppobj c_network_session_parameter_scoreboard_quality : c_network_session_parameter_base
{
	BYTE data[128];
};

/* 425 */
struct __cppobj c_network_session_parameter_network_quality : c_network_session_parameter_base
{
	BYTE data[544];
};

/* 426 */
struct c_network_session_parameters
{
	c_network_session_parameter_session_size session_size;
	c_network_session_parameter_life_cycle life_cycle;
	c_network_session_parameter_privacy_mode privacy_mode;
	c_network_session_parameter_ui_game_mode ui_game_mode;
	c_network_session_parameter_map map;
	c_network_session_parameter_initial_participants initial_participants;
	c_network_session_parameter_game_instance game_instance;
	c_network_session_parameter_random_seed random_seed;
	c_network_session_parameter_language language;
	c_network_session_parameter_determinism_version determinism_version;
	c_network_session_parameter_simulation_protocol simulation_protocol;
	c_network_session_parameter_campaign_difficulty campaign_difficulty;
	c_network_session_parameter_active_skulls active_skulls;
	c_network_session_parameter_campaign_metagame_scoring campaign_metagame_scoring;
	c_network_session_parameter_campaign_insertion_point campaign_insertion_point;
	c_network_session_parameter_start_mode start_mode;
	c_network_session_parameter_game_variant game_variant;
	c_network_session_parameter_map_variant map_variant;
	c_network_session_parameter_saved_film saved_film;
	c_network_session_parameter_game_start_status game_start_status;
	c_network_session_parameter_countdown_timer countdown_timer;
	c_network_session_parameter_requested_remote_join_data requested_remote_join_data;
	c_network_session_parameter_remote_join_data remote_join_data;
	c_network_session_parameter_active_roster_outgoing_join_request active_roster_outgoing_join_request;
	c_network_session_parameter_active_roster_outgoing_join_data active_roster_outgoing_join_data;
	c_network_session_parameter_active_roster_incoming_join_data active_roster_incoming_join_data;
	c_network_session_parameter_matchmaking_arbitration_nonce matchmaking_arbitration_nonce;
	c_network_session_parameter_matchmaking_host_selected matchmaking_host_selected;
	c_network_session_parameter_matchmaking_hopper_list matchmaking_hopper_list;
	c_network_session_parameter_matchmaking_requested_hopper matchmaking_requested_hopper;
	c_network_session_parameter_matchmaking_hopper matchmaking_hopper;
	c_network_session_parameter_end_game end_game;
	c_network_session_parameter_matchmaking_abort_requested matchmaking_abort_requested;
	c_network_session_parameter_matchmaking_search_preference matchmaking_search_preference;
	c_network_session_parameter_matchmaking_progress matchmaking_progress;
	c_network_session_parameter_matchmaking_progress_search_criteria matchmaking_progress_search_criteria;
	c_network_session_parameter_matchmaking_assembly_peer_evict_mask matchmaking_assembly_peer_evict_mask;
	c_network_session_parameter_matchmaking_rematch_data matchmaking_rematch_data;
	c_network_session_parameter_matchmaking_hopper_statistics matchmaking_hopper_statistics;
	c_network_session_parameter_matchmaking_tip matchmaking_tip;
	c_network_session_parameter_synchronous_out_of_sync synchronous_out_of_sync;
	c_network_session_parameter_matchmaking_messaging matchmaking_messaging;
	c_network_session_parameter_matchmaking_voting_results matchmaking_voting_results;
	c_network_session_parameter_matchmaking_voting_rounds matchmaking_voting_rounds;
	c_network_session_parameter_matchmaking_voting_descriptions matchmaking_voting_descriptions;
	c_network_session_parameter_matchmaking_game_configuration matchmaking_game_configuration;
	c_network_session_parameter_request_campaign_quit request_campaign_quit;
	c_network_session_parameter_leader_properties leader_properties;
	c_network_session_parameter_synchronous_halt_state synchronous_halt_state;
	c_network_session_parameter_speculative_migration speculative_migration;
	c_network_session_parameter_voice_repeater voice_repeater;
	c_network_session_parameter_scoreboard_quality scoreboard_quality;
	c_network_session_parameter_network_quality network_quality;
	c_network_session* session;
	struct c_network_observer* observer;
	c_network_session_parameter_base* parameters[53];
	int flags;
	int initial_parameters_update_mask;
	BYTE unknown5CF18[8];
};

/* 427 */
enum e_network_session_state : __int64
{
	_network_session_state_uninitialized = 0xFFFFFFFF,
	_network_session_state_none = 0x0,
	_network_session_state_peer_creating = 0x1,
	_network_session_state_peer_joining = 0x2,
	_network_session_state_peer_join_abort = 0x3,
	_network_session_state_peer_peer_established = 0x4,
	_network_session_state_peer_leaving = 0x5,
	_network_session_state_host_established = 0x6,
	_network_session_state_host_disband = 0x7,
	_network_session_state_host_handoff = 0x8,
	_network_session_state_host_reestablish = 0x9,
	_network_session_state_election = 0xA,
	_network_session_state_host_disconnected = 0xB,
	k_network_session_state_count = 0xC,
};

/* 348 */
struct __declspec(align(8)) c_network_session
{
	struct c_network_message_gateway* m_message_gateway;
	struct c_network_observer* m_observer;
	struct c_network_session_manager* m_session_manager;
	void** ppSession;
	int m_session_index;
	int m_session_type;
	e_network_session_class m_session_class;
	int unknown2C;
	c_network_session_membership m_session_membership;
	c_network_session_parameters m_session_parameters;
	e_network_session_state m_local_state;
	BYTE m_local_state_data[1456];
	BYTE unknown62BB0[24];
	DWORD m_managed_session_index;
	BYTE unknown62BCC[36];
	void* pSession;
	BYTE unknown62BF8[112];
	BYTE unknown62C68[256];
};

/* 368 */
struct __declspec(align(8)) c_network_session_parameter_base_vtbl
{
	void(__fastcall* Member00)(c_network_session_parameter_base*);
	void(__fastcall* Member01)(c_network_session_parameter_base*);
	void* Member02;
	void* Member03;
	void* Member04;
	void* Member05;
	void* Member06;
	void* Member07;
	void* Member08;
	void* Member09;
	void* Member10;
	void* Member11;
	void* Member12;
	void* Member13;
	void* Member14;
	void* Member15;
	void* Member16;
	void* Member17;
	__int64(__fastcall* Member18)(c_network_session_parameter_base*);
	void* Member19;
	void(__fastcall* Member20)(c_network_session_parameter_base*, __int64*);
	void(__fastcall* Member21)(void*, void*);
	void* Member22;
};

/* 428 */
struct __declspec(align(8)) c_network_session_parameter_packet
{
	bool unknown0;
	char unknown1[7];
	const char* m_name;
	void* m_decode;
	void* m_encode;
	void* unknown20;
	int unknown28;
	int unknown2C;
	void* m_requested_decode;
	void* m_requested_encode;
	void* unknown40;
	int unknown48;
	int unknown4C;
};

/* 429 */
struct c_network_session_parameter_packets
{
	c_network_session_parameter_packet packets[53];
};

