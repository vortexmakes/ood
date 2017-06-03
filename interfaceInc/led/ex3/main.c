/*
 * 	main.c
 */

#include <stdio.h>
#include "X10Led.h"
#include "AcmeWirelessLed.h"

static X10Led x10Led;
static AcmeWirelessLed acmeWirelessLed;

void
main(void)
{
    LedDriver *someObj, *otherObj;

    someObj = (LedDriver *)&x10Led;
    otherObj = (LedDriver *)&acmeWirelessLed;
    X10Led_init(&x10Led, X10_A, 8);
    AcmeWirelessLed_init(&acmeWirelessLed, "Home", "123abc", 4);

	LedDriver_turnOn(someObj);
	LedDriver_turnOff(someObj);

	LedDriver_turnOn(otherObj);
	LedDriver_turnOff(otherObj);

    getchar();
}
