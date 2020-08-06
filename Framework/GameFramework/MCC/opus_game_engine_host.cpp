#include "gameframework-private-pch.h"

#define sign(value) (value < 0 ? -1 : 1)
#define clamp(value, min_value, max_value) ((value) > (max_value) ? (max_value) : ((value) < (min_value) ? (min_value) : (value)))
#define CONTROLLER_JOYSTICK_THRESHOLD 0.15f

c_opus_game_engine_host::c_opus_game_engine_host(e_engine_type engine_type, e_build build, c_game_runtime& rGameRuntime) :
	IGameEngineHost(engine_type, build, &game_events),
	game_engine(nullptr),
	window(*c_game_launcher::get_window()),
	mouse_input(*c_game_launcher::get_mouse_input()),
	game_runtime(rGameRuntime),
	game_events(),
	frame_timer(),
	total_frame_cpu_time(0.0)
{
	const wchar_t* engine_string = get_enum_string<decltype(engine_string), true>(engine_type);
	const wchar_t* build_string = build_to_string<decltype(build_string), true>(engine_type, build); //#TODO: MCC product version to string to snag build numbers we don't know about
	const wchar_t* build_configuration = build_configuration_string<decltype(build_configuration), true>();

	std::wstring window_title = engine_string;
	window_title.append(L" : ");
	window_title.append(build_string);
	window_title.append(L" ");
	window_title.append(build_configuration);
	window.set_title(window_title.c_str()); // #TODO: Replace with push/pop
}

c_opus_game_engine_host::~c_opus_game_engine_host()
{
	window.set_title(L"Opus");
}

char c_opus_game_engine_host::frame_begin()
{
	return 0;
}

void c_opus_game_engine_host::frame_end(IDXGISwapChain* swap_chain, _QWORD)
{
	frame_timer.stop();
	double frame_cpu_duration = frame_timer.get_duration<double>();
	total_frame_cpu_time += frame_cpu_duration;
	frame_timer.start();

	static const bool k_quit_after_30_seconds_test = c_command_line::get_command_line_arg("-test") == "quit_after_30_seconds";
	if (k_quit_after_30_seconds_test && total_frame_cpu_time > 30.0f)
	{
		if (game_engine)
		{
			game_engine->update_engine_state(_engine_state_game_end);
		}
	}

	c_game_launcher::opus_tick();
}

void c_opus_game_engine_host::function02(__int64 player_identifier, unsigned int, __int64, float, float, float, float)
{
}

void c_opus_game_engine_host::engine_state_update_handler(e_engine_state state)
{
	/* LEGACY_REFACTOR
	const char* pEngineStateString = engine_state_to_string(state);
	c_console::write_line_verbose("%s (%d):%s", __FUNCTION__, state, pEngineStateString);

	if (state != _engine_state_unknown16) // `Unknown16` also needs a second arg so we skip it
	{
		switch (state)
		{
		case _engine_state_push_ui_page:
			c_console::write_line_verbose("Push UI stack");
			LegacyGameLauncher::s_uiStackLength++;
			break;
		case _engine_state_pop_ui_page:
			c_console::write_line_verbose("Pop UI stack");
			LegacyGameLauncher::s_uiStackLength--;
			break;
		}

		LegacyGameLauncher::s_pHaloReachEngine->update_engine_state(state);
	}
	*/
}

__int64 c_opus_game_engine_host::game_shutdown_handler(unsigned int a1, char* a2, int a3)
{
	/* LEGACY_REFACTOR
	LegacyGameLauncher::s_currentState = LegacyGameLauncher::CurrentState::eFinished;
	*/

	if (IsBadReadPtr(a2, 1)) // #LEGACY
	{
		c_console::write_line_verbose("%s %u [%p]", __func__, a1, a2);
	}
	else
	{
		c_console::write_line_verbose("%s %u [%s]", __func__, a1, a2);
	}

	c_game_launcher::game_exited_callback();

	return __int64(0);
}

