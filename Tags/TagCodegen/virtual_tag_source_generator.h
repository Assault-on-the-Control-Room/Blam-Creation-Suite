#pragma once

class c_virtual_tag_source_generator
{
public:

	e_engine_type engine_type;
	e_platform_type platform_type;
	e_build build;

	c_virtual_tag_source_generator(e_engine_type engine_type, e_platform_type platform_type, e_build build);
	bool is_tag_group(const blofeld::s_tag_struct_definition& tag_struct_definition);
	void generate_header();
	void generate_source();
	void generate_header_impl(std::stringstream& hs, bool tag_groups);
};

