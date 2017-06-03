/*
 *  LedDriver.c
 */

#include "LedDriver.h"

void 
LedDriver_turnOn(LedDriver *const me)
{
	if (me)
	{
#if 1
		const LedDriverVtbl *vptr = me->vptr;
        size_t addr = (size_t)me;
        void *realMe = (void *)(addr - me->offset);
        (*vptr->turnOn)(realMe);
#else
        (*me->vptr->turnOn)(me - me->offset);
#endif
	}
}

void 
LedDriver_turnOff(LedDriver *const me)
{
	if (me)
	{
#if 1
		const LedDriverVtbl *vptr = me->vptr;
        size_t addr = (size_t)me;
        void *realMe = (void *)(addr - me->offset);
        (*vptr->turnOff)(realMe);
#else
        (*me->vptr->turnOff)(me - me->offset);
#endif
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
