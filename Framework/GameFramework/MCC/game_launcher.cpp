#include "gameframework-private-pch.h"

e_next_launch_mode g_next_launch_mode = _next_launch_mode_none;

c_window* c_game_launcher::s_window = nullptr;
c_mouse_input* c_game_launcher::s_mouse_input = nullptr;
std::vector<c_game_launcher::t_generic_game_event> c_game_launcher::s_game_startup_events;
std::vector<c_game_launcher::t_generic_game_event> c_game_launcher::s_game_shutdown_events;
bool c_game_launcher::s_is_game_running = false;
c_opus_game_engine_host* current_game_host = nullptr;
e_campaign_difficulty_level g_campaign_difficulty_level = _campaign_difficulty_level_normal; // #TODO #REFACTOR
c_mandrill_user_interface* c_game_launcher::mandrill_user_interface = nullptr;




static std::vector<e_engine_type> g_supported_engine_types;
static e_engine_type g_engine_type = _engine_type_not_set;
static std::vector<e_map_id> g_haloreach_map_ids;
static std::vector<e_map_id> g_halo1_map_ids;
e_map_id g_halo1_map_id = _map_id_mainmenu;
static std::vector<e_map_id> g_halo2_map_ids;
e_map_id g_halo2_map_id = _map_id_mainmenu;
static std::vector<e_map_id> g_halo3_map_ids;
e_map_id g_halo3_map_id = _map_id_mainmenu;
static std::vector<e_map_id> g_halo3odst_map_ids;
e_map_id g_halo3odst_map_id = _map_id_halo3odst_mombasa_streets;
static std::vector<e_map_id> g_halo4_map_ids;
e_map_id g_halo4_map_id = _map_id_halo4_ragnarok;
static std::vector<e_map_id> g_groundhog_map_ids;
e_map_id g_groundhog_map_id = _map_id_groundhog_coagulation;
static bool has_auto_started = false;
static bool k_autostart_halo_haloreach = false;
static bool k_autostart_halo_halo1 = false;
static bool k_autostart_halo_halo2 = false;
static bool k_autostart_halo_halo3 = false;
static bool k_autostart_halo_groundhog = false;
static bool k_autostart_halo_eldorado = false;
static bool k_autostart_halo_online = false;
static bool use_remastered_visuals = true;
static bool use_remastered_music = true;
static bool start_as_forge_mode = true;

