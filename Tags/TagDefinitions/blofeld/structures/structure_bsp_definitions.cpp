#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{
	V5_TAG_STRUCT(scenario_bsp_nav)
	{
		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 2 },
		{ _field_legacy, _field_short_block_index, "reference frame" }, // assembly
		{ _field_legacy, _field_short_block_index, "bsp index" }, // assembly

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_legacy, _field_custom_long_block_index, "packedKeyOffaceref~!" },
		{ _field_legacy, _field_custom_long_block_index, "navMeshUIDOffaceref~!" },

		{ _field_legacy, _field_terminator }
	};

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

	V5_TAG_GROUP_FROM_BLOCK(prefab, PREFAB_TAG, prefab_block_block );

	V5_TAG_GROUP(scenario_structure_bsp, SCENARIO_STRUCTURE_BSP_TAG)
	{
		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach, 2 },
		{ _field_legacy, _field_struct, "build identifier*", &structure_manifest_build_identifier_struct_struct_definition },
		{ _field_legacy, _field_struct, "parent build identifier*", &structure_manifest_build_identifier_struct_struct_definition },

		{ _field_legacy, _field_long_integer, "import info checksum*" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 1 },
		{ _field_legacy, _field_tag_reference, "structure lighting_info^", &structure_lighting_bsp_reference },

		{ _field_legacy, _field_long_integer, "import version*!" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 1 },
		{ _field_legacy, _field_tag_reference, "structure meta data*", &Tag::Reference<struct StructureMetadata>::s_defaultDefinition },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach, 4 },
		{ _field_legacy, _field_word_flags, "flags*!", &structure_bsp_flags_definition },
		{ _field_legacy, _field_word_flags, "content policy flags*!", &structure_bsp_content_policy_flag },
		{ _field_legacy, _field_word_flags, "failed content policy flags*!", &structure_bsp_content_policy_flag },
		{ _field_legacy, _field_pad, "faild policy pad*!", 2 },

		{ _field_legacy, _field_version_less, _engine_type_haloreach, 1 },
		{ _field_legacy, _field_long_flags, "flags", &structure_bsp_flags_definition },

		{ _field_legacy, _field_block, "seam identifiers*!", &structure_seam_mapping_block_block },
		{ _field_legacy, _field_block, "edge to seam edge*!", &structure_edge_to_seam_edge_mapping_block_block },
		{ _field_legacy, _field_block, "collision materials*", &structure_collision_materials_block_block },

		{ _field_legacy, _field_version_equal, _engine_type_halo3, 1 },
		{ _field_legacy, _field_block, "collision bsp*", &global_collision_bsp_block_block },

		{ _field_legacy, _field_block, "leaves*", &structure_bsp_leaf_block_block },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach, 5 },
		{ _field_legacy, _field_block, "super aabbs*!", &structure_super_node_aabbs_block_block },
		{ _field_legacy, _field_block, "super node parent mappings*!", &super_node_mappings_block_block },
		{ _field_legacy, _field_block, "super node recursable_masks*!", &super_node_recursable_masks_block_block },
		{ _field_legacy, _field_block, "structure_super_node_traversal_geometry_block*!", &structure_super_node_traversal_geometry_block_block },
		{ _field_legacy, _field_struct, "instance kd hierarchy!", &collision_kd_hierarchy_static_struct_struct_definition },

		{ _field_legacy, _field_version_equal, _engine_type_haloreach, 1 },
		{ _field_legacy, _field_real, "unknown@" },

		{ _field_legacy, _field_real_bounds, "world bounds x*" },
		{ _field_legacy, _field_real_bounds, "world bounds y*" },
		{ _field_legacy, _field_real_bounds, "world bounds z*" },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 1 },
		{ _field_legacy, _field_block, "structure surfaces*", &structure_surface_block_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 1 },
		{ _field_legacy, _field_block, "large structure surfaces*", &structure_surface_block_block },

		{ _field_legacy, _field_block, "structure surface to triangle mapping*", &structure_surface_to_triangle_mapping_block_block },
		{ _field_legacy, _field_block, "cluster portals*", &structure_bsp_cluster_portal_block_block },

		{ _field_legacy, _field_version_less, _engine_type_haloreach, 4 },
		{ _field_legacy, _field_block, "unknown", &haloreach_sbsp_unknown_block_block },
		{ _field_legacy, _field_block, "atmosphere palette*", &scenario_atmosphere_palette_block_block },
		{ _field_legacy, _field_block, "camera fx palette", &scenario_camera_fx_palette_block_block },
		{ _field_legacy, _field_block, "weather palette", &scenario_weather_palette_block_block }, // #TODO: Confirm, based off observation with scenario_struct_definition and halo 2 guerilla

		{ _field_legacy, _field_block, "detail objects*", &structure_bsp_detail_object_data_block_block },
		{ _field_legacy, _field_block, "clusters*", &structure_bsp_cluster_block_block },
		{ _field_legacy, _field_block, "materials*", &global_geometry_material_block_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 1 },
		{ _field_legacy, _field_block, "emissive materials*", &structure_material_lighting_info_block_block },

		{ _field_legacy, _field_block, "sky owner cluster*", &structure_bsp_sky_owner_cluster_block_block },
		{ _field_legacy, _field_block, "conveyor surfaces*", &structure_bsp_conveyor_surface_block_block },
		{ _field_legacy, _field_block, "breakable surface sets*", &breakable_surface_set_block_block },
		{ _field_legacy, _field_block, "pathfinding data", &pathfinding_data_block_block },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 1 },
		{ _field_legacy, _field_block, "unknown@", &g_null_block_block }, // unknown, potentially 

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach, 1 },
		{ _field_legacy, _field_block, "cookie cutters", &structure_cookie_cutter_definition_block },

		{ _field_legacy, _field_block, "acoustics palette", &scenario_acoustics_palette_block_definition_block },
		{ _field_legacy, _field_data, "sound PAS data*" },

		{ _field_legacy, _field_version_less, _engine_type_haloreach, 2 }, // #TODO: this data is pure speculation, these might not even be tag blocks!!!
		{ _field_legacy, _field_block, "unknown@", &g_null_block_block },
		{ _field_legacy, _field_block, "unknown@", &g_null_block_block },

		{ _field_legacy, _field_block, "markers*", &structure_bsp_marker_block_block },
		{ _field_legacy, _field_block, "marker light palette*", &structure_bsp_marker_light_palette_block },
		{ _field_legacy, _field_block, "marker light palette index*", &structure_bsp_marker_light_index_block },
		{ _field_legacy, _field_block, "runtime decals*", &structure_bsp_runtime_decal_block_block },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 2 },
		{ _field_legacy, _field_block, "environment object palette*", &structure_bsp_environment_object_palette_block_block },
		{ _field_legacy, _field_block, "environment objects*", &structure_bsp_environment_object_block_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_legacy, _field_block, "(DEPRECATED) environment object palette*", &structure_bsp_environment_object_palette_block_block },
		{ _field_legacy, _field_block, "(DEPRECATED) environment objects*", &structure_bsp_environment_object_block_block },

		{ _field_legacy, _field_pad, "IMISWXUG", 4 },
		{ _field_legacy, _field_block, "leaf map leaves*", &global_map_leaf_block_block },
		{ _field_legacy, _field_block, "leaf map connections*", &global_leaf_connection_block_block },
		{ _field_legacy, _field_block, "errors*", &global_error_report_categories_block_block },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach, 4 },
		{ _field_legacy, _field_block, "cluster to instance group mopps", &mopp_code_definition_block_block },
		{ _field_legacy, _field_block, "instance group to instance mopps", &mopp_code_definition_block_block },
		{ _field_legacy, _field_block, "cluster to instance group spheres", &structure_instance_cluster_definition_block },
		{ _field_legacy, _field_block, "instance group to instance spheres", &structure_instance_group_definition_block },

		{ _field_legacy, _field_block, "instanced geometry instances*", &structure_bsp_instanced_geometry_instances_block_block },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach, 2 },
		{ _field_legacy, _field_block, "instanced geometry instance names*", &structure_bsp_instanced_geometry_instances_names_block_block },
		{ _field_legacy, _field_tag_reference, "instance imposters", &global_instance_imposter_reference },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_legacy, _field_block, "instance imposter infos", &structure_instance_imposter_info_block_block },
		{ _field_legacy, _field_long_integer, "Instance Geometry Tag Instance Count!" },

		{ _field_legacy, _field_custom, "decorator info" },
		{ _field_legacy, _field_block, "decorator sets*", &runtime_decorator_set_block_block },
		{ _field_legacy, _field_struct, "decorator instance buffer!*", &global_render_geometry_struct_struct_definition },
		{ _field_legacy, _field_custom },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach, 5 },
		{ _field_legacy, _field_custom, "decals info" },
		{ _field_legacy, _field_block, "preplaced decal sets*", &bsp_preplaced_decal_set_reference_block_block },
		{ _field_legacy, _field_block, "preplaced decals*", &bsp_preplaced_decal_reference_block_block },
		{ _field_legacy, _field_struct, "preplaced decal geometry!*", &global_render_geometry_struct_struct_definition },
		{ _field_legacy, _field_custom },

		{ _field_legacy, _field_block, "acoustics sound clusters!", &structure_bsp_sound_cluster_block_block },

		{ _field_legacy, _field_version_less, _engine_type_haloreach, 2 },
		{ _field_legacy, _field_block, "acoustics sound clusters 2!", &structure_bsp_sound_cluster_block_block },
		{ _field_legacy, _field_block, "acoustics sound clusters 3!", &structure_bsp_sound_cluster_block_block },

		{ _field_legacy, _field_block, "transparent planes*", &transparent_planes_block_block },
		{ _field_legacy, _field_block, "debug info*", &structure_bsp_debug_info_block_block },
		{ _field_legacy, _field_struct, "structure_physics*", &global_structure_physics_struct_struct_definition },

		{ _field_legacy, _field_version_less, _engine_type_haloreach, 1 }, // #TODO: this data is pure speculation!!!
		{ _field_legacy, _field_block, "unknown@", &g_null_block_block },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 1 }, // #TODO: this data is pure speculation!!!
		{ _field_legacy, _field_block, "unknown@", &g_null_block_block },

		{ _field_legacy, _field_struct, "render geometry*", &global_render_geometry_struct_struct_definition },
		{ _field_legacy, _field_block, "widget references", &widget_reference_block_block },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_block, "cheap light references", &cheap_light_reference_block_block },

		{ _field_legacy, _field_struct, "resource interface", &structure_bsp_resource_interface_struct_definition },

		{ _field_legacy, _field_version_equal, _engine_type_haloreach },
		{ _field_legacy, _field_long_integer, "unknown@" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 9 },
		{ _field_legacy, _field_custom, "Any Platform Temporary Storage" },
		{ _field_legacy, _field_block, "Any Platform Temp Havok Data*!", &structureIOHavokDataBlock_block },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_block, "external references", &structure_external_instanced_geometry_references_block_block },
		{ _field_legacy, _field_tag_reference, "dependencies", &Tag::Reference<struct s_dependency_list>::s_defaultDefinition },
		{ _field_legacy, _field_long_integer, "base material count*!" },
		{ _field_legacy, _field_block, "obb volume list", &structure_bsp_obb_volume_block_block },
		{ _field_legacy, _field_block, "scripted dependencies", &hs_references_block_block },
		{ _field_legacy, _field_block, "pupAnimations*!", &AnimGraphDependencyBlock_block },

		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK_FROM_STRUCT(prefab_block, 1, prefab_struct_definition_struct_definition );

	V5_TAG_BLOCK(structure_edge_to_seam_edge_mapping_block, ((true) ? 2621440 : UNSIGNED_SHORT_MAX))
	{
		{ _field_legacy, _field_short_integer, "seam_index*!" },
		{ _field_legacy, _field_short_integer, "seam_edge_index*!" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(structure_collision_materials_block, MAXIMUM_COLLISION_MATERIALS_PER_STRUCTURE)
	{
		{ _field_legacy, _field_tag_reference, "render method{old shader}*^", &structure_collision_materials_block_render_method_reference },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 1 },
		{ _field_legacy, _field_string_id, "override material name" },

		{ _field_legacy, _field_short_integer, "runtime global material index!" },
		{ _field_legacy, _field_short_block_index, "conveyor surface index*" },
		{ _field_legacy, _field_short_block_index, "seam mapping index*" },
		{ _field_legacy, _field_word_flags, "flags*", &structure_collision_materialg_flags },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(structure_bsp_leaf_block, ((true) ? 16*((1<<(k_bsp3d_node_child_index_bits-1))) : ((1<<(k_bsp3d_node_child_index_bits-1)))))
	{
		{ _field_legacy, _field_byte_integer, "cluster*" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(structure_super_node_aabbs_block, (k_bsp3d_maximum_super_node_count)*k_super_node_child_indices_count)
	{
		{ _field_legacy, _field_real, "x0" },
		{ _field_legacy, _field_real, "x1" },
		{ _field_legacy, _field_real, "y0" },
		{ _field_legacy, _field_real, "y1" },
		{ _field_legacy, _field_real, "z0" },
		{ _field_legacy, _field_real, "z1" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(super_node_mappings_block, (k_bsp3d_maximum_super_node_count))
	{
		{ _field_legacy, _field_short_integer, "parent_super_node_index!*" },
		{ _field_legacy, _field_char_integer, "parent_internal_node_index!*" },
		{ _field_legacy, _field_byte_flags, "flags!*", &structure_super_node_mapping_flags },
		{ _field_legacy, _field_long_integer, "has_traversal_geometry_mask!*" },
		{ _field_legacy, _field_short_block_index, "first_traversal_geometry_index!*" },
		{ _field_legacy, _field_short_block_index, "first_aabb_index!*" },
		{ _field_legacy, _field_long_integer, "aabb_mask!*" },
		{ _field_legacy, _field_short_block_index, "non_terminal_traversal_geometry_index!*" },
		{ _field_legacy, _field_pad, "pad", 2 },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(super_node_recursable_masks_block, (k_bsp3d_maximum_super_node_count))
	{
		{ _field_legacy, _field_short_integer, "mask!*" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(structure_super_node_traversal_geometry_indices_block, ((MAXIMUM_CLUSTER_PORTALS_PER_STRUCTURE)>(k_structure_seam_maximum_seam_count)?(MAXIMUM_CLUSTER_PORTALS_PER_STRUCTURE):(k_structure_seam_maximum_seam_count)))
	{
		{ _field_legacy, _field_short_integer, "index!*" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(structure_super_node_traversal_geometry_block, k_short_max)
	{
		{ _field_legacy, _field_block, "portal_indices!*", &structure_super_node_traversal_geometry_indices_block_block },
		{ _field_legacy, _field_block, "seam_indices!*", &structure_super_node_traversal_geometry_indices_block_block },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(structure_surface_block, ((true) ? SHORT_MAX<<3 : SHORT_MAX))
	{
		{ _field_legacy, _field_long_integer, "first_structure_surface_to_triangle_mapping_index*" },
		{ _field_legacy, _field_long_integer, "structure_surface_to_triangle_mapping_count*" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(structure_surface_to_triangle_mapping_block, (8*((true) ? SHORT_MAX<<3 : SHORT_MAX)))
	{
		{ _field_legacy, _field_dword_integer, "manual byteswarp1*" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(structure_bsp_cluster_portal_vertex_block, MAXIMUM_VERTICES_PER_CLUSTER_PORTAL)
	{
		{ _field_legacy, _field_real_point_3d, "point*" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(structure_bsp_cluster_portal_block, MAXIMUM_CLUSTER_PORTALS_PER_STRUCTURE)
	{
		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach, 1 },
		{ _field_legacy, _field_struct, "oriented bounds", &structure_bsp_cluster_portal_oriented_bounds_block_struct_definition },

		{ _field_legacy, _field_short_integer, "back cluster*" },
		{ _field_legacy, _field_short_integer, "front cluster*" },
		{ _field_legacy, _field_long_integer, "plane index*" },
		{ _field_legacy, _field_real_point_3d, "centroid*" },
		{ _field_legacy, _field_real, "bounding radius*" },
		{ _field_legacy, _field_long_flags, "flags*", &structure_bsp_cluster_portal_flags_definition },
		{ _field_legacy, _field_block, "vertices*", &structure_bsp_cluster_portal_vertex_block_block },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(structure_bsp_detail_object_data_block, 1)
	{
		{ _field_legacy, _field_block, "cells", &global_detail_object_cells_block_block },
		{ _field_legacy, _field_block, "instances", &global_detail_object_block_block },
		{ _field_legacy, _field_block, "counts", &global_detail_object_counts_block_block },
		{ _field_legacy, _field_block, "z reference vectors", &global_z_reference_vector_block_block },
		{ _field_legacy, _field_pad, "KXILLD", 1 },
		{ _field_legacy, _field_pad, "EDFPN", 3 },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(structure_bsp_cluster_portal_index_block, MAXIMUM_CLUSTER_PORTALS_PER_CLUSTER)
	{
		{ _field_legacy, _field_short_integer, "portal index*" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(seam_indices_block_definition, k_structure_seam_maximum_seam_count)
	{
		{ _field_legacy, _field_char_integer, "seam index*" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(cheap_light_marker_ref_block, MAXIMUM_MARKERS_PER_STRUCTURE)
	{
		{ _field_legacy, _field_short_block_index, "cheap light reference reference" },
		{ _field_legacy, _field_pad, "WHATIZZIT", 2 },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(pvs_bound_object_identifiers_block, k_maximum_scenario_object_datum_count)
	{
		{ _field_legacy, _field_struct, "object ID*!", &scenario_object_id_struct_struct_definition },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(pvs_bound_object_references_block, k_maximum_scenario_object_datum_count)
	{
		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_real_point_3d, "unknown#position?" },

		{ _field_legacy, _field_struct, "scenario object reference*!", &scenario_object_reference_struct_struct_definition },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(structure_bsp_cluster_block, MAXIMUM_CLUSTERS_PER_STRUCTURE)
	{
		{ _field_legacy, _field_explanation, "CLUSTER INFO", "" },
		{ _field_legacy, _field_real_bounds, "bounds x*" },
		{ _field_legacy, _field_real_bounds, "bounds y*" },
		{ _field_legacy, _field_real_bounds, "bounds z*" },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_char_integer, "unknown" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_legacy, _field_pad, "DING", 1 },

		{ _field_legacy, _field_char_integer, "atmosphere index*" },
		{ _field_legacy, _field_char_integer, "camera fx index*" },
		{ _field_legacy, _field_char_integer, "weather index*" },
		{ _field_legacy, _field_short_block_index, "acoustics*" },
		{ _field_legacy, _field_short_integer, "acoustics sound cluster index" },

		{ _field_legacy, _field_version_less, _engine_type_haloreach, 5 },
		{ _field_legacy, _field_short_integer, "unknown" },
		{ _field_legacy, _field_short_integer, "unknown" },
		{ _field_legacy, _field_short_integer, "unknown" },
		{ _field_legacy, _field_short_integer, "unknown" },
		{ _field_legacy, _field_short_integer, "unknown" },

		{ _field_legacy, _field_short_integer, "runtime first decal index!" },
		{ _field_legacy, _field_short_integer, "runtime decal cound!" },
		{ _field_legacy, _field_word_flags, "flags", &structure_cluster_flags },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach, 1 },
		{ _field_legacy, _field_pad, "ERERRFQ", 2 },

		{ _field_legacy, _field_block, "predicted resources*", &g_null_block_block },
		{ _field_legacy, _field_block, "portals*", &structure_bsp_cluster_portal_index_block_block },

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
		{ _field_legacy, _field_block, "mopp_codes*", &mopp_code_definition_block_block },
		{ _field_legacy, _field_long_integer, "unknown" },

		{ _field_legacy, _field_short_integer, "mesh index*" },
		{ _field_legacy, _field_short_integer, "instance imposter cluster mopp index" },
		{ _field_legacy, _field_block, "seam indices*!", &seam_indices_block_definition_block },
		{ _field_legacy, _field_block, "decorator groups*", &decorator_runtime_cluster_block_block },
		{ _field_legacy, _field_block, "cheap light marker refs*", &cheap_light_marker_ref_block_block },
		{ _field_legacy, _field_block, "pvs bound object identifiers*!", &pvs_bound_object_identifiers_block_block },
		{ _field_legacy, _field_block, "pvs bound object references*!", &pvs_bound_object_references_block_block },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_block, "cluster cubemaps", &structure_cluster_cubemap_block },

		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(structure_material_lighting_info_block, SHORT_MAX)
	{
		{ _field_legacy, _field_real, "emissive power" },
		{ _field_legacy, _field_real_rgb_color, "emissive color" },
		{ _field_legacy, _field_real, "emissive quality" },
		{ _field_legacy, _field_real, "emissive focus" },
		{ _field_legacy, _field_long_flags, "flags", &structure_material_lighting_info_flags },
		{ _field_legacy, _field_real, "attenuation falloff" },
		{ _field_legacy, _field_real, "attenuation cutoff" },
		{ _field_legacy, _field_real, "bounce ratio" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(structure_bsp_sky_owner_cluster_block, MAXIMUM_SKIES_PER_SCENARIO)
	{
		{ _field_legacy, _field_short_integer, "cluster owner*" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(structure_bsp_conveyor_surface_block, MAXIMUM_COLLISION_MATERIALS_PER_STRUCTURE)
	{
		{ _field_legacy, _field_real_vector_3d, "u" },
		{ _field_legacy, _field_real_vector_3d, "v" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(structure_cookie_cutter_definition, k_kilo)
	{
		{ _field_legacy, _field_custom, "Cookie Cutter" },
		{ _field_legacy, _field_struct, "collision model", &global_collision_bsp_struct_struct_definition },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(structure_bsp_marker_block, MAXIMUM_MARKERS_PER_STRUCTURE)
	{
		{ _field_legacy, _field_char_enum, "marker type*", &structure_marker_type_enum },
		{ _field_legacy, _field_pad, "pad", 3 },
		{ _field_legacy, _field_string, "marker parameter*" },
		{ _field_legacy, _field_real_quaternion, "rotation" },
		{ _field_legacy, _field_real_point_3d, "position*" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(structure_bsp_marker_light_palette, MAXIMUM_MARKERS_PER_STRUCTURE)
	{
		{ _field_legacy, _field_tag_reference, "light tag", &light_reference },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(structure_bsp_marker_light_index, MAXIMUM_MARKERS_PER_STRUCTURE)
	{
		{ _field_legacy, _field_short_integer, "palette index" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(structure_bsp_runtime_decal_block, MAXIMUM_DECALS_PER_STRUCTURE)
	{
		{ _field_legacy, _field_short_integer, "decal palette index!" },

		/*
			assumed from manualBspFlagsReferences's

			If flags got bigger than 16bits, padding would be added and there
			is a 32bits flags inside of manualBspFlagsReferences
		*/
		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 1 },
		{ _field_legacy, _field_short_integer, "flags" }, 

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_legacy, _field_pad, "post-decal-palette-index-pad", 2 },
		{ _field_legacy, _field_struct, "manual bsp flags", &manualBspFlagsReferences_struct_definition },

		{ _field_legacy, _field_real_quaternion, "rotation*" },
		{ _field_legacy, _field_real_point_3d, "position*" },

		{ _field_legacy, _field_version_less, _engine_type_haloreach, 1 },
		{ _field_legacy, _field_real, "scale*" },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach, 2 },
		{ _field_legacy, _field_real, "scale_x{scale}*" },
		{ _field_legacy, _field_real, "scale_y*" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 1 },
		{ _field_legacy, _field_real, "cull angle" },

		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(structure_bsp_environment_object_palette_block, MAXIMUM_ENVIRONMENT_OBJECT_PALETTE_ENTRIES_PER_STRUCTURE)
	{
		{ _field_legacy, _field_tag_reference, "definition^", &object_reference$8 },
		{ _field_legacy, _field_tag_reference, "model", &render_model_reference$9 },
		{ _field_legacy, _field_long_integer, "GVEYN!" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(structure_bsp_environment_object_block, MAXIMUM_ENVIRONMENT_OBJECTS_PER_STRUCTURE)
	{
		{ _field_legacy, _field_string, "name^" },
		{ _field_legacy, _field_real_quaternion, "rotation" },
		{ _field_legacy, _field_real_point_3d, "translation" },
		{ _field_legacy, _field_real, "scale" },
		{ _field_legacy, _field_short_block_index, "palette_index" },
		{ _field_legacy, _field_byte_flags, "flags", &environmentObjectFlagsDefinition },
		{ _field_legacy, _field_pad, "QHUGQ", 1 },

		{ _field_legacy, _field_long_integer, "unique id*" },
		{ _field_legacy, _field_tag, "exported object type" },

		{ _field_legacy, _field_version_less, _engine_type_haloreach, 1 },
		{ _field_legacy, _field_pad, "unknown", 32 }, // #TODO: Are there string id's in here???

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach, 2 },
		{ _field_legacy, _field_string_id, "scenario object name" },
		{ _field_legacy, _field_string_id, "variant name" },

		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(index_list_block, 4 * k_kilo)
	{
		{ _field_legacy, _field_word_integer, "index" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(structure_instance_cluster_definition, k_maximum_cluster_to_instance_group_block_size)
	{
		{ _field_legacy, _field_long_flags, "flags", &structure_instance_cluster_flags },
		{ _field_legacy, _field_block, "instance group indices", &index_list_block_block },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(structure_instance_group_definition, 4 * k_kilo)
	{
		{ _field_legacy, _field_real_point_3d, "center" },
		{ _field_legacy, _field_real, "radius" },
		{ _field_legacy, _field_short_integer, "cluster count" },
		{ _field_legacy, _field_word_flags, "flags", &structure_instance_group_flags },
		{ _field_legacy, _field_real, "maximum imposter distance*" },
		{ _field_legacy, _field_real, "minimum centrifugal distance from group center*" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_legacy, _field_real, "minimum imposter distance squared*" },

		{ _field_legacy, _field_block, "instance indices", &index_list_block_block },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(structure_instance_imposter_info_block, k_maximum_instance_geometry_instances_per_structure_bsp)
	{
		{ _field_legacy, _field_string_id, "name" },
		{ _field_legacy, _field_char_integer, "imposter policy" },
		{ _field_legacy, _field_pad, "parasdd", 3 },
		{ _field_legacy, _field_real, "transition distance" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(runtime_decorator_set_block, MAXIMUM_DECORATOR_SETS_PER_SCENARIO)
	{
		{ _field_legacy, _field_tag_reference, "decorator set reference*", &global_decorator_set_reference },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(bsp_preplaced_decal_set_reference_block, MAXIMUM_DECALS_PER_STRUCTURE)
	{
		{ _field_legacy, _field_long_integer, "decal definition index!" },
		{ _field_legacy, _field_char_integer, "location bsp 0!" },
		{ _field_legacy, _field_byte_integer, "location cluster 0!" },
		{ _field_legacy, _field_char_integer, "location bsp 1!" },
		{ _field_legacy, _field_byte_integer, "location cluster 1!" },
		{ _field_legacy, _field_char_integer, "location bsp 2!" },
		{ _field_legacy, _field_byte_integer, "location cluster 2!" },
		{ _field_legacy, _field_char_integer, "location bsp 3!" },
		{ _field_legacy, _field_byte_integer, "location cluster 3!" },
		{ _field_legacy, _field_real_point_3d, "center*" },
		{ _field_legacy, _field_short_integer, "first decal ref index!" },
		{ _field_legacy, _field_short_integer, "decal ref count!" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(bsp_preplaced_decal_reference_block, MAXIMUM_DECALS_PER_STRUCTURE)
	{
		{ _field_legacy, _field_short_integer, "index start" },
		{ _field_legacy, _field_short_integer, "index count" },
		{ _field_legacy, _field_short_integer, "vertex start" },
		{ _field_legacy, _field_short_integer, "vertex count" },
		{ _field_legacy, _field_short_integer, "definition block index" },
		{ _field_legacy, _field_pad, "paddddg", 2 },
		{ _field_legacy, _field_real_point_2d, "spirit corner" },
		{ _field_legacy, _field_real_vector_2d, "spirit size" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(transparent_planes_block, 32*k_kilo)
	{
		{ _field_legacy, _field_short_integer, "section index" },
		{ _field_legacy, _field_short_integer, "part index" },
		{ _field_legacy, _field_real_plane_3d, "plane" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(structure_bsp_debug_info_render_line_block, SHORT_MAX)
	{
		{ _field_legacy, _field_enum, "type*", &structure_bsp_debug_info_render_line_type_enum },
		{ _field_legacy, _field_short_integer, "code*" },
		{ _field_legacy, _field_short_integer, "pad thai*" },
		{ _field_legacy, _field_pad, "BNQS", 2 },
		{ _field_legacy, _field_real_point_3d, "point 0*" },
		{ _field_legacy, _field_real_point_3d, "point 1*" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(structure_bsp_debug_info_indices_block, SHORT_MAX)
	{
		{ _field_legacy, _field_long_integer, "index*" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(structure_bsp_cluster_debug_info_block, MAXIMUM_CLUSTERS_PER_STRUCTURE)
	{
		{ _field_legacy, _field_word_flags, "errors*", &structure_bsp_debug_info_cluster_error_flags },
		{ _field_legacy, _field_word_flags, "warnings*", &structure_bsp_debug_info_cluster_warning_flags },
		{ _field_legacy, _field_pad, "KHWRB", 28 },
		{ _field_legacy, _field_block, "lines*", &structure_bsp_debug_info_render_line_block_block },
		{ _field_legacy, _field_block, "fog plane indices*", &structure_bsp_debug_info_indices_block_block },
		{ _field_legacy, _field_block, "visible fog plane indices*", &structure_bsp_debug_info_indices_block_block },
		{ _field_legacy, _field_block, "vis-fog omission cluster indices*", &structure_bsp_debug_info_indices_block_block },
		{ _field_legacy, _field_block, "containing fog zone indices*", &structure_bsp_debug_info_indices_block_block },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(structure_bsp_fog_plane_debug_info_block, MAXIMUM_FOG_PLANES_PER_STRUCTURE)
	{
		{ _field_legacy, _field_long_integer, "fog zone index*" },
		{ _field_legacy, _field_pad, "WZGH", 24 },
		{ _field_legacy, _field_long_integer, "connected plane designator*" },
		{ _field_legacy, _field_block, "lines*", &structure_bsp_debug_info_render_line_block_block },
		{ _field_legacy, _field_block, "intersected cluster indices*", &structure_bsp_debug_info_indices_block_block },
		{ _field_legacy, _field_block, "inf. extent cluster indices*", &structure_bsp_debug_info_indices_block_block },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(structure_bsp_fog_zone_debug_info_block, MAXIMUM_FOG_ZONES_PER_STRUCTURE)
	{
		{ _field_legacy, _field_long_integer, "media index:scenario fog plane*" },
		{ _field_legacy, _field_long_integer, "base fog plane index*" },
		{ _field_legacy, _field_pad, "RB", 24 },
		{ _field_legacy, _field_block, "lines*", &structure_bsp_debug_info_render_line_block_block },
		{ _field_legacy, _field_block, "immersed cluster indices*", &structure_bsp_debug_info_indices_block_block },
		{ _field_legacy, _field_block, "bounding fog plane indices*", &structure_bsp_debug_info_indices_block_block },
		{ _field_legacy, _field_block, "collision fog plane indices*", &structure_bsp_debug_info_indices_block_block },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(structure_bsp_debug_info_block, 1)
	{
		{ _field_legacy, _field_pad, "BRQYEF", 64 },
		{ _field_legacy, _field_block, "clusters*", &structure_bsp_cluster_debug_info_block_block },
		{ _field_legacy, _field_block, "fog planes*", &structure_bsp_fog_plane_debug_info_block_block },
		{ _field_legacy, _field_block, "fog zones*", &structure_bsp_fog_zone_debug_info_block_block },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(widget_reference_block, MAXIMUM_MARKERS_PER_STRUCTURE)
	{
		{ _field_legacy, _field_short_integer, "marker index*" },
		{ _field_legacy, _field_pad, "gnlao", 2 },
		{ _field_legacy, _field_tag_reference, "widget ref*", &leaf_system_reference },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(cheap_light_reference_block, MAXIMUM_MARKERS_PER_STRUCTURE)
	{
		{ _field_legacy, _field_short_integer, "marker index*" },
		{ _field_legacy, _field_pad, "ldajk", 2 },
		{ _field_legacy, _field_tag_reference, "cheap light*", &cheap_light_reference },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(structure_bsp_raw_resources, 1)
	{
		{ _field_legacy, _field_struct, "raw_items", &structure_bsp_resource_struct_struct_definition },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(structure_external_instanced_geometry_references_block, k_external_instanced_geometry_max)
	{
		{ _field_legacy, _field_tag_reference, "prefab reference", &prefab_reference },
		{ _field_legacy, _field_string_id, "name*^" },
		{ _field_legacy, _field_real, "scale" },
		{ _field_legacy, _field_real_vector_3d, "forward" },
		{ _field_legacy, _field_real_vector_3d, "left" },
		{ _field_legacy, _field_real_vector_3d, "up" },
		{ _field_legacy, _field_real_point_3d, "position" },
		{ _field_legacy, _field_short_integer, "mesh count!" },
		{ _field_legacy, _field_short_integer, "mesh block index!" },
		{ _field_legacy, _field_short_integer, "light count!" },
		{ _field_legacy, _field_short_integer, "light instance block index!" },
		{ _field_legacy, _field_short_integer, "dynamic object count!" },
		{ _field_legacy, _field_short_integer, "dynamic object block index!" },
		{ _field_legacy, _field_word_flags, "override flags", &instanced_geometry_flags },
		{ _field_legacy, _field_pad, "SDFSDEE", 2 },
		{ _field_legacy, _field_char_enum, "override pathfinding policy", &instanced_geometry_pathfinding_policy_enum },
		{ _field_legacy, _field_char_enum, "override lightmapping policy", &instanced_geometry_lightmapping_policy_enum },
		{ _field_legacy, _field_char_enum, "override imposter policy", &instanced_geometry_imposter_policy_enum },
		{ _field_legacy, _field_char_enum, "override streaming priority*", &instanced_geometry_streamingpriority_enum },
		{ _field_legacy, _field_real, "override lightmap resolution scale" },
		{ _field_legacy, _field_real, "override imposter transition distance" },
		{ _field_legacy, _field_real, "override imposter brightness" },
		{ _field_legacy, _field_real, "override light channel flags" },
		{ _field_legacy, _field_word_flags, "instance flags Mask", &instanced_geometry_flags },
		{ _field_legacy, _field_word_flags, "instance policy mask", &prefabOverrideFlags },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(structure_bsp_obb_volume_block, 4096)
	{
		{ _field_legacy, _field_real_point_3d, "origin" },
		{ _field_legacy, _field_real_vector_3d, "axis 1" },
		{ _field_legacy, _field_real_vector_3d, "axis 2" },
		{ _field_legacy, _field_real_vector_3d, "axis 3" },
		{ _field_legacy, _field_dword_integer, "type" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(AnimGraphDependencyBlock, 256)
	{
		{ _field_legacy, _field_tag_reference, "graph", &model_animation_graph_reference$2 },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(structureBspFxMarkerBlock, MAXIMUM_MARKERS_PER_STRUCTURE)
	{
		{ _field_legacy, _field_string, "marker name^" },
		{ _field_legacy, _field_real_quaternion, "rotation*" },
		{ _field_legacy, _field_real_point_3d, "position*" },
		{ _field_legacy, _field_tag_reference, "optional attached effect", &structureBspFxMarkerBlock_optional_attached_effect_reference },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(structureMetadataLightConeMarkerBlock, MAXIMUM_MARKERS_PER_STRUCTURE)
	{
		{ _field_legacy, _field_string, "marker name^" },
		{ _field_legacy, _field_real_quaternion, "rotation" },
		{ _field_legacy, _field_real_point_3d, "position" },
		{ _field_legacy, _field_real, "length" },
		{ _field_legacy, _field_real, "width" },
		{ _field_legacy, _field_real, "intensity" },
		{ _field_legacy, _field_real_argb_color, "light color" },
		{ _field_legacy, _field_tag_reference, "light cone tag", &Tag::Reference<struct LightConeDefinition>::s_defaultDefinition },
		{ _field_legacy, _field_tag_reference, "intensity curve", &Tag::Reference<class c_function_definition>::s_defaultDefinition },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_STRUCT(prefab_struct_definition)
	{
		{ _field_legacy, _field_tag_reference, "bsp reference", &scenario_structure_bsp_reference },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_STRUCT(structure_bsp_cluster_portal_oriented_bounds_block)
	{
		{ _field_legacy, _field_real_point_3d, "center*!" },
		{ _field_legacy, _field_real_vector_3d, "extents*!" },
		{ _field_legacy, _field_real_quaternion, "orientation*!" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_STRUCT(structure_bsp_resource_interface)
	{
		{ _field_legacy, _field_block, "raw_resources", &structure_bsp_raw_resources_block },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_pageable, "tag_resources", &structure_bsp_tag_resources_struct_struct_definition },

		{ _field_legacy, _field_pageable, "cache_file_resources", &structure_bsp_cache_file_tag_resources_struct_struct_definition },
		{ _field_legacy, _field_long_integer, "use resource items*" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_STRUCT(structure_bsp_resource_struct)
	{
		{ _field_legacy, _field_block, "collision bsp*", &global_collision_bsp_block_block },
		{ _field_legacy, _field_block, "large collision bsp*", &global_large_collision_bsp_block_block },
		{ _field_legacy, _field_block, "instanced geometries definitions*", &structure_bsp_instanced_geometry_definition_block_block },
		{ _field_legacy, _field_block, "Havok Data*", &structureIOHavokDataBlock_block },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_STRUCT(structure_bsp_tag_resources_struct)
	{
		{ _field_legacy, _field_struct, "resource_items", &structure_bsp_resource_struct_struct_definition },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_STRUCT(structure_bsp_cache_file_tag_resources_struct)
	{
		{ _field_legacy, _field_block, "large structure surfaces*", &structure_surface_block_block },
		{ _field_legacy, _field_block, "structure surface to triangle mapping*", &structure_surface_to_triangle_mapping_block_block },
		{ _field_legacy, _field_block, "edge to seam edge*!", &structure_edge_to_seam_edge_mapping_block_block },
		{ _field_legacy, _field_block, "pathfinding data", &pathfinding_data_block_block },
		{ _field_legacy, _field_block, "instanced geometry instances without names*", &structure_bsp_instanced_geometry_instances_without_names_block_block },
		{ _field_legacy, _field_block, "super node parent mappings*!", &super_node_mappings_block_block },
		{ _field_legacy, _field_block, "super node recursable_masks*!", &super_node_recursable_masks_block_block },
		{ _field_legacy, _field_block, "structure_super_node_traversal_geometry_block*!", &structure_super_node_traversal_geometry_block_block },
		{ _field_legacy, _field_struct, "instance kd hierarchy!", &collision_kd_hierarchy_static_struct_struct_definition },
		{ _field_legacy, _field_terminator }
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

} // namespace blofeld

