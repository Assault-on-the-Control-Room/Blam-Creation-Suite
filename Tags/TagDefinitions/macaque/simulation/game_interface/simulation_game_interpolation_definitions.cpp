#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		simulation_interpolation_group,
		SIMULATION_INTERPOLATION_TAG,
		nullptr,
		INVALID_TAG,
		simulation_interpolation_block );

	TAG_BLOCK_FROM_STRUCT(
		simulation_interpolation_block,
		"simulation_interpolation_block",
		1,
		simulation_interpolation_struct_definition);

	#define SIMULATION_INTERPOLATION_STRUCT_DEFINITION_ID { 0x2FACCEF0, 0x5C3B4A32, 0x8DF1C551, 0x349A3F4A }
	TAG_STRUCT(
		simulation_interpolation_struct_definition,
		"simulation_interpolation_struct_definition",
		"s_simulation_interpolation_definition",
		SIMULATION_INTERPOLATION_STRUCT_DEFINITION_ID)
	{
		{ _field_explanation, "SIMULATION INTERPOLATION", "This tag defines interpolation that will be used to smooth the motion of objects in distributed multiplayer games.  In bandwidth-constrained multiplayer games (i.e. most games), we will receive only one or two updates per second for faraway objects.  Even near objects may frequently be dropped to <5 updates per second, especially crates, garbage bits, and similar less important elements of the simulation.  Between updates, each peer predicts the motion of each object.  These predictions are often wrong (by anything from an inch to dozens of feet).  The simulation interpolation system is responsible for correcting these mispredictions in as aesthetically pleasing a way as possible, without harming the integrity of the game.  The details of the technical implementation are beyond the scope of this explanation, but various configuration parameters are exposed here.  \n\nThe tooltips for each configuration parameter should be helpful.  Please see daldridge w/ questions or bugs." },
		FIELD_CUSTOM("High level settings", _custom_field_function_group_begin),
		{ _field_real, "position_client_ignore_tolerance:WU#How much rope clients have WRT their controlled object of this type. They are free to ignore host updates within this tolerance." },
		{ _field_real, "angular_speed_threshold_for_temporarily_ignoring_rotation_updates:degrees per second#If angular speed exceeds this threshold, we will ignore rotational updates (because it\'s spinning so fast that we can\'t possibly do a good job w/ any kind of interpolation - instead, just wait for it to settle down a bit).  Note that if a warp threshold is exceeded, rotation will be warped regardless of the value of this parameter." },
		FIELD_CUSTOM("Warp Thresholds", _custom_field_function_group_begin),
		{ _field_explanation, "WARP THRESHOLDS", "If any of the warp thresholds (position or rotation, global or xy) are exceeded, a warp in all domains (position and rotation) is executed." },
		{ _field_real, "position_warp_threshold:WU#Threshold of position error beyond which we will warp instead of interpolating." },
		{ _field_real, "position_warp_threshold_xy:WU#Separated for bipeds, for whom z discrepancies are more permissible because of jumping. If you don\'t want a special lower XY threshold, just set this to a very high number." },
		{ _field_real, "rotation_warp_threshold:degrees#Threshold of rotation error beyond which we will warp instead of interpolating.  Set this to 180.0 if you don\'t want to warp based on rotational deviation (may be important for objects that often spin very fast, e.g. grenades or garbage bits)." },
		FIELD_CUSTOM(nullptr, _custom_field_function_group_end),
		FIELD_CUSTOM(nullptr, _custom_field_function_group_end),
		FIELD_CUSTOM("Position while controlled", _custom_field_function_group_begin),
		{ _field_struct, "position_while_controlled#All speeds in here are WU/s", &single_domain_configuration_struct },
		FIELD_CUSTOM(nullptr, _custom_field_function_group_end),
		FIELD_CUSTOM("Rotation while controlled", _custom_field_function_group_begin),
		{ _field_struct, "rotation_while_controlled#All speeds in here are degrees/s", &single_domain_configuration_struct },
		FIELD_CUSTOM(nullptr, _custom_field_function_group_end),
		FIELD_CUSTOM("Position while not controlled", _custom_field_function_group_begin),
		{ _field_struct, "position_while_uncontrolled#All speeds in here are WU/s", &single_domain_configuration_struct },
		FIELD_CUSTOM(nullptr, _custom_field_function_group_end),
		FIELD_CUSTOM("Rotation while not controlled", _custom_field_function_group_begin),
		{ _field_struct, "rotation_while_uncontrolled#All speeds in here are degrees/s", &single_domain_configuration_struct },
		FIELD_CUSTOM(nullptr, _custom_field_function_group_end),
		{ _field_terminator }
	};

	#define SINGLE_DOMAIN_CONFIGURATION_STRUCT_ID { 0xE844485C, 0x782542A7, 0xB852650A, 0x3EC8A1C7 }
	TAG_STRUCT(
		single_domain_configuration_struct,
		"single_domain_configuration_struct",
		"s_simulation_single_domain_interpolation_configuration",
		SINGLE_DOMAIN_CONFIGURATION_STRUCT_ID)
	{
		{ _field_explanation, "SINGLE DOMAIN INTERPOLATION", "Note that if either the position or rotation discrepancy thresholds above which we use blending are exceeded, we will blend in both domains (because blending is more accurate and once we blend in either domain, we are forced to warp the physics representation of the object, which is the main downside of blending.  Therefore, the second domain is essentially \"free\" after we pay for the first w/ a physics warp.\n\nNote also that this discrepancy threshold is either WU or degrees, depending on context.  Check your context!" },
		{ _field_real, "discrepancy_threshold_above_which_we_use_blending:WU or degrees#Below this threshold we use velocity bumps." },
		{ _field_real, "coming_to_rest_speed:WU/s or degrees/s#When our velocity is below this threshold, we will consider using a blend to minimize at-rest error." },
		{ _field_real, "coming_to_rest_maximum_ignorable_error:WU or degrees#We will use a blend when our speed is below the coming_to_rest_speed and our error is greater than this." },
		FIELD_CUSTOM("Velocity bumps", _custom_field_function_group_begin),
		{ _field_struct, "velocity bumps", &single_domain_velocity_bumps_configuration_struct },
		FIELD_CUSTOM(nullptr, _custom_field_function_group_end),
		FIELD_CUSTOM("Blending", _custom_field_function_group_begin),
		{ _field_struct, "blending", &single_domain_blending_configuration_struct },
		FIELD_CUSTOM(nullptr, _custom_field_function_group_end),
		{ _field_terminator }
	};

	#define SINGLE_DOMAIN_VELOCITY_BUMPS_CONFIGURATION_STRUCT_ID { 0xE01ED32B, 0x4AC44923, 0xA38213D0, 0x8598722B }
	TAG_STRUCT(
		single_domain_velocity_bumps_configuration_struct,
		"single_domain_velocity_bumps_configuration_struct",
		"s_simulation_single_domain_velocity_bumps_configuration",
		SINGLE_DOMAIN_VELOCITY_BUMPS_CONFIGURATION_STRUCT_ID)
	{
		{ _field_explanation, "SINGLE DOMAIN VELOCITY BUMPS", "Velocity bumps are used for small mis-predictions because they are more visually pleasing than straight blending. However, they are less accurate, less consistent, and harder to tune." },
		{ _field_real, "velocity_scale#Fraction of delta that becomes the velocity bump" },
		{ _field_real, "velocity_min:WU or degrees per second#Minimum size of any given velocity bump" },
		{ _field_real, "velocity_max:WU or degrees per second#Maximum size of any given velocity bump" },
		{ _field_explanation, "Velocity Bump Suppression", "We suppress velocity bumps when the object is \"close enough\" to encourage objects to come to rest. Both of the below conditions must be satisfied to suppress velocity bumps." },
		{ _field_real, "velocity_difference_ignore_threshold:WU or degrees per second#The new velocity must differ from the old velocity by less than this to allow suppression." },
		{ _field_real, "velocity_difference_absolute_ignore_threshold:WU or degrees#The new position/rotation must differ from the old position/rotation by less than this to allow suppression." },
		{ _field_terminator }
	};

	#define SINGLE_DOMAIN_BLENDING_CONFIGURATION_STRUCT_ID { 0x47E921D4, 0x65AB4EBE, 0x8A71EF41, 0x224410B1 }
	TAG_STRUCT(
		single_domain_blending_configuration_struct,
		"single_domain_blending_configuration_struct",
		"s_simulation_single_domain_blending_configuration",
		SINGLE_DOMAIN_BLENDING_CONFIGURATION_STRUCT_ID)
	{
		{ _field_explanation, "SINGLE DOMAIN BLENDING CONFIGURATION", "Whether these speeds are linear or angular depends on the context - check context before modifying." },
		{ _field_real, "min_object_speed:WU or degrees per second#Approximate minimum speed for this object (either controlled or uncontrolled)." },
		{ _field_real, "max_object_speed:WU or degrees per second#Approximate maximum speed for this object (either controlled or uncontrolled)." },
		{ _field_real, "fraction_at_min_object_speed#Fraction of misprediction error consumed each tick if object is traveling at or below min_object_speed.  Linterp is executed at intermediate object speeds." },
		{ _field_real, "fraction_at_max_object_speed#Fraction of misprediction error consumed each tick if object is traveling at or above max_object_speed.  Linterp is executed at intermediate object speeds." },
		{ _field_real, "min_speed_at_min_object_speed:WU or degrees per second#Minimum misprediction error consumption speed if object is at or below min_object_speed.  Linterp is executed at intermediate object speeds." },
		{ _field_real, "min_speed_at_max_object_speed:WU or degrees per second#Minimum misprediction error consumption speed if object is at or above max_object_speed. Linterp is executed at intermediate object speeds." },
		{ _field_terminator }
	};

	TAG_REFERENCE(global_simulation_interpolation_reference, SIMULATION_INTERPOLATION_TAG);

} // namespace macaque

} // namespace blofeld

