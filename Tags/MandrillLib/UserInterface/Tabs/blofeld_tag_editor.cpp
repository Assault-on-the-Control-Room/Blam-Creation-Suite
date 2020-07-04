#include "mandrilllib-private-pch.h"

c_blofeld_tag_editor_tab::c_blofeld_tag_editor_tab(c_tag_interface& tag_interface, c_mandrill_tab& parent) :
	c_mandrill_tab("Tag Editor", "Blofeld Tag Definition Debug", &parent, false),
	tag_interface(tag_interface),
	cache_file(tag_interface.get_cache_file()),
	viewport_size()
{

}

c_blofeld_tag_editor_tab::~c_blofeld_tag_editor_tab()
{

}

uint32_t c_blofeld_tag_editor_tab::copy_data_recursively(const char* const local_tag_memory, char* const game_tag_memory, const blofeld::s_tag_struct_definition& struct_definition)
{
	uint32_t structure_size = blofeld::calculate_struct_size(cache_file.get_engine_type(), cache_file.get_platform_type(), _build_not_set, struct_definition);

	e_engine_type engine_type = tag_interface.get_cache_file().get_engine_type();
	e_platform_type platform_type = tag_interface.get_cache_file().get_platform_type();

	uint32_t bytes_traversed = 0;
	int32_t field_index = 0;
	for (const blofeld::s_tag_field* current_field = struct_definition.fields; current_field->field_type != blofeld::_field_terminator; (current_field++, field_index++))
	{
		const char* const current_local_tag_memory_position = local_tag_memory + bytes_traversed;
		char* const current_game_tag_memory_position = game_tag_memory + bytes_traversed;

		uint32_t field_skip_count;
		if (skip_tag_field_version(*current_field, engine_type, platform_type, _build_not_set, field_skip_count))
		{
			current_field += field_skip_count;
			continue;
		}

		uint32_t field_size = blofeld::get_blofeld_field_size(platform_type, current_field->field_type);

		switch (current_field->field_type)
		{
		case blofeld::_field_pad: field_size = current_field->padding; break;
		case blofeld::_field_useless_pad: /*field_size = current_field->padding;*/ break;
		case blofeld::_field_skip: field_size = current_field->length; break;
		case blofeld::_field_struct:
		{
			uint32_t structure_size = blofeld::calculate_struct_size(engine_type, platform_type, _build_not_set, *current_field->struct_definition);
			field_size += structure_size;
			break;
		}
		case blofeld::_field_array:
		{
			const blofeld::s_tag_array_definition& array_definition = *current_field->array_definition;
			uint32_t structure_size = blofeld::calculate_struct_size(engine_type, platform_type, _build_not_set, array_definition.struct_definition);
			field_size += structure_size * array_definition.count(cache_file.get_engine_type());
			break;
		}
		case blofeld::_field_block:
		{
			const s_tag_block& tag_block = *reinterpret_cast<const s_tag_block*>(current_local_tag_memory_position);

			const char* const local_tag_block_memory = cache_file.get_tag_block_data(tag_block);

			if (local_tag_block_memory)
			{
				intptr_t memory_delta = local_tag_block_memory - current_local_tag_memory_position; // #TODO: fix this madness
				char* const game_tag_block_memory = current_game_tag_memory_position + memory_delta;

				uint32_t const block_structure_size = blofeld::calculate_struct_size(cache_file.get_engine_type(), cache_file.get_platform_type(), _build_not_set, current_field->block_definition->struct_definition);
				uint32_t block_bytes_traversed = 0;

				//int tag_block_is_same = memcmp(local_tag_block_memory, game_tag_block_memory, block_structure_size * tag_block.count);
				//ASSERT(tag_block_is_same == 0);

				for (uint32_t i = 0; i < tag_block.count; i++)
				{
					const char* const current_local_tag_memory_position = local_tag_block_memory + block_bytes_traversed;
					char* const current_game_tag_memory_position = game_tag_block_memory + block_bytes_traversed;

					copy_data_recursively(current_local_tag_memory_position, current_game_tag_memory_position, current_field->block_definition->struct_definition);

					block_bytes_traversed += block_structure_size;
				}
			}

			debug_point;
			break;
		}
		}

		//int struct_is_same = memcmp(current_game_tag_memory_position, current_local_tag_memory_position, field_size);
		//ASSERT(struct_is_same == 0);
		memcpy(current_game_tag_memory_position, current_local_tag_memory_position, field_size);
		bytes_traversed += field_size;
	}
	structure_size;
	//offset += structure_size;

	debug_point;

	ASSERT(bytes_traversed == structure_size);

	return structure_size;
}

