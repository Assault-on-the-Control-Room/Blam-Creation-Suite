#include "mandrilllib-private-pch.h"

bool c_blofeld_tag_debugger_tab::show_hex_values = c_settings::read_boolean(_settings_section_mandrill, k_show_hex_values_setting, false);
bool c_blofeld_tag_debugger_tab::show_hex_values_float = c_settings::read_boolean(_settings_section_mandrill, k_show_hex_values_float_setting, false);
bool c_blofeld_tag_debugger_tab::show_broken_block_data = c_settings::read_boolean(_settings_section_mandrill, k_show_broken_block_data_setting, false);
bool c_blofeld_tag_debugger_tab::show_field_offsets = c_settings::read_boolean(_settings_section_mandrill, k_show_field_offsets_setting, true);
bool c_blofeld_tag_debugger_tab::show_custom_fields = c_settings::read_boolean(_settings_section_mandrill, k_show_custom_fields_setting, false);
bool c_blofeld_tag_debugger_tab::use_absolute_offsets = c_settings::read_boolean(_settings_section_mandrill, k_use_absolute_offsets_setting, false);

float indent_size = 20.0f;

c_blofeld_tag_debugger_tab::c_blofeld_tag_debugger_tab(c_tag_interface& tag_interface, c_mandrill_tab& parent) :
	c_mandrill_tab("Tag Debugger", "Blofeld Tag Debugger", &parent, false),
	tag_interface(tag_interface),
	viewport_size()
{
	setup_render_callbacks();
}

c_blofeld_tag_debugger_tab::~c_blofeld_tag_debugger_tab()
{

}

bool c_blofeld_tag_debugger_tab::is_enabled() const
{
	return c_mandrill_user_interface::use_developer_features;
}

void c_blofeld_tag_debugger_tab::render_field_name(c_field_formatter& formatter, const blofeld::s_tag_field& field, s_field_validation_result* result)
{
	float start = ImGui::GetCursorPosX();
	ImGui::Text(formatter.display_name.c_str());
	ImGui::SameLine();
	float end = ImGui::GetCursorPosX();
	ImGui::Dummy({ __max(0.0f, 300.0f - (end - start)), 0.0f });
}

void c_blofeld_tag_debugger_tab::render_field_name_and_information(const blofeld::s_tag_field& field, s_field_validation_result* result)
{
	ImGui::SameLine();
	if (show_field_offsets)
	{
		uint32_t offset = use_absolute_offsets ? result->absolute_offset : result->field_offset;
		ImGui::Text("0x%X | %s %s", offset, blofeld::field_to_string(field.field_type), field.name);
	}
	else
	{
		ImGui::Text("%s %s", blofeld::field_to_string(field.field_type), field.name);
	}
}

void c_blofeld_tag_debugger_tab::render_field_scalar_type(ImGuiDataType data_type, uint32_t count, int level, char* data, const blofeld::s_tag_field& field, s_field_validation_result* result, bool use_hex, const char* format)
{
	ImGuiInputTextFlags flags = ImGuiInputTextFlags_ReadOnly;
	if ((show_hex_values || use_hex) && data_type != ImGuiDataType_Float)
	{
		flags |= ImGuiInputTextFlags_CharsHexadecimal;
	}
	if ((show_hex_values_float || use_hex) && data_type == ImGuiDataType_Float)
	{
		data_type = ImGuiDataType_U32;
		flags |= ImGuiInputTextFlags_CharsHexadecimal;
	}
	if (data_type == ImGuiDataType_Float && format == nullptr)
	{
		float value = *reinterpret_cast<float*>(data);
		if (fabsf(value) < 0.000001f && value != 0.0f)
		{
			format = "%e";
		}
	}

	c_field_formatter formatter = c_field_formatter(&field, nullptr);

	const ImGuiDataTypeInfo* info = ImGui::DataTypeGetInfo(data_type);
	ImGui::BeginGroup();
	ImGui::Dummy({ level * indent_size, 0.0f });
	ImGui::SameLine();
	render_field_name(formatter, field, result);
	ImGui::SameLine();
	ImGui::PushItemWidth(300.0f + static_cast<float>(count) * 50.0f);
	ImGui::InputScalarN("", data_type, data, (int)count, nullptr, nullptr, format, ImGuiInputTextFlags_ReadOnly);
	render_field_name_and_information(field, result);
	ImGui::EndGroup();
	if (!formatter.description.is_empty() && ImGui::IsItemHovered())
	{
		ImGui::BeginTooltip();
		ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
		ImGui::TextUnformatted(formatter.description.c_str());
		ImGui::PopTextWrapPos();
		ImGui::EndTooltip();
	}
}

template<typename t_raw_value>
void c_blofeld_tag_debugger_tab::render_field_enum_type(int level, char* data, const blofeld::s_tag_field& field, s_field_validation_result* result)
{
	if (field.string_list_definition == nullptr)
	{
		ImGui::Text("ERROR: MISSING ENUM STRING_LIST_DEFINITION!!!!!!");
		return;
	}

	const char* format_string = "raw: %u ";
	if (show_hex_values)
	{
		format_string = "raw: 0x%X ";
	}

	ImGui::Dummy({ level * indent_size, 0.0f });
	ImGui::SameLine();
	e_engine_type engine_type = get_cache_file().get_engine_type();
	t_raw_value& raw_value = *reinterpret_cast<t_raw_value*>(data);
	c_fixed_string_256 enum_value;
	enum_value.format(format_string, static_cast<uint32_t>(raw_value));
	if (raw_value < field.string_list_definition->count(engine_type))
	{
		enum_value += field.string_list_definition->strings(engine_type)[raw_value];
	}
	ImGui::PushItemWidth(350.0f);
	ImGui::InputText("", enum_value.str(), 256, ImGuiInputTextFlags_ReadOnly);
	render_field_name_and_information(field, result);
}

