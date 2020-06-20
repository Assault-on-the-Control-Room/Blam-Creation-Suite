#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(particle_physics, PARTICLE_PHYSICS_TAG, particle_physics_block_block );

	TAG_BLOCK(particle_controller_parameters, c_particle_movement_definition::k_flocking_parameter_count)
	{
		{ _field_long_integer, "parameter id" },
		{ _field_struct, "property", &particle_property_scalar_struct_new_struct_definition },
		{ _field_terminator }
	};

	TAG_BLOCK(particle_controller, c_particle_movement_definition::k_type_count + 2)
	{
		{ _field_enum, "type", &particle_movement_type },
		{ _field_byte_flags, "flags!", &particle_controller_flags },
		{ _field_pad, "KNTXOMS", 1 },
		{ _field_block, "parameters", &particle_controller_parameters_block },
		{ _field_long_integer, "runtime m_constant_parameters!" },
		{ _field_long_integer, "runtime m_used_particle_states!" },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(particle_physics_block, 1, particle_physics_struct_definition_struct_definition );

	TAG_STRUCT(particle_physics_struct)
	{
		{ _field_tag_reference, "template", &particle_movement_definition },
		{ _field_word_flags, "flags", &particle_movement_flags },
		{ _field_char_integer, "collision controller index!" },
		{ _field_char_integer, "turbulence controller index!" },

		{ _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_char_integer, "global force controller index!" },
		{ _field_pad, "pphys", 3 },

		{ _field_block, "movements", &particle_controller_block },
		{ _field_tag_reference, "turbulence texture", &global_bitmap_reference },
		{ _field_terminator }
	};

	TAG_STRUCT(particle_physics_struct_definition)
	{
		{ _field_tag_reference, "template", &particle_movement_definition },
		{ _field_word_flags, "flags", &particle_movement_flags },
		{ _field_char_integer, "collision controller index!" },
		{ _field_char_integer, "turbulence controller index!" },

		{ _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_char_integer, "global force controller index!" },
		{ _field_pad, "pphys", 3 },

		{ _field_block, "movements", &particle_controller_block },
		{ _field_tag_reference, "turbulence texture", &global_bitmap_reference },
		{ _field_terminator }
	};

	STRINGS(particle_movement_flags)
	{
		"physics",
		"collide with structure",
		"collide with water",
		"collide with scenery",
		"collide with vehicles",
		"collide with bipeds",
		"always collide every frame",
		"swarm",
		"wind",
		"turbulence",
		"global force",
		"disable swarm collision"
	};
	STRING_LIST(particle_movement_flags, particle_movement_flags_strings, _countof(particle_movement_flags_strings));

	STRINGS(particle_movement_type)
	{
		"physics",
		"collider",
		"swarm",
		"wind",
		"turbulence",
		"global force"
	};
	STRING_LIST(particle_movement_type, particle_movement_type_strings, _countof(particle_movement_type_strings));

	STRINGS(particle_controller_flags)
	{
		"properties fully indexed"
	};
	STRING_LIST(particle_controller_flags, particle_controller_flags_strings, _countof(particle_controller_flags_strings));

	TAG_REFERENCE(particle_movement_definition, PARTICLE_PHYSICS_TAG);

} // namespace blofeld

