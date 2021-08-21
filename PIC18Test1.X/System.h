/* 
 * File:   System.h
 * Author: dev-user
 *
 * Created on October 12, 2020, 10:38 AM
 */

#ifndef SYSTEM_H
#define	SYSTEM_H

#ifdef	__cplusplus
extern "C" {
#endif

//#define __STEPPERSYSTEM_V2__
    
#include <xc.h>
#include <ctype.h>
#include <stdlib.h>
#include "configbits.h"
#include "../IncSystemDefs/PICDEFS.h"

#include "../LibPeripherals.X/timers.h"
#include "../LibPeripherals.X/uart.h"
//    
#include "../LibOutputDevices.X/disp_7seg4dig.h"
//#include "../LibOutputDevices.X/stepper.h"
    
#include "../LibMisc.X/IOExp_PCA9539A.h"
    
void SetupClk(void);
STATUS_T SysInit(void);
STATUS_T make_all_digital(void);

//void interpretRX(void);

volatile uint32_t sys_time;
volatile uint8_t sys_stat;
bool halfSecondTrigger;
bool twoSecondTrigger;

volatile IOEXP_PCA9539_T ioexp1;


#ifdef	__cplusplus
}
#endif

#endif	/* SYSTEM_H */

