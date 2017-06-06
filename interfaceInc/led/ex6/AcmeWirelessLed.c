/*
 *  AcmeWirelessLed.c
 */

#include <stdio.h>
#include "AcmeWirelessLed.h"

typedef struct AcmeWirelessLed AcmeWirelessLed;
struct AcmeWirelessLed
{
	LedDriver base;
    const char *ssid;
    const char *key;
    int channel;    
};

static AcmeWirelessLed acmeWirelessLedObj;
LedDriver *acmeWirelessLed = (LedDriver *)&acmeWirelessLedObj;

static void
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
AcmeWirelessLed_init(const char *ssid, 
                     const char *key, int channel)
{
    static const LedDriverVtbl vtbl = {turnOn, turnOff};

    LedDriver *base = &acmeWirelessLedObj.base;

    base->id = 1;
    base->type = "Acme wireless";
    base->offset = offsetof(AcmeWirelessLed, base);
    base->vptr = &vtbl;
    acmeWirelessLedObj.ssid = ssid;
    acmeWirelessLedObj.key = key;
    acmeWirelessLedObj.channel = channel;
}
