/* 
 * File:   eusart.h
 * Author: dev-user
 *
 * Created on September 11, 2020, 9:30 PM
 */

#ifndef EUSART_H
#define	EUSART_H

#include "../IncSystemDefs/PICDEFS.h"

#ifdef	__cplusplus
extern "C" {
#endif

#ifdef __USE_EUSART__
uint8_t eusart_tx_buff_tail;    //first available byte slot for new data
uint8_t eusart_tx_buff_head;    //first byte to read when pulling data out the buffer
bool eusart_tx_buff_full;       //handle case where the head and tail are equal, differentiate between buffer entirely full or entirely empty
uint8_t eusart_tx_buff[256];
bool eusart_tx_sys_active;      //flag for whether tx has been configured

#define EUSART_RX_BUFF_SIZE   64
uint8_t eusart_rx_buff_isr[EUSART_RX_BUFF_SIZE];
uint8_t eusart_rx_buff_use[EUSART_RX_BUFF_SIZE];
uint8_t eusart_rx_buff_idx;
uint8_t eusart_rx_buff_load_cnt;
bool eusart_rx_msg_present; 
bool eusart_rx_sys_active;      //flag for whether tx has been configured

STATUS_T EUSARTSetup(uint32_t set_baud, bool use_tx, bool use_rx);

STATUS_T load_tx_msg_str(char * in_bytes);
STATUS_T load_tx_msg_str_crlf(char * in_bytes);
#endif

#ifdef	__cplusplus
}
#endif

#endif	/* EUSART_H */

