#include "conbits.h"
#include <stdio.h>  


//Data Direction Registers
static void setup_tris()
{
    TRISAbits.TRISA0 = 0;    /* configure RA0 as output */
}


//Timer Control Registers
static void setup_timer()
{
    TMR0L = 0x00;         /* Load the reset value to TMR0L */
    TMR0H = 0xFF;         /* Load the compare value to TMR0H */ 
    
    //Enable the timer
    T0CON0bits.T0EN = 1;
    //Configure the timer in 8-bit mode
    T0CON0bits.T016BIT = 0;
    //Set Postscaler to 1:1
    T0CON0bits.T0OUTPS = 0x08;
    
    //Select LFINTOSC as the clock
    T0CON1bits.T0CS = 0x04;
     //Disable sync with system clock
    T0CON1bits.T0ASYNC = 1;
    //Set Prescaler to 1:16
    T0CON1bits.T0CKPS = 0x04;

}


//Interrupt Control Registers
static void setup_interupt()
{
    //Peripheral Interrupt Request (Flag) Register 0
    PIR0bits.TMR0IF = 0;  /* clear the interrupt flag */
    PIE0bits.TMR0IE = 1;  /* enable TMR0 interrupt */
    
    //Interrupt Control Register
    INTCONbits.GIE = 1;   /* Enable the Global Interrupts */
    INTCONbits.PEIE = 1;  /* Enable the Peripheral Interrupts */
}


static void init()
{
    setup_tris();
    setup_timer();
    setup_interupt();
}


static void TMR0_ISR(void)
{
    PIR0bits.TMR0IF = 0;                /* clear the TMR0 interrupt flag */
    LATAbits.LATA0 = ~LATAbits.LATA0;   /* toggle LED0 */
}


void __interrupt() INTERRUPT_InterruptManager (void)
{
    /* Check if TMR0 interrupt is enabled and if the interrupt flag is set */
    if(PIE0bits.TMR0IE == 1 && PIR0bits.TMR0IF == 1)
    {
        TMR0_ISR();
    }
}


void main(void) 
{   
    init();

    while(1)
    {
      ;
    }
}
