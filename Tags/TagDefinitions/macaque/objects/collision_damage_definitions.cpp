#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		collision_damage_group,
		COLLISION_DAMAGE_TAG,
		nullptr,
		INVALID_TAG,
		collision_damage_block );

	TAG_BLOCK_FROM_STRUCT(
		collision_damage_block,
		"collision_damage_block",
		1,
		collision_damage_struct_definition);

	#define COLLISION_DAMAGE_STRUCT_DEFINITION_ID { 0x50FEF768, 0x5E0F4D35, 0x8B165F16, 0xBEAAF2E6 }
	TAG_STRUCT(
		collision_damage_struct_definition,
		"collision_damage_struct_definition",
		"s_collision_damage_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		COLLISION_DAMAGE_STRUCT_DEFINITION_ID)
	{
		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_long_flags, "Flags", &collisionDamageFlags },

		FIELD_EXPLANATION("Applying collision damage", nullptr, FIELD_FLAG_NONE, "for things that want to cause more or less collision damage"),
		{ _field_real, "Apply collision damage scale", "0 means 1.  1 is standard scale.  Some things may want to apply more damage" },
		{ _field_real, "Friendly apply collision damage scale", "0 means 1.  1 is standard scale.  Some things may want to apply more damage, yet go soft on their friends" },
		FIELD_EXPLANATION("Game collision damage parameters", nullptr, FIELD_FLAG_NONE, "0 - means take default value from globals.globals"),
		{ _field_real, "minimum velocity for game damage", "if you are going below this velocity we stop all game damage" },
		{ _field_struct, "game collision damage", &collision_damage_function },
		{ _field_real_bounds, "game acceleration", "0-Infinity" },
		FIELD_EXPLANATION("Applying absolute collision damage", nullptr, FIELD_FLAG_NONE, "for things that want to cause more or less collision damage"),
		{ _field_real, "Apply absolute collision damage scale", "0 means 1.  1 is standard scale.  Some things may want to apply more damage" },
		{ _field_real, "Friendly apply absolute collision damage scale", "0 means 1.  1 is standard scale.  Some things may want to apply more damage, yet go soft on their friends" },
		FIELD_EXPLANATION("Absolute collision damage parameters", nullptr, FIELD_FLAG_NONE, "0 - means take default value from globals.globals"),
		{ _field_real, "minimum velocity for absolute damage", "if you are going below this velocity we stop all absolute damage" },
		{ _field_struct, "absolute collision damage", &collision_damage_function },
		{ _field_real_bounds, "absolute acceleration", "0-Infinity" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		FIELD_EXPLANATION("Alternative damage effect", nullptr, FIELD_FLAG_NONE, "Overrides the damage effect from globals.globals"),
		{ _field_tag_reference, "alternative damage effect", &Tag::Reference<struct s_damage_effect_definition>::s_defaultDefinition },

		{ _field_terminator }
	};

	#define COLLISION_DAMAGE_FUNCTION_ID { 0x1DE4BAA4, 0xFBC74C13, 0x9576F17A, 0x8F464147 }
	TAG_STRUCT(
		collision_damage_function,
		"collision_damage_function",
		"c_function_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		COLLISION_DAMAGE_FUNCTION_ID)
	{
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_default),
		{ _field_struct, "mapping", &mapping_function },
		{ _field_terminator }
	};

	STRINGS(collisionDamageFlags)
	{
		"Don\'t scale damage#typically, we scale the damage to make only \"lethal\" collision damage kill people; this flag overrides that behavior",
		"Object may choose not to deal damage#in some cases (notably, the thruster pack) we should ask an object if it wants to opt out of dealing damage for one reason or another"
	};
	STRING_LIST(collisionDamageFlags, collisionDamageFlags_strings, _countof(collisionDamageFlags_strings));

} // namespace macaque

} // namespace blofeld

