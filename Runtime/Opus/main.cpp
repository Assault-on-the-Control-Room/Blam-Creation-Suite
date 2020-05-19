#include <Shared\shared-public-pch.h>
#include <TagDefinitions/tagdefinitions-public-pch.h>
#include <MantleLib\mantlelib-public-pch.h>
#include <OpusFramework\opusframework-private-pch.h>

DirectX::XMFLOAT4 clearColor = { 0.01f, 0.011f, 0.03f, 1.0f };

const char* c_console::g_console_executable_name = "Opus";

int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd
)
{
	register_platforms();

	c_console::init_console();

	c_window_win32::SetIcon(LoadIconA(hInstance, c_resources_manager::get_resource_int_resource(_resource_type_icon)));
	SystemPatch::PatchEnumWindows();

	static bool s_running = true;
	void(*UpdateCallback)() = []()
	{
		c_render::begin_frame(true, &clearColor.x);
		c_game_launcher::opus_tick();
		c_render::end_frame();
	};
	void(*DestroyCallback)() = []()
	{
		s_running = false;
	};
	
	c_window_win32::init_window("Opus", "OpusConsole", "opus");
	c_render::init_render(hInstance);
	c_mantle_gui::init_mantle_gui(true);
	c_game_launcher::init_game_launcher();

	c_window_win32::register_update_callback(UpdateCallback);
	c_window_win32::register_destroy_callback(DestroyCallback);
	//MantleGUI::RegisterOnCloseCallback(DestroyCallback);

	c_console::show_startup_banner();

	while (s_running) c_window_win32::update_window();

	c_window_win32::unregister_update_callback(UpdateCallback);
	c_window_win32::unregister_destroy_callback(DestroyCallback);
	//MantleGUI::UnregisterOnCloseCallback(DestroyCallback);

	c_game_launcher::deinit_game_launcher();
	c_mantle_gui::deinit_mantle_gui();
	c_render::deinit_render();
	c_window_win32::deinit_window();
	c_console::deinit_console();

	return 0;
}