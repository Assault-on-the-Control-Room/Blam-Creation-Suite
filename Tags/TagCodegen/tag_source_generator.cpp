#include "tagcodegen-private-pch.h"

using namespace blofeld;

c_tag_source_generator::c_tag_source_generator(e_engine_type engine_type, e_build build) :
	engine_type(engine_type),
	build(build),
	has_error(false)
{

}

const char* c_tag_source_generator::field_type_to_source_type(e_field field_type)
{
	switch (field_type)
	{
	case _field_string:							return "c_static_string<32>";
	case _field_long_string:						return "c_static_string<256>";
	case _field_string_id:							return "string_id";
	case _field_old_string_id:						return "c_old_string_id";
	case _field_char_integer:						return "char";
	case _field_short_integer:						return "short";
	case _field_long_integer:						return "long";
	case _field_int64_integer:						return "long long";
	case _field_angle:								return "angle";
	case _field_tag:								return "tag";
	case _field_char_enum:							return "char";
	case _field_enum:								return "short";
	case _field_long_enum:							return "long";
	case _field_long_flags:						return "long";
	case _field_word_flags:						return "word";
	case _field_byte_flags:						return "byte";
	case _field_point_2d:							return "s_point2d";
	case _field_rectangle_2d:						return "s_rectangle2d";
	case _field_rgb_color:							return "pixel32";
	case _field_argb_color:						return "pixel32";
	case _field_real:								return "real";
	case _field_real_fraction:						return "real_fraction";
	case _field_real_point_2d:						return "real_point2d";
	case _field_real_point_3d:						return "real_point3d";
	case _field_real_vector_2d:					return "real_vector2d";
	case _field_real_vector_3d:					return "real_vector3d";
	case _field_real_quaternion:					return "real_quaternion";
	case _field_real_euler_angles_2d:				return "real_euler_angles2d";
	case _field_real_euler_angles_3d:				return "real_euler_angles3d";
	case _field_real_plane_2d:						return "real_plane2d";
	case _field_real_plane_3d:						return "real_plane3d";
	case _field_real_rgb_color:					return "rgb_color";
	case _field_real_argb_color:					return "argb_color";
	case _field_real_hsv_color:					return "real_hsv_color";
	case _field_real_ahsv_color:					return "real_ahsv_color";
	case _field_short_bounds:						return "short_bounds";
	case _field_angle_bounds:						return "angle_bounds";
	case _field_real_bounds:						return "real_bounds";
	case _field_real_fraction_bounds:				return "real_bounds";
	case _field_tag_reference:						return "s_tag_reference";
	case _field_block:								return "s_tag_block";
	case _field_long_block_flags:					return "long";
	case _field_word_block_flags:					return "word";
	case _field_byte_block_flags:					return "byte";
	case _field_char_block_index:					return "char";
	case _field_custom_char_block_index:			return "char";
	case _field_short_block_index:					return "short";
	case _field_custom_short_block_index:			return "short";
	case _field_long_block_index:					return "long";
	case _field_custom_long_block_index:			return "long";
	case _field_data:								return "s_tag_data";
	case _field_vertex_buffer:						return "s_tag_d3d_vertex_buffer";
	case _field_pad:								return nullptr;	// dynamic
	case _field_useless_pad:						return nullptr;	// dynamic
	case _field_skip:								return nullptr;	// dynamic
	case _field_non_cache_runtime_value:			return "long";
	case _field_explanation:						return nullptr;	// empty
	case _field_custom:							return nullptr;	// empty
	case _field_struct:							return nullptr;	// dynamic
	case _field_array:								return nullptr;	// dynamic
	case _field_pageable:							return "s_tag_resource";
	case _field_api_interop:						return "s_tag_interop";
	case _field_terminator:						return nullptr;	// empty
	case _field_byte_integer:						return "byte";
	case _field_word_integer:						return "word";
	case _field_dword_integer:						return "dword";
	case _field_qword_integer:						return "qword";
	default: FATAL_ERROR(L"Unknown field type");
	}
}

