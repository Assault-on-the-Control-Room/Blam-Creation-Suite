#include "tagvalidate-private-pch.h"

static uint32_t k_max_group_iterations = 5;

c_gen3_cache_file_validator2::c_gen3_cache_file_validator2(c_gen3_cache_file& cache_file) :
	cache_file(cache_file),
	engine_type(cache_file.get_engine_type()),
	platform_type(cache_file.get_platform_type())
{
}

c_gen3_cache_file_validator2::~c_gen3_cache_file_validator2()
{
}

uint32_t c_gen3_cache_file_validator2::get_struct_size(const blofeld::s_tag_struct_definition& struct_definition)
{
	uint32_t size = 0;

	for (const blofeld::s_tag_field* current_field = struct_definition.fields; current_field->field_type != blofeld::_field_terminator; current_field++)
	{
		uint32_t field_skip_count;
		if (skip_tag_field_version(*current_field, engine_type, platform_type, _build_not_set, field_skip_count))
		{
			current_field += field_skip_count;
			continue;
		}

		uint32_t field_size = get_field_size(*current_field);
		size += field_size;
	}

	return size;
}

uint32_t c_gen3_cache_file_validator2::get_field_size(const blofeld::s_tag_field& field)
{
	uint32_t field_size = get_blofeld_field_size(platform_type, field.field_type);
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
	case blofeld::_field_array:							return get_struct_size(field.array_definition->struct_definition) * field.array_definition->count(engine_type);	// dynamic
	}
	throw;
}

struct s_memory_region
{
	s_memory_region(
		const blofeld::s_tag_struct_definition* struct_definition,
		const blofeld::s_tag_block_definition* block_definition,
		const blofeld::s_tag_array_definition* array_definition,
		c_tag_interface* tag_interface,
		const char* name,
		char* data_start,
		char* data_end,
		uint32_t struct_size,
		uint32_t struct_count
	) :
		struct_definition(struct_definition),
		block_definition(block_definition),
		tag_interface(tag_interface),
		name(name),
		data_start(data_start),
		data_end(data_end),
		struct_size(struct_size),
		struct_count(struct_count)
	{

	}
	void* data_start;
	void* data_end;
	const char* name;
	const blofeld::s_tag_struct_definition* struct_definition;
	const blofeld::s_tag_block_definition* block_definition;
	c_tag_interface* tag_interface;
	uint32_t struct_size;
	uint32_t struct_count;

	bool operator ==(const s_memory_region& b) const
	{
		bool is_same = data_start == b.data_start && block_definition == b.block_definition;
		return is_same;
	}
};

struct s_tag_validation_data
{
	s_tag_validation_data(c_tag_interface& tag_interface) :
		tag_interface(tag_interface),
		unsorted_memory_regions(),
		sorted_memory_regions(),
		data_start(),
		data_end()
	{

	}
	void* data_start;
	void* data_end;
	c_tag_interface& tag_interface;
	std::vector<s_memory_region*> unsorted_memory_regions;
	std::vector<s_memory_region*> sorted_memory_regions;

	void sort()
	{
		sorted_memory_regions = unsorted_memory_regions;

		std::sort(
			sorted_memory_regions.begin(),
			sorted_memory_regions.end(),
			[](s_memory_region* a, s_memory_region* b)
			{
				return a->data_start < b->data_start;
			});

		std::vector<s_memory_region*>::iterator new_end = sorted_memory_regions.end();
		do
		{
			std::vector<s_memory_region*>::iterator new_end = std::unique(
				sorted_memory_regions.begin(),
				sorted_memory_regions.end(),
				[](s_memory_region* a, s_memory_region* b)
				{
					return *a == *b;
				});
			if (new_end == sorted_memory_regions.end())
			{
				break;
			}
			sorted_memory_regions.erase(new_end, sorted_memory_regions.end());
		} while (true);

		ASSERT(!sorted_memory_regions.empty());
		data_start = sorted_memory_regions[0]->data_start;
		data_end = sorted_memory_regions[0]->data_end;
		for (uint32_t i = 1; i < sorted_memory_regions.size(); i++)
		{
			s_memory_region& memory_region = *sorted_memory_regions[i];

			data_start = __min(data_start, memory_region.data_start);
			data_end = __max(data_end, memory_region.data_end);
		}
	}
};

#define padding(align, value) reinterpret_cast<char*>((reinterpret_cast<intptr_t>(memory_region_a_end + (intptr_t(align) - intptr_t(1))) / intptr_t(align)) * intptr_t(align))