void c_blofeld_tag_editor_tab::render_impl()
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

		if (ImGui::Button("Quick Preview"))
		{
			if (c_mandrill_user_interface::s_get_tag_game_memory)
			{
				char* local_tag_memory = tag_interface.get_data();
				char* game_tag_memory = c_mandrill_user_interface::s_get_tag_game_memory(tag_interface.get_index());
				if (local_tag_memory && game_tag_memory)
				{
					copy_data_recursively(local_tag_memory, game_tag_memory, tag_interface.get_blofeld_reflection_data()->block_definition.struct_definition);
				}
			}
		}

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

	viewport_size = ImGui::GetContentRegionAvail();

	if (tag_interface.is_null())
	{
		ImGui::Text("This tag is null.");
	}
	else if (const blofeld::s_tag_group* blofeld_reflection = tag_interface.get_blofeld_reflection_data())
	{
		bool is_valid = true;
		if (c_gen3_tag_interface* gen3_tag_interface = dynamic_cast<c_gen3_tag_interface*>(&tag_interface))
		{
			is_valid = gen3_tag_interface->get_is_tag_valid();
		}

		if (is_valid)
		{
			render_tag_group(tag_interface.get_data(), *blofeld_reflection);
		}
		else
		{
			ImGui::Text("Tag instance is not valid");
		}
	}
	else
	{
		ImGui::Text("No reflection information.");
	}

	ImGui::EndChild();
}

void c_blofeld_tag_editor_tab::render_menu_gui_impl(e_menu_render_type menu_render_type)
{

}

void c_blofeld_tag_editor_tab::render_file_dialogue_gui_impl()
{

}

void c_blofeld_tag_editor_tab::render_game_layer_impl()
{

}

static bool field_type_to_imgui_data_type(blofeld::e_field field_type, ImGuiDataType& data_type, int& components)
{
	switch (field_type)
	{
	case blofeld::_field_char_enum:
	case blofeld::_field_char_block_index:
	case blofeld::_field_custom_char_block_index:
	case blofeld::_field_char_integer: components = 1; data_type = ImGuiDataType_S8; return true;

	case blofeld::_field_byte_flags:
	case blofeld::_field_byte_block_flags:
	case blofeld::_field_byte_integer: components = 1; data_type = ImGuiDataType_U8; return true;

	case blofeld::_field_enum:
	case blofeld::_field_short_block_index:
	case blofeld::_field_custom_short_block_index:
	case blofeld::_field_short_integer: components = 1; data_type = ImGuiDataType_S16; return true;

	case blofeld::_field_word_flags:
	case blofeld::_field_word_block_flags:
	case blofeld::_field_word_integer: components = 1; data_type = ImGuiDataType_U16; break;

	case blofeld::_field_long_enum:
	case blofeld::_field_long_flags:
	case blofeld::_field_rgb_color:
	case blofeld::_field_argb_color:
	case blofeld::_field_long_block_flags:
	case blofeld::_field_long_block_index:
	case blofeld::_field_custom_long_block_index:
	case blofeld::_field_long_integer: components = 1; data_type = ImGuiDataType_S32; return true;

	case blofeld::_field_dword_integer: components = 1; data_type = ImGuiDataType_U32; return true;

	case blofeld::_field_int64_integer: components = 1; data_type = ImGuiDataType_S64; return true;

	case blofeld::_field_qword_integer: components = 1; data_type = ImGuiDataType_U64; return true;

	case blofeld::_field_angle:
	case blofeld::_field_real: components = 1; data_type = ImGuiDataType_Float; return true;

	case blofeld::_field_half: components = 1; data_type = ImGuiDataType_Float; return true;

	case blofeld::_field_short_bounds:
	case blofeld::_field_point_2d: components = 2; data_type = ImGuiDataType_S16; return true;

	case blofeld::_field_rectangle_2d: components = 4; data_type = ImGuiDataType_S16; return true;

	case blofeld::_field_real_fraction:
	case blofeld::_field_real_vector_2d:
	case blofeld::_field_real_euler_angles_2d:
	case blofeld::_field_angle_bounds:
	case blofeld::_field_real_bounds:
	case blofeld::_field_real_fraction_bounds:
	case blofeld::_field_real_point_2d: components = 2; data_type = ImGuiDataType_Float; return true;

	case blofeld::_field_real_point_3d:
	case blofeld::_field_real_euler_angles_3d:
	case blofeld::_field_real_rgb_color:
	case blofeld::_field_real_hsv_color:
	case blofeld::_field_real_plane_2d:
	case blofeld::_field_real_vector_3d: components = 3; data_type = ImGuiDataType_Float; return true;

	case blofeld::_field_real_argb_color:
	case blofeld::_field_real_ahsv_color:
	case blofeld::_field_real_plane_3d:
	case blofeld::_field_real_quaternion: components = 4; data_type = ImGuiDataType_Float; return true;
	}
	return false;
}

