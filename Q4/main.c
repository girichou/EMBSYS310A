/*
 Assignment03 Q.4 
 Program to translate text to Morse code

 Author - Girish Choudankar
 Date - 11/07/2021
*/


/*
Refe page 74, section 2.1.6 AHB/APB bridges of RM0351
after each reset , all peripheral clocks are disabled
Before using a peripheral enable its clock in the RCC_AHB1ENR or RCC_APBxENR
RCC_AHB2ENR (for GPIO port A)
Adddress offset - 0x4C
reset value - 0x0000 0000
Bits    31:19 reserved
        Bit 18 RNGEN Random Num Generator clk en
        Bit 17 HASHEN Hash en
        Bit 16 AESEN AES accelerator clk en
        Bit 15 reserved
        Bit 14 DCMIEN DCMI clk en
        Bit 13 ADCEN  ADC clk en
        Bit 12 OTGGSEN OTG Full speed clk en
Bits    11:9 reserved
        Bit 8 GPIOIEN IO port 1 clk en
        Bit 7 GPIOHEN IO port H clk en
        Bit 6 GPIOHEN IO port G clk en
        Bit 5 GPIOHEN IO port F clk en
        Bit 4 GPIOHEN IO port E clk en
        Bit 3 GPIOHEN IO port D clk en
        Bit 2 GPIOHEN IO port C clk en
        Bit 1 GPIOHEN IO port B clk en
        Bit 0 GPIOHEN IO port A clk en
*/
#define RCC_BASE        0x40021000 
#define RCC_AHB2ENR     (*((unsigned int *)(RCC_BASE + 0x4C)))

// LED1 is available on port pin PA5 at pin 30
#define GPIOA_BASE      0x48000000

/*
Select IO mode  
Address offset - 0x00
reset value - 0xABFF FFFF
Bits 31:0 Mode[15:0][1:0] - input[00], output[01], AF[10],  analog[11]
*/
#define GPIOA_MODER     (*((unsigned int *)(GPIOA_BASE + 0x00)))

/*
Data to be output
Address offset - 0x14
reset value - 0x0000 0000
Bits 31:16 reserved
Bits 15:0 OD[15:0] Port output data io pin 
*/
#define GPIOA_ODR       (*((unsigned int *)(GPIOA_BASE + 0x14)))

#define LD1_ON     (0x00000020)
#define LD1_OFF      (0x0)

void dot(void);
void delay(void);
void dash(void);

int main()
{
    // enable clock for port A by setting bit 0
    RCC_AHB2ENR |= 0x00000001;
    
    // set PA5 to output by writing b01 at bits 10 and 11 
    GPIOA_MODER &= 0xFFFFF7FF;                                          
      
    char name[] = "GIRISH";
    //char *charp_name = name;
    
    // set LD1 ON and then toogle after delay indefinitely
    while(1)
    {
      for(char *charp_name = name; *charp_name != '\0'; charp_name++)
      {
          switch(*charp_name)
          {
              case 'A':         // .-
              {
                  dot();
                  dash();
                  break;
              }
              case 'B':         // -...
              {
                  dash();
                  dot();
                  dot();
                  dot();
                  break;
              }
              case 'C':         // -.-.
              {
                dash();
                dot();
                dash();
                dot();
                break;
              }
              case 'D':         // -..
              { 
                dash();
                dot();
                dot();
                break;
              }
              case 'E':         // .
              {
                dot();
                break;
              }
              case 'F':         // ..-.
              {
                dot();
                dot();
                dash();
                dot();
                break;
              }
              case 'G':         // --.
              {
                dash();
                dash();
                dot();
                break;
              }
              case 'H':         // ....
              {
                dot();
                dot();
                dot();
                dot();
                break;
              }
              case 'I':         //..
              {
                dot();
                dot();
                break;
              }
              case 'J':         // .---
              {
                dot();
                dash();
                dash();
                dash();
                break;
              }
              case 'K':         // -.-
              {
                dash();
                dot();
                dash();
                break;
              }
              case 'L':         // .-..
              {
                dot();
                dash();
                dot();
                dot();
                break;
              }
              case 'M':         // --
              {
                dash();
                dash();
                break;
              }
              case 'N':         // -.
              {
                dash();
                dot();
                break;
              }
              case 'O':         // ---
              {
                dash();
                dash();
                dash();
                break;
              }
              case 'P':         // .--.
              {
                dot();
                dash();
                dash();
                dot();
                break;
              }
              case 'Q':         // --.-
              {
                dash();
                dash();
                dot();
                dash();
                break;
              }
              case 'R':         //.-.
              {
                dot();
                dash();
                dot();
                break;
              }
              case 'S':        // ...
              {
                dot();
                dot();
                dot();
                break;
              }
              case 'T':         // -
              {
                dash();
                break;
              }
              case 'U':         // ..-
              {
                dot();
                dot();
                dash();
                break;
              }
              case 'V':         // ...-
              {
                dot();
                dot();
                dot();
                dash();
                break;
              }
              case 'W':         // .--
              {
                dot();
                dash();
                dash();
                break;
              }
              case 'X':         // -..-
              {
                dash();
                dot();
                dot();
                dash();
                break;
              }
              case 'Y':         //-.--
              {
                dash();
                dot();
                dash();
                dash();
                break;
              }
              case 'Z':         // --..
              {
                dash();
                dash();
                dot();
                dot();
                break;
              }
              case '1':         // .----
              {
                dot();
                dash();
                dash();
                dash();
                dash();
                break;
              }
              case '2':         // ..---
              {
                dot();
                dot();
                dash();
                dash();
                dash();
                break;
              }
              case '3':         // ...--
              {
                dot();
                dot();
                dot();
                dash();
                dash();
                break;
              }
              case '4':         // ....-
              {
                dot();
                dot();
                dot();
                dot();
                dash();
                break;
              }
              case '5':         // .....
              {
                dot();
                dot();
                dot();
                dot();
                dot();
                break;
              }
              case '6':         // -....
              {
                dash();
                dot();
                dot();
                dot();
                dot();                
                break;
              }
              case '7':         // --...
              {
                dash();
                dash();
                dot();
                dot();
                dot();
                break;
              }
              case '8':         // ---..
              {
                dash();
                dash();
                dash();
                dot();
                dot();
                break;
              }
              case '9':        // ----.
              {
                dash();
                dash();
                dash();
                dash();
                dot();
                break;
              }
              case '0':         // -----
              {
                dash();
                dash();
                dash();
                dash();
                dash();
                break;
              } 
          }
          delay(); 
      }
      delay();
      delay();
      delay();
    }   
}

/*
function to add dot
*/
void dot(void)
{
    volatile unsigned int counter = 0;
    
    GPIOA_ODR = LD1_ON;
    // keep incrementing until counter reach the value
    while (counter < 30000)        
    {
        counter++;
    }
    GPIOA_ODR = LD1_OFF;
}

/*
function to add dash
*/
void dash(void)
{
    volatile unsigned int counter = 0;
    
    GPIOA_ODR = LD1_ON;
    // keep incrementing until counter reach the value
    while (counter < 90000)        
    {
        counter++;
    }
    GPIOA_ODR = LD1_OFF;
}

void delay(void)
{
    volatile unsigned int counter = 0;
    
    // keep incrementing until counter reach the value
    while (counter < 30000)        
    {
        counter++;
    }
}