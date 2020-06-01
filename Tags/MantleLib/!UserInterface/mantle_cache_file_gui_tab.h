#pragma once

class c_cache_file;
class c_mantle_halo_script_editor;

class c_mantle_cache_file_gui_tab : public c_mantle_gui_tab
{
public:
	friend class c_mantle_tag_gui_tab;

	void render_cache_file_gui();
public:
	c_mantle_cache_file_gui_tab() = delete;
	c_mantle_cache_file_gui_tab(const c_mantle_cache_file_gui_tab&) = delete;
	c_mantle_cache_file_gui_tab& operator=(const c_mantle_cache_file_gui_tab&) = delete;

	c_mantle_cache_file_gui_tab(c_cache_file& cache_file);
	c_mantle_cache_file_gui_tab(const wchar_t* map_file_path);
	virtual ~c_mantle_cache_file_gui_tab();

	c_cache_file& get_cache_file() const { return cache_file; }
	void open_tag_interface_tab(c_tag_interface& tag_interface);
protected:
	c_mantle_cache_file_gui_tab(c_cache_file* cache_file);

	virtual void render_in_game_gui() override;
	virtual void render_tab_menu_gui() override;
	virtual void render_tab_contents_gui() override;

	void open_shader_tool();
	void open_halo_script_editor();
	void close_halo_script_editor();
	void render_file_dialogue_gui();

	bool debug_file_dialogue_gui;
	char search_buffer[1024];
	c_tag_interface* search_selected_tag_interface;
	c_mantle_gui_tab* next_selected_mantle_gui_tab;
	bool render_trigger_volumes;
	c_cache_file& cache_file;
	c_cache_file* cache_file_owned_pointer;
	bool enable_shader_tool;
	std::string shader_tool_directory;
	c_mantle_halo_script_editor* halo_script_editor;
	ImGuiAddons::ImGuiFileBrowser file_browser;
};

