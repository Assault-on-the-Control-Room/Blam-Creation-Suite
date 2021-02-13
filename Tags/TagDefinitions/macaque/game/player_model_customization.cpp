#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		player_model_customization_globals_group,
		PLAYER_MODEL_CUSTOMIZATION_GLOBALS_TAG,
		nullptr,
		INVALID_TAG,
		player_model_customization_globals_block );

	TAG_BLOCK_FROM_STRUCT(
		player_model_customization_globals_block,
		"player_model_customization_globals_block",
		1,
		player_model_customization_globals_struct_definition);

	#define CUSTOMIZED_MODEL_SELECTION_BLOCK_ID { 0x2C058397, 0x039B4B24, 0x93A3E75D, 0x4E96C6D4 }
	TAG_BLOCK(
		customized_model_selection_block,
		"customized_model_selection_block",
		k_maximum_number_of_model_customization_selections_per_area,
		"s_model_customization_selection",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		CUSTOMIZED_MODEL_SELECTION_BLOCK_ID)
	{
		{ _field_string_id, "selection name", FIELD_FLAG_INDEX },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_string_id, "app name", "Which player-stats modifier should be activated when this item is equipped" },

		{ _field_block, "customized bits", &customized_model_player_bits_block },
		{ _field_terminator }
	};

	#define CUSTOMIZED_MODEL_PLAYER_BITS_BLOCK_ID { 0x3AAA47EC, 0xB8F24CE5, 0x8B427992, 0x05DF23E2 }
	TAG_BLOCK(
		customized_model_player_bits_block,
		"customized_model_player_bits_block",
		k_maximum_number_of_model_customization_bits_per_selection,
		"s_model_customization_player_region_permutation",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CUSTOMIZED_MODEL_PLAYER_BITS_BLOCK_ID)
	{
		{ _field_string_id, "region name", FIELD_FLAG_INDEX },
		{ _field_string_id, "permutation name" },
		{ _field_byte_flags, "flags", &model_customization_player_permutation_flags },
		FIELD_PAD("pad1", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_terminator }
	};

	#define PLAYER_MODEL_CUSTOMIZATION_GLOBALS_STRUCT_DEFINITION_ID { 0x3E8116B0, 0x7B4242AC, 0xA0790D22, 0x888057AC }
	TAG_STRUCT(
		player_model_customization_globals_struct_definition,
		"player_model_customization_globals_struct_definition",
		"s_player_model_customization_globals_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		PLAYER_MODEL_CUSTOMIZATION_GLOBALS_STRUCT_DEFINITION_ID)
	{
		{ _field_tag_reference, "spartan render model", "used for string list generation", &render_model_reference$7 },
		{ _field_tag_reference, "elite render model", FIELD_FLAG_UNKNOWN0, &render_model_reference$7 },
		{ _field_block, "helmet selections", &customized_model_selection_block },
		{ _field_block, "chest selections", &customized_model_selection_block },
		{ _field_block, "elite selections", FIELD_FLAG_UNKNOWN0, &customized_model_selection_block },
		{ _field_block, "left shoulder", &customized_model_selection_block },
		{ _field_block, "right shoulder", &customized_model_selection_block },
		{ _field_block, "arms", &customized_model_selection_block },
		{ _field_block, "legs", &customized_model_selection_block },
		{ _field_block, "unused 5", FIELD_FLAG_UNKNOWN0, &customized_model_selection_block },
		{ _field_block, "spartan armor effect selections", &customized_model_selection_block },
		{ _field_block, "elite armor effect selections", FIELD_FLAG_UNKNOWN0, &customized_model_selection_block },
		{ _field_block, "male spartan selections", &customized_model_player_bits_block },
		{ _field_block, "female spartan selections", &customized_model_player_bits_block },
		{ _field_block, "spartan model defaults", &customized_model_player_bits_block },
		{ _field_block, "elite model defaults", FIELD_FLAG_UNKNOWN0, &customized_model_player_bits_block },
		{ _field_terminator }
	};

	STRINGS(model_customization_player_permutation_flags)
	{
		"male_only#this permutation only applies to male players",
		"female_only#this permutation only applies to female players",
		"mandibles_hidden#this permutation is an elite with enclosed helmet"
	};
	STRING_LIST(model_customization_player_permutation_flags, model_customization_player_permutation_flags_strings, _countof(model_customization_player_permutation_flags_strings));

	TAG_REFERENCE(global_player_model_customization_globals_reference, PLAYER_MODEL_CUSTOMIZATION_GLOBALS_TAG);

} // namespace macaque

} // namespace blofeld

