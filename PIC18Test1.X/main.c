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
        
        if(halfSecondTrigger){
            halfSecondTrigger = false;

            uint16_t newIOVal = ((ioexp1.P1OVal.val+2) << 8) + (ioexp1.P0OVal.val+1);
//            newIOVal ^= 0x00AA;
            IOExpUpdateOut(&ioexp1,newIOVal);
            
            IOExpUpdateIn(&ioexp1);
            sprintf(msg_buff,"IOExp P0In: 0x%02X, P1In: 0x%02X",ioexp1.P0IVal.val,ioexp1.P1IVal.val);
            uart1_tx_str_crlf(msg_buff);
            
        }
        
        if(twoSecondTrigger){
            twoSecondTrigger = false;
            
            updateDispValHex(sys_time,4);
            sprintf(msg_buff,"System Time: %lu",sys_time);
            uart1_tx_str_crlf(msg_buff);
        }
        
        if(uart1_rx_msg_present){
            uart1_tx_str_crlf(uart1_rx_buff_use);
            uart1_rx_msg_present = false;
        }
    }
    
    return;
}
