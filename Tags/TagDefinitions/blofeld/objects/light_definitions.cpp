#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(light, LIGHT_TAG, light_block_block );

	TAG_BLOCK_FROM_STRUCT(light_block, 1, light_struct_definition_struct_definition );

	TAG_STRUCT(light_color_function_struct)
	{
		{ _field_string_id, "Input Variable!" },
		{ _field_string_id, "Range Variable!" },
		{ _field_enum, "Output Modifier!", &output_mod_enum },
		{ _field_pad, "BVCG", 2 },
		{ _field_string_id, "Output Modifier Input!" },
		{ _field_custom },
		{ _field_struct, "Mapping", &mapping_function_struct_definition },
		{ _field_terminator }
	};

	TAG_STRUCT(light_scalar_function_struct)
	{
		{ _field_string_id, "Input Variable!" },
		{ _field_string_id, "Range Variable!" },
		{ _field_enum, "Output Modifier!", &output_mod_enum },
		{ _field_pad, "BVCG", 2 },
		{ _field_string_id, "Output Modifier Input!" },
		{ _field_custom },
		{ _field_struct, "Mapping", &mapping_function_struct_definition },
		{ _field_terminator }
	};

	TAG_STRUCT(light_struct_definition)
	{
		// #Todo: move all commented field groups into their own structs 

		{ _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_struct, "Midnight_Light_Parameters", &midnight_light_struct_struct_definition },
		{ _field_terminator },

		{ _field_version_greater_or_equal, _engine_type_haloreach, 3 },
		{ _field_word_flags, "flags", &light_definition_flags }, // #todo test
		{ _field_short_integer, "unused" },
		{ _field_long_enum, "light type:#geometry shape of light.", &midnight_light_type_enum_definition }, // #todo test

		{ _field_version_less, _engine_type_haloreach, 3 },
		{ _field_long_flags, "flags", &light_definition_flags }, // #todo test
		{ _field_enum, "light type:#geometry shape of light.", &midnight_light_type_enum_definition },
		{ _field_short_integer, "unused" },

		{ _field_real, "maximum distance" },

		// struct light_geometry_frustum_parameters
		{ _field_real, "near width" },
		{ _field_real, "height scale", },
		{ _field_angle, "field of view", },

		{ _field_version_greater_or_equal, _engine_type_haloreach, 9 },
		{ _field_real, "unknown", },
		{ _field_explanation, "shared spot parameters", "" },
		{ _field_angle, "inner cone angle:[0-160 degrees]#inner hotspot attenuation end." }, // #todo test
		{ _field_angle, "outer cone end:[0-160 degrees]#angle size of spotlight." }, // #todo test
		{ _field_real, "frustum light spread", },
		{ _field_real, "unknown", },
		{ _field_real, "frustum minimum view distance", },
		{ _field_real, "unknown", },
		{ _field_long_integer, "unknown", },

		// struct light_color_parameters
		{ _field_struct, "color function", &light_color_function_struct_struct_definition },
		{ _field_struct, "brightness function", &light_scalar_function_struct_struct_definition },
		{ _field_tag_reference, "gel map", &global_bitmap_reference },

		// struct light_falloff_parameters
		{ _field_version_less, _engine_type_haloreach, 3 },
		{ _field_real, "light distance diffusion" },
		{ _field_real, "light angular smoothness" },
		{ _field_real, "light angular ambient" },

		// struct light_lifetime_parameters
		{ _field_version_less, _engine_type_haloreach },
		{ _field_real, "destroy after" },

		// struct light_priority_parameters
		{ _field_version_less, _engine_type_haloreach, 4 },
		{ _field_char_enum, "priority near", &e_light_priority },
		{ _field_char_enum, "priority far", &e_light_priority },
		{ _field_char_enum, "transition bias", &e_light_priority_bias },
		{ _field_char_integer, "unused" },

		{ _field_version_greater_or_equal, _engine_type_haloreach, 3 },
		{ _field_real, "rotation:[0-360 degrees]" }, // #todo test
		{ _field_real, "aspect ratio:[-0-1+]#shape length and width of gobo." }, // #todo test
		{ _field_long_integer, "unknown", },

		{ _field_tag_reference, "lens flare", &global_lens_flare_reference },

		{ _field_version_greater_or_equal, _engine_type_haloreach, 8 },
		{ _field_real, "unknown", },
		{ _field_real, "unknown", },
		{ _field_real, "unknown", },
		{ _field_real, "unknown", },
		{ _field_real, "unknown", },
		{ _field_real, "unknown", },
		{ _field_real, "unknown", },
		{ _field_real, "unknown", },

		{ _field_terminator }
	};

	STRINGS(output_mod_enum$4)
	{
		" ",
		"Plus",
		"Times"
	};
	STRING_LIST(output_mod_enum$4, output_mod_enum$4_strings, _countof(output_mod_enum$4_strings));

	STRINGS(e_light_priority)
	{
		"light_priority_default",
		"light_priority_absolutely_required",
		"light_priority_1",
		"light_priority_2",
		"light_priority_3",
		"light_priority_4",
		"light_priority_5",
		"light_priority_6",
		"light_priority_7",
		"light_priority_8",
		"light_priority_9",
		"light_priority_next_to_nothing",
	};
	STRING_LIST(e_light_priority, e_light_priority_strings, _countof(e_light_priority_strings));

	STRINGS(e_light_priority_bias)
	{
		"light_priority_bias_default",
		"light_priority_bias_very_close",
		"light_priority_bias_close",
		"light_priority_bias_middl",
		"light_priority_bias_far",
		"light_priority_bias_very_far",
	};
	STRING_LIST(e_light_priority_bias, e_light_priority_bias_strings, _countof(e_light_priority_bias_strings));

} // namespace blofeld

