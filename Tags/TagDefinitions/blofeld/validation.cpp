#include "tagdefinitions-private-pch.h"

namespace blofeld
{
	uint32_t calculate_struct_size(e_engine_type engine_type, e_build build, const s_tag_struct_definition& struct_definition, bool* block_failed_validation)
	{
		uint32_t computed_size = 0;


		for(const s_tag_field* current_field = struct_definition.fields; current_field->field_type != _field_terminator; current_field++)
		{
			const char* field_string = field_to_string(current_field->field_type);
			const char* nice_field_string = field_string + 1;

			uint32_t field_skip_count;
			if (skip_tag_field_version(*current_field, engine_type, build, field_skip_count))
			{
				current_field += field_skip_count;
				continue;
			}

			if (block_failed_validation)
			{

				// data validation
				switch (current_field->field_type)
				{
				case _field_char_enum:
				case _field_enum:
				case _field_long_enum:
				case _field_long_flags:
				case _field_word_flags:
				case _field_byte_flags:
					if (current_field->string_list_definition == nullptr)
					{
						c_console::write_line_verbose("%s(%i): warning V1000: '%s' '%s':'%s' failed validation. no string list specified.", current_field->filename, current_field->line, nice_field_string, struct_definition.name, current_field->name);
						*block_failed_validation = true;
					}
					break;
				case _field_struct:
					if (current_field->struct_definition == nullptr)
					{
						c_console::write_line_verbose("%s(%i): warning V2000: '%s' '%s':'%s' failed validation. no struct specified.", current_field->filename, current_field->line, nice_field_string, struct_definition.name, current_field->name);
						*block_failed_validation = true;
						continue;
					}
					break;
				case _field_array:
					if (current_field->array_definition == nullptr)
					{
						c_console::write_line_verbose("%s(%i): warning V3000: '%s' '%s':'%s' failed validation. no array specified.", current_field->filename, current_field->line, nice_field_string, struct_definition.name, current_field->name);
						*block_failed_validation = true;
						continue;
					}
					break;
				case _field_block:
					if (current_field->block_definition == nullptr)
					{
						c_console::write_line_verbose("%s(%i): warning V2000: '%s' '%s':'%s' failed validation. no block specified.", current_field->filename, current_field->line, nice_field_string, struct_definition.name, current_field->name);
						*block_failed_validation = true;
						continue;
					}
					break;
				case _field_tag_reference:
					if (current_field->tag_reference_definition == nullptr)
					{
						c_console::write_line_verbose("%s(%i): warning V4000: '%s' '%s':'%s' failed validation. no tag reference specified.", current_field->filename, current_field->line, nice_field_string, struct_definition.name, current_field->name);
						*block_failed_validation = true;
						continue;
					}
					break;
				}
			}

			switch (current_field->field_type)
			{
			case _field_pad:
			case _field_useless_pad:
				computed_size += current_field->padding;
				break;
			case _field_skip:
				computed_size += current_field->length;
				break;
			case _field_struct:
				computed_size += calculate_struct_size(engine_type, build, *current_field->struct_definition, block_failed_validation);
				break;
			case _field_array:
			{
				const s_tag_array_definition& array_definition = *current_field->array_definition;
				REFERENCE_ASSERT(array_definition);
				const s_tag_struct_definition& struct_definition = array_definition.struct_definition;
				REFERENCE_ASSERT(struct_definition);
				uint32_t struct_size = calculate_struct_size(engine_type, build, struct_definition, block_failed_validation);
				uint32_t array_data_size = struct_size * array_definition.count;
				computed_size += array_data_size;
				break;
			}
			default:
				computed_size += get_blofeld_field_size(current_field->field_type);
				break;
			}
		}

		return computed_size;
	}

	bool validate_gen3_definitions()
	{
		bool any_block_failed_validation = false;
		uint32_t successful_validation_attempts = 0;
		for (s_tag_struct_validation_data& struct_validation_data : gen3_xbox360_tag_struct_validation_data)
		{
			bool block_failed_validation = false;
			const s_tag_struct_definition& struct_definition = struct_validation_data.struct_definition;
			const char* const block_name = struct_definition.name;
			uint32_t const expected_size = struct_validation_data.size;

			uint32_t computed_size = calculate_struct_size(_engine_type_gen3_xbox360, _build_not_set, struct_definition, &block_failed_validation);

			block_failed_validation |= computed_size != expected_size;
			if (block_failed_validation)
			{
				c_console::write_line_verbose("%s(%i): warning V0002: s_tag_struct '%s' failed validation. computed size 0x%x expected 0x%x", struct_definition.filename, struct_definition.line, block_name, computed_size, expected_size);
			}
			else
			{
				successful_validation_attempts++;
			}
			any_block_failed_validation |= block_failed_validation;
		}
		float percentage = 100.0f * float(successful_validation_attempts) / float(_countof(gen3_xbox360_tag_struct_validation_data));
		if (percentage != 100.0f)
		{
			c_console::write_line_verbose("warning V0001: failed to validate all tags. success rate %.1f.", percentage);
		}
		return any_block_failed_validation;
	}

}
