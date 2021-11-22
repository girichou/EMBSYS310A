    EXTERN PrintString  // PrintString is defined outside this file.
    EXTERN myCstr       // myCstr defined outside this file.
    EXTERN divCstr
    
    PUBLIC divAsm       // Exports symbols to other modules
                        // Making sqrAsm available to other modules.
                        
    SECTION .text:CODE:REORDER:NOROOT(2)
    
    THUMB 

/*******************************************************************************
Function Name   : divAsm
Description     : Calls C code to print dividend; 
                  divides input number by 2t
C Prototype     : int sqrAsm(val)
                : Where val is the value to divide by 2
Parameters      : R0: integer val
Return value    : R0
*******************************************************************************/  
  
divAsm
    // Following code will print the string on the serial terminal
    PUSH {R0,LR}        // save the input argument and return address
    LDR R0,=divCstr     // load (global) address of string into R0
    LDR R0,[R0]         // load address of string into R0
    BL  PrintString     // call PrintString to print the string
    
    // Following code will devide the content of R0 by 2 using right shifting
    POP {R0,LR}         // Restore R0 and LR
    MOV R1, R0          // R1 = R0
    ASR R0, R1, #1      // R0 = R1/2 (ASR -> 2^n)
    BX LR               // return (with function result in R0)

    END