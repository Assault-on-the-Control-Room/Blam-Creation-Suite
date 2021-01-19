#pragma once

namespace blofeld
{

namespace macaque
{

	constexpr unsigned long PLANAR_FOG_PARAMETERS_TAG = 'pfpt';
	extern s_tag_group planar_fog_parameters_group; // planar_fog_parameters_block


	extern s_tag_block_definition planar_fog_parameters_block;
	extern s_tag_block_definition planar_fog_zone_set_visibility_definition_block;
	extern s_tag_struct_definition planar_fog_zone_set_visibility_definition_block_struct_definition; // planar_fog_zone_set_visibility_definition_block
	extern s_tag_block_definition planar_fog_structure_visibility_definition_block;
	extern s_tag_struct_definition planar_fog_structure_visibility_definition_block_struct_definition; // planar_fog_structure_visibility_definition_block
	extern s_tag_block_definition planar_fog_cluster_visibility_definition_block;
	extern s_tag_struct_definition planar_fog_cluster_visibility_definition_block_struct_definition; // planar_fog_cluster_visibility_definition_block
	extern s_tag_block_definition planar_fog_reference_definition_block;
	extern s_tag_struct_definition planar_fog_reference_definition_block_struct_definition; // planar_fog_reference_definition_block
	extern s_tag_block_definition planar_fog_definition_block;
	extern s_tag_struct_definition planar_fog_definition_block_struct_definition; // planar_fog_definition_block
	extern s_tag_block_definition planar_fog_vertex_block;
	extern s_tag_struct_definition planar_fog_vertex_block_struct_definition; // planar_fog_vertex_block
	extern s_tag_block_definition planar_fog_triangle_block;
	extern s_tag_struct_definition planar_fog_triangle_block_struct_definition; // planar_fog_triangle_block
	extern s_tag_block_definition planar_fog_triangle_planes_block;
	extern s_tag_struct_definition planar_fog_triangle_planes_block_struct_definition; // planar_fog_triangle_planes_block

	extern s_tag_struct_definition planar_fog_parameters_struct_definition; // tag group
	extern s_tag_struct_definition planar_fog_set_definition_struct;

	extern c_versioned_string_list planar_fog_flags_strings;
	extern s_string_list_definition planar_fog_flags;

	extern s_tag_reference_definition global_planar_fog_reference;

} // namespace macaque

} // namespace blofeld

