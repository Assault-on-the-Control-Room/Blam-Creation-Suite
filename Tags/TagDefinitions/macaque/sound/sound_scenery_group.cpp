#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		sound_scenery_group,
		SOUND_SCENERY_TAG,
		&object_group,
		OBJECT_TAG,
		sound_scenery_block );

	TAG_BLOCK_FROM_STRUCT(
		sound_scenery_block,
		"sound_scenery_block",
		1,
		sound_scenery_struct_definition);

	#define SOUND_SCENERY_STRUCT_DEFINITION_ID { 0xD4C4A75B, 0x96954D6A, 0xBB77085F, 0xD4396EF5 }
	TAG_STRUCT(
		sound_scenery_struct_definition,
		"sound_scenery_struct_definition",
		"_sound_scenery_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN4 | SET_UNKNOWN5 | 
		SET_UNKNOWN7 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS | 
		SET_UNKNOWN18,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SOUND_SCENERY_STRUCT_DEFINITION_ID)
	{
		{ _field_struct, "object", &object_struct_definition },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 4 },
		{ _field_real, "obstruction cutoff frequency:Hz" },
		{ _field_real, "obstruction output gain:dB" },
		{ _field_real, "occlusion cutoff frequency:Hz" },
		{ _field_real, "occlusion output gain:dB" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 5 },
		{ _field_long_integer, "YJNXHAWAO1", FIELD_FLAG_UNKNOWN0 },
		{ _field_long_integer, "YJNXHAWAO2", FIELD_FLAG_UNKNOWN0 },
		{ _field_long_integer, "YJNXHAWAO3", FIELD_FLAG_UNKNOWN0 },
		{ _field_long_integer, "YJNXHAWAO4", FIELD_FLAG_UNKNOWN0 },
		{ _field_useless_pad, "" },

		{ _field_terminator }
	};

} // namespace macaque

} // namespace blofeld

