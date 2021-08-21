/* 
 * File:   stepper.h
 * Author: dev-user
 *
 * Created on September 29, 2020, 8:55 PM
 */

#ifndef STEPPER_H
#define	STEPPER_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "../SystemDefs/PICDEFS.h"
#include "../Peripherals/timers.h"
    
uint8_t Steps;
bool Direction;
int16_t totalSteps;
STATUS_T setupStepper(void);
//STATUS_T stepMotor(int16_t steps);
void stepper(int xw);
void SetDirection(void);


#ifdef	__cplusplus
}
#endif

#endif	/* STEPPER_H */

