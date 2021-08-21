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

#include "../SystemDefs/PICDEFS.h"
#include "../Peripherals/timers.h"
    
    
//use Timer1 to interrupt when it's time to clear the output pin
//use Timer2 to trigger the pulse at 50Hz.
int8_t servoAngleUse;
uint32_t servoTimeVal;
int32_t servoCnts;
STATUS_T setupServo(int8_t initAngle);
STATUS_T setServoAngle(int8_t setAngle);
void servoStartPulseTimer(void);
void servoEndPulse(void);


#ifdef	__cplusplus
}
#endif

#endif	/* SERVO_H */

