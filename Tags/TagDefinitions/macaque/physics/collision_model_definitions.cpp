#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define COLLISION_MODEL_STRUCT_DEFINITION_ID { 0x82629323, 0x5D1942A5, 0x94270FB1, 0x49FBDD92 }
	TAG_BLOCK(
		collision_model_block,
		"collision_model_block",
		1,
		"collision_model_definition",
		SET_UNKNOWN0 | SET_UNKNOWN4 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_RESOURCES | 
		SET_UNKNOWN14 | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		COLLISION_MODEL_STRUCT_DEFINITION_ID)
	{
		{ _field_long_integer, "import_info_checksum", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_block, "errors", FIELD_FLAG_READ_ONLY, &global_error_report_categories_block },
		{ _field_long_flags, "flags", FIELD_FLAG_READ_ONLY, &collision_model_flags },
		{ _field_block, "materials", FIELD_FLAG_READ_ONLY, &collision_model_material_block },
		{ _field_block, "regions", FIELD_FLAG_READ_ONLY, &collision_model_region_block },
		{ _field_block, "cookie cutters", FIELD_FLAG_READ_ONLY, &collision_model_region_block },
		{ _field_block, "pathfinding spheres", FIELD_FLAG_READ_ONLY, &collision_model_pathfinding_sphere_block },
		{ _field_block, "nodes", FIELD_FLAG_READ_ONLY, &collision_model_node_block },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_long_integer, "unknown@" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_pageable, "regions resource", &collision_model_resource_struct },
			
		{ _field_terminator }
	};

	TAG_GROUP(
		collision_model_group,
		COLLISION_MODEL_TAG,
		nullptr,
		INVALID_TAG,
		collision_model_block );

	#define COLLISION_MODEL_MATERIAL_BLOCK_ID { 0x7B10BA44, 0xCCA147A9, 0xBA00D05C, 0x22B0B273 }
	TAG_BLOCK(
		collision_model_material_block,
		"material",
		MAXIMUM_MATERIALS_PER_MODEL,
		"collision_model_material",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		COLLISION_MODEL_MATERIAL_BLOCK_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_READ_ONLY | FIELD_FLAG_INDEX },
		{ _field_terminator }
	};

	#define COLLISION_MODEL_REGION_BLOCK_ID { 0xA2B3D98B, 0x4F4246CE, 0xA22339FE, 0xC303404E }
	TAG_BLOCK(
		collision_model_region_block,
		"region",
		MAXIMUM_REGIONS_PER_MODEL,
		"collision_model_region",
		SET_UNKNOWN0 | SET_UNKNOWN4 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		COLLISION_MODEL_REGION_BLOCK_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_READ_ONLY | FIELD_FLAG_INDEX },
		{ _field_block, "permutations", FIELD_FLAG_READ_ONLY, &collision_model_permutation_block },
		{ _field_terminator }
	};

	#define COLLISION_MODEL_PERMUTATION_BLOCK_ID { 0xAB85D1D7, 0x6FED4CD0, 0x9D46D6F6, 0x52EE1C6D }
	TAG_BLOCK(
		collision_model_permutation_block,
		"collision_model_permutation_block",
		MAXIMUM_PERMUTATIONS_PER_MODEL_REGION,
		"collision_model_permutation_block",
		SET_UNKNOWN0 | SET_UNKNOWN4 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		COLLISION_MODEL_PERMUTATION_BLOCK_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_READ_ONLY | FIELD_FLAG_INDEX },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_short_integer, "resourceBspOffset", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "resourceBspCount", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },

		{ _field_block, "bsps", FIELD_FLAG_READ_ONLY, &collision_model_bsp_block },
		{ _field_block, "bsp_physics", FIELD_FLAG_READ_ONLY, &collision_bsp_physics_block },
		{ _field_block, "mopp_codes", FIELD_FLAG_READ_ONLY, &mopp_code_definition_block },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(
		collision_model_bsp_block,
		"bsp",
		MAXIMUM_BSPS_PER_COLLISION_REGION,
		collision_model_bsp_struct);

	#define COLLISION_MODEL_PATHFINDING_SPHERE_BLOCK_ID { 0xEC25013C, 0xA1934E7A, 0xAD0346BB, 0x515C39B6 }
	TAG_BLOCK(
		collision_model_pathfinding_sphere_block,
		"sphere",
		MAXIMUM_PATHFINDING_SPHERES_PER_COLLISION_MODEL,
		"collision_model_pathfinding_sphere",
		SET_UNKNOWN4 | SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		COLLISION_MODEL_PATHFINDING_SPHERE_BLOCK_ID)
	{
		{ _field_short_block_index, "node", FIELD_FLAG_READ_ONLY, &collision_model_node_block },
		{ _field_word_flags, "flags", &pathfinding_sphere_flags },
		{ _field_useless_pad, "" },
		{ _field_real_point_3d, "center", FIELD_FLAG_READ_ONLY },
		{ _field_real, "radius", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define COLLISION_MODEL_NODE_BLOCK_ID { 0x732343D3, 0x041E4597, 0x92128A86, 0x949F6A18 }
	TAG_BLOCK(
		collision_model_node_block,
		"collision_model_node_block",
		MAXIMUM_NODES_PER_MODEL,
		"collision_model_node_block",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		COLLISION_MODEL_NODE_BLOCK_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_READ_ONLY | FIELD_FLAG_INDEX },
		FIELD_PAD("PFPPD", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_short_block_index, "parent node", FIELD_FLAG_READ_ONLY, &collision_model_node_block },
		{ _field_short_block_index, "next sibling node", FIELD_FLAG_READ_ONLY, &collision_model_node_block },
		{ _field_short_block_index, "first child node", FIELD_FLAG_READ_ONLY, &collision_model_node_block },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(
		collision_model_resource_bsp_block,
		"collision_model_resource_bsp_block",
		MAXIMUM_BSPS_PER_COLLISION_REGION*MAXIMUM_PERMUTATIONS_PER_MODEL_REGION*MAXIMUM_REGIONS_PER_MODEL,
		collision_model_bsp_struct);

	#define COLLISION_MODEL_BSP_STRUCT_ID { 0x036840D2, 0x531648C1, 0x887F7243, 0xB140B84F }
	TAG_STRUCT(
		collision_model_bsp_struct,
		"collision_model_bsp_struct",
		"collision_model_bsp",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN4 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		COLLISION_MODEL_BSP_STRUCT_ID)
	{
		{ _field_short_integer, "node index", FIELD_FLAG_READ_ONLY },
		FIELD_PAD("KXGCEIEI", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_useless_pad, "" },
		{ _field_struct, "bsp", FIELD_FLAG_READ_ONLY, &global_collision_bsp_struct },
		{ _field_terminator }
	};

	#define COLLISION_MODEL_RESOURCE_STRUCT_ID { 0x402FD7CD, 0x2E624614, 0x91F8C28F, 0x48E37EB6 }
	TAG_STRUCT(
		collision_model_resource_struct,
		"collision_model_resource_struct",
		"CollisionModelResource",
		SET_UNKNOWN0 | SET_UNKNOWN4 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		COLLISION_MODEL_RESOURCE_STRUCT_ID)
	{
		{ _field_block, "bsps", &collision_model_resource_bsp_block },
		{ _field_terminator }
	};

	STRINGS(pathfinding_sphere_flags)
	{
		"remains when open",
		"vehicle only",
		"with sectors"
	};
	STRING_LIST(pathfinding_sphere_flags, pathfinding_sphere_flags_strings, _countof(pathfinding_sphere_flags_strings));

	STRINGS(collision_model_flags)
	{
		"contains open edges",
		"physics built*!",
		"physics in use*!",
		"processed*!",
		"has two sided surfaces"
	};
	STRING_LIST(collision_model_flags, collision_model_flags_strings, _countof(collision_model_flags_strings));

} // namespace macaque

} // namespace blofeld