void c_game_launcher::init_game_launcher(c_window& window)
{
	s_window = &window;
	s_mouse_input = new c_mouse_input(*s_window);
	k_autostart_halo_haloreach = c_command_line::get_command_line_arg("-autostart") == "haloreach";
	k_autostart_halo_halo1 = c_command_line::get_command_line_arg("-autostart") == "halo1";
	k_autostart_halo_halo2 = c_command_line::get_command_line_arg("-autostart") == "halo2";
	k_autostart_halo_halo3 = c_command_line::get_command_line_arg("-autostart") == "halo3";
	k_autostart_halo_groundhog = c_command_line::get_command_line_arg("-autostart") == "groundhog";
	k_autostart_halo_eldorado = c_command_line::get_command_line_arg("-autostart") == "eldorado";
	k_autostart_halo_online = c_command_line::get_command_line_arg("-autostart") == "haloonline";

#ifdef _WIN64
	ensure_library_loaded("steam_api64.dll", "MCC\\Binaries\\Win64");
	check_steam_ownership();

	c_console::write_line("checking supported game versions");

	// #TODO: Find a home for this

	bool is_bink2_required = false;
	bool is_fmod_required = false;
	bool is_fmod_event_net_required = false;
	bool is_mopp_required = false;
	bool is_ati_compress_required = false;
	bool is_miles_sound_system_required = false;
	if (PathFileExistsA("haloreach\\haloreach.dll"))
	{
		is_bink2_required = true;
		g_supported_engine_types.push_back(_engine_type_haloreach);
	}

	if (PathFileExistsA("halo1\\halo1.dll"))
	{
		is_fmod_required = true;
		is_fmod_event_net_required = true;
		g_supported_engine_types.push_back(_engine_type_halo1);
	}

	if (PathFileExistsA("halo2\\halo2.dll"))
	{
		is_bink2_required = true;
		is_mopp_required = true;
		is_ati_compress_required = true;
		is_miles_sound_system_required = true;
		g_supported_engine_types.push_back(_engine_type_halo2);
	}

	if (PathFileExistsA("groundhog\\groundhog.dll"))
	{
		g_supported_engine_types.push_back(_engine_type_groundhog);
	}

	if (PathFileExistsA("halo3\\halo3.dll"))
	{
		is_bink2_required = true;
		g_supported_engine_types.push_back(_engine_type_halo3);
	}

	if (is_bink2_required)
	{
		ensure_library_loaded("bink2w64.dll", "MCC\\Binaries\\Win64");
	}
	if (is_fmod_required)
	{
		ensure_library_loaded("halo1\\fmodex64.dll", "..\\halo1");
	}
	if (is_fmod_event_net_required)
	{
		ensure_library_loaded("halo1\\fmod_event_net64.dll", "..\\halo1");
	}
	if (is_fmod_event_net_required)
	{
		ensure_library_loaded("halo1\\fmod_event_net64.dll", "..\\halo1");
	}
	if (is_mopp_required)
	{
		ensure_library_loaded("halo2\\MOPP.dll", "..\\halo2");
	}
	if (is_ati_compress_required)
	{
		ensure_library_loaded("halo2\\ATICompressDLL.dll", "..\\halo2");
	}
	if (is_miles_sound_system_required)
	{
		ensure_library_loaded("halo2\\mss64.dll", "..\\halo2");
	}
#endif

	g_halo1_map_ids.push_back(_map_id_mainmenu);
	g_halo2_map_ids.push_back(_map_id_mainmenu);
	g_halo3_map_ids.push_back(_map_id_mainmenu);

	for (long i = 0; i < k_number_of_map_ids; i++)
	{
		e_map_id map_id = static_cast<e_map_id>(i);
		e_engine_type engine_type = map_id_to_engine_type(map_id);
		switch (engine_type)
		{
		case _engine_type_haloreach:
			g_haloreach_map_ids.push_back(map_id);
			break;
		case _engine_type_halo1:
			g_halo1_map_ids.push_back(map_id);
			break;
		case _engine_type_halo2:
			g_halo2_map_ids.push_back(map_id);
			break;
		case _engine_type_halo3:
			g_halo3_map_ids.push_back(map_id);
			break;
		case _engine_type_halo3odst:
			g_halo3odst_map_ids.push_back(map_id);
			break;
		case _engine_type_halo4:
			g_halo4_map_ids.push_back(map_id);
			break;
		case _engine_type_groundhog:
			g_groundhog_map_ids.push_back(map_id);
			break;
		}
	}
	g_halo3_map_id = g_halo3_map_ids.front();

	// #TODO: Attempt to restore from previously selected engine
	g_engine_type = g_supported_engine_types.empty() ? _engine_type_not_set : g_supported_engine_types.front();

	c_game_launcher::load_settings();
#ifdef _WIN64
	c_haloreach_game_option_selection_legacy::Init();
#endif
	s_window->on_window_procedure.register_callback(window_procedure);
	s_window->on_window_procedure.register_callback(c_debug_gui::window_procedure);
	c_debug_gui::register_callback(_callback_mode_always_run, render_main_menu);
	c_debug_gui::register_callback(_callback_mode_toggleable, render_ui);

	s_window->on_destroy.register_callback(window_destroy_callback);

	ASSERT(mandrill_user_interface == nullptr);
	mandrill_user_interface = new c_mandrill_user_interface(*s_window, true);

	if (!has_auto_started)
	{
		if (k_autostart_halo_haloreach) start_game(_engine_type_haloreach, _next_launch_mode_generic);
		if (k_autostart_halo_halo1) start_game(_engine_type_halo1, _next_launch_mode_generic);
		if (k_autostart_halo_halo2) start_game(_engine_type_halo2, _next_launch_mode_generic);
		if (k_autostart_halo_halo3) start_game(_engine_type_halo3, _next_launch_mode_generic);
		if (k_autostart_halo_groundhog) start_game(_engine_type_groundhog, _next_launch_mode_generic);
		if (k_autostart_halo_eldorado || k_autostart_halo_online) start_game(_engine_type_eldorado, _next_launch_mode_generic);
	}

	c_console::write_line_verbose("and here we go...");
}

void c_game_launcher::deinit_game_launcher()
{
	delete mandrill_user_interface;
	mandrill_user_interface = nullptr;

	s_window->on_destroy.unregister_callback(window_destroy_callback);
	c_debug_gui::unregister_callback(_callback_mode_always_run, render_main_menu);
	c_debug_gui::unregister_callback(_callback_mode_toggleable, render_ui);
	s_window->on_window_procedure.unregister_callback(window_procedure);
#ifdef _WIN64
	c_haloreach_game_option_selection_legacy::deinit();
#endif
	delete s_mouse_input;
	s_mouse_input = nullptr;
	s_window = nullptr;
}

void c_game_launcher::window_destroy_callback()
{
	// terrible hack but lets tell the game to quit and then wait for no game to be running
	if (s_is_game_running)
	{
		IGameEngine* game_engine = current_game_host->get_game_engine();
		ASSERT(game_engine != nullptr);
		game_engine->update_engine_state(_engine_state_immediate_exit);
		c_console::write_line_verbose("Waiting for game to exit...");
		while (s_is_game_running) { Sleep(1); }
	}
}

void c_game_launcher::load_settings()
{
	float horizontalSensitivity = c_settings::read_float(_settings_section_controls, "HorizontalSensitivity", 1.0f);
	float verticalSensitivity = c_settings::read_float(_settings_section_controls, "VerticalSensitivity", 1.0f);
	s_mouse_input->set_sensitivity(horizontalSensitivity, verticalSensitivity);
}

