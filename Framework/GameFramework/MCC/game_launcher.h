#pragma once

enum e_next_launch_mode
{
	_next_launch_mode_none,
	_next_launch_mode_generic,
	_next_launch_mode_theater
};

enum e_variant_type
{
	_variant_type_game,
	_variant_type_map,

	//_variant_type_film,
	//_variant_type_save,

	k_number_of_variant_types
};

class c_mandrill_user_interface;

class c_game_launcher
{
public:
	static void init_game_launcher(c_window& window);
	static void deinit_game_launcher();
	static void add_supported_engine(e_engine_type engine_type);
	static void aotus_tick();
	static void game_exited_callback();
	static void window_destroy_callback();
	inline static bool is_game_running() { return s_is_game_running; }
private:
	static void load_settings();
	static void update();
	static void render_main_menu();
	static void render_ui();
	static void game_render();
	static void start_game(e_engine_type engine_type, e_next_launch_mode next_launch_mode);
	static void launch_game(e_engine_type engine_type);
	static void init_steam_ownership();
	static void ensure_library_loaded(const char* library_name, const char* fallback_directory);
	static void render_pause_menu();
#ifdef _WINDOWS_
	static LRESULT window_procedure(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
#endif
	static bool load_variant_from_file(IDataAccess* data_access, GameOptions* options, e_engine_type engine_type, e_variant_type variant_type, LPCSTR file_name);

	static bool load_save_from_file(GameOptions* options, LPCSTR file_name, bool should_run);

	static std::vector<std::string>& variant_files_get(e_engine_type engine_type, e_variant_type variant_type);

	// #TODO: Move these into each lib
#ifdef _WIN64
	static void launch_mcc_game(e_engine_type engine_type);
#else
	static void launch_eldorado_game();
#endif
private:

public:
	static c_mandrill_user_interface* mandrill_user_interface;
	using t_generic_game_event = void(*)(s_engine_platform_build engine_platform_build);
	inline static void register_game_startup_callback(t_generic_game_event event_callback) { s_game_startup_events.push_back(event_callback); }
	inline static void register_game_shutdown_callback(t_generic_game_event event_callback) { s_game_shutdown_events.push_back(event_callback); }
	inline static void unregister_game_startup_callback(t_generic_game_event event_callback) { vector_erase_by_value_helper(s_game_startup_events, event_callback); }
	inline static void unregister_game_shutdown_callback(t_generic_game_event event_callback) { vector_erase_by_value_helper(s_game_shutdown_events, event_callback); }



	inline static c_window* get_window() { return s_window; }
	inline static c_mouse_input* get_mouse_input() { return s_mouse_input; }

private:
	static c_window* s_window; 
	static c_mouse_input* s_mouse_input;
	static std::vector<t_generic_game_event> s_game_startup_events;
	static std::vector<t_generic_game_event> s_game_shutdown_events;
	static bool s_is_game_running;
};
