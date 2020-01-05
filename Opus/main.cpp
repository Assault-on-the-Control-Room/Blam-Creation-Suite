#include <HaloReachLib\haloreachlib-private-pch.h>

extern void init_halo_reach(EngineVersion engineVersion, BuildVersion buildVersion);
extern void deinit_halo_reach(EngineVersion engineVersion, BuildVersion buildVersion);

int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd
)
{
	GameLauncher::CheckSteamAPI();

	GameLauncher::EnsureBink2Win64IsLoaded("bink2w64.dll", "..\\MCC\\Binaries\\Win64");

	GameLauncher::SetupGlobalHooks();
	GameLauncher::RegisterGameLaunchCallback(EngineVersion::HaloReach, init_halo_reach);
	GameLauncher::RegisterGameShutdownCallback(EngineVersion::HaloReach, deinit_halo_reach);

	CustomWindow::SetIcon(LoadIconA(GetModuleHandle(NULL), MAKEINTRESOURCEA(IDI_ICON1)));

	//GameRender::Init(hInstance, NULL, NULL);

	GameInterface gameInterface = GameInterface("HaloReach\\haloreach.dll");
	int result = GameLauncher::Run(hInstance, lpCmdLine, gameInterface);
	return result;
}