void c_blofeld_tag_debugger_tab::render_field_callback(render_field_callback_args, c_callback<void(render_field_callback_args)>& render_field_callback)
{
	if (&tag_interface != &this->tag_interface) return;

	static ImVec4 validation_colors[] =
	{
		MANDRILL_THEME_TEXT(1.0f),			// unknown,
		ImVec4{ 0.3f, 1.0f, 0.3f, 1.0f },	// valid,
		ImVec4{ 0.3f, 1.0f, 0.7f, 1.0f },	// block_valid,
		ImVec4{ 1.0f, 1.0f, 0.3f, 1.0f },	// warning,
		ImVec4{ 1.0f, 0.3f, 0.3f, 1.0f },	// invalid,
		ImVec4{ 1.0f, 0.3f, 0.3f, 1.0f },	// previously_invalid
	};

	ImGui::PushID(data);
	ImGui::PushStyleColor(ImGuiCol_Text, validation_colors[result->validation_state]);

	render_field_callback(tag_interface, data, field, result);

	ImGui::PopStyleColor();
	ImGui::PopID();
}

void c_blofeld_tag_debugger_tab::render_field_string(render_field_callback_args)
{
	if (&tag_interface != &this->tag_interface) return;
	ImGui::Dummy({ result->level * indent_size, 0.0f });
	ImGui::SameLine();
	ImGui::InputText("", data, 32, ImGuiInputTextFlags_ReadOnly);
	render_field_name_and_information(field, result);
}
void c_blofeld_tag_debugger_tab::render_field_long_string(render_field_callback_args)
{
	if (&tag_interface != &this->tag_interface) return;
	ImGui::Dummy({ result->level * indent_size, 0.0f });
	ImGui::SameLine();
	ImGui::InputText("", data, 256, ImGuiInputTextFlags_ReadOnly);
	render_field_name_and_information(field, result);
}
void c_blofeld_tag_debugger_tab::render_field_string_id(render_field_callback_args)
{
	if (&tag_interface != &this->tag_interface) return;
	ImGui::Dummy({ result->level * indent_size, 0.0f });
	ImGui::SameLine();
	if (result->string_id_value)
	{
		const char* string_id = result->string_id_value;
		ImGui::InputText("", (char*)string_id, strlen(string_id) + 1, ImGuiInputTextFlags_ReadOnly);
	}
	else
	{
		ImGuiInputTextFlags flags = ImGuiInputTextFlags_ReadOnly;
		if (show_hex_values)
		{
			flags |= ImGuiInputTextFlags_CharsHexadecimal;
		}
		ImGui::InputInt("", reinterpret_cast<int*>(data), 1, 100, flags);
	}
	render_field_name_and_information(field, result);
}
void c_blofeld_tag_debugger_tab::render_field_old_string_id(render_field_callback_args)
{
	if (&tag_interface != &this->tag_interface) return;
	ImGui::Dummy({ result->level * indent_size, 0.0f });
	ImGui::SameLine();
	int& old_string_id = *reinterpret_cast<int*>(data);
	ImGui::InputInt("", &old_string_id, 1, 100, ImGuiInputTextFlags_ReadOnly);
	render_field_name_and_information(field, result);
}
void c_blofeld_tag_debugger_tab::render_field_char_integer(render_field_callback_args)
{
	if (&tag_interface != &this->tag_interface) return;
	render_field_scalar_type(ImGuiDataType_S8, 1, result->level, data, field, result);
}
void c_blofeld_tag_debugger_tab::render_field_short_integer(render_field_callback_args)
{
	if (&tag_interface != &this->tag_interface) return;
	render_field_scalar_type(ImGuiDataType_S16, 1, result->level, data, field, result);
}
void c_blofeld_tag_debugger_tab::render_field_long_integer(render_field_callback_args)
{
	if (&tag_interface != &this->tag_interface) return;
	render_field_scalar_type(ImGuiDataType_S32, 1, result->level, data, field, result);
}
void c_blofeld_tag_debugger_tab::render_field_int64_integer(render_field_callback_args)
{
	if (&tag_interface != &this->tag_interface) return;
	render_field_scalar_type(ImGuiDataType_S64, 1, result->level, data, field, result);
}
void c_blofeld_tag_debugger_tab::render_field_angle(render_field_callback_args)
{
	if (&tag_interface != &this->tag_interface) return;

	float value = *reinterpret_cast<float*>(data);
	value *= 180.0f / 3.14159265359f;
	ImGui::Dummy({ result->level * indent_size, 0.0f });
	render_field_name_and_information(field, result);
	ImGui::SameLine();
	ImGui::Text("angle: [%.4f]", value);

	//render_field_scalar_type(ImGuiDataType_Float, 1, result->level, data, field, result);
}
void c_blofeld_tag_debugger_tab::render_field_tag(render_field_callback_args)
{
	if (&tag_interface != &this->tag_interface) return;
	render_field_scalar_type(ImGuiDataType_U32, 1, result->level, data, field, result);
}
void c_blofeld_tag_debugger_tab::render_field_char_enum(render_field_callback_args)
{
	if (&tag_interface != &this->tag_interface) return;
	render_field_enum_type<byte>(result->level, data, field, result);
}
void c_blofeld_tag_debugger_tab::render_field_enum(render_field_callback_args)
{
	if (&tag_interface != &this->tag_interface) return;
	render_field_enum_type<word>(result->level, data, field, result);
}
void c_blofeld_tag_debugger_tab::render_field_long_enum(render_field_callback_args)
{
	if (&tag_interface != &this->tag_interface) return;
	render_field_enum_type<unsigned long>(result->level, data, field, result);
}
void c_blofeld_tag_debugger_tab::render_field_long_flags(render_field_callback_args)
{
	if (&tag_interface != &this->tag_interface) return;
	render_field_scalar_type(ImGuiDataType_U32, 1, result->level, data, field, result);
}
void c_blofeld_tag_debugger_tab::render_field_word_flags(render_field_callback_args)
{
	if (&tag_interface != &this->tag_interface) return;
	render_field_scalar_type(ImGuiDataType_U16, 1, result->level, data, field, result);
}
void c_blofeld_tag_debugger_tab::render_field_byte_flags(render_field_callback_args)
{
	if (&tag_interface != &this->tag_interface) return;
	render_field_scalar_type(ImGuiDataType_U8, 1, result->level, data, field, result);
}
void c_blofeld_tag_debugger_tab::render_field_point_2d(render_field_callback_args)
{
	if (&tag_interface != &this->tag_interface) return;
	render_field_scalar_type(ImGuiDataType_S16, 2, result->level, data, field, result);
}
void c_blofeld_tag_debugger_tab::render_field_rectangle_2d(render_field_callback_args)
{
	if (&tag_interface != &this->tag_interface) return;
	ImGui::Dummy({ result->level * indent_size, 0.0f });
	render_field_name_and_information(field, result);
}

