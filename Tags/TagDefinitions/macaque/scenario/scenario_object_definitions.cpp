#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define SCENARIO_WEAPON_PALETTE_BLOCK_ID { 0xB129233A, 0xC7914741, 0x9513A80A, 0x3B9C12D1 }
	TAG_BLOCK(
		scenario_weapon_palette_block,
		"scenario_weapon_palette_block",
		MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK,
		"scenario_object_palette_entry",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_WEAPON_PALETTE_BLOCK_ID)
	{
		{ _field_tag_reference, "name", FIELD_FLAG_INDEX, &weapon_reference$7 },
		{ _field_terminator }
	};

	#define SCENARIO_EQUIPMENT_PALETTE_BLOCK_ID { 0xA91733C4, 0x27394ADD, 0xBDF68C43, 0x9CDCAD72 }
	TAG_BLOCK(
		scenario_equipment_palette_block,
		"scenario_equipment_palette_block",
		MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK,
		"scenario_object_palette_entry",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_EQUIPMENT_PALETTE_BLOCK_ID)
	{
		{ _field_tag_reference, "name", FIELD_FLAG_INDEX, &equipment_reference$3 },
		{ _field_terminator }
	};

	#define SCENARIO_VEHICLE_PALETTE_BLOCK_ID { 0x666689FB, 0x9FE8484B, 0xAAAC920E, 0x44ED0845 }
	TAG_BLOCK(
		scenario_vehicle_palette_block,
		"scenario_vehicle_palette_block",
		MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK,
		"scenario_object_palette_entry",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_VEHICLE_PALETTE_BLOCK_ID)
	{
		{ _field_tag_reference, "name", FIELD_FLAG_INDEX, &vehicle_reference$2 },
		{ _field_terminator }
	};

	#define SCENARIO_VEHICLE_BLOCK_ID { 0x756D14F1, 0xDEF4497E, 0xA140AC68, 0xC9C52931 }
	TAG_BLOCK(
		scenario_vehicle_block,
		"scenario_vehicle_block",
		MAXIMUM_VEHICLE_DATUMS_PER_SCENARIO,
		"scenario_vehicle_block",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_VEHICLE_BLOCK_ID)
	{
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_filter),
		{ _field_short_block_index, "type", &scenario_vehicle_palette_block, _field_id_type },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_filter),
		{ _field_short_block_index, "name", FIELD_FLAG_INDEX, &scenario_object_names_block, _field_id_name },
		{ _field_struct, "object data", &scenario_object_datum_struct },
		{ _field_struct, "permutation data", &scenario_object_permutation_struct },
		{ _field_struct, "unit data", &scenario_unit_struct },
		{ _field_struct, "multiplayer data", &scenario_multiplayer_object_struct },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 1 },
		{ _field_struct, "vehicle data", &scenario_vehicle_datum_struct },

		{ _field_terminator }
	};

	#define SCENARIO_OBJECT_NODE_ORIENTATIONS_BLOCK_ID { 0xEDA8EC00, 0x4C774AEF, 0xB12F582C, 0x1E39C08A }
	TAG_BLOCK(
		scenario_object_node_orientations_block,
		"scenario_object_node_orientations_block",
		1,
		"s_scenario_object_node_orientations",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_OBJECT_NODE_ORIENTATIONS_BLOCK_ID)
	{
		{ _field_short_integer, "node count", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		FIELD_PAD("paddington", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_block, "bit vector", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &scenario_object_node_orientations_bit_vector_block },
		{ _field_block, "orientations", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &scenario_object_node_orientations_orientations_block },
		{ _field_terminator }
	};

	#define SCENARIO_OBJECT_NODE_ORIENTATIONS_BIT_VECTOR_BLOCK_ID { 0xEDBAEA00, 0x1CBB4AEF, 0xCC2D582C, 0x0D39C28A }
	TAG_BLOCK(
		scenario_object_node_orientations_bit_vector_block,
		"scenario_object_node_orientations_bit_vector_block",
		2*(((((MAXIMUM_NODES_PER_MODEL)+(k_int32_bits-1))>>k_int32_bits_bits))*sizeof(int32)),
		"byte",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_OBJECT_NODE_ORIENTATIONS_BIT_VECTOR_BLOCK_ID)
	{
		{ _field_byte_integer, "data", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define SCENARIO_OBJECT_NODE_ORIENTATIONS_ORIENTATIONS_BLOCK_ID { 0xEDAAEC00, 0x4CB74AEF, 0xBC2F582C, 0x1D39C08A }
	TAG_BLOCK(
		scenario_object_node_orientations_orientations_block,
		"scenario_object_node_orientations_orientations_block",
		MAXIMUM_NODES_PER_MODEL*7,
		"short",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_OBJECT_NODE_ORIENTATIONS_ORIENTATIONS_BLOCK_ID)
	{
		{ _field_short_integer, "number", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define SCRIPTLISTBLOCK_ID { 0xF24154DC, 0x70B744D7, 0x9379D8B3, 0x43C9D8E1 }
	TAG_BLOCK(
		scriptListBlock_block,
		"scriptListBlock",
		k_maximum_hs_source_files_per_context,
		"string_id",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCRIPTLISTBLOCK_ID)
	{
		{ _field_string_id, "script name", FIELD_FLAG_INDEX },
		{ _field_terminator }
	};

	#define COMMANDLINKBLOCK_ID { 0xB773C59A, 0x15D44F49, 0x939B6F21, 0x542ACFE9 }
	TAG_BLOCK(
		commandLinkBlock_block,
		"commandLinkBlock",
		CommandDispatcher::MAX_LINKS,
		"s_command_link_definition",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		COMMANDLINKBLOCK_ID)
	{
		{ _field_long_enum, "Trigger", FIELD_FLAG_INDEX, &internal_event_enum_definition },
		{ _field_long_block_index, "Target", &scenario_object_names_block },
		{ _field_long_enum, "Command", &command_event_enum_definition },
		{ _field_real, "Delay (sec)" },
		{ _field_long_flags, "Flags", &commandLinkFlags },
		{ _field_terminator }
	};

	#define PATHFINDING_OBJECT_INDEX_LIST_BLOCK_ID { 0x37C77D68, 0xF2954BAD, 0xA5D4509E, 0xBAE0F213 }
	TAG_BLOCK(
		pathfinding_object_index_list_block,
		"pathfinding_object_index_list_block",
		MAXIMUM_STRUCTURE_BSPS_PER_SCENARIO,
		"pathfinding_object_index_list",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PATHFINDING_OBJECT_INDEX_LIST_BLOCK_ID)
	{
		{ _field_short_integer, "bsp index" },
		{ _field_short_integer, "pathfinding object index" },
		{ _field_terminator }
	};

	#define SCENARIO_GIANT_BLOCK_ID { 0xD4AC3CB5, 0x4E5541D4, 0xA63121B6, 0x364F882E }
	TAG_BLOCK(
		scenario_giant_block,
		"scenario_giant_block",
		MAXIMUM_GIANT_DATUMS_PER_SCENARIO,
		"scenario_giant_block",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_GIANT_BLOCK_ID)
	{
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_filter),
		{ _field_short_block_index, "type", &scenario_giant_palette_block, _field_id_type },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_filter),
		{ _field_short_block_index, "name", FIELD_FLAG_INDEX, &scenario_object_names_block, _field_id_name },
		{ _field_struct, "object data", &scenario_object_datum_struct },
		{ _field_struct, "permutation data", &scenario_object_permutation_struct },
		{ _field_struct, "unit data", &scenario_unit_struct },
		{ _field_struct, "giant data", &scenario_giant_datum_struct },
		{ _field_terminator }
	};

	#define SCENARIO_GIANT_PALETTE_BLOCK_ID { 0xFCCBF08D, 0xF4FD4CD9, 0xFD7E48BE, 0xFF3F3102 }
	TAG_BLOCK(
		scenario_giant_palette_block,
		"scenario_giant_palette_block",
		MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK,
		"scenario_object_palette_entry",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_GIANT_PALETTE_BLOCK_ID)
	{
		{ _field_tag_reference, "name", FIELD_FLAG_INDEX, &giant_reference },
		{ _field_terminator }
	};

	#define SCENARIO_BIPED_BLOCK_ID { 0xD9AC3CB5, 0x4EB541D4, 0xA631C1B6, 0x364F885E }
	TAG_BLOCK(
		scenario_biped_block,
		"scenario_biped_block",
		MAXIMUM_BIPED_DATUMS_PER_SCENARIO,
		"scenario_biped_block",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_BIPED_BLOCK_ID)
	{
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_filter),
		{ _field_short_block_index, "type", &scenario_biped_palette_block, _field_id_type },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_filter),
		{ _field_short_block_index, "name", FIELD_FLAG_INDEX, &scenario_object_names_block, _field_id_name },
		{ _field_struct, "object data", &scenario_object_datum_struct },
		{ _field_struct, "permutation data", &scenario_object_permutation_struct },
		{ _field_struct, "unit data", &scenario_unit_struct },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 1 },
		{ _field_struct, "multiplayer data", &scenario_multiplayer_object_struct },

		{ _field_terminator }
	};

	#define SCENARIO_BIPED_PALETTE_BLOCK_ID { 0x3CCBF08D, 0x94FD4CD9, 0x9D7E48BE, 0x7F3F3102 }
	TAG_BLOCK(
		scenario_biped_palette_block,
		"scenario_biped_palette_block",
		MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK,
		"scenario_object_palette_entry",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_BIPED_PALETTE_BLOCK_ID)
	{
		{ _field_tag_reference, "name", FIELD_FLAG_INDEX, &biped_reference },
		{ _field_terminator }
	};

	#define SCENARIO_SCENERY_PALETTE_BLOCK_ID { 0x1A68BAA7, 0xC1684595, 0xAE27EC8D, 0x238EFE5D }
	TAG_BLOCK(
		scenario_scenery_palette_block,
		"scenario_scenery_palette_block",
		MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK,
		"scenario_object_palette_entry",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_SCENERY_PALETTE_BLOCK_ID)
	{
		{ _field_tag_reference, "name", FIELD_FLAG_INDEX, &scenery_reference$4 },
		{ _field_terminator }
	};

	#define SCENARIO_MACHINE_PALETTE_BLOCK_ID { 0x3DD4739B, 0xA07F4861, 0x8F13C5F7, 0xE350E9BA }
	TAG_BLOCK(
		scenario_machine_palette_block,
		"scenario_machine_palette_block",
		MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK,
		"scenario_object_palette_entry",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_MACHINE_PALETTE_BLOCK_ID)
	{
		{ _field_tag_reference, "name", FIELD_FLAG_INDEX, &device_machine_reference },
		{ _field_terminator }
	};

	#define SCENARIO_TERMINAL_PALETTE_BLOCK_ID { 0x1001DE4F, 0xE9CB4A21, 0x95F9A6C4, 0x1FD3B4DF }
	TAG_BLOCK(
		scenario_terminal_palette_block,
		"scenario_terminal_palette_block",
		MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK,
		"scenario_object_palette_entry",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_TERMINAL_PALETTE_BLOCK_ID)
	{
		{ _field_tag_reference, "name", FIELD_FLAG_INDEX, &device_terminal_reference },
		{ _field_terminator }
	};

	#define SCENARIO_CONTROL_PALETTE_BLOCK_ID { 0xFFF11901, 0x16EA4B50, 0x9C997778, 0xE1D7C1A7 }
	TAG_BLOCK(
		scenario_control_palette_block,
		"scenario_control_palette_block",
		MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK,
		"scenario_object_palette_entry",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_CONTROL_PALETTE_BLOCK_ID)
	{
		{ _field_tag_reference, "name", FIELD_FLAG_INDEX, &device_control_reference },
		{ _field_terminator }
	};

	#define SCENARIODISPENSERPALETTEBLOCK_ID { 0x053B17F4, 0x02124761, 0xAE5E9461, 0x1EF58F3A }
	TAG_BLOCK(
		ScenarioDispenserPaletteBlock_block,
		"ScenarioDispenserPaletteBlock",
		MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK,
		"scenario_object_palette_entry",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIODISPENSERPALETTEBLOCK_ID)
	{
		{ _field_tag_reference, "name", FIELD_FLAG_INDEX, &device_dispenser_reference },
		{ _field_terminator }
	};

	#define SCENARIO_SOUND_SCENERY_PALETTE_BLOCK_ID { 0x26AD173B, 0xA3964E5A, 0x8CB3FCC2, 0x50965380 }
	TAG_BLOCK(
		scenario_sound_scenery_palette_block,
		"scenario_sound_scenery_palette_block",
		MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK,
		"scenario_object_palette_entry",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_SOUND_SCENERY_PALETTE_BLOCK_ID)
	{
		{ _field_tag_reference, "name", FIELD_FLAG_INDEX, &sound_scenery_reference },
		{ _field_terminator }
	};

	#define SCENARIO_CRATE_PALETTE_BLOCK_ID { 0x551E40AB, 0x0E4A4D8D, 0x90123759, 0xFD13FAFA }
	TAG_BLOCK(
		scenario_crate_palette_block,
		"scenario_crate_palette_block",
		MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK,
		"scenario_object_palette_entry",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_CRATE_PALETTE_BLOCK_ID)
	{
		{ _field_tag_reference, "name", FIELD_FLAG_INDEX, &crate_reference$6 },
		{ _field_terminator }
	};

	#define SCENARIO_CREATURE_PALETTE_BLOCK_ID { 0x65384A0C, 0x581941A9, 0xB2668441, 0x2732CE0E }
	TAG_BLOCK(
		scenario_creature_palette_block,
		"scenario_creature_palette_block",
		MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK,
		"scenario_object_palette_entry",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_CREATURE_PALETTE_BLOCK_ID)
	{
		{ _field_tag_reference, "name", FIELD_FLAG_INDEX, &creature_reference$2 },
		{ _field_terminator }
	};

	#define SCENARIO_EFFECT_SCENERY_PALETTE_BLOCK_ID { 0xD571AA7C, 0xB1C5453D, 0xA4C230A8, 0x510B0C22 }
	TAG_BLOCK(
		scenario_effect_scenery_palette_block,
		"scenario_effect_scenery_palette_block",
		MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK,
		"scenario_object_palette_entry",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_EFFECT_SCENERY_PALETTE_BLOCK_ID)
	{
		{ _field_tag_reference, "name", FIELD_FLAG_INDEX, &effect_scenery_reference$2 },
		{ _field_terminator }
	};

	#define SCENARIO_SPAWNER_PALETTE_BLOCK_ID { 0xA5729622, 0xFDA148E8, 0xAF77D8D2, 0x33E63AFB }
	TAG_BLOCK(
		scenario_spawner_palette_block,
		"scenario_spawner_palette_block",
		MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK,
		"scenario_object_palette_entry",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_SPAWNER_PALETTE_BLOCK_ID)
	{
		{ _field_tag_reference, "name", FIELD_FLAG_INDEX, &spawner_reference },
		{ _field_terminator }
	};

	#define SCENARIO_SCENERY_BLOCK_ID { 0x283E4BAF, 0x0A4B4423, 0xAFFCC242, 0xC3BDCB2D }
	TAG_BLOCK(
		scenario_scenery_block,
		"scenario_scenery_block",
		MAXIMUM_SCENERY_DATUMS_PER_SCENARIO,
		"scenario_scenery_block",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_SCENERY_BLOCK_ID)
	{
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_filter),
		{ _field_short_block_index, "type", &scenario_scenery_palette_block, _field_id_type },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_filter),
		{ _field_short_block_index, "name", FIELD_FLAG_INDEX, &scenario_object_names_block, _field_id_name },
		{ _field_struct, "object data", &scenario_object_datum_struct },
		{ _field_struct, "permutation data", &scenario_object_permutation_struct },
		{ _field_struct, "scenery data", &scenario_scenery_datum_struct_v4 },
		{ _field_struct, "multiplayer data", &scenario_multiplayer_object_struct },
		{ _field_terminator }
	};

	#define SCENARIO_EQUIPMENT_BLOCK_ID { 0x1B8D7978, 0x0A1543A4, 0xAA855C05, 0x9DF77483 }
	TAG_BLOCK(
		scenario_equipment_block,
		"scenario_equipment_block",
		MAXIMUM_EQUIPMENT_DATUMS_PER_SCENARIO,
		"scenario_equipment_block",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_EQUIPMENT_BLOCK_ID)
	{
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_filter),
		{ _field_short_block_index, "type", &scenario_equipment_palette_block, _field_id_type },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_filter),
		{ _field_short_block_index, "name", FIELD_FLAG_INDEX, &scenario_object_names_block, _field_id_name },
		{ _field_struct, "object data", &scenario_object_datum_struct },
		{ _field_struct, "equipment data", &scenario_equipment_datum_struct },
		{ _field_struct, "multiplayer data", &scenario_multiplayer_object_struct },
		{ _field_terminator }
	};

	#define SCENARIO_WEAPON_BLOCK_ID { 0x687A60CA, 0x9BB94DE2, 0xB92F066B, 0x24108BC6 }
	TAG_BLOCK(
		scenario_weapon_block,
		"scenario_weapon_block",
		MAXIMUM_WEAPON_DATUMS_PER_SCENARIO,
		"scenario_weapon_block",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_WEAPON_BLOCK_ID)
	{
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_filter),
		{ _field_short_block_index, "type", &scenario_weapon_palette_block, _field_id_type },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_filter),
		{ _field_short_block_index, "name", FIELD_FLAG_INDEX, &scenario_object_names_block, _field_id_name },
		{ _field_struct, "object data", &scenario_object_datum_struct },
		{ _field_struct, "permutation data", &scenario_object_permutation_struct },
		{ _field_struct, "weapon data", &scenario_weapon_datum_struct },
		{ _field_struct, "multiplayer data", &scenario_multiplayer_object_struct },
		{ _field_terminator }
	};

	#define DEVICE_GROUP_BLOCK_ID { 0xACEBB874, 0x1E6A4C32, 0x839122F6, 0x6729B33B }
	TAG_BLOCK(
		device_group_block,
		"device_group_block",
		MAXIMUM_DEVICE_GROUPS_PER_SCENARIO,
		"scenario_device_group",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		DEVICE_GROUP_BLOCK_ID)
	{
		{ _field_string, "name", FIELD_FLAG_INDEX },
		{ _field_real, "initial value", nullptr, nullptr, "[0,1]" },
		{ _field_long_flags, "flags", &device_group_flags },
		{ _field_short_block_index, "editor folder", FIELD_FLAG_UNKNOWN0, &g_scenario_editor_folder_block, _field_id_hide },
		FIELD_PAD("WAFNDIO", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	#define SCENARIO_MACHINE_BLOCK_ID { 0xC7CF0D75, 0x5D864949, 0x8F05E50B, 0x8F928F88 }
	TAG_BLOCK(
		scenario_machine_block,
		"scenario_machine_block",
		MAXIMUM_MACHINE_DATUMS_PER_SCENARIO,
		"scenario_machine_block",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_MACHINE_BLOCK_ID)
	{
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_filter),
		{ _field_short_block_index, "type", &scenario_machine_palette_block, _field_id_type },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_filter),
		{ _field_short_block_index, "name", FIELD_FLAG_INDEX, &scenario_object_names_block, _field_id_name },
		{ _field_struct, "object data", &scenario_object_datum_struct },
		{ _field_struct, "permutation data", &scenario_object_permutation_struct },
		{ _field_struct, "device data", &scenario_device_struct },
		{ _field_struct, "machine data", &scenario_machine_struct_v3 },
		{ _field_struct, "multiplayer data", &scenario_multiplayer_object_struct },
		{ _field_terminator }
	};

	#define SCENARIO_TERMINAL_BLOCK_ID { 0x9BE62BD0, 0xCD8E4FD7, 0xABCBDF23, 0x3BE7133D }
	TAG_BLOCK(
		scenario_terminal_block,
		"scenario_terminal_block",
		MAXIMUM_TERMINAL_DATUMS_PER_SCENARIO,
		"s_scenario_terminal",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_TERMINAL_BLOCK_ID)
	{
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_filter),
		{ _field_short_block_index, "type", &scenario_terminal_palette_block, _field_id_type },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_filter),
		{ _field_short_block_index, "name", FIELD_FLAG_INDEX, &scenario_object_names_block, _field_id_name },
		{ _field_struct, "object data", &scenario_object_datum_struct },
		{ _field_struct, "permutation data", &scenario_object_permutation_struct },
		{ _field_struct, "device data", &scenario_device_struct },
		{ _field_struct, "terminal data", &scenario_terminal_struct },
		{ _field_terminator }
	};

	#define SCENARIO_CONTROL_BLOCK_ID { 0x92F483D9, 0x5B3C4AB8, 0xA3EBB7C5, 0x346983EF }
	TAG_BLOCK(
		scenario_control_block,
		"scenario_control_block",
		MAXIMUM_CONTROL_DATUMS_PER_SCENARIO,
		"scenario_control_block",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_CONTROL_BLOCK_ID)
	{
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_filter),
		{ _field_short_block_index, "type", &scenario_control_palette_block, _field_id_type },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_filter),
		{ _field_short_block_index, "name", FIELD_FLAG_INDEX, &scenario_object_names_block, _field_id_name },
		{ _field_struct, "object data", &scenario_object_datum_struct },
		{ _field_struct, "permutation data", &scenario_object_permutation_struct },
		{ _field_struct, "device data", &scenario_device_struct },
		{ _field_struct, "control data", &scenario_control_struct },
		{ _field_struct, "multiplayer data", &scenario_multiplayer_object_struct },
		{ _field_terminator }
	};

	#define SCENARIODISPENSERBLOCK_ID { 0x39795D38, 0x466141C4, 0xAFC2C37E, 0x99484D07 }
	TAG_BLOCK(
		ScenarioDispenserBlock_block,
		"ScenarioDispenserBlock",
		MAXIMUM_DISPENSER_DATUMS_PER_SCENARIO,
		"ScenarioDispenser",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIODISPENSERBLOCK_ID)
	{
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_filter),
		{ _field_short_block_index, "type", &ScenarioDispenserPaletteBlock_block, _field_id_type },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_filter),
		{ _field_short_block_index, "name", FIELD_FLAG_INDEX, &scenario_object_names_block, _field_id_name },
		{ _field_struct, "object data", &scenario_object_datum_struct },
		{ _field_struct, "permutation data", &scenario_object_permutation_struct },
		{ _field_struct, "device data", &scenario_device_struct },
		{ _field_struct, "dispenser data", &ScenarioDispenserStruct },
		{ _field_struct, "multiplayer data", &scenario_multiplayer_object_struct },
		{ _field_terminator }
	};

	#define SCENARIO_SOUND_SCENERY_BLOCK_ID { 0x3AF565D6, 0x04364ABA, 0xABC4F95D, 0xACF0FE38 }
	TAG_BLOCK(
		scenario_sound_scenery_block,
		"scenario_sound_scenery_block",
		MAXIMUM_SOUND_SCENERY_DATUMS_PER_SCENARIO,
		"scenario_sound_scenery_block",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_SOUND_SCENERY_BLOCK_ID)
	{
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_filter),
		{ _field_short_block_index, "type", &scenario_sound_scenery_palette_block, _field_id_type },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_filter),
		{ _field_short_block_index, "name", FIELD_FLAG_INDEX, &scenario_object_names_block, _field_id_name },
		{ _field_struct, "object data", &scenario_object_datum_struct },
		{ _field_struct, "sound_scenery", &sound_scenery_datum_struct },
		{ _field_terminator }
	};

	#define SCENARIO_EFFECT_SCENERY_BLOCK_ID { 0xAD706F17, 0x252A467B, 0x9484D9A5, 0x64355699 }
	TAG_BLOCK(
		scenario_effect_scenery_block,
		"scenario_effect_scenery_block",
		MAXIMUM_EFFECT_SCENERY_DATUMS_PER_SCENARIO,
		"scenario_effect_scenery_block",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_EFFECT_SCENERY_BLOCK_ID)
	{
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_filter),
		{ _field_short_block_index, "type", &scenario_effect_scenery_palette_block, _field_id_type },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_filter),
		{ _field_short_block_index, "name", FIELD_FLAG_INDEX, &scenario_object_names_block, _field_id_name },
		{ _field_struct, "object data", &scenario_object_datum_struct },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 1 },
		{ _field_struct, "effect scenery data", &scenario_effect_scenery_datum_struct },

		{ _field_struct, "multiplayer data", &scenario_multiplayer_object_struct },
		{ _field_terminator }
	};

	#define SCENARIO_SPAWNER_BLOCK_ID { 0x5B9D1DC1, 0x4ABA461A, 0xB9DDBE7B, 0xC3B1C86A }
	TAG_BLOCK(
		scenario_spawner_block,
		"scenario_spawner_block",
		MAXIMUM_SPAWNER_DATUMS_PER_SCENARIO,
		"scenario_spawner_block",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_SPAWNER_BLOCK_ID)
	{
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_filter),
		{ _field_short_block_index, "type", &scenario_spawner_palette_block, _field_id_type },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_filter),
		{ _field_short_block_index, "name", FIELD_FLAG_INDEX, &scenario_object_names_block, _field_id_name },
		{ _field_struct, "object data", &scenario_object_datum_struct },
		{ _field_struct, "permutation data", &scenario_object_permutation_struct },
		{ _field_struct, "Entity Data", &ScenarioEntityStruct },
		{ _field_struct, "Spawner Data", &ScenarioSpawnerStruct },
		{ _field_terminator }
	};

	#define SCENARIO_REQUISITION_PALETTE_BLOCK_ID { 0xED8D9979, 0xEF7A4B0A, 0x9F1000C9, 0x368F5409 }
	TAG_BLOCK(
		scenario_requisition_palette_block,
		"scenario_requisition_palette_block",
		MAXIMUM_REQUISITION_MENU_SIZE,
		"scenario_requisition_palette_entry",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_REQUISITION_PALETTE_BLOCK_ID)
	{
		FIELD_EXPLANATION("CUSTOM APPS", nullptr, FIELD_FLAG_NONE, "If you want the award to be a custom app, point at globals/custom_app_globals, and match one of the names from that tag for \"display_name\""),
		{ _field_tag_reference, "name", FIELD_FLAG_INDEX, &scenario_requisition_palette_block_name_reference },
		{ _field_tag_reference, "second name", FIELD_FLAG_INDEX, &scenario_requisition_palette_block_name_reference },
		{ _field_tag_reference, "third name", FIELD_FLAG_INDEX, &scenario_requisition_palette_block_name_reference },
		{ _field_string_id, "display_name", FIELD_FLAG_INDEX },
		{ _field_long_enum, "Submenu", "controls which requisition submenu this object should appear in", &requisition_submenu_global_enum },
		{ _field_long_integer, "maximum allowed", "cant buy more if there are too many in play" },
		{ _field_real, "price per instance" },
		{ _field_string_id, "model variant name" },
		{ _field_real, "bounty for destruction" },
		{ _field_short_integer, "min fireteam tier", "0=Bronze, 1=Silver, or 2=Gold" },
		{ _field_byte_integer, "additional frag grenades" },
		{ _field_byte_integer, "additional plasma grenades" },
		{ _field_long_flags, "built-in palettes for which item is enabled by default", &scenario_requisition_palette_presence },
		{ _field_long_enum, "special buy", &requisition_special_buy_enum },
		{ _field_long_integer, "starting ammo", "1..100 for ammoless weapons, 0 = default for all weapons" },
		{ _field_real, "warm-up time", "item will be unavailable until x seconds into the scenario", "seconds" },
		{ _field_real, "player purchase frequency", nullptr, "seconds" },
		{ _field_real, "team purchase frequency", nullptr, "seconds" },
		{ _field_real, "price increase factor", "price = original-price x increase-factor to-the n_times_bought" },
		{ _field_byte_integer, "maximum buy count", nullptr, "per player" },
		{ _field_byte_integer, "total maximum buy count", nullptr, "per team" },
		FIELD_PAD("SMYE", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	#define SCENARIO_CRATE_BLOCK_ID { 0x64C39900, 0x24D642E9, 0xAB5396A7, 0x50C5FCDE }
	TAG_BLOCK(
		scenario_crate_block,
		"scenario_crate_block",
		MAXIMUM_CRATE_DATUMS_PER_SCENARIO,
		"s_scenario_crate",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_CRATE_BLOCK_ID)
	{
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_filter),
		{ _field_short_block_index, "type", &scenario_crate_palette_block, _field_id_type },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_filter),
		{ _field_short_block_index, "name", FIELD_FLAG_INDEX, &scenario_object_names_block, _field_id_name },
		{ _field_struct, "object data", &scenario_object_datum_struct },
		{ _field_struct, "permutation data", &scenario_object_permutation_struct },
		{ _field_struct, "crate data", &scenario_crate_datum_struct },
		{ _field_struct, "multiplayer data", &scenario_multiplayer_object_struct },
		{ _field_terminator }
	};

	#define SCENARIO_CREATURE_BLOCK_ID { 0x09DFDC77, 0xD7B340DD, 0x98945C37, 0x64786346 }
	TAG_BLOCK(
		scenario_creature_block,
		"scenario_creature_block",
		MAXIMUM_CREATURE_DATUMS_PER_SCENARIO,
		"s_scenario_creature",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_CREATURE_BLOCK_ID)
	{
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_filter),
		{ _field_short_block_index, "type", &scenario_creature_palette_block, _field_id_type },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_filter),
		{ _field_short_block_index, "name", FIELD_FLAG_INDEX, &scenario_object_names_block, _field_id_name },
		{ _field_struct, "object data", &scenario_object_datum_struct },
		{ _field_terminator }
	};

	#define SCENARIO_OBJECT_ID_STRUCT_ID { 0xA40A1401, 0xDE4B45AE, 0xB47F4714, 0x99C39E7B }
	TAG_STRUCT(
		scenario_object_id_struct,
		"scenario_object_id_struct",
		"c_object_identifier",
		SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_OBJECT_ID_STRUCT_ID)
	{
		{ _field_long_integer, "unique id", FIELD_FLAG_READ_ONLY, _field_id_object_id },
		{ _field_short_block_index, "origin bsp index", FIELD_FLAG_READ_ONLY, &scenario_structure_bsp_reference_block, _field_id_object_id },
		{ _field_char_enum, "type", FIELD_FLAG_READ_ONLY, &object_type_enum_definition, _field_id_object_id },
		{ _field_char_enum, "source", FIELD_FLAG_READ_ONLY, &object_source_enum_definition, _field_id_object_id },
		{ _field_terminator }
	};

	#define SCENARIO_OBJECT_DATUM_STRUCT_ID { 0xB2D98DC9, 0xF27A4A22, 0xB6CD6942, 0x27B43F20 }
	TAG_STRUCT(
		scenario_object_datum_struct,
		"scenario_object_datum_struct",
		"scenario_object_datum_struct",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_OBJECT_DATUM_STRUCT_ID)
	{
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_object_editor),
		{ _field_long_flags, "placement flags", &object_location_placement_flags },
		{ _field_real_point_3d, "position", _field_id_point },
		{ _field_real_euler_angles_3d, "rotation", _field_id_orientation },
		{ _field_real, "scale", _field_id_scale },
		{ _field_block, "node orientations", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &scenario_object_node_orientations_block },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 4 },
		FIELD_PAD("YEE", nullptr, FIELD_FLAG_NONE, 3), // #TODO: Poke around these values
		{ _field_char_enum, "bsp policy", &scenario_object_bsp_placement_policy_definition, _field_id_enum },
		{ _field_legacy, _field_short_integer, "manual bsp flags*" },
		FIELD_PAD("YEET", nullptr, FIELD_FLAG_NONE, 2), // #TODO: Poke around these values

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 8 },
		{ _field_real, "gravity override" },
		{ _field_byte_flags, "gravity flags", &object_gravity_flags },
		FIELD_PAD("ZEE", nullptr, FIELD_FLAG_NONE, 1),
		{ _field_char_enum, "bsp policy", &scenario_object_bsp_placement_policy_definition, _field_id_enum },
		{ _field_byte_flags, "script flags", &scenarioObjectScriptFlagsDefinition },
		{ _field_block, "force enabled scripts", &scriptListBlock_block },
		{ _field_block, "disabled scripts", &scriptListBlock_block },
		{ _field_struct, "manual bsp flags", FIELD_FLAG_READ_ONLY, &manualBspFlagsReferences },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 5 },
		{ _field_word_flags, "transform flags", FIELD_FLAG_UNKNOWN0, &object_transform_flags },
		{ _field_char_enum, "Nav Mesh Cutting", &NavMeshCuttingOverrideEnum },
		{ _field_char_enum, "Nav Mesh Obstacle", &BooleanOverrideEnum },
		{ _field_byte_flags, "Nav Mesh Flags", &object_navmesh_flags },
		FIELD_PAD("ZEE2", nullptr, FIELD_FLAG_NONE, 3),

		{ _field_string_id, "light airprobe name" },
		{ _field_struct, "object id", &scenario_object_id_struct },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_long_flags, "Light Channels", &channelDefinitionFlags },
		{ _field_non_cache_runtime_value, "runtimeObjectHandle", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },

		{ _field_short_block_index, "editor folder", FIELD_FLAG_UNKNOWN0, &g_scenario_editor_folder_block, _field_id_hide },
		FIELD_PAD("NCIUNE", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_struct, "parent id", &scenario_object_parent_struct },
		{ _field_long_block_flags, "can attach to bsp flags", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &scenario_structure_bsp_reference_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_real, "Directional Acceleration Mult. ", "Multiplier applied to all phantoms' direction acceleration factors.  Used to scale man-cannon strength." },
		{ _field_block, "Command Links", &commandLinkBlock_block },

		{ _field_terminator }
	};

	#define SCENARIO_OBJECT_PARENT_STRUCT_ID { 0xC16E1FE3, 0xC0AA4656, 0x95075B5F, 0x41BB4DF4 }
	TAG_STRUCT(
		scenario_object_parent_struct,
		"scenario_object_parent_struct",
		"s_scenario_object_parent",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_OBJECT_PARENT_STRUCT_ID)
	{
		FIELD_PAD("der", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_short_block_index, "parent object", "if an object with this name exists, we attach to it as a child", &scenario_object_names_block },
		{ _field_string_id, "parent marker" },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_marker),
		{ _field_string_id, "connection marker" },
		{ _field_terminator }
	};

	#define SCENARIO_OBJECT_PERMUTATION_STRUCT_ID { 0x03BD8F07, 0x22A74669, 0xA02A4C64, 0x096D3305 }
	TAG_STRUCT(
		scenario_object_permutation_struct,
		"scenario_object_permutation_struct",
		"s_scenario_object_permutation",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_OBJECT_PERMUTATION_STRUCT_ID)
	{
		{ _field_string_id, "variant name", _field_id_object_variant },
		{ _field_byte_flags, "active change colors", &scenario_object_active_change_color_flags },
		FIELD_PAD("SLCJNEROH", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_rgb_color, "primary color" },
		{ _field_rgb_color, "secondary color" },
		{ _field_rgb_color, "tertiary color" },
		{ _field_rgb_color, "quaternary color" },
		{ _field_terminator }
	};

	#define SCENARIO_UNIT_STRUCT_ID { 0xF7C25813, 0x7E524E9D, 0x89F06521, 0x97EDBB16 }
	TAG_STRUCT(
		scenario_unit_struct,
		"scenario_unit_struct",
		"s_scenario_unit_datum",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_UNIT_STRUCT_ID)
	{
		{ _field_real, "body vitality", nullptr, nullptr, "[0,1]" },
		{ _field_long_flags, "flags", &scenario_unit_datum_flags },
		{ _field_terminator }
	};

	#define SCENARIO_MULTIPLAYER_OBJECT_STRUCT_ID { 0xD7949B53, 0x207B47B5, 0x99E1EB91, 0x29AF1E16 }
	TAG_STRUCT(
		scenario_multiplayer_object_struct,
		"scenario_multiplayer_object_struct",
		"s_scenario_multiplayer_object_properties",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_POSTPROCESS_RECURSIVELY | SET_IS_MEMCPYABLE | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_MULTIPLAYER_OBJECT_STRUCT_ID)
	{
		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 23 },
		{ _field_legacy, _field_explanation, "Multiplayer Data", "object data for multiplayer game use" },
		{ _field_legacy, _field_string, "megalo label" },
		{ _field_legacy, _field_long_enum, "game engine symmetric placement", &game_engine_symmetry_placement_flags },
		{ _field_legacy, _field_byte_flags, "game engine flags", &global_game_engine_type_flags },
		{ _field_legacy, _field_char_enum, "owner team", &global_multiplayer_team_designator_enum_definition },
		{ _field_legacy, _field_pad, "pad", 2 },
		{ _field_legacy, _field_char_integer, "unknown" },
		{ _field_legacy, _field_char_integer, "quota minimum" },
		{ _field_legacy, _field_char_integer, "quota maximum:<=0 for unlimited" },
		{ _field_legacy, _field_byte_flags, "spawn flags", &multiplayer_object_placement_spawn_flags },
		{ _field_legacy, _field_short_integer, "spawn time:seconds" },
		{ _field_legacy, _field_short_integer, "abandonment time:seconds" },
		{ _field_legacy, _field_real, "boundary width or radius" },
		{ _field_legacy, _field_real, "boundary box length" },
		{ _field_legacy, _field_real, "boundary positive height" },
		{ _field_legacy, _field_real, "boundary negative height" },
		{ _field_legacy, _field_char_enum, "boundary shape", &multiplayer_goal_area_boundary_shape_enum },
		{ _field_legacy, _field_pad, "boundary_pad", 1 },
		{ _field_legacy, _field_char_enum, "teleporter channel", &multiplayer_teleporter_channel },
		{ _field_legacy, _field_byte_flags, "teleporter passability", &teleporter_passability_flags },
		{ _field_legacy, _field_string_id, "location name" },
		{ _field_legacy, _field_struct, "map variant parent", &scenario_object_parent_struct },
		{ _field_legacy, _field_pad, "unknown", 4 },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 27 },
		FIELD_EXPLANATION("Multiplayer Data", nullptr, FIELD_FLAG_NONE, "object data for multiplayer game use"),
		{ _field_string, "megalo label" },
		{ _field_string, "megalo label 2" },
		{ _field_string, "megalo label 3" },
		{ _field_string, "megalo label 4" },
		{ _field_char_enum, "game engine symmetric placement", &game_engine_symmetry_placement_flags },
		{ _field_byte_flags, "game engine flags", &global_game_engine_type_flags },
		{ _field_char_enum, "owner team", &global_multiplayer_team_designator_enum_definition },
		{ _field_byte_flags, "spawn flags", &multiplayer_object_placement_spawn_flags },
		{ _field_char_integer, "quota minimum" },
		{ _field_char_integer, "quota maximum", nullptr, "<=0 for unlimited" },
		{ _field_char_enum, "remapping policy", &multiplayer_object_remapping_policy },
		{ _field_char_enum, "teleporter channel", &multiplayer_teleporter_channel },
		{ _field_byte_flags, "teleporter passability", &teleporter_passability_flags },
		{ _field_char_integer, "spawn order", nullptr, "-1 for random" },
		{ _field_char_integer, "user data 2" },
		{ _field_char_enum, "trait zone channel", &multiplayer_teleporter_channel },
		{ _field_real, "boundary width or radius" },
		{ _field_real, "boundary box length" },
		{ _field_real, "boundary positive height" },
		{ _field_real, "boundary negative height" },
		{ _field_char_enum, "boundary shape", &multiplayer_goal_area_boundary_shape_enum },
		FIELD_PAD("boundary_pad", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_short_integer, "spawn time", nullptr, "seconds" },
		{ _field_short_integer, "abandonment time", nullptr, "seconds" },
		{ _field_string_id, "location name" },
		{ _field_struct, "map variant parent", &scenario_object_parent_struct },

		{ _field_terminator }
	};

	#define SCENARIO_VEHICLE_DATUM_STRUCT_ID { 0x252FB584, 0x7A834CE5, 0xA99C3145, 0x49D3CD60 }
	TAG_STRUCT(
		scenario_vehicle_datum_struct,
		"scenario_vehicle_datum_struct",
		"s_scenario_vehicle_datum",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_VEHICLE_DATUM_STRUCT_ID)
	{
		{ _field_enum, "Pathfinding policy", &pathfinding_policy_enum },
		FIELD_PAD("post-pathfinding", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_block, "pathfinding references", FIELD_FLAG_READ_ONLY, &pathfinding_object_index_list_block },
		{ _field_terminator }
	};

	#define SCENARIO_GIANT_DATUM_STRUCT_ID { 0x89405329, 0x890C4F04, 0xB9B87A12, 0x6E648B53 }
	TAG_STRUCT(
		scenario_giant_datum_struct,
		"scenario_giant_datum_struct",
		"s_scenario_giant_datum",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_GIANT_DATUM_STRUCT_ID)
	{
		{ _field_enum, "Pathfinding policy", &pathfinding_policy_enum },
		FIELD_PAD("post-pathfinding", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_block, "pathfinding references", FIELD_FLAG_READ_ONLY, &pathfinding_object_index_list_block },
		{ _field_terminator }
	};

	#define SCENARIO_OBJECT_REFERENCE_STRUCT_ID { 0xA40BCD01, 0xDE0AB5AE, 0xB12F4714, 0xAAC39E7B }
	TAG_STRUCT(
		scenario_object_reference_struct,
		"scenario_object_reference_struct",
		"s_scenario_object_reference",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_OBJECT_REFERENCE_STRUCT_ID)
	{
		{ _field_short_integer, "object index", FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "scenario object index", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define SCENARIO_SCENERY_DATUM_STRUCT_V4_ID { 0xECD107BB, 0x32A143B7, 0x934D8DC0, 0x0B606F2D }
	TAG_STRUCT(
		scenario_scenery_datum_struct_v4,
		"scenario_scenery_datum_struct_v4",
		"s_scenario_scenery_datum",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_SCENERY_DATUM_STRUCT_V4_ID)
	{
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_pathfinding),
		{ _field_enum, "Pathfinding policy", &pathfinding_policy_enum },
		{ _field_enum, "Lightmapping policy", &scenery_lightmap_policy_enum },
		{ _field_block, "pathfinding references", FIELD_FLAG_READ_ONLY, &pathfinding_object_index_list_block },
		{ _field_short_integer, "havok mopp index", FIELD_FLAG_UNKNOWN0 },
		{ _field_short_block_index, "ai spawning squad", &squads_block },
		{ _field_terminator }
	};

	#define SCENARIO_EQUIPMENT_DATUM_STRUCT_ID { 0x48D20C56, 0x8B844C52, 0xA0DA0D7B, 0x0B10F54A }
	TAG_STRUCT(
		scenario_equipment_datum_struct,
		"scenario_equipment_datum_struct",
		"s_scenario_equipment_datum",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_EQUIPMENT_DATUM_STRUCT_ID)
	{
		{ _field_long_flags, "equipment flags", &scenario_equipment_flags_definition },
		{ _field_terminator }
	};

	#define SCENARIO_WEAPON_DATUM_STRUCT_ID { 0x95BC43BA, 0xC6EF42C5, 0x95BA7855, 0x50A05B6F }
	TAG_STRUCT(
		scenario_weapon_datum_struct,
		"scenario_weapon_datum_struct",
		"s_scenario_weapon_datum",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_WEAPON_DATUM_STRUCT_ID)
	{
		{ _field_short_integer, "rounds left" },
		{ _field_short_integer, "rounds loaded" },
		{ _field_long_flags, "flags", &scenario_weapon_datum_flags },
		{ _field_terminator }
	};

	#define SCENARIO_DEVICE_STRUCT_ID { 0xF3F2B599, 0x93524F63, 0xBF5BD676, 0x6FD79D9E }
	TAG_STRUCT(
		scenario_device_struct,
		"scenario_device_struct",
		"s_scenario_device_datum",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_DEVICE_STRUCT_ID)
	{
		{ _field_short_block_index, "power group", &device_group_block },
		{ _field_short_block_index, "position group", &device_group_block },
		{ _field_long_flags, "flags", &scenario_device_flags },
		{ _field_terminator }
	};

	#define SCENARIO_MACHINE_STRUCT_V3_ID { 0x43A76E9A, 0xA1E24E63, 0xA60DD607, 0x83C2C762 }
	TAG_STRUCT(
		scenario_machine_struct_v3,
		"scenario_machine_struct_v3",
		"s_scenario_machine_datum",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_MACHINE_STRUCT_V3_ID)
	{
		{ _field_long_flags, "flags", &scenario_machine_flags },
		{ _field_block, "pathfinding references", FIELD_FLAG_READ_ONLY, &pathfinding_object_index_list_block },
		{ _field_enum, "pathfinding policy", &scenario_machine_pathfinding_policy_enum },
		FIELD_PAD("post-pathfinding-policy", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	#define SCENARIO_TERMINAL_STRUCT_ID { 0x167BF1D1, 0x8FF44C03, 0xB1C1085B, 0xF16DB71F }
	TAG_STRUCT(
		scenario_terminal_struct,
		"scenario_terminal_struct",
		"s_scenario_terminal_datum",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_TERMINAL_STRUCT_ID)
	{
		{ _field_long_integer, "pah pah" },
		{ _field_terminator }
	};

	#define SCENARIO_CONTROL_STRUCT_ID { 0x4C0DFF56, 0xAB5E4908, 0xBC8FEA48, 0x712465AA }
	TAG_STRUCT(
		scenario_control_struct,
		"scenario_control_struct",
		"s_scenario_control_datum",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_CONTROL_STRUCT_ID)
	{
		{ _field_long_flags, "flags", &scenario_control_flags },
		{ _field_short_integer, "DON'T TOUCH THIS", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, _field_id_unknown_ugh },
		{ _field_short_integer, "health station charges", "if this control is a health station, this sets the number of charges it contains.\nUse 0 for infinite" },
		{ _field_enum, "allowed players", &scenario_control_character_types },
		FIELD_PAD("SCSP1", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	#define SCENARIODISPENSERSTRUCT_ID { 0x84208927, 0xD6114C54, 0xA8CE7861, 0xB638A761 }
	TAG_STRUCT(
		ScenarioDispenserStruct,
		"ScenarioDispenserStruct",
		"ScenarioDispenserDatum",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIODISPENSERSTRUCT_ID)
	{
		{ _field_byte_flags, "flags", &ScenarioDispenserFlags },
		FIELD_PAD("pad", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_terminator }
	};

	#define SOUND_SCENERY_DATUM_STRUCT_ID { 0xF092A3CD, 0x392B463A, 0xAA23EE22, 0x2BC855E2 }
	TAG_STRUCT(
		sound_scenery_datum_struct,
		"sound_scenery_datum_struct",
		"s_scenario_sound_scenery_datum",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SOUND_SCENERY_DATUM_STRUCT_ID)
	{
		{ _field_long_enum, "volume type", &sound_volume_type_enumeration },
		{ _field_real, "height" },
		{ _field_angle_bounds, "override cone angle bounds" },
		{ _field_real, "override outer cone gain", nullptr, "dB" },
		{ _field_struct, "override distance parameters", &sound_distance_parameters_struct },
		{ _field_terminator }
	};

	#define SCENARIO_EFFECT_SCENERY_DATUM_STRUCT_ID { 0xAECBC47E, 0xC5FD4495, 0x9C908F2E, 0x2C4FAD95 }
	TAG_STRUCT(
		scenario_effect_scenery_datum_struct,
		"scenario_effect_scenery_datum_struct",
		"ScenarioEffectSceneryDatum",
		SET_POSTPROCESS_RECURSIVELY | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_EFFECT_SCENERY_DATUM_STRUCT_ID)
	{
		{ _field_real, "effect size scale" },
		{ _field_terminator }
	};

	#define SCENARIOENTITYSTRUCT_ID { 0x5D32E50B, 0x2D59498A, 0xB59C777F, 0x8DE7F945 }
	TAG_STRUCT(
		ScenarioEntityStruct,
		"ScenarioEntityStruct",
		"ScenarioEntityDatum",
		SET_POSTPROCESS_RECURSIVELY | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIOENTITYSTRUCT_ID)
	{
		{ _field_real, "Entity Placeholder" },
		{ _field_terminator }
	};

	#define SCENARIOSPAWNERSTRUCT_ID { 0x2A28D8B0, 0x0BA34E72, 0xB05C421E, 0x29871410 }
	TAG_STRUCT(
		ScenarioSpawnerStruct,
		"ScenarioSpawnerStruct",
		"ScenarioSpawnerDatum",
		SET_POSTPROCESS_RECURSIVELY | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIOSPAWNERSTRUCT_ID)
	{
		{ _field_real, "Spawner Placeholder" },
		{ _field_terminator }
	};

	#define SCENARIO_CRATE_DATUM_STRUCT_ID { 0x5B721C93, 0xD3E64C22, 0xAA9B2A15, 0x1614421C }
	TAG_STRUCT(
		scenario_crate_datum_struct,
		"scenario_crate_datum_struct",
		"s_scenario_crate_datum",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_CRATE_DATUM_STRUCT_ID)
	{
		{ _field_enum, "Pathfinding policy", &pathfinding_policy_enum },
		FIELD_PAD("post-path-policy", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_block, "pathfinding references", FIELD_FLAG_READ_ONLY, &pathfinding_object_index_list_block },
		{ _field_terminator }
	};

	STRINGS(object_location_placement_flags)
	{
		"not automatically",
		"unused0",
		"unused1",
		"unused2",
		"lock type to env. object",
		"lock transform to env. object",
		"never placed",
		"lock name to env. object",
		"create at rest",
		"store orientations",
		"pvs bound",
		"startup",
		"attach physically",
		"attach with scale",
		"no parent lighting"
	};
	STRING_LIST(object_location_placement_flags, object_location_placement_flags_strings, _countof(object_location_placement_flags_strings));

	STRINGS(object_gravity_flags)
	{
		"apply override",
		"apply to children also"
	};
	STRING_LIST(object_gravity_flags, object_gravity_flags_strings, _countof(object_gravity_flags_strings));

	STRINGS(object_navmesh_flags)
	{
		"children inherit navmesh interaction",
		"navmesh always loaded"
	};
	STRING_LIST(object_navmesh_flags, object_navmesh_flags_strings, _countof(object_navmesh_flags_strings));

	STRINGS(object_transform_flags)
	{
		"mirrored"
	};
	STRING_LIST(object_transform_flags, object_transform_flags_strings, _countof(object_transform_flags_strings));

	STRINGS(scenario_object_active_change_color_flags)
	{
		"primary",
		"secondary",
		"tertiary",
		"quaternary"
	};
	STRING_LIST(scenario_object_active_change_color_flags, scenario_object_active_change_color_flags_strings, _countof(scenario_object_active_change_color_flags_strings));

	STRINGS(scenarioObjectScriptFlagsDefinition)
	{
		"scripts disabled",
		"use override lists",
		"scripts always run"
	};
	STRING_LIST(scenarioObjectScriptFlagsDefinition, scenarioObjectScriptFlagsDefinition_strings, _countof(scenarioObjectScriptFlagsDefinition_strings));

	STRINGS(object_type_enum_definition)
	{
		"biped",
		"vehicle",
		"weapon",
		"equipment",
		"terminal",
		"projectile",
		"scenery",
		"machine",
		"control",
		"dispenser",
		"sound_scenery",
		"crate",
		"creature",
		"giant",
		"effect_scenery",
		"spawner"
	};
	STRING_LIST(object_type_enum_definition, object_type_enum_definition_strings, _countof(object_type_enum_definition_strings));

	STRINGS(object_source_enum_definition)
	{
		"structure",
		"editor",
		"dynamic",
		"legacy",
		"sky",
		"parent"
	};
	STRING_LIST(object_source_enum_definition, object_source_enum_definition_strings, _countof(object_source_enum_definition_strings));

	STRINGS(command_event_enum_definition)
	{
		"Interact",
		"InitShardSpawn",
		"InitKnightTaint"
	};
	STRING_LIST(command_event_enum_definition, command_event_enum_definition_strings, _countof(command_event_enum_definition_strings));

	STRINGS(internal_event_enum_definition)
	{
		"OnBirth",
		"OnDeath",
		"OnInteract",
		"OnInitSpawnerShard",
		"OnInitKnightTaint"
	};
	STRING_LIST(internal_event_enum_definition, internal_event_enum_definition_strings, _countof(internal_event_enum_definition_strings));

	STRINGS(commandLinkFlags)
	{
		"Fire Once"
	};
	STRING_LIST(commandLinkFlags, commandLinkFlags_strings, _countof(commandLinkFlags_strings));

	STRINGS(scenario_object_bsp_placement_policy_definition)
	{
		"default",
		"always placed",
		"manual bsp placement"
	};
	STRING_LIST(scenario_object_bsp_placement_policy_definition, scenario_object_bsp_placement_policy_definition_strings, _countof(scenario_object_bsp_placement_policy_definition_strings));

	STRINGS(game_engine_symmetry_placement_flags)
	{
		"ignore",
		"symmetric",
		"asymmetric"
	};
	STRING_LIST(game_engine_symmetry_placement_flags, game_engine_symmetry_placement_flags_strings, _countof(game_engine_symmetry_placement_flags_strings));

	STRINGS(global_game_engine_type_flags)
	{
		"none",
		"sandbox",
		"megalogamengine",
		"campaign",
		"survival",
		"firefight"
	};
	STRING_LIST(global_game_engine_type_flags, global_game_engine_type_flags_strings, _countof(global_game_engine_type_flags_strings));

	STRINGS(multiplayer_object_remapping_policy)
	{
		"normal-default",
		"do not replace",
		"only replace"
	};
	STRING_LIST(multiplayer_object_remapping_policy, multiplayer_object_remapping_policy_strings, _countof(multiplayer_object_remapping_policy_strings));

	STRINGS(multiplayer_goal_area_boundary_shape_enum)
	{
		"unused",
		"sphere",
		"cylinder",
		"box"
	};
	STRING_LIST(multiplayer_goal_area_boundary_shape_enum, multiplayer_goal_area_boundary_shape_enum_strings, _countof(multiplayer_goal_area_boundary_shape_enum_strings));

	STRINGS(multiplayer_teleporter_channel)
	{
		"alpha",
		"bravo",
		"charlie",
		"delta",
		"echo",
		"foxtrot",
		"golf",
		"hotel",
		"india",
		"juliet",
		"kilo",
		"lima",
		"mike",
		"november",
		"oscar",
		"papa",
		"quebec",
		"romeo",
		"sierra",
		"tango",
		"uniform",
		"victor",
		"whiskey",
		"xray",
		"yankee",
		"zulu"
	};
	STRING_LIST(multiplayer_teleporter_channel, multiplayer_teleporter_channel_strings, _countof(multiplayer_teleporter_channel_strings));

	STRINGS(multiplayer_object_placement_spawn_flags)
	{
		"unique spawn",
		"not initially placed",
		"hide unless megalo required",
		"is shortcut object",
		"can spawn on bipeds",
		"spawner starts inactive"
	};
	STRING_LIST(multiplayer_object_placement_spawn_flags, multiplayer_object_placement_spawn_flags_strings, _countof(multiplayer_object_placement_spawn_flags_strings));

	STRINGS(pathfinding_policy_enum)
	{
		"Tag Default",
		"Pathfinding DYNAMIC",
		"Pathfinding CUT-OUT",
		"Pathfinding STATIC",
		"Pathfinding NONE"
	};
	STRING_LIST(pathfinding_policy_enum, pathfinding_policy_enum_strings, _countof(pathfinding_policy_enum_strings));

	STRINGS(scenery_lightmap_policy_enum)
	{
		"Tag Default",
		"Dynamic",
		"Per-Vertex"
	};
	STRING_LIST(scenery_lightmap_policy_enum, scenery_lightmap_policy_enum_strings, _countof(scenery_lightmap_policy_enum_strings));

	STRINGS(scenario_equipment_flags_definition)
	{
		"OBSOLETE0",
		"OBSOLETE1",
		"does accelerate (moves due to explosions)"
	};
	STRING_LIST(scenario_equipment_flags_definition, scenario_equipment_flags_definition_strings, _countof(scenario_equipment_flags_definition_strings));

	STRINGS(scenario_weapon_datum_flags)
	{
		"initially at rest (doesn\'t fall)",
		"obsolete",
		"does accelerate (moves due to explosions)"
	};
	STRING_LIST(scenario_weapon_datum_flags, scenario_weapon_datum_flags_strings, _countof(scenario_weapon_datum_flags_strings));

	STRINGS(scenario_unit_datum_flags)
	{
		"dead",
		"opened",
		"not enterable by player"
	};
	STRING_LIST(scenario_unit_datum_flags, scenario_unit_datum_flags_strings, _countof(scenario_unit_datum_flags_strings));

	STRINGS(requisition_submenu_global_enum)
	{
		"Support"
	};
	STRING_LIST(requisition_submenu_global_enum, requisition_submenu_global_enum_strings, _countof(requisition_submenu_global_enum_strings));

	STRINGS(scenario_requisition_palette_presence)
	{
		"empty palette",
		"full palette",
		"spartan palette",
		"elite palette"
	};
	STRING_LIST(scenario_requisition_palette_presence, scenario_requisition_palette_presence_strings, _countof(scenario_requisition_palette_presence_strings));

	STRINGS(device_group_flags)
	{
		"can change only once"
	};
	STRING_LIST(device_group_flags, device_group_flags_strings, _countof(device_group_flags_strings));

	STRINGS(scenario_device_flags)
	{
		"initially open (1.0)",
		"initially off (0.0)",
		"can change only once",
		"position reversed",
		"not usable from any side",
		"closes without power"
	};
	STRING_LIST(scenario_device_flags, scenario_device_flags_strings, _countof(scenario_device_flags_strings));

	STRINGS(scenario_machine_flags)
	{
		"does not operate automatically",
		"one-sided",
		"never appears locked",
		"opened by melee attack",
		"one-sided for player",
		"does not close automatically",
		"ignores player",
		"ignores ai"
	};
	STRING_LIST(scenario_machine_flags, scenario_machine_flags_strings, _countof(scenario_machine_flags_strings));

	STRINGS(scenario_machine_pathfinding_policy_enum)
	{
		"default",
		"discs",
		"sectors",
		"cut-out",
		"none"
	};
	STRING_LIST(scenario_machine_pathfinding_policy_enum, scenario_machine_pathfinding_policy_enum_strings, _countof(scenario_machine_pathfinding_policy_enum_strings));

	STRINGS(scenario_control_flags)
	{
		"usable from both sides"
	};
	STRING_LIST(scenario_control_flags, scenario_control_flags_strings, _countof(scenario_control_flags_strings));

	STRINGS(scenario_control_character_types)
	{
		"any",
		"spartan",
		"elite"
	};
	STRING_LIST(scenario_control_character_types, scenario_control_character_types_strings, _countof(scenario_control_character_types_strings));

	STRINGS(ScenarioDispenserFlags)
	{
		"usable from front only"
	};
	STRING_LIST(ScenarioDispenserFlags, ScenarioDispenserFlags_strings, _countof(ScenarioDispenserFlags_strings));

	STRINGS(sound_volume_type_enumeration)
	{
		"sphere",
		"vertical cylinder",
		"pill{volume pill}"
	};
	STRING_LIST(sound_volume_type_enumeration, sound_volume_type_enumeration_strings, _countof(sound_volume_type_enumeration_strings));

} // namespace macaque

} // namespace blofeld

