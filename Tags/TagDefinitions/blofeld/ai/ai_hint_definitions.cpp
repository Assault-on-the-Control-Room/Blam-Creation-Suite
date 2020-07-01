#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_BLOCK(user_hint_line_segment_block, k_max_hint_geometries)
	{
		{ _field_long_flags, "Flags", &user_hint_geometry_flags },
		{ _field_real_point_3d, "Point 0" },
		{ _field_struct, "scenario_bsp_nav 0", &scenario_bsp_nav_struct_definition }, // #CUSTOM
		{ _field_real_point_3d, "Point 1" },
		{ _field_struct, "scenario_bsp_nav 1", &scenario_bsp_nav_struct_definition }, // #CUSTOM

		{ _field_terminator }
	};

	TAG_BLOCK(user_hint_parallelogram_block, k_max_hint_geometries)
	{
		{ _field_long_flags, "Flags", &user_hint_geometry_flags },
		{ _field_real_point_3d, "Point 0" },
		{ _field_struct, "scenario_bsp_nav 0", &scenario_bsp_nav_struct_definition }, // #CUSTOM
		{ _field_real_point_3d, "Point 1" },
		{ _field_struct, "scenario_bsp_nav 1", &scenario_bsp_nav_struct_definition }, // #CUSTOM
		{ _field_real_point_3d, "Point 2" },
		{ _field_struct, "scenario_bsp_nav 2", &scenario_bsp_nav_struct_definition }, // #CUSTOM
		{ _field_real_point_3d, "Point 3" },
		{ _field_struct, "scenario_bsp_nav 3", &scenario_bsp_nav_struct_definition }, // #CUSTOM
		{ _field_word_flags, "invalid_points*", &parallelogram_points_invalid_flags },
		{ _field_pad, "KJHIUF", 2 },
		{ _field_terminator }
	};

	TAG_BLOCK(hint_vertex_block, (1024))
	{
		{ _field_real_point_3d, "point*" },
		{ _field_terminator }
	};

	TAG_BLOCK(user_hint_jump_block, k_max_hint_geometries)
	{
		{ _field_version_greater, _engine_type_haloreach, 7 },
		{ _field_enum, "hint type", &hint_type_enum },
		{ _field_short_block_index, "Squad group filter" },
		{ _field_block, "hint vertices*~", &hint_vertex_block_block },
		{ _field_long_integer, "hint data 0*" },
		{ _field_short_integer, "hint data 1*" },
		{ _field_byte_integer, "hint data 2*" },
		{ _field_byte_integer, "pad1*" },

		{ _field_word_flags, "Flags", &user_hint_geometry_flags },
		{ _field_short_block_index, "geometry index*" },
		{ _field_enum, "force jump height", &global_ai_jump_height_enum },
		{ _field_word_flags, "control flags", &jump_flags },
		{ _field_terminator }
	};

	TAG_BLOCK(user_hint_climb_block, k_max_climb_hints)
	{
		{ _field_version_greater, _engine_type_haloreach, 7 },
		{ _field_enum, "hint type", &hint_type_enum },
		{ _field_short_block_index, "Squad group filter" },
		{ _field_block, "hint vertices*~", &hint_vertex_block_block },
		{ _field_long_integer, "hint data 0*" },
		{ _field_short_integer, "hint data 1*" },
		{ _field_byte_integer, "hint data 2*" },
		{ _field_byte_integer, "pad1*" },

		{ _field_word_flags, "Flags", &user_hint_geometry_flags },
		{ _field_short_block_index, "geometry index*" },
		{ _field_enum, "force hoist height", &forced_hoist_height_enum },
		{ _field_pad, "post-forced-hoist-height", 2 },
		{ _field_terminator }
	};

	TAG_BLOCK(user_hint_well_point_block, k_max_hint_geometries)
	{
		{ _field_enum, "type", &user_hint_well_point_type_enum },
		{ _field_pad, "CNXLP", 2 },
		{ _field_real_point_3d, "point" },
		{ _field_struct, "scenario_bsp_nav", &scenario_bsp_nav_struct_definition }, // #CUSTOM
		{ _field_real_euler_angles_2d, "normal" },
		{ _field_terminator }
	};

	TAG_BLOCK(user_hint_well_block, k_max_hint_geometries)
	{
		{ _field_long_flags, "flags", &user_hint_well_geometry_flags },
		{ _field_block, "points", &user_hint_well_point_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(user_hint_flight_point_block, k_max_points_per_flight_hint)
	{
		{ _field_real_vector_3d, "point" },
		{ _field_terminator }
	};

	TAG_BLOCK(user_hint_flight_block, k_max_flight_hints_per_bsp)
	{
		{ _field_block, "points", &user_hint_flight_point_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(user_hint_volume_avoidance, k_max_avoidance_volumes_per_bsp, user_hint_volume_avoidance_struct_struct_definition );

	TAG_BLOCK(user_hint_spline_control_point_block, k_max_control_points_per_spline_hint)
	{
		{ _field_word_flags, "flags", &user_hint_spline_segment_flags },
		{ _field_pad, "post-flags-pad", 2 },
		{ _field_real_point_3d, "point" },
		{ _field_real_vector_3d, "tangent" },
		{ _field_real, "segment arc length*!" },
		{ _field_terminator }
	};

	TAG_BLOCK(user_hint_spline_intersect_point_block, 2)
	{
		{ _field_short_block_index, "volume index" },
		{ _field_pad, "post-volume-index-pad", 2 },
		{ _field_real_point_3d, "point" },
		{ _field_real_vector_3d, "tangent" },
		{ _field_terminator }
	};

	TAG_BLOCK(user_hint_spline_block, k_max_spline_hints_per_bsp)
	{
		{ _field_string_id, "name" },
		{ _field_real, "radius:wus" },
		{ _field_real, "time between points:sec" },
		{ _field_block, "control points", &user_hint_spline_control_point_block_block },
		{ _field_short_block_index, "bsp" },
		{ _field_pad, "post-bsp-pad", 2 },
		{ _field_block, "volume intersect points*!", &user_hint_spline_intersect_point_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(user_hint_sector_point_block, k_maximum_points_per_sector)
	{
		{ _field_real_point_3d, "point" },
		{ _field_struct, "scenario_bsp_nav", &scenario_bsp_nav_struct_definition }, // #CUSTOM
		{ _field_real_euler_angles_2d, "normal" },
		{ _field_terminator }
	};

	TAG_BLOCK(hint_object_id_block, k_maximum_points_per_sector)
	{
		{ _field_struct, "object ID*!", &scenario_object_id_struct_struct_definition },
		{ _field_terminator }
	};

	TAG_BLOCK(user_hint_cookie_cutter_block, k_max_cookie_cutters)
	{
		{ _field_version_greater, _engine_type_haloreach, 3 },
		{ _field_pointer, "hkaiVolume vtable*~!" },
		{ _field_short_integer, "size*~!" },
		{ _field_short_integer, "count*~!" },

		{ _field_block, "points", &user_hint_sector_point_block_block },

		{ _field_version_greater, _engine_type_haloreach, 1 },
		{ _field_block, "pointsObjectIds", &hint_object_id_block_block },

		{ _field_real, "z height" },
		{ _field_real, "z sink" },

		{ _field_version_greater, _engine_type_haloreach, 7 },
		{ _field_enum, "type", &cookie_cutter_type_enum },
		{ _field_short_integer, "pad*!" },
		{ _field_long_integer, "runtimeObjectTransformOverrideIndex*~!" },
		{ _field_char_integer, "invalid*!" },
		{ _field_char_integer, "pad2*!" },
		{ _field_char_integer, "pad3*!" },
		{ _field_char_integer, "pad4*!" },

		{ _field_terminator }
	};

	TAG_BLOCK(user_hint_navmesh_area_block, k_max_navmesh_areas)
	{
		{ _field_pointer, "hkaiVolume vtable*~!" },
		{ _field_short_integer, "size*~!" },
		{ _field_short_integer, "count*~!" },
		{ _field_block, "points", &user_hint_sector_point_block_block },
		{ _field_real, "z height" },
		{ _field_real, "z sink" },
		{ _field_real, "step height" },
		{ _field_long_enum, "type", &navmesh_area_type_enum },
		{ _field_real, "isValid*~!" },
		{ _field_explanation, "Max CONVEX Border Simplify Area", "This controls the amount of simplification applied to internal segments and convex boundary segments" },
		{ _field_real, "Max CONVEX Border Simplify Area" },
		{ _field_explanation, "Max Border Distance Error", "When simplifying internal segments and convex boundary segments, this controls the maximum projected distance by which the simplified segment can deviate from the unsimplified segment" },
		{ _field_real, "Max Border Distance Error" },
		{ _field_explanation, "Max CONCAVE Border Simplify Area", "This controls the amount of simplification applied to concave boundary segments" },
		{ _field_real, "Max CONCAVE Border Simplify Area" },
		{ _field_explanation, "Max Walkable Slope", "Maximum slope AI will traverse (degrees). Don\'t touch unless necessary." },
		{ _field_real, "Max Walkable Slope" },
		{ _field_explanation, "Cosine angle merge control", "Faces will only be merged if the cosine of the angle between their normals is greater than this." },
		{ _field_real, "Cosine angle merge control" },
		{ _field_explanation, "Hole replacement area", "Holes with area less than this are candidates for conversion to quads" },
		{ _field_real, "Hole replacement area" },
		{ _field_explanation, "Partition size", "The maximum number of faces that can be included in a partition. Basically, don\'t change this." },
		{ _field_long_integer, "Partition size" },
		{ _field_explanation, "Loop shrink factor", "The area of any partition loop will not be reduced by more than this fraction" },
		{ _field_real, "Loop shrink factor" },
		{ _field_terminator }
	};

	TAG_BLOCK(user_hint_giant_sector_block, k_max_hint_geometries)
	{
		{ _field_block, "points", &user_hint_sector_point_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(user_hint_giant_rail_block, k_max_hint_geometries)
	{
		{ _field_short_block_index, "geometry index*" },
		{ _field_pad, "JLOU", 2 },
		{ _field_terminator }
	};

	TAG_BLOCK(user_hint_giant_block, 1)
	{
		{ _field_block, "giant sector hints", &user_hint_giant_sector_block_block },
		{ _field_block, "giant rail hints", &user_hint_giant_rail_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(user_hint_flood_sector_block, k_max_hint_geometries)
	{
		{ _field_block, "points", &user_hint_sector_point_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(user_hint_flood_block, 1)
	{
		{ _field_block, "flood sector hints", &user_hint_flood_sector_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(user_hint_block, 1)
	{
		{ _field_block, "line segment geometry", &user_hint_line_segment_block_block },
		{ _field_block, "parallelogram geometry", &user_hint_parallelogram_block_block },
		{ _field_block, "jump hints", &user_hint_jump_block_block },
		{ _field_block, "climb hints", &user_hint_climb_block_block },
		{ _field_block, "well hints", &user_hint_well_block_block },
		{ _field_block, "flight hints", &user_hint_flight_block_block },
		{ _field_block, "volume avoidance hints", &user_hint_volume_avoidance_block },
		{ _field_block, "spline hints", &user_hint_spline_block_block },
		{ _field_block, "cookie cutters", &user_hint_cookie_cutter_block_block },

		{ _field_version_greater, _engine_type_haloreach }, // #NOTE assumed that reach has no navmesh support
		{ _field_block, "navmesh areas", &user_hint_navmesh_area_block_block },

		{ _field_block, "giant hints", &user_hint_giant_block_block },
		{ _field_block, "flood hints", &user_hint_flood_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(special_movement_block, 1)
	{
		{ _field_long_flags, "Special movement 1", &special_movement_flags },
		{ _field_terminator }
	};

	TAG_STRUCT(user_hint_volume_avoidance_struct)
	{
		{ _field_long_enum, "type", &user_hint_avoidance_volume_enum },
		{ _field_real_point_3d, "origin{center}" },
		{ _field_real, "radius" },
		{ _field_real_vector_3d, "facing vector#for pills" },
		{ _field_real, "height#for pills" },
		{ _field_short_block_index, "bsp" },
		{ _field_short_integer, "spline_count*!" },
		{ _field_short_integer, "zone_index*!" },
		{ _field_short_integer, "area_index*!" },
		{ _field_terminator }
	};

	STRINGS(user_hint_geometry_flags)
	{
		"bidirectional",
		"closed"
	};
	STRING_LIST(user_hint_geometry_flags, user_hint_geometry_flags_strings, _countof(user_hint_geometry_flags_strings));

	STRINGS(parallelogram_points_invalid_flags)
	{
		"1",
		"2",
		"3",
		"4"
	};
	STRING_LIST(parallelogram_points_invalid_flags, parallelogram_points_invalid_flags_strings, _countof(parallelogram_points_invalid_flags_strings));

	STRINGS(hint_type_enum)
	{
		"jump link",
		"climb link",
		"vault link",
		"mount link",
		"hoist link",
		"wall jump link",
		"takeoff link",
		"jump mandatory approach"
	};
	STRING_LIST(hint_type_enum, hint_type_enum_strings, _countof(hint_type_enum_strings));

	STRINGS(jump_flags)
	{
		"magic lift",
		"vehicle only",
		"railing",
		"vault",
		"down",
		"phase",
		"stop autodown"
	};
	STRING_LIST(jump_flags, jump_flags_strings, _countof(jump_flags_strings));

	STRINGS(forced_hoist_height_enum)
	{
		"none",
		"step",
		"crouch",
		"stand"
	};
	STRING_LIST(forced_hoist_height_enum, forced_hoist_height_enum_strings, _countof(forced_hoist_height_enum_strings));

	STRINGS(user_hint_well_geometry_flags)
	{
		"bidirectional"
	};
	STRING_LIST(user_hint_well_geometry_flags, user_hint_well_geometry_flags_strings, _countof(user_hint_well_geometry_flags_strings));

	STRINGS(user_hint_well_point_type_enum)
	{
		"jump",
		"invalid",
		"hoist"
	};
	STRING_LIST(user_hint_well_point_type_enum, user_hint_well_point_type_enum_strings, _countof(user_hint_well_point_type_enum_strings));

	STRINGS(user_hint_avoidance_volume_enum)
	{
		"sphere",
		"pill"
	};
	STRING_LIST(user_hint_avoidance_volume_enum, user_hint_avoidance_volume_enum_strings, _countof(user_hint_avoidance_volume_enum_strings));

	STRINGS(user_hint_spline_segment_flags)
	{
		"no attach-detach"
	};
	STRING_LIST(user_hint_spline_segment_flags, user_hint_spline_segment_flags_strings, _countof(user_hint_spline_segment_flags_strings));

	STRINGS(cookie_cutter_type_enum)
	{
		"carve out",
		"preserve",
		"carve air volume"
	};
	STRING_LIST(cookie_cutter_type_enum, cookie_cutter_type_enum_strings, _countof(cookie_cutter_type_enum_strings));

	STRINGS(navmesh_area_type_enum)
	{
		"Navmesh Low Res",
		"Navmesh 2",
		"Navmesh 3",
		"Navmesh 4",
		"Navmesh 5",
		"Navmesh 6",
		"Navmesh 7",
		"Navmesh 8",
		"Navmesh High Res",
		"CUSTOM (Recommended)"
	};
	STRING_LIST(navmesh_area_type_enum, navmesh_area_type_enum_strings, _countof(navmesh_area_type_enum_strings));

	STRINGS(special_movement_flags)
	{
		"jump",
		"climb",
		"vault",
		"mount",
		"hoist",
		"wall jump",
		"takeoff",
		"jump mandatory approach"
	};
	STRING_LIST(special_movement_flags, special_movement_flags_strings, _countof(special_movement_flags_strings));

} // namespace blofeld

