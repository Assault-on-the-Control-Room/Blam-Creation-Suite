#include <tagdefinitions-private-pch.h>

namespace blofeld
{

	const s_tag_struct_definition* tag_struct_definitions[] = 
	{
		&shader_particle_struct_definition_struct_definition, // tag group
		&render_method_struct_definition_struct_definition, // tag group
		&short_block_block_struct, // block
		&render_method_parameter_block_block_struct, // block
		&render_method_animated_parameter_block_block_struct, // block
		&mapping_function_struct_definition,
		&render_method_postprocess_block_block_struct, // block
		&render_method_postprocess_texture_block_block_struct, // block
		&tag_block_index_struct_struct_definition,
		&real_vector4d_block_block_struct, // block
		&int_block_block_struct, // block
		&tag_block_index_block_block_struct, // block
		&render_method_postprocess_pass_block_block_struct, // block
		&render_method_routing_info_block_block_struct, // block
		&runtime_queryable_properties_struct_definition, // array
		&render_method_locked_parameter_block_block_struct, // block
		&cache_file_sound_struct_definition_struct_definition, // tag group
		&sound_effect_template_struct_definition_struct_definition, // tag group
		&sound_effect_templates_block_block_struct, // block
		&sound_effect_template_parameter_block_block_struct, // block
		&sound_effect_template_additional_sound_input_block_block_struct, // block
		&stereo_system_struct_definition_struct_definition, // tag group
		&lightmap_model_globals_struct_definition_struct_definition, // tag group
		&lightmap_model_reference_block_block_struct, // block
		&lightmapper_globals_struct_definition_struct_definition, // tag group
		&global_lightmap_global_settings_struct_struct_definition,
		&global_lightmap_local_settings_struct_struct_definition,
		&global_lightmap_ao_settings_struct_struct_definition,
		&global_lightmap_global_illumination_falloff_settings_struct_struct_definition,
		&global_lightmap_local_override_settings_struct_struct_definition,
		&scenario_lightmap_bsp_data_block_struct, // block
		&scenario_lightmap_cluster_data_block_struct, // block
		&scenario_lightmap_instance_data_block_struct, // block
		&scenario_lightmap_lightprobe_value_block_struct, // block
		&dual_vmf_terms_struct_definition, // array
		&half_rgb_lightprobe_struct_struct_definition,
		&half_sh_terms_struct_definition, // array
		&scenario_lightmap_instance_index_block_block_struct, // block
		&scenario_lightmap_global_perpixel_padding_data_block_struct, // block
		&scenario_lightmap_rasterized_chart_data_block_struct, // block
		&scenario_lightmap_rasterized_chart_source_block_struct, // block
		&scenario_lightmap_rasterized_chart_element_block_struct, // block
		&scenario_lightmap_new_ao_data_block_block_struct, // block
		&scenario_lightmap_adjacent_bounce_vertex_block_block_struct, // block
		&scenario_lightmap_adjacent_bounce_index_block_block_struct, // block
		&global_render_geometry_struct_struct_definition,
		&global_mesh_block_block_struct, // block
		&part_block_block_struct, // block
		&subpart_block_block_struct, // block
		&vertex_buffer_indices_word_array_struct_definition, // array
		&global_instance_bucket_block_block_struct, // block
		&instance_index_word_block_block_struct, // block
		&indices_word_block_block_struct, // block
		&vertexKeyBlock_block_struct, // block
		&PCAMeshIndexBlock_block_struct, // block
		&compression_info_block_block_struct, // block
		&sorting_position_block_block_struct, // block
		&node_indices_array_struct_definition, // array
		&node_weights_implicit_array_struct_definition, // array
		&user_data_block_block_struct, // block
		&global_render_geometry_user_data_header_struct_struct_definition,
		&per_mesh_raw_data_block_block_struct, // block
		&raw_vertex_block_block_struct, // block
		&node_weights_complete_array_struct_definition, // array
		&indices_dword_block_block_struct, // block
		&raw_water_block_block_struct, // block
		&raw_water_append_block_block_struct, // block
		&raw_imposter_brdf_block_block_struct, // block
		&raw_instance_imposter_block_block_struct, // block
		&raw_blendshape_block_block_struct, // block
		&per_mesh_node_map_block_block_struct, // block
		&node_map_byte_block_block_struct, // block
		&per_mesh_subpart_visibility_block_block_struct, // block
		&per_mesh_prt_data_block_block_struct, // block
		&per_instance_prt_data_block_block_struct, // block
		&per_instance_lightmap_texcoords_block_block_struct, // block
		&raw_texcoord_block_block_struct, // block
		&water_bounding_box_block_block_struct, // block
		&render_geometry_pvs_data_block_block_struct, // block
		&render_geometry_pvs_data_visibility_value_block_block_struct, // block
		&render_geometry_pvs_data_visibility_index_block_block_struct, // block
		&shapeNameBlock_block_struct, // block
		&triangle_mapping_per_mesh_block_block_struct, // block
		&triangle_mapping_block_block_struct, // block
		&scenario_lightmap_dynamic_light_instance_block_struct, // block
		&scenario_lightmap_dynamic_light_instance_data_block_block_struct, // block
		&scenario_lightmap_structure_light_instance_block_struct, // block
		&s_scenario_lightmap_silhouette_vertex_block_struct, // block
		&s_scenario_lightmap_silhouette_edge_block_struct, // block
		&s_scenario_lightmap_silhouette_group_block_struct, // block
		&scenario_lightmap_airprobe_value_block_struct, // block
		&global_error_report_categories_block_block_struct, // block
		&error_reports_block_block_struct, // block
		&error_report_vertices_block_block_struct, // block
		&error_report_point_definition_struct_definition,
		&error_point_node_index_array_struct_definition, // array
		&error_point_node_weight_array_struct_definition, // array
		&error_report_vectors_block_block_struct, // block
		&error_report_lines_block_block_struct, // block
		&error_report_line_point_array_struct_definition, // array
		&error_report_triangles_block_block_struct, // block
		&error_report_triangle_point_array_struct_definition, // array
		&error_report_quads_block_block_struct, // block
		&error_report_quad_point_array_struct_definition, // array
		&error_report_comments_block_block_struct, // block
		&global_self_track_block_block_struct, // block
		&streamingzoneset_struct_definition_struct_definition, // tag group
		&StreamingZoneSetResourceIdBlock_block_struct, // block
		&StreamingZoneSetResourceSubregionDataBlock_block_struct, // block
		&StreamingZoneSetResourceLevelsBlock_block_struct, // block
		&achievements_struct_definition_struct_definition, // tag group
		&single_achievement_definition_block_block_struct, // block
		&single_achievement_restricted_level_block_block_struct, // block
		&ai_dialogue_globals_struct_definition_struct_definition, // tag group
		&default_stimulus_suppressor_block_block_struct, // block
		&vocalization_definitions_block_block_struct, // block
		&response_block_block_struct, // block
		&vocalization_patterns_block_block_struct, // block
		&dialogue_data_block_block_struct, // block
		&involuntary_data_block_block_struct, // block
		&predicted_data_block_block_struct, // block
		&ai_globals_struct_definition_struct_definition, // tag group
		&ai_globals_data_block_block_struct, // block
		&ai_globals_gravemind_block_block_struct, // block
		&ai_globals_formation_block_block_struct, // block
		&ai_globals_squad_template_folder_block_block_struct, // block
		&ai_globals_squad_template_sub_folder_block_block_struct, // block
		&ai_globals_squad_template_block_block_struct, // block
		&ai_globals_performance_template_folder_block_block_struct, // block
		&ai_globals_performance_template_sub_folder_block_block_struct, // block
		&ai_globals_performance_template_block_block_struct, // block
		&ai_globals_custom_stimuli_block_block_struct, // block
		&ai_cue_template_block_block_struct, // block
		&firing_point_payload_block_block_struct, // block
		&stimulus_payload_block_block_struct, // block
		&combat_cue_payload_block_block_struct, // block
		&ai_trait_vision_block_block_struct, // block
		&ai_trait_sound_block_block_struct, // block
		&ai_trait_luck_block_block_struct, // block
		&ai_trait_grenade_block_block_struct, // block
		&airstrike_struct_definition_struct_definition, // tag group
		&airstrike_battery_block_block_struct, // block
		&airstrike_fire_location_block_block_struct, // block
		&antenna_struct_definition_struct_definition, // tag group
		&antenna_vertex_block_block_struct, // block
		&armormod_globals_struct_definition_struct_definition, // tag group
		&aural_enhancement_audio_settings_block_block_struct, // block
		&atmosphere_globals_struct_definition_struct_definition, // tag group
		&scalar_function_named_struct_default_one_struct_definition,
		&mapping_function_default_one_struct_definition,
		&underwater_setting_block_block_struct, // block
		&authored_light_probe_block_struct, // block
		&authored_light_probe_lights_block_block_struct, // block
		&real_rgb_lightprobe_array_struct_definition, // array
		&avatar_awards_struct_definition_struct_definition, // tag group
		&single_avatar_award_definition_block_block_struct, // block
		&big_battle_creature_block_struct, // block
		&character_physics_struct_struct_definition,
		&spheres_block_block_struct, // block
		&havok_primitive_struct_struct_definition,
		&havok_convex_shape_struct_struct_definition,
		&havok_shape_struct_struct_definition,
		&havok_convex_translate_shape_struct_struct_definition,
		&havok_shape_reference_struct_struct_definition,
		&pills_block_block_struct, // block
		&lists_block_block_struct, // block
		&havok_shape_collection_struct_2010_2_struct_definition,
		&havok_shape_struct_2010_2_struct_definition,
		&list_shapes_block_block_struct, // block
		&character_physics_ground_struct_struct_definition,
		&character_physics_flying_struct_struct_definition,
		&campaign_metagame_bucket_block_block_struct, // block
		&creature_scalar_timing_block_block_struct, // block
		&scalar_function_named_struct_struct_definition,
		&death_program_selector_struct_definition_struct_definition, // tag group
		&death_program_special_block_block_struct, // block
		&death_program_damage_reporting_block_block_struct, // block
		&death_program_velocity_gate_block_block_struct, // block
		&bink_struct_definition_struct_definition, // tag group
		&biped_group_struct_definition, // tag group
		&unit_struct_definition_struct_definition, // tag group
		&object_struct_definition_struct_definition, // tag group
		&sidecarBlock_block_struct, // block
		&object_early_mover_obb_block_block_struct, // block
		&object_ai_properties_block_block_struct, // block
		&object_function_block_block_struct, // block
		&object_function_interpolation_block_block_struct, // block
		&object_runtime_interpolator_functions_block_block_struct, // block
		&objectFunctionSwitchBlock_block_struct, // block
		&objectFunctionSwitchFunctionBlock_block_struct, // block
		&global_object_attachment_block_block_struct, // block
		&water_physics_hull_surface_definition_block_block_struct, // block
		&water_physics_material_override_block_struct, // block
		&water_physics_drag_properties_struct_struct_definition,
		&physics_force_function_struct_struct_definition,
		&jetwash_definition_block_block_struct, // block
		&object_widget_block_block_struct, // block
		&object_change_colors_block_struct, // block
		&object_change_color_initial_permutation_block_struct, // block
		&object_change_color_function_block_struct, // block
		&g_null_block_block_struct, // block
		&multiplayer_object_block_block_struct, // block
		&spawn_influence_weight_falloff_function_block_block_struct, // block
		&object_spawn_effects_block_block_struct, // block
		&modelDissolveDataBlock_block_struct, // block
		&hs_script_data_struct_struct_definition,
		&hs_source_reference_block_block_struct, // block
		&hs_references_block_block_struct, // block
		&object_abandonment_struct_struct_definition,
		&unit_screen_effect_block_block_struct, // block
		&unit_camera_struct_struct_definition,
		&unit_camera_track_block_block_struct, // block
		&camera_obstruction_struct_struct_definition,
		&unit_camera_acceleration_displacement_block_block_struct, // block
		&unit_camera_acceleration_displacement_function_struct_struct_definition,
		&gamepad_stick_info_block_block_struct, // block
		&input_mapping_function_block_block_struct, // block
		&unit_additional_node_names_struct_struct_definition,
		&WeaponSpecificMarkersBlock_block_struct, // block
		&unit_boarding_melee_struct_struct_definition,
		&unit_postures_block_block_struct, // block
		&hud_unit_sound_block_block_struct, // block
		&hud_unit_sound_cue_block_block_struct, // block
		&dialogue_variant_block_block_struct, // block
		&powered_seat_block_block_struct, // block
		&unit_weapon_block_block_struct, // block
		&SentryPropertiesBlock_block_struct, // block
		&global_target_tracking_parameters_block_block_struct, // block
		&tracking_type_block_block_struct, // block
		&unit_seat_block_block_struct, // block
		&boarding_seat_block_block_struct, // block
		&unit_boost_struct_struct_definition,
		&unit_lipsync_scales_struct_struct_definition,
		&unit_birth_struct_struct_definition,
		&unit_trick_definition_block_block_struct, // block
		&biped_camera_height_block_block_struct, // block
		&biped_wall_proximity_block_block_struct, // block
		&biped_movement_gate_block_block_struct, // block
		&contact_point_block_block_struct, // block
		&biped_leaping_data_struct_struct_definition,
		&biped_vaulting_data_struct_struct_definition,
		&biped_grab_biped_data_struct_struct_definition,
		&biped_grab_object_data_struct_struct_definition,
		&biped_grab_object_animation_set_block_block_struct, // block
		&biped_ground_fitting_data_struct_struct_definition,
		&BipedMovementHipLeaningStruct_struct_definition,
		&BipedSoundRTPCBlock_block_struct, // block
		&BipedSoundSweetenerBlock_block_struct, // block
		&BipedAimingJointFixupBlock_block_struct, // block
		&bitmap_block_struct, // block
		&bitmap_usage_block_block_struct, // block
		&bitmap_group_sequence_block_def_block_struct, // block
		&bitmap_group_sprite_block_def_block_struct, // block
		&bitmap_tight_bounds_block_def_block_struct, // block
		&bitmap_data_block_def_block_struct, // block
		&bitmap_texture_interop_block_block_struct, // block
		&stitchable_bitmap_texture_interop_block_block_struct, // block
		&bitmap_texture_interleaved_interop_block_block_struct, // block
		&crate_struct_definition_struct_definition, // tag group
		&breakable_surface_struct_definition_struct_definition, // tag group
		&particle_system_definition_block_new_block_struct, // block
		&particle_system_emitter_definition_block_block_struct, // block
		&particle_property_real_point3d_struct_new_struct_definition,
		&particle_property_real_euler_angles2d_struct_new_struct_definition,
		&particle_property_scalar_struct_new_struct_definition,
		&particle_physics_struct_struct_definition,
		&particle_controller_block_struct, // block
		&particle_controller_parameters_block_struct, // block
		&emitterGlobalForceBlock_block_struct, // block
		&effect_global_force_struct_definition_struct_definition, // tag group
		&emitterClipSphereBlock_block_struct, // block
		&particle_property_real_vector3d_struct_new_struct_definition,
		&particle_property_color_struct_new_struct_definition,
		&gpu_property_function_color_struct_struct_definition,
		&gpu_property_block_block_struct, // block
		&gpu_property_sub_array_struct_definition, // array
		&gpu_function_block_block_struct, // block
		&gpu_function_sub_array_struct_definition, // array
		&gpu_color_block_block_struct, // block
		&gpu_color_sub_array_struct_definition, // array
		&custom_app_globals_struct_definition_struct_definition, // tag group
		&custom_app_block_block_struct, // block
		&game_engine_player_traits_block_block_struct, // block
		&player_traits_vitality_block_block_struct, // block
		&player_traits_weapons_block_block_struct, // block
		&player_traits_movement_block_block_struct, // block
		&player_traits_appearance_block_block_struct, // block
		&player_traits_sensors_block_block_struct, // block
		&custom_app_damage_modifier_block_block_struct, // block
		&collision_damage_struct_definition_struct_definition, // tag group
		&collision_damage_function_struct_definition,
		&camera_fx_settings_block_struct, // block
		&camera_fx_exposure_struct_struct_definition,
		&camera_fx_exposure_sensitivity_struct_struct_definition,
		&camera_fx_bloom_highlight_struct_struct_definition,
		&camera_fx_bloom_inherent_struct_struct_definition,
		&camera_fx_bloom_self_illum_struct_struct_definition,
		&camera_fx_bloom_intensity_struct_struct_definition,
		&camera_fx_bloom_large_color_struct_struct_definition,
		&camera_fx_bloom_medium_color_struct_struct_definition,
		&camera_fx_bloom_small_color_struct_struct_definition,
		&camera_fx_bling_intensity_struct_struct_definition,
		&camera_fx_bling_size_struct_struct_definition,
		&camera_fx_bling_angle_struct_struct_definition,
		&camera_fx_bling_count_struct_struct_definition,
		&camera_fx_self_illum_preferred_struct_struct_definition,
		&camera_fx_self_illum_scale_struct_struct_definition,
		&camera_fx_color_grading_struct_struct_definition,
		&camera_fx_filmic_tone_curve_struct_struct_definition,
		&character_struct_definition_struct_definition, // tag group
		&character_variants_block_block_struct, // block
		&character_voice_block_block_struct, // block
		&character_voice_region_filter_block_block_struct, // block
		&character_voice_region_permutation_filter_block_block_struct, // block
		&character_voice_properties_block_block_struct, // block
		&character_general_block_block_struct, // block
		&disallowed_weapons_for_trading_block_block_struct, // block
		&character_proto_spawn_block_block_struct, // block
		&character_interact_block_block_struct, // block
		&character_emotions_block_block_struct, // block
		&character_emotions_situational_danger_block_block_struct, // block
		&character_vitality_block_block_struct, // block
		&character_placement_block_block_struct, // block
		&character_perception_block_block_struct, // block
		&active_camo_perception_properties_struct_definition,
		&character_target_block_block_struct, // block
		&character_look_block_block_struct, // block
		&character_hopping_block_block_struct, // block
		&characterHopDefinitionBlock_block_struct, // block
		&character_hop_struct_struct_definition,
		&character_movement_block_block_struct, // block
		&movement_stationary_pause_block_block_struct, // block
		&movement_throttle_control_block_block_struct, // block
		&movement_throttle_block_block_struct, // block
		&SmoothThrottleStruct_struct_definition,
		&SmoothStoppingStruct_struct_definition,
		&character_throttle_style_block_block_struct, // block
		&character_movement_set_block_block_struct, // block
		&movement_mapping_block_block_struct, // block
		&character_flocking_block_block_struct, // block
		&character_swarm_block_block_struct, // block
		&character_firing_point_evaluator_block_block_struct, // block
		&evaluator_definition_block_block_struct, // block
		&character_ready_block_block_struct, // block
		&character_engage_block_block_struct, // block
		&character_charge_block_block_struct, // block
		&character_charge_difficulty_limits_block_block_struct, // block
		&character_evasion_block_block_struct, // block
		&character_cover_block_block_struct, // block
		&character_retreat_block_block_struct, // block
		&character_search_block_block_struct, // block
		&character_presearch_block_block_struct, // block
		&character_idle_block_block_struct, // block
		&character_vocalization_block_block_struct, // block
		&character_boarding_block_block_struct, // block
		&character_vehicle_boarding_block_block_struct, // block
		&character_kungfu_block_block_struct, // block
		&character_bunker_block_block_struct, // block
		&character_bunker_timings_struct_struct_definition,
		&character_guardian_block_block_struct, // block
		&character_combatform_block_block_struct, // block
		&character_engineer_block_block_struct, // block
		&character_inspect_block_block_struct, // block
		&character_scarab_block_block_struct, // block
		&character_weapons_block_block_struct, // block
		&character_firing_pattern_properties_block_block_struct, // block
		&character_firing_pattern_block_block_struct, // block
		&character_grenades_block_block_struct, // block
		&character_vehicle_block_block_struct, // block
		&character_flying_movement_block_block_struct, // block
		&character_morph_block_block_struct, // block
		&character_equipment_block_block_struct, // block
		&character_equipment_usage_block_block_struct, // block
		&character_stimuli_response_block_block_struct, // block
		&character_activity_object_block_block_struct, // block
		&character_pain_screen_block_block_struct, // block
		&character_bishop_block_block_struct, // block
		&character_combotron_parent_block_block_struct, // block
		&character_combotron_child_block_block_struct, // block
		&character_handle_dismemberment_block_block_struct, // block
		&character_cover_fight_block_block_struct, // block
		&character_emerge_block_block_struct, // block
		&dynamic_task_block_block_struct, // block
		&character_advance_block_block_struct, // block
		&character_cover_evasion_block_block_struct, // block
		&character_pack_stalk_block_block_struct, // block
		&character_fight_circle_block_block_struct, // block
		&character_hamstring_charge_block_block_struct, // block
		&character_forerunner_block_block_struct, // block
		&character_gravity_jump_block_block_struct, // block
		&challenge_globals_definition_struct_definition_struct_definition, // tag group
		&challenge_category_block_block_struct, // block
		&challenge_block_block_struct, // block
		&game_mode_flags_struct_struct_definition,
		&cinematic_block_struct, // block
		&cinematic_playback_data_block_struct_definition,
		&cinematic_shot_playback_data_block_block_struct, // block
		&g_cinematicShotFlagArray_struct_definition, // array
		&scenario_and_zone_set_struct_struct_definition,
		&cinematic_custom_script_block_struct_definition,
		&cinematic_scene_reference_block_block_struct, // block
		&cinematic_scene_struct_definition_struct_definition, // tag group
		&cinematic_scene_object_block_block_struct, // block
		&scene_object_attachment_block_block_struct, // block
		&cinematic_shot_block_block_struct, // block
		&cinematic_shot_lighting_block_block_struct, // block
		&cinematic_shot_clip_block_block_struct, // block
		&cinematic_shot_clip_subject_block_block_struct, // block
		&cinematic_shot_music_block_block_struct, // block
		&cinematic_shot_object_function_block_block_struct, // block
		&cinematic_shot_object_function_keyframe_block_block_struct, // block
		&cinematic_shot_screen_effect_block_block_struct, // block
		&cinematic_shot_user_input_constraints_block_block_struct, // block
		&cinematicShotTextureMovieBlock_block_struct, // block
		&cinematicStructureLightingBlock_block_struct, // block
		&cinematic_scene_data_struct_definition_struct_definition, // tag group
		&cinematicSceneDataObjectBlock_struct_struct_definition,
		&cinematicDataShotBlock_block_struct, // block
		&cinematic_shot_dialogue_block_block_struct, // block
		&cinematic_shot_effect_block_block_struct, // block
		&cinematic_shot_custom_script_block_block_struct, // block
		&cinematic_shot_frame_block_block_struct, // block
		&camera_frame_struct_struct_definition,
		&camera_frame_dynamic_struct_struct_definition,
		&camera_frame_constant_struct_struct_definition,
		&cinematic_shot_frame_dynamic_block_block_struct, // block
		&cinematic_shot_frame_constant_block_block_struct, // block
		&cinematic_shot_extra_camera_block_block_struct, // block
		&cinematic_extra_camera_shot_block_block_struct, // block
		&cinematic_extra_camera_frame_block_block_struct, // block
		&cinematic_transition_block_struct, // block
		&cinematic_transition_element_block_struct_definition,
		&cinematic_transition_global_fade_block_struct_definition,
		&cinematic_transition_global_gain_block_block_struct, // block
		&cinematic_transition_sound_class_gain_block_block_struct, // block
		&cinematic_transition_sound_reference_block_block_struct, // block
		&cinematic_transition_looping_sound_reference_block_block_struct, // block
		&cinematic_transition_looping_sound_state_block_block_struct, // block
		&cloth_struct_definition_struct_definition, // tag group
		&collision_sphere_block_block_struct, // block
		&cloth_properties_struct_definition,
		&cloth_vertices_block_block_struct, // block
		&cloth_indices_block_block_struct, // block
		&cloth_links_block_block_struct, // block
		&camo_struct_definition_struct_definition, // tag group
		&camo_scalar_function_struct_struct_definition,
		&controller_mapping_struct_definition_struct_definition, // tag group
		&commendation_aggregator_list_struct_definition_struct_definition, // tag group
		&commendationAggregator_block_struct, // block
		&commendationRewardBlock_block_struct, // block
		&commendationAggregatorDependent_struct_struct_definition,
		&collision_model_block_struct, // block
		&collision_model_material_block_block_struct, // block
		&collision_model_region_block_block_struct, // block
		&collision_model_permutation_block_block_struct, // block
		&collision_model_bsp_struct_struct_definition,
		&global_collision_bsp_struct_struct_definition,
		&bsp3d_nodes_block_block_struct, // block
		&bsp3d_kd_supdernodes_block_block_struct, // block
		&planes_block_block_struct, // block
		&collision_leaf_struct_struct_definition,
		&bsp2d_references_block_block_struct, // block
		&bsp2d_nodes_block_block_struct, // block
		&surfaces_block_block_struct, // block
		&edges_block_block_struct, // block
		&vertices_block_block_struct, // block
		&collision_bsp_physics_block_block_struct, // block
		&collision_geometry_shape_struct_struct_definition,
		&mopp_bv_tree_shape_struct_struct_definition,
		&mopp_code_definition_block_block_struct, // block
		&mopp_code_data_definition_block_block_struct, // block
		&collision_model_pathfinding_sphere_block_block_struct, // block
		&collision_model_node_block_block_struct, // block
		&color_table_struct_definition_struct_definition, // tag group
		&color_block_block_struct, // block
		&commendation_globals_definition_struct_definition_struct_definition, // tag group
		&commendationBlock_block_struct, // block
		&PurchasePrerequisitesUnifiedDefinitionBlock_struct_definition,
		&purchase_prerequisite_grade_definition_block_block_struct, // block
		&purchase_prerequisite_commendation_definition_block_block_struct, // block
		&PurchasePrerequisitePurchasedAppearanceItemDefinitionBlock_block_struct, // block
		&PurchaseAppearanceDefinitionReferenceStruct_struct_definition,
		&PurchasePrerequisitePurchasedLoadoutItemDefinitionBlock_block_struct, // block
		&PurchaseLoadoutDefinitionReferenceStruct_struct_definition,
		&PurchasePrerequisitePurchasedOrdnanceItemDefinitionBlock_block_struct, // block
		&PurchaseOrdnanceDefinitionReferenceStruct_struct_definition,
		&purchase_prerequisites_unlockable_definition_block_block_struct, // block
		&purchase_prerequisites_offer_definition_block_block_struct, // block
		&commendationLevelBlock_block_struct, // block
		&communication_sounds_struct_definition_struct_definition, // tag group
		&reward_globals_definition_struct_definition_struct_definition, // tag group
		&rewardDefinitionBlock_block_struct, // block
		&rewardBlock_block_struct, // block
		&coop_spawning_globals_definition_struct_definition_struct_definition, // tag group
		&cheap_particle_emitter_struct_definition_struct_definition, // tag group
		&cheap_particle_scalar_object_function_struct_struct_definition,
		&cookie_purchase_globals_struct_definition_struct_definition, // tag group
		&CookiePurchaseFamilyAppearanceDefinitionBlock_block_struct, // block
		&CookiePurchaseAppearanceDefinitionReferenceBlock_block_struct, // block
		&CookiePurchaseFamilyLoadoutDefinitionBlock_block_struct, // block
		&CookiePurchaseLoadoutDefinitionReferenceBlock_block_struct, // block
		&CookiePurchaseFamilyOrdnanceDefinitionBlock_block_struct, // block
		&CookiePurchaseOrdnanceDefinitionReferenceBlock_block_struct, // block
		&CookiePurchaseAppearanceDefinitionBlock_block_struct, // block
		&PurchasePlayerAppearanceStruct_struct_definition,
		&purchase_player_appearance_effect_model_permutation_block_block_struct, // block
		&purchase_player_appearance_effect_non_model_permutation_block_block_struct, // block
		&purchase_player_appearance_effect_visor_tint_block_block_struct, // block
		&purchase_player_appearance_effect_emblem_index_block_block_struct, // block
		&PurchasePlayerAppearancePoseBlock_block_struct, // block
		&CookiePurchaseExternalUnlockableBlockAppearanceDefinition_block_struct, // block
		&CookiePurchaseLoadoutDefinitionBlock_block_struct, // block
		&PurchasePlayerLoadoutStruct_struct_definition,
		&purchase_player_item_block_block_struct, // block
		&purchase_player_app_block_block_struct, // block
		&purchase_player_loadout_slot_block_block_struct, // block
		&purchase_player_app_mod_slot_block_block_struct, // block
		&CookiePurchaseExternalUnlockableBlockLoadoutDefinition_block_struct, // block
		&CookiePurchaseOrdnanceDefinitionBlock_block_struct, // block
		&PurchasePlayerOrdnanceStruct_struct_definition,
		&PurchasePlayerOrdnanceItemBlock_block_struct, // block
		&PurchasePlayerOrdnanceSlotBlock_block_struct, // block
		&CookiePurchaseExternalUnlockableBlockOrdnanceDefinition_block_struct, // block
		&cheap_particle_type_library_struct_definition_struct_definition, // tag group
		&cheap_particle_type_block_block_struct, // block
		&cheap_particle_bitmap_reference_block_block_struct, // block
		&cheapParticleTurbulenceTypeBlock_block_struct, // block
		&creature_struct_definition_struct_definition, // tag group
		&curve_scalar_struct_definition_struct_definition, // tag group
		&camera_shake_struct_definition_struct_definition, // tag group
		&camera_impulse_struct_struct_definition,
		&camera_shake_struct_struct_definition,
		&device_control_struct_definition_struct_definition, // tag group
		&device_struct_definition_struct_definition, // tag group
		&cui_logic_struct_definition_struct_definition, // tag group
		&cui_system_struct_definition,
		&template_instantiation_block_definition_block_struct, // block
		&component_definition_block_struct, // block
		&component_index_block_definition_block_struct, // block
		&overlay_definition_block_struct, // block
		&component_properties_definition_block_struct, // block
		&properties_struct_struct_definition,
		&property_long_value_block_struct, // block
		&property_real_value_block_struct, // block
		&property_string_id_value_block_struct, // block
		&propertyComponentPtrValue_block_struct, // block
		&property_tag_reference_value_block_struct, // block
		&property_text_value_block_struct, // block
		&property_argb_color_value_block_struct, // block
		&animation_definition_block_struct, // block
		&animation_component_definition_block_struct, // block
		&animation_component_real_property_block_struct, // block
		&animation_property_keyframe_real_value_block_struct, // block
		&animation_scalar_function_struct_definition,
		&animation_component_argb_color_property_block_struct, // block
		&animation_property_keyframe_argb_color_value_block_struct, // block
		&overlay_editor_only_definition_block_struct, // block
		&component_editor_only_definition_block_struct, // block
		&property_editor_only_definition_block_struct, // block
		&animation_editor_only_definition_block_struct, // block
		&property_binding_block_struct, // block
		&binding_conversion_long_comparison_block_definition_block_struct, // block
		&static_data_table_block_struct, // block
		&static_data_struct_struct_definition,
		&static_data_column_block_struct, // block
		&expression_block_struct, // block
		&expression_step_block_struct, // block
		&encapsulatedProperties_block_struct, // block
		&cui_screen_struct_definition_struct_definition, // tag group
		&string_file_references_block_struct, // block
		&cui_static_data_struct_definition_struct_definition, // tag group
		&decorator_set_block_struct, // block
		&decorator_set_instance_name_block_block_struct, // block
		&global_decorator_type_struct_struct_definition,
		&decal_system_struct_definition_struct_definition, // tag group
		&decal_definition_block_block_struct, // block
		&material_struct_struct_definition,
		&material_shader_parameter_block_block_struct, // block
		&material_shader_function_parameter_block_block_struct, // block
		&material_postprocess_block_block_struct, // block
		&material_postprocess_texture_block_block_struct, // block
		&real_vector4d_block$3_block_struct, // block
		&int_block$3_block_struct, // block
		&functionParameterBlock_block_struct, // block
		&externParameterBlock_block_struct, // block
		&runtime_queryable_properties$3_struct_definition, // array
		&material_type_struct_struct_definition,
		&cellular_automata_struct_definition_struct_definition, // tag group
		&detail_object_collection_struct_definition_struct_definition, // tag group
		&detail_object_type_block_block_struct, // block
		&dependency_struct_definition_struct_definition, // tag group
		&one_dependency_block_definition_block_struct, // block
		&rasterizer_cache_file_globals_struct_definition_struct_definition, // tag group
		&damage_response_definition_struct_definition_struct_definition, // tag group
		&damage_response_class_block_block_struct, // block
		&damage_response_directional_flash_struct_struct_definition,
		&damage_response_motion_sensor_ping_struct_definition,
		&damage_response_global_sound_effect_block_block_struct, // block
		&area_control_block_block_struct, // block
		&area_control_scalar_function_struct_struct_definition,
		&area_control_scalar_object_function_struct_struct_definition,
		&device_dispenser_struct_definition_struct_definition, // tag group
		&particle_emitter_boat_hull_shape_struct_definition_struct_definition, // tag group
		&particle_emitter_boat_hull_group_block_block_struct, // block
		&effect_block_struct, // block
		&effect_locations_block_block_struct, // block
		&effect_event_block_block_struct, // block
		&effect_part_block_block_struct, // block
		&effect_accelerations_block_block_struct, // block
		&effect_looping_sound_block_block_struct, // block
		&effect_conical_distribution_block_block_struct, // block
		&effect_globals_struct_definition_struct_definition, // tag group
		&effect_component_holdbacks_block_block_struct, // block
		&effect_component_holdback_block_block_struct, // block
		&effect_global_spawn_effects_block_block_struct, // block
		&effect_scenery_struct_definition_struct_definition, // tag group
		&entity_struct_definition_struct_definition, // tag group
		&equipment_struct_definition_struct_definition, // tag group
		&item_struct_definition_struct_definition, // tag group
		&predicted_bitmaps_block_block_struct, // block
		&optionalUnitCameraBlock_block_struct, // block
		&equipmentAbilityDatum_block_struct, // block
		&equipmentAbilityTypeMultiplayerPowerupBlock_block_struct, // block
		&equipmentAbilityTypeSpawnerBlock_block_struct, // block
		&equipmentAbilityTypeAiSpawnerBlock_block_struct, // block
		&equipmentAbilityTypeProximityMineBlock_block_struct, // block
		&equipmentAbilityTypeMotionTrackerNoiseBlock_block_struct, // block
		&equipmentAbilityTypeInvincibilityBlock_block_struct, // block
		&equipmentEffectWithThresholdBlock_block_struct, // block
		&equipmentAbilityTypeTreeOfLifeBlock_block_struct, // block
		&equipmentAbilityTypeShapeshifterBlock_block_struct, // block
		&equipmentAbilityTypePlayerTraitFieldBlock_block_struct, // block
		&equipmentAbilityTypeAiTraitFieldBlock_block_struct, // block
		&aiEquipmentTraitsBlock_block_struct, // block
		&aiEquipmentTraitAppearanceBlock_block_struct, // block
		&equipmentAbilityTypeRepulsorFieldBlock_block_struct, // block
		&equipmentAbilityTypeStasisFieldBlock_block_struct, // block
		&equipmentAbilityTypeBallLightningBlock_block_struct, // block
		&equipmentAbilityTypeDaddyBlock_block_struct, // block
		&equipmentAbilityTypeLaserDesignationBlock_block_struct, // block
		&equipmentAbilityTypeSuperJumpBlock_block_struct, // block
		&equipmentAbilityTypeAmmoPackBlock_block_struct, // block
		&equipmentAbilityTypePowerFistBlock_block_struct, // block
		&equipmentAbilityTypeHealthPackBlock_block_struct, // block
		&equipmentAbilityTypeJetPackBlock_block_struct, // block
		&equipmentAbilityPartCowCatcherBlock_block_struct, // block
		&equipmentAbilityTypeHologramBlock_block_struct, // block
		&equipmentAbilityTypeSpecialWeaponBlock_block_struct, // block
		&equipmentAbilityTypeSpecialMoveBlock_block_struct, // block
		&equipmentAbilityTypeEngineerShieldsBlock_block_struct, // block
		&equipmentAbilityTypeSprintBlock_block_struct, // block
		&equipmentAbilityTypeTeleporterBlock_block_struct, // block
		&equipmentAbilityTypeAutoTurretBlock_block_struct, // block
		&equipmentAbilityTypeVisionModeBlock_block_struct, // block
		&equipmentAbilityTypeShieldProjectorBlock_block_struct, // block
		&equipmentAbilityTypeProjectileCollectorBlock_block_struct, // block
		&equipmentAbilityTypeRemoteStrikeBlock_block_struct, // block
		&equipmentAbilityTypeEquipmentHackerBlock_block_struct, // block
		&equipmentHackerDrainLevel_block_struct, // block
		&equipmentAbilityTypeRemoteVehicleBlock_block_struct, // block
		&equipmentAbilityTypeSuicideBombBlock_block_struct, // block
		&equipmentAbilityTypeActiveShieldBlock_block_struct, // block
		&EquipmentSoundRTPCBlock_block_struct, // block
		&EquipmentSoundSweetenerBlock_block_struct, // block
		&firefight_globals_block_struct, // block
		&firefightWaveTemplatesBlock_struct_struct_definition,
		&GameEngineFirefightVariantTag_block_struct, // block
		&gameEngineFirefightVariantDefinition_struct_definition,
		&game_engine_miscellaneous_options_block_block_struct, // block
		&game_engine_prototype_options_block_block_struct, // block
		&game_engine_respawn_options_block_block_struct, // block
		&game_engine_social_options_block_block_struct, // block
		&game_engine_map_override_options_block_block_struct, // block
		&game_engine_team_options_block_block_struct, // block
		&game_engine_team_options_team_block_struct_definition, // array
		&game_engine_loadout_options_block_block_struct, // block
		&game_engine_loadout_palette_entry_block_block_struct, // block
		&gameEngineOrdnanceOptionsBlock_block_struct, // block
		&GameEngineFirefightPlayerGoalPropertiesBlock_block_struct, // block
		&GameEngineFirefightWavePropertiesBlock_block_struct, // block
		&flock_struct_definition_struct_definition, // tag group
		&fluid_dynamics_struct_definition_struct_definition, // tag group
		&fluid_dynamics_squirter_block_block_struct, // block
		&fluid_dynamics_inflow_block_block_struct, // block
		&fluid_dynamics_outflow_block_block_struct, // block
		&fluid_dynamics_obstacle_block_block_struct, // block
		&g_single_scalar_function_evaluation_struct_struct_definition,
		&atmosphere_definition_block_block_struct, // block
		&solo_fog_parameters_struct_definition_struct_definition,
		&soloFogFunctionBlock_block_struct, // block
		&fog_light_struct_definition_struct_definition,
		&VolumeFogParametersDefinition_struct_definition,
		&LightShaftParametersDefinition_struct_definition,
		&material_effects_block_struct, // block
		&material_effect_block_v2_block_struct, // block
		&old_material_effect_material_block_block_struct, // block
		&material_effect_material_block_block_struct, // block
		&forge_globals_block_struct, // block
		&forge_color_block_block_struct, // block
		&formation_block_struct, // block
		&formation_primitive_definition_block_struct, // block
		&formation_point_definition_block_struct, // block
		&frame_event_list_struct_definition_struct_definition, // tag group
		&animation_graph_sound_reference_block_block_struct, // block
		&animation_graph_effect_reference_block_block_struct, // block
		&import_animation_event_block_block_struct, // block
		&import_frame_event_block_block_struct, // block
		&animation_sound_event_block_extended_block_struct, // block
		&animation_effects_event_block_extended_block_struct, // block
		&animation_dialogue_event_block_extended_block_struct, // block
		&animation_script_event_block_extended_block_struct, // block
		&fx_test_struct_definition_struct_definition, // tag group
		&fx_property_block_block_struct, // block
		&fx_property_default_block_block_struct, // block
		&fx_test_scalar_function_struct_struct_definition,
		&game_completion_rewards_globals_struct_definition_struct_definition, // tag group
		&game_completion_rewards_difficulty_block_block_struct, // block
		&game_completion_rewards_definition_block_block_struct, // block
		&game_completion_rewards_falloff_point_block_block_struct, // block
		&game_completion_rewards_multiplayer_block_block_struct, // block
		&game_engine_globals_struct_definition_struct_definition, // tag group
		&game_engine_event_block_block_struct, // block
		&sound_response_definition_struct_struct_definition,
		&sound_response_definition_block_block_struct, // block
		&game_globals_grenade_list_struct_definition_struct_definition, // tag group
		&GameGlobalsGrenadeBlock_block_struct, // block
		&game_globals_ordnance_list_struct_definition_struct_definition, // tag group
		&GameGlobalsOrdnanceBlock_block_struct, // block
		&OrdnanceRemappingVariantBlock_block_struct, // block
		&OrdnanceRemappingBlock_block_struct, // block
		&giant_struct_definition_struct_definition, // tag group
		&giant_buckle_parameters_block_block_struct, // block
		&cheap_light_struct_definition_struct_definition, // tag group
		&light_color_function_struct_struct_definition,
		&light_scalar_function_struct_struct_definition,
		&global_pixel_shader_block_struct, // block
		&global_shader_entry_point_block_block_struct, // block
		&global_shader_category_dependency_block_struct, // block
		&global_shader_option_dependency_block_struct, // block
		&compiled_pixel_shader_block_block_struct, // block
		&rasterizer_compiled_shader_struct_struct_definition,
		&global_rasterizer_constant_table_struct_struct_definition,
		&rasterizer_constant_block_block_struct, // block
		&global_vertex_shader_block_struct, // block
		&global_vertex_shader_vertex_types_block_block_struct, // block
		&compiled_vertex_shader_block_block_struct, // block
		&game_medal_globals_struct_definition_struct_definition, // tag group
		&gameMedalTiers_block_struct, // block
		&game_medal_block_block_struct, // block
		&multiplayer_variant_settings_interface_definition_struct_definition_struct_definition, // tag group
		&variant_setting_edit_reference_block_block_struct, // block
		&variant_option_block_block_struct, // block
		&global_cache_file_pixel_shaders_struct_definition_struct_definition, // tag group
		&game_performance_throttle_struct_definition_struct_definition, // tag group
		&game_performance_throttle_entries_block_block_struct, // block
		&game_performance_throttle_filter_struct_struct_definition,
		&game_performance_throttle_profile_struct_struct_definition,
		&grounded_friction_struct_definition_struct_definition, // tag group
		&havok_collision_filter_struct_definition_struct_definition, // tag group
		&havok_collision_filter_group_block_block_struct, // block
		&havok_group_filter_filter_struct_struct_definition,
		&model_block_struct, // block
		&model_variant_block_block_struct, // block
		&runtime_region_index_array_struct_definition, // array
		&model_variant_region_block_block_struct, // block
		&model_variant_permutation_block_block_struct, // block
		&model_variant_state_block_block_struct, // block
		&model_state_permutation_index_array_struct_definition, // array
		&model_variant_object_block_block_struct, // block
		&model_variant_muted_node_block_block_struct, // block
		&g_node_flag_storage_array_struct_definition, // array
		&region_name_block_block_struct, // block
		&global_model_instance_group_block_block_struct, // block
		&model_instance_group_member_block_block_struct, // block
		&model_material_block_new_block_struct, // block
		&global_damage_info_block_block_struct, // block
		&damage_body_parameters_struct_struct_definition,
		&damage_shield_parameters_struct_struct_definition,
		&global_damage_section_block_block_struct, // block
		&instantaneous_damage_repsonse_block_block_struct, // block
		&instantaneous_response_damage_effect_struct_struct_definition,
		&instantaneous_response_damage_effect_marker_struct_struct_definition,
		&global_damage_nodes_block_block_struct, // block
		&damage_seat_info_block_block_struct, // block
		&damage_seat_region_setting_block_block_struct, // block
		&damage_constraint_info_block_block_struct, // block
		&model_damage_info_struct_struct_definition,
		&new_global_damage_section_block_block_struct, // block
		&damage_section_recharge_speed_curve_block_block_struct, // block
		&damage_section_segmented_recharge_fraction_block_struct, // block
		&new_instantaneous_damage_response_block_block_struct, // block
		&damage_response_region_transition_block_block_struct, // block
		&damage_transfer_block_block_struct, // block
		&seat_ejection_block_block_struct, // block
		&damage_section_rendering_paramters_block_struct, // block
		&model_target_block_old_block_struct, // block
		&model_target_lock_on_data_struct_struct_definition,
		&model_target_block_new_block_struct, // block
		&model_region_block_block_struct, // block
		&model_permutation_block_block_struct, // block
		&model_node_block_block_struct, // block
		&global_scenario_load_parameters_block_block_struct, // block
		&model_game_mode_render_model_override_block_struct, // block
		&model_self_shadow_region_cast_override_block_block_struct, // block
		&model_self_shadow_region_receive_override_block_block_struct, // block
		&model_occlusion_sphere_block_block_struct, // block
		&hlsl_include_struct_definition_struct_definition, // tag group
		&hs_source_files_block_block_struct, // block
		&script_container_struct_definition_struct_definition, // tag group
		&script_struct_definition_struct_definition, // tag group
		&hs_scripts_block_block_struct, // block
		&hs_script_parameters_block_block_struct, // block
		&hs_globals_block_block_struct, // block
		&HSInstancedVariablesBlock_block_struct, // block
		&hs_unit_seat_block_block_struct, // block
		&hs_syntax_datum_block_block_struct, // block
		&HSImportManifestBlock_block_struct, // block
		&HSImportManifestEntryBlock_block_struct, // block
		&incident_global_properties_definition_struct_definition_struct_definition, // tag group
		&incident_definition_block_block_struct, // block
		&suppressed_incident_block_block_struct, // block
		&SuppressedIncidentBlockReferenceDefinition_block_struct, // block
		&specialized_incident_block_block_struct, // block
		&specialized_incident_kill_implement_block_block_struct, // block
		&specialized_incident_object_properties_block_block_struct, // block
		&specialized_incident_object_riding_in_vehicle_properties_block_block_struct, // block
		&specialized_incident_special_kill_type_block_block_struct, // block
		&specializedIncidentGameOverBlock_block_struct, // block
		&specializedIncidentRandomOrdnanceBlock_block_struct, // block
		&specializedIncidentCustomDataFilterBlock_block_struct, // block
		&specializedIncidentDistanceFilterBlock_block_struct, // block
		&incident_accumulator_block_block_struct, // block
		&incident_accumulator_child_incident_block_block_struct, // block
		&incident_sum_accumulator_block_block_struct, // block
		&incident_sum_accumulator_child_incident_block_block_struct, // block
		&game_incident_response_block_block_struct, // block
		&game_incident_daily_challenge_to_increment_block_block_struct, // block
		&specialized_incident_fanfare_block_block_struct, // block
		&instance_imposter_definition_struct_definition_struct_definition, // tag group
		&instance_imposter_block_block_struct, // block
		&instance_imposter_checksum_block_block_struct, // block
		&imposter_model_struct_definition_struct_definition, // tag group
		&imposter_mode_node_block_block_struct, // block
		&render_model_region_block_block_struct, // block
		&render_model_permutation_block_block_struct, // block
		&incident_globals_definition_block_struct, // block
		&InfinityUIImages_struct_definition_struct_definition, // tag group
		&InfinityMissionSeasonImagesDefinition_block_struct, // block
		&InfinityMissionImagesDefinition_block_struct, // block
		&model_animation_graph_block_struct, // block
		&animation_graph_definitions_struct_struct_definition,
		&animation_usage_block_block_struct, // block
		&animation_node_mask_block_block_struct, // block
		&animation_node_mask_entry_block_block_struct, // block
		&animation_function_block_block_struct, // block
		&model_animation_variant_block_block_struct, // block
		&mode_or_stance_alias_block_block_struct, // block
		&animation_graph_node_block_block_struct, // block
		&animation_blend_screen_block_block_struct, // block
		&animation_aiming_screen_struct_struct_definition,
		&foot_tracking_member_block_block_struct, // block
		&animation_pool_block_block_struct, // block
		&shared_animation_reference_block_struct_definition,
		&shared_model_animation_block_block_struct, // block
		&animation_frame_event_block_block_struct, // block
		&animation_sound_event_block_block_struct, // block
		&animation_effect_event_block_block_struct, // block
		&animation_dialogue_event_block_block_struct, // block
		&animation_script_event_block_block_struct, // block
		&object_space_node_data_block_block_struct, // block
		&quantized_orientation_struct_struct_definition,
		&foot_tracking_block_block_struct, // block
		&foot_lock_cycle_block_block_struct, // block
		&object_space_offset_node_block_block_struct, // block
		&fik_anchor_node_block_block_struct, // block
		&animation_ik_chain_events_struct_struct_definition,
		&animation_ik_chain_proxies_struct_struct_definition,
		&animation_facial_wrinkle_events_struct_struct_definition,
		&animation_extended_events_struct_struct_definition,
		&animation_object_functions_struct_struct_definition,
		&new_animation_blend_screen_block_block_struct, // block
		&animation_index_struct_struct_definition,
		&new_animation_function_overlay_block_block_struct, // block
		&overlay_group_definition_block_block_struct, // block
		&blend_screen_item_definition_block_block_struct, // block
		&function_overlay_item_definition_block_block_struct, // block
		&animation_gait_block_block_struct, // block
		&animation_gait_group_block_block_struct, // block
		&animation_gait_item_block_block_struct, // block
		&animation_ik_block_block_struct, // block
		&animation_ik_set_block_struct, // block
		&animation_ik_set_item_block_struct, // block
		&animation_ik_chain_block_block_struct, // block
		&g_compositeTag_struct_struct_definition,
		&CompositeAxisDefinition_block_struct, // block
		&CompositeDeadZoneDefinition_block_struct, // block
		&CompositeEntryDefinition_block_struct, // block
		&CompositeEntryValueDefinition_block_struct, // block
		&CompositePhaseSetDefinition_block_struct, // block
		&SyncKeyBlock_block_struct, // block
		&StringBlock_block_struct, // block
		&PCAAnimationDataStruct_struct_definition,
		&PCAGroupSettingsBlock_block_struct, // block
		&animation_graph_contents_struct_struct_definition,
		&animation_mode_block_block_struct, // block
		&weapon_class_block_block_struct, // block
		&weapon_type_block_block_struct, // block
		&animation_set_block_block_struct, // block
		&animation_entry_block_block_struct, // block
		&damage_animation_block_block_struct, // block
		&damage_direction_block_block_struct, // block
		&damage_region_block_block_struct, // block
		&animation_transition_source_block_block_struct, // block
		&animation_transition_destination_block_block_struct, // block
		&animation_velocity_boundaries_block_block_struct, // block
		&animation_velocity_boundaries_struct_definition, // array
		&animation_ik_block_v1_block_struct, // block
		&animation_ranged_action_block_block_struct, // block
		&ranged_animation_entry_block_block_struct, // block
		&triangulation_entry_block_block_struct, // block
		&triangulation_point_block_block_struct, // block
		&triangulation_triangle_block_block_struct, // block
		&animation_sync_action_group_block_block_struct, // block
		&animation_sync_action_block_block_struct, // block
		&animation_sync_action_same_type_participant_block_struct, // block
		&animation_sync_action_other_type_participant_block_struct, // block
		&foot_tracking_defaults_block_struct, // block
		&vehicle_suspension_block_block_struct, // block
		&function_overlay_animation_block_block_struct, // block
		&model_animation_runtime_data_struct_struct_definition,
		&inherited_animation_block_block_struct, // block
		&inherited_animation_node_map_block_block_struct, // block
		&inherited_animation_node_map_flag_block_block_struct, // block
		&weapon_class_lookup_block_block_struct, // block
		&additional_node_data_block_block_struct, // block
		&model_animation_tag_resource_group_block_struct, // block
		&animation_codec_data_struct_struct_definition,
		&shared_static_data_codec_graph_data_struct_struct_definition,
		&shared_static_data_codec_rotation_block_block_struct, // block
		&shared_static_data_codec_translation_block_block_struct, // block
		&shared_static_data_codec_scale_block_block_struct, // block
		&sandbox_text_value_pair_definition_struct_definition_struct_definition, // tag group
		&sandbox_property_allowed_values_reference_block_block_struct, // block
		&text_value_pair_reference_block_block_struct, // block
		&damage_effect_group_struct_definition, // tag group
		&damage_outer_cone_angle_struct_struct_definition,
		&custom_damage_response_label_block_block_struct, // block
		&damage_effect_sound_block_block_struct, // block
		&KillCamCameraParamter_struct_definition_struct_definition, // tag group
		&loadScreenBlock_block_struct, // block
		&vertexBlock_block_struct, // block
		&lens_flare_struct_definition_struct_definition, // tag group
		&lens_flare_reflection_block_block_struct, // block
		&color_function_named_struct_struct_definition,
		&lens_flare_scalar_animation_block_block_struct, // block
		&lens_flare_color_animation_block_block_struct, // block
		&lens_flare_color_function_struct_struct_definition,
		&loadout_globals_definition_struct_definition_struct_definition, // tag group
		&loadout_definition_struct_struct_definition,
		&loadout_palette_definition_block_block_struct, // block
		&loadout_index_block_block_struct, // block
		&loadout_name_block_block_struct, // block
		&light_cone_struct_definition_struct_definition, // tag group
		&light_struct_definition_struct_definition, // tag group
		&midnight_light_struct_struct_definition,
		&location_name_globals_definition_struct_definition_struct_definition, // tag group
		&location_name_block_block_struct, // block
		&light_rig_struct_definition_struct_definition, // tag group
		&directionalLightRigBlock_block_struct, // block
		&sound_looping_struct_definition_struct_definition, // tag group
		&looping_sound_track_block_block_struct, // block
		&looping_sound_detail_block_block_struct, // block
		&leaf_system_struct_definition_struct_definition, // tag group
		&leaf_type_block_block_struct, // block
		&light_volume_system_struct_definition_struct_definition, // tag group
		&light_volume_definition_block_block_struct, // block
		&light_volume_property_real_struct_definition,
		&light_volume_property_real_rgb_color_struct_definition,
		&light_volume_precompiled_vert_block_block_struct, // block
		&device_machine_struct_definition_struct_definition, // tag group
		&material_block_struct, // block
		&globals_struct_definition_struct_definition, // tag group
		&havok_cleanup_resources_block_block_struct, // block
		&sound_globals_block_block_struct, // block
		&StreamingPackBlock_block_struct, // block
		&campaign_unspatialized_sounds_block_block_struct, // block
		&game_globals_damage_block_block_struct, // block
		&damage_group_block_block_struct, // block
		&armor_modifier_block_block_struct, // block
		&sound_block_block_struct, // block
		&camera_block_block_struct, // block
		&controller_input_block_block_struct, // block
		&player_control_block_block_struct, // block
		&controller_mapping_reference_block_block_struct, // block
		&difficulty_block_block_struct, // block
		&coop_difficulty_block_block_struct, // block
		&soft_ceiling_globals_block_block_struct, // block
		&interface_tag_references_block_struct, // block
		&cheat_weapons_block_block_struct, // block
		&cheat_powerups_block_block_struct, // block
		&player_information_block_block_struct, // block
		&player_momentum_data_block_block_struct, // block
		&player_representation_block_block_struct, // block
		&firstPersonpHiddenBodyRegionsBlock_block_struct, // block
		&damage_globals_block_block_struct, // block
		&damage_decay_struct_struct_definition,
		&shield_boost_block_block_struct, // block
		&materials_block_block_struct, // block
		&wet_proxies_struct_struct_definition,
		&material_physics_properties_struct_struct_definition,
		&object_type_drag_properties_block_block_struct, // block
		&materials_sweeteners_struct_struct_definition,
		&underwater_proxies_block_block_struct, // block
		&multiplayer_color_block_block_struct, // block
		&visor_color_block_block_struct, // block
		&elite_specular_color_struct_struct_definition,
		&cinematics_globals_block_block_struct, // block
		&cinematic_characters_block_block_struct, // block
		&campaign_metagame_globals_block_block_struct, // block
		&campaign_metagame_style_type_block_block_struct, // block
		&campaign_metagame_difficulty_scale_block_block_struct, // block
		&campaign_metagame_skull_block_block_struct, // block
		&language_pack_definition_struct_definition,
		&data_hash_definition_struct_definition, // array
		&active_camo_globals_block_block_struct, // block
		&active_camo_level_definition_block_block_struct, // block
		&garbage_collection_block_block_struct, // block
		&global_camera_impulse_block_block_struct, // block
		&runtime_materials_block_block_struct, // block
		&hologramLightingGlobalsBlock_block_struct, // block
		&hologramLightFunctions_struct_definition,
		&material_shader_block_struct, // block
		&material_shader_source_file_block_block_struct, // block
		&compiled_effects_block_block_struct, // block
		&material_vertex_shader_entry_point_block_block_struct, // block
		&compiled_vertex_shader_refererence_block_block_struct, // block
		&compiled_pixel_shader_refererence_block_block_struct, // block
		&ai_mission_dialogue_struct_definition_struct_definition, // tag group
		&mission_dialogue_lines_block_block_struct, // block
		&mission_dialogue_variants_block_block_struct, // block
		&model_dissolve_definition_struct_definition_struct_definition, // tag group
		&modelDissolvePerRegionTimeOffsetBlock_block_struct, // block
		&medal_challenge_aggregator_list_struct_definition_struct_definition, // tag group
		&medalChallengeAggregator_block_struct, // block
		&medalAggregator_struct_definition,
		&medalAggregatorEntry_block_struct, // block
		&medal_commendation_aggregator_list_struct_definition_struct_definition, // tag group
		&medalCommendationAggregator_block_struct, // block
		&meter_struct_definition_struct_definition, // tag group
		&muffin_block_struct, // block
		&muffin_permutation_name_block_block_struct, // block
		&muffin_marker_block_block_struct, // block
		&global_muffin_type_struct_struct_definition,
		&muffin_scalar_function_struct_struct_definition,
		&multiplayerEffects_struct_definition_struct_definition, // tag group
		&multiplayerEffectsBlock_block_struct, // block
		&megalogamengine_sounds_struct_definition_struct_definition, // tag group
		&emblem_library_struct_definition_struct_definition, // tag group
		&emblem_bitmap_list_block_struct, // block
		&emblem_shape_list_block_struct, // block
		&emblem_transform_struct_definition,
		&emblem_front_list_block_struct, // block
		&emblem_layer_struct_definition,
		&emblem_back_list_block_struct, // block
		&emblem_runtime_front_list_block_struct, // block
		&emblem_runtime_back_list_block_struct, // block
		&main_menu_voiceover_struct_definition_struct_definition, // tag group
		&main_menu_voiceover_lines_block_block_struct, // block
		&render_model_block_struct, // block
		&global_render_model_instance_placement_block_block_struct, // block
		&render_model_node_block_block_struct, // block
		&render_model_marker_group_block_block_struct, // block
		&render_model_marker_block_block_struct, // block
		&global_geometry_material_block_block_struct, // block
		&instance_node_map_mapping_block_block_struct, // block
		&volume_samples_block_block_struct, // block
		&radiance_transfer_matrix_struct_definition, // array
		&default_node_orientations_block_block_struct, // block
		&RenderModelBoneGroupBlock_block_struct, // block
		&RenderModelNodeIndexBlock_block_struct, // block
		&multiplayer_object_type_list_struct_definition_struct_definition, // tag group
		&multiplayer_object_type_block_block_struct, // block
		&multiplayer_object_collection_struct_struct_definition,
		&multiplayer_weapon_remap_table_block_block_struct, // block
		&multiplayer_weapon_remap_table_entry_block_block_struct, // block
		&multiplayer_vehicle_remap_table_block_block_struct, // block
		&multiplayer_vehicle_remap_table_entry_block_block_struct, // block
		&multiplayer_equipment_remap_table_block_block_struct, // block
		&multiplayer_equipment_remap_table_entry_block_block_struct, // block
		&multiplayer_scenario_description_struct_definition_struct_definition, // tag group
		&scenario_description_block_block_struct, // block
		&megalo_string_id_table_struct_definition_struct_definition, // tag group
		&megalo_string_id_block_block_struct, // block
		&megalo_string_id_to_sprite_index_block_block_struct, // block
		&material_shader_bank_block_struct, // block
		&compiled_shader_hash_block_block_struct, // block
		&vertexShaderUniqueBindingInfoBlock_block_struct, // block
		&multiplayer_globals_struct_definition_struct_definition, // tag group
		&multiplayer_universal_block_block_struct, // block
		&teamDefinitionBlock_block_struct, // block
		&global_team_role_block_block_struct, // block
		&player_role_block_block_struct, // block
		&requisition_constants_block_block_struct, // block
		&requisition_palette_block_block_struct, // block
		&scenario_profiles_block_block_struct, // block
		&multiplayer_runtime_block_block_struct, // block
		&sounds_block_block_struct, // block
		&looping_sounds_block_block_struct, // block
		&multiplayer_constants_block_block_struct, // block
		&game_engine_status_response_block_block_struct, // block
		&mux_generator_struct_definition_struct_definition, // tag group
		&mux_generator_material_block_block_struct, // block
		&NarrativeGlobals_struct_definition_struct_definition, // tag group
		&NarrativeFlagDefinitionBlock_block_struct, // block
		&new_cinematic_lighting_struct_definition_struct_definition, // tag group
		&hologramLightingBlock_struct_struct_definition,
		&hologramLight_struct_definition,
		&cinematic_dynamic_light_block_block_struct, // block
		&polyart_asset_block_struct, // block
		&polyartCameraBlock_block_struct, // block
		&polyartVertexBlock_block_struct, // block
		&polyartIndexBlock_block_struct, // block
		&vertexBuffersBlock_struct_struct_definition,
		&indexBuffersBlock_struct_struct_definition,
		&tag_package_manifest_block_struct, // block
		&tag_patch_block_block_struct, // block
		&patch_globals_struct_definition_struct_definition, // tag group
		&pca_animation_block_struct, // block
		&PCAImportedFrameDatablock_block_struct, // block
		&PCAImportedMeshDataBlock_block_struct, // block
		&PCAImportedAnimationDataBlock_block_struct, // block
		&pgcr_enemy_to_category_mapping_definition_struct_definition_struct_definition, // tag group
		&pgcr_enemy_to_category_list_block_block_struct, // block
		&pgcr_player_to_category_entry_block_block_struct, // block
		&pgcr_enemy_to_category_entry_block_block_struct, // block
		&pgcr_damage_type_image_mapping_definition_struct_definition_struct_definition, // tag group
		&pgcr_damage_type_image_block_block_struct, // block
		&particle_emitter_custom_points_struct_definition_struct_definition, // tag group
		&particle_emitter_custom_point_block_block_struct, // block
		&player_enlistment_globals_definition_struct_definition_struct_definition, // tag group
		&playerEnlistmentDefinitionBlock_block_struct, // block
		&player_grade_definition_block_block_struct, // block
		&performance_throttles_struct_definition_struct_definition, // tag group
		&performane_throttle_block_block_struct, // block
		&performance_template_block_struct, // block
		&performance_template_actor_block_block_struct, // block
		&scenario_performance_line_block_block_struct, // block
		&scenario_performance_line_script_fragment_block_block_struct, // block
		&scenario_performance_line_point_interaction_block_block_struct, // block
		&scenario_performance_line_animation_block_block_struct, // block
		&scenario_performance_line_sync_action_block_block_struct, // block
		&scenario_performance_line_sync_action_actor_block_block_struct, // block
		&scenario_performance_line_scenery_sync_action_block_block_struct, // block
		&scenario_performance_line_dialog_block_block_struct, // block
		&scenario_performance_line_sound_block_block_struct, // block
		&performance_template_point_block_block_struct, // block
		&pathfinding_block_struct, // block
		&pathfinding_data_block_block_struct, // block
		&FaceUserDataBlock_block_struct, // block
		&MobileNavMeshBlock_block_struct, // block
		&scenario_object_id_struct_struct_definition,
		&NavVolumeBlock_block_struct, // block
		&NavClimbBlock_block_struct, // block
		&user_edge_block_block_struct, // block
		&user_hint_block_block_struct, // block
		&user_hint_line_segment_block_block_struct, // block
		&user_hint_parallelogram_block_block_struct, // block
		&user_hint_jump_block_block_struct, // block
		&hint_vertex_block_block_struct, // block
		&user_hint_climb_block_block_struct, // block
		&user_hint_well_block_block_struct, // block
		&user_hint_well_point_block_block_struct, // block
		&user_hint_flight_block_block_struct, // block
		&user_hint_flight_point_block_block_struct, // block
		&user_hint_volume_avoidance_struct_struct_definition,
		&user_hint_spline_block_block_struct, // block
		&user_hint_spline_control_point_block_block_struct, // block
		&user_hint_spline_intersect_point_block_block_struct, // block
		&user_hint_cookie_cutter_block_block_struct, // block
		&user_hint_sector_point_block_block_struct, // block
		&hint_object_id_block_block_struct, // block
		&user_hint_navmesh_area_block_block_struct, // block
		&user_hint_giant_block_block_struct, // block
		&user_hint_giant_sector_block_block_struct, // block
		&user_hint_giant_rail_block_block_struct, // block
		&user_hint_flood_block_block_struct, // block
		&user_hint_flood_sector_block_block_struct, // block
		&planar_fog_parameters_struct_definition_struct_definition, // tag group
		&player_grade_globals_definition_struct_definition_struct_definition, // tag group
		&physics_model_struct_definition_struct_definition, // tag group
		&physics_model_damped_spring_motor_block_block_struct, // block
		&physics_model_position_motor_block_block_struct, // block
		&phantom_types_block_block_struct, // block
		&physics_model_powered_chains_block_block_struct, // block
		&physics_model_powered_chain_nodes_block_block_struct, // block
		&physics_model_powered_chain_constraints_block_block_struct, // block
		&physics_model_motor_reference_struct_struct_definition,
		&physics_model_node_constraint_edge_block_block_struct, // block
		&physics_model_constraint_edge_constraint_block_block_struct, // block
		&physics_model_ragdoll_motors_block_block_struct, // block
		&physics_model_limited_hinge_motors_block_block_struct, // block
		&rigid_bodies_block_block_struct, // block
		&materials_block$3_block_struct, // block
		&multi_spheres_block_block_struct, // block
		&multi_sphere_vector_storage_struct_definition, // array
		&boxes_block_block_struct, // block
		&havok_convex_transform_shape_struct_struct_definition,
		&triangles_block_block_struct, // block
		&havok_convex_shape_struct_2010_2_struct_definition,
		&polyhedra_block_block_struct, // block
		&polyhedron_four_vectors_block_block_struct, // block
		&polyhedron_plane_equations_block_block_struct, // block
		&mass_distributions_block_block_struct, // block
		&mopps_block_block_struct, // block
		&hinge_constraints_block_block_struct, // block
		&constraint_bodies_struct_struct_definition,
		&ragdoll_constraints_block_block_struct, // block
		&regions_block_block_struct, // block
		&permutations_block_block_struct, // block
		&rigid_body_indices_block_block_struct, // block
		&nodes_block_block_struct, // block
		&point_to_path_curve_block_block_struct, // block
		&point_to_path_curve_point_block_block_struct, // block
		&limited_hinge_constraints_block_block_struct, // block
		&ball_and_socket_constraints_block_block_struct, // block
		&stiff_spring_constraints_block_block_struct, // block
		&prismatic_constraints_block_block_struct, // block
		&phantoms_block_block_struct, // block
		&RigidBodySerializedShapesBlock_block_struct, // block
		&MoppSerializedHavokDataBlock_block_struct, // block
		&pixel_shader_block_struct, // block
		&pixel_entry_point_block_block_struct, // block
		&cache_file_resource_layout_table_block_struct, // block
		&cache_file_codec_identifier_block_block_struct, // block
		&cache_file_shared_file_block_block_struct, // block
		&cache_file_resource_page_struct_struct_definition,
		&resource_checksum_struct_struct_definition,
		&resource_hash_definition_struct_definition, // array
		&cache_file_resource_streaming_subpage_table_block_block_struct, // block
		&cache_file_resource_streaming_subpage_block_block_struct, // block
		&cache_file_resource_section_block_block_struct, // block
		&location_offsets_array_definition_struct_definition, // array
		&file_location_indexes_array_definition_struct_definition, // array
		&sublocation_table_indexes_array_definition_struct_definition, // array
		&particleman_struct_definition_struct_definition, // tag group
		&particleize_scalar_function_struct_struct_definition,
		&player_model_customization_globals_struct_definition_struct_definition, // tag group
		&customized_model_selection_block_block_struct, // block
		&customized_model_player_bits_block_block_struct, // block
		&particle_model_struct_definition_struct_definition, // tag group
		&gpu_data_struct_struct_definition,
		&gpu_variants_block_block_struct, // block
		&gpu_single_constant_register_array_struct_definition, // array
		&particle_physics_struct_definition_struct_definition, // tag group
		&point_physics_struct_definition_struct_definition, // tag group
		&portrait_poses_definition_struct_definition_struct_definition, // tag group
		&gui_portrait_pose_block_block_struct, // block
		&prefab_struct_definition_struct_definition, // tag group
		&progressionGlobalsBlock_block_struct, // block
		&projectile_group_struct_definition, // tag group
		&super_detonation_damage_struct_struct_definition,
		&angular_velocity_lower_bound_struct_struct_definition,
		&old_projectile_material_response_block_block_struct, // block
		&projectile_material_response_block_block_struct, // block
		&brute_grenade_block_block_struct, // block
		&fire_bomb_grenade_block_block_struct, // block
		&conical_projection_block_block_struct, // block
		&ProjectileSoundRTPCBlock_block_struct, // block
		&particle_struct_definition_struct_definition, // tag group
		&attachment_block_block_struct, // block
		&gpu_data_struct$2_struct_definition,
		&gpu_sprite_block_block_struct, // block
		&rain_definition_struct_definition_struct_definition, // tag group
		&rasterizer_globals_struct_definition_struct_definition, // tag group
		&default_textures_refs_block_block_struct, // block
		&material_textures_refs_block_block_struct, // block
		&explicit_shader_refs_block_block_struct, // block
		&rumble_struct_definition_struct_definition, // tag group
		&rumble_definition_struct_struct_definition,
		&rumble_frequency_definition_struct_struct_definition,
		&shader_custom_struct_definition_struct_definition, // tag group
		&shader_cortana_struct_definition_struct_definition, // tag group
		&shader_decal_struct_definition_struct_definition, // tag group
		&render_method_definition_struct_definition_struct_definition, // tag group
		&render_method_category_block_block_struct, // block
		&render_method_options_block_block_struct, // block
		&render_method_entry_points_block_block_struct, // block
		&render_method_pass_block_block_struct, // block
		&render_method_pass_category_dependencies_block_struct, // block
		&vertex_types_block_block_struct, // block
		&shader_foliage_struct_definition_struct_definition, // tag group
		&shader_fur_stencil_struct_definition_struct_definition, // tag group
		&shader_fur_struct_definition_struct_definition, // tag group
		&shader_glass_struct_definition_struct_definition, // tag group
		&shader_halogram_struct_definition_struct_definition, // tag group
		&render_model_lightmap_atlas_struct_definition_struct_definition, // tag group
		&shader_light_volume_struct_definition_struct_definition, // tag group
		&shader_mux_material_struct_definition_struct_definition, // tag group
		&shader_mux_struct_definition_struct_definition, // tag group
		&render_method_option_struct_definition_struct_definition, // tag group
		&render_method_option_parameter_block_block_struct, // block
		&shader_struct_definition_struct_definition, // tag group
		&shader_skin_struct_definition_struct_definition, // tag group
		&shader_screen_struct_definition_struct_definition, // tag group
		&render_method_template_struct_definition_struct_definition, // tag group
		&render_method_template_pass_block_block_struct, // block
		&render_method_template_constant_table_block_block_struct, // block
		&render_method_template_platform_block_block_struct, // block
		&shader_terrain_struct_definition_struct_definition, // tag group
		&shader_water_struct_definition_struct_definition, // tag group
		&shader_waterfall_struct_definition_struct_definition, // tag group
		&render_water_ripple_struct_definition_struct_definition, // tag group
		&scenario_lightmap_block_struct, // block
		&scenario_lightmap_bsp_data_reference_block_block_struct, // block
		&spring_acceleration_struct_definition_struct_definition, // tag group
		&spring_linear_acceleration_block_block_struct, // block
		&soundbank_block_struct, // block
		&SoundBankBlock_block_struct, // block
		&scenario_structure_bsp_block_struct, // block
		&structure_manifest_build_identifier_struct_struct_definition,
		&structure_seam_mapping_block_block_struct, // block
		&structure_seam_identifier_struct_struct_definition,
		&structure_seam_edge_mapping_block_block_struct, // block
		&structure_seam_cluster_mapping_block_block_struct, // block
		&structure_edge_to_seam_edge_mapping_block_block_struct, // block
		&structure_collision_materials_block_block_struct, // block
		&structure_bsp_leaf_block_block_struct, // block
		&structure_super_node_aabbs_block_block_struct, // block
		&super_node_mappings_block_block_struct, // block
		&super_node_recursable_masks_block_block_struct, // block
		&structure_super_node_traversal_geometry_block_block_struct, // block
		&structure_super_node_traversal_geometry_indices_block_block_struct, // block
		&collision_kd_hierarchy_static_struct_struct_definition,
		&collision_kd_hierarchy_static_hash_table_data_block_block_struct, // block
		&collision_kd_hierarchy_static_hash_table_short_block_block_struct, // block
		&collision_kd_hierarchy_static_nodes_block_block_struct, // block
		&collision_kd_hierarchy_static_hash_table_headers_block_block_struct, // block
		&collision_kd_hierarchy_static_in_use_masks_block_block_struct, // block
		&cluster_table_block_block_struct, // block
		&super_node_mappings_block$3_block_struct, // block
		&super_node_mapping_index_array_struct_definition, // array
		&structure_surface_block_block_struct, // block
		&structure_surface_to_triangle_mapping_block_block_struct, // block
		&structure_bsp_cluster_portal_block_block_struct, // block
		&structure_bsp_cluster_portal_oriented_bounds_block_struct_definition,
		&structure_bsp_cluster_portal_vertex_block_block_struct, // block
		&structure_bsp_detail_object_data_block_block_struct, // block
		&global_detail_object_cells_block_block_struct, // block
		&global_detail_object_block_block_struct, // block
		&global_detail_object_counts_block_block_struct, // block
		&global_z_reference_vector_block_block_struct, // block
		&structure_bsp_cluster_block_block_struct, // block
		&structure_bsp_cluster_portal_index_block_block_struct, // block
		&seam_indices_block_definition_block_struct, // block
		&decorator_runtime_cluster_block_block_struct, // block
		&cheap_light_marker_ref_block_block_struct, // block
		&pvs_bound_object_identifiers_block_block_struct, // block
		&pvs_bound_object_references_block_block_struct, // block
		&scenario_object_reference_struct_struct_definition,
		&structure_cluster_cubemap_block_struct, // block
		&cubemap_reference_points_block_block_struct, // block
		&structure_material_lighting_info_block_block_struct, // block
		&structure_bsp_sky_owner_cluster_block_block_struct, // block
		&structure_bsp_conveyor_surface_block_block_struct, // block
		&breakable_surface_set_block_block_struct, // block
		&supported_bitfield_struct_definition, // array
		&structure_cookie_cutter_definition_block_struct, // block
		&scenario_acoustics_palette_block_definition_struct_struct_definition,
		&scenario_acoustics_environment_definition_struct_definition,
		&scenario_acoustics_ambience_definition_struct_definition,
		&structure_bsp_marker_block_block_struct, // block
		&structure_bsp_marker_light_palette_block_struct, // block
		&structure_bsp_marker_light_index_block_struct, // block
		&structure_bsp_runtime_decal_block_block_struct, // block
		&manualBspFlagsReferences_struct_definition,
		&scenarioBspReferenceBlock_block_struct, // block
		&structure_bsp_environment_object_palette_block_block_struct, // block
		&structure_bsp_environment_object_block_block_struct, // block
		&global_map_leaf_block_block_struct, // block
		&map_leaf_face_block_block_struct, // block
		&map_leaf_face_vertex_block_block_struct, // block
		&map_leaf_connection_index_block_block_struct, // block
		&global_leaf_connection_block_block_struct, // block
		&leaf_connection_vertex_block_block_struct, // block
		&structure_instance_cluster_definition_block_struct, // block
		&index_list_block_block_struct, // block
		&structure_instance_group_definition_block_struct, // block
		&structure_bsp_instanced_geometry_instances_block_block_struct, // block
		&structure_bsp_instanced_geometry_instances_names_block_block_struct, // block
		&structure_instance_imposter_info_block_block_struct, // block
		&runtime_decorator_set_block_block_struct, // block
		&bsp_preplaced_decal_set_reference_block_block_struct, // block
		&bsp_preplaced_decal_reference_block_block_struct, // block
		&structure_bsp_sound_cluster_block_block_struct, // block
		&structure_sound_cluster_portal_designators_block_struct, // block
		&structure_sound_cluster_interior_cluster_indices_block_struct, // block
		&transparent_planes_block_block_struct, // block
		&structure_bsp_debug_info_block_block_struct, // block
		&structure_bsp_cluster_debug_info_block_block_struct, // block
		&structure_bsp_debug_info_render_line_block_block_struct, // block
		&structure_bsp_debug_info_indices_block_block_struct, // block
		&structure_bsp_fog_plane_debug_info_block_block_struct, // block
		&structure_bsp_fog_zone_debug_info_block_block_struct, // block
		&global_structure_physics_struct_struct_definition,
		&breakable_surface_key_table_block_block_struct, // block
		&widget_reference_block_block_struct, // block
		&cheap_light_reference_block_block_struct, // block
		&structure_bsp_resource_interface_struct_definition,
		&structure_bsp_raw_resources_block_struct, // block
		&structure_bsp_resource_struct_struct_definition,
		&global_collision_bsp_block_block_struct, // block
		&global_large_collision_bsp_block_block_struct, // block
		&large_bsp3d_nodes_block_block_struct, // block
		&large_leaves_block_block_struct, // block
		&large_bsp2d_references_block_block_struct, // block
		&large_bsp2d_nodes_block_block_struct, // block
		&large_surfaces_block_block_struct, // block
		&large_edges_block_block_struct, // block
		&large_vertices_block_block_struct, // block
		&structure_bsp_instanced_geometry_definition_block_block_struct, // block
		&structureIOHavokDataBlock_struct_struct_definition,
		&SerializedHavokGeometryDataBlock_struct_struct_definition,
		&structure_external_instanced_geometry_references_block_block_struct, // block
		&structure_bsp_obb_volume_block_block_struct, // block
		&AnimGraphDependencyBlock_block_struct, // block
		&scenery_group_struct_definition, // tag group
		&sound_combiner_block_struct, // block
		&sound_combiner_definition_entry_block_block_struct, // block
		&scenario_struct_definition_struct_definition, // tag group
		&scenario_child_references_block_block_struct, // block
		&scenario_structure_bsp_reference_block_block_struct, // block
		&scenarioVolumetricLightShaftSettingsStruct_struct_definition,
		&scenarioFloatingShadowSettingsStruct_struct_definition,
		&scenarioFloatingShadowCascadeSettingsArray_struct_definition, // array
		&scenario_lightmap_setting_struct_struct_definition,
		&scenario_design_reference_block_block_struct, // block
		&scenario_sky_reference_block_block_struct, // block
		&scenario_zone_set_pvs_block_block_struct, // block
		&scenario_zone_set_bsp_checksum_block_block_struct, // block
		&scenario_zone_set_bsp_pvs_block_block_struct, // block
		&scenario_zone_set_cluster_pvs_block_block_struct, // block
		&scenario_zone_set_bsp_bits_block_block_struct, // block
		&scenario_zone_set_cluster_pvs_bit_vector_block_block_struct, // block
		&scenario_zone_set_bsp_seam_cluster_mappings_block_block_struct, // block
		&scenario_zone_set_cluster_reference_block_block_struct, // block
		&structure_portal_device_mapping_block_block_struct, // block
		&structure_device_portal_association_block_block_struct, // block
		&game_portal_to_portal_mapping_block_block_struct, // block
		&occluding_portal_to_portal_mapping_block_block_struct, // block
		&game_audibility_block_block_struct, // block
		&door_encoded_pas_block_block_struct, // block
		&room_door_portal_encoded_pas_block_block_struct, // block
		&ai_deafening_encoded_pas_block_block_struct, // block
		&encoded_room_distances_block_block_struct, // block
		&game_portal_to_door_occluder_block_block_struct, // block
		&bsp_cluster_to_room_bounds_block_struct, // block
		&bsp_cluster_to_room_indices_block_struct, // block
		&scenario_zone_set_block_block_struct, // block
		&planar_fog_zone_set_visibility_definition_block_block_struct, // block
		&planar_fog_structure_visibility_definition_block_block_struct, // block
		&planar_fog_cluster_visibility_definition_block_block_struct, // block
		&planar_fog_reference_definition_block_block_struct, // block
		&scenario_zone_set_budget_override_block_block_struct, // block
		&scenario_zone_set_lipsync_block_block_struct, // block
		&scenario_lighting_zone_set_block_block_struct, // block
		&scenario_function_block_block_struct, // block
		&editor_comment_block_block_struct, // block
		&dont_use_me_scenario_environment_object_block_block_struct, // block
		&scenario_object_names_block_block_struct, // block
		&scenario_scenery_block_block_struct, // block
		&scenario_object_datum_struct_struct_definition,
		&scenario_object_node_orientations_block_block_struct, // block
		&scenario_object_node_orientations_bit_vector_block_block_struct, // block
		&scenario_object_node_orientations_orientations_block_block_struct, // block
		&scriptListBlock_block_struct, // block
		&scenario_object_parent_struct_struct_definition,
		&commandLinkBlock_block_struct, // block
		&scenario_object_permutation_struct_struct_definition,
		&scenario_scenery_datum_struct_v4_struct_definition,
		&pathfinding_object_index_list_block_block_struct, // block
		&scenario_multiplayer_object_struct_struct_definition,
		&scenario_scenery_palette_block_block_struct, // block
		&scenario_biped_block_block_struct, // block
		&scenario_unit_struct_struct_definition,
		&scenario_biped_palette_block_block_struct, // block
		&scenario_vehicle_block_block_struct, // block
		&scenario_vehicle_datum_struct_struct_definition,
		&scenario_vehicle_palette_block_block_struct, // block
		&scenario_equipment_block_block_struct, // block
		&scenario_equipment_datum_struct_struct_definition,
		&scenario_equipment_palette_block_block_struct, // block
		&scenario_weapon_block_block_struct, // block
		&scenario_weapon_datum_struct_struct_definition,
		&scenario_weapon_palette_block_block_struct, // block
		&device_group_block_block_struct, // block
		&scenario_machine_block_block_struct, // block
		&scenario_device_struct_struct_definition,
		&scenario_machine_struct_v3_struct_definition,
		&scenario_machine_palette_block_block_struct, // block
		&scenario_terminal_block_block_struct, // block
		&scenario_terminal_struct_struct_definition,
		&scenario_terminal_palette_block_block_struct, // block
		&scenario_control_block_block_struct, // block
		&scenario_control_struct_struct_definition,
		&scenario_control_palette_block_block_struct, // block
		&ScenarioDispenserBlock_block_struct, // block
		&ScenarioDispenserStruct_struct_definition,
		&ScenarioDispenserPaletteBlock_block_struct, // block
		&scenario_sound_scenery_block_block_struct, // block
		&sound_scenery_datum_struct_struct_definition,
		&sound_distance_parameters_struct_struct_definition,
		&scenario_sound_scenery_palette_block_block_struct, // block
		&scenario_giant_block_block_struct, // block
		&scenario_giant_datum_struct_struct_definition,
		&scenario_giant_palette_block_block_struct, // block
		&scenario_effect_scenery_block_block_struct, // block
		&scenario_effect_scenery_datum_struct_struct_definition,
		&scenario_effect_scenery_palette_block_block_struct, // block
		&scenario_spawner_block_block_struct, // block
		&ScenarioEntityStruct_struct_definition,
		&ScenarioSpawnerStruct_struct_definition,
		&scenario_spawner_palette_block_block_struct, // block
		&binkPaletteBlock_block_struct, // block
		&scenarioAttachedEffectsBlock_block_struct, // block
		&scenarioAttachedLensFlaresBlock_block_struct, // block
		&scenarioAttachedLightConesBlock_block_struct, // block
		&map_variant_palette_block_block_struct, // block
		&map_variant_palette_entry_block_block_struct, // block
		&map_variant_object_variant_block_block_struct, // block
		&mapVariantResourceManifest_struct_definition,
		&mapVariantPaletteDependencyBlock_block_struct, // block
		&resourceHandleBlock_block_struct, // block
		&scenario_requisition_palette_block_block_struct, // block
		&scenario_soft_ceilings_block_block_struct, // block
		&scenario_players_block_block_struct, // block
		&scenario_trigger_volume_struct_struct_definition,
		&trigger_volume_point_block_block_struct, // block
		&trigger_volume_runtime_triangles_block_block_struct, // block
		&scenario_acoustic_sector_block_block_struct, // block
		&acoustic_sector_point_block_block_struct, // block
		&scenario_acoustic_transition_block_block_struct, // block
		&scenario_acoustic_location_definition_struct_definition,
		&scenario_acoustic_cluster_reference_definition_struct_definition,
		&scenario_atmosphere_dumpling_block_block_struct, // block
		&scenario_dumpling_struct_struct_definition,
		&dumpling_point_block_block_struct, // block
		&scenario_weather_dumpling_block_block_struct, // block
		&recorded_animation_block_block_struct, // block
		&scenario_zone_set_switch_trigger_volume_block_block_struct, // block
		&scenario_named_location_volume_block_block_struct, // block
		&named_location_volume_point_block_block_struct, // block
		&scenario_decals_block_block_struct, // block
		&scenario_decal_palette_block_block_struct, // block
		&scenario_detail_object_collection_palette_block_block_struct, // block
		&style_palette_block_block_struct, // block
		&squad_groups_block_block_struct, // block
		&squads_block_block_struct, // block
		&spawn_formation_block_block_struct, // block
		&ai_spawn_conditions_struct_struct_definition,
		&patrol_point_block_block_struct, // block
		&spawn_points_block_block_struct, // block
		&squad_definition_internal_struct_struct_definition,
		&cell_block_block_struct, // block
		&character_palette_choice_block_block_struct, // block
		&weapon_palette_choice_block_block_struct, // block
		&equipment_palette_choice_block_block_struct, // block
		&zone_block_block_struct, // block
		&firing_positions_block_block_struct, // block
		&areas_block_block_struct, // block
		&NavMeshAttachmentsStruct_struct_definition,
		&NavMeshAttachmentBlock_block_struct, // block
		&area_cluster_occupancy_bitvector_array_struct_definition, // array
		&flight_reference_block_block_struct, // block
		&area_sector_point_block_block_struct, // block
		&squad_patrol_block_block_struct, // block
		&squad_patrol_member_block_block_struct, // block
		&squad_patrol_point_block_block_struct, // block
		&squad_patrol_transition_block_block_struct, // block
		&squad_patrol_waypoint_block_block_struct, // block
		&ai_cue_block_block_struct, // block
		&cue_distribution_struct_struct_definition,
		&task_distribution_block_block_struct, // block
		&cue_stimulus_distribution_struct_struct_definition,
		&radial_distribution_block_block_struct, // block
		&probability_distribution_block_block_struct, // block
		&character_distribution_block_block_struct, // block
		&weapon_distribution_block_block_struct, // block
		&cue_payload_struct_struct_definition,
		&script_payload_block_block_struct, // block
		&combat_sync_action_group_payload_block_block_struct, // block
		&ai_full_cue_block_block_struct, // block
		&ai_quick_cue_block_block_struct, // block
		&ai_scene_block_block_struct, // block
		&ai_scene_trigger_block_block_struct, // block
		&trigger_references_block_struct, // block
		&ai_scene_role_block_block_struct, // block
		&ai_scene_role_variants_block_block_struct, // block
		&character_palette_block_block_struct, // block
		&ai_recording_reference_block_block_struct, // block
		&cs_script_data_block_block_struct, // block
		&cs_point_set_block_block_struct, // block
		&cs_point_block_block_struct, // block
		&cs_animation_point_block_block_struct, // block
		&scenario_cutscene_flag_block_block_struct, // block
		&scenario_cutscene_camera_point_block_block_struct, // block
		&scenario_cutscene_title_struct_struct_definition,
		&scenario_kill_trigger_volumes_block_block_struct, // block
		&scenario_safe_zone_trigger_volumes_block_block_struct, // block
		&trigger_volume_mopp_code_block_block_struct, // block
		&scenario_requisition_trigger_volumes_block_block_struct, // block
		&scenario_location_name_trigger_volumes_block_block_struct, // block
		&scenarioUnsafeSpawnZoneTriggerVolumesBlock_block_struct, // block
		&orders_block_block_struct, // block
		&area_reference_block_block_struct, // block
		&secondary_set_trigger_block_block_struct, // block
		&special_movement_block_block_struct, // block
		&order_ending_block_block_struct, // block
		&triggers_block_block_struct, // block
		&order_completion_condition_block_struct, // block
		&scenario_atmosphere_palette_block_block_struct, // block
		&scenario_camera_fx_palette_block_block_struct, // block
		&scenario_weather_palette_block_block_struct, // block
		&scenario_cluster_data_block_block_struct, // block
		&scenario_cluster_points_block_block_struct, // block
		&scenario_cluster_acoustics_block_block_struct, // block
		&scenario_cluster_atmosphere_properties_block_block_struct, // block
		&scenario_cluster_camera_fx_properties_block_block_struct, // block
		&scenario_cluster_weather_properties_block_block_struct, // block
		&object_salt_storage_array_struct_definition, // array
		&scenario_spawn_data_block_block_struct, // block
		&scenario_crate_block_block_struct, // block
		&scenario_crate_datum_struct_struct_definition,
		&scenario_crate_palette_block_block_struct, // block
		&flock_palette_block_block_struct, // block
		&flock_instance_block_block_struct, // block
		&flock_source_block_block_struct, // block
		&flock_destination_block_block_struct, // block
		&SoundSubtitleBlock_block_struct, // block
		&scenario_creature_block_block_struct, // block
		&scenario_creature_palette_block_block_struct, // block
		&big_battle_creature_palette_block_block_struct, // block
		&g_scenario_editor_folder_block_block_struct, // block
		&ai_scenario_mission_dialogue_block_block_struct, // block
		&objectives_block_block_struct, // block
		&opposing_objective_block_block_struct, // block
		&tasks_block_block_struct, // block
		&script_fragment_block_block_struct, // block
		&task_direction_block_v2_struct_struct_definition,
		&task_direction_point_block_block_struct, // block
		&scenario_designer_zone_block_block_struct, // block
		&scenarioDesignerZoneTagReferenceBlock_block_struct, // block
		&biped_block_index_flags_block_block_struct, // block
		&vehicle_block_index_flags_block_block_struct, // block
		&weapon_block_index_flags_block_block_struct, // block
		&equipment_block_index_flags_block_block_struct, // block
		&scenery_block_index_flags_block_block_struct, // block
		&machine_block_index_flags_block_block_struct, // block
		&terminal_block_index_flags_block_block_struct, // block
		&control_block_index_flags_block_block_struct, // block
		&dispenser_block_index_flags_block_block_struct, // block
		&sound_scenery_block_index_flags_block_block_struct, // block
		&crate_block_index_flags_block_block_struct, // block
		&creature_block_index_flags_block_block_struct, // block
		&giant_block_index_flags_block_block_struct, // block
		&effect_scenery_block_index_flags_block_block_struct, // block
		&character_block_index_flags_block_block_struct, // block
		&spawner_block_index_flags_block_block_struct, // block
		&budget_reference_block_index_flags_block_block_struct, // block
		&bink_block_index_flags_block_block_struct, // block
		&scenarioDesignerResourceDependenciesBlock_block_struct, // block
		&scenario_zone_debugger_block_definition_struct_struct_definition,
		&scenario_decorator_block_block_struct, // block
		&decorator_brush_struct_struct_definition,
		&decorator_palette_block_struct, // block
		&decorator_scenario_set_block_block_struct, // block
		&global_decorator_placement_block_block_struct, // block
		&scenario_cheap_particle_system_palette_block_block_struct, // block
		&scenario_cheap_particle_systems_block_block_struct, // block
		&scriptableLightRigBlock_block_struct, // block
		&scenario_cinematics_block_block_struct, // block
		&scenario_cinematic_lighting_palette_block_block_struct, // block
		&campaign_metagame_scenario_block_block_struct, // block
		&campaign_metagame_scenario_bonuses_block_block_struct, // block
		&soft_surfaces_definition_block_block_struct, // block
		&scenario_cubemap_block_block_struct, // block
		&scenario_airprobes_block_block_struct, // block
		&scenario_budget_references_block_block_struct, // block
		&model_references_block_block_struct, // block
		&scenario_performances_block_block_struct, // block
		&scenario_performance_actor_block_block_struct, // block
		&scenario_performance_task_block_block_struct, // block
		&PuppetShowsBlock_block_struct, // block
		&PuppetBlock_block_struct, // block
		&PuppetHeaderStruct_struct_definition,
		&PuppetPathPointStruct_struct_definition,
		&PuppetActionBlock_block_struct, // block
		&PuppetActionHeaderStruct_struct_definition,
		&PuppetActionAnimationStruct_struct_definition,
		&PuppetActionPathStruct_struct_definition,
		&PuppetSubActionBlock_block_struct, // block
		&PuppetSubActionHeaderStruct_struct_definition,
		&PuppetSubActionPointStruct_struct_definition,
		&PuppetSubActionBranchStruct_struct_definition,
		&PuppetSubActionBranchElementBlock_block_struct, // block
		&PuppetSubActionScriptStruct_struct_definition,
		&PuppetScriptTextBlock_block_struct, // block
		&SubTracksBlock_block_struct, // block
		&CommentsBlock_block_struct, // block
		&scenarioRandomOrdnanceDropSetBlock_block_struct, // block
		&scenarioRandomOrdnanceDropPointBlock_block_struct, // block
		&ScenarioUnitRecordingBlock_struct_struct_definition,
		&loadScreenReferenceBlock_block_struct, // block
		&scenario_ordnance_list_struct_definition_struct_definition, // tag group
		&RandomOrdnanceItemBlock_block_struct, // block
		&PlayerOrdnanceGroupBlock_block_struct, // block
		&PlayerOrdnanceItemBlock_block_struct, // block
		&structure_design_block_struct, // block
		&global_structure_physics_design_struct_struct_definition,
		&structure_soft_ceiling_block_block_struct, // block
		&structure_soft_ceiling_triangle_block_block_struct, // block
		&structure_water_groups_block_block_struct, // block
		&structure_water_instances_block_block_struct, // block
		&structure_water_instance_planes_block_block_struct, // block
		&structure_water_instance_debug_triangles_block_block_struct, // block
		&planar_fog_set_definition_struct_struct_definition,
		&planar_fog_definition_block_block_struct, // block
		&planar_fog_vertex_block_block_struct, // block
		&planar_fog_triangle_block_block_struct, // block
		&planar_fog_triangle_planes_block_block_struct, // block
		&scenario_required_resource_struct_definition_struct_definition, // tag group
		&area_screen_effect_struct_definition_struct_definition, // tag group
		&single_screen_effect_block_struct, // block
		&screen_effect_scalar_function_struct_struct_definition,
		&screen_effect_scalar_object_function_struct_struct_definition,
		&sound_effect_collection_block_struct, // block
		&platform_sound_playback_block_block_struct, // block
		&platform_sound_playback_struct_struct_definition,
		&platform_sound_playback_lowpass_block_block_struct, // block
		&global_sound_lowpass_block_struct_definition,
		&platform_sound_playback_component_block_block_struct, // block
		&sound_global_propagation_block_struct, // block
		&sound_propagation_definition_struct_struct_definition,
		&sound_response_struct_definition_struct_definition, // tag group
		&sound_response_data_block_block_struct, // block
		&sound_response_permutation_block_block_struct, // block
		&sound_combine_response_block_block_struct, // block
		&shield_impact_struct_definition_struct_definition, // tag group
		&shield_color_function_struct_struct_definition,
		&shield_scalar_function_struct_struct_definition,
		&self_illumination_struct_definition_struct_definition, // tag group
		&self_illumination_state_block_struct, // block
		&simulated_input_struct_definition_struct_definition, // tag group
		&simulated_input_stick_struct_struct_definition,
		&SuppressedIncident_struct_definition_struct_definition, // tag group
		&simulation_interpolation_struct_definition_struct_definition, // tag group
		&single_domain_configuration_struct_struct_definition,
		&single_domain_velocity_bumps_configuration_struct_struct_definition,
		&single_domain_blending_configuration_struct_struct_definition,
		&text_value_pair_definition_struct_definition_struct_definition, // tag group
		&sound_incident_response_struct_definition_struct_definition, // tag group
		&sound_incident_response_data_block_block_struct, // block
		&scenario_interpolator_struct_definition_struct_definition, // tag group
		&scenario_interpolator_data_block_block_struct, // block
		&silent_assist_globals_struct_definition_struct_definition, // tag group
		&silentAssistLevelBlock_block_struct, // block
		&survival_mode_globals_struct_definition_struct_definition, // tag group
		&survival_mode_wave_templates_struct_struct_definition,
		&multiplayer_color_block$3_block_struct, // block
		&structure_meta_struct_definition_struct_definition, // tag group
		&structureBspFxMarkerBlock_block_struct, // block
		&structureMetadataLightConeMarkerBlock_block_struct, // block
		&sound_classes_block_struct, // block
		&sound_class_block_block_struct, // block
		&sound_block_struct, // block
		&soundLipSyncInfoBlock_struct_struct_definition,
		&deterministicSpeechEventBlock_struct_struct_definition,
		&facial_animation_language_block_block_struct, // block
		&sound_environment_block_struct, // block
		&global_sound_reverb_block_struct_definition,
		&sound_old_block_struct, // block
		&sound_playback_parameters_struct_struct_definition,
		&sound_scale_modifiers_struct_struct_definition,
		&sound_promotion_parameters_struct_struct_definition,
		&sound_promotion_rule_block_block_struct, // block
		&sound_promotion_runtime_timer_block_block_struct, // block
		&sound_pitch_range_block_block_struct, // block
		&sound_permutations_block_block_struct, // block
		&sound_permutation_languages_block_block_struct, // block
		&sound_permutation_chunk_block_block_struct, // block
		&sound_platform_sound_playback_block_block_struct, // block
		&sound_extra_info_block_block_struct, // block
		&sound_definition_language_permutation_info_block_block_struct, // block
		&sound_permutation_raw_info_block_block_struct, // block
		&sound_permutation_marker_block_block_struct, // block
		&sound_xma2_seek_table_block_block_struct, // block
		&sound_language_info_block_block_struct, // block
		&sound_permutation_language_info_block_struct, // block
		&sound_pitch_range_language_info_block_struct, // block
		&sound2_block_struct, // block
		&sound_mix_block_struct, // block
		&sound_transmission_definition_struct_struct_definition,
		&sound_stereo_mix_struct_struct_definition,
		&sound_surround_mix_struct_struct_definition,
		&sound_global_mix_struct_struct_definition,
		&sound_center_mix_struct_struct_definition,
		&sound_dialogue_constants_struct_definition_struct_definition, // tag group
		&spawner_struct_definition_struct_definition, // tag group
		&squad_template_block_struct, // block
		&cell_template_block_block_struct, // block
		&character_ref_choice_block_block_struct, // block
		&weapon_ref_choice_block_block_struct, // block
		&equipment_ref_choice_block_block_struct, // block
		&sound_radio_settings_block_struct, // block
		&global_sound_look_up_table_distortion_block_struct_definition,
		&global_sound_equalizer_block_struct_definition,
		&sound_equalizer_band_settings_block_block_struct, // block
		&ssao_definition_struct_definition_struct_definition, // tag group
		&sound_scenery_struct_definition_struct_definition, // tag group
		&SpawnSettings_struct_definition_struct_definition, // tag group
		&influencerSpawnSettingsBlock_block_struct, // block
		&weaponSpawnInfluenceBlock_block_struct, // block
		&vehicleSpawnInfluenceBlock_block_struct, // block
		&projectileSpawnInfluenceBlock_block_struct, // block
		&equipmentSpawnInfluenceBlock_block_struct, // block
		&scenario_structure_lighting_info_struct_definition_struct_definition, // tag group
		&structure_lighting_generic_light_definition_block_block_struct, // block
		&structure_lighting_generic_light_instance_block_block_struct, // block
		&screen_space_light_shader_override_block_block_struct, // block
		&structureLightingCinematicLightInstanceBlock_struct_struct_definition,
		&structureLightingCinematicObjectBlock_block_struct, // block
		&structure_seams_struct_definition_struct_definition, // tag group
		&structure_manifest_struct_struct_definition,
		&structure_manifest_bsp_block_block_struct, // block
		&structure_seam_block_block_struct, // block
		&structure_seam_original_geometry_struct_struct_definition,
		&structure_seam_original_vertex_block_block_struct, // block
		&structure_seam_original_vertex_plane_normals_block_block_struct, // block
		&structure_seam_final_geometry_struct_struct_definition,
		&structure_seam_final_planes_block_block_struct, // block
		&structure_seam_final_points_block_block_struct, // block
		&structure_seam_final_triangles_block_block_struct, // block
		&structure_seam_final_edges_block_block_struct, // block
		&style_struct_definition_struct_definition, // tag group
		&behavior_names_block_block_struct, // block
		&device_terminal_struct_definition_struct_definition, // tag group
		&terminal_page_block_definition_block_struct, // block
		&tracer_system_struct_definition_struct_definition, // tag group
		&tracerDefinitionBlock_block_struct, // block
		&tracerProperty_real_Struct_struct_definition,
		&tracerProperty_real_vector3d_Struct_struct_definition,
		&tracerProperty_real_point2d_Struct_struct_definition,
		&tracerProperty_real_rgb_color_Struct_struct_definition,
		&camera_track_struct_definition_struct_definition, // tag group
		&camera_track_control_point_block_block_struct, // block
		&dialogue_block_struct, // block
		&sound_references_block_block_struct, // block
		&vocalization_stimuli_block_definition_block_struct, // block
		&sound_cache_file_gestalt_struct_definition_struct_definition, // tag group
		&sound_gestalt_codec_block_block_struct, // block
		&sound_gestalt_playback_block_block_struct, // block
		&sound_gestalt_scale_block_block_struct, // block
		&sound_gestalt_import_names_block_block_struct, // block
		&sound_gestalt_pitch_range_parameters_block_block_struct, // block
		&sound_gestalt_pitch_ranges_block_block_struct, // block
		&sound_gestalt_permutations_block_block_struct, // block
		&sound_gestalt_permutation_languages_block_block_struct, // block
		&sound_gestalt_custom_playback_block_block_struct, // block
		&sound_gestalt_runtime_permutation_bit_vector_block_block_struct, // block
		&sound_gestalt_promotions_block_block_struct, // block
		&sound_gestalt_facial_animation_block_block_struct, // block
		&sound_gestalt_layer_markers_block_block_struct, // block
		&user_interface_hud_globals_definition_struct_definition_struct_definition, // tag group
		&screen_transform_basis_array_definition_struct_definition, // array
		&player_training_entry_data_block_block_struct, // block
		&user_interface_sounds_definition_struct_definition_struct_definition, // tag group
		&style_sheet_list_struct_definition_struct_definition, // tag group
		&UserInterfaceStyleSheetLanguagesBlock_block_struct, // block
		&UserInterfaceStyleSheetsFontBlock_block_struct, // block
		&UserInterfaceStyleSheetFontIdBlock_block_struct, // block
		&UserInterfaceStyleSheetTextCaseBlock_block_struct, // block
		&UserInterfaceStyleSheetJustificationBlock_block_struct, // block
		&UserInterfaceStyleSheetAlignmentBlock_block_struct, // block
		&UserInterfaceStyleSheetScaleBlock_block_struct, // block
		&UserInterfaceStyleSheetFixedHeightBlock_block_struct, // block
		&UserInterfaceStyleSheetsVisualBlock_block_struct, // block
		&UserInterfaceStyleSheetDropShadowStyleBlock_block_struct, // block
		&UserInterfaceStyleSheetColorBlock_block_struct, // block
		&UserInterfaceStyleSheetGradientBlock_block_struct, // block
		&UserInterfaceStyleSheetDropshadowBlock_block_struct, // block
		&UserInterfaceStyleSheetOuterGlowBlock_block_struct, // block
		&multilingual_unicode_string_list_struct_definition_struct_definition, // tag group
		&multilingual_unicode_string_reference_block_block_struct, // block
		&string_substitution_pair_block_block_struct, // block
		&multilingual_unicode_string_list_language_pack_offsets_struct_definition, // array
		&vectorart_asset_block_struct, // block
		&vector_hud_definition_struct_definition_struct_definition, // tag group
		&vehicle_group_struct_definition, // tag group
		&vehicle_physics_types_struct_struct_definition,
		&human_tank_struct_struct_definition,
		&global_vehicle_engine_struct_struct_definition,
		&gear_block_block_struct, // block
		&torque_curve_struct_struct_definition,
		&load_and_cruise_block_block_struct, // block
		&human_jeep_block_block_struct, // block
		&vehicle_steering_control_struct_struct_definition,
		&vehicle_turning_control_struct_struct_definition,
		&boat_engine_definition_block_block_struct, // block
		&human_plane_block_block_struct, // block
		&steering_animation_struct_struct_definition,
		&wolverine_block_block_struct, // block
		&alien_scout_block_block_struct, // block
		&engine_function_struct_struct_definition,
		&alien_fighter_block_block_struct, // block
		&turret_block_block_struct, // block
		&mantis_block_block_struct, // block
		&walker_physics_struct_struct_definition,
		&walker_physics_leg_block_block_struct, // block
		&vtol_block_block_struct, // block
		&vtol_descent_function_struct_struct_definition,
		&vtol_speed_interpolated_block_block_struct, // block
		&chopper_block_block_struct, // block
		&guardian_block_block_struct, // block
		&jackal_glider_block_block_struct, // block
		&flight_surface_struct_struct_definition,
		&jackal_glider_drag_struct_struct_definition,
		&boat_block_block_struct, // block
		&space_fighter_block_block_struct, // block
		&revenant_block_block_struct, // block
		&havok_vehicle_physics_struct_struct_definition,
		&anti_gravity_point_definition_block_block_struct, // block
		&friction_point_definition_block_block_struct, // block
		&boat_physics_definition_struct_struct_definition,
		&SoundRTPCBlock_block_struct, // block
		&SoundSweetenerBlock_block_struct, // block
		&physics_transitions_block_block_struct, // block
		&vision_mode_struct_definition_struct_definition, // tag group
		&visionModeScreenPassBlock_block_struct, // block
		&visionModeEnvironmentPassBlock_block_struct, // block
		&visionModeBipedPassesBlock_block_struct, // block
		&visionModeBipedPassBlock_block_struct, // block
		&visionModeBipedThreatBlock_block_struct, // block
		&visionModeOrdnanceVehiclePassBlock_block_struct, // block
		&visionModeOrdnanceVehicleTypeBlock_block_struct, // block
		&visionModeOrdnanceCrosshairBlock_block_struct, // block
		&variant_globals_struct_definition_struct_definition, // tag group
		&single_variant_block_block_struct, // block
		&FallbackHopperFileBlock_block_struct, // block
		&vertex_shader_block_struct, // block
		&vertex_entry_point_block_block_struct, // block
		&vertex_types_block$3_block_struct, // block
		&wave_template_block_struct, // block
		&wave_squad_specification_struct_struct_struct_definition,
		&weapon_block_struct, // block
		&melee_damage_parameters_block_struct_definition, // block
		&aim_assist_struct_struct_definition,
		&WeaponBarrelIronSightsStruct_struct_definition,
		&globalAimAssistBlock_block_struct, // block
		&globalAimSwimBlock_block_struct, // block
		&weapon_interface_struct_struct_definition,
		&weapon_shared_interface_struct_struct_definition,
		&weapon_first_person_interface_block_block_struct, // block
		&magazines_block_struct, // block
		&magazine_objects_block_struct, // block
		&weapon_triggers_block_struct, // block
		&weapon_trigger_autofire_struct_struct_definition,
		&weapon_trigger_charging_struct_struct_definition,
		&weapon_trigger_charging_fire_fraction_block_struct, // block
		&weapon_barrels_block_struct, // block
		&weapon_barrel_firing_parameters_struct_struct_definition,
		&weapon_barrel_firing_error_struct_struct_definition,
		&projectileDistributionCustomVector_block_struct, // block
		&weapon_barrel_projectile_accuracy_penalty_struct_struct_definition,
		&weapon_barrel_projectile_accuracy_penalty_function_struct_struct_definition,
		&weapon_barrel_function_block_block_struct, // block
		&weapon_barrel_first_person_offset_block_block_struct, // block
		&weapon_barrel_damage_effect_struct_struct_definition,
		&barrel_firing_effect_block_block_struct, // block
		&weaponScaleshotStruct_block_struct, // block
		&weaponScaleshotLevelStruct_block_struct, // block
		&weapon_screen_effect_block_block_struct, // block
		&WeaponSoundRTPCBlock_block_struct, // block
		&WeaponSoundSweetenerBlock_block_struct, // block
		&scenario_wetness_bsp_data_struct_definition_struct_definition, // tag group
		&wentness_bit_vector_block_struct, // block
		&wentness_byte_vector_block_struct, // block
		&cluster_wetness_offset_block_block_struct, // block
		&instance_wetness_instance_block_block_struct, // block
		&game_engine_settings_definition_struct_definition_struct_definition, // tag group
		&game_engine_player_traits_list_block_block_struct, // block
		&game_engine_ai_traits_list_block_block_struct, // block
		&game_engine_ai_traits_struct_struct_definition,
		&game_engine_sandbox_variant_block_block_struct, // block
		&game_engine_survival_variant_block_block_struct, // block
		&game_engine_survival_set_properties_block_block_struct, // block
		&game_engine_survival_round_properties_block_block_struct, // block
		&game_engine_survival_wave_properties_struct_struct_definition,
		&survival_wave_squad_block_block_struct, // block
		&game_engine_survival_bonus_wave_properties_struct_struct_definition,
		&game_engine_survival_custom_skull_block_block_struct, // block
		&GameEngineFirefightVariantShellBlock_block_struct, // block
		&game_engine_campaign_variant_block_block_struct, // block
		&user_interface_globals_definition_struct_definition_struct_definition, // tag group
		&cui_component_screen_reference_block_definition_block_struct, // block
		&cui_overlay_camera_block_definition_block_struct, // block
		&cui_player_model_camera_settings_definition_block_struct, // block
		&cui_player_model_controller_settings_definition_block_struct, // block
		&cui_player_model_transition_settings_definition_block_struct, // block
		&cui_active_roster_settings_block_block_struct, // block
		&campaign_state_screen_script_block_definition_block_struct, // block
		&UserInterfaceGameScreenSequenceStepDefinition_block_struct, // block
		&SwapTagReferenceDefinition_block_struct, // block
		&cellular_automata2d_struct_definition_struct_definition, // tag group
		&rules_block_block_struct, // block
		&states_block_block_struct, // block
		&user_interface_shared_globals_definition_struct_definition_struct_definition, // tag group
		&color_presets_block_block_struct, // block
		&tint_colors_block_block_struct, // block
		&color_list_block_block_struct, // block
		&gui_alert_description_block_block_struct, // block
		&gui_dialog_description_block_block_struct, // block
		&pgcr_incident_block_block_struct, // block
		&wind_block_struct, // block
		&wind_scalar_function_struct_struct_definition,
		&water_physics_drag_properties_struct_definition_struct_definition, // tag group
		&weather_globals_struct_definition_struct_definition, // tag group
		&global_textures_refs_block_block_struct, // block
		&rain_ripple_setting_block_struct_definition,
		&cache_file_resource_gestalt_block_struct, // block
		&cache_file_resource_type_identifier_block_block_struct, // block
		&tag_resource_alignment_bits_array_definition_struct_definition, // array
		&cache_file_interop_type_identifier_block_block_struct, // block
		&cache_file_resource_data_block_block_struct, // block
		&cache_file_resource_fixup_location_block_block_struct, // block
		&cache_file_resource_interop_location_block_block_struct, // block
		&cache_file_resource_priority_data_block_block_struct, // block
		&cache_file_tag_zone_manifest_struct_struct_definition,
		&cache_file_tag_resources_bitvector_block_block_struct, // block
		&resource_usage_page_size_array_definition_struct_definition, // array
		&cache_file_tag_resource_usage_block_block_struct, // block
		&cache_file_zone_resource_visit_node_block_block_struct, // block
		&cache_file_zone_resource_visit_node_link_block_block_struct, // block
		&cache_file_zone_set_zone_usage_block_block_struct, // block
		&cache_file_bsp_reference_block_block_struct, // block
		&cache_file_resource_owner_block_block_struct, // block
		&cache_file_model_variant_usage_block_block_struct, // block
		&cache_file_resource_owner_reference_block_block_struct, // block
		&cache_file_character_usage_block_block_struct, // block
		&cache_file_model_variant_usage_reference_block_block_struct, // block
		&cache_file_bsp_game_attachments_block_block_struct, // block
		&cache_file_bsp_attachment_block_block_struct, // block
		&debug_cache_file_zone_manifest_struct_struct_definition,
		&cache_file_debug_resource_definition_block_block_struct, // block
		&resource_category_block_block_struct, // block
		&cache_file_resource_layout_block_block_struct, // block
		&resource_layout_memory_size_array_definition_struct_definition, // array
		&resource_layout_compressed_size_array_definition_struct_definition, // array
		&cache_file_tag_resource_properties_block_block_struct, // block
		&cache_file_tag_resource_named_value_block_block_struct, // block
		&cache_file_tag_parentage_block_block_struct, // block
		&cache_file_tag_parentage_reference_block_block_struct, // block
		&cache_file_tag_resource_prediction_table_struct_definition,
		&cache_file_tag_resource_prediction_quantum_block_block_struct, // block
		&cache_file_tag_resource_prediction_atom_block_block_struct, // block
		&cache_file_tag_resource_prediction_molecule_atom_reference_block_block_struct, // block
		&cache_file_tag_resource_prediction_molecule_block_block_struct, // block
		&cache_file_tag_resource_prediction_molecule_keys_block_block_struct, // block
		// manual
		&compute_shader_block_struct,
		&compute_shader2_block_struct,
		&compute_entry_point_block_block_struct,
		&compiled_compute_shader_block_block_struct,
		&halo3_unit_camera_struct_unknown_block_struct,
		&unit_hud_interfaces_block_block_struct,
		&hud_screen_reference_block_block_struct,
		nullptr
	};

} // namespace blofeld

