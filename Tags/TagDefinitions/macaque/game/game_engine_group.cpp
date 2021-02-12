#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define GAMEENGINEFIREFIGHTVARIANTTAG_STRUCT_DEFINITION_ID { 0xB695034E, 0xB0F14A4C, 0xA75E0D82, 0xE5A7F4A4 }
	TAG_BLOCK(
		GameEngineFirefightVariantTag_block,
		"GameEngineFirefightVariantTag_block",
		1,
		"GameEngineFirefightVariantDefinition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		GAMEENGINEFIREFIGHTVARIANTTAG_STRUCT_DEFINITION_ID)
	{
		{ _field_struct, "variant", &gameEngineFirefightVariantDefinition },
		{ _field_terminator }
	};

	TAG_GROUP(
		GameEngineFirefightVariantTag_group,
		GAMEENGINEFIREFIGHTVARIANTTAG_TAG,
		nullptr,
		INVALID_TAG,
		GameEngineFirefightVariantTag_block );

	TAG_GROUP(
		game_engine_globals_group,
		GAME_ENGINE_GLOBALS_TAG,
		nullptr,
		INVALID_TAG,
		game_engine_globals_block );

	TAG_GROUP(
		game_engine_settings_definition_group,
		GAME_ENGINE_SETTINGS_DEFINITION_TAG,
		nullptr,
		INVALID_TAG,
		game_engine_settings_definition_block );

	TAG_BLOCK_FROM_STRUCT(
		game_engine_globals_block,
		"game_engine_globals_block",
		1,
		game_engine_globals_struct_definition);

	TAG_BLOCK_FROM_STRUCT(
		game_engine_settings_definition_block,
		"game_engine_settings_definition_block",
		1,
		game_engine_settings_definition_struct_definition);

	#define GAME_ENGINE_MISCELLANEOUS_OPTIONS_BLOCK_ID { 0x4E184020, 0x9F9B44E9, 0x9B53D8FA, 0x60936484 }
	TAG_BLOCK(
		game_engine_miscellaneous_options_block,
		"game_engine_miscellaneous_options_block",
		1,
		"s_game_engine_miscellaneous_options_definition",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		GAME_ENGINE_MISCELLANEOUS_OPTIONS_BLOCK_ID)
	{
		{ _field_word_flags, "flags", &game_engine_miscellaneous_options_flags },
		{ _field_char_integer, "early victory win count" },
		{ _field_char_integer, "round time limit", nullptr, "minutes" },
		{ _field_char_integer, "number of rounds" },
		{ _field_char_enum, "mosh difficulty level", &mosh_difficulty },
		{ _field_byte_integer, "overshield deplete time" },
		FIELD_PAD("RXXH", nullptr, FIELD_FLAG_NONE, 1),
		{ _field_terminator }
	};

	#define GAME_ENGINE_PROTOTYPE_OPTIONS_BLOCK_ID { 0x1E7F0911, 0xFD98458A, 0x85DFDCE5, 0x8CDF8AAE }
	TAG_BLOCK(
		game_engine_prototype_options_block,
		"game_engine_prototype_options_block",
		1,
		"s_game_engine_prototype_options_definition",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		GAME_ENGINE_PROTOTYPE_OPTIONS_BLOCK_ID)
	{
		{ _field_char_integer, "prototype mode" },
		{ _field_char_integer, "promethean energy kill percent" },
		{ _field_char_integer, "promethean energy time percent" },
		{ _field_char_integer, "promethean energy medal percent" },
		{ _field_char_integer, "promethean duration" },
		{ _field_char_integer, "class color override" },
		{ _field_terminator }
	};

	#define GAME_ENGINE_RESPAWN_OPTIONS_BLOCK_ID { 0xAE909DD1, 0x6A184C06, 0xA850A80C, 0x6156FB90 }
	TAG_BLOCK(
		game_engine_respawn_options_block,
		"game_engine_respawn_options_block",
		1,
		"s_game_engine_respawn_options_definition",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		GAME_ENGINE_RESPAWN_OPTIONS_BLOCK_ID)
	{
		{ _field_word_flags, "flags", &game_engine_respawn_options_flags },
		{ _field_char_integer, "lives per round" },
		{ _field_char_integer, "team lives per round" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_char_integer, "min respawn time", nullptr, "seconds" },

		{ _field_char_integer, "respawn time", nullptr, "seconds" },
		{ _field_char_integer, "suicide penalty", nullptr, "seconds" },
		{ _field_char_integer, "betrayal penalty", nullptr, "seconds" },
		{ _field_char_integer, "respawn growth", nullptr, "seconds" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		FIELD_PAD("EOTOTRXV", nullptr, FIELD_FLAG_NONE, 3),

		{ _field_string_id, "respawn player traits name" },
		{ _field_char_integer, "initial loadout selection time", "delay before spawning in at start of round", "seconds" },
		{ _field_char_integer, "respawn player traits duration", nullptr, "seconds" },
		FIELD_PAD("woman bound for glory, why you leaving me again?", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	#define GAME_ENGINE_SOCIAL_OPTIONS_BLOCK_ID { 0xEA186C9D, 0xC04940B9, 0xB8F44A1B, 0x4E8326DF }
	TAG_BLOCK(
		game_engine_social_options_block,
		"game_engine_social_options_block",
		1,
		"s_game_engine_social_options_definition",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		GAME_ENGINE_SOCIAL_OPTIONS_BLOCK_ID)
	{
		{ _field_long_flags, "flags", &game_engine_social_options_flags },
		{ _field_terminator }
	};

	#define GAME_ENGINE_MAP_OVERRIDE_OPTIONS_BLOCK_ID { 0xE881D96D, 0xBB884679, 0x9ACC0364, 0xE9D68670 }
	TAG_BLOCK(
		game_engine_map_override_options_block,
		"game_engine_map_override_options_block",
		1,
		"s_game_engine_map_override_options_definition",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		GAME_ENGINE_MAP_OVERRIDE_OPTIONS_BLOCK_ID)
	{
		{ _field_string_id, "player traits name" },
		{ _field_string_id, "weapon set name" },

		{ _field_legacy, _field_version_less, _engine_type_groundhog },
		{ _field_string_id, "vehicle set name" },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_groundhog, 4 },
		{ _field_legacy, _field_string_id, "light vehicle set name" },
		{ _field_legacy, _field_string_id, "tank set name" },
		{ _field_legacy, _field_string_id, "aircraft set name" },
		{ _field_legacy, _field_string_id, "turret set name" },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 6 },
		{ _field_legacy, _field_string_id, "overshield powerup traits name" },
		{ _field_legacy, _field_string_id, "active camo powerup traits name" },
		{ _field_legacy, _field_string_id, "custom powerup traits name" },
		{ _field_char_integer, "overshield powerup duration", nullptr, "seconds" },
		{ _field_char_integer, "active camo powerup duration", nullptr, "seconds" },
		{ _field_char_integer, "custom powerup duration", nullptr, "seconds" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 17 },
		{ _field_string_id, "equipment set name" },
		{ _field_string_id, "red powerup traits name" },
		{ _field_string_id, "blue powerup traits name" },
		{ _field_string_id, "yellow powerup traits name" },
		{ _field_string_id, "custom powerup traits name" },
		{ _field_char_integer, "red powerup duration", nullptr, "seconds" },
		{ _field_char_integer, "blue powerup duration", nullptr, "seconds" },
		{ _field_char_integer, "yellow powerup duration", nullptr, "seconds" },
		{ _field_char_integer, "custom powerup duration", nullptr, "seconds" },
		{ _field_string_id, "red powerup secondary traits name" },
		{ _field_string_id, "blue powerup secondary traits name" },
		{ _field_string_id, "yellow powerup secondary traits name" },
		{ _field_string_id, "custom powerup secondary traits name" },
		{ _field_char_integer, "red powerup secondary duration", nullptr, "seconds" },
		{ _field_char_integer, "blue powerup secondary duration", nullptr, "seconds" },
		{ _field_char_integer, "yellow powerup secondary duration", nullptr, "seconds" },
		{ _field_char_integer, "custom powerup secondary duration", nullptr, "seconds" },

		{ _field_byte_flags, "flags", &game_engine_map_override_options_flags },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		FIELD_PAD("pad", nullptr, FIELD_FLAG_NONE, 3),

		{ _field_terminator }
	};

	#define GAME_ENGINE_TEAM_OPTIONS_BLOCK_ID { 0x571F4D81, 0x003C4CD5, 0x950C0645, 0x5B6A6FA0 }
	TAG_BLOCK(
		game_engine_team_options_block,
		"game_engine_team_options_block",
		1,
		"s_game_engine_team_options_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | 
		SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		GAME_ENGINE_TEAM_OPTIONS_BLOCK_ID)
	{
		{ _field_char_enum, "model override type", &game_engine_team_options_model_override_type },
		{ _field_char_enum, "designator switch type", &game_engine_team_options_designator_switch_type },
		FIELD_PAD("pad", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_array, "teams", &game_engine_team_options_team_block_array },
		{ _field_terminator }
	};

	#define GAMEENGINEORDNANCEOPTIONSBLOCK_ID { 0xA4D1C7F4, 0xCA0849E6, 0xAADCC0FB, 0x2532C53D }
	TAG_BLOCK(
		gameEngineOrdnanceOptionsBlock_block,
		"gameEngineOrdnanceOptionsBlock",
		1,
		"GameEngineOrdnanceOptionsDefinition",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		GAMEENGINEORDNANCEOPTIONSBLOCK_ID)
	{
		{ _field_byte_flags, "flags", &gameEngineOrdnanceOptionsFlags },
		{ _field_terminator }
	};

	#define GAMEENGINEFIREFIGHTPLAYERGOALPROPERTIESBLOCK_ID { 0xF636456E, 0xCBB041F5, 0x94120EAB, 0x04B4CC2E }
	TAG_BLOCK(
		GameEngineFirefightPlayerGoalPropertiesBlock_block,
		"GameEngineFirefightPlayerGoalPropertiesBlock",
		k_firefightMaxPlayerGoals,
		"GameEngineFirefightPlayerGoalDefinition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		GAMEENGINEFIREFIGHTPLAYERGOALPROPERTIESBLOCK_ID)
	{
		{ _field_char_enum, "Player Goal", &FirefightGoal },
		{ _field_char_integer, "Lives" },
		{ _field_char_integer, "Time Limit", "minutes" },
		{ _field_byte_flags, "Wave Difficulty", &FirefightWaveDifficulty },
		{ _field_block, "Firefight Waves", &GameEngineFirefightWavePropertiesBlock_block },
		{ _field_long_flags, "Player Goal Flags", &GameEnginePlayerGoalFlags },
		{ _field_string_id, "spartan player traits" },
		{ _field_string_id, "ai traits" },
		{ _field_string, "Start Event" },
		{ _field_string, "End Event" },
		{ _field_long_flags, "skulls", MAKE_OLD_NAMES("primary skulls"), FIELD_FLAG_INDEX, &skull_flags },
		{ _field_char_integer, "objective 1" },
		{ _field_char_integer, "objective 2" },
		{ _field_char_integer, "objective 3" },
		{ _field_char_integer, "objective 4" },
		{ _field_char_integer, "User Data" },
		{ _field_char_integer, "start location folder" },
		FIELD_PAD("BLAH", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	#define GAMEENGINEFIREFIGHTWAVEPROPERTIESBLOCK_ID { 0xA5CF24B4, 0xEFA047A9, 0xB3D8E439, 0xCDDFDE02 }
	TAG_BLOCK(
		GameEngineFirefightWavePropertiesBlock_block,
		"GameEngineFirefightWavePropertiesBlock",
		k_firefightWavesPerGoal,
		"GameEngineFirefightWaveDefinition",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		GAMEENGINEFIREFIGHTWAVEPROPERTIESBLOCK_ID)
	{
		{ _field_string_id, "squad type", "survival_mode_get_wave_squad", FIELD_FLAG_INDEX },
		{ _field_char_enum, "Delivery type", &FirefightWaveDeliveryMethod },
		{ _field_char_integer, "AI allowed before next wave spawns" },
		{ _field_char_integer, "Enemies Left Before HUD Marking" },
		{ _field_char_integer, "Wave Type" },
		{ _field_char_integer, "Weapon to drop" },
		{ _field_char_integer, "Vehicle to drop" },
		{ _field_char_integer, "Squad 1" },
		{ _field_char_integer, "Squad 2" },
		{ _field_string, "Start Event" },
		{ _field_string, "End Event" },
		{ _field_terminator }
	};

	#define GAME_ENGINE_AI_TRAITS_LIST_BLOCK_ID { 0xB7D92333, 0x53D54ADE, 0x863F6885, 0xA9392539 }
	TAG_BLOCK(
		game_engine_ai_traits_list_block,
		"game_engine_ai_traits_list_block",
		64,
		"s_game_engine_ai_traits_list",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		GAME_ENGINE_AI_TRAITS_LIST_BLOCK_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_struct, "ai traits", &game_engine_ai_traits_struct },
		{ _field_terminator }
	};

	#define GAME_ENGINE_SANDBOX_VARIANT_BLOCK_ID { 0x5B14CC8E, 0x9237482D, 0xA4EED56E, 0x97F068DA }
	TAG_BLOCK(
		game_engine_sandbox_variant_block,
		"game_engine_sandbox_variant_block",
		32,
		"s_game_engine_sandbox_variant_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		GAME_ENGINE_SANDBOX_VARIANT_BLOCK_ID)
	{
		{ _field_string_id, "localizable name", FIELD_FLAG_INDEX },
		{ _field_string_id, "localizable description" },
		{ _field_block, "miscellaneous options", &game_engine_miscellaneous_options_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_block, "prototype options", &game_engine_prototype_options_block },

		{ _field_block, "respawn options", &game_engine_respawn_options_block },
		{ _field_block, "social options", &game_engine_social_options_block },
		{ _field_block, "map override options", &game_engine_map_override_options_block },
		{ _field_block, "team options", &game_engine_team_options_block },
		{ _field_block, "loadout options", &game_engine_loadout_options_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_block, "ordnance options", &gameEngineOrdnanceOptionsBlock_block },

		{ _field_long_flags, "flags", &sandbox_flags },
		{ _field_enum, "edit mode", &sandbox_editing_mode },
		{ _field_enum, "respawn time", &sandbox_respawn_time },
		{ _field_string_id, "all players traits" },
		{ _field_terminator }
	};

	#define GAME_ENGINE_SURVIVAL_VARIANT_BLOCK_ID { 0x891F8387, 0xD9A941E0, 0x87AAC1DC, 0xFA54ACF0 }
	TAG_BLOCK(
		game_engine_survival_variant_block,
		"game_engine_survival_variant_block",
		32,
		"s_game_engine_survival_variant_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		GAME_ENGINE_SURVIVAL_VARIANT_BLOCK_ID)
	{
		{ _field_string_id, "localizable name", FIELD_FLAG_INDEX },
		{ _field_string_id, "localizable description" },
		{ _field_block, "miscellaneous options", &game_engine_miscellaneous_options_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_block, "prototype options", &game_engine_prototype_options_block },

		{ _field_block, "respawn options", &game_engine_respawn_options_block },
		{ _field_block, "social options", &game_engine_social_options_block },
		{ _field_block, "map override options", &game_engine_map_override_options_block },
		{ _field_block, "team options", &game_engine_team_options_block },
		{ _field_block, "loadout options", &game_engine_loadout_options_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_block, "ordnance options", &gameEngineOrdnanceOptionsBlock_block },

		{ _field_byte_flags, "flags", &game_engine_survival_variant_flags },
		{ _field_char_enum, "game difficulty", &global_campaign_difficulty_enum },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		FIELD_PAD("SDFHJREN", nullptr, FIELD_FLAG_NONE, 2),

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 2 },
		{ _field_legacy, _field_char_integer, "time limit" },
		{ _field_legacy, _field_char_integer, "unknown" }, // #TODO: Do some research

		{ _field_char_integer, "set count", "survival_mode_get_set_count, -1 to loop last, -2 to loop last 3, -3 to loop all" },
		{ _field_char_integer, "bonus lives awarded", "survival_mode_get_bonus_lives_awarded" },
		{ _field_short_integer, "bonus target", "survival_mode_get_bonus_target" },
		{ _field_short_integer, "spartan lives on elite death" },
		{ _field_short_integer, "extra life score target" },
		{ _field_short_integer, "shared team life count" },
		{ _field_short_integer, "elite life count" },
		{ _field_short_integer, "maximum lives" },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_enum, "generator count", &game_engine_survival_generator_count_enum },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_short_integer, "generator count" },

		{ _field_string_id, "spartan player traits" },
		{ _field_string_id, "elite player traits" },
		{ _field_string_id, "ai traits" },
		{ _field_block, "elite respawn options", &game_engine_respawn_options_block },
		{ _field_block, "set properties", &game_engine_survival_set_properties_block },
		{ _field_block, "round properties", &game_engine_survival_round_properties_block },
		FIELD_CUSTOM("bonus round", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_struct, "bonus round properties", &game_engine_survival_bonus_wave_properties_struct },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		{ _field_block, "custom skulls", &game_engine_survival_custom_skull_block },
		{ _field_terminator }
	};

	#define GAME_ENGINE_SURVIVAL_SET_PROPERTIES_BLOCK_ID { 0xC3F411AE, 0xF42346FE, 0xB1585B9B, 0x7A789ABC }
	TAG_BLOCK(
		game_engine_survival_set_properties_block,
		"game_engine_survival_set_properties_block",
		10,
		"s_survival_set_properties_definition",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		GAME_ENGINE_SURVIVAL_SET_PROPERTIES_BLOCK_ID)
	{
		{ _field_long_flags, "skulls", MAKE_OLD_NAMES("primary skulls"), FIELD_FLAG_INDEX, &skull_flags },
		{ _field_terminator }
	};

	#define GAME_ENGINE_SURVIVAL_ROUND_PROPERTIES_BLOCK_ID { 0xB85241D5, 0x73D143E2, 0xBC7B2803, 0x3D920427 }
	TAG_BLOCK(
		game_engine_survival_round_properties_block,
		"game_engine_survival_round_properties_block",
		k_survival_full_rounds_per_set,
		"s_survival_round_properties_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		GAME_ENGINE_SURVIVAL_ROUND_PROPERTIES_BLOCK_ID)
	{
		{ _field_long_flags, "skulls", MAKE_OLD_NAMES("primary skulls"), FIELD_FLAG_INDEX, &skull_flags },
		FIELD_CUSTOM("initial wave", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_struct, "initial waves", &game_engine_survival_wave_properties_struct },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		FIELD_CUSTOM("primary wave", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_struct, "primary waves", &game_engine_survival_wave_properties_struct },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		FIELD_CUSTOM("boss wave", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_struct, "boss waves", &game_engine_survival_wave_properties_struct },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		{ _field_terminator }
	};

	#define SURVIVAL_WAVE_SQUAD_BLOCK_ID { 0x38B8902F, 0x4F0D477A, 0xBBDE2065, 0x8BD20DC0 }
	TAG_BLOCK(
		survival_wave_squad_block,
		"survival_wave_squad_block",
		k_maximum_survival_possible_wave_squads,
		"s_survival_wave_possible_wave_squad",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SURVIVAL_WAVE_SQUAD_BLOCK_ID)
	{
		{ _field_string_id, "squad type", "survival_mode_get_wave_squad", FIELD_FLAG_INDEX },
		{ _field_terminator }
	};

	#define GAME_ENGINE_SURVIVAL_CUSTOM_SKULL_BLOCK_ID { 0xD153890A, 0x08AE47F4, 0xA631F0D4, 0xC8E544DE }
	TAG_BLOCK(
		game_engine_survival_custom_skull_block,
		"game_engine_survival_custom_skull_block",
		k_maximum_survival_custom_skulls,
		"s_custom_skull_definition",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		GAME_ENGINE_SURVIVAL_CUSTOM_SKULL_BLOCK_ID)
	{
		{ _field_string_id, "spartan player traits" },
		{ _field_string_id, "elite player traits" },
		{ _field_string_id, "ai traits" },
		{ _field_terminator }
	};

	#define GAMEENGINEFIREFIGHTVARIANTSHELLBLOCK_ID { 0xD392368D, 0xBA17426C, 0x94047A97, 0x85056F66 }
	TAG_BLOCK(
		GameEngineFirefightVariantShellBlock_block,
		"GameEngineFirefightVariantShellBlock",
		128,
		"s_game_engine_firefight_variant_definition_shell",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		GAMEENGINEFIREFIGHTVARIANTSHELLBLOCK_ID)
	{
		{ _field_tag_reference, "variant", &GameEngineFirefightVariantReference },
		{ _field_terminator }
	};

	#define GAME_ENGINE_CAMPAIGN_VARIANT_BLOCK_ID { 0xDCABAC41, 0x7F354E3A, 0x9AA1FF47, 0xF0498D93 }
	TAG_BLOCK(
		game_engine_campaign_variant_block,
		"game_engine_campaign_variant_block",
		32,
		"s_game_engine_campaign_variant_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		GAME_ENGINE_CAMPAIGN_VARIANT_BLOCK_ID)
	{
		{ _field_string_id, "localizable name", FIELD_FLAG_INDEX },
		{ _field_string_id, "localizable description" },
		{ _field_block, "miscellaneous options", &game_engine_miscellaneous_options_block },
		{ _field_block, "prototype options", &game_engine_prototype_options_block },
		{ _field_block, "respawn options", &game_engine_respawn_options_block },
		{ _field_block, "social options", &game_engine_social_options_block },
		{ _field_block, "map override options", &game_engine_map_override_options_block },
		{ _field_block, "team options", &game_engine_team_options_block },
		{ _field_block, "loadout options", &game_engine_loadout_options_block },
		{ _field_block, "ordnance options", &gameEngineOrdnanceOptionsBlock_block },
		{ _field_terminator }
	};

	#define GAME_ENGINE_TEAM_OPTIONS_TEAM_BLOCK_ID { 0x3303F583, 0x42184740, 0x986A9390, 0x90FCFEE1 }
	TAG_ARRAY(
		game_engine_team_options_team_block_array,
		"game_engine_team_options_team_block",
		k_multiplayer_team_game_team_count,
		"s_game_engine_team_options_team_definition",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		GAME_ENGINE_TEAM_OPTIONS_TEAM_BLOCK_ID)
	{
		{ _field_byte_flags, "flags", &game_engine_team_options_team_flags },
		{ _field_char_enum, "initial team designator", &global_multiplayer_team_designator_enum_definition },
		{ _field_char_enum, "model override", &game_engine_team_options_player_model_choice },
		{ _field_byte_integer, "number of fireteams" },
		{ _field_string_id, "description" },
		{ _field_rgb_color, "primary color override", MAKE_OLD_NAMES("color override") },
		{ _field_rgb_color, "secondary color override" },
		{ _field_argb_color, "ui text tint color override" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_argb_color, "ui bitmap tint color override" },

		{ _field_terminator }
	};

	#define GAME_ENGINE_GLOBALS_STRUCT_DEFINITION_ID { 0x796F3498, 0x65054DAA, 0x882DA33D, 0xB1677B4E }
	TAG_STRUCT(
		game_engine_globals_struct_definition,
		"game_engine_globals_struct_definition",
		"s_game_engine_globals_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		GAME_ENGINE_GLOBALS_STRUCT_DEFINITION_ID)
	{
		{ _field_tag_reference, "game engine settings", &game_engine_settings_definition_reference },
		{ _field_tag_reference, "game engine text", &global_multilingual_unicode_string_list_reference },
		{ _field_block, "game engine event response list", &game_engine_event_block },
		{ _field_terminator }
	};

	#define GAME_ENGINE_SETTINGS_DEFINITION_STRUCT_DEFINITION_ID { 0x2644FCED, 0xC39A4930, 0xB9F37CB2, 0x70F9BDA5 }
	TAG_STRUCT(
		game_engine_settings_definition_struct_definition,
		"game_engine_settings_definition_struct_definition",
		"s_game_engine_settings_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		GAME_ENGINE_SETTINGS_DEFINITION_STRUCT_DEFINITION_ID)
	{
		FIELD_EXPLANATION("Game Engine Settings", nullptr, FIELD_FLAG_NONE, "This contains the definitions for the built-in custom multiplayer game variants"),
		{ _field_long_flags, "flags", &game_engine_settings_flags },
		{ _field_block, "player traits", &game_engine_player_traits_list_block, _field_id_slap },
		{ _field_block, "ai traits", &game_engine_ai_traits_list_block, _field_id_slap },
		{ _field_block, "sandbox variants", &game_engine_sandbox_variant_block, _field_id_slap },
		{ _field_block, "survival variants", &game_engine_survival_variant_block, _field_id_slap },
		{ _field_block, "new firefight variants", MAKE_OLD_NAMES("firefight variants new"), &GameEngineFirefightVariantShellBlock_block, _field_id_slap },
		{ _field_block, "campaign variants", &game_engine_campaign_variant_block, _field_id_slap },
		{ _field_terminator }
	};

	#define GAMEENGINEFIREFIGHTVARIANTDEFINITION_ID { 0x6CCBE137, 0x5F764396, 0xB5182CE2, 0xA6B2A01C }
	TAG_STRUCT(
		gameEngineFirefightVariantDefinition,
		"gameEngineFirefightVariantDefinition",
		"s_game_engine_firefight_variant_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		GAMEENGINEFIREFIGHTVARIANTDEFINITION_ID)
	{
		{ _field_string_id, "localizable name", FIELD_FLAG_INDEX },
		{ _field_string_id, "localizable description" },
		{ _field_block, "miscellaneous options", &game_engine_miscellaneous_options_block },
		{ _field_block, "prototype options", &game_engine_prototype_options_block },
		{ _field_block, "respawn options", &game_engine_respawn_options_block },
		{ _field_block, "social options", &game_engine_social_options_block },
		{ _field_block, "map override options", &game_engine_map_override_options_block },
		{ _field_block, "team options", &game_engine_team_options_block },
		{ _field_block, "loadout options", &game_engine_loadout_options_block },
		{ _field_block, "ordnance options", &gameEngineOrdnanceOptionsBlock_block },
		{ _field_long_integer, "mission_id" },
		{ _field_char_enum, "game difficulty", &global_campaign_difficulty_enum },
		{ _field_byte_flags, "firefight variant flags", &GameEngineFirefightVariantFlags },
		{ _field_short_integer, "shared team life count" },
		{ _field_short_integer, "maximum lives" },
		{ _field_char_integer, "Starting Crate 1" },
		{ _field_char_integer, "Starting Crate 2" },
		{ _field_char_integer, "Starting Crate 3" },
		{ _field_char_integer, "Starting Crate 4" },
		{ _field_char_integer, "Starting Crate 5" },
		{ _field_char_integer, "Starting Crate 6" },
		{ _field_char_integer, "Starting Crate 7" },
		{ _field_char_integer, "Starting Crate 8" },
		{ _field_char_integer, "Starting Crate 9" },
		{ _field_char_integer, "Starting Crate 10" },
		{ _field_char_integer, "Starting Crate 11" },
		{ _field_char_integer, "Starting Crate 12" },
		{ _field_char_integer, "Starting Crate 13" },
		{ _field_char_integer, "Starting Crate 14" },
		{ _field_string, "Variant Event", "This event is always set for script" },
		{ _field_block, "Midnight Player Goal Properties", &GameEngineFirefightPlayerGoalPropertiesBlock_block },
		{ _field_terminator }
	};

	#define GAME_ENGINE_AI_TRAITS_STRUCT_ID { 0xA7217EE7, 0x772048E4, 0x9BC01D53, 0x380079BA }
	TAG_STRUCT(
		game_engine_ai_traits_struct,
		"game_engine_ai_traits_struct",
		"s_game_engine_ai_traits",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		GAME_ENGINE_AI_TRAITS_STRUCT_ID)
	{
		{ _field_char_enum, "vision traits", &ai_trait_vision_settings },
		{ _field_char_enum, "sound traits", &ai_trait_sound_settings },
		{ _field_char_enum, "luck traits", &ai_trait_luck_settings },
		{ _field_char_enum, "weapon traits", &global_ai_trait_weapon_settings },
		{ _field_char_enum, "grenade traits", &ai_trait_grenade_settings },
		{ _field_char_enum, "drop equipment on death", &player_trait_bool_enum },
		{ _field_char_enum, "assassination immunity", &player_trait_bool_enum },
		{ _field_char_enum, "headshot immunity", &player_trait_bool_enum },
		{ _field_char_enum, "damage resistance percentage", &player_trait_damage_resistance },
		{ _field_char_enum, "damage modifier percentage", &player_trait_damage_modifier },
		FIELD_PAD("pad", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	#define GAME_ENGINE_SURVIVAL_WAVE_PROPERTIES_STRUCT_ID { 0x14F6C0C1, 0x7F794B40, 0x8083C34E, 0x615FA34A }
	TAG_STRUCT(
		game_engine_survival_wave_properties_struct,
		"game_engine_survival_wave_properties_struct",
		"s_survival_wave_properties_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		GAME_ENGINE_SURVIVAL_WAVE_PROPERTIES_STRUCT_ID)
	{
		{ _field_byte_flags, "flags", &survival_wave_properties_flags },
		{ _field_char_enum, "wave selection type", &survival_wave_squad_advance_type_enum },
		FIELD_PAD("VJKNMFEN", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_block, "wave squads", &survival_wave_squad_block },
		{ _field_terminator }
	};

	#define GAME_ENGINE_SURVIVAL_BONUS_WAVE_PROPERTIES_STRUCT_ID { 0x38D197D3, 0x5E0D4E20, 0x89138F88, 0x3567D711 }
	TAG_STRUCT(
		game_engine_survival_bonus_wave_properties_struct,
		"game_engine_survival_bonus_wave_properties_struct",
		"s_survival_bonus_wave_properties_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		GAME_ENGINE_SURVIVAL_BONUS_WAVE_PROPERTIES_STRUCT_ID)
	{
		{ _field_long_flags, "skulls", MAKE_OLD_NAMES("primary skulls"), FIELD_FLAG_INDEX, &skull_flags },
		{ _field_short_integer, "duration", nullptr, "s" },
		FIELD_PAD("CLKJSDF", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_struct, "base properties", &game_engine_survival_wave_properties_struct },
		{ _field_terminator }
	};

	STRINGS(ai_trait_vision_settings)
	{
		"unchanged",
		"normal",
		"blind",
		"near sighted",
		"eagle eye"
	};
	STRING_LIST(ai_trait_vision_settings, ai_trait_vision_settings_strings, _countof(ai_trait_vision_settings_strings));

	STRINGS(ai_trait_sound_settings)
	{
		"unchanged",
		"normal",
		"deaf",
		"sharp"
	};
	STRING_LIST(ai_trait_sound_settings, ai_trait_sound_settings_strings, _countof(ai_trait_sound_settings_strings));

	STRINGS(ai_trait_luck_settings)
	{
		"unchanged",
		"normal",
		"unlucky",
		"lucky",
		"leprechaun"
	};
	STRING_LIST(ai_trait_luck_settings, ai_trait_luck_settings_strings, _countof(ai_trait_luck_settings_strings));

	STRINGS(global_ai_trait_weapon_settings)
	{
		"unchanged",
		"normal",
		"marksman",
		"trigger happy"
	};
	STRING_LIST(global_ai_trait_weapon_settings, global_ai_trait_weapon_settings_strings, _countof(global_ai_trait_weapon_settings_strings));

	STRINGS(ai_trait_grenade_settings)
	{
		"unchanged",
		"normal",
		"none",
		"catch"
	};
	STRING_LIST(ai_trait_grenade_settings, ai_trait_grenade_settings_strings, _countof(ai_trait_grenade_settings_strings));

	STRINGS(game_engine_miscellaneous_options_flags)
	{
		"teams enabled",
		"round reset players",
		"round reset map",
		"perfection enabled",
		"mosh",
		"drop weapons on death",
		"killcam enabled",
		"medal scoring enabled",
		"asymmetric round scoring"
	};
	STRING_LIST(game_engine_miscellaneous_options_flags, game_engine_miscellaneous_options_flags_strings, _countof(game_engine_miscellaneous_options_flags_strings));

	STRINGS(mosh_difficulty)
	{
		"easy",
		"normal",
		"heroic",
		"legendary"
	};
	STRING_LIST(mosh_difficulty, mosh_difficulty_strings, _countof(mosh_difficulty_strings));

	STRINGS(game_engine_respawn_options_flags)
	{
		"inherit respawn time",
		"respawn with teammate",
		"respawn at location",
		"respawn on kills",
		"early respawn allowed"
	};
	STRING_LIST(game_engine_respawn_options_flags, game_engine_respawn_options_flags_strings, _countof(game_engine_respawn_options_flags_strings));

	STRINGS(game_engine_social_options_flags)
	{
		"observers enabled",
		"team changing enabled",
		"team changing balancing only",
		"friendly fire enabled",
		"betrayal booting enabled",
		"enemy voice enabled",
		"open channel voice enabled",
		"dead player voice enabled"
	};
	STRING_LIST(game_engine_social_options_flags, game_engine_social_options_flags_strings, _countof(game_engine_social_options_flags_strings));

	STRINGS(game_engine_map_override_options_flags)
	{
		"grenades on map",
		"shortcuts on map",
		"equipment on map",
		"powerups on map",
		"turrets on map",
		"indestructible vehicles"
	};
	STRING_LIST(game_engine_map_override_options_flags, game_engine_map_override_options_flags_strings, _countof(game_engine_map_override_options_flags_strings));

	STRINGS(game_engine_team_options_team_flags)
	{
		"enabled",
		"primary override color",
		"secondary override color",
		"override ui text tint color",
		"override ui bitmap tint color",
		"override emblem"
	};
	STRING_LIST(game_engine_team_options_team_flags, game_engine_team_options_team_flags_strings, _countof(game_engine_team_options_team_flags_strings));

	STRINGS(game_engine_team_options_player_model_choice)
	{
		"spartan",
		"elite"
	};
	STRING_LIST(game_engine_team_options_player_model_choice, game_engine_team_options_player_model_choice_strings, _countof(game_engine_team_options_player_model_choice_strings));

	STRINGS(game_engine_team_options_model_override_type)
	{
		"none (player choice)",
		"force spartan",
		"force elite",
		"set by team",
		"set by designator"
	};
	STRING_LIST(game_engine_team_options_model_override_type, game_engine_team_options_model_override_type_strings, _countof(game_engine_team_options_model_override_type_strings));

	STRINGS(game_engine_team_options_designator_switch_type)
	{
		"none",
		"random",
		"rotate"
	};
	STRING_LIST(game_engine_team_options_designator_switch_type, game_engine_team_options_designator_switch_type_strings, _countof(game_engine_team_options_designator_switch_type_strings));

	STRINGS(gameEngineOrdnanceOptionsFlags)
	{
		"ordnance enabled"
	};
	STRING_LIST(gameEngineOrdnanceOptionsFlags, gameEngineOrdnanceOptionsFlags_strings, _countof(gameEngineOrdnanceOptionsFlags_strings));

	STRINGS(sandbox_flags)
	{
		"open channel voice",
		"requires all objects"
	};
	STRING_LIST(sandbox_flags, sandbox_flags_strings, _countof(sandbox_flags_strings));

	STRINGS(sandbox_editing_mode)
	{
		"All players",
		"Only Leader"
	};
	STRING_LIST(sandbox_editing_mode, sandbox_editing_mode_strings, _countof(sandbox_editing_mode_strings));

	STRINGS(sandbox_respawn_time)
	{
		"instant",
		"3 seconds",
		"4 seconds",
		"5 seconds",
		"6 seconds",
		"7 seconds",
		"8 seconds",
		"9 seconds",
		"10 seconds",
		"15 seconds",
		"30 seconds",
		"60 seconds"
	};
	STRING_LIST(sandbox_respawn_time, sandbox_respawn_time_strings, _countof(sandbox_respawn_time_strings));

	STRINGS(skull_flags)
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
	STRING_LIST(skull_flags, skull_flags_strings, _countof(skull_flags_strings));

	STRINGS(survival_wave_squad_advance_type_enum)
	{
		"random",
		"sequence"
	};
	STRING_LIST(survival_wave_squad_advance_type_enum, survival_wave_squad_advance_type_enum_strings, _countof(survival_wave_squad_advance_type_enum_strings));

	STRINGS(survival_wave_properties_flags)
	{
		"delivered via dropship"
	};
	STRING_LIST(survival_wave_properties_flags, survival_wave_properties_flags_strings, _countof(survival_wave_properties_flags_strings));

	STRINGS(game_engine_survival_variant_flags)
	{
		"enable scenario hazards",
		"generator defend all",
		"generator random spawn",
		"enable weapon drops",
		"enable ammo crates"
	};
	STRING_LIST(game_engine_survival_variant_flags, game_engine_survival_variant_flags_strings, _countof(game_engine_survival_variant_flags_strings));

	STRINGS(FirefightWaveDeliveryMethod)
	{
		"Dropship",
		"Monster Closet",
		"Drop Pod",
		"Test Spawn"
	};
	STRING_LIST(FirefightWaveDeliveryMethod, FirefightWaveDeliveryMethod_strings, _countof(FirefightWaveDeliveryMethod_strings));

	STRINGS(FirefightWaveDifficulty)
	{
		"Easy",
		"Medium",
		"Hard"
	};
	STRING_LIST(FirefightWaveDifficulty, FirefightWaveDifficulty_strings, _countof(FirefightWaveDifficulty_strings));

	STRINGS(FirefightGoal)
	{
		"Object Destruction",
		"Object Delivery",
		"Location Arrival",
		"Time Passed",
		"No More Waves",
		"Kill Boss",
		"Defense",
		"Other"
	};
	STRING_LIST(FirefightGoal, FirefightGoal_strings, _countof(FirefightGoal_strings));

	STRINGS(GameEnginePlayerGoalFlags)
	{
		"Looping",
		"Random Waves"
	};
	STRING_LIST(GameEnginePlayerGoalFlags, GameEnginePlayerGoalFlags_strings, _countof(GameEnginePlayerGoalFlags_strings));

	STRINGS(GameEngineFirefightVariantFlags)
	{
		"Use Ammo Crates",
		"Players Respawn on Wave"
	};
	STRING_LIST(GameEngineFirefightVariantFlags, GameEngineFirefightVariantFlags_strings, _countof(GameEngineFirefightVariantFlags_strings));

	STRINGS(game_engine_settings_flags)
	{
		"unused"
	};
	STRING_LIST(game_engine_settings_flags, game_engine_settings_flags_strings, _countof(game_engine_settings_flags_strings));

	STRINGS(game_engine_survival_generator_count_enum)
	{
		"None",
		"1 Generator",
		"2 Generators",
		"3 Generators"
	};
	STRING_LIST(game_engine_survival_generator_count_enum, game_engine_survival_generator_count_enum_strings, _countof(game_engine_survival_generator_count_enum_strings));

	TAG_REFERENCE(GameEngineFirefightVariantReference, GAMEENGINEFIREFIGHTVARIANTTAG_TAG);

} // namespace macaque

} // namespace blofeld

