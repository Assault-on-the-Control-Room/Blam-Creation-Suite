#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP(camera_fx_settings, CAMERA_FX_SETTINGS_TAG)
	{
		{ _field_custom },
		{ _field_struct, "exposure", &camera_fx_exposure_struct_struct_definition },
		{ _field_struct, "auto_exposure_sensitivity", &camera_fx_exposure_sensitivity_struct_struct_definition },
		{ _field_struct, "bloom_highlight{bloom_point}", &camera_fx_bloom_highlight_struct_struct_definition },
		{ _field_struct, "bloom_inherent", &camera_fx_bloom_inherent_struct_struct_definition },

		{ _field_version_greater, _engine_type_haloreach },
		{ _field_struct, "bloom_self_illum", &camera_fx_bloom_self_illum_struct_struct_definition },

		{ _field_struct, "bloom_intensity", &camera_fx_bloom_intensity_struct_struct_definition },
		{ _field_struct, "bloom_large_color", &camera_fx_bloom_large_color_struct_struct_definition },
		{ _field_struct, "bloom_medium_color", &camera_fx_bloom_medium_color_struct_struct_definition },
		{ _field_struct, "bloom_small_color", &camera_fx_bloom_small_color_struct_struct_definition },
		{ _field_struct, "bling_intensity!", &camera_fx_bling_intensity_struct_struct_definition },
		{ _field_struct, "bling_size!", &camera_fx_bling_size_struct_struct_definition },
		{ _field_struct, "bling_angle!", &camera_fx_bling_angle_struct_struct_definition },
		{ _field_struct, "bling_count!", &camera_fx_bling_count_struct_struct_definition },
		{ _field_struct, "self_illum_preferred", &camera_fx_self_illum_preferred_struct_struct_definition },
		{ _field_struct, "self_illum_scale", &camera_fx_self_illum_scale_struct_struct_definition },

		{ _field_version_greater, _engine_type_haloreach, 3 },
		{ _field_struct, "color_grading", &camera_fx_color_grading_struct_struct_definition },
		{ _field_struct, "filmic_tone_curve", &camera_fx_filmic_tone_curve_struct_struct_definition },
		{ _field_custom },

		{ _field_terminator }
	};

	TAG_STRUCT(camera_fx_exposure_struct)
	{
		{ _field_custom },
		{ _field_explanation, "EXPOSURE", "Controls the brightness of the scene, like exposure time on your camera.\nThe actual exposure always blends towards the target exposure.\nWith auto-exposure on, the target exposure is calculated relative to the brightness of what is on screen.\n" },
		{ _field_word_flags, "flags", &camera_fx_parameter_flags_auto_adjust },
		{ _field_pad, "MKRGRF", 2 },
		{ _field_real, "exposure:stops#the target exposure (ONLY USED WHEN AUTO-EXPOSURE IS OFF)" },
		{ _field_real, "maximum change:stops#the maximum allowed change in exposure between frames" },
		{ _field_real, "blend speed (0-1):percent per frame#1 is instantaneous, 0.01 is a good speed, 0.001 is slower" },
		{ _field_real, "minimum:stops#the absolute target exposure is clamped to this range" },
		{ _field_real, "maximum:stops#the absolute target exposure is clamped to this range" },
		{ _field_custom },
		{ _field_real, "auto-exposure screen brightness:[0.0001-1]#how bright you want the screen to be - auto-exposure will make it happen" },
		{ _field_custom },
		{ _field_real, "auto-exposure delay:[0.1-1]seconds#how long to wait before auto-exposure kicks in to adjust the exposure" },
		{ _field_custom },
		{ _field_terminator }
	};

	TAG_STRUCT(camera_fx_exposure_sensitivity_struct)
	{
		{ _field_explanation, "AUTO EXPOSURE SENSITIVITY", "How sensitive auto exposure is to small bright patches on the screen (like the sun)" },
		{ _field_word_flags, "flags", &camera_fx_parameter_flags_no_auto_adjust },
		{ _field_pad, "MAKAMAKAHEY", 2 },
		{ _field_real, "sensitivity (0-1)" },
		{ _field_terminator }
	};

	TAG_STRUCT(camera_fx_bloom_highlight_struct)
	{
		{ _field_explanation, "HIGHLIGHT BLOOM", "These parameters control bloom off the highlights (really bright stuff)" },
		{ _field_word_flags, "flags", &camera_fx_parameter_flags_no_auto_adjust },
		{ _field_pad, "LOTPRER", 2 },
		{ _field_real, "highlight bloom{bloom point}" },
		{ _field_real, "maximum change" },
		{ _field_real, "blend speed (0-1)" },
		{ _field_terminator }
	};

	TAG_STRUCT(camera_fx_bloom_inherent_struct)
	{
		{ _field_explanation, "INHERENT BLOOM", "These parameters control bloom off everything (bright and dark)" },
		{ _field_word_flags, "flags", &camera_fx_parameter_flags_no_auto_adjust },
		{ _field_pad, "ERIRLE", 2 },
		{ _field_real, "inherent bloom" },
		{ _field_real, "maximum change" },
		{ _field_real, "blend speed (0-1)" },
		{ _field_terminator }
	};

	TAG_STRUCT(camera_fx_bloom_self_illum_struct)
	{
		{ _field_explanation, "SELF-ILLUM BLOOM", "These parameters control off of self-illum pixels" },
		{ _field_word_flags, "flags", &camera_fx_parameter_flags_no_auto_adjust },
		{ _field_pad, "ERIRLE", 2 },
		{ _field_real, "self-illum bloom bloom" },
		{ _field_real, "maximum change" },
		{ _field_real, "blend speed (0-1)" },
		{ _field_terminator }
	};

	TAG_STRUCT(camera_fx_bloom_intensity_struct)
	{
		{ _field_explanation, "BLOOM INTENSITY", "These parameters control how bright the bloom is, relative to the underlying scene" },
		{ _field_word_flags, "flags", &camera_fx_parameter_flags_no_auto_adjust },
		{ _field_pad, "SEMIFMD", 2 },
		{ _field_real, "bloom intensity" },
		{ _field_real, "maximum change" },
		{ _field_real, "blend speed (0-1)" },
		{ _field_terminator }
	};

	TAG_STRUCT(camera_fx_bloom_large_color_struct)
	{
		{ _field_explanation, "BLOOM LARGE COLOR", "These parameters control the color of the large bloom" },
		{ _field_word_flags, "flags", &camera_fx_parameter_flags_no_auto_adjust },
		{ _field_pad, "KKROFI", 2 },
		{ _field_real_rgb_color, "large color" },
		{ _field_terminator }
	};

	TAG_STRUCT(camera_fx_bloom_medium_color_struct)
	{
		{ _field_explanation, "BLOOM MEDIUM COLOR", "These parameters control the color of the medium bloom" },
		{ _field_word_flags, "flags", &camera_fx_parameter_flags_no_auto_adjust },
		{ _field_pad, "LEORPP", 2 },
		{ _field_real_rgb_color, "medium color" },
		{ _field_terminator }
	};

	TAG_STRUCT(camera_fx_bloom_small_color_struct)
	{
		{ _field_explanation, "BLOOM SMALL COLOR", "These parameters control the color of the small bloom" },
		{ _field_word_flags, "flags", &camera_fx_parameter_flags_no_auto_adjust },
		{ _field_pad, "JSIRWSFGAOD", 2 },
		{ _field_real_rgb_color, "small color" },
		{ _field_terminator }
	};

	TAG_STRUCT(camera_fx_bling_intensity_struct)
	{
		{ _field_word_flags, "flags!", &camera_fx_parameter_flags_no_auto_adjust },
		{ _field_pad, "QREWRER", 2 },
		{ _field_real, "bling intensity!" },
		{ _field_real, "maximum change!" },
		{ _field_real, "blend speed (0-1)!" },
		{ _field_terminator }
	};

	TAG_STRUCT(camera_fx_bling_size_struct)
	{
		{ _field_word_flags, "flags!", &camera_fx_parameter_flags_no_auto_adjust },
		{ _field_pad, "LSDFPO", 2 },
		{ _field_real, "bling length!" },
		{ _field_real, "maximum change!" },
		{ _field_real, "blend speed (0-1)!" },
		{ _field_terminator }
	};

	TAG_STRUCT(camera_fx_bling_angle_struct)
	{
		{ _field_word_flags, "flags!", &camera_fx_parameter_flags_no_auto_adjust },
		{ _field_pad, "ILJS", 2 },
		{ _field_real, "bling angle!" },
		{ _field_real, "maximum change!" },
		{ _field_real, "blend speed (0-1)!" },
		{ _field_terminator }
	};

	TAG_STRUCT(camera_fx_bling_count_struct)
	{
		{ _field_word_flags, "flags!", &camera_fx_parameter_flags_bling_spikes },
		{ _field_short_integer, "bling spikes!" },
		{ _field_terminator }
	};

	TAG_STRUCT(camera_fx_self_illum_preferred_struct)
	{
		{ _field_explanation, "SELF ILLUM EXPOSURE", "These parameters control the self-illumination exposure\npreferred is the preferred exposure, and scale controls\nhow much it varies from the preferred exposure" },
		{ _field_word_flags, "flags", &camera_fx_parameter_flags_no_auto_adjust },
		{ _field_pad, "JJFJFJKE", 2 },
		{ _field_real, "preferred exposure:stops#the preferred exposure for self illum" },
		{ _field_real, "maximum change" },
		{ _field_real, "blend speed (0-1)" },
		{ _field_terminator }
	};

	TAG_STRUCT(camera_fx_self_illum_scale_struct)
	{
		{ _field_explanation, "SELF ILLUM CHANGE", "How much self illum exposure is allowed to change\n0 means no change at all, 1 means it will\nequal the normal exposure" },
		{ _field_word_flags, "flags", &camera_fx_parameter_flags_no_auto_adjust },
		{ _field_pad, "WOOGATCHOU", 2 },
		{ _field_real, "exposure change:[0-1]#how much the self illum is allowed to change, as a percentage of the normal exposure change" },
		{ _field_real, "maximum change" },
		{ _field_real, "blend speed (0-1)" },
		{ _field_terminator }
	};

	TAG_STRUCT(camera_fx_color_grading_struct)
	{
		{ _field_explanation, "Color Grading", "set the color grading texture" },
		{ _field_word_flags, "flags", &camera_fx_parameter_flags_no_auto_adjust },
		{ _field_pad, "SKHFDNV", 2 },
		{ _field_tag_reference, "color grading texture", &global_bitmap_reference },
		{ _field_terminator }
	};

	TAG_STRUCT(camera_fx_filmic_tone_curve_struct)
	{
		{ _field_explanation, "Filmic Tone Curve", "set the values for the filmic tone curve" },
		{ _field_word_flags, "flags", &camera_fx_parameter_flags_enabled },
		{ _field_pad, "MKRGRF", 2 },
		{ _field_real, "shoulder strength#How intense the shoulder is" },
		{ _field_real, "linear strength#How intense the linear portion is" },
		{ _field_real, "linear angle#Angle of linear portion of curve" },
		{ _field_real, "toe strength#How intense the toe is" },
		{ _field_real, "toe numerator#Numerator of toe slope" },
		{ _field_real, "toe denominator#Denominator of toe slope" },
		{ _field_real, "linear white point#The white point in linear space" },
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

} // namespace blofeld