extern e_map_id g_halo1_map_id;
extern e_map_id g_halo2_map_id;
extern e_map_id g_halo3_map_id;
extern e_map_id g_halo4_map_id;
extern e_map_id g_halo3odst_map_id;

__int64 __fastcall c_opus_game_engine_host::game_save_handler(LPVOID buffer, size_t buffer_size)
{
	if (buffer == nullptr || buffer_size == 0)
	{
		return __int64(0);
	}
	//c_console::write_line_verbose("%s %p %016zx", __FUNCTION__, buffer, buffer_size);

	static e_engine_type last_engine_type = _engine_type_not_set;
	static e_map_id map_id = _map_id_none;
	static const wchar_t* engine_name = engine_type_to_folder_name<decltype(engine_name)>(engine_type);
	if (last_engine_type == _engine_type_not_set || last_engine_type != engine_type)
	{
		// TODO: add support for halo reach
		switch (engine_type)
		{
		//case _engine_type_haloreach:
		//	map_id = haloreach_map_id;
		//	engine_name = L"haloreach";
		//	break;
		case _engine_type_halo1:
			map_id = g_halo1_map_id;
			break;
		case _engine_type_halo2:
			map_id = g_halo2_map_id;
			break;
		case _engine_type_halo3:
			map_id = g_halo3_map_id;
			break;
		case _engine_type_halo3odst:
			map_id = g_halo3odst_map_id;
			break;
		case _engine_type_halo4:
			map_id = g_halo4_map_id;
			break;
		default:
			return __int64(0);
		}
	}

	static wchar_t autosave_path[MAX_PATH + 1] = L"opus/autosave/";
	{
		time_t now;
		time(&now);
		_snwprintf(autosave_path, MAX_PATH, L"opus/autosave/%08llX.%s.bin", now, engine_name);
	}

	bool result = false;

	// create a new buffer with space for the engine save buffer + our map id
	{
		static char *autosave_buffer = nullptr;
		size_t autosave_buffer_size = buffer_size + 4;

		autosave_buffer = new char[autosave_buffer_size];
		memset(autosave_buffer, 0, autosave_buffer_size);

		memcpy(autosave_buffer, buffer, buffer_size);
		*reinterpret_cast<int *>(&autosave_buffer[buffer_size]) = map_id;

		result = filesystem_write_file_from_memory(autosave_path, autosave_buffer, autosave_buffer_size);
		delete[] autosave_buffer;
	}

	c_console::write_line_verbose("autosave written to %S [%S]", autosave_path, (result ? L"success" : L"failure"));

	return __int64(0);
}

void c_opus_game_engine_host::game_results_submission_handler(s_game_results* game_results_data)
{
}

void c_opus_game_engine_host::game_pause_handler(unsigned int)
{
	/* LEGACY_REFACTOR
	if (LegacyGameLauncher::s_uiStackLength == 0)
	{
		c_console::write_line_verbose("IOpusGameEngineHost::Member07 PauseMenuOpened");
		DebugUI::RegisterCallback(LegacyGameLauncher::DrawPauseMenu);
		DebugUI::Show();
	}
	else
	{
		c_console::write_line_verbose("IOpusGameEngineHost::Member07 UI Stack is %i", static_cast<int>(LegacyGameLauncher::s_uiStackLength));
	}
	*/
}

void c_opus_game_engine_host::function08(const wchar_t*, const wchar_t*)
{
}

void c_opus_game_engine_host::Function09(wchar_t[1024], wchar_t[1024])
{
}

IGameEvents* c_opus_game_engine_host::game_events_get()
{
	return &game_events;
}