void c_game_launcher::opus_tick()
{
	if (!s_is_game_running)
	{
		update();
	}

	c_presense_api::update();
	c_debug_gui::start_frame(); // OpusUITick is registered to the DebugUI
	//OpusUITick();
	if (c_debug_gui::is_rendering() && s_is_game_running) // render a debug layer for the game to render text to
	{
		constexpr ImGuiWindowFlags k_debug_window_flags =
			ImGuiWindowFlags_NoMove |
			ImGuiWindowFlags_NoBackground |
			ImGuiWindowFlags_NoSavedSettings |
			ImGuiWindowFlags_NoMouseInputs |
			ImGuiWindowFlags_NoNav |
			ImGuiWindowFlags_NoDecoration |
			ImGuiWindowFlags_NoInputs;
		ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_Always);
		ImGui::SetNextWindowSize(ImVec2(s_window->get_width_float(), s_window->get_height_float()), ImGuiCond_Always);
		if (ImGui::Begin("##debug", NULL, k_debug_window_flags)) // render inside of the dummy imgui window for on screen text display
		{
			game_render();
		}
		ImGui::End();
	}
	c_debug_gui::end_frame();
}

void c_game_launcher::game_exited_callback()
{
	s_is_game_running = false;
}

void c_game_launcher::update()
{
	if (s_is_game_running)
	{
		// need some place to update the launcher, might as well do it here for now
		s_window->update(false);
	}
	else
	{
		if (g_next_launch_mode != _next_launch_mode_none)
		{
			g_next_launch_mode = _next_launch_mode_none;
			launch_game(g_engine_type);
		}
	}
}

void c_game_launcher::game_render()
{
	mandrill_user_interface->render_game_layer();
	c_primitive_render_manager::render();
}

void c_game_launcher::start_game(e_engine_type engine_type, e_next_launch_mode next_launch_mode)
{
	g_engine_type = engine_type;
	g_next_launch_mode = next_launch_mode;

#ifdef _WIN64
	c_haloreach_game_option_selection_legacy::s_launch_saved_film_filepath = "";
#endif
	has_auto_started = true;
	g_next_launch_mode = _next_launch_mode_generic;

}

void c_game_launcher::render_ui()
{
	mandrill_user_interface->render();
	if (s_is_game_running)
	{
		current_game_host->render_ui();
	}
}

