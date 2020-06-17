#include "mandrilllib-private-pch.h"
#include <TagValidate\field_validation_result.h>

bool c_blofeld_tag_debugger_tab::show_hex_values = false;
bool c_blofeld_tag_debugger_tab::show_hex_values_float = false;
bool c_blofeld_tag_debugger_tab::show_broken_block_data = false;

float indent_size = 20.0f;

c_blofeld_tag_debugger_tab::c_blofeld_tag_debugger_tab(c_tag_interface& tag_interface, c_mandrill_tab& parent) :
	c_mandrill_tab("Tag Debugger", "Blofeld Tag Debugger", &parent, false),
	tag_interface(tag_interface),
	validator(nullptr)
{
	setup_render_callbacks();
}

c_blofeld_tag_debugger_tab::~c_blofeld_tag_debugger_tab()
{

}

void c_blofeld_tag_debugger_tab::render_field_scalar_type(ImGuiDataType data_type, uint32_t count, int level, char* data, blofeld::e_field field_type, const char* field_name, const char* format)
{
	ImGuiInputTextFlags flags = ImGuiInputTextFlags_ReadOnly;
	if (show_hex_values && data_type != ImGuiDataType_Float)
	{
		flags |= ImGuiInputTextFlags_CharsHexadecimal;
	}
	if (show_hex_values_float && data_type == ImGuiDataType_Float)
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

	const ImGuiDataTypeInfo* info = ImGui::DataTypeGetInfo(data_type);
	ImGui::Dummy({ level * indent_size, 0.0f });
	ImGui::SameLine();
	ImGui::InputScalarN("", data_type, data, (int)count, nullptr, nullptr, format, ImGuiInputTextFlags_ReadOnly);
	ImGui::SameLine();
	ImGui::Text("%s %s", blofeld::field_to_string(field_type), field_name);
}

template<typename t_raw_value>
void c_blofeld_tag_debugger_tab::render_field_enum_type(int level, char* data, const blofeld::s_tag_field& field)
{
	const char* format_string = "raw: %u ";
	if (show_hex_values)
	{
		format_string = "raw: 0x%X ";
	}

	ImGui::Dummy({ level * indent_size, 0.0f });
	ImGui::SameLine();
	byte& raw_value = *reinterpret_cast<byte*>(data);
	c_fixed_string_256 enum_value;
	enum_value.format(format_string, static_cast<uint32_t>(raw_value));
	if (raw_value < field.string_list_definition->count)
	{
		enum_value += field.string_list_definition->strings[raw_value];
	}
	ImGui::InputText("", enum_value.str(), 256, ImGuiInputTextFlags_ReadOnly);
	ImGui::SameLine();
	ImGui::Text("%s %s", blofeld::field_to_string(field.field_type), field.name);
}

void c_blofeld_tag_debugger_tab::render_field_callback(render_field_callback_args, c_callback<void(render_field_callback_args)>& render_field_callback)
{
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

	render_field_callback(data, field, result);

	ImGui::PopStyleColor();
	ImGui::PopID();
}

