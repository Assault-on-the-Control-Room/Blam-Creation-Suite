#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP(cinematic, CINEMATIC_TAG)
	{
		{ _field_custom, "custom playback" },
		{ _field_struct, "cinematic playback!", &cinematic_playback_data_block_struct_definition },
		{ _field_struct, "scenario and zone set", &scenario_and_zone_set_struct_struct_definition },
		{ _field_string_id, "name^" },
		{ _field_enum, "channel type", &cinematic_channel_type_enum },
		{ _field_pad, "PADDING", 2 },
		{ _field_long_flags, "flags", &cinematic_flags },
		{ _field_real, "easing in time#seconds" },
		{ _field_real, "easing out time#seconds" },
		{ _field_tag_reference, "transition settings", &cinematic_transition_reference },

		{ _field_version_less_or_equal, _engine_type_haloreach, 1 },
		{ _field_pad, "PADDING@", 32 },

		{ _field_tag_reference, "bink movie", &bink_reference },

		{ _field_version_greater, _engine_type_haloreach, 1 },
		{ _field_string, "bink movie on disc" },

		{ _field_custom, "Header" },
		{ _field_struct, "header", &cinematic_custom_script_block_struct_definition },
		{ _field_custom },
		{ _field_block, "scenes", &cinematic_scene_reference_block_block },
		{ _field_custom, "Footer" },
		{ _field_struct, "footer", &cinematic_custom_script_block_struct_definition },
		{ _field_custom },
		{ _field_custom, "If The Player Skips" },
		{ _field_struct, "early exit", &cinematic_custom_script_block_struct_definition },
		{ _field_custom },
		{ _field_terminator }
	};

	TAG_GROUP_FROM_BLOCK(cinematic_scene, CINEMATIC_SCENE_TAG, cinematic_scene_block_block );

	TAG_GROUP_FROM_BLOCK(cinematic_scene_data, CINEMATIC_SCENE_DATA_TAG, cinematic_scene_data_block_block );

	TAG_GROUP(cinematic_transition, CINEMATIC_TRANSITION_TAG)
	{
		{ _field_custom, "fade out from game" },
		{ _field_struct, "fade out from game struct", &cinematic_transition_element_block_struct_definition },
		{ _field_custom },
		{ _field_custom, "fade in to cinematic" },
		{ _field_struct, "fade in to cinematic struct", &cinematic_transition_element_block_struct_definition },
		{ _field_custom },
		{ _field_custom, "fade out from cinematic" },
		{ _field_struct, "fade out from cinematic struct", &cinematic_transition_element_block_struct_definition },
		{ _field_custom },
		{ _field_custom, "fade post core load" },
		{ _field_struct, "fade post core load struct", &cinematic_transition_element_block_struct_definition },
		{ _field_custom },
		{ _field_custom, "fade in to game" },
		{ _field_struct, "fade in to game struct", &cinematic_transition_element_block_struct_definition },
		{ _field_custom },
		{ _field_terminator }
	};

	TAG_BLOCK(cinematic_shot_playback_data_block, MAX_CINEMATIC_SCENE_COUNT)
	{
		{ _field_array, "shot flags!", &g_cinematicShotFlagArray_array },

		{ _field_terminator }
	};

	TAG_BLOCK(cinematic_scene_reference_block, MAX_CINEMATIC_SCENE_COUNT)
	{
		{ _field_tag_reference, "scene", &cinematic_scene_reference },

		{ _field_version_greater, _engine_type_haloreach, 1 },
		{ _field_tag_reference, "data", &cinematic_scene_data_reference },

		{ _field_terminator }
	};

	TAG_BLOCK(scene_object_attachment_block, 10000)
	{
		{ _field_byte_flags, "flags", &scene_object_attachment_flags },
		{ _field_pad, "VKJSLKHF", 3 },
		{ _field_custom },
		{ _field_string_id, "object marker name" },
		{ _field_string_id, "attachment object name^" },
		{ _field_custom },
		{ _field_string_id, "attachment marker name" },
		{ _field_tag_reference, "attachment type", &scene_object_attachment_block_attachment_type_reference },
		{ _field_terminator }
	};

	TAG_BLOCK(cinematic_scene_object_block, 10000)
	{
		{ _field_string_id, "name*^" },

		{ _field_version_less_or_equal, _engine_type_haloreach, 1 }, // from H4 cisd tag
		{ _field_string_id, "identifier*" },

		{ _field_string_id, "variant name" },

		{ _field_version_less_or_equal, _engine_type_haloreach, 2 }, // from H4 cisd tag
		{ _field_tag_reference, "model animation graph*", &global_animation_graph_reference },
		{ _field_tag_reference, "object type*", &scene_object_attachment_block_attachment_type_reference },

		{ _field_long_flags, "flags", &scene_object_flags },

		{ _field_version_less_or_equal, _engine_type_haloreach, 2 }, // from H4 cisd tag
		{ _field_custom, "shots active flags*" },
		{ _field_array, "shots active flags*", &g_cinematicShotFlagArray_array },

		{ _field_version_greater, _engine_type_haloreach, 4 },    
		{ _field_custom, "lightmap shadow flags" },
		{ _field_array, "lightmap shadow flags", &g_cinematicShotFlagArray_array },
		{ _field_custom, "high res flags" },
		{ _field_array, "high res flags", &g_cinematicShotFlagArray_array },

		{ _field_long_flags, "override creation flags", &cinematic_coop_type_flags },
		{ _field_explanation, "Custom override creation condition", "Used in combination with the override creation flags above" },
		{ _field_struct, "custom don\'t create condition", &cinematic_custom_script_block_struct_definition },
		{ _field_block, "attachments", &scene_object_attachment_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(cinematic_shot_lighting_block, 10000)
	{
		{ _field_long_flags, "flags", &cinematic_shot_lighting_flags_definition },
		{ _field_tag_reference, "lighting", &global_new_cinematic_lighting_reference },
		{ _field_long_block_index, "subject^" },
		{ _field_custom },
		{ _field_string_id, "marker" },
		{ _field_terminator }
	};

	TAG_BLOCK(cinematic_shot_clip_subject_block, k_maximum_scene_shot_clip_subject_count)
	{
		{ _field_long_block_index, "index" },
		{ _field_terminator }
	};

	TAG_BLOCK(cinematic_shot_clip_block, k_maximum_scene_shot_clip_plane_count)
	{
		{ _field_real_point_3d, "plane center" },
		{ _field_real_point_3d, "plane direction" },
		{ _field_custom, "frame start" },
		{ _field_long_integer, "frame start" },
		{ _field_custom, "frame end" },
		{ _field_long_integer, "frame end" },
		{ _field_block, "subject objects", &cinematic_shot_clip_subject_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(cinematic_shot_music_block, 10000)
	{
		{ _field_long_flags, "flags", &music_flags_enum },
		{ _field_tag_reference, "music/foley", &global_sound_and_looping_sound_reference },
		{ _field_custom, "frame" },
		{ _field_long_integer, "frame" },
		{ _field_terminator }
	};

	TAG_BLOCK(cinematic_shot_object_function_keyframe_block, 10000)
	{
		{ _field_long_flags, "flags", &cinematic_shot_object_function_flags },
		{ _field_custom, "frame" },
		{ _field_long_integer, "frame" },
		{ _field_real, "value" },
		{ _field_real, "interpolation time:ticks" },
		{ _field_terminator }
	};

	TAG_BLOCK(cinematic_shot_object_function_block, 10000)
	{
		{ _field_long_block_index, "object" },
		{ _field_string_id, "function name" },
		{ _field_block, "keyframes", &cinematic_shot_object_function_keyframe_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(cinematic_shot_screen_effect_block, 10000)
	{
		{ _field_tag_reference, "screen effect", &global_area_screen_effect_reference },
		{ _field_custom, "frame" },
		{ _field_long_integer, "frame" },
		{ _field_custom, "stop frame" },
		{ _field_long_integer, "stop frame" },

		{ _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_byte_flags, "flags", &cinematicShotScreenEffectFlags },
		{ _field_pad, "BLAHWWW", 3 },

		{ _field_terminator }
	};

	TAG_BLOCK(cinematic_shot_user_input_constraints_block, 10000)
	{
		{ _field_custom, "frame" },
		{ _field_long_integer, "frame" },
		{ _field_long_integer, "ticks" },
		{ _field_rectangle_2d, "maximum look angles" },
		{ _field_real, "frictional force" },
		{ _field_terminator }
	};

	TAG_BLOCK(cinematicShotTextureMovieBlock, 10000)
	{
		{ _field_long_flags, "flags", &textureMovieFlags },
		{ _field_custom, "frame" },
		{ _field_long_integer, "frame" },
		{ _field_tag_reference, "bink movie", &bink_reference },
		{ _field_terminator }
	};

	TAG_BLOCK(cinematic_shot_block, MAX_CINEMATIC_SHOT_COUNT)
	{
		{ _field_custom, "loop now" },
		{ _field_custom, "Header" },
		{ _field_struct, "header", &cinematic_custom_script_block_struct_definition },
		{ _field_long_flags, "flags", &shot_flags_definition },
		{ _field_custom, "environment darken:0 - 1#this works best with auto-exposure off" },
		{ _field_real, "environment darken:0 - 1#this works best with auto-exposure off" },
		{ _field_custom, "forced exposure:stops#will disable auto-exposure" },
		{ _field_real, "forced exposure:stops#will disable auto-exposure" },
		{ _field_custom },
		{ _field_custom, "Settings" },
		{ _field_long_flags, "settings flags", &sceneShotSettingsFlags },

		{ _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_real, "Lightmap Direct Scalar" },
		{ _field_real, "Lightmap Indirect Scalar" },

		{ _field_real, "Sun Scalar" },

		{ _field_version_greater, _engine_type_haloreach, 3 },
		{ _field_tag_reference, "Atmosphere Fog", &global_atmosphere_definition_reference },
		{ _field_tag_reference, "Camera Effects", &global_camera_fx_settings_reference },
		{ _field_tag_reference, "Cubemap", &global_bitmap_reference },

		{ _field_custom },
		{ _field_block, "lighting", &cinematic_shot_lighting_block_block },
		{ _field_block, "clip", &cinematic_shot_clip_block_block },

		{ _field_version_less_or_equal, _engine_type_haloreach, 1 },// from H4 cisd
		{ _field_block, "dialogue", &cinematic_shot_dialogue_block_block },

		{ _field_block, "music", &cinematic_shot_music_block_block },

		{ _field_version_less_or_equal, _engine_type_haloreach, 1 },// from H4 cisd
		{ _field_block, "effects", &cinematic_shot_effect_block_block },

		{ _field_block, "object functions", &cinematic_shot_object_function_block_block },
		{ _field_block, "screen effects", &cinematic_shot_screen_effect_block_block },

		{ _field_version_less_or_equal, _engine_type_haloreach, 1 },// from H4 cisd
		{ _field_block, "custom script", &cinematic_shot_custom_script_block_block },

		{ _field_block, "user input constraints", &cinematic_shot_user_input_constraints_block_block },

		{ _field_version_greater, _engine_type_haloreach, 1 },
		{ _field_block, "texture movies", &cinematicShotTextureMovieBlock_block },

		{ _field_custom, "Footer" },
		{ _field_struct, "footer", &cinematic_custom_script_block_struct_definition },

		{ _field_version_less_or_equal, _engine_type_haloreach, 4 },// from H4 cisd
		{ _field_long_integer, "frame count*" },
		{ _field_block, "frame data*", &cinematic_shot_frame_block_block },
		{ _field_block, "dynamic frame data*!", &cinematic_shot_frame_dynamic_block_block },
		{ _field_block, "constant frame data*!", &cinematic_shot_frame_constant_block_block },

		{ _field_custom },
		{ _field_terminator }
	};

	TAG_BLOCK(cinematicStructureLightingBlock, 32)
	{
		{ _field_tag_reference, "structure lighting info^", &structure_lighting_bsp_reference },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(cinematic_scene_block, 1, cinematic_scene_struct_definition_struct_definition );

	TAG_BLOCK_FROM_STRUCT(cinematicSceneDataObjectBlock, 10000, cinematicSceneDataObjectBlock_struct_struct_definition );

	TAG_BLOCK(cinematic_shot_dialogue_block, 10000)
	{
		{ _field_tag_reference, "dialogue*", &global_sound_reference },
		{ _field_tag_reference, "female dialogue*", &global_sound_reference },
		{ _field_custom, "frame*" },
		{ _field_long_integer, "frame*" },
		{ _field_real, "scale*" },
		{ _field_string_id, "lipsync actor*" },
		{ _field_string_id, "default sound effect" },
		{ _field_string_id, "subtitle" },
		{ _field_string_id, "female subtitle" },
		{ _field_string_id, "character" },
		{ _field_terminator }
	};

	TAG_BLOCK(cinematic_shot_effect_block, 10000)
	{
		{ _field_byte_flags, "flags", &cinematic_shot_effect_flags },
		{ _field_char_enum, "state", &sceneShotEffectState },
		{ _field_pad, "CMVOIRLKSD", 2 },
		{ _field_tag_reference, "effect", &global_effect_reference },

		{ _field_version_greater, _engine_type_haloreach, 1 },
		{ _field_real, "size scale" },

		{ _field_custom, "frame" },
		{ _field_long_integer, "frame" },
		{ _field_custom },
		{ _field_string_id, "marker name" },
		{ _field_long_block_index, "marker parent" },
		{ _field_string_id, "function a" },
		{ _field_string_id, "function b" },

		{ _field_version_greater, _engine_type_haloreach, 2 },     
		{ _field_long_integer, "node id!" },
		{ _field_long_integer, "sequence id!" },
		{ _field_terminator }
	};

	TAG_BLOCK(cinematic_shot_custom_script_block, 10000)
	{
		{ _field_byte_flags, "flags!", &cinematic_shot_custom_script_flags },
		{ _field_pad, "CMVOIRLKSD", 3 },
		{ _field_custom, "frame" },
		{ _field_long_integer, "frame" },
		{ _field_struct, "script", &cinematic_custom_script_block_struct_definition },
		{ _field_long_integer, "node id!" },
		{ _field_long_integer, "sequence id!" },
		{ _field_terminator }
	};

	TAG_BLOCK(cinematic_shot_frame_block, 10000)
	{
		{ _field_struct, "camera frame", &camera_frame_struct_struct_definition },
		{ _field_terminator }
	};

	TAG_BLOCK(cinematic_shot_frame_dynamic_block, 10000)
	{
		{ _field_struct, "dynamic camera frame", &camera_frame_dynamic_struct_struct_definition },
		{ _field_terminator }
	};

	TAG_BLOCK(cinematic_shot_frame_constant_block, 10000)
	{
		{ _field_long_integer, "frame index" },
		{ _field_struct, "constant camera frame", &camera_frame_constant_struct_struct_definition },
		{ _field_terminator }
	};

	TAG_BLOCK(cinematicDataShotBlock, MAX_CINEMATIC_SHOT_COUNT)
	{
		{ _field_block, "dialogue", &cinematic_shot_dialogue_block_block },
		{ _field_block, "effects", &cinematic_shot_effect_block_block },
		{ _field_block, "custom script", &cinematic_shot_custom_script_block_block },
		{ _field_long_integer, "frame count*" },
		{ _field_block, "frame data*", &cinematic_shot_frame_block_block },
		{ _field_block, "dynamic frame data*!", &cinematic_shot_frame_dynamic_block_block },
		{ _field_block, "constant frame data*!", &cinematic_shot_frame_constant_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(cinematic_extra_camera_frame_block, 10000)
	{
		{ _field_long_flags, "flags", &cinematic_extra_camera_frame_flags },
		{ _field_struct, "frame data", &camera_frame_struct_struct_definition },
		{ _field_terminator }
	};

	TAG_BLOCK(cinematic_extra_camera_shot_block, 10000)
	{
		{ _field_block, "frame data", &cinematic_extra_camera_frame_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(cinematic_shot_extra_camera_block, 10000)
	{
		{ _field_string_id, "name" },
		{ _field_string_id, "type" },
		{ _field_block, "shots", &cinematic_extra_camera_shot_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(cinematic_scene_data_block, 1, cinematic_scene_data_struct_definition_struct_definition );

	TAG_BLOCK(cinematic_transition_global_gain_block, 1)
	{
		{ _field_real, "gain:dB^" },
		{ _field_long_integer, "time:hs_ticks" },
		{ _field_terminator }
	};

	TAG_BLOCK(cinematic_transition_sound_class_gain_block, 8)
	{
		{ _field_char_enum, "class^", &sound_class_enum },
		{ _field_pad, "pad", 3 },
		{ _field_real, "gain:dB" },
		{ _field_long_integer, "time:hs_ticks" },
		{ _field_terminator }
	};

	TAG_BLOCK(cinematic_transition_sound_reference_block, 4)
	{
		{ _field_tag_reference, "sound^", &global_sound_and_looping_sound_reference },
		{ _field_terminator }
	};

	TAG_BLOCK(cinematic_transition_looping_sound_reference_block, 4)
	{
		{ _field_tag_reference, "looping sound^", &global_looping_sound_reference },
		{ _field_terminator }
	};

	TAG_BLOCK(cinematic_transition_looping_sound_state_block, 4)
	{
		{ _field_tag_reference, "looping sound^", &global_looping_sound_reference },
		{ _field_real, "scale" },
		{ _field_word_flags, "alternate", &cinematic_transition_looping_sound_alternate_flags },
		{ _field_word_flags, "layers", &cinematic_transition_looping_sound_layer_flags },
		{ _field_terminator }
	};

	TAG_BLOCK(cinematic_characters_block, 16)
	{
		{ _field_string_id, "character name^" },
		{ _field_real_rgb_color, "subtitle color" },
		{ _field_real_rgb_color, "shadow color" },
		{ _field_terminator }
	};

	TAG_BLOCK(cinematics_globals_block, 1)
	{
		{ _field_tag_reference, "cinematic anchor reference", &scenery_reference },
		{ _field_real, "cinematic film aperture" },
		{ _field_real, "cinematic skip ui up time" },
		{ _field_real_fraction_bounds, "subtitle rect width#percentage towards the center - 0=default, 0.5=center of the screen" },
		{ _field_real_fraction_bounds, "subtitle rect height#0=default, 0.5=center of the screen" },
		{ _field_real_rgb_color, "default subtitle color" },
		{ _field_real_rgb_color, "default subtitle shadow color" },
		{ _field_block, "cinematic characters", &cinematic_characters_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(scenario_cutscene_title_block, k_maximum_scenario_cutscene_titles, scenario_cutscene_title_struct_struct_definition );

	TAG_BLOCK(scenario_cinematics_block, MAXIMUM_SCENARIO_CINEMATICS)
	{
		{ _field_byte_flags, "flags", &scenario_cinematics_flags },
		{ _field_pad, "SDJLKANF", 3 },
		{ _field_tag_reference, "name^", &cinematic_reference },
		{ _field_terminator }
	};

	TAG_ARRAY(g_cinematicShotFlagArray, c_cinematic_shot_flags::k_flag_chunk_count)
	{
		{ _field_dword_integer, "shot flag data" },
		{ _field_terminator }
	};

	TAG_STRUCT(cinematic_playback_data_block)
	{
		{ _field_long_block_flags, "scenes!" },
		{ _field_long_block_flags, "scenes expanded!" },
		{ _field_block, "shots!", &cinematic_shot_playback_data_block_block },

		{ _field_version_greater, _engine_type_haloreach, 1 },
		{ _field_long_integer, "bsp zone flags!" },

		{ _field_terminator }
	};

	TAG_STRUCT(scenario_and_zone_set_struct)
	{

		{ _field_version_greater, _engine_type_haloreach, 1 },
		{ _field_custom, "custom ui" },

		{ _field_tag_reference, "scenario!", &scenario_reference },
		{ _field_long_integer, "zone set!" },
		{ _field_terminator }
	};

	TAG_STRUCT(cinematic_custom_script_block)
	{
		{ _field_data, "script{ }" },
		{ _field_terminator }
	};

	TAG_STRUCT(cinematic_scene_struct_definition)
	{
		{ _field_custom, "loop now" },
		{ _field_string_id, "name^" },
		{ _field_string_id, "anchor" },
		{ _field_enum, "reset object lighting", &scene_reset_object_lighting_enum },
		{ _field_pad, "pad", 2 },

		{ _field_version_greater, _engine_type_haloreach, 1 },
		{ _field_tag_reference, "data*", &cinematic_scene_data_reference },

		{ _field_custom, "Header" },
		{ _field_struct, "header", &cinematic_custom_script_block_struct_definition },
		{ _field_custom },
		{ _field_block, "objects*", &cinematic_scene_object_block_block },
		{ _field_block, "shots", &cinematic_shot_block_block },

		{ _field_version_greater, _engine_type_haloreach, 1 },
		{ _field_block, "lights", &cinematicStructureLightingBlock_block },

		{ _field_version_less_or_equal, _engine_type_haloreach, 1 },
		{ _field_block, "extra camera frame data*", &cinematic_shot_extra_camera_block_block },

		{ _field_custom, "Footer" },
		{ _field_struct, "footer", &cinematic_custom_script_block_struct_definition },

		{ _field_version_less_or_equal, _engine_type_haloreach, 1 },
		{ _field_long_integer, "version*" },
		{ _field_custom },
		{ _field_terminator }
	};

	TAG_STRUCT(cinematic_scene_data_struct_definition)
	{
		{ _field_block, "objects*", &cinematicSceneDataObjectBlock_block },
		{ _field_block, "shots*", &cinematicDataShotBlock_block },
		{ _field_block, "extra camera frame data*", &cinematic_shot_extra_camera_block_block },
		{ _field_long_integer, "version*" },
		{ _field_terminator }
	};

	TAG_STRUCT(cinematicSceneDataObjectBlock_struct)
	{
		{ _field_string_id, "name*^" },
		{ _field_string_id, "identifier*" },
		{ _field_tag_reference, "model animation graph*", &global_animation_graph_reference },
		{ _field_tag_reference, "object type*", &scene_object_attachment_block_attachment_type_reference },
		{ _field_custom, "shots active flags*" },
		{ _field_array, "shots active flags*", &g_cinematicShotFlagArray_array },
		{ _field_terminator }
	};

	TAG_STRUCT(camera_frame_struct)
	{
		{ _field_struct, "dynamic data", &camera_frame_dynamic_struct_struct_definition },
		{ _field_struct, "constant data", &camera_frame_constant_struct_struct_definition },
		{ _field_terminator }
	};

	TAG_STRUCT(camera_frame_dynamic_struct)
	{
		{ _field_real_point_3d, "camera position*" },
		{ _field_real_vector_3d, "camera forward*" },
		{ _field_real_vector_3d, "camera up*" },
		{ _field_terminator }
	};

	TAG_STRUCT(camera_frame_constant_struct)
	{
		{ _field_real, "focal length*" },
		{ _field_long_integer, "depth of field*" },
		{ _field_real, "near focal plane distance*" },
		{ _field_real, "far focal plane distance*" },
		{ _field_real, "near focal depth*" },

		{ _field_version_greater, _engine_type_haloreach, 1 },
		{ _field_real, "far focal depth*" },

		{ _field_real, "near blur amount*" },

		{ _field_version_greater, _engine_type_haloreach, 1 },
		{ _field_real, "far blur amount*" },

		{ _field_terminator }
	};

	TAG_STRUCT(cinematic_transition_element_block)
	{
		{ _field_struct, "global fade", &cinematic_transition_global_fade_block_struct_definition },
		{ _field_block, "sound global gain", &cinematic_transition_global_gain_block_block },
		{ _field_block, "sound class gains", &cinematic_transition_sound_class_gain_block_block },
		{ _field_block, "stop sounds", &cinematic_transition_sound_reference_block_block },
		{ _field_block, "start sounds", &cinematic_transition_sound_reference_block_block },
		{ _field_block, "resume looping sounds", &cinematic_transition_looping_sound_reference_block_block },
		{ _field_block, "looping sound states", &cinematic_transition_looping_sound_state_block_block },
		{ _field_long_integer, "sleep time:hs_ticks" },
		{ _field_terminator }
	};

	TAG_STRUCT(cinematic_transition_global_fade_block)
	{
		{ _field_real_rgb_color, "fade_color^" },
		{ _field_long_integer, "fade time:hs_ticks" },
		{ _field_terminator }
	};

	TAG_STRUCT(scenario_cutscene_title_struct)
	{
		{ _field_string_id, "name^" },
		{ _field_real_fraction_bounds, "text bounds X" },
		{ _field_real_fraction_bounds, "text bounds Y" },
		{ _field_enum, "justification", &text_justification_enum_definition },
		{ _field_enum, "vertical justification", &text_vertical_justification_enum_definition },
		{ _field_enum, "font", &global_font_id_enum_definition },
		{ _field_pad, "padding", 2 },
		{ _field_rgb_color, "text color" },
		{ _field_rgb_color, "shadow color" },
		{ _field_real, "fade in time [seconds]" },
		{ _field_real, "up time [seconds]" },
		{ _field_real, "fade out time [seconds]" },

		{ _field_version_greater, _engine_type_haloreach },
		{ _field_real, "letter print time:seconds" },

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

} // namespace blofeld
