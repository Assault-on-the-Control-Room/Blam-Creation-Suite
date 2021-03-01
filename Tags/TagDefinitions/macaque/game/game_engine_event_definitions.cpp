#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define GAME_ENGINE_EVENT_BLOCK_STRUCT_ID { 0x935C1570, 0xF1054278, 0x92110297, 0xDF082665 }
	TAG_BLOCK(
		game_engine_event_block,
		"game_engine_event_block",
		k_maximum_game_engine_event_responses,
		"s_game_engine_event_response_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		GAME_ENGINE_EVENT_BLOCK_STRUCT_ID)
	{
		{ _field_string_id, "name", MAKE_OLD_NAMES("incident"), FIELD_FLAG_INDEX },
		{ _field_char_enum, "audience", FIELD_FLAG_INDEX, &game_engine_event_audience_enum_definition },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 2 },
		{ _field_legacy, _field_char_integer, "unknown" },
		{ _field_legacy, _field_pad, "pad0", 2 },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		FIELD_PAD("pad0", nullptr, FIELD_FLAG_NONE, 3),

		{ _field_string_id, "display string", "This string can use a bunch of neat tokens for substitution of runtime data (e.g. player names).  See an engineer for more info." },
		{ _field_char_enum, "required field", &game_engine_event_input_enum_definition },
		{ _field_byte_flags, "excluded audience", &game_engine_event_input_enum_definition },
		{ _field_char_enum, "splitscreen suppression", &game_engine_event_splitscreen_suppression_enum_definition },
		{ _field_byte_flags, "flags", &game_engine_event_flags_definition },
		{ _field_string_id, "primary string", "This string can use a bunch of neat tokens for substitution of runtime data (e.g. player names).  See an engineer for more info." },
		{ _field_long_integer, "primary string duration", nullptr, "seconds" },
		{ _field_real, "sound delay (announcer only)", "After we commit to playing this sound, wait this long to actually play it.  Used to control announcer cadence." },
		{ _field_struct, "default_sound", &sound_response_definition_struct },
		FIELD_EXPLANATION("SOUND PRIORITIZATION", nullptr, FIELD_FLAG_NONE, "A data-driven way to choose between halo 3 mp\'s always-queue behavior vs. odst firefight\'s always-suppress-older-multikills behavior."),
		{ _field_string_id, "category_for_prioritization", "which family does this response live in for announcer-spew-suppression?  e.g. all multi-kills should use the same string_id here." },
		{ _field_long_integer, "sound priority", "higher numbers mean more important" },
		{ _field_real, "priority_suppression_age_max_seconds", "If a sound from this event has been queued for more than this long, it can't be suppressed anymore.  Higher values cause a shallower announcer queue for these sounds.", "seconds" },
		FIELD_EXPLANATION("SOUND PAIR CULLING", nullptr, FIELD_FLAG_NONE, "A way to say flag taken + flag dropped = silence."),
		{ _field_string_id, "category_for_pair_culling", "e.g. flag taken and flag dropped should use the same id here, while ball taken and ball dropped should use another shared id." },
		{ _field_long_integer, "pair_id", "0 or 1, used to recognized matched pairs.  If both a 0 and a 1 are in the queue at the same time, and neither has started playing, both are removed." },
		{ _field_real, "delay_before_considering_sound_seconds", "Used to keep a sound in the queue so later sounds can priority-suppress or pair-suppress it", "seconds" },
		{ _field_block, "sound permutations", &sound_response_definition_block },
		{ _field_terminator }
	};

	#define SOUND_RESPONSE_DEFINITION_BLOCK_ID { 0xDFB84E8C, 0x19834057, 0x80B714A7, 0xEE445191 }
	TAG_BLOCK(
		sound_response_definition_block,
		"sound_response_definition_block",
		10,
		"s_game_engine_event_sound_response_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SOUND_RESPONSE_DEFINITION_BLOCK_ID)
	{
		{ _field_struct, "sound_response_definition_struct", &sound_response_definition_struct },
		{ _field_terminator }
	};

	#define SOUND_RESPONSE_DEFINITION_STRUCT_ID { 0xA50C3138, 0x066E4CA0, 0x91825778, 0xDCAFD913 }
	TAG_STRUCT(
		sound_response_definition_struct,
		"sound_response_definition_struct",
		"s_game_engine_event_sound_response_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SOUND_RESPONSE_DEFINITION_STRUCT_ID)
	{
		{ _field_byte_flags, "sound flags", &game_engine_sound_response_flags_definition },
		FIELD_PAD("AGQD", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_tag_reference, "sound", MAKE_OLD_NAMES("english sound"), FIELD_FLAG_INDEX, &global_sound_reference },
		{ _field_real, "probability", "Ignored for the default sound - used for sound permutation block entries only." },
		{ _field_terminator }
	};

	STRINGS(game_engine_event_flags_definition)
	{
		"always play sound#used for respawn ticks and final tick in halo 3",
		"always play sound in mp#so you can make multi kill sounds never be suppressed in MP"
	};
	STRING_LIST(game_engine_event_flags_definition, game_engine_event_flags_definition_strings, _countof(game_engine_event_flags_definition_strings));

	STRINGS(game_engine_event_audience_enum_definition)
	{
		"cause player",
		"cause team",
		"effect player",
		"effect team",
		"all"
	};
	STRING_LIST(game_engine_event_audience_enum_definition, game_engine_event_audience_enum_definition_strings, _countof(game_engine_event_audience_enum_definition_strings));

	STRINGS(game_engine_event_input_enum_definition)
	{
		"NONE",
		"cause player",
		"cause team",
		"effect player",
		"effect team"
	};
	STRING_LIST(game_engine_event_input_enum_definition, game_engine_event_input_enum_definition_strings, _countof(game_engine_event_input_enum_definition_strings));

	STRINGS(game_engine_event_splitscreen_suppression_enum_definition)
	{
		"NONE",
		"Suppress Audio",
		"Suppress Audio if Overlapping",
		"Suppress Text",
		"Suppress Audio and Text"
	};
	STRING_LIST(game_engine_event_splitscreen_suppression_enum_definition, game_engine_event_splitscreen_suppression_enum_definition_strings, _countof(game_engine_event_splitscreen_suppression_enum_definition_strings));

	STRINGS(game_engine_sound_response_flags_definition)
	{
		"announcer sound"
	};
	STRING_LIST(game_engine_sound_response_flags_definition, game_engine_sound_response_flags_definition_strings, _countof(game_engine_sound_response_flags_definition_strings));

} // namespace macaque

} // namespace blofeld

