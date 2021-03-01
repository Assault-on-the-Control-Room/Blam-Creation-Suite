#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		cookie_purchase_globals_group,
		COOKIE_PURCHASE_GLOBALS_TAG,
		nullptr,
		INVALID_TAG,
		cookie_purchase_globals_block );

	TAG_BLOCK_FROM_STRUCT(
		cookie_purchase_globals_block,
		"cookie_purchase_globals_block",
		1,
		cookie_purchase_globals_struct_definition);

	#define COOKIEPURCHASEAPPEARANCEDEFINITIONBLOCK_ID { 0x8A8AC979, 0x87C947CB, 0x9A2894E1, 0x6B04E6D1 }
	TAG_BLOCK(
		CookiePurchaseAppearanceDefinitionBlock_block,
		"CookiePurchaseAppearanceDefinitionBlock",
		k_max_cookie_purchase_total_appearance_items,
		"CookiePurchaseAppearanceDefinition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		COOKIEPURCHASEAPPEARANCEDEFINITIONBLOCK_ID)
	{
		{ _field_string_id, "purchase id" },
		{ _field_string_id, "display name", FIELD_FLAG_INDEX },
		{ _field_string_id, "display description" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_string_id, "Exit Experience Aggregate Group Name" },

		{ _field_byte_flags, "flags", &cookie_purchase_flags },
		FIELD_PAD("pad1", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_tag_reference, "display bitmap", &global_bitmap_reference },
		{ _field_long_integer, "sprite index" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_tag_reference, "detail display bitmap", &global_bitmap_reference },

		{ _field_long_integer, "cookie cost" },

		{ _field_legacy, _field_version_equal, _engine_type_haloreach },
		{ _field_legacy, _field_struct, "purchase player appearance", &PurchasePlayerAppearanceStruct_struct_definition }, // moved

		FIELD_CUSTOM("Prerequisites for visibility", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_struct, "visible prerequisites", &PurchasePrerequisitesUnifiedDefinitionBlock },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		FIELD_CUSTOM("Prerequisites for purchasability", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_struct, "purchasable prerequisites", &PurchasePrerequisitesUnifiedDefinitionBlock },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_struct, "purchase player appearance", &PurchasePlayerAppearanceStruct }, // moved

		{ _field_terminator }
	};

	#define COOKIEPURCHASELOADOUTDEFINITIONBLOCK_ID { 0x21D3D862, 0xCB924A2B, 0xBF1F047B, 0x8FB5A80A }
	TAG_BLOCK(
		CookiePurchaseLoadoutDefinitionBlock_block,
		"CookiePurchaseLoadoutDefinitionBlock",
		k_max_cookie_purchase_total_loadout_items,
		"CookiePurchaseLoadoutDefinition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		COOKIEPURCHASELOADOUTDEFINITIONBLOCK_ID)
	{
		{ _field_string_id, "purchase id" },
		{ _field_string_id, "display name", FIELD_FLAG_INDEX },
		{ _field_string_id, "display description" },
		{ _field_string_id, "Exit Experience Aggregate Group Name" },
		{ _field_byte_flags, "flags", &cookie_purchase_flags },
		FIELD_PAD("pad1", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_tag_reference, "display bitmap", &global_bitmap_reference },
		{ _field_long_integer, "sprite index" },
		{ _field_tag_reference, "detail display bitmap", &global_bitmap_reference },
		{ _field_long_integer, "cookie cost" },
		FIELD_CUSTOM("Prerequisites for visibility", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_struct, "visible prerequisites", &PurchasePrerequisitesUnifiedDefinitionBlock },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		FIELD_CUSTOM("Prerequisites for purchasability", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_struct, "purchasable prerequisites", &PurchasePrerequisitesUnifiedDefinitionBlock },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		{ _field_string_id, "icon string id" },
		{ _field_struct, "purchase player loadout", &PurchasePlayerLoadoutStruct },
		{ _field_terminator }
	};

	#define COOKIEPURCHASEORDNANCEDEFINITIONBLOCK_ID { 0x47C9F1A5, 0x3D984016, 0x9C9F2C7A, 0xAB4B242A }
	TAG_BLOCK(
		CookiePurchaseOrdnanceDefinitionBlock_block,
		"CookiePurchaseOrdnanceDefinitionBlock",
		k_max_cookie_purchase_total_ordnance_items,
		"CookiePurchaseOrdnanceDefinition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		COOKIEPURCHASEORDNANCEDEFINITIONBLOCK_ID)
	{
		{ _field_string_id, "purchase id" },
		{ _field_string_id, "display name", FIELD_FLAG_INDEX },
		{ _field_string_id, "display description" },
		{ _field_string_id, "Exit Experience Aggregate Group Name" },
		{ _field_byte_flags, "flags", &cookie_purchase_flags },
		FIELD_PAD("pad1", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_tag_reference, "display bitmap", &global_bitmap_reference },
		{ _field_long_integer, "sprite index" },
		{ _field_tag_reference, "detail display bitmap", &global_bitmap_reference },
		{ _field_long_integer, "cookie cost" },
		FIELD_CUSTOM("Prerequisites for visibility", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_struct, "visible prerequisites", &PurchasePrerequisitesUnifiedDefinitionBlock },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		FIELD_CUSTOM("Prerequisites for purchasability", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_struct, "purchasable prerequisites", &PurchasePrerequisitesUnifiedDefinitionBlock },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		{ _field_struct, "purchase player ordnance", &PurchasePlayerOrdnanceStruct },
		{ _field_terminator }
	};

	#define PURCHASEPLAYERORDNANCEITEMBLOCK_ID { 0xA0B64FD3, 0x6ADB4425, 0xADAD3F94, 0x2604A7D9 }
	TAG_BLOCK(
		PurchasePlayerOrdnanceItemBlock_block,
		"PurchasePlayerOrdnanceItemBlock",
		1,
		"PurchasePlayerOrdnanceItem",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PURCHASEPLAYERORDNANCEITEMBLOCK_ID)
	{
		{ _field_string_id, "ordnance_name", "This must match one of the global ordnance objects.", FIELD_FLAG_INDEX },
		{ _field_terminator }
	};

	#define PURCHASEPLAYERORDNANCESLOTBLOCK_ID { 0x7BE3DDEA, 0x4CAB4B00, 0xBEC4F180, 0x47ACB4DF }
	TAG_BLOCK(
		PurchasePlayerOrdnanceSlotBlock_block,
		"PurchasePlayerOrdnanceSlotBlock",
		1,
		"PurchasePlayerSlot",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PURCHASEPLAYERORDNANCESLOTBLOCK_ID)
	{
		{ _field_byte_integer, "slot_count", "Total slots you're allowed.", FIELD_FLAG_INDEX },
		{ _field_terminator }
	};

	#define PURCHASE_PLAYER_ITEM_BLOCK_ID { 0x6DF197DD, 0x56AA434D, 0xB24D15BE, 0xCE1CC937 }
	TAG_BLOCK(
		purchase_player_item_block,
		"purchase_player_item_block",
		1,
		"s_purchase_player_item",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PURCHASE_PLAYER_ITEM_BLOCK_ID)
	{
		{ _field_char_enum, "item_category", "From the global multiplayer object list.", &player_item_category_enum },
		FIELD_PAD("pad1", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_string_id, "object_name", "This must match one of the global objects.", FIELD_FLAG_INDEX },
		{ _field_byte_integer, "object variant index", "e.g. used for weapon skins" },
		FIELD_PAD("ppib", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_terminator }
	};

	#define PURCHASE_PLAYER_APP_BLOCK_ID { 0x3E41A4EE, 0x646248BE, 0xA5ACD8A5, 0x59F267F7 }
	TAG_BLOCK(
		purchase_player_app_block,
		"purchase_player_app_block",
		1,
		"s_purchase_player_app",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PURCHASE_PLAYER_APP_BLOCK_ID)
	{
		{ _field_string_id, "object_name", "This must match an item in the custom app globals.", FIELD_FLAG_INDEX },
		{ _field_terminator }
	};

	#define PURCHASE_PLAYER_LOADOUT_SLOT_BLOCK_ID { 0x0A652532, 0x0F8B48C7, 0x9DDBC3AE, 0xF94BA410 }
	TAG_BLOCK(
		purchase_player_loadout_slot_block,
		"purchase_player_loadout_slot_block",
		1,
		"PurchasePlayerSlot",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PURCHASE_PLAYER_LOADOUT_SLOT_BLOCK_ID)
	{
		{ _field_byte_integer, "slot_count", "Total slots you're allowed.", FIELD_FLAG_INDEX },
		{ _field_terminator }
	};

	#define PURCHASE_PLAYER_APP_MOD_SLOT_BLOCK_ID { 0xB5C06B4D, 0xA3C74BFA, 0x8ABCC728, 0xB53E8C35 }
	TAG_BLOCK(
		purchase_player_app_mod_slot_block,
		"purchase_player_app_mod_slot_block",
		1,
		"PurchasePlayerAppModSlot",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PURCHASE_PLAYER_APP_MOD_SLOT_BLOCK_ID)
	{
		{ _field_byte_integer, "app_count", "Total apps you're allowed (from 0 to 2).", FIELD_FLAG_INDEX },
		{ _field_byte_integer, "mod_count", "Total mods you're allowed (from 0 to 1).", FIELD_FLAG_INDEX },
		{ _field_terminator }
	};

	#define PURCHASE_PLAYER_APPEARANCE_EFFECT_MODEL_PERMUTATION_BLOCK_ID { 0x04F98615, 0x46AE40E6, 0xB62BDDDF, 0x8C73E74C }
	TAG_BLOCK(
		purchase_player_appearance_effect_model_permutation_block,
		"purchase_player_appearance_effect_model_permutation_block",
		1,
		"s_purchase_player_appearance_effect_model_permutation",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PURCHASE_PLAYER_APPEARANCE_EFFECT_MODEL_PERMUTATION_BLOCK_ID)
	{
		{ _field_char_enum, "model_region", "See player customization globals, linked from globals.globals.", &player_model_customization_area_enum },
		FIELD_PAD("pad1", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_string_id, "model_customization_selection_name", "This must match one of the selections in the model customization globals (within the selected region).", FIELD_FLAG_INDEX },
		{ _field_terminator }
	};

	#define PURCHASE_PLAYER_APPEARANCE_EFFECT_NON_MODEL_PERMUTATION_BLOCK_ID { 0x2B8FD9DD, 0xB6B84F52, 0x9786DDEE, 0x1E6BEC95 }
	TAG_BLOCK(
		purchase_player_appearance_effect_non_model_permutation_block,
		"purchase_player_appearance_effect_non_model_permutation_block",
		2,
		"s_purchase_player_appearance_effect_non_model_permutation",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PURCHASE_PLAYER_APPEARANCE_EFFECT_NON_MODEL_PERMUTATION_BLOCK_ID)
	{
		{ _field_char_enum, "non_model_region", "See player customization globals, linked from globals.globals.", &player_non_model_customization_area_enum },
		FIELD_PAD("pad1", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_string_id, "non_model_customization_selection_name", "This must match one of the selections in the model customization globals (within the selected region).", FIELD_FLAG_INDEX },
		{ _field_terminator }
	};

	#define PURCHASE_PLAYER_APPEARANCE_EFFECT_VISOR_TINT_BLOCK_ID { 0xF420151F, 0xD41D481B, 0xA60F863D, 0x0B8318C9 }
	TAG_BLOCK(
		purchase_player_appearance_effect_visor_tint_block,
		"purchase_player_appearance_effect_visor_tint_block",
		1,
		"s_purchase_player_appearance_effect_visor_tint",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PURCHASE_PLAYER_APPEARANCE_EFFECT_VISOR_TINT_BLOCK_ID)
	{
		{ _field_string_id, "visor color name", FIELD_FLAG_INDEX },
		{ _field_terminator }
	};

	#define PURCHASE_PLAYER_APPEARANCE_EFFECT_EMBLEM_INDEX_BLOCK_ID { 0x10888DA4, 0x230542AF, 0x891842A8, 0xF57892D2 }
	TAG_BLOCK(
		purchase_player_appearance_effect_emblem_index_block,
		"purchase_player_appearance_effect_emblem_index_block",
		k_maxEmblemIndicesPerItem,
		"s_purchase_player_appearance_effect_emblem_index",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PURCHASE_PLAYER_APPEARANCE_EFFECT_EMBLEM_INDEX_BLOCK_ID)
	{
		{ _field_char_integer, "emblem index", FIELD_FLAG_INDEX },
		{ _field_terminator }
	};

	#define PURCHASEPLAYERAPPEARANCEPOSEBLOCK_ID { 0xA06F2621, 0xD35C48B2, 0x90F96D3C, 0x9CC32FC5 }
	TAG_BLOCK(
		PurchasePlayerAppearancePoseBlock_block,
		"PurchasePlayerAppearancePoseBlock",
		1,
		"PurchasePlayerAppearancePose",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PURCHASEPLAYERAPPEARANCEPOSEBLOCK_ID)
	{
		{ _field_string_id, "pose name", FIELD_FLAG_INDEX },
		{ _field_terminator }
	};

	#define COOKIEPURCHASEFAMILYAPPEARANCEDEFINITIONBLOCK_ID { 0x1250D90C, 0xC1CE47A6, 0x928F09B8, 0x0298F667 }
	TAG_BLOCK(
		CookiePurchaseFamilyAppearanceDefinitionBlock_block,
		"CookiePurchaseFamilyAppearanceDefinitionBlock",
		k_max_cookie_purchase_families,
		"s_cookie_purchase_family_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		COOKIEPURCHASEFAMILYAPPEARANCEDEFINITIONBLOCK_ID)
	{
		{ _field_string_id, "display title", "If this is left blank, this family will be treated as a list of top-level items (items w/o a family, e.g. visor tints).", FIELD_FLAG_INDEX },
		{ _field_string_id, "display_description" },
		{ _field_tag_reference, "display bitmap", &global_bitmap_reference },
		{ _field_long_integer, "sprite index" },
		{ _field_block, "purchasable items", &CookiePurchaseAppearanceDefinitionReferenceBlock_block },
		{ _field_terminator }
	};

	#define COOKIEPURCHASEAPPEARANCEDEFINITIONREFERENCEBLOCK_ID { 0x43E90CB6, 0x142B4894, 0x91159BF3, 0x27451D8B }
	TAG_BLOCK(
		CookiePurchaseAppearanceDefinitionReferenceBlock_block,
		"CookiePurchaseAppearanceDefinitionReferenceBlock",
		k_max_cookie_purchase_family_items,
		"s_cookie_purchase_definition_reference",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		COOKIEPURCHASEAPPEARANCEDEFINITIONREFERENCEBLOCK_ID)
	{
		{ _field_struct, "purchasable item reference", &PurchaseAppearanceDefinitionReferenceStruct },
		{ _field_terminator }
	};

	#define COOKIEPURCHASEFAMILYLOADOUTDEFINITIONBLOCK_ID { 0x77DD9D2E, 0x4AA34EB4, 0x91DD8395, 0x5BF92C69 }
	TAG_BLOCK(
		CookiePurchaseFamilyLoadoutDefinitionBlock_block,
		"CookiePurchaseFamilyLoadoutDefinitionBlock",
		k_max_cookie_purchase_families,
		"s_cookie_purchase_family_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		COOKIEPURCHASEFAMILYLOADOUTDEFINITIONBLOCK_ID)
	{
		{ _field_string_id, "display title", "If this is left blank, this family will be treated as a list of top-level items (items w/o a family, e.g. visor tints).", FIELD_FLAG_INDEX },
		{ _field_string_id, "display_description" },
		{ _field_tag_reference, "display bitmap", &global_bitmap_reference },
		{ _field_long_integer, "sprite index" },
		{ _field_block, "purchasable items", &CookiePurchaseLoadoutDefinitionReferenceBlock_block },
		{ _field_terminator }
	};

	#define COOKIEPURCHASELOADOUTDEFINITIONREFERENCEBLOCK_ID { 0x94040ED2, 0x27BB4352, 0x929211F9, 0x7A7241E3 }
	TAG_BLOCK(
		CookiePurchaseLoadoutDefinitionReferenceBlock_block,
		"CookiePurchaseLoadoutDefinitionReferenceBlock",
		k_max_cookie_purchase_family_items,
		"s_cookie_purchase_definition_reference",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		COOKIEPURCHASELOADOUTDEFINITIONREFERENCEBLOCK_ID)
	{
		{ _field_struct, "purchasable item reference", &PurchaseLoadoutDefinitionReferenceStruct },
		{ _field_terminator }
	};

	#define COOKIEPURCHASEFAMILYORDNANCEDEFINITIONBLOCK_ID { 0xA9BA8BFF, 0x4FB34205, 0xBC2111A2, 0x7A9367A2 }
	TAG_BLOCK(
		CookiePurchaseFamilyOrdnanceDefinitionBlock_block,
		"CookiePurchaseFamilyOrdnanceDefinitionBlock",
		k_max_cookie_purchase_families,
		"s_cookie_purchase_family_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		COOKIEPURCHASEFAMILYORDNANCEDEFINITIONBLOCK_ID)
	{
		{ _field_string_id, "display title", "If this is left blank, this family will be treated as a list of top-level items (items w/o a family, e.g. visor tints).", FIELD_FLAG_INDEX },
		{ _field_string_id, "display_description" },
		{ _field_tag_reference, "display bitmap", &global_bitmap_reference },
		{ _field_long_integer, "sprite index" },
		{ _field_block, "purchasable items", &CookiePurchaseOrdnanceDefinitionReferenceBlock_block },
		{ _field_terminator }
	};

	#define COOKIEPURCHASEORDNANCEDEFINITIONREFERENCEBLOCK_ID { 0xA3DD0BBB, 0xF3E84731, 0xB2EE9024, 0x8B6BC514 }
	TAG_BLOCK(
		CookiePurchaseOrdnanceDefinitionReferenceBlock_block,
		"CookiePurchaseOrdnanceDefinitionReferenceBlock",
		k_max_cookie_purchase_family_items,
		"s_cookie_purchase_definition_reference",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		COOKIEPURCHASEORDNANCEDEFINITIONREFERENCEBLOCK_ID)
	{
		{ _field_struct, "purchasable item reference", &PurchaseOrdnanceDefinitionReferenceStruct },
		{ _field_terminator }
	};

	#define COOKIEPURCHASEEXTERNALUNLOCKABLEBLOCKAPPEARANCEDEFINITION_ID { 0x42248106, 0x55394468, 0xB28B8E1C, 0x0077C7FB }
	TAG_BLOCK(
		CookiePurchaseExternalUnlockableBlockAppearanceDefinition_block,
		"CookiePurchaseExternalUnlockableBlockAppearanceDefinition",
		(sizeof(dword)*k_byte_bits),
		"s_cookie_purchase_external_unlockable_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		COOKIEPURCHASEEXTERNALUNLOCKABLEBLOCKAPPEARANCEDEFINITION_ID)
	{
		{ _field_block, "purchasable items", &CookiePurchaseAppearanceDefinitionReferenceBlock_block },
		{ _field_terminator }
	};

	#define COOKIEPURCHASEEXTERNALUNLOCKABLEBLOCKLOADOUTDEFINITION_ID { 0x5DB72ECF, 0xDA3F49B1, 0x82D4E463, 0x3D71B0C2 }
	TAG_BLOCK(
		CookiePurchaseExternalUnlockableBlockLoadoutDefinition_block,
		"CookiePurchaseExternalUnlockableBlockLoadoutDefinition",
		(sizeof(dword)*k_byte_bits),
		"s_cookie_purchase_external_unlockable_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		COOKIEPURCHASEEXTERNALUNLOCKABLEBLOCKLOADOUTDEFINITION_ID)
	{
		{ _field_block, "purchasable items", &CookiePurchaseLoadoutDefinitionReferenceBlock_block },
		{ _field_terminator }
	};

	#define COOKIEPURCHASEEXTERNALUNLOCKABLEBLOCKORDNANCEDEFINITION_ID { 0xF81C40BE, 0x6C4C4705, 0xBD553B5E, 0x1C80ABF4 }
	TAG_BLOCK(
		CookiePurchaseExternalUnlockableBlockOrdnanceDefinition_block,
		"CookiePurchaseExternalUnlockableBlockOrdnanceDefinition",
		(sizeof(dword)*k_byte_bits),
		"s_cookie_purchase_external_unlockable_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		COOKIEPURCHASEEXTERNALUNLOCKABLEBLOCKORDNANCEDEFINITION_ID)
	{
		{ _field_block, "purchasable items", &CookiePurchaseOrdnanceDefinitionReferenceBlock_block },
		{ _field_terminator }
	};

	#define COOKIE_PURCHASE_GLOBALS_STRUCT_DEFINITION_ID { 0x793B38DC, 0xFD7A4B72, 0xB484A227, 0xE22E9087 }
	TAG_STRUCT(
		cookie_purchase_globals_struct_definition,
		"cookie_purchase_globals_struct_definition",
		"s_cookie_purchase_globals_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		COOKIE_PURCHASE_GLOBALS_STRUCT_DEFINITION_ID)
	{
		FIELD_CUSTOM("Purchase Families", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_block, "Helmet purchasable appearance families", &CookiePurchaseFamilyAppearanceDefinitionBlock_block },
		{ _field_block, "Left shoulder purchasable appearance families", &CookiePurchaseFamilyAppearanceDefinitionBlock_block },
		{ _field_block, "Right shoulder purchasable appearance families", &CookiePurchaseFamilyAppearanceDefinitionBlock_block },
		{ _field_block, "Chest purchasable appearance families", &CookiePurchaseFamilyAppearanceDefinitionBlock_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_block, "Legs purchasable appearance families", &CookiePurchaseFamilyAppearanceDefinitionBlock_block },

		{ _field_block, "Arms purchasable appearance families", &CookiePurchaseFamilyAppearanceDefinitionBlock_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 7 },
		{ _field_block, "App 1 loadout families", &CookiePurchaseFamilyLoadoutDefinitionBlock_block },
		{ _field_block, "App 2 loadout families", &CookiePurchaseFamilyLoadoutDefinitionBlock_block },
		{ _field_block, "Primary weapon loadout families", &CookiePurchaseFamilyLoadoutDefinitionBlock_block },
		{ _field_block, "Secondary weapon loadout families", &CookiePurchaseFamilyLoadoutDefinitionBlock_block },
		{ _field_block, "Grenade purchasable loadout families", &CookiePurchaseFamilyLoadoutDefinitionBlock_block },
		{ _field_block, "Equipment purchasable loadout families", &CookiePurchaseFamilyLoadoutDefinitionBlock_block },
		{ _field_block, "Slot purchasable loadout families", &CookiePurchaseFamilyLoadoutDefinitionBlock_block },

		{ _field_legacy, _field_version_equal, _engine_type_haloreach },
		{ _field_block, "Legs purchasable appearance families", &CookiePurchaseFamilyAppearanceDefinitionBlock_block },

		{ _field_block, "Visor tint purchasable appearance families", &CookiePurchaseFamilyAppearanceDefinitionBlock_block },

		{ _field_legacy, _field_version_equal, _engine_type_haloreach, 2 },
		{ _field_legacy, _field_block, "Knee guard purchasable appearance families", &CookiePurchaseFamilyAppearanceDefinitionBlock_block },
		{ _field_legacy, _field_block, "Armor effect purchasable appearance families", &CookiePurchaseFamilyAppearanceDefinitionBlock_block },

		{ _field_block, "Elite armor purchasable appearance families", &CookiePurchaseFamilyAppearanceDefinitionBlock_block },
		{ _field_block, "Primary emblem purchasable appearance families", &CookiePurchaseFamilyAppearanceDefinitionBlock_block },
		{ _field_block, "Secondary emblem purchasable appearance families", &CookiePurchaseFamilyAppearanceDefinitionBlock_block },

		{ _field_legacy, _field_version_equal, _engine_type_haloreach, 2 },
		{ _field_legacy, _field_block, "Firefight voice purchasable appearance families", &CookiePurchaseFamilyAppearanceDefinitionBlock_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 3 },
		{ _field_block, "Ordnance slot purchasable families", &CookiePurchaseFamilyOrdnanceDefinitionBlock_block },
		{ _field_block, "Ordnance purchasable families", &CookiePurchaseFamilyOrdnanceDefinitionBlock_block },
		{ _field_block, "Portrait pose purchasable families", &CookiePurchaseFamilyAppearanceDefinitionBlock_block },

		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		FIELD_CUSTOM("Appearance Items", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_block, "purchasable appearance items", &CookiePurchaseAppearanceDefinitionBlock_block },
		{ _field_block, "DLC appearance unlockables", &CookiePurchaseExternalUnlockableBlockAppearanceDefinition_block },
		{ _field_block, "Waypoint appearance unlockables", &CookiePurchaseExternalUnlockableBlockAppearanceDefinition_block },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 9 },
		FIELD_CUSTOM("Loadout Items", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_block, "purchasable loadout items", &CookiePurchaseLoadoutDefinitionBlock_block },
		{ _field_block, "DLC loadout unlockables", &CookiePurchaseExternalUnlockableBlockLoadoutDefinition_block },
		{ _field_block, "Waypoint loadout unlockables", &CookiePurchaseExternalUnlockableBlockLoadoutDefinition_block },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		FIELD_CUSTOM("Ordnance Items", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_block, "purchasable ordnance items", &CookiePurchaseOrdnanceDefinitionBlock_block },
		{ _field_block, "DLC ordnance unlockables", &CookiePurchaseExternalUnlockableBlockOrdnanceDefinition_block },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),

		{ _field_terminator }
	};

	#define PURCHASEPLAYERORDNANCESTRUCT_ID { 0x9D6BC685, 0x26C04A2E, 0xB2A12034, 0xE3A23772 }
	TAG_STRUCT(
		PurchasePlayerOrdnanceStruct,
		"PurchasePlayerOrdnanceStruct",
		"PurchasePlayerOrdnance",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		PURCHASEPLAYERORDNANCESTRUCT_ID)
	{
		{ _field_block, "ordnance items", &PurchasePlayerOrdnanceItemBlock_block },
		{ _field_block, "ordnance slots", &PurchasePlayerOrdnanceSlotBlock_block },
		{ _field_terminator }
	};

	#define PURCHASEPLAYERLOADOUTSTRUCT_ID { 0x8323E16A, 0x197C4288, 0x81964917, 0xCE56F651 }
	TAG_STRUCT(
		PurchasePlayerLoadoutStruct,
		"PurchasePlayerLoadoutStruct",
		"PurchasePlayerLoadout",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		PURCHASEPLAYERLOADOUTSTRUCT_ID)
	{
		{ _field_block, "items", &purchase_player_item_block },
		{ _field_block, "apps", &purchase_player_app_block },
		{ _field_block, "loadout slots", &purchase_player_loadout_slot_block },
		{ _field_block, "app and mod slots", &purchase_player_app_mod_slot_block },
		{ _field_terminator }
	};

	V5_TAG_BLOCK(purchase_player_appearance_effect_firefight_voice_block, 65536)
	{
		{ _field_legacy, _field_string_id, "voice name^" },
		{ _field_legacy, _field_terminator }
	};

	#define PURCHASEPLAYERAPPEARANCESTRUCT_ID { 0xC34CFE9C, 0x283240B7, 0x83483A7B, 0xBBFE2AB4 }
	TAG_STRUCT(
		PurchasePlayerAppearanceStruct,
		"PurchasePlayerAppearanceStruct",
		"PurchasePlayerAppearance",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		PURCHASEPLAYERAPPEARANCESTRUCT_ID)
	{
		{ _field_block, "permutations", &purchase_player_appearance_effect_model_permutation_block },
		{ _field_block, "armor effects permutations", &purchase_player_appearance_effect_non_model_permutation_block },
		{ _field_block, "visor tints", &purchase_player_appearance_effect_visor_tint_block },
		{ _field_block, "emblem indices", &purchase_player_appearance_effect_emblem_index_block },

		{ _field_legacy, _field_version_equal, _engine_type_haloreach },
		{ _field_legacy, _field_block, "firefight voices", &purchase_player_appearance_effect_firefight_voice_block_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_block, "portrait poses", &PurchasePlayerAppearancePoseBlock_block },

		{ _field_terminator }
	};

	STRINGS(player_model_customization_area_enum)
	{
		"spartan helmet",
		"spartan chest",
		"elite armor",
		"unused_1",
		"unused_2",
		"unused_3",
		"unused_4",
		"unused_5"
	};
	STRING_LIST(player_model_customization_area_enum, player_model_customization_area_enum_strings, _countof(player_model_customization_area_enum_strings));

	STRINGS(player_non_model_customization_area_enum)
	{
		"spartan armour effect",
		"elite armour effect"
	};
	STRING_LIST(player_non_model_customization_area_enum, player_non_model_customization_area_enum_strings, _countof(player_non_model_customization_area_enum_strings));

	STRINGS(player_item_category_enum)
	{
		"weapon",
		"grenade",
		"equipment",
		"vehicle"
	};
	STRING_LIST(player_item_category_enum, player_item_category_enum_strings, _countof(player_item_category_enum_strings));

	STRINGS(cookie_purchase_flags)
	{
		"auto buy#this item is automatically given to the player when they meet the conditions",
		"default#this item will appear as \'worn\' when the player isn\'t wearing any item (for \'default\' items)",
		"doesn\'t count toward percent complete#this item will NOT count toward an overall completion value",
		"doesn\'t count toward new items#this item is never \'new\'",
		"lsp_authoritative#cannot be purchased locally, only LSP can set"
	};
	STRING_LIST(cookie_purchase_flags, cookie_purchase_flags_strings, _countof(cookie_purchase_flags_strings));

} // namespace macaque

} // namespace blofeld

