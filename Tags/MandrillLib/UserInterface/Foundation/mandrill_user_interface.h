#pragma once

class c_cache_file_tab;

using t_get_tag_game_memory_callback = char* (uint32_t tag_index);
using t_get_tag_section_address_callback = char* (uint32_t address);

#define MANDRILL_THEME_HIGH(v) { 0.502f, 0.075f, 0.256f, v }
#define MANDRILL_THEME_MED(v) { 0.455f, 0.198f, 0.301f, v }
#define MANDRILL_THEME_LOW(v) { 0.232f, 0.201f, 0.271f, v }
#define MANDRILL_THEME_DISABLED_HIGH(v) { 0.224f, 0.224f, 0.224f, v }
#define MANDRILL_THEME_DISABLED_MED(v) { 0.286f, 0.286f, 0.286f, v }
#define MANDRILL_THEME_DISABLED_LOW(v) { 0.215f, 0.215f, 0.215f, v }
#define MANDRILL_THEME_BG(v) { 0.200f, 0.220f, 0.270f, v }
#define MANDRILL_THEME_TEXT(v) { 0.930f, 0.965f, 0.945f, v }
#define MANDRILL_THEME_COMMENT_TEXT(v) { 0.752f, 0.965f, 0.766f, v }
#define MANDRILL_THEME_INFO_TEXT(v) { 0.796f, 0.808f, 0.965f, v }
#define MANDRILL_THEME_MENU(v) { 0.377f, 0.377f, 0.377f, v }

constexpr float MANDRILL_THEME_DEFAULT_TEXT_ALPHA = 0.78f;

namespace ImGuiAddons
{
	class ImGuiFileBrowser;
}

class c_mandrill_user_interface :
	public c_mandrill_tab
{
public:
	non_copyconstructable(c_mandrill_user_interface);

	c_mandrill_user_interface(c_window& window, bool is_game_mode, const wchar_t* startup_file = nullptr);
	~c_mandrill_user_interface();

	void create_tag_project(const wchar_t* filepath, const char* tag_list = nullptr);
	void open_cache_file_tab(const wchar_t* filepath, const char* tag_list = nullptr);
	void open_tag_project_tab(const wchar_t* filepath, const char* tag_list = nullptr);
	void open_tag_project_configurator_tab(const wchar_t* directory);
	void restore_previous_session(bool use_projects);
	void save_current_session();
	void render();
	void render_game_layer();

	c_callback<void()> on_close;

	inline bool is_game() const { return is_game_mode; }
	inline bool get_use_full_file_length_display() { return false; }
	
	static void set_get_tag_section_address_callback(t_get_tag_section_address_callback* get_tag_section_address);
	static void set_get_tag_game_memory_callback(t_get_tag_game_memory_callback* get_tag_game_memory);

	static constexpr const char* k_use_developer_features = "use_developer_features";
	static constexpr const char* k_show_explorer_bar = "show_explorer_bar";
	static constexpr const char* k_explorer_bar_width = "explorer_bar_width";
	static constexpr const char* k_previous_open_filepath_setting = "previous_open_filepath";
	static constexpr const char* k_previous_open_maps_setting = "open_maps";
	static constexpr const char* k_previous_open_projects_setting = "open_projects";
	
	static bool use_developer_features;
	static bool show_explorer_bar;
	static float explorer_bar_width;

protected:
	void mandrill_theme_push();
	void mandrill_theme_pop();

	virtual void render_impl() override final;
	virtual void render_menu_gui_impl(e_menu_render_type menu_render_type) override final;
	virtual void render_file_dialogue_gui_impl() override final;
	virtual void render_game_layer_impl() override final;
public:
	virtual void add_tab(c_mandrill_tab& tab) override final;
	virtual void remove_tab(c_mandrill_tab& tab) override final;

protected:
	c_window& window;
	bool is_session_restored;
	bool is_exiting;
	bool is_game_mode;
	bool window_open;
	bool show_create_tag_project_file_dialogue;
	bool show_open_cache_file_dialogue;
	int mandrill_theme_color_count;
	int mandrill_theme_var_count;
	ImGuiAddons::ImGuiFileBrowser* file_browser;

public:
	static t_get_tag_game_memory_callback* s_get_tag_game_memory;
	static t_get_tag_section_address_callback* s_get_tag_section_address;
};