bool c_blofeld_tag_editor_tab::render_primitive(void* data, const blofeld::s_tag_field& field)
{
	bool result = false;

	ImGui::Columns(2, nullptr, false);
	ImGui::SetColumnWidth(0, 350);

	c_field_formatter field_formatter = c_field_formatter(&field, nullptr);

	ImGui::Text(field_formatter.display_name.c_str());

	if (!field_formatter.description.is_empty() && ImGui::IsItemHovered())
	{
		ImGui::BeginTooltip();
		ImGui::Text(field_formatter.description.c_str());
		ImGui::EndTooltip();
	}

	ImGui::NextColumn();
	{
		ImGui::SetNextItemWidth(350);

		int components;
		ImGuiDataType data_type;
		if (field_type_to_imgui_data_type(field.field_type, data_type, components))
		{
			if (components == 0)
			{
				result = ImGui::InputScalar(field_formatter.units.c_str(), data_type, data);
			}
			else
			{
				result = ImGui::InputScalarN(field_formatter.units.c_str(), data_type, data, components);
			}
		}
	}
	ImGui::NextColumn();
	ImGui::Columns(1);

	return result;
}

void c_blofeld_tag_editor_tab::render_tagblock(void* data, const blofeld::s_tag_field& field)
{
	s_tag_block& tag_block = *static_cast<s_tag_block*>(data);

	struct s_tag_block_dynamic_data
	{
		s_tag_block_dynamic_data(c_cache_file& cache_file, const blofeld::s_tag_field& field) :
			position(0),
			struct_size(blofeld::calculate_struct_size(
				cache_file.get_engine_type(),
				cache_file.get_platform_type(),
				_build_not_set,
				field.block_definition->struct_definition)),
			field_formatter(*new c_field_formatter(&field, nullptr))
		{

		}

		~s_tag_block_dynamic_data()
		{

		}

		uint32_t position;
		uint32_t struct_size;
		bool is_open;
		c_field_formatter& field_formatter;
	};
	s_tag_block_dynamic_data& dynamic_data = get_dynamic_data<s_tag_block_dynamic_data, c_cache_file&>(data, cache_file, field);

	if (ImGui::Button("+"))
	{
		dynamic_data.position++;
		if (tag_block.count == 0)
		{
			dynamic_data.position = 0;
		}
		else if (dynamic_data.position == tag_block.count)
		{
			//dynamic_data.position = tag_block.count - 1;
			dynamic_data.position = 0;
		}
	}
	if (ImGui::Button("-"))
	{
		dynamic_data.position--;
		if (tag_block.count == 0)
		{
			dynamic_data.position = 0;
		}
		else if (dynamic_data.position > tag_block.count) // unsigned underflow
		{
			dynamic_data.position = tag_block.count - 1;
			//dynamic_data.position = 0;
		}
	}

	char* const block_data = cache_file.get_tag_block_data(tag_block);
	if (block_data == nullptr)
	{
		// #TODO disable
	}
	bool header_open = ImGui::CollapsingHeader(dynamic_data.field_formatter.display_name.c_str(), /*ImGuiTreeNodeFlags_DefaultOpen |*/ /*ImGuiTreeNodeFlags_OpenOnArrow |*/ ImGuiTreeNodeFlags_Framed | ImGuiTreeNodeFlags_AllowItemOverlap);
	if (header_open && block_data != nullptr && tag_block.count > 0)
	{
		char* selected_block_data = block_data + dynamic_data.position * dynamic_data.struct_size;
		render_tag_struct_definition(10, selected_block_data, field.block_definition->struct_definition);
	}

	ImGui::Text("BLOCK POS [%i] size[%i] %s", dynamic_data.position, tag_block.count, dynamic_data.field_formatter.display_name.c_str());
}

