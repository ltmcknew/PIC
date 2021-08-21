/*
 * File:   main.c
 * Author: dev-user
 *
 * Created on October 12, 2020, 10:40 AM
 */


#include "System.h"

void main(void) {
    
    SetupClk();
    
    if(STAT_SUCCESS != SysInit())
        return;

    bool switch_stepper_dir = true;
    uint32_t sys_time_act;    
    char msg_buff[64];
    
    sprintf(msg_buff,"System Init Complete, System Status: 0x%02X, Beginning Loop",sys_stat);
    uart1_tx_str_crlf(msg_buff);    
    
    while(1){
        CLRWDT();   //WDT is configured for ~2s in the config bit fuses, SW control is enabled tho so this can be managed there if necessary.
        
        stepSMachine0();    //perform stepper state machine for stepper 0
        stepSMachine1();    //perform stepper state machine for stepper 1
        stepSMachine2();    //perform stepper state machine for stepper 2
//        if(pendingSteps0 != 0 && allowStep0){
//            stepMotor0();
//        }
//        if(pendingSteps1 != 0 && allowStep1){
//            stepMotor1();
//        }
//        if(pendingSteps2 != 0 && allowStep2){
//            stepMotor2();
//        }
        
        if(halfSecondTrigger){
            halfSecondTrigger = false;
        }
        
        if(twoSecondTrigger){
            twoSecondTrigger = false;
                        
//            updateDispValHex(sys_time,4);
            sprintf(msg_buff,"System Time: %lu",sys_time);
            uart1_tx_str_crlf(msg_buff);
            
            updateDispValHex(totalSteps0,4);
            sprintf(msg_buff,"Stepper0\n\rPending: %d,\tTotal: %ld",pendingSteps0,totalSteps0);
            uart1_tx_str_crlf(msg_buff);
            sprintf(msg_buff,"Stepper1\n\rPending: %d,\tTotal: %ld",pendingSteps1,totalSteps1);
            uart1_tx_str_crlf(msg_buff);
            sprintf(msg_buff,"Stepper2\n\rPending: %d,\tTotal: %ld",pendingSteps2,totalSteps2);
            uart1_tx_str_crlf(msg_buff);
        }
        
        if(uart1_rx_msg_present){
            uart1_tx_str_crlf(uart1_rx_buff_use);
            interpretRX();
            uart1_rx_msg_present = false;
        }
    }
    
    return;
}
