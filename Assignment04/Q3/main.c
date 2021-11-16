/*
   Assignment  04 Question 3 Implement stack for int data type
   provide unit test
   Author - Girish Choudankar
   Date: 11/16/2021 
*/
#include<assert.h>
#include "stack.h"

int main()
{
    int result1;
    int result2;
    int testData;
       
/*
TEST1: retrieve item from empty stack
*/
    //Arrange:
    result1 = 0x11;
    testData = 0xAA;
    stack_init();
    
    //Act:
    result1 = stack_pop(&testData);
    
    // Asert:
    assert(1 == result1);
    assert(0xAA == testData);
    
/*
TEST2: retrieve item from stack
*/
    
    //Arrange:
    result1 = 0x11;
    testData = 0xAA;
    stack_init();
    
    //Act:
    result1 = stack_push(0xAA);
    result2 = stack_pop(&testData);
    
    //Assert:
    assert(0 == result1);
    assert(0 == result2);
    assert(0xAA == testData);
    
/*
TEST3: Fill stack and then retrieve all
*/
    //Arrange:
    result1 = 0x11;
    testData = 0xAA;
    stack_init();
    
     //Act:
    stack_push(0xAA);
    stack_push(0xBB);
    stack_push(0xCC);
    
    //Assert:
    assert(0 == stack_pop(&testData));
    assert(0xCC == testData);
    
    assert(0 == stack_pop(&testData));
    assert(0xBB == testData);
    
    assert(0 == stack_pop(&testData));
    assert(0xAA == testData);
    
/*
TEST4: Fill more data to stack and it should fail  
*/
    //Arrange:
    result1 = 0x11;
    testData = 0xAA;
    stack_init();
    
     //Act:
    stack_push(0xAA);
    stack_push(0xBB);
    stack_push(0xCC);
    
    //Assert:
    assert(1 == stack_push(0xDD));
   
    assert(0 == stack_pop(&testData));
    assert(0xCC == testData);
    
    assert(0 == stack_pop(&testData));
    assert(0xBB == testData);
    
    assert(0 == stack_pop(&testData));
    assert(0xAA == testData);
   
/*
TEST5: Fill stack, pop one then fill one more 
*/
    //Arrange:
    result1 = 0x11;
    testData = 0xAA;
    stack_init();
    
    //Act:
    stack_push(0xAA);
    stack_push(0xBB);
    stack_push(0xCC);
    
    assert(0 == stack_pop(&testData));
    assert(0xCC == testData);
    
    stack_push(0xDD);
    
    assert(0 == stack_pop(&testData));
    assert(0xDD == testData);
    
    assert(0 == stack_pop(&testData));
    assert(0xBB == testData);
    
    assert(0 == stack_pop(&testData));
    assert(0xAA == testData);
    
/*
Test6: Fill stack and retrieve all. Do it twice.
*/
     //Arrange:
    result1 = 0x11;
    testData = 0xAA;
    stack_init();
    
    //Act:
    stack_push(0xAA);
    stack_push(0xBB);
    stack_push(0xCC);
    
    assert(0 == stack_pop(&testData));
    assert(0xCC == testData);
    
    assert(0 == stack_pop(&testData));
    assert(0xBB == testData);
    
    assert(0 == stack_pop(&testData));
    assert(0xAA == testData);
    
    assert(0 == stack_push(0xDD));
    assert(0 == stack_push(0xEE));
    assert(0 == stack_push(0xFF));
    
    assert(1 == stack_push(0x55));
    
    assert(0 == stack_pop(&testData));
    assert(0xFF == testData);
    
    assert(0 == stack_pop(&testData));
    assert(0xEE == testData);
    
    assert(0 == stack_pop(&testData));
    assert(0xDD == testData);
    
    return 0;
}
