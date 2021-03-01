#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		multiplayer_object_type_list_group,
		MULTIPLAYER_OBJECT_TYPE_LIST_TAG,
		nullptr,
		INVALID_TAG,
		multiplayer_object_type_list_block );

	TAG_BLOCK_FROM_STRUCT(
		multiplayer_object_type_list_block,
		"multiplayer_object_type_list_block",
		1,
		multiplayer_object_type_list_struct_definition);

	#define MULTIPLAYER_OBJECT_TYPE_BLOCK_ID { 0x817E82BA, 0xFCB54E3E, 0x81A64345, 0x9EDA7B38 }
	TAG_BLOCK(
		multiplayer_object_type_block,
		"multiplayer_object_type_block",
		k_multiplayer_object_type_maximum_count,
		"s_multiplayer_object_type",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		MULTIPLAYER_OBJECT_TYPE_BLOCK_ID)
	{
		FIELD_EXPLANATION("WARNING", nullptr, FIELD_FLAG_NONE, "This block is readonly because adding, removing, reordering, or renaming elements after we ship a map pack will completely break the game.  And I will punch you.  Hard.  In the face."),
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_tag_reference, "object", &object_reference$6 },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(
		multiplayer_weapon_collection_block,
		"multiplayer_weapon_collection_block",
		k_maximum_number_of_multiplayer_weapon_selections,
		multiplayer_object_collection_struct);

	TAG_BLOCK_FROM_STRUCT(
		multiplayer_vehicle_collection_block,
		"multiplayer_vehicle_collection_block",
		k_maximum_number_of_multiplayer_vehicle_selections,
		multiplayer_object_collection_struct);

	TAG_BLOCK_FROM_STRUCT(
		multiplayer_grenade_collection_block,
		"multiplayer_grenade_collection_block",
		k_maximum_number_of_multiplayer_grenade_selections,
		multiplayer_object_collection_struct);

	TAG_BLOCK_FROM_STRUCT(
		multiplayer_equipment_collection_block,
		"multiplayer_equipment_collection_block",
		k_maximum_number_of_multiplayer_equipment_selections,
		multiplayer_object_collection_struct);

	#define MULTIPLAYER_WEAPON_REMAP_TABLE_BLOCK_ID { 0x5D3D9F30, 0x90004CB3, 0x96C20653, 0x745D3F42 }
	TAG_BLOCK(
		multiplayer_weapon_remap_table_block,
		"multiplayer_weapon_remap_table_block",
		k_maximum_number_of_multiplayer_weapon_sets,
		"s_multiplayer_object_remap_table",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		MULTIPLAYER_WEAPON_REMAP_TABLE_BLOCK_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_block, "remap table", &multiplayer_weapon_remap_table_entry_block },
		{ _field_terminator }
	};

	#define MULTIPLAYER_WEAPON_REMAP_TABLE_ENTRY_BLOCK_ID { 0x4C7E7EBC, 0xBF9D4357, 0x8BACB076, 0x3DFC779A }
	TAG_BLOCK(
		multiplayer_weapon_remap_table_entry_block,
		"multiplayer_weapon_remap_table_entry_block",
		k_maximum_number_of_multiplayer_remap_table_entries,
		"s_multiplayer_object_remap_table_entry",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		MULTIPLAYER_WEAPON_REMAP_TABLE_ENTRY_BLOCK_ID)
	{
		{ _field_custom_long_block_index, "from object" },
		{ _field_custom_long_block_index, "to object" },
		{ _field_terminator }
	};

	#define MULTIPLAYER_VEHICLE_REMAP_TABLE_BLOCK_ID { 0xFCC3A7AF, 0x57C246DD, 0x85D85E79, 0x8FA0C8A0 }
	TAG_BLOCK(
		multiplayer_vehicle_remap_table_block,
		"multiplayer_vehicle_remap_table_block",
		k_maximum_number_of_multiplayer_weapon_sets,
		"s_multiplayer_object_remap_table",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		MULTIPLAYER_VEHICLE_REMAP_TABLE_BLOCK_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_block, "remap table", &multiplayer_vehicle_remap_table_entry_block },
		{ _field_terminator }
	};

	#define MULTIPLAYER_VEHICLE_REMAP_TABLE_ENTRY_BLOCK_ID { 0xFD90B365, 0x80804E2F, 0xB147502F, 0x907D75DB }
	TAG_BLOCK(
		multiplayer_vehicle_remap_table_entry_block,
		"multiplayer_vehicle_remap_table_entry_block",
		k_maximum_number_of_multiplayer_remap_table_entries,
		"s_multiplayer_object_remap_table_entry",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		MULTIPLAYER_VEHICLE_REMAP_TABLE_ENTRY_BLOCK_ID)
	{
		{ _field_custom_long_block_index, "from object" },
		{ _field_custom_long_block_index, "to object" },
		{ _field_terminator }
	};

	#define MULTIPLAYER_EQUIPMENT_REMAP_TABLE_BLOCK_ID { 0x81601365, 0x203745A7, 0x851C3490, 0xE5F4EBEA }
	TAG_BLOCK(
		multiplayer_equipment_remap_table_block,
		"multiplayer_equipment_remap_table_block",
		k_maximum_number_of_multiplayer_weapon_sets,
		"s_multiplayer_object_remap_table",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		MULTIPLAYER_EQUIPMENT_REMAP_TABLE_BLOCK_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_block, "remap table", &multiplayer_equipment_remap_table_entry_block },
		{ _field_terminator }
	};

	#define MULTIPLAYER_EQUIPMENT_REMAP_TABLE_ENTRY_BLOCK_ID { 0x282324D8, 0xD01A40AB, 0xB32458CC, 0x06E2FB06 }
	TAG_BLOCK(
		multiplayer_equipment_remap_table_entry_block,
		"multiplayer_equipment_remap_table_entry_block",
		k_maximum_number_of_multiplayer_remap_table_entries,
		"s_multiplayer_object_remap_table_entry",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		MULTIPLAYER_EQUIPMENT_REMAP_TABLE_ENTRY_BLOCK_ID)
	{
		{ _field_custom_long_block_index, "from object" },
		{ _field_custom_long_block_index, "to object" },
		{ _field_terminator }
	};

	#define MULTIPLAYER_OBJECT_TYPE_LIST_STRUCT_DEFINITION_ID { 0x85887EB3, 0x26F44812, 0x81B36A2A, 0x51B63FC9 }
	TAG_STRUCT(
		multiplayer_object_type_list_struct_definition,
		"multiplayer_object_type_list_struct_definition",
		"s_multiplayer_object_type_list",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		MULTIPLAYER_OBJECT_TYPE_LIST_STRUCT_DEFINITION_ID)
	{
		FIELD_EXPLANATION("MEGALO", nullptr, FIELD_FLAG_NONE, "After changing this tag you will need to run the tool command multiplayer-generate-global-object-type-list (once) and rebuild the .mapinfo file for each multiplayer scenario in order to use the new objects in megalo"),
		{ _field_block, "object types", &multiplayer_object_type_block },
		{ _field_block, "weapons", &multiplayer_weapon_collection_block },
		{ _field_block, "vehicles", &multiplayer_vehicle_collection_block },
		{ _field_block, "grenades", &multiplayer_grenade_collection_block },
		{ _field_block, "equipment", &multiplayer_equipment_collection_block },
		FIELD_EXPLANATION("REMAPPING TABLES", nullptr, FIELD_FLAG_NONE, "Note - if a remap table has a single element whose \'from\' is NONE, then every object will be remapped to the \'to\' object"),
		{ _field_block, "weapon remapping", &multiplayer_weapon_remap_table_block },
		{ _field_block, "vehicle remapping", &multiplayer_vehicle_remap_table_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_block, "equipment remapping", &multiplayer_equipment_remap_table_block },

		{ _field_long_integer, "random weapon menu sprite frame" },
		{ _field_long_integer, "random equipment menu sprite frame" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_string_id, "random weapon icon string id" },
		{ _field_string_id, "random equipment icon string id" },

		{ _field_terminator }
	};

	#define MULTIPLAYER_OBJECT_COLLECTION_STRUCT_ID { 0x929B2F5E, 0x14FD4020, 0x87A0C0BE, 0x54A4F353 }
	TAG_STRUCT(
		multiplayer_object_collection_struct,
		"multiplayer_object_collection_struct",
		"s_multiplayer_object_collection_entry",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		MULTIPLAYER_OBJECT_COLLECTION_STRUCT_ID)
	{
		{ _field_long_block_index, "object type", FIELD_FLAG_INDEX, &multiplayer_object_type_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 3 },
		{ _field_string_id, "object description" },
		{ _field_string_id, "object header text" },
		{ _field_string_id, "object help text" },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_long_integer, "unknown" },

		{ _field_real, "random weight" },
		{ _field_long_integer, "loadout menu sprite frame" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_string_id, "icon string id" },

		{ _field_terminator }
	};

	TAG_REFERENCE(global_multiplayer_object_type_list_reference, MULTIPLAYER_OBJECT_TYPE_LIST_TAG);

} // namespace macaque

} // namespace blofeld

