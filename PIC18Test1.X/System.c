#include "System.h"

void SetupClk(void)
{
    OSCCON1 = 0x60; //select HFIntOsc with Divider of 1
    if(_XTAL_FREQ == 32000000)
        OSCFRQ = 0x06;  //select 32MHz as HFIntOsc frequency
    else if(_XTAL_FREQ == 64000000)
        OSCFRQ = 0x08;
    else
        OSCFRQ = 0x05;  //select 16MHz by default
    
    while(! OSCSTATbits.HFOR && !OSCSTATbits.PLLR) continue;   //wait for frequency stability and lock
}


STATUS_T SysInit(void)
{
    //Default all pins to digital
    make_all_digital();
    
    //Make Programming Pins Inputs
    PGD_TRIS = 1;
    PGC_TRIS = 1;
    
    //Set GPIO RB5 to output with initial value (Pin 38)
//    GPIO_RB5_OUT = 0;
//    GPIO_RB5_TRIS = 0;    
//    GPIO_RB4_OUT = 0;
//    GPIO_RB4_TRIS = 0;    
    
//    //Setup MAX232 Reset Line
//    UART1_RST = 1;
//    UART1_RST_TRIS = 0;
    
    sys_time = 0;
    sys_stat = 0;
    halfSecondTrigger = false;
    twoSecondTrigger = false;
        
//    if(setupStepper0() == STAT_SUCCESS){
//        sys_stat |= 16;
//    }
//    if(setupStepper1() == STAT_SUCCESS){
//        sys_stat |= 32;
//    }
//    if(setupStepper2() == STAT_SUCCESS){
//        sys_stat |= 64;
//    }
    
    if(Tmr4Setup(1000,true) == STAT_SUCCESS){
        sys_stat |= 1;
        TMR4IP = 1;
        Tmr4Enable();
    }
    
    if(setupDisp(1010) == STAT_SUCCESS){
        sys_stat |= 2;
    }
    
    if(UART1Setup(115200,true,true) == STAT_SUCCESS){
        sys_stat |= 4;
    }
    
    if(IOExpSetup(&ioexp1,0xE8,0x0000,0x0000,0x0000) == STAT_SUCCESS){
        sys_stat |= 8;
    }
    
//    if(I2C1Setup(true) == STAT_SUCCESS){
//        sys_stat |= 8;
//        IOEXP_RST = 0;  //load 0 into the reset bit
//        IOEXP_RST_TRIS = 0; //make the pin an output and assert reset
//        __delay_ms(5);  //wait 5ms for the reset to occur
//        I2C1Enable();
//        IOEXP_RST = 1;  //release the reset condition.
//    }
    
//    PEIE = 1; //this chip supports independent interrupt vectors
    INTCON0bits.IPEN = 1;
    GIE = 1;
    
    return STAT_SUCCESS;
}

STATUS_T make_all_digital(void)
{
    ANSELA = 0;
    ANSELB = 0;
    ANSELC = 0;
    ANSELD = 0;
    ANSELE = 0;
    
    return STAT_SUCCESS;
}
