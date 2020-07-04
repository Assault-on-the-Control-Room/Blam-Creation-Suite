#include "mandrilllib-private-pch.h"

c_tag_interface_tab::c_tag_interface_tab(c_tag_interface& tag_interface, c_mandrill_tab& parent_tab) :
	c_mandrill_tab(tag_interface.get_name_with_group_name_cstr(), tag_interface.get_path_with_group_name_cstr(), &parent_tab),
	tag_interface(tag_interface)
{
	//if (v_tag_interface<blofeld::haloreach::s_bitmap_block_struct>* bitmap_tag_interface = dynamic_cast<decltype(bitmap_tag_interface)>(&tag_interface))
	//{
	//	c_mandrill_bitmap_gui_tab* mandrill_bitmap_gui_tab = new c_mandrill_bitmap_gui_tab(cache_file, this, *bitmap_tag_interface);
	//	ASSERT(mandrill_bitmap_gui_tab != nullptr);
	//	add_tab(*mandrill_bitmap_gui_tab);
	//}

	const blofeld::s_tag_group* blofeld_reflection = tag_interface.get_blofeld_reflection_data();
	if (blofeld_reflection)
	{
		c_blofeld_tag_editor_tab* blofeld_tag_editor_gui_tab = new c_blofeld_tag_editor_tab(tag_interface, *this);
		add_tab(*blofeld_tag_editor_gui_tab);

		c_blofeld_tag_debugger_tab* blofeld_tag_debugger_gui_tab = new c_blofeld_tag_debugger_tab(tag_interface, *this);
		add_tab(*blofeld_tag_debugger_gui_tab);

		c_blofeld_tag_definition_debug_tab* blofeld_tag_definition_debug_tab = new c_blofeld_tag_definition_debug_tab(tag_interface, *this);
		add_tab(*blofeld_tag_definition_debug_tab);
	}
}

c_tag_interface_tab::~c_tag_interface_tab()
{

}

void c_tag_interface_tab::game_quick_preview()
{

}

void c_tag_interface_tab::render_impl()
{
	if (!has_enabled_children())
	{
		ImGui::Text("No supported editors");
		return;
	}

	if (ImGui::BeginTabBar("##TagEditorTabs", ImGuiTabBarFlags_None)) // each tag
	{
		for (c_mandrill_tab& tab : c_reference_loop(children.data(), children.size()))
		{
			tab.render(next_selected_tab == &tab);
		}
		next_selected_tab = nullptr;

		ImGui::EndTabBar();
	}
}

void c_tag_interface_tab::render_menu_gui_impl(e_menu_render_type menu_render_type)
{
	if (menu_render_type == _menu_render_type_root && _is_selected)
	{
		//if (ImGui::BeginMenu(tag_interface.get_name_with_group_name_cstr()))
		//{
		//	for (c_mandrill_tab& tab : c_reference_loop(children.data(), children.size()))
		//	{
		//		tab.render_menu_gui(_menu_render_type_child);
		//	}

		//	ImGui::EndMenu();
		//}

		for (c_mandrill_tab& tab : c_reference_loop(children.data(), children.size()))
		{
			tab.render_menu_gui(_menu_render_type_root);
		}
	}
}

void c_tag_interface_tab::render_file_dialogue_gui_impl()
{

}

void c_tag_interface_tab::render_game_layer_impl()
{

}
