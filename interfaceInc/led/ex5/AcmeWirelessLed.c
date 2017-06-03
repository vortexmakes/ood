/*
 *  AcmeWirelessLed.c
 */

#include <stdio.h>
#include "AcmeWirelessLed.h"

struct AcmeWirelessLed
{
	LedDriver base;
    const char *ssid;
    const char *key;
    int channel;    
};

static AcmeWirelessLed pool[ACME_MAX_NUM_LEDS];

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

static
int
isValid(AcmeWirelessLed *const me)
{
    return (me && me->base.vptr);
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

AcmeWirelessLed *
AcmeWirelessLed_ctor(const char *ssid, const char *key, int channel)
{
    static const LedDriverVtbl vtbl = {turnOn, turnOff};
    LedDriver *base;
    AcmeWirelessLed *slot;

    for (slot = pool; slot < pool + ACME_MAX_NUM_LEDS; ++slot)
    {
        base = &slot->base;
        if (slot->base.vptr == (LedDriverVtbl *)0)
        {
            base->id = 1;
            base->type = "Acme wireless";
            base->vptr = &vtbl;
            slot->ssid = ssid;
            slot->key = key;
            slot->channel = channel;
            return slot;
        }
    }
    return (AcmeWirelessLed *)0;
}

void
AcmeWirelessLed_dtor(AcmeWirelessLed *const me)
{
    if (isValid(me))
        me->base.vptr = (LedDriverVtbl *)0;
}
