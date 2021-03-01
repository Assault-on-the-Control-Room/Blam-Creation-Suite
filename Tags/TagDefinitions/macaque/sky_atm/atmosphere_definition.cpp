#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		atmosphere_fog_group,
		ATMOSPHERE_FOG_TAG,
		nullptr,
		INVALID_TAG,
		atmosphere_definition_block );

	#define ATMOSPHERE_FOG_STRUCT_DEFINITION_ID { 0xA4C4E5E8, 0x40A7425B, 0x83DB142C, 0x3F7926B0 }
	TAG_BLOCK(
		atmosphere_definition_block,
		"atmosphere_definition_block",
		k_max_atmosphere_settings,
		"s_atmosphere_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		ATMOSPHERE_FOG_STRUCT_DEFINITION_ID)
	{
		{ _field_word_flags, "Flags", &atmosphere_flags },
		{ _field_byte_integer, "Version", FIELD_FLAG_UNKNOWN0 },
		FIELD_PAD("ABCDEFGH", nullptr, FIELD_FLAG_NONE, 1),
		FIELD_EXPLANATION("Ambient Fog Parameters", nullptr, FIELD_FLAG_NONE, "All heights are absolute world space height\n"),
		{ _field_real, "distance bias", "negative means into the screen", "world units" },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_real, "unknown@" },

		FIELD_CUSTOM("Sky Fog", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_struct, "sky fog", &solo_fog_parameters_struct_definition },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		FIELD_CUSTOM("Ground Fog", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_struct, "ground fog", &solo_fog_parameters_struct_definition },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		FIELD_CUSTOM("Ceiling Fog BEWARE", nullptr, FIELD_FLAG_UNKNOWN0, _field_id_field_group_begin),
		{ _field_struct, "ceiling fog", &solo_fog_parameters_struct_definition },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		FIELD_CUSTOM("Fog Light", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_struct, "fog light", &fog_light_struct_definition },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 8 },
		FIELD_EXPLANATION("Patchy Fog Per-Cluster Parameters", nullptr, FIELD_FLAG_NONE, "Sheet density.............Intensity scaling factor applied to all sheets\nFull intensity height.....Height above 0 below which fog should be at full intensity\nHalf intensity height.....Height at which fog should be attenuated to half intensity\nWind......................Direction and intensity of fog motion due to wind\n\n"),
		{ _field_real, "Sheet density" },
		{ _field_real_rgb_color, "Color tint" },
		{ _field_real_rgb_color, "Color tint inner" },
		{ _field_real, "Intensity" },
		{ _field_real, "Full intensity height" },
		{ _field_real, "Half intensity height" },
		{ _field_real_vector_3d, "Wind direction" },

		{ _field_real, "Reference plane height" },
		FIELD_CUSTOM("Volume Fog", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_struct, "volume fog", &VolumeFogParametersDefinition },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 3 },
		FIELD_CUSTOM("Light Shafts", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_struct, "light shaft", &LightShaftParametersDefinition },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_real, "unknown@" },

		FIELD_EXPLANATION("Weather effect", nullptr, FIELD_FLAG_NONE, "Effect tag to create nearby raindrops, snowflakes, etc.\nParticle systems from this effect will follow the camera and wrap seamlessly as you turn or move.\n\n"),
		{ _field_tag_reference, "Weather effect", &global_effect_reference },
		{ _field_terminator }
	};

	#define SOLOFOGFUNCTIONBLOCK_ID { 0xD1F9D529, 0x9B06D3E1, 0xD509793C, 0x3631AF50 }
	TAG_BLOCK(
		soloFogFunctionBlock_block,
		"soloFogFunctionBlock",
		1,
		"s_soloFogFunction",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SOLOFOGFUNCTIONBLOCK_ID)
	{
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_default),
		{ _field_struct, "mapping", &mapping_function },
		{ _field_terminator }
	};

	#define SOLO_FOG_PARAMETERS_STRUCT_DEFINITION_ID { 0xD82AB114, 0x09244998, 0x857CA148, 0x24F24947 }
	TAG_STRUCT(
		solo_fog_parameters_struct_definition,
		"solo_fog_parameters_struct_definition",
		"s_solo_fog_parameters",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SOLO_FOG_PARAMETERS_STRUCT_DEFINITION_ID)
	{
		{ _field_real, "base height", nullptr, "world units" },
		{ _field_real, "fog height", nullptr, "world units" },
		{ _field_real, "fog thickness" },
		{ _field_real, "fog falloff end", MAKE_OLD_NAMES("max fog distance") },
		{ _field_real_rgb_color, "fog color" },
		{ _field_real, "fog color intensity", "scales color up or down to allow for HDR values" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_block, "Function", &soloFogFunctionBlock_block },

		{ _field_terminator }
	};

	#define FOG_LIGHT_STRUCT_DEFINITION_ID { 0x2EA4F208, 0x23EB43DA, 0x96CF1259, 0x7F716CD9 }
	TAG_STRUCT(
		fog_light_struct_definition,
		"fog_light_struct_definition",
		"s_fog_light_parameters",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		FOG_LIGHT_STRUCT_DEFINITION_ID)
	{
		{ _field_real, "pitch angle", nullptr, "degree" },
		{ _field_real, "yaw angle", nullptr, "degree" },
		{ _field_real, "angular radius", nullptr, "degree" },
		{ _field_real_rgb_color, "tint color" },
		{ _field_real, "tint color intensity" },
		{ _field_real, "angular falloff steepness" },
		{ _field_real, "distance falloff steepness" },
		{ _field_real, "nearby cutoff percentage" },
		{ _field_terminator }
	};

	#define VOLUMEFOGPARAMETERSDEFINITION_ID { 0xB9DBF7F3, 0xD9624CCE, 0xA7F3E00E, 0x010284AE }
	TAG_STRUCT(
		VolumeFogParametersDefinition,
		"VolumeFogParametersDefinition",
		"VolumeFogParameters",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		VOLUMEFOGPARAMETERSDEFINITION_ID)
	{
		{ _field_real_rgb_color, "volume fog color" },
		{ _field_real, "volume fog color intensity" },
		{ _field_terminator }
	};

	#define LIGHTSHAFTPARAMETERSDEFINITION_ID { 0x8893D72D, 0xCA8A49CB, 0xA26C4277, 0xF0677728 }
	TAG_STRUCT(
		LightShaftParametersDefinition,
		"LightShaftParametersDefinition",
		"LightShaftParameters",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		LIGHTSHAFTPARAMETERSDEFINITION_ID)
	{
		{ _field_real_rgb_color, "light shaft tint color" },
		{ _field_real, "light shaft intensity" },
		{ _field_real, "light shaft decay rate" },
		{ _field_real, "maximum screen distance" },
		{ _field_real, "sample density" },
		{ _field_real, "minimum caster distance" },
		{ _field_terminator }
	};

	STRINGS(atmosphere_flags)
	{
		"Sky Fog Enabled",
		"Ground Fog Enabled",
		"Ceiling Fog Enabled",
		"Fog Light Enabled",
		"Patchy Fog Enabled",
		"Sky Fog Height Camera Relative",
		"Ground Fog Height Camera Relative",
		"Use Floating Shadow for Fog Light",
		"Only use fog light for light shafts"
	};
	STRING_LIST(atmosphere_flags, atmosphere_flags_strings, _countof(atmosphere_flags_strings));

	TAG_REFERENCE(global_atmosphere_definition_reference, ATMOSPHERE_FOG_TAG);

} // namespace macaque

} // namespace blofeld

