#pragma once

class c_tag_group_interface;
class c_haloreach_tag_group_interface;
class c_halo1_tag_group_interface;
class c_virtual_tag_interface;

class c_tag_interface
{
	friend c_tag_group_interface;
	friend c_haloreach_tag_group_interface;
	friend c_halo1_tag_group_interface;
	friend c_virtual_tag_interface;
protected:
	non_copyable(c_tag_interface);

	BCSAPI c_tag_interface(c_cache_file& cache_file, uint32_t tag_index);
	BCSAPI virtual ~c_tag_interface();

	BCSAPI void associate_virtual_tag_interface(c_virtual_tag_interface& virtual_tag_interface);
	BCSAPI void register_with_tag_group();
public:
	BCSAPI virtual unsigned long get_group_tag() const;
	BCSAPI virtual c_tag_group_interface* get_tag_group_interface() const;

	virtual const char* get_filepath() const = 0; // eg. globals/globals
	virtual const char* get_path_with_group_id_cstr() const = 0; // eg. globals/globals.matg
	virtual const char* get_path_with_group_name_cstr() const = 0; // eg. globals/globals.globals
	virtual const char* get_name_cstr() const = 0; // eg. globals
	virtual const char* get_name_with_group_id_cstr() const = 0; // eg. globals.matg
	virtual const char* get_name_with_group_name_cstr() const = 0; // eg. globals.globals

	BCSAPI c_virtual_tag_interface* get_virtual_tag_interface();

	template<typename T>
	inline v_tag<T>* get_virtual_tag_interface()
	{
		v_tag<T>* virtual_tag_interface = dynamic_cast<decltype(virtual_tag_interface)>(get_virtual_tag_interface());
		return virtual_tag_interface;
	}

	BCSAPI const blofeld::s_tag_group* get_blofeld_reflection_data();

	BCSAPI virtual char* get_data() = 0;
	inline char* get_data(size_t relative_offset) { return get_data() + relative_offset; }

	template<typename T>  // #TODO: check if this type is alright using group ID's
	inline T* get_data(size_t relative_offset = 0) { return reinterpret_cast<T*>(get_data() + relative_offset); }

	inline uint32_t get_index() { return tag_index; };


	// #TODO: SORT FUNCTIONS BELOW

	inline bool is_null() const { return is_tag_null; } // #TODO: programmatic check using group and address
	inline c_cache_file& get_cache_file() const { return cache_file; };

	//inline c_tag_group_interface* get_tag_group_interface() const { return group_interface; }; // #TODO: Use this version and guarantee valid value for cache_file_legacy_tag_group_interface

private:
	void init_blofeld_reflection_type();
	void init_virtual_tag_interface();

protected:

	bool is_tag_null;
	uint32_t tag_index;
	c_cache_file& cache_file;
	const blofeld::s_tag_group* blofeld_reflection_type;
	c_virtual_tag_interface* virtual_tag_interface;
public:
	void* virtual_resource_user_data;
};

