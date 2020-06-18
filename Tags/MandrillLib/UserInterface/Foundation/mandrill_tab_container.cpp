#include "mandrilllib-private-pch.h"

c_mandrill_tab_container::c_mandrill_tab_container(c_mandrill_tab* parent) :
	parent(parent),
	on_closed(),
	children()
{

}

c_mandrill_tab_container::~c_mandrill_tab_container()
{

}

void c_mandrill_tab_container::add_tab(c_mandrill_tab& tab)
{
	static std::mutex mutex;
	std::lock_guard lock(mutex);

	REFERENCE_ASSERT(tab);
	if (std::find(children.begin(), children.end(), &tab) == children.end())
	{
		children.push_back(&tab);

		tab.on_closed.register_callback(this, std::bind(&c_mandrill_tab_container::tab_closed_callback, this, std::placeholders::_1));
	}
}

void c_mandrill_tab_container::remove_tab(c_mandrill_tab& tab)
{
	vector_erase_by_value_helper(children, &tab);
}

void c_mandrill_tab_container::tab_closed_callback(c_mandrill_tab& tab)
{
	this->remove_tab(tab);
}
