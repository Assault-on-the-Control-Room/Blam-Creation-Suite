#pragma once

enum e_bcs_resource_type
{
	_bcs_resource_type_icon_application,
	_bcs_resource_type_icon_blam_creation_suite,
	_bcs_resource_type_icon_mandrill,
	_bcs_resource_type_font_cousine_regular,
	_bcs_resource_type_font_font_awesome,
	_bcs_resource_type_box_pixel_shader,
	_bcs_resource_type_box_vertex_shader,
	_bcs_resource_type_symbols_blob,
};

class c_resources_manager
{
public:
	static LPCWSTR get_resource_type(e_bcs_resource_type type);
	static LPCWSTR get_resource_int_resource(e_bcs_resource_type type);
	static bool get_resource(e_bcs_resource_type type, char** out_data, size_t* out_data_size, bool null_terminate = false);
private:
	static HRSRC get_resource_handle(e_bcs_resource_type type);
};


