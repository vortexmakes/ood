/*
 *  AcmeWirelessLed.h
 */

#ifndef __ACMEWIRELESSLED_H__
#define __ACMEWIRELESSLED_H__

#include "LedDriver.h"

extern LedDriver *acmeWirelessLed;

void AcmeWirelessLed_init(const char *ssid, 
                          const char *key, 
                          int channel);

#endif
