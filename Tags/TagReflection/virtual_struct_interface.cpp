#include "tagreflection-private-pch.h"

c_virtual_struct_interface::c_virtual_struct_interface(c_tag_interface& tag_interface, void* data) :
	tag_interface(tag_interface),
	data(data)
{
	
}

c_virtual_struct_interface::~c_virtual_struct_interface()
{

}
