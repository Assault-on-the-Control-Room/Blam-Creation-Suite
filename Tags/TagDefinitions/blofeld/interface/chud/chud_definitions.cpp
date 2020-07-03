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

	TAG_BLOCK(chgd_waypoint_blips_block, 65536)
	{
		{ _field_string_id, "title" },
		{ _field_string_id, "description" },
		{ _field_char_enum, "icon", &icon_enum_definition },
		{ _field_byte_integer, "unknown" },
		{ _field_short_integer, "unknown" },
		{ _field_real_argb_color, "primary color" },
		{ _field_real_argb_color, "secondary color" },
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
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_tag_reference, "damage microtexture", &global_bitmap_reference },
		{ _field_real, "microtexture tile scale" },
		{ _field_real, "microtexture screen fraction" },
		{ _field_real, "microtexture inner intensity" },
		{ _field_real, "microtexture center screen fraction" },
		{ _field_real, "microtexture outer intensity" },
		{ _field_tag_reference, "unknown", &global_bitmap_reference },
		{ _field_tag_reference, "directional arrow", &global_bitmap_reference },
		{ _field_tag_reference, "directional fast forward arrow", &global_bitmap_reference },
		{ _field_tag_reference, "unknown", &global_bitmap_reference },
		{ _field_tag_reference, "unknown", &global_bitmap_reference },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_data, "unknown" },
		{ _field_tag_reference, "waypoints", &global_bitmap_reference },
		{ _field_tag_reference, "scoreboard HUD", &chud_reference },
		{ _field_tag_reference, "uber scoreboard HUD", &chud_reference },
		{ _field_tag_reference, "metagame scoreboard HUD", &chud_reference },
		{ _field_tag_reference, "survival scoreboard HUD", &chud_reference },
		{ _field_tag_reference, "theater HUD", &chud_reference },
		{ _field_tag_reference, "forge HUD", &chud_reference },
		{ _field_tag_reference, "HUD strings", &global_multilingual_unicode_string_list_reference },
		{ _field_tag_reference, "medals", &global_bitmap_reference },
		{ _field_tag_reference, "medal HUD animation", &chud_animation_reference },
		{ _field_tag_reference, "cortana channel", &unknown_reference },
		{ _field_tag_reference, "unknown", &unknown_reference },
		{ _field_tag_reference, "unknown", &unknown_reference },
		{ _field_tag_reference, "tracker noise flash response", &unknown_reference },
		{ _field_tag_reference, "tracker noise flash sound", &unknown_reference },
		{ _field_real, "grenade scematics spacing" },
		{ _field_real, "equipment scematic offset y" },
		{ _field_real, "dual equipment scematic offset y" },
		{ _field_real, "unknown equipment related" },
		{ _field_real, "unknown equipment related" },
		{ _field_real, "scoreboard leader offset y" },
		{ _field_real, "unknown" },
		{ _field_real, "waypoint scale" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real_argb_color, "color" },
		{ _field_real, "minor threshold" },
		{ _field_real, "major threshold" },
		{ _field_real, "critical threshold" },
		{ _field_data, "function" },
		{ _field_data, "function" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real_argb_color, "color" },
		{ _field_real, "minor threshold" },
		{ _field_real, "major threshold" },
		{ _field_real, "critical threshold" },
		{ _field_data, "function" },
		{ _field_data, "function" },
		{ _field_block, "waypoint blips", &chgd_waypoint_blips_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(chgd_shaders_block, 65536)
	{
		{ _field_tag_reference, "vertex shader", & global_vertex_shader_reference },
		{ _field_tag_reference, "pixel shader", &global_pixel_shader_reference },
		{ _field_terminator }
	};

	TAG_BLOCK(chgd_unknown_block, 65536)
	{
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
		{ _field_terminator }
	};

	TAG_BLOCK(chgd_player_training_data_block, 65536)
	{
		{ _field_string_id, "Display String" },
		{ _field_short_integer, "Max Display Time" },
		{ _field_short_integer, "Display Count" },
		{ _field_short_integer, "Disappear Delay" },
		{ _field_short_integer, "Redisplay Delay" },
		{ _field_real, "Display Delay" },
		{ _field_word_flags, "flags", &player_training_flags_definition },
		{ _field_short_integer, "Unknown" },
		{ _field_terminator }
	};

	TAG_BLOCK(chgd_state_triggers_block, 65536)
	{
		{ _field_long_integer, "trigger index" },
		{ _field_string, "type" },
		{ _field_terminator }
	};

	TAG_REFERENCE(unknown_reference);

	TAG_GROUP_FROM_BLOCK(chud_globals, CHUD_GLOBALS_TAG, chgd_block_block);
	TAG_BLOCK_FROM_STRUCT(chgd_block, 1, chgd_struct_definition_struct_definition);
	TAG_STRUCT(chgd_struct_definition)
	{
		{ _field_block, "hud globals", &chgd_hud_globals_block_block },
		{ _field_block, "shaders", &chgd_shaders_block_block },
		{ _field_block, "unknown", &chgd_unknown_block_block },
		{ _field_block, "player training data", &chgd_player_training_data_block_block },
		{ _field_tag_reference, "start menu emblems", &global_bitmap_reference },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_real, "campaign medal scale" },
		{ _field_real, "campaign medal spacing" },
		{ _field_real, "campaign medal offset x" },
		{ _field_real, "campaign medal offset y" },
		{ _field_real, "metagame scoreboard top y" },
		{ _field_real, "metagame scoreboard spacing" },
		{ _field_tag_reference, "unknown", &unknown_reference },
		{ _field_long_integer, "unknown@" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_real, "medium sensor blip scale" },
		{ _field_real, "small sensor blip scale" },
		{ _field_real, "large sensor blip scale" },
		{ _field_real, "vehicle sensor range" },
		{ _field_real, "sensor angle" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_data, "unknown" },
		{ _field_data, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_tag_reference, "motion sensor triangulation field", &global_bitmap_reference },
		{ _field_tag_reference, "motion sensor blip", &global_bitmap_reference },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_real, "unknown" },
		{ _field_tag_reference, "unknown", &unknown_reference },
		{ _field_long_integer, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_real, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_real, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_real, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "alpha?" },
		{ _field_real, "r?" },
		{ _field_real, "g?" },
		{ _field_real, "b?" },
		{ _field_real, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_real, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_tag_reference, "unknown waypoint bitmap", &global_bitmap_reference },
		{ _field_byte_integer, "sequence index" },
		{ _field_byte_integer, "sprite index" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_tag_reference, "unknown waypoint bitmap", &global_bitmap_reference },
		{ _field_byte_integer, "sequence index" },
		{ _field_byte_integer, "sprite index" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_tag_reference, "unknown waypoint bitmap", &global_bitmap_reference },
		{ _field_byte_integer, "sequence index" },
		{ _field_byte_integer, "sprite index" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_tag_reference, "unknown waypoint bitmap", &global_bitmap_reference },
		{ _field_byte_integer, "sequence index" },
		{ _field_byte_integer, "sprite index" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_tag_reference, "unknown waypoint bitmap", &global_bitmap_reference },
		{ _field_byte_integer, "sequence index" },
		{ _field_byte_integer, "sprite index" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_tag_reference, "unknown waypoint bitmap", &global_bitmap_reference },
		{ _field_byte_integer, "sequence index" },
		{ _field_byte_integer, "sprite index" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_tag_reference, "unknown waypoint bitmap", &global_bitmap_reference },
		{ _field_byte_integer, "sequence index" },
		{ _field_byte_integer, "sprite index" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_tag_reference, "unknown waypoint bitmap", &global_bitmap_reference },
		{ _field_byte_integer, "sequence index" },
		{ _field_byte_integer, "sprite index" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_tag_reference, "unknown waypoint bitmap", &global_bitmap_reference },
		{ _field_byte_integer, "sequence index" },
		{ _field_byte_integer, "sprite index" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_tag_reference, "unknown waypoint bitmap", &global_bitmap_reference },
		{ _field_byte_integer, "sequence index" },
		{ _field_byte_integer, "sprite index" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_tag_reference, "unknown waypoint bitmap", &global_bitmap_reference },
		{ _field_byte_integer, "sequence index" },
		{ _field_byte_integer, "sprite index" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_tag_reference, "unknown waypoint bitmap", &global_bitmap_reference },
		{ _field_byte_integer, "sequence index" },
		{ _field_byte_integer, "sprite index" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_tag_reference, "unknown waypoint bitmap", &global_bitmap_reference },
		{ _field_byte_integer, "sequence index" },
		{ _field_byte_integer, "sprite index" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_tag_reference, "unknown waypoint bitmap", &global_bitmap_reference },
		{ _field_byte_integer, "sequence index" },
		{ _field_byte_integer, "sprite index" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_tag_reference, "unknown waypoint bitmap", &global_bitmap_reference },
		{ _field_byte_integer, "sequence index" },
		{ _field_byte_integer, "sprite index" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_tag_reference, "unknown waypoint bitmap", &global_bitmap_reference },
		{ _field_byte_integer, "sequence index" },
		{ _field_byte_integer, "sprite index" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_tag_reference, "unknown waypoint bitmap", &global_bitmap_reference },
		{ _field_byte_integer, "sequence index" },
		{ _field_byte_integer, "sprite index" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_tag_reference, "unknown waypoint bitmap", &global_bitmap_reference },
		{ _field_byte_integer, "sequence index" },
		{ _field_byte_integer, "sprite index" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_tag_reference, "unknown waypoint bitmap", &global_bitmap_reference },
		{ _field_byte_integer, "sequence index" },
		{ _field_byte_integer, "sprite index" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_tag_reference, "unknown waypoint bitmap", &global_bitmap_reference },
		{ _field_byte_integer, "sequence index" },
		{ _field_byte_integer, "sprite index" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_tag_reference, "unknown waypoint bitmap", &global_bitmap_reference },
		{ _field_byte_integer, "sequence index" },
		{ _field_byte_integer, "sprite index" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_tag_reference, "unknown waypoint bitmap", &global_bitmap_reference },
		{ _field_byte_integer, "sequence index" },
		{ _field_byte_integer, "sprite index" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_tag_reference, "unknown waypoint bitmap", &global_bitmap_reference },
		{ _field_byte_integer, "sequence index" },
		{ _field_byte_integer, "sprite index" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_tag_reference, "unknown waypoint bitmap", &global_bitmap_reference },
		{ _field_byte_integer, "sequence index" },
		{ _field_byte_integer, "sprite index" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_tag_reference, "unknown waypoint bitmap", &global_bitmap_reference },
		{ _field_byte_integer, "sequence index" },
		{ _field_byte_integer, "sprite index" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_tag_reference, "unknown waypoint bitmap", &global_bitmap_reference },
		{ _field_byte_integer, "sequence index" },
		{ _field_byte_integer, "sprite index" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_byte_integer, "unknown" },
		{ _field_explanation, "state triggers list (the below block, sorted)",
"0   general game state/weapon state"
"\n1   general / fireteam member state"
"\n2   general"
"\n3   general"
"\n4   general"
"\n5   general"
"\n6   general"
"\n7   unknown"
"\n8   campaign game state"
"\n9   campaign game state"
"\n10   campaign game state - mission hud 1"
"\n11   campaign game state - mission hud 2"
"\n12   campaign game state - mission hud 3"
"\n13   unknown"
"\n14   unknown"
"\n15   unknown"
"\n16   unknown"
"\n17   unknown"
"\n18   unit state - training prompt"
"\n19   unit state - objective prompt"
"\n20   unknown"
"\n21   unit state - spartan fireteams"
"\n22   unit state - elite fireteams"
"\n23   unit state"
"\n24   unit state"
"\n25   general / unit state"
"\n26   unit state"
"\n27   unit state"
"\n28   unit state"
"\n29   unit state"
"\n30   unit state"
"\n31   unit state"
"\n32   unit state - has shields"
"\n33   unit state - has 1x overshield"
"\n34   unit state - has 2x overshield"
"\n35   unit state - has 3x overshield"
"\n36   unit state"
"\n37   unit state"
"\n38   unit state - motion tracker 10m"
"\n39   unit state - motion tracker 25m"
"\n40   unit state - motion tracker 75m"
"\n41   unit state - motion tracker 150m"
"\n42   unit state"
"\n43   unit state"
"\n44   unit state"
"\n45   unit state"
"\n46   campaign game state - motion tracker enabled"
"\n47   unit state - motion tracker disabled"
"\n48   unit state"
"\n49   unit state"
"\n50   unit state"
"\n51   unit state"
"\n52   unit state"
"\n53   unknown"
"\n54   unknown"
"\n55   unit state"
"\n56   unit state"
"\n57   unknown"
"\n58   unit state"
"\n59   unit state"
"\n60   unit state"
"\n61   unit state - talking disabled"
"\n62   unit state - tap to talk"
"\n63   unit state - talking"
"\n64   unit state - not talking"
"\n65   unit state - talking enabled"
"\n66   campaign game state"
"\n67   unknown"
"\n68   unknown"
"\n69   unknown"
"\n70   unknown"
"\n71   unknown"
"\n72   weapon state"
"\n73   weapon state"
"\n74   unit state"
"\n75   unit state"
"\n76   unit state"
"\n77   unit state - out of bounds"
"\n78   unit state - altitude locked"
"\n79   unknown"
"\n80   unknown"
"\n81   unknown"
"\n82   weapon state"
"\n83   weapon state - binoculars enabled"
"\n84   weapon state - not zoomed ?"
"\n85   weapon state - unit is zoomed(level 1)"
"\n86   weapon state - unit is zoomed(level 2)"
"\n87   weapon state"
"\n88   weapon state"
"\n89   weapon state"
"\n90   weapon state"
"\n91   weapon state - autoaimed ?"
"\n92   weapon state"
"\n93   weapon state"
"\n94   weapon state"
"\n95   weapon state"
"\n96   weapon state"
"\n97   weapon state - primary weapon"
"\n98   weapon state - secondary weapon"
"\n99   weapon state - backpack"
"\n100   weapon state"
"\n101   weapon state"
"\n102   weapon state"
"\n103   weapon state - autoaim headshot"
"\n104   weapon state"
"\n105   weapon state"
"\n106   weapon state"
"\n107   weapon state - clip warning"
"\n108   weapon state - ammo warning"
"\n109   weapon state"
"\n110   weapon state"
"\n111   weapon state - low battery 1"
"\n112   weapon state - low battery 2"
"\n113   weapon state - overheated"
"\n114   weapon state - plasma locking"
"\n115   weapon state - missile locked"
"\n116   weapon state - missile locking"
"\n117   weapon state"
"\n118   weapon state"
"\n119   weapon state - pickup ammo"
"\n120   general game state"
"\n121   general game state"
"\n122   general game state"
"\n123   general game state"
"\n124   general game state / campaign fireteams"
"\n125   campaign fireteams"
"\n126   campaign fireteams"
"\n127   campaign fireteams"
"\n128   campaign fireteams"
"\n129   campaign fireteams"
"\n130   campaign fireteams"
"\n131   campaign fireteams"
"\n132   campaign fireteams"
"\n133   campaign fireteams"
"\n134   campaign fireteams"
"\n135   campaign fireteams"
"\n136   campaign fireteams"
"\n137   campaign fireteams"
"\n138   campaign fireteams"
"\n139   campaign fireteams"
"\n140   campaign fireteams"
"\n141   campaign fireteams"
"\n142   campaign fireteams"
"\n143   campaign fireteams"
"\n144   campaign fireteams"
"\n145   campaign fireteams"
"\n146   campaign fireteams"
"\n147   campaign fireteams"
"\n148   awards"
"\n149   awards"
"\n150   awards"
"\n151   awards"
"\n152   awards"
"\n153   awards"
"\n154   awards"
"\n155   awards"
"\n156   awards"
"\n157   datasource objects and players"
"\n158   datasource objects and players"
"\n159   datasource objects and players"
"\n160   datasource objects and players"
"\n161   datasource objects and players"
"\n162   datasource objects and players"
"\n163   datasource objects and players"
"\n164   datasource objects and players"
"\n165   datasource objects and players"
"\n166   datasource objects and players"
"\n167   datasource objects and players"
"\n168   datasource objects and players"
"\n169   general game state"
"\n170   awards"
"\n171   awards"
"\n172   awards"
"\n173   awards"
"\n174   awards"
"\n175   awards"
"\n176   awards"
"\n177   awards - credits awarded"
"\n178   campaign game state"
"\n179   campaign game state"
"\n180   firefight"
"\n181   general game state"
"\n182   general game state"
"\n183   general game state"
"\n184   general game state"
"\n185   campaign game state"
"\n186   campaign game state / firefight"
"\n187   campaign game state / firefight"
"\n188   campaign game state"
"\n189   campaign game state - player 2 exists"
"\n190   campaign game state"
"\n191   campaign game state - player 3 exists"
"\n192   campaign game state"
"\n193   campaign game state - player 4 exists"
"\n194   campaign game state"
"\n195   campaign game state - score added"
"\n196   campaign game state"
"\n197   campaign game state - score removed"
"\n198   campaign game state"
"\n199   campaign game state"
"\n200   datasource objects and players - generators enabled"
"\n201   datasource objects and players"
"\n202   datasource objects and players"
"\n203   datasource objects and players"
"\n204   datasource objects and players"
"\n205   datasource objects and players"
"\n206   datasource objects and players"
"\n207   datasource objects and players"
"\n208   datasource objects and players"
"\n209   datasource objects and players"
"\n210   datasource objects and players"
"\n211   datasource objects and players"
"\n212   datasource objects and players"
"\n213   datasource objects and players"
"\n214   datasource objects and players"
"\n215   datasource objects and players"
"\n216   datasource objects and players"
"\n217   datasource objects and players"
"\n218   datasource objects and players"
"\n219   datasource objects and players"
"\n220   datasource objects and players"
"\n221   datasource objects and players"
"\n222   datasource objects and players"
"\n223   datasource objects and players"
"\n224   datasource objects and players"
"\n225   datasource objects and players"
"\n226   datasource objects and players"
"\n227   datasource objects and players"
"\n228   datasource objects and players"
"\n229   datasource objects and players"
"\n230   datasource objects and players"
"\n231   datasource objects and players"
"\n232   datasource objects and players"
"\n233   datasource objects and players"
"\n234   datasource objects and players"
"\n235   firefight - waves background"
"\n236   firefight - wave 1"
"\n237   firefight - wave 2"
"\n238   firefight - wave 3"
"\n239   firefight - wave 4"
"\n240   firefight - wave 5"
"\n241   firefight"
"\n242   firefight"
"\n243   firefight"
"\n244   firefight"
"\n245   firefight - round 0"
"\n246   firefight - round 1"
"\n247   firefight - round 2"
"\n248   firefight - round 3"
"\n249   firefight"
"\n250   firefight"
"\n251   firefight"
"\n252   firefight"
"\n253   firefight"
"\n254   firefight"
"\n255   firefight"
"\n256   firefight"
"\n257   firefight"
"\n258   firefight"
"\n259   firefight"
"\n260   firefight"
"\n261   firefight"
"\n262   firefight - bonus round enabled"
"\n263   multiplayer game engine state - free for all"
"\n264   multiplayer game engine state - teams enabled"
"\n265   multiplayer game engine state"
"\n266   megalo"
"\n267   multiplayer game engine state"
"\n268   multiplayer game engine state"
"\n269   multiplayer game engine state"
"\n270   multiplayer game engine state"
"\n271   multiplayer game engine state"
"\n272   multiplayer game engine state - has friends"
"\n273   multiplayer game engine state - has enemies"
"\n274   multiplayer game engine state - has variant name ?"
"\n275   multiplayer game engine state - gametype plate 1"
"\n276   multiplayer game engine state - gametype plate 2"
"\n277   multiplayer game engine state - someone is talking"
"\n278   multiplayer game engine state - is arming"
"\n279   multiplayer game engine state - time enabled"
"\n280   multiplayer game engine state - friends have x"
"\n281   multiplayer game engine state - enemies have x"
"\n282   multiplayer game engine state - friends are x"
"\n283   multiplayer game engine state - enemies are x"
"\n284   multiplayer game engine state - x is down"
"\n285   multiplayer game engine state"
"\n286   multiplayer game engine state"
"\n287   multiplayer game engine state"
"\n288   multiplayer game engine state - summary enabled"
"\n289   multiplayer game engine state - netdebug"
"\n290   megalo - omniwidget enabled"
"\n291   megalo - omniwidget label"
"\n292   megalo - omniwidget value"
"\n293   megalo - omniwidget meter"
"\n294   megalo - omniwidget icon"
"\n295   megalo"
"\n296   fireteam member state"
"\n297   fireteam member state - someone is spawning on you"
"\n298   fireteam member state"
"\n299   fireteam member state"
"\n300   fireteam member state"
"\n301   fireteam member state"
"\n302   fireteam member state"
"\n303   fireteam member state"
"\n304   fireteam member state"
"\n305   fireteam member state"
"\n306   fireteam member state"
"\n307   fireteam member state"
"\n308   fireteam member state"
"\n309   fireteam member state"
"\n310   fireteam member state"
"\n311   fireteam member state"
"\n312   fireteam member state"
"\n313   fireteam member state"
"\n314   fireteam member state"
"\n315   fireteam member state"
"\n316   fireteam member state"
"\n317   fireteam member state"
"\n318   fireteam member state"
"\n319   forge state - is editor biped"
"\n320   weapon state - editor inactive"
"\n321   weapon state - editor active"
"\n322   weapon state - editor holding"
"\n323   weapon state - editor not allowed"
"\n324   weapon state"
"\n325   saved film state - is theater"
"\n326   saved film state"
"\n327   saved film state" },
		{ _field_block, "state triggers", &chgd_state_triggers_block_block },
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

	STRINGS(icon_enum_definition)
	{
		"null",
		"neutralize",
		"defend",
		"ordnance",
		"interface",
		"scope",
		"recover",
		"arrow",
		"hostile",
		"ammo",
		"recon",
		"structure",
		"blank",
	};
	STRING_LIST(icon_enum_definition, icon_enum_definition_strings, _countof(icon_enum_definition_strings));

	STRINGS(player_training_flags_definition)
	{
		"not in multiplayer",
		"bit 1",
		"bit 2",
		"bit 3",
		"bit 4",
		"bit 5",
		"bit 6",
		"bit 7",
		"bit 8",
		"bit 9",
		"bit 10",
		"bit 11",
		"bit 12",
		"bit 13",
		"bit 14",
		"bit 15",
	};
	STRING_LIST(player_training_flags_definition, player_training_flags_definition_strings, _countof(player_training_flags_definition_strings));
}
