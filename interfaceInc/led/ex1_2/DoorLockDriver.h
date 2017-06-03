/*
 *  DoorLockDriver.h
 */

#ifndef __DOORLOCKDRIVER_H__
#define __DOORLOCKDRIVER_H__

#include <stddef.h>

typedef struct DoorLockDriverVtbl DoorLockDriverVtbl;
typedef struct DoorLockDriver DoorLockDriver;

struct DoorLockDriver
{
    size_t offset;
	const DoorLockDriverVtbl *vptr;
    const char *type;
    int id;
};

struct DoorLockDriverVtbl
{
	void (*lock)(DoorLockDriver *const me);
	void (*unlock)(DoorLockDriver *const me);
};

void DoorLockDriver_lock(DoorLockDriver *const me);
void DoorLockDriver_unlock(DoorLockDriver *const me);
const char *DoorLockDriver_getType(DoorLockDriver *const me);
int DoorLockDriver_getId(DoorLockDriver *const me);

#endif
