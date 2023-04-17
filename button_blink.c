#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/pin_manager.h"


void OSCILLATOR_Initialize(void)
{
    // NOSC HFINTOSC; NDIV 1; 
    OSCCON1 = 0x60;
    // CSWHOLD may proceed; SOSCPWR Low power; 
    OSCCON3 = 0x00;
    // MFOEN disabled; LFOEN disabled; ADOEN disabled; SOSCEN disabled; EXTOEN disabled; HFOEN disabled; 
    OSCEN = 0x00;
    // HFFRQ 64_MHz; 
    OSCFRQ = 0x08;
    // TUN 0; 
    OSCTUNE = 0x00;
}


void PIN_MANAGER_Initialize(void)
{
    /**
    LATx registers
    */
    LATE = 0x00;
    LATD = 0x00;
    LATA = 0x00;
    LATB = 0x00;
    LATC = 0x00;

    /**
    TRISx TRIState registers
    */
    TRISE = 0x0E;
    TRISA = 0xFF;
    TRISB = 0xFF;
    TRISC = 0xFF;
    TRISD = 0xFF;

    /**
    ANSELx Analog select registers
    */
    ANSELD = 0xFF;
    ANSELC = 0xFF;
    ANSELB = 0xFF;
    ANSELE = 0x02;
    ANSELA = 0xFF;

    /**
    WPUx Weak Pull-Up Registers
     * 
    */
    WPUD = 0x00;
    WPUE = 0x04;
    WPUB = 0x00;
    WPUA = 0x00;
    WPUC = 0x00;

    /**
    ODx registers
    */
    ODCONE = 0x00;
    ODCONA = 0x00;
    ODCONB = 0x00;
    ODCONC = 0x00;
    ODCOND = 0x00;

    /**
    SLRCONx registers
    */
    SLRCONA = 0xFF;
    SLRCONB = 0xFF;
    SLRCONC = 0xFF;
    SLRCOND = 0xFF;
    SLRCONE = 0x07;

    /**
    INLVLx registers
    */
    INLVLA = 0xFF;
    INLVLB = 0xFF;
    INLVLC = 0xFF;
    INLVLD = 0xFF;
    INLVLE = 0x0F;  
}


void PMD_Initialize(void)
{
    // CLKRMD CLKR enabled; SYSCMD SYSCLK enabled; SCANMD SCANNER enabled; FVRMD FVR enabled; IOCMD IOC enabled; CRCMD CRC enabled; HLVDMD HLVD enabled; NVMMD NVM enabled; 
    PMD0 = 0x00;
    // TMR0MD TMR0 enabled; TMR1MD TMR1 enabled; TMR4MD TMR4 enabled; TMR5MD TMR5 enabled; TMR2MD TMR2 enabled; TMR3MD TMR3 enabled; TMR6MD TMR6 enabled; 
    PMD1 = 0x00;
    // ZCDMD ZCD enabled; DACMD DAC enabled; CMP1MD CMP1 enabled; ADCMD ADC enabled; CMP2MD CMP2 enabled; 
    PMD2 = 0x00;
    // CCP2MD CCP2 enabled; CLC5MD CLC5 enabled; CCP1MD CCP1 enabled; CLC6MD CLC6 enabled; PWM4MD PWM4 enabled; PWM3MD PWM3 enabled; CLC7MD CLC7 enabled; CLC8MD CLC8 enabled; 
    PMD3 = 0x00;
    // CWG1MD CWG1 enabled; UART2MD EUSART2 enabled; MSSP1MD MSSP1 enabled; UART1MD EUSART enabled; MSSP2MD MSSP2 enabled; 
    PMD4 = 0x00;
    // DSMMD DSM enabled; CLC3MD CLC3 enabled; CLC4MD CLC4 enabled; CLC1MD CLC1 enabled; CLC2MD CLC2 enabled; 
    PMD5 = 0x00;
}


void SYSTEM_Initialize(void)
{
    PMD_Initialize();
    PIN_MANAGER_Initialize();
    OSCILLATOR_Initialize();
}


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
        //IF the switch is not pressed
        if (PORTEbits.RE2 == 1)
        {
            //IF the LED is HIGH
            if (PORTEbits.RE0 == 1)
            {
                //SET LED LOW
                PORTEbits.RE0 = 0;
            }
            else
            {
                //SET LED HIGH
                PORTEbits.RE0 = 1;
            }
            __delay_ms(250);
        }
        else
        {
            //SET LED LOW
            PORTEbits.RE0 = 1;
        }
    }
}
