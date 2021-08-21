/* 
 * File:   System.h
 * Author: dev-user
 *
 * Created on October 27, 2020, 11:00 AM
 */

#ifndef SYSTEM_H
#define	SYSTEM_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "../IncSystemDefs/PICDEFS32.h"
//#include "PICDEFS32.h"
#include "../Lib32Peripherals.X/Timers.h"
#include "../Lib32Peripherals.X/Uart.h"
    
#include "../LibOutputDevices.X/stepper.h"
#include "../LibOutputDevices.X/Oled.h"

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


//uint8_t oled_addr;
//STATUS_T OledInit(uint8_t setAddr);
//STATUS_T OledCmdOnly(uint8_t cmd);
//STATUS_T OledCmdData(uint8_t cmd, uint8_t data);
//STATUS_T OledCmdData2(uint8_t cmd, uint8_t data1, uint8_t data2);
//STATUS_T OledWriteDisplay(void);

#ifdef	__cplusplus
}
#endif

#endif	/* SYSTEM_H */



