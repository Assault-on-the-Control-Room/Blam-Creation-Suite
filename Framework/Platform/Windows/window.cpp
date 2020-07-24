#include "platform-private-pch.h"

HICON c_window::icon_handles[k_number_of_window_icons] =
{
	LoadIconW(c_runtime_util::get_current_module(), c_resources_manager::get_resource_int_resource(_bcs_resource_type_icon_application)),
	LoadIconW(c_runtime_util::get_current_module(), c_resources_manager::get_resource_int_resource(_bcs_resource_type_icon_blam_creation_suite)),
	LoadIconW(c_runtime_util::get_current_module(), c_resources_manager::get_resource_int_resource(_bcs_resource_type_icon_mandrill)),
};

c_window::c_window(
	HINSTANCE instance_handle,
	const wchar_t* window_title,
	const wchar_t* application_name,
	e_window_icon window_icon,
	int show_cmd) :
	instance_handle(instance_handle),
	icon_handle(icon_handles[window_icon]),
	window_handle(NULL),
	post_message_thread_handle(NULL),
	post_message_thread_id(NULL),
	width_integer(0),
	height_integer(0),
	width_float(0.0f),
	height_float(0.0f),
	aspect_ratio(0.0f)
{
	SetProcessDPIAware();

	instance_handle = GetModuleHandle(NULL);

	// Register the window class.

	WNDCLASSEXW window_class = { };
	window_class.cbSize = sizeof(WNDCLASSEX);
	window_class.style = CS_HREDRAW | CS_VREDRAW;
	window_class.lpfnWndProc = window_procedure;
	window_class.cbClsExtra = 0;
	window_class.cbWndExtra = 0;
	window_class.hInstance = instance_handle;
	window_class.hIcon = icon_handle;
	window_class.hCursor = LoadCursor(NULL, IDC_ARROW);
	window_class.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	window_class.lpszMenuName = NULL;
	window_class.lpszClassName = application_name;
	window_class.hCursor = NULL;
	ATOM register_class_ex_result = RegisterClassExW(&window_class);
	if (register_class_ex_result == NULL)
	{
		int last_error = GetLastError();
		FATAL_ERROR(L"Failed to register window class [%i]", last_error);
	}

	// Create the window.
	window_handle = CreateWindowExW(
		0,                              // Optional window styles.
		application_name,               // Window class
		window_title,					// Window text
		WS_OVERLAPPEDWINDOW,            // Window style
		// Size and position
		CW_USEDEFAULT, CW_USEDEFAULT,
		GetSystemMetrics(SM_CXSCREEN) / 4 * 3, GetSystemMetrics(SM_CYSCREEN) / 4 * 3,

		NULL,							// Parent window
		NULL,							// Menu
		instance_handle,					// Instance handle
		NULL							// Additional application data
	);

	if (window_handle == NULL)
	{
		int err = GetLastError();
		FATAL_ERROR(L"Failed to create window [%i]", err);
	}

	SetWindowLongPtr(window_handle, GWLP_USERDATA, LONG_PTR(this));

	ShowWindow(window_handle, show_cmd);
	SetFocus(window_handle);

	update_window_size();

	static RAWINPUTDEVICE raw_mouse_input_device = {};
	raw_mouse_input_device.usUsagePage = HID_USAGE_PAGE_GENERIC;
	raw_mouse_input_device.usUsage = HID_USAGE_GENERIC_MOUSE;
	raw_mouse_input_device.dwFlags = RIDEV_INPUTSINK;
	raw_mouse_input_device.hwndTarget = window_handle;
	static RAWINPUTDEVICE raw_input_devices[] = { raw_mouse_input_device };
	BOOL register_raw_input_devices_result = RegisterRawInputDevices(raw_input_devices, _countof(raw_input_devices), sizeof(raw_input_devices));
	ASSERT(register_raw_input_devices_result == TRUE);
}

c_window::~c_window()
{
	CloseWindow(window_handle);
	UnregisterClassA("mandrill_window_class", instance_handle);
}

void c_window::update(bool allow_callbacks)
{
	c_console::Update();

	MSG msg = {};

	while (PeekMessage(&msg, window_handle, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	if (GetAsyncKeyState(VK_F11))
	{
		on_destroy();
	}

	if (allow_callbacks)
	{
		on_update();
	}
}

void c_window::set_title(const wchar_t* title)
{
	::SetWindowTextW(window_handle, title);
}

void c_window::set_post_message_thread_id(HANDLE thread_handle)
{
	post_message_thread_handle = thread_handle;
	post_message_thread_id = GetThreadId(post_message_thread_handle);
}

bool c_window::is_focused()
{
	return true; // #TODO Implement a focus check
}

LRESULT CALLBACK c_window::window_procedure(HWND hwnd, UINT msg, WPARAM w_param, LPARAM l_param)
{
	c_window* _this = (c_window*)(GetWindowLongPtr(hwnd, GWLP_USERDATA));
	if (_this)
	{
		return _this->window_procedure_impl(hwnd, msg, w_param, l_param);
	}
	else
	{
		return DefWindowProc(hwnd, msg, w_param, l_param);
	}
}

LRESULT c_window::window_procedure_impl(HWND hwnd, UINT msg, WPARAM w_param, LPARAM l_param)
{
	on_window_procedure(hwnd, msg, w_param, l_param);

	switch (msg)
	{
	case WM_SYSCOMMAND:
		if ((w_param & 0xfff0) == SC_KEYMENU)
		{
			return 0;
		}
		break;
	case WM_DESTROY:
		on_destroy();
		PostQuitMessage(WM_QUIT);
		break;
	case WM_SIZE:
		update_window_size();
		on_resize(get_width_integer(), get_height_integer());
		// #TODO: tell game to resize
		break;
	//case WM_KILLFOCUS:
	//case WM_SETFOCUS:
	//	s_focused_window_handle = GetFocus();
	//	s_foreground_window_handle = GetForegroundWindow();
	//	break;
	}
	return DefWindowProc(hwnd, msg, w_param, l_param);
}

void c_window::update_window_size()
{
	RECT rect = {};
	GetClientRect(window_handle, &rect);

	width_integer = static_cast<uint32_t>(__max(1, rect.right - rect.left));
	height_integer = static_cast<uint32_t>(__max(1, rect.bottom - rect.top));
	width_float = static_cast<float>(width_integer);
	height_float = static_cast<float>(height_integer);
	aspect_ratio = width_float / height_float;
}
