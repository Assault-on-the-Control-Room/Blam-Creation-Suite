#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_GROUP_INHERIT_FROM_BLOCK(device_control, DEVICE_CONTROL_TAG, device, DEVICE_TAG, device_control_block_block );

	V5_TAG_GROUP_INHERIT_FROM_BLOCK(device, DEVICE_TAG, object, OBJECT_TAG, device_block_block );

	V5_TAG_GROUP_INHERIT_FROM_BLOCK(device_dispenser, DEVICE_DISPENSER_TAG, device, DEVICE_TAG, device_dispenser_block_block );

	V5_TAG_GROUP_INHERIT_FROM_BLOCK(device_machine, DEVICE_MACHINE_TAG, device, DEVICE_TAG, device_machine_block_block );

	V5_TAG_GROUP_INHERIT_FROM_BLOCK(device_terminal, DEVICE_TERMINAL_TAG, device, DEVICE_TAG, device_terminal_block_block );

	V5_TAG_BLOCK_FROM_STRUCT(device_control_block, 1, device_control_struct_definition_struct_definition );

	V5_TAG_BLOCK_FROM_STRUCT(device_block, 1, device_struct_definition_struct_definition );

	V5_TAG_BLOCK_FROM_STRUCT(device_dispenser_block, 1, device_dispenser_struct_definition_struct_definition );

	V5_TAG_BLOCK_FROM_STRUCT(device_machine_block, 1, device_machine_struct_definition_struct_definition );

	V5_TAG_BLOCK(terminal_page_block_definition, _terminal_definition::k_max_page_count)
	{
		{ _field_legacy, _field_short_integer, "bitmap sequence index" },
		{ _field_legacy, _field_short_integer, "bitmap sprite index" },
		{ _field_legacy, _field_string_id, "text" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK_FROM_STRUCT(device_terminal_block, 1, device_terminal_struct_definition_struct_definition );

	V5_TAG_STRUCT(device_control_struct_definition)
	{
		{ _field_legacy, _field_struct, "device", &device_struct_definition_struct_definition },
		{ _field_legacy, _field_custom, "$$$ CONTROL $$$" },
		{ _field_legacy, _field_enum, "type", &control_types },
		{ _field_legacy, _field_enum, "triggers when", &control_triggers },
		{ _field_legacy, _field_real, "call value:[0,1]" },
		{ _field_legacy, _field_string_id, "action string" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 14 },
		{ _field_legacy, _field_string_id, "secondary action string" },
		{ _field_legacy, _field_string_id, "action denied string#A string to display when someone else is already using \"interaction held\"-type controls" },
		{ _field_legacy, _field_string_id, "action denied secondary string#A string displayed when someone else is using \"interaction held\"-type controls and it\'s in secondary mode" },
		{ _field_legacy, _field_string_id, "MP team use denied string#A string to display if the reason for denial is because of the MP team use restriction" },
		{ _field_legacy, _field_string_id, "MP team use denied secondary string#A string displayed if denied because of MP team use restriction and in secondary mode" },
		{ _field_legacy, _field_string_id, "action and MP team use denied string#Displayed when someone else already using \"interaction held\"-type controls and that player\'s team also triggers the mp use restriction" },
		{ _field_legacy, _field_string_id, "action and MP team use denied secondary string#Displayed when \"interaction held\"-type controls in use, the MP use restriction applies, and in secondary mode" },
		{ _field_legacy, _field_real, "interaction hold time#How many seconds the user must hold the interaction button before the control triggers:seconds" },
		{ _field_legacy, _field_string_id, "interaction screen#A cui_screen to display when someone is using \"interaction held\"-type controls" },
		{ _field_legacy, _field_tag_reference, "hold start#An effect to play when a user starts holding the interaction button on this control", &device_struct_definition_open_up_reference },
		{ _field_legacy, _field_tag_reference, "action denied sound#A sound to play when someone attempts to use this control while it is in use", &global_sound_reference },
		{ _field_legacy, _field_useless_pad },
		{ _field_legacy, _field_enum, "MP team use restriction", &teamUseRestrictionEnum },
		{ _field_legacy, _field_pad, "turd", 2 },

		{ _field_legacy, _field_tag_reference, "on", &device_struct_definition_open_up_reference },
		{ _field_legacy, _field_tag_reference, "off", &device_struct_definition_open_up_reference },
		{ _field_legacy, _field_tag_reference, "deny", &device_struct_definition_open_up_reference },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_legacy, _field_string_id, "script name" },

		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_STRUCT(device_struct_definition)
	{
		{ _field_legacy, _field_struct, "object", &object_struct_definition_struct_definition },
		{ _field_legacy, _field_custom, "$$$ DEVICE $$$" },
		{ _field_legacy, _field_long_flags, "flags", &device_definition_flags },
		{ _field_legacy, _field_real, "power transition time:seconds" },
		{ _field_legacy, _field_real, "power acceleration time:seconds" },
		{ _field_legacy, _field_real, "position transition time:seconds" },
		{ _field_legacy, _field_real, "position acceleration time:seconds" },
		{ _field_legacy, _field_real, "depowered position transition time:seconds" },
		{ _field_legacy, _field_real, "depowered position acceleration time:seconds" },
		{ _field_legacy, _field_word_flags, "lightmap flags", &device_lightmap_flags },
		{ _field_legacy, _field_pad, "ZHBMT", 2 },
		{ _field_legacy, _field_useless_pad },
		{ _field_legacy, _field_tag_reference, "open (up)", &device_struct_definition_open_up_reference },
		{ _field_legacy, _field_tag_reference, "close (down)", &device_struct_definition_open_up_reference },
		{ _field_legacy, _field_tag_reference, "opened", &device_struct_definition_open_up_reference },
		{ _field_legacy, _field_tag_reference, "closed", &device_struct_definition_open_up_reference },
		{ _field_legacy, _field_tag_reference, "depowered", &device_struct_definition_open_up_reference },
		{ _field_legacy, _field_tag_reference, "repowered", &device_struct_definition_open_up_reference },
		{ _field_legacy, _field_real, "delay time:seconds" },
		{ _field_legacy, _field_useless_pad },
		{ _field_legacy, _field_tag_reference, "delay effect", &device_struct_definition_open_up_reference },
		{ _field_legacy, _field_real, "automatic activation radius:world units" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 8 },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_string_id, "marker name" },
		{ _field_legacy, _field_real, "marker radius#max distance between the unit and the marker" },
		{ _field_legacy, _field_angle, "marker cone angle#angle from marker forward the unit must be" },
		{ _field_legacy, _field_angle, "marker facing angle#angle from unit facing the marker must be" },
		{ _field_legacy, _field_real, "min targetable position threshold#above this value and below the max, object becomes targetable" },
		{ _field_legacy, _field_real, "max targetable position threshold#below this value and above the min, object becomes targetable" },
		{ _field_legacy, _field_useless_pad },
		
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_STRUCT(device_dispenser_struct_definition)
	{
		{ _field_legacy, _field_struct, "device", &device_struct_definition_struct_definition },
		{ _field_legacy, _field_custom, "DISPENSER" },
		{ _field_legacy, _field_byte_flags, "flags", &DispenserDefinitionFlags },
		{ _field_legacy, _field_char_enum, "triggers when", &DispenserDefinitionTrigger },
		{ _field_legacy, _field_byte_integer, "use cooldown:seconds#The number of seconds that must elapse before this dispenser is usable" },
		{ _field_legacy, _field_byte_integer, "abandonment time:seconds#When abandoned for this many seconds the object will be deleted" },
		{ _field_legacy, _field_byte_integer, "max quota:(between 0 and 8)#The maximum number of objects that can come from this dispenser" },
		{ _field_legacy, _field_pad, "unrealized potential", 3 },
		{ _field_legacy, _field_real, "interaction hold time:seconds#How many seconds the user must hold the interaction button before the dispenser triggers" },
		{ _field_legacy, _field_string_id, "interaction screen#A cui_screen to display when someone is using \"interaction held\"-type dispensers" },
		{ _field_legacy, _field_tag_reference, "dispensed object#This object will be spawned by the dispenser", &device_dispenser_struct_definition_dispensed_object_reference },
		{ _field_legacy, _field_string_id, "desired variant name#The model variant to use of the dispensed object" },
		{ _field_legacy, _field_string_id, "action string#This interaction text will display when usable" },
		{ _field_legacy, _field_string_id, "same team denial string#Displayed when a player is in range but not on the right team" },
		{ _field_legacy, _field_string_id, "disabled denial string#Displayed when the dispenser is disabled" },
		{ _field_legacy, _field_string_id, "use cooldown denial string#Displayed when the use cooldown time hasn\'t elapsed yet" },
		{ _field_legacy, _field_string_id, "max quota denial string#Displayed when this dispenser is out of charges" },
		{ _field_legacy, _field_string_id, "interaction in progress denial string#Displayed when someone is already interacting with this device" },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_string_id, "spawn marker name#The dispensed object will appear with this marker\'s position and orientation" },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_string_id, "effect marker name#Creates the dispense effect at this marker name" },
		{ _field_legacy, _field_tag_reference, "dispense effect#An effect created when the the dispenser dispenses something", &Tag::Reference<struct effect_definition>::s_defaultDefinition },
		{ _field_legacy, _field_string_id, "dispenser attach marker#The marker on the dispenser to use for attachment if we attach our dispensed object, origin if undefined" },
		{ _field_legacy, _field_string_id, "dispensed object attach marker#The marker on the dispensed object to use for attachment if we attach our dispensed object, origin if undefined" },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_STRUCT(device_machine_struct_definition)
	{
		{ _field_legacy, _field_struct, "device", &device_struct_definition_struct_definition },
		{ _field_legacy, _field_explanation, "$$$ MACHINE $$$", "" },
		{ _field_legacy, _field_enum, "type", &machine_types },
		{ _field_legacy, _field_word_flags, "flags", &machine_flags },
		{ _field_legacy, _field_real, "door open time:seconds" },
		{ _field_legacy, _field_real_fraction_bounds, "door occlusion bounds#maps position [0,1] to occlusion" },
		{ _field_legacy, _field_useless_pad },
		{ _field_legacy, _field_enum, "collision response", &machine_collision_responses },
		{ _field_legacy, _field_short_integer, "elevator node" },
		{ _field_legacy, _field_useless_pad },
		{ _field_legacy, _field_enum, "pathfinding policy", &machine_pathfinding_policy_enum },
		{ _field_legacy, _field_pad, "R", 2 },
		{ _field_legacy, _field_string_id, "shield name#shield (or any damage section) to control" },
		{ _field_legacy, _field_string_id, "shield function#shield is on when this function is greater then 0.5f, off otherwise." },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_STRUCT(device_terminal_struct_definition)
	{
		{ _field_legacy, _field_struct, "device", &device_struct_definition_struct_definition },
		{ _field_legacy, _field_explanation, "$$$ TERMINAL $$$", "" },
		{ _field_legacy, _field_long_integer, "bah bah" },
		{ _field_legacy, _field_string_id, "action string" },
		{ _field_legacy, _field_string_id, "name#text pulled from strings tag above" },
		{ _field_legacy, _field_tag_reference, "activation sound", &sound_old_reference },
		{ _field_legacy, _field_tag_reference, "bitmap", &global_bitmap_reference },
		{ _field_legacy, _field_tag_reference, "strings", &global_multilingual_unicode_string_list_reference },
		{ _field_legacy, _field_block, "pages", &terminal_page_block_definition_block },
		{ _field_legacy, _field_terminator }
	};

	STRINGS(device_definition_flags)
	{
		"position loops",
		"use multiplayer boundary",
		"allow interpolation",
		"allow attached players",
		"control uses parent interact scripts",
		"requires line of sight for interaction",
		"only active when parent is hostile#This flag has no effect if the device is parented to a non unit",
		"is targetable"
	};
	STRING_LIST(device_definition_flags, device_definition_flags_strings, _countof(device_definition_flags_strings));

	STRINGS(device_lightmap_flags)
	{
		"don\'t use in lightmap",
		"don\'t use in lightprobe"
	};
	STRING_LIST(device_lightmap_flags, device_lightmap_flags_strings, _countof(device_lightmap_flags_strings));

	STRINGS(machine_types)
	{
		"door",
		"platform",
		"gear"
	};
	STRING_LIST(machine_types, machine_types_strings, _countof(machine_types_strings));

	STRINGS(machine_flags)
	{
		"pathfinding obstacle",
		"...but not when open",
		"elevator#lighting based on what\'s around, rather than what\'s below",
		"is portal blocker#machines of type \"door\" and all other machines with this flag checked can block a door portal",
		"is NOT pathfinding mobile",
		"uses default occlusion bounds!*",
		"gears repeat motion instead of loop#play animation, reset, play again. No smooth looping and interpolation",
		{ _field_legacy, _field_version_platform_include, _platform_type_pc, 2 },
		{ _field_legacy, _field_version_greater_or_equal, _engine_type_groundhog, 1 },
		"unknown bit 8",
	};
	STRING_LIST(machine_flags, machine_flags_strings, _countof(machine_flags_strings));

	STRINGS(machine_collision_responses)
	{
		"pause until crushed",
		"reverse directions"
	};
	STRING_LIST(machine_collision_responses, machine_collision_responses_strings, _countof(machine_collision_responses_strings));

	STRINGS(machine_pathfinding_policy_enum)
	{
		"discs",
		"sectors",
		"cut_out",
		"none"
	};
	STRING_LIST(machine_pathfinding_policy_enum, machine_pathfinding_policy_enum_strings, _countof(machine_pathfinding_policy_enum_strings));

	STRINGS(control_types)
	{
		"toggle switch",
		"on button",
		"off button",
		"call button",
		"health station#touching this device plays the \'on\' effect set below and refills the unit\'s health.\nIt also deletes itself if it runs out of charges (set in sapien)"
	};
	STRING_LIST(control_types, control_types_strings, _countof(control_types_strings));

	STRINGS(control_triggers)
	{
		"touched by player",
		"destroyed",
		"interaction held",
		{ _field_legacy, _field_version_platform_include, _platform_type_pc, 7 },
		{ _field_legacy, _field_version_greater_or_equal, _engine_type_groundhog, 6 },
		"unknown 3",
		"unknown 4",
		"unknown 5",
		"unknown 6",
		"unknown 7",
		"unknown 8",
	};
	STRING_LIST(control_triggers, control_triggers_strings, _countof(control_triggers_strings));

	STRINGS(teamUseRestrictionEnum)
	{
		"any team",
		"restrict to owner team",
		"exclude owner team"
	};
	STRING_LIST(teamUseRestrictionEnum, teamUseRestrictionEnum_strings, _countof(teamUseRestrictionEnum_strings));

	STRINGS(DispenserDefinitionFlags)
	{
		"usable by same team only",
		"automated functionality#Turn this on to allow device users to automatically enter vehicles, or automatically equip a weapon",
		"item inherits dispenser team#The spawned object will inherit the dispenser\'s team",
		"monitor for death only#Spawned objects don\'t get abandoned, and only reset on death",
		"delete dispensed objects when grabbed in forge#Used for Dominion turrets that are always supposed to be visually attached to their bases",
		"push players clear#Dispenser waits till the dispense location is clear before dispensing and can push players off the dispenser pad"
	};
	STRING_LIST(DispenserDefinitionFlags, DispenserDefinitionFlags_strings, _countof(DispenserDefinitionFlags_strings));

	STRINGS(DispenserDefinitionTrigger)
	{
		"touched",
		"interaction held"
	};
	STRING_LIST(DispenserDefinitionTrigger, DispenserDefinitionTrigger_strings, _countof(DispenserDefinitionTrigger_strings));

} // namespace blofeld

