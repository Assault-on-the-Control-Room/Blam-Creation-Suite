#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_BLOCK(input_mapping_function_block, 1)
	{
		{ _field_struct, "function", &scalar_function_named_struct_struct_definition },
		{ _field_terminator }
	};

	TAG_BLOCK(gamepad_stick_info_block, 1)
	{
		{ _field_char_enum, "input shape", &input_mapping_shape_enum },
		{ _field_pad, "F", 3 },
		{ _field_real_fraction, "peg threshold [0,1]#magnitude of analog input for pegged acceleration to kick in" },
		{ _field_real_point_2d, "pegged time#time for a pegged look to reach maximum effect" },
		{ _field_real_point_2d, "pegged scale#the maximum effect achieved over the duration of the pegged time." },
		{ _field_angle, "peg max angular velocity:degrees per sec#the maximum turning speed during peg" },
		{ _field_block, "input mapping function", &input_mapping_function_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(controller_input_block, 1)
	{
		{ _field_real, "axial dead zone" },
		{ _field_real, "radial dead zone" },
		{ _field_terminator }
	};

	TAG_BLOCK(controller_mapping_reference_block, k_button_presets_count)
	{
		{ _field_tag_reference, "mapping", &global_controller_mapping_reference },
		{ _field_terminator }
	};

	TAG_BLOCK(player_control_block, 1)
	{
		{ _field_version_greater, _engine_type_haloreach, 1 },
		{ _field_block, "controller button mappings", &controller_mapping_reference_block_block },

		{ _field_block, "move stick info", &gamepad_stick_info_block_block },
		{ _field_block, "look stick info", &gamepad_stick_info_block_block },
		{ _field_real_fraction, "magnetism friction#how much the crosshair slows over enemies" },
		{ _field_real_fraction, "magnetism adhesion#how much the crosshair sticks to enemies" },
		{ _field_real_fraction, "inconsequential target scale#scales magnetism level for inconsequential targets like infection forms" },
		{ _field_explanation, "crosshair", "" },
		{ _field_real_point_2d, "crosshair location#-1..1, 0 is middle of the screen" },
		
		{ _field_version_less_or_equal, _engine_type_haloreach, 2 },
		{ _field_real, "unknown@" },
		{ _field_real, "unknown@" },

		{ _field_explanation, "fireteam", "" },
		{ _field_real, "fireteam command mode duration:seconds#How long is command mode on after you initially attempt to issue an order" },
		{ _field_explanation, "looking", "" },
		{ _field_real, "look autolevelling scale#1 is fast, 0 is none, >1 will probably be really fast" },
		{ _field_real, "gravity_scale" },
		{ _field_pad, "VM", 2 },
		{ _field_short_integer, "minimum autolevelling ticks#amount of time player needs to move and not look up or down for autolevelling to kick in" },
		{ _field_angle, "minimum angle for vehicle flipping#0 means the vehicle\'s up vector is along the ground, 90 means the up vector is pointing straight up:degrees" },
		{ _field_explanation, "weapons may optionally be set to require extra button hold time (e.g. ordnance power weapon drops)", "" },
		{ _field_real, "minimum action hold time:seconds#time that player needs to press ACTION to register as a HOLD" },
		{ _field_real, "minimum action hold time for teammates:seconds#teammates of player who dropped/spawned weapon" },
		{ _field_real, "minimum action hold time for opponents:seconds#opponents of player who dropped/spawned weapon" },
		
		{ _field_version_greater, _engine_type_haloreach, 1 },
		{ _field_real, "pegged zoom supression threshold#for spinny-shotgun goodness" },
		
		{ _field_explanation, "double/triple jump", "" },
		{ _field_real, "minimum vertical velocity:wu/s" },
		{ _field_real, "cooldown time:seconds" },
		{ _field_real_vector_2d, "double jump velocity:horizontal, vertical" },
		{ _field_real_vector_2d, "triple jump velocity:aiming, vertical" },
		{ _field_explanation, "stick throws", "" },
		{ _field_real, "throw channel width#how close to an axis you have to be" },
		{ _field_real, "throw peg threshold#how far from the center you have to be" },
		{ _field_real, "throw centered min time:s#how long the stick must be centered to start a throw" },
		{ _field_real, "throw drawing max time:s#how long you can take to become pegged at the start of a throw" },
		{ _field_real, "throw drawn max time:s#how long you can stay pegged at the start of a throw" },
		{ _field_real, "throw throwing max time:s#how long you can take to throw the stick to pegged on the other side" },
		{ _field_real, "flick peg jump max time:s#max time you can be pegged and then press jump to activate" },
		{ _field_real, "double tap interval time:s#to engage double-tap, user must press jump twice in this much time" },
		{ _field_explanation, "Jump Assist", "" },

		{ _field_version_greater, _engine_type_haloreach, 54 },
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
		{ _field_real, "Vault ideal distance#When several via vault targets are found, vaults closer to this distance are more likely to be chosen" },
		{ _field_real, "Vault Sprint ideal distance#When several via vault targets are found, vaults closer to this distance are more likely to be chosen" },
		
		{ _field_terminator }
	};

	STRINGS(input_mapping_shape_enum)
	{
		"none",
		"unit_circle",
		"unit_square"
	};
	STRING_LIST(input_mapping_shape_enum, input_mapping_shape_enum_strings, _countof(input_mapping_shape_enum_strings));

} // namespace blofeld

