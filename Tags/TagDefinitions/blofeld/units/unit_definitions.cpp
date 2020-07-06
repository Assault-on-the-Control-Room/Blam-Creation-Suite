#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_INHERIT_FROM_BLOCK(unit, UNIT_TAG, object, OBJECT_TAG, unit_block_block);

	TAG_BLOCK(unit_screen_effect_block, 4)
	{
		{ _field_tag_reference, "screen effect^", &global_area_screen_effect_reference },
		{ _field_terminator }
	};

	TAG_BLOCK(unit_camera_track_block, MAXIMUM_NUMBER_OF_UNIT_CAMERA_TRACKS)
	{
		{ _field_tag_reference, "track", &global_camera_track_reference },

		{ _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_tag_reference, "screen effect", &global_area_screen_effect_reference },

		{ _field_terminator }
	};

	TAG_BLOCK(unit_camera_acceleration_displacement_block, 1)
	{
		{ _field_real, "maximum camera velocity:wu/s#how quickly the camera can move to a new displacement (if the velocity suddenly changes).\nDuring this time the aim vector for the unit will be inaccurate, so don\'t set this too low.\n0 defaults to infinite." },
		{ _field_explanation, "", "For each of the following functions, if 1 instance of the block is specified, the offsets are symmetric.\nIf 2 instances are specified, then the first instance is used for positive displacement and the second is used for negative displacement." },
		{ _field_struct, "forward/back", &unit_camera_acceleration_displacement_function_struct_struct_definition },
		{ _field_struct, "left/right", &unit_camera_acceleration_displacement_function_struct_struct_definition },
		{ _field_struct, "up/down", &unit_camera_acceleration_displacement_function_struct_struct_definition },
		{ _field_terminator }
	};

	TAG_BLOCK(WeaponSpecificMarkersBlock, WEAPON_SPECIFIC_MARKERS_COUNT)
	{
		{ _field_string_id, "complete weapon name^" },
		{ _field_string_id, "weapon class" },
		{ _field_string_id, "weapon name" },
		{ _field_custom },
		{ _field_string_id, "right hand marker" },
		{ _field_custom },
		{ _field_string_id, "left hand marker" },
		{ _field_terminator }
	};

	TAG_BLOCK(unit_postures_block, MAXIMUM_POSTURES_PER_UNIT)
	{
		{ _field_string_id, "name^" },
		{ _field_useless_pad },
		{ _field_real_vector_3d, "pill offset" },
		{ _field_terminator }
	};

	TAG_BLOCK(dialogue_variant_block, MAXIMUM_DIALOGUE_VARIANTS_PER_UNIT)
	{
		{ _field_short_integer, "variant number#variant number to use this dialogue with (must match the suffix in the permutations on the unit\'s model)" },
		{ _field_pad, "BQCVEMF", 2 },
		{ _field_useless_pad },
		{ _field_tag_reference, "dialogue", &dialogue_reference },
		{ _field_terminator }
	};

	TAG_BLOCK(powered_seat_block, k_powered_seats_count)
	{
		{ _field_real, "driver powerup time:seconds" },
		{ _field_real, "driver powerdown time:seconds" },
		{ _field_terminator }
	};

	TAG_BLOCK(SentryPropertiesBlock, 1)
	{
		{ _field_byte_flags, "behavior", &sentryTurretBehaviorFlagDefinition },
		{ _field_pad, "flagPad", 3 },
		{ _field_real, "sight cone angle:degrees#the cone that this sentry actually sees with; only used when scanning" },
		{ _field_real, "alert range:world units#how far the sentry can see (sentry will track enemies within alert range, but not necessarily fire)" },
		{ _field_real, "attack range:world units#how far the sentry can shoot" },
		{ _field_real, "attack range score multiplier#0 = No preference to targets in attack range; 0.5 = Targets in attack range get 50% score bonus" },
		{ _field_real, "light vehicle range scale#0 = Default of 1; 1.5 = light vehicles are attacked at 1.5x attack range" },
		{ _field_real, "heavy vehicle range scale#0 = Default of 1; 1.5 = light vehicles are attacked at 1.5x attack range" },
		{ _field_real, "flying vehicle range scale#0 = Default of 1; 1.5 = light vehicles are attacked at 1.5x attack range" },
		{ _field_real, "light vehicle score bonus#0 = No bonus preference for light vehicles; 0.5 = 50% score bonus for light vehicles" },
		{ _field_real, "heavy vehicle score bonus#0 = No bonus preference for heavy vehicles; 0.5 = 50% score bonus for heavy vehicles" },
		{ _field_real, "flying vehicle score bonus#0 = No bonus preference for flying vehicles; 0.5 = 50% score bonus for flying vehicles" },
		{ _field_real, "primary fire time:seconds#how long the sentry waits before using its primary weapon barrel" },
		{ _field_real, "secondary fire time:seconds#how long the sentry waits before using its secondary weapon barrel" },
		{ _field_tag_reference, "player entered alert range sound#1st person sound to play when targeted player enters sentry\'s alert range", &global_sound_reference },
		{ _field_tag_reference, "player exited alert range sound#1st person sound to play when targeted player leaves sentry\'s alert range", &global_sound_reference },
		{ _field_terminator }
	};

	TAG_BLOCK(unit_weapon_block, MAXIMUM_INITIAL_WEAPONS_PER_UNIT)
	{
		{ _field_tag_reference, "weapon^", &weapon_reference },

		{ _field_version_greater, _engine_type_halo3 },
		{ _field_string_id, "variant name" },

		{ _field_version_greater, _engine_type_haloreach, 32 },
		{ _field_long_enum, "position", &initial_weapon_position },
		{ _field_real, "maximum firing cone angle:degrees#must be greater than zero for turret to fire" },
		{ _field_real, "minimum retarget time:seconds#minimum time before autoturret will change targets" },
		{ _field_real, "blind fire time:seconds#time after losing a target before turret stops blind firing" },
		{ _field_real, "lead fraction#0.0 = no lead, 1.0 = perfect lead" },
		{ _field_real_bounds, "engagement range:units#when non-zero, turret will not prioritize targets above or below this range" },
		{ _field_real, "proximity score multiplier#0.0 = no importance, 2.0 = things that are close are twice as important" },
		{ _field_real, "direction score multiplier#0.0 = no importance, 2.0 = things in front of you are twice as important" },
		{ _field_real, "attacker score multiplier#0.0 = no importance, 2.0 = things that attacked you last are twice as important" },
		{ _field_real, "targeting weight hologram#multiplier" },
		{ _field_real, "targeting weight auto turret#multiplier" },
		{ _field_real, "primary fire delay from idle:seconds" },
		{ _field_real, "secondary fire delay from idle:seconds" },
		{ _field_real, "caution duration:seconds#how long the turret stays alert after losing a target" },
		{ _field_real, "alert angular speed max:radians per second#0 = infinite" },
		{ _field_real, "idle angular speed max:radians per second#0 = infinite" },
		{ _field_real, "targeting yaw min:degrees#(-180 to 0) how far it can rotate past its initial rotation" },
		{ _field_real, "targeting yaw max:degrees#(0 to 180) how far it can rotate past its initial rotation" },
		{ _field_real, "targeting pitch min:degrees#(-180 to 0) how far it can rotate past its initial rotation" },
		{ _field_real, "targeting pitch max:degrees#(0 to 180) how far it can rotate past its initial rotation" },
		{ _field_real, "idle scanning yaw min:degrees#(-180 to 0) how far it will look around past its initial rotation" },
		{ _field_real, "idle scanning yaw max:degrees#(0 to 180) how far it will look around past its initial rotation" },
		{ _field_real, "idle scanning pitch min:degrees#(-180 to 0) how far it will look around past its initial rotation" },
		{ _field_real, "idle scanning pitch max:degrees#(0 to 180) how far it will look around past its initial rotation" },
		{ _field_real, "idle scanning min interest distance:world units#0 = infinite.  Idle scanning won\'t look at something that is closer than this distance" },
		{ _field_tag_reference, "alert mode effect#effect played on the turret when it goes into alert mode", &global_effect_reference },
		{ _field_custom },
		{ _field_string_id, "alert mode effect marker" },
		{ _field_string_id, "alert mode effect primary scale" },
		{ _field_string_id, "alert mode effect secondary scale" },
		{ _field_block, "sentry properties", &SentryPropertiesBlock_block },
		{ _field_real, "target camouflage threshold# 0 - 1 : target when players camo level falls below this threshold, full camo = 1" },

		{ _field_terminator }
	};

	TAG_BLOCK(boarding_seat_block, MAXIMUM_SEATS_PER_UNIT_DEFINITION)
	{
		{ _field_short_block_index, "seat^" },
		{ _field_pad, "PAD", 2 },
		{ _field_terminator }
	};

	TAG_REFERENCE(hud_screen_reference, CUI_SCREEN_TAG);

	TAG_BLOCK(hud_screen_reference_block, 65536)
	{
		{ _field_tag_reference, "hud screen reference", &hud_screen_reference },
		{ _field_terminator }
	};

	TAG_BLOCK(unit_seat_block, MAXIMUM_SEATS_PER_UNIT_DEFINITION)
	{
		{ _field_long_flags, "flags", &unit_seat_flags },

		{ _field_version_greater, _engine_type_haloreach },
		{ _field_long_flags, "secondary flags", &unit_seat_secondary_flags },

		{ _field_old_string_id, "label^" },
		{ _field_custom },
		{ _field_old_string_id, "marker name" },
		{ _field_custom },
		{ _field_string_id, "entry marker(s) name" },

		{ _field_version_greater, _engine_type_haloreach, 3 },
		{ _field_custom },
		{ _field_string_id, "ui marker name" },
		{ _field_string_id, "ui navpoint name" },

		{ _field_custom },
		{ _field_string_id, "boarding grenade marker" },
		{ _field_string_id, "boarding grenade string" },
		{ _field_string_id, "boarding melee string" },
		{ _field_string_id, "in-seat string" },
		{ _field_real_fraction, "ping scale#nathan is too lazy to make pings for each seat." },
		{ _field_useless_pad },
		{ _field_real, "turnover time:seconds#how much time it takes to evict a rider from a flipped vehicle" },
		{ _field_explanation, "seat acceleration spring", "" },

		// Reach and above live in a new seperate tag group, see physics/spring_acceleration_definitions.cpp
		{ _field_version_less, _engine_type_haloreach, 3 },
		{ _field_real_vector_3d, "acceleration range:world units" },
		{ _field_real, "acceleration action scale#0 defaults to 1, scale the acceleration the object itself applies on this system." },
		{ _field_real, "acceleration attach scale#0 defaults to 1, scale the acceleration the object itself applies on this system." },

		{ _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_tag_reference, "seat acceleration", &spring_acceleration_reference },

		{ _field_real, "AI scariness" },
		{ _field_enum, "ai seat type", &global_ai_seat_type_enum },
		{ _field_short_block_index, "boarding seat" },

		{ _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_block, "additional boarding seats#additional seats to eject", &boarding_seat_block_block },

		{ _field_real_fraction, "listener interpolation factor#how far to interpolate listener position from camera to occupant\'s head" },
		{ _field_explanation, "speed dependant turn rates", "when the unit velocity is 0, the yaw/pitch rates are the left values\nat [max speed reference], the yaw/pitch rates are the right values.\nthe max speed reference is what the code uses to generate a clamped speed from 0..1\nthe exponent controls how midrange speeds are interpreted.\nIOW: As velocity exceeds \'min speed\' and approaches \'max speed\', turn rates are scaled from low --> high" },
		{ _field_real_bounds, "yaw rate bounds:degrees per second" },
		{ _field_real_bounds, "pitch rate bounds:degrees per second" },
		{ _field_real, "pitch interpolation time:seconds to interpolate#0 means use default 17" },
		{ _field_real, "min speed reference:world units/sec#Initial t is computed from velocity/(max speed - min speed)" },
		{ _field_real, "max speed reference" },
		{ _field_real, "speed exponent#if >0, t is then modified by raising to this exponent and result is used to linearly interpolate yaw/pitch rates" },
		{ _field_useless_pad },
		{ _field_explanation, "camera fields", "" },
		{ _field_struct, "unit camera", &unit_camera_struct_struct_definition },

		{ _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_block, "hud screen references", &hud_screen_reference_block_block },

		{ _field_version_greater, _engine_type_haloreach },
		{ _field_tag_reference, "hud screen reference", &Tag::Reference<struct CuiScreenDefinition>::s_defaultDefinition },
		
		{ _field_string_id, "enter seat string" },
		{ _field_useless_pad },
		{ _field_angle, "yaw minimum" },
		{ _field_angle, "yaw maximum" },

		{ _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_angle, "yaw minimum for AI operator#only applies when an NPC is considering using this seat" },
		{ _field_angle, "yaw maximum for AI operator#only applies when an NPC is considering using this seat" },

		{ _field_tag_reference, "built-in gunner", &character_reference },
		{ _field_useless_pad },
		{ _field_explanation, "entry fields", "note: the entry radius shouldn\'t exceed 3 world units, \nas that is as far as the player will search for a vehicle\nto enter." },
		{ _field_real, "entry radius#how close to the entry marker a unit must be" },
		{ _field_angle, "entry marker cone angle#angle from marker forward the unit must be" },
		{ _field_angle, "entry marker facing angle#angle from unit facing the marker must be" },
		{ _field_real, "maximum relative velocity" },
		{ _field_useless_pad },

		{ _field_version_greater_or_equal, _engine_type_haloreach, 5 },
		{ _field_real, "open time:seconds" },
		{ _field_real, "close time:seconds" },
		{ _field_string_id, "open function name#creates an object function with this name that you can use to query the open state of this seat" },
		{ _field_string_id, "opening function name#goes from 0 to 1 over the course of opening and stays at 1 while open.  Drops to 0 immediately when closing starts" },
		{ _field_string_id, "closing function name#goes from 0 to 1 over the course of closing and stays at 1 while closed.  Drops to 0 immediately when opening starts" },

		{ _field_string_id, "invisible seat region" },
		{ _field_long_integer, "runtime invisible seat region index*" },

		{ _field_version_greater, _engine_type_haloreach, 4 },
		{ _field_explanation, "seat death grab crate", "If this unit dies while this seat is occupied, the occupant will be handed an instance of this crate for throwing purposes." },
		{ _field_tag_reference, "seat death grab crate", &crate_reference$2 },
		{ _field_string_id, "Seat Selection String" },
		{ _field_real, "bailout velocity:wu/s#if exiting in bailout fashion, how much velocity to add in the entry_marker\'s forward direction" },

		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(unit_block, 1, unit_struct_definition_struct_definition);

	TAG_REFERENCE(integrated_light_toggle_reference, blofeld::INVALID_TAG);

	TAG_REFERENCE(unit_hud_interface_reference);

	TAG_BLOCK(unit_hud_interfaces_block, 65536)
	{
		{ _field_tag_reference, "Unit HUD Interface", &unit_hud_interface_reference },
		{ _field_terminator }
	};

	TAG_STRUCT(unit_struct_definition)
	{
		{ _field_struct, "object", &object_struct_definition_struct_definition },
		{ _field_custom, "$$$ UNIT $$$" },
		{ _field_long_flags, "flags", &unit_flags_part1 },

		{ _field_version_greater, _engine_type_haloreach },
		{ _field_long_flags, "flags2", &unit_flags_part2 },

		{ _field_enum, "default team", &unit_default_teams },
		{ _field_enum, "constant sound volume", &ai_sound_volume_enum },

		{ _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_tag_reference, "hologram unit reference", &unit_struct_definition_hologram_unit_reference_reference },

		{ _field_block, "campaign metagame bucket", &campaign_metagame_bucket_block_block },

		{ _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_block, "screen effects", &unit_screen_effect_block_block },

		{ _field_version_less, _engine_type_haloreach, 2 },
		{ _field_tag_reference, "integrated_light_toggle", &integrated_light_toggle_reference },
		{ _field_angle, "camera field of view" },

		{ _field_real, "camera stiffness" },
		{ _field_struct, "unit camera", &unit_camera_struct_struct_definition },

		{ _field_version_greater_or_equal, _engine_type_haloreach, 2 },
		{ _field_explanation, "sync action camera fields", "" },
		{ _field_struct, "sync action camera", &unit_camera_struct_struct_definition },

		{ _field_version_greater_or_equal, _engine_type_haloreach, 9 },
		{ _field_tag_reference, "assasination start damage response", &damage_response_definition_reference },
		{ _field_tag_reference, "assassination weapon", &weapon_reference },
		{ _field_custom },
		{ _field_string_id, "assassination weapon stow marker#the anchor we attach the knife to when we stow it" },
		{ _field_custom },
		{ _field_string_id, "assassination weapon out marker#the anchor we attach the knife to when we pull it out" },
		{ _field_custom },
		{ _field_string_id, "assassination weapon anchor marker#the marker on the knife that we anchor to the biped" },
		{ _field_tag_reference, "seat acceleration", &spring_acceleration_reference },

		{ _field_version_less, _engine_type_haloreach, 3 },
		{ _field_real_vector_3d, "acceleration range#ranges i,j,k" },
		{ _field_real, "acceleration action scale" },
		{ _field_real, "acceleration attach scale" },

		{ _field_custom, "pings" },
		{ _field_real, "soft ping threshold:[0,1]" },
		{ _field_real, "soft ping interrupt time:seconds" },
		{ _field_real, "hard ping threshold:[0,1]" },
		{ _field_real, "hard ping interrupt time:seconds" },

		{ _field_version_greater_or_equal, _engine_type_haloreach, 2 },
		{ _field_real, "soft death direction speed threshold:wu/s#moving faster than this means you will soft death in the movement direction. zero defaults to damage direction." },
		{ _field_real, "hard death threshold:[0,1]" },

		{ _field_real, "feign death threshold:[0,1]" },
		{ _field_real, "feign death time:seconds" },

		{ _field_version_greater_or_equal, _engine_type_haloreach, 7 },
		{ _field_real, "pain screen duration:seconds|CCBBAA#The duration of the pain function\n0 defaults to 0.5" },
		{ _field_real, "pain screen region fade out duration:seconds|CCBBAA#The time it takes to fade out a damage region that is no longer the most recent damage region to be hit" },
		{ _field_real_fraction, "pain screen region fade out weight threshold:[0,1]#The threshold weight below which the focus channel must fall before we can cross fade to another region." },
		{ _field_angle, "pain screen angle tolerance:degrees|CCBBAA#The tolerance angle between next and previous damage directions, below which we randomly vary the ping direction." },
		{ _field_angle, "pain screen angle randomness:degrees|CCBBAA#The maximum random angle to vary the incoming ping direction by if it\'s too close to the previous ping." },
		{ _field_real, "defensive screen duration:seconds#The duration of the defensive function\n0 defaults to 2.0" },
		{ _field_real_fraction, "defensive screen scrub fallback fraction:[0,1]#When receiving multiple pings, this is the min percentage of the defensive screen scrub value will fallback to." },

		{ _field_custom },
		{ _field_real, "distance of dive anim:world units#this must be set to tell the AI how far it should expect our dive animation to move us" },
		{ _field_real_fraction, "terminal velocity fall ratio#ratio of airborne_arc animation to switch off falling overlay" },

		{ _field_custom, "stun" },
		{ _field_real, "stun movement penalty:[0,1]#1.0 prevents moving while stunned" },

		{ _field_version_greater_or_equal, _engine_type_haloreach, 4 },
		{ _field_real, "stun turning penalty:[0,1]#1.0 prevents turning while stunned" },
		{ _field_real, "stun jumping penalty:[0,1]#1.0 prevents jumping while stunned" },
		{ _field_real, "minimum stun time:seconds#all stunning damage will last for at least this long" },
		{ _field_real, "maximum stun time:seconds#no stunning damage will last for longer than this" },

		{ _field_custom },
		{ _field_real, "feign death chance:[0,1]" },
		{ _field_real, "feign repeat chance:[0,1]" },
		{ _field_tag_reference, "spawned turret character#automatically created character when this unit is driven", &character_reference },
		{ _field_short_bounds, "spawned actor count#number of actors which we spawn" },
		{ _field_real, "spawned velocity#velocity at which we throw spawned actors" },

		{ _field_custom, "aiming/looking" },

		{ _field_version_greater_or_equal, _engine_type_haloreach, 1 },
		{ _field_string_id, "target aiming pivot marker name#set this to have your weapon barrel point at its calcualed target instead of matching the aiming of the unit controlling it.  This marker should be along the barrel at point that doesn\'t move when the barrel pitches up and down." },
		
		{ _field_angle, "aiming velocity maximum:degrees per second" },
		{ _field_angle, "aiming acceleration maximum:degrees per second squared" },
		{ _field_real_fraction, "casual aiming modifier:[0,1]" },
		{ _field_angle, "looking velocity maximum:degrees per second" },
		{ _field_angle, "looking acceleration maximum:degrees per second squared" },

		{ _field_custom },

		{ _field_version_greater_or_equal, _engine_type_haloreach, 1 },
		{ _field_real, "object velocity maximum!:world units per second#Debug value for object velocity that corresponds to a blend screen weight of 1, 0 defaults to 5.0" },

		{ _field_string_id, "right_hand_node#where the primary weapon is attached" },
		{ _field_string_id, "left_hand_node#where the seconday weapon is attached (for dual-pistol modes)" },
		{ _field_struct, "more damn nodes", &unit_additional_node_names_struct_struct_definition },

		{ _field_version_greater_or_equal, _engine_type_haloreach, 2 },
		{ _field_enum, "melee damage class", &global_melee_class_enum_definition },
		{ _field_pad, "PAD", 2 },

		{ _field_custom, "melee damage" },
		{ _field_tag_reference, "melee damage", &global_damage_reference },

		{ _field_version_greater, _engine_type_haloreach, 1 },
		{ _field_tag_reference, "native melee override#when set, characters will melee with these settings rather than their actual held weapon. (for characters that melee with an off hand)", &weapon_reference },

		{ _field_struct, "your momma", &unit_boarding_melee_struct_struct_definition },

		{ _field_custom },
		{ _field_enum, "motion sensor blip size", &global_chud_blip_type_definition },
		{ _field_enum, "item owner size", &unit_item_owner_size_enum },

		{ _field_version_greater_or_equal, _engine_type_haloreach, 2 },
		{ _field_string_id, "equipment variant name" },
		{ _field_string_id, "grounded equipment variant name" },

		{ _field_block, "postures", &unit_postures_block_block },

		{ _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_block, "HUD Interfaces", &unit_hud_interfaces_block_block },

		{ _field_version_greater, _engine_type_haloreach },
		{ _field_block, "Hud audio cues", &hud_unit_sound_block_block },

		{ _field_block, "dialogue variants", &dialogue_variant_block_block },

		{ _field_custom, "standard grenade throw" },

		{ _field_version_greater_or_equal, _engine_type_haloreach, 3 },
		{ _field_real, "grenade angle:degrees" },
		{ _field_real, "grenade angle max elevation:degrees" },
		{ _field_real, "grenade angle min elevation:degrees" },

		{ _field_real, "grenade velocity:world units per second" },
		{ _field_custom },

		{ _field_version_greater, _engine_type_haloreach, 6 },
		{ _field_custom, "sprinting grenade throw" },
		{ _field_real, "grenade angle (sprinting):degrees" },
		{ _field_real, "grenade angle max elevation (sprinting):degrees" },
		{ _field_real, "grenade angle min elevation (sprinting):degrees" },
		{ _field_real, "grenade velocity (sprinting):world units per second" },
		{ _field_custom },

		{ _field_version_greater, _engine_type_haloreach, 6 },
		{ _field_custom, "primary weapon toss" },
		{ _field_real, "weapon angle:degrees" },
		{ _field_real, "weapon angle max elevation:degrees" },
		{ _field_real, "weapon angle min elevation:degrees" },
		{ _field_real, "weapon velocity:world units per second" },
		{ _field_custom },

		{ _field_enum, "grenade type", &global_grenade_type_enum },
		{ _field_short_integer, "grenade count" },
		{ _field_block, "powered seats", &powered_seat_block_block },
		{ _field_block, "weapons", &unit_weapon_block_block },

		{ _field_version_greater_or_equal, _engine_type_haloreach, 1 },
		{ _field_block, "target tracking", &global_target_tracking_parameters_block_block },

		{ _field_block, "seats", &unit_seat_block_block },
		{ _field_custom, "open/close" },

		{ _field_version_greater_or_equal, _engine_type_haloreach, 2 },
		{ _field_real, "opening time:s#how long the unit takes to open when the hs_function unit_open is called\nThe current open state can be retrieved from the object function unit_open" },
		{ _field_real, "closing time:s#you don\'t have to go home, but you can\'t stay here" },

		{ _field_custom },
		{ _field_custom, "EMP Disabling" },
		{ _field_real, "emp disabled time:seconds" },

		{ _field_version_greater, _engine_type_haloreach },
		{ _field_real, "emp disabled time (PVP):seconds #Set to -1 for not disabled in MP but disabled in SP" },

		{ _field_tag_reference, "emp disabled effect", &global_effect_reference },
		{ _field_custom },
		{ _field_custom, "Boost" },
		{ _field_struct, "boost", &unit_boost_struct_struct_definition },
		{ _field_custom },
		{ _field_explanation, "Lipsync", "" },
		{ _field_struct, "lipsync", &unit_lipsync_scales_struct_struct_definition },
		{ _field_explanation, "Exit and Detach", "" },
		{ _field_tag_reference, "exit and detach damage", &global_damage_reference },
		{ _field_tag_reference, "exit and detach weapon", &global_weapon_reference },
		{ _field_explanation, "Experience", "" },

		{ _field_version_greater, _engine_type_haloreach, 9 },
		{ _field_short_integer, "experience for kill" },
		{ _field_short_integer, "experience for assist" },
		{ _field_tag_reference, "hero assist equipment#this is where you stick an equipment that the biped will always have, to implement the bizarrely named hero assist", &global_equipment_reference },
		{ _field_real, "bailout threshold:wu/s#the speed above which units will bail out of a vehicle instead of just exiting" },
		{ _field_custom },
		{ _field_real_fraction, "iron sight weapon dampening:(0-1)#when using iron sights, how much to scale the weapon overlays to steady the gun (0 = rock steady, 1= no dampening)" },
		{ _field_custom, "Birthing" },
		{ _field_struct, "birth", &unit_birth_struct_struct_definition },
		{ _field_custom },

		{ _field_terminator }
	};


	TAG_BLOCK(halo3_unit_camera_struct_unknown, 0x10000u)
	{
		{_field_terminator}
	};

	TAG_STRUCT(unit_camera_struct)
	{
		{ _field_custom, "Unit Camera" },
		{ _field_word_flags, "flags", &unit_camera_flags_definition },
		{ _field_pad, "doh", 2 },
		{ _field_custom },

		{ _field_old_string_id, "camera marker name" },

		{ _field_version_less, _engine_type_haloreach, 1 },
		{ _field_old_string_id, "camera submerged marker name" },

		{ _field_angle, "pitch auto-level" },
		{ _field_angle_bounds, "pitch range" },
		{ _field_block, "camera tracks", &unit_camera_track_block_block },
		{ _field_angle, "pitch minimum spring" },
		{ _field_angle, "pitch mmaximum spring" },
		{ _field_angle, "spring velocity" },


		{ _field_version_less, _engine_type_haloreach, 1 },
		{ _field_block, "unknown@", &halo3_unit_camera_struct_unknown_block },

		{ _field_version_greater_or_equal, _engine_type_haloreach, 8 },
		{ _field_angle, "look acceleration:deg/s/s#if non-zero, limits the change in look velocity per second while the user is pushing the look stick in the current direction of looking" },
		{ _field_angle, "look deceleration:deg/s/s#if non-zero, limits the change in look velocity per second while the user is not pushing the look stick or changing directions" },
		{ _field_real_fraction, "look acc smoothing fraction#if non-zero, when the desired velocity change is less than this fraction of the acceleration, starts interpolating the maximum acceleration towards zero.\nYou can think of this as a time in seconds where if the velocity would reach its target in this amount of time or less, it will start taking longer." },
		{ _field_angle, "override fov#if non-zero, overrides the FOV set in the unit or globals" },
		{ _field_struct, "camera obstruction", &camera_obstruction_struct_struct_definition },
		{ _field_block, "camera acceleration", &unit_camera_acceleration_displacement_block_block },
		{ _field_block, "move stick overrides", &gamepad_stick_info_block_block },
		{ _field_block, "look stick overrides", &gamepad_stick_info_block_block },

		{ _field_custom },
		{ _field_terminator }
	};

	TAG_STRUCT(unit_camera_acceleration_displacement_function_struct)
	{
		{ _field_char_enum, "Input Variable", &unit_camera_acceleration_displacement_input },
		{ _field_pad, "blah", 3 },
		{ _field_custom },
		{ _field_struct, "mapping", &mapping_function_struct_definition },
		{ _field_real, "maximum value#for linear velocity; this is wu/s\nfor linear acceleration; this is the fraction of the seat acceleration\nfor angular velocity; this is deg/s" },
		{ _field_real, "camera scale (axial)#scale factor used when this acceleration component is along the axis of the forward vector of the camera" },
		{ _field_real, "camera scale (perpendicular)#scale factor used when this acceleration component is perpendicular to the camera" },
		{ _field_terminator }
	};

	TAG_STRUCT(unit_additional_node_names_struct)
	{
		{ _field_string_id, "preferred_gun_node#if found, use this gun marker" },
		{ _field_custom },
		{ _field_version_greater_or_equal, _engine_type_haloreach, 1 },
		{ _field_string_id, "preferred_grenade_marker#if found, use this marker to attach live grenades to" },
		{ _field_explanation, "Weapon Specific Markers", "These will override the righthand/lefthand nodes when the weapon matches the one used by the unit" },

		{ _field_version_greater, _engine_type_haloreach },
		{ _field_block, "weapon specific markers", &WeaponSpecificMarkersBlock_block },

		{ _field_terminator }
	};

	TAG_STRUCT(unit_boarding_melee_struct)
	{
		{ _field_tag_reference, "boarding melee damage", &global_damage_reference },
		{ _field_tag_reference, "boarding melee response", &global_damage_reference },
		{ _field_tag_reference, "eviction melee damage", &global_damage_reference },
		{ _field_tag_reference, "eviction melee response", &global_damage_reference },
		{ _field_tag_reference, "landing melee damage", &global_damage_reference },
		{ _field_tag_reference, "flurry melee damage", &global_damage_reference },
		{ _field_tag_reference, "obstacle smash damage", &global_damage_reference },

		{ _field_version_equal, _engine_type_haloreach, 1 },
		{ _field_tag_reference, "shield pop melee damage", &global_damage_reference },


		{ _field_version_equal, _engine_type_haloreach, 1 },
		{ _field_tag_reference, "assassination damage", &global_damage_reference },

		{ _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_tag_reference, "assassination primary damage", &global_damage_reference },
		{ _field_tag_reference, "assassination ragdoll damage{assassination damage}", &global_damage_reference },

		{ _field_terminator }
	};

	TAG_STRUCT(unit_boost_struct)
	{
		{ _field_tag_reference, "boost collision damage", &collision_damage_reference$2 },

		{ _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_long_flags, "flags", &boost_flags },

		{ _field_real, "boost peak power" },

		{ _field_version_greater_or_equal, _engine_type_haloreach, 3 },
		{ _field_real, "boost rise time:s#if the trigger is fully down, takes this long to reach peak power" },
		{ _field_real, "boost fall time:s#if the trigger is let go (or peak time expires), takes this long to reach 0 power" },
		{ _field_real, "boost power per second#1, means you burn all your power in one sec.  .1 means you can boost for 10 seconds." },

		{ _field_version_greater, _engine_type_haloreach },
		{ _field_real, "boost low warning threshold" },

		{ _field_version_less, _engine_type_haloreach, 4 }, // want sure if/how to fit these against new definition
		{ _field_real, "boost peak power" },	// assembly
		{ _field_real, "boost rise power" },	// assembly
		{ _field_real, "boost peak time" },		// assembly
		{ _field_real, "boost fall power" },	// assembly

		{ _field_version_greater_or_equal, _engine_type_haloreach, 4 },
		{ _field_real, "recharge rate#1 means you recharge fully in 1 second.  .1 means you rechage fully in 10 seconds" },
		{ _field_real, "recharge delay:s#how long do you have to be off the tirgger for before boost starts recharging" },
		{ _field_custom },
		{ _field_struct, "trigger to boost", &mapping_function_struct_definition },

		{ _field_terminator }
	};

	TAG_STRUCT(unit_lipsync_scales_struct)
	{
		{ _field_real_fraction, "attack weight" },
		{ _field_real_fraction, "decay weight" },
		{ _field_terminator }
	};

	TAG_STRUCT(unit_birth_struct)
	{
		{ _field_short_block_index, "seat^" },
		{ _field_pad, "PAD", 2 },
		{ _field_string_id, "birthing region#if found, this region will be set to destroyed during birth" },
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

} // namespace blofeld