bool save_variant_to_file(IVariantAccessorBase* variant, e_variant_type variant_type, const wchar_t* file_name, const wchar_t* name, const wchar_t* description)
{
	ASSERT(is_valid(variant));
	ASSERT(is_valid(file_name));
	ASSERT(is_valid(name));
	ASSERT(is_valid(description));

	variant->SetName(name);
	variant->SetDescription(description);

	const wchar_t* variant_directory = L"";
	const wchar_t* variant_extension = L"";

	switch (variant_type)
	{
	case _variant_type_game:
		variant_directory = L"opus/game_variants/";
		variant_extension = L".bin";
		break;
	case _variant_type_map:
		variant_directory = L"opus/map_variants/";
		variant_extension = L".mvar";
		break;
	default:
		return false;
	}

	{
		void *variant_buffer = 0;
		size_t variant_buffer_size = 0;
		if (variant->CreateFileFromBuffer(&variant_buffer, &variant_buffer_size))
		{
			wchar_t variant_path[MAX_PATH + 1] = {};
			_snwprintf_s(variant_path, MAX_PATH, L"%s%s%s", variant_directory, file_name, variant_extension);

			return filesystem_write_file_from_memory(variant_path, variant_buffer, variant_buffer_size);
		}
	}

	return false;
}

void c_opus_game_engine_host::game_variant_save_handler(IGameVariant* game_variant)
{
	const wchar_t* file_name   = L"temp";
	const wchar_t* name	       = L"Temp test gvar";
	const wchar_t* description = L"This is a temporary test game variant for testing writing to file.";
	switch (engine_type)
	{
	case _engine_type_haloreach:
		file_name = L"temp.haloreach";
		break;
	case _engine_type_halo1:
		file_name = L"temp.halo1";
		break;
	case _engine_type_halo2:
		file_name = L"temp.halo2";
		break;
	case _engine_type_groundhog:
		file_name = L"temp.groundhog";
		break;
	default:
		return;
	}

	// TODO: add user input for `file_name`, `name`, and `description`
	save_variant_to_file(game_variant, _variant_type_game, file_name, name, description);
}

void c_opus_game_engine_host::map_variant_save_handler(IMapVariant* map_variant)
{
	const wchar_t* file_name   = L"temp";
	const wchar_t* name	       = L"Temp test mvar";
	const wchar_t* description = L"This is a temporary test map variant for testing writing to file.";
	switch (engine_type)
	{
	case _engine_type_haloreach:
		file_name = L"temp.haloreach";
		break;
	case _engine_type_halo1:
		file_name = L"temp.halo1";
		break;
	case _engine_type_halo2:
		file_name = L"temp.halo2";
		break;
	case _engine_type_groundhog:
		file_name = L"temp.groundhog";
		break;
	default:
		return;
	}

	// TODO: add user input for `file_name`, `name`, and `description`
	save_variant_to_file(map_variant, _variant_type_map, file_name, name, description);
}

void c_opus_game_engine_host::function13(const wchar_t*, const wchar_t*, const void*, unsigned int)
{
}

char c_opus_game_engine_host::controller_inverted_look_update_handler(int controller_index, bool inverted)
{
	static c_player_configuration* player_configuration = nullptr;
	if (PlayerConfigurationFromBuild(build, &player_configuration))
	{
		ConfigurePlayerConfiguration(*player_configuration);

		player_configuration->LookControlsInverted = inverted;
		player_configuration->MouseLookControlsInverted = inverted;
	}

	return 1;
}

char c_opus_game_engine_host::game_specific_bindings_get(int controller_index, char(*buffer)[256])
{
	static c_player_configuration* player_configuration = nullptr;
	if (PlayerConfigurationFromBuild(build, &player_configuration))
	{
		ConfigurePlayerConfiguration(*player_configuration);
		memcpy(&player_configuration->GameSpecific, buffer, 256);
	}

	return 1;
}

char c_opus_game_engine_host::next_mission_info_get(e_map_id* map_id, int* campaign_insertion_point, FILETIME* file_time, _DWORD*)
{
	return 0;
}

bool c_opus_game_engine_host::function17(int)
{
	return false;
}

void c_opus_game_engine_host::function18(int)
{
}

__int64 __fastcall c_opus_game_engine_host::engine_load_status_handler(__int64, __int64, float)
{
	return __int64(0);
}

void c_opus_game_engine_host::function20(__int64, __int8)
{
}

__int64 __fastcall c_opus_game_engine_host::local_machine_identifier_get(_QWORD)
{
	return __int64(3);
}

