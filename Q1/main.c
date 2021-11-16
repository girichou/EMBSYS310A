void delay(void);

int main()
{    
/*
    AHB2 peripheral clock enable register (RCC_AHB2ENR)
    Base Address    : 0x4002.1000
    Address offset  : 0x4C
    Reset Value     : 0x0000.0000
    */
    
    // For GPIOA enable bit 0 of AHB2ENR
    //bit_word_addr = bit_band_base + (byte_offset x 32) + (bit_number × 4)
    //*((unsigned int*)(0x42000000 + (0x2104C * 32) + (0 * 4))) = 0x01;
    *((unsigned int*)0x4002104C) |= 0x01;
    
    /*
    GPIO port mode register (GPIOA_MODER)
    Base Address    : 0x4800.0000
    Address offset  : 0x00
    Reset value     : 0xABFF.FFFF
    */
    *((unsigned int *)(0x48000000 + 0x00)) &= 0xABFFF7FF;
    
    
   while(1)
   {
       volatile unsigned int delayCounter = 0;        
        /*
        GPIO port output data register (GPIOA_ODR)
        Base Address    : 0x4800.0000
        Address Offset  : 0x14
        Reset Value     : 0x0000.0000
        */
        *((unsigned int *)(0x48000000 + 0x14)) = 0x20;
                
        while (delayCounter < 50000)
        {
            delayCounter++;
        }
        delayCounter = 0;
        *((unsigned int *)(0x48000000 + 0x14)) = 0x0;
                
        while (delayCounter < 50000)
        {
            delayCounter++;
        }
        
   }    
}
