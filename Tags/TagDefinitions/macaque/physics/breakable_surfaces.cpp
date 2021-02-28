#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		breakable_surface_group,
		BREAKABLE_SURFACE_TAG,
		nullptr,
		INVALID_TAG,
		breakable_surface_block );

	TAG_BLOCK_FROM_STRUCT(
		breakable_surface_block,
		"breakable_surface_block",
		1,
		breakable_surface_struct_definition);

	#define BREAKABLE_SURFACE_STRUCT_DEFINITION_ID { 0x7CC19130, 0xBD5344AB, 0x8BA2CB75, 0xDAA60C73 }
	TAG_STRUCT(
		breakable_surface_struct_definition,
		"breakable_surface_struct_definition",
		"s_breakable_surface_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		BREAKABLE_SURFACE_STRUCT_DEFINITION_ID)
	{
		{ _field_legacy, _field_version_less, _engine_type_haloreach },
		{ _field_legacy, _field_real, "vitality" },
		
		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach, 4 },
		FIELD_EXPLANATION("VITALITY", nullptr, FIELD_FLAG_NONE, "If the damage is below the lower bound, the surface won\'t break.\nIf the damage is above the upper bound, the surface always breaks.\nIn the middle, the surface will break with a weighted random chance.\nNegative values mean that the surface will never break from that kind of damage."),
		{ _field_real_bounds, "direct damage vitality", "this is damage from bullets hitting the surface" },
		{ _field_real_bounds, "collision damage impulse thresholds", "not really vitality - this is mass * velocity into the surface.  Running player bipeds cap out around 255\nrun 'event_display_category physics:breakable_surfaces verbose' to get verbose information about damage to breakable surfaces" },
		{ _field_real_bounds, "AoE damage vitality", "not actually in use yet...", FIELD_FLAG_UNKNOWN0 },
		
		{ _field_tag_reference, "effect", &global_effect_reference },
		{ _field_tag_reference, "sound", &global_sound_reference },
		{ _field_block, "particle effects", &particle_system_definition_block_new_block },
		{ _field_real, "particle density" },
		{ _field_tag_reference, "crack bitmap", &global_bitmap_reference },
		{ _field_tag_reference, "hole bitmap", &global_bitmap_reference },
		{ _field_terminator }
	};

	TAG_REFERENCE(global_breakable_surface_reference, BREAKABLE_SURFACE_TAG);

} // namespace macaque

} // namespace blofeld

