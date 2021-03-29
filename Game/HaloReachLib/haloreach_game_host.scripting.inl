
template<typename t_type>
class c_data_array_base
{
public:
	char name[32];
	size_t size;
	unsigned long signature;
	long max_count;
private:
	char __unknown30[8];
public:
	class c_allocation_interface* allocation;
	long next_index;
	long first_unallocated;
	long count;
	unsigned short next_identifier;
	unsigned short isolated_next_identifier;
	t_type* data_ptr;
	unsigned long* in_use_bit_vector;
	long data_offset;
	long bit_vector_offset;
private:
	char __unknown68[8];
};

template<typename t_type, size_t k_count>
class c_data_array : public c_data_array_base<t_type>
{
private:
	t_type data[k_count];
};

struct hs_syntax_datum
{
	short datum_header;
	short script_index;
	short node_expression_type;
	short flags;
	long next_node;
	long source_data;
	long source_offset_location;
	long source_file_offset;
};
constexpr size_t hs_syntax_datum_size = sizeof(hs_syntax_datum);
using hs_syntax_data_array = c_data_array<hs_syntax_datum, 61440>;

uintptr_t hs_syntax_data_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_haloreach, _build_mcc_1_1350_0_0, 0x180D2A048);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1367_0_0, 0x180D2A048);
	return ~uintptr_t();
}
hs_syntax_data_array*& g_hs_syntax_data = reference_symbol<hs_syntax_data_array*>("g_hs_syntax_data", hs_syntax_data_offset);

uintptr_t haloreach_spawn_ai_with_scripts_and_effects_patch_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_haloreach, _build_mcc_1_1270_0_0, 0x180730287);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1305_0_0, 0x18072F047);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1367_0_0, 0x18073A467);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1377_0_0, 0x18073A467);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1384_0_0, 0x18073A467);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1387_0_0, 0x18073A467);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1389_0_0, 0x18073A467);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1520_0_0, 0x18073B657);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1570_0_0, 0x18073B657);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1619_0_0, 0x18073B657);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1698_0_0, 0x18073D217);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1716_0_0, 0x18073D217);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1829_0_0, 0x1807470E5);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1864_0_0, 0x1807470E5);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1871_0_0, 0x1807470E5);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1930_0_0, 0x18058D36C);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1955_0_0, 0x18058D30C);
	OFFSET(_engine_type_haloreach, _build_mcc_1_2028_0_0, 0x18058D33C);
	OFFSET(_engine_type_haloreach, _build_mcc_1_2094_0_0, 0x18058D33C);
	return ~uintptr_t();
}

// Allows spawning AI via scripts or effects, props to Zeddikins
c_data_patch<haloreach_spawn_ai_with_scripts_and_effects_patch_offset> haloreach_spawn_ai_with_scripts_and_effects_patch = {
[](e_engine_type engine_type, e_build build, char* data, DataPatchPacket& packet)
{
	packet = MAKE_DATAPATCHPACKET(data, 6);
	nop_address(data, 6);
} };

uintptr_t haloreach_spawn_ai_with_scripts_and_effects_in_multiplayer_patch_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_haloreach, _build_mcc_1_1270_0_0, 0x18076F581);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1305_0_0, 0x18076E341);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1367_0_0, 0x180779781);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1377_0_0, 0x180779781);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1384_0_0, 0x180779781);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1387_0_0, 0x180779781);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1389_0_0, 0x180779781);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1520_0_0, 0x18077A971);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1570_0_0, 0x18077A971);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1619_0_0, 0x18077A971);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1698_0_0, 0x18077C531);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1716_0_0, 0x18077C531);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1829_0_0, 0x1807800E3);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1864_0_0, 0x1807800E3);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1871_0_0, 0x1807800E3);
	//OFFSET(_engine_type_haloreach, _build_mcc_1_1930_0_0, 0x1805BCFD0+??);
	//OFFSET(_engine_type_haloreach, _build_mcc_1_1955_0_0, 0x1805BCF70+??);
	//OFFSET(_engine_type_haloreach, _build_mcc_1_2028_0_0, 0x1805BCFA0+??);
	OFFSET(_engine_type_haloreach, _build_mcc_1_2094_0_0, 0x1805BCFC4);
	return ~uintptr_t();
}

// Allows spawning AI via scripts or effects in multiplayer, props to Zeddikins
c_data_patch<haloreach_spawn_ai_with_scripts_and_effects_in_multiplayer_patch_offset> haloreach_spawn_ai_with_scripts_and_effects_in_multiplayer_patch = {
[](e_engine_type engine_type, e_build build, char* data, DataPatchPacket& packet)
{
	if (haloreach_spawn_ai_with_scripts_and_effects_patch_offset(engine_type, build) == ~uintptr_t())
	{
		// if this patch offset doesn't exist you can't spawn ai, so return early
		return;
	}

	switch (build)
	{
	case _build_mcc_1_2094_0_0:
		packet = MAKE_DATAPATCHPACKET(data, 6);
		nop_address(data, 6);
		break;
	default:
		UINT8 jmp[1] = { 0xEB };
		packet = MAKE_DATAPATCHPACKET(data, sizeof(jmp));
		copy_to_address(data, jmp, sizeof(jmp));
		break;
	}
	

} };

