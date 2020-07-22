#pragma once

namespace blofeld
{

	constexpr unsigned long FRAME_EVENT_LIST_TAG = 'frms';

	extern s_tag_group frame_event_list_group;
	constexpr unsigned long MODEL_ANIMATION_GRAPH_TAG = 'jmad';

	extern s_tag_struct_definition model_animation_graph_block_struct;
	extern s_tag_block_definition model_animation_graph_block;
	extern s_tag_group model_animation_graph_group;

	extern s_tag_struct_definition animation_graph_sound_reference_block_block_struct;
	extern s_tag_block_definition animation_graph_sound_reference_block_block;
	extern s_tag_struct_definition animation_graph_effect_reference_block_block_struct;
	extern s_tag_block_definition animation_graph_effect_reference_block_block;
	extern s_tag_struct_definition import_frame_event_block_block_struct;
	extern s_tag_block_definition import_frame_event_block_block;
	extern s_tag_struct_definition animation_sound_event_block_extended_block_struct;
	extern s_tag_block_definition animation_sound_event_block_extended_block;
	extern s_tag_struct_definition animation_effects_event_block_extended_block_struct;
	extern s_tag_block_definition animation_effects_event_block_extended_block;
	extern s_tag_struct_definition animation_dialogue_event_block_extended_block_struct;
	extern s_tag_block_definition animation_dialogue_event_block_extended_block;
	extern s_tag_struct_definition animation_script_event_block_extended_block_struct;
	extern s_tag_block_definition animation_script_event_block_extended_block;
	extern s_tag_struct_definition import_animation_event_block_block_struct;
	extern s_tag_block_definition import_animation_event_block_block;
	extern s_tag_block_definition frame_event_list_block_block;
	extern s_tag_struct_definition animation_usage_block_block_struct;
	extern s_tag_block_definition animation_usage_block_block;
	extern s_tag_struct_definition animation_node_mask_entry_block_block_struct;
	extern s_tag_block_definition animation_node_mask_entry_block_block;
	extern s_tag_struct_definition animation_node_mask_block_block_struct;
	extern s_tag_block_definition animation_node_mask_block_block;
	extern s_tag_struct_definition animation_function_block_block_struct;
	extern s_tag_block_definition animation_function_block_block;
	extern s_tag_struct_definition mode_or_stance_alias_block_block_struct;
	extern s_tag_block_definition mode_or_stance_alias_block_block;
	extern s_tag_struct_definition model_animation_variant_block_block_struct;
	extern s_tag_block_definition model_animation_variant_block_block;
	extern s_tag_struct_definition animation_graph_node_block_block_struct;
	extern s_tag_block_definition animation_graph_node_block_block;
	extern s_tag_struct_definition animation_blend_screen_block_block_struct;
	extern s_tag_block_definition animation_blend_screen_block_block;
	extern s_tag_struct_definition foot_tracking_member_block_block_struct;
	extern s_tag_block_definition foot_tracking_member_block_block;
	extern s_tag_struct_definition animation_frame_event_block_block_struct;
	extern s_tag_block_definition animation_frame_event_block_block;
	extern s_tag_struct_definition animation_sound_event_block_block_struct;
	extern s_tag_block_definition animation_sound_event_block_block;
	extern s_tag_struct_definition animation_effect_event_block_block_struct;
	extern s_tag_block_definition animation_effect_event_block_block;
	extern s_tag_struct_definition animation_dialogue_event_block_block_struct;
	extern s_tag_block_definition animation_dialogue_event_block_block;
	extern s_tag_struct_definition animation_script_event_block_block_struct;
	extern s_tag_block_definition animation_script_event_block_block;
	extern s_tag_struct_definition object_space_node_data_block_block_struct;
	extern s_tag_block_definition object_space_node_data_block_block;
	extern s_tag_struct_definition foot_lock_cycle_block_block_struct;
	extern s_tag_block_definition foot_lock_cycle_block_block;
	extern s_tag_struct_definition foot_tracking_block_block_struct;
	extern s_tag_block_definition foot_tracking_block_block;
	extern s_tag_struct_definition object_space_offset_node_block_block_struct;
	extern s_tag_block_definition object_space_offset_node_block_block;
	extern s_tag_struct_definition fik_anchor_node_block_block_struct;
	extern s_tag_block_definition fik_anchor_node_block_block;
	extern s_tag_block_definition animation_ik_chain_events_block;
	extern s_tag_block_definition animation_ik_chain_proxies_block;
	extern s_tag_block_definition animation_facial_wrinkle_events_block;
	extern s_tag_block_definition animation_extended_events_block;
	extern s_tag_block_definition animation_object_functions_block;
	extern s_tag_struct_definition shared_model_animation_block_block_struct;
	extern s_tag_block_definition shared_model_animation_block_block;
	extern s_tag_struct_definition animation_pool_block_block_struct;
	extern s_tag_block_definition animation_pool_block_block;
	extern s_tag_struct_definition new_animation_blend_screen_block_block_struct;
	extern s_tag_block_definition new_animation_blend_screen_block_block;
	extern s_tag_struct_definition new_animation_function_overlay_block_block_struct;
	extern s_tag_block_definition new_animation_function_overlay_block_block;
	extern s_tag_struct_definition blend_screen_item_definition_block_block_struct;
	extern s_tag_block_definition blend_screen_item_definition_block_block;
	extern s_tag_struct_definition function_overlay_item_definition_block_block_struct;
	extern s_tag_block_definition function_overlay_item_definition_block_block;
	extern s_tag_struct_definition overlay_group_definition_block_block_struct;
	extern s_tag_block_definition overlay_group_definition_block_block;
	extern s_tag_struct_definition animation_gait_block_block_struct;
	extern s_tag_block_definition animation_gait_block_block;
	extern s_tag_struct_definition animation_gait_item_block_block_struct;
	extern s_tag_block_definition animation_gait_item_block_block;
	extern s_tag_struct_definition animation_gait_group_block_block_struct;
	extern s_tag_block_definition animation_gait_group_block_block;
	extern s_tag_struct_definition animation_ik_block_block_struct;
	extern s_tag_block_definition animation_ik_block_block;
	extern s_tag_struct_definition animation_ik_set_item_block_struct;
	extern s_tag_block_definition animation_ik_set_item_block;
	extern s_tag_struct_definition animation_ik_set_block_struct;
	extern s_tag_block_definition animation_ik_set_block;
	extern s_tag_struct_definition animation_ik_chain_block_block_struct;
	extern s_tag_block_definition animation_ik_chain_block_block;
	extern s_tag_struct_definition PCAGroupSettingsBlock_block_struct;
	extern s_tag_block_definition PCAGroupSettingsBlock_block;
	extern s_tag_struct_definition animation_entry_block_block_struct;
	extern s_tag_block_definition animation_entry_block_block;
	extern s_tag_struct_definition damage_region_block_block_struct;
	extern s_tag_block_definition damage_region_block_block;
	extern s_tag_struct_definition damage_direction_block_block_struct;
	extern s_tag_block_definition damage_direction_block_block;
	extern s_tag_struct_definition damage_animation_block_block_struct;
	extern s_tag_block_definition damage_animation_block_block;
	extern s_tag_struct_definition animation_transition_destination_block_block_struct;
	extern s_tag_block_definition animation_transition_destination_block_block;
	extern s_tag_struct_definition animation_transition_source_block_block_struct;
	extern s_tag_block_definition animation_transition_source_block_block;
	extern s_tag_struct_definition animation_velocity_boundaries_block_block_struct;
	extern s_tag_block_definition animation_velocity_boundaries_block_block;
	extern s_tag_struct_definition animation_set_block_block_struct;
	extern s_tag_block_definition animation_set_block_block;
	extern s_tag_struct_definition weapon_type_block_block_struct;
	extern s_tag_block_definition weapon_type_block_block;
	extern s_tag_struct_definition animation_ik_block_v1_block_struct;
	extern s_tag_block_definition animation_ik_block_v1_block;
	extern s_tag_struct_definition ranged_animation_entry_block_block_struct;
	extern s_tag_block_definition ranged_animation_entry_block_block;
	extern s_tag_struct_definition triangulation_point_block_block_struct;
	extern s_tag_block_definition triangulation_point_block_block;
	extern s_tag_struct_definition triangulation_triangle_block_block_struct;
	extern s_tag_block_definition triangulation_triangle_block_block;
	extern s_tag_struct_definition triangulation_entry_block_block_struct;
	extern s_tag_block_definition triangulation_entry_block_block;
	extern s_tag_struct_definition animation_ranged_action_block_block_struct;
	extern s_tag_block_definition animation_ranged_action_block_block;
	extern s_tag_struct_definition animation_sync_action_same_type_participant_block_struct;
	extern s_tag_block_definition animation_sync_action_same_type_participant_block;
	extern s_tag_struct_definition animation_sync_action_other_type_participant_block_struct;
	extern s_tag_block_definition animation_sync_action_other_type_participant_block;
	extern s_tag_struct_definition animation_sync_action_block_block_struct;
	extern s_tag_block_definition animation_sync_action_block_block;
	extern s_tag_struct_definition animation_sync_action_group_block_block_struct;
	extern s_tag_block_definition animation_sync_action_group_block_block;
	extern s_tag_struct_definition weapon_class_block_block_struct;
	extern s_tag_block_definition weapon_class_block_block;
	extern s_tag_struct_definition foot_tracking_defaults_block_struct;
	extern s_tag_block_definition foot_tracking_defaults_block;
	extern s_tag_struct_definition animation_mode_block_block_struct;
	extern s_tag_block_definition animation_mode_block_block;
	extern s_tag_struct_definition vehicle_suspension_block_block_struct;
	extern s_tag_block_definition vehicle_suspension_block_block;
	extern s_tag_struct_definition function_overlay_animation_block_block_struct;
	extern s_tag_block_definition function_overlay_animation_block_block;
	extern s_tag_struct_definition inherited_animation_node_map_block_block_struct;
	extern s_tag_block_definition inherited_animation_node_map_block_block;
	extern s_tag_struct_definition inherited_animation_node_map_flag_block_block_struct;
	extern s_tag_block_definition inherited_animation_node_map_flag_block_block;
	extern s_tag_struct_definition inherited_animation_block_block_struct;
	extern s_tag_block_definition inherited_animation_block_block;
	extern s_tag_struct_definition weapon_class_lookup_block_block_struct;
	extern s_tag_block_definition weapon_class_lookup_block_block;
	extern s_tag_struct_definition additional_node_data_block_block_struct;
	extern s_tag_block_definition additional_node_data_block_block;
	extern s_tag_struct_definition model_animation_tag_resource_group_block_struct;
	extern s_tag_block_definition model_animation_tag_resource_group_block;
	extern s_tag_struct_definition shared_static_data_codec_rotation_block_block_struct;
	extern s_tag_block_definition shared_static_data_codec_rotation_block_block;
	extern s_tag_struct_definition shared_static_data_codec_translation_block_block_struct;
	extern s_tag_block_definition shared_static_data_codec_translation_block_block;
	extern s_tag_struct_definition shared_static_data_codec_scale_block_block_struct;
	extern s_tag_block_definition shared_static_data_codec_scale_block_block;
	extern s_tag_struct_definition model_animation_tag_resource_member_block_struct;
	extern s_tag_block_definition model_animation_tag_resource_member_block;