void c_game_launcher::launch_game(e_engine_type engine_type)
{
	s_is_game_running = true;
	// #TODO: We currently can't resize the game without crashing
	// we should do this at the beginning of the frame.

	s_presense_info presense_info = {};
	presense_info.engine_type = engine_type;
	presense_info.party_max = 1;
	presense_info.party_size = 1;
	presense_info.map_name = "unknown"; // #TODO
	presense_info.gametype_name = "unknown"; // #TODO
	c_presense_api::set_state(&presense_info);

	c_render::set_resize_enabled(false);
	switch (engine_type)
	{
#ifdef _WIN64
	case _engine_type_haloreach:
	case _engine_type_halo1:
	case _engine_type_halo2:
	case _engine_type_halo3:
	case _engine_type_groundhog:
		launch_mcc_game(engine_type);
		break;
#else
	case _engine_type_eldorado:
		launch_eldorado_game();
		break;
#endif
	}
	c_render::set_resize_enabled(true);

	c_presense_api::set_default_state();

	s_is_game_running = false;
}
#ifdef _WIN64
void c_game_launcher::launch_mcc_game(e_engine_type engine_type)
{
	ASSERT(current_game_host == nullptr);

	e_build build = _build_not_set;
	switch (engine_type)
	{
	case _engine_type_haloreach:
		build = c_haloreach_game_host::get_game_runtime().get_build();
		current_game_host = new c_haloreach_game_host(engine_type, build);
		break;
	case _engine_type_halo1:
		build = c_halo1_game_host::get_game_runtime().get_build();
		current_game_host = new c_halo1_game_host(engine_type, build);
		c_haloreach_game_option_selection_legacy::s_launch_game_variant = "02_team_slayer";
		c_haloreach_game_option_selection_legacy::s_launch_map_variant = "Blood Gulch"; // map variants don't exist in Halo 1
		break;
	case _engine_type_halo2:
		build = c_halo2_game_host::get_game_runtime().get_build();
		current_game_host = new c_halo2_game_host(engine_type, build);
		c_haloreach_game_option_selection_legacy::s_launch_game_variant = "02_team_slayer";
		//c_haloreach_game_option_selection_legacy::s_launch_map_variant = "Bloodline"; // map variants don't exist in Halo 2
		break;
	case _engine_type_halo3:
		build = c_halo3_game_host::get_game_runtime().get_build();
		current_game_host = new c_halo3_game_host(engine_type, build);
		c_haloreach_game_option_selection_legacy::s_launch_game_variant = "00_sandbox-0_010";
		c_haloreach_game_option_selection_legacy::s_launch_map_variant = "default_last_resort_012";
		break;
	case _engine_type_groundhog:
		build = c_groundhog_game_host::get_game_runtime().get_build();
		current_game_host = new c_groundhog_game_host(engine_type, build);

		// commented out `start_as_forge_mode` checkbox due to incompatibility with normal multiplayer game modes, who doesn't want forge to be default anyway
		c_haloreach_game_option_selection_legacy::s_launch_game_variant = start_as_forge_mode ? "H2A_001_001_basic_editing_137" : "H2A_100_250_Slayer_BR_137";
		//c_haloreach_game_option_selection_legacy::s_launch_map_variant = "Bloodline"; // if left blank a default map variant is created
		break;
	default:
		c_console::write_line_verbose(__FUNCTION__"> unknown engine_type");
		return;
	}

	ASSERT(current_game_host != nullptr);
	IGameEngine* game_engine = current_game_host->get_game_engine();
	ASSERT(game_engine != nullptr);

	// #TODO: Game specific version of this!!!

	for (t_generic_game_event game_event : s_game_startup_events)
	{
		game_event(engine_type, build);
	}

	GameContext* game_context = nullptr;
	c_session_manager::create_game_context(build, &game_context);
	ASSERT(game_context);

	game_context->visual_remaster = use_remastered_visuals;
	game_context->music_remaster = use_remastered_music;

	if (!load_save_from_file(game_context, "5EE59DB6.halo3", false))
	{
		// #TODO: Make a home for this
		if (game_context->is_host)
		{
			IDataAccess *data_access = nullptr;

			game_context->campaign_difficulty_level = g_campaign_difficulty_level;

			if (engine_type == _engine_type_haloreach)
			{
				const MapInfo *selected_map_info = c_haloreach_game_option_selection_legacy::get_selected_map_info();
				e_mcc_game_mode game_mode = c_haloreach_game_option_selection_legacy::get_selected_game_mode();

				game_context->game_mode = game_mode;
				game_context->map_id = static_cast<e_map_id>(selected_map_info->GetMapID());
				data_access = c_haloreach_game_host::get_data_access();

				//c_haloreach_game_option_selection_legacy::load_savegame("gamestate", *game_context);
				//c_haloreach_game_option_selection_legacy::load_savefilm(c_haloreach_game_option_selection_legacy::s_launch_saved_film_filepath.c_str(), *game_context);

				{
					// #TODO: Move this over to a IGameEngineHost callback so when a new map is loaded we load the cache file into mandrill
					const char *map_file_name = selected_map_info->GetMafilepath();
					c_console::write_line_verbose("Loading map '%s.map'", map_file_name);
					{
						wchar_t map_filepath[MAX_PATH + 1] = {};
						_snwprintf(map_filepath, MAX_PATH, L"%S%S.map", "haloreach/maps/", map_file_name);
						mandrill_user_interface->open_cache_file_tab(map_filepath);
					}
				}
			}

			switch (engine_type)
			{
			case _engine_type_halo1:
				game_context->game_mode = map_id_to_game_mode(g_halo1_map_id);
				game_context->map_id = g_halo1_map_id;
				if (game_context->game_mode == _mcc_game_mode_multiplayer)
				{
					data_access = c_halo1_game_host::get_data_access();
				}
				break;
			case _engine_type_halo2:
				game_context->game_mode = map_id_to_game_mode(g_halo2_map_id);
				game_context->map_id = g_halo2_map_id;
				if (game_context->game_mode == _mcc_game_mode_multiplayer)
				{
					data_access = c_halo2_game_host::get_data_access();
				}
				break;
			case _engine_type_halo3:
				game_context->game_mode = map_id_to_game_mode(g_halo3_map_id);
				game_context->map_id = g_halo3_map_id;
				data_access = c_halo3_game_host::get_data_access();
				break;
			case _engine_type_halo3odst:
				game_context->game_mode = map_id_to_game_mode(g_halo3odst_map_id);
				game_context->map_id = g_halo3odst_map_id;
				//data_access = c_halo3odst_game_host::get_data_access();
				break;
			case _engine_type_halo4:
				game_context->game_mode = map_id_to_game_mode(g_halo4_map_id);
				game_context->map_id = g_halo4_map_id;
				//data_access = c_halo4_game_host::get_data_access();
				break;
			case _engine_type_groundhog:
				game_context->game_mode = map_id_to_game_mode(g_groundhog_map_id);
				game_context->map_id = g_groundhog_map_id;
				data_access = c_groundhog_game_host::get_data_access();
				break;
			}

			if (data_access != nullptr)
			{
				load_variant_from_file(data_access, game_context, engine_type, e_variant_type::_variant_type_game,
					c_haloreach_game_option_selection_legacy::s_launch_game_variant.c_str()
				);
				load_variant_from_file(data_access, game_context, engine_type, e_variant_type::_variant_type_map,
					c_haloreach_game_option_selection_legacy::s_launch_map_variant.c_str()
				);
			}
		}
	}

	{
		// useful for testing if the gameenginehostcallback vftable is correct or not
		constexpr bool k_bogus_game_engine_host_callback_vft = false;
		if constexpr (k_bogus_game_engine_host_callback_vft)
		{
			void*& game_engine_host_vftable = *reinterpret_cast<void**>(current_game_host);
			static char data[sizeof(void*) * 1024] = {};
			memset(data, -1, sizeof(data));
			constexpr size_t k_num_bytes_to_copy_from_existing_vft = 0;
			memcpy(data, game_engine_host_vftable, k_num_bytes_to_copy_from_existing_vft);
			game_engine_host_vftable = data;
		}
	}

	IGameEngineHost* game_engine_host = current_game_host->GetDynamicGameEngineHost();
	static HANDLE game_main_thread = NULL;

	game_engine->Member04(c_render::s_device);
	game_engine->Member05(game_context->map_id);
	game_engine->InitGraphics(c_render::s_device, c_render::s_device_context, c_render::s_swap_chain, c_render::s_swap_chain);
	game_main_thread = game_engine->InitThread(game_engine_host, game_context);

	s_window->set_post_message_thread_id(game_main_thread);

	// #TODO: Absolutely terrible thread sync here
	{
		while (s_is_game_running)
		{
			update();
			SwitchToThread(); // don't smash the CPU
		}
		WaitForSingleObject(game_main_thread, INFINITE);
	}

	delete game_context;


	//HRESULT waitForSingleObjectResult;
	//do
	//{
	//	update();
	//	waitForSingleObjectResult = WaitForSingleObject(hMainGameThread, 5);
	//} while (waitForSingleObjectResult == WAIT_TIMEOUT);
	//WaitForSingleObject(hMainGameThread, INFINITE);

	c_console::write_line_verbose("Game has exited.");

	for (t_generic_game_event game_event : s_game_shutdown_events)
	{
		game_event(engine_type, build);
	}

	delete current_game_host;
	current_game_host = nullptr;

	// reset runtime information after we've destroyed the engine
	//s_pCurrentGameRuntime = nullptr;
}
#else
void c_game_launcher::launch_eldorado_game()
{

}

