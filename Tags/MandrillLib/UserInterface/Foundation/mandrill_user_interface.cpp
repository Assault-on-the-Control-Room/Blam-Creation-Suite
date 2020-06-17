#include "mandrilllib-private-pch.h"

t_get_tag_game_memory_callback* c_mandrill_user_interface::s_get_tag_game_memory = nullptr;
t_get_tag_section_address_callback* c_mandrill_user_interface::s_get_tag_section_address = nullptr;

c_mandrill_user_interface::c_mandrill_user_interface(c_window& window, bool is_game_mode, const wchar_t* startup_file) :
	c_mandrill_tab("Mandrill", "", nullptr),
	window(window),
	is_session_restored(false),
	is_game_mode(is_game_mode),
	window_open(true),
	show_file_dialogue(false),
	on_close(),
	mandrill_theme_color_count(0),
	mandrill_theme_var_count(0),
	file_browser()
{
	restore_previous_session();
	open_cache_file(startup_file);
}

c_mandrill_user_interface::~c_mandrill_user_interface()
{
	for (c_mandrill_tab& tab : c_reference_loop(children.data(), children.size()))
	{
		delete& tab;
	}
}

void c_mandrill_user_interface::open_cache_file(const wchar_t* filepath)
{
	if (filepath == nullptr || !PathFileExistsW(filepath))
	{
		return;
	}

	for (c_mandrill_tab& tab : c_reference_loop(children.data(), children.size()))
	{
		if (c_cache_file_tab* cache_file_tab = dynamic_cast<c_cache_file_tab*>(&tab))
		{
			const wchar_t* cache_file_path = cache_file_tab->get_cache_file().get_map_filepath();
			if (wcscmp_ic(cache_file_path, filepath) == 0)
			{
				next_selected_tab = &tab;
				return;
			}
		}
	}

	c_cache_file* cache_file = c_cache_file::create_cache_file(filepath);
	if (cache_file)
	{
		c_cache_file_tab* cache_file_tab = new c_cache_file_tab(*cache_file, *this);
		add_tab(*cache_file_tab);
		next_selected_tab = cache_file_tab;
	}
	else
	{
		// #TODO: Display an error message that the map failed to open
	}
}

void c_mandrill_user_interface::restore_previous_session()
{
	c_fixed_wide_string<32 * 1024> open_maps_buffer;
	c_settings::read_wstring(_settings_section_mandrill, "open_maps", open_maps_buffer.str(), open_maps_buffer.capacity(), L"");

	c_fixed_wide_path open_maps_path;
	const wchar_t* read_position = open_maps_buffer.c_str();
	while (*read_position != 0)
	{
		while (*read_position && *read_position != ';')
		{
			open_maps_path += *read_position;
			read_position++;
		}

		open_cache_file(open_maps_path.c_str());

		open_maps_path.clear();
		read_position++;
	}
	is_session_restored = true;
}

void c_mandrill_user_interface::save_current_session()
{
	if (!is_session_restored)
	{
		return;
	}

	c_fixed_wide_path open_maps_path;
	for (c_mandrill_tab& tab : c_reference_loop(children.data(), children.size()))
	{
		if (c_cache_file_tab* cache_file_tab = dynamic_cast<c_cache_file_tab*>(&tab))
		{
			if (!open_maps_path.is_empty())
			{
				open_maps_path += ';';
			}
			open_maps_path += cache_file_tab->get_cache_file().get_map_filepath();			
		}
	}

	c_settings::write_wstring(_settings_section_mandrill, "open_maps", open_maps_path.c_str());
	//c_settings::write_wstring(_settings_section_mandrill, "open_maps", L"C:\\!MCC\\haloreach\\maps\\forge_halo.map;C:\\!MCC\\haloreach\\maps\\m45.map");
}

void c_mandrill_user_interface::render()
{
	render_impl();
}

void c_mandrill_user_interface::render_game_layer()
{
	render_game_layer_impl();
}

