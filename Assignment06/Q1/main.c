/*
Assignment 06 Q1

This program toggles LED1 using CMSIS standard

Author - Girish Choudankar
Date - 11/11/2021
*/

#include "stm32l475xx.h"

// delay function declaration
void delay(void);

int main()
{
    // Enable clock to the GPIOA port
    RCC->AHB2ENR |= 0x01;
    
    // Set port A in output mode
    GPIOA->MODER &= 0xABFFF7FF;
    
    // Toggle LED1 at visible rate
    while(1)
    {          
        // Turn on LED1for a while
        GPIOA->ODR = 0x20;
        delay();
        
        // Turn off LED1 for a while
        GPIOA->ODR = 0x0;
        delay();
    }    
}

/*
This function introduces delay of finite time by counting up to 50000
*/
void delay(void)
{
    volatile unsigned int counter = 0;
    while (counter < 50000)        
    {
        counter++;
    }
}