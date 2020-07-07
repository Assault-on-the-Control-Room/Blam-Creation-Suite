#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_INHERIT_FROM_BLOCK(item, ITEM_TAG, object, OBJECT_TAG, item_block_block );

	TAG_BLOCK(predicted_bitmaps_block, 8)
	{
		{ _field_tag_reference, "bitmap", &global_bitmap_reference },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(item_block, 1, item_struct_definition_struct_definition );

	TAG_STRUCT(item_struct_definition)
	{
		{ _field_struct, "object", &object_struct_definition_struct_definition },
		{ _field_custom, "$$$ ITEM $$$" },
		{ _field_long_flags, "flags", &item_definition_flags },
		{ _field_short_integer, "OLD message index" },
		{ _field_short_integer, "sort order" },
		{ _field_real, "OLD multiplayer on-ground scale" },
		{ _field_real, "OLD campaign on-ground scale" },
		{ _field_explanation, "NEW hud messages", "everything you need to display shite" },
		{ _field_string_id, "pickup message" },
		{ _field_string_id, "swap message" },
		{ _field_string_id, "pickup message (dual)" },
		{ _field_string_id, "swap message (dual)" },
		{ _field_string_id, "picked up msg" },
		{ _field_string_id, "switch-to msg" },
		{ _field_string_id, "switch-to from ai msg" },
		{ _field_string_id, "notify empty msg" },

		{ _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_string_id, "notify overheated message" },

		{ _field_tag_reference, "collision sound", &global_sound_reference },
		{ _field_block, "predicted bitmaps", &predicted_bitmaps_block_block },
		{ _field_tag_reference, "detonation damage effect", &global_damage_reference },
		{ _field_real_bounds, "detonation delay:seconds" },
		{ _field_tag_reference, "detonating effect", &global_effect_reference },
		{ _field_tag_reference, "detonation effect", &global_effect_reference },
		{ _field_explanation, "Item scale settings", "because grenades look better as coconuts. 0==1" },

		{ _field_version_less, _engine_type_haloreach, 2 },
		{ _field_real, "campaign ground scale" },
		{ _field_real, "multiplayer ground scale" },

		{ _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_real, "ground scale" },

		{ _field_real, "small unit (armed)" },
		{ _field_real, "small unit (stowed)" },
		{ _field_real, "medium unit (armed)" },
		{ _field_real, "medium unit (stowed)" },
		{ _field_real, "large unit (armed)" },
		{ _field_real, "large unit (stowed)" },
		{ _field_real, "huge unit (armed)" },
		{ _field_real, "huge unit (stowed)" },

		{ _field_version_less, _engine_type_haloreach, 2 },
		{ _field_real, "grounded friction length" },
		{ _field_real, "grounded friction unknown" },

		{ _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_tag_reference, "grounded friction settings#If not present, the default from global.globals is used.", &global_grounded_friction_reference },

		{ _field_version_greater, _engine_type_haloreach },
		{ _field_tag_reference, "Tossed Override# Used to override the object tossed when item owner is killed.  Is overridden by tossed weapon override.", &object_reference$3 },

		{ _field_custom },
		{ _field_terminator }
	};

	STRINGS(item_definition_flags)
	{
		"always maintains z up",
		"blocks headshots#like jackal shield",
		"use ground scale for all unspecified attachments",
		"fixup position upon detaching from parent",
		"fixup position after attaching to parent"
	};
	STRING_LIST(item_definition_flags, item_definition_flags_strings, _countof(item_definition_flags_strings));

	TAG_REFERENCE(object_reference$3, OBJECT_TAG);

	TAG_REFERENCE(global_item_reference, ITEM_TAG);

} // namespace blofeld

