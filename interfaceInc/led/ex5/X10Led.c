/*
 *  X10Led.h
 */

#include <stdio.h>
#include "X10Led.h"

struct X10Led
{
	LedDriver base;
    X10_HouseCode house;
    int unit;    
};

static X10Led pool[X10_MAX_NUM_LEDS];
static const char *houseCode[] =
{
    "X10_A", "X10_B", "X10_C", "X10_D", "X10_E", "X10_F",
    "X10_G", "X10_H", "X10_I", "X10_J", "X10_K", "X10_L",
    "X10_M", "X10_N", "X10_O", "X10_P"
};

static void
sendMessage(X10Led *me, const char *oper)
{
    LedDriver *base = (LedDriver *)me;
    printf("%s - driver=%s, type=%d, house=%s, unit=%d\r\n", oper, 
                                                     base->type, 
                                                     base->id,
                                                     houseCode[me->house],
                                                     me->unit);
}

static int
isValid(X10Led *const me)
{
    return (me && me->base.vptr);
}

static void 
turnOn(LedDriver *const me)
{
    X10Led *realMe = (X10Led *)me;

    sendMessage(realMe, "TurnOn");
}

static void 
turnOff(LedDriver *const me)
{
    X10Led *realMe = (X10Led *)me;

    sendMessage(realMe, "TurnOff");
}

X10Led *
X10Led_ctor(X10_HouseCode house, int unit)
{
    static const LedDriverVtbl vtbl = {turnOn, turnOff};
    LedDriver *base;
    X10Led *slot;

    for (slot = pool; slot < pool + X10_MAX_NUM_LEDS; ++slot)
    {
        base = &slot->base;
        if (slot->base.vptr == (LedDriverVtbl *)0)
        {
            base->id = 0;
            base->type = "X10";
            base->vptr = &vtbl;
            slot->house = house;
            slot->unit = unit;
            return slot;
        }
    }
    return (X10Led *)0;

}

void
X10Led_dtor(X10Led *const me)
{
    if (isValid(me))
        me->base.vptr = (LedDriverVtbl *)0;
}
