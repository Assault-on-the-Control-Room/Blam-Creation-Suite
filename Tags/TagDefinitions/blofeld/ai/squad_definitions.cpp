#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP(squad_template, SQUAD_TEMPLATE_TAG)
	{
		{ _field_string_id, "name^" },
		{ _field_block, "cell templates", &cell_template_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(squad_groups_block, k_max_squad_groups_per_map)
	{
		{ _field_string, "name^" },
		{ _field_short_block_index, "parent" },
		{ _field_short_block_index, "initial objective" },
		{ _field_pad, "soon to be an initial task", 2 },
		{ _field_short_block_index, "editor folder!" },
		{ _field_terminator }
	};

	TAG_BLOCK(patrol_point_block, 32)
	{
		{ _field_custom_short_block_index, "point^" },
		{ _field_word_flags, "flags", &patrol_point_flags },
		{ _field_real, "delay:seconds#how long the AI should pause at this point" },
		{ _field_real, "angle:degrees#the angle-from-forward that the AI can pick at this point" },
		{ _field_string_id, "activity name" },
		{ _field_enum, "activity!", &g_activity_enum },
		{ _field_short_integer, "activity variant!" },
		{ _field_string_id, "command script" },
		{ _field_short_integer, "command script index*~" },
		{ _field_pad, "post-command-script", 2 },
		{ _field_terminator }
	};

	TAG_BLOCK(spawn_formation_block, k_maximum_spawn_formations_per_squad)
	{
		{ _field_struct, "place on", &ai_spawn_conditions_struct_struct_definition },
		{ _field_string_id, "name^" },
		{ _field_real_point_3d, "position" },
		{ _field_struct, "scenario_bsp_nav", &scenario_bsp_nav_struct_definition }, // #CUSTOM
		{ _field_real_euler_angles_2d, "facing (yaw, pitch):degrees" },
		{ _field_real, "roll" },
		{ _field_string_id, "formation" },
		{ _field_real, "initial movement distance#before doing anything else, the actor will travel the given distance in its forward direction" },
		{ _field_enum, "initial movement mode", &actor_movement_modes },
		{ _field_short_integer, "placement script index!~" },
		{ _field_string_id, "placement script{Placement script}" },
		{ _field_string_id, "activity name" },
		{ _field_string_id, "movement set" },
		{ _field_custom_short_block_index, "point set" },
		{ _field_enum, "patrol mode", &patrol_mode_enum },
		{ _field_block, "points", &patrol_point_block_block },

		{ _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_byte_flags, "flags", &spawn_formation_flags },
		{ _field_pad, "post-flags-pad", 3 },

		{ _field_terminator }
	};

	TAG_BLOCK(spawn_points_block, k_maximum_spawn_points_per_squad)
	{
		{ _field_struct, "place on", &ai_spawn_conditions_struct_struct_definition },
		{ _field_string_id, "name^" },
		{ _field_custom_short_block_index, "cell" },
		{ _field_pad, "post-cell-index-pad", 2 },
		{ _field_real_point_3d, "position" },
		{ _field_struct, "scenario_bsp_nav", &scenario_bsp_nav_struct_definition }, // #CUSTOM
		{ _field_real_euler_angles_2d, "facing (yaw, pitch):degrees" },
		{ _field_real, "roll" },
		{ _field_word_flags, "flags", &starting_location_flags },
		{ _field_short_block_index, "character type" },
		{ _field_short_block_index, "initial weapon" },
		{ _field_short_block_index, "initial secondary weapon" },
		{ _field_short_block_index, "initial equipment" },
		{ _field_short_block_index, "vehicle type" },
		{ _field_enum, "seat type", &ai_placement_seat_preference_enum },
		{ _field_enum, "grenade type", &global_ai_grenade_type_enum },
		{ _field_short_integer, "swarm count#number of cretures in swarm if a swarm is spawned at this location" },
		{ _field_pad, "post-swarm-count-pad", 2 },
		{ _field_string_id, "actor variant name" },
		{ _field_string_id, "vehicle variant name" },
		{ _field_string_id, "voice designator" },
		{ _field_real, "initial movement distance#before doing anything else, the actor will travel the given distance in its forward direction" },
		{ _field_enum, "initial movement mode", &actor_movement_modes },
		{ _field_short_block_index, "emitter vehicle" },
		{ _field_short_block_index, "giant body" },
		{ _field_short_block_index, "biped body" },
		{ _field_string_id, "placement script{Placement script}" },
		{ _field_short_integer, "placement script index!~" },
		{ _field_pad, "post-placement-script-pad", 2 },
		{ _field_string_id, "activity name" },
		{ _field_string_id, "movement set" },
		{ _field_custom_short_block_index, "point set" },
		{ _field_enum, "patrol mode", &patrol_mode_enum },
		{ _field_block, "points", &patrol_point_block_block },

		{ _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_short_block_index, "vehicle body" },
		{ _field_pad, "post-vehicle_index-pad", 2 },

		{ _field_terminator }
	};

	TAG_BLOCK(character_palette_choice_block, k_maximum_palette_choices)
	{
		{ _field_struct, "place on", &ai_spawn_conditions_struct_struct_definition },
		{ _field_short_block_index, "character type^" },
		{ _field_custom },
		{ _field_short_integer, "chance" },
		{ _field_terminator }
	};

	TAG_BLOCK(weapon_palette_choice_block, k_maximum_palette_choices)
	{
		{ _field_struct, "place on", &ai_spawn_conditions_struct_struct_definition },
		{ _field_short_block_index, "weapon type^" },
		{ _field_custom },
		{ _field_short_integer, "chance" },
		{ _field_terminator }
	};

	TAG_BLOCK(equipment_palette_choice_block, k_maximum_palette_choices)
	{
		{ _field_struct, "place on", &ai_spawn_conditions_struct_struct_definition },
		{ _field_short_block_index, "equipment type^" },
		{ _field_custom },
		{ _field_short_integer, "chance" },
		{ _field_terminator }
	};

	TAG_BLOCK(cell_block, k_maximum_cells_per_squad)
	{
		{ _field_explanation, "Character Build", "Specify the distribution of characters and weapons in the cell sub-folders" },
		{ _field_string_id, "name^" },
		{ _field_struct, "place on", &ai_spawn_conditions_struct_struct_definition },
		{ _field_short_integer, "normal diff count#initial number of actors on normal difficulty" },
		{ _field_enum, "major upgrade", &major_upgrade_enum },
		{ _field_block, "character type", &character_palette_choice_block_block },
		{ _field_block, "initial weapon", &weapon_palette_choice_block_block },
		{ _field_block, "initial secondary weapon", &weapon_palette_choice_block_block },
		{ _field_block, "initial equipment", &equipment_palette_choice_block_block },
		{ _field_enum, "grenade type", &global_ai_grenade_type_enum },
		{ _field_short_block_index, "vehicle type" },
		{ _field_string_id, "vehicle variant" },
		{ _field_string_id, "Placement script" },
		{ _field_short_integer, "placement script index!~" },
		{ _field_pad, "plsc", 2 },
		{ _field_string_id, "activity name" },
		{ _field_string_id, "movement set" },
		{ _field_custom_short_block_index, "point set" },
		{ _field_enum, "patrol mode", &patrol_mode_enum },
		{ _field_block, "points!", &patrol_point_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(squads_block, k_maximum_squads_per_map)
	{
		{ _field_custom },
		{ _field_string, "name^" },
		{ _field_long_flags, "flags", &squad_flags },
		{ _field_enum, "team", &ai_team_enum },
		{ _field_short_block_index, "parent" },
		{ _field_short_block_index, "initial zone" },
		{ _field_short_block_index, "initial objective" },
		{ _field_custom_short_block_index, "initial task" },
		{ _field_short_block_index, "editor folder!" },
		{ _field_block, "spawn formations!", &spawn_formation_block_block },
		{ _field_block, "spawn points!", &spawn_points_block_block },
		{ _field_long_enum, "wave placement filter#Filter which squads in Firefight waves can be spawned into this squad", &wave_placement_filter_enum },
		{ _field_string_id, "template" },
		{ _field_long_integer, "squad template index!" },
		{ _field_custom },
		{ _field_struct, "designer", &squad_definition_internal_struct_struct_definition },
		{ _field_struct, "templated*!", &squad_definition_internal_struct_struct_definition },
		{ _field_terminator }
	};

	TAG_BLOCK(character_ref_choice_block, k_maximum_palette_choices)
	{
		{ _field_struct, "place on", &ai_spawn_conditions_struct_struct_definition },
		{ _field_tag_reference, "character type^", &character_reference$7 },
		{ _field_short_integer, "chance" },
		{ _field_pad, "post-chance", 2 },
		{ _field_terminator }
	};

	TAG_BLOCK(weapon_ref_choice_block, k_maximum_palette_choices)
	{
		{ _field_struct, "place on", &ai_spawn_conditions_struct_struct_definition },
		{ _field_tag_reference, "weapon type^", &weapon_reference$8 },
		{ _field_short_integer, "chance" },
		{ _field_pad, "post-chance", 2 },
		{ _field_terminator }
	};

	TAG_BLOCK(equipment_ref_choice_block, k_maximum_palette_choices)
	{
		{ _field_struct, "place on", &ai_spawn_conditions_struct_struct_definition },
		{ _field_tag_reference, "equipment type^", &equipment_reference$4 },
		{ _field_short_integer, "chance" },
		{ _field_pad, "post-chance", 2 },
		{ _field_terminator }
	};

	TAG_BLOCK(cell_template_block, k_maximum_cells_per_squad)
	{
		{ _field_string_id, "name^" },
		{ _field_struct, "place on", &ai_spawn_conditions_struct_struct_definition },
		{ _field_short_integer, "normal diff count#initial number of actors on normal difficulty" },
		{ _field_enum, "major upgrade", &major_upgrade_enum },
		{ _field_explanation, "Character Build", "Specify the distribution of characters and weapons in the following blocks" },
		{ _field_block, "character type", &character_ref_choice_block_block },
		{ _field_block, "initial weapon", &weapon_ref_choice_block_block },
		{ _field_block, "initial secondary weapon", &weapon_ref_choice_block_block },
		{ _field_block, "initial equipment", &equipment_ref_choice_block_block },
		{ _field_enum, "grenade type", &global_ai_grenade_type_enum },
		{ _field_pad, "post-grenade", 2 },
		{ _field_tag_reference, "vehicle type", &vehicle_reference$3 },
		{ _field_string_id, "vehicle variant" },
		{ _field_string_id, "activity name" },
		{ _field_terminator }
	};

	TAG_STRUCT(squad_definition_internal_struct)
	{
		{ _field_block, "cells", &cell_block_block },
		{ _field_terminator }
	};

	STRINGS(patrol_point_flags)
	{
		"single use"
	};
	STRING_LIST(patrol_point_flags, patrol_point_flags_strings, _countof(patrol_point_flags_strings));

	STRINGS(patrol_mode_enum)
	{
		"ping-pong",
		"loop",
		"random"
	};
	STRING_LIST(patrol_mode_enum, patrol_mode_enum_strings, _countof(patrol_mode_enum_strings));

	STRINGS(starting_location_flags)
	{
		"infection form explode",
		"n/a",
		"always place",
		"initially hidden",
		"vehicle destroyed when no driver",
		"vehicle open",
		"actor surface emerge",
		"actor surface emerge auto",
		"actor surface emerge upwards"
	};
	STRING_LIST(starting_location_flags, starting_location_flags_strings, _countof(starting_location_flags_strings));

	STRINGS(ai_placement_seat_preference_enum)
	{
		"DEFAULT",
		"passenger",
		"gunner",
		"driver",
		"small cargo",
		"large cargo",
		"NO driver",
		"NO vehicle"
	};
	STRING_LIST(ai_placement_seat_preference_enum, ai_placement_seat_preference_enum_strings, _countof(ai_placement_seat_preference_enum_strings));

	STRINGS(actor_movement_modes)
	{
		"default",
		"climbing",
		"flying"
	};
	STRING_LIST(actor_movement_modes, actor_movement_modes_strings, _countof(actor_movement_modes_strings));

	STRINGS(major_upgrade_enum)
	{
		"normal",
		"few",
		"many",
		"none",
		"all"
	};
	STRING_LIST(major_upgrade_enum, major_upgrade_enum_strings, _countof(major_upgrade_enum_strings));

	STRINGS(squad_flags)
	{
		"unused",
		"blind",
		"deaf",
		"braindead",
		"initially placed",
		"units not enterable by player",
		"fireteam absorber",
		"squad is runtime(DO NOT USE)!",
		"no wave spawn"
	};
	STRING_LIST(squad_flags, squad_flags_strings, _countof(squad_flags_strings));

	STRINGS(spawn_formation_flags)
	{
		"no vertical offset for flying"
	};
	STRING_LIST(spawn_formation_flags, spawn_formation_flags_strings, _countof(spawn_formation_flags_strings));

	STRINGS(g_activity_enum)
	{
		"none",
		"patrol",
		"stand",
		"crouch",
		"stand_drawn",
		"crouch_drawn",
		"combat",
		"backup",
		"guard",
		"guard_crouch",
		"guard_wall",
		"typing",
		"kneel",
		"gaze",
		"poke",
		"sniff",
		"track",
		"watch",
		"examine",
		"sleep",
		"at_ease",
		"cower",
		"tai_chi",
		"pee",
		"doze",
		"eat",
		"medic",
		"work",
		"cheering",
		"injured",
		"captured"
	};
	STRING_LIST(g_activity_enum, g_activity_enum_strings, _countof(g_activity_enum_strings));

	STRINGS(ai_team_enum)
	{
		"default",
		"player",
		"human",
		"covenant",
		"brute",
		"mule",
		"spare",
		"covenant_player",
		"forerunner"
	};
	STRING_LIST(ai_team_enum, ai_team_enum_strings, _countof(ai_team_enum_strings));

} // namespace blofeld

