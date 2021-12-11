/*
Assignment 07 Q1

This program toggles LED1 using CMSIS standard and SysTick timer

Author - Girish Choudankar
Date - 12/06/2021
*/

#include <stdint.h>
#include "stm32l4xx_it.h"
#include "stm32l475xx.h"

#pragma section="CSTACK"                        // stack size
#pragma weak SysTick_Handler = Unused_Handler   

void __iar_program_start(void);                 // reset vector
void Unused_Handler(void);

// --Vector_table definition 
uint32_t const __vector_table[] @ ".intvec" = {
    (uint32_t)__section_end("CSTACK"),
    (uint32_t)&__iar_program_start,
    (uint32_t)&NMI_Handler,
    (uint32_t)&HardFault_Handler,
    (uint32_t)&MemManage_Handler,
    (uint32_t)&BusFault_Handler,
    (uint32_t)&UsageFault_Handler,
    0u,      // Reserved
    0u,      // Reserved
    0u,      // Reserved
    0u,      // Reserved
    (uint32_t)&SVC_Handler,
    (uint32_t)&DebugMon_Handler,
    0u,      // Reserved
    (uint32_t)&PendSV_Handler,
    (uint32_t)&SysTick_Handler    
};

void Unused_Handler(void)
{
    while(1);
}

void NMI_Handler(void)
{
    Unused_Handler();
}

//#pragma NMI_Handler = Unused_Handler
#pragma weak HardFault_Handler = Unused_Handler
#pragma weak MemManage_Handler = Unused_Handler
#pragma weak BusFault_Handler = Unused_Handler
#pragma weak UsageFault_Handler = Unused_Handler
#pragma weak SVC_Handler = Unused_Handler
#pragma weak DebugMon_Handler = Unused_Handler
#pragma weak PendSV_Handler = Unused_Handler
#pragma weak SysTick_Handler = Unused_Handler