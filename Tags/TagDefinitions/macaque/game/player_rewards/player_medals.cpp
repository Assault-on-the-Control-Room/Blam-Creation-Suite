#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		game_medal_globals_group,
		GAME_MEDAL_GLOBALS_TAG,
		nullptr,
		INVALID_TAG,
		game_medal_globals_block );

	TAG_BLOCK_FROM_STRUCT(
		game_medal_globals_block,
		"game_medal_globals_block",
		1,
		game_medal_globals_struct_definition);

	#define GAMEMEDALTIERS_ID { 0xC1C2D85E, 0x9E664F4F, 0x9B76ABC1, 0xDAB1CD0E }
	TAG_BLOCK(
		gameMedalTiers_block,
		"gameMedalTiers",
		GameMedalTierDefinition::k_maximumGameMedalTierDefinitions,
		"GameMedalTierDefinition",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		GAMEMEDALTIERS_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_string_id, "description" },
		{ _field_short_integer, "sequence index" },
		{ _field_short_integer, "point value" },
		{ _field_terminator }
	};

	#define GAME_MEDAL_BLOCK_ID { 0xF9F8912F, 0x751346A0, 0xB670D5B7, 0x799A1799 }
	TAG_BLOCK(
		game_medal_block,
		"game_medal_block",
		s_game_medal_definition::k_maximum_game_medal_definitions,
		"s_game_medal_definition",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		GAME_MEDAL_BLOCK_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_string_id, "description" },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 8 },
		{ _field_legacy, _field_real, "scale x" },
		{ _field_legacy, _field_real, "scale y" },
		{ _field_legacy, _field_char_integer, "sequence index" },
		{ _field_legacy, _field_char_enum, "medal class", &medal_class_enum },
		{ _field_legacy, _field_byte_integer, "tier index#the tier that this medal belongs to" },
		{ _field_legacy, _field_pad, "PAD1", 1 },
		{ _field_legacy, _field_short_integer, "override point value#if greater than zero, this point value will be awarded to players instead of the tier\'s point value" },
		{ _field_legacy, _field_pad, "PAD1", 2 },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 7 },
		{ _field_short_integer, "sequence index" },
		{ _field_char_enum, "medal class", &medal_class_enum },
		FIELD_PAD("PAD1", nullptr, FIELD_FLAG_NONE, 1),
		{ _field_long_integer, "ordnance points", "The number of ordnance points that are awarded to the player when they earn this medal." },
		{ _field_byte_integer, "ordnance multiplier", "The ordnance multiplier to add to players ordnance multiplier when they earn this medal." },
		{ _field_byte_integer, "tier index", "the tier that this medal belongs to" },
		{ _field_short_integer, "override point value", "if greater than zero, this point value will be awarded to players instead of the tier's point value" },

		{ _field_terminator }
	};

	#define GAME_MEDAL_GLOBALS_STRUCT_DEFINITION_ID { 0x32C934ED, 0x6C6B4352, 0xB86FFA53, 0x76D54461 }
	TAG_STRUCT(
		game_medal_globals_struct_definition,
		"game_medal_globals_struct_definition",
		"s_game_medal_globals",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		GAME_MEDAL_GLOBALS_STRUCT_DEFINITION_ID)
	{
		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_block, "tiers", &gameMedalTiers_block },

		{ _field_block, "medals", &game_medal_block },
		{ _field_terminator }
	};

	STRINGS(medal_class_enum)
	{
		"special",
		"role spree",
		"spree",
		"multikill",
		"objectives",
		"circumstance",
		"finesse"
	};
	STRING_LIST(medal_class_enum, medal_class_enum_strings, _countof(medal_class_enum_strings));

} // namespace macaque

} // namespace blofeld

