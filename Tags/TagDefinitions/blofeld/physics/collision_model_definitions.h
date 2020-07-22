#pragma once

namespace blofeld
{

	constexpr unsigned long COLLISION_MODEL_TAG = 'coll';

	extern s_tag_struct_definition collision_model_block_struct;
	extern s_tag_block_definition collision_model_block;
	extern s_tag_group collision_model_group;

	extern s_tag_struct_definition collision_model_material_block_block_struct;
	extern s_tag_block_definition collision_model_material_block_block;
	extern s_tag_block_definition collision_model_bsp_block_block;
	extern s_tag_struct_definition collision_model_permutation_block_block_struct;
	extern s_tag_block_definition collision_model_permutation_block_block;
	extern s_tag_struct_definition collision_model_region_block_block_struct;
	extern s_tag_block_definition collision_model_region_block_block;
	extern s_tag_struct_definition collision_model_pathfinding_sphere_block_block_struct;
	extern s_tag_block_definition collision_model_pathfinding_sphere_block_block;
	extern s_tag_struct_definition collision_model_node_block_block_struct;
	extern s_tag_block_definition collision_model_node_block_block;
	extern s_tag_block_definition collision_model_resource_bsp_block_block;

	extern s_tag_struct_definition collision_model_bsp_struct_struct_definition;
	extern s_tag_struct_definition collision_model_resource_struct_struct_definition;

	extern c_versioned_string_list pathfinding_sphere_flags_strings;
	extern s_string_list_definition pathfinding_sphere_flags;
	extern c_versioned_string_list collision_model_flags_strings;
	extern s_string_list_definition collision_model_flags;

} // namespace blofeld

