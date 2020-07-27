#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_INHERIT(weapon, WEAPON_TAG, item, ITEM_TAG)
	{
		{ _field_struct, "item", &item_struct_definition_struct_definition },
		{ _field_custom, "$$$ WEAPON $$$" },
		{ _field_explanation, "", "All weapons should have \'primary trigger\' and \'secondary trigger\' markers as appropriate.\nBlurred permutations are called \'$primary-blur\' and \'$secondary-blur\'." },
		{ _field_long_flags, "flags", &weapon_definition_flags },
		{ _field_long_flags, "secondary flags", &weapon_definition_secondary_flags },
		{ _field_old_string_id, "unused label!" },
		{ _field_enum, "secondary trigger mode", &secondary_trigger_modes },
		{ _field_short_integer, "maximum alternate shots loaded#if the second trigger loads alternate ammunition, this is the maximum number of shots that can be loaded at a time" },
		{ _field_real, "turn on time#how long after being readied it takes this weapon to switch its \'turned_on\' attachment to 1.0" },

		{ _field_version_greater, _engine_type_haloreach, 3 },
		{ _field_explanation, "weapon vision mode settings", "" },
		{ _field_tag_reference, "vision mode#activated when this weapon is charging", &Tag::Reference<struct VisionModeDefinition>::s_defaultDefinition },
		{ _field_real, "vision cooldown time:seconds" },

		{ _field_explanation, "old obsolete export to functions", "" },
		{ _field_real, "ready time:seconds" },
		{ _field_tag_reference, "ready effect", &weapon_block_struct_ready_effect_reference },
		{ _field_tag_reference, "ready damage effect", &global_damage_effect_or_response_definition_reference },
		{ _field_explanation, "heat", "" },
		{ _field_real_fraction, "heat recovery threshold:[0,1]#the heat value a weapon must return to before leaving the overheated state, once it has become overheated in the first place" },
		{ _field_real_fraction, "overheated threshold:[0,1]#the heat value over which a weapon first becomes overheated (should be greater than the heat recovery threshold)" },
		{ _field_real_fraction, "heat detonation threshold:[0,1]#the heat value above which the weapon has a chance of exploding each time it is fired" },
		{ _field_real_fraction, "heat detonation fraction:[0,1]#the percent chance (between 0.0 and 1.0) the weapon will explode when fired over the heat detonation threshold" },
		{ _field_real_fraction, "heat loss per second:[0,1]#the amount of heat lost each second when the weapon is not being fired" },
		
		{ _field_version_greater_or_equal, _engine_type_haloreach, 4 },
		{ _field_string_id, "heat loss#function values sets the current heat loss per second" },
		{ _field_string_id, "heat loss venting#function value sets the heat loss per second while weapon is being vented" },
		{ _field_real, "heat venting time:seconds" },
		{ _field_real_fraction, "heat venting exit heat#heat at which to begin the venting exit animations so that the weapon is just about fully cooled when the exit animation completes." },
		
		{ _field_real_fraction, "heat illumination:[0,1]#the amount of illumination given off when the weapon is overheated" },
		
		{ _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_real_fraction, "heat warning threshold#the amount of heat at which a warning will be displayed on the hud" },
		
		{ _field_real_fraction, "overheated heat loss per second:[0,1]#the amount of heat lost each second when the weapon is not being fired" },
		
		{ _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_string_id, "overheated heat loss#function values sets the heat loss per second when weapon is overheated" },

		{ _field_tag_reference, "overheated", &weapon_block_struct_ready_effect_reference },
		{ _field_tag_reference, "overheated damage effect", &global_damage_effect_or_response_definition_reference },
		{ _field_tag_reference, "detonation", &weapon_block_struct_ready_effect_reference },
		{ _field_tag_reference, "detonation damage effect", &global_damage_effect_or_response_definition_reference },

		{ _field_version_less, _engine_type_haloreach },
		{ _field_struct, "melee damage parameters", &melee_damage_parameters_block_struct_definition }, // assembly

		{ _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_block, "melee damage parameters", &melee_damage_parameters_block_block },
		
		{ _field_tag_reference, "clang effect#effect that is played in the air between two players that clang with this weapon", &weapon_block_struct_ready_effect_reference },
		{ _field_char_enum, "melee damage reporting type", &global_damage_reporting_enum_definition },
		{ _field_pad, "FEOROBJE", 1 },
		{ _field_explanation, "zoom", "" },
		{ _field_short_integer, "magnification levels#the number of magnification levels this weapon allows" },
		{ _field_real_bounds, "magnification range" },

		{ _field_version_greater, _engine_type_haloreach, 3 },
		{ _field_char_integer, "zoom effect ticks#how often \'zoom effect\' will be triggered (while zoomed)" },
		{ _field_pad, "wzt", 3 },
		{ _field_tag_reference, "zoom effect#effect that is played while zoomed", &weapon_block_struct_ready_effect_reference },

		{ _field_explanation, "weapon aim assist!#DEPRECATED -- this will go away in favor of aim assist modes below", "DEPRECATED -- this will go away in favor of aim assist modes below" },
		{ _field_struct, "weapon aim assist", &aim_assist_struct_struct_definition },

		{ _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_struct, "iron sights modifiers", &WeaponBarrelIronSightsStruct_struct_definition },
		{ _field_block, "aim assist modes#First mode is normal, second mode is iron sights/scoped", &globalAimAssistBlock_block },

		{ _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_block, "target tracking", &global_target_tracking_parameters_block_block },

		{ _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_explanation, "aim swim indexing", "swim index 0 used when unzoomed, index 1 is for first zoom level, index 2 is 2nd zoom, etc." },
		{ _field_block, "aim swim", &globalAimSwimBlock_block },

		{ _field_version_greater_or_equal, _engine_type_haloreach, 3 },
		{ _field_explanation, "ballistics", "" },
		{ _field_real_bounds, "ballistic arcing firing bounds:world units#At the min range (or closer), the minimum ballistic arcing is used, at the max (or farther away), the maximum arcing is used" },
		{ _field_real_bounds, "ballistic arcing fraction bounds:[0-1]#Controls speed and degree of arc. 0 = low, fast, 1 = high, slow" },
		
		{ _field_explanation, "movement", "" },
		{ _field_enum, "movement penalized", &movement_penalty_modes },

		{ _field_pad, "GTIXVRPA", 2 },
		{ _field_real_fraction, "forward movement penalty#percent slowdown to forward movement for units carrying this weapon" },
		{ _field_real_fraction, "sideways movement penalty#percent slowdown to sideways and backward movement for units carrying this weapon" },

		{ _field_version_greater, _engine_type_haloreach, 6 },
		{ _field_real_fraction, "gunner armor mod forward movement penalty#percent slowdown to forward movement for units carrying this weapon with the gunner armor mod active" },
		{ _field_real_fraction, "gunner armor mod sideways movement penalty#percent slowdown to sideways and backward movement for units carrying this weapon with the gunner armor mod active" },
		{ _field_explanation, "Aiming", "" },
		{ _field_real, "Maximum pitch rate:degrees per second#This will cap the speed at which the player can aim when holding this weapon, probably want to set something sensible for turrets etc" },
		{ _field_explanation, "ArmorMod Parameters", "" },
		{ _field_real, "Ammopack power capacity#Ammopack armormod - 0.2 would give 20% additional capacity to an energy weapon" },

		{ _field_explanation, "AI targeting parameters", "" },
		{ _field_real, "AI scariness" },
		{ _field_explanation, "miscellaneous", "" },
		{ _field_real, "weapon power-on time:seconds" },
		{ _field_real, "weapon power-off time:seconds" },
		{ _field_tag_reference, "weapon power-on effect", &weapon_block_struct_ready_effect_reference },
		{ _field_tag_reference, "weapon power-off effect", &weapon_block_struct_ready_effect_reference },
		{ _field_real, "age heat recovery penalty#how much the weapon\'s heat recovery is penalized as it ages" },
		{ _field_real, "age rate of fire penalty#how much the weapon\'s rate of fire is penalized as it ages" },
		{ _field_real_fraction, "age misfire start:[0,1]#the age threshold when the weapon begins to misfire" },
		{ _field_real_fraction, "age misfire chance:[0,1]#at age 1.0, the misfire chance per shot" },
		{ _field_tag_reference, "pickup sound", &global_sound_reference },
		{ _field_tag_reference, "zoom-in sound", &global_sound_reference },
		{ _field_tag_reference, "zoom-out sound", &global_sound_reference },
		{ _field_real, "active camo ding#how much to decrease active camo when a round is fired" },

		{ _field_version_less, _engine_type_haloreach },
		{ _field_real, "active camo regrowth rate" }, // assembly

		{ _field_string_id, "handle node#the node that get\'s attached to the unit\'s hand" },
		{ _field_explanation, "weapon labels", "" },
		{ _field_string_id, "weapon class" },
		{ _field_string_id, "weapon name" },
		{ _field_explanation, "more miscellaneous", "" },

		{ _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_char_enum, "first time pickup type", &first_time_pickup_types },
		{ _field_pad, "PAD", 3 },

		{ _field_version_less, _engine_type_haloreach },
		{ _field_enum, "multiplayer weapon type", &multiplayer_weapon_types },

		{ _field_enum, "weapon type", &weapon_types },

		{ _field_version_less, _engine_type_haloreach },
		{ _field_enum, "tracking type", &tracking_types },

		{ _field_short_integer, "low ammo threshold" },
		{ _field_struct, "player interface", &weapon_interface_struct_struct_definition },
		{ _field_block, "predicted resources", &g_null_block_block },
		{ _field_block, "magazines", &magazines_block },
		{ _field_block, "new triggers", &weapon_triggers_block },
		{ _field_block, "barrels", &weapon_barrels_block },

		{ _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_explanation, "scaleshot", "Allows the weapon to scale up and fire different projectiles based upon how many hits you get etc." },
		{ _field_block, "scaleshot parameters", &weaponScaleshotStruct_block },

		{ _field_real, "runtime weapon power on velocity!" },
		{ _field_real, "runtime weapon power off velocity!" },
		{ _field_useless_pad },
		{ _field_explanation, "first-person movement control", "" },
		{ _field_real, "max movement acceleration" },
		{ _field_real, "max movement velocity" },
		{ _field_real, "max turning acceleration" },
		{ _field_real, "max turning velocity" },
		{ _field_tag_reference, "deployed vehicle", &vehicle_reference$5 },
		{ _field_tag_reference, "tossed weapon", &global_weapon_reference },
		{ _field_tag_reference, "age effect", &global_effect_reference },
		{ _field_tag_reference, "aged weapon", &global_weapon_reference },
		{ _field_tag_reference, "aged material effects", &global_material_effects_reference },

		{ _field_version_greater, _engine_type_haloreach },
		{ _field_real, "per kill or hit aging amount#aging applied for \'weapon ages when damage is inflicted\' or \'weapon ages with each kill\' flags" },
		
		{ _field_real, "external aging amount" },
		{ _field_real, "campaign external aging amount" },

		{ _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_real, "external heat amount" },

		{ _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_real_fraction, "age recovered per second:[0,1]#the amount of age the weapon recovers per second" },
		{ _field_tag_reference, "age fully recovered (sound or effect)#the sound or effect played when the weapon\'s age reaches fully recovered", &weapon_block_struct_ready_effect_reference },
		
		{ _field_real_vector_3d, "first person weapon offset" },

		{ _field_version_platform_include, _platform_type_pc, 2 },
		{ _field_version_equal, _engine_type_halo3 },
		{ _field_real_vector_3d, "centered first person weapon offset" },

		{ _field_real_vector_2d, "first person scope size" },
		{ _field_real_bounds, "support third person camera range:degrees#range in degrees. 0 is straight, -90 is down, 90 is up" },
		{ _field_real, "weapon zoom time#seconds" },
		{ _field_real, "weapon ready-for-use time#seconds" },

		{ _field_version_greater, _engine_type_haloreach, 3 },
		{ _field_real, "weapon ready 1st person animation playback scale#e.g. - 2.0 makes playspeed twice as fast" },
		{ _field_real, "tether transition to linked time:seconds#begins when tethered projectile is LNKED" },
		{ _field_real, "tether transition from linked time:seconds#begins when tethered projectile becomes non-LNKED" },

		{ _field_string_id, "unit stow anchor name" },

		{ _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_block, "screen effects", &weapon_screen_effect_block_block },

		{ _field_version_greater, _engine_type_haloreach, 12 },
		{ _field_tag_reference, "Player sound bank#High quality player sound bank to be prefetched. Can be empty.", &global_soundbank_reference },
		{ _field_string_id, "Player EQ preset name#Name of the EQ shareset in WWise to apply when this weapon is active" },
		{ _field_long_integer, "Player EQ preset hash!" },
		{ _field_string_id, "Reload cancel event#Note - this is a direct event string - not a .sound" },
		{ _field_long_integer, "Reload cancel event hash!" },
		{ _field_tag_reference, "single shot fire for automatics", &global_sound_reference },
		{ _field_tag_reference, "firing loop for automatics", &global_looping_sound_reference },
		{ _field_block, "Sound RTPCs", &WeaponSoundRTPCBlock_block },
		{ _field_block, "Sound Sweeteners", &WeaponSoundSweetenerBlock_block },
		{ _field_string_id, "Locking Reticle Screen Name" },
		{ _field_string_id, "Locked On Reticle Screen Name" },
		{ _field_custom },
		{ _field_terminator }
	};

	TAG_REFERENCE(player_melee_damage_reference, INVALID_TAG);
	TAG_REFERENCE(player_melee_response_reference, INVALID_TAG);
	TAG_REFERENCE(lunge_melee_explosive_response_reference, INVALID_TAG);

	TAG_STRUCT(melee_damage_parameters_block)
	{ 
		{ _field_explanation, "melee damage parameters", "damage pyramid angles: defines the frustum from the camera that the melee-attack uses to find targets\ndamage pyramid depth: how far the melee attack searches for a target" },
		{ _field_version_less_or_equal, _engine_type_halo3, 2 },
		{ _field_tag_reference, "player melee damage", &player_melee_damage_reference }, // assembly
		{ _field_tag_reference, "player melee response", &player_melee_response_reference }, // assembly
		{ _field_real_euler_angles_2d, "damage pyramid angles" },
		{ _field_real, "damage pyramid depth:wu#0 defaults to 0.8f" },
		{ _field_version_greater_or_equal, _engine_type_haloreach, 3 },
		{ _field_real, "maximum lunge range:wu#0 defaults to 1.22f" },
		{ _field_real, "damage lunge explosive depth:wu#the distance out from the pyramid center to spawn explosive effects.  This value will be clamped to the damage pyramid depth. 0 defaults to the damage pyramid depth" },
		{ _field_real, "runtime damage lunge explosive fraction*!" },
		{ _field_tag_reference, "melee damage", &global_damage_reference },
		{ _field_tag_reference, "melee response", &global_damage_effect_or_response_definition_reference },
		{ _field_tag_reference, "lunge melee damage#this is only important for the energy sword", &global_damage_reference },
		{ _field_tag_reference, "lunge melee response#this is only important for the energy sword", &global_damage_effect_or_response_definition_reference },
		{ _field_tag_reference, "empty melee damage#this is only important for the energy sword", &global_damage_reference },
		{ _field_tag_reference, "empty melee response#this is only important for the energy sword", &global_damage_effect_or_response_definition_reference },
		{ _field_tag_reference, "clang melee damage#this is only important for the energy sword", &global_damage_reference },
		{ _field_tag_reference, "clang melee response#this is only important for the energy sword", &global_damage_effect_or_response_definition_reference },
		{ _field_tag_reference, "clang melee against melee weapon damage#e.g. used by AR to damage sword guy when clanging sword attack", &global_damage_reference },
		{ _field_tag_reference, "clang melee against melee weapon damage response#e.g. used by AR to damage sword guy when clanging sword attack", &global_damage_effect_or_response_definition_reference },
		{ _field_tag_reference, "lunge melee explosive damage", &global_effect_reference },
		{ _field_version_less_or_equal, _engine_type_halo3, 1 },
		{ _field_tag_reference, "lunge melee explosive response", &lunge_melee_explosive_response_reference }, // assembly
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(melee_damage_parameters_block, k_melee_damage_class_count, melee_damage_parameters_block_struct_definition);

	TAG_BLOCK(globalAimAssistBlock, 3)
	{
		{ _field_real, "autoaim stick time:seconds#the number of seconds that the crosshair needs to be on target before the larger autoaim stick kicks in" },
		{ _field_angle, "autoaim stick angle:degrees#the maximum angle that autoaim works to \'stick\' a target.  set to zero to use default behavior." },
		{ _field_angle, "autoaim angle:degrees#the maximum angle that autoaim works at full strength" },
		{ _field_real, "autoaim range:world units#the maximum distance that autoaim works at full strength" },
		{ _field_real, "autoaim falloff range:world units#at what point the autoaim starts falling off" },
		{ _field_real, "autoaim near falloff range:world units#at what point the autoaim reaches full power" },
		{ _field_angle, "magnetism angle:degrees#the maximum angle that magnetism works at full strength" },
		{ _field_real, "magnetism range:world units#the maximum distance that magnetism works at full strength" },
		{ _field_real, "magnetism falloff range:world units#at what point magnetism starts falling off" },
		{ _field_real, "magnetism near falloff range:world units#at what point magnetism reaches full power" },
		{ _field_angle, "deviation angle:degrees#the maximum angle that a projectile is allowed to deviate from the gun barrel due to autoaim OR network lead vector reconstruction" },
		{ _field_pad, "ZHV", 4 },
		{ _field_pad, "CVYGPMLMX", 16 },
		{ _field_pad, "UQXKLVAXI", 4 },
		{ _field_terminator }
	};

	TAG_BLOCK(globalAimSwimBlock, 3)
	{
		{ _field_explanation, "x axis curve", "" },
		{ _field_real, "x period:seconds" },
		{ _field_real, "x amplitude" },
		{ _field_explanation, "y axis curve", "" },
		{ _field_real, "y period:seconds" },
		{ _field_real, "y amplitude" },
		{ _field_explanation, "biped state scalers", "" },
		{ _field_real, "non-moving, crouched" },
		{ _field_real, "non-moving, standing" },
		{ _field_real, "moving" },
		{ _field_explanation, "biped state transition times", "" },
		{ _field_real, "to crouched:seconds" },
		{ _field_real, "to standing:seconds" },
		{ _field_terminator }
	};

	TAG_BLOCK(weapon_first_person_interface_block, k_first_person_interface_count)
	{
		{ _field_tag_reference, "first person model", &render_model_reference$10 },
		{ _field_tag_reference, "first person animations", &model_animation_graph_reference$4 },

		{ _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_real, "first person fov scale#the multiplier by the standard first person FOV to use when this weapon is held" },
		{ _field_real, "first person dof distance#the distance to apply depth of field to the weapon" },

		{ _field_terminator }
	};

	TAG_BLOCK(magazine_objects, MAXIMUM_NUMBER_OF_MAGAZINE_OBJECTS_PER_MAGAZINE)
	{
		{ _field_short_integer, "rounds" },
		{ _field_pad, "DTDPY", 2 },
		{ _field_tag_reference, "equipment^", &global_equipment_reference },
		{ _field_terminator }
	};

	TAG_BLOCK(magazines, MAXIMUM_NUMBER_OF_MAGAZINES_PER_WEAPON)
	{
		{ _field_long_flags, "flags", &magazine_flags },
		{ _field_short_integer, "rounds recharged:per second" },
		{ _field_short_integer, "rounds total initial" },
		{ _field_short_integer, "rounds total maximum" },
		{ _field_short_integer, "rounds loaded maximum" },
		{ _field_short_integer, "runtime rounds inventory maximum" },

		{ _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_short_integer, "Ammopack rounds total initial#AmmoPack armormod - alternate total_initial value due to AmmoPack" },
		{ _field_short_integer, "Ammopack rounds total maximum#AmmoPack armormod - alternate total_maximum value due to armor mod AmmoPack" },

		{ _field_pad, "pad", 2 },
		{ _field_real, "reload dialogue time:seconds#the length of time we wait before saying the reload dialogue" },
		{ _field_short_integer, "rounds reloaded" },
		{ _field_pad, "VJGZW", 2 },
		{ _field_real, "chamber time:seconds - NOT USED!#the length of time it takes to chamber the next round" },
		{ _field_pad, "HPMIV", 8 },
		{ _field_pad, "P", 16 },
		{ _field_tag_reference, "reloading effect", &weapon_block_struct_ready_effect_reference },
		{ _field_tag_reference, "reloading damage effect", &global_damage_effect_or_response_definition_reference },
		{ _field_tag_reference, "chambering effect", &weapon_block_struct_ready_effect_reference },
		{ _field_tag_reference, "chambering damage effect", &global_damage_effect_or_response_definition_reference },
		{ _field_useless_pad },
		{ _field_block, "magazines", &magazine_objects_block },
		{ _field_terminator }
	};

	TAG_BLOCK(weapon_trigger_charging_fire_fraction, MAXIMUM_CHARGING_FIRE_FRACTIONS_PER_TRIGGER)
	{
		{ _field_real_fraction, "charge fraction^:[0.1]#charging fraction at which the weapon should additionally fire a shot." },
		{ _field_terminator }
	};

	TAG_BLOCK(weapon_triggers, k_weapon_trigger_count)
	{
		{ _field_long_flags, "flags", &weapon_trigger_definition_flags },
		{ _field_enum, "input", &weapon_trigger_inputs },
		{ _field_enum, "behavior", &weapon_trigger_behaviors },
		{ _field_short_block_index, "primary barrel" },
		{ _field_short_block_index, "secondary barrel" },
		{ _field_enum, "prediction", &trigger_prediction_type_enum },
		{ _field_pad, "GNFR", 2 },
		{ _field_useless_pad },
		{ _field_struct, "autofire", &weapon_trigger_autofire_struct_struct_definition },
		{ _field_struct, "charging", &weapon_trigger_charging_struct_struct_definition },

		{ _field_version_less, _engine_type_haloreach, 3 }, // Cheers camden, ya mad lad
		{ _field_real, "lock on hold time" }, 
		{ _field_real, "lock on acquire time" }, 
		{ _field_real, "lock on grace period" },

		{ _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_tag_reference, "double latch projectile releasable effect#created once player is able to release the tethered projectile", &global_effect_reference },
		{ _field_tag_reference, "double latch projectile released effect#created when player releases the tethered projectile", &global_effect_reference },

		{ _field_terminator }
	};

	TAG_BLOCK(projectileDistributionCustomVector, k_projectile_maximum_custom_vectors)
	{
		{ _field_real_point_2d, "Point offset^:[-1.1]#x-y offset - +x is right, +y is up" },
		{ _field_terminator }
	};

	TAG_BLOCK(weapon_barrel_function_block, 1)
	{
		{ _field_struct, "function", &scalar_function_named_struct_struct_definition },
		{ _field_terminator }
	};

	TAG_BLOCK(weapon_barrel_first_person_offset_block, k_first_person_weapon_offset_type_count)
	{
		{ _field_real_point_3d, "first person offset:world units#+x is forward, +z is up, +y is left" },
		{ _field_terminator }
	};

	TAG_BLOCK(barrel_firing_effect_block, k_weapon_barrel_effect_count)
	{
		{ _field_short_integer, "shot count lower bound#the minimum number of times this firing effect will be used, once it has been chosen" },
		{ _field_short_integer, "shot count upper bound#the maximum number of times this firing effect will be used, once it has been chosen" },
		{ _field_tag_reference, "firing effect^#this effect is used when the weapon is loaded and fired normally", &weapon_block_struct_ready_effect_reference },

		{ _field_version_greater, _engine_type_haloreach },
		{ _field_tag_reference, "critical effect^#this effect is used when the weapon is loaded and will do critical damage", &weapon_block_struct_ready_effect_reference },

		{ _field_tag_reference, "misfire effect#this effect is used when the weapon is loaded but fired while overheated", &weapon_block_struct_ready_effect_reference },
		{ _field_tag_reference, "empty effect#this effect is used when the weapon is not loaded", &weapon_block_struct_ready_effect_reference },
		{ _field_tag_reference, "optional secondary firing effect#this effect is used when the weapon is not loaded", &weapon_block_struct_ready_effect_reference },
		{ _field_tag_reference, "firing damage#this effect is used when the weapon is loaded and fired normally", &global_damage_effect_or_response_definition_reference },

		{ _field_version_greater, _engine_type_haloreach },
		{ _field_tag_reference, "critical damage^#this effect is used when the weapon is loaded and will do critical damage", &weapon_block_struct_ready_effect_reference },

		{ _field_tag_reference, "misfire damage#this effect is used when the weapon is loaded but fired while overheated", &global_damage_effect_or_response_definition_reference },
		{ _field_tag_reference, "empty damage#this effect is used when the weapon is not loaded", &global_damage_effect_or_response_definition_reference },
		{ _field_tag_reference, "optional secondary firing damage#this effect is used when the weapon is loaded and fired normally", &global_damage_effect_or_response_definition_reference },
		{ _field_tag_reference, "firing rider damage#this effect is used when the weapon is loaded and fired normally", &global_damage_effect_or_response_definition_reference },

		{ _field_version_greater, _engine_type_haloreach },
		{ _field_tag_reference, "critical rider damage^#this effect is used when the weapon is loaded and will do critical damage", &weapon_block_struct_ready_effect_reference },

		{ _field_tag_reference, "misfire rider damage#this effect is used when the weapon is loaded but fired while overheated", &global_damage_effect_or_response_definition_reference },
		{ _field_tag_reference, "empty rider damage#this effect is used when the weapon is not loaded", &global_damage_effect_or_response_definition_reference },
		{ _field_tag_reference, "optional secondary firing rider damage#this effect is used when the weapon is loaded and fired normally", &global_damage_effect_or_response_definition_reference },
		{ _field_terminator }
	};

	TAG_BLOCK(weapon_barrels, k_weapon_barrel_count)
	{
		{ _field_long_flags, "flags", &weapon_barrel_flags },
		{ _field_explanation, "firing", "" },
		{ _field_struct, "firing", &weapon_barrel_firing_parameters_struct_struct_definition },
		{ _field_short_block_index, "magazine#the magazine from which this trigger draws its ammunition" },
		{ _field_short_integer, "rounds per shot#the number of rounds expended to create a single firing effect" },
		{ _field_short_integer, "minimum rounds loaded#the minimum number of rounds necessary to fire the weapon" },
		{ _field_short_integer, "rounds between tracers#the number of non-tracer rounds fired between tracers" },
		{ _field_custom },
		{ _field_string_id, "optional barrel marker name" },

		{ _field_version_less, _engine_type_haloreach, 3 },
		{ _field_explanation, "prediction properties", "what the behavior of this barrel is in a predicted network game" },
		{ _field_enum, "prediction type", &barrel_prediction_type_enum },
		{ _field_enum, "firing noise#how loud this weapon appears to the AI", &ai_sound_volume_enum },

		{ _field_version_greater_or_equal, _engine_type_haloreach, 5 },
		{ _field_enum, "firing noise#how loud this weapon appears to the AI", &ai_sound_volume_enum },
		{ _field_explanation, "prediction properties", "what the behavior of this barrel is in a predicted network game" },
		{ _field_enum, "prediction type", &barrel_prediction_type_enum },
		{ _field_real, "event_synchronized_projectiles_per_second#Valid only for barrels set to prediction type \"continuous\". Controls how many projectiles per second can be individually synchronized (use debug_projectiles to diagnose)." },
		{ _field_real, "maximum_barrel_error_for_event_synchronization#Valid only for barrels set to prediction type \"continuous\". If the barrel\'s current error level is over this value (zero to one scale), we will not consider synchronizing projectiles with individual events (use debug_projectiles to diagnose)." },

		{ _field_explanation, "firing error", "full error look pitch rate controlls how fast you can turn \nwith full error, yaw is implied from pitch. 0==130.\nfor reference, profile sensitivities are set to:\n1: 40\n3: 60\n9: 130\n" },
		{ _field_struct, "firing error", &weapon_barrel_firing_error_struct_struct_definition },

		{ _field_version_less, _engine_type_haloreach, 2 }, // H3
		{ _field_struct, "turning", &weapon_barrel_turning_struct_struct_definition },
		{ _field_struct, "dual weapon error", &weapon_barrel_dual_error_struct_struct_definition },

		{ _field_explanation, "projectile", "" },
		{ _field_enum, "distribution function", &weapon_barrel_distribution_functions },
		{ _field_short_integer, "projectiles per shot" },

		{ _field_version_greater, _engine_type_haloreach },
		{ _field_block, "custom vectors#Custom vectors must be set in distribution function above", &projectileDistributionCustomVector_block },

		{ _field_real, "distribution angle:degrees#used by distribution function \'horizontal fan\' above" },
		{ _field_angle, "minimum error:degrees#projectile direction is randomly selected between this and max_error_angle below" },
		{ _field_angle_bounds, "error angle:degrees (max_error_angle)#current barrel_error is linearly interpolated between these to generate max_error_angle" },

		{ _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_struct, "accuracy penalties", &weapon_barrel_projectile_accuracy_penalty_struct_struct_definition },

		{ _field_block, "first person offset", &weapon_barrel_first_person_offset_block_block },
		{ _field_char_enum, "damage effect reporting type", &global_damage_reporting_enum_definition },
		{ _field_pad, "DGSXQ", 3 },
		{ _field_tag_reference, "projectile", &Tag::Reference<struct projectile_definition>::s_defaultDefinition },
		{ _field_tag_reference, "optional secondary projectile", &Tag::Reference<struct projectile_definition>::s_defaultDefinition },
		{ _field_struct, "eh", &weapon_barrel_damage_effect_struct_struct_definition },
		{ _field_tag_reference, "crate projectile", &crate_projectile_reference },
		{ _field_real, "crate projectile speed" },
		{ _field_explanation, "misc", "" },
		{ _field_real, "ejection port recovery time#the amount of time (in seconds) it takes for the ejection port to transition from 1.0 (open) to 0.0 (closed) after a shot has been fired" },
		{ _field_real, "illumination recovery time#the amount of time (in seconds) it takes the illumination function to transition from 1.0 (bright) to 0.0 (dark) after a shot has been fired" },
		{ _field_real_fraction, "heat generated per round:[0,1]#the amount of heat generated each time the barrel fires. Unlike the name suggests, this amount of heat is NOT applied per projectile created." },

		{ _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_string_id, "heat generated per round function&heat generated per round#function value sets the amount of heat to add to the weapon each tick the barrel is firing" },

		{ _field_real_fraction, "age generated per round:[0,1]#the amount the weapon ages each time the trigger is fired" },
		{ _field_real_fraction, "CAMPAIGN age generated per round:[0,1]#the amount the weapon ages each time the trigger is fired" },
		{ _field_real, "overload time:seconds#the next trigger fires this often while holding down this trigger" },

		{ _field_version_less, _engine_type_haloreach, 7 }, //pulled from assembly, probs exists in h2ek definitions(?)
		{ _field_real_bounds, "angle change per shot" },
		{ _field_real, "angle change acceleration time" },
		{ _field_real, "angle change deceleration time" },
		{ _field_enum, "angle change function", &weapon_barrel_angle_change_functions },
		{ _field_short_integer, "@unknown" },
		{ _field_real, "runtime angle change acceleration rate" },
		{ _field_real, "runtime angle change deceleration rate" },

		{ _field_real, "runtime illumination recovery rate!" },
		{ _field_real, "runtime ejection port recovery rate!" },
		{ _field_real, "runtime rate of fire acceleration rate!" },
		{ _field_real, "runtime rate of fire deceleration rate!" },

		{ _field_version_less, _engine_type_haloreach },
		{ _field_real, "runtime error acceleration rate!" },

		{ _field_real, "runtime error deceleration rate!" },
		{ _field_block, "firing effects#firing effects determine what happens when this trigger is fired", &barrel_firing_effect_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(weaponScaleshotLevelStruct, WeaponScaleshotLevelDefinition::k_maxLevels)
	{
		{ _field_long_flags, "flags", &weaponScaleshotLevelFlags },
		{ _field_real, "minimum power level^#the minimum power at which this scaleshot level kicks in" },
		{ _field_real, "power change per shot#the change per shot in power when you\'re at this level" },
		{ _field_real, "power change per second#the change per second in power when you\'re at this level" },
		{ _field_tag_reference, "projectile#the projectile to fire at this level", &Tag::Reference<struct projectile_definition>::s_defaultDefinition },
		{ _field_block, "firing effects#firing effects when firing at this level", &barrel_firing_effect_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(weaponScaleshotStruct, 1)
	{
		{ _field_long_flags, "flags", &weaponScaleshotFlags },
		{ _field_real, "power per shot#the amount of scaleshot power you get when this weapon is fired" },
		{ _field_real, "power per hit#the amount of scaleshot power you get when a projectile from this weapon hits an enemy" },
		{ _field_real, "power change per second#the change per second in power" },
		{ _field_explanation, "power levels", "IMPORTANT: put these in increasing order, by \"minimum power level\".  I claim no responsibility for weird behavior if they\'re out of order." },
		{ _field_block, "power levels", &weaponScaleshotLevelStruct_block },
		{ _field_terminator }
	};

	TAG_BLOCK(weapon_screen_effect_block, 4)
	{
		{ _field_byte_flags, "flags", &weapon_screen_effect_flags },
		{ _field_pad, "LKSZJFSE", 3 },
		{ _field_tag_reference, "screen effect^", &global_area_screen_effect_reference },
		{ _field_terminator }
	};

	TAG_BLOCK(WeaponSoundRTPCBlock, k_maxWeaponSoundRTPCBlocks)
	{
		{ _field_long_block_index, "Attachment Index#Sound attachment to affect - leave empty for main body" },
		{ _field_string_id, "Function#Function to drive the RTPC" },
		{ _field_string_id, "RTPC Name#WWise RTPC string name" },
		{ _field_long_integer, "RTPC name hash value*!" },
		{ _field_terminator }
	};

	TAG_BLOCK(WeaponSoundSweetenerBlock, k_maxWeaponSoundSweetenerBlocks)
	{
		{ _field_string_id, "Function#Function to trigger the sweetener" },
		{ _field_tag_reference, "sound", &global_sound_reference },
		{ _field_real, "Switch point#value of the function (between 0 and 1) where the sound is triggered" },
		{ _field_long_integer, "Mode#0 for triggering while function is decreasing, 1 for increasing (more modes to come\?)" },
		{ _field_terminator }
	};

	TAG_STRUCT(aim_assist_struct)
	{
		{ _field_version_greater, _engine_type_haloreach, 2},
		{ _field_real, "autoaim stick time:seconds!#the number of seconds that the crosshair needs to be on target before the larger autoaim stick kicks in" },
		{ _field_angle, "autoaim stick angle:degrees!#the maximum angle that autoaim works to \'stick\' a target.  set to zero to use default behavior." },
		
		{ _field_angle, "autoaim angle:degrees#the maximum angle that autoaim works at full strength!" },
		{ _field_real, "autoaim range:world units#the maximum distance that autoaim works at full strength!" },
		{ _field_real, "autoaim falloff range:world units#at what point the autoaim starts falling off!" },

		{ _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_real, "autoaim near falloff range:world units#at what point the autoaim reaches full power!" },

		{ _field_angle, "magnetism angle:degrees#the maximum angle that magnetism works at full strength!" },
		{ _field_real, "magnetism range:world units#the maximum distance that magnetism works at full strength!" },
		{ _field_real, "magnetism falloff range:world units#at what point magnetism starts falling off!" },

		{ _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_real, "magnetism near falloff range:world units#at what point magnetism reaches full power!" },

		{ _field_angle, "deviation angle:degrees#the maximum angle that a projectile is allowed to deviate from the gun barrel due to autoaim OR network lead vector reconstruction!" },
		{ _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_pad, "ZHV", 4 },
		{ _field_pad, "CVYGPMLMX", 16 },
		{ _field_pad, "UQXKLVAXI", 4 },
		{ _field_terminator }
	};

	TAG_STRUCT(WeaponBarrelIronSightsStruct)
	{
		{ _field_real, "spread multiplier#multiplies the spread error - use < 1.0 for more accuracy" },
		{ _field_real, "movement multiplier#multipliers player maximum move speed" },
		{ _field_real, "aim speed multiplier" },
		{ _field_real, "auto zoom out time#tick delay before zooming out upon release of iron sights zoom -- use 0 for single-zoom weapons, 5-10 for multi-zooms like sniper rifle" },
		{ _field_terminator }
	};

	TAG_STRUCT(weapon_interface_struct)
	{
		{ _field_explanation, "interface", "" },
		{ _field_struct, "shared interface", &weapon_shared_interface_struct_struct_definition },
		{ _field_block, "first person", &weapon_first_person_interface_block_block },
		{ _field_tag_reference, "hud screen reference", &Tag::Reference<struct CuiScreenDefinition>::s_defaultDefinition },
		{_field_version_greater_or_equal, _engine_type_haloreach},
		{ _field_tag_reference, "alternate hud screen reference#the parent of the weapon can indicate that this hud should be used instead of the default", &Tag::Reference<struct CuiScreenDefinition>::s_defaultDefinition },
		{ _field_terminator }
	};

	TAG_STRUCT(weapon_shared_interface_struct)
	{
		{ _field_pad, "PWGUS", 16 },
		{ _field_terminator }
	};

	TAG_STRUCT(weapon_trigger_autofire_struct)
	{
		{ _field_explanation, "AUTOFIRE", "" },
		{ _field_real, "autofire time" },
		{ _field_real, "autofire throw" },
		{ _field_enum, "secondary action", &weapon_trigger_autofire_actions },
		{ _field_enum, "primary action", &weapon_trigger_autofire_actions },
		{ _field_terminator }
	};

	TAG_STRUCT(weapon_trigger_charging_struct)
	{
		{ _field_explanation, "CHARGING", "" },
		{ _field_real, "charging time:seconds#the amount of time it takes for this trigger to become fully charged" },
		{ _field_real, "charged time:seconds#the amount of time this trigger can be charged before becoming overcharged" },

		{ _field_version_less, _engine_type_haloreach, 2 },
		{ _field_enum, "overcharged action", &weapon_trigger_overcharged_actions },
		{ _field_word_flags, "flags", &weapon_trigger_charging_flags },

		{ _field_version_greater_or_equal, _engine_type_haloreach, 2 },
		{ _field_char_enum, "overcharged action", &weapon_trigger_overcharged_actions },
		{ _field_byte_flags, "flags", &weapon_trigger_charging_flags },

		{ _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_short_integer, "cancelled trigger throw#96 was the constant in code for the pp" },

		{ _field_real, "charged illumination:[0,1]#the amount of illumination given off when the weapon is fully charged" },

		{ _field_version_less, _engine_type_haloreach },
		{ _field_real, "spew time" },

		{ _field_tag_reference, "charging effect#the charging effect is created once when the trigger begins to charge", &weapon_block_struct_ready_effect_reference },
		{ _field_tag_reference, "charging damage effect#the charging effect is created once when the trigger begins to charge", &global_damage_effect_or_response_definition_reference },
		{ _field_tag_reference, "charging continuous damage response#plays every tick you\'re charging or charged, scaled to charging fraction", &global_damage_response_definition_reference },
		{ _field_real, "charged drain rate#how much battery to drain per second when charged" },
		{ _field_tag_reference, "discharge effect#the discharging effect is created once when the trigger releases its charge", &weapon_block_struct_ready_effect_reference },
		{ _field_tag_reference, "discharge damage effect#the discharging effect is created once when the trigger releases its charge", &global_damage_effect_or_response_definition_reference },

		{ _field_version_greater_or_equal, _engine_type_haloreach }, //Versioned for H3
		{ _field_block, "fire fractions", &weapon_trigger_charging_fire_fraction_block },

		{ _field_terminator }
	};

	TAG_STRUCT(weapon_barrel_firing_parameters_struct)
	{
		{ _field_real_bounds, "rounds per second#the number of firing effects created per second" },

		{ _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_string_id, "rate of fire acceleration#function value sets the current rate of fire when the barrel is firing" },

		{ _field_real, "acceleration time:seconds#the continuous firing time it takes for the weapon to achieve its final rounds per second" },

		{ _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_string_id, "rate of fire deceleration#function value sets the current rate of fire when the barrel is not firing" },

		{ _field_real, "deceleration time:seconds#the continuous idle time it takes for the weapon to return from its final rounds per second to its initial" },
		{ _field_real, "barrel spin scale#scale the barrel spin speed by this amount" },
		{ _field_real_fraction, "blurred rate of fire#a percentage between 0 and 1 which controls how soon in its firing animation the weapon blurs" },
		{ _field_short_bounds, "shots per fire#allows designer caps to the shots you can fire from one firing action" },
		{ _field_real, "fire recovery time:seconds#how long after a set of shots it takes before the barrel can fire again" },
		{ _field_real_fraction, "soft recovery fraction#how much of the recovery allows shots to be queued" },

		{ _field_version_greater_or_equal, _engine_type_haloreach, 2 },
		{ _field_real, "melee  fire recovery time:seconds#how long after a set of shots it takes before the weapon can melee" },
		{ _field_real_fraction, "melee soft recovery fraction#how much of the melee recovery allows melee to be queued" },

		{ _field_terminator }
	};

	TAG_STRUCT(weapon_barrel_firing_error_struct)
	{
		{ _field_version_less, _engine_type_haloreach },
		{ _field_real, "acceleration time:seconds" },

		{ _field_real, "deceleration time:seconds#the continuous idle time it would take for a barrel_error of 1.0 to return to its minimum value.\nMinimum value is usually 0.0 but sprinting can override this. See\n\'globals@Player information.momentum and sprinting.min weapon error\'" },
		{ _field_real_bounds, "damage error#the range of angles (in degrees) that a damaged weapon will skew fire" },

		{ _field_version_greater_or_equal, _engine_type_haloreach, 3 },
		{ _field_angle, "min error look pitch rate#yaw rate is doubled" },
		{ _field_angle, "full error look pitch rate#yaw rate is doubled" },
		{ _field_real, "look pitch error power#use to soften or sharpen the rate ding" },

		{ _field_terminator }
	};

	TAG_STRUCT(weapon_barrel_turning_struct)
	{
		{ _field_real, "base turning speed" },
		{ _field_real_bounds , "error angle" },
		{ _field_terminator }
	};

	TAG_STRUCT(weapon_barrel_dual_error_struct)
	{
		{ _field_real, "acceleration time:seconds" },
		{ _field_real, "deceleration time:seconds" },
		{ _field_real, "@unknown" },
		{ _field_real, "@unknown" },
		{ _field_real, "minimum error" },
		{ _field_real_bounds , "error angle" },
		{ _field_real, "dual wield damage scale" },
		{ _field_terminator }
	};

	TAG_STRUCT(weapon_barrel_projectile_accuracy_penalty_struct)
	{
		{ _field_custom, "accuracy penalties" },
		{ _field_real, "reload penalty#percentage accuracy lost when reloading" },
		{ _field_real, "switch penalty#percentage accuracy lost when switching weapons" },
		{ _field_real, "zoom penalty#percentage accuracy lost when zooming in/out" },
		{ _field_real, "jump penalty#percentage accuracy lost when jumping" },
		{ _field_explanation, "barrel_error penalty functions", "barrel_error = barrel_error + penaltyfunction(barrel_error)\nWhere input value \'X\' produces output value \'Y\'\n" },
		{ _field_custom, "single wield penalties" },
		{ _field_struct, "single wield penalties", &weapon_barrel_projectile_accuracy_penalty_function_struct_struct_definition },
		{ _field_custom },
		{ _field_custom, "dual wield penalties" },
		{ _field_struct, "dual wield penalties", &weapon_barrel_projectile_accuracy_penalty_function_struct_struct_definition },
		{ _field_custom },
		{ _field_custom },
		{ _field_terminator }
	};

	TAG_STRUCT(weapon_barrel_projectile_accuracy_penalty_function_struct)
	{
		{ _field_block, "firing penalty function#percentage accuracy lost when the barrel has fired", &weapon_barrel_function_block_block },
		{ _field_block, "firing crouched penalty function#percentage accuracy lost when the barrel has fired from a crouched position", &weapon_barrel_function_block_block },
		{ _field_block, "moving penalty function#percentage accuracy lost when moving", &weapon_barrel_function_block_block },
		{ _field_block, "turning penalty function#percentage accuracy lost when turning the camera", &weapon_barrel_function_block_block },
		{ _field_real, "error angle max rotation#angle which represents the maximum input to the turning penalty function." },
		{ _field_terminator }
	};

	TAG_STRUCT(weapon_barrel_damage_effect_struct)
	{
		{ _field_tag_reference, "damage effect", &global_damage_reference },
		{ _field_terminator }
	};

	STRINGS(magazine_flags)
	{
		"wastes rounds when reloaded",
		"every round must be chambered",
		"magazine cannot change state while firing#will prevent reload until fire is complete (sticky det)",
		"allow overheated reload when empty",
		"bottomless inventory"
	};
	STRING_LIST(magazine_flags, magazine_flags_strings, _countof(magazine_flags_strings));

	STRINGS(barrel_prediction_type_enum)
	{
		"none",
		"continuous",
		"instant"
	};
	STRING_LIST(barrel_prediction_type_enum, barrel_prediction_type_enum_strings, _countof(barrel_prediction_type_enum_strings));

	STRINGS(weapon_barrel_flags)
	{
		"random firing effects#rather than being chosen sequentially, firing effects are picked randomly",
		"can fire with partial ammo#allows a weapon to be fired as long as there is a non-zero amount of ammunition loaded",
		"projectiles use weapon origin#instead of coming out of the magic first person camera origin, the projectiles for this weapon actually come out of the gun",
		"ejects during chamber#this trigger\'s ejection port is started during the key frame of its chamber animation",
		"projectile vector cannot be adjusted#projectiles fired by this weapon cannot have their direction adjusted by the AI to hit the target",
		"projectiles have identical error",
		"projectiles fire parallel#If there are multiple guns for this trigger, the projectiles emerge in parallel beams (rather than independant aiming)",
		"cant fire when others firing",
		"cant fire when others recovering",
		"don\'t clear fire bit after recovering",
		"stagger fire across multiple markers",
		"can fire at maximum age",
		"use 1 firing effect per burst",
		"prevent marker deviation#the barrel will not fire if all markers are pointed further away from the desired aiming vector than the aim assist deviation angle",
		"error ignores zoom#disables of the barrel error inversely with the zoom magnification",
		"projectile fires in marker direction#projectiles shoot out the marker direction instead of the player\'s aim vector",
		"skip test for object being outside BSP#Prevents projectile origin from changing when object is outside of BSP; Useful for units that can be placed inside physics.",
		"only reload if all barrels idle",
		"only switch weapons if barrel idle#the weapon\'s owner cannot switch weapons unless this barrel is in the idle state"
	};
	STRING_LIST(weapon_barrel_flags, weapon_barrel_flags_strings, _countof(weapon_barrel_flags_strings));

	STRINGS(weapon_barrel_distribution_functions)
	{
		"point",
		"horizontal fan",
		"custom vectors",
		"custom positions"
	};
	STRING_LIST(weapon_barrel_distribution_functions, weapon_barrel_distribution_functions_strings, _countof(weapon_barrel_distribution_functions_strings));

	STRINGS(weapon_barrel_angle_change_functions)
	{
		"linear",
		"early",
		"very early",
		"late",
		"very late",
		"cosine",
		"one",
		"zero"
	};
	STRING_LIST(weapon_barrel_angle_change_functions, weapon_barrel_angle_change_functions_strings, _countof(weapon_barrel_angle_change_functions_strings));

	STRINGS(weapon_trigger_inputs)
	{
		"right trigger",
		"left trigger",
		"melee attack",
		"ai only secondary"
	};
	STRING_LIST(weapon_trigger_inputs, weapon_trigger_inputs_strings, _countof(weapon_trigger_inputs_strings));

	STRINGS(weapon_trigger_overcharged_actions)
	{
		"none",
		"explode",
		"discharge"
	};
	STRING_LIST(weapon_trigger_overcharged_actions, weapon_trigger_overcharged_actions_strings, _countof(weapon_trigger_overcharged_actions_strings));

	STRINGS(weapon_trigger_behaviors)
	{
		"spew#fires its primary action barrel whenever the trigger is down",
		"latch#fires its primary action barrel when the trigger is down and then latches",
		"latch-autofire#fires its primary action barrel once if pulsed quickly or if not depressed all the way, otherwise does secondary behavior",
		"latch-tether#tethers projectiles if latched long enough, on release the tethered projectile detonates",
		"charge#charges the trigger",
		"latch-zoom#latched; fires its primary action barrel when unzoomed, secondary when zoomed",
		"spew-charge",
		"sword-charge",
		"paint-target",
		"double-latch-tether#projectile is tethered by 1st latch, 2nd releases and detonates it",
		"charge-with-magazine#like charge, but pays attention to any magazine and will not charge unless magazine is idle and barrel is actually able to fire"
	};
	STRING_LIST(weapon_trigger_behaviors, weapon_trigger_behaviors_strings, _countof(weapon_trigger_behaviors_strings));

	STRINGS(weapon_trigger_autofire_actions)
	{
		"fire",
		"charge",
		"fire other"
	};
	STRING_LIST(weapon_trigger_autofire_actions, weapon_trigger_autofire_actions_strings, _countof(weapon_trigger_autofire_actions_strings));

	STRINGS(trigger_prediction_type_enum)
	{
		"none",
		"spew",
		"charge"
	};
	STRING_LIST(trigger_prediction_type_enum, trigger_prediction_type_enum_strings, _countof(trigger_prediction_type_enum_strings));

	STRINGS(weapon_trigger_definition_flags)
	{
		"autofire single action only"
	};
	STRING_LIST(weapon_trigger_definition_flags, weapon_trigger_definition_flags_strings, _countof(weapon_trigger_definition_flags_strings));

	STRINGS(weapon_trigger_charging_flags)
	{
		"can fire from partial charge#discharging a partially charged weapon will spew for the charged fraction of the spew time set below",
		"limit to current rounds loaded#if magazine present, do not fire more than current rounds loaded (mantis rocket launcher)",
		"Wont charge unless tracked target is valid#spew-charge triggers only"
	};
	STRING_LIST(weapon_trigger_charging_flags, weapon_trigger_charging_flags_strings, _countof(weapon_trigger_charging_flags_strings));

	STRINGS(weapon_definition_flags)
	{
		"vertical heat display",
		"mutually exclusive triggers",
		"attacks automatically on bump",
		"must be readied",
		"doesn\'t count toward maximum",
		"aim assists only when zoomed",
		"prevents grenade throwing",
		"must be picked up",
		"holds triggers when dropped",
		"prevents melee attack",
		"detonates when dropped",
		"cannot fire at maximum age",
		"secondary trigger overrides grenades",
		"support weapon",
		"hide FP weapon when in iron sights#for scoped weapons",
		"AIs use weapon melee damage",
		"allows binoculars",
		"loop fp firing animation",
		"prevents crouching",
		"cannot fire while boosting",
		"use empty melee on empty",
		"uses 3rd person camera",
		"can be dual wielded",
		"can only be dual wielded",
		"melee only",
		"cant fire if parent dead",
		"weapon ages with each kill#see \'weapon ages when damage is inflicted\', \'per kill or hit aging amount\'",
		"allows unaimed lunge",
		"cannot be used by player",
		"hold fp firing animation",
		"strict deviation angle#deviation angle is allowed to be less than primary autoaim angle - for the rocket launcher",
		"notifies target units#aiming this weapon at another player can be important to them - for lock-on weapons"
	};
	STRING_LIST(weapon_definition_flags, weapon_definition_flags_strings, _countof(weapon_definition_flags_strings));

	STRINGS(weapon_definition_secondary_flags)
	{
		"magnetizes only when zoomed",
		"force enable equipment tossing",
		"non-lunge melee dash disabled#melee-physics dash is disabled on melees that are not lunges",
		"don\'t drop on dual wield melee",
		"is equipment special weapon#when checked, this weapon\n-is deleted when dropped\n-does not count against maximum inventory\n-gets deleted on host migrations\n-prevents swapping or switching weapons",
		"uses ghost reticle",
		"never overheats",
		"force tracers to come from weapon barrel#setting this forces effects tracers to come from weapon barrel instead of eye point",
		"cannot fire during emp",
		"weapon can headshot",
		"AI cannot fire tracking projectiles#setting this will remove tracking data from AI-fired projectiles",
		"second barrel fires if friend is targeted#bishop beam support- primary barrel fires if foe is targeted, secondary if targeting friend",
		"weapon unzooms on damage#taking damage while wielding this will ping player out of zoom/iron sights",
		"do not drop on equipment activation#will counteract default support weapon behavior to drop on equipment activation",
		"weapon can not be dropped#used for CTF magnum, weapon can not be dropped or swapped out",
		"disable function overlays during reload",
		"throw weapon instead of grenade#Throws weapon when grenade trigger is pressed",
		"do not drop \'must be readied\' on primary trigger#Allows \'must be readied\' weapons to have a primary attack",
		"delete on drop",
		"allow melee when using device#Default behavior prevents melee attacks when using device.  Setting this bit allows them.",
		"do not lower weapon when using device#Default behavior lowers weapon when using device.  Setting this leaves the weapon up.",
		"cannot fire while zooming",
		"weapon ages when damage is inflicted#see \'weapon ages with each kill\', \'per kill or hit aging amount\'",
		"apply gunner armor mod abilites#Apply weapon\'s gunner armor mod movement penalty multipliers rather than base multipliers when gunner armor mod is active in _trait_weapons_gunner_armor_modifier",
		"wielders sprint is unaffected by soft ping#see momentum globals \'disable soft ping check\'",
		"weapon drops further away#Adds velocity to weapon\'s default drop (useful for weapons with auto-pickup)",
		"use automatic firing looping sounds",
		"do not drop on assassination#Keeps the weapon in your hand while being assassinated or performing an assassination (for must_be_readied or support weapons)",
		"is part of body#Keeps the weapon from dropping or being hidden at the start of assassinations, and must instead be dropped using the drop weapon keyframe",
		"force deny equipment use#Disallows any equipment usage while holding this weapon regardless of any other traits you may have",
		"hide pickup prompt unless special pickup priority#Used for Oddball that only shows the pickup prompt when megalo script sets pickup priority to special",
		"weapon ignores player_pickup_allowed trait#Player will always pickup this weapon if requested, Used for CTF that needs to force storm_magnum_ctf onto the player"
	};
	STRING_LIST(weapon_definition_secondary_flags, weapon_definition_secondary_flags_strings, _countof(weapon_definition_secondary_flags_strings));

	STRINGS(secondary_trigger_modes)
	{
		"normal",
		"slaved to primary",
		"inhibits primary",
		"loads alterate ammunition",
		"loads multiple primary ammunition"
	};
	STRING_LIST(secondary_trigger_modes, secondary_trigger_modes_strings, _countof(secondary_trigger_modes_strings));

	STRINGS(movement_penalty_modes)
	{
		"always",
		"when zoomed",
		"when zoomed or reloading"
	};
	STRING_LIST(movement_penalty_modes, movement_penalty_modes_strings, _countof(movement_penalty_modes_strings));

	STRINGS(multiplayer_weapon_types)
	{
		"none",
		"ctf flag",
		"oddball ball",
		"headhunter head",
		"juggernaut pPowerup",
	};
	STRING_LIST(multiplayer_weapon_types, multiplayer_weapon_types_strings, _countof(multiplayer_weapon_types_strings));

	STRINGS(weapon_types)
	{
		"undefined",
		"shotgun",
		"needler",
		"plasma pistol",
		"plasma rifle",
		"rocket launcher",
		"energy blade",
		"splaser",
		"shield",
		"scarab gun",
		"wolverine quad",
		"flak cannon",
		"plasma launcher",
		"laser designator",
		"sticky detonator"
	};
	STRING_LIST(weapon_types, weapon_types_strings, _countof(weapon_types_strings));

	STRINGS(tracking_types)
	{
		"no tracking",
		"human tracking",
		"plasma tracking"
	};
	STRING_LIST(tracking_types, tracking_types_strings, _countof(tracking_types_strings));

	STRINGS(first_time_pickup_types)
	{
		"unassigned",
		"bolt pistol",
		"light rifle",
		"suppressor",
		"binary rifle",
		"scattershot",
		"incineration cannon"
	};
	STRING_LIST(first_time_pickup_types, first_time_pickup_types_strings, _countof(first_time_pickup_types_strings));

	STRINGS(global_melee_class_enum_definition)
	{
		"default class",
		"elite class"
	};
	STRING_LIST(global_melee_class_enum_definition, global_melee_class_enum_definition_strings, _countof(global_melee_class_enum_definition_strings));

	STRINGS(weapon_screen_effect_flags)
	{
		"overrides unit and camera screen effects",
		"unzoomed",
		"zoom level 1",
		"zoom level 2"
	};
	STRING_LIST(weapon_screen_effect_flags, weapon_screen_effect_flags_strings, _countof(weapon_screen_effect_flags_strings));

	STRINGS(weaponScaleshotLevelFlags)
	{
		"cannot gain power at this level#if true, as long as the weapon is at this level, you cannot gain positive power, only negative values are applied"
	};
	STRING_LIST(weaponScaleshotLevelFlags, weaponScaleshotLevelFlags_strings, _countof(weaponScaleshotLevelFlags_strings));

	STRINGS(weaponScaleshotFlags)
	{
		"level latches#if true, once you hit a power level, you stay at that level or higher until your power value hits 0; otherwise your power level is recomputed constantly"
	};
	STRING_LIST(weaponScaleshotFlags, weaponScaleshotFlags_strings, _countof(weaponScaleshotFlags_strings));

	TAG_REFERENCE(global_weapon_reference, WEAPON_TAG);

	TAG_REFERENCE(crate_projectile_reference, CRATE_TAG);

} // namespace blofeld

