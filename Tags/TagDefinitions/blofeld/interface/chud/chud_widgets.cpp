#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{
	// animation data

	TAG_BLOCK(wadt_data_block, 65536)
	{
		{ _field_byte_flags, "animation 1 flags", &wadt_flags_definition },
		{ _field_char_enum, "animation 1 function", &wadt_function_enum_definition },
		{ _field_short_integer, "unknown" },
		{ _field_tag_reference, "animation 1", &wadt_animation_reference },

		{ _field_byte_flags, "animation 2 flags", &wadt_flags_definition },
		{ _field_char_enum, "animation 2 function", &wadt_function_enum_definition },
		{ _field_short_integer, "unknown" },
		{ _field_tag_reference, "animation 2", &wadt_animation_reference },

		{ _field_byte_flags, "animation 3 flags", &wadt_flags_definition },
		{ _field_char_enum, "animation 3 function", &wadt_function_enum_definition },
		{ _field_short_integer, "unknown" },
		{ _field_tag_reference, "animation 3", &wadt_animation_reference },

		{ _field_byte_flags, "animation 4 flags", &wadt_flags_definition },
		{ _field_char_enum, "animation 4 function", &wadt_function_enum_definition },
		{ _field_short_integer, "unknown" },
		{ _field_tag_reference, "animation 4", &wadt_animation_reference },

		{ _field_byte_flags, "animation 5 flags", &wadt_flags_definition },
		{ _field_char_enum, "animation 5 function", &wadt_function_enum_definition },
		{ _field_short_integer, "unknown" },
		{ _field_tag_reference, "animation 5", &wadt_animation_reference },
		{ _field_terminator }
	};

	TAG_GROUP_FROM_BLOCK(chud_widget_animation_data, CHUD_WIDGET_ANIMATION_DATA_TAG, wadt_block_block);
	TAG_BLOCK_FROM_STRUCT(wadt_block, 1, wadt_struct_definition_struct_definition);
	TAG_STRUCT(wadt_struct_definition)
	{
		{ _field_block, "animation data", &wadt_data_block_block },
		{ _field_terminator }
	};

	TAG_REFERENCE(chud_widget_animation_data_reference, CHUD_WIDGET_ANIMATION_DATA_TAG);
	
	TAG_REFERENCE_GROUP(wadt_animation_reference, _tag_reference_flag_resolved_by_game)
	{
		CHUD_ANIMATION_TAG,
		INVALID_TAG,
	};

	
	// placement data

	TAG_BLOCK(wpdt_data_block, 65536)
	{
		{ _field_byte_flags, "unknown", &wpdt_unknown_flags_definition },
		{ _field_char_enum, "anchor", &wpdt_anchor_enum_definition },
		{ _field_short_integer, "unknown" },
		{ _field_real, "mirror offset x" },
		{ _field_real, "mirror offset y" },
		{ _field_real, "offset x" },
		{ _field_real, "offset y" },
		{ _field_real, "scale x" },
		{ _field_real, "scale y" },
		{ _field_terminator }
	};

	TAG_GROUP_FROM_BLOCK(chud_widget_placement_data, CHUD_WIDGET_PLACEMENT_DATA_TAG, wpdt_block_block);
	TAG_BLOCK_FROM_STRUCT(wpdt_block, 1, wpdt_struct_definition_struct_definition);
	TAG_STRUCT(wpdt_struct_definition)
	{
		{ _field_block, "placement data", &wpdt_data_block_block },
		{ _field_terminator }
	};

	TAG_REFERENCE(chud_widget_placement_data_reference, CHUD_WIDGET_PLACEMENT_DATA_TAG);


	// render data

	TAG_BLOCK(wrdt_data_block, 65536)
	{
		{ _field_char_enum, "shader index", &wrdt_shader_index_enum_definition },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_real_argb_color, "local color a" },
		{ _field_real_argb_color, "local color b" },
		{ _field_real_argb_color, "local color c" },
		{ _field_real_argb_color, "local color d" },
		{ _field_real, "local color scalar a" },
		{ _field_real, "local color scalar b" },
		{ _field_real, "local color scalar c" },
		{ _field_real, "local color scalar d" },
		{ _field_enum, "output color a", &wrdt_output_color_enum_definition },
		{ _field_enum, "output color b", &wrdt_output_color_enum_definition },
		{ _field_enum, "output color c", &wrdt_output_color_enum_definition },
		{ _field_enum, "output color d", &wrdt_output_color_enum_definition },
		{ _field_enum, "output color e", &wrdt_output_color_enum_definition },
		{ _field_enum, "output color f", &wrdt_output_color_enum_definition },
		{ _field_enum, "output scalar a", &wrdt_output_scalar_enum_definition },
		{ _field_enum, "output scalar b", &wrdt_output_scalar_enum_definition },
		{ _field_enum, "output scalar c", &wrdt_output_scalar_enum_definition },
		{ _field_enum, "output scalar d", &wrdt_output_scalar_enum_definition },
		{ _field_enum, "output scalar e", &wrdt_output_scalar_enum_definition },
		{ _field_enum, "output scalar f", &wrdt_output_scalar_enum_definition },
		{ _field_long_integer, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_short_integer, "unknown" },
		{ _field_short_integer, "unknown" },
		{ _field_terminator }
	};

	TAG_GROUP_FROM_BLOCK(chud_widget_render_data, CHUD_WIDGET_RENDER_DATA_TAG, wrdt_block_block);
	TAG_BLOCK_FROM_STRUCT(wrdt_block, 1, wrdt_struct_definition_struct_definition);
	TAG_STRUCT(wrdt_struct_definition)
	{
		{ _field_block, "render data", &wrdt_data_block_block },
		{ _field_terminator }
	};

	TAG_REFERENCE(chud_widget_render_data_reference, CHUD_WIDGET_RENDER_DATA_TAG);


	// state data

	TAG_BLOCK(wsdt_triggers_block, 65536)
	{
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_long_integer, "trigger index" },
		{ _field_terminator }
	};

	TAG_BLOCK(wsdt_states_block, 65536)
	{
		{ _field_block, "triggers", &wsdt_triggers_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(wsdt_data_block, 65536)
	{
		{ _field_block, "states 1", &wsdt_states_block_block },
		{ _field_block, "states 2", &wsdt_states_block_block },
		{ _field_block, "states 3", &wsdt_states_block_block },
		{ _field_short_integer, "unknown" },
		{ _field_short_integer, "unknown" },
		{ _field_short_integer, "unknown" },
		{ _field_short_integer, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_terminator }
	};

	TAG_GROUP_FROM_BLOCK(chud_widget_state_data, CHUD_WIDGET_STATE_DATA_TAG, wsdt_block_block);
	TAG_BLOCK_FROM_STRUCT(wsdt_block, 1, wsdt_struct_definition_struct_definition);
	TAG_STRUCT(wsdt_struct_definition)
	{
		{ _field_block, "state data", &wsdt_data_block_block },
		{ _field_terminator }
	};

	TAG_REFERENCE(chud_widget_state_data_reference, CHUD_WIDGET_STATE_DATA_TAG);


	// strings

	STRINGS(wadt_flags_definition)
	{
		"reverse frames"
	};
	STRING_LIST(wadt_flags_definition, wadt_flags_definition_strings, _countof(wadt_flags_definition_strings));

	STRINGS(wadt_function_enum_definition)
	{
		"default",
		"use input",
		"use range input",
		"zero",
	};
	STRING_LIST(wadt_function_enum_definition, wadt_function_enum_definition_strings, _countof(wadt_function_enum_definition_strings));

	STRINGS(wpdt_unknown_flags_definition)
	{
		"bit 0",
		"bit 1",
		"bit 2",
		"bit 3",
		"bit 4",
		"bit 5",
		"bit 6",
		"bit 7",
	};
	STRING_LIST(wpdt_unknown_flags_definition, wpdt_unknown_flags_definition_strings, _countof(wpdt_unknown_flags_definition_strings));

	STRINGS(wpdt_anchor_enum_definition)
	{
		"unknown",
		"top, left",
		"top, middle",
		"top, right",
		"center, middle",
		"bottom, left",
		"bottom, middle",
		"bottom, right",
		"motion sensor",
		"crosshair a",
		"ability",
		"weapon left",
		"weapon right",
		"health and shield",
		"unknown",
		"top, left b",
		"unknown",
		"crosshair b",
		"top, left c",
		"top, left d",
		"top, left e",
		"crosshair b",
		"top, left f",
		"unknown",
		"top, left g",
		"unknown",
		"top, left f",
		"score",
		"score b",
		"score c",
		"score d",
		"score e",
		"score f",
		"score g",
		"unknown",
		"unknown",
		"unknown",
		"unknown",
		"unknown",
		"unknown",
	};
	STRING_LIST(wpdt_anchor_enum_definition, wpdt_anchor_enum_definition_strings, _countof(wpdt_anchor_enum_definition_strings));

	STRINGS(wrdt_shader_index_enum_definition)
	{
		"cheap",
		"simple",
		"meter",
		"text simple",
		"meter shield",
		"meter gradient",
		"crosshair",
		"directional damage",
		"solid",
		"sensor",
		"meter single color",
		"navpoint",
		"medal",
		"texture cam",
		"meter chapter",
		"meter double gradient",
		"meter radial gradient",
		"turbulence",
		"emblem",
		"directional damage apply",
		"damage tracker",
	};
	STRING_LIST(wrdt_shader_index_enum_definition, wrdt_shader_index_enum_definition_strings, _countof(wrdt_shader_index_enum_definition_strings));

	STRINGS(wrdt_output_color_enum_definition)
	{
		"local a",
		"local b",
		"local c",
		"local d",
		"unknown 4",
		"unknown 5",
		"scoreboard friendly",
		"scoreboard enemy",
		"arming team",
		"metagame player 1",
		"metagame player 2",
		"metagame player 3",
		"metagame player 4",
		"unknown 13",
		"unknown 14",
		"unknown 15",
		"unknown 16",
		"unknown 17",
		"global dynamic 0",
		"global dynamic 1",
		"global dynamic 2",
		"global dynamic 3",
		"global dynamic 4",
		"global dynamic 5",
		"global dynamic 6",
		"global dynamic 7",
		"global dynamic 8",
		"global dynamic 9",
		"global dynamic 10",
		"global dynamic 11",
		"global dynamic 12",
		"global dynamic 13",
		"global dynamic 14",
		"global dynamic 15",
		"global dynamic 16",
		"global dynamic 17",
		"global dynamic 18",
		"global dynamic 19",
		"global dynamic 20",
		"global dynamic 21",
		"global dynamic 22",
		"global dynamic 23",
		"global dynamic 24",
		"global dynamic 25",
		"global dynamic 26",
		"global dynamic 27",
		"global dynamic 28",
		"global dynamic 29",
		"global dynamic 30",
		"global dynamic 31",
		"global dynamic 32",
		"global dynamic 33",
		"global dynamic 34",
		"global dynamic 35",
		"global dynamic 36",
		"global dynamic 37",
		"global dynamic 38",
		"global dynamic 39",
		"global dynamic 40",
		"global dynamic 41",
		"global dynamic 42",
	};
	STRING_LIST(wrdt_output_color_enum_definition, wrdt_output_color_enum_definition_strings, _countof(wrdt_output_color_enum_definition_strings));

	STRINGS(wrdt_output_scalar_enum_definition)
	{
		"unknown 0",
		"unknown 1",
		"input",
		"range input",
		"function value 1",
		"function value 2",
		"function value 3",
		"function value 4",
		"unknown 8",
		"unknown 9",
	};
	STRING_LIST(wrdt_output_scalar_enum_definition, wrdt_output_scalar_enum_definition_strings, _countof(wrdt_output_scalar_enum_definition_strings));

}
