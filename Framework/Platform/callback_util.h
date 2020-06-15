#pragma once


template<typename T>
struct c_callback;

template<typename t_return_type, typename ...t_args>
class c_callback<t_return_type(t_args...)>
{
public:
	using t_func = t_return_type(t_args...);
	using t_function = std::function<t_func>;
	using t_map = std::map<void*, t_function>;

	void register_callback(t_func* function)
	{
		callbacks[function] = function;
	}

	void register_callback(void* key, std::function<t_func> function)
	{
		callbacks[key] = function;
	}

	void unregister_callback(t_func* function)
	{
		callbacks.erase(function);
	}

	void unregister_callback(void* key, std::function<t_func> function)
	{
		callbacks.erase(key);
	}

	void operator()(t_args ...args)
	{
		call(args...);
	}

	void call(t_args ...args)
	{
		// #BUG Using t_map::iterator breaks MSVC here

		for (auto it = callbacks.begin(); it != callbacks.end(); it++)
		{
			std::function<t_func>& callback = it->second;

			if (callback)
			{
				callback(args...);
			}
		}
	}

	t_map callbacks;
};
