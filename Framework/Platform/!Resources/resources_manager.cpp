#include "platform-private-pch.h"
#include "resource.h"

LPCWSTR c_resources_manager::get_resource_type(e_bcs_resource_type type)
{
	switch (type)
	{
	case _bcs_resource_type_icon_application:
	case _bcs_resource_type_icon_blam_creation_suite:
	case _bcs_resource_type_icon_mandrill:
		return RT_ICON;
	default:
		return RT_RCDATA;
	}
}

LPCWSTR c_resources_manager::get_resource_int_resource(e_bcs_resource_type type)
{
	switch (type)
	{
	case _bcs_resource_type_icon_application:			return MAKEINTRESOURCEW(IDI_ICON_APPLICATION);
	case _bcs_resource_type_icon_blam_creation_suite:	return MAKEINTRESOURCEW(IDI_ICON_BLAM_CREATION_SUITE);
	case _bcs_resource_type_icon_mandrill:				return MAKEINTRESOURCEW(IDI_ICON_MANDRILL);
	case _bcs_resource_type_font_cousine_regular:		return MAKEINTRESOURCEW(IDR_FONT_COUSING_REGULAR);
	case _bcs_resource_type_font_font_awesome:			return MAKEINTRESOURCEW(IDR_FONT_FONT_AWESOME);
	case _bcs_resource_type_symbols_blob:				return MAKEINTRESOURCEW(IDR_MAPDATABASE);
	case _bcs_resource_type_box_pixel_shader:			return MAKEINTRESOURCEW(IDR_BOXSHADERPS);
	case _bcs_resource_type_box_vertex_shader:			return MAKEINTRESOURCEW(IDR_BOXSHADERVS);
	}
	return NULL;
}

HRSRC c_resources_manager::get_resource_handle(e_bcs_resource_type type)
{
	static HMODULE instance_handle = c_runtime_util::get_current_module();

	LPCWSTR int_resource = get_resource_int_resource(type);
	if (int_resource == nullptr) return NULL;

	return FindResourceW(instance_handle, int_resource, get_resource_type(type));
}

bool c_resources_manager::get_resource(e_bcs_resource_type type, char** out_data, size_t* out_data_size, bool null_terminate)
{
	*out_data = nullptr;
	*out_data_size = 0;

	static HMODULE instance_handle = c_runtime_util::get_current_module();

	HRSRC resource_handle = get_resource_handle(type);
	if (resource_handle == NULL) return false;
	HGLOBAL resource_memory_handle = LoadResource(instance_handle, resource_handle);
	if (resource_memory_handle == NULL) return false;
	DWORD resource_size = SizeofResource(instance_handle, resource_handle);
	if (resource_size == 0) return false;
	LPVOID resource_pointer = LockResource(resource_memory_handle);
	if (resource_pointer == nullptr) return false;

	char* bytes = new char[resource_size + (null_terminate ? 1 : 0)] {};
	ASSERT(bytes != nullptr);
	for (DWORD i = 0; i < resource_size; i++)
	{
		bytes[i] = reinterpret_cast<char*>(resource_pointer)[i];
	}
	memcpy(bytes, resource_pointer, resource_size);
	if (null_terminate)
	{
		bytes[resource_size] = 0;
	}

	UnlockResource(resource_pointer);
	BOOL free_resource_result = FreeResource(resource_memory_handle);
	ASSERT(free_resource_result == 0);

	*out_data = bytes;
	*out_data_size = resource_size + (null_terminate ? 1 : 0);

	return true;
}