void c_gen3_cache_file_validator2::validate_tag_instances()
{
	std::vector<s_tag_validation_data*> validation_datas;
	validation_datas.resize(cache_file.get_tag_count());

	volatile uint32_t* current_validation_data_index = new uint32_t();
	s_tag_validation_data** current_validation_datas = validation_datas.data();

	//tbb::task_group g;
	for (c_tag_interface* tag_interface_pointer : c_range_loop(cache_file.get_tag_interfaces(), cache_file.get_tag_count()))
	{
		if (tag_interface_pointer->is_null())
		{
			continue;
		}

		//g.run([this, tag_interface_pointer, current_validation_datas, current_validation_data_index]
			{
				c_tag_interface& tag_interface = *tag_interface_pointer;

				const blofeld::s_tag_group* group = tag_interface.get_blofeld_reflection_data();
				ASSERT(group != nullptr);
				char* data = tag_interface.get_data();

				s_tag_validation_data* validation_data = validate_tag_group(
					tag_interface,
					data,
					group->block_definition.struct_definition);

				validation_data->sort();

				uint32_t validation_data_index = InterlockedIncrement(current_validation_data_index) - 1;
				current_validation_datas[validation_data_index] = validation_data;
				//validation_datas.push_back(validation_data);
			
			}
		//);
	}
	//g.wait();
	validation_datas.resize(*current_validation_data_index);
	delete current_validation_data_index;

	//std::sort(
	//	validation_datas.begin(),
	//	validation_datas.end(),
	//	[](s_tag_validation_data* a, s_tag_validation_data* b)
	//	{
	//		return a->data_start < b->data_start;
	//	});

	//for (uint32_t validation_index = 0; validation_index < (validation_datas.size() - 1); validation_index++)
	//{
	//	uint32_t next_validation_index = validation_index + 1;

	//	s_tag_validation_data& validation_data_a = *validation_datas[validation_index];
	//	s_tag_validation_data& validation_data_b = *validation_datas[next_validation_index];

	//	if (validation_data_a.tag_interface.get_group_tag() != blofeld::ACHIEVEMENTS_TAG)
	//	{
	//		continue;
	//	}
	//}

	c_tag_interface* const* tag_interfaces = cache_file.get_tag_interfaces();

	if (tag_interfaces == nullptr)
	{
		return;
	}

	s_tag_validation_data validation_data(**tag_interfaces);

	for (s_tag_validation_data* current_validation_data : validation_datas)
	{
		validation_data.unsorted_memory_regions.insert(
			validation_data.unsorted_memory_regions.end(), 
			current_validation_data->sorted_memory_regions.begin(), 
			current_validation_data->sorted_memory_regions.end());
	}

	validation_data.sort();

	uint32_t error_count = 0;

	for (uint32_t region_index = 0; region_index < (validation_data.sorted_memory_regions.size() - 1); region_index++)
	{
		uint32_t next_region_index = region_index + 1;

		s_memory_region& memory_region_a = *validation_data.sorted_memory_regions[region_index];
		s_memory_region& memory_region_b = *validation_data.sorted_memory_regions[next_region_index];

		char* memory_region_a_end = static_cast<char*>(memory_region_a.data_end);
		memory_region_a_end = padding(4, memory_region_a_end);

		char* memory_region_b_start = static_cast<char*>(memory_region_b.data_start);

		if (memory_region_a_end != memory_region_b_start)
		{
			if (memory_region_a_end > memory_region_b_start)
			{
				uint32_t overlap_bytes = static_cast<uint32_t>(memory_region_a_end - memory_region_b_start);
				if (overlap_bytes != memory_region_a.struct_size)
				{
					if (memory_region_a.struct_count > 1)
					{
						if (memory_region_a.tag_interface)
						{
							c_console::write_line("TAG> '%s'", memory_region_a.tag_interface->get_path_with_group_name_cstr());
						}
						uint32_t instance_overlap_bytes = overlap_bytes / memory_region_a.struct_count;
						c_console::write_line("'%s' '%s' [OVERLAP] total:%ubytes instance:%ubytes", memory_region_a.name, memory_region_b.name, overlap_bytes, instance_overlap_bytes);
						c_console::write_line("0x%p 0x%p", memory_region_a_end, memory_region_b_start);
						error_count++;
					}
					else
					{
						if (memory_region_a.tag_interface)
						{
							c_console::write_line("TAG> '%s'", memory_region_a.tag_interface->get_path_with_group_name_cstr());
						}
						c_console::write_line("'%s' '%s' [OVERLAP] total:%ubytes", memory_region_a.name, memory_region_b.name, overlap_bytes);
						c_console::write_line("0x%p 0x%p", memory_region_a_end, memory_region_b_start);
						error_count++;
					}
				}
			}
			else
			{
				uint32_t hole_bytes = static_cast<uint32_t>(memory_region_b_start - memory_region_a_end);
				if (memory_region_a.struct_count > 1)
				{
					if (memory_region_a.tag_interface)
					{
						c_console::write_line("TAG> '%s'", memory_region_a.tag_interface->get_path_with_group_name_cstr());
					}
					uint32_t instance_hole_bytes = hole_bytes / memory_region_a.struct_count;
					c_console::write_line("'%s' '%s' [HOLE] total:%ubytes instance:%ubytes", memory_region_a.name, memory_region_b.name, hole_bytes, instance_hole_bytes);
					c_console::write_line("0x%p 0x%p", memory_region_a_end, memory_region_b_start);
					error_count++;
				}
				else
				{
					if (memory_region_a.tag_interface)
					{
						c_console::write_line("TAG> '%s'", memory_region_a.tag_interface->get_path_with_group_name_cstr());
					}
					c_console::write_line("'%s' '%s' [HOLE] total:%ubytes", memory_region_a.name, memory_region_b.name, hole_bytes);
					c_console::write_line("0x%p 0x%p", memory_region_a_end, memory_region_b_start);;
					error_count++;
				}
			}

			//if (error_count >= 1000)
			//{
			//	c_console::write_line("too many errors exiting validation");
			//	break;
			//}
		}

	}
	c_console::write_line("found %u memory region errors", error_count);

	debug_point;
}

