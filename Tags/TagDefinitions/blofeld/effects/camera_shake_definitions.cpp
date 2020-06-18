#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(camera_shake, CAMERA_SHAKE_TAG, camera_shake_block_block );

	TAG_BLOCK_FROM_STRUCT(camera_shake_block, 1, camera_shake_struct_definition_struct_definition );

	TAG_BLOCK(global_camera_impulse_block, 1)
	{
		{ _field_custom },
		{ _field_struct, "mapping", &mapping_function_struct_definition },
		{ _field_terminator }
	};

	TAG_STRUCT(camera_shake_struct_definition)
	{
		{ _field_explanation, "camera impulse", "" },
		{ _field_struct, "camera impulse", &camera_impulse_struct_struct_definition },
		{ _field_explanation, "camera shake", "" },
		{ _field_struct, "camera shake", &camera_shake_struct_struct_definition },
		{ _field_terminator }
	};

	TAG_STRUCT(camera_impulse_struct)
	{
		{ _field_real, "impulse duration:seconds" },
		{ _field_custom },
		{ _field_struct, "mapping", &mapping_function_struct_definition },
		{ _field_angle, "rotation:degrees" },
		{ _field_real, "pushback:world units" },
		{ _field_real_bounds, "jitter:world units" },
		{ _field_terminator }
	};

	TAG_STRUCT(camera_shake_struct)
	{
		{ _field_real, "shake duration:seconds#the effect will last for this duration." },
		{ _field_explanation, "procedural camera shake", "" },
		{ _field_custom },
		{ _field_struct, "mapping", &mapping_function_struct_definition },
		{ _field_real, "random translation:world units#random translation in all directions" },
		{ _field_angle, "random rotation:degrees#random rotation in all directions" },
		{ _field_real, "wobble function period:seconds" },
		{ _field_real_fraction, "wobble weight#a value of 0.0 signifies that the wobble function has no effect; a value of 1.0 the wobble function completely scales the translational\n and rotational magnitudes.  The less the weight, the less the effect wobble has." },
		{ _field_enum, "wobble function#a function to perturb the effect\'s behavior over time", &global_periodic_functions_enum },
		{ _field_explanation, "animated camera shake", "" },
		{ _field_char_enum, "animated shake playback", &animated_camera_shake_playback_type_enum },
		{ _field_char_enum, "animated shake weight", &animated_camera_shake_weight_type_enum },
		{ _field_tag_reference, "animation graph", &global_animation_graph_reference },
		{ _field_string_id, "animation name" },

		{ _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_real, "zoom penalty linear #multiplier penalty that increases linearly with zoom over 1" },
		{ _field_real, "zoom penalty squareroot #multiplier penalty that increases with square root of zoom over 1" },
		
		{ _field_terminator }
	};

	STRINGS(animated_camera_shake_playback_type_enum)
	{
		"looping",
		"frame ratio"
	};
	STRING_LIST(animated_camera_shake_playback_type_enum, animated_camera_shake_playback_type_enum_strings, _countof(animated_camera_shake_playback_type_enum_strings));

	STRINGS(animated_camera_shake_weight_type_enum)
	{
		"effect scale",
		"full"
	};
	STRING_LIST(animated_camera_shake_weight_type_enum, animated_camera_shake_weight_type_enum_strings, _countof(animated_camera_shake_weight_type_enum_strings));

	TAG_REFERENCE(global_camera_shake_reference, CAMERA_SHAKE_TAG);

} // namespace blofeld

