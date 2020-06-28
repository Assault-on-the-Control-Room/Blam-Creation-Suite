#define BLOFELD_TAG_DEFINITIONS 0
#include "tagdefinitions-private-pch.h"

namespace blofeld
{

	c_constant::c_constant(const char* name, uint32_t constant_value) :
		values()
	{
		for (std::pair<const char*, uint32_t>& value : values)
		{
			value = { name, constant_value };
		}
	}

	c_constant::c_constant(const char* name, std::initializer_list<std::pair<e_engine_type, uint32_t>> list) :
		values()
	{
		for (const std::pair<e_engine_type, uint32_t>& value : list)
		{
			for (uint32_t engine_type = value.first; engine_type < k_number_of_engine_types; engine_type++)
			{
				values[engine_type] = { name, value.second };
			}
		}
	}

	c_constant::c_constant(std::initializer_list<std::pair<e_engine_type, std::pair<const char*, uint32_t>>> list) :
		values()
	{
		for (const std::pair<e_engine_type, std::pair<const char*, uint32_t>>& value : list)
		{
			for (uint32_t engine_type = value.first; engine_type < k_number_of_engine_types; engine_type++)
			{
				values[engine_type] = value.second;
			}
		}
	}

	c_constant c_cinematic_shot_flags::k_flag_chunk_count =
	{
		"c_cinematic_shot_flags::k_flag_chunk_count",
		{
			{ _engine_type_not_set, 1 },
			{ _engine_type_gen3_xbox360, 2 }
		}
	};

	c_constant c_node_flags::k_flag_chunk_count =
	{
		"c_node_flags::k_flag_chunk_count",
		{
			{ _engine_type_not_set, 2 },
			{ _engine_type_haloreach, 8 },
			{ _engine_type_gen3_xbox360, 8 }
		}
	};

	// calculation variables
	static constexpr unsigned long __k_int32_bits_bits = 5;

	// manually calculated don't lose difficult 
	c_constant k_scenario_designer_zone_palette_count = { "k_scenario_designer_zone_palette_count", 17 };
	c_constant k_maximum_rooms_per_game = { "k_maximum_rooms_per_game", 1024 };
	c_constant k_maximum_audibility_door_count = { "k_maximum_audibility_door_count", 128 };

	// #UNCONFRMED: this validation is accepted for any value between 0 and 28, and any multiple of 32. The true value of this isn't known yet!
	const unsigned long __k_bsp3d_node_plane_index_bits = 28;
	static constexpr unsigned long validate___k_bsp3d_node_plane_index_bits = (1 << __k_bsp3d_node_plane_index_bits) > (2147483647L >> 2) ? (1 << __k_bsp3d_node_plane_index_bits) : (2147483647L >> 2);
	static_assert(validate___k_bsp3d_node_plane_index_bits == 536870911, "__k_bsp3d_node_plane_index_bits is invalid value");
	c_constant k_bsp3d_node_plane_index_bits = { "k_bsp3d_node_plane_index_bits", __k_bsp3d_node_plane_index_bits };

	// #UNCONFIRMED: this validation is accepted for any value between 128 and 256
	const unsigned long __k_maximum_breakable_surfaces_per_breakable_surface_set = 256;
	constexpr unsigned long validate___k_maximum_breakable_surfaces_per_breakable_surface_set = ((((__k_maximum_breakable_surfaces_per_breakable_surface_set)+(k_int32_bits - 1)) >> __k_int32_bits_bits));
	static_assert(validate___k_maximum_breakable_surfaces_per_breakable_surface_set == 8, "__k_maximum_breakable_surfaces_per_breakable_surface_set is invalid value");
	c_constant k_maximum_breakable_surfaces_per_breakable_surface_set = { "k_maximum_breakable_surfaces_per_breakable_surface_set", __k_maximum_breakable_surfaces_per_breakable_surface_set };

	// defines

	c_constant SHORT_MAX = { "SHORT_MAX", 32767 };
	c_constant UNSIGNED_SHORT_MAX = { "UNSIGNED_SHORT_MAX", 65535 };
	c_constant LONG_BITS = { "LONG_BITS", 32 };
	c_constant BYTE_MAX = { "BYTE_MAX", 255 };
	c_constant MAX_COMPOSITES_PER_GRAPH = { "MAX_COMPOSITES_PER_GRAPH", 256 };
	c_constant MAX_VALUES_PER_COMPOSITE_ENTRY = { "MAX_VALUES_PER_COMPOSITE_ENTRY", 16 };
	c_constant MAX_DEAD_ZONES_PER_COMPOSITE_AXIS = { "MAX_DEAD_ZONES_PER_COMPOSITE_AXIS", 16 };
	c_constant MAX_ENTRIES_PER_COMPOSITE = { "MAX_ENTRIES_PER_COMPOSITE", 256 };
	c_constant MAX_PHASE_SETS_PER_COMPOSITE = { "MAX_PHASE_SETS_PER_COMPOSITE", 16 };
	c_constant MAXIMUM_ERROR_REPORT_CATEGORIES = { "MAXIMUM_ERROR_REPORT_CATEGORIES", 512 };
	c_constant MAXIMUM_REPORTS_PER_ERROR_REPORT_CATEGORY = { "MAXIMUM_REPORTS_PER_ERROR_REPORT_CATEGORY", 1048576 };
	c_constant MAXIMUM_VERTICES_PER_ERROR_REPORT = { "MAXIMUM_VERTICES_PER_ERROR_REPORT", 1048576 };
	c_constant MAXIMUM_VECTORS_PER_ERROR_REPORT = { "MAXIMUM_VECTORS_PER_ERROR_REPORT", 1048576 };
	c_constant MAXIMUM_LINES_PER_ERROR_REPORT = { "MAXIMUM_LINES_PER_ERROR_REPORT", 1048576 };
	c_constant MAXIMUM_TRIANGLES_PER_ERROR_REPORT = { "MAXIMUM_TRIANGLES_PER_ERROR_REPORT", 1048576 };
	c_constant MAXIMUM_QUADS_PER_ERROR_REPORT = { "MAXIMUM_QUADS_PER_ERROR_REPORT", 1048576 };
	c_constant MAXIMUM_COMMENTS_PER_ERROR_REPORT = { "MAXIMUM_COMMENTS_PER_ERROR_REPORT", 1048576 };
	c_constant MAXIMUM_NUMBER_OF_ANTENNA_VERTICES = { "MAXIMUM_NUMBER_OF_ANTENNA_VERTICES", 20 };
	c_constant MAXIMUM_SEQUENCES_PER_BITMAP_GROUP = { "MAXIMUM_SEQUENCES_PER_BITMAP_GROUP", 256 };
	c_constant MAXIMUM_SPRITES_PER_SEQUENCE = { "MAXIMUM_SPRITES_PER_SEQUENCE", 128 };
	c_constant MAXIMUM_BITMAPS_PER_BITMAP_GROUP = { "MAXIMUM_BITMAPS_PER_BITMAP_GROUP", 65536 };

	c_constant MAXIMUM_REGIONS_PER_MODEL =
	{
		"MAXIMUM_REGIONS_PER_MODEL",
		{
			{ _engine_type_not_set, 16 },
			{ _engine_type_gen3_xbox360, 32 }
		}
	};

