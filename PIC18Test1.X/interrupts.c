#include "System.h"

void __interrupt(__irq(TMR4),high_priority) TMR4_ISR(void)
{
        TMR4IF = 0;
        //Timer Interrupt

        sys_time++;
        
        updateDisp();   //doing this outside of the ISR causes noticeable glitches when the ISR is disabled during the sensor read. The code in this routine is very minimal
            
        if(sys_time%500 == 0){
            halfSecondTrigger = true;
        }
        
        if(sys_time%2000 == 0){
            twoSecondTrigger = true;
        }
}

void __interrupt(__irq(U1TX),low_priority) TX_ISR(void)
{
    U1TXIF = 0;
    if(uart1_tx_buff_tail == uart1_tx_buff_head && !uart1_tx_buff_full){
        U1TXIE = 0;
        U1TXIF = 0;
    } else {
        U1TXB = uart1_tx_buff[uart1_tx_buff_tail++];
    }
    uart1_tx_buff_full = false;
}

void __interrupt(__irq(U1RX),low_priority) RX_ISR(void)
{
    U1RXIF = 0;
    bool rx_frm_error = false;
    bool rx_or_error = false;
//    GPIO_RB5_OUT = 0; //LED turned on in error conditions
    if(U1ERRIRbits.FERIF){
//        GPIO_RB5_OUT = 1; //Haven't observed LED come on at all
        rx_frm_error = true;    //reading RC1REG clears framing error
    }
    if(U1ERRIRbits.RXFOIF){
//        GPIO_RB5_OUT = 1; //Haven't observed LED come on at all
        rx_or_error = true;     //cycle of CREN clears overrun error
        U1CON0bits.RXEN = 0;
        U1CON0bits.RXEN = 1;
    }
    if(!rx_or_error){
        uint8_t rx_val = U1RXB;    //read the value to ensure the HW is read for the next byte ASAP
        if(!rx_frm_error){
            if(uart1_rx_buff_idx < UART1_RX_BUFF_SIZE){
                if(rx_val != 0x0A && rx_val != 0x0D && rx_val != 0){
                    uart1_rx_buff_isr[uart1_rx_buff_idx++] = rx_val;
                } else if(uart1_rx_buff_idx != 0){//if(rx_val == 0x0A || rx_val == 0x0D){ //a stop character received
                    for(uint8_t i = 0; i < uart1_rx_buff_idx; i++){
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
                for(uint8_t i = 0; i < UART1_RX_BUFF_SIZE; i++){
                    uart1_rx_buff_isr[i] = 0;
                    uart1_rx_buff_use[i] = 0;
                }
                uart1_rx_buff_idx = 0;
                uart1_rx_msg_present = false;
            }
        }
    }
}

void __interrupt(__irq(default),low_priority) DEFAULT_ISR(void)
{
    //do nothing
}