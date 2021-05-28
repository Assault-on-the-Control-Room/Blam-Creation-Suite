#pragma once

class c_h4_blamboozle;
class c_h4_generator_preprocessor;
class c_h4_tag_group_container;
class c_h4_tag_block_container;
class c_h4_tag_struct_container;
class c_h4_tag_enum_container;
class c_h4_tag_reference_container;

class c_h4_source_file
{
public:
	c_h4_source_file(const char* filepath, c_h4_generator_preprocessor& preprocessor);

	c_h4_generator_preprocessor& preprocessor;
	bool is_header;
	bool is_inline;
	std::string source_output_filepath;
	std::string header_output_filepath;
	std::string full_source_output_filepath;
	std::string full_header_output_filepath;
	std::vector<c_h4_tag_group_container*> tag_groups;
	std::vector<c_h4_tag_block_container*> tag_blocks;
	std::vector<c_h4_tag_block_container*> tag_arrays;
	std::vector<c_h4_tag_struct_container*> tag_structs;
	std::vector<c_h4_tag_enum_container*> tag_enums;
	std::vector<c_h4_tag_reference_container*> tag_references;
	std::stringstream source_stream;
	std::stringstream header_stream;
};

class c_h4_tag_group_container
{
public:
	c_h4_tag_group_container(c_h4_tag_group& tag_group, c_h4_generator_preprocessor& preprocessor, c_h4_source_file& source_file);
	bool operator ==(const c_h4_tag_group_container& container) const;

	c_h4_tag_group& tag_group;
	c_h4_source_file& source_file;
	c_h4_tag_block_container* tag_block_container;
	c_h4_tag_struct_container* tag_struct_container;
	std::string name;
	std::string symbol_name;
	std::string name_uppercase;
	bool define_tag_group_block_and_fields;
};

class c_h4_tag_block_container
{
public:
	c_h4_tag_block_container(c_h4_tag_block& tag_block, c_h4_generator_preprocessor& preprocessor, c_h4_tag_group_container* tag_group_container, bool defined_by_tag_group);
	bool operator ==(const c_h4_tag_block_container& container) const;

	c_h4_tag_block& tag_block;
	c_h4_tag_struct_container* tag_struct_container;
	c_h4_tag_group_container* const tag_group_container;
	std::string name;
	std::string symbol_name;
	std::string name_uppercase;
	bool use_tag_block_definition;
	bool defined_by_tag_group;
	bool has_traversed;
};

class c_h4_tag_struct_container
{
public:
	c_h4_tag_struct_container(
		c_h4_tag_struct& tag_struct, 
		c_h4_generator_preprocessor& preprocessor,
		c_h4_tag_block_container* block_container, 
		bool is_tag_group, 
		bool is_block, 
		bool is_array, 
		bool is_interop, 
		bool is_resource);
	bool operator ==(const c_h4_tag_struct_container& container) const;

	c_h4_tag_block_container* const tag_block_container;
	c_h4_tag_struct& tag_struct;
	std::string name;
	std::string symbol_name;
	std::string name_uppercase;
	std::string struct_name;
	bool const is_block;
	bool const is_array;
	bool const is_interop;
	bool const is_resource;
	bool const is_tag_group;
	bool has_traversed;
};

class c_h4_tag_enum_container
{
public:
	c_h4_tag_enum_container(c_h4_tag_enum& tag_enum, c_h4_generator_preprocessor& preprocessor);
	bool operator ==(const c_h4_tag_enum_container& container) const;

	c_h4_tag_enum& tag_enum;
	std::string name;
	std::string symbol_name;
	std::string name_uppercase;
};

class c_h4_tag_reference_container
{
public:
	c_h4_tag_reference_container(c_h4_tag_reference& tag_reference, c_h4_generator_preprocessor& preprocessor);
	bool operator ==(const c_h4_tag_reference_container& container) const;

	c_h4_tag_reference& tag_reference;
	std::string name;
	std::string symbol_name;
	std::string name_uppercase;
	bool is_tag_group_reference;
	bool is_empty_and_unknown_reference;
	bool is_template;
};

class c_h4_generator_preprocessor
{
public:
	c_h4_generator_preprocessor(c_h4_blamboozle& blamboozle);
	~c_h4_generator_preprocessor();
	c_h4_tag_block_container* find_existing_tag_block_container(c_h4_tag_block& tag_block);
	c_h4_tag_struct_container* find_existing_tag_struct_container(c_h4_tag_struct& tag_struct);
	c_h4_tag_enum_container* find_existing_tag_enum_container(c_h4_tag_enum& tag_enum);
	c_h4_tag_reference_container* find_existing_tag_reference_container(c_h4_tag_reference& tag_reference);
	c_h4_source_file& get_source_file(const char* filepath, c_h4_generator_preprocessor& preprocessor);

	c_h4_tag_block_container& traverse_tag_blocks(c_h4_tag_block& tag_block, c_h4_tag_group_container* group_container, bool is_tag, bool defined_by_tag_group, bool traverse);
	c_h4_tag_struct_container& traverse_tag_structs(c_h4_tag_struct& tag_struct, c_h4_tag_block_container* block_container, bool is_tag, bool is_block, bool is_array, bool is_interop, bool is_resource, bool traverse);

	void process_tag_block_field(c_h4_tag_field* tag_field, c_h4_tag_struct& tag_struct);
	void process_tag_struct_field(c_h4_tag_field* tag_field, c_h4_tag_struct& tag_struct);
	void process_tag_reference_field(c_h4_tag_field* tag_field, c_h4_tag_struct& tag_struct);

	void cleanup_tag_blocks();
	void cleanup_tag_structs();

	c_h4_tag_group_container* get_container_by_group_tag(unsigned long group_tag);
	void create_tag_block_source_count_constants(c_h4_tag_block& tag_block);

	c_h4_blamboozle& blamboozle;
	std::vector<c_h4_source_file*> source_files;
	std::vector<c_h4_tag_group_container*> group_containers;
	std::vector<c_h4_tag_block_container*> tag_block_containers;
	std::vector<c_h4_tag_struct_container*> tag_struct_containers;
	std::vector<c_h4_tag_enum_container*> tag_enum_containers;
	std::vector<c_h4_tag_reference_container*> tag_reference_containers;
	std::vector<std::string> maximum_count_constants_source_lines_define;
	std::vector<std::string> maximum_count_constants_source_lines_constant;
	std::vector<std::string> maximum_count_constants_source_lines_struct;
	std::map<std::string, unsigned long> tag_type_name_unique_counter;
};

