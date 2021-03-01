#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		game_completion_rewards_globals_group,
		GAME_COMPLETION_REWARDS_GLOBALS_TAG,
		nullptr,
		INVALID_TAG,
		game_completion_rewards_globals_block );

	TAG_BLOCK_FROM_STRUCT(
		game_completion_rewards_globals_block,
		"game_completion_rewards_globals_block",
		1,
		game_completion_rewards_globals_struct_definition);

	#define GAME_COMPLETION_REWARDS_DIFFICULTY_BLOCK_ID { 0x11B38235, 0xC0BB4E11, 0xB7BA4EF0, 0x72725526 }
	TAG_BLOCK(
		game_completion_rewards_difficulty_block,
		"game_completion_rewards_difficulty_block",
		1,
		"s_game_completion_rewards_category",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		GAME_COMPLETION_REWARDS_DIFFICULTY_BLOCK_ID)
	{
		{ _field_block, "easy matchmaking", "this block is used for easy matchmade games", &game_completion_rewards_definition_block },
		{ _field_block, "normal matchmaking", "this block is used for normal matchmade games", &game_completion_rewards_definition_block },
		{ _field_block, "heroic matchmaking", "this block is used for heroic matchmade games", &game_completion_rewards_definition_block },
		{ _field_block, "legendary matchmaking", "this block is used for legendary matchmade games", &game_completion_rewards_definition_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_block, "custom", "this block is used for custom games", &game_completion_rewards_definition_block },

		{ _field_terminator }
	};

	#define GAME_COMPLETION_REWARDS_DEFINITION_BLOCK_ID { 0x500564F0, 0x598044E6, 0x9D209D9A, 0xC7AF9F7B }
	TAG_BLOCK(
		game_completion_rewards_definition_block,
		"game_completion_rewards_definition_block",
		eCT_count,
		"s_game_completion_rewards_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		GAME_COMPLETION_REWARDS_DEFINITION_BLOCK_ID)
	{
		{ _field_long_integer, "initial amount per minute", "base amount of reward given for each minute of play up until the start of the falloff curve", MAKE_OLD_NAMES("initial cookies per minute") },
		{ _field_real, "hopper scaling factor", "the player's time-based reward value is multiplied by this factor before being awarded; this value can be overridden by the hopper" },
		{ _field_real, "winner scaling factor", "if the player is an unambiguous winner, their time-based reward value is multiplied by (this factor - 1) and the result is awarded as a bonus; this value can be overridden by the hopper" },
		{ _field_real, "performance scaling factor", "if the player is not a winner, but is in the top half of the standings, their time-based reward is multiplied by (this factor - 1) and the result is awarded as a bonus; this value can be overriden by the hopper" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach }, // #TODO: Unsure if this is 100% correct
		{ _field_real, "score scaling factor", "for score-based modes, the player's normalized score (0..1) is multiplied by this scaling factor and the result is awarded to the player as a bonus; this value can be overridden by the hopper" },

		{ _field_block, "apm falloff curve", "amount per minute falloff curve; used to provide diminishing returns for longer play time", MAKE_OLD_NAMES("cpm falloff curve"), &game_completion_rewards_falloff_point_block },
		{ _field_terminator }
	};

	#define GAME_COMPLETION_REWARDS_FALLOFF_POINT_BLOCK_ID { 0x5FA53769, 0x7B89442A, 0xB8CBBC10, 0xF605B579 }
	TAG_BLOCK(
		game_completion_rewards_falloff_point_block,
		"game_completion_rewards_falloff_point_block",
		s_game_completion_rewards_globals::k_max_falloff_curve_points,
		"s_game_completion_rewards_falloff_point",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		GAME_COMPLETION_REWARDS_FALLOFF_POINT_BLOCK_ID)
	{
		{ _field_short_integer, "start time", "minutes into the game after which this new reward rate applies" },
		{ _field_short_integer, "amount per minute", "points awarded per minute once the given time is reached", MAKE_OLD_NAMES("cookies per minute") },
		{ _field_terminator }
	};

	#define GAME_COMPLETION_REWARDS_MULTIPLAYER_BLOCK_ID { 0xE6AE14F0, 0x8C284494, 0x9EA0B508, 0xD493D0CA }
	TAG_BLOCK(
		game_completion_rewards_multiplayer_block,
		"game_completion_rewards_multiplayer_block",
		1,
		"s_game_completion_rewards_category",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		GAME_COMPLETION_REWARDS_MULTIPLAYER_BLOCK_ID)
	{
		{ _field_block, "matchmaking", "this block is used for matchmade games", &game_completion_rewards_definition_block },
		{ _field_block, "custom", "this block is used for custom games", &game_completion_rewards_definition_block },
		{ _field_block, "unused0", FIELD_FLAG_UNKNOWN0, &game_completion_rewards_definition_block },
		{ _field_block, "unused1", FIELD_FLAG_UNKNOWN0, &game_completion_rewards_definition_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_block, "unused2", FIELD_FLAG_UNKNOWN0, &game_completion_rewards_definition_block },

		{ _field_terminator }
	};

	#define GAME_COMPLETION_REWARDS_GLOBALS_STRUCT_DEFINITION_ID { 0xA8438CD1, 0x10C94898, 0x8C0E4C83, 0x589A8277 }
	TAG_STRUCT(
		game_completion_rewards_globals_struct_definition,
		"game_completion_rewards_globals_struct_definition",
		"s_game_completion_rewards_globals",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		GAME_COMPLETION_REWARDS_GLOBALS_STRUCT_DEFINITION_ID)
	{
		{ _field_block, "campaign", "rewards given for playing campaign games online", &game_completion_rewards_difficulty_block },
		{ _field_block, "firefight", "rewards given for playing firefight games online", &game_completion_rewards_difficulty_block },
		{ _field_block, "multiplayer", "rewards given for playing PvP multiplayer games online", &game_completion_rewards_multiplayer_block },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_block, "unknown#rewards given for unknown", &game_completion_rewards_multiplayer_block_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_real, "fast track armor modifier", "this multiplier is applied to the combined reward of timespent, score and performance, multiplied by the percentage time the player has the armor mod active" },

		{ _field_terminator }
	};

} // namespace macaque

} // namespace blofeld

