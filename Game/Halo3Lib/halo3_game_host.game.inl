
uintptr_t halo3_engine_shutdown_offset(s_engine_platform_build engine_platform_build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0x1802659D0);
	return ~uintptr_t();
}
c_function_hook_ex<halo3_engine_shutdown_offset, void()> halo3_engine_shutdown = { "halo3_engine_shutdown", []()
{
	//write_stack_back_trace(__FUNCTIONW__, 2);
	//engine_shutdown();
} };

bool g_use_30_tick = false;
uintptr_t halo3_game_time_get_ticks_per_second_constant_offset(s_engine_platform_build engine_platform_build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0x180469ED0);
	OFFSET(_engine_type_halo3, _build_mcc_1_1658_0_0, 0x180467DE0);
	OFFSET(_engine_type_halo3, _build_mcc_1_1698_0_0, 0x180467ED0);
	OFFSET(_engine_type_halo3, _build_mcc_1_1716_0_0, 0x180467ED0);
	return ~uintptr_t();
}
c_function_hook_ex<halo3_game_time_get_ticks_per_second_constant_offset, float __stdcall()> halo3_game_time_get_ticks_per_second_constant = { "halo3_game_time_get_ticks_per_second_constant", []()
{
	float result = halo3_game_time_get_ticks_per_second_constant();
	//write_stack_back_trace(__FUNCTIONW__, 2);

	if (g_use_30_tick)
	{
		// #TODO: cache refactor
		/*if (is_valid(k_halo3_physical_base) && k_halo3_physical_base)
		{
			// #TODO: confirm `engine_time_tick` and `time_per_tick` have the same offset from `k_physical_base`
			e_build build = c_halo3_game_host::get_game_runtime().get_build();
			switch (build)
			{
			case _build_mcc_1_1698_0_0:
			case _build_mcc_1_1716_0_0:
			{
				unsigned long& engine_time_tick = *reinterpret_cast<unsigned long*>(k_halo3_physical_base + 0x3F0148);
				float& time_per_tick = *reinterpret_cast<float*>(k_halo3_physical_base + 0x3F014C);

				// check if the values are set
				if (engine_time_tick && time_per_tick)
				{
					// if the values are set, we set them to 30 and float(1/30) respectively
					engine_time_tick = 30;
					time_per_tick = 1.0f / engine_time_tick;
				}
				break;
			}
			}
		}*/
	}

	return g_use_30_tick ? 30.0f : result;
} };