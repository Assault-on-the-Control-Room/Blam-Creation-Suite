#pragma once
class c_halo4_cache_file :
	public c_gen3_cache_file
{
	friend c_cache_file;
protected:
	c_halo4_cache_file(const std::wstring& map_filepath);
	virtual ~c_halo4_cache_file();

public:
	virtual bool save_map() final;
	virtual uint64_t get_base_virtual_address() const final;
	virtual uint64_t convert_page_offset(uint32_t page_offset) const final;
	virtual void get_raw_tag_memory_region(uint32_t tag_index, size_t& out_size, char*& tag_data) const final;
	virtual uint32_t get_string_id_count() const final;

protected:
	gen3::e_cache_file_flags get_cache_file_flags() const;
	void init(halo4::s_cache_file_header& cache_file_header);
	halo4::s_cache_file_header* halo4_cache_file_header;
	halo4::s_cache_file_tags_header* halo4_cache_file_tags_header;
};

