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

    X10Led_init(&x10Led, X10_A, 8);
    AcmeWirelessLed_init(&acmeWirelessLed, "Home", "123abc", 4);

    someObj = &x10Led.base;           /* someObj = (X10Led *)&x10Led; */
    otherObj = &acmeWirelessLed.base; /* otherObj = */
                                      /* (AcmeWirelessLed *)&acmeWirelessLed; */

	LedDriver_turnOn(someObj);
	LedDriver_turnOff(someObj);

	LedDriver_turnOn(otherObj);
	LedDriver_turnOff(otherObj);

    someObj = (LedDriver *)&acmeWirelessLed;
	LedDriver_turnOn(someObj);
	LedDriver_turnOff(someObj);

    getchar();
}
