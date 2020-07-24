#pragma once

struct s_section_cache
{
	long mask;
	long offset;
	long size;
	char* masked_data;
	char* data;
};

class c_gen3_cache_file_validator;
class c_cache_file_string_id_guesstimator;

enum e_resource_type
{
	_resource_type_stitchable_bitmap_texture_interop_resource,
	_resource_type_bitmap_texture_interop_resource,
	_resource_type_render_geometry_api_resource_definition,
	_resource_type_render_collision_model_resource,
	_resource_type_constant_buffer_resource_definition,
	_resource_type_sound_resource_definition,
	_resource_type_model_animation_tag_resource,
	_resource_type_bitmap_texture_interleaved_interop_resource,
	_resource_type_structure_bsp_tag_resources,
	_resource_type_structure_bsp_cache_file_tag_resources,
	_resource_type_facial_animation_resource_definition,
	k_num_resource_types
};

enum e_interop_type
{
	_interop_type_tag_d3d_vertex_buffer,
	_interop_type_tag_d3d_index_buffer,
	_interop_type_tag_d3d_texture,
	_interop_type_tag_d3d_texture_interleaved,
	_interop_type_tag_d3d_vertex_shader,
	_interop_type_tag_d3d_pixel_shader,
	_interop_type_constant_buffer,
	_interop_type_structured_buffer,
	_interop_type_polyartvertexbuffer0,
	_interop_type_polyartvertexbuffer1,
	_interop_type_polyartindexbuffer,
	k_num_interop_types
};

class c_gen3_cache_file :
	public c_cache_file
{
	friend c_cache_file;
protected:
	gen3::s_cache_file_header* read_cache_file();
	void init_gen3_cache_file();
	c_gen3_cache_file(const std::wstring& map_filepath, e_engine_type engine_type, e_platform_type platform_type);
	virtual ~c_gen3_cache_file();

public:
	virtual e_resource_type get_resource_type_by_index(uint32_t index) const = 0;
	virtual e_interop_type get_interop_type_by_index(uint32_t index) const = 0;
	virtual bool is_loading() const final;
	virtual uint32_t get_tag_count() const final;
	virtual uint32_t get_tag_group_count() const final;
	virtual uint32_t get_string_id_count() const final;
	char* get_data_with_page_offset(uint32_t page_offset) const;
	bool is_valid_data_address(char* data) const;
	virtual char* get_tag_data(s_tag_data& tag_data) const final;
	virtual char* get_tag_block_data(const s_tag_block& tag_block) const final;
	virtual char* get_tag_interop_data(const s_tag_interop& tag_interop) const final;
	virtual const char* get_string_id_by_index(uint32_t index) const final;
	virtual const char* get_string_id(string_id const id, const char* const error_value = nullptr) const final;
	virtual const char* get_tag_path(uint32_t tag_index) const final;
	virtual unsigned long get_group_tag_by_tag_index(uint32_t tag_index) const final;
	virtual void get_raw_tag_memory_region(uint32_t tag_index, size_t& out_size, char*& tag_data) const;

	virtual const s_section_cache& get_section(uint32_t section_index) const final;
	inline const s_section_cache& get_debug_section() const { return get_section(gen3::_cache_file_section_index_debug); };
	inline const s_section_cache& get_tags_section() const { return get_section(gen3::_cache_file_section_index_tags); };
	inline const s_section_cache& get_resources_section() const { return get_section(gen3::_cache_file_section_index_resource); };
	inline const s_section_cache& get_localization_section() const { return get_section(gen3::_cache_file_section_index_localization); };
	inline c_gen3_resource_manager& get_resource_manager() { return resource_manager; };
	inline const c_gen3_resource_manager& get_resource_manager() const { return resource_manager; };
	inline char* get_tags_buffer() const { return tags_buffer; }
	inline c_gen3_cache_file_validator& get_cache_file_validator() const { return *validator; }

	inline gen3::s_cache_file_tag_instance& get_internal_tag_instance(uint32_t tag_index) const 
	{ 
		gen3::s_cache_file_tag_instance* tag_instance = reinterpret_cast<gen3::s_cache_file_tag_instance*>(get_internal_tag_instance_impl(tag_index));
		DEBUG_ASSERT(tag_instance != nullptr);
		return *tag_instance;
	};
	inline gen3::s_cache_file_tag_group* get_internal_tag_group(uint32_t group_index) const
	{
		gen3::s_cache_file_tag_group* tag_group = reinterpret_cast<gen3::s_cache_file_tag_group*>(get_internal_tag_group_impl(group_index));
		return tag_group;
	};

protected:
	void post_init();
	virtual void* get_internal_tag_instance_impl(uint32_t tag_index) const final;
	virtual void* get_internal_tag_group_impl(uint32_t group_index) const final;

	c_gen3_resource_manager resource_manager;
	gen3::s_cache_file_header& cache_file_header;
	gen3::s_cache_file_tag_group* cache_file_tag_groups;
	gen3::s_cache_file_tag_instance* cache_file_tag_instances;
	char* string_ids_buffer;
	long* string_id_indices;
	char* filenames_buffer;
	long* filename_indices;
	char* tags_buffer;
	s_section_cache section_cache[underlying_cast(gen3::k_number_of_cache_file_sections)];
	c_cache_file_string_id_guesstimator* string_id_guesstimator;
	c_gen3_cache_file_validator* validator;
};

