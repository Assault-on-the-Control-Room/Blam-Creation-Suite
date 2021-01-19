#pragma once

namespace blofeld
{

namespace macaque
{

	constexpr unsigned long DAMAGE_EFFECT_TAG = 'jpt!';
	extern s_tag_group damage_effect_group; // damage_effect_block


	extern s_tag_block_definition damage_effect_block;
	extern s_tag_block_definition custom_damage_response_label_block;
	extern s_tag_struct_definition custom_damage_response_label_block_struct_definition; // custom_damage_response_label_block
	extern s_tag_block_definition damage_effect_sound_block;
	extern s_tag_struct_definition damage_effect_sound_block_struct_definition; // damage_effect_sound_block

	extern s_tag_struct_definition damage_effect_struct_definition; // tag group
	extern s_tag_struct_definition damage_outer_cone_angle_struct;

	extern c_versioned_string_list damage_side_effects_strings;
	extern s_string_list_definition damage_side_effects;
	extern c_versioned_string_list damage_categories_strings;
	extern s_string_list_definition damage_categories;
	extern c_versioned_string_list damage_death_vocalizations_strings;
	extern s_string_list_definition damage_death_vocalizations;
	extern c_versioned_string_list damage_flags_strings;
	extern s_string_list_definition damage_flags;
	extern c_versioned_string_list damageSecondaryFlags_strings;
	extern s_string_list_definition damageSecondaryFlags;
	extern c_versioned_string_list damage_effect_sound_type_flags_strings;
	extern s_string_list_definition damage_effect_sound_type_flags;
	extern c_versioned_string_list damage_effect_flags_strings;
	extern s_string_list_definition damage_effect_flags;

	extern s_tag_reference_definition global_damage_reference;

} // namespace macaque

} // namespace blofeld

