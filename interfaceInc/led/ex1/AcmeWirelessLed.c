/*
 *  AcmeWirelessLed.c
 */

#include <stdio.h>
#include "AcmeWirelessLed.h"

static
void
sendMessage(AcmeWirelessLed *me, const char *oper)
{
    LedDriver *base = (LedDriver *)me;

    printf("%s - driver=%s, type=%d, ssid=%s, key=%s, channel=%d\r\n", oper, 
                                                     base->type, 
                                                     base->id,
                                                     me->ssid,
                                                     me->key,
                                                     me->channel);
}

static void 
turnOn(LedDriver *const me)
{
    AcmeWirelessLed *realMe = (AcmeWirelessLed *)me;

    sendMessage(realMe, "TurnOn");
}

static void 
turnOff(LedDriver *const me)
{
    AcmeWirelessLed *realMe = (AcmeWirelessLed *)me;

    sendMessage(realMe, "TurnOff");
}

void 
AcmeWirelessLed_init(AcmeWirelessLed *const me, const char *ssid, 
                                                const char *key, int channel)
{
    static const LedDriverVtbl vtbl = {turnOn, turnOff};

    LedDriver *base = &me->base;

    base->id = 1;
    base->type = "Acme wireless";
    base->offset = offsetof(AcmeWirelessLed, base);
    base->vptr = &vtbl;
    me->ssid = ssid;
    me->key = key;
    me->channel = channel;
}
