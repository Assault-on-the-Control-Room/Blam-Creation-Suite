#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		light_group,
		LIGHT_TAG,
		nullptr,
		INVALID_TAG,
		light_block );

	TAG_BLOCK_FROM_STRUCT(
		light_block,
		"light_block",
		1,
		light_struct_definition);

	#define LIGHT_STRUCT_DEFINITION_ID { 0x671EB9F2, 0xB6AF482D, 0x902D0F25, 0xEDB665A1 }
	TAG_STRUCT(
		light_struct_definition,
		"light_struct_definition",
		"dynamic_light_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		LIGHT_STRUCT_DEFINITION_ID)
	{
		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_struct, "Midnight_Light_Parameters", &midnight_light_struct },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 50 }, // #WARN Don't forget to adjust this if changes are made!!

		{ _field_legacy, _field_version_equal, _engine_type_haloreach, 3 },
		{ _field_legacy, _field_word_flags, "flags", &light_definition_flags }, // #todo test
		{ _field_legacy, _field_short_integer, "unused" },
		{ _field_legacy, _field_long_enum, "light type:#geometry shape of light.", &midnight_light_type_enum_definition }, // #todo test

		{ _field_legacy, _field_version_less, _engine_type_haloreach, 3 },
		{ _field_legacy, _field_long_flags, "flags", &light_definition_flags }, // #todo test
		{ _field_legacy, _field_enum, "light type:#geometry shape of light.", &midnight_light_type_enum_definition },
		{ _field_legacy, _field_short_integer, "unused" },

		{ _field_legacy, _field_real, "maximum distance" },

			// struct light_geometry_frustum_parameters
		{ _field_legacy, _field_real, "near width" },
		{ _field_legacy, _field_real, "height scale", },
		{ _field_legacy, _field_angle, "field of view", },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach, 9 },
		{ _field_legacy, _field_real, "unknown", },
		{ _field_legacy, _field_explanation, "shared spot parameters", "" },
		{ _field_legacy, _field_angle, "inner cone angle:[0-160 degrees]#inner hotspot attenuation end." }, // #todo test
		{ _field_legacy, _field_angle, "outer cone end:[0-160 degrees]#angle size of spotlight." }, // #todo test
		{ _field_legacy, _field_real, "frustum light spread", },
		{ _field_legacy, _field_real, "unknown", },
		{ _field_legacy, _field_real, "frustum minimum view distance", },
		{ _field_legacy, _field_real, "unknown", },
		{ _field_legacy, _field_long_integer, "unknown", },

			// struct light_color_parameters
		{ _field_legacy, _field_struct, "color function", &light_color_function_struct_struct_definition },
		{ _field_legacy, _field_struct, "brightness function", &light_scalar_function_struct_struct_definition },
		{ _field_legacy, _field_tag_reference, "gel map", &global_bitmap_reference },

			// struct light_falloff_parameters
		{ _field_legacy, _field_version_less, _engine_type_haloreach, 3 },
		{ _field_legacy, _field_real, "light distance diffusion" },
		{ _field_legacy, _field_real, "light angular smoothness" },
		{ _field_legacy, _field_real, "light angular ambient" },

			// struct light_lifetime_parameters
		{ _field_legacy, _field_version_less, _engine_type_haloreach },
		{ _field_legacy, _field_real, "destroy after" },

			// struct light_priority_parameters
		{ _field_legacy, _field_version_less, _engine_type_haloreach, 4 },
		{ _field_legacy, _field_char_enum, "priority near", &e_light_priority },
		{ _field_legacy, _field_char_enum, "priority far", &e_light_priority },
		{ _field_legacy, _field_char_enum, "transition bias", &e_light_priority_bias },
		{ _field_legacy, _field_char_integer, "unused" },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach, 3 },
		{ _field_legacy, _field_real, "rotation:[0-360 degrees]" }, // #todo test
		{ _field_legacy, _field_real, "aspect ratio:[-0-1+]#shape length and width of gobo." }, // #todo test
		{ _field_legacy, _field_long_integer, "unknown", },

		{ _field_legacy, _field_tag_reference, "lens flare", &global_lens_flare_reference },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach, 8 },
		{ _field_legacy, _field_real, "unknown", },
		{ _field_legacy, _field_real, "unknown", },
		{ _field_legacy, _field_real, "unknown", },
		{ _field_legacy, _field_real, "unknown", },
		{ _field_legacy, _field_real, "unknown", },
		{ _field_legacy, _field_real, "unknown", },
		{ _field_legacy, _field_real, "unknown", },
		{ _field_legacy, _field_real, "unknown", },

		{ _field_terminator }
	};

	#define LIGHT_COLOR_FUNCTION_STRUCT_ID { 0x3DBB8F1A, 0x54F94FD0, 0x9D24DA91, 0x297A3078 }
	TAG_STRUCT(
		light_color_function_struct,
		"light_color_function_struct",
		"light_function",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		LIGHT_COLOR_FUNCTION_STRUCT_ID)
	{
		{ _field_string_id, "Input Variable", FIELD_FLAG_UNKNOWN0, _field_id_function_input_scalar },
		{ _field_string_id, "Range Variable", FIELD_FLAG_UNKNOWN0, _field_id_function_input_range },
		{ _field_enum, "Output Modifier", FIELD_FLAG_UNKNOWN0, &output_mod_enum, _field_id_fnop },
		FIELD_PAD("BVCG", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_string_id, "Output Modifier Input", FIELD_FLAG_UNKNOWN0, _field_id_function_output_modifier },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_default),
		{ _field_struct, "Mapping", &mapping_function },
		{ _field_terminator }
	};

	#define LIGHT_SCALAR_FUNCTION_STRUCT_ID { 0x26AA4A83, 0x42B4434A, 0x93ACA3CB, 0x08A920CD }
	TAG_STRUCT(
		light_scalar_function_struct,
		"light_scalar_function_struct",
		"light_function",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		LIGHT_SCALAR_FUNCTION_STRUCT_ID)
	{
		{ _field_string_id, "Input Variable", FIELD_FLAG_UNKNOWN0, _field_id_function_input_scalar },
		{ _field_string_id, "Range Variable", FIELD_FLAG_UNKNOWN0, _field_id_function_input_range },
		{ _field_enum, "Output Modifier", FIELD_FLAG_UNKNOWN0, &output_mod_enum, _field_id_fnop },
		FIELD_PAD("BVCG", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_string_id, "Output Modifier Input", FIELD_FLAG_UNKNOWN0, _field_id_function_output_modifier },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_default),
		{ _field_struct, "Mapping", &mapping_function },
		{ _field_terminator }
	};

	STRINGS(output_mod_enum$4)
	{
		" ",
		"Plus",
		"Times"
	};
	STRING_LIST(output_mod_enum$4, output_mod_enum$4_strings, _countof(output_mod_enum$4_strings));

} // namespace macaque

} // namespace blofeld

