#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define SQUAD_TEMPLATE_STRUCT_DEFINITION_ID { 0x1CFEC4FF, 0xE85F4CB8, 0x814D3264, 0x0784E278 }
	TAG_BLOCK(
		squad_template_block,
		"squad_template_block",
		1,
		"s_squad_template_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SQUAD_TEMPLATE_STRUCT_DEFINITION_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_block, "cell templates", &cell_template_block },
		{ _field_terminator }
	};

	TAG_GROUP(
		squad_template_group,
		SQUAD_TEMPLATE_TAG,
		nullptr,
		INVALID_TAG,
		squad_template_block );

	#define SQUAD_GROUPS_BLOCK_ID { 0x924C4B16, 0x87A04E62, 0x9A767F70, 0x3116A14F }
	TAG_BLOCK(
		squad_groups_block,
		"squad_groups_block",
		k_max_squad_groups_per_map,
		"squad_group_definition",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SQUAD_GROUPS_BLOCK_ID)
	{
		{ _field_string, "name", FIELD_FLAG_INDEX },
		{ _field_short_block_index, "parent", &squad_groups_block, _field_id_squad_template },
		{ _field_short_block_index, "initial objective", &objectives_block },
		FIELD_PAD("soon to be an initial task", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_short_block_index, "editor folder", FIELD_FLAG_UNKNOWN0, &g_scenario_editor_folder_block, _field_id_hide },
		{ _field_terminator }
	};

	#define SQUADS_BLOCK_STRUCT_ID { 0x650EB872, 0x6CC847B7, 0xB11BDACA, 0xAC519202 }
	TAG_BLOCK(
		squads_block,
		"squads_block",
		k_maximum_squads_per_map,
		"s_squad_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SQUADS_BLOCK_STRUCT_ID)
	{
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_filter),
		{ _field_string, "name", FIELD_FLAG_INDEX },
		{ _field_long_flags, "flags", &squad_flags },
		{ _field_enum, "team", &ai_team_enum },
		{ _field_short_block_index, "parent", &squad_groups_block, _field_id_squad_template },
		{ _field_short_block_index, "initial zone", &zone_block },
		{ _field_short_block_index, "initial objective", &objectives_block },
		{ _field_custom_short_block_index, "initial task" },
		{ _field_short_block_index, "editor folder", FIELD_FLAG_UNKNOWN0, &g_scenario_editor_folder_block, _field_id_hide },
		{ _field_block, "spawn formations", FIELD_FLAG_UNKNOWN0, &spawn_formation_block },
		{ _field_block, "spawn points", FIELD_FLAG_UNKNOWN0, &spawn_points_block },
		{ _field_long_enum, "wave placement filter", "Filter which squads in Firefight waves can be spawned into this squad", &wave_placement_filter_enum },
		{ _field_string_id, "template" },
		{ _field_long_integer, "squad template index", FIELD_FLAG_UNKNOWN0 },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_default),
		{ _field_struct, "designer", &squad_definition_internal_struct },
		{ _field_struct, "templated", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &squad_definition_internal_struct },
		{ _field_terminator }
	};

	#define SPAWN_FORMATION_BLOCK_STRUCT_ID { 0xE19AC3AA, 0x829343BD, 0x88085421, 0x54DAD4A3 }
	TAG_BLOCK(
		spawn_formation_block,
		"spawn_formation_block",
		k_maximum_spawn_formations_per_squad,
		"s_spawn_formation_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_WRITEABLE),
		SPAWN_FORMATION_BLOCK_STRUCT_ID)
	{
		{ _field_struct, "place on", &ai_spawn_conditions_struct },
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_real_point_3d, "position" },
		{ _field_custom_long_block_index, "packedKeyOffaceref", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_UNKNOWN3 },
		{ _field_custom_long_block_index, "navMeshUIDOffaceref", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_UNKNOWN3 },
		{ _field_real_euler_angles_2d, "facing (yaw, pitch)", nullptr, "degrees" },
		{ _field_real, "roll" },
		{ _field_string_id, "formation" },
		{ _field_real, "initial movement distance", "before doing anything else, the actor will travel the given distance in its forward direction" },
		{ _field_enum, "initial movement mode", &actor_movement_modes },
		{ _field_short_integer, "placement script index", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_UNKNOWN3 },
		{ _field_string_id, "placement script", MAKE_OLD_NAMES("Placement script"), _field_id_halo_script_block },
		{ _field_string_id, "activity name" },
		{ _field_string_id, "movement set" },
		{ _field_custom_short_block_index, "point set" },
		{ _field_enum, "patrol mode", &patrol_mode_enum },
		{ _field_block, "points", &patrol_point_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_byte_flags, "flags", &spawn_formation_flags },
		FIELD_PAD("post-flags-pad", nullptr, FIELD_FLAG_NONE, 3),

		{ _field_terminator }
	};

	#define PATROL_POINT_BLOCK_ID { 0xC516E1B0, 0x97634244, 0x80F25696, 0x88B435C1 }
	TAG_BLOCK(
		patrol_point_block,
		"patrol_point_block",
		32,
		"s_patrol_point",
		SET_UNKNOWN0 | SET_POSTPROCESS_RECURSIVELY | SET_IS_MEMCPYABLE | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_WRITEABLE),
		PATROL_POINT_BLOCK_ID)
	{
		{ _field_custom_short_block_index, "point", FIELD_FLAG_INDEX },
		{ _field_word_flags, "flags", &patrol_point_flags },
		{ _field_real, "delay", "how long the AI should pause at this point", "seconds" },
		{ _field_real, "angle", "the angle-from-forward that the AI can pick at this point", "degrees" },
		{ _field_string_id, "activity name" },
		{ _field_enum, "activity", FIELD_FLAG_UNKNOWN0, &g_activity_enum },
		{ _field_short_integer, "activity variant", FIELD_FLAG_UNKNOWN0 },
		{ _field_string_id, "command script", _field_id_halo_script_block },
		{ _field_short_integer, "command script index", FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		FIELD_PAD("post-command-script", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	#define SPAWN_POINTS_BLOCK_STRUCT_ID { 0x2288B874, 0x915E47FC, 0xA59792AF, 0x15D83BA8 }
	TAG_BLOCK(
		spawn_points_block,
		"spawn_points_block",
		k_maximum_spawn_points_per_squad,
		"s_spawn_point_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | 
		SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_WRITEABLE),
		SPAWN_POINTS_BLOCK_STRUCT_ID)
	{
		{ _field_struct, "place on", &ai_spawn_conditions_struct },
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_custom_short_block_index, "cell" },
		FIELD_PAD("post-cell-index-pad", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real_point_3d, "position" },
		{ _field_custom_long_block_index, "packedKeyOffaceref", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_UNKNOWN3 },
		{ _field_custom_long_block_index, "navMeshUIDOffaceref", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_UNKNOWN3 },
		{ _field_real_euler_angles_2d, "facing (yaw, pitch)", nullptr, "degrees" },
		{ _field_real, "roll" },
		{ _field_word_flags, "flags", &starting_location_flags },
		{ _field_short_block_index, "character type", &character_palette_block },
		{ _field_short_block_index, "initial weapon", &scenario_weapon_palette_block },
		{ _field_short_block_index, "initial secondary weapon", &scenario_weapon_palette_block },
		{ _field_short_block_index, "initial equipment", &scenario_equipment_palette_block },
		{ _field_short_block_index, "vehicle type", &scenario_vehicle_palette_block },
		{ _field_enum, "seat type", &ai_placement_seat_preference_enum },
		{ _field_enum, "grenade type", &global_ai_grenade_type_enum },
		{ _field_short_integer, "swarm count", "number of cretures in swarm if a swarm is spawned at this location" },
		FIELD_PAD("post-swarm-count-pad", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_string_id, "actor variant name" },
		{ _field_string_id, "vehicle variant name" },
		{ _field_string_id, "voice designator" },
		{ _field_real, "initial movement distance", "before doing anything else, the actor will travel the given distance in its forward direction" },
		{ _field_enum, "initial movement mode", &actor_movement_modes },
		{ _field_short_block_index, "emitter vehicle", &scenario_vehicle_block },
		{ _field_short_block_index, "giant body", &scenario_giant_block },
		{ _field_short_block_index, "biped body", &scenario_biped_block },
		{ _field_string_id, "placement script", MAKE_OLD_NAMES("Placement script"), _field_id_halo_script_block },
		{ _field_short_integer, "placement script index", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_UNKNOWN3 },
		FIELD_PAD("post-placement-script-pad", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_string_id, "activity name" },
		{ _field_string_id, "movement set" },
		{ _field_custom_short_block_index, "point set" },
		{ _field_enum, "patrol mode", &patrol_mode_enum },
		{ _field_block, "points", &patrol_point_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_short_block_index, "vehicle body", &scenario_vehicle_block },
		FIELD_PAD("post-vehicle_index-pad", nullptr, FIELD_FLAG_NONE, 2),

		{ _field_terminator }
	};

	#define CELL_BLOCK_STRUCT_ID { 0x3EBCDDBB, 0xE05345C9, 0x81A0110C, 0xABA2BEDD }
	TAG_BLOCK(
		cell_block,
		"cell_block",
		k_maximum_cells_per_squad,
		"s_cell_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | 
		SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_WRITEABLE),
		CELL_BLOCK_STRUCT_ID)
	{
		FIELD_EXPLANATION("Character Build", nullptr, FIELD_FLAG_NONE, "Specify the distribution of characters and weapons in the cell sub-folders"),
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_struct, "place on", &ai_spawn_conditions_struct },
		{ _field_short_integer, "normal diff count", "initial number of actors on normal difficulty" },
		{ _field_enum, "major upgrade", &major_upgrade_enum },
		{ _field_block, "character type", &character_palette_choice_block },
		{ _field_block, "initial weapon", &weapon_palette_choice_block },
		{ _field_block, "initial secondary weapon", &weapon_palette_choice_block },
		{ _field_block, "initial equipment", &equipment_palette_choice_block },
		{ _field_enum, "grenade type", &global_ai_grenade_type_enum },
		{ _field_short_block_index, "vehicle type", &scenario_vehicle_palette_block },
		{ _field_string_id, "vehicle variant" },
		{ _field_string_id, "Placement script", _field_id_halo_script_block },
		{ _field_short_integer, "placement script index", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_UNKNOWN3 },
		FIELD_PAD("plsc", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_string_id, "activity name" },
		{ _field_string_id, "movement set" },
		{ _field_custom_short_block_index, "point set" },
		{ _field_enum, "patrol mode", &patrol_mode_enum },
		{ _field_block, "points", FIELD_FLAG_UNKNOWN0, &patrol_point_block },
		{ _field_terminator }
	};

	#define CHARACTER_PALETTE_CHOICE_BLOCK_STRUCT_ID { 0xBB2A944A, 0xC1B74085, 0x8E86FA6B, 0xFDD8D702 }
	TAG_BLOCK(
		character_palette_choice_block,
		"character_palette_choice_block",
		k_maximum_palette_choices,
		"s_cell_palette_choice",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CHARACTER_PALETTE_CHOICE_BLOCK_STRUCT_ID)
	{
		{ _field_struct, "place on", &ai_spawn_conditions_struct },
		{ _field_short_block_index, "character type", FIELD_FLAG_INDEX, &character_palette_block },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_filter),
		{ _field_short_integer, "chance" },
		{ _field_terminator }
	};

	#define WEAPON_PALETTE_CHOICE_BLOCK_STRUCT_ID { 0x2A9BC12D, 0x1F3C4AF4, 0x98D10B30, 0x0D083A3F }
	TAG_BLOCK(
		weapon_palette_choice_block,
		"weapon_palette_choice_block",
		k_maximum_palette_choices,
		"s_cell_palette_choice",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		WEAPON_PALETTE_CHOICE_BLOCK_STRUCT_ID)
	{
		{ _field_struct, "place on", &ai_spawn_conditions_struct },
		{ _field_short_block_index, "weapon type", FIELD_FLAG_INDEX, &scenario_weapon_palette_block },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_filter),
		{ _field_short_integer, "chance" },
		{ _field_terminator }
	};

	#define EQUIPMENT_PALETTE_CHOICE_BLOCK_STRUCT_ID { 0xBCF7EEFC, 0xABE6477A, 0xB74E75D9, 0x124566A9 }
	TAG_BLOCK(
		equipment_palette_choice_block,
		"equipment_palette_choice_block",
		k_maximum_palette_choices,
		"s_cell_palette_choice",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		EQUIPMENT_PALETTE_CHOICE_BLOCK_STRUCT_ID)
	{
		{ _field_struct, "place on", &ai_spawn_conditions_struct },
		{ _field_short_block_index, "equipment type", FIELD_FLAG_INDEX, &scenario_equipment_palette_block },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_filter),
		{ _field_short_integer, "chance" },
		{ _field_terminator }
	};

	#define CELL_TEMPLATE_BLOCK_STRUCT_ID { 0x84753568, 0x2BD14D62, 0xB1F8C1FD, 0xBE899C68 }
	TAG_BLOCK(
		cell_template_block,
		"cell_template_block",
		k_maximum_cells_per_squad,
		"s_cell_template_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		CELL_TEMPLATE_BLOCK_STRUCT_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_struct, "place on", &ai_spawn_conditions_struct },
		{ _field_short_integer, "normal diff count", "initial number of actors on normal difficulty" },
		{ _field_enum, "major upgrade", &major_upgrade_enum },
		FIELD_EXPLANATION("Character Build", nullptr, FIELD_FLAG_NONE, "Specify the distribution of characters and weapons in the following blocks"),
		{ _field_block, "character type", &character_ref_choice_block, _field_id_grid },
		{ _field_block, "initial weapon", &weapon_ref_choice_block, _field_id_grid },
		{ _field_block, "initial secondary weapon", &weapon_ref_choice_block, _field_id_grid },
		{ _field_block, "initial equipment", &equipment_ref_choice_block, _field_id_grid },
		{ _field_enum, "grenade type", &global_ai_grenade_type_enum },
		FIELD_PAD("post-grenade", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_tag_reference, "vehicle type", &vehicle_reference$3 },
		{ _field_string_id, "vehicle variant" },
		{ _field_string_id, "activity name" },
		{ _field_terminator }
	};

	#define CHARACTER_REF_CHOICE_BLOCK_STRUCT_ID { 0x01E52F15, 0x71C34DF8, 0xA58FEA67, 0x4E3DF601 }
	TAG_BLOCK(
		character_ref_choice_block,
		"character_ref_choice_block",
		k_maximum_palette_choices,
		"s_cell_ref_choice",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CHARACTER_REF_CHOICE_BLOCK_STRUCT_ID)
	{
		{ _field_struct, "place on", &ai_spawn_conditions_struct },
		{ _field_tag_reference, "character type", FIELD_FLAG_INDEX, &character_reference$7 },
		{ _field_short_integer, "chance" },
		FIELD_PAD("post-chance", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	#define WEAPON_REF_CHOICE_BLOCK_STRUCT_ID { 0x75EE0928, 0xD53E4FC6, 0x83DA2A8E, 0x7CDFC94F }
	TAG_BLOCK(
		weapon_ref_choice_block,
		"weapon_ref_choice_block",
		k_maximum_palette_choices,
		"s_cell_ref_choice",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		WEAPON_REF_CHOICE_BLOCK_STRUCT_ID)
	{
		{ _field_struct, "place on", &ai_spawn_conditions_struct },
		{ _field_tag_reference, "weapon type", FIELD_FLAG_INDEX, &weapon_reference$8 },
		{ _field_short_integer, "chance" },
		FIELD_PAD("post-chance", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	#define EQUIPMENT_REF_CHOICE_BLOCK_STRUCT_ID { 0xADF3A9B8, 0xFACA4EA7, 0xAA2C6D31, 0xDF704939 }
	TAG_BLOCK(
		equipment_ref_choice_block,
		"equipment_ref_choice_block",
		k_maximum_palette_choices,
		"s_cell_ref_choice",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		EQUIPMENT_REF_CHOICE_BLOCK_STRUCT_ID)
	{
		{ _field_struct, "place on", &ai_spawn_conditions_struct },
		{ _field_tag_reference, "equipment type", FIELD_FLAG_INDEX, &equipment_reference$4 },
		{ _field_short_integer, "chance" },
		FIELD_PAD("post-chance", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	#define SQUAD_DEFINITION_INTERNAL_STRUCT_ID { 0x5DA7C809, 0xB8B849EE, 0x9CE778C1, 0x99C9CDD3 }
	TAG_STRUCT(
		squad_definition_internal_struct,
		"squad_definition_internal_struct",
		"s_squad_definition_internal",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SQUAD_DEFINITION_INTERNAL_STRUCT_ID)
	{
		{ _field_block, "cells", &cell_block },
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

} // namespace macaque

} // namespace blofeld

