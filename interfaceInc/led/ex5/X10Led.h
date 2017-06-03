/*
 *  X10Led.h
 */

#ifndef __X10LED_H__
#define __X10LED_H__

#include "LedDriver.h"

#define X10_MAX_NUM_LEDS        8

typedef enum X10_HouseCode 
{
    X10_A, X10_B, X10_C, X10_D, X10_E, X10_F,
    X10_G, X10_H, X10_I, X10_J, X10_K, X10_L,
    X10_M, X10_N, X10_O, X10_P 
} X10_HouseCode;

typedef struct X10Led X10Led;

X10Led *X10Led_ctor(X10_HouseCode house, int unit);
void X10Led_dtor(X10Led *const me);

#endif
