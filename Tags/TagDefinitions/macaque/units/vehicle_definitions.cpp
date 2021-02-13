#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		vehicle_group,
		VEHICLE_TAG,
		&unit_group,
		UNIT_TAG,
		vehicle_block );

	TAG_BLOCK_FROM_STRUCT(
		vehicle_block,
		"vehicle",
		1,
		vehicle_struct_definition);

	TAG_BLOCK_FROM_STRUCT(
		human_tank_block,
		"human_tank_block",
		1,
		human_tank_struct);

	#define HUMAN_JEEP_BLOCK_ID { 0xE8B7F68B, 0x63C644C7, 0xBE98A235, 0x1AD78551 }
	TAG_BLOCK(
		human_jeep_block,
		"human_jeep_block",
		1,
		"s_vehicle_human_jeep_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | 
		SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		HUMAN_JEEP_BLOCK_ID)
	{
		{ _field_struct, "steering control", &vehicle_steering_control_struct },
		{ _field_struct, "turning control", &vehicle_turning_control_struct },
		{ _field_struct, "engine", &global_vehicle_engine_struct },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_block, "boat engine", &boat_engine_definition_block },

		FIELD_EXPLANATION("wheel circumferance", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real, "wheel circumferance" },
		{ _field_real, "gravity adjust", "0-1 fraction by which we scale gravity that is not along the ground plane" },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_real, "antiroll torque factor", "how much torque should be applied to prevent a vehicle from rolling. Default should be 0.0, 1.0 is a good value for making it hard to roll." },

		{ _field_terminator }
	};

	#define HUMAN_PLANE_BLOCK_ID { 0x3F025A0A, 0x7D8B4893, 0xBEE5EAF1, 0x42591680 }
	TAG_BLOCK(
		human_plane_block,
		"human_plane_block",
		1,
		"s_vehicle_human_plane_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_POSTPROCESS_RECURSIVELY | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		HUMAN_PLANE_BLOCK_ID)
	{
		FIELD_EXPLANATION("velocity control variables", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real, "maximum forward speed" },
		{ _field_real, "maximum reverse speed" },
		{ _field_real, "speed acceleration" },
		{ _field_real, "speed deceleration" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_real, "speed accel against direction", "acceleration when trying to throttle against current speed direction" },
		{ _field_real, "maximum forward speed during boost" },

		{ _field_real, "maximum left slide" },
		{ _field_real, "maximum right slide" },
		{ _field_real, "slide acceleration" },
		{ _field_real, "slide deceleration" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_real, "slide accel against direction", "acceleration when trying to throttle against current slide direction" },
		{ _field_real, "maximum slide speed during boost" },

		{ _field_real, "maximum up rise" },
		{ _field_real, "maximum down rise" },
		{ _field_real, "rise acceleration" },
		{ _field_real, "rise deceleration" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_real, "rise accel against direction", "acceleration when trying to throttle against current rise direction" },
		{ _field_real, "maximum rise speed during boost" },

		FIELD_EXPLANATION("human plane tuning variables", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real, "flying torque scale", "big vehicles need to scale this down.  0 defaults to 1, which is generally a good value." },
		{ _field_real, "air friction deceleration", "human plane physics only. 0 is nothing.  1 is like thowing the engine to full reverse" },
		{ _field_real, "thrust scale", "human plane physics only. 0 is default (1)" },
		{ _field_real, "turn rate scale when boosting", "this was originally added for the sentinel enforce, but I could see other uses. 0 defaults to 1" },
		{ _field_real, "maximum roll", "0 defaults to 90 degrees" },
		{ _field_struct, "steering animation", &steering_animation_struct },
		{ _field_terminator }
	};

	#define WOLVERINE_BLOCK_ID { 0xABB7F68B, 0xCBC644C7, 0xB028A235, 0x1AAC8551 }
	TAG_BLOCK(
		wolverine_block,
		"wolverine_block",
		1,
		"s_vehicle_wolverine_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | 
		SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		WOLVERINE_BLOCK_ID)
	{
		{ _field_struct, "steering control", &vehicle_steering_control_struct },
		{ _field_struct, "turning control", &vehicle_turning_control_struct },
		{ _field_struct, "engine", &global_vehicle_engine_struct },
		FIELD_EXPLANATION("wheel circumferance", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real, "wheel circumferance" },
		{ _field_real, "gravity adjust", "0-1 fraction by which we scale gravity that is not along the ground plane" },
		FIELD_EXPLANATION("deployed mode", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real, "turret deployment time", "time it takes for turret and support legs to deploy", "seconds" },
		{ _field_real, "turret holster time", "time it takes for turret and support legs to pack up", "seconds" },
		{ _field_real, "runtime inverse turret deployment time", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real, "runtime inverse turret holster time", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real, "deployed camera yaw scale." },
		{ _field_terminator }
	};

	#define ALIEN_SCOUT_BLOCK_ID { 0x44F7199E, 0x44564222, 0xB555F347, 0x2AE7DC1C }
	TAG_BLOCK(
		alien_scout_block,
		"alien_scout_block",
		1,
		"s_vehicle_alien_scout_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_POSTPROCESS_RECURSIVELY | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | 
		SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		ALIEN_SCOUT_BLOCK_ID)
	{
		{ _field_struct, "steering control", &vehicle_steering_control_struct },
		FIELD_EXPLANATION("velocity control variables", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real, "maximum forward speed" },
		{ _field_real, "maximum reverse speed" },
		{ _field_real, "speed acceleration" },
		{ _field_real, "speed deceleration" },
		{ _field_real, "maximum left slide" },
		{ _field_real, "maximum right slide" },
		{ _field_real, "slide acceleration" },
		{ _field_real, "slide deceleration" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_real, "slide accel against direction", "acceleration when trying to throttle against current slide direction" },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_real, "slide speed at top speed", "the slide speeds are interpolated down to this value, reaching it when the vehicle is moving at its top speed", "wu/s" },

		FIELD_EXPLANATION("specific types", nullptr, FIELD_FLAG_NONE, "different types are treated differently alien scout controller"),
		{ _field_char_enum, "specific type", &alien_scout_specific_type_enum },
		{ _field_byte_flags, "flags", &alien_scout_flags },
		FIELD_PAD("NPBE", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real, "drag coeficient" },
		{ _field_real, "constant deceleration" },
		{ _field_real, "torque scale", "0 defaults to 1" },
		FIELD_EXPLANATION("engine object function", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_struct, "engine gravity function", &engine_function_struct },
		FIELD_EXPLANATION("contrail object function", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_struct, "contrail gravity function", &engine_function_struct },
		FIELD_EXPLANATION("engine rotation function", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real_bounds, "gear rotation speed", "cycles per second idle to full throttle" },
		{ _field_struct, "steering animation", &steering_animation_struct },
		{ _field_terminator }
	};

	#define ALIEN_FIGHTER_BLOCK_ID { 0x1F64F81E, 0x24D64BCB, 0x828FBA10, 0xABC09BAB }
	TAG_BLOCK(
		alien_fighter_block,
		"alien_fighter_block",
		1,
		"s_vehicle_alien_fighter_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_POSTPROCESS_RECURSIVELY | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		ALIEN_FIGHTER_BLOCK_ID)
	{
		{ _field_struct, "steering control", &vehicle_steering_control_struct },
		{ _field_struct, "turning control", &vehicle_turning_control_struct },
		FIELD_EXPLANATION("velocity control variables", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real, "maximum forward speed" },
		{ _field_real, "maximum reverse speed" },
		{ _field_real, "speed acceleration" },
		{ _field_real, "speed deceleration" },
		{ _field_real, "maximum left slide" },
		{ _field_real, "maximum right slide" },
		{ _field_real, "slide acceleration" },
		{ _field_real, "slide deceleration" },
		{ _field_real, "slide accel against direction", "acceleration when trying to throttle against current slide direction" },
		FIELD_EXPLANATION("torque scale", nullptr, FIELD_FLAG_NONE, "how hard the vehicle trys to rotate to it\'s desired rotation"),
		{ _field_real, "flying torque scale", "big vehicles need to scale this down.  0 defaults to 1, which is generally a good value." },
		FIELD_EXPLANATION("fixed gun offset", nullptr, FIELD_FLAG_NONE, "this offset will be aligned to the units aiming vector instead of the vehicle forward vector"),
		{ _field_angle, "fixed gun yaw" },
		{ _field_angle, "fixed gun pitch" },
		FIELD_EXPLANATION("alien fighter trick variables", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real, "maximum trick frequency" },
		{ _field_real, "loop trick duration" },
		{ _field_real, "roll trick duration" },
		FIELD_EXPLANATION("alien fighter fake flight control", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real, "zero gravity speed" },
		{ _field_real, "full gravity speed" },
		{ _field_real, "strafe boost scale" },
		{ _field_real, "off stick deceleration scale" },
		{ _field_real, "cruising throttle" },
		{ _field_real, "dive speed scale" },
		{ _field_terminator }
	};

	#define TURRET_BLOCK_ID { 0xA788CE59, 0xB2AC4121, 0xA7387B57, 0xA01A73CD }
	TAG_BLOCK(
		turret_block,
		"turret_block",
		1,
		"s_vehicle_turret_definition",
		SET_UNKNOWN0 | SET_POSTPROCESS_RECURSIVELY | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		TURRET_BLOCK_ID)
	{
		{ _field_word_flags, "flags", &turret_flags },
		FIELD_PAD("pad", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_string_id, "physical yaw node" },
		{ _field_string_id, "physical pitch node" },
		{ _field_string_id, "physical elevate node", "this is specificly for the wolverine which has a turret which pops up when you use it." },
		{ _field_angle, "operating elevation angle", "angle which elevate node is set to in order to operate" },
		{ _field_terminator }
	};

	#define MANTIS_BLOCK_ID { 0x3D5289E7, 0xE2554038, 0xA70B311D, 0xAAE49B2B }
	TAG_BLOCK(
		mantis_block,
		"mantis_block",
		1,
		"s_vehicle_mantis_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		MANTIS_BLOCK_ID)
	{
		{ _field_struct, "steering control", &vehicle_steering_control_struct },
		{ _field_struct, "turning control", &vehicle_turning_control_struct },
		FIELD_EXPLANATION("velocity control variables", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real, "maximum forward speed" },
		{ _field_real, "maximum reverse speed" },
		{ _field_real, "speed acceleration" },
		{ _field_real, "speed deceleration" },
		{ _field_real, "maximum left slide" },
		{ _field_real, "maximum right slide" },
		{ _field_real, "slide acceleration" },
		{ _field_real, "slide deceleration" },
		{ _field_struct, "walker physics", &walker_physics_struct },
		{ _field_real, "walk cycle pause", "fraction of walkcycle at end for pause" },
		{ _field_short_integer, "stable planted legs", "number of legs mantis needs planted to be considered stable." },
		FIELD_PAD("pad", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real, "time without plant buffer", "seconds" },
		{ _field_real, "not along up gravity scale", "0-1" },
		{ _field_real, "speed acceleration limit" },
		{ _field_real, "speed acceleration match scale" },
		{ _field_real, "slide acceleration limit" },
		{ _field_real, "slide acceleration match scale" },
		{ _field_real, "turn acceleration limit" },
		{ _field_real, "turn acceleration match scale" },
		FIELD_EXPLANATION("jumping", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real, "jump set time", "seconds" },
		{ _field_real, "jump set interpolation fraction", "0-1, portion of set time spent interpolating into neutral stance" },
		{ _field_real, "jump leap time", "seconds" },
		{ _field_real, "jump recovery time", "seconds" },
		{ _field_real, "jump recovery fraction", "0-1, portion of recovery time spent interpolating into neutral stance" },
		{ _field_real, "jump leg set distance", "WU, amount foot moves up to get ready to jump" },
		{ _field_real, "jump leg distance", "WU, amount foot moves down when jumping" },
		{ _field_terminator }
	};

	#define VTOL_BLOCK_ID { 0x3FF3D8BD, 0x885445AB, 0xA71E3BEE, 0x6D8D25EE }
	TAG_BLOCK(
		vtol_block,
		"vtol_block",
		1,
		"s_vehicle_vtol_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		VTOL_BLOCK_ID)
	{
		{ _field_struct, "turning control", &vehicle_turning_control_struct },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_marker),
		{ _field_string_id, "left lift marker" },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_marker),
		{ _field_string_id, "right lift marker" },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_marker),
		{ _field_string_id, "thrust marker" },

		{ _field_legacy, _field_version_less, _engine_type_haloreach, 19 }, // #TODO: vtol block needs research badly
		{ _field_legacy, _field_angle, "@unknown" },
		{ _field_legacy, _field_angle, "@unknown" },
		{ _field_legacy, _field_angle, "@unknown" },
		{ _field_legacy, _field_angle, "@unknown" },
		{ _field_legacy, _field_real, "@unknown" },
		{ _field_legacy, _field_real, "@unknown" },
		{ _field_legacy, _field_real, "@unknown" },
		{ _field_legacy, _field_real, "@unknown" },
		{ _field_legacy, _field_real, "@unknown" },
		{ _field_legacy, _field_real, "@unknown" },
		{ _field_legacy, _field_real, "@unknown" },
		{ _field_legacy, _field_real, "@unknown" },
		{ _field_legacy, _field_real, "@unknown" },
		{ _field_legacy, _field_real, "@unknown" },
		{ _field_legacy, _field_real, "@unknown" },
		{ _field_legacy, _field_real, "@unknown" },
		{ _field_legacy, _field_real, "@unknown" },
		{ _field_legacy, _field_real, "@unknown" },
		{ _field_legacy, _field_real, "@unknown" },


		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach, 18 },
		{ _field_struct, "trigger to throttle", &scalar_function_named_struct },
		{ _field_struct, "descent to boost", &vtol_descent_function_struct },
		FIELD_EXPLANATION("minimum and maximum up acceleration", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real, "maximum up acceleration" },
		{ _field_real, "maximum down acceleration" },
		{ _field_real, "vertical deceleration time", "after accelerating vertically, take this long to bleed off the throttle", "seconds" },
		FIELD_EXPLANATION("lift arm pivot", nullptr, FIELD_FLAG_NONE, "this simulates the engines being on a pivot like on an osprey.  This helps better cradle the center of mass."),
		{ _field_real, "lift arm pivot length" },
		FIELD_EXPLANATION("turn, left and forward accelerations", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real, "maximum turn acceleration" },
		{ _field_real, "turn acceleration gain" },
		FIELD_EXPLANATION("interpolation parameters", nullptr, FIELD_FLAG_NONE, "these parameters control the interpolation between the two elements in the speed interpolation block"),
		{ _field_real, "interpolation speed domain" },
		FIELD_EXPLANATION("funciton explanation", nullptr, FIELD_FLAG_NONE, "acc= INTERPOLATION_ACC(ceiling(throttle, SPEED_TROTTLE_CEILING(speed))), speed+= acc, interpolation= A_B_INTERPOLATION(speed)"),
		{ _field_struct, "SPEED_TROTTLE_CEILING()", &scalar_function_named_struct },
		{ _field_struct, "INTERPOLATION_ACC()", &scalar_function_named_struct },
		{ _field_struct, "A_B_INTERPOLATION() interpolation mapping", &scalar_function_named_struct },
		{ _field_block, "speed interpolated parameters", &vtol_speed_interpolated_block },

		{ _field_angle, "lift angles acc", "how fast can the engine animations accelerate their turn in degress/SQR(sec)" },
		{ _field_angle, "render lift angles acc", "how fast can the engine animations accelerate their turn in degress/SQR(sec)" },

		{ _field_legacy, _field_version_less, _engine_type_haloreach, 2 }, // More research needed
		{ _field_legacy, _field_real, "@unknown" },
		{ _field_legacy, _field_real, "@unknown" },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach, 9 },
		{ _field_real, "alt. lock offset coefficient", "scalar for altitude lock based on distance to target - higher numbers reach the target more quickly but may cause bounciness" },
		{ _field_real, "alt. lock velocity coefficient", "scalar for altitude lock based on velocity.  Acts like friction, trying to remove vertical velocity from the system" },
		FIELD_EXPLANATION("prop rotation", nullptr, FIELD_FLAG_NONE, "propeller speed data to drive propeller animations"),
		{ _field_real_bounds, "prop rotation speed", "cycles per second idle to full throttle" },
		FIELD_EXPLANATION("landing", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real, "landing time", "how long we must maintain the landing state in order to land", "s" },
		{ _field_real, "takeoff time", "how long it takes to leave the landed state", "s" },
		{ _field_real, "landing linear velocity", "must be under this linear velocity to enter/maintain landing state", "wu/s" },
		{ _field_real, "landing angular velocity", "must be under this angular velocity to enter/maintain landing state", "rad/s" },

		{ _field_terminator }
	};

	#define VTOL_SPEED_INTERPOLATED_BLOCK_ID { 0xAFF3D8BD, 0x88B445AB, 0x371E3BEE, 0x2D8D25EE }
	TAG_BLOCK(
		vtol_speed_interpolated_block,
		"vtol_speed_interpolated_block",
		2,
		"s_vehicle_vtol_interpolated_parameters",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		VTOL_SPEED_INTERPOLATED_BLOCK_ID)
	{
		{ _field_real, "rotor damping", "maxes out around 30" },
		{ _field_real, "maximum left acceleration" },
		{ _field_real, "maximum forward acceleration" },
		{ _field_real, "drag coeficient" },
		{ _field_real, "constant deceleration" },
		{ _field_real, "magic angular acc exp", "magic force that torques vehicle back towards up" },
		{ _field_real, "magic angular acc scale", "magic force that torques vehicle back towards up" },
		{ _field_real, "magic angular acc k", "magic force that torques vehicle back towards up" },
		{ _field_terminator }
	};

	#define CHOPPER_BLOCK_ID { 0x83DF59C4, 0xC84947A4, 0x9CF064DB, 0x032894CC }
	TAG_BLOCK(
		chopper_block,
		"chopper_block",
		1,
		"s_vehicle_chopper_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | 
		SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		CHOPPER_BLOCK_ID)
	{
		{ _field_struct, "steering control", &vehicle_steering_control_struct },
		{ _field_struct, "turning control", &vehicle_turning_control_struct },
		{ _field_struct, "engine", &global_vehicle_engine_struct },
		FIELD_EXPLANATION("wheel circumferance", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real, "wheel circumferance" },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_marker),
		{ _field_string_id, "rotation marker" },
		{ _field_real, "magic turning scale", "scale up the magic force" },
		{ _field_real, "magic turning acc", "(degrees/pow(sec,2))rate at which the turning tries to accelerate" },
		{ _field_real, "magic turning max vel.", "(degrees/sec)rate at which vehicl tries to turn" },
		{ _field_real, "magic turning exponent", "turn_acc=delta^exp" },
		{ _field_real, "bank to slide ratio", "(WU/sec)the slide velocity at which we achieve full bank" },
		{ _field_real, "bank slide exponent" },
		{ _field_real, "bank to turn ratio", "(WU/sec)the slide velocity at which we achieve full bank" },
		{ _field_real, "bank turn exponent" },
		{ _field_real, "bank fraction", "fraction of possible tire drop when we bank. 0 is full bank 1 is no bank." },
		{ _field_real, "bank rate", "bank fraction velocity. (0-1 fraction / sec)" },
		{ _field_real, "wheel accel", "acceleration of the wheel towards the engine speed" },
		{ _field_real, "gyroscopic damping", "0==none, 30==damn near full damping" },
		{ _field_terminator }
	};

	#define GUARDIAN_BLOCK_ID { 0x3A5289E7, 0xE34740B8, 0xA7CB311D, 0xDAE40875 }
	TAG_BLOCK(
		guardian_block,
		"guardian_block",
		1,
		"s_vehicle_guardian_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_POSTPROCESS_RECURSIVELY | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		GUARDIAN_BLOCK_ID)
	{
		{ _field_struct, "steering control", &vehicle_steering_control_struct },
		{ _field_real, "maximum forward speed" },
		{ _field_real, "maximum reverse speed" },
		{ _field_real, "speed acceleration" },
		{ _field_real, "speed deceleration" },
		{ _field_real, "maximum left slide" },
		{ _field_real, "maximum right slide" },
		{ _field_real, "slide acceleration" },
		{ _field_real, "slide deceleration" },
		{ _field_real, "torque scale", "0 defaults to 1" },
		{ _field_real, "anti-gravity force z-offset" },
		{ _field_terminator }
	};

	#define JACKAL_GLIDER_BLOCK_ID { 0x6ABC199E, 0x12A64A22, 0xB555CB17, 0x2B13DC3C }
	TAG_BLOCK(
		jackal_glider_block,
		"jackal_glider_block",
		1,
		"s_vehicle_jackal_glider_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_POSTPROCESS_RECURSIVELY | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | 
		SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		JACKAL_GLIDER_BLOCK_ID)
	{
		{ _field_struct, "steering control", &vehicle_steering_control_struct },
		FIELD_EXPLANATION("velocity control variables", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real, "maximum forward speed" },
		{ _field_real, "maximum reverse speed" },
		{ _field_real, "speed acceleration" },
		{ _field_real, "speed deceleration" },
		{ _field_real, "maximum left slide" },
		{ _field_real, "maximum right slide" },
		{ _field_real, "slide acceleration" },
		{ _field_real, "slide deceleration" },
		{ _field_real, "torque scale", "0 defaults to 1" },
		FIELD_EXPLANATION("engine object function", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_struct, "engine object function", &engine_function_struct },
		FIELD_EXPLANATION("contrail object function", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_struct, "contrail object function", &engine_function_struct },
		{ _field_struct, "steering animation", &steering_animation_struct },
		{ _field_real, "flying velocity threshold" },
		{ _field_angle, "flying look threshold", "degrees" },
		{ _field_real, "flying hover threshold" },
		{ _field_real, "grounded hover threshold" },
		{ _field_real, "landing grounded time" },
		{ _field_angle, "ground turn radius", "degrees" },
		{ _field_real, "ground acceleration", "wu/sec" },
		FIELD_EXPLANATION("wing lift", nullptr, FIELD_FLAG_NONE, "lift_force= k*CEILING(SQR(q*forward_velocity), function_ceiling)"),
		{ _field_real, "wing lift q" },
		{ _field_real, "wing lift k" },
		{ _field_real, "wing lift function ceiling" },
		{ _field_real, "aileron to angular acceleartion scale" },
		{ _field_angle, "aileron yaw tilt angle" },
		FIELD_EXPLANATION("wing", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_struct, "wing surface", &flight_surface_struct },
		FIELD_EXPLANATION("ailerons", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_struct, "aileron surface", &flight_surface_struct },
		FIELD_EXPLANATION("elevator", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_struct, "elevator surface", &flight_surface_struct },
		FIELD_EXPLANATION("tail", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_struct, "tail surface", &flight_surface_struct },
		FIELD_EXPLANATION("rudder", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_struct, "rudder surface", &flight_surface_struct },
		FIELD_EXPLANATION("taxi", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_struct, "taxi surface", &flight_surface_struct },
		FIELD_EXPLANATION("ground drag", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_struct, "ground drag struct", &jackal_glider_drag_struct },
		FIELD_EXPLANATION("air drag", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_struct, "air drag struct", &jackal_glider_drag_struct },
		FIELD_EXPLANATION("takeoff drag", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_struct, "takeoff drag struct", &jackal_glider_drag_struct },
		{ _field_terminator }
	};

	#define BOAT_BLOCK_ID { 0xDC1EBF40, 0xF37D4D6F, 0x93B188D5, 0x27A035CC }
	TAG_BLOCK(
		boat_block,
		"boat_block",
		1,
		"s_vehicle_boat_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | 
		SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		BOAT_BLOCK_ID)
	{
		{ _field_byte_flags, "flags", &boat_flags },
		FIELD_PAD("blah", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_angle, "tank control forward arc", "only used when 'use tank controls' is checked above", "degrees" },
		{ _field_struct, "steering control", &vehicle_steering_control_struct },
		{ _field_struct, "turning control", &vehicle_turning_control_struct },
		{ _field_real, "gravity scale", "0 means 0.  How hard is it to type 1?" },
		{ _field_struct, "engine", &global_vehicle_engine_struct },
		{ _field_block, "boat engine", &boat_engine_definition_block },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_marker),
		{ _field_string_id, "hull marker name", "the name of the hull surface used to spew effects along the hull of the vehicle." },
		{ _field_terminator }
	};

	#define SPACE_FIGHTER_BLOCK_ID { 0xCE661634, 0x027B499C, 0xBFBD2CC1, 0xEFAAA320 }
	TAG_BLOCK(
		space_fighter_block,
		"space_fighter_block",
		1,
		"s_vehicle_space_fighter_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SPACE_FIGHTER_BLOCK_ID)
	{
		{ _field_struct, "steering control", &vehicle_steering_control_struct },
		{ _field_struct, "turning control", &vehicle_turning_control_struct },
		FIELD_EXPLANATION("velocity control variables", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real, "full throttle speed", "maximum speed when throttle = 1.0", "wu/s" },
		{ _field_real, "neutral throttle speed", "speed when throttle = 0.0", "wu/s" },
		{ _field_real, "reverse throttle speed", "speed when throttle = -1.0", "wu/s" },
		{ _field_real, "speed acceleration", nullptr, "wu/s/s" },
		{ _field_real, "speed deceleration", nullptr, "wu/s/s" },
		{ _field_real, "maximum left slide" },
		{ _field_real, "maximum right slide" },
		{ _field_real, "slide acceleration" },
		{ _field_real, "slide deceleration" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_real, "slide accel against direction", "acceleration when trying to throttle against current slide direction" },

		FIELD_EXPLANATION("torque scale", nullptr, FIELD_FLAG_NONE, "how hard the vehicle trys to rotate to it\'s desired rotation"),
		{ _field_real, "flying torque scale", "big vehicles need to scale this down.  0 defaults to 1, which is generally a good value." },
		FIELD_EXPLANATION("fixed gun offset", nullptr, FIELD_FLAG_NONE, "this offset will be aligned to the units aiming vector instead of the vehicle forward vector"),
		{ _field_angle, "fixed gun yaw" },
		{ _field_angle, "fixed gun pitch" },
		FIELD_EXPLANATION("alien fighter trick variables", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real, "maximum trick frequency" },
		{ _field_real, "loop trick duration" },
		{ _field_real, "roll trick duration" },
		FIELD_EXPLANATION("alien fighter fake flight control", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real, "strafe boost scale" },
		{ _field_real, "off stick deceleration scale" },
		{ _field_real, "dive speed scale" },
		{ _field_angle, "roll max velocity", "max angular velocity for user-input roll", "deg/sec" },
		{ _field_angle, "roll acceleration", "acceleration for user-input roll", "deg/sec/sec" },
		{ _field_angle, "roll deceleration", "deceleration for user-input roll (when the user releases the stick)", "deg/sec/sec" },
		{ _field_real_fraction, "roll smoothing fraction", "if non-zero, when the desired velocity change is less than this fraction of the acceleration, starts interpolating the maximum acceleration towards zero.\nYou can think of this as a time in seconds where if the velocity would reach its target in this amount of time or less, it will start taking longer." },
		FIELD_EXPLANATION("autolevel", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real, "autolevel time", "how long you must not rotate (roll, pitch, yaw) before autoleveling kicks in", "s" },
		{ _field_angle, "autolevel pitch cutoff", "if the ship is pitched outside of this range, autoleveling will not happen.  The effect is also scaled as the pitch approaches this angle", "degrees" },
		{ _field_angle, "autolevel max velocity", "maximum angular velocity for autoleveling", "degrees/sec" },
		{ _field_angle, "autolevel max acceleration", "maximum acceleration for autoleveling", "deg/sec/sec" },
		{ _field_angle, "autolevel max user ang. vel.", "autolevel can continue to happen if the user is desiring an angular velocity lower than this", "deg/sec" },
		{ _field_real, "autolevel spring k", "controls relationship between displacement and acceleration - higher values mean faster acceleration when the desired position is far from current position" },
		{ _field_real, "autolevel spring c", "controls relationship between velocity and friction - higher values will slow the system down, lower values may let the system oscillate" },
		FIELD_EXPLANATION("cosmetic roll", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real, "cosmetic roll scale", "desired roll = delta yaw X scale" },
		{ _field_angle, "cosmetic roll max bank", "maximum cosmetic roll angle", "degrees" },
		{ _field_angle, "cosmetic roll max velocity", "maximum angular velocity that cosmetic roll can achieve", "deg/sec" },
		{ _field_angle, "cosmetic roll acceleration", "maximum angular acceleration for cosmetic roll", "deg/sec/sec" },
		{ _field_real, "cosmetic roll spring k", "controls relationship between displacement and acceleration - higher values mean faster acceleration when the desired position is far from current position" },
		{ _field_real, "cosmetic roll spring c", "controls relationship between velocity and friction - higher values will slow the system down, lower values may let the system oscillate" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 8 },
		FIELD_EXPLANATION("new roll", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_long_flags, "roll flags", &space_fighter_roll_flags },
		{ _field_angle, "maximum left stick roll angle" },
		{ _field_real, "left stick rate smoothing" },
		{ _field_real, "left stick trend smoothing" },
		{ _field_angle, "maximum right stick roll angle" },
		{ _field_real, "right stick rate smoothing" },
		{ _field_real, "right stick trend smoothing" },

		FIELD_EXPLANATION("turn deceleration", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_angle, "turn deceleration threshold", "turn deceleration kicks in when turning faster than this", "deg/sec" },
		{ _field_real_fraction, "turn deceleration fraction", "when turning at the maximum rate, throttle is limited to this value" },
		FIELD_EXPLANATION("soft ceiling turn back", nullptr, FIELD_FLAG_NONE, "parameters for controlling turing back from soft ceilings"),
		{ _field_long_flags, "turn back flags", &space_fighter_turn_back_flags },
		{ _field_real, "turn back latched period" },
		{ _field_struct, "turn back distance to turn rate", &scalar_function_named_struct },
		FIELD_EXPLANATION("thrust params", nullptr, FIELD_FLAG_NONE, "change thrust lag"),
		{ _field_real, "ideal thrust decay" },
		{ _field_real, "ideal thrust increase" },
		{ _field_real, "minimum thrust decay" },
		{ _field_real, "minimum thrust increase" },
		{ _field_real, "maximum thrust increase" },
		FIELD_EXPLANATION("dive params", nullptr, FIELD_FLAG_NONE, "controls angles under which we change speed during dive"),
		{ _field_real, "minimum dive angle" },
		{ _field_real, "maximum dive angle" },
		FIELD_EXPLANATION("strafe params", nullptr, FIELD_FLAG_NONE, "scale speed params while strafing"),
		{ _field_real, "strafe boost power" },
		FIELD_EXPLANATION("wingtip params", nullptr, FIELD_FLAG_NONE, "wingtip"),
		{ _field_real, "wingtip contrail turn" },
		{ _field_real, "wingtip min turn" },
		FIELD_EXPLANATION("Safety", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real, "dangerous trajectory prediction time", "How much the position is predicted by the velocity to check against potential collisions", "seconds" },
		{ _field_terminator }
	};

	#define REVENANT_BLOCK_ID { 0xF532AD7A, 0x164C4A28, 0x905A8AA1, 0xD0038D15 }
	TAG_BLOCK(
		revenant_block,
		"revenant_block",
		1,
		"s_vehicle_revenant_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | 
		SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		REVENANT_BLOCK_ID)
	{
		{ _field_struct, "tank block", &human_tank_struct },
		FIELD_EXPLANATION("velocity control variables", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real, "maximum forward speed" },
		{ _field_real, "maximum reverse speed" },
		{ _field_real, "speed acceleration" },
		{ _field_real, "speed deceleration" },
		{ _field_real, "maximum left slide" },
		{ _field_real, "maximum right slide" },
		{ _field_real, "slide acceleration" },
		{ _field_real, "slide deceleration" },
		{ _field_struct, "steering animation", &steering_animation_struct },
		FIELD_EXPLANATION("specific types", nullptr, FIELD_FLAG_NONE, "different types are treated differently alien scout controller"),
		{ _field_char_enum, "specific type", &alien_scout_specific_type_enum },
		{ _field_real, "drag coeficient" },
		{ _field_real, "constant deceleration" },
		{ _field_real, "torque scale", "0 defaults to 1" },
		FIELD_PAD("BLURBY", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_terminator }
	};

	#define SOUNDRTPCBLOCK_ID { 0x6EDCFD78, 0x11474177, 0xB8274D64, 0x1DD674B5 }
	TAG_BLOCK(
		SoundRTPCBlock_block,
		"SoundRTPCBlock",
		k_maxSoundRTPCBlocks,
		"vehicleSoundRTPCBlockDefinition",
		SET_UNKNOWN0 | SET_POSTPROCESS_RECURSIVELY | SET_IS_MEMCPYABLE | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SOUNDRTPCBLOCK_ID)
	{
		{ _field_long_block_index, "Attachment Index", "Sound attachment to affect", &global_object_attachment_block },
		{ _field_string_id, "Function", "Function to drive the RTPC" },
		{ _field_string_id, "RTPC Name", "WWise RTPC string name" },
		{ _field_long_integer, "RTPC name hash value", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define SOUNDSWEETENERBLOCK_ID { 0x443F16AA, 0x7A814B2A, 0x81FB74DE, 0xF7A23C5C }
	TAG_BLOCK(
		SoundSweetenerBlock_block,
		"SoundSweetenerBlock",
		k_maxSoundSweetenerBlocks,
		"vehicleSoundSweetenerBlockDefinition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SOUNDSWEETENERBLOCK_ID)
	{
		{ _field_string_id, "Function", "Function to trigger the sweetener" },
		{ _field_tag_reference, "sound", &global_sound_reference },
		{ _field_real, "Switch point", "value of the function (between 0 and 1) where the sound is triggered" },
		{ _field_long_integer, "Mode", "0 for triggering while function is decreasing, 1 for increasing (more modes to come?)" },
		{ _field_terminator }
	};

	#define PHYSICS_TRANSITIONS_BLOCK_ID { 0x16FD6B96, 0xFCF44A90, 0x8475A4B0, 0x61B5C28B }
	TAG_BLOCK(
		physics_transitions_block,
		"physics_transitions_block",
		k_max_vehicle_physics_transitions,
		"vehicle_physics_transition_definition",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PHYSICS_TRANSITIONS_BLOCK_ID)
	{
		{ _field_real, "transition velocity", "speed at which flight model transition occurs", "wu/s" },
		{ _field_real, "velocity threshold side", "0 if velocity should be smaller than transition value, else 1", "0 or 1" },
		{ _field_real, "transition throttle", "throttle input at which physics model transition occurs", "-1 to 1" },
		{ _field_real, "throttle threshold side", "0 if throttle should be smaller than transition value, else 1", "0 or 1" },
		{ _field_char_enum, "transition target vehicle type", "upon reaching transition velocity, act like this vehicle type", &vehicle_type_enum },
		FIELD_PAD("pad after transition target vehicle type", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_terminator }
	};

	#define PHANTOM_SHAPES_BLOCK_ID { 0x69696969, 0x69696969, 0x69696969, 0x69696420 } // #TODO: This should be a global havok structure when we import them
	TAG_BLOCK(
		phantom_shapes_block,
		"phantom_shapes_block",
		420, // Unknown constant, should be a havok global iirc -Ak
		"phantom_shapes_definition",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PHANTOM_SHAPES_BLOCK_ID)
	{
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_legacy, _field_long_integer, "Unknown" }, // rest in piss
		{ _field_terminator }
	};

	#define VEHICLE_STRUCT_DEFINITION_ID { 0xC6A4B989, 0x09714F2B, 0xBF522976, 0xF69B2344 }
	TAG_STRUCT(
		vehicle_struct_definition,
		"vehicle",
		"vehicle_group",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN4 | SET_UNKNOWN5 | 
		SET_UNKNOWN7 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS | 
		SET_UNKNOWN18,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		VEHICLE_STRUCT_DEFINITION_ID)
	{
		{ _field_struct, "unit", &unit_struct_definition },
		FIELD_CUSTOM("$$$ VEHICLE $$$", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_long_flags, "flags", &vehicle_flags },
		FIELD_EXPLANATION("physics type", nullptr, FIELD_FLAG_NONE, "define one of the following blocks for the type of physics you wish this vehicle to have."),
		{ _field_struct, "physics types", &vehicle_physics_types_struct },
		FIELD_EXPLANATION("friction and antigravity points", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_struct, "havok vehicle physics", &havok_vehicle_physics_struct },

		{ _field_legacy, _field_version_less, _engine_type_haloreach },
		{ _field_legacy, _field_block, "havok phantom shapes", &phantom_shapes_block }, // #TODO: replace with actual global havok block

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_block, "tricks", &unit_trick_definition_block },

		{ _field_char_enum, "player training vehicle type", &player_training_vehicle_type_enum },
		{ _field_char_enum, "vehicle size", "The size determine what kind of seats in larger vehicles it may occupy (i.e. small or large cargo seats)", &vehicle_size_enum },
		{ _field_char_integer, "complex suspension sample count", "How many additional raycasts to perform per side of a tire." },
		FIELD_PAD("VQWHV", nullptr, FIELD_FLAG_NONE, 1),

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 3 },
		{ _field_angle, "complex suspension distribution angle", "0-90 degrees of the wedge portion of the wheel to test suspension", "degrees" },
		{ _field_real, "complex suspension wheel diameter" },
		{ _field_real, "complex suspension wheel width" },

		{ _field_real, "minimum flipping angular velocity" },
		{ _field_real, "maximum flipping angular velocity" },
		{ _field_real, "crouch transition time", nullptr, "seconds" },
		{ _field_real, "HOOJYTSU", FIELD_FLAG_UNKNOWN0 },
		{ _field_real, "seat enterance acceleration scale", "how much do we scale the force the vehicle the applies down on the seat when he enters. 0 == no acceleration" },
		{ _field_real, "seat exit accelersation scale", "how much do we scale the force the vehicle the applies down on the seat when he exits. 0 == no acceleration" },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_real, "blur speed" },

		{ _field_legacy, _field_version_less, _engine_type_haloreach },
		{ _field_real, "flip time" }, // assembly #TODO: VALIDATE

		{ _field_string_id, "flip message" },
		FIELD_EXPLANATION("sounds and effects", nullptr, FIELD_FLAG_NONE, ""),

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_tag_reference, "Player vehicle sound bank", "High quality player sound bank to be prefetched. Can be empty.", &global_soundbank_reference },

		{ _field_tag_reference, "suspension sound", &global_sound_reference },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 7 },
		{ _field_real, "fake audio speed - speed increase amount", "amount to increase per frame while speeding up(.002 is a good number)" },
		{ _field_real, "fake audio speed - boost speed increase amount", "amount to increase per frame while boosting (.006 is a good number)" },
		{ _field_real, "fake audio speed - speed decrease amount", "amount to decrease per frame while slowing down (.002 is a good number)" },
		{ _field_real, "fake audio speed - non-boost limit", "max value while not boosting (maximum is 1)" },
		{ _field_real, "fake audio speed - max speed scale", "scales speed value. Must be > 0 for this to work (ie for banshee, 5 is good)" },
		{ _field_block, "Sound RTPCs", &SoundRTPCBlock_block },
		{ _field_block, "Sound Sweeteners", &SoundSweetenerBlock_block },

		{ _field_tag_reference, "special effect", &global_effect_reference },
		{ _field_tag_reference, "driver boost damage effect or response", &global_damage_effect_or_response_definition_reference },
		{ _field_tag_reference, "rider boost damage effect or response", &global_damage_effect_or_response_definition_reference },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 3 },
		{ _field_string_id, "vehicle name" },
		{ _field_block, "physics transitions", &physics_transitions_block },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),

		{ _field_terminator }
	};

	#define VEHICLE_PHYSICS_TYPES_STRUCT_ID { 0xC319BCC5, 0x75334227, 0x93E7A6C7, 0xCFF0752A }
	TAG_STRUCT(
		vehicle_physics_types_struct,
		"vehicle_physics_types_struct",
		"s_vehicle_physics_types",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		VEHICLE_PHYSICS_TYPES_STRUCT_ID)
	{
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_unknown_begin),
		{ _field_block, "type-human_tank", &human_tank_block },
		{ _field_block, "type-human_jeep", &human_jeep_block },
		{ _field_block, "type-human_plane", &human_plane_block },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_block, "type-wolverine", &wolverine_block },

		{ _field_block, "type-alien_scout", &alien_scout_block },
		{ _field_block, "type-alien_fighter", &alien_fighter_block },
		{ _field_block, "type-turret", &turret_block },

		{ _field_legacy, _field_version_less, _engine_type_haloreach, 3 }, // #TODO: Research this, another physics type IMPORTANT!!!
		{ _field_legacy, _field_long_integer, "unknown@" }, // Cloud be padding from a removed type
		{ _field_legacy, _field_long_integer, "unknown@" }, // Cloud be padding from a removed type
		{ _field_legacy, _field_long_integer, "unknown@" }, // Cloud be padding from a removed type

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_block, "type-mantis", &mantis_block },

		{ _field_block, "type-vtol", &vtol_block },
		{ _field_block, "type-chopper", &chopper_block },
		{ _field_block, "type-guardian", &guardian_block },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach, 4 },
		{ _field_block, "type-jackal-glider", &jackal_glider_block },
		{ _field_block, "type-boat", &boat_block },
		{ _field_block, "type-space-fighter", &space_fighter_block },
		{ _field_block, "type-revenant", &revenant_block },

		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_unknown_end),
		{ _field_terminator }
	};

	#define HUMAN_TANK_STRUCT_ID { 0x7AD171CF, 0x889B48FF, 0x9B3677D4, 0xF2E74E3B }
	TAG_STRUCT(
		human_tank_struct,
		"human_tank_struct",
		"s_vehicle_human_tank_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | 
		SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		HUMAN_TANK_STRUCT_ID)
	{
		{ _field_angle, "forward arc", "outside of this arc the vehicle reverse direciton, around 110 degrees seems to be nice..." },
		{ _field_angle, "perpendicular forward arc", "this is the value of forward arc when turned sideways.  We interpolate from forward arc to this value when camera becomes perpendicular to the vehicle" },
		
		{ _field_legacy, _field_version_less, _engine_type_haloreach },
		{ _field_angle, "reverse turning scale", "Think of this as oversteer, similar to the field above" }, // Assembly

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach, 4 },
		{ _field_real, "flip window", "seconds" },
		{ _field_real, "pegged fraction", "0-1" },
		{ _field_real, "forward turn scale", "think of this as oversteer" },
		{ _field_real, "reverse turn scale", "think of this as oversteer" },

		FIELD_EXPLANATION("forward differential", nullptr, FIELD_FLAG_NONE, "how quickly the differential reaches it\'s target and what the ratio is"),
		{ _field_real, "maximum left differential" },
		{ _field_real, "maximum right differential" },
		{ _field_real, "differential acceleration" },
		{ _field_real, "differential deceleration" },
		FIELD_EXPLANATION("reverse differential", nullptr, FIELD_FLAG_NONE, "how quickly the differential reaches it\'s target and what the ratio is"),
		{ _field_real, "maximum left reverse differential" },
		{ _field_real, "maximum right reverse differential" },
		{ _field_real, "differential reverse acceleration" },
		{ _field_real, "differential reverse deceleration" },
		{ _field_struct, "engine", &global_vehicle_engine_struct },
		FIELD_EXPLANATION("wheel circumferance", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real, "wheel circumferance" },
		{ _field_real, "gravity adjust", "0-1 fraction by which we scale gravity that is not along the ground plane" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 11 },
		FIELD_EXPLANATION("New Tank Controls", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_byte_flags, "control flags", &tank_flags },
		FIELD_PAD("pad", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_real, "at rest forward angle(purple)" },
		{ _field_real, "at rest reverse angle(violet)" },
		{ _field_real, "at rest side on reverse angle closest to front(green)", "first angle starting arc in which the control will cause the tank to reverse while at rest and facing side on" },
		{ _field_real, "at rest side on reverse angle furthest from front(blue)", "second angle ending arc in which the control will cause the tank to reverse while at rest and facing side on" },
		{ _field_real, "at rest facing forward reverse angle(yellow)", "angle forming arc in which the control will cause the tank to reverse while at rest and facing forward" },
		{ _field_real, "at rest facing backward reverse angle(pink)", "#angle forming arc in which the control will cause the tank to reverse while at rest and facing backwards" },
		{ _field_real, "in motion opposing direction angle", "when in motion the angle in which the control must be to start moving in the opposite direction" },
		{ _field_real, "in motion speed", "the speed a tank must reach before we consider it in motion, changing the control mode" },

		{ _field_terminator }
	};

	#define VEHICLE_STEERING_CONTROL_STRUCT_ID { 0x2B36CF56, 0x040E4806, 0xAE2A1F64, 0x89A6F9B2 }
	TAG_STRUCT(
		vehicle_steering_control_struct,
		"vehicle_steering_control_struct",
		"s_vehicle_steering_control_definition",
		SET_POSTPROCESS_RECURSIVELY | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		VEHICLE_STEERING_CONTROL_STRUCT_ID)
	{
		FIELD_EXPLANATION("steering overdampening", nullptr, FIELD_FLAG_NONE, "when the steering is off by more than the cusp angle\nthe steering will overcompensate more and more.  when it\nis less, it overcompensates less and less.  the exponent\nshould be something in the neighborhood of 2.0\n"),
		{ _field_real, "overdampen cusp angle", nullptr, "degrees" },
		{ _field_real, "overdampen exponent" },
		{ _field_terminator }
	};

	#define VEHICLE_TURNING_CONTROL_STRUCT_ID { 0x36D7646B, 0xE70A47D1, 0x98AF489E, 0x9B5C63F1 }
	TAG_STRUCT(
		vehicle_turning_control_struct,
		"vehicle_turning_control_struct",
		"s_vehicle_turning_control_definition",
		SET_POSTPROCESS_RECURSIVELY | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		VEHICLE_TURNING_CONTROL_STRUCT_ID)
	{
		FIELD_EXPLANATION("turning", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real, "maximum left turn" },
		{ _field_real, "maximum right turn (negative)" },
		{ _field_real, "turn rate" },
		{ _field_terminator }
	};

	#define STEERING_ANIMATION_STRUCT_ID { 0xA551DA10, 0x1D3F4100, 0x9C4C60D2, 0x46D74662 }
	TAG_STRUCT(
		steering_animation_struct,
		"steering_animation_struct",
		"s_vehicle_steering_animation_definition",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		STEERING_ANIMATION_STRUCT_ID)
	{
		FIELD_EXPLANATION("steering animation and interpolation\n", nullptr, FIELD_FLAG_NONE, "This data controls the depiction of steering \nthrough animation - not the vehicles ability to turn\ninterpolation scale= how much we interpolate between steering poses.\nmax angle= max animated steering angle change allowed per tick.\n"),
		{ _field_real, "interpolation scale", "1= heavy interp. of steering animations" },
		{ _field_angle, "max angle", "non-zero= max angle delta per frame" },
		{ _field_terminator }
	};

	#define ENGINE_FUNCTION_STRUCT_ID { 0xFAE37480, 0x13E14F26, 0xA1CB57D9, 0xD755D2D0 }
	TAG_STRUCT(
		engine_function_struct,
		"engine_function_struct",
		"s_engine_function_definition",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		ENGINE_FUNCTION_STRUCT_ID)
	{
		{ _field_string_id, "object function damage region", "this is the name of the region by which we gauge the overall damage of the vehicle" },
		{ _field_real, "min anti gravity engine speed", "speed at which engine position funciton  moves.  value of 1 means goes from 0-1 in 1 second" },
		{ _field_real, "max anti gravity engine speed", "speed at which engine position funciton  moves.  value of 1 means goes from 0-1 in 1 second" },
		{ _field_real, "engine speed acceleration", "strictly used for object funtion. in 0-1 space" },
		{ _field_real, "maximum vehicle speed", "function is capped by speed of the vehicle. So when we slow down for any reason we see the function go down" },
		{ _field_terminator }
	};

	#define VTOL_DESCENT_FUNCTION_STRUCT_ID { 0x54DB0E84, 0x09D24B82, 0xA95666A4, 0x8EE43895 }
	TAG_STRUCT(
		vtol_descent_function_struct,
		"vtol_descent_function_struct",
		"s_vtol_descent_function",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		VTOL_DESCENT_FUNCTION_STRUCT_ID)
	{
		{ _field_struct, "descent to boost", &scalar_function_named_struct },
		{ _field_real, "max downward speed", nullptr, "wu/s", _field_id_function_unknown },
		{ _field_terminator }
	};

	#define FLIGHT_SURFACE_STRUCT_ID { 0xFAEAB480, 0x1A314F26, 0xA1C012D9, 0xD7ABD2D0 }
	TAG_STRUCT(
		flight_surface_struct,
		"flight_surface_struct",
		"s_flight_surface_definition",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		FLIGHT_SURFACE_STRUCT_ID)
	{
		{ _field_char_enum, "offset axis", &dimensions_enum },
		{ _field_char_enum, "pivot axis", &dimensions_enum },
		{ _field_char_enum, "rotation axis", &dimensions_enum },
		{ _field_char_enum, "normal axis", &dimensions_enum },
		{ _field_real, "offset distance" },
		{ _field_real, "pivot distance" },
		FIELD_EXPLANATION("normal force", nullptr, FIELD_FLAG_NONE, "force= k*CEILING(SQR(q*velocity), function_ceiling)"),
		{ _field_real, "q" },
		{ _field_real, "k" },
		{ _field_real, "function ceiling" },
		{ _field_angle, "maximum angle" },
		{ _field_real, "render debug radius" },
		{ _field_terminator }
	};

	#define JACKAL_GLIDER_DRAG_STRUCT_ID { 0xFAEAB498, 0x1A314FAB, 0xACD012D9, 0xD7ABD2D0 }
	TAG_STRUCT(
		jackal_glider_drag_struct,
		"jackal_glider_drag_struct",
		"s_vehicle_jackal_glider_drag_definition",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		JACKAL_GLIDER_DRAG_STRUCT_ID)
	{
		FIELD_EXPLANATION("drag", nullptr, FIELD_FLAG_NONE, "drag= k*SQR(q*velocity) + constant deceleration"),
		{ _field_real, "q" },
		{ _field_real, "k" },
		{ _field_real, "constant deceleration" },
		{ _field_terminator }
	};

	STRINGS(vehicle_flags)
	{
		"no friction w/driver",
		"autoaim when teamless",
		"ai weapon cannot rotate",
		"ai does not require driver",
		"ai driver enable",
		"ai driver flying",
		"ai driver can-sidestep",
		"ai driver hovering",
		"noncombat vehicle",
		"does not cause collision damage",
		"huge vehicle physics group",
		"enable wheelie-popping hack",
		"ai auto turret#will attempt to spawn Unit\'s \'spawned turret character\' to control this turret",
		"ai sentry turret",
		"ignore camera pitch",
		"auto turret#will be ignored if \'ai auto turret\' is set in campaign or survival",
		"ignore kill volumes#Suppress kill volume checks performed by unmanned vehicles (needed by RemoteStrike/power weapon ordnance)",
		"targetable when open#makes this targetable if it is in an open state",
		"vehicle wants to recieve reduced weapon acceleration when on ground#if set, vehicle will use all tag damage_effect->alt instantaneous acceleration fields if it is on the ground",
		"vehicle wants to recieve reduced weapon acceleration when airborne#if set, vehicle will use all tag damage_effect->alt instantaneous acceleration fields if it is airborne",
		"do not force units to exit when upside down",
		"vehicle creates enemy spawn influencers#Used for Dominion Sentry Turrets, which enemies should not spawn in range of",
		"driver cannot take damage",
		"player cannot flip vehicle#the player isn\'t allowed to flip the vehicle under any circumstances"
	};
	STRING_LIST(vehicle_flags, vehicle_flags_strings, _countof(vehicle_flags_strings));

	STRINGS(vehicle_size_enum)
	{
		"small",
		"large"
	};
	STRING_LIST(vehicle_size_enum, vehicle_size_enum_strings, _countof(vehicle_size_enum_strings));

	STRINGS(alien_scout_specific_type_enum)
	{
		"none",
		"ghost",
		"spectre",
		"wraith",
		"hover craft"
	};
	STRING_LIST(alien_scout_specific_type_enum, alien_scout_specific_type_enum_strings, _countof(alien_scout_specific_type_enum_strings));

	STRINGS(vehicle_type_enum)
	{
		"vehicle_type_human_tank",
		"vehicle_type_human_jeep",
		"vehicle_type_human_plane",
		"vehicle_type_wolverine",
		"vehicle_type_alien_scout",
		"vehicle_type_alien_fighter",
		"vehicle_type_turret",
		"vehicle_type_mantis",
		"vehicle_type_vtol",
		"vehicle_type_chopper",
		"vehicle_type_guardian",
		"vehicle_type_jackal_glider",
		"vehicle_type_boat",
		"vehicle_type_space_fighter",
		"vehicle_type_revenant"
	};
	STRING_LIST(vehicle_type_enum, vehicle_type_enum_strings, _countof(vehicle_type_enum_strings));

	STRINGS(alien_scout_flags)
	{
		"locked camera"
	};
	STRING_LIST(alien_scout_flags, alien_scout_flags_strings, _countof(alien_scout_flags_strings));

	STRINGS(tank_flags)
	{
		"Enable New Control",
		"Use Linear Velocity#Used to decide if we use linear velocity to calculate if we are in motion",
		"Use Angular Velocity#Used to decide if we use angular velocity to calculate if we are in motion"
	};
	STRING_LIST(tank_flags, tank_flags_strings, _countof(tank_flags_strings));

	STRINGS(dimensions_enum)
	{
		"foward",
		"left",
		"up"
	};
	STRING_LIST(dimensions_enum, dimensions_enum_strings, _countof(dimensions_enum_strings));

	STRINGS(turret_flags)
	{
		"powered by parent#this is basicly a flag for the wolverine.  This turret pops up when the wolverine activates",
		"idles in default position#this turret holds its default position instead of swinging freely when not controlled",
		"reverse yaw motor direction",
		"reverse pitch motor direction",
		"reverse elevate motor direction",
		"targetable when open"
	};
	STRING_LIST(turret_flags, turret_flags_strings, _countof(turret_flags_strings));

	STRINGS(boat_flags)
	{
		"brick on throttle#use this for torpedoes",
		"use tank controls"
	};
	STRING_LIST(boat_flags, boat_flags_strings, _countof(boat_flags_strings));

	STRINGS(space_fighter_turn_back_flags)
	{
		"turn back to tangent"
	};
	STRING_LIST(space_fighter_turn_back_flags, space_fighter_turn_back_flags_strings, _countof(space_fighter_turn_back_flags_strings));

	STRINGS(space_fighter_roll_flags)
	{
		"use new roll"
	};
	STRING_LIST(space_fighter_roll_flags, space_fighter_roll_flags_strings, _countof(space_fighter_roll_flags_strings));

} // namespace macaque

} // namespace blofeld

