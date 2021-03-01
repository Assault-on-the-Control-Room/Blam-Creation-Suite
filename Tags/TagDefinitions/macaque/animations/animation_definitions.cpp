#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		frame_event_list_group,
		FRAME_EVENT_LIST_TAG,
		nullptr,
		INVALID_TAG,
		frame_event_list_block );

	#define MODEL_ANIMATION_GRAPH_STRUCT_DEFINITION_ID { 0xBC9BFC5F, 0x0D294C40, 0xAD92DA9E, 0xA336E795 }
	TAG_BLOCK(
		model_animation_graph_block,
		"model_animation_graph_block",
		1,
		"c_model_animation_graph",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_RESOURCES | 
		SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		MODEL_ANIMATION_GRAPH_STRUCT_DEFINITION_ID)
	{
		{ _field_struct, "definitions", &animation_graph_definitions_struct },
		{ _field_struct, "content", &animation_graph_contents_struct },
		{ _field_struct, "run time data", &model_animation_runtime_data_struct },
		{ _field_block, "additional node data", &additional_node_data_block },
		{ _field_block, "tag resource groups", &model_animation_tag_resource_group_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_struct, "codec data", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &animation_codec_data_struct },

		{ _field_terminator }
	};

	TAG_GROUP(
		model_animation_graph_group,
		MODEL_ANIMATION_GRAPH_TAG,
		nullptr,
		INVALID_TAG,
		model_animation_graph_block );

	TAG_BLOCK_FROM_STRUCT(
		frame_event_list_block,
		"frame_event_list_block",
		1,
		frame_event_list_struct_definition);

	#define ANIMATION_GRAPH_SOUND_REFERENCE_BLOCK_ID { 0x9E2008A6, 0x15384504, 0x86E98642, 0x770EB5DF }
	TAG_BLOCK(
		animation_graph_sound_reference_block,
		"animation_graph_sound_reference_block",
		k_max_sound_references_per_graph,
		"animation_graph_sound_reference",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		ANIMATION_GRAPH_SOUND_REFERENCE_BLOCK_ID)
	{
		{ _field_tag_reference, "sound", FIELD_FLAG_INDEX, &global_sound_reference },
		{ _field_word_flags, "flags", &key_event_flags_enum },
		{ _field_word_flags, "internal_flags", FIELD_FLAG_UNKNOWN0, &key_event_internal_flags_enum },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_tag_reference, "model", "optional. only allow this event when used on this model", &model_reference$3 },
		{ _field_string_id, "variant", "optional. only allow this event when used on this model variant" },

		{ _field_terminator }
	};

	#define ANIMATION_GRAPH_EFFECT_REFERENCE_BLOCK_ID { 0x3CF4A82F, 0x85234898, 0xB66DD8B6, 0xB88F8280 }
	TAG_BLOCK(
		animation_graph_effect_reference_block,
		"animation_graph_effect_reference_block",
		k_max_effect_references_per_graph,
		"animation_graph_effect_reference",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		ANIMATION_GRAPH_EFFECT_REFERENCE_BLOCK_ID)
	{
		{ _field_tag_reference, "effect", FIELD_FLAG_INDEX, &global_effect_reference },
		{ _field_word_flags, "flags", &key_event_flags_enum },
		{ _field_word_flags, "internal_flags", FIELD_FLAG_UNKNOWN0, &key_event_internal_flags_enum },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_tag_reference, "model", "optional. only allow this event when used on this model", &model_reference$3 },
		{ _field_string_id, "variant", "optional. only allow this event when used on this model variant" },

		{ _field_terminator }
	};

	#define IMPORT_ANIMATION_EVENT_BLOCK_ID { 0x2AA3BA59, 0xA0014A1F, 0x8DEF04DD, 0x745D9057 }
	TAG_BLOCK(
		import_animation_event_block,
		"import_animation_event_block",
		2*k_max_animations_per_graph,
		"s_import_animation_event",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		IMPORT_ANIMATION_EVENT_BLOCK_ID)
	{
		{ _field_string_id, "animation name", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_INDEX },
		{ _field_long_integer, "animation frame count", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_INDEX },
		{ _field_block, "animation events", &import_frame_event_block },
		{ _field_block, "sound events", &animation_sound_event_block_extended_block },
		{ _field_block, "effect events", &animation_effects_event_block_extended_block },
		{ _field_block, "dialogue events", &animation_dialogue_event_block_extended_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_block, "script events", &animation_script_event_block_extended_block },

		{ _field_terminator }
	};

	#define IMPORT_FRAME_EVENT_BLOCK_ID { 0xAB6DDD39, 0xFFC7421B, 0xBCB9FA2C, 0xCBA52259 }
	TAG_BLOCK(
		import_frame_event_block,
		"import_frame_event_block",
		k_max_frame_events,
		"s_import_frame_event",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		IMPORT_FRAME_EVENT_BLOCK_ID)
	{
		{ _field_string_id, "event name", FIELD_FLAG_READ_ONLY },
		{ _field_string_id, "animation name", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "frame" },
		{ _field_short_integer, "frame offset" },
		{ _field_enum, "type", FIELD_FLAG_READ_ONLY, &frame_event_type_new },
		FIELD_PAD("pad", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_long_integer, "unique ID", "(Do not change this)", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define ANIMATION_SOUND_EVENT_BLOCK_EXTENDED_ID { 0xA93991CB, 0xED064EBA, 0x911B680B, 0xB23DDA26 }
	TAG_BLOCK(
		animation_sound_event_block_extended_block,
		"animation_sound_event_block_extended",
		k_max_frame_events,
		"s_sound_event_extended",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		ANIMATION_SOUND_EVENT_BLOCK_EXTENDED_ID)
	{
		{ _field_short_block_index, "frame event", &import_frame_event_block },
		FIELD_PAD("pad", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_short_block_index, "sound", &animation_graph_sound_reference_block },
		{ _field_short_integer, "frame offset", "If a frame event is set, this number is relative to frame event, otherwise it's absolute." },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_marker),
		{ _field_string_id, "marker name" },
		{ _field_terminator }
	};

	#define ANIMATION_EFFECTS_EVENT_BLOCK_EXTENDED_ID { 0x8ED7D41D, 0x73CF4055, 0xA152950D, 0x9C9C10B5 }
	TAG_BLOCK(
		animation_effects_event_block_extended_block,
		"animation_effects_event_block_extended",
		k_max_frame_events,
		"s_effect_event_extended",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		ANIMATION_EFFECTS_EVENT_BLOCK_EXTENDED_ID)
	{
		{ _field_short_block_index, "frame event", &import_frame_event_block },
		FIELD_PAD("pad", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_short_block_index, "effect", &animation_graph_effect_reference_block },
		{ _field_short_integer, "frame offset", "If a frame event is set, this number is relative to frame event, otherwise it's absolute." },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_marker),
		{ _field_string_id, "marker name" },
		{ _field_char_enum, "damage effect reporting type", &global_damage_reporting_enum_definition },
		FIELD_PAD("pad_2", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_terminator }
	};

	#define ANIMATION_DIALOGUE_EVENT_BLOCK_EXTENDED_ID { 0x649B1755, 0x29134CBC, 0xBCF06814, 0x624F5E32 }
	TAG_BLOCK(
		animation_dialogue_event_block_extended_block,
		"animation_dialogue_event_block_extended",
		k_max_frame_events,
		"s_dialogue_event_extended",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		ANIMATION_DIALOGUE_EVENT_BLOCK_EXTENDED_ID)
	{
		{ _field_short_block_index, "frame event", &import_frame_event_block },
		{ _field_enum, "dialogue event", &animation_dialogue_event_enum },
		{ _field_short_integer, "frame offset", "If a frame event is set, this number is relative to frame event, otherwise it's absolute." },
		FIELD_PAD("pad", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	#define ANIMATION_SCRIPT_EVENT_BLOCK_EXTENDED_ID { 0xF1014928, 0xA2A149E4, 0x08DBE6E9, 0x5734AC5E }
	TAG_BLOCK(
		animation_script_event_block_extended_block,
		"animation_script_event_block_extended",
		k_max_frame_events,
		"s_script_event_extended",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		ANIMATION_SCRIPT_EVENT_BLOCK_EXTENDED_ID)
	{
		{ _field_short_block_index, "frame event", &import_frame_event_block },
		{ _field_short_integer, "frame offset", "If a frame event is set, this number is relative to frame event, otherwise it's absolute." },
		{ _field_string_id, "script name" },
		{ _field_terminator }
	};

	#define ANIMATION_USAGE_BLOCK_ID { 0x342555EE, 0x4EF942A3, 0x81E1346D, 0x6713E115 }
	TAG_BLOCK(
		animation_usage_block,
		"animation_usage_block",
		k_animation_node_usage_count,
		"s_animation_node_usage_entry",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		ANIMATION_USAGE_BLOCK_ID)
	{
		{ _field_enum, "usage", FIELD_FLAG_INDEX, &animation_usage_enumeration },
		{ _field_short_block_index, "node to use", &animation_graph_node_block },
		{ _field_terminator }
	};

	#define ANIMATION_GRAPH_NODE_BLOCK_ID { 0xA1BC3EC9, 0xA8A1454C, 0x8C893F2D, 0x2CAC1368 }
	TAG_BLOCK(
		animation_graph_node_block,
		"animation_graph_node_block",
		k_max_nodes_per_animation,
		"animation_graph_node_block",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		ANIMATION_GRAPH_NODE_BLOCK_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_short_block_index, "next sibling node index", FIELD_FLAG_READ_ONLY, &animation_graph_node_block },
		{ _field_short_block_index, "first child node index", FIELD_FLAG_READ_ONLY, &animation_graph_node_block },
		{ _field_short_block_index, "parent node index", FIELD_FLAG_READ_ONLY, &animation_graph_node_block },
		{ _field_byte_flags, "model flags", FIELD_FLAG_READ_ONLY, &animation_node_model_flags },
		{ _field_byte_flags, "node joint flags", &node_joint_flags },
		{ _field_byte_flags, "additional flags", &node_info_flags },
		FIELD_PAD("NOD", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_real_vector_3d, "base vector", FIELD_FLAG_READ_ONLY },
		{ _field_real, "vector range", FIELD_FLAG_READ_ONLY },
		{ _field_real, "z_pos", FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "frame_ID1", FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "frame_ID2", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define ANIMATION_NODE_MASK_BLOCK_ID { 0xBC821943, 0x591C4DFA, 0xBF374F7B, 0x7E2BDCD8 }
	TAG_BLOCK(
		animation_node_mask_block,
		"animation_node_mask_block",
		k_animation_maximum_node_mask_count,
		"s_animation_node_mask",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		ANIMATION_NODE_MASK_BLOCK_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_block, "nodes", &animation_node_mask_entry_block },
		{ _field_array, "node flags", FIELD_FLAG_UNKNOWN0, &g_node_flag_storage_array },
		{ _field_terminator }
	};

	#define ANIMATION_NODE_MASK_ENTRY_BLOCK_ID { 0x7A9DBE1F, 0x6A2B4DED, 0xBE03214D, 0xD964D836 }
	TAG_BLOCK(
		animation_node_mask_entry_block,
		"animation_node_mask_entry_block",
		k_max_nodes_per_animation,
		"s_animation_node_mask_entry",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		ANIMATION_NODE_MASK_ENTRY_BLOCK_ID)
	{
		{ _field_short_block_index, "node", FIELD_FLAG_INDEX, &animation_graph_node_block },
		FIELD_PAD("anbfp", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	#define ANIMATION_FUNCTION_BLOCK_ID { 0xEA6DD3E1, 0x42A447C1, 0xA68A00FD, 0xDD681208 }
	TAG_BLOCK(
		animation_function_block,
		"animation_function_block",
		k_animation_maximum_function_count,
		"s_animation_function",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		ANIMATION_FUNCTION_BLOCK_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_struct, "function", &scalar_function_named_struct },
		{ _field_terminator }
	};

	#define MODEL_ANIMATION_VARIANT_BLOCK_ID { 0xFD63AA7E, 0x0C884058, 0x9FA74CD9, 0x53B1BCA6 }
	TAG_BLOCK(
		model_animation_variant_block,
		"model_animation_variant_block",
		k_animation_maximum_model_variants,
		"s_model_animation_variant",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		MODEL_ANIMATION_VARIANT_BLOCK_ID)
	{
		{ _field_string_id, "variant name", FIELD_FLAG_INDEX },
		{ _field_long_flags, "variant flags", &model_animation_variant_flags },
		{ _field_block, "mode or stance aliases", &mode_or_stance_alias_block },
		{ _field_terminator }
	};

	#define MODE_OR_STANCE_ALIAS_BLOCK_STRUCT_ID { 0xC7C10AFC, 0x369245FF, 0x8F012522, 0x3A3A5FA6 }
	TAG_BLOCK(
		mode_or_stance_alias_block,
		"mode_or_stance_alias_block",
		k_animation_maximum_mode_or_stance_aliases,
		"s_mode_or_stance_alias",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		MODE_OR_STANCE_ALIAS_BLOCK_STRUCT_ID)
	{
		{ _field_string_id, "mode or stance" },
		{ _field_string_id, "alias" },
		{ _field_terminator }
	};

	#define ANIMATION_BLEND_SCREEN_BLOCK_ID { 0xED41E38F, 0x7F884652, 0xAC5624AC, 0x23F6E113 }
	TAG_BLOCK(
		animation_blend_screen_block,
		"animation_blend_screen_block",
		k_animation_maximum_blend_screens,
		"s_animation_blend_screen",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		ANIMATION_BLEND_SCREEN_BLOCK_ID)
	{
		{ _field_string_id, "label", FIELD_FLAG_INDEX },
		{ _field_struct, "aiming screen", FIELD_FLAG_READ_ONLY, &animation_aiming_screen_struct },
		{ _field_terminator }
	};

	#define FOOT_TRACKING_MEMBER_BLOCK_ID { 0xD066D043, 0x7AF34927, 0xB01540CE, 0x43143EB4 }
	TAG_BLOCK(
		foot_tracking_member_block,
		"foot_tracking_member_block",
		k_max_tracked_feet,
		"s_foot_tracking_member",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		FOOT_TRACKING_MEMBER_BLOCK_ID)
	{
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_marker),
		{ _field_string_id, "foot marker name", FIELD_FLAG_INDEX },
		{ _field_real_bounds, "foot ik range" },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_marker),
		{ _field_string_id, "ankle marker name" },
		{ _field_real_bounds, "ankle ik range" },
		{ _field_enum, "default state", &foot_tracking_default_values },
		FIELD_PAD("f00t1", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	#define ANIMATION_POOL_BLOCK_STRUCT_ID { 0x23454382, 0xA8A14CE8, 0xA1D2C1FD, 0x7F41203E }
	TAG_BLOCK(
		animation_pool_block,
		"animation_pool_block",
		k_max_animations_per_graph,
		"c_model_animation",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		ANIMATION_POOL_BLOCK_STRUCT_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_READ_ONLY | FIELD_FLAG_INDEX },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_default),
		{ _field_real, "weight" },
		{ _field_short_integer, "loop frame index" },
		{ _field_word_flags, "user flags", MAKE_OLD_NAMES("playback flags"), &animation_index_flags },
		{ _field_real, "override blend in time", MAKE_OLD_NAMES("override blend time") },
		{ _field_real, "override blend out time" },
		{ _field_short_block_index, "parent animation", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &animation_pool_block },
		{ _field_short_block_index, "next animation", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &animation_pool_block },
		{ _field_word_flags, "production flags", &production_status_flags },
		{ _field_short_block_index, "composite", FIELD_FLAG_READ_ONLY, &g_compositeTag_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		FIELD_EXPLANATION("PCA Group Link", nullptr, FIELD_FLAG_NONE, "If this animation contains PCA blend shape animation,\nprovide the name of the PCA Group to which it belongs.\nThese groups should be present in the PCA Groups block."),
		{ _field_string_id, "pca group name" },

		FIELD_EXPLANATION("Shared Animation Data", nullptr, FIELD_FLAG_NONE, "data which may be shared by one or more animations"),
		{ _field_struct, "shared animation reference", FIELD_FLAG_UNKNOWN0, &shared_animation_reference_block },
		{ _field_block, "shared animation data", &shared_model_animation_block },
		{ _field_terminator }
	};

	#define SHARED_MODEL_ANIMATION_BLOCK_ID { 0x2D18070E, 0x74B14322, 0xA7045C6F, 0x2D55B8F6 }
	TAG_BLOCK(
		shared_model_animation_block,
		"shared_model_animation_block",
		1,
		"c_shared_model_animation",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SHARED_MODEL_ANIMATION_BLOCK_ID)
	{
		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_short_integer, "frame count", FIELD_FLAG_READ_ONLY },

		{ _field_byte_integer, "node count", FIELD_FLAG_READ_ONLY },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 2 },
		{ _field_legacy, _field_pad, "pad", 1 },
		{ _field_legacy, _field_short_integer, "frame count*" },

		{ _field_char_enum, "animation type", FIELD_FLAG_READ_ONLY, &animation_type_enum },
		{ _field_char_enum, "frame info type", FIELD_FLAG_READ_ONLY, &frame_info_type_enum },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_char_enum, "desired frame info type", FIELD_FLAG_READ_ONLY, &frame_info_type_enum },

		{ _field_char_enum, "desired compression", &compression_settings },
		{ _field_char_enum, "current compression", FIELD_FLAG_READ_ONLY, &compression_settings },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_word_flags, "production flags", &production_status_flags },

		{ _field_word_flags, "internal flags", FIELD_FLAG_READ_ONLY, &internal_animation_flags },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_short_integer, "compressor_version", FIELD_FLAG_READ_ONLY },

		{ _field_long_integer, "uid", FIELD_FLAG_READ_ONLY },
		{ _field_string_id, "shared id", FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "node list checksum", FIELD_FLAG_READ_ONLY },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 3 },
		{ _field_legacy, _field_long_integer, "production checksum" }, // unknown
		{ _field_legacy, _field_short_integer, "unknown" },
		{ _field_legacy, _field_short_integer, "unknown" },

		{ _field_short_integer, "resource_group", FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "resource_group_member", FIELD_FLAG_READ_ONLY },
		{ _field_real_vector_3d, "heading", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_real, "heading angle", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },

		{ _field_real, "average translation magnitude", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real, "average pivot yaw", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		FIELD_EXPLANATION("a", nullptr, FIELD_FLAG_UNKNOWN0, "IMPORTANT NOTES ABOUT FRAME EVENTS\n1) The following four fields (hidden except in expert mode) are legacy Halo3-style tag blocks.\n2) New frame events (attached to animations in Maya) will automagically be exported to\n   the frame_event_list any time a model sidecar is imported with the tool import command.\n3) Do not add new frame events, fx events, audio events, or dialog events here.  Instead,\n   please use the frame_event_list tag referenced in \'imported events\' (it\'s right above the\n   \'animations\' tag block).\n4) The only time you should be editing the following hidden fields is to remove legacy\n   frame events that have been replaced by events generated in Maya.\n"),
		{ _field_block, "frame events", "Legacy field - please edit in new frame event tag below", &animation_frame_event_block },
		{ _field_block, "sound events", "Legacy field - please edit in new frame event tag below", &animation_sound_event_block },
		{ _field_block, "effect events", "Legacy field - please edit in new frame event tag below", &animation_effect_event_block },
		{ _field_block, "dialogue events", "Legacy field - please edit in new frame event tag below", &animation_dialogue_event_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_block, "script events", "Legacy field - please edit in new frame event tag below", &animation_script_event_block },

		FIELD_EXPLANATION("b", nullptr, FIELD_FLAG_UNKNOWN0, ""),
		{ _field_block, "object-space parent nodes", &object_space_node_data_block },
		{ _field_block, "foot tracking", &foot_tracking_block },
		{ _field_block, "object space offset nodes", &object_space_offset_node_block },
		{ _field_block, "forward-invert kinetic anchor nodes", &fik_anchor_node_block },
		{ _field_block, "ik chain events", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &animation_ik_chain_events_block },
		{ _field_block, "ik chain proxies", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &animation_ik_chain_proxies_block },
		{ _field_block, "facial wrinkle events", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &animation_facial_wrinkle_events_block },
		{ _field_block, "extended data events", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &animation_extended_events_block },
		{ _field_block, "animation object functions", &animation_object_functions_block },
		{ _field_terminator }
	};

	#define ANIMATION_FRAME_EVENT_BLOCK_STRUCT_ID { 0x4B542454, 0x08634540, 0x94899D46, 0x7CF531E1 }
	TAG_BLOCK(
		animation_frame_event_block,
		"animation_frame_event_block",
		k_max_frame_events,
		"s_frame_event",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		ANIMATION_FRAME_EVENT_BLOCK_STRUCT_ID)
	{
		{ _field_enum, "type", &frame_event_type_new },
		{ _field_short_integer, "frame" },
		{ _field_terminator }
	};

	#define ANIMATION_SOUND_EVENT_BLOCK_ID { 0xB35BC4A2, 0x13E84535, 0x99DC4BB0, 0x8C7AEE2F }
	TAG_BLOCK(
		animation_sound_event_block,
		"animation_sound_event_block",
		k_max_frame_events,
		"s_sound_event",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		ANIMATION_SOUND_EVENT_BLOCK_ID)
	{
		{ _field_short_block_index, "sound", &animation_graph_sound_reference_block },
		{ _field_short_integer, "frame" },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_marker),
		{ _field_string_id, "marker name" },
		{ _field_terminator }
	};

	#define ANIMATION_EFFECT_EVENT_BLOCK_ID { 0xE4CD0730, 0x8A8342C9, 0xB1A8EE0B, 0x73E441C9 }
	TAG_BLOCK(
		animation_effect_event_block,
		"animation_effect_event_block",
		k_max_frame_events,
		"animation_effect_event_block",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		ANIMATION_EFFECT_EVENT_BLOCK_ID)
	{
		{ _field_short_block_index, "effect", &animation_graph_effect_reference_block },
		{ _field_short_integer, "frame" },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_marker),
		{ _field_string_id, "marker name" },
		{ _field_char_enum, "damage effect reporting type", &global_damage_reporting_enum_definition },
		FIELD_PAD("eefpd1", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_terminator }
	};

	#define ANIMATION_DIALOGUE_EVENT_BLOCK_ID { 0x2A844863, 0x9AAD473C, 0x93A75C3E, 0xD1BF6F0E }
	TAG_BLOCK(
		animation_dialogue_event_block,
		"animation_dialogue_event_block",
		k_max_frame_events,
		"s_dialogue_event",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		ANIMATION_DIALOGUE_EVENT_BLOCK_ID)
	{
		{ _field_enum, "dialogue event", &animation_dialogue_event_enum },
		{ _field_short_integer, "frame" },
		{ _field_terminator }
	};

	#define ANIMATION_SCRIPT_EVENT_BLOCK_ID { 0x9E86771B, 0x03D44413, 0xBDD6E1C3, 0xF22F7BB5 }
	TAG_BLOCK(
		animation_script_event_block,
		"animation_script_event_block",
		k_max_frame_events,
		"s_script_event",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		ANIMATION_SCRIPT_EVENT_BLOCK_ID)
	{
		{ _field_string_id, "script name" },
		{ _field_short_integer, "frame" },
		FIELD_PAD("pad", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	#define OBJECT_SPACE_NODE_DATA_BLOCK_ID { 0x27BCCD47, 0x04C147A1, 0x9D4D4A77, 0xFA16E702 }
	TAG_BLOCK(
		object_space_node_data_block,
		"object_space_node_data_block",
		k_max_nodes_per_animation,
		"s_object_space_node_data",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		OBJECT_SPACE_NODE_DATA_BLOCK_ID)
	{
		{ _field_short_block_index, "node index", MAKE_OLD_NAMES("node_index"), FIELD_FLAG_INDEX, &animation_graph_node_block },
		{ _field_word_flags, "flags", FIELD_FLAG_READ_ONLY, &object_space_node_flags },
		{ _field_struct, "parent orientation", MAKE_OLD_NAMES("orientation"), FIELD_FLAG_READ_ONLY, &quantized_orientation_struct },
		{ _field_terminator }
	};

	#define FOOT_TRACKING_BLOCK_ID { 0x65A0785D, 0x1C8B4E74, 0xB942B141, 0x5D95DF9E }
	TAG_BLOCK(
		foot_tracking_block,
		"foot_tracking_block",
		k_max_tracked_feet,
		"s_foot_tracking_data",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		FOOT_TRACKING_BLOCK_ID)
	{
		{ _field_short_block_index, "foot", &foot_tracking_member_block },
		FIELD_PAD("f00t2", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_block, "cycles", &foot_lock_cycle_block },
		{ _field_terminator }
	};

	#define FOOT_LOCK_CYCLE_BLOCK_ID { 0xB3A64A4C, 0x6BC544B3, 0xAAAC4AF4, 0xA16E5881 }
	TAG_BLOCK(
		foot_lock_cycle_block,
		"foot_lock_cycle_block",
		k_max_cycles_per_tracked_foot,
		"s_foot_lock_cycle",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		FOOT_LOCK_CYCLE_BLOCK_ID)
	{
		{ _field_short_integer, "start locking" },
		{ _field_short_integer, "locked" },
		{ _field_short_integer, "start unlocking" },
		{ _field_short_integer, "unlocked" },
		{ _field_real_point_3d, "lock point", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define OBJECT_SPACE_OFFSET_NODE_BLOCK_ID { 0xF10FB882, 0x00154F22, 0x8BF8942F, 0xBBEBAE8A }
	TAG_BLOCK(
		object_space_offset_node_block,
		"object_space_offset_node_block",
		k_max_object_space_offset_node_count,
		"s_object_space_offset_node_reference",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		OBJECT_SPACE_OFFSET_NODE_BLOCK_ID)
	{
		{ _field_short_block_index, "object space offset node", FIELD_FLAG_INDEX, &animation_graph_node_block },
		FIELD_PAD("wsonbp", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	#define FIK_ANCHOR_NODE_BLOCK_ID { 0x34216E16, 0xB26A414B, 0xA0C0515C, 0x926F5CFF }
	TAG_BLOCK(
		fik_anchor_node_block,
		"fik_anchor_node_block",
		k_max_fik_anchor_node_count,
		"s_fik_anchor_node_reference",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		FIK_ANCHOR_NODE_BLOCK_ID)
	{
		{ _field_short_block_index, "anchor node", FIELD_FLAG_INDEX, &animation_graph_node_block },
		FIELD_PAD("dse", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(
		animation_ik_chain_events_block,
		"animation_ik_chain_events",
		k_animation_maximum_ik_chain_events,
		animation_ik_chain_events_struct);

	TAG_BLOCK_FROM_STRUCT(
		animation_ik_chain_proxies_block,
		"animation_ik_chain_proxies",
		k_animation_maximum_ik_chain_proxies,
		animation_ik_chain_proxies_struct);

	TAG_BLOCK_FROM_STRUCT(
		animation_facial_wrinkle_events_block,
		"animation_facial_wrinkle_events",
		k_animation_maximum_facial_wrinkle_events,
		animation_facial_wrinkle_events_struct);

	TAG_BLOCK_FROM_STRUCT(
		animation_extended_events_block,
		"animation_extended_events",
		k_animation_maximum_extended_events,
		animation_extended_events_struct);

	TAG_BLOCK_FROM_STRUCT(
		animation_object_functions_block,
		"animation_object_functions",
		k_animation_maximum_object_functions,
		animation_object_functions_struct);

	#define NEW_ANIMATION_BLEND_SCREEN_BLOCK_STRUCT_ID { 0xA19A4F54, 0x33704B09, 0x8889289B, 0xCBDA74EE }
	TAG_BLOCK(
		new_animation_blend_screen_block,
		"new_animation_blend_screen_block",
		k_animation_maximum_blend_screens,
		"s_new_animation_blend_screen",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_IS_MEMCPYABLE | SET_UNKNOWN15 | 
		SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		NEW_ANIMATION_BLEND_SCREEN_BLOCK_STRUCT_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_long_flags, "flags", &blend_screen_definition_flags },
		{ _field_real, "weight" },
		{ _field_real_fraction, "interpolation rate", "A value of zero or one means no interpolation.", nullptr, "[0,1]" },
		FIELD_PAD("nabsbfp0", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_enum, "yaw source", &blend_screen_variable_sources },
		{ _field_enum, "pitch source", &blend_screen_variable_sources },
		{ _field_enum, "weight source", &blend_screen_weight_sources },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_unknown_function),
		{ _field_string_id, "yaw source object function" },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_unknown_function),
		{ _field_string_id, "pitch source object function" },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_unknown_function),
		{ _field_string_id, "weight source object function" },
		{ _field_short_block_index, "weight function", "Function applied to input from weight function source", &animation_function_block },
		FIELD_PAD("nabsbfp1", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_struct, "animation", MAKE_OLD_NAMES("animation info"), &animation_index_struct },
		{ _field_terminator }
	};

	#define NEW_ANIMATION_FUNCTION_OVERLAY_BLOCK_ID { 0x91C27244, 0x40FD4B06, 0xACBDAAB1, 0x42BF1AB9 }
	TAG_BLOCK(
		new_animation_function_overlay_block,
		"new_animation_function_overlay_block",
		k_animation_maximum_function_overlays,
		"s_new_animation_function_overlay",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_IS_MEMCPYABLE | SET_UNKNOWN15 | 
		SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		NEW_ANIMATION_FUNCTION_OVERLAY_BLOCK_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_long_flags, "flags", &function_overlay_definition_flags },
		FIELD_EXPLANATION("Frame Ratio or Playback Speed", nullptr, FIELD_FLAG_NONE, "Enter either or leave blank.  Entering both will default to frame ratio option for playback control."),
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_unknown_function),
		{ _field_string_id, "frame ratio object function" },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_unknown_function),
		{ _field_string_id, "playback speed object function" },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_unknown_function),
		{ _field_string_id, "blend weight object function" },
		{ _field_struct, "animation", &animation_index_struct },
		{ _field_terminator }
	};

	#define OVERLAY_GROUP_DEFINITION_BLOCK_ID { 0xB0C28EAA, 0xAD92455C, 0xBCF71470, 0x116D2507 }
	TAG_BLOCK(
		overlay_group_definition_block,
		"overlay_group_definition_block",
		k_animation_maximum_overlay_groups,
		"s_overlay_group",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		OVERLAY_GROUP_DEFINITION_BLOCK_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_block, "blend screens", MAKE_OLD_NAMES("blend screen"), &blend_screen_item_definition_block },
		{ _field_block, "function overlays", &function_overlay_item_definition_block },
		{ _field_terminator }
	};

	#define BLEND_SCREEN_ITEM_DEFINITION_BLOCK_ID { 0xE8D056F9, 0xE4964C6B, 0xB217CB43, 0x50267C7B }
	TAG_BLOCK(
		blend_screen_item_definition_block,
		"blend_screen_item_definition_block",
		k_animation_maximum_mixing_board_pose_overlays,
		"s_blend_screen_item",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		BLEND_SCREEN_ITEM_DEFINITION_BLOCK_ID)
	{
		{ _field_short_block_index, "blend screen", FIELD_FLAG_INDEX, &new_animation_blend_screen_block },
		{ _field_word_flags, "flags", &pose_overlay_item_definition_block_flags },
		{ _field_short_block_index, "node mask", &animation_node_mask_block },
		FIELD_PAD("bsidbfp", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	#define FUNCTION_OVERLAY_ITEM_DEFINITION_BLOCK_ID { 0x88CDC66F, 0xED3344A6, 0x9832DB93, 0x49C99955 }
	TAG_BLOCK(
		function_overlay_item_definition_block,
		"function_overlay_item_definition_block",
		k_animation_maximum_function_overlays,
		"s_function_overlay_item",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		FUNCTION_OVERLAY_ITEM_DEFINITION_BLOCK_ID)
	{
		{ _field_short_block_index, "function overlay", FIELD_FLAG_INDEX, &new_animation_function_overlay_block },
		{ _field_word_flags, "flags", &pose_overlay_item_definition_block_flags },
		{ _field_terminator }
	};

	#define ANIMATION_GAIT_BLOCK_ID { 0x1A9E57D4, 0x76F24572, 0x9C1B7CA7, 0x96F136C6 }
	TAG_BLOCK(
		animation_gait_block,
		"animation_gait_block",
		k_animation_maximum_gaits,
		"s_animation_gait",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		ANIMATION_GAIT_BLOCK_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_string_id, "slow gait name" },
		{ _field_string_id, "intermediate gait name", "animation name used for the speed variations" },
		{ _field_string_id, "fast gait name" },
		{ _field_enum, "move state", &animation_gait_directions },
		FIELD_PAD("pad", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	#define ANIMATION_GAIT_GROUP_BLOCK_ID { 0xA7445115, 0x80D3421A, 0xB4D73C75, 0xCF80911B }
	TAG_BLOCK(
		animation_gait_group_block,
		"animation_gait_group_block",
		k_animation_maximum_gait_groups,
		"s_animation_gait_group",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		ANIMATION_GAIT_GROUP_BLOCK_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_block, "animation gaits", &animation_gait_item_block },
		{ _field_terminator }
	};

	#define ANIMATION_GAIT_ITEM_BLOCK_ID { 0xE81E90AA, 0x3B3E499E, 0xAD373A6C, 0xD8A879E6 }
	TAG_BLOCK(
		animation_gait_item_block,
		"animation_gait_item_block",
		k_animation_maximum_gaits,
		"s_animation_gait_item",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		ANIMATION_GAIT_ITEM_BLOCK_ID)
	{
		{ _field_short_block_index, "animation gait", FIELD_FLAG_INDEX, &animation_gait_block },
		FIELD_PAD("agibfap", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	#define ANIMATION_IK_BLOCK_ID { 0x732332F9, 0xD36A4D89, 0x8815B353, 0xC36A39FC }
	TAG_BLOCK(
		animation_ik_block,
		"animation_ik_block",
		k_max_ik_points,
		"s_animation_ik_point",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		ANIMATION_IK_BLOCK_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_string_id, "source marker", "the marker name on this object where the point of attachment is" },
		{ _field_long_enum, "attach to", &animation_ik_target_enum_definition },
		{ _field_string_id, "destination marker", "the marker name of the attachment destination point" },
		{ _field_real_point_3d, "pole marker" },
		{ _field_terminator }
	};

	#define ANIMATION_IK_SET_ID { 0xBC56DF32, 0xC0D04CDF, 0xBC3D6BF1, 0x5E7C50D8 }
	TAG_BLOCK(
		animation_ik_set_block,
		"animation_ik_set",
		k_max_ik_sets,
		"s_animation_ik_set",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		ANIMATION_IK_SET_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_block, "ik points", &animation_ik_set_item_block },
		{ _field_terminator }
	};

	#define ANIMATION_IK_SET_ITEM_ID { 0xB344E2ED, 0x59874CF7, 0x8590B239, 0xFB3DEA22 }
	TAG_BLOCK(
		animation_ik_set_item_block,
		"animation_ik_set_item",
		k_max_ik_points_per_set,
		"s_animation_ik_set_item",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		ANIMATION_IK_SET_ITEM_ID)
	{
		{ _field_short_block_index, "ik point", FIELD_FLAG_INDEX, &animation_ik_block },
		{ _field_word_flags, "flags", &animation_ik_set_item_flags },
		{ _field_terminator }
	};

	#define ANIMATION_IK_CHAIN_BLOCK_ID { 0xF5CF2BD8, 0x628649D3, 0xA1BEB57B, 0xAF40B16B }
	TAG_BLOCK(
		animation_ik_chain_block,
		"animation_ik_chain_block",
		k_animation_maximum_ik_chains,
		"s_animation_ik_chain",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		ANIMATION_IK_CHAIN_BLOCK_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_enum, "type", &animation_ik_chain_type_enumeration },
		FIELD_PAD("aikcbp", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_short_block_index, "start node", MAKE_OLD_NAMES("grandparent node"), &animation_graph_node_block },
		{ _field_short_block_index, "effector node", &animation_graph_node_block },
		{ _field_short_integer, "rank", "calculated during post process where rank is default ordinal for solving", FIELD_FLAG_UNKNOWN0 },
		{ _field_short_integer, "antecedents", "calculated during post process where bit index represents chain index", FIELD_FLAG_UNKNOWN0 },
		{ _field_terminator }
	};

	#define PCAGROUPSETTINGSBLOCK_ID { 0xD0D44006, 0x2B0C4A76, 0xBBB72712, 0xAA03726E }
	TAG_BLOCK(
		PCAGroupSettingsBlock_block,
		"PCAGroupSettingsBlock",
		k_max_animations_per_graph,
		"PCAGroupSettings",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PCAGROUPSETTINGSBLOCK_ID)
	{
		{ _field_string_id, "Group Name", FIELD_FLAG_INDEX },
		{ _field_long_integer, "Desired Mesh Count" },
		{ _field_terminator }
	};

	#define ANIMATION_MODE_BLOCK_ID { 0x8D89D744, 0x83E7433C, 0xB92A43A6, 0x063E43E4 }
	TAG_BLOCK(
		animation_mode_block,
		"animation_mode_block",
		k_max_modes_per_graph,
		"c_animation_mode",
		SET_UNKNOWN0 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | 
		SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		ANIMATION_MODE_BLOCK_ID)
	{
		{ _field_string_id, "label", FIELD_FLAG_INDEX },
		{ _field_short_block_index, "overlay group", MAKE_OLD_NAMES("pose overlay|overlay"), &overlay_group_definition_block },
		{ _field_short_block_index, "ik set", &animation_ik_set_block },
		{ _field_long_flags, "flags", FIELD_FLAG_READ_ONLY, &animation_mode_flags },
		{ _field_block, "weapon class", &weapon_class_block },
		{ _field_block, "mode ik", &animation_ik_block_v1_block },
		{ _field_block, "foot defaults", &foot_tracking_defaults_block },
		{ _field_terminator }
	};

	#define WEAPON_CLASS_BLOCK_STRUCT_ID { 0x4ECAAE41, 0xD23D4E20, 0xAAF8CE65, 0xF261D1BB }
	TAG_BLOCK(
		weapon_class_block,
		"weapon_class_block",
		k_max_weapon_classes,
		"c_weapon_class",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		WEAPON_CLASS_BLOCK_STRUCT_ID)
	{
		{ _field_string_id, "label", FIELD_FLAG_INDEX },
		{ _field_short_block_index, "overlay group", MAKE_OLD_NAMES("pose overlay|overlay"), &overlay_group_definition_block },
		{ _field_short_block_index, "ik set", &animation_ik_set_block },
		{ _field_block, "weapon type", &weapon_type_block },
		{ _field_block, "weapon ik", &animation_ik_block_v1_block },
		{ _field_block, "ranged actions", &animation_ranged_action_block },
		{ _field_block, "sync actions groups", &animation_sync_action_group_block },
		{ _field_terminator }
	};

	#define WEAPON_TYPE_BLOCK_STRUCT_ID { 0x8238C4F4, 0x57964DFD, 0x95379F24, 0x49275A4A }
	TAG_BLOCK(
		weapon_type_block,
		"weapon_type_block",
		k_max_weapon_types,
		"c_weapon_type",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		WEAPON_TYPE_BLOCK_STRUCT_ID)
	{
		{ _field_string_id, "label", FIELD_FLAG_INDEX },
		{ _field_short_block_index, "overlay group", MAKE_OLD_NAMES("pose overlay|overlay"), &overlay_group_definition_block },
		{ _field_short_block_index, "ik set", &animation_ik_set_block },
		{ _field_block, "sets", &animation_set_block },
		{ _field_terminator }
	};

	#define ANIMATION_SET_BLOCK_ID { 0x76D6B7C8, 0x96FE4EBE, 0xA4EA7C64, 0xFD2B9FDA }
	TAG_BLOCK(
		animation_set_block,
		"animation_set_block",
		k_max_animation_sets,
		"c_animation_set",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		ANIMATION_SET_BLOCK_ID)
	{
		{ _field_string_id, "label", FIELD_FLAG_INDEX },
		{ _field_short_block_index, "overlay group", MAKE_OLD_NAMES("pose overlay|overlay"), &overlay_group_definition_block },
		{ _field_short_block_index, "ik set", &animation_ik_set_block },
		{ _field_short_block_index, "gait group", &animation_gait_group_block },
		FIELD_PAD("asbfap", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_block, "actions", &animation_entry_block },
		{ _field_block, "overlay animations", MAKE_OLD_NAMES("overlays"), &animation_entry_block },
		{ _field_block, "death and damage", &damage_animation_block },
		{ _field_block, "transitions", &animation_transition_source_block },
		{ _field_block, "velocity boundaries", FIELD_FLAG_UNKNOWN0, &animation_velocity_boundaries_block },
		{ _field_terminator }
	};

	#define ANIMATION_ENTRY_BLOCK_ID { 0xED625457, 0xB4F24A9B, 0x864B5469, 0x3C760EF5 }
	TAG_BLOCK(
		animation_entry_block,
		"animation_entry_block",
		k_max_animations_per_block,
		"s_animation_entry",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_IS_MEMCPYABLE | SET_UNKNOWN15 | 
		SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		ANIMATION_ENTRY_BLOCK_ID)
	{
		{ _field_string_id, "label", FIELD_FLAG_INDEX },
		{ _field_short_block_index, "overlay group", MAKE_OLD_NAMES("pose overlay|overlay"), &overlay_group_definition_block },
		{ _field_short_block_index, "ik set", &animation_ik_set_block },
		{ _field_struct, "animation", &animation_index_struct },
		{ _field_terminator }
	};

	#define DAMAGE_ANIMATION_BLOCK_ID { 0x3ACB8A45, 0x68F24D9F, 0xA55254BA, 0x727902FD }
	TAG_BLOCK(
		damage_animation_block,
		"damage_animation_block",
		k_max_death_and_damage_actions,
		"s_animation_damage_actions",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		DAMAGE_ANIMATION_BLOCK_ID)
	{
		{ _field_string_id, "label", FIELD_FLAG_INDEX },
		{ _field_block, "directions", FIELD_FLAG_READ_ONLY, &damage_direction_block },
		{ _field_terminator }
	};

	#define DAMAGE_DIRECTION_BLOCK_ID { 0x08E94A96, 0x4DFE4AA9, 0xB50211A8, 0x1BE40FED }
	TAG_BLOCK(
		damage_direction_block,
		"damage_direction_block",
		k_total_damage_directions,
		"s_animation_damage_direction",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		DAMAGE_DIRECTION_BLOCK_ID)
	{
		{ _field_block, "regions", FIELD_FLAG_READ_ONLY, &damage_region_block },
		{ _field_terminator }
	};

	#define DAMAGE_REGION_BLOCK_ID { 0xC4A06F84, 0x33324424, 0x85ABA033, 0x78C5D41C }
	TAG_BLOCK(
		damage_region_block,
		"damage_region_block",
		k_total_damage_regions,
		"c_animation_id",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		DAMAGE_REGION_BLOCK_ID)
	{
		{ _field_struct, "animation", FIELD_FLAG_READ_ONLY, &animation_index_struct },
		{ _field_terminator }
	};

	#define ANIMATION_TRANSITION_SOURCE_BLOCK_STRUCT_ID { 0x21A980DD, 0x4CB746B8, 0xAB7E811F, 0x14E7A714 }
	TAG_BLOCK(
		animation_transition_source_block,
		"animation_transition_source_block",
		k_max_animations_per_block,
		"s_animation_transition_source",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		ANIMATION_TRANSITION_SOURCE_BLOCK_STRUCT_ID)
	{
		{ _field_string_id, "state name", "name of the state this transition starts in", FIELD_FLAG_INDEX },
		{ _field_block, "destinations", &animation_transition_destination_block },
		{ _field_terminator }
	};

	#define ANIMATION_TRANSITION_DESTINATION_BLOCK_ID { 0xFA4C76F9, 0xB84A45F0, 0xAC868FEA, 0xE0D1DC8B }
	TAG_BLOCK(
		animation_transition_destination_block,
		"animation_transition_destination_block",
		k_max_transition_animations,
		"s_animation_transition_destination",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_IS_MEMCPYABLE | SET_UNKNOWN15 | 
		SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		ANIMATION_TRANSITION_DESTINATION_BLOCK_ID)
	{
		{ _field_string_id, "mode name", "name of the mode this transition ends in" },
		{ _field_string_id, "state name", "name of the state this transition ends in" },
		{ _field_struct, "animation", &animation_index_struct },
		{ _field_terminator }
	};

	#define ANIMATION_VELOCITY_BOUNDARIES_BLOCK_ID { 0x7DB78F23, 0x0F92412A, 0xA5FFBF86, 0x73473212 }
	TAG_BLOCK(
		animation_velocity_boundaries_block,
		"animation_velocity_boundaries_block",
		1,
		"s_animation_velocity_boundaries",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		ANIMATION_VELOCITY_BOUNDARIES_BLOCK_ID)
	{
		{ _field_array, "velocity boundary entries", FIELD_FLAG_UNKNOWN0, &animation_velocity_boundaries_array },
		{ _field_terminator }
	};

	#define ANIMATION_IK_BLOCK_V1_ID { 0x298A3519, 0x24ED45D8, 0xB9C03830, 0x956878DD }
	TAG_BLOCK(
		animation_ik_block_v1_block,
		"animation_ik_block_v1",
		k_max_ik_points,
		"s_animation_ik_point_v1",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		ANIMATION_IK_BLOCK_V1_ID)
	{
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_marker),
		{ _field_string_id, "marker", "the marker name on the object being attached" },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_marker),
		{ _field_string_id, "attach to marker", "the marker name object (weapon, vehicle, etc.) the above marker is being attached to" },
		{ _field_terminator }
	};

	#define ANIMATION_RANGED_ACTION_BLOCK_ID { 0x95A9A8F2, 0x09CE4561, 0xB1077B2B, 0xA6B04BCF }
	TAG_BLOCK(
		animation_ranged_action_block,
		"animation_ranged_action_block",
		k_max_ranged_actions,
		"s_animation_ranged_action",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		ANIMATION_RANGED_ACTION_BLOCK_ID)
	{
		{ _field_string_id, "label", FIELD_FLAG_INDEX },
		{ _field_block, "animations", &ranged_animation_entry_block },
		{ _field_block, "triangulation data", FIELD_FLAG_UNKNOWN0, &triangulation_entry_block },
		{ _field_enum, "horizontal source", &ranged_action_variable_sources },
		{ _field_enum, "vertical source", &ranged_action_variable_sources },
		{ _field_enum, "start key", &frame_event_type_new },
		{ _field_enum, "end key", &frame_event_type_new },
		{ _field_terminator }
	};

	#define RANGED_ANIMATION_ENTRY_BLOCK_STRUCT_ID { 0x951AB02D, 0xA1C6432B, 0x96E32919, 0x7BBE629D }
	TAG_BLOCK(
		ranged_animation_entry_block,
		"ranged_animation_entry_block",
		k_max_animations_per_block,
		"s_ranged_animation_entry",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		RANGED_ANIMATION_ENTRY_BLOCK_STRUCT_ID)
	{
		{ _field_short_block_index, "overlay group", MAKE_OLD_NAMES("pose overlay|overlay"), &overlay_group_definition_block },
		{ _field_short_block_index, "ik set", &animation_ik_set_block },
		{ _field_struct, "animation", &animation_index_struct },
		{ _field_real, "animation parameter", "Numerical value associated with the ranged action animation (e.g. velocity for jumps)" },
		{ _field_real, "animation parameter b" },
		{ _field_terminator }
	};

	#define TRIANGULATION_ENTRY_BLOCK_ID { 0x8234CC8B, 0x381A41C5, 0x89E7A030, 0xE1048287 }
	TAG_BLOCK(
		triangulation_entry_block,
		"triangulation_entry_block",
		1,
		"s_triangulation_tag_struct",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		TRIANGULATION_ENTRY_BLOCK_ID)
	{
		{ _field_block, "points", &triangulation_point_block },
		{ _field_block, "triangles", &triangulation_triangle_block },
		{ _field_terminator }
	};

	#define TRIANGULATION_POINT_BLOCK_ID { 0x71BE4C3B, 0x3051498A, 0xAF9A5CC0, 0xB1712567 }
	TAG_BLOCK(
		triangulation_point_block,
		"triangulation_point_block",
		k_max_triangulation_tag_points,
		"real_point2d",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		TRIANGULATION_POINT_BLOCK_ID)
	{
		{ _field_real_vector_2d, "point" },
		{ _field_terminator }
	};

	#define TRIANGULATION_TRIANGLE_BLOCK_ID { 0x833E138E, 0x59ED4E6B, 0x8327B280, 0x9FAEC685 }
	TAG_BLOCK(
		triangulation_triangle_block,
		"triangulation_triangle_block",
		k_max_triangulation_tag_triangles,
		"s_blend_screen_delaunay_triangle",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		TRIANGULATION_TRIANGLE_BLOCK_ID)
	{
		{ _field_byte_integer, "vertex1" },
		{ _field_byte_integer, "vertex2" },
		{ _field_byte_integer, "vertex3" },
		{ _field_byte_integer, "link12" },
		{ _field_byte_integer, "link23" },
		{ _field_byte_integer, "link31" },
		FIELD_PAD("aaah", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	#define ANIMATION_SYNC_ACTION_GROUP_BLOCK_ID { 0x9718D376, 0x77E847EF, 0x8249C13C, 0x31158650 }
	TAG_BLOCK(
		animation_sync_action_group_block,
		"animation_sync_action_group_block",
		k_max_sync_action_groups,
		"s_animation_sync_action_group",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		ANIMATION_SYNC_ACTION_GROUP_BLOCK_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_block, "sync actions", &animation_sync_action_block },
		{ _field_terminator }
	};

	#define ANIMATION_SYNC_ACTION_BLOCK_ID { 0xBDCF8448, 0x72E64BF0, 0xA4F898C8, 0xE77BBEFB }
	TAG_BLOCK(
		animation_sync_action_block,
		"animation_sync_action_block",
		k_max_sync_actions,
		"s_animation_sync_action",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		ANIMATION_SYNC_ACTION_BLOCK_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_block, "same type participants", &animation_sync_action_same_type_participant_block },
		{ _field_block, "other participants", &animation_sync_action_other_type_participant_block },
		{ _field_terminator }
	};

	#define ANIMATION_SYNC_ACTION_SAME_TYPE_PARTICIPANT_ID { 0x9B2539FA, 0x54BF4D31, 0x85ACE0CF, 0x278CFCA8 }
	TAG_BLOCK(
		animation_sync_action_same_type_participant_block,
		"animation_sync_action_same_type_participant",
		k_max_sync_action_participants,
		"s_animation_sync_action_same_type_participant",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		ANIMATION_SYNC_ACTION_SAME_TYPE_PARTICIPANT_ID)
	{
		{ _field_long_flags, "flags", &animation_sync_action_flags_definition },
		{ _field_struct, "animation", &animation_index_struct },
		{ _field_real_point_3d, "start offset", FIELD_FLAG_READ_ONLY },
		{ _field_real_vector_3d, "start facing", FIELD_FLAG_READ_ONLY },
		{ _field_real_point_3d, "end offset", FIELD_FLAG_READ_ONLY },
		{ _field_real, "time_until_hurt", FIELD_FLAG_READ_ONLY },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_real_point_3d, "apex offset", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define ANIMATION_SYNC_ACTION_OTHER_TYPE_PARTICIPANT_ID { 0x273EAFFB, 0xCA1144ED, 0x8801C947, 0x43CC2243 }
	TAG_BLOCK(
		animation_sync_action_other_type_participant_block,
		"animation_sync_action_other_type_participant",
		k_max_sync_action_participants,
		"s_animation_sync_action_other_type_participant",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		ANIMATION_SYNC_ACTION_OTHER_TYPE_PARTICIPANT_ID)
	{
		{ _field_long_flags, "flags", &animation_sync_action_other_type_flags_definition },
		{ _field_tag_reference, "object type", &animation_sync_action_other_type_participant_object_type_reference },
		{ _field_terminator }
	};

	#define FOOT_TRACKING_DEFAULTS_ID { 0x38B72849, 0xFBD74264, 0xBC245286, 0x2F5A03BC }
	TAG_BLOCK(
		foot_tracking_defaults_block,
		"foot_tracking_defaults",
		k_max_tracked_feet,
		"s_foot_tracking_default",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		FOOT_TRACKING_DEFAULTS_ID)
	{
		{ _field_short_block_index, "foot", &foot_tracking_member_block },
		{ _field_enum, "default state", &foot_tracking_default_values },
		{ _field_terminator }
	};

	#define VEHICLE_SUSPENSION_BLOCK_ID { 0x8896A049, 0xE9614E59, 0x9E0BC659, 0xA399CF0C }
	TAG_BLOCK(
		vehicle_suspension_block,
		"vehicle_suspension_block",
		k_max_vehicle_suspensions,
		"c_vehicle_suspension",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_IS_MEMCPYABLE | SET_UNKNOWN15 | 
		SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		VEHICLE_SUSPENSION_BLOCK_ID)
	{
		{ _field_string_id, "label", FIELD_FLAG_INDEX },
		{ _field_struct, "animation", FIELD_FLAG_READ_ONLY, &animation_index_struct },
		{ _field_string_id, "function name" },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_marker),
		{ _field_string_id, "marker name", "this marker should be parented to the vehicle root node" },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_marker),
		{ _field_string_id, "contact marker name", "this marker should be parented to the wheel node" },
		{ _field_real, "mass point offset", "distance along the vehicle's up direction to move the wheel from the marker location" },
		{ _field_real, "full extension ground_depth", FIELD_FLAG_UNKNOWN0 },
		{ _field_real, "full compression ground_depth", FIELD_FLAG_UNKNOWN0 },
		FIELD_EXPLANATION("Destroyed Suspension", nullptr, FIELD_FLAG_NONE, "Only Necessary for suspensions with a destroyed state"),
		{ _field_string_id, "region name" },
		{ _field_real, "destroyed mass point offset" },
		{ _field_real, "destroyed full extension ground_depth", FIELD_FLAG_UNKNOWN0 },
		{ _field_real, "destroyed full compression ground_depth", FIELD_FLAG_UNKNOWN0 },
		{ _field_terminator }
	};

	#define FUNCTION_OVERLAY_ANIMATION_BLOCK_ID { 0xC89466F6, 0x7EF04B56, 0xAF1ACD05, 0xDE675B3E }
	TAG_BLOCK(
		function_overlay_animation_block,
		"function_overlay_animation_block",
		k_max_function_overlays_per_graph,
		"s_function_overlay",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_IS_MEMCPYABLE | SET_UNKNOWN15 | 
		SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		FUNCTION_OVERLAY_ANIMATION_BLOCK_ID)
	{
		{ _field_string_id, "label", FIELD_FLAG_INDEX },
		{ _field_struct, "animation", FIELD_FLAG_READ_ONLY, &animation_index_struct },
		FIELD_PAD("VQWLKE", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_enum, "function controls", &function_overlay_animation_mode },
		{ _field_string_id, "function" },
		FIELD_PAD("OHIOJE", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_terminator }
	};

	#define INHERITED_ANIMATION_BLOCK_ID { 0xBBA74F4E, 0x94B64EE2, 0xA1DCD8E7, 0x53D89B25 }
	TAG_BLOCK(
		inherited_animation_block,
		"inherited_animation_block",
		k_max_animation_inheritence_levels,
		"s_animation_inheritance",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		INHERITED_ANIMATION_BLOCK_ID)
	{
		{ _field_tag_reference, "inherited graph", FIELD_FLAG_READ_ONLY, &model_animation_graph_reference },
		{ _field_block, "node map", FIELD_FLAG_READ_ONLY, &inherited_animation_node_map_block },
		{ _field_block, "node map flags", FIELD_FLAG_READ_ONLY, &inherited_animation_node_map_flag_block },
		{ _field_long_integer, "inheritance_flags", FIELD_FLAG_READ_ONLY },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_real, "uniform translation scale", FIELD_FLAG_READ_ONLY },

		{ _field_terminator }
	};

	#define INHERITED_ANIMATION_NODE_MAP_BLOCK_ID { 0x1268AB4E, 0x215248B5, 0x946D03DB, 0xA15E169F }
	TAG_BLOCK(
		inherited_animation_node_map_block,
		"inherited_animation_node_map_block",
		k_max_nodes_per_animation,
		"short",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		INHERITED_ANIMATION_NODE_MAP_BLOCK_ID)
	{
		{ _field_short_integer, "local node" },
		{ _field_terminator }
	};

	#define INHERITED_ANIMATION_NODE_MAP_FLAG_BLOCK_ID { 0x3ED77110, 0x0F524FC0, 0xA34B0BE3, 0x168D8C7F }
	TAG_BLOCK(
		inherited_animation_node_map_flag_block,
		"inherited_animation_node_map_flag_block",
		k_max_nodes_per_animation,
		"unsigned long",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		INHERITED_ANIMATION_NODE_MAP_FLAG_BLOCK_ID)
	{
		{ _field_long_integer, "local node flags" },
		{ _field_terminator }
	};

	#define WEAPON_CLASS_LOOKUP_BLOCK_ID { 0x829BCBD4, 0x902C4457, 0xB3D2562B, 0x178C3288 }
	TAG_BLOCK(
		weapon_class_lookup_block,
		"weapon_class_lookup_block",
		k_max_weapon_types,
		"s_weapon_class_listing",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		WEAPON_CLASS_LOOKUP_BLOCK_ID)
	{
		{ _field_string_id, "weapon name", FIELD_FLAG_INDEX },
		{ _field_string_id, "weapon class" },
		{ _field_terminator }
	};

	#define ADDITIONAL_NODE_DATA_BLOCK_ID { 0x29A1DD97, 0xBB8948F7, 0xB606A4F9, 0xA4728C90 }
	TAG_BLOCK(
		additional_node_data_block,
		"additional_node_data_block",
		k_max_nodes_per_animation,
		"s_additional_node_data",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		ADDITIONAL_NODE_DATA_BLOCK_ID)
	{
		{ _field_string_id, "node name", FIELD_FLAG_INDEX },
		{ _field_real_quaternion, "default rotation", FIELD_FLAG_READ_ONLY },
		{ _field_real_point_3d, "default translation", FIELD_FLAG_READ_ONLY },
		{ _field_real, "default scale", FIELD_FLAG_READ_ONLY },
		{ _field_real_point_3d, "min bounds" },
		{ _field_real_point_3d, "max bounds" },
		{ _field_terminator }
	};

	#define MODEL_ANIMATION_TAG_RESOURCE_GROUP_ID { 0x47846C50, 0x26C74AF5, 0x8CBDED72, 0x972458F6 }
	TAG_BLOCK(
		model_animation_tag_resource_group_block,
		"model_animation_tag_resource_group",
		k_max_animations_per_graph*3,
		"c_model_animation_tag_refrence_counted_resource",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_RESOURCES | SET_UNKNOWN14,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		MODEL_ANIMATION_TAG_RESOURCE_GROUP_ID)
	{
		{ _field_long_integer, "reference_count", FIELD_FLAG_READ_ONLY },
		{ _field_pageable, "tag_resource", &model_animation_tag_resource_struct },
		{ _field_terminator }
	};

	#define SHARED_STATIC_DATA_CODEC_ROTATION_BLOCK_ID { 0xBE3BF367, 0x8E12471C, 0x8AC19374, 0x920CDCF0 }
	TAG_BLOCK(
		shared_static_data_codec_rotation_block,
		"shared_static_data_codec_rotation_block",
		k_max_animations_per_graph * k_max_nodes_per_animation,
		"c_quantized_quaternion_8byte_revised",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SHARED_STATIC_DATA_CODEC_ROTATION_BLOCK_ID)
	{
		{ _field_short_integer, "i" },
		{ _field_short_integer, "j" },
		{ _field_short_integer, "k" },
		{ _field_short_integer, "w" },
		{ _field_terminator }
	};

	#define SHARED_STATIC_DATA_CODEC_TRANSLATION_BLOCK_ID { 0x85720F55, 0x59DD4D8E, 0x90AC3678, 0x298BB472 }
	TAG_BLOCK(
		shared_static_data_codec_translation_block,
		"shared_static_data_codec_translation_block",
		k_max_animations_per_graph * k_max_nodes_per_animation,
		"real_vector3d",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SHARED_STATIC_DATA_CODEC_TRANSLATION_BLOCK_ID)
	{
		{ _field_real, "x" },
		{ _field_real, "y" },
		{ _field_real, "z" },
		{ _field_terminator }
	};

	#define SHARED_STATIC_DATA_CODEC_SCALE_BLOCK_ID { 0x4269C493, 0x52274440, 0xA14084B5, 0x31AA1D26 }
	TAG_BLOCK(
		shared_static_data_codec_scale_block,
		"shared_static_data_codec_scale_block",
		k_max_animations_per_graph * k_max_nodes_per_animation,
		"real",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SHARED_STATIC_DATA_CODEC_SCALE_BLOCK_ID)
	{
		{ _field_real, "scale" },
		{ _field_terminator }
	};

	#define MODEL_ANIMATION_TAG_RESOURCE_MEMBER_ID { 0xF84A790E, 0xBB494C5C, 0xA5D85B12, 0x9758A12C }
	TAG_BLOCK(
		model_animation_tag_resource_member_block,
		"model_animation_tag_resource_member",
		k_max_animations_per_graph,
		"c_model_animation_tag_resource_member",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_UNKNOWN8 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		MODEL_ANIMATION_TAG_RESOURCE_MEMBER_ID)
	{
		{ _field_long_integer, "animation_index" },
		{ _field_dword_integer, "animation_checksum" },
		{ _field_short_integer, "frame count", FIELD_FLAG_READ_ONLY },
		{ _field_char_integer, "node count", FIELD_FLAG_READ_ONLY },
		{ _field_char_enum, "movement_data_type", FIELD_FLAG_READ_ONLY, &frame_info_type_enum },
		{ _field_struct, "data sizes", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &packed_data_sizes_struct },
		{ _field_data, "animation_data", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define G_NODE_FLAG_STORAGE_ARRAY_ID { 0xFA382E96, 0x31004754, 0xA73B7ADD, 0xC9AA134C }
	TAG_ARRAY(
		g_node_flag_storage_array,
		"g_node_flag_storage_array",
		c_node_flags::k_flag_chunk_count,
		"c_big_flags_chunk_type",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		G_NODE_FLAG_STORAGE_ARRAY_ID)
	{
		{ _field_long_integer, "flag data" },
		{ _field_terminator }
	};

	#define ANIMATION_VELOCITY_BOUNDARIES_ID { 0xD512B001, 0x58E04B93, 0x8363AD46, 0x72E1442C }
	TAG_ARRAY(
		animation_velocity_boundaries_array,
		"animation_velocity_boundaries",
		k_animation_maximum_velocity_boundary_entries,
		"real",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		ANIMATION_VELOCITY_BOUNDARIES_ID)
	{
		{ _field_real, "values", FIELD_FLAG_UNKNOWN0 },
		{ _field_terminator }
	};

	#define FRAME_EVENT_LIST_STRUCT_DEFINITION_ID { 0x65EB9164, 0x6CF74740, 0x9EAEF341, 0x337EB682 }
	TAG_STRUCT(
		frame_event_list_struct_definition,
		"frame_event_list_struct_definition",
		"c_animation_frame_event_list",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		FRAME_EVENT_LIST_STRUCT_DEFINITION_ID)
	{
		FIELD_EXPLANATION("IMPORTANT TAG NOTES", nullptr, FIELD_FLAG_NONE, "1) DO NOT XSYNC THIS TAG DIRECTLY.  Due to the nature of how this tag is processed, it is never\nloaded in-game.  Instead, xsync the parent model_animation_graph tag.  You can do this without\nchecking out the parent model_animation_graph; just find the tag in question in Bonobo, right-click it\nand select \'Force XSync\'.\n\n2) Legacy events are generated by the parent model_animation_graph.  They are generated when the model\nsidecar is imported, and the importer will try to resolve duplicated events with the frame_event_list.\nIf you need to delete a legacy animation event (or audio/effect event or reference for that matter) it \nmust be deleted from both the model_animation_graph tag AND the frame_event_list tag.\n\n3) The internal pipeline process for animation events now is:\n\t- When a sidecar is imported, if animation, effect, or audio events exist, they are copied into the\n\t  frame_event_list tag.  If the event already exists in the frame_event_list, its values are\n\t  retained.  Otherwise, default values are assigned such that the event behaves exactly as \n\t  it used to.  For the event ID, it is assigned the word \'Legacy\' with zero frame offset.\n\t- New frame events should be specified and saved in the frame_event_list tag (you\'re looking\n\t  at it).\n\t- When the model_animation_graph is compiled, the processor opens the associated frame_event_list\n\t  if one exists, reads and processes the data, and stores it back into the original \n\t  model_animation_graph on the xbox (or cache file), so no additional runtime memory or processing \n\t  time should be required.\n"),
		{ _field_block, "sound references", &animation_graph_sound_reference_block },
		{ _field_block, "effect references", &animation_graph_effect_reference_block },
		{ _field_block, "frame events", &import_animation_event_block },
		{ _field_terminator }
	};

	#define ANIMATION_GRAPH_DEFINITIONS_STRUCT_ID { 0x7378A5C8, 0x70D449B0, 0x88828F27, 0x7D26A6A7 }
	TAG_STRUCT(
		animation_graph_definitions_struct,
		"animation_graph_definitions_struct",
		"s_animation_graph_definitions",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | 
		SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		ANIMATION_GRAPH_DEFINITIONS_STRUCT_ID)
	{
		FIELD_EXPLANATION("GRAPH DATA", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_tag_reference, "parent animation graph", &model_animation_graph_reference },
		{ _field_byte_flags, "inheritance flags", &public_animation_graph_flags },
		{ _field_byte_flags, "private flags", FIELD_FLAG_READ_ONLY, &private_animation_graph_flags },
		{ _field_short_integer, "animation codec pack", FIELD_FLAG_READ_ONLY },
		{ _field_enum, "force compression setting", FIELD_FLAG_READ_ONLY, &compression_force_settings },
		{ _field_word_flags, "misc graph flags", &animation_graph_misc_flags },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 3 },
		{ _field_long_integer, "skeleton checksum" },
		{ _field_long_integer, "skeleton checksum lite" },
		{ _field_tag_reference, "imported events", &global_frame_event_list_reference },

		{ _field_block, "node usage", FIELD_FLAG_READ_ONLY, &animation_usage_block },
		{ _field_block, "node masks", &animation_node_mask_block },
		{ _field_block, "functions", &animation_function_block },
		{ _field_block, "model animation variants", &model_animation_variant_block },
		{ _field_block, "skeleton nodes", FIELD_FLAG_READ_ONLY, &animation_graph_node_block },
		{ _field_block, "sound references", "Legacy field - please edit in new frame event tag below", &animation_graph_sound_reference_block },
		{ _field_block, "effect references", "Legacy field - please edit in new frame event tag below", &animation_graph_effect_reference_block },
		{ _field_block, "blend screens", "Legacy field - please edit in NEW blend screens tag below", &animation_blend_screen_block },
		{ _field_block, "foot markers", &foot_tracking_member_block },

		{ _field_legacy, _field_version_equal, _engine_type_haloreach },
		{ _field_tag_reference, "imported events", &global_frame_event_list_reference },

		{ _field_block, "animations", FIELD_FLAG_READ_ONLY, &animation_pool_block, _field_id_wide },
		{ _field_block, "NEW blend screens", &new_animation_blend_screen_block },
		{ _field_block, "NEW function overlays", &new_animation_function_overlay_block },
		{ _field_block, "overlay groups", MAKE_OLD_NAMES("pose overlays|NEW overlays"), &overlay_group_definition_block },
		{ _field_block, "gaits", &animation_gait_block },
		{ _field_block, "gait groups", &animation_gait_group_block },
		{ _field_block, "ik data", &animation_ik_block },
		{ _field_block, "ik sets", &animation_ik_set_block },
		{ _field_block, "ik chains", &animation_ik_chain_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_block, "composites", &g_compositeTag_block },
		{ _field_struct, "pca data", &PCAAnimationDataStruct },

		{ _field_terminator }
	};

	#define ANIMATION_AIMING_SCREEN_STRUCT_ID { 0xA933DD9C, 0x21874089, 0xA3990F17, 0x00DD3043 }
	TAG_STRUCT(
		animation_aiming_screen_struct,
		"animation_aiming_screen_struct",
		"animation_aiming_screen_bounds",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		ANIMATION_AIMING_SCREEN_STRUCT_ID)
	{
		{ _field_angle, "right yaw per frame" },
		{ _field_angle, "left yaw per frame" },
		{ _field_short_integer, "right frame count" },
		{ _field_short_integer, "left frame count" },
		{ _field_angle, "down pitch per frame" },
		{ _field_angle, "up pitch per frame" },
		{ _field_short_integer, "down pitch frame count" },
		{ _field_short_integer, "up pitch frame count" },
		{ _field_terminator }
	};

	#define SHARED_ANIMATION_REFERENCE_BLOCK_ID { 0xC0DEFD48, 0x6BB54221, 0xA917E117, 0x8DF0BDAB }
	TAG_STRUCT(
		shared_animation_reference_block,
		"shared_animation_reference_block",
		"s_shared_model_animation_reference",
		SET_UNKNOWN0 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | 
		SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SHARED_ANIMATION_REFERENCE_BLOCK_ID)
	{
		{ _field_tag_reference, "graph reference", FIELD_FLAG_UNKNOWN0, &model_animation_graph_reference },
		{ _field_short_block_index, "shared animation index", FIELD_FLAG_UNKNOWN0, &shared_model_animation_block },
		FIELD_PAD("sarbp", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	#define QUANTIZED_ORIENTATION_STRUCT_ID { 0x214A3836, 0x146C45DD, 0x91315D22, 0x78CBEE5D }
	TAG_STRUCT(
		quantized_orientation_struct,
		"quantized_orientation_struct",
		"c_quantized_orientation",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		QUANTIZED_ORIENTATION_STRUCT_ID)
	{
		{ _field_short_integer, "rotation x", FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "rotation y", FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "rotation z", FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "rotation w", FIELD_FLAG_READ_ONLY },
		{ _field_real_point_3d, "default translation", FIELD_FLAG_READ_ONLY },
		{ _field_real, "default scale", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define ANIMATION_IK_CHAIN_EVENTS_STRUCT_ID { 0x093101E5, 0x2C2B4D5E, 0xB71AF5DE, 0x699BE416 }
	TAG_STRUCT(
		animation_ik_chain_events_struct,
		"animation_ik_chain_events_struct",
		"s_animation_ik_chain_event",
		SET_UNKNOWN0 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_IS_MEMCPYABLE | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		ANIMATION_IK_CHAIN_EVENTS_STRUCT_ID)
	{
		FIELD_EXPLANATION("REFERENCE IK CHAIN INFO", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_string_id, "chain name" },
		{ _field_enum, "chain type", &animation_ik_chain_type_enumeration },
		{ _field_short_block_index, "chain start node", &animation_graph_node_block },
		{ _field_short_block_index, "chain effector node", &animation_graph_node_block },
		FIELD_EXPLANATION("IMPORTED IK CHAIN INFO", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_enum, "chain usage", &animation_ik_chain_event_usage },
		{ _field_string_id, "proxy marker" },
		{ _field_long_integer, "proxy id" },
		{ _field_char_enum, "event type", &animation_ik_chain_event_type },
		{ _field_byte_integer, "effector transform data index" },
		{ _field_byte_integer, "effector weight data index" },
		{ _field_byte_integer, "pole point data index" },
		FIELD_EXPLANATION("POST PROCESS IK CHAIN INFO", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_byte_integer, "chain index" },
		FIELD_PAD("aikcep", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_terminator }
	};

	#define ANIMATION_IK_CHAIN_PROXIES_STRUCT_ID { 0xCC1A00C4, 0x038D4FBB, 0x8F1F3051, 0xA19647E0 }
	TAG_STRUCT(
		animation_ik_chain_proxies_struct,
		"animation_ik_chain_proxies_struct",
		"s_animation_ik_chain_proxy",
		SET_UNKNOWN0 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | 
		SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		ANIMATION_IK_CHAIN_PROXIES_STRUCT_ID)
	{
		{ _field_long_integer, "id" },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_marker),
		{ _field_string_id, "target marker" },
		{ _field_byte_integer, "proxy transform data index" },
		FIELD_PAD("aikcpp", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_terminator }
	};

	#define ANIMATION_FACIAL_WRINKLE_EVENTS_STRUCT_ID { 0x5D78B2BA, 0x41204C75, 0xAAC24254, 0xA7383DE1 }
	TAG_STRUCT(
		animation_facial_wrinkle_events_struct,
		"animation_facial_wrinkle_events_struct",
		"s_animation_wrinkle_event",
		SET_UNKNOWN0 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | 
		SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		ANIMATION_FACIAL_WRINKLE_EVENTS_STRUCT_ID)
	{
		FIELD_EXPLANATION("REFERENCE FACIAL WRINKLE EVENT INFO", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_string_id, "wrinkle name" },
		{ _field_real, "default value" },
		FIELD_EXPLANATION("IMPORTED FACIAL WRINKLE INFO", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_short_integer, "start frame" },
		{ _field_short_integer, "frame count" },
		{ _field_char_enum, "region", &animation_facial_wrinkle_region },
		FIELD_PAD("PADDNG", nullptr, FIELD_FLAG_NONE, 3),
		FIELD_EXPLANATION("POST PROCESS WRINKLE EVENT INFO", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_short_integer, "wrinkle data index" },
		FIELD_PAD("aikcep", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	#define ANIMATION_EXTENDED_EVENTS_STRUCT_ID { 0x20B7F541, 0x876B4FA9, 0xAD5F76AC, 0x2667B4FA }
	TAG_STRUCT(
		animation_extended_events_struct,
		"animation_extended_events_struct",
		"s_animation_extended_event",
		SET_UNKNOWN0 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | 
		SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		ANIMATION_EXTENDED_EVENTS_STRUCT_ID)
	{
		FIELD_EXPLANATION("IMPORTED EXTENDED DATA EVENT INFO", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_string_id, "name" },
		{ _field_short_integer, "start frame" },
		{ _field_short_integer, "frame count" },
		{ _field_real, "default value" },
		{ _field_short_integer, "data index" },
		FIELD_PAD("pants", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	#define ANIMATION_OBJECT_FUNCTIONS_STRUCT_ID { 0x2C6B2EE2, 0xFC974C48, 0x9127F7F0, 0xEBF8E914 }
	TAG_STRUCT(
		animation_object_functions_struct,
		"animation_object_functions_struct",
		"s_animation_object_function",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		ANIMATION_OBJECT_FUNCTIONS_STRUCT_ID)
	{
		{ _field_string_id, "real_name", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_long_enum, "name", &animation_object_function_name },
		{ _field_short_integer, "start frame" },
		{ _field_short_integer, "frame count" },
		{ _field_struct, "function curve", &scalar_function_named_struct },
		{ _field_terminator }
	};

	#define ANIMATION_INDEX_STRUCT_ID { 0x460AC446, 0x6E044055, 0xB5772485, 0xC9FCAEC3 }
	TAG_STRUCT(
		animation_index_struct,
		"animation_index_struct",
		"c_animation_id",
		SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		ANIMATION_INDEX_STRUCT_ID)
	{
		{ _field_short_integer, "graph index", FIELD_FLAG_UNKNOWN0 },
		{ _field_short_block_index, "animation", &animation_pool_block },
		{ _field_terminator }
	};

	#define PCAANIMATIONDATASTRUCT_ID { 0xBB388541, 0xC4374DDA, 0x9ED407B4, 0x4762E780 }
	TAG_STRUCT(
		PCAAnimationDataStruct,
		"PCAAnimationDataStruct",
		"PCAAnimationData",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		PCAANIMATIONDATASTRUCT_ID)
	{
		FIELD_EXPLANATION("Group Settings", nullptr, FIELD_FLAG_NONE, "For each PCA Group desired, provide a unique name and desired number of blend shapes.\nThen, assign animations to these groups by setting their pca group name field"),
		{ _field_block, "PCA Groups", &PCAGroupSettingsBlock_block },
		FIELD_EXPLANATION("PCA Animation Tag", nullptr, FIELD_FLAG_NONE, "This is where all the imported pca blend shape animation will be stored.\nIf any animations in this graph contain PCA blend shape animation,\ncreate a unique pca_animation tag for this animation graph and link it here.\nOtherwise, one will be created for you."),
		{ _field_tag_reference, "pca animation", &global_pca_animation_tag_reference },
		{ _field_long_integer, "PCA Animation Count", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "PCA Checksum", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define ANIMATION_GRAPH_CONTENTS_STRUCT_ID { 0xBC004E8A, 0x1CC048DD, 0xBF08E736, 0x8D4C66FE }
	TAG_STRUCT(
		animation_graph_contents_struct,
		"animation_graph_contents_struct",
		"c_model_animation_graph_contents",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		ANIMATION_GRAPH_CONTENTS_STRUCT_ID)
	{
		FIELD_EXPLANATION("MODE-n-STATE GRAPH", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_short_block_index, "default gait group", &animation_gait_group_block },
		FIELD_PAD("agcsfap", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_block, "modes", &animation_mode_block },
		FIELD_EXPLANATION("SPECIAL CASE ANIMS", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_block, "vehicle suspension", &vehicle_suspension_block },
		{ _field_block, "function overlays", MAKE_OLD_NAMES("object overlays"), &function_overlay_animation_block },
		{ _field_terminator }
	};

	#define MODEL_ANIMATION_RUNTIME_DATA_STRUCT_ID { 0xB1091BBF, 0xFC474475, 0x85A2D6A5, 0x2FAF2F30 }
	TAG_STRUCT(
		model_animation_runtime_data_struct,
		"model_animation_runtime_data_struct",
		"s_model_animation_runtime_data",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		MODEL_ANIMATION_RUNTIME_DATA_STRUCT_ID)
	{
		FIELD_EXPLANATION("RUN-TIME DATA", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_block, "inheritence list", FIELD_FLAG_READ_ONLY, &inherited_animation_block },
		{ _field_block, "new inheritance list", FIELD_FLAG_READ_ONLY, &inherited_animation_block },
		{ _field_block, "weapon list", &weapon_class_lookup_block },
		{ _field_array, "left arm bit vector", FIELD_FLAG_UNKNOWN0, &g_node_flag_storage_array },
		{ _field_array, "right arm bit vector", FIELD_FLAG_UNKNOWN0, &g_node_flag_storage_array },
		{ _field_data, "animationPlayCounts", FIELD_FLAG_UNKNOWN0 },
		{ _field_terminator }
	};

	#define ANIMATION_CODEC_DATA_STRUCT_ID { 0xA5200D6D, 0x10A34D1E, 0xBDB5A4C5, 0x08252592 }
	TAG_STRUCT(
		animation_codec_data_struct,
		"animation_codec_data_struct",
		"s_animation_codec_data",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		ANIMATION_CODEC_DATA_STRUCT_ID)
	{
		FIELD_EXPLANATION("CODEC-SPECIFIC DATA", nullptr, FIELD_FLAG_NONE, "fields used by varous compression codecs to store shared or global data for this graph. Do not manually edit."),
		{ _field_struct, "shared_static_codec", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &shared_static_data_codec_graph_data_struct },
		{ _field_terminator }
	};

	#define SHARED_STATIC_DATA_CODEC_GRAPH_DATA_STRUCT_ID { 0x76EB40D7, 0x2ADD4D4D, 0xB535E99D, 0x62F2704A }
	TAG_STRUCT(
		shared_static_data_codec_graph_data_struct,
		"shared_static_data_codec_graph_data_struct",
		"s_shared_static_data_codec_graph_data",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SHARED_STATIC_DATA_CODEC_GRAPH_DATA_STRUCT_ID)
	{
		FIELD_EXPLANATION("Shared Static Codec", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_block, "rotations", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &shared_static_data_codec_rotation_block },
		{ _field_block, "translations", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &shared_static_data_codec_translation_block },
		{ _field_block, "scale", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &shared_static_data_codec_scale_block },
		{ _field_terminator }
	};

	#define MODEL_ANIMATION_TAG_RESOURCE_STRUCT_ID { 0x09439BE6, 0x3BDA48B1, 0x9947AD2E, 0xA1280611 }
	TAG_STRUCT(
		model_animation_tag_resource_struct,
		"model_animation_tag_resource_struct",
		"c_model_animation_tag_animation_group_resource",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		MODEL_ANIMATION_TAG_RESOURCE_STRUCT_ID)
	{
		{ _field_block, "group_members", &model_animation_tag_resource_member_block },
		{ _field_terminator }
	};

	#define PACKED_DATA_SIZES_STRUCT_ID { 0x1FBE28A2, 0x840641F2, 0x8852141E, 0x02D54A2E }
	TAG_STRUCT(
		packed_data_sizes_struct,
		"packed_data_sizes_struct",
		"c_animation_data_sizes",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PACKED_DATA_SIZES_STRUCT_ID)
	{
		{ _field_long_integer, "static_node_flags", FIELD_FLAG_UNKNOWN0 },
		{ _field_long_integer, "animated_node_flags", FIELD_FLAG_UNKNOWN0 },
		{ _field_long_integer, "movement_data", FIELD_FLAG_UNKNOWN0 },
		{ _field_long_integer, "pill_offset_data", FIELD_FLAG_UNKNOWN0 },
		{ _field_long_integer, "default_data", FIELD_FLAG_UNKNOWN0 },
		{ _field_long_integer, "uncompressed_data", FIELD_FLAG_UNKNOWN0 },
		{ _field_long_integer, "compressed_data", FIELD_FLAG_UNKNOWN0 },
		{ _field_long_integer, "blend_screen_data", FIELD_FLAG_UNKNOWN0 },
		{ _field_long_integer, "object_space_offset_data", FIELD_FLAG_UNKNOWN0 },
		{ _field_long_integer, "ik_chain_event_data", FIELD_FLAG_UNKNOWN0 },
		{ _field_long_integer, "ik_chain_control_data", FIELD_FLAG_UNKNOWN0 },
		{ _field_long_integer, "ik_chain_proxy_data", FIELD_FLAG_UNKNOWN0 },
		{ _field_long_integer, "ik_chain_pole_vector_data", FIELD_FLAG_UNKNOWN0 },
		{ _field_long_integer, "uncompressed_object_space_data", FIELD_FLAG_UNKNOWN0 },
		{ _field_long_integer, "fik_anchor_data", FIELD_FLAG_UNKNOWN0 },
		{ _field_long_integer, "uncompressed_object_space_node_flags", FIELD_FLAG_UNKNOWN0 },
		{ _field_long_integer, "compressed_event_curve", FIELD_FLAG_UNKNOWN0 },
		{ _field_long_integer, "compressed_static_pose", FIELD_FLAG_UNKNOWN0 },
		{ _field_terminator }
	};

	STRINGS(node_joint_flags)
	{
		"ball-socket",
		"hinge",
		"no movement"
	};
	STRING_LIST(node_joint_flags, node_joint_flags_strings, _countof(node_joint_flags_strings));

	STRINGS(node_info_flags)
	{
		"important for imposter"
	};
	STRING_LIST(node_info_flags, node_info_flags_strings, _countof(node_info_flags_strings));

	STRINGS(animation_node_model_flags)
	{
		"primary model",
		"secondary model",
		"local root",
		"left hand",
		"right hand",
		"left arm member"
	};
	STRING_LIST(animation_node_model_flags, animation_node_model_flags_strings, _countof(animation_node_model_flags_strings));

	STRINGS(key_event_flags_enum)
	{
		"allow on player",
		"left arm only",
		"right arm only",
		"first-person only",
		"third-person only",
		"forward only",
		"reverse only",
		"fp no aged weapons"
	};
	STRING_LIST(key_event_flags_enum, key_event_flags_enum_strings, _countof(key_event_flags_enum_strings));

	STRINGS(key_event_internal_flags_enum)
	{
		"model_index_required"
	};
	STRING_LIST(key_event_internal_flags_enum, key_event_internal_flags_enum_strings, _countof(key_event_internal_flags_enum_strings));

	STRINGS(animation_type_enum)
	{
		"none",
		"base",
		"overlay",
		"replacement"
	};
	STRING_LIST(animation_type_enum, animation_type_enum_strings, _countof(animation_type_enum_strings));

	STRINGS(frame_info_type_enum)
	{
		"none",
		"dx,dy",
		"dx,dy,dyaw",
		"dx,dy,dz,dyaw",
		"dx,dy,dz,dangle-axis",
		"x,y,z - absolute",
		"auto"
	};
	STRING_LIST(frame_info_type_enum, frame_info_type_enum_strings, _countof(frame_info_type_enum_strings));

	STRINGS(internal_animation_flags)
	{
		"<unused0>!",
		"world relative",
		"<unused1>!",
		"<unused3>!",
		"<unused2>!",
		"resource_group",
		"compression disabled",
		"old production checksum",
		"valid production checksum",
		"override force compression",
		"contains pca data"
	};
	STRING_LIST(internal_animation_flags, internal_animation_flags_strings, _countof(internal_animation_flags_strings));

	STRINGS(frame_event_type_new)
	{
		"none",
		"primary keyframe{primary_keyframe}",
		"secondary keyframe{secondary_keyframe}",
		"tertiary keyframe",
		"left foot{left_foot}",
		"right foot{right_foot}",
		"allow interruption{allow_interruption}",
		"do not allow interruption",
		"both-feet shuffle",
		"body impact",
		"left foot lock",
		"left foot unlock",
		"right foot lock",
		"right foot unlock",
		"blend range marker",
		"stride expansion",
		"stride contraction",
		"ragdoll keyframe",
		"drop weapon keyframe",
		"match a",
		"match b",
		"match c",
		"match d",
		"jetpack closed",
		"jetpack open",
		"sound event",
		"effect event"
	};
	STRING_LIST(frame_event_type_new, frame_event_type_new_strings, _countof(frame_event_type_new_strings));

	STRINGS(compression_settings)
	{
		"best score&medium compression",
		"best compression&rough compression",
		"best accuracy&uncompressed",
		"old codec",
		"reach medium compression",
		"reach rough compression"
	};
	STRING_LIST(compression_settings, compression_settings_strings, _countof(compression_settings_strings));

	STRINGS(compression_force_settings)
	{
		"none",
		"medium compression",
		"rough compression",
		"uncompressed",
		"old codec",
		"reach medium compression",
		"reach rough compression"
	};
	STRING_LIST(compression_force_settings, compression_force_settings_strings, _countof(compression_force_settings_strings));

	STRINGS(animation_dialogue_event_enum)
	{
		"bump",
		"dive",
		"evade",
		"lift",
		"sigh",
		"contempt",
		"anger",
		"fear",
		"relief",
		"sprint",
		"sprint_end",
		"ass_grabber",
		"kill_ass",
		"ass_grabbed",
		"die_ass"
	};
	STRING_LIST(animation_dialogue_event_enum, animation_dialogue_event_enum_strings, _countof(animation_dialogue_event_enum_strings));

	STRINGS(animation_index_flags)
	{
		"disable interpolation in{disable interpolation_in}",
		"disable interpolation out{disable interpolation_out}",
		"disable mode ik",
		"disable weapon ik",
		"disable weapon aim/1st person",
		"disable look screen",
		"disable transition adjustment",
		"force weapon ik on",
		"use custom blend-in time#when possible, interpolate into this animation using the \'blend in\' time value below",
		"enable animated source interpolation",
		"disable ik sets",
		"disable ik chains",
		"translate and scale root only#ignore all transtion and scale on all nodes except the root",
		"enable blend-out on replacement anims#fade out this animation as they reach the end of the animation.",
		"use custom blend-out time#when possible, fade this animation out over the \'blend out\' time below (requires \'enable blend-out\' above, replacement anims only)",
		"override player input with motion#use the movement data in this anim instead of player physics (player only)"
	};
	STRING_LIST(animation_index_flags, animation_index_flags_strings, _countof(animation_index_flags_strings));

	STRINGS(production_status_flags)
	{
		"do not monitor changes",
		"verify sound events",
		"do not inherit for player graphs",
		"has errors or warnings",
		"keep raw data in tag",
		"allow ball-roll on foot#prevents foot-ik from settling"
	};
	STRING_LIST(production_status_flags, production_status_flags_strings, _countof(production_status_flags_strings));

	STRINGS(object_space_node_flags)
	{
		"rotation",
		"translation",
		"scale",
		"motion root"
	};
	STRING_LIST(object_space_node_flags, object_space_node_flags_strings, _countof(object_space_node_flags_strings));

	STRINGS(foot_tracking_default_values)
	{
		"off",
		"on"
	};
	STRING_LIST(foot_tracking_default_values, foot_tracking_default_values_strings, _countof(foot_tracking_default_values_strings));

	STRINGS(animation_ik_chain_type_enumeration)
	{
		"standard"
	};
	STRING_LIST(animation_ik_chain_type_enumeration, animation_ik_chain_type_enumeration_strings, _countof(animation_ik_chain_type_enumeration_strings));

	STRINGS(animation_ik_chain_event_usage)
	{
		"none",
		"world",
		"self",
		"parent",
		"primary weapon",
		"secondary weapon",
		"assassination"
	};
	STRING_LIST(animation_ik_chain_event_usage, animation_ik_chain_event_usage_strings, _countof(animation_ik_chain_event_usage_strings));

	STRINGS(animation_ik_chain_event_type)
	{
		"active",
		"passive"
	};
	STRING_LIST(animation_ik_chain_event_type, animation_ik_chain_event_type_strings, _countof(animation_ik_chain_event_type_strings));

	STRINGS(animation_facial_wrinkle_region)
	{
		"Upper Brow",
		"Center Brow",
		"Left Squint",
		"Right Squint",
		"Left Smile",
		"Right Smile",
		"Left Sneer",
		"Right Sneer"
	};
	STRING_LIST(animation_facial_wrinkle_region, animation_facial_wrinkle_region_strings, _countof(animation_facial_wrinkle_region_strings));

	STRINGS(animation_object_function_name)
	{
		"animation_object_function_a",
		"animation_object_function_b",
		"animation_object_function_c",
		"animation_object_function_d"
	};
	STRING_LIST(animation_object_function_name, animation_object_function_name_strings, _countof(animation_object_function_name_strings));

	STRINGS(ranged_action_variable_sources)
	{
		"none",
		"offset x",
		"offset y",
		"offset z",
		"offset horizontal",
		"negative offset x",
		"negative offset y"
	};
	STRING_LIST(ranged_action_variable_sources, ranged_action_variable_sources_strings, _countof(ranged_action_variable_sources_strings));

	STRINGS(blend_screen_definition_flags)
	{
		"active only when weapon down",
		"attempt piece-wise blending",
		"allow parent adjustment"
	};
	STRING_LIST(blend_screen_definition_flags, blend_screen_definition_flags_strings, _countof(blend_screen_definition_flags_strings));

	STRINGS(function_overlay_definition_flags)
	{
		"strict looping#loop without blending the first and last frames"
	};
	STRING_LIST(function_overlay_definition_flags, function_overlay_definition_flags_strings, _countof(function_overlay_definition_flags_strings));

	STRINGS(blend_screen_variable_sources)
	{
		"none",
		"object function",
		"horizontal test",
		"vertical test",
		"aim yaw",
		"aim pitch",
		"look yaw",
		"look pitch",
		"object yaw",
		"object pitch",
		"acceleration yaw",
		"acceleration pitch",
		"steering",
		"velocity yaw",
		"velocity pitch",
		"damage gut yaw",
		"damage gut pitch",
		"damage chest yaw",
		"damage chest pitch",
		"damage head yaw",
		"damage head pitch",
		"damage left shoulder yaw",
		"damage left shoulder pitch",
		"damage left arm yaw",
		"damage left arm pitch",
		"damage left leg yaw",
		"damage left leg pitch",
		"damage left foot yaw",
		"damage left foot pitch",
		"damage right shoulder yaw",
		"damage right shoulder pitch",
		"damage right arm yaw",
		"damage right arm pitch",
		"damage right leg yaw",
		"damage right leg pitch",
		"damage right foot yaw",
		"damage right foot pitch",
		"defense yaw",
		"defense pitch",
		"first person pitch",
		"first person turn",
		"throttle side",
		"throttle_forward"
	};
	STRING_LIST(blend_screen_variable_sources, blend_screen_variable_sources_strings, _countof(blend_screen_variable_sources_strings));

	STRINGS(blend_screen_weight_sources)
	{
		"none",
		"object function",
		"acceleration magnitude",
		"velocity magnitude",
		"state function a",
		"state function b",
		"state function c",
		"state function d",
		"damage chest{damage focus chest}",
		"damage gut{damage focus gut}",
		"damage head{damage focus head}",
		"damage left shoulder{damage focus left shoulder}",
		"damage left arm{damage focus left arm}",
		"damage left leg{damage focus left leg}",
		"damage left foot{damage focus left foot}",
		"damage right shoulder{damage focus right shoulder}",
		"damage right arm{damage focus right arm}",
		"damage right leg{damage focus right leg}",
		"damage right foot{damage focus right foot}",
		"defense"
	};
	STRING_LIST(blend_screen_weight_sources, blend_screen_weight_sources_strings, _countof(blend_screen_weight_sources_strings));

	STRINGS(pose_overlay_item_definition_block_flags)
	{
		"disable"
	};
	STRING_LIST(pose_overlay_item_definition_block_flags, pose_overlay_item_definition_block_flags_strings, _countof(pose_overlay_item_definition_block_flags_strings));

	STRINGS(animation_gait_directions)
	{
		"move_front",
		"move_back",
		"move_left",
		"move_right",
		"turn_left",
		"turn_right"
	};
	STRING_LIST(animation_gait_directions, animation_gait_directions_strings, _countof(animation_gait_directions_strings));

	STRINGS(animation_ik_target_enum_definition)
	{
		"parent",
		"NYI any child",
		"primary weapon",
		"secondary weapon"
	};
	STRING_LIST(animation_ik_target_enum_definition, animation_ik_target_enum_definition_strings, _countof(animation_ik_target_enum_definition_strings));

	STRINGS(animation_ik_set_item_flags)
	{
		"disable"
	};
	STRING_LIST(animation_ik_set_item_flags, animation_ik_set_item_flags_strings, _countof(animation_ik_set_item_flags_strings));

	STRINGS(animation_sync_action_flags_definition)
	{
		"Initiator",
		"Critical Participant",
		"Disabled",
		"Airborne"
	};
	STRING_LIST(animation_sync_action_flags_definition, animation_sync_action_flags_definition_strings, _countof(animation_sync_action_flags_definition_strings));

	STRINGS(animation_sync_action_other_type_flags_definition)
	{
		"Supports any type",
		"Disabled"
	};
	STRING_LIST(animation_sync_action_other_type_flags_definition, animation_sync_action_other_type_flags_definition_strings, _countof(animation_sync_action_other_type_flags_definition_strings));

	STRINGS(animation_mode_flags)
	{
		"this is a stance"
	};
	STRING_LIST(animation_mode_flags, animation_mode_flags_strings, _countof(animation_mode_flags_strings));

	STRINGS(function_overlay_animation_mode)
	{
		"frame",
		"scale"
	};
	STRING_LIST(function_overlay_animation_mode, function_overlay_animation_mode_strings, _countof(function_overlay_animation_mode_strings));

	STRINGS(animation_usage_enumeration)
	{
		"physics control",
		"camera control",
		"origin marker",
		"left clavicle",
		"left upperarm",
		"pose blend pitch",
		"pose blend yaw",
		"pedestal",
		"pelvis",
		"left foot",
		"right foot",
		"damage root gut",
		"damage root chest",
		"damage root head",
		"damage root left shoulder",
		"damage root left arm",
		"damage root left leg",
		"damage root left foot",
		"damage root right shoulder",
		"damage root right arm",
		"damage root right leg",
		"damage root right foot",
		"left hand",
		"right hand",
		"weapon ik"
	};
	STRING_LIST(animation_usage_enumeration, animation_usage_enumeration_strings, _countof(animation_usage_enumeration_strings));

	STRINGS(model_animation_variant_flags)
	{
		"needs mandible replacement"
	};
	STRING_LIST(model_animation_variant_flags, model_animation_variant_flags_strings, _countof(model_animation_variant_flags_strings));

	STRINGS(private_animation_graph_flags)
	{
		"prepared for cache",
		"use a single mixing board{unused smelly flag}",
		"imported with codec compressors",
		"uses data driven animation",
		"written to cache",
		"animation data reordered",
		"ready for use"
	};
	STRING_LIST(private_animation_graph_flags, private_animation_graph_flags_strings, _countof(private_animation_graph_flags_strings));

	STRINGS(public_animation_graph_flags)
	{
		"inherit root trans scale only",
		"inherit for use on player"
	};
	STRING_LIST(public_animation_graph_flags, public_animation_graph_flags_strings, _countof(public_animation_graph_flags_strings));

	STRINGS(animation_graph_misc_flags)
	{
		"ignore gaits"
	};
	STRING_LIST(animation_graph_misc_flags, animation_graph_misc_flags_strings, _countof(animation_graph_misc_flags_strings));

	TAG_REFERENCE(global_animation_graph_reference, MODEL_ANIMATION_GRAPH_TAG);

	TAG_REFERENCE(global_frame_event_list_reference, FRAME_EVENT_LIST_TAG);

} // namespace macaque

} // namespace blofeld

