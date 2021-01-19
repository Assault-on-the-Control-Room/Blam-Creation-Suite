#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define SOUND_CLASSES_STRUCT_DEFINITION_ID { 0x75FD0DA6, 0x09ED40AC, 0x89E9FCF7, 0x523A0B97 }
	TAG_BLOCK(
		sound_classes_block,
		"sound_classes_block",
		1,
		"s_sound_classes_definition",
		SOUND_CLASSES_STRUCT_DEFINITION_ID)
	{
		{ _field_block, "sound classes", &sound_class_block },
		{ _field_terminator }
	};

	TAG_GROUP(
		sound_classes_group,
		SOUND_CLASSES_TAG,
		nullptr,
		INVALID_TAG,
		sound_classes_block );

	#define SOUND_CLASS_BLOCK_STRUCT_ID { 0xDECE1540, 0x806F499C, 0x88FCD3BC, 0x96250604 }
	TAG_BLOCK(
		sound_class_block,
		"sound_class_block",
		NUMBER_OF_SOUND_CLASSES,
		"sound_class_definition",
		SOUND_CLASS_BLOCK_STRUCT_ID)
	{
		{ _field_short_integer, "max sounds per tag [1,16]#maximum number of sounds playing per individual sound tag" },
		{ _field_short_integer, "max sounds per object per tag [1,16]{max sounds per object [1,16]}#maximum number of sounds per individual sound tag playing on an object" },
		{ _field_short_integer, "max sounds per class [0,16]#maximum number of sounds playing of this class. zero means ignore." },
		{ _field_short_integer, "max sounds per object per class [0,16]#maximum number of sounds of this class playing on an object. zero means ignore." },
		{ _field_long_integer, "preemption time:ms#replaces other instances after this many milliseconds" },
		{ _field_word_flags, "internal flags!*", &sound_class_internal_flags_definition },
		{ _field_word_flags, "flags", &sound_class_external_flags_definition },
		{ _field_short_integer, "priority#higher means more important" },
		{ _field_char_enum, "cache miss mode*", &sound_class_cache_miss_mode_definition },
		{ _field_byte_flags, "bind to acoustics", &sound_class_acoustics_string_definition },
		{ _field_byte_flags, "suppress spatialization", &sound_class_suppress_spatialization_string_defintion },
		{ _field_pad, "sadf", 3 },
		{ _field_explanation, "air propagation", "" },
		{ _field_real, "air reverb gain{reverb gain}:dB#how much reverb applies to this sound class", nullptr, '+dB+' },
		{ _field_real, "air direct path gain:dB#how much goes to direct path (dry)", nullptr, '+dB+' },
		{ _field_real, "air base obstruction" },
		{ _field_real, "air base occlusion" },
		{ _field_explanation, "underwater propagation", "" },
		{ _field_real, "underwater reverb gain:dB#how much reverb applies to this sound class", nullptr, '+dB+' },
		{ _field_real, "underwater direct path gain:dB#how much goes to direct path (dry)", nullptr, '+dB+' },
		{ _field_real, "underwater base obstruction" },
		{ _field_real, "underwater base occlusion" },
		{ _field_real, "override speaker gain:dB", nullptr, '+dB+' },
		{ _field_struct, "distance parameters", &sound_distance_parameters_struct },
		FIELD_CUSTOM(nullptr, 0),
		{ _field_real_bounds, "gain bounds:dB~", nullptr, '+dB+' },
		{ _field_explanation, "lowpass wetmixes", "" },
		FIELD_CUSTOM("equipment lowpass{equipment channel occlusion factor}:wetmix#sets the lowpass wet mix when an equiment is active", _custom_field_slider_editor),
		{ _field_real, "equipment lowpass{equipment channel occlusion factor}:wetmix#sets the lowpass wet mix when an equiment is active", nullptr, 'sled' },
		FIELD_CUSTOM("environment forced lowpass{forced lowpass wet mix}:wetmix#sets the lowpass wet mix when an environment forced lowpass is active", _custom_field_slider_editor),
		{ _field_real, "environment forced lowpass{forced lowpass wet mix}:wetmix#sets the lowpass wet mix when an environment forced lowpass is active", nullptr, 'sled' },
		FIELD_CUSTOM("effect lowpass:wetmix#sets the lowpass wet mix when a lowpass effect is active", _custom_field_slider_editor),
		{ _field_real, "effect lowpass:wetmix#sets the lowpass wet mix when a lowpass effect is active", nullptr, 'sled' },
		{ _field_explanation, "ducking", "" },
		{ _field_real, "cutscene ducking:dB", nullptr, '+dB+' },
		{ _field_real, "cutscene ducking fade in time:seconds" },
		{ _field_real, "cutscene ducking sustain time:seconds#how long this lasts after the cutscene ends" },
		{ _field_real, "cutscene ducking fade out time:seconds" },
		{ _field_real, "scripted dialog ducking:dB", nullptr, '+dB+' },
		{ _field_real, "scripted dialog ducking fade in time:seconds" },
		{ _field_real, "scripted dialog ducking sustain time:seconds#how long this lasts after the scripted dialog ends" },
		{ _field_real, "scripted dialog ducking fade out time:seconds" },
		{ _field_real, "equipment channel ducking:dB", nullptr, '+dB+' },
		{ _field_real, "equipment channel ducking fade in time:seconds" },
		{ _field_real, "equipment channel ducking sustain time:seconds#how long this lasts after the equipment is turned off" },
		{ _field_real, "equipment channel ducking fade out time:seconds" },
		{ _field_real, "between rounds ducking:dB", nullptr, '+dB+' },
		{ _field_real, "between rounds ducking fade in time:seconds" },
		{ _field_real, "between rounds ducking sustain time:seconds#how long this lasts after we get back in the game" },
		{ _field_real, "between rounds ducking fade out time:seconds" },
		{ _field_explanation, "misc", "" },
		{ _field_real, "doppler factor" },
		{ _field_char_enum, "stereo playback type", &sound_class_stereo_playback_definition },
		{ _field_pad, "B", 3 },
		{ _field_real, "transmission multiplier" },
		{ _field_real, "transmission interpolation time:seconds#default is 0.5 seconds" },
		{ _field_long_integer, "xma compression level" },
		{ _field_real, "send to lfe gain:dB#When send (mono) to lfe is set, this is how much additional gain to apply", nullptr, '+dB+' },
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

} // namespace macaque

} // namespace blofeld

