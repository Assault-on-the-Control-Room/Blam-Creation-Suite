#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(performance_throttles, PERFORMANCE_THROTTLES_TAG, performance_throttles_block_block );

	TAG_BLOCK(performane_throttle_block, 7)
	{
		{ _field_long_flags, "flags", &performance_throttle_flags },
		{ _field_real, "water tessellation scale" },
		{ _field_real, "decorator fade dist scale:0 = off" },
		{ _field_real, "effect lod distance scale{effect lod limit}" },
		{ _field_custom, "Object settings" },
		{ _field_real, "instance fade modifier!" },
		{ _field_real, "object fade modifier#scales down the distances at which objects first imposter and then fade out" },
		{ _field_real, "object detail fade modifier" },
		{ _field_real, "object lighting time limit:s 0=0.001s#per frame time limit to spend sampling new lighting radiosity" },
		{ _field_custom },
		{ _field_custom, "IO settings" },
		{ _field_real, "IO fade modifier#scales down the distances at which IOs imposter" },
		{ _field_custom },
		{ _field_custom, "Dynamic light settings" },
		{ _field_long_integer, "max forward dynamic lights{max gpu dynamic lights}#will quickly fade gpu lights when we try to render more than this many:0 = off" },
		{ _field_real, "forward dynamic light fade distance scale{gpu light fade distance scale}#scales the size used for distance-fade (set smaller to make it fade earlier)" },
		{ _field_long_integer, "max screenspace dynamic lights#will quickly fade screenspace lights when we try to render more than this many:0 = off" },
		{ _field_real, "screenspace light fade distance scale#scales the size used for distance-fade (set smaller to make it fade earlier)" },
		{ _field_long_integer, "max effect lights (screenspace)#limits the number of effect lights we allow to be active at a time (eg. needler needles lighting up objects):0 = off" },
		{ _field_custom },
		{ _field_custom, "Shadow settings" },
		{ _field_long_integer, "max shadow casting objects:0 = off" },
		{ _field_real, "shadow quality lod#scales resolution of object shadows:[0.0 to 1.0]" },
		{ _field_real, "floating shadow quality lod#scales resolution of floating shadow:[0.0 to 1.0], 0 = off" },
		{ _field_custom },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(performance_throttles_block, 1, performance_throttles_struct_definition_struct_definition );

	TAG_STRUCT(performance_throttles_struct_definition)
	{

		{ _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_long_integer, "Unknown@" },
		
		{ _field_explanation, "Performance Throttles", "Split-screen throttle settings should be more aggresive than non-local co-op settings\nblock index 0:\tdefault non split screen\nblock index 1: two way split screen\nblock index 2: three way split screen\nblock index 3: four way split screen\nblock index 4: one additional non-local player\nblock index 5: two additional non-local players\nblock index 6: three additional non-local players\n\n" },
		{ _field_block, "Performance Throttles", &performane_throttle_block_block },
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

} // namespace blofeld

