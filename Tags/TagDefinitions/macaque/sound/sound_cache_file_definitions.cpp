#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		cache_file_sound_group,
		CACHE_FILE_SOUND_TAG,
		nullptr,
		INVALID_TAG,
		cache_file_sound_block );

	TAG_GROUP(
		sound_cache_file_gestalt_group,
		SOUND_CACHE_FILE_GESTALT_TAG,
		nullptr,
		INVALID_TAG,
		sound_cache_file_gestalt_block );

	TAG_BLOCK_FROM_STRUCT(
		cache_file_sound_block,
		"cache_file_sound_block",
		1,
		cache_file_sound_struct_definition);

	TAG_BLOCK_FROM_STRUCT(
		sound_cache_file_gestalt_block,
		"sound_cache_file_gestalt_block",
		1,
		sound_cache_file_gestalt_struct_definition);

	#define SOUND_GESTALT_CODEC_BLOCK_ID { 0xEA72FE1B, 0xD8C74A73, 0xB3E54E1C, 0xCF7E2316 }
	TAG_BLOCK(
		sound_gestalt_codec_block,
		"sound_gestalt_codec_block",
		SHORT_MAX,
		"s_cache_file_sound_codec",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SOUND_GESTALT_CODEC_BLOCK_ID)
	{
		{ _field_char_enum, "sample rate", FIELD_FLAG_READ_ONLY, &sound_sample_rate_enum },
		{ _field_char_enum, "encoding", FIELD_FLAG_READ_ONLY, &sound_encoding_enum },
		{ _field_char_enum, "compression", FIELD_FLAG_READ_ONLY, &sound_compression_enum },
		{ _field_terminator }
	};

	#define SOUND_GESTALT_PLAYBACK_BLOCK_ID { 0x97618ABE, 0x6C854431, 0x9D80FAB7, 0xF199F2EC }
	TAG_BLOCK(
		sound_gestalt_playback_block,
		"sound_gestalt_playback_block",
		SHORT_MAX,
		"s_sound_definition_playback_parameters",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SOUND_GESTALT_PLAYBACK_BLOCK_ID)
	{
		{ _field_struct, "playback", FIELD_FLAG_UNKNOWN0, &sound_playback_parameters_struct },
		{ _field_terminator }
	};

	#define SOUND_GESTALT_SCALE_BLOCK_ID { 0x293C6CE9, 0x552C4FF1, 0x9FEBA09B, 0x46CD5D15 }
	TAG_BLOCK(
		sound_gestalt_scale_block,
		"sound_gestalt_scale_block",
		SHORT_MAX,
		"s_sound_definition_scale_modifiers",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SOUND_GESTALT_SCALE_BLOCK_ID)
	{
		{ _field_struct, "scale", FIELD_FLAG_UNKNOWN0, &sound_scale_modifiers_struct },
		{ _field_terminator }
	};

	#define SOUND_GESTALT_IMPORT_NAMES_BLOCK_ID { 0xDEDBEFA5, 0xCF91450E, 0xB92C4760, 0x1487AD06 }
	TAG_BLOCK(
		sound_gestalt_import_names_block,
		"sound_gestalt_import_names_block",
		SHORT_MAX,
		"string_id",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SOUND_GESTALT_IMPORT_NAMES_BLOCK_ID)
	{
		{ _field_string_id, "import name", FIELD_FLAG_INDEX },
		{ _field_terminator }
	};

	#define SOUND_GESTALT_PITCH_RANGE_PARAMETERS_BLOCK_ID { 0xD2578760, 0xAD2B4BD4, 0xBF890920, 0x60A1D630 }
	TAG_BLOCK(
		sound_gestalt_pitch_range_parameters_block,
		"sound_gestalt_pitch_range_parameters_block",
		SHORT_MAX,
		"s_cache_file_sound_pitch_range_parameters",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SOUND_GESTALT_PITCH_RANGE_PARAMETERS_BLOCK_ID)
	{
		{ _field_short_integer, "natural pitch", nullptr, "cents" },
		{ _field_short_integer, "PAD" },
		{ _field_short_bounds, "bend bounds", "the range of pitches that will be represented using this sample.", "cents" },
		{ _field_short_bounds, "max gain pitch bounds", nullptr, "cents" },
		{ _field_short_bounds, "playback pitch bounds", nullptr, "cents" },
		{ _field_terminator }
	};

	#define SOUND_GESTALT_PITCH_RANGES_BLOCK_ID { 0x5C7B7E97, 0x95FD457B, 0x991EDD3F, 0x533CD08C }
	TAG_BLOCK(
		sound_gestalt_pitch_ranges_block,
		"sound_gestalt_pitch_ranges_block",
		SHORT_MAX,
		"s_cache_file_sound_pitch_range",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_WRITEABLE),
		SOUND_GESTALT_PITCH_RANGES_BLOCK_ID)
	{
		{ _field_short_block_index, "name", FIELD_FLAG_INDEX, &sound_gestalt_import_names_block },
		{ _field_short_block_index, "parameters", &sound_gestalt_pitch_range_parameters_block },
		{ _field_short_integer, "encoded permutation data" },
		{ _field_short_integer, "first runtime permutation flag index", FIELD_FLAG_UNKNOWN3 },
		{ _field_long_integer, "encoded first permutation and counts" },
		{ _field_terminator }
	};

	#define SOUND_GESTALT_PERMUTATIONS_BLOCK_ID { 0x066E48B0, 0x55A34789, 0x8605F561, 0x771453C4 }
	TAG_BLOCK(
		sound_gestalt_permutations_block,
		"sound_gestalt_permutations_block",
		k_maximum_sound_cache_file_gestalt_permutations,
		"s_cache_file_sound_permutation",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SOUND_GESTALT_PERMUTATIONS_BLOCK_ID)
	{
		{ _field_short_block_index, "name", FIELD_FLAG_INDEX, &sound_gestalt_import_names_block },
		{ _field_short_integer, "encoded skip fraction" },
		{ _field_long_integer, "uncompressed sample count" },
		{ _field_long_integer, "first chunk index" },
		{ _field_short_integer, "chunk count" },
		{ _field_char_integer, "encoded gain", nullptr, "dB" },
		{ _field_char_integer, "permutation info index" },
		{ _field_word_integer, "first layer marker index" },
		{ _field_word_integer, "layer marker count" },
		{ _field_terminator }
	};

	#define SOUND_GESTALT_PERMUTATION_LANGUAGES_BLOCK_STRUCT_ID { 0xC2E50233, 0xA6814C87, 0x8DAE2CAC, 0xAE66E3A1 }
	TAG_BLOCK(
		sound_gestalt_permutation_languages_block,
		"sound_gestalt_permutation_languages_block",
		k_maximum_sound_cache_file_gestalt_permutation_languages,
		"s_cache_file_sound_permutation_languages",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SOUND_GESTALT_PERMUTATION_LANGUAGES_BLOCK_STRUCT_ID)
	{
		{ _field_long_integer, "permutation index" },
		{ _field_long_integer, "english uncompressed sample count" },
		{ _field_long_integer, "english first chunk index" },
		{ _field_long_integer, "english chunk count" },
		{ _field_long_integer, "japanese uncompressed sample count" },
		{ _field_long_integer, "japanese first chunk index" },
		{ _field_long_integer, "japanese chunk count" },
		{ _field_long_integer, "german uncompressed sample count" },
		{ _field_long_integer, "german first chunk index" },
		{ _field_long_integer, "german chunk count" },
		{ _field_long_integer, "french uncompressed sample count" },
		{ _field_long_integer, "french first chunk index" },
		{ _field_long_integer, "french chunk count" },
		{ _field_long_integer, "spanish uncompressed sample count" },
		{ _field_long_integer, "spanish first chunk index" },
		{ _field_long_integer, "spanish chunk count" },
		{ _field_long_integer, "mexican_spanish uncompressed sample count" },
		{ _field_long_integer, "mexican_spanish first chunk index" },
		{ _field_long_integer, "mexican_spanish chunk count" },
		{ _field_long_integer, "italian uncompressed sample count" },
		{ _field_long_integer, "italian first chunk index" },
		{ _field_long_integer, "italian chunk count" },
		{ _field_long_integer, "korean uncompressed sample count" },
		{ _field_long_integer, "korean first chunk index" },
		{ _field_long_integer, "korean chunk count" },
		{ _field_long_integer, "traditional_chinese uncompressed sample count" },
		{ _field_long_integer, "traditional_chinese first chunk index" },
		{ _field_long_integer, "traditional_chinese chunk count" },
		{ _field_long_integer, "simplified_chinese uncompressed sample count" },
		{ _field_long_integer, "simplified_chinese first chunk index" },
		{ _field_long_integer, "simplified_chinese chunk count" },
		{ _field_long_integer, "portuguese uncompressed sample count" },
		{ _field_long_integer, "portuguese first chunk index" },
		{ _field_long_integer, "portuguese chunk count" },
		{ _field_long_integer, "polish uncompressed sample count" },
		{ _field_long_integer, "polish first chunk index" },
		{ _field_long_integer, "polish chunk count" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 15 },
		{ _field_long_integer, "russian uncompressed sample count" },
		{ _field_long_integer, "russian first chunk index" },
		{ _field_long_integer, "russian chunk count" },
		{ _field_long_integer, "danish uncompressed sample count" },
		{ _field_long_integer, "danish first chunk index" },
		{ _field_long_integer, "danish chunk count" },
		{ _field_long_integer, "finnish uncompressed sample count" },
		{ _field_long_integer, "finnish first chunk index" },
		{ _field_long_integer, "finnish chunk count" },
		{ _field_long_integer, "dutch uncompressed sample count" },
		{ _field_long_integer, "dutch first chunk index" },
		{ _field_long_integer, "dutch chunk count" },
		{ _field_long_integer, "norwegian uncompressed sample count" },
		{ _field_long_integer, "norwegian first chunk index" },
		{ _field_long_integer, "norwegian chunk count" },

		{ _field_terminator }
	};

	#define SOUND_GESTALT_CUSTOM_PLAYBACK_BLOCK_ID { 0x85AB06BE, 0x4C484E51, 0xB1632921, 0x407A7122 }
	TAG_BLOCK(
		sound_gestalt_custom_playback_block,
		"sound_gestalt_custom_playback_block",
		SHORT_MAX,
		"s_platform_sound_playback_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SOUND_GESTALT_CUSTOM_PLAYBACK_BLOCK_ID)
	{
		{ _field_struct, "playback definition", &platform_sound_playback_struct },
		{ _field_terminator }
	};

	#define SOUND_GESTALT_RUNTIME_PERMUTATION_BIT_VECTOR_BLOCK_ID { 0xBCDA51CD, 0xDBB444BD, 0xB166F6B5, 0x6A59110C }
	TAG_BLOCK(
		sound_gestalt_runtime_permutation_bit_vector_block,
		"sound_gestalt_runtime_permutation_bit_vector_block",
		SHORT_MAX,
		"char",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_WRITEABLE),
		SOUND_GESTALT_RUNTIME_PERMUTATION_BIT_VECTOR_BLOCK_ID)
	{
		{ _field_char_integer, "runtime permutation bit vector", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_UNKNOWN3 },
		{ _field_terminator }
	};

	#define SOUND_GESTALT_PROMOTIONS_BLOCK_ID { 0xCC80F520, 0xE19E47AB, 0x9568534D, 0x2010E31B }
	TAG_BLOCK(
		sound_gestalt_promotions_block,
		"sound_gestalt_promotions_block",
		127 + 1,
		"s_sound_promotion_parameters",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_WRITEABLE),
		SOUND_GESTALT_PROMOTIONS_BLOCK_ID)
	{
		{ _field_struct, "runtime promotion storage", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_UNKNOWN3, &sound_promotion_parameters_struct },
		{ _field_terminator }
	};

	#define SOUND_GESTALT_FACIAL_ANIMATION_BLOCK_ID { 0x855E8E14, 0xC58C4761, 0x89AB85D2, 0x1F8A629F }
	TAG_BLOCK(
		sound_gestalt_facial_animation_block,
		"sound_gestalt_facial_animation_block",
		SHORT_MAX,
		"s_tag_resource",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_RESOURCES | SET_UNKNOWN14,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SOUND_GESTALT_FACIAL_ANIMATION_BLOCK_ID)
	{
		{ _field_pageable, "facial animation resource", &facial_animation_resource_definition_struct },
		{ _field_terminator }
	};

	#define SOUND_GESTALT_LAYER_MARKERS_BLOCK_ID { 0x6565F2C0, 0x50FF40A9, 0x8CA6AFDA, 0xD068C4BC }
	TAG_BLOCK(
		sound_gestalt_layer_markers_block,
		"sound_gestalt_layer_markers_block",
		SHORT_MAX,
		"dword",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SOUND_GESTALT_LAYER_MARKERS_BLOCK_ID)
	{
		{ _field_long_integer, "sample offset" },
		{ _field_terminator }
	};

	#define CACHE_FILE_SOUND_STRUCT_DEFINITION_ID { 0x063E9C33, 0xDDF646F7, 0xB9AD58DE, 0x19E86FD6 }
	TAG_STRUCT(
		cache_file_sound_struct_definition,
		"cache_file_sound_struct_definition",
		"s_cache_file_sound_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_RESOURCES | SET_UNKNOWN14,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_WRITEABLE),
		CACHE_FILE_SOUND_STRUCT_DEFINITION_ID)
	{
		{ _field_word_flags, "flags", &sound_definition_flags },
		{ _field_char_enum, "sound class", FIELD_FLAG_READ_ONLY, &sound_class_enum },
		{ _field_char_integer, "pitch range count" },
		{ _field_short_integer, "codec index" },
		{ _field_short_integer, "first pitch range index" },
		{ _field_short_integer, "first language duration pitch range index" },
		{ _field_short_integer, "runtime gestalt index storage", FIELD_FLAG_UNKNOWN3 },
		{ _field_short_integer, "sub priority" },
		{ _field_short_integer, "playback index" },
		{ _field_short_integer, "scale index" },
		{ _field_char_integer, "promotion index" },
		{ _field_char_integer, "custom playback index" },
		{ _field_short_integer, "extra info index" },
		FIELD_PAD("pad", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_long_integer, "maximum play time", nullptr, "ms" },
		{ _field_pageable, "sound data resource", &sound_resource_definition_struct },
		{ _field_terminator }
	};

	#define SOUND_CACHE_FILE_GESTALT_STRUCT_DEFINITION_ID { 0xCF6AEC54, 0x95E846F2, 0x9B3F6246, 0x00AA2223 }
	TAG_STRUCT(
		sound_cache_file_gestalt_struct_definition,
		"sound_cache_file_gestalt_struct_definition",
		"s_sound_cache_file_gestalt_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_RESOURCES | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SOUND_CACHE_FILE_GESTALT_STRUCT_DEFINITION_ID)
	{
		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_long_integer, "@unknown" }, // likely an import version requirement or some silly bollocks

		{ _field_block, "codecs", &sound_gestalt_codec_block },
		{ _field_block, "playbacks", &sound_gestalt_playback_block },
		{ _field_block, "scales", &sound_gestalt_scale_block },
		{ _field_block, "import names", &sound_gestalt_import_names_block },
		{ _field_block, "pitch range distances", &sound_pitch_range_distances_block },
		{ _field_block, "pitch range parameters", &sound_gestalt_pitch_range_parameters_block },
		{ _field_block, "pitch ranges", &sound_gestalt_pitch_ranges_block },
		{ _field_block, "permutations", &sound_gestalt_permutations_block },
		{ _field_block, "permutation languages", &sound_gestalt_permutation_languages_block },
		{ _field_block, "custom playbacks", &sound_gestalt_custom_playback_block },
		{ _field_block, "language durations", &sound_language_info_block },
		{ _field_block, "runtime permutation flags", &sound_gestalt_runtime_permutation_bit_vector_block },
		{ _field_data, "naive sample data" },
		{ _field_long_integer, "no one listens to me" },
		{ _field_long_integer, "but now I'm used to it" },
		{ _field_block, "chunks", &sound_permutation_chunk_block },
		{ _field_block, "promotions", &sound_gestalt_promotions_block },
		{ _field_block, "facial animations", &sound_gestalt_facial_animation_block },
		{ _field_block, "layer markers", &sound_gestalt_layer_markers_block },
		{ _field_terminator }
	};

} // namespace macaque

} // namespace blofeld

