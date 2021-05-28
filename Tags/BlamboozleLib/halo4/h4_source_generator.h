#pragma once

class c_h4_blamboozle;
class c_h4_generator_preprocessor;

class c_h4_source_generator
{
public:
	c_h4_source_generator(c_h4_blamboozle& blamboozle, c_h4_generator_preprocessor& preprocessor);
	~c_h4_source_generator();
	void create_tag_groups_header(std::stringstream& hs);
	void create_tag_groups_source(std::stringstream& s);
	void create_tag_structs_header(std::stringstream& hs);
	void create_tag_structs_source(std::stringstream& s);
	void create_validation_header(std::stringstream& hs);
	void create_validation_source(std::stringstream& s);
	void create_tag_group_header(std::stringstream& hs, c_h4_tag_group_container& group_container);
	void create_tag_block_header(std::stringstream& hs, c_h4_tag_block_container& tag_block_container);
	void create_tag_block_source(std::stringstream& s, c_h4_tag_block_container& tag_block_container);
	void create_tag_array_header(std::stringstream& hs, c_h4_tag_block_container& tag_block_container);
	void create_tag_array_source(std::stringstream& s, c_h4_tag_block_container& tag_block_container);
	void create_tag_struct_header(std::stringstream& hs, c_h4_tag_struct_container& tag_struct_container);
	void create_tag_struct_source(std::stringstream& s, c_h4_tag_struct_container& tag_struct_container);
	void create_tag_reference_header(std::stringstream& hs, c_h4_tag_reference_container& tag_reference_container);
	void create_tag_reference_source(std::stringstream& s, c_h4_tag_reference_container& tag_reference_container);
	void generate_tag_field_flags(std::stringstream& s, c_blamlib_string_parser_v2& string_parser);
	void create_tag_group_source(std::stringstream& s, c_h4_tag_group_container& group_container);
	void create_tag_enum_header(std::stringstream& hs, c_h4_tag_enum_container& tag_enum_container);
	void create_tag_enum_source(std::stringstream& s, c_h4_tag_enum_container& tag_enum_container, bool is_header);
	void generate_tag_fields_source(std::stringstream& s, std::vector<c_h4_tag_field*>& tag_fields);

	std::string create_struct_definition_runtime_flags(unsigned long flags, const char* new_line_format);
	std::string create_struct_definition_memory_attributes(unsigned long memory_type, unsigned long usage_flags, const char* new_line_format);
	
	c_h4_blamboozle& blamboozle;
	c_h4_generator_preprocessor& preprocessor;
};