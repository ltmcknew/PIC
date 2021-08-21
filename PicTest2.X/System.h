/* 
 * File:   System.h
 * Author: dev-user
 *
 * Created on September 25, 2020, 1:54 PM
 */

#ifndef SYSTEM_H
#define	SYSTEM_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <xc.h>
#include "configbits.h"
#include "../IncSystemDefs/PICDEFS.h"
    
//#include "../Peripherals/eusart.h"
#include "../LibPeripherals.X/timers.h"
//#include "../Peripherals/ccppwm.h"
    
#include "../LibSensors.X/dht11.h"
//#include "../LibSensors.X/ir_dist.h"
    
#include "../LibOutputDevices.X/disp_7seg4dig.h"
//#include "../LibOutputDevices.X/servo.h"
#include "../LibOutputDevices.X/stepper.h"
    
void SetupClk(void);

STATUS_T SysInit(void);

STATUS_T make_all_digital(void);

volatile uint32_t sys_time;
volatile uint8_t sys_stat;

//TmrEven_T tmr4;



#ifdef	__cplusplus
}
#endif

#endif	/* SYSTEM_H */

