#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		damage_response_definition_group,
		DAMAGE_RESPONSE_DEFINITION_TAG,
		nullptr,
		INVALID_TAG,
		damage_response_definition_block );

	TAG_BLOCK_FROM_STRUCT(
		damage_response_definition_block,
		"damage_response_definition_block",
		1,
		damage_response_definition_struct_definition);

	#define DAMAGE_RESPONSE_CLASS_BLOCK_ID { 0x4B0239EB, 0xE7E44E9F, 0x9A3C8635, 0xA660F69B }
	TAG_BLOCK(
		damage_response_class_block,
		"damage_response_class_block",
		2,
		"s_damage_response_class_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		DAMAGE_RESPONSE_CLASS_BLOCK_ID)
	{
		{ _field_enum, "type", &damage_response_class_type_enum },
		{ _field_word_flags, "flags", &damage_response_class_flags },
		FIELD_EXPLANATION("directional flash", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_struct, "directional flash", &damage_response_directional_flash_struct },
		FIELD_EXPLANATION("motion sensor ping", nullptr, FIELD_FLAG_NONE, "WARNING \'motion sensor ping\' section no longer functions post CHUD-2-CUI switchover!"),
		{ _field_struct, "motion sensor ping", &damage_response_motion_sensor_ping },
		FIELD_EXPLANATION("rumble", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_tag_reference, "rumble", MAKE_OLD_NAMES("rumble data"), &global_rumble_reference },
		FIELD_EXPLANATION("camera shake and impulse data", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_tag_reference, "camera shake", MAKE_OLD_NAMES("camera shake data"), &global_camera_shake_reference },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_tag_reference, "camera shake zoomed", "falls back on camerashake if untuned", MAKE_OLD_NAMES("camera shake data"), &global_camera_shake_reference },

		FIELD_EXPLANATION("simulated input", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_tag_reference, "simulated_input", &global_simulated_input_reference },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_tag_reference, "simulated_input zoomed ", "falls back on simulated input if untuned", &global_simulated_input_reference },

		FIELD_EXPLANATION("global sound effect", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_block, "global sound effect", &damage_response_global_sound_effect_block },
		{ _field_terminator }
	};

	#define DAMAGE_RESPONSE_GLOBAL_SOUND_EFFECT_BLOCK_STRUCT_ID { 0xD8AF888D, 0x5DA54554, 0x80FA8203, 0xC96EED16 }
	TAG_BLOCK(
		damage_response_global_sound_effect_block,
		"damage_response_global_sound_effect_block",
		1,
		"s_damage_response_global_sound_effect_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		DAMAGE_RESPONSE_GLOBAL_SOUND_EFFECT_BLOCK_STRUCT_ID)
	{
		{ _field_string_id, "effect name" },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_default),
		{ _field_struct, "scale => duration", nullptr, "seconds", &mapping_function },
		{ _field_terminator }
	};

	#define AREA_CONTROL_BLOCK_STRUCT_ID { 0x865D9C15, 0x26384F67, 0x8F336B17, 0xE28A73DE }
	TAG_BLOCK(
		area_control_block,
		"area_control_block",
		1,
		"s_area_control_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		AREA_CONTROL_BLOCK_STRUCT_ID)
	{
		FIELD_EXPLANATION("AREA CONTROL", nullptr, FIELD_FLAG_NONE, "Higher level scale controls for camera shake, camera impulse and rumble."),
		{ _field_word_flags, "flags", &area_control_flags },
		FIELD_PAD("DRCS", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_EXPLANATION("Distance Falloff", nullptr, FIELD_FLAG_NONE, "controls the maximum distance and the distance falloff of this effect\nNOTE: not used for scenario global effects"),
		{ _field_real, "maximum distance", "the maximum distance this player feedback will affect", "world units" },
		{ _field_struct, "distance falloff", &area_control_scalar_function_struct },
		FIELD_EXPLANATION("Angle Falloff", nullptr, FIELD_FLAG_NONE, "controls the falloff of this effect based on how close you are to looking directly at it\nNOTE: not used for scenario global effects"),
		{ _field_struct, "angle falloff", &area_control_scalar_function_struct },
		FIELD_EXPLANATION("Object Falloff", nullptr, FIELD_FLAG_NONE, "applies a falloff based on an object function - ignored if the effect is not attached to an object"),
		{ _field_struct, "object falloff", &area_control_scalar_object_function_struct },
		{ _field_terminator }
	};

	#define DAMAGE_RESPONSE_DEFINITION_STRUCT_DEFINITION_ID { 0x94C849C2, 0x81F94875, 0x8B4DD2B0, 0x54CD47EF }
	TAG_STRUCT(
		damage_response_definition_struct_definition,
		"damage_response_definition_struct_definition",
		"s_damage_response_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		DAMAGE_RESPONSE_DEFINITION_STRUCT_DEFINITION_ID)
	{
		{ _field_block, "classes", &damage_response_class_block },
		{ _field_block, "area control", &area_control_block, _field_id_slap },
		{ _field_terminator }
	};

	#define DAMAGE_RESPONSE_DIRECTIONAL_FLASH_STRUCT_ID { 0xD18EB7B1, 0xE169416F, 0xB5CA99B6, 0xC316A290 }
	TAG_STRUCT(
		damage_response_directional_flash_struct,
		"damage_response_directional_flash_struct",
		"s_damage_response_directional_flash_definition",
		SET_POSTPROCESS_RECURSIVELY | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		DAMAGE_RESPONSE_DIRECTIONAL_FLASH_STRUCT_ID)
	{
		{ _field_real, "indicator duration" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_real, "flash duration ", MAKE_OLD_NAMES("duration") },

		{ _field_enum, "fade function", &global_reverse_transition_functions_enum },
		FIELD_PAD("ZASSFACE", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real, "center size" },
		{ _field_real, "offscreen size", MAKE_OLD_NAMES("size") },
		{ _field_real, "center alpha" },
		{ _field_real, "offscreen alpha" },
		{ _field_real, "inner alpha", MAKE_OLD_NAMES("inner scale") },
		{ _field_real, "outer alpha", MAKE_OLD_NAMES("outer scale") },
		{ _field_real_argb_color, "flash color" },
		{ _field_real_argb_color, "arrow color" },
		{ _field_terminator }
	};

	#define DAMAGE_RESPONSE_MOTION_SENSOR_PING_ID { 0x3D5CCA56, 0x0D294C20, 0x8FA7FDB2, 0x012D1CBE }
	TAG_STRUCT(
		damage_response_motion_sensor_ping,
		"damage_response_motion_sensor_ping",
		"s_damage_response_motion_sensor_ping_definition",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		DAMAGE_RESPONSE_MOTION_SENSOR_PING_ID)
	{
		{ _field_short_integer, "ping duration", nullptr, "ticks" },
		{ _field_short_integer, "ping scale" },
		{ _field_terminator }
	};

	#define AREA_CONTROL_SCALAR_FUNCTION_STRUCT_ID { 0x3EF80F86, 0x0F31468C, 0xB4C40EA2, 0x6E38CA3A }
	TAG_STRUCT(
		area_control_scalar_function_struct,
		"area_control_scalar_function_struct",
		"s_area_control_scalar_function",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		AREA_CONTROL_SCALAR_FUNCTION_STRUCT_ID)
	{
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_default),
		{ _field_struct, "Mapping", &mapping_function },
		{ _field_terminator }
	};

	#define AREA_CONTROL_SCALAR_OBJECT_FUNCTION_STRUCT_ID { 0x3D2F4F41, 0xF93C4657, 0xA70770A2, 0x07413F8E }
	TAG_STRUCT(
		area_control_scalar_object_function_struct,
		"area_control_scalar_object_function_struct",
		"s_area_control_scalar_object_function",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		AREA_CONTROL_SCALAR_OBJECT_FUNCTION_STRUCT_ID)
	{
		{ _field_string_id, "Input Variable", FIELD_FLAG_UNKNOWN0, _field_id_function_input_scalar },
		{ _field_string_id, "Range Variable", FIELD_FLAG_UNKNOWN0, _field_id_function_input_range },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_default),
		{ _field_struct, "Mapping", &mapping_function },
		{ _field_terminator }
	};

	STRINGS(area_control_flags)
	{
		"distance_falloff",
		"angle_falloff",
		"object function falloff",
		"use unit position#use the head position and facing vector of the unit instead of the player camera"
	};
	STRING_LIST(area_control_flags, area_control_flags_strings, _countof(area_control_flags_strings));

	STRINGS(damage_response_class_type_enum)
	{
		"shielded",
		"unshielded",
		"all"
	};
	STRING_LIST(damage_response_class_type_enum, damage_response_class_type_enum_strings, _countof(damage_response_class_type_enum_strings));

	STRINGS(damage_response_class_flags)
	{
		"ignore on no damage",
		"suppress directional damage flashes",
		"suppress directional damage arrows",
		"only when zoomed#if target is zoomed",
		"sound effect only applied when scale is full"
	};
	STRING_LIST(damage_response_class_flags, damage_response_class_flags_strings, _countof(damage_response_class_flags_strings));

	TAG_REFERENCE_GROUP(global_damage_effect_or_response_definition_reference)
	{
		DAMAGE_EFFECT_TAG,
		DAMAGE_RESPONSE_DEFINITION_TAG,
		INVALID_TAG,
	};

	TAG_REFERENCE(global_damage_response_definition_reference, DAMAGE_RESPONSE_DEFINITION_TAG);

} // namespace macaque

} // namespace blofeld

