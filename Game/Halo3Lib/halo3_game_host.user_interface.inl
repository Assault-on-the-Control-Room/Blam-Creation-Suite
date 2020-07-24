
#pragma region Screen Patches
// skip the `shell_get_external_host()` check that prevents the game from using the built-in start menu
uintptr_t start_menu_screen_patch_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0x1804C176B);
	OFFSET(_engine_type_halo3, _build_mcc_1_1658_0_0, 0x1804BFD89);
	OFFSET(_engine_type_halo3, _build_mcc_1_1698_0_0, 0x1804BFEA9);
	return ~uintptr_t();
}
c_data_patch<start_menu_screen_patch_offset> start_menu_screen_patch = { [](e_engine_type engine_type, e_build build, char* data, DataPatchPacket& packet)
{
	// nop `test    rax, rax`
	packet = MAKE_DATAPATCHPACKET(data, 3);
	nop_address(data, 3);
} };

// this patch shouldn't be needed
uintptr_t settings_menu_patch2_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0x1804C183A);
	OFFSET(_engine_type_halo3, _build_mcc_1_1658_0_0, 0x1804BFE53);
	OFFSET(_engine_type_halo3, _build_mcc_1_1698_0_0, 0x1804BFF73);
	return ~uintptr_t();
}
c_data_patch<settings_menu_patch2_offset> settings_menu_patch2 = {
	[](e_engine_type engine_type, e_build build, char* data, DataPatchPacket& packet)
	{
		packet = MAKE_DATAPATCHPACKET(data, 6);
		nop_address(data, 6);
	}
};

uintptr_t gui_screen_provider_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0x1804BBB50);
	OFFSET(_engine_type_halo3, _build_mcc_1_1658_0_0, 0x1804BA140);
	OFFSET(_engine_type_halo3, _build_mcc_1_1698_0_0, 0x1804BA230);
	return ~uintptr_t();
}
FunctionHookEx<gui_screen_provider_offset, void* __fastcall (__int64, int)> gui_screen_provider = { "gui_screen_provider", [](__int64 manager, int id)
{
	/* c_gui_screen_manager*, string_id */
	 void* gui_screen = nullptr;
	switch (id)
	{
	// avoid a crash when selecting the `gui_screen_pregame_lobby_matchmaking` via the `main_menu_screen_widget`, should this be in `halo3_game_host.mainmenu.inl`?
	case 0x100AC: break; // matchmaking
	default:
		gui_screen = gui_screen_provider(manager, id);
		break;
	}
	return gui_screen;
} };
#pragma endregion

#pragma region miscellaneous ui changes
uintptr_t version_number_callback_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0x1805430F0);
	OFFSET(_engine_type_halo3, _build_mcc_1_1658_0_0, 0x1805419B0);
	OFFSET(_engine_type_halo3, _build_mcc_1_1698_0_0, 0x180541C10);
	return ~uintptr_t();
}
FunctionHookEx<version_number_callback_offset, char __fastcall(__int64, wchar_t*, int)> version_number_callback = { "version_number_callback", [](__int64 unused, wchar_t* dst, int len)
{
	swprintf_s(dst, len, L"%s", L"ED 0.7 Sucks! Buy MCC on Steam");

	e_build build = c_halo3_game_host::get_game_runtime().get_build();
	const wchar_t* build_str = get_enum_string<const wchar_t*, true>(build);

	bool use_custom_version_number = true;
	char result = use_custom_version_number ? 1i8 : version_number_callback(unused, dst, len);

	switch (build)
	{
	case _build_mcc_1_1629_0_0:
	case _build_mcc_1_1658_0_0:
	case _build_mcc_1_1698_0_0:
		swprintf_s(dst, len, L"%s", build_str);
		break;
	}

	return result;
} };
#pragma endregion
