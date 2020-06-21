#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP(sound_classes, SOUND_CLASSES_TAG)
	{
		{ _field_block, "sound classes", &sound_class_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(sound_class_block, NUMBER_OF_SOUND_CLASSES)
	{
		{ _field_short_integer, "max sounds per tag [1,16]#maximum number of sounds playing per individual sound tag" },

		{ _field_version_greater, _engine_type_haloreach, 3 },
		{ _field_short_integer, "max sounds per object per tag [1,16]{max sounds per object [1,16]}#maximum number of sounds per individual sound tag playing on an object" },
		{ _field_short_integer, "max sounds per class [0,16]#maximum number of sounds playing of this class. zero means ignore." },
		{ _field_short_integer, "max sounds per object per class [0,16]#maximum number of sounds of this class playing on an object. zero means ignore." },

		{ _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_short_integer, "max sounds per object [1,16]#maximum number of sounds of this type playing on an object" },
		
		{ _field_long_integer, "preemption time:ms#replaces other instances after this many milliseconds" },
		{ _field_word_flags, "internal flags!*", &sound_class_internal_flags_definition },
		{ _field_word_flags, "flags", &sound_class_external_flags_definition },
		{ _field_short_integer, "priority#higher means more important" },
		{ _field_char_enum, "cache miss mode*", &sound_class_cache_miss_mode_definition },
		{ _field_byte_flags, "bind to acoustics", &sound_class_acoustics_string_definition },
		{ _field_byte_flags, "suppress spatialization", &sound_class_suppress_spatialization_string_defintion },
		{ _field_pad, "sadf", 3 },
		{ _field_explanation, "air propagation", "" },
		{ _field_real, "air reverb gain{reverb gain}:dB#how much reverb applies to this sound class" },
		{ _field_real, "air direct path gain:dB#how much goes to direct path (dry)" },
		{ _field_real, "air base obstruction" },
		{ _field_real, "air base occlusion" },
		{ _field_explanation, "underwater propagation", "" },
		{ _field_real, "underwater reverb gain:dB#how much reverb applies to this sound class" },
		{ _field_real, "underwater direct path gain:dB#how much goes to direct path (dry)" },
		{ _field_real, "underwater base obstruction" },
		{ _field_real, "underwater base occlusion" },
		{ _field_real, "override speaker gain:dB" },

		{ _field_version_greater, _engine_type_haloreach },
		{ _field_struct, "distance parameters", &sound_distance_parameters_struct_struct_definition },

		{ _field_version_less_or_equal, _engine_type_haloreach, 2 },
		{ _field_real_bounds, "attack bounds" },
		{ _field_real_bounds, "distance bounds" },
		
		{ _field_custom },
		{ _field_real_bounds, "gain bounds:dB~" },

		{ _field_version_greater, _engine_type_haloreach, 8 },
		{ _field_explanation, "lowpass wetmixes", "" },
		{ _field_custom, "equipment lowpass{equipment channel occlusion factor}:wetmix#sets the lowpass wet mix when an equiment is active" },
		{ _field_real, "equipment lowpass{equipment channel occlusion factor}:wetmix#sets the lowpass wet mix when an equiment is active" },
		{ _field_custom, "environment forced lowpass{forced lowpass wet mix}:wetmix#sets the lowpass wet mix when an environment forced lowpass is active" },
		{ _field_real, "environment forced lowpass{forced lowpass wet mix}:wetmix#sets the lowpass wet mix when an environment forced lowpass is active" },
		{ _field_custom, "effect lowpass:wetmix#sets the lowpass wet mix when a lowpass effect is active" },
		{ _field_real, "effect lowpass:wetmix#sets the lowpass wet mix when a lowpass effect is active" },
		{ _field_explanation, "ducking", "" },

		{ _field_real, "cutscene ducking:dB" },
		{ _field_real, "cutscene ducking fade in time:seconds" },
		{ _field_real, "cutscene ducking sustain time:seconds#how long this lasts after the cutscene ends" },
		{ _field_real, "cutscene ducking fade out time:seconds" },
		{ _field_real, "scripted dialog ducking:dB" },
		{ _field_real, "scripted dialog ducking fade in time:seconds" },
		{ _field_real, "scripted dialog ducking sustain time:seconds#how long this lasts after the scripted dialog ends" },
		{ _field_real, "scripted dialog ducking fade out time:seconds" },
		{ _field_real, "equipment channel ducking:dB" },
		{ _field_real, "equipment channel ducking fade in time:seconds" },

		{ _field_version_greater, _engine_type_haloreach },
		{ _field_real, "equipment channel ducking sustain time:seconds#how long this lasts after the equipment is turned off" },
		
		{ _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_real, "equipment channel ducking sustain time:seconds#how long this lasts after the scripted dialog ends" },
		
		{ _field_real, "equipment channel ducking fade out time:seconds" },

		{ _field_version_greater, _engine_type_haloreach, 5 },
		{ _field_real, "between rounds ducking:dB" },
		{ _field_real, "between rounds ducking fade in time:seconds" },
		{ _field_real, "between rounds ducking sustain time:seconds#how long this lasts after we get back in the game" },
		{ _field_real, "between rounds ducking fade out time:seconds" },
		{ _field_explanation, "misc", "" },

		{ _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_real, "equipment channel occlusion factor:ratio#zero (no occlusion) to one (full occlusion)" },
		
		{ _field_real, "doppler factor" },
		{ _field_char_enum, "stereo playback type", &sound_class_stereo_playback_definition },
		{ _field_pad, "B", 3 },
		{ _field_real, "transmission multiplier" },

		{ _field_version_greater, _engine_type_haloreach },
		{ _field_real, "transmission interpolation time:seconds#default is 0.5 seconds" },

		{ _field_version_less_or_equal, _engine_type_haloreach, 2 },
		{ _field_real, "obstruction max bend" },
		{ _field_real, "occlusion max bend" },
		
		{ _field_long_integer, "xma compression level" },
		{ _field_real, "send to lfe gain:dB#When send (mono) to lfe is set, this is how much additional gain to apply" },

		{ _field_version_greater, _engine_type_haloreach, 3 },
		{ _field_long_integer, "minimum facial animation delay:msecs#setting this forces sounds of this class to be delayed while the facial animation resource loads." },
		{ _field_long_integer, "maximum facial animation delay:msecs#setting this allows sounds of this class to be delayed while the facial animation resource loads." },
		{ _field_long_integer, "maximum facial animation blend:msecs#setting this makes sounds blends in facial animation (will cut off at maximum facial animation delay)." },
		
		{ _field_terminator }
	};

	STRINGS(sound_class_internal_flags_definition)
	{
		"valid",
		"is speech",
		"scripted",
		"stops with object",
		"valid xma compression level",
		"valid doppler factor",
		"valid obstruction factor",
		"multilingual",
		"don\'t strip languages",
		"valid underwater propagation",
		"valid suppress spatialization"
	};
	STRING_LIST(sound_class_internal_flags_definition, sound_class_internal_flags_definition_strings, _countof(sound_class_internal_flags_definition_strings));

	STRINGS(sound_class_external_flags_definition)
	{
		"plays during pause",
		"bypass default dsp effects{dry stereo mix}",
		"no object obstruction!",
		"use center speaker unspatialized",
		"send (mono) to lfe",
		"deterministic",
		"use huge transmission",
		"always use speakers",
		"don\'t strip from main menu",
		"ignore stereo headroom",
		"loop fade out is linear",
		"stop when object dies",
		"don\'t fade on game over",
		"don\'t promote priority by proximity"
	};
	STRING_LIST(sound_class_external_flags_definition, sound_class_external_flags_definition_strings, _countof(sound_class_external_flags_definition_strings));

	STRINGS(sound_class_cache_miss_mode_definition)
	{
		"discard",
		"postpone"
	};
	STRING_LIST(sound_class_cache_miss_mode_definition, sound_class_cache_miss_mode_definition_strings, _countof(sound_class_cache_miss_mode_definition_strings));

	STRINGS(sound_class_stereo_playback_definition)
	{
		"first person",
		"ambient"
	};
	STRING_LIST(sound_class_stereo_playback_definition, sound_class_stereo_playback_definition_strings, _countof(sound_class_stereo_playback_definition_strings));

	STRINGS(sound_class_acoustics_string_definition)
	{
		"outside",
		"inside"
	};
	STRING_LIST(sound_class_acoustics_string_definition, sound_class_acoustics_string_definition_strings, _countof(sound_class_acoustics_string_definition_strings));

	STRINGS(sound_class_suppress_spatialization_string_defintion)
	{
		"first person",
		"third person"
	};
	STRING_LIST(sound_class_suppress_spatialization_string_defintion, sound_class_suppress_spatialization_string_defintion_strings, _countof(sound_class_suppress_spatialization_string_defintion_strings));

} // namespace blofeld

