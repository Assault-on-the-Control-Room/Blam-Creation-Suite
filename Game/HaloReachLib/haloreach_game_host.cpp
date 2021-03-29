#include "haloreachlib-private-pch.h"

extern void init_haloreach(e_engine_type engine_type, e_build build);
extern void deinit_haloreach(e_engine_type engine_type, e_build build);

/* ---------- private constants */
/* ---------- private macros */
/* ---------- private types */
/* ---------- private classes */
/* ---------- globals */

static bool g_is_reach_script_debug_window_open = true;
static bool g_is_reach_camera_debug_window_open = true;
c_game_runtime c_haloreach_game_host::g_haloreach_game_runtime(_engine_type_haloreach, "haloreach", "HaloReach\\haloreach.dll");
static c_haloreach_engine_state_command *g_haloreach_engine_state_command;
static c_haloreach_camera_command* g_haloreach_camera_command;
c_haloreach_game_host* c_haloreach_game_host::current_host = nullptr;

/* ---------- private prototypes */
/* ---------- public code */

#include "haloreach_game_host.camera.inl"
#include "haloreach_game_host.mainmenu.inl"
#include "haloreach_game_host.memory.inl"
#include "haloreach_game_host.shell.inl"
#include "haloreach_game_host.scripting.inl"
#include "haloreach_game_host.legacy.inl"
#include "haloreach_game_host.testing.inl"

void register_haloreachlib()
{

}

c_haloreach_game_host::c_haloreach_game_host(e_engine_type engine_type, e_build build) :
	c_aotus_game_engine_host(engine_type, build, g_haloreach_game_runtime)
{
	current_host = this;

	c_console::write_line_verbose("Init %s", __func__);

	init_runtime_modifications(g_haloreach_game_runtime.get_build());

	if (g_haloreach_engine_state_command != nullptr)
	{
		g_haloreach_engine_state_command->set_game_engine(get_game_engine());
	}

	if (g_haloreach_camera_command != nullptr)
	{
		g_haloreach_camera_command->read_config();
	}

	c_mandrill_user_interface::set_get_tag_section_address_callback(haloreach_tag_address_get); // #TODO: This is kinda hacky
	c_mandrill_user_interface::set_get_tag_game_memory_callback(haloreach_tag_definition_get); // #TODO: This is kinda hacky
}

c_haloreach_game_host::~c_haloreach_game_host()
{
	c_console::write_line_verbose("Deinit %s", __func__);

	c_mandrill_user_interface::set_get_tag_section_address_callback(nullptr); // #TODO: This is kinda hacky
	c_mandrill_user_interface::set_get_tag_game_memory_callback(nullptr); // #TODO: This is kinda hacky

	//game_engine->Destructor();
	//free(halo_reach_engine);
	//free(halo_reach_data_access);

	//game_engine = nullptr;

	deinit_runtime_modifications(g_haloreach_game_runtime.get_build());
	g_haloreach_game_runtime.~c_game_runtime();
	new(&g_haloreach_game_runtime) c_game_runtime(_engine_type_haloreach, "haloreach", "HaloReach\\haloreach.dll");

	current_host = nullptr;
}

void c_haloreach_game_host::frame_end(IDXGISwapChain* swap_chain, _QWORD unknown1)
{
	if (GetAsyncKeyState(VK_F10))
	{
		get_game_engine()->EngineStateUpdate(_engine_state_game_end);
	}

	update_camera_data();
	c_aotus_game_engine_host::frame_end(swap_chain, unknown1);
}

void c_haloreach_game_host::render_ui() const
{
	draw_camera_debug_ui();
	draw_script_debug_ui();
}

void c_haloreach_game_host::init_runtime_modifications(e_build build)
{
	g_haloreach_engine_state_command = new c_haloreach_engine_state_command();
	g_haloreach_camera_command = new c_haloreach_camera_command();

	//haloreach_player_mapping_get_local_player
	haloreach_spawn_ai_with_scripts_and_effects_patch.set_enabled(c_settings::read_boolean(_settings_section_debug, "SpawnAiWithScriptsAndEffects", true));
	haloreach_spawn_ai_with_scripts_and_effects_in_multiplayer_patch.set_enabled(c_settings::read_boolean(_settings_section_debug, "SpawnAiWithScriptsAndEffects", true));
	//allow_night_vision_in_multiplayer_patch.set_enabled(c_settings::read_boolean(_settings_section_debug, "AllowNightVisionInMultiplayer", true));
	haloreach_enable_debug_hud_coordinates.set_enabled(c_settings::read_boolean(_settings_section_debug, "PanCamEnabled", true));

	//#TODO: fix the crash for builds 1955 and 2028
	allow_night_vision_in_multiplayer_patch.set_enabled(c_settings::read_boolean(_settings_section_debug, "AllowNightVisionInMultiplayer", true));

	if (hs_function_table != nullptr)
	{
		if (c_settings::read_boolean(_settings_section_debug, "ReplacePrintScriptEvaluate", true))
		{
			hs_script_op* hs_print_function = hs_function_get(0x28);
			hs_script_op* hs_chud_post_message_function = hs_function_get(build >= _build_mcc_1_1186_0_0 ? 0x509 : 0x508);

			if (c_settings::read_boolean(_settings_section_debug, "PrintToHud", true))
			{
				hs_print_function->replace_evaluate(hs_chud_post_message_function->evaluate);
			}
			else
			{
				hs_print_function->replace_evaluate(hs_print_evaluate);
			}
		}
	}

	init_detours();
	c_global_reference::init_global_reference_tree(_engine_type_haloreach, build);
	c_function_hook_base::init_function_hook_tree(_engine_type_haloreach, build);
	c_data_patch_base::init_data_patch_tree(_engine_type_haloreach, build);
	end_detours();
}

