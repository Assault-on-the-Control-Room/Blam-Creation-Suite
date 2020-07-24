#include "mandrilllib-private-pch.h"

float c_cache_file_tab::explorer_bar_width = c_settings::read_float(_settings_section_mandrill, k_explorer_bar_width, 500.0f);

c_cache_file_tab::c_cache_file_tab(c_cache_file& cache_file, c_mandrill_tab& parent, const char* tag_list) :
	c_mandrill_tab(cache_file.get_filename_utf8(), cache_file.get_filepath_utf8(), &parent),
	cache_file(cache_file),
	render_trigger_volumes(c_command_line::has_command_line_arg("-showtriggervolumes")),
	search_buffer(),
	search_selected_tag_interface(nullptr)
{
	std::string load_tag_command_line = c_command_line::get_command_line_arg("-loadtag");
	if (!load_tag_command_line.empty())
	{
		open_tag_by_search_name(load_tag_command_line.c_str());
	}

	if (tag_list != nullptr)
	{
		c_fixed_path selected_tag_name;
		c_fixed_path tag_name;
		const char* read_position = tag_list;
		while (*read_position != 0)
		{
			if (*read_position == ';')
			{
				read_position++;
			}
			while (*read_position && *read_position != ';' && *read_position != ']' && *read_position != '*')
			{
				tag_name += *read_position;
				read_position++;
			}
			if (*read_position == '*')
			{
				selected_tag_name = tag_name;
				read_position++;
			}

			DEBUG_ASSERT(*read_position == 0 || *read_position == ';');

			open_tag_by_search_name(tag_name.c_str());

			tag_name.clear();
		}
		if (!selected_tag_name.is_empty())
		{
			open_tag_by_search_name(selected_tag_name.c_str()); // kinda hacky but ez way to set the selected tab
		}
	}
}

c_cache_file_tab::~c_cache_file_tab()
{
}

c_tag_interface_tab& c_cache_file_tab::open_tag_interface_tab(c_tag_interface& tag_interface)
{
	for (c_mandrill_tab& tab : c_reference_loop(children.data(), children.size()))
	{
		if (c_tag_interface_tab* tag_interface_tab = dynamic_cast<c_tag_interface_tab*>(&tab))
		{
			if (&tag_interface_tab->get_tag_interface() == &tag_interface)
			{
				next_selected_tab = tag_interface_tab;
				return *tag_interface_tab;
			}
		}
	}

	c_tag_interface_tab* tag_interface_tab = new c_tag_interface_tab(tag_interface, *this);
	add_tab(*tag_interface_tab);
	next_selected_tab = tag_interface_tab;

	return *tag_interface_tab;
}

void c_cache_file_tab::open_tag_by_search_name(const char* tag_name)
{
	// #TODO: Create a callback function interface that will run on the first frame of the main thread
	while (cache_file.is_loading()) { Sleep(1); };

	c_tag_interface* tag_interface = nullptr;

	for (c_tag_interface* current_tag_interface : c_range_loop(cache_file.get_tag_interfaces(), cache_file.get_tag_count()))
	{
		if (current_tag_interface->is_null()) continue;

		bool is_match =
			_stricmp(tag_name, current_tag_interface->get_name_with_group_id_cstr()) == 0 ||
			_stricmp(tag_name, current_tag_interface->get_path_with_group_id_cstr()) == 0 ||
			_stricmp(tag_name, current_tag_interface->get_name_with_group_name_cstr()) == 0 ||
			_stricmp(tag_name, current_tag_interface->get_path_with_group_name_cstr()) == 0;
		if (is_match)
		{
			tag_interface = current_tag_interface;
			break;
		}
	}

	if (tag_interface)
	{
		open_tag_interface_tab(*tag_interface);
	}
}

void c_cache_file_tab::render_search_box()
{
	const char* search_reccomendation = "<search for tag>";
	ImDrawList* draw_list = ImGui::GetWindowDrawList();

	ImGui::Dummy({ 10.0f, 0.0f });
	ImGui::SameLine();
	ImGui::PushItemWidth(ImGui::GetWindowContentRegionWidth() - 75.0f);
	ImGuiInputTextFlags input_text_flags = 0;
	ImVec2 pos = ImGui::GetCursorScreenPos();
	ImGui::InputText("##Search", search_buffer.str(), search_buffer.capacity(), input_text_flags);
	if (!ImGui::IsItemActive() && search_buffer.is_empty())
	{
		draw_list->AddText({ pos.x + 4.0f, pos.y + 4.0f }, ImGui::ColorConvertFloat4ToU32(MANDRILL_THEME_TEXT(0.25)), search_reccomendation);
	}
	ImGui::SameLine();
	if (ImGui::Button(ICON_FA_TIMES))
	{
		search_buffer.clear();
	}
	ImGui::SameLine();
	ImGui::Dummy({ 10.0f, 0.0f });
}

