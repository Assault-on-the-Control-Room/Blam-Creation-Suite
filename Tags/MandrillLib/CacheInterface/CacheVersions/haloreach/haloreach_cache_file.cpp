#include "mandrilllib-private-pch.h"

using namespace gen3;
using namespace haloreach;

c_haloreach_cache_file::c_haloreach_cache_file(const std::wstring& map_filepath) :
	c_gen3_cache_file(map_filepath, _engine_type_haloreach, _platform_type_pc),
	haloreach_cache_file_header(*static_cast<haloreach::s_cache_file_header*>(&cache_file_header)),
	haloreach_cache_file_tags_header(nullptr)
{
	char* cache_file_data = virtual_memory_container.get_data();

	const s_section_cache& debug_section = get_section(gen3::_cache_file_section_index_debug);
	const s_section_cache& resource_section = get_section(gen3::_cache_file_section_index_resource);
	const s_section_cache& tags_section = get_section(gen3::_cache_file_section_index_tags);
	const s_section_cache& localization_section = get_section(gen3::_cache_file_section_index_localization);

	if (resource_section.size > 0)
	{

	}

	if (debug_section.size > 0)
	{
		string_ids_buffer = debug_section.masked_data + haloreach_cache_file_header.string_table_offset;
		string_id_indices = reinterpret_cast<long*>(debug_section.masked_data + haloreach_cache_file_header.string_table_indices_offset);

		filenames_buffer = debug_section.masked_data + haloreach_cache_file_header.file_table_offset;
		filename_indices = reinterpret_cast<long*>(debug_section.masked_data + haloreach_cache_file_header.file_table_indices_offset);

		string_id_guesstimator = new c_cache_file_string_id_guesstimator(*this);
	}

	if (tags_section.size > 0)
	{
		haloreach_cache_file_tags_header = reinterpret_cast<s_cache_file_tags_header*>(tags_section.masked_data + (cache_file_header.tags_header_address - cache_file_header.virtual_base_address));

		tags_buffer = tags_section.masked_data + haloreach_cache_file_header.tag_buffer_offset;
		haloreach_cache_file_tags_header = reinterpret_cast<s_cache_file_tags_header*>(tags_buffer + convert_virtual_address(haloreach_cache_file_header.tags_header_address));

		cache_file_tag_groups = reinterpret_cast<s_cache_file_tag_group*>(tags_buffer + convert_virtual_address(haloreach_cache_file_tags_header->tag_groups.address));
		for (uint32_t group_index = 0; group_index < haloreach_cache_file_tags_header->tag_groups.count; group_index++)
		{
			s_cache_file_tag_group& cache_file_tag_group = cache_file_tag_groups[group_index];
			debug_point;

			tag_group_interfaces.push_back(new c_gen3_tag_group_interface(*this, group_index));
		}

		cache_file_tag_instances = reinterpret_cast<s_cache_file_tag_instance*>(tags_buffer + convert_virtual_address(haloreach_cache_file_tags_header->tag_instances.address));
		for (uint32_t tag_instance = 0; tag_instance < haloreach_cache_file_tags_header->tag_instances.count; tag_instance++)
		{
			s_cache_file_tag_instance& cache_file_tag_instance = cache_file_tag_instances[tag_instance];
			debug_point;

			const char* name = string_ids_buffer + string_id_indices[0];

			tag_interfaces.push_back(new c_gen3_tag_interface(*this, tag_instance));
		}
	}

	on_init();


}

c_haloreach_cache_file::~c_haloreach_cache_file()
{
	while (is_loading()) {};
	if (string_id_guesstimator != nullptr)
	{
		delete string_id_guesstimator;
	}
}

