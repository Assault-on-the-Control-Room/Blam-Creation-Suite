#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_GROUP_FROM_BLOCK(incident_global_properties_definition, INCIDENT_GLOBAL_PROPERTIES_DEFINITION_TAG, incident_global_properties_definition_block_block );

	V5_TAG_GROUP(incident_globals_definition, INCIDENT_GLOBALS_DEFINITION_TAG)
	{
		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_long_integer, "unknown" },

		{ _field_legacy, _field_block, "incidents", &incident_definition_block_block },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_GROUP_FROM_BLOCK(SuppressedIncident, SUPPRESSEDINCIDENT_TAG, SuppressedIncident_block_block );

	V5_TAG_BLOCK(suppressed_incident_block, 1000)
	{
		{ _field_legacy, _field_string_id, "incident name^" },
		{ _field_legacy, _field_byte_flags, "suppression type", &suppressed_incident_flags },
		{ _field_legacy, _field_pad, "VNJESHFHV", 3 },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(SuppressedIncidentBlockReferenceDefinition, 8)
	{
		{ _field_legacy, _field_tag_reference, "suppression block", &SuppressedIncidentGroupReference },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(specialized_incident_kill_implement_block, 50)
	{
		{ _field_legacy, _field_char_enum, "damage reporting type^", &global_damage_reporting_enum_definition },
		{ _field_legacy, _field_pad, "ACNUIEHF", 3 },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(specialized_incident_object_riding_in_vehicle_properties_block, 10)
	{
		{ _field_legacy, _field_long_enum, "vehicle type", &vehicle_type_enum },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(specialized_incident_object_properties_block, 10)
	{
		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 4},
		{ _field_legacy, _field_word_flags, "flags", &specialized_incident_kill_bucket_flags },
		{ _field_legacy, _field_char_enum, "bucket type^", &campaign_metagame_bucket_type_with_none_enum },
		{ _field_legacy, _field_char_enum, "bucket class^", &campaign_metagame_bucket_class_with_none_enum },
		{ _field_legacy, _field_string, "profile name" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 6 },
		{ _field_legacy, _field_long_flags, "flags", &specialized_incident_kill_bucket_flags },
		{ _field_legacy, _field_char_enum, "bucket type^", &campaign_metagame_bucket_type_with_none_enum },
		{ _field_legacy, _field_char_enum, "bucket class^", &campaign_metagame_bucket_class_with_none_enum },
		{ _field_legacy, _field_pad, "PAD0", 2 },
		{ _field_legacy, _field_string, "gamertag" },
		{ _field_legacy, _field_block, "riding in vehicles", &specialized_incident_object_riding_in_vehicle_properties_block_block },

		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(specialized_incident_special_kill_type_block, 10)
	{
		{ _field_legacy, _field_char_enum, "special kill type^", &specialized_incident_special_kill_type_enum },
		{ _field_legacy, _field_pad, "CVUIHEN", 3 },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(specializedIncidentGameOverBlock, 1)
	{
		{ _field_legacy, _field_word_flags, "flags", &specializedIncidentGameOverFlags },
		{ _field_legacy, _field_short_integer, "minimum game length:seconds" },
		{ _field_legacy, _field_char_integer, "megalo category index#only used if the \"check megalo category\" flag is set" },
		{ _field_legacy, _field_pad, "PAD1", 3 },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(specializedIncidentRandomOrdnanceBlock, 16)
	{
		{ _field_legacy, _field_string_id, "ordnance_name^#This must match one of the global ordnance objects." },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(specializedIncidentCustomDataFilterBlock, 1)
	{
		{ _field_legacy, _field_byte_flags, "flags", &numeric_comparison_flags },
		{ _field_legacy, _field_pad, "PAD1", 3 },
		{ _field_legacy, _field_long_integer, "value" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(specializedIncidentDistanceFilterBlock, 1)
	{
		{ _field_legacy, _field_byte_flags, "flags", &numeric_comparison_flags },
		{ _field_legacy, _field_pad, "PAD1", 3 },
		{ _field_legacy, _field_long_integer, "distance between effect and cause player: wu" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(specialized_incident_block, 1)
	{
		{ _field_legacy, _field_string_id, "base incident^" },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_long_integer, "unknown@" },

		{ _field_legacy, _field_block, "kill implements", &specialized_incident_kill_implement_block_block },
		{ _field_legacy, _field_block, "cause object", &specialized_incident_object_properties_block_block },
		{ _field_legacy, _field_block, "effect object{kill bucket}", &specialized_incident_object_properties_block_block },
		{ _field_legacy, _field_block, "special kill type", &specialized_incident_special_kill_type_block_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 4 },
		{ _field_legacy, _field_block, "game over filter", &specializedIncidentGameOverBlock_block },
		{ _field_legacy, _field_block, "ordnance filter", &specializedIncidentRandomOrdnanceBlock_block },
		{ _field_legacy, _field_block, "custom data filter", &specializedIncidentCustomDataFilterBlock_block },
		{ _field_legacy, _field_block, "distance filter", &specializedIncidentDistanceFilterBlock_block },

		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(incident_accumulator_child_incident_block, 60)
	{
		{ _field_legacy, _field_byte_flags, "flags", &numeric_comparison_flags },
		{ _field_legacy, _field_pad, "VLHSJNRE", 3 },
		{ _field_legacy, _field_long_integer, "count" },
		{ _field_legacy, _field_string_id, "incident name" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_legacy, _field_string_id, "reset incident name" },
		{ _field_legacy, _field_real, "reset timeout" },

		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(incident_accumulator_block, 1)
	{
		{ _field_legacy, _field_char_enum, "aggregation type", &incident_accumulator_aggregation_method_enum },
		{ _field_legacy, _field_char_enum, "resets on", &incident_accumulator_reset_enum },
		{ _field_legacy, _field_pad, "VJIOEJNLKS", 2 },
		{ _field_legacy, _field_block, "child incidents", &incident_accumulator_child_incident_block_block },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(incident_sum_accumulator_child_incident_block, 60)
	{
		{ _field_legacy, _field_string_id, "incident name" },
		{ _field_legacy, _field_string_id, "reset incident name" },
		{ _field_legacy, _field_real, "reset timeout" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(incident_sum_accumulator_block, 1)
	{
		{ _field_legacy, _field_char_enum, "resets on", &incident_accumulator_reset_enum },
		{ _field_legacy, _field_byte_flags, "flags", &numeric_comparison_flags },
		{ _field_legacy, _field_pad, "XSEXEC", 2 },
		{ _field_legacy, _field_long_integer, "count" },
		{ _field_legacy, _field_block, "child incidents", &incident_sum_accumulator_child_incident_block_block },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(incident_definition_block, s_incident_definition::k_maximum_incidents_per_definition)
	{
		{ _field_legacy, _field_string_id, "name^" },
		{ _field_legacy, _field_custom, "PROPERTIES" },
		{ _field_legacy, _field_byte_flags, "flags", &incident_definition_flags },
		{ _field_legacy, _field_pad, "JKOPEIE", 3 },
		{ _field_legacy, _field_custom, "DISALLOWED GAME MODES" },
		{ _field_legacy, _field_struct, "disallowed game modes", &game_mode_flags_struct_struct_definition },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_block, "suppressed incidents", &suppressed_incident_block_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_legacy, _field_block, "suppressed incident blocks", &SuppressedIncidentBlockReferenceDefinition_block },

		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_custom, "CREATION" },
		{ _field_legacy, _field_block, "specialized incidents", &specialized_incident_block_block },
		{ _field_legacy, _field_block, "accumulator incidents", &incident_accumulator_block_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_legacy, _field_block, "sum accumulator incidents", &incident_sum_accumulator_block_block },

		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_block, "response", &game_incident_response_block_block },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK_FROM_STRUCT(incident_global_properties_definition_block, 1, incident_global_properties_definition_struct_definition_struct_definition );

	V5_TAG_BLOCK_FROM_STRUCT(SuppressedIncident_block, 1, SuppressedIncident_struct_definition_struct_definition );

	V5_TAG_BLOCK(incident_global_properties_incident_definitions, 65536)
	{
		{ _field_legacy, _field_tag_reference, "incident definitions", &incident_globals_definition_reference },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_STRUCT(incident_global_properties_definition_struct_definition)
	{
		{ _field_legacy, _field_real, "campaign multikill time:s" },
		{ _field_legacy, _field_real, "survival multikill time:s" },
		{ _field_legacy, _field_real, "multiplayer multikill time:s" },
		{ _field_legacy, _field_real, "low health threshold:[0,1]" },
		{ _field_legacy, _field_real, "shield recharge threshold:[0,1]" },
		{ _field_legacy, _field_real, "maximum vengeance time:s" },
		{ _field_legacy, _field_real, "lifesaver damage threshold:[0,2]" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 8 },
		{ _field_legacy, _field_real, "avenger dead time:s" },
		{ _field_legacy, _field_real, "hologram recently used maximum time:s" },
		{ _field_legacy, _field_long_enum, "active camouflage incident minimum level", &active_camo_enum_definition },
		{ _field_legacy, _field_real, "thruster pack recently used maximum time:s" },
		{ _field_legacy, _field_real, "active shield recently used maximum time:s" },
		{ _field_legacy, _field_real, "damage threshold for hologram incidents:[0,1]" },
		{ _field_legacy, _field_real, "damage threshold for distraction incident killer:[0,1]" },
		{ _field_legacy, _field_real, "damage threshold for distraction incident distractor:[0,1]" },

		{ _field_legacy, _field_tag_reference, "reward globals!", &reward_globals_definition_reference },
		{ _field_legacy, _field_tag_reference, "commendation globals", &commendation_globals_definition_reference },
		{ _field_legacy, _field_custom, "HEAT" },
		{ _field_legacy, _field_short_integer, "maximum heat" },
		{ _field_legacy, _field_pad, "KVLHESKH", 2 },
		{ _field_legacy, _field_real, "full heat decay time:S#seconds to completely deplete a full heat meter" },
		{ _field_legacy, _field_real, "full heat stun time:s#seconds from the time you are at maximum heat until it starts decaying again" },
		{ _field_legacy, _field_real, "betrayal heat stun time:s#seconds from the time you are at maximum heat until it starts decaying again" },
		{ _field_legacy, _field_custom },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_block, "incident definitions", &incident_global_properties_incident_definitions_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_legacy, _field_tag_reference, "incident definitions", &incident_globals_definition_reference },

		{ _field_legacy, _field_block, "default incident definition!*#generated in code", &incident_definition_block_block },

		{ _field_legacy, _field_terminator }
	};

	V5_TAG_STRUCT(SuppressedIncident_struct_definition)
	{
		{ _field_legacy, _field_block, "suppressed incidents", &suppressed_incident_block_block },
		{ _field_legacy, _field_terminator }
	};

	STRINGS(numeric_comparison_flags)
	{
		"equal to",
		"greater than",
		"less than"
	};
	STRING_LIST(numeric_comparison_flags, numeric_comparison_flags_strings, _countof(numeric_comparison_flags_strings));

	STRINGS(suppressed_incident_flags)
	{
		"suppress cause player game engine event{suppress game engine event}",
		"suppress effect player game engine event",
		"suppress cause team game engine event",
		"suppress effect team game engine event",
		"suppress medal display{suppress display}",
		"suppress medal stats{suppress stats}",
		"suppress fanfare",
		"suppress audio"
	};
	STRING_LIST(suppressed_incident_flags, suppressed_incident_flags_strings, _countof(suppressed_incident_flags_strings));

	STRINGS(incident_definition_flags)
	{
		"never network (default is network only to interested parties)",
		"always network to everyone (default is network only to interested parties)",
		"use long delay (used in halo 3 on player_joined and player_rejoined incidents",
		"force game engine event display in campaign"
	};
	STRING_LIST(incident_definition_flags, incident_definition_flags_strings, _countof(incident_definition_flags_strings));

	STRINGS(specialized_incident_kill_bucket_flags)
	{
		"player",
		"ai",
		"343i employee{bungie employee}",
		"hologram",
		"airborne",
		"sprinting",
		"crouched",
		"reloading",
		"not fancy assassinating",
		"fancy assassinating",
		"being fancy assassinated",
		"low health",
		"unshielded",
		"in stasis field",
		"active camouflage active",
		"hologram active",
		"jetpack active{jetpacking}",
		"portable automated turret active",
		"reflective shield active",
		"thruster pack active",
		"x-ray vision active",
		"active camouflage active and effective",
		"hologram recently activated",
		"thruster pack recently activated",
		"hologram took damage from other player",
		"hologram did not take damage from other player",
		"active shield recently activated",
		"in a full vehicle",
		"scoped in",
		"not scoped in",
		"jacking vehicle",
		"airsassination"
	};
	STRING_LIST(specialized_incident_kill_bucket_flags, specialized_incident_kill_bucket_flags_strings, _countof(specialized_incident_kill_bucket_flags_strings));

	STRINGS(specializedIncidentGameOverFlags)
	{
		"killed all enemies#only looks at the enemies in-game at the end",
		"highest score#had the highest score",
		"top 3 score#one of the top three scorers",
		"winner#individual winner or on the winning team",
		"hosted#was the host of the game at the end",
		"check megalo category#if set, compare the Megalo category index against the tag value",
		"loser",
		"tied",
		"not tied"
	};
	STRING_LIST(specializedIncidentGameOverFlags, specializedIncidentGameOverFlags_strings, _countof(specializedIncidentGameOverFlags_strings));

	STRINGS(specialized_incident_special_kill_type_enum)
	{
		"headshot",
		"grenade stick",
		"stealth kill",
		"fancy assassination",
		"superdetonation",
		"emp kill",
		"melee",
		"collision#vehicular splatter",
		"leader killed#killed the player in 1st place",
		"team elimination kill#killed the last surviving player on a team in team game",
		"ffa elimination kill#killed the last surviving player in a ffa game"
	};
	STRING_LIST(specialized_incident_special_kill_type_enum, specialized_incident_special_kill_type_enum_strings, _countof(specialized_incident_special_kill_type_enum_strings));

	STRINGS(incident_accumulator_reset_enum)
	{
		"four seconds since last event",
		"player death",
		"round over",
		"game over",
		"on incident"
	};
	STRING_LIST(incident_accumulator_reset_enum, incident_accumulator_reset_enum_strings, _countof(incident_accumulator_reset_enum_strings));

	STRINGS(incident_accumulator_aggregation_method_enum)
	{
		"all",
		"any"
	};
	STRING_LIST(incident_accumulator_aggregation_method_enum, incident_accumulator_aggregation_method_enum_strings, _countof(incident_accumulator_aggregation_method_enum_strings));

	TAG_REFERENCE(SuppressedIncidentGroupReference, SUPPRESSEDINCIDENT_TAG);

} // namespace blofeld

