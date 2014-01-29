/*
 * Network_Winsock2.c
 *
 *  Created on: 29 Jan 2014
 *      Author: Dan
 */

#include "Network_Winsock2.h"

static void Network_Winsock2_Start();
static void Network_Winsock2_Stop();
static Socket* Network_Winsock_new_Socket();

INetwork* new_Network_Winsock2()
{
	INetwork* result = malloc(sizeof(INetwork));

	result->Start = Network_Winsock2_Start();
	result->Stop = Network_Winsock2_Stop();
	result->new_Socket = Network_Winsock_new_Socket();

	return result;
}


static void Network_Winsock2_Start()
{
	net_start();
}


static void Network_Winsock2_Stop()
{
	net_stop();
}


static Socket* Network_Winsock_new_Socket()
{
	Socket* result = malloc(sizeof(Socket));

	return result;
}