void c_blofeld_tag_editor_tab::render_tagref(void* data, const blofeld::s_tag_field& field)
{
	ImGui::PushID(data);

	DEBUG_ASSERT(data != nullptr);
	DEBUG_ASSERT(field.tag_reference_definition != nullptr);

	const blofeld::s_tag_reference_definition& tag_reference_definition = *field.tag_reference_definition;
	s_tag_reference& tag_reference = *static_cast<s_tag_reference*>(data);

	const char* group_name = "(null)";
	c_tag_group_interface* tag_group_interface = cache_file.get_tag_group_interface_by_group_id(tag_reference.group_tag);
	if (tag_group_interface)
	{
		group_name = tag_group_interface->get_full_name();
	}

	ImGui::Columns(3, nullptr, false);
	ImGui::SetColumnWidth(0, 350);
	ImGui::SetColumnWidth(1, 350);
	ImGui::SetColumnWidth(2, 1000);

	c_field_formatter field_formatter = c_field_formatter(&field, nullptr);
	ImGui::Text(field_formatter.display_name.c_str());

	if (!field_formatter.description.is_empty() && ImGui::IsItemHovered())
	{
		ImGui::BeginTooltip();
		ImGui::Text(field_formatter.description.c_str());
		ImGui::EndTooltip();
	}

	ImGui::NextColumn();
	{
		ImGui::SetNextItemWidth(-1);
		if (ImGui::BeginCombo("##tag_tag_group", group_name))
		{
			if (ImGui::Selectable("(null)", tag_group_interface == nullptr))
			{
				tag_reference.group_tag = blofeld::INVALID_TAG;
				tag_reference.name = 0;
				tag_reference.name_length = 0;
				tag_reference.index = INT16_MAX;
				tag_reference.datum = INT16_MAX;
				tag_group_interface = nullptr;
			}

			if (tag_reference_definition.group_tag != blofeld::INVALID_TAG)
			{
				for (c_tag_group_interface& current_tag_group_interface : c_reference_loop(cache_file.get_tag_group_interfaces(), cache_file.get_tag_group_count()))
				{
					if (current_tag_group_interface.get_group_tag() != tag_reference_definition.group_tag)
					{
						continue;
					}

					bool is_selected = &current_tag_group_interface == tag_group_interface;

					const char* current_group_name = current_tag_group_interface.get_full_name();
					if (ImGui::Selectable(current_group_name, is_selected) && !is_selected)
					{
						tag_group_interface = &current_tag_group_interface;
						tag_reference.group_tag = current_tag_group_interface.get_group_tag();
						tag_reference.name = 0;
						tag_reference.name_length = 0;
						tag_reference.index = INT16_MAX;
						tag_reference.datum = INT16_MAX;
					}
				}
			}
			else if (const unsigned long* const group_tags = tag_reference_definition.group_tags)
			{
				for (const unsigned long* current_group_tag = group_tags; *current_group_tag != blofeld::INVALID_TAG; current_group_tag++)
				{
					for (c_tag_group_interface& current_tag_group_interface : c_reference_loop(cache_file.get_tag_group_interfaces(), cache_file.get_tag_group_count()))
					{
						if (current_tag_group_interface.get_group_tag() != *current_group_tag)
						{
							continue;
						}

						bool is_selected = &current_tag_group_interface == tag_group_interface;

						const char* current_group_name = current_tag_group_interface.get_full_name();
						if (ImGui::Selectable(current_group_name, is_selected) && !is_selected)
						{
							tag_group_interface = &current_tag_group_interface;
							tag_reference.group_tag = current_tag_group_interface.get_group_tag();
							tag_reference.name = 0;
							tag_reference.name_length = 0;
							tag_reference.index = INT16_MAX;
							tag_reference.datum = INT16_MAX;
						}

						break;
					}
				}
			}
			else
			{
				for (c_tag_group_interface& current_tag_group_interface : c_reference_loop(cache_file.get_tag_group_interfaces(), cache_file.get_tag_group_count()))
				{
					bool is_selected = &current_tag_group_interface == tag_group_interface;

					const char* current_group_name = current_tag_group_interface.get_full_name();
					if (ImGui::Selectable(current_group_name, is_selected) && !is_selected)
					{
						tag_group_interface = &current_tag_group_interface;
						tag_reference.group_tag = current_tag_group_interface.get_group_tag();
						tag_reference.name = 0;
						tag_reference.name_length = 0;
						tag_reference.index = INT16_MAX;
						tag_reference.datum = INT16_MAX;
					}
				}
			}

			ImGui::EndCombo();
		}
	}
	ImGui::NextColumn();
	{
		ImGui::SetNextItemWidth(-1);

		const char* tag_instance_name = "";
		c_tag_interface* current_interface = nullptr;
		if (tag_group_interface)
		{
			current_interface = cache_file.get_tag_interface(tag_reference.index);
			if (current_interface)
			{
				tag_instance_name = current_interface->get_path_with_group_name_cstr();
			}
		}

		if (ImGui::BeginCombo("##tag_path", tag_instance_name))
		{
			if (tag_group_interface)
			{
				for (c_tag_interface& current_tag_interface : c_reference_loop(cache_file.get_tag_interfaces(), cache_file.get_tag_count()))
				{
					if (current_tag_interface.is_null())
					{
						continue;
					}
					if (current_tag_interface.get_tag_group_interface() != tag_group_interface)
					{
						continue;
					}

					const char* current_name = current_tag_interface.get_path_with_group_name_cstr();
					bool is_selected = &current_tag_interface == current_interface;
					if (ImGui::Selectable(current_name, is_selected) && !is_selected)
					{
						tag_group_interface = current_tag_interface.get_tag_group_interface();
						if (tag_group_interface)
						{
							tag_reference.group_tag = tag_group_interface->get_group_tag();
							tag_reference.name = 0;
							tag_reference.name_length = 0;
							tag_reference.index = current_tag_interface.get_index();
							tag_reference.datum = INT16_MAX;
						}
						else
						{
							c_console::write_line("failed to set tag reference, tag group was null");

							tag_reference.group_tag = blofeld::INVALID_TAG;
							tag_reference.name = 0;
							tag_reference.name_length = 0;
							tag_reference.index = INT16_MAX;
							tag_reference.datum = INT16_MAX;
						}
					}
				}
			}
			else if (tag_reference_definition.group_tag != blofeld::INVALID_TAG)
			{
				for (c_tag_interface& current_tag_interface : c_reference_loop(cache_file.get_tag_interfaces(), cache_file.get_tag_count()))
				{
					if (current_tag_interface.is_null())
					{
						continue;
					}
					if (current_tag_interface.get_tag_group_interface()->get_group_tag() != tag_reference_definition.group_tag)
					{
						continue;
					}

					const char* current_name = current_tag_interface.get_path_with_group_name_cstr();
					bool is_selected = &current_tag_interface == current_interface;
					if (ImGui::Selectable(current_name, is_selected) && !is_selected)
					{
						tag_group_interface = current_tag_interface.get_tag_group_interface();
						if (tag_group_interface)
						{
							tag_reference.group_tag = tag_group_interface->get_group_tag();
							tag_reference.name = 0;
							tag_reference.name_length = 0;
							tag_reference.index = current_tag_interface.get_index();
							tag_reference.datum = INT16_MAX;
						}
						else
						{
							c_console::write_line("failed to set tag reference, tag group was null");

							tag_reference.group_tag = blofeld::INVALID_TAG;
							tag_reference.name = 0;
							tag_reference.name_length = 0;
							tag_reference.index = INT16_MAX;
							tag_reference.datum = INT16_MAX;
						}
					}
				}
			}
			else if (const unsigned long* const group_tags = tag_reference_definition.group_tags)
			{
				for (c_tag_interface& current_tag_interface : c_reference_loop(cache_file.get_tag_interfaces(), cache_file.get_tag_count()))
				{
					if (current_tag_interface.is_null())
					{
						continue;
					}
					for (const unsigned long* current_group_tag = group_tags; *current_group_tag != blofeld::INVALID_TAG; current_group_tag++)
					{
						if (current_tag_interface.get_tag_group_interface()->get_group_tag() == *current_group_tag)
						{
							goto is_valid_type;
						}
					}
					continue;
				is_valid_type:

					const char* current_name = current_tag_interface.get_path_with_group_name_cstr();
					bool is_selected = &current_tag_interface == current_interface;
					if (ImGui::Selectable(current_name, is_selected) && !is_selected)
					{
						tag_group_interface = current_tag_interface.get_tag_group_interface();
						if (tag_group_interface)
						{
							tag_reference.group_tag = tag_group_interface->get_group_tag();
							tag_reference.name = 0;
							tag_reference.name_length = 0;
							tag_reference.index = current_tag_interface.get_index();
							tag_reference.datum = INT16_MAX;
						}
						else
						{
							c_console::write_line("failed to set tag reference, tag group was null");

							tag_reference.group_tag = blofeld::INVALID_TAG;
							tag_reference.name = 0;
							tag_reference.name_length = 0;
							tag_reference.index = INT16_MAX;
							tag_reference.datum = INT16_MAX;
						}
					}
				}
			}
			else
			{
				for (c_tag_interface& current_tag_interface : c_reference_loop(cache_file.get_tag_interfaces(), cache_file.get_tag_count()))
				{
					const char* current_name = current_tag_interface.get_path_with_group_name_cstr();
					bool is_selected = &current_tag_interface == current_interface;
					if (ImGui::Selectable(current_name, is_selected) && !is_selected)
					{
						tag_group_interface = current_tag_interface.get_tag_group_interface();
						if (tag_group_interface)
						{
							tag_reference.group_tag = tag_group_interface->get_group_tag();
							tag_reference.name = 0;
							tag_reference.name_length = 0;
							tag_reference.index = current_tag_interface.get_index();
							tag_reference.datum = INT16_MAX;
						}
						else
						{
							c_console::write_line("failed to set tag reference, tag group was null");

							tag_reference.group_tag = blofeld::INVALID_TAG;
							tag_reference.name = 0;
							tag_reference.name_length = 0;
							tag_reference.index = INT16_MAX;
							tag_reference.datum = INT16_MAX;
						}
					}
				}
			}

			ImGui::EndCombo();
		}
	}
	ImGui::NextColumn();
	ImGui::Columns(1);

	ImGui::PopID();
}

