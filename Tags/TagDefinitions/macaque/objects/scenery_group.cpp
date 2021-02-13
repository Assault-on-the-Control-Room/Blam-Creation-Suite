#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		scenery_group,
		SCENERY_TAG,
		&object_group,
		OBJECT_TAG,
		scenery_block );

	TAG_BLOCK_FROM_STRUCT(
		scenery_block,
		"scenery",
		1,
		scenery_struct_definition);

	#define SCENERY_STRUCT_DEFINITION_ID { 0x8EF5AC73, 0xE1C843B9, 0xA15CC8AA, 0xC9F15E5C }
	TAG_STRUCT(
		scenery_struct_definition,
		"scenery",
		"scenery_group",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN4 | SET_UNKNOWN5 | 
		SET_UNKNOWN7 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS | 
		SET_UNKNOWN18,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SCENERY_STRUCT_DEFINITION_ID)
	{
		{ _field_struct, "object", &object_struct_definition },
		FIELD_EXPLANATION("Pathfinding", nullptr, FIELD_FLAG_NONE, "Indicate whether, by default, we should create pathfinding data for this type of scenery"),
		{ _field_enum, "pathfinding policy", &pathfinding_policy_enum },
		{ _field_word_flags, "flags", &scenery_flags },
		FIELD_EXPLANATION("Lightmapping", nullptr, FIELD_FLAG_NONE, "Indicate whether, by default, how we should lightmap this type of scenery"),
		{ _field_enum, "lightmapping policy", &lightmapping_policy_enum },
		FIELD_PAD("WGW", nullptr, FIELD_FLAG_NONE, 2),

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_tag_reference, "Structure Lighting Tag", &Tag::Reference<struct s_structure_lighting_info>::s_defaultDefinition },
		{ _field_useless_pad, "" },

		{ _field_terminator }
	};

	STRINGS(pathfinding_policy_enum$2)
	{
		"Pathfinding CUT-OUT",
		"Pathfinding STATIC",
		"Pathfinding DYNAMIC",
		"Pathfinding NONE"
	};
	STRING_LIST(pathfinding_policy_enum$2, pathfinding_policy_enum$2_strings, _countof(pathfinding_policy_enum$2_strings));

	STRINGS(lightmapping_policy_enum)
	{
		"Per-Vertex",
		"Per-Pixel (not implemented)",
		"Dynamic"
	};
	STRING_LIST(lightmapping_policy_enum, lightmapping_policy_enum_strings, _countof(lightmapping_policy_enum_strings));

	STRINGS(scenery_flags)
	{
		"not physical#has no havok representation; will not build physics from collision",
		"use complex activation#tests all clusters for activation instead of just the origin"
	};
	STRING_LIST(scenery_flags, scenery_flags_strings, _countof(scenery_flags_strings));

} // namespace macaque

} // namespace blofeld