uint32_t argb_to_abgr(uint32_t argb_color)
{
	uint32_t bgra_color = _byteswap_ulong(argb_color);
	uint32_t Xbgr_color = bgra_color >> 8;
	uint32_t abgr_color = argb_color & 0xFF00FF00 | Xbgr_color & 0x00FF00FF;
	return abgr_color;
}

void c_blofeld_tag_debugger_tab::render_field_rgb_color(render_field_callback_args)
{
	if (&tag_interface != &this->tag_interface) return;
	ImGui::Dummy({ result->level * indent_size, 0.0f });
	ImGui::SameLine();
	uint32_t argb_color = *reinterpret_cast<uint32_t*>(data);
	uint32_t abgr_color = argb_to_abgr(argb_color);
	ImVec4 float_color = ImGui::ColorConvertU32ToFloat4(abgr_color);
	ImGui::ColorEdit3("", &float_color.x, ImGuiColorEditFlags_Uint8);
	render_field_name_and_information(field, result);
}
void c_blofeld_tag_debugger_tab::render_field_argb_color(render_field_callback_args)
{
	if (&tag_interface != &this->tag_interface) return;
	ImGui::Dummy({ result->level * indent_size, 0.0f });
	ImGui::SameLine();
	uint32_t argb_color = *reinterpret_cast<uint32_t*>(data);
	uint32_t abgr_color = argb_to_abgr(argb_color);
	ImVec4 float_color = ImGui::ColorConvertU32ToFloat4(abgr_color);
	ImGui::ColorEdit4("", &float_color.x, ImGuiColorEditFlags_Uint8);
	render_field_name_and_information(field, result);
}
void c_blofeld_tag_debugger_tab::render_field_real(render_field_callback_args)
{
	if (&tag_interface != &this->tag_interface) return;
	render_field_scalar_type(ImGuiDataType_Float, 1, result->level, data, field, result);
}
void c_blofeld_tag_debugger_tab::render_field_real_fraction(render_field_callback_args)
{
	if (&tag_interface != &this->tag_interface) return;
	render_field_scalar_type(ImGuiDataType_Float, 1, result->level, data, field, result);
}
void c_blofeld_tag_debugger_tab::render_field_real_point_2d(render_field_callback_args)
{
	if (&tag_interface != &this->tag_interface) return;
	render_field_scalar_type(ImGuiDataType_Float, 2, result->level, data, field, result);
}
void c_blofeld_tag_debugger_tab::render_field_real_point_3d(render_field_callback_args)
{
	if (&tag_interface != &this->tag_interface) return;
	render_field_scalar_type(ImGuiDataType_Float, 3, result->level, data, field, result);
}
void c_blofeld_tag_debugger_tab::render_field_real_vector_2d(render_field_callback_args)
{
	if (&tag_interface != &this->tag_interface) return;
	render_field_scalar_type(ImGuiDataType_Float, 2, result->level, data, field, result);
}
void c_blofeld_tag_debugger_tab::render_field_real_vector_3d(render_field_callback_args)
{
	if (&tag_interface != &this->tag_interface) return;
	render_field_scalar_type(ImGuiDataType_Float, 3, result->level, data, field, result);
}
void c_blofeld_tag_debugger_tab::render_field_real_quaternion(render_field_callback_args)
{
	if (&tag_interface != &this->tag_interface) return;
	render_field_scalar_type(ImGuiDataType_Float, 4, result->level, data, field, result);
}
void c_blofeld_tag_debugger_tab::render_field_real_euler_angles_2d(render_field_callback_args)
{
	if (&tag_interface != &this->tag_interface) return;
	render_field_scalar_type(ImGuiDataType_Float, 2, result->level, data, field, result);
}
void c_blofeld_tag_debugger_tab::render_field_real_euler_angles_3d(render_field_callback_args)
{
	if (&tag_interface != &this->tag_interface) return;
	render_field_scalar_type(ImGuiDataType_Float, 3, result->level, data, field, result);
}
void c_blofeld_tag_debugger_tab::render_field_real_plane_2d(render_field_callback_args)
{
	if (&tag_interface != &this->tag_interface) return;
	render_field_scalar_type(ImGuiDataType_Float, 3, result->level, data, field, result);
}
void c_blofeld_tag_debugger_tab::render_field_real_plane_3d(render_field_callback_args)
{
	if (&tag_interface != &this->tag_interface) return;
	render_field_scalar_type(ImGuiDataType_Float, 4, result->level, data, field, result);
}
void c_blofeld_tag_debugger_tab::render_field_real_rgb_color(render_field_callback_args)
{
	if (&tag_interface != &this->tag_interface) return;
	ImGui::Dummy({ result->level * indent_size, 0.0f });
	ImGui::SameLine();
	float* color = reinterpret_cast<float*>(data);
	ImGui::ColorEdit3("", color, ImGuiColorEditFlags_Float);
	render_field_name_and_information(field, result);
}
void c_blofeld_tag_debugger_tab::render_field_real_argb_color(render_field_callback_args)
{
	if (&tag_interface != &this->tag_interface) return;
	ImGui::Dummy({ result->level * indent_size, 0.0f });
	ImGui::SameLine();
	float* raw_color = reinterpret_cast<float*>(data);
	float swizzled_color[4] = { raw_color[1], raw_color[2], raw_color[3], raw_color[0] };
	ImGui::ColorEdit4("", swizzled_color, ImGuiColorEditFlags_Float);
	render_field_name_and_information(field, result);
}
void c_blofeld_tag_debugger_tab::render_field_real_hsv_color(render_field_callback_args)
{
	if (&tag_interface != &this->tag_interface) return;
	ImGui::Dummy({ result->level * indent_size, 0.0f });
	ImGui::SameLine();
	float* color = reinterpret_cast<float*>(data);
	ImGui::ColorEdit3("", color, ImGuiColorEditFlags_Float | ImGuiColorEditFlags_InputHSV);
	render_field_name_and_information(field, result);
}
void c_blofeld_tag_debugger_tab::render_field_real_ahsv_color(render_field_callback_args)
{
	if (&tag_interface != &this->tag_interface) return;
	ImGui::Dummy({ result->level * indent_size, 0.0f });
	ImGui::SameLine();
	float* color = reinterpret_cast<float*>(data);
	ImGui::ColorEdit4("", color, ImGuiColorEditFlags_Float | ImGuiColorEditFlags_InputHSV);
	render_field_name_and_information(field, result);
}
void c_blofeld_tag_debugger_tab::render_field_short_bounds(render_field_callback_args)
{
	if (&tag_interface != &this->tag_interface) return;
	render_field_scalar_type(ImGuiDataType_S16, 2, result->level, data, field, result);
}
void c_blofeld_tag_debugger_tab::render_field_angle_bounds(render_field_callback_args)
{
	if (&tag_interface != &this->tag_interface) return;
	render_field_scalar_type(ImGuiDataType_Float, 2, result->level, data, field, result);
}
void c_blofeld_tag_debugger_tab::render_field_real_bounds(render_field_callback_args)
{
	if (&tag_interface != &this->tag_interface) return;
	render_field_scalar_type(ImGuiDataType_Float, 2, result->level, data, field, result);
}
void c_blofeld_tag_debugger_tab::render_field_real_fraction_bounds(render_field_callback_args)
{
	if (&tag_interface != &this->tag_interface) return;
	render_field_scalar_type(ImGuiDataType_Float, 2, result->level, data, field, result);
}
void c_blofeld_tag_debugger_tab::render_field_tag_reference(render_field_callback_args)
{
	if (&tag_interface != &this->tag_interface) return;
	s_tag_reference& tag_reference = *reinterpret_cast<s_tag_reference*>(data);
	union
	{
		uint64_t group_tag64;
		char group_tag_buffer[8];
	};
	group_tag64 = _byteswap_ulong(tag_reference.group_tag);
	const char* group_tag_str = tag_reference.group_tag == blofeld::INVALID_TAG ? "INVALID_TAG" : group_tag_buffer;

	ImGui::Dummy({ result->level * indent_size, 0.0f });
	ImGui::SameLine();
	const char* tag_name = result->tag_reference_instance ? result->tag_reference_instance->get_path_with_group_name_cstr() : "";
	ImGui::InputText("", (char*)tag_name, strlen(tag_name) + 1, ImGuiInputTextFlags_ReadOnly);
	render_field_name_and_information(field, result);

	const char* format_string = "[group_tag:'%s' name:0x%X name_length:0x%i index:%u datum:0x%X]";
	if (show_hex_values)
	{
		format_string = "[group_tag:0x%X name:0x%X name_length:0x%X index:0x%X datum:0x%X]";
	}
	ImGui::SameLine();
	ImGui::Text(
		format_string,
		group_tag_str,
		tag_reference.name,
		tag_reference.name_length,
		static_cast<uint32_t>(tag_reference.index),
		static_cast<uint32_t>(tag_reference.datum));
}
void c_blofeld_tag_debugger_tab::render_field_block(render_field_callback_args)
{
	if (&tag_interface != &this->tag_interface) return;
	s_tag_block& tag_block = *reinterpret_cast<s_tag_block*>(data);
	ImGui::Dummy({ result->level * indent_size, 0.0f });
	render_field_name_and_information(field, result);
	ImGui::SameLine();
	const char* format_string = "[count:%i address:0x%X definition_address:0x%X]";
	if (show_hex_values)
	{
		format_string = "[count:0x%X address:0x%X definition_address:0x%X]";
	}
	ImGui::Text(format_string, tag_block.count, tag_block.address, tag_block.definition_address);
}
void c_blofeld_tag_debugger_tab::render_field_long_block_flags(render_field_callback_args)
{
	if (&tag_interface != &this->tag_interface) return;
	render_field_scalar_type(ImGuiDataType_U32, 1, result->level, data, field, result);
}
void c_blofeld_tag_debugger_tab::render_field_word_block_flags(render_field_callback_args)
{
	if (&tag_interface != &this->tag_interface) return;
	render_field_scalar_type(ImGuiDataType_U16, 1, result->level, data, field, result);
}
void c_blofeld_tag_debugger_tab::render_field_byte_block_flags(render_field_callback_args)
{
	if (&tag_interface != &this->tag_interface) return;
	render_field_scalar_type(ImGuiDataType_U8, 1, result->level, data, field, result);
}
void c_blofeld_tag_debugger_tab::render_field_char_block_index(render_field_callback_args)
{
	if (&tag_interface != &this->tag_interface) return;
	render_field_scalar_type(ImGuiDataType_U8, 1, result->level, data, field, result);
}
void c_blofeld_tag_debugger_tab::render_field_custom_char_block_index(render_field_callback_args)
{
	if (&tag_interface != &this->tag_interface) return;
	render_field_scalar_type(ImGuiDataType_U8, 1, result->level, data, field, result);
}
void c_blofeld_tag_debugger_tab::render_field_short_block_index(render_field_callback_args)
{
	if (&tag_interface != &this->tag_interface) return;
	render_field_scalar_type(ImGuiDataType_U16, 1, result->level, data, field, result);
}
void c_blofeld_tag_debugger_tab::render_field_custom_short_block_index(render_field_callback_args)
{
	if (&tag_interface != &this->tag_interface) return;
	render_field_scalar_type(ImGuiDataType_U16, 1, result->level, data, field, result);
}
void c_blofeld_tag_debugger_tab::render_field_long_block_index(render_field_callback_args)
{
	if (&tag_interface != &this->tag_interface) return;
	render_field_scalar_type(ImGuiDataType_U32, 1, result->level, data, field, result);
}
void c_blofeld_tag_debugger_tab::render_field_custom_long_block_index(render_field_callback_args)
{
	if (&tag_interface != &this->tag_interface) return;
	render_field_scalar_type(ImGuiDataType_U32, 1, result->level, data, field, result);
}
void c_blofeld_tag_debugger_tab::render_field_data(render_field_callback_args)
{
	if (&tag_interface != &this->tag_interface) return;
	ImGui::Dummy({ result->level * indent_size, 0.0f }); ImGui::SameLine();
	render_field_name_and_information(field, result);
}
void c_blofeld_tag_debugger_tab::render_field_vertex_buffer(render_field_callback_args)
{
	if (&tag_interface != &this->tag_interface) return;
	ImGui::Dummy({ result->level * indent_size, 0.0f }); ImGui::SameLine();
	render_field_name_and_information(field, result);
}
void c_blofeld_tag_debugger_tab::render_field_pad(render_field_callback_args)
{
	if (&tag_interface != &this->tag_interface) return;
	render_field_scalar_type(ImGuiDataType_S8, field.padding, result->level, data, field, result);
}
void c_blofeld_tag_debugger_tab::render_field_useless_pad(render_field_callback_args)
{
	if (&tag_interface != &this->tag_interface) return;
	ImGui::Dummy({ result->level * indent_size, 0.0f }); ImGui::SameLine();
	render_field_name_and_information(field, result);
}
void c_blofeld_tag_debugger_tab::render_field_skip(render_field_callback_args)
{
	if (&tag_interface != &this->tag_interface) return;
	ImGui::Dummy({ result->level * indent_size, 0.0f }); ImGui::SameLine();
	render_field_name_and_information(field, result);
}
void c_blofeld_tag_debugger_tab::render_field_non_cache_runtime_value(render_field_callback_args)
{
	if (&tag_interface != &this->tag_interface) return;
	ImGui::Dummy({ result->level * indent_size, 0.0f }); ImGui::SameLine();
	render_field_name_and_information(field, result);
}
void c_blofeld_tag_debugger_tab::render_field_explanation(render_field_callback_args)
{
	if (&tag_interface != &this->tag_interface) return;
	ImGui::PushStyleColor(ImGuiCol_Text, { 0.8f, 0.6f, 1.0f, 1.0f });
	ImGui::Dummy({ result->level * indent_size, 0.0f });
	render_field_name_and_information(field, result);
	if (field.explanation && strlen(field.explanation) > 0)
	{
		ImGui::Dummy({ result->level * indent_size, 0.0f });
		ImGui::SameLine();
		ImGui::Text("%s", field.explanation);
	}
	ImGui::PopStyleColor();
}
void c_blofeld_tag_debugger_tab::render_field_custom(render_field_callback_args)
{
	if (show_custom_fields)
	{
		if (&tag_interface != &this->tag_interface) return;
		ImGui::Dummy({ result->level * indent_size, 0.0f }); ImGui::SameLine();
		render_field_name_and_information(field, result);
	}
}
void c_blofeld_tag_debugger_tab::render_field_struct(render_field_callback_args)
{
	if (&tag_interface != &this->tag_interface) return;
	ImGui::Dummy({ result->level * indent_size, 0.0f }); ImGui::SameLine();
	render_field_name_and_information(field, result);
}
void c_blofeld_tag_debugger_tab::render_field_array(render_field_callback_args)
{
	if (&tag_interface != &this->tag_interface) return;
	ImGui::Dummy({ result->level * indent_size, 0.0f }); ImGui::SameLine();
	render_field_name_and_information(field, result);
}
void c_blofeld_tag_debugger_tab::render_field_pageable(render_field_callback_args)
{
	if (&tag_interface != &this->tag_interface) return;
	ImGui::Dummy({ result->level * indent_size, 0.0f }); ImGui::SameLine();
	render_field_name_and_information(field, result);

	s_tag_resource& tag_resource = *reinterpret_cast<s_tag_resource*>(data);
	unsigned long absolute_index = tag_resource.resource_handle.get_absolute_index();
	unsigned long identifier = tag_resource.resource_handle.get_identifier();
	unsigned long definition_address = tag_resource.definition_address;

	ImGui::SameLine();

	if (show_hex_values)
	{
		ImGui::Text("absolute_index:0x%X identifier:0x%X definition_address:0x%X", absolute_index, identifier, definition_address);
	}
	else
	{
		ImGui::Text("absolute_index:%u identifier:%u definition_address:%u", absolute_index, identifier, definition_address);
	}
}
void c_blofeld_tag_debugger_tab::render_field_api_interop(render_field_callback_args)
{
	if (&tag_interface != &this->tag_interface) return;
	ImGui::Dummy({ result->level * indent_size, 0.0f }); ImGui::SameLine();
	render_field_name_and_information(field, result);
}
void c_blofeld_tag_debugger_tab::render_field_terminator(render_field_callback_args)
{
	throw; // we shouldn't be rendering this!
}
void c_blofeld_tag_debugger_tab::render_field_byte_integer(render_field_callback_args)
{
	if (&tag_interface != &this->tag_interface) return;
	render_field_scalar_type(ImGuiDataType_U8, 1, result->level, data, field, result);
}
void c_blofeld_tag_debugger_tab::render_field_word_integer(render_field_callback_args)
{
	if (&tag_interface != &this->tag_interface) return;
	render_field_scalar_type(ImGuiDataType_U16, 1, result->level, data, field, result);
}
void c_blofeld_tag_debugger_tab::render_field_dword_integer(render_field_callback_args)
{
	if (&tag_interface != &this->tag_interface) return;
	render_field_scalar_type(ImGuiDataType_U32, 1, result->level, data, field, result);
}
void c_blofeld_tag_debugger_tab::render_field_qword_integer(render_field_callback_args)
{
	if (&tag_interface != &this->tag_interface) return;
	render_field_scalar_type(ImGuiDataType_U64, 1, result->level, data, field, result);
}
void c_blofeld_tag_debugger_tab::render_field_pointer(render_field_callback_args)
{
	if (&tag_interface != &this->tag_interface) return;

	uint32_t pointer_size = get_platform_pointer_size(get_cache_file().get_platform_type());
	switch (pointer_size)
	{
	case 8:
		render_field_scalar_type(ImGuiDataType_U64, 1, result->level, data, field, result, true, "0x%llX");
		break;
	case 4:
		render_field_scalar_type(ImGuiDataType_U32, 1, result->level, data, field, result, true, "0x%X");
		break;
	default:
		ImGui::Text("ERROR: Unknown pointer size %u", pointer_size);
		break;
	}
}

