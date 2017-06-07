/*
 * 	main.c
 */

#include <stdio.h>
#include <stdlib.h>

#include "X10Led.h"
#include "AcmeWirelessLed.h"

static X10Led *ledA;
static AcmeWirelessLed *ledB;

int
main(void)
{
    ledA = X10Led_ctor(X10_A, 8);

    ledB = AcmeWirelessLed_ctor("Home", "123abc", 4);
    if (ledB == (AcmeWirelessLed *)0)
    {
        printf("Can't create a AcmeWirelessLed object\r\n");
        exit(EXIT_FAILURE);
    }

	LedDriver_turnOn((LedDriver *)ledA);
	LedDriver_turnOff((LedDriver *)ledA);

	LedDriver_turnOn((LedDriver *)ledB);
	LedDriver_turnOff((LedDriver *)ledB);

    AcmeWirelessLed_dtor(ledB);
    X10Led_dtor(ledA);

    getchar();
    return 0;
}
