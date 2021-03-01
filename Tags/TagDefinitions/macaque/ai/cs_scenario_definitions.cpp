#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define CS_SCRIPT_DATA_BLOCK_ID { 0x667ACAAE, 0x6780495F, 0xB3DDEB61, 0x86448951 }
	TAG_BLOCK(
		cs_script_data_block,
		"cs_script_data_block",
		1,
		"cs_script_data",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		CS_SCRIPT_DATA_BLOCK_ID)
	{
		{ _field_block, "point sets", &cs_point_set_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_block, "animation points", &cs_animation_point_block },

		FIELD_PAD("TPHWNCUR", nullptr, FIELD_FLAG_NONE, 120),
		{ _field_terminator }
	};

	#define CS_POINT_SET_BLOCK_ID { 0xB3DF7F2E, 0x72DA41E9, 0x9FA27244, 0x2AD627D1 }
	TAG_BLOCK(
		cs_point_set_block,
		"cs_point_set_block",
		k_max_point_sets_per_map,
		"cs_point_set",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		CS_POINT_SET_BLOCK_ID)
	{
		{ _field_string, "name", FIELD_FLAG_INDEX },
		{ _field_block, "points", &cs_point_block },
		{ _field_short_block_index, "bsp index", &scenario_structure_bsp_reference_block },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_short_block_index, "reference frame" }, // assembly

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		FIELD_PAD("PAD1", nullptr, FIELD_FLAG_NONE, 2),

		{ _field_long_flags, "flags", &point_set_flags },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_long_flags, "traversal flags", &point_set_traversal_flags },

		{ _field_short_block_index, "editor folder", FIELD_FLAG_UNKNOWN0, &g_scenario_editor_folder_block, _field_id_hide },
		FIELD_PAD("AJDEYNFD", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	#define CS_POINT_BLOCK_STRUCT_ID { 0x2E9A6212, 0xC24649F6, 0xB5738072, 0x69527BF3 }
	TAG_BLOCK(
		cs_point_block,
		"cs_point_block",
		32,
		"cs_point",
		SET_UNKNOWN0 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_IS_MEMCPYABLE | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_WRITEABLE),
		CS_POINT_BLOCK_STRUCT_ID)
	{
		{ _field_string, "name", FIELD_FLAG_INDEX },
		{ _field_string_id, "name_id", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real_point_3d, "position" },
		{ _field_custom_long_block_index, "packedKeyOffaceref", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_UNKNOWN3 },
		{ _field_custom_long_block_index, "navMeshUIDOffaceref", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_UNKNOWN3 },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 1 },
		{ _field_legacy, _field_long_block_index, "surface index" }, // assembly

		{ _field_real_euler_angles_2d, "facing direction" },
		{ _field_terminator }
	};

	#define CS_ANIMATION_POINT_BLOCK_ID { 0x076E9537, 0xC5B54847, 0xA6B8BDB2, 0x81073985 }
	TAG_BLOCK(
		cs_animation_point_block,
		"cs_animation_point_block",
		k_max_animation_points_per_map,
		"cs_animation_point",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CS_ANIMATION_POINT_BLOCK_ID)
	{
		{ _field_string, "name", FIELD_FLAG_INDEX },
		{ _field_long_block_index, "Animating Object", &scenario_object_names_block },
		{ _field_long_integer, "Animating Object Index", FIELD_FLAG_UNKNOWN0 },
		{ _field_string_id, "Animation Name" },
		{ _field_long_integer, "Animation Bone to Track" },
		{ _field_real_point_3d, "Offset From Bone" },
		{ _field_real, "Animation Time Offset" },
		{ _field_real, "Assumed Playback Rate" },
		{ _field_terminator }
	};

	STRINGS(point_set_flags)
	{
		"manual reference frame",
		"turret deployment",
		"giant set",
		"invalid sector refs"
	};
	STRING_LIST(point_set_flags, point_set_flags_strings, _countof(point_set_flags_strings));

	STRINGS(point_set_traversal_flags)
	{
		"curve the traversal path",
		"loop when end is reached"
	};
	STRING_LIST(point_set_traversal_flags, point_set_traversal_flags_strings, _countof(point_set_traversal_flags_strings));

} // namespace macaque

} // namespace blofeld

