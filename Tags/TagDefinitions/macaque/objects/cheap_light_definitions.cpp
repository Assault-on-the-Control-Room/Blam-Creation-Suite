#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		cheap_light_group,
		CHEAP_LIGHT_TAG,
		nullptr,
		INVALID_TAG,
		cheap_light_block );

	TAG_BLOCK_FROM_STRUCT(
		cheap_light_block,
		"cheap_light_block",
		1,
		cheap_light_struct_definition);

	#define CHEAP_LIGHT_STRUCT_DEFINITION_ID { 0x6A1EB2F2, 0xF6AF4F2D, 0x9C2D7F25, 0xE4B6E5AE }
	TAG_STRUCT(
		cheap_light_struct_definition,
		"cheap_light_struct_definition",
		"s_cheap_light_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		CHEAP_LIGHT_STRUCT_DEFINITION_ID)
	{
		FIELD_EXPLANATION("Cheap Lights", nullptr, FIELD_FLAG_NONE, "These are the cheapest light possible. They are spherical, have a color with an intensity and a radius - and that\'s it. They should be small: 0.5 or smaller if you can get close to them. That\'s why they are so cheap."),

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_char_enum, "function input", &cheapLightFunctionInputEnum },
		FIELD_PAD("clblah", nullptr, FIELD_FLAG_NONE, 3),

		FIELD_EXPLANATION("COLOR", nullptr, FIELD_FLAG_NONE, "color and intensity of the light"),
		{ _field_struct, "color", &light_color_function_struct },
		{ _field_struct, "intensity", &light_scalar_function_struct },
		FIELD_EXPLANATION("SIZE", nullptr, FIELD_FLAG_NONE, "radius of the spherical light"),

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 3 },
		{ _field_legacy, _field_struct, "radius", &light_scalar_function_struct_struct_definition },
		{ _field_real, "Falloff Begin Ratio", "Ratio of falloff start to falloff end", nullptr, "[0-1]" },
		{ _field_real, "near fade distance", nullptr, "world units", MAKE_OLD_NAMES("closeup fading distance") }, // #TODO: unconfirmed

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 5 },
		{ _field_struct, "Falloff End", MAKE_OLD_NAMES("radius"), &light_scalar_function_struct },
		{ _field_real, "Falloff Begin Ratio", "Ratio of falloff start to falloff end", nullptr, "[0-1]" },
		{ _field_real, "near fade distance", nullptr, "world units", MAKE_OLD_NAMES("closeup fading distance") },
		{ _field_real, "far fade begin", nullptr, "world units" },
		{ _field_real, "far fade cutoff", nullptr, "world units" },
		{ _field_terminator }
	};

	STRINGS(cheapLightFunctionInputEnum)
	{
		"time/age",
		"scale A",
		"scale B"
	};
	STRING_LIST(cheapLightFunctionInputEnum, cheapLightFunctionInputEnum_strings, _countof(cheapLightFunctionInputEnum_strings));

} // namespace macaque

} // namespace blofeld

