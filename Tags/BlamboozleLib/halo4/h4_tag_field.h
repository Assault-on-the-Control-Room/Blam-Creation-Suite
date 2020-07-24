#pragma once

class c_h4_tag_struct;

struct s_h4_tag_struct_definition
{
	bpointer32<const char*> display_name;
	bpointer32<const char*> name;
	bpointer32<const char*> filepath;
	buint32_t line_number;
	GUID _unknownguid;
	bpointer32<void*> fields_address;
	buint32_t size;
	bpointer32<const char*> size_string_address;
	buint32_t unknown;
	buint32_t unknown_tag0;
	buint32_t unknown_tag1;
	buint32_t unknown0;
	buint32_t unknown1;
	bpointer32<void*> unknown2;
	buint32_t unknown3;
	bpointer32<void*> unknown4;
	buint32_t unknown5;
	bpointer32<void*> tag_struct_vtable;
	uint64_t procedures_table_size;
	uint32_t _unknown[44];
};

struct s_h4_tag_field_definition
{
	bigendian_type<e_h4_field_type> field_type;
	bpointer32<const char*> name_address;
	bpointer32<void*> definition_address;
	buint32_t tool_tag;
};

struct s_h4_tag_block_definition
{
	bpointer32<const char*> display_name;
	bpointer32<const char*> name;
	buint32_t maximum_element_count;
	bpointer32<const char*> maximum_element_count_string;
	bpointer32<s_h4_tag_struct_definition*> struct_definition;
};


class c_h4_tag_field
{
public:
	c_h4_tag_field(const char* h4_data, const s_h4_tag_field_definition* field_definition) :
		field_type(field_definition->field_type),
		field_definition(field_definition),
		name(h4_va_to_pointer(h4_data, field_definition->name_address)),
		raw(field_definition->definition_address),
		tool_tag(field_definition->tool_tag)
	{

	}
	virtual ~c_h4_tag_field() {}

public:
	e_h4_field_type field_type;
	const char* name;
	const uint32_t raw;
	const uint32_t tool_tag;

protected:
	const s_h4_tag_field_definition* field_definition;
};

enum e_h4_tag_field_validation_check
{
	_h4_tag_field_validation_check_none,
	_h4_tag_field_validation_check_ensure_valid,
	_h4_tag_field_validation_check_ensure_invalid,
};

template<typename T>
class t_h4_tag_field :
	public c_h4_tag_field
{
public:

	t_h4_tag_field(const char* h4_data, const s_h4_tag_field_definition* field_definition, e_h4_tag_field_validation_check ensure_valid_definition = _h4_tag_field_validation_check_none) :
		c_h4_tag_field(h4_data, field_definition),
		definition(reinterpret_cast<const T*>(h4_va_to_pointer_safe(h4_data, field_definition->definition_address)))
	{
		if (ensure_valid_definition == _h4_tag_field_validation_check_ensure_valid)
		{
			ASSERT(definition != nullptr);
		}
		if (ensure_valid_definition == _h4_tag_field_validation_check_ensure_invalid)
		{
			ASSERT(definition == nullptr);
		}
	}

	const T* definition;
};

template<typename T>
struct t_h4_tag_numerical_definition
{
	T min;
	T max;
	T step;
};

using c_h4_tag_field_char_integer = t_h4_tag_field<t_h4_tag_numerical_definition<int8_t>>;
using c_h4_tag_field_short_integer = t_h4_tag_field<t_h4_tag_numerical_definition<int16_t>>;
using c_h4_tag_field_long_integer = t_h4_tag_field<t_h4_tag_numerical_definition<int32_t>>;
using c_h4_tag_field_int64_integer = t_h4_tag_field<t_h4_tag_numerical_definition<int64_t>>;
using c_h4_tag_field_byte_integer = t_h4_tag_field<t_h4_tag_numerical_definition<uint8_t>>;
using c_h4_tag_field_word_integer = t_h4_tag_field<t_h4_tag_numerical_definition<uint16_t>>;
using c_h4_tag_field_dword_integer = t_h4_tag_field<t_h4_tag_numerical_definition<uint32_t>>;
using c_h4_tag_field_qword_integer = t_h4_tag_field<t_h4_tag_numerical_definition<uint64_t>>;
using c_h4_tag_field_real = t_h4_tag_field<t_h4_tag_numerical_definition<float>>;
using c_h4_tag_field_explanation = t_h4_tag_field<const char>;