#endif
void c_game_launcher::check_steam_ownership()
{
#ifdef _WIN64
	{
		static const char k_steam_appid[] = "976730";
		bool write_file_from_memory_result = filesystem_write_file_from_memory("steam_appid.txt", k_steam_appid, strlen(k_steam_appid));
		ASSERT(write_file_from_memory_result == true);
	}

	bool steam_api_init_result = SteamAPI_Init();
	if (!steam_api_init_result)
	{
		c_console::write_line("Steam failed to initialize.");
		MessageBoxA(NULL, "Fatal Error - Steam failed to initialize", "Fatal Error", MB_OK | MB_ICONWARNING);
		exit(1);
	}
#endif
}

void c_game_launcher::ensure_library_loaded(const char* library_name, const char* fallback_directory)
{
	HMODULE module_handle = GetModuleHandleA(library_name);
	if (!module_handle)
	{
		module_handle = LoadLibraryA(library_name);

		// use fallback if
		if (!module_handle && fallback_directory[0])
		{
			char fallbackPath[MAX_PATH] = {};
			sprintf(fallbackPath, "%s\\%s", fallback_directory, library_name);
			module_handle = GetModuleHandleA(fallbackPath);
			if (!module_handle)
			{
				module_handle = LoadLibraryA(fallbackPath);
			}
		}
	}
	if (!module_handle)
	{
		c_console::write_line("failed to load library '%s'", library_name);
		MessageBoxA(s_window->get_window_handle(), library_name, "failed to load library", MB_ICONERROR);
	}
	ASSERT(module_handle != NULL);
}

#ifdef _WIN64
void display_map_in_ui(std::vector<e_map_id> map_ids, e_map_id& map_id_ref)
{
	if (ImGui::BeginCombo("Map", get_enum_string<const char*, true>(map_id_ref)))
	{
		for (e_map_id map_id : map_ids)
		{
			bool is_selected = map_id == map_id_ref;

			if (ImGui::Selectable(get_enum_string<const char*, true>(map_id), is_selected))
			{
				map_id_ref = map_id;
			}
		}
		ImGui::EndCombo();
	}

	if (map_id_to_engine_type(map_id_ref) == _mcc_game_mode_campaign)
	{
		ImGui::Checkbox("Use Remastered Visuals", &use_remastered_visuals);
		ImGui::Checkbox("Use Remastered Music", &use_remastered_music);
		c_haloreach_game_option_selection_legacy::SelectDifficulty(); // #TODO #REFACTOR
	}

	if (map_id_to_engine_type(map_id_ref) == _mcc_game_mode_multiplayer)
	{
		// commented out due to incompatibility with normal multiplayer game modes, who doesn't want forge to be default anyway
		//ImGui::Checkbox("Forge Mode", &start_as_forge_mode);
	}
}
#endif

