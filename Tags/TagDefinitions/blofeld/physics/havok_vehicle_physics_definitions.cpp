#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_BLOCK(anti_gravity_point_definition_block, k_maximum_anti_gravity_points_per_vehicle_physics_definition)
	{
		{ _field_custom },
		{ _field_string_id, "marker name^" },
		{ _field_long_flags, "flags", &anti_gravity_point_definition_flags },

		{ _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_long_enum, "damping", &anti_gravity_point_definition_damping },

		{ _field_custom },
		{ _field_real, "antigrav strength" },

		{ _field_version_less, _engine_type_haloreach },
		{ _field_real, "antigrav offset" },

		{ _field_real, "antigrav height" },

		{ _field_version_less, _engine_type_haloreach },
		{ _field_real, "antigrav damp factor" },

		{ _field_version_greater_or_equal, _engine_type_haloreach, 2 },
		{ _field_real, "antigrav compression damping{antigrav damp factor}" },
		{ _field_real, "antigrav extension damping" },

		{ _field_real, "antigrav normal k1" },
		{ _field_real, "antigrav normal k0" },
		{ _field_real, "radius" },

		{ _field_version_less, _engine_type_haloreach, 5 },
		{ _field_long_integer, "unused!" },
		{ _field_long_integer, "unused!" },
		{ _field_long_integer, "unused!" },
		{ _field_pad, "pad", 2 },
		{ _field_short_integer, "runtime damage source region index" },

		{ _field_version_greater_or_equal, _engine_type_haloreach, 4 },
		{ _field_custom },
		{ _field_string_id, "collision global material name" },
		{ _field_short_integer, "runtime global material index!" },
		{ _field_short_integer, "WU!" },

		{ _field_string_id, "damage source region name" },
		{ _field_real, "default state error" },
		{ _field_real, "minor damage error" },
		{ _field_real, "medium damage error" },
		{ _field_real, "major damage error" },
		{ _field_real, "destroyed state error" },
		{ _field_terminator }
	};

	TAG_BLOCK(friction_point_definition_block, k_maximum_friction_points_per_vehicle_physics_definition)
	{
		{ _field_custom },
		{ _field_string_id, "marker name^" },
		{ _field_long_flags, "flags", &friction_point_definition_flags },
		{ _field_custom },
		{ _field_real, "fraction of total mass#(0.0-1.0) fraction of total vehicle mass" },
		{ _field_real, "radius" },
		{ _field_real, "damaged radius#radius when the tire is blown off." },

		{ _field_version_less, _engine_type_haloreach },
		{ _field_enum, "friction type", &friction_type_enum }, //h2ek

		{ _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_real, "ground friction scale# scale the non sliding friction on this friction point" },
		{ _field_real, "AI ground friction scale override# use this value when an AI is driving" },

		{ _field_version_less, _engine_type_haloreach },
		{ _field_short_integer, "unknown@" },

		{ _field_real, "moving friction velocity diff" },

		{ _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_real, "moving friction scale# scale the sliding friction on this friction point, active when velocity is greater than moving friction velocity diff" },
		{ _field_real, "AI moving friction scale override# use this value when an AI is driving" },

		{ _field_real, "e-brake moving friction" },
		{ _field_real, "e-brake friction" },
		{ _field_real, "e-brake moving friction vel diff" },

		{ _field_version_less, _engine_type_haloreach, 5 },
		{ _field_long_integer, "unknown@" },
		{ _field_long_integer, "unknown@" },
		{ _field_long_integer, "unknown@" },
		{ _field_long_integer, "unknown@" },
		{ _field_long_integer, "unknown@" },

		{ _field_custom },
		{ _field_string_id, "collision global material name" },
		{ _field_short_integer, "runtime global material index!" },
		{ _field_explanation, "friction point destruction data", "" },
		{ _field_enum, "model state destroyed#only need point can destroy flag set", &model_state_enum_definition },
		{ _field_string_id, "region name#only need point can destroy flag set" },
		{ _field_long_integer, "runtime region index!" },
		{ _field_terminator }
	};

	TAG_STRUCT(havok_vehicle_physics_struct)
	{
		{ _field_long_flags, "flags*", &havok_vehicle_physics_definition_flags },
		{ _field_custom },
		{ _field_real, "ground friction#this sucks.  for friction based vehicles only" },
		{ _field_real, "ground depth#this sucks.  for friction based vehicles only" },
		{ _field_real, "ground damp factor#this sucks.  for friction based vehicles only" },
		{ _field_real, "ground moving friction#this sucks.  for friction based vehicles only" },
		{ _field_real, "ground maximum slope 0#degrees 0-90" },
		{ _field_real, "ground maximum slope 1#degrees 0-90.  and greater than slope 0" },
		{ _field_real, "maximum normal force contribution#0 defaults to 3, this prevents the physics from becoming unstable when hucked against a surface" },
		{ _field_real, "anti_gravity_bank_lift#lift per WU." },
		{ _field_real, "steering_bank_reaction_scale#how quickly we bank when we steer " },
		{ _field_real, "gravity scale#value of 0 defaults to 1.  .5 is half gravity" },

		{ _field_version_less, _engine_type_haloreach, 4 },
		{ _field_real, "radius" },
		{ _field_real, "unknown@" },
		{ _field_real, "unknown@" },
		{ _field_real, "unknown@" },

		{_field_version_greater_or_equal, _engine_type_haloreach, 5},
		{ _field_custom },
		{ _field_enum, "maximum update period ticks#ticks. 0 is default of 2", &physics_update_period_enum },
		{ _field_enum, "maximum remote update period ticks#ticks. when controlled by an ai or remote player. 0 defaults to 4", &physics_update_period_enum },
		{ _field_long_integer, "iteration count# 0 defaults to 1.  Number of iterations per frame of physics" },
		{ _field_long_integer, "suspension count*!" },

		{ _field_block, "anti gravity points", &anti_gravity_point_definition_block_block },
		{ _field_block, "friction points", &friction_point_definition_block_block },

		{ _field_version_greater_or_equal, _engine_type_haloreach, 1 },
		{ _field_struct, "boat physics", &boat_physics_definition_struct_struct_definition },

		{ _field_terminator }
	};

	STRINGS(anti_gravity_point_definition_flags)
	{
		"gets damage from region",
		"only active on water"
	};
	STRING_LIST(anti_gravity_point_definition_flags, anti_gravity_point_definition_flags_strings, _countof(anti_gravity_point_definition_flags_strings));

	STRINGS(anti_gravity_point_definition_damping)
	{
		"normal",
		"damped left",
		"damped right",
		"undamped left",
		"undamped right"
	};
	STRING_LIST(anti_gravity_point_definition_damping, anti_gravity_point_definition_damping_strings, _countof(anti_gravity_point_definition_damping_strings));

	STRINGS(friction_point_definition_flags)
	{
		"gets damage from region",
		"powered",
		"front turning",
		"rear turning",
		"AI force rear turning",
		"attached to e-brake",
		"can be destroyed",
		"AI override ground friction scale",
		"AI override moving friction scale"
	};
	STRING_LIST(friction_point_definition_flags, friction_point_definition_flags_strings, _countof(friction_point_definition_flags_strings));

	STRINGS(friction_type_enum)
	{
		"point",
		"forward"
	};
	STRING_LIST(friction_type_enum, friction_type_enum_strings, _countof(friction_type_enum_strings));

	STRINGS(havok_vehicle_physics_definition_flags)
	{
		"has suspension*!",
		"friction points test only environment"
	};
	STRING_LIST(havok_vehicle_physics_definition_flags, havok_vehicle_physics_definition_flags_strings, _countof(havok_vehicle_physics_definition_flags_strings));

	STRINGS(physics_update_period_enum)
	{
		"defaults (every other frame)",
		"every frame",
		"every other frame",
		"every 3rd frame",
		"every 4th frame",
		"every 5th frame",
		"every 6th frame",
		"every 7th frame",
		"every 8th frame"
	};
	STRING_LIST(physics_update_period_enum, physics_update_period_enum_strings, _countof(physics_update_period_enum_strings));

} // namespace blofeld