struct s_h4_tag_enum_definition
{
	bpointer32<const char*> name;
	buint32_t option_count;
	bpointer32<bpointer32<const char*>*> options;
	bpointer32<const char*> filepath;
	buint32_t line_number;
};

struct s_h4_tag_reference_definition
{
	buint32_t flags;
	buint32_t group_tag;
	bpointer32<buint32_t*> group_tags_address;
};

class c_h4_tag_field_tag_reference :
	public t_h4_tag_field<s_h4_tag_reference_definition>
{
public:
	c_h4_tag_reference* const reference;
	c_h4_tag_field_tag_reference(const char* h4_data, const s_h4_tag_field_definition* field_definition) :
		t_h4_tag_field(h4_data, field_definition),
		reference(c_h4_blamboozle::get_tag_reference_definition(h4_data, definition, field_definition->definition_address))
	{
		uint32_t definition_address = field_definition->definition_address;
		uint32_t group_tags_address = this->definition->group_tags_address;

		
	}
};

struct s_h4_tag_data_definition
{
	bpointer32<const char*> definition_name_address;
	uint32_t flags;
	uint32_t alignment_bit;
	uint32_t maximum_size;
	bpointer32<const char*> maximum_size_string_address;
	bpointer32<void*> byteswap_procedure;
	bpointer32<void*> copy_procedure;
	uint32_t : 32; // unknown
	uint32_t : 32; // unknown
	uint32_t : 32; // unknown
};

class c_h4_tag_field_data :
	public t_h4_tag_field<s_h4_tag_data_definition>
{
public:
	c_h4_tag_field_data(const char* h4_data, const s_h4_tag_field_definition* field_definition) :
		t_h4_tag_field(h4_data, field_definition, _h4_tag_field_validation_check_ensure_valid)
	{
		uint32_t definition_address = field_definition->definition_address;

		if (definition)
		{
			const char* definition_name = h4_va_to_pointer(h4_data, definition->definition_name_address);
			c_console::write_line("found data for field '%s' called '%s'", name, definition_name);
		}
	}
};

class c_h4_tag_field_struct :
	public t_h4_tag_field<s_h4_tag_struct_definition>
{
public:
	c_h4_tag_struct* tag_struct;

	c_h4_tag_field_struct(const char* h4_data, const s_h4_tag_field_definition* field_definition) :
		t_h4_tag_field(h4_data, field_definition, _h4_tag_field_validation_check_ensure_valid),
		tag_struct(c_h4_blamboozle::get_tag_struct_definition(h4_data, definition, field_definition->definition_address))
	{
		uint32_t definition_address = field_definition->definition_address;
		const char* field_set_display_name = h4_va_to_pointer(h4_data, definition->display_name);
		const char* field_set_name = h4_va_to_pointer(h4_data, definition->name);

		
	}
};

class c_h4_tag_field_block :
	public t_h4_tag_field<s_h4_tag_block_definition>
{
public:
	c_h4_tag_block* tag_block_definition;

	c_h4_tag_field_block(const char* h4_data, const s_h4_tag_field_definition* field_definition) :
		t_h4_tag_field(h4_data, field_definition, _h4_tag_field_validation_check_ensure_valid),
		tag_block_definition(c_h4_blamboozle::get_tag_block_definition(h4_data, definition, nullptr))
	{
		uint32_t definition_address = field_definition->definition_address;

		
	}
};

