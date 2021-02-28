#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define CHARACTER_PHYSICS_STRUCT_ID { 0x7F1CE04F, 0x93D14DEC, 0xA9872258, 0x04CD6B27 }
	TAG_STRUCT(
		character_physics_struct,
		"character_physics_struct",
		"s_character_physics_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN4 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		CHARACTER_PHYSICS_STRUCT_ID)
	{
		{ _field_long_flags, "flags", &character_physics_flags },
		{ _field_real, "height standing" },
		{ _field_real, "height crouching" },
		{ _field_real, "radius" },
		{ _field_real, "mass" },
		{ _field_string_id, "living material name", "collision material used when character is alive" },
		{ _field_string_id, "dead material name", "collision material used when character is dead" },
		{ _field_useless_pad, "" },
		{ _field_short_integer, "runtime global material type", FIELD_FLAG_UNKNOWN0 },
		{ _field_short_integer, "runtime dead global material type", FIELD_FLAG_UNKNOWN0 },
		{ _field_useless_pad, "" },
		{ _field_block, "dead sphere shapes", "don't be an asshole, edit something else", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &spheres_block },
		{ _field_block, "pill shapes", "don't be an asshole, edit something else", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &pills_block },
		{ _field_block, "sphere shapes", "don't be an asshole, edit something else", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &spheres_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 3 },
		{ _field_block, "list sphere shapes", "don't be an asshole, edit something else", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &spheres_block },
		{ _field_block, "list shapes", "don't be an asshole, edit something else", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &lists_block },
		{ _field_block, "list shape childInfos", "don't be an asshole, edit something else", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &list_shapes_block },

		FIELD_EXPLANATION("ground", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_struct, "ground physics", &character_physics_ground_struct },
		FIELD_EXPLANATION("flying", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_struct, "flying physics", &character_physics_flying_struct },
		{ _field_terminator }
	};

	#define CHARACTER_PHYSICS_GROUND_STRUCT_ID { 0xE61D5093, 0x77E5453D, 0x90EC05A0, 0x8B7B778B }
	TAG_STRUCT(
		character_physics_ground_struct,
		"character_physics_ground_struct",
		"s_character_physics_ground_definition",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CHARACTER_PHYSICS_GROUND_STRUCT_ID)
	{
		{ _field_angle, "maximum slope angle", nullptr, "degrees" },
		{ _field_angle, "downhill falloff angle", nullptr, "degrees" },
		{ _field_angle, "downhill cutoff angle", nullptr, "degrees" },
		{ _field_angle, "uphill falloff angle", nullptr, "degrees" },
		{ _field_angle, "uphill cutoff angle", nullptr, "degrees" },
		{ _field_real, "downhill velocity scale" },
		{ _field_real, "uphill velocity scale" },
		{ _field_real, "runtime_minimum_normal_k", FIELD_FLAG_UNKNOWN0 },
		{ _field_real, "runtime_downhill_k0", FIELD_FLAG_UNKNOWN0 },
		{ _field_real, "runtime_downhill_k1", FIELD_FLAG_UNKNOWN0 },
		{ _field_real, "runtime_uphill_k0", FIELD_FLAG_UNKNOWN0 },
		{ _field_real, "runtime_uphill_k1", FIELD_FLAG_UNKNOWN0 },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach }, // one of the follow fields is not in h3, this is the logical choice base on assembly's defs
		{ _field_angle, "climb inflection angle", "angle for bipeds at which climb direction changes between up and down" },

		{ _field_real, "scale airborne reaction time", "scale on the time for the entity to realize it is airborne" },
		{ _field_real, "scale ground adhesion velocity", "scale on velocity with which the entity is pushed back into its ground plane (set to -1 to lock to ground)" },
		{ _field_real, "gravity scale", "scale on gravity for this entity" },
		{ _field_real, "airborne acceleration scale", "scale on airborne acceleration maximum" },
		{ _field_terminator }
	};

	#define CHARACTER_PHYSICS_FLYING_STRUCT_ID { 0x692E7BDD, 0x59F4483F, 0xAEBF3C6D, 0x645E1EC3 }
	TAG_STRUCT(
		character_physics_flying_struct,
		"character_physics_flying_struct",
		"s_character_physics_flying_definition",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CHARACTER_PHYSICS_FLYING_STRUCT_ID)
	{
		{ _field_angle, "bank angle", "angle at which we bank left/right when sidestepping or turning while moving forwards", "degrees" },
		{ _field_real, "bank apply time", "time it takes us to apply a bank", "seconds" },
		{ _field_real, "bank decay time", "time it takes us to recover from a bank", "seconds" },
		{ _field_real, "pitch ratio", "amount that we pitch up/down when moving up or down" },
		{ _field_real, "max velocity", "max velocity when not crouching", "world units per second" },
		{ _field_real, "max sidestep velocity", "max sideways or up/down velocity when not crouching", "world units per second" },
		{ _field_real, "acceleration", nullptr, "world units per second squared" },
		{ _field_real, "deceleration", nullptr, "world units per second squared" },
		{ _field_angle, "angular velocity maximum", "turn rate", "degrees per second" },
		{ _field_angle, "angular acceleration maximum", "turn acceleration rate", "degrees per second squared" },
		{ _field_real, "crouch velocity modifier", "how much slower we fly if crouching (zero = same speed)", nullptr, "[0,1]" },
		{ _field_long_flags, "flags", &flying_physics_flags },
		{ _field_terminator }
	};

	STRINGS(flying_physics_flags)
	{
		"use world up"
	};
	STRING_LIST(flying_physics_flags, flying_physics_flags_strings, _countof(flying_physics_flags_strings));

	STRINGS(character_physics_flags)
	{
		"centered_at_origin",
		"shape spherical",
		"use player physics",
		"climb any surface",
		"flying",
		"not physical",
		"dead character collision group",
		"suppress ground planes on bipeds",
		"physical ragdoll",
		"do not resize dead spheres",
		"multiple Mantis shapes",
		"I am an Extreme Slipsurface",
		"slips off movers"
	};
	STRING_LIST(character_physics_flags, character_physics_flags_strings, _countof(character_physics_flags_strings));

} // namespace macaque

} // namespace blofeld

