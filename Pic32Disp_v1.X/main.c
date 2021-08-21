/*
 * File:   main.c
 * Author: dev-user
 *
 * Created on October 30, 2020, 2:08 PM
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
    uart1_wait();

//    OledDrawFastVLine(100,0,64,WHITE);
//    OledDrawFastHLine(0,16,128,WHITE);
//    OledDrawLine(0,16,127,63,WHITE);
//    OledDrawRect(0,16,127,63-16,WHITE);
//    OledFillRect(0,16,127,63-16,WHITE);
//    OledFillScreen(WHITE);
    OledDrawCircle(64,40,20,WHITE);
//    OledFillCircle(64,40,16,WHITE);
//    OledDrawTriangle(0,63,64,16,127,63,WHITE);
//    OledFillTriangle(0,63,64,16,127,63,WHITE);
//    OledDrawRoundRect(14,20,100,40,10,WHITE);
//    OledFillRoundRect(14,20,100,40,10,WHITE);
//    OledDim(false);
//    OledDrawBitmap(64-20,40-20,globe_bmp,40,39,WHITE,BLACK);
    OledDrawGlobe();
    sprintf(msg_buff,"Pic32Disp_v1");
    OledDrawString(0,0,msg_buff);
    
    while(running){
        WDTCONCLR = _WDTCON_WDTCLR_MASK;
        
        if(sys_twoseconds){
            sys_twoseconds = false;
            
            sprintf(msg_buff,"System Time: %lu",sys_time/1000);
            uart1_tx_str_crlf(msg_buff);
            OledDrawString(0,8,msg_buff);
            
//            if(sys_time/1000%4 == 0){
//                OledStopScroll();
//            } else {
//                OledStartScrollDiagLeft(0,127);
//            }

        }
        
        if(uart1_rx_msg_present){
            uart1_tx_str_crlf(uart1_rx_buff_use);
//            interpretRX();
            uart1_rx_msg_present = false;
        }
    }
    
    return;
}

