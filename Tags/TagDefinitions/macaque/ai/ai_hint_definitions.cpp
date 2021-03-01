#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define USER_HINT_BLOCK_ID { 0x8E857EED, 0xECA14C74, 0xB042E3D8, 0x772B85FB }
	TAG_BLOCK(
		user_hint_block,
		"user_hint_block",
		1,
		"user_hint_data",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		USER_HINT_BLOCK_ID)
	{
		{ _field_block, "line segment geometry", &user_hint_line_segment_block },
		{ _field_block, "parallelogram geometry", &user_hint_parallelogram_block },
		{ _field_block, "jump hints", &user_hint_jump_block },
		{ _field_block, "climb hints", &user_hint_climb_block },
		{ _field_block, "well hints", &user_hint_well_block },
		{ _field_block, "flight hints", &user_hint_flight_block },
		{ _field_block, "volume avoidance hints", &user_hint_volume_avoidance_block },
		{ _field_block, "spline hints", &user_hint_spline_block },
		{ _field_block, "cookie cutters", &user_hint_cookie_cutter_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach }, // #NOTE assumed that reach has no navmesh support
		{ _field_block, "navmesh areas", &user_hint_navmesh_area_block },

		{ _field_block, "giant hints", &user_hint_giant_block },
		{ _field_block, "flood hints", &user_hint_flood_block },
		{ _field_terminator }
	};

	#define USER_HINT_LINE_SEGMENT_BLOCK_ID { 0xA392E29A, 0xEE1145F9, 0x93FDF552, 0x0799BE4B }
	TAG_BLOCK(
		user_hint_line_segment_block,
		"user_hint_line_segment_block",
		k_max_hint_geometries,
		"user_hint_line_segment",
		SET_POSTPROCESS_RECURSIVELY | SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_WRITEABLE),
		USER_HINT_LINE_SEGMENT_BLOCK_ID)
	{
		{ _field_long_flags, "Flags", &user_hint_geometry_flags },
		{ _field_real_point_3d, "Point 0" },
		{ _field_custom_long_block_index, "packedKeyOffaceref0", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_UNKNOWN3 },
		{ _field_custom_long_block_index, "navMeshUIDOffaceref0", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_UNKNOWN3 },
		{ _field_real_point_3d, "Point 1" },
		{ _field_custom_long_block_index, "packedKeyOffaceref1", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_UNKNOWN3 },
		{ _field_custom_long_block_index, "navMeshUIDOffaceref1", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_UNKNOWN3 },
		{ _field_terminator }
	};

	#define USER_HINT_PARALLELOGRAM_BLOCK_ID { 0xDE702C7E, 0x6C544FF7, 0x92C31361, 0x31033915 }
	TAG_BLOCK(
		user_hint_parallelogram_block,
		"user_hint_parallelogram_block",
		k_max_hint_geometries,
		"user_hint_parallelogram",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		USER_HINT_PARALLELOGRAM_BLOCK_ID)
	{
		{ _field_long_flags, "Flags", &user_hint_geometry_flags },
		{ _field_real_point_3d, "Point 0" },
		{ _field_custom_long_block_index, "packedKeyOffaceref0", FIELD_FLAG_UNKNOWN0 },
		{ _field_custom_long_block_index, "navMeshUIDOffaceref0", FIELD_FLAG_UNKNOWN0 },
		{ _field_real_point_3d, "Point 1" },
		{ _field_custom_long_block_index, "packedKeyOffaceref1", FIELD_FLAG_UNKNOWN0 },
		{ _field_custom_long_block_index, "navMeshUIDOffaceref1", FIELD_FLAG_UNKNOWN0 },
		{ _field_real_point_3d, "Point 2" },
		{ _field_custom_long_block_index, "packedKeyOffaceref2", FIELD_FLAG_UNKNOWN0 },
		{ _field_custom_long_block_index, "navMeshUIDOffaceref2", FIELD_FLAG_UNKNOWN0 },
		{ _field_real_point_3d, "Point 3" },
		{ _field_custom_long_block_index, "packedKeyOffaceref3", FIELD_FLAG_UNKNOWN0 },
		{ _field_custom_long_block_index, "navMeshUIDOffaceref3", FIELD_FLAG_UNKNOWN0 },
		{ _field_word_flags, "invalid_points", FIELD_FLAG_READ_ONLY, &parallelogram_points_invalid_flags },
		FIELD_PAD("KJHIUF", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	#define USER_HINT_JUMP_BLOCK_ID { 0x5FAFC377, 0xA4B146AC, 0xA6A374C6, 0x0DAFEE5A }
	TAG_BLOCK(
		user_hint_jump_block,
		"user_hint_jump_block",
		k_max_hint_geometries,
		"user_hint_jump",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_WRITEABLE),
		USER_HINT_JUMP_BLOCK_ID)
	{
		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 7 },
		{ _field_enum, "hint type", &hint_type_enum },
		{ _field_short_block_index, "Squad group filter", &squad_groups_block },
		{ _field_block, "hint vertices", FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3, &hint_vertex_block },
		{ _field_long_integer, "hint data 0", FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "hint data 1", FIELD_FLAG_READ_ONLY },
		{ _field_byte_integer, "hint data 2", FIELD_FLAG_READ_ONLY },
		{ _field_byte_integer, "pad1", FIELD_FLAG_READ_ONLY },

		{ _field_word_flags, "Flags", &user_hint_geometry_flags },
		{ _field_short_block_index, "geometry index", FIELD_FLAG_READ_ONLY, &user_hint_parallelogram_block },
		{ _field_enum, "force jump height", &global_ai_jump_height_enum },
		{ _field_word_flags, "control flags", &jump_flags },
		{ _field_terminator }
	};

	#define HINT_VERTEX_BLOCK_ID { 0xD1BE6D07, 0xA78F4322, 0x993136EC, 0x1C79F419 }
	TAG_BLOCK(
		hint_vertex_block,
		"hint_vertex_block",
		(1024),
		"real_point3d",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		HINT_VERTEX_BLOCK_ID)
	{
		{ _field_real_point_3d, "point", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define USER_HINT_CLIMB_BLOCK_ID { 0x6A67CD6B, 0x706D4B61, 0xA2AC7D7F, 0x935B4514 }
	TAG_BLOCK(
		user_hint_climb_block,
		"user_hint_climb_block",
		k_max_climb_hints,
		"user_hint_climb",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_WRITEABLE),
		USER_HINT_CLIMB_BLOCK_ID)
	{
		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 7 },
		{ _field_enum, "hint type", &hint_type_enum },
		{ _field_short_block_index, "Squad group filter", &squad_groups_block },
		{ _field_block, "hint vertices", FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3, &hint_vertex_block },
		{ _field_long_integer, "hint data 0", FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "hint data 1", FIELD_FLAG_READ_ONLY },
		{ _field_byte_integer, "hint data 2", FIELD_FLAG_READ_ONLY },
		{ _field_byte_integer, "pad1", FIELD_FLAG_READ_ONLY },

		{ _field_word_flags, "Flags", &user_hint_geometry_flags },
		{ _field_short_block_index, "geometry index", FIELD_FLAG_READ_ONLY, &user_hint_line_segment_block },
		{ _field_enum, "force hoist height", &forced_hoist_height_enum },
		FIELD_PAD("post-forced-hoist-height", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	#define USER_HINT_WELL_BLOCK_ID { 0xB85E0E09, 0x77864ADD, 0x8518BC91, 0x4109DAC4 }
	TAG_BLOCK(
		user_hint_well_block,
		"user_hint_well_block",
		k_max_hint_geometries,
		"user_hint_well",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		USER_HINT_WELL_BLOCK_ID)
	{
		{ _field_long_flags, "flags", &user_hint_well_geometry_flags },
		{ _field_block, "points", &user_hint_well_point_block },
		{ _field_terminator }
	};

	#define USER_HINT_WELL_POINT_BLOCK_ID { 0xEC1F1B2F, 0x3F284D04, 0x8BE174D1, 0x90862606 }
	TAG_BLOCK(
		user_hint_well_point_block,
		"user_hint_well_point_block",
		k_max_hint_geometries,
		"user_hint_well_point",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_WRITEABLE),
		USER_HINT_WELL_POINT_BLOCK_ID)
	{
		{ _field_enum, "type", &user_hint_well_point_type_enum },
		FIELD_PAD("CNXLP", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real_point_3d, "point" },
		{ _field_custom_long_block_index, "packedKeyOffaceref", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_UNKNOWN3 },
		{ _field_custom_long_block_index, "navMeshUIDOffaceref", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_UNKNOWN3 },
		{ _field_real_euler_angles_2d, "normal" },
		{ _field_terminator }
	};

	#define USER_HINT_FLIGHT_BLOCK_ID { 0xB581E84E, 0x09FF4697, 0xB58594A3, 0xDD4DDF06 }
	TAG_BLOCK(
		user_hint_flight_block,
		"user_hint_flight_block",
		k_max_flight_hints_per_bsp,
		"user_flight_hint",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		USER_HINT_FLIGHT_BLOCK_ID)
	{
		{ _field_block, "points", &user_hint_flight_point_block },
		{ _field_terminator }
	};

	#define USER_HINT_FLIGHT_POINT_BLOCK_ID { 0x2AA64424, 0xBAF84638, 0x89BFB4AA, 0x35A278B4 }
	TAG_BLOCK(
		user_hint_flight_point_block,
		"user_hint_flight_point_block",
		k_max_points_per_flight_hint,
		"user_hint_flight_point",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		USER_HINT_FLIGHT_POINT_BLOCK_ID)
	{
		{ _field_real_vector_3d, "point" },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(
		user_hint_volume_avoidance_block,
		"user_hint_volume_avoidance",
		k_max_avoidance_volumes_per_bsp,
		user_hint_volume_avoidance_struct);

	#define USER_HINT_SPLINE_BLOCK_ID { 0x4195BB83, 0x5F8E428A, 0x85E900EA, 0x15FC8C7E }
	TAG_BLOCK(
		user_hint_spline_block,
		"user_hint_spline_block",
		k_max_spline_hints_per_bsp,
		"s_user_hint_spline",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		USER_HINT_SPLINE_BLOCK_ID)
	{
		{ _field_string_id, "name" },
		{ _field_real, "radius", nullptr, "wus" },
		{ _field_real, "time between points", nullptr, "sec" },
		{ _field_block, "control points", &user_hint_spline_control_point_block },
		{ _field_short_block_index, "bsp", &scenario_structure_bsp_reference_block },
		FIELD_PAD("post-bsp-pad", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_block, "volume intersect points", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &user_hint_spline_intersect_point_block },
		{ _field_terminator }
	};

	#define USER_HINT_SPLINE_CONTROL_POINT_BLOCK_STRUCT_ID { 0xE44C896B, 0x73DD4D16, 0xA510B2D5, 0x73AC4D5D }
	TAG_BLOCK(
		user_hint_spline_control_point_block,
		"user_hint_spline_control_point_block",
		k_max_control_points_per_spline_hint,
		"s_user_hint_spline_control_point",
		SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		USER_HINT_SPLINE_CONTROL_POINT_BLOCK_STRUCT_ID)
	{
		{ _field_word_flags, "flags", &user_hint_spline_segment_flags },
		FIELD_PAD("post-flags-pad", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real_point_3d, "point", _field_id_point },
		{ _field_real_vector_3d, "tangent" },
		{ _field_real, "segment arc length", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define USER_HINT_SPLINE_INTERSECT_POINT_BLOCK_STRUCT_ID { 0xE113E95D, 0xBEB24849, 0x9CCCECA4, 0x8EE06828 }
	TAG_BLOCK(
		user_hint_spline_intersect_point_block,
		"user_hint_spline_intersect_point_block",
		2,
		"s_user_hint_spline_intersect_point",
		SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		USER_HINT_SPLINE_INTERSECT_POINT_BLOCK_STRUCT_ID)
	{
		{ _field_short_block_index, "volume index", &user_hint_volume_avoidance_block },
		FIELD_PAD("post-volume-index-pad", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real_point_3d, "point" },
		{ _field_real_vector_3d, "tangent" },
		{ _field_terminator }
	};

	#define USER_HINT_COOKIE_CUTTER_BLOCK_STRUCT_ID { 0x51C7F11E, 0xA5064538, 0xAAAFEA9C, 0x8154A396 }
	TAG_BLOCK(
		user_hint_cookie_cutter_block,
		"user_hint_cookie_cutter_block",
		k_max_cookie_cutters,
		"s_cookie_cutter",
		SET_UNKNOWN0 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | 
		SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_WRITEABLE | TAG_MEMORY_USAGE_NON_ALIASED),
		USER_HINT_COOKIE_CUTTER_BLOCK_STRUCT_ID)
	{
		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 3 },
		{ _field_pointer, "hkaiVolume vtable", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 | FIELD_FLAG_POINTER, _field_id_zero_data },
		{ _field_short_integer, "size", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_short_integer, "count", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },

		{ _field_block, "points", &user_hint_sector_point_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_block, "pointsObjectIds", &hint_object_id_block },

		{ _field_real, "z height" },
		{ _field_real, "z sink" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 7 },
		{ _field_enum, "type", &cookie_cutter_type_enum },
		{ _field_short_integer, "pad", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "runtimeObjectTransformOverrideIndex", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_char_integer, "invalid", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_char_integer, "pad2", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_char_integer, "pad3", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_char_integer, "pad4", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },

		{ _field_terminator }
	};

	#define USER_HINT_SECTOR_POINT_BLOCK_ID { 0x33170C5B, 0x126041FF, 0x8EBBD6A4, 0x4C98464E }
	TAG_BLOCK(
		user_hint_sector_point_block,
		"user_hint_sector_point_block",
		k_maximum_points_per_sector,
		"s_ai_sector_point",
		SET_POSTPROCESS_RECURSIVELY | SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_WRITEABLE),
		USER_HINT_SECTOR_POINT_BLOCK_ID)
	{
		{ _field_real_point_3d, "point" },
		{ _field_custom_long_block_index, "packedKeyOffaceref", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_UNKNOWN3 },
		{ _field_custom_long_block_index, "navMeshUIDOffaceref", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_UNKNOWN3 },
		{ _field_real_euler_angles_2d, "normal" },
		{ _field_terminator }
	};

	#define HINT_OBJECT_ID_BLOCK_ID { 0x9B758221, 0x4AB243C2, 0x9A3B5FE5, 0xA09A93E0 }
	TAG_BLOCK(
		hint_object_id_block,
		"hint_object_id_block",
		k_maximum_points_per_sector,
		"c_object_identifier",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		HINT_OBJECT_ID_BLOCK_ID)
	{
		{ _field_struct, "object ID", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &scenario_object_id_struct },
		{ _field_terminator }
	};

	#define USER_HINT_NAVMESH_AREA_BLOCK_STRUCT_ID { 0x60C6E6A6, 0xEC9C446B, 0xAC02F347, 0xACFE022E }
	TAG_BLOCK(
		user_hint_navmesh_area_block,
		"user_hint_navmesh_area_block",
		k_max_navmesh_areas,
		"NavMeshArea",
		SET_UNKNOWN0 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | 
		SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_WRITEABLE | TAG_MEMORY_USAGE_NON_ALIASED),
		USER_HINT_NAVMESH_AREA_BLOCK_STRUCT_ID)
	{
		{ _field_pointer, "hkaiVolume vtable", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 | FIELD_FLAG_POINTER, _field_id_zero_data },
		{ _field_short_integer, "size", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_short_integer, "count", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_block, "points", &user_hint_sector_point_block },
		{ _field_real, "z height" },
		{ _field_real, "z sink" },
		{ _field_real, "step height" },
		{ _field_long_enum, "type", &navmesh_area_type_enum },
		{ _field_real, "isValid", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		FIELD_EXPLANATION("Max CONVEX Border Simplify Area", nullptr, FIELD_FLAG_NONE, "This controls the amount of simplification applied to internal segments and convex boundary segments"),
		{ _field_real, "Max CONVEX Border Simplify Area" },
		FIELD_EXPLANATION("Max Border Distance Error", nullptr, FIELD_FLAG_NONE, "When simplifying internal segments and convex boundary segments, this controls the maximum projected distance by which the simplified segment can deviate from the unsimplified segment"),
		{ _field_real, "Max Border Distance Error" },
		FIELD_EXPLANATION("Max CONCAVE Border Simplify Area", nullptr, FIELD_FLAG_NONE, "This controls the amount of simplification applied to concave boundary segments"),
		{ _field_real, "Max CONCAVE Border Simplify Area" },
		FIELD_EXPLANATION("Max Walkable Slope", nullptr, FIELD_FLAG_NONE, "Maximum slope AI will traverse (degrees). Don\'t touch unless necessary."),
		{ _field_real, "Max Walkable Slope" },
		FIELD_EXPLANATION("Cosine angle merge control", nullptr, FIELD_FLAG_NONE, "Faces will only be merged if the cosine of the angle between their normals is greater than this."),
		{ _field_real, "Cosine angle merge control" },
		FIELD_EXPLANATION("Hole replacement area", nullptr, FIELD_FLAG_NONE, "Holes with area less than this are candidates for conversion to quads"),
		{ _field_real, "Hole replacement area" },
		FIELD_EXPLANATION("Partition size", nullptr, FIELD_FLAG_NONE, "The maximum number of faces that can be included in a partition. Basically, don\'t change this."),
		{ _field_long_integer, "Partition size" },
		FIELD_EXPLANATION("Loop shrink factor", nullptr, FIELD_FLAG_NONE, "The area of any partition loop will not be reduced by more than this fraction"),
		{ _field_real, "Loop shrink factor" },
		{ _field_terminator }
	};

	#define USER_HINT_GIANT_BLOCK_ID { 0x0BF7986E, 0x826547BE, 0xA38ED044, 0xDB6C3FF2 }
	TAG_BLOCK(
		user_hint_giant_block,
		"user_hint_giant_block",
		1,
		"s_user_hint_giant",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		USER_HINT_GIANT_BLOCK_ID)
	{
		{ _field_block, "giant sector hints", &user_hint_giant_sector_block },
		{ _field_block, "giant rail hints", &user_hint_giant_rail_block },
		{ _field_terminator }
	};

	#define USER_HINT_GIANT_SECTOR_BLOCK_ID { 0x4AD85397, 0xD0D74BDC, 0xB6D37C85, 0x245EB9F3 }
	TAG_BLOCK(
		user_hint_giant_sector_block,
		"user_hint_giant_sector_block",
		k_max_hint_geometries,
		"s_user_hint_sector",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		USER_HINT_GIANT_SECTOR_BLOCK_ID)
	{
		{ _field_block, "points", &user_hint_sector_point_block },
		{ _field_terminator }
	};

	#define USER_HINT_GIANT_RAIL_BLOCK_ID { 0xF2320873, 0x2B8B40FF, 0xBC5FF0CD, 0xF5CA7C72 }
	TAG_BLOCK(
		user_hint_giant_rail_block,
		"user_hint_giant_rail_block",
		k_max_hint_geometries,
		"s_user_hint_giant_rail",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		USER_HINT_GIANT_RAIL_BLOCK_ID)
	{
		{ _field_short_block_index, "geometry index", FIELD_FLAG_READ_ONLY, &user_hint_line_segment_block },
		FIELD_PAD("JLOU", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	#define USER_HINT_FLOOD_BLOCK_ID { 0xFBF96DFB, 0xF74A4483, 0x973BB01D, 0xCCB4FF83 }
	TAG_BLOCK(
		user_hint_flood_block,
		"user_hint_flood_block",
		1,
		"s_user_hint_flood",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		USER_HINT_FLOOD_BLOCK_ID)
	{
		{ _field_block, "flood sector hints", &user_hint_flood_sector_block },
		{ _field_terminator }
	};

	#define USER_HINT_FLOOD_SECTOR_BLOCK_ID { 0xA81E69FD, 0x8F844CEC, 0x90A753B8, 0x5B664D35 }
	TAG_BLOCK(
		user_hint_flood_sector_block,
		"user_hint_flood_sector_block",
		k_max_hint_geometries,
		"s_user_hint_sector",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		USER_HINT_FLOOD_SECTOR_BLOCK_ID)
	{
		{ _field_block, "points", &user_hint_sector_point_block },
		{ _field_terminator }
	};

	#define SPECIAL_MOVEMENT_BLOCK_ID { 0x5AF31295, 0xE49D42AB, 0xA49A9DBC, 0x8B6B49C3 }
	TAG_BLOCK(
		special_movement_block,
		"special_movement_block",
		1,
		"special_movement_definition",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SPECIAL_MOVEMENT_BLOCK_ID)
	{
		{ _field_long_flags, "Special movement 1", &special_movement_flags },
		{ _field_terminator }
	};

	#define USER_HINT_VOLUME_AVOIDANCE_STRUCT_ID { 0x29245A8E, 0x0A494EC9, 0xBD64B83D, 0x2522CB5D }
	TAG_STRUCT(
		user_hint_volume_avoidance_struct,
		"user_hint_volume_avoidance_struct",
		"s_avoidance_volume",
		SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		USER_HINT_VOLUME_AVOIDANCE_STRUCT_ID)
	{
		{ _field_long_enum, "type", &user_hint_avoidance_volume_enum },
		{ _field_real_point_3d, "origin", MAKE_OLD_NAMES("center") },
		{ _field_real, "radius" },
		{ _field_real_vector_3d, "facing vector", "for pills" },
		{ _field_real, "height", "for pills" },
		{ _field_short_block_index, "bsp", &scenario_structure_bsp_reference_block },
		{ _field_short_integer, "spline_count", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "zone_index", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "area_index", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
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

} // namespace macaque

} // namespace blofeld