s_tag_validation_data* c_gen3_cache_file_validator2::validate_tag_group(c_tag_interface& tag_interface, char* data, const blofeld::s_tag_struct_definition& struct_definition)
{
	if (tag_interface.is_null())
	{
		return nullptr;
	}

	s_tag_validation_data* validation_data = new s_tag_validation_data
	{
		tag_interface
	};

	validate_tag_struct(*validation_data, data, struct_definition);

	return validation_data;
}

void validate_tag_api_interop(s_tag_validation_data& validation_data, char* data, const blofeld::s_tag_struct_definition& struct_definition)
{

}

void c_gen3_cache_file_validator2::validate_tag_struct(
	s_tag_validation_data& validation_data,
	char* const data,
	const blofeld::s_tag_struct_definition& struct_definition)
{
	uint32_t struct_size = calculate_struct_size(engine_type, platform_type, _build_not_set, struct_definition);
	char* start_data = data;
	char* end_data = data + struct_size;
	s_memory_region* memory_region = new s_memory_region
	{
		&struct_definition,
		nullptr,
		nullptr,
		&validation_data.tag_interface,
		struct_definition.name,
		start_data,
		end_data,
		struct_size,
		1
	};
	validation_data.unsorted_memory_regions.push_back(memory_region);


	char* current_struct_data_position = data;
	traverse_tag_struct(validation_data, current_struct_data_position, struct_definition);
}

void c_gen3_cache_file_validator2::validate_tag_block(
	s_tag_validation_data& validation_data,
	char* data,
	const blofeld::s_tag_block_definition& block_definition)
{
	s_tag_block& tag_block = *reinterpret_cast<s_tag_block*>(data);

	if (tag_block.address == 0xFFFFFFFFu || tag_block.count == 0xFFFFFFFFu)
	{
		return;
	}
	if (tag_block.address == 0 || tag_block.count == 0)
	{
		return;
	}

	uint32_t struct_size = calculate_struct_size(engine_type, platform_type, _build_not_set, block_definition.struct_definition);
	uint32_t struct_count = tag_block.count;
	char* current_block_data_position = cache_file.get_tag_block_data(tag_block);
	char* start_data = current_block_data_position;
	ASSERT(start_data);

	char* end_data = current_block_data_position + struct_size * struct_count;
	s_memory_region* memory_region = new s_memory_region
	{
		&block_definition.struct_definition,
		&block_definition,
		nullptr,
		&validation_data.tag_interface,
		block_definition.name,
		start_data,
		end_data,
		struct_size,
		struct_count
	};
	validation_data.unsorted_memory_regions.push_back(memory_region);

	for (uint32_t struct_index = 0; struct_index < struct_count; struct_index++)
	{
		traverse_tag_struct(validation_data, current_block_data_position, block_definition.struct_definition);
		current_block_data_position += struct_size;
	}
}