__int64 c_opus_game_engine_host::function22(s_function22_data* buffer, __int64)
{
	memset(buffer, 0, sizeof(*buffer)); // fix a crash when alt-tabbing in Groundhog
	return __int64(0);
}

char c_opus_game_engine_host::function23(__int64, __int64)
{
	return 1;
}

void c_opus_game_engine_host::session_info_get(s_session_info_part* session_info_part)
{

}

void __fastcall c_opus_game_engine_host::session_membership_update_handler(s_session_membership* session_membership, uint32_t player_count)
{
	RUNONCE({ c_console::write_line_verbose(__FUNCTION__); });
}

bool __fastcall c_opus_game_engine_host::function26()
{
	RUNONCE({ c_console::write_line_verbose(__FUNCTION__); });
	return false;
}

bool __fastcall c_opus_game_engine_host::function27()
{
	RUNONCE({ c_console::write_line_verbose(__FUNCTION__); });
	return false;
}

bool __fastcall c_opus_game_engine_host::video_settings_update_handler(VideoSettings* video_settings)
{
	DEBUG_ASSERT(video_settings != nullptr);

	video_settings->GeneralSettings.DesiredScreenWidth = static_cast<int>(window.get_width_integer());
	video_settings->GeneralSettings.DesiredScreenHeight = static_cast<int>(window.get_height_integer());

	// 2 is the maximum quality option any of the engines will let you set without patching them to accept a higher value
	video_settings->GeneralSettings.TextureResolution = 2;
	video_settings->GeneralSettings.TextureFilteringQuality = 2;
	video_settings->GeneralSettings.LightingQuality = 2;
	video_settings->GeneralSettings.EffectsQuality = 2;
	video_settings->GeneralSettings.ShadowQuality = 2;
	video_settings->GeneralSettings.DetailsQuality = 2;
	video_settings->GeneralSettings.PostProcessingQuality = 2;
	video_settings->GeneralSettings.AntiAliasing = true;

	// UNLIMITED POWER! *frames*
	video_settings->GeneralSettings.VSync = false;
	video_settings->GeneralSettings.FPSLock = false;
	
	// the values set are taken from `AppData\LocalLow\MCC\Saved\Config\WindowsNoEditor\GameUserSettings.ini` for "Enhanced Mode",
	// these values are overrides for the `globals\default.performance_throttles` tag
	video_settings->PerformanceThrottles.WaterLod = { 1.0f, 0.0f };
	video_settings->PerformanceThrottles.DecoratorFadeDistance = { 3.0f, 0.0f };
	video_settings->PerformanceThrottles.EffectsLODDistanceScale = { 3.0f, 0.0f };
	video_settings->PerformanceThrottles.InstanceFadeModifier = { 3.0f, 0.0f };
	video_settings->PerformanceThrottles.ObjectFadeModifer = { 3.0f, 0.0f };
	video_settings->PerformanceThrottles.ObjectDetailModifer = { 3.0f, 0.0f };
	video_settings->PerformanceThrottles.ObjectImposterCutoffModifer = { 3.0f, 0.0f };
	video_settings->PerformanceThrottles.DecalFadeDistanceScale = { 3.0f, 0.0f };
	video_settings->PerformanceThrottles.StructureInstanceLODModifer = { 3.0f, 0.0f };
	video_settings->PerformanceThrottles.CPUDynamicLightMaxCount = { 3.0f, 0.0f };
	video_settings->PerformanceThrottles.CPUDynamicLightScale = { 3.0f, 0.0f };
	video_settings->PerformanceThrottles.GPUDynamicLightMaxCount = { 3.0f, 0.0f };
	video_settings->PerformanceThrottles.GPUDynamicLightScale = { 3.0f, 0.0f };
	video_settings->PerformanceThrottles.ScreenspaceDynamicLightMaxCount = { 3.0f, 0.0f };
	video_settings->PerformanceThrottles.ScreenspaceDynamicLightScale = { 3.0f, 0.0f };
	video_settings->PerformanceThrottles.ShadowGenerateCount = { 3.0f, 0.0f };
	video_settings->PerformanceThrottles.ShadowQualityLOD = { 3.0f, 0.0f };
	video_settings->PerformanceThrottles.DisableObjectPRT = false;
	video_settings->PerformanceThrottles.DisableFirstPersonShadow = false;
	video_settings->PerformanceThrottles.DisableDynamicLightingShadows = false;
	video_settings->PerformanceThrottles.DisablePatchyFog = false;
	video_settings->PerformanceThrottles.DisableCheapParticles = false;
	video_settings->PerformanceThrottles.DisableSSAO = false;
	video_settings->PerformanceThrottles.DisableCHUDTurbulence = false;
	video_settings->PerformanceThrottles.DisableDecoratorTypeInstances = false;
	video_settings->PerformanceThrottles.DisableRain = false;

	c_console::write_line_verbose(__FUNCTION__);

	// returning false effectively doubles fps when unlocked
	return !(video_settings->GeneralSettings.VSync || video_settings->GeneralSettings.FPSLock);
}

