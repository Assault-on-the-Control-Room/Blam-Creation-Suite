#pragma once

namespace blofeld
{

namespace macaque
{

	constexpr unsigned long BIPED_TAG = 'bipd';
	extern s_tag_group biped_group; // biped_block


	extern s_tag_block_definition biped_block;
	extern s_tag_block_definition biped_camera_height_block;
	extern s_tag_struct_definition biped_camera_height_block_struct_definition; // biped_camera_height_block
	extern s_tag_block_definition biped_wall_proximity_block;
	extern s_tag_struct_definition biped_wall_proximity_block_struct_definition; // biped_wall_proximity_block
	extern s_tag_block_definition biped_movement_gate_block;
	extern s_tag_struct_definition biped_movement_gate_block_struct_definition; // biped_movement_gate_block
	extern s_tag_block_definition contact_point_block;
	extern s_tag_struct_definition contact_point_block_struct_definition; // contact_point_block
	extern s_tag_block_definition biped_grab_object_animation_set_block;
	extern s_tag_struct_definition biped_grab_object_animation_set_block_struct_definition; // biped_grab_object_animation_set_block
	extern s_tag_block_definition BipedSoundRTPCBlock_block;
	extern s_tag_struct_definition BipedSoundRTPCBlock_block_struct_definition; // BipedSoundRTPCBlock_block
	extern s_tag_block_definition BipedSoundSweetenerBlock_block;
	extern s_tag_struct_definition BipedSoundSweetenerBlock_block_struct_definition; // BipedSoundSweetenerBlock_block
	extern s_tag_block_definition BipedAimingJointFixupBlock_block;
	extern s_tag_struct_definition BipedAimingJointFixupBlock_block_struct_definition; // BipedAimingJointFixupBlock_block

	extern s_tag_struct_definition biped_struct_definition; // tag group
	extern s_tag_struct_definition biped_leaping_data_struct;
	extern s_tag_struct_definition biped_vaulting_data_struct;
	extern s_tag_struct_definition biped_grab_biped_data_struct;
	extern s_tag_struct_definition biped_grab_object_data_struct;
	extern s_tag_struct_definition biped_ground_fitting_data_struct;
	extern s_tag_struct_definition BipedMovementHipLeaningStruct;

	extern c_versioned_string_list biped_definition_flags_strings;
	extern s_string_list_definition biped_definition_flags;
	extern c_versioned_string_list biped_leap_flags_definition_strings;
	extern s_string_list_definition biped_leap_flags_definition;
	extern c_versioned_string_list grab_biped_throw_control_modes_strings;
	extern s_string_list_definition grab_biped_throw_control_modes;
	extern c_versioned_string_list biped_ground_fitting_flags_definition_strings;
	extern s_string_list_definition biped_ground_fitting_flags_definition;
	extern c_versioned_string_list biped_wall_proximity_composition_mode_strings;
	extern s_string_list_definition biped_wall_proximity_composition_mode;

} // namespace macaque

} // namespace blofeld

