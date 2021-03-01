#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_BLOCK(game_incident_daily_challenge_to_increment_block, MAXIMUM_CHALLENGES_TO_PROGRESS_PER_BLOCK)
	{
		{ _field_legacy, _field_string_id, "daily challenge^" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(specialized_incident_fanfare_block, 1)
	{
		{ _field_legacy, _field_long_integer, "priority#0 is highest prioroty" },
		{ _field_legacy, _field_char_enum, "queue type", &incident_fanfare_queue_type },
		{ _field_legacy, _field_byte_flags, "excluded audience", &incident_fanfare_event_input_enum_definition },
		{ _field_legacy, _field_byte_flags, "broad cast message", &incident_fanfare_event_flags_definition },
		{ _field_legacy, _field_pad, "PADME", 1 },
		{ _field_legacy, _field_string_id, "fanfare string" },
		{ _field_legacy, _field_short_integer, "fanfare sprite index" },
		{ _field_legacy, _field_short_integer, "display time in seconds" },
		{ _field_legacy, _field_tag_reference, "hud screen reference", &Tag::Reference<struct CuiScreenDefinition>::s_defaultDefinition },
		{ _field_legacy, _field_tag_reference, "sound response", &sound_response_group_reference },
		{ _field_legacy, _field_string_id, "carried object type" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(game_incident_response_block, MAXIMUM_GAME_INCIDENT_RESPONSES_PER_BLOCK)
	{
		{ _field_legacy, _field_custom, "allowed game modes" },
		{ _field_legacy, _field_struct, "allowed game modes", &game_mode_flags_struct_struct_definition },
		{ _field_legacy, _field_custom },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 4 },
		{ _field_legacy, _field_custom, "allowed campaign and firefight" },
		{ _field_legacy, _field_string_id, "allowed level name#Can only be triggered on this level." },
		{ _field_legacy, _field_long_flags, "required skulls#These skulls must be enabled to trigger.", &skull_flags_definition },
		{ _field_legacy, _field_custom },

		{ _field_legacy, _field_long_integer, "heat award" },
		{ _field_legacy, _field_string_id, "game engine event" },
		{ _field_legacy, _field_string_id, "medal" },
		{ _field_legacy, _field_string_id, "commendation" },
		{ _field_legacy, _field_string_id, "achievement" },
		{ _field_legacy, _field_string_id, "avatar award" },
		{ _field_legacy, _field_block, "challenges", &game_incident_daily_challenge_to_increment_block_block },
		{ _field_legacy, _field_string_id, "hs script" },
		{ _field_legacy, _field_short_integer, "internal hs script index!*~" },
		{ _field_legacy, _field_pad, "VHSLKJNE", 2 },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_legacy, _field_block, "fanfare", &specialized_incident_fanfare_block_block },
		{ _field_legacy, _field_tag_reference, "sound response", &sound_incident_response_group_reference },

		{ _field_legacy, _field_terminator }
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

} // namespace blofeld

