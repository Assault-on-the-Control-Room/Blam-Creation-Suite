#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{
	V5_TAG_ARRAY_FROM_STRUCT(render_interleaved_texture_array_definition, k_interleaved_texture_count, render_texture_format_definition_struct_definition);

	V5_TAG_STRUCT(render_texture_interop_definition_struct)
	{
		{ _field_legacy, _field_data, "pixel data*" },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_halo4 },
		{ _field_legacy, _field_data, "medium res data*" },

		{ _field_legacy, _field_data, "high res data*" },
		{ _field_legacy, _field_short_integer, "width*" },
		{ _field_legacy, _field_short_integer, "height*" },
		{ _field_legacy, _field_char_integer, "depth*" },
		{ _field_legacy, _field_char_integer, "total mipmap count*" },
		{ _field_legacy, _field_char_enum, "type*", &bitmap_types },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_halo4, 1 },
		{ _field_legacy, _field_char_integer, "pad1_1" },

		{ _field_legacy, _field_char_enum, "is high res bitmap", &boolean_enum_definition },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_halo4, 3 },
		{ _field_legacy, _field_char_enum, "is medium res bitmap", &boolean_enum_definition },
		{ _field_legacy, _field_char_enum, "pad2_1", &boolean_enum_definition },
		{ _field_legacy, _field_char_enum, "pad2_2", &boolean_enum_definition },

		{ _field_legacy, _field_long_integer, "exponent bias" },
		{ _field_legacy, _field_long_integer, "xenon d3d format*" },

		{ _field_legacy, _field_version_less, _engine_type_halo4, 2 },
		{ _field_legacy, _field_long_integer, "unknown" },
		{ _field_legacy, _field_api_interop, "d3d data" },

		{ _field_legacy, _field_terminator }
	};

	V5_TAG_STRUCT(render_texture_interleaved_interop_definition_struct)
	{
		{ _field_legacy, _field_data, "pixel data*" },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_halo4 },
		{ _field_legacy, _field_data, "medium res data*" },

		{ _field_legacy, _field_array, "interleaved textures", &render_interleaved_texture_array_definition_array },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_STRUCT(render_texture_format_definition)
	{
		{ _field_legacy, _field_short_integer, "width*" },
		{ _field_legacy, _field_short_integer, "height*" },
		{ _field_legacy, _field_char_integer, "depth*" },
		{ _field_legacy, _field_char_integer, "total mipmap count*" },
		{ _field_legacy, _field_char_enum, "type*", &bitmap_types },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_halo4, 1 },
		{ _field_legacy, _field_char_integer, "pad1_1" },

		{ _field_legacy, _field_char_enum, "is high res bitmap", &boolean_enum_definition },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_halo4, 3 },
		{ _field_legacy, _field_char_enum, "is medium res bitmap", &boolean_enum_definition },
		{ _field_legacy, _field_char_enum, "pad2_1", &boolean_enum_definition },
		{ _field_legacy, _field_char_enum, "pad2_2", &boolean_enum_definition },

		{ _field_legacy, _field_long_integer, "exponent bias" },
		{ _field_legacy, _field_long_integer, "xenon d3d format*" },
		{ _field_legacy, _field_terminator }
	};

	STRINGS(boolean_enum_definition)
	{
		"false",
		"true"
	};
	STRING_LIST(boolean_enum_definition, boolean_enum_definition_strings, _countof(boolean_enum_definition_strings));

} // namespace blofeld

