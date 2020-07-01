#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{
	STRINGS(beam_system_output_kind)
	{
		"none",
		"additive",
		"multiply"
	};
	STRING_LIST(beam_system_output_kind, beam_system_output_kind_strings, _countof(beam_system_output_kind_strings));

	TAG_STRUCT(beam_system_unknown_struct)
	{
		{ _field_char_integer, "input" },
		{ _field_char_integer, "input range" },
		{ _field_char_enum, "output kind", &beam_system_output_kind },
		{ _field_char_integer, "output" },
		{ _field_data, "unknown" },
		{ _field_real, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_terminator }
	};

	TAG_REFERENCE(beam_render_method_definition_reference, blofeld::RENDER_METHOD_DEFINITION_TAG);
	TAG_REFERENCE(beam_render_method_reference);

	TAG_BLOCK(beam_system_entry, 65536)
	{
		{ _field_string_id, "name" },

		{ _field_custom, "Tracer Appearance" },
		//{ _field_word_flags, "appearance flags", &tracerAppearanceFlags },
		//{ _field_short_integer, "sort bias#use values between -10 and 10 to move closer and farther from camera (positive is closer)" },
		{ _field_custom, "material" },
		{ _field_custom },
		{ _field_struct, "actual material\?", &render_method_struct_definition_struct_definition },

		{ _field_long_integer, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },

		{ _field_struct, "unknown", &beam_system_unknown_struct_struct_definition },
		{ _field_struct, "unknown", &beam_system_unknown_struct_struct_definition },
		{ _field_struct, "unknown", &beam_system_unknown_struct_struct_definition },
		{ _field_struct, "unknown", &beam_system_unknown_struct_struct_definition },

		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },

		{ _field_struct, "unknown", &beam_system_unknown_struct_struct_definition },
		{ _field_struct, "unknown", &beam_system_unknown_struct_struct_definition },
		{ _field_struct, "unknown", &beam_system_unknown_struct_struct_definition },
		{ _field_struct, "unknown", &beam_system_unknown_struct_struct_definition },
		{ _field_struct, "unknown", &beam_system_unknown_struct_struct_definition },
		{ _field_struct, "unknown", &beam_system_unknown_struct_struct_definition },
		{ _field_struct, "unknown", &beam_system_unknown_struct_struct_definition },

		{ _field_long_integer, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_long_integer, "structured scenario interop index" }, // see "runtime m_gpu_data!" gpu_property_function_color_struct_struct_definition
		{ _field_long_integer, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_long_integer, "unknown" },

		{ _field_terminator }
	};

	TAG_GROUP(beam_system, BEAM_SYSTEM_TAG)
	{
		{ _field_block, "beam system", &beam_system_entry_block },
		{ _field_terminator }
	};

}