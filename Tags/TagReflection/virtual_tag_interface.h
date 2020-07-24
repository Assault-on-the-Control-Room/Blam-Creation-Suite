#pragma once

class c_tag_interface;

class c_virtual_tag_interface
{
public:
	c_virtual_tag_interface(c_tag_interface& tag_interface);
	virtual ~c_virtual_tag_interface();

	c_tag_interface& tag_interface;
};

template<typename T>
class v_tag :
	public c_virtual_tag_interface
{
};