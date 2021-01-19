#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		cheap_particle_emitter_group,
		CHEAP_PARTICLE_EMITTER_TAG,
		nullptr,
		INVALID_TAG,
		cheap_particle_emitter_block );

	TAG_GROUP(
		cheap_particle_type_library_group,
		CHEAP_PARTICLE_TYPE_LIBRARY_TAG,
		nullptr,
		INVALID_TAG,
		cheap_particle_type_library_block );

	TAG_BLOCK_FROM_STRUCT(
		cheap_particle_emitter_block,
		"cheap_particle_emitter_block",
		1,
		cheap_particle_emitter_struct_definition);

	TAG_BLOCK_FROM_STRUCT(
		cheap_particle_type_library_block,
		"cheap_particle_type_library_block",
		1,
		cheap_particle_type_library_struct_definition);

	#define CHEAP_PARTICLE_TYPE_BLOCK_ID { 0x3268D5F7, 0x4EE149C2, 0xAF15C140, 0xE9900147 }
	TAG_BLOCK(
		cheap_particle_type_block,
		"cheap_particle_type_block",
		s_cheap_particle_type::k_maximum_types,
		"s_cheap_particle_type",
		CHEAP_PARTICLE_TYPE_BLOCK_ID)
	{
		{ _field_string_id, "name^" },
		FIELD_CUSTOM("physics", _custom_field_function_group_begin),
		{ _field_real, "drag" },
		{ _field_real, "gravity" },
		{ _field_real, "turbulence" },
		{ _field_long_block_index, "turbulence type#the type of turbulence this particle will experience" },
		FIELD_CUSTOM(nullptr, _custom_field_function_group_end),
		FIELD_CUSTOM("collision", _custom_field_function_group_begin),
		{ _field_real, "depth_range#depth range over which the particle will collide" },
		{ _field_real, "elasticity#energy remaining after collision bounce" },
		{ _field_real, "death#percentage change [0-1] that the particle will die on collision" },
		{ _field_long_block_index, "change type#the type this particle will change into on collision" },
		FIELD_CUSTOM(nullptr, _custom_field_function_group_end),
		FIELD_CUSTOM("render", _custom_field_function_group_begin),
		{ _field_long_enum, "orientation", &cheap_particle_type_orientation },
		{ _field_explanation, "render parameters", "cheap particles do not use alpha-blend transparency, they use multiply-and-add\nas such, an alpha of zero gives you additive particles, and an alpha of one gives you alpha-blend particles" },
		{ _field_real_argb_color, "color0" },
		{ _field_real, "intensity0" },
		{ _field_real, "fade start:[0,1]#point in particles lifetime at which fade begins" },
		{ _field_real_bounds, "size:world units" },
		{ _field_real, "motion blur stretch#how much the particle stretches as it moves" },
		{ _field_long_block_index, "texture" },
		{ _field_real, "texture y scale#scales the texture in the y direction" },
		FIELD_CUSTOM(nullptr, _custom_field_function_group_end),
		{ _field_terminator }
	};

	#define CHEAP_PARTICLE_BITMAP_REFERENCE_BLOCK_ID { 0x6F5DFB08, 0x0FA04C2C, 0xB051184D, 0xA52DBEBA }
	TAG_BLOCK(
		cheap_particle_bitmap_reference_block,
		"cheap_particle_bitmap_reference_block",
		s_cheap_particle_type_library::k_max_textures,
		"s_tag_reference",
		CHEAP_PARTICLE_BITMAP_REFERENCE_BLOCK_ID)
	{
		{ _field_tag_reference, "bitmap^", &bitmap_reference$5 },
		{ _field_terminator }
	};

	#define CHEAPPARTICLETURBULENCETYPEBLOCK_ID { 0x97CA1A74, 0x71CB44A7, 0x8E7407F5, 0xDA0EDC23 }
	TAG_BLOCK(
		cheapParticleTurbulenceTypeBlock_block,
		"cheapParticleTurbulenceTypeBlock",
		CheapParticleTurbulenceType::k_maxTypes,
		"CheapParticleTurbulenceType",
		CHEAPPARTICLETURBULENCETYPEBLOCK_ID)
	{
		{ _field_string_id, "name^" },
		{ _field_tag_reference, "turbulence:texture used to turbulate particles", &bitmap_reference$5 },
		{ _field_real, "turb du dt#change in u coordinate over time" },
		{ _field_real, "turb dv dt#change in v coordinate over time" },
		{ _field_real, "turb du dp#change in u coordinate per particle" },
		{ _field_real, "turb dv dp#change in v coordinate per particle" },
		{ _field_terminator }
	};

	#define CHEAP_PARTICLE_EMITTER_STRUCT_DEFINITION_ID { 0x03578EF2, 0xE31FA29B, 0x53BAF43A, 0x00E427CA }
	TAG_STRUCT(
		cheap_particle_emitter_struct_definition,
		"cheap_particle_emitter_struct_definition",
		"s_cheap_particle_emitter",
		CHEAP_PARTICLE_EMITTER_STRUCT_DEFINITION_ID)
	{
		{ _field_word_flags, "flags", &cheap_particle_emitter_flags },
		{ _field_word_integer, "version!" },
		{ _field_real, "spawn rate!:particles per second" },
		{ _field_explanation, "SPAWN RATE", "how many particles to spawn per second" },
		{ _field_struct, "spawnrate", &cheap_particle_scalar_object_function_struct },
		{ _field_explanation, "LOD", "reduces the number of particles at distance" },
		{ _field_real, "distance fade start:world_units#the distance where the number of spawned particles starts to be reduced" },
		{ _field_real, "distance fade end:world units#the distance where the number of spawned particles is zero" },
		{ _field_explanation, "TYPES", "types of particles to spawn, from the global particle type library" },
		FIELD_CUSTOM("types", _custom_field_function_group_begin),
		{ _field_string_id, "type 0" },
		{ _field_real, "weight 0" },
		{ _field_string_id, "type 1" },
		{ _field_real, "weight 1" },
		{ _field_string_id, "type 2" },
		{ _field_real, "weight 2" },
		{ _field_string_id, "type 3" },
		{ _field_real, "weight 3" },
		FIELD_CUSTOM(nullptr, _custom_field_function_group_end),
		{ _field_explanation, "LIFETIME", "how long the spawned particles will last" },
		{ _field_real_bounds, "lifetime:seconds" },
		{ _field_explanation, "EMITTER PARAMETERS", "controls where a particle spawns, and its initial velocity" },
		{ _field_tag_reference, "position texture", &bitmap_reference$5 },
		{ _field_real, "position scale" },
		{ _field_real, "position flatten" },
		{ _field_tag_reference, "velocity texture", &bitmap_reference$5 },
		{ _field_real_bounds, "directionality:[0-1]#Blends between a random direction and the forward direction" },
		{ _field_real_bounds, "speed scale#scales the initial speed of the particle" },
		{ _field_real_bounds, "subframe offset:frames#spawns particle at subframe time" },
		{ _field_explanation, "PARTICLE PARAMETERS", "controls randomized rotation and size" },
		{ _field_real, "rotation randomness:[0-1]#how much the particle is randomly rotated" },
		{ _field_real, "particle scale modifier:[0-2]#modifies the inherent scale of the particles" },
		{ _field_explanation, "LIGHTING PARAMETERS", "controls the effects of lighting on this particle\nNOTE: only monochrome lighting is supported in neuticles" },
		{ _field_real, "lighting contrast#increase or decrease contrast between bright and dark areas" },
		{ _field_real, "lighting offset#adjust overall brightness in all areas" },
		{ _field_real, "lighting min#clamps darkest particles to this exposure" },
		{ _field_real, "lighting max#clamps brightest particles to this exposure" },
		{ _field_real_quaternion, "spawn_params0!" },
		{ _field_real_quaternion, "spawn_params1!" },
		{ _field_real_quaternion, "spawn_params2!" },
		{ _field_real_quaternion, "spawn_params3!" },
		{ _field_real_quaternion, "spawn_params4!" },
		{ _field_tag_reference, "global type library!", &cheap_particle_type_library_reference },
		{ _field_terminator }
	};

	#define CHEAP_PARTICLE_TYPE_LIBRARY_STRUCT_DEFINITION_ID { 0x2BCDE64D, 0xF1374714, 0x8A6A9EB7, 0xAD124FCF }
	TAG_STRUCT(
		cheap_particle_type_library_struct_definition,
		"cheap_particle_type_library_struct_definition",
		"s_cheap_particle_type_library",
		CHEAP_PARTICLE_TYPE_LIBRARY_STRUCT_DEFINITION_ID)
	{
		FIELD_CUSTOM("compile", _custom_field_unknown_compile),
		{ _field_block, "types", &cheap_particle_type_block },
		{ _field_block, "textures", &cheap_particle_bitmap_reference_block },
		{ _field_tag_reference, "random:texture used to generate random values per particle", &bitmap_reference$5 },
		{ _field_block, "turbulence types", &cheapParticleTurbulenceTypeBlock_block },
		{ _field_tag_reference, "type_texture!", &bitmap_reference$5 },
		{ _field_tag_reference, "render_texture!", &bitmap_reference$5 },
		{ _field_tag_reference, "turbulenceTexture!", &bitmap_reference$5 },
		{ _field_terminator }
	};

	#define CHEAP_PARTICLE_SCALAR_OBJECT_FUNCTION_STRUCT_ID { 0xE439295B, 0xED024F7F, 0xBA3D7B94, 0x393D4F18 }
	TAG_STRUCT(
		cheap_particle_scalar_object_function_struct,
		"cheap_particle_scalar_object_function_struct",
		"s_cheap_particle_scalar_object_function",
		CHEAP_PARTICLE_SCALAR_OBJECT_FUNCTION_STRUCT_ID)
	{
		{ _field_string_id, "Input Variable!", nullptr, 'fnin' },
		{ _field_string_id, "Range Variable!", nullptr, 'fnir' },
		FIELD_CUSTOM(nullptr, 0),
		{ _field_struct, "Mapping", &mapping_function },
		{ _field_terminator }
	};

	STRINGS(cheap_particle_emitter_flags)
	{
		"correlate position and velocity",
		"position texture in local space",
		"velocity texture in local space",
		"normalize velocity before scaling",
		"randomly rotate emitter about up vector"
	};
	STRING_LIST(cheap_particle_emitter_flags, cheap_particle_emitter_flags_strings, _countof(cheap_particle_emitter_flags_strings));

	STRINGS(cheap_particle_type_orientation)
	{
		"velocity",
		"screen facing"
	};
	STRING_LIST(cheap_particle_type_orientation, cheap_particle_type_orientation_strings, _countof(cheap_particle_type_orientation_strings));

	TAG_REFERENCE(global_cheap_particle_emitter_reference, CHEAP_PARTICLE_EMITTER_TAG);

} // namespace macaque

} // namespace blofeld

