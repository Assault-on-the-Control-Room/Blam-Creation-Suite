#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(new_cinematic_lighting, NEW_CINEMATIC_LIGHTING_TAG, new_cinematic_lighting_block_block );

	TAG_BLOCK(cinematic_dynamic_light_block, 16)
	{
		{ _field_long_flags, "Flags", &cinematic_dynamic_light_flags },
		{ _field_custom, "Dynamic Light" },
		{ _field_custom, "Direction" },
		{ _field_real, "Direction" },
		{ _field_custom, "Front-Back" },
		{ _field_real, "Front-Back" },
		{ _field_real, "Distance:world units" },
		{ _field_tag_reference, "light", &global_light_definition_reference },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(new_cinematic_lighting_block, 1, new_cinematic_lighting_struct_definition_struct_definition );

	TAG_STRUCT(new_cinematic_lighting_struct_definition)
	{
		{ _field_custom, "Cinematic Lighting" },
		{ _field_custom, "Cinema Lighting" },

		{ _field_version_greater, _engine_type_haloreach, 1 },
		{ _field_long_integer, "version!" },

		{ _field_custom, "Direction&Direction(D)" },
		{ _field_real, "Direction&Direction(D)" },
		{ _field_custom, "Front-Back&Front-Back(D)" },
		{ _field_real, "Front-Back&Front-Back(D)" },
		{ _field_custom, "Shadow Interpolation" },
		{ _field_real, "Shadow Interpolation" },
		{ _field_custom, "Overall weight" },
		{ _field_real, "Overall weight" },
		{ _field_custom, "Direct weight" },
		{ _field_real, "Direct weight" },
		{ _field_custom, "Indirect weight" },
		{ _field_real, "Indirect weight" },
		{ _field_custom, "Airprobe weight" },
		{ _field_real, "Airprobe weight" },
		{ _field_custom, "Sun weight" },
		{ _field_real, "Sun weight" },
		{ _field_real_rgb_color, "Direct color" },
		{ _field_custom, "Direct intensity" },
		{ _field_real, "Direct intensity" },

		{ _field_version_less_or_equal, _engine_type_haloreach, 1 },
		{ _field_real, "unknown" },

		{ _field_real_rgb_color, "Indirect color" },
		{ _field_custom, "Indirect intensity" },
		{ _field_real, "Indirect intensity" },
		{ _field_custom, "Interpolation" },
		{ _field_real, "Interpolation" },

		{ _field_version_less_or_equal, _engine_type_haloreach, 3 },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },

		{ _field_version_greater, _engine_type_haloreach, 3 },
		{ _field_custom },
		{ _field_block, "Authored Light Probe", &authored_light_probe_block },
		{ _field_block, "Cortana Lighting", &hologramLightingBlock_block },

		{ _field_block, "dynamic lights!", &cinematic_dynamic_light_block_block },
		{ _field_terminator }
	};

	STRINGS(cinematic_dynamic_light_flags)
	{
		"debug this light",
		"follow object",
		"position at marker"
	};
	STRING_LIST(cinematic_dynamic_light_flags, cinematic_dynamic_light_flags_strings, _countof(cinematic_dynamic_light_flags_strings));

	TAG_REFERENCE(global_new_cinematic_lighting_reference, NEW_CINEMATIC_LIGHTING_TAG);

	TAG_REFERENCE(global_light_definition_reference, LIGHT_TAG);

} // namespace blofeld

