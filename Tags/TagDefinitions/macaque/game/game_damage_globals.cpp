#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define GAME_GLOBALS_DAMAGE_BLOCK_ID { 0x5E608798, 0x58964FDC, 0xBCD062B5, 0x7302D300 }
	TAG_BLOCK(
		game_globals_damage_block,
		"game_globals_damage_block",
		s_damage_globals_definition::k_numBlockElements,
		"s_damage_globals_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		GAME_GLOBALS_DAMAGE_BLOCK_ID)
	{
		{ _field_block, "damage groups", &damage_group_block },
		{ _field_terminator }
	};

	#define DAMAGE_GROUP_BLOCK_ID { 0x34945DAA, 0x3110409D, 0xA4F3330D, 0x4B1BFD04 }
	TAG_BLOCK(
		damage_group_block,
		"damage_group_block",
		k_maximum_material_types,
		"s_damage_group_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		DAMAGE_GROUP_BLOCK_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_block, "armor modifiers", &armor_modifier_block },
		{ _field_terminator }
	};

	#define ARMOR_MODIFIER_BLOCK_ID { 0x1D0D482B, 0x0AB145C0, 0x86B6EF80, 0x3FDE838A }
	TAG_BLOCK(
		armor_modifier_block,
		"armor_modifier_block",
		k_maximum_material_types,
		"s_armor_modifier_definition",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		ARMOR_MODIFIER_BLOCK_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_real, "damage multiplier" },
		{ _field_terminator }
	};

	#define DAMAGE_GLOBALS_BLOCK_ID { 0x2B7CE12A, 0xC9FD4184, 0xA5B5C911, 0x6D515D0A }
	TAG_BLOCK(
		damage_globals_block,
		"damage_globals_block",
		1,
		"s_game_globals_damage",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		DAMAGE_GLOBALS_BLOCK_ID)
	{
		{ _field_tag_reference, "falling damage", &global_damage_reference },
		{ _field_tag_reference, "jumping damage", &global_damage_reference },
		{ _field_tag_reference, "soft landing damage", &global_damage_reference },
		{ _field_tag_reference, "hard landing damage", &global_damage_reference },
		{ _field_tag_reference, "hs damage", &global_damage_reference },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_tag_reference, "hs fire damage", &global_damage_reference },

		{ _field_real, "terminal velocity", "you die if you fall faster than this (non-multiplayer only)", "wu/s" },
		{ _field_tag_reference, "terminal velocity damage", MAKE_OLD_NAMES("distance damage"), &global_damage_reference },
		{ _field_tag_reference, "default damage response", "fall back if none is specified in damage effect tags", MAKE_OLD_NAMES("damage response"), &global_damage_response_definition_reference },
		{ _field_tag_reference, "friendly fire damage response", "anytime your teammate shoots you", &global_damage_response_definition_reference },
		{ _field_real, "player shield spillover", "the minimum amount of shield vitality needed to prevent spillover from damage types that do not spillover." },
		FIELD_CUSTOM("damage decay", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_struct, "damage decay props", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &damage_decay_struct },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		FIELD_CUSTOM("AI damage decay", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_struct, "ai damage decay props", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &damage_decay_struct },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		FIELD_CUSTOM("shield impact decay", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_struct, "shield impact decay props", &damage_decay_struct },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		{ _field_terminator }
	};

	#define SHIELD_BOOST_BLOCK_ID { 0xC8A4D40E, 0x830F49E4, 0x90962271, 0x1FDC8F7C }
	TAG_BLOCK(
		shield_boost_block,
		"shield_boost_block",
		1,
		"s_game_globals_shield_boost",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SHIELD_BOOST_BLOCK_ID)
	{
		FIELD_EXPLANATION("shield boosting", nullptr, FIELD_FLAG_NONE, "This feature was implemented for the engineer character in atlas. Shield dynamics overrides for when shields are being \'boosted\' by an external source"),
		{ _field_real, "shield boost decay", "amount of shield-boost to decay per second" },
		{ _field_real, "shield boost recharge time", "time to recharge full shields when getting boosted" },
		{ _field_real, "shield boost stun time", "stun time when getting boosted" },
		{ _field_terminator }
	};

	#define DAMAGE_DECAY_STRUCT_ID { 0x1C1E2343, 0x2E644935, 0xA2CE1C35, 0x2B143905 }
	TAG_STRUCT(
		damage_decay_struct,
		"damage_decay_struct",
		"s_damage_decay",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		DAMAGE_DECAY_STRUCT_ID)
	{
		{ _field_real, "current damage decay delay", "current damage begins to fall after a time delay has passed since last the damage (MAX 4.1, because timer is stored in a char so 127 ticks maximum)", "seconds" },
		{ _field_real, "current damage decay time", "amount of time it would take for 100% current damage to decay to 0", "seconds" },
		{ _field_real, "current damage decay rate", "amount of damage that decays from our current damage every second", "damage/second" },
		{ _field_real, "recent damage decay delay", "recent damage begins to fall after a time delay has passed since last the damage (MAX 4.1, because timer is stored in a char so 127 ticks maximum)", "seconds" },
		{ _field_real, "recent damage decay time", "amount of time it would take for 100% recent damage to decay to 0", "seconds" },
		{ _field_terminator }
	};

} // namespace macaque

} // namespace blofeld