void c_game_launcher::render_main_menu()
{
	if (s_is_game_running) return;
	s_mouse_input->set_mode(_mouse_mode_ui);

	ImVec2 global_window_size = ImVec2(s_window->get_width_float(), s_window->get_height_float());
	ImVec2 imgui_window_size = ImVec2(global_window_size.x * 0.75f, global_window_size.y * 0.75f);
	ImVec2 imgui_window_offset = ImVec2((global_window_size.x - imgui_window_size.x) / 2.0f, (global_window_size.y - imgui_window_size.y) / 2.0f);
	ImGui::SetNextWindowSize(imgui_window_size, ImGuiCond_Always);
	ImGui::SetNextWindowPos(imgui_window_offset, ImGuiCond_Always);

	constexpr ImGuiWindowFlags window_flags =
		ImGuiWindowFlags_NoCollapse |
		ImGuiWindowFlags_NoTitleBar |
		ImGuiWindowFlags_NoMove |
		ImGuiWindowFlags_NoResize |
		ImGuiWindowFlags_NoSavedSettings;
	if (ImGui::Begin("Main Menu", nullptr, window_flags))
	{
		ImGui::Columns(2);
		ImGui::SetColumnOffset(1, s_window->get_width_float() * 0.5f);

		const char* current_engine_name = get_enum_pretty_string<decltype(current_engine_name)>(g_engine_type);
		if (ImGui::BeginCombo("Game", current_engine_name))
		{
			for (e_engine_type supported_engine_type : g_supported_engine_types)
			{
				const char* supported_engine_name = get_enum_pretty_string<decltype(supported_engine_name)>(supported_engine_type);
				if (ImGui::Selectable(supported_engine_name))
				{
					g_engine_type = supported_engine_type;
				}
			}

			ImGui::EndCombo();
		}

		switch (g_engine_type)
		{
#ifdef _WIN64
		case _engine_type_haloreach:	c_haloreach_game_option_selection_legacy::Render(); break;
		case _engine_type_halo1:		display_map_in_ui(g_halo1_map_ids, g_halo1_map_id); break;
		case _engine_type_halo2:		display_map_in_ui(g_halo2_map_ids, g_halo2_map_id); break;
		case _engine_type_halo3:		display_map_in_ui(g_halo3_map_ids, g_halo3_map_id); break;
		case _engine_type_halo3odst:	display_map_in_ui(g_halo3odst_map_ids, g_halo3odst_map_id); break;
		case _engine_type_halo4:		display_map_in_ui(g_halo4_map_ids, g_halo4_map_id); break;
		case _engine_type_groundhog:	display_map_in_ui(g_groundhog_map_ids, g_groundhog_map_id); break;
#else
		case _engine_type_eldorado:
			break;
#endif
}

		ImGui::Dummy(ImVec2(0.0f, 30.0f));

		if (ImGui::Button("START GAME"))
		{
			start_game(g_engine_type, _next_launch_mode_generic);
		}

		if (g_engine_type == _engine_type_haloreach)
		{
			if (ImGui::Button("PLAY FILM"))
			{
				start_game(g_engine_type, _next_launch_mode_theater);
			}
		}

		ImGui::Dummy(ImVec2(0.0f, 20.0f));
		if (ImGui::Button("QUIT TO DESKTOP"))
		{
			exit(0); // #TODO: Exit properly
		}

		ImGui::NextColumn();
		ImGui::Text("My Game Session");
		ImGui::Dummy(ImVec2(0.0f, 10.0f));
		// #TODO: Display session information
		//for (size_t player_index = 0; player_index < game_context->player_count; player_index++)
		//{
		//	ImGui::Text("Player xuid[%llx]", game_context.players[player_index].xbox_user_id);
		//}

		ImGui::Dummy(ImVec2(0.0f, 50.0f));
		ImGui::Text("Friends");
		ImGui::Dummy(ImVec2(0.0f, 10.0f));
		// #TODO: Display friends information

		ImGui::Columns(1);

		ImGui::End();
	}
}

