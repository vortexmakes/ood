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

    X10Led_init(X10_A, 8);
    AcmeWirelessLed_init("Home", "123abc", 4);

    ledA = x10Led;
    ledB = acmeWirelessLed;

	LedDriver_turnOn(ledA);
	LedDriver_turnOff(ledA);

	LedDriver_turnOn(ledB);
	LedDriver_turnOff(ledB);

    getchar();
}
