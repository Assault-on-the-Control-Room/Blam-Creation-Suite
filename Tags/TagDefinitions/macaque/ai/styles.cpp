#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		style_group,
		STYLE_TAG,
		nullptr,
		INVALID_TAG,
		style_block );

	TAG_BLOCK_FROM_STRUCT(
		style_block,
		"style_block",
		1,
		style_struct_definition);

	#define STYLE_PALETTE_BLOCK_ID { 0x3D8C9FE3, 0x023D40AE, 0x968E5BAF, 0x3C164F2B }
	TAG_BLOCK(
		style_palette_block,
		"style_palette_block",
		50,
		"style_palette_entry",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		STYLE_PALETTE_BLOCK_ID)
	{
		{ _field_tag_reference, "reference", FIELD_FLAG_INDEX, &style_reference$2 },
		{ _field_terminator }
	};

	#define BEHAVIOR_NAMES_BLOCK_ID { 0x3B1809CC, 0x71BE4135, 0xA509EB0E, 0x42358E50 }
	TAG_BLOCK(
		behavior_names_block,
		"behavior_names_block",
		k_maximum_behavior_count,
		"style_behavior_name",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		BEHAVIOR_NAMES_BLOCK_ID)
	{
		{ _field_string, "behavior name", FIELD_FLAG_READ_ONLY | FIELD_FLAG_INDEX },
		{ _field_terminator }
	};

	#define STYLE_STRUCT_DEFINITION_ID { 0xAC59B7DE, 0x455644C8, 0x9268F008, 0x8B74CD54 }
	TAG_STRUCT(
		style_struct_definition,
		"style_struct_definition",
		"style_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		STYLE_STRUCT_DEFINITION_ID)
	{
		{ _field_string, "name", FIELD_FLAG_INDEX },
		FIELD_EXPLANATION("Combat status decay options", nullptr, FIELD_FLAG_NONE, "Controls how combat status is allowed to be automatically reduced in the absence of combat stimuli. \'Latch at X\' means that once the level of x is attained (and/or surpassed) the combat status never falls below it. Not applicable when style is applied to a character tag."),
		{ _field_enum, "Combat status decay options", &combat_status_enum },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach },
		FIELD_PAD("hghq", nullptr, FIELD_FLAG_NONE, 2),

		{ _field_legacy, _field_version_less, _engine_type_haloreach },
		{ _field_legacy, _field_short_integer, "@unknown" },

		FIELD_EXPLANATION("Style Behavior Control", nullptr, FIELD_FLAG_NONE, "Check the appropriate box to turn on/off the given behavior"),
		{ _field_long_flags, "Style control", &style_control_flags },
		{ _field_long_flags, "Behaviors1", &behavior_set1, _field_id_dumb },
		{ _field_long_flags, "Behaviors2", &behavior_set2, _field_id_dumb },
		{ _field_long_flags, "Behaviors3", &behavior_set3, _field_id_dumb },
		{ _field_long_flags, "Behaviors4", &behavior_set4, _field_id_dumb },
		{ _field_long_flags, "Behaviors5", &behavior_set5, _field_id_dumb },
		{ _field_long_flags, "Behaviors6", &behavior_set6, _field_id_dumb },
		{ _field_long_flags, "Behaviors7", &behavior_set7, _field_id_dumb },
		{ _field_long_flags, "Behaviors8", &behavior_set8, _field_id_dumb },
		{ _field_block, "Special movement", &special_movement_block },
		{ _field_block, "Behavior list", &behavior_names_block },
		{ _field_terminator }
	};

	STRINGS(behavior_set1)
	{
		"------GENERAL------",
		"root",
		"null",
		"null_discrete",
		"interruptable_control",
		"obey",
		"guard",
		"ready",
		"smash_obstacle",
		"destroy_obstacle",
		"perch",
		"blind_panic",
		"combat",
		"interact object behavior",
		"interact object impulse",
		"squad_patrol_behavior",
		"movement_plan_cover_impulse",
		"------BROKEN------",
		"broken behavior",
		"huddle impulse",
		"huddle behavior",
		"kamikaze behavior",
		"broken kamikaze impulse",
		"broken berserk impulse",
		"broken flee impulse",
		"broken scatter impulse",
		"------ENGAGE------",
		"equipment",
		"equipment active camo",
		"engage",
		"fight",
		"fight_circle"
	};
	STRING_LIST(behavior_set1, behavior_set1_strings, _countof(behavior_set1_strings));

	STRINGS(behavior_set2)
	{
		"hamstring_charge",
		"gravity_jump",
		"fight_positioning",
		"melee_charge",
		"unreachable leap charge",
		"melee_leaping_charge",
		"melee sync attack",
		"grenade_impulse",
		"object throw impulse",
		"anti_vehicle_grenade",
		"stalk",
		"berserk_wander_impulse",
		"stalker_camo_control",
		"leader_abandoned_berserk",
		"unassailable grenade impulse",
		"suppressing_fire_vehicle",
		"demand_charge_impulse",
		"------BERSERK------",
		"shield_depleted_berserk",
		"last_man_berserk",
		"stuck_with_grenade_berserk",
		"surprise_berserk",
		"proximity_berserk",
		"stuck_with_grenade_balling",
		"------PRESEARCH------",
		"presearch",
		"uncover",
		"destroy_cover",
		"suppressing fire",
		"grenade_uncover",
		"leap_on_cover",
		"------LEADER------"
	};
	STRING_LIST(behavior_set2, behavior_set2_strings, _countof(behavior_set2_strings));

	STRINGS(behavior_set3)
	{
		"engage_sync",
		"------SEARCH------",
		"search",
		"find_pursuit",
		"investigate",
		"------SELF-DEFENSE------",
		"self_preservation",
		"cover",
		"avoid",
		"evasion_impulse",
		"dive_impulse",
		"juke_impulse",
		"danger cover impulse",
		"danger crouch impulse",
		"proximity_melee",
		"proximity_self_preservation",
		"unreachable_enemy_cover",
		"unassailable_enemy_cover",
		"scary_target_cover",
		"group_emerge",
		"kungfu_cover",
		"------RETREAT------",
		"retreat",
		"retreat_grenade",
		"flee",
		"flee_target",
		"cower",
		"low_shield_retreat",
		"scary_target_retreat",
		"leader_dead_retreat",
		"peer_dead_retreat",
		"danger_retreat"
	};
	STRING_LIST(behavior_set3, behavior_set3_strings, _countof(behavior_set3_strings));

	STRINGS(behavior_set4)
	{
		"proximity_retreat",
		"charge when cornered",
		"surprise_retreat",
		"overheated_weapon_retreat",
		"------AMBUSH------",
		"ambush",
		"coordinated_ambush",
		"proximity_ambush",
		"vulnerable_enemy_ambush",
		"nowhere_to_run_ambush",
		"------VEHICLE------",
		"enter_vehicle",
		"enter_friendly_vehicle",
		"switch_to_friendly_vehicle",
		"vehicle_enter_impulse",
		"vehicle_entry_engage_impulse",
		"vehicle_board",
		"vehicle_fight",
		"vehicle_fight@boost",
		"vehicle_charge",
		"vehicle_ram_behavior",
		"vehicle_cover",
		"damage_vehicle_cover",
		"exposed_rear_cover_impulse",
		"player_endagered_cover_impulse",
		"vehicle_avoid",
		"vehicle_pickup",
		"vehicle_exit_impulse",
		"danger_vehicle_exit_impulse",
		"vehicle_flip_impulse",
		"vehicle_flip",
		"vehicle_turtle"
	};
	STRING_LIST(behavior_set4, behavior_set4_strings, _countof(behavior_set4_strings));

	STRINGS(behavior_set5)
	{
		"vehicle_engage_patrol_impulse",
		"vehicle_engage_wander_impulse",
		"vehicle keep station",
		"------POSTCOMBAT------",
		"postcombat",
		"post_postcombat",
		"check_friend",
		"shoot_corpse",
		"postcombat_approach",
		"------ALERT------",
		"alert",
		"------IDLE------",
		"idle",
		"wander behavior",
		"flight_wander",
		"patrol",
		"fall_sleep",
		"------BUGGERS------",
		"bugger_ground_uncover",
		"------ENGINEER------",
		"engineer_control",
		"engineer_control@slave",
		"engineer_control@free",
		"engineer_control@equipment",
		"engineer_explode",
		"engineer_broken_detonation",
		"boost_allies",
		"------SCARAB------",
		"scarab_root",
		"scarab_cure_isolation",
		"scarab_combat",
		"scarab_fight"
	};
	STRING_LIST(behavior_set5, behavior_set5_strings, _countof(behavior_set5_strings));

	STRINGS(behavior_set6)
	{
		"scarab_target_lock",
		"scarab_search",
		"scarab_search_pause",
		"------FLYING------",
		"flying_root",
		"flying_idle",
		"flying_combat",
		"flying_approach",
		"flying_cover",
		"flying_evade",
		"flying_retreat",
		"flying_tail",
		"flying_strafe",
		"flying_dodge_impulse",
		"------LOD------",
		"lod_root",
		"lod_idle",
		"lod_combat",
		"------ATOMS------",
		"go_to",
		"------ACTIVITIES------",
		"activity",
		"posture",
		"activity_default",
		"------SPECIAL------",
		"formation",
		"grunt scared by elite",
		"cure_isolation",
		"deploy_turret",
		"control",
		"arrange sync action",
		"------MOSH------"
	};
	STRING_LIST(behavior_set6, behavior_set6_strings, _countof(behavior_set6_strings));

	STRINGS(behavior_set7)
	{
		"ctf",
		"koth",
		"assault",
		"balling_attack",
		"balling_leap_attack",
		"protect allies",
		"activate item",
		"collect projectiles",
		"resurrect ally",
		"give birth",
		"advance",
		"teleport advance",
		"leap advance",
		"follow impulse (pack)",
		"follow (pack)",
		"stalk (pack)",
		"fight (pack)",
		"command charge impulse",
		"puppet",
		"shard spawn"
	};
	STRING_LIST(behavior_set7, behavior_set7_strings, _countof(behavior_set7_strings));

	STRING_LIST(behavior_set8, empty_string_list, 0);

	STRINGS(style_control_flags)
	{
		"New behaviors default to ON"
	};
	STRING_LIST(style_control_flags, style_control_flags_strings, _countof(style_control_flags_strings));

	STRINGS(combat_status_enum$2)
	{
		"Latch at Idle",
		"Latch at Alert",
		"Latch at Combat"
	};
	STRING_LIST(combat_status_enum$2, combat_status_enum$2_strings, _countof(combat_status_enum$2_strings));

} // namespace macaque

} // namespace blofeld

