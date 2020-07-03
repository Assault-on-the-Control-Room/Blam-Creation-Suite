#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_REFERENCE(chud_animation_reference, CHUD_ANIMATION_TAG);
	TAG_REFERENCE(chud_reference, CHUD_TAG);

	TAG_GROUP(chud_animation, CHUD_ANIMATION_TAG)
	{
		{ _field_terminator }
	};

	TAG_GROUP(chud, CHUD_TAG)
	{
		{ _field_terminator }
	};

	TAG_BLOCK(chgd_hud_sounds_block, 65536)
	{
		{ _field_tag_reference, "sound", &global_sound_reference },
		{ _field_long_flags, "latched to", &latched_to_flags_definition },
		{ _field_real, "Scale" },
		{ _field_terminator }
	};

	TAG_REFERENCE_GROUP(chgd_sound_reference, _tag_reference_flag_resolved_by_game)
	{
		SOUND_TAG,
		INVALID_TAG,
	};

	TAG_BLOCK(chgd_hud_attributes_block, 65536)
	{
		{ _field_byte_flags, "resolution flags", &resolution_flags_definition },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "horizontal roll" },
		{ _field_real, "vertical bow" },
		{ _field_real, "inverse horizontal roll" },
		{ _field_real, "inverse vertical bow" },
		{ _field_real, "horizontal roll 2" },
		{ _field_real, "vertical bow 2" },
		{ _field_real, "horizontal twist" },
		{ _field_real, "vertical twist" },
		{ _field_real, "horizontal twist 2" },
		{ _field_real, "vertical twist 2" },
		{ _field_real, "vertical scale" },
		{ _field_real, "vertical twist 3" },
		{ _field_real, "horizontal skew" },
		{ _field_real, "vertical flip" },
		{ _field_real, "inverse horizontal skew" },
		{ _field_real, "vertical flip 2" },
		{ _field_real, "hud offset x" },
		{ _field_real, "hud offset y" },
		{ _field_long_integer, "resolution width" },
		{ _field_long_integer, "resolution height" },
		{ _field_real, "motion sensor offset x" },
		{ _field_real, "motion sensor offset y" },
		{ _field_real, "unknown" },
		{ _field_real, "motion sensor radius" },
		{ _field_real, "motion sensor scale" },
		{ _field_long_integer, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_real, "horizontal scale" },
		{ _field_real, "vertical scale" },
		{ _field_real, "horizontal stretch" },
		{ _field_real, "vertical stretch" },
		{ _field_real, "notification offset x" },
		{ _field_real, "notification offset y" },
		{ _field_real, "state left/right offset y" },
		{ _field_real, "state center offset y" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "state scale" },
		{ _field_real, "notification scale" },
		{ _field_real, "notification line spacing" },
		{ _field_long_integer, "notification line count modifier" },
		{ _field_terminator }
	};

	TAG_BLOCK(chgd_hud_globals_block, 65536)
	{
		{ _field_long_enum, "biped", &biped_enum_definition },
		{ _field_real_argb_color, "0 [HUD disabled]" },
		{ _field_real_argb_color, "1 [HUD primary]" },
		{ _field_real_argb_color, "2 [HUD foreground]" },
		{ _field_real_argb_color, "3 [HUD warning]" },
		{ _field_real_argb_color, "4 [neutral reticule]" },
		{ _field_real_argb_color, "5 [hostile reticule]" },
		{ _field_real_argb_color, "6 [friendly reticule]" },
		{ _field_real_argb_color, "7" },
		{ _field_real_argb_color, "8" },
		{ _field_real_argb_color, "9" },
		{ _field_real_argb_color, "10" },
		{ _field_real_argb_color, "11" },
		{ _field_real_argb_color, "12" },
		{ _field_real_argb_color, "13" },
		{ _field_real_argb_color, "14" },
		{ _field_real_argb_color, "15" },
		{ _field_real_argb_color, "16" },
		{ _field_real_argb_color, "17" },
		{ _field_real_argb_color, "18" },
		{ _field_real_argb_color, "19" },
		{ _field_real_argb_color, "20" },
		{ _field_real_argb_color, "21" },
		{ _field_real_argb_color, "22" },
		{ _field_real_argb_color, "23" },
		{ _field_real_argb_color, "24" },
		{ _field_real_argb_color, "25" },
		{ _field_real_argb_color, "26" },
		{ _field_real_argb_color, "27" },
		{ _field_real_argb_color, "28" },
		{ _field_real_argb_color, "29" },
		{ _field_real_argb_color, "30" },
		{ _field_real_argb_color, "31" },
		{ _field_data, "32" },
		{ _field_data, "33" },
		{ _field_data, "34" },
		{ _field_data, "35" },
		{ _field_data, "36" },
		{ _field_data, "37" },
		{ _field_data, "38" },
		{ _field_data, "39" },
		{ _field_data, "40" },
		{ _field_data, "41" },
		{ _field_real, "blip above threshold max" },
		{ _field_real, "blip above threshold min" },
		{ _field_real, "blip below threshold min" },
		{ _field_real, "blip below threshold max" },
		{ _field_block, "HUD attributes", &chgd_hud_attributes_block_block },
		{ _field_block, "HUD sounds", &chgd_hud_sounds_block_block },
		{ _field_pad, "unknown", 4 },
		{ _field_tag_reference, "unknown", &global_sound_reference },
		{ _field_tag_reference, "frag grenade swap sound", &global_sound_reference },
		{ _field_tag_reference, "plasma grenade swap sound", &global_sound_reference },
		{ _field_byte_integer, "Unknown" },
		{ _field_byte_integer, "Unknown" },
		{ _field_byte_integer, "Unknown" },
		{ _field_byte_integer, "Unknown" },
		{ _field_tag_reference, "Damage Microtexture", &global_bitmap_reference },
		{ _field_real, "Microtexture Tile Scale" },
		{ _field_real, "Microtexture Screen Fraction" },
		{ _field_real, "Microtexture Inner Intensity" },
		{ _field_real, "Microtexture Center Screen Fraction" },
		{ _field_real, "Microtexture Outer Intensity" },
		{ _field_tag_reference, "Unknown", &global_bitmap_reference },
		{ _field_tag_reference, "Directional Arrow", &global_bitmap_reference },
		{ _field_tag_reference, "Directional Fast Forward Arrow", &global_bitmap_reference },
		{ _field_tag_reference, "Unknown", &global_bitmap_reference },
		{ _field_tag_reference, "Unknown", &global_bitmap_reference },
		{ _field_real, "Unknown" },
		{ _field_real, "Unknown" },
		{ _field_real, "Unknown" },
		{ _field_real, "Unknown" },
		{ _field_real, "Unknown" },
		{ _field_real, "Unknown" },
		{ _field_real, "Unknown" },
		{ _field_data, "Unknown" },
		{ _field_tag_reference, "Waypoints", &global_bitmap_reference },
		{ _field_tag_reference, "Scoreboard HUD", &chud_reference },
		{ _field_tag_reference, "Uber Scoreboard HUD", &chud_reference },
		{ _field_tag_reference, "Metagame Scoreboard HUD", &chud_reference },
		{ _field_tag_reference, "Survival Scoreboard HUD", &chud_reference },
		{ _field_tag_reference, "Theater HUD", &chud_reference },
		{ _field_tag_reference, "Forge HUD", &chud_reference },
		{ _field_tag_reference, "HUD Strings", &global_multilingual_unicode_string_list_reference },
		{ _field_tag_reference, "Medals", &global_bitmap_reference },
		{ _field_tag_reference, "Medal HUD Animation", &chud_animation_reference },
		{ _field_tag_reference, "Cortana Channel", &unknown_reference },
		{ _field_tag_reference, "Unknown", &unknown_reference },
		{ _field_tag_reference, "Unknown", &unknown_reference },
		{ _field_tag_reference, "Tracker Noise Flash Response", &unknown_reference },
		{ _field_tag_reference, "Tracker Noise Flash Sound", &unknown_reference },
		{ _field_real, "Grenade Scematics Spacing" },
		{ _field_real, "Equipment Scematic Offset y" },
		{ _field_real, "Dual Equipment Scematic Offset y" },
		{ _field_real, "Unknown Equipment Related" },
		{ _field_real, "Unknown Equipment Related" },
		{ _field_real, "Scoreboard Leader Offset y" },
		{ _field_real, "Unknown" },
		{ _field_real, "Waypoint Scale" },
		{ _field_real, "Unknown" },
		{ _field_real, "Unknown" },
		{ _field_real_argb_color, "Color" },
		{ _field_real, "Minor Threshold" },
		{ _field_real, "Major Threshold" },
		{ _field_real, "Critical Threshold" },
		{ _field_data, "Function" },
		{ _field_data, "Function" },
		{ _field_real, "Unknown" },
		{ _field_real, "Unknown" },
		{ _field_real_argb_color, "Color" },
		{ _field_real, "Minor Threshold" },
		{ _field_real, "Major Threshold" },
		{ _field_real, "Critical Threshold" },
		{ _field_data, "Function" },
		{ _field_data, "Function" },
		{ _field_terminator }
	};

	TAG_REFERENCE(unknown_reference);

	TAG_GROUP_FROM_BLOCK(chud_globals, CHUD_GLOBALS_TAG, chgd_block_block);
	TAG_BLOCK_FROM_STRUCT(chgd_block, 1, chgd_struct_definition_struct_definition);
	TAG_STRUCT(chgd_struct_definition)
	{
		{ _field_block, "hud globals", &chgd_hud_globals_block_block },
		{ _field_terminator }
	};
	TAG_REFERENCE(chud_globals_reference, CHUD_GLOBALS_TAG);

	STRINGS(biped_enum_definition)
	{
		"spartan",
		"elite",
		"monitor",
	};
	STRING_LIST(biped_enum_definition, biped_enum_definition_strings, _countof(biped_enum_definition_strings));
	
	STRINGS(resolution_flags_definition)
	{
		"wide full",
		"standard full",
		"wide/standard half",
		"wide quarter",
		"standard quarter",
		"bit 5",
		"bit 6",
		"bit 7",
	};
	STRING_LIST(resolution_flags_definition, resolution_flags_definition_strings, _countof(resolution_flags_definition_strings));

	STRINGS(latched_to_flags_definition)
	{
		"health recharging",
		"health minor",
		"health major",
		"health critical",
		"health low minor",
		"health low major",
		"health low critical",
		"shield recharging",
		"shield minor",
		"shield major",
		"shield critical",
		"shield minor state",
		"shield major state",
		"shield critical state",
		"rocket locking",
		"rocket locked",
		"missile locking",
		"missile locked",
		"bit 18",
		"bit 19",
		"bit 20",
		"bit 21",
		"bit 22",
		"bit 23",
		"bit 24",
		"bit 25",
		"bit 26",
		"bit 27",
		"bit 28",
		"bit 29",
		"bit 30",
		"bit 31",
	};
	STRING_LIST(latched_to_flags_definition, latched_to_flags_definition_strings, _countof(latched_to_flags_definition_strings));
}