	extern s_tag_struct_definition g_node_flag_storage_array_struct_definition;
	extern s_tag_array_definition g_node_flag_storage_array_array;
	extern s_tag_struct_definition animation_velocity_boundaries_struct_definition;
	extern s_tag_array_definition animation_velocity_boundaries_array;
	extern s_tag_struct_definition frame_event_list_struct_definition_struct_definition; // tag group
	extern s_tag_struct_definition animation_graph_definitions_struct_struct_definition;
	extern s_tag_struct_definition animation_aiming_screen_struct_struct_definition;
	extern s_tag_struct_definition shared_animation_reference_block_struct_definition;
	extern s_tag_struct_definition quantized_orientation_struct_struct_definition;
	extern s_tag_struct_definition animation_ik_chain_events_struct_struct_definition;
	extern s_tag_struct_definition animation_ik_chain_proxies_struct_struct_definition;
	extern s_tag_struct_definition animation_facial_wrinkle_events_struct_struct_definition;
	extern s_tag_struct_definition animation_extended_events_struct_struct_definition;
	extern s_tag_struct_definition animation_object_functions_struct_struct_definition;
	extern s_tag_struct_definition animation_index_struct_struct_definition;
	extern s_tag_struct_definition PCAAnimationDataStruct_struct_definition;
	extern s_tag_struct_definition animation_graph_contents_struct_struct_definition;
	extern s_tag_struct_definition model_animation_runtime_data_struct_struct_definition;
	extern s_tag_struct_definition animation_codec_data_struct_struct_definition;
	extern s_tag_struct_definition shared_static_data_codec_graph_data_struct_struct_definition;
	extern s_tag_struct_definition model_animation_tag_resource_struct_struct_definition;
	extern s_tag_struct_definition packed_data_sizes_struct_struct_definition;

