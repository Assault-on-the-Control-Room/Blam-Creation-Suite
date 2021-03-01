#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define MOPP_CODE_DEFINITION_BLOCK_ID { 0xEE2BC898, 0x8AD14E98, 0xB64351E5, 0x635CF676 }
	TAG_BLOCK(
		mopp_code_definition_block,
		"mopp_code_definition_block",
		SHORT_MAX,
		"s_havok_mopp_code_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_WRITEABLE | TAG_MEMORY_USAGE_NON_ALIASED),
		MOPP_CODE_DEFINITION_BLOCK_ID,
		4)
	{
		// hkBaseObject
		{ _field_pointer, "field pointer skip", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_UNKNOWN3 | FIELD_FLAG_POINTER, _field_id_zero_data }, // vftbl

		// hkReferencedObject
		{ _field_short_integer, "size", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "count", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },

		{ _field_legacy, _field_version_platform_include, _platform_type_pc },
		FIELD_PAD("total shit pad1", nullptr, FIELD_FLAG_NONE, 4),

		{ _field_legacy, _field_version_platform_exclude, _platform_type_pc, 2 },
		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach },
		FIELD_PAD("total shit pad1", nullptr, FIELD_FLAG_NONE, 8),

		{ _field_legacy, _field_version_equal, _engine_type_haloreach }, // unknown. havok struct modified?? data was nuke?
		{ _field_legacy, _field_pad, "unknown", 16 },

		// hkpMoppCode
		// CodeInfo m_info
		{ _field_real, "v.i", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY }, // hkVector4 m_offset
		{ _field_real, "v.j", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real, "v.k", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real, "v.w", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },

		// hkArray<hkUint8> m_data
		// hkArrayBase

		// unknown Halo 4 PC modification to hkArray/hkArrayBase
		{ _field_legacy, _field_version_platform_include, _platform_type_pc, 3 },
		{ _field_legacy, _field_version_greater_or_equal, _engine_type_halo4, 2 },
		{ _field_legacy, _field_long_integer, "@unknown" },
		{ _field_legacy, _field_pad, "padding", 4 },

		{ _field_pointer, "m_data pointer", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_UNKNOWN3 | FIELD_FLAG_POINTER, _field_id_zero_data },  // T* m_data
		{ _field_long_integer, "int m_size", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY }, // int m_size
		{ _field_long_integer, "int m_capacityAndFlags", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY }, // int m_capacityAndFlags highest 2 bits indicate any special considerations about the allocation for the array

		// kEnum<BuildType, hkInt8> m_buildType
		{ _field_char_integer, "int8 m_buildType", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		FIELD_PAD("total shit pad2", nullptr, FIELD_FLAG_NONE, 3),

		{ _field_legacy, _field_version_platform_include, _platform_type_pc, 4 },
		{ _field_legacy, _field_version_equal, _engine_type_haloreach },
		{ _field_legacy, _field_pad, "padding", 12 }, // alignment
		{ _field_legacy, _field_version_greater_or_equal, _engine_type_halo4 },
		{ _field_legacy, _field_pad, "padding", 4 }, // alignment


		// ## blam specific data below ##
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_hidd_begin),
		{ _field_block, "mopp data block ", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &mopp_code_data_definition_block },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_hidd_end),
		{ _field_char_integer, "mopp build type", "they say it only matters for ps3", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		FIELD_PAD("explicit alignment pad 3", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_terminator }
	};

	#define MOPP_CODE_DATA_DEFINITION_BLOCK_ID { 0x0EAB741F, 0xF5D74408, 0x9D5A32E1, 0x12D4FD6D }
	TAG_BLOCK(
		mopp_code_data_definition_block,
		"mopp_code_data_definition_block",
		16*(1024*1024),
		"byte",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		MOPP_CODE_DATA_DEFINITION_BLOCK_ID)
	{
		{ _field_byte_integer, "mopp data", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

} // namespace macaque

} // namespace blofeld

