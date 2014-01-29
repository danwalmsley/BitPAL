/*
 ============================================================================
 Name        : BitHAL.c
 Author      : Dan Walmsley
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#define PLATFORM_WINCE	0x8000
#define PLATFORM_BITTHUNDER	0x8001
#define PLATFORM_STM32F4DISCOVERY 0x8002;

#define PLATFORM	PLATFORM_WINCE

#if PLATFORM	== PLATFORM_WINCE
#include "WinCEPlatform.h"
#elif PLATFORM	== PLATFORM_BITTHUNDER
#include "BitThunderPlatform.h"
#elif PLATFORM 	== PLATFORM_STM32F4DISCOVERY
#include "STM32F4DiscoveryPlatform.h"
#endif

IPlatform* Platform;

IPlatform* InitialisePlatform()
{
#if PLATFORM	== PLATFORM_WINCE
	return new_WinCEPlatform();
#elif PLATFORM	== PLATFORM_BITTHUNDER
	return new_BitThunderPlatform();
#elif PLATFORM 	== PLATFORM_STM32F4DISCOVERY
	return new_STM32F4DiscoveryPlatform();
#endif
}

int main(void)
{
	byte DataBuffer[100];
	int bytesReceived = 0;
	int bytesSent = 0;

	Platform = InitialisePlatform();

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
