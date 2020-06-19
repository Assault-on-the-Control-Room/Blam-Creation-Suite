#pragma once

namespace blofeld
{

#define MAX_COMPOSITES_PER_GRAPH 256
#define MAX_VALUES_PER_COMPOSITE_ENTRY 16
#define MAX_DEAD_ZONES_PER_COMPOSITE_AXIS 16
#define MAX_ENTRIES_PER_COMPOSITE 256
#define MAX_PHASE_SETS_PER_COMPOSITE 16
#define SHORT_MAX 32767
#define UNSIGNED_SHORT_MAX 65535
#define MAXIMUM_ERROR_REPORT_CATEGORIES 512
#define MAXIMUM_REPORTS_PER_ERROR_REPORT_CATEGORY 1048576
#define MAXIMUM_VERTICES_PER_ERROR_REPORT 1048576
#define MAXIMUM_VECTORS_PER_ERROR_REPORT 1048576
#define MAXIMUM_LINES_PER_ERROR_REPORT 1048576
#define MAXIMUM_TRIANGLES_PER_ERROR_REPORT 1048576
#define MAXIMUM_QUADS_PER_ERROR_REPORT 1048576
#define MAXIMUM_COMMENTS_PER_ERROR_REPORT 1048576
#define MAXIMUM_NUMBER_OF_ANTENNA_VERTICES 20
#define MAXIMUM_SEQUENCES_PER_BITMAP_GROUP 256
#define MAXIMUM_SPRITES_PER_SEQUENCE 128
#define MAXIMUM_BITMAPS_PER_BITMAP_GROUP 65536
#define MAXIMUM_REGIONS_PER_MODEL 32
#define MAXIMUM_PERMUTATIONS_PER_MODEL_REGION 255
#define NUMBER_OF_PROP_CLASSES 14
#define NUMBER_OF_ACTOR_COMBAT_STATUS_LEVELS 10
#define MAX_CINEMATIC_SCENE_COUNT 32
#define MAX_CINEMATIC_SHOT_COUNT 64
#define MAXIMUM_MATERIALS_PER_MODEL 32
#define MAXIMUM_BSPS_PER_COLLISION_REGION 64
#define MAXIMUM_PATHFINDING_SPHERES_PER_COLLISION_MODEL 256
#define MAXIMUM_NODES_PER_MODEL 255
#define MAXIMUM_COLORS_PER_COLOR_TABLE_GROUP 512
#define MAXIMUM_DECORATOR_SETS_PER_SCENARIO 48
#define MAXIMUM_DETAIL_OBJECT_TYPES_PER_COLLECTION 16
#define MAXIMUM_SQUIRTERS_PER_FLUID_DYNAMICS 16
#define MAXIMUM_INFLOWS_PER_FLUID_DYNAMICS 16
#define MAXIMUM_OUTFLOWS_PER_FLUID_DYNAMICS 16
#define MAXIMUM_OBSTACLES_PER_FLUID_DYNAMICS 32
#define MAXIMUM_STATES_PER_MODEL_PERMUTATION 10
#define MAXIMUM_DAMAGE_SECTIONS_PER_MODEL 16
#define MAXIMUM_RESPONSES_PER_DAMAGE_SECTION 16
#define MAXIMUM_DAMAGE_SEAT_INFOS_PER_MODEL 16
#define MAXIMUM_DAMAGE_CONSTRAINT_INFOS_PER_MODEL 16
#define MAXIMUM_MODEL_TARGETS_PER_MODEL 32
#define MAXIMUM_GAME_INCIDENT_RESPONSES_PER_BLOCK 32
#define MAXIMUM_CHALLENGES_TO_PROGRESS_PER_BLOCK 64
#define MAXIMUM_TRACKS_PER_LOOPING_SOUND 4
#define MAXIMUM_DETAIL_SOUNDS_PER_LOOPING_SOUND 12
#define NUMBER_OF_GLOBAL_SOUNDS 2
#define MATERIAL_SHADER_MAX_SOURCE_FILES 256
#define MAXIMUM_MARKER_GROUPS_PER_RENDER_MODEL 4096
#define MAXIMUM_MARKERS_PER_RENDER_MODEL_MARKER_GROUP 256
#define MAXIMUM_MATERIALS_PER_GEOMETRY 1024
#define MAXIMUM_BONE_GROUPS_PER_MODEL 64
#define MAXIMUM_NUMBER_OF_MULTIPLAYER_SCENARIOS 32
#define MAXIMUM_SCENARIO_PLAYERS_PER_BLOCK 256
#define MAXIMUM_WIDGETS_PER_OBJECT 4
#define MAXIMUM_NUMBER_OF_OBJECT_CHANGE_COLOR_INITIAL_PERMUTATIONS 32
#define MAXIMUM_NUMBER_OF_OBJECT_CHANGE_COLOR_FUNCTIONS 4
#define MAXIMUM_VERTICES_PER_GEOMETRY_SECTION 16777214
#define MAXIMUM_ACTORS_PER_PERFORMANCE 16
#define MAXIMUM_LINES_PER_PERFORMANCE 256
#define MAXIMUM_SCRIPT_FRAGMENTS_PER_PERFORMANCE_LINE 16
#define MAXIMUM_POINT_INTERACTIONS_PER_PERFORMANCE_LINE 16
#define MAXIMUM_ANIMATIONS_PER_PERFORMANCE_LINE 8
#define MAXIMUM_SYNC_ACTIONS_PER_PERFORMANCE_LINE 8
#define MAXIMUM_SCENERY_SYNC_ACTIONS_PER_PERFORMANCE_LINE 8
#define MAXIMUM_DIALOG_LINES_PER_PERFORMANCE_LINE 4
#define MAXIMUM_SOUNDS_PER_PERFORMANCE_LINE 4
#define MAXIMUM_STRUCTURE_BSPS_PER_SCENARIO 32
#define MAX_NUM_MOBILE_NAVMESHES 128
#define MAX_NUM_NAV_VOLUMES 256
#define MAX_NUM_NAV_CLIMBS 256
#define LONG_BITS 32
#define MAXIMUM_COLLISION_MATERIALS_PER_STRUCTURE 512
#define MAXIMUM_CLUSTER_PORTALS_PER_STRUCTURE 1000
#define MAXIMUM_VERTICES_PER_CLUSTER_PORTAL 128
#define MAXIMUM_DETAIL_OBJECT_CELLS_PER_STRUCTURE 262144
#define MAXIMUM_DETAIL_OBJECTS_PER_STRUCTURE 2097152
#define MAXIMUM_CLUSTERS_PER_STRUCTURE 255
#define MAXIMUM_CLUSTER_PORTALS_PER_CLUSTER 512
#define MAXIMUM_BLOCKS_PER_CLUSTER 1429968
#define MAXIMUM_MARKERS_PER_STRUCTURE 1024
#define MAXIMUM_SKIES_PER_SCENARIO 32
#define MAXIMUM_DECALS_PER_STRUCTURE 6144
#define MAXIMUM_ENVIRONMENT_OBJECT_PALETTE_ENTRIES_PER_STRUCTURE 1024
#define MAXIMUM_ENVIRONMENT_OBJECTS_PER_STRUCTURE 16384
#define MAXIMUM_FACES_PER_MAP_LEAF 1048576
#define MAXIMUM_VERTICES_PER_LEAF_CONNECTION 512
#define MAXIMUM_CONNECTIONS_PER_MAP_LEAF 1048576
#define MAXIMUM_CONNECTIONS_PER_LEAF_MAP 1073741824
#define MAXIMUM_FOG_PLANES_PER_STRUCTURE 127
#define MAXIMUM_FOG_ZONES_PER_STRUCTURE 127
#define MAXIMUM_CHILD_SCENARIOS_PER_SCENARIO 16
#define MAXIMUM_STRUCTURE_DESIGNS_PER_SCENARIO 8
#define MAXIMUM_FUNCTIONS_PER_SCENARIO 32
#define MAXIMUM_EDITOR_COMMENTS 65536
#define MAXIMUM_ENVIRONMENT_OBJECTS_PER_SCENARIO 4096
#define MAXIMUM_OBJECT_NAMES_PER_SCENARIO 2048
#define MAXIMUM_SCENERY_DATUMS_PER_SCENARIO 2000
#define MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK 256
#define MAXIMUM_BIPED_DATUMS_PER_SCENARIO 256
#define MAXIMUM_VEHICLE_DATUMS_PER_SCENARIO 256
#define MAXIMUM_EQUIPMENT_DATUMS_PER_SCENARIO 256
#define MAXIMUM_WEAPON_DATUMS_PER_SCENARIO 128
#define MAXIMUM_DEVICE_GROUPS_PER_SCENARIO 128
#define MAXIMUM_MACHINE_DATUMS_PER_SCENARIO 400
#define MAXIMUM_TERMINAL_DATUMS_PER_SCENARIO 20
#define MAXIMUM_CONTROL_DATUMS_PER_SCENARIO 100
#define MAXIMUM_DISPENSER_DATUMS_PER_SCENARIO 40
#define MAXIMUM_SOUND_SCENERY_DATUMS_PER_SCENARIO 512
#define MAXIMUM_GIANT_DATUMS_PER_SCENARIO 32
#define MAXIMUM_EFFECT_SCENERY_DATUMS_PER_SCENARIO 512
#define MAXIMUM_SPAWNER_DATUMS_PER_SCENARIO 128
#define MAXIMUM_BINK_PALETTE_ENTRIES_PER_BLOCK 32
#define MAXIMUM_REQUISITION_MENU_SIZE 64
#define MAXIMUM_SCENARIO_SOFT_CEILINGS_PER_SCENARIO 128
#define MAXIMUM_TRIGGER_VOLUMES_PER_SCENARIO 1024
#define MAXIMUM_RECORDED_ANIMATIONS_PER_MAP 1024
#define MAXIMUM_DECALS_PER_SCENARIO 65536
#define MAXIMUM_DECAL_PALETTES_PER_SCENARIO 128
#define MAXIMUM_DETAIL_OBJECT_LAYERS_PER_STRUCTURE 32
#define MAXIMUM_CUTSCENE_FLAGS_PER_SCENARIO 4096
#define MAXIMUM_CUTSCENE_CAMERA_POINTS_PER_SCENARIO 512
#define MAXIMUM_ATMOSPHERE_PALETTE_ENTRIES_PER_STRUCTURE 32
#define MAXIMUM_CAMERA_FX_PALETTE_ENTRIES_PER_STRUCTURE 64
#define MAXIMUM_WEATHER_PALETTE_ENTRIES_PER_STRUCTURE 32
#define MAXIMUM_CRATE_DATUMS_PER_SCENARIO 1536
#define MAXIMUM_SUBTITLES_PER_SCENARIO 1024
#define MAXIMUM_CREATURE_DATUMS_PER_SCENARIO 128
#define MAXIMUM_DECORATOR_PALETTES_PER_SCENARIO 8
#define MAXIMUM_DECORATOR_PLACEMENTS_PER_SET 262144
#define MAXIMUM_SCENARIO_CINEMATICS 32
#define MAXIMUM_PERFORMANCES_PER_SCENARIO 256
#define MAXIMUM_TASKS_PER_PERFORMANCE 8
#define MAX_PUPPETS_PER_SHOW 32
#define MAX_ACTIONS_PER_PUPPET 256
#define MAX_SUB_ACTIONS_PER_PUPPET 256
#define MAX_BRANCHES_PER_SUB_ACTION 8
#define MAX_SUB_TRACKS 20
#define MAX_ACTIONS_PER_SHOW 256
#define MAX_SUB_ACTIONS_PER_SHOW 256
#define MAX_POINTS_PER_PATH 32
#define NUMBER_OF_SOUND_CLASSES 71
#define MAXIMUM_PERMUTATIONS_PER_PITCH_RANGE 32
#define MAXIMUM_PITCH_RANGES_PER_SOUND 17
#define MAXIMUM_MARKERS_PER_PERMUTATION 65535
#define MAXIMUM_SOUND_DATA_SIZE 16777216
#define MAXIMUM_POSTURES_PER_UNIT 20
#define MAXIMUM_DIALOGUE_VARIANTS_PER_UNIT 16
#define MAXIMUM_INITIAL_WEAPONS_PER_UNIT 4
#define MAXIMUM_SEATS_PER_UNIT_DEFINITION 64
#define MAXIMUM_NUMBER_OF_MAGAZINES_PER_WEAPON 2
#define MAXIMUM_NUMBER_OF_MAGAZINE_OBJECTS_PER_MAGAZINE 8
#define MAXIMUM_RULES_PER_CA 16
#define MAXIMUM_STATES_PER_RULE 16
#define BYTE_MAX 255
#define MAXIMUM_NUMBER_OF_UNIT_CAMERA_TRACKS 3
#define WEAPON_SPECIFIC_MARKERS_COUNT 64
#define MAXIMUM_CHARGING_FIRE_FRACTIONS_PER_TRIGGER 16
#define MAXIMUM_DAMAGE_TRANSFERS_PER_MODEL 32
#define NUMBER_OF_OBJECT_TYPES 16
#define MAXIMUM_NODE_INDICES_PER_ERROR_POINT 4


