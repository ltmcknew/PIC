#include "System.h"


void __interrupt() Isr(void){
//    if((PIR4 & Stp1.timerIntBitVal) != 0x00){
//        PIR4 &= ~Stp1.timerIntBitVal;
//        Stp1.allowStep = true;
//    }
//    if((PIR4 & Stp2.timerIntBitVal) != 0x00){
//        PIR4 &= ~Stp2.timerIntBitVal;
//        Stp2.allowStep = true;
//    }
    if(TMR1IF){
        TMR1IF = 0;
        allowStep0 = true;
        if(pendingSteps0 == 0){
            STEPPER0_OUT0 = 0;
            STEPPER0_OUT1 = 0;
            STEPPER0_OUT2 = 0;
            STEPPER0_OUT3 = 0;
        }
//        Stp1.allowStep = true;
    }
    if(TMR3IF){
        TMR3IF = 0;
        allowStep1 = true;
        if(pendingSteps1 == 0){
            STEPPER1_OUT0 = 0;
            STEPPER1_OUT1 = 0;
            STEPPER1_OUT2 = 0;
            STEPPER1_OUT3 = 0;
        }
//        Stp2.allowStep = true;
    }
    if(TMR5IF){
        TMR5IF = 0;
        allowStep2 = true;
        if(pendingSteps2 == 0){
            STEPPER2_OUT0 = 0;
            STEPPER2_OUT1 = 0;
            STEPPER2_OUT2 = 0;
            STEPPER2_OUT3 = 0;
        }
    }
    
    if(PIR4bits.TMR4IF){
        PIR4bits.TMR4IF = 0;
        //Timer Interrupt

        sys_time++;
        
        updateDisp();   //doing this outside of the ISR causes noticeable glitches when the ISR is disabled during the sensor read. The code in this routine is very minimal
            
//        if(sys_time%500 == 0){
//        }
        
        
        if(sys_time%2000 == 0){
            twoSecondTrigger = true;
        }
    }
}

