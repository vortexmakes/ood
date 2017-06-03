/*
 *  LedDriver.c
 */

#include "LedDriver.h"

void 
LedDriver_turnOn(LedDriver *const me)
{
	if (me)
	{
		const LedDriverVtbl *vptr = me->vptr;
        size_t addr = (size_t)me;
        void *realMe = (void *)(addr - me->offset);
        (*vptr->turnOn)(realMe);
	}
}

void 
LedDriver_turnOff(LedDriver *const me)
{
	if (me)
	{
		const LedDriverVtbl *vptr = me->vptr;
        size_t addr = (size_t)me;
        void *realMe = (void *)(addr - me->offset);
        (*vptr->turnOff)(realMe);
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
