#include "tagcodegen-private-pch.h"

using namespace blofeld;

c_virtual_tag_source_generator::c_virtual_tag_source_generator(e_engine_type engine_type, e_build build) :
	engine_type(engine_type),
	build(build)
{

}

void c_virtual_tag_source_generator::generate_header()
{
	std::stringstream hs;

	const char* namespace_name = engine_type_to_folder_name<const char*>(engine_type);

	hs << std::endl;
	hs << std::endl;

	hs << "namespace blofeld" << std::endl;
	hs << "{" << std::endl;
	hs << "\tnamespace " << namespace_name << std::endl;
	hs << "\t{" << std::endl << std::endl;



	//hs << "\t\t" << "class c_cache_file;" << std::endl << std::endl;
	//hs << "\t\t" << "class c_tag_interface { public: c_tag_interface(c_cache_file&, uint16_t tag_index); template<typename T> T* get_data(); };" << std::endl << std::endl;
	//hs << "\t\t" << "template<typename t_value> class c_virtual_tag_block { public: c_virtual_tag_block(c_cache_file& cache_file, c_tag_interface& tag_interface, c_typed_tag_block<t_value>& tag_block); };" << std::endl << std::endl;
	//hs << "\t\t" << "class c_virtual_tag { public: c_virtual_tag(c_cache_file& cache_file, c_tag_interface& tag_interface, s_tag_reference& tag_reference); };" << std::endl << std::endl;


	//hs << "\t\t" << "template<typename T>" << std::endl;
	//hs << "\t\t" << "class v_tag_interface :" << std::endl;
	//hs << "\t\t" << "\tpublic c_tag_interface" << std::endl;
	//hs << "\t\t" << "{" << std::endl;
	//hs << "\t\t" << "};" << std::endl << std::endl;

	hs << "\t\tc_virtual_tag_interface* create_virtual_tag_interface(c_tag_interface& tag_interface, unsigned long group_tag);" << std::endl << std::endl;

	std::map<std::string, int> field_name_unique_counter;
	for (const s_tag_struct_definition* tag_struct_definition : c_structure_relationship_node::sorted_tag_struct_definitions)
	{
		hs << "\t\t" << "template<>" << std::endl;
		hs << "\t\t" << "class v_tag_interface<s_" << tag_struct_definition->name << "> : " << std::endl;
		hs << "\t\t\t" << "public c_virtual_tag_interface" << std::endl;
		hs << "\t\t" << "{" << std::endl;
		hs << "\t\t\t" << "public:" << std::endl;
		hs << "\t\t\t" << "v_tag_interface(c_tag_interface& tag_interface) : " << std::endl;
		hs << "\t\t\t\t" << "c_virtual_tag_interface(tag_interface)";

		for (const s_tag_field* current_field = tag_struct_definition->fields; current_field->field_type != _field_terminator; current_field++)
		{
			uint32_t field_skip_count;
			if (skip_tag_field_version(*current_field, engine_type, build, field_skip_count))
			{
				current_field += field_skip_count;
				continue;
			}

			c_field_formatter field_formatter = c_field_formatter(current_field, current_field->name, &field_name_unique_counter);

			switch (current_field->field_type)
			{
			case _field_pad:
			case _field_skip:
			case _field_useless_pad:
			case _field_custom:
			case _field_terminator:
			case _field_explanation:
				continue;
			default:
				hs << "," << std::endl;
				break;
			}

			switch (current_field->field_type)
			{
			case _field_block:
			case _field_tag_reference:
				hs << "\t\t\t\t" << field_formatter.code_name.c_str() << "(tag_interface, tag_interface.get_data<s_" << tag_struct_definition->name << ">()->" << field_formatter.code_name.c_str() << ")";
				break;
			default:
				hs << "\t\t\t\t" << field_formatter.code_name.c_str() << "(tag_interface.get_data<s_" << tag_struct_definition->name << ">()->" << field_formatter.code_name.c_str() << ")";
				break;
			}
		}
		field_name_unique_counter.clear();
		hs << std::endl;
		hs << "\t\t\t\t" << "{ }";
		hs << std::endl;
		hs << std::endl;

		for (const s_tag_field* current_field = tag_struct_definition->fields; current_field->field_type != _field_terminator; current_field++)
		{
			uint32_t field_skip_count;
			if (skip_tag_field_version(*current_field, engine_type, build, field_skip_count))
			{
				current_field += field_skip_count;
				continue;
			}

			c_field_formatter field_formatter = c_field_formatter(current_field, current_field->name, &field_name_unique_counter);

			if (current_field->field_type > _field_type_non_standard)
			{
				continue;
			}

			switch (current_field->field_type)
			{
			case _field_pad:
			case _field_skip:
			case _field_useless_pad:
			case _field_custom:
			case _field_terminator:
			case _field_explanation:
				continue;
			}

			switch (current_field->field_type)
			{
			case _field_array:
			{
				const char* field_source_type = current_field->array_definition->struct_definition.name;
				hs << "\t\t\t\t" << "s_" << field_source_type << " (&" << field_formatter.code_name.c_str() << ")[" << current_field->array_definition->count << "];";
				break;
			}
			case _field_struct:
			{
				const char* field_source_type = current_field->struct_definition->name;
				hs << "\t\t\t\t" << "s_" << field_source_type << "& " << field_formatter.code_name.c_str() << ";";
				break;
			}
			case _field_block:
			{
				const char* field_source_type = current_field->block_definition->struct_definition.name;
				hs << "\t\t\t\t" << "c_virtual_tag_block<s_" << field_source_type << "> " << field_formatter.code_name.c_str() << ";";
				break;
			}
			case _field_tag_reference:
			{
				hs << "\t\t\t\t" << "c_virtual_tag " << field_formatter.code_name.c_str() << ";";
				break;
			}
			default:
			{
				const char* field_source_type = c_tag_source_generator::field_type_to_source_type(current_field->field_type);
				ASSERT(field_source_type != nullptr);
				hs << "\t\t\t\t" << field_source_type << "& " << field_formatter.code_name.c_str() << ";";
			}
			}
			hs << std::endl;

		}
		field_name_unique_counter.clear();

		hs << "\t\t" << "};" << std::endl;

		hs << std::endl;

		debug_point;

	}

	hs << std::endl << "\t} // end namespace " << namespace_name << std::endl;
	hs << std::endl << "} // end namespace blofeld" << std::endl;


	std::string source_code = hs.str();
	std::string output_filepath = c_command_line::get_command_line_arg("-output") + namespace_name + "/" + namespace_name + "_virtual.h";
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

void c_virtual_tag_source_generator::generate_source()
{
	std::stringstream ss;

	const char* namespace_name = engine_type_to_folder_name<const char*>(engine_type);

	ss << "#include <tagreflection-private-pch.h>" << std::endl << std::endl;

	ss << "namespace blofeld" << std::endl;
	ss << "{" << std::endl;
	ss << "\tnamespace " << namespace_name << std::endl;
	ss << "\t{" << std::endl << std::endl;


	ss << "\t\tc_virtual_tag_interface* create_virtual_tag_interface(c_tag_interface& tag_interface, unsigned long group_tag)" << std::endl;
	ss << "\t\t{" << std::endl;

	ss << "\t\t\t" << "switch (group_tag)" << std::endl;
	ss << "\t\t\t" << "{" << std::endl;

	std::map<std::string, int> field_name_unique_counter;
	for (const s_tag_group** tag_group = tag_groups; *tag_group; tag_group++)
	{
		c_fixed_string_128 tag_group_name = (*tag_group)->name;
		tag_group_name += "_TAG";
		tag_group_name.uppercase();

		const s_tag_struct_definition& tag_struct_definition = (*tag_group)->block_definition.struct_definition;

		ss << "\t\t\t" << "case " << tag_group_name.data << ": return new v_tag_interface<s_" << tag_struct_definition.name << ">(tag_interface);" << std::endl;

		debug_point;

	}

	ss << "\t\t\t" << "}" << std::endl << std::endl;

	ss << "\t\t\treturn nullptr;" << std::endl << std::endl;
	ss << "\t\t}" << std::endl;

	ss << std::endl << "\t} // end namespace " << namespace_name << std::endl;
	ss << std::endl << "} // end namespace blofeld" << std::endl;

	std::string source_code = ss.str();
	std::string output_filepath = c_command_line::get_command_line_arg("-output") + namespace_name + "/" + namespace_name + "_virtual.cpp";
	bool write_output = true;
	size_t existing_file_size;
	const char* existing_file_data;
	if(filesystem_read_file_to_memory(output_filepath.c_str(), &existing_file_data, &existing_file_size))
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
