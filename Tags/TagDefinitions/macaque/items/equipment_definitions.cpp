#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		equipment_group,
		EQUIPMENT_TAG,
		&item_group,
		ITEM_TAG,
		equipment_block );

	TAG_BLOCK_FROM_STRUCT(
		equipment_block,
		"equipment_block",
		1,
		equipment_struct_definition);

	#define OPTIONALUNITCAMERABLOCK_ID { 0x85EBC038, 0x51394353, 0xAEDC0BB1, 0x06CA0F4B }
	TAG_BLOCK(
		optionalUnitCameraBlock_block,
		"optionalUnitCameraBlock",
		1,
		"s_unit_camera",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		OPTIONALUNITCAMERABLOCK_ID)
	{
		{ _field_struct, "unit camera", &unit_camera_struct },
		{ _field_terminator }
	};

	#define EQUIPMENTABILITYDATUM_ID { 0x94AFD719, 0xB6EB42A2, 0xAB347BA3, 0xD20773A1 }
	TAG_BLOCK(
		equipmentAbilityDatum_block,
		"equipmentAbilityDatum",
		k_equipmentMaxAbilityCount,
		"EquipmentAbility",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		EQUIPMENTABILITYDATUM_ID)
	{
		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 21 },
		FIELD_CUSTOM("Timers", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_real, "duration", "use negative numbers for infinite duration", "seconds" },
		{ _field_real, "warmup time", "time before the equipment truly becomes active", "seconds" },
		{ _field_real, "cooldown time", "for equipment that suppresses combat actions, these actions remain suppressed for this long after the equipment deactivates\nNote that if this equipment also readies weapons when deactivated, the weapon will not be usable until both this timer expires and the ready animation has finished, whichever is longer", "seconds" },
		{ _field_real, "phantom volume activation time", "time in seconds for the phantom volumes on this object to start accelerating things in them" },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		FIELD_CUSTOM("Energy", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		FIELD_EXPLANATION("Energy", nullptr, FIELD_FLAG_NONE, "All these fields are additive, meaning a negative number will reduce energy and a positive one will increase energy.  Every piece of equipment starts at 1.0 energy"),
		{ _field_real, "minimum activation energy", "energy must be at least this high to activate\nLike activation cost, but doesn't actually change energy levels" },
		{ _field_real, "low energy warning threshold", "used by UI" },
		{ _field_real, "activation energy cost" },
		{ _field_real, "deactivation energy cost" },
		{ _field_real, "active energy rate", nullptr, "energy/second" },
		{ _field_struct, "movement speed to energy rate", nullptr, "1/s", &scalar_function_named_struct },
		{ _field_real, "movement speed domain", nullptr, "wu/s" },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		{ _field_long_flags, "flags", &equipment_activation_flags },
		{ _field_long_flags, "secondary flags", &equipmentActivationSecondaryFlags },
		{ _field_short_integer, "charges", "-1 means unlimited charges" },
		{ _field_char_enum, "activation mode", FIELD_FLAG_INDEX, &equipment_activation_mode },
		{ _field_char_integer, "object noise adjustment", "for AI perception.\nwhile active, adjusts noises made by the owner unit by this many 'notches'.\nnote that this is additive, so a positive number is louder and a negative number is quieter" },

		FIELD_CUSTOM("Type Definitions", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_block, "multiplayer powerup", &equipmentAbilityTypeMultiplayerPowerupBlock_block },
		{ _field_block, "spawner", &equipmentAbilityTypeSpawnerBlock_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_block, "ai spawner", &equipmentAbilityTypeAiSpawnerBlock_block },

		{ _field_block, "proximity mine", &equipmentAbilityTypeProximityMineBlock_block },
		{ _field_block, "moition tracker noise", &equipmentAbilityTypeMotionTrackerNoiseBlock_block },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_block, "unknown@", &g_null_block },

		{ _field_block, "invincibility mode", &equipmentAbilityTypeInvincibilityBlock_block },
		{ _field_block, "tree of life", &equipmentAbilityTypeTreeOfLifeBlock_block },
		{ _field_block, "shapeshifter", &equipmentAbilityTypeShapeshifterBlock_block },
		{ _field_block, "player trait field", &equipmentAbilityTypePlayerTraitFieldBlock_block },
		{ _field_block, "ai trait field", &equipmentAbilityTypeAiTraitFieldBlock_block },
		{ _field_block, "repulsor field", &equipmentAbilityTypeRepulsorFieldBlock_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_block, "stasis field", &equipmentAbilityTypeStasisFieldBlock_block },
		{ _field_block, "ball lightning", &equipmentAbilityTypeBallLightningBlock_block },

		{ _field_block, "IWHBYDaddy", &equipmentAbilityTypeDaddyBlock_block },
		{ _field_block, "laser designation", &equipmentAbilityTypeLaserDesignationBlock_block },
		{ _field_block, "super jump", &equipmentAbilityTypeSuperJumpBlock_block },
		{ _field_block, "ammo pack", &equipmentAbilityTypeAmmoPackBlock_block },
		{ _field_block, "power fist", &equipmentAbilityTypePowerFistBlock_block },
		{ _field_block, "health pack", &equipmentAbilityTypeHealthPackBlock_block },
		{ _field_block, "jet pack", &equipmentAbilityTypeJetPackBlock_block },
		{ _field_block, "hologram", &equipmentAbilityTypeHologramBlock_block },
		{ _field_block, "special weapon", &equipmentAbilityTypeSpecialWeaponBlock_block },
		{ _field_block, "special move", &equipmentAbilityTypeSpecialMoveBlock_block },
		{ _field_block, "engineer shields", &equipmentAbilityTypeEngineerShieldsBlock_block },
		{ _field_block, "sprint", &equipmentAbilityTypeSprintBlock_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 19 },
		{ _field_block, "teleporter", &equipmentAbilityTypeTeleporterBlock_block },
		{ _field_block, "auto turret", &equipmentAbilityTypeAutoTurretBlock_block },
		{ _field_block, "vision mode", &equipmentAbilityTypeVisionModeBlock_block },
		{ _field_block, "shield projector", &equipmentAbilityTypeShieldProjectorBlock_block },
		{ _field_block, "projectile collector", &equipmentAbilityTypeProjectileCollectorBlock_block },
		{ _field_block, "remote strike", &equipmentAbilityTypeRemoteStrikeBlock_block },
		{ _field_block, "equipment hacker", &equipmentAbilityTypeEquipmentHackerBlock_block },
		{ _field_block, "remote vehicle", &equipmentAbilityTypeRemoteVehicleBlock_block },
		{ _field_block, "suicide bomb", &equipmentAbilityTypeSuicideBombBlock_block },
		{ _field_block, "active shield", &equipmentAbilityTypeActiveShieldBlock_block },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		{ _field_tag_reference, "activation while disabled by player traits sound", &global_sound_reference },
		{ _field_tag_reference, "activate effect", &global_effect_reference },
		{ _field_tag_reference, "looping effect", &global_effect_reference },
		{ _field_tag_reference, "deactivate effect", &global_effect_reference },
		{ _field_string_id, "activation animation" },
		{ _field_string_id, "active animation" },
		{ _field_string_id, "deactivate animation" },
		{ _field_string_id, "active animation stance" },

		{ _field_terminator }
	};

	#define EQUIPMENTABILITYTYPEMULTIPLAYERPOWERUPBLOCK_ID { 0x722536F2, 0xBC644EEF, 0xAD1E23AD, 0x7F611939 }
	TAG_BLOCK(
		equipmentAbilityTypeMultiplayerPowerupBlock_block,
		"equipmentAbilityTypeMultiplayerPowerupBlock",
		1,
		"EquipmentAbilityTypeMultiplayerPowerup",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		EQUIPMENTABILITYTYPEMULTIPLAYERPOWERUPBLOCK_ID)
	{
		{ _field_long_enum, "flavor", &multiplayer_powerup_flavor },
		{ _field_terminator }
	};

	#define EQUIPMENTABILITYTYPESPAWNERBLOCK_ID { 0x094A0C6C, 0xB09B4658, 0xA912F337, 0x82263A70 }
	TAG_BLOCK(
		equipmentAbilityTypeSpawnerBlock_block,
		"equipmentAbilityTypeSpawnerBlock",
		1,
		"EquipmentAbilityTypeSpawner",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		EQUIPMENTABILITYTYPESPAWNERBLOCK_ID)
	{
		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 2},
		{ _field_legacy, _field_tag_reference, "spawned object", &object_reference$4 },
		{ _field_legacy, _field_tag_reference, "spawned effect", &global_effect_reference },

		{ _field_real, "spawn radius", "distance from players eyeball on the z-plane that this effect spawns" },
		{ _field_real, "spawn z offset", "z-offset of effect spawn" },
		{ _field_real, "spawn area radius", "need a sphere of radius r's free space in order to spawn, otherwise we pick a new spawn location" },
		{ _field_real, "spawn velocity", "WU/sec" },
		{ _field_enum, "type", &equipment_spawner_spawn_type },
		FIELD_PAD("LSJ", nullptr, FIELD_FLAG_NONE, 2),

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_tag_reference, "spawned object", &object_reference$4 },
		{ _field_tag_reference, "spawned effect", &global_effect_reference },

		{ _field_terminator }
	};

	#define EQUIPMENTABILITYTYPEAISPAWNERBLOCK_ID { 0x66BF1BDC, 0x55CD4D37, 0xB0F472F5, 0xBE8FD3C3 }
	TAG_BLOCK(
		equipmentAbilityTypeAiSpawnerBlock_block,
		"equipmentAbilityTypeAiSpawnerBlock",
		1,
		"EquipmentAbilityTypeAiSpawner",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		EQUIPMENTABILITYTYPEAISPAWNERBLOCK_ID)
	{
		{ _field_real, "spawn radius", "distance from players eyeball on the z-plane that this effect spawns" },
		{ _field_real, "spawn z offset", "z-offset of effect spawn" },
		{ _field_real, "spawn area radius", "need a sphere of radius r's free space in order to spawn, otherwise we pick a new spawn location" },
		{ _field_real, "spawn velocity", "WU/sec" },
		{ _field_enum, "type", &equipment_spawner_spawn_type },
		FIELD_PAD("RFD", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_tag_reference, "spawned character", &character_reference$4 },
		{ _field_terminator }
	};

	#define EQUIPMENTABILITYTYPEPROXIMITYMINEBLOCK_ID { 0x5B614FE2, 0xDCDC4443, 0xAD380949, 0x1CC95A5E }
	TAG_BLOCK(
		equipmentAbilityTypeProximityMineBlock_block,
		"equipmentAbilityTypeProximityMineBlock",
		1,
		"EquipmentAbilityTypeProximityMine",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		EQUIPMENTABILITYTYPEPROXIMITYMINEBLOCK_ID)
	{
		{ _field_tag_reference, "explosion effect", &global_effect_reference },
		{ _field_tag_reference, "explosion damage effect", &global_damage_reference },
		{ _field_real, "arm time", "time before it becomes a proximity mine" },
		{ _field_real, "self destruct time", "seconds after it is created that it must self destruct.  0 means never destroy" },
		{ _field_real, "trigger time", "seconds object moving at trigger velocity takes to trigger explosion.  This will smooth out sensitivity to velocity noise" },
		{ _field_real, "trigger velocity", "WU/sec at which we trigger explosion" },
		{ _field_terminator }
	};

	#define EQUIPMENTABILITYTYPEMOTIONTRACKERNOISEBLOCK_ID { 0x480DD4C7, 0x59894CFD, 0xAC664023, 0x2F91791D }
	TAG_BLOCK(
		equipmentAbilityTypeMotionTrackerNoiseBlock_block,
		"equipmentAbilityTypeMotionTrackerNoiseBlock",
		1,
		"EquipmentAbilityTypeMotionTrackerNoise",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		EQUIPMENTABILITYTYPEMOTIONTRACKERNOISEBLOCK_ID)
	{
		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_long_flags, "flags", &equipmentAbilityType_MotionTrackerNoise_flags },

		{ _field_real, "arm time", "time before it starts making noise" },
		{ _field_real, "noise radius", "radius in WU that the noise extends to." },
		{ _field_long_integer, "noise count", "number of noise points that are generated" },
		{ _field_real, "flash radius", "radius in WU that the damage flash noise extends to." },
		{ _field_terminator }
	};

	#define EQUIPMENTABILITYTYPEINVINCIBILITYBLOCK_ID { 0x0B02D7AE, 0xA10DBB78, 0xC0E7DE1A, 0x2ADAE4DB }
	TAG_BLOCK(
		equipmentAbilityTypeInvincibilityBlock_block,
		"equipmentAbilityTypeInvincibilityBlock",
		1,
		"EquipmentAbilityTypeInvincibilityMode",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		EQUIPMENTABILITYTYPEINVINCIBILITYBLOCK_ID)
	{
		{ _field_string_id, "invincibility material" },
		{ _field_short_integer, "invincibility material type", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		FIELD_PAD("invincibility material pad", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real, "shield recharge rate", "while active, shields recharge at this fraction per second", "1.0f/s" },
		{ _field_real, "shield max recharge level", "highest level shield can recharge to (can be up to 4)" },
		{ _field_tag_reference, "override collision damage", &collision_damage_reference$3 },
		{ _field_tag_reference, "ai melee reflect damage", &damage_effect_reference$2 },
		{ _field_tag_reference, "player melee reflect damage", &damage_effect_reference$2 },
		{ _field_string_id, "loop-invincibility shield name", "active while the equipment is in use (used for shield rendering effects)" },
		{ _field_string_id, "post-invincibility shield name", "active once the equipment is no longer in use" },
		{ _field_struct, "post-invincibility time to shield level function", &scalar_function_named_struct },
		{ _field_real, "maximum vertical velocity", "we use this to specify the domain of the active vertical velocity funtion", "WU/SEC" },
		{ _field_struct, "active vertical velocity damping", &scalar_function_named_struct },
		{ _field_block, "threshold effects", "the effect with the highest threshold will play on deactivation", &equipmentEffectWithThresholdBlock_block },
		{ _field_terminator }
	};

	#define EQUIPMENTEFFECTWITHTHRESHOLDBLOCK_ID { 0x0648007E, 0x418E4DDE, 0xA5C71D06, 0xCC447A75 }
	TAG_BLOCK(
		equipmentEffectWithThresholdBlock_block,
		"equipmentEffectWithThresholdBlock",
		10,
		"s_equipment_effect_with_threshold",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		EQUIPMENTEFFECTWITHTHRESHOLDBLOCK_ID)
	{
		{ _field_real, "threshold energy burned", "how much energy you have to burn to play this effect", "0-1", FIELD_FLAG_INDEX },
		{ _field_real, "energy adjustment", "how much energy to add when playing this effect", "-1 to 1" },
		{ _field_tag_reference, "effect", &global_effect_reference },
		{ _field_terminator }
	};

	#define EQUIPMENTABILITYTYPETREEOFLIFEBLOCK_ID { 0xBD1902E6, 0x186146F4, 0xB593ECBF, 0x3804E959 }
	TAG_BLOCK(
		equipmentAbilityTypeTreeOfLifeBlock_block,
		"equipmentAbilityTypeTreeOfLifeBlock",
		1,
		"EquipmentAbilityTypeTreeOfLife",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		EQUIPMENTABILITYTYPETREEOFLIFEBLOCK_ID)
	{
		{ _field_long_flags, "flags", &equipmentAbilityType_treeoflife_flags },
		{ _field_string_id, "origin marker" },
		{ _field_real, "radius" },
		{ _field_terminator }
	};

	#define EQUIPMENTABILITYTYPESHAPESHIFTERBLOCK_ID { 0x22338F4E, 0xCCFC486B, 0xAA6093F1, 0x5E704DD6 }
	TAG_BLOCK(
		equipmentAbilityTypeShapeshifterBlock_block,
		"equipmentAbilityTypeShapeshifterBlock",
		1,
		"EquipmentAbilityTypeShapeshifter",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		EQUIPMENTABILITYTYPESHAPESHIFTERBLOCK_ID)
	{
		{ _field_string_id, "region name" },
		{ _field_string_id, "inactive permutation name" },
		{ _field_string_id, "active permutation name" },
		{ _field_terminator }
	};

	#define EQUIPMENTABILITYTYPEPLAYERTRAITFIELDBLOCK_ID { 0x5A671CC4, 0x9D8D44CA, 0xA3EA38A8, 0xC13CA44A }
	TAG_BLOCK(
		equipmentAbilityTypePlayerTraitFieldBlock_block,
		"equipmentAbilityTypePlayerTraitFieldBlock",
		1,
		"EquipmentAbilityTypePlayerTraitField",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		EQUIPMENTABILITYTYPEPLAYERTRAITFIELDBLOCK_ID)
	{
		FIELD_SKIP("radius", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_block, "active player traits", &game_engine_player_traits_block },
		{ _field_block, "inactive player traits", &game_engine_player_traits_block },
		{ _field_terminator }
	};

	#define EQUIPMENTABILITYTYPEAITRAITFIELDBLOCK_ID { 0x54AB38A6, 0xE7644A67, 0xB659C021, 0x2517CF1D }
	TAG_BLOCK(
		equipmentAbilityTypeAiTraitFieldBlock_block,
		"equipmentAbilityTypeAiTraitFieldBlock",
		1,
		"EquipmentAbilityTypeAiTraitField",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		EQUIPMENTABILITYTYPEAITRAITFIELDBLOCK_ID)
	{
		{ _field_block, "active ai equipment traits", &aiEquipmentTraitsBlock_block },
		{ _field_block, "inactive ai equipment traits", &aiEquipmentTraitsBlock_block },
		{ _field_terminator }
	};

	#define AIEQUIPMENTTRAITSBLOCK_ID { 0xA4BC8CA7, 0xF0E14FAE, 0x98292262, 0xF2809C3A }
	TAG_BLOCK(
		aiEquipmentTraitsBlock_block,
		"aiEquipmentTraitsBlock",
		1,
		"s_ai_equipement_traits",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		AIEQUIPMENTTRAITSBLOCK_ID)
	{
		{ _field_block, "appearance traits", &aiEquipmentTraitAppearanceBlock_block },
		{ _field_terminator }
	};

	#define AIEQUIPMENTTRAITAPPEARANCEBLOCK_ID { 0xA2186C77, 0x36B54B46, 0xA9AFB3E7, 0xC45F17C8 }
	TAG_BLOCK(
		aiEquipmentTraitAppearanceBlock_block,
		"aiEquipmentTraitAppearanceBlock",
		1,
		"s_ai_equipment_trait_appearance",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		AIEQUIPMENTTRAITAPPEARANCEBLOCK_ID)
	{
		FIELD_EXPLANATION("Appearance Traits", nullptr, FIELD_FLAG_NONE, "Traits that affect the AI\'s appearance"),
		{ _field_char_enum, "active camo setting", &player_trait_active_camo },
		FIELD_PAD("pad", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_terminator }
	};

	#define EQUIPMENTABILITYTYPEREPULSORFIELDBLOCK_ID { 0x1941789D, 0x3D774B27, 0x95D5AD84, 0x3F228963 }
	TAG_BLOCK(
		equipmentAbilityTypeRepulsorFieldBlock_block,
		"equipmentAbilityTypeRepulsorFieldBlock",
		1,
		"EquipmentAbilityTypeRepulsorField",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		EQUIPMENTABILITYTYPEREPULSORFIELDBLOCK_ID)
	{
		{ _field_long_flags, "flags", &repulsor_field_flags },
		{ _field_real, "radius", nullptr, "wu" },
		{ _field_real, "power" },
		{ _field_terminator }
	};

	#define EQUIPMENTABILITYTYPESTASISFIELDBLOCK_ID { 0x093E5892, 0xE0AA4A8E, 0x801153D9, 0xE061EC46 }
	TAG_BLOCK(
		equipmentAbilityTypeStasisFieldBlock_block,
		"equipmentAbilityTypeStasisFieldBlock",
		1,
		"EquipmentAbilityTypeStasisField",
		SET_POSTPROCESS_RECURSIVELY | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		EQUIPMENTABILITYTYPESTASISFIELDBLOCK_ID)
	{
		{ _field_long_flags, "flags", &repulsor_field_flags },
		{ _field_real, "radius", nullptr, "wu" },
		FIELD_CUSTOM("Time Dilation Values", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		FIELD_EXPLANATION("Time Dilation", nullptr, FIELD_FLAG_NONE, "The effective rate at which time passes for objects in the field.  Values below 0.45 screw up jumping."),
		{ _field_real, "time dilation player characters" },
		{ _field_real, "time dilation projectiles" },
		{ _field_real, "time dilation vehicles" },
		{ _field_real, "time dilation other", "everything else" },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		{ _field_real, "max biped turning rate", nullptr, "no idea what units... something like .2 or so" },
		{ _field_real, "gravity multiplier", "negative values will invert gravity" },
		{ _field_terminator }
	};

	#define EQUIPMENTABILITYTYPEBALLLIGHTNINGBLOCK_ID { 0xE6C8848E, 0xC6284601, 0x94E9738C, 0x282AC84F }
	TAG_BLOCK(
		equipmentAbilityTypeBallLightningBlock_block,
		"equipmentAbilityTypeBallLightningBlock",
		1,
		"EquipmentAbilityTypeBallLightning",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		EQUIPMENTABILITYTYPEBALLLIGHTNINGBLOCK_ID)
	{
		{ _field_long_flags, "flags", &repulsor_field_flags },
		{ _field_real, "start radius", nullptr, "wu" },
		FIELD_EXPLANATION("Ball Lightning", nullptr, FIELD_FLAG_NONE, "Damage effect that passes from one biped to nearby bipeds, recursively"),
		{ _field_real, "chain radius reduction multiplier", "MUST BE GREATER THAN ZERO - each time lightning chains, this is the multiplier that controls how much the radius is reduced by", nullptr, "[0.01, 1]", FIELD_FLAG_INDEX },
		{ _field_real, "chain delay timer", nullptr, "seconds" },
		{ _field_tag_reference, "lightning damage", &global_damage_reference },
		{ _field_terminator }
	};

	#define EQUIPMENTABILITYTYPEDADDYBLOCK_ID { 0x7E61D95C, 0x7E374E85, 0x9A9F6832, 0xB8984DDC }
	TAG_BLOCK(
		equipmentAbilityTypeDaddyBlock_block,
		"equipmentAbilityTypeDaddyBlock",
		1,
		"EquipmentAbilityTypeDaddy",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		EQUIPMENTABILITYTYPEDADDYBLOCK_ID)
	{
		{ _field_tag_reference, "child object", &object_reference$4 },
		{ _field_word_flags, "flags", &equipmentAbilityTypeDaddyVisibleFlags },
		FIELD_PAD("dada", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real, "shield damage to energy scale", "scale factor for energy gain from shield damage to child.\nDamage is normalized, so if this value is -1.0 then the equipment will lose all its energy when its child's shield is depleted." },
		{ _field_real, "starting warm up object scale", "if >0 (and warm up time is >0), object size will scale up from this up to 1.0 over course of warm up time and down over cooldown time" },
		{ _field_real_point_3d, "offset from parent", "the root of the child is offset by this amount from the root of the parent biped" },
		{ _field_real, "vertical offset in world space", "used to adjust hight per biped, regardless of aim direction" },
		{ _field_real_bounds, "min and max pitch", "the min and max pitch that the child will follow as you aim up and down.  -90 to 90", "degrees" },
		{ _field_real, "visual activation time", nullptr, "seconds" },
		{ _field_tag_reference, "spawn effect", &global_effect_reference },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_marker),
		{ _field_string_id, "spawn effect marker" },
		{ _field_tag_reference, "despawn effect", &global_effect_reference },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_marker),
		{ _field_string_id, "despawn effect marker" },
		{ _field_terminator }
	};

	#define EQUIPMENTABILITYTYPELASERDESIGNATIONBLOCK_ID { 0xD5ABC610, 0xB1BB4BE8, 0xA33289BD, 0xA8B4FC22 }
	TAG_BLOCK(
		equipmentAbilityTypeLaserDesignationBlock_block,
		"equipmentAbilityTypeLaserDesignationBlock",
		1,
		"EquipmentAbilityTypeLaserDesignation",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		EQUIPMENTABILITYTYPELASERDESIGNATIONBLOCK_ID)
	{
		{ _field_real, "unused", FIELD_FLAG_UNKNOWN0 },
		{ _field_terminator }
	};

	#define EQUIPMENTABILITYTYPESUPERJUMPBLOCK_ID { 0xF8751FEC, 0x0B824A62, 0x8CE0A3A6, 0x979B7F8A }
	TAG_BLOCK(
		equipmentAbilityTypeSuperJumpBlock_block,
		"equipmentAbilityTypeSuperJumpBlock",
		1,
		"EquipmentAbilityTypeSuperJump",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		EQUIPMENTABILITYTYPESUPERJUMPBLOCK_ID)
	{
		{ _field_struct, "energy to jump", &scalar_function_named_struct },
		{ _field_terminator }
	};

	#define EQUIPMENTABILITYTYPEAMMOPACKBLOCK_ID { 0xCD976E6F, 0x30024F0C, 0x889E8DC5, 0x5612CFD3 }
	TAG_BLOCK(
		equipmentAbilityTypeAmmoPackBlock_block,
		"equipmentAbilityTypeAmmoPackBlock",
		1,
		"EquipmentAbilityTypeAmmoPack",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		EQUIPMENTABILITYTYPEAMMOPACKBLOCK_ID)
	{
		{ _field_real, "energy change per clip added" },
		{ _field_long_integer, "extra frags" },
		{ _field_long_integer, "extra plasma" },
		{ _field_long_integer, "extra grenade 3" },
		{ _field_long_integer, "extra grenade 4" },
		{ _field_long_integer, "extra grenade 5" },
		{ _field_long_integer, "extra grenade 6" },
		{ _field_long_integer, "extra grenade 7" },
		{ _field_long_integer, "extra grenade 8" },
		{ _field_terminator }
	};

	#define EQUIPMENTABILITYTYPEPOWERFISTBLOCK_ID { 0xB7516F5E, 0x8E8645EE, 0xA8FB87FF, 0xBAF48D47 }
	TAG_BLOCK(
		equipmentAbilityTypePowerFistBlock_block,
		"equipmentAbilityTypePowerFistBlock",
		1,
		"EquipmentAbilityTypePowerFist",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		EQUIPMENTABILITYTYPEPOWERFISTBLOCK_ID)
	{
		{ _field_tag_reference, "melee damage", &global_damage_reference },
		{ _field_tag_reference, "melee response", &global_damage_effect_or_response_definition_reference },
		{ _field_tag_reference, "clang damage", &global_damage_reference },
		{ _field_tag_reference, "clang response", &global_damage_effect_or_response_definition_reference },
		{ _field_terminator }
	};

	#define EQUIPMENTABILITYTYPEHEALTHPACKBLOCK_ID { 0x51194C17, 0xFB474562, 0x9233D362, 0x8DC64DB3 }
	TAG_BLOCK(
		equipmentAbilityTypeHealthPackBlock_block,
		"equipmentAbilityTypeHealthPackBlock",
		1,
		"EquipmentAbilityTypeHealthPack",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		EQUIPMENTABILITYTYPEHEALTHPACKBLOCK_ID)
	{
		{ _field_struct, "health given over energy used", &scalar_function_named_struct },
		{ _field_terminator }
	};

	#define EQUIPMENTABILITYTYPEJETPACKBLOCK_ID { 0x5AA45049, 0x747240B2, 0x844C11B6, 0x272429F2 }
	TAG_BLOCK(
		equipmentAbilityTypeJetPackBlock_block,
		"equipmentAbilityTypeJetPackBlock",
		1,
		"EquipmentAbilityTypeJetPack",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		EQUIPMENTABILITYTYPEJETPACKBLOCK_ID)
	{
		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_byte_flags, "flags", &equipmentAbilityTypeJetPackFlags },
		FIELD_PAD("pad after useCamAndMoveForThrustDirection", nullptr, FIELD_FLAG_NONE, 3),

		{ _field_struct, "thrust to acceleration function", &scalar_function_named_struct },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_struct, "Infinite energy thrust to acceleration function", &scalar_function_named_struct },

		{ _field_real, "thrust attack time", nullptr, "s" },
		{ _field_real, "thrust decay time", nullptr, "s" },
		{ _field_real, "negative velocity acceleration scale", "when falling, scale the thrust by this (so you can 'catch' yourself easier)" },
		{ _field_real, "airborne acceleration scale", FIELD_FLAG_UNKNOWN0 },
		{ _field_real, "grounded acceleration magnitude", "how hard to kick you upwards if you activate while grounded" },
		{ _field_real, "landing anticipation time", "how many seconds before landing the jetpack user enters the airborne arc", "s" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 10 },
		FIELD_EXPLANATION("Zero-G jet pack", nullptr, FIELD_FLAG_NONE, "These apply if \'Use camera and movement for thrust dir\' flag is checked"),
		{ _field_real, "camera vs move input thrust control", "Camera direction (0.0) VS movement input (1.0) interpolation" },
		{ _field_real, "min speed", "drag will be applied above this" },
		{ _field_real, "max speed" },
		{ _field_real, "stick forward thrust" },
		{ _field_real, "stick strafe thrust" },
		{ _field_real, "drag" },
		{ _field_real, "drag cutoff time", "if 0, drag is always applied" },
		{ _field_real, "cow catcher duration" },
		{ _field_block, "cow catcher parameters", &equipmentAbilityPartCowCatcherBlock_block },

		{ _field_terminator }
	};

	#define EQUIPMENTABILITYPARTCOWCATCHERBLOCK_ID { 0xF15A68E8, 0xB423423C, 0x83E49DD1, 0xA82C51A5 }
	TAG_BLOCK(
		equipmentAbilityPartCowCatcherBlock_block,
		"equipmentAbilityPartCowCatcherBlock",
		1,
		"EquipmentAbilityPartCowCatcher",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		EQUIPMENTABILITYPARTCOWCATCHERBLOCK_ID)
	{
		{ _field_real, "cow catcher height", "world units" },
		{ _field_real, "cow catcher front width", "world units, the width of the flat front portion of the cow-catcher" },
		{ _field_real, "cow catcher side width", "world units, the width of the angled side portion of the cow-catcher" },
		{ _field_real, "cow catcher side depth", "world units, the depth of the angled side portion of the cow-catcher" },
		{ _field_real_vector_3d, "cow catcher offset", "offset from the unit's origin to put the origin of the cow-catcher at" },
		{ _field_tag_reference, "collision damage override", "if \"hide unit during transit\" isn't checked, this can override the unit's collision damage definition during the teleport", &collision_damage_reference$4 },
		{ _field_terminator }
	};

	#define EQUIPMENTABILITYTYPEHOLOGRAMBLOCK_ID { 0x97010557, 0x57654DBF, 0xA7B8368A, 0x77EFE214 }
	TAG_BLOCK(
		equipmentAbilityTypeHologramBlock_block,
		"equipmentAbilityTypeHologramBlock",
		1,
		"EquipmentAbilityTypeHologram",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		EQUIPMENTABILITYTYPEHOLOGRAMBLOCK_ID)
	{
		{ _field_real, "hologram duration", nullptr, "s" },
		{ _field_long_enum, "havok filter group", &collision_filter_enum },
		{ _field_tag_reference, "creation effect", &global_effect_reference },
		{ _field_tag_reference, "attached effect", &global_effect_reference },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_marker),
		{ _field_string_id, "attached effect marker" },
		{ _field_string_id, "attached effect primary scale" },
		{ _field_string_id, "attached effect secondary scale" },
		{ _field_tag_reference, "destruction effect", &global_effect_reference },
		{ _field_real, "shimmer decrease rate", "how fast shimmer decreases", "1.0/s" },
		{ _field_real, "shimmer bullet ping", "how much to ping shimmer when hit by a bullet", "0-1" },
		{ _field_struct, "shimmer to camo function", "this is a periodic function with a period of 1 second\nthe shimmer value is used as the range input (interpolates between green and red)", &scalar_function_named_struct },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_byte_flags, "flags", &equipmentAbilityTypeHologramFlags },
		FIELD_PAD("pad after hologram flags", nullptr, FIELD_FLAG_NONE, 3),

		{ _field_terminator }
	};

	#define EQUIPMENTABILITYTYPESPECIALWEAPONBLOCK_ID { 0xAD13DE60, 0x89524538, 0x99481D62, 0xA70E7F5B }
	TAG_BLOCK(
		equipmentAbilityTypeSpecialWeaponBlock_block,
		"equipmentAbilityTypeSpecialWeaponBlock",
		1,
		"EquipmentAbilityTypeSpecialWeapon",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		EQUIPMENTABILITYTYPESPECIALWEAPONBLOCK_ID)
	{
		{ _field_tag_reference, "weapon", &global_weapon_reference },
		{ _field_terminator }
	};

	#define EQUIPMENTABILITYTYPESPECIALMOVEBLOCK_ID { 0x9A303175, 0x3AD74EA4, 0xBD64A730, 0x03760E27 }
	TAG_BLOCK(
		equipmentAbilityTypeSpecialMoveBlock_block,
		"equipmentAbilityTypeSpecialMoveBlock",
		1,
		"EquipmentAbilityTypeSpecialMove",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		EQUIPMENTABILITYTYPESPECIALMOVEBLOCK_ID)
	{
		{ _field_string_id, "forward" },
		{ _field_string_id, "left" },
		{ _field_string_id, "backward" },
		{ _field_string_id, "right" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 5 },
		{ _field_char_enum, "default direction", &EquipmentSpecialMoveDefaultDirectionDefinition },
		FIELD_PAD("pad0", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_tag_reference, "directional effect", &Tag::Reference<struct effect_definition>::s_defaultDefinition },
		{ _field_real, "Danger Radius", "AI avoidance radius.  Ignored if zero." },
		{ _field_real, "Speed multiplier", "Use this instead of a trait.  0 defaults to 1.  With a trait, the client will move at non-modified scale until it gets replicated." },

		{ _field_terminator }
	};

	#define EQUIPMENTABILITYTYPEENGINEERSHIELDSBLOCK_ID { 0x3A303175, 0x2AD74EA4, 0xBA64A730, 0x13760E27 }
	TAG_BLOCK(
		equipmentAbilityTypeEngineerShieldsBlock_block,
		"equipmentAbilityTypeEngineerShieldsBlock",
		1,
		"EquipmentAbilityTypeEngineerShields",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		EQUIPMENTABILITYTYPEENGINEERSHIELDSBLOCK_ID)
	{
		{ _field_real, "radius" },
		{ _field_string_id, "shield name" },
		{ _field_long_flags, "flags", &equipment_engineer_shields_flags },
		{ _field_terminator }
	};

	#define EQUIPMENTABILITYTYPESPRINTBLOCK_ID { 0xC2CF2C6B, 0xAE264A0A, 0x8C1B77E3, 0x3AA738B9 }
	TAG_BLOCK(
		equipmentAbilityTypeSprintBlock_block,
		"equipmentAbilityTypeSprintBlock",
		1,
		"EquipmentAbilityTypeSprint",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		EQUIPMENTABILITYTYPESPRINTBLOCK_ID)
	{
		FIELD_PAD("haha", nullptr, FIELD_FLAG_NONE, 1),
		{ _field_terminator }
	};

	#define EQUIPMENTABILITYTYPETELEPORTERBLOCK_ID { 0x6566AC44, 0x354B4E2B, 0xB5CB8234, 0xA3503CD5 }
	TAG_BLOCK(
		equipmentAbilityTypeTeleporterBlock_block,
		"equipmentAbilityTypeTeleporterBlock",
		1,
		"EquipmentAbilityTypeTeleporter",
		SET_UNKNOWN0 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | 
		SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		EQUIPMENTABILITYTYPETELEPORTERBLOCK_ID)
	{
		FIELD_EXPLANATION("Teleporter", nullptr, FIELD_FLAG_NONE, "This causes you to warp forward.  It\'ll trace the path with an effect at the specified speed, then spawn you at the end of it."),
		{ _field_byte_flags, "flags", &teleporterFlags },
		FIELD_PAD("blurgh", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_real, "teleport distance" },
		{ _field_real, "travel speed", "the speed at which you cross the teleporter distance; 0 means instant" },
		{ _field_real, "deactivation speed", "the speed you return to at the end of the teleport, if \"hide unit during transit\" isn't checked" },
		{ _field_tag_reference, "trace effect", "an effect that will follow along the travel path", &global_effect_reference },
		{ _field_real_vector_3d, "trace effect offset", "offset from the unit's origin to put the effects at" },
		{ _field_real, "max pitch (airborne)", "[-90 to 90] the pitch of the search vector will be clamped to no higher than this when starting a teleport in the air" },
		{ _field_real, "max pitch (ground)", "[-90 to 90] the pitch of the search vector will be clamped to no higher than this when starting a teleport on the ground" },
		FIELD_CUSTOM("Search Vector", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		FIELD_EXPLANATION("Look Vector Weight", nullptr, FIELD_FLAG_NONE, "If \"force along aim vector\" isn\'t checked, the start vector will be your motion vector, plus some amount of weight for where you\'re looking, if you\'re moving along your look vector."),
		{ _field_real, "look vector weight", "value from 0 to 1 for how much we can use the look vector in place of the movement vector" },
		{ _field_real, "look vector falloff inner", "degrees, inside this angle, we use the look vector at full weight" },
		{ _field_real, "look vector falloff outer", "degrees, outside this angle, we only use the movement vector" },
		{ _field_real, "move vector vertical offset", "degrees, how much to offset the move vector vertically; positive is up, negative is down" },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		FIELD_CUSTOM("Probes", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		FIELD_EXPLANATION("Probe", nullptr, FIELD_FLAG_NONE, "If \"disable extra probes\" isn\'t checked, we\'ll do a fan of rays vertically from our central vector, with one probe horizontally on either side of each of those rays."),
		{ _field_real, "horizontal probe angle", "degrees, the angle to each side of the horizontal probes" },
		{ _field_real, "vertical probe angle", "degrees, the angle up and down covered by the fan of vertical rays" },
		{ _field_long_integer, "number of vertical probes", "higher is more likely to find a good match, but more expensive" },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		FIELD_CUSTOM("Collision", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		FIELD_EXPLANATION("Collision", nullptr, FIELD_FLAG_NONE, "If \"hide unit during transit\" isn\'t checked, we\'ll add a cow-catcher collision volume on the front and change the collision damage type."),
		{ _field_block, "cow catcher parameters", &equipmentAbilityPartCowCatcherBlock_block },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		{ _field_terminator }
	};

	#define EQUIPMENTABILITYTYPEAUTOTURRETBLOCK_ID { 0xB2F58312, 0x187E45FA, 0xB6D5D498, 0x850FC6C9 }
	TAG_BLOCK(
		equipmentAbilityTypeAutoTurretBlock_block,
		"equipmentAbilityTypeAutoTurretBlock",
		1,
		"EquipmentAbilityTypeAutoTurret",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		EQUIPMENTABILITYTYPEAUTOTURRETBLOCK_ID)
	{
		{ _field_byte_flags, "flags", &equipment_auto_turret_flags },
		FIELD_PAD("atf", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_tag_reference, "weapon", &object_reference$4 },
		{ _field_real_point_3d, "orbit offset from player", "z forward, x right, y down.  Set x,z zero to get independent turret, y is altitude off ground" },
		{ _field_real, "orbit range", "if above are zeros, this is max turret range" },
		{ _field_real, "orbit rate", nullptr, "orbits per second" },
		{ _field_real, "maximum range", "if not following player, maximum distance downrange turret will travel" },
		{ _field_real, "max velocity", nullptr, "units per second" },
		{ _field_real, "max acceleration", nullptr, "units per second squared" },
		{ _field_real, "turret halt engage time", "amount of time after a moving turret engages a target before it halts movement", "seconds" },
		{ _field_real, "turret idle equipment drain multiplier", "the multiplier on equipment drain when equipment is in its idle state", nullptr, "[0.1]" },
		{ _field_real, "turret inactive equipment drain multiplier", "the multiplier on equipment drain when equipment is in its inactive state", nullptr, "[0.1]" },
		{ _field_real, "spawn radius", "area that must be clear in order for turret to spawn", "world units" },
		{ _field_real, "spawn in time", "the turret will be inactive for this duration", "seconds" },
		{ _field_real_vector_3d, "spawn offset from player", "relative to origin and camera direction without pitch", "world units" },
		{ _field_real, "vertical bob height", nullptr, "world units" },
		{ _field_real, "vertical bobs per second" },
		{ _field_tag_reference, "spawn effect", "effect played on the turret when it is spawned into the world", &global_effect_reference },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_marker),
		{ _field_string_id, "spawn effect marker" },
		{ _field_string_id, "spawn dissolve type" },
		{ _field_string_id, "spawn dissolve marker" },
		{ _field_tag_reference, "collision phase effect", "effect played on the turret while a biped or vehicle passes through it", &Tag::Reference<struct effect_definition>::s_defaultDefinition },
		{ _field_terminator }
	};

	#define EQUIPMENTABILITYTYPEVISIONMODEBLOCK_ID { 0x0E888D6A, 0xBEB249B3, 0xB34F52D8, 0x01D7C208 }
	TAG_BLOCK(
		equipmentAbilityTypeVisionModeBlock_block,
		"equipmentAbilityTypeVisionModeBlock",
		1,
		"EquipmentAbilityTypeVisionMode",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		EQUIPMENTABILITYTYPEVISIONMODEBLOCK_ID)
	{
		{ _field_byte_flags, "Flags", &equipmentVisionModeFlags },
		FIELD_PAD("vmbf", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_real, "maximum tell distance", "'Other activation tell effect' will be applied to players within this distance", "wu" },
		{ _field_tag_reference, "activation tell effect", "applied to other players within maximum distance", &global_effect_reference },
		{ _field_long_integer, "motion sensor tell blip ticks", "within 'maxiumum tell distance' blip duration if 'Generate tell motion sensor blip' is checked" },
		{ _field_tag_reference, "vision mode", &Tag::Reference<struct VisionModeDefinition>::s_defaultDefinition },
		{ _field_terminator }
	};

	#define EQUIPMENTABILITYTYPESHIELDPROJECTORBLOCK_ID { 0x87D0224D, 0xE3FF4C21, 0xA392E654, 0xD126F6A2 }
	TAG_BLOCK(
		equipmentAbilityTypeShieldProjectorBlock_block,
		"equipmentAbilityTypeShieldProjectorBlock",
		1,
		"EquipmentAbilityTypeShieldProjector",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		EQUIPMENTABILITYTYPESHIELDPROJECTORBLOCK_ID)
	{
		{ _field_real, "Lifetime ", "Number of seconds a projected shield will remain active." },
		{ _field_real, "Recharge Time ", "Number of seconds between shield projections." },
		{ _field_real, "Warmup Time ", "Number of seconds it takes to activate a projection." },
		{ _field_real_fraction, "Max Move Percentage ", "Percentage of distance between current and desired positions a shield can be moved per update tick." },
		{ _field_real, "Offset Amount ", "Distance from defender's position to project the shield." },
		{ _field_real, "Min Projection Distance ", "Minimum distance between defender and attacker required to project shield." },
		{ _field_real, "Max Projection Distance ", "Max distance from equipment that shield can be projected." },
		{ _field_real_fraction, "Min Required Energy Level ", "Min energy required to activate shield." },
		{ _field_tag_reference, "Project Effect ", "Beam effect that links equipment to projected shield.", &effect_reference$2 },
		{ _field_tag_reference, "Warmup Effect ", "Effect played at eventual shield projection point during warmup period.", &effect_reference$2 },
		{ _field_tag_reference, "Shield Crate ", "Crate created to represent projected shield.", &crate_reference$5 },
		{ _field_terminator }
	};

	#define EQUIPMENTABILITYTYPEPROJECTILECOLLECTORBLOCK_ID { 0x6189206D, 0x582E47EF, 0x97185355, 0x74E112D6 }
	TAG_BLOCK(
		equipmentAbilityTypeProjectileCollectorBlock_block,
		"equipmentAbilityTypeProjectileCollectorBlock",
		1,
		"EquipmentAbilityTypeProjectileCollector",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		EQUIPMENTABILITYTYPEPROJECTILECOLLECTORBLOCK_ID)
	{
		{ _field_real_fraction, "Chance to Collect ", "Percent chance (0-1) that collector has to collect each grenade.  Will only attempt to collect each grenade once." },
		{ _field_real_bounds, "Collect Cooldown ", "Number of seconds collector must wait between successful collections." },
		{ _field_real_bounds, "Attack Delay ", "Number of seconds collector must wait before throwing a collected projectile at a target." },
		{ _field_real, "Max Collect Range", "Max range in world units that collector can collect and hold onto projectiles." },
		{ _field_real_bounds, "Orbit Radius", "Collector will try to keep collected projectiles orbiting in this range." },
		{ _field_real, "Orbit Speed", "Speed at which collected projectiles orbit." },
		{ _field_real, "Vertical Offset", "Orbit vertical offset amount." },
		{ _field_real, "Strength", "Controls amount of acceleration applied to projectile." },
		{ _field_real, "Attack Speed", "Initial speed of projectiles when thrown as an attack." },
		{ _field_tag_reference, "Collect Effect ", "Beam effect that links equipment to each collected projectile.", &effect_reference$2 },
		{ _field_terminator }
	};

	#define EQUIPMENTABILITYTYPEREMOTESTRIKEBLOCK_ID { 0x837869A3, 0xC1AF46C4, 0x8CEE091D, 0x4EDA8D40 }
	TAG_BLOCK(
		equipmentAbilityTypeRemoteStrikeBlock_block,
		"equipmentAbilityTypeRemoteStrikeBlock",
		1,
		"EquipmentAbilityTypeRemoteStrike",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		EQUIPMENTABILITYTYPEREMOTESTRIKEBLOCK_ID)
	{
		{ _field_tag_reference, "weapon", &object_reference$4 },
		{ _field_real, "max velocity" },
		{ _field_real, "acceleration", "this is a percentage of max velocity per second - 0.1 reaches max velocity in 10 seconds" },
		{ _field_real, "decay rate", "the rate at which a moving camera decays when you release the stick.  Lower decays faster." },
		{ _field_real, "camera interpolation time" },
		{ _field_byte_flags, "flags", &equipment_remote_strike_flags },
		FIELD_PAD("rso", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_terminator }
	};

	#define EQUIPMENTABILITYTYPEEQUIPMENTHACKERBLOCK_ID { 0xFF1934CE, 0x4F5D4FAA, 0xADC69819, 0x22B04AB9 }
	TAG_BLOCK(
		equipmentAbilityTypeEquipmentHackerBlock_block,
		"equipmentAbilityTypeEquipmentHackerBlock",
		1,
		"EquipmentAbilityTypeEquipmentHacker",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		EQUIPMENTABILITYTYPEEQUIPMENTHACKERBLOCK_ID)
	{
		{ _field_byte_flags, "Flags", &equipmentHackerFlags },
		FIELD_PAD("grue", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_real, "Base drain per second", "Will be multiplied by a value from the drain level block." },
		{ _field_real, "Energy recovery delay", "The targeted equipment will not start regenerating energy until at least this much time has gone by." },
		{ _field_real, "Cone angle degrees", "Degrees away from the reticle at which targets are in the cone." },
		{ _field_block, "Drain levels", &equipmentHackerDrainLevel_block },
		{ _field_tag_reference, "cone effect", "an effect that will shoot out of your face", &global_effect_reference },
		{ _field_tag_reference, "target effect", "an effect that will play on the target", &global_effect_reference },
		{ _field_terminator }
	};

	#define EQUIPMENTHACKERDRAINLEVEL_ID { 0x737BF71D, 0x4FC14A0D, 0xB353676B, 0x7698A316 }
	TAG_BLOCK(
		equipmentHackerDrainLevel_block,
		"equipmentHackerDrainLevel",
		EquipmentAbilityTypeEquipmentHacker::DrainLevel::k_maxLevels,
		"EquipmentAbilityTypeEquipmentHacker::DrainLevel",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		EQUIPMENTHACKERDRAINLEVEL_ID)
	{
		{ _field_real, "Cutoff distance", "Targets within this distance will be affected by this multiplier." },
		{ _field_real, "Drain multiplier", "Multiplied by the base drain per second." },
		{ _field_terminator }
	};

	#define EQUIPMENTABILITYTYPEREMOTEVEHICLEBLOCK_ID { 0x20711F9E, 0xBD914250, 0xAC35F336, 0x4116390A }
	TAG_BLOCK(
		equipmentAbilityTypeRemoteVehicleBlock_block,
		"equipmentAbilityTypeRemoteVehicleBlock",
		1,
		"EquipmentAbilityTypeRemoteVehicle",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		EQUIPMENTABILITYTYPEREMOTEVEHICLEBLOCK_ID)
	{
		{ _field_tag_reference, "hologram spawner", "reference the equipment that will spawn the hologram that will pilot the remote vehicle", &object_reference$4 },
		{ _field_tag_reference, "vehicle", "reference the remote vehicle to be created", &object_reference$4 },
		{ _field_string_id, "seat label", "hologram gets loaded into this seat in the vehicle", FIELD_FLAG_INDEX },
		{ _field_string_id, "spawn position flag", "position of scenerio flag with this name. Empty will default to flag named 'remote_vehicle_start_position'" },
		{ _field_terminator }
	};

	#define EQUIPMENTABILITYTYPESUICIDEBOMBBLOCK_ID { 0xA65568DD, 0x1A5B4208, 0xA7A0D455, 0x9E304A41 }
	TAG_BLOCK(
		equipmentAbilityTypeSuicideBombBlock_block,
		"equipmentAbilityTypeSuicideBombBlock",
		1,
		"EquipmentAbilityTypeSuicideBomb",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		EQUIPMENTABILITYTYPESUICIDEBOMBBLOCK_ID)
	{
		{ _field_tag_reference, "explosion damage effect", &global_damage_reference },
		{ _field_tag_reference, "explosion effect", &global_effect_reference },
		{ _field_terminator }
	};

	#define EQUIPMENTABILITYTYPEACTIVESHIELDBLOCK_ID { 0x660BD22D, 0x44234908, 0xA97F6A1B, 0x471978A3 }
	TAG_BLOCK(
		equipmentAbilityTypeActiveShieldBlock_block,
		"equipmentAbilityTypeActiveShieldBlock",
		1,
		"EquipmentAbilityTypeActiveShield",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		EQUIPMENTABILITYTYPEACTIVESHIELDBLOCK_ID)
	{
		{ _field_byte_flags, "flags", &activeShieldFlags },
		{ _field_terminator }
	};

	#define EQUIPMENTSOUNDRTPCBLOCK_ID { 0x5C15BB60, 0x3F0D44C2, 0x9CCAF913, 0xAFF4B21B }
	TAG_BLOCK(
		EquipmentSoundRTPCBlock_block,
		"EquipmentSoundRTPCBlock",
		k_maxEquipmentSoundRTPCBlocks,
		"EquipmentSoundRTPCBlockDefinition",
		SET_UNKNOWN0 | SET_POSTPROCESS_RECURSIVELY | SET_IS_MEMCPYABLE | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		EQUIPMENTSOUNDRTPCBLOCK_ID)
	{
		{ _field_long_block_index, "Attachment Index", "Sound attachment to affect", &global_object_attachment_block },
		{ _field_string_id, "Function", "Function to drive the RTPC" },
		{ _field_string_id, "RTPC Name", "WWise RTPC string name" },
		{ _field_long_integer, "RTPC name hash value", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define EQUIPMENTSOUNDSWEETENERBLOCK_ID { 0x4F774A69, 0xC6AC4AF2, 0xA2B9AD3E, 0x91289963 }
	TAG_BLOCK(
		EquipmentSoundSweetenerBlock_block,
		"EquipmentSoundSweetenerBlock",
		k_maxEquipmentSoundSweetenerBlocks,
		"EquipmentSoundSweetenerBlockDefinition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		EQUIPMENTSOUNDSWEETENERBLOCK_ID)
	{
		{ _field_string_id, "Function", "Function to trigger the sweetener" },
		{ _field_tag_reference, "sound", &global_sound_reference },
		{ _field_real, "Switch point", "value of the function (between 0 and 1) where the sound is triggered" },
		{ _field_long_integer, "Mode", "0 for triggering while function is decreasing, 1 for increasing (more modes to come?)" },
		{ _field_terminator }
	};

	#define EQUIPMENT_STRUCT_DEFINITION_ID { 0x18B70662, 0x869349C3, 0xB79E4FBE, 0xC65A52CB }
	TAG_STRUCT(
		equipment_struct_definition,
		"equipment_struct_definition",
		"_equipment_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN4 | SET_UNKNOWN5 | 
		SET_UNKNOWN7 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS | 
		SET_UNKNOWN18,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		EQUIPMENT_STRUCT_DEFINITION_ID)
	{
		{ _field_struct, "item", &item_struct_definition },
		FIELD_CUSTOM("$$$ EQUIPMENT $$$", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 21 }, // BEEG UPGRADES MY BOIIIIII
		FIELD_CUSTOM("Timers", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_real, "duration", "use negative numbers for infinite duration", "seconds" },
		{ _field_real, "warmup time", "time before the equipment truly becomes active", "seconds" },
		{ _field_real, "cooldown time", "for equipment that suppresses combat actions, these actions remain suppressed for this long after the equipment deactivates\nNote that if this equipment also readies weapons when deactivated, the weapon will not be usable until both this timer expires and the ready animation has finished, whichever is longer", "seconds" },
		{ _field_real, "phantom volume activation time", "time in seconds for the phantom volumes on this object to start accelerating things in them" },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		FIELD_CUSTOM("Energy", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		FIELD_EXPLANATION("Energy", nullptr, FIELD_FLAG_NONE, "All these fields are additive, meaning a negative number will reduce energy and a positive one will increase energy.  Every piece of equipment starts at 1.0 energy"),
		{ _field_legacy, _field_real, "energy recovery time" },
		{ _field_real, "minimum activation energy", "energy must be at least this high to activate\nLike activation cost, but doesn't actually change energy levels" },
		{ _field_real, "activation energy cost" },
		{ _field_real, "deactivation energy cost" },
		{ _field_real, "active energy rate", nullptr, "energy/second" },
		{ _field_legacy, _field_real, "recharge rate" },
		{ _field_struct, "movement speed to energy rate", nullptr, "1/s", &scalar_function_named_struct },
		{ _field_real, "movement speed domain", nullptr, "wu/s" },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		{ _field_long_flags, "flags", &equipment_activation_flags },
		{ _field_short_integer, "charges", "-1 means unlimited charges" },
		{ _field_char_enum, "activation mode", FIELD_FLAG_INDEX, &equipment_activation_mode },
		{ _field_char_integer, "object noise adjustment", "for AI perception.\nwhile active, adjusts noises made by the owner unit by this many 'notches'.\nnote that this is additive, so a positive number is louder and a negative number is quieter" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 6 },
		FIELD_CUSTOM("Energy", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_real, "initial energy" },
		{ _field_real, "energy recovery time", "after deactivation, energy stays constant for this long before starting to change by 'inactive energy rate'", "seconds" },
		{ _field_real, "inactive energy rate", nullptr, "energy/second" },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		{ _field_long_flags, "flags", &equipment_flags },

		{ _field_string_id, "unit stow marker name", "the marker on the unit to attach this equipment to when it is stowed.\nThe equipment should have a marker named \"equipment_stow_anchor\"" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_char_enum, "pickup behavior", &equipment_pickup_behavior },
		FIELD_PAD("IJKMOP", nullptr, FIELD_FLAG_NONE, 3),

		{ _field_real_argb_color, "forced primary change color", "sets the primary change color on the unit to this if the flag above is checked" },
		{ _field_real_argb_color, "forced secondary change color", "sets the secondary change color on the unit to this if the flag above is checked" },
		FIELD_CUSTOM("AI", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		FIELD_EXPLANATION("AI", nullptr, FIELD_FLAG_NONE, "Settings which the AI use to know how they should react to this equipment"),
		{ _field_real, "danger radius", "How large a danger zone we should create around this equipment (0 means no danger zone)" },
		{ _field_real, "min deployment distance", "How far does my target have to be for me to throw this at them?", "wus" },
		{ _field_real, "awareness time", "How long I should go unnoticed by nearby enemies", "seconds" },
		{ _field_string_id, "ai dialogue equipment type", "The equipment ability type name used by the ai dialog system used to filter equipment activation dialogue events." },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		{ _field_block, "override camera", &optionalUnitCameraBlock_block },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_struct, "abilities", &equipmentAbilityDatum_block_struct_definition },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_block, "abilities", &equipmentAbilityDatum_block },

		{ _field_char_enum, "damage reporting type", &global_damage_reporting_enum_definition },
		FIELD_PAD("LKSHFDIJ", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_tag_reference, "hud screen reference", &Tag::Reference<struct CuiScreenDefinition>::s_defaultDefinition },
		{ _field_tag_reference, "pickup sound", &global_sound_reference },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 4 },
		{ _field_legacy, _field_tag_reference, "activation while disabled by player traits sound", &global_sound_reference },
		{ _field_legacy, _field_tag_reference, "activate effect", &global_effect_reference },
		{ _field_legacy, _field_tag_reference, "looping effect", &global_effect_reference },
		{ _field_legacy, _field_tag_reference, "deactivate effect", &global_effect_reference },

		{ _field_tag_reference, "energy charged effect", &global_effect_reference },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 4 },
		{ _field_legacy, _field_string_id, "activation animation" },
		{ _field_legacy, _field_string_id, "active animation" },
		{ _field_legacy, _field_string_id, "deactivate animation" },
		{ _field_legacy, _field_string_id, "active animation stance" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 4 },
		{ _field_tag_reference, "unable to activate sound", &global_sound_reference },
		{ _field_tag_reference, "Player sound bank", "High quality player sound bank to be prefetched. Can be empty.", &global_soundbank_reference },
		{ _field_block, "Sound RTPCs", &EquipmentSoundRTPCBlock_block },
		{ _field_block, "Sound Sweeteners", &EquipmentSoundSweetenerBlock_block },

		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		{ _field_terminator }
	};

	STRINGS(multiplayer_powerup_flavor)
	{
		"red powerup",
		"blue powerup",
		"yellow powerup",
		"custom powerup"
	};
	STRING_LIST(multiplayer_powerup_flavor, multiplayer_powerup_flavor_strings, _countof(multiplayer_powerup_flavor_strings));

	STRINGS(equipment_spawner_spawn_type)
	{
		"along aiming vector",
		"camera pos z plane",
		"foot pos z plane"
	};
	STRING_LIST(equipment_spawner_spawn_type, equipment_spawner_spawn_type_strings, _countof(equipment_spawner_spawn_type_strings));

	STRINGS(equipmentAbilityType_MotionTrackerNoise_flags)
	{
		"affects self",
		"affects friendlies"
	};
	STRING_LIST(equipmentAbilityType_MotionTrackerNoise_flags, equipmentAbilityType_MotionTrackerNoise_flags_strings, _countof(equipmentAbilityType_MotionTrackerNoise_flags_strings));

	STRINGS(equipmentAbilityType_treeoflife_flags)
	{
		"un-stuns shileds",
		"un-stuns body"
	};
	STRING_LIST(equipmentAbilityType_treeoflife_flags, equipmentAbilityType_treeoflife_flags_strings, _countof(equipmentAbilityType_treeoflife_flags_strings));

	STRINGS(repulsor_field_flags)
	{
		"affects projectiles",
		"affects vehicles",
		"affects bipeds"
	};
	STRING_LIST(repulsor_field_flags, repulsor_field_flags_strings, _countof(repulsor_field_flags_strings));

	STRINGS(equipmentAbilityTypeDaddyVisibleFlags)
	{
		"inactive unstowed",
		"inactive stowed",
		"active unstowed",
		"active stowed",
		"warming up unstowed",
		"warming up stowed",
		"cooling down unstowed",
		"cooling down stowed",
		"shield vitality tied to energy#as energy goes down, the shield vitality will as well"
	};
	STRING_LIST(equipmentAbilityTypeDaddyVisibleFlags, equipmentAbilityTypeDaddyVisibleFlags_strings, _countof(equipmentAbilityTypeDaddyVisibleFlags_strings));

	STRINGS(equipmentAbilityTypeJetPackFlags)
	{
		"Use camera and movement for thrust dir#Jetpack thrust dir is controlled by camera dir and player movement (signifies Zero-G jet pack)",
		"Cache thrust at activation#don\'t let the player change the direction of thrust once they activate"
	};
	STRING_LIST(equipmentAbilityTypeJetPackFlags, equipmentAbilityTypeJetPackFlags_strings, _countof(equipmentAbilityTypeJetPackFlags_strings));

	STRINGS(equipmentAbilityTypeHologramFlags)
	{
		"driveable#hologram is automatically bump possessed by the player"
	};
	STRING_LIST(equipmentAbilityTypeHologramFlags, equipmentAbilityTypeHologramFlags_strings, _countof(equipmentAbilityTypeHologramFlags_strings));

	STRINGS(equipment_auto_turret_flags)
	{
		"turret follows player#if set, turret follows player, otherwise it moves to a specific location",
		"turret fake gravity#if set, turret will sink to a height defined in y orbit offset below"
	};
	STRING_LIST(equipment_auto_turret_flags, equipment_auto_turret_flags_strings, _countof(equipment_auto_turret_flags_strings));

	STRINGS(equipment_remote_strike_flags)
	{
		"ordnance ui#special version of RS use for ordnance droppod UI",
		"target designator#target designator is in weapon field"
	};
	STRING_LIST(equipment_remote_strike_flags, equipment_remote_strike_flags_strings, _countof(equipment_remote_strike_flags_strings));

	STRINGS(EquipmentSpecialMoveDefaultDirectionDefinition)
	{
		"none",
		"forward",
		"left",
		"backward",
		"right"
	};
	STRING_LIST(EquipmentSpecialMoveDefaultDirectionDefinition, EquipmentSpecialMoveDefaultDirectionDefinition_strings, _countof(EquipmentSpecialMoveDefaultDirectionDefinition_strings));

	STRINGS(equipment_engineer_shields_flags)
	{
		"gives shields to owner"
	};
	STRING_LIST(equipment_engineer_shields_flags, equipment_engineer_shields_flags_strings, _countof(equipment_engineer_shields_flags_strings));

	STRINGS(activeShieldFlags)
	{
		"Pause shield stun timer#false forces full amount of stun following deactivation"
	};
	STRING_LIST(activeShieldFlags, activeShieldFlags_strings, _countof(activeShieldFlags_strings));

	STRINGS(teleporterFlags)
	{
		"hide unit during transit#during the teleport, hide the unit and turn off collision",
		"disable shortened teleport#makes it so that we always thrust or teleport the full distance; not wise unless \"hide unit during transit\" is unchecked",
		"disable extra probes#only the center probe is cast, no extra probes",
		"force along aim vector#ignores all search vector parameters and uses the aim vector as the search vector",
		"can pass through objects#only collides against environment and structures",
		"force along stick direction#if stick throw magnitude==0 then search in facing direction, else search in stick direction"
	};
	STRING_LIST(teleporterFlags, teleporterFlags_strings, _countof(teleporterFlags_strings));

	STRINGS(equipmentVisionModeFlags)
	{
		"Apply tell damage response to friends",
		"Generate tell motion sensor blip"
	};
	STRING_LIST(equipmentVisionModeFlags, equipmentVisionModeFlags_strings, _countof(equipmentVisionModeFlags_strings));

	STRINGS(equipmentHackerFlags)
	{
		"Disable friendly fire"
	};
	STRING_LIST(equipmentHackerFlags, equipmentHackerFlags_strings, _countof(equipmentHackerFlags_strings));

	STRINGS(equipment_flags)
	{
		"pathfinding obstacle",
		"equipment is dangerous to ai",
		"never dropped by ai#if an actor dies while carrying this, it gets deleted immediately\ndoes not affect dropping by players",
		"protects parent from AOE",
		"3rd person camera always",
		"use forced primary change color",
		"use forced secondary change color",
		"can not be picked up by player",
		"is removed from world on deactivation#used with supercombine attach",
		"is dropped by player",
		"is dropped by ai"
	};
	STRING_LIST(equipment_flags, equipment_flags_strings, _countof(equipment_flags_strings));

	STRINGS(equipment_activation_flags)
	{
		"3rd person camera while active",
		"3rd person camera during activation animation",
		"hide reticule while active",
		"cannot be active while airborne#if checked, this equipment cannot be activated if the user is airborne, and deactivates itself if the user becomes airborne",
		"cannot activate while airborne#can\'t activate in midair, but doesn\'t turn off if you later become airborne",
		"cannot activate while standing on biped#if you are standing on another biped you can not use this equipment",
		"cannot be active in vehicle#can\'t be activated in a seat, and deactivates if a vehicle is entered",
		"cannot be active while motion is modified by physics#e.g. by mancannon",
		"suppresses weapons while active",
		"suppresses melee while active",
		"suppresses grenades while active",
		"suppresses device interaction while active",
		"suppresses hero-assist-equipment use while active#probably this means sprint",
		"suppresses entering vehicle",
		"activation anim suppresses weapons and melee",
		"duck sound while active",
		"blocks tracking while active",
		"readies weapon on deactivation#note - if this equipment has an animation cycle, the weapon is readied after the exit animation finishes.  Otherwise the weapon-ready happens immediately on deactivation",
		"drops support/must_be_readied weapons on activation",
		"hides weapon on activation#checking this flag will automatically cause the weapon to ready on deactivation",
		"Cannot activate in vehicle#cannot activate while in vehicle, but previously activated equipment remains active",
		"deactivated by firing weapon",
		"deactivated by reloading weapon",
		"deactivated by switching weapon",
		"deactivated by throwing grenade",
		"deactivated by grenade anim",
		"deactivated by melee attacking",
		"suppresses weapon zoom while active",
		"ignore auto-pick-up weapons while active#Prevents auto-pick-up of weapons set to auto by megalo action weapon_set_picup_priority",
		"cannot crouch while active",
		"activation interrupts melee",
		"activation interrupts grenades"
	};
	STRING_LIST(equipment_activation_flags, equipment_activation_flags_strings, _countof(equipment_activation_flags_strings));

	STRINGS(equipmentActivationSecondaryFlags)
	{
		"suppresses weapon zoom during activation animation#the equipment only suppresses zoom during its activation animation",
		"suppresses jumping while active",
		"suppresses toggle deactivation while active",
		"suppresses jumping during activation animation#only suppresses jumping during its activation animation",
		"suppresses vehicle entry during activation animation#only suppresses vehicle entry during its activation animation",
		"suppresses grenade usage during activation animation#only suppresses grenade usage during its activation animation",
		"Hide reticule during activation animation",
		"Hide reticule during during weapon ready",
		"Deactivating during warmup will apply deactivation energy penalty",
		"Deactivating during warmup will fire deactivation effects",
		"Apply player traits during warmup",
		"Apply player traits during cooldown",
		"Hero Assist ability",
		"Ignores normal support weapon force deactivation of equipment#used by Auto Turret to bypass how support weapons force equipment deactivation"
	};
	STRING_LIST(equipmentActivationSecondaryFlags, equipmentActivationSecondaryFlags_strings, _countof(equipmentActivationSecondaryFlags_strings));

	STRINGS(equipment_activation_mode)
	{
		"toggle#toggles state when X is pressed",
		"hold#activates when X is pressed and deactivates when X is released",
		"double tap#activates when X is pressed twice in quick succession",
		"shield fail#activates when player shield fails",
		"death#activates when player dies"
	};
	STRING_LIST(equipment_activation_mode, equipment_activation_mode_strings, _countof(equipment_activation_mode_strings));

	STRINGS(equipment_pickup_behavior)
	{
		"automatic if empty#picks it up automatically, if you have no equipment in your inventory, otherwise, press RB to swap",
		"always automatic#always picks it up, whether or not you have another piece of equipment",
		"manual#press RB to pickup or swap this equipment",
		"activate on ground#Never pickup, press RB to activate it in-place"
	};
	STRING_LIST(equipment_pickup_behavior, equipment_pickup_behavior_strings, _countof(equipment_pickup_behavior_strings));

	TAG_REFERENCE(global_equipment_reference, EQUIPMENT_TAG);

} // namespace macaque

} // namespace blofeld

