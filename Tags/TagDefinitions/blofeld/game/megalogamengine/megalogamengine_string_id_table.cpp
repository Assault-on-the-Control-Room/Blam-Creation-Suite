#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(megalo_string_id_table, MEGALO_STRING_ID_TABLE_TAG, megalo_string_id_table_block_block );

	TAG_BLOCK(megalo_string_id_block, k_maximum_megalo_string_ids)
	{
		{ _field_string_id, "string_id^" },
		{ _field_terminator }
	};

	TAG_BLOCK(megalo_string_id_to_sprite_index_block, k_maximum_megalo_string_ids)
	{
		{ _field_custom_long_block_index, "from megalo string_id" },
		{ _field_long_integer, "loadout menu sprite frame" },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(megalo_string_id_table_block, 1, megalo_string_id_table_struct_definition_struct_definition );

	TAG_STRUCT(megalo_string_id_table_struct_definition)
	{
		{ _field_block, "megalo string_ids", &megalo_string_id_block_block },

		{ _field_version_greater, _engine_type_haloreach },
		{ _field_block, "megalo string_ids sprite mapping", &megalo_string_id_to_sprite_index_block_block },
		
		{ _field_terminator }
	};

	TAG_REFERENCE(global_megalo_string_id_table_reference, MEGALO_STRING_ID_TABLE_TAG);

} // namespace blofeld

