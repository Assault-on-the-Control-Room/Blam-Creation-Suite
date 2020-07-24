#pragma once

class c_gen3_cache_file;
class c_gen3_resource;
class c_gen3_file_page_manager;

namespace tbb
{
	class task_group;
}

class c_gen3_resource_manager
{
public:
	non_copyconstructable(c_gen3_resource_manager);
	friend c_gen3_cache_file;
	c_gen3_resource_manager(c_gen3_cache_file& cache_file);
	~c_gen3_resource_manager();

protected:
	void init_resources();
	void deinit_resources();

	std::vector<c_gen3_file_page_manager*> file_page_managers;
	std::vector<c_gen3_cache_file*> resource_files;
	std::vector<c_gen3_resource*> resources;
	c_gen3_cache_file& cache_file;
};

class c_gen3_file_page_manager
{
public:
	non_copyconstructable(c_gen3_file_page_manager);
	friend c_gen3_resource_manager;
	c_gen3_file_page_manager(
		c_gen3_resource_manager& resource_manager, 
		char* raw_resource_data, 
		uint32_t compressed_size, 
		uint32_t uncompressed_size, 
		int32_t codec, 
		tbb::task_group* g = nullptr);
	~c_gen3_file_page_manager();

	void read_file_page();

private:
	c_gen3_resource_manager& resource_manager;
	char* raw_resource_data;
	uint32_t compressed_size;
	uint32_t uncompressed_size;
	int32_t codec;
	char* resource_data;
};

class c_gen3_resource
{
public:
	non_copyconstructable(c_gen3_resource);
	friend c_gen3_resource_manager;
	c_gen3_resource(c_gen3_resource_manager& resource_manager);

protected:
	c_gen3_resource_manager& resource_manager;
};

