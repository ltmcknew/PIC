/* 
 * File:   servo.h
 * Author: dev-user
 *
 * Created on September 29, 2020, 2:07 PM
 */

#ifndef SERVO_H
#define	SERVO_H

#ifdef	__cplusplus
extern "C" {
#endif

#ifdef __PIC32M
#include "../IncSystemDefs/PICDEFS32.h"
#include "../Lib32Peripherals.X/Timers.h"
#else
#include "../IncSystemDefs/PICDEFS.h"
#include "../LibPeripherals.X/timers.h"
#endif 
    
#ifdef __USE_SERVO__
// for PIC18 & PIC16
//use Timer1 to interrupt when it's time to clear the output pin
//use Timer2 to trigger the pulse at 50Hz.
// else (PIC32)
//use Timer2 to trigger output clearing after delay when pulse is applied
//use Timer3 to trigger the pulse at 50Hz.
int16_t servoAngleUse;
uint32_t servoTimeVal;
int32_t servoCnts;
STATUS_T setupServo(int8_t initAngle);
STATUS_T setServoAngle(int8_t setAngle);
void servoStartPulseTimer(void);
void servoEndPulse(void);
#endif

#ifdef	__cplusplus
}
#endif

#endif	/* SERVO_H */

