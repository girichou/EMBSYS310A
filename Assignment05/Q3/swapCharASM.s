/*
    Assignment05 Q3
    Swap the chars
    Author - Girish Choudankar
    Date - 11/22/2021
*/

    EXTERN var1         // var1 defined outside this file
    EXTERN var2         // var2 defined outside this file
    
    PUBLIC swapCharASM  // Exports symbols to other modules
                        // Making swapCharASM available to other modules.
                        
    SECTION .text:CODE:REORDER:NOROOT(2)
    
    THUMB 

/*******************************************************************************
Function Name   : swapCharASM
Description     : swap 2 chars at memory location 
                  compare both the chars and return 0 if similar else 1
C Prototype     : int swapCharASM(var1, var2)
                : Where var1 & var2 are chars to be swapped
Parameters      : var1, var2 character value
Return value    : R0, comparsion result
*******************************************************************************/  
  
swapCharASM

            // read values of var1 and var2
            PUSH    {LR}            // push return value to stack
            LDR.N   R0, =var1       // load the address of var1 in R0
            LDRB    R1, [R0]        // load byte value of R0 in register R1
            LDR.N   R0, =var2       // load the address of var1 in R0
            LDRB    R2, [R0]        // load byte value of R0 in register R2
            
            // swap values of var1 and var2 locally
            MOV     R3, R1          // store R1 in temp register R3
            MOV     R1, R2          // copy R2 to R1 register
            MOV     R2, R3          // restore original value of R1 to R2
            
            // store back the swapped values to memory
            LDR.N   R0, =var1       // get address of var1
            STR     R1, [R0]        // store the updated value to var1
            LDR.N   R0, =var2       // get address of var2
            STR     R2, [R0]        // store the updated value to var2
            
            // compare chars for equality
            CMP     R1, R2          // comare if R1 and R2 are same
            BNE.N   SET_FLAG        // if dissimilar then jump to set flag
            MOVS    R0, #0          // else set the flag to 0
            B.N     RESET_FLAG      // jump to continue
SET_FLAG    MOVS    R0, #1          // set return flag to 1    
RESET_FLAG  POP     {LR}            // retrieve return value from stack

            BX      LR              // jump back to callee
            END