void c_gen3_cache_file_validator2::traverse_tag_array(
	s_tag_validation_data& validation_data,
	char* data,
	const blofeld::s_tag_array_definition& array_definition)
{
	ASSERT(data);

	uint32_t struct_size = calculate_struct_size(engine_type, platform_type, _build_not_set, array_definition.struct_definition);
	uint32_t struct_count = array_definition.count(engine_type);

	char* const start_data = data;
	char* const end_data = start_data + struct_size * struct_count;

	//s_memory_region* memory_region = new s_memory_region
	//{
	//	&array_definition.struct_definition,
	//	nullptr,
	//	&array_definition,
	//	&validation_data.tag_interface,
	//	array_definition.name,
	//	start_data,
	//	end_data,
	//	struct_size,
	//	struct_count
	//};
	//validation_data.unsorted_memory_regions.push_back(memory_region);

	char* current_array_data_position = start_data;
	for (uint32_t struct_index = 0; struct_index < struct_count; struct_index++)
	{
		traverse_tag_struct(validation_data, current_array_data_position, array_definition.struct_definition);
		current_array_data_position += struct_size;
	}
}

void c_gen3_cache_file_validator2::validate_tag_api_interop(
	s_tag_validation_data& validation_data,
	char* data,
	const blofeld::s_tag_struct_definition& struct_definition)
{
	s_tag_interop& tag_interop = *reinterpret_cast<s_tag_interop*>(data);

	ASSERT(tag_interop.definition_address == 0);

	if (tag_interop.descriptor == 0xFFFFFFFFu)
	{
		return;
	}
	if (tag_interop.descriptor == 0)
	{
		return;
	}

	uint32_t const struct_size = calculate_struct_size(engine_type, platform_type, _build_not_set, struct_definition);
	uint32_t const struct_count = 1;

	char* const start_data = cache_file.get_tag_interop_data(tag_interop);
	s_tag_data& tag_data = *reinterpret_cast<s_tag_data*>(start_data);
	char* end_data = start_data + struct_size * struct_count;

	ASSERT(start_data);

	s_memory_region* memory_region = new s_memory_region
	{
		nullptr,
		nullptr,
		nullptr,
		&validation_data.tag_interface,
		struct_definition.name,
		start_data,
		end_data,
		struct_size,
		struct_count
	};
	validation_data.unsorted_memory_regions.push_back(memory_region);

	char* current_interop_data_position = start_data;
	for (uint32_t struct_index = 0; struct_index < struct_count; struct_index++)
	{
		traverse_tag_struct(validation_data, current_interop_data_position, struct_definition);
		current_interop_data_position += struct_size;
	}
}

