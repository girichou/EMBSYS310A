/*
Assignment 03 Q1

This program toggles LED1. It uses raw address defined in reference manual,
programmers manual and microcontroller datasheet

Author - Girish Choudankar
Date - 11/07/2021
*/

void delay(void);

int main()
{
    /* enable clock for port A */
    *((unsigned int*)0x4002104C) |= 0x01;
    /* set GPIOA to output mode */
    *((unsigned int*)0x48000000) &= 0xABFFF7FF;
    
    /* toggle LD2 on PA5 at visisble rate*/
    while(1)
    {
        *((unsigned int*)0x48000014) = 0x20;
        delay();
        *((unsigned int*)0x48000014) = 0x0;
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