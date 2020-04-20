#include "opusframework-private-pch.h"

e_next_launch_mode g_next_launch_mode = _next_launch_mode_none;
std::vector<c_game_launcher::t_generic_game_event> c_game_launcher::s_game_startup_events;
std::vector<c_game_launcher::t_generic_game_event> c_game_launcher::s_game_shutdown_events;
bool c_game_launcher::s_is_game_running = false;
c_opus_game_engine_host* current_game_host = nullptr;
e_campaign_difficulty_level g_campaign_difficulty_level = _campaign_difficulty_level_normal; // #TODO #REFACTOR


// #TODO: #REFACTOR
static e_map_id halo1_map_ids[] =
{
	_map_id_mainmenu,
	_map_id_halo1_pillar_of_autumn,
	_map_id_halo1_halo,
	_map_id_halo1_truth_and_reconciliation,
	_map_id_halo1_silent_cartographer,
	_map_id_halo1_assault_on_the_control_room,
	_map_id_halo1_343_guilty_spark,
	_map_id_halo1_the_library,
	_map_id_halo1_two_betrayals,
	_map_id_halo1_keyes,
	_map_id_halo1_the_maw,
};
e_map_id halo1_map_id = halo1_map_ids[0];

static e_map_id halo2_map_ids[] =
{
	_map_id_halo2_coagulation,
	_map_id_mainmenu,
	//_map_id_halo2_the_heretic,
	//_map_id_halo2_the_armory,
	_map_id_halo2_cairo_station,
	//_map_id_halo2_outskirts,
	_map_id_halo2_metropolis,
	//_map_id_halo2_the_arbiter,
	_map_id_halo2_the_oracle,
	_map_id_halo2_delta_halo,
	//_map_id_halo2_regret,
	//_map_id_halo2_sacred_icon,
	_map_id_halo2_quarantine_zone,
	_map_id_halo2_gravemind,
	//_map_id_halo2_uprising,
	//_map_id_halo2_high_charity,
	//_map_id_halo2_the_great_journey,
};
e_map_id halo2_map_id = halo2_map_ids[0];

static e_map_id groundhog_map_ids[] =
{
	_map_id_groundhog_lockout,
	_map_id_groundhog_ascension,
	_map_id_groundhog_zanzibar,
	_map_id_groundhog_coagulation,
	_map_id_groundhog_warlock,
	_map_id_groundhog_sanctuary,
	_map_id_groundhog_forge_skybox01,
	_map_id_groundhog_forge_skybox02,
	_map_id_groundhog_forge_skybox03,
	_map_id_groundhog_relic,
};
e_map_id groundhog_map_id = groundhog_map_ids[0];


static std::vector<e_engine_type> g_supported_engine_types;
static e_engine_type g_engine_type = _engine_type_not_set;
static bool has_auto_started = false;
static bool k_autostart_halo_reach = false;
static bool k_autostart_halo_halo1 = false;
static bool k_autostart_halo_halo2 = false;
static bool k_autostart_halo_groundhog = false;
static bool k_autostart_halo_eldorado = false;
static bool k_autostart_halo_online = false;
static bool use_anniversary_graphics = true;
static bool use_anniversary_sounds = true;

