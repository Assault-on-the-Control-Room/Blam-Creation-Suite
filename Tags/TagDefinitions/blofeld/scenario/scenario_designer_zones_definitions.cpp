#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_BLOCK(scenarioDesignerZoneTagReferenceBlock, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK*k_scenario_designer_zone_palette_count)
	{
		{ _field_tag_reference, "tag^", &scenarioDesignerZoneTagReferenceBlock_tag_reference },
		{ _field_terminator }
	};

	TAG_BLOCK(biped_block_index_flags_block, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
	{
		{ _field_short_block_index, "palette index^" },
		{ _field_terminator }
	};

	TAG_BLOCK(vehicle_block_index_flags_block, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
	{
		{ _field_short_block_index, "palette index^" },
		{ _field_terminator }
	};

	TAG_BLOCK(weapon_block_index_flags_block, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
	{
		{ _field_short_block_index, "palette index^" },
		{ _field_terminator }
	};

	TAG_BLOCK(equipment_block_index_flags_block, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
	{
		{ _field_short_block_index, "palette index^" },
		{ _field_terminator }
	};

	TAG_BLOCK(scenery_block_index_flags_block, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
	{
		{ _field_short_block_index, "palette index^" },
		{ _field_terminator }
	};

	TAG_BLOCK(machine_block_index_flags_block, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
	{
		{ _field_short_block_index, "palette index^" },
		{ _field_terminator }
	};

	TAG_BLOCK(terminal_block_index_flags_block, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
	{
		{ _field_short_block_index, "palette index^" },
		{ _field_terminator }
	};

	TAG_BLOCK(control_block_index_flags_block, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
	{
		{ _field_short_block_index, "palette index^" },
		{ _field_terminator }
	};

	TAG_BLOCK(dispenser_block_index_flags_block, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
	{
		{ _field_short_block_index, "palette index^" },
		{ _field_terminator }
	};

	TAG_BLOCK(sound_scenery_block_index_flags_block, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
	{
		{ _field_short_block_index, "palette index^" },
		{ _field_terminator }
	};

	TAG_BLOCK(crate_block_index_flags_block, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
	{
		{ _field_short_block_index, "palette index^" },
		{ _field_terminator }
	};

	TAG_BLOCK(creature_block_index_flags_block, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
	{
		{ _field_short_block_index, "palette index^" },
		{ _field_terminator }
	};

	TAG_BLOCK(giant_block_index_flags_block, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
	{
		{ _field_short_block_index, "palette index^" },
		{ _field_terminator }
	};

	TAG_BLOCK(effect_scenery_block_index_flags_block, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
	{
		{ _field_short_block_index, "palette index^" },
		{ _field_terminator }
	};

	TAG_BLOCK(character_block_index_flags_block, 64)
	{
		{ _field_short_block_index, "palette index^" },
		{ _field_terminator }
	};

	TAG_BLOCK(spawner_block_index_flags_block, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
	{
		{ _field_short_block_index, "palette index^" },
		{ _field_terminator }
	};

	TAG_BLOCK(budget_reference_block_index_flags_block, k_maximum_hs_references_per_context)
	{
		{ _field_short_block_index, "palette index^" },
		{ _field_terminator }
	};

	TAG_BLOCK(bink_block_index_flags_block, MAXIMUM_BINK_PALETTE_ENTRIES_PER_BLOCK)
	{
		{ _field_short_block_index, "palette index^" },
		{ _field_terminator }
	};

	TAG_BLOCK(scenarioDesignerResourceDependenciesBlock, 16*1024)
	{
		{ _field_tag_reference, "tag^", &scenarioDesignerResourceDependenciesBlock_tag_reference },
		{ _field_terminator }
	};

	TAG_BLOCK(scenario_designer_zone_block, k_maximum_designer_zone_count)
	{
		{ _field_string_id, "name^" },

		{ _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_long_integer, "unknown" },

		{ _field_version_greater, _engine_type_haloreach },
		{ _field_block, "references*", &scenarioDesignerZoneTagReferenceBlock_block },

		{ _field_custom, "biped" },
		{ _field_block, "biped", &biped_block_index_flags_block_block },
		{ _field_custom, "vehicle" },
		{ _field_block, "vehicle", &vehicle_block_index_flags_block_block },
		{ _field_custom, "weapon" },
		{ _field_block, "weapon", &weapon_block_index_flags_block_block },
		{ _field_custom, "equipment" },
		{ _field_block, "equipment", &equipment_block_index_flags_block_block },
		{ _field_custom, "scenery" },
		{ _field_block, "scenery", &scenery_block_index_flags_block_block },
		{ _field_custom, "machine" },
		{ _field_block, "machine", &machine_block_index_flags_block_block },
		{ _field_custom, "terminal" },
		{ _field_block, "terminal", &terminal_block_index_flags_block_block },
		{ _field_custom, "control" },
		{ _field_block, "control", &control_block_index_flags_block_block },

		{ _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_custom, "dispenser" },
		{ _field_block, "dispenser", &dispenser_block_index_flags_block_block },

		{ _field_custom, "sound_scenery" },
		{ _field_block, "sound_scenery", &sound_scenery_block_index_flags_block_block },
		{ _field_custom, "crate" },
		{ _field_block, "crate", &crate_block_index_flags_block_block },
		{ _field_custom, "creature" },
		{ _field_block, "creature", &creature_block_index_flags_block_block },
		{ _field_custom, "giant" },
		{ _field_block, "giant", &giant_block_index_flags_block_block },
		{ _field_custom, "effect_scenery" },
		{ _field_block, "effect_scenery", &effect_scenery_block_index_flags_block_block },
		{ _field_custom, "character" },
		{ _field_block, "character", &character_block_index_flags_block_block },
		{ _field_custom, "spawner" },
		{ _field_block, "spawner", &spawner_block_index_flags_block_block },

		{ _field_version_greater, _engine_type_haloreach, 5 },
		{ _field_custom, "budget_reference" },
		{ _field_block, "budget_reference", &budget_reference_block_index_flags_block_block },
		{ _field_custom, "bink" },
		{ _field_block, "bink", &bink_block_index_flags_block_block },
		{ _field_block, "resource dependencies*!", &scenarioDesignerResourceDependenciesBlock_block },

		{ _field_terminator }
	};

} // namespace blofeld

