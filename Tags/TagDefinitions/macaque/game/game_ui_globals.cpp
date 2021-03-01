#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define INTERFACE_TAG_REFERENCES_ID { 0xEAFCBD42, 0x27264DFB, 0x9C2624C1, 0x928B0D3C }
	TAG_BLOCK(
		interface_tag_references_block,
		"interface_tag_references",
		1,
		"s_game_globals_interface_tag_references",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		INTERFACE_TAG_REFERENCES_ID)
	{
		{ _field_tag_reference, "spinner bitmap", &global_bitmap_reference },
		{ _field_tag_reference, "obsolete2", &global_bitmap_reference },
		{ _field_tag_reference, "screen color table", &global_color_table_reference },
		{ _field_tag_reference, "hud color table", &global_color_table_reference },
		{ _field_tag_reference, "editor color table", &global_color_table_reference },
		{ _field_tag_reference, "dialog color table", &global_color_table_reference },
		{ _field_tag_reference, "motion sensor sweep bitmap", &global_bitmap_reference },
		{ _field_tag_reference, "motion sensor sweep bitmap mask", &global_bitmap_reference },
		{ _field_tag_reference, "multiplayer hud bitmap", &global_bitmap_reference },
		{ _field_tag_reference, "unused", FIELD_FLAG_UNKNOWN0, &g_non_traversed_reference_definition },
		{ _field_tag_reference, "motion sensor blip bitmap", &global_bitmap_reference },
		{ _field_tag_reference, "interface goo map1", &global_bitmap_reference },
		{ _field_tag_reference, "interface goo map2", &global_bitmap_reference },
		{ _field_tag_reference, "interface goo map3", &global_bitmap_reference },
		{ _field_tag_reference, "mainmenu ui globals", &g_user_interface_globals_reference },
		{ _field_tag_reference, "singleplayer ui globals", &g_user_interface_globals_reference },
		{ _field_tag_reference, "multiplayer ui globals", &g_user_interface_globals_reference },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_tag_reference, "firefight ui globals", &g_user_interface_globals_reference },
		{ _field_tag_reference, "style sheet globals", &style_sheets_global_reference },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_tag_reference, "HUD globals", &character_reference }, // chgd

		{ _field_terminator }
	};

} // namespace macaque

} // namespace blofeld

