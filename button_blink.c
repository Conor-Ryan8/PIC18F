#include <xc.h>
#include "pic18f47q10.h"
#include "conbits.h"

void main(void)
{
    //Set PIN E0 to output
    TRISEbits.TRISE0 = 0;
    //Set PIN E2 to input
    TRISEbits.TRISE2 = 1;
    
    //Set E0 + E2 PIN's to analog 
    ANSELEbits.ANSELE0 = 0;
    ANSELEbits.ANSELE2 = 0;
    
    //Enable weak pull-up on PIN E2
    WPUEbits.WPUE2 = 1;
    
    while (1)
    {
        //If switch PIN is high
        if (PORTEbits.RE2 == 1)
        {
            //Set LED to HIGH
            LATEbits.LATE0 = 1;
        }
        else
        {
            //Set LED to LOW
            LATEbits.LATE0 = 0;
        }
    }
}
