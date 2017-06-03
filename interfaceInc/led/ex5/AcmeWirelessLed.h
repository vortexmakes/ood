/*
 *  AcmeWirelessLed.h
 */

#ifndef __ACMEWIRELESSLED_H__
#define __ACMEWIRELESSLED_H__

#include "LedDriver.h"

#define ACME_MAX_NUM_LEDS       8

typedef struct AcmeWirelessLed AcmeWirelessLed;

AcmeWirelessLed *AcmeWirelessLed_ctor(const char *ssid, const char *key, 
                                      int channel);
void AcmeWirelessLed_dtor(AcmeWirelessLed *const me);

#endif
