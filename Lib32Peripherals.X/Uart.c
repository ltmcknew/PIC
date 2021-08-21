#include <proc/p32mx170f256b.h>

#include "Uart.h"

#ifdef __USE_UART1__
STATUS_T UART1Setup(uint32_t set_baud, bool use_tx, bool use_rx)
{
    // SETUP THE PINS
    U1RXR = UART1_RX_PPS_VAL;
    UART1_RX_TRIS = 1;
    
    UART1_TX_PPS = 0b0001;
    UART1_TX_TRIS = 1;

    // DISABLE THE PORT BEFORE CONFIGURATION
    U1MODECLR = 0xFFFFFFFF; //disable whole port (by clearing the whole register) for init
    _nop();
    //disable auto-baud detection, RX Idles High, 8n configuration, 1 stop bit, BRGH=0->16x baud clock
    U1STASET = 0x00009000;
    //RX Interrup when buffer is not empty, Addr Detect Mode disabled, many other bits are read-only status flags    
    
    
    // SETUP THE BAUDRATE
    //Select 115200, depends on BRGH = 1 or 0, Value given by RegVal = Fosc/X/DesiredBaud - 1, RegVal can be 16 bit in SP1BRGH:SP1BRGL, X is either 16 or 4 depending on BRGH
    /*  BRGH    |   BRG Base Clk
     *  0           Fosc/16
     *  1           Fosc/4
     */
    uint32_t regVal = _XTAL_FREQ/4;  //Assume Fosc/4 at start
    regVal = regVal / set_baud;
    regVal = regVal - 1;
    if(regVal <= 0xFFFF){
        U1MODESET = _U1MODE_BRGH_MASK;
    } else {
        //try Fosc/16, assume 16bit SP1BRG value still
        regVal = (regVal+1)/4; //add the one back and the previous value just needs to be divided by 4 to account for the new factor
        regVal = regVal - 1;
        if(regVal <= 0xFFFF){
            U1MODECLR = _U1MODE_BRGH_MASK;
        } else {
            //Nothing else to try
            return STAT_FAIL;
        }
    }
    U1BRG = regVal;   //81 -> 115200

        
    if(use_tx){
        // SETUP THE TRANSMITTER
        uart1_tx_buff_tail = 0;
        uart1_tx_buff_head = 0;
        uart1_tx_buff_full = false;
        uint16_t i;
        for(i = 0; i < 256; i++){
            uart1_tx_buff[i] = 0;
        }
        uart1_tx_sys_active = true;
    } else {
        uart1_tx_sys_active = false;
    }
    
    if(use_rx){
        // SETUP THE RECEIVER
        U1STASET = _U1STA_URXEN_MASK;
        uint8_t i;
        for(i = 0; i < UART1_RX_BUFF_SIZE; i++){
            uart1_rx_buff_isr[i] = 0;
            uart1_rx_buff_use[i] = 0;
        }
        uart1_rx_buff_idx = 0;
        uart1_rx_msg_present = false;
        uart1_rx_sys_active = true;
        IFS1CLR = _IFS1_U1RXIF_MASK;
        IEC1SET = _IEC1_U1RXIE_MASK;
    } else {
        uart1_rx_sys_active = false;
    }
    
    if(use_tx || use_rx){
        IPC8SET = 5 << _IPC8_U1IP_POSITION;
        IPC8SET = 3 << _IPC8_U1IS_POSITION;
//        IPC8bits.U1IP = 5;
//        IPC8bits.U1IS = 3;
        U1MODESET = _U1MODE_UARTEN_MASK;
//        U1MODEbits.ON = 1;      //Enable the UART
    }
    
    return STAT_SUCCESS;
}

STATUS_T uart1_tx_str(char * in_bytes)
{
    IEC1CLR = _IEC1_U1TXIE_MASK;
//    U1STACLR = _U1STA_UTXEN_MASK;
    if((uart1_tx_buff_tail != uart1_tx_buff_head) || !uart1_tx_buff_full){                     //  |eeeeeetailfffffffheadeeeeee| or |ffffffheadeeeeeeetailffffff|
        if(((uart1_tx_buff_tail - uart1_tx_buff_head) >= strlen(in_bytes)) || ((uart1_tx_buff_head == uart1_tx_buff_tail) && !uart1_tx_buff_full)){       // if tail = 10 and head = 200, tail - head = -190 => 66 due to byte saturation, 66 empty bytes
            uint8_t i;
            for(i = 0; i < strlen(in_bytes); i++){                        // if tail = 200 and head = 10, tail - head = 190, 190 empty bytes
                uart1_tx_buff[uart1_tx_buff_head++] = in_bytes[i];    //load data byte-by-byte into buffer
            }
            if(uart1_tx_buff_head == uart1_tx_buff_tail){
                uart1_tx_buff_full = true;
            }
        } else {    //not enough space to load the message
            return STAT_FAIL;
        }
    } else {              
        //reset the buffer?
    }
    
    if((uart1_tx_buff_head != uart1_tx_buff_tail) || (uart1_tx_buff_full)){
        IEC1SET = _IEC1_U1TXIE_MASK;
        U1STASET = _U1STA_UTXEN_MASK;
//        IEC1bits.U1TXIE = 1;   //enable TXinterrupt for thread protection
//        U1STAbits.UTXEN = 1;   //enable TXenable for thread protection
    }
    
    return STAT_SUCCESS;
}

STATUS_T uart1_tx_str_crlf(char * in_bytes)
{
    STATUS_T res = STAT_SUCCESS;
            
    if(UART1_RX_BUFF_SIZE > (strlen(in_bytes)+2)){
        char new_buff[UART1_RX_BUFF_SIZE];
        strcpy(new_buff,in_bytes);
        strcat(new_buff,"\n\r");
        
        return uart1_tx_str(new_buff);
    }
    
    return uart1_tx_str(in_bytes);
}

void uart1_wait(void){
    while(U1STAbits.UTXBF || IEC1bits.U1TXIE) continue;
}
#endif