c_player_configuration* __fastcall c_opus_game_engine_host::player_configuration_get(__int64 value)
{
	RUNONCE({ c_console::write_line_verbose(__FUNCTION__); });

	static c_player_configuration *player_configuration = nullptr;
	if (PlayerConfigurationFromBuild(build, &player_configuration))
	{
		ConfigurePlayerConfiguration(*player_configuration);
	}

	return player_configuration;
}

BYTE keyboardState[256] = {};

__int64 __fastcall c_opus_game_engine_host::player_configuration_update_handler(wchar_t player_names[4][16], c_player_configuration* player_configuration)
{
	// #TODO #LEGACY: The format for player_configuration_update_handler changed sometime after 887
	if (build <= _build_mcc_1_887_0_0 || !is_valid(player_configuration))
	{
		return false; // skips a large chunk of code that crashes out because the format changed
	}

	if (PlayerConfigurationFromBuild(build, &player_configuration))
	{
		ConfigurePlayerConfiguration(*player_configuration);
	}

	//WriteStackBackTrace("IOpusGameEngineHost::player_configuration_update_handler");
	return __int64(1);
}

bool __fastcall c_opus_game_engine_host::input_update_handler(_QWORD a1, InputBuffer* input_buffer)
{
	ASSERT(input_buffer);
	memset(input_buffer, 0, sizeof(*input_buffer));

	static const bool k_has_input_debug = c_command_line::has_command_line_arg("-inputdebug");
	if (k_has_input_debug)
	{
		c_console::write_line_verbose("%llu", a1);
	}

	bool is_debug_ui_visible = c_debug_gui::IsVisible();
	bool is_window_focused = window.is_focused();

	e_mouse_mode mode = _mouse_mode_none;
	if (is_window_focused)
	{
		mode = is_debug_ui_visible ? _mouse_mode_ui : _mouse_mode_exclusive;
	}
	mouse_input.set_mode(mode);

	// don't update and return an empty zero buffer
	if (is_debug_ui_visible)
	{
		input_buffer->inputSource = InputSource::MouseAndKeyboard;
		return unsigned __int8(1);
	}

	static InputSource s_current_input_source = InputSource::MouseAndKeyboard;

	// grab controller
	// grab mouse and keyboard

	float mouse_input_x = 0;
	float mouse_input_y = 0;
	bool left_button_pressed = 0;
	bool right_button_pressed = 0;
	bool middle_button_pressed = 0;

	bool hasControllerInput = false;
	bool has_mouse_and_keyboard_input = false;

	float fThumbLX = 0;
	float fThumbLY = 0;
	float fThumbRX = 0;
	float fThumbRY = 0;
	float fThumbL_Length = 0;
	float fThumbR_Length = 0;
	XINPUT_STATE xinputState = {};

	if (is_window_focused || true)
	{
		DWORD xinputGetStateResult = XInputGetState(0, &xinputState);
		if (xinputGetStateResult == ERROR_SUCCESS)
		{
			hasControllerInput |= xinputState.Gamepad.wButtons != 0;
			hasControllerInput |= xinputState.Gamepad.bLeftTrigger != 0;
			hasControllerInput |= xinputState.Gamepad.bRightTrigger != 0;

			fThumbLX = static_cast<float>(static_cast<short>(xinputState.Gamepad.sThumbLX));
			fThumbLY = static_cast<float>(static_cast<short>(xinputState.Gamepad.sThumbLY));
			fThumbRX = static_cast<float>(static_cast<short>(xinputState.Gamepad.sThumbRX));
			fThumbRY = static_cast<float>(static_cast<short>(xinputState.Gamepad.sThumbRY));

			fThumbLX /= static_cast<float>(fThumbLX > 0.0f ? INT16_MAX : -INT16_MIN);
			fThumbLY /= static_cast<float>(fThumbLY > 0.0f ? INT16_MAX : -INT16_MIN);
			fThumbRX /= static_cast<float>(fThumbRX > 0.0f ? INT16_MAX : -INT16_MIN);
			fThumbRY /= static_cast<float>(fThumbRY > 0.0f ? INT16_MAX : -INT16_MIN);

			fThumbL_Length = sqrtf(fThumbLX * fThumbLX + fThumbLY * fThumbLY);
			fThumbR_Length = sqrtf(fThumbRX * fThumbRX + fThumbRY * fThumbRY);

			fThumbLX = sign(fThumbLX) * clamp(abs(fThumbLX) - CONTROLLER_JOYSTICK_THRESHOLD, 0.0f, 1.0f - CONTROLLER_JOYSTICK_THRESHOLD) / (1.0f - CONTROLLER_JOYSTICK_THRESHOLD);
			fThumbLY = sign(fThumbLY) * clamp(abs(fThumbLY) - CONTROLLER_JOYSTICK_THRESHOLD, 0.0f, 1.0f - CONTROLLER_JOYSTICK_THRESHOLD) / (1.0f - CONTROLLER_JOYSTICK_THRESHOLD);
			fThumbRX = sign(fThumbRX) * clamp(abs(fThumbRX) - CONTROLLER_JOYSTICK_THRESHOLD, 0.0f, 1.0f - CONTROLLER_JOYSTICK_THRESHOLD) / (1.0f - CONTROLLER_JOYSTICK_THRESHOLD);
			fThumbRY = sign(fThumbRY) * clamp(abs(fThumbRY) - CONTROLLER_JOYSTICK_THRESHOLD, 0.0f, 1.0f - CONTROLLER_JOYSTICK_THRESHOLD) / (1.0f - CONTROLLER_JOYSTICK_THRESHOLD);

			hasControllerInput |= fThumbL_Length > CONTROLLER_JOYSTICK_THRESHOLD;
			hasControllerInput |= fThumbR_Length > CONTROLLER_JOYSTICK_THRESHOLD;
		}

		{
			GetKeyState(-1); // force keys to update
			if (!GetKeyboardState(keyboardState))
				ZeroMemory(keyboardState, sizeof(keyboardState));

			mouse_input_x = mouse_input.get_mouse_x();
			mouse_input_y = mouse_input.get_mouse_y();

			left_button_pressed = mouse_input.get_mouse_button(_mouse_input_button_left);
			right_button_pressed = mouse_input.get_mouse_button(_mouse_input_button_right);
			middle_button_pressed = mouse_input.get_mouse_button(_mouse_input_button_middle);

			{
				//for (size_t i = 0; i < sizeof(keyboardState); i++)
				//	has_mouse_and_keyboard_input |= keyboardState[i] != 0;

				has_mouse_and_keyboard_input |= mouse_input_x != 0.0f;
				has_mouse_and_keyboard_input |= mouse_input_y != 0.0f;
				has_mouse_and_keyboard_input |= left_button_pressed;
				has_mouse_and_keyboard_input |= right_button_pressed;
				has_mouse_and_keyboard_input |= middle_button_pressed;

				for (int i = 32; i < 128; i++)
				{
					has_mouse_and_keyboard_input |= (keyboardState[i] & 0b10000000) != 0;
				}

				if (has_mouse_and_keyboard_input)
				{
					s_current_input_source = InputSource::MouseAndKeyboard;
				}
			}

			if (k_has_input_debug)
			{
				c_console::write_line_verbose("%f %f", mouse_input_x, mouse_input_y);
			}
		}
	}

	if (hasControllerInput)
	{
		s_current_input_source = InputSource::Gamepad;
	}
	else if (has_mouse_and_keyboard_input)
	{
		s_current_input_source = InputSource::MouseAndKeyboard;
	}

	if (s_current_input_source == InputSource::MouseAndKeyboard)
	{
		for (int i = 0; i < 256; i++)
		{
			input_buffer->keyboardState[i] = (keyboardState[i] & 0b10000000) != 0;
		}
		input_buffer->MouseX += mouse_input_x;
		input_buffer->MouseY += mouse_input_y;
		input_buffer->mouseButtonBits |= BYTE(left_button_pressed) << 0;
		input_buffer->mouseButtonBits |= BYTE(middle_button_pressed) << 1;
		input_buffer->mouseButtonBits |= BYTE(right_button_pressed) << 2;
	}

	if (s_current_input_source == InputSource::Gamepad)
	{
		input_buffer->wButtons = xinputState.Gamepad.wButtons;
		input_buffer->bLeftTrigger = xinputState.Gamepad.bLeftTrigger;
		input_buffer->bRightTrigger = xinputState.Gamepad.bRightTrigger;
		input_buffer->sThumbLX = fThumbLX * static_cast<float>(fThumbLX > 0 ? INT16_MAX : -INT16_MIN);
		input_buffer->sThumbLY = fThumbLY * static_cast<float>(fThumbLY > 0 ? INT16_MAX : -INT16_MIN);
		input_buffer->sThumbRX = fThumbRX * static_cast<float>(fThumbRX > 0 ? INT16_MAX : -INT16_MIN);
		input_buffer->sThumbRY = fThumbRY * static_cast<float>(fThumbRY > 0 ? INT16_MAX : -INT16_MIN);
	}

	input_buffer->inputSource = s_current_input_source;

	return unsigned __int8(1);
}

