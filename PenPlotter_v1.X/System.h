/* 
 * File:   System.h
 * Author: dev-user
 *
 * Created on November 19, 2020, 1:30 PM
 */

#ifndef SYSTEM_H
#define	SYSTEM_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include "../IncSystemDefs/PICDEFS32.h"
#include "../Lib32Peripherals.X/Timers.h"
#include "../Lib32Peripherals.X/Uart.h"
    
#include "../LibOutputDevices.X/servo.h"
#include "../LibOutputDevices.X/stepper.h"
#include "../LibOutputDevices.X/Oled.h"

#include <string.h>
#include <stdlib.h>
    
#define MAX_INPUT_FIELDS 5
    
volatile uint32_t sys_time;
uint16_t sys_stat;
bool running;

float stepper_dist_to_steps;

bool sys_twoseconds;

STATUS_T CheckClocks();
STATUS_T AllDigital();
STATUS_T SysInit();
void interpretRX(void);

typedef union {
    struct {
        float x;
        float y;
        float z;
    };
} Point3F_T;

Point3F_T path[4];
bool startPath;

#ifdef	__cplusplus
}
#endif

#endif	/* SYSTEM_H */

