/*
 *  LedDriver.c
 */

#include "LedDriver.h"

void 
LedDriver_turnOn(void *const me)
{
	if (me)
	{
		const LedDriverVtbl *vptr = ((LedDriver *)me)->vptr;
        size_t addr = (size_t)me;
        void *realMe = (void *)(addr - ((LedDriver *)me)->offset);
        (*vptr->turnOn)(realMe);
	}
}

void 
LedDriver_turnOff(void *const me)
{
	if (me)
	{
		const LedDriverVtbl *vptr = ((LedDriver *)me)->vptr;
        size_t addr = (size_t)me;
        void *realMe = (void *)(addr - ((LedDriver *)me)->offset);
        (*vptr->turnOn)(realMe);
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
