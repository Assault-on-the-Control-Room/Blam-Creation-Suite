#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define SCENARIO_DESIGNER_ZONE_BLOCK_ID { 0xB02184D9, 0xCED54A10, 0xA3980886, 0x739063EC }
	TAG_BLOCK(
		scenario_designer_zone_block,
		"scenario_designer_zone_block",
		k_maximum_designer_zone_count,
		"s_scenario_designer_zone",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_DESIGNER_ZONE_BLOCK_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 1 },
		{ _field_legacy, _field_long_integer, "unknown" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 1 },
		{ _field_block, "references", FIELD_FLAG_READ_ONLY, &scenarioDesignerZoneTagReferenceBlock_block },

		FIELD_CUSTOM("biped", nullptr, FIELD_FLAG_NONE, _field_id_block_index_flags),
		{ _field_block, "biped", &biped_block_index_flags_block },
		FIELD_CUSTOM("vehicle", nullptr, FIELD_FLAG_NONE, _field_id_block_index_flags),
		{ _field_block, "vehicle", &vehicle_block_index_flags_block },
		FIELD_CUSTOM("weapon", nullptr, FIELD_FLAG_NONE, _field_id_block_index_flags),
		{ _field_block, "weapon", &weapon_block_index_flags_block },
		FIELD_CUSTOM("equipment", nullptr, FIELD_FLAG_NONE, _field_id_block_index_flags),
		{ _field_block, "equipment", &equipment_block_index_flags_block },
		FIELD_CUSTOM("scenery", nullptr, FIELD_FLAG_NONE, _field_id_block_index_flags),
		{ _field_block, "scenery", &scenery_block_index_flags_block },
		FIELD_CUSTOM("machine", nullptr, FIELD_FLAG_NONE, _field_id_block_index_flags),
		{ _field_block, "machine", &machine_block_index_flags_block },
		FIELD_CUSTOM("terminal", nullptr, FIELD_FLAG_NONE, _field_id_block_index_flags),
		{ _field_block, "terminal", &terminal_block_index_flags_block },
		FIELD_CUSTOM("control", nullptr, FIELD_FLAG_NONE, _field_id_block_index_flags),
		{ _field_block, "control", &control_block_index_flags_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		FIELD_CUSTOM("dispenser", nullptr, FIELD_FLAG_NONE, _field_id_block_index_flags),
		{ _field_block, "dispenser", &dispenser_block_index_flags_block },

		FIELD_CUSTOM("sound_scenery", nullptr, FIELD_FLAG_NONE, _field_id_block_index_flags),
		{ _field_block, "sound_scenery", &sound_scenery_block_index_flags_block },
		FIELD_CUSTOM("crate", nullptr, FIELD_FLAG_NONE, _field_id_block_index_flags),
		{ _field_block, "crate", &crate_block_index_flags_block },
		FIELD_CUSTOM("creature", nullptr, FIELD_FLAG_NONE, _field_id_block_index_flags),
		{ _field_block, "creature", &creature_block_index_flags_block },
		FIELD_CUSTOM("giant", nullptr, FIELD_FLAG_NONE, _field_id_block_index_flags),
		{ _field_block, "giant", &giant_block_index_flags_block },
		FIELD_CUSTOM("effect_scenery", nullptr, FIELD_FLAG_NONE, _field_id_block_index_flags),
		{ _field_block, "effect_scenery", &effect_scenery_block_index_flags_block },
		FIELD_CUSTOM("character", nullptr, FIELD_FLAG_NONE, _field_id_block_index_flags),
		{ _field_block, "character", &character_block_index_flags_block },
		FIELD_CUSTOM("spawner", nullptr, FIELD_FLAG_NONE, _field_id_block_index_flags),
		{ _field_block, "spawner", &spawner_block_index_flags_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 5 },
		FIELD_CUSTOM("budget_reference", nullptr, FIELD_FLAG_NONE, _field_id_block_index_flags),
		{ _field_block, "budget_reference", &budget_reference_block_index_flags_block },
		FIELD_CUSTOM("bink", nullptr, FIELD_FLAG_NONE, _field_id_block_index_flags),
		{ _field_block, "bink", &bink_block_index_flags_block },
		{ _field_block, "resource dependencies", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &scenarioDesignerResourceDependenciesBlock_block },

		{ _field_terminator }
	};

	#define SCENARIODESIGNERZONETAGREFERENCEBLOCK_ID { 0xC7638BFA, 0x6D494909, 0x8E215D8D, 0xD8F92497 }
	TAG_BLOCK(
		scenarioDesignerZoneTagReferenceBlock_block,
		"scenarioDesignerZoneTagReferenceBlock",
		MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK*k_scenario_designer_zone_palette_count,
		"DesignerZoneTagReference",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIODESIGNERZONETAGREFERENCEBLOCK_ID)
	{
		{ _field_tag_reference, "tag", FIELD_FLAG_INDEX, &scenarioDesignerZoneTagReferenceBlock_tag_reference },
		{ _field_terminator }
	};

	#define BIPED_BLOCK_INDEX_FLAGS_BLOCK_STRUCT_ID { 0xAE76A8B1, 0xEEE349D5, 0x8E0EB470, 0xCF3F6160 }
	TAG_BLOCK(
		biped_block_index_flags_block,
		"biped_block_index_flags_block",
		MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK,
		"s_scenario_designer_zone_palette_index_flag",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		BIPED_BLOCK_INDEX_FLAGS_BLOCK_STRUCT_ID)
	{
		{ _field_short_block_index, "palette index", FIELD_FLAG_INDEX, &scenario_biped_palette_block },
		{ _field_terminator }
	};

	#define VEHICLE_BLOCK_INDEX_FLAGS_BLOCK_STRUCT_ID { 0xD97D47DE, 0x61A34B62, 0x9D457953, 0x3628F7DE }
	TAG_BLOCK(
		vehicle_block_index_flags_block,
		"vehicle_block_index_flags_block",
		MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK,
		"s_scenario_designer_zone_palette_index_flag",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		VEHICLE_BLOCK_INDEX_FLAGS_BLOCK_STRUCT_ID)
	{
		{ _field_short_block_index, "palette index", FIELD_FLAG_INDEX, &scenario_vehicle_palette_block },
		{ _field_terminator }
	};

	#define WEAPON_BLOCK_INDEX_FLAGS_BLOCK_STRUCT_ID { 0xF11CDE07, 0xCED0403C, 0xBF09B2C7, 0x6653FAB9 }
	TAG_BLOCK(
		weapon_block_index_flags_block,
		"weapon_block_index_flags_block",
		MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK,
		"s_scenario_designer_zone_palette_index_flag",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		WEAPON_BLOCK_INDEX_FLAGS_BLOCK_STRUCT_ID)
	{
		{ _field_short_block_index, "palette index", FIELD_FLAG_INDEX, &scenario_weapon_palette_block },
		{ _field_terminator }
	};

	#define EQUIPMENT_BLOCK_INDEX_FLAGS_BLOCK_STRUCT_ID { 0xB7A7D0B5, 0x849B45D5, 0x9D7AEBD2, 0x7FA02CCB }
	TAG_BLOCK(
		equipment_block_index_flags_block,
		"equipment_block_index_flags_block",
		MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK,
		"s_scenario_designer_zone_palette_index_flag",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		EQUIPMENT_BLOCK_INDEX_FLAGS_BLOCK_STRUCT_ID)
	{
		{ _field_short_block_index, "palette index", FIELD_FLAG_INDEX, &scenario_equipment_palette_block },
		{ _field_terminator }
	};

	#define SCENERY_BLOCK_INDEX_FLAGS_BLOCK_STRUCT_ID { 0x50BDCE4A, 0x841D42F3, 0xB6BD3790, 0xCD47CDBA }
	TAG_BLOCK(
		scenery_block_index_flags_block,
		"scenery_block_index_flags_block",
		MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK,
		"s_scenario_designer_zone_palette_index_flag",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENERY_BLOCK_INDEX_FLAGS_BLOCK_STRUCT_ID)
	{
		{ _field_short_block_index, "palette index", FIELD_FLAG_INDEX, &scenario_scenery_palette_block },
		{ _field_terminator }
	};

	#define MACHINE_BLOCK_INDEX_FLAGS_BLOCK_STRUCT_ID { 0x266621B5, 0xFDB64754, 0x8FC9D2C5, 0xA7FF5BDF }
	TAG_BLOCK(
		machine_block_index_flags_block,
		"machine_block_index_flags_block",
		MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK,
		"s_scenario_designer_zone_palette_index_flag",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		MACHINE_BLOCK_INDEX_FLAGS_BLOCK_STRUCT_ID)
	{
		{ _field_short_block_index, "palette index", FIELD_FLAG_INDEX, &scenario_machine_palette_block },
		{ _field_terminator }
	};

	#define TERMINAL_BLOCK_INDEX_FLAGS_BLOCK_STRUCT_ID { 0xC2BEE19D, 0xB5F0423F, 0xBA356503, 0x62B96151 }
	TAG_BLOCK(
		terminal_block_index_flags_block,
		"terminal_block_index_flags_block",
		MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK,
		"s_scenario_designer_zone_palette_index_flag",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		TERMINAL_BLOCK_INDEX_FLAGS_BLOCK_STRUCT_ID)
	{
		{ _field_short_block_index, "palette index", FIELD_FLAG_INDEX, &scenario_terminal_palette_block },
		{ _field_terminator }
	};

	#define CONTROL_BLOCK_INDEX_FLAGS_BLOCK_STRUCT_ID { 0x6388FD6C, 0x6FE74B66, 0xB04DAAF6, 0x602232D9 }
	TAG_BLOCK(
		control_block_index_flags_block,
		"control_block_index_flags_block",
		MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK,
		"s_scenario_designer_zone_palette_index_flag",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CONTROL_BLOCK_INDEX_FLAGS_BLOCK_STRUCT_ID)
	{
		{ _field_short_block_index, "palette index", FIELD_FLAG_INDEX, &scenario_control_palette_block },
		{ _field_terminator }
	};

	#define DISPENSER_BLOCK_INDEX_FLAGS_BLOCK_STRUCT_ID { 0x7FF5A8A6, 0x60DF479F, 0x81451DEF, 0xD2B1FCAA }
	TAG_BLOCK(
		dispenser_block_index_flags_block,
		"dispenser_block_index_flags_block",
		MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK,
		"s_scenario_designer_zone_palette_index_flag",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		DISPENSER_BLOCK_INDEX_FLAGS_BLOCK_STRUCT_ID)
	{
		{ _field_short_block_index, "palette index", FIELD_FLAG_INDEX, &ScenarioDispenserPaletteBlock_block },
		{ _field_terminator }
	};

	#define SOUND_SCENERY_BLOCK_INDEX_FLAGS_BLOCK_STRUCT_ID { 0x1D75B752, 0x30794C1E, 0x92F7FE0B, 0x9A73B1F6 }
	TAG_BLOCK(
		sound_scenery_block_index_flags_block,
		"sound_scenery_block_index_flags_block",
		MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK,
		"s_scenario_designer_zone_palette_index_flag",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SOUND_SCENERY_BLOCK_INDEX_FLAGS_BLOCK_STRUCT_ID)
	{
		{ _field_short_block_index, "palette index", FIELD_FLAG_INDEX, &scenario_sound_scenery_palette_block },
		{ _field_terminator }
	};

	#define CRATE_BLOCK_INDEX_FLAGS_BLOCK_STRUCT_ID { 0xAE2328B4, 0x9AF842AF, 0xB8597C81, 0x177E8F02 }
	TAG_BLOCK(
		crate_block_index_flags_block,
		"crate_block_index_flags_block",
		MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK,
		"s_scenario_designer_zone_palette_index_flag",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CRATE_BLOCK_INDEX_FLAGS_BLOCK_STRUCT_ID)
	{
		{ _field_short_block_index, "palette index", FIELD_FLAG_INDEX, &scenario_crate_palette_block },
		{ _field_terminator }
	};

	#define CREATURE_BLOCK_INDEX_FLAGS_BLOCK_STRUCT_ID { 0x28EFEBFB, 0x85BB41F9, 0xAA7F3DB1, 0x4525BDC6 }
	TAG_BLOCK(
		creature_block_index_flags_block,
		"creature_block_index_flags_block",
		MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK,
		"s_scenario_designer_zone_palette_index_flag",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CREATURE_BLOCK_INDEX_FLAGS_BLOCK_STRUCT_ID)
	{
		{ _field_short_block_index, "palette index", FIELD_FLAG_INDEX, &scenario_creature_palette_block },
		{ _field_terminator }
	};

	#define GIANT_BLOCK_INDEX_FLAGS_BLOCK_STRUCT_ID { 0x127D1256, 0x0AD44F51, 0xB07D8B34, 0x4496D0A2 }
	TAG_BLOCK(
		giant_block_index_flags_block,
		"giant_block_index_flags_block",
		MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK,
		"s_scenario_designer_zone_palette_index_flag",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		GIANT_BLOCK_INDEX_FLAGS_BLOCK_STRUCT_ID)
	{
		{ _field_short_block_index, "palette index", FIELD_FLAG_INDEX, &scenario_giant_palette_block },
		{ _field_terminator }
	};

	#define EFFECT_SCENERY_BLOCK_INDEX_FLAGS_BLOCK_STRUCT_ID { 0xA5A55650, 0xA1334BAB, 0x9A91DD38, 0x86E1FFBA }
	TAG_BLOCK(
		effect_scenery_block_index_flags_block,
		"effect_scenery_block_index_flags_block",
		MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK,
		"s_scenario_designer_zone_palette_index_flag",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		EFFECT_SCENERY_BLOCK_INDEX_FLAGS_BLOCK_STRUCT_ID)
	{
		{ _field_short_block_index, "palette index", FIELD_FLAG_INDEX, &scenario_effect_scenery_palette_block },
		{ _field_terminator }
	};

	#define CHARACTER_BLOCK_INDEX_FLAGS_BLOCK_STRUCT_ID { 0x878E0364, 0x3F1F47F2, 0x963CE43C, 0xA3BB5D25 }
	TAG_BLOCK(
		character_block_index_flags_block,
		"character_block_index_flags_block",
		64,
		"s_scenario_designer_zone_palette_index_flag",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CHARACTER_BLOCK_INDEX_FLAGS_BLOCK_STRUCT_ID)
	{
		{ _field_short_block_index, "palette index", FIELD_FLAG_INDEX, &character_palette_block },
		{ _field_terminator }
	};

	#define SPAWNER_BLOCK_INDEX_FLAGS_BLOCK_STRUCT_ID { 0xADC48FA4, 0x19AF414B, 0x97D43F6D, 0x531B4F37 }
	TAG_BLOCK(
		spawner_block_index_flags_block,
		"spawner_block_index_flags_block",
		MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK,
		"s_scenario_designer_zone_palette_index_flag",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SPAWNER_BLOCK_INDEX_FLAGS_BLOCK_STRUCT_ID)
	{
		{ _field_short_block_index, "palette index", FIELD_FLAG_INDEX, &scenario_spawner_palette_block },
		{ _field_terminator }
	};

	#define BUDGET_REFERENCE_BLOCK_INDEX_FLAGS_BLOCK_STRUCT_ID { 0xFD713DEA, 0x0786402E, 0xA77EA27B, 0xD760F6BF }
	TAG_BLOCK(
		budget_reference_block_index_flags_block,
		"budget_reference_block_index_flags_block",
		k_maximum_hs_references_per_context,
		"s_scenario_designer_zone_palette_index_flag",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		BUDGET_REFERENCE_BLOCK_INDEX_FLAGS_BLOCK_STRUCT_ID)
	{
		{ _field_short_block_index, "palette index", FIELD_FLAG_INDEX, &scenario_budget_references_block },
		{ _field_terminator }
	};

	#define BINK_BLOCK_INDEX_FLAGS_BLOCK_STRUCT_ID { 0x51BDB563, 0x39E8469B, 0x998DB016, 0x62EF70DF }
	TAG_BLOCK(
		bink_block_index_flags_block,
		"bink_block_index_flags_block",
		MAXIMUM_BINK_PALETTE_ENTRIES_PER_BLOCK,
		"s_scenario_designer_zone_palette_index_flag",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		BINK_BLOCK_INDEX_FLAGS_BLOCK_STRUCT_ID)
	{
		{ _field_short_block_index, "palette index", FIELD_FLAG_INDEX, &binkPaletteBlock_block },
		{ _field_terminator }
	};

	#define SCENARIODESIGNERRESOURCEDEPENDENCIESBLOCK_ID { 0xA3BBAFF9, 0xC83C4712, 0xBB6E582F, 0xFB6D2D17 }
	TAG_BLOCK(
		scenarioDesignerResourceDependenciesBlock_block,
		"scenarioDesignerResourceDependenciesBlock",
		16*1024,
		"s_tag_reference",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIODESIGNERRESOURCEDEPENDENCIESBLOCK_ID)
	{
		{ _field_tag_reference, "tag", FIELD_FLAG_INDEX, &scenarioDesignerResourceDependenciesBlock_tag_reference },
		{ _field_terminator }
	};

} // namespace macaque

} // namespace blofeld

