#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		biped_group,
		BIPED_TAG,
		&unit_group,
		UNIT_TAG,
		biped_block );

	TAG_BLOCK_FROM_STRUCT(
		biped_block,
		"biped",
		1,
		biped_struct_definition);

	#define BIPED_CAMERA_HEIGHT_BLOCK_ID { 0x5E996FBA, 0xD7CD4C2A, 0x893DD1ED, 0x4E4058FF }
	TAG_BLOCK(
		biped_camera_height_block,
		"biped_camera_height_block",
		16,
		"s_biped_camera_height",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		BIPED_CAMERA_HEIGHT_BLOCK_ID)
	{
		{ _field_string_id, "weapon class", FIELD_FLAG_INDEX },
		{ _field_real, "standing height", nullptr, "wu" },
		{ _field_real, "crouching height", nullptr, "wu" },
		{ _field_terminator }
	};

	#define BIPED_WALL_PROXIMITY_BLOCK_ID { 0x6ADD7B21, 0x29074976, 0x83B082B3, 0x4DB6C6A1 }
	TAG_BLOCK(
		biped_wall_proximity_block,
		"biped_wall_proximity_block",
		k_maximum_biped_proximity_feelers,
		"s_biped_wall_proximity_feeler",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		BIPED_WALL_PROXIMITY_BLOCK_ID)
	{
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_marker),
		{ _field_string_id, "marker name", FIELD_FLAG_INDEX },
		{ _field_real, "search distance", nullptr, "wu" },
		{ _field_real, "compression time", nullptr, "s" },
		{ _field_real, "extension time", nullptr, "s" },
		{ _field_long_enum, "composition mode", "if multiple markers share the same name, this specifies how to compose their search values", &biped_wall_proximity_composition_mode },
		{ _field_string_id, "output function name", "creates an object function with this name that you can use to drive an overlay animation" },
		{ _field_terminator }
	};

	#define BIPED_MOVEMENT_GATE_BLOCK_ID { 0xE1AABC0A, 0x4127B5EF, 0xA2BF1821, 0xAEC9C18A }
	TAG_BLOCK(
		biped_movement_gate_block,
		"biped_movement_gate_block",
		16,
		"s_biped_movement_gate",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		BIPED_MOVEMENT_GATE_BLOCK_ID)
	{
		{ _field_real, "period", nullptr, "seconds" },
		{ _field_real, "z offset", nullptr, "world units" },
		{ _field_real, "constant z offset", "camera z is modified by this constant z value", "world units" },
		{ _field_real, "y offset", nullptr, "world units" },
		{ _field_real, "speed threshold", nullptr, "world units per second" },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_default),
		{ _field_struct, "default function", &mapping_function },
		{ _field_terminator }
	};

	#define CONTACT_POINT_BLOCK_ID { 0x0EE23ED8, 0x815D4570, 0x855B29FD, 0xF4A4104A }
	TAG_BLOCK(
		contact_point_block,
		"contact_point_block",
		k_contact_point_count,
		"biped_contact_point",
		SET_UNKNOWN0 | SET_UNKNOWN3 | SET_UNKNOWN4 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CONTACT_POINT_BLOCK_ID)
	{
		{ _field_useless_pad, "" },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_marker),
		{ _field_old_string_id, "marker name", FIELD_FLAG_INDEX },
		{ _field_terminator }
	};

	#define BIPED_GRAB_OBJECT_ANIMATION_SET_BLOCK_ID { 0x780145CA, 0xEE214EE8, 0xB1227279, 0x52CBFAA5 }
	TAG_BLOCK(
		biped_grab_object_animation_set_block,
		"biped_grab_object_animation_set_block",
		k_max_biped_grab_object_animation_sets,
		"s_biped_grab_object_animation_set",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		BIPED_GRAB_OBJECT_ANIMATION_SET_BLOCK_ID)
	{
		{ _field_string_id, "animation set name", FIELD_FLAG_INDEX },
		{ _field_string_id, "attach marker", "The marker on the biped to which we attach the grabbed object." },
		{ _field_real, "throw speed" },
		{ _field_terminator }
	};

	#define BIPEDSOUNDRTPCBLOCK_ID { 0x8FE0C5DC, 0x1A32451A, 0x9C2DE06C, 0x44EC2C23 }
	TAG_BLOCK(
		BipedSoundRTPCBlock_block,
		"BipedSoundRTPCBlock",
		k_maxBipedSoundRTPCBlocks,
		"BipedSoundRTPCBlockDefinition",
		SET_UNKNOWN0 | SET_POSTPROCESS_RECURSIVELY | SET_IS_MEMCPYABLE | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		BIPEDSOUNDRTPCBLOCK_ID)
	{
		{ _field_long_block_index, "Attachment Index", "Sound attachment to affect - leave empty for main body", &global_object_attachment_block },
		{ _field_string_id, "Function", "Function to drive the RTPC" },
		{ _field_string_id, "RTPC Name", "WWise RTPC string name" },
		{ _field_terminator }
	};

	#define BIPEDSOUNDSWEETENERBLOCK_ID { 0x1E90D57C, 0xEB4945F3, 0x9158FCF1, 0x3B53CA73 }
	TAG_BLOCK(
		BipedSoundSweetenerBlock_block,
		"BipedSoundSweetenerBlock",
		k_maxBipedSoundSweetenerBlocks,
		"BipedSoundSweetenerBlockDefinition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		BIPEDSOUNDSWEETENERBLOCK_ID)
	{
		{ _field_string_id, "Function", "Function to trigger the sweetener" },
		{ _field_tag_reference, "sound", &global_sound_reference },
		{ _field_real, "Switch point", "value of the function (between 0 and 1) where the sound is triggered" },
		{ _field_long_integer, "Mode", "0 for triggering while function is decreasing, 1 for increasing (more modes to come?)" },
		{ _field_terminator }
	};

	#define BIPEDAIMINGJOINTFIXUPBLOCK_ID { 0xABDDE304, 0x116F4CA8, 0x908F407E, 0x115097A5 }
	TAG_BLOCK(
		BipedAimingJointFixupBlock_block,
		"BipedAimingJointFixupBlock",
		k_maximum_aiming_fixup_joints,
		"BipedAimingJointFixup",
		SET_UNKNOWN0 | SET_POSTPROCESS_RECURSIVELY | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		BIPEDAIMINGJOINTFIXUPBLOCK_ID)
	{
		{ _field_string_id, "rotation_node", nullptr, "bone to rotate to align marker", FIELD_FLAG_INDEX },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_marker),
		{ _field_string_id, "marker name", FIELD_FLAG_INDEX },
		{ _field_angle_bounds, "yaw bounds", nullptr, "degrees" },
		{ _field_angle_bounds, "pitch bounds", nullptr, "degrees" },
		{ _field_real, "max yaw velocity", nullptr, "degrees per second" },
		{ _field_real, "max pitch velocity", nullptr, "degrees per second" },
		{ _field_terminator }
	};

	#define BIPED_STRUCT_DEFINITION_ID { 0x6855591D, 0xC7A2477E, 0xBB97CD08, 0xE97A8C61 }
	TAG_STRUCT(
		biped_struct_definition,
		"biped",
		"biped_group",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN4 | SET_UNKNOWN5 | 
		SET_UNKNOWN7 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS | 
		SET_UNKNOWN18,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		BIPED_STRUCT_DEFINITION_ID)
	{
		{ _field_struct, "unit", &unit_struct_definition },
		FIELD_CUSTOM("$$$ BIPED $$$", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_angle, "moving turning speed", nullptr, "degrees per second" },
		{ _field_long_flags, "flags", &biped_definition_flags },
		{ _field_angle, "stationary turning threshold" },
		{ _field_useless_pad, "" },
		{ _field_useless_pad, "" },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach, 3 },
		{ _field_tag_reference, "death program selector", &death_program_selector_reference },
		{ _field_string_id, "ragdoll region name", "when the biped transitions to ragdoll, this region will change to the destroyed state" },
		{ _field_string_id, "assassination chud text", "The string id for the assassination action text in the CHUD" },
		
		FIELD_EXPLANATION("jumping and landing", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real, "jump velocity", nullptr, "world units per second" },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_block, "tricks", &unit_trick_definition_block },

		// #TODO: This is assumed to be a tag block. Assert on these values and check if they are non zero
		{ _field_legacy, _field_version_equal, _engine_type_haloreach, 3 },
		{ _field_legacy, _field_long_integer, "unknown@" }, // assembly
		{ _field_legacy, _field_long_integer, "unknown@" }, // assembly
		{ _field_legacy, _field_long_integer, "unknown@" }, // assembly
		
		{ _field_useless_pad, "" },
		{ _field_real, "maximum soft landing time", "the longest amount of time the biped can take to recover from a soft landing", "seconds" },
		{ _field_real, "maximum hard landing time", "the longest amount of time the biped can take to recover from a hard landing", "seconds" },
		{ _field_real, "minimum soft landing velocity", "below this velocity the biped does not react when landing", "world units per second" },
		{ _field_real, "minimum hard landing velocity", "below this velocity the biped will not do a soft landing when returning to the ground", "world units per second" },
		{ _field_real, "maximum hard landing velocity", "the velocity corresponding to the maximum landing time", "world units per second" },

		{ _field_legacy, _field_version_less, _engine_type_haloreach },
		{ _field_legacy, _field_real, "death hard landing velocity" },
		
		{ _field_useless_pad, "" },
		{ _field_real, "stun duration", "0 is the default.  Bipeds are stunned when damaged by vehicle collisions, also some are when they take emp damage" },
		FIELD_EXPLANATION("camera, collision, and autoaim", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real, "standing camera height", nullptr, "world units" },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_real, "running camera height", nullptr, "world units" },
		
		{ _field_real, "crouching camera height", nullptr, "world units" },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_real, "crouch walking camera height", nullptr, "world units" },
		
		{ _field_real, "crouch transition time", nullptr, "seconds" },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach, 3 },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_default),
		{ _field_struct, "camera height velocity function", &mapping_function },
		{ _field_block, "camera heights", &biped_camera_height_block },
		
		{ _field_angle, "camera interpolation start", "looking-downward angle that starts camera interpolation to fp position", "degrees" },
		{ _field_angle, "camera interpolation end", "looking-downward angle at which camera interpolation to fp position is complete", "degrees" },
		{ _field_real_vector_3d, "camera offset", "amount of fp camera movement in (forward, right, down) when pitched down by 'camera interpolation end' above", "wu" },

		{ _field_legacy, _field_version_less, _engine_type_haloreach }, //h2ek
		{ _field_legacy, _field_real, "camera exclusion distance" },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach, 2 },
		{ _field_real, "root offset camera scale" },
		{ _field_real, "root offset camera dampening" },
		
		{ _field_real, "autoaim width", nullptr, "world units" },

		{ _field_legacy, _field_version_less, _engine_type_haloreach, 2 }, // h2ek / assembly
		{ _field_legacy, _field_long_flags, "lock-on flags", &biped_lock_on_flags_definition },
		{ _field_legacy, _field_real, "lock-on distance" },
		
		{ _field_short_integer, "runtime physics control node index", FIELD_FLAG_UNKNOWN0 },
		FIELD_PAD("JWSSY", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real, "runtime cosine stationary turning threshold", FIELD_FLAG_UNKNOWN0 },
		{ _field_real, "runtime crouch transition velocity", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_real, "runtime_camera_height_velocity", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		
		{ _field_short_integer, "runtime pelvis node index", FIELD_FLAG_UNKNOWN0 },
		{ _field_short_integer, "runtime head node index", FIELD_FLAG_UNKNOWN0 },
		{ _field_useless_pad, "" },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_block, "wall proximity feelers", &biped_wall_proximity_block },

		{ _field_legacy, _field_version_less, _engine_type_haloreach },
		{ _field_legacy, _field_real, "headshot acceleration scale" },
		
		{ _field_tag_reference, "area damage effect", &global_effect_reference },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach, 9 },
		{ _field_tag_reference, "health station recharge effect", &global_effect_reference },
		{ _field_block, "movement gates", &biped_movement_gate_block },
		{ _field_block, "movement gates crouching", &biped_movement_gate_block },
		{ _field_real, "jump aim offset distance", nullptr, "world units" },
		{ _field_real, "jump aim offset duration", nullptr, "seconds" },
		{ _field_real, "land aim offset distance", nullptr, "world units" },
		{ _field_real, "land aim offset duration", nullptr, "seconds" },
		{ _field_real, "aim compensate minimum distance", nullptr, "world units" },
		{ _field_real, "aim compensate maximum distance", nullptr, "world units" },
		
		{ _field_struct, "physics", &character_physics_struct },
		{ _field_block, "contact points", "these are the points where the biped touches the ground", &contact_point_block },
		{ _field_tag_reference, "reanimation character", "when the flood reanimate this guy, he turns into a ...", &character_reference$2 },
		{ _field_tag_reference, "reanimation/morph muffins", "the kind of muffins I create to cover my horrible transformation", &muffin_reference },
		{ _field_tag_reference, "death spawn character", "when I die, out of the ashes of my death crawls a ...", &character_reference$2 },
		{ _field_short_integer, "death spawn count" },
		FIELD_PAD("TQYQEWG", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_struct, "leaping data", &biped_leaping_data_struct },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 3 },
		{ _field_struct, "vaulting data", &biped_vaulting_data_struct },
		{ _field_struct, "grab biped data", &biped_grab_biped_data_struct },
		{ _field_struct, "grab object data", &biped_grab_object_data_struct },
		
		{ _field_struct, "ground fitting data", &biped_ground_fitting_data_struct },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 3 },
		{ _field_tag_reference, "death particleize", "optional particleization effect definition, if you want this to particleize when it dies", &global_particleize_parameters_reference },
		{ _field_real, "movement speed scale" },
		{ _field_struct, "movement hip lean", &BipedMovementHipLeaningStruct },
		
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 11 },
		{ _field_tag_reference, "Player biped sound bank", "Intended for biped vehicles (ie mantis)", &global_soundbank_reference },
		{ _field_tag_reference, "RegenField Looping Sound", "plays when player is inside a RegenField", &global_looping_sound_reference },
		{ _field_tag_reference, "Crouch down sound", "plays when player starts crouching", &global_sound_reference },
		{ _field_tag_reference, "Crouch up sound", "plays when player stands up", &global_sound_reference },
		{ _field_tag_reference, "Shield impact override", "overrides shield impact sound, like when in a Mantis", &global_sound_reference },
		{ _field_tag_reference, "Non shield impact override", "overrides regular impact sound, like when in a Mantis", &global_sound_reference },
		{ _field_real, "Sound radius multiplier", "increases radius of other sounds when piloting this biped (mech)" },
		{ _field_block, "Sound RTPCs", &BipedSoundRTPCBlock_block },
		{ _field_block, "Sound Sweeteners", &BipedSoundSweetenerBlock_block },
		{ _field_block, "Aiming Fixup", &BipedAimingJointFixupBlock_block },
		{ _field_tag_reference, "Self Illumination", &self_illumination_reference },
		
		{ _field_terminator }
	};

	#define BIPED_LEAPING_DATA_STRUCT_ID { 0x8D1584BD, 0xB9A24D94, 0xAB6217DD, 0x65BD78D0 }
	TAG_STRUCT(
		biped_leaping_data_struct,
		"biped_leaping_data_struct",
		"s_biped_leaping_data",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		BIPED_LEAPING_DATA_STRUCT_ID)
	{
		FIELD_CUSTOM("wall-leaping", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		FIELD_EXPLANATION("wall-leaping fields", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_long_flags, "leap flags", &biped_leap_flags_definition },
		{ _field_real_fraction, "dampening scale", nullptr, nullptr, "[0,1] 1= very slow changes" },
		{ _field_real_fraction, "roll delay", nullptr, nullptr, "[0,1] 1= roll fast and late" },
		{ _field_real_fraction, "cannonball off-axis scale", nullptr, nullptr, "[0,1] weight" },
		{ _field_real_fraction, "cannonball off-track scale", nullptr, nullptr, "[0,1] weight" },
		{ _field_angle_bounds, "cannonball roll bounds", nullptr, "degrees per second" },
		{ _field_real_bounds, "anticipation ratio bounds", nullptr, "current velocity/leap velocity" },
		{ _field_real_bounds, "reaction force bounds", nullptr, "units per second" },
		{ _field_real_fraction, "lobbing desire", nullptr, "1= heavy arc, 0= no arc" },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		{ _field_terminator }
	};

	#define BIPED_VAULTING_DATA_STRUCT_ID { 0x34215BE1, 0xC36F4C81, 0x87730F91, 0x58CF50C2 }
	TAG_STRUCT(
		biped_vaulting_data_struct,
		"biped_vaulting_data_struct",
		"s_biped_vaulting_data",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		BIPED_VAULTING_DATA_STRUCT_ID)
	{
		FIELD_CUSTOM("vaulting", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		FIELD_EXPLANATION("vaulting fields", nullptr, FIELD_FLAG_NONE, "The cost of the vault check is scaled by max horizontal distance divided by min object size.  Try to keep that number reasonably low."),
		{ _field_real_bounds, "vault height bounds", nullptr, "wus" },
		{ _field_real, "vault max horizontal distance", nullptr, "wus" },
		{ _field_real_fraction, "vault arc amount", nullptr, "1= heavy arc, 0= no arc" },
		{ _field_real, "vault min object size", nullptr, "wus" },
		{ _field_real, "search width", nullptr, "wus, the side-to-side width of the search path" },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		{ _field_terminator }
	};

	#define BIPED_GRAB_BIPED_DATA_STRUCT_ID { 0x3356D931, 0xCB37420D, 0xAC9B3B8F, 0xA4A1CACD }
	TAG_STRUCT(
		biped_grab_biped_data_struct,
		"biped_grab_biped_data_struct",
		"s_biped_grab_biped_data",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		BIPED_GRAB_BIPED_DATA_STRUCT_ID)
	{
		FIELD_CUSTOM("grab biped", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		FIELD_EXPLANATION("grab biped fields", nullptr, FIELD_FLAG_NONE, "Allows a biped to grab and be grabbed by other bipeds."),
		{ _field_string_id, "grab biped animation class" },
		{ _field_char_enum, "throw biped control mode", &grab_biped_throw_control_modes },
		FIELD_PAD("hurgh", nullptr, FIELD_FLAG_NONE, 3),
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		{ _field_terminator }
	};

	#define BIPED_GRAB_OBJECT_DATA_STRUCT_ID { 0x62E91941, 0x927649BD, 0x93129581, 0x268B9207 }
	TAG_STRUCT(
		biped_grab_object_data_struct,
		"biped_grab_object_data_struct",
		"s_biped_grab_object_data",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		BIPED_GRAB_OBJECT_DATA_STRUCT_ID)
	{
		FIELD_CUSTOM("grab object", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		FIELD_EXPLANATION("grab object fields", nullptr, FIELD_FLAG_NONE, "Allows a biped to grab and throw crate objects."),
		{ _field_block, "grab object animation sets", &biped_grab_object_animation_set_block },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		{ _field_terminator }
	};

	#define BIPED_GROUND_FITTING_DATA_STRUCT_ID { 0x8E954938, 0x813744E7, 0xBA856A03, 0x1B7808B0 }
	TAG_STRUCT(
		biped_ground_fitting_data_struct,
		"biped_ground_fitting_data_struct",
		"biped_ground_fitting_data_struct",
		SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_POSTPROCESS_RECURSIVELY | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		BIPED_GROUND_FITTING_DATA_STRUCT_ID)
	{
		FIELD_CUSTOM("ground fitting", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		FIELD_EXPLANATION("ground fitting data", nullptr, FIELD_FLAG_NONE, ""),

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_long_flags, "ground fitting flags", &biped_ground_fitting_flags_definition },

		{ _field_real_fraction, "ground normal dampening", nullptr, "react to slope changes (0=slow, 1= fast)" },
		{ _field_real, "root offset max scale idle", nullptr, "vertical drop to ground allowed (0=none, 1=full)", MAKE_OLD_NAMES("root offset max scale") },
		{ _field_real, "root offset max scale moving", nullptr, "vertical drop to ground allowed (0=none, 1=full)" },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_real_fraction, "root offset dampening", nullptr, "react to root changes (0=slow, 1= fast)" },

		{ _field_real_fraction, "following cam scale", nullptr, "root offset effect on following cam (0=none, 1=full)" },
		{ _field_real_fraction, "root leaning scale", nullptr, "lean into slopes (0=none, 1=full)" },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_real, "stance width scale", nullptr, "scale pill width to use as stance radius" },

		{ _field_angle, "foot roll max", nullptr, "orient to ground slope (degrees)" },
		{ _field_angle, "foot pitch max", nullptr, "orient to ground slope (degrees)" },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach, 13 },
		{ _field_real_fraction, "foot normal dampening", nullptr, "(0=slow, 1= fast)" },
		{ _field_real, "foot fitting test distance" },
		{ _field_real_fraction, "foot displacement upward dampening", nullptr, "(0=slow, 1= fast)" },
		{ _field_real_fraction, "foot displacement downward dampening", nullptr, "(0=slow, 1= fast)" },
		{ _field_real, "foot pull threshold distance idle", nullptr, "amount past the authored plane the foot can be pulled (wu)" },
		{ _field_real, "foot pull threshold distance moving", nullptr, "amount past the authored plane the foot can be pulled (wu)" },
		{ _field_real, "foot turn minimum radius", nullptr, "minimum radius at which foot is fit to turn radius" },
		{ _field_real, "foot turn maximum radius", nullptr, "maximum radius at which foot is fit to turn radius" },
		{ _field_real, "foot turn threshold radius", nullptr, "foot is fit to turn radius fully at minimum plus threshold and above" },
		{ _field_real, "foot turn rate dampening", nullptr, "(0=slow, 1=fast)" },
		{ _field_real, "foot turn weight dampening", nullptr, "dampening of fitting value for fit to turn radius(0=none, 1=fast)" },
		{ _field_real, "foot turn blend on time", nullptr, "time to blend on the foot turn effect (seconds)" },
		{ _field_real, "foot turn blend off time", nullptr, "time to blend off the foot turn effect (seconds)" },

		{ _field_legacy, _field_version_equal, _engine_type_haloreach, 2 },
		{ _field_legacy, _field_real, "unknown@" },
		{ _field_legacy, _field_real, "unknown@" },

		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		FIELD_CUSTOM("pivot-on-foot", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		FIELD_EXPLANATION("pivot-on-foot data", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real_fraction, "pivot-on-foot scale", nullptr, "(0=none, 1= full)" },
		{ _field_real, "pivot min foot delta", nullptr, "vert world units to find lowest foot" },
		{ _field_real, "pivot stride length scale", nullptr, "leg length * this = stride length" },
		{ _field_real_fraction, "pivot throttle scale", nullptr, "pivoting slows throttle (0=none, 1= full)" },
		{ _field_real_fraction, "pivot offset dampening", nullptr, "react to pivot changes (0=slow, 1= fast)" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 17 },
		{ _field_real_fraction, "pivot force turn rate", nullptr, "turn no matter what the pivot state is (0=control turn, 1= always turn)" },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		FIELD_CUSTOM("Ground fitting pelvis elevation settings", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_real, "ideal pelvis over high foot scale", "ideal ratio of distance from the pelvis to pedestal to place pelvis over the highest foot", "ratio of pedestal to pelvis distance " },
		{ _field_real, "ideal pelvis over low foot scale", "ideal ratio of distance from the pelvis to pedestal to place pelvis over the lowest foot", "ratio of pedestal to pelvis distance " },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		FIELD_CUSTOM("Ledge Push", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		FIELD_EXPLANATION("Pushing over Ledges", nullptr, FIELD_FLAG_NONE, "When a locked foot is unsupported, meaning it can\'t reach the ground, the biped is considered to be hanging over a ledge. You can provide a velocity that will either push the character over the ledge or away from it"),
		{ _field_real, "push over mag", nullptr, "magnitude of throttle to push over ledges. 0= no push" },
		{ _field_real, "push back mag", nullptr, "magnitude of throttle to push back from ledges. 0= no push" },
		{ _field_real, "ledgeIKSuccessRange", nullptr, "when unable to IK at least this close, consider the IK failed." },
		{ _field_real, "ledge warning time", nullptr, "secs to warn the player before pushing over a ledge" },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		FIELD_CUSTOM("Foot locking", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_real, "footlock Scale", "how much this biped respects foot lock events", "(0-1) " },
		{ _field_real, "footlock Min Throttle", "throttle at which foot lock should be fully on (footlockScale)", "(0-1) " },
		{ _field_real, "footlock Max Throttle", "throttle at which foot lock should be fully off", "(0-1) " },

		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		{ _field_terminator }
	};

	#define BIPEDMOVEMENTHIPLEANINGSTRUCT_ID { 0x7BB8ADF6, 0x878942AB, 0xB4814282, 0x2B52E6CB }
	TAG_STRUCT(
		BipedMovementHipLeaningStruct,
		"BipedMovementHipLeaningStruct",
		"BipedMovementHipLeaning",
		SET_POSTPROCESS_RECURSIVELY | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		BIPEDMOVEMENTHIPLEANINGSTRUCT_ID)
	{
		FIELD_CUSTOM("Movement Hip Leaning", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		FIELD_EXPLANATION("Movement Hip Leaning", nullptr, FIELD_FLAG_NONE, "Allows a biped to lean based on movement."),
		{ _field_real, "prediction seconds", nullptr, "predict ahead to determine lean. 0= off, more time=more lean" },
		{ _field_real, "max lean angle", nullptr, "(degrees) maximum lean amount" },
		{ _field_real_fraction, "max vertical dip", nullptr, "(fraction of leg length)" },
		{ _field_real, "max lean angle sine", nullptr, "set on post-process, don't edit", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real, "max lean angle cosine", nullptr, "set on post-process, don't edit", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
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

} // namespace macaque

} // namespace blofeld

