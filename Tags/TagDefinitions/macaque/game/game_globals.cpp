#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		globals_group,
		GLOBALS_TAG,
		nullptr,
		INVALID_TAG,
		globals_block );

	TAG_GROUP(
		patch_globals_group,
		PATCH_GLOBALS_TAG,
		nullptr,
		INVALID_TAG,
		patch_globals_block );

	TAG_BLOCK_FROM_STRUCT(
		globals_block,
		"globals_block",
		1,
		globals_struct_definition);

	TAG_BLOCK_FROM_STRUCT(
		patch_globals_block,
		"patch_globals_block",
		1,
		patch_globals_struct_definition);

	#define HAVOK_CLEANUP_RESOURCES_BLOCK_ID { 0x1158B5B8, 0xFBFC4D5A, 0xB4862259, 0xCB91EB7B }
	TAG_BLOCK(
		havok_cleanup_resources_block,
		"havok_cleanup_resources_block",
		1,
		"s_game_globals_havok_cleanup_resources",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		HAVOK_CLEANUP_RESOURCES_BLOCK_ID)
	{
		{ _field_tag_reference, "object cleanup effect", &global_effect_reference },
		{ _field_terminator }
	};

	#define SOUND_BLOCK_ID { 0xBAB7A89B, 0xDFC743D6, 0xB8895623, 0xEBA18D33 }
	TAG_BLOCK(
		sound_block$2_block,
		"sound_block",
		NUMBER_OF_GLOBAL_SOUNDS,
		"s_tag_reference",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SOUND_BLOCK_ID)
	{
		{ _field_tag_reference, "sound (OBSOLETE)", &sound_block_sound_OBSOLETE_reference },
		{ _field_terminator }
	};

	#define SOFT_CEILING_GLOBALS_BLOCK_ID { 0x64E57956, 0x36734BA7, 0x83B6CF77, 0xDA4FEAED }
	TAG_BLOCK(
		soft_ceiling_globals_block,
		"soft_ceiling_globals_block",
		1,
		"s_game_globals_soft_ceiling",
		SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_POSTPROCESS_RECURSIVELY | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SOFT_CEILING_GLOBALS_BLOCK_ID)
	{
		{ _field_real, "biped spring constant" },
		{ _field_real, "biped normal damping" },
		{ _field_real, "biped tangent damping" },
		{ _field_real, "biped min tangent damp velocity" },
		{ _field_real, "vehicle spring constant" },
		{ _field_real, "vehicle normal damping" },
		{ _field_real, "vehicle tangent damping" },
		{ _field_terminator }
	};

	#define CHEAT_WEAPONS_BLOCK_ID { 0xD13CBBE7, 0x9DEC4ED6, 0x983BA69C, 0x9D39AE04 }
	TAG_BLOCK(
		cheat_weapons_block,
		"cheat_weapons_block",
		20,
		"s_game_globals_tag_reference",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CHEAT_WEAPONS_BLOCK_ID)
	{
		{ _field_tag_reference, "weapon", FIELD_FLAG_INDEX, &global_item_reference },
		{ _field_terminator }
	};

	#define CHEAT_POWERUPS_BLOCK_ID { 0x60B57D08, 0xF45F431C, 0xBCFF4793, 0x3C28C018 }
	TAG_BLOCK(
		cheat_powerups_block,
		"cheat_powerups_block",
		20,
		"s_game_globals_tag_reference",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CHEAT_POWERUPS_BLOCK_ID)
	{
		{ _field_tag_reference, "powerup", FIELD_FLAG_INDEX, &global_equipment_reference },
		{ _field_terminator }
	};

	#define MULTIPLAYER_COLOR_BLOCK_ID { 0x0A6C9756, 0xF0E24866, 0xA708F3E9, 0xC9C41962 }
	TAG_BLOCK(
		multiplayer_color_block,
		"multiplayer_color_block",
		k_player_color_index_count,
		"real_rgb_color",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		MULTIPLAYER_COLOR_BLOCK_ID)
	{
		{ _field_real_rgb_color, "color" },
		{ _field_terminator }
	};

	#define VISOR_COLOR_BLOCK_ID { 0x91C73AC2, 0x84F247BD, 0x933B0BAD, 0x26DB133B }
	TAG_BLOCK(
		visor_color_block,
		"visor_color_block",
		32,
		"s_multiplayer_visor_color",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		VISOR_COLOR_BLOCK_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_real_rgb_color, "tertiary color" },
		{ _field_real_rgb_color, "quaternary color" },
		{ _field_terminator }
	};

	TAG_REFERENCE(haloreach_unknown_globals_reference);

	V5_TAG_BLOCK(grenade_globals_block, k_grenade_globals_count)
	{
		{ _field_legacy, _field_short_integer, "maximum count" },
		{ _field_legacy, _field_pad, "pad@", 2 },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_tag_reference, "throwing effect", &global_effect_reference },
		{ _field_legacy, _field_tag_reference, "equipment", &global_equipment_reference },
		{ _field_legacy, _field_tag_reference, "projectile", &projectile_reference },
		{ _field_legacy, _field_terminator }
	};

	#define GLOBALS_STRUCT_DEFINITION_ID { 0x08DE77CB, 0xA2CF4145, 0xBB807A30, 0xB2A866B3 }
	TAG_STRUCT(
		globals_struct_definition,
		"globals_struct_definition",
		"s_game_globals",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | 
		SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_WRITEABLE | TAG_MEMORY_USAGE_NON_ALIASED),
		GLOBALS_STRUCT_DEFINITION_ID)
	{
		FIELD_PAD("YJLTWDSL", nullptr, FIELD_FLAG_NONE, 172),
		{ _field_long_enum, "language", &language_enum },
		{ _field_block, "havok cleanup resources", &havok_cleanup_resources_block },
		{ _field_block, "sound globals", &sound_globals_block },
		FIELD_EXPLANATION("AI globals", nullptr, FIELD_FLAG_NONE, "I have moved the ai globals out of this tag, and into its own tag which is referenced here."),
		{ _field_block, "DEPRECATED", MAKE_OLD_NAMES("ai globals"), FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &ai_globals_data_block, _field_id_slap },
		{ _field_tag_reference, "ai globals ref", &ai_globals_reference },
		{ _field_block, "damage table", &game_globals_damage_block },

		{ _field_legacy, _field_version_equal, _engine_type_haloreach },
		{ _field_legacy, _field_tag_reference, "unknown@", &haloreach_unknown_globals_reference },

		{ _field_block, "sounds", &sound_block$2_block },
		{ _field_block, "camera", &camera_block },
		{ _field_block, "controller input", &controller_input_block },
		{ _field_block, "player control", &player_control_block },
		{ _field_block, "default player traits", &game_engine_player_traits_block },
		{ _field_block, "difficulty", &difficulty_block },
		{ _field_block, "co-op difficulty", &coop_difficulty_block },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_block, "grenades", &grenade_globals_block_block },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },// probably an unused tagblock
		{ _field_block, "soft ceilings", &soft_ceiling_globals_block },
			// #TODO: definitions yeah this is fucking wrong
		{ _field_legacy, _field_pad, "pad", 4 * 3 },
		{ _field_block, "interface tags", &interface_tag_references_block },
		{ _field_block, "@weapon list (update _weapon_list enum in game_globals.h)", &cheat_weapons_block },
		{ _field_block, "@cheat powerups", &cheat_powerups_block },
		{ _field_block, "@player information", &player_information_block },
		{ _field_block, "@player representation", &player_representation_block },
		{ _field_block, "damage", MAKE_OLD_NAMES("falling damage"), &damage_globals_block },
		{ _field_block, "shield boost", &shield_boost_block },
		{ _field_block, "materials", &materials_block$3_block, _field_id_sort },
		{ _field_block, "profile colors", &multiplayer_color_block },
		{ _field_block, "emblem colors", &multiplayer_color_block },
		{ _field_block, "visor colors", &visor_color_block },
		FIELD_CUSTOM("Elite specular colors", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_struct, "elite specular color", &elite_specular_color_struct },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_tag_reference, "forge globals", &forge_globals_reference },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_block, "forge globals", &forge_color_block },

		{ _field_tag_reference, "game engine globals", &game_engine_globals_reference },
		{ _field_tag_reference, "multiplayer globals", &multiplayer_globals_reference },
		{ _field_tag_reference, "survival_mode globals", &survival_mode_globals_reference },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_tag_reference, "firefight globals", &firefight_globals_reference },

		{ _field_tag_reference, "global multiplayer object type list", &global_multiplayer_object_type_list_reference },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 4 },
		{ _field_tag_reference, "custom app globals", &global_custom_app_globals_reference },
		{ _field_tag_reference, "grenades", &Tag::Reference<struct GameGlobalsGrenadeList>::s_defaultDefinition },
		{ _field_tag_reference, "ordnances", &Tag::Reference<struct GameGlobalsOrdnance>::s_defaultDefinition },
		{ _field_tag_reference, "silent assist", &Tag::Reference<struct SilentAssistGlobals>::s_defaultDefinition },

		{ _field_block, "cinematics globals", &cinematics_globals_block },
		{ _field_block, "campaign metagame globals", &campaign_metagame_globals_block },
		{ _field_tag_reference, "game medal globals", &game_medal_globals_reference },
		{ _field_struct, "language pack1", FIELD_FLAG_UNKNOWN0, &language_pack_definition },
		{ _field_struct, "language pack2", FIELD_FLAG_UNKNOWN0, &language_pack_definition },
		{ _field_struct, "language pack3", FIELD_FLAG_UNKNOWN0, &language_pack_definition },
		{ _field_struct, "language pack4", FIELD_FLAG_UNKNOWN0, &language_pack_definition },
		{ _field_struct, "language pack5", FIELD_FLAG_UNKNOWN0, &language_pack_definition },
		{ _field_struct, "language pack6", FIELD_FLAG_UNKNOWN0, &language_pack_definition },
		{ _field_struct, "language pack7", FIELD_FLAG_UNKNOWN0, &language_pack_definition },
		{ _field_struct, "language pack8", FIELD_FLAG_UNKNOWN0, &language_pack_definition },
		{ _field_struct, "language pack9", FIELD_FLAG_UNKNOWN0, &language_pack_definition },
		{ _field_struct, "language pack10", FIELD_FLAG_UNKNOWN0, &language_pack_definition },
		{ _field_struct, "language pack11", FIELD_FLAG_UNKNOWN0, &language_pack_definition },
		{ _field_struct, "language pack12", FIELD_FLAG_UNKNOWN0, &language_pack_definition },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 5 },
		{ _field_struct, "language pack13", FIELD_FLAG_UNKNOWN0, &language_pack_definition },
		{ _field_struct, "language pack14", FIELD_FLAG_UNKNOWN0, &language_pack_definition },
		{ _field_struct, "language pack15", FIELD_FLAG_UNKNOWN0, &language_pack_definition },
		{ _field_struct, "language pack16", FIELD_FLAG_UNKNOWN0, &language_pack_definition },
		{ _field_struct, "language pack17", FIELD_FLAG_UNKNOWN0, &language_pack_definition },

		FIELD_EXPLANATION("Rasterizer globals", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_tag_reference, "rasterizer_globals_ref", &global_rasterizer_globals_reference },
		FIELD_EXPLANATION("Default camera fx settings", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_tag_reference, "default camera fx settings", &global_camera_fx_settings_reference },
		FIELD_EXPLANATION("Default wind settings", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_tag_reference, "default wind settings", &global_wind_reference },
		FIELD_EXPLANATION("Weather globals", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_tag_reference, "weather globals", &global_weather_globals_reference },
		FIELD_EXPLANATION("Default collision damage", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_tag_reference, "collision damage effect", &global_damage_reference },
		{ _field_tag_reference, "collision damage", &collision_damage_reference$5 },
		FIELD_EXPLANATION("global material types", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_string_id, "global water material", "the default value for what material type water is" },
		{ _field_string_id, "global air material", "the default value for what material type air is" },
		{ _field_short_integer, "global water material type", FIELD_FLAG_UNKNOWN0 },
		{ _field_short_integer, "global air material type", FIELD_FLAG_UNKNOWN0 },
		{ _field_tag_reference, "effect globals", &global_effect_globals_reference },
		{ _field_tag_reference, "havok collision filter", &havok_collision_filter_reference },
		{ _field_tag_reference, "default item grounded friction", &global_grounded_friction_reference },
		{ _field_block, "active camo", &active_camo_globals_block },
		{ _field_tag_reference, "incident global properties", &incident_global_properties_definition_reference },
		{ _field_tag_reference, "player grade globals", &player_grade_globals_definition_reference },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_tag_reference, "enlistment globals", &player_enlistment_globals_definition_reference },

		{ _field_tag_reference, "player model customization globals", &global_player_model_customization_globals_reference },
		{ _field_tag_reference, "loadout globals", &global_loadout_globals_reference },
		{ _field_tag_reference, "challenge globals", &challenge_globals_definition_reference },
		{ _field_tag_reference, "game completion rewards globals", &game_completion_rewards_globals_reference },
		{ _field_tag_reference, "game achievements", &achievements_reference },
		{ _field_tag_reference, "game avatar awards", &avatar_awards_reference },
		{ _field_tag_reference, "game performance thortles default", &game_performance_throttle_reference },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_tag_reference, "armormod globals", &armormod_globals_reference },
		{ _field_tag_reference, "progression globals", &global_progression_reference },

		{ _field_block, "garbage collection", &garbage_collection_block, _field_id_slap },
		{ _field_block, "camera impulse", &global_camera_impulse_block },
		{ _field_block, "runtime materials", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &runtime_materials_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_block, "Hologram Lighting", &hologramLightingGlobalsBlock_block },
		{ _field_tag_reference, "Narrative globals", &NarrativeGlobalsReference },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_long_integer, "unknown@" },

		{ _field_terminator }
	};

	#define PATCH_GLOBALS_STRUCT_DEFINITION_ID { 0x61508392, 0x3EAD42E3, 0x8EC54AE9, 0xD301A46B }
	TAG_STRUCT(
		patch_globals_struct_definition,
		"patch_globals_struct_definition",
		"PatchGlobals",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_WRITEABLE | TAG_MEMORY_USAGE_NON_ALIASED),
		PATCH_GLOBALS_STRUCT_DEFINITION_ID)
	{
		{ _field_struct, "language pack1", FIELD_FLAG_UNKNOWN0, &language_pack_definition },
		{ _field_struct, "language pack2", FIELD_FLAG_UNKNOWN0, &language_pack_definition },
		{ _field_struct, "language pack3", FIELD_FLAG_UNKNOWN0, &language_pack_definition },
		{ _field_struct, "language pack4", FIELD_FLAG_UNKNOWN0, &language_pack_definition },
		{ _field_struct, "language pack5", FIELD_FLAG_UNKNOWN0, &language_pack_definition },
		{ _field_struct, "language pack6", FIELD_FLAG_UNKNOWN0, &language_pack_definition },
		{ _field_struct, "language pack7", FIELD_FLAG_UNKNOWN0, &language_pack_definition },
		{ _field_struct, "language pack8", FIELD_FLAG_UNKNOWN0, &language_pack_definition },
		{ _field_struct, "language pack9", FIELD_FLAG_UNKNOWN0, &language_pack_definition },
		{ _field_struct, "language pack10", FIELD_FLAG_UNKNOWN0, &language_pack_definition },
		{ _field_struct, "language pack11", FIELD_FLAG_UNKNOWN0, &language_pack_definition },
		{ _field_struct, "language pack12", FIELD_FLAG_UNKNOWN0, &language_pack_definition },
		{ _field_struct, "language pack13", FIELD_FLAG_UNKNOWN0, &language_pack_definition },
		{ _field_struct, "language pack14", FIELD_FLAG_UNKNOWN0, &language_pack_definition },
		{ _field_struct, "language pack15", FIELD_FLAG_UNKNOWN0, &language_pack_definition },
		{ _field_struct, "language pack16", FIELD_FLAG_UNKNOWN0, &language_pack_definition },
		{ _field_struct, "language pack17", FIELD_FLAG_UNKNOWN0, &language_pack_definition },
		{ _field_terminator }
	};

	#define ELITE_SPECULAR_COLOR_STRUCT_ID { 0x19358444, 0x61AC41D0, 0x8B134E19, 0x26C63A1B }
	TAG_STRUCT(
		elite_specular_color_struct,
		"elite_specular_color_struct",
		"s_elite_specular_color",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		ELITE_SPECULAR_COLOR_STRUCT_ID)
	{
		{ _field_real_rgb_color, "tertiary color" },
		{ _field_real_rgb_color, "quaternary color" },
		{ _field_terminator }
	};

	STRINGS(language_enum)
	{
		"english",
		"japanese",
		"german",
		"french",
		"spanish",
		"mexican spanish",
		"italian",
		"korean",
		"chinese-traditional",
		"chinese-simplified",
		"portuguese",
		"polish",
		"russian",
		"danish",
		"finnish",
		"dutch",
		"norwegian"
	};
	STRING_LIST(language_enum, language_enum_strings, _countof(language_enum_strings));

} // namespace macaque

} // namespace blofeld