void c_blofeld_tag_debugger_tab::render_field_half(render_field_callback_args)
{
	if (&tag_interface != &this->tag_interface) return;
	uint16_t& raw_half_data = *reinterpret_cast<uint16_t*>(data);
	float half_value = half_to_float(raw_half_data);
	render_field_scalar_type(ImGuiDataType_Float, 1, result->level, reinterpret_cast<char*>(&half_value), field, result);
}

void c_blofeld_tag_debugger_tab::setup_render_callbacks()
{
	using namespace std::placeholders;

	c_gen3_tag_interface* gen3_tag_interface = dynamic_cast<c_gen3_tag_interface*>(&tag_interface);
	if (gen3_tag_interface == nullptr)
	{
		return;
	}

	c_gen3_cache_file& gen3_cache_file = gen3_tag_interface->get_cache_file();

	c_gen3_cache_file_validator* validator = &gen3_cache_file.get_cache_file_validator();

	validator->field_render_callback.register_callback(this, std::bind(&c_blofeld_tag_debugger_tab::render_field_callback, this, _1, _2, _3, _4, _5));

#define register_validation_callback(field_type, callback) \
	validator->field_type_render_callbacks[field_type].register_callback(this, std::bind(&c_blofeld_tag_debugger_tab::callback, this, _1, _2, _3, _4))

	register_validation_callback(blofeld::_field_string, render_field_string);
	register_validation_callback(blofeld::_field_long_string, render_field_long_string);
	register_validation_callback(blofeld::_field_string_id, render_field_string_id);
	register_validation_callback(blofeld::_field_old_string_id, render_field_old_string_id);
	register_validation_callback(blofeld::_field_char_integer, render_field_char_integer);
	register_validation_callback(blofeld::_field_short_integer, render_field_short_integer);
	register_validation_callback(blofeld::_field_long_integer, render_field_long_integer);
	register_validation_callback(blofeld::_field_int64_integer, render_field_int64_integer);
	register_validation_callback(blofeld::_field_angle, render_field_angle);
	register_validation_callback(blofeld::_field_tag, render_field_tag);
	register_validation_callback(blofeld::_field_char_enum, render_field_char_enum);
	register_validation_callback(blofeld::_field_enum, render_field_enum);
	register_validation_callback(blofeld::_field_long_enum, render_field_long_enum);
	register_validation_callback(blofeld::_field_long_flags, render_field_long_flags);
	register_validation_callback(blofeld::_field_word_flags, render_field_word_flags);
	register_validation_callback(blofeld::_field_byte_flags, render_field_byte_flags);
	register_validation_callback(blofeld::_field_point_2d, render_field_point_2d);
	register_validation_callback(blofeld::_field_rectangle_2d, render_field_rectangle_2d);
	register_validation_callback(blofeld::_field_rgb_color, render_field_rgb_color);
	register_validation_callback(blofeld::_field_argb_color, render_field_argb_color);
	register_validation_callback(blofeld::_field_real, render_field_real);
	register_validation_callback(blofeld::_field_real_fraction, render_field_real_fraction);
	register_validation_callback(blofeld::_field_real_point_2d, render_field_real_point_2d);
	register_validation_callback(blofeld::_field_real_point_3d, render_field_real_point_3d);
	register_validation_callback(blofeld::_field_real_vector_2d, render_field_real_vector_2d);
	register_validation_callback(blofeld::_field_real_vector_3d, render_field_real_vector_3d);
	register_validation_callback(blofeld::_field_real_quaternion, render_field_real_quaternion);
	register_validation_callback(blofeld::_field_real_euler_angles_2d, render_field_real_euler_angles_2d);
	register_validation_callback(blofeld::_field_real_euler_angles_3d, render_field_real_euler_angles_3d);
	register_validation_callback(blofeld::_field_real_plane_2d, render_field_real_plane_2d);
	register_validation_callback(blofeld::_field_real_plane_3d, render_field_real_plane_3d);
	register_validation_callback(blofeld::_field_real_rgb_color, render_field_real_rgb_color);
	register_validation_callback(blofeld::_field_real_argb_color, render_field_real_argb_color);
	register_validation_callback(blofeld::_field_real_hsv_color, render_field_real_hsv_color);
	register_validation_callback(blofeld::_field_real_ahsv_color, render_field_real_ahsv_color);
	register_validation_callback(blofeld::_field_short_bounds, render_field_short_bounds);
	register_validation_callback(blofeld::_field_angle_bounds, render_field_angle_bounds);
	register_validation_callback(blofeld::_field_real_bounds, render_field_real_bounds);
	register_validation_callback(blofeld::_field_real_fraction_bounds, render_field_real_fraction_bounds);
	register_validation_callback(blofeld::_field_tag_reference, render_field_tag_reference);
	register_validation_callback(blofeld::_field_block, render_field_block);
	register_validation_callback(blofeld::_field_long_block_flags, render_field_long_block_flags);
	register_validation_callback(blofeld::_field_word_block_flags, render_field_word_block_flags);
	register_validation_callback(blofeld::_field_byte_block_flags, render_field_byte_block_flags);
	register_validation_callback(blofeld::_field_char_block_index, render_field_char_block_index);
	register_validation_callback(blofeld::_field_custom_char_block_index, render_field_custom_char_block_index);
	register_validation_callback(blofeld::_field_short_block_index, render_field_short_block_index);
	register_validation_callback(blofeld::_field_custom_short_block_index, render_field_custom_short_block_index);
	register_validation_callback(blofeld::_field_long_block_index, render_field_long_block_index);
	register_validation_callback(blofeld::_field_custom_long_block_index, render_field_custom_long_block_index);
	register_validation_callback(blofeld::_field_data, render_field_data);
	register_validation_callback(blofeld::_field_vertex_buffer, render_field_vertex_buffer);
	register_validation_callback(blofeld::_field_pad, render_field_pad);
	register_validation_callback(blofeld::_field_useless_pad, render_field_useless_pad);
	register_validation_callback(blofeld::_field_skip, render_field_skip);
	register_validation_callback(blofeld::_field_non_cache_runtime_value, render_field_non_cache_runtime_value);
	register_validation_callback(blofeld::_field_explanation, render_field_explanation);
	register_validation_callback(blofeld::_field_custom, render_field_custom);
	register_validation_callback(blofeld::_field_struct, render_field_struct);
	register_validation_callback(blofeld::_field_array, render_field_array);
	register_validation_callback(blofeld::_field_pageable, render_field_pageable);
	register_validation_callback(blofeld::_field_api_interop, render_field_api_interop);
	register_validation_callback(blofeld::_field_terminator, render_field_terminator);
	register_validation_callback(blofeld::_field_byte_integer, render_field_byte_integer);
	register_validation_callback(blofeld::_field_word_integer, render_field_word_integer);
	register_validation_callback(blofeld::_field_dword_integer, render_field_dword_integer);
	register_validation_callback(blofeld::_field_qword_integer, render_field_qword_integer);
	register_validation_callback(blofeld::_field_pointer, render_field_pointer);
	register_validation_callback(blofeld::_field_half, render_field_half);

#undef register_validation_callback
}

