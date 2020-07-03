#pragma once

namespace blofeld
{
	constexpr unsigned long CHUD_ANIMATION_TAG = 'chad';
	constexpr unsigned long CHUD_TAG = 'chdt';
	constexpr unsigned long CHUD_GLOBALS_TAG = 'chgd';

	extern s_tag_group chud_animation_group;
	extern s_tag_group chud_group;

	extern s_tag_group chud_globals_group;
	extern s_tag_struct_definition chgd_struct_definition_struct_definition;
	extern s_tag_block_definition chgd_block_block;
	extern s_tag_reference_definition chud_globals_reference;
	extern s_tag_block_definition chgd_hud_sounds_block_block;
	extern s_tag_block_definition chgd_hud_attributes_block_block;
	extern s_tag_block_definition chgd_hud_globals_block_block;
	extern s_tag_block_definition chgd_waypoint_blips_block_block;
	extern s_tag_block_definition chgd_shaders_block_block;
	extern s_tag_block_definition chgd_unknown_block_block;
	extern s_tag_block_definition chgd_player_training_data_block_block;
	extern s_tag_block_definition chgd_state_triggers_block_block;

	extern s_tag_reference_definition unknown_reference;

	extern c_versioned_string_list biped_enum_definition_strings;
	extern s_string_list_definition biped_enum_definition;
	extern c_versioned_string_list resolution_flags_definition_strings;
	extern s_string_list_definition resolution_flags_definition;
	extern c_versioned_string_list latched_to_flags_definition_strings;
	extern s_string_list_definition latched_to_flags_definition;
	extern c_versioned_string_list icon_enum_definition_strings;
	extern s_string_list_definition icon_enum_definition;
	extern c_versioned_string_list player_training_flags_definition_strings;
	extern s_string_list_definition player_training_flags_definition;

	extern s_tag_reference_definition chud_animation_reference;
	extern s_tag_reference_definition chud_reference;

}

