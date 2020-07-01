#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_BLOCK(part_block, BYTE_MAX)
	{
		{ _field_short_block_index, "render method index^*" },
		{ _field_short_block_index, "transparent sorting index*" },

		{ _field_version_less_or_equal, _engine_type_haloreach, 2 },
		{ _field_short_integer, "index start*" },
		{ _field_short_integer, "index count*" },

		{ _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_long_integer, "index start*" },
		{ _field_long_integer, "index count*" },

		{ _field_short_integer, "subpart start*" },
		{ _field_short_integer, "subpart count*" },

		{ _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_char_integer, "part type*" },
		{ _field_char_enum, "specialized render", &specialized_render_definition },

		{ _field_word_flags, "part flags*", &part_flags },
		{ _field_word_integer, "budget vertex count" },

		{ _field_version_greater, _engine_type_haloreach },
		{ _field_enum, "tessellation", &tessellation_mode_definition },

		{ _field_terminator }
	};

	TAG_BLOCK(subpart_block, UNSIGNED_SHORT_MAX)
	{
		{ _field_version_less_or_equal, _engine_type_haloreach, 2 },
		{ _field_short_integer, "index start*" },
		{ _field_short_integer, "index count*" },

		{ _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_long_integer, "index start*" },
		{ _field_long_integer, "index count*" },

		{ _field_short_block_index, "part index*" },
		{ _field_word_integer, "budget vertex count" },

		{ _field_version_greater, _engine_type_haloreach },
		{ _field_dword_integer, "analytical light index" },
		{ _field_terminator }
	};

	TAG_BLOCK(instance_index_word_block, UNSIGNED_SHORT_MAX)
	{
		{ _field_short_integer, "instance index*" },
		{ _field_terminator }
	};

	TAG_BLOCK(global_instance_bucket_block, (2*1024))
	{
		{ _field_short_integer, "mesh index*" },
		{ _field_short_integer, "definition index*" },
		{ _field_block, "instances", &instance_index_word_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(indices_word_block, 2147483647L)
	{
		{ _field_short_integer, "word*" },
		{ _field_terminator }
	};

	TAG_BLOCK(vertexKeyBlock, MAXIMUM_VERTICES_PER_GEOMETRY_SECTION)
	{
		{ _field_long_integer, "key1*" },
		{ _field_long_integer, "key2*" },
		{ _field_terminator }
	};

	TAG_BLOCK(global_mesh_block, (8*1024-1))
	{
		{ _field_block, "parts*", &part_block_block },
		{ _field_block, "subparts*", &subpart_block_block },
		{ _field_array, "vertex buffer indices*", &vertex_buffer_indices_word_array_array },
		{ _field_short_integer, "index buffer index*" },

		{ _field_version_greater, _engine_type_haloreach, 1 },
		{ _field_short_integer, "index buffer tessellation*" },

		{ _field_word_flags, "mesh flags*", &mesh_flags },

		{ _field_char_integer, "rigid node index*" },
		{ _field_char_enum, "vertex type*", &mesh_vertex_type_definition },
		{ _field_char_enum, "PRT vertex type*", &mesh_transfer_vertex_type_definition },
		{ _field_char_enum, "lighting policy", &mesh_lighting_policy_type_definition },
		{ _field_char_enum, "index buffer type*", &mesh_index_buffer_type_definition },

		{ _field_version_less_or_equal, _engine_type_haloreach, 1 },
		{ _field_char_integer, "pca mesh index*" },

		{ _field_version_greater, _engine_type_haloreach, 2 },	
		{ _field_pad, "BAASDFIR", 1 },
		{ _field_short_integer, "pca mesh index*" },

		{ _field_block, "instance buckets*", &global_instance_bucket_block_block },
		{ _field_block, "water indices start", &indices_word_block_block },

		{ _field_real, "runtime bounding radius:world units*!" },
		{ _field_real_point_3d, "runtime bounding offset*!" },

		{ _field_version_greater, _engine_type_haloreach, 3 },
		{ _field_block, "vertex keys*", &vertexKeyBlock_block },
		{ _field_short_block_index, "clone index*" },
		{ _field_short_integer, "cumulative part count (initialized by PVS building code)" },

		{ _field_terminator }
	};

	TAG_BLOCK(PCAMeshIndexBlock, (8*1024-1))
	{
		{ _field_long_block_index, "mesh index" },
		{ _field_terminator }
	};

	TAG_BLOCK(compression_info_block, 1+UNSIGNED_SHORT_MAX)
	{
		{ _field_word_flags, "compression flags*", &compression_flags },
		{ _field_pad, "JOJOBOMO", 2 },
		{ _field_explanation, "WARNING", "The following fields are mislabeled for legacy reasons.The actual order is:\nposition_bounds.x0 position_bounds.x1 position_bounds.y0\nposition_bounds.y1 position_bounds.z0 position_bounds.z1\n\ntexcoord_bounds.x0 texcoord_bounds.x1\ntexcoord_bounds.y0 texcoord_bounds.y1\n" },
		{ _field_real_point_3d, "position bounds 0*" },
		{ _field_real_point_3d, "position bounds 1*" },
		{ _field_real_point_2d, "texcoord bounds 0*" },
		{ _field_real_point_2d, "texcoord bounds 1*" },
		{ _field_real, "unused0*" },
		{ _field_real, "unused1*" },

		{ _field_terminator }
	};

	TAG_BLOCK(sorting_position_block, UNSIGNED_SHORT_MAX)
	{
		{ _field_real_plane_3d, "plane*" },
		{ _field_real_point_3d, "position*" },
		{ _field_real, "radius*" },
		{ _field_array, "node indices*", &node_indices_array_array },
		{ _field_array, "node weights*", &node_weights_implicit_array_array },
		{ _field_terminator }
	};

	TAG_BLOCK(user_data_block, 64)
	{
		{ _field_struct, "user data header*", &global_render_geometry_user_data_header_struct_struct_definition },
		{ _field_data, "user data*" },
		{ _field_terminator }
	};

	TAG_BLOCK(raw_vertex_block, MAXIMUM_VERTICES_PER_GEOMETRY_SECTION)
	{
		{ _field_real_point_3d, "position*" },
		{ _field_real_point_2d, "texcoord*" },
		{ _field_real_point_3d, "normal*" },
		{ _field_real_point_3d, "binormal*" },
		{ _field_real_point_3d, "tangent*" },
		{ _field_real_point_2d, "lightmap texcoord*" },
		{ _field_array, "node indices*", &node_indices_array_array },
		{ _field_array, "node weights*", &node_weights_complete_array_array },
		{ _field_real_point_3d, "vertex color*" },
		{ _field_real_point_2d, "texcoord1*" },
		{ _field_terminator }
	};

	TAG_BLOCK(indices_dword_block, 2147483647L)
	{
		{ _field_long_integer, "dword*" },
		{ _field_terminator }
	};

	TAG_BLOCK(raw_water_append_block, UNSIGNED_SHORT_MAX)
	{
		{ _field_real_point_2d, "base texcoord*" },
		{ _field_terminator }
	};

	TAG_BLOCK(raw_water_block, 1024)
	{
		{ _field_block, "raw water indices*", &indices_word_block_block },
		{ _field_block, "raw water vertices*", &raw_water_append_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(raw_imposter_brdf_block, UNSIGNED_SHORT_MAX)
	{
		{ _field_real_rgb_color, "diffuse" },
		{ _field_real_rgb_color, "ambient" },
		{ _field_real_rgb_color, "specular" },
		{ _field_real, "shininess" },
		{ _field_real, "alpha" },
		{ _field_real_argb_color, "change color tint of diffuse" },
		{ _field_real_argb_color, "change color tint of specular" },
		{ _field_terminator }
	};

	TAG_BLOCK(raw_instance_imposter_block, UNSIGNED_SHORT_MAX)
	{
		{ _field_real_vector_3d, "position" },
		{ _field_dword_integer, "color" },
		{ _field_real, "HDR scaler" },
		{ _field_terminator }
	};

	TAG_BLOCK(raw_blendshape_block, MAXIMUM_VERTICES_PER_GEOMETRY_SECTION)
	{
		{ _field_real_vector_3d, "position*" },
		{ _field_real_vector_3d, "normal*" },
		{ _field_real_argb_color, "tension and ambient occlusion*" },
		{ _field_terminator }
	};

	TAG_BLOCK(per_mesh_raw_data_block, (8*1024-1))
	{
		{ _field_block, "raw vertices*", &raw_vertex_block_block },
		{ _field_block, "raw indices*", &indices_word_block_block },
		{ _field_block, "raw indices32*", &indices_dword_block_block },
		{ _field_block, "raw water data", &raw_water_block_block },
		{ _field_block, "raw imposter data", &raw_imposter_brdf_block_block },
		{ _field_block, "raw instance imposter verts", &raw_instance_imposter_block_block },
		{ _field_block, "raw blendshapes*", &raw_blendshape_block_block },
		{ _field_long_integer, "per vertex lighting vertex size" },
		{ _field_short_integer, "parameterized texture width" },
		{ _field_short_integer, "parameterized texture height" },
		{ _field_long_flags, "flags", &per_mesh_raw_data_flags },
		{ _field_terminator }
	};

	TAG_BLOCK(node_map_byte_block, BYTE_MAX)
	{
		{ _field_char_integer, "node index*" },
		{ _field_terminator }
	};

	TAG_BLOCK(per_mesh_node_map_block, (8*1024-1))
	{
		{ _field_block, "node map*", &node_map_byte_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(per_mesh_subpart_visibility_block, 64)
	{
		{ _field_block, "bounding_sphere*", &sorting_position_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(per_instance_prt_data_block, UNSIGNED_SHORT_MAX)
	{
		{ _field_data, "mesh pca data*" },
		{ _field_terminator }
	};

	TAG_BLOCK(per_mesh_prt_data_block, (8*1024-1))
	{
		{ _field_data, "mesh pca data*" },
		{ _field_block, "per instance prt data", &per_instance_prt_data_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(raw_texcoord_block, MAXIMUM_VERTICES_PER_GEOMETRY_SECTION)
	{
		{ _field_real_point_2d, "texcoord*" },
		{ _field_terminator }
	};

	TAG_BLOCK(per_instance_lightmap_texcoords_block, UNSIGNED_SHORT_MAX)
	{
		{ _field_block, "texture coordinates", &raw_vertex_block_block },

		{ _field_version_greater, _engine_type_haloreach },
		{ _field_block, "texture coordinates (concise)", &raw_texcoord_block_block },

		{ _field_short_integer, "vertex buffer index*" },
		{ _field_pad, "HTJIAHA", 2 },
		{ _field_terminator }
	};

	TAG_BLOCK(water_bounding_box_block, (8*1024-1))
	{
		{ _field_short_integer, "mesh index" },
		{ _field_short_integer, "part index" },
		{ _field_real_point_3d, "position bounds 0" },
		{ _field_real_point_3d, "position bounds 1" },
		{ _field_terminator }
	};

	TAG_BLOCK(render_geometry_pvs_data_visibility_value_block, UNSIGNED_SHORT_MAX)
	{
		{ _field_dword_integer, "Value" },
		{ _field_terminator }
	};

	TAG_BLOCK(render_geometry_pvs_data_visibility_index_block, UNSIGNED_SHORT_MAX)
	{
		{ _field_word_integer, "Index" },
		{ _field_terminator }
	};

	TAG_BLOCK(render_geometry_pvs_data_block, 16)
	{
		{ _field_block, "Visibility array", &render_geometry_pvs_data_visibility_value_block_block },
		{ _field_block, "Per-block visibility offset array", &render_geometry_pvs_data_visibility_index_block_block },
		{ _field_long_integer, "Bits per block" },
		{ _field_real_point_3d, "Object space grid AABB min" },
		{ _field_real_point_3d, "Object space grid AABB max" },
		{ _field_real_vector_3d, "Block Size" },
		{ _field_long_integer, "Num blocks X" },
		{ _field_long_integer, "Num blocks Y" },
		{ _field_long_integer, "Num blocks Z" },
		{ _field_terminator }
	};

	TAG_BLOCK(shapeNameBlock, 8192)
	{
		{ _field_long_integer, "key*" },
		{ _field_long_string, "name*" },
		{ _field_terminator }
	};

	TAG_ARRAY(vertex_buffer_indices_word_array, ((sizeof(*numberof_sizeof_proxy<(sizeof(((((s_mesh *)0)->vertex_buffer_indices)))/sizeof(((((s_mesh *)0)->vertex_buffer_indices))[0]))>(((((s_mesh *)0)->vertex_buffer_indices)))))))
	{
		{ _field_word_integer, "vertex buffer index*" },
		{ _field_terminator }
	};

	TAG_ARRAY(node_indices_array, 4)
	{
		{ _field_byte_integer, "node index*" },
		{ _field_terminator }
	};

	TAG_ARRAY(node_weights_implicit_array, 4-1)
	{
		{ _field_real, "node weight*" },
		{ _field_terminator }
	};

	TAG_ARRAY(node_weights_complete_array, 4)
	{
		{ _field_real, "node weight*" },
		{ _field_terminator }
	};

	TAG_BLOCK(global_render_geometry_unknown_meshes2, 65536)
	{
		{ _field_short_integer, "unknown" },
		{ _field_terminator }
	};

	TAG_BLOCK(global_render_geometry_unknown_meshes, 65536)
	{
		{ _field_data, "unknown" },
		{ _field_block, "unknown", &global_render_geometry_unknown_meshes2_block },
		{ _field_terminator }
	};

	TAG_BLOCK(structure_design_constant_buffer_interop, 65536) // assembly
	{
		{ _field_api_interop, "constant buffer interop*" },
		{ _field_terminator }
	};

	TAG_STRUCT(global_render_geometry_struct)
	{
		{ _field_explanation, "Render Geometry", "\nAll new Halo 3 render geometry definitions!\n\n" },
		{ _field_long_flags, "runtime flags*!", &render_geometry_flags },
		{ _field_block, "meshes*", &global_mesh_block_block },

		{ _field_version_greater, _engine_type_haloreach, 1 },
		{ _field_block, "PCA Mesh Indices*", &PCAMeshIndexBlock_block },

		{ _field_block, "compression info*", &compression_info_block_block },
		{ _field_block, "part sorting position*", &sorting_position_block_block },
		{ _field_block, "user data*", &user_data_block_block },
		{ _field_block, "per mesh temporary*", &per_mesh_raw_data_block_block },
		{ _field_pad, "pad3", 12 },
		{ _field_block, "per mesh node map*", &per_mesh_node_map_block_block },
		{ _field_block, "per mesh subpart visibility*", &per_mesh_subpart_visibility_block_block },
		{ _field_block, "per_mesh_prt_data*", &per_mesh_prt_data_block_block },
		{ _field_block, "per_instance_lightmap_texcoords*", &per_instance_lightmap_texcoords_block_block },

		{ _field_version_less, _engine_type_haloreach, 1 }, // assembly. #TODO: Verify this
		{ _field_block, "unknown meshes", &global_render_geometry_unknown_meshes_block }, // Unknown Meshes

		{ _field_version_equal, _engine_type_haloreach, 1 }, // assembly. #TODO: Verify this
		{ _field_block, "unknown meshes", &global_render_geometry_unknown_meshes2_block }, // Unknown Meshes

		{ _field_block, "water bounding box block*", &water_bounding_box_block_block },	
		{ _field_pageable, "api resource" },

		{ _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_block, "Optional PVS data", &render_geometry_pvs_data_block_block },
		{ _field_block, "shapeNames*", &shapeNameBlock_block },

		{ _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_block, "constant buffer interop", &structure_design_constant_buffer_interop_block }, // assembly

		{ _field_terminator }
	};

	TAG_STRUCT(global_render_geometry_user_data_header_struct)
	{
		{ _field_char_enum, "data type^*", &render_geometry_user_data_type_definition },
		{ _field_char_integer, "data count*" },
		{ _field_word_integer, "data size*" },
		{ _field_terminator }
	};

	STRINGS(part_flags)
	{
		{
			_engine_type_not_set,
			_versioned_string_list_mode_new,
			{
				"is water surface",
				"per vertex lightmap part",
				"debug flag instance part",
				"subparts has uberlights info",
				"draw cull distance medium",
				"draw cull distance close",
				"draw cull rendering shields",
				"cannot single pass render",
				"is transparent",
				"cannot two pass",
				"transparent should output depth for DoF#expensive",
				"do not include in static lightmap",
				"do not include in PVS generation",
				"draw cull rendering active camo",
			}
		},
		{
			_engine_type_haloreach,
			_versioned_string_list_mode_append,
			{
				"bit 15",
				"bit 16"
			}
		}
	};
	STRING_LIST(part_flags, part_flags_strings, _countof(part_flags_strings));

	STRINGS(tessellation_mode_definition)
	{
		"none",
		"fixed x4 faces",
		"fixed x9 faces",
		"fixed x36 faces"
	};
	STRING_LIST(tessellation_mode_definition, tessellation_mode_definition_strings, _countof(tessellation_mode_definition_strings));

	STRINGS(specialized_render_definition)
	{
		"none",
		"fail",
		"fur",
		"fur_stencil",
		"decal",
		"shield",
		"water",
		"lightmap_only",
		"hologram"
	};
	STRING_LIST(specialized_render_definition, specialized_render_definition_strings, _countof(specialized_render_definition_strings));

	STRINGS(compression_flags)
	{
		"compressed position",
		"compressed texcoord",
		"compression optimized"
	};
	STRING_LIST(compression_flags, compression_flags_strings, _countof(compression_flags_strings));

	STRINGS(mesh_flags)
	{
		"mesh has vertex color",
		"use region index for sorting",
		"use vertex buffers for indices",
		"mesh has per-instance lighting (do not modify)",
		"mesh is unindexed (do not modify)",
		"subpart were merged",
		"mesh has fur",
		"mesh has decal",
		"mesh doesnt use compressed position",
		"use uncompressed vertex format",
		"mesh is PCA",
		"mesh compression determined",
		"mesh has authored lightmap texture coords",
		"mesh has a useful set of second texture coords",
		"mesh has no lightmap",
		"per vertex lighting"
	};
	STRING_LIST(mesh_flags, mesh_flags_strings, _countof(mesh_flags_strings));

	STRINGS(mesh_vertex_type_definition)
	{
		"world",
		"rigid",
		"skinned",
		"particle_model",
		"flat world",
		"flat rigid",
		"flat skinned",
		"screen",
		"debug",
		"transparent",
		"particle",
		"unused0",
		"light_volume",
		"chud_simple",
		"chud_fancy",
		"decorator",
		"position only",
		"patchy_fog",
		"water",
		"ripple",
		"implicit geometry",
		"unused1",
		"world_tessellated",
		"rigid_tessellated",
		"skinned_tessellated",
		"shader_cache",
		"structure_instance_imposter",
		"object_instance_imposter",
		"rigid compressed",
		"skinned uncompressed",
		"light volume precompiled",
		"blendshape_rigid",
		"blendshape_rigid_blendshaped",
		"rigid_blendshaped",
		"blendshape_skinned",
		"blendshape_skinned_blendshaped",
		"skinned_blendshaped",
		"VirtualGeometryHWtess",
		"VirtualGeometryMemexport",
		"position_only",
		"VirtualGeometryDebug",
		"blendshapeRigidCompressed",
		"skinnedUncompressedBlendshaped",
		"blendshapeSkinnedCompressed",
		"tracer",
		"polyart",
		"vectorart",
		"rigid_boned",
		"rigid_boned_2uv",
		"blendshape_skinned_2uv",
		"blendshape_skinned_2uv_blendshaped",
		"skinned_2uv_blendshaped",
		"polyartUV",
		"blendshape_skinned_uncompressed_blendshaped"
	};
	STRING_LIST(mesh_vertex_type_definition, mesh_vertex_type_definition_strings, _countof(mesh_vertex_type_definition_strings));

	STRINGS(mesh_transfer_vertex_type_definition)
	{
		"No PRT",
		"PRT Ambient",
		"PRT Linear",
		"PRT Quadratic"
	};
	STRING_LIST(mesh_transfer_vertex_type_definition, mesh_transfer_vertex_type_definition_strings, _countof(mesh_transfer_vertex_type_definition_strings));

	STRINGS(mesh_lighting_policy_type_definition)
	{
		"vertex color",
		"single probe",
		"prt ambient"
	};
	STRING_LIST(mesh_lighting_policy_type_definition, mesh_lighting_policy_type_definition_strings, _countof(mesh_lighting_policy_type_definition_strings));

	STRINGS(mesh_index_buffer_type_definition)
	{
		"DEFAULT",
		"line list",
		"line strip",
		"triangle list",
		"triangle fan",
		"triangle strip",
		"quad list",
		"rect list"
	};
	STRING_LIST(mesh_index_buffer_type_definition, mesh_index_buffer_type_definition_strings, _countof(mesh_index_buffer_type_definition_strings));

	STRINGS(per_mesh_raw_data_flags)
	{
		"indices are triangle strips",
		"indices are triangle lists",
		"indices are quad lists"
	};
	STRING_LIST(per_mesh_raw_data_flags, per_mesh_raw_data_flags_strings, _countof(per_mesh_raw_data_flags_strings));

	STRINGS(render_geometry_user_data_type_definition)
	{
		"PRT Info"
	};
	STRING_LIST(render_geometry_user_data_type_definition, render_geometry_user_data_type_definition_strings, _countof(render_geometry_user_data_type_definition_strings));

	STRINGS(render_geometry_flags)
	{
		"processed*!",
		"available*!",
		"has valid budgets (really)*!",
		"manual resource creation*!",
		"keep raw geometry*!",
		"dont use compressed vertex positions*!",
		"pca animation table sorted*!",
		"needs no lightmap uvs*!",
		"always needs lightmap uvs*!"
	};
	STRING_LIST(render_geometry_flags, render_geometry_flags_strings, _countof(render_geometry_flags_strings));

} // namespace blofeld

