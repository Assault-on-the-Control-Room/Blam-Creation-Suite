#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define GLOBAL_PIXEL_SHADER_STRUCT_DEFINITION_ID { 0x4D7594D2, 0x86B447C9, 0xAB545AE9, 0x92626D45 }
	TAG_BLOCK(
		global_pixel_shader_block,
		"global_pixel_shader_block",
		1,
		"s_global_render_method_pixel_shader",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		GLOBAL_PIXEL_SHADER_STRUCT_DEFINITION_ID)
	{
		{ _field_block, "entry points", &global_shader_entry_point_block },
		{ _field_dword_integer, "version", FIELD_FLAG_READ_ONLY },
		{ _field_block, "compiled shaders", &compiled_pixel_shader_block },
		{ _field_terminator }
	};

	TAG_GROUP(
		global_pixel_shader_group,
		GLOBAL_PIXEL_SHADER_TAG,
		nullptr,
		INVALID_TAG,
		global_pixel_shader_block );

	#define GLOBAL_VERTEX_SHADER_STRUCT_DEFINITION_ID { 0x6551E55E, 0x833B4478, 0x87DF6901, 0x1AA92BE2 }
	TAG_BLOCK(
		global_vertex_shader_block,
		"global_vertex_shader_block",
		1,
		"s_global_render_method_vertex_shader",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		GLOBAL_VERTEX_SHADER_STRUCT_DEFINITION_ID)
	{
		{ _field_block, "vertex types", &global_vertex_shader_vertex_types_block },
		{ _field_dword_integer, "version", FIELD_FLAG_READ_ONLY },
		{ _field_block, "compiled shaders", &compiled_vertex_shader_block },
		{ _field_terminator }
	};

	TAG_GROUP(
		global_vertex_shader_group,
		GLOBAL_VERTEX_SHADER_TAG,
		nullptr,
		INVALID_TAG,
		global_vertex_shader_block );

	TAG_GROUP(
		global_cache_file_pixel_shaders_group,
		GLOBAL_CACHE_FILE_PIXEL_SHADERS_TAG,
		nullptr,
		INVALID_TAG,
		global_cache_file_pixel_shaders_block );

	TAG_GROUP(
		hlsl_include_group,
		HLSL_INCLUDE_TAG,
		nullptr,
		INVALID_TAG,
		hlsl_include_block );

	#define PIXEL_SHADER_STRUCT_DEFINITION_ID { 0xA0282D19, 0x14CF4500, 0xBB7ADB22, 0x40C57D44 }
	TAG_BLOCK(
		pixel_shader_block,
		"pixel_shader_block",
		1,
		"c_rasterizer_pixel_shader",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		PIXEL_SHADER_STRUCT_DEFINITION_ID)
	{
		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_dword_integer, "unknown@" },

		{ _field_block, "entry points", &pixel_entry_point_block },
		{ _field_dword_integer, "version", FIELD_FLAG_READ_ONLY },
		{ _field_block, "compiled shaders", &compiled_pixel_shader_block },
		{ _field_terminator }
	};

	TAG_GROUP(
		pixel_shader_group,
		PIXEL_SHADER_TAG,
		nullptr,
		INVALID_TAG,
		pixel_shader_block );

	#define VERTEX_SHADER_STRUCT_DEFINITION_ID { 0x60FD71E9, 0xC5654B09, 0xBE6F6918, 0x7C935A75 }
	TAG_BLOCK(
		vertex_shader_block,
		"vertex_shader_block",
		1,
		"c_rasterizer_vertex_shader",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		VERTEX_SHADER_STRUCT_DEFINITION_ID)
	{
		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_dword_integer, "unknown@" },

		{ _field_block, "entry points", &vertex_entry_point_block },
		{ _field_dword_integer, "version", FIELD_FLAG_READ_ONLY },
		{ _field_block, "compiled shaders", &compiled_vertex_shader_block },
		{ _field_terminator }
	};

	TAG_GROUP(
		vertex_shader_group,
		VERTEX_SHADER_TAG,
		nullptr,
		INVALID_TAG,
		vertex_shader_block );

	TAG_BLOCK_FROM_STRUCT(
		global_cache_file_pixel_shaders_block,
		"global_cache_file_pixel_shaders_block",
		1,
		global_cache_file_pixel_shaders_struct_definition);

	TAG_BLOCK_FROM_STRUCT(
		hlsl_include_block,
		"hlsl_include_block",
		1,
		hlsl_include_struct_definition);

	#define GLOBAL_SHADER_ENTRY_POINT_BLOCK_ID { 0xC774B246, 0x4B264463, 0x8F00FFB5, 0xDBF46C9D }
	TAG_BLOCK(
		global_shader_entry_point_block,
		"global_shader_entry_point_block",
		k_number_of_entry_points*2,
		"s_global_shader_entry_point_dependency",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		GLOBAL_SHADER_ENTRY_POINT_BLOCK_ID)
	{
		{ _field_block, "category dependency", &global_shader_category_dependency_block },
		{ _field_long_integer, "default compiled shader index" },
		{ _field_terminator }
	};

	#define GLOBAL_SHADER_CATEGORY_DEPENDENCY_ID { 0x5F7BC1E8, 0x34304024, 0xA5DBCB55, 0x1D18FDE8 }
	TAG_BLOCK(
		global_shader_category_dependency_block,
		"global_shader_category_dependency",
		c_render_method_definition::k_maximum_categories,
		"s_global_shader_category_dependency",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		GLOBAL_SHADER_CATEGORY_DEPENDENCY_ID)
	{
		{ _field_long_integer, "definition category index" },
		{ _field_block, "option dependency", &global_shader_option_dependency_block },
		{ _field_terminator }
	};

	#define GLOBAL_SHADER_OPTION_DEPENDENCY_ID { 0x36B7BB10, 0x29F2482F, 0xA621D1B7, 0x8FC91F6E }
	TAG_BLOCK(
		global_shader_option_dependency_block,
		"global_shader_option_dependency",
		c_render_method_definition::k_maximum_category_options,
		"s_category_option_dependency",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		GLOBAL_SHADER_OPTION_DEPENDENCY_ID)
	{
		{ _field_long_integer, "compiled shader index" },
		{ _field_terminator }
	};

	#define COMPILED_PIXEL_SHADER_BLOCK_ID { 0xFA151841, 0x172743E2, 0xB91717BF, 0x3BAF16F7 }
	TAG_BLOCK(
		compiled_pixel_shader_block,
		"compiled_pixel_shader_block",
		10*k_kilo,
		"c_rasterizer_compiled_pixel_shader",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_WRITEABLE),
		COMPILED_PIXEL_SHADER_BLOCK_ID)
	{
		{ _field_struct, "compiled shader splut", &rasterizer_compiled_shader_struct },
		{ _field_long_integer, "runtime shader ", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3, _field_id_shader_unknown },

		{ _field_legacy, _field_version_platform_include, _platform_type_pc, 2 },
		{ _field_legacy, _field_version_greater_or_equal, _engine_type_halo4, 1 },
		{ _field_legacy, _field_pad, "padding", 4 },

		{ _field_terminator }
	};

	#define GLOBAL_VERTEX_SHADER_VERTEX_TYPES_BLOCK_ID { 0xD8909DB6, 0x9DFC44C9, 0xA2F08BB0, 0x5B8D92E6 }
	TAG_BLOCK(
		global_vertex_shader_vertex_types_block,
		"global_vertex_shader_vertex_types_block",
		k_number_of_vertex_types*2,
		"s_global_vertex_shader_vertex_type",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		GLOBAL_VERTEX_SHADER_VERTEX_TYPES_BLOCK_ID)
	{
		{ _field_block, "entry point dependency", &global_shader_entry_point_block },
		{ _field_terminator }
	};

	#define COMPILED_VERTEX_SHADER_BLOCK_ID { 0x3543DB1D, 0x836C4843, 0xB307E446, 0x83BD276F }
	TAG_BLOCK(
		compiled_vertex_shader_block,
		"compiled_vertex_shader_block",
		10*k_kilo,
		"c_rasterizer_compiled_vertex_shader",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_WRITEABLE),
		COMPILED_VERTEX_SHADER_BLOCK_ID)
	{
		{ _field_struct, "compiled shader splut", &rasterizer_compiled_shader_struct },
		{ _field_long_integer, "runtime shader ", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3, _field_id_shader_unknown },

		{ _field_legacy, _field_version_platform_include, _platform_type_pc, 2 },
		{ _field_legacy, _field_version_greater_or_equal, _engine_type_halo4, 1 },
		{ _field_legacy, _field_pad, "padding", 4 },

		{ _field_terminator }
	};

	#define PIXEL_ENTRY_POINT_BLOCK_ID { 0x1E202E95, 0x06BA407D, 0x9B57749D, 0xC19E5EF2 }
	TAG_BLOCK(
		pixel_entry_point_block,
		"pixel_entry_point_block",
		k_kilo,
		"s_compiled_shader_reference",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PIXEL_ENTRY_POINT_BLOCK_ID)
	{
		{ _field_byte_integer, "start index" },
		{ _field_byte_integer, "count" },
		{ _field_terminator }
	};

	#define VERTEX_ENTRY_POINT_BLOCK_ID { 0x7D27C32F, 0x4BFF419F, 0xAE908394, 0xF054F56B }
	TAG_BLOCK(
		vertex_entry_point_block,
		"vertex_entry_point_block",
		k_number_of_vertex_types*2,
		"s_tag_block",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		VERTEX_ENTRY_POINT_BLOCK_ID)
	{
		{ _field_block, "vertex types", &vertex_types_block$3_block },
		{ _field_terminator }
	};

	#define VERTEX_TYPES_BLOCK_ID { 0x179BB0D5, 0x3B834BE0, 0x81D71471, 0xB7FD5D61 }
	TAG_BLOCK(
		vertex_types_block$3_block,
		"vertex_types_block",
		k_kilo,
		"s_compiled_shader_reference",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		VERTEX_TYPES_BLOCK_ID)
	{
		{ _field_byte_integer, "start index" },
		{ _field_byte_integer, "count" },
		{ _field_terminator }
	};

	#define GLOBAL_CACHE_FILE_PIXEL_SHADERS_STRUCT_DEFINITION_ID { 0xA0F8ADA1, 0x1ACFD5EA, 0xA2DA2122, 0x4AC1DDEE }
	TAG_STRUCT(
		global_cache_file_pixel_shaders_struct_definition,
		"global_cache_file_pixel_shaders_struct_definition",
		"c_global_cache_file_pixel_shaders",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		GLOBAL_CACHE_FILE_PIXEL_SHADERS_STRUCT_DEFINITION_ID)
	{
		{ _field_long_integer, "shader count" },
		{ _field_long_integer, "cached shader count" },
		{ _field_long_integer, "total memory size" },
		{ _field_long_integer, "cached memory size" },
		{ _field_block, "compiled shaders", &compiled_pixel_shader_block },
		{ _field_terminator }
	};

	#define HLSL_INCLUDE_STRUCT_DEFINITION_ID { 0x7481D09D, 0x2F6D4C89, 0xB397EADA, 0xCEE7E3AE }
	TAG_STRUCT(
		hlsl_include_struct_definition,
		"hlsl_include_struct_definition",
		"c_rasterizer_hlsl_include_file",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		HLSL_INCLUDE_STRUCT_DEFINITION_ID)
	{
		{ _field_data, "include file" },
		{ _field_terminator }
	};

	#define RASTERIZER_COMPILED_SHADER_STRUCT_ID { 0xF99B344C, 0x5A344EF5, 0x8D1FB1EE, 0xFC6B0182 }
	TAG_STRUCT(
		rasterizer_compiled_shader_struct,
		"rasterizer_compiled_shader_struct",
		"c_rasterizer_compiled_shader",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		RASTERIZER_COMPILED_SHADER_STRUCT_ID)
	{
		{ _field_long_flags, "shader flags", &shader_flags },
		{ _field_data, "xenon compiled shader", MAKE_OLD_NAMES("..:xenon compiled shader") },
		{ _field_data, "dx9 compiled shader", MAKE_OLD_NAMES("..:dx9 compiled shader") },
		FIELD_EXPLANATION("Xenon constant table", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_struct, "xenon rasterizer constant table", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &global_rasterizer_constant_table_struct },
		FIELD_EXPLANATION("DX9 constant table", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_struct, "dx9 rasterizer constant table", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &global_rasterizer_constant_table_struct },
		{ _field_dword_integer, "gprs", MAKE_OLD_NAMES("..:gprs") },
		{ _field_long_integer, "cache file reference", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	STRINGS(shader_flags)
	{
		"requires constant table"
	};
	STRING_LIST(shader_flags, shader_flags_strings, _countof(shader_flags_strings));

} // namespace macaque

} // namespace blofeld

