#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_BLOCK(firing_point_payload_block, 1)
	{
		{ _field_legacy, _field_real, "radius" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(stimulus_payload_block, 1)
	{
		{ _field_legacy, _field_string_id, "stimulus type" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(combat_cue_payload_block, 1)
	{
		{ _field_legacy, _field_real_point_3d, "position!" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 4 },
		{ _field_legacy, _field_custom_long_block_index, "packedKeyOffaceref~!" },
		{ _field_legacy, _field_custom_long_block_index, "navMeshUIDOffaceref~!" },
		{ _field_legacy, _field_word_flags, "flags!", &g_firing_position_flags },
		{ _field_legacy, _field_word_flags, "posture flags!", &g_firing_position_posture_flags },

		{ _field_legacy, _field_short_block_index, "area^!" },
		{ _field_legacy, _field_short_integer, "cluster index!" },
		{ _field_legacy, _field_short_integer, "cluster bsp*" },
		{ _field_legacy, _field_char_integer, "bits and pad!" },
		{ _field_legacy, _field_pad, "PAD1", 1 },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_long_integer, "unknown" },

		{ _field_legacy, _field_real_euler_angles_2d, "normal!" },
		{ _field_legacy, _field_angle, "facing!" },
		{ _field_legacy, _field_long_integer, "lastAbsoluteRejectionGameTime!" },
		{ _field_legacy, _field_enum, "preference", &combat_cue_preference_enum },
		{ _field_legacy, _field_pad, "post-preference", 2 },

		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(ai_cue_template_block, k_max_ai_cue_templates)
	{
		{ _field_legacy, _field_string_id, "name^" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_legacy, _field_long_flags, "template_flags", &cue_template_flags },

		{ _field_legacy, _field_block, "firing points", &firing_point_payload_block_block },
		{ _field_legacy, _field_block, "stimulus", &stimulus_payload_block_block },
		{ _field_legacy, _field_block, "combat cue", &combat_cue_payload_block_block },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(task_distribution_block, k_max_task_distributions_per_cue)
	{
		{ _field_legacy, _field_short_block_index, "objective" },
		{ _field_legacy, _field_custom_short_block_index, "task" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(radial_distribution_block, k_max_radial_distributions_per_cue)
	{
		{ _field_legacy, _field_real, "radius" },
		{ _field_legacy, _field_short_integer, "travel time (ticks)" },
		{ _field_legacy, _field_pad, "post-travel-time", 2 },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(probability_distribution_block, k_max_probability_distributions_per_cue)
	{
		{ _field_legacy, _field_real, "chance per second" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(character_distribution_block, k_max_character_distributions_per_cue)
	{
		{ _field_legacy, _field_short_block_index, "character" },
		{ _field_legacy, _field_byte_flags, "flags", &distribution_character_flags },
		{ _field_legacy, _field_pad, "post-flags", 1 },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(weapon_distribution_block, k_max_weapon_distributions_per_cue)
	{
		{ _field_legacy, _field_short_block_index, "weapon" },
		{ _field_legacy, _field_pad, "post-weapon-palette-index", 2 },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(script_payload_block, 1)
	{
		{ _field_legacy, _field_string_id, "script function name" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(combat_sync_action_group_payload_block, 1)
	{
		{ _field_legacy, _field_string_id, "sync action group name" },
		{ _field_legacy, _field_real, "cooldown#seconds" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(ai_cue_block, k_max_ai_cues_per_level)
	{
		{ _field_legacy, _field_string_id, "name^" },
		{ _field_legacy, _field_byte_flags, "flags", &cue_flags },
		{ _field_legacy, _field_char_integer, "quick cue*!" },
		{ _field_legacy, _field_short_integer, "editor folder!" },
		{ _field_legacy, _field_real_point_3d, "position!" },
		//{ _field_legacy, _field_struct, "scenario_bsp_nav", &scenario_bsp_nav_struct_definition }, // #CUSTOM
		{ _field_custom_long_block_index, "packedKeyOffaceref" },
		{ _field_custom_long_block_index, "navMeshUIDOffaceref" },
		{ _field_legacy, _field_real_euler_angles_2d, "facing (yaw, pitch):degrees" },
		{ _field_legacy, _field_real, "roll" },
		{ _field_legacy, _field_custom, "distribution" },
		{ _field_legacy, _field_struct, "distribution", &cue_distribution_struct_struct_definition },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_custom, "payload" },
		{ _field_legacy, _field_struct, "payload", &cue_payload_struct_struct_definition },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_pad, "no-cue-definition-index", 4 },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(ai_full_cue_block, k_max_ai_cues_per_level)
	{
		{ _field_legacy, _field_string_id, "name^" },
		{ _field_legacy, _field_byte_flags, "flags", &cue_flags },
		{ _field_legacy, _field_char_integer, "quick cue*!" },
		{ _field_legacy, _field_short_block_index, "editor folder!" },
		{ _field_legacy, _field_real_point_3d, "position" },
		//{ _field_legacy, _field_struct, "scenario_bsp_nav", &scenario_bsp_nav_struct_definition }, // #CUSTOM
		{ _field_custom_long_block_index, "packedKeyOffaceref" },
		{ _field_custom_long_block_index, "navMeshUIDOffaceref" },
		{ _field_legacy, _field_real_euler_angles_2d, "facing!" },
		{ _field_legacy, _field_real, "roll!" },
		{ _field_legacy, _field_explanation, "Distribution", "The following blocks describe who will receive this cue." },
		{ _field_legacy, _field_custom, "distribution" },
		{ _field_legacy, _field_struct, "distribution", &cue_distribution_struct_struct_definition },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_explanation, "Payload", "The following blocks describe the type of stimulus and related payload; you should only specify one." },
		{ _field_legacy, _field_custom, "payload" },
		{ _field_legacy, _field_struct, "payload", &cue_payload_struct_struct_definition },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_long_block_index, "cue definition index!" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(ai_quick_cue_block, k_max_ai_cues_per_level)
	{
		{ _field_legacy, _field_string_id, "name^" },
		{ _field_legacy, _field_byte_flags, "flags", &quick_cue_flags },
		{ _field_legacy, _field_pad, "post-flags", 1 },
		{ _field_legacy, _field_short_block_index, "editor folder!" },
		{ _field_legacy, _field_real_point_3d, "position" },
		//{ _field_legacy, _field_struct, "scenario_bsp_nav", &scenario_bsp_nav_struct_definition }, // #CUSTOM
		{ _field_custom_long_block_index, "packedKeyOffaceref" },
		{ _field_custom_long_block_index, "navMeshUIDOffaceref" },
		{ _field_legacy, _field_real_euler_angles_2d, "facing!" },
		{ _field_legacy, _field_real, "roll!" },
		{ _field_legacy, _field_block, "tasks*!", &task_distribution_block_block },
		{ _field_legacy, _field_short_block_index, "character" },
		{ _field_legacy, _field_short_block_index, "weapon" },
		{ _field_legacy, _field_string_id, "template" },
		{ _field_legacy, _field_long_block_index, "cue definition index!" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_STRUCT(cue_distribution_struct)
	{
		{ _field_legacy, _field_block, "tasks*!", &task_distribution_block_block },
		{ _field_legacy, _field_struct, "distribution", &cue_stimulus_distribution_struct_struct_definition },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_STRUCT(cue_stimulus_distribution_struct)
	{
		{ _field_legacy, _field_block, "radius", &radial_distribution_block_block },
		{ _field_legacy, _field_block, "probability", &probability_distribution_block_block },
		{ _field_legacy, _field_block, "characters", &character_distribution_block_block },
		{ _field_legacy, _field_block, "weapons", &weapon_distribution_block_block },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_STRUCT(cue_payload_struct)
	{
		{ _field_legacy, _field_block, "firing points", &firing_point_payload_block_block },
		{ _field_legacy, _field_block, "script", &script_payload_block_block },
		{ _field_legacy, _field_block, "combat sync action", &combat_sync_action_group_payload_block_block },
		{ _field_legacy, _field_block, "stimulus", &stimulus_payload_block_block },
		{ _field_legacy, _field_block, "combat cue", &combat_cue_payload_block_block },
		{ _field_legacy, _field_terminator }
	};

	STRINGS(cue_flags)
	{
		"not initially placed",
		"passive stimulus"
	};
	STRING_LIST(cue_flags, cue_flags_strings, _countof(cue_flags_strings));

	STRINGS(cue_template_flags)
	{
		"ignored",
		"passive stimulus"
	};
	STRING_LIST(cue_template_flags, cue_template_flags_strings, _countof(cue_template_flags_strings));

	STRINGS(quick_cue_flags)
	{
		"don\'t distribute to children"
	};
	STRING_LIST(quick_cue_flags, quick_cue_flags_strings, _countof(quick_cue_flags_strings));

	STRINGS(distribution_character_flags)
	{
		"don\'t distribute to children"
	};
	STRING_LIST(distribution_character_flags, distribution_character_flags_strings, _countof(distribution_character_flags_strings));

	STRINGS(combat_cue_preference_enum)
	{
		"low",
		"high",
		"total"
	};
	STRING_LIST(combat_cue_preference_enum, combat_cue_preference_enum_strings, _countof(combat_cue_preference_enum_strings));

} // namespace blofeld

