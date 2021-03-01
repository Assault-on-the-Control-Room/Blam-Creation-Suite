#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_BLOCK(cubemap_reference_points_block, k_max_cubemap_reference_point_count)
	{
		{ _field_legacy, _field_real_point_3d, "reference point" },
		{ _field_legacy, _field_long_integer, "point index!" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(structure_cluster_cubemap, k_max_cubemaps_per_cluster)
	{
		{ _field_legacy, _field_short_integer, "scenario cubemap index" },
		{ _field_legacy, _field_short_integer, "cubemap bitmap index" },
		{ _field_legacy, _field_block, "reference points", &cubemap_reference_points_block_block },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(scenario_cubemap_block, k_max_cubemaps_per_scenario)
	{
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_string_id, "name" },
		{ _field_legacy, _field_real_point_3d, "cubemap position" },
		{ _field_legacy, _field_enum, "cubemap resolution", &cubemap_resolution_enum },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 1 },
		{ _field_legacy, _field_short_integer, "unknown" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 1 },
		{ _field_legacy, _field_pad, "post-cubemap-resolution-pad", 2 },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_legacy, _field_explanation, "bsps it could belong to", "empty masks mean automatic selection." },
		{ _field_legacy, _field_struct, "manual bsp flags", &manualBspFlagsReferences_struct_definition },

		{ _field_legacy, _field_block, "reference points", &cubemap_reference_points_block_block },
		{ _field_legacy, _field_terminator }
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

} // namespace blofeld

