/*
 *  AcmeWirelessLed.h
 */

#ifndef __ACMEWIRELESSLED_H__
#define __ACMEWIRELESSLED_H__

#include "LedDriver.h"

typedef struct AcmeWirelessLed AcmeWirelessLed;
extern AcmeWirelessLed *acmeWirelessLed;

void AcmeWirelessLed_init(AcmeWirelessLed *const me, const char *ssid, 
                                                     const char *key, 
                                                     int channel);

#endif
