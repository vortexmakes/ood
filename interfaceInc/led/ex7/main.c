/*
 * 	main.c
 */

#include <stdio.h>
#include "X10Led.h"
#include "AcmeWirelessLed.h"

static X10Led x10LedA, x10LedB;
static AcmeWirelessLed acmeWirelessLedA, acmeWirelessLedB;

void
main(void)
{
    LedDriver *ledA, *ledB;

    X10Led_init(&x10LedA, X10_A, 8);
    X10Led_init(&x10LedB, X10_B, 4);

    ledA = (LedDriver *)&x10LedA;
    ledB = (LedDriver *)&x10LedB;

	LedDriver_turnOn(ledA);
	LedDriver_turnOn(ledB);

    AcmeWirelessLed_init(&acmeWirelessLedA, "Home", "123abc", 4);
    AcmeWirelessLed_init(&acmeWirelessLedB, "Home", "5231aa", 2);

    ledA = (LedDriver *)&acmeWirelessLedA;
    ledB = (LedDriver *)&acmeWirelessLedB;

	LedDriver_turnOn(ledA);
	LedDriver_turnOn(ledB);

    getchar();
}
