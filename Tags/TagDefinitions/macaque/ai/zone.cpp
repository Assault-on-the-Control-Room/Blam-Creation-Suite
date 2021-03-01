#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define AREAS_BLOCK_STRUCT_ID { 0x65351716, 0xEEF54EC7, 0xB16396B1, 0x2F48E3D7 }
	TAG_BLOCK(
		areas_block,
		"areas_block",
		k_max_areas_per_zone,
		"area_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_WRITEABLE | TAG_MEMORY_USAGE_NON_ALIASED),
		AREAS_BLOCK_STRUCT_ID)
	{
		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 7 },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_default),
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_default),
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_default),
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_default),
		{ _field_pointer, "hkaiVolume vtable", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 | FIELD_FLAG_POINTER, _field_id_zero_data },
		{ _field_short_integer, "size", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_short_integer, "count", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },

		{ _field_string, "name", FIELD_FLAG_INDEX },
		{ _field_long_flags, "area flags", &area_flags },
		{ _field_real_point_3d, "runtime relative mean point", FIELD_FLAG_UNKNOWN0 },
		{ _field_custom_long_block_index, "packedKeyOffaceref", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_UNKNOWN3 },
		{ _field_custom_long_block_index, "navMeshUIDOffaceref", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_UNKNOWN3 },
		{ _field_real, "runtime standard deviation", FIELD_FLAG_UNKNOWN0 },
		{ _field_short_integer, "runtime starting index", FIELD_FLAG_UNKNOWN0 },
		{ _field_short_integer, "runtime count", FIELD_FLAG_UNKNOWN0 },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 2 }, // #TODO: commom pattern
		{ _field_legacy, _field_short_integer, "unknown" },
		{ _field_legacy, _field_short_integer, "unknown" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 1 },
		{ _field_struct, "Nav Mesh Attachments", FIELD_FLAG_READ_ONLY, &NavMeshAttachmentsStruct },

		{ _field_array, "cluster occupancy", FIELD_FLAG_UNKNOWN0, &area_cluster_occupancy_bitvector_array },
		{ _field_block, "flight_hints", &flight_reference_block },
		{ _field_block, "points", FIELD_FLAG_INDEX, &area_sector_point_block },
		FIELD_EXPLANATION("Generation Properties", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_enum, "preset", &generate_preset_enum, _field_id_ugpc },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 1 },
		{ _field_legacy, _field_pad, "pad", 2 },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 1 },
		{ _field_short_integer, "runtimeCarverInversion", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },

		{ _field_long_flags, "flags", &generate_flags },
		{ _field_real, "extrusion" },
		{ _field_real, "sink" },
		{ _field_angle, "firing point orientation" },
		{ _field_angle, "grid orientation" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 1 },
		{ _field_real, "nav volume cell size" },

		{ _field_real, "spacing", FIELD_FLAG_READ_ONLY },
		{ _field_real, "airborne spacing", FIELD_FLAG_READ_ONLY },
		{ _field_real, "min cover length", FIELD_FLAG_READ_ONLY },
		{ _field_real, "cover spacing", FIELD_FLAG_READ_ONLY },
		{ _field_real, "cover offset distance", FIELD_FLAG_READ_ONLY },
		{ _field_real, "too close distance", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define NAVMESHATTACHMENTBLOCK_ID { 0x2D17D937, 0x4B834305, 0x97485CEC, 0x205D022E }
	TAG_BLOCK(
		NavMeshAttachmentBlock_block,
		"NavMeshAttachmentBlock",
		MAXIMUM_STRUCTURE_BSPS_PER_SCENARIO + MAX_NUM_MOBILE_NAVMESHES,
		"long",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		NAVMESHATTACHMENTBLOCK_ID)
	{
		{ _field_dword_integer, "navMeshUID" },
		{ _field_terminator }
	};

	#define FLIGHT_REFERENCE_BLOCK_ID { 0xCB74EBB1, 0x491241BB, 0x95438C3E, 0x3B97578A }
	TAG_BLOCK(
		flight_reference_block,
		"flight_reference_block",
		k_max_flight_references_per_area,
		"flight_hint_reference",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		FLIGHT_REFERENCE_BLOCK_ID)
	{
		{ _field_short_integer, "flight hint index" },
		{ _field_short_integer, "point index" },
		{ _field_short_integer, "structure index" },
		FIELD_PAD("post-structure-index-pad", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	#define AREA_SECTOR_POINT_BLOCK_ID { 0x40B3B9F7, 0xF0C94F35, 0xB1D416B3, 0x93918A26 }
	TAG_BLOCK(
		area_sector_point_block,
		"area_sector_point_block",
		k_maximum_points_per_sector,
		"s_ai_sector_point",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_WRITEABLE),
		AREA_SECTOR_POINT_BLOCK_ID)
	{
		{ _field_real_point_3d, "point" },
		{ _field_custom_long_block_index, "packedKeyOffaceref", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_UNKNOWN3 },
		{ _field_custom_long_block_index, "navMeshUIDOffaceref", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_UNKNOWN3 },
		{ _field_real_euler_angles_2d, "normal" },
		{ _field_terminator }
	};

	#define ZONE_BLOCK_ID { 0x661CA582, 0xD7F44761, 0x8100E014, 0x147ECA8B }
	TAG_BLOCK(
		zone_block,
		"zone_block",
		k_max_zones_per_map,
		"zone_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | 
		SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		ZONE_BLOCK_ID)
	{
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_default),
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_default),
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_default),
		{ _field_string, "name", FIELD_FLAG_INDEX },
		{ _field_word_flags, "flags", &zone_flags },
		{ _field_short_block_index, "editor folder index", FIELD_FLAG_UNKNOWN0, &g_scenario_editor_folder_block, _field_id_hide },
		{ _field_block, "firing positions", &firing_positions_block },
		{ _field_block, "areas", &areas_block },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 2 }, // #TODO: commom pattern
		{ _field_legacy, _field_short_integer, "unknown" },
		{ _field_legacy, _field_short_integer, "unknown" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_struct, "Nav Mesh Attachments", FIELD_FLAG_READ_ONLY, &NavMeshAttachmentsStruct },
		{ _field_struct, "disallowed attachment bsps", &manualBspFlagsReferences },

		{ _field_terminator }
	};

	#define AREA_CLUSTER_OCCUPANCY_BITVECTOR_ARRAY_ID { 0xC8420AC3, 0x96874B81, 0x8F07ACCE, 0xEDD9DE36 }
	TAG_ARRAY(
		area_cluster_occupancy_bitvector_array,
		"area_cluster_occupancy_bitvector_array",
		((((MAXIMUM_CLUSTERS_PER_STRUCTURE)+(k_int32_bits-1))>>k_int32_bits_bits)),
		"long",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		AREA_CLUSTER_OCCUPANCY_BITVECTOR_ARRAY_ID)
	{
		{ _field_long_integer, "bitvector data", FIELD_FLAG_UNKNOWN0 },
		{ _field_terminator }
	};

	#define NAVMESHATTACHMENTSSTRUCT_ID { 0x39206AE0, 0xEC31496C, 0x8A09F9EF, 0x9A3E893B }
	TAG_STRUCT(
		NavMeshAttachmentsStruct,
		"NavMeshAttachmentsStruct",
		"NavMeshAttachment",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		NAVMESHATTACHMENTSSTRUCT_ID)
	{
		{ _field_block, "attachments", &NavMeshAttachmentBlock_block },
		{ _field_terminator }
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

} // namespace macaque

} // namespace blofeld

