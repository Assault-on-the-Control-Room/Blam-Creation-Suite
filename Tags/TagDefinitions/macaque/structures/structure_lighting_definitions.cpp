#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		scenario_structure_lighting_info_group,
		SCENARIO_STRUCTURE_LIGHTING_INFO_TAG,
		nullptr,
		INVALID_TAG,
		scenario_structure_lighting_info_block );

	TAG_BLOCK_FROM_STRUCT(
		scenario_structure_lighting_info_block,
		"scenario_structure_lighting_info_block",
		1,
		scenario_structure_lighting_info_struct_definition);

	#define STRUCTURE_LIGHTING_GENERIC_LIGHT_DEFINITION_BLOCK_ID { 0x5CAD7A73, 0x815E4084, 0xBEC019F8, 0xB6D14D02 }
	TAG_BLOCK(
		structure_lighting_generic_light_definition_block,
		"structure_lighting_generic_light_definition_block",
		SHORT_MAX,
		"s_structure_lighting_generic_light_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTURE_LIGHTING_GENERIC_LIGHT_DEFINITION_BLOCK_ID)
	{
		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 18 },
		{ _field_legacy, _field_long_integer, "unknown" },
		{ _field_legacy, _field_long_enum, "light type:#geometry shape of light.", &midnight_light_type_enum_definition },
		{ _field_legacy, _field_real_rgb_color, "light color" },
		{ _field_legacy, _field_real, "light intensity" },
		{ _field_legacy, _field_angle, "inner cone angle:[0-160 degrees]#inner hotspot attenuation end." },
		{ _field_legacy, _field_angle, "outer cone end:[0-160 degrees]#angle size of spotlight." },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_real, "unknown" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 13 },
		{ _field_int64_integer, "Definition Identifier", FIELD_FLAG_UNKNOWN0 },
		{ _field_struct, "Midnight_Light_Parameters", &midnight_light_struct },
		{ _field_long_integer, "Source File Identifier", FIELD_FLAG_UNKNOWN0 },
		FIELD_EXPLANATION("Static Only Parameters", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real, "indirect amplification factor" },
		{ _field_real, "jitter sphere radius" },
		{ _field_real, "jitter angle" },
		{ _field_enum, "jitter quality", &structure_lighting_generic_light_jitter_quality_enum },
		{ _field_char_enum, "sun", &midnight_boolean_enum_definition },
		{ _field_char_enum, "indirect only", &midnight_boolean_enum_definition },
		{ _field_long_flags, "flags", &structure_lighting_generic_light_flags },
		{ _field_char_enum, "static analytic", &midnight_boolean_enum_definition },
		FIELD_PAD("pdd", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_terminator }
	};

	TAG_REFERENCE(structure_lighting_generic_light_instance_unknown_reference0);
	TAG_REFERENCE(structure_lighting_generic_light_instance_unknown_reference1);
	TAG_REFERENCE(structure_lighting_generic_light_instance_unknown_reference3);

	#define STRUCTURE_LIGHTING_GENERIC_LIGHT_INSTANCE_BLOCK_ID { 0x09005BBF, 0x4E134B68, 0x9B53BFCC, 0x6CC50117 }
	TAG_BLOCK(
		structure_lighting_generic_light_instance_block,
		"structure_lighting_generic_light_instance_block",
		SHORT_MAX,
		"s_structure_lighting_generic_light_instance",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTURE_LIGHTING_GENERIC_LIGHT_INSTANCE_BLOCK_ID)
	{
		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 5 },
		{ _field_int64_integer, "Light Definition ID", FIELD_FLAG_UNKNOWN0 },
		{ _field_int64_integer, "Light Instance ID", FIELD_FLAG_UNKNOWN0 },
		{ _field_long_integer, "Light Definition Index", FIELD_FLAG_UNKNOWN0 },
		{ _field_long_integer, "Maya Source Hash", FIELD_FLAG_UNKNOWN0 },
		{ _field_tag_reference, "runtime definition", FIELD_FLAG_UNKNOWN0, &Tag::Reference<struct dynamic_light_definition>::s_defaultDefinition },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 1 },
		{ _field_legacy, _field_long_integer, "unknown" },

		{ _field_long_enum, "light mode", &structure_lighting_light_mode_enum },
		{ _field_real_point_3d, "origin" },
		{ _field_real_vector_3d, "forward" },
		{ _field_real_vector_3d, "up" },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 4 },
		{ _field_legacy, _field_long_integer, "unknown" },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_real, "unknown" },

		{ _field_real, "fade out distance" },
		{ _field_real, "fade start distance" },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 4 },
		{ _field_legacy, _field_tag_reference, "unknown", &structure_lighting_generic_light_instance_unknown_reference0 },
		{ _field_legacy, _field_tag_reference, "unknown", &structure_lighting_generic_light_instance_unknown_reference1 },
		{ _field_legacy, _field_tag_reference, "gel map", &global_bitmap_reference },
		{ _field_legacy, _field_tag_reference, "unknown", &structure_lighting_generic_light_instance_unknown_reference3 },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_long_integer, "Shadow Geometry Checksum" },
		FIELD_PAD("pdd", nullptr, FIELD_FLAG_NONE, 4),

		{ _field_terminator }
	};

	V5_TAG_BLOCK(scenario_structure_lighting_info_unknown_block0, 65536)
	{
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_real_rgb_color, "unknown" },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_long_integer, "unknown" },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(scenario_structure_lighting_info_unknown_block1, 65536)
	{
		{ _field_legacy, _field_string_id, "name" },
		{ _field_legacy, _field_long_integer, "unknown" },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_terminator }
	};

	#define SCREEN_SPACE_LIGHT_SHADER_OVERRIDE_BLOCK_ID { 0xC1084686, 0x18CA4C2E, 0x9EA0ADF9, 0xC22C29DF }
	TAG_BLOCK(
		screen_space_light_shader_override_block,
		"screen_space_light_shader_override_block",
		SHORT_MAX,
		"s_screen_space_light_shader_override",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCREEN_SPACE_LIGHT_SHADER_OVERRIDE_BLOCK_ID)
	{
		{ _field_real_rgb_color, "specular color normal" },
		{ _field_real, "specular steepness" },
		{ _field_real_rgb_color, "specular color gazing" },
		{ _field_real, "specular coeff" },
		{ _field_real, "diffuse coeff" },
		{ _field_real, "roughness offset" },
		{ _field_real, "albedo blend" },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(
		structureLightingCinematicLightInstanceBlock_block,
		"structureLightingCinematicLightInstanceBlock",
		SHORT_MAX,
		structureLightingCinematicLightInstanceBlock_struct);

	#define STRUCTURELIGHTINGCINEMATICOBJECTBLOCK_ID { 0x7369B6E6, 0x2808420D, 0x8F97AAAF, 0x27C9838D }
	TAG_BLOCK(
		structureLightingCinematicObjectBlock_block,
		"structureLightingCinematicObjectBlock",
		SHORT_MAX,
		"StructureLightingCinematicObject",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTURELIGHTINGCINEMATICOBJECTBLOCK_ID)
	{
		{ _field_string_id, "name" },
		{ _field_terminator }
	};

	#define SCENARIO_STRUCTURE_LIGHTING_INFO_STRUCT_DEFINITION_ID { 0xF6DF366B, 0xD04D4A01, 0xA4C203FB, 0xA459CB2F }
	TAG_STRUCT(
		scenario_structure_lighting_info_struct_definition,
		"scenario_structure_lighting_info_struct_definition",
		"s_structure_lighting_info",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_STRUCTURE_LIGHTING_INFO_STRUCT_DEFINITION_ID)
	{
		{ _field_long_integer, "import info checksum" },
		{ _field_block, "generic light definitions", &structure_lighting_generic_light_definition_block },
		{ _field_block, "generic light instances", &structure_lighting_generic_light_instance_block },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 8 },
		{ _field_legacy, _field_real, "unknown@" },
		{ _field_legacy, _field_real, "unknown@" },
		{ _field_legacy, _field_real, "unknown@" },
		{ _field_legacy, _field_real, "unknown@" },
		{ _field_legacy, _field_real, "unknown@" },
		{ _field_legacy, _field_real, "unknown@" },
		{ _field_legacy, _field_block, "unknown", &scenario_structure_lighting_info_unknown_block0_block },
		{ _field_legacy, _field_block, "unknown", &scenario_structure_lighting_info_unknown_block1_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 3 },
		{ _field_block, "screen space light shader override", &screen_space_light_shader_override_block },
		{ _field_block, "cinematic light instances", &structureLightingCinematicLightInstanceBlock_block, _field_id_slap },
		{ _field_struct, "Sun Intensity Multiplier", &light_scalar_function_struct },

		{ _field_terminator }
	};

	#define STRUCTURELIGHTINGCINEMATICLIGHTINSTANCEBLOCK_STRUCT_ID { 0x601943D7, 0xAA2240B1, 0xB21A7725, 0x03A7D78D }
	TAG_STRUCT(
		structureLightingCinematicLightInstanceBlock_struct,
		"structureLightingCinematicLightInstanceBlock_struct",
		"StructureLightingCinematicLightInfo",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTURELIGHTINGCINEMATICLIGHTINSTANCEBLOCK_STRUCT_ID)
	{
		{ _field_int64_integer, "Light Instance ID", FIELD_FLAG_UNKNOWN0 },
		{ _field_long_block_index, "Light Definition Index", &structure_lighting_generic_light_definition_block },
		{ _field_long_block_index, "Light Instance Index", &structure_lighting_generic_light_instance_block },
		{ _field_array, "Active Shots", &g_cinematicShotFlagArray_array },
		{ _field_block, "Linked Objects", &structureLightingCinematicObjectBlock_block },
		FIELD_PAD("padding", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_terminator }
	};

	STRINGS(structure_lighting_light_mode_enum)
	{
		"Dynamic",
		"Static",
		"Analytic"
	};
	STRING_LIST(structure_lighting_light_mode_enum, structure_lighting_light_mode_enum_strings, _countof(structure_lighting_light_mode_enum_strings));

	STRINGS(structure_lighting_generic_light_jitter_quality_enum)
	{
		"low",
		"medium",
		"high"
	};
	STRING_LIST(structure_lighting_generic_light_jitter_quality_enum, structure_lighting_generic_light_jitter_quality_enum_strings, _countof(structure_lighting_generic_light_jitter_quality_enum_strings));

	STRINGS(structure_lighting_generic_light_flags)
	{
		"use near attenuation",
		"use far attenuation",
		"invere squared falloff",
		"light version 1"
	};
	STRING_LIST(structure_lighting_generic_light_flags, structure_lighting_generic_light_flags_strings, _countof(structure_lighting_generic_light_flags_strings));

} // namespace macaque

} // namespace blofeld

