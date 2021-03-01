#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define RASTERIZER_CONSTANT_BLOCK_ID { 0x9EAC07AB, 0x559D43EF, 0x88AEF5BC, 0x656E3255 }
	TAG_BLOCK(
		rasterizer_constant_block,
		"rasterizer_constant_block",
		c_rasterizer_constant_table_definition::k_max_constants,
		"c_rasterizer_constant_definition",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		RASTERIZER_CONSTANT_BLOCK_ID)
	{
		{ _field_string_id, "constant name", FIELD_FLAG_INDEX },
		{ _field_word_integer, "register start", FIELD_FLAG_READ_ONLY },
		{ _field_byte_integer, "register count", FIELD_FLAG_READ_ONLY },
		{ _field_char_enum, "register set", FIELD_FLAG_READ_ONLY, &register_set_enum },
		{ _field_terminator }
	};

	#define GLOBAL_RASTERIZER_CONSTANT_TABLE_STRUCT_ID { 0x88225AE9, 0x664A4892, 0xA3910819, 0x46CAAEFB }
	TAG_STRUCT(
		global_rasterizer_constant_table_struct,
		"global_rasterizer_constant_table_struct",
		"c_rasterizer_constant_table_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		GLOBAL_RASTERIZER_CONSTANT_TABLE_STRUCT_ID)
	{
		{ _field_block, "constants", FIELD_FLAG_READ_ONLY, &rasterizer_constant_block },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 2 },
		{ _field_legacy, _field_dword_integer, "unknown@" },
		{ _field_legacy, _field_dword_integer, "unknown@" },

		{ _field_char_enum, "type", FIELD_FLAG_READ_ONLY, &rasterizer_constant_table_type_enum },
		FIELD_PAD("qersaui", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_terminator }
	};

	STRINGS(register_set_enum)
	{
		"bool",
		"int",
		"float",
		"sampler",
		"vertex_bool",
		"vertex_int",
		"vertex_float",
		"vertex_sampler"
	};
	STRING_LIST(register_set_enum, register_set_enum_strings, _countof(register_set_enum_strings));

	STRINGS(rasterizer_constant_table_type_enum)
	{
		"vertex",
		"pixel"
	};
	STRING_LIST(rasterizer_constant_table_type_enum, rasterizer_constant_table_type_enum_strings, _countof(rasterizer_constant_table_type_enum_strings));

} // namespace macaque

} // namespace blofeld

