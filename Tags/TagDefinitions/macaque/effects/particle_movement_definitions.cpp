#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		particle_physics_group,
		PARTICLE_PHYSICS_TAG,
		nullptr,
		INVALID_TAG,
		particle_physics_block );

	TAG_BLOCK_FROM_STRUCT(
		particle_physics_block,
		"particle_physics_block",
		1,
		particle_physics_struct_definition);

	#define PARTICLE_CONTROLLER_ID { 0xFFDF1EEA, 0xE003416F, 0xBBE85C7F, 0xA06AFA10 }
	TAG_BLOCK(
		particle_controller_block,
		"particle_controller",
		c_particle_movement_definition::k_type_count + 2,
		"c_particle_controller",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		PARTICLE_CONTROLLER_ID)
	{
		{ _field_enum, "type", &particle_movement_type },
		{ _field_byte_flags, "flags", FIELD_FLAG_UNKNOWN0, &particle_controller_flags },
		FIELD_PAD("KNTXOMS", nullptr, FIELD_FLAG_NONE, 1),
		{ _field_block, "parameters", &particle_controller_parameters_block },
		{ _field_long_integer, "runtime m_constant_parameters", FIELD_FLAG_UNKNOWN0 },
		{ _field_long_integer, "runtime m_used_particle_states", FIELD_FLAG_UNKNOWN0 },
		{ _field_terminator }
	};

	#define PARTICLE_CONTROLLER_PARAMETERS_ID { 0xAC90ED63, 0x7FCF4CE1, 0xADDEA140, 0x9C137F95 }
	TAG_BLOCK(
		particle_controller_parameters_block,
		"particle_controller_parameters",
		c_particle_movement_definition::k_flocking_parameter_count,
		"c_particle_controller_parameter",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		PARTICLE_CONTROLLER_PARAMETERS_ID)
	{
		{ _field_long_integer, "parameter id" },
		{ _field_struct, "property", &particle_property_scalar_struct_new },
		{ _field_terminator }
	};

	#define PARTICLE_PHYSICS_STRUCT_DEFINITION_ID { 0xC86CD2D6, 0xEB9C4A4F, 0x96C423E9, 0x48A52870 }
	TAG_STRUCT(
		particle_physics_struct_definition,
		"particle_physics_struct_definition",
		"c_particle_movement_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		PARTICLE_PHYSICS_STRUCT_DEFINITION_ID)
	{
		{ _field_tag_reference, "template", &particle_movement_definition },
		{ _field_word_flags, "flags", &particle_movement_flags },
		{ _field_char_integer, "collision controller index", FIELD_FLAG_UNKNOWN0 },
		{ _field_char_integer, "turbulence controller index", FIELD_FLAG_UNKNOWN0 },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_char_integer, "global force controller index", FIELD_FLAG_UNKNOWN0 },
		FIELD_PAD("pphys", nullptr, FIELD_FLAG_NONE, 3),

		{ _field_block, "movements", &particle_controller_block },
		{ _field_tag_reference, "turbulence texture", &global_bitmap_reference },
		{ _field_terminator }
	};

	#define PARTICLE_PHYSICS_STRUCT_ID { 0x2E19EA87, 0xEB8741A8, 0xB25C5661, 0x9D4201DD }
	TAG_STRUCT(
		particle_physics_struct,
		"particle_physics_struct",
		"c_particle_movement_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		PARTICLE_PHYSICS_STRUCT_ID)
	{
		{ _field_tag_reference, "template", &particle_movement_definition },
		{ _field_word_flags, "flags", &particle_movement_flags },
		{ _field_char_integer, "collision controller index", FIELD_FLAG_UNKNOWN0 },
		{ _field_char_integer, "turbulence controller index", FIELD_FLAG_UNKNOWN0 },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_char_integer, "global force controller index", FIELD_FLAG_UNKNOWN0 },
		FIELD_PAD("pphys", nullptr, FIELD_FLAG_NONE, 3),

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
		//{ _field_legacy, _field_version_platform_include, _platform_type_pc, 2 },
		//{ _field_legacy, _field_version_greater_or_equal, _engine_type_halo4, 1 },
		//"unknown bit 13"
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

} // namespace macaque

} // namespace blofeld

