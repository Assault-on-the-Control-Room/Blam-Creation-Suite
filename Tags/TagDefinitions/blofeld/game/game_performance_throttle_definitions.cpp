#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(game_performance_throttle, GAME_PERFORMANCE_THROTTLE_TAG, game_performance_throttle_block_block );

	TAG_BLOCK(game_performance_throttle_entries_block, 32)
	{
		{ _field_struct, "filter", &game_performance_throttle_filter_struct_struct_definition },
		{ _field_struct, "profile", &game_performance_throttle_profile_struct_struct_definition },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(game_performance_throttle_block, 1, game_performance_throttle_struct_definition_struct_definition );

	TAG_STRUCT(game_performance_throttle_struct_definition)
	{
		{ _field_block, "entries", &game_performance_throttle_entries_block_block },
		{ _field_terminator }
	};

	TAG_STRUCT(game_performance_throttle_filter_struct)
	{
		{ _field_long_integer, "minimum player count" },
		{ _field_terminator }
	};

	TAG_STRUCT(game_performance_throttle_profile_struct)
	{
		{ _field_long_integer, "maximum havok proxy count" },
		{ _field_long_integer, "maximum ragdoll count" },
		{ _field_long_integer, "maximum impact count" },
		{ _field_long_integer, "vehicle suspension update frequency" },
		{ _field_long_integer, "Actor LOD, AI actors to update fully each frame" },
		{ _field_long_integer, "Actor LOD, Number of frames to tick LODed AI" },
		{ _field_long_integer, "Actor LOD, Number of concurrent LOD actors to tick" },
		{ _field_terminator }
	};

} // namespace blofeld