	c_constant MAXIMUM_PERMUTATIONS_PER_MODEL_REGION = { "MAXIMUM_PERMUTATIONS_PER_MODEL_REGION", 255 };
	c_constant NUMBER_OF_PROP_CLASSES = { "NUMBER_OF_PROP_CLASSES", 14 };
	c_constant NUMBER_OF_ACTOR_COMBAT_STATUS_LEVELS = { "NUMBER_OF_ACTOR_COMBAT_STATUS_LEVELS", 10 };
	c_constant MAX_CINEMATIC_SCENE_COUNT = { "MAX_CINEMATIC_SCENE_COUNT", 32 };
	c_constant MAX_CINEMATIC_SHOT_COUNT = { "MAX_CINEMATIC_SHOT_COUNT", 64 };
	c_constant MAXIMUM_MATERIALS_PER_MODEL = { "MAXIMUM_MATERIALS_PER_MODEL", 32 };
	c_constant MAXIMUM_BSPS_PER_COLLISION_REGION = { "MAXIMUM_BSPS_PER_COLLISION_REGION", 64 };
	c_constant MAXIMUM_PATHFINDING_SPHERES_PER_COLLISION_MODEL = { "MAXIMUM_PATHFINDING_SPHERES_PER_COLLISION_MODEL", 256 };
	c_constant MAXIMUM_NODES_PER_MODEL = { "MAXIMUM_NODES_PER_MODEL", 255 };
	c_constant MAXIMUM_COLORS_PER_COLOR_TABLE_GROUP = { "MAXIMUM_COLORS_PER_COLOR_TABLE_GROUP", 512 };
	c_constant MAXIMUM_DECORATOR_SETS_PER_SCENARIO = { "MAXIMUM_DECORATOR_SETS_PER_SCENARIO", 48 };
	c_constant MAXIMUM_DETAIL_OBJECT_TYPES_PER_COLLECTION = { "MAXIMUM_DETAIL_OBJECT_TYPES_PER_COLLECTION", 16 };
	c_constant MAXIMUM_SQUIRTERS_PER_FLUID_DYNAMICS = { "MAXIMUM_SQUIRTERS_PER_FLUID_DYNAMICS", 16 };
	c_constant MAXIMUM_INFLOWS_PER_FLUID_DYNAMICS = { "MAXIMUM_INFLOWS_PER_FLUID_DYNAMICS", 16 };
	c_constant MAXIMUM_OUTFLOWS_PER_FLUID_DYNAMICS = { "MAXIMUM_OUTFLOWS_PER_FLUID_DYNAMICS", 16 };
	c_constant MAXIMUM_OBSTACLES_PER_FLUID_DYNAMICS = { "MAXIMUM_OBSTACLES_PER_FLUID_DYNAMICS", 32 };
	c_constant MAXIMUM_STATES_PER_MODEL_PERMUTATION = { "MAXIMUM_STATES_PER_MODEL_PERMUTATION", 10 };
	c_constant MAXIMUM_DAMAGE_SECTIONS_PER_MODEL = { "MAXIMUM_DAMAGE_SECTIONS_PER_MODEL", 16 };
	c_constant MAXIMUM_RESPONSES_PER_DAMAGE_SECTION = { "MAXIMUM_RESPONSES_PER_DAMAGE_SECTION", 16 };
	c_constant MAXIMUM_DAMAGE_SEAT_INFOS_PER_MODEL = { "MAXIMUM_DAMAGE_SEAT_INFOS_PER_MODEL", 16 };
	c_constant MAXIMUM_DAMAGE_CONSTRAINT_INFOS_PER_MODEL = { "MAXIMUM_DAMAGE_CONSTRAINT_INFOS_PER_MODEL", 16 };
	c_constant MAXIMUM_MODEL_TARGETS_PER_MODEL = { "MAXIMUM_MODEL_TARGETS_PER_MODEL", 32 };
	c_constant MAXIMUM_GAME_INCIDENT_RESPONSES_PER_BLOCK = { "MAXIMUM_GAME_INCIDENT_RESPONSES_PER_BLOCK", 32 };
	c_constant MAXIMUM_CHALLENGES_TO_PROGRESS_PER_BLOCK = { "MAXIMUM_CHALLENGES_TO_PROGRESS_PER_BLOCK", 64 };
	c_constant MAXIMUM_TRACKS_PER_LOOPING_SOUND = { "MAXIMUM_TRACKS_PER_LOOPING_SOUND", 4 };
	c_constant MAXIMUM_DETAIL_SOUNDS_PER_LOOPING_SOUND = { "MAXIMUM_DETAIL_SOUNDS_PER_LOOPING_SOUND", 12 };
	c_constant NUMBER_OF_GLOBAL_SOUNDS = { "NUMBER_OF_GLOBAL_SOUNDS", 2 };
	c_constant MATERIAL_SHADER_MAX_SOURCE_FILES = { "MATERIAL_SHADER_MAX_SOURCE_FILES", 256 };
	c_constant MAXIMUM_MARKER_GROUPS_PER_RENDER_MODEL = { "MAXIMUM_MARKER_GROUPS_PER_RENDER_MODEL", 4096 };
	c_constant MAXIMUM_MARKERS_PER_RENDER_MODEL_MARKER_GROUP = { "MAXIMUM_MARKERS_PER_RENDER_MODEL_MARKER_GROUP", 256 };
	c_constant MAXIMUM_MATERIALS_PER_GEOMETRY = { "MAXIMUM_MATERIALS_PER_GEOMETRY", 1024 };
	c_constant MAXIMUM_BONE_GROUPS_PER_MODEL = { "MAXIMUM_BONE_GROUPS_PER_MODEL", 64 };
	c_constant MAXIMUM_NUMBER_OF_MULTIPLAYER_SCENARIOS = { "MAXIMUM_NUMBER_OF_MULTIPLAYER_SCENARIOS", 32 };
	c_constant MAXIMUM_SCENARIO_PLAYERS_PER_BLOCK = { "MAXIMUM_SCENARIO_PLAYERS_PER_BLOCK", 256 };
	c_constant MAXIMUM_WIDGETS_PER_OBJECT = { "MAXIMUM_WIDGETS_PER_OBJECT", 4 };
	c_constant MAXIMUM_NUMBER_OF_OBJECT_CHANGE_COLOR_INITIAL_PERMUTATIONS = { "MAXIMUM_NUMBER_OF_OBJECT_CHANGE_COLOR_INITIAL_PERMUTATIONS", 32 };
	c_constant MAXIMUM_NUMBER_OF_OBJECT_CHANGE_COLOR_FUNCTIONS = { "MAXIMUM_NUMBER_OF_OBJECT_CHANGE_COLOR_FUNCTIONS", 4 };
	c_constant MAXIMUM_VERTICES_PER_GEOMETRY_SECTION = { "MAXIMUM_VERTICES_PER_GEOMETRY_SECTION", 16777214 };
	c_constant MAXIMUM_ACTORS_PER_PERFORMANCE = { "MAXIMUM_ACTORS_PER_PERFORMANCE", 16 };
	c_constant MAXIMUM_LINES_PER_PERFORMANCE = { "MAXIMUM_LINES_PER_PERFORMANCE", 256 };
	c_constant MAXIMUM_SCRIPT_FRAGMENTS_PER_PERFORMANCE_LINE = { "MAXIMUM_SCRIPT_FRAGMENTS_PER_PERFORMANCE_LINE", 16 };
	c_constant MAXIMUM_POINT_INTERACTIONS_PER_PERFORMANCE_LINE = { "MAXIMUM_POINT_INTERACTIONS_PER_PERFORMANCE_LINE", 16 };
	c_constant MAXIMUM_ANIMATIONS_PER_PERFORMANCE_LINE = { "MAXIMUM_ANIMATIONS_PER_PERFORMANCE_LINE", 8 };
	c_constant MAXIMUM_SYNC_ACTIONS_PER_PERFORMANCE_LINE = { "MAXIMUM_SYNC_ACTIONS_PER_PERFORMANCE_LINE", 8 };
	c_constant MAXIMUM_SCENERY_SYNC_ACTIONS_PER_PERFORMANCE_LINE = { "MAXIMUM_SCENERY_SYNC_ACTIONS_PER_PERFORMANCE_LINE", 8 };
	c_constant MAXIMUM_DIALOG_LINES_PER_PERFORMANCE_LINE = { "MAXIMUM_DIALOG_LINES_PER_PERFORMANCE_LINE", 4 };
	c_constant MAXIMUM_SOUNDS_PER_PERFORMANCE_LINE = { "MAXIMUM_SOUNDS_PER_PERFORMANCE_LINE", 4 };
	c_constant MAXIMUM_STRUCTURE_BSPS_PER_SCENARIO = { "MAXIMUM_STRUCTURE_BSPS_PER_SCENARIO", 32 };
	c_constant MAX_NUM_MOBILE_NAVMESHES = { "MAX_NUM_MOBILE_NAVMESHES", 128 };
	c_constant MAX_NUM_NAV_VOLUMES = { "MAX_NUM_NAV_VOLUMES", 256 };
	c_constant MAX_NUM_NAV_CLIMBS = { "MAX_NUM_NAV_CLIMBS", 256 };
	c_constant MAXIMUM_COLLISION_MATERIALS_PER_STRUCTURE = { "MAXIMUM_COLLISION_MATERIALS_PER_STRUCTURE", 512 };
	c_constant MAXIMUM_CLUSTER_PORTALS_PER_STRUCTURE = { "MAXIMUM_CLUSTER_PORTALS_PER_STRUCTURE", 1000 };
	c_constant MAXIMUM_VERTICES_PER_CLUSTER_PORTAL = { "MAXIMUM_VERTICES_PER_CLUSTER_PORTAL", 128 };
	c_constant MAXIMUM_DETAIL_OBJECT_CELLS_PER_STRUCTURE = { "MAXIMUM_DETAIL_OBJECT_CELLS_PER_STRUCTURE", 262144 };
	c_constant MAXIMUM_DETAIL_OBJECTS_PER_STRUCTURE = { "MAXIMUM_DETAIL_OBJECTS_PER_STRUCTURE", 2097152 };
	c_constant MAXIMUM_CLUSTERS_PER_STRUCTURE = { "MAXIMUM_CLUSTERS_PER_STRUCTURE", 255 };
	c_constant MAXIMUM_CLUSTER_PORTALS_PER_CLUSTER = { "MAXIMUM_CLUSTER_PORTALS_PER_CLUSTER", 512 };
	c_constant MAXIMUM_BLOCKS_PER_CLUSTER = { "MAXIMUM_BLOCKS_PER_CLUSTER", 1429968 };
	c_constant MAXIMUM_MARKERS_PER_STRUCTURE = { "MAXIMUM_MARKERS_PER_STRUCTURE", 1024 };
	c_constant MAXIMUM_SKIES_PER_SCENARIO = { "MAXIMUM_SKIES_PER_SCENARIO", 32 };
	c_constant MAXIMUM_DECALS_PER_STRUCTURE = { "MAXIMUM_DECALS_PER_STRUCTURE", 6144 };
	c_constant MAXIMUM_ENVIRONMENT_OBJECT_PALETTE_ENTRIES_PER_STRUCTURE = { "MAXIMUM_ENVIRONMENT_OBJECT_PALETTE_ENTRIES_PER_STRUCTURE", 1024 };
	c_constant MAXIMUM_ENVIRONMENT_OBJECTS_PER_STRUCTURE = { "MAXIMUM_ENVIRONMENT_OBJECTS_PER_STRUCTURE", 16384 };
	c_constant MAXIMUM_FACES_PER_MAP_LEAF = { "MAXIMUM_FACES_PER_MAP_LEAF", 1048576 };
	c_constant MAXIMUM_VERTICES_PER_LEAF_CONNECTION = { "MAXIMUM_VERTICES_PER_LEAF_CONNECTION", 512 };
	c_constant MAXIMUM_CONNECTIONS_PER_MAP_LEAF = { "MAXIMUM_CONNECTIONS_PER_MAP_LEAF", 1048576 };
	c_constant MAXIMUM_CONNECTIONS_PER_LEAF_MAP = { "MAXIMUM_CONNECTIONS_PER_LEAF_MAP", 1073741824 };
	c_constant MAXIMUM_FOG_PLANES_PER_STRUCTURE = { "MAXIMUM_FOG_PLANES_PER_STRUCTURE", 127 };
	c_constant MAXIMUM_FOG_ZONES_PER_STRUCTURE = { "MAXIMUM_FOG_ZONES_PER_STRUCTURE", 127 };
	c_constant MAXIMUM_CHILD_SCENARIOS_PER_SCENARIO = { "MAXIMUM_CHILD_SCENARIOS_PER_SCENARIO", 16 };
	c_constant MAXIMUM_STRUCTURE_DESIGNS_PER_SCENARIO = { "MAXIMUM_STRUCTURE_DESIGNS_PER_SCENARIO", 8 };
	c_constant MAXIMUM_FUNCTIONS_PER_SCENARIO = { "MAXIMUM_FUNCTIONS_PER_SCENARIO", 32 };
	c_constant MAXIMUM_EDITOR_COMMENTS = { "MAXIMUM_EDITOR_COMMENTS", 65536 };
	c_constant MAXIMUM_ENVIRONMENT_OBJECTS_PER_SCENARIO = { "MAXIMUM_ENVIRONMENT_OBJECTS_PER_SCENARIO", 4096 };
	c_constant MAXIMUM_OBJECT_NAMES_PER_SCENARIO = { "MAXIMUM_OBJECT_NAMES_PER_SCENARIO", 2048 };
	c_constant MAXIMUM_SCENERY_DATUMS_PER_SCENARIO = { "MAXIMUM_SCENERY_DATUMS_PER_SCENARIO", 2000 };
	c_constant MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK = { "MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK", 256 };
	c_constant MAXIMUM_BIPED_DATUMS_PER_SCENARIO = { "MAXIMUM_BIPED_DATUMS_PER_SCENARIO", 256 };
	c_constant MAXIMUM_VEHICLE_DATUMS_PER_SCENARIO = { "MAXIMUM_VEHICLE_DATUMS_PER_SCENARIO", 256 };
	c_constant MAXIMUM_EQUIPMENT_DATUMS_PER_SCENARIO = { "MAXIMUM_EQUIPMENT_DATUMS_PER_SCENARIO", 256 };
	c_constant MAXIMUM_WEAPON_DATUMS_PER_SCENARIO = { "MAXIMUM_WEAPON_DATUMS_PER_SCENARIO", 128 };
	c_constant MAXIMUM_DEVICE_GROUPS_PER_SCENARIO = { "MAXIMUM_DEVICE_GROUPS_PER_SCENARIO", 128 };
	c_constant MAXIMUM_MACHINE_DATUMS_PER_SCENARIO = { "MAXIMUM_MACHINE_DATUMS_PER_SCENARIO", 400 };
	c_constant MAXIMUM_TERMINAL_DATUMS_PER_SCENARIO = { "MAXIMUM_TERMINAL_DATUMS_PER_SCENARIO", 20 };
	c_constant MAXIMUM_CONTROL_DATUMS_PER_SCENARIO = { "MAXIMUM_CONTROL_DATUMS_PER_SCENARIO", 100 };
	c_constant MAXIMUM_DISPENSER_DATUMS_PER_SCENARIO = { "MAXIMUM_DISPENSER_DATUMS_PER_SCENARIO", 40 };
	c_constant MAXIMUM_SOUND_SCENERY_DATUMS_PER_SCENARIO = { "MAXIMUM_SOUND_SCENERY_DATUMS_PER_SCENARIO", 512 };
	c_constant MAXIMUM_GIANT_DATUMS_PER_SCENARIO = { "MAXIMUM_GIANT_DATUMS_PER_SCENARIO", 32 };
	c_constant MAXIMUM_EFFECT_SCENERY_DATUMS_PER_SCENARIO = { "MAXIMUM_EFFECT_SCENERY_DATUMS_PER_SCENARIO", 512 };
	c_constant MAXIMUM_SPAWNER_DATUMS_PER_SCENARIO = { "MAXIMUM_SPAWNER_DATUMS_PER_SCENARIO", 128 };
	c_constant MAXIMUM_BINK_PALETTE_ENTRIES_PER_BLOCK = { "MAXIMUM_BINK_PALETTE_ENTRIES_PER_BLOCK", 32 };
	c_constant MAXIMUM_REQUISITION_MENU_SIZE = { "MAXIMUM_REQUISITION_MENU_SIZE", 64 };
	c_constant MAXIMUM_SCENARIO_SOFT_CEILINGS_PER_SCENARIO = { "MAXIMUM_SCENARIO_SOFT_CEILINGS_PER_SCENARIO", 128 };
	c_constant MAXIMUM_TRIGGER_VOLUMES_PER_SCENARIO = { "MAXIMUM_TRIGGER_VOLUMES_PER_SCENARIO", 1024 };
	c_constant MAXIMUM_RECORDED_ANIMATIONS_PER_MAP = { "MAXIMUM_RECORDED_ANIMATIONS_PER_MAP", 1024 };
	c_constant MAXIMUM_DECALS_PER_SCENARIO = { "MAXIMUM_DECALS_PER_SCENARIO", 65536 };
	c_constant MAXIMUM_DECAL_PALETTES_PER_SCENARIO = { "MAXIMUM_DECAL_PALETTES_PER_SCENARIO", 128 };
	c_constant MAXIMUM_DETAIL_OBJECT_LAYERS_PER_STRUCTURE = { "MAXIMUM_DETAIL_OBJECT_LAYERS_PER_STRUCTURE", 32 };
	c_constant MAXIMUM_CUTSCENE_FLAGS_PER_SCENARIO = { "MAXIMUM_CUTSCENE_FLAGS_PER_SCENARIO", 4096 };
	c_constant MAXIMUM_CUTSCENE_CAMERA_POINTS_PER_SCENARIO = { "MAXIMUM_CUTSCENE_CAMERA_POINTS_PER_SCENARIO", 512 };
	c_constant MAXIMUM_ATMOSPHERE_PALETTE_ENTRIES_PER_STRUCTURE = { "MAXIMUM_ATMOSPHERE_PALETTE_ENTRIES_PER_STRUCTURE", 32 };
	c_constant MAXIMUM_CAMERA_FX_PALETTE_ENTRIES_PER_STRUCTURE = { "MAXIMUM_CAMERA_FX_PALETTE_ENTRIES_PER_STRUCTURE", 64 };
	c_constant MAXIMUM_WEATHER_PALETTE_ENTRIES_PER_STRUCTURE = { "MAXIMUM_WEATHER_PALETTE_ENTRIES_PER_STRUCTURE", 32 };
	c_constant MAXIMUM_CRATE_DATUMS_PER_SCENARIO = { "MAXIMUM_CRATE_DATUMS_PER_SCENARIO", 1536 };
	c_constant MAXIMUM_SUBTITLES_PER_SCENARIO = { "MAXIMUM_SUBTITLES_PER_SCENARIO", 1024 };
	c_constant MAXIMUM_CREATURE_DATUMS_PER_SCENARIO = { "MAXIMUM_CREATURE_DATUMS_PER_SCENARIO", 128 };
	c_constant MAXIMUM_DECORATOR_PALETTES_PER_SCENARIO = { "MAXIMUM_DECORATOR_PALETTES_PER_SCENARIO", 8 };
	c_constant MAXIMUM_DECORATOR_PLACEMENTS_PER_SET = { "MAXIMUM_DECORATOR_PLACEMENTS_PER_SET", 262144 };
	c_constant MAXIMUM_SCENARIO_CINEMATICS = { "MAXIMUM_SCENARIO_CINEMATICS", 32 };
	c_constant MAXIMUM_PERFORMANCES_PER_SCENARIO = { "MAXIMUM_PERFORMANCES_PER_SCENARIO", 256 };
	c_constant MAXIMUM_TASKS_PER_PERFORMANCE = { "MAXIMUM_TASKS_PER_PERFORMANCE", 8 };
	c_constant MAX_PUPPETS_PER_SHOW = { "MAX_PUPPETS_PER_SHOW", 32 };
	c_constant MAX_ACTIONS_PER_PUPPET = { "MAX_ACTIONS_PER_PUPPET", 256 };
	c_constant MAX_SUB_ACTIONS_PER_PUPPET = { "MAX_SUB_ACTIONS_PER_PUPPET", 256 };
	c_constant MAX_BRANCHES_PER_SUB_ACTION = { "MAX_BRANCHES_PER_SUB_ACTION", 8 };
	c_constant MAX_SUB_TRACKS = { "MAX_SUB_TRACKS", 20 };
	c_constant MAX_ACTIONS_PER_SHOW = { "MAX_ACTIONS_PER_SHOW", 256 };
	c_constant MAX_SUB_ACTIONS_PER_SHOW = { "MAX_SUB_ACTIONS_PER_SHOW", 256 };
	c_constant MAX_POINTS_PER_PATH = { "MAX_POINTS_PER_PATH", 32 };
	c_constant NUMBER_OF_SOUND_CLASSES = { "NUMBER_OF_SOUND_CLASSES", 71 };
	c_constant MAXIMUM_PERMUTATIONS_PER_PITCH_RANGE = { "MAXIMUM_PERMUTATIONS_PER_PITCH_RANGE", 32 };
	c_constant MAXIMUM_PITCH_RANGES_PER_SOUND = { "MAXIMUM_PITCH_RANGES_PER_SOUND", 17 };
	c_constant MAXIMUM_MARKERS_PER_PERMUTATION = { "MAXIMUM_MARKERS_PER_PERMUTATION", 65535 };
	c_constant MAXIMUM_SOUND_DATA_SIZE = { "MAXIMUM_SOUND_DATA_SIZE", 16777216 };
	c_constant MAXIMUM_POSTURES_PER_UNIT = { "MAXIMUM_POSTURES_PER_UNIT", 20 };
	c_constant MAXIMUM_DIALOGUE_VARIANTS_PER_UNIT = { "MAXIMUM_DIALOGUE_VARIANTS_PER_UNIT", 16 };
	c_constant MAXIMUM_INITIAL_WEAPONS_PER_UNIT = { "MAXIMUM_INITIAL_WEAPONS_PER_UNIT", 4 };
	c_constant MAXIMUM_SEATS_PER_UNIT_DEFINITION = { "MAXIMUM_SEATS_PER_UNIT_DEFINITION", 64 };
	c_constant MAXIMUM_NUMBER_OF_MAGAZINES_PER_WEAPON = { "MAXIMUM_NUMBER_OF_MAGAZINES_PER_WEAPON", 2 };
	c_constant MAXIMUM_NUMBER_OF_MAGAZINE_OBJECTS_PER_MAGAZINE = { "MAXIMUM_NUMBER_OF_MAGAZINE_OBJECTS_PER_MAGAZINE", 8 };
	c_constant MAXIMUM_RULES_PER_CA = { "MAXIMUM_RULES_PER_CA", 16 };
	c_constant MAXIMUM_STATES_PER_RULE = { "MAXIMUM_STATES_PER_RULE", 16 };
	c_constant MAXIMUM_NUMBER_OF_UNIT_CAMERA_TRACKS = { "MAXIMUM_NUMBER_OF_UNIT_CAMERA_TRACKS", 3 };
	c_constant WEAPON_SPECIFIC_MARKERS_COUNT = { "WEAPON_SPECIFIC_MARKERS_COUNT", 64 };
	c_constant MAXIMUM_CHARGING_FIRE_FRACTIONS_PER_TRIGGER = { "MAXIMUM_CHARGING_FIRE_FRACTIONS_PER_TRIGGER", 16 };
	c_constant MAXIMUM_DAMAGE_TRANSFERS_PER_MODEL = { "MAXIMUM_DAMAGE_TRANSFERS_PER_MODEL", 32 };
	c_constant NUMBER_OF_OBJECT_TYPES = { "NUMBER_OF_OBJECT_TYPES", 16 };
	c_constant MAXIMUM_NODE_INDICES_PER_ERROR_POINT = { "MAXIMUM_NODE_INDICES_PER_ERROR_POINT", 4 };