void c_opus_game_engine_host::function32(_QWORD, float* a2)
{
	*a2 = 0.f; // why are we doing this?
	// spams if fps is unlocked
}

void c_opus_game_engine_host::function33()
{
	// appears to be usermanagement related?
	// we haven't seen this fire yet and don't know its structure so throw an error
	throw;
}

void c_opus_game_engine_host::xinput_set_state_handler(DWORD user_index, XINPUT_VIBRATION* xinput_vibration)
{
	::XInputSetState(user_index, xinput_vibration);
}

bool __fastcall c_opus_game_engine_host::player_name_update_handler(__int64*, wchar_t player_names[4][16], size_t data_size)
{
	if (player_names == nullptr || data_size == 0)
	{
		return false;
	}

	size_t num_players = data_size / 32;

	constexpr size_t player_name_max_len = _countof(player_names[0]);
	constexpr size_t player_name_max_index = player_name_max_len - 1;

	for (uint32_t player_index = 0; player_index < __min(num_players, 4u); player_index++)
	{
		const wchar_t* ppNames[] = { L"Player", L"Player2", L"Player3",L"Player4" };
		const wchar_t* pName = ppNames[player_index];

		if (player_index == 0) // #TODO: Proper player class for interface!
		{
			static wchar_t player_name_configuration[16] = {};
			static bool initialized_player_name = false;
			if (!initialized_player_name)
			{
				c_settings::read_wstring(_settings_section_player, "Name", player_name_configuration, sizeof(player_name_configuration), pName);
				initialized_player_name = true;
			}
			if (player_name_configuration[0])
			{
				pName = player_name_configuration;
			}
		}

		if (wcsncmp(player_names[player_index], pName, _countof(player_names[player_index])) == 0)
		{
			return true;
		}
		wcsncpy(player_names[player_index], pName, __min(wcslen(pName) + 1, player_name_max_len));
		player_names[player_index][player_name_max_index] = 0;
		c_console::write_line_verbose("player[%d].Name: set %ls", player_index, pName);
	}

	return true;
}

