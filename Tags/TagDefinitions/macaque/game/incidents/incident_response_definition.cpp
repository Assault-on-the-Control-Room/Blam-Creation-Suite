#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define GAME_INCIDENT_RESPONSE_BLOCK_STRUCT_ID { 0x2CD0CD80, 0x1A094BE0, 0xBEA6B3B3, 0x68205D16 }
	TAG_BLOCK(
		game_incident_response_block,
		"game_incident_response_block",
		MAXIMUM_GAME_INCIDENT_RESPONSES_PER_BLOCK,
		"s_game_incident_response",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_WRITEABLE),
		GAME_INCIDENT_RESPONSE_BLOCK_STRUCT_ID)
	{
		FIELD_CUSTOM("allowed game modes", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_struct, "allowed game modes", &game_mode_flags_struct },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 4 },
		FIELD_CUSTOM("allowed campaign and firefight", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_string_id, "allowed level name", "Can only be triggered on this level." },
		{ _field_long_flags, "required skulls", "These skulls must be enabled to trigger.", &skull_flags_definition },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),

		{ _field_long_integer, "heat award" },
		{ _field_string_id, "game engine event" },
		{ _field_string_id, "medal" },
		{ _field_string_id, "commendation" },
		{ _field_string_id, "achievement" },
		{ _field_string_id, "avatar award" },
		{ _field_block, "challenges", &game_incident_daily_challenge_to_increment_block },
		{ _field_string_id, "hs script" },
		{ _field_short_integer, "internal hs script index", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		FIELD_PAD("VHSLKJNE", nullptr, FIELD_FLAG_NONE, 2),

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_block, "fanfare", &specialized_incident_fanfare_block },
		{ _field_tag_reference, "sound response", &sound_incident_response_group_reference },

		{ _field_terminator }
	};

	#define GAME_INCIDENT_DAILY_CHALLENGE_TO_INCREMENT_BLOCK_ID { 0x42BE7F12, 0x282745AF, 0x8FB944C7, 0x5507C3E4 }
	TAG_BLOCK(
		game_incident_daily_challenge_to_increment_block,
		"game_incident_daily_challenge_to_increment_block",
		MAXIMUM_CHALLENGES_TO_PROGRESS_PER_BLOCK,
		"s_daily_challenge_to_increment",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		GAME_INCIDENT_DAILY_CHALLENGE_TO_INCREMENT_BLOCK_ID)
	{
		{ _field_string_id, "daily challenge", FIELD_FLAG_INDEX },
		{ _field_terminator }
	};

	#define SPECIALIZED_INCIDENT_FANFARE_BLOCK_ID { 0xBDADBDB5, 0x3A934FFE, 0x9ACFD385, 0xB197D612 }
	TAG_BLOCK(
		specialized_incident_fanfare_block,
		"specialized_incident_fanfare_block",
		1,
		"IncidentFanfareImplementDefinition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SPECIALIZED_INCIDENT_FANFARE_BLOCK_ID)
	{
		{ _field_long_integer, "priority", "0 is highest prioroty" },
		{ _field_char_enum, "queue type", &incident_fanfare_queue_type },
		{ _field_byte_flags, "excluded audience", &incident_fanfare_event_input_enum_definition },
		{ _field_byte_flags, "broad cast message", &incident_fanfare_event_flags_definition },
		FIELD_PAD("PADME", nullptr, FIELD_FLAG_NONE, 1),
		{ _field_string_id, "fanfare string" },
		{ _field_short_integer, "fanfare sprite index" },
		{ _field_short_integer, "display time in seconds" },
		{ _field_tag_reference, "hud screen reference", &Tag::Reference<struct CuiScreenDefinition>::s_defaultDefinition },
		{ _field_tag_reference, "sound response", &sound_response_group_reference },
		{ _field_string_id, "carried object type" },
		{ _field_terminator }
	};

	STRINGS(incident_fanfare_event_input_enum_definition)
	{
		"NONE",
		"cause player",
		"cause team",
		"effect player",
		"effect team"
	};
	STRING_LIST(incident_fanfare_event_input_enum_definition, incident_fanfare_event_input_enum_definition_strings, _countof(incident_fanfare_event_input_enum_definition_strings));

	STRINGS(incident_fanfare_queue_type)
	{
		"center",
		"game mode",
		"territory",
		"game mode secondary",
		"ordnance"
	};
	STRING_LIST(incident_fanfare_queue_type, incident_fanfare_queue_type_strings, _countof(incident_fanfare_queue_type_strings));

	STRINGS(incident_fanfare_event_flags_definition)
	{
		"broad cast message"
	};
	STRING_LIST(incident_fanfare_event_flags_definition, incident_fanfare_event_flags_definition_strings, _countof(incident_fanfare_event_flags_definition_strings));

} // namespace macaque

} // namespace blofeld

