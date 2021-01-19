#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define SQUAD_PATROL_BLOCK_ID { 0xBA52B4CA, 0xAF324B33, 0x9B6A0F6F, 0xAD1274B9 }
	TAG_BLOCK(
		squad_patrol_block,
		"squad_patrol_block",
		k_max_squad_patrols_per_map,
		"s_squad_patrol_definition",
		SQUAD_PATROL_BLOCK_ID)
	{
		FIELD_CUSTOM(nullptr, 0),
		{ _field_string_id, "name^" },
		{ _field_block, "squads", &squad_patrol_member_block },
		{ _field_block, "points", &squad_patrol_point_block },
		{ _field_block, "transitions", &squad_patrol_transition_block },
		{ _field_short_block_index, "editor folder!", nullptr, 'ugly' },
		{ _field_pad, "pad", 2 },
		{ _field_terminator }
	};

	#define SQUAD_PATROL_MEMBER_BLOCK_ID { 0x8092823C, 0x0CE64669, 0xA842F833, 0xC9ACEABD }
	TAG_BLOCK(
		squad_patrol_member_block,
		"squad_patrol_member_block",
		k_max_members_per_squad_patrol,
		"s_squad_patrol_member_definition",
		SQUAD_PATROL_MEMBER_BLOCK_ID)
	{
		{ _field_short_block_index, "squad^" },
		{ _field_pad, "post-squad-pad", 2 },
		{ _field_terminator }
	};

	#define SQUAD_PATROL_POINT_BLOCK_ID { 0x19925340, 0x2CD7411C, 0x84AED8BA, 0x22F75B6D }
	TAG_BLOCK(
		squad_patrol_point_block,
		"squad_patrol_point_block",
		k_max_points_per_squad_patrol,
		"s_squad_patrol_point_definition",
		SQUAD_PATROL_POINT_BLOCK_ID)
	{
		{ _field_short_block_index, "objective^" },
		{ _field_pad, "post-objective-pad", 2 },
		FIELD_CUSTOM(nullptr, _custom_field_filter),
		{ _field_real, "hold time{occupy time}:seconds#How long the AI should pause at this point before searching" },
		FIELD_CUSTOM(nullptr, _custom_field_filter),
		{ _field_real, "search time:seconds#How long the AI should search at this point before returning" },
		FIELD_CUSTOM(nullptr, _custom_field_filter),
		{ _field_real, "pause time:seconds#How long the AI should pause at this point after searching before moving on" },
		FIELD_CUSTOM(nullptr, _custom_field_filter),
		{ _field_real, "cooldown time:seconds#How long after being abandoned should this point be available again" },
		{ _field_terminator }
	};

	#define SQUAD_PATROL_TRANSITION_BLOCK_ID { 0x70647FDE, 0x5A0449E6, 0x8491538C, 0xAFE36794 }
	TAG_BLOCK(
		squad_patrol_transition_block,
		"squad_patrol_transition_block",
		k_max_squad_patrol_transitions,
		"s_squad_patrol_transition_definition",
		SQUAD_PATROL_TRANSITION_BLOCK_ID)
	{
		{ _field_short_block_index, "point1" },
		{ _field_short_block_index, "point2" },
		{ _field_block, "waypoints", &squad_patrol_waypoint_block },
		{ _field_terminator }
	};

	#define SQUAD_PATROL_WAYPOINT_BLOCK_ID { 0xE428A1E3, 0x735A4EF2, 0xB58F05F6, 0x703A8167 }
	TAG_BLOCK(
		squad_patrol_waypoint_block,
		"squad_patrol_waypoint_block",
		k_max_squad_patrol_waypoints_per_transition,
		"s_squad_patrol_waypoint_definition",
		SQUAD_PATROL_WAYPOINT_BLOCK_ID)
	{
		{ _field_real_point_3d, "position" },
		{ _field_custom_long_block_index, "packedKeyOffaceref~!" },
		{ _field_custom_long_block_index, "navMeshUIDOffaceref~!" },
		{ _field_terminator }
	};

} // namespace macaque

} // namespace blofeld

