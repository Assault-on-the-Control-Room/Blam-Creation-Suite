#pragma once

namespace blofeld
{

namespace macaque
{

	constexpr unsigned long VEHICLE_TAG = 'vehi';
	extern s_tag_group vehicle_group; // vehicle_block

	extern s_tag_block_definition phantom_shapes_block;
	extern s_tag_struct_definition phantom_shapes_definition; // temp

	extern s_tag_block_definition vehicle_block;
	extern s_tag_block_definition human_tank_block;
	extern s_tag_block_definition human_jeep_block;
	extern s_tag_struct_definition human_jeep_block_struct_definition; // human_jeep_block
	extern s_tag_block_definition human_plane_block;
	extern s_tag_struct_definition human_plane_block_struct_definition; // human_plane_block
	extern s_tag_block_definition wolverine_block;
	extern s_tag_struct_definition wolverine_block_struct_definition; // wolverine_block
	extern s_tag_block_definition alien_scout_block;
	extern s_tag_struct_definition alien_scout_block_struct_definition; // alien_scout_block
	extern s_tag_block_definition alien_fighter_block;
	extern s_tag_struct_definition alien_fighter_block_struct_definition; // alien_fighter_block
	extern s_tag_block_definition turret_block;
	extern s_tag_struct_definition turret_block_struct_definition; // turret_block
	extern s_tag_block_definition mantis_block;
	extern s_tag_struct_definition mantis_block_struct_definition; // mantis_block
	extern s_tag_block_definition vtol_block;
	extern s_tag_struct_definition vtol_block_struct_definition; // vtol_block
	extern s_tag_block_definition vtol_speed_interpolated_block;
	extern s_tag_struct_definition vtol_speed_interpolated_block_struct_definition; // vtol_speed_interpolated_block
	extern s_tag_block_definition chopper_block;
	extern s_tag_struct_definition chopper_block_struct_definition; // chopper_block
	extern s_tag_block_definition guardian_block;
	extern s_tag_struct_definition guardian_block_struct_definition; // guardian_block
	extern s_tag_block_definition jackal_glider_block;
	extern s_tag_struct_definition jackal_glider_block_struct_definition; // jackal_glider_block
	extern s_tag_block_definition boat_block;
	extern s_tag_struct_definition boat_block_struct_definition; // boat_block
	extern s_tag_block_definition space_fighter_block;
	extern s_tag_struct_definition space_fighter_block_struct_definition; // space_fighter_block
	extern s_tag_block_definition revenant_block;
	extern s_tag_struct_definition revenant_block_struct_definition; // revenant_block
	extern s_tag_block_definition SoundRTPCBlock_block;
	extern s_tag_struct_definition SoundRTPCBlock_block_struct_definition; // SoundRTPCBlock_block
	extern s_tag_block_definition SoundSweetenerBlock_block;
	extern s_tag_struct_definition SoundSweetenerBlock_block_struct_definition; // SoundSweetenerBlock_block
	extern s_tag_block_definition physics_transitions_block;
	extern s_tag_struct_definition physics_transitions_block_struct_definition; // physics_transitions_block

	extern s_tag_struct_definition vehicle_struct_definition; // tag group
	extern s_tag_struct_definition vehicle_physics_types_struct;
	extern s_tag_struct_definition human_tank_struct;
	extern s_tag_struct_definition vehicle_steering_control_struct;
	extern s_tag_struct_definition vehicle_turning_control_struct;
	extern s_tag_struct_definition steering_animation_struct;
	extern s_tag_struct_definition engine_function_struct;
	extern s_tag_struct_definition vtol_descent_function_struct;
	extern s_tag_struct_definition flight_surface_struct;
	extern s_tag_struct_definition jackal_glider_drag_struct;

	extern c_versioned_string_list vehicle_flags_strings;
	extern s_string_list_definition vehicle_flags;
	extern c_versioned_string_list vehicle_size_enum_strings;
	extern s_string_list_definition vehicle_size_enum;
	extern c_versioned_string_list alien_scout_specific_type_enum_strings;
	extern s_string_list_definition alien_scout_specific_type_enum;
	extern c_versioned_string_list vehicle_type_enum_strings;
	extern s_string_list_definition vehicle_type_enum;
	extern c_versioned_string_list alien_scout_flags_strings;
	extern s_string_list_definition alien_scout_flags;
	extern c_versioned_string_list tank_flags_strings;
	extern s_string_list_definition tank_flags;
	extern c_versioned_string_list dimensions_enum_strings;
	extern s_string_list_definition dimensions_enum;
	extern c_versioned_string_list turret_flags_strings;
	extern s_string_list_definition turret_flags;
	extern c_versioned_string_list boat_flags_strings;
	extern s_string_list_definition boat_flags;
	extern c_versioned_string_list space_fighter_turn_back_flags_strings;
	extern s_string_list_definition space_fighter_turn_back_flags;
	extern c_versioned_string_list space_fighter_roll_flags_strings;
	extern s_string_list_definition space_fighter_roll_flags;

} // namespace macaque

} // namespace blofeld

