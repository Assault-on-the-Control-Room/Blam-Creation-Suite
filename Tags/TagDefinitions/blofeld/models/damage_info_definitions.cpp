#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_BLOCK(instantaneous_damage_repsonse_block, MAXIMUM_RESPONSES_PER_DAMAGE_SECTION)
	{
		{ _field_enum, "response type", &damage_response_type_enum_definition },
		{ _field_explanation, "Constraint damage type", "* if you specify a constraint group name (see lower section of this block)\n  you can specify a constraint damage\n* loosening a constraint takes it out of the rigid state - activates it\n* destroying a constraint sets the attached body free" },
		{ _field_enum, "constraint damage type", &damage_response_constraint_damage_type_enum_definition },
		{ _field_explanation, "Constraint destruction", "- a response can destroy a single constraint by naming it explicitly.\n- alternatively it can randomly destroy a single constraint from a specified group if the \"destroy one group constraint\" flag is set\n- also it can destroy all constraints in a specified group if the \"destroy all group constraints\" flag is set\n" },
		{ _field_string_id, "constraint/group name" },
		{ _field_explanation, "Damage response flags", "* kills object: when the response fires the object dies regardless of its current health\n* inhibits <x>: from halo 1 - disallows basic behaviors for a unit\n* forces drop weapon: from halo 1 - makes the unit drop its current weapon\n* kills weapon <x> trigger: destroys the <x> trigger on the unit\'s current weapon\n* destroys object: when the response fires the object is destroyed" },
		{ _field_long_flags, "flags", &damage_response_set1 },

		{ _field_version_greater, _engine_type_haloreach },
		{ _field_long_flags, "flags2", &damage_response_set2 },

		{ _field_real_fraction, "damage threshold#response fires after crossing this threshold.  1=full health" },

		{ _field_version_greater_or_equal, _engine_type_haloreach, 2 },
		{ _field_long_flags, "body threshold flags", &damage_response_body_threshold_flags_definition },
		{ _field_real, "body damage threshold#response fires after object body damage crosses this threshold, numbers can be negative.  You need to set the flag \"body threshold active\" for this number to be used. 1=full health" },

		{ _field_tag_reference, "transition effect (generic){transition effect}", &global_effect_reference },
		{ _field_tag_reference, "transition effect (specific)", &global_effect_reference },
		{ _field_struct, "damage effect", &instantaneous_response_damage_effect_struct_struct_definition },
		{ _field_string_id, "region" },
		{ _field_enum, "new state", &model_state_enum_definition },
		{ _field_short_integer, "runtime region index!*" },
		{ _field_string_id, "region (secondary)" },
		{ _field_enum, "new state (secondary)", &model_state_enum_definition },
		{ _field_short_integer, "runtime region index (secondary)!*" },
		{ _field_short_block_index, "destroy instance group#all possible instances from this group will be destroyed" },
		{ _field_enum, "custom response behavior", &damage_response_custom_response_behavior_enum_definition },
		{ _field_string_id, "custom response label" },
		{ _field_string_id, "effect marker name" },
		{ _field_struct, "damage effect marker", &instantaneous_response_damage_effect_marker_struct_struct_definition },
		{ _field_explanation, "Response delay", "If desired, you can specify a delay until the response fires.This delay is pre-empted if another timed response for the same section fires.The delay effect plays while the timer is counting down.If the damage threshold is taken in a single hit while counting down, it will prematurely fire." },
		{ _field_real, "response delay#in seconds" },
		{ _field_tag_reference, "delay effect", &global_effect_reference },
		{ _field_string_id, "delay effect marker name" },

		{ _field_version_greater, _engine_type_haloreach },
		{ _field_real, "response delay premature damage threshold" },

		{ _field_explanation, "seat ejaculation", "" },
		{ _field_string_id, "ejecting seat label" },
		{ _field_explanation, "skip fraction", "0.0 always fires, 1.0 never fires" },
		{ _field_real_fraction, "skip fraction" },
		{ _field_explanation, "destroyed child object marker name", "when this response fires, any children objects created at the supplied marker name will be destroyed" },
		{ _field_string_id, "destroyed child object marker name" },
		{ _field_explanation, "total damage threshold", "scale on total damage section vitality" },
		{ _field_real_fraction, "total damage threshold" },
		{ _field_terminator }
	};

	TAG_BLOCK(global_damage_section_block, MAXIMUM_DAMAGE_SECTIONS_PER_MODEL)
	{
		{ _field_string_id, "name^" },
		{ _field_explanation, "damage section flags", "* absorbs body damage: damage to this section does not count against body vitality\n* headshottable: takes extra headshot damage when shot\n* ignores shields: damage to this section bypasses shields" },
		{ _field_long_flags, "flags", &damage_section_flags_definition },
		{ _field_real_fraction, "vitality percentage:[0.1]#percentage of total object vitality" },
		{ _field_block, "instant responses", &instantaneous_damage_repsonse_block_block },
		{ _field_block, "unused0", &g_null_block_block },
		{ _field_block, "unused1", &g_null_block_block },
		{ _field_real, "stun time:seconds" },
		{ _field_real, "recharge time:seconds" },
		{ _field_real, "runtime recharge velocity!*" },
		{ _field_string_id, "resurrection restored region name" },
		{ _field_short_integer, "runtime resurrection restored region index!*" },
		{ _field_pad, "AG", 2 },
		{ _field_terminator }
	};

	TAG_BLOCK(global_damage_nodes_block, MAXIMUM_NODES_PER_MODEL)
	{
		{ _field_short_integer, "runtime damage part!*" },
		{ _field_pad, "EOT", 2 },
		{ _field_pad, "SBFL", 12 },
		{ _field_terminator }
	};

	TAG_BLOCK(damage_seat_region_setting_block, 1)
	{
		{ _field_explanation, "region-state-specific-damage", "for fields below, 0.0==inherit from damage seat" },
		{ _field_string_id, "damage region name" },
		{ _field_short_integer, "runtime damage region index!*" },
		{ _field_pad, "EOQ", 2 },
		{ _field_real, "direct damage scale (minor)" },
		{ _field_real, "Max. transfer scale (minor)" },
		{ _field_real, "min. transfer scale (minor)" },
		{ _field_real, "direct damage scale (medium)" },
		{ _field_real, "Max. transfer scale (medium)" },
		{ _field_real, "min. transfer scale (medium)" },
		{ _field_real, "direct damage scale (major)" },
		{ _field_real, "Max. transfer scale (major)" },
		{ _field_real, "min. transfer scale (major)" },
		{ _field_terminator }
	};

	TAG_BLOCK(damage_seat_info_block, MAXIMUM_DAMAGE_SEAT_INFOS_PER_MODEL)
	{
		{ _field_string_id, "seat label^" },
		{ _field_real_fraction, "direct damage scale#0==no damage, 1==full damage" },
		{ _field_real, "damage transfer fall-off radius" },
		{ _field_real, "maximum transfer damage scale" },
		{ _field_real, "minimum transfer damage scale" },
		{ _field_block, "region-specific-damage", &damage_seat_region_setting_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(damage_constraint_info_block, MAXIMUM_DAMAGE_CONSTRAINT_INFOS_PER_MODEL)
	{
		{ _field_string_id, "physics model constraint name" },
		{ _field_string_id, "damage constraint name" },
		{ _field_string_id, "damage constraint group name" },
		{ _field_real, "group probability scale" },
		{ _field_short_integer, "runtime constraint type!*" },
		{ _field_short_integer, "runtime constraint index!*" },
		{ _field_terminator }
	};

	TAG_BLOCK(global_damage_info_block, 1)
	{
		{ _field_long_flags, "flags", &model_damage_info_flags_definition },
		{ _field_string_id, "global indirect material name#absorbes AOE or child damage" },
		{ _field_custom_short_block_index, "indirect damage section#absorbes AOE or child damage" },
		{ _field_pad, "XN", 2 },
		{ _field_pad, "LPVYKO", 4 },
		{ _field_char_enum, "collision damage reporting type", &global_damage_reporting_enum_definition },
		{ _field_char_enum, "response damage reporting type", &global_damage_reporting_enum_definition },
		{ _field_pad, "MQ", 2 },
		{ _field_pad, "MYON", 20 },
		{ _field_explanation, "body", "" },
		{ _field_struct, "body", &damage_body_parameters_struct_struct_definition },
		{ _field_pad, "IKEIDYSCX", 64 },
		{ _field_explanation, "shield", "" },
		{ _field_struct, "shield", &damage_shield_parameters_struct_struct_definition },
		{ _field_block, "damage sections", &global_damage_section_block_block },
		{ _field_block, "nodes*", &global_damage_nodes_block_block },
		{ _field_short_integer, "runtime shield material type!*" },
		{ _field_short_integer, "runtime indirect material type!*" },

		{ _field_version_less, _engine_type_haloreach },
		{ _field_real, "@unknown" },
		{ _field_real, "@unknown" },

		{ _field_version_greater_or_equal, _engine_type_haloreach, 3 },
		{ _field_real, "runtime shield recharge velocity!*" },
		{ _field_real, "runtime overcharge velocity!*" },
		{ _field_real, "runtime health recharge velocity!*" },

		{ _field_block, "damage seats", &damage_seat_info_block_block },
		{ _field_block, "damage constraints", &damage_constraint_info_block_block },
		{ _field_explanation, "overshield", "" },
		{ _field_terminator }
	};

	TAG_BLOCK(damage_section_recharge_speed_curve_block, 1)
	{
		{ _field_custom },
		{ _field_struct, "Mapping", &mapping_function_struct_definition },
		{ _field_terminator }
	};

	TAG_BLOCK(damage_section_segmented_recharge_fraction, 16)
	{
		{ _field_real_fraction, "vitality percentage:[0.1]#recharge will stop once this percentage of vitality is reached." },
		{ _field_terminator }
	};

	TAG_BLOCK(damage_response_region_transition_block, 16)
	{
		{ _field_string_id, "region" },
		{ _field_enum, "new state", &model_state_enum_definition },
		{ _field_short_integer, "runtime region index!*" },
		{ _field_terminator }
	};

	TAG_BLOCK(damage_transfer_block, MAXIMUM_DAMAGE_TRANSFERS_PER_MODEL)
	{
		{ _field_long_flags, "flags", &damage_transfer_flags_definition },
		{ _field_real, "transfer amount" },
		{ _field_enum, "transfer function", &damage_transfer_function_enum_definition },
		{ _field_short_block_index, "damage section" },
		{ _field_string_id, "seat label" },
		{ _field_terminator }
	};

	TAG_BLOCK(seat_ejection_block, 8)
	{
		{ _field_string_id, "seat label^" },
		{ _field_terminator }
	};

	TAG_BLOCK(new_instantaneous_damage_response_block, MAXIMUM_RESPONSES_PER_DAMAGE_SECTION)
	{
		{ _field_long_flags, "flags", &newDamageResponseFlagsPart1 },

		{ _field_version_greater, _engine_type_haloreach },
		{ _field_long_flags, "flags2", &newDamageResponseFlagsPart2 },

		{ _field_string_id, "label" },
		{ _field_real_fraction, "damage threshold#response fires after crossing this threshold.  1=full health" },
		{ _field_tag_reference, "transition effect (generic){transition effect}", &global_effect_reference },
		{ _field_string_id, "generic effect marker{effect marker name}" },
		{ _field_tag_reference, "transition effect (specific)", &global_effect_reference },
		{ _field_string_id, "specific effect marker" },
		{ _field_struct, "damage effect", &instantaneous_response_damage_effect_struct_struct_definition },
		{ _field_struct, "damage effect marker", &instantaneous_response_damage_effect_marker_struct_struct_definition },
		{ _field_tag_reference, "looping effect#will play until the next response is triggered.", &global_effect_reference },
		{ _field_block, "region_transitions", &damage_response_region_transition_block_block },
		{ _field_block, "response damage transfers", &damage_transfer_block_block },
		{ _field_short_block_index, "destroy instance group#all possible instances from this group will be destroyed" },
		{ _field_enum, "custom response behavior", &damage_response_custom_response_behavior_enum_definition },
		{ _field_string_id, "custom response label" },
		{ _field_real, "response delay:seconds#time to wait until firing the response. This delay is pre-empted if another timed response for the same section fires." },
		{ _field_tag_reference, "delay effect#plays while the timer is counting down", &global_effect_reference },
		{ _field_string_id, "delay effect marker name" },
		{ _field_block, "seat eject", &seat_ejection_block_block },
		{ _field_real_fraction, "skip fraction#0.0 always fires, 1.0 never fires" },
		{ _field_string_id, "destroyed child object marker name#when this response fires, any children objects created at the supplied marker name will be destroyed" },
		{ _field_real_fraction, "total damage threshold#scale on total damage section vitality" },
		{ _field_string_id, "constraint/group name#can specify a randomly-selected single constraint or the entire group of named constraints" },
		{ _field_enum, "constraint damage type", &damage_response_constraint_damage_type_enum_definition },
		{ _field_pad, "IDRBCDT", 2 },
		{ _field_terminator }
	};

	TAG_BLOCK(damage_section_rendering_paramters, 1)
	{
		{ _field_tag_reference, "3rd person impact parameters", &global_shield_parameters_reference },
		{ _field_tag_reference, "1st person impact parameters", &global_shield_parameters_reference },
		{ _field_terminator }
	};

	STRINGS(health_transfers_flags_definition)
	{
		"transfer health to damage section",
		"transfer health to parent",
		"transfer health to children",
		"transfer health to seats",
		"transfer direct health",
		"transfer aoe exposed damage",
		"transfer aoe obstructed damage",
	};
	STRING_LIST(health_transfers_flags_definition, health_transfers_flags_definition_strings, _countof(health_transfers_flags_definition_strings));

	STRINGS(transfer_function_enum_definition)
	{
		"percent",
		"points",
		"ceiling",
	};
	STRING_LIST(transfer_function_enum_definition, transfer_function_enum_definition_strings, _countof(transfer_function_enum_definition_strings));

	TAG_BLOCK(health_transfers_block, 65536) // assembly #NOTE: where did this information come from?
	{
		{ _field_long_flags, "flags", &health_transfers_flags_definition },
		{ _field_real, "transfer amount" },
		{ _field_word_flags, "transfer function", &transfer_function_enum_definition },
		{ _field_short_integer, "damage section index" },
		{ _field_string_id, "seat label" },
		{ _field_terminator }
	};

	TAG_BLOCK(new_global_damage_section_block, MAXIMUM_DAMAGE_SECTIONS_PER_MODEL)
	{
		{ _field_string_id, "name^" },
		{ _field_long_flags, "flags", &new_damage_section_flags_definition },
		{ _field_real_fraction, "vitality percentage:[0.1]#percentage of total object vitality" },
		{ _field_string_id, "shield material name#set this to make this damage section a shield" },
		{ _field_explanation, "stun", "" },
		{ _field_real, "stun time:seconds" },
		{ _field_real, "minimum stun damage#the minimum damage required to stun this object\'s health" },
		{ _field_explanation, "recharge", "" },
		{ _field_real, "recharge time:seconds" },
		{ _field_block, "recharge speed curve", &damage_section_recharge_speed_curve_block_block },
		{ _field_block, "recharge fractions", &damage_section_segmented_recharge_fraction_block },
		{ _field_tag_reference, "recharging effect", &global_effect_reference },
		{ _field_real, "pre recharge effect warn time:seconds#(main shield only) how long before the recharge begins the pre-recharge effect fires" },
		{ _field_tag_reference, "pre recharge effect#(main shield only)", &global_effect_reference },
		{ _field_string_id, "pre recharge effect marker#(main shield only)" },
		{ _field_tag_reference, "pre recharge abort effect#(main shield only) if the pre-recharge effect is aborted before the actual recharge starts, this effect plays", &global_effect_reference },
		{ _field_string_id, "pre recharge abort effect marker#(main shield only)" },
		{ _field_explanation, "overcharge", "" },
		{ _field_real, "overcharge time:seconds#time it takes to reach full \"overcharge fraction\"" },
		{ _field_real, "overcharge fraction#fraction to which shields will automatically overcharge, values <= 1.0 are ignored" },
		{ _field_explanation, "decay", "" },
		{ _field_real, "pre decay time:seconds#time for this section to be active before it will start to decay" },
		{ _field_real, "decay time:seconds#time for need for this section to fully decay with full health." },
		{ _field_explanation, "resurrection", "" },
		{ _field_string_id, "resurrection restored region name" },
		{ _field_block, "instant responses", &new_instantaneous_damage_response_block_block },
		{ _field_block, "section damage transfers", &damage_transfer_block_block },

		{ _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_block, "health transfers", &health_transfers_block_block },

		{ _field_block, "rendering", &damage_section_rendering_paramters_block },
		{ _field_real, "runtime recharge velocity!*" },
		{ _field_real, "runtime overcharge velocity!*" },
		{ _field_short_integer, "runtime resurrection restored region index!*" },
		{ _field_short_integer, "runtime global shield material type!*" },
		{ _field_terminator }
	};

	TAG_STRUCT(damage_body_parameters_struct)
	{
		{ _field_real, "maximum vitality" },
		{ _field_real, "minimum stun damage#the minimum damage required to stun this object\'s health" },
		{ _field_real, "stun time:seconds#the length of time the health stay stunned (do not recharge) after taking damage" },
		{ _field_real, "recharge time:seconds#the length of time it would take for the shields to fully recharge after being completely depleted" },
		{ _field_real_fraction, "recharge fraction#0 defaults to 1 - to what maximum level the body health will be allowed to recharge" },
		{ _field_terminator }
	};

	TAG_STRUCT(damage_shield_parameters_struct)
	{
		{ _field_real, "maximum shield vitality#the default initial and maximum shield vitality of this object" },
		{ _field_string_id, "global shield material name" },
		{ _field_real, "minimum stun damage#the minimum damage required to stun this object\'s shields" },
		{ _field_real, "stun time:seconds#the length of time the shields stay stunned (do not recharge) after taking damage" },
		{ _field_real, "recharge time:seconds#the length of time it would take for the shields to fully recharge after being completely depleted" },

		{ _field_version_greater_or_equal, _engine_type_haloreach, 2 },
		{ _field_real, "shield overcharge fraction#fraction to which shields will automatically overcharge, values <= 1.0 are ignored" },
		{ _field_real, "shield overcharge time#time it takes to reach full \"shield overcharge fraction\"" },

		{ _field_real, "shield damaged threshold" },
		{ _field_tag_reference, "shield damaged effect", &global_effect_reference },
		{ _field_tag_reference, "shield depleted effect", &global_effect_reference },
		{ _field_tag_reference, "shield recharging effect", &global_effect_reference },
		{ _field_terminator }
	};

	TAG_STRUCT(instantaneous_response_damage_effect_struct)
	{
		{ _field_tag_reference, "transition damage effect", &global_damage_reference },
		{ _field_terminator }
	};

	TAG_STRUCT(instantaneous_response_damage_effect_marker_struct)
	{
		{ _field_string_id, "damage effect marker name" },
		{ _field_terminator }
	};

	TAG_STRUCT(model_damage_info_struct)
	{
		{ _field_explanation, "Damage Info", "" },
		{ _field_long_flags, "flags", &new_model_damage_info_flags_definition },
		{ _field_real, "maximum vitality#value of zero implies \'damage sections\' should be empty" },
		{ _field_string_id, "indirect material name#absorbes AOE or child damage" },
		{ _field_short_block_index, "indirect damage section#absorbes AOE or child damage" },
		{ _field_short_block_index, "shielded state damage section#the model\'s shielded/unshielded state reflects the depletion of this damage section" },
		{ _field_char_enum, "collision damage reporting type", &global_damage_reporting_enum_definition },
		{ _field_char_enum, "response damage reporting type", &global_damage_reporting_enum_definition },
		{ _field_pad, "MDIBP0", 2 },
		{ _field_block, "damage sections", &new_global_damage_section_block_block },
		{ _field_block, "damage constraints", &damage_constraint_info_block_block },
		{ _field_block, "nodes*", &global_damage_nodes_block_block },
		{ _field_short_integer, "runtime indirect material type!*" },
		{ _field_pad, "MDIBP1", 2 },
		{ _field_terminator }
	};

	STRINGS(model_state_enum_definition)
	{
		"default",
		"minor damage",
		"medium damage",
		"major damage",
		"destroyed"
	};
	STRING_LIST(model_state_enum_definition, model_state_enum_definition_strings, _countof(model_state_enum_definition_strings));

	STRINGS(object_damage_aftermath_special_damage_type_enum)
	{
		"none",
		"headshot",
		"melee",
		"collision",
		"assassination"
	};
	STRING_LIST(object_damage_aftermath_special_damage_type_enum, object_damage_aftermath_special_damage_type_enum_strings, _countof(object_damage_aftermath_special_damage_type_enum_strings));

	STRINGS(model_damage_info_flags_definition)
	{
		"takes shield damage for children",
		"takes body damage for children",
		"always shields friendly damage",
		"passes area damage to children",
		"parent never takes body damage for us",
		"only damaged by explosives",
		"parent never takes shield damage for us",
		"cannot die from damage",
		"passes attached damage to riders",
		"shield depletion is permanent",
		"shield depletion force hard ping",
		"AI do not damage without player",
		"health regrows while dead",
		"shield recharge plays only when empty",
		"IGNORE force minimum transfer",
		"orphan from postprocess autogen#check this to take control of the new damage info tag block",
		"only damaged by boarding damage"
	};
	STRING_LIST(model_damage_info_flags_definition, model_damage_info_flags_definition_strings, _countof(model_damage_info_flags_definition_strings));

	STRINGS(damage_section_flags_definition)
	{
		"absorbs body damage",
		"takes full dmg when object dies",
		"cannot die with riders",
		"takes full dmg when obj dstryd",
		"restored on ressurection",
		"unused0!",
		"unused1!",
		"heatshottable",
		"ignores shields",
		"takes full dmg when shield depl",
		"networked (e.g. armor lock)",
		"allow damage response overflow"
	};
	STRING_LIST(damage_section_flags_definition, damage_section_flags_definition_strings, _countof(damage_section_flags_definition_strings));

	STRINGS(damage_response_type_enum_definition)
	{
		"receives all damage",
		"receives area effect damage",
		"receives local damage"
	};
	STRING_LIST(damage_response_type_enum_definition, damage_response_type_enum_definition_strings, _countof(damage_response_type_enum_definition_strings));

	STRINGS(damage_response_constraint_damage_type_enum_definition)
	{
		"none",
		"destroy one of group#sets the attached body of this constraint free",
		"destroy entire group#sets the attached body of all constraints free",
		"loosen one of group#takes this constraint out of the rigid state - activates it",
		"loosen entire group#takes all constraints out of the rigid state - activates them"
	};
	STRING_LIST(damage_response_constraint_damage_type_enum_definition, damage_response_constraint_damage_type_enum_definition_strings, _countof(damage_response_constraint_damage_type_enum_definition_strings));

	STRINGS(damage_response_set1)
	{
		"kills object#when the response fires the object dies regardless of its current health",
		"inhibits melee attack#from halo 1 - disallows melee for a unit",
		"inhibits weapon attack#from halo 1 - disallows weapon fire for a unit",
		"inhibits walking#from halo 1 - disallows walking for a unit",
		"forces drop weapon#from halo 1 - makes the unit drop its current weapon",
		"kills weapon primary trigger",
		"kills weapon secondary trigger",
		"destroys object#when the response fires the object is destroyed",
		"damages weapon primary trigger#destroys the primary trigger on the unit\'s current weapon",
		"damages weapon secondary trigger#destroys the secondary trigger on the unit\'s current weapon",
		"light damage left turn",
		"major damage left turn",
		"light damage right turn",
		"major damage right turn",
		"light damage engine",
		"major damage engine",
		"kills object (no player solo)",
		"causes detonation",
		"fires on creation",
		"kills variant objects",
		"force unattached effects",
		"fires under threshold",
		"triggers special death",
		"only on special death",
		"only NOT on special death",
		"buckles giants",
		"causes sp detonation",
		"skip sounds on generic effect",
		"kills giants",
		"skip sounds on special death",
		"cause head dismemberment",
		"cause left leg dismemberment"
	};
	STRING_LIST(damage_response_set1, damage_response_set1_strings, _countof(damage_response_set1_strings));

	STRINGS(damage_response_set2)
	{
		"cause right leg dismemberment",
		"cause left arm dismemberment",
		"cause right arm dismemberment",
		"allow damage recharge overflow"
	};
	STRING_LIST(damage_response_set2, damage_response_set2_strings, _countof(damage_response_set2_strings));

	STRINGS(damage_response_body_threshold_flags_definition)
	{
		"body threshold active#this resoponse fires when the body healh fraction crosses this boundary"
	};
	STRING_LIST(damage_response_body_threshold_flags_definition, damage_response_body_threshold_flags_definition_strings, _countof(damage_response_body_threshold_flags_definition_strings));

	STRINGS(damage_response_custom_response_behavior_enum_definition)
	{
		"plays always",
		"plays if labels match",
		"plays if labels differ"
	};
	STRING_LIST(damage_response_custom_response_behavior_enum_definition, damage_response_custom_response_behavior_enum_definition_strings, _countof(damage_response_custom_response_behavior_enum_definition_strings));

	STRINGS(new_model_damage_info_flags_definition)
	{
		"takes damage for children#useful for bipeds shielding/taking damage for weapons",
		"parent never takes damage for us#useful for attached shields",
		"cannot die from damage",
		"dies with riders",
		"passes area damage to children"
	};
	STRING_LIST(new_model_damage_info_flags_definition, new_model_damage_info_flags_definition_strings, _countof(new_model_damage_info_flags_definition_strings));

	STRINGS(new_damage_section_flags_definition)
	{
		{
			_engine_type_not_set,
			_versioned_string_list_mode_new,
			{
				"starts inactive#this section will be initialized with zero health and will be stunned indefinitely",
				"takes full dmg when object dies",
				"takes full dmg when obj dstryd",
				"restored on ressurection",
				"headshot#takes extra headshot damage when shot",
				"depletion is permanent",
				"recharges while dead",
				"play recharge effect only when empty",
				"networked (note that primary body and shield are always networked)",
				"can recharge independently#always a shield layer to recharge even if there is an inner shield layer that is stunned"
			}
		},
		{
			_engine_type_haloreach,
			_versioned_string_list_mode_append,
			{
				// NOTE: taken from halo5 and used to extend haloreach
				"depletion tracked by AI characters#on an AI character, depletion of this section is tracked by the AI, stimulus 'tracked_sections_depleted' is set when all of these on a character are depleted",
				"DEPRECATED DO NOT USE 1!",
				"DEPRECATED DO NOT USE 2!",
				"DEPRECATED DO NOT USE 3!",
				"DEPRECATED DO NOT USE 4!",
				"DEPRECATED DO NOT USE 5!",
				"DEPRECATED DO NOT USE 6!",
				"blocks headshots#headshot obstruction test collides with this damage section",
				"weak spot#this section is considered a weak spot and is not blocked by trivial collision sections",
				"trivial collision#test for headshots and weak spot hits through this damage section",
				"disable additive player damage sound",
			}
		},
		{
			_engine_type_gen3_xbox360,
			_versioned_string_list_mode_new,
			{
				"starts inactive#this section will be initialized with zero health and will be stunned indefinitely",
				"takes full dmg when object dies",
				"takes full dmg when obj dstryd",
				"restored on ressurection",
				"headshot#takes extra headshot damage when shot",
				"depletion is permanent",
				"recharges while dead",
				"play recharge effect only when empty",
				"networked (note that primary body and shield are always networked)",
				"can recharge independently#always a shield layer to recharge even if there is an inner shield layer that is stunned"
			}
		},
		{
			_engine_type_halo5,
			_versioned_string_list_mode_new,
			{
				"starts inactive#this section will be initialized with zero health and will be stunned indefinitely",
				"takes full dmg when object dies",
				"takes full dmg when obj dstryd",
				"restored on ressurection",
				"headshot#takes extra headshot damage when shot",
				"depletion is permanent",
				"recharges while dead",
				"play recharge effect only when empty",
				"networked (note that primary body and shield are always networked)",
				"can recharge independently#always a shield layer to recharge even if there is an inner shield layer that is stunned",
				"depletion tracked by AI characters#on an AI character, depletion of this section is tracked by the AI, stimulus 'tracked_sections_depleted' is set when all of these on a character are depleted",
				"DEPRECATED DO NOT USE 1!",
				"DEPRECATED DO NOT USE 2!",
				"DEPRECATED DO NOT USE 3!",
				"DEPRECATED DO NOT USE 4!",
				"DEPRECATED DO NOT USE 5!",
				"DEPRECATED DO NOT USE 6!",
				"blocks headshots#headshot obstruction test collides with this damage section",
				"weak spot#this section is considered a weak spot and is not blocked by trivial collision sections",
				"trivial collision#test for headshots and weak spot hits through this damage section",
				"disable additive player damage sound",
			}
		}
	};
	STRING_LIST(new_damage_section_flags_definition, new_damage_section_flags_definition_strings, _countof(new_damage_section_flags_definition_strings));

	STRINGS(newDamageResponseFlagsPart1)
	{
		"kills object#when the response fires the object dies regardless of its current health",
		"inhibits melee attack#from halo 1 - disallows melee for a unit",
		"inhibits weapon attack#from halo 1 - disallows weapon fire for a unit",
		"inhibits walking#from halo 1 - disallows walking for a unit",
		"forces drop weapon#from halo 1 - makes the unit drop its current weapon",
		"kills weapon primary trigger",
		"kills weapon secondary trigger",
		"destroys object#when the response fires the object is destroyed",
		"damages weapon primary trigger#destroys the primary trigger on the unit\'s current weapon",
		"damages weapon secondary trigger#destroys the secondary trigger on the unit\'s current weapon",
		"kills object (no player solo)",
		"causes detonation",
		"kills variant objects",
		"force unattached effects",
		"fires under threshold",
		"triggers special death",
		"only on special death",
		"only NOT on special death",
		"buckles giants",
		"causes sp detonation",
		"skip sounds on generic effect",
		"kills giants",
		"skip sounds on special death",
		"force hard ping",
		"can refire#can fire again if the section ever recharges past its threshold",
		"can skip transition effects#will not spawn effects if previous response also fired",
		"cause head dismemberment",
		"cause left leg dismemberment",
		"cause right leg dismemberment",
		"cause left arm dismemberment",
		"cause right arm dismemberment",
		"allow damage recharge overflow"
	};
	STRING_LIST(newDamageResponseFlagsPart1, newDamageResponseFlagsPart1_strings, _countof(newDamageResponseFlagsPart1_strings));

	STRINGS(newDamageResponseFlagsPart2)
	{
		"hides object if destroyed by response on predicted client#if the destroys object flag and this flag are both checked, the object will be hidden on predicted clients when the response fires (hologram hack)"
	};
	STRING_LIST(newDamageResponseFlagsPart2, newDamageResponseFlagsPart2_strings, _countof(newDamageResponseFlagsPart2_strings));

	STRINGS(damage_transfer_flags_definition)
	{
		"transfer damage to damage section",
		"transfer damage to parent",
		"transfer damage to children",
		"transfer damage to seats",
		"transfer direct damage",
		"transfer AOE exposed damage",
		"transfer AOE obstructed damage"
	};
	STRING_LIST(damage_transfer_flags_definition, damage_transfer_flags_definition_strings, _countof(damage_transfer_flags_definition_strings));

	STRINGS(damage_transfer_function_enum_definition)
	{
		"percent",
		"points",
		"ceiling"
	};
	STRING_LIST(damage_transfer_function_enum_definition, damage_transfer_function_enum_definition_strings, _countof(damage_transfer_function_enum_definition_strings));

} // namespace blofeld

