#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(game_globals_grenade_list, GAME_GLOBALS_GRENADE_LIST_TAG, game_globals_grenade_list_block_block );

	TAG_BLOCK(GameGlobalsGrenadeBlock, eUGT_count)
	{
		{ _field_short_integer, "maximum count" },
		{ _field_pad, "CXVLKJE", 2 },
		{ _field_short_integer, "initial count (Campaign)" },
		{ _field_short_integer, "initial count (Firefight)" },
		{ _field_short_integer, "initial count (Multiplayer)" },
		{ _field_short_integer, "grenadier extra count (Campaign)" },
		{ _field_short_integer, "grenadier extra count (Firefight)" },
		{ _field_short_integer, "grenadier extra count (Multiplayer)" },
		{ _field_real, "drop percentage (Campaign)" },
		{ _field_real, "drop percentage (Firefight)" },
		{ _field_real, "drop percentage (Multiplayer)" },
		{ _field_real, "resourceful scavenge percentage (Campaign)" },
		{ _field_real, "resourceful scavenge percentage (Firefight)" },
		{ _field_real, "resourceful scavenge percentage (Multiplayer)" },
		{ _field_tag_reference, "throwing effect", &Tag::Reference<struct effect_definition>::s_defaultDefinition },
		{ _field_tag_reference, "equipment", &Tag::Reference<struct equipment_definition>::s_defaultDefinition },
		{ _field_tag_reference, "projectile", &Tag::Reference<struct projectile_definition>::s_defaultDefinition },
		{ _field_tag_reference, "equipment (PvE)", &Tag::Reference<struct equipment_definition>::s_defaultDefinition },
		{ _field_tag_reference, "projectile (PvE)", &Tag::Reference<struct projectile_definition>::s_defaultDefinition },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(game_globals_grenade_list_block, 1, game_globals_grenade_list_struct_definition_struct_definition );

	TAG_STRUCT(game_globals_grenade_list_struct_definition)
	{
		{ _field_block, "grenades", &GameGlobalsGrenadeBlock_block },
		{ _field_terminator }
	};

	STRINGS(global_grenade_type_enum)
	{
		"human fragmentation",
		"covenant plasma",

		{ _field_version_less, _engine_type_haloreach, 2 },
		"brute spike",
		"fire bomb",

		{ _field_version_equal, _engine_type_haloreach },
		"grenade type 2",

		{ _field_version_greater, _engine_type_haloreach },
		"pulse grenade",

		{ _field_version_greater_or_equal, _engine_type_haloreach, 5 },
		"grenade type 3",
		"grenade type 4",
		"grenade type 5",
		"grenade type 6",
		"grenade type 7"
	};
	STRING_LIST(global_grenade_type_enum, global_grenade_type_enum_strings, _countof(global_grenade_type_enum_strings));

} // namespace blofeld

