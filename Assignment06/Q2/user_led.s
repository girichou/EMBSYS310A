/*******************************************************************************
Assignemnt 06 Q2
File name       : user_led.s
Description     : Assembly language function for controlling the user LED
Author - Girish Choudankar
Date - 11/29/2021
*******************************************************************************/   

    EXTERN delay                    // delay() is defined outside this file

    PUBLIC control_user_led1        // Exports symbols to other modules

// Code is split into logical sections using the SECTION directive.
// Source: http://ftp.iar.se/WWWfiles/arm/webic/doc/EWARM_AssemblerReference.ENU.pdf
// SECTION  section  :type [:flag] [(align)]
//      The data section is used for declaring initialized data or constants. This data does not change at runtime
//      The bss section is used for declaring variables. The syntax for declaring bss section is -
//      The text section is used for keeping the actual code.

// CODE: Interprets subsequent instructions as Arm or Thumb instructions, 
// depending on the setting of related assembler options.

// NOREORDER (the default mode) starts a new fragment in the section
// with the given name, or a new section if no such section exists.
// REORDER starts a new section with the given name.

// NOROOT means that the section fragment is discarded by the linker if
// no symbols in this section fragment are referred to. Normally, all
// section fragments except startup code and interrupt vectors should
// set this flag.

// The (2) is for the (align)
// The power of two to which the address should be aligned.
// The permitted range is 0 to 8. 
// Code aligned at 4 Bytes.

    SECTION .text:CODE:REORDER:NOROOT(2)
    
    THUMB               // Indicates THUMB code is used
                        // Subsequent instructions are assembled as THUMB instructions
    
/*******************************************************************************
Function Name   : control_user_led1
Description     : - Uses Peripheral registers at base 0x4800.0000
                    to set GPIOA Output Data Register.
                  - Calls another assembly function delay to insert
                    delay loop

C Prototype     : void control_user_led(uint8_t state, uint32_t duration)
                : Where state indicates if LED should be on or off.
Parameters      : R0: uint8_t state
                : R1: uint32_t duration
Return value    : None
*******************************************************************************/  

GPIOA_BASE  EQU 0x48000000
GPIOA_ODR   EQU 0x14
GPIOA_BIT_5 EQU 0x20

control_user_led1
    // <TODO> Implement function in assembly
            PUSH {R3, R4, LR}           // push register to be used on stack
            MOV R3, #GPIOA_BASE         // Store GPIOA base address to R3
            ADD R3, R3, #GPIOA_ODR      // Make port A output
    // if(flag == LED_ON)
            CMP R0, #1                  // Compare if LED_ON  
            BNE.N   LD_OFF              // Branch if copmarison is not equal to
            MOV R4, #GPIOA_BIT_5        // Move 1 to 5th bit to turn LD2 on
            STR R4, [R3]                // at the address pointer by R3
            B.N     CALL_DELAY          // if 
    // else flag == LED_OFF 
LD_OFF      MOV R4, #0                  // move 0 to 5th bit to turn LD2 off
            STR R4, [R3]                // at the address pointer by R3
            
CALL_DELAY  BL delay                    // jump to delay routine 
            POP {R3, R4, LR}            // retrieve registers from stack            
            BX LR                       // return back to calee
            
    END
