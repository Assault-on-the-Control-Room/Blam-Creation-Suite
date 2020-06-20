#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(achievements, ACHIEVEMENTS_TAG, achievements_block_block );

	TAG_BLOCK(single_achievement_restricted_level_block, s_single_achivement_restricted_level_definition::k_maximum_count)
	{
		{ _field_string_id, "level name^#Compared to map name in scenario" },
		{ _field_terminator }
	};

	TAG_BLOCK(single_achievement_definition_block, k_maximum_achievements)
	{
		{ _field_string_id, "name^" },
		{ _field_char_enum, "type", &global_achievement_enum },
		{ _field_byte_flags, "difficulty", &global_campaign_difficulty_flags },
		{ _field_pad, "VJNOSNJER", 2 },
		{ _field_block, "restricted levels", &single_achievement_restricted_level_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(achievements_block, 1, achievements_struct_definition_struct_definition );

	TAG_STRUCT(achievements_struct_definition)
	{
		{ _field_block, "achievement", &single_achievement_definition_block_block },
		{ _field_terminator }
	};

	STRINGS(global_achievement_enum)
	{
		"m10_complete",
		"m20_complete",
		"m30_complete",
		"m60_complete",
		"m40_complete",
		"m70_complete",
		"m80_complete",
		"m90_complete",
		"camp_normal_complete",
		"camp_heroic_complete",
		"camp_legendary_complete",
		"camp_legendary_solo_complete",
		"camp_heroic_3skulls_complete",
		"camp_coop_mission_complete",
		"camp_coop_complete",
		"terminal_1",
		"terminal_all",
		"m10_special",
		"m20_special",
		"m30_special",
		"m60_special",
		"m40_special",
		"m70_special",
		"m80_special",
		"m90_special",
		"earn_rank_005",
		"earn_rank_020",
		"wargames_win_5",
		"wargames_win_20",
		"spartan_ops_mission_complete",
		"spartan_ops_episode1_complete",
		"spartan_ops_5episodes_complete",
		"spartan_ops_legendary_solo_mission_complete",
		"spops_1_special",
		"spops_2_special",
		"spops_3_special",
		"spops_4_special",
		"spops_5_special",
		"challenge_complete",
		"25_challenges_complete",
		"change_armor",
		"change_emblem",
		"change_tag",
		"change_pose",
		"save_custom_map",
		"save_custom_gametype",
		"save_screenshot",
		"save_filmclip",
		"upload_to_fileshare",
		// From this point onwards, we don't know what the actual strings are. The following are based on the strings in the tags.
		"dlc_achievement0",
		"dlc_achievement1",
		"dlc_achievement2",
		"dlc_achievement3",
		"dlc_achievement4",
		"dlc_achievement5",
		"dlc_achievement6",
		"dlc_achievement7",
		"dlc_achievement8",
		"dlc_achievement9",
		"unknown59",
		"unknown60",
		"unknown61",
		"unknown62",
		"unknown63",
		"unknown64",
		"unknown65",
		"unknown66",
		"unknown67",
		"unknown68",
		"unknown69",
		"unknown70",
		"unknown71",
		"unknown72",
		"unknown73",
		"unknown74",
		"unknown75",
		"unknown76",
		"unknown77",
		"unknown78",
		"unknown79",
		"unknown80",
		"unknown81",
		"unknown82",
		"unknown83",
		"unknown84",
		"unknown85",
		"unknown86",
		"unknown87",
		"unknown88",
		"reach_racer",
		"dj_brute",
		"siege_of_madrigal",
		"fly_pelican_phantom",
		"club_errera_reference",
		"moa_burgers",
		"secret_balcony",
		"teddy_bear",
		"hidden_banshees",
		"tribute_room",
		"complete_firefight_set",
		"skullamanjaro_matchmade",
		"bob_kill",
		"unknown102",
		"unknown103",
		"unknown104",
		"unknown105",
		"unknown106",
		"unknown107",
		"unknown108",
		"bxr_mining",
	};
	STRING_LIST(global_achievement_enum, global_achievement_enum_strings, _countof(global_achievement_enum_strings));

} // namespace blofeld

