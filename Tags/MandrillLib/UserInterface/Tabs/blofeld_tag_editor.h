#pragma once

class c_blofeld_tag_editor_tab :
	public c_mandrill_tab
{
public:
	non_copyconstructable(c_blofeld_tag_editor_tab);

	c_blofeld_tag_editor_tab(c_tag_interface& tag_interface, c_mandrill_tab& parent);
	virtual ~c_blofeld_tag_editor_tab();

	uint32_t copy_data_recursively(const char* const local_tag_memory, char* const game_tag_memory, const blofeld::s_tag_struct_definition& struct_definition);
	c_tag_interface& get_tag_interface() const { return tag_interface; }
	c_cache_file& get_cache_file() const { return tag_interface.get_cache_file(); }

protected:
	virtual void render_impl() override final;
	virtual void render_menu_gui_impl(e_menu_render_type menu_render_type) override final;
	virtual void render_file_dialogue_gui_impl() override final;
	virtual void render_game_layer_impl() override final;

	bool render_primitive(void* data, const blofeld::s_tag_field& field);
	void render_tagblock(void* data, const blofeld::s_tag_field& field);
	void render_tagref(void* data, const blofeld::s_tag_field& field);
	c_tag_interface& tag_interface;
	c_cache_file& cache_file;
	ImVec2 viewport_size;

	uint32_t render_tag_struct_definition(int level, char* data, const blofeld::s_tag_struct_definition& struct_definition);
	uint32_t render_tag_group(char* data, const blofeld::s_tag_group& group);
};
