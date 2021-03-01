#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define PURCHASE_PREREQUISITE_GRADE_DEFINITION_BLOCK_ID { 0x9AF241A1, 0x06F44BE8, 0x893A86A5, 0x707FD4A4 }
	TAG_BLOCK(
		purchase_prerequisite_grade_definition_block,
		"purchase_prerequisite_grade_definition_block",
		1,
		"s_purchase_prerequisite_grade_definition",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PURCHASE_PREREQUISITE_GRADE_DEFINITION_BLOCK_ID)
	{
		{ _field_long_integer, "enlistment index" },
		{ _field_long_integer, "minimum grade" },
		{ _field_terminator }
	};

	#define PURCHASE_PREREQUISITE_COMMENDATION_DEFINITION_BLOCK_ID { 0xD075D6AB, 0x69CF49C9, 0x8AA142ED, 0x6CA22A5E }
	TAG_BLOCK(
		purchase_prerequisite_commendation_definition_block,
		"purchase_prerequisite_commendation_definition_block",
		1,
		"s_purchase_prerequisite_commendation_definition",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PURCHASE_PREREQUISITE_COMMENDATION_DEFINITION_BLOCK_ID)
	{
		{ _field_string_id, "commendation id", "This must match one of the commendation names.", FIELD_FLAG_INDEX },
		{ _field_char_enum, "type", &aggregatorDependentTypeEnumDefinition },
		{ _field_char_integer, "minimum level", "This field is ignored if 'type' is set to 'aggregator'." },
		FIELD_PAD("PAD1", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	#define PURCHASEPREREQUISITEPURCHASEDAPPEARANCEITEMDEFINITIONBLOCK_ID { 0x125F94AF, 0x47D24BB4, 0xB12F2DB9, 0xB4614E8E }
	TAG_BLOCK(
		PurchasePrerequisitePurchasedAppearanceItemDefinitionBlock_block,
		"PurchasePrerequisitePurchasedAppearanceItemDefinitionBlock",
		20,
		"s_purchase_prerequisite_purchased_item_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PURCHASEPREREQUISITEPURCHASEDAPPEARANCEITEMDEFINITIONBLOCK_ID)
	{
		{ _field_struct, "item reference", &PurchaseAppearanceDefinitionReferenceStruct },
		{ _field_terminator }
	};

	#define PURCHASEPREREQUISITEPURCHASEDLOADOUTITEMDEFINITIONBLOCK_ID { 0x56ECE124, 0x7ACA4648, 0x81DE2BA5, 0x80468087 }
	TAG_BLOCK(
		PurchasePrerequisitePurchasedLoadoutItemDefinitionBlock_block,
		"PurchasePrerequisitePurchasedLoadoutItemDefinitionBlock",
		20,
		"s_purchase_prerequisite_purchased_item_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PURCHASEPREREQUISITEPURCHASEDLOADOUTITEMDEFINITIONBLOCK_ID)
	{
		{ _field_struct, "item reference", &PurchaseLoadoutDefinitionReferenceStruct },
		{ _field_terminator }
	};

	#define PURCHASEPREREQUISITEPURCHASEDORDNANCEITEMDEFINITIONBLOCK_ID { 0x9F9F3603, 0xE3A84826, 0xAB19354F, 0xC2E3BC35 }
	TAG_BLOCK(
		PurchasePrerequisitePurchasedOrdnanceItemDefinitionBlock_block,
		"PurchasePrerequisitePurchasedOrdnanceItemDefinitionBlock",
		20,
		"s_purchase_prerequisite_purchased_item_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PURCHASEPREREQUISITEPURCHASEDORDNANCEITEMDEFINITIONBLOCK_ID)
	{
		{ _field_struct, "item reference", &PurchaseOrdnanceDefinitionReferenceStruct },
		{ _field_terminator }
	};

	#define PURCHASE_PREREQUISITES_UNLOCKABLE_DEFINITION_BLOCK_ID { 0xA7314672, 0x7AB34B28, 0xA1AB8A3A, 0x9F9A1765 }
	TAG_BLOCK(
		purchase_prerequisites_unlockable_definition_block,
		"purchase_prerequisites_unlockable_definition_block",
		10,
		"s_purchase_prerequisite_unlockable_definition",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PURCHASE_PREREQUISITES_UNLOCKABLE_DEFINITION_BLOCK_ID)
	{
		{ _field_string_id, "unlockable name", FIELD_FLAG_INDEX },
		{ _field_terminator }
	};

	#define PURCHASE_PREREQUISITES_OFFER_DEFINITION_BLOCK_ID { 0x28A28E77, 0x1D3E44AB, 0x9249DE5E, 0xD58EA8FE }
	TAG_BLOCK(
		purchase_prerequisites_offer_definition_block,
		"purchase_prerequisites_offer_definition_block",
		10,
		"PurchasePrerequisiteOfferDefinition",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PURCHASE_PREREQUISITES_OFFER_DEFINITION_BLOCK_ID)
	{
		{ _field_char_enum, "offer type", FIELD_FLAG_INDEX, &MarketplaceOfferTypeEnum },
		FIELD_PAD("pad1", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_terminator }
	};

	#define PURCHASEPREREQUISITESUNIFIEDDEFINITIONBLOCK_ID { 0xF5FA6611, 0xE7704556, 0x9523C551, 0xFC8C0B41 }
	TAG_STRUCT(
		PurchasePrerequisitesUnifiedDefinitionBlock,
		"PurchasePrerequisitesUnifiedDefinitionBlock",
		"PurchasePrerequisitesUnifiedDefinition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		PURCHASEPREREQUISITESUNIFIEDDEFINITIONBLOCK_ID)
	{
		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 4 },
		{ _field_string_id, "prerequisite purchased item error string" },
		{ _field_string_id, "prerequisite unlockable error string" },
		{ _field_string_id, "prerequisite offers error string" },
		{ _field_long_integer, "prerequisite enlistment count" },

		{ _field_block, "prerequisite grades", &purchase_prerequisite_grade_definition_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_block, "prerequisite commendations", &purchase_prerequisite_commendation_definition_block },

		{ _field_block, "prerequisite appearance purchased items", &PurchasePrerequisitePurchasedAppearanceItemDefinitionBlock_block },

		{ _field_legacy, _field_version_equal, _engine_type_haloreach, 1 },
		{ _field_legacy, _field_string_id, "prerequisite purchased item error string" }, // moved

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_block, "prerequisite loadout purchased items", &PurchasePrerequisitePurchasedLoadoutItemDefinitionBlock_block },
		{ _field_block, "prerequisite ordnance purchased items", &PurchasePrerequisitePurchasedOrdnanceItemDefinitionBlock_block },

		{ _field_block, "prerequisite unlockables", &purchase_prerequisites_unlockable_definition_block },

		{ _field_legacy, _field_version_equal, _engine_type_haloreach },
		{ _field_legacy, _field_string_id, "prerequisite unlockable item error string" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 1 },
		{ _field_block, "prerequisite offers", &purchase_prerequisites_offer_definition_block },

		{ _field_terminator }
	};

	#define PURCHASEAPPEARANCEDEFINITIONREFERENCESTRUCT_ID { 0x48833527, 0xA603470E, 0x9BD2329F, 0x76E43668 }
	TAG_STRUCT(
		PurchaseAppearanceDefinitionReferenceStruct,
		"PurchaseAppearanceDefinitionReferenceStruct",
		"s_cookie_purchase_definition_reference",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PURCHASEAPPEARANCEDEFINITIONREFERENCESTRUCT_ID)
	{
		{ _field_short_block_index, "item reference", FIELD_FLAG_INDEX, &CookiePurchaseAppearanceDefinitionBlock_block },
		FIELD_PAD("pad1", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	#define PURCHASELOADOUTDEFINITIONREFERENCESTRUCT_ID { 0x074268E4, 0x4CD54AC6, 0xA50A5222, 0xC59797D2 }
	TAG_STRUCT(
		PurchaseLoadoutDefinitionReferenceStruct,
		"PurchaseLoadoutDefinitionReferenceStruct",
		"s_cookie_purchase_definition_reference",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PURCHASELOADOUTDEFINITIONREFERENCESTRUCT_ID)
	{
		{ _field_short_block_index, "item reference", FIELD_FLAG_INDEX, &CookiePurchaseLoadoutDefinitionBlock_block },
		FIELD_PAD("pad1", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	#define PURCHASEORDNANCEDEFINITIONREFERENCESTRUCT_ID { 0x9B560063, 0x138A4E32, 0x8D089C68, 0x9FB1BF32 }
	TAG_STRUCT(
		PurchaseOrdnanceDefinitionReferenceStruct,
		"PurchaseOrdnanceDefinitionReferenceStruct",
		"s_cookie_purchase_definition_reference",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PURCHASEORDNANCEDEFINITIONREFERENCESTRUCT_ID)
	{
		{ _field_short_block_index, "item reference", FIELD_FLAG_INDEX, &CookiePurchaseOrdnanceDefinitionBlock_block },
		FIELD_PAD("pad1", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	STRINGS(MarketplaceOfferTypeEnum)
	{
		"DeadeyeHelmet",
		"LocusHelmet",
		"GungnirPulse",
		"VenatorRaptor",
		"CIOWeb",
		"HazopForest",
		"OceanicCircuit",
		"BattleRifleArctic",
		"BonebreakerEmblem",
		"AssassinEmblem",
		"BulletproofEmblem",
		"SpartanEmblem",
		"MjolnirEmblem",
		"LCE1Emblem",
		"SpartanIVArmorUnique",
		"AssaultRifleUnique",
		"Specializations",
		"UnicornEmblem",
		"UnicornArmor",
		"UnicornLightRifle",
		"LiveEmblem",
		"ScannerHelmet",
		"StriderHelmet",
		"FalconEmblem",
		"Reserved01",
		"Reserved02",
		"Reserved04",
		"Reserved08",
		"Reserved10",
		"Reserved20",
		"Reserved40",
		"ReservedDoNotUse80"
	};
	STRING_LIST(MarketplaceOfferTypeEnum, MarketplaceOfferTypeEnum_strings, _countof(MarketplaceOfferTypeEnum_strings));

} // namespace macaque

} // namespace blofeld