void c_blofeld_tag_debugger_tab::render_impl()
{
	ImDrawList* draw_list = ImGui::GetWindowDrawList();
	float line_height = ImGui::GetTextLineHeight();

	{
		float header_height = line_height * 1.5f;

		ImVec2 start_pos = ImGui::GetCursorScreenPos();
		ImVec2 finish_pos = start_pos;
		finish_pos.x += ImGui::GetContentRegionAvailWidth();
		finish_pos.y += header_height;
		draw_list->AddRectFilled(start_pos, finish_pos, ImGui::ColorConvertFloat4ToU32(MANDRILL_THEME_MENU(1.0f)));


		ImVec2 text_pos = start_pos;
		text_pos.x += 10.0f;
		text_pos.y += (header_height - line_height) / 2.0f;
		draw_list->AddText(text_pos, ImGui::ColorConvertFloat4ToU32(MANDRILL_THEME_TEXT(1.0f)), tag_interface.get_path_with_group_name_cstr());

		finish_pos.x = start_pos.x;
		ImGui::SetCursorScreenPos(finish_pos);
	}
	ImGui::Dummy({ 0.0f, ImGui::GetStyle().ItemSpacing.y });

	static c_custom_tool_render_model custom_tool;
	//custom_tool.render();

	ImVec2 size = ImGui::GetContentRegionAvail();

	ImGuiWindowFlags flags = ImGuiWindowFlags_None;
	flags |= ImGuiWindowFlags_AlwaysHorizontalScrollbar;
	flags |= ImGuiWindowFlags_AlwaysVerticalScrollbar;
	ImGui::BeginChild("##fields", size, false, flags);

	viewport_size = ImGui::GetContentRegionAvail();

	if (c_gen3_tag_interface* gen3_tag_interface = dynamic_cast<c_gen3_tag_interface*>(&tag_interface))
	{
		bool is_struct_valid;
		bool is_tag_valid;

		c_gen3_cache_file& cache_file = gen3_tag_interface->get_cache_file();
		c_gen3_cache_file_validator& validator = cache_file.get_cache_file_validator();
		validator.validate_tag_instance(*gen3_tag_interface, true, is_struct_valid, is_tag_valid);
	}
	else
	{
		ImGui::Text("Debugging not yet supported for this tag interface");
	}

	ImGui::EndChild();
}

