
#pragma region Shell Debug
uintptr_t halo3odst_external_launch_state_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1767_0_0, 0x180B79E64);
	return ~uintptr_t();
}
long& halo3odst_external_launch_state = reference_symbol<long>("halo3odst_external_launch_state", halo3odst_external_launch_state_offset);

uintptr_t halo3odst_main_game_launch_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1767_0_0, 0x180014270);
	return ~uintptr_t();
}
FunctionHookEx<halo3odst_main_game_launch_offset, char __fastcall(__int64 a1, __int64 a2, __int64 a3)> halo3odst_main_game_launch = { "halo3odst_main_game_launch", [](__int64 a1, __int64 a2, __int64 a3)
{
	static const char* external_launch_state_names[] =
	{
		"initial",
		"create_local_squad",
		"select_game_mode",
		"saved_film",
		"campaign",
		"save_game",
		"multiplayer",
		"survival",
		"wait_for_party",
		"join_remote_squad",
		"",
		"start_game",
		"finished"
	};

	ASSERT(is_valid(halo3odst_main_game_launch));
	if (is_valid(halo3odst_external_launch_state))
	{
		static long halo3odst_external_launch_state_prev = -1l;
		if (halo3odst_external_launch_state != halo3odst_external_launch_state_prev)
		{
			halo3odst_external_launch_state_prev = halo3odst_external_launch_state;
			printf("halo3odst_main_game_launch changed to: %s\n", external_launch_state_names[halo3odst_external_launch_state]);
		}

		char result = halo3odst_main_game_launch(a1, a2, a3);

		if (halo3odst_external_launch_state != halo3odst_external_launch_state_prev)
		{
			halo3odst_external_launch_state_prev = halo3odst_external_launch_state;
			printf("halo3odst_external_launch_state changed to: %s\n", external_launch_state_names[halo3odst_external_launch_state]);
		}

		return result;
	}
	else
	{
		char result = halo3odst_main_game_launch(a1, a2, a3);
		return result;
	}
} };
#pragma endregion