//#include "PICDEFS.h"
#include "System.h"

// If Device Support Interrupt Priorities
//void interrupt high_priority   HighIsr(void){
//    
//}
//void interrupt low_priority   LowIsr(void){
//    
//}

void __interrupt() Isr(void){
    if(PIR4 && tmr4.intBitPos){
        PIR4 &= ~tmr4.intBitPos;
        //Timer Interrupt

        sys_time++;
        
        GPIO_RD1_OUT ^= 1;
        
        if(sys_time%50 == 0){
//            do_pwm_updates = true;
        }
        
        if(sys_time%333 == 0){            
            if(sys_time%666 == 0){
                TRICOLOR_B ^= 1;
            } else if(sys_time%999 == 0){
                    TRICOLOR_R ^= 1;
            } else {
                TRICOLOR_G ^= 1;
            }
        }
        
        if(sys_time%2000 == 0){
            do_dht11_snsr_read = true;
        }
    }
//    if(TMR0IF){
//        TMR0IF = 0;
//        TMR0H = TMR0Val>>8;
//        TMR0L = TMR0Val & 0xFF;
//        //Timer0 Interrupt
//
//        sys_time++;
//        
//        GPIO_RD1_OUT ^= 1;
//                
//        if(sys_time%5 == 0){
//            do_pwm_updates = true;
//        }
//        
//        
//        if(sys_time%2000 == 0){
//            do_dht11_snsr_read = true;
//        }
//    }
    
    if(INTF){
        INTF = 0;
        do_irdist_snsr_read = true;
    }
    
    if(TXIF){
        TXIF = 0;
        if(eusart_tx_buff_tail == eusart_tx_buff_head && !eusart_tx_buff_full){
            TXIE = 0;
            TXIF = 0;
        } else {
            TX1REG = eusart_tx_buff[eusart_tx_buff_tail++];
        }
        eusart_tx_buff_full = false;
    }
    
    if(RCIF){
        RCIF = 0;
        bool rx_frm_error = false;
        bool rx_or_error = false;
//        GPIO_RB5_OUT = 0; //LED turned on in error conditions
        if(RC1STAbits.FERR){
//            GPIO_RB5_OUT = 1; //Haven't observed LED come on at all
            rx_frm_error = true;    //reading RC1REG clears framing error
        }
        if(RC1STAbits.OERR){
//            GPIO_RB5_OUT = 1; //Haven't observed LED come on at all
            rx_or_error = true;     //cycle of CREN clears overrun error
            RC1STAbits.CREN = 0;
            RC1STAbits.CREN = 1;
        }
        if(!rx_or_error){
            uint8_t rx_val = RC1REG;    //read the value to ensure the HW is read for the next byte ASAP
            if(!rx_frm_error){
                if(eusart_rx_buff_idx < EUSART_RX_BUFF_SIZE){
                    if(rx_val != 0x0A && rx_val != 0x0D && rx_val != 0){
                        eusart_rx_buff_isr[eusart_rx_buff_idx++] = rx_val;
                    } else if(eusart_rx_buff_idx != 0){//if(rx_val == 0x0A || rx_val == 0x0D){ //a stop character received
                        for(uint8_t i = 0; i < eusart_rx_buff_idx; i++){
                            eusart_rx_buff_use[i] = eusart_rx_buff_isr[i];  //copy the whole string
                            eusart_rx_buff_isr[i] = 0;  //clear the isr buffer as the data gets copied out
                        }
                        eusart_rx_buff_use[eusart_rx_buff_idx] = 0; //ensure the byte after the stop character gets cleared for string operations
                        eusart_rx_buff_load_cnt = eusart_rx_buff_idx;
                        eusart_rx_msg_present = true;   //indicate to main that a message is in the 'use' buffer
                        eusart_rx_buff_idx = 0; //reset index for next message
                    }
                } else {
                    //buffer full, reset the logic and buffers
                    for(uint8_t i = 0; i < EUSART_RX_BUFF_SIZE; i++){
                        eusart_rx_buff_isr[i] = 0;
                        eusart_rx_buff_use[i] = 0;
                    }
                    eusart_rx_buff_idx = 0;
                    eusart_rx_msg_present = false;
                }
            }
        }
    }
}