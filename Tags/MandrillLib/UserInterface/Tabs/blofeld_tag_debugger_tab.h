#pragma once

class c_gen3_cache_file_validator;
struct s_field_validation_result;

class c_blofeld_tag_debugger_tab :
	public c_mandrill_tab
{
public:
	non_copyconstructable(c_blofeld_tag_debugger_tab);

	c_blofeld_tag_debugger_tab(c_tag_interface& tag_interface, c_mandrill_tab& parent);
	virtual ~c_blofeld_tag_debugger_tab();

	c_tag_interface& get_tag_interface() const { return tag_interface; }
	c_cache_file& get_cache_file() const { return tag_interface.get_cache_file(); }

protected:
	virtual void render_impl() override final;
	virtual void render_menu_gui_impl(e_menu_render_type menu_render_type) override final;
	virtual void render_file_dialogue_gui_impl() override final;
	virtual void render_game_layer_impl() override final;

	c_tag_interface& tag_interface;

	static constexpr const char* k_show_hex_values_setting = "show_hex_values";
	static constexpr const char* k_show_hex_values_float_setting = "show_hex_values_float";
	static constexpr const char* k_show_broken_block_data_setting = "show_broken_block_data";
	static constexpr const char* k_show_field_offsets_setting = "show_field_offsets";
	static constexpr const char* k_show_custom_fields_setting = "show_custom_fields";
	static constexpr const char* k_use_absolute_offsets_setting = "use_absolute_offsets";

	static bool show_hex_values;
	static bool show_hex_values_float;
	static bool show_broken_block_data;
	static bool show_field_offsets;
	static bool show_custom_fields;
	static bool use_absolute_offsets;
	

	void setup_render_callbacks();
#define render_field_callback_args c_tag_interface& tag_interface, char* data, const blofeld::s_tag_field& field, s_field_validation_result* result
	void render_field_callback(render_field_callback_args, c_callback<void(render_field_callback_args)>& render_field_callback);
	void render_field_string(render_field_callback_args);
	void render_field_long_string(render_field_callback_args);
	void render_field_string_id(render_field_callback_args);
	void render_field_old_string_id(render_field_callback_args);
	void render_field_char_integer(render_field_callback_args);
	void render_field_short_integer(render_field_callback_args);
	void render_field_long_integer(render_field_callback_args);
	void render_field_int64_integer(render_field_callback_args);
	void render_field_angle(render_field_callback_args);
	void render_field_tag(render_field_callback_args);
	void render_field_char_enum(render_field_callback_args);
	void render_field_enum(render_field_callback_args);
	void render_field_long_enum(render_field_callback_args);
	void render_field_long_flags(render_field_callback_args);
	void render_field_word_flags(render_field_callback_args);
	void render_field_byte_flags(render_field_callback_args);
	void render_field_point_2d(render_field_callback_args);
	void render_field_rectangle_2d(render_field_callback_args);
	void render_field_rgb_color(render_field_callback_args);
	void render_field_argb_color(render_field_callback_args);
	void render_field_real(render_field_callback_args);
	void render_field_real_fraction(render_field_callback_args);
	void render_field_real_point_2d(render_field_callback_args);
	void render_field_real_point_3d(render_field_callback_args);
	void render_field_real_vector_2d(render_field_callback_args);
	void render_field_real_vector_3d(render_field_callback_args);
	void render_field_real_quaternion(render_field_callback_args);
	void render_field_real_euler_angles_2d(render_field_callback_args);
	void render_field_real_euler_angles_3d(render_field_callback_args);
	void render_field_real_plane_2d(render_field_callback_args);
	void render_field_real_plane_3d(render_field_callback_args);
	void render_field_real_rgb_color(render_field_callback_args);
	void render_field_real_argb_color(render_field_callback_args);
	void render_field_real_hsv_color(render_field_callback_args);
	void render_field_real_ahsv_color(render_field_callback_args);
	void render_field_short_bounds(render_field_callback_args);
	void render_field_angle_bounds(render_field_callback_args);
	void render_field_real_bounds(render_field_callback_args);
	void render_field_real_fraction_bounds(render_field_callback_args);
	void render_field_tag_reference(render_field_callback_args);
	void render_field_block(render_field_callback_args);
	void render_field_long_block_flags(render_field_callback_args);
	void render_field_word_block_flags(render_field_callback_args);
	void render_field_byte_block_flags(render_field_callback_args);
	void render_field_char_block_index(render_field_callback_args);
	void render_field_custom_char_block_index(render_field_callback_args);
	void render_field_short_block_index(render_field_callback_args);
	void render_field_custom_short_block_index(render_field_callback_args);
	void render_field_long_block_index(render_field_callback_args);
	void render_field_custom_long_block_index(render_field_callback_args);
	void render_field_data(render_field_callback_args);
	void render_field_vertex_buffer(render_field_callback_args);
	void render_field_pad(render_field_callback_args);
	void render_field_useless_pad(render_field_callback_args);
	void render_field_skip(render_field_callback_args);
	void render_field_non_cache_runtime_value(render_field_callback_args);
	void render_field_explanation(render_field_callback_args);
	void render_field_custom(render_field_callback_args);
	void render_field_struct(render_field_callback_args);
	void render_field_array(render_field_callback_args);
	void render_field_pageable(render_field_callback_args);
	void render_field_api_interop(render_field_callback_args);
	void render_field_terminator(render_field_callback_args);
	void render_field_byte_integer(render_field_callback_args);
	void render_field_word_integer(render_field_callback_args);
	void render_field_dword_integer(render_field_callback_args);
	void render_field_qword_integer(render_field_callback_args);
#undef callback_args

	void render_field_name(const blofeld::s_tag_field& field, s_field_validation_result* result);
	void render_field_scalar_type(ImGuiDataType data_type, uint32_t count, int level, char* data, const blofeld::s_tag_field& field, s_field_validation_result* result, const char* format = nullptr);
private:
	template<typename t_raw_value> void render_field_enum_type(int level, char* data, const blofeld::s_tag_field& field, s_field_validation_result* result);
};