class c_h4_tag_field_enum :
	public t_h4_tag_field<s_h4_tag_enum_definition>
{
public:
	c_h4_tag_enum* tag_enum;

	c_h4_tag_field_enum(const char* h4_data, const s_h4_tag_field_definition* field_definition) :
		t_h4_tag_field(h4_data, field_definition, _h4_tag_field_validation_check_ensure_valid),
		tag_enum(c_h4_blamboozle::get_tag_enum_definition(h4_data, definition))
	{
		uint32_t definition_address = field_definition->definition_address;

		
	}
};

struct s_h4_tag_block_flags
{
	bpointer32<const char*> display_name;
	bpointer32<const char*> name;
	uint32_t count;
	bpointer32<const char*> count_string;
	bpointer32<s_h4_tag_struct_definition*> struct_definition;
};

class c_h4_tag_field_block_flags :
	public t_h4_tag_field<s_h4_tag_block_flags>
{
public:
	const char* const display_name;
	const char* const name;
	uint32_t const count;
	const char* const count_string;
protected:
	const s_h4_tag_struct_definition* struct_definition;
public:
	c_h4_tag_struct* tag_struct_definition;

	c_h4_tag_field_block_flags(const char* h4_data, const s_h4_tag_field_definition* field_definition) :
		t_h4_tag_field(h4_data, field_definition, _h4_tag_field_validation_check_ensure_valid),
		display_name(h4_va_to_pointer(h4_data, definition->display_name)),
		name(h4_va_to_pointer(h4_data, definition->name)),
		count(definition->count),
		count_string(h4_va_to_pointer(h4_data, definition->count_string)),
		struct_definition(h4_va_to_pointer<s_h4_tag_struct_definition>(h4_data, definition->struct_definition)),
		tag_struct_definition(c_h4_blamboozle::get_tag_struct_definition(h4_data, struct_definition, definition->struct_definition))
	{
		uint32_t definition_address = field_definition->definition_address;
		uint32_t struct_definition_address = definition->struct_definition;

		
	}
};

class c_h4_tag_field_block_index :
	public t_h4_tag_field<s_h4_tag_block_definition>
{
public:
	const char* name;
	const char* display_name;
	uint32_t maximum_elememt_count;
	const char* maximum_element_count_string;
	c_h4_tag_struct* tag_struct;

	c_h4_tag_field_block_index(const char* h4_data, const s_h4_tag_field_definition* field_definition) :
		t_h4_tag_field(h4_data, field_definition, _h4_tag_field_validation_check_ensure_valid)
	{
		uint32_t definition_address = field_definition->definition_address;

		name = h4_va_to_pointer(h4_data, definition->name);
		display_name = h4_va_to_pointer(h4_data, definition->display_name);
		maximum_elememt_count = definition->maximum_element_count;
		maximum_element_count_string = h4_va_to_pointer(h4_data, definition->maximum_element_count_string);

		const s_h4_tag_struct_definition* struct_definition = reinterpret_cast<const s_h4_tag_struct_definition*>(h4_va_to_pointer(h4_data, definition->struct_definition));
		ASSERT(struct_definition != nullptr);
		tag_struct = c_h4_blamboozle::get_tag_struct_definition(h4_data, struct_definition, definition->struct_definition);

		
	}
};

struct s_h4_block_index_custom_search_definition
{
	bpointer32<const char*> name_address;
	bpointer32<void*> get_block_procedure;
	bpointer32<void*> is_valid_source_block_procedure;
};

class c_h4_tag_field_custom_block_index :
	public t_h4_tag_field<s_h4_block_index_custom_search_definition>
{
public:
	const char* name;

	c_h4_tag_field_custom_block_index(const char* h4_data, const s_h4_tag_field_definition* field_definition) :
		t_h4_tag_field(h4_data, field_definition, _h4_tag_field_validation_check_ensure_valid)
	{
		uint32_t definition_address = field_definition->definition_address;

		name = h4_va_to_pointer(h4_data, definition->name_address);

		
	}
};

