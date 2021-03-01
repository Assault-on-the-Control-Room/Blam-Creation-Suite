#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_BLOCK(cs_point_block, 32)
	{
		{ _field_legacy, _field_string, "name^" },
		{ _field_legacy, _field_string_id, "name_id*!" },
		{ _field_legacy, _field_real_point_3d, "position" },
		//{ _field_legacy, _field_struct, "scenario_bsp_nav", &scenario_bsp_nav_struct_definition }, // #CUSTOM
		{ _field_custom_long_block_index, "packedKeyOffaceref" },
		{ _field_custom_long_block_index, "navMeshUIDOffaceref" },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 1 },
		{ _field_legacy, _field_long_block_index, "surface index" }, // assembly

		{ _field_legacy, _field_real_euler_angles_2d, "facing direction" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(cs_point_set_block, k_max_point_sets_per_map)
	{
		{ _field_legacy, _field_string, "name^" },
		{ _field_legacy, _field_block, "points", &cs_point_block_block },
		{ _field_legacy, _field_short_block_index, "bsp index" },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_short_block_index, "reference frame" }, // assembly

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_legacy, _field_pad, "PAD1", 2 },
		
		{ _field_legacy, _field_long_flags, "flags", &point_set_flags },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_legacy, _field_long_flags, "traversal flags", &point_set_traversal_flags },

		{ _field_legacy, _field_short_block_index, "editor folder!" },
		{ _field_legacy, _field_pad, "AJDEYNFD", 2 },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(cs_animation_point_block, k_max_animation_points_per_map)
	{
		{ _field_legacy, _field_string, "name^" },
		{ _field_legacy, _field_long_block_index, "Animating Object" },
		{ _field_legacy, _field_long_integer, "Animating Object Index!" },
		{ _field_legacy, _field_string_id, "Animation Name" },
		{ _field_legacy, _field_long_integer, "Animation Bone to Track" },
		{ _field_legacy, _field_real_point_3d, "Offset From Bone" },
		{ _field_legacy, _field_real, "Animation Time Offset" },
		{ _field_legacy, _field_real, "Assumed Playback Rate" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(cs_script_data_block, 1)
	{
		{ _field_legacy, _field_block, "point sets", &cs_point_set_block_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_legacy, _field_block, "animation points", &cs_animation_point_block_block },

		{ _field_legacy, _field_pad, "TPHWNCUR", 120 },
		{ _field_legacy, _field_terminator }
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

} // namespace blofeld

