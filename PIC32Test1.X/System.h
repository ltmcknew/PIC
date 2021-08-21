/* 
 * File:   System.h
 * Author: dev-user
 *
 * Created on October 21, 2020, 9:57 AM
 */

#ifndef SYSTEM_H
#define	SYSTEM_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "../IncSystemDefs/PICDEFS32.h"
#include "../Lib32Peripherals.X/Timers.h"
#include "../Lib32Peripherals.X/Uart.h"
//#include "../Lib32Peripherals.X/I2C.h"
//#include "../LibMisc.X/IOExp_PCA9539A.h"
#include "../LibOutputDevices.X/stepper.h"

#include <string.h>
#include <stdlib.h>
    
volatile uint32_t sys_time;
uint16_t sys_stat;
bool running;

bool sys_twoseconds;

//IOEXP_PCA9539_T ioexp1;

STATUS_T CheckClocks();
STATUS_T AllDigital();
STATUS_T SysInit();
void interpretRX(void);


#ifdef	__cplusplus
}
#endif

#endif	/* SYSTEM_H */

