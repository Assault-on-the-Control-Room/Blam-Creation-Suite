#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(atmosphere_globals, ATMOSPHERE_GLOBALS_TAG, atmosphere_globals_block_block );

	TAG_BLOCK(underwater_setting_block, k_max_atmosphere_settings)
	{
		{ _field_string_id, "Name" },
		{ _field_real, "Murkiness" },
		{ _field_real_rgb_color, "Fog Color" },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(atmosphere_globals_block, 1, atmosphere_globals_struct_definition_struct_definition );

	TAG_STRUCT(atmosphere_globals_struct_definition)
	{
		{ _field_explanation, "Patchy Fog Global Parameters", "Fog Bitmap................Noise texture to use on the screen-aligned sheets of fog\nTexture repeat rate.......Scaling factor to apply to fog UV coordinates\nDistance between sheets...Separating distance between sheets of fog\nDepth fade factor.........Lower values (approaching 0) cause a smoother fade at scene boundaries. Larger values (1 or more) make for a sharp transition\n\nFalloff start distance....Distance (in world units) at which to begin fading out patchy fog (default: 5)\nDistance falloff power....Rate at which to begin attenuating patchy fog settings (default: 2)\nTransparent sort distance..Distance from the camera where we sort the patchy fog effect (default: 100)\nwind strength across distance..Multiplies the wind strength based upon distance from player\n\n" },
		{ _field_tag_reference, "Fog Bitmap", &global_bitmap_reference },
		{ _field_real, "Texture repeat rate" },
		{ _field_real, "Distance between sheets" },
		{ _field_real, "Depth fade factor" },
		{ _field_real, "Transparent sort distance" },
		{ _field_char_enum, "Transparent sort layer", &global_sort_layer_enum_defintion },
		{ _field_pad, "UNdfdfdSED", 3 },
		
		{ _field_version_greater, _engine_type_haloreach },
		{ _field_struct, "wind strength across distance", &scalar_function_named_struct_default_one_struct_definition },
		
		{ _field_block, "underwater settings", &underwater_setting_block_block },
		{ _field_terminator }
	};

	TAG_REFERENCE(global_atmosphere_globals_reference, ATMOSPHERE_GLOBALS_TAG);

} // namespace blofeld