void c_mandrill_user_interface::set_get_tag_section_address_callback(t_get_tag_section_address_callback* get_tag_section_address)
{
	s_get_tag_section_address = get_tag_section_address;
}

void c_mandrill_user_interface::set_get_tag_game_memory_callback(t_get_tag_game_memory_callback* get_tag_game_memory)
{
	s_get_tag_game_memory = get_tag_game_memory;
}

void c_mandrill_user_interface::render_impl()
{
	mandrill_theme_push();

	float margin = 4.0f;
	ImGui::SetNextWindowPos({ margin, margin }, ImGuiCond_Always);
	ImGui::SetNextWindowSize({ window.get_width_float() - margin * 2.0f, window.get_height_float() - margin * 2.0f }, ImGuiCond_Always);

	ImGuiWindowFlags imgui_window_flags = 0;
	imgui_window_flags |= ImGuiWindowFlags_NoCollapse;
	imgui_window_flags |= ImGuiWindowFlags_MenuBar;
	imgui_window_flags |= ImGuiWindowFlags_NoSavedSettings;
	if (!is_game_mode)
	{
		imgui_window_flags |= ImGuiWindowFlags_NoTitleBar;
		imgui_window_flags |= ImGuiWindowFlags_NoMove;
		imgui_window_flags |= ImGuiWindowFlags_NoResize;
	}

	render_file_dialogue_gui_impl();

	if (ImGui::Begin("##mandrill", &window_open, imgui_window_flags))
	{
		ImGuiIO& io = ImGui::GetIO();

		render_menu_gui_impl(_menu_render_type_root);

		if (ImGui::BeginTabBar("##root"))
		{
			for (c_mandrill_tab& tab : c_reference_loop(children.data(), children.size()))
			{
				tab.render(next_selected_tab == &tab);
			}
			next_selected_tab = nullptr;

			ImGui::EndTabBar();
		}

	}
	ImGui::End();

	mandrill_theme_pop();

	if (!is_open)
	{
		on_close();
	}
}

void c_mandrill_user_interface::render_menu_gui_impl(e_menu_render_type menu_render_type)
{
	if (menu_render_type == _menu_render_type_root)
	{
		if (ImGui::BeginMenuBar())
		{
			if (ImGui::BeginMenu("File"))
			{
				ImGui::MenuItem("New");
				if (ImGui::MenuItem("Open File", "Ctrl+O"))
				{
					show_file_dialogue = true;
				}
				ImGui::MenuItem("Close");
				ImGui::Separator();
				ImGui::MenuItem("Save");
				ImGui::MenuItem("Save As");
				ImGui::Separator();
				ImGui::MenuItem("Compile");
				ImGui::Separator();
				ImGui::MenuItem("Save Workspace");
				ImGui::MenuItem("Load Workspace");
				ImGui::Separator();
				if (ImGui::MenuItem("Exit"))
				{
					is_open = false;
				}
				ImGui::EndMenu();
			}
			if (ImGui::BeginMenu("Edit"))
			{
				ImGui::MenuItem("Undo");
				ImGui::Separator();
				ImGui::MenuItem("Cut");
				ImGui::MenuItem("Copy");
				ImGui::MenuItem("Paste");
				ImGui::MenuItem("Clear");
				ImGui::Separator();
				ImGui::MenuItem("Expert Mode");
				ImGui::EndMenu();
			}
			if (ImGui::BeginMenu("Tools"))
			{
				ImGui::MenuItem("Push to game");
				ImGui::EndMenu();
			}
			if (ImGui::BeginMenu("View"))
			{
				ImGui::MenuItem("Explorer Bar");
				ImGui::EndMenu();
			}
			for (c_mandrill_tab& tab : c_reference_loop(children.data(), children.size()))
			{
				tab.render_menu_gui(_menu_render_type_root);
			}
			if (ImGui::BeginMenu("Help"))
			{
				ImGui::MenuItem("Read Me");
				ImGui::MenuItem("About");
				ImGui::EndMenu();
			}
			ImGui::EndMenuBar();
		}
	}
}

