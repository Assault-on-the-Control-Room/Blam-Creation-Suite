#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP(collision_model, COLLISION_MODEL_TAG)
	{
		{ _field_long_integer, "import_info_checksum*!" },
		{ _field_block, "errors*", &global_error_report_categories_block_block },
		{ _field_long_flags, "flags*", &collision_model_flags },
		{ _field_block, "materials*", &collision_model_material_block_block },
		{ _field_block, "regions*", &collision_model_region_block_block },
		{ _field_block, "cookie cutters*", &collision_model_region_block_block },
		{ _field_block, "pathfinding spheres*", &collision_model_pathfinding_sphere_block_block },
		{ _field_block, "nodes*", &collision_model_node_block_block },
		{ _field_pageable, "regions resource" },
		{ _field_terminator }
	};

	TAG_BLOCK(collision_model_material_block, MAXIMUM_MATERIALS_PER_MODEL)
	{
		{ _field_string_id, "name^*" },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(collision_model_bsp_block, MAXIMUM_BSPS_PER_COLLISION_REGION, collision_model_bsp_struct_struct_definition );

	TAG_BLOCK(collision_model_permutation_block, MAXIMUM_PERMUTATIONS_PER_MODEL_REGION)
	{
		{ _field_string_id, "name^*" },

		{ _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_short_integer, "resourceBspOffset*!" },
		{ _field_short_integer, "resourceBspCount*!" },

		{ _field_block, "bsps*", &collision_model_bsp_block_block },
		{ _field_block, "bsp_physics*", &collision_bsp_physics_block_block },
		{ _field_block, "mopp_codes*", &mopp_code_definition_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(collision_model_region_block, MAXIMUM_REGIONS_PER_MODEL)
	{
		{ _field_string_id, "name^*" },
		{ _field_block, "permutations*", &collision_model_permutation_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(collision_model_pathfinding_sphere_block, MAXIMUM_PATHFINDING_SPHERES_PER_COLLISION_MODEL)
	{
		{ _field_short_block_index, "node*" },
		{ _field_word_flags, "flags", &pathfinding_sphere_flags },
		{ _field_useless_pad },
		{ _field_real_point_3d, "center*" },
		{ _field_real, "radius*" },
		{ _field_terminator }
	};

	TAG_BLOCK(collision_model_node_block, MAXIMUM_NODES_PER_MODEL)
	{
		{ _field_string_id, "name^*" },
		{ _field_pad, "PFPPD", 2 },
		{ _field_short_block_index, "parent node*" },
		{ _field_short_block_index, "next sibling node*" },
		{ _field_short_block_index, "first child node*" },
		{ _field_terminator }
	};

	TAG_STRUCT(collision_model_bsp_struct)
	{
		{ _field_short_integer, "node index*" },
		{ _field_pad, "KXGCEIEI", 2 },
		{ _field_useless_pad },
		{ _field_struct, "bsp*", &global_collision_bsp_struct_struct_definition },
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

} // namespace blofeld

