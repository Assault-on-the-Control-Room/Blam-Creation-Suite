#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define SOUND_RADIO_SETTINGS_STRUCT_DEFINITION_ID { 0x6177BF04, 0xF09F4A0C, 0xB670E9D3, 0x530193CE }
	TAG_BLOCK(
		sound_radio_settings_block,
		"sound_radio_settings_block",
		1,
		"s_sound_radio_settings",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SOUND_RADIO_SETTINGS_STRUCT_DEFINITION_ID)
	{
		FIELD_EXPLANATION("mix settings", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_long_enum, "mix", &radio_mix_setting_definition },
		FIELD_EXPLANATION("distortion settings", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_struct, "distortion settings", &global_sound_look_up_table_distortion_block },
		FIELD_EXPLANATION("equalizer settings", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_struct, "equalizer settings", &global_sound_equalizer_block },
		{ _field_terminator }
	};

	TAG_GROUP(
		sound_radio_settings_group,
		SOUND_RADIO_SETTINGS_TAG,
		nullptr,
		INVALID_TAG,
		sound_radio_settings_block );

	#define SOUND_EQUALIZER_BAND_SETTINGS_BLOCK_STRUCT_ID { 0xF89C600C, 0x62DA422A, 0xAF5B1D5D, 0x0D1DD0DB }
	TAG_BLOCK(
		sound_equalizer_band_settings_block,
		"sound_equalizer_band_settings_block",
		k_maximum_sound_equalizer_bands,
		"s_sound_equalizer_band_settings",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SOUND_EQUALIZER_BAND_SETTINGS_BLOCK_STRUCT_ID)
	{
		{ _field_long_enum, "type", FIELD_FLAG_INDEX, &equalizer_band_type_definition },
		FIELD_CUSTOM("frequency", nullptr, FIELD_FLAG_NONE, _field_id_slider_editor),
		{ _field_real, "frequency", nullptr, "Hz", _field_id_slider_editor },
		FIELD_CUSTOM("gain", nullptr, FIELD_FLAG_NONE, _field_id_slider_editor),
		{ _field_real, "gain", nullptr, "dB", _field_id_slider_editor },
		FIELD_CUSTOM("q", nullptr, FIELD_FLAG_NONE, _field_id_slider_editor),
		{ _field_real, "q", _field_id_slider_editor },
		{ _field_terminator }
	};

	#define GLOBAL_SOUND_LOWPASS_BLOCK_ID { 0xF38F05D9, 0xF9BB4F33, 0x95EAD7FE, 0x61588F25 }
	TAG_STRUCT(
		global_sound_lowpass_block,
		"global_sound_lowpass_block",
		"s_sound_lowpass_settings",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		GLOBAL_SOUND_LOWPASS_BLOCK_ID)
	{
		FIELD_CUSTOM("cutoff frequency", nullptr, FIELD_FLAG_NONE, _field_id_slider_editor),
		{ _field_real, "cutoff frequency", nullptr, "Hz", _field_id_slider_editor },
		FIELD_CUSTOM("output gain", nullptr, FIELD_FLAG_NONE, _field_id_slider_editor),
		{ _field_real, "output gain", nullptr, "dB", _field_id_slider_editor },
		{ _field_terminator }
	};

	#define GLOBAL_SOUND_REVERB_BLOCK_ID { 0xE4B31E1D, 0xC5A74C51, 0xAE02D86C, 0x2B3F8B06 }
	TAG_STRUCT(
		global_sound_reverb_block,
		"global_sound_reverb_block",
		"s_sound_reverb_settings",
		SET_UNKNOWN0 | SET_POSTPROCESS_RECURSIVELY | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		GLOBAL_SOUND_REVERB_BLOCK_ID)
	{
		FIELD_CUSTOM("room intensity", "intensity of the room effect", FIELD_FLAG_NONE, _field_id_slider_editor),
		{ _field_real, "room intensity", "intensity of the room effect", "dB", _field_id_slider_editor },
		FIELD_CUSTOM("room intensity hf", "intensity of the room effect above the reference high frequency", FIELD_FLAG_NONE, _field_id_slider_editor),
		{ _field_real, "room intensity hf", "intensity of the room effect above the reference high frequency", "dB", _field_id_slider_editor },
		FIELD_CUSTOM("room rolloff (0 to 10)", "how quickly the room effect rolls off, from 0.0 to 10.0", FIELD_FLAG_NONE, _field_id_slider_editor),
		{ _field_real, "room rolloff (0 to 10)", "how quickly the room effect rolls off, from 0.0 to 10.0", _field_id_slider_editor },
		FIELD_CUSTOM("decay time (.1 to 20)", nullptr, FIELD_FLAG_NONE, _field_id_slider_editor),
		{ _field_real, "decay time (.1 to 20)", nullptr, "seconds", _field_id_slider_editor },
		FIELD_CUSTOM("decay hf ratio (.1 to 2)", nullptr, FIELD_FLAG_NONE, _field_id_slider_editor),
		{ _field_real, "decay hf ratio (.1 to 2)", _field_id_slider_editor },
		FIELD_CUSTOM("reflections intensity", nullptr, FIELD_FLAG_NONE, _field_id_slider_editor),
		{ _field_real, "reflections intensity", nullptr, "dB", "[-100,10]", _field_id_slider_editor },
		FIELD_CUSTOM("reflections delay (0 to .3)", nullptr, FIELD_FLAG_NONE, _field_id_slider_editor),
		{ _field_real, "reflections delay (0 to .3)", nullptr, "seconds", _field_id_slider_editor },
		FIELD_CUSTOM("reverb intensity", nullptr, FIELD_FLAG_NONE, _field_id_slider_editor),
		{ _field_real, "reverb intensity", nullptr, "dB", "[-100,20]", _field_id_slider_editor },
		FIELD_CUSTOM("reverb delay (0 to .1)", nullptr, FIELD_FLAG_NONE, _field_id_slider_editor),
		{ _field_real, "reverb delay (0 to .1)", nullptr, "seconds", _field_id_slider_editor },
		FIELD_CUSTOM("diffusion", nullptr, FIELD_FLAG_NONE, _field_id_slider_editor),
		{ _field_real, "diffusion", _field_id_slider_editor },
		FIELD_CUSTOM("density", nullptr, FIELD_FLAG_NONE, _field_id_slider_editor),
		{ _field_real, "density", _field_id_slider_editor },
		FIELD_CUSTOM("hf reference(20 to 20,000)", "for hf values, what frequency defines hf, from 20 to 20,000", FIELD_FLAG_NONE, _field_id_slider_editor),
		{ _field_real, "hf reference(20 to 20,000)", "for hf values, what frequency defines hf, from 20 to 20,000", "Hz", _field_id_slider_editor },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 8 },
		FIELD_EXPLANATION("WWise Environment", nullptr, FIELD_FLAG_NONE, "Use these values for WWise reverb. Above stuff will be removed eventually."),
		{ _field_string_id, "Environment name", "Name of the environment from WWise. This will be a DSP effect with Environmental Effect checked." },
		FIELD_CUSTOM("Dry mix value", "0 to 1 with 0 being none, and 1 being full.", FIELD_FLAG_NONE, _field_id_slider_editor),
		{ _field_real, "Dry mix value", "0 to 1 with 0 being none, and 1 being full.", _field_id_slider_editor },
		FIELD_CUSTOM("Wet mix value", "0 to 1 with 0 being none, and 1 being full.", FIELD_FLAG_NONE, _field_id_slider_editor),
		{ _field_real, "Wet mix value", "0 to 1 with 0 being none, and 1 being full.", _field_id_slider_editor },
		FIELD_CUSTOM("Player wet mix value", "0 to 1 with 0 being none, and 1 being full.", FIELD_FLAG_NONE, _field_id_slider_editor),
		{ _field_real, "Player wet mix value", "0 to 1 with 0 being none, and 1 being full.", _field_id_slider_editor },

		{ _field_terminator }
	};

	#define GLOBAL_SOUND_LOOK_UP_TABLE_DISTORTION_BLOCK_ID { 0x898FB725, 0x714849A9, 0x8A88EB99, 0x09FC092C }
	TAG_STRUCT(
		global_sound_look_up_table_distortion_block,
		"global_sound_look_up_table_distortion_block",
		"s_sound_look_up_table_distortion_settings",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		GLOBAL_SOUND_LOOK_UP_TABLE_DISTORTION_BLOCK_ID)
	{
		FIELD_CUSTOM("table size", nullptr, FIELD_FLAG_NONE, _field_id_slider_editor),
		{ _field_long_integer, "table size", _field_id_slider_editor },
		FIELD_CUSTOM("noise amount", nullptr, FIELD_FLAG_NONE, _field_id_slider_editor),
		{ _field_real, "noise amount", _field_id_slider_editor },
		{ _field_long_flags, "flags", &look_up_table_flags_definition },
		{ _field_terminator }
	};

	#define GLOBAL_SOUND_EQUALIZER_BLOCK_ID { 0x9EE2BF8D, 0x8CB54AD8, 0xA7D0F3DA, 0x3FDE09A9 }
	TAG_STRUCT(
		global_sound_equalizer_block,
		"global_sound_equalizer_block",
		"s_sound_equalizer_settings",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		GLOBAL_SOUND_EQUALIZER_BLOCK_ID)
	{
		FIELD_CUSTOM("input gain", nullptr, FIELD_FLAG_NONE, _field_id_slider_editor),
		{ _field_real, "input gain", nullptr, "dB", _field_id_slider_editor },
		FIELD_CUSTOM("output gain", nullptr, FIELD_FLAG_NONE, _field_id_slider_editor),
		{ _field_real, "output gain", nullptr, "dB", _field_id_slider_editor },
		{ _field_block, "band settings", &sound_equalizer_band_settings_block },
		{ _field_terminator }
	};

	STRINGS(look_up_table_flags_definition)
	{
		"interpolate"
	};
	STRING_LIST(look_up_table_flags_definition, look_up_table_flags_definition_strings, _countof(look_up_table_flags_definition_strings));

	STRINGS(equalizer_band_type_definition)
	{
		"band pass",
		"low shelf",
		"high shelf",
		"low pass",
		"high pass"
	};
	STRING_LIST(equalizer_band_type_definition, equalizer_band_type_definition_strings, _countof(equalizer_band_type_definition_strings));

	STRINGS(radio_mix_setting_definition)
	{
		"full#full unspatialized radio effect",
		"3d#mixes in the unspatialized radio effect with distance",
		"none#essentially turns off the radio effect!"
	};
	STRING_LIST(radio_mix_setting_definition, radio_mix_setting_definition_strings, _countof(radio_mix_setting_definition_strings));

	TAG_REFERENCE(global_sound_radio_settings_reference, SOUND_RADIO_SETTINGS_TAG);

} // namespace macaque

} // namespace blofeld