	c_constant k_maxEmblemIndicesPerItem = { "k_maxEmblemIndicesPerItem", 32 };
	c_constant k_max_triangulation_tag_triangles = { "k_max_triangulation_tag_triangles", 255 };
	c_constant k_max_sync_action_groups = { "k_max_sync_action_groups", 16 };
	c_constant k_max_sync_actions = { "k_max_sync_actions", 32 };
	c_constant k_max_sync_action_participants = { "k_max_sync_action_participants", 6 };
	c_constant k_max_vehicle_suspensions = { "k_max_vehicle_suspensions", 32 };
	c_constant k_max_function_overlays_per_graph = { "k_max_function_overlays_per_graph", 32 };
	c_constant k_max_animation_inheritence_levels = { "k_max_animation_inheritence_levels", 8 };
	c_constant k_max_triangulation_tag_points = { "k_max_triangulation_tag_points", 255 };
	c_constant k_firefightWavesPerGoal = { "k_firefightWavesPerGoal", 30 };
	c_constant k_firefightMaxPlayerGoals = { "k_firefightMaxPlayerGoals", 15 };
	c_constant k_maximum_survival_possible_wave_squads = { "k_maximum_survival_possible_wave_squads", 12 };
	c_constant k_cui_max_component_count = { "k_cui_max_component_count", 8192 };
	c_constant k_cui_max_property_binding_count = { "k_cui_max_property_binding_count", 1024 };
	c_constant k_cuiMaxEncapsulationCount = { "k_cuiMaxEncapsulationCount", 64 };
	c_constant k_cui_max_animation_count = { "k_cui_max_animation_count", 8192 };
	c_constant k_cui_max_property_count = { "k_cui_max_property_count", 8192 };
	c_constant k_first_person_interface_count = { "k_first_person_interface_count", 2 };
	c_constant k_animation_node_usage_count = { "k_animation_node_usage_count", 25 };
	c_constant k_animation_maximum_node_mask_count = { "k_animation_maximum_node_mask_count", 8 };
	c_constant k_animation_maximum_function_count = { "k_animation_maximum_function_count", 16 };
	c_constant k_animation_maximum_model_variants = { "k_animation_maximum_model_variants", 64 };
	c_constant k_animation_maximum_mode_or_stance_aliases = { "k_animation_maximum_mode_or_stance_aliases", 64 };
	c_constant k_meg = { "k_meg", 1048576 };
	c_constant k_num_ai_trait_weapon = { "k_num_ai_trait_weapon", 4 };
	c_constant k_maximum_number_of_sound_effect_templates = { "k_maximum_number_of_sound_effect_templates", 8 };
	c_constant k_maximum_number_of_sound_effect_parameters = { "k_maximum_number_of_sound_effect_parameters", 128 };
	c_constant k_max_airprobes_per_scenario = { "k_max_airprobes_per_scenario", 4096 };
	c_constant k_maximum_achievements = { "k_maximum_achievements", 256 };
	c_constant k_dialogue_type_count = { "k_dialogue_type_count", 158 };
	c_constant k_global_formations_count = { "k_global_formations_count", 128 };
	c_constant k_global_squad_template_folder_count = { "k_global_squad_template_folder_count", 32 };
	c_constant k_global_squad_templates_count = { "k_global_squad_templates_count", 128 };
	c_constant k_global_performance_template_folder_count = { "k_global_performance_template_folder_count", 32 };
	c_constant k_global_performance_templates_count = { "k_global_performance_templates_count", 128 };
	c_constant k_max_custom_stimuli_count = { "k_max_custom_stimuli_count", 128 };
	c_constant k_max_ai_cue_templates = { "k_max_ai_cue_templates", 32 };
	c_constant k_num_ai_trait_vision = { "k_num_ai_trait_vision", 5 };
	c_constant k_num_ai_trait_sound = { "k_num_ai_trait_sound", 4 };
	c_constant k_num_ai_trait_luck = { "k_num_ai_trait_luck", 5 };
	c_constant k_num_ai_trait_grenade = { "k_num_ai_trait_grenade", 4 };
	c_constant k_max_atmosphere_settings = { "k_max_atmosphere_settings", 16 };
	c_constant k_online_avatar_award_count = { "k_online_avatar_award_count", 3 };
	c_constant k_maximum_death_program_special_types = { "k_maximum_death_program_special_types", 5 };
	c_constant k_maximum_death_program_damage_types = { "k_maximum_death_program_damage_types", 12 };
	c_constant k_maximum_death_program_velocity_gates = { "k_maximum_death_program_velocity_gates", 2 };
	c_constant k_maximum_trick_definitions_per_unit = { "k_maximum_trick_definitions_per_unit", 8 };
	c_constant k_maximum_biped_proximity_feelers = { "k_maximum_biped_proximity_feelers", 4 };
	c_constant k_contact_point_count = { "k_contact_point_count", 3 };
	c_constant k_maxBipedSoundRTPCBlocks = { "k_maxBipedSoundRTPCBlocks", 16 };
	c_constant k_maxBipedSoundSweetenerBlocks = { "k_maxBipedSoundSweetenerBlocks", 16 };
	c_constant k_maximum_aiming_fixup_joints = { "k_maximum_aiming_fixup_joints", 2 };
	c_constant k_maxTightBoundsSets = { "k_maxTightBoundsSets", 5 };
	c_constant k_maximum_custom_app_count = { "k_maximum_custom_app_count", 64 };
	c_constant k_maximum_custom_app_damage_modifier_count = { "k_maximum_custom_app_damage_modifier_count", 16 };
	c_constant k_maximum_variants_per_model = { "k_maximum_variants_per_model", 64 };
	c_constant k_max_movement_sets = { "k_max_movement_sets", 8 };
	c_constant k_max_movement_variants = { "k_max_movement_variants", 8 };
	c_constant k_fp_evaluator_count = { "k_fp_evaluator_count", 69 };
	c_constant k_campaign_difficulty_levels_count = { "k_campaign_difficulty_levels_count", 4 };
	c_constant k_character_equipment_usage_when_count = { "k_character_equipment_usage_when_count", 8 };
	c_constant k_max_character_stimuli_responses = { "k_max_character_stimuli_responses", 16 };
	c_constant k_roomEnoughToConvertAllExistingCategories = { "k_roomEnoughToConvertAllExistingCategories", 5 };
	c_constant k_maximum_challenges_per_category = { "k_maximum_challenges_per_category", 200 };
	c_constant k_maximum_scene_shot_clip_plane_count = { "k_maximum_scene_shot_clip_plane_count", 32 };
	c_constant k_maximum_scene_shot_clip_subject_count = { "k_maximum_scene_shot_clip_subject_count", 24 };
	c_constant k_maximum_collision_spheres_per_cloth = { "k_maximum_collision_spheres_per_cloth", 8 };
	c_constant k_maximum_vertices_per_cloth = { "k_maximum_vertices_per_cloth", 121 };
	c_constant k_maximum_indices_per_cloth = { "k_maximum_indices_per_cloth", 1210 };
	c_constant k_maximum_links_per_cloth = { "k_maximum_links_per_cloth", 1210 };
	c_constant eCT_count = { "eCT_count", 2 };
	c_constant k_max_cookie_purchase_families = { "k_max_cookie_purchase_families", 30 };
	c_constant k_max_cookie_purchase_family_items = { "k_max_cookie_purchase_family_items", 200 };
	c_constant k_max_cookie_purchase_total_appearance_items = { "k_max_cookie_purchase_total_appearance_items", 512 };
	c_constant k_byte_bits = { "k_byte_bits", 8 };
	c_constant k_max_cookie_purchase_total_loadout_items = { "k_max_cookie_purchase_total_loadout_items", 96 };
	c_constant k_max_cookie_purchase_total_ordnance_items = { "k_max_cookie_purchase_total_ordnance_items", 32 };
	c_constant k_kilo = { "k_kilo", 1024 };
	c_constant k_maximum_effect_locations_count = { "k_maximum_effect_locations_count", 8 };
	c_constant k_maximum_effect_events_count = { "k_maximum_effect_events_count", 32 };
	c_constant k_maximum_effect_parts_per_event_count = { "k_maximum_effect_parts_per_event_count", 32 };
	c_constant k_maximum_effect_accelerations_per_event_count = { "k_maximum_effect_accelerations_per_event_count", 32 };
	c_constant k_maximum_effect_looping_sounds_count = { "k_maximum_effect_looping_sounds_count", 2 };
	c_constant k_effect_holdback_type_max = { "k_effect_holdback_type_max", 26 };
	c_constant k_effect_priority_max = { "k_effect_priority_max", 6 };
	c_constant k_equipmentMaxAbilityCount = { "k_equipmentMaxAbilityCount", 5 };
	c_constant k_maxEquipmentSoundRTPCBlocks = { "k_maxEquipmentSoundRTPCBlocks", 16 };
	c_constant k_maxEquipmentSoundSweetenerBlocks = { "k_maxEquipmentSoundSweetenerBlocks", 16 };
	c_constant k_material_effect_type_count = { "k_material_effect_type_count", 24 };
	c_constant k_maximum_material_effect_blocks = { "k_maximum_material_effect_blocks", 500 };
	c_constant k_forge_named_color_count = { "k_forge_named_color_count", 8 };
	c_constant k_max_primitives_per_formation = { "k_max_primitives_per_formation", 4 };
	c_constant k_max_points_per_primitive = { "k_max_points_per_primitive", 8 };
	c_constant k_max_sound_references_per_graph = { "k_max_sound_references_per_graph", 4096 };
	c_constant k_max_effect_references_per_graph = { "k_max_effect_references_per_graph", 4096 };
	c_constant k_max_frame_events = { "k_max_frame_events", 512 };
	c_constant k_maximum_game_engine_event_responses = { "k_maximum_game_engine_event_responses", 1000 };
	c_constant eUGT_count = { "eUGT_count", 8 };
	c_constant k_maximumNumberOfMultiplayerOrdnanceSelections = { "k_maximumNumberOfMultiplayerOrdnanceSelections", 64 };
	c_constant k_giant_buckle_total_types = { "k_giant_buckle_total_types", 3 };
	c_constant k_number_of_entry_points = { "k_number_of_entry_points", 40 };
	c_constant k_maximum_game_setting_blocks = { "k_maximum_game_setting_blocks", 205 };
	c_constant k_maximum_variant_category_blocks = { "k_maximum_variant_category_blocks", 16 };
	c_constant k_havok_group_count = { "k_havok_group_count", 31 };
	c_constant k_maximum_objects_per_model_variant = { "k_maximum_objects_per_model_variant", 31 };
	c_constant k_maximum_muted_nodes_per_model_variant = { "k_maximum_muted_nodes_per_model_variant", 31 };
	c_constant k_maximum_instance_groups_per_model = { "k_maximum_instance_groups_per_model", 256 };
	c_constant k_maximum_members_per_instance_group = { "k_maximum_members_per_instance_group", 32 };
	c_constant k_scenario_load_maximum_parameter_blocks = { "k_scenario_load_maximum_parameter_blocks", 32 };
	c_constant k_maximum_model_game_mode_types = { "k_maximum_model_game_mode_types", 4 };
	c_constant k_maximum_hs_source_files_per_context = { "k_maximum_hs_source_files_per_context", 128 };
	c_constant k_maximum_hs_scripts_per_context = { "k_maximum_hs_scripts_per_context", 3072 };
	c_constant k_maximum_hs_parameters_per_script = { "k_maximum_hs_parameters_per_script", 16 };
	c_constant k_maximum_hs_globals_per_context = { "k_maximum_hs_globals_per_context", 768 };
	c_constant k_maximum_hs_instanced_variables_per_context = { "k_maximum_hs_instanced_variables_per_context", 128 };
	c_constant k_maximum_hs_references_per_context = { "k_maximum_hs_references_per_context", 1024 };
	c_constant k_maximum_hs_unit_seat_mappings = { "k_maximum_hs_unit_seat_mappings", 65536 };
	c_constant k_maximum_hs_syntax_nodes_per_context = { "k_maximum_hs_syntax_nodes_per_context", 65023 };
	c_constant k_maximum_instance_geometry_instances_per_structure_bsp = { "k_maximum_instance_geometry_instances_per_structure_bsp", 8192 };
	c_constant k_infinityMaximumSeasonCount = { "k_infinityMaximumSeasonCount", 3 };
	c_constant k_infinityMaximumMissionsPerSeason = { "k_infinityMaximumMissionsPerSeason", 55 };
	c_constant k_max_nodes_per_animation = { "k_max_nodes_per_animation", 255 };
	c_constant k_max_animations_per_graph = { "k_max_animations_per_graph", 2048 };
	c_constant k_maximum_sandbox_property_values = { "k_maximum_sandbox_property_values", 64 };
	c_constant k_maximum_text_value_pairs_per_block = { "k_maximum_text_value_pairs_per_block", 100 };
	c_constant k_maximum_reflections_per_lens_flare = { "k_maximum_reflections_per_lens_flare", 32 };
	c_constant k_maximum_loadouts = { "k_maximum_loadouts", 128 };
	c_constant k_maximum_loadout_palettes = { "k_maximum_loadout_palettes", 64 };
	c_constant k_maximum_loadouts_per_palette = { "k_maximum_loadouts_per_palette", 5 };
	c_constant k_maximum_loadout_names = { "k_maximum_loadout_names", 128 };
	c_constant k_maximum_loadout_custom_slot_count = { "k_maximum_loadout_custom_slot_count", 5 };
	c_constant lightRigDirectionalCount = { "lightRigDirectionalCount", 16 };
	c_constant k_maximum_leaf_type_definitions = { "k_maximum_leaf_type_definitions", 16 };
	c_constant k_maximum_streaming_packs = { "k_maximum_streaming_packs", 20 };
	c_constant k_maximum_campaign_unspatialized_sounds = { "k_maximum_campaign_unspatialized_sounds", 64 };
	c_constant k_maximum_material_types = { "k_maximum_material_types", 512 };
	c_constant k_button_presets_count = { "k_button_presets_count", 7 };
	c_constant k_player_character_type_count = { "k_player_character_type_count", 3 };
	c_constant k_player_momentum_count = { "k_player_momentum_count", 2 };
	c_constant k_maximum_editable_material_types = { "k_maximum_editable_material_types", 256 };
	c_constant k_player_color_index_count = { "k_player_color_index_count", 32 };
	c_constant k_game_skull_count = { "k_game_skull_count", 17 };
	c_constant k_number_of_active_camo_levels = { "k_number_of_active_camo_levels", 5 };
	c_constant k_number_of_platforms = { "k_number_of_platforms", 2 };
	c_constant k_number_of_vertex_types = { "k_number_of_vertex_types", 54 };
	c_constant k_max_lines_per_scenario = { "k_max_lines_per_scenario", 500 };
	c_constant k_max_variants_per_line = { "k_max_variants_per_line", 10 };
	c_constant k_multiplayer_effect_maximum_count = { "k_multiplayer_effect_maximum_count", 2048 };
	c_constant k_MaxVoiceoverLines = { "k_MaxVoiceoverLines", 100 };
	c_constant k_maximum_instance_placements_per_render_model = { "k_maximum_instance_placements_per_render_model", 128 };
	c_constant k_max_volume_samples_per_render_model = { "k_max_volume_samples_per_render_model", 128 };
	c_constant k_multiplayer_object_type_maximum_count = { "k_multiplayer_object_type_maximum_count", 2048 };
	c_constant k_maximum_number_of_multiplayer_weapon_selections = { "k_maximum_number_of_multiplayer_weapon_selections", 64 };
	c_constant k_maximum_number_of_multiplayer_vehicle_selections = { "k_maximum_number_of_multiplayer_vehicle_selections", 64 };
	c_constant k_maximum_number_of_multiplayer_grenade_selections = { "k_maximum_number_of_multiplayer_grenade_selections", 8 };
	c_constant k_maximum_number_of_multiplayer_equipment_selections = { "k_maximum_number_of_multiplayer_equipment_selections", 32 };
	c_constant k_maximum_number_of_multiplayer_weapon_sets = { "k_maximum_number_of_multiplayer_weapon_sets", 32 };
	c_constant k_maximum_number_of_multiplayer_remap_table_entries = { "k_maximum_number_of_multiplayer_remap_table_entries", 32 };
	c_constant k_maximum_megalo_string_ids = { "k_maximum_megalo_string_ids", 255 };
	c_constant kshaderBlockCount = { "kshaderBlockCount", 10240 };
	c_constant k_multiplayer_team_game_team_count = { "k_multiplayer_team_game_team_count", 8 };
	c_constant k_maximum_number_of_game_engine_roles = { "k_maximum_number_of_game_engine_roles", 64 };
	c_constant k_infinity_requisition_palette_maximum_count = { "k_infinity_requisition_palette_maximum_count", 64 };
	c_constant k_maximum_multiplayer_sounds = { "k_maximum_multiplayer_sounds", 60 };
	c_constant k_maximum_status_response_count = { "k_maximum_status_response_count", 32 };
	c_constant k_maximum_object_functions = { "k_maximum_object_functions", 256 };
	c_constant k_maximum_number_of_attachments_per_object = { "k_maximum_number_of_attachments_per_object", 48 };
	c_constant k_maximum_jetwash_points_per_object = { "k_maximum_jetwash_points_per_object", 4 };
	c_constant k_object_change_color_count = { "k_object_change_color_count", 4 };
	c_constant k_maximum_multiplayer_object_blocks = { "k_maximum_multiplayer_object_blocks", 1 };
	c_constant k_chudPolyArtVertexMaxCount = { "k_chudPolyArtVertexMaxCount", 32768 };
	c_constant k_pgcr_maximum_number_of_categories_per_bucket = { "k_pgcr_maximum_number_of_categories_per_bucket", 128 };
	c_constant k_pgcr_maximum_number_of_player_entries_per_category = { "k_pgcr_maximum_number_of_player_entries_per_category", 1 };
	c_constant k_pgcr_maximum_number_of_ai_entries_per_category = { "k_pgcr_maximum_number_of_ai_entries_per_category", 16 };
	c_constant k_damage_reporting_type_count = { "k_damage_reporting_type_count", 98 };
	c_constant k_maximumPlayerEnlistments = { "k_maximumPlayerEnlistments", 16 };
	c_constant k_maxPlayerGradeCount = { "k_maxPlayerGradeCount", 127 };
	c_constant k_max_hint_geometries = { "k_max_hint_geometries", 1000 };
	c_constant k_max_climb_hints = { "k_max_climb_hints", 200 };
	c_constant k_max_flight_hints_per_bsp = { "k_max_flight_hints_per_bsp", 256 };
	c_constant k_max_points_per_flight_hint = { "k_max_points_per_flight_hint", 10 };
	c_constant k_max_avoidance_volumes_per_bsp = { "k_max_avoidance_volumes_per_bsp", 512 };
	c_constant k_max_spline_hints_per_bsp = { "k_max_spline_hints_per_bsp", 256 };
	c_constant k_max_control_points_per_spline_hint = { "k_max_control_points_per_spline_hint", 32 };
	c_constant k_max_cookie_cutters = { "k_max_cookie_cutters", 512 };
	c_constant k_maximum_points_per_sector = { "k_maximum_points_per_sector", 32 };
	c_constant k_max_navmesh_areas = { "k_max_navmesh_areas", 512 };
	c_constant k_maximum_constraints_per_physics_model = { "k_maximum_constraints_per_physics_model", 64 };
	c_constant k_maximum_phantom_types_per_physics_model = { "k_maximum_phantom_types_per_physics_model", 16 };
	c_constant k_maximum_node_constraint_edges_per_physics_model = { "k_maximum_node_constraint_edges_per_physics_model", 4096 };
	c_constant k_maximum_rigid_bodies_per_physics_model = { "k_maximum_rigid_bodies_per_physics_model", 64 };
	c_constant k_maximum_materials_per_physics_model = { "k_maximum_materials_per_physics_model", 64 };
	c_constant k_maximum_shapes_per_physics_model = { "k_maximum_shapes_per_physics_model", 16384 };
	c_constant k_maximum_four_vectors_per_physics_model = { "k_maximum_four_vectors_per_physics_model", 24576 };
	c_constant k_maximum_plane_equations_per_physics_model = { "k_maximum_plane_equations_per_physics_model", 131072 };
	c_constant k_maximum_inertia_tensors_per_physics_model = { "k_maximum_inertia_tensors_per_physics_model", 1024 };
	c_constant k_maximum_list_shapes_per_physics_model = { "k_maximum_list_shapes_per_physics_model", 4096 };
	c_constant k_maximum_phantoms_per_physics_model = { "k_maximum_phantoms_per_physics_model", 128 };
	c_constant k_maximum_cache_file_codecs = { "k_maximum_cache_file_codecs", 127 };
	c_constant k_maximum_cache_file_shared_files = { "k_maximum_cache_file_shared_files", 7 };
	c_constant k_maximum_number_of_model_customization_selections_per_area = { "k_maximum_number_of_model_customization_selections_per_area", 96 };
	c_constant k_maximum_number_of_model_customization_bits_per_selection = { "k_maximum_number_of_model_customization_bits_per_selection", 32 };
	c_constant k_maxPortraitPoses = { "k_maxPortraitPoses", 32 };
	c_constant k_maximum_material_responses = { "k_maximum_material_responses", 200 };
	c_constant k_maxProjectileSoundRTPCBlocks = { "k_maxProjectileSoundRTPCBlocks", 16 };
	c_constant k_dimensions_in_3d_count = { "k_dimensions_in_3d_count", 3 };
	c_constant k_maximumSoundBanksPerTag = { "k_maximumSoundBanksPerTag", 8 };
	c_constant k_structure_seam_maximum_seam_count = { "k_structure_seam_maximum_seam_count", 128 };
	c_constant k_structure_seam_maximum_edges_count = { "k_structure_seam_maximum_edges_count", 32767 };
	c_constant k_structure_seam_maximum_clusters_on_seam_count = { "k_structure_seam_maximum_clusters_on_seam_count", 255 };
	c_constant k_bsp3d_node_child_index_bits = { "k_bsp3d_node_child_index_bits", 24 };
	c_constant k_super_node_child_indices_count = { "k_super_node_child_indices_count", 16 };
	c_constant k_super_node_node_count = { "k_super_node_node_count", 15 };
	c_constant k_bsp3d_maximum_super_node_count = { "k_bsp3d_maximum_super_node_count", 2048 };
	c_constant k_short_max = { "k_short_max", 32767 };
	c_constant k_maximum_scenario_object_datum_count = { "k_maximum_scenario_object_datum_count", 6304 };
	c_constant k_max_cubemaps_per_cluster = { "k_max_cubemaps_per_cluster", 32 };
	c_constant k_max_cubemap_reference_point_count = { "k_max_cubemap_reference_point_count", 15 };
	c_constant k_maximum_breakable_surface_sets = { "k_maximum_breakable_surface_sets", 2048 };
	c_constant k_maximum_cluster_sound_palette_entries_per_structure = { "k_maximum_cluster_sound_palette_entries_per_structure", 128 };
	c_constant k_maximum_cluster_to_instance_group_block_size = { "k_maximum_cluster_to_instance_group_block_size", 4096 };
	c_constant k_external_instanced_geometry_max = { "k_external_instanced_geometry_max", 4096 };
	c_constant k_maximum_sound_combiner_defintion_entry_count = { "k_maximum_sound_combiner_defintion_entry_count", 32 };
	c_constant k_maximum_machine_door_portal_associations = { "k_maximum_machine_door_portal_associations", 128 };
	c_constant k_maximum_occluding_portal_associations = { "k_maximum_occluding_portal_associations", 128 };
	c_constant k_maximum_scenario_zone_set_count = { "k_maximum_scenario_zone_set_count", 64 };
	c_constant k_maximum_audibility_room_count = { "k_maximum_audibility_room_count", 1024 };
	c_constant k_maximum_map_variant_palettes = { "k_maximum_map_variant_palettes", 16 };
	c_constant k_maximum_map_variant_palette_entries = { "k_maximum_map_variant_palette_entries", 256 };
	c_constant k_maximum_object_variants_per_map_variant_palette_entry = { "k_maximum_object_variants_per_map_variant_palette_entry", 32 };
	c_constant k_max_squad_groups_per_map = { "k_max_squad_groups_per_map", 130 };
	c_constant k_maximum_squads_per_map = { "k_maximum_squads_per_map", 256 };
	c_constant k_maximum_spawn_formations_per_squad = { "k_maximum_spawn_formations_per_squad", 8 };
	c_constant k_maximum_spawn_points_per_squad = { "k_maximum_spawn_points_per_squad", 128 };
	c_constant k_max_zones_per_map = { "k_max_zones_per_map", 128 };
	c_constant k_max_firing_positions_per_zone = { "k_max_firing_positions_per_zone", 2048 };
	c_constant k_max_areas_per_zone = { "k_max_areas_per_zone", 128 };
	c_constant k_max_flight_references_per_area = { "k_max_flight_references_per_area", 10 };
	c_constant k_max_squad_patrols_per_map = { "k_max_squad_patrols_per_map", 16 };
	c_constant k_max_members_per_squad_patrol = { "k_max_members_per_squad_patrol", 64 };
	c_constant k_max_points_per_squad_patrol = { "k_max_points_per_squad_patrol", 48 };
	c_constant k_max_squad_patrol_transitions = { "k_max_squad_patrol_transitions", 256 };
	c_constant k_max_squad_patrol_waypoints_per_transition = { "k_max_squad_patrol_waypoints_per_transition", 10 };
	c_constant k_max_ai_cues_per_level = { "k_max_ai_cues_per_level", 256 };
	c_constant k_max_task_distributions_per_cue = { "k_max_task_distributions_per_cue", 16 };
	c_constant k_max_scenes_per_scenario = { "k_max_scenes_per_scenario", 100 };
	c_constant k_max_roles_per_scene = { "k_max_roles_per_scene", 10 };
	c_constant k_max_point_sets_per_map = { "k_max_point_sets_per_map", 200 };
	c_constant k_max_animation_points_per_map = { "k_max_animation_points_per_map", 256 };
	c_constant k_maximum_scenario_cutscene_titles = { "k_maximum_scenario_cutscene_titles", 128 };
	c_constant k_maximum_areas_per_task = { "k_maximum_areas_per_task", 64 };
	c_constant k_max_flock_instances_per_map = { "k_max_flock_instances_per_map", 50 };
	c_constant k_max_sources_per_flock = { "k_max_sources_per_flock", 10 };
	c_constant k_max_destinations_per_flock = { "k_max_destinations_per_flock", 10 };
	c_constant k_maximum_scenario_editor_folders = { "k_maximum_scenario_editor_folders", 32767 };
	c_constant k_maximum_objectives_per_map = { "k_maximum_objectives_per_map", 64 };
	c_constant k_maximum_opposing_objectives = { "k_maximum_opposing_objectives", 4 };
	c_constant k_maximum_tasks_per_objective = { "k_maximum_tasks_per_objective", 100 };
	c_constant k_max_points_per_task_direction = { "k_max_points_per_task_direction", 8 };
	c_constant k_maximum_designer_zone_count = 
	{ 
		"k_maximum_designer_zone_count", 
		{
			{ _engine_type_not_set, 32 },
			{ _engine_type_haloreach, 32 }, // #NOTE: Deduced as the block flags in cache_file_zone_set_zone_usage_block for reach is only 32bits
			{ _engine_type_gen3_xbox360, 64 },
		}
	};
	c_constant e_scriptableLightRigMax = { "e_scriptableLightRigMax", 128 };
	c_constant k_maximum_scenario_cinematic_lighting_palette_entry_count = { "k_maximum_scenario_cinematic_lighting_palette_entry_count", 128 };
	c_constant k_maximum_campaign_metagame_scenario_completion_bonus_count = { "k_maximum_campaign_metagame_scenario_completion_bonus_count", 8 };
	c_constant k_max_cubemaps_per_scenario = { "k_max_cubemaps_per_scenario", 1024 };
	c_constant k_maximum_budget_references_per_scenario = { "k_maximum_budget_references_per_scenario", 128 };
	c_constant k_maximum_scenario_ordnance_drop_sets = { "k_maximum_scenario_ordnance_drop_sets", 32 };
	c_constant k_maximum_random_ordnance_drop_points = { "k_maximum_random_ordnance_drop_points", 256 };
	c_constant k_maximum_unit_recordings_per_scenario = { "k_maximum_unit_recordings_per_scenario", 32 };
	c_constant k_maximum_random_ordnance_items = { "k_maximum_random_ordnance_items", 24 };
	c_constant k_maximum_instance_geometry_definitions_per_structure_bsp = { "k_maximum_instance_geometry_definitions_per_structure_bsp", 2048 };
	c_constant k_maximum_interpolators_per_scenario = { "k_maximum_interpolators_per_scenario", 32 };
	c_constant k_global_wave_templates_count = { "k_global_wave_templates_count", 128 };
	c_constant k_language_count = { "k_language_count", 17 };
	c_constant k_maximum_cells_per_squad = { "k_maximum_cells_per_squad", 10 };
	c_constant k_maximum_palette_choices = { "k_maximum_palette_choices", 8 };
	c_constant k_spawn_influencer_type_count = { "k_spawn_influencer_type_count", 16 };
	c_constant k_vehicle_spawn_influencer_maximum_count = { "k_vehicle_spawn_influencer_maximum_count", 18 };
	c_constant k_projectile_spawn_influencer_maximum_count = { "k_projectile_spawn_influencer_maximum_count", 32 };
	c_constant k_equipment_spawn_influencer_maximum_count = { "k_equipment_spawn_influencer_maximum_count", 18 };
	c_constant k_maximum_behavior_count = { "k_maximum_behavior_count", 256 };
	c_constant k_maximum_number_of_camera_track_control_points = { "k_maximum_number_of_camera_track_control_points", 16 };
	c_constant k_maximum_sound_cache_file_gestalt_permutations = { "k_maximum_sound_cache_file_gestalt_permutations", 1048575 };
	c_constant k_maximum_sound_cache_file_gestalt_permutation_languages = { "k_maximum_sound_cache_file_gestalt_permutation_languages", 1048575 };
	c_constant k_player_training_count = { "k_player_training_count", 35 };
	c_constant k_maximumNumberOfStyleSheets = { "k_maximumNumberOfStyleSheets", 64 };
	c_constant k_maximum_multilingual_unicode_strings_per_string_list = { "k_maximum_multilingual_unicode_strings_per_string_list", 34816 };
	c_constant k_maximum_strings_per_string_list = { "k_maximum_strings_per_string_list", 2048 };
	c_constant k_maximumHudUnitSoundCues = { "k_maximumHudUnitSoundCues", 16 };
	c_constant k_powered_seats_count = { "k_powered_seats_count", 2 };
	c_constant k_maxSoundRTPCBlocks = { "k_maxSoundRTPCBlocks", 16 };
	c_constant k_maxSoundSweetenerBlocks = { "k_maxSoundSweetenerBlocks", 16 };
	c_constant k_max_vehicle_physics_transitions = { "k_max_vehicle_physics_transitions", 4 };
	c_constant k_max_squad_specifications_per_wave = { "k_max_squad_specifications_per_wave", 16 };
	c_constant k_melee_damage_class_count = { "k_melee_damage_class_count", 2 };
	c_constant k_weapon_trigger_count = { "k_weapon_trigger_count", 2 };
	c_constant k_weapon_barrel_count = { "k_weapon_barrel_count", 2 };
	c_constant k_projectile_maximum_custom_vectors = { "k_projectile_maximum_custom_vectors", 16 };
	c_constant k_first_person_weapon_offset_type_count = { "k_first_person_weapon_offset_type_count", 3 };
	c_constant k_weapon_barrel_effect_count = { "k_weapon_barrel_effect_count", 5 };
	c_constant k_maxWeaponSoundRTPCBlocks = { "k_maxWeaponSoundRTPCBlocks", 16 };
	c_constant k_maxWeaponSoundSweetenerBlocks = { "k_maxWeaponSoundSweetenerBlocks", 16 };
	c_constant k_maximum_game_engine_static_loadout_palettes = { "k_maximum_game_engine_static_loadout_palettes", 6 };
	c_constant k_survival_full_rounds_per_set = { "k_survival_full_rounds_per_set", 3 };
	c_constant k_maximum_survival_custom_skulls = { "k_maximum_survival_custom_skulls", 3 };
	c_constant k_maximum_number_of_screen_widgets = { "k_maximum_number_of_screen_widgets", 256 };
	c_constant k_cui_max_overlay_count = { "k_cui_max_overlay_count", 24 };
	c_constant k_maximum_cache_file_tag_resource_types = { "k_maximum_cache_file_tag_resource_types", 16 };

