#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(rasterizer_cache_file_globals, RASTERIZER_CACHE_FILE_GLOBALS_TAG, rasterizer_cache_file_globals_block_block );

	TAG_BLOCK_FROM_STRUCT(rasterizer_cache_file_globals_block, 1, rasterizer_cache_file_globals_struct_definition_struct_definition );

	TAG_STRUCT(rasterizer_cache_file_globals_struct_definition)
	{
		{ _field_long_integer, "texture header count" },

		{ _field_version_greater_or_equal, _engine_type_haloreach, 2 },
		{ _field_long_integer, "maximum vertex shader gprs" },
		{ _field_long_integer, "maximum pixel shader gprs" },
		
		{ _field_terminator }
	};

} // namespace blofeld

