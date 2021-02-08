#pragma once

namespace blofeld
{

namespace macaque
{

	constexpr unsigned long COLLISION_MODEL_TAG = 'coll';
	extern s_tag_group collision_model_group; // collision_model_block
	extern s_tag_block_definition collision_model_block;
	extern s_tag_struct_definition collision_model; // collision_model_block


	extern s_tag_block_definition collision_model_material_block;
	extern s_tag_struct_definition collision_model_material_block_struct_definition; // collision_model_material_block
	extern s_tag_block_definition collision_model_region_block;
	extern s_tag_struct_definition collision_model_region_block_struct_definition; // collision_model_region_block
	extern s_tag_block_definition collision_model_permutation_block;
	extern s_tag_struct_definition collision_model_permutation_block_struct_definition; // collision_model_permutation_block
	extern s_tag_block_definition collision_model_bsp_block;
	extern s_tag_block_definition collision_model_pathfinding_sphere_block;
	extern s_tag_struct_definition collision_model_pathfinding_sphere_block_struct_definition; // collision_model_pathfinding_sphere_block
	extern s_tag_block_definition collision_model_node_block;
	extern s_tag_struct_definition collision_model_node_block_struct_definition; // collision_model_node_block
	extern s_tag_block_definition collision_model_resource_bsp_block;

	extern s_tag_struct_definition collision_model_bsp_struct;
	extern s_tag_struct_definition collision_model_resource_struct;

	extern c_versioned_string_list pathfinding_sphere_flags_strings;
	extern s_string_list_definition pathfinding_sphere_flags;
	extern c_versioned_string_list collision_model_flags_strings;
	extern s_string_list_definition collision_model_flags;

} // namespace macaque

} // namespace blofeld
