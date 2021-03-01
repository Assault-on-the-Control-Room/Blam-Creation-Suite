#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_GROUP_FROM_BLOCK(lens_flare, LENS_FLARE_TAG, lens_flare_block_block );

	V5_TAG_BLOCK(lens_flare_reflection_block, k_maximum_reflections_per_lens_flare)
	{
		// #TODO: Verify fields between beginning and unknown for Halo Reach
		{ _field_legacy, _field_custom },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 1 },
		{ _field_legacy, _field_string_id, "name^" },

		{ _field_legacy, _field_word_flags, "flags", &lens_flare_reflection_flags_definition },
		{ _field_legacy, _field_short_integer, "bitmap index" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_legacy, _field_tag_reference, "bitmap override", &Tag::Reference<struct bitmap_group>::s_defaultDefinition },

		{ _field_legacy, _field_real, "rotation offset:degrees" },
		{ _field_legacy, _field_real, "axis offset:percent#percent offset in screen space along corona axis - 0.0 is on the corona, 1.0 is primary side edge of the screen, -1.0 is opposite side" },
		{ _field_legacy, _field_real_bounds, "offset bounds#the axis offset times corona offset is clamped between these values" },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 2 },
		{ _field_legacy, _field_real_bounds, "brightness bounds" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 1 },
		{ _field_legacy, _field_struct, "radius curve#interpolated by external input", &scalar_function_named_struct_struct_definition },

		{ _field_legacy, _field_struct, "scale curve X#interpolated by external input", &scalar_function_named_struct_struct_definition },
		{ _field_legacy, _field_struct, "scale curve Y#interpolated by external input", &scalar_function_named_struct_struct_definition },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_legacy, _field_struct, "brightness curve#interpolated by external input", &scalar_function_named_struct_struct_definition },

		{ _field_legacy, _field_explanation, "TINT COLOR", "Tinting and modulating are not the same; \'tinting\' a reflection will color the darker regions but leave the highlights, while \'modulating\' will color everything uniformly. The modulation factor controls how much the reflection is modulated as opposed to tinted (0 is tinted, 1 is modulated). The tint power affects the curve of how much of the color range to tint." },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_legacy, _field_struct, "color curve#interpolated by external input", &color_function_named_struct_struct_definition },
		
		{ _field_legacy, _field_real_fraction, "modulation factor:[0,1]" },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_real_rgb_color, "tint color" },

		{ _field_legacy, _field_real, "tint power:[0.1, 16]" },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(lens_flare_scalar_animation_block, 1)
	{
		{ _field_legacy, _field_struct, "function", &scalar_function_named_struct_struct_definition },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(lens_flare_color_animation_block, 1)
	{
		{ _field_legacy, _field_struct, "color animation", &lens_flare_color_function_struct_struct_definition },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK_FROM_STRUCT(lens_flare_block, 1, lens_flare_struct_definition_struct_definition );

	V5_TAG_STRUCT(lens_flare_struct_definition)
	{
		{ _field_legacy, _field_explanation, "LENS FLARE", "" },
		{ _field_legacy, _field_angle, "falloff angle:degrees" },
		{ _field_legacy, _field_angle, "cutoff angle:degrees" },
		{ _field_legacy, _field_explanation, "OCCLUSION", "Occlusion factor affects overall lens flare brightness and can also affect scale. Occlusion never affects rotation." },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_legacy, _field_long_integer, "occlusion reflection index#occlusion information will be generated against the size of this reflection" },
		
		{ _field_legacy, _field_real, "occlusion offset distance:world units#distance along offset direction used to test occlusion" },
		{ _field_legacy, _field_enum, "occlusion offset direction", &lens_flare_occlusion_offset_enum_definition },
		{ _field_legacy, _field_pad, "PANTS", 2 },
		{ _field_legacy, _field_real, "occlusion inner radius scale#percent of the corona to occlude against (ie 0.25, 0.125, etc)" },
		{ _field_legacy, _field_real, "near fade begin distance:world units#distance where the lens flare starts to fade in" },
		{ _field_legacy, _field_real, "near fade end distance:world units#distance where the lens flare is fully faded in" },
		{ _field_legacy, _field_real, "near fade distance:world units#distance at which the lens flare brightness is maximum" },
		{ _field_legacy, _field_real, "far fade distance:world units#distance at which the lens flare brightness is minimum; set to zero to disable distance fading" },
		{ _field_legacy, _field_tag_reference, "bitmap", &global_bitmap_reference },
		{ _field_legacy, _field_word_flags, "flags", &lens_flare_flags_definition },
		{ _field_legacy, _field_short_integer, "runtime flags!" },
		{ _field_legacy, _field_enum, "rotation function", &lens_flare_corona_rotation_function_enum_definition },
		{ _field_legacy, _field_pad, "WWZC", 2 },
		{ _field_legacy, _field_angle, "rotation function scale:degrees" },
		{ _field_legacy, _field_explanation, "EFFECT PARAMETERS", "Only affects lens flares created by effects." },
		{ _field_legacy, _field_enum, "falloff function", &global_reverse_transition_functions_enum },
		{ _field_legacy, _field_pad, "COYUTLR", 2 },
		{ _field_legacy, _field_block, "reflections", &lens_flare_reflection_block_block },
		{ _field_legacy, _field_explanation, "ANIMATION", "" },
		{ _field_legacy, _field_word_flags, "animation flags", &lens_flare_animation_flags_definition },
		{ _field_legacy, _field_pad, "AQVC", 2 },
		{ _field_legacy, _field_block, "time brightness", &lens_flare_scalar_animation_block_block },
		{ _field_legacy, _field_block, "age brightness", &lens_flare_scalar_animation_block_block },
		{ _field_legacy, _field_block, "time color", &lens_flare_color_animation_block_block },
		{ _field_legacy, _field_block, "age color", &lens_flare_color_animation_block_block },
		{ _field_legacy, _field_block, "time rotation", &lens_flare_scalar_animation_block_block },
		{ _field_legacy, _field_block, "age rotation", &lens_flare_scalar_animation_block_block },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_STRUCT(lens_flare_color_function_struct)
	{
		{ _field_legacy, _field_string_id, "Input Variable!" },
		{ _field_legacy, _field_string_id, "Range Variable!" },
		{ _field_legacy, _field_enum, "Output Modifier!", &output_mod_enum },
		{ _field_legacy, _field_pad, "BVCG1", 2 },
		{ _field_legacy, _field_string_id, "Output Modifier Input!" },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_struct, "lens flare color mapping", &mapping_function_struct_definition },
		{ _field_legacy, _field_terminator }
	};

	STRINGS(lens_flare_reflection_flags_definition)
	{
		"rotate from center of screen",
		"radius scaled by distance",
		"radius scaled by occlusion factor",
		"ignore external color",
		"lock to flare X",
		"lock to flare Y",
		"proximity to center as function input#The input to the curves below should be multiplied by 1 if at the center of the screen and 0 if at the edge",
		"mirror across flare#Also renders this reflection\'s mirror image across the flare center",
		"disabled for debugging",
		"flip U coordinate",
		"flip V coordinate",
		"draw in world space instead of screen space"
	};
	STRING_LIST(lens_flare_reflection_flags_definition, lens_flare_reflection_flags_definition_strings, _countof(lens_flare_reflection_flags_definition_strings));

	STRINGS(lens_flare_flags_definition)
	{
		"rotate occlusion testing box with lens flare#otherwise remains aligned with screen. turn on render_debug_lens_flares and look at green box",
		"no occlusion test",
		"only render in first person",
		"only render in third person",
		"use simple occlusion box test#ignore fancy occlusion box scaling - useful for very big or very far away lens flares (skybox flares, etc)",
		"no reflection opacity feedback#unchecked, each reflection evaluates its opacity from the previous reflection in the list",
		"scale by marker",
		"don\'t autofade#otherwise fade based on effect time, for effect attachments only",
		"don\'t render while zoomed"
	};
	STRING_LIST(lens_flare_flags_definition, lens_flare_flags_definition_strings, _countof(lens_flare_flags_definition_strings));

	STRINGS(lens_flare_occlusion_offset_enum_definition)
	{
		"toward viewer",
		"marker forward",
		"none"
	};
	STRING_LIST(lens_flare_occlusion_offset_enum_definition, lens_flare_occlusion_offset_enum_definition_strings, _countof(lens_flare_occlusion_offset_enum_definition_strings));

	STRINGS(lens_flare_corona_rotation_function_enum_definition)
	{
		"none",
		"rotation A",
		"rotation B",
		"rotation-translation",
		"translation"
	};
	STRING_LIST(lens_flare_corona_rotation_function_enum_definition, lens_flare_corona_rotation_function_enum_definition_strings, _countof(lens_flare_corona_rotation_function_enum_definition_strings));

	STRINGS(output_mod_enum)
	{
		" ",
		"Plus",
		"Times"
	};
	STRING_LIST(output_mod_enum, output_mod_enum_strings, _countof(output_mod_enum_strings));

	STRINGS(lens_flare_animation_flags_definition)
	{
		"synchronized"
	};
	STRING_LIST(lens_flare_animation_flags_definition, lens_flare_animation_flags_definition_strings, _countof(lens_flare_animation_flags_definition_strings));

	TAG_REFERENCE(global_lens_flare_reference, LENS_FLARE_TAG);

	TAG_REFERENCE(globalLensFlareReferenceNonResourceDependency, LENS_FLARE_TAG, _tag_reference_flag_not_a_resource_dependency);

} // namespace blofeld

