/*
 ============================================================================
 Name        : BitHAL.c
 Author      : Dan Walmsley
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */



#include "WinCEPlatform.h"

IPlatform* Platform;
byte DataBuffer[100];

int main(void)
{
	int bytesReceived = 0;
	int bytesSent = 0;

	Platform = new_WinCEPlatform();

	Platform->Network->Start();

	Socket* ServerSocket = Platform->Network->new_Socket();

	ServerSocket->Connect("192.168.1.1", 1234);

	while(bytesSent < 4)
	{
		bytesSent += ServerSocket->Send(&DataBuffer[0 + bytesSent], 4 - bytesSent);
	}

	while(bytesReceived < 10)
	{
		bytesReceived += ServerSocket->Receive(&DataBuffer[0 + bytesReceived], 10 - bytesReceived);
	}

	ServerSocket->Disconnect();

	Platform->Network->Stop();
}
