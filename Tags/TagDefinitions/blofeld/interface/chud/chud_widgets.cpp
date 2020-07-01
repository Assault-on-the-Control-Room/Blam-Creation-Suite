#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{


	// animation data

	TAG_GROUP_FROM_BLOCK(chud_widget_animation_data, CHUD_WIDGET_ANIMATION_DATA_TAG, wadt_block_block);

	TAG_BLOCK(wadt_animation_data_block, 65536)
	{
		{ _field_byte_flags, "animation 1 flags", &animation_flags_definition },
		{ _field_char_enum, "animation 1 function", &animation_function_enum_definition },
		{ _field_short_integer, "unknown" },
		{ _field_tag_reference, "animation 1", &animation_reference },

		{ _field_byte_flags, "animation 2 flags", &animation_flags_definition },
		{ _field_char_enum, "animation 2 function", &animation_function_enum_definition },
		{ _field_short_integer, "unknown" },
		{ _field_tag_reference, "animation 2", &animation_reference },

		{ _field_byte_flags, "animation 3 flags", &animation_flags_definition },
		{ _field_char_enum, "animation 3 function", &animation_function_enum_definition },
		{ _field_short_integer, "unknown" },
		{ _field_tag_reference, "animation 3", &animation_reference },

		{ _field_byte_flags, "animation 4 flags", &animation_flags_definition },
		{ _field_char_enum, "animation 4 function", &animation_function_enum_definition },
		{ _field_short_integer, "unknown" },
		{ _field_tag_reference, "animation 4", &animation_reference },

		{ _field_byte_flags, "animation 5 flags", &animation_flags_definition },
		{ _field_char_enum, "animation 5 function", &animation_function_enum_definition },
		{ _field_short_integer, "unknown" },
		{ _field_tag_reference, "animation 5", &animation_reference },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(wadt_block, 1, wadt_struct_definition_struct_definition);

	TAG_STRUCT(wadt_struct_definition)
	{
		{ _field_block, "animation data", &wadt_animation_data_block_block },
		{ _field_terminator }
	};

	TAG_REFERENCE(chud_widget_animation_data_reference, CHUD_WIDGET_ANIMATION_DATA_TAG);
	
	TAG_REFERENCE_GROUP(animation_reference, _tag_reference_flag_resolved_by_game)
	{
		CHUD_ANIMATION_TAG,
		INVALID_TAG,
	};

	STRINGS(animation_flags_definition)
	{
		"reverse frames"
	};
	STRING_LIST(animation_flags_definition, animation_flags_definition_strings, _countof(animation_flags_definition_strings));

	STRINGS(animation_function_enum_definition)
	{
		"default",
		"use input",
		"use range input",
		"zero",
	};
	STRING_LIST(animation_function_enum_definition, animation_function_enum_definition_strings, _countof(animation_function_enum_definition_strings));




	// placement data

	TAG_GROUP_FROM_BLOCK(chud_widget_placement_data, CHUD_WIDGET_PLACEMENT_DATA_TAG, wpdt_block_block);

	TAG_BLOCK(wpdt_placement_data_block, 65536)
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

	TAG_BLOCK_FROM_STRUCT(wpdt_block, 1, wpdt_struct_definition_struct_definition);

	TAG_STRUCT(wpdt_struct_definition)
	{
		{ _field_block, "placement data", &wpdt_placement_data_block_block },
		{ _field_terminator }
	};

	TAG_REFERENCE(chud_widget_placement_data_reference, CHUD_WIDGET_PLACEMENT_DATA_TAG);

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
		"Unknown",
		"Top, Left",
		"Top, Middle",
		"Top, Right",
		"Center, Middle",
		"Bottom, Left",
		"Bottom, Middle",
		"Bottom, Right",
		"Motion Sensor",
		"Crosshair A",
		"Ability",
		"Weapon Left",
		"Weapon Right",
		"Health and Shield",
		"Unknown",
		"Top, Left B",
		"Unknown",
		"Crosshair B",
		"Top, Left C",
		"Top, Left D",
		"Top, Left E",
		"Crosshair B",
		"Top, Left F",
		"Unknown",
		"Top, Left G",
		"Unknown",
		"Top, Left F",
		"Score",
		"Score B",
		"Score C",
		"Score D",
		"Score E",
		"Score F",
		"Score G",
		"Unknown",
		"Unknown",
		"Unknown",
		"Unknown",
		"Unknown",
		"Unknown",
	};
	STRING_LIST(wpdt_anchor_enum_definition, wpdt_anchor_enum_definition_strings, _countof(wpdt_anchor_enum_definition_strings));




	// render data

	TAG_GROUP(chud_widget_render_data, CHUD_WIDGET_RENDER_DATA_TAG)
	{
		{ _field_terminator }
	};

	TAG_REFERENCE(chud_widget_render_data_reference, CHUD_WIDGET_RENDER_DATA_TAG);



	// state data

	TAG_GROUP_FROM_BLOCK(chud_widget_state_data, CHUD_WIDGET_STATE_DATA_TAG, wsdt_block_block);

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

	TAG_BLOCK(wsdt_state_data_block, 65536)
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

	TAG_BLOCK_FROM_STRUCT(wsdt_block, 1, wsdt_struct_definition_struct_definition);

	TAG_STRUCT(wsdt_struct_definition)
	{
		{ _field_block, "state data", &wsdt_state_data_block_block },
		{ _field_terminator }
	};

	TAG_REFERENCE(chud_widget_state_data_reference, CHUD_WIDGET_STATE_DATA_TAG);
}
