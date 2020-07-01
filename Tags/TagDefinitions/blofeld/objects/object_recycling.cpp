#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_BLOCK(garbage_collection_block, 1)
	{
		{ _field_explanation, "Garbage Times", "time before the game considers that following entities as garbage" },
		{ _field_real, "Dropped item:seconds" },
		{ _field_real, "Dropped item by player:seconds" },
		{ _field_real, "Dropped item in multiplayer:seconds" },
		{ _field_real, "Broken constraints:seconds" },
		{ _field_real, "Dead unit:seconds" },
		{ _field_real, "Dead player:seconds" },

		{ _field_version_greater, _engine_type_haloreach, 3 }, // #NOTE: Chose this point to shorten struct simply becaues all data appears to be zero
		{ _field_real, "Dead MP Player:seconds" },
		{ _field_real, "Dead MP Player overloaded: seconds" },
		{ _field_long_integer, "Max dead body count #above this number, overloaded mp time is used to garbage collect dead bodies" },

		{ _field_terminator }
	};

} // namespace blofeld

