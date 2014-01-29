/*
 * Platform.h
 *
 *  Created on: 29 Jan 2014
 *      Author: Dan
 */

#ifndef IPLATFORM_H_
#define IPLATFORM_H_

#include "types.h"
#include "INetwork.h"

typedef struct IPlatform
{
	INetwork* Network;
}IPlatform;

#endif /* PLATFORM_H_ */
