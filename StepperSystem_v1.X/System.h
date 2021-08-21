/* 
 * File:   System.h
 * Author: dev-user
 *
 * Created on September 30, 2020, 10:57 AM
 */

#ifndef SYSTEM_H
#define	SYSTEM_H

#ifdef	__cplusplus
extern "C" {
#endif

//#define __STEPPERSYSTEM_V1__
    
#include <xc.h>
#include "configbits.h"
#include "../IncSystemDefs/PICDEFS.h"

#include "../LibPeripherals.X/timers.h"    
    
#include "../LibOutputDevices.X/disp_7seg4dig.h"
#include "../LibOutputDevices.X/stepper.h"
    
void SetupClk(void);

STATUS_T SysInit(void);

STATUS_T make_all_digital(void);

volatile uint32_t sys_time;
volatile uint8_t sys_stat;
bool twoSecondTrigger;

//struct STEPPER Stp1;
//struct STEPPER Stp2;


#ifdef	__cplusplus
}
#endif

#endif	/* SYSTEM_H */

