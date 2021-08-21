/*
 * File:   main.c
 * Author: dev-user
 *
 * Created on September 11, 2020, 10:26 AM
 */

//#define __UART_XMIT_TEST__

#include <xc.h>
#include "System.h"

void main(void) {
    
    SetupClk();
    
    if(STAT_SUCCESS != SysInit())
        return;
    
    uint8_t byte_acc = 0;
//    bool pwm2_up = false;
//    bool pwm5_up = false;
//    bool pwm6_up = false;

#ifdef __UART_XMIT_TEST__
    char msg_buff[64];
    sprintf(msg_buff,"TMR2 PR: 0x%02X, T2CON: 0x%02X, Xtal: %ld\n\r",T2PR,T2CON,_XTAL_FREQ);
#else    
    char msg_buff[64];
    uint32_t sys_time_act;
    
    sprintf(msg_buff,"System Init Complete, System Status: 0x%02X, Beginning Loop",sys_stat);
    load_tx_msg_str_crlf(msg_buff);
#endif

    
    while(1){
        CLRWDT();   //WDT is configured for ~2s in the config bit fuses, SW control is enabled tho so this can be managed there if necessary.
        
#ifdef __UART_XMIT_TEST__
        load_tx_msg_str(msg_buff);
        GPIO_RA5_OUT ^= 1;
        __delay_ms(500);
        
#else
        if(do_dht11_snsr_read){
            do_dht11_snsr_read = false;   //flag set in Timer2 interrupt every 2s
            sprintf(msg_buff,"%d: Starting Data Read",sys_time/1000);
            load_tx_msg_str_crlf(msg_buff);
            //the data read here is very time sensitive, it needs to be uninterruptable 
            if(read_dht11_dat() == STAT_SUCCESS){   //if read succeeded then output the values
                sprintf(msg_buff,"H = %d.%d%% T = %d.%dC",dht11_dat_arr[0],dht11_dat_arr[1],dht11_dat_arr[2],dht11_dat_arr[3]);
                load_tx_msg_str_crlf(msg_buff);
            }
        }
        
        if(do_irdist_snsr_read){
            do_irdist_snsr_read = false;
            if(read_irdist_dat() == STAT_SUCCESS){
                if(irdist_result){
                    GPIO_RB5_OUT = 1;
                } else {
                    GPIO_RB5_OUT = 0;
                }
            }
            sys_time_act = sys_time + 1000;
        }
        
        if(sys_time == sys_time_act){
            GPIO_RB5_OUT = 0;
            sys_time_act = sys_time - 1;
        }
        
//        if(do_pwm_updates){
//            do_pwm_updates = false;
//            if(pwm2_up){
//                Pwm2UpdateDC(Pwm2DCPct+200); //add 0.5% to the DC Value
//                if(Pwm2DCPct == PWMMAXPCT){  //if we've saturated, flip the action
//                    pwm2_up = false;
//                }
//            } else {
//                Pwm2UpdateDC(Pwm2DCPct-200); //subtract 0.5% from the DC Value
//                if(Pwm2DCPct == 0){             //if we've saturated, flip the action
//                    pwm2_up = true;
//                }
//            }
//            if(pwm5_up){
//                Pwm5UpdateDC(Pwm5DCPct+200); //add 0.5% to the DC Value
//                if(Pwm5DCPct == PWMMAXPCT){  //if we've saturated, flip the action
//                    pwm5_up = false;
//                }
//            } else {
//                Pwm5UpdateDC(Pwm5DCPct-200); //subtract 0.5% from the DC Value
//                if(Pwm5DCPct == 0){             //if we've saturated, flip the action
//                    pwm5_up = true;
//                }
//            }
//            if(pwm6_up){
//                Pwm6UpdateDC(Pwm6DCPct+200); //add 0.5% to the DC Value
//                if(Pwm6DCPct == PWMMAXPCT){  //if we've saturated, flip the action
//                    pwm6_up = false;
//                }
//            } else {
//                Pwm6UpdateDC(Pwm6DCPct-200); //subtract 0.5% from the DC Value
//                if(Pwm6DCPct == 0){             //if we've saturated, flip the action
//                    pwm6_up = true;
//                }
//            }
//        }
//        if(eusart_rx_msg_present){
//            load_tx_msg_str_crlf(eusart_rx_buff_use);
//            eusart_rx_msg_present = false;
//        }
#endif
    }
    
    return;
}
