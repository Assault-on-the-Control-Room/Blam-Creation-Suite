#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(effect_globals, EFFECT_GLOBALS_TAG, effect_globals_block_block );

	TAG_BLOCK(effect_component_holdback_block, k_effect_priority_max)
	{
		{ _field_long_enum, "priority type^*", &global_effect_priority_enum },
		{ _field_explanation, "SET ONE OF THE FOLLOWING", "Whichever is larger will be used" },
		{ _field_dword_integer, "absolute count" },
		{ _field_real, "relative percentage:/ 100" },
		{ _field_dword_integer, "How many available at this priority*!" },
		{ _field_terminator }
	};

	TAG_BLOCK(effect_component_holdbacks_block, k_effect_holdback_type_max)
	{
		{ _field_long_enum, "holdback type^*", &effect_holdback_type_enum },
		{ _field_dword_integer, "overall budget*#from code" },
		{ _field_block, "priorities", &effect_component_holdback_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(effect_global_spawn_effects_block, 1)
	{
		{ _field_tag_reference, "biped spawn effect", &global_effect_reference },
		{ _field_tag_reference, "vehicle spawn effect", &global_effect_reference },
		{ _field_tag_reference, "weapon spawn effect", &global_effect_reference }, 

		{ _field_version_greater, _engine_type_haloreach },
		{ _field_tag_reference, "first person player spawn effect", &global_effect_reference },

		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(effect_globals_block, 1, effect_globals_struct_definition_struct_definition );

	TAG_STRUCT(effect_globals_struct_definition)
	{
		{ _field_explanation, "EFFECT HOLDBACKS", "ALLOCATIONS ON THE MAIN THREAD\ntype_effect:                     Number of effect slots\ntype_event:                      Number of event slots\ntype_location:                   Number of location slots\ntype_lightprobe:                 Number of lightprobe slots\n\nTHREAD MESSAGES\ntype_effect_message:             Number of main-->render messages\n                                 Most effect components require 2 messages + 1 x number of locations\ntype_effect_reverse_message:     Number of render-->main messages (attached effects to particles)\n                                 Holdback not implemented due to complexity.\n\nALLOCATIONS ON THE RENDER THREAD\ntracer system\t\t              Number of instances\ntracer location\t\t          Number of instances * markers\ntracer\t\t\t                  Number of instances * markers * tag-block-entries\ntracer profile row\t\t\t      x16 = Number of tracer profiles\n\ntype_decal_system                Number of instances\ntype_decal                       Number of instances * tag-block-entries\ntype_decal_vertex                Number of decal vertices\ntype_decal_index                 Number of decal indices\n\ntype_light_volume_system         Number of instances\ntype_light_volume_location       Number of instances * markers\ntype_light_volume                Number of instances * markers * tag-block-entries\ntype_light_volume_profile_row    x16 =Number of light_volume profiles\n\ntype_particle_system             Number of instances\ntype_particle_location           Number of instances * markers\ntype_particle_emitter            Number of instances * markers * tag-block-entries\ntype_cpu_particle                Number of cpu particles\ntype_gpu_particle_row            x16 =Number of gpu particles (includes cpu particles)\n\nSPAWNS TO THE GPU\ntype_particle_queue              Number of particles created in a frame (includes cpu particles)\ntracer queue\t\t              Number of tracer profiles created in a frame\n" },
		{ _field_block, "holdbacks", &effect_component_holdbacks_block_block },
		{ _field_tag_reference, "grunt birthday effect", &global_effect_reference },
		{ _field_explanation, "Spawn Effects", "Effect played when an object of this type spawns in during each game mode.\nCan be overridden per-object in the object definition tag" },
		{ _field_block, "multiplayer", &effect_global_spawn_effects_block_block },
		{ _field_block, "survival", &effect_global_spawn_effects_block_block },
		{ _field_block, "campaign", &effect_global_spawn_effects_block_block },
		{ _field_terminator }
	};

	STRINGS(global_effect_priority_enum)
	{
		"low",
		"normal",
		"above normal",
		"high",
		"very high",
		"essential"
	};
	STRING_LIST(global_effect_priority_enum, global_effect_priority_enum_strings, _countof(global_effect_priority_enum_strings));

	STRINGS(effect_holdback_type_enum)
	{
		"type_effect",
		"type_event",
		"type_location",
		"type_lightprobe",
		"type_effect_message",
		"tracer system",
		"tracer location",
		"tracer spawned",
		"tracer stateless",
		"tracer spawned profile row",
		"tracer stateless profile row",
		"type_decal_system",
		"type_decal",
		"type_decal_vertex",
		"type_decal_index",
		"type_light_volume_system",
		"type_light_volume_location",
		"type_light_volume",
		"type_light_volume_profile_row",
		"type_particle_system",
		"type_particle_location",
		"type_particle_emitter",
		"type_cpu_particle",
		"type_gpu_particle_row",
		"type_particle_queue",
		"tracer queue",
		"track decal system",
		"halo_reach_unknown", // #TODO
	};
	STRING_LIST(effect_holdback_type_enum, effect_holdback_type_enum_strings, _countof(effect_holdback_type_enum_strings));

	TAG_REFERENCE(global_effect_globals_reference, EFFECT_GLOBALS_TAG);

} // namespace blofeld

