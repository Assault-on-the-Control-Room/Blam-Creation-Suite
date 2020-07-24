#pragma once

template<typename t_value>
class c_virtual_tag_block
{
public:
	c_virtual_tag_block(c_tag_interface& tag_interface, c_typed_tag_block<t_value>& tag_block) :
		address(tag_block.address),
		count(tag_block.count),
		definition_address(tag_block.definition_address),
		begin_raw(nullptr),
		end_raw(nullptr),
		tag_interface(tag_interface),
		tag_block(tag_block)
	{
		if (tag_interface.get_data() != nullptr)
		{
			begin_raw = tag_interface.get_cache_file().get_tag_block_data(tag_block);
			end_raw = begin_raw + tag_block.count;
		}

		struct_interfaces = new v_struct<t_value>*[count] {};
		for (uint32_t index = 0; index < count; index++)
		{
			struct_interfaces[index] = nullptr;
		}
	}

	~c_virtual_tag_block()
	{
		for (uint32_t index = 0; index < count; index++)
		{
			v_struct<t_value>* struct_interface = struct_interfaces[index];
			if (struct_interface)
			{
				delete struct_interface;
			}
		}
		delete[] struct_interfaces;
	}

	v_struct<t_value>** begin()
	{ 
		// #TODO: create custom iterator to initialize structs on the fly

		for (uint32_t index = 0; index < count; index++)
		{
			if (struct_interfaces[index])
			{
				continue;
			}
			struct_interfaces[index] = new v_struct<t_value>(tag_interface, begin_raw[index]);
		}

		return struct_interfaces; 
	}
	v_struct<t_value>** end() { return struct_interfaces + count; }

	//t_value* begin() { return begin_pointer; }
	//t_value* end() { return end_pointer; }

	decltype(s_tag_block::address)& address;
	decltype(s_tag_block::count)& count;
	decltype(s_tag_block::definition_address)& definition_address;


	//t_value& operator[](size_t index) const { return begin_pointer[index]; }

	// #TODO: Can the tag block own this and return a reference?
	v_struct<t_value>& operator[](size_t index) const
	{
		if (struct_interfaces[index] == nullptr)
		{
			struct_interfaces[index] = new v_struct<t_value>(tag_interface, begin_raw[index]);
		}
		return *struct_interfaces[index];
	}


private:

	v_struct<t_value>** struct_interfaces;
	t_value* begin_raw;
	t_value* end_raw;

	c_tag_interface& tag_interface;
	c_typed_tag_block<t_value>& tag_block;
};

