/*
 * WinCEPlatform.c
 *
 *  Created on: 29 Jan 2014
 *      Author: Dan
 */

#include "WinCEPlatform.h"
#include "Network_Winsock2.h"

IPlatform* new_WinCEPlatform()
{
	IPlatform* result = malloc(sizeof(IPlatform));

	result->Network = new_Network_Winsock2();

	return result;
}
