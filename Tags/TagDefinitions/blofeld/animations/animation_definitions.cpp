#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(frame_event_list, FRAME_EVENT_LIST_TAG, frame_event_list_block_block );

	TAG_GROUP(model_animation_graph, MODEL_ANIMATION_GRAPH_TAG)
	{
		{ _field_struct, "definitions", &animation_graph_definitions_struct_struct_definition },
		{ _field_struct, "content", &animation_graph_contents_struct_struct_definition },
		{ _field_struct, "run time data", &model_animation_runtime_data_struct_struct_definition },
		{ _field_block, "additional node data", &additional_node_data_block_block },
		{ _field_block, "tag resource groups", &model_animation_tag_resource_group_block },

		{ _field_version_greater, _engine_type_haloreach, 1 },
		{ _field_struct, "codec data*!", &animation_codec_data_struct_struct_definition },

		{ _field_terminator }
	};

	TAG_BLOCK(animation_graph_sound_reference_block, k_max_sound_references_per_graph)
	{
		{ _field_tag_reference, "sound^", &global_sound_reference },
		{ _field_word_flags, "flags", &key_event_flags_enum },
		{ _field_word_flags, "internal_flags!", &key_event_internal_flags_enum },

		{ _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_tag_reference, "model#optional. only allow this event when used on this model", &model_reference$3 },
		{ _field_string_id, "variant#optional. only allow this event when used on this model variant" },

		{ _field_terminator }
	};

	TAG_BLOCK(animation_graph_effect_reference_block, k_max_effect_references_per_graph)
	{
		{ _field_tag_reference, "effect^", &global_effect_reference },
		{ _field_word_flags, "flags", &key_event_flags_enum },
		{ _field_word_flags, "internal_flags!", &key_event_internal_flags_enum },

		{ _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_tag_reference, "model#optional. only allow this event when used on this model", &model_reference$3 },
		{ _field_string_id, "variant#optional. only allow this event when used on this model variant" },

		{ _field_terminator }
	};

	TAG_BLOCK(import_frame_event_block, k_max_frame_events)
	{
		{ _field_string_id, "event name*" },
		{ _field_string_id, "animation name!*" },
		{ _field_short_integer, "frame" },
		{ _field_short_integer, "frame offset" },
		{ _field_enum, "type*", &frame_event_type_new },
		{ _field_pad, "pad", 2 },
		{ _field_long_integer, "unique ID*!#(Do not change this)" },
		{ _field_terminator }
	};

	TAG_BLOCK(animation_sound_event_block_extended, k_max_frame_events)
	{
		{ _field_short_block_index, "frame event" },
		{ _field_pad, "pad", 2 },
		{ _field_short_block_index, "sound" },
		{ _field_short_integer, "frame offset#If a frame event is set, this number is relative to frame event, otherwise it\'s absolute." },
		{ _field_custom },
		{ _field_string_id, "marker name" },
		{ _field_terminator }
	};

	TAG_BLOCK(animation_effects_event_block_extended, k_max_frame_events)
	{
		{ _field_short_block_index, "frame event" },
		{ _field_pad, "pad", 2 },
		{ _field_short_block_index, "effect" },
		{ _field_short_integer, "frame offset#If a frame event is set, this number is relative to frame event, otherwise it\'s absolute." },
		{ _field_custom },
		{ _field_string_id, "marker name" },
		{ _field_char_enum, "damage effect reporting type", &global_damage_reporting_enum_definition },
		{ _field_pad, "pad_2", 3 },
		{ _field_terminator }
	};

	TAG_BLOCK(animation_dialogue_event_block_extended, k_max_frame_events)
	{
		{ _field_short_block_index, "frame event" },
		{ _field_enum, "dialogue event", &animation_dialogue_event_enum },
		{ _field_short_integer, "frame offset#If a frame event is set, this number is relative to frame event, otherwise it\'s absolute." },
		{ _field_pad, "pad", 2 },
		{ _field_terminator }
	};

	TAG_BLOCK(animation_script_event_block_extended, k_max_frame_events)
	{
		{ _field_short_block_index, "frame event" },
		{ _field_short_integer, "frame offset#If a frame event is set, this number is relative to frame event, otherwise it\'s absolute." },
		{ _field_string_id, "script name" },
		{ _field_terminator }
	};

	TAG_BLOCK(import_animation_event_block, 2*k_max_animations_per_graph)
	{
		{ _field_string_id, "animation name^*!" },
		{ _field_long_integer, "animation frame count^*!" },
		{ _field_block, "animation events", &import_frame_event_block_block },
		{ _field_block, "sound events", &animation_sound_event_block_extended_block },
		{ _field_block, "effect events", &animation_effects_event_block_extended_block },
		{ _field_block, "dialogue events", &animation_dialogue_event_block_extended_block },
		{ _field_block, "script events", &animation_script_event_block_extended_block },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(frame_event_list_block, 1, frame_event_list_struct_definition_struct_definition );

	TAG_BLOCK(animation_usage_block, k_animation_node_usage_count)
	{
		{ _field_enum, "usage^", &animation_usage_enumeration },
		{ _field_short_block_index, "node to use" },
		{ _field_terminator }
	};

	TAG_BLOCK(animation_node_mask_entry_block, k_max_nodes_per_animation)
	{
		{ _field_short_block_index, "node^" },
		{ _field_pad, "anbfp", 2 },
		{ _field_terminator }
	};

	TAG_BLOCK(animation_node_mask_block, k_animation_maximum_node_mask_count)
	{
		{ _field_string_id, "name^" },
		{ _field_block, "nodes", &animation_node_mask_entry_block_block },
		{ _field_array, "node flags!", &g_node_flag_storage_array_array },
		{ _field_terminator }
	};

	TAG_BLOCK(animation_function_block, k_animation_maximum_function_count)
	{
		{ _field_string_id, "name^" },
		{ _field_struct, "function", &scalar_function_named_struct_struct_definition },
		{ _field_terminator }
	};

	TAG_BLOCK(mode_or_stance_alias_block, k_animation_maximum_mode_or_stance_aliases)
	{
		{ _field_string_id, "mode or stance" },
		{ _field_string_id, "alias" },
		{ _field_terminator }
	};

	TAG_BLOCK(model_animation_variant_block, k_animation_maximum_model_variants)
	{
		{ _field_string_id, "variant name^" },
		{ _field_long_flags, "variant flags", &model_animation_variant_flags },
		{ _field_block, "mode or stance aliases", &mode_or_stance_alias_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(animation_graph_node_block, k_max_nodes_per_animation)
	{
		{ _field_string_id, "name^" },
		{ _field_short_block_index, "next sibling node index*" },
		{ _field_short_block_index, "first child node index*" },
		{ _field_short_block_index, "parent node index*" },
		{ _field_byte_flags, "model flags*", &animation_node_model_flags },
		{ _field_byte_flags, "node joint flags", &node_joint_flags },
		{ _field_byte_flags, "additional flags", &node_info_flags },
		{ _field_pad, "NOD", 3 },
		{ _field_real_vector_3d, "base vector*" },
		{ _field_real, "vector range*" },
		{ _field_real, "z_pos*" },
		{ _field_long_integer, "frame_ID1*" },
		{ _field_long_integer, "frame_ID2*" },
		{ _field_terminator }
	};

	TAG_BLOCK(animation_blend_screen_block, k_animation_maximum_blend_screens)
	{
		{ _field_string_id, "label^" },
		{ _field_struct, "aiming screen*", &animation_aiming_screen_struct_struct_definition },
		{ _field_terminator }
	};

	TAG_BLOCK(foot_tracking_member_block, k_max_tracked_feet)
	{
		{ _field_custom },
		{ _field_string_id, "foot marker name^" },
		{ _field_real_bounds, "foot ik range" },
		{ _field_custom },
		{ _field_string_id, "ankle marker name" },
		{ _field_real_bounds, "ankle ik range" },
		{ _field_enum, "default state", &foot_tracking_default_values },
		{ _field_pad, "f00t1", 2 },
		{ _field_terminator }
	};

	TAG_BLOCK(animation_frame_event_block, k_max_frame_events)
	{
		{ _field_enum, "type", &frame_event_type_new },
		{ _field_short_integer, "frame" },
		{ _field_terminator }
	};

	TAG_BLOCK(animation_sound_event_block, k_max_frame_events)
	{
		{ _field_short_block_index, "sound" },
		{ _field_short_integer, "frame" },
		{ _field_custom },
		{ _field_string_id, "marker name" },
		{ _field_terminator }
	};

	TAG_BLOCK(animation_effect_event_block, k_max_frame_events)
	{
		{ _field_short_block_index, "effect" },
		{ _field_short_integer, "frame" },
		{ _field_custom },
		{ _field_string_id, "marker name" },
		{ _field_char_enum, "damage effect reporting type", &global_damage_reporting_enum_definition },
		{ _field_pad, "eefpd1", 3 },
		{ _field_terminator }
	};

	TAG_BLOCK(animation_dialogue_event_block, k_max_frame_events)
	{
		{ _field_enum, "dialogue event", &animation_dialogue_event_enum },
		{ _field_short_integer, "frame" },
		{ _field_terminator }
	};

	TAG_BLOCK(animation_script_event_block, k_max_frame_events)
	{
		{ _field_string_id, "script name" },
		{ _field_short_integer, "frame" },
		{ _field_pad, "pad", 2 },
		{ _field_terminator }
	};

	TAG_BLOCK(object_space_node_data_block, k_max_nodes_per_animation)
	{
		{ _field_short_block_index, "node index{node_index}^" },
		{ _field_word_flags, "flags*", &object_space_node_flags },
		{ _field_struct, "parent orientation{orientation}*", &quantized_orientation_struct_struct_definition },
		{ _field_terminator }
	};

	TAG_BLOCK(foot_lock_cycle_block, k_max_cycles_per_tracked_foot)
	{
		{ _field_short_integer, "start locking" },
		{ _field_short_integer, "locked" },
		{ _field_short_integer, "start unlocking" },
		{ _field_short_integer, "unlocked" },
		{ _field_real_point_3d, "lock point*" },
		{ _field_terminator }
	};

	TAG_BLOCK(foot_tracking_block, k_max_tracked_feet)
	{
		{ _field_short_block_index, "foot" },
		{ _field_pad, "f00t2", 2 },
		{ _field_block, "cycles|ABCDCC", &foot_lock_cycle_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(object_space_offset_node_block, k_max_object_space_offset_node_count)
	{
		{ _field_short_block_index, "object space offset node^" },
		{ _field_pad, "wsonbp", 2 },
		{ _field_terminator }
	};

	TAG_BLOCK(fik_anchor_node_block, k_max_fik_anchor_node_count)
	{
		{ _field_short_block_index, "anchor node^" },
		{ _field_pad, "dse", 2 },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(animation_ik_chain_events, k_animation_maximum_ik_chain_events, animation_ik_chain_events_struct_struct_definition );

	TAG_BLOCK_FROM_STRUCT(animation_ik_chain_proxies, k_animation_maximum_ik_chain_proxies, animation_ik_chain_proxies_struct_struct_definition );

	TAG_BLOCK_FROM_STRUCT(animation_facial_wrinkle_events, k_animation_maximum_facial_wrinkle_events, animation_facial_wrinkle_events_struct_struct_definition );

	TAG_BLOCK_FROM_STRUCT(animation_extended_events, k_animation_maximum_extended_events, animation_extended_events_struct_struct_definition );

	TAG_BLOCK_FROM_STRUCT(animation_object_functions, k_animation_maximum_object_functions, animation_object_functions_struct_struct_definition );

	TAG_BLOCK(shared_model_animation_block, 1)
	{
		{ _field_version_greater, _engine_type_haloreach, 1 },
		{ _field_short_integer, "frame count*" },

		{ _field_byte_integer, "node count*" },

		{ _field_version_less_or_equal, _engine_type_haloreach, 2 },
		{ _field_pad, "pad", 1 },
		{ _field_short_integer, "frame count*" },

		{ _field_char_enum, "animation type*", &animation_type_enum },
		{ _field_char_enum, "frame info type*", &frame_info_type_enum },

		{ _field_version_greater, _engine_type_haloreach, 1 },
		{ _field_char_enum, "desired frame info type*", &frame_info_type_enum },

		{ _field_char_enum, "desired compression", &compression_settings },
		{ _field_char_enum, "current compression*", &compression_settings },

		{ _field_version_less_or_equal, _engine_type_haloreach, 1 },
		{ _field_word_flags, "production flags", &production_status_flags },

		{ _field_word_flags, "internal flags*", &internal_animation_flags },

		{ _field_version_greater, _engine_type_haloreach, 1 },
		{ _field_short_integer, "compressor_version*" },

		{ _field_long_integer, "uid*" },
		{ _field_string_id, "shared id*" },
		{ _field_long_integer, "node list checksum*" },

		{ _field_version_less_or_equal, _engine_type_haloreach, 3 },
		{ _field_long_integer, "production checksum" }, // unknown
		{ _field_short_integer, "unknown" },
		{ _field_short_integer, "unknown" },

		{ _field_short_integer, "resource_group*" },
		{ _field_short_integer, "resource_group_member*" },
		{ _field_real_vector_3d, "heading*!" },

		{ _field_version_greater, _engine_type_haloreach, 1 },
		{ _field_real, "heading angle*!" },

		{ _field_real, "average translation magnitude*!" },
		{ _field_real, "average pivot yaw*!" },
		{ _field_explanation, "a!", "IMPORTANT NOTES ABOUT FRAME EVENTS\n1) The following four fields (hidden except in expert mode) are legacy Halo3-style tag blocks.\n2) New frame events (attached to animations in Maya) will automagically be exported to\n   the frame_event_list any time a model sidecar is imported with the tool import command.\n3) Do not add new frame events, fx events, audio events, or dialog events here.  Instead,\n   please use the frame_event_list tag referenced in \'imported events\' (it\'s right above the\n   \'animations\' tag block).\n4) The only time you should be editing the following hidden fields is to remove legacy\n   frame events that have been replaced by events generated in Maya.\n" },
		{ _field_block, "frame events|ABCDCC!*#Legacy field - please edit in new frame event tag below", &animation_frame_event_block_block },
		{ _field_block, "sound events|ABCDCC!*#Legacy field - please edit in new frame event tag below", &animation_sound_event_block_block },
		{ _field_block, "effect events|ABCDCC!*#Legacy field - please edit in new frame event tag below", &animation_effect_event_block_block },
		{ _field_block, "dialogue events|ABCDCC!*#Legacy field - please edit in new frame event tag below", &animation_dialogue_event_block_block },

		{ _field_version_greater, _engine_type_haloreach, 1 },
		{ _field_block, "script events|ABCDCC!*#Legacy field - please edit in new frame event tag below", &animation_script_event_block_block },

		{ _field_explanation, "b!", "" },
		{ _field_block, "object-space parent nodes|ABCDCC", &object_space_node_data_block_block },
		{ _field_block, "foot tracking|ABCDCC", &foot_tracking_block_block },
		{ _field_block, "object space offset nodes|ABCDCC", &object_space_offset_node_block_block },
		{ _field_block, "forward-invert kinetic anchor nodes|ABCDCC", &fik_anchor_node_block_block },
		{ _field_block, "ik chain events*!", &animation_ik_chain_events_block },
		{ _field_block, "ik chain proxies*!", &animation_ik_chain_proxies_block },
		{ _field_block, "facial wrinkle events*!", &animation_facial_wrinkle_events_block },
		{ _field_block, "extended data events*!", &animation_extended_events_block },
		{ _field_block, "animation object functions", &animation_object_functions_block },
		{ _field_terminator }
	};

	TAG_BLOCK(animation_pool_block, k_max_animations_per_graph)
	{
		{ _field_string_id, "name*^" },
		{ _field_custom },
		{ _field_real, "weight" },
		{ _field_short_integer, "loop frame index" },
		{ _field_word_flags, "user flags{playback flags}", &animation_index_flags },
		{ _field_real, "override blend in time{override blend time}" },
		{ _field_real, "override blend out time" },
		{ _field_short_block_index, "parent animation*!" },
		{ _field_short_block_index, "next animation*!" },
		{ _field_word_flags, "production flags", &production_status_flags },
		{ _field_short_block_index, "composite*" },

		{ _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_explanation, "PCA Group Link", "If this animation contains PCA blend shape animation,\nprovide the name of the PCA Group to which it belongs.\nThese groups should be present in the PCA Groups block." },
		{ _field_string_id, "pca group name" },

		{ _field_explanation, "Shared Animation Data", "data which may be shared by one or more animations" },
		{ _field_struct, "shared animation reference!", &shared_animation_reference_block_struct_definition },
		{ _field_block, "shared animation data", &shared_model_animation_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(new_animation_blend_screen_block, k_animation_maximum_blend_screens)
	{
		{ _field_string_id, "name^" },
		{ _field_long_flags, "flags", &blend_screen_definition_flags },
		{ _field_real, "weight" },
		{ _field_real_fraction, "interpolation rate:[0,1]#A value of zero or one means no interpolation." },
		{ _field_pad, "nabsbfp0", 2 },
		{ _field_enum, "yaw source", &blend_screen_variable_sources },
		{ _field_enum, "pitch source", &blend_screen_variable_sources },
		{ _field_enum, "weight source", &blend_screen_weight_sources },
		{ _field_custom },
		{ _field_string_id, "yaw source object function" },
		{ _field_custom },
		{ _field_string_id, "pitch source object function" },
		{ _field_custom },
		{ _field_string_id, "weight source object function" },
		{ _field_short_block_index, "weight function#Function applied to input from weight function source" },
		{ _field_pad, "nabsbfp1", 2 },
		{ _field_struct, "animation{animation info}", &animation_index_struct_struct_definition },
		{ _field_terminator }
	};

	TAG_BLOCK(new_animation_function_overlay_block, k_animation_maximum_function_overlays)
	{
		{ _field_string_id, "name^" },
		{ _field_long_flags, "flags", &function_overlay_definition_flags },
		{ _field_explanation, "Frame Ratio or Playback Speed", "Enter either or leave blank.  Entering both will default to frame ratio option for playback control." },
		{ _field_custom },
		{ _field_string_id, "frame ratio object function" },
		{ _field_custom },
		{ _field_string_id, "playback speed object function" },
		{ _field_custom },
		{ _field_string_id, "blend weight object function" },
		{ _field_struct, "animation", &animation_index_struct_struct_definition },
		{ _field_terminator }
	};

	TAG_BLOCK(blend_screen_item_definition_block, k_animation_maximum_mixing_board_pose_overlays)
	{
		{ _field_short_block_index, "blend screen^" },
		{ _field_word_flags, "flags", &pose_overlay_item_definition_block_flags },
		{ _field_short_block_index, "node mask" },
		{ _field_pad, "bsidbfp", 2 },
		{ _field_terminator }
	};

	TAG_BLOCK(function_overlay_item_definition_block, k_animation_maximum_function_overlays)
	{
		{ _field_short_block_index, "function overlay^" },
		{ _field_word_flags, "flags", &pose_overlay_item_definition_block_flags },
		{ _field_terminator }
	};

	TAG_BLOCK(overlay_group_definition_block, k_animation_maximum_overlay_groups)
	{
		{ _field_string_id, "name^" },
		{ _field_block, "blend screens{blend screen}|CCBBAA", &blend_screen_item_definition_block_block },
		{ _field_block, "function overlays|CCBBAA", &function_overlay_item_definition_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(animation_gait_block, k_animation_maximum_gaits)
	{
		{ _field_string_id, "name^" },
		{ _field_string_id, "slow gait name" },
		{ _field_string_id, "intermediate gait name#animation name used for the speed variations" },
		{ _field_string_id, "fast gait name" },
		{ _field_enum, "move state", &animation_gait_directions },
		{ _field_pad, "pad", 2 },
		{ _field_terminator }
	};

	TAG_BLOCK(animation_gait_item_block, k_animation_maximum_gaits)
	{
		{ _field_short_block_index, "animation gait^" },
		{ _field_pad, "agibfap", 2 },
		{ _field_terminator }
	};

	TAG_BLOCK(animation_gait_group_block, k_animation_maximum_gait_groups)
	{
		{ _field_string_id, "name^" },
		{ _field_block, "animation gaits", &animation_gait_item_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(animation_ik_block, k_max_ik_points)
	{
		{ _field_string_id, "name^" },
		{ _field_string_id, "source marker#the marker name on this object where the point of attachment is" },
		{ _field_long_enum, "attach to", &animation_ik_target_enum_definition },
		{ _field_string_id, "destination marker#the marker name of the attachment destination point" },
		{ _field_real_point_3d, "pole marker" },
		{ _field_terminator }
	};

	TAG_BLOCK(animation_ik_set_item, k_max_ik_points_per_set)
	{
		{ _field_short_block_index, "ik point^" },
		{ _field_word_flags, "flags", &animation_ik_set_item_flags },
		{ _field_terminator }
	};

	TAG_BLOCK(animation_ik_set, k_max_ik_sets)
	{
		{ _field_string_id, "name^" },
		{ _field_block, "ik points|CCBBAA", &animation_ik_set_item_block },
		{ _field_terminator }
	};

	TAG_BLOCK(animation_ik_chain_block, k_animation_maximum_ik_chains)
	{
		{ _field_string_id, "name^" },
		{ _field_enum, "type", &animation_ik_chain_type_enumeration },
		{ _field_pad, "aikcbp", 2 },
		{ _field_short_block_index, "start node{grandparent node}" },
		{ _field_short_block_index, "effector node" },
		{ _field_short_integer, "rank!#calculated during post process where rank is default ordinal for solving" },
		{ _field_short_integer, "antecedents!#calculated during post process where bit index represents chain index" },
		{ _field_terminator }
	};

	TAG_BLOCK(PCAGroupSettingsBlock, k_max_animations_per_graph)
	{
		{ _field_string_id, "Group Name^" },
		{ _field_long_integer, "Desired Mesh Count" },
		{ _field_terminator }
	};

	TAG_BLOCK(animation_entry_block, k_max_animations_per_block)
	{
		{ _field_string_id, "label^" },
		{ _field_short_block_index, "overlay group{pose overlay|overlay}" },
		{ _field_short_block_index, "ik set" },
		{ _field_struct, "animation", &animation_index_struct_struct_definition },
		{ _field_terminator }
	};

	TAG_BLOCK(damage_region_block, k_total_damage_regions)
	{
		{ _field_struct, "animation*", &animation_index_struct_struct_definition },
		{ _field_terminator }
	};

	TAG_BLOCK(damage_direction_block, k_total_damage_directions)
	{
		{ _field_block, "regions*|AABBCC", &damage_region_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(damage_animation_block, k_max_death_and_damage_actions)
	{
		{ _field_string_id, "label^" },
		{ _field_block, "directions*|AABBCC", &damage_direction_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(animation_transition_destination_block, k_max_transition_animations)
	{
		{ _field_string_id, "mode name#name of the mode this transition ends in" },
		{ _field_string_id, "state name#name of the state this transition ends in" },
		{ _field_struct, "animation", &animation_index_struct_struct_definition },
		{ _field_terminator }
	};

	TAG_BLOCK(animation_transition_source_block, k_max_animations_per_block)
	{
		{ _field_string_id, "state name^#name of the state this transition starts in" },
		{ _field_block, "destinations", &animation_transition_destination_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(animation_velocity_boundaries_block, 1)
	{
		{ _field_array, "velocity boundary entries!", &animation_velocity_boundaries_array },
		{ _field_terminator }
	};

	TAG_BLOCK(animation_set_block, k_max_animation_sets)
	{
		{ _field_string_id, "label^" },
		{ _field_short_block_index, "overlay group{pose overlay|overlay}" },
		{ _field_short_block_index, "ik set" },
		{ _field_short_block_index, "gait group|AABBCC" },
		{ _field_pad, "asbfap", 2 },
		{ _field_block, "actions|AABBCC", &animation_entry_block_block },
		{ _field_block, "overlay animations{overlays}|AABBCC", &animation_entry_block_block },
		{ _field_block, "death and damage|AABBCC", &damage_animation_block_block },
		{ _field_block, "transitions|AABBCC", &animation_transition_source_block_block },
		{ _field_block, "velocity boundaries!", &animation_velocity_boundaries_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(weapon_type_block, k_max_weapon_types)
	{
		{ _field_string_id, "label^" },
		{ _field_short_block_index, "overlay group{pose overlay|overlay}" },
		{ _field_short_block_index, "ik set" },
		{ _field_block, "sets|AABBCC", &animation_set_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(animation_ik_block_v1, k_max_ik_points)
	{
		{ _field_custom },
		{ _field_string_id, "marker#the marker name on the object being attached" },
		{ _field_custom },
		{ _field_string_id, "attach to marker#the marker name object (weapon, vehicle, etc.) the above marker is being attached to" },
		{ _field_terminator }
	};

	TAG_BLOCK(ranged_animation_entry_block, k_max_animations_per_block)
	{
		{ _field_short_block_index, "overlay group{pose overlay|overlay}" },
		{ _field_short_block_index, "ik set" },
		{ _field_struct, "animation", &animation_index_struct_struct_definition },
		{ _field_real, "animation parameter#Numerical value associated with the ranged action animation (e.g. velocity for jumps)" },
		{ _field_real, "animation parameter b" },
		{ _field_terminator }
	};

	TAG_BLOCK(triangulation_point_block, k_max_triangulation_tag_points)
	{
		{ _field_real_vector_2d, "point" },
		{ _field_terminator }
	};

	TAG_BLOCK(triangulation_triangle_block, k_max_triangulation_tag_triangles)
	{
		{ _field_byte_integer, "vertex1" },
		{ _field_byte_integer, "vertex2" },
		{ _field_byte_integer, "vertex3" },
		{ _field_byte_integer, "link12" },
		{ _field_byte_integer, "link23" },
		{ _field_byte_integer, "link31" },
		{ _field_pad, "aaah", 2 },
		{ _field_terminator }
	};

	TAG_BLOCK(triangulation_entry_block, 1)
	{
		{ _field_block, "points", &triangulation_point_block_block },
		{ _field_block, "triangles", &triangulation_triangle_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(animation_ranged_action_block, k_max_ranged_actions)
	{
		{ _field_string_id, "label^" },
		{ _field_block, "animations", &ranged_animation_entry_block_block },
		{ _field_block, "triangulation data!", &triangulation_entry_block_block },
		{ _field_enum, "horizontal source", &ranged_action_variable_sources },
		{ _field_enum, "vertical source", &ranged_action_variable_sources },
		{ _field_enum, "start key", &frame_event_type_new },
		{ _field_enum, "end key", &frame_event_type_new },
		{ _field_terminator }
	};

	TAG_BLOCK(animation_sync_action_same_type_participant, k_max_sync_action_participants)
	{
		{ _field_long_flags, "flags", &animation_sync_action_flags_definition },
		{ _field_struct, "animation", &animation_index_struct_struct_definition },
		{ _field_real_point_3d, "start offset*" },
		{ _field_real_vector_3d, "start facing*" },
		{ _field_real_point_3d, "end offset*" },
		{ _field_real, "time_until_hurt*" },

		{ _field_version_greater, _engine_type_haloreach, 1 },
		{ _field_real_point_3d, "apex offset*" },

		{ _field_terminator }
	};

	TAG_BLOCK(animation_sync_action_other_type_participant, k_max_sync_action_participants)
	{
		{ _field_long_flags, "flags", &animation_sync_action_other_type_flags_definition },
		{ _field_tag_reference, "object type", &animation_sync_action_other_type_participant_object_type_reference },
		{ _field_terminator }
	};

	TAG_BLOCK(animation_sync_action_block, k_max_sync_actions)
	{
		{ _field_string_id, "name^" },
		{ _field_block, "same type participants", &animation_sync_action_same_type_participant_block },
		{ _field_block, "other participants", &animation_sync_action_other_type_participant_block },
		{ _field_terminator }
	};

	TAG_BLOCK(animation_sync_action_group_block, k_max_sync_action_groups)
	{
		{ _field_string_id, "name^" },
		{ _field_block, "sync actions", &animation_sync_action_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(weapon_class_block, k_max_weapon_classes)
	{
		{ _field_string_id, "label^" },
		{ _field_short_block_index, "overlay group{pose overlay|overlay}" },
		{ _field_short_block_index, "ik set" },
		{ _field_block, "weapon type|AABBCC", &weapon_type_block_block },
		{ _field_block, "weapon ik|AABBCC", &animation_ik_block_v1_block },
		{ _field_block, "ranged actions", &animation_ranged_action_block_block },
		{ _field_block, "sync actions groups", &animation_sync_action_group_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(foot_tracking_defaults, k_max_tracked_feet)
	{
		{ _field_short_block_index, "foot" },
		{ _field_enum, "default state", &foot_tracking_default_values },
		{ _field_terminator }
	};

	TAG_BLOCK(animation_mode_block, k_max_modes_per_graph)
	{
		{ _field_string_id, "label^" },
		{ _field_short_block_index, "overlay group{pose overlay|overlay}" },
		{ _field_short_block_index, "ik set" },
		{ _field_long_flags, "flags*", &animation_mode_flags },
		{ _field_block, "weapon class|AABBCC", &weapon_class_block_block },
		{ _field_block, "mode ik|AABBCC", &animation_ik_block_v1_block },
		{ _field_block, "foot defaults|AABBCC", &foot_tracking_defaults_block },
		{ _field_terminator }
	};

	TAG_BLOCK(vehicle_suspension_block, k_max_vehicle_suspensions)
	{
		{ _field_string_id, "label^" },
		{ _field_struct, "animation*", &animation_index_struct_struct_definition },
		{ _field_string_id, "function name" },
		{ _field_custom },
		{ _field_string_id, "marker name#this marker should be parented to the vehicle root node" },
		{ _field_custom },
		{ _field_string_id, "contact marker name#this marker should be parented to the wheel node" },
		{ _field_real, "mass point offset#distance along the vehicle\'s up direction to move the wheel from the marker location" },
		{ _field_real, "full extension ground_depth!" },
		{ _field_real, "full compression ground_depth!" },
		{ _field_explanation, "Destroyed Suspension", "Only Necessary for suspensions with a destroyed state" },
		{ _field_string_id, "region name" },
		{ _field_real, "destroyed mass point offset" },
		{ _field_real, "destroyed full extension ground_depth!" },
		{ _field_real, "destroyed full compression ground_depth!" },
		{ _field_terminator }
	};

	TAG_BLOCK(function_overlay_animation_block, k_max_function_overlays_per_graph)
	{
		{ _field_string_id, "label^" },
		{ _field_struct, "animation*", &animation_index_struct_struct_definition },
		{ _field_pad, "VQWLKE", 2 },
		{ _field_enum, "function controls", &function_overlay_animation_mode },
		{ _field_string_id, "function" },
		{ _field_pad, "OHIOJE", 4 },
		{ _field_terminator }
	};

	TAG_BLOCK(inherited_animation_node_map_block, k_max_nodes_per_animation)
	{
		{ _field_short_integer, "local node" },
		{ _field_terminator }
	};

	TAG_BLOCK(inherited_animation_node_map_flag_block, k_max_nodes_per_animation)
	{
		{ _field_long_integer, "local node flags" },
		{ _field_terminator }
	};

	TAG_BLOCK(inherited_animation_block, k_max_animation_inheritence_levels)
	{
		{ _field_tag_reference, "inherited graph*", &model_animation_graph_reference },
		{ _field_block, "node map*", &inherited_animation_node_map_block_block },
		{ _field_block, "node map flags*", &inherited_animation_node_map_flag_block_block },
		{ _field_long_integer, "inheritance_flags*" },
		{ _field_real, "uniform translation scale*" },
		{ _field_terminator }
	};

	TAG_BLOCK(weapon_class_lookup_block, k_max_weapon_types)
	{
		{ _field_string_id, "weapon name^" },
		{ _field_string_id, "weapon class" },
		{ _field_terminator }
	};

	TAG_BLOCK(additional_node_data_block, k_max_nodes_per_animation)
	{
		{ _field_string_id, "node name^" },
		{ _field_real_quaternion, "default rotation*" },
		{ _field_real_point_3d, "default translation*" },
		{ _field_real, "default scale*" },
		{ _field_real_point_3d, "min bounds" },
		{ _field_real_point_3d, "max bounds" },
		{ _field_terminator }
	};

	TAG_BLOCK(model_animation_tag_resource_group, k_max_animations_per_graph*3)
	{
		{ _field_long_integer, "reference_count*" },
		{ _field_pageable, "tag_resource" },
		{ _field_terminator }
	};

	TAG_BLOCK(shared_static_data_codec_rotation_block, k_max_animations_per_graph * k_max_nodes_per_animation)
	{
		{ _field_short_integer, "i" },
		{ _field_short_integer, "j" },
		{ _field_short_integer, "k" },
		{ _field_short_integer, "w" },
		{ _field_terminator }
	};

	TAG_BLOCK(shared_static_data_codec_translation_block, k_max_animations_per_graph * k_max_nodes_per_animation)
	{
		{ _field_real, "x" },
		{ _field_real, "y" },
		{ _field_real, "z" },
		{ _field_terminator }
	};

	TAG_BLOCK(shared_static_data_codec_scale_block, k_max_animations_per_graph * k_max_nodes_per_animation)
	{
		{ _field_real, "scale" },
		{ _field_terminator }
	};

	TAG_ARRAY(g_node_flag_storage_array, c_node_flags::k_flag_chunk_count)
	{
		{ _field_long_integer, "flag data" },
		{ _field_terminator }
	};

	TAG_ARRAY(animation_velocity_boundaries, k_animation_maximum_velocity_boundary_entries)
	{
		{ _field_real, "values!" },
		{ _field_terminator }
	};

	TAG_STRUCT(frame_event_list_struct_definition)
	{
		{ _field_explanation, "IMPORTANT TAG NOTES", "1) DO NOT XSYNC THIS TAG DIRECTLY.  Due to the nature of how this tag is processed, it is never\nloaded in-game.  Instead, xsync the parent model_animation_graph tag.  You can do this without\nchecking out the parent model_animation_graph; just find the tag in question in Bonobo, right-click it\nand select \'Force XSync\'.\n\n2) Legacy events are generated by the parent model_animation_graph.  They are generated when the model\nsidecar is imported, and the importer will try to resolve duplicated events with the frame_event_list.\nIf you need to delete a legacy animation event (or audio/effect event or reference for that matter) it \nmust be deleted from both the model_animation_graph tag AND the frame_event_list tag.\n\n3) The internal pipeline process for animation events now is:\n\t- When a sidecar is imported, if animation, effect, or audio events exist, they are copied into the\n\t  frame_event_list tag.  If the event already exists in the frame_event_list, its values are\n\t  retained.  Otherwise, default values are assigned such that the event behaves exactly as \n\t  it used to.  For the event ID, it is assigned the word \'Legacy\' with zero frame offset.\n\t- New frame events should be specified and saved in the frame_event_list tag (you\'re looking\n\t  at it).\n\t- When the model_animation_graph is compiled, the processor opens the associated frame_event_list\n\t  if one exists, reads and processes the data, and stores it back into the original \n\t  model_animation_graph on the xbox (or cache file), so no additional runtime memory or processing \n\t  time should be required.\n" },
		{ _field_block, "sound references|ABCDCC", &animation_graph_sound_reference_block_block },
		{ _field_block, "effect references|ABCDCC", &animation_graph_effect_reference_block_block },
		{ _field_block, "frame events|ABCDCC", &import_animation_event_block_block },
		{ _field_terminator }
	};

	TAG_STRUCT(animation_graph_definitions_struct)
	{
		{ _field_explanation, "GRAPH DATA", "" },
		{ _field_tag_reference, "parent animation graph", &model_animation_graph_reference },
		{ _field_byte_flags, "inheritance flags", &public_animation_graph_flags },
		{ _field_byte_flags, "private flags*", &private_animation_graph_flags },
		{ _field_short_integer, "animation codec pack*" },
		{ _field_enum, "force compression setting*", &compression_force_settings },
		{ _field_word_flags, "misc graph flags", &animation_graph_misc_flags },

		{ _field_version_greater, _engine_type_haloreach, 3 },
		{ _field_long_integer, "skeleton checksum" },
		{ _field_long_integer, "skeleton checksum lite" },
		{ _field_tag_reference, "imported events|ABCDCC", &global_frame_event_list_reference },

		{ _field_block, "node usage*|ABCDCC", &animation_usage_block_block },
		{ _field_block, "node masks|ABCDCC", &animation_node_mask_block_block },
		{ _field_block, "functions|ABCDCC", &animation_function_block_block },
		{ _field_block, "model animation variants|ABCDCC", &model_animation_variant_block_block },
		{ _field_block, "skeleton nodes*|ABCDCC", &animation_graph_node_block_block },
		{ _field_block, "sound references|ABCDCC!*#Legacy field - please edit in new frame event tag below", &animation_graph_sound_reference_block_block },
		{ _field_block, "effect references|ABCDCC!*#Legacy field - please edit in new frame event tag below", &animation_graph_effect_reference_block_block },
		{ _field_block, "blend screens|ABCDCC!*#Legacy field - please edit in NEW blend screens tag below", &animation_blend_screen_block_block },
		{ _field_block, "foot markers|ABCDCC", &foot_tracking_member_block_block },

		{ _field_version_equal, _engine_type_haloreach, 3 },
		{ _field_tag_reference, "imported events|ABCDCC", &global_frame_event_list_reference }, // moved

		{ _field_block, "animations*|ABCDCC", &animation_pool_block_block },
		{ _field_block, "NEW blend screens|CCBBAA", &new_animation_blend_screen_block_block },
		{ _field_block, "NEW function overlays|CCAABB", &new_animation_function_overlay_block_block },
		{ _field_block, "overlay groups{pose overlays|NEW overlays}|CCBBAA", &overlay_group_definition_block_block },
		{ _field_block, "gaits|ABCDCC", &animation_gait_block_block },
		{ _field_block, "gait groups|ABCDCC", &animation_gait_group_block_block },
		{ _field_block, "ik data|CCBBAA", &animation_ik_block_block },
		{ _field_block, "ik sets|CCBBAA", &animation_ik_set_block },
		{ _field_block, "ik chains|CCBBAA", &animation_ik_chain_block_block },

		{ _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_block, "composites", &g_compositeTag_block },
		{ _field_struct, "pca data", &PCAAnimationDataStruct_struct_definition },

		{ _field_terminator }
	};

	TAG_STRUCT(animation_aiming_screen_struct)
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

	TAG_STRUCT(shared_animation_reference_block)
	{
		{ _field_tag_reference, "graph reference!", &model_animation_graph_reference },
		{ _field_short_block_index, "shared animation index!" },
		{ _field_pad, "sarbp", 2 },
		{ _field_terminator }
	};

	TAG_STRUCT(quantized_orientation_struct)
	{
		{ _field_short_integer, "rotation x*" },
		{ _field_short_integer, "rotation y*" },
		{ _field_short_integer, "rotation z*" },
		{ _field_short_integer, "rotation w*" },
		{ _field_real_point_3d, "default translation*" },
		{ _field_real, "default scale*" },
		{ _field_terminator }
	};

	TAG_STRUCT(animation_ik_chain_events_struct)
	{
		{ _field_explanation, "REFERENCE IK CHAIN INFO", "" },
		{ _field_string_id, "chain name" },
		{ _field_enum, "chain type", &animation_ik_chain_type_enumeration },
		{ _field_short_block_index, "chain start node" },
		{ _field_short_block_index, "chain effector node" },
		{ _field_explanation, "IMPORTED IK CHAIN INFO", "" },
		{ _field_enum, "chain usage", &animation_ik_chain_event_usage },
		{ _field_string_id, "proxy marker" },
		{ _field_long_integer, "proxy id" },
		{ _field_char_enum, "event type", &animation_ik_chain_event_type },
		{ _field_byte_integer, "effector transform data index" },
		{ _field_byte_integer, "effector weight data index" },
		{ _field_byte_integer, "pole point data index" },
		{ _field_explanation, "POST PROCESS IK CHAIN INFO", "" },
		{ _field_byte_integer, "chain index" },
		{ _field_pad, "aikcep", 3 },
		{ _field_terminator }
	};

	TAG_STRUCT(animation_ik_chain_proxies_struct)
	{
		{ _field_long_integer, "id" },
		{ _field_custom },
		{ _field_string_id, "target marker" },
		{ _field_byte_integer, "proxy transform data index" },
		{ _field_pad, "aikcpp", 3 },
		{ _field_terminator }
	};

	TAG_STRUCT(animation_facial_wrinkle_events_struct)
	{
		{ _field_explanation, "REFERENCE FACIAL WRINKLE EVENT INFO", "" },
		{ _field_string_id, "wrinkle name" },
		{ _field_real, "default value" },
		{ _field_explanation, "IMPORTED FACIAL WRINKLE INFO", "" },
		{ _field_short_integer, "start frame" },
		{ _field_short_integer, "frame count" },
		{ _field_char_enum, "region", &animation_facial_wrinkle_region },
		{ _field_pad, "PADDNG", 3 },
		{ _field_explanation, "POST PROCESS WRINKLE EVENT INFO", "" },
		{ _field_short_integer, "wrinkle data index" },
		{ _field_pad, "aikcep", 2 },
		{ _field_terminator }
	};

	TAG_STRUCT(animation_extended_events_struct)
	{
		{ _field_explanation, "IMPORTED EXTENDED DATA EVENT INFO", "" },
		{ _field_string_id, "name" },
		{ _field_short_integer, "start frame" },
		{ _field_short_integer, "frame count" },
		{ _field_real, "default value" },
		{ _field_short_integer, "data index" },
		{ _field_pad, "pants", 2 },
		{ _field_terminator }
	};

	TAG_STRUCT(animation_object_functions_struct)
	{
		{ _field_string_id, "real_name!*" },
		{ _field_long_enum, "name", &animation_object_function_name },
		{ _field_short_integer, "start frame" },
		{ _field_short_integer, "frame count" },
		{ _field_struct, "function curve", &scalar_function_named_struct_struct_definition },
		{ _field_terminator }
	};

	TAG_STRUCT(animation_index_struct)
	{
		{ _field_short_integer, "graph index!" },
		{ _field_short_block_index, "animation" },
		{ _field_terminator }
	};

	TAG_STRUCT(PCAAnimationDataStruct)
	{
		{ _field_explanation, "Group Settings", "For each PCA Group desired, provide a unique name and desired number of blend shapes.\nThen, assign animations to these groups by setting their pca group name field" },
		{ _field_block, "PCA Groups", &PCAGroupSettingsBlock_block },
		{ _field_explanation, "PCA Animation Tag", "This is where all the imported pca blend shape animation will be stored.\nIf any animations in this graph contain PCA blend shape animation,\ncreate a unique pca_animation tag for this animation graph and link it here.\nOtherwise, one will be created for you." },
		{ _field_tag_reference, "pca animation|ABCDCC", &global_pca_animation_tag_reference },
		{ _field_long_integer, "PCA Animation Count*!" },
		{ _field_long_integer, "PCA Checksum*!" },
		{ _field_terminator }
	};

	TAG_STRUCT(animation_graph_contents_struct)
	{
		{ _field_explanation, "MODE-n-STATE GRAPH", "" },
		{ _field_short_block_index, "default gait group|CCAABB" },
		{ _field_pad, "agcsfap", 2 },
		{ _field_block, "modes|AABBCC", &animation_mode_block_block },
		{ _field_explanation, "SPECIAL CASE ANIMS", "" },
		{ _field_block, "vehicle suspension|CCAABB", &vehicle_suspension_block_block },
		{ _field_block, "function overlays{object overlays}|CCAABB", &function_overlay_animation_block_block },
		{ _field_terminator }
	};

	TAG_STRUCT(model_animation_runtime_data_struct)
	{
		{ _field_explanation, "RUN-TIME DATA", "" },
		{ _field_block, "inheritence list*|BBAAAA", &inherited_animation_block_block },
		{ _field_block, "new inheritance list*|BBAAAA", &inherited_animation_block_block },
		{ _field_block, "weapon list|BBAAAA", &weapon_class_lookup_block_block },
		{ _field_array, "left arm bit vector!", &g_node_flag_storage_array_array },
		{ _field_array, "right arm bit vector!", &g_node_flag_storage_array_array },
		{ _field_data, "animationPlayCounts!" },
		{ _field_terminator }
	};

	TAG_STRUCT(animation_codec_data_struct)
	{
		{ _field_explanation, "CODEC-SPECIFIC DATA", "fields used by varous compression codecs to store shared or global data for this graph. Do not manually edit." },
		{ _field_struct, "shared_static_codec*!", &shared_static_data_codec_graph_data_struct_struct_definition },
		{ _field_terminator }
	};

	TAG_STRUCT(shared_static_data_codec_graph_data_struct)
	{
		{ _field_explanation, "Shared Static Codec", "" },
		{ _field_block, "rotations*!", &shared_static_data_codec_rotation_block_block },
		{ _field_block, "translations*!", &shared_static_data_codec_translation_block_block },
		{ _field_block, "scale*!", &shared_static_data_codec_scale_block_block },
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

} // namespace blofeld

