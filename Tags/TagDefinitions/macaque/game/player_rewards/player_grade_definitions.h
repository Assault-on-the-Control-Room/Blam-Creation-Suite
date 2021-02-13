#pragma once

namespace blofeld
{

namespace macaque
{

	constexpr unsigned long PLAYER_GRADE_GLOBALS_DEFINITION_TAG = 'pggd';
	extern s_tag_group player_grade_globals_definition_group; // player_grade_globals_definition_block


	extern s_tag_block_definition player_grade_globals_definition_block;
	extern s_tag_block_definition player_grade_definition_block;
	extern s_tag_struct_definition player_grade_definition_block_struct_definition; // player_grade_definition_block

	extern s_tag_block_definition player_rank_globals_definition_block;
	extern s_tag_struct_definition s_player_rank_globals_definition;

	extern s_tag_struct_definition player_grade_globals_definition_struct_definition; // tag group

} // namespace macaque

} // namespace blofeld

