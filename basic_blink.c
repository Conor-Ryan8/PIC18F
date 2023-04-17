#include "mcc_generated_files/mcc.h"

void main(void)
{

    SYSTEM_Initialize();

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    while (1)
    {
        if (PORTEbits.RE0 == 1)
        {
            PORTEbits.RE0 = 0;
        }
        else
        {
            PORTEbits.RE0 = 1;
        }
        __delay_ms(2000);
    }
}