class c_h4_tag_field_pad :
	public t_h4_tag_field<void>
{
public:
	uint32_t const padding;

	c_h4_tag_field_pad(const char* h4_data, const s_h4_tag_field_definition* field_definition) :
		t_h4_tag_field(h4_data, field_definition),
		padding(field_definition->definition_address)
	{

	}
};

class c_h4_tag_field_skip :
	public t_h4_tag_field<void>
{
public:
	uint32_t const length;

	c_h4_tag_field_skip(const char* h4_data, const s_h4_tag_field_definition* field_definition) :
		t_h4_tag_field(h4_data, field_definition),
		length(field_definition->definition_address)
	{

	}
};

struct s_h4_tag_array_definition
{
	bpointer32<const char*> name;
	buint32_t element_count;
	bpointer32<const char*> element_count_string;
	bpointer32<s_h4_tag_struct_definition*> struct_definition;
};

class c_h4_tag_field_array :
	public t_h4_tag_field<s_h4_tag_array_definition>
{
public:
	const char* const name;
	uint32_t const count;
	const char* const count_string;
protected:
	const s_h4_tag_struct_definition* struct_definition;
public:
	c_h4_tag_struct* tag_struct_definition;
	c_h4_tag_array* tag_array_definition;

	c_h4_tag_field_array(const char* h4_data, const s_h4_tag_field_definition* field_definition) :
		t_h4_tag_field(h4_data, field_definition, _h4_tag_field_validation_check_ensure_valid),
		name(h4_va_to_pointer(h4_data, definition->name)),
		count(definition->element_count),
		count_string(h4_va_to_pointer(h4_data, definition->element_count_string)),
		struct_definition(h4_va_to_pointer<s_h4_tag_struct_definition>(h4_data, definition->struct_definition)),
		tag_struct_definition(c_h4_blamboozle::get_tag_struct_definition(h4_data, struct_definition, definition->struct_definition)),
		tag_array_definition(c_h4_blamboozle::get_tag_array_definition(h4_data, definition))
	{
		uint32_t definition_address = field_definition->definition_address;
		uint32_t struct_definition_address = definition->struct_definition;

		
	}
};

class c_h4_tag_field_string :
	public t_h4_tag_field<void>
{
public:

	c_h4_tag_field_string(const char* h4_data, const s_h4_tag_field_definition* field_definition) :
		t_h4_tag_field(h4_data, field_definition, _h4_tag_field_validation_check_ensure_invalid)
	{
		uint32_t definition_address = field_definition->definition_address;

		
	}
};

class c_h4_tag_field_string_id :
	public t_h4_tag_field<void>
{
public:

	c_h4_tag_field_string_id(const char* h4_data, const s_h4_tag_field_definition* field_definition) :
		t_h4_tag_field(h4_data, field_definition, _h4_tag_field_validation_check_ensure_invalid)
	{
		uint32_t definition_address = field_definition->definition_address;

		
	}
};

enum e_tag_resource_type
{
	_tag_bcs_resource_type_sound = 2,
	_tag_bcs_resource_type_bitmap = 4,
};

struct s_h4_tag_resource_definition
{
	bpointer32<const char*> name;
	bigendian_type<e_tag_resource_type> resource_type;
	bpointer32<s_h4_tag_struct_definition*> struct_definition;
	bpointer32<void*> tag_resource_vtable; // c_tag_resource_vtable<c_sound_resource_vtable>
	buint32_t unknown0;
	bpointer32<const char*> filepath;
	buint32_t count;
	buint32_t unknown1;
	buint32_t unknown2;
};

