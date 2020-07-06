#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(cloth, CLOTH_TAG, cloth_block_block );

	TAG_BLOCK(collision_sphere_block, k_maximum_collision_spheres_per_cloth)
	{
		{ _field_string_id, "object marker name" },
		{ _field_real, "radius" },
		{ _field_terminator }
	};

	TAG_BLOCK(cloth_vertices_block, k_maximum_vertices_per_cloth)
	{
		{ _field_real_point_3d, "initial position*" },
		{ _field_real_vector_2d, "uv*" },
		{ _field_terminator }
	};

	TAG_BLOCK(cloth_indices_block, k_maximum_indices_per_cloth)
	{
		{ _field_short_integer, "index*" },
		{ _field_terminator }
	};

	TAG_BLOCK(cloth_links_block, k_maximum_links_per_cloth)
	{
		{ _field_version_greater, _engine_type_halo3, 4 },
		{ _field_real, "default_distance*" },
		{ _field_long_integer, "index1*" },
		{ _field_long_integer, "index2*" },
		{ _field_pad, "vmx_pad", 4 },

		{ _field_version_less_or_equal, _engine_type_halo3, 3 },
		{ _field_short_integer, "index1*" },
		{ _field_short_integer, "index2*" },
		{ _field_real, "default_distance*" },
		
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(cloth_block, 1, cloth_struct_definition_struct_definition );

	TAG_STRUCT(cloth_struct_definition)
	{
		{ _field_long_flags, "flags", &cloth_flags },
		{ _field_string_id, "marker attachment name" },
		{ _field_string_id, "secondary axis attachment name" },
		{ _field_tag_reference, "Shader", &global_shader_reference },
		{ _field_explanation, "Default cloth vertices", "if not importing from a render model, type a grid size" },
		{ _field_short_integer, "grid x dimension" },
		{ _field_short_integer, "grid y dimension" },
		{ _field_real, "grid spacing x" },
		{ _field_real, "grid spacing y" },
		{ _field_block, "collision spheres", &collision_sphere_block_block },
		{ _field_explanation, "Cloth Properties", "" },
		{ _field_struct, "properties", &cloth_properties_struct_definition },
		{ _field_explanation, "Import or grid data", "" },
		{ _field_block, "vertices*", &cloth_vertices_block_block },
		{ _field_block, "indices*", &cloth_indices_block_block },
		{ _field_block, "strip indices*", &cloth_indices_block_block },
		{ _field_block, "links*", &cloth_links_block_block },
		{ _field_terminator }
	};

	TAG_STRUCT(cloth_properties)
	{
		{ _field_enum, "Integration type*", &cloth_integration_enum },
		{ _field_short_integer, "Number iterations#[1-8] sug 1" },
		{ _field_real, "weight#[-10.0 - 10.0] sug 1.0" },
		{ _field_real, "drag#[0.0 - 0.5] sug 0.07" },
		{ _field_real, "wind_scale#[0.0 - 3.0] sug 1.0" },
		{ _field_real, "wind_flappiness_scale#[0.0 - 1.0] sug 0.75" },
		{ _field_real, "longest_rod#[1.0 - 10.0] sug 3.5" },
		{ _field_pad, "WXLH", 24 },
		{ _field_terminator }
	};

	STRINGS(cloth_flags)
	{
		"Doesn\'t use wind",
		"Uses grid attach top"
	};
	STRING_LIST(cloth_flags, cloth_flags_strings, _countof(cloth_flags_strings));

	STRINGS(cloth_integration_enum)
	{
		"verlet"
	};
	STRING_LIST(cloth_integration_enum, cloth_integration_enum_strings, _countof(cloth_integration_enum_strings));

	TAG_REFERENCE(global_shader_reference, MATERIAL_TAG);

} // namespace blofeld

