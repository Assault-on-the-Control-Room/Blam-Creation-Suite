#pragma once

namespace blofeld
{

namespace macaque
{

	constexpr unsigned long POINT_PHYSICS_TAG = 'pphy';
	extern s_tag_group point_physics_group; // point_physics_block


	extern s_tag_block_definition point_physics_block;

	extern s_tag_struct_definition point_physics_struct_definition; // tag group

	extern c_versioned_string_list point_physics_definition_flags_strings;
	extern s_string_list_definition point_physics_definition_flags;

	extern s_tag_reference_definition global_point_physics_reference;

} // namespace macaque

} // namespace blofeld

