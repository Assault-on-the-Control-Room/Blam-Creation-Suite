#pragma once

class c_mandrill_tab;

class c_mandrill_tab_container
{
public:
	non_copyconstructable(c_mandrill_tab_container);

	c_mandrill_tab_container(c_mandrill_tab* parent);
	virtual ~c_mandrill_tab_container();

	virtual void add_tab(c_mandrill_tab& tab);
	virtual void remove_tab(c_mandrill_tab& tab);
	c_callback<void(c_mandrill_tab&)> on_closed;

	inline c_mandrill_tab* get_parent() const { return parent; }

protected:
	c_mandrill_tab* parent;
	std::vector<c_mandrill_tab*> children;
};
