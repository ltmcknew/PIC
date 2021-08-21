/* 
 * File:   mssp.h
 * Author: dev-user
 *
 * Created on October 8, 2020, 2:58 PM
 */

#ifndef MSSP_H
#define	MSSP_H

#include "../IncSystemDefs/PICDEFS.h"

#ifdef	__cplusplus
extern "C" {
#endif

    /* Generic MSSP System, currently I2C Master mode is implemented
     * 
     * I2C Master Mode:
     *      Write Example:
     *          MSSP1_buff_out[0] = 0xA5;   //load first data byte
     *          MSSP1_buff_out[1] = 0x69;   //load second data byte
     *          MSSP1Write(2,0xE8);         //write address then 2 data bytes
     * 
     */
    
    
//#define __USE_MSSP1__
//#define __MSSP1_I2C__
    
#ifdef __USE_MSSP1__
#define MSSP_BUFF_SIZE 64
int16_t  MSSP1_buff_idx;
uint8_t  MSSP1_buff_in[MSSP_BUFF_SIZE];
uint8_t  MSSP1_buff_out[MSSP_BUFF_SIZE];

#ifdef __MSSP1_I2C__
STATUS_T MSSP1SetupI2C(bool high_speed, bool use_tx, bool use_rx); 
#endif
#ifdef __MSSP1_SPI__
STATUS_T MSSP1SetupSPI(uint32_t sck_freq, bool use_tx, bool use_rx);
#endif
STATUS_T MSSP1Enable(void);
STATUS_T MSSP1Disable(void);
uint8_t MSSP1Read(uint8_t byteCnt, uint8_t devAddr);
uint8_t MSSP1Write(uint8_t byteCnt, uint8_t devAddr);
uint8_t MSSP1WrRd(uint8_t wrCnt, uint8_t rdCnt, uint8_t devAddr);
#endif
    
#ifdef _USE_MSSP2_
#endif


#ifdef	__cplusplus
}
#endif

#endif	/* MSSP_H */

