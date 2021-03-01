#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define COLLISION_BSP_PHYSICS_BLOCK_ID { 0x5B8E7B3A, 0xC8394498, 0xB6AE249F, 0x4C00F83F }
	TAG_BLOCK(
		collision_bsp_physics_block,
		"collision_bsp_physics_block",
		(1024),
		"s_collision_bsp_physics_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_WRITEABLE | TAG_MEMORY_USAGE_NON_ALIASED),
		COLLISION_BSP_PHYSICS_BLOCK_ID,
		4)
	{
		{ _field_struct, "collision bsp shape", &collision_geometry_shape_struct },
		{ _field_struct, "mopp bv tree shap", &mopp_bv_tree_shape_struct },
		{ _field_terminator }
	};

	#define COLLISION_GEOMETRY_SHAPE_STRUCT_ID { 0x97B622E0, 0xF8AF48BA, 0x85446709, 0x0386FA88 }
	TAG_STRUCT(
		collision_geometry_shape_struct,
		"collision_geometry_shape_struct",
		"c_collision_geometry_shape",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_WRITEABLE | TAG_MEMORY_USAGE_NON_ALIASED),
		COLLISION_GEOMETRY_SHAPE_STRUCT_ID,
		4)
	{
		{ _field_struct, "base", &havok_shape_collection_struct_2010_2 },

		{ _field_legacy, _field_version_platform_exclude, _platform_type_pc },
		FIELD_PAD("foobar666", nullptr, FIELD_FLAG_NONE, 8),

		{ _field_real_vector_3d, "center", FIELD_FLAG_READ_ONLY },
		{ _field_real, "havok w center", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real_vector_3d, "half extent", FIELD_FLAG_READ_ONLY },
		{ _field_real, "havok w half extent", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "runtime model definition tag index", FIELD_FLAG_UNKNOWN0 },

		{ _field_legacy, _field_version_platform_include, _platform_type_pc },
		{ _field_legacy, _field_pad, "8byte alignment", 4 },

		{ _field_pointer, "collision bsp reference pointer0", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_UNKNOWN3 | FIELD_FLAG_POINTER, _field_id_zero_data },
		{ _field_pointer, "collision bsp reference pointer1", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_UNKNOWN3 | FIELD_FLAG_POINTER, _field_id_zero_data },
		{ _field_char_integer, "structure_bsp_index", FIELD_FLAG_UNKNOWN0 },
		{ _field_char_integer, "collision geometry shape type", FIELD_FLAG_UNKNOWN0 },
		{ _field_short_integer, "instance index", FIELD_FLAG_UNKNOWN0 },

		{ _field_real, "scale", FIELD_FLAG_UNKNOWN0 },
		FIELD_PAD("3 long pad", nullptr, FIELD_FLAG_NONE, 12),

		{ _field_legacy, _field_version_platform_include, _platform_type_pc },
		{ _field_legacy, _field_pad, "8byte alignment", 4 },

		{ _field_terminator }
	};

	#define MOPP_BV_TREE_SHAPE_STRUCT_ID { 0x662B38A4, 0xAAAC448C, 0x81C491AB, 0xA4E2A6EE }
	TAG_STRUCT(
		mopp_bv_tree_shape_struct,
		"mopp_bv_tree_shape_struct",
		"c_mopp_bv_tree_shape",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_WRITEABLE | TAG_MEMORY_USAGE_NON_ALIASED),
		MOPP_BV_TREE_SHAPE_STRUCT_ID,
		4)
	{
		{ _field_struct, "mopp bv tree shape", &havok_shape_struct_2010_2 },
		FIELD_PAD("m_bvTreeType", nullptr, FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_UNKNOWN3, 1),
		FIELD_PAD("3 other bytes", nullptr, FIELD_FLAG_NONE, 3),

		{ _field_legacy, _field_version_platform_include, _platform_type_pc },
		{ _field_legacy, _field_pad, "8byte alignment", 4 },

		// hkMoppBvTreeShapeBase
		{ _field_pointer, "mopp code pointer", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_UNKNOWN3 | FIELD_FLAG_POINTER, _field_id_zero_data },
		{ _field_pointer, "mopp data skip", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_UNKNOWN3 | FIELD_FLAG_POINTER, _field_id_zero_data },
		{ _field_long_integer, "mopp data size", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_UNKNOWN3 },

		{ _field_legacy, _field_version_platform_include, _platform_type_pc },
		{ _field_legacy, _field_pad, "8byte alignment", 4 },

		{ _field_real_vector_3d, "code info copy", FIELD_FLAG_READ_ONLY },
		{ _field_real, "havok w code info copy", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },

		// hkpSingleShapeContainer
		{ _field_pointer, "child shape vtable", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 | FIELD_FLAG_POINTER, _field_id_zero_data },
		{ _field_pointer, "child shape pointer", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_UNKNOWN3 | FIELD_FLAG_POINTER, _field_id_zero_data },
		{ _field_long_integer, "child size", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_UNKNOWN3 },

		{ _field_legacy, _field_version_platform_include, _platform_type_pc },
		{ _field_legacy, _field_pad, "8byte alignment", 4 },

		FIELD_PAD("mopp alignment", nullptr, FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3, 4),
		{ _field_real, "mopp scale", FIELD_FLAG_READ_ONLY },

		{ _field_legacy, _field_version_platform_include, _platform_type_pc },
		{ _field_legacy, _field_pad, "final pad", 16 },

		{ _field_legacy, _field_version_platform_exclude, _platform_type_pc },
		FIELD_PAD("final pad", nullptr, FIELD_FLAG_NONE, 12),

		{ _field_terminator }
	};

} // namespace macaque

} // namespace blofeld

