#include "mandrilllib-private-pch.h"

c_halo3odst_cache_file::c_halo3odst_cache_file(const std::wstring& map_filepath) :
	c_cache_file(map_filepath, _engine_type_halo3odst, _platform_type_pc)
{

}

c_halo3odst_cache_file::~c_halo3odst_cache_file()
{

}

bool c_halo3odst_cache_file::save_map()
{
	return false;
}

bool c_halo3odst_cache_file::is_loading() const
{
	return false;
}

uint64_t c_halo3odst_cache_file::get_base_virtual_address() const
{
	return 0;
}

uint64_t c_halo3odst_cache_file::convert_page_offset(uint32_t page_offset) const
{
	return 0;
}

uint32_t c_halo3odst_cache_file::get_tag_count() const
{
	return 0;
}

uint32_t c_halo3odst_cache_file::get_tag_group_count() const
{
	return 0;
}

uint32_t c_halo3odst_cache_file::get_string_id_count() const
{
	return 0;
}

char* c_halo3odst_cache_file::get_tag_data(s_tag_data& tag_data) const
{
	return nullptr;
}

char* c_halo3odst_cache_file::get_tag_block_data(const s_tag_block& tag_block) const
{
	return nullptr;
}

const char* c_halo3odst_cache_file::get_string_id_by_index(uint32_t index) const
{
	return nullptr;
}

const char* c_halo3odst_cache_file::get_string_id(string_id const id, const char* const error_value /*= nullptr*/) const
{
	return nullptr;
}

const char* c_halo3odst_cache_file::get_tag_path(uint32_t tag_index) const
{
	return nullptr;
}

unsigned long c_halo3odst_cache_file::get_group_tag_by_tag_index(uint32_t tag_index) const
{
	return blofeld::INVALID_TAG;
}

void c_halo3odst_cache_file::get_raw_tag_memory_region(uint32_t tag_index, size_t& out_size, char*& tag_data) const
{

}

const s_section_cache* c_halo3odst_cache_file::get_section(uint32_t section_index) const
{
	return nullptr;
}

void* c_halo3odst_cache_file::get_internal_tag_instance_impl(uint32_t tag_index) const
{
	return nullptr;
}

void* c_halo3odst_cache_file::get_internal_tag_group_impl(uint32_t group_index) const
{
	return nullptr;
}
