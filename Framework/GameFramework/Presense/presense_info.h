#pragma once

struct s_presense_info
{
	e_engine_type engine_type;
	c_fixed_string_128 gametype_name;
	c_fixed_string_128 map_name;
	int64_t start_timestamp;
	int64_t end_timestamp;
	int party_size;
	int party_max;
	bool is_joinable;
};
