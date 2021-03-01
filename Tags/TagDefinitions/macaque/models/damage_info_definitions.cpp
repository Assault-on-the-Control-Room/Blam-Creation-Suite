#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{
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

	V5_TAG_BLOCK(health_transfers_block, 65536) // assembly #NOTE: where did this information come from?
	{
		{ _field_legacy, _field_long_flags, "flags", & health_transfers_flags_definition },
		{ _field_legacy, _field_real, "transfer amount" },
		{ _field_legacy, _field_word_flags, "transfer function", &transfer_function_enum_definition },
		{ _field_legacy, _field_short_integer, "damage section index" },
		{ _field_legacy, _field_string_id, "seat label" },
		{ _field_legacy, _field_terminator }
	};

	#define NEW_GLOBAL_DAMAGE_SECTION_BLOCK_ID { 0xB8F6D2FD, 0xEE1D49A5, 0xA82B01A4, 0xFE09380E }
	TAG_BLOCK(
		new_global_damage_section_block,
		"new_global_damage_section_block",
		MAXIMUM_DAMAGE_SECTIONS_PER_MODEL,
		"s_new_model_damage_section",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		NEW_GLOBAL_DAMAGE_SECTION_BLOCK_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_long_flags, "flags", &new_damage_section_flags_definition },
		{ _field_real_fraction, "vitality percentage", "percentage of total object vitality", nullptr, "[0.1]" },
		{ _field_string_id, "shield material name", "set this to make this damage section a shield" },
		FIELD_EXPLANATION("stun", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real, "stun time", nullptr, "seconds" },
		{ _field_real, "minimum stun damage", "the minimum damage required to stun this object's health" },
		FIELD_EXPLANATION("recharge", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real, "recharge time", nullptr, "seconds" },
		{ _field_block, "recharge speed curve", &damage_section_recharge_speed_curve_block },
		{ _field_block, "recharge fractions", &damage_section_segmented_recharge_fraction_block },
		{ _field_tag_reference, "recharging effect", &global_effect_reference },
		{ _field_real, "pre recharge effect warn time", "(main shield only) how long before the recharge begins the pre-recharge effect fires", "seconds" },
		{ _field_tag_reference, "pre recharge effect", "(main shield only)", &global_effect_reference },
		{ _field_string_id, "pre recharge effect marker", "(main shield only)" },
		{ _field_tag_reference, "pre recharge abort effect", "(main shield only) if the pre-recharge effect is aborted before the actual recharge starts, this effect plays", &global_effect_reference },
		{ _field_string_id, "pre recharge abort effect marker", "(main shield only)" },
		FIELD_EXPLANATION("overcharge", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real, "overcharge time", "time it takes to reach full \"overcharge fraction\"", "seconds" },
		{ _field_real, "overcharge fraction", "fraction to which shields will automatically overcharge, values <= 1.0 are ignored" },
		FIELD_EXPLANATION("decay", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real, "pre decay time", "time for this section to be active before it will start to decay", "seconds" },
		{ _field_real, "decay time", "time for need for this section to fully decay with full health.", "seconds" },
		FIELD_EXPLANATION("resurrection", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_string_id, "resurrection restored region name" },
		{ _field_block, "instant responses", &new_instantaneous_damage_response_block },
		{ _field_block, "section damage transfers", &damage_transfer_block },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_block, "health transfers", &health_transfers_block_block },

		{ _field_block, "rendering", &damage_section_rendering_paramters_block },
		{ _field_real, "runtime recharge velocity", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real, "runtime overcharge velocity", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "runtime resurrection restored region index", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "runtime global shield material type", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define DAMAGE_SECTION_RECHARGE_SPEED_CURVE_BLOCK_ID { 0x93ADFC14, 0xDC9D498C, 0xAF3BA884, 0x17FF6AD8 }
	TAG_BLOCK(
		damage_section_recharge_speed_curve_block,
		"damage_section_recharge_speed_curve_block",
		1,
		"s_damage_section_recharge_speed_multiplier_curve",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		DAMAGE_SECTION_RECHARGE_SPEED_CURVE_BLOCK_ID)
	{
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_default),
		{ _field_struct, "Mapping", &mapping_function },
		{ _field_terminator }
	};

	#define DAMAGE_SECTION_SEGMENTED_RECHARGE_FRACTION_ID { 0x974937E7, 0x69D54EC5, 0xB34261A9, 0x53C817CE }
	TAG_BLOCK(
		damage_section_segmented_recharge_fraction_block,
		"damage_section_segmented_recharge_fraction",
		16,
		"real",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		DAMAGE_SECTION_SEGMENTED_RECHARGE_FRACTION_ID)
	{
		{ _field_real_fraction, "vitality percentage", "recharge will stop once this percentage of vitality is reached.", nullptr, "[0.1]" },
		{ _field_terminator }
	};

	#define NEW_INSTANTANEOUS_DAMAGE_RESPONSE_BLOCK_ID { 0x559D19CA, 0xE3724DAB, 0xB0CCAE0B, 0xFF415CD4 }
	TAG_BLOCK(
		new_instantaneous_damage_response_block,
		"new_instantaneous_damage_response_block",
		MAXIMUM_RESPONSES_PER_DAMAGE_SECTION,
		"s_new_instantaneous_damage_response",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		NEW_INSTANTANEOUS_DAMAGE_RESPONSE_BLOCK_ID)
	{
		{ _field_long_flags, "flags", &newDamageResponseFlagsPart1, _field_id_dumb },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_long_flags, "flags2", &newDamageResponseFlagsPart2, _field_id_dumb },

		{ _field_string_id, "label" },
		{ _field_real_fraction, "damage threshold", "response fires after crossing this threshold.  1=full health" },
		{ _field_tag_reference, "transition effect (generic)", MAKE_OLD_NAMES("transition effect"), &global_effect_reference },
		{ _field_string_id, "generic effect marker", MAKE_OLD_NAMES("effect marker name") },
		{ _field_tag_reference, "transition effect (specific)", &global_effect_reference },
		{ _field_string_id, "specific effect marker" },
		{ _field_struct, "damage effect", &instantaneous_response_damage_effect_struct },
		{ _field_struct, "damage effect marker", &instantaneous_response_damage_effect_marker_struct },
		{ _field_tag_reference, "looping effect", "will play until the next response is triggered.", &global_effect_reference },
		{ _field_block, "region_transitions", &damage_response_region_transition_block },
		{ _field_block, "response damage transfers", &damage_transfer_block },
		{ _field_short_block_index, "destroy instance group", "all possible instances from this group will be destroyed", &global_model_instance_group_block },
		{ _field_enum, "custom response behavior", &damage_response_custom_response_behavior_enum_definition },
		{ _field_string_id, "custom response label" },
		{ _field_real, "response delay", "time to wait until firing the response. This delay is pre-empted if another timed response for the same section fires.", "seconds" },
		{ _field_tag_reference, "delay effect", "plays while the timer is counting down", &global_effect_reference },
		{ _field_string_id, "delay effect marker name" },
		{ _field_block, "seat eject", &seat_ejection_block },
		{ _field_real_fraction, "skip fraction", "0.0 always fires, 1.0 never fires" },
		{ _field_string_id, "destroyed child object marker name", "when this response fires, any children objects created at the supplied marker name will be destroyed" },
		{ _field_real_fraction, "total damage threshold", "scale on total damage section vitality" },
		{ _field_string_id, "constraint/group name", "can specify a randomly-selected single constraint or the entire group of named constraints" },
		{ _field_enum, "constraint damage type", &damage_response_constraint_damage_type_enum_definition },
		FIELD_PAD("IDRBCDT", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	#define DAMAGE_RESPONSE_REGION_TRANSITION_BLOCK_ID { 0xAB37ECDD, 0x2463448A, 0xA416FEB5, 0x6A0B2580 }
	TAG_BLOCK(
		damage_response_region_transition_block,
		"damage_response_region_transition_block",
		16,
		"s_region_transition",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		DAMAGE_RESPONSE_REGION_TRANSITION_BLOCK_ID)
	{
		{ _field_string_id, "region" },
		{ _field_enum, "new state", &model_state_enum_definition },
		{ _field_short_integer, "runtime region index", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define DAMAGE_TRANSFER_BLOCK_ID { 0xD77922D6, 0x7BE043FA, 0xB5E62CE4, 0x60490EB9 }
	TAG_BLOCK(
		damage_transfer_block,
		"damage_transfer_block",
		MAXIMUM_DAMAGE_TRANSFERS_PER_MODEL,
		"s_damage_transfer",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		DAMAGE_TRANSFER_BLOCK_ID)
	{
		{ _field_long_flags, "flags", &damage_transfer_flags_definition },
		{ _field_real, "transfer amount" },
		{ _field_enum, "transfer function", &damage_transfer_function_enum_definition },
		{ _field_short_block_index, "damage section", &new_global_damage_section_block },
		{ _field_string_id, "seat label" },
		{ _field_terminator }
	};

	#define SEAT_EJECTION_BLOCK_ID { 0x6CB868BB, 0x2CBA40A2, 0xAEB08A95, 0xCA96880D }
	TAG_BLOCK(
		seat_ejection_block,
		"seat_ejection_block",
		8,
		"string_id",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SEAT_EJECTION_BLOCK_ID)
	{
		{ _field_string_id, "seat label", FIELD_FLAG_INDEX },
		{ _field_terminator }
	};

	#define DAMAGE_SECTION_RENDERING_PARAMTERS_ID { 0x54A5FE0B, 0xE53A4277, 0x95555319, 0x9F924131 }
	TAG_BLOCK(
		damage_section_rendering_paramters_block,
		"damage_section_rendering_paramters",
		1,
		"s_damage_section_rendering_parameters",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		DAMAGE_SECTION_RENDERING_PARAMTERS_ID)
	{
		{ _field_tag_reference, "3rd person impact parameters", &global_shield_parameters_reference },
		{ _field_tag_reference, "1st person impact parameters", &global_shield_parameters_reference },
		{ _field_terminator }
	};

	#define GLOBAL_DAMAGE_INFO_BLOCK_ID { 0xF8EA703F, 0x560E438E, 0x903E0A00, 0x1C77B3F2 }
	TAG_BLOCK(
		global_damage_info_block,
		"global_damage_info_block",
		1,
		"global_damage_info_block",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		GLOBAL_DAMAGE_INFO_BLOCK_ID)
	{
		{ _field_long_flags, "flags", &model_damage_info_flags_definition },
		{ _field_string_id, "global indirect material name", "absorbes AOE or child damage" },
		{ _field_custom_short_block_index, "indirect damage section", "absorbes AOE or child damage" },
		FIELD_PAD("XN", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD("LPVYKO", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_char_enum, "collision damage reporting type", &global_damage_reporting_enum_definition },
		{ _field_char_enum, "response damage reporting type", &global_damage_reporting_enum_definition },
		FIELD_PAD("MQ", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD("MYON", nullptr, FIELD_FLAG_NONE, 20),
		FIELD_EXPLANATION("body", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_struct, "body", &damage_body_parameters_struct },
		FIELD_PAD("IKEIDYSCX", nullptr, FIELD_FLAG_NONE, 64),
		FIELD_EXPLANATION("shield", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_struct, "shield", &damage_shield_parameters_struct },
		{ _field_block, "damage sections", &global_damage_section_block },
		{ _field_block, "nodes", FIELD_FLAG_READ_ONLY, &global_damage_nodes_block },
		{ _field_short_integer, "runtime shield material type", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "runtime indirect material type", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },

		{ _field_legacy, _field_version_less, _engine_type_haloreach, 2 },
		{ _field_legacy, _field_real, "@unknown" },
		{ _field_legacy, _field_real, "@unknown" },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach, 3 },
		{ _field_real, "runtime shield recharge velocity", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real, "runtime overcharge velocity", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real, "runtime health recharge velocity", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },

		{ _field_block, "damage seats", &damage_seat_info_block },
		{ _field_block, "damage constraints", &damage_constraint_info_block },
		FIELD_EXPLANATION("overshield", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_terminator }
	};

	#define GLOBAL_DAMAGE_SECTION_BLOCK_ID { 0x62D3077B, 0xC6584BCA, 0x9A4E7C7A, 0x989EB4F1 }
	TAG_BLOCK(
		global_damage_section_block,
		"global_damage_section_block",
		MAXIMUM_DAMAGE_SECTIONS_PER_MODEL,
		"s_model_damage_section",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		GLOBAL_DAMAGE_SECTION_BLOCK_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		FIELD_EXPLANATION("damage section flags", nullptr, FIELD_FLAG_NONE, "* absorbs body damage: damage to this section does not count against body vitality\n* headshottable: takes extra headshot damage when shot\n* ignores shields: damage to this section bypasses shields"),
		{ _field_long_flags, "flags", &damage_section_flags_definition },
		{ _field_real_fraction, "vitality percentage", "percentage of total object vitality", nullptr, "[0.1]" },
		{ _field_block, "instant responses", &instantaneous_damage_repsonse_block },
		{ _field_block, "unused0", &g_null_block },
		{ _field_block, "unused1", &g_null_block },
		{ _field_real, "stun time", nullptr, "seconds" },
		{ _field_real, "recharge time", nullptr, "seconds" },
		{ _field_real, "runtime recharge velocity", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_string_id, "resurrection restored region name" },
		{ _field_short_integer, "runtime resurrection restored region index", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		FIELD_PAD("AG", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	#define INSTANTANEOUS_DAMAGE_REPSONSE_BLOCK_ID { 0x2A8C9E6B, 0x10DE4CDB, 0x9C2F98C4, 0xBB69FEED }
	TAG_BLOCK(
		instantaneous_damage_repsonse_block,
		"instantaneous_damage_repsonse_block",
		MAXIMUM_RESPONSES_PER_DAMAGE_SECTION,
		"s_instantaneous_damage_response",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		INSTANTANEOUS_DAMAGE_REPSONSE_BLOCK_ID)
	{
		{ _field_enum, "response type", &damage_response_type_enum_definition },
		FIELD_EXPLANATION("Constraint damage type", nullptr, FIELD_FLAG_NONE, "* if you specify a constraint group name (see lower section of this block)\n  you can specify a constraint damage\n* loosening a constraint takes it out of the rigid state - activates it\n* destroying a constraint sets the attached body free"),
		{ _field_enum, "constraint damage type", &damage_response_constraint_damage_type_enum_definition },
		FIELD_EXPLANATION("Constraint destruction", nullptr, FIELD_FLAG_NONE, "- a response can destroy a single constraint by naming it explicitly.\n- alternatively it can randomly destroy a single constraint from a specified group if the \"destroy one group constraint\" flag is set\n- also it can destroy all constraints in a specified group if the \"destroy all group constraints\" flag is set\n"),
		{ _field_string_id, "constraint/group name" },
		FIELD_EXPLANATION("Damage response flags", nullptr, FIELD_FLAG_NONE, "* kills object: when the response fires the object dies regardless of its current health\n* inhibits <x>: from halo 1 - disallows basic behaviors for a unit\n* forces drop weapon: from halo 1 - makes the unit drop its current weapon\n* kills weapon <x> trigger: destroys the <x> trigger on the unit\'s current weapon\n* destroys object: when the response fires the object is destroyed"),
		{ _field_long_flags, "flags", &damage_response_set1, _field_id_dumb },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_long_flags, "flags2", &damage_response_set2, _field_id_dumb },

		{ _field_real_fraction, "damage threshold", "response fires after crossing this threshold.  1=full health" },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach, 2 },
		{ _field_long_flags, "body threshold flags", &damage_response_body_threshold_flags_definition },
		{ _field_real, "body damage threshold", "response fires after object body damage crosses this threshold, numbers can be negative.  You need to set the flag \"body threshold active\" for this number to be used. 1=full health" },

		{ _field_tag_reference, "transition effect (generic)", MAKE_OLD_NAMES("transition effect"), &global_effect_reference },
		{ _field_tag_reference, "transition effect (specific)", &global_effect_reference },
		{ _field_struct, "damage effect", &instantaneous_response_damage_effect_struct },
		{ _field_string_id, "region" },
		{ _field_enum, "new state", &model_state_enum_definition },
		{ _field_short_integer, "runtime region index", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_string_id, "region (secondary)" },
		{ _field_enum, "new state (secondary)", &model_state_enum_definition },
		{ _field_short_integer, "runtime region index (secondary)", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_short_block_index, "destroy instance group", "all possible instances from this group will be destroyed", &global_model_instance_group_block },
		{ _field_enum, "custom response behavior", &damage_response_custom_response_behavior_enum_definition },
		{ _field_string_id, "custom response label" },
		{ _field_string_id, "effect marker name" },
		{ _field_struct, "damage effect marker", &instantaneous_response_damage_effect_marker_struct },
		FIELD_EXPLANATION("Response delay", nullptr, FIELD_FLAG_NONE, "If desired, you can specify a delay until the response fires.This delay is pre-empted if another timed response for the same section fires.The delay effect plays while the timer is counting down.If the damage threshold is taken in a single hit while counting down, it will prematurely fire."),
		{ _field_real, "response delay", "in seconds" },
		{ _field_tag_reference, "delay effect", &global_effect_reference },
		{ _field_string_id, "delay effect marker name" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_real, "response delay premature damage threshold" },

		FIELD_EXPLANATION("seat ejaculation", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_string_id, "ejecting seat label" },
		FIELD_EXPLANATION("skip fraction", nullptr, FIELD_FLAG_NONE, "0.0 always fires, 1.0 never fires"),
		{ _field_real_fraction, "skip fraction" },
		FIELD_EXPLANATION("destroyed child object marker name", nullptr, FIELD_FLAG_NONE, "when this response fires, any children objects created at the supplied marker name will be destroyed"),
		{ _field_string_id, "destroyed child object marker name" },
		FIELD_EXPLANATION("total damage threshold", nullptr, FIELD_FLAG_NONE, "scale on total damage section vitality"),
		{ _field_real_fraction, "total damage threshold" },
		{ _field_terminator }
	};

	#define GLOBAL_DAMAGE_NODES_BLOCK_ID { 0x3736D0B4, 0x7C0A40E1, 0xA4811152, 0x22F811F0 }
	TAG_BLOCK(
		global_damage_nodes_block,
		"global_damage_nodes_block",
		MAXIMUM_NODES_PER_MODEL,
		"s_damage_node",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		GLOBAL_DAMAGE_NODES_BLOCK_ID)
	{
		{ _field_short_integer, "runtime damage part", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		FIELD_PAD("EOT", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD("SBFL", nullptr, FIELD_FLAG_NONE, 12),
		{ _field_terminator }
	};

	#define DAMAGE_SEAT_INFO_BLOCK_ID { 0xF8A6BCA3, 0xCAA541C0, 0xA3EBD6F5, 0xFED5C84D }
	TAG_BLOCK(
		damage_seat_info_block,
		"damage_seat_info_block",
		MAXIMUM_DAMAGE_SEAT_INFOS_PER_MODEL,
		"s_damage_seat_info",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		DAMAGE_SEAT_INFO_BLOCK_ID)
	{
		{ _field_string_id, "seat label", FIELD_FLAG_INDEX },
		{ _field_real_fraction, "direct damage scale", "0==no damage, 1==full damage" },
		{ _field_real, "damage transfer fall-off radius" },
		{ _field_real, "maximum transfer damage scale" },
		{ _field_real, "minimum transfer damage scale" },
		{ _field_block, "region-specific-damage", &damage_seat_region_setting_block },
		{ _field_terminator }
	};

	#define DAMAGE_SEAT_REGION_SETTING_BLOCK_ID { 0x11C1834D, 0xC1A14C1E, 0x9BB6EFBD, 0x8A649453 }
	TAG_BLOCK(
		damage_seat_region_setting_block,
		"damage_seat_region_setting_block",
		1,
		"s_damage_seat_region_setting",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		DAMAGE_SEAT_REGION_SETTING_BLOCK_ID)
	{
		FIELD_EXPLANATION("region-state-specific-damage", nullptr, FIELD_FLAG_NONE, "for fields below, 0.0==inherit from damage seat"),
		{ _field_string_id, "damage region name" },
		{ _field_short_integer, "runtime damage region index", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		FIELD_PAD("EOQ", nullptr, FIELD_FLAG_NONE, 2),
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

	#define DAMAGE_CONSTRAINT_INFO_BLOCK_ID { 0xB2695CA4, 0x6DBB4594, 0x8CD7C095, 0x292B2763 }
	TAG_BLOCK(
		damage_constraint_info_block,
		"damage_constraint_info_block",
		MAXIMUM_DAMAGE_CONSTRAINT_INFOS_PER_MODEL,
		"s_damage_constraint_info",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		DAMAGE_CONSTRAINT_INFO_BLOCK_ID)
	{
		{ _field_string_id, "physics model constraint name" },
		{ _field_string_id, "damage constraint name" },
		{ _field_string_id, "damage constraint group name" },
		{ _field_real, "group probability scale" },
		{ _field_short_integer, "runtime constraint type", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "runtime constraint index", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define INSTANTANEOUS_RESPONSE_DAMAGE_EFFECT_STRUCT_ID { 0x16BAF761, 0x451A4914, 0xB508138C, 0x7244DA1E }
	TAG_STRUCT(
		instantaneous_response_damage_effect_struct,
		"instantaneous_response_damage_effect_struct",
		"instantaneous_response_damage_effect_struct",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		INSTANTANEOUS_RESPONSE_DAMAGE_EFFECT_STRUCT_ID)
	{
		{ _field_tag_reference, "transition damage effect", &global_damage_reference },
		{ _field_terminator }
	};

	#define INSTANTANEOUS_RESPONSE_DAMAGE_EFFECT_MARKER_STRUCT_ID { 0x6272DDC9, 0xC8664D2F, 0xB77E21BC, 0xB0C9B9DF }
	TAG_STRUCT(
		instantaneous_response_damage_effect_marker_struct,
		"instantaneous_response_damage_effect_marker_struct",
		"instantaneous_response_damage_effect_marker_struct",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		INSTANTANEOUS_RESPONSE_DAMAGE_EFFECT_MARKER_STRUCT_ID)
	{
		{ _field_string_id, "damage effect marker name" },
		{ _field_terminator }
	};

	#define DAMAGE_BODY_PARAMETERS_STRUCT_ID { 0x33ECAC95, 0x9A4245E7, 0x8F244955, 0x413516E8 }
	TAG_STRUCT(
		damage_body_parameters_struct,
		"damage_body_parameters_struct",
		"real",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		DAMAGE_BODY_PARAMETERS_STRUCT_ID)
	{
		{ _field_real, "maximum vitality" },
		{ _field_real, "minimum stun damage", "the minimum damage required to stun this object's health" },
		{ _field_real, "stun time", "the length of time the health stay stunned (do not recharge) after taking damage", "seconds" },
		{ _field_real, "recharge time", "the length of time it would take for the shields to fully recharge after being completely depleted", "seconds" },
		{ _field_real_fraction, "recharge fraction", "0 defaults to 1 - to what maximum level the body health will be allowed to recharge" },
		{ _field_terminator }
	};

	#define DAMAGE_SHIELD_PARAMETERS_STRUCT_ID { 0xD30C88AC, 0xF030462C, 0x9536E894, 0xA6F752C1 }
	TAG_STRUCT(
		damage_shield_parameters_struct,
		"damage_shield_parameters_struct",
		"damage_shield_parameters_struct",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		DAMAGE_SHIELD_PARAMETERS_STRUCT_ID)
	{
		{ _field_real, "maximum shield vitality", "the default initial and maximum shield vitality of this object" },
		{ _field_string_id, "global shield material name" },
		{ _field_real, "minimum stun damage", "the minimum damage required to stun this object's shields" },
		{ _field_real, "stun time", "the length of time the shields stay stunned (do not recharge) after taking damage", "seconds" },
		{ _field_real, "recharge time", "the length of time it would take for the shields to fully recharge after being completely depleted", "seconds" },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach, 2 },
		{ _field_real, "shield overcharge fraction", "fraction to which shields will automatically overcharge, values <= 1.0 are ignored" },
		{ _field_real, "shield overcharge time", "time it takes to reach full \"shield overcharge fraction\"" },

		{ _field_real, "shield damaged threshold" },
		{ _field_tag_reference, "shield damaged effect", &global_effect_reference },
		{ _field_tag_reference, "shield depleted effect", &global_effect_reference },
		{ _field_tag_reference, "shield recharging effect", &global_effect_reference },
		{ _field_terminator }
	};

	#define MODEL_DAMAGE_INFO_STRUCT_ID { 0xDF8AD947, 0xD85A4A9F, 0xA4D8F89C, 0xD3E30B24 }
	TAG_STRUCT(
		model_damage_info_struct,
		"model_damage_info_struct",
		"s_new_model_damage_info",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		MODEL_DAMAGE_INFO_STRUCT_ID)
	{
		FIELD_EXPLANATION("Damage Info", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_long_flags, "flags", &new_model_damage_info_flags_definition },
		{ _field_real, "maximum vitality", "value of zero implies 'damage sections' should be empty" },
		{ _field_string_id, "indirect material name", "absorbes AOE or child damage" },
		{ _field_short_block_index, "indirect damage section", "absorbes AOE or child damage", &new_global_damage_section_block },
		{ _field_short_block_index, "shielded state damage section", "the model's shielded/unshielded state reflects the depletion of this damage section", &new_global_damage_section_block },
		{ _field_char_enum, "collision damage reporting type", &global_damage_reporting_enum_definition },
		{ _field_char_enum, "response damage reporting type", &global_damage_reporting_enum_definition },
		FIELD_PAD("MDIBP0", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_block, "damage sections", &new_global_damage_section_block },
		{ _field_block, "damage constraints", &damage_constraint_info_block },
		{ _field_block, "nodes", FIELD_FLAG_READ_ONLY, &global_damage_nodes_block },
		{ _field_short_integer, "runtime indirect material type", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		FIELD_PAD("MDIBP1", nullptr, FIELD_FLAG_NONE, 2),
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

} // namespace macaque

} // namespace blofeld