void c_game_launcher::init_game_launcher()
{
	k_autostart_halo_reach = c_command_line::get_command_line_arg("-autostart") == "haloreach";
	k_autostart_halo_halo1 = c_command_line::get_command_line_arg("-autostart") == "halo1";
	k_autostart_halo_halo2 = c_command_line::get_command_line_arg("-autostart") == "halo2";
	k_autostart_halo_groundhog = c_command_line::get_command_line_arg("-autostart") == "groundhog";
	k_autostart_halo_eldorado = c_command_line::get_command_line_arg("-autostart") == "eldorado";
	k_autostart_halo_online = c_command_line::get_command_line_arg("-autostart") == "haloonline";

#ifdef _WIN64
	ensure_library_loaded("steam_api64.dll", "MCC\\Binaries\\Win64");
	check_steam_ownership();

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
		g_supported_engine_types.push_back(_engine_type_halo_reach);
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

	// #TODO: Attempt to restore from previously selected engine
	g_engine_type = g_supported_engine_types.empty() ? _engine_type_not_set : g_supported_engine_types.front();

	c_game_launcher::load_settings();
#ifdef _WIN64
	c_halo_reach_game_option_selection_legacy::Init();
#endif
	c_window::register_window_procedure_callback(window_procedure_callback);
	c_debug_gui::register_callback(_callback_mode_always_run, render_main_menu);
	c_debug_gui::register_callback(_callback_mode_toggleable, render_ui);

	c_window::register_destroy_callback(window_destroy_callback);

	if (!has_auto_started)
	{
		if (k_autostart_halo_reach) start_game(_engine_type_halo_reach, _next_launch_mode_generic);
		if (k_autostart_halo_halo1) start_game(_engine_type_halo1, _next_launch_mode_generic);
		if (k_autostart_halo_halo2) start_game(_engine_type_halo2, _next_launch_mode_generic);
		if (k_autostart_halo_groundhog) start_game(_engine_type_groundhog, _next_launch_mode_generic);
		if (k_autostart_halo_eldorado || k_autostart_halo_online) start_game(_engine_type_eldorado, _next_launch_mode_generic);
	}
}

void c_game_launcher::deinit_game_launcher()
{
	c_window::unregister_destroy_callback(window_destroy_callback);
	c_debug_gui::unregister_callback(_callback_mode_always_run, render_main_menu);
	c_debug_gui::unregister_callback(_callback_mode_toggleable, render_ui);
	c_window::unregister_window_procedure_callback(window_procedure_callback);
#ifdef _WIN64
	c_halo_reach_game_option_selection_legacy::deinit();
#endif
}

void c_game_launcher::window_destroy_callback()
{
	// terrible hack but lets tell the game to quit and then wait for no game to be running
	if (s_is_game_running)
	{
		IGameEngine* game_engine = current_game_host->get_game_engine();
		ASSERT(game_engine != nullptr);
		game_engine->UpdateEngineState(eEngineState::ImmediateExit);
		write_line_verbose("Waiting for game to exit...");
		while (s_is_game_running) { Sleep(1); }
	}
}

void c_game_launcher::load_settings()
{
	float horizontalSensitivity = c_settings_legacy::read_float(_settings_section_legacy_controls, "HorizontalSensitivity", 1.0f);
	float verticalSensitivity = c_settings_legacy::read_float(_settings_section_legacy_controls, "VerticalSensitivity", 1.0f);
	c_mouse_input::set_sensitivity(horizontalSensitivity, verticalSensitivity);
}


void c_game_launcher::opus_tick()
{
	if (!s_is_game_running)
	{
		update();
	}

	c_debug_gui::start_frame(); // OpusUITick is registered to the DebugUI
	//OpusUITick();
	if (c_debug_gui::is_rendering() && s_is_game_running) // render a debug layer for the game to render text to
	{
		constexpr ImGuiWindowFlags kDebugWindowFlags =
			ImGuiWindowFlags_NoMove |
			ImGuiWindowFlags_NoBackground |
			ImGuiWindowFlags_NoSavedSettings |
			ImGuiWindowFlags_NoMouseInputs |
			ImGuiWindowFlags_NoNav |
			ImGuiWindowFlags_NoDecoration |
			ImGuiWindowFlags_NoInputs;
		ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_Always);
		ImGui::SetNextWindowSize(ImVec2(static_cast<float>(c_window::get_width()), static_cast<float>(c_window::get_height())), ImGuiCond_Always);
		if (ImGui::Begin("##debug", NULL, kDebugWindowFlags)) // render inside of the dummy imgui window for on screen text display
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
		c_window::update_no_callbacks();
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
	c_mantle_gui::render_in_game_gui();
	c_primitive_render_manager::render();
}