uintptr_t allow_night_vision_in_multiplayer_patch_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_haloreach, _build_mcc_1_1305_0_0, 0x1805D66B7);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1367_0_0, 0x1805E18D7);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1377_0_0, 0x1805E18D7);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1384_0_0, 0x1805E18D7);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1387_0_0, 0x1805E18D7);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1389_0_0, 0x1805E18D7);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1520_0_0, 0x1805E2AC7);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1570_0_0, 0x1805E2AC7);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1619_0_0, 0x1805E2AC7);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1698_0_0, 0x1805E4687);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1716_0_0, 0x1805E4687);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1829_0_0, 0x1805E4B79);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1864_0_0, 0x1805E4B79);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1871_0_0, 0x1805E4B79);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1930_0_0, 0x18004B4F5);
	#pragma region crashes
	OFFSET(_engine_type_haloreach, _build_mcc_1_1955_0_0, 0x18004B4A5);
	OFFSET(_engine_type_haloreach, _build_mcc_1_2028_0_0, 0x18004B4A5);
	#pragma endregion
	OFFSET(_engine_type_haloreach, _build_mcc_1_2094_0_0, 0x1804705E7);
	return ~uintptr_t();
}

// Allow the use of night vision in multiplayer, props to Zeddikins
c_data_patch<allow_night_vision_in_multiplayer_patch_offset> allow_night_vision_in_multiplayer_patch = {
[](e_engine_type engine_type, e_build build, char* data, DataPatchPacket& packet)
{
	switch (build)
	{
	case _build_mcc_1_1930_0_0:
	case _build_mcc_1_1955_0_0:
	case _build_mcc_1_2028_0_0:
	default:
		packet = MAKE_DATAPATCHPACKET(data, 6);
		nop_address(data, 6);
		break;
	}
} };

#pragma pack(push, 4)
struct hs_script_op
{
	short return_type;
	short flags;
	__int32 __unused4;
	void(__fastcall* evaluate)(short opcode, unsigned short expression_index, char execute);
	const char* parameter_info;
	short parameter_count;
	short parameter_types;

	void replace_evaluate(LPVOID new_evaluate)
	{
		//printf("0x%08llX\n", *(UINT64 *)&evaluate);
		memcpy_virtual(&evaluate, &new_evaluate, sizeof(void*));
		//printf("0x%08llX\n", *(UINT64 *)&evaluate);
	}
	void print_parameter_info()
	{
		printf("%s\n", parameter_info);
	}
};
#pragma pack(pop)

uintptr_t hs_function_table_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_haloreach, _build_mcc_1_824_0_0, 0x180C33620);
	OFFSET(_engine_type_haloreach, _build_mcc_1_887_0_0, 0x180D89480);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1035_0_0, 0x180AB2910);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1186_0_0, 0x180ABF520);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1211_0_0, 0x180ABF4B0);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1246_0_0, 0x180ABC220);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1270_0_0, 0x180ABC230);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1305_0_0, 0x180AA76C0);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1350_0_0, 0x180AB2810);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1367_0_0, 0x180AB2820);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1377_0_0, 0x180AB2820);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1384_0_0, 0x180AB2820);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1387_0_0, 0x180AB2820);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1389_0_0, 0x180AB2820);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1520_0_0, 0x180AB4850);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1570_0_0, 0x180AB4850);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1619_0_0, 0x180AB4840);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1698_0_0, 0x180AC7890);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1716_0_0, 0x180AC7890);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1829_0_0, 0x180AC8A10);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1864_0_0, 0x180AC8A10);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1871_0_0, 0x180AC8A10);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1930_0_0, 0x1808DB7D0);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1955_0_0, 0x1808DB7D0);
	OFFSET(_engine_type_haloreach, _build_mcc_1_2028_0_0, 0x1808DB7D0);
	OFFSET(_engine_type_haloreach, _build_mcc_1_2094_0_0, 0x1808DB7D0);
	return ~uintptr_t();
}
hs_script_op* (&hs_function_table)[] = reference_symbol<hs_script_op* []>("hs_function_table", hs_function_table_offset);

uintptr_t hs_evaluate_arguments_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_haloreach, _build_mcc_1_824_0_0, 0x1807351D0);
	OFFSET(_engine_type_haloreach, _build_mcc_1_887_0_0, 0x1803EC060);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1035_0_0, 0x1801F9290);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1186_0_0, 0x1801F6420);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1211_0_0, 0x1801F6B60);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1246_0_0, 0x1801EF600);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1270_0_0, 0x1801EF690);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1305_0_0, 0x1801EF7A0);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1350_0_0, 0x1801F1620);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1367_0_0, 0x1801F1610);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1377_0_0, 0x1801F1610);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1384_0_0, 0x1801F1610);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1387_0_0, 0x1801F1610);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1389_0_0, 0x1801F1610);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1520_0_0, 0x1801F17D0);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1570_0_0, 0x1801F17D0);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1619_0_0, 0x1801F17D0);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1698_0_0, 0x1801F3110);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1716_0_0, 0x1801F3110);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1829_0_0, 0x1801FA630);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1864_0_0, 0x1801FA630);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1871_0_0, 0x1801FA630);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1930_0_0, 0x18017FC24);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1955_0_0, 0x18017FBC4);
	OFFSET(_engine_type_haloreach, _build_mcc_1_2028_0_0, 0x18017FBF4);
	OFFSET(_engine_type_haloreach, _build_mcc_1_2094_0_0, 0x18017FBF4);
	return ~uintptr_t();
}

