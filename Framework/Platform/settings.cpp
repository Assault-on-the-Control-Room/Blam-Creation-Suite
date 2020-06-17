#include "platform-private-pch.h"

bool c_settings::read_boolean(e_settings_section section, const char* pName, bool defaultValue /*= false*/)
{
	const char* pSectionName = get_section_name_string(section);
	return !!GetPrivateProfileIntA(pSectionName, pName, defaultValue, k_settings_path);
}

int c_settings::read_integer(e_settings_section section, const char* pName, int defaultValue /*= 0*/)
{
	const char* pSectionName = get_section_name_string(section);
	return GetPrivateProfileIntA(pSectionName, pName, defaultValue, k_settings_path);
}

float c_settings::read_float(e_settings_section section, const char* pName, float defaultValue /*= 0.0*/)
{
	char floatBuffer[32] = {};
	uint32_t length = read_string(section, pName, floatBuffer, sizeof(floatBuffer), "");

	if (length)
	{
		float value = static_cast<float>(atof(floatBuffer));
		return value;
	}
	return defaultValue;
}

uint32_t c_settings::read_string(e_settings_section section, const char* pName, char* buffer, uint32_t buffer_size, const char* pDefaultValue /*= nullptr*/)
{
	if (buffer_size > 0)
	{
		const char* pSectionName = get_section_name_string(section);
		memset(buffer, 0, buffer_size);
		GetPrivateProfileStringA(pSectionName, pName, pDefaultValue, buffer, buffer_size, k_settings_path);
		return static_cast<uint32_t>(strlen(buffer));
	}
	return 0;
}

uint32_t c_settings::read_wstring(e_settings_section section, const char* pName, wchar_t* buffer, uint32_t buffer_size, const wchar_t* pDefaultValue /*= nullptr*/)
{
	if (buffer_size > 0)
	{
		const char* pSectionName = get_section_name_string(section);
		memset(buffer, 0, buffer_size);

		size_t widecharNameBufferSize = (strlen(pName) + 1) * sizeof(wchar_t);
		wchar_t* pWidecharNameBuffer = static_cast<wchar_t*>(alloca(widecharNameBufferSize));
		memset(pWidecharNameBuffer, 0, widecharNameBufferSize);
		_snwprintf(pWidecharNameBuffer, widecharNameBufferSize / sizeof(wchar_t), L"%S", pName);

		size_t widecharSectionNameBufferSize = (strlen(pSectionName) + 1) * sizeof(wchar_t);
		wchar_t* pwidecharSectionNameBuffer = static_cast<wchar_t*>(alloca(widecharSectionNameBufferSize));
		memset(pwidecharSectionNameBuffer, 0, widecharSectionNameBufferSize);
		_snwprintf(pwidecharSectionNameBuffer, widecharSectionNameBufferSize / sizeof(wchar_t), L"%S", pSectionName);

		GetPrivateProfileStringW(pwidecharSectionNameBuffer, pWidecharNameBuffer, pDefaultValue, buffer, buffer_size, k_settings_path_wide);
		return static_cast<uint32_t>(wcslen(buffer));
	}
	return 0;
}

bool c_settings::write_boolean(e_settings_section section, const char* pName, bool value)
{
	const char* pSectionName = get_section_name_string(section);
	return WritePrivateProfileStringA(pSectionName, pName, value ? "1" : "0", k_settings_path);
}

bool c_settings::write_integer(e_settings_section section, const char* pName, int value)
{
	const char* pSectionName = get_section_name_string(section);
	size_t buffer_length = static_cast<int>(logl(UINT_MAX)) + 2;
	char* buffer = static_cast<char*>(alloca(buffer_length));
	memset(buffer, 0, buffer_length);
	_itoa(value, buffer, 10);
	return WritePrivateProfileStringA(pSectionName, pName, buffer, k_settings_path);
}

bool c_settings::write_string(e_settings_section section, const char* pName, const char* pValue)
{
	const char* pSectionName = get_section_name_string(section);
	return WritePrivateProfileStringA(pSectionName, pName, pValue, k_settings_path);
}

const char* c_settings::get_section_name_string(e_settings_section section)
{
	switch (section)
	{
	case _settings_section_game:
		return "Game";
	case _settings_section_camera:
		return "Camera";
	case _settings_section_player:
		return "Player";
	case _settings_section_debug:
		return "Debug";
	case _settings_section_launch:
		return "Launch";
	case _settings_section_controls:
		return "Controls";
	case _settings_section_mandrill:
		return "Mandrill";
	default:
		FATAL_ERROR(L"unknown <e_settings_section>");
		return nullptr;
	}
}