	c_constant k_numberOfResourcePriorities =
	{
		"k_numberOfResourcePriorities",
		{
			{ _engine_type_not_set, 2 },
			{ _engine_type_haloreach, 2 },
			{ _engine_type_gen3_xbox360, 3 },
		}
	};

	c_constant k_maximum_simultaneous_tag_instances = { "k_maximum_simultaneous_tag_instances", 32767 };
	c_constant k_maximum_categories_per_resource = { "k_maximum_categories_per_resource", 32 };
	c_constant k_maximum_category_rows_per_resource = { "k_maximum_category_rows_per_resource", 128 };
	c_constant k_maximum_tag_parentages_count = { "k_maximum_tag_parentages_count", 65534 };
	c_constant k_maximum_number_of_platform_sound_playback_components = { "k_maximum_number_of_platform_sound_playback_components", 16 };
	c_constant k_max_biped_grab_object_animation_sets = { "k_max_biped_grab_object_animation_sets", 16 };
	c_constant k_structure_seam_maximum_points_count = { "k_structure_seam_maximum_points_count", 32767 };
	c_constant k_structure_seam_maximum_planes_count = { "k_structure_seam_maximum_planes_count", 32767 };
	c_constant k_structure_seam_maximum_triangles_count = { "k_structure_seam_maximum_triangles_count", 32767 };
	c_constant k_maximum_structure_soft_ceilings_count = { "k_maximum_structure_soft_ceilings_count", 128 };
	c_constant k_maximum_structure_soft_ceiling_triangles = { "k_maximum_structure_soft_ceiling_triangles", 32767 };
	c_constant k_maximum_structure_water_groups = { "k_maximum_structure_water_groups", 1024 };
	c_constant k_maximum_structure_water_instances = { "k_maximum_structure_water_instances", 1024 };
	c_constant k_maximum_structure_water_instance_planes = { "k_maximum_structure_water_instance_planes", 1024 };
	c_constant k_maximum_structure_water_instance_debug_triangles = { "k_maximum_structure_water_instance_debug_triangles", 8192 };
	c_constant k_maximum_structure_manifest_items_count = { "k_maximum_structure_manifest_items_count", 64 };
	c_constant k_maximum_promotion_rules_per_sound = { "k_maximum_promotion_rules_per_sound", 17 };
	c_constant k_maximum_sound_equalizer_bands = { "k_maximum_sound_equalizer_bands", 3 };
	c_constant k_vertices_per_triangle_count = { "k_vertices_per_triangle_count", 3 };
	c_constant k_maximum_anti_gravity_points_per_vehicle_physics_definition = { "k_maximum_anti_gravity_points_per_vehicle_physics_definition", 16 };
	c_constant k_maximum_friction_points_per_vehicle_physics_definition = { "k_maximum_friction_points_per_vehicle_physics_definition", 16 };
	c_constant k_animation_maximum_blend_screens = { "k_animation_maximum_blend_screens", 1024 };
	c_constant k_max_tracked_feet = { "k_max_tracked_feet", 32 };
	c_constant k_max_cycles_per_tracked_foot = { "k_max_cycles_per_tracked_foot", 64 };
	c_constant k_max_fik_anchor_node_count = { "k_max_fik_anchor_node_count", 5 };
	c_constant k_animation_maximum_ik_chain_events = { "k_animation_maximum_ik_chain_events", 32 };
	c_constant k_animation_maximum_ik_chain_proxies = { "k_animation_maximum_ik_chain_proxies", 8 };
	c_constant k_animation_maximum_facial_wrinkle_events = { "k_animation_maximum_facial_wrinkle_events", 32 };
	c_constant k_animation_maximum_extended_events = { "k_animation_maximum_extended_events", 32 };
	c_constant k_animation_maximum_object_functions = { "k_animation_maximum_object_functions", 4 };
	c_constant k_animation_maximum_function_overlays = { "k_animation_maximum_function_overlays", 32 };
	c_constant k_animation_maximum_overlay_groups = { "k_animation_maximum_overlay_groups", 1056 };
	c_constant k_animation_maximum_mixing_board_pose_overlays = { "k_animation_maximum_mixing_board_pose_overlays", 10 };
	c_constant k_animation_maximum_gaits = { "k_animation_maximum_gaits", 32 };
	c_constant k_animation_maximum_gait_groups = { "k_animation_maximum_gait_groups", 32 };
	c_constant k_max_ik_points = { "k_max_ik_points", 64 };
	c_constant k_max_ik_sets = { "k_max_ik_sets", 32 };
	c_constant k_max_ik_points_per_set = { "k_max_ik_points_per_set", 8 };
	c_constant k_animation_maximum_ik_chains = { "k_animation_maximum_ik_chains", 4 };
	c_constant k_max_modes_per_graph = { "k_max_modes_per_graph", 512 };
	c_constant k_max_weapon_classes = { "k_max_weapon_classes", 64 };
	c_constant k_max_object_space_offset_node_count = { "k_max_object_space_offset_node_count", 16 };
	c_constant k_max_weapon_types = { "k_max_weapon_types", 64 };
	c_constant k_max_animation_sets = { "k_max_animation_sets", 64 };
	c_constant k_max_animations_per_block = { "k_max_animations_per_block", 256 };
	c_constant k_max_death_and_damage_actions = { "k_max_death_and_damage_actions", 8 };
	c_constant k_total_damage_directions = { "k_total_damage_directions", 4 };
	c_constant k_total_damage_regions = { "k_total_damage_regions", 11 };
	c_constant k_max_transition_animations = { "k_max_transition_animations", 32 };
	c_constant k_max_ranged_actions = { "k_max_ranged_actions", 16 };
	c_constant k_max_gpu_properties = { "k_max_gpu_properties", 17 };
	c_constant k_max_gpu_functions = { "k_max_gpu_functions", 25 };
	c_constant k_max_gpu_colors = { "k_max_gpu_colors", 8 };
	c_constant k_max_radial_distributions_per_cue = { "k_max_radial_distributions_per_cue", 1 };
	c_constant k_max_probability_distributions_per_cue = { "k_max_probability_distributions_per_cue", 1 };
	c_constant k_max_character_distributions_per_cue = { "k_max_character_distributions_per_cue", 8 };
	c_constant k_max_weapon_distributions_per_cue = { "k_max_weapon_distributions_per_cue", 8 };
	c_constant k_hash_size = { "k_hash_size", 20 };
	c_constant k_maximum_number_of_object_salts = { "k_maximum_number_of_object_salts", 32 };
	c_constant k_dual_vmf_basis_real_coefficients_count = { "k_dual_vmf_basis_real_coefficients_count", 16 };
	c_constant k_animation_maximum_velocity_boundary_entries = { "k_animation_maximum_velocity_boundary_entries", 8 };
	c_constant k_number_of_model_states = { "k_number_of_model_states", 5 };
	c_constant k_vertices_per_line_count = { "k_vertices_per_line_count", 2 };
	c_constant k_vertices_per_quadrilateral_count = { "k_vertices_per_quadrilateral_count", 4 };
	c_constant k_int32_bits_bits = { "k_int32_bits_bits", __k_int32_bits_bits };

}