e_resource_type c_haloreach_cache_file::get_resource_type_by_index(uint32_t index) const
{
	using namespace blofeld::haloreach;

	c_tag_group_interface* cache_file_resource_gestalt_group = get_tag_group_interface_by_group_id(blofeld::CACHE_FILE_RESOURCE_GESTALT_TAG);
	ASSERT(cache_file_resource_gestalt_group != nullptr);
	ASSERT(cache_file_resource_gestalt_group->get_tag_interfaces_count() > 0);
	c_tag_interface* cache_file_resource_gestalt = cache_file_resource_gestalt_group->get_tag_interfaces()[0];

	auto haloreach_cache_file_resource_gestalt = cache_file_resource_gestalt->get_virtual_tag_interface<s_cache_file_resource_gestalt_block_struct>();
	ASSERT(haloreach_cache_file_resource_gestalt != nullptr);

	auto& resource_type_identifier = haloreach_cache_file_resource_gestalt->resource_type_identifiers_block[index];
	GUID& guid = *reinterpret_cast<GUID*>(&resource_type_identifier.identifier_part_0);

	static GUID bitmap_texture_interop_resource_guid			= UuidFromString2("A9542662-42AB-C80B-049A-C0899CFF3BF3");
	static GUID render_geometry_api_resource_definition_guid	= UuidFromString2("8AEB8021-4164-F60A-7091-0C9745553623");
	static GUID constant_buffer_resource_definition_guid		= UuidFromString2("0A547ABF-4CC0-0279-0E11-B8A3EA347A53");
	static GUID sound_resource_definition_guid					= UuidFromString2("C0BA15AA-4B7B-B9CB-A769-989DBBC835D3");
	static GUID model_animation_tag_resource_guid				= UuidFromString2("09439BE6-48B1-3BDA-AD2E-4799110628A1");
	static GUID structure_bsp_tag_resources_guid				= UuidFromString2("72D3359D-4E28-5BCF-04A5-69A20CE623D9");
	static GUID structure_bsp_cache_file_tag_resources_guid		= UuidFromString2("F94BEACC-423F-EDAB-5E23-6782ADA114FA");

	e_resource_type resource_type = k_num_resource_types;

	if (IsEqualGUID(guid,	bitmap_texture_interop_resource_guid						)) resource_type = _resource_type_bitmap_texture_interop_resource;
	else if (IsEqualGUID(guid,	render_geometry_api_resource_definition_guid			)) resource_type = _resource_type_render_geometry_api_resource_definition;
	else if (IsEqualGUID(guid,	constant_buffer_resource_definition_guid				)) resource_type = _resource_type_constant_buffer_resource_definition;
	else if (IsEqualGUID(guid,	sound_resource_definition_guid							)) resource_type = _resource_type_sound_resource_definition;
	else if (IsEqualGUID(guid,	model_animation_tag_resource_guid						)) resource_type = _resource_type_model_animation_tag_resource;
	else if (IsEqualGUID(guid,	structure_bsp_tag_resources_guid						)) resource_type = _resource_type_structure_bsp_tag_resources;
	else if (IsEqualGUID(guid,	structure_bsp_cache_file_tag_resources_guid				)) resource_type = _resource_type_structure_bsp_cache_file_tag_resources;

	ASSERT(resource_type != k_num_resource_types);

	return resource_type;
}

