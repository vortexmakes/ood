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

    X10Led_init(x10LedA, X10_A, 8);
    X10Led_init(x10LedB, X10_B, 6);
    AcmeWirelessLed_init(acmeWirelessLed, "Home", "123abc", 4);

    someObj = (LedDriver *)x10LedA;
    otherObj = (LedDriver *)acmeWirelessLed;

	LedDriver_turnOn(someObj);
	LedDriver_turnOff(someObj);

	LedDriver_turnOn(otherObj);
	LedDriver_turnOff(otherObj);

    someObj = (LedDriver *)x10LedB;
	LedDriver_turnOn(someObj);
	LedDriver_turnOff(someObj);

    getchar();
}
