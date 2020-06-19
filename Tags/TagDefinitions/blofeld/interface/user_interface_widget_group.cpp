#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(InfinityUIImages, INFINITYUIIMAGES_TAG, InfinityUIImages_block_block );

	TAG_GROUP_FROM_BLOCK(pgcr_enemy_to_category_mapping_definition, PGCR_ENEMY_TO_CATEGORY_MAPPING_DEFINITION_TAG, pgcr_enemy_to_category_mapping_definition_block_block );

	TAG_GROUP_FROM_BLOCK(pgcr_damage_type_image_mapping_definition, PGCR_DAMAGE_TYPE_IMAGE_MAPPING_DEFINITION_TAG, pgcr_damage_type_image_mapping_definition_block_block );

	TAG_GROUP_FROM_BLOCK(portrait_poses_definition, PORTRAIT_POSES_DEFINITION_TAG, portrait_poses_definition_block_block );

	TAG_GROUP_FROM_BLOCK(user_interface_sounds_definition, USER_INTERFACE_SOUNDS_DEFINITION_TAG, user_interface_sounds_definition_block_block );

	TAG_GROUP_FROM_BLOCK(user_interface_globals_definition, USER_INTERFACE_GLOBALS_DEFINITION_TAG, user_interface_globals_definition_block_block );

	TAG_GROUP_FROM_BLOCK(user_interface_shared_globals_definition, USER_INTERFACE_SHARED_GLOBALS_DEFINITION_TAG, user_interface_shared_globals_definition_block_block );

	TAG_BLOCK(InfinityMissionImagesDefinition, k_infinityMaximumMissionsPerSeason)
	{
		{ _field_tag_reference, "card image^", &global_bitmap_reference },
		{ _field_tag_reference, "detail image", &global_bitmap_reference },
		{ _field_tag_reference, "lobby image", &global_bitmap_reference },
		{ _field_tag_reference, "match image", &global_bitmap_reference },
		{ _field_terminator }
	};

	TAG_BLOCK(InfinityMissionSeasonImagesDefinition, k_infinityMaximumSeasonCount)
	{
		{ _field_explanation, "Season Images", "This block should contain a season\'s worth of Infinity mission images" },
		{ _field_long_integer, "season number^" },
		{ _field_tag_reference, "epilogue image#displayed where the missions would be, when the epilogue is selected", &global_bitmap_reference },
		{ _field_block, "season images", &InfinityMissionImagesDefinition_block },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(InfinityUIImages_block, 1, InfinityUIImages_struct_definition_struct_definition );

	TAG_BLOCK(pgcr_player_to_category_entry_block, k_pgcr_maximum_number_of_player_entries_per_category)
	{
		{ _field_char_enum, "player type", &pgcr_player_type_enum },
		{ _field_pad, "pad0", 3 },
		{ _field_terminator }
	};

	TAG_BLOCK(pgcr_enemy_to_category_entry_block, k_pgcr_maximum_number_of_ai_entries_per_category)
	{
		{ _field_char_enum, "character type", &campaign_metagame_bucket_type_with_none_enum },
		{ _field_char_enum, "character class", &campaign_metagame_bucket_class_with_none_enum },
		{ _field_pad, "pad0", 2 },
		{ _field_terminator }
	};

	TAG_BLOCK(pgcr_enemy_to_category_list_block, k_pgcr_maximum_number_of_categories_per_bucket)
	{
		{ _field_string_id, "category display name^" },
		{ _field_short_integer, "sprite index" },
		{ _field_byte_flags, "flags", &pgcr_enemy_to_category_entry_flags },
		{ _field_pad, "pad0", 1 },
		{ _field_block, "player types", &pgcr_player_to_category_entry_block_block },
		{ _field_block, "enemy types", &pgcr_enemy_to_category_entry_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(pgcr_enemy_to_category_mapping_definition_block, 1, pgcr_enemy_to_category_mapping_definition_struct_definition_struct_definition );

	TAG_BLOCK(pgcr_damage_type_image_block, k_damage_reporting_type_count)
	{
		{ _field_long_enum, "damage type^", &global_damage_reporting_enum_definition },
		{ _field_string_id, "display name" },
		{ _field_tag_reference, "sprite", &global_bitmap_reference },
		{ _field_short_integer, "sprite index" },
		{ _field_pad, "pad0", 2 },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(pgcr_damage_type_image_mapping_definition_block, 1, pgcr_damage_type_image_mapping_definition_struct_definition_struct_definition );

	TAG_BLOCK(gui_portrait_pose_block, k_maxPortraitPoses)
	{
		{ _field_string_id, "pose name^" },
		{ _field_string_id, "animation name" },
		{ _field_string_id, "camera view name" },
		{ _field_long_integer, "scenario profile index" },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(portrait_poses_definition_block, 1, portrait_poses_definition_struct_definition_struct_definition );

	TAG_BLOCK_FROM_STRUCT(user_interface_sounds_definition_block, 1, user_interface_sounds_definition_struct_definition_struct_definition );

	TAG_BLOCK(cui_component_screen_reference_block_definition, k_maximum_number_of_screen_widgets)
	{
		
		{ _field_version_greater, _engine_type_halo3, 2 },
		{ _field_string_id, "name^#for use in code" },
		{ _field_tag_reference, "cui screen tag", &cui_screen_reference },

		{ _field_terminator }
	};

	TAG_BLOCK(cui_overlay_camera_block_definition, k_cui_max_overlay_count)
	{
		{ _field_string_id, "resolution name" },
		{ _field_char_enum, "pivot corner", &cui_camera_pivot_corner_enum_definition },
		{ _field_pad, "pad0", 3 },
		{ _field_real, "Z near#distance to near clipping plane" },
		{ _field_real, "Z far#distance to far clipping plane" },
		{ _field_real, "X angle degrees#camera angle around the X axis" },
		{ _field_real, "Y angle degrees#camera angle around the Y axis" },
		{ _field_terminator }
	};

	TAG_BLOCK(cui_player_model_camera_settings_definition, s_cui_player_model_camera_settings_definition::k_maximum_count)
	{
		{ _field_explanation, "Camera Settings", "These are model-viewing camera parameters that you can control\n* FOV is the field of view used by the texture camera\n  if left 0, a suitable default FOV is used\n* Initial Radial Offset is the initial radial distance of the camera from the target model\n* Final Radial Offset is the final radial distance of the camera from the target model\n* Camera Radial Step Size is the incremental change in input to the radial transition function per tick\n* Initial Vertical Offset is the initial vertical distance of the camera from the target\'s center\n* Final Vertical Offset is the final vertical distance of the camera from the target\'s center\n* Camera Vertical Step Size is the incremental change in input to the vertical transition function per tick\n* Camera Rotational Step Size is the incremental change in camera rotation per game tick\n* The Transition Functions are used to control the camera zoom with controller input\n  if left empty, a linear interpolation is used for camera zoom" },
		{ _field_string_id, "name" },
		{ _field_real_point_3d, "model world position:wu#arbitrary location in the world to place the model" },
		{ _field_real_point_3d, "minimum world position" },
		{ _field_real_point_3d, "maximum world position" },
		{ _field_string_id, "viewed model marker name" },
		{ _field_real_point_3d, "minimum camera offset:wu" },
		{ _field_real_point_3d, "minimum camera focal offset:wu" },
		{ _field_real_point_3d, "maximum camera offset:wu" },
		{ _field_real_point_3d, "maximum camera focal offset:wu" },
		{ _field_real, "initial zoom:[0,1]" },
		{ _field_real, "fov:degrees" },
		{ _field_terminator }
	};

	TAG_BLOCK(cui_player_model_controller_settings_definition, s_cui_player_model_control_settings_definition::k_maximum_count)
	{
		{ _field_string_id, "name" },
		{ _field_real, "zoom speed:wu per tick" },
		{ _field_custom },
		{ _field_struct, "zoom transition function", &mapping_function_struct_definition },
		{ _field_real_euler_angles_2d, "initial rotation:degrees" },
		{ _field_real_euler_angles_2d, "minimum rotation:degrees" },
		{ _field_real_euler_angles_2d, "maximum rotation:degrees" },
		{ _field_real, "rotation speed:degrees per tick" },
		{ _field_terminator }
	};

	TAG_BLOCK(cui_player_model_transition_settings_definition, s_cui_player_model_transition_settings_definition::k_maximum_count)
	{
		{ _field_custom },
		{ _field_struct, "camera transition function", &mapping_function_struct_definition },
		{ _field_terminator }
	};

	TAG_BLOCK(cui_active_roster_settings_block, s_cui_active_roster_settings_definition::k_max_count)
	{
		{ _field_custom },
		{ _field_struct, "analog scroll function", &mapping_function_struct_definition },
		{ _field_terminator }
	};

	TAG_BLOCK(campaign_state_screen_script_block_definition, s_campaign_state_screen_script::k_max_count)
	{
		{ _field_long_integer, "map ID" },
		{ _field_string_id, "screen script name" },
		{ _field_tag_reference, "music override", &global_looping_sound_reference },
		{ _field_terminator }
	};

	TAG_BLOCK(UserInterfaceGameScreenSequenceStepDefinition, UserInterfaceGameScreenSequenceStep::k_maxCount)
	{
		{ _field_byte_flags, "flags", &UIGameStartSequenceFlagsDefinition },
		{ _field_pad, "UMPKIU", 3 },
		{ _field_tag_reference, "screen^", &cui_screen_reference },
		{ _field_short_integer, "startTime:ticks" },
		{ _field_short_integer, "endTime:ticks" },
		{ _field_terminator }
	};

	TAG_BLOCK(SwapTagReferenceDefinition, SwapTagReferences::k_maxCount)
	{
		{ _field_tag_reference, "original tag^", &SwapTagReferenceDefinition_original_tag_reference },
		{ _field_tag_reference, "replacement tag", &SwapTagReferenceDefinition_original_tag_reference },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(user_interface_globals_definition_block, 1, user_interface_globals_definition_struct_definition_struct_definition );

	TAG_BLOCK(color_presets_block, s_color_preset::k_maximum_color_presets)
	{
		{ _field_string_id, "name^" },
		{ _field_real_argb_color, "color" },
		{ _field_terminator }
	};

	TAG_BLOCK(color_list_block, ((k_player_color_index_count)>(k_multiplayer_team_game_team_count+1)?(k_player_color_index_count):(k_multiplayer_team_game_team_count+1)))
	{
		{ _field_real_argb_color, "color" },
		{ _field_terminator }
	};

	TAG_BLOCK(tint_colors_block, 1)
	{
		{ _field_block, "text player", &color_list_block_block },
		{ _field_block, "text team", &color_list_block_block },
		{ _field_block, "bitmap player", &color_list_block_block },
		{ _field_block, "bitmap team", &color_list_block_block },
		{ _field_custom, "Affiliation" },
		{ _field_real_argb_color, "bitmap friend" },
		{ _field_real_argb_color, "bitmap enemy" },
		{ _field_real_argb_color, "bitmap neutral" },
		{ _field_custom },
		{ _field_custom, "Flood Team Colors" },
		{ _field_real_argb_color, "bitmap flood" },
		{ _field_real_argb_color, "bitmap spartans" },
		{ _field_custom },
		{ _field_terminator }
	};

	TAG_BLOCK(gui_alert_description_block, s_gui_alert_description::k_maximum_gui_error_types_count)
	{
		{ _field_string_id, "error name^" },
		{ _field_byte_flags, "flags", &gui_alert_flags },
		{ _field_char_enum, "error category", &gui_error_category_enum },
		{ _field_char_enum, "error icon", &gui_error_icon_enum },
		{ _field_pad, "pad0", 1 },
		{ _field_string_id, "title" },
		{ _field_string_id, "message" },
		{ _field_terminator }
	};

	TAG_BLOCK(gui_dialog_description_block, s_gui_dialog_description::k_maximum_gui_dialog_types_count)
	{
		{ _field_string_id, "dialog name^" },
		{ _field_word_flags, "flags", &gui_dialog_flags },
		{ _field_pad, "pad0", 2 },
		{ _field_string_id, "title" },
		{ _field_string_id, "message" },
		{ _field_string_id, "first_item" },
		{ _field_string_id, "second_item" },
		{ _field_string_id, "third_item" },
		{ _field_string_id, "fourth_item" },
		{ _field_string_id, "button key" },
		{ _field_enum, "default item", &gui_dialog_choice_enum },
		{ _field_enum, "b button action", &gui_dialog_b_button_action_enum },
		{ _field_terminator }
	};

	TAG_BLOCK(pgcr_incident_block, s_cui_pgcr_incident::k_maximum_count)
	{
		{ _field_string_id, "incident name^" },
		{ _field_long_integer, "maximum stat count*#number of times this can happen before the PGCR stops tracking them" },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(user_interface_shared_globals_definition_block, 1, user_interface_shared_globals_definition_struct_definition_struct_definition );

	TAG_STRUCT(InfinityUIImages_struct_definition)
	{
		{ _field_block, "seasons", &InfinityMissionSeasonImagesDefinition_block },
		{ _field_terminator }
	};

	TAG_STRUCT(pgcr_enemy_to_category_mapping_definition_struct_definition)
	{
		{ _field_block, "character categories", &pgcr_enemy_to_category_list_block_block },
		{ _field_block, "vehicle categories", &pgcr_enemy_to_category_list_block_block },
		{ _field_terminator }
	};

	TAG_STRUCT(pgcr_damage_type_image_mapping_definition_struct_definition)
	{
		{ _field_block, "damage type mapping", &pgcr_damage_type_image_block_block },
		{ _field_terminator }
	};

	TAG_STRUCT(portrait_poses_definition_struct_definition)
	{
		{ _field_block, "portrait poses", &gui_portrait_pose_block_block },
		{ _field_terminator }
	};

	TAG_STRUCT(user_interface_sounds_definition_struct_definition)
	{
		{ _field_custom, "Controller Input Events" },
		{ _field_tag_reference, "tab up", &global_sound_reference },
		{ _field_tag_reference, "tab left", &global_sound_reference },
		{ _field_tag_reference, "tab right", &global_sound_reference },
		{ _field_tag_reference, "tab down", &global_sound_reference },
		{ _field_tag_reference, "alt stick up", &global_sound_reference },
		{ _field_tag_reference, "alt stick left", &global_sound_reference },
		{ _field_tag_reference, "alt stick right", &global_sound_reference },
		{ _field_tag_reference, "alt stick down", &global_sound_reference },
		{ _field_tag_reference, "alt tab up", &global_sound_reference },
		{ _field_tag_reference, "alt tab left", &global_sound_reference },
		{ _field_tag_reference, "alt tab right", &global_sound_reference },
		{ _field_tag_reference, "alt tab down", &global_sound_reference },
		{ _field_tag_reference, "A button pressed", &global_sound_reference },
		{ _field_tag_reference, "B button pressed", &global_sound_reference },
		{ _field_tag_reference, "X button pressed", &global_sound_reference },
		{ _field_tag_reference, "Y button pressed", &global_sound_reference },
		{ _field_tag_reference, "left trigger pressed", &global_sound_reference },
		{ _field_tag_reference, "right trigger pressed", &global_sound_reference },
		{ _field_tag_reference, "D-pad up pressed", &global_sound_reference },
		{ _field_tag_reference, "D-pad left pressed", &global_sound_reference },
		{ _field_tag_reference, "D-pad right pressed", &global_sound_reference },
		{ _field_tag_reference, "D-pad down pressed", &global_sound_reference },
		{ _field_tag_reference, "start button pressed", &global_sound_reference },
		{ _field_tag_reference, "back button pressed", &global_sound_reference },
		{ _field_tag_reference, "left stick pressed", &global_sound_reference },
		{ _field_tag_reference, "right stick pressed", &global_sound_reference },
		{ _field_tag_reference, "left bumper pressed", &global_sound_reference },
		{ _field_tag_reference, "right bumper pressed", &global_sound_reference },
		{ _field_tag_reference, "left thumbstick pressed", &global_sound_reference },
		{ _field_tag_reference, "right thumbstick pressed", &global_sound_reference },
		{ _field_tag_reference, "left stick pressed left", &global_sound_reference },
		{ _field_tag_reference, "left stick pressed right", &global_sound_reference },
		{ _field_tag_reference, "left stick pressed up", &global_sound_reference },
		{ _field_tag_reference, "left stick pressed down", &global_sound_reference },
		{ _field_tag_reference, "right stick pressed left", &global_sound_reference },
		{ _field_tag_reference, "right stick pressed right", &global_sound_reference },
		{ _field_tag_reference, "right stick pressed up", &global_sound_reference },
		{ _field_tag_reference, "right stick pressed down", &global_sound_reference },
		{ _field_tag_reference, "A button released", &global_sound_reference },
		{ _field_tag_reference, "B button released", &global_sound_reference },
		{ _field_tag_reference, "X button released", &global_sound_reference },
		{ _field_tag_reference, "Y button released", &global_sound_reference },
		{ _field_tag_reference, "left trigger released", &global_sound_reference },
		{ _field_tag_reference, "right trigger released", &global_sound_reference },
		{ _field_tag_reference, "D-pad up released", &global_sound_reference },
		{ _field_tag_reference, "D-pad left released", &global_sound_reference },
		{ _field_tag_reference, "D-pad right released", &global_sound_reference },
		{ _field_tag_reference, "D-pad down released", &global_sound_reference },
		{ _field_tag_reference, "start button released", &global_sound_reference },
		{ _field_tag_reference, "back button released", &global_sound_reference },
		{ _field_tag_reference, "left stick released", &global_sound_reference },
		{ _field_tag_reference, "right stick released", &global_sound_reference },
		{ _field_tag_reference, "left bumper released", &global_sound_reference },
		{ _field_tag_reference, "right bumper released", &global_sound_reference },
		{ _field_tag_reference, "left thumbstick released", &global_sound_reference },
		{ _field_tag_reference, "right thumbstick released", &global_sound_reference },
		{ _field_tag_reference, "left stick released left", &global_sound_reference },
		{ _field_tag_reference, "left stick released right", &global_sound_reference },
		{ _field_tag_reference, "left stick released up", &global_sound_reference },
		{ _field_tag_reference, "left stick released down", &global_sound_reference },
		{ _field_tag_reference, "right stick released left", &global_sound_reference },
		{ _field_tag_reference, "right stick released right", &global_sound_reference },
		{ _field_tag_reference, "right stick released up", &global_sound_reference },
		{ _field_tag_reference, "right stick released down", &global_sound_reference },
		{ _field_custom },
		{ _field_custom, "General" },
		{ _field_tag_reference, "error", &global_sound_reference },
		{ _field_custom },
		{ _field_custom, "Screen" },
		{ _field_tag_reference, "screen transition in", &global_sound_reference },
		{ _field_tag_reference, "screen transition out", &global_sound_reference },
		{ _field_custom },
		{ _field_custom, "Timers" },
		{ _field_tag_reference, "game start countdown timer first tick", &global_sound_reference },
		{ _field_tag_reference, "game start countdown timer tick", &global_sound_reference },
		{ _field_tag_reference, "game start countdown timer final tick", &global_sound_reference },
		{ _field_tag_reference, "alternate countdown timer first tick", &global_sound_reference },
		{ _field_tag_reference, "alternate countdown timer tick", &global_sound_reference },
		{ _field_tag_reference, "alternate countdown timer final tick", &global_sound_reference },
		{ _field_custom },
		{ _field_custom, "Misc" },
		{ _field_tag_reference, "matchmaking reveal", &global_sound_reference },
		{ _field_custom },
		{ _field_custom, "Exit Experience" },
		{ _field_tag_reference, "game completion", &global_sound_reference },
		{ _field_tag_reference, "winning bonus", &global_sound_reference },
		{ _field_tag_reference, "hopper bonus", &global_sound_reference },
		{ _field_tag_reference, "boost bonus", &global_sound_reference },
		{ _field_tag_reference, "fasttrack bonus", &global_sound_reference },
		{ _field_tag_reference, "totals", &global_sound_reference },
		{ _field_tag_reference, "subrank up", &global_sound_reference },
		{ _field_tag_reference, "rank up", &global_sound_reference },
		{ _field_tag_reference, "completed", &global_sound_reference },
		{ _field_tag_reference, "counter loop", &global_looping_sound_reference },
		{ _field_tag_reference, "score bonus", &global_sound_reference },
		{ _field_tag_reference, "rewards", &global_sound_reference },
		{ _field_custom },
		{ _field_terminator }
	};

	TAG_STRUCT(user_interface_globals_definition_struct_definition)
	{
		
		{ _field_version_greater, _engine_type_haloreach },
		{ _field_long_flags, "flags", &UserInterfaceTagGlobalsFlagsDefinition },
		
		{ _field_explanation, "Shared Globals", "This is a reference to the ui shared globals tag" },
		{ _field_tag_reference, "shared globals", &g_user_interface_shared_globals_reference },
		{ _field_explanation, "Multiplayer Variant Settings Interface", "This blob defines the ui for setting multiplayer game variant parameters" },
		{ _field_tag_reference, "mp variant settings ui", &g_multiplayer_variant_settings_interface_reference },
		{ _field_explanation, "Game Hopper Localization Strings", "This is for the loc game hopper strings" },
		{ _field_tag_reference, "game hopper descriptions", &global_multilingual_unicode_string_list_reference },
		{ _field_explanation, "Screen Widgets", "These are the HaloX screen widgets" },
		{ _field_block, "cui screen widgets", &cui_component_screen_reference_block_definition_block },

		{ _field_version_greater_or_equal, _engine_type_haloreach, 5 },
		{ _field_block, "cui overlay cameras", &cui_overlay_camera_block_definition_block },
		{ _field_block, "player model camera settings", &cui_player_model_camera_settings_definition_block },
		{ _field_block, "player model input settings", &cui_player_model_controller_settings_definition_block },
		{ _field_block, "player model camera transition settings", &cui_player_model_transition_settings_definition_block },
		{ _field_tag_reference, "purchase globals", &cookie_purchase_globals_reference },
		
		{ _field_version_greater, _engine_type_haloreach },
		{ _field_tag_reference, "infinity mission images{infinity mission images ref}", &Tag::Reference<struct InfinityUIImages>::s_defaultDefinition },

		{ _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_block, "active roster settings", &cui_active_roster_settings_block_block },
		
		{ _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_explanation, "PGCR Categories Definitions", "This is a reference to the tag storing the categories we want to display in the PGCR" },
		{ _field_tag_reference, "pgcr categories definitions", &pgcr_enemy_to_category_mapping_definition_reference },

		{ _field_version_greater_or_equal, _engine_type_haloreach, 2 },
		{ _field_explanation, "PGCR Damage Types Definitions", "This is a reference to the tag storing details about damage types for display in the PGCR" },
		{ _field_tag_reference, "pgcr damage types definitions", &pgcr_damage_type_image_mapping_definition_reference },

		{ _field_version_greater_or_equal, _engine_type_haloreach, 2 },
		{ _field_explanation, "Campaign State Screen Scripts", "Contains a mapping of campaign map IDs and screen scripts used to implement lobby backgrounds that track campaign state. This block should only be non-empty for the main menu." },
		{ _field_block, "campaign state screen scripts", &campaign_state_screen_script_block_definition_block },

		{ _field_version_greater, _engine_type_haloreach, 9 },
		{ _field_real, "spawn-timer countdown rate:counts/sec" },
		{ _field_block, "game intro sequence", &UserInterfaceGameScreenSequenceStepDefinition_block },
		{ _field_block, "game round end sequence", &UserInterfaceGameScreenSequenceStepDefinition_block },
		{ _field_block, "game next round sequence", &UserInterfaceGameScreenSequenceStepDefinition_block },
		{ _field_block, "game end sequence", &UserInterfaceGameScreenSequenceStepDefinition_block },
		{ _field_block, "game end with killcam sequence", &UserInterfaceGameScreenSequenceStepDefinition_block },
		{ _field_tag_reference, "HUD globals#global settings for the HUD. Set this for ingame globals.", &Tag::Reference<struct UserInterfaceHUDGlobalsDefinitions>::s_defaultDefinition },
		{ _field_tag_reference, "portrait poses", &portrait_poses_definition_reference },
		{ _field_block, "swap tags", &SwapTagReferenceDefinition_block },
		
		{ _field_terminator }
	};

	TAG_STRUCT(user_interface_shared_globals_definition_struct_definition)
	{
		{ _field_explanation, "UI Rendering Globals", "miscellaneous rendering globals, more below..." },
		{ _field_short_integer, "inc. text update period:milliseconds" },
		{ _field_short_integer, "inc. text block character:ASCII code" },
		{ _field_real, "near clip plane distance:objects closer than this are not drawn" },
		{ _field_real, "projection plane distance:distance at which objects are rendered when z=0 (normal size)" },
		{ _field_real, "far clip plane distance:objects farther than this are not drawn" },
		{ _field_explanation, "Global Text Strings", "Global UI Text goes here" },
		{ _field_tag_reference, "unicode string list tag", &global_multilingual_unicode_string_list_reference },
		{ _field_tag_reference, "unicode damage reporting string list tag", &global_multilingual_unicode_string_list_reference },
		{ _field_tag_reference, "unicode fire team member name string list{unicode fire team member string list tag}", &global_multilingual_unicode_string_list_reference },
		{ _field_tag_reference, "unicode fire team member service tag string list", &global_multilingual_unicode_string_list_reference },
		{ _field_explanation, "Main menu music", "Looping sound that plays while the main menu is active" },
		{ _field_tag_reference, "main menu music", &global_looping_sound_reference },
		{ _field_tag_reference, "main menu alternate music", &global_looping_sound_reference },
		{ _field_long_integer, "music fade time:milliseconds" },
		{ _field_explanation, "Default Text and Shadow Colors", "These are the default values used for text glyphs and text shadows" },
		{ _field_real_argb_color, "text color" },
		{ _field_real_argb_color, "shadow color" },
		{ _field_explanation, "Color presets", "Colors are defined here and used in text widgets throughout the UI.  Specify a string_id here and the same one in a text widget.  If you don\'t specify one in a text widget, you\'ll use the first entry here." },
		{ _field_block, "color presets", &color_presets_block_block },
		{ _field_explanation, "Tint colors", "These colors are used for tinting widgets by team or player color." },
		{ _field_block, "tint colors", &tint_colors_block_block },
		{ _field_explanation, "Emblem counts", "This lets us define how many images are in the emblem image bitmaps without opening them." },
		{ _field_short_integer, "Primary emblem count" },
		{ _field_short_integer, "Secondary emblem count" },
		{ _field_explanation, "User interface sounds", "Default sound effects for various UI actions" },
		{ _field_tag_reference, "default sounds", &user_interface_sounds_definition_reference },
		{ _field_explanation, "HaloX Alerts", "Alerts are triggered by specific events that happen in the game.  The game can require that an error be resolved before the dialog can be dismissed.  Once the error is resolved (or if it doesn\'t require resolution,) the user can dismiss it." },
		{ _field_block, "alert descriptions", &gui_alert_description_block_block },
		{ _field_explanation, "HaloX Dialogs", "Dialogs are brought up by individual screens or UI systems to ask the user a question, typically of the Ok/Cancel sort such as: \'Are you sure you want to leave the game\?\'.\nNotes:\n- first item defaults to \'ok\', second item defaults to \'cancel.  third and fourth items don\'t display if they\'re not set\n- if \'b button action\' is set to \'button ignored\' then the b button doesn\'t do anything (such as cancelling)" },
		{ _field_block, "dialog descriptions", &gui_dialog_description_block_block },
		{ _field_explanation, "Content Aspect Ratio Scaling", "These define the scaling that will get applied to UI content and animations when running at the specified display modes" },
		{ _field_real_vector_2d, "16x9" },
		{ _field_real_vector_2d, "4x3" },
		{ _field_explanation, "Blur Constants", "These control the blur kernel used when blurring overlayed UI" },
		{ _field_real, "horizontal blur factor" },
		{ _field_real, "vertical blur factor" },
		{ _field_explanation, "Appearance Model Names", "These specify the name of a scenario-placed biped to be used for the Start Menu Appearance model\nIf you want to use a scenario-placed biped (non-AI), enter the biped name in the \'biped name\' field\nIf you want to use an AI-placed biped, enter the squad name string and starting position string_id" },
		{ _field_string_id, "mc biped name" },
		{ _field_string, "mc ai squad name" },
		{ _field_string_id, "mc ai start pos" },
		{ _field_string_id, "elite biped name" },
		{ _field_string, "elite ai squad name" },
		{ _field_string_id, "elite ai start pos" },
		
		{ _field_version_greater, _engine_type_haloreach, 3 },
		{ _field_explanation, "Player Portrait Model Names", "These specify the name of a scenario-placed biped to be used for the Player Portrait Appearance model\nEnter the scenario-placed biped (non-AI) name in the \'spartan biped name\' and \'elite biped name\' field" },
		{ _field_string_id, "spartan portrait biped name" },
		{ _field_string_id, "elite portrait biped name" },
		
		{ _field_explanation, "UI Navigation speed", "This controls tabbing around the UI.  The tab delay is how fast you move around normally. \nTab fast wait is how long the UI waits till using the tab fast delay instead of the tab delay." },
		{ _field_long_integer, "navigation tab delay msec" },
		{ _field_long_integer, "navigation tab fast wait msec" },
		{ _field_long_integer, "navigation tab fast delay msec" },
		{ _field_explanation, "Spinner tab speed", "This is an alternate control for tabbing speed in the spinner.\nThe input (x) is the time the stick has been held down.\nThe output (y) is the time between tab events." },
		{ _field_custom },
		{ _field_struct, "spinner tab speed function", &mapping_function_struct_definition },
		{ _field_long_integer, "max input time (x) on the graph (msec)" },
		{ _field_explanation, "Attract Mode Settings", "These control behavior of the attract mode movies" },
		{ _field_long_integer, "delay:seconds" },
		{ _field_block, "PGCR per player tracked incidents", &pgcr_incident_block_block },
		{ _field_terminator }
	};

	STRINGS(gui_alert_flags)
	{
		"allow auto dismissal",
		"show spinner"
	};
	STRING_LIST(gui_alert_flags, gui_alert_flags_strings, _countof(gui_alert_flags_strings));

	STRINGS(gui_error_category_enum)
	{
		"default",
		"networking",
		"storage (reading/writing failure)",
		"controller"
	};
	STRING_LIST(gui_error_category_enum, gui_error_category_enum_strings, _countof(gui_error_category_enum_strings));

	STRINGS(gui_error_icon_enum)
	{
		"default alert",
		"downloading",
		"paused",
		"uploading",
		"completed"
	};
	STRING_LIST(gui_error_icon_enum, gui_error_icon_enum_strings, _countof(gui_error_icon_enum_strings));

	STRINGS(gui_dialog_choice_enum)
	{
		"first item",
		"second item",
		"third item",
		"fourth item"
	};
	STRING_LIST(gui_dialog_choice_enum, gui_dialog_choice_enum_strings, _countof(gui_dialog_choice_enum_strings));

	STRINGS(gui_dialog_b_button_action_enum)
	{
		"dismisses dialog",
		"button ignored",
		"first item activates",
		"second item activates",
		"third item activates",
		"fourth item activates"
	};
	STRING_LIST(gui_dialog_b_button_action_enum, gui_dialog_b_button_action_enum_strings, _countof(gui_dialog_b_button_action_enum_strings));

	STRINGS(gui_dialog_flags)
	{
		"unused"
	};
	STRING_LIST(gui_dialog_flags, gui_dialog_flags_strings, _countof(gui_dialog_flags_strings));

	STRINGS(pgcr_enemy_to_category_entry_flags)
	{
		"category contains players"
	};
	STRING_LIST(pgcr_enemy_to_category_entry_flags, pgcr_enemy_to_category_entry_flags_strings, _countof(pgcr_enemy_to_category_entry_flags_strings));

	STRINGS(pgcr_player_type_enum)
	{
		"UNSC",
		"Covenant"
	};
	STRING_LIST(pgcr_player_type_enum, pgcr_player_type_enum_strings, _countof(pgcr_player_type_enum_strings));

	STRINGS(cui_camera_pivot_corner_enum_definition)
	{
		"top left",
		"top right",
		"bottom right",
		"bottom left"
	};
	STRING_LIST(cui_camera_pivot_corner_enum_definition, cui_camera_pivot_corner_enum_definition_strings, _countof(cui_camera_pivot_corner_enum_definition_strings));

	STRINGS(UIGameStartSequenceFlagsDefinition)
	{
		"show loadout menu",
		"loadout menu close ends sequence"
	};
	STRING_LIST(UIGameStartSequenceFlagsDefinition, UIGameStartSequenceFlagsDefinition_strings, _countof(UIGameStartSequenceFlagsDefinition_strings));

	STRINGS(UserInterfaceTagGlobalsFlagsDefinition)
	{
		"show ammo navpoints#show navpoints over ammo-crates and weapon-racks when below a clip-full of ammo"
	};
	STRING_LIST(UserInterfaceTagGlobalsFlagsDefinition, UserInterfaceTagGlobalsFlagsDefinition_strings, _countof(UserInterfaceTagGlobalsFlagsDefinition_strings));

	TAG_REFERENCE(g_user_interface_globals_reference, USER_INTERFACE_GLOBALS_DEFINITION_TAG);

	TAG_REFERENCE(g_user_interface_shared_globals_reference, USER_INTERFACE_SHARED_GLOBALS_DEFINITION_TAG);

} // namespace blofeld

