#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		unit_group,
		UNIT_TAG,
		&object_group,
		OBJECT_TAG,
		unit_block );

	TAG_BLOCK_FROM_STRUCT(
		unit_block,
		"unit_block",
		1,
		unit_struct_definition);

	#define UNIT_SCREEN_EFFECT_BLOCK_ID { 0xCF227E5C, 0xEA87405B, 0x8FC0CED4, 0x4AA6446C }
	TAG_BLOCK(
		unit_screen_effect_block,
		"unit_screen_effect_block",
		4,
		"s_unit_screen_effect_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		UNIT_SCREEN_EFFECT_BLOCK_ID)
	{
		{ _field_tag_reference, "screen effect", FIELD_FLAG_INDEX, &global_area_screen_effect_reference },
		{ _field_terminator }
	};

	#define UNIT_CAMERA_TRACK_BLOCK_ID { 0x7C803867, 0x535E45B7, 0x81C122B6, 0xD6F2CAFC }
	TAG_BLOCK(
		unit_camera_track_block,
		"unit_camera_track_block",
		MAXIMUM_NUMBER_OF_UNIT_CAMERA_TRACKS,
		"s_unit_camera_track",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		UNIT_CAMERA_TRACK_BLOCK_ID)
	{
		{ _field_tag_reference, "track", &global_camera_track_reference },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_tag_reference, "screen effect", &global_area_screen_effect_reference },
		{ _field_terminator }
	};

	#define UNIT_CAMERA_ACCELERATION_DISPLACEMENT_BLOCK_ID { 0x23D5C530, 0x05A548F3, 0x80168453, 0x80F5F3F1 }
	TAG_BLOCK(
		unit_camera_acceleration_displacement_block,
		"unit_camera_acceleration_displacement_block",
		1,
		"s_unit_camera_acceleration",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		UNIT_CAMERA_ACCELERATION_DISPLACEMENT_BLOCK_ID)
	{
		{ _field_real, "maximum camera velocity", "how quickly the camera can move to a new displacement (if the velocity suddenly changes).\nDuring this time the aim vector for the unit will be inaccurate, so don't set this too low.\n0 defaults to infinite.", "wu/s" },
		FIELD_EXPLANATION(nullptr, nullptr, FIELD_FLAG_NONE, "For each of the following functions, if 1 instance of the block is specified, the offsets are symmetric.\nIf 2 instances are specified, then the first instance is used for positive displacement and the second is used for negative displacement."),
		{ _field_struct, "forward/back", &unit_camera_acceleration_displacement_function_struct },
		{ _field_struct, "left/right", &unit_camera_acceleration_displacement_function_struct },
		{ _field_struct, "up/down", &unit_camera_acceleration_displacement_function_struct },
		{ _field_terminator }
	};

	#define WEAPONSPECIFICMARKERSBLOCK_ID { 0x6EDCC4BF, 0x9740432D, 0x85F0E1C2, 0x1CA4087B }
	TAG_BLOCK(
		WeaponSpecificMarkersBlock_block,
		"WeaponSpecificMarkersBlock",
		WEAPON_SPECIFIC_MARKERS_COUNT,
		"WeaponSpecificMarkers",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		WEAPONSPECIFICMARKERSBLOCK_ID)
	{
		{ _field_string_id, "complete weapon name", FIELD_FLAG_INDEX },
		{ _field_string_id, "weapon class" },
		{ _field_string_id, "weapon name" },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_marker),
		{ _field_string_id, "right hand marker" },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_marker),
		{ _field_string_id, "left hand marker" },
		{ _field_terminator }
	};

	#define UNIT_POSTURES_BLOCK_ID { 0xAE9EA3B9, 0x5AAA4959, 0xAA7D53AA, 0x08A60FB7 }
	TAG_BLOCK(
		unit_postures_block,
		"unit_postures_block",
		MAXIMUM_POSTURES_PER_UNIT,
		"s_posture_definition",
		SET_UNKNOWN0 | SET_UNKNOWN4 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		UNIT_POSTURES_BLOCK_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_useless_pad, "" },
		{ _field_real_vector_3d, "pill offset" },
		{ _field_terminator }
	};

	#define DIALOGUE_VARIANT_BLOCK_ID { 0xC954BD46, 0x4A9C4A98, 0xAC562A99, 0x9AE5A33F }
	TAG_BLOCK(
		dialogue_variant_block,
		"dialogue_variant_block",
		MAXIMUM_DIALOGUE_VARIANTS_PER_UNIT,
		"dialogue_variant_definition",
		SET_UNKNOWN0 | SET_UNKNOWN4 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		DIALOGUE_VARIANT_BLOCK_ID)
	{
		{ _field_short_integer, "variant number", "variant number to use this dialogue with (must match the suffix in the permutations on the unit's model)" },
		FIELD_PAD("BQCVEMF", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_useless_pad, "" },
		{ _field_tag_reference, "dialogue", &dialogue_reference },
		{ _field_terminator }
	};

	#define POWERED_SEAT_BLOCK_ID { 0x26FB2A20, 0x2F5946C9, 0x912DAE92, 0xEC1BCBB6 }
	TAG_BLOCK(
		powered_seat_block,
		"powered_seat_block",
		k_powered_seats_count,
		"powered_seat_definition",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		POWERED_SEAT_BLOCK_ID)
	{
		{ _field_real, "driver powerup time", nullptr, "seconds" },
		{ _field_real, "driver powerdown time", nullptr, "seconds" },
		{ _field_terminator }
	};

	#define UNIT_WEAPON_BLOCK_STRUCT_ID { 0x2B5DC512, 0x14364A80, 0x855CD54E, 0xDCE951E0 }
	TAG_BLOCK(
		unit_weapon_block,
		"unit_weapon_block",
		MAXIMUM_INITIAL_WEAPONS_PER_UNIT,
		"unit_initial_weapon",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		UNIT_WEAPON_BLOCK_STRUCT_ID)
	{
		{ _field_tag_reference, "weapon", FIELD_FLAG_INDEX, &weapon_reference },

		{ _field_legacy, _field_version_greater, _engine_type_halo3 },
		{ _field_string_id, "variant name" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 32 },
		{ _field_long_enum, "position", &initial_weapon_position },
		{ _field_real, "maximum firing cone angle", "must be greater than zero for turret to fire", "degrees" },
		{ _field_real, "minimum retarget time", "minimum time before autoturret will change targets", "seconds" },
		{ _field_real, "blind fire time", "time after losing a target before turret stops blind firing", "seconds" },
		{ _field_real, "lead fraction", "0.0 = no lead, 1.0 = perfect lead" },
		{ _field_real_bounds, "engagement range", "when non-zero, turret will not prioritize targets above or below this range", "units" },
		{ _field_real, "proximity score multiplier", "0.0 = no importance, 2.0 = things that are close are twice as important" },
		{ _field_real, "direction score multiplier", "0.0 = no importance, 2.0 = things in front of you are twice as important" },
		{ _field_real, "attacker score multiplier", "0.0 = no importance, 2.0 = things that attacked you last are twice as important" },
		{ _field_real, "targeting weight hologram", "multiplier" },
		{ _field_real, "targeting weight auto turret", "multiplier" },
		{ _field_real, "primary fire delay from idle", nullptr, "seconds" },
		{ _field_real, "secondary fire delay from idle", nullptr, "seconds" },
		{ _field_real, "caution duration", "how long the turret stays alert after losing a target", "seconds" },
		{ _field_real, "alert angular speed max", "0 = infinite", "radians per second" },
		{ _field_real, "idle angular speed max", "0 = infinite", "radians per second" },
		{ _field_real, "targeting yaw min", "(-180 to 0) how far it can rotate past its initial rotation", "degrees" },
		{ _field_real, "targeting yaw max", "(0 to 180) how far it can rotate past its initial rotation", "degrees" },
		{ _field_real, "targeting pitch min", "(-180 to 0) how far it can rotate past its initial rotation", "degrees" },
		{ _field_real, "targeting pitch max", "(0 to 180) how far it can rotate past its initial rotation", "degrees" },
		{ _field_real, "idle scanning yaw min", "(-180 to 0) how far it will look around past its initial rotation", "degrees" },
		{ _field_real, "idle scanning yaw max", "(0 to 180) how far it will look around past its initial rotation", "degrees" },
		{ _field_real, "idle scanning pitch min", "(-180 to 0) how far it will look around past its initial rotation", "degrees" },
		{ _field_real, "idle scanning pitch max", "(0 to 180) how far it will look around past its initial rotation", "degrees" },
		{ _field_real, "idle scanning min interest distance", "0 = infinite.  Idle scanning won't look at something that is closer than this distance", "world units" },
		{ _field_tag_reference, "alert mode effect", "effect played on the turret when it goes into alert mode", &global_effect_reference },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_marker),
		{ _field_string_id, "alert mode effect marker" },
		{ _field_string_id, "alert mode effect primary scale" },
		{ _field_string_id, "alert mode effect secondary scale" },
		{ _field_block, "sentry properties", &SentryPropertiesBlock_block },
		{ _field_real, "target camouflage threshold", "0 - 1 : target when players camo level falls below this threshold, full camo = 1" },

		{ _field_terminator }
	};

	#define SENTRYPROPERTIESBLOCK_ID { 0x219B49E2, 0x77D04F5E, 0xB773D8E3, 0x249343D6 }
	TAG_BLOCK(
		SentryPropertiesBlock_block,
		"SentryPropertiesBlock",
		1,
		"SentryProperties",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SENTRYPROPERTIESBLOCK_ID)
	{
		{ _field_byte_flags, "behavior", &sentryTurretBehaviorFlagDefinition },
		FIELD_PAD("flagPad", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_real, "sight cone angle", "the cone that this sentry actually sees with; only used when scanning", "degrees" },
		{ _field_real, "alert range", "how far the sentry can see (sentry will track enemies within alert range, but not necessarily fire)", "world units" },
		{ _field_real, "attack range", "how far the sentry can shoot", "world units" },
		{ _field_real, "attack range score multiplier", "0 = No preference to targets in attack range; 0.5 = Targets in attack range get 50% score bonus" },
		{ _field_real, "light vehicle range scale", "0 = Default of 1; 1.5 = light vehicles are attacked at 1.5x attack range" },
		{ _field_real, "heavy vehicle range scale", "0 = Default of 1; 1.5 = light vehicles are attacked at 1.5x attack range" },
		{ _field_real, "flying vehicle range scale", "0 = Default of 1; 1.5 = light vehicles are attacked at 1.5x attack range" },
		{ _field_real, "light vehicle score bonus", "0 = No bonus preference for light vehicles; 0.5 = 50% score bonus for light vehicles" },
		{ _field_real, "heavy vehicle score bonus", "0 = No bonus preference for heavy vehicles; 0.5 = 50% score bonus for heavy vehicles" },
		{ _field_real, "flying vehicle score bonus", "0 = No bonus preference for flying vehicles; 0.5 = 50% score bonus for flying vehicles" },
		{ _field_real, "primary fire time", "how long the sentry waits before using its primary weapon barrel", "seconds" },
		{ _field_real, "secondary fire time", "how long the sentry waits before using its secondary weapon barrel", "seconds" },
		{ _field_tag_reference, "player entered alert range sound", "1st person sound to play when targeted player enters sentry's alert range", &global_sound_reference },
		{ _field_tag_reference, "player exited alert range sound", "1st person sound to play when targeted player leaves sentry's alert range", &global_sound_reference },
		{ _field_terminator }
	};

	TAG_REFERENCE(hud_screen_reference, CUI_SCREEN_TAG);

	V5_TAG_BLOCK(hud_screen_reference_block, 65536)
	{
		{ _field_legacy, _field_tag_reference, "hud screen reference", &hud_screen_reference },
		{ _field_legacy, _field_terminator }
	};

	#define UNIT_SEAT_BLOCK_ID { 0x0503B218, 0xDE414AF3, 0xAED6B5FD, 0xC83836D9 }
	TAG_BLOCK(
		unit_seat_block,
		"unit_seat_block",
		MAXIMUM_SEATS_PER_UNIT_DEFINITION,
		"unit_seat_block",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN3 | SET_UNKNOWN4 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | 
		SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		UNIT_SEAT_BLOCK_ID)
	{
		{ _field_long_flags, "flags", &unit_seat_flags },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_long_flags, "secondary flags", &unit_seat_secondary_flags },

		{ _field_old_string_id, "label", FIELD_FLAG_INDEX },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_marker),
		{ _field_old_string_id, "marker name" },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_marker),
		{ _field_string_id, "entry marker(s) name" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 3 },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_marker),
		{ _field_string_id, "ui marker name" },
		{ _field_string_id, "ui navpoint name" },

		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_marker),
		{ _field_string_id, "boarding grenade marker" },
		{ _field_string_id, "boarding grenade string" },
		{ _field_string_id, "boarding melee string" },
		{ _field_string_id, "in-seat string" },
		{ _field_real_fraction, "ping scale", "nathan is too lazy to make pings for each seat." },
		{ _field_useless_pad, "" },
		{ _field_real, "turnover time", "how much time it takes to evict a rider from a flipped vehicle", "seconds" },
		FIELD_EXPLANATION("seat acceleration spring", nullptr, FIELD_FLAG_NONE, ""),

		// Reach and above live in a new seperate tag group, see physics/spring_acceleration_definitions.cpp
		{ _field_legacy, _field_version_less, _engine_type_haloreach, 3 },
		{ _field_legacy, _field_real_vector_3d, "acceleration range:world units" },
		{ _field_legacy, _field_real, "acceleration action scale#0 defaults to 1, scale the acceleration the object itself applies on this system." },
		{ _field_legacy, _field_real, "acceleration attach scale#0 defaults to 1, scale the acceleration the object itself applies on this system." },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_tag_reference, "seat acceleration", &spring_acceleration_reference },

		{ _field_real, "AI scariness" },
		{ _field_enum, "ai seat type", &global_ai_seat_type_enum },
		{ _field_short_block_index, "boarding seat", &unit_seat_block },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_block, "additional boarding seats", "additional seats to eject", &boarding_seat_block },

		{ _field_real_fraction, "listener interpolation factor", "how far to interpolate listener position from camera to occupant's head" },
		FIELD_EXPLANATION("speed dependant turn rates", nullptr, FIELD_FLAG_NONE, "when the unit velocity is 0, the yaw/pitch rates are the left values\nat [max speed reference], the yaw/pitch rates are the right values.\nthe max speed reference is what the code uses to generate a clamped speed from 0..1\nthe exponent controls how midrange speeds are interpreted.\nIOW: As velocity exceeds \'min speed\' and approaches \'max speed\', turn rates are scaled from low --> high"),
		{ _field_real_bounds, "yaw rate bounds", nullptr, "degrees per second" },
		{ _field_real_bounds, "pitch rate bounds", nullptr, "degrees per second" },
		{ _field_real, "pitch interpolation time", "0 means use default 17", "seconds to interpolate" },
		{ _field_real, "min speed reference", "Initial t is computed from velocity/(max speed - min speed)", "world units/sec" },
		{ _field_real, "max speed reference" },
		{ _field_real, "speed exponent", "if >0, t is then modified by raising to this exponent and result is used to linearly interpolate yaw/pitch rates" },
		{ _field_useless_pad, "" },
		FIELD_EXPLANATION("camera fields", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_struct, "unit camera", &unit_camera_struct },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_block, "hud screen references", &hud_screen_reference_block_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_tag_reference, "hud screen reference", &Tag::Reference<struct CuiScreenDefinition>::s_defaultDefinition },

		{ _field_string_id, "enter seat string" },
		{ _field_useless_pad, "" },
		{ _field_angle, "yaw minimum" },
		{ _field_angle, "yaw maximum" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_angle, "yaw minimum for AI operator", "only applies when an NPC is considering using this seat" },
		{ _field_angle, "yaw maximum for AI operator", "only applies when an NPC is considering using this seat" },

		{ _field_tag_reference, "built-in gunner", &character_reference },
		{ _field_useless_pad, "" },
		FIELD_EXPLANATION("entry fields", nullptr, FIELD_FLAG_NONE, "note: the entry radius shouldn\'t exceed 3 world units, \nas that is as far as the player will search for a vehicle\nto enter."),
		{ _field_real, "entry radius", "how close to the entry marker a unit must be" },
		{ _field_angle, "entry marker cone angle", "angle from marker forward the unit must be" },
		{ _field_angle, "entry marker facing angle", "angle from unit facing the marker must be" },
		{ _field_real, "maximum relative velocity" },
		{ _field_useless_pad, "" },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach, 5 },
		{ _field_real, "open time", nullptr, "seconds" },
		{ _field_real, "close time", nullptr, "seconds" },
		{ _field_string_id, "open function name", "creates an object function with this name that you can use to query the open state of this seat" },
		{ _field_string_id, "opening function name", "goes from 0 to 1 over the course of opening and stays at 1 while open.  Drops to 0 immediately when closing starts" },
		{ _field_string_id, "closing function name", "goes from 0 to 1 over the course of closing and stays at 1 while closed.  Drops to 0 immediately when opening starts" },

		{ _field_string_id, "invisible seat region" },
		{ _field_long_integer, "runtime invisible seat region index", FIELD_FLAG_READ_ONLY },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 4 },
		FIELD_EXPLANATION("seat death grab crate", nullptr, FIELD_FLAG_NONE, "If this unit dies while this seat is occupied, the occupant will be handed an instance of this crate for throwing purposes."),
		{ _field_tag_reference, "seat death grab crate", &crate_reference$2 },
		{ _field_string_id, "Seat Selection String" },
		{ _field_real, "bailout velocity", "if exiting in bailout fashion, how much velocity to add in the entry_marker's forward direction", "wu/s" },

		{ _field_terminator }
	};

	#define BOARDING_SEAT_BLOCK_ID { 0x355B4BFC, 0x76F044A3, 0xB2456430, 0x1E8E4B6E }
	TAG_BLOCK(
		boarding_seat_block,
		"boarding_seat_block",
		MAXIMUM_SEATS_PER_UNIT_DEFINITION,
		"s_boarding_seat",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		BOARDING_SEAT_BLOCK_ID)
	{
		{ _field_short_block_index, "seat", FIELD_FLAG_INDEX, &unit_seat_block },
		FIELD_PAD("PAD", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	#define UNIT_STRUCT_DEFINITION_ID { 0xC8958077, 0x466A4028, 0x94ACA1E3, 0xDB3BF1B8 }
	TAG_STRUCT(
		unit_struct_definition,
		"unit_struct_definition",
		"_unit_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN4 | SET_UNKNOWN5 | 
		SET_UNKNOWN7 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS | 
		SET_UNKNOWN18,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		UNIT_STRUCT_DEFINITION_ID)
	{
		{ _field_struct, "object", &object_struct_definition },
		FIELD_CUSTOM("$$$ UNIT $$$", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_long_flags, "flags", &unit_flags_part1, _field_id_dumb },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_long_flags, "flags2", &unit_flags_part2, _field_id_dumb },
		
		{ _field_enum, "default team", &unit_default_teams },
		{ _field_enum, "constant sound volume", &ai_sound_volume_enum },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_tag_reference, "hologram unit reference", &unit_struct_definition_hologram_unit_reference_reference },
		
		{ _field_block, "campaign metagame bucket", &campaign_metagame_bucket_block },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_block, "screen effects", &unit_screen_effect_block },

		{ _field_legacy, _field_version_less, _engine_type_haloreach, 2 },
		{ _field_legacy, _field_tag_reference, "integrated_light_toggle", &integrated_light_toggle_reference },
		{ _field_legacy, _field_angle, "camera field of view" },
		
		{ _field_real, "camera stiffness" },
		{ _field_struct, "unit camera", &unit_camera_struct },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach, 2 },
		FIELD_EXPLANATION("sync action camera fields", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_struct, "sync action camera", &unit_camera_struct },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach, 9 },
		{ _field_tag_reference, "assasination start damage response", &damage_response_definition_reference },
		{ _field_tag_reference, "assassination weapon", &weapon_reference },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_marker),
		{ _field_string_id, "assassination weapon stow marker", "the anchor we attach the knife to when we stow it" },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_marker),
		{ _field_string_id, "assassination weapon out marker", "the anchor we attach the knife to when we pull it out" },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_marker),
		{ _field_string_id, "assassination weapon anchor marker", "the marker on the knife that we anchor to the biped" },
		{ _field_tag_reference, "seat acceleration", &spring_acceleration_reference },

		{ _field_legacy, _field_version_less, _engine_type_haloreach, 3 },
		{ _field_legacy, _field_real_vector_3d, "acceleration range#ranges i,j,k" },
		{ _field_legacy, _field_real, "acceleration action scale" },
		{ _field_legacy, _field_real, "acceleration attach scale" },
		
		FIELD_CUSTOM("pings", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_real, "soft ping threshold", nullptr, nullptr, "[0,1]" },
		{ _field_real, "soft ping interrupt time", nullptr, "seconds" },
		{ _field_real, "hard ping threshold", nullptr, nullptr, "[0,1]" },
		{ _field_real, "hard ping interrupt time", nullptr, "seconds" },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach, 2 },
		{ _field_real, "soft death direction speed threshold", "moving faster than this means you will soft death in the movement direction. zero defaults to damage direction.", "wu/s" },
		{ _field_real, "hard death threshold", nullptr, nullptr, "[0,1]" },

		{ _field_real, "feign death threshold", nullptr, nullptr, "[0,1]" },
		{ _field_real, "feign death time", nullptr, "seconds" },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach, 7 },
		{ _field_real, "pain screen duration", "The duration of the pain function\n0 defaults to 0.5", "seconds" },
		{ _field_real, "pain screen region fade out duration", "The time it takes to fade out a damage region that is no longer the most recent damage region to be hit", "seconds" },
		{ _field_real_fraction, "pain screen region fade out weight threshold", "The threshold weight below which the focus channel must fall before we can cross fade to another region.", nullptr, "[0,1]" },
		{ _field_angle, "pain screen angle tolerance", "The tolerance angle between next and previous damage directions, below which we randomly vary the ping direction.", "degrees" },
		{ _field_angle, "pain screen angle randomness", "The maximum random angle to vary the incoming ping direction by if it's too close to the previous ping.", "degrees" },
		{ _field_real, "defensive screen duration", "The duration of the defensive function\n0 defaults to 2.0", "seconds" },
		{ _field_real_fraction, "defensive screen scrub fallback fraction", "When receiving multiple pings, this is the min percentage of the defensive screen scrub value will fallback to.", nullptr, "[0,1]" },

		{ _field_legacy, _field_version_less, _engine_type_haloreach },
		{ _field_legacy, _field_real, "distance of evade anim:world units#this must be set to tell the AI how far it should expect our evade animation to move us" },

		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		{ _field_real, "distance of dive anim", "this must be set to tell the AI how far it should expect our dive animation to move us", "world units" },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_real_fraction, "terminal velocity fall ratio", "ratio of airborne_arc animation to switch off falling overlay" },

		FIELD_CUSTOM("stun", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_real, "stun movement penalty", "1.0 prevents moving while stunned", nullptr, "[0,1]" },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach, 4 },
		{ _field_real, "stun turning penalty", "1.0 prevents turning while stunned", nullptr, "[0,1]" },
		{ _field_real, "stun jumping penalty", "1.0 prevents jumping while stunned", nullptr, "[0,1]" },
		{ _field_real, "minimum stun time", "all stunning damage will last for at least this long", "seconds" },
		{ _field_real, "maximum stun time", "no stunning damage will last for longer than this", "seconds" },
		
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		{ _field_real, "feign death chance", nullptr, nullptr, "[0,1]" },
		{ _field_real, "feign repeat chance", nullptr, nullptr, "[0,1]" },
		{ _field_tag_reference, "spawned turret character", "automatically created character when this unit is driven", &character_reference },
		{ _field_short_bounds, "spawned actor count", "number of actors which we spawn" },
		{ _field_real, "spawned velocity", "velocity at which we throw spawned actors" },
		FIELD_CUSTOM("aiming/looking", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_string_id, "target aiming pivot marker name", "set this to have your weapon barrel point at its calcualed target instead of matching the aiming of the unit controlling it.  This marker should be along the barrel at point that doesn't move when the barrel pitches up and down." },

		{ _field_angle, "aiming velocity maximum", nullptr, "degrees per second" },
		{ _field_angle, "aiming acceleration maximum", nullptr, "degrees per second squared" },
		{ _field_real_fraction, "casual aiming modifier", nullptr, nullptr, "[0,1]" },
		{ _field_angle, "looking velocity maximum", nullptr, "degrees per second" },
		{ _field_angle, "looking acceleration maximum", nullptr, "degrees per second squared" },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_real, "object velocity maximum", "Debug value for object velocity that corresponds to a blend screen weight of 1, 0 defaults to 5.0", "world units per second", FIELD_FLAG_UNKNOWN0 },

		{ _field_string_id, "right_hand_node", "where the primary weapon is attached" },
		{ _field_string_id, "left_hand_node", "where the seconday weapon is attached (for dual-pistol modes)" },
		{ _field_struct, "more damn nodes", &unit_additional_node_names_struct },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach, 2 },
		{ _field_enum, "melee damage class", &global_melee_class_enum_definition },
		FIELD_PAD("PAD", nullptr, FIELD_FLAG_NONE, 2),
		
		FIELD_CUSTOM("melee damage", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_tag_reference, "melee damage", &global_damage_reference },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_tag_reference, "native melee override", "when set, characters will melee with these settings rather than their actual held weapon. (for characters that melee with an off hand)", &weapon_reference },

		{ _field_struct, "your momma", &unit_boarding_melee_struct },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		{ _field_enum, "motion sensor blip size", &global_chud_blip_type_definition },
		{ _field_enum, "item owner size", &unit_item_owner_size_enum },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach, 2 },
		{ _field_string_id, "equipment variant name" },
		{ _field_string_id, "grounded equipment variant name" },
		
		{ _field_block, "postures", &unit_postures_block },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_block, "HUD Interfaces", &unit_hud_interfaces_block_block },
		
		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_block, "Hud audio cues", &hud_unit_sound_block },

		{ _field_block, "dialogue variants", &dialogue_variant_block },
		FIELD_CUSTOM("standard grenade throw", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach, 3 },
		{ _field_real, "grenade angle", nullptr, "degrees" },
		{ _field_real, "grenade angle max elevation", nullptr, "degrees" },
		{ _field_real, "grenade angle min elevation", nullptr, "degrees" },
		
		{ _field_real, "grenade velocity", nullptr, "world units per second" },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 6 },
		FIELD_CUSTOM("sprinting grenade throw", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_real, "grenade angle (sprinting)", nullptr, "degrees" },
		{ _field_real, "grenade angle max elevation (sprinting)", nullptr, "degrees" },
		{ _field_real, "grenade angle min elevation (sprinting)", nullptr, "degrees" },
		{ _field_real, "grenade velocity (sprinting)", nullptr, "world units per second" },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		
		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 6 },
		FIELD_CUSTOM("primary weapon toss", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_real, "weapon angle", nullptr, "degrees" },
		{ _field_real, "weapon angle max elevation", nullptr, "degrees" },
		{ _field_real, "weapon angle min elevation", nullptr, "degrees" },
		{ _field_real, "weapon velocity", nullptr, "world units per second" },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		
		{ _field_enum, "grenade type", &global_grenade_type_enum },
		{ _field_short_integer, "grenade count" },
		{ _field_block, "powered seats", &powered_seat_block },
		{ _field_block, "weapons", &unit_weapon_block },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_block, "target tracking", &global_target_tracking_parameters_block },
		
		{ _field_block, "seats", &unit_seat_block },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach, 4 }, // custom fields are factored into the versioning
		FIELD_CUSTOM("open/close", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_real, "opening time", "how long the unit takes to open when the hs_function unit_open is called\nThe current open state can be retrieved from the object function unit_open", "s" },
		{ _field_real, "closing time", "you don't have to go home, but you can't stay here", "s" },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		
		FIELD_CUSTOM("EMP Disabling", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_real, "emp disabled time", nullptr, "seconds" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_real, "emp disabled time (PVP)", "Set to -1 for not disabled in MP but disabled in SP", "seconds " },
		
		{ _field_tag_reference, "emp disabled effect", &global_effect_reference },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		FIELD_CUSTOM("Boost", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_struct, "boost", &unit_boost_struct },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		FIELD_EXPLANATION("Lipsync", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_struct, "lipsync", &unit_lipsync_scales_struct },
		FIELD_EXPLANATION("Exit and Detach", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_tag_reference, "exit and detach damage", &global_damage_reference },
		{ _field_tag_reference, "exit and detach weapon", &global_weapon_reference },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 5 },
		FIELD_EXPLANATION("Experience", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_short_integer, "experience for kill" },
		{ _field_short_integer, "experience for assist" },
		{ _field_tag_reference, "hero assist equipment", "this is where you stick an equipment that the biped will always have, to implement the bizarrely named hero assist", &global_equipment_reference },
		{ _field_real, "bailout threshold", "the speed above which units will bail out of a vehicle instead of just exiting", "wu/s" },

		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end), // end unit group

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_real_fraction, "iron sight weapon dampening", "when using iron sights, how much to scale the weapon overlays to steady the gun (0 = rock steady, 1= no dampening)", "(0-1)" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 3 },
		FIELD_CUSTOM("Birthing", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_struct, "birth", &unit_birth_struct },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		
		{ _field_terminator }
	};

	#define UNIT_CAMERA_STRUCT_ID { 0x382328B4, 0x49B04550, 0x9B1635F2, 0x1B616A06 }
	TAG_STRUCT(
		unit_camera_struct,
		"unit_camera_struct",
		"s_unit_camera",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN3 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | 
		SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		UNIT_CAMERA_STRUCT_ID)
	{
		FIELD_CUSTOM("Unit Camera", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_word_flags, "flags", &unit_camera_flags_definition },
		FIELD_PAD("doh", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_marker),
		{ _field_old_string_id, "camera marker name" },

		{ _field_legacy, _field_version_less, _engine_type_haloreach },
		{ _field_legacy, _field_old_string_id, "camera submerged marker name" },

		{ _field_angle, "pitch auto-level" },
		{ _field_angle_bounds, "pitch range" },
		{ _field_block, "camera tracks", &unit_camera_track_block },
		{ _field_angle, "pitch minimum spring" },
		{ _field_angle, "pitch mmaximum spring" },
		{ _field_angle, "spring velocity" },

		{ _field_legacy, _field_version_less, _engine_type_haloreach, 1 },
		{ _field_legacy, _field_block, "unknown@", &g_null_block }, // #TODO: Research

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach, 8 },
		{ _field_angle, "look acceleration", "if non-zero, limits the change in look velocity per second while the user is pushing the look stick in the current direction of looking", "deg/s/s" },
		{ _field_angle, "look deceleration", "if non-zero, limits the change in look velocity per second while the user is not pushing the look stick or changing directions", "deg/s/s" },
		{ _field_real_fraction, "look acc smoothing fraction", "if non-zero, when the desired velocity change is less than this fraction of the acceleration, starts interpolating the maximum acceleration towards zero.\nYou can think of this as a time in seconds where if the velocity would reach its target in this amount of time or less, it will start taking longer." },
		{ _field_angle, "override fov", "if non-zero, overrides the FOV set in the unit or globals" },
		{ _field_struct, "camera obstruction", &camera_obstruction_struct },
		{ _field_block, "camera acceleration", &unit_camera_acceleration_displacement_block },
		{ _field_block, "move stick overrides", &gamepad_stick_info_block },
		{ _field_block, "look stick overrides", &gamepad_stick_info_block },

		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		{ _field_terminator }
	};

	V5_TAG_BLOCK(halo3_unit_camera_struct_unknown, 0x10000u)
	{
		{ _field_legacy, _field_terminator }
	};

	#define UNIT_CAMERA_ACCELERATION_DISPLACEMENT_FUNCTION_STRUCT_ID { 0x22A7A324, 0xB17C4B45, 0xBBF37B84, 0xD2BD1E36 }
	TAG_STRUCT(
		unit_camera_acceleration_displacement_function_struct,
		"unit_camera_acceleration_displacement_function_struct",
		"s_unit_camera_acceleration_displacement_function",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		UNIT_CAMERA_ACCELERATION_DISPLACEMENT_FUNCTION_STRUCT_ID)
	{
		{ _field_char_enum, "Input Variable", &unit_camera_acceleration_displacement_input, _field_id_function_input_scalar },
		FIELD_PAD("blah", nullptr, FIELD_FLAG_NONE, 3),
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_default),
		{ _field_struct, "mapping", &mapping_function },
		{ _field_real, "maximum value", "for linear velocity; this is wu/s\nfor linear acceleration; this is the fraction of the seat acceleration\nfor angular velocity; this is deg/s", _field_id_function_unknown },
		{ _field_real, "camera scale (axial)", "scale factor used when this acceleration component is along the axis of the forward vector of the camera", _field_id_function_unknown },
		{ _field_real, "camera scale (perpendicular)", "scale factor used when this acceleration component is perpendicular to the camera", _field_id_function_unknown },
		{ _field_terminator }
	};

	#define UNIT_ADDITIONAL_NODE_NAMES_STRUCT_ID { 0x35A19301, 0xDCF54C9C, 0x8671ED37, 0x1EF33AE5 }
	TAG_STRUCT(
		unit_additional_node_names_struct,
		"unit_additional_node_names_struct",
		"unit_additional_node_names_struct",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		UNIT_ADDITIONAL_NODE_NAMES_STRUCT_ID)
	{
		{ _field_string_id, "preferred_gun_node", "if found, use this gun marker" },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_marker),

		{ _field_legacy, _field_version_equal, _engine_type_groundhog },
		{ _field_legacy, _field_string_id, "preferred_dual_gun_node" },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_string_id, "preferred_grenade_marker", "if found, use this marker to attach live grenades to" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		FIELD_EXPLANATION("Weapon Specific Markers", nullptr, FIELD_FLAG_NONE, "These will override the righthand/lefthand nodes when the weapon matches the one used by the unit"),
		{ _field_block, "weapon specific markers", &WeaponSpecificMarkersBlock_block },

		{ _field_terminator }
	};

	#define UNIT_BOARDING_MELEE_STRUCT_ID { 0xA96C7D6D, 0xD8B54A51, 0xBF99FA0C, 0x13071BCE }
	TAG_STRUCT(
		unit_boarding_melee_struct,
		"unit_boarding_melee_struct",
		"unit_boarding_melee_struct",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		UNIT_BOARDING_MELEE_STRUCT_ID)
	{
		{ _field_tag_reference, "boarding melee damage", &global_damage_reference },
		{ _field_tag_reference, "boarding melee response", &global_damage_reference },
		{ _field_tag_reference, "eviction melee damage", &global_damage_reference },
		{ _field_tag_reference, "eviction melee response", &global_damage_reference },
		{ _field_tag_reference, "landing melee damage", &global_damage_reference },
		{ _field_tag_reference, "flurry melee damage", &global_damage_reference },
		{ _field_tag_reference, "obstacle smash damage", &global_damage_reference },

		{ _field_legacy, _field_version_equal, _engine_type_haloreach },
		{ _field_legacy, _field_tag_reference, "shield pop melee damage", &global_damage_reference },

		{ _field_legacy, _field_version_equal, _engine_type_haloreach },
		{ _field_legacy, _field_tag_reference, "assassination damage", &global_damage_reference },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_tag_reference, "assassination primary damage", &global_damage_reference },
		{ _field_tag_reference, "assassination ragdoll damage", MAKE_OLD_NAMES("assassination damage"), &global_damage_reference },

		{ _field_terminator }
	};

	#define UNIT_BOOST_STRUCT_ID { 0x4506D858, 0x370B402D, 0x83F08481, 0xCB943803 }
	TAG_STRUCT(
		unit_boost_struct,
		"unit_boost_struct",
		"s_unit_boost_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		UNIT_BOOST_STRUCT_ID)
	{
		{ _field_tag_reference, "boost collision damage", &collision_damage_reference$2 },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_long_flags, "flags", &boost_flags },

		{ _field_real, "boost peak power" },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach, 3 },
		{ _field_real, "boost rise time", "if the trigger is fully down, takes this long to reach peak power", "s" },
		{ _field_real, "boost fall time", "if the trigger is let go (or peak time expires), takes this long to reach 0 power", "s" },
		{ _field_real, "boost power per second", "1, means you burn all your power in one sec.  .1 means you can boost for 10 seconds." },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_real, "boost low warning threshold" },

		{ _field_legacy, _field_version_less, _engine_type_haloreach, 4 }, // want sure if/how to fit these against new definition
		{ _field_legacy, _field_real, "boost peak power" },	// assembly
		{ _field_legacy, _field_real, "boost rise power" },	// assembly
		{ _field_legacy, _field_real, "boost peak time" },		// assembly
		{ _field_legacy, _field_real, "boost fall power" },	// assembly

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach, 4 },
		{ _field_real, "recharge rate", "1 means you recharge fully in 1 second.  .1 means you rechage fully in 10 seconds" },
		{ _field_real, "recharge delay", "how long do you have to be off the tirgger for before boost starts recharging", "s" },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_default),
		{ _field_struct, "trigger to boost", &mapping_function },

		{ _field_terminator }
	};

	#define UNIT_LIPSYNC_SCALES_STRUCT_ID { 0x2E5A89D9, 0xAF1E466B, 0x9F62F58C, 0x8B1BFE32 }
	TAG_STRUCT(
		unit_lipsync_scales_struct,
		"unit_lipsync_scales_struct",
		"unit_lipsync_scales_struct",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		UNIT_LIPSYNC_SCALES_STRUCT_ID)
	{
		{ _field_real_fraction, "attack weight" },
		{ _field_real_fraction, "decay weight" },
		{ _field_terminator }
	};

	#define UNIT_BIRTH_STRUCT_ID { 0x3810C67E, 0xD2B344FD, 0x97ED0AC4, 0x965DA861 }
	TAG_STRUCT(
		unit_birth_struct,
		"unit_birth_struct",
		"UnitBirthingProperties",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		UNIT_BIRTH_STRUCT_ID)
	{
		{ _field_short_block_index, "seat", FIELD_FLAG_INDEX, &unit_seat_block },
		FIELD_PAD("PAD", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_string_id, "birthing region", "if found, this region will be set to destroyed during birth" },
		{ _field_terminator }
	};

	STRINGS(unit_camera_acceleration_displacement_input)
	{
		"linear velocity",
		"linear acceleration",
		"yaw",
		"pitch",
		"roll"
	};
	STRING_LIST(unit_camera_acceleration_displacement_input, unit_camera_acceleration_displacement_input_strings, _countof(unit_camera_acceleration_displacement_input_strings));

	STRINGS(unit_camera_flags_definition)
	{
		"pitch bounds absolute space",
		"only collides with environment",
		"hides player-unit from camera#the player controlling this camera will not see their unit.  All other cameras will see this unit",
		"use aiming vector instead of marker forward#for cameras without tracks that use a marker position, specifies that we use the unit\'s aiming vector instead of the marker\'s forward vector.\nThis results in more accurate aiming and smoother movement when frames are dropped"
	};
	STRING_LIST(unit_camera_flags_definition, unit_camera_flags_definition_strings, _countof(unit_camera_flags_definition_strings));

	STRINGS(unit_seat_flags)
	{
		"invisible#completely enclosed by vehicle",
		"locked#when occupied, prevents enemies from entering locked seats",
		"driver",
		"gunner",
		"third person camera",
		"allows weapons",
		"third person on enter",
		"first person camera slaved to gun.",
		"not valid without driver",
		"allow AI noncombatants",
		"boarding seat",
		"ai firing disabled by max acceleration",
		"boarding enters seat",
		"boarding need any passenger",
		"invalid for player",
		"invalid for non-player",
		"invalid for hero",
		"gunner (player only)",
		"invisible under major damage",
		"melee instant killable",
		"leader preference",
		"allows exit and detach",
		"blocks headshots",
		"exits to ground",
		"forward from attachment",
		"disallow AI shooting",
		"prevents weapon stowing",
		"takes top level aoe damage",
		"disallow exit#Prevents the unit currently in the seat from exiting regardless of circumstances",
		"local aiming",
		"pelvis relative attachment",
		"apply velocity on death exit"
	};
	STRING_LIST(unit_seat_flags, unit_seat_flags_strings, _countof(unit_seat_flags_strings));

	STRINGS(unit_seat_secondary_flags)
	{
		"biped grab seat",
		"low hanging cargo",
		"ninja hot seat",
		"skip obstacle check",
		"search parent for entry marker",
		"gunner release aim on exit#The unit\'s aim will no longer be controlled by gunner when it exits",
		"fully open before allowing exit",
		"finish melee before allowing exit",
		"kill parent if unit in seat dies",
		"co-pilot#opens and closes the cockpit to allow copilot in (if already closed)"
	};
	STRING_LIST(unit_seat_secondary_flags, unit_seat_secondary_flags_strings, _countof(unit_seat_secondary_flags_strings));

	STRINGS(global_ai_seat_type_enum)
	{
		"NONE",
		"passenger",
		"gunner",
		"small cargo",
		"large cargo",
		"driver"
	};
	STRING_LIST(global_ai_seat_type_enum, global_ai_seat_type_enum_strings, _countof(global_ai_seat_type_enum_strings));

	STRINGS(initial_weapon_position)
	{
		"primary or backpack",
		"secondary"
	};
	STRING_LIST(initial_weapon_position, initial_weapon_position_strings, _countof(initial_weapon_position_strings));

	STRINGS(sentryTurretBehaviorFlagDefinition)
	{
		"performs yaw scanning",
		"secondary barrel starts enabled",
		"suppress secondary barrel for light vehicles#Can be used to prevent turret from using its big guns on a mongoose",
		"only use vehicle range scale if secondary barrel active",
		"only use vehicle score bonus if secondary barrel active"
	};
	STRING_LIST(sentryTurretBehaviorFlagDefinition, sentryTurretBehaviorFlagDefinition_strings, _countof(sentryTurretBehaviorFlagDefinition_strings));

	STRINGS(unit_flags_part1)
	{
		"circular aiming",
		"destroyed after dying",
		"half-speed interpolation",
		"fires from camera",
		"entrance inside bounding sphere",
		"doesn\'t show readied weapon",
		"causes passenger dialogue",
		"resists pings",
		"melee attack is fatal",
		"don\'t reface during pings",
		"has no aiming",
		"impact melee attaches to unit",
		"impact melee dies on shields",
		"cannot open doors automatically",
		"melee attackers cannot attach",
		"not instantly killed by melee",
		"flashlight power doesnt transfer to weapon",
		"runs around flaming",
		"top level for AOE damage",
		"special cinematic unit",
		"ignored by autoaiming",
		"shields fry infection forms",
		"use velocity as acceleration",
		"can dual wield",
		"acts as gunner for parent",
		"controlled by parent gunner",
		"parent\'s primary weapon",
		"parent\'s secondary weapon",
		"unit has boost",
		"unit has vectored thrust",
		"allow aim while opening or closing",
		"compute acceleration from aiming"
	};
	STRING_LIST(unit_flags_part1, unit_flags_part1_strings, _countof(unit_flags_part1_strings));

	STRINGS(unit_flags_part2)
	{
		"override all pings",
		"unit supports bailout",
		"flying_or_vehicle_hard_pings_allowed",
		"attempt to fire from weapon matching camera#if this unit \"fires from camera\", this flag attempts to match the result, but have the projectile actually come out of the gun",
		"treat as vehicle #Treats a non-vehicle unit as a vehicle for gameplay purposes.  Mantis (biped) hack.",
		"dropped weapons can dissolve",
		"hard pings not allowed for driver-less vehicle",
		"No friendly bump damage #Unit does not inflict collision damage to friendly units",
		"ignores attachment feedback forced hard pings#ignores hard pings forced by attachment of sticky grenade",
		"unit appears on radar as dot not sprite#do not try to find a sprite for this unit.  Just draw a dot.",
		"suppress radar blip",
		"do not ignore parents for line of sight tests#ai that are operating this unit will not ignore the unit\'s parents when doing line of sight tests (Mammoth turret hack)",
		"do not pass attached AOE damage to children#projectiles attached to this object do not do attached damage to the object\'s children (regular aoe damage is still done to top level aoe children)",
		"do not generate AI line of fire pill for unit#even if this vehicle is being driven by a friendly character, don\'t generate a pill for it during ai line of fire checks (for very large vehicles i.e. the lich)"
	};
	STRING_LIST(unit_flags_part2, unit_flags_part2_strings, _countof(unit_flags_part2_strings));

	STRINGS(unit_default_teams$2)
	{
		"default",
		"player",
		"human",
		"covenant",
		"brute",
		"mule",
		"spare",
		"covenant_player",
		"forerunner"
	};
	STRING_LIST(unit_default_teams$2, unit_default_teams$2_strings, _countof(unit_default_teams$2_strings));

	STRINGS(boost_flags)
	{
		"pegs throttle"
	};
	STRING_LIST(boost_flags, boost_flags_strings, _countof(boost_flags_strings));

	STRINGS(unit_item_owner_size_enum)
	{
		"small",
		"medium",
		"large",
		"huge"
	};
	STRING_LIST(unit_item_owner_size_enum, unit_item_owner_size_enum_strings, _countof(unit_item_owner_size_enum_strings));

} // namespace macaque

} // namespace blofeld

