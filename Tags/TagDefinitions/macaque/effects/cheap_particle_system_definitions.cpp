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
		SET_UNKNOWN0 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_POSTPROCESS_RECURSIVELY | SET_IS_MEMCPYABLE | 
		SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CHEAP_PARTICLE_TYPE_BLOCK_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		FIELD_CUSTOM("physics", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_real, "drag" },
		{ _field_real, "gravity" },
		{ _field_real, "turbulence" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_long_block_index, "turbulence type", "the type of turbulence this particle will experience", &cheapParticleTurbulenceTypeBlock_block },

		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		FIELD_CUSTOM("collision", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_real, "depth_range", "depth range over which the particle will collide" },
		{ _field_real, "elasticity", "energy remaining after collision bounce" },
		{ _field_real, "death", "percentage change [0-1] that the particle will die on collision" },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_long_integer, "unknown@" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_long_block_index, "change type", "the type this particle will change into on collision", &cheap_particle_type_block },

		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		FIELD_CUSTOM("render", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_long_enum, "orientation", &cheap_particle_type_orientation },
		FIELD_EXPLANATION("render parameters", nullptr, FIELD_FLAG_NONE, "cheap particles do not use alpha-blend transparency, they use multiply-and-add\nas such, an alpha of zero gives you additive particles, and an alpha of one gives you alpha-blend particles"),
		{ _field_real_argb_color, "color0" },
		{ _field_real, "intensity0" },
		{ _field_real, "fade start", "point in particles lifetime at which fade begins", nullptr, "[0,1]" },
		{ _field_real_bounds, "size", nullptr, "world units" },
		{ _field_real, "motion blur stretch", "how much the particle stretches as it moves" },
		{ _field_long_block_index, "texture", &cheap_particle_bitmap_reference_block },
		{ _field_real, "texture y scale", "scales the texture in the y direction" },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		{ _field_terminator }
	};

	#define CHEAPPARTICLETURBULENCETYPEBLOCK_ID { 0x97CA1A74, 0x71CB44A7, 0x8E7407F5, 0xDA0EDC23 }
	TAG_BLOCK(
		cheapParticleTurbulenceTypeBlock_block,
		"cheapParticleTurbulenceTypeBlock",
		CheapParticleTurbulenceType::k_maxTypes,
		"CheapParticleTurbulenceType",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CHEAPPARTICLETURBULENCETYPEBLOCK_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_tag_reference, "turbulence", nullptr, "texture used to turbulate particles", &bitmap_reference$5 },
		{ _field_real, "turb du dt", "change in u coordinate over time" },
		{ _field_real, "turb dv dt", "change in v coordinate over time" },
		{ _field_real, "turb du dp", "change in u coordinate per particle" },
		{ _field_real, "turb dv dp", "change in v coordinate per particle" },
		{ _field_terminator }
	};

	#define CHEAP_PARTICLE_BITMAP_REFERENCE_BLOCK_ID { 0x6F5DFB08, 0x0FA04C2C, 0xB051184D, 0xA52DBEBA }
	TAG_BLOCK(
		cheap_particle_bitmap_reference_block,
		"cheap_particle_bitmap_reference_block",
		s_cheap_particle_type_library::k_max_textures,
		"s_tag_reference",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CHEAP_PARTICLE_BITMAP_REFERENCE_BLOCK_ID)
	{
		{ _field_tag_reference, "bitmap", FIELD_FLAG_INDEX, &bitmap_reference$5 },
		{ _field_terminator }
	};

	#define CHEAP_PARTICLE_EMITTER_STRUCT_DEFINITION_ID { 0x03578EF2, 0xE31FA29B, 0x53BAF43A, 0x00E427CA }
	TAG_STRUCT(
		cheap_particle_emitter_struct_definition,
		"cheap_particle_emitter_struct_definition",
		"s_cheap_particle_emitter",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		CHEAP_PARTICLE_EMITTER_STRUCT_DEFINITION_ID)
	{
		{ _field_word_flags, "flags", &cheap_particle_emitter_flags },
		{ _field_word_integer, "version", FIELD_FLAG_UNKNOWN0 },
		{ _field_real, "spawn rate", nullptr, "particles per second", FIELD_FLAG_UNKNOWN0 },
		FIELD_EXPLANATION("SPAWN RATE", nullptr, FIELD_FLAG_NONE, "how many particles to spawn per second"),
		{ _field_struct, "spawnrate", &cheap_particle_scalar_object_function_struct },
		FIELD_EXPLANATION("LOD", nullptr, FIELD_FLAG_NONE, "reduces the number of particles at distance"),
		{ _field_real, "distance fade start", "the distance where the number of spawned particles starts to be reduced", "world_units" },
		{ _field_real, "distance fade end", "the distance where the number of spawned particles is zero", "world units" },
		FIELD_EXPLANATION("TYPES", nullptr, FIELD_FLAG_NONE, "types of particles to spawn, from the global particle type library"),
		FIELD_CUSTOM("types", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_string_id, "type 0" },
		{ _field_real, "weight 0" },
		{ _field_string_id, "type 1" },
		{ _field_real, "weight 1" },
		{ _field_string_id, "type 2" },
		{ _field_real, "weight 2" },
		{ _field_string_id, "type 3" },
		{ _field_real, "weight 3" },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		FIELD_EXPLANATION("LIFETIME", nullptr, FIELD_FLAG_NONE, "how long the spawned particles will last"),
		{ _field_real_bounds, "lifetime", nullptr, "seconds" },
		FIELD_EXPLANATION("EMITTER PARAMETERS", nullptr, FIELD_FLAG_NONE, "controls where a particle spawns, and its initial velocity"),
		{ _field_tag_reference, "position texture", &bitmap_reference$5 },
		{ _field_real, "position scale" },
		{ _field_real, "position flatten" },
		{ _field_tag_reference, "velocity texture", &bitmap_reference$5 },
		{ _field_real_bounds, "directionality", "Blends between a random direction and the forward direction", nullptr, "[0-1]" },
		{ _field_real_bounds, "speed scale", "scales the initial speed of the particle" },
		{ _field_real_bounds, "subframe offset", "spawns particle at subframe time", "frames" },
		FIELD_EXPLANATION("PARTICLE PARAMETERS", nullptr, FIELD_FLAG_NONE, "controls randomized rotation and size"),
		{ _field_real, "rotation randomness", "how much the particle is randomly rotated", nullptr, "[0-1]" },
		{ _field_real, "particle scale modifier", "modifies the inherent scale of the particles", nullptr, "[0-2]" },
		FIELD_EXPLANATION("LIGHTING PARAMETERS", nullptr, FIELD_FLAG_NONE, "controls the effects of lighting on this particle\nNOTE: only monochrome lighting is supported in neuticles"),
		{ _field_real, "lighting contrast", "increase or decrease contrast between bright and dark areas" },
		{ _field_real, "lighting offset", "adjust overall brightness in all areas" },
		{ _field_real, "lighting min", "clamps darkest particles to this exposure" },
		{ _field_real, "lighting max", "clamps brightest particles to this exposure" },
		{ _field_real_quaternion, "spawn_params0", FIELD_FLAG_UNKNOWN0 },
		{ _field_real_quaternion, "spawn_params1", FIELD_FLAG_UNKNOWN0 },
		{ _field_real_quaternion, "spawn_params2", FIELD_FLAG_UNKNOWN0 },
		{ _field_real_quaternion, "spawn_params3", FIELD_FLAG_UNKNOWN0 },
		{ _field_real_quaternion, "spawn_params4", FIELD_FLAG_UNKNOWN0 },
		{ _field_tag_reference, "global type library", FIELD_FLAG_UNKNOWN0, &cheap_particle_type_library_reference },
		{ _field_terminator }
	};

	#define CHEAP_PARTICLE_TYPE_LIBRARY_STRUCT_DEFINITION_ID { 0x2BCDE64D, 0xF1374714, 0x8A6A9EB7, 0xAD124FCF }
	TAG_STRUCT(
		cheap_particle_type_library_struct_definition,
		"cheap_particle_type_library_struct_definition",
		"s_cheap_particle_type_library",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		CHEAP_PARTICLE_TYPE_LIBRARY_STRUCT_DEFINITION_ID)
	{
		FIELD_CUSTOM("compile", nullptr, FIELD_FLAG_NONE, _field_id_unknown_compile),
		{ _field_block, "types", &cheap_particle_type_block },
		{ _field_block, "textures", &cheap_particle_bitmap_reference_block },
		{ _field_tag_reference, "random", nullptr, "texture used to generate random values per particle", &bitmap_reference$5 },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_tag_reference, "turbulenceTexture!", &bitmap_reference$5 },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_block, "turbulence types", &cheapParticleTurbulenceTypeBlock_block },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 4 },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_real, "unknown" },

		{ _field_tag_reference, "type_texture", FIELD_FLAG_UNKNOWN0, &bitmap_reference$5 },
		{ _field_tag_reference, "render_texture", FIELD_FLAG_UNKNOWN0, &bitmap_reference$5 },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_tag_reference, "turbulenceTexture", FIELD_FLAG_UNKNOWN0, &bitmap_reference$5 },

		{ _field_terminator }
	};

	#define CHEAP_PARTICLE_SCALAR_OBJECT_FUNCTION_STRUCT_ID { 0xE439295B, 0xED024F7F, 0xBA3D7B94, 0x393D4F18 }
	TAG_STRUCT(
		cheap_particle_scalar_object_function_struct,
		"cheap_particle_scalar_object_function_struct",
		"s_cheap_particle_scalar_object_function",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		CHEAP_PARTICLE_SCALAR_OBJECT_FUNCTION_STRUCT_ID)
	{
		{ _field_string_id, "Input Variable", FIELD_FLAG_UNKNOWN0, _field_id_function_input_scalar },
		{ _field_string_id, "Range Variable", FIELD_FLAG_UNKNOWN0, _field_id_function_input_range },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_default),
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

