
#include "System.h"

void __ISR(_TIMER_4_VECTOR,IPL7AUTO) timer4ISR(void)
{
    IFS0CLR = _IFS0_T4IF_MASK;
    
    if(sys_time % 2000 == 0){
        sys_twoseconds = true;
    }
    
    sys_time++;
}

void __ISR(_UART_1_VECTOR,IPL6AUTO) UART1_ISR(void)
{
    if(IFS1bits.U1TXIF && IEC1bits.U1TXIE){ //TX Interrupt
        IFS1CLR = _IFS1_U1TXIF_MASK;
        if(uart1_tx_buff_tail == uart1_tx_buff_head && !uart1_tx_buff_full){
            IEC1CLR = _IEC1_U1TXIE_MASK;
            IFS1CLR = _IFS1_U1TXIF_MASK;
        } else {
            U1TXREG = uart1_tx_buff[uart1_tx_buff_tail++];
        }
        uart1_tx_buff_full = false;
    }
    
    if(IFS1bits.U1RXIF){    //RX Interrupt
        IFS1CLR = _IFS1_U1RXIF_MASK;
        
        while(U1STAbits.URXDA == 1){
            bool rx_frm_error = false;
            bool rx_or_error = false;
        //    GPIO_RB5_OUT = 0; //LED turned on in error conditions
            if(U1STAbits.FERR){
        //        GPIO_RB5_OUT = 1; //Haven't observed LED come on at all
                rx_frm_error = true;    //reading U1RXREG clears framing error
            }
            if(U1STAbits.OERR){
        //        GPIO_RB5_OUT = 1; //Haven't observed LED come on at all
                rx_or_error = true;     //cycle of CREN clears overrun error
                U1STACLR = _U1STA_OERR_MASK;
            }
            if(!rx_or_error){
                uint8_t rx_val = U1RXREG;    //read the value to ensure the HW is read for the next byte ASAP
                if(!rx_frm_error){
                    if(uart1_rx_buff_idx < UART1_RX_BUFF_SIZE){
                        if(rx_val != 0x0A && rx_val != 0x0D && rx_val != 0){
                            uart1_rx_buff_isr[uart1_rx_buff_idx++] = rx_val;
                        } else if(uart1_rx_buff_idx != 0 && rx_val != 0){//if(rx_val == 0x0A || rx_val == 0x0D){ //a stop character received
                            uint8_t i;
                            for(i = 0; i < uart1_rx_buff_idx; i++){
                                uart1_rx_buff_use[i] = uart1_rx_buff_isr[i];  //copy the whole string
                                uart1_rx_buff_isr[i] = 0;  //clear the isr buffer as the data gets copied out
                            }
                            uart1_rx_buff_use[uart1_rx_buff_idx] = 0; //ensure the byte after the stop character gets cleared for string operations
                            uart1_rx_buff_load_cnt = uart1_rx_buff_idx;
                            uart1_rx_msg_present = true;   //indicate to main that a message is in the 'use' buffer
                            uart1_rx_buff_idx = 0; //reset index for next message
                        }
                    } else {
                        //buffer full, reset the logic and buffers
                        uint8_t i;
                        for(i = 0; i < UART1_RX_BUFF_SIZE; i++){
                            uart1_rx_buff_isr[i] = 0;
                            uart1_rx_buff_use[i] = 0;
                        }
                        uart1_rx_buff_idx = 0;
                        uart1_rx_msg_present = false;
                    }
                }
            }
        }
    }
}

