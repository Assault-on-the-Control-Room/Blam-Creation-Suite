#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_GROUP_FROM_BLOCK(decal_system, DECAL_SYSTEM_TAG, decal_system_block_block );

	V5_TAG_BLOCK(decal_definition_block, c_decal_system_definition::k_max_decal)
	{
		{ _field_legacy, _field_string_id, "decal name^" },
		{ _field_legacy, _field_long_flags, "flags", &decal_flags },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 2 },
		{ _field_legacy, _field_explanation, "Render Method" },
		{ _field_legacy, _field_struct, "render method", &render_method_struct_definition_struct_definition },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 4 },
		{ _field_legacy, _field_custom, "material" },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_struct, "actual material\?", &material_block_struct },
		{ _field_legacy, _field_custom },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_long_integer, "unknown" }, // likely flags?

		{ _field_legacy, _field_real_bounds, "radius:world units" },
		{ _field_legacy, _field_real_bounds, "decay time:seconds!" },
		{ _field_legacy, _field_real_bounds, "lifespan:seconds!" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_legacy, _field_real, "clamp angle:degrees#Projections at greater than this angle will be clamped to this angle" },
		{ _field_legacy, _field_real, "cull angle:degrees#Projections at greater than this angle will not be drawn" },

		{ _field_legacy, _field_real, "depth bias" },
		{ _field_legacy, _field_custom, "Decal Strip" },
		{ _field_legacy, _field_real, "strip U-coordinate tile length" },
		{ _field_legacy, _field_real, "strip max profile distance" },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_real, "runtime bitmap aspect!" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK_FROM_STRUCT(decal_system_block, 1, decal_system_struct_definition_struct_definition );

	V5_TAG_STRUCT(decal_system_struct_definition)
	{
		{ _field_legacy, _field_long_flags, "flags", &decal_system_flags },
		{ _field_legacy, _field_long_integer, "ring buffer size (in triangles)#bigger sizes keep more decals around but use much more memory" },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_real, "unknown@"},

		{ _field_legacy, _field_long_integer, "ring buffer size single player (in triangles)#above entry is for MP -- SP can be different" },
		{ _field_legacy, _field_real, "material shader fade time#material shader lifetime is modulated from 1 to 0 over this time" },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_tag_reference, "successor", &decal_system_reference },

		{ _field_legacy, _field_real_point_2d, "decal scale override#NOTE - If set to non-zero, this will override manual scaling in Sapien and smash it with these values" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_legacy, _field_explanation, "Decal bucket sharing", "For the index bounds below, if non-zero, sprites will be chosen between low and high bounds, inclusive.\nUse this to keep multiple different decals in the same bucket.\nIf multiple decal systems use the same bitmap set and the same material definition, they will be combined at runtime and share their vertex bucket.\nThis is more efficient in memory and more performant to render." },
		{ _field_legacy, _field_short_bounds, "random sprite index bounds#if zero, will use random sprite" },
		
		{ _field_legacy, _field_block, "decals", &decal_definition_block_block },
		{ _field_legacy, _field_real, "runtime max radius!" },
		{ _field_legacy, _field_terminator }
	};

	STRINGS(decal_flags)
	{
		{
			_engine_type_not_set,
			_versioned_string_list_mode_new,
			{
				"render in transparents pass",
			}
		},
		{
			_engine_type_haloreach,
			_versioned_string_list_mode_append,
			{
				"render in transparents pass",
				"use team color#you need to select a team based decal shader with this option" // unconfirmed, taken from halo 5
			}
		},
		{
			_engine_type_halo5,
			_versioned_string_list_mode_new,
			{
				"render in transparents pass",
				"use team color#you need to select a team based decal shader with this option"
			}
		},
	};
	STRING_LIST(decal_flags, decal_flags_strings, _countof(decal_flags_strings));

	STRINGS(decal_system_flags)
	{
		{
			_engine_type_not_set,
			_versioned_string_list_mode_new,
			{
				"random rotation",
				"force planar",
				"is strip",
			}
		},
		{
			_engine_type_haloreach,
			_versioned_string_list_mode_append,
			{
				"bit 4",
				"bit 5",
				"bit 6",
				"bit 7",
				"bit 8",
				"bit 9",
				"bit 10",
			}
		},
		{
			_engine_type_gen3_xbox360,
			_versioned_string_list_mode_new,
			{
				"random rotation",
				"force planar",
				"is strip",
			}
		},
		{
			_engine_type_halo5,
			_versioned_string_list_mode_new,
			{
				"random rotation",
				"force planar",
			}
		},
	};
	STRING_LIST(decal_system_flags, decal_system_flags_strings, _countof(decal_system_flags_strings));

} // namespace blofeld

