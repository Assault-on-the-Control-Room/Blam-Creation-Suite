#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(commendation_aggregator_list, COMMENDATION_AGGREGATOR_LIST_TAG, commendation_aggregator_list_block_block );

	TAG_GROUP_FROM_BLOCK(commendation_globals_definition, COMMENDATION_GLOBALS_DEFINITION_TAG, commendation_globals_definition_block_block );

	TAG_BLOCK(commendationRewardBlock, eCT_count)
	{
		{ _field_char_enum, "currency type#Type of currency given by this reward.", &currencyTypeEnumDefinition },
		{ _field_pad, "CRB_PAD1", 1 },
		{ _field_short_integer, "reward value" },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(commendationAggregatorDependent, CommendationAggregatorDependent::k_commendationDependentMaxCount, commendationAggregatorDependent_struct_struct_definition );

	TAG_BLOCK(commendationAggregator, CommendationAggregator::k_commendationAggregatorMaxCount)
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

	TAG_BLOCK_FROM_STRUCT(commendation_aggregator_list_block, 1, commendation_aggregator_list_struct_definition_struct_definition );

	TAG_BLOCK(commendationLevelBlock, CommendationLevel::k_maximumCommendationLevels)
	{
		{ _field_string_id, "level name^" },
		{ _field_short_integer, "progress ticks to level#number of ticks to reach this level" },
		{ _field_short_integer, "progress display interval#number of ticks between displaying progress toast; 0=never display progress, 1=display every tick, 2=every other, etc." },
		{ _field_string_id, "achievement" },
		{ _field_block, "level up rewards#rewards given for reaching this level", &commendationRewardBlock_block },
		{ _field_terminator }
	};

	TAG_BLOCK(commendationBlock, CommendationDefinition::k_maximumCommendationDefinitions)
	{
		{ _field_string_id, "name^" },
		{ _field_string_id, "description" },

		{ _field_version_equal, _engine_type_haloreach, 13 }, // #TODO: Research these fields. Based on assembly's plugins for now ew.
		{ _field_long_integer, "credits earned before silver" },
		{ _field_long_integer, "credits earned after silver" },
		{ _field_short_integer, "unknown@" },
		{ _field_char_integer, "sprite index" },
		{ _field_char_integer, "unknown@" },
		{ _field_short_integer, "count required for iron" },
		{ _field_short_integer, "count required for bronze" },
		{ _field_short_integer, "count required for silver" },
		{ _field_short_integer, "count required for gold" },
		{ _field_short_integer, "count required for onyx" },
		{ _field_short_integer, "count required for MAX" },
		{ _field_long_integer, "unknown@" },
		{ _field_short_integer, "credits awarded for iron" },
		{ _field_short_integer, "credits awarded for bronze" },
		{ _field_short_integer, "credits awarded for silver" },
		{ _field_short_integer, "credits awarded for gold" },
		{ _field_short_integer, "credits awarded for onyx" },
		{ _field_short_integer, "credits awarded for MAX" },
		{ _field_short_integer, "unknown@" },
		{ _field_char_enum, "category", &commendationCategoryReachEnum },
		{ _field_pad, "pad", 1 },

		{ _field_version_greater, _engine_type_haloreach, 12 },
		{ _field_byte_flags, "flags", &commendationFlags },
		{ _field_pad, "CB_PAD0", 3 },
		{ _field_char_enum, "category", &commendationCategoryEnum },
		{ _field_char_enum, "subcategory", &commendationSubcategoryEnum },
		{ _field_char_integer, "sequence index" },
		{ _field_pad, "CB_PAD1", 1 },
		{ _field_short_integer, "medal sprite index" },
		{ _field_short_integer, "game type sprite index" },
		{ _field_custom, "unlock prerequisites" },
		{ _field_struct, "prerequisites", &PurchasePrerequisitesUnifiedDefinitionBlock_struct_definition },
		{ _field_custom },
		{ _field_block, "levels", &commendationLevelBlock_block },

		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(commendation_globals_definition_block, 1, commendation_globals_definition_struct_definition_struct_definition );

	TAG_STRUCT(commendation_aggregator_list_struct_definition)
	{
		{ _field_block, "lists", &commendationAggregator_block },
		{ _field_terminator }
	};

	TAG_STRUCT(commendationAggregatorDependent_struct)
	{
		{ _field_char_enum, "type", &aggregatorDependentTypeEnumDefinition },
		{ _field_pad, "PAD1", 3 },
		{ _field_string_id, "name^" },
		{ _field_terminator }
	};

	TAG_STRUCT(commendation_globals_definition_struct_definition)
	{
		{ _field_tag_reference, "commendation aggregators", &Tag::Reference<struct CommendationAggregatorList>::s_defaultDefinition },

		{ _field_version_equal, _engine_type_haloreach, 26 },
		{ _field_char_integer, "unknown@" },
		{ _field_char_integer, "unknown@" },
		{ _field_char_integer, "unknown@" },
		{ _field_char_integer, "unknown@" },
		{ _field_short_integer, "unknown@" },
		{ _field_short_integer, "unknown@" },
		{ _field_custom },
		{ _field_real_argb_color, "color 1" },
		{ _field_custom },
		{ _field_real_argb_color, "color 2" },
		{ _field_custom },
		{ _field_real_argb_color, "color 3" },
		{ _field_custom },
		{ _field_real_argb_color, "color 4" },
		{ _field_custom },
		{ _field_real_argb_color, "unranked" },
		{ _field_custom },
		{ _field_real_argb_color, "iron" },
		{ _field_custom },
		{ _field_real_argb_color, "bronze" },
		{ _field_custom },
		{ _field_real_argb_color, "silver" },
		{ _field_custom },
		{ _field_real_argb_color, "gold" },
		{ _field_custom },
		{ _field_real_argb_color, "onyx" },

		{ _field_version_greater, _engine_type_haloreach, 4 },
		{ _field_tag_reference, "medal aggregators", &Tag::Reference<struct MedalCommendationAggregatorList>::s_defaultDefinition },
		{ _field_tag_reference, "commendation text", &global_multilingual_unicode_string_list_reference },
		{ _field_short_integer, "progress display time{progression display time}:seconds" },
		{ _field_short_integer, "complete display time{callout display time}:seconds" },

		{ _field_block, "commendations", &commendationBlock_block },
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

	STRINGS(commendationCategoryReachEnum)
	{
		"Campaign",
		"Firefight",
		"Multiplayer"
	};
	STRING_LIST(commendationCategoryReachEnum, commendationCategoryReachEnum_strings, _countof(commendationCategoryReachEnum_strings));

	STRINGS(commendationFlags)
	{
		"hidden"
	};
	STRING_LIST(commendationFlags, commendationFlags_strings, _countof(commendationFlags_strings));

	STRINGS(commendationSubcategoryEnum) // #TODO: versioning for reach 
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

} // namespace blofeld

