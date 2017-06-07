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
    LedDriver *ledA, *ledB;
    DoorLockDriver *foo;

    ledA = (LedDriver *)&x10Led;
    ledB = &acmeWirelessLed.ledDriver;
    foo = &acmeWirelessLed.lockDriver;

    X10Led_init(&x10Led, X10_A, 8);
    AcmeWirelessLed_init(&acmeWirelessLed, "Home", "123abc", 4);

	LedDriver_turnOn(ledA);
	LedDriver_turnOff(ledA);

	LedDriver_turnOn(ledB);
	LedDriver_turnOff(ledB);

	DoorLockDriver_lock(foo);
	DoorLockDriver_unlock(foo);

    getchar();
}
