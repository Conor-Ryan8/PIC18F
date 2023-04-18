#include <xc.h>
#include "pic18f47q10.h"
#include "conbits.h"

void main(void)
{
    TRISEbits.TRISE0 = 0; //LED PIN set to Output

    while (1)
    {
        LATE = 0;
        __delay_ms(500);
        LATE = 1;
        __delay_ms(500);
    }
}
