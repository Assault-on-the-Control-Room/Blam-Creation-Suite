#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_GROUP_FROM_BLOCK(cookie_purchase_globals, COOKIE_PURCHASE_GLOBALS_TAG, cookie_purchase_globals_block_block );

	V5_TAG_BLOCK(CookiePurchaseAppearanceDefinitionReferenceBlock, k_max_cookie_purchase_family_items)
	{
		{ _field_legacy, _field_struct, "purchasable item reference", &PurchaseAppearanceDefinitionReferenceStruct_struct_definition },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(CookiePurchaseFamilyAppearanceDefinitionBlock, k_max_cookie_purchase_families)
	{
		{ _field_legacy, _field_string_id, "display title^#If this is left blank, this family will be treated as a list of top-level items (items w/o a family, e.g. visor tints)." },
		{ _field_legacy, _field_string_id, "display_description" },
		{ _field_legacy, _field_tag_reference, "display bitmap", &global_bitmap_reference },
		{ _field_legacy, _field_long_integer, "sprite index" },
		{ _field_legacy, _field_block, "purchasable items", &CookiePurchaseAppearanceDefinitionReferenceBlock_block },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(CookiePurchaseLoadoutDefinitionReferenceBlock, k_max_cookie_purchase_family_items)
	{
		{ _field_legacy, _field_struct, "purchasable item reference", &PurchaseLoadoutDefinitionReferenceStruct_struct_definition },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(CookiePurchaseFamilyLoadoutDefinitionBlock, k_max_cookie_purchase_families)
	{
		{ _field_legacy, _field_string_id, "display title^#If this is left blank, this family will be treated as a list of top-level items (items w/o a family, e.g. visor tints)." },
		{ _field_legacy, _field_string_id, "display_description" },
		{ _field_legacy, _field_tag_reference, "display bitmap", &global_bitmap_reference },
		{ _field_legacy, _field_long_integer, "sprite index" },
		{ _field_legacy, _field_block, "purchasable items", &CookiePurchaseLoadoutDefinitionReferenceBlock_block },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(CookiePurchaseOrdnanceDefinitionReferenceBlock, k_max_cookie_purchase_family_items)
	{
		{ _field_legacy, _field_struct, "purchasable item reference", &PurchaseOrdnanceDefinitionReferenceStruct_struct_definition },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(CookiePurchaseFamilyOrdnanceDefinitionBlock, k_max_cookie_purchase_families)
	{
		{ _field_legacy, _field_string_id, "display title^#If this is left blank, this family will be treated as a list of top-level items (items w/o a family, e.g. visor tints)." },
		{ _field_legacy, _field_string_id, "display_description" },
		{ _field_legacy, _field_tag_reference, "display bitmap", &global_bitmap_reference },
		{ _field_legacy, _field_long_integer, "sprite index" },
		{ _field_legacy, _field_block, "purchasable items", &CookiePurchaseOrdnanceDefinitionReferenceBlock_block },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(purchase_player_appearance_effect_model_permutation_block, 1)
	{
		{ _field_legacy, _field_char_enum, "model_region#See player customization globals, linked from globals.globals.", &player_model_customization_area_enum },
		{ _field_legacy, _field_pad, "pad1", 3 },
		{ _field_legacy, _field_string_id, "model_customization_selection_name^#This must match one of the selections in the model customization globals (within the selected region)." },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(purchase_player_appearance_effect_non_model_permutation_block, 2)
	{
		{ _field_legacy, _field_char_enum, "non_model_region#See player customization globals, linked from globals.globals.", &player_non_model_customization_area_enum },
		{ _field_legacy, _field_pad, "pad1", 3 },
		{ _field_legacy, _field_string_id, "non_model_customization_selection_name^#This must match one of the selections in the model customization globals (within the selected region)." },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(purchase_player_appearance_effect_visor_tint_block, 1)
	{
		{ _field_legacy, _field_string_id, "visor color name^" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(purchase_player_appearance_effect_emblem_index_block, k_maxEmblemIndicesPerItem)
	{
		{ _field_legacy, _field_char_integer, "emblem index^" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(purchase_player_appearance_effect_firefight_voice_block, 65536)
	{
		{ _field_legacy, _field_string_id, "voice name^" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(PurchasePlayerAppearancePoseBlock, 1)
	{
		{ _field_legacy, _field_string_id, "pose name^" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(CookiePurchaseAppearanceDefinitionBlock, k_max_cookie_purchase_total_appearance_items)
	{
		{ _field_legacy, _field_string_id, "purchase id" },
		{ _field_legacy, _field_string_id, "display name^" },
		{ _field_legacy, _field_string_id, "display description" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_legacy, _field_string_id, "Exit Experience Aggregate Group Name" },

		{ _field_legacy, _field_byte_flags, "flags", &cookie_purchase_flags },
		{ _field_legacy, _field_pad, "pad1", 3 },
		{ _field_legacy, _field_tag_reference, "display bitmap", &global_bitmap_reference },
		{ _field_legacy, _field_long_integer, "sprite index" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_legacy, _field_tag_reference, "detail display bitmap", &global_bitmap_reference },

		{ _field_legacy, _field_long_integer, "cookie cost" },

		{ _field_legacy, _field_version_equal, _engine_type_haloreach },
		{ _field_legacy, _field_struct, "purchase player appearance", &PurchasePlayerAppearanceStruct_struct_definition }, // moved

		{ _field_legacy, _field_custom, "Prerequisites for visibility" },
		{ _field_legacy, _field_struct, "visible prerequisites", &PurchasePrerequisitesUnifiedDefinitionBlock_struct_definition },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_custom, "Prerequisites for purchasability" },
		{ _field_legacy, _field_struct, "purchasable prerequisites", &PurchasePrerequisitesUnifiedDefinitionBlock_struct_definition },
		{ _field_legacy, _field_custom },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_legacy, _field_struct, "purchase player appearance", &PurchasePlayerAppearanceStruct_struct_definition }, // moved

		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(CookiePurchaseExternalUnlockableBlockAppearanceDefinition, (sizeof(dword)*k_byte_bits))
	{
		{ _field_legacy, _field_block, "purchasable items", &CookiePurchaseAppearanceDefinitionReferenceBlock_block },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(purchase_player_item_block, 1)
	{
		{ _field_legacy, _field_char_enum, "item_category#From the global multiplayer object list.", &player_item_category_enum },
		{ _field_legacy, _field_pad, "pad1", 3 },
		{ _field_legacy, _field_string_id, "object_name^#This must match one of the global objects." },
		{ _field_legacy, _field_byte_integer, "object variant index#e.g. used for weapon skins" },
		{ _field_legacy, _field_pad, "ppib", 3 },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(purchase_player_app_block, 1)
	{
		{ _field_legacy, _field_string_id, "object_name^#This must match an item in the custom app globals." },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(purchase_player_loadout_slot_block, 1)
	{
		{ _field_legacy, _field_byte_integer, "slot_count^#Total slots you\'re allowed." },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(purchase_player_app_mod_slot_block, 1)
	{
		{ _field_legacy, _field_byte_integer, "app_count^#Total apps you\'re allowed (from 0 to 2)." },
		{ _field_legacy, _field_byte_integer, "mod_count^#Total mods you\'re allowed (from 0 to 1)." },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(CookiePurchaseLoadoutDefinitionBlock, k_max_cookie_purchase_total_loadout_items)
	{
		{ _field_legacy, _field_string_id, "purchase id" },
		{ _field_legacy, _field_string_id, "display name^" },
		{ _field_legacy, _field_string_id, "display description" },
		{ _field_legacy, _field_string_id, "Exit Experience Aggregate Group Name" },
		{ _field_legacy, _field_byte_flags, "flags", &cookie_purchase_flags },
		{ _field_legacy, _field_pad, "pad1", 3 },
		{ _field_legacy, _field_tag_reference, "display bitmap", &global_bitmap_reference },
		{ _field_legacy, _field_long_integer, "sprite index" },
		{ _field_legacy, _field_tag_reference, "detail display bitmap", &global_bitmap_reference },
		{ _field_legacy, _field_long_integer, "cookie cost" },
		{ _field_legacy, _field_custom, "Prerequisites for visibility" },
		{ _field_legacy, _field_struct, "visible prerequisites", &PurchasePrerequisitesUnifiedDefinitionBlock_struct_definition },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_custom, "Prerequisites for purchasability" },
		{ _field_legacy, _field_struct, "purchasable prerequisites", &PurchasePrerequisitesUnifiedDefinitionBlock_struct_definition },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_string_id, "icon string id" },
		{ _field_legacy, _field_struct, "purchase player loadout", &PurchasePlayerLoadoutStruct_struct_definition },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(CookiePurchaseExternalUnlockableBlockLoadoutDefinition, (sizeof(dword)*k_byte_bits))
	{
		{ _field_legacy, _field_block, "purchasable items", &CookiePurchaseLoadoutDefinitionReferenceBlock_block },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(PurchasePlayerOrdnanceItemBlock, 1)
	{
		{ _field_legacy, _field_string_id, "ordnance_name^#This must match one of the global ordnance objects." },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(PurchasePlayerOrdnanceSlotBlock, 1)
	{
		{ _field_legacy, _field_byte_integer, "slot_count^#Total slots you\'re allowed." },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(CookiePurchaseOrdnanceDefinitionBlock, k_max_cookie_purchase_total_ordnance_items)
	{
		{ _field_legacy, _field_string_id, "purchase id" },
		{ _field_legacy, _field_string_id, "display name^" },
		{ _field_legacy, _field_string_id, "display description" },
		{ _field_legacy, _field_string_id, "Exit Experience Aggregate Group Name" },
		{ _field_legacy, _field_byte_flags, "flags", &cookie_purchase_flags },
		{ _field_legacy, _field_pad, "pad1", 3 },
		{ _field_legacy, _field_tag_reference, "display bitmap", &global_bitmap_reference },
		{ _field_legacy, _field_long_integer, "sprite index" },
		{ _field_legacy, _field_tag_reference, "detail display bitmap", &global_bitmap_reference },
		{ _field_legacy, _field_long_integer, "cookie cost" },
		{ _field_legacy, _field_custom, "Prerequisites for visibility" },
		{ _field_legacy, _field_struct, "visible prerequisites", &PurchasePrerequisitesUnifiedDefinitionBlock_struct_definition },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_custom, "Prerequisites for purchasability" },
		{ _field_legacy, _field_struct, "purchasable prerequisites", &PurchasePrerequisitesUnifiedDefinitionBlock_struct_definition },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_struct, "purchase player ordnance", &PurchasePlayerOrdnanceStruct_struct_definition },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(CookiePurchaseExternalUnlockableBlockOrdnanceDefinition, (sizeof(dword)*k_byte_bits))
	{
		{ _field_legacy, _field_block, "purchasable items", &CookiePurchaseOrdnanceDefinitionReferenceBlock_block },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK_FROM_STRUCT(cookie_purchase_globals_block, 1, cookie_purchase_globals_struct_definition_struct_definition );

	V5_TAG_STRUCT(cookie_purchase_globals_struct_definition)
	{
		{ _field_legacy, _field_custom, "Purchase Families" },
		{ _field_legacy, _field_block, "Helmet purchasable appearance families", &CookiePurchaseFamilyAppearanceDefinitionBlock_block },
		{ _field_legacy, _field_block, "Left shoulder purchasable appearance families", &CookiePurchaseFamilyAppearanceDefinitionBlock_block },
		{ _field_legacy, _field_block, "Right shoulder purchasable appearance families", &CookiePurchaseFamilyAppearanceDefinitionBlock_block },
		{ _field_legacy, _field_block, "Chest purchasable appearance families", &CookiePurchaseFamilyAppearanceDefinitionBlock_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_legacy, _field_block, "Legs purchasable appearance families", &CookiePurchaseFamilyAppearanceDefinitionBlock_block }, // moved

		{ _field_legacy, _field_block, "Arms purchasable appearance families", &CookiePurchaseFamilyAppearanceDefinitionBlock_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 7 },
		{ _field_legacy, _field_block, "App 1 loadout families", &CookiePurchaseFamilyLoadoutDefinitionBlock_block },
		{ _field_legacy, _field_block, "App 2 loadout families", &CookiePurchaseFamilyLoadoutDefinitionBlock_block },
		{ _field_legacy, _field_block, "Primary weapon loadout families", &CookiePurchaseFamilyLoadoutDefinitionBlock_block },
		{ _field_legacy, _field_block, "Secondary weapon loadout families", &CookiePurchaseFamilyLoadoutDefinitionBlock_block },
		{ _field_legacy, _field_block, "Grenade purchasable loadout families", &CookiePurchaseFamilyLoadoutDefinitionBlock_block },
		{ _field_legacy, _field_block, "Equipment purchasable loadout families", &CookiePurchaseFamilyLoadoutDefinitionBlock_block },
		{ _field_legacy, _field_block, "Slot purchasable loadout families", &CookiePurchaseFamilyLoadoutDefinitionBlock_block },

		{ _field_legacy, _field_version_equal, _engine_type_haloreach },
		{ _field_legacy, _field_block, "Legs purchasable appearance families", &CookiePurchaseFamilyAppearanceDefinitionBlock_block }, // moved

		{ _field_legacy, _field_block, "Visor tint purchasable appearance families", &CookiePurchaseFamilyAppearanceDefinitionBlock_block },

		{ _field_legacy, _field_version_equal, _engine_type_haloreach, 2 },
		{ _field_legacy, _field_block, "Knee guard purchasable appearance families", &CookiePurchaseFamilyAppearanceDefinitionBlock_block },
		{ _field_legacy, _field_block, "Armor effect purchasable appearance families", &CookiePurchaseFamilyAppearanceDefinitionBlock_block },

		{ _field_legacy, _field_block, "Elite armor purchasable appearance families", &CookiePurchaseFamilyAppearanceDefinitionBlock_block },
		{ _field_legacy, _field_block, "Primary emblem purchasable appearance families", &CookiePurchaseFamilyAppearanceDefinitionBlock_block },
		{ _field_legacy, _field_block, "Secondary emblem purchasable appearance families", &CookiePurchaseFamilyAppearanceDefinitionBlock_block },

		{ _field_legacy, _field_version_equal, _engine_type_haloreach, 2 },
		{ _field_legacy, _field_block, "Firefight voice purchasable appearance families", &CookiePurchaseFamilyAppearanceDefinitionBlock_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 3 },
		{ _field_legacy, _field_block, "Ordnance slot purchasable families", &CookiePurchaseFamilyOrdnanceDefinitionBlock_block },
		{ _field_legacy, _field_block, "Ordnance purchasable families", &CookiePurchaseFamilyOrdnanceDefinitionBlock_block },
		{ _field_legacy, _field_block, "Portrait pose purchasable families", &CookiePurchaseFamilyAppearanceDefinitionBlock_block },

		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_custom, "Appearance Items" },
		{ _field_legacy, _field_block, "purchasable appearance items", &CookiePurchaseAppearanceDefinitionBlock_block },
		{ _field_legacy, _field_block, "DLC appearance unlockables", &CookiePurchaseExternalUnlockableBlockAppearanceDefinition_block },
		{ _field_legacy, _field_block, "Waypoint appearance unlockables", &CookiePurchaseExternalUnlockableBlockAppearanceDefinition_block },
		{ _field_legacy, _field_custom },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 9 },
		{ _field_legacy, _field_custom, "Loadout Items" },
		{ _field_legacy, _field_block, "purchasable loadout items", &CookiePurchaseLoadoutDefinitionBlock_block },
		{ _field_legacy, _field_block, "DLC loadout unlockables", &CookiePurchaseExternalUnlockableBlockLoadoutDefinition_block },
		{ _field_legacy, _field_block, "Waypoint loadout unlockables", &CookiePurchaseExternalUnlockableBlockLoadoutDefinition_block },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_custom, "Ordnance Items" },
		{ _field_legacy, _field_block, "purchasable ordnance items", &CookiePurchaseOrdnanceDefinitionBlock_block },
		{ _field_legacy, _field_block, "DLC ordnance unlockables", &CookiePurchaseExternalUnlockableBlockOrdnanceDefinition_block },
		{ _field_legacy, _field_custom },

		{ _field_legacy, _field_terminator }
	};

	V5_TAG_STRUCT(PurchasePlayerAppearanceStruct)
	{
		{ _field_legacy, _field_block, "permutations", &purchase_player_appearance_effect_model_permutation_block_block },
		{ _field_legacy, _field_block, "armor effects permutations", &purchase_player_appearance_effect_non_model_permutation_block_block },
		{ _field_legacy, _field_block, "visor tints", &purchase_player_appearance_effect_visor_tint_block_block },
		{ _field_legacy, _field_block, "emblem indices", &purchase_player_appearance_effect_emblem_index_block_block },

		{ _field_legacy, _field_version_equal, _engine_type_haloreach },
		{ _field_legacy, _field_block, "firefight voices", &purchase_player_appearance_effect_firefight_voice_block_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_legacy, _field_block, "portrait poses", &PurchasePlayerAppearancePoseBlock_block },

		{ _field_legacy, _field_terminator }
	};

	V5_TAG_STRUCT(PurchasePlayerLoadoutStruct)
	{
		{ _field_legacy, _field_block, "items", &purchase_player_item_block_block },
		{ _field_legacy, _field_block, "apps", &purchase_player_app_block_block },
		{ _field_legacy, _field_block, "loadout slots", &purchase_player_loadout_slot_block_block },
		{ _field_legacy, _field_block, "app and mod slots", &purchase_player_app_mod_slot_block_block },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_STRUCT(PurchasePlayerOrdnanceStruct)
	{
		{ _field_legacy, _field_block, "ordnance items", &PurchasePlayerOrdnanceItemBlock_block },
		{ _field_legacy, _field_block, "ordnance slots", &PurchasePlayerOrdnanceSlotBlock_block },
		{ _field_legacy, _field_terminator }
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

} // namespace blofeld

