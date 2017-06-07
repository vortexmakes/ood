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
    const char *type;
    int id;
};

struct LedDriverVtbl
{
	void (*turnOn)(LedDriver *const me);
	void (*turnOff)(LedDriver *const me);
};

void LedDriver_turnOn(LedDriver *const me);
void LedDriver_turnOff(LedDriver *const me);
const char *LedDriver_getType(LedDriver *const me);
int LedDriver_getId(LedDriver *const me);
void LedDriver_setInterface(const LedDriverVtbl *interface);

#endif
