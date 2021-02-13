#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		area_screen_effect_group,
		AREA_SCREEN_EFFECT_TAG,
		nullptr,
		INVALID_TAG,
		area_screen_effect_block );

	TAG_BLOCK_FROM_STRUCT(
		area_screen_effect_block,
		"area_screen_effect_block",
		1,
		area_screen_effect_struct_definition);

	#define SINGLE_SCREEN_EFFECT_ID { 0x2E559B36, 0x4E3546A7, 0xA1AE1E29, 0x90AA239F }
	TAG_BLOCK(
		single_screen_effect_block,
		"single_screen_effect",
		s_area_screen_effect_definition::k_maximum_effects_per_tag,
		"s_single_screen_effect_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SINGLE_SCREEN_EFFECT_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_word_flags, "flags", &area_screen_effect_flags_definition },
		{ _field_word_flags, "hidden flags", FIELD_FLAG_UNKNOWN0, &area_screen_effect_hidden_flags_definition },
		FIELD_EXPLANATION("DISTANCE FALLOFF", nullptr, FIELD_FLAG_NONE, "controls the maximum distance and the distance falloff of this effect\nNOTE: not used for scenario global effects"),
		{ _field_real, "maximum distance", "the maximum distance this screen effect will affect", "world units" },
		{ _field_struct, "distance falloff", &screen_effect_scalar_function_struct },
		FIELD_EXPLANATION("TIME EVOLUTION", nullptr, FIELD_FLAG_NONE, "controls the lifetime and time falloff of this effect\nNOTE: not used for scenario global effects"),
		{ _field_real, "delay", "the effect will start after this many seconds (ignored if the play sequentially flag is set)", "seconds" },
		{ _field_real, "lifetime", "the effect is destroyed after this many seconds (0 = never dies)", "seconds" },
		{ _field_struct, "time falloff", &screen_effect_scalar_function_struct },
		FIELD_EXPLANATION("ANGLE FALLOFF", nullptr, FIELD_FLAG_NONE, "controls the falloff of this effect based on how close you are to looking directly at it\nNOTE: not used for scenario global effects"),
		{ _field_struct, "angle falloff", &screen_effect_scalar_function_struct },
		FIELD_EXPLANATION("OBJECT FALLOFF", nullptr, FIELD_FLAG_NONE, "applies a falloff based on an object function - ignored if the effect is not attached to an object"),
		{ _field_struct, "object falloff", &screen_effect_scalar_object_function_struct },
		FIELD_EXPLANATION("EFFECTS", nullptr, FIELD_FLAG_NONE, "a selection of effects to choose from\nin the case of overlapping effects, the maximum will be taken"),

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_tag_reference, "color grading look-up-texture", &Tag::Reference<struct bitmap_group>::s_defaultDefinition },
		{ _field_real, "runtime color grading strength", "do not edit", nullptr, "[do not edit]", FIELD_FLAG_UNKNOWN0 },

		{ _field_real, "exposure boost", "increase in exposure", "stops" },
		{ _field_real, "exposure deboost", "decrease in exposure", "stops" },
		{ _field_real, "hue left", "shifts hue R->G->B", "degrees ", "[0-360]" },
		{ _field_real, "hue right", "shifts hue B->G->R", "degrees ", "[0-360]" },
		{ _field_real, "saturation", "increases saturation", nullptr, "[0-1]" },
		{ _field_real, "desaturation", "decreases saturation", nullptr, "[0-1]" },
		{ _field_real, "contrast enhance", "contrast increase", nullptr, "[0-1]" },
		{ _field_real, "gamma enhance", "gamma increase", nullptr, "[0-10]" },
		{ _field_real, "gamma reduce", "gamma increase", nullptr, "[0-10]" },
		{ _field_real, "bright noise", "add bright noise contribution, 0 turns it off, 1: full on", nullptr, "[0-1]" },
		{ _field_real, "dark noise", "add dark noise contribution, 0 turns it off, 1: full on", nullptr, "[0-1]" },
		{ _field_real_rgb_color, "color filter", "this color is multiplied on top" },
		{ _field_real_rgb_color, "color floor", "this color is subtracted" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_real_fraction, "color replace strength", "used to blend in the color replace below", nullptr, "[0-1]" },
		{ _field_real_rgb_color, "color replace", "this color is blended in place of the screen's color" },

		{ _field_real, "tron", "adds a full-screen tron effect", nullptr, "[0-1]" },
		{ _field_real, "motion suck", "adds motion-blur towards or away from this screen effect", nullptr, "[-2, 2]" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach }, // This or the field above could be wrong.
		{ _field_real, "bloom buffer motion suck", "adds cheap bloom buffer motion-blur towards or away from this screen effect", nullptr, "[-2, 2]" },

		{ _field_real_vector_3d, "motion suck direction", "do not edit", nullptr, "[do not edit]", FIELD_FLAG_UNKNOWN0 },
		{ _field_real, "horizontal blur", "blurs the entire screen", nullptr, "[0-10] expensive" },
		{ _field_real, "vertical blur", "blurs the entire screen", nullptr, "[0-10] expensive" },
		{ _field_real, "vision mode", "turns on the global vision mode", nullptr, "[0-1]" },
		{ _field_real, "hud fade", "fades the chud", nullptr, "[0-1]" },
		{ _field_real, "fov in", "zooms in the field of view", nullptr, "[0-1]" },
		{ _field_real, "fov out", "zooms out the field of view", nullptr, "[0-1]" },
		{ _field_real, "screen shake", "shakes the entire screen", nullptr, "[0-1]" },
		{ _field_tag_reference, "shader effect", "applies this shader to the entire screen", &global_screen_shader_reference },
		{ _field_terminator }
	};

	#define AREA_SCREEN_EFFECT_STRUCT_DEFINITION_ID { 0xE25095D4, 0x57E84346, 0xAA15B7AB, 0x8088091E }
	TAG_STRUCT(
		area_screen_effect_struct_definition,
		"area_screen_effect_struct_definition",
		"s_area_screen_effect_definition",
		SET_UNKNOWN0 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | 
		SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		AREA_SCREEN_EFFECT_STRUCT_DEFINITION_ID)
	{
		{ _field_word_flags, "global flags", &area_screen_effect_global_flags_definition },
		{ _field_word_flags, "global hidden flags", FIELD_FLAG_UNKNOWN0, &area_screen_effect_global_hidden_flags_definition },
		{ _field_block, "screen effects", &single_screen_effect_block },
		{ _field_terminator }
	};

	#define SCREEN_EFFECT_SCALAR_FUNCTION_STRUCT_ID { 0xD2D2C2B8, 0xA3D24359, 0x8D127DD8, 0x7EB7F3D8 }
	TAG_STRUCT(
		screen_effect_scalar_function_struct,
		"screen_effect_scalar_function_struct",
		"s_screen_effect_scalar_function",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SCREEN_EFFECT_SCALAR_FUNCTION_STRUCT_ID)
	{
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_default),
		{ _field_struct, "Mapping", &mapping_function },
		{ _field_terminator }
	};

	#define SCREEN_EFFECT_SCALAR_OBJECT_FUNCTION_STRUCT_ID { 0x92C128E6, 0x4B424665, 0x80E1707B, 0xCE6CDB1D }
	TAG_STRUCT(
		screen_effect_scalar_object_function_struct,
		"screen_effect_scalar_object_function_struct",
		"s_screen_effect_scalar_object_function",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SCREEN_EFFECT_SCALAR_OBJECT_FUNCTION_STRUCT_ID)
	{
		{ _field_string_id, "Input Variable", FIELD_FLAG_UNKNOWN0, _field_id_function_input_scalar },
		{ _field_string_id, "Range Variable", FIELD_FLAG_UNKNOWN0, _field_id_function_input_range },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_default),
		{ _field_struct, "Mapping", &mapping_function },
		{ _field_terminator }
	};

	STRINGS(area_screen_effect_global_flags_definition)
	{
		"play sequentially - ignore delay settings",
		"debug this screen effect",
		"force delete when attached to dead object",
		"force max one per object",
		"force looping (dangerous; lasts forever)",
		"only spawn killcam version during killcam"
	};
	STRING_LIST(area_screen_effect_global_flags_definition, area_screen_effect_global_flags_definition_strings, _countof(area_screen_effect_global_flags_definition_strings));

	STRINGS(area_screen_effect_global_hidden_flags_definition)
	{
		"update thread",
		"render thread"
	};
	STRING_LIST(area_screen_effect_global_hidden_flags_definition, area_screen_effect_global_hidden_flags_definition_strings, _countof(area_screen_effect_global_hidden_flags_definition_strings));

	STRINGS(area_screen_effect_flags_definition)
	{
		"debug disable",
		"allow effect outside radius",
		"unattached",
		"first person{first person only}",
		"third person{third person only}",
		"disable camera falloffs{cinematic}#disables distance and angle falloffs",
		"only affects attached object",
		"draw precisely one (ask Bill before you check this)"
	};
	STRING_LIST(area_screen_effect_flags_definition, area_screen_effect_flags_definition_strings, _countof(area_screen_effect_flags_definition_strings));

	STRINGS(area_screen_effect_hidden_flags_definition)
	{
		"update thread",
		"render thread"
	};
	STRING_LIST(area_screen_effect_hidden_flags_definition, area_screen_effect_hidden_flags_definition_strings, _countof(area_screen_effect_hidden_flags_definition_strings));

	TAG_REFERENCE(global_area_screen_effect_reference, AREA_SCREEN_EFFECT_TAG);

	TAG_REFERENCE(global_screen_shader_reference, MATERIAL_TAG);

} // namespace macaque

} // namespace blofeld

