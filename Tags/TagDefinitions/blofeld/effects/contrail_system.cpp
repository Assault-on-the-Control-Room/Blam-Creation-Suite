#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{
	STRINGS(contrail_flags)
	{
		"first point unfaded"
		"last point unfaded"
		"points start pinned to media"
		"points start pinned to ground"
		"points always pinned to media"
		"points always pinned to ground"
		"edge effect fades slowly"
		"dont't inherit object change color"
	};
	STRING_LIST(contrail_flags, contrail_flags_strings, _countof(contrail_flags_strings));

	STRINGS(contrail_scale_flags)
	{
		"point generation rate"
		"point velocity"
		"point velocity delta"
		"point velocity cone angle"
		"inherited velocity fraction"
		"sequence animation rate"
		"texture scale u"
		"texture scale v"
		"texture animation u"
		"texture animation v"
	};
	STRING_LIST(contrail_scale_flags, contrail_scale_flags_strings, _countof(contrail_scale_flags_strings));

	STRINGS(contrail_system_output_kind)
	{
		"none",
		"additive",
		"multiply"
	};
	STRING_LIST(contrail_system_output_kind, contrail_system_output_kind_strings, _countof(contrail_system_output_kind_strings));

	TAG_STRUCT(contrail_system_unknown_struct)
	{
		{ _field_char_integer, "input" },
		{ _field_char_integer, "input range" },
		{ _field_char_enum, "output kind", &contrail_system_output_kind },
		{ _field_char_integer, "output" },
		{ _field_data, "unknown" },
		{ _field_real, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_terminator }
	};

	TAG_REFERENCE(contrail_render_method_definition_reference, blofeld::RENDER_METHOD_DEFINITION_TAG);
	TAG_REFERENCE(contrail_render_method_reference);

	TAG_BLOCK(contrail_system_entry, 65536)
	{
		{ _field_string_id, "name" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_struct, "unknown", &contrail_system_unknown_struct_struct_definition },
		{ _field_struct, "unknown", &contrail_system_unknown_struct_struct_definition },
		{ _field_struct, "unknown", &contrail_system_unknown_struct_struct_definition },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_struct, "unknown", &contrail_system_unknown_struct_struct_definition },
		{ _field_struct, "unknown", &contrail_system_unknown_struct_struct_definition },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_struct, "unknown", &contrail_system_unknown_struct_struct_definition },
		{ _field_struct, "unknown", &contrail_system_unknown_struct_struct_definition },
		{ _field_long_integer, "unknown" },

		{ _field_explanation, "Render Method" },
		{ _field_struct, "render method", &render_method_struct_definition_struct_definition },

		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_struct, "profile color", &tracerProperty_real_rgb_color_Struct_struct_definition },
		{ _field_struct, "profile alpha", &tracerProperty_real_Struct_struct_definition },
		{ _field_struct, "profile alpha2", &tracerProperty_real_Struct_struct_definition },
		{ _field_struct, "profile black point", &tracerProperty_real_Struct_struct_definition },
		{ _field_struct, "profile palette", &tracerProperty_real_Struct_struct_definition },
		{ _field_struct, "profile intensity", &tracerProperty_real_Struct_struct_definition },

		{ _field_long_integer, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_long_integer, "structured scenario interop index" }, // see "runtime m_gpu_data!" gpu_property_function_color_struct_struct_definition
		{ _field_long_integer, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_long_integer, "unknown" },

		{ _field_terminator }
	};

	TAG_GROUP(contrail_system, CONTRAIL_SYSTEM_TAG)
	{
		{ _field_block, "contrail system", &contrail_system_entry_block },
		{ _field_terminator }
	};

}