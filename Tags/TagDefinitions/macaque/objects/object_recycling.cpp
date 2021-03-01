#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define GARBAGE_COLLECTION_BLOCK_ID { 0x49B147E0, 0x863C4847, 0xBE1348AA, 0x6BC92D7E }
	TAG_BLOCK(
		garbage_collection_block,
		"garbage_collection_block",
		1,
		"s_garbage_collection_globals",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		GARBAGE_COLLECTION_BLOCK_ID)
	{
		FIELD_EXPLANATION("Garbage Times", nullptr, FIELD_FLAG_NONE, "time before the game considers that following entities as garbage"),
		{ _field_real, "Dropped item", nullptr, "seconds" },
		{ _field_real, "Dropped item by player", nullptr, "seconds" },
		{ _field_real, "Dropped item in multiplayer", nullptr, "seconds" },
		{ _field_real, "Broken constraints", nullptr, "seconds" },
		{ _field_real, "Dead unit", nullptr, "seconds" },
		{ _field_real, "Dead player", nullptr, "seconds" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 3 }, // #NOTE: Chose this point to shorten struct simply becaues all data appears to be zero
		{ _field_real, "Dead MP Player", nullptr, "seconds" },
		{ _field_real, "Dead MP Player overloaded", nullptr, "seconds" },
		{ _field_long_integer, "Max dead body count ", "above this number, overloaded mp time is used to garbage collect dead bodies" },

		{ _field_terminator }
	};

} // namespace macaque

} // namespace blofeld

