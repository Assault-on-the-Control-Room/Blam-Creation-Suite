#pragma once

class c_halo3_cache_file :
	public c_gen3_cache_file
{
	friend c_cache_file;
protected:
	c_halo3_cache_file(const std::wstring& map_filepath);
	virtual ~c_halo3_cache_file();

	virtual e_resource_type get_resource_type_by_index(uint32_t index) const final;
	virtual e_interop_type get_interop_type_by_index(uint32_t index) const final;
public:
	virtual bool save_map() final;
	virtual uint64_t get_base_virtual_address() const final;
	virtual uint64_t convert_page_offset(uint32_t page_offset) const final;

protected:
	halo3::s_cache_file_header& halo3_cache_file_header;
	halo3::s_cache_file_tags_header* halo3_cache_file_tags_header;
};
