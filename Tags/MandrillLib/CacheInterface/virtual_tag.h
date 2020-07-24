#pragma once

template<typename T>
class v_parent_tag_interface;

class c_virtual_tag
{
public:
	c_virtual_tag(c_tag_interface& parent_tag_interface, s_tag_reference& tag_reference) :
		parent_tag_interface(parent_tag_interface),
		tag_reference(tag_reference)
	{

	}

	operator c_tag_interface* () const
	{
		return parent_tag_interface.get_cache_file().get_tag_interface(tag_reference.index);
	}

	operator const c_tag_interface* () const
	{
		return parent_tag_interface.get_cache_file().get_tag_interface(tag_reference.index);
	}

	template<typename T>
	operator v_parent_tag_interface<T>* () const
	{
		c_tag_interface* target_tag_interface = *this;
		return tag_cast<T>(target_tag_interface);
	}

	template<typename T>
	operator const v_parent_tag_interface<T>* () const
	{
		c_tag_interface* target_tag_interface = *this;
		return tag_cast<T>(target_tag_interface);
	}

private:
	c_tag_interface& parent_tag_interface;
	s_tag_reference& tag_reference;
};
