/*
 *  LedDriver.c
 */

#include "LedDriver.h"

void 
LedDriver_turnOn(LedDriver *const me)
{
	if (me)
	{
        (*me->vptr->turnOn)(me);
	}
}

void 
LedDriver_turnOff(LedDriver *const me)
{
	if (me)
	{
        (*me->vptr->turnOff)(me);
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
