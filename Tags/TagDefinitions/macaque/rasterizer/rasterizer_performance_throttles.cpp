#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		performance_throttles_group,
		PERFORMANCE_THROTTLES_TAG,
		nullptr,
		INVALID_TAG,
		performance_throttles_block );

	TAG_BLOCK_FROM_STRUCT(
		performance_throttles_block,
		"performance_throttles_block",
		1,
		performance_throttles_struct_definition);

	#define PERFORMANE_THROTTLE_BLOCK_ID { 0x85D15105, 0x8B6740B3, 0xA382FD88, 0xD1A37CE3 }
	TAG_BLOCK(
		performane_throttle_block,
		"performane_throttle_block",
		7,
		"s_performance_throttles",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERFORMANE_THROTTLE_BLOCK_ID)
	{
		{ _field_long_flags, "flags", &performance_throttle_flags },
		{ _field_real, "water tessellation scale" },
		{ _field_real, "decorator fade dist scale", nullptr, "0 = off" },
		{ _field_real, "effect lod distance scale", MAKE_OLD_NAMES("effect lod limit") },
		FIELD_CUSTOM("Object settings", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_real, "instance fade modifier", FIELD_FLAG_UNKNOWN0 },
		{ _field_real, "object fade modifier", "scales down the distances at which objects first imposter and then fade out" },
		{ _field_real, "object detail fade modifier" },
		{ _field_real, "object lighting time limit", "per frame time limit to spend sampling new lighting radiosity", "s 0=0.001s" },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		FIELD_CUSTOM("IO settings", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_real, "IO fade modifier", "scales down the distances at which IOs imposter" },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_real, "instanced geometry modifier" },

		FIELD_CUSTOM("Dynamic light settings", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_long_integer, "max forward dynamic lights", "will quickly fade gpu lights when we try to render more than this many:0 = off", MAKE_OLD_NAMES("max gpu dynamic lights") },
		{ _field_real, "forward dynamic light fade distance scale", "scales the size used for distance-fade (set smaller to make it fade earlier)", MAKE_OLD_NAMES("gpu light fade distance scale") },
		{ _field_long_integer, "max screenspace dynamic lights", "will quickly fade screenspace lights when we try to render more than this many:0 = off" },
		{ _field_real, "screenspace light fade distance scale", "scales the size used for distance-fade (set smaller to make it fade earlier)" },
		{ _field_long_integer, "max effect lights (screenspace)", "limits the number of effect lights we allow to be active at a time (eg. needler needles lighting up objects):0 = off" },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_real, "unknown" },

		FIELD_CUSTOM("Shadow settings", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_long_integer, "max shadow casting objects", nullptr, "0 = off" },
		{ _field_real, "shadow quality lod", "scales resolution of object shadows:[0.0 to 1.0]" },
		{ _field_real, "floating shadow quality lod", "scales resolution of floating shadow:[0.0 to 1.0], 0 = off" },

		{ _field_legacy, _field_version_platform_include, _platform_type_pc, 2 },
		{ _field_legacy, _field_version_equal, _engine_type_haloreach, 1 },
		{ _field_legacy, _field_real, "anisotropic filtering" },

		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		{ _field_terminator }
	};

	#define PERFORMANCE_THROTTLES_STRUCT_DEFINITION_ID { 0x044A4563, 0x26134854, 0xA54E1DDE, 0x72F14803 }
	TAG_STRUCT(
		performance_throttles_struct_definition,
		"performance_throttles_struct_definition",
		"c_performance_throttles",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		PERFORMANCE_THROTTLES_STRUCT_DEFINITION_ID)
	{
		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_long_integer, "unknown" },

		FIELD_EXPLANATION("Performance Throttles", nullptr, FIELD_FLAG_NONE, "Split-screen throttle settings should be more aggresive than non-local co-op settings\nblock index 0:\tdefault non split screen\nblock index 1: two way split screen\nblock index 2: three way split screen\nblock index 3: four way split screen\nblock index 4: one additional non-local player\nblock index 5: two additional non-local players\nblock index 6: three additional non-local players\n\n"),
		{ _field_block, "Performance Throttles", &performane_throttle_block },
		{ _field_terminator }
	};

	STRINGS(performance_throttle_flags)
	{
		"disable object attachment lights",
		"disable first person shadow",
		"disable cheap particles",
		"disable blob shadows",
		"disable patchy fog",
		"disable screen distortion",
		"disable light shafts",
		"disable first person depth of field",
		"disable motion blur",
		"disable particles continue offscreen",
		"disable light cones",
		"disable water interraction",
		"disable water refraction",
		"disable decorators",
		"disable instance occlusion queries#WARNING Will likely hurt perf on most maps"
	};
	STRING_LIST(performance_throttle_flags, performance_throttle_flags_strings, _countof(performance_throttle_flags_strings));

	TAG_REFERENCE(global_performance_throttles_reference, PERFORMANCE_THROTTLES_TAG);

} // namespace macaque

} // namespace blofeld

