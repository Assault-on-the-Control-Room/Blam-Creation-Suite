#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define CINEMATIC_STRUCT_DEFINITION_ID { 0xC3B34AC3, 0x066746A9, 0x861EC843, 0xA1016B03 }
	TAG_BLOCK(
		cinematic_block,
		"cinematic_block",
		1,
		"s_cinematic_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | 
		SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		CINEMATIC_STRUCT_DEFINITION_ID)
	{
		FIELD_CUSTOM("custom playback", nullptr, FIELD_FLAG_NONE, _field_id_cinematic_playback),
		{ _field_struct, "cinematic playback", FIELD_FLAG_UNKNOWN0, &cinematic_playback_data_block },
		{ _field_struct, "scenario and zone set", &scenario_and_zone_set_struct },
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_enum, "channel type", &cinematic_channel_type_enum },
		FIELD_PAD("PADDING", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_long_flags, "flags", &cinematic_flags },
		{ _field_real, "easing in time", "seconds" },
		{ _field_real, "easing out time", "seconds" },
		{ _field_tag_reference, "transition settings", &cinematic_transition_reference },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_pad, "PADDING@", 32 },

		{ _field_tag_reference, "bink movie", &bink_reference },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_string, "bink movie on disc" },

		FIELD_CUSTOM("Header", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_struct, "header", &cinematic_custom_script_block },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		{ _field_block, "scenes", &cinematic_scene_reference_block },
		FIELD_CUSTOM("Footer", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_struct, "footer", &cinematic_custom_script_block },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		FIELD_CUSTOM("If The Player Skips", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_struct, "early exit", &cinematic_custom_script_block },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		{ _field_terminator }
	};

	TAG_GROUP(
		cinematic_group,
		CINEMATIC_TAG,
		nullptr,
		INVALID_TAG,
		cinematic_block );

	TAG_GROUP(
		cinematic_scene_group,
		CINEMATIC_SCENE_TAG,
		nullptr,
		INVALID_TAG,
		cinematic_scene_block );

	TAG_GROUP(
		cinematic_scene_data_group,
		CINEMATIC_SCENE_DATA_TAG,
		nullptr,
		INVALID_TAG,
		cinematic_scene_data_block );

	#define CINEMATIC_TRANSITION_STRUCT_DEFINITION_ID { 0xB7AC8CFA, 0x1E964BA2, 0x84A035B9, 0x0A068B73 }
	TAG_BLOCK(
		cinematic_transition_block,
		"cinematic_transition_block",
		1,
		"s_cinematic_transition_data",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		CINEMATIC_TRANSITION_STRUCT_DEFINITION_ID)
	{
		FIELD_CUSTOM("fade out from game", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_struct, "fade out from game struct", &cinematic_transition_element_block },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		FIELD_CUSTOM("fade in to cinematic", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_struct, "fade in to cinematic struct", &cinematic_transition_element_block },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		FIELD_CUSTOM("fade out from cinematic", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_struct, "fade out from cinematic struct", &cinematic_transition_element_block },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		FIELD_CUSTOM("fade post core load", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_struct, "fade post core load struct", &cinematic_transition_element_block },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		FIELD_CUSTOM("fade in to game", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_struct, "fade in to game struct", &cinematic_transition_element_block },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		{ _field_terminator }
	};

	TAG_GROUP(
		cinematic_transition_group,
		CINEMATIC_TRANSITION_TAG,
		nullptr,
		INVALID_TAG,
		cinematic_transition_block );

	TAG_BLOCK_FROM_STRUCT(
		cinematic_scene_block,
		"cinematic_scene_block",
		1,
		cinematic_scene_struct_definition);

	TAG_BLOCK_FROM_STRUCT(
		cinematic_scene_data_block,
		"cinematic_scene_data_block",
		1,
		cinematic_scene_data_struct_definition);

	#define CINEMATIC_SCENE_REFERENCE_BLOCK_ID { 0x77C11E67, 0x725B4B54, 0x916808BF, 0x593A841D }
	TAG_BLOCK(
		cinematic_scene_reference_block,
		"cinematic_scene_reference_block",
		MAX_CINEMATIC_SCENE_COUNT,
		"s_cinematic_scene_reference",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CINEMATIC_SCENE_REFERENCE_BLOCK_ID)
	{
		{ _field_tag_reference, "scene", &cinematic_scene_reference },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_tag_reference, "data", &cinematic_scene_data_reference },

		{ _field_terminator }
	};

	#define CINEMATIC_SHOT_PLAYBACK_DATA_BLOCK_ID { 0xBCE7A6B4, 0xE12744C9, 0xBEAEBC13, 0xD21CF591 }
	TAG_BLOCK(
		cinematic_shot_playback_data_block,
		"cinematic_shot_playback_data_block",
		MAX_CINEMATIC_SCENE_COUNT,
		"s_cinematic_shot_playback_data",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CINEMATIC_SHOT_PLAYBACK_DATA_BLOCK_ID)
	{
		{ _field_array, "shot flags", FIELD_FLAG_UNKNOWN0, &g_cinematicShotFlagArray_array },
		{ _field_terminator }
	};

	#define CINEMATIC_SCENE_OBJECT_BLOCK_STRUCT_ID { 0x50C09E03, 0x425D488E, 0xA09DB8AD, 0x3EB374E0 }
	TAG_BLOCK(
		cinematic_scene_object_block,
		"cinematic_scene_object_block",
		10000,
		"s_scene_object",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		CINEMATIC_SCENE_OBJECT_BLOCK_STRUCT_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_READ_ONLY | FIELD_FLAG_INDEX },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 1 }, // from H4 cisd tag
		{ _field_legacy, _field_string_id, "identifier*" },

		{ _field_string_id, "variant name" },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 2 }, // from H4 cisd tag
		{ _field_legacy, _field_tag_reference, "model animation graph*", &global_animation_graph_reference },
		{ _field_legacy, _field_tag_reference, "object type*", &scene_object_attachment_block_attachment_type_reference },

		{ _field_long_flags, "flags", &scene_object_flags },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 2 }, // from H4 cisd tag
		{ _field_legacy, _field_custom, "shots active flags*" },
		{ _field_legacy, _field_array, "shots active flags*", &g_cinematicShotFlagArray_array },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 4 },
		FIELD_CUSTOM("lightmap shadow flags", nullptr, FIELD_FLAG_NONE, _field_id_cinematic_scene_flags),
		{ _field_array, "lightmap shadow flags", &g_cinematicShotFlagArray_array, _field_id_cinematic_scene_flags },
		FIELD_CUSTOM("high res flags", nullptr, FIELD_FLAG_NONE, _field_id_cinematic_scene_flags),
		{ _field_array, "high res flags", &g_cinematicShotFlagArray_array, _field_id_cinematic_scene_flags },

		{ _field_long_flags, "override creation flags", &cinematic_coop_type_flags },
		FIELD_EXPLANATION("Custom override creation condition", nullptr, FIELD_FLAG_NONE, "Used in combination with the override creation flags above"),
		{ _field_struct, "custom don't create condition", &cinematic_custom_script_block },
		{ _field_block, "attachments", &scene_object_attachment_block, _field_id_slap },
		{ _field_terminator }
	};

	#define SCENE_OBJECT_ATTACHMENT_BLOCK_ID { 0x713DCA38, 0xF48F4FA1, 0x87E89BFB, 0x1A6D2BC3 }
	TAG_BLOCK(
		scene_object_attachment_block,
		"scene_object_attachment_block",
		10000,
		"s_scene_object_attachment",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENE_OBJECT_ATTACHMENT_BLOCK_ID)
	{
		{ _field_byte_flags, "flags", &scene_object_attachment_flags },
		FIELD_PAD("VKJSLKHF", nullptr, FIELD_FLAG_NONE, 3),
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_marker),
		{ _field_string_id, "object marker name" },
		{ _field_string_id, "attachment object name", FIELD_FLAG_INDEX },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_marker),
		{ _field_string_id, "attachment marker name" },
		{ _field_tag_reference, "attachment type", &scene_object_attachment_block_attachment_type_reference },
		{ _field_terminator }
	};

	#define CINEMATIC_SHOT_BLOCK_STRUCT_ID { 0xCD10E9F0, 0x721C470E, 0x8571C1FE, 0xA88E8AC9 }
	TAG_BLOCK(
		cinematic_shot_block,
		"cinematic_shot_block",
		MAX_CINEMATIC_SHOT_COUNT,
		"s_scene_shot",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		CINEMATIC_SHOT_BLOCK_STRUCT_ID)
	{
		FIELD_CUSTOM("loop now", nullptr, FIELD_FLAG_NONE, _field_id_loop_cinematic_shot),
		FIELD_CUSTOM("Header", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_struct, "header", &cinematic_custom_script_block },
		{ _field_long_flags, "flags", &shot_flags_definition },
		FIELD_CUSTOM("environment darken", "this works best with auto-exposure off", FIELD_FLAG_NONE, _field_id_slider_editor),
		{ _field_real, "environment darken", "this works best with auto-exposure off", "0 - 1", _field_id_slider_editor },
		FIELD_CUSTOM("forced exposure", "will disable auto-exposure", FIELD_FLAG_NONE, _field_id_slider_editor),
		{ _field_real, "forced exposure", "will disable auto-exposure", "stops", _field_id_slider_editor },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		FIELD_CUSTOM("Settings", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_long_flags, "settings flags", &sceneShotSettingsFlags },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_real, "Lightmap Direct Scalar" },
		{ _field_real, "Lightmap Indirect Scalar" },

		{ _field_real, "Sun Scalar" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 3 },
		{ _field_tag_reference, "Atmosphere Fog", &global_atmosphere_definition_reference },
		{ _field_tag_reference, "Camera Effects", &global_camera_fx_settings_reference },
		{ _field_tag_reference, "Cubemap", &global_bitmap_reference },

		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		{ _field_block, "lighting", &cinematic_shot_lighting_block, _field_id_slap },
		{ _field_block, "clip", &cinematic_shot_clip_block, _field_id_slap },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },// from H4 cisd
		{ _field_legacy, _field_block, "dialogue", &cinematic_shot_dialogue_block },

		{ _field_block, "music", &cinematic_shot_music_block, _field_id_slap },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },// from H4 cisd
		{ _field_legacy, _field_block, "effects", &cinematic_shot_effect_block },

		{ _field_block, "object functions", &cinematic_shot_object_function_block, _field_id_slap },
		{ _field_block, "screen effects", &cinematic_shot_screen_effect_block, _field_id_slap },


		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 1 },// from H4 cisd
		{ _field_legacy, _field_block, "custom script", &cinematic_shot_custom_script_block },

		{ _field_block, "user input constraints", &cinematic_shot_user_input_constraints_block, _field_id_slap },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_block, "texture movies", &cinematicShotTextureMovieBlock_block, _field_id_slap },

		FIELD_CUSTOM("Footer", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_struct, "footer", &cinematic_custom_script_block },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 4 },// from H4 cisd
		{ _field_legacy, _field_long_integer, "frame count*" },
		{ _field_legacy, _field_block, "frame data*", &cinematic_shot_frame_block },
		{ _field_legacy, _field_block, "dynamic frame data*!", &cinematic_shot_frame_dynamic_block },
		{ _field_legacy, _field_block, "constant frame data*!", &cinematic_shot_frame_constant_block },

		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		{ _field_terminator }
	};

	#define CINEMATIC_SHOT_LIGHTING_BLOCK_ID { 0x6F86178C, 0xF5E04C8F, 0xA14C3003, 0xEAADCE78 }
	TAG_BLOCK(
		cinematic_shot_lighting_block,
		"cinematic_shot_lighting_block",
		10000,
		"s_scene_shot_lighting",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CINEMATIC_SHOT_LIGHTING_BLOCK_ID)
	{
		{ _field_long_flags, "flags", &cinematic_shot_lighting_flags_definition },
		{ _field_tag_reference, "lighting", &global_new_cinematic_lighting_reference },
		{ _field_long_block_index, "subject", FIELD_FLAG_INDEX, &cinematic_scene_object_block },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_marker),
		{ _field_string_id, "marker" },
		{ _field_terminator }
	};

	#define CINEMATIC_SHOT_CLIP_BLOCK_ID { 0xE6CA5E17, 0x64634682, 0x97D7DE14, 0x41724603 }
	TAG_BLOCK(
		cinematic_shot_clip_block,
		"cinematic_shot_clip_block",
		k_maximum_scene_shot_clip_plane_count,
		"s_scene_shot_clip",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		CINEMATIC_SHOT_CLIP_BLOCK_ID)
	{
		{ _field_real_point_3d, "plane center" },
		{ _field_real_point_3d, "plane direction" },
		FIELD_CUSTOM("frame start", nullptr, FIELD_FLAG_NONE, _field_id_cinematic_frame_index),
		{ _field_long_integer, "frame start", _field_id_cinematic_frame_index },
		FIELD_CUSTOM("frame end", nullptr, FIELD_FLAG_NONE, _field_id_cinematic_frame_index),
		{ _field_long_integer, "frame end", _field_id_cinematic_frame_index },
		{ _field_block, "subject objects", &cinematic_shot_clip_subject_block, _field_id_slap },
		{ _field_terminator }
	};

	#define CINEMATIC_SHOT_CLIP_SUBJECT_BLOCK_ID { 0xFD9DBB28, 0x7065418F, 0x93640300, 0xE4390930 }
	TAG_BLOCK(
		cinematic_shot_clip_subject_block,
		"cinematic_shot_clip_subject_block",
		k_maximum_scene_shot_clip_subject_count,
		"s_scene_shot_clip_subject",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CINEMATIC_SHOT_CLIP_SUBJECT_BLOCK_ID)
	{
		{ _field_long_block_index, "index", &cinematic_scene_object_block },
		{ _field_terminator }
	};

	#define CINEMATIC_SHOT_MUSIC_BLOCK_ID { 0xC8BD6E28, 0x7DEA45AA, 0x9861384B, 0xA392711F }
	TAG_BLOCK(
		cinematic_shot_music_block,
		"cinematic_shot_music_block",
		10000,
		"s_scene_shot_music",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CINEMATIC_SHOT_MUSIC_BLOCK_ID)
	{
		{ _field_long_flags, "flags", &music_flags_enum },
		{ _field_tag_reference, "music/foley", &global_sound_and_looping_sound_reference },
		FIELD_CUSTOM("frame", nullptr, FIELD_FLAG_NONE, _field_id_cinematic_frame_index),
		{ _field_long_integer, "frame", _field_id_cinematic_frame_index },
		{ _field_terminator }
	};

	#define CINEMATIC_SHOT_OBJECT_FUNCTION_BLOCK_ID { 0x5AA608DA, 0xB9F145EE, 0xAF52C72D, 0x315EC520 }
	TAG_BLOCK(
		cinematic_shot_object_function_block,
		"cinematic_shot_object_function_block",
		10000,
		"s_scene_object_function",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		CINEMATIC_SHOT_OBJECT_FUNCTION_BLOCK_ID)
	{
		{ _field_long_block_index, "object", &cinematic_scene_object_block },
		{ _field_string_id, "function name" },
		{ _field_block, "keyframes", &cinematic_shot_object_function_keyframe_block },
		{ _field_terminator }
	};

	#define CINEMATIC_SHOT_OBJECT_FUNCTION_KEYFRAME_BLOCK_ID { 0x272DF6C5, 0xFB2B42CF, 0x8D0089D4, 0x982001C8 }
	TAG_BLOCK(
		cinematic_shot_object_function_keyframe_block,
		"cinematic_shot_object_function_keyframe_block",
		10000,
		"s_scene_object_function_keyframe",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CINEMATIC_SHOT_OBJECT_FUNCTION_KEYFRAME_BLOCK_ID)
	{
		{ _field_long_flags, "flags", &cinematic_shot_object_function_flags },
		FIELD_CUSTOM("frame", nullptr, FIELD_FLAG_NONE, _field_id_cinematic_frame_index),
		{ _field_long_integer, "frame", _field_id_cinematic_frame_index },
		{ _field_real, "value" },
		{ _field_real, "interpolation time", nullptr, "ticks" },
		{ _field_terminator }
	};

	#define CINEMATIC_SHOT_SCREEN_EFFECT_BLOCK_ID { 0xCBE8C0A5, 0xAC9D47F8, 0x8713016E, 0x344C3792 }
	TAG_BLOCK(
		cinematic_shot_screen_effect_block,
		"cinematic_shot_screen_effect_block",
		10000,
		"s_scene_shot_screen_effect",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CINEMATIC_SHOT_SCREEN_EFFECT_BLOCK_ID)
	{
		{ _field_tag_reference, "screen effect", &global_area_screen_effect_reference },
		FIELD_CUSTOM("frame", nullptr, FIELD_FLAG_NONE, _field_id_cinematic_frame_index),
		{ _field_long_integer, "frame", _field_id_cinematic_frame_index },
		FIELD_CUSTOM("stop frame", nullptr, FIELD_FLAG_NONE, _field_id_cinematic_frame_index),
		{ _field_long_integer, "stop frame", _field_id_cinematic_frame_index },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_byte_flags, "flags", &cinematicShotScreenEffectFlags },
		FIELD_PAD("BLAHWWW", nullptr, FIELD_FLAG_NONE, 3),

		{ _field_terminator }
	};

	#define CINEMATIC_SHOT_USER_INPUT_CONSTRAINTS_BLOCK_ID { 0xF997FF41, 0xDFBF4267, 0x9DE524D7, 0x2624CB23 }
	TAG_BLOCK(
		cinematic_shot_user_input_constraints_block,
		"cinematic_shot_user_input_constraints_block",
		10000,
		"s_scene_shot_user_input_constraints",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CINEMATIC_SHOT_USER_INPUT_CONSTRAINTS_BLOCK_ID)
	{
		FIELD_CUSTOM("frame", nullptr, FIELD_FLAG_NONE, _field_id_cinematic_frame_index),
		{ _field_long_integer, "frame", _field_id_cinematic_frame_index },
		{ _field_long_integer, "ticks" },
		{ _field_rectangle_2d, "maximum look angles" },
		{ _field_real, "frictional force" },
		{ _field_terminator }
	};

	#define CINEMATICSHOTTEXTUREMOVIEBLOCK_ID { 0x7AC4065C, 0x22F04AD1, 0x895E6A2C, 0x059924DB }
	TAG_BLOCK(
		cinematicShotTextureMovieBlock_block,
		"cinematicShotTextureMovieBlock",
		10000,
		"ShotTextureMovie",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CINEMATICSHOTTEXTUREMOVIEBLOCK_ID)
	{
		{ _field_long_flags, "flags", &textureMovieFlags },
		FIELD_CUSTOM("frame", nullptr, FIELD_FLAG_NONE, _field_id_cinematic_frame_index),
		{ _field_long_integer, "frame", _field_id_cinematic_frame_index },
		{ _field_tag_reference, "bink movie", &bink_reference },
		{ _field_terminator }
	};

	#define CINEMATICSTRUCTURELIGHTINGBLOCK_ID { 0xF27B62CA, 0x34B243BF, 0x924FBCFD, 0xE3D020B9 }
	TAG_BLOCK(
		cinematicStructureLightingBlock_block,
		"cinematicStructureLightingBlock",
		32,
		"CinematicStructureLighting",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CINEMATICSTRUCTURELIGHTINGBLOCK_ID)
	{
		{ _field_tag_reference, "structure lighting info", FIELD_FLAG_INDEX, &structure_lighting_bsp_reference },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(
		cinematicSceneDataObjectBlock_block,
		"cinematicSceneDataObjectBlock",
		10000,
		cinematicSceneDataObjectBlock_struct);

	#define CINEMATICDATASHOTBLOCK_ID { 0x93F7EE7A, 0xECF14886, 0x997A153B, 0x3FE4CE24 }
	TAG_BLOCK(
		cinematicDataShotBlock_block,
		"cinematicDataShotBlock",
		MAX_CINEMATIC_SHOT_COUNT,
		"SceneDataShot",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		CINEMATICDATASHOTBLOCK_ID)
	{
		{ _field_block, "dialogue", &cinematic_shot_dialogue_block, _field_id_slap },
		{ _field_block, "effects", &cinematic_shot_effect_block, _field_id_slap },
		{ _field_block, "custom script", &cinematic_shot_custom_script_block, _field_id_slap },
		{ _field_long_integer, "frame count", FIELD_FLAG_READ_ONLY },
		{ _field_block, "frame data", FIELD_FLAG_READ_ONLY, &cinematic_shot_frame_block, _field_id_slap },
		{ _field_block, "dynamic frame data", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &cinematic_shot_frame_dynamic_block, _field_id_slap },
		{ _field_block, "constant frame data", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &cinematic_shot_frame_constant_block, _field_id_slap },
		{ _field_terminator }
	};

	#define CINEMATIC_SHOT_DIALOGUE_BLOCK_ID { 0x71BBACCC, 0x8A6D4B0B, 0xB080D7CC, 0x12A99F39 }
	TAG_BLOCK(
		cinematic_shot_dialogue_block,
		"cinematic_shot_dialogue_block",
		10000,
		"s_scene_shot_dialogue",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CINEMATIC_SHOT_DIALOGUE_BLOCK_ID)
	{
		{ _field_tag_reference, "dialogue", FIELD_FLAG_READ_ONLY, &global_sound_reference },
		{ _field_tag_reference, "female dialogue", FIELD_FLAG_READ_ONLY, &global_sound_reference },
		FIELD_CUSTOM("frame", nullptr, FIELD_FLAG_READ_ONLY, _field_id_cinematic_frame_index),
		{ _field_long_integer, "frame", FIELD_FLAG_READ_ONLY, _field_id_cinematic_frame_index },
		{ _field_real, "scale", FIELD_FLAG_READ_ONLY },
		{ _field_string_id, "lipsync actor", FIELD_FLAG_READ_ONLY },
		{ _field_string_id, "default sound effect" },
		{ _field_string_id, "subtitle" },
		{ _field_string_id, "female subtitle" },
		{ _field_string_id, "character" },
		{ _field_terminator }
	};

	#define CINEMATIC_SHOT_EFFECT_BLOCK_ID { 0x1FE3755D, 0xB74B489F, 0xB43E9A17, 0x145632C0 }
	TAG_BLOCK(
		cinematic_shot_effect_block,
		"cinematic_shot_effect_block",
		10000,
		"s_scene_shot_effect",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CINEMATIC_SHOT_EFFECT_BLOCK_ID)
	{
		{ _field_byte_flags, "flags", &cinematic_shot_effect_flags },
		{ _field_char_enum, "state", &sceneShotEffectState },
		FIELD_PAD("CMVOIRLKSD", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_tag_reference, "effect", &global_effect_reference },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_real, "size scale" },

		FIELD_CUSTOM("frame", nullptr, FIELD_FLAG_NONE, _field_id_cinematic_frame_index),
		{ _field_long_integer, "frame", _field_id_cinematic_frame_index },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_marker),
		{ _field_string_id, "marker name" },
		{ _field_long_block_index, "marker parent", &cinematicSceneDataObjectBlock_block },
		{ _field_string_id, "function a" },
		{ _field_string_id, "function b" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_long_integer, "node id", FIELD_FLAG_UNKNOWN0 },
		{ _field_long_integer, "sequence id", FIELD_FLAG_UNKNOWN0 },

		{ _field_terminator }
	};

	#define CINEMATIC_SHOT_CUSTOM_SCRIPT_BLOCK_ID { 0xBC8133AA, 0xC1F84079, 0x922C7BA9, 0x5FCA1CD2 }
	TAG_BLOCK(
		cinematic_shot_custom_script_block,
		"cinematic_shot_custom_script_block",
		10000,
		"s_scene_shot_custom_script",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		CINEMATIC_SHOT_CUSTOM_SCRIPT_BLOCK_ID)
	{
		{ _field_byte_flags, "flags", FIELD_FLAG_UNKNOWN0, &cinematic_shot_custom_script_flags },
		FIELD_PAD("CMVOIRLKSD", nullptr, FIELD_FLAG_NONE, 3),
		FIELD_CUSTOM("frame", nullptr, FIELD_FLAG_NONE, _field_id_cinematic_frame_index),
		{ _field_long_integer, "frame", _field_id_cinematic_frame_index },
		{ _field_struct, "script", &cinematic_custom_script_block },
		{ _field_long_integer, "node id", FIELD_FLAG_UNKNOWN0 },
		{ _field_long_integer, "sequence id", FIELD_FLAG_UNKNOWN0 },
		{ _field_terminator }
	};

	#define CINEMATIC_SHOT_FRAME_BLOCK_ID { 0xBD4D0364, 0x996745B6, 0x859A07A4, 0x186868E9 }
	TAG_BLOCK(
		cinematic_shot_frame_block,
		"cinematic_shot_frame_block",
		10000,
		"s_scene_shot_frame",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CINEMATIC_SHOT_FRAME_BLOCK_ID)
	{
		{ _field_struct, "camera frame", &camera_frame_struct },
		{ _field_terminator }
	};

	#define CINEMATIC_SHOT_FRAME_DYNAMIC_BLOCK_ID { 0x718252B2, 0x205E431F, 0xB6296B5A, 0xFE8EB20E }
	TAG_BLOCK(
		cinematic_shot_frame_dynamic_block,
		"cinematic_shot_frame_dynamic_block",
		10000,
		"s_scene_shot_frame_dynamic",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CINEMATIC_SHOT_FRAME_DYNAMIC_BLOCK_ID)
	{
		{ _field_struct, "dynamic camera frame", &camera_frame_dynamic_struct },
		{ _field_terminator }
	};

	#define CINEMATIC_SHOT_FRAME_CONSTANT_BLOCK_ID { 0xEC8CBCAC, 0x6D6B4ADA, 0x9476E1A8, 0x1F85D6B3 }
	TAG_BLOCK(
		cinematic_shot_frame_constant_block,
		"cinematic_shot_frame_constant_block",
		10000,
		"s_scene_shot_frame_constant",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CINEMATIC_SHOT_FRAME_CONSTANT_BLOCK_ID)
	{
		{ _field_long_integer, "frame index" },
		{ _field_struct, "constant camera frame", &camera_frame_constant_struct },
		{ _field_terminator }
	};

	#define CINEMATIC_SHOT_EXTRA_CAMERA_BLOCK_ID { 0x1451DA10, 0xDBD64C68, 0xAAABB84D, 0xD39799B3 }
	TAG_BLOCK(
		cinematic_shot_extra_camera_block,
		"cinematic_shot_extra_camera_block",
		10000,
		"s_scene_extra_camera",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		CINEMATIC_SHOT_EXTRA_CAMERA_BLOCK_ID)
	{
		{ _field_string_id, "name" },
		{ _field_string_id, "type" },
		{ _field_block, "shots", &cinematic_extra_camera_shot_block },
		{ _field_terminator }
	};

	#define CINEMATIC_EXTRA_CAMERA_SHOT_BLOCK_ID { 0x897BBEBF, 0xD4A34B10, 0x91144E0E, 0xE6EFBDD5 }
	TAG_BLOCK(
		cinematic_extra_camera_shot_block,
		"cinematic_extra_camera_shot_block",
		10000,
		"s_extra_camera_shot",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		CINEMATIC_EXTRA_CAMERA_SHOT_BLOCK_ID)
	{
		{ _field_block, "frame data", &cinematic_extra_camera_frame_block, _field_id_slap },
		{ _field_terminator }
	};

	#define CINEMATIC_EXTRA_CAMERA_FRAME_BLOCK_ID { 0x39DDFE90, 0x9DEA4DD3, 0x994B8B1C, 0xECB7261F }
	TAG_BLOCK(
		cinematic_extra_camera_frame_block,
		"cinematic_extra_camera_frame_block",
		10000,
		"s_extra_camera_frame",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CINEMATIC_EXTRA_CAMERA_FRAME_BLOCK_ID)
	{
		{ _field_long_flags, "flags", &cinematic_extra_camera_frame_flags },
		{ _field_struct, "frame data", &camera_frame_struct },
		{ _field_terminator }
	};

	#define CINEMATIC_TRANSITION_GLOBAL_GAIN_BLOCK_STRUCT_ID { 0x8ACEB60C, 0xE6E34BD7, 0xB3B66F6C, 0xB34F073C }
	TAG_BLOCK(
		cinematic_transition_global_gain_block,
		"cinematic_transition_global_gain_block",
		1,
		"s_cinematic_transition_global_gain_data",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CINEMATIC_TRANSITION_GLOBAL_GAIN_BLOCK_STRUCT_ID)
	{
		{ _field_real, "gain", nullptr, "dB", FIELD_FLAG_INDEX },
		{ _field_long_integer, "time", nullptr, "hs_ticks" },
		{ _field_terminator }
	};

	#define CINEMATIC_TRANSITION_SOUND_CLASS_GAIN_BLOCK_STRUCT_ID { 0x96B5CEC2, 0x0E82478A, 0xBCBF8B27, 0xABF26BCF }
	TAG_BLOCK(
		cinematic_transition_sound_class_gain_block,
		"cinematic_transition_sound_class_gain_block",
		8,
		"s_cinematic_transition_sound_class_gain_data",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CINEMATIC_TRANSITION_SOUND_CLASS_GAIN_BLOCK_STRUCT_ID)
	{
		{ _field_char_enum, "class", FIELD_FLAG_INDEX, &sound_class_enum },
		FIELD_PAD("pad", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_real, "gain", nullptr, "dB" },
		{ _field_long_integer, "time", nullptr, "hs_ticks" },
		{ _field_terminator }
	};

	#define CINEMATIC_TRANSITION_SOUND_REFERENCE_BLOCK_STRUCT_ID { 0x13D7CCC9, 0x85304398, 0x85357F68, 0x2D49AD3A }
	TAG_BLOCK(
		cinematic_transition_sound_reference_block,
		"cinematic_transition_sound_reference_block",
		4,
		"s_cinematic_transition_sound_reference",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CINEMATIC_TRANSITION_SOUND_REFERENCE_BLOCK_STRUCT_ID)
	{
		{ _field_tag_reference, "sound", FIELD_FLAG_INDEX, &global_sound_and_looping_sound_reference },
		{ _field_terminator }
	};

	#define CINEMATIC_TRANSITION_LOOPING_SOUND_REFERENCE_BLOCK_STRUCT_ID { 0xBAFE65BC, 0x9F534CB0, 0x84B2ED70, 0xA68F0ECF }
	TAG_BLOCK(
		cinematic_transition_looping_sound_reference_block,
		"cinematic_transition_looping_sound_reference_block",
		4,
		"s_cinematic_transition_sound_reference",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CINEMATIC_TRANSITION_LOOPING_SOUND_REFERENCE_BLOCK_STRUCT_ID)
	{
		{ _field_tag_reference, "looping sound", FIELD_FLAG_INDEX, &global_looping_sound_reference },
		{ _field_terminator }
	};

	#define CINEMATIC_TRANSITION_LOOPING_SOUND_STATE_BLOCK_STRUCT_ID { 0x827B3E86, 0x2BAC4782, 0xAF5E4C04, 0x3F3B687E }
	TAG_BLOCK(
		cinematic_transition_looping_sound_state_block,
		"cinematic_transition_looping_sound_state_block",
		4,
		"s_cinematic_transition_looping_sound_state",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CINEMATIC_TRANSITION_LOOPING_SOUND_STATE_BLOCK_STRUCT_ID)
	{
		{ _field_tag_reference, "looping sound", FIELD_FLAG_INDEX, &global_looping_sound_reference },
		{ _field_real, "scale" },
		{ _field_word_flags, "alternate", &cinematic_transition_looping_sound_alternate_flags },
		{ _field_word_flags, "layers", &cinematic_transition_looping_sound_layer_flags },
		{ _field_terminator }
	};

	#define CINEMATICS_GLOBALS_BLOCK_ID { 0x3B2F2A5B, 0x52DF4FB0, 0xA68FFF8B, 0x30D069D7 }
	TAG_BLOCK(
		cinematics_globals_block,
		"cinematics_globals_block",
		1,
		"cinematics_globals_block",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		CINEMATICS_GLOBALS_BLOCK_ID)
	{
		{ _field_tag_reference, "cinematic anchor reference", &scenery_reference },
		{ _field_real, "cinematic film aperture" },
		{ _field_real, "cinematic skip ui up time" },
		{ _field_real_fraction_bounds, "subtitle rect width", "percentage towards the center - 0=default, 0.5=center of the screen" },
		{ _field_real_fraction_bounds, "subtitle rect height", "0=default, 0.5=center of the screen" },
		{ _field_real_rgb_color, "default subtitle color" },
		{ _field_real_rgb_color, "default subtitle shadow color" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_block, "cinematic characters", &cinematic_characters_block },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 3 }, // possibly cinematic characters but unused
		{ _field_legacy, _field_long_integer, "unknown@" },
		{ _field_legacy, _field_long_integer, "unknown@" },
		{ _field_legacy, _field_long_integer, "unknown@" },

		{ _field_terminator }
	};

	#define CINEMATIC_CHARACTERS_BLOCK_ID { 0x4A6E3D74, 0xC507478D, 0x862BFF5F, 0x1F1FA177 }
	TAG_BLOCK(
		cinematic_characters_block,
		"cinematic_characters_block",
		16,
		"s_cinematic_character",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CINEMATIC_CHARACTERS_BLOCK_ID)
	{
		{ _field_string_id, "character name", FIELD_FLAG_INDEX },
		{ _field_real_rgb_color, "subtitle color" },
		{ _field_real_rgb_color, "shadow color" },
		{ _field_terminator }
	};

	#define SCENARIO_CINEMATICS_BLOCK_ID { 0x59336E8E, 0x27A04735, 0xA9545DF3, 0x921A7282 }
	TAG_BLOCK(
		scenario_cinematics_block,
		"scenario_cinematics_block",
		MAXIMUM_SCENARIO_CINEMATICS,
		"s_cinematic_reference",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_CINEMATICS_BLOCK_ID)
	{
		{ _field_byte_flags, "flags", &scenario_cinematics_flags },
		FIELD_PAD("SDJLKANF", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_tag_reference, "name", FIELD_FLAG_INDEX, &cinematic_reference },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(
		scenario_cutscene_title_block,
		"scenario_cutscene_title_block",
		k_maximum_scenario_cutscene_titles,
		scenario_cutscene_title_struct);

	#define G_CINEMATICSHOTFLAGARRAY_ID { 0x519DEDF9, 0x1CBB442B, 0xAC615A1F, 0xAD7FAB9B }
	TAG_ARRAY(
		g_cinematicShotFlagArray_array,
		"g_cinematicShotFlagArray",
		c_cinematic_shot_flags::k_flag_chunk_count,
		"c_big_flags_chunk_type",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		G_CINEMATICSHOTFLAGARRAY_ID)
	{
		{ _field_dword_integer, "shot flag data" },
		{ _field_terminator }
	};

	#define CINEMATIC_SCENE_STRUCT_DEFINITION_ID { 0x2F16CF25, 0xB4144920, 0xAA9CA793, 0x06DFF67F }
	TAG_STRUCT(
		cinematic_scene_struct_definition,
		"cinematic_scene_struct_definition",
		"s_cinematic_scene",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | 
		SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		CINEMATIC_SCENE_STRUCT_DEFINITION_ID)
	{
		FIELD_CUSTOM("loop now", nullptr, FIELD_FLAG_NONE, _field_id_loop_cinematic_scene),
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_string_id, "anchor" },
		{ _field_enum, "reset object lighting", &scene_reset_object_lighting_enum },
		FIELD_PAD("pad", nullptr, FIELD_FLAG_NONE, 2),

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_tag_reference, "data", FIELD_FLAG_READ_ONLY, &cinematic_scene_data_reference },

		FIELD_CUSTOM("Header", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_struct, "header", &cinematic_custom_script_block },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		{ _field_block, "objects", FIELD_FLAG_READ_ONLY, &cinematic_scene_object_block, _field_id_slap },
		{ _field_block, "shots", &cinematic_shot_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_block, "lights", &cinematicStructureLightingBlock_block, _field_id_slap },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_block, "extra camera frame data", FIELD_FLAG_READ_ONLY, &cinematic_shot_extra_camera_block, _field_id_slap },

		FIELD_CUSTOM("Footer", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_struct, "footer", &cinematic_custom_script_block },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_long_integer, "version*" },

		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		{ _field_terminator }
	};

	#define CINEMATIC_SCENE_DATA_STRUCT_DEFINITION_ID { 0x47C351F7, 0xEBF24619, 0xB563ACCC, 0xE2868568 }
	TAG_STRUCT(
		cinematic_scene_data_struct_definition,
		"cinematic_scene_data_struct_definition",
		"CinematicSceneData",
		SET_UNKNOWN0 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | 
		SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		CINEMATIC_SCENE_DATA_STRUCT_DEFINITION_ID)
	{
		{ _field_block, "objects", FIELD_FLAG_READ_ONLY, &cinematicSceneDataObjectBlock_block, _field_id_slap },
		{ _field_block, "shots", FIELD_FLAG_READ_ONLY, &cinematicDataShotBlock_block },
		{ _field_block, "extra camera frame data", FIELD_FLAG_READ_ONLY, &cinematic_shot_extra_camera_block, _field_id_slap },
		{ _field_long_integer, "version", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define CINEMATIC_PLAYBACK_DATA_BLOCK_ID { 0xEBD41AA0, 0x8EDA4FF2, 0x91204D62, 0x3C9BA5B4 }
	TAG_STRUCT(
		cinematic_playback_data_block,
		"cinematic_playback_data_block",
		"s_cinematic_playback_data",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		CINEMATIC_PLAYBACK_DATA_BLOCK_ID)
	{
		{ _field_long_block_flags, "scenes", FIELD_FLAG_UNKNOWN0, &cinematic_scene_reference_block },
		{ _field_long_block_flags, "scenes expanded", FIELD_FLAG_UNKNOWN0, &cinematic_scene_reference_block },
		{ _field_block, "shots", FIELD_FLAG_UNKNOWN0, &cinematic_shot_playback_data_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 1 },
		{ _field_long_integer, "bsp zone flags", FIELD_FLAG_UNKNOWN0 },

		{ _field_terminator }
	};

	#define SCENARIO_AND_ZONE_SET_STRUCT_ID { 0x68E9CE6F, 0xC3964CAE, 0xB0D8CDC6, 0xA3F5786D }
	TAG_STRUCT(
		scenario_and_zone_set_struct,
		"scenario_and_zone_set_struct",
		"s_scenario_and_zone_set",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_AND_ZONE_SET_STRUCT_ID)
	{
		{ _field_legacy, _field_version_greater, _engine_type_haloreach }, //why?
		FIELD_CUSTOM("custom ui", nullptr, FIELD_FLAG_NONE, _field_id_scenario_zone_set_index),

		{ _field_tag_reference, "scenario", FIELD_FLAG_UNKNOWN0, &scenario_reference },
		{ _field_long_integer, "zone set", FIELD_FLAG_UNKNOWN0 },
		{ _field_terminator }
	};

	#define CINEMATIC_CUSTOM_SCRIPT_BLOCK_ID { 0xC119D09A, 0x7F5F44A3, 0x9703E8E0, 0x3EFD6987 }
	TAG_STRUCT(
		cinematic_custom_script_block,
		"cinematic_custom_script_block",
		"s_cinematic_custom_script",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		CINEMATIC_CUSTOM_SCRIPT_BLOCK_ID)
	{
		{ _field_data, "script" },
		{ _field_terminator }
	};

	#define CINEMATICSCENEDATAOBJECTBLOCK_STRUCT_ID { 0xDAB513EC, 0x33A549FA, 0x962D8DE6, 0x722B8799 }
	TAG_STRUCT(
		cinematicSceneDataObjectBlock_struct,
		"cinematicSceneDataObjectBlock_struct",
		"SceneDataObject",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CINEMATICSCENEDATAOBJECTBLOCK_STRUCT_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_READ_ONLY | FIELD_FLAG_INDEX },
		{ _field_string_id, "identifier", FIELD_FLAG_READ_ONLY },
		{ _field_tag_reference, "model animation graph", FIELD_FLAG_READ_ONLY, &global_animation_graph_reference },
		{ _field_tag_reference, "object type", FIELD_FLAG_READ_ONLY, &scene_object_attachment_block_attachment_type_reference },
		FIELD_CUSTOM("shots active flags", nullptr, FIELD_FLAG_READ_ONLY, _field_id_cinematic_scene_flags),
		{ _field_array, "shots active flags", FIELD_FLAG_READ_ONLY, &g_cinematicShotFlagArray_array, _field_id_cinematic_scene_flags },
		{ _field_terminator }
	};

	#define CAMERA_FRAME_STRUCT_ID { 0x24513EF2, 0x4F2E45C3, 0x08BDA4BB, 0xE783FA56 }
	TAG_STRUCT(
		camera_frame_struct,
		"camera_frame_struct",
		"s_camera_frame",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CAMERA_FRAME_STRUCT_ID)
	{
		{ _field_struct, "dynamic data", &camera_frame_dynamic_struct },
		{ _field_struct, "constant data", &camera_frame_constant_struct },
		{ _field_terminator }
	};

	#define CAMERA_FRAME_DYNAMIC_STRUCT_ID { 0xC705DD64, 0x32F8496A, 0x824ED19E, 0x17E1B595 }
	TAG_STRUCT(
		camera_frame_dynamic_struct,
		"camera_frame_dynamic_struct",
		"s_camera_frame_dynamic",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CAMERA_FRAME_DYNAMIC_STRUCT_ID)
	{
		{ _field_real_point_3d, "camera position", FIELD_FLAG_READ_ONLY },
		{ _field_real_vector_3d, "camera forward", FIELD_FLAG_READ_ONLY },
		{ _field_real_vector_3d, "camera up", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define CAMERA_FRAME_CONSTANT_STRUCT_ID { 0x12ABA01E, 0x09C34EC1, 0x09BEE2E9, 0xE1741C6A }
	TAG_STRUCT(
		camera_frame_constant_struct,
		"camera_frame_constant_struct",
		"s_camera_frame_constant",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CAMERA_FRAME_CONSTANT_STRUCT_ID)
	{
		{ _field_real, "focal length", FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "depth of field", FIELD_FLAG_READ_ONLY },
		{ _field_real, "near focal plane distance", FIELD_FLAG_READ_ONLY },
		{ _field_real, "far focal plane distance", FIELD_FLAG_READ_ONLY },
		{ _field_real, "near focal depth", FIELD_FLAG_READ_ONLY },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_real, "far focal depth", FIELD_FLAG_READ_ONLY },

		{ _field_real, "near blur amount", FIELD_FLAG_READ_ONLY },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_real, "far blur amount", FIELD_FLAG_READ_ONLY },

		{ _field_terminator }
	};

	#define CINEMATIC_TRANSITION_ELEMENT_BLOCK_ID { 0xA7937387, 0x8CDD41A3, 0x9C4CEBD7, 0xBA5E17E9 }
	TAG_STRUCT(
		cinematic_transition_element_block,
		"cinematic_transition_element_block",
		"s_cinematic_transition_element_data",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		CINEMATIC_TRANSITION_ELEMENT_BLOCK_ID)
	{
		{ _field_struct, "global fade", &cinematic_transition_global_fade_block },
		{ _field_block, "sound global gain", &cinematic_transition_global_gain_block },
		{ _field_block, "sound class gains", &cinematic_transition_sound_class_gain_block },
		{ _field_block, "stop sounds", &cinematic_transition_sound_reference_block },
		{ _field_block, "start sounds", &cinematic_transition_sound_reference_block },
		{ _field_block, "resume looping sounds", &cinematic_transition_looping_sound_reference_block },
		{ _field_block, "looping sound states", &cinematic_transition_looping_sound_state_block },
		{ _field_long_integer, "sleep time", nullptr, "hs_ticks" },
		{ _field_terminator }
	};

	#define CINEMATIC_TRANSITION_GLOBAL_FADE_BLOCK_ID { 0xA7E518D2, 0xE67D4F58, 0x9709C7D0, 0xAC2B8E6F }
	TAG_STRUCT(
		cinematic_transition_global_fade_block,
		"cinematic_transition_global_fade_block",
		"s_cinematic_transition_global_fade_data",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CINEMATIC_TRANSITION_GLOBAL_FADE_BLOCK_ID)
	{
		{ _field_real_rgb_color, "fade_color", FIELD_FLAG_INDEX },
		{ _field_long_integer, "fade time", nullptr, "hs_ticks" },
		{ _field_terminator }
	};

	#define SCENARIO_CUTSCENE_TITLE_STRUCT_ID { 0x110603E7, 0x74B8410A, 0x8C263BBC, 0xDC0D2541 }
	TAG_STRUCT(
		scenario_cutscene_title_struct,
		"scenario_cutscene_title_struct",
		"s_scenario_cutscene_title",
		SET_UNKNOWN0 | SET_POSTPROCESS_RECURSIVELY | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_CUTSCENE_TITLE_STRUCT_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_real_fraction_bounds, "text bounds X" },
		{ _field_real_fraction_bounds, "text bounds Y" },
		{ _field_enum, "justification", &text_justification_enum_definition },
		{ _field_enum, "vertical justification", &text_vertical_justification_enum_definition },
		{ _field_enum, "font", &global_font_id_enum_definition },
		FIELD_PAD("padding", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_rgb_color, "text color" },
		{ _field_rgb_color, "shadow color" },
		{ _field_real, "fade in time [seconds]" },
		{ _field_real, "up time [seconds]" },
		{ _field_real, "fade out time [seconds]" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_real, "letter print time", nullptr, "seconds" },

		{ _field_terminator }
	};

	STRINGS(scenario_cutscene_camera_flags)
	{
		"edit as relative"
	};
	STRING_LIST(scenario_cutscene_camera_flags, scenario_cutscene_camera_flags_strings, _countof(scenario_cutscene_camera_flags_strings));

	STRINGS(scenario_cutscene_camera_types)
	{
		"normal",
		"ignore target orientation",
		"dolly",
		"ignore target updates"
	};
	STRING_LIST(scenario_cutscene_camera_types, scenario_cutscene_camera_types_strings, _countof(scenario_cutscene_camera_types_strings));

	STRINGS(text_justification_enum_definition)
	{
		"left",
		"right",
		"center"
	};
	STRING_LIST(text_justification_enum_definition, text_justification_enum_definition_strings, _countof(text_justification_enum_definition_strings));

	STRINGS(text_vertical_justification_enum_definition)
	{
		"default",
		"top",
		"center",
		"bottom"
	};
	STRING_LIST(text_vertical_justification_enum_definition, text_vertical_justification_enum_definition_strings, _countof(text_vertical_justification_enum_definition_strings));

	STRINGS(cinematic_channel_type_enum)
	{
		"letterbox",
		"briefing",
		"perspective",
		"vignette",
		"bink briefing",
		"bink (full screen)"
	};
	STRING_LIST(cinematic_channel_type_enum, cinematic_channel_type_enum_strings, _countof(cinematic_channel_type_enum_strings));

	STRINGS(shot_flags_definition)
	{
		"Instant Auto-Exposure",
		"Force Exposure",
		"Generate Looping Script"
	};
	STRING_LIST(shot_flags_definition, shot_flags_definition_strings, _countof(shot_flags_definition_strings));

	STRINGS(cinematic_shot_lighting_flags_definition)
	{
		"persists across shots"
	};
	STRING_LIST(cinematic_shot_lighting_flags_definition, cinematic_shot_lighting_flags_definition_strings, _countof(cinematic_shot_lighting_flags_definition_strings));

	STRINGS(scene_object_flags)
	{
		"Placed Manually in Sapien",
		"Object Comes From Game",
		"Special Case (like player0)",
		"Effect Object",
		"No Lightmap Shadow",
		"Apply Player Customization",
		"Apply First Person Player Customization",
		"I will animate the English lipsync manually",
		"Primary Cortana",
		"Preload Textures"
	};
	STRING_LIST(scene_object_flags, scene_object_flags_strings, _countof(scene_object_flags_strings));

	STRINGS(cinematic_coop_type_flags)
	{
		"single player",
		"2 player co-op",
		"3 player co-op",
		"4 player co-op"
	};
	STRING_LIST(cinematic_coop_type_flags, cinematic_coop_type_flags_strings, _countof(cinematic_coop_type_flags_strings));

	STRINGS(scene_object_attachment_flags)
	{
		"invisible"
	};
	STRING_LIST(scene_object_attachment_flags, scene_object_attachment_flags_strings, _countof(scene_object_attachment_flags_strings));

	STRINGS(music_flags_enum)
	{
		"Stop Music At Frame (rather than starting it)"
	};
	STRING_LIST(music_flags_enum, music_flags_enum_strings, _countof(music_flags_enum_strings));

	STRINGS(textureMovieFlags)
	{
		"Stop Movie At Frame (rather than starting it)"
	};
	STRING_LIST(textureMovieFlags, textureMovieFlags_strings, _countof(textureMovieFlags_strings));

	STRINGS(cinematic_shot_effect_flags)
	{
		"use maya value!",
		"looping"
	};
	STRING_LIST(cinematic_shot_effect_flags, cinematic_shot_effect_flags_strings, _countof(cinematic_shot_effect_flags_strings));

	STRINGS(sceneShotEffectState)
	{
		"start",
		"stop",
		"kill"
	};
	STRING_LIST(sceneShotEffectState, sceneShotEffectState_strings, _countof(sceneShotEffectState_strings));

	STRINGS(cinematicShotScreenEffectFlags)
	{
		"Persist Entire Shot"
	};
	STRING_LIST(cinematicShotScreenEffectFlags, cinematicShotScreenEffectFlags_strings, _countof(cinematicShotScreenEffectFlags_strings));

	STRINGS(cinematic_shot_object_function_flags)
	{
		"clear function (Value and Interpolation time are unused)"
	};
	STRING_LIST(cinematic_shot_object_function_flags, cinematic_shot_object_function_flags_strings, _countof(cinematic_shot_object_function_flags_strings));

	STRINGS(cinematic_extra_camera_frame_flags)
	{
		"enabled"
	};
	STRING_LIST(cinematic_extra_camera_frame_flags, cinematic_extra_camera_frame_flags_strings, _countof(cinematic_extra_camera_frame_flags_strings));

	STRINGS(cinematic_shot_custom_script_flags)
	{
		"use maya value"
	};
	STRING_LIST(cinematic_shot_custom_script_flags, cinematic_shot_custom_script_flags_strings, _countof(cinematic_shot_custom_script_flags_strings));

	STRINGS(sceneShotSettingsFlags)
	{
		"Lightmap Scalars - set",
		"Lightmap Scalars - clear",
		"Lightmap Scalars - persist across shots",
		"Atmosphere Fog - clear",
		"Atmosphere fog - persist across shots",
		"Camera Effects - clear",
		"Camera Effects - persist across shots",
		"Sun Scalar - set",
		"Sun Scalar - clear",
		"Sun Scalar - persist across shots",
		"Cubemap - clear",
		"Cubemap - persist across shots",
		"Disable All Lightmap Shadows"
	};
	STRING_LIST(sceneShotSettingsFlags, sceneShotSettingsFlags_strings, _countof(sceneShotSettingsFlags_strings));

	STRINGS(scene_reset_object_lighting_enum)
	{
		"Default",
		"Don\'t reset lighting",
		"Reset lighting"
	};
	STRING_LIST(scene_reset_object_lighting_enum, scene_reset_object_lighting_enum_strings, _countof(scene_reset_object_lighting_enum_strings));

	STRINGS(cinematic_transition_looping_sound_alternate_flags)
	{
		"alternate"
	};
	STRING_LIST(cinematic_transition_looping_sound_alternate_flags, cinematic_transition_looping_sound_alternate_flags_strings, _countof(cinematic_transition_looping_sound_alternate_flags_strings));

	STRINGS(cinematic_transition_looping_sound_layer_flags)
	{
		"none!",
		"layer 1",
		"layer 2",
		"layer 3",
		"layer 4"
	};
	STRING_LIST(cinematic_transition_looping_sound_layer_flags, cinematic_transition_looping_sound_layer_flags_strings, _countof(cinematic_transition_looping_sound_layer_flags_strings));

	STRINGS(cinematic_flags)
	{
		"Outro",
		"Extra Memory Bink",
		"Opaque Bink",
		"Don\'t Stretch Bink",
		"Don\'t Force Hologram Render"
	};
	STRING_LIST(cinematic_flags, cinematic_flags_strings, _countof(cinematic_flags_strings));

	STRINGS(scenario_cinematics_flags)
	{
		"debug only"
	};
	STRING_LIST(scenario_cinematics_flags, scenario_cinematics_flags_strings, _countof(scenario_cinematics_flags_strings));

} // namespace macaque

} // namespace blofeld