class c_h4_tag_resource_definition :
	public t_h4_tag_field<s_h4_tag_resource_definition>
{
public:
	const char* const name;
	e_tag_resource_type const resource_type;
	const s_h4_tag_struct_definition* const struct_definition;
	const void* const tag_resource_vtable;
	buint32_t const unknown0;
	const char* const filepath;
	buint32_t const count;
	buint32_t const unknown1;
	buint32_t const unknown2;

	c_h4_tag_struct* tag_struct;
	c_h4_tag_resource* tag_resource_definition;

	c_h4_tag_resource_definition(const char* h4_data, const s_h4_tag_field_definition* field_definition) :
		t_h4_tag_field(h4_data, field_definition, _h4_tag_field_validation_check_ensure_valid),
		name(h4_va_to_pointer(h4_data, definition->name)),
		resource_type(definition->resource_type),
		struct_definition(h4_va_to_pointer<s_h4_tag_struct_definition>(h4_data, definition->struct_definition)),
		tag_resource_vtable(h4_va_to_pointer<void>(h4_data, definition->struct_definition)),
		unknown0(definition->unknown0),
		filepath(h4_va_to_pointer(h4_data, definition->filepath)),
		count(definition->count),
		unknown1(definition->unknown1),
		unknown2(definition->unknown2),
		tag_struct(c_h4_blamboozle::get_tag_struct_definition(h4_data, struct_definition, definition->struct_definition)),
		tag_resource_definition(c_h4_blamboozle::get_tag_resource_definition(h4_data, definition))
	{
		uint32_t definition_address = field_definition->definition_address;

		ASSERT(unknown0 == 0);
		//ASSERT(unknown1 == 0);
		//ASSERT(unknown2 == 0);

		
	}
};

struct s_h4_tag_interop_definition
{
	GUID guid;
	bpointer32<s_h4_tag_struct_definition*> struct_definition;
	bpointer32<void*> interop_vtable; // c_tag_d3d_interop_vtable
	bpointer32<const char*> name;
	buint32_t unknown;
};

class c_h4_tag_interop_definition :
	public t_h4_tag_field<s_h4_tag_interop_definition>
{
public:
	c_h4_tag_interop* tag_interop_definition;

	c_h4_tag_interop_definition(const char* h4_data, const s_h4_tag_field_definition* field_definition) :
		t_h4_tag_field(h4_data, field_definition, _h4_tag_field_validation_check_ensure_valid),
		tag_interop_definition(c_h4_blamboozle::get_tag_interop_definition(h4_data, definition))
	{
		uint32_t definition_address = field_definition->definition_address;


	}
};
//
//class c_h4_tag_interop_definition :
//	public t_h4_tag_field<s_h4_tag_interop_definition>
//{
//public:
//	GUID const guid;
//protected:
//	const s_h4_tag_struct_definition* const struct_definition;
//public:
//	const char* name;
//	uint32_t unknown;
//	c_h4_tag_struct* tag_struct;
//
//	c_h4_tag_interop_definition(const char* h4_data, const s_h4_tag_field_definition* field_definition) :
//		t_h4_tag_field(h4_data, field_definition, _h4_tag_field_validation_check_ensure_valid),
//		guid(definition->guid),
//		struct_definition(h4_va_to_pointer<s_h4_tag_struct_definition>(h4_data, definition->struct_definition)),
//		name(h4_va_to_pointer(h4_data, definition->name)),
//		unknown(definition->unknown),
//		tag_struct(c_h4_blamboozle::get_tag_struct_definition(h4_data, struct_definition, definition->struct_definition))
//	{
//		uint32_t definition_address = field_definition->definition_address;
//
//		
//	}
//};

struct s_tag_custom_tool_data_definition;
class c_h4_tag_field_custom :
	public t_h4_tag_field<s_tag_custom_tool_data_definition>
{
public:
	c_h4_tag_field_custom(const char* h4_data, const s_h4_tag_field_definition* field_definition) :
		t_h4_tag_field(h4_data, field_definition)
	{
		uint32_t definition_address = field_definition->definition_address;

		
	}
};