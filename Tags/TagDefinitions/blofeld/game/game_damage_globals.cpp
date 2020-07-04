#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_BLOCK(armor_modifier_block, k_maximum_material_types)
	{
		{ _field_string_id, "name^" },
		{ _field_real, "damage multiplier" },
		{ _field_terminator }
	};

	TAG_BLOCK(damage_group_block, k_maximum_material_types)
	{
		{ _field_string_id, "name^" },
		{ _field_block, "armor modifiers", &armor_modifier_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(game_globals_damage_block, s_damage_globals_definition::k_numBlockElements)
	{
		{ _field_block, "damage groups", &damage_group_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(damage_globals_block, 1)
	{
		{ _field_tag_reference, "falling damage", &global_damage_reference },
		{ _field_tag_reference, "jumping damage", &global_damage_reference },
		{ _field_tag_reference, "soft landing damage", &global_damage_reference },
		{ _field_tag_reference, "hard landing damage", &global_damage_reference },
		{ _field_tag_reference, "hs damage", &global_damage_reference },
		
		{ _field_version_greater, _engine_type_haloreach },
		{ _field_tag_reference, "hs fire damage", &global_damage_reference },

		{ _field_real, "terminal velocity:wu/s#you die if you fall faster than this (non-multiplayer only)" },
		{ _field_tag_reference, "terminal velocity damage{distance damage}", &global_damage_reference },
		{ _field_tag_reference, "default damage response{damage response}#fall back if none is specified in damage effect tags", &global_damage_response_definition_reference },
		{ _field_tag_reference, "friendly fire damage response#anytime your teammate shoots you", &global_damage_response_definition_reference },
		{ _field_real, "player shield spillover#the minimum amount of shield vitality needed to prevent spillover from damage types that do not spillover." },
		{ _field_custom, "damage decay" },
		{ _field_struct, "damage decay props*!", &damage_decay_struct_struct_definition },
		{ _field_custom },
		{ _field_custom, "AI damage decay" },
		{ _field_struct, "ai damage decay props*!", &damage_decay_struct_struct_definition },
		{ _field_custom },
		{ _field_custom, "shield impact decay" },
		{ _field_struct, "shield impact decay props", &damage_decay_struct_struct_definition },
		{ _field_custom },
		{ _field_terminator }
	};

	TAG_BLOCK(shield_boost_block, 1)
	{
		{ _field_explanation, "shield boosting", "This feature was implemented for the engineer character in atlas. Shield dynamics overrides for when shields are being \'boosted\' by an external source" },
		{ _field_real, "shield boost decay#amount of shield-boost to decay per second" },
		{ _field_real, "shield boost recharge time#time to recharge full shields when getting boosted" },
		{ _field_real, "shield boost stun time#stun time when getting boosted" },
		{ _field_terminator }
	};

	TAG_STRUCT(damage_decay_struct)
	{
		{ _field_real, "current damage decay delay:seconds#current damage begins to fall after a time delay has passed since last the damage (MAX 4.1, because timer is stored in a char so 127 ticks maximum)" },
		{ _field_real, "current damage decay time:seconds#amount of time it would take for 100% current damage to decay to 0" },
		{ _field_real, "current damage decay rate:damage/second#amount of damage that decays from our current damage every second" },
		{ _field_real, "recent damage decay delay:seconds#recent damage begins to fall after a time delay has passed since last the damage (MAX 4.1, because timer is stored in a char so 127 ticks maximum)" },
		{ _field_real, "recent damage decay time:seconds#amount of time it would take for 100% recent damage to decay to 0" },
		{ _field_terminator }
	};

} // namespace blofeld

