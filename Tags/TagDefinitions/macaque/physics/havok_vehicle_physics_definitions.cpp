#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define ANTI_GRAVITY_POINT_DEFINITION_BLOCK_ID { 0x9001A182, 0x08DF4B6F, 0x8425443F, 0xF6CA64AD }
	TAG_BLOCK(
		anti_gravity_point_definition_block,
		"anti_gravity_point_definition_block",
		k_maximum_anti_gravity_points_per_vehicle_physics_definition,
		"s_anti_gravity_point_definition",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		ANTI_GRAVITY_POINT_DEFINITION_BLOCK_ID)
	{
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_marker),
		{ _field_string_id, "marker name", FIELD_FLAG_INDEX },
		{ _field_long_flags, "flags", &anti_gravity_point_definition_flags },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_long_enum, "damping", &anti_gravity_point_definition_damping },

		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_unknown_begin),
		{ _field_real, "antigrav strength" },

		{ _field_legacy, _field_version_less, _engine_type_haloreach }, // Source?
		{ _field_legacy, _field_real, "antigrav offset" },

		{ _field_real, "antigrav height" },

		{ _field_legacy, _field_version_less, _engine_type_haloreach },
		{ _field_legacy, _field_real, "antigrav damp factor" },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach, 2 },
		{ _field_real, "antigrav compression damping", MAKE_OLD_NAMES("antigrav damp factor") },
		{ _field_real, "antigrav extension damping" },

		{ _field_real, "antigrav normal k1" },
		{ _field_real, "antigrav normal k0" },
		{ _field_real, "radius" },

		{ _field_legacy, _field_version_less, _engine_type_haloreach, 5 }, // Source?
		{ _field_legacy, _field_long_integer, "unused!" },
		{ _field_legacy, _field_long_integer, "unused!" },
		{ _field_legacy, _field_long_integer, "unused!" },
		{ _field_legacy, _field_pad, "pad", 2 },
		{ _field_legacy, _field_short_integer, "runtime damage source region index" },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach, 4 },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_unknown_end),
		{ _field_string_id, "collision global material name" },
		{ _field_short_integer, "runtime global material index", FIELD_FLAG_UNKNOWN0 },
		{ _field_short_integer, "WU", FIELD_FLAG_UNKNOWN0 },

		{ _field_string_id, "damage source region name" },
		{ _field_real, "default state error" },
		{ _field_real, "minor damage error" },
		{ _field_real, "medium damage error" },
		{ _field_real, "major damage error" },
		{ _field_real, "destroyed state error" },
		{ _field_terminator }
	};

	#define FRICTION_POINT_DEFINITION_BLOCK_ID { 0x1694B591, 0xC73D42A9, 0x9D1207F5, 0xEFCEF368 }
	TAG_BLOCK(
		friction_point_definition_block,
		"friction_point_definition_block",
		k_maximum_friction_points_per_vehicle_physics_definition,
		"s_friction_point_definition",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		FRICTION_POINT_DEFINITION_BLOCK_ID)
	{
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_marker),
		{ _field_string_id, "marker name", FIELD_FLAG_INDEX },
		{ _field_long_flags, "flags", &friction_point_definition_flags },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_unknown_begin),
		{ _field_real, "fraction of total mass", "(0.0-1.0) fraction of total vehicle mass" },
		{ _field_real, "radius" },
		{ _field_real, "damaged radius", "radius when the tire is blown off." },

		{ _field_legacy, _field_version_less, _engine_type_haloreach },
		{ _field_legacy, _field_enum, "friction type", &friction_type_enum }, //h2ek

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_real, "ground friction scale", "scale the non sliding friction on this friction point" },
		{ _field_real, "AI ground friction scale override", "use this value when an AI is driving" },

		{ _field_legacy, _field_version_less, _engine_type_haloreach },
		{ _field_legacy, _field_short_integer, "@unknown" },

		{ _field_real, "moving friction velocity diff" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_real, "moving friction scale", "scale the sliding friction on this friction point, active when velocity is greater than moving friction velocity diff" },
		{ _field_real, "AI moving friction scale override", "use this value when an AI is driving" },

		{ _field_real, "e-brake moving friction" },
		{ _field_real, "e-brake friction" },
		{ _field_real, "e-brake moving friction vel diff" },

		{ _field_legacy, _field_version_less, _engine_type_haloreach, 5 },
		{ _field_legacy, _field_long_integer, "unknown@" },
		{ _field_legacy, _field_long_integer, "unknown@" },
		{ _field_legacy, _field_long_integer, "unknown@" },
		{ _field_legacy, _field_long_integer, "unknown@" },
		{ _field_legacy, _field_long_integer, "unknown@" },

		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_unknown_end),
		{ _field_string_id, "collision global material name" },
		{ _field_short_integer, "runtime global material index", FIELD_FLAG_UNKNOWN0 },
		FIELD_EXPLANATION("friction point destruction data", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_enum, "model state destroyed", "only need point can destroy flag set", &model_state_enum_definition },
		{ _field_string_id, "region name", "only need point can destroy flag set" },
		{ _field_long_integer, "runtime region index", FIELD_FLAG_UNKNOWN0 },
		{ _field_terminator }
	};

	STRINGS(friction_type_enum)
	{
		"point",
		"forward"
	};
	STRING_LIST(friction_type_enum, friction_type_enum_strings, _countof(friction_type_enum_strings));


	#define HAVOK_VEHICLE_PHYSICS_STRUCT_ID { 0xF61F67DF, 0xEC364DFE, 0x9AB565F7, 0x2D6F7EA8 }
	TAG_STRUCT(
		havok_vehicle_physics_struct,
		"havok_vehicle_physics_struct",
		"s_havok_vehicle_physics_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		HAVOK_VEHICLE_PHYSICS_STRUCT_ID)
	{
		{ _field_long_flags, "flags", FIELD_FLAG_READ_ONLY, &havok_vehicle_physics_definition_flags },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_unknown_begin),
		{ _field_real, "ground friction", "this sucks.  for friction based vehicles only" },
		{ _field_real, "ground depth", "this sucks.  for friction based vehicles only" },
		{ _field_real, "ground damp factor", "this sucks.  for friction based vehicles only" },
		{ _field_real, "ground moving friction", "this sucks.  for friction based vehicles only" },
		{ _field_real, "ground maximum slope 0", "degrees 0-90" },
		{ _field_real, "ground maximum slope 1", "degrees 0-90.  and greater than slope 0" },
		{ _field_real, "maximum normal force contribution", "0 defaults to 3, this prevents the physics from becoming unstable when hucked against a surface" },
		{ _field_real, "anti_gravity_bank_lift", "lift per WU." },
		{ _field_real, "steering_bank_reaction_scale", "how quickly we bank when we steer " },
		{ _field_real, "gravity scale", "value of 0 defaults to 1.  .5 is half gravity" },

		{ _field_legacy, _field_version_less, _engine_type_haloreach, 4 },
		{ _field_real, "radius" },
		{ _field_real, "@unknown" },
		{ _field_real, "@unknown" },
		{ _field_real, "@unknown" },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach, 5 }, // rip field id end, fix this later #temp for UpgradeMacaque to continue
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_unknown_end),
		{ _field_enum, "maximum update period ticks", "ticks. 0 is default of 2", &physics_update_period_enum },
		{ _field_enum, "maximum remote update period ticks", "ticks. when controlled by an ai or remote player. 0 defaults to 4", &physics_update_period_enum },
		{ _field_long_integer, "iteration count", "0 defaults to 1.  Number of iterations per frame of physics" },
		{ _field_long_integer, "suspension count", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },

		{ _field_block, "anti gravity points", &anti_gravity_point_definition_block },
		{ _field_block, "friction points", &friction_point_definition_block },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach, 1 },
		{ _field_struct, "boat physics", &boat_physics_definition_struct },
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

} // namespace macaque

} // namespace blofeld

