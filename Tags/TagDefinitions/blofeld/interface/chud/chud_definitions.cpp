#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{
	TAG_REFERENCE(unknown_reference);

	TAG_BLOCK(chad_size_block, 65536)
	{
		{ _field_block, "animation", &chad_size_animation_block_block },
		{ _field_data, "unknown" },
		{ _field_terminator }
	};
	TAG_BLOCK(chad_texture_coords_animation_block, 65536)
	{
		{ _field_real, "frame number" },
		{ _field_real, "movement 1 x" },
		{ _field_real, "movement 1 y" },
		{ _field_real, "movement 2 x" },
		{ _field_real, "movement 2 y" },
		{ _field_terminator }
	};
	TAG_BLOCK(chad_color_block, 65536)
	{
		{ _field_block, "animation", &chad_color_animation_block_block },
		{ _field_data, "function" },
		{ _field_terminator }
	};
	TAG_BLOCK(chad_position_animation_block, 65536)
	{
		{ _field_real, "frame number" },
		{ _field_real, "position x" },
		{ _field_real, "position y" },
		{ _field_real, "position z" },
		{ _field_terminator }
	};
	TAG_BLOCK(chad_alpha_animation_block, 65536)
	{
		{ _field_real, "frame number" },
		{ _field_real, "alpha" },
		{ _field_terminator }
	};
	TAG_BLOCK(chad_rotation_animation_block, 65536)
	{
		{ _field_real, "frame number" },
		{ _field_angle, "x angle" },
		{ _field_angle, "y angle" },
		{ _field_angle, "z angle" },
		{ _field_terminator }
	};
	TAG_BLOCK(chad_ammo_counter_block, 65536)
	{
		{ _field_real, "frame number" },
		{ _field_real, "boot progress fraction" },
		{ _field_terminator }
	};
	TAG_BLOCK(chad_color_animation_block, 65536)
	{
		{ _field_real, "frame number" },
		{ _field_terminator }
	};
	TAG_BLOCK(chad_ammo_counter_boot_block, 65536)
	{
		{ _field_block, "ammo counter", &chad_ammo_counter_block_block },
		{ _field_data, "function" },
		{ _field_terminator }
	};
	TAG_BLOCK(chad_size_animation_block, 65536)
	{
		{ _field_real, "frame number" },
		{ _field_real, "stretch x" },
		{ _field_real, "stretch y" },
		{ _field_terminator }
	};
	TAG_BLOCK(chad_position_block, 65536)
	{
		{ _field_block, "animation", &chad_position_animation_block_block },
		{ _field_data, "function" },
		{ _field_terminator }
	};
	TAG_BLOCK(chad_rotation_block, 65536)
	{
		{ _field_block, "animation", &chad_rotation_animation_block_block },
		{ _field_data, "function" },
		{ _field_terminator }
	};
	TAG_BLOCK(chad_alpha_block, 65536)
	{
		{ _field_block, "animation", &chad_alpha_animation_block_block },
		{ _field_data, "function" },
		{ _field_terminator }
	};
	TAG_BLOCK(chad_texture_coords_block, 65536)
	{
		{ _field_block, "animation", &chad_texture_coords_animation_block_block },
		{ _field_data, "function" },
		{ _field_terminator }
	};

	TAG_GROUP_FROM_BLOCK(chud_animation, CHUD_ANIMATION_TAG, chad_block_block);
	TAG_BLOCK_FROM_STRUCT(chad_block, 1, chad_struct_definition_struct_definition)
	TAG_STRUCT(chad_struct_definition)
	{
		{ _field_byte_flags, "flags", &chad_flags_definition },
		{ _field_byte_integer, "unknown" },
		{ _field_short_integer, "unknown" },
		{ _field_block, "position", &chad_position_block_block },
		{ _field_block, "rotation", &chad_rotation_block_block },
		{ _field_block, "size", &chad_size_block_block },
		{ _field_block, "color", &chad_color_block_block },
		{ _field_block, "alpha", &chad_alpha_block_block },
		{ _field_block, "alpha unknown", &chad_alpha_block_block },
		{ _field_block, "texture coordinates", &chad_texture_coords_block_block },
		{ _field_block, "ammo counter boot", &chad_ammo_counter_boot_block_block },
		{ _field_long_integer, "unknown animation block" },
		{ _field_long_integer, "unknown animation block" },
		{ _field_long_integer, "unknown animation block" },
		{ _field_real, "number of frames" },
		{ _field_terminator }
	};
	TAG_REFERENCE(chud_animation_reference, CHUD_ANIMATION_TAG);


	TAG_BLOCK(chdt_compiled_widget_data_block, 65536)
	{
		{ _field_char_enum, "special hud type", &chdt_special_hud_type_definition },
		{ _field_byte_flags, "unknown", &chdt_unknown_definition },
		{ _field_byte_integer, "unknown index?" },
		{ _field_byte_flags, "unknown", &chdt_unknown_definition },
		{ _field_real, "animation 1 frame count" },
		{ _field_real, "animation 2 frame count" },
		{ _field_real, "animation 3 frame count" },
		{ _field_real, "animation 4 frame count" },
		{ _field_real, "animation 5 frame count" },
		{ _field_enum, "input", &chdt_input_definition },
		{ _field_enum, "range input", &chdt_input_definition },
		{ _field_long_flags, "input variable triggers", &chdt_input_variable_triggers_definition },
		{ _field_char_enum, "second state-block start value", &chdt_second_state_block_start_value_definition },
		{ _field_char_enum, "third state-block start value", &chdt_second_state_block_start_value_definition },
		{ _field_short_integer, "0" },
		{ _field_short_integer, "1" },
		{ _field_short_integer, "2" },
		{ _field_short_integer, "3" },
		{ _field_short_integer, "4" },
		{ _field_short_integer, "5" },
		{ _field_short_integer, "6" },
		{ _field_short_integer, "7" },
		{ _field_short_integer, "8" },
		{ _field_short_integer, "9" },
		{ _field_short_integer, "10" },
		{ _field_short_integer, "11" },
		{ _field_short_integer, "12" },
		{ _field_short_integer, "13" },
		{ _field_short_integer, "14" },
		{ _field_short_integer, "15" },
		{ _field_short_integer, "16" },
		{ _field_short_integer, "17" },
		{ _field_short_integer, "18" },
		{ _field_short_integer, "19" },
		{ _field_short_integer, "20" },
		{ _field_short_integer, "21" },
		{ _field_short_integer, "22" },
		{ _field_short_integer, "23" },
		{ _field_short_integer, "24" },
		{ _field_short_integer, "25" },
		{ _field_short_integer, "26" },
		{ _field_short_integer, "27" },
		{ _field_short_integer, "28" },
		{ _field_terminator }
	};
	TAG_BLOCK(chdt_triggers_block, 65536)
	{
		{ _field_byte_flags, "flag", &chdt_flag_definition },

		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_long_integer, "trigger index" },
		{ _field_terminator }
	};
	TAG_BLOCK(chdt_yesno_states_block, 65536)
	{
		{ _field_block, "triggers", &chdt_triggers_block_block },
		{ _field_terminator }
	};
	TAG_BLOCK(chdt_placement_data_block, 65536)
	{
		{ _field_byte_flags, "unknown", & chdt_unknown_definition },
		{ _field_char_enum, "anchor", &chdt_anchor_definition },
		{ _field_short_integer, "unknown" },
		{ _field_real, "mirror offset x" },
		{ _field_real, "mirror offset y" },
		{ _field_real, "offset x" },
		{ _field_real, "offset y" },
		{ _field_real, "scale x" },
		{ _field_real, "scale y" },
		{ _field_terminator }
	};
	TAG_BLOCK(chdt_state_data_block, 65536)
	{
		{ _field_block, "'yes' states", &chdt_yesno_states_block_block },
		{ _field_block, "unknown states", &chdt_yesno_states_block_block },
		{ _field_block, "'no' states", &chdt_yesno_states_block_block },
		{ _field_short_integer, "unknown" },
		{ _field_short_integer, "unknown" },
		{ _field_short_integer, "unknown" },
		{ _field_short_integer, "unknown" },
		//{ undefined ooga booga, "unknown" },
		//{ undefined ooga booga, "unknown" },
		//{ undefined ooga booga, "unknown" },
		{ _field_terminator }
	};
	TAG_BLOCK(chdt_animation_data_block, 65536)
	{
		{ _field_byte_flags, "animation 1 flags", & chdt_animation_flags_definition },
		{ _field_char_enum, "animation 1 function", &chdt_animation_function_definition },
		{ _field_short_integer, "unknown" },
		{ _field_tag_reference, "animation 1", &chud_animation_reference },
		{ _field_byte_flags, "animation 2 flags", &chdt_animation_flags_definition },
		{ _field_char_enum, "animation 2 function", &chdt_animation_function_definition },
		{ _field_short_integer, "unknown" },
		{ _field_tag_reference, "animation 2", &chud_animation_reference },
		{ _field_byte_flags, "animation 3 flags", &chdt_animation_flags_definition },
		{ _field_char_enum, "animation 3 function", &chdt_animation_function_definition },
		{ _field_short_integer, "unknown" },
		{ _field_tag_reference, "animation 3", &chud_animation_reference },
		{ _field_byte_flags, "animation 4 flags", &chdt_animation_flags_definition },
		{ _field_char_enum, "animation 4 function", &chdt_animation_function_definition },
		{ _field_short_integer, "unknown" },
		{ _field_tag_reference, "animation 4", &chud_animation_reference },
		{ _field_byte_flags, "animation 5 flags", &chdt_animation_flags_definition },
		{ _field_char_enum, "animation 5 function", &chdt_animation_function_definition },
		{ _field_short_integer, "unknown" },
		{ _field_tag_reference, "animation 5", &chud_animation_reference },
		{ _field_terminator }
	};
	TAG_BLOCK(chdt_render_data_block, 65536)
	{
		{ _field_char_enum, "shader index", & chdt_shader_index_definition },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_real_argb_color, "local color a" },
		{ _field_real_argb_color, "local color b" },
		{ _field_real_argb_color, "local color c" },
		{ _field_real_argb_color, "local color d" },
		{ _field_real, "local scalar a" },
		{ _field_real, "local scalar b" },
		{ _field_real, "local scalar c" },
		{ _field_real, "local scalar d" },
		{ _field_enum, "output color a", &chdt_output_color_definition },
		{ _field_enum, "output color b", &chdt_output_color_definition },
		{ _field_enum, "output color c", &chdt_output_color_definition },
		{ _field_enum, "output color d", &chdt_output_color_definition },
		{ _field_enum, "output color e", &chdt_output_color_definition },
		{ _field_enum, "output color f", &chdt_output_color_definition },
		{ _field_enum, "output scalar a", &chdt_output_scalar_definition },
		{ _field_enum, "output scalar b", &chdt_output_scalar_definition },
		{ _field_enum, "output scalar c", &chdt_output_scalar_definition },
		{ _field_enum, "output scalar d", &chdt_output_scalar_definition },
		{ _field_enum, "output scalar e", &chdt_output_scalar_definition },
		{ _field_enum, "output scalar f", &chdt_output_scalar_definition },
		{ _field_long_integer, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_short_integer, "unknown" },
		{ _field_short_integer, "unknown" },
		{ _field_terminator }
	};
	TAG_BLOCK(chdt_unknown_block, 65536)
	{
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_terminator }
	};
	TAG_BLOCK(chdt_datasource_block, 65536)
	{
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_short_integer, "unknown" },
		{ _field_short_integer, "unknown" },
		//{ undefined ooga booga, "unknown" },
		//{ undefined ooga booga, "unknown" },
		//{ undefined ooga booga, "unknown" },
		{ _field_block, "unknown", &chdt_unknown_block_block },

		{ _field_terminator }
	};
	TAG_BLOCK(chdt_bitmap_widgets_block, 65536)
	{
		{ _field_string_id, "name" },
		{ _field_char_enum, "special hud type", &chdt_special_hud_type_definition },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_enum, "import input", &chdt_input_definition },
		{ _field_enum, "import range input", &chdt_input_definition },
		{ _field_tag_reference, "state data template", &chud_widget_state_data_reference },
		{ _field_block, "state data", &chdt_state_data_block_block },
		{ _field_tag_reference, "placement data template", &chud_widget_placement_data_reference },
		{ _field_block, "placement data", &chdt_placement_data_block_block },
		{ _field_tag_reference, "animation data template", &wadt_animation_reference },
		{ _field_block, "animation data", &chdt_animation_data_block_block },
		{ _field_tag_reference, "render data template", &chud_widget_render_data_reference },
		{ _field_block, "render data", &chdt_render_data_block_block },
		{ _field_long_flags, "flags", &chdt_flags_definition },
		{ _field_tag_reference, "bitmap", &global_bitmap_reference },
		{ _field_byte_integer, "bitmap sprite index" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_rectangle_2d, "manual texture coordinates#this defines the visible rectangle for the bitmap if the bit of the same name is set. for ammo counters, l/r should be a multiple of 8, and t/b a multiple of 12." },
		{ _field_terminator }
	};
	TAG_BLOCK(chdt_text_widgets_block, 65536)
	{
		{ _field_string_id, "name" },
		{ _field_char_enum, "special hud type", &chdt_special_hud_type_definition },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_enum, "import input", &chdt_input_definition },
		{ _field_enum, "import range input", &chdt_input_definition },
		{ _field_tag_reference, "state data template", &chud_widget_state_data_reference },
		{ _field_block, "state data", &chdt_state_data_block_block },
		{ _field_tag_reference, "placement data template", &chud_widget_placement_data_reference },
		{ _field_block, "placement data", &chdt_placement_data_block_block },
		{ _field_tag_reference, "animation data template", &wadt_animation_reference },
		{ _field_block, "animation data", &chdt_animation_data_block_block },
		{ _field_tag_reference, "render data template", &chud_widget_render_data_reference },
		{ _field_block, "render data", &chdt_render_data_block_block },
		{ _field_word_flags, "flags", &chdt_flags_definition },
		{ _field_enum, "font", &chdt_font_definition },
		{ _field_explanation, "string", "This value can be anything from the hud_messages unicode tag, or one of the following, where a - f correspond to Output Scalars a - f in the Render Data block :"
			"\nchud_out_a"
			"\nchud_out_b"
			"\nchud_out_c"
			"\nchud_out_d"
			"\nchud_out_e"
			"\nchud_out_f"
			"\nchud_variant_name"
			"\nchud_variant_objective_variant"
			"\nchud_variant_objective"
			"\nchud_variant_objective_designator"
			"\nchud_talking_player_name"
			"\nchud_arming_meter_name"
			"\nchud_time_left"
			"\nchud_training_text"
			"\nchud_nav_point"
			"\nchud_scripted_objective_text"
			"\nchud_scripted_chapter_title_text"
			"\nchud_scripted_training_text"
			"\nchud_campaign_objective_text"
			"\nchud_ft_member_1_name"
			"\nchud_ft_member_2_name"
			"\nchud_ft_member_3_name"
			"\nchud_ft_member_name"
			"\nchud_ft_member_1_kill_count"
			"\nchud_ft_member_2_kill_count"
			"\nchud_ft_member_3_kill_count"
			"\nchud_ft_member_kill_count"
			"\nchud_campaign_ft_member_1_name"
			"\nchud_campaign_ft_member_2_name"
			"\nchud_campaign_ft_member_3_name"
			"\nchud_campaign_ft_member_4_name"
			"\nchud_campaign_ft_member_5_name"
			"\nchud_campaign_ft_member_name"
			"\nchud_campaign_ft_member_1_service_tag"
			"\nchud_campaign_ft_member_2_service_tag"
			"\nchud_campaign_ft_member_3_service_tag"
			"\nchud_campaign_ft_member_4_service_tag"
			"\nchud_campaign_ft_member_5_service_tag"
			"\nchud_campaign_ft_member_service_tag"
			"\nchud_megalo_datasource_omni_widget_label"
			"\nchud_megalo_datasource_omni_widget_value"
			"\nchud_megalo_progress_bar_label"
			"\nchud_datasource_scripted_object_text"
			"\nchud_datasource_tracked_target_text"
			"\nchud_location_name"
			"\nchud_commendation_callout_text"
			"\nchud_datasource_progression_toast_text"
			"\nchud_datasource_scripted_object_priority_text"
			"\nchud_datasource_scripted_object_priority_description_text" },
		{ _field_string_id, "string" },
		{ _field_terminator }
	};
	TAG_BLOCK(chdt_hud_widgets_block, 65536)
	{
		{ _field_string_id, "name" },
		{ _field_char_enum, "special hud type", &chdt_special_hud_type_definition },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_enum, "import input", &chdt_input_definition },
		{ _field_enum, "import range input", &chdt_input_definition },
		{ _field_tag_reference, "state data template", &chud_widget_state_data_reference },
		{ _field_block, "state data", &chdt_state_data_block_block },
		{ _field_tag_reference, "placement data template", &chud_widget_placement_data_reference },
		{ _field_block, "placement data", &chdt_placement_data_block_block },
		{ _field_tag_reference, "animation data template", &wadt_animation_reference },
		{ _field_block, "animation data", &chdt_animation_data_block_block },
		{ _field_tag_reference, "render data template", &chud_widget_render_data_reference },
		{ _field_block, "render data", &chdt_render_data_block_block },
		{ _field_tag_reference, "datasource template", &unknown_reference },
		{ _field_block, "datasource", &chdt_datasource_block_block },
		{ _field_block, "bitmap widgets", &chdt_bitmap_widgets_block_block },
		{ _field_block, "text widgets", &chdt_text_widgets_block_block },
		{ _field_long_integer, "unknown text addition" },
		{ _field_short_integer, "unknown" },
		{ _field_short_integer, "unknown" },
		{ _field_short_integer, "unknown" },
		{ _field_short_integer, "unknown" },
		{ _field_char_enum, "second state-block starting value", &chdt_second_state_block_start_value_definition },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_word_flags, "input variable triggers", &chdt_input_variable_triggers_definition },
		{ _field_explanation, "Compiled States (HUD Widgets)", "Uses this format:"
		"\nStates(Yes, No) Count(\"Unknown\" States not used here!)"
		"\n		Then for every States count :"
		"\n-Triggers Count"
		"\n		Then for every Triggers count :"
		"\n-Trigger Index"
		"\n		Repeats for both States blocks.Use a 0 if the block is null."
		"\n		It is currently unknown what the criteria is for more than one \"X States\" index."
		"\n		Check existing tags for examples, good luck."},
		{ _field_short_integer, "0" },
		{ _field_short_integer, "1" },
		{ _field_short_integer, "2" },
		{ _field_short_integer, "3" },
		{ _field_short_integer, "4" },
		{ _field_short_integer, "5" },
		{ _field_short_integer, "6" },
		{ _field_short_integer, "7" },
		{ _field_short_integer, "8" },
		{ _field_short_integer, "9" },
		{ _field_short_integer, "10" },
		{ _field_short_integer, "11" },
		{ _field_short_integer, "12" },
		{ _field_terminator }
	};

	TAG_GROUP_FROM_BLOCK(chud, CHUD_TAG, chud_block_block);
	TAG_BLOCK_FROM_STRUCT(chud_block, 1, chud_struct_definition_struct_definition);
	TAG_STRUCT(chud_struct_definition)
	{
		{ _field_explanation, "Reach HUDs Are Annoying", "The inputs are not defined where they were for Halo 3, but instead are in the \"Compiled Widget Data\" block at the bottom, along with the 3 blocks within \"State Data\"."
			"...Unless the State Data block is part of HUD Widgets not Bitmap / Text Widgets, which THOSE states are defined at the bottom of the HUD Widgets block."
			"There is no outright index for Compiled Widget Data so use the Import Inputs / States and counting(Bitmap and Text Widgets only!) to find it."
			"Mapping the Trigger indexes will take time.There is a block at the bottom of CHGD with an unsorted list of triggers with a vague category, which has been sorted into a comment about the block."
			"As for Placement Data, each index likely refers to each \"HUD Attributes\" index in CHGD to change depending on resolution." },
		{ _field_explanation, "Render Data Shader Index", "While represented as an enum, it is actually an index to the \"HUD Shaders\" block in CHGD." },
		{ _field_explanation, "Placement Anchor", "Only select \"Use Parent Widget\" for a Bitmap or Text Widget, otherwise the game will crash." },
		{ _field_block, "hud widgets", & chdt_hud_widgets_block_block },
		{ _field_long_integer, "low clip cutoff" },
		{ _field_long_integer, "low ammo cutoff" },
		{ _field_long_integer, "age cutoff" },
		{ _field_long_integer, "sword age cutoff" },
		{ _field_block, "compiled widget data", &chdt_compiled_widget_data_block_block },
		{ _field_terminator }
	};
	TAG_REFERENCE(chud_reference, CHUD_TAG);


	TAG_BLOCK(chgd_hud_sounds_block, 65536)
	{
		{ _field_tag_reference, "sound", &global_sound_reference },
		{ _field_long_flags, "latched to", &latched_to_flags_definition },
		{ _field_real, "Scale" },
		{ _field_terminator }
	};
	TAG_BLOCK(chgd_hud_attributes_block, 65536)
	{
		{ _field_byte_flags, "resolution flags", &resolution_flags_definition },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "horizontal roll" },
		{ _field_real, "vertical bow" },
		{ _field_real, "inverse horizontal roll" },
		{ _field_real, "inverse vertical bow" },
		{ _field_real, "horizontal roll 2" },
		{ _field_real, "vertical bow 2" },
		{ _field_real, "horizontal twist" },
		{ _field_real, "vertical twist" },
		{ _field_real, "horizontal twist 2" },
		{ _field_real, "vertical twist 2" },
		{ _field_real, "vertical scale" },
		{ _field_real, "vertical twist 3" },
		{ _field_real, "horizontal skew" },
		{ _field_real, "vertical flip" },
		{ _field_real, "inverse horizontal skew" },
		{ _field_real, "vertical flip 2" },
		{ _field_real, "hud offset x" },
		{ _field_real, "hud offset y" },
		{ _field_long_integer, "resolution width" },
		{ _field_long_integer, "resolution height" },
		{ _field_real, "motion sensor offset x" },
		{ _field_real, "motion sensor offset y" },
		{ _field_real, "unknown" },
		{ _field_real, "motion sensor radius" },
		{ _field_real, "motion sensor scale" },
		{ _field_long_integer, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_real, "horizontal scale" },
		{ _field_real, "vertical scale" },
		{ _field_real, "horizontal stretch" },
		{ _field_real, "vertical stretch" },
		{ _field_real, "notification offset x" },
		{ _field_real, "notification offset y" },
		{ _field_real, "state left/right offset y" },
		{ _field_real, "state center offset y" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "state scale" },
		{ _field_real, "notification scale" },
		{ _field_real, "notification line spacing" },
		{ _field_long_integer, "notification line count modifier" },
		{ _field_terminator }
	};
	TAG_BLOCK(chgd_waypoint_blips_block, 65536)
	{
		{ _field_string_id, "title" },
		{ _field_string_id, "description" },
		{ _field_char_enum, "icon", &icon_enum_definition },
		{ _field_byte_integer, "unknown" },
		{ _field_short_integer, "unknown" },
		{ _field_real_argb_color, "primary color" },
		{ _field_real_argb_color, "secondary color" },
		{ _field_terminator }
	};
	TAG_BLOCK(chgd_hud_globals_block, 65536)
	{
		{ _field_long_enum, "biped", &biped_enum_definition },
		{ _field_real_argb_color, "0 [HUD disabled]" },
		{ _field_real_argb_color, "1 [HUD primary]" },
		{ _field_real_argb_color, "2 [HUD foreground]" },
		{ _field_real_argb_color, "3 [HUD warning]" },
		{ _field_real_argb_color, "4 [neutral reticule]" },
		{ _field_real_argb_color, "5 [hostile reticule]" },
		{ _field_real_argb_color, "6 [friendly reticule]" },
		{ _field_real_argb_color, "7" },
		{ _field_real_argb_color, "8" },
		{ _field_real_argb_color, "9" },
		{ _field_real_argb_color, "10" },
		{ _field_real_argb_color, "11" },
		{ _field_real_argb_color, "12" },
		{ _field_real_argb_color, "13" },
		{ _field_real_argb_color, "14" },
		{ _field_real_argb_color, "15" },
		{ _field_real_argb_color, "16" },
		{ _field_real_argb_color, "17" },
		{ _field_real_argb_color, "18" },
		{ _field_real_argb_color, "19" },
		{ _field_real_argb_color, "20" },
		{ _field_real_argb_color, "21" },
		{ _field_real_argb_color, "22" },
		{ _field_real_argb_color, "23" },
		{ _field_real_argb_color, "24" },
		{ _field_real_argb_color, "25" },
		{ _field_real_argb_color, "26" },
		{ _field_real_argb_color, "27" },
		{ _field_real_argb_color, "28" },
		{ _field_real_argb_color, "29" },
		{ _field_real_argb_color, "30" },
		{ _field_real_argb_color, "31" },
		{ _field_data, "32" },
		{ _field_data, "33" },
		{ _field_data, "34" },
		{ _field_data, "35" },
		{ _field_data, "36" },
		{ _field_data, "37" },
		{ _field_data, "38" },
		{ _field_data, "39" },
		{ _field_data, "40" },
		{ _field_data, "41" },
		{ _field_real, "blip above threshold max" },
		{ _field_real, "blip above threshold min" },
		{ _field_real, "blip below threshold min" },
		{ _field_real, "blip below threshold max" },
		{ _field_block, "HUD attributes", &chgd_hud_attributes_block_block },
		{ _field_block, "HUD sounds", &chgd_hud_sounds_block_block },
		{ _field_pad, "unknown", 4 },
		{ _field_tag_reference, "unknown", &global_sound_reference },
		{ _field_tag_reference, "frag grenade swap sound", &global_sound_reference },
		{ _field_tag_reference, "plasma grenade swap sound", &global_sound_reference },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_tag_reference, "damage microtexture", &global_bitmap_reference },
		{ _field_real, "microtexture tile scale" },
		{ _field_real, "microtexture screen fraction" },
		{ _field_real, "microtexture inner intensity" },
		{ _field_real, "microtexture center screen fraction" },
		{ _field_real, "microtexture outer intensity" },
		{ _field_tag_reference, "unknown", &global_bitmap_reference },
		{ _field_tag_reference, "directional arrow", &global_bitmap_reference },
		{ _field_tag_reference, "directional fast forward arrow", &global_bitmap_reference },
		{ _field_tag_reference, "unknown", &global_bitmap_reference },
		{ _field_tag_reference, "unknown", &global_bitmap_reference },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_data, "unknown" },
		{ _field_tag_reference, "waypoints", &global_bitmap_reference },
		{ _field_tag_reference, "scoreboard HUD", &chud_reference },
		{ _field_tag_reference, "uber scoreboard HUD", &chud_reference },
		{ _field_tag_reference, "metagame scoreboard HUD", &chud_reference },
		{ _field_tag_reference, "survival scoreboard HUD", &chud_reference },
		{ _field_tag_reference, "theater HUD", &chud_reference },
		{ _field_tag_reference, "forge HUD", &chud_reference },
		{ _field_tag_reference, "HUD strings", &global_multilingual_unicode_string_list_reference },
		{ _field_tag_reference, "medals", &global_bitmap_reference },
		{ _field_tag_reference, "medal HUD animation", &chud_animation_reference },
		{ _field_tag_reference, "cortana channel", &unknown_reference },
		{ _field_tag_reference, "unknown", &unknown_reference },
		{ _field_tag_reference, "unknown", &unknown_reference },
		{ _field_tag_reference, "tracker noise flash response", &unknown_reference },
		{ _field_tag_reference, "tracker noise flash sound", &unknown_reference },
		{ _field_real, "grenade scematics spacing" },
		{ _field_real, "equipment scematic offset y" },
		{ _field_real, "dual equipment scematic offset y" },
		{ _field_real, "unknown equipment related" },
		{ _field_real, "unknown equipment related" },
		{ _field_real, "scoreboard leader offset y" },
		{ _field_real, "unknown" },
		{ _field_real, "waypoint scale" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real_argb_color, "color" },
		{ _field_real, "minor threshold" },
		{ _field_real, "major threshold" },
		{ _field_real, "critical threshold" },
		{ _field_data, "function" },
		{ _field_data, "function" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real_argb_color, "color" },
		{ _field_real, "minor threshold" },
		{ _field_real, "major threshold" },
		{ _field_real, "critical threshold" },
		{ _field_data, "function" },
		{ _field_data, "function" },
		{ _field_block, "waypoint blips", &chgd_waypoint_blips_block_block },
		{ _field_terminator }
	};
	TAG_BLOCK(chgd_shaders_block, 65536)
	{
		{ _field_tag_reference, "vertex shader", & global_vertex_shader_reference },
		{ _field_tag_reference, "pixel shader", &global_pixel_shader_reference },
		{ _field_terminator }
	};
	TAG_BLOCK(chgd_unknown_block, 65536)
	{
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_terminator }
	};
	TAG_BLOCK(chgd_player_training_data_block, 65536)
	{
		{ _field_string_id, "Display String" },
		{ _field_short_integer, "Max Display Time" },
		{ _field_short_integer, "Display Count" },
		{ _field_short_integer, "Disappear Delay" },
		{ _field_short_integer, "Redisplay Delay" },
		{ _field_real, "Display Delay" },
		{ _field_word_flags, "flags", &player_training_flags_definition },
		{ _field_short_integer, "Unknown" },
		{ _field_terminator }
	};
	TAG_BLOCK(chgd_state_triggers_block, 65536)
	{
		{ _field_long_integer, "trigger index" },
		{ _field_string, "type" },
		{ _field_terminator }
	};

	TAG_GROUP_FROM_BLOCK(chud_globals, CHUD_GLOBALS_TAG, chgd_block_block);
	TAG_BLOCK_FROM_STRUCT(chgd_block, 1, chgd_struct_definition_struct_definition);
	TAG_STRUCT(chgd_struct_definition)
	{
		{ _field_block, "hud globals", &chgd_hud_globals_block_block },
		{ _field_block, "shaders", &chgd_shaders_block_block },
		{ _field_block, "unknown", &chgd_unknown_block_block },
		{ _field_block, "player training data", &chgd_player_training_data_block_block },
		{ _field_tag_reference, "start menu emblems", &global_bitmap_reference },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_real, "campaign medal scale" },
		{ _field_real, "campaign medal spacing" },
		{ _field_real, "campaign medal offset x" },
		{ _field_real, "campaign medal offset y" },
		{ _field_real, "metagame scoreboard top y" },
		{ _field_real, "metagame scoreboard spacing" },
		{ _field_tag_reference, "unknown", &unknown_reference },
		{ _field_long_integer, "unknown@" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_real, "medium sensor blip scale" },
		{ _field_real, "small sensor blip scale" },
		{ _field_real, "large sensor blip scale" },
		{ _field_real, "vehicle sensor range" },
		{ _field_real, "sensor angle" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_data, "unknown" },
		{ _field_data, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_tag_reference, "motion sensor triangulation field", &global_bitmap_reference },
		{ _field_tag_reference, "motion sensor blip", &global_bitmap_reference },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_real, "unknown" },
		{ _field_tag_reference, "unknown", &unknown_reference },
		{ _field_long_integer, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_real, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_real, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_real, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "alpha?" },
		{ _field_real, "r?" },
		{ _field_real, "g?" },
		{ _field_real, "b?" },
		{ _field_real, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_real, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_tag_reference, "unknown waypoint bitmap", &global_bitmap_reference },
		{ _field_byte_integer, "sequence index" },
		{ _field_byte_integer, "sprite index" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_tag_reference, "unknown waypoint bitmap", &global_bitmap_reference },
		{ _field_byte_integer, "sequence index" },
		{ _field_byte_integer, "sprite index" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_tag_reference, "unknown waypoint bitmap", &global_bitmap_reference },
		{ _field_byte_integer, "sequence index" },
		{ _field_byte_integer, "sprite index" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_tag_reference, "unknown waypoint bitmap", &global_bitmap_reference },
		{ _field_byte_integer, "sequence index" },
		{ _field_byte_integer, "sprite index" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_tag_reference, "unknown waypoint bitmap", &global_bitmap_reference },
		{ _field_byte_integer, "sequence index" },
		{ _field_byte_integer, "sprite index" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_tag_reference, "unknown waypoint bitmap", &global_bitmap_reference },
		{ _field_byte_integer, "sequence index" },
		{ _field_byte_integer, "sprite index" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_tag_reference, "unknown waypoint bitmap", &global_bitmap_reference },
		{ _field_byte_integer, "sequence index" },
		{ _field_byte_integer, "sprite index" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_tag_reference, "unknown waypoint bitmap", &global_bitmap_reference },
		{ _field_byte_integer, "sequence index" },
		{ _field_byte_integer, "sprite index" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_tag_reference, "unknown waypoint bitmap", &global_bitmap_reference },
		{ _field_byte_integer, "sequence index" },
		{ _field_byte_integer, "sprite index" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_tag_reference, "unknown waypoint bitmap", &global_bitmap_reference },
		{ _field_byte_integer, "sequence index" },
		{ _field_byte_integer, "sprite index" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_tag_reference, "unknown waypoint bitmap", &global_bitmap_reference },
		{ _field_byte_integer, "sequence index" },
		{ _field_byte_integer, "sprite index" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_tag_reference, "unknown waypoint bitmap", &global_bitmap_reference },
		{ _field_byte_integer, "sequence index" },
		{ _field_byte_integer, "sprite index" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_tag_reference, "unknown waypoint bitmap", &global_bitmap_reference },
		{ _field_byte_integer, "sequence index" },
		{ _field_byte_integer, "sprite index" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_tag_reference, "unknown waypoint bitmap", &global_bitmap_reference },
		{ _field_byte_integer, "sequence index" },
		{ _field_byte_integer, "sprite index" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_tag_reference, "unknown waypoint bitmap", &global_bitmap_reference },
		{ _field_byte_integer, "sequence index" },
		{ _field_byte_integer, "sprite index" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_tag_reference, "unknown waypoint bitmap", &global_bitmap_reference },
		{ _field_byte_integer, "sequence index" },
		{ _field_byte_integer, "sprite index" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_tag_reference, "unknown waypoint bitmap", &global_bitmap_reference },
		{ _field_byte_integer, "sequence index" },
		{ _field_byte_integer, "sprite index" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_tag_reference, "unknown waypoint bitmap", &global_bitmap_reference },
		{ _field_byte_integer, "sequence index" },
		{ _field_byte_integer, "sprite index" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_tag_reference, "unknown waypoint bitmap", &global_bitmap_reference },
		{ _field_byte_integer, "sequence index" },
		{ _field_byte_integer, "sprite index" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_tag_reference, "unknown waypoint bitmap", &global_bitmap_reference },
		{ _field_byte_integer, "sequence index" },
		{ _field_byte_integer, "sprite index" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_tag_reference, "unknown waypoint bitmap", &global_bitmap_reference },
		{ _field_byte_integer, "sequence index" },
		{ _field_byte_integer, "sprite index" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_tag_reference, "unknown waypoint bitmap", &global_bitmap_reference },
		{ _field_byte_integer, "sequence index" },
		{ _field_byte_integer, "sprite index" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_tag_reference, "unknown waypoint bitmap", &global_bitmap_reference },
		{ _field_byte_integer, "sequence index" },
		{ _field_byte_integer, "sprite index" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_tag_reference, "unknown waypoint bitmap", &global_bitmap_reference },
		{ _field_byte_integer, "sequence index" },
		{ _field_byte_integer, "sprite index" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_tag_reference, "unknown waypoint bitmap", &global_bitmap_reference },
		{ _field_byte_integer, "sequence index" },
		{ _field_byte_integer, "sprite index" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_tag_reference, "unknown waypoint bitmap", &global_bitmap_reference },
		{ _field_byte_integer, "sequence index" },
		{ _field_byte_integer, "sprite index" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_explanation, "state triggers list (the below block, sorted)",
"0   general game state/weapon state"
"\n1   general / fireteam member state"
"\n2   general"
"\n3   general"
"\n4   general"
"\n5   general"
"\n6   general"
"\n7   unknown"
"\n8   campaign game state"
"\n9   campaign game state"
"\n10   campaign game state - mission hud 1"
"\n11   campaign game state - mission hud 2"
"\n12   campaign game state - mission hud 3"
"\n13   unknown"
"\n14   unknown"
"\n15   unknown"
"\n16   unknown"
"\n17   unknown"
"\n18   unit state - training prompt"
"\n19   unit state - objective prompt"
"\n20   unknown"
"\n21   unit state - spartan fireteams"
"\n22   unit state - elite fireteams"
"\n23   unit state"
"\n24   unit state"
"\n25   general / unit state"
"\n26   unit state"
"\n27   unit state"
"\n28   unit state"
"\n29   unit state"
"\n30   unit state"
"\n31   unit state"
"\n32   unit state - has shields"
"\n33   unit state - has 1x overshield"
"\n34   unit state - has 2x overshield"
"\n35   unit state - has 3x overshield"
"\n36   unit state"
"\n37   unit state"
"\n38   unit state - motion tracker 10m"
"\n39   unit state - motion tracker 25m"
"\n40   unit state - motion tracker 75m"
"\n41   unit state - motion tracker 150m"
"\n42   unit state"
"\n43   unit state"
"\n44   unit state"
"\n45   unit state"
"\n46   campaign game state - motion tracker enabled"
"\n47   unit state - motion tracker disabled"
"\n48   unit state"
"\n49   unit state"
"\n50   unit state"
"\n51   unit state"
"\n52   unit state"
"\n53   unknown"
"\n54   unknown"
"\n55   unit state"
"\n56   unit state"
"\n57   unknown"
"\n58   unit state"
"\n59   unit state"
"\n60   unit state"
"\n61   unit state - talking disabled"
"\n62   unit state - tap to talk"
"\n63   unit state - talking"
"\n64   unit state - not talking"
"\n65   unit state - talking enabled"
"\n66   campaign game state"
"\n67   unknown"
"\n68   unknown"
"\n69   unknown"
"\n70   unknown"
"\n71   unknown"
"\n72   weapon state"
"\n73   weapon state"
"\n74   unit state"
"\n75   unit state"
"\n76   unit state"
"\n77   unit state - out of bounds"
"\n78   unit state - altitude locked"
"\n79   unknown"
"\n80   unknown"
"\n81   unknown"
"\n82   weapon state"
"\n83   weapon state - binoculars enabled"
"\n84   weapon state - not zoomed ?"
"\n85   weapon state - unit is zoomed(level 1)"
"\n86   weapon state - unit is zoomed(level 2)"
"\n87   weapon state"
"\n88   weapon state"
"\n89   weapon state"
"\n90   weapon state"
"\n91   weapon state - autoaimed ?"
"\n92   weapon state"
"\n93   weapon state"
"\n94   weapon state"
"\n95   weapon state"
"\n96   weapon state"
"\n97   weapon state - primary weapon"
"\n98   weapon state - secondary weapon"
"\n99   weapon state - backpack"
"\n100   weapon state"
"\n101   weapon state"
"\n102   weapon state"
"\n103   weapon state - autoaim headshot"
"\n104   weapon state"
"\n105   weapon state"
"\n106   weapon state"
"\n107   weapon state - clip warning"
"\n108   weapon state - ammo warning"
"\n109   weapon state"
"\n110   weapon state"
"\n111   weapon state - low battery 1"
"\n112   weapon state - low battery 2"
"\n113   weapon state - overheated"
"\n114   weapon state - plasma locking"
"\n115   weapon state - missile locked"
"\n116   weapon state - missile locking"
"\n117   weapon state"
"\n118   weapon state"
"\n119   weapon state - pickup ammo"
"\n120   general game state"
"\n121   general game state"
"\n122   general game state"
"\n123   general game state"
"\n124   general game state / campaign fireteams"
"\n125   campaign fireteams"
"\n126   campaign fireteams"
"\n127   campaign fireteams"
"\n128   campaign fireteams"
"\n129   campaign fireteams"
"\n130   campaign fireteams"
"\n131   campaign fireteams"
"\n132   campaign fireteams"
"\n133   campaign fireteams"
"\n134   campaign fireteams"
"\n135   campaign fireteams"
"\n136   campaign fireteams"
"\n137   campaign fireteams"
"\n138   campaign fireteams"
"\n139   campaign fireteams"
"\n140   campaign fireteams"
"\n141   campaign fireteams"
"\n142   campaign fireteams"
"\n143   campaign fireteams"
"\n144   campaign fireteams"
"\n145   campaign fireteams"
"\n146   campaign fireteams"
"\n147   campaign fireteams"
"\n148   awards"
"\n149   awards"
"\n150   awards"
"\n151   awards"
"\n152   awards"
"\n153   awards"
"\n154   awards"
"\n155   awards"
"\n156   awards"
"\n157   datasource objects and players"
"\n158   datasource objects and players"
"\n159   datasource objects and players"
"\n160   datasource objects and players"
"\n161   datasource objects and players"
"\n162   datasource objects and players"
"\n163   datasource objects and players"
"\n164   datasource objects and players"
"\n165   datasource objects and players"
"\n166   datasource objects and players"
"\n167   datasource objects and players"
"\n168   datasource objects and players"
"\n169   general game state"
"\n170   awards"
"\n171   awards"
"\n172   awards"
"\n173   awards"
"\n174   awards"
"\n175   awards"
"\n176   awards"
"\n177   awards - credits awarded"
"\n178   campaign game state"
"\n179   campaign game state"
"\n180   firefight"
"\n181   general game state"
"\n182   general game state"
"\n183   general game state"
"\n184   general game state"
"\n185   campaign game state"
"\n186   campaign game state / firefight"
"\n187   campaign game state / firefight"
"\n188   campaign game state"
"\n189   campaign game state - player 2 exists"
"\n190   campaign game state"
"\n191   campaign game state - player 3 exists"
"\n192   campaign game state"
"\n193   campaign game state - player 4 exists"
"\n194   campaign game state"
"\n195   campaign game state - score added"
"\n196   campaign game state"
"\n197   campaign game state - score removed"
"\n198   campaign game state"
"\n199   campaign game state"
"\n200   datasource objects and players - generators enabled"
"\n201   datasource objects and players"
"\n202   datasource objects and players"
"\n203   datasource objects and players"
"\n204   datasource objects and players"
"\n205   datasource objects and players"
"\n206   datasource objects and players"
"\n207   datasource objects and players"
"\n208   datasource objects and players"
"\n209   datasource objects and players"
"\n210   datasource objects and players"
"\n211   datasource objects and players"
"\n212   datasource objects and players"
"\n213   datasource objects and players"
"\n214   datasource objects and players"
"\n215   datasource objects and players"
"\n216   datasource objects and players"
"\n217   datasource objects and players"
"\n218   datasource objects and players"
"\n219   datasource objects and players"
"\n220   datasource objects and players"
"\n221   datasource objects and players"
"\n222   datasource objects and players"
"\n223   datasource objects and players"
"\n224   datasource objects and players"
"\n225   datasource objects and players"
"\n226   datasource objects and players"
"\n227   datasource objects and players"
"\n228   datasource objects and players"
"\n229   datasource objects and players"
"\n230   datasource objects and players"
"\n231   datasource objects and players"
"\n232   datasource objects and players"
"\n233   datasource objects and players"
"\n234   datasource objects and players"
"\n235   firefight - waves background"
"\n236   firefight - wave 1"
"\n237   firefight - wave 2"
"\n238   firefight - wave 3"
"\n239   firefight - wave 4"
"\n240   firefight - wave 5"
"\n241   firefight"
"\n242   firefight"
"\n243   firefight"
"\n244   firefight"
"\n245   firefight - round 0"
"\n246   firefight - round 1"
"\n247   firefight - round 2"
"\n248   firefight - round 3"
"\n249   firefight"
"\n250   firefight"
"\n251   firefight"
"\n252   firefight"
"\n253   firefight"
"\n254   firefight"
"\n255   firefight"
"\n256   firefight"
"\n257   firefight"
"\n258   firefight"
"\n259   firefight"
"\n260   firefight"
"\n261   firefight"
"\n262   firefight - bonus round enabled"
"\n263   multiplayer game engine state - free for all"
"\n264   multiplayer game engine state - teams enabled"
"\n265   multiplayer game engine state"
"\n266   megalo"
"\n267   multiplayer game engine state"
"\n268   multiplayer game engine state"
"\n269   multiplayer game engine state"
"\n270   multiplayer game engine state"
"\n271   multiplayer game engine state"
"\n272   multiplayer game engine state - has friends"
"\n273   multiplayer game engine state - has enemies"
"\n274   multiplayer game engine state - has variant name ?"
"\n275   multiplayer game engine state - gametype plate 1"
"\n276   multiplayer game engine state - gametype plate 2"
"\n277   multiplayer game engine state - someone is talking"
"\n278   multiplayer game engine state - is arming"
"\n279   multiplayer game engine state - time enabled"
"\n280   multiplayer game engine state - friends have x"
"\n281   multiplayer game engine state - enemies have x"
"\n282   multiplayer game engine state - friends are x"
"\n283   multiplayer game engine state - enemies are x"
"\n284   multiplayer game engine state - x is down"
"\n285   multiplayer game engine state"
"\n286   multiplayer game engine state"
"\n287   multiplayer game engine state"
"\n288   multiplayer game engine state - summary enabled"
"\n289   multiplayer game engine state - netdebug"
"\n290   megalo - omniwidget enabled"
"\n291   megalo - omniwidget label"
"\n292   megalo - omniwidget value"
"\n293   megalo - omniwidget meter"
"\n294   megalo - omniwidget icon"
"\n295   megalo"
"\n296   fireteam member state"
"\n297   fireteam member state - someone is spawning on you"
"\n298   fireteam member state"
"\n299   fireteam member state"
"\n300   fireteam member state"
"\n301   fireteam member state"
"\n302   fireteam member state"
"\n303   fireteam member state"
"\n304   fireteam member state"
"\n305   fireteam member state"
"\n306   fireteam member state"
"\n307   fireteam member state"
"\n308   fireteam member state"
"\n309   fireteam member state"
"\n310   fireteam member state"
"\n311   fireteam member state"
"\n312   fireteam member state"
"\n313   fireteam member state"
"\n314   fireteam member state"
"\n315   fireteam member state"
"\n316   fireteam member state"
"\n317   fireteam member state"
"\n318   fireteam member state"
"\n319   forge state - is editor biped"
"\n320   weapon state - editor inactive"
"\n321   weapon state - editor active"
"\n322   weapon state - editor holding"
"\n323   weapon state - editor not allowed"
"\n324   weapon state"
"\n325   saved film state - is theater"
"\n326   saved film state"
"\n327   saved film state" },
		{ _field_block, "state triggers", &chgd_state_triggers_block_block },
		{ _field_terminator }
	};
	TAG_REFERENCE(chud_globals_reference, CHUD_GLOBALS_TAG);


	STRINGS(biped_enum_definition)
	{
		"spartan",
		"elite",
		"monitor",
	};
	STRING_LIST(biped_enum_definition, biped_enum_definition_strings, _countof(biped_enum_definition_strings));
	
	STRINGS(resolution_flags_definition)
	{
		"wide full",
		"standard full",
		"wide/standard half",
		"wide quarter",
		"standard quarter",
		"bit 5",
		"bit 6",
		"bit 7",
	};
	STRING_LIST(resolution_flags_definition, resolution_flags_definition_strings, _countof(resolution_flags_definition_strings));

	STRINGS(latched_to_flags_definition)
	{
		"health recharging",
		"health minor",
		"health major",
		"health critical",
		"health low minor",
		"health low major",
		"health low critical",
		"shield recharging",
		"shield minor",
		"shield major",
		"shield critical",
		"shield minor state",
		"shield major state",
		"shield critical state",
		"rocket locking",
		"rocket locked",
		"missile locking",
		"missile locked",
		"bit 18",
		"bit 19",
		"bit 20",
		"bit 21",
		"bit 22",
		"bit 23",
		"bit 24",
		"bit 25",
		"bit 26",
		"bit 27",
		"bit 28",
		"bit 29",
		"bit 30",
		"bit 31",
	};
	STRING_LIST(latched_to_flags_definition, latched_to_flags_definition_strings, _countof(latched_to_flags_definition_strings));

	STRINGS(icon_enum_definition)
	{
		"null",
		"neutralize",
		"defend",
		"ordnance",
		"interface",
		"scope",
		"recover",
		"arrow",
		"hostile",
		"ammo",
		"recon",
		"structure",
		"blank",
	};
	STRING_LIST(icon_enum_definition, icon_enum_definition_strings, _countof(icon_enum_definition_strings));

	STRINGS(player_training_flags_definition)
	{
		"not in multiplayer",
		"bit 1",
		"bit 2",
		"bit 3",
		"bit 4",
		"bit 5",
		"bit 6",
		"bit 7",
		"bit 8",
		"bit 9",
		"bit 10",
		"bit 11",
		"bit 12",
		"bit 13",
		"bit 14",
		"bit 15",
	};
	STRING_LIST(player_training_flags_definition, player_training_flags_definition_strings, _countof(player_training_flags_definition_strings));

	STRINGS(chdt_special_hud_type_definition)
	{
		"unspecial",
		"ammo",
		"crosshair and scope",
		"unit shield meter",
		"grenades",
		"gametype",
		"motion sensor",
		"unknown",
		"m70_bonus",
	};
	STRING_LIST(chdt_special_hud_type_definition, chdt_special_hud_type_definition_strings, _countof(chdt_special_hud_type_definition_strings));

	STRINGS(chdt_input_definition)
	{
		"zero",
		"one",
		"unknown 2",
		"unknown 3",
		"unknown 4",
		"time",
		"fade",
		"unknown 7",
		"unknown 8",
		"unknown 9",
		"unknown 10",
		"unknown 11",
		"unknown 12",
		"unknown 13",
		"unknown 14",
		"unknown 15",
		"unknown 16",
		"unknown 17",
		"unknown 18",
		"unknown 19",
		"unknown 20",
		"saber unknown 1",
		"vehicle health current percentage",
		"unit health current",
		"unit health",
		"unit shield current",
		"unit 1x overshield current",
		"unit 2x overshield current",
		"unit 2x overshield current",
		"unit shield",
		"unit 1x overshield",
		"unit 2x overshield",
		"unit 3x overshield",
		"unit shield current percentage",
		"vehicle shield current percentage",
		"boost energy fraction",
		"unknown 36",
		"aim yaw",
		"aim pitch",
		"saber waypoint distance",
		"sensor range",
		"unit altitude 1",
		"unit altitude 2",
		"unknown 43",
		"softkill timer",
		"transient credits",
		"unknown 46",
		"clip ammo fraction",
		"total ammo fraction",
		"pickup",
		"heat fraction",
		"airstrike charge fraction",
		"battery fraction",
		"deprecated",
		"unknown 54",
		"weapon error",
		"unknown weapon error",
		"unit autoaimed",
		"saber waypoint distance current",
		"airstrike distance",
		"nav point airstrike",
		"airstrike ammo",
		"unknown 62",
		"unknown 63",
		"grenade fraction",
		"unknown 65",
		"charge fraction",
		"unknown 67",
		"trigger cooldown",
		"trigger remote detonate fraction",
		"trigger locked on",
		"target distance",
		"target elevation",
		"equipment energy fraction",
		"unknown 74",
		"unknown 75",
		"unknown 76",
		"unknown 77",
		"unknown 78",
		"unknown 79",
		"medal commendation",
		"generator health current",
		"generator health",
		"unknown 83",
		"waypoint",
		"unknown 85",
		"unknown 86",
		"waypoint onscreen",
		"waypoint offscreen",
		"gametype plate",
		"offense defense",
		"metagame time",
		"metagame score transient",
		"metagame score player 1",
		"unknown 94",
		"unknown 95",
		"unknown 96",
		"unknown 97",
		"unknown 98",
		"unknown 99",
		"survival multiplier",
		"metagame score negative",
		"survival set",
		"unknown 103",
		"survival waves background",
		"survival lives 1",
		"survival lives 2",
		"survival bonus timer",
		"unknown 108",
		"unknown 109",
		"friendly score",
		"enemy score",
		"score to win",
		"arming fraction",
		"posession icon",
		"arming unknown",
		"omniwidget icon",
		"unknown 117",
		"fireteam health",
		"unknown 119",
		"unknown 120",
		"unknown 121",
		"fireteam current shield",
		"unknown 123",
		"unknown 124",
		"fireteam 1 arming fraction",
		"fireteam 2 arming fraction",
		"unknown 127",
		"fireteam 1 directional arrow",
		"fireteam 2 directional arrow",
		"unknown 130",
		"unknown 131",
		"unknown 132",
		"unknown 133",
		"unknown 134",
		"unknown 135",
		"unknown 136",
		"unknown 137",
		"editor budget",
		"editor budget cost",
		"film total time",
		"film current time",
		"deprecated",
		"film timeline last marker fraction",
		"film timeline fraction",
		"unknown 145",
		"deprecated",
		"netdebug latency",
		"netdebug latency quality",
		"netdebug host quality",
		"netdebug local quality",
	};
	STRING_LIST(chdt_input_definition, chdt_input_definition_strings, _countof(chdt_input_definition_strings));

	STRINGS(chdt_flag_definition)
	{
		"input variable",
	};
	STRING_LIST(chdt_flag_definition, chdt_flag_definition_strings, _countof(chdt_flag_definition_strings));

	STRINGS(chdt_unknown_definition)
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
	STRING_LIST(chdt_unknown_definition, chdt_unknown_definition_strings, _countof(chdt_unknown_definition_strings));

	STRINGS(chdt_anchor_definition)
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
		"use parent widget",
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
	STRING_LIST(chdt_anchor_definition, chdt_anchor_definition_strings, _countof(chdt_anchor_definition_strings));

	STRINGS(chdt_animation_function_definition)
	{
		"default",
		"use input",
		"use range input",
		"zero",
	};
	STRING_LIST(chdt_animation_function_definition, chdt_animation_function_definition_strings, _countof(chdt_animation_function_definition_strings));

	STRINGS(chdt_animation_flags_definition)
	{
		"reverse frames",
	};
	STRING_LIST(chdt_animation_flags_definition, chdt_animation_flags_definition_strings, _countof(chdt_animation_flags_definition_strings));

	STRINGS(chdt_shader_index_definition)
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
	STRING_LIST(chdt_shader_index_definition, chdt_shader_index_definition_strings, _countof(chdt_shader_index_definition_strings));

	STRINGS(chdt_output_color_definition)
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
	STRING_LIST(chdt_output_color_definition, chdt_output_color_definition_strings, _countof(chdt_output_color_definition_strings));

	STRINGS(chdt_output_scalar_definition)
	{
		"unknown 0",
		"unknown 1",
		"input",
		"range input",
		"local a",
		"local b",
		"local c",
		"local d",
		"unknown 8",
		"unknown 9",
	};
	STRING_LIST(chdt_output_scalar_definition, chdt_output_scalar_definition_strings, _countof(chdt_output_scalar_definition_strings));

	STRINGS(chdt_flags_definition)
	{
		"mirror horizontally",
		"mirror vertically",
		"stretch edges",
		"bit 3",
		"enable texture cam",
		"looping",
		"offset sprite index by biped type",
		"offset sprite index by input",
		"offset sprite index by range input",
		"player 1 emblem",
		"player 2 emblem",
		"player 3 emblem",
		"player 4 emblem",
		"unknown alpha modifier",
		"bit 14",
		"unk bit 15",
		"unk bit 16",
		"unk bit 17",
		"bit 18",
		"unk persistent chud data1",
		"unk persistent chud data2",
		"unk persistent chud data3",
		"unk persistent chud data4",
		"manual texture coordinates",
		"bit 24",
		"bit 25",
		"bit 26",
		"bit 27",
		"bit 28",
		"bit 29",
		"bit 30",
		"bit 31",
	};
	STRING_LIST(chdt_flags_definition, chdt_flags_definition_strings, _countof(chdt_flags_definition_strings));

	STRINGS(chdt_render_data_flags_definition)
	{
		"string is a number",
		"force 2-digit",
		"force 3-digit",
		"'+' prefix",
		"'m' suffix",
		"tenths decimal",
		"hundredths decimal",
		"thousandths decimal",
		"hundred thousandths decimal",
		"round number (obsolete)",
		"'x' suffix",
		"in brackets",
		"time format s:ms",
		"time format h:m:s",
		"money format",
		"'-' prefix",
	};
	STRING_LIST(chdt_render_data_flags_definition, chdt_render_data_flags_definition_strings, _countof(chdt_render_data_flags_definition_strings));

	STRINGS(chdt_font_definition)
	{
		"fixedsys, 9pt",
		"tv nord condensed, 18pt",
		"tv nord condensed, bold, 24pt",
		"tv nord condensed, bold, 42pt",
		"tv nord condensed, bold, 30pt",
		"eurostile light demi, 13pt",
		"tv nord hud, 15pt",
		"tv nord condensed, 15pt",
		"eurostile light demi, 18pt",
		"tv nord condensed, 16pt",
		"tv nord condensed, 17pt",
	};
	STRING_LIST(chdt_font_definition, chdt_font_definition_strings, _countof(chdt_font_definition_strings));

	STRINGS(chdt_second_state_block_start_value_definition)
	{
		"value 0",
		"value 1",
		"value 2",
		"value 3",
		"value 4",
		"value 5",
		"value 6",
		"value 7",
		"value 8",
		"value 9",
		"value 10",
		"value 11",
		"value 12",
	};
	STRING_LIST(chdt_second_state_block_start_value_definition, chdt_second_state_block_start_value_definition_strings, _countof(chdt_second_state_block_start_value_definition_strings));

	STRINGS(chdt_input_variable_triggers_definition)
	{
		"value 0",
		"value 1",
		"value 2",
		"value 3",
		"value 4",
		"value 5",
		"value 6",
		"value 7",
		"value 8",
		"value 9",
		"value 10",
		"value 11",
		"value 12",
		"value 13",
		"value 14",
		"value 15",
		"value 16",
		"value 17",
		"value 18",
		"value 19",
		"value 20",
		"value 21",
		"value 22",
		"value 23",
		"value 24",
		"value 25",
		"value 26",
		"value 27",
		"value 28",
	};
	STRING_LIST(chdt_input_variable_triggers_definition, chdt_input_variable_triggers_definition_strings, _countof(chdt_input_variable_triggers_definition_strings));

	STRINGS(chad_flags_definition)
	{
		"bit 0",
		"loops",
		"loops - oscillate",
		"bit 3",
		"bit 4",
		"bit 5",
		"bit 6",
		"bit 7",
	};
	STRING_LIST(chad_flags_definition, chad_flags_definition_strings, _countof(chad_flags_definition_strings));
}