void c_haloreach_game_host::deinit_runtime_modifications(e_build build)
{
	delete g_haloreach_engine_state_command;
	delete g_haloreach_camera_command;

	init_detours();
	c_function_hook_base::deinit_function_hook_tree(_engine_type_haloreach, build);
	c_data_patch_base::deinit_data_patch_tree(_engine_type_haloreach, build);
	c_global_reference::deinit_global_reference_tree(_engine_type_haloreach, build);
	end_detours();
}

void c_haloreach_game_host::update_camera_data()
{
	if (!haloreach_player_mapping_get_local_player.is_hooked) return;
	if (!haloreach_observer_try_and_get_camera.is_hooked) return;

	int player_index = haloreach_player_mapping_get_local_player();
	s_observer_camera* observer_camera = haloreach_observer_try_and_get_camera(player_index);
	if (observer_camera)
	{
		float aspect_ratio = current_host->window.get_aspect_ratio();
		float horizontal_field_of_view = observer_camera->field_of_view;
		c_render::update_perspective(horizontal_field_of_view, aspect_ratio);
		c_render::update_view(
			observer_camera->forward.i,
			observer_camera->forward.k,
			observer_camera->forward.k,
			observer_camera->up.i,
			observer_camera->up.k,
			observer_camera->up.k,
			observer_camera->position.i,
			observer_camera->position.k,
			observer_camera->position.k
		);
	}
}

void c_haloreach_game_host::draw_script_debug_ui()
{
	static const bool k_enable_script_debug = c_command_line::has_command_line_arg("-scriptdebug");
	if (!k_enable_script_debug)
	{
		return;
	}
	if (!is_valid(g_hs_syntax_data))
	{
		return;
	}

	ImGui::SetNextWindowPos(ImVec2(17, 4), ImGuiCond_FirstUseEver);
	ImGui::SetNextWindowSize(ImVec2(1876, 1024), ImGuiCond_FirstUseEver);

	// Main body of the Demo window starts here.
	if (ImGui::Begin("Script Debug", &g_is_reach_script_debug_window_open, ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoCollapse))
	{
		ImGui::Text("g_hs_syntax_data %p", g_hs_syntax_data);
		if (g_hs_syntax_data)
		{
			ImGui::Text("count %i", g_hs_syntax_data->count);
			for (int i = 0; i < g_hs_syntax_data->count; i++)
			{
				hs_syntax_datum& syntax_datum = g_hs_syntax_data->data_ptr[i];

			}
		}
	}
	ImGui::End();
}

void c_haloreach_game_host::draw_camera_debug_ui()
{
	static const bool k_enable_camera_debug = c_command_line::has_command_line_arg("-cameradebug");
	if (!k_enable_camera_debug)
	{
		return;
	}

	ImGui::SetNextWindowPos(ImVec2(17, 4), ImGuiCond_FirstUseEver);
	ImGui::SetNextWindowSize(ImVec2(1876, 1024), ImGuiCond_FirstUseEver);

	// Main body of the Demo window starts here.
	if (ImGui::Begin("Camera Debug", &g_is_reach_camera_debug_window_open, ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoCollapse))
	{
		if (!haloreach_player_mapping_get_local_player.is_hooked) ImGui::Text("haloreach_player_mapping_get_local_player is not hooked");
		else if (!haloreach_observer_try_and_get_camera.is_hooked) ImGui::Text("haloreach_observer_try_and_get_camera is not hooked");
		else
		{
			int player_index = haloreach_player_mapping_get_local_player();
			s_observer_camera* observer_camera = haloreach_observer_try_and_get_camera(player_index);

			if (observer_camera)
			{
				ImGui::Text("position:       %f, %f, %f", observer_camera->position.i, observer_camera->position.j, observer_camera->position.k);
				ImGui::Text("position_shift: %f, %f, %f", observer_camera->position_shift.i, observer_camera->position_shift.j, observer_camera->position_shift.k);
				ImGui::Text("look:           %f", observer_camera->look);
				ImGui::Text("look_shift:     %f", observer_camera->look_shift);
				ImGui::Text("depth:          %f", observer_camera->depth);
				ImGui::Text("unknown0:       %f", observer_camera->unknown0);
				ImGui::Text("forward:        %f, %f, %f", observer_camera->forward.i, observer_camera->forward.j, observer_camera->forward.k);
				ImGui::Text("up:             %f, %f, %f", observer_camera->up.i, observer_camera->up.j, observer_camera->up.k);
				ImGui::Text("field_of_view:  %f", observer_camera->field_of_view);
				ImGui::Text("unknown1:       %f", observer_camera->unknown1);
				ImGui::Text("unknown2:       %f", observer_camera->unknown2);
			}
			else ImGui::Text("No camera present.");
		}
	}
	ImGui::End();

}

IGameEngine* c_haloreach_game_host::get_game_engine() const
{
	if (game_engine == nullptr)
	{
		__int64 create_game_engine_result = get_game_runtime().create_game_engine((IGameEngine**)&game_engine);
	}
	ASSERT(game_engine != nullptr);

	return game_engine;
}

/* ---------- private code */

