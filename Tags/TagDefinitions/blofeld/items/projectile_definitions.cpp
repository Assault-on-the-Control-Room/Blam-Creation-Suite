#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(KillCamCameraParamter, KILLCAMCAMERAPARAMTER_TAG, KillCamCameraParamter_block_block );

	TAG_GROUP_INHERIT_FROM_BLOCK(projectile, PROJECTILE_TAG, object, OBJECT_TAG, projectile_block_block );

	TAG_BLOCK_FROM_STRUCT(KillCamCameraParamter_block, 1, KillCamCameraParamter_struct_definition_struct_definition );

	TAG_BLOCK(old_projectile_material_response_block, k_maximum_material_responses)
	{
		{ _field_explanation, "default result", "(if the potential result, below, fails to happen)" },
		{ _field_enum, "default response", &material_response },
		{ _field_pad, "KJSH", 2 },
		{ _field_string_id, "material name" },
		{ _field_short_integer, "runtime material index!" },
		{ _field_pad, "JJHT", 2 },
		{ _field_useless_pad },
		{ _field_explanation, "potential result", "" },
		{ _field_enum, "potential response", &material_response },
		{ _field_word_flags, "response flags", &material_possible_response_flags },
		{ _field_real_fraction, "chance fraction:[0,1]" },
		{ _field_angle_bounds, "between:degrees" },
		{ _field_real_bounds, "and:world units per second" },
		{ _field_useless_pad },
		{ _field_explanation, "misc", "" },
		{ _field_enum, "scale effects by", &effect_scale_enum },
		{ _field_pad, "BDFI", 2 },
		{ _field_angle, "angular noise:degrees#the angle of incidence is randomly perturbed by at most this amount to simulate irregularity." },
		{ _field_real, "velocity noise:world units per second#the velocity is randomly perturbed by at most this amount to simulate irregularity." },
		{ _field_useless_pad },
		{ _field_explanation, "penetration", "" },
		{ _field_real, "initial friction#the fraction of the projectile\'s velocity lost on penetration" },
		{ _field_explanation, "reflection", "" },
		{ _field_real, "parallel friction#the fraction of the projectile\'s velocity parallel to the surface lost on impact" },
		{ _field_real, "perpendicular friction#the fraction of the projectile\'s velocity perpendicular to the surface lost on impact" },
		{ _field_terminator }
	};

	TAG_BLOCK(projectile_material_response_block, k_maximum_material_responses)
	{
		{ _field_explanation, "matching criteria", "" },
		{ _field_string_id, "material name" },
		{ _field_short_integer, "runtime material index!" },
		{ _field_word_flags, "response flags", &material_possible_response_flags },
		{ _field_real_fraction, "chance fraction:[0,1]" },
		{ _field_angle_bounds, "between:degrees" },
		{ _field_real_bounds, "and:world units per second" },
		{ _field_explanation, "response", "" },
		{ _field_enum, "response", &material_response },
		{ _field_explanation, "misc", "" },
		{ _field_enum, "scale effects by", &effect_scale_enum },
		{ _field_angle, "angular noise:degrees#the angle of incidence is randomly perturbed by at most this amount to simulate irregularity." },
		{ _field_real, "velocity noise:world units per second#the velocity is randomly perturbed by at most this amount to simulate irregularity." },
		{ _field_explanation, "overpenetration", "" },
		{ _field_real, "initial friction#the fraction of the projectile\'s velocity lost on penetration" },
		{ _field_explanation, "reflection", "" },
		{ _field_real, "parallel friction#the fraction of the projectile\'s velocity parallel to the surface lost on impact" },
		{ _field_real, "perpendicular friction#the fraction of the projectile\'s velocity perpendicular to the surface lost on impact" },
		{ _field_terminator }
	};

	TAG_BLOCK(brute_grenade_block, 1)
	{
		{ _field_angle, "minimum angular vel#degrees/sec" },
		{ _field_angle, "maximum angular vel#degrees/sec" },
		{ _field_angle, "spin angular vel#degrees/sec" },
		{ _field_real, "angular damping#0==nothing 30==almost comlete damping" },
		{ _field_real, "drag angle k" },
		{ _field_real, "drag speed k" },
		{ _field_real, "drag exponent" },
		{ _field_real, "attach sample radius" },
		{ _field_real, "attach acc k" },
		{ _field_real, "attach acc s" },
		{ _field_real, "attach acc e" },
		{ _field_real, "attach acc damping" },
		{ _field_terminator }
	};

	TAG_BLOCK(fire_bomb_grenade_block, 1)
	{
		{ _field_real, "projection offset" },
		{ _field_terminator }
	};

	TAG_BLOCK(conical_projection_block, 1)
	{
		{ _field_explanation, "conical_projection: AKA shotgun", "projectile_count = yaw_count*pitch_count\nThis block has no effect if _projectile_disable_instantaneous_first_tick is set or projectile has not been fired from a weapon." },
		{ _field_short_integer, "yaw count" },
		{ _field_short_integer, "pitch count" },
		{ _field_real, "distribution exponent#exp==.5 even distribution, exp==1  halo2 distribution, exp>1== weighted towards center" },
		{ _field_angle, "spread#degrees" },
		{ _field_terminator }
	};

	TAG_BLOCK(ProjectileSoundRTPCBlock, k_maxProjectileSoundRTPCBlocks)
	{
		{ _field_long_block_index, "Attachment Index#Sound attachment to affect - leave empty for main body" },
		{ _field_string_id, "Function#Function to drive the RTPC" },
		{ _field_string_id, "RTPC Name#WWise RTPC string name" },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(projectile_block, 1, projectile_group_struct_definition );

	TAG_STRUCT(KillCamCameraParamter_struct_definition)
	{
		{ _field_real, "distance from camera" },
		{ _field_real, "height above object" },
		{ _field_real, "minimum velocity to update" },
		{ _field_terminator }
	};

	TAG_STRUCT(projectile_group)
	{
		{ _field_struct, "object", &object_struct_definition_struct_definition },
		{ _field_custom, "$$$ PROJECTILE $$$" },
		{ _field_long_flags, "flags", &projectile_flags },

		{ _field_version_greater, _engine_type_haloreach },
		{ _field_long_flags, "secondary flags", &secondary_projectile_flags },

		{ _field_enum, "detonation timer starts", &projectile_detonation_timer_modes },
		{ _field_enum, "impact noise", &ai_sound_volume_enum },

		{ _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_real, "detonation biped proximity:wu#if >0, both \'detonation timer starts\' + a biped must be within this proximity for condition to be met; see \'biped proximity enemies only\' flag" },
		{ _field_real, "max lifetime to detonate:seconds#if >0, projectile will detonate regardless of other conditions after this total time" },

		{ _field_real, "collision radius:world units" },
		{ _field_explanation, "detonation", "" },
		{ _field_real, "arming time:seconds#won\'t detonate before this time elapses" },
		{ _field_real, "danger radius:world units" },
		{ _field_real, "danger stimuli radius:world units#Overrides the danger radius when non-zero for stimuli related danger radius calculations." },
		{ _field_short_integer, "danger group burst count#The number of projectiles in this burst before this burst is considered dangerous" },
		{ _field_short_integer, "danger group burst max count#The maximum number of projectiles we allow in a group" },
		{ _field_real_bounds, "timer:seconds#detonation countdown (zero is untimed)" },
		{ _field_real, "minimum velocity:world units per second#detonates when slowed below this velocity" },
		{ _field_real, "maximum range:world units#detonates after travelling this distance" },
		{ _field_real, "bounce maximum range:world units#detonates after travelling this distance, but is reset after a bounce.  Combines with maximum range" },
		{ _field_real, "max latch time to detonate:seconds#projectile will detonate regardless of weapon latching after this total time" },
		{ _field_real, "max latch time to arm:seconds#projectile will arm itself regardless of detonation mode if latched for this amount of time." },
		{ _field_enum, "detonation noise", &ai_sound_volume_enum },
		{ _field_short_integer, "super det. projectile count" },
		{ _field_real, "super det. time" },

		{ _field_version_greater, _engine_type_haloreach, 3 },
		{ _field_real_bounds, "super det. range:world units#The range within which supercombine will happen - outside this range, no supercombine" },
		{ _field_tag_reference, "super det. behavior#An equipment reference that is attached to the target upon super detonation", &behavior_object_reference },
		{ _field_real, "tether release safety delay#if the weapon the projectile is tethered to loses its owner, this amount of time will pass before detonation" },

		{ _field_explanation, "tethering", "A detonating tethered projectile attached to an object will use the \'super\' versions of damage ie \'super attached detonation damage\' instead of \'attached detonation damage\'." },
		{ _field_tag_reference, "detonation started#effect", &global_effect_reference },
		{ _field_tag_reference, "detonation effect (airborne)", &global_effect_reference },
		{ _field_tag_reference, "detonation effect (ground)", &global_effect_reference },
		{ _field_tag_reference, "detonation damage", &global_damage_reference },

		{ _field_version_greater, _engine_type_haloreach },
		{ _field_tag_reference, "detonation behavior#An equipment reference that is attached to the target upon detonation", &behavior_object_reference },

		{ _field_tag_reference, "attached detonation damage", &global_damage_reference },
		{ _field_tag_reference, "super detonation", &global_effect_reference },
		{ _field_struct, "your momma", &super_detonation_damage_struct_struct_definition },
		{ _field_tag_reference, "detonation sound", &global_sound_reference },
		{ _field_char_enum, "damage reporting type", &global_damage_reporting_enum_definition },
		{ _field_pad, "UAQLONXGN", 1 },
		{ _field_word_flags, "super detonation object types", &object_type_enum_definition },
		{ _field_tag_reference, "super attached detonation damage", &global_damage_reference },
		{ _field_real, "material effect radius#radius within we will generate material effects" },
		{ _field_explanation, "flyby/impact", "" },
		{ _field_tag_reference, "flyby sound", &global_sound_reference },
		{ _field_tag_reference, "flyby damage response", &global_damage_response_definition_reference },
		{ _field_real, "flyby damage response max distance" },
		{ _field_tag_reference, "impact effect", &global_effect_reference },
		{ _field_tag_reference, "object impact effect", &global_effect_reference },
		{ _field_tag_reference, "impact damage", &global_damage_reference },
		{ _field_explanation, "boarding fields", "" },
		{ _field_real, "boarding detonation time" },
		{ _field_tag_reference, "boarding detonation damage", &global_damage_reference },
		{ _field_tag_reference, "boarding attached detonation damage", &global_damage_reference },
		{ _field_explanation, "physics", "damage range low is unused unless \'distance based damage scaling uses damage range low bounds\' flag is true." },
		{ _field_real, "air gravity scale#the proportion of normal gravity applied to the projectile when in air." },
		{ _field_real_bounds, "air damage range:world units#the range over which damage is scaled when the projectile is in air." },
		{ _field_real, "water gravity scale#the proportion of normal gravity applied to the projectile when in water." },
		{ _field_real_bounds, "water damage range:world units#the range over which damage is scaled when the projectile is in water." },
		{ _field_real, "initial velocity:world units per second#bullet\'s velocity when inflicting maximum damage" },
		{ _field_real, "final velocity:world units per second#bullet\'s velocity when inflicting minimum damage" },
		{ _field_real, "indirect fire velocity:world units per second#base velocity used for ballistics calculations for indirect firing." },
		{ _field_real, "ai velocity scale (normal):[0-1]#scale on the initial velocity when fired by the ai on normal difficulty (0 defaults to 1.0" },
		{ _field_real, "ai velocity scale (heroic):[0-1]#scale on the initial velocity when fired by the ai on heroic difficulty (0 defaults to 1.0)" },
		{ _field_real, "ai velocity scale (legendary):[0-1]#scale on the initial velocity when fired by the ai on legendary difficulty (0 defaults to 1.0)" },
		{ _field_real, "ai guided angular velocity scale (normal):[0-1]#scale on the guided angular velocity when fired by the ai on normal difficulty (0 defaults to 1.0" },
		{ _field_real, "ai guided angular velocity scale (legendary):[0-1]#scale on the guided angular velocity when fired by the ai on legendary difficulty (0 defaults to 1.0)" },
		{ _field_struct, "blah", &angular_velocity_lower_bound_struct_struct_definition },
		{ _field_angle, "guided angular velocity (upper):degrees per second" },
		{ _field_angle, "guided angular velocity at rest:degrees per second" },
		{ _field_real_bounds, "acceleration range:world units#what distance range the projectile goes from initial velocity to final velocity" },
		{ _field_real, "runtime acceleration bound inverse!" },
		{ _field_real_fraction, "targeted leading fraction" },
		{ _field_real, "guided projectile (outer range) error radius" },
		{ _field_real, "autoaim leading max lead time" },
		{ _field_block, "old material responses{material responses}!", &old_projectile_material_response_block_block },
		{ _field_block, "material response", &projectile_material_response_block_block },
		{ _field_block, "brute grenade", &brute_grenade_block_block },
		{ _field_block, "fire bomb grenade", &fire_bomb_grenade_block_block },
		{ _field_block, "conical spread", &conical_projection_block_block },
		{ _field_tag_reference, "grounded friction settings#If not present, the default from global.globals is used.", &global_grounded_friction_reference },

		{ _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_tag_reference, "killcam parameters# if not present, first person will be used.", &Tag::Reference<struct KillCamCameraParameterDefinition>::s_defaultDefinition },
		{ _field_block, "Sound RTPCs", &ProjectileSoundRTPCBlock_block },

		{ _field_custom },
		{ _field_terminator }
	};

	TAG_STRUCT(super_detonation_damage_struct)
	{
		{ _field_tag_reference, "super detonation damage", &global_damage_reference },
		{ _field_terminator }
	};

	TAG_STRUCT(angular_velocity_lower_bound_struct)
	{
		{ _field_angle, "guided angular velocity (lower):degrees per second" },
		{ _field_terminator }
	};

	STRINGS(effect_scale_enum)
	{
		"damage",
		"angle"
	};
	STRING_LIST(effect_scale_enum, effect_scale_enum_strings, _countof(effect_scale_enum_strings));

	STRINGS(material_response)
	{
		"impact (detonate)",
		"fizzle",
		"overpenetrate",
		"attach",
		"bounce",
		"bounce (dud)",
		"fizzle (ricochet)",
		"turn physical"
	};
	STRING_LIST(material_response, material_response_strings, _countof(material_response_strings));

	STRINGS(material_possible_response_flags)
	{
		"only against units (except giants){only against units}",
		"never against units (except giants){never against units}",
		"only against bipeds",
		"only against vehicles",
		"never against wuss players",
		"only when tethered",
		"only when not tethered",
		"only against dead bipeds",
		"never against dead bipeds",
		"only AI projectiles",
		"never AI projectiles"
	};
	STRING_LIST(material_possible_response_flags, material_possible_response_flags_strings, _countof(material_possible_response_flags_strings));

	STRINGS(projectile_flags)
	{
		"oriented along velocity",
		"AI must use ballistic aiming",
		"detonation max time if attached#If attach happens timeout is set to timer.high",
		"damage scales based on distance",
		"steering adjusts orientation",
		"don\'t noise up steering",
		"can track behind itself",
		"ROBOTRON STEERING#or robotech, maybe",
		"affected by phantom volumes",
		"notifies target units",
		"use ground detonation when attached",
		"AI minor tracking threat",
		"dangerous when inactive",
		"AI stimulus when attached",
		"OverPeneDetonation",
		"no impact effects on bounce",
		"RC1 overpenetration fixes",
		"Disable instantaneous first tick",
		"Constrain gravity to velocity bounds",
		"allow deceleration below final velocity#use for bouncing projectiles that also have initial/final velocity so that can reliably come to rest.",
		"supports tethering#projectile waits for trigger unlatch before immediately detonating",
		"damage_not_predictable_by_clients#used on the focus rifle to disable observer shield flash prediction for a high-dps weapon that does low damage per projectile",
		"collides with physics-only surfaces#aka sphere-only collision.  Use this for projectiles that you want to bounce smoothly up stairs, but don\'t use it for projectiles that may come to rest on stairs",
		"detonates when attached to objects#when projectiles move slowly enough they attach to objects or come to rest.  Check this for projectiles that don\'t normally attach to things like frag grenades",
		"cannot be detached by equipment#armor lock will not detach these projectiles - for the airstrike",
		"always attach regardless of material",
		"does not collide with world geometry#this gun shoots through schools",
		"is collectible#Projectile is collectible by projectile collector equipment",
		"continuous damage while attached and tethered",
		"combinations of projectiles from different weapons or different bursts of the same weapon will not trigger super combine detonation",
		"distance based damage scaling uses damage range low bounds#damage scales from 1.f --> 0.f  between \'damage range - low\' --> \'damage range - high\'",
		"skip object first tick#similar to Disable instantaneous first tick, but there\'s actually two types of ticks"
	};
	STRING_LIST(projectile_flags, projectile_flags_strings, _countof(projectile_flags_strings));

	STRINGS(secondary_projectile_flags)
	{
		"Use projectile radius for thickness testing#IF THIS IS OFF, NO THICKNESS OR CHUBBY TESTS ARE PERFORMED.",
		"Expensive chubby test#Will only be active if thickness testing is ON.",
		"Use play collision#Will use simple and smooth collision mesh.",
		"Highlight projectile in vision mode#Makes the projectile show up as an enemy in vision mode",
		"biped proximity enemies only#modifies behavior of \'detonation biped proximity\'",
		"always use localized physics#overrides early mover localize projectiles",
		"never use localized physics#overrides early mover localize projectiles"
	};
	STRING_LIST(secondary_projectile_flags, secondary_projectile_flags_strings, _countof(secondary_projectile_flags_strings));

	STRINGS(projectile_detonation_timer_modes)
	{
		"immediately",
		"after first bounce off floor{after first bounce}",
		"when at rest",
		"after first bounce off any surface"
	};
	STRING_LIST(projectile_detonation_timer_modes, projectile_detonation_timer_modes_strings, _countof(projectile_detonation_timer_modes_strings));

	TAG_REFERENCE(behavior_object_reference, OBJECT_TAG);

} // namespace blofeld

