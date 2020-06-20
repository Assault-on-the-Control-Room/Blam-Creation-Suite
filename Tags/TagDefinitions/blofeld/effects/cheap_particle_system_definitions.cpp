#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(cheap_particle_emitter, CHEAP_PARTICLE_EMITTER_TAG, cheap_particle_emitter_block_block );

	TAG_GROUP_FROM_BLOCK(cheap_particle_type_library, CHEAP_PARTICLE_TYPE_LIBRARY_TAG, cheap_particle_type_library_block_block );

	TAG_BLOCK_FROM_STRUCT(cheap_particle_emitter_block, 1, cheap_particle_emitter_struct_definition_struct_definition );

	TAG_BLOCK(cheap_particle_type_block, s_cheap_particle_type::k_maximum_types)
	{
		{ _field_string_id, "name^" },
		{ _field_custom, "physics" },
		{ _field_real, "drag" },
		{ _field_real, "gravity" },
		{ _field_real, "turbulence" },

		{ _field_version_greater, _engine_type_haloreach },
		{ _field_long_block_index, "turbulence type#the type of turbulence this particle will experience" },

		{ _field_custom },
		{ _field_custom, "collision" },
		{ _field_real, "depth_range#depth range over which the particle will collide" },
		{ _field_real, "elasticity#energy remaining after collision bounce" },
		{ _field_real, "death#percentage change [0-1] that the particle will die on collision" },

		{ _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_long_integer, "unknown@" },

		{ _field_version_greater, _engine_type_haloreach },
		{ _field_long_block_index, "change type#the type this particle will change into on collision" },

		{ _field_custom },
		{ _field_custom, "render" },
		{ _field_long_enum, "orientation", &cheap_particle_type_orientation },
		{ _field_explanation, "render parameters", "cheap particles do not use alpha-blend transparency, they use multiply-and-add\nas such, an alpha of zero gives you additive particles, and an alpha of one gives you alpha-blend particles" },
		{ _field_real_argb_color, "color0" },
		{ _field_real, "intensity0" },
		{ _field_real, "fade start:[0,1]#point in particles lifetime at which fade begins" },
		{ _field_real_bounds, "size:world units" },
		{ _field_real, "motion blur stretch#how much the particle stretches as it moves" },
		{ _field_long_block_index, "texture" },
		{ _field_real, "texture y scale#scales the texture in the y direction" },
		{ _field_custom },
		{ _field_terminator }
	};

	TAG_BLOCK(cheap_particle_bitmap_reference_block, s_cheap_particle_type_library::k_max_textures)
	{
		{ _field_tag_reference, "bitmap^", &bitmap_reference$5 },
		{ _field_terminator }
	};

	TAG_BLOCK(cheapParticleTurbulenceTypeBlock, CheapParticleTurbulenceType::k_maxTypes)
	{
		{ _field_string_id, "name^" },
		{ _field_tag_reference, "turbulence:texture used to turbulate particles", &bitmap_reference$5 },
		{ _field_real, "turb du dt#change in u coordinate over time" },
		{ _field_real, "turb dv dt#change in v coordinate over time" },
		{ _field_real, "turb du dp#change in u coordinate per particle" },
		{ _field_real, "turb dv dp#change in v coordinate per particle" },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(cheap_particle_type_library_block, 1, cheap_particle_type_library_struct_definition_struct_definition );

	TAG_STRUCT(cheap_particle_emitter_struct_definition)
	{
		{ _field_word_flags, "flags", &cheap_particle_emitter_flags },
		{ _field_word_integer, "version!" },
		{ _field_real, "spawn rate!:particles per second" },
		{ _field_explanation, "SPAWN RATE", "how many particles to spawn per second" },
		{ _field_struct, "spawnrate", &cheap_particle_scalar_object_function_struct_struct_definition },
		{ _field_explanation, "LOD", "reduces the number of particles at distance" },
		{ _field_real, "distance fade start:world_units#the distance where the number of spawned particles starts to be reduced" },
		{ _field_real, "distance fade end:world units#the distance where the number of spawned particles is zero" },
		{ _field_explanation, "TYPES", "types of particles to spawn, from the global particle type library" },
		{ _field_custom, "types" },
		{ _field_string_id, "type 0" },
		{ _field_real, "weight 0" },
		{ _field_string_id, "type 1" },
		{ _field_real, "weight 1" },
		{ _field_string_id, "type 2" },
		{ _field_real, "weight 2" },
		{ _field_string_id, "type 3" },
		{ _field_real, "weight 3" },
		{ _field_custom },
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

	TAG_STRUCT(cheap_particle_scalar_object_function_struct)
	{
		{ _field_string_id, "Input Variable!" },
		{ _field_string_id, "Range Variable!" },
		{ _field_custom },
		{ _field_struct, "Mapping", &mapping_function_struct_definition },
		{ _field_terminator }
	};

	TAG_STRUCT(cheap_particle_type_library_struct_definition)
	{
		{ _field_custom, "compile" },
		{ _field_block, "types", &cheap_particle_type_block_block },
		{ _field_block, "textures", &cheap_particle_bitmap_reference_block_block },
		{ _field_tag_reference, "random:texture used to generate random values per particle", &bitmap_reference$5 },

		{ _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_tag_reference, "turbulenceTexture!", &bitmap_reference$5 },

		{ _field_version_greater, _engine_type_haloreach },
		{ _field_block, "turbulence types", &cheapParticleTurbulenceTypeBlock_block },

		{ _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },

		{ _field_tag_reference, "type_texture!", &bitmap_reference$5 },
		{ _field_tag_reference, "render_texture!", &bitmap_reference$5 },

		{ _field_version_greater, _engine_type_haloreach },
		{ _field_tag_reference, "turbulenceTexture!", &bitmap_reference$5 },

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

} // namespace blofeld

