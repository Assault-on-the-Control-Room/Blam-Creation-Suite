#include "gameframework-private-pch.h"

std::vector<c_presense_api*> c_presense_api::s_apis;

void c_presense_api::update()
{
	for (c_presense_api* api : s_apis)
	{
		api->update_impl();
	}
}

void c_presense_api::set_state(s_presense_info* presense_info)
{
	for (c_presense_api* api : s_apis)
	{
		api->set_state_impl(presense_info);
	}
}

void c_presense_api::set_default_state()
{
	s_presense_info presense_info = {};
	presense_info.engine_type = _engine_type_not_set;
	presense_info.map_name = "Main Menu";
	presense_info.is_joinable = false;
	presense_info.party_max = 1;
	presense_info.party_size = 1;
	presense_info.start_timestamp = 0;
	presense_info.end_timestamp = 0;

	c_presense_api::set_state(&presense_info);
}
