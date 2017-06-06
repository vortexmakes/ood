/*
 * 	main.c
 */

#include <stdio.h>
#include "X10Led.h"
#include "AcmeWirelessLed.h"

void
main(void)
{
    LedDriver *someObj, *otherObj;

    X10Led_init(X10_A, 8);
    AcmeWirelessLed_init("Home", "123abc", 4);

    someObj = x10Led;
    otherObj = acmeWirelessLed;

	LedDriver_turnOn(someObj);
	LedDriver_turnOff(someObj);

	LedDriver_turnOn(otherObj);
	LedDriver_turnOff(otherObj);

    getchar();
}
