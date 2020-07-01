#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_STRUCT(character_physics_struct)
	{
		{ _field_long_flags, "flags", &character_physics_flags },
		{ _field_real, "height standing" },
		{ _field_real, "height crouching" },
		{ _field_real, "radius" },
		{ _field_real, "mass" },
		{ _field_string_id, "living material name#collision material used when character is alive" },
		{ _field_string_id, "dead material name#collision material used when character is dead" },
		{ _field_useless_pad },
		{ _field_short_integer, "runtime global material type!" },
		{ _field_short_integer, "runtime dead global material type!" },
		{ _field_useless_pad },
		{ _field_block, "dead sphere shapes*#don\'t be an asshole, edit something else!", &spheres_block_block },
		{ _field_block, "pill shapes*#don\'t be an asshole, edit something else!", &pills_block_block },
		{ _field_block, "sphere shapes*#don\'t be an asshole, edit something else!", &spheres_block_block },

		{ _field_version_greater, _engine_type_haloreach, 3 },
		{ _field_block, "list sphere shapes*#don\'t be an asshole, edit something else!", &spheres_block_block },
		{ _field_block, "list shapes*#don\'t be an asshole, edit something else!", &lists_block_block },
		{ _field_block, "list shape childInfos*#don\'t be an asshole, edit something else!", &list_shapes_block_block },

		{ _field_explanation, "ground", "" },
		{ _field_struct, "ground physics", &character_physics_ground_struct_struct_definition },
		{ _field_explanation, "flying", "" },
		{ _field_struct, "flying physics", &character_physics_flying_struct_struct_definition },
		{ _field_terminator }
	};

	TAG_STRUCT(character_physics_ground_struct)
	{
		{ _field_angle, "maximum slope angle:degrees" },
		{ _field_angle, "downhill falloff angle:degrees" },
		{ _field_angle, "downhill cutoff angle:degrees" },
		{ _field_angle, "uphill falloff angle:degrees" },
		{ _field_angle, "uphill cutoff angle:degrees" },
		{ _field_real, "downhill velocity scale" },
		{ _field_real, "uphill velocity scale" },
		{ _field_real, "runtime_minimum_normal_k!" },
		{ _field_real, "runtime_downhill_k0!" },
		{ _field_real, "runtime_downhill_k1!" },
		{ _field_real, "runtime_uphill_k0!" },
		{ _field_real, "runtime_uphill_k1!" },
		{ _field_angle, "climb inflection angle#angle for bipeds at which climb direction changes between up and down" },
		{ _field_real, "scale airborne reaction time#scale on the time for the entity to realize it is airborne" },
		{ _field_real, "scale ground adhesion velocity#scale on velocity with which the entity is pushed back into its ground plane (set to -1 to lock to ground)" },
		{ _field_real, "gravity scale#scale on gravity for this entity" },
		{ _field_real, "airborne acceleration scale#scale on airborne acceleration maximum" },
		{ _field_terminator }
	};

	TAG_STRUCT(character_physics_flying_struct)
	{
		{ _field_angle, "bank angle:degrees#angle at which we bank left/right when sidestepping or turning while moving forwards" },
		{ _field_real, "bank apply time:seconds#time it takes us to apply a bank" },
		{ _field_real, "bank decay time:seconds#time it takes us to recover from a bank" },
		{ _field_real, "pitch ratio#amount that we pitch up/down when moving up or down" },
		{ _field_real, "max velocity:world units per second#max velocity when not crouching" },
		{ _field_real, "max sidestep velocity:world units per second#max sideways or up/down velocity when not crouching" },
		{ _field_real, "acceleration:world units per second squared" },
		{ _field_real, "deceleration:world units per second squared" },
		{ _field_angle, "angular velocity maximum:degrees per second#turn rate" },
		{ _field_angle, "angular acceleration maximum:degrees per second squared#turn acceleration rate" },
		{ _field_real, "crouch velocity modifier:[0,1]#how much slower we fly if crouching (zero = same speed)" },
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

} // namespace blofeld

