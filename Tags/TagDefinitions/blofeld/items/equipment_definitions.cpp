#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_GROUP_INHERIT_FROM_BLOCK(equipment, EQUIPMENT_TAG, item, ITEM_TAG, equipment_block_block );

	V5_TAG_BLOCK(optionalUnitCameraBlock, 1)
	{
		{ _field_legacy, _field_struct, "unit camera", &unit_camera_struct_struct_definition },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(equipmentAbilityTypeMultiplayerPowerupBlock, 1)
	{
		{ _field_legacy, _field_long_enum, "flavor", &multiplayer_powerup_flavor },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(equipmentAbilityTypeSpawnerBlock, 1)
	{
		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 2},
		{ _field_legacy, _field_tag_reference, "spawned object", &object_reference$4 },
		{ _field_legacy, _field_tag_reference, "spawned effect", &global_effect_reference },

		{ _field_legacy, _field_real, "spawn radius#distance from players eyeball on the z-plane that this effect spawns" },
		{ _field_legacy, _field_real, "spawn z offset#z-offset of effect spawn" },
		{ _field_legacy, _field_real, "spawn area radius#need a sphere of radius r\'s free space in order to spawn, otherwise we pick a new spawn location" },
		{ _field_legacy, _field_real, "spawn velocity#WU/sec" },
		{ _field_legacy, _field_enum, "type", &equipment_spawner_spawn_type },
		{ _field_legacy, _field_pad, "LSJ", 2 },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_legacy, _field_tag_reference, "spawned object", &object_reference$4 },
		{ _field_legacy, _field_tag_reference, "spawned effect", &global_effect_reference },

		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(equipmentAbilityTypeAiSpawnerBlock, 1)
	{
		{ _field_legacy, _field_real, "spawn radius#distance from players eyeball on the z-plane that this effect spawns" },
		{ _field_legacy, _field_real, "spawn z offset#z-offset of effect spawn" },
		{ _field_legacy, _field_real, "spawn area radius#need a sphere of radius r\'s free space in order to spawn, otherwise we pick a new spawn location" },
		{ _field_legacy, _field_real, "spawn velocity#WU/sec" },
		{ _field_legacy, _field_enum, "type", &equipment_spawner_spawn_type },
		{ _field_legacy, _field_pad, "RFD", 2 },
		{ _field_legacy, _field_tag_reference, "spawned character", &character_reference$4 },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(equipmentAbilityTypeProximityMineBlock, 1)
	{
		{ _field_legacy, _field_tag_reference, "explosion effect", &global_effect_reference },
		{ _field_legacy, _field_tag_reference, "explosion damage effect", &global_damage_reference },
		{ _field_legacy, _field_real, "arm time#time before it becomes a proximity mine" },
		{ _field_legacy, _field_real, "self destruct time#seconds after it is created that it must self destruct.  0 means never destroy" },
		{ _field_legacy, _field_real, "trigger time#seconds object moving at trigger velocity takes to trigger explosion.  This will smooth out sensitivity to velocity noise" },
		{ _field_legacy, _field_real, "trigger velocity#WU/sec at which we trigger explosion" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(equipmentAbilityTypeMotionTrackerNoiseBlock, 1)
	{
		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_legacy, _field_long_flags, "flags", &equipmentAbilityType_MotionTrackerNoise_flags },

		{ _field_legacy, _field_real, "arm time#time before it starts making noise" },
		{ _field_legacy, _field_real, "noise radius#radius in WU that the noise extends to." },
		{ _field_legacy, _field_long_integer, "noise count#number of noise points that are generated" },
		{ _field_legacy, _field_real, "flash radius#radius in WU that the damage flash noise extends to." },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(equipmentEffectWithThresholdBlock, 10)
	{
		{ _field_legacy, _field_real, "threshold energy burned^:0-1#how much energy you have to burn to play this effect" },
		{ _field_legacy, _field_real, "energy adjustment:-1 to 1#how much energy to add when playing this effect" },
		{ _field_legacy, _field_tag_reference, "effect", &global_effect_reference },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(equipmentAbilityTypeInvincibilityBlock, 1)
	{
		{ _field_legacy, _field_string_id, "invincibility material" },
		{ _field_legacy, _field_short_integer, "invincibility material type*!" },
		{ _field_legacy, _field_pad, "invincibility material pad", 2 },
		{ _field_legacy, _field_real, "shield recharge rate:1.0f/s#while active, shields recharge at this fraction per second" },
		{ _field_legacy, _field_real, "shield max recharge level#highest level shield can recharge to (can be up to 4)" },
		{ _field_legacy, _field_tag_reference, "override collision damage", &collision_damage_reference$3 },
		{ _field_legacy, _field_tag_reference, "ai melee reflect damage", &damage_effect_reference$2 },
		{ _field_legacy, _field_tag_reference, "player melee reflect damage", &damage_effect_reference$2 },
		{ _field_legacy, _field_string_id, "loop-invincibility shield name#active while the equipment is in use (used for shield rendering effects)" },
		{ _field_legacy, _field_string_id, "post-invincibility shield name#active once the equipment is no longer in use" },
		{ _field_legacy, _field_struct, "post-invincibility time to shield level function", &scalar_function_named_struct_struct_definition },
		{ _field_legacy, _field_real, "maximum vertical velocity:WU/SEC#we use this to specify the domain of the active vertical velocity funtion" },
		{ _field_legacy, _field_struct, "active vertical velocity damping", &scalar_function_named_struct_struct_definition },
		{ _field_legacy, _field_block, "threshold effects#the effect with the highest threshold will play on deactivation", &equipmentEffectWithThresholdBlock_block },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(equipmentAbilityTypeTreeOfLifeBlock, 1)
	{
		{ _field_legacy, _field_long_flags, "flags", &equipmentAbilityType_treeoflife_flags },
		{ _field_legacy, _field_string_id, "origin marker" },
		{ _field_legacy, _field_real, "radius" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(equipmentAbilityTypeShapeshifterBlock, 1)
	{
		{ _field_legacy, _field_string_id, "region name" },
		{ _field_legacy, _field_string_id, "inactive permutation name" },
		{ _field_legacy, _field_string_id, "active permutation name" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(equipmentAbilityTypePlayerTraitFieldBlock, 1)
	{
		{ _field_legacy, _field_skip, "radius", 4 },
		{ _field_legacy, _field_block, "active player traits", &game_engine_player_traits_block_block },
		{ _field_legacy, _field_block, "inactive player traits", &game_engine_player_traits_block_block },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(aiEquipmentTraitAppearanceBlock, 1)
	{
		{ _field_legacy, _field_explanation, "Appearance Traits", "Traits that affect the AI\'s appearance" },
		{ _field_legacy, _field_char_enum, "active camo setting", &player_trait_active_camo },
		{ _field_legacy, _field_pad, "pad", 3 },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(aiEquipmentTraitsBlock, 1)
	{
		{ _field_legacy, _field_block, "appearance traits", &aiEquipmentTraitAppearanceBlock_block },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(equipmentAbilityTypeAiTraitFieldBlock, 1)
	{
		{ _field_legacy, _field_block, "active ai equipment traits", &aiEquipmentTraitsBlock_block },
		{ _field_legacy, _field_block, "inactive ai equipment traits", &aiEquipmentTraitsBlock_block },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(equipmentAbilityTypeRepulsorFieldBlock, 1)
	{
		{ _field_legacy, _field_long_flags, "flags", &repulsor_field_flags },
		{ _field_legacy, _field_real, "radius:wu" },
		{ _field_legacy, _field_real, "power" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(equipmentAbilityTypeStasisFieldBlock, 1)
	{
		{ _field_legacy, _field_long_flags, "flags", &repulsor_field_flags },
		{ _field_legacy, _field_real, "radius:wu" },
		{ _field_legacy, _field_custom, "Time Dilation Values" },
		{ _field_legacy, _field_explanation, "Time Dilation", "The effective rate at which time passes for objects in the field.  Values below 0.45 screw up jumping." },
		{ _field_legacy, _field_real, "time dilation player characters" },
		{ _field_legacy, _field_real, "time dilation projectiles" },
		{ _field_legacy, _field_real, "time dilation vehicles" },
		{ _field_legacy, _field_real, "time dilation other#everything else" },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_real, "max biped turning rate:no idea what units... something like .2 or so" },
		{ _field_legacy, _field_real, "gravity multiplier#negative values will invert gravity" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(equipmentAbilityTypeBallLightningBlock, 1)
	{
		{ _field_legacy, _field_long_flags, "flags", &repulsor_field_flags },
		{ _field_legacy, _field_real, "start radius:wu" },
		{ _field_legacy, _field_explanation, "Ball Lightning", "Damage effect that passes from one biped to nearby bipeds, recursively" },
		{ _field_legacy, _field_real, "chain radius reduction multiplier^:[0.01, 1]#MUST BE GREATER THAN ZERO - each time lightning chains, this is the multiplier that controls how much the radius is reduced by" },
		{ _field_legacy, _field_real, "chain delay timer:seconds" },
		{ _field_legacy, _field_tag_reference, "lightning damage", &global_damage_reference },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(equipmentAbilityTypeDaddyBlock, 1)
	{
		{ _field_legacy, _field_tag_reference, "child object", &object_reference$4 },
		{ _field_legacy, _field_word_flags, "flags", &equipmentAbilityTypeDaddyVisibleFlags },
		{ _field_legacy, _field_pad, "dada", 2 },
		{ _field_legacy, _field_real, "shield damage to energy scale#scale factor for energy gain from shield damage to child.\nDamage is normalized, so if this value is -1.0 then the equipment will lose all its energy when its child\'s shield is depleted." },
		{ _field_legacy, _field_real, "starting warm up object scale#if >0 (and warm up time is >0), object size will scale up from this up to 1.0 over course of warm up time and down over cooldown time" },
		{ _field_legacy, _field_real_point_3d, "offset from parent#the root of the child is offset by this amount from the root of the parent biped" },
		{ _field_legacy, _field_real, "vertical offset in world space#used to adjust hight per biped, regardless of aim direction" },
		{ _field_legacy, _field_real_bounds, "min and max pitch:degrees#the min and max pitch that the child will follow as you aim up and down.  -90 to 90" },
		{ _field_legacy, _field_real, "visual activation time:seconds" },
		{ _field_legacy, _field_tag_reference, "spawn effect", &global_effect_reference },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_string_id, "spawn effect marker" },
		{ _field_legacy, _field_tag_reference, "despawn effect", &global_effect_reference },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_string_id, "despawn effect marker" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(equipmentAbilityTypeLaserDesignationBlock, 1)
	{
		{ _field_legacy, _field_real, "unused!" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(equipmentAbilityTypeSuperJumpBlock, 1)
	{
		{ _field_legacy, _field_struct, "energy to jump", &scalar_function_named_struct_struct_definition },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(equipmentAbilityTypeAmmoPackBlock, 1)
	{
		{ _field_legacy, _field_real, "energy change per clip added" },
		{ _field_legacy, _field_long_integer, "extra frags" },
		{ _field_legacy, _field_long_integer, "extra plasma" },
		{ _field_legacy, _field_long_integer, "extra grenade 3" },
		{ _field_legacy, _field_long_integer, "extra grenade 4" },
		{ _field_legacy, _field_long_integer, "extra grenade 5" },
		{ _field_legacy, _field_long_integer, "extra grenade 6" },
		{ _field_legacy, _field_long_integer, "extra grenade 7" },
		{ _field_legacy, _field_long_integer, "extra grenade 8" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(equipmentAbilityTypePowerFistBlock, 1)
	{
		{ _field_legacy, _field_tag_reference, "melee damage", &global_damage_reference },
		{ _field_legacy, _field_tag_reference, "melee response", &global_damage_effect_or_response_definition_reference },
		{ _field_legacy, _field_tag_reference, "clang damage", &global_damage_reference },
		{ _field_legacy, _field_tag_reference, "clang response", &global_damage_effect_or_response_definition_reference },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(equipmentAbilityTypeHealthPackBlock, 1)
	{
		{ _field_legacy, _field_struct, "health given over energy used", &scalar_function_named_struct_struct_definition },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(equipmentAbilityPartCowCatcherBlock, 1)
	{
		{ _field_legacy, _field_real, "cow catcher height#world units" },
		{ _field_legacy, _field_real, "cow catcher front width#world units, the width of the flat front portion of the cow-catcher" },
		{ _field_legacy, _field_real, "cow catcher side width#world units, the width of the angled side portion of the cow-catcher" },
		{ _field_legacy, _field_real, "cow catcher side depth#world units, the depth of the angled side portion of the cow-catcher" },
		{ _field_legacy, _field_real_vector_3d, "cow catcher offset#offset from the unit\'s origin to put the origin of the cow-catcher at" },
		{ _field_legacy, _field_tag_reference, "collision damage override#if \"hide unit during transit\" isn\'t checked, this can override the unit\'s collision damage definition during the teleport", &collision_damage_reference$4 },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(equipmentAbilityTypeJetPackBlock, 1)
	{
		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_legacy, _field_byte_flags, "flags", &equipmentAbilityTypeJetPackFlags },
		{ _field_legacy, _field_pad, "pad after useCamAndMoveForThrustDirection", 3 },

		{ _field_legacy, _field_struct, "thrust to acceleration function", &scalar_function_named_struct_struct_definition },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_legacy, _field_struct, "Infinite energy thrust to acceleration function", &scalar_function_named_struct_struct_definition },

		{ _field_legacy, _field_real, "thrust attack time:s" },
		{ _field_legacy, _field_real, "thrust decay time:s" },
		{ _field_legacy, _field_real, "negative velocity acceleration scale#when falling, scale the thrust by this (so you can \'catch\' yourself easier)" },
		{ _field_legacy, _field_real, "airborne acceleration scale!" },
		{ _field_legacy, _field_real, "grounded acceleration magnitude#how hard to kick you upwards if you activate while grounded" },
		{ _field_legacy, _field_real, "landing anticipation time:s#how many seconds before landing the jetpack user enters the airborne arc" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 10 },
		{ _field_legacy, _field_explanation, "Zero-G jet pack", "These apply if \'Use camera and movement for thrust dir\' flag is checked" },
		{ _field_legacy, _field_real, "camera vs move input thrust control#Camera direction (0.0) VS movement input (1.0) interpolation" },
		{ _field_legacy, _field_real, "min speed#drag will be applied above this" },
		{ _field_legacy, _field_real, "max speed" },
		{ _field_legacy, _field_real, "stick forward thrust" },
		{ _field_legacy, _field_real, "stick strafe thrust" },
		{ _field_legacy, _field_real, "drag" },
		{ _field_legacy, _field_real, "drag cutoff time#if 0, drag is always applied" },
		{ _field_legacy, _field_real, "cow catcher duration" },
		{ _field_legacy, _field_block, "cow catcher parameters", &equipmentAbilityPartCowCatcherBlock_block },

		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(equipmentAbilityTypeHologramBlock, 1)
	{
		{ _field_legacy, _field_real, "hologram duration:s" },
		{ _field_legacy, _field_long_enum, "havok filter group", &collision_filter_enum },
		{ _field_legacy, _field_tag_reference, "creation effect", &global_effect_reference },
		{ _field_legacy, _field_tag_reference, "attached effect", &global_effect_reference },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_string_id, "attached effect marker" },
		{ _field_legacy, _field_string_id, "attached effect primary scale" },
		{ _field_legacy, _field_string_id, "attached effect secondary scale" },
		{ _field_legacy, _field_tag_reference, "destruction effect", &global_effect_reference },
		{ _field_legacy, _field_real, "shimmer decrease rate:1.0/s#how fast shimmer decreases" },
		{ _field_legacy, _field_real, "shimmer bullet ping:0-1#how much to ping shimmer when hit by a bullet" },
		{ _field_legacy, _field_struct, "shimmer to camo function#this is a periodic function with a period of 1 second\nthe shimmer value is used as the range input (interpolates between green and red)", &scalar_function_named_struct_struct_definition },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_legacy, _field_byte_flags, "flags", &equipmentAbilityTypeHologramFlags },
		{ _field_legacy, _field_pad, "pad after hologram flags", 3 },

		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(equipmentAbilityTypeSpecialWeaponBlock, 1)
	{
		{ _field_legacy, _field_tag_reference, "weapon", &global_weapon_reference },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(equipmentAbilityTypeSpecialMoveBlock, 1)
	{
		{ _field_legacy, _field_string_id, "forward" },
		{ _field_legacy, _field_string_id, "left" },
		{ _field_legacy, _field_string_id, "backward" },
		{ _field_legacy, _field_string_id, "right" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 5 },
		{ _field_legacy, _field_char_enum, "default direction", &EquipmentSpecialMoveDefaultDirectionDefinition },
		{ _field_legacy, _field_pad, "pad0", 3 },
		{ _field_legacy, _field_tag_reference, "directional effect", &Tag::Reference<struct effect_definition>::s_defaultDefinition },
		{ _field_legacy, _field_real, "Danger Radius#AI avoidance radius.  Ignored if zero." },
		{ _field_legacy, _field_real, "Speed multiplier#Use this instead of a trait.  0 defaults to 1.  With a trait, the client will move at non-modified scale until it gets replicated." },

		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(equipmentAbilityTypeEngineerShieldsBlock, 1)
	{
		{ _field_legacy, _field_real, "radius" },
		{ _field_legacy, _field_string_id, "shield name" },
		{ _field_legacy, _field_long_flags, "flags", &equipment_engineer_shields_flags },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(equipmentAbilityTypeSprintBlock, 1)
	{
		{ _field_legacy, _field_pad, "haha", 1 },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(equipmentAbilityTypeTeleporterBlock, 1)
	{
		{ _field_legacy, _field_explanation, "Teleporter", "This causes you to warp forward.  It\'ll trace the path with an effect at the specified speed, then spawn you at the end of it." },
		{ _field_legacy, _field_byte_flags, "flags", &teleporterFlags },
		{ _field_legacy, _field_pad, "blurgh", 3 },
		{ _field_legacy, _field_real, "teleport distance" },
		{ _field_legacy, _field_real, "travel speed#the speed at which you cross the teleporter distance; 0 means instant" },
		{ _field_legacy, _field_real, "deactivation speed#the speed you return to at the end of the teleport, if \"hide unit during transit\" isn\'t checked" },
		{ _field_legacy, _field_tag_reference, "trace effect#an effect that will follow along the travel path", &global_effect_reference },
		{ _field_legacy, _field_real_vector_3d, "trace effect offset#offset from the unit\'s origin to put the effects at" },
		{ _field_legacy, _field_real, "max pitch (airborne)#[-90 to 90] the pitch of the search vector will be clamped to no higher than this when starting a teleport in the air" },
		{ _field_legacy, _field_real, "max pitch (ground)#[-90 to 90] the pitch of the search vector will be clamped to no higher than this when starting a teleport on the ground" },
		{ _field_legacy, _field_custom, "Search Vector" },
		{ _field_legacy, _field_explanation, "Look Vector Weight", "If \"force along aim vector\" isn\'t checked, the start vector will be your motion vector, plus some amount of weight for where you\'re looking, if you\'re moving along your look vector." },
		{ _field_legacy, _field_real, "look vector weight#value from 0 to 1 for how much we can use the look vector in place of the movement vector" },
		{ _field_legacy, _field_real, "look vector falloff inner#degrees, inside this angle, we use the look vector at full weight" },
		{ _field_legacy, _field_real, "look vector falloff outer#degrees, outside this angle, we only use the movement vector" },
		{ _field_legacy, _field_real, "move vector vertical offset#degrees, how much to offset the move vector vertically; positive is up, negative is down" },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_custom, "Probes" },
		{ _field_legacy, _field_explanation, "Probe", "If \"disable extra probes\" isn\'t checked, we\'ll do a fan of rays vertically from our central vector, with one probe horizontally on either side of each of those rays." },
		{ _field_legacy, _field_real, "horizontal probe angle#degrees, the angle to each side of the horizontal probes" },
		{ _field_legacy, _field_real, "vertical probe angle#degrees, the angle up and down covered by the fan of vertical rays" },
		{ _field_legacy, _field_long_integer, "number of vertical probes#higher is more likely to find a good match, but more expensive" },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_custom, "Collision" },
		{ _field_legacy, _field_explanation, "Collision", "If \"hide unit during transit\" isn\'t checked, we\'ll add a cow-catcher collision volume on the front and change the collision damage type." },
		{ _field_legacy, _field_block, "cow catcher parameters", &equipmentAbilityPartCowCatcherBlock_block },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(equipmentAbilityTypeAutoTurretBlock, 1)
	{
		{ _field_legacy, _field_byte_flags, "flags", &equipment_auto_turret_flags },
		{ _field_legacy, _field_pad, "atf", 3 },
		{ _field_legacy, _field_tag_reference, "weapon", &object_reference$4 },
		{ _field_legacy, _field_real_point_3d, "orbit offset from player#z forward, x right, y down.  Set x,z zero to get independent turret, y is altitude off ground" },
		{ _field_legacy, _field_real, "orbit range#if above are zeros, this is max turret range" },
		{ _field_legacy, _field_real, "orbit rate:orbits per second" },
		{ _field_legacy, _field_real, "maximum range#if not following player, maximum distance downrange turret will travel" },
		{ _field_legacy, _field_real, "max velocity:units per second" },
		{ _field_legacy, _field_real, "max acceleration:units per second squared" },
		{ _field_legacy, _field_real, "turret halt engage time:seconds#amount of time after a moving turret engages a target before it halts movement" },
		{ _field_legacy, _field_real, "turret idle equipment drain multiplier:[0.1]#the multiplier on equipment drain when equipment is in its idle state" },
		{ _field_legacy, _field_real, "turret inactive equipment drain multiplier:[0.1]#the multiplier on equipment drain when equipment is in its inactive state" },
		{ _field_legacy, _field_real, "spawn radius:world units#area that must be clear in order for turret to spawn" },
		{ _field_legacy, _field_real, "spawn in time:seconds#the turret will be inactive for this duration" },
		{ _field_legacy, _field_real_vector_3d, "spawn offset from player:world units#relative to origin and camera direction without pitch" },
		{ _field_legacy, _field_real, "vertical bob height:world units" },
		{ _field_legacy, _field_real, "vertical bobs per second" },
		{ _field_legacy, _field_tag_reference, "spawn effect#effect played on the turret when it is spawned into the world", &global_effect_reference },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_string_id, "spawn effect marker" },
		{ _field_legacy, _field_string_id, "spawn dissolve type" },
		{ _field_legacy, _field_string_id, "spawn dissolve marker" },
		{ _field_legacy, _field_tag_reference, "collision phase effect#effect played on the turret while a biped or vehicle passes through it", &Tag::Reference<struct effect_definition>::s_defaultDefinition },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(equipmentAbilityTypeVisionModeBlock, 1)
	{
		{ _field_legacy, _field_byte_flags, "Flags", &equipmentVisionModeFlags },
		{ _field_legacy, _field_pad, "vmbf", 3 },
		{ _field_legacy, _field_real, "maximum tell distance:wu#\'Other activation tell effect\' will be applied to players within this distance" },
		{ _field_legacy, _field_tag_reference, "activation tell effect#applied to other players within maximum distance", &global_effect_reference },
		{ _field_legacy, _field_long_integer, "motion sensor tell blip ticks#within \'maxiumum tell distance\' blip duration if \'Generate tell motion sensor blip\' is checked" },
		{ _field_legacy, _field_tag_reference, "vision mode", &Tag::Reference<struct VisionModeDefinition>::s_defaultDefinition },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(equipmentAbilityTypeShieldProjectorBlock, 1)
	{
		{ _field_legacy, _field_real, "Lifetime #Number of seconds a projected shield will remain active." },
		{ _field_legacy, _field_real, "Recharge Time #Number of seconds between shield projections." },
		{ _field_legacy, _field_real, "Warmup Time #Number of seconds it takes to activate a projection." },
		{ _field_legacy, _field_real_fraction, "Max Move Percentage #Percentage of distance between current and desired positions a shield can be moved per update tick." },
		{ _field_legacy, _field_real, "Offset Amount #Distance from defender\'s position to project the shield." },
		{ _field_legacy, _field_real, "Min Projection Distance #Minimum distance between defender and attacker required to project shield." },
		{ _field_legacy, _field_real, "Max Projection Distance #Max distance from equipment that shield can be projected." },
		{ _field_legacy, _field_real_fraction, "Min Required Energy Level #Min energy required to activate shield." },
		{ _field_legacy, _field_tag_reference, "Project Effect #Beam effect that links equipment to projected shield.", &effect_reference$2 },
		{ _field_legacy, _field_tag_reference, "Warmup Effect #Effect played at eventual shield projection point during warmup period.", &effect_reference$2 },
		{ _field_legacy, _field_tag_reference, "Shield Crate #Crate created to represent projected shield.", &crate_reference$5 },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(equipmentAbilityTypeProjectileCollectorBlock, 1)
	{
		{ _field_legacy, _field_real_fraction, "Chance to Collect #Percent chance (0-1) that collector has to collect each grenade.  Will only attempt to collect each grenade once." },
		{ _field_legacy, _field_real_bounds, "Collect Cooldown #Number of seconds collector must wait between successful collections." },
		{ _field_legacy, _field_real_bounds, "Attack Delay #Number of seconds collector must wait before throwing a collected projectile at a target." },
		{ _field_legacy, _field_real, "Max Collect Range# Max range in world units that collector can collect and hold onto projectiles." },
		{ _field_legacy, _field_real_bounds, "Orbit Radius# Collector will try to keep collected projectiles orbiting in this range." },
		{ _field_legacy, _field_real, "Orbit Speed# Speed at which collected projectiles orbit." },
		{ _field_legacy, _field_real, "Vertical Offset# Orbit vertical offset amount." },
		{ _field_legacy, _field_real, "Strength# Controls amount of acceleration applied to projectile." },
		{ _field_legacy, _field_real, "Attack Speed# Initial speed of projectiles when thrown as an attack." },
		{ _field_legacy, _field_tag_reference, "Collect Effect #Beam effect that links equipment to each collected projectile.", &effect_reference$2 },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(equipmentAbilityTypeRemoteStrikeBlock, 1)
	{
		{ _field_legacy, _field_tag_reference, "weapon", &object_reference$4 },
		{ _field_legacy, _field_real, "max velocity" },
		{ _field_legacy, _field_real, "acceleration#this is a percentage of max velocity per second - 0.1 reaches max velocity in 10 seconds" },
		{ _field_legacy, _field_real, "decay rate#the rate at which a moving camera decays when you release the stick.  Lower decays faster." },
		{ _field_legacy, _field_real, "camera interpolation time" },
		{ _field_legacy, _field_byte_flags, "flags", &equipment_remote_strike_flags },
		{ _field_legacy, _field_pad, "rso", 3 },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(equipmentHackerDrainLevel, EquipmentAbilityTypeEquipmentHacker::DrainLevel::k_maxLevels)
	{
		{ _field_legacy, _field_real, "Cutoff distance#Targets within this distance will be affected by this multiplier." },
		{ _field_legacy, _field_real, "Drain multiplier#Multiplied by the base drain per second." },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(equipmentAbilityTypeEquipmentHackerBlock, 1)
	{
		{ _field_legacy, _field_byte_flags, "Flags", &equipmentHackerFlags },
		{ _field_legacy, _field_pad, "grue", 3 },
		{ _field_legacy, _field_real, "Base drain per second#Will be multiplied by a value from the drain level block." },
		{ _field_legacy, _field_real, "Energy recovery delay#The targeted equipment will not start regenerating energy until at least this much time has gone by." },
		{ _field_legacy, _field_real, "Cone angle degrees#Degrees away from the reticle at which targets are in the cone." },
		{ _field_legacy, _field_block, "Drain levels", &equipmentHackerDrainLevel_block },
		{ _field_legacy, _field_tag_reference, "cone effect#an effect that will shoot out of your face", &global_effect_reference },
		{ _field_legacy, _field_tag_reference, "target effect#an effect that will play on the target", &global_effect_reference },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(equipmentAbilityTypeRemoteVehicleBlock, 1)
	{
		{ _field_legacy, _field_tag_reference, "hologram spawner#reference the equipment that will spawn the hologram that will pilot the remote vehicle", &object_reference$4 },
		{ _field_legacy, _field_tag_reference, "vehicle#reference the remote vehicle to be created", &object_reference$4 },
		{ _field_legacy, _field_string_id, "seat label^#hologram gets loaded into this seat in the vehicle" },
		{ _field_legacy, _field_string_id, "spawn position flag#position of scenerio flag with this name. Empty will default to flag named \'remote_vehicle_start_position\'" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(equipmentAbilityTypeSuicideBombBlock, 1)
	{
		{ _field_legacy, _field_tag_reference, "explosion damage effect", &global_damage_reference },
		{ _field_legacy, _field_tag_reference, "explosion effect", &global_effect_reference },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(equipmentAbilityTypeActiveShieldBlock, 1)
	{
		{ _field_legacy, _field_byte_flags, "flags", &activeShieldFlags },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(unknown_equipment_ability, 65536)
	{
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK_FROM_STRUCT(equipmentAbilityDatum, k_equipmentMaxAbilityCount, equipmentAbilityDatum_struct_definition);

	V5_TAG_STRUCT(equipmentAbilityDatum)
	{
		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 21 },
		{ _field_legacy, _field_custom, "Timers" },
		{ _field_legacy, _field_real, "duration:seconds#use negative numbers for infinite duration" },
		{ _field_legacy, _field_real, "warmup time:seconds#time before the equipment truly becomes active" },
		{ _field_legacy, _field_real, "cooldown time:seconds#for equipment that suppresses combat actions, these actions remain suppressed for this long after the equipment deactivates\nNote that if this equipment also readies weapons when deactivated, the weapon will not be usable until both this timer expires and the ready animation has finished, whichever is longer" },
		{ _field_legacy, _field_real, "phantom volume activation time#time in seconds for the phantom volumes on this object to start accelerating things in them" },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_custom, "Energy" },
		{ _field_legacy, _field_explanation, "Energy", "All these fields are additive, meaning a negative number will reduce energy and a positive one will increase energy.  Every piece of equipment starts at 1.0 energy" },
		{ _field_legacy, _field_real, "minimum activation energy#energy must be at least this high to activate\nLike activation cost, but doesn\'t actually change energy levels" },
		{ _field_legacy, _field_real, "low energy warning threshold#used by UI" },
		{ _field_legacy, _field_real, "activation energy cost" },
		{ _field_legacy, _field_real, "deactivation energy cost" },
		{ _field_legacy, _field_real, "active energy rate:energy/second" },
		{ _field_legacy, _field_struct, "movement speed to energy rate:1/s", &scalar_function_named_struct_struct_definition },
		{ _field_legacy, _field_real, "movement speed domain:wu/s" },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_long_flags, "flags", &equipment_activation_flags },
		{ _field_legacy, _field_long_flags, "secondary flags", &equipmentActivationSecondaryFlags },
		{ _field_legacy, _field_short_integer, "charges#-1 means unlimited charges" },
		{ _field_legacy, _field_char_enum, "activation mode^", &equipment_activation_mode },
		{ _field_legacy, _field_char_integer, "object noise adjustment#for AI perception.\nwhile active, adjusts noises made by the owner unit by this many \'notches\'.\nnote that this is additive, so a positive number is louder and a negative number is quieter" },

		{ _field_legacy, _field_custom, "Type Definitions" },
		{ _field_legacy, _field_block, "multiplayer powerup", &equipmentAbilityTypeMultiplayerPowerupBlock_block },
		{ _field_legacy, _field_block, "spawner", &equipmentAbilityTypeSpawnerBlock_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_legacy, _field_block, "ai spawner", &equipmentAbilityTypeAiSpawnerBlock_block },

		{ _field_legacy, _field_block, "proximity mine", &equipmentAbilityTypeProximityMineBlock_block },
		{ _field_legacy, _field_block, "moition tracker noise", &equipmentAbilityTypeMotionTrackerNoiseBlock_block },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_block, "unknown@", &g_null_block_block },

		{ _field_legacy, _field_block, "invincibility mode", &equipmentAbilityTypeInvincibilityBlock_block },
		{ _field_legacy, _field_block, "tree of life", &equipmentAbilityTypeTreeOfLifeBlock_block },
		{ _field_legacy, _field_block, "shapeshifter", &equipmentAbilityTypeShapeshifterBlock_block },
		{ _field_legacy, _field_block, "player trait field", &equipmentAbilityTypePlayerTraitFieldBlock_block },
		{ _field_legacy, _field_block, "ai trait field", &equipmentAbilityTypeAiTraitFieldBlock_block },
		{ _field_legacy, _field_block, "repulsor field", &equipmentAbilityTypeRepulsorFieldBlock_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_legacy, _field_block, "stasis field", &equipmentAbilityTypeStasisFieldBlock_block },
		{ _field_legacy, _field_block, "ball lightning", &equipmentAbilityTypeBallLightningBlock_block },

		{ _field_legacy, _field_block, "IWHBYDaddy", &equipmentAbilityTypeDaddyBlock_block },
		{ _field_legacy, _field_block, "laser designation", &equipmentAbilityTypeLaserDesignationBlock_block },
		{ _field_legacy, _field_block, "super jump", &equipmentAbilityTypeSuperJumpBlock_block },
		{ _field_legacy, _field_block, "ammo pack", &equipmentAbilityTypeAmmoPackBlock_block },
		{ _field_legacy, _field_block, "power fist", &equipmentAbilityTypePowerFistBlock_block },
		{ _field_legacy, _field_block, "health pack", &equipmentAbilityTypeHealthPackBlock_block },
		{ _field_legacy, _field_block, "jet pack", &equipmentAbilityTypeJetPackBlock_block },
		{ _field_legacy, _field_block, "hologram", &equipmentAbilityTypeHologramBlock_block },
		{ _field_legacy, _field_block, "special weapon", &equipmentAbilityTypeSpecialWeaponBlock_block },
		{ _field_legacy, _field_block, "special move", &equipmentAbilityTypeSpecialMoveBlock_block },
		{ _field_legacy, _field_block, "engineer shields", &equipmentAbilityTypeEngineerShieldsBlock_block },
		{ _field_legacy, _field_block, "sprint", &equipmentAbilityTypeSprintBlock_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 19 },
		{ _field_legacy, _field_block, "teleporter", &equipmentAbilityTypeTeleporterBlock_block },
		{ _field_legacy, _field_block, "auto turret", &equipmentAbilityTypeAutoTurretBlock_block },
		{ _field_legacy, _field_block, "vision mode", &equipmentAbilityTypeVisionModeBlock_block },
		{ _field_legacy, _field_block, "shield projector", &equipmentAbilityTypeShieldProjectorBlock_block },
		{ _field_legacy, _field_block, "projectile collector", &equipmentAbilityTypeProjectileCollectorBlock_block },
		{ _field_legacy, _field_block, "remote strike", &equipmentAbilityTypeRemoteStrikeBlock_block },
		{ _field_legacy, _field_block, "equipment hacker", &equipmentAbilityTypeEquipmentHackerBlock_block },
		{ _field_legacy, _field_block, "remote vehicle", &equipmentAbilityTypeRemoteVehicleBlock_block },
		{ _field_legacy, _field_block, "suicide bomb", &equipmentAbilityTypeSuicideBombBlock_block },
		{ _field_legacy, _field_block, "active shield", &equipmentAbilityTypeActiveShieldBlock_block },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_tag_reference, "activation while disabled by player traits sound", &global_sound_reference },
		{ _field_legacy, _field_tag_reference, "activate effect", &global_effect_reference },
		{ _field_legacy, _field_tag_reference, "looping effect", &global_effect_reference },
		{ _field_legacy, _field_tag_reference, "deactivate effect", &global_effect_reference },
		{ _field_legacy, _field_string_id, "activation animation" },
		{ _field_legacy, _field_string_id, "active animation" },
		{ _field_legacy, _field_string_id, "deactivate animation" },
		{ _field_legacy, _field_string_id, "active animation stance" },

		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(EquipmentSoundRTPCBlock, k_maxEquipmentSoundRTPCBlocks)
	{
		{ _field_legacy, _field_long_block_index, "Attachment Index#Sound attachment to affect" },
		{ _field_legacy, _field_string_id, "Function#Function to drive the RTPC" },
		{ _field_legacy, _field_string_id, "RTPC Name#WWise RTPC string name" },
		{ _field_legacy, _field_long_integer, "RTPC name hash value*!" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(EquipmentSoundSweetenerBlock, k_maxEquipmentSoundSweetenerBlocks)
	{
		{ _field_legacy, _field_string_id, "Function#Function to trigger the sweetener" },
		{ _field_legacy, _field_tag_reference, "sound", &global_sound_reference },
		{ _field_legacy, _field_real, "Switch point#value of the function (between 0 and 1) where the sound is triggered" },
		{ _field_legacy, _field_long_integer, "Mode#0 for triggering while function is decreasing, 1 for increasing (more modes to come\?)" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK_FROM_STRUCT(equipment_block, 1, equipment_struct_definition_struct_definition );

	V5_TAG_STRUCT(equipment_struct_definition)
	{
		{ _field_legacy, _field_struct, "item", &item_struct_definition_struct_definition },
		{ _field_legacy, _field_custom, "$$$ EQUIPMENT $$$" },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 21 },
		{ _field_legacy, _field_custom, "Timers" },
		{ _field_legacy, _field_real, "duration:seconds#use negative numbers for infinite duration" },
		{ _field_legacy, _field_real, "warmup time:seconds#time before the equipment truly becomes active" },
		{ _field_legacy, _field_real, "cooldown time:seconds#for equipment that suppresses combat actions, these actions remain suppressed for this long after the equipment deactivates\nNote that if this equipment also readies weapons when deactivated, the weapon will not be usable until both this timer expires and the ready animation has finished, whichever is longer" },
		{ _field_legacy, _field_real, "phantom volume activation time#time in seconds for the phantom volumes on this object to start accelerating things in them" },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_custom, "Energy" },
		{ _field_legacy, _field_explanation, "Energy", "All these fields are additive, meaning a negative number will reduce energy and a positive one will increase energy.  Every piece of equipment starts at 1.0 energy" },
		{ _field_legacy, _field_real, "energy recovery time" },
		{ _field_legacy, _field_real, "minimum activation energy#energy must be at least this high to activate\nLike activation cost, but doesn\'t actually change energy levels" },
		{ _field_legacy, _field_real, "activation energy cost" },
		{ _field_legacy, _field_real, "deactivation energy cost" },
		{ _field_legacy, _field_real, "active energy rate:energy/second" },
		{ _field_legacy, _field_real, "recharge rate" },
		{ _field_legacy, _field_struct, "movement speed to energy rate:1/s", &scalar_function_named_struct_struct_definition },
		{ _field_legacy, _field_real, "movement speed domain:wu/s" },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_long_flags, "flags", &equipment_activation_flags },
		{ _field_legacy, _field_short_integer, "charges#-1 means unlimited charges" },
		{ _field_legacy, _field_char_enum, "activation mode^", &equipment_activation_mode },
		{ _field_legacy, _field_char_integer, "object noise adjustment#for AI perception.\nwhile active, adjusts noises made by the owner unit by this many \'notches\'.\nnote that this is additive, so a positive number is louder and a negative number is quieter" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 6 },
		{ _field_legacy, _field_custom, "Energy" },
		{ _field_legacy, _field_real, "initial energy" },
		{ _field_legacy, _field_real, "energy recovery time:seconds#after deactivation, energy stays constant for this long before starting to change by \'inactive energy rate\'" },
		{ _field_legacy, _field_real, "inactive energy rate:energy/second" },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_long_flags, "flags", &equipment_flags },

		{ _field_legacy, _field_string_id, "unit stow marker name#the marker on the unit to attach this equipment to when it is stowed.\nThe equipment should have a marker named \"equipment_stow_anchor\"" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_legacy, _field_char_enum, "pickup behavior", &equipment_pickup_behavior },
		{ _field_legacy, _field_pad, "IJKMOP", 3 },

		{ _field_legacy, _field_real_argb_color, "forced primary change color#sets the primary change color on the unit to this if the flag above is checked" },
		{ _field_legacy, _field_real_argb_color, "forced secondary change color#sets the secondary change color on the unit to this if the flag above is checked" },
		{ _field_legacy, _field_custom, "AI" },
		{ _field_legacy, _field_explanation, "AI", "Settings which the AI use to know how they should react to this equipment" },
		{ _field_legacy, _field_real, "danger radius#How large a danger zone we should create around this equipment (0 means no danger zone)" },
		{ _field_legacy, _field_real, "min deployment distance:wus#How far does my target have to be for me to throw this at them\?" },
		{ _field_legacy, _field_real, "awareness time:seconds#How long I should go unnoticed by nearby enemies" },
		{ _field_legacy, _field_string_id, "ai dialogue equipment type#The equipment ability type name used by the ai dialog system used to filter equipment activation dialogue events." },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_block, "override camera", &optionalUnitCameraBlock_block },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_struct, "abilities", &equipmentAbilityDatum_struct_definition },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_legacy, _field_block, "abilities", &equipmentAbilityDatum_block },

		{ _field_legacy, _field_char_enum, "damage reporting type", &global_damage_reporting_enum_definition },
		{ _field_legacy, _field_pad, "LKSHFDIJ", 3 },
		{ _field_legacy, _field_tag_reference, "hud screen reference", &Tag::Reference<struct CuiScreenDefinition>::s_defaultDefinition },
		{ _field_legacy, _field_tag_reference, "pickup sound", &global_sound_reference },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 4 },
		{ _field_legacy, _field_tag_reference, "activation while disabled by player traits sound", &global_sound_reference },
		{ _field_legacy, _field_tag_reference, "activate effect", &global_effect_reference },
		{ _field_legacy, _field_tag_reference, "looping effect", &global_effect_reference },
		{ _field_legacy, _field_tag_reference, "deactivate effect", &global_effect_reference },

		{ _field_legacy, _field_tag_reference, "energy charged effect", &global_effect_reference },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 4 },
		{ _field_legacy, _field_string_id, "activation animation" },
		{ _field_legacy, _field_string_id, "active animation" },
		{ _field_legacy, _field_string_id, "deactivate animation" },
		{ _field_legacy, _field_string_id, "active animation stance" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 4 },
		{ _field_legacy, _field_tag_reference, "unable to activate sound", &global_sound_reference },
		{ _field_legacy, _field_tag_reference, "Player sound bank#High quality player sound bank to be prefetched. Can be empty.", &global_soundbank_reference },
		{ _field_legacy, _field_block, "Sound RTPCs", &EquipmentSoundRTPCBlock_block },
		{ _field_legacy, _field_block, "Sound Sweeteners", &EquipmentSoundSweetenerBlock_block },

		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_terminator }
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

} // namespace blofeld

