#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define SOUNDBANK_STRUCT_DEFINITION_ID { 0xFE440A1B, 0x7A464815, 0xB3D5F22E, 0x382E3380 }
	TAG_BLOCK(
		soundbank_block,
		"soundbank_block",
		1,
		"SoundBankDefinition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SOUNDBANK_STRUCT_DEFINITION_ID)
	{
		{ _field_long_flags, "flags", &SoundBankDefinitionFlags },
		{ _field_long_flags, "import flags", FIELD_FLAG_UNKNOWN0, &sound_import_flags },
		{ _field_long_flags, "xsync flags", FIELD_FLAG_UNKNOWN0, &sound_xsync_flags },
		{ _field_block, "Sound bank list", "List of names of soundbanks. If more than one, one will be randomly chosen at load", &SoundBankBlock_block },
		{ _field_long_integer, "Bank priority", "the importance of this bank over others. 1 is highest priority (ie will bump all others)" },
		{ _field_long_integer, "Bank unique ID" },
		{ _field_terminator }
	};

	TAG_GROUP(
		soundbank_group,
		SOUNDBANK_TAG,
		nullptr,
		INVALID_TAG,
		soundbank_block );

	#define SOUND_GLOBAL_PROPAGATION_STRUCT_DEFINITION_ID { 0xC5AF7C88, 0xA7864D2E, 0xA2207469, 0xA4EDB0BE }
	TAG_BLOCK(
		sound_global_propagation_block,
		"sound_global_propagation_block",
		1,
		"s_sound_global_propagation_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SOUND_GLOBAL_PROPAGATION_STRUCT_DEFINITION_ID)
	{
		FIELD_EXPLANATION("underwater propagation globals", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_struct, "underwater propagation", &sound_propagation_definition_struct },
		{ _field_terminator }
	};

	TAG_GROUP(
		sound_global_propagation_group,
		SOUND_GLOBAL_PROPAGATION_TAG,
		nullptr,
		INVALID_TAG,
		sound_global_propagation_block );

	#define SOUND_STRUCT_DEFINITION_ID { 0xF318793A, 0xA02C4636, 0x99A0A79B, 0x02BB64CD }
	TAG_BLOCK(
		sound_block,
		"sound_block",
		1,
		"SoundEventDefinition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_RESOURCES | 
		SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SOUND_STRUCT_DEFINITION_ID)
	{
		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 2 },
		{ _field_legacy, _field_struct, "playback", &cache_file_sound_struct_definition_struct_definition },
		{ _field_legacy, _field_block, "extra info!", &sound_extra_info_block_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 13 },
		{ _field_long_flags, "flags", &SoundEventDefinitionFlags },
		{ _field_long_flags, "import flags", FIELD_FLAG_UNKNOWN0, &sound_import_flags },
		{ _field_long_flags, "xsync flags", FIELD_FLAG_UNKNOWN0, &sound_xsync_flags },
		{ _field_string_id, "Event Name", "Sound event name." },
		{ _field_string_id, "Player Event Name", "Optional sound event name for player only." },
		{ _field_string_id, "Fallback Event Name", "Fallback sound event if the others don't play - should be an a guaranteed bank." },
		{ _field_real, "Max Radius" },
		{ _field_real, "Max Duration", "Max duration of this event. Enter manually for now - will auto-fill later." },
		{ _field_real, "Don't play time.", "Time the event will not retrigger for (global)" },
		{ _field_long_integer, "Hidden runtime info index", FIELD_FLAG_UNKNOWN0 },
		{ _field_tag_reference, "Sound bank", "Reference to the sound bank tag this event is in. Can be empty.", &global_soundbank_reference },
		{ _field_block, "lipsync info", &soundLipSyncInfoBlock_block },
		{ _field_long_integer, "deterministic flag index" },

		{ _field_terminator }
	};

	TAG_GROUP(
		sound_group,
		SOUND_TAG,
		nullptr,
		INVALID_TAG,
		sound_block );

	#define SOUND_OLD_STRUCT_DEFINITION_ID { 0xBF8174A7, 0x7DF64FD4, 0x9E177D93, 0xC7401C9C }
	TAG_BLOCK(
		sound_old_block,
		"sound_old_block",
		1,
		"sound_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_RESOURCES | 
		SET_UNKNOWN14 | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_WRITEABLE),
		SOUND_OLD_STRUCT_DEFINITION_ID)
	{
		{ _field_long_flags, "flags", &sound_definition_flags },
		{ _field_long_flags, "import flags", FIELD_FLAG_UNKNOWN0, &sound_import_flags },
		{ _field_long_flags, "xsync flags", FIELD_FLAG_UNKNOWN0, &sound_xsync_flags },
		{ _field_char_enum, "class", &sound_class_enum },
		{ _field_char_enum, "sample rate", FIELD_FLAG_READ_ONLY, &sound_sample_rate_enum },
		{ _field_char_integer, "override xma compression", nullptr, nullptr, "[1-100]" },
		{ _field_char_enum, "import type", FIELD_FLAG_READ_ONLY, &sound_import_type_enum },
		{ _field_struct, "playback", &sound_playback_parameters_struct },
		{ _field_struct, "scale", &sound_scale_modifiers_struct },
		FIELD_EXPLANATION("sub priority", nullptr, FIELD_FLAG_NONE, "Used to compare individual sounds in the same class. Higher means more important. (Negative means do not use.)"),
		{ _field_real, "sub priority" },
		FIELD_EXPLANATION("import properties", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_char_enum, "encoding", FIELD_FLAG_READ_ONLY, &sound_encoding_enum },
		{ _field_char_enum, "compression", FIELD_FLAG_READ_ONLY, &sound_compression_enum },
		FIELD_PAD("pad", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_struct, "promotion", &sound_promotion_parameters_struct },
		FIELD_PAD("runtime pad", nullptr, FIELD_FLAG_UNKNOWN3, 4),
		{ _field_block, "pitch ranges", "pitch ranges allow multiple samples to represent the same sound at different pitches", FIELD_FLAG_READ_ONLY, &sound_pitch_range_block },
		{ _field_block, "platform parameters", &sound_platform_sound_playback_block },
		{ _field_pageable, "sound data resource", &sound_resource_definition_struct },
		{ _field_block, "extra info", FIELD_FLAG_UNKNOWN0, &sound_extra_info_block },
		{ _field_block, "language info", FIELD_FLAG_UNKNOWN0, &sound_language_info_block },
		{ _field_terminator }
	};

	TAG_GROUP(
		sound_old_group,
		SOUND_OLD_TAG,
		nullptr,
		INVALID_TAG,
		sound_old_block );

	#define SOUND2_STRUCT_DEFINITION_ID { 0xFD4F3EEC, 0xA74F4557, 0x95B7892C, 0xFCCB91A0 }
	TAG_BLOCK(
		sound2_block,
		"sound2_block",
		1,
		"sound_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_RESOURCES | 
		SET_UNKNOWN14 | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_WRITEABLE),
		SOUND2_STRUCT_DEFINITION_ID)
	{
		{ _field_long_flags, "flags", &sound_definition_flags },
		{ _field_long_flags, "import flags", FIELD_FLAG_UNKNOWN0, &sound_import_flags },
		{ _field_long_flags, "xsync flags", FIELD_FLAG_UNKNOWN0, &sound_xsync_flags },
		{ _field_char_enum, "class", &sound_class_enum },
		{ _field_char_enum, "sample rate", FIELD_FLAG_READ_ONLY, &sound_sample_rate_enum },
		{ _field_char_integer, "override xma compression", nullptr, nullptr, "[1-100]" },
		{ _field_char_enum, "import type", FIELD_FLAG_READ_ONLY, &sound_import_type_enum },
		{ _field_struct, "playback", &sound_playback_parameters_struct },
		{ _field_struct, "scale", &sound_scale_modifiers_struct },
		FIELD_EXPLANATION("sub priority", nullptr, FIELD_FLAG_NONE, "Used to compare individual sounds in the same class. Higher means more important. (Negative means do not use.)"),
		{ _field_real, "sub priority" },
		FIELD_EXPLANATION("import properties", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_char_enum, "encoding", FIELD_FLAG_READ_ONLY, &sound_encoding_enum },
		{ _field_char_enum, "compression", FIELD_FLAG_READ_ONLY, &sound_compression_enum },
		FIELD_PAD("pad", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_struct, "promotion", &sound_promotion_parameters_struct },
		FIELD_PAD("runtime pad", nullptr, FIELD_FLAG_UNKNOWN3, 4),
		{ _field_block, "pitch ranges", "pitch ranges allow multiple samples to represent the same sound at different pitches", FIELD_FLAG_READ_ONLY, &sound_pitch_range_block },
		{ _field_block, "platform parameters", &sound_platform_sound_playback_block },
		{ _field_pageable, "sound data resource", &sound_resource_definition_struct },
		{ _field_block, "extra info", FIELD_FLAG_UNKNOWN0, &sound_extra_info_block },
		{ _field_block, "language info", FIELD_FLAG_UNKNOWN0, &sound_language_info_block },
		{ _field_terminator }
	};

	TAG_GROUP(
		sound2_group,
		SOUND2_TAG,
		nullptr,
		INVALID_TAG,
		sound2_block );

	#define SOUND_MIX_STRUCT_DEFINITION_ID { 0xE80CFFF1, 0xA42648F0, 0xB072961C, 0x74F379DE }
	TAG_BLOCK(
		sound_mix_block,
		"sound_mix_block",
		1,
		"s_sound_mix_configuration_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SOUND_MIX_STRUCT_DEFINITION_ID)
	{
		{ _field_struct, "default transmission settings", &sound_transmission_definition_struct },
		FIELD_EXPLANATION("first person left side mix", nullptr, FIELD_FLAG_NONE, "for first person sounds to the left of you"),
		{ _field_struct, "first person left side mix", &sound_stereo_mix_struct },
		FIELD_EXPLANATION("first person middle mix", nullptr, FIELD_FLAG_NONE, "for first person sounds between your ears"),
		{ _field_struct, "first person middle mix", &sound_stereo_mix_struct },
		FIELD_EXPLANATION("first person right side mix", nullptr, FIELD_FLAG_NONE, "for first person sounds to the right of you"),
		{ _field_struct, "first person right side mix", &sound_stereo_mix_struct },
		FIELD_EXPLANATION("first person surround mix", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_struct, "first person surround mix", &sound_surround_mix_struct },
		FIELD_EXPLANATION("ambient surround mix", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_struct, "ambient surround mix", &sound_surround_mix_struct },
		FIELD_EXPLANATION("global mix", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_struct, "global mix", &sound_global_mix_struct },
		{ _field_terminator }
	};

	TAG_GROUP(
		sound_mix_group,
		SOUND_MIX_TAG,
		nullptr,
		INVALID_TAG,
		sound_mix_block );

	TAG_GROUP(
		sound_dialogue_constants_group,
		SOUND_DIALOGUE_CONSTANTS_TAG,
		nullptr,
		INVALID_TAG,
		sound_dialogue_constants_block );

	TAG_BLOCK_FROM_STRUCT(
		sound_dialogue_constants_block,
		"sound_dialogue_constants_block",
		1,
		sound_dialogue_constants_struct_definition);

	#define SOUND_GLOBALS_BLOCK_ID { 0x49B78628, 0xC8024A1F, 0x9F59E6A4, 0x7AB7B1C5 }
	TAG_BLOCK(
		sound_globals_block,
		"sound_globals_block",
		1,
		"s_sound_globals_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SOUND_GLOBALS_BLOCK_ID)
	{
		{ _field_tag_reference, "sound classes", &sound_classes_reference },
		{ _field_tag_reference, "sound effects", &global_sound_effect_collection_reference },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_tag_reference, "sound mastering", &sound_mix_reference },

		{ _field_tag_reference, "sound mix", &sound_mix_reference },
		{ _field_tag_reference, "sound combat dialogue constants", &sound_dialogue_constants_reference },
		{ _field_tag_reference, "sound propagation", &sound_global_propagation_reference },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 6 },
		{ _field_tag_reference, "Init sound bank", "Init sound bank for WWise.", &global_soundbank_reference },
		{ _field_tag_reference, "Global sound bank", "Global sound bank for WWise.", &global_soundbank_reference },
		{ _field_tag_reference, "Extra sound bank", "The other sound bank for WWise.", &global_soundbank_reference },
		{ _field_tag_reference, "Campaign sound bank", "Extra sound bank for WWise - only loaded for Campaign.", &global_soundbank_reference },
		{ _field_tag_reference, "Multiplayer sound bank", "Extra sound bank for WWise - only loaded for MP - PVP.", &global_soundbank_reference },
		{ _field_block, "Streaming pack files", &StreamingPackBlock_block },

		{ _field_block, "un-spatialized campaign sounds", &campaign_unspatialized_sounds_block },
		{ _field_terminator }
	};

	#define STREAMINGPACKBLOCK_ID { 0x3D42E3DF, 0xF0B74E4A, 0xB9FE7D41, 0x8FA6B7D5 }
	TAG_BLOCK(
		StreamingPackBlock_block,
		"StreamingPackBlock",
		k_maximum_streaming_packs,
		"StreamPackBlockDefinition",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		STREAMINGPACKBLOCK_ID)
	{
		{ _field_long_flags, "flags", &StreamingPackBlockFlags },
		{ _field_string, "Streaming pck file", "Name of the stream pack file" },
		{ _field_terminator }
	};

	#define CAMPAIGN_UNSPATIALIZED_SOUNDS_BLOCK_ID { 0x56405873, 0x5E06469C, 0x86CCC3CD, 0x243AB85C }
	TAG_BLOCK(
		campaign_unspatialized_sounds_block,
		"campaign_unspatialized_sounds_block",
		k_maximum_campaign_unspatialized_sounds,
		"s_tag_reference",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CAMPAIGN_UNSPATIALIZED_SOUNDS_BLOCK_ID)
	{
		{ _field_tag_reference, "sound", FIELD_FLAG_INDEX, &global_sound_reference },
		{ _field_terminator }
	};

	#define SOUNDBANKBLOCK_ID { 0xBA6C3A66, 0xF2B240C5, 0x8DB3E00A, 0x6129DCB6 }
	TAG_BLOCK(
		SoundBankBlock_block,
		"SoundBankBlock",
		k_maximumSoundBanksPerTag,
		"SoundBankBlockDefinition",
		SET_UNKNOWN0 | SET_POSTPROCESS_RECURSIVELY | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SOUNDBANKBLOCK_ID)
	{
		{ _field_string_id, "Sound bank name", "Name of the main sound bank." },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(
		soundLipSyncInfoBlock_block,
		"soundLipSyncInfoBlock",
		1,
		soundLipSyncInfoBlock_struct);

	TAG_BLOCK_FROM_STRUCT(
		deterministicSpeechEventBlock_block,
		"deterministicSpeechEventBlock",
		MAXIMUM_PERMUTATIONS_PER_PITCH_RANGE,
		deterministicSpeechEventBlock_struct);

	#define FACIAL_ANIMATION_LANGUAGE_BLOCK_STRUCT_ID { 0x5280F0A0, 0xA2804A45, 0xB6512D45, 0x32312FB4 }
	TAG_BLOCK(
		facial_animation_language_block,
		"facial_animation_language_block",
		k_language_count,
		"s_facial_animation_language",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_RESOURCES | SET_UNKNOWN14,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		FACIAL_ANIMATION_LANGUAGE_BLOCK_STRUCT_ID)
	{
		{ _field_pageable, "facial animation resource", &facial_animation_resource_definition_struct },
		{ _field_long_enum, "language", &sound_language_enum_definition },
		{ _field_terminator }
	};

	#define SOUND_PROMOTION_RULE_BLOCK_ID { 0xC69943B0, 0x10BC44C8, 0xBC4D84CB, 0xADCE8178 }
	TAG_BLOCK(
		sound_promotion_rule_block,
		"sound_promotion_rule_block",
		k_maximum_promotion_rules_per_sound,
		"s_sound_promotion_rule",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SOUND_PROMOTION_RULE_BLOCK_ID)
	{
		{ _field_short_block_index, "pitch range", FIELD_FLAG_INDEX, &sound_pitch_range_block },
		{ _field_short_integer, "maximum playing count" },
		{ _field_real, "suppression time", "time from when first permutation plays to when another sound from an equal or lower promotion can play", "seconds" },
		{ _field_long_integer, "runtime rollover time", FIELD_FLAG_UNKNOWN0 },
		{ _field_long_integer, "impulse promotion time", FIELD_FLAG_UNKNOWN0 },
		{ _field_terminator }
	};

	#define SOUND_PITCH_RANGE_BLOCK_ID { 0x77F72A4F, 0x42D64D55, 0xB4072E44, 0x0E750C29 }
	TAG_BLOCK(
		sound_pitch_range_block,
		"sound_pitch_range_block",
		MAXIMUM_PITCH_RANGES_PER_SOUND,
		"s_sound_pitch_range",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | 
		SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_WRITEABLE),
		SOUND_PITCH_RANGE_BLOCK_ID)
	{
		{ _field_string_id, "name", "the name of the imported pitch range directory", FIELD_FLAG_READ_ONLY },
		FIELD_EXPLANATION("pitch control", nullptr, FIELD_FLAG_NONE, "these settings control what pitches this set of samples represents. if there is only one pitch range, all three values are ignored."),
		{ _field_short_integer, "natural pitch", "the apparent pitch when these samples are played at their recorded pitch.", "cents" },
		FIELD_PAD("KCTSDWPP", nullptr, FIELD_FLAG_UNKNOWN3, 2),
		{ _field_short_bounds, "bend bounds", "the range of pitches that will be represented using this sample.", "cents" },
		{ _field_short_bounds, "full volume bounds", "the range of pitches that map to full gain.", "cents", FIELD_FLAG_UNKNOWN0 },
		{ _field_short_bounds, "playback bend bounds", "the actual pitch will be clamped to this", "cents", _field_id_function_unknown },
		{ _field_struct, "distance parameters", &sound_distance_parameters_struct },
		FIELD_PAD("YAMTVB", nullptr, FIELD_FLAG_UNKNOWN3, 4),
		{ _field_char_integer, "runtime usable permutation count", FIELD_FLAG_UNKNOWN0 },
		{ _field_byte_flags, "xsync flags", FIELD_FLAG_UNKNOWN0, &sound_pitch_range_internal_xsync_flags },
		FIELD_PAD("asdf", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_block, "permutations", "permutations represent equivalent variations of this sound.", FIELD_FLAG_READ_ONLY, &sound_permutations_block },
		{ _field_terminator }
	};

	#define SOUND_PERMUTATIONS_BLOCK_ID { 0x1426CFA4, 0x00DA4206, 0xAD7C0A62, 0xDA270964 }
	TAG_BLOCK(
		sound_permutations_block,
		"sound_permutations_block",
		MAXIMUM_PERMUTATIONS_PER_PITCH_RANGE,
		"s_sound_permutation",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SOUND_PERMUTATIONS_BLOCK_ID)
	{
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_sound_player),
		{ _field_string_id, "name", "name of the file from which this sample was imported", FIELD_FLAG_READ_ONLY | FIELD_FLAG_INDEX },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_default),
		{ _field_real_fraction, "skip fraction", "fraction of requests to play this permutation that are ignored (a different permutation is selected.)" },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_default),
		{ _field_real, "gain", "additional attenuation when played", "dB", _field_id_decibels },
		{ _field_custom_short_block_index, "raw info", FIELD_FLAG_UNKNOWN0 },
		{ _field_short_block_index, "play fraction type", FIELD_FLAG_UNKNOWN0, &g_null_block },
		{ _field_short_bounds, "mission range", "first and last mission ids this permutation can play in (zero values are ignored)" },
		{ _field_word_flags, "permutation flags", &sound_permutation_external_flags },
		{ _field_word_flags, "flags", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &sound_permutation_flags },
		{ _field_block, "languages", FIELD_FLAG_UNKNOWN0, &sound_permutation_languages_block },
		{ _field_terminator }
	};

	#define SOUND_PERMUTATION_LANGUAGES_BLOCK_STRUCT_ID { 0xAC83695F, 0xAB6349CB, 0x8B5CAF87, 0x9F79EC46 }
	TAG_BLOCK(
		sound_permutation_languages_block,
		"sound_permutation_languages_block",
		k_language_count,
		"s_sound_permutation_language",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SOUND_PERMUTATION_LANGUAGES_BLOCK_STRUCT_ID)
	{
		{ _field_long_integer, "uncompressed sample count" },
		{ _field_block, "chunks", &sound_permutation_chunk_block },
		{ _field_terminator }
	};

	#define SOUND_PERMUTATION_CHUNK_BLOCK_ID { 0xBDB277FD, 0x04314F54, 0x95098A19, 0x71D29FE5 }
	TAG_BLOCK(
		sound_permutation_chunk_block,
		"sound_permutation_chunk_block",
		UNSIGNED_SHORT_MAX*4,
		"sound_permutation_chunk_block",
		SET_DELETE_RECURSIVELY | SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_WRITEABLE),
		SOUND_PERMUTATION_CHUNK_BLOCK_ID)
	{
		{ _field_long_integer, "file offset", FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "encoded size and flags", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_UNKNOWN3 },
		{ _field_long_block_index, "cache index", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_UNKNOWN3, &g_null_block },
		{ _field_long_integer, "xma2_source_buffer_sample_start", FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "xma2_source_buffer_sample_end", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define SOUND_PROMOTION_RUNTIME_TIMER_BLOCK_ID { 0x7738DDE0, 0x0D754110, 0xB20B95F0, 0x43509AAA }
	TAG_BLOCK(
		sound_promotion_runtime_timer_block,
		"sound_promotion_runtime_timer_block",
		k_maximum_promotion_rules_per_sound,
		"long",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_WRITEABLE),
		SOUND_PROMOTION_RUNTIME_TIMER_BLOCK_ID)
	{
		{ _field_long_integer, "timer storage", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_UNKNOWN3 },
		{ _field_terminator }
	};

	#define SOUND_PLATFORM_SOUND_PLAYBACK_BLOCK_ID { 0x4A3DA0A2, 0xCB0F41E1, 0xAAB6650E, 0xBCA33F94 }
	TAG_BLOCK(
		sound_platform_sound_playback_block,
		"sound_platform_sound_playback_block",
		1,
		"s_sound_definition_custom_playback_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SOUND_PLATFORM_SOUND_PLAYBACK_BLOCK_ID)
	{
		{ _field_struct, "playback definition", &platform_sound_playback_struct },
		{ _field_terminator }
	};

	#define SOUND_EXTRA_INFO_BLOCK_STRUCT_ID { 0xA88172BA, 0x8BEC4641, 0x8E2A9EDB, 0x3B346B18 }
	TAG_BLOCK(
		sound_extra_info_block,
		"sound_extra_info_block",
		1,
		"s_sound_definition_extra_info",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_RESOURCES | 
		SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SOUND_EXTRA_INFO_BLOCK_STRUCT_ID)
	{
		{ _field_block, "language permutation info", &sound_definition_language_permutation_info_block },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 4 },
		{ _field_legacy, _field_data, "facial animation resource" }, // #TODO: Research, not 100% that this is facial animation resource but the format might have changed?
		{ _field_legacy, _field_long_integer, "unknown" },
		{ _field_legacy, _field_long_integer, "unknown@" },
		{ _field_legacy, _field_long_enum, "language", &sound_language_enum_definition },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_block, "facial animation resource languages", &facial_animation_language_block },
		{ _field_terminator }
	};

	#define SOUND_DEFINITION_LANGUAGE_PERMUTATION_INFO_BLOCK_ID { 0x87CF4394, 0xE57F4B18, 0xAA4D2FB5, 0x6C5606CB }
	TAG_BLOCK(
		sound_definition_language_permutation_info_block,
		"sound_definition_language_permutation_info_block",
		MAXIMUM_PITCH_RANGES_PER_SOUND*MAXIMUM_PERMUTATIONS_PER_PITCH_RANGE*2,
		"s_sound_definition_language_permutation_info",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SOUND_DEFINITION_LANGUAGE_PERMUTATION_INFO_BLOCK_ID)
	{
		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 4 },
		{ _field_legacy, _field_real, "@unknown" },
		{ _field_legacy, _field_real, "@unknown" },
		{ _field_legacy, _field_real, "@unknown" },
		{ _field_legacy, _field_real, "@unknown" },

		{ _field_block, "raw info block", &sound_permutation_raw_info_block },
		{ _field_terminator }
	};

	#define SOUND_PERMUTATION_RAW_INFO_BLOCK_ID { 0xDC6BFACE, 0x54E5414E, 0xB0B03C61, 0x2ED507A1 }
	TAG_BLOCK(
		sound_permutation_raw_info_block,
		"sound_permutation_raw_info_block",
		2*k_language_count,
		"s_sound_permutation_raw_info",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_UNKNOWN8 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SOUND_PERMUTATION_RAW_INFO_BLOCK_ID)
	{
		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 1 },
		{ _field_long_integer, "@unknown" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 9 },
		{ _field_string_id, "skip fraction name" },
		{ _field_data, "samples", "sampled sound data", FIELD_FLAG_UNKNOWN0 },
		{ _field_block, "markers", FIELD_FLAG_UNKNOWN0, &sound_permutation_marker_block },
		{ _field_block, "layer markers", FIELD_FLAG_UNKNOWN0, &sound_permutation_marker_block },
		{ _field_block, "xma2 seek table", FIELD_FLAG_UNKNOWN0, &sound_xma2_seek_table_block },
		{ _field_enum, "compression", FIELD_FLAG_READ_ONLY, &sound_compression_enum },
		{ _field_char_enum, "language", FIELD_FLAG_READ_ONLY, &sound_language_enum_definition },
		FIELD_PAD("ZHDGBHWS", nullptr, FIELD_FLAG_NONE, 1),
		{ _field_long_integer, "sample count", FIELD_FLAG_UNKNOWN0 },

		{ _field_long_integer, "resource sample offset", FIELD_FLAG_UNKNOWN0 },
		{ _field_long_integer, "resource sample size", FIELD_FLAG_UNKNOWN0 },
		{ _field_terminator }
	};

	#define SOUND_PERMUTATION_MARKER_BLOCK_ID { 0x4679E356, 0x4CB34837, 0xA34808AC, 0x6DCA28A0 }
	TAG_BLOCK(
		sound_permutation_marker_block,
		"sound_permutation_marker_block",
		MAXIMUM_MARKERS_PER_PERMUTATION,
		"s_sound_permutation_marker",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SOUND_PERMUTATION_MARKER_BLOCK_ID)
	{
		{ _field_long_integer, "marker id", FIELD_FLAG_READ_ONLY },
		{ _field_string_id, "name", FIELD_FLAG_READ_ONLY | FIELD_FLAG_INDEX },
		{ _field_long_integer, "sample offset", FIELD_FLAG_READ_ONLY },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_unknown_player),
		{ _field_terminator }
	};

	#define SOUND_XMA2_SEEK_TABLE_BLOCK_ID { 0x6927A11A, 0x10E24EDD, 0x9E681A4E, 0xB2AD185F }
	TAG_BLOCK(
		sound_xma2_seek_table_block,
		"sound_xma2_seek_table_block",
		MAXIMUM_SOUND_DATA_SIZE/k_kilo,
		"s_sound_xma2_seek_table_entry",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SOUND_XMA2_SEEK_TABLE_BLOCK_ID)
	{
		{ _field_long_integer, "block relative sample start", FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "block relative sample end" },
		{ _field_long_integer, "starting sample index", FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "ending sample index", FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "starting xma2 offset", FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "ending xma2 offset", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(
		sound_pitch_range_distances_block,
		"sound_pitch_range_distances_block",
		SHORT_MAX,
		sound_distance_parameters_struct);

	#define FACIAL_ANIMATION_PERMUTATION_BLOCK_STRUCT_ID { 0x0EFE0F99, 0x36EC4871, 0xA87914A5, 0x6551CE61 }
	TAG_BLOCK(
		facial_animation_permutation_block,
		"facial_animation_permutation_block",
		MAXIMUM_PITCH_RANGES_PER_SOUND*MAXIMUM_PERMUTATIONS_PER_PITCH_RANGE,
		"s_facial_animation_permutation",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		FACIAL_ANIMATION_PERMUTATION_BLOCK_STRUCT_ID)
	{
		{ _field_real, "start time" },
		{ _field_real, "end time" },
		{ _field_real, "blend in" },
		{ _field_real, "blend out" },
		{ _field_block, "facial animation curves", &facial_animation_curve_block },
		{ _field_terminator }
	};

	#define FACIAL_ANIMATION_CURVE_BLOCK_STRUCT_ID { 0xA566493B, 0x9431409F, 0xABE0F9B2, 0x19D5B5C8 }
	TAG_BLOCK(
		facial_animation_curve_block,
		"facial_animation_curve_block",
		k_facial_animation_track_count,
		"s_facial_animation_curve",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		FACIAL_ANIMATION_CURVE_BLOCK_STRUCT_ID)
	{
		{ _field_long_enum, "facial animation track", &facial_animation_track_enum_definition },
		{ _field_long_integer, "facial animation curve data offset" },
		{ _field_long_integer, "facial animation curve data size" },
		{ _field_terminator }
	};

	#define SOUND_DIALOGUE_CONSTANTS_STRUCT_DEFINITION_ID { 0x81DF7335, 0x8D55482D, 0xBCD40D38, 0xA8F5D740 }
	TAG_STRUCT(
		sound_dialogue_constants_struct_definition,
		"sound_dialogue_constants_struct_definition",
		"s_sound_dialogue_constants_definition",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SOUND_DIALOGUE_CONSTANTS_STRUCT_DEFINITION_ID)
	{
		FIELD_EXPLANATION("named playing fractions", nullptr, FIELD_FLAG_NONE, "these values correspond to the named play fractions in the dialogue editor (It\'s really skip fractions, but who cares?)"),
		{ _field_real, "almost never" },
		{ _field_real, "rarely" },
		{ _field_real, "somewhat" },
		{ _field_real, "often" },
		FIELD_PAD("VBEZIIDOF", nullptr, FIELD_FLAG_NONE, 24),
		{ _field_terminator }
	};

	#define SOUND_DISTANCE_PARAMETERS_STRUCT_ID { 0x5E198FB1, 0xA69A46FA, 0x8FC2D774, 0xF76DCAAA }
	TAG_STRUCT(
		sound_distance_parameters_struct,
		"sound_distance_parameters_struct",
		"s_sound_distance_parameters",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SOUND_DISTANCE_PARAMETERS_STRUCT_ID)
	{
		FIELD_EXPLANATION("attenuation distances", nullptr, FIELD_FLAG_NONE, "these settings vary how the sound fades as you move closer or further away from it."),
		{ _field_real, "don't obstruct distance", "don't obstruct below this distance", "world units" },
		{ _field_real, "don't play distance", "don't play below this distance", "world units" },
		{ _field_real, "attack distance", "start playing at full volume at this distance", "world units" },
		{ _field_real, "minimum distance", "start attenuating at this distance", "world units" },
		{ _field_real, "sustain begin distance", "set attenuation to sustain db at this distance", "world units" },
		{ _field_real, "sustain end distance", "continue attenuating to silence at this distance", "world units" },
		{ _field_real, "maximum distance", "the distance beyond which this sound is no longer audible", "world units" },
		{ _field_real, "sustain db", "the amount of attenuation between sustain begin and end", "dB" },
		{ _field_terminator }
	};

	#define SOUND_PROPAGATION_DEFINITION_STRUCT_ID { 0xDE42E807, 0x9F174952, 0xA2622269, 0x55663071 }
	TAG_STRUCT(
		sound_propagation_definition_struct,
		"sound_propagation_definition_struct",
		"s_sound_propagation_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SOUND_PROPAGATION_DEFINITION_STRUCT_ID)
	{
		{ _field_tag_reference, "sound environment", &global_sound_environment_reference },
		{ _field_tag_reference, "background sound", &global_looping_sound_reference },
		{ _field_real, "background sound gain", "scale for fog background sound:dB" },
		{ _field_real, "environment ducking", "scales the surrounding background sound by this much:dB" },
		{ _field_tag_reference, "entry sound", &global_sound_reference },
		{ _field_tag_reference, "exit sound", &global_sound_reference },
		{ _field_terminator }
	};

	#define SOUNDLIPSYNCINFOBLOCK_STRUCT_ID { 0x0CE98746, 0xD3DA483B, 0xAED26267, 0xCD83DD37 }
	TAG_STRUCT(
		soundLipSyncInfoBlock_struct,
		"soundLipSyncInfoBlock_struct",
		"soundLipSyncInfo",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_RESOURCES | 
		SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SOUNDLIPSYNCINFOBLOCK_STRUCT_ID)
	{
		{ _field_long_integer, "number of usable facial animations" },
		{ _field_block, "deterministic event info", &deterministicSpeechEventBlock_block },
		{ _field_block, "facial animation resource languages", &facial_animation_language_block },
		{ _field_terminator }
	};

	#define DETERMINISTICSPEECHEVENTBLOCK_STRUCT_ID { 0x7EEDB328, 0xCE2543C3, 0xB20B798B, 0xEE2D947A }
	TAG_STRUCT(
		deterministicSpeechEventBlock_struct,
		"deterministicSpeechEventBlock_struct",
		"deterministicSpeechEventInfo",
		SET_UNKNOWN0 | SET_POSTPROCESS_RECURSIVELY | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		DETERMINISTICSPEECHEVENTBLOCK_STRUCT_ID)
	{
		{ _field_long_flags, "flags", &SpeechEventInfoFlags },
		{ _field_string_id, "voice file path" },
		{ _field_real, "event duration" },
		{ _field_real, "skip fraction", "Percent this file will be skipped when picked. 0 is always, 0.99 is almost never" },
		{ _field_terminator }
	};

	#define SOUND_PLAYBACK_PARAMETERS_STRUCT_ID { 0x04851E6C, 0x1277447B, 0xB15A0C03, 0x9B5C40CA }
	TAG_STRUCT(
		sound_playback_parameters_struct,
		"sound_playback_parameters_struct",
		"s_sound_definition_playback_parameters",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SOUND_PLAYBACK_PARAMETERS_STRUCT_ID)
	{
		{ _field_long_integer, "internal flags", FIELD_FLAG_UNKNOWN0 },
		{ _field_real_fraction, "skip fraction", "fraction of requests to play this sound that will be ignored (0 means always play.)" },
		{ _field_real, "maximum bend per second", nullptr, "cents", _field_id_cents },
		{ _field_struct, "distance parameters", MAKE_OLD_NAMES("."), &sound_distance_parameters_struct },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_default),
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_default),
		FIELD_EXPLANATION("randomization", nullptr, FIELD_FLAG_NONE, "these settings control random variation of volume and pitch.\n the second parameter gets clipped to the first."),
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_default),
		{ _field_real, "gain base", "sound's random gain will start here", "dB", _field_id_decibels },
		{ _field_real, "gain variance", "sound's gain will be randomly modulated within this range", "dB", _field_id_decibels },
		{ _field_short_bounds, "random pitch bounds", "the sound's pitch will be modulated randomly within this range.", "cents" },
		FIELD_EXPLANATION("directional sounds", nullptr, FIELD_FLAG_NONE, "these settings allow sounds to be directional, fading as they turn away from the listener"),
		{ _field_angle, "inner cone angle", "within the cone defined by this angle and the sound's direction, the sound plays with a gain of 1.0.", "degrees" },
		{ _field_angle, "outer cone angle", "outside the cone defined by this angle and the sound's direction, the sound plays with a gain of OUTER CONE GAIN. (0 means the sound does not attenuate with direction.)", "degrees" },
		{ _field_real, "outer cone gain", "the gain to use when the sound is directed away from the listener", "dB", _field_id_decibels },
		FIELD_EXPLANATION("scripted location override", nullptr, FIELD_FLAG_NONE, "NOTE: this will only apply when the sound is started via script\nazimuth:\n    0 => front\n    90 => left\n    180 => back\n    270 => right\n"),
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_default),
		{ _field_long_flags, "flags", &sound_override_location_flags_definition },
		{ _field_angle, "azimuth" },
		{ _field_real, "positional gain", nullptr, "dB" },
		{ _field_real, "first person gain", nullptr, "dB" },
		{ _field_terminator }
	};

	#define SOUND_SCALE_MODIFIERS_STRUCT_ID { 0x3ABE3277, 0x90774F0E, 0xA794C831, 0x58D6DACF }
	TAG_STRUCT(
		sound_scale_modifiers_struct,
		"sound_scale_modifiers_struct",
		"s_sound_definition_scale_modifiers",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SOUND_SCALE_MODIFIERS_STRUCT_ID)
	{
		FIELD_EXPLANATION("scale modifiers", nullptr, FIELD_FLAG_NONE, "as the sound\'s input scale changes from zero to one, these modifiers move between the two values specified here. the sound will play using the current scale modifier multiplied by the values specified above. (0 values are ignored.)"),
		{ _field_real_bounds, "gain modifier", nullptr, "dB", _field_id_decibels },
		{ _field_short_bounds, "pitch modifier", nullptr, "cents" },
		{ _field_real_fraction_bounds, "skip fraction modifier" },
		{ _field_terminator }
	};

	#define SOUND_PROMOTION_PARAMETERS_STRUCT_ID { 0x2CF97DF2, 0xC0014BDB, 0xAE39ECEA, 0xBA189908 }
	TAG_STRUCT(
		sound_promotion_parameters_struct,
		"sound_promotion_parameters_struct",
		"sound_promotion_parameters_struct",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SOUND_PROMOTION_PARAMETERS_STRUCT_ID)
	{
		{ _field_block, "promotion rules", &sound_promotion_rule_block },
		{ _field_block, "runtime timers", FIELD_FLAG_UNKNOWN0, &sound_promotion_runtime_timer_block },
		{ _field_long_integer, "runtime active promotion index", FIELD_FLAG_UNKNOWN0 },
		{ _field_long_integer, "runtime last promotion time", FIELD_FLAG_UNKNOWN0 },
		{ _field_long_integer, "runtime suppression timeout", FIELD_FLAG_UNKNOWN0 },
		{ _field_terminator }
	};

	#define SOUND_TRANSMISSION_DEFINITION_STRUCT_ID { 0x7D2210B1, 0x1E4E416A, 0xA69625D0, 0xDF052335 }
	TAG_STRUCT(
		sound_transmission_definition_struct,
		"sound_transmission_definition_struct",
		"s_sound_transmission_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_POSTPROCESS_RECURSIVELY | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SOUND_TRANSMISSION_DEFINITION_STRUCT_ID)
	{
		FIELD_EXPLANATION("default obstruction settings", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_struct, "obstruction settings", &global_sound_lowpass_block },
		FIELD_EXPLANATION("default occlusion settings", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_struct, "occlusion settings", &global_sound_lowpass_block },
		{ _field_terminator }
	};

	#define SOUND_STEREO_MIX_STRUCT_ID { 0xF0FFEE52, 0xB30949B6, 0x86208462, 0x42D0E5DB }
	TAG_STRUCT(
		sound_stereo_mix_struct,
		"sound_stereo_mix_struct",
		"s_sound_stereo_mix_definition",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SOUND_STEREO_MIX_STRUCT_ID)
	{
		{ _field_real, "left stereo gain", nullptr, "dB" },
		{ _field_real, "right stereo gain", nullptr, "dB" },
		{ _field_terminator }
	};

	#define SOUND_SURROUND_MIX_STRUCT_ID { 0xEA4CD876, 0x62334CC1, 0xABC12101, 0x9DCEA290 }
	TAG_STRUCT(
		sound_surround_mix_struct,
		"sound_surround_mix_struct",
		"s_sound_stereo_mix_definition",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SOUND_SURROUND_MIX_STRUCT_ID)
	{
		{ _field_real, "front speaker gain", nullptr, "dB" },
		{ _field_real, "rear speaker gain", nullptr, "dB" },
		{ _field_terminator }
	};

	#define SOUND_GLOBAL_MIX_STRUCT_ID { 0xA2C05D8F, 0xA92D4D82, 0x9534A331, 0x4BD3EF82 }
	TAG_STRUCT(
		sound_global_mix_struct,
		"sound_global_mix_struct",
		"s_sound_global_mix_configuration",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SOUND_GLOBAL_MIX_STRUCT_ID)
	{
		{ _field_real, "mono unspatialized gain", nullptr, "dB" },
		{ _field_real, "stereo to 3d gain", nullptr, "dB" },
		{ _field_real, "rear surround to front stereo gain", nullptr, "dB" },
		FIELD_EXPLANATION("surround center mix", nullptr, FIELD_FLAG_NONE, "for sounds that have \"use center speaker unspatialized\" checked when outputting in surround"),
		{ _field_struct, "surround center mix", &sound_center_mix_struct },
		FIELD_EXPLANATION("stereo center mix", nullptr, FIELD_FLAG_NONE, "for sounds that have \"use center speaker unspatialized\" checked when outputting in stereo"),
		{ _field_struct, "stereo center mix", &sound_center_mix_struct },
		FIELD_EXPLANATION("radio surround center mix", nullptr, FIELD_FLAG_NONE, "for the radio effect when outputting in surround"),
		{ _field_struct, "radio surround center mix", &sound_center_mix_struct },
		FIELD_EXPLANATION("radio stereo center mix", nullptr, FIELD_FLAG_NONE, "for the radio effect when outputting in stereo"),
		{ _field_struct, "radio stereo center mix", &sound_center_mix_struct },
		FIELD_EXPLANATION("more sound lovin'", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real, "stereo unspatialized gain", nullptr, "dB" },
		{ _field_real, "quad route to lfe gain", nullptr, "dB" },
		FIELD_EXPLANATION("last minute values", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real, "solo player fade out delay", nullptr, "seconds" },
		{ _field_real, "solo player fade out time", nullptr, "seconds" },
		{ _field_real, "solo player fade in time", nullptr, "seconds" },
		{ _field_real, "game music fade out time", nullptr, "seconds" },
		FIELD_EXPLANATION("debugging stuff", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_tag_reference, "play on unplayable sound", &global_force_sound_only_reference },
		{ _field_real, "left/right bleed", nullptr, nullptr, "[0 = no bleed, 1 = swap left/right, 0.5 = mono" },
		{ _field_real, "remote voice boost", nullptr, "output= (1 + boost)*input" },
		{ _field_terminator }
	};

	#define SOUND_CENTER_MIX_STRUCT_ID { 0x5F672B73, 0xEC7142BA, 0xB9066F9F, 0x56A974D9 }
	TAG_STRUCT(
		sound_center_mix_struct,
		"sound_center_mix_struct",
		"s_sound_center_mix_definition",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SOUND_CENTER_MIX_STRUCT_ID)
	{
		{ _field_real, "front speaker gain", nullptr, "dB" },
		{ _field_real, "center speaker gain", nullptr, "dB" },
		{ _field_terminator }
	};

	#define SOUND_RESOURCE_DEFINITION_STRUCT_ID { 0xC0BA15AA, 0xB9CB4B7B, 0x9D98A769, 0xD335C8BB }
	TAG_STRUCT(
		sound_resource_definition_struct,
		"sound_resource_definition_struct",
		"s_sound_resource_data",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SOUND_RESOURCE_DEFINITION_STRUCT_ID)
	{
		{ _field_data, "sample data" },
		{ _field_terminator }
	};

	#define FACIAL_ANIMATION_RESOURCE_DEFINITION_STRUCT_ID { 0x268C469E, 0xD68743D8, 0x898CC9F7, 0xC60502E7 }
	TAG_STRUCT(
		facial_animation_resource_definition_struct,
		"facial_animation_resource_definition_struct",
		"s_facial_animation",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_UNKNOWN8 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		FACIAL_ANIMATION_RESOURCE_DEFINITION_STRUCT_ID)
	{
		{ _field_block, "facial animation permutations", &facial_animation_permutation_block },
		{ _field_data, "compressed facial animation curve data" },
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
		"none (big endian)",
		"xbox adpcm",
		"ima adpcm",
		"none (little endian)",
		"wma",
		"none (endian agnostic)",
		"xma",
		"xma v2.0"
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
		"22kHz",
		"44kHz",
		"32kHz"
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

} // namespace macaque

} // namespace blofeld

