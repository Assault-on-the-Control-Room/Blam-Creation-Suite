#pragma once

#if defined(BLOFELD_TAG_DEFINITIONS) && BLOFELD_TAG_DEFINITIONS
#define BLOFELD_CONST_ARGS engine_type
#endif

namespace blofeld
{
	class c_constant
	{
	public:
		c_constant(const char* name, uint32_t value);
		c_constant(const char* name, std::initializer_list<std::pair<e_engine_type, uint32_t>> list);
		c_constant(std::initializer_list<std::pair<e_engine_type, std::pair<const char*, uint32_t>>> list);

		uint32_t operator()(e_engine_type engine_type)
		{
			return values[engine_type].second;
		}

		mutable  std::pair<const char*, uint32_t> values[k_number_of_engine_types];
	};

	// manually calculated don't lose difficult 

	extern c_constant k_scenario_designer_zone_palette_count;
	extern c_constant k_maximum_rooms_per_game;
	extern c_constant k_maximum_audibility_door_count;
	extern c_constant k_bsp3d_node_plane_index_bits;
	extern c_constant k_maximum_breakable_surfaces_per_breakable_surface_set;

	// defines

	extern c_constant SHORT_MAX;
	extern c_constant UNSIGNED_SHORT_MAX;
	extern c_constant LONG_BITS;
	extern c_constant BYTE_MAX;
	extern c_constant MAX_COMPOSITES_PER_GRAPH;
	extern c_constant MAX_VALUES_PER_COMPOSITE_ENTRY;
	extern c_constant MAX_DEAD_ZONES_PER_COMPOSITE_AXIS;
	extern c_constant MAX_ENTRIES_PER_COMPOSITE;
	extern c_constant MAX_PHASE_SETS_PER_COMPOSITE;
	extern c_constant MAXIMUM_ERROR_REPORT_CATEGORIES;
	extern c_constant MAXIMUM_REPORTS_PER_ERROR_REPORT_CATEGORY;
	extern c_constant MAXIMUM_VERTICES_PER_ERROR_REPORT;
	extern c_constant MAXIMUM_VECTORS_PER_ERROR_REPORT;
	extern c_constant MAXIMUM_LINES_PER_ERROR_REPORT;
	extern c_constant MAXIMUM_TRIANGLES_PER_ERROR_REPORT;
	extern c_constant MAXIMUM_QUADS_PER_ERROR_REPORT;
	extern c_constant MAXIMUM_COMMENTS_PER_ERROR_REPORT;
	extern c_constant MAXIMUM_NUMBER_OF_ANTENNA_VERTICES;
	extern c_constant MAXIMUM_SEQUENCES_PER_BITMAP_GROUP;
	extern c_constant MAXIMUM_SPRITES_PER_SEQUENCE;
	extern c_constant MAXIMUM_BITMAPS_PER_BITMAP_GROUP;
	extern c_constant MAXIMUM_REGIONS_PER_MODEL;
	extern c_constant MAXIMUM_PERMUTATIONS_PER_MODEL_REGION;
	extern c_constant NUMBER_OF_PROP_CLASSES;
	extern c_constant NUMBER_OF_ACTOR_COMBAT_STATUS_LEVELS;
	extern c_constant MAX_CINEMATIC_SCENE_COUNT;
	extern c_constant MAX_CINEMATIC_SHOT_COUNT;
	extern c_constant MAXIMUM_MATERIALS_PER_MODEL;
	extern c_constant MAXIMUM_BSPS_PER_COLLISION_REGION;
	extern c_constant MAXIMUM_PATHFINDING_SPHERES_PER_COLLISION_MODEL;
	extern c_constant MAXIMUM_NODES_PER_MODEL;
	extern c_constant MAXIMUM_COLORS_PER_COLOR_TABLE_GROUP;
	extern c_constant MAXIMUM_DECORATOR_SETS_PER_SCENARIO;
	extern c_constant MAXIMUM_DETAIL_OBJECT_TYPES_PER_COLLECTION;
	extern c_constant MAXIMUM_SQUIRTERS_PER_FLUID_DYNAMICS;
	extern c_constant MAXIMUM_INFLOWS_PER_FLUID_DYNAMICS;
	extern c_constant MAXIMUM_OUTFLOWS_PER_FLUID_DYNAMICS;
	extern c_constant MAXIMUM_OBSTACLES_PER_FLUID_DYNAMICS;
	extern c_constant MAXIMUM_STATES_PER_MODEL_PERMUTATION;
	extern c_constant MAXIMUM_DAMAGE_SECTIONS_PER_MODEL;
	extern c_constant MAXIMUM_RESPONSES_PER_DAMAGE_SECTION;
	extern c_constant MAXIMUM_DAMAGE_SEAT_INFOS_PER_MODEL;
	extern c_constant MAXIMUM_DAMAGE_CONSTRAINT_INFOS_PER_MODEL;
	extern c_constant MAXIMUM_MODEL_TARGETS_PER_MODEL;
	extern c_constant MAXIMUM_GAME_INCIDENT_RESPONSES_PER_BLOCK;
	extern c_constant MAXIMUM_CHALLENGES_TO_PROGRESS_PER_BLOCK;
	extern c_constant MAXIMUM_TRACKS_PER_LOOPING_SOUND;
	extern c_constant MAXIMUM_DETAIL_SOUNDS_PER_LOOPING_SOUND;
	extern c_constant NUMBER_OF_GLOBAL_SOUNDS;
	extern c_constant MATERIAL_SHADER_MAX_SOURCE_FILES;
	extern c_constant MAXIMUM_MARKER_GROUPS_PER_RENDER_MODEL;
	extern c_constant MAXIMUM_MARKERS_PER_RENDER_MODEL_MARKER_GROUP;
	extern c_constant MAXIMUM_MATERIALS_PER_GEOMETRY;
	extern c_constant MAXIMUM_BONE_GROUPS_PER_MODEL;
	extern c_constant MAXIMUM_NUMBER_OF_MULTIPLAYER_SCENARIOS;
	extern c_constant MAXIMUM_SCENARIO_PLAYERS_PER_BLOCK;
	extern c_constant MAXIMUM_WIDGETS_PER_OBJECT;
	extern c_constant MAXIMUM_NUMBER_OF_OBJECT_CHANGE_COLOR_INITIAL_PERMUTATIONS;
	extern c_constant MAXIMUM_NUMBER_OF_OBJECT_CHANGE_COLOR_FUNCTIONS;
	extern c_constant MAXIMUM_VERTICES_PER_GEOMETRY_SECTION;
	extern c_constant MAXIMUM_ACTORS_PER_PERFORMANCE;
	extern c_constant MAXIMUM_LINES_PER_PERFORMANCE;
	extern c_constant MAXIMUM_SCRIPT_FRAGMENTS_PER_PERFORMANCE_LINE;
	extern c_constant MAXIMUM_POINT_INTERACTIONS_PER_PERFORMANCE_LINE;
	extern c_constant MAXIMUM_ANIMATIONS_PER_PERFORMANCE_LINE;
	extern c_constant MAXIMUM_SYNC_ACTIONS_PER_PERFORMANCE_LINE;
	extern c_constant MAXIMUM_SCENERY_SYNC_ACTIONS_PER_PERFORMANCE_LINE;
	extern c_constant MAXIMUM_DIALOG_LINES_PER_PERFORMANCE_LINE;
	extern c_constant MAXIMUM_SOUNDS_PER_PERFORMANCE_LINE;
	extern c_constant MAXIMUM_STRUCTURE_BSPS_PER_SCENARIO;
	extern c_constant MAX_NUM_MOBILE_NAVMESHES;
	extern c_constant MAX_NUM_NAV_VOLUMES;
	extern c_constant MAX_NUM_NAV_CLIMBS;
	extern c_constant MAXIMUM_COLLISION_MATERIALS_PER_STRUCTURE;
	extern c_constant MAXIMUM_CLUSTER_PORTALS_PER_STRUCTURE;
	extern c_constant MAXIMUM_VERTICES_PER_CLUSTER_PORTAL;
	extern c_constant MAXIMUM_DETAIL_OBJECT_CELLS_PER_STRUCTURE;
	extern c_constant MAXIMUM_DETAIL_OBJECTS_PER_STRUCTURE;
	extern c_constant MAXIMUM_CLUSTERS_PER_STRUCTURE;
	extern c_constant MAXIMUM_CLUSTER_PORTALS_PER_CLUSTER;
	extern c_constant MAXIMUM_BLOCKS_PER_CLUSTER;
	extern c_constant MAXIMUM_MARKERS_PER_STRUCTURE;
	extern c_constant MAXIMUM_SKIES_PER_SCENARIO;
	extern c_constant MAXIMUM_DECALS_PER_STRUCTURE;
	extern c_constant MAXIMUM_ENVIRONMENT_OBJECT_PALETTE_ENTRIES_PER_STRUCTURE;
	extern c_constant MAXIMUM_ENVIRONMENT_OBJECTS_PER_STRUCTURE;
	extern c_constant MAXIMUM_FACES_PER_MAP_LEAF;
	extern c_constant MAXIMUM_VERTICES_PER_LEAF_CONNECTION;
	extern c_constant MAXIMUM_CONNECTIONS_PER_MAP_LEAF;
	extern c_constant MAXIMUM_CONNECTIONS_PER_LEAF_MAP;
	extern c_constant MAXIMUM_FOG_PLANES_PER_STRUCTURE;
	extern c_constant MAXIMUM_FOG_ZONES_PER_STRUCTURE;
	extern c_constant MAXIMUM_CHILD_SCENARIOS_PER_SCENARIO;
	extern c_constant MAXIMUM_STRUCTURE_DESIGNS_PER_SCENARIO;
	extern c_constant MAXIMUM_FUNCTIONS_PER_SCENARIO;
	extern c_constant MAXIMUM_EDITOR_COMMENTS;
	extern c_constant MAXIMUM_ENVIRONMENT_OBJECTS_PER_SCENARIO;
	extern c_constant MAXIMUM_OBJECT_NAMES_PER_SCENARIO;
	extern c_constant MAXIMUM_SCENERY_DATUMS_PER_SCENARIO;
	extern c_constant MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK;
	extern c_constant MAXIMUM_BIPED_DATUMS_PER_SCENARIO;
	extern c_constant MAXIMUM_VEHICLE_DATUMS_PER_SCENARIO;
	extern c_constant MAXIMUM_EQUIPMENT_DATUMS_PER_SCENARIO;
	extern c_constant MAXIMUM_WEAPON_DATUMS_PER_SCENARIO;
	extern c_constant MAXIMUM_DEVICE_GROUPS_PER_SCENARIO;
	extern c_constant MAXIMUM_MACHINE_DATUMS_PER_SCENARIO;
	extern c_constant MAXIMUM_TERMINAL_DATUMS_PER_SCENARIO;
	extern c_constant MAXIMUM_CONTROL_DATUMS_PER_SCENARIO;
	extern c_constant MAXIMUM_DISPENSER_DATUMS_PER_SCENARIO;
	extern c_constant MAXIMUM_SOUND_SCENERY_DATUMS_PER_SCENARIO;
	extern c_constant MAXIMUM_GIANT_DATUMS_PER_SCENARIO;
	extern c_constant MAXIMUM_EFFECT_SCENERY_DATUMS_PER_SCENARIO;
	extern c_constant MAXIMUM_SPAWNER_DATUMS_PER_SCENARIO;
	extern c_constant MAXIMUM_BINK_PALETTE_ENTRIES_PER_BLOCK;
	extern c_constant MAXIMUM_REQUISITION_MENU_SIZE;
	extern c_constant MAXIMUM_SCENARIO_SOFT_CEILINGS_PER_SCENARIO;
	extern c_constant MAXIMUM_TRIGGER_VOLUMES_PER_SCENARIO;
	extern c_constant MAXIMUM_RECORDED_ANIMATIONS_PER_MAP;
	extern c_constant MAXIMUM_DECALS_PER_SCENARIO;
	extern c_constant MAXIMUM_DECAL_PALETTES_PER_SCENARIO;
	extern c_constant MAXIMUM_DETAIL_OBJECT_LAYERS_PER_STRUCTURE;
	extern c_constant MAXIMUM_CUTSCENE_FLAGS_PER_SCENARIO;
	extern c_constant MAXIMUM_CUTSCENE_CAMERA_POINTS_PER_SCENARIO;
	extern c_constant MAXIMUM_ATMOSPHERE_PALETTE_ENTRIES_PER_STRUCTURE;
	extern c_constant MAXIMUM_CAMERA_FX_PALETTE_ENTRIES_PER_STRUCTURE;
	extern c_constant MAXIMUM_WEATHER_PALETTE_ENTRIES_PER_STRUCTURE;
	extern c_constant MAXIMUM_CRATE_DATUMS_PER_SCENARIO;
	extern c_constant MAXIMUM_SUBTITLES_PER_SCENARIO;
	extern c_constant MAXIMUM_CREATURE_DATUMS_PER_SCENARIO;
	extern c_constant MAXIMUM_DECORATOR_PALETTES_PER_SCENARIO;
	extern c_constant MAXIMUM_DECORATOR_PLACEMENTS_PER_SET;
	extern c_constant MAXIMUM_SCENARIO_CINEMATICS;
	extern c_constant MAXIMUM_PERFORMANCES_PER_SCENARIO;
	extern c_constant MAXIMUM_TASKS_PER_PERFORMANCE;
	extern c_constant MAX_PUPPETS_PER_SHOW;
	extern c_constant MAX_ACTIONS_PER_PUPPET;
	extern c_constant MAX_SUB_ACTIONS_PER_PUPPET;
	extern c_constant MAX_BRANCHES_PER_SUB_ACTION;
	extern c_constant MAX_SUB_TRACKS;
	extern c_constant MAX_ACTIONS_PER_SHOW;
	extern c_constant MAX_SUB_ACTIONS_PER_SHOW;
	extern c_constant MAX_POINTS_PER_PATH;
	extern c_constant NUMBER_OF_SOUND_CLASSES;
	extern c_constant MAXIMUM_PERMUTATIONS_PER_PITCH_RANGE;
	extern c_constant MAXIMUM_PITCH_RANGES_PER_SOUND;
	extern c_constant MAXIMUM_MARKERS_PER_PERMUTATION;
	extern c_constant MAXIMUM_SOUND_DATA_SIZE;
	extern c_constant MAXIMUM_POSTURES_PER_UNIT;
	extern c_constant MAXIMUM_DIALOGUE_VARIANTS_PER_UNIT;
	extern c_constant MAXIMUM_INITIAL_WEAPONS_PER_UNIT;
	extern c_constant MAXIMUM_SEATS_PER_UNIT_DEFINITION;
	extern c_constant MAXIMUM_NUMBER_OF_MAGAZINES_PER_WEAPON;
	extern c_constant MAXIMUM_NUMBER_OF_MAGAZINE_OBJECTS_PER_MAGAZINE;
	extern c_constant MAXIMUM_RULES_PER_CA;
	extern c_constant MAXIMUM_STATES_PER_RULE;
	extern c_constant MAXIMUM_NUMBER_OF_UNIT_CAMERA_TRACKS;
	extern c_constant WEAPON_SPECIFIC_MARKERS_COUNT;
	extern c_constant MAXIMUM_CHARGING_FIRE_FRACTIONS_PER_TRIGGER;
	extern c_constant MAXIMUM_DAMAGE_TRANSFERS_PER_MODEL;
	extern c_constant NUMBER_OF_OBJECT_TYPES;
	extern c_constant MAXIMUM_NODE_INDICES_PER_ERROR_POINT;

