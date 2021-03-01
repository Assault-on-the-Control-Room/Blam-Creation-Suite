#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_GROUP_FROM_BLOCK(globals, GLOBALS_TAG, globals_block_block );

	V5_TAG_GROUP_FROM_BLOCK(patch_globals, PATCH_GLOBALS_TAG, patch_globals_block_block );

	V5_TAG_BLOCK(havok_cleanup_resources_block, 1)
	{
		{ _field_legacy, _field_tag_reference, "object cleanup effect", &global_effect_reference },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(sound_block, NUMBER_OF_GLOBAL_SOUNDS)
	{
		{ _field_legacy, _field_tag_reference, "sound (OBSOLETE)", &sound_block_sound_OBSOLETE_reference },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(soft_ceiling_globals_block, 1)
	{
		{ _field_legacy, _field_real, "biped spring constant" },
		{ _field_legacy, _field_real, "biped normal damping" },
		{ _field_legacy, _field_real, "biped tangent damping" },
		{ _field_legacy, _field_real, "biped min tangent damp velocity" },
		{ _field_legacy, _field_real, "vehicle spring constant" },
		{ _field_legacy, _field_real, "vehicle normal damping" },
		{ _field_legacy, _field_real, "vehicle tangent damping" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(cheat_weapons_block, 20)
	{
		{ _field_legacy, _field_tag_reference, "weapon^", &global_item_reference },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(cheat_powerups_block, 20)
	{
		{ _field_legacy, _field_tag_reference, "powerup^", &global_equipment_reference },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(multiplayer_color_block, k_player_color_index_count)
	{
		{ _field_legacy, _field_real_rgb_color, "color" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(visor_color_block, 32)
	{
		{ _field_legacy, _field_string_id, "name^" },
		{ _field_legacy, _field_real_rgb_color, "tertiary color" },
		{ _field_legacy, _field_real_rgb_color, "quaternary color" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK_FROM_STRUCT(globals_block, 1, globals_struct_definition_struct_definition );

	V5_TAG_BLOCK_FROM_STRUCT(patch_globals_block, 1, patch_globals_struct_definition_struct_definition );

	TAG_REFERENCE(haloreach_unknown_globals_reference);

	V5_TAG_STRUCT(globals_struct_definition)
	{
		{ _field_legacy, _field_pad, "YJLTWDSL", 172 },
		{ _field_legacy, _field_long_enum, "language", &language_enum },
		{ _field_legacy, _field_block, "havok cleanup resources", &havok_cleanup_resources_block_block },
		{ _field_legacy, _field_block, "sound globals", &sound_globals_block_block },
		{ _field_legacy, _field_explanation, "AI globals", "I have moved the ai globals out of this tag, and into its own tag which is referenced here." },
		{ _field_legacy, _field_block, "DEPRECATED{ai globals}*!", &ai_globals_data_block_block },
		{ _field_legacy, _field_tag_reference, "ai globals ref", &ai_globals_reference },
		{ _field_legacy, _field_block, "damage table", &game_globals_damage_block_block },
		
		{ _field_legacy, _field_version_equal, _engine_type_haloreach },
		{ _field_legacy, _field_tag_reference, "unknown@", &haloreach_unknown_globals_reference },

		{ _field_legacy, _field_block, "sounds", &sound_block_block },
		{ _field_legacy, _field_block, "camera", &camera_block_block },
		{ _field_legacy, _field_block, "controller input", &controller_input_block_block },
		{ _field_legacy, _field_block, "player control", &player_control_block_block },
		{ _field_legacy, _field_block, "default player traits", &game_engine_player_traits_block_block },
		{ _field_legacy, _field_block, "difficulty", &difficulty_block_block },
		{ _field_legacy, _field_block, "co-op difficulty", &coop_difficulty_block_block },
		
		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_block, "grenades", &grenade_globals_block_block },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },// probably an unused tagblock
		{ _field_legacy, _field_block, "soft ceilings", &soft_ceiling_globals_block_block },

		{ _field_legacy, _field_pad, "pad", 4 * 3 },
		{ _field_legacy, _field_block, "interface tags", &interface_tag_references_block },
		{ _field_legacy, _field_block, "@weapon list (update _weapon_list enum in game_globals.h)", &cheat_weapons_block_block },
		{ _field_legacy, _field_block, "@cheat powerups", &cheat_powerups_block_block },
		{ _field_legacy, _field_block, "@player information", &player_information_block_block },
		{ _field_legacy, _field_block, "@player representation", &player_representation_block_block },
		{ _field_legacy, _field_block, "damage{falling damage}", &damage_globals_block_block },
		{ _field_legacy, _field_block, "shield boost", &shield_boost_block_block },
		{ _field_legacy, _field_block, "materials", &materials_block_block },
		{ _field_legacy, _field_block, "profile colors", &multiplayer_color_block_block },
		{ _field_legacy, _field_block, "emblem colors", &multiplayer_color_block_block },
		{ _field_legacy, _field_block, "visor colors", &visor_color_block_block },
		{ _field_legacy, _field_custom, "Elite specular colors" },
		{ _field_legacy, _field_struct, "elite specular color", &elite_specular_color_struct_struct_definition },
		{ _field_legacy, _field_custom },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_legacy, _field_tag_reference, "forge globals", &forge_globals_reference },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_block, "forge globals", &forge_color_block_block },

		{ _field_legacy, _field_tag_reference, "game engine globals", &game_engine_globals_reference },
		{ _field_legacy, _field_tag_reference, "multiplayer globals", &multiplayer_globals_reference },
		{ _field_legacy, _field_tag_reference, "survival_mode globals", &survival_mode_globals_reference },
		
		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_legacy, _field_tag_reference, "firefight globals", &firefight_globals_reference },

		{ _field_legacy, _field_tag_reference, "global multiplayer object type list", &global_multiplayer_object_type_list_reference },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 4 },
		{ _field_legacy, _field_tag_reference, "custom app globals", &global_custom_app_globals_reference },
		{ _field_legacy, _field_tag_reference, "grenades", &Tag::Reference<struct GameGlobalsGrenadeList>::s_defaultDefinition },
		{ _field_legacy, _field_tag_reference, "ordnances", &Tag::Reference<struct GameGlobalsOrdnance>::s_defaultDefinition },
		{ _field_legacy, _field_tag_reference, "silent assist", &Tag::Reference<struct SilentAssistGlobals>::s_defaultDefinition },

		{ _field_legacy, _field_block, "cinematics globals", &cinematics_globals_block_block },
		{ _field_legacy, _field_block, "campaign metagame globals", &campaign_metagame_globals_block_block },
		{ _field_legacy, _field_tag_reference, "game medal globals", &game_medal_globals_reference },
		{ _field_legacy, _field_struct, "language pack1!", &language_pack_definition_struct_definition },
		{ _field_legacy, _field_struct, "language pack2!", &language_pack_definition_struct_definition },
		{ _field_legacy, _field_struct, "language pack3!", &language_pack_definition_struct_definition },
		{ _field_legacy, _field_struct, "language pack4!", &language_pack_definition_struct_definition },
		{ _field_legacy, _field_struct, "language pack5!", &language_pack_definition_struct_definition },
		{ _field_legacy, _field_struct, "language pack6!", &language_pack_definition_struct_definition },
		{ _field_legacy, _field_struct, "language pack7!", &language_pack_definition_struct_definition },
		{ _field_legacy, _field_struct, "language pack8!", &language_pack_definition_struct_definition },
		{ _field_legacy, _field_struct, "language pack9!", &language_pack_definition_struct_definition },
		{ _field_legacy, _field_struct, "language pack10!", &language_pack_definition_struct_definition },
		{ _field_legacy, _field_struct, "language pack11!", &language_pack_definition_struct_definition },
		{ _field_legacy, _field_struct, "language pack12!", &language_pack_definition_struct_definition },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 5 },
		{ _field_legacy, _field_struct, "language pack13!", &language_pack_definition_struct_definition },
		{ _field_legacy, _field_struct, "language pack14!", &language_pack_definition_struct_definition },
		{ _field_legacy, _field_struct, "language pack15!", &language_pack_definition_struct_definition },
		{ _field_legacy, _field_struct, "language pack16!", &language_pack_definition_struct_definition },
		{ _field_legacy, _field_struct, "language pack17!", &language_pack_definition_struct_definition },

		{ _field_legacy, _field_explanation, "Rasterizer globals", "" },
		{ _field_legacy, _field_tag_reference, "rasterizer_globals_ref", &global_rasterizer_globals_reference },
		{ _field_legacy, _field_explanation, "Default camera fx settings", "" },
		{ _field_legacy, _field_tag_reference, "default camera fx settings", &global_camera_fx_settings_reference },
		{ _field_legacy, _field_explanation, "Default wind settings", "" },
		{ _field_legacy, _field_tag_reference, "default wind settings", &global_wind_reference },
		{ _field_legacy, _field_explanation, "Weather globals", "" },
		{ _field_legacy, _field_tag_reference, "weather globals", &global_weather_globals_reference },
		{ _field_legacy, _field_explanation, "Default collision damage", "" },
		{ _field_legacy, _field_tag_reference, "collision damage effect", &global_damage_reference },
		{ _field_legacy, _field_tag_reference, "collision damage", &collision_damage_reference$5 },
		{ _field_legacy, _field_explanation, "global material types", "" },
		{ _field_legacy, _field_string_id, "global water material#the default value for what material type water is" },
		{ _field_legacy, _field_string_id, "global air material#the default value for what material type air is" },
		{ _field_legacy, _field_short_integer, "global water material type!" },
		{ _field_legacy, _field_short_integer, "global air material type!" },
		{ _field_legacy, _field_tag_reference, "effect globals", &global_effect_globals_reference },
		{ _field_legacy, _field_tag_reference, "havok collision filter", &havok_collision_filter_reference },
		{ _field_legacy, _field_tag_reference, "default item grounded friction", &global_grounded_friction_reference },
		{ _field_legacy, _field_block, "active camo", &active_camo_globals_block_block },
		{ _field_legacy, _field_tag_reference, "incident global properties", &incident_global_properties_definition_reference },
		{ _field_legacy, _field_tag_reference, "player grade globals", &player_grade_globals_definition_reference },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_legacy, _field_tag_reference, "enlistment globals", &player_enlistment_globals_definition_reference },

		{ _field_legacy, _field_tag_reference, "player model customization globals", &global_player_model_customization_globals_reference },
		{ _field_legacy, _field_tag_reference, "loadout globals", &global_loadout_globals_reference },
		{ _field_legacy, _field_tag_reference, "challenge globals", &challenge_globals_definition_reference },
		{ _field_legacy, _field_tag_reference, "game completion rewards globals", &game_completion_rewards_globals_reference },
		{ _field_legacy, _field_tag_reference, "game achievements", &achievements_reference },
		{ _field_legacy, _field_tag_reference, "game avatar awards", &avatar_awards_reference },
		{ _field_legacy, _field_tag_reference, "game performance thortles default", &game_performance_throttle_reference },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_legacy, _field_tag_reference, "armormod globals", &armormod_globals_reference },
		{ _field_legacy, _field_tag_reference, "progression globals", &global_progression_reference },

		{ _field_legacy, _field_block, "garbage collection", &garbage_collection_block_block },
		{ _field_legacy, _field_block, "camera impulse", &global_camera_impulse_block_block },
		{ _field_legacy, _field_block, "runtime materials*!", &runtime_materials_block_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_legacy, _field_block, "Hologram Lighting", &hologramLightingGlobalsBlock_block },
		{ _field_legacy, _field_tag_reference, "Narrative globals", &NarrativeGlobalsReference },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_long_integer, "unknown@" },

		{ _field_legacy, _field_terminator }
	};

	V5_TAG_STRUCT(elite_specular_color_struct)
	{
		{ _field_legacy, _field_real_rgb_color, "tertiary color" },
		{ _field_legacy, _field_real_rgb_color, "quaternary color" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_STRUCT(patch_globals_struct_definition)
	{
		{ _field_legacy, _field_struct, "language pack1!", &language_pack_definition_struct_definition },
		{ _field_legacy, _field_struct, "language pack2!", &language_pack_definition_struct_definition },
		{ _field_legacy, _field_struct, "language pack3!", &language_pack_definition_struct_definition },
		{ _field_legacy, _field_struct, "language pack4!", &language_pack_definition_struct_definition },
		{ _field_legacy, _field_struct, "language pack5!", &language_pack_definition_struct_definition },
		{ _field_legacy, _field_struct, "language pack6!", &language_pack_definition_struct_definition },
		{ _field_legacy, _field_struct, "language pack7!", &language_pack_definition_struct_definition },
		{ _field_legacy, _field_struct, "language pack8!", &language_pack_definition_struct_definition },
		{ _field_legacy, _field_struct, "language pack9!", &language_pack_definition_struct_definition },
		{ _field_legacy, _field_struct, "language pack10!", &language_pack_definition_struct_definition },
		{ _field_legacy, _field_struct, "language pack11!", &language_pack_definition_struct_definition },
		{ _field_legacy, _field_struct, "language pack12!", &language_pack_definition_struct_definition },
		{ _field_legacy, _field_struct, "language pack13!", &language_pack_definition_struct_definition },
		{ _field_legacy, _field_struct, "language pack14!", &language_pack_definition_struct_definition },
		{ _field_legacy, _field_struct, "language pack15!", &language_pack_definition_struct_definition },
		{ _field_legacy, _field_struct, "language pack16!", &language_pack_definition_struct_definition },
		{ _field_legacy, _field_struct, "language pack17!", &language_pack_definition_struct_definition },
		{ _field_legacy, _field_terminator }
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

} // namespace blofeld

