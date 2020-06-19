#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(antenna, ANTENNA_TAG, antenna_block_block );

	TAG_BLOCK(antenna_vertex_block, MAXIMUM_NUMBER_OF_ANTENNA_VERTICES)
	{
		{ _field_real_euler_angles_2d, "angles#direction toward next vertex!" },
		{ _field_real, "length:world units#distance between this vertex and the next" },
		{ _field_short_integer, "sequence index#bitmap group sequence index for this vertex\'s texture" },
		{ _field_pad, "NTCTQQF", 2 },
		{ _field_real_argb_color, "color#color at this vertex" },
		{ _field_real_argb_color, "LOD color#color at this vertex for the low-LOD line primitives!" },
		{ _field_real, "hermite t!" },
		{ _field_real_vector_3d, "vector to next!" },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(antenna_block, 1, antenna_struct_definition_struct_definition );

	TAG_STRUCT(antenna_struct_definition)
	{
		{ _field_old_string_id, "attachment marker name#the marker name where the antenna should be attached" },
		{ _field_tag_reference, "bitmaps", &bitmap_reference$4 },
		{ _field_tag_reference, "physics", &global_point_physics_reference },
		{ _field_real_fraction, "spring strength coefficient#strength of the spring (larger values make the spring stronger)" },

		{ _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_real, "texel to world width scale" },
		
		{ _field_real, "falloff pixels!" },
		{ _field_real, "cutoff pixels!" },
		{ _field_real, "point of bend#[0,1]" },
		{ _field_real, "starting bend#[0,1]" },
		{ _field_real, "ending bend#[0,1]" },
		{ _field_real, "runtime total length!" },
		{ _field_block, "vertices", &antenna_vertex_block_block },
		{ _field_terminator }
	};

} // namespace blofeld

