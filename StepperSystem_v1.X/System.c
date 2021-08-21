#include "System.h"

void SetupClk(void)
{
    OSCCON1 = 0x60; //select HFIntOsc with Divider of 1
    OSCFRQ = 0x06;  //select 32MHz as HFIntOsc frequency
    
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
    GPIO_RB5_OUT = 0;
    GPIO_RB5_TRIS = 0;    
    
    sys_time = 0;
    sys_stat = 0;
    twoSecondTrigger = false;
        
    setupStepper0();    //working
    setupStepper1();    //working
    setupStepper2();    //working

//    setupStepper(Stp1,1,0x01,&LATA,&TRISA,0x01,&LATA,&TRISA,0x02,&LATA,&TRISA,0x04,&LATA,&TRISA,0x08);
//    setupStepper(Stp2,3,0x04,&LATA,&TRISA,0x10,&LATA,&TRISA,0x20,&LATA,&TRISA,0x40,&LATA,&TRISA,0x80);
    
    if(Tmr4Setup(1000,true) == STAT_SUCCESS){
        sys_stat |= 1;
        Tmr4Enable();
    }
    
    if(setupDisp(1010) == STAT_SUCCESS){
        sys_stat |= 4;
    }
    
    PEIE = 1;
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


