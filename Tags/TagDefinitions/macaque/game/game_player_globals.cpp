#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define PLAYER_INFORMATION_BLOCK_ID { 0x45AF4745, 0x4D24477D, 0xA205702C, 0xE5CAEBE7 }
	TAG_BLOCK(
		player_information_block,
		"player_information_block",
		k_player_character_type_count,
		"s_game_globals_player_information",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		PLAYER_INFORMATION_BLOCK_ID)
	{
		{ _field_real, "walking speed", nullptr, "world units per second" },
		{ _field_real, "run forward", nullptr, "world units per second" },
		{ _field_real, "run backward", nullptr, "world units per second" },
		{ _field_real, "run sideways", nullptr, "world units per second" },
		{ _field_real, "run acceleration", nullptr, "world units per second squared" },
		{ _field_real, "sneak forward", nullptr, "world units per second" },
		{ _field_real, "sneak backward", nullptr, "world units per second" },
		{ _field_real, "sneak sideways", nullptr, "world units per second" },
		{ _field_real, "sneak acceleration", nullptr, "world units per second squared" },
		{ _field_real, "airborne acceleration", nullptr, "world units per second squared" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_real, "weapon ready anim scaler" },

		{ _field_real_point_3d, "grenade origin" },
		{ _field_struct, "grenade aiming", "determines the distance along the aiming vector to orient the grenade based on the camera pitch", &scalar_function_named_struct },
		{ _field_real_bounds, "first person idle time", nullptr, "seconds" },
		{ _field_real_fraction, "first person skip fraction", nullptr, nullptr, "[0,1]" },
		{ _field_tag_reference, "coop countdown sound", &global_sound_reference },
		{ _field_tag_reference, "coop respawn sound", &global_sound_reference },
		{ _field_tag_reference, "coop respawn effect", &global_effect_reference },
		{ _field_tag_reference, "hologram death effect", &global_effect_reference },
		{ _field_long_integer, "binoculars zoom count" },
		{ _field_real_bounds, "binoculars zoom range" },
		{ _field_tag_reference, "night vision on", MAKE_OLD_NAMES("flashlight on"), &global_sound_reference },
		{ _field_tag_reference, "night vision off", MAKE_OLD_NAMES("flashlight off"), &global_sound_reference },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 3 },
		{ _field_real, "fire team objective range" },
		{ _field_real, "fire team sandbox range" },
		{ _field_real, "fire team cone angle", nullptr, "in degrees" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		FIELD_EXPLANATION("sprinting/momentum", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_block, "momentum and sprinting", &player_momentum_data_block },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 3 },
		{ _field_legacy, _field_long_integer, "unknown@" },
		{ _field_legacy, _field_long_integer, "unknown@" },
		{ _field_struct, "momentum and sprinting", &player_momentum_data_block_struct_definition }, // // H4 moved this into a tagblock

		{ _field_terminator }
	};

	#define PLAYER_MOMENTUM_DATA_BLOCK_ID { 0x7AA5B02F, 0x50D74B18, 0x892AD20A, 0x2B334390 }
	TAG_BLOCK(
		player_momentum_data_block,
		"player_momentum_data_block",
		k_player_momentum_count,
		"s_game_globals_player_momentum_data",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PLAYER_MOMENTUM_DATA_BLOCK_ID)
	{
		{ _field_byte_flags, "flag", &MomentumFlag },
		FIELD_PAD("PAD", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_real, "seconds to start", "how long you must be pegged before you gain momentum" },
		{ _field_real, "seconds to full speed", "how long you must have momentum before you reach top speed" },
		{ _field_real, "decay rate", "how fast being unpegged decays the timer (seconds per second)" },
		{ _field_real, "full speed multiplier", "how much faster we actually go when at full momentum" },
		{ _field_real, "sprint turn multiplier", "how much faster to turn when sprinting" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_real, "pegged magnitude", "how far the stick needs to be pressed before being considered pegged" },
		{ _field_real, "pegged angular threshold", "how far off straight up (in degrees) we consider pegged" },

		{ _field_angle, "max look yaw velocity", nullptr, "degrees per second" },
		{ _field_angle, "max look pitch velocity", nullptr, "degrees per second" },
		{ _field_real, "minimum player velocity to be considered in a momentum state", nullptr, "world units per second" },
		{ _field_real, "look window length", "period of time over which we record the biped's look angle for deciding if we should drop him out of momentum", "seconds" },
		{ _field_string_id, "momentum animation stance" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_real, "min weapon error", "[0, 1] while using this type of momentum, the player's weapon error cannot drop below this value" },

		{ _field_terminator }
	};

	#define PLAYER_REPRESENTATION_BLOCK_ID { 0x4F35E23A, 0xFACB43D1, 0x90C6D726, 0x49C496B7 }
	TAG_BLOCK(
		player_representation_block,
		"player_representation_block",
		k_player_character_type_count,
		"s_game_globals_player_representation",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		PLAYER_REPRESENTATION_BLOCK_ID)
	{
		{ _field_byte_flags, "flags", &player_representation_flags },
		FIELD_PAD("pad", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_tag_reference, "hud screen reference", &Tag::Reference<struct CuiScreenDefinition>::s_defaultDefinition },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_tag_reference, "first person hands model", &model_reference$4 },
		{ _field_string_id, "first person multiplayer hands variant" },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_tag_reference, "first person hands model", &model_reference$4 },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 3 },
		{ _field_tag_reference, "first person body model", &model_reference$4 },
		{ _field_string_id, "first person multiplayer body variant" },
		{ _field_block, "hidden fpBody regions", &firstPersonpHiddenBodyRegionsBlock_block },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_tag_reference, "first person body model", &model_reference$4 },

		{ _field_tag_reference, "third person unit", &unit_reference$3 },
		{ _field_string_id, "third person variant" },
		{ _field_tag_reference, "binoculars zoom in sound", &global_sound_reference },
		{ _field_tag_reference, "binoculars zoom out sounds", &global_sound_reference },
		{ _field_long_block_index, "player information", &player_information_block },
		{ _field_terminator }
	};

	#define FIRSTPERSONPHIDDENBODYREGIONSBLOCK_ID { 0xB6C7F81F, 0x2D744D11, 0x9CA9B38F, 0x50F32BC5 }
	TAG_BLOCK(
		firstPersonpHiddenBodyRegionsBlock_block,
		"firstPersonpHiddenBodyRegionsBlock",
		32,
		"FirstPersonHiddenBodyRegion",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		FIRSTPERSONPHIDDENBODYREGIONSBLOCK_ID)
	{
		{ _field_string_id, "hidden region", FIELD_FLAG_INDEX },
		{ _field_byte_flags, "flags", &FpBodyRegionFlags },
		FIELD_PAD("pad", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_terminator }
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

} // namespace macaque

} // namespace blofeld

