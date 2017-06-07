/*
 * 	main.c
 */

#include <stdio.h>
#include "X10Led.h"
#include "AcmeWirelessLed.h"

void
main(void)
{
    LedDriver *ledA, *ledB;

    X10Led_init(x10LedA, X10_A, 8);
    X10Led_init(x10LedB, X10_B, 6);
    AcmeWirelessLed_init(acmeWirelessLed, "Home", "123abc", 4);

    ledA = (LedDriver *)x10LedA;
    ledB = (LedDriver *)acmeWirelessLed;

	LedDriver_turnOn(ledA);
	LedDriver_turnOff(ledA);

	LedDriver_turnOn(ledB);
	LedDriver_turnOff(ledB);

    ledA = (LedDriver *)x10LedB;
	LedDriver_turnOn(ledA);
	LedDriver_turnOff(ledA);

    getchar();
}
