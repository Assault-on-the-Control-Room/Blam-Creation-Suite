#pragma once

template<typename T>
class v_tag_interface;

#pragma once

template<typename T>
class v_tag_interface_legacy;

class c_virtual_tag_legacy;
class c_tag_interface;

#ifdef __INTELLISENSE__

template<typename T>
const v_tag_interface_legacy<T>* tag_cast(const s_tag_reference* tag_interface);

template<typename T>
v_tag_interface_legacy<T>* tag_cast(s_tag_reference* tag_interface);

#endif

template<typename T>
v_tag_interface_legacy<T>* tag_cast(c_virtual_tag_legacy* virtual_tag_interface)
{
	ASSERT(virtual_tag_interface != nullptr);
	c_tag_interface* tag_interface = *virtual_tag_interface;
	if (tag_interface != nullptr)
	{
		v_tag_interface_legacy<T>* virtual_tag_interface = dynamic_cast<decltype(virtual_tag_interface)>(tag_interface);
		return virtual_tag_interface;
	}
	return nullptr;
}

template<typename T>
const v_tag_interface_legacy<T>* tag_cast(const c_virtual_tag_legacy* virtual_tag_interface)
{
	ASSERT(virtual_tag_interface != nullptr);
	const c_tag_interface* tag_interface = *virtual_tag_interface;
	if (tag_interface != nullptr)
	{
		const v_tag_interface_legacy<T>* virtual_tag_interface = dynamic_cast<decltype(virtual_tag_interface)>(tag_interface);
		return virtual_tag_interface;
	}
	return nullptr;
}

template<typename T>
const v_tag_interface_legacy<T>* tag_cast(const c_tag_interface* tag_interface)
{
	const v_tag_interface_legacy<T>* virtual_tag_interface = dynamic_cast<decltype(virtual_tag_interface)>(tag_interface);
	return virtual_tag_interface;
}

template<typename T>
v_tag_interface_legacy<T>* tag_cast(c_tag_interface* tag_interface)
{
	v_tag_interface_legacy<T>* virtual_tag_interface = dynamic_cast<decltype(virtual_tag_interface)>(tag_interface);
	return virtual_tag_interface;
}

class c_virtual_tag
{
public:
	c_virtual_tag(c_tag_interface& tag_interface, s_tag_reference& tag_reference) :
		tag_interface(tag_interface),
		tag_reference(tag_reference)
	{

	}

	operator c_tag_interface* () const
	{
		// #TODO: cache refactor
		//return tag_interface.get_cache_file().get_tag_interface(tag_reference.index);
		throw;
	}

	operator const c_tag_interface* () const
	{
		// #TODO: cache refactor
		//return tag_interface.get_cache_file().get_tag_interface(tag_reference.index);
		throw;
	}

	template<typename T>
	operator v_tag_interface<T>* () const
	{
		c_tag_interface* target_tag_interface = *this;
		return tag_cast<T>(target_tag_interface);
	}

	template<typename T>
	operator const v_tag_interface<T>* () const
	{
		c_tag_interface* target_tag_interface = *this;
		return tag_cast<T>(target_tag_interface);
	}

private:
	c_tag_interface& tag_interface;
	s_tag_reference& tag_reference;
};
