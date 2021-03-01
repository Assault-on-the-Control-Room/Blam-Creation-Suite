#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{
	V5_TAG_STRUCT(render_model_unknown_sky_struct2)
	{
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_STRUCT(render_model_unknown_struct)
	{
		{ _field_legacy, _field_block, "sky light unknown", &g_null_block },
		{ _field_legacy, _field_struct, "sh sky red", &render_model_unknown_sky_struct2_struct_definition },
		{ _field_legacy, _field_struct, "sh sky green", &render_model_unknown_sky_struct2_struct_definition },
		{ _field_legacy, _field_struct, "sh sky blue", &render_model_unknown_sky_struct2_struct_definition },
		{ _field_legacy, _field_struct, "sh sky alpha", &render_model_unknown_sky_struct2_struct_definition },
		{ _field_legacy, _field_real_point_3d, "sky light levels#Negative for the opposite direction" },
		{ _field_legacy, _field_real_rgb_color, "sky light color" },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_real, "unknown" }, // #TODO: Test these values
		{ _field_legacy, _field_terminator }
	};

	TAG_GROUP(
		imposter_model_group,
		IMPOSTER_MODEL_TAG,
		nullptr,
		INVALID_TAG,
		imposter_model_block );

	#define RENDER_MODEL_STRUCT_DEFINITION_ID { 0x69FF7DC3, 0x07F94EB6, 0xA4788DFF, 0xBBF9621C }
	TAG_BLOCK(
		render_model_block,
		"render_model_block",
		1,
		"render_model_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_RESOURCES | 
		SET_UNKNOWN14 | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		RENDER_MODEL_STRUCT_DEFINITION_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_READ_ONLY },
		{ _field_word_flags, "flags", FIELD_FLAG_READ_ONLY, &render_model_flags_definition },
		{ _field_word_integer, "version", FIELD_FLAG_UNKNOWN0 },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_unknown_checksum_begin),
		{ _field_long_integer, "runtime import info checksum", FIELD_FLAG_UNKNOWN0 },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_unknown_checksum_end),
		{ _field_block, "regions", FIELD_FLAG_READ_ONLY, &render_model_region_block, _field_id_slap },
		{ _field_char_integer, "L1 section group index", nullptr, "(low)", FIELD_FLAG_READ_ONLY },
		{ _field_char_integer, "L2 section group index", nullptr, "(high)", FIELD_FLAG_READ_ONLY },
		FIELD_PAD("PUJJ", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_long_block_index, "instance mesh index", FIELD_FLAG_READ_ONLY, &global_mesh_block },
		{ _field_block, "instance placements", &global_render_model_instance_placement_block, _field_id_slap },
		{ _field_long_integer, "node list checksum", FIELD_FLAG_READ_ONLY },
		{ _field_block, "nodes", FIELD_FLAG_READ_ONLY, &render_model_node_block, _field_id_slap },
		{ _field_block, "marker groups", FIELD_FLAG_READ_ONLY, &render_model_marker_group_block, _field_id_slap },
		{ _field_block, "materials", &global_geometry_material_block, _field_id_slap },
		{ _field_block, "errors", FIELD_FLAG_READ_ONLY, &global_error_report_categories_block, _field_id_slap },
		{ _field_real, "don't draw over camera cosine angle", "dont draw fp model when camera > this angle cosine (-1,1) Sugg. -0.2. 0 disables." },
		{ _field_struct, "render geometry", FIELD_FLAG_READ_ONLY, &global_render_geometry_struct },
		{ _field_block, "node map mapping", FIELD_FLAG_READ_ONLY, &instance_node_map_mapping_block, _field_id_slap },

		{ _field_legacy, _field_version_less_or_equal , _engine_type_haloreach },
		{ _field_legacy, _field_struct, "unknown", &render_model_unknown_struct_struct_definition },

		{ _field_block, "volume samples", &volume_samples_block, _field_id_slap },
		{ _field_block, "runtime node orientations", FIELD_FLAG_UNKNOWN0, &default_node_orientations_block, _field_id_slap },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 5 },
		{ _field_block, "bone groups", &RenderModelBoneGroupBlock_block, _field_id_slap },
		FIELD_EXPLANATION("Static Lightmap", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_tag_reference, "structure meta data", FIELD_FLAG_READ_ONLY, &Tag::Reference<struct StructureMetadata>::s_defaultDefinition },
		{ _field_tag_reference, "lightmap bsp data reference", &scenario_lightmap_bsp_data_reference },
		{ _field_tag_reference, "forge lightmap atlases", &RenderModelLightmapAtlasReference },

		{ _field_terminator }
	};

	TAG_GROUP(
		render_model_group,
		RENDER_MODEL_TAG,
		nullptr,
		INVALID_TAG,
		render_model_block );

	TAG_GROUP(
		render_model_lightmap_atlas_group,
		RENDER_MODEL_LIGHTMAP_ATLAS_TAG,
		nullptr,
		INVALID_TAG,
		render_model_lightmap_atlas_block );

	TAG_BLOCK_FROM_STRUCT(
		imposter_model_block,
		"imposter_model_block",
		1,
		imposter_model_struct_definition);

	TAG_BLOCK_FROM_STRUCT(
		render_model_lightmap_atlas_block,
		"render_model_lightmap_atlas_block",
		1,
		render_model_lightmap_atlas_struct_definition);

	#define IMPOSTER_MODE_NODE_BLOCK_ID { 0xAA9DAC5D, 0x8B574A67, 0xA94FD4D9, 0xE2D76CB1 }
	TAG_BLOCK(
		imposter_mode_node_block,
		"imposter_mode_node_block",
		k_kilo,
		"s_model_node_map_node",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		IMPOSTER_MODE_NODE_BLOCK_ID)
	{
		{ _field_string_id, "name" },
		{ _field_short_integer, "base node index" },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_short_integer, "unknown" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		FIELD_PAD("WAXI", nullptr, FIELD_FLAG_NONE, 2),

		{ _field_terminator }
	};

	#define RENDER_MODEL_REGION_BLOCK_ID { 0x5F23BC11, 0xB76B42D7, 0xA38C6C46, 0x1DEE5813 }
	TAG_BLOCK(
		render_model_region_block,
		"region",
		MAXIMUM_REGIONS_PER_MODEL,
		"render_model_region",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		RENDER_MODEL_REGION_BLOCK_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_READ_ONLY | FIELD_FLAG_INDEX },
		{ _field_block, "permutations", FIELD_FLAG_READ_ONLY, &render_model_permutation_block, _field_id_slap },
		{ _field_terminator }
	};

	#define RENDER_MODEL_PERMUTATION_BLOCK_ID { 0x7900DDE2, 0x064B40BE, 0x8F806330, 0x878B35EB }
	TAG_BLOCK(
		render_model_permutation_block,
		"permutation",
		MAXIMUM_PERMUTATIONS_PER_MODEL_REGION,
		"render_model_permutation",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		RENDER_MODEL_PERMUTATION_BLOCK_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_READ_ONLY | FIELD_FLAG_INDEX },
		{ _field_short_integer, "mesh index", FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "mesh count", FIELD_FLAG_READ_ONLY },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_string_id, "clone name", FIELD_FLAG_READ_ONLY },

		{ _field_long_flags, "instance mask 0-31", FIELD_FLAG_READ_ONLY, &render_model_instance_bitfield_flags_definition },
		{ _field_long_flags, "instance mask 32-63", FIELD_FLAG_READ_ONLY, &render_model_instance_bitfield_flags_definition },
		{ _field_long_flags, "instance mask 64-95", FIELD_FLAG_READ_ONLY, &render_model_instance_bitfield_flags_definition },
		{ _field_long_flags, "instance mask 96-127", FIELD_FLAG_READ_ONLY, &render_model_instance_bitfield_flags_definition },
		{ _field_terminator }
	};

	#define RENDER_MODEL_NODE_BLOCK_ID { 0xB74453B7, 0xD6E3402E, 0x8A1587D0, 0xEFBF22EA }
	TAG_BLOCK(
		render_model_node_block,
		"node",
		MAXIMUM_NODES_PER_MODEL,
		"render_model_node",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		RENDER_MODEL_NODE_BLOCK_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_READ_ONLY | FIELD_FLAG_INDEX },
		{ _field_short_block_index, "parent node", FIELD_FLAG_READ_ONLY, &render_model_node_block },
		{ _field_short_block_index, "first child node", FIELD_FLAG_READ_ONLY, &render_model_node_block },
		{ _field_short_block_index, "next sibling node", FIELD_FLAG_READ_ONLY, &render_model_node_block },
		FIELD_PAD("RELFLFLLE", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real_point_3d, "default translation", FIELD_FLAG_READ_ONLY },
		{ _field_real_quaternion, "default rotation", FIELD_FLAG_READ_ONLY },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_real, "scale", FIELD_FLAG_READ_ONLY },	// yes its read only, dont question it dumdum

		{ _field_real_vector_3d, "inverse forward", FIELD_FLAG_READ_ONLY },
		{ _field_real_vector_3d, "inverse left", FIELD_FLAG_READ_ONLY },
		{ _field_real_vector_3d, "inverse up", FIELD_FLAG_READ_ONLY },
		{ _field_real_point_3d, "inverse position", FIELD_FLAG_READ_ONLY },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_real, "inverse scale", FIELD_FLAG_READ_ONLY },

		{ _field_real, "distance from parent", FIELD_FLAG_READ_ONLY },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 9 },
		FIELD_CUSTOM("Procedural Joint", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_char_enum, "procedure", &procedure_enum_definition },
		{ _field_char_enum, "procedure axis", &procedure_axis_enum_definition },
		FIELD_PAD("pad", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_short_block_index, "procedure node A", &render_model_node_block },
		{ _field_short_block_index, "procedure node B", &render_model_node_block },
		{ _field_real, "procedure var 1" },
		{ _field_real, "procedure var 2" },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),

		{ _field_terminator }
	};

	#define RENDER_MODEL_MARKER_GROUP_BLOCK_ID { 0xE60694FA, 0xA9EC4D0D, 0x89E6238C, 0xF66CBE15 }
	TAG_BLOCK(
		render_model_marker_group_block,
		"marker group",
		MAXIMUM_MARKER_GROUPS_PER_RENDER_MODEL,
		"render_model_marker_group",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		RENDER_MODEL_MARKER_GROUP_BLOCK_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_READ_ONLY | FIELD_FLAG_INDEX },
		{ _field_block, "markers", FIELD_FLAG_READ_ONLY, &render_model_marker_block },
		{ _field_terminator }
	};

	#define RENDER_MODEL_MARKER_BLOCK_ID { 0xD7CC940F, 0x39874D92, 0x808A0C39, 0x0AF0AC68 }
	TAG_BLOCK(
		render_model_marker_block,
		"marker",
		MAXIMUM_MARKERS_PER_RENDER_MODEL_MARKER_GROUP,
		"render_model_marker",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		RENDER_MODEL_MARKER_BLOCK_ID)
	{
		{ _field_char_integer, "region index", FIELD_FLAG_READ_ONLY },
		{ _field_char_integer, "permutation index", FIELD_FLAG_READ_ONLY },
		{ _field_byte_integer, "node index", FIELD_FLAG_READ_ONLY },
		{ _field_byte_flags, "flags", &render_model_marker_flags_definition },
		{ _field_real_point_3d, "translation", FIELD_FLAG_READ_ONLY },
		{ _field_real_quaternion, "rotation", FIELD_FLAG_READ_ONLY },
		{ _field_real, "scale" },
		{ _field_real_vector_3d, "direction", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define INSTANCE_NODE_MAP_MAPPING_BLOCK_ID { 0x1119ACFD, 0x0221F3EF, 0x38131BEE, 0x8441FBB8 }
	TAG_BLOCK(
		instance_node_map_mapping_block,
		"instance_node_map_mapping_block",
		MAXIMUM_NODES_PER_MODEL,
		"short",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		INSTANCE_NODE_MAP_MAPPING_BLOCK_ID)
	{
		{ _field_short_integer, "instance_node map region node index", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define VOLUME_SAMPLES_BLOCK_ID { 0x069D0DD6, 0x55E6413E, 0xAABD61B5, 0x3168B3C9 }
	TAG_BLOCK(
		volume_samples_block,
		"volume_samples_block",
		k_max_volume_samples_per_render_model,
		"s_volume_sample",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		VOLUME_SAMPLES_BLOCK_ID)
	{
		{ _field_real_vector_3d, "position" },
		{ _field_array, "radiance transfer matrix", FIELD_FLAG_READ_ONLY, &radiance_transfer_matrix_array },
		{ _field_terminator }
	};

	#define DEFAULT_NODE_ORIENTATIONS_BLOCK_ID { 0xA3A5979B, 0x41D84244, 0xA1400226, 0xA5CD38C9 }
	TAG_BLOCK(
		default_node_orientations_block,
		"default_node_orientations_block",
		MAXIMUM_NODES_PER_MODEL,
		"real_orientation",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		DEFAULT_NODE_ORIENTATIONS_BLOCK_ID,
		4)
	{
		{ _field_real_quaternion, "rotation", FIELD_FLAG_READ_ONLY },
		{ _field_real_point_3d, "translation", FIELD_FLAG_READ_ONLY },
		{ _field_real, "scale", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define RENDERMODELBONEGROUPBLOCK_ID { 0x0CECE183, 0xA7D74D0A, 0xA78A641B, 0x0A8E8A6D }
	TAG_BLOCK(
		RenderModelBoneGroupBlock_block,
		"bone_group",
		MAXIMUM_BONE_GROUPS_PER_MODEL,
		"RenderModelBoneGroup",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		RENDERMODELBONEGROUPBLOCK_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_READ_ONLY | FIELD_FLAG_INDEX },
		{ _field_block, "bones", FIELD_FLAG_READ_ONLY, &RenderModelNodeIndexBlock_block },
		{ _field_terminator }
	};

	#define RENDERMODELNODEINDEXBLOCK_ID { 0xEA52C9C3, 0x6EAF447E, 0x8B78348F, 0x9B765F30 }
	TAG_BLOCK(
		RenderModelNodeIndexBlock_block,
		"node_index",
		MAXIMUM_NODES_PER_MODEL,
		"short",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		RENDERMODELNODEINDEXBLOCK_ID)
	{
		{ _field_short_block_index, "node index", FIELD_FLAG_READ_ONLY | FIELD_FLAG_INDEX, &render_model_node_block },
		{ _field_terminator }
	};

	#define RADIANCE_TRANSFER_MATRIX_ID { 0x0FA34AD9, 0x785D45B5, 0xA12B1861, 0x7B84E30C }
	TAG_ARRAY(
		radiance_transfer_matrix_array,
		"radiance_transfer_matrix",
		9*9,
		"real",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		RADIANCE_TRANSFER_MATRIX_ID)
	{
		{ _field_real, "element", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define IMPOSTER_MODEL_STRUCT_DEFINITION_ID { 0x2A12A29F, 0xCF1C431E, 0x9FA1D5D2, 0xB805F111 }
	TAG_STRUCT(
		imposter_model_struct_definition,
		"imposter_model_struct_definition",
		"s_imposter_model",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_RESOURCES | 
		SET_UNKNOWN14 | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		IMPOSTER_MODEL_STRUCT_DEFINITION_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "quality" },
		FIELD_PAD("NBOML", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real, "brightness adjustment" },
		{ _field_block, "node maps", &imposter_mode_node_block },
		{ _field_block, "regions", FIELD_FLAG_READ_ONLY, &render_model_region_block, _field_id_slap },
		FIELD_CUSTOM("render geometry", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_struct, "geometry", FIELD_FLAG_READ_ONLY, &global_render_geometry_struct },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		{ _field_terminator }
	};

	#define RENDER_MODEL_LIGHTMAP_ATLAS_STRUCT_DEFINITION_ID { 0x00CA337E, 0x43CE7697, 0x0ABE1E3E, 0x1D862276 }
	TAG_STRUCT(
		render_model_lightmap_atlas_struct_definition,
		"render_model_lightmap_atlas_struct_definition",
		"RenderModelLightmapAtlas",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_RESOURCES | 
		SET_UNKNOWN14 | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		RENDER_MODEL_LIGHTMAP_ATLAS_STRUCT_DEFINITION_ID)
	{
		{ _field_struct, "atlas geometry", FIELD_FLAG_READ_ONLY, &global_render_geometry_struct },
		{ _field_real, "world scale ratio" },
		{ _field_terminator }
	};

	STRINGS(procedure_enum_definition)
	{
		"NONE",
		"multiply rotation"
	};
	STRING_LIST(procedure_enum_definition, procedure_enum_definition_strings, _countof(procedure_enum_definition_strings));

	STRINGS(procedure_axis_enum_definition)
	{
		"ALL",
		"Yaw (Maya Y)",
		"Pitch (Maya X)",
		"Roll (Maya Z)"
	};
	STRING_LIST(procedure_axis_enum_definition, procedure_axis_enum_definition_strings, _countof(procedure_axis_enum_definition_strings));

	STRINGS(render_model_flags_definition)
	{
		"is hologram",
		"UNUSED2",
		"has node maps",
		"has fur shader"
	};
	STRING_LIST(render_model_flags_definition, render_model_flags_definition_strings, _countof(render_model_flags_definition_strings));

	STRINGS(render_model_instance_bitfield_flags_definition)
	{
		"0",
		"1",
		"2",
		"3",
		"4",
		"5",
		"6",
		"7",
		"8",
		"9",
		"10",
		"11",
		"12",
		"13",
		"14",
		"15",
		"16",
		"17",
		"18",
		"19",
		"20",
		"21",
		"22",
		"23",
		"24",
		"25",
		"26",
		"27",
		"28",
		"29",
		"30",
		"31"
	};
	STRING_LIST(render_model_instance_bitfield_flags_definition, render_model_instance_bitfield_flags_definition_strings, _countof(render_model_instance_bitfield_flags_definition_strings));

	STRINGS(render_model_marker_flags_definition)
	{
		"has node relative direction"
	};
	STRING_LIST(render_model_marker_flags_definition, render_model_marker_flags_definition_strings, _countof(render_model_marker_flags_definition_strings));

	TAG_REFERENCE(RenderModelLightmapAtlasReference, RENDER_MODEL_LIGHTMAP_ATLAS_TAG);

} // namespace macaque

} // namespace blofeld

