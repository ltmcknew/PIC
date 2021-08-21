#include "eusart.h"

#ifdef __USE_EUSART__
STATUS_T EUSARTSetup(uint32_t set_baud, bool use_tx, bool use_rx)
{
    // SETUP THE PINS
    RXPPS = EUSART_RX_PPS_VAL;
    EUSART_RX_TRIS = 1;
    
    EUSART_TX_PPS = 0x10;
    EUSART_TX_TRIS = 1;

    // DISABLE THE PORT BEFORE CONFIGURATION
    RC1STAbits.SPEN = 0;    //disable whole port for init
    RC1STAbits.CREN = 0;    //disable RX
    TX1STAbits.TXEN = 0;    //disable TX
    
    // SETUP THE BAUDRATE
    //Select 115200, depends on BRGH = 1 & BRG16 = 1, Value given by RegVal = Fosc/X/DesiredBaud - 1, RegVal can be 16 bit in SP1BRGH:SP1BRGL, X is either 64, 16 or 4 depeding on BGRH and BGR16
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
        TX1STAbits.BRGH = 1;
        BAUD1CONbits.BRG16 = 1;
    } else {
        //try Fosc/16, assume 16bit SP1BRG value still
        regVal = (regVal+1)/4; //add the one back and the previous value just needs to be divided by 4 to account for the new factor
        regVal = regVal - 1;
        if(regVal <= 0xFFFF){
            TX1STAbits.BRGH = 0;
            BAUD1CONbits.BRG16 = 1;
        } else {
            //Can only go to Fosc/64 now, repeat the previous steps
            regVal = (regVal+1)/4; //add the one back and the previous value just needs to be divided by 4 to account for the new factor
            regVal = regVal - 1;
            if(regVal > 255){
                return STAT_FAIL;   //invalid baudrate input, it won't fit in the register
            }
            TX1STAbits.BRGH = 0;
            BAUD1CONbits.BRG16 = 0;
        }
    }
    SP1BRGH = (uint8_t)(0xFF & (regVal>>8));
    SP1BRGL = (uint8_t)(0xFF & regVal);   //68 -> 115200

    BAUD1CONbits.WUE = 0;   //Disable Wake-Up-Enable
    BAUD1CONbits.ABDEN = 0; //Disable AutoBaud
    TX1STAbits.SYNC = 0;    //Asynchronous mode for whole EUSART
        
    if(use_tx){
        // SETUP THE TRANSMITTER
        TX1STAbits.TX9 = 0; //8-bit mode, Leave TXEN off until there is data to send
        BAUD1CONbits.SCKP = 0;  //TX Idle State is High
        eusart_tx_buff_tail = 0;
        eusart_tx_buff_head = 0;
        eusart_tx_buff_full = false;
        for(uint16_t i = 0; i < 256; i++){
            eusart_tx_buff[i] = 0;
        }
        eusart_tx_sys_active = true;
    } else {
        eusart_tx_sys_active = false;
    }
    
    if(use_rx){
        // SETUP THE RECEIVER
        RC1STAbits.CREN = 1;    //Continuous RX Enabled
        for(uint8_t i = 0; i < EUSART_RX_BUFF_SIZE; i++){
            eusart_rx_buff_isr[i] = 0;
            eusart_rx_buff_use[i] = 0;
        }
        eusart_rx_buff_idx = 0;
        eusart_rx_msg_present = false;
        eusart_rx_sys_active = true;
        RCIF = 0;   //clear any pending interrupt before enabling
        RCIE = 1;   //enable the RX Interrupt
    } else {
        RC1STA = 0b00000000;    //SP Disabled, 8-bit mode, Don't Care, Continuous RX Disabled, Don't Care, R/O, R/O, R/O
        eusart_rx_sys_active = false;
    }
    
    if(use_tx || use_rx)
        RC1STAbits.SPEN = 1;    //Enable the EUSART
    
    return STAT_SUCCESS;
}

STATUS_T load_tx_msg_str(char * in_bytes)
{
    TXIE = 0;   //disable TXinterrupt for thread protection
    TXEN = 0;   //disable TXenable for thread protection
    if((eusart_tx_buff_tail != eusart_tx_buff_head) || !eusart_tx_buff_full){                     //  |eeeeeetailfffffffheadeeeeee| or |ffffffheadeeeeeeetailffffff|
        if(((eusart_tx_buff_tail - eusart_tx_buff_head) >= strlen(in_bytes)) || ((eusart_tx_buff_head == eusart_tx_buff_tail) && !eusart_tx_buff_full)){       // if tail = 10 and head = 200, tail - head = -190 => 66 due to byte saturation, 66 empty bytes
            for(uint8_t i = 0; i < strlen(in_bytes); i++){                        // if tail = 200 and head = 10, tail - head = 190, 190 empty bytes
                eusart_tx_buff[eusart_tx_buff_head++] = in_bytes[i];    //load data byte-by-byte into buffer
            }
            if(eusart_tx_buff_head == eusart_tx_buff_tail){
                eusart_tx_buff_full = true;
            }
        } else {    //not enough space to load the message
            return STAT_FAIL;
        }
    } else {              
        //reset the buffer?
    }
    
    if((eusart_tx_buff_head != eusart_tx_buff_tail) || (eusart_tx_buff_full)){
        TXIE = 1;   //enable TXinterrupt for thread protection
        TXEN = 1;   //enable TXenable for thread protection
    }
    
    return STAT_SUCCESS;
}

STATUS_T load_tx_msg_str_crlf(char * in_bytes)
{
    STATUS_T res = STAT_SUCCESS;
            
    if(EUSART_RX_BUFF_SIZE > (strlen(in_bytes)+2)){
        char new_buff[EUSART_RX_BUFF_SIZE];
        strcpy(new_buff,in_bytes);
        strcat(new_buff,"\n\r");
        
        return load_tx_msg_str(new_buff);
    }
    
    return load_tx_msg_str(in_bytes);
}
#endif