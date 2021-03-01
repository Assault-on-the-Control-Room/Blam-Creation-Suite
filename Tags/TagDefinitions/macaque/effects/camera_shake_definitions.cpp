#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		camera_shake_group,
		CAMERA_SHAKE_TAG,
		nullptr,
		INVALID_TAG,
		camera_shake_block );

	TAG_BLOCK_FROM_STRUCT(
		camera_shake_block,
		"camera_shake_block",
		1,
		camera_shake_struct_definition);

	#define GLOBAL_CAMERA_IMPULSE_BLOCK_ID { 0x57F39345, 0x0B824565, 0xA343C4B0, 0xFDAD9A47 }
	TAG_BLOCK(
		global_camera_impulse_block,
		"global_camera_impulse_block",
		1,
		"s_camera_impulse_globals",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		GLOBAL_CAMERA_IMPULSE_BLOCK_ID)
	{
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_default),
		{ _field_struct, "mapping", &mapping_function },
		{ _field_terminator }
	};

	#define CAMERA_SHAKE_STRUCT_DEFINITION_ID { 0x85B81D32, 0x7C1249A5, 0x863CDDB2, 0xA7052723 }
	TAG_STRUCT(
		camera_shake_struct_definition,
		"camera_shake_struct_definition",
		"s_camera_shake_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		CAMERA_SHAKE_STRUCT_DEFINITION_ID)
	{
		FIELD_EXPLANATION("camera impulse", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_struct, "camera impulse", &camera_impulse_struct },
		FIELD_EXPLANATION("camera shake", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_struct, "camera shake", &camera_shake_struct },
		{ _field_terminator }
	};

	#define CAMERA_IMPULSE_STRUCT_ID { 0xE55AD1CC, 0x22484F82, 0xAAEE9A87, 0xE60B4CDF }
	TAG_STRUCT(
		camera_impulse_struct,
		"camera_impulse_struct",
		"s_camera_impulse",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		CAMERA_IMPULSE_STRUCT_ID)
	{
		{ _field_real, "impulse duration", nullptr, "seconds" },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_default),
		{ _field_struct, "mapping", &mapping_function },
		{ _field_angle, "rotation", nullptr, "degrees" },
		{ _field_real, "pushback", nullptr, "world units" },
		{ _field_real_bounds, "jitter", nullptr, "world units" },
		{ _field_terminator }
	};

	#define CAMERA_SHAKE_STRUCT_ID { 0x21432949, 0x6E214B80, 0x8BD2D31B, 0x44AC9FAE }
	TAG_STRUCT(
		camera_shake_struct,
		"camera_shake_struct",
		"s_camera_shake",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		CAMERA_SHAKE_STRUCT_ID)
	{
		{ _field_real, "shake duration", "the effect will last for this duration.", "seconds" },
		FIELD_EXPLANATION("procedural camera shake", nullptr, FIELD_FLAG_NONE, ""),
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_default),
		{ _field_struct, "mapping", &mapping_function },
		{ _field_real, "random translation", "random translation in all directions", "world units" },
		{ _field_angle, "random rotation", "random rotation in all directions", "degrees" },
		{ _field_real, "wobble function period", nullptr, "seconds" },
		{ _field_real_fraction, "wobble weight", "a value of 0.0 signifies that the wobble function has no effect; a value of 1.0 the wobble function completely scales the translational\n and rotational magnitudes.  The less the weight, the less the effect wobble has." },
		{ _field_enum, "wobble function", "a function to perturb the effect's behavior over time", &global_periodic_functions_enum },
		FIELD_EXPLANATION("animated camera shake", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_char_enum, "animated shake playback", &animated_camera_shake_playback_type_enum },
		{ _field_char_enum, "animated shake weight", &animated_camera_shake_weight_type_enum },
		{ _field_tag_reference, "animation graph", &global_animation_graph_reference },
		{ _field_string_id, "animation name" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_real, "zoom penalty linear ", "multiplier penalty that increases linearly with zoom over 1" },
		{ _field_real, "zoom penalty squareroot ", "multiplier penalty that increases with square root of zoom over 1" },

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

} // namespace macaque

} // namespace blofeld

