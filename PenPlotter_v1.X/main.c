/*
 * File:   main.c
 * Author: dev-user
 *
 * Created on November 19, 2020, 1:30 PM
 */

#include "System.h"

void main(void) {
    
    SysInit();
    
    char msg_buff[256];
    uint16_t i2c_val = 0;
    
    while(sys_time < 250)  //wait 1s after init to begin operation
        WDTCONCLR = _WDTCON_WDTCLR_MASK;
    
    sprintf(msg_buff,"System Init Complete, Status: 0x%04X",sys_stat);
    uart1_tx_str_crlf(msg_buff);
   
    OledDrawCircle(64,40,20,WHITE);
    OledDrawGlobe();
    sprintf(msg_buff,"PenPlotter_v1");
    OledDrawString(0,0,msg_buff,true);
    
    while(running){
        WDTCONCLR = _WDTCON_WDTCLR_MASK;
        
        stepSMachine0();    //perform stepper state machine for stepper 0
        stepSMachine1();    //perform stepper state machine for stepper 1
        
        
        if(sys_twoseconds){
            sys_twoseconds = false;
            
            sprintf(msg_buff,"System Time: %lus",sys_time/1000);
            uart1_tx_str_crlf(msg_buff);
            OledDrawString(0,8,msg_buff,false);
            
            if(sys_time < 2000){    //clear the startup image (globe))
                OledDrawString(0,8,msg_buff,true);
                OledFillRect(0,16,128,48,BLACK);
            } else {
                OledDrawString(0,8,msg_buff,false);
                sprintf(msg_buff,"Positions:");
                OledDrawString(0,16,msg_buff,false);
                sprintf(msg_buff,"X: %ld",totalSteps0);
                OledDrawString(0,24,msg_buff,false);
                sprintf(msg_buff,"Y: %ld",totalSteps1);
                OledDrawString(0,32,msg_buff,false);
                sprintf(msg_buff,"Z: %d",servoAngleUse);
                OledDrawString(0,40,msg_buff,false);
                OledWriteDisplay();
            }
            
            sprintf(msg_buff,"X Position: %ld"totalSteps0);
            uart1_tx_str_crlf(msg_buff);
            sprintf(msg_buff,"Y Position: %ld",totalSteps1);
            uart1_tx_str_crlf(msg_buff);
            sprintf(msg_buff,"Z Position: %d",servoAngleUse);
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

