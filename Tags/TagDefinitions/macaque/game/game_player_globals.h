#pragma once

namespace blofeld
{

namespace macaque
{

	extern s_tag_block_definition player_information_block;
	extern s_tag_struct_definition player_information_block_struct_definition; // player_information_block
	extern s_tag_block_definition player_momentum_data_block;
	extern s_tag_struct_definition player_momentum_data_block_struct_definition; // player_momentum_data_block
	extern s_tag_block_definition player_representation_block;
	extern s_tag_struct_definition player_representation_block_struct_definition; // player_representation_block
	extern s_tag_block_definition firstPersonpHiddenBodyRegionsBlock_block;
	extern s_tag_struct_definition firstPersonpHiddenBodyRegionsBlock_block_struct_definition; // firstPersonpHiddenBodyRegionsBlock_block


	extern c_versioned_string_list MomentumFlag_strings;
	extern s_string_list_definition MomentumFlag;
	extern c_versioned_string_list player_representation_flags_strings;
	extern s_string_list_definition player_representation_flags;
	extern c_versioned_string_list FpBodyRegionFlags_strings;
	extern s_string_list_definition FpBodyRegionFlags;

} // namespace macaque

} // namespace blofeld

