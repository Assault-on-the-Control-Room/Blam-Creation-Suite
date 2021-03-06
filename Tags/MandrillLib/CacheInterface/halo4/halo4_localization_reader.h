#pragma once

class c_halo4_cache_cluster;
class c_halo4_cache_file_reader;

class c_halo4_localization_reader : public c_localization_reader
{
public:
	c_halo4_localization_reader(c_halo4_cache_cluster& cache_cluster, c_halo4_cache_file_reader& cache_reader);
	~c_halo4_localization_reader();

private:
	c_halo4_cache_cluster& cache_cluster;
	c_halo4_cache_file_reader& cache_reader;
};