	struct s_numberof_sizeof
	{
		char data[9];
	};
	template<size_t x, typename type>
	s_numberof_sizeof* numberof_sizeof_proxy(type&);

	// manually calculated don't lose difficult 

	constexpr unsigned long k_scenario_designer_zone_palette_count = 17;
	constexpr unsigned long k_maximum_rooms_per_game = 1024;
	constexpr unsigned long k_maximum_audibility_door_count = 128;
	constexpr unsigned long k_int32_bits_bits = 5;

	// #UNCONFRMED: this validation is accepted for any value between 0 and 28, and any multiple of 32. The true value of this isn't known yet!
	const unsigned long k_bsp3d_node_plane_index_bits = 28; 
	static constexpr unsigned long validate_k_bsp3d_node_plane_index_bits = (1 << k_bsp3d_node_plane_index_bits) > (2147483647L >> 2) ? (1 << k_bsp3d_node_plane_index_bits) : (2147483647L >> 2);
	static_assert(validate_k_bsp3d_node_plane_index_bits == 536870911, "k_bsp3d_node_plane_index_bits is invalid value");

	// #UNCONFIRMED: this validation is accepted for any value between 128 and 256
	const unsigned long k_maximum_breakable_surfaces_per_breakable_surface_set = 256;
	constexpr unsigned long validate_k_maximum_breakable_surfaces_per_breakable_surface_set = ((((k_maximum_breakable_surfaces_per_breakable_surface_set)+(k_int32_bits - 1)) >> k_int32_bits_bits));
	static_assert(validate_k_maximum_breakable_surfaces_per_breakable_surface_set == 8, "k_maximum_breakable_surfaces_per_breakable_surface_set is invalid value");

