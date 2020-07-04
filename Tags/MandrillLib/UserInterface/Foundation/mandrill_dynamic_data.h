#pragma once

class s_mandrill_dynamic_data
{
public:
	non_copyable(s_mandrill_dynamic_data);

	// #WARN This structure should be kept as small as possible
	// to avoid excessive cache misses. Maybe it is worth looking
	// into a way to allocate these in multiples of smaller 
	// allocations?
	// #NOTE Make the assumption that cache lines are 64bytes
	// (512 bits) wide. 64, 128, 192, 256, 320 etc.

	using c_imgui_dynamic_data = std::pair<void*, char[256 - sizeof(intptr_t)]>;
	static_assert(sizeof(c_imgui_dynamic_data) == 256);

	// #TODO Replace this with a virtual memory container
	// that allocates in 4KB pages. Most of the allocations
	// made to this vector are in their own 4KB pages, meaning
	// that a 256KB structure has only 6.25% efficiency
	std::vector<c_imgui_dynamic_data*> imgui_dynamic_data;

	inline c_imgui_dynamic_data& get_dynamic_data(void* data, bool& was_allocated);

	template<typename T>
	inline T& get_dynamic_data(void* data)
	{
		bool was_allocated = false;
		c_imgui_dynamic_data& dynamic_data = get_dynamic_data(data, was_allocated);
		static_assert(sizeof(T) <= sizeof(dynamic_data.second), "Dynamic data exceeds allocated space");
		if (was_allocated)
		{
			new(dynamic_data.second) T(); // initialize value
		}
		T& dynamic_tag_block_data = *reinterpret_cast<T*>(dynamic_data.second);
		return dynamic_tag_block_data;
	}
	template<typename T, typename ...Tconstructor>
	inline T& get_dynamic_data(void* data, Tconstructor ...args)
	{
		bool was_allocated = false;
		c_imgui_dynamic_data& dynamic_data = get_dynamic_data(data, was_allocated);
		static_assert(sizeof(T) <= sizeof(dynamic_data.second), "Dynamic data exceeds allocated space");
		if (was_allocated)
		{
			new(dynamic_data.second) T(args...); // initialize value
		}
		T& dynamic_tag_block_data = *reinterpret_cast<T*>(dynamic_data.second);
		return dynamic_tag_block_data;
	}
};

inline s_mandrill_dynamic_data::c_imgui_dynamic_data& s_mandrill_dynamic_data::get_dynamic_data(void* data, bool& was_allocated)
{
	for (c_imgui_dynamic_data* pDynamicData : imgui_dynamic_data)
	{
		if (pDynamicData->first == data)
		{
			was_allocated = false;
			return *pDynamicData;
		}
	}

	was_allocated = true;
	c_imgui_dynamic_data& dynamic_tag_block_data = *imgui_dynamic_data.emplace_back(new c_imgui_dynamic_data{});
	dynamic_tag_block_data.first = data;
	return dynamic_tag_block_data;
}
