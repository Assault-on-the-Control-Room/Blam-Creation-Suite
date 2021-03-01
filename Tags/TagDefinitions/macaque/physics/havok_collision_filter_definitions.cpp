#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		havok_collision_filter_group,
		HAVOK_COLLISION_FILTER_TAG,
		nullptr,
		INVALID_TAG,
		havok_collision_filter_block );

	TAG_BLOCK_FROM_STRUCT(
		havok_collision_filter_block,
		"havok_collision_filter_block",
		1,
		havok_collision_filter_struct_definition);

	#define HAVOK_COLLISION_FILTER_GROUP_BLOCK_ID { 0x6049342A, 0xAB34415C, 0xAF0AB27C, 0x68DABDD9 }
	TAG_BLOCK(
		havok_collision_filter_group_block,
		"havok_collision_filter_group_block",
		k_havok_group_count,
		"s_havok_collision_filter_group",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		HAVOK_COLLISION_FILTER_GROUP_BLOCK_ID)
	{
		{ _field_long_flags, "filter", &collision_filter_enum },
		{ _field_terminator }
	};

	#define HAVOK_COLLISION_FILTER_STRUCT_DEFINITION_ID { 0x509AF768, 0xBE0F4CC5, 0xAAA65F16, 0xBEAB01E6 }
	TAG_STRUCT(
		havok_collision_filter_struct_definition,
		"havok_collision_filter_struct_definition",
		"s_havok_collision_filter_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_WRITEABLE | TAG_MEMORY_USAGE_NON_ALIASED),
		HAVOK_COLLISION_FILTER_STRUCT_DEFINITION_ID)
	{
		FIELD_EXPLANATION("specify what each group collides with", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_block, "groups", &havok_collision_filter_group_block },
		FIELD_PAD("alignment_pad", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_struct, "group filter", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &havok_group_filter_filter_struct },
		{ _field_terminator }
	};

	#define HAVOK_GROUP_FILTER_FILTER_STRUCT_ID { 0x14C2A328, 0xA8CD64B0, 0xCDFB8BE7, 0xDBAF80A0 }
	TAG_STRUCT(
		havok_group_filter_filter_struct,
		"havok_group_filter_filter_struct",
		"hkpGroupFilter",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_WRITEABLE | TAG_MEMORY_USAGE_NON_ALIASED),
		HAVOK_GROUP_FILTER_FILTER_STRUCT_ID)
	{
		{ _field_pointer, "hkReferencedObject vtable", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 | FIELD_FLAG_POINTER, _field_id_zero_data },
		{ _field_short_integer, "size", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_short_integer, "count", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },

		{ _field_legacy, _field_version_platform_include, _platform_type_pc },
		{ _field_legacy, _field_pad, "8byte struct alignment", 4 },

		{ _field_pointer, "hkpCollidableCollidableFilter vtable", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 | FIELD_FLAG_POINTER, _field_id_zero_data },
		{ _field_pointer, "hkpShapeCollectionFilter vtable", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 | FIELD_FLAG_POINTER, _field_id_zero_data },
		{ _field_pointer, "hkpRayShapeCollectionFilter vtable", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 | FIELD_FLAG_POINTER, _field_id_zero_data },
		{ _field_pointer, "hkpRayCollidableFilter vtable", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 | FIELD_FLAG_POINTER, _field_id_zero_data },
		FIELD_PAD("m_prepad[2]", nullptr, FIELD_FLAG_NONE, 8),
		{ _field_long_integer, "m_type", FIELD_FLAG_UNKNOWN0 },
		FIELD_PAD("m_postpad[3]", nullptr, FIELD_FLAG_NONE, 12),
		{ _field_long_integer, "m_nextFreeSystemGroup", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_long_integer, "m_collisionLookupTable00", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_long_integer, "m_collisionLookupTable01", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_long_integer, "m_collisionLookupTable02", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_long_integer, "m_collisionLookupTable03", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_long_integer, "m_collisionLookupTable04", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_long_integer, "m_collisionLookupTable05", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_long_integer, "m_collisionLookupTable06", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_long_integer, "m_collisionLookupTable07", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_long_integer, "m_collisionLookupTable08", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_long_integer, "m_collisionLookupTable09", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_long_integer, "m_collisionLookupTable10", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_long_integer, "m_collisionLookupTable11", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_long_integer, "m_collisionLookupTable12", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_long_integer, "m_collisionLookupTable13", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_long_integer, "m_collisionLookupTable14", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_long_integer, "m_collisionLookupTable15", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_long_integer, "m_collisionLookupTable16", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_long_integer, "m_collisionLookupTable17", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_long_integer, "m_collisionLookupTable18", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_long_integer, "m_collisionLookupTable19", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_long_integer, "m_collisionLookupTable20", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_long_integer, "m_collisionLookupTable21", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_long_integer, "m_collisionLookupTable22", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_long_integer, "m_collisionLookupTable23", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_long_integer, "m_collisionLookupTable24", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_long_integer, "m_collisionLookupTable25", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_long_integer, "m_collisionLookupTable26", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_long_integer, "m_collisionLookupTable27", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_long_integer, "m_collisionLookupTable28", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_long_integer, "m_collisionLookupTable29", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_long_integer, "m_collisionLookupTable30", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_long_integer, "m_collisionLookupTable31", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		FIELD_PAD("16 byte align pad", nullptr, FIELD_FLAG_NONE, 12),

		{ _field_real_vector_3d, "m_pad256[0]", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_real, "havok w m_pad256[0]", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_real_vector_3d, "m_pad256[1]", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_real, "havok w m_pad256[1]", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_real_vector_3d, "m_pad256[2]", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_real, "havok w m_pad256[2]", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_real_vector_3d, "m_pad256[3]", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_real, "havok w m_pad256[3]", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },

		{ _field_legacy, _field_version_platform_include, _platform_type_pc },
		{ _field_legacy, _field_pad, "8byte struct alignment", 4 },

		{ _field_terminator }
	};

	STRINGS(collision_filter_enum)
	{
		"everything",
		"environment default",
		"environment only",
		"small crate",
		"crate",
		"huge crate",
		"item",
		"projectile",
		"machine",
		"early mover machine",
		"creature",
		"biped",
		"dead biped",
		"super collidable ragdoll",
		"ragdoll",
		"vehicle",
		"decal",
		"forge dynamic scenary",
		"small expensive plant",
		"tech art custom",
		"proxy",
		"huge vehicle",
		"ignore environment",
		"character posture",
		"item blocker",
		"user00",
		"zero extent",
		"physical projectile",
		"environment invisible wall",
		"environment play collision",
		"environment bullet collision"
	};
	STRING_LIST(collision_filter_enum, collision_filter_enum_strings, _countof(collision_filter_enum_strings));

} // namespace macaque

} // namespace blofeld

