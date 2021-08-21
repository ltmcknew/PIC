/* 
 * File:   i2c.h
 * Author: dev-user
 *
 * Created on October 9, 2020, 11:45 PM
 */

#ifndef I2C_H
#define	I2C_H

#include "../IncSystemDefs/PICDEFS.h"
#include "timers.h"

//#include "uart.h"

#ifdef	__cplusplus
extern "C" {
#endif

    
/*
 *  Examples for Use:
 * 
 *  //write two bytes beginning at address 0x06
 *  I2C1_buff_out[0] = 0x06;
 *  I2C1_buff_out[1] = 0x00;
 *  I2C1_buff_out[2] = 0x00;
 *  I2C1Write(3,0xE8);
 * 
 *  //manually write byte address then read 2 bytes
 *  I2C1_buff_out[0] = 0x06;
 *  I2C1Write(1,0xE8);
 *  __delay_ms(1);
 *  I2C1Read(2,0xE8);
 * 
 *  //perform write then read using function
 *  I2C1_buff_out[0] = 0x00;    //set address to write as write portion
 *  I2C1WrRd(1,2,0xE8);         //indicate to write 1 byte, then read 2 bytes and provide IC's I2C address
 * 
 */
    
//#define __USE_I2C1__
#ifdef __USE_I2C1__         //uses Timer6 internally
#define I2C_BUFF_SIZE 64
bool     I2C1_use_highspeed;
int16_t  I2C1_buff_idx;
uint8_t  I2C1_buff_in[I2C_BUFF_SIZE];
uint8_t  I2C1_buff_out[I2C_BUFF_SIZE];

STATUS_T I2C1Setup(bool high_speed); 
STATUS_T I2C1Enable(void);
STATUS_T I2C1Disable(void);
uint8_t I2C1Write(uint8_t byteCnt, uint8_t devAddr);
uint8_t I2C1Read(uint8_t byteCnt, uint8_t devAddr);
uint8_t I2C1WrRd(uint8_t wrCnt, uint8_t rdCnt, uint8_t devAddr);
#endif


#ifdef	__cplusplus
}
#endif

#endif	/* I2C_H */




/* TODO: Attempt to make this work without needing to wait and block. Here's a state machine from online at:
 *      https://www.microchip.com/forums/m1066475.aspx
 * 
 * 
   void i2c_mach (void) {
    switch (i2c_st) {

    case i2c_next:
        if (i2c_scan_cmd) {
            i2c_st    = i2c_scan1;
        } else if (i2c_read_cmd) {
            i2c_read_cmd = 0;
            i2caddr    = (uint8_t)(i2c_rcbfr.addr << 1u);
            i2c_reg    = i2c_rcbfr.reg;
            i2c_cnt    = i2c_rcbfr.cnt;
            i2c_st    = i2c_rstart;
        } else if (i2c_hd != i2c_tl) {
            i2caddr = i2c_wcbfr[i2c_tl].addr;
            i2c_reg = i2c_wcbfr[i2c_tl].reg;
            i2c_val.bt[0] = i2c_wcbfr[i2c_tl].val;
            i2c_tl    = (i2c_tl + 1u) MOD_WCBFR_SIZE;
            i2c_st    = i2c_wstart;
        }
        break;
 
    case i2c_rstart:
        if (I2C1STAT0bits.MMA == 0) {    // if I2C not busy
            I2C1ADB1    = i2caddr;        // write operation first
            I2C1CNT        = 1;            // eeadr (0) + ptr (1)
            I2C1TXB        = i2c_reg;        // register ptr
            I2C1CON0bits.S    = 1;        // start the transfer
            CNT1IF        = 0;            // I don't think this is actually needed
            i2cfault    = 0;
            i2c_st        = i2c_rd;
        }
        break;
    case i2c_rd:
        if (I2C1STAT0bits.MMA == 0) {
            if (I2C1CON1bits.ACKSTAT == 1) {    // no ack received
                I2C1STAT1bits.CLRBF    = 1;        // clear buffer since no ack
                i2cfault= 1;
                i2c_st    = i2c_next;
            } else {
                I2C1ADB1    |= 1;            // read operation
                if (i2c_cnt == 2) {            // read 2 bytes
                    I2C1CNT        = 2;            // read 2 bytes
                    I2C1CON0bits.S    = 1;        // start the transfer
                    i2c_st        = i2c_datah;
                } else {                    // else read only 1
                    i2c_val.bt[1]    = 0;        // clear top byte
                    I2C1CNT            = 1;        // read 1 byte
                    I2C1CON0bits.S    = 1;        // start the transfer
                    i2c_st        = i2c_datal;
                }
            }
        }
        break;
    case i2c_datah:
        if (I2C1STAT1bits.RXBF) {
            if (I2C1CON1bits.ACKSTAT == 1) {    // no ack received
                I2C1STAT1bits.CLRBF    = 1;        // clear buffer since no ack
                i2cfault = 1;
                i2c_st    = i2c_error;        // error state?
            } else {
                i2c_val.bt[1]     = I2C1RXB;
                i2c_st            = i2c_datal;
            }
        }
        break;
    case i2c_datal:
        if (I2C1STAT1bits.RXBF) {
            if (I2C1CON1bits.ACKSTAT == 1) {    // no ack received
                I2C1STAT1bits.CLRBF    = 1;        // clear buffer since no ack
                i2cfault = 1;
                i2c_st    = i2c_error;        // error state?
            } else {
                i2c_val.bt[0]    = I2C1RXB;
                i2c_rdone        = 1;    
                i2c_st            = i2c_done;
            }
        }
        break;
    

    case i2c_wstart:
        if (I2C1STAT0bits.MMA == 0) {    // if I2C not busy
            I2C1ADB1    = i2caddr;        // write operation
            I2C1CNT        = 2;            // eeadr (0) + ptr (1) + data (1)
            I2C1TXB        = i2c_reg;        // register ptr
            I2C1CON0bits.S    = 1;        // start the transfer
            CNT1IF        = 0;
            i2cfault    = 0;
            i2c_st        = i2c_wr1;
        }
        break;
    case i2c_wr1:
        if (I2C1STAT1bits.TXBE) {
            if (I2C1CON1bits.ACKSTAT == 1) {    // no ack received
                I2C1CNT        = 0;
                I2C1STAT1bits.CLRBF    = 1;        // clear buffer since no ack
                i2cfault    = 1;
                i2c_st        = i2c_error;    
            } else {
                I2C1TXB        = i2c_val.bt[0];
                i2c_st        = i2c_wr2;
            } 
        }
        break;
    case i2c_wr2:
        if (I2C1STAT0bits.MMA == 0) {
            if (I2C1CON1bits.ACKSTAT == 1) {    // no ack received
                I2C1CNT = 0;
                I2C1STAT1bits.CLRBF    = 1;        // clear buffer since no ack
                i2cfault    = 1;
                i2c_st    = i2c_error;    
            } else {
                i2c_st    = i2c_next;
            }
        }
        break;
        
        
    case i2c_error:
        if (i2cfault) {
            printf("i2c 0x%02x fault\n", (uint16_t)i2caddr);
            i2cfault = 0;
        }
        i2c_st = i2c_next;
        break;

    case i2c_done:
        if (i2c_rdone) {
            printf("i2c read a 0x%02x d 0x%02x\n",
                (uint16_t)i2caddr, i2c_val.wd);
            i2c_rdone = 0;
        }
        i2c_st = i2c_next;
        break;

    default:
        i2c_st    = i2c_next;
        break;
    }
}
 */