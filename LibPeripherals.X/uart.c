#include "uart.h"

#ifdef __USE_UART1__
STATUS_T UART1Setup(uint32_t set_baud, bool use_tx, bool use_rx)
{
    // SETUP THE PINS
    U1RXPPS = UART1_RX_PPS_VAL;
    UART1_RX_TRIS = 1;
    
    UART1_TX_PPS = 0x13;
    UART1_TX_TRIS = 1;

    // DISABLE THE PORT BEFORE CONFIGURATION
    U1CON1bits.ON = 0;    //disable whole port for init
    U1CON0bits.RXEN = 0;    //disable RX
    U1CON0bits.TXEN = 0;    //disable TX
    
    U1CON0bits.MODE = 0b0000;   //Async 8-bit UART Mode
    U1CON2 = 0x00;
    
    // SETUP THE BAUDRATE
    //Select 115200, depends on BRGS = 1 or 0, Value given by RegVal = Fosc/X/DesiredBaud - 1, RegVal can be 16 bit in SP1BRGH:SP1BRGL, X is either 16 or 4 depending on BRGS
//    uint32_t regVal = _XTAL_FREQ >> 4;  //Fosc/4
//    regVal /= set_baud; //Fosc/4/DesiredBaud
//    regVal -= 1;        //Fosc/4/DesiredBaud - 1
//    SP1BRGH = (uint8_t)(0xFF & (regVal>>8));
//    SP1BRGL = (uint8_t)(0xFF & regVal);   //68 -> 115200
    /*  BRG16   |   BRGH    |   BRG Base Clk
     *  0           0           Fosc/64
     *  0           1           Fosc/16
     *  1           0           Fosc/16
     *  1           1           Fosc/4
     */
    uint32_t regVal = _XTAL_FREQ/4;  //Assume Fosc/4 at start
    regVal = regVal / set_baud;
    regVal = regVal - 1;
    if(regVal <= 0xFFFF){
        U1CON0bits.BRGS = 1;
    } else {
        //try Fosc/16, assume 16bit SP1BRG value still
        regVal = (regVal+1)/4; //add the one back and the previous value just needs to be divided by 4 to account for the new factor
        regVal = regVal - 1;
        if(regVal <= 0xFFFF){
            U1CON0bits.BRGS = 0;
        } else {
            //Nothing else to try
            return STAT_FAIL;
        }
    }
    U1BRGH = (uint8_t)(0xFF & (regVal>>8));
    U1BRGL = (uint8_t)(0xFF & regVal);   //68 -> 115200

    U1CON1bits.WUE = 0;   //Disable Wake-Up-Enable
    U1CON0bits.ABDEN = 0; //Disable AutoBaud
        
    if(use_tx){
        // SETUP THE TRANSMITTER
        uart1_tx_buff_tail = 0;
        uart1_tx_buff_head = 0;
        uart1_tx_buff_full = false;
        for(uint16_t i = 0; i < 256; i++){
            uart1_tx_buff[i] = 0;
        }
        uart1_tx_sys_active = true;
    } else {
        uart1_tx_sys_active = false;
    }
    
    if(use_rx){
        // SETUP THE RECEIVER
        U1CON0bits.RXEN = 1;    //Continuous RX Enabled
        for(uint8_t i = 0; i < UART1_RX_BUFF_SIZE; i++){
            uart1_rx_buff_isr[i] = 0;
            uart1_rx_buff_use[i] = 0;
        }
        uart1_rx_buff_idx = 0;
        uart1_rx_msg_present = false;
        uart1_rx_sys_active = true;
        U1RXIF = 0;   //clear any pending interrupt before enabling
        U1RXIE = 1;   //enable the RX Interrupt
    } else {
        uart1_rx_sys_active = false;
    }
    
    if(use_tx || use_rx)
        U1CON1bits.ON = 1;      //Enable the UART
    
    return STAT_SUCCESS;
}

STATUS_T uart1_tx_str(char * in_bytes)
{
    U1TXIE = 0;   //disable TXinterrupt for thread protection
    U1TXEN = 0;   //disable TXenable for thread protection
    if((uart1_tx_buff_tail != uart1_tx_buff_head) || !uart1_tx_buff_full){                     //  |eeeeeetailfffffffheadeeeeee| or |ffffffheadeeeeeeetailffffff|
        if(((uart1_tx_buff_tail - uart1_tx_buff_head) >= strlen(in_bytes)) || ((uart1_tx_buff_head == uart1_tx_buff_tail) && !uart1_tx_buff_full)){       // if tail = 10 and head = 200, tail - head = -190 => 66 due to byte saturation, 66 empty bytes
            for(uint8_t i = 0; i < strlen(in_bytes); i++){                        // if tail = 200 and head = 10, tail - head = 190, 190 empty bytes
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
        U1TXIE = 1;   //enable TXinterrupt for thread protection
        U1TXEN = 1;   //enable TXenable for thread protection
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
#endif