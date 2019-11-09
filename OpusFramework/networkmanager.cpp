#include "opusframework-private-pch.h"

SOCKET LocalSocket = INVALID_SOCKET;
int s_destinationIPAddress = -1;
int s_destinationPort = 2000;
bool s_isHost = false;

void NetworkManager::CreateClientConnection()
{
	if (LocalSocket == INVALID_SOCKET)
	{
		/* Open a datagram socket */
		LocalSocket = socket(AF_INET, SOCK_DGRAM, 0);
		if (LocalSocket == INVALID_SOCKET)
		{
			FATAL_ERROR("Could not create socket.");
		}
	}

	u_long nonblocking_enabled = TRUE;
	ioctlsocket(LocalSocket, FIONBIO, &nonblocking_enabled);

	//int nbo_ipv4 = inet_addr("127.0.0.1");
	u_short nbo_port = htons(s_destinationPort);

	sockaddr_in addr = {};
	addr.sin_family = AF_INET;
	addr.sin_port = nbo_port;
	//addr.sin_addr.s_addr = nbo_ipv4;
	addr.sin_addr.s_addr = 0;
	auto bind_result = bind(LocalSocket, (sockaddr*)&addr, sizeof(addr));
	assert(bind_result == 0);
}

void NetworkManager::CreateServerConnection()
{
	if (LocalSocket == INVALID_SOCKET)
	{
		/* Open a datagram socket */
		LocalSocket = socket(AF_INET, SOCK_DGRAM, 0);
		if (LocalSocket == INVALID_SOCKET)
		{
			FATAL_ERROR("Could not create socket.");
		}
	}

	u_long nonblocking_enabled = TRUE;
	ioctlsocket(LocalSocket, FIONBIO, &nonblocking_enabled);

	//int nbo_ipv4 = inet_addr("127.0.0.1");
	u_short nbo_port = htons(s_destinationPort);

	sockaddr_in addr = {};
	addr.sin_family = AF_INET;
	addr.sin_port = nbo_port;
	//addr.sin_addr.s_addr = nbo_ipv4;
	addr.sin_addr.s_addr = 0;
	auto bind_result = bind(LocalSocket, (sockaddr*)&addr, sizeof(addr));
	assert(bind_result == 0);

	s_isHost = true;
}

static constexpr size_t x = sizeof(sockaddr);
int NetworkManager::RecieveFrom(char* buffer, uint32_t buffersize, struct sockaddr* from, int* fromlen)
{
	// terrible testing code that didn't work
	int recvfromResult = recvfrom(LocalSocket, buffer, buffersize, 0, from, fromlen);

	if (recvfromResult >= 0)
	{
		WriteLineVerbose("IGameEngineHost::NetworkReceiveFrom %i", recvfromResult);
		return recvfromResult;
	}

	int err = WSAGetLastError();
	if (err != WSAEWOULDBLOCK)
	{
		WriteLineVerbose("IGameEngineHost::NetworkReceiveFrom (error) %i", err);
		return -1;
	}
	else
	{
		return 0;
	}
}

int NetworkManager::SendTo(char* buffer, uint32_t buffersize)
{
	//assert(networkID != NetworkID::Invalid && networkID < NetworkID::k_NumNetworkID);
	sockaddr_in addr = {};
	addr.sin_family = AF_INET;

	if (s_isHost)
	{
		addr.sin_addr.s_addr = inet_addr("10.255.0.2");
		addr.sin_port = htons(s_destinationPort);
	}
	else
	{
		addr.sin_addr.s_addr = inet_addr("10.255.0.1");
		addr.sin_port = htons(s_destinationPort);
	}

	int sendtoResult = sendto(LocalSocket, buffer, buffersize, 0, (sockaddr*)&addr, sizeof(addr));
	if (sendtoResult == -1)
	{
		int err = WSAGetLastError();
		WriteLineVerbose("IGameEngineHost::NetworkSendTo err %i", err);
	}
	else
	{
		WriteLineVerbose("IGameEngineHost::NetworkSendTo %i", sendtoResult);
	}

	return sendtoResult;
}
