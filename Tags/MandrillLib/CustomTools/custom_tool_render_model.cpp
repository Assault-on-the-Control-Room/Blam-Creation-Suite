#include "mandrilllib-private-pch.h"

c_custom_tool_render_model::c_custom_tool_render_model(c_cache_file& cache_file, blofeld::haloreach::s_object_struct_definition* object_struct_definition) :
	c_custom_tool_base()
{
	v_tag<s_model_definition>* model_tag = dynamic_cast<v_tag<s_model_definition>*>(cache_file.get_tag_interface(object_struct_definition->model.index));

	title = "Render model";
	maximum_height = 500.0f;
	init_placeholder_textures();
}

c_custom_tool_render_model::~c_custom_tool_render_model()
{
	placeholder_texture->Release();
	shader_resource_view->Release();
}

void c_custom_tool_render_model::init_placeholder_textures()
{
	if (placeholder_texture == nullptr)
	{
		D3D11_TEXTURE2D_DESC texture_description = {};
		texture_description.Width = 1;
		texture_description.Height = 1;
		texture_description.MipLevels = 1;
		texture_description.ArraySize = 1;
		texture_description.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		texture_description.SampleDesc.Count = 1;
		texture_description.SampleDesc.Quality = 0;
		texture_description.Usage = D3D11_USAGE_DEFAULT;
		texture_description.BindFlags = D3D11_BIND_SHADER_RESOURCE;
		texture_description.CPUAccessFlags = 0;
		texture_description.MiscFlags = 0;

		D3D11_SUBRESOURCE_DATA subresource_data = {};
		char data[4] = { 100i8, 149i8, 237i8, 255i8 };
		subresource_data.pSysMem = data;

		size_t num_bytes;
		size_t row_bytes;
		HRESULT get_surface_info_result = GetSurfaceInfo(texture_description.Width, texture_description.Height, texture_description.Format, &num_bytes, &row_bytes, nullptr);
		ASSERT(SUCCEEDED(get_surface_info_result));

		subresource_data.SysMemPitch = static_cast<UINT>(row_bytes);
		subresource_data.SysMemSlicePitch = static_cast<UINT>(num_bytes);

		HRESULT create_texture_2d_result = c_render::s_device->CreateTexture2D(&texture_description, &subresource_data, &placeholder_texture);
		ASSERT(SUCCEEDED(create_texture_2d_result));
		ASSERT(placeholder_texture);
	}
	if (shader_resource_view == nullptr)
	{
		HRESULT createShaderResourceViewResult = c_render::s_device->CreateShaderResourceView(placeholder_texture, NULL, &shader_resource_view);
		ASSERT(SUCCEEDED(createShaderResourceViewResult));
	}
}

void c_custom_tool_render_model::render_contents()
{
	ImDrawList* draw_list = ImGui::GetWindowDrawList();

	ImGui::Columns(2, nullptr, false);
	float col0_width = ImGui::GetContentRegionAvailWidth();
	ImGui::SetColumnWidth(0, __min(720.0f, col0_width) + ImGui::GetStyle().ItemSpacing.x * 2.0f);
	{
		const char* slider_format = "%.2f";
		if (scale >= 10.0f) slider_format = "%.1f";
		ImGui::SliderFloat("scale", &scale, 0.01f, 100.0f, slider_format, 3.0f);

		float width = ImGui::GetContentRegionAvailWidth();
		if (ImGui::GetCurrentWindow()->ScrollbarSizes.x == 0) // account for the scrollbar being added to prevent flicker
		{
			width -= ImGui::GetStyle().ScrollbarSize;
		}

		// viewport
		{
			ImVec2 start_pos = ImGui::GetCursorScreenPos();
			ImVec2 content_region = { width, width * (9.0f / 16.0f) };
			ImVec2 end_pos = { start_pos.x * content_region.x, start_pos.y * content_region.y };
			//draw_list->AddRectFilled(start_pos, end_pos, ImGui::ColorConvertFloat4ToU32({ 1.0f, 0.0f, 0.0f, 1.0f }));

			ImGui::Image(shader_resource_view, content_region);
		}

		// viewport controls
		{
			ImVec2 start_pos = ImGui::GetCursorPos();
			ImGui::Checkbox("Markers", &show_markers);
			ImVec2 end_pos = ImGui::GetCursorPos();

			float button_width = ImGui::CalcTextSize("Refresh model").x + (ImGui::GetStyle().FramePadding.x + ImGui::GetStyle().ItemInnerSpacing.x) * 2.0f;
			ImVec2 button_pos = { ImGui::GetContentRegionAvailWidth() - button_width, start_pos.y };
			ImGui::SetCursorPos(button_pos);
			ImGui::Button("Refresh model");
			ImGui::SetCursorPos(end_pos);
		}
	}
	ImGui::NextColumn();
	{
		ImGui::Text("Variant:");
		ImGui::SameLine();
		ImGui::SetNextItemWidth(400.0f);
		if (ImGui::BeginCombo("##variant", ""))
		{
			ImGui::EndCombo();
		}

		ImGui::Dummy({ 0.0f, 10.0f });

		ImGui::Text("default:");
		ImGui::SameLine();
		ImGui::Checkbox("##default", &show_default_variant);


		ImGui::BeginChild("##buttons", { ImGui::GetContentRegionAvailWidth(), 120.0f });

		ImGui::Separator();

		ImGui::Dummy({ 0.0f, 10.0f });

		ImGui::Button("Drop Variant");
		ImGui::Button("Drop Permutation");
		ImGui::Button("Update");

		ImGui::EndChild();
	}
	ImGui::Columns(1);
}