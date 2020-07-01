#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP(GameEngineFirefightVariantTag, GAMEENGINEFIREFIGHTVARIANTTAG_TAG)
	{
		{ _field_struct, "variant", &gameEngineFirefightVariantDefinition_struct_definition },
		{ _field_terminator }
	};

	TAG_GROUP_FROM_BLOCK(game_engine_globals, GAME_ENGINE_GLOBALS_TAG, game_engine_globals_block_block );

	TAG_GROUP_FROM_BLOCK(game_engine_settings_definition, GAME_ENGINE_SETTINGS_DEFINITION_TAG, game_engine_settings_definition_block_block );

	TAG_BLOCK(game_engine_miscellaneous_options_block, 1)
	{
		{ _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_byte_flags, "flags", &game_engine_miscellaneous_options_flags },
		
		{ _field_version_greater, _engine_type_haloreach },
		{ _field_word_flags, "flags", &game_engine_miscellaneous_options_flags },
		
		{ _field_char_integer, "early victory win count" },
		{ _field_char_integer, "round time limit:minutes" },
		{ _field_char_integer, "number of rounds" },

		{ _field_version_less_or_equal, _engine_type_haloreach, 2 },
		{ _field_short_integer, "sudden death" },
		{ _field_short_integer, "grace period" },
		
		{ _field_version_greater, _engine_type_haloreach, 3 },
		{ _field_char_enum, "mosh difficulty level", &mosh_difficulty },
		{ _field_byte_integer, "overshield deplete time" },
		{ _field_pad, "RXXH", 1 },
		
		{ _field_terminator }
	};

	TAG_BLOCK(game_engine_prototype_options_block, 1)
	{
		{ _field_char_integer, "prototype mode" },
		{ _field_char_integer, "promethean energy kill percent" },
		{ _field_char_integer, "promethean energy time percent" },
		{ _field_char_integer, "promethean energy medal percent" },
		{ _field_char_integer, "promethean duration" },
		{ _field_char_integer, "class color override" },
		{ _field_terminator }
	};

	TAG_BLOCK(game_engine_respawn_options_block, 1)
	{
		{ _field_word_flags, "flags", &game_engine_respawn_options_flags },
		{ _field_char_integer, "lives per round" },
		{ _field_char_integer, "team lives per round" },

		{ _field_version_greater, _engine_type_haloreach },
		{ _field_char_integer, "min respawn time:seconds" },
		
		{ _field_char_integer, "respawn time:seconds" },
		{ _field_char_integer, "suicide penalty:seconds" },
		{ _field_char_integer, "betrayal penalty:seconds" },
		{ _field_char_integer, "respawn growth:seconds" },

		{ _field_version_greater, _engine_type_haloreach },
		{ _field_pad, "EOTOTRXV", 3 },
		
		{ _field_string_id, "respawn player traits name" },
		{ _field_char_integer, "initial loadout selection time:seconds#delay before spawning in at start of round" },
		{ _field_char_integer, "respawn player traits duration:seconds" },
		{ _field_pad, "woman bound for glory, why you leaving me again\?", 2 },
		{ _field_terminator }
	};

	TAG_BLOCK(game_engine_social_options_block, 1)
	{
		{ _field_long_flags, "flags", &game_engine_social_options_flags },
		{ _field_terminator }
	};

	TAG_BLOCK(game_engine_map_override_options_block, 1)
	{
		{ _field_string_id, "player traits name" },
		{ _field_string_id, "weapon set name" },
		{ _field_string_id, "vehicle set name" },

		{ _field_version_less_or_equal, _engine_type_haloreach, 6 },
		{ _field_string_id, "overshield powerup traits name" },
		{ _field_string_id, "active camo powerup traits name" },
		{ _field_string_id, "custom powerup traits name" },
		{ _field_char_integer, "overshield powerup duration:seconds" },
		{ _field_char_integer, "active camo powerup duration:seconds" },
		{ _field_char_integer, "custom powerup duration:seconds" },
		
		{ _field_version_greater, _engine_type_haloreach, 17 },
		{ _field_string_id, "equipment set name" },
		{ _field_string_id, "red powerup traits name" },
		{ _field_string_id, "blue powerup traits name" },
		{ _field_string_id, "yellow powerup traits name" },
		{ _field_string_id, "custom powerup traits name" },
		{ _field_char_integer, "red powerup duration:seconds" },
		{ _field_char_integer, "blue powerup duration:seconds" },
		{ _field_char_integer, "yellow powerup duration:seconds" },
		{ _field_char_integer, "custom powerup duration:seconds" },
		{ _field_string_id, "red powerup secondary traits name" },
		{ _field_string_id, "blue powerup secondary traits name" },
		{ _field_string_id, "yellow powerup secondary traits name" },
		{ _field_string_id, "custom powerup secondary traits name" },
		{ _field_char_integer, "red powerup secondary duration:seconds" },
		{ _field_char_integer, "blue powerup secondary duration:seconds" },
		{ _field_char_integer, "yellow powerup secondary duration:seconds" },
		{ _field_char_integer, "custom powerup secondary duration:seconds" },
		
		{ _field_byte_flags, "flags", &game_engine_map_override_options_flags },

		{ _field_version_greater, _engine_type_haloreach },
		{ _field_pad, "pad", 3 },
		
		{ _field_terminator }
	};

	TAG_BLOCK(game_engine_team_options_block, 1)
	{
		{ _field_char_enum, "model override type", &game_engine_team_options_model_override_type },
		{ _field_char_enum, "designator switch type", &game_engine_team_options_designator_switch_type },
		{ _field_pad, "pad", 2 },
		{ _field_array, "teams", &game_engine_team_options_team_block_array },
		{ _field_terminator }
	};

	TAG_BLOCK(gameEngineOrdnanceOptionsBlock, 1)
	{
		{ _field_byte_flags, "flags", &gameEngineOrdnanceOptionsFlags },
		{ _field_terminator }
	};

	TAG_BLOCK(GameEngineFirefightWavePropertiesBlock, k_firefightWavesPerGoal)
	{
		{ _field_string_id, "squad type^#survival_mode_get_wave_squad" },
		{ _field_char_enum, "Delivery type", &FirefightWaveDeliveryMethod },
		{ _field_char_integer, "AI allowed before next wave spawns" },
		{ _field_char_integer, "Enemies Left Before HUD Marking" },
		{ _field_char_integer, "Wave Type" },
		{ _field_char_integer, "Weapon to drop" },
		{ _field_char_integer, "Vehicle to drop" },
		{ _field_char_integer, "Squad 1" },
		{ _field_char_integer, "Squad 2" },
		{ _field_string, "Start Event" },
		{ _field_string, "End Event" },
		{ _field_terminator }
	};

	TAG_BLOCK(GameEngineFirefightPlayerGoalPropertiesBlock, k_firefightMaxPlayerGoals)
	{
		{ _field_char_enum, "Player Goal", &FirefightGoal },
		{ _field_char_integer, "Lives" },
		{ _field_char_integer, "Time Limit#minutes" },
		{ _field_byte_flags, "Wave Difficulty", &FirefightWaveDifficulty },
		{ _field_block, "Firefight Waves", &GameEngineFirefightWavePropertiesBlock_block },
		{ _field_long_flags, "Player Goal Flags", &GameEnginePlayerGoalFlags },
		{ _field_string_id, "spartan player traits" },
		{ _field_string_id, "ai traits" },
		{ _field_string, "Start Event" },
		{ _field_string, "End Event" },
		{ _field_long_flags, "skulls^{primary skulls}", &skull_flags },
		{ _field_char_integer, "objective 1" },
		{ _field_char_integer, "objective 2" },
		{ _field_char_integer, "objective 3" },
		{ _field_char_integer, "objective 4" },
		{ _field_char_integer, "User Data" },
		{ _field_char_integer, "start location folder" },
		{ _field_pad, "BLAH", 2 },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(game_engine_globals_block, 1, game_engine_globals_struct_definition_struct_definition );

	TAG_BLOCK(game_engine_ai_traits_list_block, 64)
	{
		{ _field_string_id, "name^" },
		{ _field_struct, "ai traits", &game_engine_ai_traits_struct_struct_definition },
		{ _field_terminator }
	};

	TAG_BLOCK(game_engine_sandbox_variant_block, 32)
	{
		{ _field_string_id, "localizable name^" },
		{ _field_string_id, "localizable description" },
		{ _field_block, "miscellaneous options", &game_engine_miscellaneous_options_block_block },

		{ _field_version_greater, _engine_type_haloreach },
		{ _field_block, "prototype options", &game_engine_prototype_options_block_block },
		
		{ _field_block, "respawn options", &game_engine_respawn_options_block_block },
		{ _field_block, "social options", &game_engine_social_options_block_block },
		{ _field_block, "map override options", &game_engine_map_override_options_block_block },
		{ _field_block, "team options", &game_engine_team_options_block_block },
		{ _field_block, "loadout options", &game_engine_loadout_options_block_block },

		{ _field_version_greater, _engine_type_haloreach },
		{ _field_block, "ordnance options", &gameEngineOrdnanceOptionsBlock_block },
		
		{ _field_long_flags, "flags", &sandbox_flags },
		{ _field_enum, "edit mode", &sandbox_editing_mode },
		{ _field_enum, "respawn time", &sandbox_respawn_time },
		{ _field_string_id, "all players traits" },
		{ _field_terminator }
	};

	TAG_BLOCK(game_engine_survival_set_properties_block, 10)
	{
		{ _field_long_flags, "skulls^{primary skulls}", &skull_flags },
		{ _field_terminator }
	};

	TAG_BLOCK(survival_wave_squad_block, k_maximum_survival_possible_wave_squads)
	{
		{ _field_string_id, "squad type^#survival_mode_get_wave_squad" },
		{ _field_terminator }
	};

	TAG_BLOCK(game_engine_survival_round_properties_block, k_survival_full_rounds_per_set)
	{
		{ _field_long_flags, "skulls^{primary skulls}", &skull_flags },
		{ _field_custom, "initial wave" },
		{ _field_struct, "initial waves", &game_engine_survival_wave_properties_struct_struct_definition },
		{ _field_custom },
		{ _field_custom, "primary wave" },
		{ _field_struct, "primary waves", &game_engine_survival_wave_properties_struct_struct_definition },
		{ _field_custom },
		{ _field_custom, "boss wave" },
		{ _field_struct, "boss waves", &game_engine_survival_wave_properties_struct_struct_definition },
		{ _field_custom },
		{ _field_terminator }
	};

	TAG_BLOCK(game_engine_survival_custom_skull_block, k_maximum_survival_custom_skulls)
	{
		{ _field_string_id, "spartan player traits" },
		{ _field_string_id, "elite player traits" },
		{ _field_string_id, "ai traits" },
		{ _field_terminator }
	};

	TAG_BLOCK(game_engine_survival_variant_block, 32)
	{
		{ _field_string_id, "localizable name^" },
		{ _field_string_id, "localizable description" },
		{ _field_block, "miscellaneous options", &game_engine_miscellaneous_options_block_block },

		{ _field_version_greater, _engine_type_haloreach },
		{ _field_block, "prototype options", &game_engine_prototype_options_block_block },
		
		{ _field_block, "respawn options", &game_engine_respawn_options_block_block },
		{ _field_block, "social options", &game_engine_social_options_block_block },
		{ _field_block, "map override options", &game_engine_map_override_options_block_block },
		{ _field_block, "team options", &game_engine_team_options_block_block },
		{ _field_block, "loadout options", &game_engine_loadout_options_block_block },

		{ _field_version_greater, _engine_type_haloreach },
		{ _field_block, "ordnance options", &gameEngineOrdnanceOptionsBlock_block },
		
		{ _field_byte_flags, "flags", &game_engine_survival_variant_flags },
		{ _field_char_enum, "game difficulty", &game_engine_survival_variant_difficulty_enum },

		{ _field_version_greater, _engine_type_haloreach },
		{ _field_pad, "SDFHJREN", 2 },

		{ _field_version_less_or_equal, _engine_type_haloreach, 2 },
		{ _field_char_integer, "time limit" },
		{ _field_char_integer, "unknown" }, // #TODO: Do some research
		
		{ _field_char_integer, "set count#survival_mode_get_set_count, -1 to loop last, -2 to loop last 3, -3 to loop all" },
		{ _field_char_integer, "bonus lives awarded#survival_mode_get_bonus_lives_awarded" },
		{ _field_short_integer, "bonus target#survival_mode_get_bonus_target" },
		{ _field_short_integer, "spartan lives on elite death" },
		{ _field_short_integer, "extra life score target" },
		{ _field_short_integer, "shared team life count" },
		{ _field_short_integer, "elite life count" },
		{ _field_short_integer, "maximum lives" },

		{ _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_enum, "generator count", &game_engine_survival_generator_count_enum },

		{ _field_version_greater, _engine_type_haloreach },
		{ _field_short_integer, "generator count" },
		
		{ _field_string_id, "spartan player traits" },
		{ _field_string_id, "elite player traits" },
		{ _field_string_id, "ai traits" },
		{ _field_block, "elite respawn options", &game_engine_respawn_options_block_block },
		{ _field_block, "set properties", &game_engine_survival_set_properties_block_block },
		{ _field_block, "round properties", &game_engine_survival_round_properties_block_block },
		{ _field_custom, "bonus round" },
		{ _field_struct, "bonus round properties", &game_engine_survival_bonus_wave_properties_struct_struct_definition },
		{ _field_custom },
		{ _field_block, "custom skulls", &game_engine_survival_custom_skull_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(GameEngineFirefightVariantShellBlock, 128)
	{
		{ _field_tag_reference, "variant", &GameEngineFirefightVariantReference },
		{ _field_terminator }
	};

	TAG_BLOCK(game_engine_campaign_variant_block, 32)
	{
		{ _field_string_id, "localizable name^" },
		{ _field_string_id, "localizable description" },
		{ _field_block, "miscellaneous options", &game_engine_miscellaneous_options_block_block },
		{ _field_block, "prototype options", &game_engine_prototype_options_block_block },
		{ _field_block, "respawn options", &game_engine_respawn_options_block_block },
		{ _field_block, "social options", &game_engine_social_options_block_block },
		{ _field_block, "map override options", &game_engine_map_override_options_block_block },
		{ _field_block, "team options", &game_engine_team_options_block_block },
		{ _field_block, "loadout options", &game_engine_loadout_options_block_block },
		{ _field_block, "ordnance options", &gameEngineOrdnanceOptionsBlock_block },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(game_engine_settings_definition_block, 1, game_engine_settings_definition_struct_definition_struct_definition );

	TAG_ARRAY(game_engine_team_options_team_block, k_multiplayer_team_game_team_count)
	{
		{ _field_byte_flags, "flags", &game_engine_team_options_team_flags },
		{ _field_char_enum, "initial team designator", &global_multiplayer_team_designator_enum_definition },
		{ _field_char_enum, "model override", &game_engine_team_options_player_model_choice },
		{ _field_byte_integer, "number of fireteams" },
		{ _field_string_id, "description" },
		{ _field_rgb_color, "primary color override{color override}" },
		{ _field_rgb_color, "secondary color override" },
		{ _field_argb_color, "ui text tint color override" },

		{ _field_version_greater, _engine_type_haloreach },
		{ _field_argb_color, "ui bitmap tint color override" },
		
		{ _field_terminator }
	};

	TAG_STRUCT(gameEngineFirefightVariantDefinition)
	{
		{ _field_string_id, "localizable name^" },
		{ _field_string_id, "localizable description" },
		{ _field_block, "miscellaneous options", &game_engine_miscellaneous_options_block_block },

		{ _field_version_greater, _engine_type_haloreach },
		{ _field_block, "prototype options", &game_engine_prototype_options_block_block },
		
		{ _field_block, "respawn options", &game_engine_respawn_options_block_block },
		{ _field_block, "social options", &game_engine_social_options_block_block },
		{ _field_block, "map override options", &game_engine_map_override_options_block_block },
		{ _field_block, "team options", &game_engine_team_options_block_block },
		{ _field_block, "loadout options", &game_engine_loadout_options_block_block },

		{ _field_version_greater, _engine_type_haloreach },
		{ _field_block, "ordnance options", &gameEngineOrdnanceOptionsBlock_block },
		
		{ _field_long_integer, "mission_id" },
		{ _field_char_enum, "game difficulty", &global_campaign_difficulty_enum },
		{ _field_byte_flags, "firefight variant flags", &GameEngineFirefightVariantFlags },
		{ _field_short_integer, "shared team life count" },
		{ _field_short_integer, "maximum lives" },
		{ _field_char_integer, "Starting Crate 1" },
		{ _field_char_integer, "Starting Crate 2" },
		{ _field_char_integer, "Starting Crate 3" },
		{ _field_char_integer, "Starting Crate 4" },
		{ _field_char_integer, "Starting Crate 5" },
		{ _field_char_integer, "Starting Crate 6" },
		{ _field_char_integer, "Starting Crate 7" },
		{ _field_char_integer, "Starting Crate 8" },
		{ _field_char_integer, "Starting Crate 9" },
		{ _field_char_integer, "Starting Crate 10" },
		{ _field_char_integer, "Starting Crate 11" },
		{ _field_char_integer, "Starting Crate 12" },
		{ _field_char_integer, "Starting Crate 13" },
		{ _field_char_integer, "Starting Crate 14" },
		{ _field_string, "Variant Event#This event is always set for script" },
		{ _field_block, "Midnight Player Goal Properties", &GameEngineFirefightPlayerGoalPropertiesBlock_block },
		{ _field_terminator }
	};

	TAG_STRUCT(game_engine_globals_struct_definition)
	{
		{ _field_tag_reference, "game engine settings", &game_engine_settings_definition_reference },
		{ _field_tag_reference, "game engine text", &global_multilingual_unicode_string_list_reference },
		{ _field_block, "game engine event response list", &game_engine_event_block_block },
		{ _field_terminator }
	};

	TAG_STRUCT(game_engine_settings_definition_struct_definition)
	{
		{ _field_explanation, "Game Engine Settings", "This contains the definitions for the built-in custom multiplayer game variants" },
		{ _field_long_flags, "flags", &game_engine_settings_flags },
		{ _field_block, "player traits", &game_engine_player_traits_list_block_block },
		{ _field_block, "ai traits", &game_engine_ai_traits_list_block_block },
		{ _field_block, "sandbox variants", &game_engine_sandbox_variant_block_block },
		{ _field_block, "survival variants", &game_engine_survival_variant_block_block },
		{ _field_block, "new firefight variants{firefight variants new}", &GameEngineFirefightVariantShellBlock_block },
		{ _field_block, "campaign variants", &game_engine_campaign_variant_block_block },
		{ _field_terminator }
	};

	TAG_STRUCT(game_engine_ai_traits_struct)
	{
		{ _field_char_enum, "vision traits", &ai_trait_vision_settings },
		{ _field_char_enum, "sound traits", &ai_trait_sound_settings },
		{ _field_char_enum, "luck traits", &ai_trait_luck_settings },
		{ _field_char_enum, "weapon traits", &global_ai_trait_weapon_settings },
		{ _field_char_enum, "grenade traits", &ai_trait_grenade_settings },
		{ _field_char_enum, "drop equipment on death", &player_trait_bool_enum },
		{ _field_char_enum, "assassination immunity", &player_trait_bool_enum },
		{ _field_char_enum, "headshot immunity", &player_trait_bool_enum },
		{ _field_char_enum, "damage resistance percentage", &player_trait_damage_resistance },
		{ _field_char_enum, "damage modifier percentage", &player_trait_damage_modifier },
		{ _field_pad, "pad", 2 },
		{ _field_terminator }
	};

	TAG_STRUCT(game_engine_survival_wave_properties_struct)
	{
		{ _field_byte_flags, "flags", &survival_wave_properties_flags },
		{ _field_char_enum, "wave selection type", &survival_wave_squad_advance_type_enum },
		{ _field_pad, "VJKNMFEN", 2 },
		{ _field_block, "wave squads", &survival_wave_squad_block_block },
		{ _field_terminator }
	};

	TAG_STRUCT(game_engine_survival_bonus_wave_properties_struct)
	{
		{ _field_long_flags, "skulls^{primary skulls}", &skull_flags },
		{ _field_short_integer, "duration:s" },
		{ _field_pad, "CLKJSDF", 2 },
		{ _field_struct, "base properties", &game_engine_survival_wave_properties_struct_struct_definition },
		{ _field_terminator }
	};

	STRINGS(ai_trait_vision_settings)
	{
		"unchanged",
		"normal",
		"blind",
		"near sighted",
		"eagle eye"
	};
	STRING_LIST(ai_trait_vision_settings, ai_trait_vision_settings_strings, _countof(ai_trait_vision_settings_strings));

	STRINGS(ai_trait_sound_settings)
	{
		"unchanged",
		"normal",
		"deaf",
		"sharp"
	};
	STRING_LIST(ai_trait_sound_settings, ai_trait_sound_settings_strings, _countof(ai_trait_sound_settings_strings));

	STRINGS(ai_trait_luck_settings)
	{
		"unchanged",
		"normal",
		"unlucky",
		"lucky",
		"leprechaun"
	};
	STRING_LIST(ai_trait_luck_settings, ai_trait_luck_settings_strings, _countof(ai_trait_luck_settings_strings));

	STRINGS(global_ai_trait_weapon_settings)
	{
		"unchanged",
		"normal",
		"marksman",
		"trigger happy"
	};
	STRING_LIST(global_ai_trait_weapon_settings, global_ai_trait_weapon_settings_strings, _countof(global_ai_trait_weapon_settings_strings));

	STRINGS(ai_trait_grenade_settings)
	{
		"unchanged",
		"normal",
		"none",
		"catch"
	};
	STRING_LIST(ai_trait_grenade_settings, ai_trait_grenade_settings_strings, _countof(ai_trait_grenade_settings_strings));

	STRINGS(game_engine_miscellaneous_options_flags)
	{
		"teams enabled",
		"round reset players",
		"round reset map",
		"perfection enabled",
		"mosh",
		"drop weapons on death",
		"killcam enabled",
		"medal scoring enabled",
		"asymmetric round scoring"
	};
	STRING_LIST(game_engine_miscellaneous_options_flags, game_engine_miscellaneous_options_flags_strings, _countof(game_engine_miscellaneous_options_flags_strings));

	STRINGS(mosh_difficulty)
	{
		"easy",
		"normal",
		"heroic",
		"legendary"
	};
	STRING_LIST(mosh_difficulty, mosh_difficulty_strings, _countof(mosh_difficulty_strings));

	STRINGS(game_engine_respawn_options_flags)
	{
		"inherit respawn time",
		"respawn with teammate",
		"respawn at location",
		"respawn on kills",
		"early respawn allowed"
	};
	STRING_LIST(game_engine_respawn_options_flags, game_engine_respawn_options_flags_strings, _countof(game_engine_respawn_options_flags_strings));

	STRINGS(game_engine_social_options_flags)
	{
		"observers enabled",
		"team changing enabled",
		"team changing balancing only",
		"friendly fire enabled",
		"betrayal booting enabled",
		"enemy voice enabled",
		"open channel voice enabled",
		"dead player voice enabled"
	};
	STRING_LIST(game_engine_social_options_flags, game_engine_social_options_flags_strings, _countof(game_engine_social_options_flags_strings));

	STRINGS(game_engine_map_override_options_flags)
	{
		"grenades on map",
		"shortcuts on map",
		"equipment on map",
		"powerups on map",
		"turrets on map",
		"indestructible vehicles"
	};
	STRING_LIST(game_engine_map_override_options_flags, game_engine_map_override_options_flags_strings, _countof(game_engine_map_override_options_flags_strings));

	STRINGS(game_engine_team_options_team_flags)
	{
		"enabled",
		"primary override color",
		"secondary override color",
		"override ui text tint color",
		"override ui bitmap tint color",
		"override emblem"
	};
	STRING_LIST(game_engine_team_options_team_flags, game_engine_team_options_team_flags_strings, _countof(game_engine_team_options_team_flags_strings));

	STRINGS(game_engine_team_options_player_model_choice)
	{
		"spartan",
		"elite"
	};
	STRING_LIST(game_engine_team_options_player_model_choice, game_engine_team_options_player_model_choice_strings, _countof(game_engine_team_options_player_model_choice_strings));

	STRINGS(game_engine_team_options_model_override_type)
	{
		"none (player choice)",
		"force spartan",
		"force elite",
		"set by team",
		"set by designator"
	};
	STRING_LIST(game_engine_team_options_model_override_type, game_engine_team_options_model_override_type_strings, _countof(game_engine_team_options_model_override_type_strings));

	STRINGS(game_engine_team_options_designator_switch_type)
	{
		"none",
		"random",
		"rotate"
	};
	STRING_LIST(game_engine_team_options_designator_switch_type, game_engine_team_options_designator_switch_type_strings, _countof(game_engine_team_options_designator_switch_type_strings));

	STRINGS(gameEngineOrdnanceOptionsFlags)
	{
		"ordnance enabled"
	};
	STRING_LIST(gameEngineOrdnanceOptionsFlags, gameEngineOrdnanceOptionsFlags_strings, _countof(gameEngineOrdnanceOptionsFlags_strings));

	STRINGS(sandbox_flags)
	{
		"open channel voice",
		"requires all objects"
	};
	STRING_LIST(sandbox_flags, sandbox_flags_strings, _countof(sandbox_flags_strings));

	STRINGS(sandbox_editing_mode)
	{
		"All players",
		"Only Leader"
	};
	STRING_LIST(sandbox_editing_mode, sandbox_editing_mode_strings, _countof(sandbox_editing_mode_strings));

	STRINGS(sandbox_respawn_time)
	{
		"instant",
		"3 seconds",
		"4 seconds",
		"5 seconds",
		"6 seconds",
		"7 seconds",
		"8 seconds",
		"9 seconds",
		"10 seconds",
		"15 seconds",
		"30 seconds",
		"60 seconds"
	};
	STRING_LIST(sandbox_respawn_time, sandbox_respawn_time_strings, _countof(sandbox_respawn_time_strings));

	STRINGS(skull_flags)
	{
		"skull_iron",
		"skull_black_eye",
		"skull_tough_luck",
		"skull_catch",
		"skull_fog",
		"skull_famine",
		"skull_thunderstorm",
		"skull_tilt",
		"skull_mythic",
		"skull_assassin",
		"skull_blind",
		"skull_superman",
		"skull_birthday_party",
		"skull_daddy",
		"skull_red",
		"skull_yellow",
		"skull_blue"
	};
	STRING_LIST(skull_flags, skull_flags_strings, _countof(skull_flags_strings));

	STRINGS(survival_wave_squad_advance_type_enum)
	{
		"random",
		"sequence"
	};
	STRING_LIST(survival_wave_squad_advance_type_enum, survival_wave_squad_advance_type_enum_strings, _countof(survival_wave_squad_advance_type_enum_strings));

	STRINGS(survival_wave_properties_flags)
	{
		"delivered via dropship"
	};
	STRING_LIST(survival_wave_properties_flags, survival_wave_properties_flags_strings, _countof(survival_wave_properties_flags_strings));

	STRINGS(game_engine_survival_variant_flags)
	{
		"enable scenario hazards",
		"generator defend all",
		"generator random spawn",
		"enable weapon drops",
		"enable ammo crates"
	};
	STRING_LIST(game_engine_survival_variant_flags, game_engine_survival_variant_flags_strings, _countof(game_engine_survival_variant_flags_strings));

	STRINGS(FirefightWaveDeliveryMethod)
	{
		"Dropship",
		"Monster Closet",
		"Drop Pod",
		"Test Spawn"
	};
	STRING_LIST(FirefightWaveDeliveryMethod, FirefightWaveDeliveryMethod_strings, _countof(FirefightWaveDeliveryMethod_strings));

	STRINGS(FirefightWaveDifficulty)
	{
		"Easy",
		"Medium",
		"Hard"
	};
	STRING_LIST(FirefightWaveDifficulty, FirefightWaveDifficulty_strings, _countof(FirefightWaveDifficulty_strings));

	STRINGS(FirefightGoal)
	{
		"Object Destruction",
		"Object Delivery",
		"Location Arrival",
		"Time Passed",
		"No More Waves",
		"Kill Boss",
		"Defense",
		"Other"
	};
	STRING_LIST(FirefightGoal, FirefightGoal_strings, _countof(FirefightGoal_strings));

	STRINGS(GameEnginePlayerGoalFlags)
	{
		"Looping",
		"Random Waves"
	};
	STRING_LIST(GameEnginePlayerGoalFlags, GameEnginePlayerGoalFlags_strings, _countof(GameEnginePlayerGoalFlags_strings));

	STRINGS(GameEngineFirefightVariantFlags)
	{
		"Use Ammo Crates",
		"Players Respawn on Wave"
	};
	STRING_LIST(GameEngineFirefightVariantFlags, GameEngineFirefightVariantFlags_strings, _countof(GameEngineFirefightVariantFlags_strings));

	STRINGS(game_engine_settings_flags)
	{
		"unused"
	};
	STRING_LIST(game_engine_settings_flags, game_engine_settings_flags_strings, _countof(game_engine_settings_flags_strings));

	STRINGS(game_engine_survival_generator_count_enum)
	{
		"None",
		"1 Generator",
		"2 Generators",
		"3 Generators"
	};
	STRING_LIST(game_engine_survival_generator_count_enum, game_engine_survival_generator_count_enum_strings, _countof(game_engine_survival_generator_count_enum_strings));

	STRINGS(game_engine_survival_variant_difficulty_enum)
	{
		"unchanged",
		"easy",
		"normal",
		"heroic",
		"legendary"
	};
	STRING_LIST(game_engine_survival_variant_difficulty_enum, game_engine_survival_variant_difficulty_enum_strings, _countof(game_engine_survival_variant_difficulty_enum_strings));

	TAG_REFERENCE(GameEngineFirefightVariantReference, GAMEENGINEFIREFIGHTVARIANTTAG_TAG);

} // namespace blofeld

