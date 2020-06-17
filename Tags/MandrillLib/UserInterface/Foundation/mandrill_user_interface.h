#pragma once

using t_get_tag_game_memory_callback = char* (uint16_t tag_index);
using t_get_tag_section_address_callback = char* (uint32_t address);

#define MANDRILL_THEME_HIGH(v) { 0.502f, 0.075f, 0.256f, v }
#define MANDRILL_THEME_MED(v) { 0.455f, 0.198f, 0.301f, v }
#define MANDRILL_THEME_LOW(v) { 0.232f, 0.201f, 0.271f, v }
#define MANDRILL_THEME_BG(v) { 0.200f, 0.220f, 0.270f, v }
#define MANDRILL_THEME_TEXT(v) { 0.930f, 0.965f, 0.945f, v }
#define MANDRILL_THEME_MENU(v) { 0.377f, 0.377f, 0.377f, v }

class c_mandrill_user_interface :
	public c_mandrill_tab
{
public:
	non_copyconstructable(c_mandrill_user_interface);

	c_mandrill_user_interface(c_window& window, bool is_game_mode, const wchar_t* startup_file = nullptr);
	~c_mandrill_user_interface();

	void open_cache_file(const wchar_t* filepath);
	void restore_previous_session();
	void save_current_session();
	void render();
	void render_game_layer();

	c_callback<void()> on_close;

	inline bool is_game() const { return is_game_mode; }
	inline bool get_use_full_file_length_display() { return false; }
	
	static void set_get_tag_section_address_callback(t_get_tag_section_address_callback* get_tag_section_address);
	static void set_get_tag_game_memory_callback(t_get_tag_game_memory_callback* get_tag_game_memory);

protected:
	void mandrill_theme_push();
	void mandrill_theme_pop();

	virtual void render_impl() override final;
	virtual void render_menu_gui_impl(e_menu_render_type menu_render_type) override final;
	virtual void render_file_dialogue_gui_impl() override final;
	virtual void render_game_layer_impl() override final;
	virtual void add_tab(c_mandrill_tab& tab) override final;
	virtual void remove_tab(c_mandrill_tab& tab) override final;

	c_window& window;
	bool is_session_restored;
	bool is_game_mode;
	bool window_open;
	bool show_file_dialogue;
	int mandrill_theme_color_count;
	int mandrill_theme_var_count;
	ImGuiAddons::ImGuiFileBrowser file_browser;

	static t_get_tag_game_memory_callback* s_get_tag_game_memory;
	static t_get_tag_section_address_callback* s_get_tag_section_address;

};
