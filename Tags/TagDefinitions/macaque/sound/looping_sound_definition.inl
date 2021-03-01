#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		sound_looping_group,
		SOUND_LOOPING_TAG,
		nullptr,
		INVALID_TAG,
		sound_looping_block );

	TAG_BLOCK_FROM_STRUCT(
		sound_looping_block,
		"sound_looping_block",
		1,
		sound_looping_struct_definition);

	#define SOUND_LOOPING_STRUCT_DEFINITION_ID { 0xD492E38E, 0x64EC43C3, 0x8F8AC4EC, 0xE04E0DB9 }
	TAG_STRUCT(
		sound_looping_struct_definition,
		"sound_looping_struct_definition",
		"looping_sound_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SOUND_LOOPING_STRUCT_DEFINITION_ID)
	{
		{ _field_long_flags, "flags", &looping_sound_flags },
		{ _field_real_bounds, "marty's music time", nullptr, "seconds" },
		{ _field_real_bounds, "runtime distance bounds", FIELD_FLAG_UNKNOWN0 },
		{ _field_real, "maximum flyby range distance" },
		{ _field_enum, "runtime sound class", FIELD_FLAG_UNKNOWN0, &sound_class_enum },
		FIELD_PAD("asdf", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_string_id, "master marker track", "This track's markers, flags, gain and fade settings are copied to the other tracks. Its gain and fadeout settings are also copied to the details. If you want to change the master track use the sound-looping tool command", FIELD_FLAG_READ_ONLY },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_real, "maximum radius" },

		{ _field_block, "tracks", "tracks play in parallel and loop continuously for the duration of the looping sound.", &looping_sound_track_block },
		{ _field_block, "detail sounds", "detail sounds play at random throughout the duration of the looping sound.", &looping_sound_detail_block },
		{ _field_terminator }
	};

	STRINGS(looping_sound_flags)
	{
		"deafening to AIs#when used as a background stereo track, causes nearby AIs to be unable to hear",
		"not a loop#this is a collection of permutations strung together that should play once then stop.",
		"stops music#all other music loops will stop when this one starts.",
		"always spatialize#always play as 3d sound, even in first person",
		"synchronize with owner{synchronize playback}#synchronizes playback with other looping sounds attached to the owner of this sound",
		"synchronize tracks",
		"fake spatialization with distance",
		"combine all 3d playback",
		"persistent flyby#like a laser blast",
		"don\'t apply random spatialization to details",
		"allow marker stitching#you need to reimport the sound_looping for this to take effect",
		"don\'t delay retries!#don\'t delay retrying the looping sound, in case the bank is loaded now",
		"Use vehicle parent for playerness#Look to the parent of the vehicle. Only works on vehicles. Duh",
		"Implicit speed RPTC#looping_sound_speed"
	};
	STRING_LIST(looping_sound_flags, looping_sound_flags_strings, _countof(looping_sound_flags_strings));

} // namespace macaque

} // namespace blofeld

