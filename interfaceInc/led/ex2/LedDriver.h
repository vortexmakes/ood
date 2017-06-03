/*
 *  LedDriver.h
 */

#ifndef __LEDDRIVER_H__
#define __LEDDRIVER_H__

#include <stddef.h>

typedef struct LedDriverVtbl LedDriverVtbl;
typedef struct LedDriver LedDriver;

struct LedDriver
{
    size_t offset;
	const LedDriverVtbl *vptr;
    const char *type;
    int id;
};

struct LedDriverVtbl
{
	void (*turnOn)(void *const me);
	void (*turnOff)(void *const me);
};

void LedDriver_turnOn(void *const me);
void LedDriver_turnOff(void *const me);
const char *LedDriver_getType(LedDriver *const me);
int LedDriver_getId(LedDriver *const me);

#endif
