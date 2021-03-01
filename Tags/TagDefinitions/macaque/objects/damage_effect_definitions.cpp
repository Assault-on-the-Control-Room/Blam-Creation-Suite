#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		damage_effect_group,
		DAMAGE_EFFECT_TAG,
		nullptr,
		INVALID_TAG,
		damage_effect_block );

	TAG_BLOCK_FROM_STRUCT(
		damage_effect_block,
		"damage_effect",
		1,
		damage_effect_struct_definition);

	#define CUSTOM_DAMAGE_RESPONSE_LABEL_BLOCK_ID { 0x26EA92BD, 0xE58B40F2, 0x91D334D4, 0xE8A82956 }
	TAG_BLOCK(
		custom_damage_response_label_block,
		"custom_damage_response_label_block",
		8,
		"string_id",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CUSTOM_DAMAGE_RESPONSE_LABEL_BLOCK_ID)
	{
		{ _field_string_id, "custom label", "label used to control what damage response will fire.", FIELD_FLAG_INDEX },
		{ _field_terminator }
	};

	#define DAMAGE_EFFECT_SOUND_BLOCK_STRUCT_ID { 0x98E29191, 0x66FD4A13, 0xBD131534, 0x68160A3F }
	TAG_BLOCK(
		damage_effect_sound_block,
		"damage_effect_sound_block",
		4,
		"s_damage_effect_sound",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		DAMAGE_EFFECT_SOUND_BLOCK_STRUCT_ID)
	{
		{ _field_tag_reference, "sound", &global_sound_reference },
		{ _field_word_flags, "damage types", &damage_effect_sound_type_flags },
		{ _field_word_flags, "object types", &object_type_enum_definition },
		{ _field_terminator }
	};

	#define DAMAGE_EFFECT_STRUCT_DEFINITION_ID { 0x902C71FE, 0x22D24D90, 0x94283954, 0x36E07393 }
	TAG_STRUCT(
		damage_effect_struct_definition,
		"damage_effect",
		"damage_effect_group",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN4 | SET_UNKNOWN5 | 
		SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		DAMAGE_EFFECT_STRUCT_DEFINITION_ID)
	{
		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_tag_reference, "area of effect behavior equipment", "if a reference is here, area of effect damage will attach the equipment to the target", &behavior_object_reference },

		{ _field_real_bounds, "radius", nullptr, "world units" },
		{ _field_real_fraction, "cutoff scale", nullptr, nullptr, "[0,1]" },
		{ _field_long_flags, "effect flags", &damage_effect_flags },
		FIELD_EXPLANATION("damage", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_enum, "side effect", &damage_side_effects },
		{ _field_enum, "category", &damage_categories },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_long_enum, "death vocalization", &damage_death_vocalizations },

		{ _field_long_flags, "flags", &damage_flags },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_long_flags, "secondary flags", &damageSecondaryFlags },
		{ _field_real, "headshot damage multiplier", "ignored if zero or if headshot flag is not set above; \notherwise, makes headshot not instantly lethal, but multiplies damage done to head by this much.  \n2 does 2x damage to head for headshot.  note that head still has different health than body." },

		{ _field_real, "AOE core radius", "if >0 then higher fidelity obstruction collision checks are preformed. This field has no other ramifications.", "world units" },
		{ _field_real, "damage lower bound" },
		{ _field_real_bounds, "damage upper bound" },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_struct, "damage falloff function", &scalar_function_named_struct },

		{ _field_angle, "dmg inner cone angle" },

		{ _field_legacy, _field_version_less, _engine_type_haloreach },
		{ _field_legacy, _field_angle, "dmg inner cone angle" },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_struct, "blah", &damage_outer_cone_angle_struct },

		{ _field_real, "active camouflage damage", "how much more visible this damage makes a player who is active camouflaged", nullptr, "[0,1]" },
		{ _field_real, "stun", "amount of stun added to damaged unit", nullptr, "[0,1]" },
		{ _field_real, "maximum stun", "damaged unit's stun will never exceed this amount", nullptr, "[0,1]" },
		{ _field_real, "stun time", "duration of stun due to this damage", "seconds" },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_long_integer, "damage stun", "how long we stun recovering current body damage", "ticks" },

		{ _field_real, "instantaneous acceleration", nullptr, nullptr, "[0,+inf]" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_real, "alt instantaneous acceleration", "This field can be used for an alternative acceleration if the corresponding flags are set, e.g. check vehicle->flags.vehicle wants reduced weapon impulse when airborne", nullptr, "[0,+inf]" },
		{ _field_real, "acceleration cap", "set to zero to disable cap" },

		{ _field_useless_pad, "" },
		{ _field_useless_pad, "" },
		FIELD_EXPLANATION("DEPRECATED - rider damage scales", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real, "rider direct damage scale" },
		{ _field_real, "rider maximum transfer damage scale" },
		{ _field_real, "rider minimum transfer damage scale" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_real, "vehicle damage multiplier" },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_real_fraction, "soft ping pain screen scale", "The maximum amount to apply the pain screen pose overlay", nullptr, "[0,1]" },

		{ _field_useless_pad, "" },
		{ _field_string_id, "general_damage" },
		{ _field_string_id, "specific_damage" },

		{ _field_legacy, _field_version_less, _engine_type_haloreach },
		{ _field_legacy, _field_string_id, "custom response label" },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_block, "custom response labels", &custom_damage_response_label_block },

		{ _field_real, "AI stun radius", nullptr, "world units" },
		{ _field_real_bounds, "AI stun bounds", nullptr, "(0-1)" },
		{ _field_real, "shake radius" },
		{ _field_real, "EMP radius" },
		{ _field_real, "aoe spike radius" },
		{ _field_real, "aoe spike damage bump" },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_real, "shield render effects scale" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 17 },
		{ _field_long_integer, "stasis time", "duration of stasis due to this damage, zero disables", "ticks" },
		{ _field_real, "stasis time dilation" },
		{ _field_real, "stasis max biped turning rate" },
		{ _field_real, "stasis gravity multiplier" },
		{ _field_real, "equipment hack time", nullptr, "seconds" },
		FIELD_EXPLANATION("if 'Apply Tree Of Life'", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real, "tree_of_life shield regen modifier", "regen velocity of TOL:if non-1.0 this overrides any 'shield recharge rate' trait" },
		{ _field_real, "minimum shield level", "when hit, shield will be reset to this percentage of full strength if it is below", nullptr, "[0, 1]" },
		{ _field_real, "shield stun time", "time after damage applied before shield recharges", "seconds" },
		{ _field_real, "minimum health level", "when hit, health will be reset to this percentage of full health if it is below", nullptr, "[0, 1]" },
		{ _field_real, "health stun time", "time after damage applied before health recharges", "seconds" },
		{ _field_real, "minimum energy level", "like above, TOL reset minimum equipment energy to this", nullptr, "[0, 1]" },
		{ _field_real, "maximum energy level", "cap equipment energy to this", nullptr, "[0, 1]" },
		{ _field_real, "equipment stun time", "time after damage applied before equipment recharges", "seconds" },
		FIELD_EXPLANATION("Modifies TOL logic so that (above) unstun will only happen if (below) minimum stun time has passed", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real, "shield minimum stun time", nullptr, "seconds" },
		{ _field_real, "health minimum stun time", nullptr, "seconds" },

		// reach moved a bunch of this into its own tag
		FIELD_EXPLANATION("damage response", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_tag_reference, "damage response", &global_damage_response_definition_reference },

		FIELD_EXPLANATION("sound", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_tag_reference, "old melee sound", MAKE_OLD_NAMES("sound"), &global_sound_reference },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_block, "damage sounds", &damage_effect_sound_block },

		{ _field_useless_pad, "" },
		FIELD_EXPLANATION("breaking effect", nullptr, FIELD_FLAG_NONE, "Controls particle velocities when a damage effect shatters a materal.\n\nAll particles created within \'forward radius\' will be kicked along the\ndamage direction with a speed equivalent to \'forward velocity\' at the\nepicenter of the damage and 0 at the outer radius.  \'Forward exponent\'\nis used to modify the velocity scale.  A low exponent (like 0.5) means that\nparticles between the epicenter and the radius will be kicked out with a speed\ncloser to \'forward velocity\' than if a higher exponent (like 2.0) was used\n\nThe outward fields work in a similar way, except instead of kicking along the\ndamage direction, they get kick away from the damage epicenter."),
		{ _field_real, "forward velocity", nullptr, "world units per second" },
		{ _field_real, "forward radius", nullptr, "world units" },
		{ _field_real, "forward exponent" },
		{ _field_useless_pad, "" },
		{ _field_real, "outward velocity", nullptr, "world units per second" },
		{ _field_real, "outward radius", nullptr, "world units" },
		{ _field_real, "outward exponent" },
		{ _field_useless_pad, "" },
		{ _field_terminator }
	};

	#define DAMAGE_OUTER_CONE_ANGLE_STRUCT_ID { 0x728A16DC, 0x5EF1403B, 0x873B7F44, 0xC741A9F2 }
	TAG_STRUCT(
		damage_outer_cone_angle_struct,
		"damage_outer_cone_angle_struct",
		"damage_outer_cone_angle_struct",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		DAMAGE_OUTER_CONE_ANGLE_STRUCT_ID)
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

} // namespace macaque

} // namespace blofeld

