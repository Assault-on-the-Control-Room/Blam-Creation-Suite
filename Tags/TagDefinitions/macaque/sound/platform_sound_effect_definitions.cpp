#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define SOUND_EFFECT_COLLECTION_STRUCT_DEFINITION_ID { 0xA24760BC, 0xCAB4458A, 0x9782A026, 0xDBEF5B53 }
	TAG_BLOCK(
		sound_effect_collection_block,
		"sound_effect_collection_block",
		1,
		"s_platform_sound_playback_collection",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SOUND_EFFECT_COLLECTION_STRUCT_DEFINITION_ID)
	{
		{ _field_block, "sound effects", &platform_sound_playback_block },
		{ _field_terminator }
	};

	TAG_GROUP(
		sound_effect_collection_group,
		SOUND_EFFECT_COLLECTION_TAG,
		nullptr,
		INVALID_TAG,
		sound_effect_collection_block );

	#define PLATFORM_SOUND_PLAYBACK_BLOCK_STRUCT_ID { 0x334A1B38, 0x94C44B5C, 0x9CBD395C, 0x8A7B7F5A }
	TAG_BLOCK(
		platform_sound_playback_block,
		"platform_sound_playback_block",
		128,
		"s_platform_sound_playback_named_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		PLATFORM_SOUND_PLAYBACK_BLOCK_STRUCT_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_struct, "playback", &platform_sound_playback_struct },
		{ _field_terminator }
	};

	#define PLATFORM_SOUND_PLAYBACK_LOWPASS_BLOCK_STRUCT_ID { 0x881A1219, 0x01DE4EA7, 0x8BC63300, 0xBAA416AB }
	TAG_BLOCK(
		platform_sound_playback_lowpass_block,
		"platform_sound_playback_lowpass_block",
		1,
		"s_platform_sound_playback_lowpass_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PLATFORM_SOUND_PLAYBACK_LOWPASS_BLOCK_STRUCT_ID)
	{
		{ _field_real, "attack", nullptr, "seconds" },
		{ _field_real, "release", nullptr, "seconds" },
		{ _field_struct, "settings", &global_sound_lowpass_block },
		{ _field_terminator }
	};

	#define PLATFORM_SOUND_PLAYBACK_COMPONENT_BLOCK_STRUCT_ID { 0x7F148C26, 0x4A18433F, 0xA4754101, 0x5B0E7F87 }
	TAG_BLOCK(
		platform_sound_playback_component_block,
		"platform_sound_playback_component_block",
		k_maximum_number_of_platform_sound_playback_components,
		"s_platform_sound_playback_component_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PLATFORM_SOUND_PLAYBACK_COMPONENT_BLOCK_STRUCT_ID)
	{
		{ _field_tag_reference, "sound", FIELD_FLAG_INDEX, &global_sound_and_looping_sound_reference },
		{ _field_real, "gain", "additional attenuation to sound", "dB" },
		{ _field_long_flags, "flags", &platform_sound_playback_component_flags },
		{ _field_terminator }
	};

	#define PLATFORM_SOUND_PLAYBACK_STRUCT_ID { 0x4A19C737, 0xDB944AA2, 0x9B7BCF04, 0x64F78334 }
	TAG_STRUCT(
		platform_sound_playback_struct,
		"platform_sound_playback_struct",
		"s_platform_sound_playback_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		PLATFORM_SOUND_PLAYBACK_STRUCT_ID)
	{
		{ _field_long_flags, "flags", &platform_sound_effect_flags_definition },
		{ _field_tag_reference, "radio effect", &global_sound_radio_settings_reference },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 3 },
		{ _field_tag_reference, "Start event", &global_sound_reference },
		{ _field_tag_reference, "End event", &global_sound_reference },
		{ _field_tag_reference, "Immediate stop event", "Must clear the effect without any transition - used for exiting levels, etc", &global_sound_reference },

		{ _field_block, "lowpass effect", &platform_sound_playback_lowpass_block },
		{ _field_block, "sound components", &platform_sound_playback_component_block },
		{ _field_terminator }
	};

	STRINGS(platform_sound_playback_component_flags)
	{
		"don\'t play at start",
		"play on stop",
		"play alternate",
		"sync with origin looping sound"
	};
	STRING_LIST(platform_sound_playback_component_flags, platform_sound_playback_component_flags_strings, _countof(platform_sound_playback_component_flags_strings));

	STRINGS(platform_sound_effect_flags_definition)
	{
		"turn off in splitscreen",
		"only turn on in first person"
	};
	STRING_LIST(platform_sound_effect_flags_definition, platform_sound_effect_flags_definition_strings, _countof(platform_sound_effect_flags_definition_strings));

} // namespace macaque

} // namespace blofeld

