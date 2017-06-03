/*
 *  X10Led.h
 */

#ifndef __X10LED_H__
#define __X10LED_H__

#include "LedDriver.h"

typedef enum X10_HouseCode 
{
    X10_A, X10_B, X10_C, X10_D, X10_E, X10_F,
    X10_G, X10_H, X10_I, X10_J, X10_K, X10_L,
    X10_M, X10_N, X10_O, X10_P 
} X10_HouseCode;

typedef struct X10Led X10Led;
struct X10Led
{
	LedDriver base;
    X10_HouseCode house;
    int unit;    
};

void X10Led_init(X10Led *const me, X10_HouseCode house, int unit);

#endif
