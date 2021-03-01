#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		decal_system_group,
		DECAL_SYSTEM_TAG,
		nullptr,
		INVALID_TAG,
		decal_system_block );

	TAG_BLOCK_FROM_STRUCT(
		decal_system_block,
		"decal_system_block",
		1,
		decal_system_struct_definition);

	#define DECAL_DEFINITION_BLOCK_ID { 0x05E5AE1B, 0x33A44FBF, 0x83F60D66, 0xAC15FDB8 }
	TAG_BLOCK(
		decal_definition_block,
		"decal_definition_block",
		c_decal_system_definition::k_max_decal,
		"c_decal_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		DECAL_DEFINITION_BLOCK_ID)
	{
		{ _field_string_id, "decal name", FIELD_FLAG_INDEX },
		{ _field_long_flags, "flags", &decal_flags },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 2 },
		{ _field_legacy, _field_explanation, "Render Method" },
		{ _field_legacy, _field_struct, "render method", &render_method_struct_definition },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 4 },
		FIELD_CUSTOM("material", nullptr, FIELD_FLAG_NONE, _field_id_shader_template),
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_hidd_begin),
		{ _field_struct, "actual material?", &material_struct },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_hidd_end),

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_long_integer, "unknown" }, 

		{ _field_real_bounds, "radius", nullptr, "world units" },
		{ _field_real_bounds, "decay time", nullptr, "seconds", FIELD_FLAG_UNKNOWN0 },
		{ _field_real_bounds, "lifespan", nullptr, "seconds", FIELD_FLAG_UNKNOWN0 },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_real, "clamp angle", "Projections at greater than this angle will be clamped to this angle", "degrees" },
		{ _field_real, "cull angle", "Projections at greater than this angle will not be drawn", "degrees" },

		{ _field_real, "depth bias" },
		FIELD_CUSTOM("Decal Strip", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_real, "strip U-coordinate tile length" },
		{ _field_real, "strip max profile distance" },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		{ _field_real, "runtime bitmap aspect", FIELD_FLAG_UNKNOWN0 },
		{ _field_terminator }
	};

	#define DECAL_SYSTEM_STRUCT_DEFINITION_ID { 0x570BB931, 0x8CB3411C, 0xB0466FBE, 0x7FE4EEE5 }
	TAG_STRUCT(
		decal_system_struct_definition,
		"decal_system_struct_definition",
		"c_decal_system_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		DECAL_SYSTEM_STRUCT_DEFINITION_ID)
	{
		{ _field_long_flags, "flags", &decal_system_flags },
		{ _field_long_integer, "ring buffer size (in triangles)", "bigger sizes keep more decals around but use much more memory" },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_real, "unknown@" },

		{ _field_long_integer, "ring buffer size single player (in triangles)", "above entry is for MP -- SP can be different" },
		{ _field_real, "material shader fade time", "material shader lifetime is modulated from 1 to 0 over this time" },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_tag_reference, "successor", &decal_system_reference },

		{ _field_real_point_2d, "decal scale override", "NOTE - If set to non-zero, this will override manual scaling in Sapien and smash it with these values" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		FIELD_EXPLANATION("Decal bucket sharing", nullptr, FIELD_FLAG_NONE, "For the index bounds below, if non-zero, sprites will be chosen between low and high bounds, inclusive.\nUse this to keep multiple different decals in the same bucket.\nIf multiple decal systems use the same bitmap set and the same material definition, they will be combined at runtime and share their vertex bucket.\nThis is more efficient in memory and more performant to render."),
		{ _field_short_bounds, "random sprite index bounds", "if zero, will use random sprite" },

		{ _field_block, "decals", &decal_definition_block },
		{ _field_real, "runtime max radius", FIELD_FLAG_UNKNOWN0 },
		{ _field_terminator }
	};

	STRINGS(decal_flags)
	{
		"render in transparents pass"
	};
	STRING_LIST(decal_flags, decal_flags_strings, _countof(decal_flags_strings));

	STRINGS(decal_system_flags)
	{
		"random rotation",
		"force planar",
		"is strip"
	};
	STRING_LIST(decal_system_flags, decal_system_flags_strings, _countof(decal_system_flags_strings));

} // namespace macaque

} // namespace blofeld

