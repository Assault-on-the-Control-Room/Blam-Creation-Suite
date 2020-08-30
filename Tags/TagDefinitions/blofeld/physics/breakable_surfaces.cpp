#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(breakable_surface, BREAKABLE_SURFACE_TAG, breakable_surface_block_block );

	TAG_BLOCK_FROM_STRUCT(breakable_surface_block, 1, breakable_surface_struct_definition_struct_definition );

	TAG_STRUCT(breakable_surface_struct_definition)
	{
		{ _field_version_less, _engine_type_haloreach },
		{ _field_real, "vitality" },

		{ _field_version_greater_or_equal, _engine_type_haloreach, 4 },
		{ _field_explanation, "VITALITY", "If the damage is below the lower bound, the surface won\'t break.\nIf the damage is above the upper bound, the surface always breaks.\nIn the middle, the surface will break with a weighted random chance.\nNegative values mean that the surface will never break from that kind of damage." },
		{ _field_real_bounds, "direct damage vitality#this is damage from bullets hitting the surface" },
		{ _field_real_bounds, "collision damage impulse thresholds#not really vitality - this is mass * velocity into the surface.  Running player bipeds cap out around 255\nrun \'event_display_category physics:breakable_surfaces verbose\' to get verbose information about damage to breakable surfaces" },
		{ _field_real_bounds, "AoE damage vitality!#not actually in use yet..." },

		{ _field_tag_reference, "effect", &global_effect_reference },
		{ _field_tag_reference, "sound", &global_sound_reference },
		{ _field_block, "particle effects", &particle_system_definition_block_new_block }, // This block and associated real could just be padding in H3, not sure
		{ _field_real, "particle density" },
		{ _field_tag_reference, "crack bitmap", &global_bitmap_reference },
		{ _field_tag_reference, "hole bitmap", &global_bitmap_reference },
		{ _field_terminator }
	};

	TAG_REFERENCE(global_breakable_surface_reference, BREAKABLE_SURFACE_TAG);

} // namespace blofeld

