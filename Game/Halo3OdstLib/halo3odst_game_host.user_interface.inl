
#pragma region Screen Patches
// skip the `shell_get_external_host()` check that prevents the game from using the built-in start menu
uintptr_t halo3odst_start_menu_screen_patch_offset(s_engine_platform_build engine_platform_build)
{
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1767_0_0, 0x1802DF294);
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1778_0_0, 0x1802DEF74);
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1792_0_0, 0x1802DFA04);
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1829_0_0, 0x1802E04C4);
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1864_0_0, 0x1802E04C4);
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1871_0_0, 0x1802E04C4);
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1955_0_0, 0x18022D3AC);
	OFFSET(_engine_type_halo3odst, _build_mcc_1_2028_0_0, 0x18022D3AC);
	OFFSET(_engine_type_halo3odst, _build_mcc_1_2094_0_0, 0x18022D3AC);
	return ~uintptr_t();
}
c_data_patch<halo3odst_start_menu_screen_patch_offset> halo3odst_start_menu_screen_patch = { [](s_engine_platform_build engine_platform_build, char* data, DataPatchPacket& packet)
{
	// nop `test    r9, r9`
	packet = MAKE_DATAPATCHPACKET(data, 3);
	nop_address(data, 3);
} };

// this patch shouldn't be needed
uintptr_t halo3odst_settings_menu_patch2_offset(s_engine_platform_build engine_platform_build)
{
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1767_0_0, 0x1802DF3AC);
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1778_0_0, 0x1802DF08C);
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1792_0_0, 0x1802DFB1C);
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1829_0_0, 0x1802E05DC);
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1864_0_0, 0x1802E05DC);
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1871_0_0, 0x1802E05DC);
	OFFSET(_engine_type_halo3odst, _build_mcc_1_1955_0_0, 0x18022D4F8);
	OFFSET(_engine_type_halo3odst, _build_mcc_1_2028_0_0, 0x18022D4F8);
	OFFSET(_engine_type_halo3odst, _build_mcc_1_2094_0_0, 0x18022D4F8);
	return ~uintptr_t();
}
c_data_patch<halo3odst_settings_menu_patch2_offset> halo3odst_settings_menu_patch2 = {
	[](s_engine_platform_build engine_platform_build, char* data, DataPatchPacket& packet)
	{
		packet = MAKE_DATAPATCHPACKET(data, 6);
		nop_address(data, 6);
	}
};
#pragma endregion
