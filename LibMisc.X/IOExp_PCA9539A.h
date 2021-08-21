/* 
 * File:   IOExp_PCA9539A.h
 * Author: dev-user
 *
 * Created on October 9, 2020, 9:07 AM
 */

#ifndef IOEXP_PCA9539A_H
#define	IOEXP_PCA9539A_H

#ifdef __PIC32M
#include "../IncSystemDefs/PICDEFS32.h"
#include "../Lib32Peripherals.X/I2C.h"
#else
#include "../IncSystemDefs/PICDEFS.h"
#include "../LibPeripherals.X/mssp.h"
#include "../LibPeripherals.X/i2c.h"
#endif

#ifdef	__cplusplus
extern "C" {
#endif

    typedef union {
        struct {
            unsigned nibbleL    :4;
            unsigned nibbleH    :4;
        };
        struct {
            unsigned val        :8;
        };
        struct {
            unsigned b0         :1;
            unsigned b1         :1;
            unsigned b2         :1;
            unsigned b3         :1;
            unsigned b4         :1;
            unsigned b5         :1;
            unsigned b6         :1;
            unsigned b7         :1;
        };
    } IOEXP_SUBBYTE_T;
    
    typedef struct {
        volatile uint8_t Addr;   //must be 7-bit left aligned in the byte (the lowest bit is the R/~W bit)
        volatile IOEXP_SUBBYTE_T P0IVal;
        volatile IOEXP_SUBBYTE_T P0OVal;
        volatile IOEXP_SUBBYTE_T P0Inv;
        volatile IOEXP_SUBBYTE_T P0Dir;
        volatile IOEXP_SUBBYTE_T P1IVal;
        volatile IOEXP_SUBBYTE_T P1OVal;
        volatile IOEXP_SUBBYTE_T P1Inv;
        volatile IOEXP_SUBBYTE_T P1Dir;
    } IOEXP_PCA9539_T;
    
    enum IOEXP_PORTENUM {
        P0 = 0,
        P1,
        BOTH
    };
    
    //Exposed functions
STATUS_T IOExpSetup(IOEXP_PCA9539_T *ioexp_inst, uint8_t set_addr, uint8_t set_dir_p0, uint8_t set_dir_p1, uint8_t set_inv_p0, uint8_t set_inv_p1, uint8_t set_oval_p0, uint8_t set_oval_p1);
//STATUS_T IOExpSetup(IOEXP_PCA9539_T *ioexp_inst, uint8_t set_addr, uint16_t set_dir, uint16_t set_inv, uint16_t set_oval);
STATUS_T IOExpUpdateOut(IOEXP_PCA9539_T *ioexp_inst, uint16_t set_oval);
STATUS_T IOExpUpdateIn(IOEXP_PCA9539_T *ioexp_inst);
STATUS_T IOExpUpdateOutPart(IOEXP_PCA9539_T *ioexp_inst, uint8_t set_oval, uint8_t port_num);
STATUS_T IOExpUpdateAll(IOEXP_PCA9539_T *ioexp_inst);

//These functions are only used internally
//STATUS_T IOExpWriteDir(IOEXP_PCA9539_T ioexp_inst, enum IOEXP_PORTENUM portSel);
//STATUS_T IOExpWriteInv(IOEXP_PCA9539_T ioexp_inst, enum IOEXP_PORTENUM portSel);
//STATUS_T IOExpWriteVal(IOEXP_PCA9539_T ioexp_inst, enum IOEXP_PORTENUM portSel);
//
//STATUS_T IOExpReadDir(IOEXP_PCA9539_T ioexp_inst, enum IOEXP_PORTENUM portSel);
//STATUS_T IOExpReadInv(IOEXP_PCA9539_T ioexp_inst, enum IOEXP_PORTENUM portSel);
//STATUS_T IOExpReadIVal(IOEXP_PCA9539_T ioexp_inst, enum IOEXP_PORTENUM portSel);
//STATUS_T IOExpReadOVal(IOEXP_PCA9539_T ioexp_inst, enum IOEXP_PORTENUM portSel);


#ifdef	__cplusplus
}
#endif

#endif	/* IOEXP_PCA9539A_H */

