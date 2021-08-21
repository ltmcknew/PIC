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
    
    //Set GPIO RD1 to output with initial value (Pin 20)
    GPIO_RD1_OUT = 0;
    GPIO_RD1_TRIS = 0;
    
    //Set GPIO RB5 to output with initial value (Pin 38)
    GPIO_RB5_OUT = 0;
    GPIO_RB5_TRIS = 0;
    
//    //Setup MAX232 Reset Line
//    EUSART_RST = 1;
//    EUSART_RST_TRIS = 0;
    
//    setup_dht11_snsr();
//    setup_irdist_snsr(true);
//    //LED GPIO Pins
//    TRICOLOR_G = 0;
//    TRICOLOR_G_TRIS = 0;
//    TRICOLOR_B = 0;
//    TRICOLOR_B_TRIS = 0;
//    TRICOLOR_R = 0;
//    TRICOLOR_R_TRIS = 0;
    
    sys_time = 0;
    sys_stat = 0;
    
//    servoAngleUse = 0;
//    setupServo(servoAngleUse);
    
    setupStepper();
    
    //Assign Timer4 to tmr4 object
//    tmr4.CON = &T4CON;
//    tmr4.CLKCON = &T4CLKCON;
//    tmr4.HLT = &T4HLT;
//    tmr4.PREG = &T4PR;
//    tmr4.intBitPos = 0x08;
//    if(TmrSetup(tmr4,1000,true) == STAT_SUCCESS){
//        sys_stat |= 1;
//        TmrEnable(tmr4);
//    }
    if(Tmr4Setup(1000,true) == STAT_SUCCESS){
        sys_stat |= 1;
        Tmr4Enable();
    }
    
//    if(EUSARTSetup(115200,true,true) == STAT_SUCCESS){
//        sys_stat |= 2;
//    }
    
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

