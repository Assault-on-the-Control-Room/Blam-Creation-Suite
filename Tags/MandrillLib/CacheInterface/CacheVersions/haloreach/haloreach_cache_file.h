#pragma once

class c_haloreach_cache_file :
	public c_gen3_cache_file
{
	friend c_cache_file;
protected:
	c_haloreach_cache_file(const std::wstring& map_filepath);
	virtual ~c_haloreach_cache_file();

	virtual e_resource_type get_resource_type_by_index(uint32_t index) const final;
	virtual e_interop_type get_interop_type_by_index(uint32_t index) const final;
public:
	virtual bool save_map() final;
	virtual uint64_t get_base_virtual_address() const final;
	virtual uint64_t convert_page_offset(uint32_t page_offset) const final;
	virtual void get_raw_tag_memory_region(uint32_t tag_index, size_t& out_size, char*& tag_data) const final;

protected:
	haloreach::s_cache_file_header& haloreach_cache_file_header;
	haloreach::s_cache_file_tags_header* haloreach_cache_file_tags_header;
};