	extern c_constant k_maxEmblemIndicesPerItem;
	extern c_constant k_max_triangulation_tag_triangles;
	extern c_constant k_max_sync_action_groups;
	extern c_constant k_max_sync_actions;
	extern c_constant k_max_sync_action_participants;
	extern c_constant k_max_vehicle_suspensions;
	extern c_constant k_max_function_overlays_per_graph;
	extern c_constant k_max_animation_inheritence_levels;
	extern c_constant k_max_triangulation_tag_points;
	extern c_constant k_firefightWavesPerGoal;
	extern c_constant k_firefightMaxPlayerGoals;
	extern c_constant k_maximum_survival_possible_wave_squads;
	extern c_constant k_cui_max_component_count;
	extern c_constant k_cui_max_property_binding_count;
	extern c_constant k_cuiMaxEncapsulationCount;
	extern c_constant k_cui_max_animation_count;
	extern c_constant k_cui_max_property_count;
	extern c_constant k_first_person_interface_count;
	extern c_constant k_animation_node_usage_count;
	extern c_constant k_animation_maximum_node_mask_count;
	extern c_constant k_animation_maximum_function_count;
	extern c_constant k_animation_maximum_model_variants;
	extern c_constant k_animation_maximum_mode_or_stance_aliases;
	extern c_constant k_meg;
	extern c_constant k_num_ai_trait_weapon;
	extern c_constant k_maximum_number_of_sound_effect_templates;
	extern c_constant k_maximum_number_of_sound_effect_parameters;
	extern c_constant k_max_airprobes_per_scenario;
	extern c_constant k_maximum_achievements;
	extern c_constant k_dialogue_type_count;
	extern c_constant k_global_formations_count;
	extern c_constant k_global_squad_template_folder_count;
	extern c_constant k_global_squad_templates_count;
	extern c_constant k_global_performance_template_folder_count;
	extern c_constant k_global_performance_templates_count;
	extern c_constant k_max_custom_stimuli_count;
	extern c_constant k_max_ai_cue_templates;
	extern c_constant k_num_ai_trait_vision;
	extern c_constant k_num_ai_trait_sound;
	extern c_constant k_num_ai_trait_luck;
	extern c_constant k_num_ai_trait_grenade;
	extern c_constant k_max_atmosphere_settings;
	extern c_constant k_online_avatar_award_count;
	extern c_constant k_maximum_death_program_special_types;
	extern c_constant k_maximum_death_program_damage_types;
	extern c_constant k_maximum_death_program_velocity_gates;
	extern c_constant k_maximum_trick_definitions_per_unit;
	extern c_constant k_maximum_biped_proximity_feelers;
	extern c_constant k_contact_point_count;
	extern c_constant k_maxBipedSoundRTPCBlocks;
	extern c_constant k_maxBipedSoundSweetenerBlocks;
	extern c_constant k_maximum_aiming_fixup_joints;
	extern c_constant k_maxTightBoundsSets;
	extern c_constant k_maximum_custom_app_count;
	extern c_constant k_maximum_custom_app_damage_modifier_count;
	extern c_constant k_maximum_variants_per_model;
	extern c_constant k_max_movement_sets;
	extern c_constant k_max_movement_variants;
	extern c_constant k_fp_evaluator_count;
	extern c_constant k_campaign_difficulty_levels_count;
	extern c_constant k_character_equipment_usage_when_count;
	extern c_constant k_max_character_stimuli_responses;
	extern c_constant k_roomEnoughToConvertAllExistingCategories;
	extern c_constant k_maximum_challenges_per_category;
	extern c_constant k_maximum_scene_shot_clip_plane_count;
	extern c_constant k_maximum_scene_shot_clip_subject_count;
	extern c_constant k_maximum_collision_spheres_per_cloth;
	extern c_constant k_maximum_vertices_per_cloth;
	extern c_constant k_maximum_indices_per_cloth;
	extern c_constant k_maximum_links_per_cloth;
	extern c_constant eCT_count;
	extern c_constant k_max_cookie_purchase_families;
	extern c_constant k_max_cookie_purchase_family_items;
	extern c_constant k_max_cookie_purchase_total_appearance_items;
	extern c_constant k_byte_bits;
	extern c_constant k_max_cookie_purchase_total_loadout_items;
	extern c_constant k_max_cookie_purchase_total_ordnance_items;
	extern c_constant k_kilo;
	extern c_constant k_maximum_effect_locations_count;
	extern c_constant k_maximum_effect_events_count;
	extern c_constant k_maximum_effect_parts_per_event_count;
	extern c_constant k_maximum_effect_accelerations_per_event_count;
	extern c_constant k_maximum_effect_looping_sounds_count;
	extern c_constant k_effect_holdback_type_max;
	extern c_constant k_effect_priority_max;
	extern c_constant k_equipmentMaxAbilityCount;
	extern c_constant k_maxEquipmentSoundRTPCBlocks;
	extern c_constant k_maxEquipmentSoundSweetenerBlocks;
	extern c_constant k_material_effect_type_count;
	extern c_constant k_maximum_material_effect_blocks;
	extern c_constant k_forge_named_color_count;
	extern c_constant k_max_primitives_per_formation;
	extern c_constant k_max_points_per_primitive;
	extern c_constant k_max_sound_references_per_graph;
	extern c_constant k_max_effect_references_per_graph;
	extern c_constant k_max_frame_events;
	extern c_constant k_maximum_game_engine_event_responses;
	extern c_constant eUGT_count;
	extern c_constant k_maximumNumberOfMultiplayerOrdnanceSelections;
	extern c_constant k_giant_buckle_total_types;
	extern c_constant k_number_of_entry_points;
	extern c_constant k_maximum_game_setting_blocks;
	extern c_constant k_maximum_variant_category_blocks;
	extern c_constant k_havok_group_count;
	extern c_constant k_maximum_objects_per_model_variant;
	extern c_constant k_maximum_muted_nodes_per_model_variant;
	extern c_constant k_maximum_instance_groups_per_model;
	extern c_constant k_maximum_members_per_instance_group;
	extern c_constant k_scenario_load_maximum_parameter_blocks;
	extern c_constant k_maximum_model_game_mode_types;
	extern c_constant k_maximum_hs_source_files_per_context;
	extern c_constant k_maximum_hs_scripts_per_context;
	extern c_constant k_maximum_hs_parameters_per_script;
	extern c_constant k_maximum_hs_globals_per_context;
	extern c_constant k_maximum_hs_instanced_variables_per_context;
	extern c_constant k_maximum_hs_references_per_context;
	extern c_constant k_maximum_hs_unit_seat_mappings;
	extern c_constant k_maximum_hs_syntax_nodes_per_context;
	extern c_constant k_maximum_instance_geometry_instances_per_structure_bsp;
	extern c_constant k_infinityMaximumSeasonCount;
	extern c_constant k_infinityMaximumMissionsPerSeason;
	extern c_constant k_max_nodes_per_animation;
	extern c_constant k_max_animations_per_graph;
	extern c_constant k_maximum_sandbox_property_values;
	extern c_constant k_maximum_text_value_pairs_per_block;
	extern c_constant k_maximum_reflections_per_lens_flare;
	extern c_constant k_maximum_loadouts;
	extern c_constant k_maximum_loadout_palettes;
	extern c_constant k_maximum_loadouts_per_palette;
	extern c_constant k_maximum_loadout_names;
	extern c_constant k_maximum_loadout_custom_slot_count;
	extern c_constant lightRigDirectionalCount;
	extern c_constant k_maximum_leaf_type_definitions;
	extern c_constant k_maximum_streaming_packs;
	extern c_constant k_maximum_campaign_unspatialized_sounds;
	extern c_constant k_maximum_material_types;
	extern c_constant k_button_presets_count;
	extern c_constant k_player_character_type_count;
	extern c_constant k_player_momentum_count;
	extern c_constant k_maximum_editable_material_types;
	extern c_constant k_player_color_index_count;
	extern c_constant k_game_skull_count;
	extern c_constant k_number_of_active_camo_levels;
	extern c_constant k_number_of_platforms;
	extern c_constant k_number_of_vertex_types;
	extern c_constant k_max_lines_per_scenario;
	extern c_constant k_max_variants_per_line;
	extern c_constant k_multiplayer_effect_maximum_count;
	extern c_constant k_MaxVoiceoverLines;
	extern c_constant k_maximum_instance_placements_per_render_model;
	extern c_constant k_max_volume_samples_per_render_model;
	extern c_constant k_multiplayer_object_type_maximum_count;
	extern c_constant k_maximum_number_of_multiplayer_weapon_selections;
	extern c_constant k_maximum_number_of_multiplayer_vehicle_selections;
	extern c_constant k_maximum_number_of_multiplayer_grenade_selections;
	extern c_constant k_maximum_number_of_multiplayer_equipment_selections;
	extern c_constant k_maximum_number_of_multiplayer_weapon_sets;
	extern c_constant k_maximum_number_of_multiplayer_remap_table_entries;
	extern c_constant k_maximum_megalo_string_ids;
	extern c_constant kshaderBlockCount;
	extern c_constant k_multiplayer_team_game_team_count;
	extern c_constant k_maximum_number_of_game_engine_roles;
	extern c_constant k_infinity_requisition_palette_maximum_count;
	extern c_constant k_maximum_multiplayer_sounds;
	extern c_constant k_maximum_status_response_count;
	extern c_constant k_maximum_object_functions;
	extern c_constant k_maximum_number_of_attachments_per_object;
	extern c_constant k_maximum_jetwash_points_per_object;
	extern c_constant k_object_change_color_count;
	extern c_constant k_maximum_multiplayer_object_blocks;
	extern c_constant k_chudPolyArtVertexMaxCount;
	extern c_constant k_pgcr_maximum_number_of_categories_per_bucket;
	extern c_constant k_pgcr_maximum_number_of_player_entries_per_category;
	extern c_constant k_pgcr_maximum_number_of_ai_entries_per_category;
	extern c_constant k_damage_reporting_type_count;
	extern c_constant k_maximumPlayerEnlistments;
	extern c_constant k_maxPlayerGradeCount;
	extern c_constant k_max_hint_geometries;
	extern c_constant k_max_climb_hints;
	extern c_constant k_max_flight_hints_per_bsp;
	extern c_constant k_max_points_per_flight_hint;
	extern c_constant k_max_avoidance_volumes_per_bsp;
	extern c_constant k_max_spline_hints_per_bsp;
	extern c_constant k_max_control_points_per_spline_hint;
	extern c_constant k_max_cookie_cutters;
	extern c_constant k_maximum_points_per_sector;
	extern c_constant k_max_navmesh_areas;
	extern c_constant k_maximum_constraints_per_physics_model;
	extern c_constant k_maximum_phantom_types_per_physics_model;
	extern c_constant k_maximum_node_constraint_edges_per_physics_model;
	extern c_constant k_maximum_rigid_bodies_per_physics_model;
	extern c_constant k_maximum_materials_per_physics_model;
	extern c_constant k_maximum_shapes_per_physics_model;
	extern c_constant k_maximum_four_vectors_per_physics_model;
	extern c_constant k_maximum_plane_equations_per_physics_model;
	extern c_constant k_maximum_inertia_tensors_per_physics_model;
	extern c_constant k_maximum_list_shapes_per_physics_model;
	extern c_constant k_maximum_phantoms_per_physics_model;
	extern c_constant k_maximum_cache_file_codecs;
	extern c_constant k_maximum_cache_file_shared_files;
	extern c_constant k_maximum_number_of_model_customization_selections_per_area;
	extern c_constant k_maximum_number_of_model_customization_bits_per_selection;
	extern c_constant k_maxPortraitPoses;
	extern c_constant k_maximum_material_responses;
	extern c_constant k_maxProjectileSoundRTPCBlocks;
	extern c_constant k_dimensions_in_3d_count;
	extern c_constant k_maximumSoundBanksPerTag;
	extern c_constant k_structure_seam_maximum_seam_count;
	extern c_constant k_structure_seam_maximum_edges_count;
	extern c_constant k_structure_seam_maximum_clusters_on_seam_count;
	extern c_constant k_bsp3d_node_child_index_bits;
	extern c_constant k_super_node_child_indices_count;
	extern c_constant k_super_node_node_count;
	extern c_constant k_bsp3d_maximum_super_node_count;
	extern c_constant k_short_max;
	extern c_constant k_maximum_scenario_object_datum_count;
	extern c_constant k_max_cubemaps_per_cluster;
	extern c_constant k_max_cubemap_reference_point_count;
	extern c_constant k_maximum_breakable_surface_sets;
	extern c_constant k_maximum_cluster_sound_palette_entries_per_structure;
	extern c_constant k_maximum_cluster_to_instance_group_block_size;
	extern c_constant k_external_instanced_geometry_max;
	extern c_constant k_maximum_sound_combiner_defintion_entry_count;
	extern c_constant k_maximum_machine_door_portal_associations;
	extern c_constant k_maximum_occluding_portal_associations;
	extern c_constant k_maximum_scenario_zone_set_count;
	extern c_constant k_maximum_audibility_room_count;
	extern c_constant k_maximum_map_variant_palettes;
	extern c_constant k_maximum_map_variant_palette_entries;
	extern c_constant k_maximum_object_variants_per_map_variant_palette_entry;
	extern c_constant k_max_squad_groups_per_map;
	extern c_constant k_maximum_squads_per_map;
	extern c_constant k_maximum_spawn_formations_per_squad;
	extern c_constant k_maximum_spawn_points_per_squad;
	extern c_constant k_max_zones_per_map;
	extern c_constant k_max_firing_positions_per_zone;
	extern c_constant k_max_areas_per_zone;
	extern c_constant k_max_flight_references_per_area;
	extern c_constant k_max_squad_patrols_per_map;
	extern c_constant k_max_members_per_squad_patrol;
	extern c_constant k_max_points_per_squad_patrol;
	extern c_constant k_max_squad_patrol_transitions;
	extern c_constant k_max_squad_patrol_waypoints_per_transition;
	extern c_constant k_max_ai_cues_per_level;
	extern c_constant k_max_task_distributions_per_cue;
	extern c_constant k_max_scenes_per_scenario;
	extern c_constant k_max_roles_per_scene;
	extern c_constant k_max_point_sets_per_map;
	extern c_constant k_max_animation_points_per_map;
	extern c_constant k_maximum_scenario_cutscene_titles;
	extern c_constant k_maximum_areas_per_task;
	extern c_constant k_max_flock_instances_per_map;
	extern c_constant k_max_sources_per_flock;
	extern c_constant k_max_destinations_per_flock;
	extern c_constant k_maximum_scenario_editor_folders;
	extern c_constant k_maximum_objectives_per_map;
	extern c_constant k_maximum_opposing_objectives;
	extern c_constant k_maximum_tasks_per_objective;
	extern c_constant k_max_points_per_task_direction;
	extern c_constant k_maximum_designer_zone_count;
	extern c_constant e_scriptableLightRigMax;
	extern c_constant k_maximum_scenario_cinematic_lighting_palette_entry_count;
	extern c_constant k_maximum_campaign_metagame_scenario_completion_bonus_count;
	extern c_constant k_max_cubemaps_per_scenario;
	extern c_constant k_maximum_budget_references_per_scenario;
	extern c_constant k_maximum_scenario_ordnance_drop_sets;
	extern c_constant k_maximum_random_ordnance_drop_points;
	extern c_constant k_maximum_unit_recordings_per_scenario;
	extern c_constant k_maximum_random_ordnance_items;
	extern c_constant k_maximum_instance_geometry_definitions_per_structure_bsp;
	extern c_constant k_maximum_interpolators_per_scenario;
	extern c_constant k_global_wave_templates_count;
	extern c_constant k_language_count;
	extern c_constant k_maximum_cells_per_squad;
	extern c_constant k_maximum_palette_choices;
	extern c_constant k_spawn_influencer_type_count;
	extern c_constant k_vehicle_spawn_influencer_maximum_count;
	extern c_constant k_projectile_spawn_influencer_maximum_count;
	extern c_constant k_equipment_spawn_influencer_maximum_count;
	extern c_constant k_maximum_behavior_count;
	extern c_constant k_maximum_number_of_camera_track_control_points;
	extern c_constant k_maximum_sound_cache_file_gestalt_permutations;
	extern c_constant k_maximum_sound_cache_file_gestalt_permutation_languages;
	extern c_constant k_player_training_count;
	extern c_constant k_maximumNumberOfStyleSheets;
	extern c_constant k_maximum_multilingual_unicode_strings_per_string_list;
	extern c_constant k_maximum_strings_per_string_list;
	extern c_constant k_maximumHudUnitSoundCues;
	extern c_constant k_powered_seats_count;
	extern c_constant k_maxSoundRTPCBlocks;
	extern c_constant k_maxSoundSweetenerBlocks;
	extern c_constant k_max_vehicle_physics_transitions;
	extern c_constant k_max_squad_specifications_per_wave;
	extern c_constant k_melee_damage_class_count;
	extern c_constant k_weapon_trigger_count;
	extern c_constant k_weapon_barrel_count;
	extern c_constant k_projectile_maximum_custom_vectors;
	extern c_constant k_first_person_weapon_offset_type_count;
	extern c_constant k_weapon_barrel_effect_count;
	extern c_constant k_maxWeaponSoundRTPCBlocks;
	extern c_constant k_maxWeaponSoundSweetenerBlocks;
	extern c_constant k_maximum_game_engine_static_loadout_palettes;
	extern c_constant k_survival_full_rounds_per_set;
	extern c_constant k_maximum_survival_custom_skulls;
	extern c_constant k_maximum_number_of_screen_widgets;
	extern c_constant k_cui_max_overlay_count;
	extern c_constant k_maximum_cache_file_tag_resource_types;
	extern c_constant k_numberOfResourcePriorities;
	extern c_constant k_maximum_simultaneous_tag_instances;
	extern c_constant k_maximum_categories_per_resource;
	extern c_constant k_maximum_category_rows_per_resource;
	extern c_constant k_maximum_tag_parentages_count;
	extern c_constant k_maximum_number_of_platform_sound_playback_components;
	extern c_constant k_max_biped_grab_object_animation_sets;
	extern c_constant k_structure_seam_maximum_points_count;
	extern c_constant k_structure_seam_maximum_planes_count;
	extern c_constant k_structure_seam_maximum_triangles_count;
	extern c_constant k_maximum_structure_soft_ceilings_count;
	extern c_constant k_maximum_structure_soft_ceiling_triangles;
	extern c_constant k_maximum_structure_water_groups;
	extern c_constant k_maximum_structure_water_instances;
	extern c_constant k_maximum_structure_water_instance_planes;
	extern c_constant k_maximum_structure_water_instance_debug_triangles;
	extern c_constant k_maximum_structure_manifest_items_count;
	extern c_constant k_maximum_promotion_rules_per_sound;
	extern c_constant k_maximum_sound_equalizer_bands;
	extern c_constant k_vertices_per_triangle_count;
	extern c_constant k_maximum_anti_gravity_points_per_vehicle_physics_definition;
	extern c_constant k_maximum_friction_points_per_vehicle_physics_definition;
	extern c_constant k_animation_maximum_blend_screens;
	extern c_constant k_max_tracked_feet;
	extern c_constant k_max_cycles_per_tracked_foot;
	extern c_constant k_max_fik_anchor_node_count;
	extern c_constant k_animation_maximum_ik_chain_events;
	extern c_constant k_animation_maximum_ik_chain_proxies;
	extern c_constant k_animation_maximum_facial_wrinkle_events;
	extern c_constant k_animation_maximum_extended_events;
	extern c_constant k_animation_maximum_object_functions;
	extern c_constant k_animation_maximum_function_overlays;
	extern c_constant k_animation_maximum_overlay_groups;
	extern c_constant k_animation_maximum_mixing_board_pose_overlays;
	extern c_constant k_animation_maximum_gaits;
	extern c_constant k_animation_maximum_gait_groups;
	extern c_constant k_max_ik_points;
	extern c_constant k_max_ik_sets;
	extern c_constant k_max_ik_points_per_set;
	extern c_constant k_animation_maximum_ik_chains;
	extern c_constant k_max_modes_per_graph;
	extern c_constant k_max_weapon_classes;
	extern c_constant k_max_object_space_offset_node_count;
	extern c_constant k_max_weapon_types;
	extern c_constant k_max_animation_sets;
	extern c_constant k_max_animations_per_block;
	extern c_constant k_max_death_and_damage_actions;
	extern c_constant k_total_damage_directions;
	extern c_constant k_total_damage_regions;
	extern c_constant k_max_transition_animations;
	extern c_constant k_max_ranged_actions;
	extern c_constant k_max_gpu_properties;
	extern c_constant k_max_gpu_functions;
	extern c_constant k_max_gpu_colors;
	extern c_constant k_max_radial_distributions_per_cue;
	extern c_constant k_max_probability_distributions_per_cue;
	extern c_constant k_max_character_distributions_per_cue;
	extern c_constant k_max_weapon_distributions_per_cue;
	extern c_constant k_hash_size;
	extern c_constant k_maximum_number_of_object_salts;
	extern c_constant k_dual_vmf_basis_real_coefficients_count;
	extern c_constant k_animation_maximum_velocity_boundary_entries;
	extern c_constant k_number_of_model_states;
	extern c_constant k_vertices_per_line_count;
	extern c_constant k_vertices_per_quadrilateral_count;
	extern c_constant k_int32_bits_bits;
	extern c_constant k_model_flag_chunk_count; // based on c_node_flags::k_model_flag_chunk_count but with fixups
	
