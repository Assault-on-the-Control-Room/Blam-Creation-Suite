#include "tagvalidate-private-pch.h"

c_gen3_cache_file_validator::c_gen3_cache_file_validator(c_gen3_cache_file& cache_file) :
	cache_file(cache_file),
	engine_type(cache_file.get_engine_type())
{



}

c_gen3_cache_file_validator::~c_gen3_cache_file_validator()
{



}


ImGuiDataType c_gen3_cache_file_validator::field_to_imgui_data_type(blofeld::e_field field_type)
{
	switch (field_type)
	{
	case blofeld::_field_char_enum:return ImGuiDataType_S8;
	case blofeld::_field_enum: return ImGuiDataType_S16;
	case blofeld::_field_long_enum: return ImGuiDataType_S32;
	case blofeld::_field_long_flags: return ImGuiDataType_S32;
	case blofeld::_field_word_flags: return ImGuiDataType_S16;
	case blofeld::_field_byte_flags:return ImGuiDataType_S8;
	case blofeld::_field_char_integer: return ImGuiDataType_S8;
	case blofeld::_field_short_integer: return ImGuiDataType_S16;
	case blofeld::_field_long_integer: return ImGuiDataType_S32;
	case blofeld::_field_int64_integer: return ImGuiDataType_S64;
	case blofeld::_field_angle: return ImGuiDataType_Float;
	case blofeld::_field_real: return ImGuiDataType_Float;
	case blofeld::_field_real_fraction: return ImGuiDataType_Float;
	}
	throw;
}

uint32_t c_gen3_cache_file_validator::get_struct_size(const blofeld::s_tag_struct_definition& struct_definition)
{
	uint32_t size = 0;

	for (const blofeld::s_tag_field* current_field = struct_definition.fields; current_field->field_type != blofeld::_field_terminator; current_field++)
	{
		uint32_t field_skip_count;
		if (skip_tag_field_version(*current_field, engine_type, _build_not_set, field_skip_count))
		{
			current_field += field_skip_count;
			continue;
		}

		uint32_t field_size = get_field_size(*current_field);
		size += field_size;
	}

	return size;
}

uint32_t c_gen3_cache_file_validator::get_field_size(const blofeld::s_tag_field& field)
{
	uint32_t field_size = get_blofeld_field_size(field.field_type);
	if (field_size > 0)
	{
		return field_size;
	}
	switch (field.field_type)
	{
	case blofeld::_field_explanation:					return 0;	// empty
	case blofeld::_field_custom:						return 0;	// empty
	case blofeld::_field_terminator:					return 0;	// empty
	case blofeld::_field_pad:							return field.padding;	// dynamic
	case blofeld::_field_useless_pad:					return 0;	// dynamic
	case blofeld::_field_skip:							return field.padding;	// dynamic
	case blofeld::_field_struct:
	{
		uint32_t struct_size = get_struct_size(*field.struct_definition);	// dynamic
		return struct_size;
	}
	case blofeld::_field_array:							return get_struct_size(field.array_definition->struct_definition) * field.array_definition->count;	// dynamic
	}
	throw;
}

uint32_t __log2u(uint32_t index)
{
	uint32_t value = 0;
	while (index >>= 1) ++value;
	return value;
}

