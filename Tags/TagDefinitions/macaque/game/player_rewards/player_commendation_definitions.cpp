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
		COMMENDATIONAGGREGATOR_ID)
	{
		{ _field_string_id, "name^" },
		{ _field_string_id, "description text" },
		{ _field_block, "rewards", &commendationRewardBlock_block },
		{ _field_char_integer, "sequence index" },
		{ _field_pad, "CA_PAD1", 3 },
		{ _field_short_integer, "medal sprite index" },
		{ _field_short_integer, "game type sprite index" },
		{ _field_block, "prerequisites{contributing commendations}", &commendationAggregatorDependent_block },
		{ _field_terminator }
	};

	#define COMMENDATIONREWARDBLOCK_ID { 0x37141A9A, 0x96D6477D, 0x9A77CFD4, 0xF2005522 }
	TAG_BLOCK(
		commendationRewardBlock_block,
		"commendationRewardBlock",
		eCT_count,
		"CommendationReward",
		COMMENDATIONREWARDBLOCK_ID)
	{
		{ _field_char_enum, "currency type#Type of currency given by this reward.", &currencyTypeEnumDefinition },
		{ _field_pad, "CRB_PAD1", 1 },
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
		COMMENDATIONBLOCK_ID)
	{
		{ _field_string_id, "name^" },
		{ _field_string_id, "description" },
		{ _field_byte_flags, "flags", &commendationFlags },
		{ _field_pad, "CB_PAD0", 3 },
		{ _field_char_enum, "category", &commendationCategoryEnum },
		{ _field_char_enum, "subcategory", &commendationSubcategoryEnum },
		{ _field_char_integer, "sequence index" },
		{ _field_pad, "CB_PAD1", 1 },
		{ _field_short_integer, "medal sprite index" },
		{ _field_short_integer, "game type sprite index" },
		FIELD_CUSTOM("unlock prerequisites", _custom_field_function_group_begin),
		{ _field_struct, "prerequisites", &PurchasePrerequisitesUnifiedDefinitionBlock },
		FIELD_CUSTOM(nullptr, _custom_field_function_group_end),
		{ _field_block, "levels", &commendationLevelBlock_block },
		{ _field_terminator }
	};

	#define COMMENDATIONLEVELBLOCK_ID { 0xD0F61385, 0xF52B4A99, 0xB0178B54, 0x95CB7360 }
	TAG_BLOCK(
		commendationLevelBlock_block,
		"commendationLevelBlock",
		CommendationLevel::k_maximumCommendationLevels,
		"CommendationLevel",
		COMMENDATIONLEVELBLOCK_ID)
	{
		{ _field_string_id, "level name^" },
		{ _field_short_integer, "progress ticks to level#number of ticks to reach this level" },
		{ _field_short_integer, "progress display interval#number of ticks between displaying progress toast; 0=never display progress, 1=display every tick, 2=every other, etc." },
		{ _field_string_id, "achievement" },
		{ _field_block, "level up rewards#rewards given for reaching this level", &commendationRewardBlock_block },
		{ _field_terminator }
	};

	#define COMMENDATION_AGGREGATOR_LIST_STRUCT_DEFINITION_ID { 0x74E71545, 0x00054456, 0xA4FC7176, 0x58FE61F2 }
	TAG_STRUCT(
		commendation_aggregator_list_struct_definition,
		"commendation_aggregator_list_struct_definition",
		"CommendationAggregatorList",
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
		COMMENDATION_GLOBALS_DEFINITION_STRUCT_DEFINITION_ID)
	{
		{ _field_tag_reference, "commendation aggregators", &Tag::Reference<struct CommendationAggregatorList>::s_defaultDefinition },
		{ _field_tag_reference, "medal aggregators", &Tag::Reference<struct MedalCommendationAggregatorList>::s_defaultDefinition },
		{ _field_tag_reference, "commendation text", &global_multilingual_unicode_string_list_reference },
		{ _field_short_integer, "progress display time{progression display time}:seconds" },
		{ _field_short_integer, "complete display time{callout display time}:seconds" },
		{ _field_block, "commendations", &commendationBlock_block },
		{ _field_terminator }
	};

	#define COMMENDATIONAGGREGATORDEPENDENT_STRUCT_ID { 0x75C2D96E, 0x84EA4CC2, 0xBF5E2775, 0xB36E1BD7 }
	TAG_STRUCT(
		commendationAggregatorDependent_struct,
		"commendationAggregatorDependent_struct",
		"CommendationAggregatorDependent",
		COMMENDATIONAGGREGATORDEPENDENT_STRUCT_ID)
	{
		{ _field_char_enum, "type", &aggregatorDependentTypeEnumDefinition },
		{ _field_pad, "PAD1", 3 },
		{ _field_string_id, "name^" },
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