void __fastcall c_opus_game_engine_host::function36(const wchar_t*, const wchar_t*)
{
}

bool __fastcall c_opus_game_engine_host::function37(wchar_t*, __int64)
{
	return 0;
}

__int64 __fastcall c_opus_game_engine_host::network_sendto_handler(NetworkID network_id, char* buffer, uint32_t buffer_size, int)
{
	if (buffer)
	{
		debug_point;
	}
	return 0;
}

__int64 __fastcall c_opus_game_engine_host::network_recvfrom_handler(char* buffer, uint32_t buffer_size, __int64, s_transport_address* pTransportAddress)
{
	if (buffer)
	{
		debug_point;
	}
	return 0;
}

char* __fastcall c_opus_game_engine_host::function40(unsigned int)
{
	return 0;
}

int __fastcall c_opus_game_engine_host::function41(BYTE* buffer)
{
	return 0;
}

bool __fastcall c_opus_game_engine_host::function42(signed int, __int64, __int64)
{
	return 0;
}

void __fastcall c_opus_game_engine_host::firefight_new_handler(__int64, float)
{
}

BOOL __fastcall c_opus_game_engine_host::function44(__int64, __int64)
{
	return 0;
}

bool __fastcall c_opus_game_engine_host::path_by_type_get(PathType path_type, LPSTR buffer, size_t buffer_length)
{
	const char* pEngineName = game_runtime.get_engine_name().c_str();

	// this implementation is inline with MCC
	switch (path_type)
	{
	case PathType::DebugLogs:
		sprintf_s(buffer, buffer_length, "opus/%s/DebugLogs/", pEngineName);
		return true;
	case PathType::Config:
		sprintf_s(buffer, buffer_length, "opus/%s/Config/", pEngineName);
		return true;
	case PathType::Temporary:
		sprintf_s(buffer, buffer_length, "opus/%s/Temporary/", pEngineName);
		return true;
	case PathType::Root:
		sprintf_s(buffer, buffer_length, "opus/%s/", pEngineName);
		return true;
	}

	return false;
}

