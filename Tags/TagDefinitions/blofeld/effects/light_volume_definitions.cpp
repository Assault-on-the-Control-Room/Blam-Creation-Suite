#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_GROUP_FROM_BLOCK(light_volume_system, LIGHT_VOLUME_SYSTEM_TAG, light_volume_system_block_block );

	V5_TAG_BLOCK(light_volume_precompiled_vert_block, c_light_volume_definition::k_max_precompiled_profiles)
	{
		{ _field_legacy, _field_word_integer, "r" },
		{ _field_legacy, _field_word_integer, "g" },
		{ _field_legacy, _field_word_integer, "b" },
		{ _field_legacy, _field_word_integer, "thickness" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(light_volume_definition_block, c_light_volume_system_definition::k_max_light_volume)
	{
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_string_id, "light_volume name^" },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 2 },
		{ _field_legacy, _field_explanation, "Render Method" },
		{ _field_legacy, _field_struct, "render method", &render_method_struct_definition_struct_definition },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 4 },
		{ _field_legacy, _field_custom, "material" },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_struct, "actual material\?", &material_block_struct },
		{ _field_legacy, _field_custom },

		{ _field_legacy, _field_word_flags, "appearance flags", &light_volume_appearance_flags },
		{ _field_legacy, _field_pad, "SONGWEOINGEW", 2 },
		{ _field_legacy, _field_real, "brightness ratio#avg. brightness head-on/side-view" },
		{ _field_legacy, _field_long_flags, "flags", &light_volume_flags },
		{ _field_legacy, _field_real, "LOD in distance#defaults to 0.0, ignored if \'lod enabled\' not checked above" },
		{ _field_legacy, _field_real, "LOD feather in delta#defaults to 0.0, ignored if \'lod enabled\' not checked above" },
		{ _field_legacy, _field_real, "inverse LOD feather in!" },
		{ _field_legacy, _field_real, "LOD out distance#defaults to 30.0, ignored if \'lod enabled\' not checked above" },
		{ _field_legacy, _field_real, "LOD feather out delta#defaults to 10.0, ignored if \'lod enabled\' not checked above" },
		{ _field_legacy, _field_real, "inverse LOD feather out!" },
		{ _field_legacy, _field_struct, "length", &light_volume_property_real_struct_definition },
		{ _field_legacy, _field_struct, "offset", &light_volume_property_real_struct_definition },
		{ _field_legacy, _field_struct, "profile_density", &light_volume_property_real_struct_definition },
		{ _field_legacy, _field_struct, "profile_length", &light_volume_property_real_struct_definition },
		{ _field_legacy, _field_struct, "profile_thickness", &light_volume_property_real_struct_definition },
		{ _field_legacy, _field_struct, "profile_color", &light_volume_property_real_rgb_color_struct_definition },
		{ _field_legacy, _field_struct, "profile_alpha", &light_volume_property_real_struct_definition },
		{ _field_legacy, _field_struct, "profile_intensity", &light_volume_property_real_struct_definition },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_dword_integer, "runtime m_constant_per_profile_properties!" },
		{ _field_legacy, _field_dword_integer, "runtime m_used_states!" },
		{ _field_legacy, _field_dword_integer, "runtime m_max_profile_count!" },
		{ _field_legacy, _field_struct, "runtime m_gpuData!", &gpu_property_function_color_struct_struct_definition },
		{ _field_legacy, _field_block, "precompiled vertices", &light_volume_precompiled_vert_block_block },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK_FROM_STRUCT(light_volume_system_block, 1, light_volume_system_struct_definition_struct_definition );

	V5_TAG_STRUCT(light_volume_system_struct_definition)
	{
		{ _field_legacy, _field_block, "light_volumes", &light_volume_definition_block_block },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_STRUCT(light_volume_property_real)
	{
		{ _field_legacy, _field_char_enum, "Input Variable", &light_volume_state_input_enum },
		{ _field_legacy, _field_char_enum, "Range Variable", &light_volume_state_input_enum },
		{ _field_legacy, _field_char_enum, "Output Modifier", &output_mod_enum },
		{ _field_legacy, _field_char_enum, "Output Modifier Input", &light_volume_state_input_enum },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_struct, "Mapping", &mapping_function_struct_definition },
		{ _field_legacy, _field_real, "runtime m_constant_value!" },
		{ _field_legacy, _field_word_integer, "runtime m_flags!" },
		{ _field_legacy, _field_pad, "DSFDSGLKJ", 2 },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_STRUCT(light_volume_property_real_rgb_color)
	{
		{ _field_legacy, _field_char_enum, "Input Variable", &light_volume_state_input_enum },
		{ _field_legacy, _field_char_enum, "Range Variable", &light_volume_state_input_enum },
		{ _field_legacy, _field_char_enum, "Output Modifier", &output_mod_enum },
		{ _field_legacy, _field_char_enum, "Output Modifier Input", &light_volume_state_input_enum },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_struct, "Mapping", &mapping_function_struct_definition },
		{ _field_legacy, _field_real, "runtime m_constant_value!" },
		{ _field_legacy, _field_word_integer, "runtime m_flags!" },
		{ _field_legacy, _field_pad, "DSFDSGLKJ", 2 },
		{ _field_legacy, _field_terminator }
	};

	STRINGS(light_volume_state_input_enum)
	{
		"profile position",
		"game time",
		"light volume age",
		"light volume random",
		"light volume correlation 1",
		"light volume correlation 2",
		"light volume lod",
		"effect a scale",
		"effect b scale",
		"invalid state --- please set again"
	};
	STRING_LIST(light_volume_state_input_enum, light_volume_state_input_enum_strings, _countof(light_volume_state_input_enum_strings));

	STRINGS(output_mod_enum$2)
	{
		" ",
		"Plus",
		"Times"
	};
	STRING_LIST(output_mod_enum$2, output_mod_enum$2_strings, _countof(output_mod_enum$2_strings));

	STRING_LIST(light_volume_appearance_flags, empty_string_list, 0);

	STRINGS(light_volume_flags)
	{
		"lod enabled#if not checked, the following flags do not matter, nor do LOD parameters below",
		"lod always 1.0{ignore lod (render always)}",
		"lod same in splitscreen",
		"disable precompiled profiles",
		"force precompile profiles",
		"can be low res",
		"precompiled!"
	};
	STRING_LIST(light_volume_flags, light_volume_flags_strings, _countof(light_volume_flags_strings));

} // namespace blofeld