e_interop_type c_haloreach_cache_file::get_interop_type_by_index(uint32_t index) const
{
	using namespace blofeld::haloreach;

	c_tag_group_interface* cache_file_resource_gestalt_group = get_tag_group_interface_by_group_id(blofeld::CACHE_FILE_RESOURCE_GESTALT_TAG);
	ASSERT(cache_file_resource_gestalt_group != nullptr);
	ASSERT(cache_file_resource_gestalt_group->get_tag_interfaces_count() > 0);
	c_tag_interface* cache_file_resource_gestalt = cache_file_resource_gestalt_group->get_tag_interfaces()[0];

	auto haloreach_cache_file_resource_gestalt = cache_file_resource_gestalt->get_virtual_tag_interface<s_cache_file_resource_gestalt_block_struct>();
	ASSERT(haloreach_cache_file_resource_gestalt != nullptr);

	auto& interop_type_identifier = haloreach_cache_file_resource_gestalt->interop_type_identifiers_block[index];
	GUID& guid = *reinterpret_cast<GUID*>(&interop_type_identifier.identifier_part_0);


	static GUID tag_d3d_vertex_buffer_guid				= UuidFromString2("12721193-4648-798F-4D25-8EB0DF0759FB");
	static GUID tag_d3d_index_buffer_guid				= UuidFromString2("08380D7D-4112-F14D-7134-CE8270A7431E");
	static GUID tag_d3d_texture_guid					= UuidFromString2("64017671-46F0-437A-22C4-339AE3967051");
	static GUID tag_d3d_texture_interleaved_guid		= UuidFromString2("90486D0A-4941-944A-F09A-E79F11E6E239");
	static GUID tag_d3d_vertex_shader_guid				= UuidFromString2("A6D79D0E-4E35-B84B-B21E-079259B0B16F");
	static GUID tag_d3d_pixel_shader_guid				= UuidFromString2("1578CC0C-43B3-CE00-1999-9C9705BE3CD4");
	static GUID constant_buffer_guid					= UuidFromString2("F2C8DD55-46A0-C9D0-46A7-8D9B17698FBC");
	static GUID structured_buffer_guid					= UuidFromString2("2A2E1537-4C31-EFBF-7D95-3799477DA90D");

	e_interop_type interop_type = k_num_interop_types;

	if (IsEqualGUID(guid, tag_d3d_vertex_buffer_guid))					interop_type = _interop_type_tag_d3d_vertex_buffer;
	if (IsEqualGUID(guid, tag_d3d_index_buffer_guid))					interop_type = _interop_type_tag_d3d_index_buffer;
	if (IsEqualGUID(guid, tag_d3d_texture_guid))						interop_type = _interop_type_tag_d3d_texture;
	if (IsEqualGUID(guid, tag_d3d_texture_interleaved_guid))			interop_type = _interop_type_tag_d3d_texture_interleaved;
	if (IsEqualGUID(guid, tag_d3d_vertex_shader_guid))					interop_type = _interop_type_tag_d3d_vertex_shader;
	if (IsEqualGUID(guid, tag_d3d_pixel_shader_guid))					interop_type = _interop_type_tag_d3d_pixel_shader;
	if (IsEqualGUID(guid, constant_buffer_guid))						interop_type = _interop_type_constant_buffer;
	if (IsEqualGUID(guid, structured_buffer_guid))						interop_type = _interop_type_structured_buffer;

	ASSERT(interop_type != k_num_interop_types);

	return interop_type;
}

bool c_haloreach_cache_file::save_map()
{
	// #TODO: Replace with filesystem API

	FILE* file = _wfopen(get_filepath(), L"wb");
	if (file == nullptr)
	{
		MessageBoxA(NULL, "Failed to save map", "File error failed to open for write", 0);
		return false;
	}

	size_t map_size = virtual_memory_container.GetSize();
	char* map_data = virtual_memory_container.get_data();

	fwrite(map_data, 1, map_size, file);
	fflush(file);
	fclose(file);
	return true;
}

uint64_t c_haloreach_cache_file::get_base_virtual_address() const
{
	return haloreach_cache_file_header.virtual_base_address;
}

uint64_t c_haloreach_cache_file::convert_page_offset(uint32_t page_offset) const
{
	if (haloreach_cache_file_header.unknown_bits & _cache_file_flag_use_absolute_addressing) // #TODO: Actually detect version
	{
		return (static_cast<uint64_t>(page_offset) * 4ull) - (get_base_virtual_address() - 0x10000000ull);
	}
	else
	{
		return (static_cast<uint64_t>(page_offset) * 4ull) - (get_base_virtual_address() - 0x50000000ull);
	}
}

void c_haloreach_cache_file::get_raw_tag_memory_region(uint32_t tag_index, size_t& out_size, char*& tag_data) const
{
	out_size = 0;
	tag_data = nullptr;

	c_tag_interface& tag_interface0 = *get_tag_interface(tag_index);

	uint32_t sorted_index = 0;
	for (; sorted_index < get_tag_count(); sorted_index++)
	{
		if (tag_interfaces_sorted_by_data_address[sorted_index] == &tag_interface0)
		{
			break;
		}
	}

	if (sorted_index < (haloreach_cache_file_tags_header->tag_instances.count - 1))
	{
		c_tag_interface& tag_interface1 = *tag_interfaces_sorted_by_data_address[sorted_index + 1];
		if (!tag_interface0.is_null() && !tag_interface1.is_null())
		{
			char* start = tag_interface0.get_data();
			char* end = tag_interface1.get_data();

			out_size = end - start;
			tag_data = start;
		}
	}

	debug_point;
}
