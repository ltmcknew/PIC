/*
 * File:   main.c
 * Author: dev-user
 *
 * Created on September 30, 2020, 10:57 AM
 */

#include "System.h"

void main(void) {
    
    SetupClk();
    
    if(STAT_SUCCESS != SysInit())
        return;
    
    bool switch_stepper_dir = true;
    
    while(1){
        CLRWDT();   //WDT is configured for ~2s in the config bit fuses, SW control is enabled tho so this can be managed there if necessary.
        
//        if(Stp1.pendingSteps != 0) {
////                GPIO_RB5_OUT ^= 1;
////            if(Stp1.allowStep){
////                GPIO_RB5_OUT ^= 1;
//                stepMotor(Stp1);
////            }
//        }
//        if((Stp2.pendingSteps != 0) && Stp2.allowStep){
//            stepMotor(Stp2);
//        }
        if(pendingSteps0 != 0 && allowStep0){
            stepMotor0();
        }
        if(pendingSteps1 != 0 && allowStep1){
            stepMotor1();
        }
        if(pendingSteps2 != 0 && allowStep2){
            stepMotor2();
        }
        
        if(twoSecondTrigger){
            twoSecondTrigger = false;   //flag set in Timer2 interrupt every 2s
            
//            if(Stp1.totalSteps >= 8192){
//                switch_stepper_dir = false;
//            } else if(Stp1.totalSteps <= 0){
//                switch_stepper_dir = true;
//            }
            if(totalSteps0 >= 8192){
                switch_stepper_dir = false;
            } else if(totalSteps0 <= 0){
                switch_stepper_dir = true;
            }
            
//            updateDispValHex(Stp1.totalSteps,4);
            updateDispValHex(totalSteps0,4);
            
            if(switch_stepper_dir){
//                GPIO_RB5_OUT ^= 1;
//                Stp1.pendingSteps += 1024;
//                Stp2.pendingSteps += 1024;
                pendingSteps0 += 1024;
                pendingSteps1 += 1024;
                pendingSteps2 += 1024;
            } else {
//                Stp1.pendingSteps -= 1024;
//                Stp2.pendingSteps -= 1024;
                pendingSteps0 -= 1024;
                pendingSteps1 -= 1024;
                pendingSteps2 -= 1024;
            }
        }
     
    }
    
    return;
}