void c_tag_source_generator::generate_source()
{
	std::stringstream ss;

	const char* namespace_name = engine_type_to_folder_name<const char*>(engine_type);

	ss << std::endl;
	ss << std::endl;

	ss << "namespace blofeld" << std::endl;
	ss << "{" << std::endl;
	ss << "\tnamespace " << namespace_name << std::endl;
	ss << "\t{" << std::endl;
	ss << "#pragma pack(push, 1)" << std::endl << std::endl;


	for (const s_tag_struct_definition* tag_struct_definition : c_structure_relationship_node::sorted_tag_struct_definitions)
	{
		ss << "\t\t" << "struct s_" << tag_struct_definition->name << std::endl;
		ss << "\t\t" << "{" << std::endl;

		std::map<std::string, int> field_name_unique_counter;



		for (const s_tag_field* current_field = tag_struct_definition->fields; current_field->field_type != _field_terminator; current_field++)
		{
			c_field_formatter field_formatter = c_field_formatter(current_field, current_field->name, &field_name_unique_counter);
			const char* field_type_string = field_to_string(current_field->field_type);

			uint32_t field_skip_count;
			if (skip_tag_field_version(*current_field, engine_type, build, field_skip_count))
			{
				current_field += field_skip_count;
				continue;
			}

			switch (current_field->field_type)
			{
			case _field_pad:
				ss << "\t\t\t" << "char " << field_formatter.code_name.c_str() << "[" << current_field->padding << "]; // padding" << std::endl;
				break;
			case _field_skip:
				ss << "\t\t\t" << "char " << field_formatter.code_name.c_str() << "[" << current_field->padding << "]; // skip" << std::endl;
				break;
			case _field_useless_pad:
				ss << "\t\t\t" << "// char " << field_formatter.code_name.c_str() << "[" << current_field->padding << "]; // useless padding" << std::endl;
				break;
			case _field_custom:
				ss << "\t\t\t" << "// " << field_type_string;
				if (!field_formatter.code_name.is_empty())
				{
					ss << " " << field_formatter.code_name.c_str();
				}
				ss << std::endl;
				break;
			case _field_terminator:
				ss << "\t\t\t" << "// " << field_type_string << std::endl;
				break;
			case _field_explanation:
			{
				if (current_field->name)
				{
					if (current_field->explanation && *current_field->explanation)
					{
						ss << std::endl << "\t\t\t" << "/* " << current_field->name << std::endl;
						ss << "\t\t\t ";
						const char* current_pos = current_field->explanation;
						while (*current_pos)
						{
							switch (*current_pos)
							{
							case '\n':
								ss << *current_pos;
								ss << "\t\t\t ";
								break;
							default:
								ss << *current_pos;
							}
							current_pos++;
						}
						ss << std::endl;
						ss << "\t\t\t" << "*/" << std::endl << std::endl;
					}
					else
					{
						ss << std::endl << "\t\t\t" << "/* " << current_field->name << " */" << std::endl << std::endl;
					}
				}
				break;
			}
			case _field_array:
			{
				const char* field_source_type = current_field->array_definition->struct_definition.name;
				ss << "\t\t\t" << "s_" << field_source_type << " " << field_formatter.code_name.c_str() << "[" << current_field->array_definition->count << "];";
				break;
			}
			case _field_struct:
			{
				const char* field_source_type = current_field->struct_definition->name;
				ss << "\t\t\t" << "s_" << field_source_type << " " << field_formatter.code_name.c_str() << ";";
				break;
			}
			case _field_block:
			{
				const char* field_source_type = current_field->block_definition->struct_definition.name;
				ss << "\t\t\t" << "c_typed_tag_block<s_" << field_source_type << "> " << field_formatter.code_name.c_str() << ";";
				break;
			}
			case _field_tag_reference:
			{
				if (current_field->tag_reference_definition == nullptr)
				{
					c_console::write_line("%s(%i): error TSG0001: _field_tag_reference is null", current_field->filename, current_field->line);
					has_error = true;
				}
				else
				{
					bool handled = false;

					long group_tag = current_field->tag_reference_definition->group_tag;
					uint32_t group_tag_count = current_field->tag_reference_definition->group_tag;



					std::vector<unsigned long> group_tags;

					if (current_field->tag_reference_definition->group_tag != INVALID_TAG)
					{
						group_tags.emplace_back(current_field->tag_reference_definition->group_tag);
					}
					else if (current_field->tag_reference_definition->group_tags)
					{
						for (const unsigned long* current_group_tag = current_field->tag_reference_definition->group_tags; *current_group_tag != INVALID_TAG; current_group_tag++)
						{
							group_tags.push_back(*current_group_tag);
						}
					}


					if (group_tags.empty())
					{
						ss << "\t\t\t" << "s_tag_reference " << field_formatter.code_name.c_str() << ";";
					}
					else
					{

						ss << "\t\t\t" << "c_typed_tag_reference<";

						for (size_t group_tag_index = 0; group_tag_index < group_tags.size(); group_tag_index++)
						{
							const s_tag_group* tag_group = get_group_tag_by_group_tag(group_tags[group_tag_index]);
							ASSERT(tag_group != nullptr);
							if (group_tag_index > 0)
							{
								ss << ", ";
							}

							c_fixed_string_128 tag_group_name = tag_group->name;
							tag_group_name += "_TAG";
							tag_group_name.uppercase();

							ss << tag_group_name.data;
						}
						ss << "> " << field_formatter.code_name.c_str() << ";";
					}
				}

				break;
			}
			default:
			{
				const char* field_source_type = field_type_to_source_type(current_field->field_type);
				ASSERT(!field_formatter.code_name.is_empty());
				ss << "\t\t\t" << field_source_type << " " << field_formatter.code_name.data << ";";
			}
			}

			constexpr bool k_write_field_types = false;
			switch (current_field->field_type)
			{
			case _field_pad:
			case _field_skip:
			case _field_useless_pad:
			case _field_custom:
			case _field_terminator:
			case _field_explanation:
				break;
			default:
				if (!field_formatter.description.is_empty() || k_write_field_types)
				{
					ss << " // ";
					if constexpr (k_write_field_types) ss << field_type_string << " ";
					const char* current_pos = field_formatter.description.data;
					while (*current_pos)
					{
						switch (*current_pos)
						{
						case '\n':
							ss << ' ';
							break;
						default:
							ss << *current_pos;
						}
						current_pos++;
					}
				}
				ss << std::endl;
			}
		}

		ss << "\t\t" << "};" << std::endl;

		uint32_t struct_size = calculate_struct_size(engine_type, build, *tag_struct_definition);

		ss << "\t\t" << "static constexpr size_t " << tag_struct_definition->name << "_size = sizeof(s_" << tag_struct_definition->name << ");" << std::endl;
		ss << "\t\t" << "static_assert(" << tag_struct_definition->name << "_size == " << std::uppercase << std::dec << __max(1u, struct_size) << ", \"struct s_" << tag_struct_definition->name << " is invalid size\");" << std::endl;

		ss << std::endl;

		debug_point;


	}

	ss << "#pragma pack(pop)" << std::endl;
	ss << std::endl << "\t} // end namespace " << namespace_name << std::endl;
	ss << std::endl << "} // end namespace blofeld" << std::endl;



	std::string source_code = ss.str();
	std::string output_filepath = c_command_line::get_command_line_arg("-output") + namespace_name + "/" + namespace_name + ".h";
	bool write_output = true;
	size_t existing_file_size;
	const char* existing_file_data;
	if (filesystem_read_file_to_memory(output_filepath.c_str(), &existing_file_data, &existing_file_size))
	{
		if (source_code.size() == existing_file_size && strncmp(existing_file_data, source_code.c_str(), existing_file_size) == 0)
		{
			write_output = false;
		}
		delete[] existing_file_data;
	}

	if (write_output)
	{
		bool filesystem_write_file_from_memory_result = filesystem_write_file_from_memory(output_filepath.c_str(), source_code.data(), source_code.size());
		ASSERT(filesystem_write_file_from_memory_result);
	}
}
