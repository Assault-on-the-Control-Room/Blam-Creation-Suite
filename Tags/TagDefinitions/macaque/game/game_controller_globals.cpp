#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define GAMEPAD_STICK_INFO_BLOCK_ID { 0xD3417406, 0xF47E4B5F, 0x953C7C15, 0xD364BEAB }
	TAG_BLOCK(
		gamepad_stick_info_block,
		"gamepad_stick_info_block",
		1,
		"s_gamepad_stick_settings",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		GAMEPAD_STICK_INFO_BLOCK_ID)
	{
		{ _field_char_enum, "input shape", &input_mapping_shape_enum },
		FIELD_PAD("F", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_real_fraction, "peg threshold", "magnitude of analog input for pegged acceleration to kick in" },
		{ _field_real_point_2d, "pegged time", "time for a pegged look to reach maximum effect" },
		{ _field_real_point_2d, "pegged scale", "the maximum effect achieved over the duration of the pegged time." },
		{ _field_angle, "peg max angular velocity", "the maximum turning speed during peg", "degrees per sec" },
		{ _field_block, "input mapping function", &input_mapping_function_block },
		{ _field_terminator }
	};

	#define INPUT_MAPPING_FUNCTION_BLOCK_ID { 0xAAEEBF63, 0x6AA04553, 0xA5DAA31B, 0x60373717 }
	TAG_BLOCK(
		input_mapping_function_block,
		"input_mapping_function_block",
		1,
		"c_function_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		INPUT_MAPPING_FUNCTION_BLOCK_ID)
	{
		{ _field_struct, "function", &scalar_function_named_struct },
		{ _field_terminator }
	};

	#define CONTROLLER_INPUT_BLOCK_ID { 0x056079C5, 0xBD194D1C, 0xB7544182, 0xD8A4D2AD }
	TAG_BLOCK(
		controller_input_block,
		"controller_input_block",
		1,
		"s_game_globals_input_abstraction",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CONTROLLER_INPUT_BLOCK_ID)
	{
		{ _field_real, "axial dead zone" },
		{ _field_real, "radial dead zone" },
		{ _field_terminator }
	};

	#define PLAYER_CONTROL_BLOCK_ID { 0xAFAD7414, 0x08FE4A96, 0x94E4BCF6, 0x39C2EEFC }
	TAG_BLOCK(
		player_control_block,
		"player_control_block",
		1,
		"s_game_globals_player_control",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		PLAYER_CONTROL_BLOCK_ID)
	{
		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_block, "controller button mappings", &controller_mapping_reference_block },

		{ _field_block, "move stick info", &gamepad_stick_info_block },
		{ _field_block, "look stick info", &gamepad_stick_info_block },
		{ _field_real_fraction, "magnetism friction", "how much the crosshair slows over enemies" },
		{ _field_real_fraction, "magnetism adhesion", "how much the crosshair sticks to enemies" },
		{ _field_real_fraction, "inconsequential target scale", "scales magnetism level for inconsequential targets like infection forms" },
		FIELD_EXPLANATION("crosshair", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real_point_2d, "crosshair location", "-1..1, 0 is middle of the screen" },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 2 },
		{ _field_legacy, _field_real, "unknown@" },
		{ _field_legacy, _field_real, "unknown@" },

		FIELD_EXPLANATION("fireteam", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real, "fireteam command mode duration", "How long is command mode on after you initially attempt to issue an order", "seconds" },
		FIELD_EXPLANATION("looking", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real, "look autolevelling scale", "1 is fast, 0 is none, >1 will probably be really fast" },
		{ _field_real, "gravity_scale" },
		FIELD_PAD("VM", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_short_integer, "minimum autolevelling ticks", "amount of time player needs to move and not look up or down for autolevelling to kick in" },
		{ _field_angle, "minimum angle for vehicle flipping", "0 means the vehicle's up vector is along the ground, 90 means the up vector is pointing straight up:degrees" },
		FIELD_EXPLANATION("weapons may optionally be set to require extra button hold time (e.g. ordnance power weapon drops)", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real, "minimum action hold time", "time that player needs to press ACTION to register as a HOLD", "seconds" },
		{ _field_real, "minimum action hold time for teammates", "teammates of player who dropped/spawned weapon", "seconds" },
		{ _field_real, "minimum action hold time for opponents", "opponents of player who dropped/spawned weapon", "seconds" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_real, "pegged zoom supression threshold", "for spinny-shotgun goodness" },

		FIELD_EXPLANATION("double/triple jump", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real, "minimum vertical velocity", nullptr, "wu/s" },
		{ _field_real, "cooldown time", nullptr, "seconds" },
		{ _field_real_vector_2d, "double jump velocity", nullptr, "horizontal, vertical" },
		{ _field_real_vector_2d, "triple jump velocity", nullptr, "aiming, vertical" },
		FIELD_EXPLANATION("stick throws", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real, "throw channel width", "how close to an axis you have to be" },
		{ _field_real, "throw peg threshold", "how far from the center you have to be" },
		{ _field_real, "throw centered min time", "how long the stick must be centered to start a throw", "s" },
		{ _field_real, "throw drawing max time", "how long you can take to become pegged at the start of a throw", "s" },
		{ _field_real, "throw drawn max time", "how long you can stay pegged at the start of a throw", "s" },
		{ _field_real, "throw throwing max time", "how long you can take to throw the stick to pegged on the other side", "s" },
		{ _field_real, "flick peg jump max time", "max time you can be pegged and then press jump to activate", "s" },
		{ _field_real, "double tap interval time", "to engage double-tap, user must press jump twice in this much time", "s" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 55 },
		FIELD_EXPLANATION("Jump Assist", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real, "vault_speed_gain" },
		{ _field_real, "vaultSprint_speed_gain" },
		{ _field_real, "vault_height_high" },
		{ _field_real, "vaultSprint_height_high" },
		{ _field_real, "vault_height_medium" },
		{ _field_real, "vaultSprint_height_medium" },
		{ _field_real, "vault_height_min" },
		{ _field_real, "vaultSprint_height_min" },
		{ _field_real, "vault_height_traverse" },
		{ _field_real, "vaultSprint_height_traverse" },
		{ _field_real, "vault_max_downward_distance" },
		{ _field_real, "vaultSprint_max_downward_distance" },
		{ _field_real, "vault_max_distance" },
		{ _field_real, "vaultSprint_max_distance" },
		{ _field_real, "vault_gravity_gain" },
		{ _field_real, "vaultSprint_gravity_gain" },
		{ _field_real, "vault_stationary_probe_distance" },
		{ _field_real, "vault_stationary_probe_angle" },
		{ _field_real, "vault_stationary_probe_min_z" },
		{ _field_real, "vault_lateral_speed_gain" },
		{ _field_real, "vaultSprint_lateral_speed_gain" },
		{ _field_real, "jump_air_control_gain" },
		{ _field_real, "jump_forward_horizontal_speed_0" },
		{ _field_real, "jump_forward_horizontal_speed_1" },
		{ _field_real, "jump_forward_horizontal_speed_2" },
		{ _field_real, "jump_forward_gravity_0" },
		{ _field_real, "jump_forward_gravity_1" },
		{ _field_real, "jump_forward_gravity_2" },
		{ _field_real, "jump_forward_height" },
		{ _field_real, "jump_lateral_horizontal_speed_0" },
		{ _field_real, "jump_lateral_horizontal_speed_1" },
		{ _field_real, "jump_lateral_horizontal_speed_2" },
		{ _field_real, "jump_lateral_gravity_0" },
		{ _field_real, "jump_lateral_gravity_1" },
		{ _field_real, "jump_lateral_gravity_2" },
		{ _field_real, "jump_lateral_height" },
		{ _field_real, "jump_reverse_horizontal_speed_0" },
		{ _field_real, "jump_reverse_horizontal_speed_1" },
		{ _field_real, "jump_reverse_horizontal_speed_2" },
		{ _field_real, "jump_reverse_gravity_0" },
		{ _field_real, "jump_reverse_gravity_1" },
		{ _field_real, "jump_reverse_gravity_2" },
		{ _field_real, "jump_reverse_height" },
		{ _field_real, "jump_stationary_horizontal_speed_0" },
		{ _field_real, "jump_stationary_horizontal_speed_1" },
		{ _field_real, "jump_stationary_horizontal_speed_2" },
		{ _field_real, "jump_stationary_gravity_0" },
		{ _field_real, "jump_stationary_gravity_1" },
		{ _field_real, "jump_stationary_gravity_2" },
		{ _field_real, "jump_stationary_height" },
		{ _field_real, "Downward_Vault_Min_Laterial_Distance" },
		{ _field_real, "Vault_AutoCorrect_MaxAngle" },
		{ _field_real, "Vault ideal distance", "When several via vault targets are found, vaults closer to this distance are more likely to be chosen" },
		{ _field_real, "Vault Sprint ideal distance", "When several via vault targets are found, vaults closer to this distance are more likely to be chosen" },

		{ _field_terminator }
	};

	#define CONTROLLER_MAPPING_REFERENCE_BLOCK_ID { 0x6D1C4D66, 0x921C4C4E, 0xB2A0F6C3, 0xEC6AACBF }
	TAG_BLOCK(
		controller_mapping_reference_block,
		"controller_mapping_reference_block",
		k_button_presets_count,
		"s_controller_mapping_reference",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CONTROLLER_MAPPING_REFERENCE_BLOCK_ID)
	{
		{ _field_tag_reference, "mapping", &global_controller_mapping_reference },
		{ _field_terminator }
	};

	STRINGS(input_mapping_shape_enum)
	{
		"none",
		"unit_circle",
		"unit_square"
	};
	STRING_LIST(input_mapping_shape_enum, input_mapping_shape_enum_strings, _countof(input_mapping_shape_enum_strings));

} // namespace macaque

} // namespace blofeld