void c_gen3_cache_file_validator2::validate_tag_pageable(
	s_tag_validation_data& validation_data,
	char* data,
	const blofeld::s_tag_struct_definition& struct_definition)
{
	s_tag_resource& tag_resource = *reinterpret_cast<s_tag_resource*>(data);

	ASSERT(tag_resource.definition_address == 0);

	if (!tag_resource.resource_handle.valid())
	{
		return;
	}

	uint32_t index = tag_resource.resource_handle.get_absolute_index();
	uint32_t id = tag_resource.resource_handle.get_identifier();

	c_tag_group_interface* cache_file_resource_gestalt_group = cache_file.get_tag_group_interface_by_group_id(blofeld::CACHE_FILE_RESOURCE_GESTALT_TAG);
	if (cache_file_resource_gestalt_group == nullptr)
	{
		return; // throw error?
	}
	if (cache_file_resource_gestalt_group->get_tag_interfaces_count() == 0)
	{
		return; // throw error?
	}

	//c_tag_interface* cache_file_resource_gestalt = cache_file_resource_gestalt_group->get_tag_interfaces()[0];
	//if (v_tag<blofeld::haloreach::s_cache_file_resource_gestalt_block_struct>* haloreach_cache_file_resource_gestalt = dynamic_cast<decltype(haloreach_cache_file_resource_gestalt)>(cache_file_resource_gestalt->get_virtual_tag_interface()))
	//{
	//	blofeld::haloreach::s_cache_file_resource_data_block_block_struct& cache_file_resource_data_block = haloreach_cache_file_resource_gestalt->resources_block[index];
	//	char* data = cache_file.get_tag_data(haloreach_cache_file_resource_gestalt->naive_resource_control_data); // #TODO: virtual tag data [tag_data.get_data()]
	//	char* pagable_data = data + cache_file_resource_data_block.naive_data_offset;

	//	traverse_tag_struct(validation_data, pagable_data, struct_definition);

	//	debug_point;
	//}
	//else if (v_tag<blofeld::halo3::s_cache_file_resource_gestalt_block_struct>* halo3_cache_file_resource_gestalt = dynamic_cast<decltype(halo3_cache_file_resource_gestalt)>(cache_file_resource_gestalt->get_virtual_tag_interface()))
	//{
	//	return; // throw error?
	//}
	//else
	//{
	//	return; // throw error?
	//}


	




	debug_point;

	//uint32_t const struct_size = calculate_struct_size(engine_type, platform_type, _build_not_set, struct_definition);
	//uint32_t const struct_count = 1;

	//char* const start_data = cache_file.get_tag_interop_data(tag_resource);
	//char* end_data = start_data + struct_size * struct_count;

	//ASSERT(start_data);

	//s_memory_region* memory_region = new s_memory_region
	//{
	//	nullptr,
	//	nullptr,
	//	nullptr,
	//	&validation_data.tag_interface,
	//	struct_definition.name,
	//	start_data,
	//	end_data,
	//	struct_size,
	//	struct_count
	//};
	//validation_data.unsorted_memory_regions.push_back(memory_region);

	//char* current_interop_data_position = start_data;
	//for (uint32_t struct_index = 0; struct_index < struct_count; struct_index++)
	//{
	//	traverse_tag_struct(validation_data, current_interop_data_position, struct_definition);
	//	current_interop_data_position += struct_size;
	//}
}

void c_gen3_cache_file_validator2::validate_tag_data(s_tag_validation_data& validation_data, char* const data, const char* field_name)
{
	s_tag_data& tag_data = *reinterpret_cast<s_tag_data*>(data);

	if (tag_data.address == 0xFFFFFFFFu || tag_data.size == 0xFFFFFFFFu)
	{
		return;
	}
	if (tag_data.address == 0 || tag_data.size == 0)
	{
		return;
	}

	char* current_data_position = cache_file.get_tag_data(tag_data);
	char* start_data = current_data_position;
	char* end_data = start_data + tag_data.size;
	s_memory_region* memory_region = new s_memory_region
	{
		nullptr,
		nullptr,
		nullptr,
		&validation_data.tag_interface,
		field_name,
		start_data,
		end_data,
		(uint32_t)tag_data.size,
		1
	};
	validation_data.unsorted_memory_regions.push_back(memory_region);
}

void c_gen3_cache_file_validator2::traverse_tag_struct(
	s_tag_validation_data& validation_data,
	char* const data,
	const blofeld::s_tag_struct_definition& struct_definition
)
{
	char* current_data_position = data;
	for (const blofeld::s_tag_field* current_field = struct_definition.fields; current_field->field_type != blofeld::_field_terminator; current_field++)
	{
		uint32_t field_skip_count;
		if (skip_tag_field_version(*current_field, engine_type, platform_type, _build_not_set, field_skip_count))
		{
			current_field += field_skip_count;
			continue;
		}

		uint32_t field_size = get_field_size(*current_field);

		switch (current_field->field_type)
		{
		case blofeld::_field_array:
		{
			traverse_tag_array(validation_data, current_data_position, *current_field->array_definition);
			break;
		}
		case blofeld::_field_struct:
		{
			traverse_tag_struct(validation_data, current_data_position, *current_field->struct_definition);
			break;
		}
		case blofeld::_field_block:
		{
			validate_tag_block(validation_data, current_data_position, *current_field->block_definition);
			break;
		}
		case blofeld::_field_data:
		{
			validate_tag_data(validation_data, current_data_position, current_field->name);
			break;
		}
		case blofeld::_field_pageable:
		{
			//ASSERT(current_field->struct_definition);
			if (current_field->struct_definition)
			{
				validate_tag_pageable(validation_data, current_data_position, *current_field->struct_definition);
			}
			break;
		}
		case blofeld::_field_api_interop:
		{
			ASSERT(current_field->struct_definition);
			validate_tag_api_interop(validation_data, current_data_position, *current_field->struct_definition);
			break;
		}
		}

		current_data_position += field_size;
	}
}