void c_mandrill_user_interface::render_file_dialogue_gui_impl()
{
	if (show_file_dialogue)
	{
		float file_browser_window_width = std::clamp(window.get_width_float(), 700.0f, 1200.0f);
		float file_browser_window_height = std::clamp(window.get_height_float(), 310.0f, 675.0f);
		if (file_browser.show_open_file_dialog("Open File", ImVec2(file_browser_window_width, file_browser_window_height), ".map"))
		{
			show_file_dialogue = false;

			const char* selected_file_path = file_browser.get_selected_file_name();
			c_fixed_wide_path selected_file_path_buffer;
			selected_file_path_buffer.format(L"%S", selected_file_path);
			open_cache_file(selected_file_path_buffer.c_str());
		}
	}
	else
	{
		for (c_mandrill_tab& tab : c_reference_loop(children.data(), children.size()))
		{
			tab.render_file_dialogue_gui();
		}
	}
}

void c_mandrill_user_interface::render_game_layer_impl()
{
	for (c_mandrill_tab& tab : c_reference_loop(children.data(), children.size()))
	{
		tab.render_game_layer();
	}
}

void c_mandrill_user_interface::add_tab(c_mandrill_tab& tab)
{
	c_mandrill_tab_container::add_tab(tab);
	save_current_session();
}

void c_mandrill_user_interface::remove_tab(c_mandrill_tab& tab)
{
	c_mandrill_tab_container::remove_tab(tab);
	save_current_session();
}

