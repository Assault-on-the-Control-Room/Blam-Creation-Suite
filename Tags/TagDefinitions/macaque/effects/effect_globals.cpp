#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		effect_globals_group,
		EFFECT_GLOBALS_TAG,
		nullptr,
		INVALID_TAG,
		effect_globals_block );

	TAG_BLOCK_FROM_STRUCT(
		effect_globals_block,
		"effect_globals_block",
		1,
		effect_globals_struct_definition);

	#define EFFECT_COMPONENT_HOLDBACKS_BLOCK_ID { 0x8CADDBFF, 0xC0E843FA, 0xB225FFEB, 0xB26D05DA }
	TAG_BLOCK(
		effect_component_holdbacks_block,
		"effect_component_holdbacks_block",
		k_effect_holdback_type_max,
		"s_effect_component_holdbacks",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		EFFECT_COMPONENT_HOLDBACKS_BLOCK_ID)
	{
		{ _field_long_enum, "holdback type", FIELD_FLAG_READ_ONLY | FIELD_FLAG_INDEX, &effect_holdback_type_enum },
		{ _field_dword_integer, "overall budget", "from code", FIELD_FLAG_READ_ONLY },
		{ _field_block, "priorities", &effect_component_holdback_block },
		{ _field_terminator }
	};

	#define EFFECT_COMPONENT_HOLDBACK_BLOCK_ID { 0xF1F9FECE, 0xDB96482E, 0x888A6653, 0xCAACCD84 }
	TAG_BLOCK(
		effect_component_holdback_block,
		"effect_component_holdback_block",
		k_effect_priority_max,
		"s_effect_component_holdbacks::s_holdback",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		EFFECT_COMPONENT_HOLDBACK_BLOCK_ID)
	{
		{ _field_long_enum, "priority type", FIELD_FLAG_READ_ONLY | FIELD_FLAG_INDEX, &global_effect_priority_enum },
		FIELD_EXPLANATION("SET ONE OF THE FOLLOWING", nullptr, FIELD_FLAG_NONE, "Whichever is larger will be used"),
		{ _field_dword_integer, "absolute count" },
		{ _field_real, "relative percentage", nullptr, "/ 100" },
		{ _field_dword_integer, "How many available at this priority", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define EFFECT_GLOBAL_SPAWN_EFFECTS_BLOCK_ID { 0x43548FDC, 0x178A4ED6, 0x88EA2BD1, 0xC0B02BBE }
	TAG_BLOCK(
		effect_global_spawn_effects_block,
		"effect_global_spawn_effects_block",
		1,
		"s_effect_global_spawn_effects",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		EFFECT_GLOBAL_SPAWN_EFFECTS_BLOCK_ID)
	{
		{ _field_tag_reference, "biped spawn effect", &global_effect_reference },
		{ _field_tag_reference, "vehicle spawn effect", &global_effect_reference },
		{ _field_tag_reference, "weapon spawn effect", &global_effect_reference },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_tag_reference, "first person player spawn effect", &global_effect_reference },

		{ _field_terminator }
	};

	#define EFFECT_GLOBALS_STRUCT_DEFINITION_ID { 0xA7E2A204, 0x03B84418, 0xA6A9A385, 0x4797476F }
	TAG_STRUCT(
		effect_globals_struct_definition,
		"effect_globals_struct_definition",
		"s_effect_globals_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		EFFECT_GLOBALS_STRUCT_DEFINITION_ID)
	{
		FIELD_EXPLANATION("EFFECT HOLDBACKS", nullptr, FIELD_FLAG_NONE, "ALLOCATIONS ON THE MAIN THREAD\ntype_effect:                     Number of effect slots\ntype_event:                      Number of event slots\ntype_location:                   Number of location slots\ntype_lightprobe:                 Number of lightprobe slots\n\nTHREAD MESSAGES\ntype_effect_message:             Number of main-->render messages\n                                 Most effect components require 2 messages + 1 x number of locations\ntype_effect_reverse_message:     Number of render-->main messages (attached effects to particles)\n                                 Holdback not implemented due to complexity.\n\nALLOCATIONS ON THE RENDER THREAD\ntracer system\t\t              Number of instances\ntracer location\t\t          Number of instances * markers\ntracer\t\t\t                  Number of instances * markers * tag-block-entries\ntracer profile row\t\t\t      x16 = Number of tracer profiles\n\ntype_decal_system                Number of instances\ntype_decal                       Number of instances * tag-block-entries\ntype_decal_vertex                Number of decal vertices\ntype_decal_index                 Number of decal indices\n\ntype_light_volume_system         Number of instances\ntype_light_volume_location       Number of instances * markers\ntype_light_volume                Number of instances * markers * tag-block-entries\ntype_light_volume_profile_row    x16 =Number of light_volume profiles\n\ntype_particle_system             Number of instances\ntype_particle_location           Number of instances * markers\ntype_particle_emitter            Number of instances * markers * tag-block-entries\ntype_cpu_particle                Number of cpu particles\ntype_gpu_particle_row            x16 =Number of gpu particles (includes cpu particles)\n\nSPAWNS TO THE GPU\ntype_particle_queue              Number of particles created in a frame (includes cpu particles)\ntracer queue\t\t              Number of tracer profiles created in a frame\n"),
		{ _field_block, "holdbacks", &effect_component_holdbacks_block },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach, 5 },
		{ _field_tag_reference, "grunt birthday effect", &global_effect_reference },
		FIELD_EXPLANATION("Spawn Effects", nullptr, FIELD_FLAG_NONE, "Effect played when an object of this type spawns in during each game mode.\nCan be overridden per-object in the object definition tag"),
		{ _field_block, "multiplayer", &effect_global_spawn_effects_block },
		{ _field_block, "survival", &effect_global_spawn_effects_block },
		{ _field_block, "campaign", &effect_global_spawn_effects_block },

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
		"tracer queue"
	};
	STRING_LIST(effect_holdback_type_enum, effect_holdback_type_enum_strings, _countof(effect_holdback_type_enum_strings));

	TAG_REFERENCE(global_effect_globals_reference, EFFECT_GLOBALS_TAG);

} // namespace macaque

} // namespace blofeld

