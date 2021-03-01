#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		new_cinematic_lighting_group,
		NEW_CINEMATIC_LIGHTING_TAG,
		nullptr,
		INVALID_TAG,
		new_cinematic_lighting_block );

	TAG_BLOCK_FROM_STRUCT(
		new_cinematic_lighting_block,
		"new_cinematic_lighting_block",
		1,
		new_cinematic_lighting_struct_definition);

	#define CINEMATIC_DYNAMIC_LIGHT_BLOCK_ID { 0x6D9568FD, 0x448D4F36, 0x9C5940F5, 0x15B39D09 }
	TAG_BLOCK(
		cinematic_dynamic_light_block,
		"cinematic_dynamic_light_block",
		16,
		"s_cinematic_dynamic_light",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CINEMATIC_DYNAMIC_LIGHT_BLOCK_ID)
	{
		{ _field_long_flags, "Flags", &cinematic_dynamic_light_flags },
		FIELD_CUSTOM("Dynamic Light", nullptr, FIELD_FLAG_NONE, _field_id_cinematic_dynamic_light),
		FIELD_CUSTOM("Direction", nullptr, FIELD_FLAG_NONE, _field_id_slider_editor),
		{ _field_real, "Direction", _field_id_slider_editor },
		FIELD_CUSTOM("Front-Back", nullptr, FIELD_FLAG_NONE, _field_id_slider_editor),
		{ _field_real, "Front-Back", _field_id_slider_editor },
		{ _field_real, "Distance", nullptr, "world units" },
		{ _field_tag_reference, "light", &global_light_definition_reference },
		{ _field_terminator }
	};

	V5_TAG_BLOCK(cinematic_sh_light_block, 16)
	{
		{ _field_legacy, _field_long_flags, "Flags", & cinematic_dynamic_light_flags },
		{ _field_legacy, _field_custom, "Dynamic Light" },
		{ _field_legacy, _field_custom, "Direction" },
		{ _field_legacy, _field_real, "Direction" },
		{ _field_legacy, _field_custom, "Front-Back" },
		{ _field_legacy, _field_real, "Front-Back" },
		{ _field_legacy, _field_real, "intensity" },
		{ _field_legacy, _field_real_rgb_color, "color" },
		{ _field_legacy, _field_real, "diffusion" },

		{ _field_legacy, _field_terminator }
	};

	#define NEW_CINEMATIC_LIGHTING_STRUCT_DEFINITION_ID { 0x6E8A26A1, 0xE0954B7C, 0xA1044895, 0x5B59B00D }
	TAG_STRUCT(
		new_cinematic_lighting_struct_definition,
		"new_cinematic_lighting_struct_definition",
		"s_cinematic_lighting",
		SET_UNKNOWN0 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | 
		SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		NEW_CINEMATIC_LIGHTING_STRUCT_DEFINITION_ID)
	{
		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach, 38 },
		FIELD_CUSTOM("Cinematic Lighting", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		FIELD_CUSTOM("Cinema Lighting", nullptr, FIELD_FLAG_NONE, _field_id_cinematic_version),

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_long_integer, "version", FIELD_FLAG_UNKNOWN0 },

		FIELD_CUSTOM("Direction&Direction(D)", nullptr, FIELD_FLAG_NONE, _field_id_slider_editor),
		{ _field_real, "Direction&Direction(D)", _field_id_slider_editor },
		FIELD_CUSTOM("Front-Back&Front-Back(D)", nullptr, FIELD_FLAG_NONE, _field_id_slider_editor),
		{ _field_real, "Front-Back&Front-Back(D)", _field_id_slider_editor },
		FIELD_CUSTOM("Shadow Interpolation", nullptr, FIELD_FLAG_NONE, _field_id_slider_editor),
		{ _field_real, "Shadow Interpolation", _field_id_slider_editor },
		FIELD_CUSTOM("Overall weight", nullptr, FIELD_FLAG_NONE, _field_id_slider_editor),
		{ _field_real, "Overall weight", _field_id_slider_editor },
		FIELD_CUSTOM("Direct weight", nullptr, FIELD_FLAG_NONE, _field_id_slider_editor),
		{ _field_real, "Direct weight", _field_id_slider_editor },
		FIELD_CUSTOM("Indirect weight", nullptr, FIELD_FLAG_NONE, _field_id_slider_editor),
		{ _field_real, "Indirect weight", _field_id_slider_editor },
		FIELD_CUSTOM("Airprobe weight", nullptr, FIELD_FLAG_NONE, _field_id_slider_editor),
		{ _field_real, "Airprobe weight", _field_id_slider_editor },
		FIELD_CUSTOM("Sun weight", nullptr, FIELD_FLAG_NONE, _field_id_slider_editor),
		{ _field_real, "Sun weight", _field_id_slider_editor },
		{ _field_real_rgb_color, "Direct color" },
		FIELD_CUSTOM("Direct intensity", nullptr, FIELD_FLAG_NONE, _field_id_slider_editor),
		{ _field_real, "Direct intensity", _field_id_slider_editor },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_real, "unknown" },

		{ _field_real_rgb_color, "Indirect color" },
		FIELD_CUSTOM("Indirect intensity", nullptr, FIELD_FLAG_NONE, _field_id_slider_editor),
		{ _field_real, "Indirect intensity", _field_id_slider_editor },
		FIELD_CUSTOM("Interpolation", nullptr, FIELD_FLAG_NONE, _field_id_slider_editor),
		{ _field_real, "Interpolation", _field_id_slider_editor },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 3 },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_real, "unknown" },

		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_block, "Authored Light Probe", &authored_light_probe_block },
		{ _field_block, "Cortana Lighting", &hologramLightingBlock_block },

		{ _field_legacy, _field_version_less, _engine_type_haloreach, 1 },
		{ _field_legacy, _field_block, "sh lights!", &cinematic_sh_light_block_block },

		{ _field_block, "dynamic lights", FIELD_FLAG_UNKNOWN0, &cinematic_dynamic_light_block },

		{ _field_legacy, _field_version_less, _engine_type_haloreach },
		{ _field_legacy, _field_real, "sampled lighting scale" },

		{ _field_terminator }
	};

	STRINGS(cinematic_dynamic_light_flags)
	{
		"debug this light",
		"follow object",
		"position at marker"
	};
	STRING_LIST(cinematic_dynamic_light_flags, cinematic_dynamic_light_flags_strings, _countof(cinematic_dynamic_light_flags_strings));

	TAG_REFERENCE(global_new_cinematic_lighting_reference, NEW_CINEMATIC_LIGHTING_TAG);

	TAG_REFERENCE(global_light_definition_reference, LIGHT_TAG);

} // namespace macaque

} // namespace blofeld

