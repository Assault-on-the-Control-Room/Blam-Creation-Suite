#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_REFERENCE(render_method_definition_reference, RENDER_METHOD_DEFINITION_TAG, _tag_reference_flag_not_a_resource_dependency);

	TAG_REFERENCE(render_method_reference, RENDER_METHOD_TAG, _tag_reference_flag_dont_resolve_in_editor);

	TAG_REFERENCE(bitmap_reference, BITMAP_TAG, _tag_reference_flag_dont_resolve_in_editor | _tag_reference_flag_not_a_resource_dependency);

	TAG_REFERENCE(render_method_template_reference, RENDER_METHOD_TEMPLATE_TAG);

	TAG_REFERENCE(model_reference, MODEL_TAG);

	TAG_REFERENCE(lightmap_bitmap_reference, BITMAP_TAG, _tag_reference_flag_dont_resolve_in_editor);

	TAG_REFERENCE(bitmap_reference$3, BITMAP_TAG, _tag_reference_flag_dont_resolve_in_editor);

	TAG_REFERENCE(ai_dialogue_globals_reference, AI_DIALOGUE_GLOBALS_TAG);

	TAG_REFERENCE(formation_reference, FORMATION_TAG);

	TAG_REFERENCE(squad_template_reference, SQUAD_TEMPLATE_TAG);

	TAG_REFERENCE(performance_template_reference, PERFORMANCE_TEMPLATE_TAG);

	TAG_REFERENCE(bitmap_reference$4, BITMAP_TAG);

	TAG_REFERENCE(projectile_reference, PROJECTILE_TAG);

	TAG_REFERENCE(sound_looping_reference, SOUND_LOOPING_TAG);

	TAG_REFERENCE(imposter_model_reference, IMPOSTER_MODEL_TAG);

	TAG_REFERENCE(model_reference$2, MODEL_TAG);

	TAG_REFERENCE(crate_reference, CRATE_TAG);

	TAG_REFERENCE(collision_damage_reference, COLLISION_DAMAGE_TAG);

	TAG_REFERENCE_GROUP(global_object_attachment_block_type_reference)
	{
		LIGHT_TAG,
		CHEAP_LIGHT_TAG,
		LIGHT_VOLUME_SYSTEM_TAG,
		EFFECT_TAG,
		SOUND_LOOPING_TAG,
		LENS_FLARE_TAG,
		CHEAP_PARTICLE_EMITTER_TAG,
		EFFECT_GLOBAL_FORCE_TAG,
		DECAL_SYSTEM_TAG,
		INVALID_TAG,
	};

	TAG_REFERENCE_GROUP(object_widget_block_type_reference)
	{
		ANTENNA_TAG,
		CLOTH_TAG,
		INVALID_TAG,
	};

	TAG_REFERENCE(object_reference, OBJECT_TAG);

	TAG_REFERENCE_GROUP(multiplayer_object_block_boundary_standard_shader_reference)
	{
		MATERIAL_TAG,
		RENDER_METHOD_TAG,
		INVALID_TAG,
	};

	TAG_REFERENCE(hsc_reference, HSC_TAG);

	TAG_REFERENCE(hs_references_block_reference_reference);

	TAG_REFERENCE_GROUP(unit_struct_definition_hologram_unit_reference_reference)
	{
		BIPED_TAG,
		VEHICLE_TAG,
		INVALID_TAG,
	};

	TAG_REFERENCE(damage_response_definition_reference, DAMAGE_RESPONSE_DEFINITION_TAG);

	TAG_REFERENCE(weapon_reference, WEAPON_TAG);

	TAG_REFERENCE(spring_acceleration_reference, SPRING_ACCELERATION_TAG);

	TAG_REFERENCE(character_reference, CHARACTER_TAG);

	TAG_REFERENCE(dialogue_reference, DIALOGUE_TAG);

	TAG_REFERENCE(crate_reference$2, CRATE_TAG);

	TAG_REFERENCE(collision_damage_reference$2, COLLISION_DAMAGE_TAG);

	TAG_REFERENCE(character_reference$2, CHARACTER_TAG, _tag_reference_flag_not_a_dependency | _tag_reference_flag_not_a_resource_dependency);

	TAG_REFERENCE(muffin_reference, MUFFIN_TAG);

	TAG_REFERENCE(self_illumination_reference, SELF_ILLUMINATION_TAG);

	TAG_REFERENCE(particle_reference, PARTICLE_TAG);

	TAG_REFERENCE(character_reference$3, CHARACTER_TAG);

	TAG_REFERENCE(unit_reference, UNIT_TAG);

	TAG_REFERENCE(creature_reference, CREATURE_TAG);

	TAG_REFERENCE(style_reference, STYLE_TAG);

	TAG_REFERENCE(dialogue_reference$2, DIALOGUE_TAG);

	TAG_REFERENCE(weapon_reference$2, WEAPON_TAG, _tag_reference_flag_not_a_dependency);

	TAG_REFERENCE(weapon_reference$3, WEAPON_TAG);

	TAG_REFERENCE(equipment_reference, EQUIPMENT_TAG);

	TAG_REFERENCE(projectile_reference$2, PROJECTILE_TAG);

	TAG_REFERENCE(unit_reference$2, UNIT_TAG, _tag_reference_flag_not_a_dependency);

	TAG_REFERENCE(damage_effect_reference, DAMAGE_EFFECT_TAG);

	TAG_REFERENCE(muffin_reference$2, MUFFIN_TAG);

	TAG_REFERENCE(crate_reference$3, CRATE_TAG, _tag_reference_flag_not_a_dependency);

	TAG_REFERENCE(effect_reference, EFFECT_TAG);

	TAG_REFERENCE(crate_reference$4, CRATE_TAG);

	TAG_REFERENCE(object_reference$2, OBJECT_TAG);

	TAG_REFERENCE(scenario_reference, SCENARIO_TAG, _tag_reference_flag_not_a_dependency);

	TAG_REFERENCE(cinematic_transition_reference, CINEMATIC_TRANSITION_TAG);

	TAG_REFERENCE(bink_reference, BINK_TAG);

	TAG_REFERENCE(cinematic_scene_reference, CINEMATIC_SCENE_TAG);

	TAG_REFERENCE(cinematic_scene_data_reference, CINEMATIC_SCENE_DATA_TAG);

	TAG_REFERENCE_GROUP(scene_object_attachment_block_attachment_type_reference)
	{
		OBJECT_TAG,
		SCENERY_TAG,
		EFFECT_SCENERY_TAG,
		INVALID_TAG,
	};

	TAG_REFERENCE(bitmap_reference$5, BITMAP_TAG);

	TAG_REFERENCE(cheap_particle_type_library_reference, CHEAP_PARTICLE_TYPE_LIBRARY_TAG);

	TAG_REFERENCE_GROUP(device_struct_definition_open_up_reference)
	{
		SOUND_TAG,
		SOUND_OLD_TAG,
		EFFECT_TAG,
		INVALID_TAG,
	};

	TAG_REFERENCE(property_tag_reference_value_value_reference);

	TAG_REFERENCE(cui_logic_reference, CUI_LOGIC_TAG);

	TAG_REFERENCE(render_model_reference, RENDER_MODEL_TAG);

	TAG_REFERENCE(bitmap_reference$6, BITMAP_TAG);

	TAG_REFERENCE(material_shader_reference, MATERIAL_SHADER_TAG);

	TAG_REFERENCE(bitmap_reference$7, BITMAP_TAG, _tag_reference_flag_dont_resolve_in_editor | _tag_reference_flag_not_a_resource_dependency);

	TAG_REFERENCE_GROUP(device_dispenser_struct_definition_dispensed_object_reference)
	{
		BIPED_TAG,
		VEHICLE_TAG,
		WEAPON_TAG,
		CRATE_TAG,
		INVALID_TAG,
	};

	TAG_REFERENCE_GROUP(effect_part_block_type_reference)
	{
		RENDER_WATER_RIPPLE_TAG,
		DAMAGE_EFFECT_TAG,
		DAMAGE_RESPONSE_DEFINITION_TAG,
		SOUND_OLD_TAG,
		DECAL_SYSTEM_TAG,
		LENS_FLARE_TAG,
		LIGHT_TAG,
		CHEAP_LIGHT_TAG,
		LIGHT_VOLUME_SYSTEM_TAG,
		AREA_SCREEN_EFFECT_TAG,
		CHARACTER_TAG,
		CHEAP_PARTICLE_EMITTER_TAG,
		OBJECT_TAG,
		SHIELD_IMPACT_TAG,
		CAMO_TAG,
		SOUND_TAG,
		TRACER_SYSTEM_TAG,
		AIRSTRIKE_TAG,
		INVALID_TAG,
	};

	TAG_REFERENCE(object_reference$4, OBJECT_TAG);

	TAG_REFERENCE(character_reference$4, CHARACTER_TAG);

	TAG_REFERENCE(collision_damage_reference$3, COLLISION_DAMAGE_TAG);

	TAG_REFERENCE(damage_effect_reference$2, DAMAGE_EFFECT_TAG);

	TAG_REFERENCE(collision_damage_reference$4, COLLISION_DAMAGE_TAG);

	TAG_REFERENCE(effect_reference$2, EFFECT_TAG);

	TAG_REFERENCE(crate_reference$5, CRATE_TAG);

	TAG_REFERENCE(wave_template_reference, WAVE_TEMPLATE_TAG);

	TAG_REFERENCE_GROUP(material_effect_material_block_tag_effect_or_sound_reference, _tag_reference_flag_resolved_by_game)
	{
		SOUND_OLD_TAG,
		SOUND_LOOPING_TAG,
		SOUND_TAG,
		EFFECT_TAG,
		INVALID_TAG,
	};

	TAG_REFERENCE(effect_scenery_reference, EFFECT_SCENERY_TAG);

	TAG_REFERENCE(model_reference$3, MODEL_TAG, _tag_reference_flag_not_a_dependency);

	TAG_REFERENCE(game_engine_settings_definition_reference, GAME_ENGINE_SETTINGS_DEFINITION_TAG);

	TAG_REFERENCE(render_model_reference$2, RENDER_MODEL_TAG);

	TAG_REFERENCE(collision_model_reference, COLLISION_MODEL_TAG);

	TAG_REFERENCE(physics_model_reference, PHYSICS_MODEL_TAG);

	TAG_REFERENCE(imposter_model_reference$2, IMPOSTER_MODEL_TAG);

	TAG_REFERENCE(object_reference$5, OBJECT_TAG, _tag_reference_flag_dont_resolve_in_editor);

	TAG_REFERENCE(dialogue_reference$3, DIALOGUE_TAG, _tag_reference_flag_dont_resolve_in_editor);

	TAG_REFERENCE(scenario_reference$2, SCENARIO_TAG, _tag_reference_flag_not_a_dependency);

	TAG_REFERENCE(render_model_reference$3, RENDER_MODEL_TAG, _tag_reference_flag_not_a_dependency);

	TAG_REFERENCE(reward_globals_definition_reference, REWARD_GLOBALS_DEFINITION_TAG);

	TAG_REFERENCE(commendation_globals_definition_reference, COMMENDATION_GLOBALS_DEFINITION_TAG);

	TAG_REFERENCE(incident_globals_definition_reference, INCIDENT_GLOBALS_DEFINITION_TAG);

	TAG_REFERENCE(model_animation_graph_reference, MODEL_ANIMATION_GRAPH_TAG);

	TAG_REFERENCE_GROUP(animation_sync_action_other_type_participant_object_type_reference, _tag_reference_flag_not_a_dependency)
	{
		UNIT_TAG,
		SCENERY_TAG,
		INVALID_TAG,
	};

	TAG_REFERENCE(render_model_reference$4, RENDER_MODEL_TAG);

	TAG_REFERENCE(bitmap_reference$8, BITMAP_TAG);

	TAG_REFERENCE(sound_classes_reference, SOUND_CLASSES_TAG);

	TAG_REFERENCE(sound_mix_reference, SOUND_MIX_TAG);

	TAG_REFERENCE(sound_dialogue_constants_reference, SOUND_DIALOGUE_CONSTANTS_TAG);

	TAG_REFERENCE(sound_global_propagation_reference, SOUND_GLOBAL_PROPAGATION_TAG);

	TAG_REFERENCE(ai_globals_reference, AI_GLOBALS_TAG);

	TAG_REFERENCE(sound_block_sound_OBSOLETE_reference);

	TAG_REFERENCE(model_reference$4, MODEL_TAG);

	TAG_REFERENCE(unit_reference$3, UNIT_TAG);

	TAG_REFERENCE(render_water_ripple_reference, RENDER_WATER_RIPPLE_TAG);

	TAG_REFERENCE(forge_globals_reference, FORGE_GLOBALS_TAG);

	TAG_REFERENCE(game_engine_globals_reference, GAME_ENGINE_GLOBALS_TAG);

	TAG_REFERENCE(multiplayer_globals_reference, MULTIPLAYER_GLOBALS_TAG);

	TAG_REFERENCE(survival_mode_globals_reference, SURVIVAL_MODE_GLOBALS_TAG);

	TAG_REFERENCE(firefight_globals_reference, FIREFIGHT_GLOBALS_TAG);

	TAG_REFERENCE(scenery_reference, SCENERY_TAG);

	TAG_REFERENCE(game_medal_globals_reference, GAME_MEDAL_GLOBALS_TAG);

	TAG_REFERENCE(collision_damage_reference$5, COLLISION_DAMAGE_TAG);

	TAG_REFERENCE(havok_collision_filter_reference, HAVOK_COLLISION_FILTER_TAG);

	TAG_REFERENCE(incident_global_properties_definition_reference, INCIDENT_GLOBAL_PROPERTIES_DEFINITION_TAG);

	TAG_REFERENCE(player_grade_globals_definition_reference, PLAYER_GRADE_GLOBALS_DEFINITION_TAG);

	TAG_REFERENCE(player_enlistment_globals_definition_reference, PLAYER_ENLISTMENT_GLOBALS_DEFINITION_TAG);

	TAG_REFERENCE(challenge_globals_definition_reference, CHALLENGE_GLOBALS_DEFINITION_TAG);

	TAG_REFERENCE(game_completion_rewards_globals_reference, GAME_COMPLETION_REWARDS_GLOBALS_TAG);

	TAG_REFERENCE(achievements_reference, ACHIEVEMENTS_TAG);

	TAG_REFERENCE(avatar_awards_reference, AVATAR_AWARDS_TAG);

	TAG_REFERENCE(game_performance_throttle_reference, GAME_PERFORMANCE_THROTTLE_TAG);

	TAG_REFERENCE(armormod_globals_reference, ARMORMOD_GLOBALS_TAG);

	TAG_REFERENCE(material_shader_bank_reference, MATERIAL_SHADER_BANK_TAG);

	TAG_REFERENCE(sound_reference, SOUND_TAG, _tag_reference_flag_resolved_by_game);

	TAG_REFERENCE(bitmap_reference$9, BITMAP_TAG, _tag_reference_flag_dont_resolve_in_editor);

	TAG_REFERENCE(render_model_reference$5, RENDER_MODEL_TAG);

	TAG_REFERENCE(effect_reference$3, EFFECT_TAG, _tag_reference_flag_resolved_by_game);

	TAG_REFERENCE(sound_reference$2, SOUND_TAG, _tag_reference_flag_resolved_by_game);

	TAG_REFERENCE(global_geometry_material_block_render_method_reference);

	TAG_REFERENCE(object_reference$6, OBJECT_TAG, _tag_reference_flag_not_a_dependency);

	TAG_REFERENCE(weapon_reference$4, WEAPON_TAG);

	TAG_REFERENCE_GROUP(requisition_palette_block_name_reference, _tag_reference_flag_not_a_dependency | _tag_reference_flag_dependency_for_cache_file_sharing)
	{
		OBJECT_TAG,
		VEHICLE_TAG,
		CUSTOM_APP_GLOBALS_TAG,
		INVALID_TAG,
	};

	TAG_REFERENCE(weapon_reference$5, WEAPON_TAG);

	TAG_REFERENCE(equipment_reference$2, EQUIPMENT_TAG);

	TAG_REFERENCE(unit_reference$4, UNIT_TAG);

	TAG_REFERENCE(object_reference$7, OBJECT_TAG);

	TAG_REFERENCE_GROUP(multiplayer_runtime_block_hill_shader_reference)
	{
		MATERIAL_TAG,
		RENDER_METHOD_TAG,
		INVALID_TAG,
	};

	TAG_REFERENCE(bitmap_reference$10, BITMAP_TAG);

	TAG_REFERENCE(shader_mux_reference, SHADER_MUX_TAG);

	TAG_REFERENCE(tag_patch_block_struct_new_tag_reference);

	TAG_REFERENCE(tag_patch_block_struct_tag_to_override_reference);

	TAG_REFERENCE(render_model_reference$6, RENDER_MODEL_TAG, _tag_reference_flag_not_a_dependency);

	TAG_REFERENCE(character_reference$5, CHARACTER_TAG, _tag_reference_flag_not_a_dependency);

	TAG_REFERENCE(vehicle_reference, VEHICLE_TAG, _tag_reference_flag_not_a_dependency);

	TAG_REFERENCE(weapon_reference$6, WEAPON_TAG, _tag_reference_flag_not_a_dependency);

	TAG_REFERENCE(render_model_reference$7, RENDER_MODEL_TAG, _tag_reference_flag_not_a_dependency);

	TAG_REFERENCE(scenario_structure_bsp_reference, SCENARIO_STRUCTURE_BSP_TAG, _tag_reference_flag_dont_resolve_in_editor);

	TAG_REFERENCE(scenery_reference$2, SCENERY_TAG);

	TAG_REFERENCE_GROUP(attachment_block_type_reference)
	{
		EFFECT_TAG,
		SOUND_OLD_TAG,
		MATERIAL_EFFECTS_TAG,
		INVALID_TAG,
	};

	TAG_REFERENCE(particle_model_reference$2, PARTICLE_MODEL_TAG);

	TAG_REFERENCE(bitmap_reference$11, BITMAP_TAG, _tag_reference_flag_dont_resolve_in_editor);

	TAG_REFERENCE_GROUP(explicit_shader_refs_block_explicit_vertex_shader_reference)
	{
		MATERIAL_TAG,
		MATERIAL_SHADER_TAG,
		VERTEX_SHADER_TAG,
		INVALID_TAG,
	};

	TAG_REFERENCE_GROUP(explicit_shader_refs_block_explicit_pixel_shader_reference)
	{
		MATERIAL_TAG,
		MATERIAL_SHADER_TAG,
		PIXEL_SHADER_TAG,
		INVALID_TAG,
	};

	TAG_REFERENCE(cheap_particle_type_library_reference$2, CHEAP_PARTICLE_TYPE_LIBRARY_TAG);

	TAG_REFERENCE(render_model_reference$8, RENDER_MODEL_TAG);

	TAG_REFERENCE(render_method_option_reference, RENDER_METHOD_OPTION_TAG, _tag_reference_flag_not_a_resource_dependency);

	TAG_REFERENCE(global_pixel_shader_reference, GLOBAL_PIXEL_SHADER_TAG);

	TAG_REFERENCE(global_vertex_shader_reference, GLOBAL_VERTEX_SHADER_TAG);

	TAG_REFERENCE(vertex_shader_reference, VERTEX_SHADER_TAG);

	TAG_REFERENCE(pixel_shader_reference, PIXEL_SHADER_TAG);

	TAG_REFERENCE(scenario_wetness_bsp_data_reference, SCENARIO_WETNESS_BSP_DATA_TAG);

	TAG_REFERENCE_GROUP(structure_collision_materials_block_render_method_reference, _tag_reference_flag_not_a_resource_dependency)
	{
		MATERIAL_TAG,
		RENDER_METHOD_TAG,
		INVALID_TAG,
	};

	TAG_REFERENCE(light_reference, LIGHT_TAG, _tag_reference_flag_resolved_by_game);

	TAG_REFERENCE(object_reference$8, OBJECT_TAG, _tag_reference_flag_dont_resolve_in_editor | _tag_reference_flag_not_a_resource_dependency);

	TAG_REFERENCE(render_model_reference$9, RENDER_MODEL_TAG, _tag_reference_flag_dont_resolve_in_editor | _tag_reference_flag_not_a_resource_dependency);

	TAG_REFERENCE_GROUP(leaf_system_reference)
	{
		LEAF_SYSTEM_TAG,
		INVALID_TAG,
	};

	TAG_REFERENCE(cheap_light_reference, CHEAP_LIGHT_TAG, _tag_reference_flag_resolved_by_game);

	TAG_REFERENCE(prefab_reference, PREFAB_TAG);

	TAG_REFERENCE(model_animation_graph_reference$2, MODEL_ANIMATION_GRAPH_TAG);

	TAG_REFERENCE(game_performance_throttle_reference$2, GAME_PERFORMANCE_THROTTLE_TAG);

	TAG_REFERENCE(structure_design_reference, STRUCTURE_DESIGN_TAG);

	TAG_REFERENCE(structure_seams_reference, STRUCTURE_SEAMS_TAG);

	TAG_REFERENCE(scenery_reference$3, SCENERY_TAG);

	TAG_REFERENCE(streamingzoneset_reference, STREAMINGZONESET_TAG);

	TAG_REFERENCE(sound_reference$3, SOUND_TAG, _tag_reference_flag_not_a_dependency);

	TAG_REFERENCE(scenery_reference$4, SCENERY_TAG);

	TAG_REFERENCE(biped_reference, BIPED_TAG);

	TAG_REFERENCE(vehicle_reference$2, VEHICLE_TAG);

	TAG_REFERENCE(equipment_reference$3, EQUIPMENT_TAG);

	TAG_REFERENCE(weapon_reference$7, WEAPON_TAG);

	TAG_REFERENCE(device_machine_reference, DEVICE_MACHINE_TAG);

	TAG_REFERENCE(device_terminal_reference, DEVICE_TERMINAL_TAG);

	TAG_REFERENCE(device_control_reference, DEVICE_CONTROL_TAG);

	TAG_REFERENCE(device_dispenser_reference, DEVICE_DISPENSER_TAG);

	TAG_REFERENCE(sound_scenery_reference, SOUND_SCENERY_TAG);

	TAG_REFERENCE(giant_reference, GIANT_TAG);

	TAG_REFERENCE(effect_scenery_reference$2, EFFECT_SCENERY_TAG);

	TAG_REFERENCE(spawner_reference, SPAWNER_TAG);

	TAG_REFERENCE(bink_reference$2, BINK_TAG);

	TAG_REFERENCE(object_reference$9, OBJECT_TAG);

	TAG_REFERENCE_GROUP(scenario_requisition_palette_block_name_reference)
	{
		OBJECT_TAG,
		VEHICLE_TAG,
		SCENERY_TAG,
		DEVICE_MACHINE_TAG,
		CUSTOM_APP_GLOBALS_TAG,
		INVALID_TAG,
	};

	TAG_REFERENCE(decal_system_reference, DECAL_SYSTEM_TAG);

	TAG_REFERENCE(style_reference$2, STYLE_TAG);

	TAG_REFERENCE(character_reference$6, CHARACTER_TAG);

	TAG_REFERENCE(crate_reference$6, CRATE_TAG);

	TAG_REFERENCE(flock_reference, FLOCK_TAG);

	TAG_REFERENCE(creature_reference$2, CREATURE_TAG);

	TAG_REFERENCE(big_battle_creature_reference, BIG_BATTLE_CREATURE_TAG);

	TAG_REFERENCE(ai_mission_dialogue_reference, AI_MISSION_DIALOGUE_TAG);

	TAG_REFERENCE(scenario_lightmap_reference, SCENARIO_LIGHTMAP_TAG);

	TAG_REFERENCE(scenarioDesignerZoneTagReferenceBlock_tag_reference);

	TAG_REFERENCE(scenarioDesignerResourceDependenciesBlock_tag_reference);

	TAG_REFERENCE(cheap_particle_emitter_reference, CHEAP_PARTICLE_EMITTER_TAG);

	TAG_REFERENCE(cinematic_reference, CINEMATIC_TAG);

	TAG_REFERENCE(scenario_budget_references_block_reference_reference);

	TAG_REFERENCE(model_reference$5, MODEL_TAG);

	TAG_REFERENCE_GROUP(PuppetHeaderStruct_type_reference, _tag_reference_flag_not_a_dependency)
	{
		BIPED_TAG,
		CHARACTER_TAG,
		CRATE_TAG,
		DEVICE_MACHINE_TAG,
		SCENERY_TAG,
		VEHICLE_TAG,
		INVALID_TAG,
	};

	TAG_REFERENCE(model_animation_graph_reference$3, MODEL_ANIMATION_GRAPH_TAG, _tag_reference_flag_not_a_dependency);

	TAG_REFERENCE_GROUP(PuppetSubActionPointStruct_asset_reference)
	{
		EFFECT_TAG,
		SOUND_TAG,
		SOUND_LOOPING_TAG,
		AI_MISSION_DIALOGUE_TAG,
		INVALID_TAG,
	};

	TAG_REFERENCE(scenario_required_resource_reference, SCENARIO_REQUIRED_RESOURCE_TAG);

	TAG_REFERENCE(variant_globals_reference, VARIANT_GLOBALS_TAG);

	TAG_REFERENCE(scenery_reference$5, SCENERY_TAG);

	TAG_REFERENCE(wave_template_reference$2, WAVE_TEMPLATE_TAG);

	TAG_REFERENCE_GROUP(structureBspFxMarkerBlock_optional_attached_effect_reference)
	{
		EFFECT_TAG,
		LENS_FLARE_TAG,
		INVALID_TAG,
	};

	TAG_REFERENCE(character_reference$7, CHARACTER_TAG, _tag_reference_flag_not_a_dependency);

	TAG_REFERENCE(weapon_reference$8, WEAPON_TAG, _tag_reference_flag_not_a_dependency);

	TAG_REFERENCE(equipment_reference$4, EQUIPMENT_TAG, _tag_reference_flag_not_a_dependency);

	TAG_REFERENCE(vehicle_reference$3, VEHICLE_TAG, _tag_reference_flag_not_a_dependency);

	TAG_REFERENCE(weapon_reference$9, WEAPON_TAG, _tag_reference_flag_not_a_dependency | _tag_reference_flag_dependency_for_cache_file_sharing);

	TAG_REFERENCE(vehicle_reference$4, VEHICLE_TAG, _tag_reference_flag_not_a_dependency | _tag_reference_flag_dependency_for_cache_file_sharing);

	TAG_REFERENCE(projectile_reference$3, PROJECTILE_TAG, _tag_reference_flag_not_a_dependency | _tag_reference_flag_dependency_for_cache_file_sharing);

	TAG_REFERENCE(equipment_reference$5, EQUIPMENT_TAG, _tag_reference_flag_not_a_dependency | _tag_reference_flag_dependency_for_cache_file_sharing);

	TAG_REFERENCE(sound_old_reference, SOUND_OLD_TAG);

	TAG_REFERENCE(sound_reference$4, SOUND_TAG, _tag_reference_flag_resolved_by_game);

	TAG_REFERENCE(squad_template_reference$2, SQUAD_TEMPLATE_TAG);

	TAG_REFERENCE_GROUP(weapon_block_struct_ready_effect_reference)
	{
		SOUND_OLD_TAG,
		EFFECT_TAG,
		INVALID_TAG,
	};

	TAG_REFERENCE(render_model_reference$10, RENDER_MODEL_TAG, _tag_reference_flag_dont_resolve_in_editor);

	TAG_REFERENCE(model_animation_graph_reference$4, MODEL_ANIMATION_GRAPH_TAG, _tag_reference_flag_dont_resolve_in_editor);

	TAG_REFERENCE(vehicle_reference$5, VEHICLE_TAG);

	TAG_REFERENCE(cui_screen_reference, CUI_SCREEN_TAG);

	TAG_REFERENCE(cookie_purchase_globals_reference, COOKIE_PURCHASE_GLOBALS_TAG);

	TAG_REFERENCE(pgcr_enemy_to_category_mapping_definition_reference, PGCR_ENEMY_TO_CATEGORY_MAPPING_DEFINITION_TAG);

	TAG_REFERENCE(pgcr_damage_type_image_mapping_definition_reference, PGCR_DAMAGE_TYPE_IMAGE_MAPPING_DEFINITION_TAG);

	TAG_REFERENCE(portrait_poses_definition_reference, PORTRAIT_POSES_DEFINITION_TAG);

	TAG_REFERENCE(SwapTagReferenceDefinition_original_tag_reference);

	TAG_REFERENCE(user_interface_sounds_definition_reference, USER_INTERFACE_SOUNDS_DEFINITION_TAG);

} // namespace blofeld

