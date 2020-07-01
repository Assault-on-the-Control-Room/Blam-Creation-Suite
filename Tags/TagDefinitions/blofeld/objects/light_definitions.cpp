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
		{ _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_struct, "Midnight_Light_Parameters", &midnight_light_struct_struct_definition },
		{ _field_terminator },

		// { _field_real, "destroy light after:seconds#automatically destroys the light after it has existed this long (0 to disable)" },

		{ _field_word_flags, "flags", &light_definition_flags }, // #todo test
		{ _field_short_integer, "unknown" },
		{ _field_long_enum, "light type:#geometry shape of light.", &midnight_light_type_enum_definition }, // #todo test
		{ _field_real, "intensity:[0-1+]" }, // #todo test
		{ _field_real, "radius or size of light" }, // #todo test
		{ _field_real, "unknown@", },
		{ _field_real, "unknown", },
		{ _field_real, "unknown", },
		{ _field_explanation, "shared spot parameters", "" },
		{ _field_real, "inner cone angle:[0-160 degrees]#inner hotspot attenuation end." }, // #todo test
		{ _field_real, "outer cone end:[0-160 degrees]#angle size of spotlight." }, // #todo test
		{ _field_real, "unknown", },
		{ _field_real, "unknown", },
		{ _field_real, "unknown", },
		{ _field_real, "unknown", },
		{ _field_long_integer, "unknown", },
		{ _field_struct, "color function", &light_color_function_struct_struct_definition }, // #todo test
		{ _field_struct, "brightness function", &light_scalar_function_struct_struct_definition }, // #todo test
		{ _field_tag_reference, "gel map", &global_bitmap_reference },
		{ _field_real, "rotation:[0-360 degrees]" }, // #todo test
		{ _field_real, "aspect ratio:[-0-1+]#shape length and width of gobo." }, // #todo test
		{ _field_long_integer, "unknown", },
		{ _field_tag_reference, "lens flare", &global_lens_flare_reference },
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

} // namespace blofeld

