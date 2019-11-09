#pragma once
class NetworkManager
{
public: /* static functions */
	static void CreateClientConnection();
	static void CreateServerConnection();
	static int RecieveFrom(char* buffer, uint32_t buffersize, struct sockaddr * from, int * fromlen);
	static int SendTo(char* buffer, uint32_t buffersize);
};

