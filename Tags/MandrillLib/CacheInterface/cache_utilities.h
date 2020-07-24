#pragma once

template<typename T>
class v_tag_legacy;

class c_virtual_tag_legacy;
class c_tag_interface;

#ifdef __INTELLISENSE__

template<typename T>
const v_tag_legacy<T>* tag_cast(const s_tag_reference* tag_interface);

template<typename T>
v_tag_legacy<T>* tag_cast(s_tag_reference* tag_interface);

#endif

template<typename T>
v_tag_legacy<T>* tag_cast(c_virtual_tag_legacy* virtual_tag_interface)
{
	ASSERT(virtual_tag_interface != nullptr);
	c_tag_interface* tag_interface = *virtual_tag_interface;
	if (tag_interface != nullptr)
	{
		v_tag_legacy<T>* virtual_tag_interface = dynamic_cast<decltype(virtual_tag_interface)>(tag_interface);
		return virtual_tag_interface;
	}
	return nullptr;
}

template<typename T>
const v_tag_legacy<T>* tag_cast(const c_virtual_tag_legacy* virtual_tag_interface)
{
	ASSERT(virtual_tag_interface != nullptr);
	const c_tag_interface* tag_interface = *virtual_tag_interface;
	if (tag_interface != nullptr)
	{
		const v_tag_legacy<T>* virtual_tag_interface = dynamic_cast<decltype(virtual_tag_interface)>(tag_interface);
		return virtual_tag_interface;
	}
	return nullptr;
}

template<typename T>
const v_tag_legacy<T>* tag_cast(const c_tag_interface* tag_interface)
{
	const v_tag_legacy<T>* virtual_tag_interface = dynamic_cast<decltype(virtual_tag_interface)>(tag_interface);
	return virtual_tag_interface;
}

template<typename T>
v_tag_legacy<T>* tag_cast(c_tag_interface* tag_interface)
{
	v_tag_legacy<T>* virtual_tag_interface = dynamic_cast<decltype(virtual_tag_interface)>(tag_interface);
	return virtual_tag_interface;
}
