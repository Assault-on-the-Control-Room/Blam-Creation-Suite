#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{
	TAG_STRUCT(sound_mix_equalizer)
	{
		{ _field_long_integer, "unknown" },
		{ _field_real, "base db" },
		{ _field_real, "40hz" },
		{ _field_real, "50hz" },
		{ _field_real, "63hz" },
		{ _field_real, "80hz" },
		{ _field_real, "100hz" },
		{ _field_real, "125hz" },
		{ _field_real, "160hz" },
		{ _field_real, "200hz" },
		{ _field_real, "250hz" },
		{ _field_real, "315hz" },
		{ _field_real, "400hz" },
		{ _field_real, "500hz" },
		{ _field_real, "630hz" },
		{ _field_real, "800hz" },
		{ _field_real, "1000hz" },
		{ _field_real, "1250hz" },
		{ _field_real, "1600hz" },
		{ _field_real, "2000hz" },
		{ _field_real, "2500hz" },
		{ _field_real, "3150hz" },
		{ _field_real, "4000hz" },
		{ _field_real, "5000hz" },
		{ _field_real, "6300hz" },
		{ _field_real, "8000hz" },
		{ _field_real, "10000hz" },
		{ _field_real, "12500hz" },
		{ _field_terminator }
	};

	TAG_GROUP(sound_mix_mastering, SOUND_MIX_MASTERING_TAG)
	{
		{ _field_long_integer, "unknown@" },
		{ _field_short_integer, "unknown" },
		{ _field_short_integer, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_real, "base db" },
		{ _field_real, "left db@" },
		{ _field_real, "right db@" },
		{ _field_real, "ambient db@" },
		{ _field_real, "object db@" },
		{ _field_real, "unknown@" },
		{ _field_struct, "equalizer a", &sound_mix_equalizer_struct_definition },
		{ _field_struct, "equalizer b", &sound_mix_equalizer_struct_definition },

		{ _field_terminator }
	};

	TAG_GROUP(soundbank, SOUNDBANK_TAG)
	{
		{ _field_long_flags, "flags", &SoundBankDefinitionFlags },
		{ _field_long_flags, "import flags!", &sound_import_flags },
		{ _field_long_flags, "xsync flags!", &sound_xsync_flags },
		{ _field_block, "Sound bank list#List of names of soundbanks. If more than one, one will be randomly chosen at load", &SoundBankBlock_block },
		{ _field_long_integer, "Bank priority#the importance of this bank over others. 1 is highest priority (ie will bump all others)" },
		{ _field_long_integer, "Bank unique ID" },
		{ _field_terminator }
	};

	TAG_GROUP(sound_global_propagation, SOUND_GLOBAL_PROPAGATION_TAG)
	{
		{ _field_explanation, "underwater propagation globals", "" },
		{ _field_struct, "underwater propagation", &sound_propagation_definition_struct_struct_definition },
		{ _field_terminator }
	};

	TAG_STRUCT(sound_group)
	{
		{_field_version_less_or_equal, _engine_type_haloreach, 2 },
		{ _field_struct, "playback", &cache_file_sound_struct_definition_struct_definition },
		{ _field_block, "extra info!", &sound_extra_info_block_block },

		{_field_version_greater, _engine_type_haloreach, 13 },
		{ _field_long_flags, "flags", &SoundEventDefinitionFlags },
		{ _field_long_flags, "import flags!", &sound_import_flags },
		{ _field_long_flags, "xsync flags!", &sound_xsync_flags },
		{ _field_string_id, "Event Name#Sound event name." },
		{ _field_string_id, "Player Event Name#Optional sound event name for player only." },
		{ _field_string_id, "Fallback Event Name#Fallback sound event if the others don\'t play - should be an a guaranteed bank." },
		{ _field_real, "Max Radius" },
		{ _field_real, "Max Duration#Max duration of this event. Enter manually for now - will auto-fill later." },
		{ _field_real, "Don\'t play time.#Time the event will not retrigger for (global)" },
		{ _field_long_integer, "Hidden runtime info index!" },
		{ _field_tag_reference, "Sound bank#Reference to the sound bank tag this event is in. Can be empty.", &global_soundbank_reference },
		{ _field_block, "lipsync info", &soundLipSyncInfoBlock_block },
		{ _field_long_integer, "deterministic flag index" },

		{ _field_terminator }
	};
	TAG_BLOCK_FROM_STRUCT(sound_group, 1, sound_group_struct_definition);
	TAG_GROUP_FROM_BLOCK(sound, SOUND_TAG, sound_group_block);

	TAG_GROUP(sound_old, SOUND_OLD_TAG)
	{
		{ _field_long_flags, "flags", &sound_definition_flags },
		{ _field_long_flags, "import flags!", &sound_import_flags },
		{ _field_long_flags, "xsync flags!", &sound_xsync_flags },
		{ _field_char_enum, "class", &sound_class_enum },
		{ _field_char_enum, "sample rate*", &sound_sample_rate_enum },
		{ _field_char_integer, "override xma compression:[1-100]" },
		{ _field_char_enum, "import type*", &sound_import_type_enum },
		{ _field_struct, "playback", &sound_playback_parameters_struct_struct_definition },
		{ _field_struct, "scale", &sound_scale_modifiers_struct_struct_definition },
		{ _field_explanation, "sub priority", "Used to compare individual sounds in the same class. Higher means more important. (Negative means do not use.)" },
		{ _field_real, "sub priority" },
		{ _field_explanation, "import properties", "" },
		{ _field_char_enum, "encoding*", &sound_encoding_enum },
		{ _field_char_enum, "compression*", &sound_compression_enum },
		{ _field_pad, "pad", 2 },
		{ _field_struct, "promotion", &sound_promotion_parameters_struct_struct_definition },
		{ _field_pad, "runtime pad~", 4 },
		{ _field_block, "pitch ranges*#pitch ranges allow multiple samples to represent the same sound at different pitches", &sound_pitch_range_block_block },
		{ _field_block, "platform parameters", &sound_platform_sound_playback_block_block },
		{ _field_pageable, "sound data resource" },
		{ _field_block, "extra info!", &sound_extra_info_block_block },
		{ _field_block, "language info!", &sound_language_info_block_block },
		{ _field_terminator }
	};

	TAG_GROUP(sound2, SOUND2_TAG)
	{
		{ _field_long_flags, "flags", &sound_definition_flags },
		{ _field_long_flags, "import flags!", &sound_import_flags },
		{ _field_long_flags, "xsync flags!", &sound_xsync_flags },
		{ _field_char_enum, "class", &sound_class_enum },
		{ _field_char_enum, "sample rate*", &sound_sample_rate_enum },
		{ _field_char_integer, "override xma compression:[1-100]" },
		{ _field_char_enum, "import type*", &sound_import_type_enum },
		{ _field_struct, "playback", &sound_playback_parameters_struct_struct_definition },
		{ _field_struct, "scale", &sound_scale_modifiers_struct_struct_definition },
		{ _field_explanation, "sub priority", "Used to compare individual sounds in the same class. Higher means more important. (Negative means do not use.)" },
		{ _field_real, "sub priority" },
		{ _field_explanation, "import properties", "" },
		{ _field_char_enum, "encoding*", &sound_encoding_enum },
		{ _field_char_enum, "compression*", &sound_compression_enum },
		{ _field_pad, "pad", 2 },
		{ _field_struct, "promotion", &sound_promotion_parameters_struct_struct_definition },
		{ _field_pad, "runtime pad~", 4 },
		{ _field_block, "pitch ranges*#pitch ranges allow multiple samples to represent the same sound at different pitches", &sound_pitch_range_block_block },
		{ _field_block, "platform parameters", &sound_platform_sound_playback_block_block },
		{ _field_pageable, "sound data resource" },
		{ _field_block, "extra info!", &sound_extra_info_block_block },
		{ _field_block, "language info!", &sound_language_info_block_block },
		{ _field_terminator }
	};

	TAG_GROUP(sound_mix, SOUND_MIX_TAG)
	{
		{ _field_struct, "default transmission settings", &sound_transmission_definition_struct_struct_definition },
		{ _field_explanation, "first person left side mix", "for first person sounds to the left of you" },
		{ _field_struct, "first person left side mix", &sound_stereo_mix_struct_struct_definition },
		{ _field_explanation, "first person middle mix", "for first person sounds between your ears" },
		{ _field_struct, "first person middle mix", &sound_stereo_mix_struct_struct_definition },
		{ _field_explanation, "first person right side mix", "for first person sounds to the right of you" },
		{ _field_struct, "first person right side mix", &sound_stereo_mix_struct_struct_definition },
		{ _field_explanation, "first person surround mix", "" },
		{ _field_struct, "first person surround mix", &sound_surround_mix_struct_struct_definition },
		{ _field_explanation, "ambient surround mix", "" },
		{ _field_struct, "ambient surround mix", &sound_surround_mix_struct_struct_definition },
		{ _field_explanation, "global mix", "" },
		{ _field_struct, "global mix", &sound_global_mix_struct_struct_definition },
		{ _field_terminator }
	};

	TAG_GROUP_FROM_BLOCK(sound_dialogue_constants, SOUND_DIALOGUE_CONSTANTS_TAG, sound_dialogue_constants_block_block );

	TAG_BLOCK(StreamingPackBlock, k_maximum_streaming_packs)
	{
		{ _field_long_flags, "flags", &StreamingPackBlockFlags },
		{ _field_string, "Streaming pck file#Name of the stream pack file" },
		{ _field_terminator }
	};

	TAG_BLOCK(campaign_unspatialized_sounds_block, k_maximum_campaign_unspatialized_sounds)
	{
		{ _field_tag_reference, "sound^", &global_sound_reference },
		{ _field_terminator }
	};

	TAG_BLOCK(sound_globals_block, 1)
	{
		{ _field_tag_reference, "sound classes", &sound_classes_reference },
		{ _field_tag_reference, "sound effects", &global_sound_effect_collection_reference },

		{ _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_tag_reference, "sound mastering", &sound_mix_reference },

		{ _field_tag_reference, "sound mix", &sound_mix_reference },
		{ _field_tag_reference, "sound combat dialogue constants", &sound_dialogue_constants_reference },
		{ _field_tag_reference, "sound propagation", &sound_global_propagation_reference },
		
		{ _field_version_greater, _engine_type_haloreach, 6 },
		{ _field_tag_reference, "Init sound bank#Init sound bank for WWise.", &global_soundbank_reference },
		{ _field_tag_reference, "Global sound bank#Global sound bank for WWise.", &global_soundbank_reference },
		{ _field_tag_reference, "Extra sound bank#The other sound bank for WWise.", &global_soundbank_reference },
		{ _field_tag_reference, "Campaign sound bank#Extra sound bank for WWise - only loaded for Campaign.", &global_soundbank_reference },
		{ _field_tag_reference, "Multiplayer sound bank#Extra sound bank for WWise - only loaded for MP - PVP.", &global_soundbank_reference },
		{ _field_block, "Streaming pack files", &StreamingPackBlock_block },

		{ _field_block, "un-spatialized campaign sounds", &campaign_unspatialized_sounds_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(SoundBankBlock, k_maximumSoundBanksPerTag)
	{
		{ _field_string_id, "Sound bank name#Name of the main sound bank." },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(deterministicSpeechEventBlock, MAXIMUM_PERMUTATIONS_PER_PITCH_RANGE, deterministicSpeechEventBlock_struct_struct_definition );

	TAG_BLOCK(facial_animation_language_block, k_language_count)
	{
		{ _field_pageable, "facial animation resource" },
		{ _field_long_enum, "language", &sound_language_enum_definition },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(soundLipSyncInfoBlock, 1, soundLipSyncInfoBlock_struct_struct_definition );

	TAG_BLOCK(sound_promotion_rule_block, k_maximum_promotion_rules_per_sound)
	{
		{ _field_short_block_index, "pitch range^" },
		{ _field_short_integer, "maximum playing count" },
		{ _field_real, "suppression time:seconds#time from when first permutation plays to when another sound from an equal or lower promotion can play" },
		{ _field_long_integer, "runtime rollover time!" },
		{ _field_long_integer, "impulse promotion time!" },
		{ _field_terminator }
	};

	TAG_BLOCK(sound_promotion_runtime_timer_block, k_maximum_promotion_rules_per_sound)
	{
		{ _field_long_integer, "timer storage~!" },
		{ _field_terminator }
	};

	TAG_BLOCK(sound_permutation_chunk_block, UNSIGNED_SHORT_MAX*4)
	{
		{ _field_long_integer, "file offset*" },
		{ _field_long_integer, "encoded size and flags~!" },
		{ _field_long_block_index, "cache index~!" },
		{ _field_long_integer, "xma2_source_buffer_sample_start*" },
		{ _field_long_integer, "xma2_source_buffer_sample_end*" },
		{ _field_terminator }
	};

	TAG_BLOCK(sound_permutation_languages_block, k_language_count)
	{
		{ _field_long_integer, "uncompressed sample count" },
		{ _field_block, "chunks", &sound_permutation_chunk_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(sound_permutations_block, MAXIMUM_PERMUTATIONS_PER_PITCH_RANGE)
	{
		{ _field_custom },
		{ _field_string_id, "name*^#name of the file from which this sample was imported" },
		{ _field_custom },
		{ _field_real_fraction, "skip fraction#fraction of requests to play this permutation that are ignored (a different permutation is selected.)" },
		{ _field_custom },
		{ _field_real, "gain:dB#additional attenuation when played" },
		{ _field_custom_short_block_index, "raw info!" },
		{ _field_short_block_index, "play fraction type!" },
		{ _field_short_bounds, "mission range#first and last mission ids this permutation can play in (zero values are ignored)" },
		{ _field_word_flags, "permutation flags", &sound_permutation_external_flags },
		{ _field_word_flags, "flags!*", &sound_permutation_flags },
		{ _field_block, "languages!", &sound_permutation_languages_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(sound_pitch_range_block, MAXIMUM_PITCH_RANGES_PER_SOUND)
	{
		{ _field_string_id, "name*#the name of the imported pitch range directory" },
		{ _field_explanation, "pitch control", "these settings control what pitches this set of samples represents. if there is only one pitch range, all three values are ignored." },
		{ _field_short_integer, "natural pitch:cents#the apparent pitch when these samples are played at their recorded pitch." },
		{ _field_pad, "KCTSDWPP~", 2 },
		{ _field_short_bounds, "bend bounds:cents#the range of pitches that will be represented using this sample." },
		{ _field_short_bounds, "full volume bounds!:cents#the range of pitches that map to full gain." },
		{ _field_short_bounds, "playback bend bounds:cents#the actual pitch will be clamped to this" },
		{ _field_struct, "distance parameters", &sound_distance_parameters_struct_struct_definition },
		{ _field_pad, "YAMTVB~", 4 },
		{ _field_char_integer, "runtime usable permutation count!" },
		{ _field_byte_flags, "xsync flags!", &sound_pitch_range_internal_xsync_flags },
		{ _field_pad, "asdf", 2 },
		{ _field_block, "permutations*#permutations represent equivalent variations of this sound.", &sound_permutations_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(sound_platform_sound_playback_block, 1)
	{
		{ _field_struct, "playback definition", &platform_sound_playback_struct_struct_definition },
		{ _field_terminator }
	};

	TAG_BLOCK(sound_permutation_marker_block, MAXIMUM_MARKERS_PER_PERMUTATION)
	{
		{ _field_long_integer, "marker id*" },
		{ _field_string_id, "name^*" },
		{ _field_long_integer, "sample offset*" },
		{ _field_custom },
		{ _field_terminator }
	};

	TAG_BLOCK(sound_xma2_seek_table_block, MAXIMUM_SOUND_DATA_SIZE/k_kilo)
	{
		{ _field_long_integer, "block relative sample start*" },
		{ _field_long_integer, "block relative sample end" },
		{ _field_long_integer, "starting sample index*" },
		{ _field_long_integer, "ending sample index*" },
		{ _field_long_integer, "starting xma2 offset*" },
		{ _field_long_integer, "ending xma2 offset*" },
		{ _field_terminator }
	};

	TAG_BLOCK(sound_permutation_raw_info_block, 2*k_language_count)
	{
		{ _field_version_less_or_equal, _engine_type_haloreach, 1 },
		{ _field_long_integer, "unknown" },

		{ _field_version_greater, _engine_type_haloreach, 9 },
		{ _field_string_id, "skip fraction name" },
		{ _field_data, "samples!#sampled sound data" },
		{ _field_block, "markers!", &sound_permutation_marker_block_block },
		{ _field_block, "layer markers!", &sound_permutation_marker_block_block },
		{ _field_block, "xma2 seek table!", &sound_xma2_seek_table_block_block },
		{ _field_enum, "compression*", &sound_compression_enum },
		{ _field_char_enum, "language*", &sound_language_enum_definition },
		{ _field_pad, "ZHDGBHWS", 1 },
		{ _field_long_integer, "sample count!" },

		{ _field_long_integer, "resource sample offset!" },
		{ _field_long_integer, "resource sample size!" },
		{ _field_terminator }
	};

	TAG_BLOCK(sound_definition_language_permutation_info_block, MAXIMUM_PITCH_RANGES_PER_SOUND*MAXIMUM_PERMUTATIONS_PER_PITCH_RANGE*2)
	{
		{ _field_version_less_or_equal, _engine_type_haloreach, 4 },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },

		{ _field_block, "raw info block", &sound_permutation_raw_info_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(sound_extra_info_block, 1)
	{
		{ _field_block, "language permutation info", &sound_definition_language_permutation_info_block_block },

		{ _field_version_less_or_equal, _engine_type_haloreach, 4 },
		{ _field_data, "facial animation resource" }, // #TODO: Research, not 100% that this is facial animation resource but the format might have changed?
		{ _field_long_integer, "unknown" },
		{ _field_long_integer, "unknown@" },
		{ _field_long_enum, "language", &sound_language_enum_definition },

		{ _field_version_greater, _engine_type_haloreach, 1 },
		{ _field_block, "facial animation resource languages", &facial_animation_language_block_block },

		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(sound_dialogue_constants_block, 1, sound_dialogue_constants_struct_definition_struct_definition );

	TAG_BLOCK_FROM_STRUCT(sound_pitch_range_distances_block, SHORT_MAX, sound_distance_parameters_struct_struct_definition );

	TAG_STRUCT(sound_distance_parameters_struct)
	{
		{ _field_explanation, "attenuation distances", "these settings vary how the sound fades as you move closer or further away from it." },
		{ _field_real, "don\'t obstruct distance:world units#don\'t obstruct below this distance" },
		{ _field_real, "don\'t play distance:world units#don\'t play below this distance" },
		{ _field_real, "attack distance:world units#start playing at full volume at this distance" },
		{ _field_real, "minimum distance:world units#start attenuating at this distance" },
		{ _field_real, "sustain begin distance:world units#set attenuation to sustain db at this distance" },
		{ _field_real, "sustain end distance:world units#continue attenuating to silence at this distance" },
		{ _field_real, "maximum distance:world units#the distance beyond which this sound is no longer audible" },
		{ _field_real, "sustain db:dB#the amount of attenuation between sustain begin and end" },
		{ _field_terminator }
	};

	TAG_STRUCT(sound_propagation_definition_struct)
	{
		{ _field_tag_reference, "sound environment", &global_sound_environment_reference },
		{ _field_tag_reference, "background sound", &global_looping_sound_reference },
		{ _field_real, "background sound gain#scale for fog background sound:dB" },
		{ _field_real, "environment ducking#scales the surrounding background sound by this much:dB" },
		{ _field_tag_reference, "entry sound", &global_sound_reference },
		{ _field_tag_reference, "exit sound", &global_sound_reference },
		{ _field_terminator }
	};

	TAG_STRUCT(soundLipSyncInfoBlock_struct)
	{
		{ _field_long_integer, "number of usable facial animations" },
		{ _field_block, "deterministic event info", &deterministicSpeechEventBlock_block },
		{ _field_block, "facial animation resource languages", &facial_animation_language_block_block },
		{ _field_terminator }
	};

	TAG_STRUCT(deterministicSpeechEventBlock_struct)
	{
		{ _field_long_flags, "flags", &SpeechEventInfoFlags },
		{ _field_string_id, "voice file path" },
		{ _field_real, "event duration" },
		{ _field_real, "skip fraction#Percent this file will be skipped when picked. 0 is always, 0.99 is almost never" },
		{ _field_terminator }
	};

	TAG_STRUCT(sound_playback_parameters_struct)
	{
		{ _field_long_integer, "internal flags!" },
		{ _field_real_fraction, "skip fraction#fraction of requests to play this sound that will be ignored (0 means always play.)" },
		{ _field_real, "maximum bend per second:cents" },
		{ _field_struct, "distance parameters{.}", &sound_distance_parameters_struct_struct_definition },
		{ _field_custom },
		{ _field_custom },
		{ _field_explanation, "randomization", "these settings control random variation of volume and pitch.\n the second parameter gets clipped to the first." },
		{ _field_custom },
		{ _field_real, "gain base:dB#sound\'s random gain will start here" },
		{ _field_real, "gain variance:dB#sound\'s gain will be randomly modulated within this range" },
		{ _field_short_bounds, "random pitch bounds:cents#the sound\'s pitch will be modulated randomly within this range." },
		{ _field_explanation, "directional sounds", "these settings allow sounds to be directional, fading as they turn away from the listener" },
		{ _field_angle, "inner cone angle:degrees#within the cone defined by this angle and the sound\'s direction, the sound plays with a gain of 1.0." },
		{ _field_angle, "outer cone angle:degrees#outside the cone defined by this angle and the sound\'s direction, the sound plays with a gain of OUTER CONE GAIN. (0 means the sound does not attenuate with direction.)" },
		{ _field_real, "outer cone gain:dB#the gain to use when the sound is directed away from the listener" },
		{ _field_explanation, "scripted location override", "NOTE: this will only apply when the sound is started via script\nazimuth:\n    0 => front\n    90 => left\n    180 => back\n    270 => right\n" },
		{ _field_custom },
		{ _field_long_flags, "flags", &sound_override_location_flags_definition },
		{ _field_angle, "azimuth" },
		{ _field_real, "positional gain:dB" },
		{ _field_real, "first person gain:dB" },
		{ _field_terminator }
	};

	TAG_STRUCT(sound_scale_modifiers_struct)
	{
		{ _field_explanation, "scale modifiers", "as the sound\'s input scale changes from zero to one, these modifiers move between the two values specified here. the sound will play using the current scale modifier multiplied by the values specified above. (0 values are ignored.)" },
		{ _field_real_bounds, "gain modifier:dB" },
		{ _field_short_bounds, "pitch modifier:cents" },
		{ _field_real_fraction_bounds, "skip fraction modifier" },
		{ _field_terminator }
	};

	TAG_STRUCT(sound_promotion_parameters_struct)
	{
		{ _field_block, "promotion rules", &sound_promotion_rule_block_block },
		{ _field_block, "runtime timers!", &sound_promotion_runtime_timer_block_block },
		{ _field_long_integer, "runtime active promotion index!" },
		{ _field_long_integer, "runtime last promotion time!" },
		{ _field_long_integer, "runtime suppression timeout!" },
		{ _field_terminator }
	};

	TAG_STRUCT(sound_transmission_definition_struct)
	{
		{ _field_explanation, "default obstruction settings", "" },
		{ _field_struct, "obstruction settings", &global_sound_lowpass_block_struct_definition },
		{ _field_explanation, "default occlusion settings", "" },
		{ _field_struct, "occlusion settings", &global_sound_lowpass_block_struct_definition },
		{ _field_terminator }
	};

	TAG_STRUCT(sound_stereo_mix_struct)
	{
		{ _field_real, "left stereo gain:dB" },
		{ _field_real, "right stereo gain:dB" },
		{ _field_terminator }
	};

	TAG_STRUCT(sound_surround_mix_struct)
	{
		{ _field_real, "front speaker gain:dB" },
		{ _field_real, "rear speaker gain:dB" },
		{ _field_terminator }
	};

	TAG_STRUCT(sound_global_mix_struct)
	{
		{ _field_real, "mono unspatialized gain:dB" },
		{ _field_real, "stereo to 3d gain:dB" },
		{ _field_real, "rear surround to front stereo gain:dB" },
		{ _field_explanation, "surround center mix", "for sounds that have \"use center speaker unspatialized\" checked when outputting in surround" },
		{ _field_struct, "surround center mix", &sound_center_mix_struct_struct_definition },
		{ _field_explanation, "stereo center mix", "for sounds that have \"use center speaker unspatialized\" checked when outputting in stereo" },
		{ _field_struct, "stereo center mix", &sound_center_mix_struct_struct_definition },
		{ _field_explanation, "radio surround center mix", "for the radio effect when outputting in surround" },
		{ _field_struct, "radio surround center mix", &sound_center_mix_struct_struct_definition },
		{ _field_explanation, "radio stereo center mix", "for the radio effect when outputting in stereo" },
		{ _field_struct, "radio stereo center mix", &sound_center_mix_struct_struct_definition },
		{ _field_explanation, "more sound lovin\'", "" },
		{ _field_real, "stereo unspatialized gain:dB" },
		{ _field_real, "quad route to lfe gain:dB" },
		{ _field_explanation, "last minute values", "" },
		{ _field_real, "solo player fade out delay: seconds" },
		{ _field_real, "solo player fade out time: seconds" },
		{ _field_real, "solo player fade in time: seconds" },
		{ _field_real, "game music fade out time: seconds" },
		{ _field_explanation, "debugging stuff", "" },
		{ _field_tag_reference, "play on unplayable sound", &global_force_sound_only_reference },
		{ _field_real, "left/right bleed:[0 = no bleed, 1 = swap left/right, 0.5 = mono" },
		{ _field_real, "remote voice boost: output= (1 + boost)*input" },
		{ _field_terminator }
	};

	TAG_STRUCT(sound_center_mix_struct)
	{
		{ _field_real, "front speaker gain:dB" },
		{ _field_real, "center speaker gain:dB" },
		{ _field_terminator }
	};

	TAG_STRUCT(sound_dialogue_constants_struct_definition)
	{
		{ _field_explanation, "named playing fractions", "these values correspond to the named play fractions in the dialogue editor (It\'s really skip fractions, but who cares\?)" },
		{ _field_real, "almost never" },
		{ _field_real, "rarely" },
		{ _field_real, "somewhat" },
		{ _field_real, "often" },
		{ _field_pad, "VBEZIIDOF", 24 },
		{ _field_terminator }
	};

	STRINGS(StreamingPackBlockFlags)
	{
		"Language pack",
		"Sound bank pack"
	};
	STRING_LIST(StreamingPackBlockFlags, StreamingPackBlockFlags_strings, _countof(StreamingPackBlockFlags_strings));

	STRINGS(sound_definition_flags)
	{
		{
			_engine_type_not_set,
				_versioned_string_list_mode_new,
			{
				"fit to adpcm blocksize",
				"always spatialize#always play as 3d sound, even in first person",
				"never obstruct#disable occlusion/obstruction for this sound",
				"internal don\'t touch!",
				"facial animation data stripped!",
				"use huge sound transmission",
				"link count to owner unit",
				"pitch range is language",
				"don\'t use sound class speaker flag",
				"don\'t use lipsync data",
				"instant sound propagation",
				"fake spatialization with distance",
				"play permutations in order#picks the first permutation randomly"
			}
		},
		{
			_engine_type_haloreach,
			_versioned_string_list_mode_append,
			{
				"bit 14"
			}
		},
		{
			_engine_type_gen3_xbox360,
			_versioned_string_list_mode_new,
			{
				"fit to adpcm blocksize",
				"always spatialize#always play as 3d sound, even in first person",
				"never obstruct#disable occlusion/obstruction for this sound",
				"internal don\'t touch!",
				"facial animation data stripped!",
				"use huge sound transmission",
				"link count to owner unit",
				"pitch range is language",
				"don\'t use sound class speaker flag",
				"don\'t use lipsync data",
				"instant sound propagation",
				"fake spatialization with distance",
				"play permutations in order#picks the first permutation randomly"
			}
		}
	};
	STRING_LIST(sound_definition_flags, sound_definition_flags_strings, _countof(sound_definition_flags_strings));

	STRINGS(SoundEventDefinitionFlags)
	{
		"never obstruct#disable occlusion/obstruction for this sound",
		"use huge sound transmission",
		"link count to owner unit",
		"don\'t use lipsync data",
		"instant sound propagation",
		"optional player sound event!*",
		"fallback sound event!*",
		"has lipsync data",
		"is deterministic",
		"is external source",
		"override external source event",
		"use don\'t play time!",
		"delay start if sound bank not loaded",
		"use fallback only for DVD",
		"has subtitle!*",
		"ignore node transform#use this if you\'re getting wacky spatialization (such as scorpion cannon)",
		"radio combo voice",
		"cinematic allow tails to play out"
	};
	STRING_LIST(SoundEventDefinitionFlags, SoundEventDefinitionFlags_strings, _countof(SoundEventDefinitionFlags_strings));

	STRINGS(sound_import_flags)
	{
		"duplicate directory name",
		"cut to block size",
		"use markers",
		"use layer markers"
	};
	STRING_LIST(sound_import_flags, sound_import_flags_strings, _countof(sound_import_flags_strings));

	STRINGS(sound_pitch_range_internal_xsync_flags)
	{
		"processed language permutations"
	};
	STRING_LIST(sound_pitch_range_internal_xsync_flags, sound_pitch_range_internal_xsync_flags_strings, _countof(sound_pitch_range_internal_xsync_flags_strings));

	STRINGS(sound_compression_enum)
	{
		{
			_engine_type_not_set,
			_versioned_string_list_mode_new,
			{
				"none (big endian)",
				"xbox adpcm",
				"ima adpcm",
				"none (little endian)",
				"wma",
				"none (endian agnostic)",
				"xma",
				"xma v2.0"
			}
		},
		{
			_engine_type_not_set,
			_versioned_string_list_mode_append,
			{
				"unknown compression codec"
			}
		}
	};
	STRING_LIST(sound_compression_enum, sound_compression_enum_strings, _countof(sound_compression_enum_strings));

	STRINGS(sound_encoding_enum)
	{
		"mono",
		"stereo",
		"quad",
		"5.1",
		"codec"
	};
	STRING_LIST(sound_encoding_enum, sound_encoding_enum_strings, _countof(sound_encoding_enum_strings));

	STRINGS(sound_sample_rate_enum)
	{
		{
			_engine_type_not_set,
			_versioned_string_list_mode_new,
			{
				"22kHz",
				"44kHz",
				"32kHz"
			}
		},
		{
			_engine_type_not_set,
			_versioned_string_list_mode_append,
			{
				"unknown sample rate"
			}
		}
	};
	STRING_LIST(sound_sample_rate_enum, sound_sample_rate_enum_strings, _countof(sound_sample_rate_enum_strings));

	STRINGS(sound_effects_enum)
	{
		"none",
		"output front speakers",
		"output rear speakers",
		"output center speakers"
	};
	STRING_LIST(sound_effects_enum, sound_effects_enum_strings, _countof(sound_effects_enum_strings));

	STRINGS(sound_import_type_enum)
	{
		"unknown",
		"single-shot",
		"single-layer",
		"multi-layer"
	};
	STRING_LIST(sound_import_type_enum, sound_import_type_enum_strings, _countof(sound_import_type_enum_strings));

	STRINGS(sound_class_enum)
	{
		"projectile_impact",
		"projectile_detonation",
		"projectile_flyby",
		"projectile_detonation_lod",
		"weapon_fire",
		"weapon_ready",
		"weapon_reload",
		"weapon_empty",
		"weapon_charge",
		"weapon_overheat",
		"weapon_idle",
		"weapon_melee",
		"weapon_animation",
		"object_impacts",
		"particle_impacts",
		"weapon_fire_lod",
		"water_transitions",
		"lowpass_effects",
		"unit_footsteps",
		"unit_dialog",
		"unit_animation",
		"unit_unused!",
		"vehicle_collision",
		"vehicle_engine",
		"vehicle_animation",
		"vehicle_engine_lod",
		"device_door",
		"device_unused0!",
		"device_machinery",
		"device_stationary",
		"device_unused1!",
		"device_unused2!",
		"music",
		"ambient_nature",
		"ambient_machinery",
		"ambient_stationary",
		"huge_ass",
		"object_looping",
		"cinematic_music",
		"unknown_unused0!",
		"unknown_unused1!",
		"ambient_flock",
		"no_pad",
		"no_pad_stationary",
		"equipment_effect",
		"mission_dialog",
		"cinematic_dialog",
		"scripted_cinematic_foley",
		"game_event",
		"ui",
		"test",
		"multiplayer_dialog",
		"ambient_nature_details",
		"ambient_machinery_details",
		"inside_surround_tail",
		"outside_surround_tail",
		"vehicle_detonation",
		"ambient_detonation",
		"first_person_inside",
		"first_person_outside",
		"first_person_anywhere",
		"space_projectile_detonation",
		"space_projectile_flyby",
		"space_vehicle_engine",
		"space_weapon_fire",
		"player_voice_team",
		"player_voice_proxy",
		"projectile_impact_postpone",
		"unit_footsteps_postpone",
		"weapon_ready_third_person",
		"ui_music"
	};
	STRING_LIST(sound_class_enum, sound_class_enum_strings, _countof(sound_class_enum_strings));

	STRINGS(sound_language_enum_definition)
	{
		"english",
		"japanese",
		"german",
		"french",
		"spanish",
		"mexican spanish",
		"italian",
		"korean",
		"chinese-traditional",
		"chinese-simplified",
		"portuguese",
		"polish",
		"russian",
		"danish",
		"finnish",
		"dutch",
		"norwegian"
	};
	STRING_LIST(sound_language_enum_definition, sound_language_enum_definition_strings, _countof(sound_language_enum_definition_strings));

	STRINGS(facial_animation_track_enum_definition)
	{
		"Silence",
		"Eat",
		"Earth",
		"If",
		"Ox",
		"Oat",
		"Wet",
		"Size",
		"Church",
		"Fave",
		"Though",
		"Told",
		"Bump",
		"New",
		"Roar",
		"Cage",
		"Eyebrow_Raise",
		"Blink",
		"Orientation_Head_Pitch",
		"Orientation_Head_Roll",
		"Orientation_Head_Yaw",
		"Emphasis_Head_Pitch",
		"Emphasis_Head_Roll",
		"Emphasis_Head_Yaw",
		"Gaze_Eye_Pitch",
		"Gaze_Eye_Yaw",
		"happy",
		"sad",
		"angry",
		"disgusted",
		"scared",
		"surprised",
		"pain",
		"shout"
	};
	STRING_LIST(facial_animation_track_enum_definition, facial_animation_track_enum_definition_strings, _countof(facial_animation_track_enum_definition_strings));

	STRING_LIST(sound_permutation_flags, empty_string_list, 0);

	STRINGS(sound_permutation_external_flags)
	{
		"don\'t play in dvd build"
	};
	STRING_LIST(sound_permutation_external_flags, sound_permutation_external_flags_strings, _countof(sound_permutation_external_flags_strings));

	STRINGS(sound_override_location_flags_definition)
	{
		"override azimuth",
		"override 3d gain",
		"override speaker gain"
	};
	STRING_LIST(sound_override_location_flags_definition, sound_override_location_flags_definition_strings, _countof(sound_override_location_flags_definition_strings));

	STRINGS(sound_xsync_flags)
	{
		"processed language times",
		"optimized facial animation"
	};
	STRING_LIST(sound_xsync_flags, sound_xsync_flags_strings, _countof(sound_xsync_flags_strings));

	STRINGS(SpeechEventInfoFlags)
	{
		"Campaign Only",
		"Exclude from certain missions",
		"Exclude from M10",
		"Exclude from M20",
		"Exclude from M30",
		"Exclude from M40",
		"Exclude from M60",
		"Exclude from M70",
		"Exclude from M80",
		"Exclude from M90"
	};
	STRING_LIST(SpeechEventInfoFlags, SpeechEventInfoFlags_strings, _countof(SpeechEventInfoFlags_strings));

	STRINGS(SoundBankDefinitionFlags)
	{
		"Don\'t use FP bank in split-screen#don\'t use the high quality first person bank in split-screen",
		"Deterministic#Bank contains deterministic sounds (voices)",
		"Stream off DVD only#Files will not be played off HD, only DVD (for music, etc)",
		"Can delay start#Can delay start time for a short period waiting for bank to load",
		"Don\'t load for player#Use this if there\'s a special player bank that\'s loaded by other means (ie weapon, vehicle).",
		"Ground forces sound bank#Don\'t load this bank if player is in a vehicle (ie bipeds, footsteps)"
	};
	STRING_LIST(SoundBankDefinitionFlags, SoundBankDefinitionFlags_strings, _countof(SoundBankDefinitionFlags_strings));

} // namespace blofeld