void c_cache_file_tab::render_explorer_bar()
{
	ImGui::Dummy({ 0.0f, 10.0f });

	render_search_box();

	ImGui::Dummy({ 0.0f, 10.0f });
	ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, { 25, 8 });
	if (search_buffer.is_empty())
	{
		if (ImGui::BeginTabBar("##fileview"))
		{
			if (ImGui::BeginTabItem("Tags"))
			{
				ImGui::Dummy({ 0.0f, 1.0f });
				ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, { 4, 4 });

				ImGui::BeginChild("left column", {}, false, ImGuiWindowFlags_AlwaysVerticalScrollbar | ImGuiWindowFlags_HorizontalScrollbar);

				render_tags_list_tree();

				ImGui::EndChild();

				ImGui::PopStyleVar();
				ImGui::EndTabItem();
			}


			ImGui::EndTabBar();
		}
	}
	else
	{
		ImGui::BeginChild("left column", {}, false, ImGuiWindowFlags_AlwaysVerticalScrollbar | ImGuiWindowFlags_HorizontalScrollbar);

		render_tags_list_search();

		ImGui::EndChild();

	}
	ImGui::PopStyleVar();
}

void c_cache_file_tab::render_impl()
{
	if (c_mandrill_user_interface::show_explorer_bar)
	{
		ImGui::Columns(2, "##navigation");
		ImGui::SetColumnOffset(1, explorer_bar_width);
		ImGui::Separator();
		{
			ImGui::BeginGroup();
			ImVec2 size = ImGui::GetContentRegionAvail();
			if (size.x < 200.0f)
			{
				size.x = 200.0f;
			}
			ImGui::BeginChild("left column", size, false, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);
			
			render_explorer_bar();

			ImGui::EndChild();
			ImGui::EndGroup();
		}
		if (ImGui::IsMouseDragging(ImGuiMouseButton_Left))
		{
			auto& x = ImGui::GetStyle();
			explorer_bar_width = ImGui::GetItemRectSize().x + 16.0f;
			c_settings::write_float(_settings_section_mandrill, k_explorer_bar_width, explorer_bar_width);
		}
		if (explorer_bar_width < 200.0f)
		{
			explorer_bar_width = 200.0f + 16.0f;
		}
		ImGui::NextColumn();
	}
	{
		ImGui::BeginGroup();
		ImGui::BeginChild("right column", {}, false);

		if (ImGui::BeginTabBar("##tagsview"))
		{
			c_mandrill_tab* select_tab = next_selected_tab;
			next_selected_tab = nullptr; // take a copy here as child render calls can set this value
			//for (c_mandrill_tab& tab : c_reference_loop(children.data(), children.size()))
			for (c_mandrill_tab* tab : children)
			{
				tab->render(tab == select_tab);
			}

			ImGui::EndTabBar();
		}

		ImGui::EndChild();
		ImGui::EndGroup();
	}
	ImGui::Columns(1);
}

void c_cache_file_tab::render_menu_gui_impl(e_menu_render_type menu_render_type)
{
	if (menu_render_type == _menu_render_type_root_file && is_selected())
	{
		c_fixed_string_512 save_string;
		save_string.format("Save %s", cache_file.get_filename_utf8());
		if (ImGui::MenuItem(save_string.c_str(), "Ctrl+S"))
		{
			cache_file.save_map();
		}
		//ImGui::MenuItem("Save As");
		ImGui::Separator();
		//ImGui::MenuItem("Compile");
		//ImGui::Separator();
	}
	if (menu_render_type == _menu_render_type_root && is_selected())
	{
		if (ImGui::BeginMenu("Cache"))
		{
			for (c_mandrill_tab& tab : c_reference_loop(children.data(), children.size()))
			{
				tab.render_menu_gui(_menu_render_type_child);
			}

			ImGui::EndMenu();
		}

		c_mandrill_user_interface& user_interface = *search_parent_tab_type<c_mandrill_user_interface>();
		REFERENCE_ASSERT(user_interface);

		if (user_interface.is_game())
		{
			if (ImGui::BeginMenu("Game"))
			{
				if (ImGui::MenuItem(render_trigger_volumes ? "Hide Trigger Volumes" : "Show Trigger Volumes"))
				{
					render_trigger_volumes = !render_trigger_volumes;
				}

				ImGui::EndMenu();
			}
		}

		for (c_mandrill_tab& tab : c_reference_loop(children.data(), children.size()))
		{
			tab.render_menu_gui(_menu_render_type_root);
		}
	}
}