void c_game_launcher::render_pause_menu()
{
	s_mouse_input->set_mode(_mouse_mode_ui);

	float width = static_cast<float>(GetSystemMetrics(SM_CXSCREEN));
	float height = static_cast<float>(GetSystemMetrics(SM_CYSCREEN));

	ImVec2 global_window_size = ImVec2(s_window->get_width_float(), s_window->get_height_float());
	ImVec2 imgui_window_size = ImVec2(global_window_size.x * 0.75f, global_window_size.y * 0.75f);
	ImVec2 imgui_window_offset = ImVec2((global_window_size.x - imgui_window_size.x) / 2.0f, (global_window_size.y - imgui_window_size.y) / 2.0f);
	ImGui::SetNextWindowSize(imgui_window_size, ImGuiCond_Always);
	ImGui::SetNextWindowPos(imgui_window_offset, ImGuiCond_Always);

	static bool is_window_open = true;
	constexpr ImGuiWindowFlags window_flags = 0
		| ImGuiWindowFlags_MenuBar
		| ImGuiWindowFlags_NoCollapse
		| ImGuiWindowFlags_NoTitleBar
		| ImGuiWindowFlags_NoMove
		| ImGuiWindowFlags_NoResize
		| ImGuiWindowFlags_NoSavedSettings;
	//| ImGuiWindowFlags_AlwaysAutoResize;

	static ImVec2 const grid_button_size = ImVec2((width / 1.5f) / 5, (height / 1.5f) / 16);

	if (!ImGui::Begin("PAUSE MENU", &is_window_open, window_flags))
	{
		// Early out if the window is collapsed, as an optimization.
		ImGui::End();
		return;
	}

	static bool isPaused = false;

	while (!isPaused && GetKeyState(VK_ESCAPE) & 0x80)
	{
		Sleep(1);
	}

	//if (s_pHaloReachEngine)
	//{
	//	if (!isPaused)
	//	{
	//		s_pHaloReachEngine->update_engine_state(_engine_state_pause);
	//		isPaused = true;
	//	}

	//	if (ImGui::Button("RETURN TO GAME", grid_button_size) || GetKeyState(VK_ESCAPE) & 0x80)
	//	{
	//		isPaused = false;
	//	}

	//	if (s_currentGameMode == GameMode::GameMode::Campaign)
	//	{
	//		if (ImGui::Button("REVERT TO LAST SAVE", grid_button_size))
	//		{
	//			s_pHaloReachEngine->update_engine_state(_engine_state_restart_checkpoint);
	//			isPaused = false;
	//		}
	//	}

	//	if (s_currentGameMode == GameMode::GameMode::Multiplayer || s_currentGameMode == GameMode::GameMode::Survival)
	//	{
	//		if (ImGui::Button("END ROUND", grid_button_size))
	//		{
	//			s_pHaloReachEngine->update_engine_state(_engine_state_round_end);
	//			isPaused = false;
	//		}
	//	}

	//	if (s_currentGameMode == GameMode::GameMode::Campaign || s_currentGameMode == GameMode::GameMode::Survival)
	//	{
	//		if (ImGui::Button("RESTART GAME", grid_button_size))
	//		{
	//			s_pHaloReachEngine->update_engine_state(_engine_state_restart_level);
	//			isPaused = false;
	//		}
	//	}

	//	if (ImGui::Button("RETURN TO MAINMENU", grid_button_size))
	//	{
	//		s_pHaloReachEngine->update_engine_state(_engine_state_game_end);
	//		isPaused = false;
	//	}

	//	if (!isPaused)
	//	{
	//		s_pHaloReachEngine->update_engine_state(_engine_state_unpause);
	//		DebugUI::UnregisterCallback(LegacyGameLauncher::DrawPauseMenu);
	//		MouseInput::SetMode(MouseMode::Exclusive);
	//		DebugUI::Hide();
	//	}
	//}

	//ImVec2 mouseSensitivity = MouseInput::GetSensitivity();
	//static float MouseSensitivityX = mouseSensitivity.x;
	//static float MouseSensitivityY = mouseSensitivity.y;

	//if (ImGui::InputFloat("Mouse Sensitivity X", &MouseSensitivityX, 0.01f, 0.1f, "%.3f"))
	//{
	//	if (MouseSensitivityX > 1.0f) MouseSensitivityX = 1.0f;
	//	if (MouseSensitivityX < 0.0f) MouseSensitivityX = 0.0f;
	//}

	//if (ImGui::InputFloat("Mouse Sensitivity Y", &MouseSensitivityY, 0.01f, 0.1f, "%.3f"))
	//{
	//	if (MouseSensitivityY > 1.0f) MouseSensitivityY = 1.0f;
	//	if (MouseSensitivityY < 0.0f) MouseSensitivityY = 0.0f;
	//}

	//if (MouseSensitivityX != mouseSensitivity.x || MouseSensitivityY != mouseSensitivity.y)
	//{
	//	MouseInput::SetSensitivity(MouseSensitivityX, MouseSensitivityY);
	//}

	ImGui::End();
}

LRESULT c_game_launcher::window_procedure(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_INPUT:
		s_mouse_input->handle_input_window_message(lParam);
		break;
	case WM_SETCURSOR:
		if (s_mouse_input->handle_cursor_window_message(lParam))
		{
			return TRUE;
		}
		break;
	}
	return 0;
}

