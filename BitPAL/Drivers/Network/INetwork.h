/*
 * INetwork.h
 *
 *  Created on: 29 Jan 2014
 *      Author: Dan
 */

#ifndef INETWORK_H_
#define INETWORK_H_

#include "types.h"

typedef struct Socket Socket;

struct Socket
{
	Int32 (*Connect)(char* IpAddress, UInt32 Port);
	Int32 (*Disconnect)();
	Int32 (*Send)(byte* Buffer, UInt32 Length);
	Int32 (*Receive)(byte* buffer, UInt32 Length);
	void* privateData;
};

typedef struct INetwork INetwork;

struct INetwork
{
	void (*Start)();
	void (*Stop)();
	Socket* (*new_Socket)();
};

#endif /* INETWORK_H_ */