void c_cache_file_tab::render_file_dialogue_gui_impl()
{
	for (c_mandrill_tab& tab : c_reference_loop(children.data(), children.size()))
	{
		tab.render_file_dialogue_gui();
	}
}

void c_cache_file_tab::render_game_layer_impl()
{
	if (render_trigger_volumes)
	{
		// #TODO reimplement trigger volume rendering
	}

	for (c_mandrill_tab& tab : c_reference_loop(children.data(), children.size()))
	{
		tab.render_game_layer();
	}
}

void c_cache_file_tab::render_tags_list_tree()
{
	c_mandrill_user_interface& user_interface = *search_parent_tab_type<c_mandrill_user_interface>();
	REFERENCE_ASSERT(user_interface);
	c_tag_group_interface* const* group_interfaces = cache_file.get_tag_group_interfaces();

	for (c_tag_group_interface* group_interface : c_range_loop(group_interfaces, cache_file.get_tag_group_count()))
	{
		const uint32_t tag_interfaces_count = group_interface->get_tag_interfaces_count();
		c_tag_interface* const* tag_interfaces = user_interface.get_use_full_file_length_display()
			? group_interface->get_tag_interfaces_sorted_by_path_with_group_id()
			: group_interface->get_tag_interfaces_sorted_by_name_with_group_id();

		const char* group_name = group_interface->get_full_name();
		const char* group_short_name = group_interface->get_short_name();

		bool display_group = tag_interfaces_count > 0;

		if (!display_group) continue;


		bool tree_node_selected = false;
		if (c_mandrill_user_interface::use_developer_features)
		{
			uint32_t tag_interface_count = 0;
			uint32_t tag_interface_validated_count = 0;
			for (c_tag_interface* tag_interface : c_range_loop(tag_interfaces, tag_interfaces_count))
			{
				tag_interface_count++;
				if (c_gen3_tag_interface* gen3_tag_interface = dynamic_cast<c_gen3_tag_interface*>(tag_interface))
				{
					if (gen3_tag_interface->get_is_tag_valid())
					{
						tag_interface_validated_count++;
					}
				}
				else
				{
					tag_interface_validated_count++;
				}
			}

			bool is_tag_group_valid = tag_interface_count == 0 || tag_interface_validated_count == tag_interface_count;
			bool has_valid_tags = tag_interface_validated_count > 0;

			if (is_tag_group_valid) ImGui::PushStyleColor(ImGuiCol_Text, { 0.55f, 1.0f, 0.55f, 1.0f });
			else if (has_valid_tags) ImGui::PushStyleColor(ImGuiCol_Text, { 1.0f, 1.0f, 0.55f, 1.0f });
			else ImGui::PushStyleColor(ImGuiCol_Text, { 1.0f, 0.55f, 0.55f, 1.0f });

			tree_node_selected = ImGui::TreeNode(group_short_name, "%s - %s (%u/%u)", group_name, group_short_name, tag_interface_validated_count, tag_interface_count);
		}
		else
		{
			tree_node_selected = ImGui::TreeNode(group_short_name, "%s - %s", group_name, group_short_name);
		}

		if (tree_node_selected)
		{

			for (c_tag_interface* tag_interface : c_range_loop(tag_interfaces, tag_interfaces_count))
			{
				if (tag_interface->is_null()) continue;

				const char* tag_display_with_group_id = user_interface.get_use_full_file_length_display()
					? tag_interface->get_path_with_group_id_cstr()
					: tag_interface->get_name_with_group_id_cstr();

				c_gen3_tag_interface* gen3_tag_interface = nullptr;
				if (c_mandrill_user_interface::use_developer_features)
				{
					gen3_tag_interface = dynamic_cast<c_gen3_tag_interface*>(tag_interface);
					bool is_tag_valid = true;
					if (gen3_tag_interface)
					{
						is_tag_valid = gen3_tag_interface->get_is_tag_valid();

						if (is_tag_valid) ImGui::PushStyleColor(ImGuiCol_Text, { 0.55f, 1.0f, 0.55f, 1.0f });
						else ImGui::PushStyleColor(ImGuiCol_Text, { 1.0f, 0.55f, 0.55f, 1.0f });
					}
				}

				static ImGuiTreeNodeFlags base_flags = ImGuiTreeNodeFlags_OpenOnArrow | ImGuiTreeNodeFlags_OpenOnDoubleClick | ImGuiTreeNodeFlags_SpanAvailWidth;
				if (ImGui::TreeNodeEx(tag_interface, base_flags | ImGuiTreeNodeFlags_Leaf | ImGuiTreeNodeFlags_NoTreePushOnOpen, "%s - 0x%X", tag_display_with_group_id, tag_interface->get_index()))
				{
					if (ImGui::IsItemClicked() && ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left))
					{
						open_tag_interface_tab(*tag_interface);
					}
				}

				if (c_mandrill_user_interface::use_developer_features && gen3_tag_interface != nullptr)
				{
					ImGui::PopStyleColor();
				}
			}

			ImGui::TreePop();
		}

		if (c_mandrill_user_interface::use_developer_features)
		{
			ImGui::PopStyleColor();
		}
	}
}