bool c_game_launcher::load_variant_from_file(IDataAccess* data_access, GameContext* game_context, e_engine_type engine_type, e_variant_type variant_type, LPCSTR file_name)
{
	ASSERT(is_valid(game_context));
	ASSERT(is_valid(data_access));
	ASSERT(engine_type != _engine_type_not_set);
	ASSERT(is_valid(file_name));

	char* game_context_variant_buffer = nullptr;
	size_t variant_buffer_size = 0;

	std::vector<std::string> files;
	variant_files_get(engine_type, variant_type, files);

	switch (variant_type)
	{
	case _variant_type_game:
		game_context_variant_buffer = game_context->game_variant_buffer;
		variant_buffer_size = k_game_variant_buffer_size;
		break;
	case _variant_type_map:
		game_context_variant_buffer = game_context->map_variant_buffer;
		variant_buffer_size = k_map_variant_buffer_size;
		break;
	default:
		return false;
	}
	memset(game_context_variant_buffer, 0, variant_buffer_size);

	std::string selected;
	for (std::string file : files)
	{
		if (!(*file_name) || strstr(file.c_str(), file_name) == 0)
			continue;

		selected = file;
	}

	char* variant_data = nullptr;
	size_t variant_data_size = 0;

	char* variant_buffer = nullptr;

	if (selected.empty() || !PathFileExistsA(selected.c_str()) || strstr(selected.c_str(), "/.") != 0)
	{
		if (!selected.empty())
		{
			c_console::write_line_verbose("variant file '%s' does not exist, falling back to default", selected.c_str());
		}

		variant_data = new char[variant_buffer_size];
		memset(variant_data, 0, variant_buffer_size);
		switch (variant_type)
		{
		case _variant_type_game:
			variant_buffer = data_access->GameVariantCreateDefault(variant_data)->variant_buffer; // This is not correct
			break;
		case _variant_type_map:
			variant_buffer = data_access->MapVariantCreateFromMapID(game_context->map_id)->variant_buffer;
			break;
		default:
			return false;
		}

		memcpy(game_context_variant_buffer, variant_buffer, variant_buffer_size);
		delete[] variant_data;

		return true;
	}

	if (!filesystem_read_file_to_memory(selected.c_str(), reinterpret_cast<void **>(&variant_data), &variant_data_size))
	{
		c_console::write_line_verbose("Failed to open variant file");
		return false;
	}
	if (variant_data_size == 0)
	{
		c_console::write_line_verbose("Variant file was zero sized");
		return false;
	}

	switch (variant_type)
	{
	case _variant_type_game:
		variant_buffer = data_access->GameVariantCreateFromFile(variant_data, variant_data_size)->variant_buffer;
		break;
	case _variant_type_map:
		variant_buffer = data_access->MapVariantCreateFromFile(variant_data, variant_data_size)->variant_buffer;
		break;
	default:
		return false;
	}

	size_t variant_size = variant_data_size;
	variant_size = (variant_size < variant_buffer_size ? variant_size : variant_buffer_size);
	memcpy(game_context_variant_buffer, variant_buffer, variant_size);
	if (is_valid(variant_data))
	{
		delete[] variant_data;
	}

	return true;
}

bool c_game_launcher::load_save_from_file(GameContext *game_context, LPCSTR file_name, bool should_run)
{
	if (should_run)
	{
		std::string file_path = std::string("opus/autosave/").append(file_name).append(".bin");
		size_t game_state_header_size = 0;
		if (filesystem_read_file_to_memory(file_path.c_str(), &game_context->game_state_header, &game_state_header_size))
		{
			game_context->game_state_header_size = game_state_header_size;
			if (is_valid(game_context->game_state_header) && game_context->game_state_header_size > 0)
			{
				// take off the last 4 bytes from the size to exclude our added map id
				game_context->game_state_header_size -= 4;
				e_map_id map_id = *reinterpret_cast<e_map_id *>(&game_context->game_state_header[game_context->game_state_header_size]);
				game_context->game_mode = map_id_to_game_mode(map_id);
				game_context->map_id = map_id;

				return true;
			}
			return false;
		}
		return false;
	}
	return false;
};

bool c_game_launcher::variant_files_get(e_engine_type engine_type, e_variant_type variant_type, std::vector<std::string>& files)
{
	if (!is_valid(files))
		return false;

	const char* type_name = "";
	const char* type_nice_name = "";
	const char* type_extension = "";
	const char* engine_folder_name = engine_type_to_folder_name<decltype(engine_folder_name)>(engine_type);

	switch (variant_type)
	{
	case _variant_type_game:
		type_name = "game";
		type_nice_name = "GameType";
		type_extension = ".bin";
		break;
	case _variant_type_map:
		type_name = "map";
		type_nice_name = "Map";
		type_extension = ".mvar";
		break;
	default:
		return false;
	}

	LPCSTR user_profile_path = get_user_profile_environment_variable();
	std::vector<std::string> file_directories =
	{
		std::string("opus/").append(type_name).append("_variants/"),
		std::string(engine_folder_name).append("/").append(type_name).append("_variants/"),
		std::string(engine_folder_name).append("/hopper_").append(type_name).append("_variants/"),
		std::string(user_profile_path).append("/AppData/LocalLow/HaloMCC/Temporary/UserContent/").append(engine_type == _engine_type_groundhog ? "Halo2A" : engine_folder_name).append("/").append(type_nice_name).append("/"),
		std::string(user_profile_path).append("/AppData/LocalLow/MCC/Temporary/UserContent/").append(engine_type == _engine_type_groundhog ? "Halo2A" : engine_folder_name).append("/").append(type_nice_name).append("/")
	};


	for (std::string& directory : file_directories)
	{
		if (!PathFileExistsA(directory.c_str()))
			continue;

		for (const std::filesystem::directory_entry& directory_entry : std::filesystem::directory_iterator(directory))
		{
			if (directory_entry.path().extension().generic_string().compare(type_extension) != 0)
				continue;

			files.push_back(directory_entry.path().generic_string());
		}
	}

	return true;
}
