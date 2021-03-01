#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define STRUCTURE_CLUSTER_CUBEMAP_ID { 0xCAE96BC4, 0xD7A14711, 0xBA17DE83, 0x3A3B5BAB }
	TAG_BLOCK(
		structure_cluster_cubemap_block,
		"structure_cluster_cubemap",
		k_max_cubemaps_per_cluster,
		"s_structure_cluster_cubemap_info",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTURE_CLUSTER_CUBEMAP_ID)
	{
		{ _field_short_integer, "scenario cubemap index" },
		{ _field_short_integer, "cubemap bitmap index" },
		{ _field_block, "reference points", &cubemap_reference_points_block },
		{ _field_terminator }
	};

	#define CUBEMAP_REFERENCE_POINTS_BLOCK_ID { 0x45C01CA0, 0xD2404181, 0xBCC9CAE3, 0x3C979EBD }
	TAG_BLOCK(
		cubemap_reference_points_block,
		"cubemap_reference_points_block",
		k_max_cubemap_reference_point_count,
		"s_cubemap_reference_point",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CUBEMAP_REFERENCE_POINTS_BLOCK_ID)
	{
		{ _field_real_point_3d, "reference point" },
		{ _field_long_integer, "point index", FIELD_FLAG_UNKNOWN0 },
		{ _field_terminator }
	};

	#define SCENARIO_CUBEMAP_BLOCK_ID { 0x05268782, 0x3F8F473B, 0x87B21BB6, 0x67E5D5EF }
	TAG_BLOCK(
		scenario_cubemap_block,
		"scenario_cubemap_block",
		k_max_cubemaps_per_scenario,
		"s_scenario_cubemap_info",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_CUBEMAP_BLOCK_ID)
	{
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_filter),
		{ _field_string_id, "name" },
		{ _field_real_point_3d, "cubemap position" },
		{ _field_enum, "cubemap resolution", &cubemap_resolution_enum },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 1 },
		{ _field_legacy, _field_short_integer, "unknown" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 1 },
		FIELD_PAD("post-cubemap-resolution-pad", nullptr, FIELD_FLAG_NONE, 2),

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		FIELD_EXPLANATION("bsps it could belong to", nullptr, FIELD_FLAG_NONE, "empty masks mean automatic selection."),
		{ _field_struct, "manual bsp flags", &manualBspFlagsReferences },

		{ _field_block, "reference points", &cubemap_reference_points_block },
		{ _field_terminator }
	};

	STRINGS(cubemap_resolution_enum)
	{
		"16",
		"32",
		"64",
		"128",
		"256"
	};
	STRING_LIST(cubemap_resolution_enum, cubemap_resolution_enum_strings, _countof(cubemap_resolution_enum_strings));

	TAG_REFERENCE(scenario_cubemap_bitmap_reference, BITMAP_TAG, _tag_reference_flag_dont_resolve_in_editor | _tag_reference_flag_not_a_resource_dependency);

} // namespace macaque

} // namespace blofeld

