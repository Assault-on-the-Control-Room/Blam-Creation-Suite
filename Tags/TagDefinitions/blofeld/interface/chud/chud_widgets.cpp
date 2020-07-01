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
		/*
		<flags8 name="Unknown" offset="0x0" visible="true">
			<bit name="Bit 0" index="0" />
			<bit name="Bit 1" index="1" />
			<bit name="Bit 2" index="2" />
			<bit name="Bit 3" index="3" />
			<bit name="Bit 4" index="4" />
			<bit name="Bit 5" index="5" />
			<bit name="Bit 6" index="6" />
			<bit name="Bit 7" index="7" />
		</flags8>
		<enum8 name="Anchor" offset="0x1" visible="true">
			<option name="Unknown" value="0x0" />
			<option name="Top, Left" value="0x1" />
			<option name="Top, Middle" value="0x2" />
			<option name="Top, Right" value="0x3" />
			<option name="Center, Middle" value="0x4" />
			<option name="Bottom, Left" value="0x5" />
			<option name="Bottom, Middle" value="0x6" />
			<option name="Bottom, Right" value="0x7" />
			<option name="Motion Sensor" value="0x8" />
			<option name="Crosshair A" value="0x9" />
			<option name="Ability" value="0xA" />
			<option name="Weapon Left" value="0xB" />
			<option name="Weapon Right" value="0xC" />
			<option name="Health and Shield" value="0xD" />
			<option name="Unknown" value="0xE" />
			<option name="Top, Left B" value="0xF" />
			<option name="Unknown" value="0x10" />
			<option name="Crosshair B" value="0x11" />
			<option name="Top, Left C" value="0x12" />
			<option name="Top, Left D" value="0x13" />
			<option name="Top, Left E" value="0x14" />
			<option name="Crosshair B" value="0x15" />
			<option name="Top, Left F" value="0x16" />
			<option name="Unknown" value="0x17" />
			<option name="Top, Left G" value="0x18" />
			<option name="Unknown" value="0x19" />
			<option name="Top, Left F" value="0x1A" />
			<option name="Score" value="0x1B" />
			<option name="Score B" value="0x1C" />
			<option name="Score C" value="0x1D" />
			<option name="Score D" value="0x1E" />
			<option name="Score E" value="0x1F" />
			<option name="Score F" value="0x20" />
			<option name="Score G" value="0x21" />
			<option name="Unknown" value="0x22" />
			<option name="Unknown" value="0x23" />
			<option name="Unknown" value="0x24" />
			<option name="Unknown" value="0x25" />
			<option name="Unknown" value="0x26" />
			<option name="Unknown" value="0x27" />
		</enum8>
		<int16 name="Unknown" offset="0x2" visible="false" />
		<float32 name="Mirror Offset X" offset="0x4" visible="true" />
		<float32 name="Mirror Offset Y" offset="0x8" visible="true" />
		<float32 name="Offset X" offset="0xC" visible="true" />
		<float32 name="Offset Y" offset="0x10" visible="true" />
		<float32 name="Scale X" offset="0x14" visible="true" />
		<float32 name="Scale Y" offset="0x18" visible="true" />
		*/
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(wpdt_block, 1, wpdt_struct_definition_struct_definition);

	TAG_STRUCT(wpdt_struct_definition)
	{
		{ _field_block, "placement data", &wpdt_placement_data_block_block },
		{ _field_terminator }
	};

	TAG_REFERENCE(chud_widget_placement_data_reference, CHUD_WIDGET_PLACEMENT_DATA_TAG);



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
