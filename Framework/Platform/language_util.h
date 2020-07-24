#pragma once

#define movable_only(movable_only) \
movable_only() = default; \
movable_only(movable_only const&) = delete; /* redundant */ \
movable_only(movable_only&&) { /*...*/ }; \
movable_only& operator=(movable_only const&) = delete; /* redundant */ \
movable_only& operator=(movable_only&&) { /*...*/ return *this; }

#define copyable_only(copyable_only) \
copyable_only() = default; \
copyable_only(copyable_only const&) { /*...*/ }; \
copyable_only(copyable_only&&) = delete; /* discouraged */ \
copyable_only& operator=(copyable_only const&) { /*...*/ return *this; } \
copyable_only& operator=(copyable_only&&) = delete; /* discouraged */

#define non_copyable(non_copyable) \
non_copyable() = default; \
non_copyable(non_copyable const&) = delete; \
non_copyable(non_copyable&&) = delete; /* redundant */ \
non_copyable& operator=(non_copyable const&) = delete; \
non_copyable& operator=(non_copyable&&) = delete; /* redundant */

#define non_copyconstructable(non_copyconstructable) \
non_copyconstructable() = delete; \
non_copyconstructable(non_copyconstructable const&) = delete; \
non_copyconstructable(non_copyconstructable&&) = delete; /* redundant */ \
non_copyconstructable& operator=(non_copyconstructable const&) = delete; \
non_copyconstructable& operator=(non_copyconstructable&&) = delete; /* redundant */

template<typename T>
class c_explicit_storage
{
public:
	c_explicit_storage() :
		is_initialized(false)
	{

	}
	~c_explicit_storage()
	{
		if (is_initialized)
		{
			delete reinterpret_cast<T*>(storage_data);
		}
	}

	template <class... Args>
	T& operator()(Args&&... args)
	{
		return *new(storage_data) T(args...);
	}

	bool is_initialized;
	char storage_data[sizeof(T)];
};

template<typename t_value, bool reverse = false>
class c_reference_iterator
{
public:
	c_reference_iterator(t_value start_position, t_value end_position) :
		current_position(reverse ? end_position : start_position)
	{
		if constexpr (reverse)
		{
			current_position--;
		}
	}

	t_value current_position;

	decltype(**current_position)& operator*()
	{
		auto& reference = **current_position;
		REFERENCE_ASSERT(reference);
		return reference;
	}

	void operator++()
	{
		if constexpr (reverse)
		{
			current_position--;
		}
		else
		{
			current_position++;
		}
	}

	bool operator !=(c_reference_iterator& it)
	{
		return current_position != it.current_position;
	}
};

template<typename t_value, typename t_iterator, bool start_and_end_iterator_ctor = false>
class c_loop_helper
{
public:
	t_value begin_pointer;
	t_value end_pointer;

	t_iterator begin()
	{
		if constexpr (start_and_end_iterator_ctor)
		{
			return { begin_pointer, end_pointer };
		}
		else
		{
			return begin_pointer;
		}
	}

	t_iterator end()
	{
		if constexpr (start_and_end_iterator_ctor)
		{
			return { end_pointer, begin_pointer };
		}
		else
		{
			return end_pointer;
		}
	}

	c_loop_helper(t_value begin, t_value end) :
		begin_pointer(begin),
		end_pointer(end)
	{

	}

	c_loop_helper(t_value begin, size_t count) :
		c_loop_helper(begin, begin + count)
	{

	}

	c_loop_helper(t_value begin) :
		begin_pointer(begin)
	{
		end_pointer = begin;
		while (*end_pointer)
		{
			end_pointer++;
		}
	}
};

template<typename t_value>
class c_reference_loop : public c_loop_helper<t_value, c_reference_iterator<t_value>, true>
{
public:
	c_reference_loop(t_value begin, t_value end) : c_loop_helper<t_value, c_reference_iterator<t_value>, true>(begin, end) {}
	c_reference_loop(t_value begin, size_t count) : c_loop_helper<t_value, c_reference_iterator<t_value>, true>(begin, count) {}
	c_reference_loop(t_value begin) : c_loop_helper<t_value, c_reference_iterator<t_value>, true>(begin) {}
};

template<typename t_value>
class c_reverse_reference_loop : public c_loop_helper<t_value, c_reference_iterator<t_value, true>, true>
{
public:
	c_reverse_reference_loop(t_value begin, t_value end) : c_loop_helper<t_value, c_reference_iterator<t_value, true>, true>(begin, end) {}
	c_reverse_reference_loop(t_value begin, size_t count) : c_loop_helper<t_value, c_reference_iterator<t_value, true>, true>(begin, count) {}
	c_reverse_reference_loop(t_value begin) : c_loop_helper<t_value, c_reference_iterator<t_value, true>, true>(begin) {}
};

template<typename t_value>
class c_range_loop : public c_loop_helper<t_value, t_value>
{
public:
	c_range_loop(t_value begin, t_value end) : c_loop_helper<t_value, t_value>(begin, end) {}
	c_range_loop(t_value begin, size_t count) : c_loop_helper<t_value, t_value>(begin, count) {}
	c_range_loop(t_value begin) : c_loop_helper<t_value, t_value>(begin) {}
};

inline GUID UuidFromString2(const char* guid_str)
{
	c_fixed_wide_string_64 buffer;
	buffer.format(L"{%S}", guid_str);
	GUID guid;
	HRESULT clsid_from_string_result = IIDFromString(buffer.c_str(), &guid);
	ASSERT(clsid_from_string_result == S_OK);
	return guid;
}
