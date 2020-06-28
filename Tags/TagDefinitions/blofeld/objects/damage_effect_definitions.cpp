#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(damage_effect, DAMAGE_EFFECT_TAG, damage_effect_block_block );

	TAG_BLOCK(custom_damage_response_label_block, 8)
	{
		{ _field_string_id, "custom label#label used to control what damage response will fire.^" },
		{ _field_terminator }
	};

	TAG_BLOCK(damage_effect_sound_block, 4)
	{
		{ _field_tag_reference, "sound", &global_sound_reference },
		{ _field_word_flags, "damage types", &damage_effect_sound_type_flags },
		{ _field_word_flags, "object types", &object_type_enum_definition },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(damage_effect_block, 1, damage_effect_group_struct_definition );

	TAG_STRUCT(damage_effect_group)
	{
		{ _field_version_greater, _engine_type_haloreach },
		{ _field_tag_reference, "area of effect behavior equipment#if a reference is here, area of effect damage will attach the equipment to the target", &behavior_object_reference },
		
		{ _field_real_bounds, "radius:world units" },
		{ _field_real_fraction, "cutoff scale:[0,1]" },
		{ _field_long_flags, "effect flags", &damage_effect_flags },
		{ _field_explanation, "damage", "" },
		{ _field_enum, "side effect", &damage_side_effects },
		{ _field_enum, "category", &damage_categories },
		{ _field_long_enum, "death vocalization", &damage_death_vocalizations },
		{ _field_long_flags, "flags", &damage_flags },

		{ _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_long_flags, "secondary flags", &damageSecondaryFlags },
		{ _field_real, "headshot damage multiplier#ignored if zero or if headshot flag is not set above; \notherwise, makes headshot not instantly lethal, but multiplies damage done to head by this much.  \n2 does 2x damage to head for headshot.  note that head still has different health than body." },
		
		{ _field_real, "AOE core radius:world units#if >0 then higher fidelity obstruction collision checks are preformed. This field has no other ramifications." },
		{ _field_real, "damage lower bound" },
		{ _field_real_bounds, "damage upper bound" },
		{ _field_struct, "damage falloff function", &scalar_function_named_struct_struct_definition },
		{ _field_angle, "dmg inner cone angle" },
		{ _field_struct, "blah", &damage_outer_cone_angle_struct_struct_definition },
		{ _field_real, "active camouflage damage:[0,1]#how much more visible this damage makes a player who is active camouflaged" },
		{ _field_real, "stun:[0,1]#amount of stun added to damaged unit" },
		{ _field_real, "maximum stun:[0,1]#damaged unit\'s stun will never exceed this amount" },
		{ _field_real, "stun time:seconds#duration of stun due to this damage" },
		{ _field_long_integer, "damage stun:ticks#how long we stun recovering current body damage" },
		{ _field_real, "instantaneous acceleration:[0,+inf]" },

		{ _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_real, "alt instantaneous acceleration:[0,+inf]#This field can be used for an alternative acceleration if the corresponding flags are set, e.g. check vehicle->flags.vehicle wants reduced weapon impulse when airborne" },
		{ _field_real, "acceleration cap#set to zero to disable cap" },
		
		{ _field_useless_pad },
		{ _field_useless_pad },
		{ _field_explanation, "DEPRECATED - rider damage scales", "" },
		{ _field_real, "rider direct damage scale" },
		{ _field_real, "rider maximum transfer damage scale" },
		{ _field_real, "rider minimum transfer damage scale" },

		{ _field_version_greater, _engine_type_haloreach },
		{ _field_real, "vehicle damage multiplier" },
		
		{ _field_real_fraction, "soft ping pain screen scale:[0,1]#The maximum amount to apply the pain screen pose overlay" },
		{ _field_useless_pad },
		{ _field_string_id, "general_damage" },
		{ _field_string_id, "specific_damage" },
		{ _field_block, "custom response labels", &custom_damage_response_label_block_block },
		{ _field_real, "AI stun radius:world units" },
		{ _field_real_bounds, "AI stun bounds:(0-1)" },
		{ _field_real, "shake radius" },
		{ _field_real, "EMP radius" },
		{ _field_real, "aoe spike radius" },
		{ _field_real, "aoe spike damage bump" },
		{ _field_real, "shield render effects scale" },

		{ _field_version_greater, _engine_type_haloreach, 17 },
		{ _field_long_integer, "stasis time:ticks#duration of stasis due to this damage, zero disables" },
		{ _field_real, "stasis time dilation" },
		{ _field_real, "stasis max biped turning rate" },
		{ _field_real, "stasis gravity multiplier" },
		{ _field_real, "equipment hack time:seconds" },
		{ _field_explanation, "if \'Apply Tree Of Life\'", "" },
		{ _field_real, "tree_of_life shield regen modifier#regen velocity of TOL:if non-1.0 this overrides any \'shield recharge rate\' trait" },
		{ _field_real, "minimum shield level:[0, 1]#when hit, shield will be reset to this percentage of full strength if it is below" },
		{ _field_real, "shield stun time:seconds#time after damage applied before shield recharges" },
		{ _field_real, "minimum health level:[0, 1]#when hit, health will be reset to this percentage of full health if it is below" },
		{ _field_real, "health stun time:seconds#time after damage applied before health recharges" },
		{ _field_real, "minimum energy level:[0, 1]#like above, TOL reset minimum equipment energy to this" },
		{ _field_real, "maximum energy level:[0, 1]#cap equipment energy to this" },
		{ _field_real, "equipment stun time:seconds#time after damage applied before equipment recharges" },
		{ _field_explanation, "Modifies TOL logic so that (above) unstun will only happen if (below) minimum stun time has passed", "" },
		{ _field_real, "shield minimum stun time:seconds" },
		{ _field_real, "health minimum stun time:seconds" },
		
		{ _field_explanation, "damage response", "" },
		{ _field_tag_reference, "damage response", &global_damage_response_definition_reference },
		{ _field_explanation, "sound", "" },
		{ _field_tag_reference, "old melee sound{sound}", &global_sound_reference },
		{ _field_block, "damage sounds", &damage_effect_sound_block_block },
		{ _field_useless_pad },
		{ _field_explanation, "breaking effect", "Controls particle velocities when a damage effect shatters a materal.\n\nAll particles created within \'forward radius\' will be kicked along the\ndamage direction with a speed equivalent to \'forward velocity\' at the\nepicenter of the damage and 0 at the outer radius.  \'Forward exponent\'\nis used to modify the velocity scale.  A low exponent (like 0.5) means that\nparticles between the epicenter and the radius will be kicked out with a speed\ncloser to \'forward velocity\' than if a higher exponent (like 2.0) was used\n\nThe outward fields work in a similar way, except instead of kicking along the\ndamage direction, they get kick away from the damage epicenter." },
		{ _field_real, "forward velocity:world units per second" },
		{ _field_real, "forward radius:world units" },
		{ _field_real, "forward exponent" },
		{ _field_useless_pad },
		{ _field_real, "outward velocity:world units per second" },
		{ _field_real, "outward radius:world units" },
		{ _field_real, "outward exponent" },
		{ _field_useless_pad },
		{ _field_terminator }
	};

	TAG_STRUCT(damage_outer_cone_angle_struct)
	{
		{ _field_angle, "dmg outer cone angle" },
		{ _field_terminator }
	};

	STRINGS(damage_side_effects)
	{
		"none",
		"harmless",
		"lethal to the unsuspecting",
		"emp"
	};
	STRING_LIST(damage_side_effects, damage_side_effects_strings, _countof(damage_side_effects_strings));

	STRINGS(damage_categories)
	{
		"none",
		"falling",
		"bullet",
		"grenade",
		"high explosive",
		"sniper",
		"melee",
		"flame",
		"mounted weapon",
		"vehicle",
		"plasma",
		"needle",
		"shotgun",
		"assassinated"
	};
	STRING_LIST(damage_categories, damage_categories_strings, _countof(damage_categories_strings));

	STRINGS(damage_death_vocalizations)
	{
		"default#uses code to figure out what vocalization to use",
		"dth",
		"dth_fall",
		"dth_mjr",
		"dth_slw",
		"dth_hdsht",
		"dth_slnt",
		"dth_drama",
		"dth_reanimated",
		"thrwn",
		"die_space",
		"die_ass"
	};
	STRING_LIST(damage_death_vocalizations, damage_death_vocalizations_strings, _countof(damage_death_vocalizations_strings));

	STRINGS(damage_flags)
	{
		"does not hurt owner",
		"can cause headshots",
		"ignores headshot obstructions#arms, held weapons, attachments",
		"pings resistant units",
		"does not hurt friends#affects aoe only",
		"does not ping units",
		"detonates explosives",
		"only hurts shields",
		"causes flaming death",
		"skips shields",
		"transfer dmg always uses min",
		"ignore seat scale for dir. dmg",
		"forces hard ping if body dmg{forces hard ping}",
		"forces hard ping always",
		"does not hurt players",
		"enables special death",
		"cannot cause betrayals",
		"uses old EMP behavior",
		"ignores damage resistance",
		"force s_kill on death",
		"cause magic deceleration",
		"aoe skip obstruction test",
		"does not spill over",
		"does not hurt boarders",
		"does not cause biped aoe effect",
		"causes biped \'knockback\'",
		"apply tree of life#as if a tree of life was near \'victim\'",
		"hurt only friends#affects aoe only",
		"causes incineration dissolve",
		"causes incineration dissolve on headshot",
		"does not hurt damage source",
		"damage vehicles only"
	};
	STRING_LIST(damage_flags, damage_flags_strings, _countof(damage_flags_strings));

	STRINGS(damageSecondaryFlags)
	{
		"causes incineration dissolve to dead units",
		"force hard ping as attachment feedback#force a hard ping as a notification to the player that the sticky grenade has attached"
	};
	STRING_LIST(damageSecondaryFlags, damageSecondaryFlags_strings, _countof(damageSecondaryFlags_strings));

	STRINGS(damage_effect_sound_type_flags)
	{
		"none!",
		"lethal instantaneous#headshots and assassinations",
		"lethal#excludes headshots and assassinations",
		"non lethal"
	};
	STRING_LIST(damage_effect_sound_type_flags, damage_effect_sound_type_flags_strings, _countof(damage_effect_sound_type_flags_strings));

	STRINGS(damage_effect_flags)
	{
		"don\'t scale damage by distance",
		"area damage players only#area of effect damage only affects players",
		"affects model targets#distribute the damage amongst the model targets. this is the default behavior for aoe damage, but can be set here for direct damage.",
		"explosive area of effect"
	};
	STRING_LIST(damage_effect_flags, damage_effect_flags_strings, _countof(damage_effect_flags_strings));

	TAG_REFERENCE(global_damage_reference, DAMAGE_EFFECT_TAG);

} // namespace blofeld

