#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(airstrike, AIRSTRIKE_TAG, airstrike_block_block );

	TAG_BLOCK(airstrike_fire_location_block, s_airstrike_battery_definition::max_fire_locations)
	{
		{ _field_real_point_2d, "offset" },
		{ _field_terminator }
	};

	TAG_BLOCK(airstrike_battery_block, AirStrikeDefinition::k_max_airstrike_batteries)
	{
		{ _field_real, "launch radius:wu#each shot will be fired with a random offset in this radius in the x/y plane above the target location" },
		{ _field_real, "launch z height:wu#strike will be launched at this plane height above the target location" },
		{ _field_real, "launch warmup:seconds#seconds to wait before launching the strike" },
		{ _field_real, "launch arrival:seconds#seconds to wait until the launch site marker is removed" },
		{ _field_real, "launch cooldown:seconds#seconds to wait before the next launch will be ready" },
		{ _field_real, "launch duration:seconds#how long a launch should take to fire all rounds" },
		{ _field_long_integer, "shots per launch#number of rounds to fire per launch" },

		{ _field_version_equal, _engine_type_haloreach },
		{ _field_long_integer, "default shot count" },

		{ _field_tag_reference, "fire effect#the effect that will be created when the strike fires.", &global_effect_reference },

		{ _field_version_greater, _engine_type_haloreach },
		{ _field_tag_reference, "fire effect (indoor)#the effect that will be created when the strike fires and is indoors", &global_effect_reference },

		{ _field_block, "fire offsets", &airstrike_fire_location_block_block },

		{ _field_version_equal, _engine_type_haloreach },
		{ _field_tag_reference, "affected weapon", &weapon_reference },

		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(airstrike_block, 1, airstrike_struct_definition_struct_definition );

	TAG_STRUCT(airstrike_struct_definition)
	{
		{ _field_block, "batteries", &airstrike_battery_block_block },
		{ _field_terminator }
	};

} // namespace blofeld

