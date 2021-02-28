#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define AI_CUE_TEMPLATE_BLOCK_STRUCT_ID { 0x6A4327A8, 0x23424013, 0x82100EBF, 0x905BE117 }
	TAG_BLOCK(
		ai_cue_template_block,
		"ai_cue_template_block",
		k_max_ai_cue_templates,
		"s_ai_cue_template_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		AI_CUE_TEMPLATE_BLOCK_STRUCT_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_long_flags, "template_flags", &cue_template_flags },
		
		{ _field_block, "firing points", &firing_point_payload_block },
		{ _field_block, "stimulus", &stimulus_payload_block },
		{ _field_block, "combat cue", &combat_cue_payload_block },
		{ _field_terminator }
	};

	#define FIRING_POINT_PAYLOAD_BLOCK_STRUCT_ID { 0x6558B362, 0xE6E44C39, 0xA65A64FC, 0x061CE475 }
	TAG_BLOCK(
		firing_point_payload_block,
		"firing_point_payload_block",
		1,
		"s_cue_payload_firing_point",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		FIRING_POINT_PAYLOAD_BLOCK_STRUCT_ID)
	{
		{ _field_real, "radius" },
		{ _field_terminator }
	};

	#define STIMULUS_PAYLOAD_BLOCK_STRUCT_ID { 0x627E7586, 0x1A29436A, 0xB5E81C06, 0xB6A3FD65 }
	TAG_BLOCK(
		stimulus_payload_block,
		"stimulus_payload_block",
		1,
		"s_cue_payload_stimulus",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		STIMULUS_PAYLOAD_BLOCK_STRUCT_ID)
	{
		{ _field_string_id, "stimulus type" },
		{ _field_terminator }
	};

	#define COMBAT_CUE_PAYLOAD_BLOCK_STRUCT_ID { 0xC16D563E, 0x80BD4F5A, 0x9E28EAF6, 0x4F1F71C0 }
	TAG_BLOCK(
		combat_cue_payload_block,
		"combat_cue_payload_block",
		1,
		"s_cue_payload_combat_cue",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_WRITEABLE),
		COMBAT_CUE_PAYLOAD_BLOCK_STRUCT_ID)
	{
		{ _field_real_point_3d, "position", FIELD_FLAG_UNKNOWN0 },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 4 },
		{ _field_custom_long_block_index, "packedKeyOffaceref", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_UNKNOWN3 },
		{ _field_custom_long_block_index, "navMeshUIDOffaceref", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_UNKNOWN3 },
		{ _field_word_flags, "flags", FIELD_FLAG_UNKNOWN0, &g_firing_position_flags },
		{ _field_word_flags, "posture flags", FIELD_FLAG_UNKNOWN0, &g_firing_position_posture_flags },

		{ _field_short_block_index, "area", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_INDEX, &areas_block },
		{ _field_short_integer, "cluster index", FIELD_FLAG_UNKNOWN0 },
		{ _field_short_integer, "cluster bsp", FIELD_FLAG_READ_ONLY },
		{ _field_char_integer, "bits and pad", FIELD_FLAG_UNKNOWN0 },
		FIELD_PAD("PAD1", nullptr, FIELD_FLAG_NONE, 1),

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_long_integer, "unknown" },

		{ _field_real_euler_angles_2d, "normal", FIELD_FLAG_UNKNOWN0 },
		{ _field_angle, "facing", FIELD_FLAG_UNKNOWN0 },
		{ _field_long_integer, "lastAbsoluteRejectionGameTime", FIELD_FLAG_UNKNOWN0 },
		{ _field_enum, "preference", &combat_cue_preference_enum },
		FIELD_PAD("post-preference", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	#define AI_CUE_BLOCK_STRUCT_ID { 0x48B57F37, 0xDAD74E23, 0xAFAEB2CC, 0x3A1D25D7 }
	TAG_BLOCK(
		ai_cue_block,
		"ai_cue_block",
		k_max_ai_cues_per_level,
		"s_ai_cue_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_WRITEABLE),
		AI_CUE_BLOCK_STRUCT_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_byte_flags, "flags", &cue_flags },
		{ _field_char_integer, "quick cue", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "editor folder", FIELD_FLAG_UNKNOWN0 },
		{ _field_real_point_3d, "position", FIELD_FLAG_UNKNOWN0 },
		{ _field_custom_long_block_index, "packedKeyOffaceref", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_UNKNOWN3 },
		{ _field_custom_long_block_index, "navMeshUIDOffaceref", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_UNKNOWN3 },
		{ _field_real_euler_angles_2d, "facing (yaw, pitch)", nullptr, "degrees" },
		{ _field_real, "roll" },
		FIELD_CUSTOM("distribution", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_struct, "distribution", &cue_distribution_struct },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		FIELD_CUSTOM("payload", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_struct, "payload", &cue_payload_struct },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		FIELD_PAD("no-cue-definition-index", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_terminator }
	};

	#define TASK_DISTRIBUTION_BLOCK_STRUCT_ID { 0x4A35DA4C, 0x7C8349B7, 0x857A1EE7, 0x216200D6 }
	TAG_BLOCK(
		task_distribution_block,
		"task_distribution_block",
		k_max_task_distributions_per_cue,
		"s_stimulus_distribution_task",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		TASK_DISTRIBUTION_BLOCK_STRUCT_ID)
	{
		{ _field_short_block_index, "objective", &objectives_block },
		{ _field_custom_short_block_index, "task" },
		{ _field_terminator }
	};

	#define RADIAL_DISTRIBUTION_BLOCK_STRUCT_ID { 0xDA5E1767, 0x3784497B, 0x90304D5B, 0x0E716564 }
	TAG_BLOCK(
		radial_distribution_block,
		"radial_distribution_block",
		k_max_radial_distributions_per_cue,
		"s_stimulus_distribution_radial",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		RADIAL_DISTRIBUTION_BLOCK_STRUCT_ID)
	{
		{ _field_real, "radius" },
		{ _field_short_integer, "travel time (ticks)" },
		FIELD_PAD("post-travel-time", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	#define PROBABILITY_DISTRIBUTION_BLOCK_STRUCT_ID { 0x2CC76578, 0x07224D22, 0x82DAF697, 0xAB1327F8 }
	TAG_BLOCK(
		probability_distribution_block,
		"probability_distribution_block",
		k_max_probability_distributions_per_cue,
		"s_stimulus_distribution_probability",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PROBABILITY_DISTRIBUTION_BLOCK_STRUCT_ID)
	{
		{ _field_real, "chance per second" },
		{ _field_terminator }
	};

	#define CHARACTER_DISTRIBUTION_BLOCK_STRUCT_ID { 0xC16F904D, 0x87464DF1, 0xBD91ADC3, 0xEFD9352E }
	TAG_BLOCK(
		character_distribution_block,
		"character_distribution_block",
		k_max_character_distributions_per_cue,
		"s_stimulus_distribution_character",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CHARACTER_DISTRIBUTION_BLOCK_STRUCT_ID)
	{
		{ _field_short_block_index, "character", &character_palette_block },
		{ _field_byte_flags, "flags", &distribution_character_flags },
		FIELD_PAD("post-flags", nullptr, FIELD_FLAG_NONE, 1),
		{ _field_terminator }
	};

	#define WEAPON_DISTRIBUTION_BLOCK_STRUCT_ID { 0xC1DBA160, 0x6F0F42BC, 0xB1DEA6B8, 0x5AA47A6C }
	TAG_BLOCK(
		weapon_distribution_block,
		"weapon_distribution_block",
		k_max_weapon_distributions_per_cue,
		"s_stimulus_distribution_weapon",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		WEAPON_DISTRIBUTION_BLOCK_STRUCT_ID)
	{
		{ _field_short_block_index, "weapon", &scenario_weapon_palette_block },
		FIELD_PAD("post-weapon-palette-index", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	#define SCRIPT_PAYLOAD_BLOCK_STRUCT_ID { 0x38C721BD, 0x8C89406B, 0x84E71F56, 0xB2A70A24 }
	TAG_BLOCK(
		script_payload_block,
		"script_payload_block",
		1,
		"s_cue_payload_script",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCRIPT_PAYLOAD_BLOCK_STRUCT_ID)
	{
		{ _field_string_id, "script function name" },
		{ _field_terminator }
	};

	#define COMBAT_SYNC_ACTION_GROUP_PAYLOAD_BLOCK_STRUCT_ID { 0x0D7C247C, 0xEBDF4F0E, 0x9E7C3D53, 0x4B5E9E51 }
	TAG_BLOCK(
		combat_sync_action_group_payload_block,
		"combat_sync_action_group_payload_block",
		1,
		"s_cue_payload_combat_sync_action",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		COMBAT_SYNC_ACTION_GROUP_PAYLOAD_BLOCK_STRUCT_ID)
	{
		{ _field_string_id, "sync action group name" },
		{ _field_real, "cooldown", "seconds" },
		{ _field_terminator }
	};

	#define AI_FULL_CUE_BLOCK_STRUCT_ID { 0x140AEEEF, 0xDB74495E, 0x9B67740E, 0x0B59FA71 }
	TAG_BLOCK(
		ai_full_cue_block,
		"ai_full_cue_block",
		k_max_ai_cues_per_level,
		"s_ai_cue_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_WRITEABLE),
		AI_FULL_CUE_BLOCK_STRUCT_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_byte_flags, "flags", &cue_flags },
		{ _field_char_integer, "quick cue", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_short_block_index, "editor folder", FIELD_FLAG_UNKNOWN0, &g_scenario_editor_folder_block, _field_id_hide },
		{ _field_real_point_3d, "position" },
		{ _field_custom_long_block_index, "packedKeyOffaceref", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_UNKNOWN3 },
		{ _field_custom_long_block_index, "navMeshUIDOffaceref", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_UNKNOWN3 },
		{ _field_real_euler_angles_2d, "facing", FIELD_FLAG_UNKNOWN0 },
		{ _field_real, "roll", FIELD_FLAG_UNKNOWN0 },
		FIELD_EXPLANATION("Distribution", nullptr, FIELD_FLAG_NONE, "The following blocks describe who will receive this cue."),
		FIELD_CUSTOM("distribution", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_struct, "distribution", &cue_distribution_struct },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		FIELD_EXPLANATION("Payload", nullptr, FIELD_FLAG_NONE, "The following blocks describe the type of stimulus and related payload; you should only specify one."),
		FIELD_CUSTOM("payload", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_struct, "payload", &cue_payload_struct },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		{ _field_long_block_index, "cue definition index", FIELD_FLAG_UNKNOWN0, &ai_cue_block },
		{ _field_terminator }
	};

	#define AI_QUICK_CUE_BLOCK_STRUCT_ID { 0xA141B018, 0xEDC04D19, 0xABF077FB, 0x088C1F73 }
	TAG_BLOCK(
		ai_quick_cue_block,
		"ai_quick_cue_block",
		k_max_ai_cues_per_level,
		"s_ai_quick_cue_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_WRITEABLE),
		AI_QUICK_CUE_BLOCK_STRUCT_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_byte_flags, "flags", &quick_cue_flags },
		FIELD_PAD("post-flags", nullptr, FIELD_FLAG_NONE, 1),
		{ _field_short_block_index, "editor folder", FIELD_FLAG_UNKNOWN0, &g_scenario_editor_folder_block, _field_id_hide },
		{ _field_real_point_3d, "position" },
		{ _field_custom_long_block_index, "packedKeyOffaceref", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_UNKNOWN3 },
		{ _field_custom_long_block_index, "navMeshUIDOffaceref", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_UNKNOWN3 },
		{ _field_real_euler_angles_2d, "facing", FIELD_FLAG_UNKNOWN0 },
		{ _field_real, "roll", FIELD_FLAG_UNKNOWN0 },
		{ _field_block, "tasks", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &task_distribution_block },
		{ _field_short_block_index, "character", &character_palette_block },
		{ _field_short_block_index, "weapon", &scenario_weapon_palette_block },
		{ _field_string_id, "template" },
		{ _field_long_block_index, "cue definition index", FIELD_FLAG_UNKNOWN0, &ai_cue_block },
		{ _field_terminator }
	};

	#define CUE_DISTRIBUTION_STRUCT_ID { 0xA33A8714, 0x99B0463B, 0xB3A517EF, 0x698F20A2 }
	TAG_STRUCT(
		cue_distribution_struct,
		"cue_distribution_struct",
		"s_ai_cue_distribution",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		CUE_DISTRIBUTION_STRUCT_ID)
	{
		{ _field_block, "tasks", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &task_distribution_block },
		{ _field_struct, "distribution", &cue_stimulus_distribution_struct },
		{ _field_terminator }
	};

	#define CUE_STIMULUS_DISTRIBUTION_STRUCT_ID { 0xCBD9EBB5, 0xF4194B72, 0x950D2BF6, 0x26BD4CF9 }
	TAG_STRUCT(
		cue_stimulus_distribution_struct,
		"cue_stimulus_distribution_struct",
		"s_ai_cue_stimulus_distribution",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		CUE_STIMULUS_DISTRIBUTION_STRUCT_ID)
	{
		{ _field_block, "radius", &radial_distribution_block },
		{ _field_block, "probability", &probability_distribution_block },
		{ _field_block, "characters", &character_distribution_block },
		{ _field_block, "weapons", &weapon_distribution_block },
		{ _field_terminator }
	};

	#define CUE_PAYLOAD_STRUCT_ID { 0x26F9B58E, 0x59334FCB, 0x9239438F, 0xB6029B2B }
	TAG_STRUCT(
		cue_payload_struct,
		"cue_payload_struct",
		"s_ai_cue_payload",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		CUE_PAYLOAD_STRUCT_ID)
	{
		{ _field_block, "firing points", &firing_point_payload_block },
		{ _field_block, "script", &script_payload_block },
		{ _field_block, "combat sync action", &combat_sync_action_group_payload_block },
		{ _field_block, "stimulus", &stimulus_payload_block },
		{ _field_block, "combat cue", &combat_cue_payload_block },
		{ _field_terminator }
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

} // namespace macaque

} // namespace blofeld

