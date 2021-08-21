/*
 * File:   main.c
 * Author: dev-user
 *
 * Created on October 20, 2020, 5:17 PM
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
    
    while(running){
        WDTCONCLR = _WDTCON_WDTCLR_MASK;
        
        stepSMachine0();    //perform stepper state machine for stepper 0
        stepSMachine1();    //perform stepper state machine for stepper 1
        stepSMachine2();    //perform stepper state machine for stepper 2
        
        
        if(sys_twoseconds){
            sys_twoseconds = false;
            
            sprintf(msg_buff,"System Time: %lu",sys_time/1000);
            uart1_tx_str_crlf(msg_buff);
            
            sprintf(msg_buff,"Stepper0\n\rPending: %d,\tTotal: %ld",pendingSteps0,totalSteps0);
            uart1_tx_str_crlf(msg_buff);
            sprintf(msg_buff,"Stepper1\n\rPending: %d,\tTotal: %ld",pendingSteps1,totalSteps1);
            uart1_tx_str_crlf(msg_buff);
            sprintf(msg_buff,"Stepper2\n\rPending: %d,\tTotal: %ld",pendingSteps2,totalSteps2);
            uart1_tx_str_crlf(msg_buff);
            
//            IOExpUpdateOut(&ioexp1,i2c_val);
//            i2c_val += 0x0101;
//
//            IOExpUpdateIn(&ioexp1);
//            sprintf(msg_buff,"I2C Read P0: 0x%02X, P1: 0x%02X",ioexp1.P0IVal,ioexp1.P1IVal);
//            uart1_tx_str_crlf(msg_buff);
        }
        if(uart1_rx_msg_present){
            uart1_tx_str_crlf(uart1_rx_buff_use);
            interpretRX();
            uart1_rx_msg_present = false;
        }
        
//        if(IFS0bits.T2IF){        //check timer config without interrupts enabled
//            IFS0bits.T2IF = 0;
//            GPIO_RB15_OUT ^= 1;
//        }
//        GPIO_RB15_OUT ^= 1;   //toggling at 20ms with XTAL_FREQ = 38MHz
//        for(i = 0; i < 65534; i++){
//            continue;
//        }
    }
    
    return;
}