template<typename t_parameter>
c_function_hook_ex<hs_evaluate_arguments_offset, t_parameter __fastcall (unsigned short expression_index, short parameters_count, short* parameters, char execute)> hs_evaluate_arguments;

uintptr_t hs_return_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_haloreach, _build_mcc_1_824_0_0, 0x180734900);
	OFFSET(_engine_type_haloreach, _build_mcc_1_887_0_0, 0x1803EB790);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1035_0_0, 0x1801F8A00);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1186_0_0, 0x1801F5B90);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1211_0_0, 0x1801F62D0);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1246_0_0, 0x1801EED70);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1270_0_0, 0x1801EEE00);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1305_0_0, 0x1801EEF10);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1350_0_0, 0x1801F0D90);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1367_0_0, 0x1801F0D80);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1377_0_0, 0x1801F0D80);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1384_0_0, 0x1801F0D80);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1387_0_0, 0x1801F0D80);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1389_0_0, 0x1801F0D80);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1520_0_0, 0x1801F0F40);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1570_0_0, 0x1801F0F40);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1619_0_0, 0x1801F0F40);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1698_0_0, 0x1801F2880);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1716_0_0, 0x1801F2880);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1829_0_0, 0x1801F9C70);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1864_0_0, 0x1801F9C70);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1871_0_0, 0x1801F9C70);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1930_0_0, 0x18017F358);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1955_0_0, 0x18017F2F8);
	OFFSET(_engine_type_haloreach, _build_mcc_1_2028_0_0, 0x18017F328);
	OFFSET(_engine_type_haloreach, _build_mcc_1_2094_0_0, 0x18017F328);
	return ~uintptr_t();
}
c_function_hook_ex<hs_return_offset, __int64 __fastcall (unsigned short expression_index, unsigned int handle)> hs_return;

hs_script_op* hs_function_get(short opcode)
{
	REFERENCE_ASSERT(hs_function_table);
	return hs_function_table[opcode];
}

template<typename t_parameter>
t_parameter& hs_macro_function_evaluate(short opcode, unsigned short expression_index, char execute)
{
	hs_script_op* hs_function = hs_function_get(opcode);
	return *hs_evaluate_arguments<t_parameter*>(expression_index, hs_function->parameter_count, &hs_function->parameter_types, execute);
}

uintptr_t hs_inspect_str_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_haloreach, _build_mcc_1_824_0_0, 0x180732290);
	OFFSET(_engine_type_haloreach, _build_mcc_1_887_0_0, 0x1803E9120);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1035_0_0, 0x1801F6B00);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1186_0_0, 0x1801F3D10);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1211_0_0, 0x1801F4450);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1246_0_0, 0x1801ECEF0);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1270_0_0, 0x1801ECF80);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1305_0_0, 0x1801ED090);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1350_0_0, 0x1801EEF10);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1367_0_0, 0x1801EEF00);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1377_0_0, 0x1801EEF00);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1384_0_0, 0x1801EEF00);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1387_0_0, 0x1801EEF00);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1389_0_0, 0x1801EEF00);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1520_0_0, 0x1801EF0C0);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1570_0_0, 0x1801EF0C0);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1619_0_0, 0x1801EF0C0);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1698_0_0, 0x1801F0A00);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1716_0_0, 0x1801F0A00);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1829_0_0, 0x1801F80D0);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1864_0_0, 0x1801F80D0);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1871_0_0, 0x1801F80D0);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1930_0_0, 0x18017DCD8);
	OFFSET(_engine_type_haloreach, _build_mcc_1_1955_0_0, 0x18017DC78);
	OFFSET(_engine_type_haloreach, _build_mcc_1_2028_0_0, 0x18017DCA8);
	OFFSET(_engine_type_haloreach, _build_mcc_1_2094_0_0, 0x18017DCA8);
	return ~uintptr_t();
}
c_function_hook_ex<hs_inspect_str_offset, char* __fastcall (__int64 unused, int id, char* dst, int len)> hs_inspect_str;

void __fastcall hs_print_evaluate(short opcode, unsigned short expression_index, char execute)
{
	int& out_parameter = hs_macro_function_evaluate<int>(opcode, expression_index, execute);
	if (&out_parameter)
	{
		char buf[1024] = {};
		hs_inspect_str(0, out_parameter, buf, 1024);
		printf("%s\n", buf);

		hs_return(expression_index, 0);
	}
}
