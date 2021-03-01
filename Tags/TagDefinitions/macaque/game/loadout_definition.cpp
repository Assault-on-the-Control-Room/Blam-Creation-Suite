#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		loadout_globals_definition_group,
		LOADOUT_GLOBALS_DEFINITION_TAG,
		nullptr,
		INVALID_TAG,
		loadout_globals_definition_block );

	TAG_BLOCK_FROM_STRUCT(
		loadout_globals_definition_block,
		"loadout_globals_definition_block",
		1,
		loadout_globals_definition_struct_definition);

	#define GAME_ENGINE_LOADOUT_OPTIONS_BLOCK_ID { 0x2DF85826, 0x424C4A2B, 0xADE6F7B4, 0x3B780B92 }
	TAG_BLOCK(
		game_engine_loadout_options_block,
		"game_engine_loadout_options_block",
		1,
		"s_game_engine_loadout_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		GAME_ENGINE_LOADOUT_OPTIONS_BLOCK_ID)
	{
		{ _field_byte_flags, "flags", &loadout_flags_definition },
		FIELD_PAD("DLVKJSER", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_block, "loadout palettes", &game_engine_loadout_palette_entry_block },
		{ _field_terminator }
	};

	#define GAME_ENGINE_LOADOUT_PALETTE_ENTRY_BLOCK_ID { 0xEB349E58, 0xB4864414, 0xA31F0584, 0x137CBFC3 }
	TAG_BLOCK(
		game_engine_loadout_palette_entry_block,
		"game_engine_loadout_palette_entry_block",
		k_maximum_game_engine_static_loadout_palettes,
		"s_static_loadout_palette_entry_definition",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		GAME_ENGINE_LOADOUT_PALETTE_ENTRY_BLOCK_ID)
	{
		{ _field_string_id, "palette name", FIELD_FLAG_INDEX },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(
		loadout_definition_block,
		"loadout_definition_block",
		k_maximum_loadouts,
		loadout_definition_struct);

	#define LOADOUT_PALETTE_DEFINITION_BLOCK_ID { 0xEA3BF1F1, 0x1E794E79, 0xA7A6CFF0, 0x12B16524 }
	TAG_BLOCK(
		loadout_palette_definition_block,
		"loadout_palette_definition_block",
		k_maximum_loadout_palettes,
		"s_static_loadout_palette_tag_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		LOADOUT_PALETTE_DEFINITION_BLOCK_ID)
	{
		{ _field_string_id, "palette name" },
		{ _field_block, "loadout choices", &loadout_index_block },
		{ _field_terminator }
	};

	#define LOADOUT_INDEX_BLOCK_ID { 0x9F5C94AF, 0xDA6A4E2D, 0x96F55A0D, 0x2ED3BCD3 }
	TAG_BLOCK(
		loadout_index_block,
		"loadout_index_block",
		k_maximum_loadouts_per_palette,
		"s_static_loadout_tag_reference",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		LOADOUT_INDEX_BLOCK_ID)
	{
		{ _field_short_block_index, "loadout", FIELD_FLAG_INDEX, &loadout_definition_block },
		FIELD_PAD("padding0", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	#define LOADOUT_NAME_BLOCK_ID { 0xEC398708, 0x26884E12, 0x8AFC21CD, 0xFCC7EF66 }
	TAG_BLOCK(
		loadout_name_block,
		"loadout_name_block",
		k_maximum_loadout_names,
		"s_static_loadout_name_tag_definition",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		LOADOUT_NAME_BLOCK_ID)
	{
		{ _field_string_id, "display name", FIELD_FLAG_INDEX },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(
		custom_loadout_defaults_block,
		"custom_loadout_defaults_block",
		k_maximum_loadout_custom_slot_count,
		loadout_definition_struct);

	#define LOADOUT_GLOBALS_DEFINITION_STRUCT_DEFINITION_ID { 0x5693EB43, 0x326642CF, 0x9E14B116, 0x47BA7EC3 }
	TAG_STRUCT(
		loadout_globals_definition_struct_definition,
		"loadout_globals_definition_struct_definition",
		"s_loadout_globals_tag_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		LOADOUT_GLOBALS_DEFINITION_STRUCT_DEFINITION_ID)
	{
		{ _field_block, "loadouts", &loadout_definition_block },
		{ _field_block, "loadout palettes", &loadout_palette_definition_block },
		{ _field_block, "loadout names", &loadout_name_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_block, "default custom loadouts", &custom_loadout_defaults_block },

		{ _field_terminator }
	};

	#define LOADOUT_DEFINITION_STRUCT_ID { 0x5C0C246C, 0x32674BAA, 0x9C95C60D, 0x7F5607D6 }
	TAG_STRUCT(
		loadout_definition_struct,
		"loadout_definition_struct",
		"s_static_loadout_tag_definition",
		SET_UNKNOWN0 | SET_POSTPROCESS_RECURSIVELY | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		LOADOUT_DEFINITION_STRUCT_ID)
	{
		{ _field_string_id, "loadout name", FIELD_FLAG_INDEX },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_string_id, "app1", "name of an element from custom_app_globals/custom_apps.  Can be left empty." },
		{ _field_string_id, "app2", "see above" },

		{ _field_string_id, "initial primary weapon", "name of an element from global starting weapons block. Other values:\n(empty) - unchanged\nunchanged - unchanged\ndefault - take from starting profiles in scenario\nnone - no weapon\nrandom - use random item from valid starting weapons" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_string_id, "initial primary weapon variant name" },

		{ _field_string_id, "initial secondary weapon", "see above" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_string_id, "initial secondary weapon variant name" },

		{ _field_string_id, "initial equipment", "see above" },
		{ _field_char_enum, "initial grenade count", &player_trait_initial_grenade_count_enum },
		FIELD_PAD("SDJCESLRN", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_terminator }
	};

	STRINGS(loadout_flags_definition)
	{
		"custom loadouts enabled",
		"spartan loadouts enabled",
		"elite loadouts enabled",
		"map loadouts enabled"
	};
	STRING_LIST(loadout_flags_definition, loadout_flags_definition_strings, _countof(loadout_flags_definition_strings));

	TAG_REFERENCE(global_loadout_globals_reference, LOADOUT_GLOBALS_DEFINITION_TAG);

} // namespace macaque

} // namespace blofeld