void c_blofeld_tag_debugger_tab::render_field_string(render_field_callback_args)
{
	ImGui::Dummy({ result->level * indent_size, 0.0f });
	ImGui::SameLine();
	ImGui::InputText("", data, 32, ImGuiInputTextFlags_ReadOnly);
	ImGui::SameLine();
	ImGui::Text("%s %s", blofeld::field_to_string(field.field_type), field.name);
}
void c_blofeld_tag_debugger_tab::render_field_long_string(render_field_callback_args)
{
	ImGui::Dummy({ result->level * indent_size, 0.0f });
	ImGui::SameLine();
	ImGui::InputText("", data, 256, ImGuiInputTextFlags_ReadOnly);
	ImGui::SameLine();
	ImGui::Text("%s %s", blofeld::field_to_string(field.field_type), field.name);
}
void c_blofeld_tag_debugger_tab::render_field_string_id(render_field_callback_args)
{
	ImGui::Dummy({ result->level * indent_size, 0.0f });
	ImGui::SameLine();
	const char* string_id = result->string_id_value ? result->string_id_value : "<error invalid string id>";
	ImGui::InputText("", (char*)string_id, strlen(string_id) + 1, ImGuiInputTextFlags_ReadOnly);
	ImGui::SameLine();
	ImGui::Text("%s %s", blofeld::field_to_string(field.field_type), field.name);
}
void c_blofeld_tag_debugger_tab::render_field_old_string_id(render_field_callback_args)
{
	ImGui::Dummy({ result->level * indent_size, 0.0f });
	ImGui::SameLine();
	int& old_string_id = *reinterpret_cast<int*>(data);
	ImGui::InputInt("", &old_string_id, 1, 100, ImGuiInputTextFlags_ReadOnly);
	ImGui::SameLine();
	ImGui::Text("%s %s", blofeld::field_to_string(field.field_type), field.name);
}
void c_blofeld_tag_debugger_tab::render_field_char_integer(render_field_callback_args)
{
	render_field_scalar_type(ImGuiDataType_S8, 1, result->level, data, field.field_type, field.name);
}
void c_blofeld_tag_debugger_tab::render_field_short_integer(render_field_callback_args)
{
	render_field_scalar_type(ImGuiDataType_S16, 1, result->level, data, field.field_type, field.name);
}
void c_blofeld_tag_debugger_tab::render_field_long_integer(render_field_callback_args)
{
	render_field_scalar_type(ImGuiDataType_S32, 1, result->level, data, field.field_type, field.name);
}
void c_blofeld_tag_debugger_tab::render_field_int64_integer(render_field_callback_args)
{
	render_field_scalar_type(ImGuiDataType_S64, 1, result->level, data, field.field_type, field.name);
}
void c_blofeld_tag_debugger_tab::render_field_angle(render_field_callback_args)
{
	render_field_scalar_type(ImGuiDataType_Float, 1, result->level, data, field.field_type, field.name);
}
void c_blofeld_tag_debugger_tab::render_field_tag(render_field_callback_args)
{
	render_field_scalar_type(ImGuiDataType_U32, 1, result->level, data, field.field_type, field.name);
}
void c_blofeld_tag_debugger_tab::render_field_char_enum(render_field_callback_args)
{
	render_field_enum_type<byte>(result->level, data, field);
}
void c_blofeld_tag_debugger_tab::render_field_enum(render_field_callback_args)
{
	render_field_enum_type<word>(result->level, data, field);
}
void c_blofeld_tag_debugger_tab::render_field_long_enum(render_field_callback_args)
{
	render_field_enum_type<unsigned long>(result->level, data, field);
}
void c_blofeld_tag_debugger_tab::render_field_long_flags(render_field_callback_args)
{
	render_field_scalar_type(ImGuiDataType_U32, 1, result->level, data, field.field_type, field.name);
}
void c_blofeld_tag_debugger_tab::render_field_word_flags(render_field_callback_args)
{
	render_field_scalar_type(ImGuiDataType_U16, 1, result->level, data, field.field_type, field.name);
}
void c_blofeld_tag_debugger_tab::render_field_byte_flags(render_field_callback_args)
{
	render_field_scalar_type(ImGuiDataType_U8, 1, result->level, data, field.field_type, field.name);
}
void c_blofeld_tag_debugger_tab::render_field_point_2d(render_field_callback_args)
{
	ImGui::Dummy({ result->level * indent_size, 0.0f }); ImGui::SameLine(); ImGui::Text("%s %s", blofeld::field_to_string(field.field_type), field.name);
}
void c_blofeld_tag_debugger_tab::render_field_rectangle_2d(render_field_callback_args)
{
	ImGui::Dummy({ result->level * indent_size, 0.0f }); ImGui::SameLine(); ImGui::Text("%s %s", blofeld::field_to_string(field.field_type), field.name);
}
void c_blofeld_tag_debugger_tab::render_field_rgb_color(render_field_callback_args)
{
	ImGui::Dummy({ result->level * indent_size, 0.0f }); ImGui::SameLine(); ImGui::Text("%s %s", blofeld::field_to_string(field.field_type), field.name);
}
void c_blofeld_tag_debugger_tab::render_field_argb_color(render_field_callback_args)
{
	ImGui::Dummy({ result->level * indent_size, 0.0f }); ImGui::SameLine(); ImGui::Text("%s %s", blofeld::field_to_string(field.field_type), field.name);
}
void c_blofeld_tag_debugger_tab::render_field_real(render_field_callback_args)
{
	render_field_scalar_type(ImGuiDataType_Float, 1, result->level, data, field.field_type, field.name);
}
void c_blofeld_tag_debugger_tab::render_field_real_fraction(render_field_callback_args)
{
	render_field_scalar_type(ImGuiDataType_Float, 1, result->level, data, field.field_type, field.name);
}
void c_blofeld_tag_debugger_tab::render_field_real_point_2d(render_field_callback_args)
{
	render_field_scalar_type(ImGuiDataType_Float, 2, result->level, data, field.field_type, field.name);
}
void c_blofeld_tag_debugger_tab::render_field_real_point_3d(render_field_callback_args)
{
	render_field_scalar_type(ImGuiDataType_Float, 3, result->level, data, field.field_type, field.name);
}
void c_blofeld_tag_debugger_tab::render_field_real_vector_2d(render_field_callback_args)
{
	render_field_scalar_type(ImGuiDataType_Float, 2, result->level, data, field.field_type, field.name);
}
void c_blofeld_tag_debugger_tab::render_field_real_vector_3d(render_field_callback_args)
{
	render_field_scalar_type(ImGuiDataType_Float, 3, result->level, data, field.field_type, field.name);
}
void c_blofeld_tag_debugger_tab::render_field_real_quaternion(render_field_callback_args)
{
	render_field_scalar_type(ImGuiDataType_Float, 4, result->level, data, field.field_type, field.name);
}
void c_blofeld_tag_debugger_tab::render_field_real_euler_angles_2d(render_field_callback_args)
{
	render_field_scalar_type(ImGuiDataType_Float, 2, result->level, data, field.field_type, field.name);
}
void c_blofeld_tag_debugger_tab::render_field_real_euler_angles_3d(render_field_callback_args)
{
	render_field_scalar_type(ImGuiDataType_Float, 3, result->level, data, field.field_type, field.name);
}
void c_blofeld_tag_debugger_tab::render_field_real_plane_2d(render_field_callback_args)
{
	render_field_scalar_type(ImGuiDataType_Float, 3, result->level, data, field.field_type, field.name);
}
void c_blofeld_tag_debugger_tab::render_field_real_plane_3d(render_field_callback_args)
{
	render_field_scalar_type(ImGuiDataType_Float, 4, result->level, data, field.field_type, field.name);
}
void c_blofeld_tag_debugger_tab::render_field_real_rgb_color(render_field_callback_args)
{
	ImGui::Dummy({ result->level * indent_size, 0.0f });
	ImGui::SameLine();
	ImVec4 color = ImGui::ColorConvertU32ToFloat4(*reinterpret_cast<ImU32*>(data));
	ImGui::ColorEdit3("", &color.x, ImGuiColorEditFlags_Float);
	ImGui::SameLine();
	ImGui::Text("%s %s", blofeld::field_to_string(field.field_type), field.name);
}
void c_blofeld_tag_debugger_tab::render_field_real_argb_color(render_field_callback_args)
{
	ImGui::Dummy({ result->level * indent_size, 0.0f });
	ImGui::SameLine();
	ImVec4 color = ImGui::ColorConvertU32ToFloat4(*reinterpret_cast<ImU32*>(data));
	ImGui::ColorEdit4("", &color.x, ImGuiColorEditFlags_Float);
	ImGui::SameLine();
	ImGui::Text("%s %s", blofeld::field_to_string(field.field_type), field.name);
}
void c_blofeld_tag_debugger_tab::render_field_real_hsv_color(render_field_callback_args)
{
	ImGui::Dummy({ result->level * indent_size, 0.0f });
	ImGui::SameLine();
	ImVec4 color = ImGui::ColorConvertU32ToFloat4(*reinterpret_cast<ImU32*>(data));
	ImGui::ColorEdit3("", &color.x, ImGuiColorEditFlags_Float | ImGuiColorEditFlags_InputHSV);
	ImGui::SameLine();
	ImGui::Text("%s %s", blofeld::field_to_string(field.field_type), field.name);
}
void c_blofeld_tag_debugger_tab::render_field_real_ahsv_color(render_field_callback_args)
{
	ImGui::Dummy({ result->level * indent_size, 0.0f });
	ImGui::SameLine();
	ImVec4 color = ImGui::ColorConvertU32ToFloat4(*reinterpret_cast<ImU32*>(data));
	ImGui::ColorEdit4("", &color.x, ImGuiColorEditFlags_Float | ImGuiColorEditFlags_InputHSV);
	ImGui::SameLine();
	ImGui::Text("%s %s", blofeld::field_to_string(field.field_type), field.name);
}
void c_blofeld_tag_debugger_tab::render_field_short_bounds(render_field_callback_args)
{
	render_field_scalar_type(ImGuiDataType_S16, 2, result->level, data, field.field_type, field.name);
}
void c_blofeld_tag_debugger_tab::render_field_angle_bounds(render_field_callback_args)
{
	render_field_scalar_type(ImGuiDataType_Float, 2, result->level, data, field.field_type, field.name);
}
void c_blofeld_tag_debugger_tab::render_field_real_bounds(render_field_callback_args)
{
	render_field_scalar_type(ImGuiDataType_Float, 2, result->level, data, field.field_type, field.name);
}
void c_blofeld_tag_debugger_tab::render_field_real_fraction_bounds(render_field_callback_args)
{
	render_field_scalar_type(ImGuiDataType_Float, 2, result->level, data, field.field_type, field.name);
}
void c_blofeld_tag_debugger_tab::render_field_tag_reference(render_field_callback_args)
{
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
	ImGui::SameLine();
	ImGui::Text("%s %s", blofeld::field_to_string(field.field_type), field.name);

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
	s_tag_block& tag_block = *reinterpret_cast<s_tag_block*>(data);
	ImGui::Dummy({ result->level * indent_size, 0.0f });
	ImGui::SameLine();
	ImGui::Text("%s %s", blofeld::field_to_string(field.field_type), field.name);
	ImGui::SameLine();
	const char* format_string = "[count:%i address:0x%X definition_address:0x%i]";
	if (show_hex_values)
	{
		format_string = "[count:0x%X address:0x%X definition_address:0x%X]";
	}
	ImGui::Text(format_string, tag_block.count, tag_block.address, tag_block.definition_address);
}
void c_blofeld_tag_debugger_tab::render_field_long_block_flags(render_field_callback_args)
{
	render_field_scalar_type(ImGuiDataType_U32, 1, result->level, data, field.field_type, field.name);
}
void c_blofeld_tag_debugger_tab::render_field_word_block_flags(render_field_callback_args)
{
	render_field_scalar_type(ImGuiDataType_U16, 1, result->level, data, field.field_type, field.name);
}
void c_blofeld_tag_debugger_tab::render_field_byte_block_flags(render_field_callback_args)
{
	render_field_scalar_type(ImGuiDataType_U8, 1, result->level, data, field.field_type, field.name);
}
void c_blofeld_tag_debugger_tab::render_field_char_block_index(render_field_callback_args)
{
	render_field_scalar_type(ImGuiDataType_U8, 1, result->level, data, field.field_type, field.name);
}
void c_blofeld_tag_debugger_tab::render_field_custom_char_block_index(render_field_callback_args)
{
	render_field_scalar_type(ImGuiDataType_U8, 1, result->level, data, field.field_type, field.name);
}
void c_blofeld_tag_debugger_tab::render_field_short_block_index(render_field_callback_args)
{
	render_field_scalar_type(ImGuiDataType_U16, 1, result->level, data, field.field_type, field.name);
}
void c_blofeld_tag_debugger_tab::render_field_custom_short_block_index(render_field_callback_args)
{
	render_field_scalar_type(ImGuiDataType_U16, 1, result->level, data, field.field_type, field.name);
}
void c_blofeld_tag_debugger_tab::render_field_long_block_index(render_field_callback_args)
{
	render_field_scalar_type(ImGuiDataType_U32, 1, result->level, data, field.field_type, field.name);
}
void c_blofeld_tag_debugger_tab::render_field_custom_long_block_index(render_field_callback_args)
{
	render_field_scalar_type(ImGuiDataType_U32, 1, result->level, data, field.field_type, field.name);
}
void c_blofeld_tag_debugger_tab::render_field_data(render_field_callback_args)
{
	ImGui::Dummy({ result->level * indent_size, 0.0f }); ImGui::SameLine(); ImGui::Text("%s %s", blofeld::field_to_string(field.field_type), field.name);
}
void c_blofeld_tag_debugger_tab::render_field_vertex_buffer(render_field_callback_args)
{
	ImGui::Dummy({ result->level * indent_size, 0.0f }); ImGui::SameLine(); ImGui::Text("%s %s", blofeld::field_to_string(field.field_type), field.name);
}
void c_blofeld_tag_debugger_tab::render_field_pad(render_field_callback_args)
{
	render_field_scalar_type(ImGuiDataType_S8, field.padding, result->level, data, field.field_type, field.name);
}
void c_blofeld_tag_debugger_tab::render_field_useless_pad(render_field_callback_args)
{
	ImGui::Dummy({ result->level * indent_size, 0.0f }); ImGui::SameLine(); ImGui::Text("%s %s", blofeld::field_to_string(field.field_type), field.name);
}
void c_blofeld_tag_debugger_tab::render_field_skip(render_field_callback_args)
{
	ImGui::Dummy({ result->level * indent_size, 0.0f }); ImGui::SameLine(); ImGui::Text("%s %s", blofeld::field_to_string(field.field_type), field.name);
}
void c_blofeld_tag_debugger_tab::render_field_non_cache_runtime_value(render_field_callback_args)
{
	ImGui::Dummy({ result->level * indent_size, 0.0f }); ImGui::SameLine(); ImGui::Text("%s %s", blofeld::field_to_string(field.field_type), field.name);
}
void c_blofeld_tag_debugger_tab::render_field_explanation(render_field_callback_args)
{
	ImGui::PushStyleColor(ImGuiCol_Text, { 0.8f, 0.6f, 1.0f, 1.0f });
	ImGui::Dummy({ result->level * indent_size, 0.0f });
	ImGui::SameLine();
	ImGui::Text("%s %s", blofeld::field_to_string(field.field_type), field.name);
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
	ImGui::Dummy({ result->level * indent_size, 0.0f }); ImGui::SameLine(); ImGui::Text("%s %s", blofeld::field_to_string(field.field_type), field.name);
}
void c_blofeld_tag_debugger_tab::render_field_struct(render_field_callback_args)
{
	ImGui::Dummy({ result->level * indent_size, 0.0f }); ImGui::SameLine(); ImGui::Text("%s %s", blofeld::field_to_string(field.field_type), field.name);
}
void c_blofeld_tag_debugger_tab::render_field_array(render_field_callback_args)
{
	ImGui::Dummy({ result->level * indent_size, 0.0f }); ImGui::SameLine(); ImGui::Text("%s %s", blofeld::field_to_string(field.field_type), field.name);
}
void c_blofeld_tag_debugger_tab::render_field_pageable(render_field_callback_args)
{
	ImGui::Dummy({ result->level * indent_size, 0.0f }); ImGui::SameLine(); ImGui::Text("%s %s", blofeld::field_to_string(field.field_type), field.name);
}
void c_blofeld_tag_debugger_tab::render_field_api_interop(render_field_callback_args)
{
	ImGui::Dummy({ result->level * indent_size, 0.0f }); ImGui::SameLine(); ImGui::Text("%s %s", blofeld::field_to_string(field.field_type), field.name);
}
void c_blofeld_tag_debugger_tab::render_field_terminator(render_field_callback_args)
{
	throw; // we shouldn't be rendering this!
}
void c_blofeld_tag_debugger_tab::render_field_byte_integer(render_field_callback_args)
{
	render_field_scalar_type(ImGuiDataType_U8, 1, result->level, data, field.field_type, field.name);
}
void c_blofeld_tag_debugger_tab::render_field_word_integer(render_field_callback_args)
{
	render_field_scalar_type(ImGuiDataType_U16, 1, result->level, data, field.field_type, field.name);
}
void c_blofeld_tag_debugger_tab::render_field_dword_integer(render_field_callback_args)
{
	render_field_scalar_type(ImGuiDataType_U32, 1, result->level, data, field.field_type, field.name);
}
void c_blofeld_tag_debugger_tab::render_field_qword_integer(render_field_callback_args)
{
	render_field_scalar_type(ImGuiDataType_U64, 1, result->level, data, field.field_type, field.name);
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

	validator = new c_gen3_cache_file_validator(gen3_cache_file);

	validator->field_render_callback.register_callback(this, std::bind(&c_blofeld_tag_debugger_tab::render_field_callback, this, _1, _2, _3, _4));

#define register_validation_callback(field_type, callback) \
	validator->field_type_render_callbacks[field_type].register_callback(this, std::bind(&c_blofeld_tag_debugger_tab::callback, this, _1, _2, _3))

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

	{
		float header_height = line_height * 1.75f;

		ImVec2 start_pos = ImGui::GetCursorScreenPos();
		ImVec2 finish_pos = start_pos;
		finish_pos.x += ImGui::GetContentRegionAvailWidth();
		finish_pos.y += header_height;
		draw_list->AddRectFilled(start_pos, finish_pos, ImGui::ColorConvertFloat4ToU32(MANDRILL_THEME_MENU(0.5f)));

		ImVec2 text_pos = start_pos;
		text_pos.x += 10.0f;
		text_pos.y += (header_height - line_height) / 2.0f;
		ImGui::SetCursorScreenPos(text_pos);

		{
			ImGui::Text("User view:");
			ImGui::SameLine();
			ImGui::SetNextItemWidth(250.0f);
			if (ImGui::BeginCombo("##userview", "<All>"))
			{
				ImGui::EndCombo();
			}
			ImGui::SameLine();
			ImGui::Button("...");
		}

		float field_search_width = ImGui::CalcTextSize("#").x * 30.0f;
		ImVec2 search_pos = text_pos;
		{
			float content_width = 0.0f;
			content_width += ImGui::CalcTextSize("search fields").x + ImGui::GetStyle().ItemSpacing.x; // "search fields"
			content_width += field_search_width + ImGui::GetStyle().ItemSpacing.x; // "text input"
			content_width += ImGui::CalcTextSize(ICON_FA_ARROW_LEFT).x + ImGui::GetStyle().FramePadding.x * 2.0f + ImGui::GetStyle().ItemSpacing.x; // "button1"
			content_width += ImGui::CalcTextSize(ICON_FA_ARROW_RIGHT).x + ImGui::GetStyle().FramePadding.x * 2.0f + ImGui::GetStyle().ItemSpacing.x; // "button2"
			content_width += ImGui::CalcTextSize(ICON_FA_TIMES).x + ImGui::GetStyle().FramePadding.x * 2.0f + ImGui::GetStyle().ItemSpacing.x; // "button3"

			search_pos.x = finish_pos.x - content_width;
		}
		ImGui::SetCursorScreenPos(search_pos);

		ImGui::Text("search fields");
		ImGui::SameLine();
		char field_search_buffer[256]{};
		ImGui::SetNextItemWidth(field_search_width);
		ImGui::InputText("##search_input", field_search_buffer, _countof(field_search_buffer));
		ImGui::SameLine();
		ImGui::Button(ICON_FA_ARROW_LEFT);
		ImGui::SameLine();
		ImGui::Button(ICON_FA_ARROW_RIGHT);
		ImGui::SameLine();
		ImGui::Button(ICON_FA_TIMES);

		finish_pos.x = start_pos.x;
		ImGui::SetCursorScreenPos(finish_pos);
	}

	{
		float header_height = line_height * 1.75f;

		ImVec2 start_pos = ImGui::GetCursorScreenPos();
		ImVec2 finish_pos = start_pos;
		finish_pos.x += ImGui::GetContentRegionAvailWidth();
		finish_pos.y += header_height;
		draw_list->AddRectFilled(start_pos, finish_pos, ImGui::ColorConvertFloat4ToU32(MANDRILL_THEME_MENU(0.5f)));

		ImVec2 text_pos = start_pos;
		text_pos.x += 10.0f;
		text_pos.y += (header_height - line_height) / 2.0f;
		ImGui::SetCursorScreenPos(text_pos);
		ImGui::Button("Quick Preview");
		ImGui::SameLine(0.0f, 25.0f);
		static bool use_live_mode = false;
		ImGui::Checkbox("Use Live Mode", &use_live_mode);
		ImGui::SameLine(0.0f, 25.0f);
		ImGui::Text("Status:");
		ImGui::SameLine();
		ImGui::Text("Ready");


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

	if (c_gen3_tag_interface* gen3_tag_interface = dynamic_cast<c_gen3_tag_interface*>(&tag_interface))
	{
		validator->validate_tag_instance(*gen3_tag_interface, show_broken_block_data);
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
		for (c_mandrill_tab& tab : c_reference_loop(children.data(), children.size()))
		{
			tab.render_menu_gui(_menu_render_type_root);
		}
	}
	if (menu_render_type == _menu_render_type_child)
	{
		if (ImGui::MenuItem(show_hex_values ? "Show Decimal Values" : "Show Hex Values"))
		{
			show_hex_values = !show_hex_values;
		}
		if (ImGui::MenuItem(show_hex_values ? "Show Decimal Values (Float)" : "Show Hex Values (Float)"))
		{
			show_hex_values_float = !show_hex_values_float;
		}
		if (ImGui::MenuItem(show_broken_block_data ? "Show Broken Block Data" : "Show Broken Block Data"))
		{
			show_broken_block_data = !show_broken_block_data;
		}
		
	}
}

void c_blofeld_tag_debugger_tab::render_file_dialogue_gui_impl()
{

}

void c_blofeld_tag_debugger_tab::render_game_layer_impl()
{

}

