#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define CACHE_FILE_RESOURCE_LAYOUT_TABLE_STRUCT_DEFINITION_ID { 0x3FC58CEB, 0x3F3647DE, 0x9126EA74, 0xF2ED0990 }
	TAG_BLOCK(
		cache_file_resource_layout_table_block,
		"cache_file_resource_layout_table_block",
		1,
		"Resources::LayoutTable",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		CACHE_FILE_RESOURCE_LAYOUT_TABLE_STRUCT_DEFINITION_ID)
	{
		{ _field_block, "codec identifiers", FIELD_FLAG_READ_ONLY, &cache_file_codec_identifier_block, _field_id_wide },
		{ _field_block, "shared files", &cache_file_shared_file_block },
		{ _field_block, "file pages", &cache_file_resource_file_page_block, _field_id_wide },
		{ _field_block, "streaming subpage tables", &cache_file_resource_streaming_subpage_table_block },

		{ _field_legacy, _field_version_platform_include, _platform_type_pc, 2 },
		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 1 },
		{ _field_legacy, _field_block, "unknown@", &g_null_block },

		{ _field_block, "sections", &cache_file_resource_section_block },
		{ _field_long_integer, "required location count" },
		{ _field_long_integer, "required dvd location count" },
		{ _field_terminator }
	};

	TAG_GROUP(
		cache_file_resource_layout_table_group,
		CACHE_FILE_RESOURCE_LAYOUT_TABLE_TAG,
		nullptr,
		INVALID_TAG,
		cache_file_resource_layout_table_block );

	#define CACHE_FILE_RESOURCE_GESTALT_STRUCT_DEFINITION_ID { 0x84D7FF6E, 0xDE544E80, 0x8139DE61, 0x36DCA9DB }
	TAG_BLOCK(
		cache_file_resource_gestalt_block,
		"cache_file_resource_gestalt_block",
		1,
		"Resources::Gestalt",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		CACHE_FILE_RESOURCE_GESTALT_STRUCT_DEFINITION_ID)
	{
		{ _field_enum, "scenario type", &scenario_type_enum },
		{ _field_word_flags, "scenario flags", &scenario_flags },
		{ _field_block, "resource type identifiers", FIELD_FLAG_READ_ONLY, &cache_file_resource_type_identifier_block, _field_id_wide },
		{ _field_block, "interop type identifiers", FIELD_FLAG_READ_ONLY, &cache_file_interop_type_identifier_block, _field_id_wide },
		{ _field_block, "codec identifiers", FIELD_FLAG_READ_ONLY, &cache_file_codec_identifier_block, _field_id_wide },
		{ _field_block, "shared files", &cache_file_shared_file_block },
		{ _field_block, "file pages", &cache_file_resource_file_page_block, _field_id_wide },
		{ _field_block, "streaming subpage tables", &cache_file_resource_streaming_subpage_table_block },

		{ _field_legacy, _field_version_platform_include, _platform_type_pc, 2 },
		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 1 },
		{ _field_legacy, _field_block, "@unknown", &g_null_block_block },

		{ _field_block, "sections", &cache_file_resource_section_block },
		{ _field_block, "resources", FIELD_FLAG_READ_ONLY, &cache_file_resource_data_block, _field_id_wide },
		{ _field_block, "designer zone manifests", FIELD_FLAG_READ_ONLY, &cache_file_designer_zone_block },
		{ _field_block, "global zone manifest", FIELD_FLAG_READ_ONLY, &cache_file_global_zone_block },
		{ _field_block, "hs zone manifest", FIELD_FLAG_READ_ONLY, &cache_file_tag_zone_block },
		{ _field_block, "unattached designer zone manifest", FIELD_FLAG_READ_ONLY, &cache_file_tag_zone_block },
		{ _field_block, "dvd forbidden zone manifest", FIELD_FLAG_READ_ONLY, &cache_file_tag_zone_block },
		{ _field_block, "dvd always streaming zone manifest", FIELD_FLAG_READ_ONLY, &cache_file_tag_zone_block },
		{ _field_block, "default bsp zone manifests", FIELD_FLAG_READ_ONLY, &cache_file_bsp_zone_block },
		{ _field_block, "static bsp zone manifests", FIELD_FLAG_READ_ONLY, &cache_file_tag_zone_block },
		{ _field_block, "dynamic bsp zone manifests", FIELD_FLAG_READ_ONLY, &cache_file_tag_zone_block },
		{ _field_block, "cinematic zone manifests", FIELD_FLAG_READ_ONLY, &cache_file_cinematic_zone_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_block, "required map variant manifests", FIELD_FLAG_READ_ONLY, &cache_file_tag_zone_block },
		{ _field_block, "sandbox map variant manifests", FIELD_FLAG_READ_ONLY, &cache_file_tag_zone_block },

		{ _field_block, "zone only zone set manifests", FIELD_FLAG_READ_ONLY, &cache_file_tag_zone_block },
		{ _field_block, "expected zone set manifests", FIELD_FLAG_READ_ONLY, &cache_file_tag_zone_block },
		{ _field_block, "fully populated zone set manifests", &cache_file_full_zone_sets_block },
		{ _field_block, "zone set zone usage", &cache_file_zone_set_zone_usage_block },
		{ _field_block, "bsp references", FIELD_FLAG_READ_ONLY, &cache_file_bsp_reference_block },
		{ _field_block, "resource owners", FIELD_FLAG_READ_ONLY, &cache_file_resource_owner_block },
		{ _field_block, "model variant usage", FIELD_FLAG_READ_ONLY, &cache_file_model_variant_usage_block },
		{ _field_block, "character usage", FIELD_FLAG_READ_ONLY, &cache_file_character_usage_block },
		{ _field_data, "naive resource control data", FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "minimum complete resource size" },
		{ _field_long_integer, "minimum required resource size" },
		{ _field_long_integer, "minimum dvd resource size" },
		{ _field_long_integer, "global required resource size", "intersection of resources amongst all zone sets" },
		{ _field_long_integer, "total optional control data size" },
		{ _field_block, "overall resource usage", FIELD_FLAG_READ_ONLY, &cache_file_tag_resource_usage_block },
		{ _field_block, "bsp game attachments", FIELD_FLAG_READ_ONLY, &cache_file_bsp_game_attachments_block },
		{ _field_block, "model variant zones", FIELD_FLAG_READ_ONLY, &debug_cache_file_model_variant_zone_block },
		{ _field_block, "combat dialogue zones", FIELD_FLAG_READ_ONLY, &debug_cache_file_combat_dialogue_zone_block },
		{ _field_block, "tag zones", FIELD_FLAG_READ_ONLY, &debug_cache_file_tag_zone_block },
		{ _field_block, "debug resource definitions", &cache_file_debug_resource_definition_block, _field_id_wide },
		{ _field_block, "resource layouts", FIELD_FLAG_READ_ONLY, &cache_file_resource_layout_block, _field_id_wide },
		{ _field_block, "resource properties", FIELD_FLAG_READ_ONLY, &cache_file_tag_resource_properties_block, _field_id_wide },
		{ _field_block, "parentages", FIELD_FLAG_READ_ONLY, &cache_file_tag_parentage_block, _field_id_wide },
		{ _field_struct, "prediction table", FIELD_FLAG_READ_ONLY, &cache_file_tag_resource_prediction_table },
		{ _field_long_integer, "Mat is in a really bad mood campaign id" },
		{ _field_long_integer, "Next time we don't put things that the game depends on outside of tool, guerilla, or sapien map id" },
		{ _field_terminator }
	};

	TAG_GROUP(
		cache_file_resource_gestalt_group,
		CACHE_FILE_RESOURCE_GESTALT_TAG,
		nullptr,
		INVALID_TAG,
		cache_file_resource_gestalt_block );

	#define CACHE_FILE_CODEC_IDENTIFIER_BLOCK_ID { 0x98BC457E, 0x5FEA4C26, 0x9C9EFCF1, 0xFB46C21F }
	TAG_BLOCK(
		cache_file_codec_identifier_block,
		"cache_file_codec_identifier_block",
		k_maximum_cache_file_codecs,
		"s_cache_file_codec_definition",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CACHE_FILE_CODEC_IDENTIFIER_BLOCK_ID)
	{
		{ _field_long_integer, "identifier part 0" },
		{ _field_long_integer, "identifier part 1" },
		{ _field_long_integer, "identifier part 2" },
		{ _field_long_integer, "identifier part 3" },
		{ _field_terminator }
	};

	#define CACHE_FILE_SHARED_FILE_BLOCK_ID { 0x13027DEC, 0xFA9E4C11, 0xBD81B8E7, 0xD68881E9 }
	TAG_BLOCK(
		cache_file_shared_file_block,
		"cache_file_shared_file_block",
		k_maximum_cache_file_shared_files,
		"s_cache_file_resource_shared_file",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CACHE_FILE_SHARED_FILE_BLOCK_ID)
	{
		{ _field_long_string, "dvd relative path", FIELD_FLAG_INDEX },
		{ _field_word_flags, "flags", &cache_file_shared_file_flags_definition },
		{ _field_short_integer, "global shared location offset" },
		{ _field_long_integer, "io offset" },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(
		cache_file_resource_file_page_block,
		"cache_file_resource_file_page_block",
		UNSIGNED_SHORT_MAX,
		cache_file_resource_page_struct);

	#define CACHE_FILE_RESOURCE_STREAMING_SUBPAGE_TABLE_BLOCK_ID { 0x41CFEA33, 0xC3564990, 0xABA22B6B, 0xF24EB390 }
	TAG_BLOCK(
		cache_file_resource_streaming_subpage_table_block,
		"cache_file_resource_streaming_subpage_table_block",
		SHORT_MAX,
		"CacheFiles::Resources::SubpageTable",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		CACHE_FILE_RESOURCE_STREAMING_SUBPAGE_TABLE_BLOCK_ID)
	{
		{ _field_long_integer, "total memory size" },
		{ _field_block, "streaming subpages", &cache_file_resource_streaming_subpage_block },
		{ _field_terminator }
	};

	#define CACHE_FILE_RESOURCE_STREAMING_SUBPAGE_BLOCK_ID { 0x184D947A, 0x728243C5, 0x8329E7B3, 0xF3FB0838 }
	TAG_BLOCK(
		cache_file_resource_streaming_subpage_block,
		"cache_file_resource_streaming_subpage_block",
		SHORT_MAX,
		"CacheFiles::Resources::Subpage",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CACHE_FILE_RESOURCE_STREAMING_SUBPAGE_BLOCK_ID)
	{
		{ _field_long_integer, "memory offset" },
		{ _field_long_integer, "memory size" },
		{ _field_terminator }
	};

	#define CACHE_FILE_RESOURCE_SECTION_BLOCK_ID { 0xE8CE3689, 0x412848DF, 0x8D98BA3D, 0x43333461 }
	TAG_BLOCK(
		cache_file_resource_section_block,
		"cache_file_resource_section_block",
		SHORT_MAX,
		"CacheFiles::Resources::Section",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CACHE_FILE_RESOURCE_SECTION_BLOCK_ID)
	{
		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_array, "page offsets", &location_offsets_array_definition_array },

		{ _field_array, "file page indexes", &file_location_indexes_array_definition_array },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_array, "page offsets", &location_offsets_array_definition_array }, // moved

		{ _field_array, "subpage table indexes", &sublocation_table_indexes_array_definition_array },
		{ _field_terminator }
	};

	#define CACHE_FILE_RESOURCE_TYPE_IDENTIFIER_BLOCK_ID { 0xA2D1A781, 0xD56446D0, 0xA06621D2, 0x648D26B3 }
	TAG_BLOCK(
		cache_file_resource_type_identifier_block,
		"cache_file_resource_type_identifier_block",
		k_maximum_cache_file_tag_resource_types,
		"s_cache_file_tag_resource_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CACHE_FILE_RESOURCE_TYPE_IDENTIFIER_BLOCK_ID)
	{
		{ _field_long_integer, "identifier part 0" },
		{ _field_long_integer, "identifier part 1" },
		{ _field_long_integer, "identifier part 2" },
		{ _field_long_integer, "identifier part 3" },
		{ _field_long_integer, "definition flags" },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 1 },
		{ _field_legacy, _field_array, "page alignment bits", &tag_resource_alignment_bits_array_definition_array },

		{ _field_string_id, "name", FIELD_FLAG_INDEX },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_array, "page alignment bits", &tag_resource_alignment_bits_array_definition_array },
		FIELD_PAD("pad0", nullptr, FIELD_FLAG_NONE, 2),

		{ _field_terminator }
	};

	#define CACHE_FILE_INTEROP_TYPE_IDENTIFIER_BLOCK_ID { 0x946946AC, 0x22F84B4A, 0x8DC4B9C6, 0xB9CDE8FE }
	TAG_BLOCK(
		cache_file_interop_type_identifier_block,
		"cache_file_interop_type_identifier_block",
		k_maximum_cache_file_tag_resource_types,
		"s_cache_file_tag_interop_definition",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CACHE_FILE_INTEROP_TYPE_IDENTIFIER_BLOCK_ID)
	{
		{ _field_long_integer, "identifier part 0" },
		{ _field_long_integer, "identifier part 1" },
		{ _field_long_integer, "identifier part 2" },
		{ _field_long_integer, "identifier part 3" },
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_terminator }
	};

	#define CACHE_FILE_RESOURCE_DATA_BLOCK_ID { 0x07EF6B5D, 0x210B4AD1, 0x9DEC2F43, 0xE9DCB6A4 }
	TAG_BLOCK(
		cache_file_resource_data_block,
		"cache_file_resource_data_block",
		SHORT_MAX,
		"Resources::ResourceData",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		CACHE_FILE_RESOURCE_DATA_BLOCK_ID)
	{
		{ _field_tag_reference, "owner tag", FIELD_FLAG_READ_ONLY | FIELD_FLAG_INDEX, &g_non_traversed_reference_definition },
		{ _field_short_integer, "resource salt" },
		{ _field_char_block_index, "resource type index", FIELD_FLAG_READ_ONLY, &cache_file_resource_type_identifier_block },
		{ _field_char_integer, "control alignment bits" },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_long_integer, "naive data offset" },

		{ _field_long_integer, "control size" },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_long_integer, "secondary control size" },

		{ _field_word_flags, "flags", &cache_file_resource_data_flags_definition },
		{ _field_short_block_index, "page", &cache_file_resource_section_block },
		{ _field_long_integer, "root fixup" },
		{ _field_block, "control fixups", &cache_file_resource_fixup_location_block },
		{ _field_block, "interop locations", &cache_file_resource_interop_location_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_block, "priority level data", &cache_file_resource_priority_data_block },

		{ _field_terminator }
	};

	#define CACHE_FILE_RESOURCE_FIXUP_LOCATION_BLOCK_ID { 0xFEA3F8F7, 0x966E4EFE, 0xBA0B07A9, 0x40C2D4EC }
	TAG_BLOCK(
		cache_file_resource_fixup_location_block,
		"cache_file_resource_fixup_location_block",
		SHORT_MAX,
		"s_tag_resource_fixup_location",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CACHE_FILE_RESOURCE_FIXUP_LOCATION_BLOCK_ID)
	{
		{ _field_long_integer, "encoded fixup location", FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "encoded fixup value", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define CACHE_FILE_RESOURCE_INTEROP_LOCATION_BLOCK_ID { 0x5A424E33, 0x52034BD5, 0xB69A55CD, 0x95A55DA9 }
	TAG_BLOCK(
		cache_file_resource_interop_location_block,
		"cache_file_resource_interop_location_block",
		SHORT_MAX,
		"s_tag_resource_interop_location",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CACHE_FILE_RESOURCE_INTEROP_LOCATION_BLOCK_ID)
	{
		{ _field_long_integer, "encoded interop location", FIELD_FLAG_READ_ONLY },
		{ _field_long_block_index, "interop type index", FIELD_FLAG_READ_ONLY | FIELD_FLAG_INDEX, &cache_file_interop_type_identifier_block },
		{ _field_terminator }
	};

	#define CACHE_FILE_RESOURCE_PRIORITY_DATA_BLOCK_ID { 0x57E10DCD, 0x09B0435D, 0x989C704E, 0xC205B3F3 }
	TAG_BLOCK(
		cache_file_resource_priority_data_block,
		"cache_file_resource_priority_data_block",
		k_numberOfResourcePriorities,
		"Resources::ResourcePriorityLevelData",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CACHE_FILE_RESOURCE_PRIORITY_DATA_BLOCK_ID)
	{
		{ _field_long_integer, "naive data offset" },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(
		cache_file_designer_zone_block,
		"cache_file_designer_zone_block",
		k_maximum_designer_zone_count,
		cache_file_tag_zone_manifest_struct);

	#define CACHE_FILE_TAG_RESOURCES_BITVECTOR_BLOCK_ID { 0xF5CB474E, 0xF51C465F, 0x9DD77EAF, 0x5070BA68 }
	TAG_BLOCK(
		cache_file_tag_resources_bitvector_block,
		"cache_file_tag_resources_bitvector_block",
		SHORT_MAX,
		"dword",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CACHE_FILE_TAG_RESOURCES_BITVECTOR_BLOCK_ID)
	{
		{ _field_long_integer, "32 bits" },
		{ _field_terminator }
	};

	#define CACHE_FILE_TAG_RESOURCE_USAGE_BLOCK_STRUCT_ID { 0x7E3FC27D, 0x0B104D30, 0xBE6C359D, 0xBB4988CB }
	TAG_BLOCK(
		cache_file_tag_resource_usage_block,
		"cache_file_tag_resource_usage_block",
		k_maximum_cache_file_tag_resource_types,
		"s_cache_file_zone_resource_usage",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CACHE_FILE_TAG_RESOURCE_USAGE_BLOCK_STRUCT_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_array, "page sizes", &resource_usage_page_size_array_definition_array },
		{ _field_long_integer, "deferred required size" },
		{ _field_long_integer, "streamed resource size" },
		{ _field_long_integer, "dvd in-memory resource size" },
		{ _field_terminator }
	};

	#define CACHE_FILE_ZONE_RESOURCE_VISIT_NODE_BLOCK_STRUCT_ID { 0x17C375BA, 0xE7B7481F, 0xAF7D1577, 0xFAC6CD4A }
	TAG_BLOCK(
		cache_file_zone_resource_visit_node_block,
		"cache_file_zone_resource_visit_node_block",
		SHORT_MAX,
		"s_cache_file_zone_resource_visit_node",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_UNKNOWN19,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		CACHE_FILE_ZONE_RESOURCE_VISIT_NODE_BLOCK_STRUCT_ID)
	{
		{ _field_short_block_index, "parent tag", FIELD_FLAG_INDEX, &cache_file_resource_owner_block },
		FIELD_PAD("sdfasfas", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_block, "children", &cache_file_zone_resource_visit_node_link_block },
		{ _field_terminator }
	};

	#define CACHE_FILE_RESOURCE_OWNER_BLOCK_ID { 0xEEF8F43D, 0x5D8249C7, 0x8CD02DD1, 0x34A61C28 }
	TAG_BLOCK(
		cache_file_resource_owner_block,
		"cache_file_resource_owner_block",
		SHORT_MAX,
		"s_cache_file_tag_instance_reference",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CACHE_FILE_RESOURCE_OWNER_BLOCK_ID)
	{
		{ _field_tag_reference, "resource owner", FIELD_FLAG_INDEX, &g_non_traversed_reference_definition },
		{ _field_long_integer, "actual tag index", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define CACHE_FILE_ZONE_RESOURCE_VISIT_NODE_LINK_BLOCK_ID { 0x22319003, 0x8D884426, 0xAF2ED443, 0xE9B58033 }
	TAG_BLOCK(
		cache_file_zone_resource_visit_node_link_block,
		"cache_file_zone_resource_visit_node_link_block",
		SHORT_MAX,
		"short",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CACHE_FILE_ZONE_RESOURCE_VISIT_NODE_LINK_BLOCK_ID)
	{
		{ _field_short_block_index, "child tag", FIELD_FLAG_INDEX, &cache_file_zone_resource_visit_node_block },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(
		cache_file_global_zone_block,
		"cache_file_global_zone_block",
		1,
		cache_file_tag_zone_manifest_struct);

	TAG_BLOCK_FROM_STRUCT(
		cache_file_tag_zone_block,
		"cache_file_tag_zone_block",
		SHORT_MAX,
		cache_file_tag_zone_manifest_struct);

	TAG_BLOCK_FROM_STRUCT(
		cache_file_bsp_zone_block,
		"cache_file_bsp_zone_block",
		MAXIMUM_STRUCTURE_BSPS_PER_SCENARIO,
		cache_file_tag_zone_manifest_struct);

	TAG_BLOCK_FROM_STRUCT(
		cache_file_cinematic_zone_block,
		"cache_file_cinematic_zone_block",
		MAXIMUM_SCENARIO_CINEMATICS,
		cache_file_tag_zone_manifest_struct);

	TAG_BLOCK_FROM_STRUCT(
		cache_file_full_zone_sets_block,
		"cache_file_full_zone_sets_block",
		k_maximum_scenario_zone_set_count,
		cache_file_tag_zone_manifest_struct);

	#define CACHE_FILE_ZONE_SET_ZONE_USAGE_BLOCK_ID { 0xFA90B323, 0xCE6D4D2B, 0xA8722EA8, 0xB3830975 }
	TAG_BLOCK(
		cache_file_zone_set_zone_usage_block,
		"cache_file_zone_set_zone_usage_block",
		k_maximum_scenario_zone_set_count,
		"s_cache_file_zone_set_zone_usage",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CACHE_FILE_ZONE_SET_ZONE_USAGE_BLOCK_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_long_flags, "flags", &scenario_zone_set_flags_definition },
		{ _field_long_block_flags, "required bsp zones", &cache_file_bsp_zone_block },
		{ _field_long_block_flags, "expected touched bsp zones", &cache_file_bsp_zone_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_qword_integer, "required designer zones" }, // #NOTE: 64bit block flags
		{ _field_qword_integer, "expected designer zones" }, // #NOTE: 64bit block flags

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 3 },
		{ _field_legacy, _field_long_block_flags, "required designer zones" },
		{ _field_legacy, _field_long_block_flags, "expected designer zones" },
		{ _field_legacy, _field_long_block_flags, "expected designer zones (inverted)" }, // #NOTE: named from observation of data

		{ _field_long_block_flags, "required cinematic zones", &cache_file_cinematic_zone_block },
		{ _field_long_block_index, "hint previous zone set", &cache_file_zone_set_zone_usage_block },
		{ _field_terminator }
	};

	#define CACHE_FILE_BSP_REFERENCE_BLOCK_ID { 0x84874E4D, 0xDBA4456E, 0x8BC8229B, 0xA6B4A90D }
	TAG_BLOCK(
		cache_file_bsp_reference_block,
		"cache_file_bsp_reference_block",
		MAXIMUM_STRUCTURE_BSPS_PER_SCENARIO,
		"s_tag_reference",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CACHE_FILE_BSP_REFERENCE_BLOCK_ID)
	{
		{ _field_tag_reference, "bsp", FIELD_FLAG_INDEX, &g_non_traversed_reference_definition },
		{ _field_terminator }
	};

	#define CACHE_FILE_MODEL_VARIANT_USAGE_BLOCK_ID { 0x2321AB6C, 0xB74547EF, 0x8B8E12EA, 0x7D729350 }
	TAG_BLOCK(
		cache_file_model_variant_usage_block,
		"cache_file_model_variant_usage_block",
		SHORT_MAX,
		"s_cache_file_model_variant_usage",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		CACHE_FILE_MODEL_VARIANT_USAGE_BLOCK_ID)
	{
		{ _field_short_block_index, "model", FIELD_FLAG_INDEX, &cache_file_resource_owner_block },
		FIELD_PAD("sdfasfas", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_string_id, "variant" },
		{ _field_block, "used materials", &cache_file_resource_owner_reference_block },
		{ _field_terminator }
	};

	#define CACHE_FILE_RESOURCE_OWNER_REFERENCE_BLOCK_ID { 0x182CCAC9, 0x87284EE2, 0xA12E1B0F, 0xEEAE5B58 }
	TAG_BLOCK(
		cache_file_resource_owner_reference_block,
		"cache_file_resource_owner_reference_block",
		SHORT_MAX,
		"short",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CACHE_FILE_RESOURCE_OWNER_REFERENCE_BLOCK_ID)
	{
		{ _field_short_block_index, "tag", FIELD_FLAG_INDEX, &cache_file_resource_owner_block },
		{ _field_terminator }
	};

	#define CACHE_FILE_CHARACTER_USAGE_BLOCK_ID { 0x7DCD4D50, 0xCCC04A10, 0xA5187197, 0xDCC31708 }
	TAG_BLOCK(
		cache_file_character_usage_block,
		"cache_file_character_usage_block",
		SHORT_MAX,
		"s_cache_file_character_usage",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		CACHE_FILE_CHARACTER_USAGE_BLOCK_ID)
	{
		{ _field_short_block_index, "model", FIELD_FLAG_INDEX, &cache_file_resource_owner_block },
		FIELD_PAD("sdfasfas", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_block, "used model variants", &cache_file_model_variant_usage_reference_block },
		{ _field_terminator }
	};

	#define CACHE_FILE_MODEL_VARIANT_USAGE_REFERENCE_BLOCK_ID { 0x48A5C4F6, 0x17C44C21, 0x8BB1975C, 0x887DC11F }
	TAG_BLOCK(
		cache_file_model_variant_usage_reference_block,
		"cache_file_model_variant_usage_reference_block",
		SHORT_MAX,
		"short",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CACHE_FILE_MODEL_VARIANT_USAGE_REFERENCE_BLOCK_ID)
	{
		{ _field_short_block_index, "model variant", FIELD_FLAG_INDEX, &cache_file_model_variant_usage_block },
		{ _field_terminator }
	};

	#define CACHE_FILE_BSP_GAME_ATTACHMENTS_BLOCK_STRUCT_ID { 0xE0BB848D, 0xE4CB4E34, 0x80F3985E, 0x09450C40 }
	TAG_BLOCK(
		cache_file_bsp_game_attachments_block,
		"cache_file_bsp_game_attachments_block",
		MAXIMUM_STRUCTURE_BSPS_PER_SCENARIO,
		"s_cache_file_bsp_game_attachments",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		CACHE_FILE_BSP_GAME_ATTACHMENTS_BLOCK_STRUCT_ID)
	{
		{ _field_block, "static", &cache_file_bsp_attachment_block },
		{ _field_block, "persistent", &cache_file_bsp_attachment_block },
		{ _field_block, "dynamic", &cache_file_bsp_attachment_block },
		{ _field_terminator }
	};

	#define CACHE_FILE_BSP_ATTACHMENT_BLOCK_ID { 0x8A7031E2, 0xC4C94AC7, 0x89C74C82, 0xC996E277 }
	TAG_BLOCK(
		cache_file_bsp_attachment_block,
		"cache_file_bsp_attachment_block",
		SHORT_MAX,
		"s_cache_file_bsp_attachment",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CACHE_FILE_BSP_ATTACHMENT_BLOCK_ID)
	{
		{ _field_tag_reference, "attachment", FIELD_FLAG_INDEX, &g_non_traversed_reference_definition },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(
		debug_cache_file_model_variant_zone_block,
		"debug_cache_file_model_variant_zone_block",
		k_maximum_simultaneous_tag_instances,
		debug_cache_file_zone_manifest_struct);

	TAG_BLOCK_FROM_STRUCT(
		debug_cache_file_combat_dialogue_zone_block,
		"debug_cache_file_combat_dialogue_zone_block",
		k_maximum_simultaneous_tag_instances,
		debug_cache_file_zone_manifest_struct);

	TAG_BLOCK_FROM_STRUCT(
		debug_cache_file_tag_zone_block,
		"debug_cache_file_tag_zone_block",
		k_maximum_simultaneous_tag_instances,
		debug_cache_file_zone_manifest_struct);

	#define CACHE_FILE_DEBUG_RESOURCE_DEFINITION_BLOCK_ID { 0x6D56BE92, 0xE91F4C91, 0x901F2870, 0xADDF2F38 }
	TAG_BLOCK(
		cache_file_debug_resource_definition_block,
		"cache_file_debug_resource_definition_block",
		k_maximum_cache_file_tag_resource_types,
		"s_cache_file_debug_tag_resource_defintion",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		CACHE_FILE_DEBUG_RESOURCE_DEFINITION_BLOCK_ID)
	{
		{ _field_block, "categories", &resource_category_block },
		{ _field_terminator }
	};

	#define RESOURCE_CATEGORY_BLOCK_ID { 0xC450B05F, 0xDFCD4840, 0xAED5D08F, 0x1D23AEB7 }
	TAG_BLOCK(
		resource_category_block,
		"resource_category_block",
		k_maximum_categories_per_resource,
		"string_id",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		RESOURCE_CATEGORY_BLOCK_ID)
	{
		{ _field_string_id, "name" },
		{ _field_terminator }
	};

	#define CACHE_FILE_RESOURCE_LAYOUT_BLOCK_STRUCT_ID { 0xAF086415, 0x9CB7429E, 0xB4D397A6, 0x0AD19864 }
	TAG_BLOCK(
		cache_file_resource_layout_block,
		"cache_file_resource_layout_block",
		SHORT_MAX,
		"s_cache_file_tag_resource_layout",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_UNKNOWN15 | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CACHE_FILE_RESOURCE_LAYOUT_BLOCK_STRUCT_ID)
	{
		{ _field_array, "memory sizes", &resource_layout_memory_size_array_definition_array },
		{ _field_array, "compressed sizes", &resource_layout_compressed_size_array_definition_array },
		{ _field_long_integer, "deferred required resource size" },
		{ _field_long_integer, "unused resource size" },
		{ _field_word_flags, "global zone attachment", &cache_file_resource_global_zone_attachment_flags },
		FIELD_PAD("global-zone-attachment-pad", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_long_block_flags, "bsp zone attachment", &cache_file_bsp_zone_block },
		{ _field_qword_integer, "designer zone attachment" },
		{ _field_long_block_flags, "cinematic zone attachment", &cache_file_cinematic_zone_block },
		FIELD_PAD("64 bit alignment pad", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_terminator }
	};

	#define CACHE_FILE_TAG_RESOURCE_PROPERTIES_BLOCK_ID { 0x884D15C8, 0x1E404784, 0xB1E4362C, 0x2E44E7E3 }
	TAG_BLOCK(
		cache_file_tag_resource_properties_block,
		"cache_file_tag_resource_properties_block",
		SHORT_MAX,
		"s_cache_file_tag_resource_properties",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		CACHE_FILE_TAG_RESOURCE_PROPERTIES_BLOCK_ID)
	{
		{ _field_block, "named values", &cache_file_tag_resource_named_value_block },
		{ _field_terminator }
	};

	#define CACHE_FILE_TAG_RESOURCE_NAMED_VALUE_BLOCK_ID { 0xE15017A2, 0xAB51458E, 0xB4ADB126, 0x18477B8E }
	TAG_BLOCK(
		cache_file_tag_resource_named_value_block,
		"cache_file_tag_resource_named_value_block",
		k_maximum_categories_per_resource*k_maximum_category_rows_per_resource,
		"s_cache_file_tag_resource_named_value",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CACHE_FILE_TAG_RESOURCE_NAMED_VALUE_BLOCK_ID)
	{
		{ _field_string_id, "name" },
		{ _field_long_enum, "type", &named_value_type_enum },
		{ _field_long_integer, "row" },
		{ _field_string_id, "string value" },
		{ _field_real, "real value" },
		{ _field_long_integer, "int value" },
		{ _field_terminator }
	};

	#define CACHE_FILE_TAG_PARENTAGE_BLOCK_STRUCT_ID { 0x30B9A8D9, 0x80FD41FD, 0xBE990CAA, 0x8CF7F824 }
	TAG_BLOCK(
		cache_file_tag_parentage_block,
		"cache_file_tag_parentage_block",
		k_maximum_tag_parentages_count,
		"s_cache_file_tag_parentage",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		CACHE_FILE_TAG_PARENTAGE_BLOCK_STRUCT_ID)
	{
		{ _field_tag_reference, "tag", &g_non_traversed_reference_definition },
		{ _field_word_flags, "flags", &cache_file_tag_parentage_flags_definition },
		{ _field_short_integer, "resource owner index" },
		{ _field_block, "parents", &cache_file_tag_parentage_reference_block, _field_id_wide },
		{ _field_block, "children", &cache_file_tag_parentage_reference_block, _field_id_wide },
		{ _field_terminator }
	};

	#define CACHE_FILE_TAG_PARENTAGE_REFERENCE_BLOCK_ID { 0xC273771E, 0x99C645BA, 0xB30E3EC4, 0x968468FB }
	TAG_BLOCK(
		cache_file_tag_parentage_reference_block,
		"cache_file_tag_parentage_reference_block",
		k_maximum_tag_parentages_count,
		"long",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CACHE_FILE_TAG_PARENTAGE_REFERENCE_BLOCK_ID)
	{
		{ _field_long_block_index, "link", FIELD_FLAG_INDEX, &cache_file_tag_parentage_block },
		{ _field_terminator }
	};

	#define CACHE_FILE_TAG_RESOURCE_PREDICTION_QUANTUM_BLOCK_ID { 0xB0C3E6A3, 0x6B6C44A1, 0x9C87B72D, 0xEF8EF158 }
	TAG_BLOCK(
		cache_file_tag_resource_prediction_quantum_block,
		"cache_file_tag_resource_prediction_quantum_block",
		60*k_kilo,
		"s_tag_resource_prediction_quantum",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CACHE_FILE_TAG_RESOURCE_PREDICTION_QUANTUM_BLOCK_ID)
	{
		{ _field_long_integer, "internal resource handle" },
		{ _field_terminator }
	};

	#define CACHE_FILE_TAG_RESOURCE_PREDICTION_ATOM_BLOCK_ID { 0xD4DF8812, 0xE9CC40B4, 0x83EC0650, 0x0C2C8AC6 }
	TAG_BLOCK(
		cache_file_tag_resource_prediction_atom_block,
		"cache_file_tag_resource_prediction_atom_block",
		k_maximum_simultaneous_tag_instances,
		"s_tag_resource_prediction_atom",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CACHE_FILE_TAG_RESOURCE_PREDICTION_ATOM_BLOCK_ID)
	{
		{ _field_short_integer, "index salt" },
		{ _field_word_integer, "prediction quantum count" },
		{ _field_long_block_index, "first prediction quantum index", &cache_file_tag_resource_prediction_quantum_block },
		{ _field_terminator }
	};

	#define CACHE_FILE_TAG_RESOURCE_PREDICTION_MOLECULE_ATOM_REFERENCE_BLOCK_ID { 0xF49C2052, 0xC3B94427, 0xB175D8B8, 0x44EC4F73 }
	TAG_BLOCK(
		cache_file_tag_resource_prediction_molecule_atom_reference_block,
		"cache_file_tag_resource_prediction_molecule_atom_reference_block",
		SHORT_MAX,
		"long",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CACHE_FILE_TAG_RESOURCE_PREDICTION_MOLECULE_ATOM_REFERENCE_BLOCK_ID)
	{
		{ _field_long_integer, "prediction atom handle" },
		{ _field_terminator }
	};

	#define CACHE_FILE_TAG_RESOURCE_PREDICTION_MOLECULE_BLOCK_ID { 0x335E8A1B, 0x745046FF, 0xA6B7B810, 0xC0F7C4B7 }
	TAG_BLOCK(
		cache_file_tag_resource_prediction_molecule_block,
		"cache_file_tag_resource_prediction_molecule_block",
		SHORT_MAX,
		"s_tag_resource_prediction_molecule",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CACHE_FILE_TAG_RESOURCE_PREDICTION_MOLECULE_BLOCK_ID)
	{
		{ _field_word_integer, "prediction atom count" },
		{ _field_short_block_index, "first prediction atom index", &cache_file_tag_resource_prediction_atom_block },
		{ _field_word_integer, "prediction quantum count" },
		{ _field_word_integer, "first prediction quantum index" },
		{ _field_terminator }
	};

	#define CACHE_FILE_TAG_RESOURCE_PREDICTION_MOLECULE_KEYS_BLOCK_ID { 0xB205AA17, 0xED834796, 0xB4669D18, 0x47F86845 }
	TAG_BLOCK(
		cache_file_tag_resource_prediction_molecule_keys_block,
		"cache_file_tag_resource_prediction_molecule_keys_block",
		c_tag_resource_prediction_table_base::k_maximum_mapped_molecules,
		"s_tag_resource_prediction_molecule_key",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CACHE_FILE_TAG_RESOURCE_PREDICTION_MOLECULE_KEYS_BLOCK_ID)
	{
		{ _field_long_integer, "index a" },
		{ _field_long_integer, "index b" },
		{ _field_long_integer, "index c" },
		{ _field_terminator }
	};

	#define RESOURCE_HASH_DEFINITION_ID { 0xF713F8B8, 0xA3FB4157, 0x956953B8, 0x16833EDB }
	TAG_ARRAY(
		resource_hash_definition_array,
		"resource_hash_definition",
		k_hash_size,
		"byte",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		RESOURCE_HASH_DEFINITION_ID)
	{
		{ _field_byte_integer, "hash byte" },
		{ _field_terminator }
	};

	#define LOCATION_OFFSETS_ARRAY_DEFINITION_ID { 0x18557C2E, 0x60C811E0, 0xA9F9FD26, 0xE0D72085 }
	TAG_ARRAY(
		location_offsets_array_definition_array,
		"location_offsets_array_definition",
		k_numberOfResourcePriorities,
		"dword",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		LOCATION_OFFSETS_ARRAY_DEFINITION_ID)
	{
		{ _field_long_integer, "offset" },
		{ _field_terminator }
	};

	#define FILE_LOCATION_INDEXES_ARRAY_DEFINITION_ID { 0x955AB4BE, 0x60C811E0, 0x86CB7C27, 0xE0D72085 }
	TAG_ARRAY(
		file_location_indexes_array_definition_array,
		"file_location_indexes_array_definition",
		k_numberOfResourcePriorities,
		"word",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		FILE_LOCATION_INDEXES_ARRAY_DEFINITION_ID)
	{
		{ _field_short_block_index, "page index", &cache_file_resource_file_page_block },
		{ _field_terminator }
	};

	#define SUBLOCATION_TABLE_INDEXES_ARRAY_DEFINITION_ID { 0xB3E03FAA, 0x04D94FCF, 0xA6602684, 0xA733B0FA }
	TAG_ARRAY(
		sublocation_table_indexes_array_definition_array,
		"sublocation_table_indexes_array_definition",
		k_numberOfResourcePriorities,
		"word",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SUBLOCATION_TABLE_INDEXES_ARRAY_DEFINITION_ID)
	{
		{ _field_short_block_index, "subpage table index", &cache_file_resource_file_page_block },
		{ _field_terminator }
	};

	#define TAG_RESOURCE_ALIGNMENT_BITS_ARRAY_DEFINITION_ID { 0x105858F0, 0xA65043AA, 0x8F0EE066, 0x4222491A }
	TAG_ARRAY(
		tag_resource_alignment_bits_array_definition_array,
		"tag_resource_alignment_bits_array_definition",
		k_numberOfResourcePriorities,
		"word",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		TAG_RESOURCE_ALIGNMENT_BITS_ARRAY_DEFINITION_ID)
	{
		{ _field_short_integer, "page alignment bits" },
		{ _field_terminator }
	};

	#define RESOURCE_USAGE_PAGE_SIZE_ARRAY_DEFINITION_ID { 0x75BD02C0, 0xF0BA48F9, 0x851711E4, 0xDB4626C6 }
	TAG_ARRAY(
		resource_usage_page_size_array_definition_array,
		"resource_usage_page_size_array_definition",
		k_numberOfResourcePriorities,
		"dword",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		RESOURCE_USAGE_PAGE_SIZE_ARRAY_DEFINITION_ID)
	{
		{ _field_long_integer, "page size" },
		{ _field_terminator }
	};

	#define RESOURCE_LAYOUT_MEMORY_SIZE_ARRAY_DEFINITION_ID { 0xBF77779F, 0xBE234452, 0xB2A3C7EC, 0xF73AFF38 }
	TAG_ARRAY(
		resource_layout_memory_size_array_definition_array,
		"resource_layout_memory_size_array_definition",
		k_numberOfResourcePriorities,
		"dword",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		RESOURCE_LAYOUT_MEMORY_SIZE_ARRAY_DEFINITION_ID)
	{
		{ _field_long_integer, "memory size" },
		{ _field_terminator }
	};

	#define RESOURCE_LAYOUT_COMPRESSED_SIZE_ARRAY_DEFINITION_ID { 0x48483D04, 0x07DB4B74, 0xAA4B1292, 0xCC40B002 }
	TAG_ARRAY(
		resource_layout_compressed_size_array_definition_array,
		"resource_layout_compressed_size_array_definition",
		k_numberOfResourcePriorities,
		"dword",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		RESOURCE_LAYOUT_COMPRESSED_SIZE_ARRAY_DEFINITION_ID)
	{
		{ _field_long_integer, "compressed size" },
		{ _field_terminator }
	};

	#define CACHE_FILE_RESOURCE_PAGE_STRUCT_ID { 0xA82CDAB9, 0xAF1B4171, 0x816BA199, 0xDD8E6C9C }
	TAG_STRUCT(
		cache_file_resource_page_struct,
		"cache_file_resource_page_struct",
		"CacheFiles::Resources::FilePage",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CACHE_FILE_RESOURCE_PAGE_STRUCT_ID)
	{
		{ _field_short_integer, "header salt at runtime" },
		{ _field_byte_flags, "flags", &cache_file_tag_resource_page_flags },
		{ _field_char_block_index, "codec", &cache_file_codec_identifier_block },
		{ _field_short_block_index, "shared file", FIELD_FLAG_INDEX, &cache_file_shared_file_block },
		{ _field_short_integer, "shared file location index" },
		{ _field_long_integer, "file offset" },
		{ _field_long_integer, "file size" },
		{ _field_long_integer, "size" },
		{ _field_struct, "checksum", &resource_checksum_struct },
		{ _field_short_integer, "resource reference count" },
		{ _field_short_block_index, "streaming subpage table", &cache_file_resource_streaming_subpage_table_block },
		{ _field_terminator }
	};

	#define RESOURCE_CHECKSUM_STRUCT_ID { 0x6DA6A4F0, 0x19C443F8, 0x8B233E7F, 0xE4FB0736 }
	TAG_STRUCT(
		resource_checksum_struct,
		"resource_checksum_struct",
		"s_cache_file_resource_checksum",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		RESOURCE_CHECKSUM_STRUCT_ID)
	{
		{ _field_long_integer, "checksum" },
		{ _field_array, "entire hash", &resource_hash_definition_array },
		{ _field_array, "first chunk hash", &resource_hash_definition_array },
		{ _field_array, "last chunk hash", &resource_hash_definition_array },
		{ _field_terminator }
	};

	#define CACHE_FILE_TAG_ZONE_MANIFEST_STRUCT_ID { 0x97526DBD, 0x0D3046F2, 0x846E0460, 0xDADC74B2 }
	TAG_STRUCT(
		cache_file_tag_zone_manifest_struct,
		"cache_file_tag_zone_manifest_struct",
		"s_cache_file_zone_manifest",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		CACHE_FILE_TAG_ZONE_MANIFEST_STRUCT_ID)
	{
		{ _field_block, "cached resource bitvector", &cache_file_tag_resources_bitvector_block },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_block, "unknown resource bitvector", &cache_file_tag_resources_bitvector_block },

		{ _field_block, "streamed resource bitvector", &cache_file_tag_resources_bitvector_block },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_block, "unknown resource bitvector", &cache_file_tag_resources_bitvector_block },

		{ _field_string_id, "name", FIELD_FLAG_INDEX },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_array, "page sizes", &resource_usage_page_size_array_definition_array },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 2 }, // this needs to be setup properly as a _field_array with a count of 2
		{  _field_long_integer, "page sizes" },
		{  _field_long_integer, "page sizes" },

		{ _field_long_integer, "deferred required size" },
		{ _field_long_integer, "streamed resource size" },
		{ _field_long_integer, "dvd in-memory resource size" },
		{ _field_block, "resource usage", &cache_file_tag_resource_usage_block },
		{ _field_block, "budget usage", &cache_file_tag_resource_usage_block },
		{ _field_block, "unique budget usage", &cache_file_tag_resource_usage_block },
		{ _field_block, "active resource owners", &cache_file_tag_resources_bitvector_block },
		{ _field_block, "top level resource owners", &cache_file_tag_resources_bitvector_block },
		{ _field_block, "visitation hierarchy", &cache_file_zone_resource_visit_node_block },
		{ _field_long_integer, "active bsp mask", FIELD_FLAG_UNKNOWN0 },
		{ _field_long_integer, "touched bsp mask", FIELD_FLAG_UNKNOWN0 },
		{ _field_long_integer, "cinematic zone mask", FIELD_FLAG_UNKNOWN0 },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_qword_integer, "designer zone mask", FIELD_FLAG_UNKNOWN0 },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach }, // fuck formating because upgrade.exe
		{ _field_long_integer, "designer zone mask", FIELD_FLAG_UNKNOWN0 },

		{ _field_terminator }
	};

	#define DEBUG_CACHE_FILE_ZONE_MANIFEST_STRUCT_ID { 0x4E4AC3CD, 0x598D4EFC, 0xAD44DA5D, 0xEA3DA8F0 }
	TAG_STRUCT(
		debug_cache_file_zone_manifest_struct,
		"debug_cache_file_zone_manifest_struct",
		"s_debug_tag_cache_file_zone_manifest",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		DEBUG_CACHE_FILE_ZONE_MANIFEST_STRUCT_ID)
	{
		{ _field_struct, "cache zone manifest", &cache_file_tag_zone_manifest_struct },
		{ _field_long_integer, "disk size" },
		{ _field_long_integer, "unused size" },
		{ _field_tag_reference, "owner tag", FIELD_FLAG_INDEX, &g_non_traversed_reference_definition },
		{ _field_terminator }
	};

	#define CACHE_FILE_TAG_RESOURCE_PREDICTION_TABLE_ID { 0x8AC05042, 0xF5CF4649, 0x91F59F02, 0xC1CF8172 }
	TAG_STRUCT(
		cache_file_tag_resource_prediction_table,
		"cache_file_tag_resource_prediction_table",
		"s_cache_file_resource_prediction_table",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		CACHE_FILE_TAG_RESOURCE_PREDICTION_TABLE_ID)
	{
		{ _field_block, "prediction quanta", &cache_file_tag_resource_prediction_quantum_block },
		{ _field_block, "prediction atoms", &cache_file_tag_resource_prediction_atom_block },
		{ _field_block, "prediction molecule atoms", &cache_file_tag_resource_prediction_molecule_atom_reference_block },
		{ _field_block, "prediction molecules", &cache_file_tag_resource_prediction_molecule_block },
		{ _field_block, "prediction molecule keys", &cache_file_tag_resource_prediction_molecule_keys_block },
		{ _field_terminator }
	};

	STRINGS(cache_file_shared_file_flags_definition)
	{
		"use header io offset",
		"not required",
		"use header locations"
	};
	STRING_LIST(cache_file_shared_file_flags_definition, cache_file_shared_file_flags_definition_strings, _countof(cache_file_shared_file_flags_definition_strings));

	STRINGS(cache_file_tag_resource_page_flags)
	{
		"valid checksum",
		"shared and required",
		"dvd only shared and required",
		"dvd only and required",
		"referenced by cache file header",
		"only full valid checksum"
	};
	STRING_LIST(cache_file_tag_resource_page_flags, cache_file_tag_resource_page_flags_strings, _countof(cache_file_tag_resource_page_flags_strings));

	STRINGS(cache_file_resource_data_flags_definition)
	{
		"has highest priority data",
		"has medium priority data",
		"has low priority data"
	};
	STRING_LIST(cache_file_resource_data_flags_definition, cache_file_resource_data_flags_definition_strings, _countof(cache_file_resource_data_flags_definition_strings));

	STRINGS(cache_file_resource_global_zone_attachment_flags)
	{
		"global",
		"script",
		"hdd only",
		"always streaming",
		"unattached"
	};
	STRING_LIST(cache_file_resource_global_zone_attachment_flags, cache_file_resource_global_zone_attachment_flags_strings, _countof(cache_file_resource_global_zone_attachment_flags_strings));

	STRINGS(named_value_type_enum)
	{
		"unknown",
		"string",
		"real",
		"int"
	};
	STRING_LIST(named_value_type_enum, named_value_type_enum_strings, _countof(named_value_type_enum_strings));

	STRINGS(cache_file_tag_parentage_flags_definition)
	{
		"loaded by game",
		"unloaded"
	};
	STRING_LIST(cache_file_tag_parentage_flags_definition, cache_file_tag_parentage_flags_definition_strings, _countof(cache_file_tag_parentage_flags_definition_strings));

} // namespace macaque

} // namespace blofeld