uint32_t c_blofeld_tag_editor_tab::render_tag_struct_definition(int level, char* structure_data, const blofeld::s_tag_struct_definition& struct_definition)
{
	ImGui::PushID(structure_data);

	e_engine_type engine_type = tag_interface.get_cache_file().get_engine_type();
	e_platform_type platform_type = tag_interface.get_cache_file().get_platform_type();

	constexpr float indent = 25.0f;
	uint32_t bytes_traversed = 0;
	int32_t field_index = 0;
	for (const blofeld::s_tag_field* current_field = struct_definition.fields; current_field->field_type != blofeld::_field_terminator; (current_field++, field_index++))
	{
		char* current_data_position = structure_data + bytes_traversed;

		uint32_t field_skip_count;
		if (skip_tag_field_version(*current_field, engine_type, platform_type, _build_not_set, field_skip_count))
		{
			current_field += field_skip_count;
			continue;
		}
		ImGui::PushID(field_index);

		uint32_t field_size = blofeld::get_blofeld_field_size(platform_type, current_field->field_type);

		const char* field_typename = field_to_string(current_field->field_type);
		ASSERT(field_typename != nullptr);

		switch (current_field->field_type)
		{
		case blofeld::_field_string:
		{
			ImGui::Text("0x%X 0x%X %s %s", bytes_traversed, field_size, field_typename, current_field->name ? current_field->name : "");
			break;
		}
		case blofeld::_field_long_string:
		{
			ImGui::Text("0x%X 0x%X %s %s", bytes_traversed, field_size, field_typename, current_field->name ? current_field->name : "");
			break;
		}
		case blofeld::_field_string_id:
		{
			ImGui::Text("0x%X 0x%X %s %s", bytes_traversed, field_size, field_typename, current_field->name ? current_field->name : "");
			break;
		}
		case blofeld::_field_old_string_id:
		{
			ImGui::Text("0x%X 0x%X %s %s", bytes_traversed, field_size, field_typename, current_field->name ? current_field->name : "");
			break;
		}

		case blofeld::_field_char_integer:
		case blofeld::_field_short_integer:
		case blofeld::_field_long_integer:
		case blofeld::_field_int64_integer:
		case blofeld::_field_byte_integer:
		case blofeld::_field_word_integer:
		case blofeld::_field_dword_integer:
		case blofeld::_field_qword_integer:

		case blofeld::_field_char_enum:
		case blofeld::_field_enum:
		case blofeld::_field_long_enum:

		case blofeld::_field_long_flags:
		case blofeld::_field_word_flags:
		case blofeld::_field_byte_flags:

		case blofeld::_field_point_2d:
		case blofeld::_field_rectangle_2d:
		case blofeld::_field_rgb_color:
		case blofeld::_field_argb_color:

		case blofeld::_field_real:
		case blofeld::_field_real_fraction:
		case blofeld::_field_real_point_2d:
		case blofeld::_field_real_point_3d:
		case blofeld::_field_real_vector_2d:
		case blofeld::_field_real_vector_3d:
		case blofeld::_field_real_quaternion:
		case blofeld::_field_real_plane_2d:
		case blofeld::_field_real_plane_3d:
		case blofeld::_field_real_rgb_color:
		case blofeld::_field_real_argb_color:
		case blofeld::_field_real_hsv_color:
		case blofeld::_field_real_ahsv_color:
		case blofeld::_field_short_bounds:
		case blofeld::_field_real_bounds:
		case blofeld::_field_real_fraction_bounds:

		case blofeld::_field_byte_block_flags:
		case blofeld::_field_word_block_flags:
		case blofeld::_field_long_block_flags:
		case blofeld::_field_char_block_index:
		case blofeld::_field_short_block_index:
		case blofeld::_field_long_block_index:
		case blofeld::_field_custom_char_block_index:
		case blofeld::_field_custom_short_block_index:
		case blofeld::_field_custom_long_block_index:
		{
			render_primitive(current_data_position, *current_field);
			break;
		}
		case blofeld::_field_angle:
		{
			float constexpr pi = 3.14159265359f;
			float constexpr degrees_to_radians = 180.0f / pi;
			float constexpr radians_to_degrees = pi / 180.0f;

			float& src_radians = *reinterpret_cast<float*>(current_data_position);
			float degrees = src_radians * radians_to_degrees;
			if (render_primitive(&degrees, *current_field))
			{
				src_radians = degrees * radians_to_degrees;
			}
			break;
		}
		case blofeld::_field_real_euler_angles_2d:
		case blofeld::_field_angle_bounds:
		{
			ImGui::Text("0x%X 0x%X %s %s", bytes_traversed, field_size, field_typename, current_field->name ? current_field->name : "");
			break;
		}
		case blofeld::_field_real_euler_angles_3d:
		{
			ImGui::Text("0x%X 0x%X %s %s", bytes_traversed, field_size, field_typename, current_field->name ? current_field->name : "");
			break;
		}
		case blofeld::_field_tag:
		{
			ImGui::Text("0x%X 0x%X %s %s", bytes_traversed, field_size, field_typename, current_field->name ? current_field->name : "");
			break;
		}
		case blofeld::_field_tag_reference:
		{
			render_tagref(current_data_position, *current_field);
			break;
		}
		case blofeld::_field_block:
		{
			render_tagblock(current_data_position, *current_field);
			break;
		}
		case blofeld::_field_data:
		{
			ImGui::Text("0x%X 0x%X %s %s", bytes_traversed, field_size, field_typename, current_field->name ? current_field->name : "");
			break;
		}
		case blofeld::_field_vertex_buffer:
		{
			ImGui::Text("0x%X 0x%X %s %s", bytes_traversed, field_size, field_typename, current_field->name ? current_field->name : "");
			break;
		}
		case blofeld::_field_pad:
		{
			field_size = current_field->padding;
			break;
		}
		case blofeld::_field_useless_pad:
		{
			//field_size = current_field->padding;
			break;
		}
		case blofeld::_field_skip:
		{
			field_size = current_field->length;
			break;
		}
		case blofeld::_field_non_cache_runtime_value:
		{
			ImGui::Text("0x%X 0x%X %s %s", bytes_traversed, field_size, field_typename, current_field->name ? current_field->name : "");
			break;
		}
		case blofeld::_field_explanation:
		{
			ImGui::Dummy({ 10.0f, 10.0f });
			ImGui::PushStyleColor(ImGuiCol_Text, { 1.0f, 0.0f, 0.0f, 1.0f });
			ImGui::Text(current_field->name);
			if (current_field->explanation && *current_field->explanation)
			{
				ImGui::Text(current_field->explanation);
			}
			ImGui::PopStyleColor(1);
			ImGui::Dummy({ 5.0f, 5.0f });
			break;
		}
		case blofeld::_field_custom:
		{
			// #TODO: render custom fields
			break;
		}
		case blofeld::_field_struct:
		{
			uint32_t traversed_size = render_tag_struct_definition(level++, current_data_position, *current_field->struct_definition);
#ifdef _DEBUG
			uint32_t structure_size = blofeld::calculate_struct_size(engine_type, platform_type, _build_not_set, *current_field->struct_definition);
			DEBUG_ASSERT(traversed_size == structure_size);
#endif
			field_size = traversed_size;
			break;
		}
		case blofeld::_field_array:
		{
			uint32_t array_count = current_field->array_definition->count(engine_type);

			bool use_array_navigation = true;
			if (use_array_navigation)
			{
				struct s_tag_block_dynamic_data
				{
					uint32_t position = 0;
					uint32_t structure_size = 0;
				};
				s_tag_block_dynamic_data& dynamic_data = get_dynamic_data<s_tag_block_dynamic_data>(current_data_position);

				if (dynamic_data.structure_size == 0) // #TODO: precompute and find a home for this
				{
					dynamic_data.structure_size = blofeld::calculate_struct_size(engine_type, platform_type, _build_not_set, current_field->array_definition->struct_definition);
				}

				if (dynamic_data.position)
				{
					if (dynamic_data.position == ~uint32_t())
					{
						dynamic_data.position = array_count - 1;
					}
					else if (dynamic_data.position >= static_cast<int64_t>(array_count))
					{
						dynamic_data.position = 0;
					}
				}

				char* array_data_position = current_data_position + dynamic_data.structure_size * dynamic_data.position;

				uint32_t traversed_size = render_tag_struct_definition(level++, array_data_position, current_field->array_definition->struct_definition);
				DEBUG_ASSERT(traversed_size == dynamic_data.structure_size);

				current_data_position += dynamic_data.structure_size * array_count;
			}
			else
			{
				for (uint32_t array_index = 0; array_index < array_count; array_index++)
				{
					uint32_t traversed_size = render_tag_struct_definition(level++, current_data_position, current_field->array_definition->struct_definition);
					current_data_position += traversed_size;
				}
			}
			break;
		}
		case blofeld::_field_pageable:
		{
			ImGui::Text("0x%X 0x%X %s %s", bytes_traversed, field_size, field_typename, current_field->name ? current_field->name : "");
			break;
		}
		case blofeld::_field_api_interop:
		{
			ImGui::Text("0x%X 0x%X %s %s", bytes_traversed, field_size, field_typename, current_field->name ? current_field->name : "");
			break;
		}
		}

		ImGui::PopID();

		bytes_traversed += field_size;
	}

	ImGui::PopID();
	return bytes_traversed;
}

uint32_t c_blofeld_tag_editor_tab::render_tag_group(char* data, const blofeld::s_tag_group& group)
{
	return render_tag_struct_definition(0, data, group.block_definition.struct_definition);
}
