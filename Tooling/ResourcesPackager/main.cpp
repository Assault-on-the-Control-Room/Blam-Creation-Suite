#include <Platform\platform-public-pch.h>
#include <SymbolsLib\symbolslib-public-pch.h>

const char* c_console::g_console_executable_name = "Resource";

void update_resource_data(LPCWSTR szExecutablePath, e_bcs_resource_type type, const char* data, size_t data_length)
{
	HANDLE update_resource_handle = BeginUpdateResourceW(szExecutablePath, FALSE);
	ASSERT(update_resource_handle != NULL);

	LPCWSTR resource_type = c_resources_manager::get_resource_type(type);
	LPCWSTR resource_name = c_resources_manager::get_resource_int_resource(type);
	BOOL update_resource_result = UpdateResourceW(
		update_resource_handle, 
		resource_type,
		resource_name,
		MAKELANGID(LANG_NEUTRAL, 
		SUBLANG_NEUTRAL), 
		const_cast<char*>(data), 
		static_cast<DWORD>(data_length));
	ASSERT(update_resource_result == TRUE);

	BOOL end_update_resource_result = EndUpdateResource(update_resource_handle, FALSE);
	ASSERT(update_resource_result == TRUE);

}

void update_resource(LPCWSTR executable_path, LPCWSTR file_path, e_bcs_resource_type resource_type)
{
	char* file_data = nullptr;
	size_t file_length = 0;
	bool succeeded = filesystem_read_file_to_memory(file_path, &file_data, &file_length);
	ASSERT(succeeded);

	update_resource_data(executable_path, resource_type, file_data, file_length);

	delete[] file_data;
}

int WINAPI wWinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR lpCmdLine,
	_In_ int nShowCmd
)
{
	std::wstring executable = c_command_line::get_command_line_warg("-executable");
	if (executable.size() == 0)
	{
		c_console::write_line_verbose("ResourcesPackager> missing argument -executable");
		return 1;
	}

	std::wstring outputdir = c_command_line::get_command_line_warg("-outputdir");
	if (outputdir.size() == 0)
	{
		c_console::write_line_verbose("ResourcesPackager> missing argument -outputdir");
		return 1;
	}

	std::wstring resources = c_command_line::get_command_line_warg("-resources");
	if (resources.size() == 0)
	{
		c_console::write_line_verbose("ResourcesPackager> missing argument -resources");
		return 1;
	}

	bool mandrill = c_command_line::has_command_line_arg("-mandrill");
	bool gameframework = c_command_line::has_command_line_arg("-gameframework");
	if (!mandrill && !gameframework)
	{
		c_console::write_line_verbose("ResourcesPackager> missing argument -mandrill, -gameframework");
		return 1;
	}

	bool package_symbols = gameframework;
	bool package_shaders = gameframework;

	if (package_symbols)
	{
		std::wstring symbolfile = c_command_line::get_command_line_warg("-symbolfile");
		if (symbolfile.size() == 0)
		{
			c_console::write_line_verbose("ResourcesPackager> missing argument -symbolfile");
			return 1;
		}

		const char* excluded_symbol_libs[] =
		{
			"Shared",
			"MandrillLib",
			"MandrillGen",
			"imgui",
			"tbb_static",
			"gameframework",
			"detours"
		};

		c_map_file_parser map_file_parser = c_map_file_parser(symbolfile.c_str(), excluded_symbol_libs, _countof(excluded_symbol_libs));
		update_resource_data(executable.c_str(), _bcs_resource_type_symbols_blob, map_file_parser.get_sym_data(), map_file_parser.get_sym_size());
	}

	if (package_shaders)
	{
		std::wstring box_shader_ps_filepath = outputdir + L"BoxShaderPS.cso";
		std::wstring box_shader_vs_filepath = outputdir + L"BoxShaderVS.cso";
		update_resource(executable.c_str(), box_shader_ps_filepath.c_str(), _bcs_resource_type_box_pixel_shader);
		update_resource(executable.c_str(), box_shader_vs_filepath.c_str(), _bcs_resource_type_box_vertex_shader);
	}

	if (mandrill)
	{
#ifdef _DEBUG
		std::wstring mandrill_icon = resources + L"mandrill_icon_debug.ico";
#else
		std::wstring mandrill_icon = resources + L"mandrill_icon.ico";
#endif
		// #TODO Programatically replace icons here
	}

	c_console::write_line_verbose("ResourcesPackager> Successfully updated resources");

	return 0;
}