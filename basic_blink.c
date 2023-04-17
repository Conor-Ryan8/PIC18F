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
        PORTEbits.RE0 ^= 1;
        __delay_ms(1000);
    }
}
