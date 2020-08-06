#pragma once

class c_presense_api
{
public:
	static void update();
	static void set_state(s_presense_info* presense_info);
	static void set_default_state();

protected:
	virtual void update_impl() = 0;
	virtual void set_state_impl(s_presense_info* presense_info) = 0;
	static std::vector<c_presense_api*> s_apis;

};
