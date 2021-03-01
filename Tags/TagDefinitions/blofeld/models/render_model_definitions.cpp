#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_GROUP_FROM_BLOCK(imposter_model, IMPOSTER_MODEL_TAG, imposter_model_block_block );


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
		{ _field_legacy, _field_block, "sky light unknown", &g_null_block_block },
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

	V5_TAG_GROUP(render_model, RENDER_MODEL_TAG)
	{
		{ _field_legacy, _field_string_id, "name*" },
		{ _field_legacy, _field_word_flags, "flags*", &render_model_flags_definition },
		{ _field_legacy, _field_word_integer, "version!" },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_long_integer, "runtime import info checksum!" },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_block, "regions*", &render_model_region_block_block },
		{ _field_legacy, _field_char_integer, "L1 section group index*:(low)" },
		{ _field_legacy, _field_char_integer, "L2 section group index*:(high)" },
		{ _field_legacy, _field_pad, "PUJJ", 2 },
		{ _field_legacy, _field_long_block_index, "instance mesh index*" },
		{ _field_legacy, _field_block, "instance placements", &global_render_model_instance_placement_block_block },
		{ _field_legacy, _field_long_integer, "node list checksum*" },
		{ _field_legacy, _field_block, "nodes*", &render_model_node_block_block },
		{ _field_legacy, _field_block, "marker groups*", &render_model_marker_group_block_block },
		{ _field_legacy, _field_block, "materials", &global_geometry_material_block_block },
		{ _field_legacy, _field_block, "errors*", &global_error_report_categories_block_block },
		{ _field_legacy, _field_real, "don\'t draw over camera cosine angle#dont draw fp model when camera > this angle cosine (-1,1) Sugg. -0.2. 0 disables." },
		{ _field_legacy, _field_struct, "render geometry*", &global_render_geometry_struct_struct_definition },
		{ _field_legacy, _field_block, "node map mapping*", &instance_node_map_mapping_block_block },

		{ _field_legacy, _field_version_less_or_equal , _engine_type_haloreach, 1 },
		{ _field_legacy, _field_struct, "unknown", &render_model_unknown_struct_struct_definition },

		{ _field_legacy, _field_block, "volume samples", &volume_samples_block_block },
		{ _field_legacy, _field_block, "runtime node orientations!", &default_node_orientations_block_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 5 },
		{ _field_legacy, _field_block, "bone groups", &RenderModelBoneGroupBlock_block },
		{ _field_legacy, _field_explanation, "Static Lightmap", "" },
		{ _field_legacy, _field_tag_reference, "structure meta data*", &Tag::Reference<struct StructureMetadata>::s_defaultDefinition },
		{ _field_legacy, _field_tag_reference, "lightmap bsp data reference", &scenario_lightmap_bsp_data_reference },
		{ _field_legacy, _field_tag_reference, "forge lightmap atlases", &RenderModelLightmapAtlasReference },

		{ _field_legacy, _field_terminator }
	};

	V5_TAG_GROUP_FROM_BLOCK(render_model_lightmap_atlas, RENDER_MODEL_LIGHTMAP_ATLAS_TAG, render_model_lightmap_atlas_block_block );

	V5_TAG_BLOCK(imposter_mode_node_block, k_kilo)
	{
		{ _field_legacy, _field_string_id, "name" },
		{ _field_legacy, _field_short_integer, "base node index" },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_short_integer, "unknown" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_legacy, _field_pad, "WAXI", 2 },

		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(render_model_permutation_block, MAXIMUM_PERMUTATIONS_PER_MODEL_REGION)
	{
		{ _field_legacy, _field_string_id, "name^*" },
		{ _field_legacy, _field_short_integer, "mesh index*" },
		{ _field_legacy, _field_short_integer, "mesh count*" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_legacy, _field_string_id, "clone name*" },

		{ _field_legacy, _field_long_flags, "instance mask 0-31*", &render_model_instance_bitfield_flags_definition },
		{ _field_legacy, _field_long_flags, "instance mask 32-63*", &render_model_instance_bitfield_flags_definition },
		{ _field_legacy, _field_long_flags, "instance mask 64-95*", &render_model_instance_bitfield_flags_definition },
		{ _field_legacy, _field_long_flags, "instance mask 96-127*", &render_model_instance_bitfield_flags_definition },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(render_model_region_block, MAXIMUM_REGIONS_PER_MODEL)
	{
		{ _field_legacy, _field_string_id, "name^*" },
		{ _field_legacy, _field_block, "permutations*", &render_model_permutation_block_block },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK_FROM_STRUCT(imposter_model_block, 1, imposter_model_struct_definition_struct_definition );

	V5_TAG_BLOCK(render_model_node_block, MAXIMUM_NODES_PER_MODEL)
	{
		{ _field_legacy, _field_string_id, "name^*" },
		{ _field_legacy, _field_short_block_index, "parent node*" },
		{ _field_legacy, _field_short_block_index, "first child node*" },
		{ _field_legacy, _field_short_block_index, "next sibling node*" },
		{ _field_legacy, _field_pad, "RELFLFLLE", 2 },
		{ _field_legacy, _field_real_point_3d, "default translation*" },
		{ _field_legacy, _field_real_quaternion, "default rotation*" },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_real, "scale*" },

		{ _field_legacy, _field_real_vector_3d, "inverse forward*" },
		{ _field_legacy, _field_real_vector_3d, "inverse left*" },
		{ _field_legacy, _field_real_vector_3d, "inverse up*" },
		{ _field_legacy, _field_real_point_3d, "inverse position*" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_legacy, _field_real, "inverse scale*" },

		{ _field_legacy, _field_real, "distance from parent*" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 9 },
		{ _field_legacy, _field_custom, "Procedural Joint" },
		{ _field_legacy, _field_char_enum, "procedure", &procedure_enum_definition },
		{ _field_legacy, _field_char_enum, "procedure axis", &procedure_axis_enum_definition },
		{ _field_legacy, _field_pad, "pad", 2 },
		{ _field_legacy, _field_short_block_index, "procedure node A" },
		{ _field_legacy, _field_short_block_index, "procedure node B" },
		{ _field_legacy, _field_real, "procedure var 1" },
		{ _field_legacy, _field_real, "procedure var 2" },
		{ _field_legacy, _field_custom },

		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(render_model_marker_block, MAXIMUM_MARKERS_PER_RENDER_MODEL_MARKER_GROUP)
	{
		{ _field_legacy, _field_char_integer, "region index*" },
		{ _field_legacy, _field_char_integer, "permutation index*" },
		{ _field_legacy, _field_byte_integer, "node index*" },
		{ _field_legacy, _field_byte_flags, "flags", &render_model_marker_flags_definition },
		{ _field_legacy, _field_real_point_3d, "translation*" },
		{ _field_legacy, _field_real_quaternion, "rotation*" },
		{ _field_legacy, _field_real, "scale" },
		{ _field_legacy, _field_real_vector_3d, "direction*" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(render_model_marker_group_block, MAXIMUM_MARKER_GROUPS_PER_RENDER_MODEL)
	{
		{ _field_legacy, _field_string_id, "name^*" },
		{ _field_legacy, _field_block, "markers*", &render_model_marker_block_block },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(instance_node_map_mapping_block, MAXIMUM_NODES_PER_MODEL)
	{
		{ _field_legacy, _field_short_integer, "instance_node map region node index*" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(volume_samples_block, k_max_volume_samples_per_render_model)
	{
		{ _field_legacy, _field_real_vector_3d, "position" },
		{ _field_legacy, _field_array, "radiance transfer matrix*", &radiance_transfer_matrix_array },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(default_node_orientations_block, MAXIMUM_NODES_PER_MODEL)
	{
		{ _field_legacy, _field_real_quaternion, "rotation*" },
		{ _field_legacy, _field_real_point_3d, "translation*" },
		{ _field_legacy, _field_real, "scale*" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(RenderModelNodeIndexBlock, MAXIMUM_NODES_PER_MODEL)
	{
		{ _field_legacy, _field_short_block_index, "node index^*" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(RenderModelBoneGroupBlock, MAXIMUM_BONE_GROUPS_PER_MODEL)
	{
		{ _field_legacy, _field_string_id, "name^*" },
		{ _field_legacy, _field_block, "bones*", &RenderModelNodeIndexBlock_block },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK_FROM_STRUCT(render_model_lightmap_atlas_block, 1, render_model_lightmap_atlas_struct_definition_struct_definition );

	V5_TAG_ARRAY(radiance_transfer_matrix, 9*9)
	{
		{ _field_legacy, _field_real, "element*!" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_STRUCT(imposter_model_struct_definition)
	{
		{ _field_legacy, _field_string_id, "name*" },
		{ _field_legacy, _field_short_integer, "quality" },
		{ _field_legacy, _field_pad, "NBOML", 2 },
		{ _field_legacy, _field_real, "brightness adjustment" },
		{ _field_legacy, _field_block, "node maps", &imposter_mode_node_block_block },
		{ _field_legacy, _field_block, "regions*", &render_model_region_block_block },
		{ _field_legacy, _field_custom, "render geometry" },
		{ _field_legacy, _field_struct, "geometry*", &global_render_geometry_struct_struct_definition },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_STRUCT(render_model_lightmap_atlas_struct_definition)
	{
		{ _field_legacy, _field_struct, "atlas geometry*", &global_render_geometry_struct_struct_definition },
		{ _field_legacy, _field_real, "world scale ratio" },
		{ _field_legacy, _field_terminator }
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
		{
			_engine_type_not_set,
			_versioned_string_list_mode_new,
			{
				"is hologram",
				"UNUSED2",
				"has node maps",
				"has fur shader"
			}
		},
		{
			_engine_type_haloreach,
			_versioned_string_list_mode_append,
			{
				"has split lighting", // #NOTE: unconfirmed, taken from halo5
			}
		},
		{
			_engine_type_gen3_xbox360,
			_versioned_string_list_mode_new,
			{
				"is hologram",
				"UNUSED2",
				"has node maps",
				"has fur shader"
			}
		},
		{
			_engine_type_halo5,
			_versioned_string_list_mode_new,
			{
				"is hologram",
				"has water",
				"has node maps",
				"LOD regions enabled",
				"has split lighting",
				"has depth peeling",
				"has custom shadow meshes",
				"has deferred reflections",
				"is hologram lofi",
				"has mid distance cull parts",
				"has close distance cull parts",
			}
		}
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

} // namespace blofeld

