#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		light_volume_system_group,
		LIGHT_VOLUME_SYSTEM_TAG,
		nullptr,
		INVALID_TAG,
		light_volume_system_block );

	TAG_BLOCK_FROM_STRUCT(
		light_volume_system_block,
		"light_volume_system_block",
		1,
		light_volume_system_struct_definition);

	#define LIGHT_VOLUME_DEFINITION_BLOCK_ID { 0x7E3CF99B, 0xB85C4AF7, 0x8F990018, 0xB1E1DD8A }
	TAG_BLOCK(
		light_volume_definition_block,
		"light_volume_definition_block",
		c_light_volume_system_definition::k_max_light_volume,
		"c_light_volume_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		LIGHT_VOLUME_DEFINITION_BLOCK_ID)
	{
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_unknown_begin),
		{ _field_string_id, "light_volume name", FIELD_FLAG_INDEX },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 2 },
		{ _field_legacy, _field_explanation, "Render Method" },
		{ _field_legacy, _field_struct, "render method", &render_method_struct_definition_struct_definition },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 4 },
		FIELD_CUSTOM("material", nullptr, FIELD_FLAG_NONE, _field_id_shader_template),
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_hidd_begin),
		{ _field_struct, "actual material?", &material_struct },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_hidd_end),

		{ _field_word_flags, "appearance flags", &light_volume_appearance_flags },
		FIELD_PAD("SONGWEOINGEW", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real, "brightness ratio", "avg. brightness head-on/side-view" },
		{ _field_long_flags, "flags", &light_volume_flags },
		{ _field_real, "LOD in distance", "defaults to 0.0, ignored if 'lod enabled' not checked above" },
		{ _field_real, "LOD feather in delta", "defaults to 0.0, ignored if 'lod enabled' not checked above" },
		{ _field_real, "inverse LOD feather in", FIELD_FLAG_UNKNOWN0 },
		{ _field_real, "LOD out distance", "defaults to 30.0, ignored if 'lod enabled' not checked above" },
		{ _field_real, "LOD feather out delta", "defaults to 10.0, ignored if 'lod enabled' not checked above" },
		{ _field_real, "inverse LOD feather out", FIELD_FLAG_UNKNOWN0 },
		{ _field_struct, "length", &light_volume_property_real },
		{ _field_struct, "offset", &light_volume_property_real },
		{ _field_struct, "profile_density", &light_volume_property_real },
		{ _field_struct, "profile_length", &light_volume_property_real },
		{ _field_struct, "profile_thickness", &light_volume_property_real },
		{ _field_struct, "profile_color", &light_volume_property_real_rgb_color },
		{ _field_struct, "profile_alpha", &light_volume_property_real },
		{ _field_struct, "profile_intensity", &light_volume_property_real },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_unknown_end),
		{ _field_dword_integer, "runtime m_constant_per_profile_properties", FIELD_FLAG_UNKNOWN0 },
		{ _field_dword_integer, "runtime m_used_states", FIELD_FLAG_UNKNOWN0 },
		{ _field_dword_integer, "runtime m_max_profile_count", FIELD_FLAG_UNKNOWN0 },
		{ _field_struct, "runtime m_gpu_data", FIELD_FLAG_UNKNOWN0, &gpu_property_function_color_struct },
		{ _field_block, "precompiled vertices", &light_volume_precompiled_vert_block },
		{ _field_terminator }
	};

	#define LIGHT_VOLUME_PRECOMPILED_VERT_BLOCK_ID { 0x12FEF688, 0x36D54ACF, 0xAF16F740, 0x2A42B196 }
	TAG_BLOCK(
		light_volume_precompiled_vert_block,
		"light_volume_precompiled_vert_block",
		c_light_volume_definition::k_max_precompiled_profiles,
		"c_light_volume_definition::s_precompiled_vertex",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		LIGHT_VOLUME_PRECOMPILED_VERT_BLOCK_ID)
	{
		{ _field_word_integer, "r" },
		{ _field_word_integer, "g" },
		{ _field_word_integer, "b" },
		{ _field_word_integer, "thickness" },
		{ _field_terminator }
	};

	#define LIGHT_VOLUME_SYSTEM_STRUCT_DEFINITION_ID { 0x668829E0, 0x9E2E4295, 0xACE1F43F, 0x067789BC }
	TAG_STRUCT(
		light_volume_system_struct_definition,
		"light_volume_system_struct_definition",
		"c_light_volume_system_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		LIGHT_VOLUME_SYSTEM_STRUCT_DEFINITION_ID)
	{
		{ _field_block, "light_volumes", &light_volume_definition_block },
		{ _field_terminator }
	};

	#define LIGHT_VOLUME_PROPERTY_REAL_ID { 0xBC2E916E, 0x13C1459C, 0x82BC6E0D, 0x888CE0DD }
	TAG_STRUCT(
		light_volume_property_real,
		"light_volume_property_real",
		"c_light_volume_property_real",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		LIGHT_VOLUME_PROPERTY_REAL_ID)
	{
		{ _field_char_enum, "Input Variable", &light_volume_state_input_enum, _field_id_function_input_scalar },
		{ _field_char_enum, "Range Variable", &light_volume_state_input_enum, _field_id_function_input_range },
		{ _field_char_enum, "Output Modifier", &output_mod_enum, _field_id_fnop },
		{ _field_char_enum, "Output Modifier Input", &light_volume_state_input_enum, _field_id_function_output_modifier },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_default),
		{ _field_struct, "Mapping", &mapping_function },
		{ _field_real, "runtime m_constant_value", FIELD_FLAG_UNKNOWN0 },
		{ _field_word_integer, "runtime m_flags", FIELD_FLAG_UNKNOWN0 },
		FIELD_PAD("DSFDSGLKJ", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	#define LIGHT_VOLUME_PROPERTY_REAL_RGB_COLOR_ID { 0x59110FA9, 0x9D244BEE, 0x8CBB0FF2, 0x3A822ECF }
	TAG_STRUCT(
		light_volume_property_real_rgb_color,
		"light_volume_property_real_rgb_color",
		"c_light_volume_property_real_rgb_color",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		LIGHT_VOLUME_PROPERTY_REAL_RGB_COLOR_ID)
	{
		{ _field_char_enum, "Input Variable", &light_volume_state_input_enum, _field_id_function_input_scalar },
		{ _field_char_enum, "Range Variable", &light_volume_state_input_enum, _field_id_function_input_range },
		{ _field_char_enum, "Output Modifier", &output_mod_enum, _field_id_fnop },
		{ _field_char_enum, "Output Modifier Input", &light_volume_state_input_enum, _field_id_function_output_modifier },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_default),
		{ _field_struct, "Mapping", &mapping_function },
		{ _field_real, "runtime m_constant_value", FIELD_FLAG_UNKNOWN0 },
		{ _field_word_integer, "runtime m_flags", FIELD_FLAG_UNKNOWN0 },
		FIELD_PAD("DSFDSGLKJ", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
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

} // namespace macaque

} // namespace blofeld

