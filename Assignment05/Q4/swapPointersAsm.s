/*
    Assignment05 Q4
    Swap pointers to chars
    Author - Girish Choudankar
    Date - 11/22/2021
*/
   
    PUBLIC swapPointersAsm  // Exports symbols to other modules
                        // Making swapPointersAsm available to other modules.
                        
    SECTION .text:CODE:REORDER:NOROOT(2)
    
    THUMB 

/*******************************************************************************
Function Name   : swapPointersAsm
Description     : swap 2 pointers to char                    
C Prototype     : int swapPointersAsm(**var1, **var2)
                : Where **var1 & **var2 are pointers to chars to be swapped
Parameters      : var1, var2 character value
Return value    : 
*******************************************************************************/  
  
swapPointersAsm

            // read values of pointers to var1 and var2
            PUSH    {R3, R4, LR}    // push return value to stack and in use registers
            LDR     R3, [R0]        // get the address of var1 pointer
            LDR     R4, [R1]        // get the address of var2 pointer
            
            // swap values of var1 and var2 locally
            MOV     R2, R3          // store R1 in temp register R3
            MOV     R3, R4          // copy R2 to R1 register
            MOV     R4, R2          // restore original value of R1 to R2
            
            // store back the swapped values to memory
            STR     R3, [R0]        // update the pointer to var1
            STR     R4, [R1]        // update the pointer to var2
            
            POP     {R3, R4, LR}    // retrieve return value from stack

            BX      LR              // jump back to callee
            END