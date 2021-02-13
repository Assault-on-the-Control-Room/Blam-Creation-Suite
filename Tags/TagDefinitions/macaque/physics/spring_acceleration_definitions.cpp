#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		spring_acceleration_group,
		SPRING_ACCELERATION_TAG,
		nullptr,
		INVALID_TAG,
		spring_acceleration_block );

	TAG_BLOCK_FROM_STRUCT(
		spring_acceleration_block,
		"spring_acceleration_block",
		1,
		spring_acceleration_struct_definition);

	#define SPRING_LINEAR_ACCELERATION_BLOCK_ID { 0x1C23AAAC, 0x13234449, 0xAEAB1083, 0xD9170D8A }
	TAG_BLOCK(
		spring_linear_acceleration_block,
		"spring_linear_acceleration_block",
		k_dimensions_in_3d_count,
		"s_spring_acceleration_linear_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SPRING_LINEAR_ACCELERATION_BLOCK_ID)
	{
		{ _field_real, "acceleration range", nullptr, "world units" },
		{ _field_real, "inverse acceleration range", nullptr, "world units", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real, "world acceleration scale", "0 defaults to 1, scale the acceleration the object itself applies on this system." },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_pad, "presumed 8byte struct alignment", 4 },

		FIELD_EXPLANATION("damping", nullptr, FIELD_FLAG_NONE, "feed velocity into this function and damp by the value that comes out"),
		{ _field_struct, "spring damping", &scalar_function_named_struct },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_pad, "presumed 8byte struct alignment", 4 },

		{ _field_real, "velocity domain" },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_pad, "presumed 8byte struct alignment", 4 },

		{ _field_struct, "spring acceleration", &scalar_function_named_struct },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_pad, "presumed 8byte struct alignment", 4 },

		{ _field_terminator }
	};

	#define SPRING_ACCELERATION_STRUCT_DEFINITION_ID { 0x1073ABE0, 0xAD9447BB, 0x8910B4FF, 0x30CD63B1 }
	TAG_STRUCT(
		spring_acceleration_struct_definition,
		"spring_acceleration_struct_definition",
		"s_spring_acceleration_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SPRING_ACCELERATION_STRUCT_DEFINITION_ID)
	{
		{ _field_block, "linear acceleartions", &spring_linear_acceleration_block },
		{ _field_short_block_index, "x-axis", &spring_linear_acceleration_block },
		{ _field_short_block_index, "y-axis", &spring_linear_acceleration_block },
		{ _field_short_block_index, "z-axis", &spring_linear_acceleration_block },
		FIELD_PAD("pad", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

} // namespace macaque

} // namespace blofeld

