/*
   Assignment  04 Question 3 Implement stack for int data type
   provide unit test
   Author - Girish Choudankar
   Date: 11/16/2021 
*/

#include "stack.h"

#define STACK_SIZE 3

// stack storage
int StackBuf[STACK_SIZE];

// pointers to push and pop data from the stack
int *stackPtr;

// inittialize the stack with all content to 0
void stack_init(void)
{          
    // Inititalize stack buffer with ASCII 0
    for(int index = 0; index < STACK_SIZE; index++)
    {
        StackBuf[index] = '\0';
    }
    stackPtr = &StackBuf[0];
}

/* add data to stack
   retun 1 if stack is full
   return -1 for error
*/
int stack_push(int data)
{
    if (stackPtr > &StackBuf[STACK_SIZE - 1])
    {
        return 1;
    }
    else
    {
        *stackPtr++ = data;
    }
    return 0;
}

/* pop data from stack
   retun 1 if stack is full
   return -1 for error
*/
int stack_pop(int *data)
{   
    // if stack pointer is below lowest element return error
    if(stackPtr < &StackBuf[0])
    {
        return -1;
    }
    // if stack pointer is at the lowest element then do not decrement
    else if(stackPtr == &StackBuf[0])
    {
        stackPtr = &StackBuf[0];
        return 1;
    }
    else
    {
        stackPtr--;
    }    
    *data = *stackPtr;
        
    return 0;
}