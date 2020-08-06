#include <Platform\platform-public-pch.h>
#include <Versioning\versioning-public-pch.h>
#include <Shared\shared-public-pch.h>
#include <TagDefinitions\tagdefinitions-public-pch.h>
#include <MandrillLib\mandrilllib-public-pch.h>
#include <GameFramework\gameframework-private-pch.h>
#include <Rhesus\rhesus-private-pch.h>

DirectX::XMFLOAT4 clearColor = { 0.01f, 0.011f, 0.03f, 1.0f };

const char* c_console::g_console_executable_name = "Opus";
c_window* window = nullptr;

int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd
)
{
	c_discord_presense_api discord = c_discord_presense_api("483795144114569227");

	c_presense_api::set_default_state();

	int result = 0;
	if (rhesus_crash_reporter(result))
	{
		return result;
	}

	register_platforms();

	c_console::init_console();

	SystemPatch::PatchEnumWindows();

	static bool s_running = true;
	auto update_callback = [&discord]()
	{
		c_render::begin_frame(true, &clearColor.x);
		c_game_launcher::opus_tick();
		c_render::end_frame();
	};
	void(*DestroyCallback)() = []()
	{
		s_running = false;
	};

#ifdef _DEBUG
	const wchar_t* k_window_title = L"Opus Debug";
#else
	const wchar_t* k_window_title = L"Opus";
#endif
	c_console::write_line("creating window");
	window = new c_window(hInstance, k_window_title, L"mandrill", _window_icon_blam_creation_suite, nShowCmd);
	c_console::write_line("init_render");
	c_render::init_render(window, hInstance);
	c_console::write_line("init_game_launcher");
	c_game_launcher::init_game_launcher(*window);

	window->on_update.register_callback(&update_callback, update_callback);
	window->on_destroy.register_callback(DestroyCallback);

	c_console::show_startup_banner();

	while (s_running)
	{
		window->update();
	}

	window->on_update.unregister_callback(&update_callback, update_callback);
	window->on_destroy.unregister_callback(DestroyCallback);

	c_game_launcher::deinit_game_launcher();
	c_render::deinit_render();
	delete window;
	c_console::deinit_console();

	return 0;
}