#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(scenario_structure_lighting_info, SCENARIO_STRUCTURE_LIGHTING_INFO_TAG, scenario_structure_lighting_info_block_block );

	TAG_BLOCK(structure_lighting_generic_light_definition_block, SHORT_MAX)
	{
		{ _field_version_less_or_equal, _engine_type_haloreach, 18 },
		{ _field_long_integer, "unknown" },
		{ _field_long_enum, "light type:#geometry shape of light.", &midnight_light_type_enum_definition },
		{ _field_real_rgb_color, "light color" },
		{ _field_real, "light intensity" },
		{ _field_angle, "inner cone angle:[0-160 degrees]#inner hotspot attenuation end." },
		{ _field_angle, "outer cone end:[0-160 degrees]#angle size of spotlight." },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },

		{ _field_version_greater, _engine_type_haloreach, 13 },
		{ _field_int64_integer, "Definition Identifier!" },
		{ _field_struct, "Midnight_Light_Parameters", &midnight_light_struct_struct_definition },
		{ _field_long_integer, "Source File Identifier!" },
		{ _field_explanation, "Static Only Parameters", "" },
		{ _field_real, "indirect amplification factor" },
		{ _field_real, "jitter sphere radius" },
		{ _field_real, "jitter angle" },
		{ _field_enum, "jitter quality", &structure_lighting_generic_light_jitter_quality_enum },
		{ _field_char_enum, "sun", &midnight_boolean_enum_definition },
		{ _field_char_enum, "indirect only", &midnight_boolean_enum_definition },
		{ _field_long_flags, "flags", &structure_lighting_generic_light_flags },
		{ _field_char_enum, "static analytic", &midnight_boolean_enum_definition },
		{ _field_pad, "pdd", 3 },
		{ _field_terminator }
	};

	TAG_REFERENCE(structure_lighting_generic_light_instance_unknown_reference0);
	TAG_REFERENCE(structure_lighting_generic_light_instance_unknown_reference1);
	TAG_REFERENCE(structure_lighting_generic_light_instance_unknown_reference3);

	TAG_BLOCK(structure_lighting_generic_light_instance_block, SHORT_MAX)
	{
		{ _field_version_greater, _engine_type_haloreach, 5 },
		{ _field_int64_integer, "Light Definition ID!" },
		{ _field_int64_integer, "Light Instance ID!" },
		{ _field_long_integer, "Light Definition Index!" },
		{ _field_long_integer, "Maya Source Hash!" },
		{ _field_tag_reference, "runtime definition!", &Tag::Reference<struct dynamic_light_definition>::s_defaultDefinition },

		{ _field_version_less_or_equal, _engine_type_haloreach, 1 },
		{ _field_long_integer, "unknown" },

		{ _field_long_enum, "light mode", &structure_lighting_light_mode_enum },
		{ _field_real_point_3d, "origin" },
		{ _field_real_vector_3d, "forward" },
		{ _field_real_vector_3d, "up" },

		{ _field_version_less_or_equal, _engine_type_haloreach, 4 },
		{ _field_long_integer, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },

		{ _field_real, "fade out distance" },
		{ _field_real, "fade start distance" },

		{ _field_version_less_or_equal, _engine_type_haloreach, 4 },
		{ _field_tag_reference, "unknown", &structure_lighting_generic_light_instance_unknown_reference0 },
		{ _field_tag_reference, "unknown", &structure_lighting_generic_light_instance_unknown_reference1 },
		{ _field_tag_reference, "gel map", &global_bitmap_reference },
		{ _field_tag_reference, "unknown", &structure_lighting_generic_light_instance_unknown_reference3 },

		{ _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_long_integer, "Shadow Geometry Checksum" },
		{ _field_pad, "pdd", 4 },
		{ _field_terminator }
	};

	TAG_BLOCK(screen_space_light_shader_override_block, SHORT_MAX)
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

	TAG_BLOCK(structureLightingCinematicObjectBlock, SHORT_MAX)
	{
		{ _field_string_id, "name" },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(structureLightingCinematicLightInstanceBlock, SHORT_MAX, structureLightingCinematicLightInstanceBlock_struct_struct_definition );

	TAG_BLOCK_FROM_STRUCT(scenario_structure_lighting_info_block, 1, scenario_structure_lighting_info_struct_definition_struct_definition );

	TAG_BLOCK(scenario_structure_lighting_info_unknown_block0, 65536)
	{
		{ _field_real, "unknown" },
		{ _field_real_rgb_color, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_terminator }
	};

	TAG_BLOCK(scenario_structure_lighting_info_unknown_block1, 65536)
	{
		{ _field_string_id, "name" },
		{ _field_long_integer, "unknown" },
		{ _field_real, "unknown" },
		{ _field_terminator }
	};

	TAG_STRUCT(scenario_structure_lighting_info_struct_definition)
	{
		{ _field_long_integer, "import info checksum" },
		{ _field_block, "generic light definitions", &structure_lighting_generic_light_definition_block_block },
		{ _field_block, "generic light instances", &structure_lighting_generic_light_instance_block_block },

		{ _field_version_less_or_equal, _engine_type_haloreach, 8 },
		{ _field_real, "unknown@" },
		{ _field_real, "unknown@" },
		{ _field_real, "unknown@" },
		{ _field_real, "unknown@" },
		{ _field_real, "unknown@" },
		{ _field_real, "unknown@" },
		{ _field_block, "unknown", &scenario_structure_lighting_info_unknown_block0_block },
		{ _field_block, "unknown", &scenario_structure_lighting_info_unknown_block1_block },

		{ _field_version_greater, _engine_type_haloreach, 3 },
		{ _field_block, "screen space light shader override", &screen_space_light_shader_override_block_block },
		{ _field_block, "cinematic light instances", &structureLightingCinematicLightInstanceBlock_block },
		{ _field_struct, "Sun Intensity Multiplier", &light_scalar_function_struct_struct_definition },
		{ _field_terminator }
	};

	TAG_STRUCT(structureLightingCinematicLightInstanceBlock_struct)
	{
		{ _field_int64_integer, "Light Instance ID!" },
		{ _field_long_block_index, "Light Definition Index" },
		{ _field_long_block_index, "Light Instance Index" },
		{ _field_array, "Active Shots", &g_cinematicShotFlagArray_array },
		{ _field_block, "Linked Objects", &structureLightingCinematicObjectBlock_block },
		{ _field_pad, "padding", 4 },
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

} // namespace blofeld

