#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(sound_looping, SOUND_LOOPING_TAG, sound_looping_block_block );

	TAG_BLOCK_FROM_STRUCT(sound_looping_block, 1, sound_looping_struct_definition_struct_definition );

	TAG_STRUCT(sound_looping_struct_definition)
	{
		{ _field_long_flags, "flags", &looping_sound_flags },
		{ _field_real_bounds, "marty\'s music time:seconds" },
		{ _field_real_bounds, "runtime distance bounds!" },
		{ _field_real, "maximum flyby range distance" },
		{ _field_enum, "runtime sound class!", &sound_class_enum },
		{ _field_pad, "asdf", 2 },
		{ _field_string_id, "master marker track*#This track\'s markers, flags, gain and fade settings are copied to the other tracks. Its gain and fadeout settings are also copied to the details. If you want to change the master track use the sound-looping tool command" },
		
		{ _field_version_greater, _engine_type_haloreach },
		{ _field_real, "maximum radius" },
		
		{ _field_block, "tracks#tracks play in parallel and loop continuously for the duration of the looping sound.", &looping_sound_track_block_block },
		{ _field_block, "detail sounds#detail sounds play at random throughout the duration of the looping sound.", &looping_sound_detail_block_block },
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

} // namespace blofeld

