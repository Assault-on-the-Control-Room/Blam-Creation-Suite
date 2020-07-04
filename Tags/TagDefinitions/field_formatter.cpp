#include "tagdefinitions-private-pch.h"

std::pair<const char*, const char*> c_field_formatter::bespoke_fixups[] =
{
	{ "class crates + vehicles", "class crates and vehicles" },
	{ "boundary -height", "boundary negative height" },
	{ "boundary +height", "boundary positive height" },
	{ "@weapon list (update _weapon_list enum in game_globals.h)", "weapon list"},
	{ "scale_x(scale}*", "scale_x{scale}*" } // what a bag of dicks
};

c_field_formatter::c_field_formatter(const blofeld::s_tag_field* field, std::map<std::string, int>* field_name_unique_counter) :
	display_name(),
	alt_name(),
	units(),
	description(),
	minimum("0"),
	maximum(),
	code_name(),
	read_only(false),
	is_index(false),
	is_pointer(false)
{
	const char* name = field->name;

	//name = "air reverb gain*!^{reverb gain}*!^:dB*!^[   -100  ]#how much reverb applies to this sound class";
	static int y = 0;
	//c_console::write_line_verbose("%i %s", y, name);
	if (name != nullptr)
	{
		// bespoke fixups
		for (std::pair<const char*, const char*>& fixup : bespoke_fixups)
		{
			if (strcmp(name, fixup.first) == 0)
			{
				name = fixup.second;
			}
		}

		c_fixed_string_16 flags0;
		c_fixed_string_16 flags1;
		c_fixed_string_16 flags2;

		size_t remainder_buffer_size = strlen(name) + 1;
		c_stack_string remainder_buffer_a = c_stack_string(remainder_buffer_size);
		c_stack_string remainder_buffer_b = c_stack_string(remainder_buffer_size);

		int description_scan = sscanf(name, "%[^#]#%2047[^\1]", remainder_buffer_a.data, description.data);
		int min_max_scan = sscanf(remainder_buffer_a.data, "%[^[][%*[\x20]%127[^\x20,]%*[\x20],%*[\x20]%127[^\x20]]]", remainder_buffer_b.data, minimum.data, maximum.data);
		int units_scan = sscanf(remainder_buffer_b.data, "%[^:]:%255[^*^!~?\1]%15[^\xFF]", remainder_buffer_a.data, units.data, flags0.data);
		int alt_name_scan = sscanf(remainder_buffer_a.data, "%[^{]{%[^}]}%15[^\xFF]", remainder_buffer_b.data, alt_name.data, flags1.data);
		int display_name_scan = sscanf(remainder_buffer_b.data, "%511[^*^!~?\1]%15[^\xFF]", display_name.data, flags2.data);

		c_fixed_string_64 flags;
		flags.format("%s%s%s", flags0.data, flags1.data, flags2.data);

		read_only = flags.contains('*');
		is_index = flags.contains('^');
		is_pointer = flags.contains('\1');

		code_name = display_name;

		// bespoke fixups
		for (std::pair<const char*, const char*>& fixup : bespoke_fixups)
		{
			if (code_name == fixup.first)
			{
				code_name = fixup.second;
			}
		}

		cleanup_code_name();

		if (field->field_type == blofeld::_field_block && !code_name.ends_with("_block"))
		{
			code_name += "_block";
			debug_point;
		}
		else if (!units.is_empty() && units.size() < 6)
		{
			code_name += "_";
			code_name += units;
			cleanup_code_name();
		}

		if (code_name.starts_with('%'))
		{
			c_fixed_string_512 temp = code_name;
			code_name.format("percent%s", temp.data + 1);
		}
		if (code_name.ends_with('%'))
		{
			code_name.shrink(code_name.size() - 1);
			code_name += "percent";
			debug_point;
		}
		if (code_name.starts_with_numeric())
		{
			c_fixed_string_512 temp = code_name;
			code_name.format("_%s", temp.data);
		}

		if (code_name == "char") code_name = "_char";
		if (code_name == "short") code_name = "_short";
		if (code_name == "class") code_name = "_class";
		if (code_name == "default") code_name = "_default";
		if (code_name == "operator") code_name = "_operator";
		if (code_name == "protected") code_name = "_protected";
		if (code_name == "static") code_name = "_static";
		if (code_name == "template") code_name = "_template";
		if (code_name == "and") code_name = "_and";
		if (code_name == "final") code_name = "_final";
		if (code_name == "real") code_name = "_real";

		if (field_name_unique_counter)
		{
			int unique_field_count = ++(*field_name_unique_counter)[code_name.data];

			if (unique_field_count > 1)
			{
				c_fixed_string_512 temp = code_name;
				code_name.format("%s$%i", temp.data, unique_field_count);
			}
		}

		debug_point;
		y++;
	}
}

void c_field_formatter::cleanup_code_name()
{
	code_name.lowercase();
	code_name.replace(' ', '_');
	code_name.replace('/', '_');
	code_name.replace('\\', '_');
	code_name.replace('-', '_');
	code_name.replace('+', '_');
	code_name.replace('&', '_');
	code_name.replace('|', '_');
	code_name.replace('>', '_');
	code_name.replace('<', '_');
	code_name.replace('=', '_');
	code_name.remove('{');
	code_name.remove('}');
	code_name.remove('@');
	code_name.remove('(');
	code_name.remove(')');
	code_name.remove('.');
	code_name.remove(',');
	code_name.remove('\'');
	code_name.remove(';');
}
