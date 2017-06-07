/*
 *  LedDriver.c
 */

#include "LedDriver.h"

static const LedDriverVtbl *vptr = (LedDriverVtbl *)0;

void 
LedDriver_turnOn(LedDriver *const me)
{
	if (me)
	{
        (*vptr->turnOn)(me);
	}
}

void 
LedDriver_turnOff(LedDriver *const me)
{
	if (me)
	{
        (*vptr->turnOff)(me);
	}
}

const char *
LedDriver_getType(LedDriver *const me)
{
    return me->type;
}

int 
LedDriver_getId(LedDriver *const me)
{
    return me->id;
}

void 
LedDriver_setInterface(const LedDriverVtbl *interface)
{
    vptr = interface;
}