bool __fastcall c_opus_game_engine_host::wide_path_by_type_get(PathType path_type, wchar_t* buffer, size_t buffer_length)
{
	const char* pEngineName = game_runtime.get_engine_name().c_str();

	// this implementation is inline with MCC
	switch (path_type)
	{
	case PathType::DebugLogs:
		swprintf(buffer, buffer_length, L"opus/%S/DebugLogs/", pEngineName);
		return true;
	case PathType::Config:
		swprintf(buffer, buffer_length, L"opus/%S/Config/", pEngineName);
		return true;
	case PathType::Temporary:
		swprintf(buffer, buffer_length, L"opus/%S/Temporary/", pEngineName);
		return true;
	case PathType::Root:
		swprintf(buffer, buffer_length, L"opus/%S/", pEngineName);
		return true;
	}

	return false;
}

unsigned __int8* __fastcall c_opus_game_engine_host::function47(_QWORD, unsigned __int8*, _QWORD)
{
	return 0;
}

__int64 __fastcall c_opus_game_engine_host::function48(_QWORD, __int64)
{
	// appears to be security related
	return 1;
}

char* __fastcall c_opus_game_engine_host::function49(char* str)
{
	return str;
}

__int64 __fastcall c_opus_game_engine_host::function58()
{
	return 0;
}

__int64 __fastcall c_opus_game_engine_host::function59(__int64 a1, unsigned int a2)
{
	// appears to be skins related
	return 0;
}

__int64 __fastcall c_opus_game_engine_host::function60(__int64 a1)
{
	return 0;
}

void __fastcall c_opus_game_engine_host::function61(__int64 a1)
{
}