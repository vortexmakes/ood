/*
 * 	main.c
 */

#include <stdio.h>
#include <stdlib.h>

#include "X10Led.h"
#include "AcmeWirelessLed.h"

static X10Led *x10Led;
static AcmeWirelessLed *acmeWirelessLed;

int
main(void)
{
    x10Led = X10Led_ctor(X10_A, 8);

    acmeWirelessLed = AcmeWirelessLed_ctor("Home", "123abc", 4);
    if (acmeWirelessLed == (AcmeWirelessLed *)0)
    {
        printf("Can't create a AcmeWirelessLed object\r\n");
        exit(EXIT_FAILURE);
    }

	LedDriver_turnOn((LedDriver *)x10Led);
	LedDriver_turnOff((LedDriver *)x10Led);

	LedDriver_turnOn((LedDriver *)acmeWirelessLed);
	LedDriver_turnOff((LedDriver *)acmeWirelessLed);

    AcmeWirelessLed_dtor(acmeWirelessLed);
    X10Led_dtor(x10Led);

    getchar();
    return 0;
}