void c_blofeld_tag_debugger_tab::render_menu_gui_impl(e_menu_render_type menu_render_type)
{
	if (menu_render_type == _menu_render_type_root)
	{
		if (c_mandrill_user_interface::use_developer_features && ImGui::BeginMenu("Debugging"))
		{
			if (ImGui::MenuItem(show_hex_values ? "Show Decimal Values" : "Show Hex Values"))
			{
				show_hex_values = !show_hex_values;
				c_settings::write_boolean(_settings_section_mandrill, k_show_hex_values_setting, show_hex_values);
			}
			if (ImGui::MenuItem(show_hex_values ? "Show Decimal Values (Float)" : "Show Hex Values (Float)"))
			{
				show_hex_values_float = !show_hex_values_float;
				c_settings::write_boolean(_settings_section_mandrill, k_show_hex_values_float_setting, show_hex_values_float);
			}
			if (ImGui::MenuItem(show_broken_block_data ? "Hide Broken Block Data" : "Show Broken Block Data"))
			{
				show_broken_block_data = !show_broken_block_data;
				c_settings::write_boolean(_settings_section_mandrill, k_show_broken_block_data_setting, show_broken_block_data);
			}
			if (ImGui::MenuItem(show_field_offsets ? "Hide Field Offsets" : "Show Field Offsets"))
			{
				show_field_offsets = !show_field_offsets;
				c_settings::write_boolean(_settings_section_mandrill, k_show_field_offsets_setting, show_field_offsets);
			}
			if (ImGui::MenuItem(show_custom_fields ? "Hide Custom Fields" : "Show Custom Fields"))
			{
				show_custom_fields = !show_custom_fields;
				c_settings::write_boolean(_settings_section_mandrill, k_show_custom_fields_setting, show_custom_fields);
			}
			if (ImGui::MenuItem(use_absolute_offsets ? "Use Relative Offsets" : "Use Absolute Offsets"))
			{
				use_absolute_offsets = !use_absolute_offsets;
				c_settings::write_boolean(_settings_section_mandrill, k_use_absolute_offsets_setting, use_absolute_offsets);
			}


			ImGui::EndMenu();
		}

		for (c_mandrill_tab& tab : c_reference_loop(children.data(), children.size()))
		{
			tab.render_menu_gui(_menu_render_type_root);
		}
	}
	if (menu_render_type == _menu_render_type_child)
	{

	}
}

void c_blofeld_tag_debugger_tab::render_file_dialogue_gui_impl()
{

}

void c_blofeld_tag_debugger_tab::render_game_layer_impl()
{

}

