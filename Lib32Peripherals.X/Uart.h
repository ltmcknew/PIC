/* 
 * File:   Uart.h
 * Author: dev-user
 *
 * Created on October 23, 2020, 1:50 PM
 */

#ifndef UART_H
#define	UART_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "../IncSystemDefs/PICDEFS32.h"
#include <sys/attribs.h>
#include <string.h>
    
#ifdef __USE_UART1__
uint8_t uart1_tx_buff_tail;    //first available byte slot for new data
uint8_t uart1_tx_buff_head;    //first byte to read when pulling data out the buffer
bool uart1_tx_buff_full;       //handle case where the head and tail are equal, differentiate between buffer entirely full or entirely empty
uint8_t uart1_tx_buff[256];
bool uart1_tx_sys_active;      //flag for whether tx has been configured

#define UART1_RX_BUFF_SIZE   64
uint8_t uart1_rx_buff_isr[UART1_RX_BUFF_SIZE];
uint8_t uart1_rx_buff_use[UART1_RX_BUFF_SIZE];
uint8_t uart1_rx_buff_idx;
uint8_t uart1_rx_buff_load_cnt;
bool uart1_rx_msg_present; 
bool uart1_rx_sys_active;      //flag for whether tx has been configured

STATUS_T UART1Setup(uint32_t set_baud, bool use_tx, bool use_rx);

STATUS_T uart1_tx_str(char * in_bytes);
STATUS_T uart1_tx_str_crlf(char * in_bytes);
void uart1_wait(void);
#endif



#ifdef	__cplusplus
}
#endif

#endif	/* UART_H */

