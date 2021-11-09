/*
Assignment 3 Q 4 MOrse Code
Author - Girish Choudankar
Date - 11/09/2021

Improvement - Use pointer to parse the array
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

#define LD1_ON          (0x00000020)
#define LD1_OFF         (0x0)

char *morseKey[27] = { 
        {"A.-"},
        {"B-..."},
        {"C-.-."},
        {"D-.."},
        {"E."},
        {"F..-."},
        {"G--."},
        {"H...."},
        {"I.."},
        {"J.---"},
        {"L.-.."},
        {"K-.-"},
        {"L.-.."},
        {"M--"},
        {"N-."},
        {"O---"},
        {"P.--."},
        {"Q--.-"},
        {"R.-."},
        {"S..."},
        {"T-"},
        {"U..-"},
        {"V...-"},
        {"W.--"},
        {"X-..-"},
        {"Y-.--"},
        {"Z--.."}
    };

char GetMorseCode(char **morseCode, int first, int last, char nameCode);
void dot(void);
void dash(void);

int main()
{
    char nameCode[] = "GIRISH";
    int first = 0;
    int last = 26;
    int charLoc = first;
    char **cp_morseKey= &morseKey[0];
       
    // enable clock for port A by setting bit 0
    RCC_AHB2ENR |= 0x00000001;
    
    // set PA5 to output by writing b01 at bits 10 and 11 
    GPIOA_MODER &= 0xFFFFF7FF;
    
    /*
        Fins a match for each character from nameCode string that need to be 
        transformed to Morse Code. Once the match is found then based on the 
        Morse code flash the LED for dash and dot.
    */
    for(char *cp_nameCode = &nameCode[0]; *cp_nameCode != '\0'; cp_nameCode++)
    {
        charLoc = GetMorseCode(morseKey, first, last, *cp_nameCode);
        for(int col = 1; cp_morseKey[charLoc][col] != '\0'; col++)
        {
            cp_morseKey[charLoc][col] == '.' ? dot() : dash();            
        }
    }
        
    return 0;
}

/*
  Function to search an input character match from the MorseKey array
  This is a binary search implementation for fasted search
*/
char GetMorseCode(char **morseKey, int first, int last, char nameCode)
{    
   while(first <= last)
    {
        int middle = (first + last)/2;
        
        if(*morseKey[middle] == nameCode)
            return middle;
        if(*morseKey[middle] <= nameCode)
            first = middle + 1;
        else
            last = middle - 1;            
    }
    return -1;
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