#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		prefab_group,
		PREFAB_TAG,
		nullptr,
		INVALID_TAG,
		prefab_block );

	V5_TAG_BLOCK(haloreach_sbsp_unknown_block, 65536)
	{
		{ _field_legacy, _field_real, "unknown@" },
		{ _field_legacy, _field_real, "unknown@" },
		{ _field_legacy, _field_real, "unknown@" },
		{ _field_legacy, _field_real, "unknown@" },
		{ _field_legacy, _field_real, "unknown@" },
		{ _field_legacy, _field_real, "unknown@" },
		{ _field_legacy, _field_real, "unknown@" },
		{ _field_legacy, _field_real, "unknown@" },
		{ _field_legacy, _field_real, "unknown@" },
		{ _field_legacy, _field_real, "unknown@" },
		{ _field_legacy, _field_real, "unknown@" },
		{ _field_legacy, _field_real, "unknown@" },
		{ _field_legacy, _field_real, "unknown@" },
		{ _field_legacy, _field_real, "unknown@" },
		{ _field_legacy, _field_real, "unknown@" },
		{ _field_legacy, _field_real, "unknown@" },
		{ _field_legacy, _field_real, "unknown@" },
		{ _field_legacy, _field_real, "unknown@" },
		{ _field_legacy, _field_real, "unknown@" },
		{ _field_legacy, _field_real, "unknown@" },
		{ _field_legacy, _field_real, "unknown@" },
		{ _field_legacy, _field_real, "unknown@" },
		{ _field_legacy, _field_real, "unknown@" },
		{ _field_legacy, _field_real, "unknown@" },
		{ _field_legacy, _field_real, "unknown@" },
		{ _field_legacy, _field_real, "unknown@" },
		{ _field_legacy, _field_real, "unknown@" },
		{ _field_legacy, _field_real, "unknown@" },
		{ _field_legacy, _field_real, "unknown@" },
		{ _field_legacy, _field_real, "unknown@" },
		{ _field_legacy, _field_terminator }
	};

	#define SCENARIO_STRUCTURE_BSP_STRUCT_DEFINITION_ID { 0x5043D2DD, 0xE3624E5A, 0xBB518106, 0x4E2109D4 }
	TAG_BLOCK(
		scenario_structure_bsp_block,
		"scenario_structure_bsp_block",
		1,
		"structure_bsp",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_RESOURCES | 
		SET_UNKNOWN14 | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_STRUCTURE_BSP_STRUCT_DEFINITION_ID)
	{
		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach, 2 },
		{ _field_struct, "build identifier", FIELD_FLAG_READ_ONLY, &structure_manifest_build_identifier_struct },
		{ _field_struct, "parent build identifier", FIELD_FLAG_READ_ONLY, &structure_manifest_build_identifier_struct },

		{ _field_long_integer, "import info checksum", FIELD_FLAG_READ_ONLY },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_tag_reference, "structure lighting_info", FIELD_FLAG_INDEX, &structure_lighting_bsp_reference },

		{ _field_long_integer, "import version", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_tag_reference, "structure meta data", FIELD_FLAG_READ_ONLY, &Tag::Reference<struct StructureMetadata>::s_defaultDefinition },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach, 4 },
		{ _field_word_flags, "flags", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &structure_bsp_flags_definition },
		{ _field_word_flags, "content policy flags", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &structure_bsp_content_policy_flag },
		{ _field_word_flags, "failed content policy flags", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &structure_bsp_content_policy_flag },
		FIELD_PAD("faild policy pad", nullptr, FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, 2),

		{ _field_legacy, _field_version_less, _engine_type_haloreach },
		{ _field_long_flags, "flags", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &structure_bsp_flags_definition },

		{ _field_block, "seam identifiers", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &structure_seam_mapping_block },
		{ _field_block, "edge to seam edge", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &structure_edge_to_seam_edge_mapping_block },
		{ _field_block, "collision materials", FIELD_FLAG_READ_ONLY, &structure_collision_materials_block },

		{ _field_legacy, _field_version_equal, _engine_type_halo3 },
		{ _field_legacy, _field_block, "collision bsp*", &global_collision_bsp_block },

		{ _field_block, "leaves", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &structure_bsp_leaf_block },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach, 5 },
		{ _field_block, "super aabbs", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &structure_super_node_aabbs_block },
		{ _field_block, "super node parent mappings", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &super_node_mappings_block },
		{ _field_block, "super node recursable_masks", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &super_node_recursable_masks_block },
		{ _field_block, "structure_super_node_traversal_geometry_block", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &structure_super_node_traversal_geometry_block },
		{ _field_struct, "instance kd hierarchy", FIELD_FLAG_UNKNOWN0, &collision_kd_hierarchy_static_struct },

		{ _field_legacy, _field_version_equal, _engine_type_haloreach },
		{ _field_legacy, _field_real, "unknown@" },

		{ _field_real_bounds, "world bounds x", FIELD_FLAG_READ_ONLY },
		{ _field_real_bounds, "world bounds y", FIELD_FLAG_READ_ONLY },
		{ _field_real_bounds, "world bounds z", FIELD_FLAG_READ_ONLY },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 1 },
		{ _field_block, "structure surfaces", FIELD_FLAG_READ_ONLY, &structure_surface_block }, //assumed readonly reach and below

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 1 },
		{ _field_block, "large structure surfaces", FIELD_FLAG_READ_ONLY, &structure_surface_block },

		{ _field_block, "structure surface to triangle mapping", FIELD_FLAG_READ_ONLY, &structure_surface_to_triangle_mapping_block },
		{ _field_block, "cluster portals", FIELD_FLAG_READ_ONLY, &structure_bsp_cluster_portal_block },

		{ _field_legacy, _field_version_less, _engine_type_haloreach, 4 },
		{ _field_legacy, _field_block, "unknown", &haloreach_sbsp_unknown_block_block },
		{ _field_legacy, _field_block, "atmosphere palette*", &scenario_atmosphere_palette_block },
		{ _field_legacy, _field_block, "camera fx palette", &scenario_camera_fx_palette_block },
		{ _field_legacy, _field_block, "weather palette", &scenario_weather_palette_block }, // #TODO: Confirm, based off observation with scenario_struct_definition and halo 2 guerilla

		{ _field_block, "detail objects", FIELD_FLAG_READ_ONLY, &structure_bsp_detail_object_data_block },
		{ _field_block, "clusters", FIELD_FLAG_READ_ONLY, &structure_bsp_cluster_block },
		{ _field_block, "materials", FIELD_FLAG_READ_ONLY, &global_geometry_material_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 1 },
		{ _field_block, "emissive materials", FIELD_FLAG_READ_ONLY, &structure_material_lighting_info_block },

		{ _field_block, "sky owner cluster", FIELD_FLAG_READ_ONLY, &structure_bsp_sky_owner_cluster_block },
		{ _field_block, "conveyor surfaces", FIELD_FLAG_READ_ONLY, &structure_bsp_conveyor_surface_block },
		{ _field_block, "breakable surface sets", FIELD_FLAG_READ_ONLY, &breakable_surface_set_block },
		{ _field_block, "pathfinding data", &pathfinding_data_block },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 1 },
		{ _field_legacy, _field_block, "unknown@", &g_null_block_block }, // unknown, potentially 

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach, 1 },
		{ _field_block, "cookie cutters", &structure_cookie_cutter_definition_block },

		{ _field_block, "acoustics palette", &scenario_acoustics_palette_block_definition_block },
		{ _field_data, "sound PAS data", FIELD_FLAG_READ_ONLY },

		{ _field_legacy, _field_version_less, _engine_type_haloreach, 2 }, // #TODO: this data is pure speculation, these might not even be tag blocks!!!
		{ _field_legacy, _field_block, "unknown@", &g_null_block_block },
		{ _field_legacy, _field_block, "unknown@", &g_null_block_block },

		{ _field_block, "markers", FIELD_FLAG_READ_ONLY, &structure_bsp_marker_block },
		{ _field_block, "marker light palette", FIELD_FLAG_READ_ONLY, &structure_bsp_marker_light_palette_block },
		{ _field_block, "marker light palette index", FIELD_FLAG_READ_ONLY, &structure_bsp_marker_light_index_block },
		{ _field_block, "runtime decals", FIELD_FLAG_READ_ONLY, &structure_bsp_runtime_decal_block },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 2 },
		{ _field_block, "environment object palette", FIELD_FLAG_READ_ONLY, &structure_bsp_environment_object_palette_block },
		{ _field_block, "environment objects", FIELD_FLAG_READ_ONLY, &structure_bsp_environment_object_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_block, "(DEPRECATED) environment object palette", FIELD_FLAG_READ_ONLY, &structure_bsp_environment_object_palette_block },
		{ _field_block, "(DEPRECATED) environment objects", FIELD_FLAG_READ_ONLY, &structure_bsp_environment_object_block },

		FIELD_PAD("IMISWXUG", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_block, "leaf map leaves", FIELD_FLAG_READ_ONLY, &global_map_leaf_block },
		{ _field_block, "leaf map connections", FIELD_FLAG_READ_ONLY, &global_leaf_connection_block },
		{ _field_block, "errors", FIELD_FLAG_READ_ONLY, &global_error_report_categories_block },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach, 4 },
		{ _field_block, "cluster to instance group mopps", &mopp_code_definition_block },
		{ _field_block, "instance group to instance mopps", &mopp_code_definition_block },
		{ _field_block, "cluster to instance group spheres", &structure_instance_cluster_definition_block },
		{ _field_block, "instance group to instance spheres", &structure_instance_group_definition_block },

		{ _field_block, "instanced geometry instances", FIELD_FLAG_READ_ONLY, &structure_bsp_instanced_geometry_instances_block },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach, 2 },
		{ _field_block, "instanced geometry instance names", FIELD_FLAG_READ_ONLY, &structure_bsp_instanced_geometry_instances_names_block },
		{ _field_tag_reference, "instance imposters", &global_instance_imposter_reference },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_block, "instance imposter infos", &structure_instance_imposter_info_block },
		{ _field_long_integer, "Instance Geometry Tag Instance Count", FIELD_FLAG_UNKNOWN0 },

		FIELD_CUSTOM("decorator info", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_block, "decorator sets", FIELD_FLAG_READ_ONLY, &runtime_decorator_set_block },
		{ _field_struct, "decorator instance buffer", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &global_render_geometry_struct },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach, 5 },
		FIELD_CUSTOM("decals info", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_block, "preplaced decal sets", FIELD_FLAG_READ_ONLY, &bsp_preplaced_decal_set_reference_block },
		{ _field_block, "preplaced decals", FIELD_FLAG_READ_ONLY, &bsp_preplaced_decal_reference_block },
		{ _field_struct, "preplaced decal geometry", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &global_render_geometry_struct },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),

		{ _field_block, "acoustics sound clusters", FIELD_FLAG_UNKNOWN0, &structure_bsp_sound_cluster_block },

		{ _field_legacy, _field_version_less, _engine_type_haloreach, 2 },
		{ _field_legacy, _field_block, "acoustics sound clusters 2!", &structure_bsp_sound_cluster_block },
		{ _field_legacy, _field_block, "acoustics sound clusters 3!", &structure_bsp_sound_cluster_block },

		{ _field_block, "transparent planes", FIELD_FLAG_READ_ONLY, &transparent_planes_block },
		{ _field_block, "debug info", FIELD_FLAG_READ_ONLY, &structure_bsp_debug_info_block },
		{ _field_struct, "structure_physics", FIELD_FLAG_READ_ONLY, &global_structure_physics_struct },

		{ _field_legacy, _field_version_less, _engine_type_haloreach, 1 }, // #TODO: this data is pure speculation!!!
		{ _field_legacy, _field_block, "unknown@", &g_null_block },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 1 }, // #TODO: this data is pure speculation!!!
		{ _field_legacy, _field_block, "unknown@", &g_null_block },

		{ _field_struct, "render geometry", FIELD_FLAG_READ_ONLY, &global_render_geometry_struct },
		{ _field_block, "widget references", &widget_reference_block },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_block, "cheap light references", &cheap_light_reference_block },

		{ _field_struct, "resource interface", &structure_bsp_resource_interface },

		{ _field_legacy, _field_version_equal, _engine_type_haloreach },
		{ _field_legacy, _field_long_integer, "unknown@" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 9 },
		FIELD_CUSTOM("Any Platform Temporary Storage", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_block, "Any Platform Temp Havok Data", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &structureIOHavokDataBlock_block },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		{ _field_block, "external references", &structure_external_instanced_geometry_references_block },
		{ _field_tag_reference, "dependencies", &Tag::Reference<struct s_dependency_list>::s_defaultDefinition },
		{ _field_long_integer, "base material count", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_block, "obb volume list", &structure_bsp_obb_volume_block },
		{ _field_block, "scripted dependencies", &hs_references_block },
		{ _field_block, "pupAnimations", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &AnimGraphDependencyBlock_block },

		{ _field_terminator }
	};

	TAG_GROUP(
		scenario_structure_bsp_group,
		SCENARIO_STRUCTURE_BSP_TAG,
		nullptr,
		INVALID_TAG,
		scenario_structure_bsp_block );

	TAG_BLOCK_FROM_STRUCT(
		prefab_block,
		"prefab_block",
		1,
		prefab_struct_definition);

	#define STRUCTURE_EDGE_TO_SEAM_EDGE_MAPPING_BLOCK_ID { 0x5E7D4A2C, 0x49134181, 0xB2652E00, 0xABA99982 }
	TAG_BLOCK(
		structure_edge_to_seam_edge_mapping_block,
		"structure_edge_to_seam_edge_mapping_block",
		((true) ? 2621440 : UNSIGNED_SHORT_MAX),
		"s_structure_edge_to_seam_edge_mapping",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTURE_EDGE_TO_SEAM_EDGE_MAPPING_BLOCK_ID)
	{
		{ _field_short_integer, "seam_index", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "seam_edge_index", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define STRUCTURE_COLLISION_MATERIALS_BLOCK_ID { 0x9B46AC25, 0x4F274C73, 0xA712E380, 0x4CCC324B }
	TAG_BLOCK(
		structure_collision_materials_block,
		"structure_collision_materials_block",
		MAXIMUM_COLLISION_MATERIALS_PER_STRUCTURE,
		"structure_collision_material",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTURE_COLLISION_MATERIALS_BLOCK_ID)
	{
		{ _field_tag_reference, "render method", MAKE_OLD_NAMES("old shader"), FIELD_FLAG_READ_ONLY | FIELD_FLAG_INDEX, &structure_collision_materials_block_render_method_reference },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 1 },
		{ _field_string_id, "override material name" },

		{ _field_short_integer, "runtime global material index", FIELD_FLAG_UNKNOWN0 },
		{ _field_short_block_index, "conveyor surface index", FIELD_FLAG_READ_ONLY, &structure_bsp_conveyor_surface_block },
		{ _field_short_block_index, "seam mapping index", FIELD_FLAG_READ_ONLY, &structure_seam_mapping_block },
		{ _field_word_flags, "flags", FIELD_FLAG_READ_ONLY, &structure_collision_materialg_flags },
		{ _field_terminator }
	};

	#define STRUCTURE_BSP_CONVEYOR_SURFACE_BLOCK_ID { 0xCD0C6613, 0x20BF49D0, 0x9379FD49, 0xA1729B48 }
	TAG_BLOCK(
		structure_bsp_conveyor_surface_block,
		"structure_bsp_conveyor_surface_block",
		MAXIMUM_COLLISION_MATERIALS_PER_STRUCTURE,
		"structure_conveyor_surface",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTURE_BSP_CONVEYOR_SURFACE_BLOCK_ID)
	{
		{ _field_real_vector_3d, "u" },
		{ _field_real_vector_3d, "v" },
		{ _field_terminator }
	};

	#define STRUCTURE_BSP_LEAF_BLOCK_ID { 0xB611DF65, 0xC92C4779, 0x8227AAFA, 0x52126166 }
	TAG_BLOCK(
		structure_bsp_leaf_block,
		"structure_bsp_leaf_block",
		((true) ? 16*((1<<(k_bsp3d_node_child_index_bits-1))) : ((1<<(k_bsp3d_node_child_index_bits-1)))),
		"structure_bsp_leaf_block",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTURE_BSP_LEAF_BLOCK_ID)
	{
		{ _field_byte_integer, "cluster", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define STRUCTURE_SUPER_NODE_AABBS_BLOCK_ID { 0xABAAAA8A, 0x32044161, 0x3467CA2F, 0xAD4716BF }
	TAG_BLOCK(
		structure_super_node_aabbs_block,
		"structure_super_node_aabbs_block",
		(k_bsp3d_maximum_super_node_count)*k_super_node_child_indices_count,
		"real_rectangle3d",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTURE_SUPER_NODE_AABBS_BLOCK_ID)
	{
		{ _field_real, "x0" },
		{ _field_real, "x1" },
		{ _field_real, "y0" },
		{ _field_real, "y1" },
		{ _field_real, "z0" },
		{ _field_real, "z1" },
		{ _field_terminator }
	};

	#define SUPER_NODE_MAPPINGS_BLOCK_ID { 0x61AA468A, 0x0A044161, 0xB167CA2F, 0xCB2716BF }
	TAG_BLOCK(
		super_node_mappings_block,
		"super_node_mappings_block",
		(k_bsp3d_maximum_super_node_count),
		"s_structure_super_node_mapping",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SUPER_NODE_MAPPINGS_BLOCK_ID)
	{
		{ _field_short_integer, "parent_super_node_index", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_char_integer, "parent_internal_node_index", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_byte_flags, "flags", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &structure_super_node_mapping_flags },
		{ _field_long_integer, "has_traversal_geometry_mask", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_short_block_index, "first_traversal_geometry_index", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &structure_super_node_traversal_geometry_indices_block },
		{ _field_short_block_index, "first_aabb_index", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &structure_super_node_aabbs_block },
		{ _field_long_integer, "aabb_mask", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_short_block_index, "non_terminal_traversal_geometry_index", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &structure_super_node_traversal_geometry_indices_block },
		FIELD_PAD("pad", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	#define STRUCTURE_SUPER_NODE_TRAVERSAL_GEOMETRY_INDICES_BLOCK_ID { 0x61AAAA8A, 0x80044161, 0x3167CA2F, 0xCD4716BF }
	TAG_BLOCK(
		structure_super_node_traversal_geometry_indices_block,
		"structure_super_node_traversal_geometry_indices_block",
		((MAXIMUM_CLUSTER_PORTALS_PER_STRUCTURE)>(k_structure_seam_maximum_seam_count)?(MAXIMUM_CLUSTER_PORTALS_PER_STRUCTURE):(k_structure_seam_maximum_seam_count)),
		"short",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTURE_SUPER_NODE_TRAVERSAL_GEOMETRY_INDICES_BLOCK_ID)
	{
		{ _field_short_integer, "index", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define SUPER_NODE_RECURSABLE_MASKS_BLOCK_ID { 0x61AB468A, 0xCA044161, 0xB167CAAF, 0x1B2716BF }
	TAG_BLOCK(
		super_node_recursable_masks_block,
		"super_node_recursable_masks_block",
		(k_bsp3d_maximum_super_node_count),
		"word",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SUPER_NODE_RECURSABLE_MASKS_BLOCK_ID)
	{
		{ _field_short_integer, "mask", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define STRUCTURE_SUPER_NODE_TRAVERSAL_GEOMETRY_BLOCK_ID { 0x61AAAB8A, 0x10044161, 0xC167CA2F, 0xCB4716BF }
	TAG_BLOCK(
		structure_super_node_traversal_geometry_block,
		"structure_super_node_traversal_geometry_block",
		k_short_max,
		"s_structure_super_node_traversal_geometry",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTURE_SUPER_NODE_TRAVERSAL_GEOMETRY_BLOCK_ID)
	{
		{ _field_block, "portal_indices", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &structure_super_node_traversal_geometry_indices_block },
		{ _field_block, "seam_indices", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &structure_super_node_traversal_geometry_indices_block },
		{ _field_terminator }
	};

	#define STRUCTURE_SURFACE_BLOCK_ID { 0xE0159FC4, 0xC9AB45E9, 0xB1B58400, 0x24345098 }
	TAG_BLOCK(
		structure_surface_block,
		"structure_surface_block",
		((true) ? SHORT_MAX<<3 : SHORT_MAX),
		"structure_surface_block",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTURE_SURFACE_BLOCK_ID)
	{
		{ _field_long_integer, "first_structure_surface_to_triangle_mapping_index", FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "structure_surface_to_triangle_mapping_count", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define STRUCTURE_SURFACE_TO_TRIANGLE_MAPPING_BLOCK_STRUCT_ID { 0x8E1D81A7, 0xAC1146C3, 0x126EDAC7, 0xB65E2B07 }
	TAG_BLOCK(
		structure_surface_to_triangle_mapping_block,
		"structure_surface_to_triangle_mapping_block",
		(8*((true) ? SHORT_MAX<<3 : SHORT_MAX)),
		"structure_surface_to_triangle_mapping",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTURE_SURFACE_TO_TRIANGLE_MAPPING_BLOCK_STRUCT_ID)
	{
		{ _field_dword_integer, "manual byteswarp1", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define STRUCTURE_BSP_CLUSTER_PORTAL_BLOCK_ID { 0x515C51A4, 0x87494090, 0x95104547, 0x3C6C550F }
	TAG_BLOCK(
		structure_bsp_cluster_portal_block,
		"structure_bsp_cluster_portal_block",
		MAXIMUM_CLUSTER_PORTALS_PER_STRUCTURE,
		"cluster_portal",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTURE_BSP_CLUSTER_PORTAL_BLOCK_ID)
	{
		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach, 1 },
		{ _field_struct, "oriented bounds", &structure_bsp_cluster_portal_oriented_bounds_block },

		{ _field_short_integer, "back cluster", FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "front cluster", FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "plane index", FIELD_FLAG_READ_ONLY },
		{ _field_real_point_3d, "centroid", FIELD_FLAG_READ_ONLY },
		{ _field_real, "bounding radius", FIELD_FLAG_READ_ONLY },
		{ _field_long_flags, "flags", FIELD_FLAG_READ_ONLY, &structure_bsp_cluster_portal_flags_definition },
		{ _field_block, "vertices", FIELD_FLAG_READ_ONLY, &structure_bsp_cluster_portal_vertex_block },
		{ _field_terminator }
	};

	#define STRUCTURE_BSP_CLUSTER_PORTAL_VERTEX_BLOCK_ID { 0xCE56A99F, 0x1DD34CA8, 0xAA366F5F, 0xF8F748EC }
	TAG_BLOCK(
		structure_bsp_cluster_portal_vertex_block,
		"structure_bsp_cluster_portal_vertex_block",
		MAXIMUM_VERTICES_PER_CLUSTER_PORTAL,
		"real_point3d",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTURE_BSP_CLUSTER_PORTAL_VERTEX_BLOCK_ID)
	{
		{ _field_real_point_3d, "point", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define STRUCTURE_BSP_DETAIL_OBJECT_DATA_BLOCK_ID { 0x20D0C285, 0xB61244F7, 0x996ED157, 0x181CA371 }
	TAG_BLOCK(
		structure_bsp_detail_object_data_block,
		"structure_bsp_detail_object_data_block",
		1,
		"structure_detail_object_data",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTURE_BSP_DETAIL_OBJECT_DATA_BLOCK_ID)
	{
		{ _field_block, "cells", &global_detail_object_cells_block },
		{ _field_block, "instances", &global_detail_object_block },
		{ _field_block, "counts", &global_detail_object_counts_block },
		{ _field_block, "z reference vectors", &global_z_reference_vector_block },
		FIELD_PAD("KXILLD", nullptr, FIELD_FLAG_NONE, 1),
		FIELD_PAD("EDFPN", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_terminator }
	};

	#define STRUCTURE_BSP_CLUSTER_BLOCK_STRUCT_ID { 0x443EB808, 0xF3A4493E, 0xAAB7DADD, 0x79F9A8DE }
	TAG_BLOCK(
		structure_bsp_cluster_block,
		"structure_bsp_cluster_block",
		MAXIMUM_CLUSTERS_PER_STRUCTURE,
		"structure_cluster",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTURE_BSP_CLUSTER_BLOCK_STRUCT_ID)
	{
		FIELD_EXPLANATION("CLUSTER INFO", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real_bounds, "bounds x", FIELD_FLAG_READ_ONLY },
		{ _field_real_bounds, "bounds y", FIELD_FLAG_READ_ONLY },
		{ _field_real_bounds, "bounds z", FIELD_FLAG_READ_ONLY },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_char_integer, "unknown" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		FIELD_PAD("DING", nullptr, FIELD_FLAG_NONE, 1),

		{ _field_char_integer, "atmosphere index", FIELD_FLAG_READ_ONLY },
		{ _field_char_integer, "camera fx index", FIELD_FLAG_READ_ONLY },
		{ _field_char_integer, "weather index", FIELD_FLAG_READ_ONLY },
		{ _field_short_block_index, "acoustics", FIELD_FLAG_READ_ONLY, &scenario_acoustics_palette_block_definition_block },
		{ _field_short_integer, "acoustics sound cluster index" },

		{ _field_legacy, _field_version_less, _engine_type_haloreach, 5 },
		{ _field_legacy, _field_short_integer, "unknown" },
		{ _field_legacy, _field_short_integer, "unknown" },
		{ _field_legacy, _field_short_integer, "unknown" },
		{ _field_legacy, _field_short_integer, "unknown" },
		{ _field_legacy, _field_short_integer, "unknown" },

		{ _field_short_integer, "runtime first decal index", FIELD_FLAG_UNKNOWN0 },
		{ _field_short_integer, "runtime decal cound", FIELD_FLAG_UNKNOWN0 },
		{ _field_word_flags, "flags", &structure_cluster_flags },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach, 1 },
		FIELD_PAD("ERERRFQ", nullptr, FIELD_FLAG_NONE, 2),

		{ _field_block, "predicted resources", FIELD_FLAG_READ_ONLY, &g_null_block },
		{ _field_block, "portals", FIELD_FLAG_READ_ONLY, &structure_bsp_cluster_portal_index_block },

		{ _field_legacy, _field_version_less, _engine_type_haloreach, 33 },
		{ _field_legacy, _field_long_integer, "unknown" },
		{ _field_legacy, _field_long_integer, "unknown" },
		{ _field_legacy, _field_short_integer, "unknown size" },
		{ _field_legacy, _field_short_integer, "unknown count" },
		{ _field_legacy, _field_long_integer, "unknown" },
		{ _field_legacy, _field_long_integer, "unknown offset" },
		{ _field_legacy, _field_long_integer, "unknown" },
		{ _field_legacy, _field_long_integer, "unknown" },
		{ _field_legacy, _field_long_integer, "unknown" },
		{ _field_legacy, _field_long_integer, "unknown" },
		{ _field_legacy, _field_long_integer, "unknown" },
		{ _field_legacy, _field_long_integer, "unknown" },
		{ _field_legacy, _field_long_integer, "unknown" },
		{ _field_legacy, _field_tag_reference, "bsp", &structure_bsp_reference_non_resolving },
		{ _field_legacy, _field_long_integer, "cluster index" },
		{ _field_legacy, _field_long_integer, "unknown" },
		{ _field_legacy, _field_long_integer, "unknown" },
		{ _field_legacy, _field_long_integer, "unknown" },
		{ _field_legacy, _field_short_integer, "unknown size" },
		{ _field_legacy, _field_short_integer, "unknown count" },
		{ _field_legacy, _field_long_integer, "unknown" },
		{ _field_legacy, _field_long_integer, "unknown offset" },
		{ _field_legacy, _field_long_integer, "unknown" },
		{ _field_legacy, _field_long_integer, "unknown" },
		{ _field_legacy, _field_long_integer, "unknown" },
		{ _field_legacy, _field_long_integer, "unknown" },
		{ _field_legacy, _field_long_integer, "unknown" },
		{ _field_legacy, _field_long_integer, "unknown" },
		{ _field_legacy, _field_long_integer, "unknown" },
		{ _field_legacy, _field_long_integer, "unknown" },
		{ _field_legacy, _field_long_integer, "unknown" },
		{ _field_legacy, _field_block, "mopp_codes*", &mopp_code_definition_block },
		{ _field_legacy, _field_long_integer, "unknown" },

		{ _field_short_integer, "mesh index", FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "instance imposter cluster mopp index" },
		{ _field_block, "seam indices", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &seam_indices_block_definition_block },
		{ _field_block, "decorator groups", FIELD_FLAG_READ_ONLY, &decorator_runtime_cluster_block },
		{ _field_block, "cheap light marker refs", FIELD_FLAG_READ_ONLY, &cheap_light_marker_ref_block },
		{ _field_block, "pvs bound object identifiers", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &pvs_bound_object_identifiers_block },
		{ _field_block, "pvs bound object references", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &pvs_bound_object_references_block },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_block, "cluster cubemaps", &structure_cluster_cubemap_block },

		{ _field_terminator }
	};

	#define STRUCTURE_BSP_CLUSTER_PORTAL_INDEX_BLOCK_ID { 0x8C1C3A41, 0x400B4519, 0x95B2C6B8, 0x710AC715 }
	TAG_BLOCK(
		structure_bsp_cluster_portal_index_block,
		"structure_bsp_cluster_portal_index_block",
		MAXIMUM_CLUSTER_PORTALS_PER_CLUSTER,
		"short",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTURE_BSP_CLUSTER_PORTAL_INDEX_BLOCK_ID)
	{
		{ _field_short_integer, "portal index", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define SEAM_INDICES_BLOCK_DEFINITION_ID { 0x4DD47B87, 0x293440E9, 0x95732E53, 0xECAD8B62 }
	TAG_BLOCK(
		seam_indices_block_definition_block,
		"seam_indices_block_definition",
		k_structure_seam_maximum_seam_count,
		"char",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SEAM_INDICES_BLOCK_DEFINITION_ID)
	{
		{ _field_char_integer, "seam index", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define CHEAP_LIGHT_MARKER_REF_BLOCK_ID { 0x4AFFFB87, 0xCAAA40E9, 0x9BBBFE53, 0x0CCC8B62 }
	TAG_BLOCK(
		cheap_light_marker_ref_block,
		"cheap_light_marker_ref_block",
		MAXIMUM_MARKERS_PER_STRUCTURE,
		"s_cheap_light_marker_reference_reference",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CHEAP_LIGHT_MARKER_REF_BLOCK_ID)
	{
		{ _field_short_block_index, "cheap light reference reference", &cheap_light_reference_block },
		FIELD_PAD("WHATIZZIT", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	#define CHEAP_LIGHT_REFERENCE_BLOCK_ID { 0xFE62CAFA, 0x49536A8C, 0xB9E5A93F, 0xA9AA1AAB }
	TAG_BLOCK(
		cheap_light_reference_block,
		"cheap_light_reference_block",
		MAXIMUM_MARKERS_PER_STRUCTURE,
		"s_cheap_light_marker_reference",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CHEAP_LIGHT_REFERENCE_BLOCK_ID)
	{
		{ _field_short_integer, "marker index", FIELD_FLAG_READ_ONLY },
		FIELD_PAD("ldajk", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_tag_reference, "cheap light", FIELD_FLAG_READ_ONLY, &cheap_light_reference },
		{ _field_terminator }
	};

	#define PVS_BOUND_OBJECT_IDENTIFIERS_BLOCK_ID { 0x4AB47B87, 0xCD3440E9, 0x957EFE53, 0x01AD8B62 }
	TAG_BLOCK(
		pvs_bound_object_identifiers_block,
		"pvs_bound_object_identifiers_block",
		k_maximum_scenario_object_datum_count,
		"c_object_identifier",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PVS_BOUND_OBJECT_IDENTIFIERS_BLOCK_ID)
	{
		{ _field_struct, "object ID", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &scenario_object_id_struct },
		{ _field_terminator }
	};

	#define PVS_BOUND_OBJECT_REFERENCES_BLOCK_ID { 0xAAB47B87, 0xCD3AA0E9, 0x9BBEFE53, 0x01AD8BCC }
	TAG_BLOCK(
		pvs_bound_object_references_block,
		"pvs_bound_object_references_block",
		k_maximum_scenario_object_datum_count,
		"s_scenario_object_reference",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PVS_BOUND_OBJECT_REFERENCES_BLOCK_ID)
	{
		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_real_point_3d, "unknown#position?" },

		{ _field_struct, "scenario object reference", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &scenario_object_reference_struct },
		{ _field_terminator }
	};

	#define STRUCTURE_MATERIAL_LIGHTING_INFO_BLOCK_ID { 0x9DD3CC89, 0xB8374B30, 0xBD6F5C2D, 0xDA247EA0 }
	TAG_BLOCK(
		structure_material_lighting_info_block,
		"structure_material_lighting_info_block",
		SHORT_MAX,
		"s_structure_material_lighting_info",
		SET_POSTPROCESS_RECURSIVELY | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTURE_MATERIAL_LIGHTING_INFO_BLOCK_ID)
	{
		{ _field_real, "emissive power" },
		{ _field_real_rgb_color, "emissive color" },
		{ _field_real, "emissive quality" },
		{ _field_real, "emissive focus" },
		{ _field_long_flags, "flags", &structure_material_lighting_info_flags },
		{ _field_real, "attenuation falloff" },
		{ _field_real, "attenuation cutoff" },
		{ _field_real, "bounce ratio" },
		{ _field_terminator }
	};

	#define STRUCTURE_BSP_SKY_OWNER_CLUSTER_BLOCK_ID { 0x5CDBBAA5, 0x15CB4A6C, 0xA0F28010, 0xC976FB69 }
	TAG_BLOCK(
		structure_bsp_sky_owner_cluster_block,
		"structure_bsp_sky_owner_cluster_block",
		MAXIMUM_SKIES_PER_SCENARIO,
		"short",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTURE_BSP_SKY_OWNER_CLUSTER_BLOCK_ID)
	{
		{ _field_short_integer, "cluster owner", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define STRUCTURE_COOKIE_CUTTER_DEFINITION_ID { 0x24E4D315, 0xF5FA4BA3, 0x96C80371, 0x7A6F48AC }
	TAG_BLOCK(
		structure_cookie_cutter_definition_block,
		"structure_cookie_cutter_definition",
		k_kilo,
		"s_structure_cookie_cutter",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTURE_COOKIE_CUTTER_DEFINITION_ID)
	{
		FIELD_CUSTOM("Cookie Cutter", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_struct, "collision model", &global_collision_bsp_struct },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		{ _field_terminator }
	};

	#define STRUCTURE_BSP_MARKER_BLOCK_ID { 0xE4B2C51D, 0xF2C84524, 0x8F67A353, 0x3E9F7017 }
	TAG_BLOCK(
		structure_bsp_marker_block,
		"structure_bsp_marker_block",
		MAXIMUM_MARKERS_PER_STRUCTURE,
		"structure_marker",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTURE_BSP_MARKER_BLOCK_ID)
	{
		{ _field_char_enum, "marker type", FIELD_FLAG_READ_ONLY, &structure_marker_type_enum },
		FIELD_PAD("pad", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_string, "marker parameter", FIELD_FLAG_READ_ONLY },
		{ _field_real_quaternion, "rotation" },
		{ _field_real_point_3d, "position", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define STRUCTURE_BSP_MARKER_LIGHT_PALETTE_ID { 0xA008D181, 0x9612449F, 0x96D5E611, 0xE4355D97 }
	TAG_BLOCK(
		structure_bsp_marker_light_palette_block,
		"structure_bsp_marker_light_palette",
		MAXIMUM_MARKERS_PER_STRUCTURE,
		"s_tag_reference",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTURE_BSP_MARKER_LIGHT_PALETTE_ID)
	{
		{ _field_tag_reference, "light tag", &light_reference },
		{ _field_terminator }
	};

	#define STRUCTURE_BSP_MARKER_LIGHT_INDEX_ID { 0xCBAC4327, 0xB7F94CF8, 0x9E42DAEC, 0xFA79FFA7 }
	TAG_BLOCK(
		structure_bsp_marker_light_index_block,
		"structure_bsp_marker_light_index",
		MAXIMUM_MARKERS_PER_STRUCTURE,
		"short",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTURE_BSP_MARKER_LIGHT_INDEX_ID)
	{
		{ _field_short_integer, "palette index" },
		{ _field_terminator }
	};

	#define STRUCTURE_BSP_RUNTIME_DECAL_BLOCK_ID { 0x617C468A, 0x8AC44161, 0xB167C76F, 0x152716BF }
	TAG_BLOCK(
		structure_bsp_runtime_decal_block,
		"structure_bsp_runtime_decal_block",
		MAXIMUM_DECALS_PER_STRUCTURE,
		"scenario_decal",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTURE_BSP_RUNTIME_DECAL_BLOCK_ID)
	{
		{ _field_short_integer, "decal palette index", FIELD_FLAG_UNKNOWN0 },

		/*
			assumed from manualBspFlagsReferences's

			If flags got bigger than 16bits, padding would be added and there
			is a 32bits flags inside of manualBspFlagsReferences
		*/

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 1 },
		{ _field_legacy, _field_short_integer, "flags" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		FIELD_PAD("post-decal-palette-index-pad", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_struct, "manual bsp flags", &manualBspFlagsReferences },

		{ _field_real_quaternion, "rotation", FIELD_FLAG_READ_ONLY },
		{ _field_real_point_3d, "position", FIELD_FLAG_READ_ONLY },

		{ _field_legacy, _field_version_less, _engine_type_haloreach, 1 },
		{ _field_legacy, _field_real, "scale*" },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach, 2 },
		{ _field_real, "scale_x", MAKE_OLD_NAMES("scale"), FIELD_FLAG_READ_ONLY },
		{ _field_real, "scale_y", FIELD_FLAG_READ_ONLY },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 1 },
		{ _field_real, "cull angle" },

		{ _field_terminator }
	};

	#define STRUCTURE_BSP_ENVIRONMENT_OBJECT_PALETTE_BLOCK_ID { 0x37D2FC4A, 0x2E6243F8, 0xB235BEDE, 0x7776BE11 }
	TAG_BLOCK(
		structure_bsp_environment_object_palette_block,
		"structure_bsp_environment_object_palette_block",
		MAXIMUM_ENVIRONMENT_OBJECT_PALETTE_ENTRIES_PER_STRUCTURE,
		"structure_environment_object_palette_entry",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTURE_BSP_ENVIRONMENT_OBJECT_PALETTE_BLOCK_ID)
	{
		{ _field_tag_reference, "definition", FIELD_FLAG_INDEX, &object_reference$8 },
		{ _field_tag_reference, "model", &render_model_reference$9 },
		{ _field_long_integer, "GVEYN", FIELD_FLAG_UNKNOWN0 },
		{ _field_terminator }
	};

	#define STRUCTURE_BSP_ENVIRONMENT_OBJECT_BLOCK_ID { 0x1CDF634D, 0xFD90476F, 0x9133F1DA, 0xCC1B247F }
	TAG_BLOCK(
		structure_bsp_environment_object_block,
		"structure_bsp_environment_object_block",
		MAXIMUM_ENVIRONMENT_OBJECTS_PER_STRUCTURE,
		"structure_environment_object",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTURE_BSP_ENVIRONMENT_OBJECT_BLOCK_ID)
	{
		{ _field_string, "name", FIELD_FLAG_INDEX },
		{ _field_real_quaternion, "rotation" },
		{ _field_real_point_3d, "translation" },
		{ _field_real, "scale" },
		{ _field_short_block_index, "palette_index", &structure_bsp_environment_object_palette_block },
		{ _field_byte_flags, "flags", &environmentObjectFlagsDefinition },
		FIELD_PAD("QHUGQ", nullptr, FIELD_FLAG_NONE, 1),
		{ _field_long_integer, "unique id", FIELD_FLAG_READ_ONLY },
		{ _field_tag, "exported object type" },

		{ _field_legacy, _field_version_less, _engine_type_haloreach },
		{ _field_legacy, _field_pad, "unknown", 32 }, // #TODO: Are there string id's in here???

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach, 2 },
		{ _field_string_id, "scenario object name" },
		{ _field_string_id, "variant name" },

		{ _field_terminator }
	};

	#define STRUCTURE_INSTANCE_CLUSTER_DEFINITION_ID { 0xB125B7FC, 0xF9B846A3, 0x91E9DFCF, 0x3E1978AB }
	TAG_BLOCK(
		structure_instance_cluster_definition_block,
		"structure_instance_cluster_definition",
		k_maximum_cluster_to_instance_group_block_size,
		"s_structure_instance_cluster",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTURE_INSTANCE_CLUSTER_DEFINITION_ID)
	{
		{ _field_long_flags, "flags", &structure_instance_cluster_flags },
		{ _field_block, "instance group indices", &index_list_block },
		{ _field_terminator }
	};

	#define INDEX_LIST_BLOCK_ID { 0x46A289B9, 0x00CD4938, 0xBAAECC17, 0x5E24C7BA }
	TAG_BLOCK(
		index_list_block,
		"index_list_block",
		4 * k_kilo,
		"word",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		INDEX_LIST_BLOCK_ID)
	{
		{ _field_word_integer, "index" },
		{ _field_terminator }
	};

	#define STRUCTURE_INSTANCE_GROUP_DEFINITION_ID { 0x690AAB9C, 0x68A24457, 0xB5BCABD7, 0x3411A2B6 }
	TAG_BLOCK(
		structure_instance_group_definition_block,
		"structure_instance_group_definition",
		4 * k_kilo,
		"s_structure_instance_group",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTURE_INSTANCE_GROUP_DEFINITION_ID)
	{
		{ _field_real_point_3d, "center" },
		{ _field_real, "radius" },
		{ _field_short_integer, "cluster count" },
		{ _field_word_flags, "flags", &structure_instance_group_flags },
		{ _field_real, "maximum imposter distance", FIELD_FLAG_READ_ONLY },
		{ _field_real, "minimum centrifugal distance from group center", FIELD_FLAG_READ_ONLY },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_real, "minimum imposter distance squared", FIELD_FLAG_READ_ONLY },

		{ _field_block, "instance indices", &index_list_block },
		{ _field_terminator }
	};

	#define STRUCTURE_INSTANCE_IMPOSTER_INFO_BLOCK_ID { 0x4B11C756, 0x848E464C, 0x8723247D, 0x98DBB91E }
	TAG_BLOCK(
		structure_instance_imposter_info_block,
		"structure_instance_imposter_info_block",
		k_maximum_instance_geometry_instances_per_structure_bsp,
		"s_structure_instance_imposter_info",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTURE_INSTANCE_IMPOSTER_INFO_BLOCK_ID)
	{
		{ _field_string_id, "name" },
		{ _field_char_integer, "imposter policy" },
		FIELD_PAD("parasdd", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_real, "transition distance" },
		{ _field_terminator }
	};

	#define RUNTIME_DECORATOR_SET_BLOCK_ID { 0xEBC8164A, 0x583140C6, 0xBB8277A0, 0x58357ADA }
	TAG_BLOCK(
		runtime_decorator_set_block,
		"runtime_decorator_set_block",
		MAXIMUM_DECORATOR_SETS_PER_SCENARIO,
		"s_tag_reference",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		RUNTIME_DECORATOR_SET_BLOCK_ID)
	{
		{ _field_tag_reference, "decorator set reference", FIELD_FLAG_READ_ONLY, &global_decorator_set_reference },
		{ _field_terminator }
	};

	#define BSP_PREPLACED_DECAL_SET_REFERENCE_BLOCK_ID { 0xA3345A30, 0xF7654F6F, 0xAE72426D, 0x15740B0B }
	TAG_BLOCK(
		bsp_preplaced_decal_set_reference_block,
		"bsp_preplaced_decal_set_reference_block",
		MAXIMUM_DECALS_PER_STRUCTURE,
		"s_bsp_preplaced_decal_set_reference",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		BSP_PREPLACED_DECAL_SET_REFERENCE_BLOCK_ID)
	{
		{ _field_long_integer, "decal definition index", FIELD_FLAG_UNKNOWN0 },
		{ _field_char_integer, "location bsp 0", FIELD_FLAG_UNKNOWN0 },
		{ _field_byte_integer, "location cluster 0", FIELD_FLAG_UNKNOWN0 },
		{ _field_char_integer, "location bsp 1", FIELD_FLAG_UNKNOWN0 },
		{ _field_byte_integer, "location cluster 1", FIELD_FLAG_UNKNOWN0 },
		{ _field_char_integer, "location bsp 2", FIELD_FLAG_UNKNOWN0 },
		{ _field_byte_integer, "location cluster 2", FIELD_FLAG_UNKNOWN0 },
		{ _field_char_integer, "location bsp 3", FIELD_FLAG_UNKNOWN0 },
		{ _field_byte_integer, "location cluster 3", FIELD_FLAG_UNKNOWN0 },
		{ _field_real_point_3d, "center", FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "first decal ref index", FIELD_FLAG_UNKNOWN0 },
		{ _field_short_integer, "decal ref count", FIELD_FLAG_UNKNOWN0 },
		{ _field_terminator }
	};

	#define BSP_PREPLACED_DECAL_REFERENCE_BLOCK_ID { 0xE6FD463F, 0xE03645F2, 0xAB632862, 0x08D637AB }
	TAG_BLOCK(
		bsp_preplaced_decal_reference_block,
		"bsp_preplaced_decal_reference_block",
		MAXIMUM_DECALS_PER_STRUCTURE,
		"s_bsp_preplaced_decal_reference",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		BSP_PREPLACED_DECAL_REFERENCE_BLOCK_ID)
	{
		{ _field_short_integer, "index start" },
		{ _field_short_integer, "index count" },
		{ _field_short_integer, "vertex start" },
		{ _field_short_integer, "vertex count" },
		{ _field_short_integer, "definition block index" },
		FIELD_PAD("paddddg", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real_point_2d, "spirit corner" },
		{ _field_real_vector_2d, "spirit size" },
		{ _field_terminator }
	};

	#define TRANSPARENT_PLANES_BLOCK_ID { 0xB66CE451, 0x57AE4DC8, 0xB204270D, 0x07A9412F }
	TAG_BLOCK(
		transparent_planes_block,
		"transparent_planes_block",
		32*k_kilo,
		"s_transparent_plane",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		TRANSPARENT_PLANES_BLOCK_ID)
	{
		{ _field_short_integer, "section index" },
		{ _field_short_integer, "part index" },
		{ _field_real_plane_3d, "plane" },
		{ _field_terminator }
	};

	#define STRUCTURE_BSP_DEBUG_INFO_BLOCK_ID { 0x8FF53A43, 0xE3814420, 0x81140052, 0xAB9DFEA6 }
	TAG_BLOCK(
		structure_bsp_debug_info_block,
		"structure_bsp_debug_info_block",
		1,
		"s_structure_debug_info",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTURE_BSP_DEBUG_INFO_BLOCK_ID)
	{
		FIELD_PAD("BRQYEF", nullptr, FIELD_FLAG_NONE, 64),
		{ _field_block, "clusters", FIELD_FLAG_READ_ONLY, &structure_bsp_cluster_debug_info_block },
		{ _field_block, "fog planes", FIELD_FLAG_READ_ONLY, &structure_bsp_fog_plane_debug_info_block },
		{ _field_block, "fog zones", FIELD_FLAG_READ_ONLY, &structure_bsp_fog_zone_debug_info_block },
		{ _field_terminator }
	};

	#define STRUCTURE_BSP_CLUSTER_DEBUG_INFO_BLOCK_ID { 0xB5A0AC69, 0x26934359, 0x9CA55C27, 0x431EC06E }
	TAG_BLOCK(
		structure_bsp_cluster_debug_info_block,
		"structure_bsp_cluster_debug_info_block",
		MAXIMUM_CLUSTERS_PER_STRUCTURE,
		"s_structure_cluster_debug_info",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTURE_BSP_CLUSTER_DEBUG_INFO_BLOCK_ID)
	{
		{ _field_word_flags, "errors", FIELD_FLAG_READ_ONLY, &structure_bsp_debug_info_cluster_error_flags },
		{ _field_word_flags, "warnings", FIELD_FLAG_READ_ONLY, &structure_bsp_debug_info_cluster_warning_flags },
		FIELD_PAD("KHWRB", nullptr, FIELD_FLAG_NONE, 28),
		{ _field_block, "lines", FIELD_FLAG_READ_ONLY, &structure_bsp_debug_info_render_line_block },
		{ _field_block, "fog plane indices", FIELD_FLAG_READ_ONLY, &structure_bsp_debug_info_indices_block },
		{ _field_block, "visible fog plane indices", FIELD_FLAG_READ_ONLY, &structure_bsp_debug_info_indices_block },
		{ _field_block, "vis-fog omission cluster indices", FIELD_FLAG_READ_ONLY, &structure_bsp_debug_info_indices_block },
		{ _field_block, "containing fog zone indices", FIELD_FLAG_READ_ONLY, &structure_bsp_debug_info_indices_block },
		{ _field_terminator }
	};

	#define STRUCTURE_BSP_DEBUG_INFO_RENDER_LINE_BLOCK_ID { 0x288FF283, 0x1AB747CD, 0x84A91A1A, 0x49EB05F1 }
	TAG_BLOCK(
		structure_bsp_debug_info_render_line_block,
		"structure_bsp_debug_info_render_line_block",
		SHORT_MAX,
		"s_structure_debug_info_render_line",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTURE_BSP_DEBUG_INFO_RENDER_LINE_BLOCK_ID)
	{
		{ _field_enum, "type", FIELD_FLAG_READ_ONLY, &structure_bsp_debug_info_render_line_type_enum },
		{ _field_short_integer, "code", FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "pad thai", FIELD_FLAG_READ_ONLY },
		FIELD_PAD("BNQS", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real_point_3d, "point 0", FIELD_FLAG_READ_ONLY },
		{ _field_real_point_3d, "point 1", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define STRUCTURE_BSP_DEBUG_INFO_INDICES_BLOCK_ID { 0x5E7D4A5C, 0x49B34181, 0xB5652E00, 0x9BA99982 }
	TAG_BLOCK(
		structure_bsp_debug_info_indices_block,
		"structure_bsp_debug_info_indices_block",
		SHORT_MAX,
		"long",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTURE_BSP_DEBUG_INFO_INDICES_BLOCK_ID)
	{
		{ _field_long_integer, "index", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define STRUCTURE_BSP_FOG_PLANE_DEBUG_INFO_BLOCK_ID { 0xF78A15DF, 0xDCC84AD0, 0xA18E7B16, 0x621BC70B }
	TAG_BLOCK(
		structure_bsp_fog_plane_debug_info_block,
		"structure_bsp_fog_plane_debug_info_block",
		MAXIMUM_FOG_PLANES_PER_STRUCTURE,
		"s_structure_fog_plane_debug_info",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTURE_BSP_FOG_PLANE_DEBUG_INFO_BLOCK_ID)
	{
		{ _field_long_integer, "fog zone index", FIELD_FLAG_READ_ONLY },
		FIELD_PAD("WZGH", nullptr, FIELD_FLAG_NONE, 24),
		{ _field_long_integer, "connected plane designator", FIELD_FLAG_READ_ONLY },
		{ _field_block, "lines", FIELD_FLAG_READ_ONLY, &structure_bsp_debug_info_render_line_block },
		{ _field_block, "intersected cluster indices", FIELD_FLAG_READ_ONLY, &structure_bsp_debug_info_indices_block },
		{ _field_block, "inf. extent cluster indices", FIELD_FLAG_READ_ONLY, &structure_bsp_debug_info_indices_block },
		{ _field_terminator }
	};

	#define STRUCTURE_BSP_FOG_ZONE_DEBUG_INFO_BLOCK_ID { 0x54513BD1, 0x61374DCB, 0x950FF95C, 0x72B662D5 }
	TAG_BLOCK(
		structure_bsp_fog_zone_debug_info_block,
		"structure_bsp_fog_zone_debug_info_block",
		MAXIMUM_FOG_ZONES_PER_STRUCTURE,
		"s_structure_fog_zone_debug_info",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTURE_BSP_FOG_ZONE_DEBUG_INFO_BLOCK_ID)
	{
		{ _field_long_integer, "media index", nullptr, "scenario fog plane", FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "base fog plane index", FIELD_FLAG_READ_ONLY },
		FIELD_PAD("RB", nullptr, FIELD_FLAG_NONE, 24),
		{ _field_block, "lines", FIELD_FLAG_READ_ONLY, &structure_bsp_debug_info_render_line_block },
		{ _field_block, "immersed cluster indices", FIELD_FLAG_READ_ONLY, &structure_bsp_debug_info_indices_block },
		{ _field_block, "bounding fog plane indices", FIELD_FLAG_READ_ONLY, &structure_bsp_debug_info_indices_block },
		{ _field_block, "collision fog plane indices", FIELD_FLAG_READ_ONLY, &structure_bsp_debug_info_indices_block },
		{ _field_terminator }
	};

	#define WIDGET_REFERENCE_BLOCK_ID { 0xFE7DCA2C, 0x49136A81, 0xB9652900, 0xABAA5A82 }
	TAG_BLOCK(
		widget_reference_block,
		"widget_reference_block",
		MAXIMUM_MARKERS_PER_STRUCTURE,
		"s_widget_marker_reference",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		WIDGET_REFERENCE_BLOCK_ID)
	{
		{ _field_short_integer, "marker index", FIELD_FLAG_READ_ONLY },
		FIELD_PAD("gnlao", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_tag_reference, "widget ref", FIELD_FLAG_READ_ONLY, &leaf_system_reference },
		{ _field_terminator }
	};

	#define STRUCTURE_BSP_RAW_RESOURCES_ID { 0x3A39EBF4, 0xA1FA4120, 0x8CA7C0AC, 0x54DCAE26 }
	TAG_BLOCK(
		structure_bsp_raw_resources_block,
		"structure_bsp_raw_resources",
		1,
		"s_structure_bsp_resources",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTURE_BSP_RAW_RESOURCES_ID)
	{
		{ _field_struct, "raw_items", &structure_bsp_resource_struct },
		{ _field_terminator }
	};

	#define STRUCTURE_EXTERNAL_INSTANCED_GEOMETRY_REFERENCES_BLOCK_ID { 0x87C8EF26, 0xE9354157, 0x85B70AF5, 0x447B03B8 }
	TAG_BLOCK(
		structure_external_instanced_geometry_references_block,
		"structure_external_instanced_geometry_references_block",
		k_external_instanced_geometry_max,
		"structure_external_instanced_geometry_reference",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTURE_EXTERNAL_INSTANCED_GEOMETRY_REFERENCES_BLOCK_ID)
	{
		{ _field_tag_reference, "prefab reference", &prefab_reference },
		{ _field_string_id, "name", FIELD_FLAG_READ_ONLY | FIELD_FLAG_INDEX },
		{ _field_real, "scale" },
		{ _field_real_vector_3d, "forward" },
		{ _field_real_vector_3d, "left" },
		{ _field_real_vector_3d, "up" },
		{ _field_real_point_3d, "position" },
		{ _field_short_integer, "mesh count", FIELD_FLAG_UNKNOWN0 },
		{ _field_short_integer, "mesh block index", FIELD_FLAG_UNKNOWN0 },
		{ _field_short_integer, "light count", FIELD_FLAG_UNKNOWN0 },
		{ _field_short_integer, "light instance block index", FIELD_FLAG_UNKNOWN0 },
		{ _field_short_integer, "dynamic object count", FIELD_FLAG_UNKNOWN0 },
		{ _field_short_integer, "dynamic object block index", FIELD_FLAG_UNKNOWN0 },
		{ _field_word_flags, "override flags", &instanced_geometry_flags },
		FIELD_PAD("SDFSDEE", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_char_enum, "override pathfinding policy", &instanced_geometry_pathfinding_policy_enum },
		{ _field_char_enum, "override lightmapping policy", &instanced_geometry_lightmapping_policy_enum },
		{ _field_char_enum, "override imposter policy", &instanced_geometry_imposter_policy_enum },
		{ _field_char_enum, "override streaming priority", FIELD_FLAG_READ_ONLY, &instanced_geometry_streamingpriority_enum },
		{ _field_real, "override lightmap resolution scale" },
		{ _field_real, "override imposter transition distance" },
		{ _field_real, "override imposter brightness" },
		{ _field_real, "override light channel flags" },
		{ _field_word_flags, "instance flags Mask", &instanced_geometry_flags },
		{ _field_word_flags, "instance policy mask", &prefabOverrideFlags },
		{ _field_terminator }
	};

	#define STRUCTURE_BSP_OBB_VOLUME_BLOCK_ID { 0x7B8CD005, 0x85E1496D, 0xAE545C18, 0x4F842706 }
	TAG_BLOCK(
		structure_bsp_obb_volume_block,
		"structure_bsp_obb_volume_block",
		4096,
		"s_structure_bsp_obb_volume",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTURE_BSP_OBB_VOLUME_BLOCK_ID)
	{
		{ _field_real_point_3d, "origin" },
		{ _field_real_vector_3d, "axis 1" },
		{ _field_real_vector_3d, "axis 2" },
		{ _field_real_vector_3d, "axis 3" },
		{ _field_dword_integer, "type" },
		{ _field_terminator }
	};

	#define ANIMGRAPHDEPENDENCYBLOCK_ID { 0x39127510, 0x2A154795, 0xB625EF56, 0x00B30C28 }
	TAG_BLOCK(
		AnimGraphDependencyBlock_block,
		"AnimGraphDependencyBlock",
		256,
		"AnimGraphDependency",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		ANIMGRAPHDEPENDENCYBLOCK_ID)
	{
		{ _field_tag_reference, "graph", &model_animation_graph_reference$2 },
		{ _field_terminator }
	};

	#define STRUCTUREBSPFXMARKERBLOCK_ID { 0x025D71C3, 0x50534BF1, 0xB1331C99, 0x25EAA551 }
	TAG_BLOCK(
		structureBspFxMarkerBlock_block,
		"structureBspFxMarkerBlock",
		MAXIMUM_MARKERS_PER_STRUCTURE,
		"structureFxMarker",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTUREBSPFXMARKERBLOCK_ID)
	{
		{ _field_string, "marker name", FIELD_FLAG_INDEX },
		{ _field_real_quaternion, "rotation", FIELD_FLAG_READ_ONLY },
		{ _field_real_point_3d, "position", FIELD_FLAG_READ_ONLY },
		{ _field_tag_reference, "optional attached effect", &structureBspFxMarkerBlock_optional_attached_effect_reference },
		{ _field_terminator }
	};

	#define STRUCTUREMETADATALIGHTCONEMARKERBLOCK_ID { 0x54973095, 0x6F2344DD, 0xA012514D, 0x3DC2A5F7 }
	TAG_BLOCK(
		structureMetadataLightConeMarkerBlock_block,
		"structureMetadataLightConeMarkerBlock",
		MAXIMUM_MARKERS_PER_STRUCTURE,
		"structureMetadataLightConeMarker",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTUREMETADATALIGHTCONEMARKERBLOCK_ID)
	{
		{ _field_string, "marker name", FIELD_FLAG_INDEX },
		{ _field_real_quaternion, "rotation" },
		{ _field_real_point_3d, "position" },
		{ _field_real, "length" },
		{ _field_real, "width" },
		{ _field_real, "intensity" },
		{ _field_real_argb_color, "light color" },
		{ _field_tag_reference, "light cone tag", &Tag::Reference<struct LightConeDefinition>::s_defaultDefinition },
		{ _field_tag_reference, "intensity curve", &Tag::Reference<class c_function_definition>::s_defaultDefinition },
		{ _field_terminator }
	};

	#define PREFAB_STRUCT_DEFINITION_ID { 0xE161B79D, 0x69904839, 0xBCB1689B, 0x7197C39E }
	TAG_STRUCT(
		prefab_struct_definition,
		"prefab_struct_definition",
		"structure_prefab",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PREFAB_STRUCT_DEFINITION_ID)
	{
		{ _field_tag_reference, "bsp reference", &scenario_structure_bsp_reference },
		{ _field_terminator }
	};

	#define STRUCTURE_BSP_CLUSTER_PORTAL_ORIENTED_BOUNDS_BLOCK_ID { 0x224A23F3, 0x3B5842F1, 0x421067FE, 0x3C5CE7F2 }
	TAG_STRUCT(
		structure_bsp_cluster_portal_oriented_bounds_block,
		"structure_bsp_cluster_portal_oriented_bounds_block",
		"cluster_portal::s_oriented_bounds",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTURE_BSP_CLUSTER_PORTAL_ORIENTED_BOUNDS_BLOCK_ID)
	{
		{ _field_real_point_3d, "center", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real_vector_3d, "extents", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real_quaternion, "orientation", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define STRUCTURE_BSP_RESOURCE_INTERFACE_ID { 0xB024FA19, 0x92E24683, 0xB26BDF83, 0x52E5E222 }
	TAG_STRUCT(
		structure_bsp_resource_interface,
		"structure_bsp_resource_interface",
		"c_structure_bsp_resource_interface",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_RESOURCES | 
		SET_UNKNOWN14 | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTURE_BSP_RESOURCE_INTERFACE_ID)
	{
		{ _field_block, "raw_resources", &structure_bsp_raw_resources_block },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach, 1 },
		{ _field_pageable, "tag_resources", &structure_bsp_tag_resources_struct },

		{ _field_pageable, "cache_file_resources", &structure_bsp_cache_file_tag_resources_struct },
		{ _field_long_integer, "use resource items", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define STRUCTURE_BSP_RESOURCE_STRUCT_ID { 0x03A9EF85, 0x2F7A473A, 0x8A86F093, 0x2DE335AF }
	TAG_STRUCT(
		structure_bsp_resource_struct,
		"structure_bsp_resource_struct",
		"s_structure_bsp_resources",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTURE_BSP_RESOURCE_STRUCT_ID)
	{
		{ _field_block, "collision bsp", FIELD_FLAG_READ_ONLY, &global_collision_bsp_block },
		{ _field_block, "large collision bsp", FIELD_FLAG_READ_ONLY, &global_large_collision_bsp_block },
		{ _field_block, "instanced geometries definitions", FIELD_FLAG_READ_ONLY, &structure_bsp_instanced_geometry_definition_block },
		{ _field_block, "Havok Data", FIELD_FLAG_READ_ONLY, &structureIOHavokDataBlock_block },
		{ _field_terminator }
	};

	#define STRUCTURE_BSP_TAG_RESOURCES_STRUCT_ID { 0x72D3359D, 0x5BCF4E28, 0xA26904A5, 0xD923E60C }
	TAG_STRUCT(
		structure_bsp_tag_resources_struct,
		"structure_bsp_tag_resources_struct",
		"s_structure_bsp_resources",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTURE_BSP_TAG_RESOURCES_STRUCT_ID)
	{
		{ _field_struct, "resource_items", &structure_bsp_resource_struct },
		{ _field_terminator }
	};

	#define STRUCTURE_BSP_CACHE_FILE_TAG_RESOURCES_STRUCT_ID { 0xF94BEACC, 0xEDAB423F, 0x82675E23, 0xFA14A1AD }
	TAG_STRUCT(
		structure_bsp_cache_file_tag_resources_struct,
		"structure_bsp_cache_file_tag_resources_struct",
		"s_structure_bsp_cache_file_resources",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTURE_BSP_CACHE_FILE_TAG_RESOURCES_STRUCT_ID)
	{
		{ _field_block, "large structure surfaces", FIELD_FLAG_READ_ONLY, &structure_surface_block },
		{ _field_block, "structure surface to triangle mapping", FIELD_FLAG_READ_ONLY, &structure_surface_to_triangle_mapping_block },
		{ _field_block, "edge to seam edge", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &structure_edge_to_seam_edge_mapping_block },
		{ _field_block, "pathfinding data", &pathfinding_data_block },
		{ _field_block, "instanced geometry instances without names", FIELD_FLAG_READ_ONLY, &structure_bsp_instanced_geometry_instances_without_names_block },
		{ _field_block, "super node parent mappings", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &super_node_mappings_block },
		{ _field_block, "super node recursable_masks", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &super_node_recursable_masks_block },
		{ _field_block, "structure_super_node_traversal_geometry_block", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &structure_super_node_traversal_geometry_block },
		{ _field_struct, "instance kd hierarchy", FIELD_FLAG_UNKNOWN0, &collision_kd_hierarchy_static_struct },
		{ _field_terminator }
	};

	STRINGS(structure_material_lighting_info_flags)
	{
		"reserved{use attenuation}",
		"power per unit area",
		"use shader gel"
	};
	STRING_LIST(structure_material_lighting_info_flags, structure_material_lighting_info_flags_strings, _countof(structure_material_lighting_info_flags_strings));

	STRINGS(structure_bsp_cluster_portal_flags_definition)
	{
		"ai can\'t hear through this shit",
		"one-way",
		"door",
		"no-way",
		"one-way-reversed",
		"no one can hear through this"
	};
	STRING_LIST(structure_bsp_cluster_portal_flags_definition, structure_bsp_cluster_portal_flags_definition_strings, _countof(structure_bsp_cluster_portal_flags_definition_strings));

	STRINGS(structure_cluster_flags)
	{
		"one way portal",
		"door portal",
		"postprocessed geometry",
		"is the sky",
		"decorators are lit"
	};
	STRING_LIST(structure_cluster_flags, structure_cluster_flags_strings, _countof(structure_cluster_flags_strings));

	STRINGS(structure_collision_materialg_flags)
	{
		"is seam"
	};
	STRING_LIST(structure_collision_materialg_flags, structure_collision_materialg_flags_strings, _countof(structure_collision_materialg_flags_strings));

	STRINGS(structure_marker_type_enum)
	{
		"none",
		"cheap light",
		"falling leaf generator",
		"light",
		"sky (unused)",
		"model"
	};
	STRING_LIST(structure_marker_type_enum, structure_marker_type_enum_strings, _countof(structure_marker_type_enum_strings));

	STRINGS(environmentObjectFlagsDefinition)
	{
		"scripts always run"
	};
	STRING_LIST(environmentObjectFlagsDefinition, environmentObjectFlagsDefinition_strings, _countof(environmentObjectFlagsDefinition_strings));

	STRINGS(structure_super_node_mapping_flags)
	{
		"above"
	};
	STRING_LIST(structure_super_node_mapping_flags, structure_super_node_mapping_flags_strings, _countof(structure_super_node_mapping_flags_strings));

	STRINGS(structure_bsp_debug_info_cluster_error_flags)
	{
		"multiple fog planes",
		"fog zone collision",
		"fog zone immersion"
	};
	STRING_LIST(structure_bsp_debug_info_cluster_error_flags, structure_bsp_debug_info_cluster_error_flags_strings, _countof(structure_bsp_debug_info_cluster_error_flags_strings));

	STRINGS(structure_bsp_debug_info_cluster_warning_flags)
	{
		"multiple visible fog planes",
		"visible fog cluster omission",
		"fog plane missed render-bsp"
	};
	STRING_LIST(structure_bsp_debug_info_cluster_warning_flags, structure_bsp_debug_info_cluster_warning_flags_strings, _countof(structure_bsp_debug_info_cluster_warning_flags_strings));

	STRINGS(structure_bsp_debug_info_render_line_type_enum)
	{
		"fog plane boundary edge",
		"fog plane internal edge",
		"fog zone floodfill",
		"fog zone cluster centroid",
		"fog zone cluster geometry",
		"fog zone portal centroid",
		"fog zone portal geometry"
	};
	STRING_LIST(structure_bsp_debug_info_render_line_type_enum, structure_bsp_debug_info_render_line_type_enum_strings, _countof(structure_bsp_debug_info_render_line_type_enum_strings));

	STRINGS(structure_bsp_flags_definition)
	{
		"has instance groups",
		"surface to triangle mapping remapped*",
		"external references converted to io",
		"structure mopp needs rebuilt",
		"structure prefab materials need postprocessing",
		"serialized havok data converted to target platform"
	};
	STRING_LIST(structure_bsp_flags_definition, structure_bsp_flags_definition_strings, _countof(structure_bsp_flags_definition_strings));

	STRINGS(structure_bsp_content_policy_flag)
	{
		"has working pathfinding",
		"convex decomposition enabled"
	};
	STRING_LIST(structure_bsp_content_policy_flag, structure_bsp_content_policy_flag_strings, _countof(structure_bsp_content_policy_flag_strings));

	STRINGS(structure_instance_cluster_flags)
	{
		"optimized mopp"
	};
	STRING_LIST(structure_instance_cluster_flags, structure_instance_cluster_flags_strings, _countof(structure_instance_cluster_flags_strings));

	STRINGS(structure_instance_group_flags)
	{
		"contains card imposters",
		"contains poly imposters",
		"is decorator type",
		"optimized mopp"
	};
	STRING_LIST(structure_instance_group_flags, structure_instance_group_flags_strings, _countof(structure_instance_group_flags_strings));

	STRINGS(prefabOverrideFlags)
	{
		"override pathfinding policy",
		"override lightmapping policy",
		"override lmposter policy",
		"override lightmap resolution policy",
		"override imposter transition distance policy",
		"override light channel flags policy",
		"override imposter brightness"
	};
	STRING_LIST(prefabOverrideFlags, prefabOverrideFlags_strings, _countof(prefabOverrideFlags_strings));

	TAG_REFERENCE(structure_lighting_bsp_reference, SCENARIO_STRUCTURE_LIGHTING_INFO_TAG);

} // namespace macaque

} // namespace blofeld

