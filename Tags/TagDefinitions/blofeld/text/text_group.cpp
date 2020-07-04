#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(multilingual_unicode_string_list, MULTILINGUAL_UNICODE_STRING_LIST_TAG, multilingual_unicode_string_list_block_block );

	TAG_BLOCK(multilingual_unicode_string_reference_block, k_maximum_multilingual_unicode_strings_per_string_list)
	{
		{ _field_string_id, "string id^*" },
		{ _field_long_integer, "english offset*" },
		{ _field_long_integer, "japanese offset*" },
		{ _field_long_integer, "german offset*" },
		{ _field_long_integer, "french offset*" },
		{ _field_long_integer, "spanish offset*" },
		{ _field_long_integer, "mexican spanish offset*" },
		{ _field_long_integer, "italian offset*" },
		{ _field_long_integer, "korean offset*" },
		{ _field_long_integer, "traditional chinese offset*" },
		{ _field_long_integer, "simplified chinese offset*" },
		{ _field_long_integer, "portuguese offset*" },
		{ _field_long_integer, "polish offset*" },
		{ _field_long_integer, "russian offset*" },
		{ _field_long_integer, "danish offset*" },
		{ _field_long_integer, "finnish offset*" },
		{ _field_long_integer, "dutch offset*" },
		{ _field_long_integer, "norwegian offset*" },
		{ _field_terminator }
	};

	TAG_BLOCK(string_substitution_pair_block, k_maximum_strings_per_string_list)
	{
		{ _field_string_id, "first string id^*!" },
		{ _field_string_id, "second string id*!" },
		{ _field_long_integer, "associated value*!" },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(multilingual_unicode_string_list_block, 1, multilingual_unicode_string_list_struct_definition_struct_definition );

	TAG_ARRAY(data_hash_definition, k_hash_size)
	{
		{ _field_byte_integer, "hash byte!" },
		{ _field_terminator }
	};

	TAG_ARRAY(multilingual_unicode_string_list_language_pack_offsets, k_language_count)
	{
		{ _field_short_integer, "start index!" },
		{ _field_short_integer, "string count!" },
		{ _field_terminator }
	};

	TAG_STRUCT(language_pack_definition)
	{
		{ _field_pointer, "string reference pointer!" },
		{ _field_pointer, "string data pointer!" },
		{ _field_long_integer, "number of strings!" },
		{ _field_long_integer, "string data size!" },
		{ _field_long_integer, "string reference cache offset!" },
		{ _field_long_integer, "string data cache offset!" },
		{ _field_array, "string reference checksum!", &data_hash_definition_array },
		{ _field_array, "string data checksum!", &data_hash_definition_array },
		{ _field_long_integer, "data loaded boolean~!" },

		{ _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_long_integer, "unknown@" },
		
		{ _field_terminator }
	};

	TAG_STRUCT(multilingual_unicode_string_list_struct_definition)
	{
		{ _field_custom, "import" },
		{ _field_custom, "import clean" },
		{ _field_block, "string references*", &multilingual_unicode_string_reference_block_block },
		{ _field_block, "substitution pairs*", &string_substitution_pair_block_block },
		{ _field_data, "string data utf8*" },
		{ _field_array, "language pack offsets!", &multilingual_unicode_string_list_language_pack_offsets_array },
		{ _field_terminator }
	};

	TAG_REFERENCE(global_multilingual_unicode_string_list_reference, MULTILINGUAL_UNICODE_STRING_LIST_TAG);

} // namespace blofeld

