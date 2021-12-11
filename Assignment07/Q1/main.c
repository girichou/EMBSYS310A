/*
Assignment 07 Q1

This program toggles LED1 using CMSIS standard and SysTick timer

Author - Girish Choudankar
Date - 12/10/2021
*/

#include "stm32l475xx.h"
#include "stm32l4xx_it.h"
#include "delay.h"

#define SYS_CLOCK_HZ    4000000u   // Default clock after startup
                                // Section 3.11 in STM32L475 datasheet DS10969
#define CLOCK_DIVISOR   1000u
#define CLOCK_1mS       SYS_CLOCK_HZ/CLOCK_DIVISOR // clock for 1mS delay

void SysTick_Initialize(void);

uint32_t tick_counter;          // global variable to hold the time


int main()
{    
    // inittialize the system clock
    SysTick_Initialize();   
    
    // Enable clock to the GPIOA port
    RCC->AHB2ENR |= 0x01;
    
    // Set port A in output mode
    GPIOA->MODER &= 0xABFFF7FF;
    
    // keep looping forever
    while(1)
    {
        GPIOA->ODR ^= GPIO_ODR_OD5;     // toggle the LED2
        delay(1000);                    // delay for mS
    }
}

/*
    A function to inititalize the system clock afor 1mS interrupt
*/
void SysTick_Initialize(void)
{
    SysTick->LOAD = CLOCK_1mS - 1;       // 0xE000E014 - Counts down to 0.
    SysTick->VAL = 0x0;                     // 0xE000E018 - Clears initial value
    SysTick->CTRL = 0x7;                    // 0xE000E010 - Enable interrupts    
}

/*
    SysClk time routine to toggle LED at predefined time
    It increments a 1mS timer until desired time delay is reached defined by
    delayInMilliSeconds and then toggles the LED2 and resets the timer
*/

void SysTick_Handler(void)
{
    tick_counter--;         // count down the tick timer
    
}

/*
void SysTick_Handler(void)
{
    tick_counter_1ms++;
    
    // check for desired delay
    if(tick_counter_1ms == delayInMilliseconds)        
    {
        tick_counter_1ms = 0;           // reset the timer tick
        GPIOA->ODR ^= GPIO_ODR_OD5;     // toggle the LED2
    }
}
*/