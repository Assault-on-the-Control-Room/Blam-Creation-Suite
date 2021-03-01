#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_BLOCK(player_momentum_data_block, k_player_momentum_count)
	{
		{ _field_legacy, _field_byte_flags, "flag", &MomentumFlag },
		{ _field_legacy, _field_pad, "PAD", 3 },
		{ _field_legacy, _field_real, "seconds to start#how long you must be pegged before you gain momentum" },
		{ _field_legacy, _field_real, "seconds to full speed#how long you must have momentum before you reach top speed" },
		{ _field_legacy, _field_real, "decay rate#how fast being unpegged decays the timer (seconds per second)" },
		{ _field_legacy, _field_real, "full speed multiplier#how much faster we actually go when at full momentum" },
		{ _field_legacy, _field_real, "sprint turn multiplier#how much faster to turn when sprinting" },
		    
		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_legacy, _field_real, "pegged magnitude#how far the stick needs to be pressed before being considered pegged" },
		{ _field_legacy, _field_real, "pegged angular threshold#how far off straight up (in degrees) we consider pegged" },

		{ _field_legacy, _field_angle, "max look yaw velocity:degrees per second" },
		{ _field_legacy, _field_angle, "max look pitch velocity:degrees per second" },
		{ _field_legacy, _field_real, "minimum player velocity to be considered in a momentum state:world units per second" },
		{ _field_legacy, _field_real, "look window length:seconds#period of time over which we record the biped\'s look angle for deciding if we should drop him out of momentum" },
		{ _field_legacy, _field_string_id, "momentum animation stance" },
		
		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_legacy, _field_real, "min weapon error#[0, 1] while using this type of momentum, the player\'s weapon error cannot drop below this value" },

		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(player_information_block, k_player_character_type_count)
	{
		{ _field_legacy, _field_real, "walking speed:world units per second" },
		{ _field_legacy, _field_real, "run forward:world units per second" },
		{ _field_legacy, _field_real, "run backward:world units per second" },
		{ _field_legacy, _field_real, "run sideways:world units per second" },
		{ _field_legacy, _field_real, "run acceleration:world units per second squared" },
		{ _field_legacy, _field_real, "sneak forward:world units per second" },
		{ _field_legacy, _field_real, "sneak backward:world units per second" },
		{ _field_legacy, _field_real, "sneak sideways:world units per second" },
		{ _field_legacy, _field_real, "sneak acceleration:world units per second squared" },
		{ _field_legacy, _field_real, "airborne acceleration:world units per second squared" },
		
		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_legacy, _field_real, "weapon ready anim scaler" },

		{ _field_legacy, _field_real_point_3d, "grenade origin" },
		{ _field_legacy, _field_struct, "grenade aiming#determines the distance along the aiming vector to orient the grenade based on the camera pitch", &scalar_function_named_struct_struct_definition },
		{ _field_legacy, _field_real_bounds, "first person idle time:seconds" },
		{ _field_legacy, _field_real_fraction, "first person skip fraction:[0,1]" },
		{ _field_legacy, _field_tag_reference, "coop countdown sound", &global_sound_reference },
		{ _field_legacy, _field_tag_reference, "coop respawn sound", &global_sound_reference },
		{ _field_legacy, _field_tag_reference, "coop respawn effect", &global_effect_reference },
		{ _field_legacy, _field_tag_reference, "hologram death effect", &global_effect_reference },
		{ _field_legacy, _field_long_integer, "binoculars zoom count" },
		{ _field_legacy, _field_real_bounds, "binoculars zoom range" },
		{ _field_legacy, _field_tag_reference, "night vision on{flashlight on}", &global_sound_reference },
		{ _field_legacy, _field_tag_reference, "night vision off{flashlight off}", &global_sound_reference },
		
		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 3 },
		{ _field_legacy, _field_real, "fire team objective range" },
		{ _field_legacy, _field_real, "fire team sandbox range" },
		{ _field_legacy, _field_real, "fire team cone angle: in degrees" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_legacy, _field_explanation, "sprinting/momentum", "" },
		{ _field_legacy, _field_block, "momentum and sprinting", &player_momentum_data_block_block },
		
		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 3 },
		{ _field_legacy, _field_long_integer, "unknown@" },
		{ _field_legacy, _field_long_integer, "unknown@" },
		{ _field_legacy, _field_struct, "momentum and sprinting", &player_momentum_data_block_block_struct }, // H4 moved to a tagblock

		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(firstPersonpHiddenBodyRegionsBlock, 32)
	{
		{ _field_legacy, _field_string_id, "hidden region^" },
		{ _field_legacy, _field_byte_flags, "flags", &FpBodyRegionFlags },
		{ _field_legacy, _field_pad, "pad", 3 },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(player_representation_block, k_player_character_type_count)
	{
		{ _field_legacy, _field_byte_flags, "flags", &player_representation_flags },
		{ _field_legacy, _field_pad, "pad", 3 },
		{ _field_legacy, _field_tag_reference, "hud screen reference", &Tag::Reference<struct CuiScreenDefinition>::s_defaultDefinition },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_legacy, _field_tag_reference, "first person hands model", &model_reference$4 },
		{ _field_legacy, _field_string_id, "first person multiplayer hands variant" },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_tag_reference, "first person hands model", &render_model_reference },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 3 },
		{ _field_legacy, _field_tag_reference, "first person body model", &model_reference$4 },
		{ _field_legacy, _field_string_id, "first person multiplayer body variant" },
		{ _field_legacy, _field_block, "hidden fpBody regions", &firstPersonpHiddenBodyRegionsBlock_block },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_tag_reference, "first person body model", &render_model_reference },

		{ _field_legacy, _field_tag_reference, "third person unit", &unit_reference$3 },
		{ _field_legacy, _field_string_id, "third person variant" },
		{ _field_legacy, _field_tag_reference, "binoculars zoom in sound", &global_sound_reference },
		{ _field_legacy, _field_tag_reference, "binoculars zoom out sounds", &global_sound_reference },
		{ _field_legacy, _field_long_block_index, "player information" },
		{ _field_legacy, _field_terminator }
	};

	STRINGS(MomentumFlag)
	{
		"disable soft ping check",
		"disable hard ping check"
	};
	STRING_LIST(MomentumFlag, MomentumFlag_strings, _countof(MomentumFlag_strings));

	STRINGS(player_representation_flags)
	{
		"can use health packs"
	};
	STRING_LIST(player_representation_flags, player_representation_flags_strings, _countof(player_representation_flags_strings));

	STRINGS(FpBodyRegionFlags)
	{
		"visible in ICS"
	};
	STRING_LIST(FpBodyRegionFlags, FpBodyRegionFlags_strings, _countof(FpBodyRegionFlags_strings));

} // namespace blofeld

