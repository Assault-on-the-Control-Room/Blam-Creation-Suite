#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define PERFORMANCE_TEMPLATE_STRUCT_DEFINITION_ID { 0x75BA5372, 0x8E344209, 0x96284F55, 0x56AA1347 }
	TAG_BLOCK(
		performance_template_block,
		"performance_template_block",
		1,
		"s_performance_template_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		PERFORMANCE_TEMPLATE_STRUCT_DEFINITION_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_string_id, "script name", "The name of a custom script used to drive the performance. If none is given, a default script is uses that goes through the lines in sequence" },
		{ _field_block, "Actors", &performance_template_actor_block },
		{ _field_block, "Lines", &scenario_performance_line_block },
		{ _field_block, "Points", &performance_template_point_block },
		{ _field_terminator }
	};

	TAG_GROUP(
		performance_template_group,
		PERFORMANCE_TEMPLATE_TAG,
		nullptr,
		INVALID_TAG,
		performance_template_block );

	TAG_GROUP(
		scenario_group,
		SCENARIO_TAG,
		nullptr,
		INVALID_TAG,
		scenario_block );

	TAG_GROUP(
		scenario_required_resource_group,
		SCENARIO_REQUIRED_RESOURCE_TAG,
		nullptr,
		INVALID_TAG,
		scenario_required_resource_block );

	TAG_BLOCK_FROM_STRUCT(
		scenario_block,
		"scenario_block",
		1,
		scenario_struct_definition);

	TAG_BLOCK_FROM_STRUCT(
		scenario_required_resource_block,
		"scenario_required_resource_block",
		1,
		scenario_required_resource_struct_definition);

	#define SCENARIO_PROFILES_BLOCK_ID { 0x5AFB6481, 0x6ED940DC, 0x855CB02A, 0xB73D1AC4 }
	TAG_BLOCK(
		scenario_profiles_block,
		"scenario_profiles_block",
		MAXIMUM_SCENARIO_PLAYERS_PER_BLOCK,
		"scenario_starting_profile",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_PROFILES_BLOCK_ID)
	{
		{ _field_string, "name", FIELD_FLAG_INDEX },
		{ _field_real_fraction, "starting health damage", nullptr, nullptr, "[0,1]" },
		{ _field_real_fraction, "starting shield damage", nullptr, nullptr, "[0,1]" },
		{ _field_tag_reference, "primary weapon", &weapon_reference$5 },
		{ _field_short_integer, "primaryrounds loaded", "-1 = weapon default" },
		{ _field_short_integer, "primaryrounds total", "-1 = weapon default" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_real, "primaryage remaining", "0.0 = default, 1.0 = full" },

		{ _field_tag_reference, "secondary weapon", &weapon_reference$5 },
		{ _field_short_integer, "secondaryrounds loaded", "-1 = weapon default" },
		{ _field_short_integer, "secondaryrounds total", "-1 = weapon default" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_real, "secondaryage remaining", "0.0 = default, 1.0 = full" },

		{ _field_char_integer, "starting fragmentation grenade count" },
		{ _field_char_integer, "starting plasma grenade count" },
		{ _field_char_integer, "starting grenade 3 count" },
		{ _field_char_integer, "starting grenade 4 count" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 4 },
		{ _field_char_integer, "starting grenade 5 count" },
		{ _field_char_integer, "starting grenade 6 count" },
		{ _field_char_integer, "starting grenade 7 count" },
		{ _field_char_integer, "starting grenade 8 count" },

		{ _field_tag_reference, "starting equipment", &equipment_reference$2 },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_string_id, "starting tactical package" },
		{ _field_string_id, "starting support upgrade" },

		{ _field_short_block_index, "editor folder", FIELD_FLAG_UNKNOWN0, &g_scenario_editor_folder_block, _field_id_hide },
		FIELD_PAD("AHDVHJE", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	#define PERFORMANCE_TEMPLATE_ACTOR_BLOCK_STRUCT_ID { 0x7B70E3B5, 0x7F8E4983, 0x8B995D0B, 0xE8E80DC7 }
	TAG_BLOCK(
		performance_template_actor_block,
		"performance_template_actor_block",
		MAXIMUM_ACTORS_PER_PERFORMANCE,
		"s_performance_template_actor",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERFORMANCE_TEMPLATE_ACTOR_BLOCK_STRUCT_ID)
	{
		{ _field_long_flags, "flags", &scenario_performance_actor_flags_definition },
		{ _field_string_id, "Actor name", FIELD_FLAG_INDEX },
		{ _field_tag_reference, "Actor type", &character_reference$5 },
		{ _field_tag_reference, "Vehicle type", &vehicle_reference },
		{ _field_string_id, "Vehicle seat label" },
		{ _field_tag_reference, "Weapon type", &weapon_reference$6 },
		FIELD_PAD("pad0", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_custom_short_block_index, "Spawn Point" },
		{ _field_terminator }
	};

	#define SCENARIO_PERFORMANCE_LINE_BLOCK_STRUCT_ID { 0xA6CCBC29, 0x9C694FAB, 0x813635E3, 0x1CEBC1FF }
	TAG_BLOCK(
		scenario_performance_line_block,
		"scenario_performance_line_block",
		MAXIMUM_LINES_PER_PERFORMANCE,
		"s_scenario_performance_line",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_PERFORMANCE_LINE_BLOCK_STRUCT_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_custom_short_block_index, "Actor" },
		{ _field_word_flags, "flags", &scenario_performance_line_flags },
		{ _field_short_integer, "sleep minimum", nullptr, "ticks" },
		{ _field_short_integer, "sleep maximum", nullptr, "ticks" },
		{ _field_long_enum, "Line progress type", &scenario_performance_line_progress_definition },
		{ _field_block, "Script fragments", &scenario_performance_line_script_fragment_block },
		{ _field_block, "Point interaction", &scenario_performance_line_point_interaction_block },
		{ _field_block, "Animations", &scenario_performance_line_animation_block },
		{ _field_block, "Sync Actions", &scenario_performance_line_sync_action_block },
		{ _field_block, "Scenery Sync Actions", &scenario_performance_line_scenery_sync_action_block },
		{ _field_block, "Dialog lines", &scenario_performance_line_dialog_block },
		{ _field_block, "Sounds", &scenario_performance_line_sound_block },
		{ _field_terminator }
	};

	#define SCENARIO_PERFORMANCE_LINE_SCRIPT_FRAGMENT_BLOCK_ID { 0x46F762CB, 0x405D4C8A, 0xA0333371, 0xB410E28A }
	TAG_BLOCK(
		scenario_performance_line_script_fragment_block,
		"scenario_performance_line_script_fragment_block",
		MAXIMUM_SCRIPT_FRAGMENTS_PER_PERFORMANCE_LINE,
		"s_scenario_performance_line_script_fragment",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_PERFORMANCE_LINE_SCRIPT_FRAGMENT_BLOCK_ID)
	{
		{ _field_enum, "fragment placement", &scenario_performance_fragment_placement_definition },
		{ _field_enum, "fragment type", &scenario_performance_fragment_type_definition },
		{ _field_long_string, "fragment", "maximum 256 characters, type just branch condition (with brackets) in case of branches" },
		{ _field_long_string, "branch target", "the script to branch to (with any arguments to it). Used only if type is branch" },
		{ _field_terminator }
	};

	#define SCENARIO_PERFORMANCE_LINE_POINT_INTERACTION_BLOCK_STRUCT_ID { 0x42C82873, 0xA3CB4127, 0xA02B8B05, 0xABD54C59 }
	TAG_BLOCK(
		scenario_performance_line_point_interaction_block,
		"scenario_performance_line_point_interaction_block",
		MAXIMUM_POINT_INTERACTIONS_PER_PERFORMANCE_LINE,
		"s_scenario_performance_line_point_interaction",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_PERFORMANCE_LINE_POINT_INTERACTION_BLOCK_STRUCT_ID)
	{
		{ _field_long_flags, "interaction type", &scenario_performance_line_point_interaction_type_definition },
		{ _field_custom_short_block_index, "point" },
		{ _field_custom_short_block_index, "actor" },
		{ _field_string_id, "object name" },
		{ _field_string_id, "throttle style" },
		{ _field_terminator }
	};

	#define SCENARIO_PERFORMANCE_LINE_ANIMATION_BLOCK_STRUCT_ID { 0x7F3FD52E, 0x957543C2, 0xA41B8BBD, 0x3C94DACE }
	TAG_BLOCK(
		scenario_performance_line_animation_block,
		"scenario_performance_line_animation_block",
		MAXIMUM_ANIMATIONS_PER_PERFORMANCE_LINE,
		"s_scenario_performance_line_animation",
		SET_UNKNOWN0 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | 
		SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_PERFORMANCE_LINE_ANIMATION_BLOCK_STRUCT_ID)
	{
		{ _field_word_flags, "flags", &scenario_performance_line_animation_flags_definition },
		FIELD_PAD("pad0", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_string_id, "stance" },
		{ _field_string_id, "animation", FIELD_FLAG_INDEX },
		{ _field_real, "duration" },
		{ _field_real, "probability" },
		{ _field_real, "throttle transition time", nullptr, "seconds" },
		{ _field_long_integer, "transition frame count", "The number of frames from the end of the animation to start transitioning out" },
		{ _field_terminator }
	};

	#define SCENARIO_PERFORMANCE_LINE_SYNC_ACTION_BLOCK_STRUCT_ID { 0x3CD14898, 0x114147AE, 0x8303309F, 0x8F172B69 }
	TAG_BLOCK(
		scenario_performance_line_sync_action_block,
		"scenario_performance_line_sync_action_block",
		MAXIMUM_SYNC_ACTIONS_PER_PERFORMANCE_LINE,
		"s_scenario_performance_line_sync_action",
		SET_UNKNOWN0 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | 
		SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_PERFORMANCE_LINE_SYNC_ACTION_BLOCK_STRUCT_ID)
	{
		{ _field_string_id, "sync action name" },
		{ _field_real, "probability" },
		{ _field_custom_short_block_index, "attach to point" },
		{ _field_word_flags, "flags", &scenario_performance_line_sync_action_flag_type_definition },
		{ _field_block, "Actors", &scenario_performance_line_sync_action_actor_block },
		{ _field_terminator }
	};

	#define SCENARIO_PERFORMANCE_LINE_SYNC_ACTION_ACTOR_BLOCK_ID { 0x3B846F9F, 0x155E4332, 0x9334A3E3, 0xB50AE87B }
	TAG_BLOCK(
		scenario_performance_line_sync_action_actor_block,
		"scenario_performance_line_sync_action_actor_block",
		MAXIMUM_ACTORS_PER_PERFORMANCE,
		"s_scenario_sync_action_actor",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_PERFORMANCE_LINE_SYNC_ACTION_ACTOR_BLOCK_ID)
	{
		{ _field_custom_short_block_index, "Actor type" },
		FIELD_PAD("pad", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	#define SCENARIO_PERFORMANCE_LINE_SCENERY_SYNC_ACTION_BLOCK_STRUCT_ID { 0xF9F4EDE2, 0x1D8747B8, 0xBFDB568C, 0xEA43CA92 }
	TAG_BLOCK(
		scenario_performance_line_scenery_sync_action_block,
		"scenario_performance_line_scenery_sync_action_block",
		MAXIMUM_SCENERY_SYNC_ACTIONS_PER_PERFORMANCE_LINE,
		"s_scenario_performance_line_scenery_sync_action",
		SET_UNKNOWN0 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | 
		SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_PERFORMANCE_LINE_SCENERY_SYNC_ACTION_BLOCK_STRUCT_ID)
	{
		{ _field_string_id, "scenery object name" },
		{ _field_string_id, "sync action name" },
		{ _field_string_id, "stance name" },
		{ _field_real, "probability" },
		{ _field_word_flags, "flags", &scenario_performance_line_scenery_sync_action_flag_type_definition },
		FIELD_PAD("pad", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_block, "Actors", &scenario_performance_line_sync_action_actor_block },
		{ _field_terminator }
	};

	#define SCENARIO_PERFORMANCE_LINE_DIALOG_BLOCK_STRUCT_ID { 0xDA03E62A, 0xCBB84C28, 0xAFF51214, 0x5F621322 }
	TAG_BLOCK(
		scenario_performance_line_dialog_block,
		"scenario_performance_line_dialog_block",
		MAXIMUM_DIALOG_LINES_PER_PERFORMANCE_LINE,
		"s_scenario_performance_line_dialog",
		SET_UNKNOWN0 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | 
		SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_PERFORMANCE_LINE_DIALOG_BLOCK_STRUCT_ID)
	{
		{ _field_string_id, "dialog" },
		{ _field_real, "probability" },
		{ _field_terminator }
	};

	#define SCENARIO_PERFORMANCE_LINE_SOUND_BLOCK_STRUCT_ID { 0x952C6A2F, 0x077B4EA9, 0xB110F08B, 0xA8122D4E }
	TAG_BLOCK(
		scenario_performance_line_sound_block,
		"scenario_performance_line_sound_block",
		MAXIMUM_SOUNDS_PER_PERFORMANCE_LINE,
		"s_scenario_performance_line_sound",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_PERFORMANCE_LINE_SOUND_BLOCK_STRUCT_ID)
	{
		{ _field_tag_reference, "sound effect", &global_sound_reference },
		{ _field_custom_short_block_index, "attach to point" },
		FIELD_PAD("pad", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_string_id, "attach to object named" },
		{ _field_terminator }
	};

	#define PERFORMANCE_TEMPLATE_POINT_BLOCK_STRUCT_ID { 0x969B27EE, 0x95614149, 0x9EA14F37, 0x1AA14CB6 }
	TAG_BLOCK(
		performance_template_point_block,
		"performance_template_point_block",
		32,
		"s_performance_template_point",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERFORMANCE_TEMPLATE_POINT_BLOCK_STRUCT_ID)
	{
		{ _field_string_id, "Point name", FIELD_FLAG_INDEX },
		{ _field_real_vector_3d, "Relative Position", "The offset of the performance point from the center of the performance" },
		{ _field_real_euler_angles_2d, "Relative Facing", "The facing at the point in the space of the performance" },
		{ _field_terminator }
	};

	#define SCENARIO_STRUCTURE_BSP_REFERENCE_BLOCK_STRUCT_ID { 0xE6CC8C8B, 0x3B6B4E10, 0x897CB89E, 0x1FA22862 }
	TAG_BLOCK(
		scenario_structure_bsp_reference_block,
		"scenario_structure_bsp_reference_block",
		MAXIMUM_STRUCTURE_BSPS_PER_SCENARIO,
		"scenario_structure_bsp_reference",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_STRUCTURE_BSP_REFERENCE_BLOCK_STRUCT_ID)
	{
		{ _field_tag_reference, "structure bsp", FIELD_FLAG_INDEX, &structure_bsp_reference_non_resolving },
		{ _field_tag_reference, "local structure bsp", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_INDEX, &structure_bsp_reference_non_resolving },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_tag_reference, "structure bsp lighting^*!", &structure_lighting_bsp_reference },

		{ _field_tag_reference, "structure metadata", FIELD_FLAG_READ_ONLY, &Tag::Reference<struct StructureMetadata>::s_defaultDefinition },
		FIELD_EXPLANATION("Size Class", nullptr, FIELD_FLAG_NONE, "Tells lightmapper desired res for structure bitmaps.\nNumbers in parens are final sizes after compression"),
		{ _field_long_enum, "size class", &scenario_structure_size_enum },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_long_enum, "refinement size class", &scenario_structure_refinement_size_enum },

		{ _field_real, "hacky ambient min luminance" },
		{ _field_real, "direct/draft ambient min luminance" },
		{ _field_real, "structure vertex sink", "this is the most that we can sink a soft surface link snow in the structure_bsp via vertex painting." },

		{ _field_word_flags, "flags", &scenario_structure_bsp_reference_flags_definition },
		{ _field_short_block_index, "default sky", &scenario_sky_reference_block },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_real, "unknown@" },

		{ _field_tag_reference, "bsp specific cubemap", &scenario_cubemap_bitmap_reference },
		{ _field_tag_reference, "wind", &global_wind_reference },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 10 },
		{ _field_tag_reference, "authored light probe", &AuthoredLightProbeReference },
		{ _field_tag_reference, "vehicle authored light probe", &AuthoredLightProbeReference },
		{ _field_real, "max shadow count scale", "scale up or down the max number of shadows as set in the throttle tag per bsp" },
		{ _field_real, "decorator sunlight minimum", "0.0 means allow fully dark in the shadows, higher values will brighten up the shadowed decorators", nullptr, "[0.0 to 1.0]" },
		FIELD_CUSTOM("volumetric light shafts", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_struct, "volumetric light shaft settings", &scenarioVolumetricLightShaftSettingsStruct },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		FIELD_CUSTOM("floating shadows", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_struct, "floating shadow settings", &scenarioFloatingShadowSettingsStruct },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),

		FIELD_EXPLANATION("Clones", nullptr, FIELD_FLAG_NONE, "Describes which other bsps are physical \'clones\' of this bsp\nThis is used to determine how to attach \'position-only\' elements, like decorators, to the bsps:\nEach clone gets a separate copy of decorators that are in both.\nNon-cloned bsps cannot split decorators this way - the decorator will be given to the lowest numbered bsp\n"),
		{ _field_long_block_flags, "cloned bsp flags", &scenario_structure_bsp_reference_block },
		{ _field_struct, "lightmap setting", MAKE_OLD_NAMES("lightmap resolution buckets"), &scenario_lightmap_setting_struct },
		{ _field_real, "custom gravity scale", "0==nogravity, 1==full, set the custom gravity scale flag to make this parameter active" },
		{ _field_terminator }
	};

	#define SCENARIO_SKY_REFERENCE_BLOCK_ID { 0x4C469778, 0xC1694C79, 0x977EC9A8, 0xBC46911A }
	TAG_BLOCK(
		scenario_sky_reference_block,
		"scenario_sky_reference_block",
		MAXIMUM_SKIES_PER_SCENARIO,
		"s_scenario_sky_reference",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_SKY_REFERENCE_BLOCK_ID)
	{
		{ _field_tag_reference, "sky", &scenery_reference$2 },
		{ _field_real, "cloud scale", "mapping to the world unit" },
		{ _field_real, "cloud speed", "cloud movement speed" },
		{ _field_real, "cloud direction", "cloud movement direction, 0-360 degree" },
		{ _field_tag_reference, "cloud texture", "red channel is used", &global_bitmap_reference },
		{ _field_short_block_index, "name", FIELD_FLAG_INDEX, &scenario_object_names_block, _field_id_name },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_word_block_flags, "active on bsps!" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		FIELD_PAD("post-name-pad", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_long_block_flags, "active on bsps", FIELD_FLAG_UNKNOWN0, &scenario_structure_bsp_reference_block },

		{ _field_terminator }
	};

	#define SCENARIO_OBJECT_NAMES_BLOCK_ID { 0x6B05A7F7, 0x3584428C, 0x92762448, 0xA29197DB }
	TAG_BLOCK(
		scenario_object_names_block,
		"scenario_object_names_block",
		MAXIMUM_OBJECT_NAMES_PER_SCENARIO,
		"scenario_object_name",
		SET_UNKNOWN0 | SET_POSTPROCESS_RECURSIVELY | SET_IS_MEMCPYABLE | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_OBJECT_NAMES_BLOCK_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_custom_short_block_index, "object_type", FIELD_FLAG_UNKNOWN0 },
		{ _field_custom_short_block_index, "scenario_datum_index", FIELD_FLAG_UNKNOWN0 },
		{ _field_terminator }
	};

	#define SCENARIOBSPREFERENCEBLOCK_ID { 0x7DDBEF56, 0x5E7649D4, 0xA10F631A, 0xC7523C29 }
	TAG_BLOCK(
		scenarioBspReferenceBlock_block,
		"scenarioBspReferenceBlock",
		MAXIMUM_STRUCTURE_BSPS_PER_SCENARIO,
		"Tag::Reference<structure_bsp>",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIOBSPREFERENCEBLOCK_ID)
	{
		{ _field_tag_reference, "structure design", FIELD_FLAG_INDEX, &structureBspReferenceNonDependency },
		{ _field_terminator }
	};

	#define SCENARIO_CHILD_REFERENCES_BLOCK_ID { 0xA2EFF3E9, 0xFC0242BB, 0xAE4FD2CD, 0x88ACCE9B }
	TAG_BLOCK(
		scenario_child_references_block,
		"scenario_child_references_block",
		MAXIMUM_CHILD_SCENARIOS_PER_SCENARIO,
		"scenario_child_reference",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_CHILD_REFERENCES_BLOCK_ID)
	{
		{ _field_tag_reference, "tag", FIELD_FLAG_INDEX, &Tag::Reference<struct Scenario>::s_defaultDefinition },
		{ _field_terminator }
	};

	#define SCENARIO_DESIGN_REFERENCE_BLOCK_ID { 0xA6B28C8B, 0x3AB34E10, 0x89AB459E, 0x1AA22862 }
	TAG_BLOCK(
		scenario_design_reference_block,
		"scenario_design_reference_block",
		MAXIMUM_STRUCTURE_DESIGNS_PER_SCENARIO,
		"s_scenario_structure_design_reference",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_DESIGN_REFERENCE_BLOCK_ID)
	{
		{ _field_tag_reference, "structure design", FIELD_FLAG_INDEX, &structure_design_reference },
		{ _field_tag_reference, "local structure design", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_INDEX, &structure_design_reference },
		{ _field_terminator }
	};

	#define SCENARIO_ZONE_SET_PVS_BLOCK_ID { 0x1B4A2C99, 0x8ECA4B38, 0x8A4A2436, 0x5888158E }
	TAG_BLOCK(
		scenario_zone_set_pvs_block,
		"scenario_zone_set_pvs_block",
		k_maximum_scenario_zone_set_count+1,
		"s_scenario_zone_set_pvs",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_ZONE_SET_PVS_BLOCK_ID)
	{
		{ _field_dword_integer, "structure bsp mask", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "version", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_word_flags, "flags", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &scenario_zone_set_pvs_flags },
		{ _field_block, "bsp checksums", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &scenario_zone_set_bsp_checksum_block },
		{ _field_block, "structure bsp pvs", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &scenario_zone_set_bsp_pvs_block },
		{ _field_block, "portal=>device mapping", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &structure_portal_device_mapping_block },
		{ _field_terminator }
	};

	#define SCENARIO_ZONE_SET_BSP_CHECKSUM_BLOCK_ID { 0xA095C3A1, 0x36A34F37, 0xBC4C3E01, 0x17E4A7C7 }
	TAG_BLOCK(
		scenario_zone_set_bsp_checksum_block,
		"scenario_zone_set_bsp_checksum_block",
		MAXIMUM_STRUCTURE_BSPS_PER_SCENARIO,
		"long",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_ZONE_SET_BSP_CHECKSUM_BLOCK_ID)
	{
		{ _field_dword_integer, "bsp checksum", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	V5_TAG_BLOCK(cluster_sky_index_block, 65536)
	{
		{ _field_legacy, _field_char_block_index, "sky index" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(scenario_zone_set_bsp_pvs_unknown_block, 65536)
	{
		{ _field_legacy, _field_long_integer, "unknown" },
		{ _field_legacy, _field_terminator }
	};

	#define SCENARIO_ZONE_SET_BSP_PVS_BLOCK_ID { 0xFF83875C, 0xA9F04229, 0xA769E3B0, 0xE36AB1A8 }
	TAG_BLOCK(
		scenario_zone_set_bsp_pvs_block,
		"scenario_zone_set_bsp_pvs_block",
		MAXIMUM_STRUCTURE_BSPS_PER_SCENARIO,
		"s_scenario_zone_set_structure_bsp_pvs",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_ZONE_SET_BSP_PVS_BLOCK_ID)
	{
		{ _field_block, "cluster pvs", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &scenario_zone_set_cluster_pvs_block },
		{ _field_block, "cluster pvs doors closed", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &scenario_zone_set_cluster_pvs_block },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 3 },
		{ _field_legacy, _field_block, "sky index", &cluster_sky_index_block_block },
		{ _field_legacy, _field_block, "visible sky index", &cluster_sky_index_block_block },
		{ _field_legacy, _field_block, "unknown", &scenario_zone_set_bsp_pvs_unknown_block_block },

		{ _field_block, "bsp cluster mapings", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &scenario_zone_set_bsp_seam_cluster_mappings_block },
		{ _field_terminator }
	};

	#define SCENARIO_ZONE_SET_CLUSTER_PVS_BLOCK_ID { 0x6ACD70D4, 0x2B484AE0, 0xA1A1A7CB, 0x597648C4 }
	TAG_BLOCK(
		scenario_zone_set_cluster_pvs_block,
		"scenario_zone_set_cluster_pvs_block",
		MAXIMUM_CLUSTERS_PER_STRUCTURE,
		"s_scenario_zone_set_cluster_pvs",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_ZONE_SET_CLUSTER_PVS_BLOCK_ID)
	{
		{ _field_block, "cluster pvs bit vectors", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &scenario_zone_set_bsp_bits_block },
		{ _field_terminator }
	};

	#define SCENARIO_ZONE_SET_BSP_BITS_BLOCK_ID { 0x10A94FBA, 0xA71E43CE, 0x8AC7E6E6, 0x78196CDB }
	TAG_BLOCK(
		scenario_zone_set_bsp_bits_block,
		"scenario_zone_set_bsp_bits_block",
		MAXIMUM_STRUCTURE_BSPS_PER_SCENARIO,
		"s_scenario_zone_set_bsp_bits",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_ZONE_SET_BSP_BITS_BLOCK_ID)
	{
		{ _field_block, "bits", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &scenario_zone_set_cluster_pvs_bit_vector_block },
		{ _field_terminator }
	};

	#define SCENARIO_ZONE_SET_CLUSTER_PVS_BIT_VECTOR_BLOCK_ID { 0x91455EA9, 0x29C14710, 0x9953A70B, 0x26677B16 }
	TAG_BLOCK(
		scenario_zone_set_cluster_pvs_bit_vector_block,
		"scenario_zone_set_cluster_pvs_bit_vector_block",
		((((MAXIMUM_CLUSTERS_PER_STRUCTURE)+(k_int32_bits-1))>>k_int32_bits_bits)),
		"long",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_ZONE_SET_CLUSTER_PVS_BIT_VECTOR_BLOCK_ID)
	{
		{ _field_dword_integer, "dword", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define SCENARIO_ZONE_SET_BSP_SEAM_CLUSTER_MAPPINGS_BLOCK_ID { 0xABA3875C, 0xA9F0C2A9, 0xA7A453B0, 0xA31AB1A8 }
	TAG_BLOCK(
		scenario_zone_set_bsp_seam_cluster_mappings_block,
		"scenario_zone_set_bsp_seam_cluster_mappings_block",
		MAXIMUM_CLUSTERS_PER_STRUCTURE,
		"s_scenario_zone_set_cluster_seam_cluster_mappings",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_ZONE_SET_BSP_SEAM_CLUSTER_MAPPINGS_BLOCK_ID)
	{
		{ _field_block, "root clusters", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &scenario_zone_set_cluster_reference_block },
		{ _field_block, "attached clusters", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &scenario_zone_set_cluster_reference_block },
		{ _field_block, "connected clusters", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &scenario_zone_set_cluster_reference_block },
		{ _field_terminator }
	};

	#define SCENARIO_ZONE_SET_CLUSTER_REFERENCE_BLOCK_ID { 0xABBC875C, 0xA9F0CA19, 0xA7A434B0, 0xA31AB176 }
	TAG_BLOCK(
		scenario_zone_set_cluster_reference_block,
		"scenario_zone_set_cluster_reference_block",
		MAXIMUM_CLUSTERS_PER_STRUCTURE*MAXIMUM_STRUCTURE_BSPS_PER_SCENARIO,
		"s_cluster_reference",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_ZONE_SET_CLUSTER_REFERENCE_BLOCK_ID)
	{
		{ _field_char_integer, "bsp index", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_byte_integer, "cluster index", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define SCENARIO_ZONE_SET_BLOCK_ID { 0x49565D10, 0xEFBE4EE6, 0xB18E7C6D, 0x68053DDB }
	TAG_BLOCK(
		scenario_zone_set_block,
		"scenario_zone_set_block",
		k_maximum_scenario_zone_set_count,
		"s_scenario_zone_set",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_ZONE_SET_BLOCK_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_long_string, "name string", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_long_block_index, "pvs index", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &scenario_zone_set_pvs_block },
		{ _field_long_flags, "flags", &scenario_zone_set_flags_definition },
		{ _field_long_block_flags, "bsp zone flags", &scenario_structure_bsp_reference_block },
		{ _field_long_block_flags, "structure design zone flags", &scenario_design_reference_block },
		{ _field_long_block_flags, "runtime bsp zone flags", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &scenario_structure_bsp_reference_block },
		{ _field_long_block_flags, "sruntime tructure design zone flags", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &scenario_design_reference_block }, // dear person at 343 or Bungie, you originally named this field "sruntime tructure design zone flags" and I think you're stupid

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_long_block_flags, "required designer zones", MAKE_OLD_NAMES("designer zone flags"), &scenario_designer_zone_block, _field_id_block_flags_32bit }, // #TODO: Research this. Not entirely what what flags are here or removed???

		{ _field_qword_integer, "runtime designer zone flags", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY }, // could this just be 32bit in reach instead?
		{ _field_long_block_flags, "cinematic zones", &scenario_cinematics_block },
		{ _field_long_block_index, "hint previous zone set", &scenario_zone_set_block },
		{ _field_long_block_index, "audibility index", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &game_audibility_block },
		{ _field_block, "planar fog visibility", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &planar_fog_zone_set_visibility_definition_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 8 },
		{ _field_block, "budget overrides", &scenario_zone_set_budget_override_block },
		{ _field_tag_reference, "streaming_reference_tag", &streamingzoneset_reference },
		{ _field_real_point_3d, "world bounds min", "Physics world will include this min point" },
		{ _field_real_point_3d, "world bounds max", "Physics world will include this max point" },
		{ _field_block, "lipsync sounds", &scenario_zone_set_lipsync_block },
		{ _field_tag_reference, "cinematic soundbank", "only for cinematics. If you try to use this for anything else without talking to me, i will stab you in the face", &global_soundbank_reference },
		{ _field_real_rgb_color, "sky clear color", "linear color, must check override flag above to use" },
		FIELD_PAD("pad4", nullptr, FIELD_FLAG_NONE, 4),

		{ _field_terminator }
	};

	#define SCENARIO_BUDGET_REFERENCES_BLOCK_ID { 0x236E8B7D, 0x9D0D45DE, 0x9CEAEB74, 0xFEDA3382 }
	TAG_BLOCK(
		scenario_budget_references_block,
		"scenario_budget_references_block",
		k_maximum_budget_references_per_scenario,
		"s_scenario_budget_reference",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_BUDGET_REFERENCES_BLOCK_ID)
	{
		{ _field_tag_reference, "reference", FIELD_FLAG_INDEX, &scenario_budget_references_block_reference_reference },
		{ _field_terminator }
	};

	#define SCENARIO_ZONE_SET_BUDGET_OVERRIDE_BLOCK_ID { 0x038751F2, 0xE0C846D1, 0x8F567F0E, 0x0966DF8D }
	TAG_BLOCK(
		scenario_zone_set_budget_override_block,
		"scenario_zone_set_budget_override_block",
		1,
		"ScenarioZoneSetBudgetOverride",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_ZONE_SET_BUDGET_OVERRIDE_BLOCK_ID)
	{
		{ _field_long_integer, "env bitmap", nullptr, "megs" },
		{ _field_long_integer, "env object bitmap", nullptr, "megs" },
		{ _field_long_integer, "env geometry", nullptr, "megs" },
		{ _field_long_integer, "env object geometry", nullptr, "megs" },
		{ _field_terminator }
	};

	#define SCENARIO_ZONE_SET_LIPSYNC_BLOCK_ID { 0x0F76E710, 0xFD754360, 0x98E09719, 0x8CBE3BE7 }
	TAG_BLOCK(
		scenario_zone_set_lipsync_block,
		"scenario_zone_set_lipsync_block",
		SHORT_MAX,
		"ScenarioZoneSetBudgetOverride",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_ZONE_SET_LIPSYNC_BLOCK_ID)
	{
		{ _field_tag_reference, "dummy", &sound_reference$3 },
		{ _field_terminator }
	};

	#define SCENARIO_LIGHTING_ZONE_SET_BLOCK_ID { 0x79C011B7, 0xF6B34F11, 0xB4F34E8E, 0x389F9F4F }
	TAG_BLOCK(
		scenario_lighting_zone_set_block,
		"scenario_lighting_zone_set_block",
		k_maximum_scenario_zone_set_count,
		"s_scenario_lighting_zone_set_obsolete",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_LIGHTING_ZONE_SET_BLOCK_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_long_block_flags, "rendered bsp flags", &scenario_structure_bsp_reference_block },
		{ _field_long_block_flags, "extra bsp flags", &scenario_structure_bsp_reference_block },
		{ _field_terminator }
	};

	#define SCENARIO_FUNCTION_BLOCK_ID { 0x9B8F92BF, 0xE23F4122, 0xA8821B49, 0xAD8F29FB }
	TAG_BLOCK(
		scenario_function_block,
		"scenario_function_block",
		MAXIMUM_FUNCTIONS_PER_SCENARIO,
		"scenario_function",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_FUNCTION_BLOCK_ID)
	{
		{ _field_long_flags, "flags", &scenario_function_flags },
		{ _field_string, "name", FIELD_FLAG_INDEX },
		{ _field_real, "period", "this is the period for the above function (lower values make the function oscillate quickly, higher values make it oscillate slowly)", "seconds" },
		{ _field_short_block_index, "scale period by", "multiply this function by the above period", &scenario_function_block },
		{ _field_enum, "function", &global_periodic_functions_enum },
		{ _field_short_block_index, "scale function by", "multiply this function by the result of the above function", &scenario_function_block },
		{ _field_enum, "wobble function", "the curve used for the wobble", &global_periodic_functions_enum },
		{ _field_real, "wobble period", "the length of time it takes for the magnitude of this function to complete a wobble", "seconds" },
		{ _field_real, "wobble magnitude", "the amount of random wobble in the magnitude", "percent" },
		{ _field_real_fraction, "square wave threshold", "if non-zero, all values above the square wave threshold are snapped to 1.0, and all values below it are snapped to 0.0 to create a square wave." },
		{ _field_short_integer, "step count", "the number of discrete values to snap to (e.g., a step count of 5 would snap the function to 0.00,0.25,0.50,0.75 or 1.00)" },
		{ _field_enum, "map to", &global_transition_functions_enum },
		{ _field_short_integer, "sawtooth count", "the number of times this function should repeat (e.g., a sawtooth count of 5 would give the function a value of 1.0 at each of 0.25,0.50,0.75 as well as at 1.0" },
		FIELD_PAD("WBP", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_short_block_index, "scale result by", "multiply this function (from a weapon, vehicle, etc.) final result of all of the above math", &scenario_function_block },
		{ _field_enum, "bounds mode", "controls how the bounds, below, are used", &function_bounds_mode_enum },
		{ _field_real_fraction_bounds, "bounds" },
		{ _field_real, "runtime inverse bounds range", FIELD_FLAG_UNKNOWN0 },
		FIELD_PAD("OFLIM", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_short_block_index, "turn off with", "if the specified function is off, so is this function", &scenario_function_block },
		FIELD_PAD("FX", nullptr, FIELD_FLAG_NONE, 16),
		{ _field_real, "runtime reciprocal sawtooth count", FIELD_FLAG_UNKNOWN0 },
		{ _field_real, "runtime reciprocal bounds range", FIELD_FLAG_UNKNOWN0 },
		{ _field_real, "runtime reciprocal step count", FIELD_FLAG_UNKNOWN0 },
		{ _field_real, "runtime one over period", FIELD_FLAG_UNKNOWN0 },
		{ _field_terminator }
	};

	#define EDITOR_COMMENT_BLOCK_ID { 0x6FEF91B0, 0x9F8D4BB8, 0xABF5A1D9, 0xBA1A600D }
	TAG_BLOCK(
		editor_comment_block,
		"editor_comment_block",
		MAXIMUM_EDITOR_COMMENTS,
		"editor_comment_definition",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		EDITOR_COMMENT_BLOCK_ID)
	{
		{ _field_real_point_3d, "position" },
		{ _field_long_enum, "type", FIELD_FLAG_UNKNOWN0, &editor_comment_type_enum_definition },
		{ _field_string, "name", FIELD_FLAG_INDEX },
		{ _field_long_string, "comment" },
		{ _field_terminator }
	};

	#define DONT_USE_ME_SCENARIO_ENVIRONMENT_OBJECT_BLOCK_ID { 0x5F0CC647, 0xE8A84CED, 0x8889437C, 0xA1791104 }
	TAG_BLOCK(
		dont_use_me_scenario_environment_object_block,
		"dont_use_me_scenario_environment_object_block",
		MAXIMUM_ENVIRONMENT_OBJECTS_PER_SCENARIO,
		"scenario_environment_object",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		DONT_USE_ME_SCENARIO_ENVIRONMENT_OBJECT_BLOCK_ID)
	{
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_environment_unknown),
		{ _field_short_block_index, "bsp", FIELD_FLAG_READ_ONLY, &scenario_structure_bsp_reference_block },
		{ _field_short_integer, "runtime object type", FIELD_FLAG_UNKNOWN0 },
		{ _field_long_integer, "unique id", FIELD_FLAG_READ_ONLY },
		FIELD_PAD("WOQHKQB", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_tag, "object definition tag", FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "object", FIELD_FLAG_READ_ONLY | FIELD_FLAG_INDEX },
		FIELD_PAD("YMRTLZ", nullptr, FIELD_FLAG_NONE, 44),
		{ _field_terminator }
	};

	#define SCENARIOATTACHEDEFFECTSBLOCK_ID { 0xB21743AF, 0x88CE4201, 0x8541372F, 0x5401FFD4 }
	TAG_BLOCK(
		scenarioAttachedEffectsBlock_block,
		"scenarioAttachedEffectsBlock",
		ScenarioAttachedEffect::k_maxLoopingEffectsAllowed,
		"ScenarioAttachedEffect",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIOATTACHEDEFFECTSBLOCK_ID)
	{
		{ _field_long_integer, "cutscene flag index" },
		{ _field_tag_reference, "effect reference", FIELD_FLAG_INDEX, &globalEffectReferenceNonResourceDependency },
		{ _field_terminator }
	};

	#define SCENARIOATTACHEDLENSFLARESBLOCK_ID { 0x1CC24BE7, 0x4FC44DAE, 0xABDDD6C1, 0x0D3C9E07 }
	TAG_BLOCK(
		scenarioAttachedLensFlaresBlock_block,
		"scenarioAttachedLensFlaresBlock",
		ScenarioAttachedEffect::k_maxLensFlaresAllowed,
		"ScenarioAttachedEffect",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIOATTACHEDLENSFLARESBLOCK_ID)
	{
		{ _field_long_integer, "cutscene flag index" },
		{ _field_tag_reference, "lens flare reference", FIELD_FLAG_INDEX, &globalLensFlareReferenceNonResourceDependency },
		{ _field_terminator }
	};

	#define SCENARIOATTACHEDLIGHTCONESBLOCK_ID { 0x27DC2CA5, 0x251942AB, 0x992F3401, 0x5F00B2BA }
	TAG_BLOCK(
		scenarioAttachedLightConesBlock_block,
		"scenarioAttachedLightConesBlock",
		ScenarioAttachedLightCone::k_maxLightConesAllowed,
		"ScenarioAttachedLightCone",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIOATTACHEDLIGHTCONESBLOCK_ID)
	{
		{ _field_long_integer, "cutscene flag index" },
		{ _field_tag_reference, "light cone reference", FIELD_FLAG_INDEX, &Tag::Reference<struct LightConeDefinition>::s_defaultDefinition },
		{ _field_real_argb_color, "color" },
		{ _field_real_point_2d, "size" },
		{ _field_real, "intensity" },
		{ _field_tag_reference, "intensity curve", &Tag::Reference<class c_function_definition>::s_defaultDefinition },
		{ _field_terminator }
	};

	#define SCENARIO_SOFT_CEILINGS_BLOCK_ID { 0xB256A9B1, 0x07994E39, 0x90B64DA5, 0x84259A58 }
	TAG_BLOCK(
		scenario_soft_ceilings_block,
		"scenario_soft_ceilings_block",
		MAXIMUM_SCENARIO_SOFT_CEILINGS_PER_SCENARIO,
		"s_scenario_soft_ceiling",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_SOFT_CEILINGS_BLOCK_ID)
	{
		{ _field_word_flags, "flags", &scenario_soft_ceiling_flags_definition },
		{ _field_word_flags, "runtime flags", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &scenario_soft_ceiling_flags_definition },
		{ _field_string_id, "name" },
		{ _field_enum, "type", &soft_ceiling_type_enum },
		FIELD_PAD("my name is", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	#define SCENARIO_PLAYERS_BLOCK_ID { 0x2C1FF0F5, 0x45734A11, 0x891B161E, 0xC24170EF }
	TAG_BLOCK(
		scenario_players_block,
		"scenario_players_block",
		MAXIMUM_SCENARIO_PLAYERS_PER_BLOCK,
		"scenario_player_starting_location",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_WRITEABLE),
		SCENARIO_PLAYERS_BLOCK_ID)
	{
		{ _field_real_point_3d, "position" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_custom_long_block_index, "packedKeyOffaceref", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_UNKNOWN3 },
		{ _field_custom_long_block_index, "navMeshUIDOffaceref", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_UNKNOWN3 },

		{ _field_angle, "facing", nullptr, "degrees" },
		{ _field_angle, "pitch", nullptr, "degrees" },
		{ _field_short_integer, "insertion point index" },
		{ _field_word_flags, "flags", &scenario_player_flags },
		{ _field_short_block_index, "editor folder", FIELD_FLAG_UNKNOWN0, &g_scenario_editor_folder_block, _field_id_hide },
		FIELD_PAD("ANDYNDGE", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(
		scenario_trigger_volume_block,
		"scenario_trigger_volume_block",
		MAXIMUM_TRIGGER_VOLUMES_PER_SCENARIO,
		scenario_trigger_volume_struct);

	#define TRIGGER_VOLUME_POINT_BLOCK_ID { 0xC82D658B, 0x069F41B2, 0x9F32D7A8, 0x13062FAB }
	TAG_BLOCK(
		trigger_volume_point_block,
		"trigger_volume_point_block",
		k_maximum_points_per_sector,
		"s_real_sector_point",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		TRIGGER_VOLUME_POINT_BLOCK_ID)
	{
		{ _field_real_point_3d, "position" },
		{ _field_real_euler_angles_2d, "normal" },
		{ _field_terminator }
	};

	#define TRIGGER_VOLUME_RUNTIME_TRIANGLES_BLOCK_ID { 0xCAB2658B, 0x069F4165, 0x9AC2D7A8, 0x1306123B }
	TAG_BLOCK(
		trigger_volume_runtime_triangles_block,
		"trigger_volume_runtime_triangles_block",
		k_maximum_points_per_sector-2,
		"s_trigger_volume_triangle",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		TRIGGER_VOLUME_RUNTIME_TRIANGLES_BLOCK_ID,
		4)
	{
		{ _field_real_plane_3d, "plane 0", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real_plane_3d, "plane 1", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real_plane_3d, "plane 2", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real_plane_3d, "plane 3", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real_plane_3d, "plane 4", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real_point_2d, "vertex 0", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real_point_2d, "vertex 1", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real_point_2d, "vertex 2", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		FIELD_PAD("pad0", nullptr, FIELD_FLAG_NONE, 8),
		{ _field_terminator }
	};

	#define SCENARIO_KILL_TRIGGER_VOLUMES_BLOCK_ID { 0xF8016A0D, 0x0FB54EB9, 0xAE9F2DBA, 0x9A8BF849 }
	TAG_BLOCK(
		scenario_kill_trigger_volumes_block,
		"scenario_kill_trigger_volumes_block",
		MAXIMUM_TRIGGER_VOLUMES_PER_SCENARIO,
		"s_scenario_kill_trigger_volume",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_KILL_TRIGGER_VOLUMES_BLOCK_ID)
	{
		{ _field_short_block_index, "trigger volume", &scenario_trigger_volume_block },
		{ _field_byte_flags, "flags", &kill_volume_flags },
		FIELD_PAD("pad", nullptr, FIELD_FLAG_NONE, 1),
		{ _field_terminator }
	};

	#define SCENARIO_ATMOSPHERE_PALETTE_BLOCK_ID { 0x5E3AA7DD, 0x3DA64CE6, 0xA9642C49, 0xB0358993 }
	TAG_BLOCK(
		scenario_atmosphere_palette_block,
		"scenario_atmosphere_palette_block",
		MAXIMUM_ATMOSPHERE_PALETTE_ENTRIES_PER_STRUCTURE,
		"scenario_atmosphere_palette_entry",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_ATMOSPHERE_PALETTE_BLOCK_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_UNKNOWN0 },
		{ _field_word_integer, "Atmosphere Setting Index", FIELD_FLAG_UNKNOWN0 },
		FIELD_PAD("XQLJZUE", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_tag_reference, "atmosphere", FIELD_FLAG_INDEX, &global_atmosphere_definition_reference },
		{ _field_terminator }
	};

	#define SCENARIO_WEATHER_PALETTE_BLOCK_ID { 0x9D9FC817, 0x83D54FF3, 0xA4331AEF, 0xD988677F }
	TAG_BLOCK(
		scenario_weather_palette_block,
		"scenario_weather_palette_block",
		MAXIMUM_WEATHER_PALETTE_ENTRIES_PER_STRUCTURE,
		"scenario_weather_palette_entry",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_WEATHER_PALETTE_BLOCK_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_tag_reference, "rain", &global_rain_definition_reference },
		{ _field_terminator }
	};

	#define SCENARIO_ZONE_SET_SWITCH_TRIGGER_VOLUME_BLOCK_ID { 0xDBC2A01B, 0xC1BC44B3, 0xAF8E24E1, 0xBC8618F1 }
	TAG_BLOCK(
		scenario_zone_set_switch_trigger_volume_block,
		"scenario_zone_set_switch_trigger_volume_block",
		MAXIMUM_TRIGGER_VOLUMES_PER_SCENARIO,
		"s_scenario_zone_set_switch_trigger_volume",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_ZONE_SET_SWITCH_TRIGGER_VOLUME_BLOCK_ID)
	{
		{ _field_word_flags, "flags", &scenario_zone_set_switch_trigger_volume_flags_definition },
		{ _field_short_block_index, "begin zone set", &scenario_zone_set_block },
		{ _field_short_block_index, "trigger volume", &scenario_trigger_volume_block },
		{ _field_short_block_index, "commit zone set", &scenario_zone_set_block },
		{ _field_terminator }
	};

	#define SCENARIO_DECALS_BLOCK_ID { 0x2F188AAB, 0x722045CB, 0xBB8315AD, 0xA352D120 }
	TAG_BLOCK(
		scenario_decals_block,
		"scenario_decals_block",
		MAXIMUM_DECALS_PER_SCENARIO,
		"scenario_decal",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | 
		SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_DECALS_BLOCK_ID)
	{
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_filter),
		{ _field_short_block_index, "decal palette index", &scenario_decal_palette_block },
		{ _field_byte_flags, "flags", &decal_placement_flags },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_char_integer, "unknown" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		FIELD_PAD("post-decal-palette-index-pad", nullptr, FIELD_FLAG_NONE, 1),
		{ _field_struct, "manual bsp flags", FIELD_FLAG_READ_ONLY, &manualBspFlagsReferences },

		{ _field_real_quaternion, "rotation", FIELD_FLAG_READ_ONLY },
		{ _field_real_point_3d, "position", FIELD_FLAG_READ_ONLY },
		{ _field_real, "scale x", MAKE_OLD_NAMES("scale") },
		{ _field_real, "scale y" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_real, "cull angle" },

		{ _field_terminator }
	};

	#define SCENARIO_DECAL_PALETTE_BLOCK_ID { 0xC7E94CE6, 0x20F34065, 0xA165ACE3, 0x5C495C0A }
	TAG_BLOCK(
		scenario_decal_palette_block,
		"scenario_decal_palette_block",
		MAXIMUM_DECAL_PALETTES_PER_SCENARIO,
		"scenario_decal_palette_entry",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_DECAL_PALETTE_BLOCK_ID)
	{
		{ _field_tag_reference, "reference", FIELD_FLAG_INDEX, &decal_system_reference },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_long_integer, "max static bucket size", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },

		{ _field_terminator }
	};

	#define SCENARIO_DETAIL_OBJECT_COLLECTION_PALETTE_BLOCK_ID { 0xC7D6DFC3, 0xD05849AE, 0xA3485B28, 0x5E5D947F }
	TAG_BLOCK(
		scenario_detail_object_collection_palette_block,
		"scenario_detail_object_collection_palette_block",
		MAXIMUM_DETAIL_OBJECT_LAYERS_PER_STRUCTURE,
		"scenario_detail_object_collection_palette_entry",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_DETAIL_OBJECT_COLLECTION_PALETTE_BLOCK_ID)
	{
		{ _field_tag_reference, "name", FIELD_FLAG_INDEX, &global_detail_object_collection_reference },
		FIELD_PAD("XBMYUIKEJ", nullptr, FIELD_FLAG_NONE, 32),
		{ _field_terminator }
	};

	#define SCENARIO_CUTSCENE_FLAG_BLOCK_ID { 0xE5E8BB54, 0x69394856, 0xBCAC9DB6, 0x2C324EB0 }
	TAG_BLOCK(
		scenario_cutscene_flag_block,
		"scenario_cutscene_flag_block",
		MAXIMUM_CUTSCENE_FLAGS_PER_SCENARIO,
		"scenario_cutscene_flag",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_CUTSCENE_FLAG_BLOCK_ID)
	{
		FIELD_PAD("MMNGQBXC", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_real_point_3d, "position" },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_real_euler_angles_2d, "facing" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_real_euler_angles_3d, "facing" },

		{ _field_short_block_index, "editor folder", FIELD_FLAG_UNKNOWN0, &g_scenario_editor_folder_block, _field_id_hide },
		{ _field_short_block_index, "source bsp", FIELD_FLAG_READ_ONLY, &scenario_structure_bsp_reference_block },
		{ _field_terminator }
	};

	V5_TAG_BLOCK(scenario_unknown, 65536) // CUSTOM
	{
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_short_integer, "unknown" },
		{ _field_legacy, _field_short_integer, "unknown" },
		{ _field_legacy, _field_short_integer, "unknown" },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_terminator }
	};

	TAG_REFERENCE(scenario_resources_reference_block_reference);

	V5_TAG_BLOCK(scenario_resources_reference_block, NUMBER_OF_SCENARIO_RESOURCE_TYPES)
	{
		{ _field_legacy, _field_version_less_or_equal, _engine_type_halo2 },
		{ _field_legacy, _field_tag_reference, "reference*", &scenario_resources_reference_block_reference },

		{ _field_legacy, _field_version_greater, _engine_type_halo2, 21 },
		{ _field_legacy, _field_tag_reference, "scenery reference", &scenario_resources_reference_block_reference },
		{ _field_legacy, _field_tag_reference, "bipeds reference", &scenario_resources_reference_block_reference },
		{ _field_legacy, _field_tag_reference, "vehicles reference", &scenario_resources_reference_block_reference },
		{ _field_legacy, _field_tag_reference, "equipment reference", &scenario_resources_reference_block_reference },
		{ _field_legacy, _field_tag_reference, "weapons reference", &scenario_resources_reference_block_reference },
		{ _field_legacy, _field_tag_reference, "sound scenery reference", &scenario_resources_reference_block_reference },
		{ _field_legacy, _field_tag_reference, "lights reference", &scenario_resources_reference_block_reference },
		{ _field_legacy, _field_tag_reference, "devices reference", &scenario_resources_reference_block_reference },
		{ _field_legacy, _field_tag_reference, "effect scenery reference", &scenario_resources_reference_block_reference },
		{ _field_legacy, _field_tag_reference, "decals reference", &scenario_resources_reference_block_reference },
		{ _field_legacy, _field_tag_reference, "cinematics reference", &scenario_resources_reference_block_reference },
		{ _field_legacy, _field_tag_reference, "trigger volumes reference", &scenario_resources_reference_block_reference },
		{ _field_legacy, _field_tag_reference, "cluster data reference", &scenario_resources_reference_block_reference },
		{ _field_legacy, _field_tag_reference, "comments reference", &scenario_resources_reference_block_reference },
		{ _field_legacy, _field_tag_reference, "creature reference", &scenario_resources_reference_block_reference },
		{ _field_legacy, _field_tag_reference, "structure lighing reference", &scenario_resources_reference_block_reference },
		{ _field_legacy, _field_tag_reference, "decorators reference", &scenario_resources_reference_block_reference },
		{ _field_legacy, _field_tag_reference, "sky references reference", &scenario_resources_reference_block_reference },
		{ _field_legacy, _field_tag_reference, "cubemap reference", &scenario_resources_reference_block_reference },
		{ _field_legacy, _field_tag_reference, "performances reference", &scenario_resources_reference_block_reference },
		{ _field_legacy, _field_tag_reference, "dumplings reference", &scenario_resources_reference_block_reference },

		{ _field_legacy, _field_terminator }
	};

	TAG_REFERENCE(scenario_hs_source_reference_block_block_reference, HSC_TAG);

	V5_TAG_BLOCK(scenario_hs_source_reference_block, k_maximum_hs_source_files_per_scenario)
	{
		{ _field_legacy, _field_tag_reference, "reference*", & scenario_hs_source_reference_block_block_reference },
		{ _field_legacy, _field_terminator }
	};

	TAG_REFERENCE(scenario_ai_resource_reference_block_reference);

	V5_TAG_BLOCK(scenario_ai_resource_reference_block, k_number_of_scenario_ai_types)
	{
		{ _field_legacy, _field_tag_reference, "reference*", & scenario_ai_resource_reference_block_reference },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(scenario_resources_block, 1)
	{
		{ _field_legacy, _field_version_greater, _engine_type_halo2, 2 },
		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 1 },
		{ _field_legacy, _field_long_integer, "unknown" },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_halo2 },
		{ _field_legacy, _field_block, "references*", &scenario_resources_reference_block_block },

		{ _field_legacy, _field_block, "Script Source*", &scenario_hs_source_reference_block_block },
		{ _field_legacy, _field_block, "AI Resources*", &scenario_ai_resource_reference_block_block },

		{ _field_legacy, _field_version_greater, _engine_type_halo2, 2 },
		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 1 },
		{ _field_legacy, _field_block, "references*", &scenario_resources_reference_block_block },

		{ _field_legacy, _field_terminator }
	};

	#define SCENARIO_CUTSCENE_CAMERA_POINT_BLOCK_ID { 0xC38639D4, 0x24BA4407, 0xB58BCDD4, 0xF728D8DC }
	TAG_BLOCK(
		scenario_cutscene_camera_point_block,
		"scenario_cutscene_camera_point_block",
		MAXIMUM_CUTSCENE_CAMERA_POINTS_PER_SCENARIO,
		"scenario_cutscene_camera_point",
		SET_UNKNOWN4 | SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_CUTSCENE_CAMERA_POINT_BLOCK_ID)
	{
		{ _field_word_flags, "flags", &scenario_cutscene_camera_flags },
		{ _field_enum, "type", &scenario_cutscene_camera_types },
		{ _field_string, "name", FIELD_FLAG_INDEX },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_camera_matrix_editor),
		FIELD_PAD("pad", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_real_point_3d, "position" },
		{ _field_real_euler_angles_3d, "orientation" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 4 },
		{ _field_short_block_index, "zone set", &scenario_zone_set_block },
		FIELD_PAD("padd", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_useless_pad, "" },
		{ _field_useless_pad, "" },

		{ _field_terminator }
	};

	#define SCENARIO_SAFE_ZONE_TRIGGER_VOLUMES_BLOCK_ID { 0x3B6FF7F7, 0xD6F1480D, 0x9AC3621D, 0xA0ED3BA2 }
	TAG_BLOCK(
		scenario_safe_zone_trigger_volumes_block,
		"scenario_safe_zone_trigger_volumes_block",
		MAXIMUM_TRIGGER_VOLUMES_PER_SCENARIO,
		"s_scenario_safe_zone_trigger_volume",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_SAFE_ZONE_TRIGGER_VOLUMES_BLOCK_ID)
	{
		{ _field_short_block_index, "trigger volume", &scenario_trigger_volume_block },
		{ _field_byte_flags, "flags", &kill_volume_flags },
		FIELD_PAD("pad", nullptr, FIELD_FLAG_NONE, 1),
		{ _field_terminator }
	};

	#define TRIGGER_VOLUME_MOPP_CODE_BLOCK_ID { 0x69A0250B, 0x5B194147, 0xCD8BA5D6, 0xA1ED8CA3 }
	TAG_BLOCK(
		trigger_volume_mopp_code_block,
		"trigger_volume_mopp_code_block",
		1,
		"s_trigger_volume_mopp",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		TRIGGER_VOLUME_MOPP_CODE_BLOCK_ID)
	{
		{ _field_long_integer, "trigger volume checksum" },
		{ _field_block, "mopp code", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &mopp_code_definition_block },
		{ _field_terminator }
	};

	#define SCENARIO_REQUISITION_TRIGGER_VOLUMES_BLOCK_ID { 0x124EB6B7, 0xA2D644B4, 0xB0A21EF6, 0xF4611612 }
	TAG_BLOCK(
		scenario_requisition_trigger_volumes_block,
		"scenario_requisition_trigger_volumes_block",
		MAXIMUM_TRIGGER_VOLUMES_PER_SCENARIO,
		"s_scenario_requisition_trigger_volume",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_REQUISITION_TRIGGER_VOLUMES_BLOCK_ID)
	{
		{ _field_short_block_index, "trigger volume", &scenario_trigger_volume_block },
		{ _field_word_flags, "flags", &scenario_requisition_trigger_volume_flags_definition },
		{ _field_terminator }
	};

	#define SCENARIO_LOCATION_NAME_TRIGGER_VOLUMES_BLOCK_ID { 0x327D2673, 0x4CDC49DD, 0x93D5F5BC, 0x2A051223 }
	TAG_BLOCK(
		scenario_location_name_trigger_volumes_block,
		"scenario_location_name_trigger_volumes_block",
		MAXIMUM_TRIGGER_VOLUMES_PER_SCENARIO,
		"s_scenario_location_name_trigger_volume",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_LOCATION_NAME_TRIGGER_VOLUMES_BLOCK_ID)
	{
		{ _field_short_block_index, "trigger volume", &scenario_trigger_volume_block },
		{ _field_string, "name" },
		{ _field_terminator }
	};

	#define SCENARIOUNSAFESPAWNZONETRIGGERVOLUMESBLOCK_ID { 0xD81BF5E7, 0xF2C24D8E, 0xA5E09973, 0xD7BACE17 }
	TAG_BLOCK(
		scenarioUnsafeSpawnZoneTriggerVolumesBlock_block,
		"scenarioUnsafeSpawnZoneTriggerVolumesBlock",
		MAXIMUM_TRIGGER_VOLUMES_PER_SCENARIO,
		"ScenarioUnsafeSpawnVolume",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIOUNSAFESPAWNZONETRIGGERVOLUMESBLOCK_ID)
	{
		{ _field_short_block_index, "trigger volume", &scenario_trigger_volume_block },
		{ _field_terminator }
	};

	#define SCENARIO_CAMERA_FX_PALETTE_BLOCK_ID { 0x391597B7, 0x927B496B, 0xA8EBEFFE, 0x90972B2F }
	TAG_BLOCK(
		scenario_camera_fx_palette_block,
		"scenario_camera_fx_palette_block",
		MAXIMUM_CAMERA_FX_PALETTE_ENTRIES_PER_STRUCTURE,
		"scenario_camera_fx_palette_entry",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_CAMERA_FX_PALETTE_BLOCK_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_tag_reference, "cluster camera_fx tag", "if empty, uses default", "if empty, uses default", &global_camera_fx_settings_reference },
		{ _field_byte_flags, "flags", &camera_fx_palette_flags },
		FIELD_PAD("EKJFER", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_real, "forced exposure", "the target exposure (ONLY USED WHEN FORCE EXPOSURE IS CHECKED)", "stops" },
		{ _field_real, "forced auto-exposure screen brightness", "how bright you want the screen to be (ONLY USED WHEN FORCE AUTO EXPOSURE IS CHECKED)", nullptr, "[0.0001-1]" },
		{ _field_real, "exposure min", nullptr, "stops" },
		{ _field_real, "exposure max", nullptr, "stops" },
		{ _field_real, "inherent bloom" },
		{ _field_real, "bloom intensity" },
		{ _field_terminator }
	};

	#define SCENARIO_CLUSTER_DATA_BLOCK_ID { 0x2C52EDFB, 0xACFE4C9E, 0xAA66C6ED, 0xD4B370C9 }
	TAG_BLOCK(
		scenario_cluster_data_block,
		"scenario_cluster_data_block",
		MAXIMUM_STRUCTURE_BSPS_PER_SCENARIO,
		"s_scenario_cluster_data",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_CLUSTER_DATA_BLOCK_ID)
	{
		{ _field_tag_reference, "bsp", FIELD_FLAG_READ_ONLY | FIELD_FLAG_INDEX, &structure_bsp_reference_non_resolving },
		{ _field_long_integer, "bsp checksum", FIELD_FLAG_READ_ONLY },
		{ _field_block, "cluster centroids", FIELD_FLAG_READ_ONLY, &scenario_cluster_points_block },
		{ _field_long_block_index, "default acoustic palette", &scenario_acoustics_palette_block_definition_block },
		{ _field_block, "acoustics", MAKE_OLD_NAMES("background sounds"), FIELD_FLAG_READ_ONLY, &scenario_cluster_acoustics_block },
		{ _field_block, "atmospheric properties", FIELD_FLAG_READ_ONLY, &scenario_cluster_atmosphere_properties_block },
		{ _field_block, "camera fx properties", FIELD_FLAG_READ_ONLY, &scenario_cluster_camera_fx_properties_block },
		{ _field_block, "weather properties", FIELD_FLAG_READ_ONLY, &scenario_cluster_weather_properties_block },
		{ _field_terminator }
	};

	#define SCENARIO_CLUSTER_POINTS_BLOCK_ID { 0xEB2CB6F0, 0x63FF4765, 0x8D37ED82, 0x6D07B4D1 }
	TAG_BLOCK(
		scenario_cluster_points_block,
		"scenario_cluster_points_block",
		MAXIMUM_CLUSTERS_PER_STRUCTURE,
		"real_point3d",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_CLUSTER_POINTS_BLOCK_ID)
	{
		{ _field_real_point_3d, "centroid", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define SCENARIO_CLUSTER_ACOUSTICS_BLOCK_STRUCT_ID { 0xBF96DEDB, 0xC56E4461, 0x8A27F764, 0x81157DE4 }
	TAG_BLOCK(
		scenario_cluster_acoustics_block,
		"scenario_cluster_acoustics_block",
		MAXIMUM_CLUSTERS_PER_STRUCTURE,
		"s_scenario_cluster_property",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_CLUSTER_ACOUSTICS_BLOCK_STRUCT_ID)
	{
		{ _field_short_block_index, "type", FIELD_FLAG_INDEX, &scenario_acoustics_palette_block_definition_block },
		FIELD_PAD("XQQ", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	#define SCENARIO_CLUSTER_ATMOSPHERE_PROPERTIES_BLOCK_ID { 0x5AA1878B, 0x7AFC441D, 0x92F1DBC3, 0xD6BB0B64 }
	TAG_BLOCK(
		scenario_cluster_atmosphere_properties_block,
		"scenario_cluster_atmosphere_properties_block",
		MAXIMUM_CLUSTERS_PER_STRUCTURE,
		"s_scenario_cluster_property",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_CLUSTER_ATMOSPHERE_PROPERTIES_BLOCK_ID)
	{
		{ _field_short_block_index, "type", FIELD_FLAG_INDEX, &scenario_atmosphere_palette_block },
		FIELD_PAD("XQQ", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	#define SCENARIO_CLUSTER_CAMERA_FX_PROPERTIES_BLOCK_ID { 0x04C3DEFF, 0xE1014E4F, 0x95C9EC20, 0x1B0C0C04 }
	TAG_BLOCK(
		scenario_cluster_camera_fx_properties_block,
		"scenario_cluster_camera_fx_properties_block",
		MAXIMUM_CLUSTERS_PER_STRUCTURE,
		"s_scenario_cluster_property",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_CLUSTER_CAMERA_FX_PROPERTIES_BLOCK_ID)
	{
		{ _field_short_block_index, "type", FIELD_FLAG_INDEX, &scenario_camera_fx_palette_block },
		FIELD_PAD("XQQ", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	#define SCENARIO_CLUSTER_WEATHER_PROPERTIES_BLOCK_ID { 0x5501F721, 0x233D41FC, 0x8CBF9D50, 0x77B6F973 }
	TAG_BLOCK(
		scenario_cluster_weather_properties_block,
		"scenario_cluster_weather_properties_block",
		MAXIMUM_CLUSTERS_PER_STRUCTURE,
		"s_scenario_cluster_property",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_CLUSTER_WEATHER_PROPERTIES_BLOCK_ID)
	{
		{ _field_short_block_index, "type", FIELD_FLAG_INDEX, &scenario_weather_palette_block },
		FIELD_PAD("XQQ", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	#define SCENARIO_SPAWN_DATA_BLOCK_ID { 0x802F5382, 0x9FDA439F, 0x845A38FB, 0xA6060A27 }
	TAG_BLOCK(
		scenario_spawn_data_block,
		"scenario_spawn_data_block",
		1,
		"s_scenario_spawn_data",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_SPAWN_DATA_BLOCK_ID)
	{
		{ _field_real, "game object reset height" },
		{ _field_terminator }
	};

	#define SOUNDSUBTITLEBLOCK_ID { 0x1031970B, 0xDBCF4F62, 0x0B1B5F44, 0x119CDDCF }
	TAG_BLOCK(
		SoundSubtitleBlock_block,
		"SoundSubtitleBlock",
		MAXIMUM_SUBTITLES_PER_SCENARIO,
		"SoundSubtitle",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SOUNDSUBTITLEBLOCK_ID)
	{
		{ _field_long_integer, "tagIndex" },
		{ _field_string_id, "subtitleName" },
		{ _field_terminator }
	};

	#define SCENARIO_CHEAP_PARTICLE_SYSTEM_PALETTE_BLOCK_ID { 0x826B3BF5, 0xBB024D06, 0x9A9CC14D, 0xDE9EFD73 }
	TAG_BLOCK(
		scenario_cheap_particle_system_palette_block,
		"scenario_cheap_particle_system_palette_block",
		s_scenario_cheap_particle_emitter_palette_entry::k_maximum_scenario_cheap_particle_system_palette_entries,
		"s_scenario_cheap_particle_emitter_palette_entry",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_CHEAP_PARTICLE_SYSTEM_PALETTE_BLOCK_ID)
	{
		{ _field_tag_reference, "definition", FIELD_FLAG_INDEX, &cheap_particle_emitter_reference },
		{ _field_terminator }
	};

	#define SCENARIO_CHEAP_PARTICLE_SYSTEMS_BLOCK_ID { 0x7D7FD824, 0xE8234CD7, 0xAA72C46F, 0x0428C991 }
	TAG_BLOCK(
		scenario_cheap_particle_systems_block,
		"scenario_cheap_particle_systems_block",
		s_scenario_cheap_particle_system::k_maximum_scenario_cheap_particle_systems,
		"s_scenario_cheap_particle_system",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_CHEAP_PARTICLE_SYSTEMS_BLOCK_ID)
	{
		{ _field_short_block_index, "palette index", FIELD_FLAG_INDEX, &scenario_cheap_particle_system_palette_block },
		FIELD_PAD("VLKSJLER", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real_point_3d, "position" },
		{ _field_real_euler_angles_3d, "rotation" },
		{ _field_terminator }
	};

	#define SCENARIO_CINEMATIC_LIGHTING_PALETTE_BLOCK_ID { 0x43D75F43, 0xE5A54B36, 0xB4332785, 0x75D44A46 }
	TAG_BLOCK(
		scenario_cinematic_lighting_palette_block,
		"scenario_cinematic_lighting_palette_block",
		k_maximum_scenario_cinematic_lighting_palette_entry_count,
		"s_scenario_cinematic_lighting_palette_entry",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_CINEMATIC_LIGHTING_PALETTE_BLOCK_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_tag_reference, "cinematic_lighting_tag", &global_new_cinematic_lighting_reference },
		{ _field_terminator }
	};

	#define SCENARIO_AIRPROBES_BLOCK_ID { 0x7F6345AD, 0x5BD4425F, 0x8DEEF6ED, 0xF522A677 }
	TAG_BLOCK(
		scenario_airprobes_block,
		"scenario_airprobes_block",
		k_max_airprobes_per_scenario,
		"s_scenario_airprobe_info",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_AIRPROBES_BLOCK_ID)
	{
		{ _field_real_point_3d, "airprobe position" },
		{ _field_string_id, "airprobe name", FIELD_FLAG_INDEX },
		{ _field_long_integer, "BSP index", FIELD_FLAG_INDEX },
		{ _field_terminator }
	};

	#define MODEL_REFERENCES_BLOCK_ID { 0x6910250B, 0x56194147, 0xBD8BA5D6, 0x51ED8CA3 }
	TAG_BLOCK(
		model_references_block,
		"model_references_block",
		SHORT_MAX,
		"s_tag_reference",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		MODEL_REFERENCES_BLOCK_ID)
	{
		{ _field_tag_reference, "model reference", FIELD_FLAG_INDEX, &model_reference$5 },
		{ _field_terminator }
	};

	#define SCENARIO_PERFORMANCES_BLOCK_STRUCT_ID { 0x0C0C1943, 0xAB2C410E, 0xB5058F24, 0xE7E5BA05 }
	TAG_BLOCK(
		scenario_performances_block,
		"scenario_performances_block",
		MAXIMUM_PERFORMANCES_PER_SCENARIO,
		"s_scenario_performance",
		SET_UNKNOWN0 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | 
		SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_PERFORMANCES_BLOCK_STRUCT_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_string_id, "script name", "The name of a custom script used to drive the performance. If none is given, a default script is uses that goes through the lines in sequence" },
		{ _field_string_id, "global name", "The name of a script global that will be declared for this performance." },
		{ _field_word_flags, "flags", &performance_flags },
		{ _field_short_block_index, "editor folder", FIELD_FLAG_UNKNOWN0, &g_scenario_editor_folder_block, _field_id_hide },
		{ _field_custom_short_block_index, "Point set" },
		FIELD_PAD("padding", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_block, "Actors", &scenario_performance_actor_block },
		{ _field_block, "Lines", &scenario_performance_line_block },
		{ _field_real_point_3d, "position" },
		{ _field_real_euler_angles_2d, "template facing" },
		{ _field_real, "thespian radius", "The radius inside which actors have to be in order to start.", MAKE_OLD_NAMES("performance radius") },
		{ _field_real, "attraction radius", "The radius inside which actors become attracted to the thespian origin." },
		{ _field_real_fraction, "attraction probability per second", "The probability that an actor be attracted once inside the thespian radius, every second.", nullptr, "[0,1]" },
		{ _field_string_id, "template" },
		{ _field_long_integer, "template index", FIELD_FLAG_UNKNOWN0 },
		{ _field_block, "tasks", FIELD_FLAG_UNKNOWN0, &scenario_performance_task_block },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_default),
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_default),
		{ _field_terminator }
	};

	#define SCENARIO_PERFORMANCE_ACTOR_BLOCK_STRUCT_ID { 0xCC4F984F, 0xE5DF44CB, 0xBA6183C7, 0x77AD7E3B }
	TAG_BLOCK(
		scenario_performance_actor_block,
		"scenario_performance_actor_block",
		MAXIMUM_ACTORS_PER_PERFORMANCE,
		"s_scenario_performance_actor",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_PERFORMANCE_ACTOR_BLOCK_STRUCT_ID)
	{
		{ _field_long_flags, "flags", &scenario_performance_actor_flags_definition },
		{ _field_string_id, "Actor name", FIELD_FLAG_INDEX },
		{ _field_short_block_index, "Actor type", &character_palette_block },
		{ _field_short_block_index, "Weapon type", &scenario_weapon_palette_block },
		{ _field_short_block_index, "Vehicle type", &scenario_vehicle_palette_block },
		{ _field_custom_short_block_index, "debug spawn point" },
		{ _field_string_id, "Vehicle seat label" },
		{ _field_terminator }
	};

	#define SCENARIO_PERFORMANCE_TASK_BLOCK_STRUCT_ID { 0x75C14F83, 0xB7224AB4, 0xB092DFD0, 0x65E02EDE }
	TAG_BLOCK(
		scenario_performance_task_block,
		"scenario_performance_task_block",
		MAXIMUM_TASKS_PER_PERFORMANCE,
		"s_stimulus_distribution_task",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_PERFORMANCE_TASK_BLOCK_STRUCT_ID)
	{
		{ _field_short_block_index, "objective", &objectives_block },
		{ _field_custom_short_block_index, "task" },
		{ _field_terminator }
	};

	#define SCENARIORANDOMORDNANCEDROPSETBLOCK_ID { 0x53132DE6, 0x9A8A49F1, 0xA35A67A0, 0x2E1EE7C6 }
	TAG_BLOCK(
		scenarioRandomOrdnanceDropSetBlock_block,
		"scenarioRandomOrdnanceDropSetBlock",
		k_maximum_scenario_ordnance_drop_sets,
		"scenarioOrdnanceDropSet",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIORANDOMORDNANCEDROPSETBLOCK_ID)
	{
		{ _field_word_flags, "drop set flags", &ordnance_dropset_flags },
		FIELD_PAD("ODSF", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_string, "name", FIELD_FLAG_INDEX },
		{ _field_long_integer, "count" },
		{ _field_tag_reference, "Ordnance List", &Tag::Reference<struct ScenarioOrdnance>::s_defaultDefinition },
		{ _field_block, "Drop point list", &scenarioRandomOrdnanceDropPointBlock_block },
		{ _field_terminator }
	};

	#define SCENARIORANDOMORDNANCEDROPPOINTBLOCK_ID { 0x8246CA07, 0x0C304010, 0xBBFA7F86, 0x6DBDDF6A }
	TAG_BLOCK(
		scenarioRandomOrdnanceDropPointBlock_block,
		"scenarioRandomOrdnanceDropPointBlock",
		k_maximum_random_ordnance_drop_points,
		"scenarioOrdnanceDropPoint",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIORANDOMORDNANCEDROPPOINTBLOCK_ID)
	{
		{ _field_short_block_index, "Drop point", &scenario_scenery_block },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(
		ScenarioUnitRecordingBlock_block,
		"ScenarioUnitRecordingBlock",
		k_maximum_unit_recordings_per_scenario,
		ScenarioUnitRecordingBlock_struct);

	#define LOADSCREENREFERENCEBLOCK_ID { 0x56847268, 0xE9764C18, 0xBDD617A3, 0xF04F21D2 }
	TAG_BLOCK(
		loadScreenReferenceBlock_block,
		"loadScreenReferenceBlock",
		SHORT_MAX,
		"LoadScreenReferenceBlock",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		LOADSCREENREFERENCEBLOCK_ID)
	{
		FIELD_EXPLANATION("Map IDs", nullptr, FIELD_FLAG_NONE, "These are pulled from levels_map_id_constants.h\nk_mp_z00_testchamber_map_id\t\t\t10777)\nk_mp_wraparound_map_id\t\t\t\t\t10080)  \nk_mp_z05_cliffside_map_id              10085)  // complex \nk_mp_z11_valhalla_id\t\t\t\t\t10091)\nk_mp_ca_gore_valley_map_id\t\t\t\t10200)\nk_mp_ca_tower_map_id\t\t\t\t\t10202)\nk_mp_ca_warhouse_map_id\t\t\t\t10210)\nk_mp_ca_blood_cavern_map_id\t\t\t10225)\nk_mp_ca_blood_crash_map_id\t\t\t\t10226)\nk_mp_ca_forge_erosion_map_id\t\t\t10245)\nk_mp_ca_redoubt_map_id\t\t\t\t\t10252)\nk_mp_ca_forge_bonanza_map_id\t\t\t10255)\nk_mp_ca_forge_ravine_map_id\t\t\t10256)\nk_mp_ca_canyon_map_id\t\t\t\t\t10261)\nk_mp_zd_02_grind_map_id\t\t\t\t10102)\n\nk_ff81_courtyard_map_id\t\t\t\t11081)\nk_ff82_scurve_map_id\t\t\t\t\t11071)\nk_ff83_breach_map_id\t\t\t\t\t11061)\nk_ff84_temple_map_id\t\t\t\t\t11084)\nk_ff85_island_map_id\t\t\t\t\t11091)\nk_ff86_sniperalley_map_id\t\t\t\t11101)\nk_ff87_chopperbowl_map_id\t\t\t\t11111)\nk_ff88_horseshou_map_id\t\t\t\t11121)\nk_ff89_infinity_map_id\t\t\t\t\t11131)\nk_ff90_fortsw_map_id\t\t\t\t\t11141)\n\nk_sp_intro_map_id\t\t\t\t\t\t12000)\nk_sp_m10_crash_map_id\t\t\t\t\t12010)\nk_sp_m20_haven_map_id\t\t\t\t\t12020)\nk_sp_m30_cryptum_map_id\t\t\t\t12030)\nk_sp_m40_invasion_map_id\t\t\t\t12040)\nk_sp_m60_rescue_map_id\t\t\t\t\t12060)\nk_sp_m70_liftoff_map_id\t\t\t\t12070)\nk_sp_m80_delta_map_id\t\t\t\t\t12080)\nk_sp_m90_sacrifice_map_id\t\t\t\t12090)\n\nk_sp_max_environment_solo_map_id\t\t12499)\n"),
		{ _field_long_integer, "Map ID", "Only valid for main menu - otherwise always use first reference" },
		{ _field_tag_reference, "Load Screen Reference", &global_loadscreen_reference },
		{ _field_real, "Tint Gradient Lookup V Coordinate", "Value between 0.0 and 1.0 determines which line to use for tint.\nA negative value will choose a random tint from the palette." },
		{ _field_terminator }
	};

	#define SCENARIOFLOATINGSHADOWCASCADESETTINGSARRAY_ID { 0xB53B3A91, 0xBF404DB2, 0x89CA7210, 0x6570A7D4 }
	TAG_ARRAY(
		scenarioFloatingShadowCascadeSettingsArray_array,
		"scenarioFloatingShadowCascadeSettingsArray",
		4,
		"scenarioFloatingShadowCascadeSettings",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIOFLOATINGSHADOWCASCADESETTINGSARRAY_ID)
	{
		FIELD_CUSTOM("CASCADE", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_real, "cascade half-width" },
		{ _field_real, "cascade length" },
		{ _field_real, "cascade offset" },
		{ _field_real, "bias" },
		{ _field_real, "filter width" },
		{ _field_real, "sun direction offset", "if we want to slide the frustum up closer to the sun so that not as much of the frustum is below the ground" },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		{ _field_terminator }
	};

	#define OBJECT_SALT_STORAGE_ARRAY_ID { 0x2BAB1657, 0x98084D7F, 0x8C0FFCBC, 0x954E72C1 }
	TAG_ARRAY(
		object_salt_storage_array,
		"object_salt_storage_array",
		k_maximum_number_of_object_salts,
		"long",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		OBJECT_SALT_STORAGE_ARRAY_ID)
	{
		{ _field_long_integer, "salt", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	V5_TAG_BLOCK(scenario_structured_buffer_interops_block, 1)
	{
		{ _field_legacy, _field_api_interop, "effect", & structured_buffer_struct_definition },
		{ _field_legacy, _field_api_interop, "beam", &structured_buffer_struct_definition },
		{ _field_legacy, _field_api_interop, "contrail", &structured_buffer_struct_definition },
		{ _field_legacy, _field_api_interop, "light volume", &structured_buffer_struct_definition },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(scenario_unknown_object_reference, 65536) // CUSTOM
	{
		{ _field_legacy, _field_struct, "object ID*!", & scenario_object_id_struct_struct_definition },
		{ _field_legacy, _field_char_integer, "unknown" }, // index?
		{ _field_legacy, _field_pad, "pad", 1 },
		{ _field_legacy, _field_short_integer, "unknown" },
		{ _field_legacy, _field_short_integer, "unknown" },
		{ _field_legacy, _field_short_integer, "unknown" },
		{ _field_legacy, _field_terminator }
	};

	#define SCENARIO_STRUCT_DEFINITION_ID { 0xEFAE882E, 0x0DC94D1D, 0xA358CB6A, 0x34875D40 }
	TAG_STRUCT(
		scenario_struct_definition,
		"scenario_struct_definition",
		"Scenario",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN4 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | 
		SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_WRITEABLE),
		SCENARIO_STRUCT_DEFINITION_ID)
	{
		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_block, "child scenarios", &scenario_child_references_block },

		FIELD_CUSTOM("link to scenario lightmap", nullptr, FIELD_FLAG_NONE, _field_id_unknown_compile),
		{ _field_enum, "type", &scenario_type_enum },
		{ _field_word_flags, "flags", &scenario_flags },
		{ _field_long_flags, "runtime trigger volume flags", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &scenario_runtime_trigger_volume_flags },
		{ _field_long_integer, "campaign id" },
		{ _field_long_integer, "map id" },
		{ _field_string_id, "map name", "Used to associate external resources with this map - e.g. PDA camera setting block names." },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 6 },
		{ _field_tag_reference, "Scenario sound bank", "Scenario-specific sound bank.", &global_soundbank_reference },
		{ _field_tag_reference, "Scenario sound bank Number 2", "Another scenario-specific sound bank. All will be loaded.", &global_soundbank_reference },
		{ _field_tag_reference, "Scenario sound bank Number 3", "Another scenario-specific sound bank. All will be loaded.", &global_soundbank_reference },
		{ _field_tag_reference, "Scenario sound bank Number 4", "Another scenario-specific sound bank. All will be loaded.", &global_soundbank_reference },
		{ _field_string_id, "Inside reverb name", "This reverb will be used for inside areas when the listener is outside." },
		{ _field_long_integer, "Inside reverb hash ID", FIELD_FLAG_UNKNOWN0 },

		{ _field_short_integer, "sound permutation mission id" },
		FIELD_PAD("pad", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_long_integer, "minimum structure bsp importer version", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_angle, "local north" },
		{ _field_real, "local sea level", "used to calculate aircraft altitude", "wu" },
		{ _field_real, "altitude cap", nullptr, "wu" },
		{ _field_real_point_3d, "sandbox origin point", "forge coordinates are relative to this point" },
		{ _field_real, "sandbox budget" },
		{ _field_string_id, "default vehicle set", "when vehicle set is \"map default,\" this vehicle set is used" },
		{ _field_tag_reference, "game performance throttles", MAKE_OLD_NAMES("performance thorttles"), &game_performance_throttle_reference$2 },
		{ _field_block, "structure bsps", &scenario_structure_bsp_reference_block },
		{ _field_block, "structure designs", &scenario_design_reference_block },
		{ _field_tag_reference, "structure seams", &structure_seams_reference },
		{ _field_tag_reference, "local structure seams", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &structure_seams_reference },
		{ _field_block, "skies", &scenario_sky_reference_block },
		{ _field_block, "zone set pvs", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &scenario_zone_set_pvs_block },
		{ _field_block, "zone set audibility", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &game_audibility_block },
		{ _field_block, "zone sets", &scenario_zone_set_block },
		{ _field_block, "lighting zone sets", FIELD_FLAG_UNKNOWN0, &scenario_lighting_zone_set_block },
		{ _field_block, "predicted resources", FIELD_FLAG_READ_ONLY, &g_null_block },
		{ _field_block, "functions", &scenario_function_block },
		{ _field_data, "editor scenario data" },
		{ _field_block, "comments", &editor_comment_block },
		{ _field_block, "unused scenario environment objects", FIELD_FLAG_UNKNOWN0, &dont_use_me_scenario_environment_object_block },
		{ _field_block, "object names", FIELD_FLAG_READ_ONLY, &scenario_object_names_block, _field_id_sort },
		{ _field_block, "scenery", &scenario_scenery_block },
		{ _field_block, "scenery palette", &scenario_scenery_palette_block, _field_id_sort },
		{ _field_block, "bipeds", &scenario_biped_block },
		{ _field_block, "biped palette", &scenario_biped_palette_block, _field_id_sort },
		{ _field_block, "vehicles", &scenario_vehicle_block },
		{ _field_block, "vehicle palette", &scenario_vehicle_palette_block, _field_id_sort },
		{ _field_block, "equipment", &scenario_equipment_block },
		{ _field_block, "equipment palette", &scenario_equipment_palette_block, _field_id_sort },
		{ _field_block, "weapons", &scenario_weapon_block },
		{ _field_block, "weapon palette", &scenario_weapon_palette_block, _field_id_sort },
		{ _field_block, "device groups", &device_group_block, _field_id_sort },
		{ _field_block, "machines", &scenario_machine_block },
		{ _field_block, "machine palette", &scenario_machine_palette_block, _field_id_sort },
		{ _field_block, "terminals", &scenario_terminal_block },
		{ _field_block, "terminal palette", &scenario_terminal_palette_block, _field_id_sort },
		{ _field_block, "controls", &scenario_control_block },
		{ _field_block, "control palette", &scenario_control_palette_block, _field_id_sort },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_block, "dispensers", &ScenarioDispenserBlock_block },
		{ _field_block, "dispenser palette", &ScenarioDispenserPaletteBlock_block, _field_id_sort },

		{ _field_block, "sound scenery", &scenario_sound_scenery_block },
		{ _field_block, "sound scenery palette", &scenario_sound_scenery_palette_block, _field_id_sort },
		{ _field_block, "giants", &scenario_giant_block },
		{ _field_block, "giant palette", &scenario_giant_palette_block, _field_id_sort },
		{ _field_block, "effect scenery", &scenario_effect_scenery_block },
		{ _field_block, "effect scenery palette", &scenario_effect_scenery_palette_block, _field_id_sort },
		{ _field_block, "spawners", &scenario_spawner_block },
		{ _field_block, "spawner palette", &scenario_spawner_palette_block, _field_id_sort },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 4 },
		{ _field_block, "bink palette", &binkPaletteBlock_block, _field_id_sort },
		{ _field_block, "scenario attached effects", &scenarioAttachedEffectsBlock_block },
		{ _field_block, "scenario attached lens flares", &scenarioAttachedLensFlaresBlock_block },
		{ _field_block, "scenario attached light cones", &scenarioAttachedLightConesBlock_block },

		{ _field_block, "map variant palettes", &map_variant_palette_block },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_block, "legacy map variant palette info", &map_variant_legacy_palette_info_block_block },

		{ _field_tag_reference, "multiplayer object types", &global_multiplayer_object_type_list_reference },
		{ _field_char_enum, "multiplayer map size", &multiplayer_map_size_enum },
		FIELD_PAD("mulmapsizepad", nullptr, FIELD_FLAG_NONE, 3),

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_block, "Playtest req palette", "requisition for SvE, activated via an init.txt option for playtest balance", &scenario_requisition_palette_block, _field_id_sort },

		{ _field_real, "player requisition frequency", nullptr, "seconds" },
		{ _field_long_integer, "initial game currency", nullptr, "SpaceBucks" },
		{ _field_block, "soft ceilings", &scenario_soft_ceilings_block },
		{ _field_block, "player starting profile", &scenario_profiles_block },
		{ _field_block, "player starting locations", &scenario_players_block },
		{ _field_block, "trigger volumes", &scenario_trigger_volume_block },
		{ _field_block, "acoustic sectors", &scenario_acoustic_sector_block },
		{ _field_block, "acoustic transitions", &scenario_acoustic_transition_block },
		{ _field_block, "atmosphere dumplings", &scenario_atmosphere_dumpling_block },
		{ _field_block, "weather dumplings", &scenario_weather_dumpling_block },
		{ _field_block, "recorded animations", &recorded_animation_block },
		{ _field_block, "zone set switch trigger volumes", FIELD_FLAG_UNKNOWN3, &scenario_zone_set_switch_trigger_volume_block },
		{ _field_block, "named location volumes", &scenario_named_location_volume_block },
		FIELD_EXPLANATION("SPAWN INFLUENCE OVERRIDES", nullptr, FIELD_FLAG_NONE, "You can use the following to override multiplayer global spawn influencers for the scenario.  Default settings are defined in multiplayer/multiplayer_globals.multiplayer_globals."),
		{ _field_tag_reference, "Spawn Settings", &g_spawnSettingsReference },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 10 },
		{ _field_legacy, _field_block, "unknown@", &g_null_block_block }, // assumed
		{ _field_legacy, _field_block, "unknown", &scenario_unknown_block },
		{ _field_legacy, _field_block, "unknown", &scenario_unknown_block },
		{ _field_legacy, _field_block, "unknown", &scenario_unknown_block },
		{ _field_legacy, _field_block, "unknown", &scenario_unknown_block },
		{ _field_legacy, _field_block, "unknown@", &g_null_block }, // assumed
		{ _field_legacy, _field_block, "unknown@", &g_null_block }, // assumed
		{ _field_legacy, _field_block, "unknown@", &g_null_block }, // assumed
		{ _field_legacy, _field_block, "unknown@", &g_null_block }, // assumed
		{ _field_legacy, _field_block, "unknown@", &g_null_block }, // assumed

		FIELD_EXPLANATION("RENDER FLUFF", nullptr, FIELD_FLAG_NONE, "Pretty"),
		{ _field_block, "decals", &scenario_decals_block },
		{ _field_block, "decal palette", &scenario_decal_palette_block, _field_id_sort },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 3 },
		{ _field_long_integer, "largest zoneset static decal memory size", "this is memory for the largest possible zoneset - default (0) is 2048", "kilobytes" },
		{ _field_data, "static decal memory data", FIELD_FLAG_READ_ONLY },
		{ _field_real, "decal depth bias override (USE WITH CAUTION)", "you should not need to do this -- this is for a mission with strange collision geo" },

		{ _field_block, "detail object collection palette", &scenario_detail_object_collection_palette_block },
		{ _field_block, "style pallette", &style_palette_block, _field_id_sort },
		{ _field_block, "squad groups", &squad_groups_block },
		{ _field_block, "squads", &squads_block },
		{ _field_block, "zones", &zone_block },
		{ _field_block, "squad patrols", &squad_patrol_block },
		{ _field_block, "actual cues", FIELD_FLAG_UNKNOWN0, &ai_cue_block },
		{ _field_block, "full cues", MAKE_OLD_NAMES("cues"), &ai_full_cue_block },
		{ _field_block, "quick cues", &ai_quick_cue_block },
		{ _field_block, "mission scenes", &ai_scene_block },
		{ _field_block, "character palette", &character_palette_block, _field_id_sort },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_tag_reference, "ai pathfinding data", &Tag::Reference<struct ai_pathfinding>::s_defaultDefinition },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_block, "unknown@", &g_null_block_block }, // assumed

		{ _field_block, "ai user hint data", &user_hint_block },
		{ _field_block, "ai recording references", &ai_recording_reference_block },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 5 },
		{ _field_legacy, _field_data, "script data" },
		{ _field_legacy, _field_block, "scripts*", &hs_scripts_block },
		{ _field_legacy, _field_block, "globals*", &hs_globals_block },
		{ _field_legacy, _field_block, "references*", &hs_references_block },
		{ _field_legacy, _field_block, "unknown@", &g_null_block }, // assumed

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 3 },
		{ _field_struct, "script data", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &hs_script_data_struct },
		{ _field_block, "manual script file references", &hs_source_reference_block },
		{ _field_tag_reference, "compiled global scripts", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &Tag::Reference<struct HSScriptContainer>::s_defaultDefinition },

		{ _field_block, "scripting data", &cs_script_data_block },
		{ _field_block, "cutscene flags", &scenario_cutscene_flag_block },
		{ _field_block, "cutscene camera points", &scenario_cutscene_camera_point_block },
		{ _field_block, "cutscene titles", &scenario_cutscene_title_block },
		{ _field_tag_reference, "custom object names", &global_multilingual_unicode_string_list_reference },
		{ _field_tag_reference, "chapter title text", &global_multilingual_unicode_string_list_reference },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 2 },
		{ _field_legacy, _field_block, "scenario resources", &scenario_resources_block_block },
		{ _field_legacy, _field_block, "hs unit seats!", &hs_unit_seat_block }, // gets moved into the new h4 tag group iirc

		{ _field_block, "scenario kill triggers", &scenario_kill_trigger_volumes_block },
		{ _field_block, "scenario safe zone triggers", &scenario_safe_zone_trigger_volumes_block },
		{ _field_block, "scenario trigger volumes mopp code", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &trigger_volume_mopp_code_block },
		{ _field_block, "scenario requisition triggers", &scenario_requisition_trigger_volumes_block },
		{ _field_block, "scenario location name triggers", &scenario_location_name_trigger_volumes_block },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_block, "hs syntax datums", &hs_syntax_datum_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 3 },
		{ _field_block, "scenario unsafe spawn trigger volumes", &scenarioUnsafeSpawnZoneTriggerVolumesBlock_block },
		{ _field_short_block_index, "scenario ordnance bounds trigger volume", &scenario_trigger_volume_block },
		FIELD_PAD("ordnandy", nullptr, FIELD_FLAG_NONE, 2),

		{ _field_block, "Orders", &orders_block },
		{ _field_block, "Triggers", &triggers_block },
		{ _field_block, "acoustics palette", MAKE_OLD_NAMES("background sound palette"), &scenario_acoustics_palette_block_definition_block, _field_id_sort },
		{ _field_block, "atmosphere", &scenario_atmosphere_palette_block, _field_id_sort },
		{ _field_block, "camera fx palette", &scenario_camera_fx_palette_block, _field_id_sort },
		{ _field_block, "weather palette", &scenario_weather_palette_block, _field_id_sort },
		{ _field_block, "scenario cluster data", &scenario_cluster_data_block },
		{ _field_array, "object_salts", FIELD_FLAG_READ_ONLY, &object_salt_storage_array },
		{ _field_block, "spawn data", &scenario_spawn_data_block },
		{ _field_tag_reference, "sound effect collection", &global_sound_effect_collection_reference },
		{ _field_block, "crates", &scenario_crate_block },
		{ _field_block, "crate palette", &scenario_crate_palette_block, _field_id_sort },
		{ _field_block, "flock palette", &flock_palette_block, _field_id_sort },
		{ _field_block, "flocks", &flock_instance_block },
		{ _field_tag_reference, "subtitles", &global_multilingual_unicode_string_list_reference },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 1 },
		{ _field_block, "soundSubtitles", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &SoundSubtitleBlock_block },

		{ _field_block, "creatures", &scenario_creature_block },
		{ _field_block, "creature palette", &scenario_creature_palette_block, _field_id_sort },
		{ _field_block, "big battle creature palette", &big_battle_creature_palette_block, _field_id_sort },
		{ _field_block, "editor folders", FIELD_FLAG_UNKNOWN0, &g_scenario_editor_folder_block },
		{ _field_tag_reference, "game engine strings", &global_multilingual_unicode_string_list_reference },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		FIELD_PAD("QVUC", nullptr, FIELD_FLAG_NONE, 8),

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		FIELD_PAD("QVUC", nullptr, FIELD_FLAG_NONE, 4),

		{ _field_block, "mission dialogue", &ai_scenario_mission_dialogue_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_tag_reference, "voiceover", &Tag::Reference<struct MainMenuVoiceover>::s_defaultDefinition },

		{ _field_tag_reference, "objectives", &global_multilingual_unicode_string_list_reference },
		{ _field_tag_reference, "interpolators", &global_scenario_interpolator_reference },
		{ _field_block, "shared references", &hs_references_block },
		{ _field_tag_reference, "camera effects", &global_camera_fx_settings_reference },
		{ _field_tag_reference, "global screen effect", "ignores the falloff curves", &global_area_screen_effect_reference },
		{ _field_tag_reference, "global ssao", &global_ssao_definition_reference },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_tag_reference, "sky atmosphere parameters", &global_sky_atmosphere_definition_reference },

		{ _field_tag_reference, "atmosphere globals", "settings that apply to the entire scenario", &global_atmosphere_globals_reference },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_tag_reference, "global lighting", &global_chocolate_mountain_reference },

		{ _field_tag_reference, "new lightmaps", &scenario_lightmap_reference },
		{ _field_tag_reference, "performance throttles", &global_performance_throttles_reference },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_block, "scenario unknown object", &scenario_unknown_object_reference_block }, // #TODO: ai related? (see ObjectReferenceFrames in tagtool for more information)

		{ _field_block, "ai objectives", &objectives_block },
		{ _field_block, "designer zones", &scenario_designer_zone_block },
		{ _field_block, "zone debugger", FIELD_FLAG_UNKNOWN0, &scenario_zone_debugger_block_definition_block },
		{ _field_block, "decorators", &scenario_decorator_block },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach, 2 },
		{ _field_block, "neuticle palette", &scenario_cheap_particle_system_palette_block },
		{ _field_block, "neuticles", &scenario_cheap_particle_systems_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		FIELD_EXPLANATION("Scriptable Light Rigs", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_block, "scriptable light rigs", &scriptableLightRigBlock_block },

		{ _field_block, "cinematics", &scenario_cinematics_block },
		{ _field_block, "cinematic lighting palette", &scenario_cinematic_lighting_palette_block },
		{ _field_block, "override player representations", &player_representation_block },
		{ _field_block, "campaign metagame", &campaign_metagame_scenario_block },
		{ _field_block, "soft surfaces", &soft_surfaces_definition_block },
		{ _field_block, "cubemaps", &scenario_cubemap_block },
		{ _field_block, "airprobes", &scenario_airprobes_block },
		{ _field_block, "budget references", &scenario_budget_references_block },
		{ _field_block, "model references", FIELD_FLAG_READ_ONLY, &model_references_block },
		{ _field_block, "thespian", MAKE_OLD_NAMES("performances"), &scenario_performances_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_block, "puppetShows", &PuppetShowsBlock_block },

		{ _field_tag_reference, "location name globals", &global_location_name_globals_reference },
		FIELD_EXPLANATION("garbage collection", nullptr, FIELD_FLAG_NONE, "specify zero for values that should use the data in the globals tag."),
		{ _field_block, "garbage collection", &garbage_collection_block, _field_id_slap },
		{ _field_tag_reference, "hud screen reference", "appears for the player through the scenario", &Tag::Reference<struct CuiScreenDefinition>::s_defaultDefinition },
		{ _field_tag_reference, "required resources", &scenario_required_resource_reference },
		{ _field_tag_reference, "variant globals", &variant_globals_reference },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 1 },
		{ _field_legacy, _field_block, "structured buffer interops", &scenario_structured_buffer_interops_block_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 21 },
		{ _field_tag_reference, "ordnance map bitmap", &global_bitmap_reference },
		{ _field_real_fraction_bounds, "ordnance map depth bounds" },
		FIELD_EXPLANATION("Random ordnance", nullptr, FIELD_FLAG_NONE, "Drops randomly selected set of ordnance at positions marked by drop_point objects."),
		{ _field_word_flags, "ordnance flags", &ordnance_flags },
		FIELD_PAD("SRO", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_tag_reference, "drop pod (scenery)", "if set, overrides that in progression globals", &scenery_reference$5 },
		{ _field_long_integer, "Ordnance drop count" },
		{ _field_long_integer, "Ordnance max active count", "zero means unlimited" },
		{ _field_real_bounds, "Time between random drops", nullptr, "seconds" },
		{ _field_string, "Initial drop name" },
		{ _field_real, "Initial drop delay", "from start of play til fanfare begins", "seconds" },
		{ _field_real, "Initial drop fanfare duration", nullptr, "seconds" },
		{ _field_string, "Normal drop name", nullptr, "blank string will match all sets" },
		{ _field_string, "Player drop name" },
		{ _field_real, "Nav marker visibility proximity", nullptr, "wu" },
		{ _field_real, "Nav marker premium visibility proximity", nullptr, "wu" },
		{ _field_block, "Drop sets", &scenarioRandomOrdnanceDropSetBlock_block, _field_id_slap },
		FIELD_EXPLANATION("Ordnance personal", nullptr, FIELD_FLAG_NONE, "Ordnance personal"),
		{ _field_tag_reference, "Scenario Ordnance List", &Tag::Reference<struct ScenarioOrdnance>::s_defaultDefinition },
		{ _field_block, "Unit Recordings", &ScenarioUnitRecordingBlock_block },
		{ _field_block, "Exit load screen", "for non-mainmenu, we always use the first one", &loadScreenReferenceBlock_block },

		{ _field_terminator }
	};

	#define SCENARIO_REQUIRED_RESOURCE_STRUCT_DEFINITION_ID { 0xA9B90BB8, 0xC5684B2B, 0xA9CD6FDD, 0x9B7C6602 }
	TAG_STRUCT(
		scenario_required_resource_struct_definition,
		"scenario_required_resource_struct_definition",
		"s_scenario_required_resources",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_REQUIRED_RESOURCE_STRUCT_DEFINITION_ID)
	{
		{ _field_block, "resources", &scenario_budget_references_block },
		{ _field_terminator }
	};

	#define SCENARIOVOLUMETRICLIGHTSHAFTSETTINGSSTRUCT_ID { 0xDF38658D, 0x07724BB3, 0xB0012C2A, 0xACBA277F }
	TAG_STRUCT(
		scenarioVolumetricLightShaftSettingsStruct,
		"scenarioVolumetricLightShaftSettingsStruct",
		"scenarioVolumetricLightShaftSettings",
		SET_POSTPROCESS_RECURSIVELY | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIOVOLUMETRICLIGHTSHAFTSETTINGSSTRUCT_ID)
	{
		{ _field_byte_flags, "flags", &scenarioVolumetricLightShaftSettingsFlags },
		FIELD_PAD("pad the byte flag", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_real_vector_3d, "source direction" },
		{ _field_real_rgb_color, "shaft color tint" },
		{ _field_real, "exposure level" },
		{ _field_real, "decay" },
		{ _field_terminator }
	};

	#define SCENARIOFLOATINGSHADOWSETTINGSSTRUCT_ID { 0x1F09F99A, 0x3F304C08, 0xA8530F29, 0xAA552F0A }
	TAG_STRUCT(
		scenarioFloatingShadowSettingsStruct,
		"scenarioFloatingShadowSettingsStruct",
		"scenarioFloatingShadowSettings",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_POSTPROCESS_RECURSIVELY | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIOFLOATINGSHADOWSETTINGSSTRUCT_ID)
	{
		{ _field_byte_integer, "number of cascades" },
		{ _field_byte_integer, "has been initialized" },
		{ _field_char_enum, "quality", &floatingShadowQualityDefinition },
		{ _field_char_enum, "resolution", &floatingShadowBufferResolution },
		{ _field_real, "static shadow sharpening" },
		{ _field_array, "frustums", FIELD_FLAG_READ_ONLY, &scenarioFloatingShadowCascadeSettingsArray_array },
		{ _field_terminator }
	};

	#define SCENARIO_LIGHTMAP_SETTING_STRUCT_ID { 0x125A33B6, 0x658D4812, 0x8893A3A8, 0x7953003D }
	TAG_STRUCT(
		scenario_lightmap_setting_struct,
		"scenario_lightmap_setting_struct",
		"scenario_lightmap_setting",
		SET_POSTPROCESS_RECURSIVELY | SET_IS_MEMCPYABLE | SET_UNKNOWN15 | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_LIGHTMAP_SETTING_STRUCT_ID)
	{
		FIELD_EXPLANATION("Lightmap resolution for each buckets", nullptr, FIELD_FLAG_NONE, "relative to world unit per texel. default:\n1-> 1\n2-> 4\n2-> 16\n3-> 64\n5-> 128\n6-> 256\n7-> 512"),
		{ _field_real, "lightmap res lowest" },
		{ _field_real, "lightmap res 2nd low" },
		{ _field_real, "lightmap res 3rd low" },
		{ _field_real, "lightmap res medium" },
		{ _field_real, "lightmap res 3rd high" },
		{ _field_real, "lightmap res 2nd high" },
		{ _field_real, "lightmap res highest" },
		{ _field_byte_flags, "lightmap flags", &scenario_lightmap_per_bsp_flags },
		FIELD_PAD("pad the byte flag", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_real, "analytical light bounce modifier (when per bsp flag is on)" },
		{ _field_real, "non analytical light bounce modifier (when per bsp flag is on)" },
		{ _field_long_block_flags, "extra lighting bsp flags", "neighbor bsp that occlude or contribute light (including bounce light)", &scenario_structure_bsp_reference_block },
		{ _field_terminator }
	};

	#define MANUALBSPFLAGSREFERENCES_ID { 0x749519ED, 0x976649C5, 0x93B9867B, 0x7A6FAAF2 }
	TAG_STRUCT(
		manualBspFlagsReferences,
		"manualBspFlagsReferences",
		"ManualBspReferenceFlags",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		MANUALBSPFLAGSREFERENCES_ID)
	{
		FIELD_CUSTOM("manual bsp flags", nullptr, FIELD_FLAG_NONE, _field_id_manual_bsp_flags),
		{ _field_block, "references block", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &scenarioBspReferenceBlock_block },
		{ _field_long_integer, "flags", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define SCENARIO_TRIGGER_VOLUME_STRUCT_ID { 0xBF59DB68, 0x05A9439E, 0x811C3B2F, 0xADE31F09 }
	TAG_STRUCT(
		scenario_trigger_volume_struct,
		"scenario_trigger_volume_struct",
		"scenario_trigger_volume_struct",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_WRITEABLE),
		SCENARIO_TRIGGER_VOLUME_STRUCT_ID)
	{
		FIELD_EXPLANATION("naming", nullptr, FIELD_FLAG_NONE, "the name of the trigger volume specifies what kind of volume it is:\n\'zone_set:\'\n\'begin_zone_set:\'\n\'kill\' (plus \'_soft\' for soft kill volume)\n\'playerkill\' (plus \'_soft\' for soft kill volume) for player only kill volume \n\'safe_zone\' (plus \'_soft\' for soft kill volume)\n\'location_\'\n\'ordnance_bounds\'\n\'unsafe_spawn\'\nappend \':*\' to zone set names to allow vehicles to teleport along with their players."),
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_short_block_index, "object name", &scenario_object_names_block },
		{ _field_short_integer, "runtime node index", FIELD_FLAG_UNKNOWN0 },
		{ _field_string_id, "node name" },
		{ _field_enum, "type", &trigger_volume_type_enum },
		FIELD_PAD("padding", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real_vector_3d, "forward", FIELD_FLAG_UNKNOWN0 },
		{ _field_real_vector_3d, "up", FIELD_FLAG_UNKNOWN0 },
		{ _field_real_point_3d, "position" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_custom_long_block_index, "packedKeyOffaceref", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_UNKNOWN3 },
		{ _field_custom_long_block_index, "navMeshUIDOffaceref", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_UNKNOWN3 },

		{ _field_real_point_3d, "extents" },
		{ _field_real, "z sink", "this is only valid for sector type trigger volumes" },
		{ _field_block, "sector points", &trigger_volume_point_block },
		{ _field_block, "runtime triangles", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &trigger_volume_runtime_triangles_block },
		{ _field_real, "runtime sector bounds x0", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real, "runtime sector bounds x1", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real, "runtime sector bounds y0", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real, "runtime sector bounds y1", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real, "runtime sector bounds z0", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real, "runtime sector bounds z1", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real, "C", FIELD_FLAG_UNKNOWN0 },
		{ _field_short_block_index, "kill trigger volume", FIELD_FLAG_READ_ONLY, &scenario_kill_trigger_volumes_block },
		{ _field_short_block_index, "editor folder", FIELD_FLAG_UNKNOWN0, &g_scenario_editor_folder_block, _field_id_hide },
		{ _field_terminator }
	};

	#define SCENARIOUNITRECORDINGBLOCK_STRUCT_ID { 0x076AC662, 0x1CCA4061, 0x800A10D5, 0x3522A841 }
	TAG_STRUCT(
		ScenarioUnitRecordingBlock_struct,
		"ScenarioUnitRecordingBlock_struct",
		"ScenarioUnitRecording",
		SET_UNKNOWN0 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_UNKNOWN8 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIOUNITRECORDINGBLOCK_STRUCT_ID)
	{
		{ _field_string, "name", FIELD_FLAG_INDEX },
		{ _field_long_integer, "sampling rate" },
		{ _field_long_integer, "num samples", FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "Unit Recording version", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_data, "Unit Recording Data", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	STRINGS(function_bounds_mode_enum)
	{
		"clip",
		"clip and normalize",
		"scale to fit"
	};
	STRING_LIST(function_bounds_mode_enum, function_bounds_mode_enum_strings, _countof(function_bounds_mode_enum_strings));

	STRINGS(scenario_function_flags)
	{
		"scripted#the level script will set this value; the other settings here will be ignored.",
		"invert#result of function is one minus actual result",
		"additive",
		"always active#function does not deactivate when at or below lower bound"
	};
	STRING_LIST(scenario_function_flags, scenario_function_flags_strings, _countof(scenario_function_flags_strings));

	STRINGS(scenario_soft_ceiling_flags_definition)
	{
		"ignore bipeds",
		"ignore vehicles",
		"ignore camera",
		"ignore huge vehicles"
	};
	STRING_LIST(scenario_soft_ceiling_flags_definition, scenario_soft_ceiling_flags_definition_strings, _countof(scenario_soft_ceiling_flags_definition_strings));

	STRINGS(scenario_player_flags)
	{
		"survival mode",
		"survival mode elite"
	};
	STRING_LIST(scenario_player_flags, scenario_player_flags_strings, _countof(scenario_player_flags_strings));

	STRINGS(kill_volume_flags)
	{
		"don\'t kill immediately",
		"only kill players"
	};
	STRING_LIST(kill_volume_flags, kill_volume_flags_strings, _countof(kill_volume_flags_strings));

	STRINGS(scenario_requisition_trigger_volume_flags_definition)
	{
		"defender can buy",
		"attacker can buy",
		"can buy weapons",
		"can buy equipment",
		"can buy vehicles",
		"can buy custom apps"
	};
	STRING_LIST(scenario_requisition_trigger_volume_flags_definition, scenario_requisition_trigger_volume_flags_definition_strings, _countof(scenario_requisition_trigger_volume_flags_definition_strings));

	STRINGS(trigger_volume_type_enum)
	{
		"bounding box",
		"sector"
	};
	STRING_LIST(trigger_volume_type_enum, trigger_volume_type_enum_strings, _countof(trigger_volume_type_enum_strings));

	STRINGS(scenario_zone_set_switch_trigger_volume_flags_definition)
	{
		"teleport vehicles"
	};
	STRING_LIST(scenario_zone_set_switch_trigger_volume_flags_definition, scenario_zone_set_switch_trigger_volume_flags_definition_strings, _countof(scenario_zone_set_switch_trigger_volume_flags_definition_strings));

	STRINGS(scenario_zone_set_pvs_flags)
	{
		"empty debug pvs*!"
	};
	STRING_LIST(scenario_zone_set_pvs_flags, scenario_zone_set_pvs_flags_strings, _countof(scenario_zone_set_pvs_flags_strings));

	STRINGS(scenario_zone_set_flags_definition)
	{
		"begin loading next level",
		"debug purposes only",
		"interal zone set*!",
		"disable sky clearing",
		"override sky clear color"
	};
	STRING_LIST(scenario_zone_set_flags_definition, scenario_zone_set_flags_definition_strings, _countof(scenario_zone_set_flags_definition_strings));

	STRINGS(scenario_structure_size_enum)
	{
		"32x32",
		"64x64",
		"128x128",
		"256x256 - 0.4 Meg{0.3Meg_256x256}",
		"512x512 - 1.5 Meg{1Meg_512x512}",
		"768x768 - 3.4 Meg{2.25Meg_768x768}",
		"1024x1024 - 6 Meg{4Meg_1024x1024}",
		"1280x1280 - 9.4 Meg{6.3Meg_1280x1280}",
		"1536x1536 - 13.5 Meg{9Meg_1536x1536}",
		"1792x1792 - 18.4Meg{12.3Meg_1792x1792}"
	};
	STRING_LIST(scenario_structure_size_enum, scenario_structure_size_enum_strings, _countof(scenario_structure_size_enum_strings));

	STRINGS(scenario_structure_refinement_size_enum)
	{
		" 4.0 Meg (Default)",
		" 1.0 Meg",
		" 2.0 Meg",
		" 6.0 Meg"
	};
	STRING_LIST(scenario_structure_refinement_size_enum, scenario_structure_refinement_size_enum_strings, _countof(scenario_structure_refinement_size_enum_strings));

	STRINGS(scenario_structure_bsp_reference_flags_definition)
	{
		"default sky enabled!",
		"per vertex only lightmap",
		"never lightmap",
		"generate fake small lightmaps",
		"ray trace adjacent bsps on sky hits",
		"lightmaps use conservative subcharts",
		"lightmaps reduce stretch hack",
		"lightmaps use extended gathering (very slow)",
		"lightmaps final gather ignores backfacing hits",
		"not a normally playable space in an MP map (check this on shared BSPs)",
		"shared bsp",
		"dont use extra lighting bsps for cubemaps",
		"custom gravity scale",
		"disable streaming subregions",
		"do not desaturate decorators",
		"make all shadows blob"
	};
	STRING_LIST(scenario_structure_bsp_reference_flags_definition, scenario_structure_bsp_reference_flags_definition_strings, _countof(scenario_structure_bsp_reference_flags_definition_strings));

	STRINGS(scenarioVolumetricLightShaftSettingsFlags)
	{
		"enable volumetric light shafts for this BSP"
	};
	STRING_LIST(scenarioVolumetricLightShaftSettingsFlags, scenarioVolumetricLightShaftSettingsFlags_strings, _countof(scenarioVolumetricLightShaftSettingsFlags_strings));

	STRINGS(floatingShadowQualityDefinition)
	{
		"8 tap",
		"12 tap",
		"6 tap"
	};
	STRING_LIST(floatingShadowQualityDefinition, floatingShadowQualityDefinition_strings, _countof(floatingShadowQualityDefinition_strings));

	STRINGS(floatingShadowBufferResolution)
	{
		"512x512",
		"800x800"
	};
	STRING_LIST(floatingShadowBufferResolution, floatingShadowBufferResolution_strings, _countof(floatingShadowBufferResolution_strings));

	STRINGS(scenario_lightmap_per_bsp_flags)
	{
		"analytical bounce uses per bsp setting"
	};
	STRING_LIST(scenario_lightmap_per_bsp_flags, scenario_lightmap_per_bsp_flags_strings, _countof(scenario_lightmap_per_bsp_flags_strings));

	STRINGS(scenario_performance_actor_flags_definition)
	{
		"actor is critical"
	};
	STRING_LIST(scenario_performance_actor_flags_definition, scenario_performance_actor_flags_definition_strings, _countof(scenario_performance_actor_flags_definition_strings));

	STRINGS(scenario_performance_line_animation_flags_definition)
	{
		"Loop",
		"Loop until task transition",
		"Die on animation completion"
	};
	STRING_LIST(scenario_performance_line_animation_flags_definition, scenario_performance_line_animation_flags_definition_strings, _countof(scenario_performance_line_animation_flags_definition_strings));

	STRINGS(scenario_performance_line_sync_action_flag_type_definition)
	{
		"Share initiator stance",
		"Initiator is origin"
	};
	STRING_LIST(scenario_performance_line_sync_action_flag_type_definition, scenario_performance_line_sync_action_flag_type_definition_strings, _countof(scenario_performance_line_sync_action_flag_type_definition_strings));

	STRINGS(scenario_performance_line_scenery_sync_action_flag_type_definition)
	{
		"Share initiator stance"
	};
	STRING_LIST(scenario_performance_line_scenery_sync_action_flag_type_definition, scenario_performance_line_scenery_sync_action_flag_type_definition_strings, _countof(scenario_performance_line_scenery_sync_action_flag_type_definition_strings));

	STRINGS(scenario_performance_fragment_placement_definition)
	{
		"Pre-Line",
		"Post-Line"
	};
	STRING_LIST(scenario_performance_fragment_placement_definition, scenario_performance_fragment_placement_definition_strings, _countof(scenario_performance_fragment_placement_definition_strings));

	STRINGS(scenario_performance_fragment_type_definition)
	{
		"Default",
		"Conditional Sleep",
		"Branch"
	};
	STRING_LIST(scenario_performance_fragment_type_definition, scenario_performance_fragment_type_definition_strings, _countof(scenario_performance_fragment_type_definition_strings));

	STRINGS(scenario_performance_line_point_interaction_type_definition)
	{
		"Face point",
		"Aim at point",
		"Look at point",
		"Shoot at point",
		"Go by point",
		"Go to point",
		"Go to and align",
		"Go to thespian center",
		"Teleport to point"
	};
	STRING_LIST(scenario_performance_line_point_interaction_type_definition, scenario_performance_line_point_interaction_type_definition_strings, _countof(scenario_performance_line_point_interaction_type_definition_strings));

	STRINGS(scenario_performance_line_progress_definition)
	{
		"Immediate (play)",
		"Block until all done",
		"Block until line done",
		"Queue blocking",
		"Queue immediate"
	};
	STRING_LIST(scenario_performance_line_progress_definition, scenario_performance_line_progress_definition_strings, _countof(scenario_performance_line_progress_definition_strings));

	STRINGS(scenario_performance_line_flags)
	{
		"Disable"
	};
	STRING_LIST(scenario_performance_line_flags, scenario_performance_line_flags_strings, _countof(scenario_performance_line_flags_strings));

	STRINGS(performance_flags)
	{
		"not initially placed",
		"allow replay",
		"infinite radius",
		"actors in search"
	};
	STRING_LIST(performance_flags, performance_flags_strings, _countof(performance_flags_strings));

	STRINGS(decal_placement_flags)
	{
		"force planar#force decal to be 2 triangle quad.  does not clip to geometry"
	};
	STRING_LIST(decal_placement_flags, decal_placement_flags_strings, _countof(decal_placement_flags_strings));

	STRINGS(editor_comment_type_enum_definition)
	{
		"generic"
	};
	STRING_LIST(editor_comment_type_enum_definition, editor_comment_type_enum_definition_strings, _countof(editor_comment_type_enum_definition_strings));

	STRINGS(scenario_type_enum)
	{
		"solo",
		"multiplayer",
		"main menu",
		"multiplayer shared",
		"single player shared"
	};
	STRING_LIST(scenario_type_enum, scenario_type_enum_strings, _countof(scenario_type_enum_strings));

	STRINGS(scenario_flags)
	{
		"always draw sky!#always draw sky 0, even if no +sky polygons are visible",
		"don\'t strip pathfinding#always leave pathfinding in, even for a multiplayer scenario",
		"symmetric multiplayer map!",
		"quick loading (cinematic only) scenario",
		"characters use previous mission weapons",
		"lightmaps smooth palettes with neighbors!",
		"snap to white at start",
		"override globals!",
		"big vehicle use center point for light sampling!",
		"don\'t use campaign sharing",
		"ignore size and can\'t ship",
		"always run lightmaps per-bsp",
		"in space#so we can hide hud elements like the compass",
		"survival#so we can strip the elite from the global player representations",
		"do not strip variants#so we can test the impact of variant stripping"
	};
	STRING_LIST(scenario_flags, scenario_flags_strings, _countof(scenario_flags_strings));

	STRINGS(scenario_runtime_trigger_volume_flags)
	{
		"has hard safe volume!*",
		"has soft safe volume!*"
	};
	STRING_LIST(scenario_runtime_trigger_volume_flags, scenario_runtime_trigger_volume_flags_strings, _countof(scenario_runtime_trigger_volume_flags_strings));

	STRINGS(camera_fx_palette_flags)
	{
		"force exposure",
		"force auto-exposure",
		"override exposure bounds",
		"override inherent bloom",
		"override bloom intensity"
	};
	STRING_LIST(camera_fx_palette_flags, camera_fx_palette_flags_strings, _countof(camera_fx_palette_flags_strings));

	STRINGS(ordnance_flags)
	{
		"suppress incident fanfare ui"
	};
	STRING_LIST(ordnance_flags, ordnance_flags_strings, _countof(ordnance_flags_strings));

	STRINGS(ordnance_dropset_flags)
	{
		"initial drop#will be used for initial drops",
		"player drop#will be used for personal drops",
		"random drop#will be used for random drops",
		"objective drop#will be used for objective-based drops"
	};
	STRING_LIST(ordnance_dropset_flags, ordnance_dropset_flags_strings, _countof(ordnance_dropset_flags_strings));

	STRINGS(multiplayer_map_size_enum)
	{
		"small",
		"medium",
		"large"
	};
	STRING_LIST(multiplayer_map_size_enum, multiplayer_map_size_enum_strings, _countof(multiplayer_map_size_enum_strings));

} // namespace macaque

} // namespace blofeld

