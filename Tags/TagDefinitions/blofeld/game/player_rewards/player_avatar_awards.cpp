#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(avatar_awards, AVATAR_AWARDS_TAG, avatar_awards_block_block );

	TAG_BLOCK(single_avatar_award_definition_block, k_online_avatar_award_count)
	{
		{ _field_string_id, "name^" },
		{ _field_long_enum, "type", &global_avatar_award_enum },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(avatar_awards_block, 1, avatar_awards_struct_definition_struct_definition );

	TAG_STRUCT(avatar_awards_struct_definition)
	{
		{ _field_block, "avatar_award", &single_avatar_award_definition_block_block },
		{ _field_terminator }
	};

	STRINGS(global_avatar_award_enum)
	{
		"award_0",
		"award_1",
		"award_2",
		"award_3",
		"award_4"
		
	};
	STRING_LIST(global_avatar_award_enum, global_avatar_award_enum_strings, _countof(global_avatar_award_enum_strings));

} // namespace blofeld

