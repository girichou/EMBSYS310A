/*
Assignment04 Q4 Program to find endienness of the micro

Author - Girish Choudankar
Date - 11/15/2021

*/

#define BIG_ENDIEN      1
#define LITTLE_ENDIEN   0


/*
var, a variable type int takes 32 bit to repesent a number.
say 0x12345678. If it is little endien then the LSB bits (0x78)
will be stores at lower address and so on. In case of big endiness the MSB bits
(0x12) are stored at lower memory address.
*/
int main()
{
   // stores 1 in the int type variable
    unsigned int var = 0x01;
    // set a flag to default BIG ENDIEN state
    int endien = 0;
    
    // now point to the first location uisng the char pointer to base address 
    // of a variable and then compare the first byte with 1 to ensure byte order     
    char *p = (char *)&var;
    int x = *p;
    
    endien = (x == 1) ? LITTLE_ENDIEN : BIG_ENDIEN;
               
    return 0;
}
