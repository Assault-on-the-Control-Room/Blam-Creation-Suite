#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		SpawnSettings_group,
		SPAWNSETTINGS_TAG,
		nullptr,
		INVALID_TAG,
		SpawnSettings_block );

	TAG_BLOCK_FROM_STRUCT(
		SpawnSettings_block,
		"SpawnSettings_block",
		1,
		SpawnSettings_struct_definition);

	#define INFLUENCERSPAWNSETTINGSBLOCK_ID { 0x757BE24D, 0xC5C540AA, 0x961D9850, 0x49F6D4AC }
	TAG_BLOCK(
		influencerSpawnSettingsBlock_block,
		"influencerSpawnSettingsBlock",
		k_spawn_influencer_type_count,
		"InfluencerSpawnSettings",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		INFLUENCERSPAWNSETTINGSBLOCK_ID)
	{
		{ _field_long_flags, "Flags", &InfluencerSpawnSettingsFlagsDefinition },
		{ _field_real, "Minimum Influence", nullptr, "Only used if 'Pin' flag is set" },
		{ _field_real, "Maximum Influence", nullptr, "Only used if 'Pin' flag is set" },
		{ _field_terminator }
	};

	#define WEAPONSPAWNINFLUENCEBLOCK_ID { 0x87D4A845, 0x10704864, 0x96A1F457, 0x58B8ED50 }
	TAG_BLOCK(
		weaponSpawnInfluenceBlock_block,
		"weaponSpawnInfluenceBlock",
		48,
		"WeaponSpawnInfluence",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		WEAPONSPAWNINFLUENCEBLOCK_ID)
	{
		{ _field_tag_reference, "weapon", &weapon_reference$9 },
		{ _field_real, "full weight range", nullptr, "wu" },
		{ _field_real, "fall-off range", nullptr, "wu" },
		{ _field_real, "fall-off cone radius", nullptr, "wu" },
		{ _field_real, "weight" },
		{ _field_terminator }
	};

	#define VEHICLESPAWNINFLUENCEBLOCK_ID { 0x64AE7B1C, 0x32A64906, 0x892A75B8, 0xEBC0BE95 }
	TAG_BLOCK(
		vehicleSpawnInfluenceBlock_block,
		"vehicleSpawnInfluenceBlock",
		k_vehicle_spawn_influencer_maximum_count,
		"VehicleSpawnInfluence",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		VEHICLESPAWNINFLUENCEBLOCK_ID)
	{
		{ _field_tag_reference, "vehicle", &vehicle_reference$4 },
		{ _field_real, "box width", nullptr, "wu" },
		{ _field_real, "box min height", "How far influencer will extend below unit's origin.  Will usually be negative.  (If min and max are both 0, unit radius is used)", "wu" },
		{ _field_real, "box max height", "How far influencer will extend above unit's origin.  Will usually be positive.  (If min and max are both 0, unit radius is used)", "wu" },
		{ _field_real, "lead time", nullptr, "seconds" },
		{ _field_real, "minimum velocity", nullptr, "wu/sec" },
		{ _field_real, "weight" },
		{ _field_terminator }
	};

	#define PROJECTILESPAWNINFLUENCEBLOCK_ID { 0x6E14464D, 0x2EB94C80, 0xA81C3654, 0xB772B549 }
	TAG_BLOCK(
		projectileSpawnInfluenceBlock_block,
		"projectileSpawnInfluenceBlock",
		k_projectile_spawn_influencer_maximum_count,
		"ProjectileSpawnInfluence",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PROJECTILESPAWNINFLUENCEBLOCK_ID)
	{
		{ _field_tag_reference, "projectile", &projectile_reference$3 },
		{ _field_real, "lead time", nullptr, "seconds" },
		{ _field_real, "collision cylinder radius", nullptr, "wu" },
		{ _field_real, "weight" },
		{ _field_terminator }
	};

	#define EQUIPMENTSPAWNINFLUENCEBLOCK_ID { 0x2642BDE4, 0x300F4A33, 0x8ABD12F8, 0x1B904F85 }
	TAG_BLOCK(
		equipmentSpawnInfluenceBlock_block,
		"equipmentSpawnInfluenceBlock",
		k_equipment_spawn_influencer_maximum_count,
		"EquipmentSpawnInfluence",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		EQUIPMENTSPAWNINFLUENCEBLOCK_ID)
	{
		{ _field_tag_reference, "equipment", &equipment_reference$5 },
		{ _field_real, "weight" },
		{ _field_terminator }
	};

	#define SPAWNSETTINGS_STRUCT_DEFINITION_ID { 0xD4FD6AF4, 0xF1D44565, 0xB4FF38A0, 0xC43A50F8 }
	TAG_STRUCT(
		SpawnSettings_struct_definition,
		"SpawnSettings_struct_definition",
		"SpawnSettingsTagGroup",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SPAWNSETTINGS_STRUCT_DEFINITION_ID)
	{
		{ _field_real, "minimum spawn time", "Absolute floor.  Used to put a few-frame delay between death and instaspawn.  Will not override longer minimum times.", "seconds" },
		{ _field_real, "min acceptable spawn score", "spawns with a score lower than this will never be used" },
		FIELD_EXPLANATION("Spawn Randomization", nullptr, FIELD_FLAG_NONE, "Values that affect randomization of respawn point selection\nRuntime will use the largest of \'% best weight to use\' and \'Min absolute weight range\'"),
		{ _field_real, "maximum random spawn bias", "Controls how large of a random value gets added to each spawn point", "0 disables" },
		{ _field_real_fraction, "% num spawn points to use", "Example -\nOn a map with 140 respawn points, a value of 0.1 here\nwill choose randomly between up to the best 14 points.\nNumber of points considered is also limited by the following parameters and flags.\nIf next two parameters are 0, only points with the exact same weight as the highest\nscoring respawn point will be considered.  If 'Min absolute weight range' is 25 then\nthe best 'X' points within 25 points of the highest scoring point will be considered.", "0 uses only best point" },
		{ _field_real_fraction, "% best weight to use", "Example -\nValue of 0.25 will consider all points with weight within 25% of the highest scoring point.\nNote - At run-time, the larger of '% best weight to use' and 'Min absolute weight range' will be used.\nFor instance if '% best weight' is 0.1 and 'Min absolute weight' is 5.0' a max weight\nof 150 will use 15, but a max weight of 10 will fall back on the min weight of 5", "0 disables" },
		{ _field_real, "Min absolute weight range", "Example -\nValue of 50 will consider all points within 50 of the highest scoring point.\nNote - At run-time, the larger of '% best weight to use' and 'Min absolute weight range' will be used.\n", "0 disables" },
		{ _field_long_flags, "Flags", &SpawnSettingsFlagsDefinition },
		FIELD_EXPLANATION("Spawn Settings", nullptr, FIELD_FLAG_NONE, "block index 0: influencer - Enemy Forbid\nblock index 1: influencer - Enemy Bias\nblock index 2: influencer - Ally Bias\nblock index 3: influencer - Selected Ally Bias\nblock index 4: influencer - Dead Teammate\nblock index 5: influencer - Respawn Zone\nblock index 6: influencer - Weapon\nblock index 7: influencer - Vehicle\nblock index 8: influencer - Projectile\nblock index 9: influencer - Equipment\nblock index 10: influencer - Fireteam 1 zone\nblock index 11: influencer - Fireteam 2 zone\nblock index 12: influencer - Fireteam 3 zone\nblock index 13: influencer - Fireteam 4 zone\nblock index 14: influencer - Drop Pod\nblock index 15: influencer - Auto Turret\n"),
		{ _field_block, "Spawn Settings", &influencerSpawnSettingsBlock_block },
		FIELD_EXPLANATION("ENEMY FORBID", nullptr, FIELD_FLAG_NONE, "This is a tight cylinder around the player with a strong negative weight. It serves to protect players from spawning close to an enemy, or having and enemy spawn close to them."),
		{ _field_real, "ef full weight radius", nullptr, "wu" },
		{ _field_real, "ef fall-off radius", nullptr, "wu" },
		{ _field_block, "ef falloff function", "Multiplier applied to weight (domain is full weight radius to fall-off radius, range should be 0 to 1).", &spawn_influence_weight_falloff_function_block },
		{ _field_real, "ef upper height", nullptr, "wu" },
		{ _field_real, "ef lower height", nullptr, "wu" },
		{ _field_real, "ef weight" },
		FIELD_EXPLANATION("ENEMY BIAS", nullptr, FIELD_FLAG_NONE, "This is a larger cylinder, with a size set specifically for the size of the map. It has a weak negative weight which falls to zero towards the outer radius. It serves to bias players away from spawning near enemies, or in enemy held areas."),
		{ _field_real, "eb full weight radius", nullptr, "wu" },
		{ _field_real, "eb fall-off radius", nullptr, "wu" },
		{ _field_block, "eb falloff function", "Multiplier applied to weight (domain is full weight radius to fall-off radius, range should be 0 to 1).", &spawn_influence_weight_falloff_function_block },
		{ _field_real, "eb upper height", nullptr, "wu" },
		{ _field_real, "eb lower height", nullptr, "wu" },
		{ _field_real, "eb weight" },
		FIELD_EXPLANATION("ALLY BIAS", nullptr, FIELD_FLAG_NONE, "This is a larger cylinder, with a size set specifically for the size of the map. It has a weak positive weight which falls to zero towards the outer radius. It serves to bias players towards spawning with allies, or in areas which are controlled by friendly players."),
		{ _field_real, "ab full weight radius", nullptr, "wu" },
		{ _field_real, "ab fall-off radius", nullptr, "wu" },
		{ _field_block, "ab falloff function", "Multiplier applied to weight (domain is full weight radius to fall-off radius, range should be 0 to 1).", &spawn_influence_weight_falloff_function_block },
		{ _field_real, "ab upper height", nullptr, "wu" },
		{ _field_real, "ab lower height", nullptr, "wu" },
		{ _field_real, "ab weight" },
		FIELD_EXPLANATION("SELECTED ALLY BIAS", nullptr, FIELD_FLAG_NONE, "Same as ALLY BIAS, but used when the ally is selected in the dead-camera."),
		{ _field_real, "sab full weight radius", nullptr, "wu" },
		{ _field_real, "sab fall-off radius", nullptr, "wu" },
		{ _field_block, "sab falloff function", "Multiplier applied to weight (domain is full weight radius to fall-off radius, range should be 0 to 1).", &spawn_influence_weight_falloff_function_block },
		{ _field_real, "sab upper height", nullptr, "wu" },
		{ _field_real, "sab lower height", nullptr, "wu" },
		{ _field_real, "sab weight" },
		FIELD_EXPLANATION("DEAD TEAMMATE BIAS", nullptr, FIELD_FLAG_NONE, "Dead teammate influences are cylinders centered upon the body of a dead teammate (or the player’s own dead body)."),
		{ _field_real, "dt full weight radius", nullptr, "wu" },
		{ _field_real, "dt fall-off radius", nullptr, "wu" },
		{ _field_block, "dt falloff function", "Multiplier applied to weight (domain is full weight radius to fall-off radius, range should be 0 to 1).", &spawn_influence_weight_falloff_function_block },
		{ _field_real, "dt upper height", nullptr, "wu" },
		{ _field_real, "dt lower height", nullptr, "wu" },
		{ _field_real, "dt weight" },
		{ _field_real, "dead teammate influence duration", nullptr, "seconds" },

		{ _field_legacy, _field_version_less, _engine_type_groundhog, 7 },
		FIELD_EXPLANATION("DROP POD BIAS", nullptr, FIELD_FLAG_NONE, "Drop pods influences are cylinders centered on unclaimed ordnance."),
		{ _field_real, "Drop Pod full weight radius", nullptr, "wu" },
		{ _field_real, "Drop Pod fall-off radius", nullptr, "wu" },
		{ _field_block, "Drop Pod falloff function", "Multiplier applied to weight (domain is full weight radius to fall-off radius, range should be 0 to 1).", &spawn_influence_weight_falloff_function_block },
		{ _field_real, "Drop Pod upper height", nullptr, "wu" },
		{ _field_real, "Drop Pod lower height", nullptr, "wu" },
		{ _field_real, "Drop Pod weight" },

		{ _field_legacy, _field_version_less, _engine_type_groundhog, 7 },
		FIELD_EXPLANATION("PLAYER AUTO TURRET BIAS", nullptr, FIELD_FLAG_NONE, "Auto Turret influences are cylinders centered on players\' auto turrets."),
		{ _field_real, "Auto Turret full weight radius", nullptr, "wu" },
		{ _field_real, "Auto Turret fall-off radius", nullptr, "wu" },
		{ _field_block, "Auto Turret falloff function", "Multiplier applied to weight (domain is full weight radius to fall-off radius, range should be 0 to 1).", &spawn_influence_weight_falloff_function_block },
		{ _field_real, "Auto Turret upper height", nullptr, "wu" },
		{ _field_real, "Auto Turret lower height", nullptr, "wu" },
		{ _field_real, "Auto Turret weight" },

		{ _field_legacy, _field_version_equal, _engine_type_groundhog, 8 },
		{ _field_legacy, _field_explanation, "UNKNOWN BIAS" },
		{ _field_legacy, _field_real, "@unknown full weight radius:wu" },
		{ _field_legacy, _field_real, "@unknown fall-off radius:wu" },
		{ _field_legacy, _field_block, "@unknown falloff function#Multiplier applied to weight (domain is full weight radius to fall-off radius, range should be 0 to 1).", &spawn_influence_weight_falloff_function_block_block },
		{ _field_legacy, _field_real, "@unknown upper height:wu" },
		{ _field_legacy, _field_real, "@unknown lower height:wu" },
		{ _field_legacy, _field_real, "@unknown weight" },
		{ _field_legacy, _field_real, "@unknown" },

		FIELD_EXPLANATION("WEAPON INFLUENCERS", nullptr, FIELD_FLAG_NONE, "These influencers are induced by weapons either weilded or carried in the player\'s backpack"),
		{ _field_block, "weapon influencers", &weaponSpawnInfluenceBlock_block },
		FIELD_EXPLANATION("VEHICLE INFLUENCERS", nullptr, FIELD_FLAG_NONE, "These influencers are induced by vehicles."),
		{ _field_block, "vehicle influencers", &vehicleSpawnInfluenceBlock_block },
		FIELD_EXPLANATION("PROJECTILE INFLUENCERS", nullptr, FIELD_FLAG_NONE, "These influencers are induced by projectiles."),
		{ _field_block, "projectile influencers", &projectileSpawnInfluenceBlock_block },
		FIELD_EXPLANATION("EQUIPMENT INFLUENCERS", nullptr, FIELD_FLAG_NONE, "These influencers are induced by equipment."),
		{ _field_block, "equipment influencers", &equipmentSpawnInfluenceBlock_block },
		{ _field_terminator }
	};

	STRINGS(InfluencerSpawnSettingsFlagsDefinition)
	{
		"Only use largest influence",
		"Pin influence to Minimum and Maximum"
	};
	STRING_LIST(InfluencerSpawnSettingsFlagsDefinition, InfluencerSpawnSettingsFlagsDefinition_strings, _countof(InfluencerSpawnSettingsFlagsDefinition_strings));

	STRINGS(SpawnSettingsFlagsDefinition)
	{
		"Allow negative weights in randomization#If checked, negative weighted respawn points are treated the same as ones with positive weight.\nIf not checked, negative respawn points aren\'t grouped with positive weighted respawn points."
	};
	STRING_LIST(SpawnSettingsFlagsDefinition, SpawnSettingsFlagsDefinition_strings, _countof(SpawnSettingsFlagsDefinition_strings));

	TAG_REFERENCE(g_spawnSettingsReference, SPAWNSETTINGS_TAG);

} // namespace macaque

} // namespace blofeld

