#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		challenge_globals_definition_group,
		CHALLENGE_GLOBALS_DEFINITION_TAG,
		nullptr,
		INVALID_TAG,
		challenge_globals_definition_block );

	TAG_BLOCK_FROM_STRUCT(
		challenge_globals_definition_block,
		"challenge_globals_definition_block",
		1,
		challenge_globals_definition_struct_definition);

	#define CHALLENGE_CATEGORY_BLOCK_ID { 0x1BF3629D, 0x7DFA41AA, 0xB84F471F, 0xB5D25884 }
	TAG_BLOCK(
		challenge_category_block,
		"challenge_category_block",
		k_roomEnoughToConvertAllExistingCategories,
		"s_challenge_category_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		CHALLENGE_CATEGORY_BLOCK_ID)
	{
		{ _field_string_id, "category_name", FIELD_FLAG_INDEX },
		{ _field_char_enum, "challenge category", FIELD_FLAG_INDEX, &challenge_category_enum_definition },
		FIELD_PAD("WAT1", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_block, "challenges", &challenge_block },
		{ _field_terminator }
	};

	#define CHALLENGE_BLOCK_STRUCT_ID { 0xAE40AC39, 0xD24F44B4, 0x8FD89CFF, 0x20129E29 }
	TAG_BLOCK(
		challenge_block,
		"challenge_block",
		k_maximum_challenges_per_category,
		"s_challenge_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CHALLENGE_BLOCK_STRUCT_ID)
	{
		{ _field_string_id, "challenge_name", FIELD_FLAG_INDEX },
		{ _field_string_id, "display_string", "in the UI, name and description" },
		{ _field_string_id, "display_name", "in the UI, name" },
		{ _field_string_id, "display_description", "in the UI, description" },
		{ _field_string_id, "completion_toast_string", "in the UI, the text on the toast when you complete this challenge" },
		{ _field_long_integer, "required_progress_count", "How many times this challenge must be progressed to complete it (unless overridden by LSP)." },
		{ _field_long_integer, "cookies reward", "cookies for completing this challenge; can be overridden by LSP" },
		{ _field_long_integer, "XP reward", "XP for completing this challenge; can be overridden by LSP" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_long_integer, "progress_tracking_interval", "Frequency we toast your progress (think pink and deadly)." },

		{ _field_string_id, "chud_progress_string", "progress toast string (presumably very concise)." },
		{ _field_long_integer, "chud_progress_bitmap_sequence_index", "What icon is shown in the progress toast?" },
		{ _field_byte_flags, "flags", &challenge_definition_flags },
		{ _field_char_enum, "icon", &challengeIconDefinition },
		FIELD_PAD("PJB1", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_long_flags, "auto progress on", "Conditions that progress this challenge magically (aside from incidents, which can progress any challenge)", &challenge_progress_flags },
		FIELD_CUSTOM("requirements", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		FIELD_CUSTOM("permitted game types", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_struct, "permitted game types", &game_mode_flags_struct },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		{ _field_string_id, "level_name", "can only be progressed on this level, if specified" },
		{ _field_long_integer, "map_id", "can only be progressed on this map, if > 0 (only works for campaign and spartan ops)" },
		{ _field_short_integer, "mission id", "can only be progressed on this mission, if >= 0 (only works for spartan ops)" },
		FIELD_PAD("PJB2", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_long_flags, "skulls", "this challenge can only be progressed with at least these skulls enabled in the game options (only works for campaign)", &skull_flags_definition },
		{ _field_long_integer, "minimum_score", "must score at least this many points, if > 0 (only works for campaign)" },
		{ _field_long_integer, "maximum_player_death_count", "must die no more than this many times, if >= 0" },
		{ _field_long_integer, "maximum_level_completion_seconds", "must complete the level in no more than this many seconds, if > 0" },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		{ _field_terminator }
	};

	#define CHALLENGE_GLOBALS_DEFINITION_STRUCT_DEFINITION_ID { 0x243AAA96, 0x410741B1, 0xBE0CC69B, 0xAEBFABE2 }
	TAG_STRUCT(
		challenge_globals_definition_struct_definition,
		"challenge_globals_definition_struct_definition",
		"s_challenge_globals_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		CHALLENGE_GLOBALS_DEFINITION_STRUCT_DEFINITION_ID)
	{
		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_tag_reference, "medal aggregators", &Tag::Reference<struct MedalChallengeAggregatorList>::s_defaultDefinition },

		{ _field_block, "challenge_categories", &challenge_category_block },
		{ _field_terminator }
	};

	STRINGS(challenge_definition_flags)
	{
		"progress_resets_at_end_of_game"
	};
	STRING_LIST(challenge_definition_flags, challenge_definition_flags_strings, _countof(challenge_definition_flags_strings));

	STRINGS(challengeIconDefinition)
	{
		"iron",
		"bronze",
		"silver",
		"gold",
		"onyx",
		"daily",
		"weekly"
	};
	STRING_LIST(challengeIconDefinition, challengeIconDefinition_strings, _countof(challengeIconDefinition_strings));

	STRINGS(challenge_progress_flags)
	{
		"matchmaking_multiplayer_game_won",
		"campaign_mission_beaten",
		"matchmaking_multiplayer_game_completed",
		"complete_single_daily_challenge",
		"complete_single_weekly_challenge",
		"complete_single_monthly_challenge",
		"complete_all_daily_challenges_in_a_day",
		"upload_film_clip_that_you_authored",
		"wear_a_piece_of_armor_in_armory",
		"auto_progress#progresses the instant all requirements are met",
		"spartan ops- mission beaten",
		"spartan ops- completed all weekly missions on easy (or harder)",
		"spartan ops- completed all weekly missions on normal (or harder)",
		"spartan ops- completed all weekly missions on hard (or harder)",
		"spartan ops- completed all weekly missions on impossible"
	};
	STRING_LIST(challenge_progress_flags, challenge_progress_flags_strings, _countof(challenge_progress_flags_strings));

	STRINGS(challenge_category_enum_definition)
	{
		"campaign",
		"competitive",
		"spartan ops",
		"waypoint"
	};
	STRING_LIST(challenge_category_enum_definition, challenge_category_enum_definition_strings, _countof(challenge_category_enum_definition_strings));

	STRINGS(skull_flags_definition)
	{
		"skull_iron",
		"skull_black_eye",
		"skull_tough_luck",
		"skull_catch",
		"skull_fog",
		"skull_famine",
		"skull_thunderstorm",
		"skull_tilt",
		"skull_mythic",
		"skull_assassin",
		"skull_blind",
		"skull_superman",
		"skull_birthday_party",
		"skull_daddy",
		"skull_red",
		"skull_yellow",
		"skull_blue"
	};
	STRING_LIST(skull_flags_definition, skull_flags_definition_strings, _countof(skull_flags_definition_strings));

} // namespace macaque

} // namespace blofeld

