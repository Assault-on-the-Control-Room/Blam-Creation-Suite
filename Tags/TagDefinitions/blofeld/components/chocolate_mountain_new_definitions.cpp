#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{
	TAG_GROUP_FROM_BLOCK(chocolate_mountain_new, CHOCOLATE_MOUNTAIN_NEW_TAG, chocolate_mountain_block_block);

	TAG_BLOCK(lighting_variable_block, 65536)
	{
		{ _field_real, "lightmap brightness offset" },
		{ _field_real, "lightmap darkness offset" },
		{ _field_real, "unknown" },
		{ _field_real, "dynamic lightmap brightness offset" },
		{ _field_real, "dynamic lightmap darkness offset" },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(chocolate_mountain_block, 1, chocolate_mountain_struct_definition_struct_definition);

	TAG_STRUCT(chocolate_mountain_struct_definition)
	{
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_block, "lighting variables", &lighting_variable_block_block },
		{ _field_terminator }
	};

	TAG_REFERENCE(global_chocolate_mountain_reference, CHOCOLATE_MOUNTAIN_NEW_TAG);
} // namespace blofeld