#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		InfinityUIImages_group,
		INFINITYUIIMAGES_TAG,
		nullptr,
		INVALID_TAG,
		InfinityUIImages_block );

	TAG_GROUP(
		pgcr_enemy_to_category_mapping_definition_group,
		PGCR_ENEMY_TO_CATEGORY_MAPPING_DEFINITION_TAG,
		nullptr,
		INVALID_TAG,
		pgcr_enemy_to_category_mapping_definition_block );

	TAG_GROUP(
		pgcr_damage_type_image_mapping_definition_group,
		PGCR_DAMAGE_TYPE_IMAGE_MAPPING_DEFINITION_TAG,
		nullptr,
		INVALID_TAG,
		pgcr_damage_type_image_mapping_definition_block );

	TAG_GROUP(
		portrait_poses_definition_group,
		PORTRAIT_POSES_DEFINITION_TAG,
		nullptr,
		INVALID_TAG,
		portrait_poses_definition_block );

	TAG_GROUP(
		user_interface_sounds_definition_group,
		USER_INTERFACE_SOUNDS_DEFINITION_TAG,
		nullptr,
		INVALID_TAG,
		user_interface_sounds_definition_block );

	TAG_GROUP(
		user_interface_globals_definition_group,
		USER_INTERFACE_GLOBALS_DEFINITION_TAG,
		nullptr,
		INVALID_TAG,
		user_interface_globals_definition_block );

	TAG_GROUP(
		user_interface_shared_globals_definition_group,
		USER_INTERFACE_SHARED_GLOBALS_DEFINITION_TAG,
		nullptr,
		INVALID_TAG,
		user_interface_shared_globals_definition_block );

	TAG_BLOCK_FROM_STRUCT(
		InfinityUIImages_block,
		"InfinityUIImages_block",
		1,
		InfinityUIImages_struct_definition);

	TAG_BLOCK_FROM_STRUCT(
		pgcr_enemy_to_category_mapping_definition_block,
		"pgcr_enemy_to_category_mapping_definition_block",
		1,
		pgcr_enemy_to_category_mapping_definition_struct_definition);

	TAG_BLOCK_FROM_STRUCT(
		pgcr_damage_type_image_mapping_definition_block,
		"pgcr_damage_type_image_mapping_definition_block",
		1,
		pgcr_damage_type_image_mapping_definition_struct_definition);

	TAG_BLOCK_FROM_STRUCT(
		portrait_poses_definition_block,
		"portrait_poses_definition_block",
		1,
		portrait_poses_definition_struct_definition);

	TAG_BLOCK_FROM_STRUCT(
		user_interface_sounds_definition_block,
		"user_interface_sounds_definition_block",
		1,
		user_interface_sounds_definition_struct_definition);

	TAG_BLOCK_FROM_STRUCT(
		user_interface_globals_definition_block,
		"user_interface_globals_definition_block",
		1,
		user_interface_globals_definition_struct_definition);

	TAG_BLOCK_FROM_STRUCT(
		user_interface_shared_globals_definition_block,
		"user_interface_shared_globals_definition_block",
		1,
		user_interface_shared_globals_definition_struct_definition);

	#define INFINITYMISSIONSEASONIMAGESDEFINITION_ID { 0x3FEA443C, 0xB8C04669, 0xA99A3532, 0x68153106 }
	TAG_BLOCK(
		InfinityMissionSeasonImagesDefinition_block,
		"InfinityMissionSeasonImagesDefinition",
		k_infinityMaximumSeasonCount,
		"InfinityMissionSeasonImages",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		INFINITYMISSIONSEASONIMAGESDEFINITION_ID)
	{
		FIELD_EXPLANATION("Season Images", nullptr, FIELD_FLAG_NONE, "This block should contain a season\'s worth of Infinity mission images"),
		{ _field_long_integer, "season number", FIELD_FLAG_INDEX },
		{ _field_tag_reference, "epilogue image", "displayed where the missions would be, when the epilogue is selected", &global_bitmap_reference },
		{ _field_block, "season images", &InfinityMissionImagesDefinition_block },
		{ _field_terminator }
	};

	#define INFINITYMISSIONIMAGESDEFINITION_ID { 0x0CCFE755, 0x34704BF3, 0xAC2769A3, 0x76B16EC8 }
	TAG_BLOCK(
		InfinityMissionImagesDefinition_block,
		"InfinityMissionImagesDefinition",
		k_infinityMaximumMissionsPerSeason,
		"InfinityMissionImages",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		INFINITYMISSIONIMAGESDEFINITION_ID)
	{
		{ _field_tag_reference, "card image", FIELD_FLAG_INDEX, &global_bitmap_reference },
		{ _field_tag_reference, "detail image", &global_bitmap_reference },
		{ _field_tag_reference, "lobby image", &global_bitmap_reference },
		{ _field_tag_reference, "match image", &global_bitmap_reference },
		{ _field_terminator }
	};

	#define PGCR_ENEMY_TO_CATEGORY_LIST_BLOCK_ID { 0x13CB91F2, 0x8FA0486C, 0xAD93BA1A, 0x01A12334 }
	TAG_BLOCK(
		pgcr_enemy_to_category_list_block,
		"pgcr_enemy_to_category_list_block",
		k_pgcr_maximum_number_of_categories_per_bucket,
		"s_pgcr_enemy_to_category_list",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		PGCR_ENEMY_TO_CATEGORY_LIST_BLOCK_ID)
	{
		{ _field_string_id, "category display name", FIELD_FLAG_INDEX },
		{ _field_short_integer, "sprite index" },
		{ _field_byte_flags, "flags", &pgcr_enemy_to_category_entry_flags },
		FIELD_PAD("pad0", nullptr, FIELD_FLAG_NONE, 1),
		{ _field_block, "player types", &pgcr_player_to_category_entry_block },
		{ _field_block, "enemy types", &pgcr_enemy_to_category_entry_block },
		{ _field_terminator }
	};

	#define PGCR_PLAYER_TO_CATEGORY_ENTRY_BLOCK_ID { 0xB6D21071, 0xD5C44DA8, 0xA2F448A1, 0xAC68E5A2 }
	TAG_BLOCK(
		pgcr_player_to_category_entry_block,
		"pgcr_player_to_category_entry_block",
		k_pgcr_maximum_number_of_player_entries_per_category,
		"s_pgcr_player_to_category_entry",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PGCR_PLAYER_TO_CATEGORY_ENTRY_BLOCK_ID)
	{
		{ _field_char_enum, "player type", &pgcr_player_type_enum },
		FIELD_PAD("pad0", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_terminator }
	};

	#define PGCR_ENEMY_TO_CATEGORY_ENTRY_BLOCK_ID { 0x27D7EA73, 0x810A49B9, 0x99464770, 0x0298B605 }
	TAG_BLOCK(
		pgcr_enemy_to_category_entry_block,
		"pgcr_enemy_to_category_entry_block",
		k_pgcr_maximum_number_of_ai_entries_per_category,
		"s_pgcr_enemy_to_category_entry",
		SET_POSTPROCESS_RECURSIVELY | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PGCR_ENEMY_TO_CATEGORY_ENTRY_BLOCK_ID)
	{
		{ _field_char_enum, "character type", &campaign_metagame_bucket_type_with_none_enum },
		{ _field_char_enum, "character class", &campaign_metagame_bucket_class_with_none_enum },
		FIELD_PAD("pad0", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	#define PGCR_DAMAGE_TYPE_IMAGE_BLOCK_ID { 0xA58519CD, 0xBDFA479A, 0xAD03CCFB, 0x836DF305 }
	TAG_BLOCK(
		pgcr_damage_type_image_block,
		"pgcr_damage_type_image_block",
		k_damage_reporting_type_count,
		"PgcrDamageTypeImageBlock",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PGCR_DAMAGE_TYPE_IMAGE_BLOCK_ID)
	{
		{ _field_long_enum, "damage type", FIELD_FLAG_INDEX, &global_damage_reporting_enum_definition },
		{ _field_string_id, "display name" },
		{ _field_tag_reference, "sprite", &global_bitmap_reference },
		{ _field_short_integer, "sprite index" },
		FIELD_PAD("pad0", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	#define GUI_PORTRAIT_POSE_BLOCK_ID { 0x44F2F85B, 0x26274A15, 0xBDC8AE7C, 0x9A78BCDA }
	TAG_BLOCK(
		gui_portrait_pose_block,
		"gui_portrait_pose_block",
		k_maxPortraitPoses,
		"GuiPortraitPose",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		GUI_PORTRAIT_POSE_BLOCK_ID)
	{
		{ _field_string_id, "pose name", FIELD_FLAG_INDEX },
		{ _field_string_id, "animation name" },
		{ _field_string_id, "camera view name" },
		{ _field_long_integer, "scenario profile index" },
		{ _field_terminator }
	};

	#define CUI_COMPONENT_SCREEN_REFERENCE_BLOCK_DEFINITION_ID { 0x5760E7A0, 0x4C3B4769, 0x86F13D78, 0x7B288742 }
	TAG_BLOCK(
		cui_component_screen_reference_block_definition_block,
		"cui_component_screen_reference_block_definition",
		k_maximum_number_of_screen_widgets,
		"s_cui_component_screen_reference",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CUI_COMPONENT_SCREEN_REFERENCE_BLOCK_DEFINITION_ID)
	{
		{ _field_legacy, _field_version_greater, _engine_type_halo3, 2 },
		{ _field_string_id, "name", "for use in code", FIELD_FLAG_INDEX },
		{ _field_tag_reference, "cui screen tag", &cui_screen_reference },

		{ _field_terminator }
	};

	#define CUI_OVERLAY_CAMERA_BLOCK_DEFINITION_ID { 0x83781BD0, 0x054D418E, 0x8894CE59, 0x955626E0 }
	TAG_BLOCK(
		cui_overlay_camera_block_definition_block,
		"cui_overlay_camera_block_definition",
		k_cui_max_overlay_count,
		"s_cui_overlay_camera_definition",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CUI_OVERLAY_CAMERA_BLOCK_DEFINITION_ID)
	{
		{ _field_string_id, "resolution name" },
		{ _field_char_enum, "pivot corner", &cui_camera_pivot_corner_enum_definition },
		FIELD_PAD("pad0", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_real, "Z near", "distance to near clipping plane" },
		{ _field_real, "Z far", "distance to far clipping plane" },
		{ _field_real, "X angle degrees", "camera angle around the X axis" },
		{ _field_real, "Y angle degrees", "camera angle around the Y axis" },
		{ _field_terminator }
	};

	#define CUI_PLAYER_MODEL_CAMERA_SETTINGS_DEFINITION_ID { 0x73F77A8A, 0xD54408BE, 0x85B6BDBA, 0xF872B8EF }
	TAG_BLOCK(
		cui_player_model_camera_settings_definition_block,
		"cui_player_model_camera_settings_definition",
		s_cui_player_model_camera_settings_definition::k_maximum_count,
		"s_cui_player_model_camera_settings_definition",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CUI_PLAYER_MODEL_CAMERA_SETTINGS_DEFINITION_ID)
	{
		FIELD_EXPLANATION("Camera Settings", nullptr, FIELD_FLAG_NONE, "These are model-viewing camera parameters that you can control\n* FOV is the field of view used by the texture camera\n  if left 0, a suitable default FOV is used\n* Initial Radial Offset is the initial radial distance of the camera from the target model\n* Final Radial Offset is the final radial distance of the camera from the target model\n* Camera Radial Step Size is the incremental change in input to the radial transition function per tick\n* Initial Vertical Offset is the initial vertical distance of the camera from the target\'s center\n* Final Vertical Offset is the final vertical distance of the camera from the target\'s center\n* Camera Vertical Step Size is the incremental change in input to the vertical transition function per tick\n* Camera Rotational Step Size is the incremental change in camera rotation per game tick\n* The Transition Functions are used to control the camera zoom with controller input\n  if left empty, a linear interpolation is used for camera zoom"),
		{ _field_string_id, "name" },
		{ _field_real_point_3d, "model world position", "arbitrary location in the world to place the model", "wu" },
		{ _field_real_point_3d, "minimum world position" },
		{ _field_real_point_3d, "maximum world position" },
		{ _field_string_id, "viewed model marker name" },
		{ _field_real_point_3d, "minimum camera offset", nullptr, "wu" },
		{ _field_real_point_3d, "minimum camera focal offset", nullptr, "wu" },
		{ _field_real_point_3d, "maximum camera offset", nullptr, "wu" },
		{ _field_real_point_3d, "maximum camera focal offset", nullptr, "wu" },
		{ _field_real, "initial zoom", nullptr, nullptr, "[0,1]" },
		{ _field_real, "fov", nullptr, "degrees" },
		{ _field_terminator }
	};

	#define CUI_PLAYER_MODEL_CONTROLLER_SETTINGS_DEFINITION_ID { 0x5D1BD5FE, 0xE2C814D2, 0x82BEF4F7, 0x43A082FE }
	TAG_BLOCK(
		cui_player_model_controller_settings_definition_block,
		"cui_player_model_controller_settings_definition",
		s_cui_player_model_control_settings_definition::k_maximum_count,
		"s_cui_player_model_control_settings_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		CUI_PLAYER_MODEL_CONTROLLER_SETTINGS_DEFINITION_ID)
	{
		{ _field_string_id, "name" },
		{ _field_real, "zoom speed", nullptr, "wu per tick" },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_default),
		{ _field_struct, "zoom transition function", &mapping_function },
		{ _field_real_euler_angles_2d, "initial rotation", nullptr, "degrees" },
		{ _field_real_euler_angles_2d, "minimum rotation", nullptr, "degrees" },
		{ _field_real_euler_angles_2d, "maximum rotation", nullptr, "degrees" },
		{ _field_real, "rotation speed", nullptr, "degrees per tick" },
		{ _field_terminator }
	};

	#define CUI_PLAYER_MODEL_TRANSITION_SETTINGS_DEFINITION_ID { 0x20E2FA5B, 0x22E54706, 0xB4CC1F62, 0x40E0ACAD }
	TAG_BLOCK(
		cui_player_model_transition_settings_definition_block,
		"cui_player_model_transition_settings_definition",
		s_cui_player_model_transition_settings_definition::k_maximum_count,
		"s_cui_player_model_transition_settings_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		CUI_PLAYER_MODEL_TRANSITION_SETTINGS_DEFINITION_ID)
	{
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_default),
		{ _field_struct, "camera transition function", &mapping_function },
		{ _field_terminator }
	};

	#define CUI_ACTIVE_ROSTER_SETTINGS_BLOCK_ID { 0x53A07740, 0x597D4CA2, 0xBD0133BC, 0x186516E6 }
	TAG_BLOCK(
		cui_active_roster_settings_block,
		"cui_active_roster_settings_block",
		s_cui_active_roster_settings_definition::k_max_count,
		"s_cui_active_roster_settings_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		CUI_ACTIVE_ROSTER_SETTINGS_BLOCK_ID)
	{
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_default),
		{ _field_struct, "analog scroll function", &mapping_function },
		{ _field_terminator }
	};

	#define CAMPAIGN_STATE_SCREEN_SCRIPT_BLOCK_DEFINITION_ID { 0x94A0C938, 0x2B6549A6, 0xBD541503, 0xC73BBD58 }
	TAG_BLOCK(
		campaign_state_screen_script_block_definition_block,
		"campaign_state_screen_script_block_definition",
		s_campaign_state_screen_script::k_max_count,
		"s_campaign_state_screen_script",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CAMPAIGN_STATE_SCREEN_SCRIPT_BLOCK_DEFINITION_ID)
	{
		{ _field_long_integer, "map ID" },
		{ _field_string_id, "screen script name" },
		{ _field_tag_reference, "music override", &global_looping_sound_reference },
		{ _field_terminator }
	};

	#define USERINTERFACEGAMESCREENSEQUENCESTEPDEFINITION_ID { 0x790FA350, 0xA4944DE5, 0x837B32AD, 0x52620CA4 }
	TAG_BLOCK(
		UserInterfaceGameScreenSequenceStepDefinition_block,
		"UserInterfaceGameScreenSequenceStepDefinition",
		UserInterfaceGameScreenSequenceStep::k_maxCount,
		"UserInterfaceGameScreenSequenceStep",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		USERINTERFACEGAMESCREENSEQUENCESTEPDEFINITION_ID)
	{
		{ _field_byte_flags, "flags", &UIGameStartSequenceFlagsDefinition },
		FIELD_PAD("UMPKIU", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_tag_reference, "screen", FIELD_FLAG_INDEX, &cui_screen_reference },
		{ _field_short_integer, "startTime", nullptr, "ticks" },
		{ _field_short_integer, "endTime", nullptr, "ticks" },
		{ _field_terminator }
	};

	#define SWAPTAGREFERENCEDEFINITION_ID { 0x60312DAA, 0xFAEB4AB4, 0xB8D8FC27, 0xED5127A8 }
	TAG_BLOCK(
		SwapTagReferenceDefinition_block,
		"SwapTagReferenceDefinition",
		SwapTagReferences::k_maxCount,
		"SwapTagReferences",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SWAPTAGREFERENCEDEFINITION_ID)
	{
		{ _field_tag_reference, "original tag", FIELD_FLAG_INDEX, &SwapTagReferenceDefinition_original_tag_reference },
		{ _field_tag_reference, "replacement tag", &SwapTagReferenceDefinition_original_tag_reference },
		{ _field_terminator }
	};

	#define COLOR_PRESETS_BLOCK_ID { 0x26B5A836, 0x2251412E, 0xA23E454A, 0x0039DCDE }
	TAG_BLOCK(
		color_presets_block,
		"color_presets_block",
		s_color_preset::k_maximum_color_presets,
		"s_color_preset",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		COLOR_PRESETS_BLOCK_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_real_argb_color, "color" },
		{ _field_terminator }
	};

	#define TINT_COLORS_BLOCK_ID { 0x60C481EE, 0x800046A2, 0x8304DA08, 0xAC51C372 }
	TAG_BLOCK(
		tint_colors_block,
		"tint_colors_block",
		1,
		"s_tint_colors",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		TINT_COLORS_BLOCK_ID)
	{
		{ _field_block, "text player", &color_list_block },
		{ _field_block, "text team", &color_list_block },
		{ _field_block, "bitmap player", &color_list_block },
		{ _field_block, "bitmap team", &color_list_block },
		FIELD_CUSTOM("Affiliation", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_real_argb_color, "bitmap friend" },
		{ _field_real_argb_color, "bitmap enemy" },
		{ _field_real_argb_color, "bitmap neutral" },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		FIELD_CUSTOM("Flood Team Colors", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_real_argb_color, "bitmap flood" },
		{ _field_real_argb_color, "bitmap spartans" },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		{ _field_terminator }
	};

	#define COLOR_LIST_BLOCK_ID { 0x0F5F62C7, 0xC6A24A78, 0xBCCFBB7A, 0xF47B91CD }
	TAG_BLOCK(
		color_list_block,
		"color_list_block",
		((k_player_color_index_count)>(k_multiplayer_team_game_team_count+1)?(k_player_color_index_count):(k_multiplayer_team_game_team_count+1)),
		"real_argb_color",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		COLOR_LIST_BLOCK_ID)
	{
		{ _field_real_argb_color, "color" },
		{ _field_terminator }
	};

	#define GUI_ALERT_DESCRIPTION_BLOCK_ID { 0xBE222E19, 0x7F2B4774, 0x8343FCDB, 0x1E293D77 }
	TAG_BLOCK(
		gui_alert_description_block,
		"gui_alert_description_block",
		s_gui_alert_description::k_maximum_gui_error_types_count,
		"s_gui_alert_description",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		GUI_ALERT_DESCRIPTION_BLOCK_ID)
	{
		{ _field_string_id, "error name", FIELD_FLAG_INDEX },
		{ _field_byte_flags, "flags", &gui_alert_flags },
		{ _field_char_enum, "error category", &gui_error_category_enum },
		{ _field_char_enum, "error icon", &gui_error_icon_enum },
		FIELD_PAD("pad0", nullptr, FIELD_FLAG_NONE, 1),
		{ _field_string_id, "title" },
		{ _field_string_id, "message" },
		{ _field_terminator }
	};

	#define GUI_DIALOG_DESCRIPTION_BLOCK_ID { 0x7C5393A4, 0x94744F38, 0x8CC51E2D, 0x299DFBF4 }
	TAG_BLOCK(
		gui_dialog_description_block,
		"gui_dialog_description_block",
		s_gui_dialog_description::k_maximum_gui_dialog_types_count,
		"s_gui_dialog_description",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		GUI_DIALOG_DESCRIPTION_BLOCK_ID)
	{
		{ _field_string_id, "dialog name", FIELD_FLAG_INDEX },
		{ _field_word_flags, "flags", &gui_dialog_flags },
		FIELD_PAD("pad0", nullptr, FIELD_FLAG_NONE, 2),
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

	#define PGCR_INCIDENT_BLOCK_STRUCT_ID { 0x177FA8B3, 0xD2614622, 0xBBDF9F2E, 0x00C598B9 }
	TAG_BLOCK(
		pgcr_incident_block,
		"pgcr_incident_block",
		s_cui_pgcr_incident::k_maximum_count,
		"s_cui_pgcr_incident",
		SET_UNKNOWN0 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | 
		SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PGCR_INCIDENT_BLOCK_STRUCT_ID)
	{
		{ _field_string_id, "incident name", FIELD_FLAG_INDEX },
		{ _field_long_integer, "maximum stat count", "number of times this can happen before the PGCR stops tracking them", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define INFINITYUIIMAGES_STRUCT_DEFINITION_ID { 0xD223EB5F, 0xCD5E44E1, 0xA3DEEA14, 0x416725BA }
	TAG_STRUCT(
		InfinityUIImages_struct_definition,
		"InfinityUIImages_struct_definition",
		"InfinityUIImages",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		INFINITYUIIMAGES_STRUCT_DEFINITION_ID)
	{
		{ _field_block, "seasons", &InfinityMissionSeasonImagesDefinition_block },
		{ _field_terminator }
	};

	#define PGCR_ENEMY_TO_CATEGORY_MAPPING_DEFINITION_STRUCT_DEFINITION_ID { 0x21E13268, 0x65D94C93, 0xAF53E865, 0x3B4C8BFC }
	TAG_STRUCT(
		pgcr_enemy_to_category_mapping_definition_struct_definition,
		"pgcr_enemy_to_category_mapping_definition_struct_definition",
		"s_pgcr_enemy_to_category_mapping",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		PGCR_ENEMY_TO_CATEGORY_MAPPING_DEFINITION_STRUCT_DEFINITION_ID)
	{
		{ _field_block, "character categories", &pgcr_enemy_to_category_list_block },
		{ _field_block, "vehicle categories", &pgcr_enemy_to_category_list_block },
		{ _field_terminator }
	};

	#define PGCR_DAMAGE_TYPE_IMAGE_MAPPING_DEFINITION_STRUCT_DEFINITION_ID { 0x1294C4E2, 0x1F1D4FBF, 0xAA479C98, 0xC6592582 }
	TAG_STRUCT(
		pgcr_damage_type_image_mapping_definition_struct_definition,
		"pgcr_damage_type_image_mapping_definition_struct_definition",
		"PgcrDamageTypeImageMapping",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		PGCR_DAMAGE_TYPE_IMAGE_MAPPING_DEFINITION_STRUCT_DEFINITION_ID)
	{
		{ _field_block, "damage type mapping", &pgcr_damage_type_image_block },
		{ _field_terminator }
	};

	#define PORTRAIT_POSES_DEFINITION_STRUCT_DEFINITION_ID { 0xF0850C93, 0x4E2245F1, 0xB23D8D60, 0xE64B9FE0 }
	TAG_STRUCT(
		portrait_poses_definition_struct_definition,
		"portrait_poses_definition_struct_definition",
		"UserInterfacePortraitPosesDefinitions",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		PORTRAIT_POSES_DEFINITION_STRUCT_DEFINITION_ID)
	{
		{ _field_block, "portrait poses", &gui_portrait_pose_block },
		{ _field_terminator }
	};

	#define USER_INTERFACE_SOUNDS_DEFINITION_STRUCT_DEFINITION_ID { 0x70FFE855, 0x2DE74385, 0x83BAE604, 0x1597E3B6 }
	TAG_STRUCT(
		user_interface_sounds_definition_struct_definition,
		"user_interface_sounds_definition_struct_definition",
		"s_user_interface_sounds",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		USER_INTERFACE_SOUNDS_DEFINITION_STRUCT_DEFINITION_ID)
	{
		FIELD_CUSTOM("Controller Input Events", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
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
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		FIELD_CUSTOM("General", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_tag_reference, "error", &global_sound_reference },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		FIELD_CUSTOM("Screen", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_tag_reference, "screen transition in", &global_sound_reference },
		{ _field_tag_reference, "screen transition out", &global_sound_reference },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		FIELD_CUSTOM("Timers", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_tag_reference, "game start countdown timer first tick", &global_sound_reference },
		{ _field_tag_reference, "game start countdown timer tick", &global_sound_reference },
		{ _field_tag_reference, "game start countdown timer final tick", &global_sound_reference },
		{ _field_tag_reference, "alternate countdown timer first tick", &global_sound_reference },
		{ _field_tag_reference, "alternate countdown timer tick", &global_sound_reference },
		{ _field_tag_reference, "alternate countdown timer final tick", &global_sound_reference },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		FIELD_CUSTOM("Misc", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_tag_reference, "matchmaking reveal", &global_sound_reference },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		FIELD_CUSTOM("Exit Experience", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
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
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		{ _field_terminator }
	};

	#define USER_INTERFACE_GLOBALS_DEFINITION_STRUCT_DEFINITION_ID { 0xFF5E4703, 0xC3CE4535, 0xBBBF413E, 0x31D62CBE }
	TAG_STRUCT(
		user_interface_globals_definition_struct_definition,
		"user_interface_globals_definition_struct_definition",
		"s_user_interface_tag_globals",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		USER_INTERFACE_GLOBALS_DEFINITION_STRUCT_DEFINITION_ID)
	{
		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_long_flags, "flags", &UserInterfaceTagGlobalsFlagsDefinition },

		FIELD_EXPLANATION("Shared Globals", nullptr, FIELD_FLAG_NONE, "This is a reference to the ui shared globals tag"),
		{ _field_tag_reference, "shared globals", &g_user_interface_shared_globals_reference },
		FIELD_EXPLANATION("Multiplayer Variant Settings Interface", nullptr, FIELD_FLAG_NONE, "This blob defines the ui for setting multiplayer game variant parameters"),
		{ _field_tag_reference, "mp variant settings ui", &g_multiplayer_variant_settings_interface_reference },
		FIELD_EXPLANATION("Game Hopper Localization Strings", nullptr, FIELD_FLAG_NONE, "This is for the loc game hopper strings"),
		{ _field_tag_reference, "game hopper descriptions", &global_multilingual_unicode_string_list_reference },
		FIELD_EXPLANATION("Screen Widgets", nullptr, FIELD_FLAG_NONE, "These are the HaloX screen widgets"),
		{ _field_block, "cui screen widgets", &cui_component_screen_reference_block_definition_block },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach, 5 },
		{ _field_block, "cui overlay cameras", &cui_overlay_camera_block_definition_block },
		{ _field_block, "player model camera settings", &cui_player_model_camera_settings_definition_block },
		{ _field_block, "player model input settings", &cui_player_model_controller_settings_definition_block },
		{ _field_block, "player model camera transition settings", &cui_player_model_transition_settings_definition_block },
		{ _field_tag_reference, "purchase globals", &cookie_purchase_globals_reference },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_tag_reference, "infinity mission images", MAKE_OLD_NAMES("infinity mission images ref"), &Tag::Reference<struct InfinityUIImages>::s_defaultDefinition },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_block, "active roster settings", &cui_active_roster_settings_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		FIELD_EXPLANATION("PGCR Categories Definitions", nullptr, FIELD_FLAG_NONE, "This is a reference to the tag storing the categories we want to display in the PGCR"),
		{ _field_tag_reference, "pgcr categories definitions", &pgcr_enemy_to_category_mapping_definition_reference },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach, 2 },
		FIELD_EXPLANATION("PGCR Damage Types Definitions", nullptr, FIELD_FLAG_NONE, "This is a reference to the tag storing details about damage types for display in the PGCR"),
		{ _field_tag_reference, "pgcr damage types definitions", &pgcr_damage_type_image_mapping_definition_reference },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach, 2 },
		FIELD_EXPLANATION("Campaign State Screen Scripts", nullptr, FIELD_FLAG_NONE, "Contains a mapping of campaign map IDs and screen scripts used to implement lobby backgrounds that track campaign state. This block should only be non-empty for the main menu."),
		{ _field_block, "campaign state screen scripts", &campaign_state_screen_script_block_definition_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 9 },
		{ _field_real, "spawn-timer countdown rate", nullptr, "counts/sec" },
		{ _field_block, "game intro sequence", &UserInterfaceGameScreenSequenceStepDefinition_block },
		{ _field_block, "game round end sequence", &UserInterfaceGameScreenSequenceStepDefinition_block },
		{ _field_block, "game next round sequence", &UserInterfaceGameScreenSequenceStepDefinition_block },
		{ _field_block, "game end sequence", &UserInterfaceGameScreenSequenceStepDefinition_block },
		{ _field_block, "game end with killcam sequence", &UserInterfaceGameScreenSequenceStepDefinition_block },
		{ _field_tag_reference, "HUD globals", "global settings for the HUD. Set this for ingame globals.", &Tag::Reference<struct UserInterfaceHUDGlobalsDefinitions>::s_defaultDefinition },
		{ _field_tag_reference, "portrait poses", &portrait_poses_definition_reference },
		{ _field_block, "swap tags", &SwapTagReferenceDefinition_block },

		{ _field_terminator }
	};

	#define USER_INTERFACE_SHARED_GLOBALS_DEFINITION_STRUCT_DEFINITION_ID { 0x520DAD1B, 0x3ABC40F7, 0xA25DED9A, 0xB6D09BC7 }
	TAG_STRUCT(
		user_interface_shared_globals_definition_struct_definition,
		"user_interface_shared_globals_definition_struct_definition",
		"s_user_interface_shared_globals",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		USER_INTERFACE_SHARED_GLOBALS_DEFINITION_STRUCT_DEFINITION_ID)
	{
		FIELD_EXPLANATION("UI Rendering Globals", nullptr, FIELD_FLAG_NONE, "miscellaneous rendering globals, more below..."),
		{ _field_short_integer, "inc. text update period", nullptr, "milliseconds" },
		{ _field_short_integer, "inc. text block character", nullptr, "ASCII code" },
		{ _field_real, "near clip plane distance", nullptr, "objects closer than this are not drawn" },
		{ _field_real, "projection plane distance", nullptr, "distance at which objects are rendered when z=0 (normal size)" },
		{ _field_real, "far clip plane distance", nullptr, "objects farther than this are not drawn" },
		FIELD_EXPLANATION("Global Text Strings", nullptr, FIELD_FLAG_NONE, "Global UI Text goes here"),
		{ _field_tag_reference, "unicode string list tag", &global_multilingual_unicode_string_list_reference },
		{ _field_tag_reference, "unicode damage reporting string list tag", &global_multilingual_unicode_string_list_reference },
		{ _field_tag_reference, "unicode fire team member name string list", MAKE_OLD_NAMES("unicode fire team member string list tag"), &global_multilingual_unicode_string_list_reference },
		{ _field_tag_reference, "unicode fire team member service tag string list", &global_multilingual_unicode_string_list_reference },
		FIELD_EXPLANATION("Main menu music", nullptr, FIELD_FLAG_NONE, "Looping sound that plays while the main menu is active"),
		{ _field_tag_reference, "main menu music", &global_looping_sound_reference },
		{ _field_tag_reference, "main menu alternate music", &global_looping_sound_reference },
		{ _field_long_integer, "music fade time", nullptr, "milliseconds" },
		FIELD_EXPLANATION("Default Text and Shadow Colors", nullptr, FIELD_FLAG_NONE, "These are the default values used for text glyphs and text shadows"),
		{ _field_real_argb_color, "text color" },
		{ _field_real_argb_color, "shadow color" },
		FIELD_EXPLANATION("Color presets", nullptr, FIELD_FLAG_NONE, "Colors are defined here and used in text widgets throughout the UI.  Specify a string_id here and the same one in a text widget.  If you don\'t specify one in a text widget, you\'ll use the first entry here."),
		{ _field_block, "color presets", &color_presets_block },
		FIELD_EXPLANATION("Tint colors", nullptr, FIELD_FLAG_NONE, "These colors are used for tinting widgets by team or player color."),
		{ _field_block, "tint colors", &tint_colors_block },
		FIELD_EXPLANATION("Emblem counts", nullptr, FIELD_FLAG_NONE, "This lets us define how many images are in the emblem image bitmaps without opening them."),
		{ _field_short_integer, "Primary emblem count" },
		{ _field_short_integer, "Secondary emblem count" },
		FIELD_EXPLANATION("User interface sounds", nullptr, FIELD_FLAG_NONE, "Default sound effects for various UI actions"),
		{ _field_tag_reference, "default sounds", &user_interface_sounds_definition_reference },
		FIELD_EXPLANATION("HaloX Alerts", nullptr, FIELD_FLAG_NONE, "Alerts are triggered by specific events that happen in the game.  The game can require that an error be resolved before the dialog can be dismissed.  Once the error is resolved (or if it doesn\'t require resolution,) the user can dismiss it."),
		{ _field_block, "alert descriptions", &gui_alert_description_block },
		FIELD_EXPLANATION("HaloX Dialogs", nullptr, FIELD_FLAG_NONE, "Dialogs are brought up by individual screens or UI systems to ask the user a question, typically of the Ok/Cancel sort such as: \'Are you sure you want to leave the game?\'.\nNotes:\n- first item defaults to \'ok\', second item defaults to \'cancel.  third and fourth items don\'t display if they\'re not set\n- if \'b button action\' is set to \'button ignored\' then the b button doesn\'t do anything (such as cancelling)"),
		{ _field_block, "dialog descriptions", &gui_dialog_description_block },
		FIELD_EXPLANATION("Content Aspect Ratio Scaling", nullptr, FIELD_FLAG_NONE, "These define the scaling that will get applied to UI content and animations when running at the specified display modes"),
		{ _field_real_vector_2d, "16x9" },
		{ _field_real_vector_2d, "4x3" },
		FIELD_EXPLANATION("Blur Constants", nullptr, FIELD_FLAG_NONE, "These control the blur kernel used when blurring overlayed UI"),
		{ _field_real, "horizontal blur factor" },
		{ _field_real, "vertical blur factor" },
		FIELD_EXPLANATION("Appearance Model Names", nullptr, FIELD_FLAG_NONE, "These specify the name of a scenario-placed biped to be used for the Start Menu Appearance model\nIf you want to use a scenario-placed biped (non-AI), enter the biped name in the \'biped name\' field\nIf you want to use an AI-placed biped, enter the squad name string and starting position string_id"),
		{ _field_string_id, "mc biped name" },
		{ _field_string, "mc ai squad name" },
		{ _field_string_id, "mc ai start pos" },
		{ _field_string_id, "elite biped name" },
		{ _field_string, "elite ai squad name" },
		{ _field_string_id, "elite ai start pos" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 3 },
		FIELD_EXPLANATION("Player Portrait Model Names", nullptr, FIELD_FLAG_NONE, "These specify the name of a scenario-placed biped to be used for the Player Portrait Appearance model\nEnter the scenario-placed biped (non-AI) name in the \'spartan biped name\' and \'elite biped name\' field"),
		{ _field_string_id, "spartan portrait biped name" },
		{ _field_string_id, "elite portrait biped name" },

		FIELD_EXPLANATION("UI Navigation speed", nullptr, FIELD_FLAG_NONE, "This controls tabbing around the UI.  The tab delay is how fast you move around normally. \nTab fast wait is how long the UI waits till using the tab fast delay instead of the tab delay."),
		{ _field_long_integer, "navigation tab delay msec" },
		{ _field_long_integer, "navigation tab fast wait msec" },
		{ _field_long_integer, "navigation tab fast delay msec" },
		FIELD_EXPLANATION("Spinner tab speed", nullptr, FIELD_FLAG_NONE, "This is an alternate control for tabbing speed in the spinner.\nThe input (x) is the time the stick has been held down.\nThe output (y) is the time between tab events."),
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_default),
		{ _field_struct, "spinner tab speed function", &mapping_function },
		{ _field_long_integer, "max input time (x) on the graph (msec)" },
		FIELD_EXPLANATION("Attract Mode Settings", nullptr, FIELD_FLAG_NONE, "These control behavior of the attract mode movies"),
		{ _field_long_integer, "delay", nullptr, "seconds" },
		{ _field_block, "PGCR per player tracked incidents", &pgcr_incident_block },
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

} // namespace macaque

} // namespace blofeld

