#pragma once

class c_halo1_tag_interface;

class c_halo1_cache_file : 
	public c_cache_file
{
	friend c_halo1_tag_interface;
	friend c_cache_file;
protected:
	c_halo1_cache_file(const std::wstring& map_filepath);
	virtual ~c_halo1_cache_file();

public:
	void read_cache_file();
	void load_map();
	virtual bool save_map() final;
	virtual bool is_loading() const final;
	virtual uint64_t get_base_virtual_address() const final;
	virtual uint64_t convert_page_offset(uint32_t page_offset) const final;
	virtual uint32_t get_tag_count() const final;
	virtual uint32_t get_tag_group_count() const final;
	virtual uint32_t get_string_id_count() const final;
	virtual char* get_tag_data(s_tag_data& tag_data) const final;
	virtual char* get_tag_block_data(const s_tag_block& tag_block) const final;
	virtual const char* get_string_id_by_index(uint32_t index) const final;
	virtual const char* get_string_id(string_id const id, const char* const error_value = nullptr) const final;
	virtual const char* get_tag_path(uint32_t tag_index) const final;
	virtual unsigned long get_group_tag_by_tag_index(uint32_t tag_index) const final;
	virtual void get_raw_tag_memory_region(uint32_t tag_index, size_t& out_size, char*& tag_data) const final;

protected:
	virtual void* get_internal_tag_instance_impl(uint32_t tag_index) const final;
	virtual void* get_internal_tag_group_impl(uint32_t group_index) const final;

protected:
	halo1::s_cache_file_header* cache_file_header;
	halo1::s_cache_file_tags_header* cache_file_tags_header;
	halo1::s_cache_file_tag_instance* cache_file_tag_instances;
};

