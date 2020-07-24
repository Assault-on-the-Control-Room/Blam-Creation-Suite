#include "symbolslib-private-pch.h"

c_runtime_symbols* c_runtime_symbols::runtime_symbols = nullptr;

c_runtime_symbols& c_runtime_symbols::runtime()
{
	if (runtime_symbols == nullptr)
	{
		runtime_symbols = new c_runtime_symbols();
	}
	ASSERT(runtime_symbols != nullptr);
	return *runtime_symbols;
}

c_runtime_symbols::c_runtime_symbols() :
	symbol_file_data(nullptr),
	symbol_file_data_size(0)
{
	static bool has_symbols_blob = c_resources_manager::get_resource(_bcs_resource_type_symbols_blob, &symbol_file_data, &symbol_file_data_size, true);
	if (has_symbols_blob)
	{
		ASSERT(symbol_file_data != nullptr);
		ASSERT(symbol_file_data_size > 0);
		symbol_file_header = reinterpret_cast<s_symbol_file_header*>(symbol_file_data);
	}

	init();
}

c_runtime_symbols::c_runtime_symbols(char* symbol_file_data, size_t symbol_file_data_size) :
	symbol_file_data(symbol_file_data),
	symbol_file_data_size(symbol_file_data_size)
{
	symbol_file_header = reinterpret_cast<s_symbol_file_header*>(symbol_file_data);
	init();
}

void c_runtime_symbols::init()
{
	if (symbol_file_header)
	{
		uintptr_t symbol_file_data_address = reinterpret_cast<uintptr_t>(symbol_file_data);

		symbol_file_header->sections_offset += symbol_file_data_address;
		symbol_file_header->public_symbols_offset += symbol_file_data_address;
		symbol_file_header->static_symbols_offset += symbol_file_data_address;
		symbol_file_header->binary_name_offset += symbol_file_data_address;
		symbol_file_header->timestamp_string_offset += symbol_file_data_address;

		for (uint32_t section_index = 0; section_index < symbol_file_header->sections_count; section_index++)
		{
			s_symbol_file_section& section = symbol_file_header->sections[section_index];
			section.class_string_offset += symbol_file_data_address;
			section.name_string_offset += symbol_file_data_address;
		}

		for (uint32_t public_symbol_index = 0; public_symbol_index < symbol_file_header->public_symbols_count; public_symbol_index++)
		{
			s_symbol_file_public& public_symbol = symbol_file_header->public_symbols[public_symbol_index];
			public_symbol.lib_and_object_offset += symbol_file_data_address;
			public_symbol.mangled_symbol_name_offset += symbol_file_data_address;
			public_symbol.symbol_name_offset += symbol_file_data_address;
#ifndef _DEBUG
			public_symbol.complete_symbol_name_offset += symbol_file_data_address;
#endif
		}

		for (uint32_t static_symbol_index = 0; static_symbol_index < symbol_file_header->static_symbols_count; static_symbol_index++)
		{
			s_symbol_file_static& static_symbol = symbol_file_header->static_symbols[static_symbol_index];
			static_symbol.lib_and_object_offset += symbol_file_data_address;
			static_symbol.mangled_symbol_name_offset += symbol_file_data_address;
			static_symbol.symbol_name_offset += symbol_file_data_address;
#ifndef _DEBUG
			static_symbol.complete_symbol_name_offset += symbol_file_data_address;
#endif
		}

		debug_point;
	}
}

s_symbol_file_public* c_runtime_symbols::get_public_symbol_by_name(const char* symbol_name)
{
	if (symbol_file_header == nullptr)
	{
		return nullptr;
	}

	for (uint32_t public_symbol_index = 0; public_symbol_index < symbol_file_header->public_symbols_count; public_symbol_index++)
	{
		s_symbol_file_public& public_symbol = symbol_file_header->public_symbols[public_symbol_index];
		
		if (strcmp(public_symbol.symbol_name, symbol_name) == 0)
		{
			return &public_symbol;
		}
	}

	return nullptr;
}

s_symbol_file_public* c_runtime_symbols::get_public_symbol_by_relative_virtual_address(uint64_t relative_virtual_address)
{
	uint64_t base_virtual_adress = symbol_file_header->preferred_load_address;

	for (uint32_t public_symbol_index = 0; public_symbol_index < symbol_file_header->public_symbols_count; public_symbol_index++)
	{
		s_symbol_file_public& public_symbol = symbol_file_header->public_symbols[public_symbol_index];

		uint64_t symbol_rva = public_symbol.rva_plus_base - base_virtual_adress; // #TODO: calculate this once

		if (symbol_rva == relative_virtual_address)
		{
			return &public_symbol;
		}
	}
	return nullptr;
}

s_symbol_file_public* c_runtime_symbols::get_public_symbol_by_base_virtual_address(uint64_t relative_virtual_address)
{
	uint64_t base_virtual_adress = symbol_file_header->preferred_load_address;
	return get_public_symbol_by_relative_virtual_address(relative_virtual_address - base_virtual_adress);
}

s_symbol_file_public* c_runtime_symbols::get_public_symbol_by_virtual_address(void* pointer)
{
	static HMODULE instance_handle = c_runtime_util::get_current_module();

	uint64_t virtual_address = reinterpret_cast<uintptr_t>(pointer);
	uint64_t module_address = reinterpret_cast<uintptr_t>(instance_handle);
	uint64_t relative_virtual_address = virtual_address - module_address;

	return get_public_symbol_by_relative_virtual_address(relative_virtual_address);
}
