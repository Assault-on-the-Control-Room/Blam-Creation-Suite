#pragma once

class c_virtual_memory_container;

class c_cache_file
{
public:
	friend class c_tag_interface;
	friend class c_tag_group_interface;

	static e_engine_type get_cache_file_engine_type(const wchar_t* filepath);
	static c_cache_file* create_cache_file(const std::wstring& map_filepath);

protected:
	BCSAPI c_cache_file(const std::wstring& map_filepath, e_engine_type engine_type, e_platform_type platform_type);
public:
	BCSAPI virtual ~c_cache_file();

	virtual bool save_map() = 0;
	virtual bool is_loading() const = 0;
	virtual uint64_t get_base_virtual_address() const = 0;
	virtual uint64_t convert_page_offset(uint32_t page_offset) const = 0;
	BCSAPI uint64_t convert_virtual_address(uint64_t virtual_address) const;
	virtual uint32_t get_tag_count() const = 0;
	virtual uint32_t get_tag_group_count() const = 0;
	virtual uint32_t get_string_id_count() const = 0;
	BCSAPI c_tag_interface* get_tag_interface(uint32_t tag_index) const;
	BCSAPI c_tag_interface* const* get_tag_interfaces() const;
	BCSAPI c_tag_interface* const* get_tag_interfaces_sorted_by_name_with_group_id() const;
	BCSAPI c_tag_interface* const* get_tag_interfaces_sorted_by_path_with_group_id() const;
	BCSAPI c_tag_interface* const* get_tag_interfaces_sorted_by_data_address() const;
	BCSAPI c_tag_group_interface* get_tag_group_interface(uint16_t group_index) const;
	BCSAPI c_tag_group_interface* get_tag_group_interface_by_group_id(unsigned long tag_group) const;
	BCSAPI c_tag_group_interface* const* get_tag_group_interfaces() const;
	virtual char* get_tag_data(s_tag_data& tag_data) const = 0;
	virtual char* get_tag_block_data(const s_tag_block& tag_block) const = 0;
	virtual const char* get_string_id_by_index(uint32_t index) const = 0;
	virtual const char* get_string_id(string_id const id, const char* const error_value = nullptr) const = 0;
	virtual void* get_internal_tag_instance_impl(uint32_t tag_index) const = 0;
	virtual void* get_internal_tag_group_impl(uint32_t group_index) const = 0;
	virtual unsigned long get_group_tag_by_tag_index(uint32_t tag_index) const = 0;
	virtual const char* get_tag_path(uint32_t tag_index) const = 0;

	virtual void get_raw_tag_memory_region(uint32_t tag_index, size_t& out_size, char*& tag_data) const = 0;

	template<typename T>
	inline T* get_tag_block_data(const c_typed_tag_block<T>& tag_block)
	{
		void* data = get_tag_block_data(*reinterpret_cast<const s_tag_block*>(&tag_block));
		T* typed_data = reinterpret_cast<T*>(data);
		return typed_data;
	}

	inline const wchar_t* get_map_filepath() const { return map_filepath.c_str(); }
	inline const char* get_map_filepath_utf8() const { return map_filepath_utf8.c_str(); }

	inline const wchar_t* get_map_path() const { return map_filename.c_str(); }
	inline const char* get_map_path_utf8() const { return map_filename_utf8.c_str(); }

	inline e_engine_type get_engine_type() const { return engine_type; }
	inline e_platform_type get_platform_type() const { return platform_type; }

protected:
	c_virtual_memory_container& virtual_memory_container;
	e_engine_type engine_type;
	e_platform_type platform_type;

	// interface types
	std::vector<c_tag_interface*> tag_interfaces;
	std::vector<c_tag_interface*> tag_interfaces_sorted_by_name_with_group_id;
	std::vector<c_tag_interface*> tag_interfaces_sorted_by_path_with_group_id;
	std::vector<c_tag_interface*> tag_interfaces_sorted_by_data_address;
	std::vector<c_tag_group_interface*> tag_group_interfaces;

protected:
	/* initialize each tag instance */
	BCSAPI void init_sorted_instance_lists();
	c_fixed_wide_path map_filepath;
	c_fixed_path map_filepath_utf8;
	c_fixed_wide_string_256 map_filename;
	c_fixed_string_256 map_filename_utf8;
};