void c_game_launcher::start_game(e_engine_type engine_type, e_next_launch_mode next_launch_mode)
{
	g_engine_type = engine_type;
	g_next_launch_mode = next_launch_mode;

#ifdef _WIN64
	c_halo_reach_game_option_selection_legacy::s_launch_saved_film_filepath = "";
#endif
	has_auto_started = true;
	g_next_launch_mode = _next_launch_mode_generic;

}

void c_game_launcher::render_ui()
{
	c_mantle_gui::render_gui();
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

	c_render::set_resize_enabled(false);
	switch (engine_type)
	{
#ifdef _WIN64
	case _engine_type_halo_reach:
	case _engine_type_halo1:
	case _engine_type_halo2:
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

	s_is_game_running = false;
}
#ifdef _WIN64
void c_game_launcher::launch_mcc_game(e_engine_type engine_type)
{
	ASSERT(current_game_host == nullptr);

	e_build build = _build_not_set;
	switch (engine_type)
	{
	case _engine_type_halo_reach:
		build = c_halo_reach_game_host::get_game_runtime().get_build();
		current_game_host = new c_halo_reach_game_host(engine_type, build);
		break;
	case _engine_type_halo1:
		build = c_halo1_game_host::get_game_runtime().get_build();
		current_game_host = new c_halo1_game_host(engine_type, build);
		break;
	case _engine_type_halo2:
		build = c_halo2_game_host::get_game_runtime().get_build();
		current_game_host = new c_halo2_game_host(engine_type, build);
		break;
	case _engine_type_groundhog:
		build = c_groundhog_game_host::get_game_runtime().get_build();
		current_game_host = new c_groundhog_game_host(engine_type, build);
		break;
	default:
		write_line_verbose(__FUNCTION__"> unknown engine_type");
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

	game_context->is_anniversary_mode = use_anniversary_graphics;
	game_context->is_anniversary_sounds = use_anniversary_sounds;

	{
		// #TODO: Make a home for this
		if (game_context->is_host)
		{
			game_context->campaign_difficulty_level = g_campaign_difficulty_level;

			if (engine_type == _engine_type_halo_reach)
			{
				const MapInfo* selected_map_info = c_halo_reach_game_option_selection_legacy::get_selected_map_info();
				e_mcc_game_mode game_mode = c_halo_reach_game_option_selection_legacy::get_selected_game_mode();

				game_context->game_mode = game_mode;
				game_context->map_id = static_cast<e_map_id>(selected_map_info->GetMapID());

				c_halo_reach_game_option_selection_legacy::load_game_variant(
					c_halo_reach_game_host::get_data_access(),
					"haloreach",
					c_halo_reach_game_option_selection_legacy::s_launch_game_variant.c_str(),
					*reinterpret_cast<s_game_variant*>(game_context->game_variant_buffer),
					true);
				c_halo_reach_game_option_selection_legacy::load_map_variant(
					c_halo_reach_game_host::get_data_access(),
					"haloreach",
					c_halo_reach_game_option_selection_legacy::s_launch_map_variant.c_str(),
					*reinterpret_cast<s_map_variant*>(game_context->map_variant_buffer),
					true);
				//c_halo_reach_game_option_selection_legacy::load_savegame("gamestate", *game_context);
				//c_halo_reach_game_option_selection_legacy::load_savefilm(c_halo_reach_game_option_selection_legacy::s_launch_saved_film_filepath.c_str(), *game_context);

				{
					// #TODO: Move this over to a IGameEngineHost callback so when a new map is loaded we load the cache file into mantle
					const char* map_file_name = selected_map_info->GetMapFileName();
					write_line_verbose("Loading map '%s.map'", map_file_name);
					{
						wchar_t map_filepath[MAX_PATH + 1] = {};
						_snwprintf(map_filepath, MAX_PATH, L"%S%S.map", "haloreach/maps/", map_file_name);
						c_mantle_gui::open_cache_file_from_filepath(map_filepath);
					}
				}
			}
			else if (engine_type == _engine_type_halo1)
			{
				if (halo1_map_id == _map_id_mainmenu)
				{
					game_context->game_mode = _mcc_game_mode_ui_shell;
				}
				else
				{
					game_context->game_mode = _mcc_game_mode_campaign;
				}

				game_context->map_id = halo1_map_id;
			}
			else if (engine_type == _engine_type_halo2)
			{
				switch (halo2_map_id)
				{
				case _map_id_mainmenu:
					game_context->game_mode = _mcc_game_mode_ui_shell;
					break;
				case _map_id_halo2_the_heretic:
				case _map_id_halo2_the_armory:
				case _map_id_halo2_cairo_station:
				case _map_id_halo2_outskirts:
				case _map_id_halo2_metropolis:
				case _map_id_halo2_the_arbiter:
				case _map_id_halo2_the_oracle:
				case _map_id_halo2_delta_halo:
				case _map_id_halo2_regret:
				case _map_id_halo2_sacred_icon:
				case _map_id_halo2_quarantine_zone:
				case _map_id_halo2_gravemind:
				case _map_id_halo2_uprising:
				case _map_id_halo2_high_charity:
				case _map_id_halo2_the_great_journey:
					game_context->game_mode = _mcc_game_mode_campaign;
					break;
				default:
					game_context->game_mode = _mcc_game_mode_multiplayer;
				}

				c_halo_reach_game_option_selection_legacy::s_launch_game_variant = "01_slayer";
				c_halo_reach_game_option_selection_legacy::load_game_variant(
					c_halo2_game_host::get_data_access(),
					"halo2",
					c_halo_reach_game_option_selection_legacy::s_launch_game_variant.c_str(),
					*reinterpret_cast<s_game_variant*>(game_context->game_variant_buffer),
					true);
				//c_halo_reach_game_option_selection_legacy::s_launch_map_variant = "Bloodline";
				//c_halo_reach_game_option_selection_legacy::load_map_variant(
				//	c_groundhog_game_host::get_data_access(),
				//	"groundhog",
				//	c_halo_reach_game_option_selection_legacy::s_launch_map_variant.c_str(),
				//	*reinterpret_cast<s_map_variant*>(game_context->map_variant_buffer),
				//	true);

				game_context->map_id = halo2_map_id;
			}
			else if (engine_type == _engine_type_groundhog)
			{
				game_context->game_mode = _mcc_game_mode_multiplayer;
				game_context->map_id = groundhog_map_id;

				c_halo_reach_game_option_selection_legacy::s_launch_game_variant = "H2A_Team_Slayer";
				c_halo_reach_game_option_selection_legacy::load_game_variant(
					c_groundhog_game_host::get_data_access(),
					"groundhog",
					c_halo_reach_game_option_selection_legacy::s_launch_game_variant.c_str(),
					*reinterpret_cast<s_game_variant*>(game_context->game_variant_buffer),
					true);
				c_halo_reach_game_option_selection_legacy::s_launch_map_variant = "Bloodline";
				c_halo_reach_game_option_selection_legacy::load_map_variant(
					c_groundhog_game_host::get_data_access(),
					"groundhog",
					c_halo_reach_game_option_selection_legacy::s_launch_map_variant.c_str(),
					*reinterpret_cast<s_map_variant*>(game_context->map_variant_buffer),
					true);

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

	game_engine->Member04(c_render::s_pDevice);
	game_engine->Member05(game_context->map_id);
	game_engine->InitGraphics(c_render::s_pDevice, c_render::s_pDeviceContext, c_render::s_swap_chain, c_render::s_swap_chain);
	game_main_thread = game_engine->InitThread(game_engine_host, game_context);

	c_window::set_post_message_thread_id(game_main_thread);

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

	write_line_verbose("Game has exited.");

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
		bool write_file_from_memory_result = write_file_from_memory("steam_appid.txt", k_steam_appid, strlen(k_steam_appid));
		ASSERT(write_file_from_memory_result == true);
	}

	bool steam_api_init_result = SteamAPI_Init();
	if (!steam_api_init_result)
	{
		MessageBox(NULL, "Fatal Error - Steam failed to initialize", "Fatal Error", MB_OK | MB_ICONWARNING);
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
		MessageBox(c_window::get_window_handle(), library_name, "failed to load library", MB_ICONERROR);
	}
	ASSERT(module_handle != NULL);
}


void c_game_launcher::render_main_menu()
{
	if (s_is_game_running) return;
	c_mouse_input::set_mode(_mouse_mode_ui);

	ImVec2 global_window_size = ImVec2(static_cast<float>(c_window::get_width()), static_cast<float>(c_window::get_height()));
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

	constexpr ImGuiWindowFlags settings_window_flags =
		ImGuiWindowFlags_NoResize |
		ImGuiWindowFlags_NoCollapse |
		ImGuiWindowFlags_AlwaysAutoResize;
	if (ImGui::Begin("Main Menu", nullptr, window_flags))
	{
		ImGui::Columns(2);
		ImGui::SetColumnOffset(1, c_window::get_width() * 0.5f);

		const char* current_engine_name = engine_type_to_nice_name(g_engine_type);
		if (ImGui::BeginCombo("Game", current_engine_name))
		{
			for (e_engine_type supported_engine_type : g_supported_engine_types)
			{
				const char* supported_engine_name = engine_type_to_nice_name(supported_engine_type);
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
		case _engine_type_halo1:

			if (ImGui::BeginCombo("Map", map_id_to_string(halo1_map_id)))
			{
				for (e_map_id map_id : halo1_map_ids)
				{
					bool is_selected = map_id == halo1_map_id;

					if (ImGui::Selectable(map_id_to_string(map_id), is_selected))
					{
						halo1_map_id = map_id;
					}
				}
				ImGui::EndCombo();
			}

			ImGui::Checkbox("Use Anniversary Graphics", &use_anniversary_graphics);
			ImGui::Checkbox("Use Anniversary Sounds", &use_anniversary_sounds);
			c_halo_reach_game_option_selection_legacy::SelectDifficulty(); // #TODO #REFACTOR
			break;
		case _engine_type_halo_reach:
			c_halo_reach_game_option_selection_legacy::Render();
			break;
		case _engine_type_halo2:
		{
			if (ImGui::BeginCombo("Map", map_id_to_string(halo2_map_id)))
			{
				for (e_map_id map_id : halo2_map_ids)
				{
					bool is_selected = map_id == halo2_map_id;

					if (ImGui::Selectable(map_id_to_string(map_id), is_selected))
					{
						halo2_map_id = map_id;
					}
				}
				ImGui::EndCombo();
			}

			ImGui::Checkbox("Use Anniversary Graphics", &use_anniversary_graphics);
			ImGui::Checkbox("Use Anniversary Sounds", &use_anniversary_sounds);
			c_halo_reach_game_option_selection_legacy::SelectDifficulty(); // #TODO #REFACTOR
		}
		break;
		case _engine_type_groundhog:
		{
			if (ImGui::BeginCombo("Map", map_id_to_string(groundhog_map_id)))
			{
				for (e_map_id map_id : groundhog_map_ids)
				{
					bool is_selected = map_id == groundhog_map_id;

					if (ImGui::Selectable(map_id_to_string(map_id), is_selected))
					{
						groundhog_map_id = map_id;
					}
				}
				ImGui::EndCombo();
			}

			c_halo_reach_game_option_selection_legacy::SelectDifficulty(); // #TODO #REFACTOR
		}
		break;

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

		if (g_engine_type == _engine_type_halo_reach)
		{
			if (ImGui::Button("PLAY FILM"))
			{
				start_game(g_engine_type, _next_launch_mode_theater);
			}
		}
		
		if (ImGui::Button("SETTINGS"))
		{
			ImGui::OpenPopup("Settings");
		}

		bool dummy_open = true;
		if (ImGui::BeginPopupModal("Settings", &dummy_open, settings_window_flags))
		{
			// initialize variables
			static int fov;
			
			static bool center_crosshair;
			static bool pancam_enabled;
			static bool allow_night_vision_in_multiplayer;
			static bool allow_ai_spawning_with_scripts_and_effects;
			static bool hs_print_is_replaced;
			static bool hs_print_to_hud;

			static float horizontalSensitivity;
			static float verticalSensitivity;

			static char service_tag_buffer[4] = {};
			static char player_name_buffer[16] = {};

			// Read Settings
			if (ImGui::IsWindowAppearing())
			{
				fov = c_settings_legacy::read_integer(_settings_section_legacy_camera, "FieldOfView", 90);
				center_crosshair = c_settings_legacy::read_boolean(_settings_section_legacy_camera, "CenteredCrosshair", true);
				
				c_settings_legacy::read_string(_settings_section_legacy_player, "ServiceTag", service_tag_buffer, 4, "117");
				c_settings_legacy::read_string(_settings_section_legacy_player, "Name", player_name_buffer, 16, "Player");
				
				pancam_enabled = c_settings_legacy::read_boolean(_settings_section_legacy_debug, "PancamEnabled", false);
				allow_night_vision_in_multiplayer = c_settings_legacy::read_boolean(_settings_section_legacy_debug, "AllowNightVisionInMultiplayer", true);
				allow_ai_spawning_with_scripts_and_effects = c_settings_legacy::read_boolean(_settings_section_legacy_debug, "SpawnAiWithScriptsAndEffects", true);
				hs_print_is_replaced = c_settings_legacy::read_boolean(_settings_section_legacy_debug, "ReplacePrintScriptEvaluate", true);
				hs_print_to_hud = c_settings_legacy::read_boolean(_settings_section_legacy_debug, "PrintToHud", false);

				horizontalSensitivity = c_settings_legacy::read_float(_settings_section_legacy_controls, "HorizontalSensitivity", 1.0f);
				verticalSensitivity = c_settings_legacy::read_float(_settings_section_legacy_controls, "VerticalSensitivity", 1.0f);
			}
			
			ImGui::Text("Camera");
			

			ImGui::InputInt("Field Of View", &fov);

		
			ImGui::Checkbox("Centered Crosshair", &center_crosshair);


			ImGui::Dummy(ImVec2(0.0f, 20.0f));

			ImGui::Text("Player");

			ImGui::InputText("Service Tag", service_tag_buffer,4);

			ImGui::InputText("Name", player_name_buffer, 16);


			ImGui::Dummy(ImVec2(0.0f, 20.0f));


			ImGui::Text("Debug");
		
			if (g_engine_type == _engine_type_halo_reach)
			{
				ImGui::Checkbox("Pancam", &pancam_enabled);

				ImGui::Checkbox("Allow night vision in multiplayer", &allow_night_vision_in_multiplayer);
				

				ImGui::Checkbox("Allow spawning ai through effects and scripts", &allow_ai_spawning_with_scripts_and_effects);
				
				ImGui::Checkbox("Replace Print Script Evaluate", &hs_print_is_replaced);

				if (hs_print_is_replaced)
				{
					ImGui::Checkbox("Print to Hud", &hs_print_to_hud);
				}

			}

			ImGui::Dummy(ImVec2(0.0f, 20.0f));

			
			ImGui::Text("Sensitivity");

			ImGui::InputFloat("Horizontal Sensitivity", &horizontalSensitivity);
			

			ImGui::InputFloat("Vertical Sensitivity", &verticalSensitivity);
			

			ImGui::Dummy(ImVec2(0.0f, 20.0f));

			if (ImGui::Button("Save Settings"))
			{
				c_settings_legacy::write_integer(_settings_section_legacy_camera, "FieldOfView", fov);
				c_settings_legacy::write_boolean(_settings_section_legacy_camera, "CenteredCrosshair", center_crosshair);
				c_settings_legacy::write_string(_settings_section_legacy_player, "ServiceTag", service_tag_buffer);
				c_settings_legacy::write_string(_settings_section_legacy_player, "Name", player_name_buffer);
				c_settings_legacy::write_boolean(_settings_section_legacy_debug, "PancamEnabled", pancam_enabled);
				c_settings_legacy::write_boolean(_settings_section_legacy_debug, "AllowNightVisionInMultiplayer", allow_night_vision_in_multiplayer);
				c_settings_legacy::write_boolean(_settings_section_legacy_debug, "SpawnAiWithScriptsAndEffects", allow_ai_spawning_with_scripts_and_effects);
				c_settings_legacy::write_boolean(_settings_section_legacy_debug, "ReplacePrintScriptEvaluate", hs_print_is_replaced);
				c_settings_legacy::write_boolean(_settings_section_legacy_debug, "PrintToHud", hs_print_to_hud);
				c_settings_legacy::write_string(_settings_section_legacy_controls, "HorizontalSensitivity", std::to_string(horizontalSensitivity).c_str());
				c_settings_legacy::write_string(_settings_section_legacy_controls, "VerticalSensitivity", std::to_string(verticalSensitivity).c_str());
				ImGui::OpenPopup("SettingsSavedDialog");
			}

			if (ImGui::BeginPopupModal("SettingsSavedDialog", NULL, settings_window_flags | ImGuiWindowFlags_NoTitleBar))
			{
				ImGui::Text("Your settings have been saved!");
				ImGui::Separator();
				
				if (ImGui::Button("OK", ImVec2(120, 0))) { ImGui::CloseCurrentPopup(); }
				ImGui::SetItemDefaultFocus();
				ImGui::SameLine();

				ImGui::EndPopup();
			}
			ImGui::EndPopup();
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
	c_mouse_input::set_mode(_mouse_mode_ui);

	float width = static_cast<float>(GetSystemMetrics(SM_CXSCREEN));
	float height = static_cast<float>(GetSystemMetrics(SM_CYSCREEN));

	ImVec2 global_window_size = ImVec2(static_cast<float>(c_window::get_width()), static_cast<float>(c_window::get_height()));
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
	//		s_pHaloReachEngine->UpdateEngineState(eEngineState::Pause);
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
	//			s_pHaloReachEngine->UpdateEngineState(eEngineState::RestartCheckpoint);
	//			isPaused = false;
	//		}
	//	}

	//	if (s_currentGameMode == GameMode::GameMode::Multiplayer || s_currentGameMode == GameMode::GameMode::Survival)
	//	{
	//		if (ImGui::Button("END ROUND", grid_button_size))
	//		{
	//			s_pHaloReachEngine->UpdateEngineState(eEngineState::EndRound);
	//			isPaused = false;
	//		}
	//	}

	//	if (s_currentGameMode == GameMode::GameMode::Campaign || s_currentGameMode == GameMode::GameMode::Survival)
	//	{
	//		if (ImGui::Button("RESTART GAME", grid_button_size))
	//		{
	//			s_pHaloReachEngine->UpdateEngineState(eEngineState::RestartLevel);
	//			isPaused = false;
	//		}
	//	}

	//	if (ImGui::Button("RETURN TO MAINMENU", grid_button_size))
	//	{
	//		s_pHaloReachEngine->UpdateEngineState(eEngineState::EndGame);
	//		isPaused = false;
	//	}

	//	if (!isPaused)
	//	{
	//		s_pHaloReachEngine->UpdateEngineState(eEngineState::Unpause);
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

LRESULT CALLBACK c_game_launcher::window_procedure_callback(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_INPUT:
		c_mouse_input::handle_input_window_message(lParam);
		break;
	case WM_SETCURSOR:
		if (c_mouse_input::handle_cursor_window_message(lParam))
		{
			return TRUE;
		}
		break;
	}
	return 0;
}
