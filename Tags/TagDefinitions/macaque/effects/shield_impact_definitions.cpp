#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		shield_impact_group,
		SHIELD_IMPACT_TAG,
		nullptr,
		INVALID_TAG,
		shield_impact_block );

	TAG_BLOCK_FROM_STRUCT(
		shield_impact_block,
		"shield_impact_block",
		1,
		shield_impact_struct_definition);

	#define SHIELD_IMPACT_STRUCT_DEFINITION_ID { 0x0C627936, 0x3C6642FA, 0xAD2D41FD, 0x3F729B2F }
	TAG_STRUCT(
		shield_impact_struct_definition,
		"shield_impact_struct_definition",
		"s_shield_parameters",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SHIELD_IMPACT_STRUCT_DEFINITION_ID)
	{
		// H3, ODST. Based on Assembly definitions.
		// #TODO: merge shield_impact_struct definition versions
		{ _field_legacy, _field_version_less, _engine_type_haloreach, 27 },
		{ _field_legacy, _field_tag_reference, "Plasma Noise Texture 0", &Tag::Reference<struct bitmap_group>::s_defaultDefinition },
		{ _field_legacy, _field_tag_reference, "Plasma Noise Texture 1", &Tag::Reference<struct bitmap_group>::s_defaultDefinition },
		{ _field_legacy, _field_real, "Offset Amount" },
		{ _field_legacy, _field_real, "Tiling Scale" },
		{ _field_legacy, _field_real, "Scroll Speed" },
		{ _field_legacy, _field_explanation, "Layer 1" },
		{ _field_legacy, _field_real, "Edge Sharpness" },
		{ _field_legacy, _field_real, "Edge Radius" },
		{ _field_legacy, _field_real, "Edge Fade" },
		{ _field_legacy, _field_explanation, "Layer 2" },
		{ _field_legacy, _field_real, "Edge Sharpness" },
		{ _field_legacy, _field_real, "Edge Radius" },
		{ _field_legacy, _field_real, "Edge Fade" },
		{ _field_legacy, _field_explanation, "Overshield" },
		{ _field_legacy, _field_real_rgb_color, "Overshield Plasma Edge 1 Color" },
		{ _field_legacy, _field_real, "Overshield Plasma Edge 1 Intensity" },
		{ _field_legacy, _field_real_rgb_color, "Overshield Plasma Edge 2 Color" },
		{ _field_legacy, _field_real, "Overshield Plasma Edge 2 Intensity" },
		{ _field_legacy, _field_real_rgb_color, "Overshield Plasma Color" },
		{ _field_legacy, _field_real, "Overshield Plasma Intensity" },
		{ _field_legacy, _field_explanation, "Default Hit" },
		{ _field_legacy, _field_real_rgb_color, "Hit Plasma Edge 1 Color" },
		{ _field_legacy, _field_real, "Hit Plasma Edge 1 Intensity" },
		{ _field_legacy, _field_real_rgb_color, "Hit Plasma Edge 2 Color" },
		{ _field_legacy, _field_real, "Hit Plasma Edge 2 Intensity" },
		{ _field_legacy, _field_real_rgb_color, "Hit Plasma Color" },
		{ _field_legacy, _field_real, "Hit Plasma Intensity" },

		// Reach, H4
		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach, 48 },
		FIELD_EXPLANATION("Shield Controls", nullptr, FIELD_FLAG_NONE, "You can use the following variables as inputs to the functions here, in addition to any object variables\n    shield_vitality        percentage of shield remaining\n    shield_intensity       mixture of recent and current damage (see below)\n    current_shield_damage\n    recent_shield_damage\n"),
		{ _field_word_flags, "flags", &shield_flags },
		{ _field_short_integer, "version", FIELD_FLAG_UNKNOWN0 },
		FIELD_CUSTOM("Shield Intensity", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		FIELD_EXPLANATION("Shield Intensity", nullptr, FIELD_FLAG_NONE, "Shield intensity is a combination of recent damage and current damage.\nThese controls let you adjust the relative intensity contribution from each.\n\'shield_intensity\' can be used as an input to any of the animation function curves below."),
		{ _field_real, "Recent Damage Intensity" },
		{ _field_real, "Current Damage Intensity" },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		FIELD_CUSTOM("Shield Edge", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		FIELD_EXPLANATION("Shield Edge", nullptr, FIELD_FLAG_NONE, "These controls allow you to define the location and width of the shield edges.\nThe edge is faded as a function of the surface normal with respect to the camera.\nRadius 1.0 corresponds to the glancing edges of the surface (the silhouette edges).\nRadius 0.0 corresponds to the area of the surface directly facing the camera (the center).\nYou can control separately the inner and outer fades."),
		{ _field_real, "Depth Fade Range", nullptr, "world units" },
		{ _field_real, "Outer Fade Radius", nullptr, nullptr, "[0-1]" },
		{ _field_real, "Center Radius", nullptr, nullptr, "[0-1]" },
		{ _field_real, "Inner Fade Radius", nullptr, nullptr, "[0-1]" },
		{ _field_struct, "Edge Glow Color", &shield_color_function_struct },
		{ _field_struct, "Edge Glow Intensity", &shield_scalar_function_struct },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		FIELD_CUSTOM("Plasma", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		FIELD_EXPLANATION("Plasma", nullptr, FIELD_FLAG_NONE, "These controls allow you to define the appearance of the plasma effect.\nThe plasma is calculated using the standard formula (1-abs(tex0-tex1))^(sharpness).\nTiling scale controls the spatial tiling of the plasma textures.\nScroll speed controls how fast the textures scroll on the surface.\nYou can specify separate sharpness values for the edge and the center.\n"),
		{ _field_real, "Plasma Depth Fade Range", nullptr, "world units" },
		{ _field_tag_reference, "Plasma Noise Texture 0", &global_bitmap_reference },
		{ _field_tag_reference, "Plasma Noise Texture 1", &global_bitmap_reference },
		{ _field_real, "Tiling Scale" },
		{ _field_real, "Scroll Speed" },
		{ _field_real, "Edge Sharpness" },
		{ _field_real, "Center Sharpness" },
		{ _field_real, "Plasma Outer Fade Radius", nullptr, nullptr, "[0-1]" },
		{ _field_real, "Plasma Center Radius", nullptr, nullptr, "[0-1]" },
		{ _field_real, "Plasma Inner Fade Radius", nullptr, nullptr, "[0-1]" },
		{ _field_struct, "Plasma Center Color", &shield_color_function_struct },
		{ _field_struct, "Plasma Center Intensity", &shield_scalar_function_struct },
		{ _field_struct, "Plasma Edge Color", &shield_color_function_struct },
		{ _field_struct, "Plasma Edge Intensity", &shield_scalar_function_struct },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		FIELD_CUSTOM("Extrusion Oscillation", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		FIELD_EXPLANATION("Extrusion Oscillation", nullptr, FIELD_FLAG_NONE, "These controls allow you to define the oscillation in the extrusion.\nThese textures are tiled and scrolled in the xy and yz planes, and their red channel is applied as an offset to the extrusion\nTiling scale controls the spatial tiling of the plasma textures.\nScroll speed controls how fast the textures scroll on the surface.\nYou can specify separate sharpness values for the edge and the center.\n"),
		{ _field_tag_reference, "Oscillation Texture 0", &global_bitmap_reference },
		{ _field_tag_reference, "Oscillation Texture 1", &global_bitmap_reference },
		{ _field_real, "Oscillation Tiling Scale" },
		{ _field_real, "Oscillation Scroll Speed" },
		{ _field_struct, "Extrusion Amount", &shield_scalar_function_struct },
		{ _field_struct, "Oscillation Amplitude", &shield_scalar_function_struct },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		FIELD_CUSTOM("Hit Response", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		FIELD_EXPLANATION("Hit Response", nullptr, FIELD_FLAG_NONE, "These controls allow you to define the color variation in the area surrounding projectile impacts.\nYou can control the color, and the size of the colored area.\nThe default input is time since impact.\n"),
		{ _field_real, "Hit Time", nullptr, "seconds" },
		{ _field_struct, "Hit Color", &shield_color_function_struct },
		{ _field_struct, "Hit Intensity", &shield_scalar_function_struct },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 3 },
		{ _field_struct, "Hit Radius", &shield_scalar_function_struct },
		{ _field_tag_reference, "hit blob texture (adds significant cost)", &Tag::Reference<struct bitmap_group>::s_defaultDefinition },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach, 4 },
		{ _field_real_quaternion, "edge_scales", FIELD_FLAG_UNKNOWN0 },
		{ _field_real_quaternion, "edge_offsets", FIELD_FLAG_UNKNOWN0 },
		{ _field_real_quaternion, "plasma_scales", FIELD_FLAG_UNKNOWN0 },
		{ _field_real_quaternion, "depth_fade_params", FIELD_FLAG_UNKNOWN0 },

		{ _field_terminator }
	};

	#define SHIELD_COLOR_FUNCTION_STRUCT_ID { 0xBDAC1B15, 0x794F4ADF, 0xA4DE2E70, 0x63BBFA9F }
	TAG_STRUCT(
		shield_color_function_struct,
		"shield_color_function_struct",
		"s_shield_function",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SHIELD_COLOR_FUNCTION_STRUCT_ID)
	{
		{ _field_string_id, "Input Variable", FIELD_FLAG_UNKNOWN0, _field_id_function_input_scalar },
		{ _field_string_id, "Range Variable", FIELD_FLAG_UNKNOWN0, _field_id_function_input_range },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_default),
		{ _field_struct, "Mapping", &mapping_function },
		{ _field_terminator }
	};

	#define SHIELD_SCALAR_FUNCTION_STRUCT_ID { 0xEFDDC631, 0xEAB14736, 0x9C10734E, 0x609E19A3 }
	TAG_STRUCT(
		shield_scalar_function_struct,
		"shield_scalar_function_struct",
		"s_shield_function",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SHIELD_SCALAR_FUNCTION_STRUCT_ID)
	{
		{ _field_string_id, "Input Variable", FIELD_FLAG_UNKNOWN0, _field_id_function_input_scalar },
		{ _field_string_id, "Range Variable", FIELD_FLAG_UNKNOWN0, _field_id_function_input_range },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_default),
		{ _field_struct, "Mapping", &mapping_function },
		{ _field_terminator }
	};

	STRINGS(shield_flags)
	{
		"render always",
		"render first person",
		"dont render third person"
	};
	STRING_LIST(shield_flags, shield_flags_strings, _countof(shield_flags_strings));

	TAG_REFERENCE(global_shield_parameters_reference, SHIELD_IMPACT_TAG);

} // namespace macaque

} // namespace blofeld

