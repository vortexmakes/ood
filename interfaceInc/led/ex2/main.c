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
    X10Led_init(&x10Led, X10_A, 8);
    AcmeWirelessLed_init(&acmeWirelessLed, "Home", "123abc", 4);

	LedDriver_turnOn(&x10Led);
	LedDriver_turnOff(&x10Led);

	LedDriver_turnOn(&acmeWirelessLed);
	LedDriver_turnOff(&acmeWirelessLed);

    getchar();
}
