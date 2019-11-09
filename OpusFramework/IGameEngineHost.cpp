#include "opusframework-private-pch.h"

IGameEngineHost::IGameEngineHost()
	:pGameEvents(&IGameEvents::g_gameEvents)
{

}

IGameEngineHost::~IGameEngineHost()
{

}

char __fastcall IGameEngineHost::Member00()
{
	//WriteLineVerbose("IGameEngineHost::Member00");
	return 0;
}

void __fastcall IGameEngineHost::FrameEnd(IDXGISwapChain* pSwapChain, _QWORD a2)
{
	DebugUI::RenderFrame();
}

void __fastcall IGameEngineHost::Member02(__int64 player_identifier, unsigned int a2, __int64 a3, float a4, float a5, float a6, float a7)
{
	//WriteLineVerbose("IGameEngineHost::Member02");
}

void __fastcall IGameEngineHost::GameStatusUpdated(IGameEngine::eGameStatus status)
{
	WriteLineVerbose("IGameEngineHost::GameStatusUpdated(%d)", status);

	// `Unknown16` also needs a second arg so we skip it
	if (status != IGameEngine::eGameStatus::Unknown16)
	{
		GameLauncher::s_pHaloReachEngine->UpdateGameStatus(status);
	}
}

__int64 __fastcall IGameEngineHost::GameExited(unsigned int a1, char* a2, int a3)
{
	GameLauncher::s_currentState = GameLauncher::CurrentState::eFinished;
	SplashScreen::Destroy();

	WriteLineVerbose("GameExited %u [%s]", a1, a2);
	return __int64(0);
}

__int64 __fastcall IGameEngineHost::WriteBufferToFile(LPVOID pBuffer, size_t bufferSize)
{
	WriteLineVerbose("IGameEngineHost::Member05 WriteBufferToFile %p %016llx", pBuffer, bufferSize);
	return __int64(0);
}

void __fastcall IGameEngineHost::Member06(Member06Struct* buffer)
{
	WriteLineVerbose("IGameEngineHost::Member06");
}

void __fastcall IGameEngineHost::Member07(unsigned int a1)
{
	WriteLineVerbose("IGameEngineHost::Member07 PauseMenuOpened");
}

void __fastcall IGameEngineHost::Member08(const wchar_t *, const wchar_t *) 
{ 
	WriteLineVerbose("IGameEngineHost::Member08");
}

void __fastcall IGameEngineHost::Member09(wchar_t buffer0[1024], wchar_t buffer1[1024])
{ 
	WriteLineVerbose("IGameEngineHost::Member09");
}

IGameEvents* __fastcall IGameEngineHost::GetGameEvents()
{
	return pGameEvents;
}

void __fastcall IGameEngineHost::UpdateGameVariant(IGameVariant* variant) 
{ 
	WriteLineVerbose("IGameEngineHost::UpdateGameVariant");
}

void __fastcall IGameEngineHost::UpdateMapVariant(IMapVariant* variant) 
{ 
	WriteLineVerbose("IGameEngineHost::UpdateMapVariant"); 
}

void __fastcall IGameEngineHost::Member13(const wchar_t*, const wchar_t*, const void*, unsigned int) 
{ 
	WriteLineVerbose("IGameEngineHost::Member12");
}

char __fastcall IGameEngineHost::Member14(int controllerIndex, BYTE* flags)
{
	WriteLineVerbose("IGameEngineHost::Member13");
	return 0;
}

char __fastcall IGameEngineHost::Member15(int controllerIndex, BYTE* buffer)
{
	WriteLineVerbose("IGameEngineHost::Member15");
	return 0;
}

char __fastcall IGameEngineHost::GetNextLevelInfo(e_map_id* map_id, int* campaign_insertion_point, FILETIME* filetime, _DWORD*)
{
	WriteLineVerbose("IGameEngineHost::Member16 GetNextLevelInfo");
	return 0;
}

bool __fastcall IGameEngineHost::Member17(int a1)
{
	WriteLineVerbose("IGameEngineHost::Member17");
	return false;
}

void __fastcall IGameEngineHost::Member18(int) 
{ 
	WriteLineVerbose("IGameEngineHost::Member18"); 
}

__int64 __fastcall IGameEngineHost::MapLoadPecentStatus(__int64 a1, __int64 a2, float a3)
{
	/*WriteLineVerbose("GameEngineHostCallback::Member19 MapLoadPecentStatus %016llx", a1);*/
	return __int64(0);
}

void __fastcall IGameEngineHost::Member20(__int64 a1, __int8 a2) 
{ 
	WriteLineVerbose("IGameEngineHost::Member20");
}

__int64 __fastcall IGameEngineHost::GetMachineIdentifier(_QWORD a1)
{
	return __int64(3);
}