	// already defined in blamlib

	//constexpr unsigned long k_int32_bits = 32;
	//const unsigned long k_uint8_max = 255;

	const unsigned long k_maxEmblemIndicesPerItem = 32;
	const unsigned long k_max_triangulation_tag_triangles = 255;
	const unsigned long k_max_sync_action_groups = 16;
	const unsigned long k_max_sync_actions = 32;
	const unsigned long k_max_sync_action_participants = 6;
	const unsigned long k_max_vehicle_suspensions = 32;
	const unsigned long k_max_function_overlays_per_graph = 32;
	const unsigned long k_max_animation_inheritence_levels = 8;
	const unsigned long k_max_triangulation_tag_points = 255;
	const unsigned long k_firefightWavesPerGoal = 30;
	const unsigned long k_firefightMaxPlayerGoals = 15;
	const unsigned long k_maximum_survival_possible_wave_squads = 12;
	const unsigned long k_cui_max_component_count = 8192;
	const unsigned long k_cui_max_property_binding_count = 1024;
	const unsigned long k_cuiMaxEncapsulationCount = 64;
	const unsigned long k_cui_max_animation_count = 8192;
	const unsigned long k_cui_max_property_count = 8192;
	const unsigned long k_first_person_interface_count = 2;
	const unsigned long k_animation_node_usage_count = 25;
	const unsigned long k_animation_maximum_node_mask_count = 8;
	const unsigned long k_animation_maximum_function_count = 16;
	const unsigned long k_animation_maximum_model_variants = 64;
	const unsigned long k_animation_maximum_mode_or_stance_aliases = 64;
	const unsigned long k_meg = 1048576;
	const unsigned long k_num_ai_trait_weapon = 4;
	const unsigned long k_maximum_number_of_sound_effect_templates = 8;
	const unsigned long k_maximum_number_of_sound_effect_parameters = 128;
	const unsigned long k_max_airprobes_per_scenario = 4096;
	const unsigned long k_maximum_achievements = 256;
	const unsigned long k_dialogue_type_count = 158;
	const unsigned long k_global_formations_count = 128;
	const unsigned long k_global_squad_template_folder_count = 32;
	const unsigned long k_global_squad_templates_count = 128;
	const unsigned long k_global_performance_template_folder_count = 32;
	const unsigned long k_global_performance_templates_count = 128;
	const unsigned long k_max_custom_stimuli_count = 128;
	const unsigned long k_max_ai_cue_templates = 32;
	const unsigned long k_num_ai_trait_vision = 5;
	const unsigned long k_num_ai_trait_sound = 4;
	const unsigned long k_num_ai_trait_luck = 5;
	const unsigned long k_num_ai_trait_grenade = 4;
	const unsigned long k_max_atmosphere_settings = 16;
	const unsigned long k_online_avatar_award_count = 3;
	const unsigned long k_maximum_death_program_special_types = 5;
	const unsigned long k_maximum_death_program_damage_types = 12;
	const unsigned long k_maximum_death_program_velocity_gates = 2;
	const unsigned long k_maximum_trick_definitions_per_unit = 8;
	const unsigned long k_maximum_biped_proximity_feelers = 4;
	const unsigned long k_contact_point_count = 3;
	const unsigned long k_maxBipedSoundRTPCBlocks = 16;
	const unsigned long k_maxBipedSoundSweetenerBlocks = 16;
	const unsigned long k_maximum_aiming_fixup_joints = 2;
	const unsigned long k_maxTightBoundsSets = 5;
	const unsigned long k_maximum_custom_app_count = 64;
	const unsigned long k_maximum_custom_app_damage_modifier_count = 16;
	const unsigned long k_maximum_variants_per_model = 64;
	const unsigned long k_max_movement_sets = 8;
	const unsigned long k_max_movement_variants = 8;
	const unsigned long k_fp_evaluator_count = 69;
	const unsigned long k_campaign_difficulty_levels_count = 4;
	const unsigned long k_character_equipment_usage_when_count = 8;
	const unsigned long k_max_character_stimuli_responses = 16;
	const unsigned long k_roomEnoughToConvertAllExistingCategories = 5;
	const unsigned long k_maximum_challenges_per_category = 200;
	const unsigned long k_maximum_scene_shot_clip_plane_count = 32;
	const unsigned long k_maximum_scene_shot_clip_subject_count = 24;
	const unsigned long k_maximum_collision_spheres_per_cloth = 8;
	const unsigned long k_maximum_vertices_per_cloth = 121;
	const unsigned long k_maximum_indices_per_cloth = 1210;
	const unsigned long k_maximum_links_per_cloth = 1210;
	const unsigned long eCT_count = 2;
	const unsigned long k_max_cookie_purchase_families = 30;
	const unsigned long k_max_cookie_purchase_family_items = 200;
	const unsigned long k_max_cookie_purchase_total_appearance_items = 512;
	const unsigned long k_byte_bits = 8;
	const unsigned long k_max_cookie_purchase_total_loadout_items = 96;
	const unsigned long k_max_cookie_purchase_total_ordnance_items = 32;
	const unsigned long k_kilo = 1024;
	const unsigned long k_maximum_effect_locations_count = 8;
	const unsigned long k_maximum_effect_events_count = 32;
	const unsigned long k_maximum_effect_parts_per_event_count = 32;
	const unsigned long k_maximum_effect_accelerations_per_event_count = 32;
	const unsigned long k_maximum_effect_looping_sounds_count = 2;
	const unsigned long k_effect_holdback_type_max = 26;
	const unsigned long k_effect_priority_max = 6;
	const unsigned long k_equipmentMaxAbilityCount = 5;
	const unsigned long k_maxEquipmentSoundRTPCBlocks = 16;
	const unsigned long k_maxEquipmentSoundSweetenerBlocks = 16;
	const unsigned long k_material_effect_type_count = 24;
	const unsigned long k_maximum_material_effect_blocks = 500;
	const unsigned long k_forge_named_color_count = 8;
	const unsigned long k_max_primitives_per_formation = 4;
	const unsigned long k_max_points_per_primitive = 8;
	const unsigned long k_max_sound_references_per_graph = 4096;
	const unsigned long k_max_effect_references_per_graph = 4096;
	const unsigned long k_max_frame_events = 512;
	const unsigned long k_maximum_game_engine_event_responses = 1000;
	const unsigned long eUGT_count = 8;
	const unsigned long k_maximumNumberOfMultiplayerOrdnanceSelections = 64;
	const unsigned long k_giant_buckle_total_types = 3;
	const unsigned long k_number_of_entry_points = 40;
	const unsigned long k_maximum_game_setting_blocks = 205;
	const unsigned long k_maximum_variant_category_blocks = 16;
	const unsigned long k_havok_group_count = 31;
	const unsigned long k_maximum_objects_per_model_variant = 31;
	const unsigned long k_maximum_muted_nodes_per_model_variant = 31;
	const unsigned long k_maximum_instance_groups_per_model = 256;
	const unsigned long k_maximum_members_per_instance_group = 32;
	const unsigned long k_scenario_load_maximum_parameter_blocks = 32;
	const unsigned long k_maximum_model_game_mode_types = 4;
	const unsigned long k_maximum_hs_source_files_per_context = 128;
	const unsigned long k_maximum_hs_scripts_per_context = 3072;
	const unsigned long k_maximum_hs_parameters_per_script = 16;
	const unsigned long k_maximum_hs_globals_per_context = 768;
	const unsigned long k_maximum_hs_instanced_variables_per_context = 128;
	const unsigned long k_maximum_hs_references_per_context = 1024;
	const unsigned long k_maximum_hs_unit_seat_mappings = 65536;
	const unsigned long k_maximum_hs_syntax_nodes_per_context = 65023;
	const unsigned long k_maximum_instance_geometry_instances_per_structure_bsp = 8192;
	const unsigned long k_infinityMaximumSeasonCount = 3;
	const unsigned long k_infinityMaximumMissionsPerSeason = 55;
	const unsigned long k_max_nodes_per_animation = 255;
	const unsigned long k_max_animations_per_graph = 2048;
	const unsigned long k_maximum_sandbox_property_values = 64;
	const unsigned long k_maximum_text_value_pairs_per_block = 100;
	const unsigned long k_maximum_reflections_per_lens_flare = 32;
	const unsigned long k_maximum_loadouts = 128;
	const unsigned long k_maximum_loadout_palettes = 64;
	const unsigned long k_maximum_loadouts_per_palette = 5;
	const unsigned long k_maximum_loadout_names = 128;
	const unsigned long k_maximum_loadout_custom_slot_count = 5;
	const unsigned long lightRigDirectionalCount = 16;
	const unsigned long k_maximum_leaf_type_definitions = 16;
	const unsigned long k_maximum_streaming_packs = 20;
	const unsigned long k_maximum_campaign_unspatialized_sounds = 64;
	const unsigned long k_maximum_material_types = 512;
	const unsigned long k_button_presets_count = 7;
	const unsigned long k_player_character_type_count = 3;
	const unsigned long k_player_momentum_count = 2;
	const unsigned long k_maximum_editable_material_types = 256;
	const unsigned long k_player_color_index_count = 32;
	const unsigned long k_game_skull_count = 17;
	const unsigned long k_number_of_active_camo_levels = 5;
	const unsigned long k_number_of_platforms = 2;
	const unsigned long k_number_of_vertex_types = 54;
	const unsigned long k_max_lines_per_scenario = 500;
	const unsigned long k_max_variants_per_line = 10;
	const unsigned long k_multiplayer_effect_maximum_count = 2048;
	const unsigned long k_MaxVoiceoverLines = 100;
	const unsigned long k_maximum_instance_placements_per_render_model = 128;
	const unsigned long k_max_volume_samples_per_render_model = 128;
	const unsigned long k_multiplayer_object_type_maximum_count = 2048;
	const unsigned long k_maximum_number_of_multiplayer_weapon_selections = 64;
	const unsigned long k_maximum_number_of_multiplayer_vehicle_selections = 64;
	const unsigned long k_maximum_number_of_multiplayer_grenade_selections = 8;
	const unsigned long k_maximum_number_of_multiplayer_equipment_selections = 32;
	const unsigned long k_maximum_number_of_multiplayer_weapon_sets = 32;
	const unsigned long k_maximum_number_of_multiplayer_remap_table_entries = 32;
	const unsigned long k_maximum_megalo_string_ids = 255;
	const unsigned long kshaderBlockCount = 10240;
	const unsigned long k_multiplayer_team_game_team_count = 8;
	const unsigned long k_maximum_number_of_game_engine_roles = 64;
	const unsigned long k_infinity_requisition_palette_maximum_count = 64;
	const unsigned long k_maximum_multiplayer_sounds = 60;
	const unsigned long k_maximum_status_response_count = 32;
	const unsigned long k_maximum_object_functions = 256;
	const unsigned long k_maximum_number_of_attachments_per_object = 48;
	const unsigned long k_maximum_jetwash_points_per_object = 4;
	const unsigned long k_object_change_color_count = 4;
	const unsigned long k_maximum_multiplayer_object_blocks = 1;
	const unsigned long k_chudPolyArtVertexMaxCount = 32768;
	const unsigned long k_pgcr_maximum_number_of_categories_per_bucket = 128;
	const unsigned long k_pgcr_maximum_number_of_player_entries_per_category = 1;
	const unsigned long k_pgcr_maximum_number_of_ai_entries_per_category = 16;
	const unsigned long k_damage_reporting_type_count = 98;
	const unsigned long k_maximumPlayerEnlistments = 16;
	const unsigned long k_maxPlayerGradeCount = 127;
	const unsigned long k_max_hint_geometries = 1000;
	const unsigned long k_max_climb_hints = 200;
	const unsigned long k_max_flight_hints_per_bsp = 256;
	const unsigned long k_max_points_per_flight_hint = 10;
	const unsigned long k_max_avoidance_volumes_per_bsp = 512;
	const unsigned long k_max_spline_hints_per_bsp = 256;
	const unsigned long k_max_control_points_per_spline_hint = 32;
	const unsigned long k_max_cookie_cutters = 512;
	const unsigned long k_maximum_points_per_sector = 32;
	const unsigned long k_max_navmesh_areas = 512;
	const unsigned long k_maximum_constraints_per_physics_model = 64;
	const unsigned long k_maximum_phantom_types_per_physics_model = 16;
	const unsigned long k_maximum_node_constraint_edges_per_physics_model = 4096;
	const unsigned long k_maximum_rigid_bodies_per_physics_model = 64;
	const unsigned long k_maximum_materials_per_physics_model = 64;
	const unsigned long k_maximum_shapes_per_physics_model = 16384;
	const unsigned long k_maximum_four_vectors_per_physics_model = 24576;
	const unsigned long k_maximum_plane_equations_per_physics_model = 131072;
	const unsigned long k_maximum_inertia_tensors_per_physics_model = 1024;
	const unsigned long k_maximum_list_shapes_per_physics_model = 4096;
	const unsigned long k_maximum_phantoms_per_physics_model = 128;
	const unsigned long k_maximum_cache_file_codecs = 127;
	const unsigned long k_maximum_cache_file_shared_files = 7;
	const unsigned long k_maximum_number_of_model_customization_selections_per_area = 96;
	const unsigned long k_maximum_number_of_model_customization_bits_per_selection = 32;
	const unsigned long k_maxPortraitPoses = 32;
	const unsigned long k_maximum_material_responses = 200;
	const unsigned long k_maxProjectileSoundRTPCBlocks = 16;
	const unsigned long k_dimensions_in_3d_count = 3;
	const unsigned long k_maximumSoundBanksPerTag = 8;
	const unsigned long k_structure_seam_maximum_seam_count = 128;
	const unsigned long k_structure_seam_maximum_edges_count = 32767;
	const unsigned long k_structure_seam_maximum_clusters_on_seam_count = 255;
	static constexpr unsigned long k_bsp3d_node_child_index_bits = 24;
	const unsigned long k_super_node_child_indices_count = 16;
	const unsigned long k_super_node_node_count = 15;
	const unsigned long k_bsp3d_maximum_super_node_count = 2048;
	const unsigned long k_short_max = 32767;
	const unsigned long k_maximum_scenario_object_datum_count = 6304;
	const unsigned long k_max_cubemaps_per_cluster = 32;
	const unsigned long k_max_cubemap_reference_point_count = 15;
	const unsigned long k_maximum_breakable_surface_sets = 2048;
	const unsigned long k_maximum_cluster_sound_palette_entries_per_structure = 128;
	const unsigned long k_maximum_cluster_to_instance_group_block_size = 4096;
	const unsigned long k_external_instanced_geometry_max = 4096;
	const unsigned long k_maximum_sound_combiner_defintion_entry_count = 32;
	const unsigned long k_maximum_machine_door_portal_associations = 128;
	const unsigned long k_maximum_occluding_portal_associations = 128;
	const unsigned long k_maximum_scenario_zone_set_count = 64;
	const unsigned long k_maximum_audibility_room_count = 1024;
	const unsigned long k_maximum_map_variant_palettes = 16;
	const unsigned long k_maximum_map_variant_palette_entries = 256;
	const unsigned long k_maximum_object_variants_per_map_variant_palette_entry = 32;
	const unsigned long k_max_squad_groups_per_map = 130;
	const unsigned long k_maximum_squads_per_map = 256;
	const unsigned long k_maximum_spawn_formations_per_squad = 8;
	const unsigned long k_maximum_spawn_points_per_squad = 128;
	const unsigned long k_max_zones_per_map = 128;
	const unsigned long k_max_firing_positions_per_zone = 2048;
	const unsigned long k_max_areas_per_zone = 128;
	const unsigned long k_max_flight_references_per_area = 10;
	const unsigned long k_max_squad_patrols_per_map = 16;
	const unsigned long k_max_members_per_squad_patrol = 64;
	const unsigned long k_max_points_per_squad_patrol = 48;
	const unsigned long k_max_squad_patrol_transitions = 256;
	const unsigned long k_max_squad_patrol_waypoints_per_transition = 10;
	const unsigned long k_max_ai_cues_per_level = 256;
	const unsigned long k_max_task_distributions_per_cue = 16;
	const unsigned long k_max_scenes_per_scenario = 100;
	const unsigned long k_max_roles_per_scene = 10;
	const unsigned long k_max_point_sets_per_map = 200;
	const unsigned long k_max_animation_points_per_map = 256;
	const unsigned long k_maximum_scenario_cutscene_titles = 128;
	const unsigned long k_maximum_areas_per_task = 64;
	const unsigned long k_max_flock_instances_per_map = 50;
	const unsigned long k_max_sources_per_flock = 10;
	const unsigned long k_max_destinations_per_flock = 10;
	const unsigned long k_maximum_scenario_editor_folders = 32767;
	const unsigned long k_maximum_objectives_per_map = 64;
	const unsigned long k_maximum_opposing_objectives = 4;
	const unsigned long k_maximum_tasks_per_objective = 100;
	const unsigned long k_max_points_per_task_direction = 8;
	const unsigned long k_maximum_designer_zone_count = 64;
	const unsigned long e_scriptableLightRigMax = 128;
	const unsigned long k_maximum_scenario_cinematic_lighting_palette_entry_count = 128;
	const unsigned long k_maximum_campaign_metagame_scenario_completion_bonus_count = 8;
	const unsigned long k_max_cubemaps_per_scenario = 1024;
	const unsigned long k_maximum_budget_references_per_scenario = 128;
	const unsigned long k_maximum_scenario_ordnance_drop_sets = 32;
	const unsigned long k_maximum_random_ordnance_drop_points = 256;
	const unsigned long k_maximum_unit_recordings_per_scenario = 32;
	const unsigned long k_maximum_random_ordnance_items = 24;
	const unsigned long k_maximum_instance_geometry_definitions_per_structure_bsp = 2048;
	const unsigned long k_maximum_interpolators_per_scenario = 32;
	const unsigned long k_global_wave_templates_count = 128;
	const unsigned long k_language_count = 17;
	const unsigned long k_maximum_cells_per_squad = 10;
	const unsigned long k_maximum_palette_choices = 8;
	const unsigned long k_spawn_influencer_type_count = 16;
	const unsigned long k_vehicle_spawn_influencer_maximum_count = 18;
	const unsigned long k_projectile_spawn_influencer_maximum_count = 32;
	const unsigned long k_equipment_spawn_influencer_maximum_count = 18;
	const unsigned long k_maximum_behavior_count = 256;
	const unsigned long k_maximum_number_of_camera_track_control_points = 16;
	const unsigned long k_maximum_sound_cache_file_gestalt_permutations = 1048575;
	const unsigned long k_maximum_sound_cache_file_gestalt_permutation_languages = 1048575;
	const unsigned long k_player_training_count = 35;
	const unsigned long k_maximumNumberOfStyleSheets = 64;
	const unsigned long k_maximum_multilingual_unicode_strings_per_string_list = 34816;
	const unsigned long k_maximum_strings_per_string_list = 2048;
	const unsigned long k_maximumHudUnitSoundCues = 16;
	const unsigned long k_powered_seats_count = 2;
	const unsigned long k_maxSoundRTPCBlocks = 16;
	const unsigned long k_maxSoundSweetenerBlocks = 16;
	const unsigned long k_max_vehicle_physics_transitions = 4;
	const unsigned long k_max_squad_specifications_per_wave = 16;
	const unsigned long k_melee_damage_class_count = 2;
	const unsigned long k_weapon_trigger_count = 2;
	const unsigned long k_weapon_barrel_count = 2;
	const unsigned long k_projectile_maximum_custom_vectors = 16;
	const unsigned long k_first_person_weapon_offset_type_count = 3;
	const unsigned long k_weapon_barrel_effect_count = 5;
	const unsigned long k_maxWeaponSoundRTPCBlocks = 16;
	const unsigned long k_maxWeaponSoundSweetenerBlocks = 16;
	const unsigned long k_maximum_game_engine_static_loadout_palettes = 6;
	const unsigned long k_survival_full_rounds_per_set = 3;
	const unsigned long k_maximum_survival_custom_skulls = 3;
	const unsigned long k_maximum_number_of_screen_widgets = 256;
	const unsigned long k_cui_max_overlay_count = 24;
	const unsigned long k_maximum_cache_file_tag_resource_types = 16;
	const unsigned long k_numberOfResourcePriorities = 3;
	const unsigned long k_maximum_simultaneous_tag_instances = 32767;
	const unsigned long k_maximum_categories_per_resource = 32;
	const unsigned long k_maximum_category_rows_per_resource = 128;
	const unsigned long k_maximum_tag_parentages_count = 65534;
	const unsigned long k_maximum_number_of_platform_sound_playback_components = 16;
	const unsigned long k_max_biped_grab_object_animation_sets = 16;
	const unsigned long k_structure_seam_maximum_points_count = 32767;
	const unsigned long k_structure_seam_maximum_planes_count = 32767;
	const unsigned long k_structure_seam_maximum_triangles_count = 32767;
	const unsigned long k_maximum_structure_soft_ceilings_count = 128;
	const unsigned long k_maximum_structure_soft_ceiling_triangles = 32767;
	const unsigned long k_maximum_structure_water_groups = 1024;
	const unsigned long k_maximum_structure_water_instances = 1024;
	const unsigned long k_maximum_structure_water_instance_planes = 1024;
	const unsigned long k_maximum_structure_water_instance_debug_triangles = 8192;
	const unsigned long k_maximum_structure_manifest_items_count = 64;
	const unsigned long k_maximum_promotion_rules_per_sound = 17;
	const unsigned long k_maximum_sound_equalizer_bands = 3;
	const unsigned long k_vertices_per_triangle_count = 3;
	const unsigned long k_maximum_anti_gravity_points_per_vehicle_physics_definition = 16;
	const unsigned long k_maximum_friction_points_per_vehicle_physics_definition = 16;
	const unsigned long k_animation_maximum_blend_screens = 1024;
	const unsigned long k_max_tracked_feet = 32;
	const unsigned long k_max_cycles_per_tracked_foot = 64;
	const unsigned long k_max_fik_anchor_node_count = 5;
	const unsigned long k_animation_maximum_ik_chain_events = 32;
	const unsigned long k_animation_maximum_ik_chain_proxies = 8;
	const unsigned long k_animation_maximum_facial_wrinkle_events = 32;
	const unsigned long k_animation_maximum_extended_events = 32;
	const unsigned long k_animation_maximum_object_functions = 4;
	const unsigned long k_animation_maximum_function_overlays = 32;
	const unsigned long k_animation_maximum_overlay_groups = 1056;
	const unsigned long k_animation_maximum_mixing_board_pose_overlays = 10;
	const unsigned long k_animation_maximum_gaits = 32;
	const unsigned long k_animation_maximum_gait_groups = 32;
	const unsigned long k_max_ik_points = 64;
	const unsigned long k_max_ik_sets = 32;
	const unsigned long k_max_ik_points_per_set = 8;
	const unsigned long k_animation_maximum_ik_chains = 4;
	const unsigned long k_max_modes_per_graph = 512;
	const unsigned long k_max_weapon_classes = 64;
	const unsigned long k_max_object_space_offset_node_count = 16;
	const unsigned long k_max_weapon_types = 64;
	const unsigned long k_max_animation_sets = 64;
	const unsigned long k_max_animations_per_block = 256;
	const unsigned long k_max_death_and_damage_actions = 8;
	const unsigned long k_total_damage_directions = 4;
	const unsigned long k_total_damage_regions = 11;
	const unsigned long k_max_transition_animations = 32;
	const unsigned long k_max_ranged_actions = 16;
	const unsigned long k_max_gpu_properties = 17;
	const unsigned long k_max_gpu_functions = 25;
	const unsigned long k_max_gpu_colors = 8;
	const unsigned long k_max_radial_distributions_per_cue = 1;
	const unsigned long k_max_probability_distributions_per_cue = 1;
	const unsigned long k_max_character_distributions_per_cue = 8;
	const unsigned long k_max_weapon_distributions_per_cue = 8;
	const unsigned long k_hash_size = 20;
	const unsigned long k_maximum_number_of_object_salts = 32;
	const unsigned long k_dual_vmf_basis_real_coefficients_count = 16;
	const unsigned long k_animation_maximum_velocity_boundary_entries = 8;
	const unsigned long k_number_of_model_states = 5;
	const unsigned long k_vertices_per_line_count = 2;
	const unsigned long k_vertices_per_quadrilateral_count = 4;

