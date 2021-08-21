/* 
 * File:   System.h
 * Author: dev-user
 *
 * Created on October 30, 2020, 2:07 PM
 */

#ifndef SYSTEM_H
#define	SYSTEM_H

#ifdef	__cplusplus
extern "C" {
#endif


#include "../IncSystemDefs/PICDEFS32.h"
#include "../Lib32Peripherals.X/Timers.h"
#include "../Lib32Peripherals.X/Uart.h"
#include "../Lib32Peripherals.X/I2C.h"
    
#include "../LibOutputDevices.X/Oled.h"
//#include "Oled.h"

#include <string.h>
#include <stdlib.h>
    
volatile uint32_t sys_time;
uint16_t sys_stat;
bool running;

bool sys_twoseconds;

//SSD1306_T oled_disp;

STATUS_T CheckClocks();
STATUS_T AllDigital();
STATUS_T SysInit();
void interpretRX(void);


#ifdef	__cplusplus
}
#endif

#endif	/* SYSTEM_H */

