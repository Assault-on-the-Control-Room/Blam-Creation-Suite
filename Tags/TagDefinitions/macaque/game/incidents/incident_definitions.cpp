#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		incident_global_properties_definition_group,
		INCIDENT_GLOBAL_PROPERTIES_DEFINITION_TAG,
		nullptr,
		INVALID_TAG,
		incident_global_properties_definition_block );

	#define INCIDENT_GLOBALS_DEFINITION_STRUCT_DEFINITION_ID { 0x81B17C12, 0x7D6C4B6A, 0xB91D09EA, 0x622C30D7 }
	TAG_BLOCK(
		incident_globals_definition_block,
		"incident_globals_definition_block",
		1,
		"s_incident_globals_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		INCIDENT_GLOBALS_DEFINITION_STRUCT_DEFINITION_ID)
	{
		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_long_integer, "unknown" },

		{ _field_block, "incidents", &incident_definition_block },
		{ _field_terminator }
	};

	TAG_GROUP(
		incident_globals_definition_group,
		INCIDENT_GLOBALS_DEFINITION_TAG,
		nullptr,
		INVALID_TAG,
		incident_globals_definition_block );

	TAG_GROUP(
		SuppressedIncident_group,
		SUPPRESSEDINCIDENT_TAG,
		nullptr,
		INVALID_TAG,
		SuppressedIncident_block );

	TAG_BLOCK_FROM_STRUCT(
		incident_global_properties_definition_block,
		"incident_global_properties_definition_block",
		1,
		incident_global_properties_definition_struct_definition);

	TAG_BLOCK_FROM_STRUCT(
		SuppressedIncident_block,
		"SuppressedIncident_block",
		1,
		SuppressedIncident_struct_definition);

	#define INCIDENT_DEFINITION_BLOCK_STRUCT_ID { 0xAE3FFFE9, 0xC8F4415E, 0x8E9C451C, 0xC8DCAAE9 }
	TAG_BLOCK(
		incident_definition_block,
		"incident_definition_block",
		s_incident_definition::k_maximum_incidents_per_definition,
		"s_incident_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		INCIDENT_DEFINITION_BLOCK_STRUCT_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		FIELD_CUSTOM("PROPERTIES", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_byte_flags, "flags", &incident_definition_flags },
		FIELD_PAD("JKOPEIE", nullptr, FIELD_FLAG_NONE, 3),
		FIELD_CUSTOM("DISALLOWED GAME MODES", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_struct, "disallowed game modes", &game_mode_flags_struct },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		{ _field_block, "suppressed incidents", &suppressed_incident_block, _field_id_slap },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_block, "suppressed incident blocks", &SuppressedIncidentBlockReferenceDefinition_block, _field_id_slap },

		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		FIELD_CUSTOM("CREATION", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_block, "specialized incidents", &specialized_incident_block, _field_id_slap },
		{ _field_block, "accumulator incidents", &incident_accumulator_block, _field_id_slap },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_block, "sum accumulator incidents", &incident_sum_accumulator_block, _field_id_slap },

		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		{ _field_block, "response", &game_incident_response_block },
		{ _field_terminator }
	};

	#define SUPPRESSED_INCIDENT_BLOCK_ID { 0xCB9D3072, 0xC3A1469E, 0x95FAAE71, 0x33A3E3E1 }
	TAG_BLOCK(
		suppressed_incident_block,
		"suppressed_incident_block",
		1000,
		"s_suppressed_incident_definition",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SUPPRESSED_INCIDENT_BLOCK_ID)
	{
		{ _field_string_id, "incident name", FIELD_FLAG_INDEX },
		{ _field_byte_flags, "suppression type", &suppressed_incident_flags },
		FIELD_PAD("VNJESHFHV", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_terminator }
	};

	#define SUPPRESSEDINCIDENTBLOCKREFERENCEDEFINITION_ID { 0x6BB34F94, 0x60A4411A, 0x9BA76EA7, 0x91D1D9A8 }
	TAG_BLOCK(
		SuppressedIncidentBlockReferenceDefinition_block,
		"SuppressedIncidentBlockReferenceDefinition",
		8,
		"SuppressedIncidentBlockReferenceDefinition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SUPPRESSEDINCIDENTBLOCKREFERENCEDEFINITION_ID)
	{
		{ _field_tag_reference, "suppression block", &SuppressedIncidentGroupReference },
		{ _field_terminator }
	};

	#define SPECIALIZED_INCIDENT_BLOCK_ID { 0xC1F3C060, 0xBF5B4A72, 0x9CE8BC8B, 0xF98CE86B }
	TAG_BLOCK(
		specialized_incident_block,
		"specialized_incident_block",
		1,
		"s_specialized_incident_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SPECIALIZED_INCIDENT_BLOCK_ID)
	{
		{ _field_string_id, "base incident", FIELD_FLAG_INDEX },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_long_integer, "unknown@" },

		{ _field_block, "kill implements", &specialized_incident_kill_implement_block },
		{ _field_block, "cause object", &specialized_incident_object_properties_block },
		{ _field_block, "effect object", MAKE_OLD_NAMES("kill bucket"), &specialized_incident_object_properties_block },
		{ _field_block, "special kill type", &specialized_incident_special_kill_type_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 4 },
		{ _field_block, "game over filter", &specializedIncidentGameOverBlock_block },
		{ _field_block, "ordnance filter", &specializedIncidentRandomOrdnanceBlock_block },
		{ _field_block, "custom data filter", &specializedIncidentCustomDataFilterBlock_block },
		{ _field_block, "distance filter", &specializedIncidentDistanceFilterBlock_block },

		{ _field_terminator }
	};

	#define SPECIALIZED_INCIDENT_KILL_IMPLEMENT_BLOCK_ID { 0x5969BC5F, 0x11694C45, 0x80E8714E, 0xEFB5D98C }
	TAG_BLOCK(
		specialized_incident_kill_implement_block,
		"specialized_incident_kill_implement_block",
		50,
		"s_specialized_incident_kill_implement_definition",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SPECIALIZED_INCIDENT_KILL_IMPLEMENT_BLOCK_ID)
	{
		{ _field_char_enum, "damage reporting type", FIELD_FLAG_INDEX, &global_damage_reporting_enum_definition },
		FIELD_PAD("ACNUIEHF", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_terminator }
	};

	#define SPECIALIZED_INCIDENT_OBJECT_PROPERTIES_BLOCK_ID { 0x4D1FDE04, 0x89074B60, 0x944875B0, 0x8DACCC3E }
	TAG_BLOCK(
		specialized_incident_object_properties_block,
		"specialized_incident_object_properties_block",
		10,
		"s_specialized_incident_object_properties_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SPECIALIZED_INCIDENT_OBJECT_PROPERTIES_BLOCK_ID)
	{
		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 4},
		{ _field_word_flags, "flags", &specialized_incident_kill_bucket_flags },
		{ _field_char_enum, "bucket type", FIELD_FLAG_INDEX, &campaign_metagame_bucket_type_with_none_enum },
		{ _field_char_enum, "bucket class", FIELD_FLAG_INDEX, &campaign_metagame_bucket_class_with_none_enum },
		{ _field_string, "profile name" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 6 },
		{ _field_long_flags, "flags", &specialized_incident_kill_bucket_flags },
		{ _field_char_enum, "bucket type", FIELD_FLAG_INDEX, &campaign_metagame_bucket_type_with_none_enum },
		{ _field_char_enum, "bucket class", FIELD_FLAG_INDEX, &campaign_metagame_bucket_class_with_none_enum },
		FIELD_PAD("PAD0", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_string, "gamertag" },
		{ _field_block, "riding in vehicles", &specialized_incident_object_riding_in_vehicle_properties_block },

		{ _field_terminator }
	};

	#define SPECIALIZED_INCIDENT_OBJECT_RIDING_IN_VEHICLE_PROPERTIES_BLOCK_ID { 0x0F5BB51F, 0xA1E14A01, 0x835ED18E, 0x9B9729FE }
	TAG_BLOCK(
		specialized_incident_object_riding_in_vehicle_properties_block,
		"specialized_incident_object_riding_in_vehicle_properties_block",
		10,
		"s_specialized_incident_object_vehicle_properties_definition",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SPECIALIZED_INCIDENT_OBJECT_RIDING_IN_VEHICLE_PROPERTIES_BLOCK_ID)
	{
		{ _field_long_enum, "vehicle type", &vehicle_type_enum },
		{ _field_terminator }
	};

	#define SPECIALIZED_INCIDENT_SPECIAL_KILL_TYPE_BLOCK_ID { 0x98E84EDD, 0x6C444EFF, 0xAD29087E, 0xB316BB19 }
	TAG_BLOCK(
		specialized_incident_special_kill_type_block,
		"specialized_incident_special_kill_type_block",
		10,
		"s_specialized_incident_special_kill_type_definition",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SPECIALIZED_INCIDENT_SPECIAL_KILL_TYPE_BLOCK_ID)
	{
		{ _field_char_enum, "special kill type", FIELD_FLAG_INDEX, &specialized_incident_special_kill_type_enum },
		FIELD_PAD("CVUIHEN", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_terminator }
	};

	#define SPECIALIZEDINCIDENTGAMEOVERBLOCK_ID { 0x897B0508, 0xAACF426F, 0x862BB053, 0x70A8D420 }
	TAG_BLOCK(
		specializedIncidentGameOverBlock_block,
		"specializedIncidentGameOverBlock",
		1,
		"SpecializedIncidentGameOverDefinition",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SPECIALIZEDINCIDENTGAMEOVERBLOCK_ID)
	{
		{ _field_word_flags, "flags", &specializedIncidentGameOverFlags },
		{ _field_short_integer, "minimum game length", nullptr, "seconds" },
		{ _field_char_integer, "megalo category index", "only used if the \"check megalo category\" flag is set" },
		FIELD_PAD("PAD1", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_terminator }
	};

	#define SPECIALIZEDINCIDENTRANDOMORDNANCEBLOCK_ID { 0xF6A98D0C, 0xC3F742AC, 0xAEABE06B, 0x901CE612 }
	TAG_BLOCK(
		specializedIncidentRandomOrdnanceBlock_block,
		"specializedIncidentRandomOrdnanceBlock",
		16,
		"specializedIncidentRandomOrdnanceDefinition",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SPECIALIZEDINCIDENTRANDOMORDNANCEBLOCK_ID)
	{
		{ _field_string_id, "ordnance_name", "This must match one of the global ordnance objects.", FIELD_FLAG_INDEX },
		{ _field_terminator }
	};

	#define SPECIALIZEDINCIDENTCUSTOMDATAFILTERBLOCK_ID { 0xFEA8C235, 0x959D4A7B, 0xA399E592, 0x8CFE5FFC }
	TAG_BLOCK(
		specializedIncidentCustomDataFilterBlock_block,
		"specializedIncidentCustomDataFilterBlock",
		1,
		"SpecializedIncidentCustomDataFilterDefinition",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SPECIALIZEDINCIDENTCUSTOMDATAFILTERBLOCK_ID)
	{
		{ _field_byte_flags, "flags", &numeric_comparison_flags },
		FIELD_PAD("PAD1", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_long_integer, "value" },
		{ _field_terminator }
	};

	#define SPECIALIZEDINCIDENTDISTANCEFILTERBLOCK_ID { 0xAE5C724E, 0x45294261, 0x9B787400, 0x52BDE73A }
	TAG_BLOCK(
		specializedIncidentDistanceFilterBlock_block,
		"specializedIncidentDistanceFilterBlock",
		1,
		"SpecializedIncidentDistanceDefinition",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SPECIALIZEDINCIDENTDISTANCEFILTERBLOCK_ID)
	{
		{ _field_byte_flags, "flags", &numeric_comparison_flags },
		FIELD_PAD("PAD1", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_long_integer, "distance between effect and cause player", nullptr, "wu" },
		{ _field_terminator }
	};

	#define INCIDENT_ACCUMULATOR_BLOCK_ID { 0x7C9F1078, 0x549D4D20, 0x925A0B61, 0xD07065E2 }
	TAG_BLOCK(
		incident_accumulator_block,
		"incident_accumulator_block",
		1,
		"s_incident_accumulator_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		INCIDENT_ACCUMULATOR_BLOCK_ID)
	{
		{ _field_char_enum, "aggregation type", &incident_accumulator_aggregation_method_enum },
		{ _field_char_enum, "resets on", &incident_accumulator_reset_enum },
		FIELD_PAD("VJIOEJNLKS", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_block, "child incidents", &incident_accumulator_child_incident_block },
		{ _field_terminator }
	};

	#define INCIDENT_ACCUMULATOR_CHILD_INCIDENT_BLOCK_ID { 0xC4843BBE, 0xFB7B47AC, 0x8C8D6C0C, 0xBF7AAF10 }
	TAG_BLOCK(
		incident_accumulator_child_incident_block,
		"incident_accumulator_child_incident_block",
		60,
		"s_incident_accumulator_child_incident_definition",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		INCIDENT_ACCUMULATOR_CHILD_INCIDENT_BLOCK_ID)
	{
		{ _field_byte_flags, "flags", &numeric_comparison_flags },
		FIELD_PAD("VLHSJNRE", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_long_integer, "count" },
		{ _field_string_id, "incident name" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_string_id, "reset incident name" },
		{ _field_real, "reset timeout" },

		{ _field_terminator }
	};

	#define INCIDENT_SUM_ACCUMULATOR_BLOCK_ID { 0x6CDCE224, 0xE8B64DC0, 0x85A497BA, 0x008347A1 }
	TAG_BLOCK(
		incident_sum_accumulator_block,
		"incident_sum_accumulator_block",
		1,
		"s_incident_sum_accumulator_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		INCIDENT_SUM_ACCUMULATOR_BLOCK_ID)
	{
		{ _field_char_enum, "resets on", &incident_accumulator_reset_enum },
		{ _field_byte_flags, "flags", &numeric_comparison_flags },
		FIELD_PAD("XSEXEC", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_long_integer, "count" },
		{ _field_block, "child incidents", &incident_sum_accumulator_child_incident_block },
		{ _field_terminator }
	};

	#define INCIDENT_SUM_ACCUMULATOR_CHILD_INCIDENT_BLOCK_ID { 0x3D98BF85, 0xA9BF46E2, 0xA4A9FD5F, 0x7F9748B3 }
	TAG_BLOCK(
		incident_sum_accumulator_child_incident_block,
		"incident_sum_accumulator_child_incident_block",
		60,
		"s_incident_sum_accumulator_child_incident_definition",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		INCIDENT_SUM_ACCUMULATOR_CHILD_INCIDENT_BLOCK_ID)
	{
		{ _field_string_id, "incident name" },
		{ _field_string_id, "reset incident name" },
		{ _field_real, "reset timeout" },
		{ _field_terminator }
	};

	V5_TAG_BLOCK(incident_global_properties_incident_definitions, 65536)
	{
		{ _field_legacy, _field_tag_reference, "incident definitions", & incident_globals_definition_reference },
		{ _field_legacy, _field_terminator }
	};

	#define INCIDENT_GLOBAL_PROPERTIES_DEFINITION_STRUCT_DEFINITION_ID { 0x249A61F3, 0xA6094D20, 0x94E24664, 0x95C2EF27 }
	TAG_STRUCT(
		incident_global_properties_definition_struct_definition,
		"incident_global_properties_definition_struct_definition",
		"s_incident_global_properties_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		INCIDENT_GLOBAL_PROPERTIES_DEFINITION_STRUCT_DEFINITION_ID)
	{
		{ _field_real, "campaign multikill time", nullptr, "s" },
		{ _field_real, "survival multikill time", nullptr, "s" },
		{ _field_real, "multiplayer multikill time", nullptr, "s" },
		{ _field_real, "low health threshold", nullptr, nullptr, "[0,1]" },
		{ _field_real, "shield recharge threshold", nullptr, nullptr, "[0,1]" },
		{ _field_real, "maximum vengeance time", nullptr, "s" },
		{ _field_real, "lifesaver damage threshold", nullptr, nullptr, "[0,2]" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 8 },
		{ _field_real, "avenger dead time", nullptr, "s" },
		{ _field_real, "hologram recently used maximum time", nullptr, "s" },
		{ _field_long_enum, "active camouflage incident minimum level", &active_camo_enum_definition },
		{ _field_real, "thruster pack recently used maximum time", nullptr, "s" },
		{ _field_real, "active shield recently used maximum time", nullptr, "s" },
		{ _field_real, "damage threshold for hologram incidents", nullptr, nullptr, "[0,1]" },
		{ _field_real, "damage threshold for distraction incident killer", nullptr, nullptr, "[0,1]" },
		{ _field_real, "damage threshold for distraction incident distractor", nullptr, nullptr, "[0,1]" },
		{ _field_tag_reference, "reward globals", FIELD_FLAG_UNKNOWN0, &reward_globals_definition_reference },
		{ _field_tag_reference, "commendation globals", &commendation_globals_definition_reference },
		FIELD_CUSTOM("HEAT", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_short_integer, "maximum heat" },
		FIELD_PAD("KVLHESKH", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real, "full heat decay time", "seconds to completely deplete a full heat meter", "S" },
		{ _field_real, "full heat stun time", "seconds from the time you are at maximum heat until it starts decaying again", "s" },
		{ _field_real, "betrayal heat stun time", "seconds from the time you are at maximum heat until it starts decaying again", "s" },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_block, "incident definitions", &incident_global_properties_incident_definitions_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_tag_reference, "incident definitions", &incident_globals_definition_reference },
		{ _field_block, "default incident definition", "generated in code", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &incident_definition_block },
		{ _field_terminator }
	};

	#define SUPPRESSEDINCIDENT_STRUCT_DEFINITION_ID { 0xD30BEC71, 0x3F404567, 0x83A6CB68, 0xF2572EFF }
	TAG_STRUCT(
		SuppressedIncident_struct_definition,
		"SuppressedIncident_struct_definition",
		"SuppressedIncidentGroupDefinition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SUPPRESSEDINCIDENT_STRUCT_DEFINITION_ID)
	{
		{ _field_block, "suppressed incidents", &suppressed_incident_block, _field_id_slap },
		{ _field_terminator }
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

} // namespace macaque

} // namespace blofeld