	struct s_numberof_sizeof
	{
		char data[9];
	};
	template<size_t x, typename type>
	s_numberof_sizeof* numberof_sizeof_proxy(type&);




















	// already defined in blamlib

	//constexpr unsigned long k_int32_bits = 32;
	//const unsigned long k_uint8_max = 255;



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
		static c_constant k_flag_chunk_count;
	};
	struct c_node_flags
	{
		static c_constant k_flag_chunk_count;
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














#if defined(BLOFELD_TAG_DEFINITIONS) && BLOFELD_TAG_DEFINITIONS

#define BLOFELD_CONST_ARGS engine_type

// manually calculated don't lose difficult 

#define k_scenario_designer_zone_palette_count k_scenario_designer_zone_palette_count(BLOFELD_CONST_ARGS)
#define k_maximum_rooms_per_game k_maximum_rooms_per_game(BLOFELD_CONST_ARGS)
#define k_maximum_audibility_door_count k_maximum_audibility_door_count(BLOFELD_CONST_ARGS)
#define k_bsp3d_node_plane_index_bits k_bsp3d_node_plane_index_bits(BLOFELD_CONST_ARGS)
#define k_maximum_breakable_surfaces_per_breakable_surface_set k_maximum_breakable_surfaces_per_breakable_surface_set(BLOFELD_CONST_ARGS)

// defines

#define SHORT_MAX SHORT_MAX(BLOFELD_CONST_ARGS)
#define UNSIGNED_SHORT_MAX UNSIGNED_SHORT_MAX(BLOFELD_CONST_ARGS)
#define LONG_BITS LONG_BITS(BLOFELD_CONST_ARGS)
#define BYTE_MAX BYTE_MAX(BLOFELD_CONST_ARGS)
#define MAX_COMPOSITES_PER_GRAPH MAX_COMPOSITES_PER_GRAPH(BLOFELD_CONST_ARGS)
#define MAX_VALUES_PER_COMPOSITE_ENTRY MAX_VALUES_PER_COMPOSITE_ENTRY(BLOFELD_CONST_ARGS)
#define MAX_DEAD_ZONES_PER_COMPOSITE_AXIS MAX_DEAD_ZONES_PER_COMPOSITE_AXIS(BLOFELD_CONST_ARGS)
#define MAX_ENTRIES_PER_COMPOSITE MAX_ENTRIES_PER_COMPOSITE(BLOFELD_CONST_ARGS)
#define MAX_PHASE_SETS_PER_COMPOSITE MAX_PHASE_SETS_PER_COMPOSITE(BLOFELD_CONST_ARGS)
#define MAXIMUM_ERROR_REPORT_CATEGORIES MAXIMUM_ERROR_REPORT_CATEGORIES(BLOFELD_CONST_ARGS)
#define MAXIMUM_REPORTS_PER_ERROR_REPORT_CATEGORY MAXIMUM_REPORTS_PER_ERROR_REPORT_CATEGORY(BLOFELD_CONST_ARGS)
#define MAXIMUM_VERTICES_PER_ERROR_REPORT MAXIMUM_VERTICES_PER_ERROR_REPORT(BLOFELD_CONST_ARGS)
#define MAXIMUM_VECTORS_PER_ERROR_REPORT MAXIMUM_VECTORS_PER_ERROR_REPORT(BLOFELD_CONST_ARGS)
#define MAXIMUM_LINES_PER_ERROR_REPORT MAXIMUM_LINES_PER_ERROR_REPORT(BLOFELD_CONST_ARGS)
#define MAXIMUM_TRIANGLES_PER_ERROR_REPORT MAXIMUM_TRIANGLES_PER_ERROR_REPORT(BLOFELD_CONST_ARGS)
#define MAXIMUM_QUADS_PER_ERROR_REPORT MAXIMUM_QUADS_PER_ERROR_REPORT(BLOFELD_CONST_ARGS)
#define MAXIMUM_COMMENTS_PER_ERROR_REPORT MAXIMUM_COMMENTS_PER_ERROR_REPORT(BLOFELD_CONST_ARGS)
#define MAXIMUM_NUMBER_OF_ANTENNA_VERTICES MAXIMUM_NUMBER_OF_ANTENNA_VERTICES(BLOFELD_CONST_ARGS)
#define MAXIMUM_SEQUENCES_PER_BITMAP_GROUP MAXIMUM_SEQUENCES_PER_BITMAP_GROUP(BLOFELD_CONST_ARGS)
#define MAXIMUM_SPRITES_PER_SEQUENCE MAXIMUM_SPRITES_PER_SEQUENCE(BLOFELD_CONST_ARGS)
#define MAXIMUM_BITMAPS_PER_BITMAP_GROUP MAXIMUM_BITMAPS_PER_BITMAP_GROUP(BLOFELD_CONST_ARGS)
#define MAXIMUM_REGIONS_PER_MODEL MAXIMUM_REGIONS_PER_MODEL(BLOFELD_CONST_ARGS)
#define MAXIMUM_PERMUTATIONS_PER_MODEL_REGION MAXIMUM_PERMUTATIONS_PER_MODEL_REGION(BLOFELD_CONST_ARGS)
#define NUMBER_OF_PROP_CLASSES NUMBER_OF_PROP_CLASSES(BLOFELD_CONST_ARGS)
#define NUMBER_OF_ACTOR_COMBAT_STATUS_LEVELS NUMBER_OF_ACTOR_COMBAT_STATUS_LEVELS(BLOFELD_CONST_ARGS)
#define MAX_CINEMATIC_SCENE_COUNT MAX_CINEMATIC_SCENE_COUNT(BLOFELD_CONST_ARGS)
#define MAX_CINEMATIC_SHOT_COUNT MAX_CINEMATIC_SHOT_COUNT(BLOFELD_CONST_ARGS)
#define MAXIMUM_MATERIALS_PER_MODEL MAXIMUM_MATERIALS_PER_MODEL(BLOFELD_CONST_ARGS)
#define MAXIMUM_BSPS_PER_COLLISION_REGION MAXIMUM_BSPS_PER_COLLISION_REGION(BLOFELD_CONST_ARGS)
#define MAXIMUM_PATHFINDING_SPHERES_PER_COLLISION_MODEL MAXIMUM_PATHFINDING_SPHERES_PER_COLLISION_MODEL(BLOFELD_CONST_ARGS)
#define MAXIMUM_NODES_PER_MODEL MAXIMUM_NODES_PER_MODEL(BLOFELD_CONST_ARGS)
#define MAXIMUM_COLORS_PER_COLOR_TABLE_GROUP MAXIMUM_COLORS_PER_COLOR_TABLE_GROUP(BLOFELD_CONST_ARGS)
#define MAXIMUM_DECORATOR_SETS_PER_SCENARIO MAXIMUM_DECORATOR_SETS_PER_SCENARIO(BLOFELD_CONST_ARGS)
#define MAXIMUM_DETAIL_OBJECT_TYPES_PER_COLLECTION MAXIMUM_DETAIL_OBJECT_TYPES_PER_COLLECTION(BLOFELD_CONST_ARGS)
#define MAXIMUM_SQUIRTERS_PER_FLUID_DYNAMICS MAXIMUM_SQUIRTERS_PER_FLUID_DYNAMICS(BLOFELD_CONST_ARGS)
#define MAXIMUM_INFLOWS_PER_FLUID_DYNAMICS MAXIMUM_INFLOWS_PER_FLUID_DYNAMICS(BLOFELD_CONST_ARGS)
#define MAXIMUM_OUTFLOWS_PER_FLUID_DYNAMICS MAXIMUM_OUTFLOWS_PER_FLUID_DYNAMICS(BLOFELD_CONST_ARGS)
#define MAXIMUM_OBSTACLES_PER_FLUID_DYNAMICS MAXIMUM_OBSTACLES_PER_FLUID_DYNAMICS(BLOFELD_CONST_ARGS)
#define MAXIMUM_STATES_PER_MODEL_PERMUTATION MAXIMUM_STATES_PER_MODEL_PERMUTATION(BLOFELD_CONST_ARGS)
#define MAXIMUM_DAMAGE_SECTIONS_PER_MODEL MAXIMUM_DAMAGE_SECTIONS_PER_MODEL(BLOFELD_CONST_ARGS)
#define MAXIMUM_RESPONSES_PER_DAMAGE_SECTION MAXIMUM_RESPONSES_PER_DAMAGE_SECTION(BLOFELD_CONST_ARGS)
#define MAXIMUM_DAMAGE_SEAT_INFOS_PER_MODEL MAXIMUM_DAMAGE_SEAT_INFOS_PER_MODEL(BLOFELD_CONST_ARGS)
#define MAXIMUM_DAMAGE_CONSTRAINT_INFOS_PER_MODEL MAXIMUM_DAMAGE_CONSTRAINT_INFOS_PER_MODEL(BLOFELD_CONST_ARGS)
#define MAXIMUM_MODEL_TARGETS_PER_MODEL MAXIMUM_MODEL_TARGETS_PER_MODEL(BLOFELD_CONST_ARGS)
#define MAXIMUM_GAME_INCIDENT_RESPONSES_PER_BLOCK MAXIMUM_GAME_INCIDENT_RESPONSES_PER_BLOCK(BLOFELD_CONST_ARGS)
#define MAXIMUM_CHALLENGES_TO_PROGRESS_PER_BLOCK MAXIMUM_CHALLENGES_TO_PROGRESS_PER_BLOCK(BLOFELD_CONST_ARGS)
#define MAXIMUM_TRACKS_PER_LOOPING_SOUND MAXIMUM_TRACKS_PER_LOOPING_SOUND(BLOFELD_CONST_ARGS)
#define MAXIMUM_DETAIL_SOUNDS_PER_LOOPING_SOUND MAXIMUM_DETAIL_SOUNDS_PER_LOOPING_SOUND(BLOFELD_CONST_ARGS)
#define NUMBER_OF_GLOBAL_SOUNDS NUMBER_OF_GLOBAL_SOUNDS(BLOFELD_CONST_ARGS)
#define MATERIAL_SHADER_MAX_SOURCE_FILES MATERIAL_SHADER_MAX_SOURCE_FILES(BLOFELD_CONST_ARGS)
#define MAXIMUM_MARKER_GROUPS_PER_RENDER_MODEL MAXIMUM_MARKER_GROUPS_PER_RENDER_MODEL(BLOFELD_CONST_ARGS)
#define MAXIMUM_MARKERS_PER_RENDER_MODEL_MARKER_GROUP MAXIMUM_MARKERS_PER_RENDER_MODEL_MARKER_GROUP(BLOFELD_CONST_ARGS)
#define MAXIMUM_MATERIALS_PER_GEOMETRY MAXIMUM_MATERIALS_PER_GEOMETRY(BLOFELD_CONST_ARGS)
#define MAXIMUM_BONE_GROUPS_PER_MODEL MAXIMUM_BONE_GROUPS_PER_MODEL(BLOFELD_CONST_ARGS)
#define MAXIMUM_NUMBER_OF_MULTIPLAYER_SCENARIOS MAXIMUM_NUMBER_OF_MULTIPLAYER_SCENARIOS(BLOFELD_CONST_ARGS)
#define MAXIMUM_SCENARIO_PLAYERS_PER_BLOCK MAXIMUM_SCENARIO_PLAYERS_PER_BLOCK(BLOFELD_CONST_ARGS)
#define MAXIMUM_WIDGETS_PER_OBJECT MAXIMUM_WIDGETS_PER_OBJECT(BLOFELD_CONST_ARGS)
#define MAXIMUM_NUMBER_OF_OBJECT_CHANGE_COLOR_INITIAL_PERMUTATIONS MAXIMUM_NUMBER_OF_OBJECT_CHANGE_COLOR_INITIAL_PERMUTATIONS(BLOFELD_CONST_ARGS)
#define MAXIMUM_NUMBER_OF_OBJECT_CHANGE_COLOR_FUNCTIONS MAXIMUM_NUMBER_OF_OBJECT_CHANGE_COLOR_FUNCTIONS(BLOFELD_CONST_ARGS)
#define MAXIMUM_VERTICES_PER_GEOMETRY_SECTION MAXIMUM_VERTICES_PER_GEOMETRY_SECTION(BLOFELD_CONST_ARGS)
#define MAXIMUM_ACTORS_PER_PERFORMANCE MAXIMUM_ACTORS_PER_PERFORMANCE(BLOFELD_CONST_ARGS)
#define MAXIMUM_LINES_PER_PERFORMANCE MAXIMUM_LINES_PER_PERFORMANCE(BLOFELD_CONST_ARGS)
#define MAXIMUM_SCRIPT_FRAGMENTS_PER_PERFORMANCE_LINE MAXIMUM_SCRIPT_FRAGMENTS_PER_PERFORMANCE_LINE(BLOFELD_CONST_ARGS)
#define MAXIMUM_POINT_INTERACTIONS_PER_PERFORMANCE_LINE MAXIMUM_POINT_INTERACTIONS_PER_PERFORMANCE_LINE(BLOFELD_CONST_ARGS)
#define MAXIMUM_ANIMATIONS_PER_PERFORMANCE_LINE MAXIMUM_ANIMATIONS_PER_PERFORMANCE_LINE(BLOFELD_CONST_ARGS)
#define MAXIMUM_SYNC_ACTIONS_PER_PERFORMANCE_LINE MAXIMUM_SYNC_ACTIONS_PER_PERFORMANCE_LINE(BLOFELD_CONST_ARGS)
#define MAXIMUM_SCENERY_SYNC_ACTIONS_PER_PERFORMANCE_LINE MAXIMUM_SCENERY_SYNC_ACTIONS_PER_PERFORMANCE_LINE(BLOFELD_CONST_ARGS)
#define MAXIMUM_DIALOG_LINES_PER_PERFORMANCE_LINE MAXIMUM_DIALOG_LINES_PER_PERFORMANCE_LINE(BLOFELD_CONST_ARGS)
#define MAXIMUM_SOUNDS_PER_PERFORMANCE_LINE MAXIMUM_SOUNDS_PER_PERFORMANCE_LINE(BLOFELD_CONST_ARGS)
#define MAXIMUM_STRUCTURE_BSPS_PER_SCENARIO MAXIMUM_STRUCTURE_BSPS_PER_SCENARIO(BLOFELD_CONST_ARGS)
#define MAX_NUM_MOBILE_NAVMESHES MAX_NUM_MOBILE_NAVMESHES(BLOFELD_CONST_ARGS)
#define MAX_NUM_NAV_VOLUMES MAX_NUM_NAV_VOLUMES(BLOFELD_CONST_ARGS)
#define MAX_NUM_NAV_CLIMBS MAX_NUM_NAV_CLIMBS(BLOFELD_CONST_ARGS)
#define MAXIMUM_COLLISION_MATERIALS_PER_STRUCTURE MAXIMUM_COLLISION_MATERIALS_PER_STRUCTURE(BLOFELD_CONST_ARGS)
#define MAXIMUM_CLUSTER_PORTALS_PER_STRUCTURE MAXIMUM_CLUSTER_PORTALS_PER_STRUCTURE(BLOFELD_CONST_ARGS)
#define MAXIMUM_VERTICES_PER_CLUSTER_PORTAL MAXIMUM_VERTICES_PER_CLUSTER_PORTAL(BLOFELD_CONST_ARGS)
#define MAXIMUM_DETAIL_OBJECT_CELLS_PER_STRUCTURE MAXIMUM_DETAIL_OBJECT_CELLS_PER_STRUCTURE(BLOFELD_CONST_ARGS)
#define MAXIMUM_DETAIL_OBJECTS_PER_STRUCTURE MAXIMUM_DETAIL_OBJECTS_PER_STRUCTURE(BLOFELD_CONST_ARGS)
#define MAXIMUM_CLUSTERS_PER_STRUCTURE MAXIMUM_CLUSTERS_PER_STRUCTURE(BLOFELD_CONST_ARGS)
#define MAXIMUM_CLUSTER_PORTALS_PER_CLUSTER MAXIMUM_CLUSTER_PORTALS_PER_CLUSTER(BLOFELD_CONST_ARGS)
#define MAXIMUM_BLOCKS_PER_CLUSTER MAXIMUM_BLOCKS_PER_CLUSTER(BLOFELD_CONST_ARGS)
#define MAXIMUM_MARKERS_PER_STRUCTURE MAXIMUM_MARKERS_PER_STRUCTURE(BLOFELD_CONST_ARGS)
#define MAXIMUM_SKIES_PER_SCENARIO MAXIMUM_SKIES_PER_SCENARIO(BLOFELD_CONST_ARGS)
#define MAXIMUM_DECALS_PER_STRUCTURE MAXIMUM_DECALS_PER_STRUCTURE(BLOFELD_CONST_ARGS)
#define MAXIMUM_ENVIRONMENT_OBJECT_PALETTE_ENTRIES_PER_STRUCTURE MAXIMUM_ENVIRONMENT_OBJECT_PALETTE_ENTRIES_PER_STRUCTURE(BLOFELD_CONST_ARGS)
#define MAXIMUM_ENVIRONMENT_OBJECTS_PER_STRUCTURE MAXIMUM_ENVIRONMENT_OBJECTS_PER_STRUCTURE(BLOFELD_CONST_ARGS)
#define MAXIMUM_FACES_PER_MAP_LEAF MAXIMUM_FACES_PER_MAP_LEAF(BLOFELD_CONST_ARGS)
#define MAXIMUM_VERTICES_PER_LEAF_CONNECTION MAXIMUM_VERTICES_PER_LEAF_CONNECTION(BLOFELD_CONST_ARGS)
#define MAXIMUM_CONNECTIONS_PER_MAP_LEAF MAXIMUM_CONNECTIONS_PER_MAP_LEAF(BLOFELD_CONST_ARGS)
#define MAXIMUM_CONNECTIONS_PER_LEAF_MAP MAXIMUM_CONNECTIONS_PER_LEAF_MAP(BLOFELD_CONST_ARGS)
#define MAXIMUM_FOG_PLANES_PER_STRUCTURE MAXIMUM_FOG_PLANES_PER_STRUCTURE(BLOFELD_CONST_ARGS)
#define MAXIMUM_FOG_ZONES_PER_STRUCTURE MAXIMUM_FOG_ZONES_PER_STRUCTURE(BLOFELD_CONST_ARGS)
#define MAXIMUM_CHILD_SCENARIOS_PER_SCENARIO MAXIMUM_CHILD_SCENARIOS_PER_SCENARIO(BLOFELD_CONST_ARGS)
#define MAXIMUM_STRUCTURE_DESIGNS_PER_SCENARIO MAXIMUM_STRUCTURE_DESIGNS_PER_SCENARIO(BLOFELD_CONST_ARGS)
#define MAXIMUM_FUNCTIONS_PER_SCENARIO MAXIMUM_FUNCTIONS_PER_SCENARIO(BLOFELD_CONST_ARGS)
#define MAXIMUM_EDITOR_COMMENTS MAXIMUM_EDITOR_COMMENTS(BLOFELD_CONST_ARGS)
#define MAXIMUM_ENVIRONMENT_OBJECTS_PER_SCENARIO MAXIMUM_ENVIRONMENT_OBJECTS_PER_SCENARIO(BLOFELD_CONST_ARGS)
#define MAXIMUM_OBJECT_NAMES_PER_SCENARIO MAXIMUM_OBJECT_NAMES_PER_SCENARIO(BLOFELD_CONST_ARGS)
#define MAXIMUM_SCENERY_DATUMS_PER_SCENARIO MAXIMUM_SCENERY_DATUMS_PER_SCENARIO(BLOFELD_CONST_ARGS)
#define MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK(BLOFELD_CONST_ARGS)
#define MAXIMUM_BIPED_DATUMS_PER_SCENARIO MAXIMUM_BIPED_DATUMS_PER_SCENARIO(BLOFELD_CONST_ARGS)
#define MAXIMUM_VEHICLE_DATUMS_PER_SCENARIO MAXIMUM_VEHICLE_DATUMS_PER_SCENARIO(BLOFELD_CONST_ARGS)
#define MAXIMUM_EQUIPMENT_DATUMS_PER_SCENARIO MAXIMUM_EQUIPMENT_DATUMS_PER_SCENARIO(BLOFELD_CONST_ARGS)
#define MAXIMUM_WEAPON_DATUMS_PER_SCENARIO MAXIMUM_WEAPON_DATUMS_PER_SCENARIO(BLOFELD_CONST_ARGS)
#define MAXIMUM_DEVICE_GROUPS_PER_SCENARIO MAXIMUM_DEVICE_GROUPS_PER_SCENARIO(BLOFELD_CONST_ARGS)
#define MAXIMUM_MACHINE_DATUMS_PER_SCENARIO MAXIMUM_MACHINE_DATUMS_PER_SCENARIO(BLOFELD_CONST_ARGS)
#define MAXIMUM_TERMINAL_DATUMS_PER_SCENARIO MAXIMUM_TERMINAL_DATUMS_PER_SCENARIO(BLOFELD_CONST_ARGS)
#define MAXIMUM_CONTROL_DATUMS_PER_SCENARIO MAXIMUM_CONTROL_DATUMS_PER_SCENARIO(BLOFELD_CONST_ARGS)
#define MAXIMUM_DISPENSER_DATUMS_PER_SCENARIO MAXIMUM_DISPENSER_DATUMS_PER_SCENARIO(BLOFELD_CONST_ARGS)
#define MAXIMUM_SOUND_SCENERY_DATUMS_PER_SCENARIO MAXIMUM_SOUND_SCENERY_DATUMS_PER_SCENARIO(BLOFELD_CONST_ARGS)
#define MAXIMUM_GIANT_DATUMS_PER_SCENARIO MAXIMUM_GIANT_DATUMS_PER_SCENARIO(BLOFELD_CONST_ARGS)
#define MAXIMUM_EFFECT_SCENERY_DATUMS_PER_SCENARIO MAXIMUM_EFFECT_SCENERY_DATUMS_PER_SCENARIO(BLOFELD_CONST_ARGS)
#define MAXIMUM_SPAWNER_DATUMS_PER_SCENARIO MAXIMUM_SPAWNER_DATUMS_PER_SCENARIO(BLOFELD_CONST_ARGS)
#define MAXIMUM_BINK_PALETTE_ENTRIES_PER_BLOCK MAXIMUM_BINK_PALETTE_ENTRIES_PER_BLOCK(BLOFELD_CONST_ARGS)
#define MAXIMUM_REQUISITION_MENU_SIZE MAXIMUM_REQUISITION_MENU_SIZE(BLOFELD_CONST_ARGS)
#define MAXIMUM_SCENARIO_SOFT_CEILINGS_PER_SCENARIO MAXIMUM_SCENARIO_SOFT_CEILINGS_PER_SCENARIO(BLOFELD_CONST_ARGS)
#define MAXIMUM_TRIGGER_VOLUMES_PER_SCENARIO MAXIMUM_TRIGGER_VOLUMES_PER_SCENARIO(BLOFELD_CONST_ARGS)
#define MAXIMUM_RECORDED_ANIMATIONS_PER_MAP MAXIMUM_RECORDED_ANIMATIONS_PER_MAP(BLOFELD_CONST_ARGS)
#define MAXIMUM_DECALS_PER_SCENARIO MAXIMUM_DECALS_PER_SCENARIO(BLOFELD_CONST_ARGS)
#define MAXIMUM_DECAL_PALETTES_PER_SCENARIO MAXIMUM_DECAL_PALETTES_PER_SCENARIO(BLOFELD_CONST_ARGS)
#define MAXIMUM_DETAIL_OBJECT_LAYERS_PER_STRUCTURE MAXIMUM_DETAIL_OBJECT_LAYERS_PER_STRUCTURE(BLOFELD_CONST_ARGS)
#define MAXIMUM_CUTSCENE_FLAGS_PER_SCENARIO MAXIMUM_CUTSCENE_FLAGS_PER_SCENARIO(BLOFELD_CONST_ARGS)
#define MAXIMUM_CUTSCENE_CAMERA_POINTS_PER_SCENARIO MAXIMUM_CUTSCENE_CAMERA_POINTS_PER_SCENARIO(BLOFELD_CONST_ARGS)
#define MAXIMUM_ATMOSPHERE_PALETTE_ENTRIES_PER_STRUCTURE MAXIMUM_ATMOSPHERE_PALETTE_ENTRIES_PER_STRUCTURE(BLOFELD_CONST_ARGS)
#define MAXIMUM_CAMERA_FX_PALETTE_ENTRIES_PER_STRUCTURE MAXIMUM_CAMERA_FX_PALETTE_ENTRIES_PER_STRUCTURE(BLOFELD_CONST_ARGS)
#define MAXIMUM_WEATHER_PALETTE_ENTRIES_PER_STRUCTURE MAXIMUM_WEATHER_PALETTE_ENTRIES_PER_STRUCTURE(BLOFELD_CONST_ARGS)
#define MAXIMUM_CRATE_DATUMS_PER_SCENARIO MAXIMUM_CRATE_DATUMS_PER_SCENARIO(BLOFELD_CONST_ARGS)
#define MAXIMUM_SUBTITLES_PER_SCENARIO MAXIMUM_SUBTITLES_PER_SCENARIO(BLOFELD_CONST_ARGS)
#define MAXIMUM_CREATURE_DATUMS_PER_SCENARIO MAXIMUM_CREATURE_DATUMS_PER_SCENARIO(BLOFELD_CONST_ARGS)
#define MAXIMUM_DECORATOR_PALETTES_PER_SCENARIO MAXIMUM_DECORATOR_PALETTES_PER_SCENARIO(BLOFELD_CONST_ARGS)
#define MAXIMUM_DECORATOR_PLACEMENTS_PER_SET MAXIMUM_DECORATOR_PLACEMENTS_PER_SET(BLOFELD_CONST_ARGS)
#define MAXIMUM_SCENARIO_CINEMATICS MAXIMUM_SCENARIO_CINEMATICS(BLOFELD_CONST_ARGS)
#define MAXIMUM_PERFORMANCES_PER_SCENARIO MAXIMUM_PERFORMANCES_PER_SCENARIO(BLOFELD_CONST_ARGS)
#define MAXIMUM_TASKS_PER_PERFORMANCE MAXIMUM_TASKS_PER_PERFORMANCE(BLOFELD_CONST_ARGS)
#define MAX_PUPPETS_PER_SHOW MAX_PUPPETS_PER_SHOW(BLOFELD_CONST_ARGS)
#define MAX_ACTIONS_PER_PUPPET MAX_ACTIONS_PER_PUPPET(BLOFELD_CONST_ARGS)
#define MAX_SUB_ACTIONS_PER_PUPPET MAX_SUB_ACTIONS_PER_PUPPET(BLOFELD_CONST_ARGS)
#define MAX_BRANCHES_PER_SUB_ACTION MAX_BRANCHES_PER_SUB_ACTION(BLOFELD_CONST_ARGS)
#define MAX_SUB_TRACKS MAX_SUB_TRACKS(BLOFELD_CONST_ARGS)
#define MAX_ACTIONS_PER_SHOW MAX_ACTIONS_PER_SHOW(BLOFELD_CONST_ARGS)
#define MAX_SUB_ACTIONS_PER_SHOW MAX_SUB_ACTIONS_PER_SHOW(BLOFELD_CONST_ARGS)
#define MAX_POINTS_PER_PATH MAX_POINTS_PER_PATH(BLOFELD_CONST_ARGS)
#define NUMBER_OF_SOUND_CLASSES NUMBER_OF_SOUND_CLASSES(BLOFELD_CONST_ARGS)
#define MAXIMUM_PERMUTATIONS_PER_PITCH_RANGE MAXIMUM_PERMUTATIONS_PER_PITCH_RANGE(BLOFELD_CONST_ARGS)
#define MAXIMUM_PITCH_RANGES_PER_SOUND MAXIMUM_PITCH_RANGES_PER_SOUND(BLOFELD_CONST_ARGS)
#define MAXIMUM_MARKERS_PER_PERMUTATION MAXIMUM_MARKERS_PER_PERMUTATION(BLOFELD_CONST_ARGS)
#define MAXIMUM_SOUND_DATA_SIZE MAXIMUM_SOUND_DATA_SIZE(BLOFELD_CONST_ARGS)
#define MAXIMUM_POSTURES_PER_UNIT MAXIMUM_POSTURES_PER_UNIT(BLOFELD_CONST_ARGS)
#define MAXIMUM_DIALOGUE_VARIANTS_PER_UNIT MAXIMUM_DIALOGUE_VARIANTS_PER_UNIT(BLOFELD_CONST_ARGS)
#define MAXIMUM_INITIAL_WEAPONS_PER_UNIT MAXIMUM_INITIAL_WEAPONS_PER_UNIT(BLOFELD_CONST_ARGS)
#define MAXIMUM_SEATS_PER_UNIT_DEFINITION MAXIMUM_SEATS_PER_UNIT_DEFINITION(BLOFELD_CONST_ARGS)
#define MAXIMUM_NUMBER_OF_MAGAZINES_PER_WEAPON MAXIMUM_NUMBER_OF_MAGAZINES_PER_WEAPON(BLOFELD_CONST_ARGS)
#define MAXIMUM_NUMBER_OF_MAGAZINE_OBJECTS_PER_MAGAZINE MAXIMUM_NUMBER_OF_MAGAZINE_OBJECTS_PER_MAGAZINE(BLOFELD_CONST_ARGS)
#define MAXIMUM_RULES_PER_CA MAXIMUM_RULES_PER_CA(BLOFELD_CONST_ARGS)
#define MAXIMUM_STATES_PER_RULE MAXIMUM_STATES_PER_RULE(BLOFELD_CONST_ARGS)
#define MAXIMUM_NUMBER_OF_UNIT_CAMERA_TRACKS MAXIMUM_NUMBER_OF_UNIT_CAMERA_TRACKS(BLOFELD_CONST_ARGS)
#define WEAPON_SPECIFIC_MARKERS_COUNT WEAPON_SPECIFIC_MARKERS_COUNT(BLOFELD_CONST_ARGS)
#define MAXIMUM_CHARGING_FIRE_FRACTIONS_PER_TRIGGER MAXIMUM_CHARGING_FIRE_FRACTIONS_PER_TRIGGER(BLOFELD_CONST_ARGS)
#define MAXIMUM_DAMAGE_TRANSFERS_PER_MODEL MAXIMUM_DAMAGE_TRANSFERS_PER_MODEL(BLOFELD_CONST_ARGS)
#define NUMBER_OF_OBJECT_TYPES NUMBER_OF_OBJECT_TYPES(BLOFELD_CONST_ARGS)
#define MAXIMUM_NODE_INDICES_PER_ERROR_POINT MAXIMUM_NODE_INDICES_PER_ERROR_POINT(BLOFELD_CONST_ARGS)

#define k_maxEmblemIndicesPerItem k_maxEmblemIndicesPerItem(BLOFELD_CONST_ARGS)
#define k_max_triangulation_tag_triangles k_max_triangulation_tag_triangles(BLOFELD_CONST_ARGS)
#define k_max_sync_action_groups k_max_sync_action_groups(BLOFELD_CONST_ARGS)
#define k_max_sync_actions k_max_sync_actions(BLOFELD_CONST_ARGS)
#define k_max_sync_action_participants k_max_sync_action_participants(BLOFELD_CONST_ARGS)
#define k_max_vehicle_suspensions k_max_vehicle_suspensions(BLOFELD_CONST_ARGS)
#define k_max_function_overlays_per_graph k_max_function_overlays_per_graph(BLOFELD_CONST_ARGS)
#define k_max_animation_inheritence_levels k_max_animation_inheritence_levels(BLOFELD_CONST_ARGS)
#define k_max_triangulation_tag_points k_max_triangulation_tag_points(BLOFELD_CONST_ARGS)
#define k_firefightWavesPerGoal k_firefightWavesPerGoal(BLOFELD_CONST_ARGS)
#define k_firefightMaxPlayerGoals k_firefightMaxPlayerGoals(BLOFELD_CONST_ARGS)
#define k_maximum_survival_possible_wave_squads k_maximum_survival_possible_wave_squads(BLOFELD_CONST_ARGS)
#define k_cui_max_component_count k_cui_max_component_count(BLOFELD_CONST_ARGS)
#define k_cui_max_property_binding_count k_cui_max_property_binding_count(BLOFELD_CONST_ARGS)
#define k_cuiMaxEncapsulationCount k_cuiMaxEncapsulationCount(BLOFELD_CONST_ARGS)
#define k_cui_max_animation_count k_cui_max_animation_count(BLOFELD_CONST_ARGS)
#define k_cui_max_property_count k_cui_max_property_count(BLOFELD_CONST_ARGS)
#define k_first_person_interface_count k_first_person_interface_count(BLOFELD_CONST_ARGS)
#define k_animation_node_usage_count k_animation_node_usage_count(BLOFELD_CONST_ARGS)
#define k_animation_maximum_node_mask_count k_animation_maximum_node_mask_count(BLOFELD_CONST_ARGS)
#define k_animation_maximum_function_count k_animation_maximum_function_count(BLOFELD_CONST_ARGS)
#define k_animation_maximum_model_variants k_animation_maximum_model_variants(BLOFELD_CONST_ARGS)
#define k_animation_maximum_mode_or_stance_aliases k_animation_maximum_mode_or_stance_aliases(BLOFELD_CONST_ARGS)
#define k_meg k_meg(BLOFELD_CONST_ARGS)
#define k_num_ai_trait_weapon k_num_ai_trait_weapon(BLOFELD_CONST_ARGS)
#define k_maximum_number_of_sound_effect_templates k_maximum_number_of_sound_effect_templates(BLOFELD_CONST_ARGS)
#define k_maximum_number_of_sound_effect_parameters k_maximum_number_of_sound_effect_parameters(BLOFELD_CONST_ARGS)
#define k_max_airprobes_per_scenario k_max_airprobes_per_scenario(BLOFELD_CONST_ARGS)
#define k_maximum_achievements k_maximum_achievements(BLOFELD_CONST_ARGS)
#define k_dialogue_type_count k_dialogue_type_count(BLOFELD_CONST_ARGS)
#define k_global_formations_count k_global_formations_count(BLOFELD_CONST_ARGS)
#define k_global_squad_template_folder_count k_global_squad_template_folder_count(BLOFELD_CONST_ARGS)
#define k_global_squad_templates_count k_global_squad_templates_count(BLOFELD_CONST_ARGS)
#define k_global_performance_template_folder_count k_global_performance_template_folder_count(BLOFELD_CONST_ARGS)
#define k_global_performance_templates_count k_global_performance_templates_count(BLOFELD_CONST_ARGS)
#define k_max_custom_stimuli_count k_max_custom_stimuli_count(BLOFELD_CONST_ARGS)
#define k_max_ai_cue_templates k_max_ai_cue_templates(BLOFELD_CONST_ARGS)
#define k_num_ai_trait_vision k_num_ai_trait_vision(BLOFELD_CONST_ARGS)
#define k_num_ai_trait_sound k_num_ai_trait_sound(BLOFELD_CONST_ARGS)
#define k_num_ai_trait_luck k_num_ai_trait_luck(BLOFELD_CONST_ARGS)
#define k_num_ai_trait_grenade k_num_ai_trait_grenade(BLOFELD_CONST_ARGS)
#define k_max_atmosphere_settings k_max_atmosphere_settings(BLOFELD_CONST_ARGS)
#define k_online_avatar_award_count k_online_avatar_award_count(BLOFELD_CONST_ARGS)
#define k_maximum_death_program_special_types k_maximum_death_program_special_types(BLOFELD_CONST_ARGS)
#define k_maximum_death_program_damage_types k_maximum_death_program_damage_types(BLOFELD_CONST_ARGS)
#define k_maximum_death_program_velocity_gates k_maximum_death_program_velocity_gates(BLOFELD_CONST_ARGS)
#define k_maximum_trick_definitions_per_unit k_maximum_trick_definitions_per_unit(BLOFELD_CONST_ARGS)
#define k_maximum_biped_proximity_feelers k_maximum_biped_proximity_feelers(BLOFELD_CONST_ARGS)
#define k_contact_point_count k_contact_point_count(BLOFELD_CONST_ARGS)
#define k_maxBipedSoundRTPCBlocks k_maxBipedSoundRTPCBlocks(BLOFELD_CONST_ARGS)
#define k_maxBipedSoundSweetenerBlocks k_maxBipedSoundSweetenerBlocks(BLOFELD_CONST_ARGS)
#define k_maximum_aiming_fixup_joints k_maximum_aiming_fixup_joints(BLOFELD_CONST_ARGS)
#define k_maxTightBoundsSets k_maxTightBoundsSets(BLOFELD_CONST_ARGS)
#define k_maximum_custom_app_count k_maximum_custom_app_count(BLOFELD_CONST_ARGS)
#define k_maximum_custom_app_damage_modifier_count k_maximum_custom_app_damage_modifier_count(BLOFELD_CONST_ARGS)
#define k_maximum_variants_per_model k_maximum_variants_per_model(BLOFELD_CONST_ARGS)
#define k_max_movement_sets k_max_movement_sets(BLOFELD_CONST_ARGS)
#define k_max_movement_variants k_max_movement_variants(BLOFELD_CONST_ARGS)
#define k_fp_evaluator_count k_fp_evaluator_count(BLOFELD_CONST_ARGS)
#define k_campaign_difficulty_levels_count k_campaign_difficulty_levels_count(BLOFELD_CONST_ARGS)
#define k_character_equipment_usage_when_count k_character_equipment_usage_when_count(BLOFELD_CONST_ARGS)
#define k_max_character_stimuli_responses k_max_character_stimuli_responses(BLOFELD_CONST_ARGS)
#define k_roomEnoughToConvertAllExistingCategories k_roomEnoughToConvertAllExistingCategories(BLOFELD_CONST_ARGS)
#define k_maximum_challenges_per_category k_maximum_challenges_per_category(BLOFELD_CONST_ARGS)
#define k_maximum_scene_shot_clip_plane_count k_maximum_scene_shot_clip_plane_count(BLOFELD_CONST_ARGS)
#define k_maximum_scene_shot_clip_subject_count k_maximum_scene_shot_clip_subject_count(BLOFELD_CONST_ARGS)
#define k_maximum_collision_spheres_per_cloth k_maximum_collision_spheres_per_cloth(BLOFELD_CONST_ARGS)
#define k_maximum_vertices_per_cloth k_maximum_vertices_per_cloth(BLOFELD_CONST_ARGS)
#define k_maximum_indices_per_cloth k_maximum_indices_per_cloth(BLOFELD_CONST_ARGS)
#define k_maximum_links_per_cloth k_maximum_links_per_cloth(BLOFELD_CONST_ARGS)
#define eCT_count eCT_count(BLOFELD_CONST_ARGS)
#define k_max_cookie_purchase_families k_max_cookie_purchase_families(BLOFELD_CONST_ARGS)
#define k_max_cookie_purchase_family_items k_max_cookie_purchase_family_items(BLOFELD_CONST_ARGS)
#define k_max_cookie_purchase_total_appearance_items k_max_cookie_purchase_total_appearance_items(BLOFELD_CONST_ARGS)
#define k_byte_bits k_byte_bits(BLOFELD_CONST_ARGS)
#define k_max_cookie_purchase_total_loadout_items k_max_cookie_purchase_total_loadout_items(BLOFELD_CONST_ARGS)
#define k_max_cookie_purchase_total_ordnance_items k_max_cookie_purchase_total_ordnance_items(BLOFELD_CONST_ARGS)
#define k_kilo k_kilo(BLOFELD_CONST_ARGS)
#define k_maximum_effect_locations_count k_maximum_effect_locations_count(BLOFELD_CONST_ARGS)
#define k_maximum_effect_events_count k_maximum_effect_events_count(BLOFELD_CONST_ARGS)
#define k_maximum_effect_parts_per_event_count k_maximum_effect_parts_per_event_count(BLOFELD_CONST_ARGS)
#define k_maximum_effect_accelerations_per_event_count k_maximum_effect_accelerations_per_event_count(BLOFELD_CONST_ARGS)
#define k_maximum_effect_looping_sounds_count k_maximum_effect_looping_sounds_count(BLOFELD_CONST_ARGS)
#define k_effect_holdback_type_max k_effect_holdback_type_max(BLOFELD_CONST_ARGS)
#define k_effect_priority_max k_effect_priority_max(BLOFELD_CONST_ARGS)
#define k_equipmentMaxAbilityCount k_equipmentMaxAbilityCount(BLOFELD_CONST_ARGS)
#define k_maxEquipmentSoundRTPCBlocks k_maxEquipmentSoundRTPCBlocks(BLOFELD_CONST_ARGS)
#define k_maxEquipmentSoundSweetenerBlocks k_maxEquipmentSoundSweetenerBlocks(BLOFELD_CONST_ARGS)
#define k_material_effect_type_count k_material_effect_type_count(BLOFELD_CONST_ARGS)
#define k_maximum_material_effect_blocks k_maximum_material_effect_blocks(BLOFELD_CONST_ARGS)
#define k_forge_named_color_count k_forge_named_color_count(BLOFELD_CONST_ARGS)
#define k_max_primitives_per_formation k_max_primitives_per_formation(BLOFELD_CONST_ARGS)
#define k_max_points_per_primitive k_max_points_per_primitive(BLOFELD_CONST_ARGS)
#define k_max_sound_references_per_graph k_max_sound_references_per_graph(BLOFELD_CONST_ARGS)
#define k_max_effect_references_per_graph k_max_effect_references_per_graph(BLOFELD_CONST_ARGS)
#define k_max_frame_events k_max_frame_events(BLOFELD_CONST_ARGS)
#define k_maximum_game_engine_event_responses k_maximum_game_engine_event_responses(BLOFELD_CONST_ARGS)
#define eUGT_count eUGT_count(BLOFELD_CONST_ARGS)
#define k_maximumNumberOfMultiplayerOrdnanceSelections k_maximumNumberOfMultiplayerOrdnanceSelections(BLOFELD_CONST_ARGS)
#define k_giant_buckle_total_types k_giant_buckle_total_types(BLOFELD_CONST_ARGS)
#define k_number_of_entry_points k_number_of_entry_points(BLOFELD_CONST_ARGS)
#define k_maximum_game_setting_blocks k_maximum_game_setting_blocks(BLOFELD_CONST_ARGS)
#define k_maximum_variant_category_blocks k_maximum_variant_category_blocks(BLOFELD_CONST_ARGS)
#define k_havok_group_count k_havok_group_count(BLOFELD_CONST_ARGS)
#define k_maximum_objects_per_model_variant k_maximum_objects_per_model_variant(BLOFELD_CONST_ARGS)
#define k_maximum_muted_nodes_per_model_variant k_maximum_muted_nodes_per_model_variant(BLOFELD_CONST_ARGS)
#define k_maximum_instance_groups_per_model k_maximum_instance_groups_per_model(BLOFELD_CONST_ARGS)
#define k_maximum_members_per_instance_group k_maximum_members_per_instance_group(BLOFELD_CONST_ARGS)
#define k_scenario_load_maximum_parameter_blocks k_scenario_load_maximum_parameter_blocks(BLOFELD_CONST_ARGS)
#define k_maximum_model_game_mode_types k_maximum_model_game_mode_types(BLOFELD_CONST_ARGS)
#define k_maximum_hs_source_files_per_context k_maximum_hs_source_files_per_context(BLOFELD_CONST_ARGS)
#define k_maximum_hs_scripts_per_context k_maximum_hs_scripts_per_context(BLOFELD_CONST_ARGS)
#define k_maximum_hs_parameters_per_script k_maximum_hs_parameters_per_script(BLOFELD_CONST_ARGS)
#define k_maximum_hs_globals_per_context k_maximum_hs_globals_per_context(BLOFELD_CONST_ARGS)
#define k_maximum_hs_instanced_variables_per_context k_maximum_hs_instanced_variables_per_context(BLOFELD_CONST_ARGS)
#define k_maximum_hs_references_per_context k_maximum_hs_references_per_context(BLOFELD_CONST_ARGS)
#define k_maximum_hs_unit_seat_mappings k_maximum_hs_unit_seat_mappings(BLOFELD_CONST_ARGS)
#define k_maximum_hs_syntax_nodes_per_context k_maximum_hs_syntax_nodes_per_context(BLOFELD_CONST_ARGS)
#define k_maximum_instance_geometry_instances_per_structure_bsp k_maximum_instance_geometry_instances_per_structure_bsp(BLOFELD_CONST_ARGS)
#define k_infinityMaximumSeasonCount k_infinityMaximumSeasonCount(BLOFELD_CONST_ARGS)
#define k_infinityMaximumMissionsPerSeason k_infinityMaximumMissionsPerSeason(BLOFELD_CONST_ARGS)
#define k_max_nodes_per_animation k_max_nodes_per_animation(BLOFELD_CONST_ARGS)
#define k_max_animations_per_graph k_max_animations_per_graph(BLOFELD_CONST_ARGS)
#define k_maximum_sandbox_property_values k_maximum_sandbox_property_values(BLOFELD_CONST_ARGS)
#define k_maximum_text_value_pairs_per_block k_maximum_text_value_pairs_per_block(BLOFELD_CONST_ARGS)
#define k_maximum_reflections_per_lens_flare k_maximum_reflections_per_lens_flare(BLOFELD_CONST_ARGS)
#define k_maximum_loadouts k_maximum_loadouts(BLOFELD_CONST_ARGS)
#define k_maximum_loadout_palettes k_maximum_loadout_palettes(BLOFELD_CONST_ARGS)
#define k_maximum_loadouts_per_palette k_maximum_loadouts_per_palette(BLOFELD_CONST_ARGS)
#define k_maximum_loadout_names k_maximum_loadout_names(BLOFELD_CONST_ARGS)
#define k_maximum_loadout_custom_slot_count k_maximum_loadout_custom_slot_count(BLOFELD_CONST_ARGS)
#define lightRigDirectionalCount lightRigDirectionalCount(BLOFELD_CONST_ARGS)
#define k_maximum_leaf_type_definitions k_maximum_leaf_type_definitions(BLOFELD_CONST_ARGS)
#define k_maximum_streaming_packs k_maximum_streaming_packs(BLOFELD_CONST_ARGS)
#define k_maximum_campaign_unspatialized_sounds k_maximum_campaign_unspatialized_sounds(BLOFELD_CONST_ARGS)
#define k_maximum_material_types k_maximum_material_types(BLOFELD_CONST_ARGS)
#define k_button_presets_count k_button_presets_count(BLOFELD_CONST_ARGS)
#define k_player_character_type_count k_player_character_type_count(BLOFELD_CONST_ARGS)
#define k_player_momentum_count k_player_momentum_count(BLOFELD_CONST_ARGS)
#define k_maximum_editable_material_types k_maximum_editable_material_types(BLOFELD_CONST_ARGS)
#define k_player_color_index_count k_player_color_index_count(BLOFELD_CONST_ARGS)
#define k_game_skull_count k_game_skull_count(BLOFELD_CONST_ARGS)
#define k_number_of_active_camo_levels k_number_of_active_camo_levels(BLOFELD_CONST_ARGS)
#define k_number_of_platforms k_number_of_platforms(BLOFELD_CONST_ARGS)
#define k_number_of_vertex_types k_number_of_vertex_types(BLOFELD_CONST_ARGS)
#define k_max_lines_per_scenario k_max_lines_per_scenario(BLOFELD_CONST_ARGS)
#define k_max_variants_per_line k_max_variants_per_line(BLOFELD_CONST_ARGS)
#define k_multiplayer_effect_maximum_count k_multiplayer_effect_maximum_count(BLOFELD_CONST_ARGS)
#define k_MaxVoiceoverLines k_MaxVoiceoverLines(BLOFELD_CONST_ARGS)
#define k_maximum_instance_placements_per_render_model k_maximum_instance_placements_per_render_model(BLOFELD_CONST_ARGS)
#define k_max_volume_samples_per_render_model k_max_volume_samples_per_render_model(BLOFELD_CONST_ARGS)
#define k_multiplayer_object_type_maximum_count k_multiplayer_object_type_maximum_count(BLOFELD_CONST_ARGS)
#define k_maximum_number_of_multiplayer_weapon_selections k_maximum_number_of_multiplayer_weapon_selections(BLOFELD_CONST_ARGS)
#define k_maximum_number_of_multiplayer_vehicle_selections k_maximum_number_of_multiplayer_vehicle_selections(BLOFELD_CONST_ARGS)
#define k_maximum_number_of_multiplayer_grenade_selections k_maximum_number_of_multiplayer_grenade_selections(BLOFELD_CONST_ARGS)
#define k_maximum_number_of_multiplayer_equipment_selections k_maximum_number_of_multiplayer_equipment_selections(BLOFELD_CONST_ARGS)
#define k_maximum_number_of_multiplayer_weapon_sets k_maximum_number_of_multiplayer_weapon_sets(BLOFELD_CONST_ARGS)
#define k_maximum_number_of_multiplayer_remap_table_entries k_maximum_number_of_multiplayer_remap_table_entries(BLOFELD_CONST_ARGS)
#define k_maximum_megalo_string_ids k_maximum_megalo_string_ids(BLOFELD_CONST_ARGS)
#define kshaderBlockCount kshaderBlockCount(BLOFELD_CONST_ARGS)
#define k_multiplayer_team_game_team_count k_multiplayer_team_game_team_count(BLOFELD_CONST_ARGS)
#define k_maximum_number_of_game_engine_roles k_maximum_number_of_game_engine_roles(BLOFELD_CONST_ARGS)
#define k_infinity_requisition_palette_maximum_count k_infinity_requisition_palette_maximum_count(BLOFELD_CONST_ARGS)
#define k_maximum_multiplayer_sounds k_maximum_multiplayer_sounds(BLOFELD_CONST_ARGS)
#define k_maximum_status_response_count k_maximum_status_response_count(BLOFELD_CONST_ARGS)
#define k_maximum_object_functions k_maximum_object_functions(BLOFELD_CONST_ARGS)
#define k_maximum_number_of_attachments_per_object k_maximum_number_of_attachments_per_object(BLOFELD_CONST_ARGS)
#define k_maximum_jetwash_points_per_object k_maximum_jetwash_points_per_object(BLOFELD_CONST_ARGS)
#define k_object_change_color_count k_object_change_color_count(BLOFELD_CONST_ARGS)
#define k_maximum_multiplayer_object_blocks k_maximum_multiplayer_object_blocks(BLOFELD_CONST_ARGS)
#define k_chudPolyArtVertexMaxCount k_chudPolyArtVertexMaxCount(BLOFELD_CONST_ARGS)
#define k_pgcr_maximum_number_of_categories_per_bucket k_pgcr_maximum_number_of_categories_per_bucket(BLOFELD_CONST_ARGS)
#define k_pgcr_maximum_number_of_player_entries_per_category k_pgcr_maximum_number_of_player_entries_per_category(BLOFELD_CONST_ARGS)
#define k_pgcr_maximum_number_of_ai_entries_per_category k_pgcr_maximum_number_of_ai_entries_per_category(BLOFELD_CONST_ARGS)
#define k_damage_reporting_type_count k_damage_reporting_type_count(BLOFELD_CONST_ARGS)
#define k_maximumPlayerEnlistments k_maximumPlayerEnlistments(BLOFELD_CONST_ARGS)
#define k_maxPlayerGradeCount k_maxPlayerGradeCount(BLOFELD_CONST_ARGS)
#define k_max_hint_geometries k_max_hint_geometries(BLOFELD_CONST_ARGS)
#define k_max_climb_hints k_max_climb_hints(BLOFELD_CONST_ARGS)
#define k_max_flight_hints_per_bsp k_max_flight_hints_per_bsp(BLOFELD_CONST_ARGS)
#define k_max_points_per_flight_hint k_max_points_per_flight_hint(BLOFELD_CONST_ARGS)
#define k_max_avoidance_volumes_per_bsp k_max_avoidance_volumes_per_bsp(BLOFELD_CONST_ARGS)
#define k_max_spline_hints_per_bsp k_max_spline_hints_per_bsp(BLOFELD_CONST_ARGS)
#define k_max_control_points_per_spline_hint k_max_control_points_per_spline_hint(BLOFELD_CONST_ARGS)
#define k_max_cookie_cutters k_max_cookie_cutters(BLOFELD_CONST_ARGS)
#define k_maximum_points_per_sector k_maximum_points_per_sector(BLOFELD_CONST_ARGS)
#define k_max_navmesh_areas k_max_navmesh_areas(BLOFELD_CONST_ARGS)
#define k_maximum_constraints_per_physics_model k_maximum_constraints_per_physics_model(BLOFELD_CONST_ARGS)
#define k_maximum_phantom_types_per_physics_model k_maximum_phantom_types_per_physics_model(BLOFELD_CONST_ARGS)
#define k_maximum_node_constraint_edges_per_physics_model k_maximum_node_constraint_edges_per_physics_model(BLOFELD_CONST_ARGS)
#define k_maximum_rigid_bodies_per_physics_model k_maximum_rigid_bodies_per_physics_model(BLOFELD_CONST_ARGS)
#define k_maximum_materials_per_physics_model k_maximum_materials_per_physics_model(BLOFELD_CONST_ARGS)
#define k_maximum_shapes_per_physics_model k_maximum_shapes_per_physics_model(BLOFELD_CONST_ARGS)
#define k_maximum_four_vectors_per_physics_model k_maximum_four_vectors_per_physics_model(BLOFELD_CONST_ARGS)
#define k_maximum_plane_equations_per_physics_model k_maximum_plane_equations_per_physics_model(BLOFELD_CONST_ARGS)
#define k_maximum_inertia_tensors_per_physics_model k_maximum_inertia_tensors_per_physics_model(BLOFELD_CONST_ARGS)
#define k_maximum_list_shapes_per_physics_model k_maximum_list_shapes_per_physics_model(BLOFELD_CONST_ARGS)
#define k_maximum_phantoms_per_physics_model k_maximum_phantoms_per_physics_model(BLOFELD_CONST_ARGS)
#define k_maximum_cache_file_codecs k_maximum_cache_file_codecs(BLOFELD_CONST_ARGS)
#define k_maximum_cache_file_shared_files k_maximum_cache_file_shared_files(BLOFELD_CONST_ARGS)
#define k_maximum_number_of_model_customization_selections_per_area k_maximum_number_of_model_customization_selections_per_area(BLOFELD_CONST_ARGS)
#define k_maximum_number_of_model_customization_bits_per_selection k_maximum_number_of_model_customization_bits_per_selection(BLOFELD_CONST_ARGS)
#define k_maxPortraitPoses k_maxPortraitPoses(BLOFELD_CONST_ARGS)
#define k_maximum_material_responses k_maximum_material_responses(BLOFELD_CONST_ARGS)
#define k_maxProjectileSoundRTPCBlocks k_maxProjectileSoundRTPCBlocks(BLOFELD_CONST_ARGS)
#define k_dimensions_in_3d_count k_dimensions_in_3d_count(BLOFELD_CONST_ARGS)
#define k_maximumSoundBanksPerTag k_maximumSoundBanksPerTag(BLOFELD_CONST_ARGS)
#define k_structure_seam_maximum_seam_count k_structure_seam_maximum_seam_count(BLOFELD_CONST_ARGS)
#define k_structure_seam_maximum_edges_count k_structure_seam_maximum_edges_count(BLOFELD_CONST_ARGS)
#define k_structure_seam_maximum_clusters_on_seam_count k_structure_seam_maximum_clusters_on_seam_count(BLOFELD_CONST_ARGS)
#define k_bsp3d_node_child_index_bits k_bsp3d_node_child_index_bits(BLOFELD_CONST_ARGS)
#define k_super_node_child_indices_count k_super_node_child_indices_count(BLOFELD_CONST_ARGS)
#define k_super_node_node_count k_super_node_node_count(BLOFELD_CONST_ARGS)
#define k_bsp3d_maximum_super_node_count k_bsp3d_maximum_super_node_count(BLOFELD_CONST_ARGS)
#define k_short_max k_short_max(BLOFELD_CONST_ARGS)
#define k_maximum_scenario_object_datum_count k_maximum_scenario_object_datum_count(BLOFELD_CONST_ARGS)
#define k_max_cubemaps_per_cluster k_max_cubemaps_per_cluster(BLOFELD_CONST_ARGS)
#define k_max_cubemap_reference_point_count k_max_cubemap_reference_point_count(BLOFELD_CONST_ARGS)
#define k_maximum_breakable_surface_sets k_maximum_breakable_surface_sets(BLOFELD_CONST_ARGS)
#define k_maximum_cluster_sound_palette_entries_per_structure k_maximum_cluster_sound_palette_entries_per_structure(BLOFELD_CONST_ARGS)
#define k_maximum_cluster_to_instance_group_block_size k_maximum_cluster_to_instance_group_block_size(BLOFELD_CONST_ARGS)
#define k_external_instanced_geometry_max k_external_instanced_geometry_max(BLOFELD_CONST_ARGS)
#define k_maximum_sound_combiner_defintion_entry_count k_maximum_sound_combiner_defintion_entry_count(BLOFELD_CONST_ARGS)
#define k_maximum_machine_door_portal_associations k_maximum_machine_door_portal_associations(BLOFELD_CONST_ARGS)
#define k_maximum_occluding_portal_associations k_maximum_occluding_portal_associations(BLOFELD_CONST_ARGS)
#define k_maximum_scenario_zone_set_count k_maximum_scenario_zone_set_count(BLOFELD_CONST_ARGS)
#define k_maximum_audibility_room_count k_maximum_audibility_room_count(BLOFELD_CONST_ARGS)
#define k_maximum_map_variant_palettes k_maximum_map_variant_palettes(BLOFELD_CONST_ARGS)
#define k_maximum_map_variant_palette_entries k_maximum_map_variant_palette_entries(BLOFELD_CONST_ARGS)
#define k_maximum_object_variants_per_map_variant_palette_entry k_maximum_object_variants_per_map_variant_palette_entry(BLOFELD_CONST_ARGS)
#define k_max_squad_groups_per_map k_max_squad_groups_per_map(BLOFELD_CONST_ARGS)
#define k_maximum_squads_per_map k_maximum_squads_per_map(BLOFELD_CONST_ARGS)
#define k_maximum_spawn_formations_per_squad k_maximum_spawn_formations_per_squad(BLOFELD_CONST_ARGS)
#define k_maximum_spawn_points_per_squad k_maximum_spawn_points_per_squad(BLOFELD_CONST_ARGS)
#define k_max_zones_per_map k_max_zones_per_map(BLOFELD_CONST_ARGS)
#define k_max_firing_positions_per_zone k_max_firing_positions_per_zone(BLOFELD_CONST_ARGS)
#define k_max_areas_per_zone k_max_areas_per_zone(BLOFELD_CONST_ARGS)
#define k_max_flight_references_per_area k_max_flight_references_per_area(BLOFELD_CONST_ARGS)
#define k_max_squad_patrols_per_map k_max_squad_patrols_per_map(BLOFELD_CONST_ARGS)
#define k_max_members_per_squad_patrol k_max_members_per_squad_patrol(BLOFELD_CONST_ARGS)
#define k_max_points_per_squad_patrol k_max_points_per_squad_patrol(BLOFELD_CONST_ARGS)
#define k_max_squad_patrol_transitions k_max_squad_patrol_transitions(BLOFELD_CONST_ARGS)
#define k_max_squad_patrol_waypoints_per_transition k_max_squad_patrol_waypoints_per_transition(BLOFELD_CONST_ARGS)
#define k_max_ai_cues_per_level k_max_ai_cues_per_level(BLOFELD_CONST_ARGS)
#define k_max_task_distributions_per_cue k_max_task_distributions_per_cue(BLOFELD_CONST_ARGS)
#define k_max_scenes_per_scenario k_max_scenes_per_scenario(BLOFELD_CONST_ARGS)
#define k_max_roles_per_scene k_max_roles_per_scene(BLOFELD_CONST_ARGS)
#define k_max_point_sets_per_map k_max_point_sets_per_map(BLOFELD_CONST_ARGS)
#define k_max_animation_points_per_map k_max_animation_points_per_map(BLOFELD_CONST_ARGS)
#define k_maximum_scenario_cutscene_titles k_maximum_scenario_cutscene_titles(BLOFELD_CONST_ARGS)
#define k_maximum_areas_per_task k_maximum_areas_per_task(BLOFELD_CONST_ARGS)
#define k_max_flock_instances_per_map k_max_flock_instances_per_map(BLOFELD_CONST_ARGS)
#define k_max_sources_per_flock k_max_sources_per_flock(BLOFELD_CONST_ARGS)
#define k_max_destinations_per_flock k_max_destinations_per_flock(BLOFELD_CONST_ARGS)
#define k_maximum_scenario_editor_folders k_maximum_scenario_editor_folders(BLOFELD_CONST_ARGS)
#define k_maximum_objectives_per_map k_maximum_objectives_per_map(BLOFELD_CONST_ARGS)
#define k_maximum_opposing_objectives k_maximum_opposing_objectives(BLOFELD_CONST_ARGS)
#define k_maximum_tasks_per_objective k_maximum_tasks_per_objective(BLOFELD_CONST_ARGS)
#define k_max_points_per_task_direction k_max_points_per_task_direction(BLOFELD_CONST_ARGS)
#define k_maximum_designer_zone_count k_maximum_designer_zone_count(BLOFELD_CONST_ARGS)
#define e_scriptableLightRigMax e_scriptableLightRigMax(BLOFELD_CONST_ARGS)
#define k_maximum_scenario_cinematic_lighting_palette_entry_count k_maximum_scenario_cinematic_lighting_palette_entry_count(BLOFELD_CONST_ARGS)
#define k_maximum_campaign_metagame_scenario_completion_bonus_count k_maximum_campaign_metagame_scenario_completion_bonus_count(BLOFELD_CONST_ARGS)
#define k_max_cubemaps_per_scenario k_max_cubemaps_per_scenario(BLOFELD_CONST_ARGS)
#define k_maximum_budget_references_per_scenario k_maximum_budget_references_per_scenario(BLOFELD_CONST_ARGS)
#define k_maximum_scenario_ordnance_drop_sets k_maximum_scenario_ordnance_drop_sets(BLOFELD_CONST_ARGS)
#define k_maximum_random_ordnance_drop_points k_maximum_random_ordnance_drop_points(BLOFELD_CONST_ARGS)
#define k_maximum_unit_recordings_per_scenario k_maximum_unit_recordings_per_scenario(BLOFELD_CONST_ARGS)
#define k_maximum_random_ordnance_items k_maximum_random_ordnance_items(BLOFELD_CONST_ARGS)
#define k_maximum_instance_geometry_definitions_per_structure_bsp k_maximum_instance_geometry_definitions_per_structure_bsp(BLOFELD_CONST_ARGS)
#define k_maximum_interpolators_per_scenario k_maximum_interpolators_per_scenario(BLOFELD_CONST_ARGS)
#define k_global_wave_templates_count k_global_wave_templates_count(BLOFELD_CONST_ARGS)
#define k_language_count k_language_count(BLOFELD_CONST_ARGS)
#define k_maximum_cells_per_squad k_maximum_cells_per_squad(BLOFELD_CONST_ARGS)
#define k_maximum_palette_choices k_maximum_palette_choices(BLOFELD_CONST_ARGS)
#define k_spawn_influencer_type_count k_spawn_influencer_type_count(BLOFELD_CONST_ARGS)
#define k_vehicle_spawn_influencer_maximum_count k_vehicle_spawn_influencer_maximum_count(BLOFELD_CONST_ARGS)
#define k_projectile_spawn_influencer_maximum_count k_projectile_spawn_influencer_maximum_count(BLOFELD_CONST_ARGS)
#define k_equipment_spawn_influencer_maximum_count k_equipment_spawn_influencer_maximum_count(BLOFELD_CONST_ARGS)
#define k_maximum_behavior_count k_maximum_behavior_count(BLOFELD_CONST_ARGS)
#define k_maximum_number_of_camera_track_control_points k_maximum_number_of_camera_track_control_points(BLOFELD_CONST_ARGS)
#define k_maximum_sound_cache_file_gestalt_permutations k_maximum_sound_cache_file_gestalt_permutations(BLOFELD_CONST_ARGS)
#define k_maximum_sound_cache_file_gestalt_permutation_languages k_maximum_sound_cache_file_gestalt_permutation_languages(BLOFELD_CONST_ARGS)
#define k_player_training_count k_player_training_count(BLOFELD_CONST_ARGS)
#define k_maximumNumberOfStyleSheets k_maximumNumberOfStyleSheets(BLOFELD_CONST_ARGS)
#define k_maximum_multilingual_unicode_strings_per_string_list k_maximum_multilingual_unicode_strings_per_string_list(BLOFELD_CONST_ARGS)
#define k_maximum_strings_per_string_list k_maximum_strings_per_string_list(BLOFELD_CONST_ARGS)
#define k_maximumHudUnitSoundCues k_maximumHudUnitSoundCues(BLOFELD_CONST_ARGS)
#define k_powered_seats_count k_powered_seats_count(BLOFELD_CONST_ARGS)
#define k_maxSoundRTPCBlocks k_maxSoundRTPCBlocks(BLOFELD_CONST_ARGS)
#define k_maxSoundSweetenerBlocks k_maxSoundSweetenerBlocks(BLOFELD_CONST_ARGS)
#define k_max_vehicle_physics_transitions k_max_vehicle_physics_transitions(BLOFELD_CONST_ARGS)
#define k_max_squad_specifications_per_wave k_max_squad_specifications_per_wave(BLOFELD_CONST_ARGS)
#define k_melee_damage_class_count k_melee_damage_class_count(BLOFELD_CONST_ARGS)
#define k_weapon_trigger_count k_weapon_trigger_count(BLOFELD_CONST_ARGS)
#define k_weapon_barrel_count k_weapon_barrel_count(BLOFELD_CONST_ARGS)
#define k_projectile_maximum_custom_vectors k_projectile_maximum_custom_vectors(BLOFELD_CONST_ARGS)
#define k_first_person_weapon_offset_type_count k_first_person_weapon_offset_type_count(BLOFELD_CONST_ARGS)
#define k_weapon_barrel_effect_count k_weapon_barrel_effect_count(BLOFELD_CONST_ARGS)
#define k_maxWeaponSoundRTPCBlocks k_maxWeaponSoundRTPCBlocks(BLOFELD_CONST_ARGS)
#define k_maxWeaponSoundSweetenerBlocks k_maxWeaponSoundSweetenerBlocks(BLOFELD_CONST_ARGS)
#define k_maximum_game_engine_static_loadout_palettes k_maximum_game_engine_static_loadout_palettes(BLOFELD_CONST_ARGS)
#define k_survival_full_rounds_per_set k_survival_full_rounds_per_set(BLOFELD_CONST_ARGS)
#define k_maximum_survival_custom_skulls k_maximum_survival_custom_skulls(BLOFELD_CONST_ARGS)
#define k_maximum_number_of_screen_widgets k_maximum_number_of_screen_widgets(BLOFELD_CONST_ARGS)
#define k_cui_max_overlay_count k_cui_max_overlay_count(BLOFELD_CONST_ARGS)
#define k_maximum_cache_file_tag_resource_types k_maximum_cache_file_tag_resource_types(BLOFELD_CONST_ARGS)
#define k_numberOfResourcePriorities k_numberOfResourcePriorities(BLOFELD_CONST_ARGS)
#define k_maximum_simultaneous_tag_instances k_maximum_simultaneous_tag_instances(BLOFELD_CONST_ARGS)
#define k_maximum_categories_per_resource k_maximum_categories_per_resource(BLOFELD_CONST_ARGS)
#define k_maximum_category_rows_per_resource k_maximum_category_rows_per_resource(BLOFELD_CONST_ARGS)
#define k_maximum_tag_parentages_count k_maximum_tag_parentages_count(BLOFELD_CONST_ARGS)
#define k_maximum_number_of_platform_sound_playback_components k_maximum_number_of_platform_sound_playback_components(BLOFELD_CONST_ARGS)
#define k_max_biped_grab_object_animation_sets k_max_biped_grab_object_animation_sets(BLOFELD_CONST_ARGS)
#define k_structure_seam_maximum_points_count k_structure_seam_maximum_points_count(BLOFELD_CONST_ARGS)
#define k_structure_seam_maximum_planes_count k_structure_seam_maximum_planes_count(BLOFELD_CONST_ARGS)
#define k_structure_seam_maximum_triangles_count k_structure_seam_maximum_triangles_count(BLOFELD_CONST_ARGS)
#define k_maximum_structure_soft_ceilings_count k_maximum_structure_soft_ceilings_count(BLOFELD_CONST_ARGS)
#define k_maximum_structure_soft_ceiling_triangles k_maximum_structure_soft_ceiling_triangles(BLOFELD_CONST_ARGS)
#define k_maximum_structure_water_groups k_maximum_structure_water_groups(BLOFELD_CONST_ARGS)
#define k_maximum_structure_water_instances k_maximum_structure_water_instances(BLOFELD_CONST_ARGS)
#define k_maximum_structure_water_instance_planes k_maximum_structure_water_instance_planes(BLOFELD_CONST_ARGS)
#define k_maximum_structure_water_instance_debug_triangles k_maximum_structure_water_instance_debug_triangles(BLOFELD_CONST_ARGS)
#define k_maximum_structure_manifest_items_count k_maximum_structure_manifest_items_count(BLOFELD_CONST_ARGS)
#define k_maximum_promotion_rules_per_sound k_maximum_promotion_rules_per_sound(BLOFELD_CONST_ARGS)
#define k_maximum_sound_equalizer_bands k_maximum_sound_equalizer_bands(BLOFELD_CONST_ARGS)
#define k_vertices_per_triangle_count k_vertices_per_triangle_count(BLOFELD_CONST_ARGS)
#define k_maximum_anti_gravity_points_per_vehicle_physics_definition k_maximum_anti_gravity_points_per_vehicle_physics_definition(BLOFELD_CONST_ARGS)
#define k_maximum_friction_points_per_vehicle_physics_definition k_maximum_friction_points_per_vehicle_physics_definition(BLOFELD_CONST_ARGS)
#define k_animation_maximum_blend_screens k_animation_maximum_blend_screens(BLOFELD_CONST_ARGS)
#define k_max_tracked_feet k_max_tracked_feet(BLOFELD_CONST_ARGS)
#define k_max_cycles_per_tracked_foot k_max_cycles_per_tracked_foot(BLOFELD_CONST_ARGS)
#define k_max_fik_anchor_node_count k_max_fik_anchor_node_count(BLOFELD_CONST_ARGS)
#define k_animation_maximum_ik_chain_events k_animation_maximum_ik_chain_events(BLOFELD_CONST_ARGS)
#define k_animation_maximum_ik_chain_proxies k_animation_maximum_ik_chain_proxies(BLOFELD_CONST_ARGS)
#define k_animation_maximum_facial_wrinkle_events k_animation_maximum_facial_wrinkle_events(BLOFELD_CONST_ARGS)
#define k_animation_maximum_extended_events k_animation_maximum_extended_events(BLOFELD_CONST_ARGS)
#define k_animation_maximum_object_functions k_animation_maximum_object_functions(BLOFELD_CONST_ARGS)
#define k_animation_maximum_function_overlays k_animation_maximum_function_overlays(BLOFELD_CONST_ARGS)
#define k_animation_maximum_overlay_groups k_animation_maximum_overlay_groups(BLOFELD_CONST_ARGS)
#define k_animation_maximum_mixing_board_pose_overlays k_animation_maximum_mixing_board_pose_overlays(BLOFELD_CONST_ARGS)
#define k_animation_maximum_gaits k_animation_maximum_gaits(BLOFELD_CONST_ARGS)
#define k_animation_maximum_gait_groups k_animation_maximum_gait_groups(BLOFELD_CONST_ARGS)
#define k_max_ik_points k_max_ik_points(BLOFELD_CONST_ARGS)
#define k_max_ik_sets k_max_ik_sets(BLOFELD_CONST_ARGS)
#define k_max_ik_points_per_set k_max_ik_points_per_set(BLOFELD_CONST_ARGS)
#define k_animation_maximum_ik_chains k_animation_maximum_ik_chains(BLOFELD_CONST_ARGS)
#define k_max_modes_per_graph k_max_modes_per_graph(BLOFELD_CONST_ARGS)
#define k_max_weapon_classes k_max_weapon_classes(BLOFELD_CONST_ARGS)
#define k_max_object_space_offset_node_count k_max_object_space_offset_node_count(BLOFELD_CONST_ARGS)
#define k_max_weapon_types k_max_weapon_types(BLOFELD_CONST_ARGS)
#define k_max_animation_sets k_max_animation_sets(BLOFELD_CONST_ARGS)
#define k_max_animations_per_block k_max_animations_per_block(BLOFELD_CONST_ARGS)
#define k_max_death_and_damage_actions k_max_death_and_damage_actions(BLOFELD_CONST_ARGS)
#define k_total_damage_directions k_total_damage_directions(BLOFELD_CONST_ARGS)
#define k_total_damage_regions k_total_damage_regions(BLOFELD_CONST_ARGS)
#define k_max_transition_animations k_max_transition_animations(BLOFELD_CONST_ARGS)
#define k_max_ranged_actions k_max_ranged_actions(BLOFELD_CONST_ARGS)
#define k_max_gpu_properties k_max_gpu_properties(BLOFELD_CONST_ARGS)
#define k_max_gpu_functions k_max_gpu_functions(BLOFELD_CONST_ARGS)
#define k_max_gpu_colors k_max_gpu_colors(BLOFELD_CONST_ARGS)
#define k_max_radial_distributions_per_cue k_max_radial_distributions_per_cue(BLOFELD_CONST_ARGS)
#define k_max_probability_distributions_per_cue k_max_probability_distributions_per_cue(BLOFELD_CONST_ARGS)
#define k_max_character_distributions_per_cue k_max_character_distributions_per_cue(BLOFELD_CONST_ARGS)
#define k_max_weapon_distributions_per_cue k_max_weapon_distributions_per_cue(BLOFELD_CONST_ARGS)
#define k_hash_size k_hash_size(BLOFELD_CONST_ARGS)
#define k_maximum_number_of_object_salts k_maximum_number_of_object_salts(BLOFELD_CONST_ARGS)
#define k_dual_vmf_basis_real_coefficients_count k_dual_vmf_basis_real_coefficients_count(BLOFELD_CONST_ARGS)
#define k_animation_maximum_velocity_boundary_entries k_animation_maximum_velocity_boundary_entries(BLOFELD_CONST_ARGS)
#define k_number_of_model_states k_number_of_model_states(BLOFELD_CONST_ARGS)
#define k_vertices_per_line_count k_vertices_per_line_count(BLOFELD_CONST_ARGS)
#define k_vertices_per_quadrilateral_count k_vertices_per_quadrilateral_count(BLOFELD_CONST_ARGS)
#define k_int32_bits_bits k_int32_bits_bits(BLOFELD_CONST_ARGS)
#define k_model_flag_chunk_count k_model_flag_chunk_count(BLOFELD_CONST_ARGS)

#define k_flag_chunk_count k_flag_chunk_count(BLOFELD_CONST_ARGS)

#endif
}