void c_cache_file_tab::render_tags_list_search()
{
	c_mandrill_user_interface& user_interface = *search_parent_tab_type<c_mandrill_user_interface>();
	REFERENCE_ASSERT(user_interface);

	c_tag_interface* const* tag_interfaces = user_interface.get_use_full_file_length_display()
		? cache_file.get_tag_interfaces_sorted_by_path_with_group_id()
		: cache_file.get_tag_interfaces_sorted_by_name_with_group_id();
	for (c_tag_interface& tag_interface : c_reference_loop(tag_interfaces, cache_file.get_tag_count()))
	{
		if (tag_interface.is_null()) continue;

		const char* tag_path_group_id = tag_interface.get_path_with_group_id_cstr();
		const char* tag_path_group_name = tag_interface.get_path_with_group_name_cstr();

		const char* tag_display_with_group_name = user_interface.get_use_full_file_length_display()
			? tag_interface.get_path_with_group_name_cstr()
			: tag_interface.get_name_with_group_name_cstr();

		if (!search_buffer.is_empty())
		{
			if (strstr(tag_path_group_name, search_buffer.c_str()) == nullptr && strstr(tag_path_group_id, search_buffer.c_str()) == nullptr)
			{
				continue;
			}
		}

		c_gen3_tag_interface* gen3_tag_interface = nullptr; 
		if (c_mandrill_user_interface::use_developer_features)
		{
			gen3_tag_interface = dynamic_cast<c_gen3_tag_interface*>(&tag_interface);
			bool is_tag_valid = true;
			if (gen3_tag_interface)
			{
				is_tag_valid = gen3_tag_interface->get_is_tag_valid();

				if (is_tag_valid) ImGui::PushStyleColor(ImGuiCol_Text, { 0.55f, 1.0f, 0.55f, 1.0f });
				else ImGui::PushStyleColor(ImGuiCol_Text, { 1.0f, 0.55f, 0.55f, 1.0f });
			}
		}

		bool selected = ImGui::Selectable(tag_display_with_group_name, search_selected_tag_interface == &tag_interface, ImGuiSelectableFlags_AllowDoubleClick);

		if (c_mandrill_user_interface::use_developer_features && gen3_tag_interface)
		{
			ImGui::PopStyleColor();
		}

		if (ImGui::IsItemHovered())
		{
			ImGui::BeginTooltip();
			ImGui::Text(tag_path_group_name);
			ImGui::EndTooltip();
		}
		if (selected && ImGui::IsMouseDoubleClicked((ImGuiMouseButton_Left)))
		{
			search_selected_tag_interface = &tag_interface;
			open_tag_interface_tab(tag_interface);
			search_selected_tag_interface = nullptr;
		}
	}
}
