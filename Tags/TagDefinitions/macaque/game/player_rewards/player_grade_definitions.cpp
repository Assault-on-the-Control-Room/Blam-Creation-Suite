#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		player_grade_globals_definition_group,
		PLAYER_GRADE_GLOBALS_DEFINITION_TAG,
		nullptr,
		INVALID_TAG,
		player_grade_globals_definition_block );

	TAG_BLOCK_FROM_STRUCT(
		player_grade_globals_definition_block,
		"player_grade_globals_definition_block",
		1,
		player_grade_globals_definition_struct_definition);

	#define PLAYER_GRADE_DEFINITION_BLOCK_ID { 0x06E98160, 0xD9D646B4, 0xBD6054A2, 0x970CE24B }
	TAG_BLOCK(
		player_grade_definition_block,
		"player_grade_definition_block",
		k_maxPlayerGradeCount,
		"s_player_grade_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		PLAYER_GRADE_DEFINITION_BLOCK_ID)
	{
		{ _field_long_integer, "xp threshold ", "total earned XP needed to reach this rank" },
		{ _field_string_id, "name" },
		{ _field_short_integer, "sprite index" },
		FIELD_PAD("pad0", nullptr, FIELD_FLAG_NONE, 2),

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_real, "time played multiplier", "This is an additional multiplier to rewards given for time played for players at this grade" },
		{ _field_block, "level up rewards", "These rewards will be given to the player when they reach this grade", &rewardBlock_block },

		{ _field_terminator }
	};

	#define PLAYER_RANK_GLOBALS_DEFINITION_BLOCK_ID { 0xCE27F00B, 0x5AC44866, 0xA310574D, 0x5912AF36 }
	TAG_BLOCK(
		player_rank_globals_definition_block,
		"player_rank_globals_definition_block",
		k_maxPlayerGradeCount,
		"s_player_rank_globals_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		PLAYER_RANK_GLOBALS_DEFINITION_BLOCK_ID)
	{
		{ _field_block, "player grades", &player_grade_definition_block },
		{ _field_terminator }
	};

	#define PLAYER_GRADE_GLOBALS_DEFINITION_STRUCT_DEFINITION_ID { 0xCE27F00B, 0x5AC44866, 0xA310574D, 0x5912AF36 }
	TAG_STRUCT(
		player_grade_globals_definition_struct_definition,
		"player_grade_globals_definition_struct_definition",
		"s_player_grade_globals_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		PLAYER_GRADE_GLOBALS_DEFINITION_STRUCT_DEFINITION_ID)
	{
		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_block, "player ranks", &player_rank_globals_definition_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_block, "player grades", &player_grade_definition_block },

		{ _field_terminator }
	};

} // namespace macaque

} // namespace blofeld