	constexpr int k_maximum_number_of_vertex_buffers_per_mesh = 8;
	constexpr int k_maximum_number_of_index_buffers_per_mesh = 2;

	struct s_mesh
	{
		short vertex_buffer_indices[k_maximum_number_of_vertex_buffers_per_mesh];
		short index_buffer_indices[k_maximum_number_of_index_buffers_per_mesh];
	};
	struct s_material_postprocess_definition
	{
		static const unsigned long k_runtime_queryable_properties_count = 12;
	};
	struct c_particle_emitter_gpu
	{
		static const unsigned long _sizeof_gpu_property = 16;
		static const unsigned long _sizeof_gpu_function = 64;
		static const unsigned long _sizeof_gpu_color = 16;
	};
	struct c_cinematic_shot_flags
	{
		static const unsigned long k_flag_chunk_count = 2;
	};
	struct c_node_flags
	{
		static const unsigned long k_flag_chunk_count = 8;
	};
	struct s_render_method_postprocess_definition
	{
		static const unsigned long k_runtime_queryable_properties_count = 28;
	};
	struct c_rasterizer_constant_table_definition
	{
		static const unsigned long k_max_constants = 426;
	};
	struct MedalAggregatorEntry
	{
		static const unsigned long k_medalAggregatorEntryMaxCount = 12;
	};
	struct c_tag_resource_prediction_table_base
	{
		static const unsigned long k_maximum_mapped_molecules = 8192;
	};
	struct s_cui_expression_step_definition
	{
		static const unsigned long k_maximum_step_count = 32;
	};
	struct s_walker_physics_definition
	{
		static const unsigned long k_maximum_leg_count = 32;
	};
	struct s_vehicle_engine_definition
	{
		static const unsigned long k_gear_count_max = 16;
		static const unsigned long k_load_and_cruise_looping_sound_max = 2;
	};
	struct c_particle_definition
	{
		struct s_gpu_data
		{
			struct s_frames
			{
				char data[256];
			};
		};
	};
	struct s_planer_fog_set_definition
	{
		static const unsigned long k_maximum_planar_fog_count = 128;
	};
	struct s_planar_fog_definition
	{
		static const unsigned long k_maximum_triangle_count = 512;
	};
	struct Composite
	{
		static const unsigned long MAX_SYNC_KEYS = 8;
	};
	struct CommandDispatcher
	{
		static const unsigned long MAX_LINKS = 6;
	};
	struct s_single_achivement_restricted_level_definition
	{
		static constexpr unsigned long k_maximum_count = 5;
	};
	struct AirStrikeDefinition
	{
		static constexpr unsigned long k_max_airstrike_batteries = 1;
	};
	struct s_airstrike_battery_definition
	{
		static constexpr unsigned long max_fire_locations = 16;
	};
	struct c_particle_system_definition
	{
		static constexpr unsigned long k_maximum_particle_systems_per_block = 32;
		static constexpr unsigned long k_maximum_emitters_per_definition = 8;
	};
	struct c_character_voice_properties_internal
	{
		static constexpr unsigned long k_block_count = 1;
	};
	struct c_character_general_properties_internal
	{
		static constexpr unsigned long k_block_count = 1;
	};
	struct c_character_proto_spawn_properties_internal
	{
		static constexpr unsigned long k_block_count = 1;
	};
	struct c_character_interact_properties_internal
	{
		static constexpr unsigned long k_block_count = 1;
	};
	struct c_character_emotions_properties_internal
	{
		static constexpr unsigned long k_block_count = 1;
	};
	struct c_character_vitality_properties_internal
	{
		static constexpr unsigned long k_block_count = 1;
	};
	struct c_character_placement_properties_internal
	{
		static constexpr unsigned long k_block_count = 1;
	};
	struct c_character_perception_properties_internal
	{
		static constexpr unsigned long k_block_count = 8;
	};
	struct c_character_target_properties_internal
	{
		static constexpr unsigned long k_block_count = 1;
	};
	struct c_character_look_properties_internal
	{
		static constexpr unsigned long k_block_count = 1;
	};
	struct c_character_throttle_style_properties_internal
	{
		static constexpr unsigned long k_block_count = 256;
	};
	struct c_character_flocking_properties_internal
	{
		static constexpr unsigned long k_block_count = 1;
	};
	struct c_character_swarm_properties_internal
	{
		static constexpr unsigned long k_block_count = 1;
	};
	struct c_character_firing_point_evaluation_properties_internal
	{
		static constexpr unsigned long k_block_count = 11;
	};
	struct c_character_ready_properties_internal
	{
		static constexpr unsigned long k_block_count = 1;
	};
	struct c_character_engage_properties_internal
	{
		static constexpr unsigned long k_block_count = 1;
	};
	struct c_character_charge_properties_internal
	{
		static constexpr unsigned long k_block_count = 1;
	};
	struct c_character_evasion_properties_internal
	{
		static constexpr unsigned long k_block_count = 1;
	};
	struct c_character_cover_properties_internal
	{
		static constexpr unsigned long k_block_count = 1;
	};
	struct c_character_retreat_properties_internal
	{
		static constexpr unsigned long k_block_count = 1;
	};
	struct c_character_search_properties_internal
	{
		static constexpr unsigned long k_block_count = 1;
	};
	struct c_character_presearch_properties_internal
	{
		static constexpr unsigned long k_block_count = 1;
	};
	struct c_character_idle_properties_internal
	{
		static constexpr unsigned long k_block_count = 1;
	};
	struct c_character_vocalization_properties_internal
	{
		static constexpr unsigned long k_block_count = 1;
	};
	struct c_character_boarding_properties_internal
	{
		static constexpr unsigned long k_block_count = 1;
	};
	struct s_character_vehicle_boarding_properties
	{
		static constexpr unsigned long k_block_count = 32;
	};
	struct c_character_kungfu_properties_internal
	{
		static constexpr unsigned long k_block_count = 1;
	};
	struct c_character_bunker_properties_internal
	{
		static constexpr unsigned long k_block_count = 1;
	};
	struct c_character_guardian_properties_internal
	{
		static constexpr unsigned long k_block_count = 1;
	};
	struct c_character_combatform_properties_internal
	{
		static constexpr unsigned long k_block_count = 1;
	};
	struct c_character_engineer_properties_internal
	{
		static constexpr unsigned long k_block_count = 1;
	};
	struct c_character_inspect_properties_internal
	{
		static constexpr unsigned long k_block_count = 1;
	};
	struct c_character_scarab_properties_internal
	{
		static constexpr unsigned long k_block_count = 1;
	};
	struct c_character_weapon_properties_internal
	{
		static constexpr unsigned long k_block_count = 100;
	};
	struct c_character_firing_pattern_properties_internal
	{
		static constexpr unsigned long k_block_count = 100;
	};
	struct c_character_grenade_properties_internal
	{
		static constexpr unsigned long k_block_count = 10;
	};
	struct c_character_vehicle_properties_internal
	{
		static constexpr unsigned long k_block_count = 100;
	};
	struct c_character_flying_movement_properties_internal
	{
		static constexpr unsigned long k_block_count = 32;
	};
	struct c_character_morph_properties_internal
	{
		static constexpr unsigned long k_block_count = 1;
	};
	struct c_character_pain_screen_properties_internal
	{
		static constexpr unsigned long k_block_count = 1;
	};
	struct c_character_bishop_properties_internal
	{
		static constexpr unsigned long k_block_count = 1;
	};
	struct c_character_combotron_parent_properties_internal
	{
		static constexpr unsigned long k_block_count = 1;
	};
	struct c_character_combotron_child_properties_internal
	{
		static constexpr unsigned long k_block_count = 1;
	};
	struct c_character_handle_dismemberment_properties_internal
	{
		static constexpr unsigned long k_block_count = 1;
	};
	struct c_character_cover_fight_properties_internal
	{
		static constexpr unsigned long k_block_count = 1;
	};
	struct c_character_emerge_properties_internal
	{
		static constexpr unsigned long k_block_count = 1;
	};
	struct c_character_dynamic_task_properties_internal
	{
		static constexpr unsigned long k_block_count = 1;
	};
	struct c_character_advance_properties_internal
	{
		static constexpr unsigned long k_block_count = 1;
	};
	struct c_character_cover_evasion_properties_internal
	{
		static constexpr unsigned long k_block_count = 1;
	};
	struct c_character_pack_stalk_properties_internal
	{
		static constexpr unsigned long k_block_count = 1;
	};
	struct c_character_fight_circle_properties_internal
	{
		static constexpr unsigned long k_block_count = 1;
	};
	struct c_character_hamstring_charge_properties_internal
	{
		static constexpr unsigned long k_block_count = 1;
	};
	struct c_character_forerunner_properties_internal
	{
		static constexpr unsigned long k_block_count = 1;
	};
	struct c_character_gravity_jump_properties_internal
	{
		static constexpr unsigned long k_block_count = 1;
	};
	struct CommendationAggregator
	{
		static constexpr unsigned long k_commendationAggregatorMaxCount = 64;
	};
	struct CommendationAggregatorDependent
	{
		static constexpr unsigned long k_commendationDependentMaxCount = 12;
	};
	struct CommendationDefinition
	{
		static constexpr unsigned long k_maximumCommendationDefinitions = 160;
	};
	struct CommendationLevel
	{
		static constexpr unsigned long k_maximumCommendationLevels = 10;
	};
	struct RewardGlobalDefinition
	{
		static constexpr unsigned long k_maximum_count = 256;
	};
	struct s_cheap_particle_type
	{
		static constexpr unsigned long k_maximum_types = 255;
	};
	struct s_cheap_particle_type_library
	{
		static constexpr unsigned long k_max_textures = 63;
	};
	struct CheapParticleTurbulenceType
	{
		static constexpr unsigned long k_maxTypes = 8;
	};
	struct c_decal_system_definition
	{
		static constexpr unsigned long k_max_decal = 16;
	};
	struct s_particle_emitter_boat_hull_shape_data
	{
		static constexpr unsigned long k_max_groups_per_hull_shape = 16;
	};
	struct EquipmentAbilityTypeEquipmentHacker
	{
		struct DrainLevel
		{
			static constexpr unsigned long k_maxLevels = 8;
		};
	};
	struct FirefightWaveTemplateDefinition
	{
		static constexpr unsigned long k_maximumAIWaveTemplates = 128;
	};
	struct s_fx_test
	{
		static constexpr unsigned long k_max_properties = 256;
		static constexpr unsigned long k_max_defaults = 64;
	};
	struct s_game_completion_rewards_globals
	{
		static constexpr unsigned long k_max_falloff_curve_points = 15;
	};
	struct c_render_method_definition
	{
		static constexpr unsigned long k_maximum_categories = 16;
		static constexpr unsigned long k_maximum_category_options = 32;
		static constexpr unsigned long k_maximum_entry_points = 32;
	};
	struct GameMedalTierDefinition
	{
		static constexpr unsigned long k_maximumGameMedalTierDefinitions = 10;
	};
	struct s_game_medal_definition
	{
		static constexpr unsigned long k_maximum_game_medal_definitions = 256;
	};
	struct s_incident_definition
	{
		static constexpr unsigned long k_maximum_incidents_per_definition = 1000;
	};
	struct s_location_name_globals_tag_definition
	{
		static constexpr unsigned long k_maximum_location_names = 255;
	};
	struct c_light_volume_system_definition
	{
		static constexpr unsigned long k_max_light_volume = 16;
	};
	struct c_light_volume_definition
	{
		static constexpr unsigned long k_max_precompiled_profiles = 128;
	};
	struct s_material_shader_parameter
	{
		static constexpr unsigned long k_max_material_shader_parameters = 111;
	};
	struct c_material
	{
		static constexpr unsigned long k_maximum_postprocess_textures = 32;
	};
	struct s_damage_globals_definition
	{
		static constexpr unsigned long k_numBlockElements = 2;
	};
	struct MedalChallengeAggregator
	{
		static constexpr unsigned long k_medalChallengeAggregatorMaxCount = 64;
	};
	struct MedalCommendationAggregator
	{
		static constexpr unsigned long k_medalCommendationAggregatorMaxCount = 64;
	};
	struct s_emblem_library
	{
		static constexpr unsigned long k_max_bitmap_list_count = 256;
		static constexpr unsigned long k_max_shape_list_count = 512;
		static constexpr unsigned long k_max_front_emblem_count = 256;
		static constexpr unsigned long k_max_back_emblem_count = 256;
	};
	struct s_mux_generator
	{
		static constexpr unsigned long k_max_materials = 16;
	};
	struct ObjectFunctionSwitchDefinition
	{
		struct Function
		{
			static constexpr unsigned long k_maxCount = 8;
		};
		static constexpr unsigned long k_maxCount = 32;
	};
	struct s_water_physics_model
	{
		static constexpr unsigned long k_maximum_hull_surfaces_count = 64;
	};
	struct ModelDissolveDefinition
	{
		static constexpr unsigned long eTT_count = 13;
	};
	struct PolyartIndex
	{
		static constexpr unsigned long k_chudPolyArtIndexMaxCount = 32768;
	};
	struct s_particle_emitter_custom_points
	{
		static constexpr unsigned long k_maximum_points = 32768;
	};
	struct c_particle_movement_definition
	{
		static constexpr unsigned long k_type_count = 6;
		static constexpr unsigned long k_flocking_parameter_count = 9;
	};
	struct c_render_method
	{
		static constexpr unsigned long k_maximum_parameters = 64;
		static constexpr unsigned long k_maximum_postprocess_textures = 64;
	};
	struct c_render_method_template
	{
		static constexpr unsigned long k_maximum_routing_info = 512;
		static constexpr unsigned long k_maximum_passes = 64;
	};
	struct c_render_method_option
	{
		static constexpr unsigned long k_maximum_parameters = 32;
	};
	struct ScenarioAttachedEffect
	{
		static constexpr unsigned long k_maxLoopingEffectsAllowed = 1024;
		static constexpr unsigned long k_maxLensFlaresAllowed = 1024;
	};
	struct ScenarioAttachedLightCone
	{
		static constexpr unsigned long k_maxLightConesAllowed = 512;
	};
	struct s_scenario_acoustic_sector
	{
		static constexpr unsigned long k_maximum_scenario_acoustic_sectors = 300;
	};
	struct s_scenario_acoustic_transition
	{
		static constexpr unsigned long k_maximum_scenario_acoustic_transitions = 300;
	};
	struct s_scenario_atmosphere_dumpling
	{
		static constexpr unsigned long k_maximum_scenario_atmosphere_dumplings = 100;
	};
	struct s_scenario_weather_dumpling
	{
		static constexpr unsigned long k_maximum_scenario_weather_dumplings = 100;
	};
	struct s_scenario_named_location_volume
	{
		static constexpr unsigned long k_maximum_scenario_named_location_volumes = 128;
	};
	struct s_scenario_cheap_particle_emitter_palette_entry
	{
		static constexpr unsigned long k_maximum_scenario_cheap_particle_system_palette_entries = 20;
	};
	struct s_scenario_cheap_particle_system
	{
		static constexpr unsigned long k_maximum_scenario_cheap_particle_systems = 100;
	};
	struct s_area_screen_effect_definition
	{
		static constexpr unsigned long k_maximum_effects_per_tag = 8;
	};
	struct SelfIlluminationDefinition
	{
		static constexpr unsigned long MAX_STATES = 16;
	};
	struct SilentAssistGlobals
	{
		static constexpr unsigned long k_maxSilentAssistLevel = 3;
	};
	struct _terminal_definition
	{
		static constexpr unsigned long k_max_page_count = 32;
	};
	struct TracerSystemDefinition
	{
		static constexpr unsigned long k_maxTracers = 16;
	};
	struct VisionModeScreenPass
	{
		static constexpr unsigned long k_maxCount = 1;
	};
	struct VisionModeEnvironmentPass
	{
		static constexpr unsigned long k_maxCount = 1;
	};
	struct VisionModeBipedPasses
	{
		static constexpr unsigned long k_maxCount = 1;
	};
	struct VisionModeBipedPass
	{
		static constexpr unsigned long k_maxCount = 3;
	};
	struct VisionModeBipedThreat
	{
		static constexpr unsigned long k_maxCount = 1;
	};
	struct VisionModeOrdnanceVehiclePass
	{
		static constexpr unsigned long k_maxCount = 1;
	};
	struct VisionModeOrdnanceVehicleType
	{
		static constexpr unsigned long k_maxCount = 64;
	};
	struct VisionModeOrdnanceCrosshair
	{
		static constexpr unsigned long k_maxCount = 1;
	};
	struct s_variant_globals_definition
	{
		static constexpr unsigned long k_variant_globals_per_block_count_maximum = 1024;
		static constexpr unsigned long k_hopper_files_maximum_count = 300;
	};
	struct WeaponScaleshotLevelDefinition
	{
		static constexpr unsigned long k_maxLevels = 10;
	};
	struct s_cui_player_model_camera_settings_definition
	{
		static constexpr unsigned long k_maximum_count = 32;
	};
	struct s_cui_player_model_control_settings_definition
	{
		static constexpr unsigned long k_maximum_count = 32;
	};
	struct s_cui_player_model_transition_settings_definition
	{
		static constexpr unsigned long k_maximum_count = 1;
	};
	struct s_cui_active_roster_settings_definition
	{
		static constexpr unsigned long k_max_count = 1;
	};
	struct s_campaign_state_screen_script
	{
		static constexpr unsigned long k_max_count = 64;
	};
	struct UserInterfaceGameScreenSequenceStep
	{
		static constexpr unsigned long k_maxCount = 5;
	};
	struct SwapTagReferences
	{
		static constexpr unsigned long k_maxCount = 128;
	};
	struct s_color_preset
	{
		static constexpr unsigned long k_maximum_color_presets = 64;
	};
	struct s_gui_alert_description
	{
		static constexpr unsigned long k_maximum_gui_error_types_count = 512;
	};
	struct s_gui_dialog_description
	{
		static constexpr unsigned long k_maximum_gui_dialog_types_count = 256;
	};
	struct s_cui_pgcr_incident
	{
		static constexpr unsigned long k_maximum_count = 50;
	};

}
