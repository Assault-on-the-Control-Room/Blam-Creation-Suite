#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_BLOCK(NavMeshAttachmentBlock, MAXIMUM_STRUCTURE_BSPS_PER_SCENARIO + MAX_NUM_MOBILE_NAVMESHES)
	{
		{ _field_legacy, _field_dword_integer, "navMeshUID" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(flight_reference_block, k_max_flight_references_per_area)
	{
		{ _field_legacy, _field_short_integer, "flight hint index" },
		{ _field_legacy, _field_short_integer, "point index" },
		{ _field_legacy, _field_short_integer, "structure index" },
		{ _field_legacy, _field_pad, "post-structure-index-pad", 2 },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(area_sector_point_block, k_maximum_points_per_sector)
	{
		{ _field_legacy, _field_real_point_3d, "point" },
		//{ _field_legacy, _field_struct, "scenario_bsp_nav", &scenario_bsp_nav_struct_definition }, // #CUSTOM
		{ _field_custom_long_block_index, "packedKeyOffaceref" },
		{ _field_custom_long_block_index, "navMeshUIDOffaceref" },
		{ _field_legacy, _field_real_euler_angles_2d, "normal" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(areas_block, k_max_areas_per_zone)
	{
		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 7 },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_pointer, "hkaiVolume vtable*~!" },
		{ _field_legacy, _field_short_integer, "size*~!" },
		{ _field_legacy, _field_short_integer, "count*~!" },

		{ _field_legacy, _field_string, "name^`" },
		{ _field_legacy, _field_long_flags, "area flags", &area_flags },
		{ _field_legacy, _field_real_point_3d, "runtime relative mean point!" },
		{ _field_custom_long_block_index, "packedKeyOffaceref" }, //{ _field_legacy, _field_struct, "scenario_bsp_nav", &scenario_bsp_nav_struct_definition }, // #CUSTOM
		{ _field_custom_long_block_index, "navMeshUIDOffaceref" },
		{ _field_legacy, _field_real, "runtime standard deviation!" },
		{ _field_legacy, _field_short_integer, "runtime starting index!" },
		{ _field_legacy, _field_short_integer, "runtime count!" },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 2 }, // #TODO: commom pattern
		{ _field_legacy, _field_short_integer, "unknown" },
		{ _field_legacy, _field_short_integer, "unknown" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 1 },
		{ _field_legacy, _field_struct, "Nav Mesh Attachments*", &NavMeshAttachmentsStruct_struct_definition },

		{ _field_legacy, _field_array, "cluster occupancy!", &area_cluster_occupancy_bitvector_array_array },
		{ _field_legacy, _field_block, "flight_hints", &flight_reference_block_block },
		{ _field_legacy, _field_block, "points^", &area_sector_point_block_block },
		{ _field_legacy, _field_explanation, "Generation Properties", "" },
		{ _field_legacy, _field_enum, "preset", &generate_preset_enum },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 1 },
		{ _field_legacy, _field_pad, "pad", 2 },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 1 },
		{ _field_legacy, _field_short_integer, "runtimeCarverInversion*~!" },

		{ _field_legacy, _field_long_flags, "flags", &generate_flags },
		{ _field_legacy, _field_real, "extrusion" },
		{ _field_legacy, _field_real, "sink" },
		{ _field_legacy, _field_angle, "firing point orientation" },
		{ _field_legacy, _field_angle, "grid orientation" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 1 },
		{ _field_legacy, _field_real, "nav volume cell size" },

		{ _field_legacy, _field_real, "spacing*" },
		{ _field_legacy, _field_real, "airborne spacing*" },
		{ _field_legacy, _field_real, "min cover length*" },
		{ _field_legacy, _field_real, "cover spacing*" },
		{ _field_legacy, _field_real, "cover offset distance*" },
		{ _field_legacy, _field_real, "too close distance*" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(zone_block, k_max_zones_per_map)
	{
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_string, "name^" },
		{ _field_legacy, _field_word_flags, "flags", &zone_flags },
		{ _field_legacy, _field_short_block_index, "editor folder index!" },
		{ _field_legacy, _field_block, "firing positions", &firing_positions_block_block },
		{ _field_legacy, _field_block, "areas", &areas_block_block },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 2 }, // #TODO: commom pattern
		{ _field_legacy, _field_short_integer, "unknown" },
		{ _field_legacy, _field_short_integer, "unknown" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_legacy, _field_struct, "Nav Mesh Attachments*", &NavMeshAttachmentsStruct_struct_definition },
		{ _field_legacy, _field_struct, "disallowed attachment bsps", &manualBspFlagsReferences_struct_definition },

		{ _field_legacy, _field_terminator }
	};

	V5_TAG_ARRAY(area_cluster_occupancy_bitvector_array, ((((MAXIMUM_CLUSTERS_PER_STRUCTURE)+(k_int32_bits-1))>>k_int32_bits_bits)))
	{
		{ _field_legacy, _field_long_integer, "bitvector data!" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_STRUCT(NavMeshAttachmentsStruct)
	{
		{ _field_legacy, _field_block, "attachments", &NavMeshAttachmentBlock_block },
		{ _field_legacy, _field_terminator }
	};

	STRINGS(area_flags)
	{
		"vehicle area",
		"wall climb",
		"manual reference frame",
		"turret deployment area",
		"invalid sector def!",
		"air volume navigation",
		"generate wall climb nav mesh"
	};
	STRING_LIST(area_flags, area_flags_strings, _countof(area_flags_strings));

	STRINGS(generate_flags)
	{
		"exclude cover",
		"ignore existing",
		"generate radial",
		"don\'t stagger",
		"airborne",
		"airborne stagger",
		"continue casting"
	};
	STRING_LIST(generate_flags, generate_flags_strings, _countof(generate_flags_strings));

	STRINGS(generate_preset_enum)
	{
		"high density{dense}",
		"medium density",
		"low density{loose}",
		"high density vehicle",
		"medium density vehicle{vehicle}",
		"airborne",
		"engineer",
		"dogfight",
		"dropship",
		"orbital",
		"bishop high density",
		"bishop medium density",
		"bishop low density"
	};
	STRING_LIST(generate_preset_enum, generate_preset_enum_strings, _countof(generate_preset_enum_strings));

	STRINGS(zone_flags)
	{
		"giants zone"
	};
	STRING_LIST(zone_flags, zone_flags_strings, _countof(zone_flags_strings));

} // namespace blofeld

