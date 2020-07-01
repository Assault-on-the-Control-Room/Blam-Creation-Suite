#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(hsc, HSC_TAG, hs_source_files_block_block );

	TAG_BLOCK(hs_references_block, k_maximum_hs_references_per_context)
	{
		{ _field_tag_reference, "reference*^", &hs_references_block_reference_reference },
		{ _field_terminator }
	};

	TAG_BLOCK(hs_source_files_block, k_maximum_hs_source_files_per_context)
	{
		{ _field_string, "name*" },
		{ _field_data, "source*" },
		{ _field_long_flags, "flags", &hs_source_file_flags },
		{ _field_terminator }
	};

	TAG_BLOCK(hs_script_parameters_block, k_maximum_hs_parameters_per_script)
	{
		{ _field_string, "name^*" },
		{ _field_long_enum, "return type*", &hs_types_enum },
		{ _field_terminator }
	};

	TAG_BLOCK(hs_scripts_block, k_maximum_hs_scripts_per_context)
	{
		{ _field_string_id, "name^*" },
		{ _field_enum, "script type*", &hs_script_types_enum },

		{ _field_version_less_or_equal, _engine_type_haloreach, 3 },
		{ _field_enum, "return type*", &hs_types_enum },
		{ _field_short_integer, "root expression index*" },
		{ _field_short_integer, "locals stack space" },

		{ _field_version_greater, _engine_type_haloreach, 4 },
		{ _field_word_flags, "script flags*", &scriptFlagsEnumDefinition },
		{ _field_long_enum, "return type*", &hs_types_enum },
		{ _field_long_integer, "root expression index*" },
		{ _field_long_integer, "locals stack space" },

		{ _field_block, "parameters", &hs_script_parameters_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(hs_globals_block, k_maximum_hs_globals_per_context)
	{
		{ _field_version_less_or_equal, _engine_type_haloreach, 1 },
		{ _field_string, "name" },

		{ _field_version_greater, _engine_type_haloreach, 1 },
		{ _field_string_id, "name*" },

		{ _field_long_enum, "type*", &hs_types_enum },
		{ _field_long_integer, "initialization expression index*" },
		{ _field_terminator }
	};

	TAG_BLOCK(HSInstancedVariablesBlock, k_maximum_hs_instanced_variables_per_context)
	{
		{ _field_string_id, "name*" },
		{ _field_long_enum, "type*", &hs_types_enum },
		{ _field_long_integer, "initialization expression index*" },
		{ _field_terminator }
	};

	TAG_BLOCK(hs_unit_seat_block, k_maximum_hs_unit_seat_mappings)
	{
		{ _field_long_integer, "unit definition tag index!" },
		{ _field_long_integer, "unit seats!" },
		{ _field_long_integer, "unit seats2!" },
		{ _field_terminator }
	};

	TAG_BLOCK(hs_syntax_datum_block, k_maximum_hs_syntax_nodes_per_context)
	{
		{ _field_version_less_or_equal, _engine_type_haloreach, 8 },
		{ _field_short_integer, "datum header~" },
		{ _field_short_integer, "script index/function index/constant type union" },
		{ _field_enum, "node expression type", &hs_types_enum },
		{ _field_short_integer, "flags" },
		{ _field_long_integer, "next node" },
		{ _field_long_integer, "source data" }, // offset into script string data (check halo 2)
		{ _field_long_integer, "source offset location" }, // reinterpreted value
		{ _field_long_integer, "source file offset" },

		{ _field_version_greater, _engine_type_haloreach, 9 },
		{ _field_short_integer, "datum header~" },
		{ _field_short_integer, "script index/function index/constant type union" },
		{ _field_long_integer, "next node" },
		{ _field_long_integer, "source data" },
		{ _field_long_integer, "source offset location" },
		{ _field_long_enum, "node expression type", &hs_types_enum },
		{ _field_short_integer, "flags" },
		{ _field_short_integer, "source file index" },
		{ _field_long_integer, "source file offset" },
		{ _field_terminator }
	};

	TAG_BLOCK(HSImportManifestEntryBlock, k_maximum_hs_scripts_per_context)
	{
		{ _field_string_id, "script name*" },
		{ _field_long_integer, "argCount*" },
		{ _field_long_integer, "index!~" },
		{ _field_terminator }
	};

	TAG_BLOCK(HSImportManifestBlock, 128)
	{
		{ _field_tag, "callee tag*" },
		{ _field_block, "script table*", &HSImportManifestEntryBlock_block },
		{ _field_block, "variable table*", &HSImportManifestEntryBlock_block },
		{ _field_terminator }
	};

	STRINGS(hs_script_types_enum)
	{
		"startup",
		"dormant",
		"continuous",
		"static",
		"command_script",
		"stub"
	};
	STRING_LIST(hs_script_types_enum, hs_script_types_enum_strings, _countof(hs_script_types_enum_strings));

	STRINGS(scriptFlagsEnumDefinition)
	{
		"instanced",
		"cinema"
	};
	STRING_LIST(scriptFlagsEnumDefinition, scriptFlagsEnumDefinition_strings, _countof(scriptFlagsEnumDefinition_strings));

	STRINGS(hs_types_enum)
	{
		"unparsed",
		"special_form",
		"function_name",
		"passthrough",
		"void",
		"boolean",
		"real",
		"short",
		"long",
		"string",
		"script",
		"string_id",
		"unit_seat_mapping",
		"trigger_volume",
		"sound_event",
		"cutscene_flag",
		"cutscene_camera_point",
		"cutscene_title",
		"cutscene_recording",
		"device_group",
		"ai",
		"ai_command_list",
		"ai_command_script",
		"ai_behavior",
		"ai_orders",
		"ai_line",
		"starting_profile",
		"conversation",
		"player",
		"zone_set",
		"designer_zone",
		"point_reference",
		"point_set_reference",
		"style",
		"object_list",
		"folder",
		"sound",
		"effect",
		"damage",
		"looping_sound",
		"animation_graph",
		"damage_effect",
		"object_definition",
		"bitmap",
		"shader",
		"render_model",
		"structure_definition",
		"lightmap_definition",
		"cinematic_definition",
		"cinematic_scene_definition",
		"cinematic_scene_data_definition",
		"cinematic_transition_definition",
		"bink_definition",
		"cui_screen_definition",
		"any_tag",
		"any_tag_not_resolving",
		"game_difficulty",
		"team",
		"mp_team",
		"controller",
		"button_preset",
		"joystick_preset",
		"player_color",
		"player_model_choice",
		"voice_output_setting",
		"voice_mask",
		"subtitle_setting",
		"actor_type",
		"model_state",
		"event",
		"character_physics",
		"skull",
		"firing_point_evaluator",
		"damage_region",
		"currency_type",
		"delivery_method",
		"wave_difficulty",
		"firefight_goal",
		"firefight_wave_type",
		"font",
		"text_justification",
		"text_alignment",
		"text_drop_shadow_type",
		"havok_group",
		"object",
		"unit",
		"vehicle",
		"weapon",
		"device",
		"scenery",
		"effect_scenery",
		"object_name",
		"unit_name",
		"vehicle_name",
		"weapon_name",
		"device_name",
		"scenery_name",
		"effect_scenery_name",
		"cinematic_lightprobe",
		"animation_budget_reference",
		"looping_sound_budget_reference",
		"sound_budget_reference"
	};
	STRING_LIST(hs_types_enum, hs_types_enum_strings, _countof(hs_types_enum_strings));

	STRINGS(hs_source_file_flags)
	{
		"generated at runtime",
		"ai fragments",
		"ai performances"
	};
	STRING_LIST(hs_source_file_flags, hs_source_file_flags_strings, _countof(hs_source_file_flags_strings));

} // namespace blofeld