__int64 __fastcall IGameEngineHost::Member22(Member22Struct* buffer, __int64 a2)
{
	WriteLineVerbose("IGameEngineHost::Member22");
	return __int64(0);
}

char __fastcall IGameEngineHost::Member23(__int64 a1, __int64 a2)
{
	WriteLineVerbose("IGameEngineHost::Member23 ScoreboardOpened");
	return 1;
}

void __fastcall IGameEngineHost::GetSessionInfo(s_session_info_part* buffer)
{
	WriteVerbose("IGameEngineHost::GetSessionInfo");
}

void __fastcall IGameEngineHost::MembershipUpdate(s_session_membership *pSessionMembership, uint32_t playercount)
{
	WriteLineVerbose("s_session_membership count: %i", pSessionMembership->Count);
	for (int i = 0; i < pSessionMembership->Count; i++)
	{
		WriteLineVerbose("MachineIdentifier[%i]: 0x%llx", i, pSessionMembership->Members[i].MachineIdentifier);

		pSessionMembership->Members[i].SecureAddress = -1;
	}

	//if (g_isHost)
	//{
	//	pSessionMembership->Count = 2;
	//	static int x = 1;
	//	pSessionMembership->Members[1].MachineIdentifier = x;
	//}

	//auto x = &pSessionMembership->Members[0].SecureAddress;

	WriteLineVerbose("IGameEngineHost::Member25 MembershipUpdate");
};

bool __fastcall IGameEngineHost::Member26()
{
	WriteLineVerbose("IGameEngineHost::Member26");
	return false;
}

bool __fastcall IGameEngineHost::Member27()
{
	//WriteLineVerbose("IGameEngineHost::Member27");
	return false;
}

bool __fastcall IGameEngineHost::Member28(Member28Struct* buffer)
{
	if (!buffer)
	{
		return false;
	}
	WriteLineVerbose("IGameEngineHost::Member28");
	return true;
}

__int64 __fastcall IGameEngineHost::Member29(wchar_t playerNames[4][32], Member29Struct* buffer)
{
	// todo: find a good home for this
	SplashScreen::Destroy();

	WriteLineVerbose("IGameEngineHost::Member29");
	return __int64(0);
}

bool __fastcall IGameEngineHost::UpdateInput(_QWORD, InputBuffer* pInputBuffer)
{
	//if (GetAsyncKeyState(VK_F1))
	//{
	//	GameLauncher::s_pHaloReachEngine->Member02(IGameEngine::Member02EventEnum::Pause);
	//}
	//if (GetAsyncKeyState(VK_F2))
	//{
	//	GameLauncher::s_pHaloReachEngine->Member02(IGameEngine::Member02EventEnum::Unpause);
	//}


	/*
		When we load the level, we set the g_waitingForInputUpdate to true allowing us
		to reset the input system. This function sets the engine to use the keyboard
		or mouse input.
	*/

	memset(pInputBuffer, 0, sizeof(*pInputBuffer));
	pInputBuffer->unknown0 = 1;

	bool debugUIVisible = DebugUI::IsVisible();
	bool windowFocused = CustomWindow::IsWindowFocused();

	MouseMode mode = MouseMode::None;
	if (windowFocused)
	{
		mode = debugUIVisible ? MouseMode::UI : MouseMode::Exclusive;
	}
	MouseInput::SetMode(mode);

	// don't update and return an empty zero buffer
	if (debugUIVisible)
	{
		return unsigned __int8(1);
	}

	// get keyboard state
	BYTE keyboardState[256] = {};
	pInputBuffer->MouseX = 0.0f;
	pInputBuffer->MouseY = 0.0f;
	pInputBuffer->mouseButtonBits = 0;

	if (windowFocused)
	{
		GetKeyState(-1); // force keys to update
		if (GetKeyboardState(keyboardState))
		{
			for (int i = 0; i < 256; i++)
			{
				pInputBuffer->keyboardState[i] = (keyboardState[i] & 0b10000000) != 0;
			}
		}

		{
			float mouseInputX = MouseInput::GetMouseX();
			float mouseInputY = MouseInput::GetMouseY();

			pInputBuffer->MouseX += mouseInputX;
			pInputBuffer->MouseY += mouseInputY;

			bool leftButtonPressed = MouseInput::GetMouseButton(MouseInputButton::Left);
			bool rightButtonPressed = MouseInput::GetMouseButton(MouseInputButton::Right);
			bool middleButtonPressed = MouseInput::GetMouseButton(MouseInputButton::Middle);

			pInputBuffer->mouseButtonBits |= BYTE(leftButtonPressed) << 0;
			pInputBuffer->mouseButtonBits |= BYTE(middleButtonPressed) << 1;
			pInputBuffer->mouseButtonBits |= BYTE(rightButtonPressed) << 2;
		}
	}

	return unsigned __int8(1);
}

