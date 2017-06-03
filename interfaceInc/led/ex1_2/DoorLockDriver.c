/*
 *  DoorLockDriver.c
 */

#include "DoorLockDriver.h"

void 
DoorLockDriver_lock(DoorLockDriver *const me)
{
	if (me)
	{
		const DoorLockDriverVtbl *vptr = me->vptr;
        size_t addr = (size_t)me;
        void *realMe = (void *)(addr - me->offset);
        (*vptr->lock)(realMe);
	}
}

void 
DoorLockDriver_unlock(DoorLockDriver *const me)
{
	if (me)
	{
		const DoorLockDriverVtbl *vptr = me->vptr;
        size_t addr = (size_t)me;
        void *realMe = (void *)(addr - me->offset);
        (*vptr->unlock)(realMe);
	}
}

const char *
DoorLockDriver_getType(DoorLockDriver *const me)
{
    return me->type;
}

int 
DoorLockDriver_getId(DoorLockDriver *const me)
{
    return me->id;
}
