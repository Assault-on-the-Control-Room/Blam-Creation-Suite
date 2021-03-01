#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		lens_flare_group,
		LENS_FLARE_TAG,
		nullptr,
		INVALID_TAG,
		lens_flare_block );

	TAG_BLOCK_FROM_STRUCT(
		lens_flare_block,
		"lens_flare_block",
		1,
		lens_flare_struct_definition);

	#define LENS_FLARE_REFLECTION_BLOCK_ID { 0xFBC30377, 0x4BFC46CA, 0x879F8A99, 0xBC0D240A }
	TAG_BLOCK(
		lens_flare_reflection_block,
		"reflection",
		k_maximum_reflections_per_lens_flare,
		"LensFlareReflection",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		LENS_FLARE_REFLECTION_BLOCK_ID)
	{
		// #TODO: Verify fields between beginning and unknown for Halo Reach
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_unknown_begin),

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_string_id, "name", FIELD_FLAG_INDEX },

		{ _field_word_flags, "flags", &lens_flare_reflection_flags_definition },
		{ _field_short_integer, "bitmap index" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_tag_reference, "bitmap override", &Tag::Reference<struct bitmap_group>::s_defaultDefinition },

		{ _field_real, "rotation offset", nullptr, "degrees" },
		{ _field_real, "axis offset", "percent offset in screen space along corona axis - 0.0 is on the corona, 1.0 is primary side edge of the screen, -1.0 is opposite side", "percent" },
		{ _field_real_bounds, "offset bounds", "the axis offset times corona offset is clamped between these values" },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 2 },
		{ _field_legacy, _field_real_bounds, "brightness bounds" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, },
		{ _field_struct, "radius curve", "interpolated by external input", &scalar_function_named_struct },

		{ _field_struct, "scale curve X", "interpolated by external input", &scalar_function_named_struct },
		{ _field_struct, "scale curve Y", "interpolated by external input", &scalar_function_named_struct },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_struct, "brightness curve", "interpolated by external input", &scalar_function_named_struct },

		FIELD_EXPLANATION("TINT COLOR", nullptr, FIELD_FLAG_NONE, "Tinting and modulating are not the same; \'tinting\' a reflection will color the darker regions but leave the highlights, while \'modulating\' will color everything uniformly. The modulation factor controls how much the reflection is modulated as opposed to tinted (0 is tinted, 1 is modulated). The tint power affects the curve of how much of the color range to tint."),

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_struct, "color curve", "interpolated by external input", &color_function_named_struct },

		{ _field_real_fraction, "modulation factor", nullptr, nullptr, "[0,1]" },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_real_rgb_color, "tint color" },

		{ _field_real, "tint power", nullptr, nullptr, "[0.1, 16]" },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_unknown_end),
		{ _field_terminator }
	};

	#define LENS_FLARE_SCALAR_ANIMATION_BLOCK_ID { 0x70D82126, 0xAABD40BB, 0xA37A03B0, 0x9D77D10B }
	TAG_BLOCK(
		lens_flare_scalar_animation_block,
		"lens_flare_scalar_animation_block",
		1,
		"c_function_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		LENS_FLARE_SCALAR_ANIMATION_BLOCK_ID)
	{
		{ _field_struct, "function", &scalar_function_named_struct },
		{ _field_terminator }
	};

	#define LENS_FLARE_COLOR_ANIMATION_BLOCK_ID { 0xA0B6D131, 0x2A634A2F, 0x8DD9CB77, 0x8BDC993A }
	TAG_BLOCK(
		lens_flare_color_animation_block,
		"lens_flare_color_animation_block",
		1,
		"s_editing_function",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		LENS_FLARE_COLOR_ANIMATION_BLOCK_ID)
	{
		{ _field_struct, "color animation", &lens_flare_color_function_struct },
		{ _field_terminator }
	};

	#define LENS_FLARE_STRUCT_DEFINITION_ID { 0xDA19E8C2, 0xEFC54593, 0xAB4A3192, 0x74E25FCB }
	TAG_STRUCT(
		lens_flare_struct_definition,
		"lens_flare_struct_definition",
		"s_lens_flare_definition",
		SET_UNKNOWN0 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | 
		SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		LENS_FLARE_STRUCT_DEFINITION_ID)
	{
		FIELD_EXPLANATION("LENS FLARE", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_angle, "falloff angle", nullptr, "degrees" },
		{ _field_angle, "cutoff angle", nullptr, "degrees" },
		FIELD_EXPLANATION("OCCLUSION", nullptr, FIELD_FLAG_NONE, "Occlusion factor affects overall lens flare brightness and can also affect scale. Occlusion never affects rotation."),

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_long_integer, "occlusion reflection index", "occlusion information will be generated against the size of this reflection" },

		{ _field_real, "occlusion offset distance", "distance along offset direction used to test occlusion", "world units" },
		{ _field_enum, "occlusion offset direction", &lens_flare_occlusion_offset_enum_definition },
		FIELD_PAD("PANTS", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real, "occlusion inner radius scale", "percent of the corona to occlude against (ie 0.25, 0.125, etc)" },
		{ _field_real, "near fade begin distance", "distance where the lens flare starts to fade in", "world units" },
		{ _field_real, "near fade end distance", "distance where the lens flare is fully faded in", "world units" },
		{ _field_real, "near fade distance", "distance at which the lens flare brightness is maximum", "world units" },
		{ _field_real, "far fade distance", "distance at which the lens flare brightness is minimum; set to zero to disable distance fading", "world units" },
		{ _field_tag_reference, "bitmap", &global_bitmap_reference },
		{ _field_word_flags, "flags", &lens_flare_flags_definition },
		{ _field_short_integer, "runtime flags", FIELD_FLAG_UNKNOWN0 },
		{ _field_enum, "rotation function", &lens_flare_corona_rotation_function_enum_definition },
		FIELD_PAD("WWZC", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_angle, "rotation function scale", nullptr, "degrees" },
		FIELD_EXPLANATION("EFFECT PARAMETERS", nullptr, FIELD_FLAG_NONE, "Only affects lens flares created by effects."),
		{ _field_enum, "falloff function", &global_reverse_transition_functions_enum },
		FIELD_PAD("COYUTLR", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_block, "reflections", &lens_flare_reflection_block },
		FIELD_EXPLANATION("ANIMATION", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_word_flags, "animation flags", &lens_flare_animation_flags_definition },
		FIELD_PAD("AQVC", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_block, "time brightness", &lens_flare_scalar_animation_block },
		{ _field_block, "age brightness", &lens_flare_scalar_animation_block },
		{ _field_block, "time color", &lens_flare_color_animation_block },
		{ _field_block, "age color", &lens_flare_color_animation_block },
		{ _field_block, "time rotation", &lens_flare_scalar_animation_block },
		{ _field_block, "age rotation", &lens_flare_scalar_animation_block },
		{ _field_terminator }
	};

	#define LENS_FLARE_COLOR_FUNCTION_STRUCT_ID { 0x3DBB7F1A, 0x54F94FD0, 0x9D24DA91, 0x297A3078 }
	TAG_STRUCT(
		lens_flare_color_function_struct,
		"lens_flare_color_function_struct",
		"s_editing_function",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		LENS_FLARE_COLOR_FUNCTION_STRUCT_ID)
	{
		{ _field_string_id, "Input Variable", FIELD_FLAG_UNKNOWN0, _field_id_function_input_scalar },
		{ _field_string_id, "Range Variable", FIELD_FLAG_UNKNOWN0, _field_id_function_input_range },
		{ _field_enum, "Output Modifier", FIELD_FLAG_UNKNOWN0, &output_mod_enum, _field_id_fnop },
		FIELD_PAD("BVCG1", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_string_id, "Output Modifier Input", FIELD_FLAG_UNKNOWN0, _field_id_function_output_modifier },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_default),
		{ _field_struct, "lens flare color mapping", &mapping_function },
		{ _field_terminator }
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

} // namespace macaque

} // namespace blofeld

