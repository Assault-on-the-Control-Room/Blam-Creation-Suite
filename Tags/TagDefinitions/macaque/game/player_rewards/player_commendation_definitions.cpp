#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		commendation_aggregator_list_group,
		COMMENDATION_AGGREGATOR_LIST_TAG,
		nullptr,
		INVALID_TAG,
		commendation_aggregator_list_block );

	TAG_GROUP(
		commendation_globals_definition_group,
		COMMENDATION_GLOBALS_DEFINITION_TAG,
		nullptr,
		INVALID_TAG,
		commendation_globals_definition_block );

	TAG_BLOCK_FROM_STRUCT(
		commendation_aggregator_list_block,
		"commendation_aggregator_list_block",
		1,
		commendation_aggregator_list_struct_definition);

	TAG_BLOCK_FROM_STRUCT(
		commendation_globals_definition_block,
		"commendation_globals_definition_block",
		1,
		commendation_globals_definition_struct_definition);

	#define COMMENDATIONAGGREGATOR_ID { 0xEE1F5591, 0x7C05414B, 0x97F89953, 0x90717D05 }
	TAG_BLOCK(
		commendationAggregator_block,
		"commendationAggregator",
		CommendationAggregator::k_commendationAggregatorMaxCount,
		"CommendationAggregator",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		COMMENDATIONAGGREGATOR_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_string_id, "description text" },
		{ _field_block, "rewards", &commendationRewardBlock_block },
		{ _field_char_integer, "sequence index" },
		FIELD_PAD("CA_PAD1", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_short_integer, "medal sprite index" },
		{ _field_short_integer, "game type sprite index" },
		{ _field_block, "prerequisites", MAKE_OLD_NAMES("contributing commendations"), &commendationAggregatorDependent_block },
		{ _field_terminator }
	};

	#define COMMENDATIONREWARDBLOCK_ID { 0x37141A9A, 0x96D6477D, 0x9A77CFD4, 0xF2005522 }
	TAG_BLOCK(
		commendationRewardBlock_block,
		"commendationRewardBlock",
		eCT_count,
		"CommendationReward",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		COMMENDATIONREWARDBLOCK_ID)
	{
		{ _field_char_enum, "currency type", "Type of currency given by this reward.", &currencyTypeEnumDefinition },
		FIELD_PAD("CRB_PAD1", nullptr, FIELD_FLAG_NONE, 1),
		{ _field_short_integer, "reward value" },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(
		commendationAggregatorDependent_block,
		"commendationAggregatorDependent",
		CommendationAggregatorDependent::k_commendationDependentMaxCount,
		commendationAggregatorDependent_struct);

	#define COMMENDATIONBLOCK_ID { 0x0610838D, 0xCA384AEB, 0x9A5F622D, 0xF2945CBC }
	TAG_BLOCK(
		commendationBlock_block,
		"commendationBlock",
		CommendationDefinition::k_maximumCommendationDefinitions,
		"CommendationDefinition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		COMMENDATIONBLOCK_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_string_id, "description" },

		{ _field_legacy, _field_version_equal, _engine_type_haloreach, 21 }, // #TODO: Research these fields. Based on assembly's plugins for now ew.
		{ _field_legacy, _field_long_integer, "credits earned before silver" },
		{ _field_legacy, _field_long_integer, "credits earned after silver" },
		{ _field_legacy, _field_short_integer, "unknown@" },
		{ _field_legacy, _field_char_integer, "sprite index" },
		{ _field_legacy, _field_char_integer, "unknown@" },
		{ _field_legacy, _field_short_integer, "count required for iron" },
		{ _field_legacy, _field_short_integer, "count required for bronze" },
		{ _field_legacy, _field_short_integer, "count required for silver" },
		{ _field_legacy, _field_short_integer, "count required for gold" },
		{ _field_legacy, _field_short_integer, "count required for onyx" },
		{ _field_legacy, _field_short_integer, "count required for MAX" },
		{ _field_legacy, _field_long_integer, "unknown@" },
		{ _field_legacy, _field_short_integer, "credits awarded for iron" },
		{ _field_legacy, _field_short_integer, "credits awarded for bronze" },
		{ _field_legacy, _field_short_integer, "credits awarded for silver" },
		{ _field_legacy, _field_short_integer, "credits awarded for gold" },
		{ _field_legacy, _field_short_integer, "credits awarded for onyx" },
		{ _field_legacy, _field_short_integer, "credits awarded for MAX" },
		{ _field_legacy, _field_short_integer, "unknown@" },
		{ _field_legacy, _field_char_enum, "category", &commendationCategoryReachEnum },
		{ _field_legacy, _field_pad, "pad", 1 },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 12 },
		{ _field_byte_flags, "flags", &commendationFlags },
		FIELD_PAD("CB_PAD0", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_char_enum, "category", &commendationCategoryEnum },
		{ _field_char_enum, "subcategory", &commendationSubcategoryEnum },
		{ _field_char_integer, "sequence index" },
		FIELD_PAD("CB_PAD1", nullptr, FIELD_FLAG_NONE, 1),
		{ _field_short_integer, "medal sprite index" },
		{ _field_short_integer, "game type sprite index" },
		FIELD_CUSTOM("unlock prerequisites", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_struct, "prerequisites", &PurchasePrerequisitesUnifiedDefinitionBlock },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		{ _field_block, "levels", &commendationLevelBlock_block },

		{ _field_terminator }
	};

	#define COMMENDATIONLEVELBLOCK_ID { 0xD0F61385, 0xF52B4A99, 0xB0178B54, 0x95CB7360 }
	TAG_BLOCK(
		commendationLevelBlock_block,
		"commendationLevelBlock",
		CommendationLevel::k_maximumCommendationLevels,
		"CommendationLevel",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		COMMENDATIONLEVELBLOCK_ID)
	{
		{ _field_string_id, "level name", FIELD_FLAG_INDEX },
		{ _field_short_integer, "progress ticks to level", "number of ticks to reach this level" },
		{ _field_short_integer, "progress display interval", "number of ticks between displaying progress toast; 0=never display progress, 1=display every tick, 2=every other, etc." },
		{ _field_string_id, "achievement" },
		{ _field_block, "level up rewards", "rewards given for reaching this level", &commendationRewardBlock_block },
		{ _field_terminator }
	};

	#define COMMENDATION_AGGREGATOR_LIST_STRUCT_DEFINITION_ID { 0x74E71545, 0x00054456, 0xA4FC7176, 0x58FE61F2 }
	TAG_STRUCT(
		commendation_aggregator_list_struct_definition,
		"commendation_aggregator_list_struct_definition",
		"CommendationAggregatorList",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		COMMENDATION_AGGREGATOR_LIST_STRUCT_DEFINITION_ID)
	{
		{ _field_block, "lists", &commendationAggregator_block },
		{ _field_terminator }
	};

	#define COMMENDATION_GLOBALS_DEFINITION_STRUCT_DEFINITION_ID { 0xCB5F3608, 0xE8F44DE4, 0x8D3DAD05, 0x61C42080 }
	TAG_STRUCT(
		commendation_globals_definition_struct_definition,
		"commendation_globals_definition_struct_definition",
		"s_commendation_globals_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		COMMENDATION_GLOBALS_DEFINITION_STRUCT_DEFINITION_ID)
	{
		{ _field_tag_reference, "commendation aggregators", & Tag::Reference<struct CommendationAggregatorList>::s_defaultDefinition },

		{ _field_legacy, _field_version_equal, _engine_type_haloreach, 26 },
		{ _field_legacy, _field_char_integer, "unknown@" },
		{ _field_legacy, _field_char_integer, "unknown@" },
		{ _field_legacy, _field_char_integer, "unknown@" },
		{ _field_legacy, _field_char_integer, "unknown@" },
		{ _field_legacy, _field_short_integer, "unknown@" },
		{ _field_legacy, _field_short_integer, "unknown@" },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_real_argb_color, "color 1" },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_real_argb_color, "color 2" },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_real_argb_color, "color 3" },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_real_argb_color, "color 4" },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_real_argb_color, "unranked" },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_real_argb_color, "iron" },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_real_argb_color, "bronze" },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_real_argb_color, "silver" },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_real_argb_color, "gold" },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_real_argb_color, "onyx" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 4 },
		{ _field_tag_reference, "medal aggregators", &Tag::Reference<struct MedalCommendationAggregatorList>::s_defaultDefinition },
		{ _field_tag_reference, "commendation text", &global_multilingual_unicode_string_list_reference },
		{ _field_short_integer, "progress display time", nullptr, "seconds", MAKE_OLD_NAMES("progression display time") },
		{ _field_short_integer, "complete display time", nullptr, "seconds", MAKE_OLD_NAMES("callout display time") },

		{ _field_block, "commendations", &commendationBlock_block },
		{ _field_terminator }
	};

	#define COMMENDATIONAGGREGATORDEPENDENT_STRUCT_ID { 0x75C2D96E, 0x84EA4CC2, 0xBF5E2775, 0xB36E1BD7 }
	TAG_STRUCT(
		commendationAggregatorDependent_struct,
		"commendationAggregatorDependent_struct",
		"CommendationAggregatorDependent",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		COMMENDATIONAGGREGATORDEPENDENT_STRUCT_ID)
	{
		{ _field_char_enum, "type", &aggregatorDependentTypeEnumDefinition },
		FIELD_PAD("PAD1", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_terminator }
	};

	STRINGS(commendationCategoryEnum)
	{
		"default",
		"weapons",
		"ordnance",
		"enemies",
		"vehicles",
		"player",
		"armor abilities",
		"objectives",
		"customs",
		"UGC"
	};
	STRING_LIST(commendationCategoryEnum, commendationCategoryEnum_strings, _countof(commendationCategoryEnum_strings));

	STRINGS(commendationFlags)
	{
		"hidden"
	};
	STRING_LIST(commendationFlags, commendationFlags_strings, _countof(commendationFlags_strings));

	STRINGS(commendationSubcategoryEnum)
	{
		"default",
		"unsc",
		"covenant",
		"forerunner",
		"Covenant Enemy",
		"Forerunner Enemy",
		"Campaign",
		"War Games",
		"Slayer",
		"Regicide",
		"CTF",
		"Extraction",
		"Oddball",
		"King of the Hill",
		"Dominion",
		"Flood"
	};
	STRING_LIST(commendationSubcategoryEnum, commendationSubcategoryEnum_strings, _countof(commendationSubcategoryEnum_strings));

	STRINGS(aggregatorDependentTypeEnumDefinition)
	{
		"commendation",
		"aggregator"
	};
	STRING_LIST(aggregatorDependentTypeEnumDefinition, aggregatorDependentTypeEnumDefinition_strings, _countof(aggregatorDependentTypeEnumDefinition_strings));

} // namespace macaque

} // namespace blofeld

