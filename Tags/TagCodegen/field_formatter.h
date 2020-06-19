#pragma once

class c_field_formatter
{
public:
	c_field_formatter(const blofeld::s_tag_field* field, const char* name, std::map<std::string, int>* field_name_unique_counter);
	void cleanup_code_name();

	c_fixed_string_512 display_name;
	c_fixed_string_512 alt_name;
	c_fixed_string_128 units;
	c_fixed_string_2048 description;
	c_fixed_string_128 minimum;
	c_fixed_string_128 maximum;
	bool read_only;
	bool is_index;

	c_fixed_string_512 code_name;

	static std::pair<const char*, const char*> bespoke_fixups[];
};

