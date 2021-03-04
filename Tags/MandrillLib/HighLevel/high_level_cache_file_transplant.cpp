#include "mandrilllib-private-pch.h"
// #TODO: cache refactor
//using namespace blofeld;
//
//c_high_level_cache_file_transplant::c_high_level_cache_file_transplant(c_cache_cluster& cache_cluster, c_cache_file& cache_file) :
//	cache_cluster(cache_cluster),
//	cache_file(cache_file)
//{
//	// #TODO: Fix this. See fixes below.
//	//for (uint32_t group_index = 0; group_index < cache_file.get_tag_group_count(); group_index++)
//	//{
//	//	c_tag_group_interface* tag_group_interface = cache_file.get_tag_group_interface(group_index);
//
//	//	get_or_create_group(*tag_group_interface);
//	//}
//
//	for (c_tag_interface& tag_interface : c_reference_loop(cache_file.get_tag_interfaces(), cache_file.get_tag_count()))
//	{
//		h_tag* high_level_tag = tag_interface_to_high_level(tag_interface);
//
//		if (high_level_tag == nullptr)
//		{
//			continue;
//		}
//
//		s_tag_pair tag_pair = { tag_interface, *high_level_tag };
//		tags_and_interface.emplace_back(tag_pair);
//	}
//
//	auto transplant_high_level_tags = [this](uint32_t index)
//	{
//		s_tag_pair& tag_pair = tags_and_interface[index];
//
//		h_tag& high_level_tag = tag_pair.high_level_tag;
//		c_tag_interface& tag_interface = tag_pair.tag_interface;
//
//		const char* raw_tag_data = tag_interface.get_data();
//
//		const blofeld::s_tag_group* tag_group = tag_interface.get_blofeld_reflection_data();
//		DEBUG_ASSERT(tag_group != nullptr);
//		const blofeld::s_tag_struct_definition& tag_struct_definition = tag_group->block_definition.struct_definition;
//
//		transplant_data(high_level_tag, raw_tag_data, tag_struct_definition);
//	};
//	//tbb::parallel_for(0u, static_cast<uint32_t>(tags_and_interface.size()), transplant_high_level_tags);
//	for (uint32_t i = 0; i < tags_and_interface.size(); i++) transplant_high_level_tags(i);
//}
//
//c_high_level_cache_file_transplant::~c_high_level_cache_file_transplant()
//{
//
//}
//
//void c_high_level_cache_file_transplant::transplant_data(h_object& high_level, const char* const low_level_data, const blofeld::s_tag_struct_definition& struct_definition)
//{
//	e_engine_type const engine_type = cache_file.get_engine_type();
//	e_platform_type const platform_type = cache_file.get_platform_type();
//	e_build const build = _build_not_set;
//
//	const char* current_data_position = low_level_data;
//	for (const s_tag_field* field = struct_definition.fields; field->field_type != _field_terminator; field++)
//	{
//		uint32_t field_skip_count;
//		if (skip_tag_field_version(*field, engine_platform_build, field_skip_count))
//		{
//			field += field_skip_count;
//			continue;
//		}
//
//		void* high_level_field_data = high_level.get_field_data(*field);
//
//		uint32_t field_size = get_blofeld_field_size(*field, engine_platform_build);
//
//		if (high_level_field_data != nullptr)
//		{
//			switch (field->field_type)
//			{
//			case _field_string:
//			case _field_long_string:
//			case _field_char_integer:
//			case _field_short_integer:
//			case _field_long_integer:
//			case _field_int64_integer:
//			case _field_angle:
//			case _field_point_2d:
//			case _field_rectangle_2d:
//			case _field_rgb_color:
//			case _field_argb_color:
//			case _field_real:
//			case _field_real_fraction:
//			case _field_real_point_2d:
//			case _field_real_point_3d:
//			case _field_real_vector_2d:
//			case _field_real_vector_3d:
//			case _field_real_quaternion:
//			case _field_real_euler_angles_2d:
//			case _field_real_euler_angles_3d:
//			case _field_real_plane_2d:
//			case _field_real_plane_3d:
//			case _field_real_rgb_color:
//			case _field_real_argb_color:
//			case _field_real_hsv_color:
//			case _field_real_ahsv_color:
//			case _field_short_bounds:
//			case _field_angle_bounds:
//			case _field_real_bounds:
//			case _field_real_fraction_bounds:
//			case _field_tag:
//			case _field_long_block_flags:
//			case _field_word_block_flags:
//			case _field_byte_block_flags:
//			case _field_char_block_index:
//			case _field_custom_char_block_index:
//			case _field_short_block_index:
//			case _field_custom_short_block_index:
//			case _field_long_block_index:
//			case _field_custom_long_block_index:
//			case _field_byte_integer:
//			case _field_word_integer:
//			case _field_dword_integer:
//			case _field_qword_integer:
//			case _field_pointer:
//			case _field_half:
//			{
//				memcpy(high_level_field_data, current_data_position, field_size);
//				break;
//			}
//			case _field_char_enum:
//			{
//				long data = *reinterpret_cast<const char*>(current_data_position);
//				memcpy(high_level_field_data, &data, sizeof(data));
//				break;
//			}
//			case _field_enum:
//			{
//				long data = *reinterpret_cast<const short*>(current_data_position);
//				memcpy(high_level_field_data, &data, sizeof(data));
//				break;
//			}
//			case _field_long_enum:
//			{
//				long data = *reinterpret_cast<const long*>(current_data_position);
//				memcpy(high_level_field_data, &data, sizeof(data));
//				break;
//			}
//			case _field_byte_flags:
//			{
//				dword data = *reinterpret_cast<const byte*>(current_data_position);
//				memcpy(high_level_field_data, &data, sizeof(data));
//				break;
//			}
//			case _field_word_flags:
//			{
//				dword data = *reinterpret_cast<const word*>(current_data_position);
//				memcpy(high_level_field_data, &data, sizeof(data));
//				break;
//			}
//			case _field_long_flags:
//			{
//				dword data = *reinterpret_cast<const dword*>(current_data_position);
//				memcpy(high_level_field_data, &data, sizeof(data));
//				break;
//			}
//			case _field_old_string_id:
//			case _field_string_id:
//			{
//				if (const char* string_id_value = cache_file.get_string_id(*reinterpret_cast<const string_id*>(current_data_position)))
//				{
//					h_string_id& string_id_storage = *reinterpret_cast<decltype(&string_id_storage)>(high_level_field_data);
//					string_id_storage = string_id_value;
//				}
//				break;
//			}
//			case _field_block:
//			{
//				const blofeld::s_tag_struct_definition& block_struct_definition = field->block_definition->struct_definition;
//				const s_tag_block& tag_block = *reinterpret_cast<decltype(&tag_block)>(current_data_position);
//
//				h_block& block_storage = *reinterpret_cast<decltype(&block_storage)>(high_level_field_data);
//				uint32_t const block_struct_size = calculate_struct_size(engine_platform_build, block_struct_definition);
//				const char* const block_data = cache_file.get_tag_block_data(tag_block);
//
//				//if (tag_block.count < 1024)
//				{
//					block_storage.reserve(tag_block.count);
//
//					const char* current_block_data_position = block_data;
//					for (uint32_t block_index = 0; block_index < tag_block.count; block_index++)
//					{
//						h_object& type = block_storage.emplace_back();
//						transplant_data(type, current_block_data_position, block_struct_definition);
//
//						current_block_data_position += block_struct_size;
//					}
//				}
//				//else
//				//{
//				//	block_storage.resize(tag_block.count);
//
//				//	auto transplant_high_level_block = [this, &block_storage, block_data, block_struct_size, block_struct_definition](uint32_t index)
//				//	{
//				//		const void* current_block_data = block_data + block_struct_size * index;
//
//				//		h_object& type = block_storage.get(index);
//				//		transplant_data(type, block_data, block_struct_definition);
//				//	};
//				//	tbb::parallel_for(0u, static_cast<uint32_t>(tag_block.count), transplant_high_level_block);
//				//}
//
//				break;
//			}
//			case _field_struct:
//			{
//				h_object& struct_storage = *reinterpret_cast<decltype(&struct_storage)>(high_level_field_data);
//				transplant_data(struct_storage, current_data_position, *field->struct_definition);
//				break;
//			}
//			case _field_array:
//			{
//				h_enumerable& array_storage = *reinterpret_cast<decltype(&array_storage)>(high_level_field_data);
//				const char* raw_array_data_position = current_data_position;
//
//				uint32_t const array_elements_count = field->array_definition->count(engine_type);
//				for (uint32_t array_index = 0; array_index < array_elements_count; array_index++)
//				{
//					h_object& array_element_storage = array_storage[array_index];
//
//					transplant_data(array_element_storage, raw_array_data_position, field->array_definition->struct_definition);
//
//					raw_array_data_position += array_element_storage.get_low_level_type_size();
//				}
//				break;
//			}
//			case _field_tag_reference:
//			{
//				const s_tag_reference& tag_reference = *reinterpret_cast<decltype(&tag_reference)>(current_data_position);
//				h_tag*& tag_ref_storage = *reinterpret_cast<decltype(&tag_ref_storage)>(high_level_field_data);
//
//				c_tag_interface* tag_reference_tag_interface = cache_file.get_tag_interface(tag_reference.index);
//				h_tag* tag_reference_high_level_tag = get_high_level_tag_by_tag_interface(tag_reference_tag_interface);
//
//				tag_ref_storage = tag_reference_high_level_tag;
//				break;
//			}
//			case _field_data:
//			{
//				const s_tag_data& tag_data = *reinterpret_cast<decltype(&tag_data)>(current_data_position);
//				h_data& data_storage = *reinterpret_cast<decltype(&data_storage)>(high_level_field_data);
//				
//				const char* tag_data_data = cache_file.get_tag_data(tag_data);
//				if (tag_data_data != nullptr)
//				{
//					data_storage.clear();
//					data_storage.insert(data_storage.begin(), tag_data_data, tag_data_data + tag_data.size);
//				}
//				break;
//			}
//			case _field_pageable:
//			{
//				const s_tag_resource& tag_resource = *reinterpret_cast<decltype(&tag_resource)>(current_data_position);
//				h_resource& resource_storage = *reinterpret_cast<decltype(&resource_storage)>(high_level_field_data);
//
//				resource_storage._original_resource = tag_resource;
//				break;
//			}
//			case _field_api_interop:
//			{
//				//const s_tag_interop& tag_interop = *reinterpret_cast<decltype(&tag_interop)>(current_data_position);
//				//h_interop& interop_storage = *reinterpret_cast<decltype(&interop_storage)>(high_level_field_data);
//
//				//interop_storage._original_interop = tag_interop;
//				//interop_storage._interop_fixup_index = -1;
//
//				//if (c_haloreach_cache_file* haloreach_cache_file = dynamic_cast<decltype(haloreach_cache_file)>(&cache_file))
//				//{
//				//	using namespace blofeld::haloreach;
//				//	using namespace cache_compiler;
//
//				//	uint32_t tag_interop_page_offset = haloreach_cache_file->calculate_page_offset_from_pointer(current_data_position);
//
//				//	auto cache_file_tag_interop_type_fixups = reinterpret_cast<s_cache_file_tag_interop_type_fixup*>(haloreach_cache_file->tags_buffer + haloreach_cache_file->convert_virtual_address(haloreach_cache_file->haloreach_cache_file_tags_header->tag_interop_table.address));
//				//	uint32_t tag_interop_count = haloreach_cache_file->haloreach_cache_file_tags_header->tag_interop_table.count;
//				//	for (uint32_t interop_type_fixup_index = 0; interop_type_fixup_index < tag_interop_count; interop_type_fixup_index++)
//				//	{
//				//		s_cache_file_tag_interop_type_fixup& cache_file_tag_interop_type_fixup = cache_file_tag_interop_type_fixups[interop_type_fixup_index];
//
//				//		if (cache_file_tag_interop_type_fixup.page_address == tag_interop_page_offset)
//				//		{
//				//			interop_storage._interop_fixup_index = interop_type_fixup_index;
//				//			debug_point;
//				//		}
//
//				//	}
//				//}
//
//				//if (interop_storage._interop_fixup_index == -1)
//				//{
//				//	debug_point;
//				//}
//
//				break;
//			}
//			case _field_vertex_buffer:
//			{
//				throw; // currently unused
//			}
//			case _field_pad:
//			case _field_useless_pad:
//			case _field_skip:
//			case _field_non_cache_runtime_value:
//			case _field_explanation:
//			case _field_custom:
//			case _field_terminator:
//			{
//
//			}
//			}
//		}
//
//		current_data_position += field_size;
//	}
//}
//
//h_tag* c_high_level_cache_file_transplant::get_high_level_tag_by_tag_interface(c_tag_interface* tag_interface)
//{
//	if (tag_interface == nullptr)
//	{
//		return nullptr;
//	}
//	if (tag_interface->is_null())
//	{
//		return nullptr;
//	}
//
//	for (s_tag_pair& tag_pair : tags_and_interface)
//	{
//		if (tag_interface == &tag_pair.tag_interface)
//		{
//			return &tag_pair.high_level_tag;
//		}
//	}
//
//	return nullptr;
//}
//
//h_tag* c_high_level_cache_file_transplant::tag_interface_to_high_level(c_tag_interface& tag_interface)
//{
//	if (tag_interface.is_null())
//	{
//		return nullptr;
//	}
//
//	// #TODO: Fix this, currently returns null.
//	//c_tag_group_interface* group_interface = tag_interface.get_tag_group_interface();
//	//DEBUG_ASSERT(group_interface != nullptr);
//
//	c_virtual_tag_interface* virtual_tag_interface = tag_interface.get_virtual_tag_interface();
//	DEBUG_ASSERT(virtual_tag_interface != nullptr);
//
//	const blofeld::s_tag_group* tag_group = virtual_tag_interface->tag_interface.get_blofeld_reflection_data();
//	DEBUG_ASSERT(tag_group != nullptr);
//
//	h_group& group = get_or_create_group(*tag_group);
//
//	const char* filepath = tag_interface.get_path_with_group_name_cstr();
//	h_tag& high_level_tag = group.create_tag_instance(filepath);
//
//	return &high_level_tag;
//}
//
//h_group& c_high_level_cache_file_transplant::get_or_create_group(/*c_tag_group_interface& group_interface*/ const blofeld::s_tag_group& tag_group)
//{
//	for (s_group_pair& group_pair : groups_and_interface)
//	{
//		if (&tag_group == &group_pair.tag_group)
//		{
//			return group_pair.high_level_group;
//		}
//	}
//
//	// #TODO: Fix this, currently returns null.
//	//const blofeld::s_tag_group* tag_group = group_interface.get_blofeld_tag_group();
//	//DEBUG_ASSERT(tag_group != nullptr);
//
//	e_engine_type const engine_type = cache_file.get_engine_type();
//	e_platform_type const platform_type = cache_file.get_platform_type();
//	e_build const build = _build_not_set;
//
//	h_group* group = new h_group(engine_platform_build, tag_group);
//
//	s_group_pair group_pair = { /*group_interface*/ tag_group, *group };
//	groups_and_interface.emplace_back(group_pair);
//
//	return *group;
//}