uint32_t c_gen3_cache_file_validator::render_tag_struct_definition(
	c_tag_interface& tag_interface,
	int level,
	char* data,
	const blofeld::s_tag_struct_definition& struct_definition,
	bool is_block,
	bool render,
	bool& is_struct_valid,
	bool& is_tag_valid,
	uint32_t parent_offset,
	e_cache_file_validator_struct_type struct_type,
	uint32_t index)
{
	float indent_size = 20.0f;
	uint32_t struct_size = get_struct_size(struct_definition);

	if (render)
	{
		ImGui::PushID(data);
		ImGui::BeginGroup();
		ImGui::PushStyleColor(ImGuiCol_Text, { 0.3f, 0.5f, 1.0f, 1.0f });
		ImGui::Dummy({ level * indent_size, 0.0f }); 
		ImGui::SameLine();
		switch (struct_type)
		{
		case _cache_file_validator_struct_type_array:
			ImGui::Text("ARRAY STRUCT START>%s index:%u size:[0x%X]", struct_definition.name, index, struct_size);
			break;
		case _cache_file_validator_struct_type_tag_block:
			ImGui::Text("BLOCK STRUCT START>%s index:%u size:[0x%X]", struct_definition.name, index, struct_size);
			break;
		default:
		case _cache_file_validator_struct_type_structure:
			ImGui::Text("STRUCT START>%s [0x%X]", struct_definition.name, struct_size);
			break;
		}
		ImGui::PopStyleColor();
	}

	uint32_t bytes_traversed = 0;
	int32_t field_index = 0;
	char* current_data_position = data;

	for (const blofeld::s_tag_field* current_field = struct_definition.fields; current_field->field_type != blofeld::_field_terminator; (current_field++, field_index++))
	{
		uint32_t field_skip_count;
		if (skip_tag_field_version(*current_field, engine_type, _build_not_set, field_skip_count))
		{
			current_field += field_skip_count;
			continue;
		}

		const char* field_typename = field_to_string(current_field->field_type);
		ASSERT(field_typename != nullptr);

		uint32_t field_size = get_field_size(*current_field);


		s_field_validation_result result = {};
		result.field_size = field_size;
		result.string_id_value = nullptr;
		result.tag_reference_instance = nullptr;
		result.float_is_out_of_range = false;
		result.block_is_out_of_range = false;
		result.block_struct_is_valid = true;
		result.field_offset = bytes_traversed;
		result.absolute_offset = parent_offset + bytes_traversed;
		result.level = level + 1;
		bool previously_invalid = !is_struct_valid;
		{
			bool was_tested = true;
			switch (current_field->field_type)
			{
			case blofeld::_field_char_enum:
			{
				long enum_max = current_field->string_list_definition ? current_field->string_list_definition->count : 0;
				char enum_value = *reinterpret_cast<char*>(current_data_position);
				is_struct_valid &= enum_value < enum_max;
				break;
			}
			case blofeld::_field_enum:
			{
				long enum_max = current_field->string_list_definition ? current_field->string_list_definition->count : 0;
				short enum_value = *reinterpret_cast<short*>(current_data_position);
				is_struct_valid &= enum_value < enum_max;
				break;
			}
			case blofeld::_field_long_enum:
			{
				long enum_max = current_field->string_list_definition ? current_field->string_list_definition->count : 0;
				long enum_value = *reinterpret_cast<long*>(current_data_position);
				is_struct_valid &= enum_value < enum_max;
				break;
			}
			case blofeld::_field_byte_flags:
			{
				uint32_t enum_max = current_field->string_list_definition ? current_field->string_list_definition->count : 0;
				byte enum_value = __log2u(*reinterpret_cast<byte*>(current_data_position));
				is_struct_valid &= enum_value < enum_max;
				break;
			}
			case blofeld::_field_word_flags:
			{
				uint32_t enum_max = current_field->string_list_definition ? current_field->string_list_definition->count : 0;
				word enum_value = __log2u(*reinterpret_cast<word*>(current_data_position));
				is_struct_valid &= enum_value < enum_max;
				break;
			}
			case blofeld::_field_real:
			case blofeld::_field_angle:
			case blofeld::_field_real_fraction:
			{
				float float_value = *reinterpret_cast<float*>(current_data_position);
				is_struct_valid &= !isnan(float_value);
				result.float_is_out_of_range |= fabsf(float_value) > float(0xFFFFFFFu);
				break;
			}
			case blofeld::_field_real_point_2d:
			case blofeld::_field_real_vector_2d:
			case blofeld::_field_angle_bounds:
			case blofeld::_field_real_bounds:
			case blofeld::_field_real_fraction_bounds:
			{
				float float_value0 = reinterpret_cast<float*>(current_data_position)[0];
				float float_value1 = reinterpret_cast<float*>(current_data_position)[1];
				is_struct_valid &= !isnan(float_value0);
				is_struct_valid &= !isnan(float_value1);
				result.float_is_out_of_range |= fabsf(float_value0) > float(0xFFFFFFFu);
				result.float_is_out_of_range |= fabsf(float_value1) > float(0xFFFFFFFu);
				break;
			}
			case blofeld::_field_real_point_3d:
			case blofeld::_field_real_vector_3d:
			{
				float float_value0 = reinterpret_cast<float*>(current_data_position)[0];
				float float_value1 = reinterpret_cast<float*>(current_data_position)[1];
				float float_value2 = reinterpret_cast<float*>(current_data_position)[2];
				is_struct_valid &= !isnan(float_value0);
				is_struct_valid &= !isnan(float_value1);
				is_struct_valid &= !isnan(float_value2);
				result.float_is_out_of_range |= fabsf(float_value0) > float(0xFFFFFFFu);
				result.float_is_out_of_range |= fabsf(float_value1) > float(0xFFFFFFFu);
				result.float_is_out_of_range |= fabsf(float_value2) > float(0xFFFFFFFu);
				break;
			}
			case blofeld::_field_real_quaternion:
			{
				float float_value0 = reinterpret_cast<float*>(current_data_position)[0];
				float float_value1 = reinterpret_cast<float*>(current_data_position)[1];
				float float_value2 = reinterpret_cast<float*>(current_data_position)[2];
				float float_value3 = reinterpret_cast<float*>(current_data_position)[4];
				is_struct_valid &= !isnan(float_value0);
				is_struct_valid &= !isnan(float_value1);
				is_struct_valid &= !isnan(float_value2);
				is_struct_valid &= !isnan(float_value3);
				result.float_is_out_of_range |= fabsf(float_value0) > float(0xFFFFFFFu);
				result.float_is_out_of_range |= fabsf(float_value1) > float(0xFFFFFFFu);
				result.float_is_out_of_range |= fabsf(float_value2) > float(0xFFFFFFFu);
				result.float_is_out_of_range |= fabsf(float_value3) > float(0xFFFFFFFu);
				break;
			}
			case blofeld::_field_long_flags:
			{
				uint32_t enum_max = current_field->string_list_definition ? current_field->string_list_definition->count : 0;
				unsigned long enum_value = __log2u(*reinterpret_cast<unsigned long*>(current_data_position));
				is_struct_valid &= enum_value < enum_max;
				break;
			}
			case blofeld::_field_string_id:
			{
				string_id value = *reinterpret_cast<string_id*>(current_data_position);
				result.string_id_value = cache_file.get_string_id(value, nullptr);
				is_struct_valid &= result.string_id_value != nullptr || value.value > 0xFFFFu;
				break;
			}
			case blofeld::_field_pad:
				for (uint32_t i = 0; i < current_field->padding; i++)
				{
					is_struct_valid &= current_data_position[i] == 0;
				}
				break;
			case blofeld::_field_tag_reference:
			{
				s_tag_reference& tag_reference = *reinterpret_cast<s_tag_reference*>(current_data_position);

				if (tag_reference.group_tag == UINT32_MAX)
				{
					is_struct_valid &= tag_reference.name_length == 0;
					is_struct_valid &= tag_reference.index == UINT16_MAX;
					is_struct_valid &= tag_reference.datum == UINT16_MAX;
				}
				else
				{
					const char* known_legacy_tag_group_name = get_known_legacy_tag_group_name(tag_reference.group_tag);
					is_struct_valid = known_legacy_tag_group_name != nullptr;
				}
				if (is_struct_valid && tag_reference.index != UINT16_MAX)
				{
					result.tag_reference_instance = cache_file.get_tag_interface(tag_reference.index);
					is_struct_valid &= result.tag_reference_instance != nullptr;
				}
				break;
			}
			case blofeld::_field_data:
			{
				s_tag_data& tag_data = *reinterpret_cast<s_tag_data*>(current_data_position);

				is_struct_valid &= tag_data.stream_flags == 0;
				is_struct_valid &= tag_data.stream_offset == 0;
				is_struct_valid &= tag_data.definition == 0;
				if (tag_data.size > 0)
				{
					char* data_address = cache_file.get_data_with_page_offset(tag_data.address);
					is_struct_valid &= cache_file.is_valid_data_address(data_address);
				}
				break;
			}
			case blofeld::_field_block:
			{
				s_tag_block& tag_block = *reinterpret_cast<s_tag_block*>(current_data_position);

				bool is_valid = true;
				is_struct_valid &= tag_block.definition_address == 0;
				if (tag_block.count == 0)
				{
					is_struct_valid &= tag_block.address == 0;
				}
				else
				{
					char* data_address_old = cache_file.get_data_with_page_offset(tag_block.address);
					char* data_address = cache_file.get_tag_block_data(tag_block);
					is_struct_valid &= cache_file.is_valid_data_address(data_address);
					is_struct_valid &= cache_file.is_valid_data_address(data_address);

					if (is_struct_valid)
					{
						result.block_is_out_of_range = tag_block.count > current_field->block_definition->max_count;

						uint32_t total_block_bytes_traversed = 0;
						for (uint32_t tag_block_index = 0; tag_block_index < tag_block.count; tag_block_index++)
						{
							uint32_t block_bytes_traversed = render_tag_struct_definition(
								tag_interface,
								level + 2,
								data_address + total_block_bytes_traversed,
								current_field->block_definition->struct_definition,
								true,
								false,
								result.block_struct_is_valid,
								is_tag_valid,
								total_block_bytes_traversed,
								_cache_file_validator_struct_type_tag_block,
								tag_block_index);
							total_block_bytes_traversed += block_bytes_traversed;
						}
					}
				}
				break;
			}
			case blofeld::_field_struct:
			{
				render_tag_struct_definition(
					tag_interface,
					level + 2,
					current_data_position,
					*current_field->struct_definition,
					false,
					render,
					is_struct_valid,
					is_tag_valid,
					parent_offset + bytes_traversed,
					_cache_file_validator_struct_type_structure);
				break;
			}
			case blofeld::_field_array:
			{
				uint32_t total_array_struct_bytes_traversed = 0;
				for (uint32_t array_index = 0; array_index < current_field->array_definition->count; array_index++)
				{
					uint32_t array_struct_bytes_traversed = render_tag_struct_definition(
						tag_interface,
						level + 2,
						current_data_position + total_array_struct_bytes_traversed,
						current_field->array_definition->struct_definition,
						false,
						render, 
						is_struct_valid,
						is_tag_valid,
						parent_offset + bytes_traversed,
						_cache_file_validator_struct_type_array,
						array_index);
					total_array_struct_bytes_traversed += array_struct_bytes_traversed;
				}
				break;
			}
			default:
			{
				was_tested = false;
				break;
			}
			}

			if (previously_invalid) result.validation_state = _validation_state_previously_invalid;
			else if (!was_tested) result.validation_state = _validation_state_unknown;
			else if (!is_struct_valid) result.validation_state = _validation_state_invalid;
			else if (result.float_is_out_of_range) result.validation_state = _validation_state_warning;
			else if (result.block_is_out_of_range) result.validation_state = _validation_state_warning;
			else if (!result.block_struct_is_valid) result.validation_state = _validation_state_warning;
			else if (is_block) result.validation_state = _validation_state_block_valid;
			else result.validation_state = _validation_state_valid;
		}

		if (render)
		{
			field_render_callback(tag_interface, current_data_position, *current_field, &result, field_type_render_callbacks[current_field->field_type]);

			switch (current_field->field_type)
			{
			case blofeld::_field_block:
			{
				s_tag_block& tag_block = *reinterpret_cast<s_tag_block*>(current_data_position);

				if (is_struct_valid)
				{
					bool is_struct_valid = true;
					char* block_data_position_old = cache_file.get_data_with_page_offset(tag_block.address);
					char* const block_data = cache_file.get_tag_block_data(tag_block);
					uint32_t total_block_bytes_traversed = 0;
					for (uint32_t tag_block_index = 0; tag_block_index < tag_block.count/* && (is_struct_valid || show_broken_block_data)*/; tag_block_index++)
					{
						char* current_block_data = block_data + total_block_bytes_traversed;
						if (!cache_file.is_valid_data_address(current_block_data))
						{
							ImGui::Dummy({ level * indent_size, 0.0f }); 
							ImGui::SameLine();
							ImGui::Text("ERROR: TAG BLOCK READ INTO INVALID MEMORY REGION!!!!!!");
							break;
						}
						uint32_t block_bytes_traversed = render_tag_struct_definition(
							tag_interface,
							level + 2,
							current_block_data,
							current_field->block_definition->struct_definition,
							true,
							render,
							is_struct_valid,
							is_tag_valid,
							total_block_bytes_traversed,
							_cache_file_validator_struct_type_tag_block,
							tag_block_index);
						total_block_bytes_traversed += block_bytes_traversed;
					}
				}
				break;
			}
			}
		}

		current_data_position += field_size;
		bytes_traversed += field_size;
	}

	if (render)
	{
		ImGui::PushStyleColor(ImGuiCol_Text, { 0.3f, 0.5f, 1.0f, 1.0f });
		ImGui::Dummy({ level * indent_size, 0.0f }); 
		ImGui::SameLine();
		switch (struct_type)
		{
		case _cache_file_validator_struct_type_array:
			ImGui::Text("ARRAY STRUCT END>%s index:%u size:[0x%X]", struct_definition.name, index, struct_size);
			break;
		case _cache_file_validator_struct_type_tag_block:
			ImGui::Text("BLOCK STRUCT END>%s index:%u size:[0x%X]", struct_definition.name, index, struct_size);
			break;
		default:
		case _cache_file_validator_struct_type_structure:
			ImGui::Text("STRUCT END>%s [0x%X]", struct_definition.name, struct_size);
			break;
		}
		ImGui::PopStyleColor();
	}

	if (render)
	{
		ImGui::EndGroup();
		ImGui::PopID();

		if (level)
		{
			ImVec2 item_rect_min = ImGui::GetItemRectMin();
			item_rect_min.x += level * indent_size;
			ImVec2 item_rect_max = ImGui::GetItemRectMax();
			ImDrawList* draw_list = ImGui::GetWindowDrawList();
			if (is_struct_valid)
			{
				draw_list->AddRectFilled(item_rect_min, item_rect_max, ImGui::ColorConvertFloat4ToU32({ 0.3f, 0.5f, 1.0f, 0.02f }));
				draw_list->AddRect(item_rect_min, item_rect_max, ImGui::ColorConvertFloat4ToU32({ 0.3f, 0.5f, 1.0f, 0.35f }));
			}
			else
			{
				draw_list->AddRectFilled(item_rect_min, item_rect_max, ImGui::ColorConvertFloat4ToU32({ 1.0f, 0.3f, 0.5f, 0.04f }));
				draw_list->AddRect(item_rect_min, item_rect_max, ImGui::ColorConvertFloat4ToU32({ 1.0f, 0.3f, 0.5f, 0.5f }));
			}


		}
	}

	is_tag_valid &= is_struct_valid;

	return bytes_traversed;
}

void c_gen3_cache_file_validator::validate_tag_instance(c_gen3_tag_interface& tag_interface, bool render, bool& is_struct_valid, bool& is_tag_valid)
{
	const blofeld::s_tag_group* group = tag_interface.get_blofeld_reflection_data();
	if (group)
	{
		char* data = tag_interface.get_data();

		is_struct_valid = true;
		is_tag_valid = true;

		uint32_t bytes_traversed = render_tag_struct_definition(
			tag_interface,
			0,
			data,
			group->block_definition.struct_definition,
			false,
			render,
			is_struct_valid,
			is_tag_valid,
			0,
			_cache_file_validator_struct_type_structure);
		debug_point;
	}
	else
	{
		is_struct_valid = false;
		is_tag_valid = false;
	}
}
