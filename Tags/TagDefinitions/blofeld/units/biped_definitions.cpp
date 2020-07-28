#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_INHERIT_FROM_BLOCK(biped, BIPED_TAG, unit, UNIT_TAG, biped_block_block );

	TAG_BLOCK(biped_camera_height_block, 16)
	{
		{ _field_string_id, "weapon class^" },
		{ _field_real, "standing height:wu" },
		{ _field_real, "crouching height:wu" },
		{ _field_terminator }
	};

	TAG_BLOCK(biped_wall_proximity_block, k_maximum_biped_proximity_feelers)
	{
		{ _field_custom },
		{ _field_string_id, "marker name^" },
		{ _field_real, "search distance:wu" },
		{ _field_real, "compression time:s" },
		{ _field_real, "extension time:s" },
		{ _field_long_enum, "composition mode#if multiple markers share the same name, this specifies how to compose their search values", &biped_wall_proximity_composition_mode },
		{ _field_string_id, "output function name#creates an object function with this name that you can use to drive an overlay animation" },
		{ _field_terminator }
	};

	TAG_BLOCK(biped_movement_gate_block, 16)
	{
		{ _field_real, "period:seconds" },
		{ _field_real, "z offset:world units" },
		{ _field_real, "constant z offset:world units#camera z is modified by this constant z value" },
		{ _field_real, "y offset:world units" },
		{ _field_real, "speed threshold:world units per second" },
		{ _field_custom },
		{ _field_struct, "default function", &mapping_function_struct_definition },
		{ _field_terminator }
	};

	TAG_BLOCK(contact_point_block, k_contact_point_count)
	{
		{ _field_useless_pad },
		{ _field_custom },
		{ _field_old_string_id, "marker name^" },
		{ _field_terminator }
	};

	TAG_BLOCK(biped_grab_object_animation_set_block, k_max_biped_grab_object_animation_sets)
	{
		{ _field_string_id, "animation set name^" },
		{ _field_string_id, "attach marker#The marker on the biped to which we attach the grabbed object." },
		{ _field_real, "throw speed" },
		{ _field_terminator }
	};

	TAG_BLOCK(BipedSoundRTPCBlock, k_maxBipedSoundRTPCBlocks)
	{
		{ _field_long_block_index, "Attachment Index#Sound attachment to affect - leave empty for main body" },
		{ _field_string_id, "Function#Function to drive the RTPC" },
		{ _field_string_id, "RTPC Name#WWise RTPC string name" },
		{ _field_terminator }
	};

	TAG_BLOCK(BipedSoundSweetenerBlock, k_maxBipedSoundSweetenerBlocks)
	{
		{ _field_string_id, "Function#Function to trigger the sweetener" },
		{ _field_tag_reference, "sound", &global_sound_reference },
		{ _field_real, "Switch point#value of the function (between 0 and 1) where the sound is triggered" },
		{ _field_long_integer, "Mode#0 for triggering while function is decreasing, 1 for increasing (more modes to come\?)" },
		{ _field_terminator }
	};

	TAG_BLOCK(BipedAimingJointFixupBlock, k_maximum_aiming_fixup_joints)
	{
		{ _field_string_id, "rotation_node^:bone to rotate to align marker" },
		{ _field_custom },
		{ _field_string_id, "marker name^" },
		{ _field_angle_bounds, "yaw bounds:degrees" },
		{ _field_angle_bounds, "pitch bounds:degrees" },
		{ _field_real, "max yaw velocity:degrees per second" },
		{ _field_real, "max pitch velocity:degrees per second" },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(biped_block, 1, biped_group_struct_definition );

	TAG_STRUCT(biped_group)
	{
		{ _field_struct, "unit", &unit_struct_definition_struct_definition },
		{ _field_custom, "$$$ BIPED $$$" },
		{ _field_angle, "moving turning speed:degrees per second" },
		{ _field_long_flags, "flags", &biped_definition_flags },
		{ _field_angle, "stationary turning threshold" },
		{ _field_useless_pad },
		{ _field_useless_pad },

		{ _field_version_greater_or_equal, _engine_type_haloreach, 3 },
		{ _field_tag_reference, "death program selector", &death_program_selector_reference },
		{ _field_string_id, "ragdoll region name#when the biped transitions to ragdoll, this region will change to the destroyed state" },
		{ _field_string_id, "assassination chud text#The string id for the assassination action text in the CHUD" },

		{ _field_explanation, "jumping and landing", "" },
		{ _field_real, "jump velocity:world units per second" },

		{ _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_block, "tricks", &unit_trick_definition_block_block },

		// #TODO: This is assumed to be a tag block. Assert on these values and check if they are non zero
		{ _field_version_equal, _engine_type_haloreach, 3 },
		{ _field_long_integer, "unknown@" }, // assembly
		{ _field_long_integer, "unknown@" }, // assembly
		{ _field_long_integer, "unknown@" }, // assembly

		{ _field_useless_pad },
		{ _field_real, "maximum soft landing time:seconds#the longest amount of time the biped can take to recover from a soft landing" },
		{ _field_real, "maximum hard landing time:seconds#the longest amount of time the biped can take to recover from a hard landing" },
		{ _field_real, "minimum soft landing velocity:world units per second#below this velocity the biped does not react when landing" },
		{ _field_real, "minimum hard landing velocity:world units per second#below this velocity the biped will not do a soft landing when returning to the ground" },
		{ _field_real, "maximum hard landing velocity:world units per second#the velocity corresponding to the maximum landing time" },

		{ _field_version_less, _engine_type_haloreach },
		{ _field_real, "death hard landing velocity" },

		{ _field_useless_pad },
		{ _field_real, "stun duration#0 is the default.  Bipeds are stunned when damaged by vehicle collisions, also some are when they take emp damage" },
		{ _field_explanation, "camera, collision, and autoaim", "" },
		{ _field_real, "standing camera height:world units" },

		{ _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_real, "running camera height:world units" },

		{ _field_real, "crouching camera height:world units" },

		{ _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_real, "crouch walking camera height:world units" },

		{ _field_real, "crouch transition time:seconds" },

		{ _field_version_greater_or_equal, _engine_type_haloreach, 3 },
		{ _field_custom },
		{ _field_struct, "camera height velocity function", &mapping_function_struct_definition },
		{ _field_block, "camera heights", &biped_camera_height_block_block },

		{ _field_angle, "camera interpolation start:degrees#looking-downward angle that starts camera interpolation to fp position" },
		{ _field_angle, "camera interpolation end:degrees#looking-downward angle at which camera interpolation to fp position is complete" },
		{ _field_real_vector_3d, "camera offset:wu#amount of fp camera movement in (forward, right, down) when pitched down by \'camera interpolation end\' above" },

		{ _field_version_less, _engine_type_haloreach }, //h2ek
		{ _field_real, "camera exclusion distance" },

		{ _field_version_greater_or_equal, _engine_type_haloreach, 2 },
		{ _field_real, "root offset camera scale" },
		{ _field_real, "root offset camera dampening" },

		{ _field_real, "autoaim width:world units" },

		{ _field_version_less, _engine_type_haloreach, 2 }, // h2ek / assembly
		{ _field_long_flags, "lock-on flags", &biped_lock_on_flags_definition },
		{ _field_real, "lock-on distance" },

		{ _field_short_integer, "runtime physics control node index!" },
		{ _field_pad, "JWSSY", 2 },
		{ _field_real, "runtime cosine stationary turning threshold!" },
		{ _field_real, "runtime crouch transition velocity!*" },

		{ _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_real, "runtime_camera_height_velocity!*" },

		{ _field_short_integer, "runtime pelvis node index!" },
		{ _field_short_integer, "runtime head node index!" },
		{ _field_useless_pad },

		{ _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_block, "wall proximity feelers", &biped_wall_proximity_block_block },

		{ _field_version_less, _engine_type_haloreach },
		{ _field_real, "headshot acceleration scale" },

		{ _field_tag_reference, "area damage effect", &global_effect_reference },

		{ _field_version_greater_or_equal, _engine_type_haloreach, 9 },
		{ _field_tag_reference, "health station recharge effect", &global_effect_reference },
		{ _field_block, "movement gates", &biped_movement_gate_block_block },
		{ _field_block, "movement gates crouching", &biped_movement_gate_block_block },
		{ _field_real, "jump aim offset distance:world units" },
		{ _field_real, "jump aim offset duration:seconds" },
		{ _field_real, "land aim offset distance:world units" },
		{ _field_real, "land aim offset duration:seconds" },
		{ _field_real, "aim compensate minimum distance:world units" },
		{ _field_real, "aim compensate maximum distance:world units" },

		{ _field_struct, "physics", &character_physics_struct_struct_definition },
		{ _field_block, "contact points#these are the points where the biped touches the ground", &contact_point_block_block },
		{ _field_tag_reference, "reanimation character#when the flood reanimate this guy, he turns into a ...", &character_reference$2 },
		{ _field_tag_reference, "reanimation/morph muffins#the kind of muffins I create to cover my horrible transformation", &muffin_reference },
		{ _field_tag_reference, "death spawn character#when I die, out of the ashes of my death crawls a ...", &character_reference$2 },
		{ _field_short_integer, "death spawn count" },
		{ _field_pad, "TQYQEWG", 2 },
		{ _field_struct, "leaping data", &biped_leaping_data_struct_struct_definition },

		{ _field_version_greater, _engine_type_haloreach, 3 },
		{ _field_struct, "vaulting data", &biped_vaulting_data_struct_struct_definition },
		{ _field_struct, "grab biped data", &biped_grab_biped_data_struct_struct_definition },
		{ _field_struct, "grab object data", &biped_grab_object_data_struct_struct_definition },

		{ _field_struct, "ground fitting data", &biped_ground_fitting_data_struct_struct_definition },

		{ _field_version_greater, _engine_type_haloreach, 15 },
		{ _field_tag_reference, "death particleize#optional particleization effect definition, if you want this to particleize when it dies", &global_particleize_parameters_reference },
		{ _field_real, "movement speed scale" },
		{ _field_struct, "movement hip lean", &BipedMovementHipLeaningStruct_struct_definition },
		{ _field_custom },
		{ _field_tag_reference, "Player biped sound bank#Intended for biped vehicles (ie mantis)", &global_soundbank_reference },
		{ _field_tag_reference, "RegenField Looping Sound#plays when player is inside a RegenField", &global_looping_sound_reference },
		{ _field_tag_reference, "Crouch down sound#plays when player starts crouching", &global_sound_reference },
		{ _field_tag_reference, "Crouch up sound#plays when player stands up", &global_sound_reference },
		{ _field_tag_reference, "Shield impact override#overrides shield impact sound, like when in a Mantis", &global_sound_reference },
		{ _field_tag_reference, "Non shield impact override#overrides regular impact sound, like when in a Mantis", &global_sound_reference },
		{ _field_real, "Sound radius multiplier#increases radius of other sounds when piloting this biped (mech)" },
		{ _field_block, "Sound RTPCs", &BipedSoundRTPCBlock_block },
		{ _field_block, "Sound Sweeteners", &BipedSoundSweetenerBlock_block },
		{ _field_block, "Aiming Fixup", &BipedAimingJointFixupBlock_block },
		{ _field_tag_reference, "Self Illumination", &self_illumination_reference },

		{ _field_terminator }
	};

	TAG_STRUCT(biped_leaping_data_struct)
	{
		{ _field_custom, "wall-leaping" },
		{ _field_explanation, "wall-leaping fields", "" },
		{ _field_long_flags, "leap flags", &biped_leap_flags_definition },
		{ _field_real_fraction, "dampening scale:[0,1] 1= very slow changes" },
		{ _field_real_fraction, "roll delay:[0,1] 1= roll fast and late" },
		{ _field_real_fraction, "cannonball off-axis scale:[0,1] weight" },
		{ _field_real_fraction, "cannonball off-track scale:[0,1] weight" },
		{ _field_angle_bounds, "cannonball roll bounds:degrees per second" },
		{ _field_real_bounds, "anticipation ratio bounds:current velocity/leap velocity" },
		{ _field_real_bounds, "reaction force bounds:units per second" },
		{ _field_real_fraction, "lobbing desire:1= heavy arc, 0= no arc" },
		{ _field_custom },
		{ _field_terminator }
	};

	TAG_STRUCT(biped_vaulting_data_struct)
	{
		{ _field_custom, "vaulting" },
		{ _field_explanation, "vaulting fields", "The cost of the vault check is scaled by max horizontal distance divided by min object size.  Try to keep that number reasonably low." },
		{ _field_real_bounds, "vault height bounds:wus" },
		{ _field_real, "vault max horizontal distance:wus" },
		{ _field_real_fraction, "vault arc amount:1= heavy arc, 0= no arc" },
		{ _field_real, "vault min object size:wus" },
		{ _field_real, "search width:wus, the side-to-side width of the search path" },
		{ _field_custom },
		{ _field_terminator }
	};

	TAG_STRUCT(biped_grab_biped_data_struct)
	{
		{ _field_custom, "grab biped" },
		{ _field_explanation, "grab biped fields", "Allows a biped to grab and be grabbed by other bipeds." },
		{ _field_string_id, "grab biped animation class" },
		{ _field_char_enum, "throw biped control mode", &grab_biped_throw_control_modes },
		{ _field_pad, "hurgh", 3 },
		{ _field_custom },
		{ _field_terminator }
	};

	TAG_STRUCT(biped_grab_object_data_struct)
	{
		{ _field_custom, "grab object" },
		{ _field_explanation, "grab object fields", "Allows a biped to grab and throw crate objects." },
		{ _field_block, "grab object animation sets", &biped_grab_object_animation_set_block_block },
		{ _field_custom },
		{ _field_terminator }
	};

	TAG_STRUCT(biped_ground_fitting_data_struct)
	{
		{ _field_custom, "ground fitting" },
		{ _field_explanation, "ground fitting data", "" },

		{ _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_long_flags, "ground fitting flags", &biped_ground_fitting_flags_definition },

		{ _field_real_fraction, "ground normal dampening:react to slope changes (0=slow, 1= fast)" },
		{ _field_real, "root offset max scale idle{root offset max scale}:vertical drop to ground allowed (0=none, 1=full)" },
		{ _field_real, "root offset max scale moving:vertical drop to ground allowed (0=none, 1=full)" },

		{ _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_real_fraction, "root offset dampening:react to root changes (0=slow, 1= fast)" },

		{ _field_real_fraction, "following cam scale:root offset effect on following cam (0=none, 1=full)" },
		{ _field_real_fraction, "root leaning scale:lean into slopes (0=none, 1=full)" },

		{ _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_real, "stance width scale:scale pill width to use as stance radius" },

		{ _field_angle, "foot roll max:orient to ground slope (degrees)" },
		{ _field_angle, "foot pitch max:orient to ground slope (degrees)" },

		{ _field_version_greater_or_equal, _engine_type_haloreach, 13 },
		{ _field_real_fraction, "foot normal dampening:(0=slow, 1= fast)" },
		{ _field_real, "foot fitting test distance" },
		{ _field_real_fraction, "foot displacement upward dampening:(0=slow, 1= fast)" },
		{ _field_real_fraction, "foot displacement downward dampening:(0=slow, 1= fast)" },
		{ _field_real, "foot pull threshold distance idle:amount past the authored plane the foot can be pulled (wu)" },
		{ _field_real, "foot pull threshold distance moving:amount past the authored plane the foot can be pulled (wu)" },
		{ _field_real, "foot turn minimum radius:minimum radius at which foot is fit to turn radius" },
		{ _field_real, "foot turn maximum radius:maximum radius at which foot is fit to turn radius" },
		{ _field_real, "foot turn threshold radius:foot is fit to turn radius fully at minimum plus threshold and above" },
		{ _field_real, "foot turn rate dampening:(0=slow, 1=fast)" },
		{ _field_real, "foot turn weight dampening:dampening of fitting value for fit to turn radius(0=none, 1=fast)" },
		{ _field_real, "foot turn blend on time:time to blend on the foot turn effect (seconds)" },
		{ _field_real, "foot turn blend off time:time to blend off the foot turn effect (seconds)" },

		{ _field_version_equal, _engine_type_haloreach, 2 },
		{ _field_real, "unknown@" },
		{ _field_real, "unknown@" },

		{ _field_custom },
		{ _field_custom, "pivot-on-foot" },
		{ _field_explanation, "pivot-on-foot data", "" },
		{ _field_real_fraction, "pivot-on-foot scale: (0=none, 1= full)" },
		{ _field_real, "pivot min foot delta: vert world units to find lowest foot" },
		{ _field_real, "pivot stride length scale: leg length * this = stride length" },
		{ _field_real_fraction, "pivot throttle scale:pivoting slows throttle (0=none, 1= full)" },
		{ _field_real_fraction, "pivot offset dampening:react to pivot changes (0=slow, 1= fast)" },

		{ _field_version_greater, _engine_type_haloreach, 18 },

		{ _field_real_fraction, "pivot force turn rate:turn no matter what the pivot state is (0=control turn, 1= always turn)" },
		{ _field_custom },
		{ _field_custom, "Ground fitting pelvis elevation settings" },
		{ _field_real, "ideal pelvis over high foot scale: ratio of pedestal to pelvis distance #ideal ratio of distance from the pelvis to pedestal to place pelvis over the highest foot" },
		{ _field_real, "ideal pelvis over low foot scale: ratio of pedestal to pelvis distance #ideal ratio of distance from the pelvis to pedestal to place pelvis over the lowest foot" },
		{ _field_custom },
		{ _field_custom, "Ledge Push" },
		{ _field_explanation, "Pushing over Ledges", "When a locked foot is unsupported, meaning it can\'t reach the ground, the biped is considered to be hanging over a ledge. You can provide a velocity that will either push the character over the ledge or away from it" },
		{ _field_real, "push over mag: magnitude of throttle to push over ledges. 0= no push" },
		{ _field_real, "push back mag: magnitude of throttle to push back from ledges. 0= no push" },
		{ _field_real, "ledgeIKSuccessRange: when unable to IK at least this close, consider the IK failed." },
		{ _field_real, "ledge warning time: secs to warn the player before pushing over a ledge" },
		{ _field_custom },
		{ _field_custom, "Foot locking" },
		{ _field_real, "footlock Scale: (0-1) #how much this biped respects foot lock events" },
		{ _field_real, "footlock Min Throttle: (0-1) #throttle at which foot lock should be fully on (footlockScale)" },
		{ _field_real, "footlock Max Throttle: (0-1) #throttle at which foot lock should be fully off" },
		{ _field_custom },
		{ _field_terminator }
	};

	TAG_STRUCT(BipedMovementHipLeaningStruct)
	{
		{ _field_custom, "Movement Hip Leaning" },
		{ _field_explanation, "Movement Hip Leaning", "Allows a biped to lean based on movement." },
		{ _field_real, "prediction seconds:predict ahead to determine lean. 0= off, more time=more lean" },
		{ _field_real, "max lean angle:(degrees) maximum lean amount" },
		{ _field_real_fraction, "max vertical dip:(fraction of leg length)" },
		{ _field_real, "max lean angle sine:set on post-process, don\'t edit!*" },
		{ _field_real, "max lean angle cosine:set on post-process, don\'t edit!*" },
		{ _field_custom },
		{ _field_terminator }
	};

	STRINGS(biped_definition_flags)
	{
		"turns without animating",
		"has physical rigid bodies when alive",
		"immune to falling damage",
		"has animated jetpack",
		"unused1!",
		"unused2!",
		"random speed increase",
		"unused3!",
		"spawn death children on destroy",
		"stunned by emp damage",
		"dead physics when stunned",
		"always ragdoll when dead",
		"snaps turns",
		"sync action always projects on ground",
		"orient facing to movement (Mantis)"
	};
	STRING_LIST(biped_definition_flags, biped_definition_flags_strings, _countof(biped_definition_flags_strings));

	STRINGS(biped_leap_flags_definition)
	{
		"force early roll"
	};
	STRING_LIST(biped_leap_flags_definition, biped_leap_flags_definition_strings, _countof(biped_leap_flags_definition_strings));

	STRINGS(grab_biped_throw_control_modes)
	{
		"camera facing",
		"control stick direction"
	};
	STRING_LIST(grab_biped_throw_control_modes, grab_biped_throw_control_modes_strings, _countof(grab_biped_throw_control_modes_strings));

	STRINGS(biped_ground_fitting_flags_definition)
	{
		"foot fixup enabled",
		"root offset enabled",
		"free foot enabled:deprecated#deprecated",
		"z leg enabled",
		"foot pull pinned",
		"footlock adjusts root:deprecated#deprecated",
		"raycast vehicles#slow",
		"foot fixup on composites:deprecated#deprecated",
		"allow feet below grade#noramlly, we will force the feet to lock to the ground surface",
		"use biped up direction#for characters that climb walls",
		"snap marker above contact#prevents ground marker from going below the contact point"
	};
	STRING_LIST(biped_ground_fitting_flags_definition, biped_ground_fitting_flags_definition_strings, _countof(biped_ground_fitting_flags_definition_strings));

	STRINGS(biped_wall_proximity_composition_mode)
	{
		"most compressed#pick the marker that has the closest obstacle",
		"least compressed#pick the marker that has the furthest obstacle",
		"average#average the distances from each marker"
	};
	STRING_LIST(biped_wall_proximity_composition_mode, biped_wall_proximity_composition_mode_strings, _countof(biped_wall_proximity_composition_mode_strings));

	STRINGS(biped_lock_on_flags_definition)
	{
		"locked by human targeting",
		"locked by plasma targeting",
		"always locked by human targeting" // could be plasma, based on assembly; but h2ek is plasma
	};
	STRING_LIST(biped_lock_on_flags_definition, biped_lock_on_flags_definition_strings, _countof(biped_lock_on_flags_definition_strings));

} // namespace blofeld

