/*
 *  AcmeWirelessLed.c
 */

#include <stdio.h>
#include "AcmeWirelessLed.h"

typedef enum OPER
{
    TURNON, TURNOFF, LOCK, UNLOCK
} OPER;

static const char *operStr[] =
{
    "TurnOn", "turnOff", "Lock", "Unlock"
};

static void
sendMessage(AcmeWirelessLed *me, OPER oper)
{
    LedDriver *ledDriver = &me->ledDriver;
    DoorLockDriver *lockDriver = &me->lockDriver;

    if (oper == TURNON || oper == TURNOFF)
        printf("%s - driver=%s, type=%d, ssid=%s, key=%s, channel=%d\r\n", 
                    operStr[oper],
                    ledDriver->type, 
                    ledDriver->id,
                    me->ssid,
                    me->key,
                    me->channel);
    else
        printf("%s - driver=%s, type=%d, ssid=%s, key=%s, channel=%d\r\n", 
                    operStr[oper],
                    lockDriver->type, 
                    lockDriver->id,
                    me->ssid,
                    me->key,
                    me->channel);
}

static void 
turnOn(LedDriver *const me)
{
    AcmeWirelessLed *realMe = (AcmeWirelessLed *)me;

    sendMessage(realMe, TURNON);
}

static void 
turnOff(LedDriver *const me)
{
    AcmeWirelessLed *realMe = (AcmeWirelessLed *)me;

    sendMessage(realMe, TURNOFF);
}

static void 
lock(DoorLockDriver *const me)
{
    AcmeWirelessLed *realMe = (AcmeWirelessLed *)me;

    sendMessage(realMe, LOCK);
}

static void 
unlock(DoorLockDriver *const me)
{
    AcmeWirelessLed *realMe = (AcmeWirelessLed *)me;

    sendMessage(realMe, UNLOCK);
}

void 
AcmeWirelessLed_init(AcmeWirelessLed *const me, const char *ssid, 
                                                const char *key, int channel)
{
    static const LedDriverVtbl ledDriverVtbl = {turnOn, turnOff};
    static const DoorLockDriverVtbl doorLockDriverVtbl = {lock, unlock};
    LedDriver *ledDriver = &me->ledDriver;
    DoorLockDriver *lockDriver = &me->lockDriver;

    ledDriver->id = 1;
    ledDriver->type = "Acme led wireless";
    ledDriver->offset = offsetof(AcmeWirelessLed, ledDriver);
    ledDriver->vptr = &ledDriverVtbl;

    lockDriver->id = 2;
    lockDriver->type = "Acme door lock wireless";
    lockDriver->offset = offsetof(AcmeWirelessLed, lockDriver);
    lockDriver->vptr = &doorLockDriverVtbl;

    me->ssid = ssid;
    me->key = key;
    me->channel = channel;
}
