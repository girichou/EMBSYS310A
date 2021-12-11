/*
Assignment 07 Q1

This program toggles LED1 using CMSIS standard and SysTick timer

Author - Girish Choudankar
Date - 12/06/2021
*/

#include "delay.h"

extern uint32_t tick_counter;

void delay(uint32_t delayinmS)
{
    // check for desired delay
    tick_counter = delayinmS;
    
    // loop here until delay expires
    while(tick_counter);    
}