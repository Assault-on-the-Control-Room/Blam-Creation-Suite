#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(shield_impact, SHIELD_IMPACT_TAG, shield_impact_block_block );

	TAG_BLOCK_FROM_STRUCT(shield_impact_block, 1, shield_impact_struct_definition_struct_definition );

	TAG_STRUCT(shield_impact_struct_definition)
	{
		{ _field_explanation, "Shield Controls", "You can use the following variables as inputs to the functions here, in addition to any object variables\n    shield_vitality        percentage of shield remaining\n    shield_intensity       mixture of recent and current damage (see below)\n    current_shield_damage\n    recent_shield_damage\n" },
		{ _field_word_flags, "flags", &shield_flags },
		{ _field_short_integer, "version!" },
		{ _field_custom, "Shield Intensity" },
		{ _field_explanation, "Shield Intensity", "Shield intensity is a combination of recent damage and current damage.\nThese controls let you adjust the relative intensity contribution from each.\n\'shield_intensity\' can be used as an input to any of the animation function curves below." },
		{ _field_real, "Recent Damage Intensity" },
		{ _field_real, "Current Damage Intensity" },
		{ _field_custom },
		{ _field_custom, "Shield Edge" },
		{ _field_explanation, "Shield Edge", "These controls allow you to define the location and width of the shield edges.\nThe edge is faded as a function of the surface normal with respect to the camera.\nRadius 1.0 corresponds to the glancing edges of the surface (the silhouette edges).\nRadius 0.0 corresponds to the area of the surface directly facing the camera (the center).\nYou can control separately the inner and outer fades." },
		{ _field_real, "Depth Fade Range:world units" },
		{ _field_real, "Outer Fade Radius:[0-1]" },
		{ _field_real, "Center Radius:[0-1]" },
		{ _field_real, "Inner Fade Radius:[0-1]" },
		{ _field_struct, "Edge Glow Color", &shield_color_function_struct_struct_definition },
		{ _field_struct, "Edge Glow Intensity", &shield_scalar_function_struct_struct_definition },
		{ _field_custom },
		{ _field_custom, "Plasma" },
		{ _field_explanation, "Plasma", "These controls allow you to define the appearance of the plasma effect.\nThe plasma is calculated using the standard formula (1-abs(tex0-tex1))^(sharpness).\nTiling scale controls the spatial tiling of the plasma textures.\nScroll speed controls how fast the textures scroll on the surface.\nYou can specify separate sharpness values for the edge and the center.\n" },
		{ _field_real, "Plasma Depth Fade Range:world units" },
		{ _field_tag_reference, "Plasma Noise Texture 0", &global_bitmap_reference },
		{ _field_tag_reference, "Plasma Noise Texture 1", &global_bitmap_reference },
		{ _field_real, "Tiling Scale" },
		{ _field_real, "Scroll Speed" },
		{ _field_real, "Edge Sharpness" },
		{ _field_real, "Center Sharpness" },
		{ _field_real, "Plasma Outer Fade Radius:[0-1]" },
		{ _field_real, "Plasma Center Radius:[0-1]" },
		{ _field_real, "Plasma Inner Fade Radius:[0-1]" },
		{ _field_struct, "Plasma Center Color", &shield_color_function_struct_struct_definition },
		{ _field_struct, "Plasma Center Intensity", &shield_scalar_function_struct_struct_definition },
		{ _field_struct, "Plasma Edge Color", &shield_color_function_struct_struct_definition },
		{ _field_struct, "Plasma Edge Intensity", &shield_scalar_function_struct_struct_definition },
		{ _field_custom },
		{ _field_custom, "Extrusion Oscillation" },
		{ _field_explanation, "Extrusion Oscillation", "These controls allow you to define the oscillation in the extrusion.\nThese textures are tiled and scrolled in the xy and yz planes, and their red channel is applied as an offset to the extrusion\nTiling scale controls the spatial tiling of the plasma textures.\nScroll speed controls how fast the textures scroll on the surface.\nYou can specify separate sharpness values for the edge and the center.\n" },
		{ _field_tag_reference, "Oscillation Texture 0", &global_bitmap_reference },
		{ _field_tag_reference, "Oscillation Texture 1", &global_bitmap_reference },
		{ _field_real, "Oscillation Tiling Scale" },
		{ _field_real, "Oscillation Scroll Speed" },
		{ _field_struct, "Extrusion Amount", &shield_scalar_function_struct_struct_definition },
		{ _field_struct, "Oscillation Amplitude", &shield_scalar_function_struct_struct_definition },
		{ _field_custom },
		{ _field_custom, "Hit Response" },
		{ _field_explanation, "Hit Response", "These controls allow you to define the color variation in the area surrounding projectile impacts.\nYou can control the color, and the size of the colored area.\nThe default input is time since impact.\n" },
		{ _field_real, "Hit Time:seconds" },
		{ _field_struct, "Hit Color", &shield_color_function_struct_struct_definition },
		{ _field_struct, "Hit Intensity", &shield_scalar_function_struct_struct_definition },

		{ _field_version_greater, _engine_type_haloreach, 3 },
		{ _field_struct, "Hit Radius", &shield_scalar_function_struct_struct_definition },
		{ _field_tag_reference, "hit blob texture (adds significant cost)", &Tag::Reference<struct bitmap_group>::s_defaultDefinition },
		{ _field_custom },

		{ _field_real_quaternion, "edge_scales!" },
		{ _field_real_quaternion, "edge_offsets!" },
		{ _field_real_quaternion, "plasma_scales!" },
		{ _field_real_quaternion, "depth_fade_params!" },
		{ _field_terminator }
	};

	TAG_STRUCT(shield_color_function_struct)
	{
		{ _field_string_id, "Input Variable!" },
		{ _field_string_id, "Range Variable!" },
		{ _field_custom },
		{ _field_struct, "Mapping", &mapping_function_struct_definition },
		{ _field_terminator }
	};

	TAG_STRUCT(shield_scalar_function_struct)
	{
		{ _field_string_id, "Input Variable!" },
		{ _field_string_id, "Range Variable!" },
		{ _field_custom },
		{ _field_struct, "Mapping", &mapping_function_struct_definition },
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

} // namespace blofeld

