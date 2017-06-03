/*
 *  AcmeWirelessLed.h
 */

#ifndef __ACMEWIRELESSLED_H__
#define __ACMEWIRELESSLED_H__

#include "LedDriver.h"
#include "DoorLockDriver.h"

typedef struct AcmeWirelessLed AcmeWirelessLed;
struct AcmeWirelessLed
{
	LedDriver ledDriver;
	DoorLockDriver lockDriver;
    const char *ssid;
    const char *key;
    int channel;
};

void AcmeWirelessLed_init(AcmeWirelessLed *const me, const char *ssid, 
                                                     const char *key, 
                                                     int channel);

#endif
