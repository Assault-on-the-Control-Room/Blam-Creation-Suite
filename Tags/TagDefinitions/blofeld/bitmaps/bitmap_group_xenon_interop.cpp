#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{
	TAG_ARRAY_FROM_STRUCT(render_interleaved_texture_array_definition, k_interleaved_texture_count, render_texture_format_definition_struct_definition);

	TAG_STRUCT(render_texture_interop_definition_struct)
	{
		{ _field_version_greater, _engine_type_haloreach, 1 },
		{ _field_data, "pixel data*" },

		{ _field_data, "medium res data*" },
		{ _field_data, "high res data*" },
		{ _field_short_integer, "width*" },
		{ _field_short_integer, "height*" },
		{ _field_char_integer, "depth*" },
		{ _field_char_integer, "total mipmap count*" },
		{ _field_char_enum, "type*", &bitmap_types },

		{ _field_version_greater, _engine_type_haloreach, 1 },
		{ _field_char_integer, "pad1_1" },

		{ _field_char_enum, "is high res bitmap", &boolean_enum_definition },

		{ _field_version_greater, _engine_type_haloreach, 4 },
		{ _field_char_enum, "is medium res bitmap", &boolean_enum_definition },
		{ _field_char_enum, "pad2_1", &boolean_enum_definition },
		{ _field_char_enum, "pad2_2", &boolean_enum_definition },
		{ _field_long_integer, "exponent bias" },

		{ _field_long_integer, "xenon d3d format*" },

		{ _field_terminator }
	};

	TAG_STRUCT(render_texture_interleaved_interop_definition_struct)
	{
		{ _field_data, "pixel data*" },
		{ _field_data, "medium res data*" },
		{ _field_array, "interleaved textures", &render_interleaved_texture_array_definition_array },
		{ _field_terminator }
	};

	TAG_STRUCT(render_texture_format_definition)
	{
		{ _field_short_integer, "width*" },
		{ _field_short_integer, "height*" },
		{ _field_char_integer, "depth*" },
		{ _field_char_integer, "total mipmap count*" },
		{ _field_char_enum, "type*", &bitmap_types },
		{ _field_char_integer, "pad1_1" },
		{ _field_char_enum, "is high res bitmap", &boolean_enum_definition },
		{ _field_char_enum, "is medium res bitmap", &boolean_enum_definition },
		{ _field_char_enum, "pad2_1", &boolean_enum_definition },
		{ _field_char_enum, "pad2_2", &boolean_enum_definition },
		{ _field_long_integer, "exponent bias" },
		{ _field_long_integer, "xenon d3d format*" },
		{ _field_terminator }
	};

	STRINGS(boolean_enum_definition)
	{
		"false",
		"true"
	};
	STRING_LIST(boolean_enum_definition, boolean_enum_definition_strings, _countof(boolean_enum_definition_strings));

} // namespace blofeld

