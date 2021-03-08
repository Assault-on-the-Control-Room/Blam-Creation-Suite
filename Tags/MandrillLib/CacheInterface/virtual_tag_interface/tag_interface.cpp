#include "mandrilllib-private-pch.h"

c_tag_interface::c_tag_interface(c_cache_file& cache_file, uint32_t tag_index) :
	tag_index(tag_index),
	is_tag_null(false),
	blofeld_reflection_type(nullptr),
	cache_file(cache_file),
	reflection_initialised(false),
	virtual_tag_interface(nullptr),
	virtual_resource_user_data(nullptr)
{
	
}

c_tag_interface::~c_tag_interface()
{
	if (virtual_tag_interface != nullptr)
	{
		delete virtual_tag_interface;
	}
}

void c_tag_interface::associate_virtual_tag_interface(c_virtual_tag_interface& virtual_tag_interface)
{
	this->virtual_tag_interface = &virtual_tag_interface;
}

void c_tag_interface::init_virtual_tag_interface()
{
	if (is_null())
	{
		return;
	}

	if (get_group_tag() == blofeld::INVALID_TAG)
	{
		return;
	}

	blofeld_reflection_type = blofeld::get_group_tag_by_group_tag(get_group_tag());



	for (c_mandrill_extension& extension : c_reference_loop(c_mandrill_extension::get_extensions(), c_mandrill_extension::get_extension_count()))
	{
		if (virtual_tag_interface = extension.create_virtual_tag_interface(*this, get_group_tag()))
		{
			break;
		}
	}
	// #TODO: cache refactor
	/*
	if (virtual_tag_interface == nullptr)
	{
		virtual_tag_interface = create_virtual_tag_interface(*this, cache_file.engine_type, cache_file.platform_type, _build_not_set, get_group_tag());
	}
	*/

	if (virtual_tag_interface == nullptr)
	{
		if (c_tag_group_interface* tag_group_interface = get_tag_group_interface())
		{
			const char* tag_group_short_name = tag_group_interface->get_short_name();
			const char* tag_group_full_name = tag_group_interface->get_full_name();
			c_console::write_line_verbose(__FUNCTION__": warning unknown tag group '%s' '%s'", tag_group_short_name, tag_group_full_name);
		}
		else
		{
			c_console::write_line_verbose(__FUNCTION__": warning unknown tag group");
		}
	}
}

void c_tag_interface::register_with_tag_group()
{
	if (c_tag_group_interface* tag_group_interface = get_tag_group_interface())
	{
		tag_group_interface->add_tag_interface(*this);
	}
}

unsigned long c_tag_interface::get_group_tag() const
{
	return blofeld::INVALID_TAG;
}

c_tag_group_interface* c_tag_interface::get_tag_group_interface() const
{
	return nullptr;
}

c_virtual_tag_interface* c_tag_interface::get_virtual_tag_interface()
{
	if (!reflection_initialised)
	{
		init_virtual_tag_interface();
		reflection_initialised = true;
	}

	return virtual_tag_interface;
}

const blofeld::s_tag_group* c_tag_interface::get_blofeld_reflection_data()
{
	if (!reflection_initialised)
	{
		init_virtual_tag_interface();
		reflection_initialised = true;
	}

	return blofeld_reflection_type;
}
