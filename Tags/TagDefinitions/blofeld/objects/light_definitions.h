#pragma once

namespace blofeld
{

	constexpr unsigned long LIGHT_TAG = 'ligh';

	extern s_tag_group light_group;

	extern s_tag_block_definition light_block_block;

	extern s_tag_struct_definition light_color_function_struct_struct_definition;
	extern s_tag_struct_definition light_scalar_function_struct_struct_definition;
	extern s_tag_struct_definition light_struct_definition_struct_definition; // tag group

	extern c_versioned_string_list output_mod_enum$4_strings;
	extern s_string_list_definition output_mod_enum$4;

	extern c_versioned_string_list e_light_priority_strings;
	extern s_string_list_definition e_light_priority;

	extern c_versioned_string_list e_light_priority_bias_strings;
	extern s_string_list_definition e_light_priority_bias;

} // namespace blofeld