void IGameEngineHost::Member31()
{
	WriteLineVerbose("IGameEngineHost::Member31");
	// appears to be usermanagement related?
	// we haven't seen this fire yet and don't know its structure so throw an error
	throw;
}

void IGameEngineHost::XInputSetState(DWORD dwUserIndex, XINPUT_VIBRATION* pVibration)
{
	::XInputSetState(dwUserIndex, pVibration);
}

bool __fastcall IGameEngineHost::UpdatePlayerNames(__int64* playerIndices, wchar_t playerNames[4][32], size_t dataSize)
{
	if (playerNames && dataSize)
	{
		const wchar_t* ppNames[] = { L"Player", L"Player2", L"Player3",L"Player4" };

		for (int i = 0; i < 4; i++)
		{
			static wchar_t pPlayerNameBuffer[4][16] = {};
			if (pPlayerNameBuffer[i][0] == 0)
			{
				const wchar_t* pName = ppNames[i];
				if (i == 0)
				{
					if (Settings::ReadStringValueW(SettingsSection::Player, "Name", pPlayerNameBuffer[i], sizeof(pPlayerNameBuffer[i]), ppNames[i]) > 0)
					{
						pName = pPlayerNameBuffer[i];
					}
				}

				{
					if (wcsncmp(playerNames[i], pName, 16) == 0)
					{
						return true;
					}
					wcsncpy_s(playerNames[i], 32, pName, 16);
					WriteLineVerbose("player[%d].Name: set %ls", i, pName);
				}
			}
		}


		return true;
	}
	return false;
}

void IGameEngineHost::Member34(const wchar_t *a1, const wchar_t *a2) 
{ 
	WriteLineVerbose("IGameEngineHost::Member34"); 
}

bool IGameEngineHost::Member35(wchar_t *a1, __int64 a2)
{
	WriteLineVerbose("IGameEngineHost::Member35");
	return 0;
}

__int64 __fastcall IGameEngineHost::NetworkSendTo(NetworkID networkID, char* buffer, uint32_t buffersize, int a5)
{
	return NetworkManager::SendTo(buffer, buffersize);
}

__int64 IGameEngineHost::NetworkReceiveFrom(char* buffer, uint32_t buffersize, struct sockaddr * from, int * fromlen)
{
	return NetworkManager::RecieveFrom(buffer, buffersize, from, fromlen);
}

char* __fastcall IGameEngineHost::Member38(unsigned int a1)
{
	WriteLineVerbose("IGameEngineHost::Member38");
	return 0;
}

int __fastcall IGameEngineHost::Member39(BYTE* buffer)
{
	WriteLineVerbose("IGameEngineHost::Member39");
	return 0;
}

bool __fastcall IGameEngineHost::Member40(signed int a1, __int64 a2, __int64 a3)
{
	WriteLineVerbose("IGameEngineHost::Member40");
	return 0;
}

// new wave/set
void __fastcall IGameEngineHost::FirefightNew(__int64 a1, float a2)
{
	WriteLineVerbose("IGameEngineHost::FirefightNew");
}

BOOL __fastcall IGameEngineHost::Member42(__int64 a1, __int64 a2)
{
	WriteLineVerbose("IGameEngineHost::Member42");
	return 0;
}

bool __fastcall IGameEngineHost::GetPathByType(int pathType, char* buffer, size_t bufferlength)
{
	// this this should be in its function
	switch (pathType)
	{
	case 0:
		sprintf_s(buffer, bufferlength, "DebugLogs\\");
		break;
	case 1:
		sprintf_s(buffer, bufferlength, "Config\\");
		break;
	case 2:
		sprintf_s(buffer, bufferlength, "Temp\\");
		break;
	case 3:
		sprintf_s(buffer, bufferlength, "\\");
		break;
	}

	return 1;
}

// this is correct implementation inline with MCC
bool __fastcall IGameEngineHost::GetWidePathByType(int pathType, wchar_t* buffer, size_t bufferlength)
{
	// this this should be in its function
	switch (pathType)
	{
	case 0:
		swprintf_s(buffer, bufferlength, L"DebugLogs\\");
		break;
	case 1:
		swprintf_s(buffer, bufferlength, L"Config\\");
		break;
	case 2:
		swprintf_s(buffer, bufferlength, L"Temp\\");
		break;
	case 3:
		swprintf_s(buffer, bufferlength, L"\\");
		break;
	}

	return 1;
}

unsigned __int8* IGameEngineHost::Member45(_QWORD a1, unsigned __int8 *a2, _QWORD a3)
{
	return 0;
}

__int64 __fastcall IGameEngineHost::Member46(_QWORD, __int64)
{
	// appears to be security related
	WriteLineVerbose("IGameEngineHost::Member46");
	return 0;
}
