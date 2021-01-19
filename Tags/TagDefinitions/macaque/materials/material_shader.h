#pragma once

namespace blofeld
{

namespace macaque
{

	constexpr unsigned long MATERIAL_SHADER_TAG = 'mats';
	extern s_tag_group material_shader_group; // material_shader_block
	extern s_tag_block_definition material_shader_block;
	extern s_tag_struct_definition material_shader; // material_shader_block


	extern s_tag_block_definition material_shader_source_file_block;
	extern s_tag_struct_definition material_shader_source_file_block_struct_definition; // material_shader_source_file_block
	extern s_tag_block_definition compiled_effects_block;
	extern s_tag_struct_definition compiled_effects_block_struct_definition; // compiled_effects_block
	extern s_tag_block_definition material_vertex_shader_entry_point_block;
	extern s_tag_struct_definition material_vertex_shader_entry_point_block_struct_definition; // material_vertex_shader_entry_point_block
	extern s_tag_block_definition compiled_vertex_shader_refererence_block;
	extern s_tag_struct_definition compiled_vertex_shader_refererence_block_struct_definition; // compiled_vertex_shader_refererence_block
	extern s_tag_block_definition compiled_pixel_shader_refererence_block;
	extern s_tag_struct_definition compiled_pixel_shader_refererence_block_struct_definition; // compiled_pixel_shader_refererence_block


	extern c_versioned_string_list material_shader_flags_strings;
	extern s_string_list_definition material_shader_flags;

} // namespace macaque

} // namespace blofeld