void c_mandrill_user_interface::mandrill_theme_push()
{
#define push_color4_float(color, r, g, b, a) mandrill_theme_color_count++; ImGui::PushStyleColor(color, ImVec4(float(r), float(g), float(b), float(a)))
#define push_color3_float(color, r, g, b) push_color4_float(color, r, g, b, 1.0f)
#define push_color4(color, r, g, b, a) push_color4_float(color, float(r) / 255.0f, float(g) / 255.0f, float(b) / 255.0f, 1.0f)
#define push_color3(color, r, g, b) push_color4(color, r, g, b, 255)
#define push_color(color, value) mandrill_theme_color_count++; ImGui::PushStyleColor(color, value)
#define push_style(style, ...) mandrill_theme_var_count++; ImGui::PushStyleVar(style, __VA_ARGS__)

	mandrill_theme_color_count = 0;
	mandrill_theme_var_count = 0;

	push_color(ImGuiCol_Text, MANDRILL_THEME_TEXT(0.78f));
	push_color(ImGuiCol_TextDisabled, MANDRILL_THEME_TEXT(0.28f));
	push_color(ImGuiCol_WindowBg, ImVec4(0.13f, 0.14f, 0.17f, 1.00f));
	push_color(ImGuiCol_ChildBg, MANDRILL_THEME_BG(0.15f));
	push_color(ImGuiCol_PopupBg, MANDRILL_THEME_BG(0.9f));
	push_color(ImGuiCol_Border, ImVec4(0.31f, 0.31f, 1.00f, 0.00f));
	push_color(ImGuiCol_BorderShadow, ImVec4(0.00f, 0.00f, 0.00f, 0.00f));
	push_color(ImGuiCol_FrameBg, MANDRILL_THEME_BG(1.00f));
	push_color(ImGuiCol_FrameBgHovered, MANDRILL_THEME_MED(0.78f));
	push_color(ImGuiCol_FrameBgActive, MANDRILL_THEME_MED(1.00f));
	push_color(ImGuiCol_TitleBg, MANDRILL_THEME_LOW(1.00f));
	push_color(ImGuiCol_TitleBgActive, MANDRILL_THEME_HIGH(1.00f));
	push_color(ImGuiCol_TitleBgCollapsed, MANDRILL_THEME_BG(0.75f));
	push_color(ImGuiCol_MenuBarBg, MANDRILL_THEME_BG(0.47f));
	push_color(ImGuiCol_ScrollbarBg, MANDRILL_THEME_BG(1.00f));
	push_color(ImGuiCol_ScrollbarGrab, ImVec4(0.09f, 0.15f, 0.16f, 1.00f));
	push_color(ImGuiCol_ScrollbarGrabHovered, MANDRILL_THEME_MED(0.78f));
	push_color(ImGuiCol_ScrollbarGrabActive, MANDRILL_THEME_MED(1.00f));
	push_color(ImGuiCol_CheckMark, ImVec4(0.71f, 0.22f, 0.27f, 1.00f));
	push_color(ImGuiCol_SliderGrab, ImVec4(0.47f, 0.77f, 0.83f, 0.14f));
	push_color(ImGuiCol_SliderGrabActive, ImVec4(0.71f, 0.22f, 0.27f, 1.00f));
	push_color(ImGuiCol_Button, ImVec4(0.47f, 0.77f, 0.83f, 0.14f));
	push_color(ImGuiCol_ButtonHovered, MANDRILL_THEME_MED(0.86f));
	push_color(ImGuiCol_ButtonActive, MANDRILL_THEME_MED(1.00f));
	push_color(ImGuiCol_Header, MANDRILL_THEME_MED(0.76f));
	push_color(ImGuiCol_HeaderHovered, MANDRILL_THEME_MED(0.86f));
	push_color(ImGuiCol_HeaderActive, MANDRILL_THEME_HIGH(1.00f));
	//push_color(ImGuiCol_Column, ImVec4(0.14f, 0.16f, 0.19f, 1.00f));
	//push_color(ImGuiCol_ColumnHovered, MANDRILL_THEME_MED(0.78f));
	//push_color(ImGuiCol_ColumnActive, MANDRILL_THEME_MED(1.00f));
	push_color(ImGuiCol_ResizeGrip, ImVec4(0.47f, 0.77f, 0.83f, 0.04f));
	push_color(ImGuiCol_ResizeGripHovered, MANDRILL_THEME_MED(0.78f));
	push_color(ImGuiCol_ResizeGripActive, MANDRILL_THEME_MED(1.00f));
	push_color(ImGuiCol_PlotLines, MANDRILL_THEME_TEXT(0.63f));
	push_color(ImGuiCol_PlotLinesHovered, MANDRILL_THEME_MED(1.00f));
	push_color(ImGuiCol_PlotHistogram, MANDRILL_THEME_TEXT(0.63f));
	push_color(ImGuiCol_PlotHistogramHovered, MANDRILL_THEME_MED(1.00f));
	push_color(ImGuiCol_TextSelectedBg, MANDRILL_THEME_MED(0.43f));
	push_color(ImGuiCol_ModalWindowDarkening, MANDRILL_THEME_BG(0.73f));

	push_color(ImGuiCol_Tab, ImVec4(0.14f, 0.16f, 0.19f, 1.00f));
	push_color(ImGuiCol_TabHovered, MANDRILL_THEME_MED(0.78f));
	push_color(ImGuiCol_TabActive, MANDRILL_THEME_MED(1.00f));
	push_color(ImGuiCol_TabUnfocused, MANDRILL_THEME_LOW(0.78f));


	//push_color3(ImGuiCol_WindowBg, 33, 33, 33);
	push_color(ImGuiCol_MenuBarBg, MANDRILL_THEME_MENU(1.0f));

	push_style(ImGuiStyleVar_WindowPadding, { 4, 8 });
	push_style(ImGuiStyleVar_ScrollbarSize, { 20 });
	push_style(ImGuiStyleVar_ItemInnerSpacing, { 5, 4 });

	push_style(ImGuiStyleVar_WindowRounding, { 0 });
	push_style(ImGuiStyleVar_ScrollbarRounding, { 0 });
	push_style(ImGuiStyleVar_TabRounding, { 0 });

#undef push_color4_float
#undef push_color3_float
#undef push_color4
#undef push_color3
#undef push_style
}

void c_mandrill_user_interface::mandrill_theme_pop()
{
	ImGui::PopStyleColor(mandrill_theme_color_count);
	ImGui::PopStyleVar(mandrill_theme_var_count);
}
