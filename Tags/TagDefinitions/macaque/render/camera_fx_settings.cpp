#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define CAMERA_FX_SETTINGS_STRUCT_DEFINITION_ID { 0xC7122CD7, 0x03134944, 0xAAB3E3D9, 0xBFBE70FD }
	TAG_BLOCK(
		camera_fx_settings_block,
		"camera_fx_settings_block",
		1,
		"c_camera_fx_settings",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CAMERA_FX_SETTINGS_STRUCT_DEFINITION_ID)
	{
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_unknown_begin),
		{ _field_struct, "exposure", &camera_fx_exposure_struct },
		{ _field_struct, "auto_exposure_sensitivity", &camera_fx_exposure_sensitivity_struct },
		{ _field_struct, "bloom_highlight", MAKE_OLD_NAMES("bloom_point"), &camera_fx_bloom_highlight_struct },
		{ _field_struct, "bloom_inherent", &camera_fx_bloom_inherent_struct },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_struct, "bloom_self_illum", &camera_fx_bloom_self_illum_struct },

		{ _field_struct, "bloom_intensity", &camera_fx_bloom_intensity_struct },
		{ _field_struct, "bloom_large_color", &camera_fx_bloom_large_color_struct },
		{ _field_struct, "bloom_medium_color", &camera_fx_bloom_medium_color_struct },
		{ _field_struct, "bloom_small_color", &camera_fx_bloom_small_color_struct },
		{ _field_struct, "bling_intensity", FIELD_FLAG_UNKNOWN0, &camera_fx_bling_intensity_struct },
		{ _field_struct, "bling_size", FIELD_FLAG_UNKNOWN0, &camera_fx_bling_size_struct },
		{ _field_struct, "bling_angle", FIELD_FLAG_UNKNOWN0, &camera_fx_bling_angle_struct },
		{ _field_struct, "bling_count", FIELD_FLAG_UNKNOWN0, &camera_fx_bling_count_struct },
		{ _field_struct, "self_illum_preferred", &camera_fx_self_illum_preferred_struct },
		{ _field_struct, "self_illum_scale", &camera_fx_self_illum_scale_struct },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_struct, "color_grading", &camera_fx_color_grading_struct },
		{ _field_struct, "filmic_tone_curve", &camera_fx_filmic_tone_curve_struct },

		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_unknown_end),
		{ _field_terminator }
	};

	TAG_GROUP(
		camera_fx_settings_group,
		CAMERA_FX_SETTINGS_TAG,
		nullptr,
		INVALID_TAG,
		camera_fx_settings_block );

	#define CAMERA_FX_EXPOSURE_STRUCT_ID { 0x1FBECC29, 0x38C74B70, 0xAF139847, 0x3C5FD67B }
	TAG_STRUCT(
		camera_fx_exposure_struct,
		"camera_fx_exposure_struct",
		"c_camera_fx_settings::s_real_exposure_parameter",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CAMERA_FX_EXPOSURE_STRUCT_ID)
	{
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_unknown_begin),
		FIELD_EXPLANATION("EXPOSURE", nullptr, FIELD_FLAG_NONE, "Controls the brightness of the scene, like exposure time on your camera.\nThe actual exposure always blends towards the target exposure.\nWith auto-exposure on, the target exposure is calculated relative to the brightness of what is on screen.\n"),
		{ _field_word_flags, "flags", &camera_fx_parameter_flags_auto_adjust },
		FIELD_PAD("MKRGRF", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real, "exposure", "the target exposure (ONLY USED WHEN AUTO-EXPOSURE IS OFF)", "stops" },
		{ _field_real, "maximum change", "the maximum allowed change in exposure between frames", "stops" },
		{ _field_real, "blend speed (0-1)", "1 is instantaneous, 0.01 is a good speed, 0.001 is slower", "percent per frame" },
		{ _field_real, "minimum", "the absolute target exposure is clamped to this range", "stops" },
		{ _field_real, "maximum", "the absolute target exposure is clamped to this range", "stops" },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_unknown_end),
		{ _field_real, "auto-exposure screen brightness", "how bright you want the screen to be - auto-exposure will make it happen", nullptr, "[0.0001-1]" },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_unknown_begin),
		{ _field_real, "auto-exposure delay", "how long to wait before auto-exposure kicks in to adjust the exposure", nullptr, "[0.1-1]seconds" },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_unknown_end),
		{ _field_terminator }
	};

	#define CAMERA_FX_EXPOSURE_SENSITIVITY_STRUCT_ID { 0xB2285D8B, 0x80E54585, 0xA4116DDE, 0x5A2A16B5 }
	TAG_STRUCT(
		camera_fx_exposure_sensitivity_struct,
		"camera_fx_exposure_sensitivity_struct",
		"c_camera_fx_settings::s_real_instant_parameter",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CAMERA_FX_EXPOSURE_SENSITIVITY_STRUCT_ID)
	{
		FIELD_EXPLANATION("AUTO EXPOSURE SENSITIVITY", nullptr, FIELD_FLAG_NONE, "How sensitive auto exposure is to small bright patches on the screen (like the sun)"),
		{ _field_word_flags, "flags", &camera_fx_parameter_flags_no_auto_adjust },
		FIELD_PAD("MAKAMAKAHEY", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real, "sensitivity (0-1)" },
		{ _field_terminator }
	};

	#define CAMERA_FX_BLOOM_HIGHLIGHT_STRUCT_ID { 0x5C28BDB2, 0x7AA74136, 0x95D02E4D, 0x477781EA }
	TAG_STRUCT(
		camera_fx_bloom_highlight_struct,
		"camera_fx_bloom_highlight_struct",
		"c_camera_fx_settings::s_real_parameter",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CAMERA_FX_BLOOM_HIGHLIGHT_STRUCT_ID)
	{
		FIELD_EXPLANATION("HIGHLIGHT BLOOM", nullptr, FIELD_FLAG_NONE, "These parameters control bloom off the highlights (really bright stuff)"),
		{ _field_word_flags, "flags", &camera_fx_parameter_flags_no_auto_adjust },
		FIELD_PAD("LOTPRER", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real, "highlight bloom", MAKE_OLD_NAMES("bloom point") },
		{ _field_real, "maximum change" },
		{ _field_real, "blend speed (0-1)" },
		{ _field_terminator }
	};

	#define CAMERA_FX_BLOOM_INHERENT_STRUCT_ID { 0x1889C932, 0xA56D48C8, 0xB0B3D7D4, 0x01DCD5F7 }
	TAG_STRUCT(
		camera_fx_bloom_inherent_struct,
		"camera_fx_bloom_inherent_struct",
		"c_camera_fx_settings::s_real_parameter",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CAMERA_FX_BLOOM_INHERENT_STRUCT_ID)
	{
		FIELD_EXPLANATION("INHERENT BLOOM", nullptr, FIELD_FLAG_NONE, "These parameters control bloom off everything (bright and dark)"),
		{ _field_word_flags, "flags", &camera_fx_parameter_flags_no_auto_adjust },
		FIELD_PAD("ERIRLE", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real, "inherent bloom" },
		{ _field_real, "maximum change" },
		{ _field_real, "blend speed (0-1)" },
		{ _field_terminator }
	};

	#define CAMERA_FX_BLOOM_SELF_ILLUM_STRUCT_ID { 0xC4818F7F, 0xC84D4C8F, 0x949CB9BD, 0x418899B7 }
	TAG_STRUCT(
		camera_fx_bloom_self_illum_struct,
		"camera_fx_bloom_self_illum_struct",
		"c_camera_fx_settings::s_real_parameter",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CAMERA_FX_BLOOM_SELF_ILLUM_STRUCT_ID)
	{
		FIELD_EXPLANATION("SELF-ILLUM BLOOM", nullptr, FIELD_FLAG_NONE, "These parameters control off of self-illum pixels"),
		{ _field_word_flags, "flags", &camera_fx_parameter_flags_no_auto_adjust },
		FIELD_PAD("ERIRLE", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real, "self-illum bloom bloom" },
		{ _field_real, "maximum change" },
		{ _field_real, "blend speed (0-1)" },
		{ _field_terminator }
	};

	#define CAMERA_FX_BLOOM_INTENSITY_STRUCT_ID { 0xA87763D2, 0xF5B240F3, 0xA22524B0, 0xF5DFD719 }
	TAG_STRUCT(
		camera_fx_bloom_intensity_struct,
		"camera_fx_bloom_intensity_struct",
		"c_camera_fx_settings::s_real_parameter",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CAMERA_FX_BLOOM_INTENSITY_STRUCT_ID)
	{
		FIELD_EXPLANATION("BLOOM INTENSITY", nullptr, FIELD_FLAG_NONE, "These parameters control how bright the bloom is, relative to the underlying scene"),
		{ _field_word_flags, "flags", &camera_fx_parameter_flags_no_auto_adjust },
		FIELD_PAD("SEMIFMD", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real, "bloom intensity" },
		{ _field_real, "maximum change" },
		{ _field_real, "blend speed (0-1)" },
		{ _field_terminator }
	};

	#define CAMERA_FX_BLOOM_LARGE_COLOR_STRUCT_ID { 0x3318D9F0, 0x02EC4CD5, 0xADE89517, 0x0292B6B5 }
	TAG_STRUCT(
		camera_fx_bloom_large_color_struct,
		"camera_fx_bloom_large_color_struct",
		"c_camera_fx_settings::s_color_parameter",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CAMERA_FX_BLOOM_LARGE_COLOR_STRUCT_ID)
	{
		FIELD_EXPLANATION("BLOOM LARGE COLOR", nullptr, FIELD_FLAG_NONE, "These parameters control the color of the large bloom"),
		{ _field_word_flags, "flags", &camera_fx_parameter_flags_no_auto_adjust },
		FIELD_PAD("KKROFI", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real_rgb_color, "large color" },
		{ _field_terminator }
	};

	#define CAMERA_FX_BLOOM_MEDIUM_COLOR_STRUCT_ID { 0xA8C89B4A, 0x156A41DD, 0xBCA2746E, 0x49C59B4A }
	TAG_STRUCT(
		camera_fx_bloom_medium_color_struct,
		"camera_fx_bloom_medium_color_struct",
		"c_camera_fx_settings::s_color_parameter",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CAMERA_FX_BLOOM_MEDIUM_COLOR_STRUCT_ID)
	{
		FIELD_EXPLANATION("BLOOM MEDIUM COLOR", nullptr, FIELD_FLAG_NONE, "These parameters control the color of the medium bloom"),
		{ _field_word_flags, "flags", &camera_fx_parameter_flags_no_auto_adjust },
		FIELD_PAD("LEORPP", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real_rgb_color, "medium color" },
		{ _field_terminator }
	};

	#define CAMERA_FX_BLOOM_SMALL_COLOR_STRUCT_ID { 0x36F650D6, 0x8BC24EAA, 0x80D95DD3, 0xC20AACC8 }
	TAG_STRUCT(
		camera_fx_bloom_small_color_struct,
		"camera_fx_bloom_small_color_struct",
		"c_camera_fx_settings::s_color_parameter",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CAMERA_FX_BLOOM_SMALL_COLOR_STRUCT_ID)
	{
		FIELD_EXPLANATION("BLOOM SMALL COLOR", nullptr, FIELD_FLAG_NONE, "These parameters control the color of the small bloom"),
		{ _field_word_flags, "flags", &camera_fx_parameter_flags_no_auto_adjust },
		FIELD_PAD("JSIRWSFGAOD", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real_rgb_color, "small color" },
		{ _field_terminator }
	};

	#define CAMERA_FX_BLING_INTENSITY_STRUCT_ID { 0xE8F1A4E1, 0xC00F4456, 0x8EE2967B, 0x6D8FA42B }
	TAG_STRUCT(
		camera_fx_bling_intensity_struct,
		"camera_fx_bling_intensity_struct",
		"c_camera_fx_settings::s_real_parameter",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CAMERA_FX_BLING_INTENSITY_STRUCT_ID)
	{
		{ _field_word_flags, "flags", FIELD_FLAG_UNKNOWN0, &camera_fx_parameter_flags_no_auto_adjust },
		FIELD_PAD("QREWRER", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real, "bling intensity", FIELD_FLAG_UNKNOWN0 },
		{ _field_real, "maximum change", FIELD_FLAG_UNKNOWN0 },
		{ _field_real, "blend speed (0-1)", FIELD_FLAG_UNKNOWN0 },
		{ _field_terminator }
	};

	#define CAMERA_FX_BLING_SIZE_STRUCT_ID { 0xF54F8BED, 0xE5544B4E, 0x926E406D, 0xEFE013B9 }
	TAG_STRUCT(
		camera_fx_bling_size_struct,
		"camera_fx_bling_size_struct",
		"c_camera_fx_settings::s_real_parameter",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CAMERA_FX_BLING_SIZE_STRUCT_ID)
	{
		{ _field_word_flags, "flags", FIELD_FLAG_UNKNOWN0, &camera_fx_parameter_flags_no_auto_adjust },
		FIELD_PAD("LSDFPO", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real, "bling length", FIELD_FLAG_UNKNOWN0 },
		{ _field_real, "maximum change", FIELD_FLAG_UNKNOWN0 },
		{ _field_real, "blend speed (0-1)", FIELD_FLAG_UNKNOWN0 },
		{ _field_terminator }
	};

	#define CAMERA_FX_BLING_ANGLE_STRUCT_ID { 0x31CE204D, 0x092C4581, 0xA500B810, 0x18D31B80 }
	TAG_STRUCT(
		camera_fx_bling_angle_struct,
		"camera_fx_bling_angle_struct",
		"c_camera_fx_settings::s_real_parameter",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CAMERA_FX_BLING_ANGLE_STRUCT_ID)
	{
		{ _field_word_flags, "flags", FIELD_FLAG_UNKNOWN0, &camera_fx_parameter_flags_no_auto_adjust },
		FIELD_PAD("ILJS", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real, "bling angle", FIELD_FLAG_UNKNOWN0 },
		{ _field_real, "maximum change", FIELD_FLAG_UNKNOWN0 },
		{ _field_real, "blend speed (0-1)", FIELD_FLAG_UNKNOWN0 },
		{ _field_terminator }
	};

	#define CAMERA_FX_BLING_COUNT_STRUCT_ID { 0x8457D09C, 0xCB004AEB, 0x87C29399, 0xF221FEF5 }
	TAG_STRUCT(
		camera_fx_bling_count_struct,
		"camera_fx_bling_count_struct",
		"c_camera_fx_settings::s_word_parameter",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CAMERA_FX_BLING_COUNT_STRUCT_ID)
	{
		{ _field_word_flags, "flags", FIELD_FLAG_UNKNOWN0, &camera_fx_parameter_flags_bling_spikes },
		{ _field_short_integer, "bling spikes", FIELD_FLAG_UNKNOWN0 },
		{ _field_terminator }
	};

	#define CAMERA_FX_SELF_ILLUM_PREFERRED_STRUCT_ID { 0xE684AD74, 0xC6D54D23, 0x996036C6, 0xC011911B }
	TAG_STRUCT(
		camera_fx_self_illum_preferred_struct,
		"camera_fx_self_illum_preferred_struct",
		"c_camera_fx_settings::s_real_parameter",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CAMERA_FX_SELF_ILLUM_PREFERRED_STRUCT_ID)
	{
		FIELD_EXPLANATION("SELF ILLUM EXPOSURE", nullptr, FIELD_FLAG_NONE, "These parameters control the self-illumination exposure\npreferred is the preferred exposure, and scale controls\nhow much it varies from the preferred exposure"),
		{ _field_word_flags, "flags", &camera_fx_parameter_flags_no_auto_adjust },
		FIELD_PAD("JJFJFJKE", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real, "preferred exposure", "the preferred exposure for self illum", "stops" },
		{ _field_real, "maximum change" },
		{ _field_real, "blend speed (0-1)" },
		{ _field_terminator }
	};

	#define CAMERA_FX_SELF_ILLUM_SCALE_STRUCT_ID { 0x4545C700, 0x22624FE4, 0xB9FDE3E7, 0x1696B87B }
	TAG_STRUCT(
		camera_fx_self_illum_scale_struct,
		"camera_fx_self_illum_scale_struct",
		"c_camera_fx_settings::s_real_parameter",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CAMERA_FX_SELF_ILLUM_SCALE_STRUCT_ID)
	{
		FIELD_EXPLANATION("SELF ILLUM CHANGE", nullptr, FIELD_FLAG_NONE, "How much self illum exposure is allowed to change\n0 means no change at all, 1 means it will\nequal the normal exposure"),
		{ _field_word_flags, "flags", &camera_fx_parameter_flags_no_auto_adjust },
		FIELD_PAD("WOOGATCHOU", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real, "exposure change", "how much the self illum is allowed to change, as a percentage of the normal exposure change", nullptr, "[0-1]" },
		{ _field_real, "maximum change" },
		{ _field_real, "blend speed (0-1)" },
		{ _field_terminator }
	};

	#define CAMERA_FX_COLOR_GRADING_STRUCT_ID { 0x20D7EB22, 0x88C04602, 0xBEB7FEF7, 0x42178564 }
	TAG_STRUCT(
		camera_fx_color_grading_struct,
		"camera_fx_color_grading_struct",
		"c_camera_fx_settings::s_color_grading_parameter",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CAMERA_FX_COLOR_GRADING_STRUCT_ID)
	{
		FIELD_EXPLANATION("Color Grading", nullptr, FIELD_FLAG_NONE, "set the color grading texture"),
		{ _field_word_flags, "flags", &camera_fx_parameter_flags_no_auto_adjust },
		FIELD_PAD("SKHFDNV", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_tag_reference, "color grading texture", &global_bitmap_reference },
		{ _field_terminator }
	};

	#define CAMERA_FX_FILMIC_TONE_CURVE_STRUCT_ID { 0x50612BFA, 0x4C8940DC, 0x9911F845, 0x5C3B5FB1 }
	TAG_STRUCT(
		camera_fx_filmic_tone_curve_struct,
		"camera_fx_filmic_tone_curve_struct",
		"c_camera_fx_settings::s_filmic_tone_curve_parameter",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CAMERA_FX_FILMIC_TONE_CURVE_STRUCT_ID)
	{
		FIELD_EXPLANATION("Filmic Tone Curve", nullptr, FIELD_FLAG_NONE, "set the values for the filmic tone curve"),
		{ _field_word_flags, "flags", &camera_fx_parameter_flags_enabled },
		FIELD_PAD("MKRGRF", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real, "shoulder strength", "How intense the shoulder is" },
		{ _field_real, "linear strength", "How intense the linear portion is" },
		{ _field_real, "linear angle", "Angle of linear portion of curve" },
		{ _field_real, "toe strength", "How intense the toe is" },
		{ _field_real, "toe numerator", "Numerator of toe slope" },
		{ _field_real, "toe denominator", "Denominator of toe slope" },
		{ _field_real, "linear white point", "The white point in linear space" },
		{ _field_terminator }
	};

	STRINGS(camera_fx_parameter_flags_auto_adjust)
	{
		"use default (ignore these values)",
		"maximum change is relative",
		"auto-adjust target",
		"bit3!",
		"fixed!",
		"(unused2)!",
		"fixed2!"
	};
	STRING_LIST(camera_fx_parameter_flags_auto_adjust, camera_fx_parameter_flags_auto_adjust_strings, _countof(camera_fx_parameter_flags_auto_adjust_strings));

	STRINGS(camera_fx_parameter_flags_no_auto_adjust)
	{
		"use default (ignore these values)",
		"maximum change is relative",
		"(unused)!",
		"bit3!",
		"fixed!",
		"(unused2)!",
		"fixed2!"
	};
	STRING_LIST(camera_fx_parameter_flags_no_auto_adjust, camera_fx_parameter_flags_no_auto_adjust_strings, _countof(camera_fx_parameter_flags_no_auto_adjust_strings));

	STRINGS(camera_fx_parameter_flags_enabled)
	{
		"use default (ignore these values)",
		"maximum change is relative",
		"(unused)!",
		"bit3!",
		"fixed!",
		"enabled",
		"fixed2!"
	};
	STRING_LIST(camera_fx_parameter_flags_enabled, camera_fx_parameter_flags_enabled_strings, _countof(camera_fx_parameter_flags_enabled_strings));

	STRINGS(camera_fx_parameter_flags_bling_spikes)
	{
		"use default (ignore these values)",
		"maximum change is relative",
		"(unused)!",
		"double sided bling",
		"fixed!",
		"(unused2)!",
		"fixed2!"
	};
	STRING_LIST(camera_fx_parameter_flags_bling_spikes, camera_fx_parameter_flags_bling_spikes_strings, _countof(camera_fx_parameter_flags_bling_spikes_strings));

	TAG_REFERENCE(global_camera_fx_settings_reference, CAMERA_FX_SETTINGS_TAG);

} // namespace macaque

} // namespace blofeld

