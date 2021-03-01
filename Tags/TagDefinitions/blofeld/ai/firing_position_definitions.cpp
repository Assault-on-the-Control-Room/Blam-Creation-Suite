#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_BLOCK(firing_positions_block, k_max_firing_positions_per_zone)
	{
		{ _field_legacy, _field_explanation, "CONTROLS~", "Ctrl-N: Creates a new area and assigns it to the current selection of firing points." },
		{ _field_legacy, _field_real_point_3d, "position (local)" },
		//{ _field_legacy, _field_struct, "scenario_bsp_nav", &scenario_bsp_nav_struct_definition }, // #CUSTOM
		{ _field_custom_long_block_index, "packedKeyOffaceref" },
		{ _field_custom_long_block_index, "navMeshUIDOffaceref" },

		{ _field_legacy, _field_word_flags, "flags*", &g_firing_position_flags },
		{ _field_legacy, _field_word_flags, "posture flags", &g_firing_position_posture_flags },
		{ _field_legacy, _field_short_block_index, "area^" },
		{ _field_legacy, _field_short_integer, "cluster index*" },
		{ _field_legacy, _field_short_integer, "cluster bsp*" },
		{ _field_legacy, _field_char_integer, "bits and pad!" },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_char_integer, "unknown" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_legacy, _field_pad, "PAD1", 1 },

		{ _field_legacy, _field_real_euler_angles_2d, "normal" },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_angle, "facing" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_legacy, _field_long_integer, "lastAbsoluteRejectionGameTime!" },

		{ _field_legacy, _field_terminator }
	};

	STRINGS(g_firing_position_flags)
	{
		"open",
		"partial",
		"closed",
		"mobile",
		"wall lean",
		"perch",
		"ground point",
		"dynamic cover point",
		"automatically generated!",
		"nav volume"
	};
	STRING_LIST(g_firing_position_flags, g_firing_position_flags_strings, _countof(g_firing_position_flags_strings));

	STRINGS(g_firing_position_posture_flags)
	{
		"corner_left",
		"corner_right",
		"bunker",
		"bunker high",
		"bunker low"
	};
	STRING_LIST(g_firing_position_posture_flags, g_firing_position_posture_flags_strings, _countof(g_firing_position_posture_flags_strings));

} // namespace blofeld

