#pragma once

class c_struct_interface;

class c_virtual_struct_interface
{
public:
	c_virtual_struct_interface(c_tag_interface& tag_interface, void* data);
	virtual ~c_virtual_struct_interface();

	inline c_tag_interface& get_tag_interface() const { return tag_interface; }
	inline void* get_data() const { return data; }

private:
	c_tag_interface& tag_interface;
	void* data;
};

template<typename T>
class v_struct :
	public c_virtual_struct_interface
{
	v_struct(c_tag_interface&, T&);
};