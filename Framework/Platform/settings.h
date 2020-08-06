#pragma once

enum e_settings_section
{
	_settings_section_game,
	_settings_section_camera,
	_settings_section_player,
	_settings_section_player_configuration,
	_settings_section_debug,
	_settings_section_launch,
	_settings_section_mandrill
};

class c_settings
{
public:
	static constexpr char k_settings_path[MAX_PATH] = ".\\Settings.ini";
	static constexpr wchar_t k_settings_path_wide[MAX_PATH] = L".\\Settings.ini";

	static bool read_boolean(e_settings_section section, const char* name, bool defaultValue = false);
	static int read_integer(e_settings_section section, const char* name, int defaultValue = 0);
	static float read_float(e_settings_section section, const char* name, float defaultValue = 0.0);
	static uint32_t read_string(e_settings_section section, const char* name, char* buffer, uint32_t buffer_size, const char* default_value = nullptr);
	static uint32_t read_wstring(e_settings_section section, const char* name, wchar_t* buffer, uint32_t buffer_size, const wchar_t* default_value = nullptr);

	static bool write_boolean(e_settings_section section, const char* name, bool value);
	static bool write_integer(e_settings_section section, const char* name, int value);
	static bool write_float(e_settings_section section, const char* name, float value);
	static bool write_string(e_settings_section section, const char* name, const char* value);
	static bool write_wstring(e_settings_section section, const char* name, const wchar_t* value);

	static const char* get_section_name_string(e_settings_section section);
};