	extern c_versioned_string_list node_joint_flags_strings;
	extern s_string_list_definition node_joint_flags;
	extern c_versioned_string_list node_info_flags_strings;
	extern s_string_list_definition node_info_flags;
	extern c_versioned_string_list animation_node_model_flags_strings;
	extern s_string_list_definition animation_node_model_flags;
	extern c_versioned_string_list key_event_flags_enum_strings;
	extern s_string_list_definition key_event_flags_enum;
	extern c_versioned_string_list key_event_internal_flags_enum_strings;
	extern s_string_list_definition key_event_internal_flags_enum;
	extern c_versioned_string_list animation_type_enum_strings;
	extern s_string_list_definition animation_type_enum;
	extern c_versioned_string_list frame_info_type_enum_strings;
	extern s_string_list_definition frame_info_type_enum;
	extern c_versioned_string_list internal_animation_flags_strings;
	extern s_string_list_definition internal_animation_flags;
	extern c_versioned_string_list frame_event_type_new_strings;
	extern s_string_list_definition frame_event_type_new;
	extern c_versioned_string_list compression_settings_strings;
	extern s_string_list_definition compression_settings;
	extern c_versioned_string_list compression_force_settings_strings;
	extern s_string_list_definition compression_force_settings;
	extern c_versioned_string_list animation_dialogue_event_enum_strings;
	extern s_string_list_definition animation_dialogue_event_enum;
	extern c_versioned_string_list animation_index_flags_strings;
	extern s_string_list_definition animation_index_flags;
	extern c_versioned_string_list production_status_flags_strings;
	extern s_string_list_definition production_status_flags;
	extern c_versioned_string_list object_space_node_flags_strings;
	extern s_string_list_definition object_space_node_flags;
	extern c_versioned_string_list foot_tracking_default_values_strings;
	extern s_string_list_definition foot_tracking_default_values;
	extern c_versioned_string_list animation_ik_chain_type_enumeration_strings;
	extern s_string_list_definition animation_ik_chain_type_enumeration;
	extern c_versioned_string_list animation_ik_chain_event_usage_strings;
	extern s_string_list_definition animation_ik_chain_event_usage;
	extern c_versioned_string_list animation_ik_chain_event_type_strings;
	extern s_string_list_definition animation_ik_chain_event_type;
	extern c_versioned_string_list animation_facial_wrinkle_region_strings;
	extern s_string_list_definition animation_facial_wrinkle_region;
	extern c_versioned_string_list animation_object_function_name_strings;
	extern s_string_list_definition animation_object_function_name;
	extern c_versioned_string_list ranged_action_variable_sources_strings;
	extern s_string_list_definition ranged_action_variable_sources;
	extern c_versioned_string_list blend_screen_definition_flags_strings;
	extern s_string_list_definition blend_screen_definition_flags;
	extern c_versioned_string_list function_overlay_definition_flags_strings;
	extern s_string_list_definition function_overlay_definition_flags;
	extern c_versioned_string_list blend_screen_variable_sources_strings;
	extern s_string_list_definition blend_screen_variable_sources;
	extern c_versioned_string_list blend_screen_weight_sources_strings;
	extern s_string_list_definition blend_screen_weight_sources;
	extern c_versioned_string_list pose_overlay_item_definition_block_flags_strings;
	extern s_string_list_definition pose_overlay_item_definition_block_flags;
	extern c_versioned_string_list animation_gait_directions_strings;
	extern s_string_list_definition animation_gait_directions;
	extern c_versioned_string_list animation_ik_target_enum_definition_strings;
	extern s_string_list_definition animation_ik_target_enum_definition;
	extern c_versioned_string_list animation_ik_set_item_flags_strings;
	extern s_string_list_definition animation_ik_set_item_flags;
	extern c_versioned_string_list animation_sync_action_flags_definition_strings;
	extern s_string_list_definition animation_sync_action_flags_definition;
	extern c_versioned_string_list animation_sync_action_other_type_flags_definition_strings;
	extern s_string_list_definition animation_sync_action_other_type_flags_definition;
	extern c_versioned_string_list animation_mode_flags_strings;
	extern s_string_list_definition animation_mode_flags;
	extern c_versioned_string_list function_overlay_animation_mode_strings;
	extern s_string_list_definition function_overlay_animation_mode;
	extern c_versioned_string_list animation_usage_enumeration_strings;
	extern s_string_list_definition animation_usage_enumeration;
	extern c_versioned_string_list model_animation_variant_flags_strings;
	extern s_string_list_definition model_animation_variant_flags;
	extern c_versioned_string_list private_animation_graph_flags_strings;
	extern s_string_list_definition private_animation_graph_flags;
	extern c_versioned_string_list public_animation_graph_flags_strings;
	extern s_string_list_definition public_animation_graph_flags;
	extern c_versioned_string_list animation_graph_misc_flags_strings;
	extern s_string_list_definition animation_graph_misc_flags;

	extern s_tag_reference_definition global_animation_graph_reference;
	extern s_tag_reference_definition global_frame_event_list_reference;

} // namespace blofeld

