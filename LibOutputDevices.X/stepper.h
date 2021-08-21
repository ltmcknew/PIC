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

#ifdef __PIC32M
#include "../IncSystemDefs/PICDEFS32.h"
#include "../Lib32Peripherals.X/Timers.h"
#else
#include "../IncSystemDefs/PICDEFS.h"
#include "../LibPeripherals.X/timers.h"
#endif
    
#include "../LibMisc.X/IOExp_PCA9539A.h"
    
#define STEPPER_FULLROTATION    4096
    
#ifdef __USE_STEPPER__
#ifdef __USE_STEPPER0__
//use Timer2 to interrupt when applying a step is valid (lockout steps during 800us immediately following step)
uint8_t stepOutVal0; //set of 4 bits that indicate the pin states
bool stepOutShift0;  //whether to shift the output value to the high 4 bits or leave it in the low 4 bits of the output byte, only necessary in I2C mode
int8_t stepState0;   //state machine step selection, range [0:7], indicates which pin/pair of pins will be active for the current step
bool stepDirection0; //state machine next step determination, if true increment step, if false decrement step
int32_t totalSteps0; //track total number of steps output to motor, signed to record steps in each direction, provide method to zero and this can track total rotation of motor
bool allowStep0;     //lockout steps for 800us after a new step is output
int16_t pendingSteps0;   //count of pending steps to complete, add or subtract from here to rotate one way or the other and the interrupt system will allow steps to be applied until this value equals zero
STATUS_T setupStepper0(void);   //initialization run on startup
#ifdef __STEPPER_GPIO__
void stepper0ISR(void);
#elif defined(__STEPPER_I2C__)
#ifndef __PIC32M
void __interrupt(__irq(TMR1),high_priority) stepper0ISR(void);
#endif
#endif
STATUS_T stepSMachine0(void);   //routine here for running the state machine so main doesn't have to know the deets
STATUS_T stepMotor0(void);      //output one step depending on pendingSteps value
STATUS_T stepMotorFixed0(int16_t steps); //output a fixed number of steps, loop internally
STATUS_T stepMotorSM0(void);    //stepper state machine, set the output pins based on the stepState value
STATUS_T updateStepState0(void);//increment or decrement stepState based on previous state and desired step direction
#endif

#ifdef __USE_STEPPER1__
//use Timer3 to interrupt when applying a step is valid (lockout steps during 800us immediately following step)
uint8_t stepOutVal1; //set of 4 bits that indicate the pin states
bool stepOutShift1;  //whether to shift the output value to the high 4 bits or leave it in the low 4 bits of the output byte, only necessary in I2C mode
int8_t stepState1;   //state machine step selection, range [0:7], indicates which pin/pair of pins will be active for the current step
bool stepDirection1; //state machine next step determination, if true increment step, if false decrement step
int32_t totalSteps1; //track total number of steps output to motor, signed to record steps in each direction, provide method to zero and this can track total rotation of motor
bool allowStep1;     //lockout steps for 800us after a new step is output
int16_t pendingSteps1;   //count of pending steps to complete, add or subtract from here to rotate one way or the other and the interrupt system will allow steps to be applied until this value equals zero
STATUS_T setupStepper1(void);    //initialization run on startup
#ifdef __STEPPER_GPIO__
void stepper1ISR(void);
#elif defined(__STEPPER_I2C__)
#ifndef __PIC32M
void __interrupt(__irq(TMR3),high_priority) stepper1ISR(void);
#endif
#endif
STATUS_T stepSMachine1(void);   //routine here for running the state machine so main doesn't have to know the deets
STATUS_T stepMotor1(void);       //output one step depending on pendingSteps value
STATUS_T stepMotorFixed1(int16_t steps); //output a fixed number of steps, loop internally
STATUS_T stepMotorSM1(void);     //stepper state machine, set the output pins based on the stepState value
STATUS_T updateStepState1(void); //increment or decrement stepState based on previous state and desired step direction
#endif

#ifdef __USE_STEPPER2__
//use Timer5 to interrupt when applying a step is valid (lockout steps during 800us immediately following step)
uint8_t stepOutVal2; //set of 4 bits that indicate the pin states
bool stepOutShift2;  //whether to shift the output value to the high 4 bits or leave it in the low 4 bits of the output byte, only necessary in I2C mode
int8_t stepState2;   //state machine step selection, range [0:7], indicates which pin/pair of pins will be active for the current step
bool stepDirection2; //state machine next step determination, if true increment step, if false decrement step
int32_t totalSteps2; //track total number of steps output to motor, signed to record steps in each direction, provide method to zero and this can track total rotation of motor
bool allowStep2;     //lockout steps for 800us after a new step is output
int16_t pendingSteps2;   //count of pending steps to complete, add or subtract from here to rotate one way or the other and the interrupt system will allow steps to be applied until this value equals zero
STATUS_T setupStepper2(void);    //initialization run on startup
#ifdef __STEPPER_GPIO__
void stepper2ISR(void);
#elif defined(__STEPPER_I2C__)
#ifndef __PIC32M
void __interrupt(__irq(TMR5),high_priority) stepper2ISR(void);
#endif
#endif
STATUS_T stepSMachine2(void);   //routine here for running the state machine so main doesn't have to know the deets
STATUS_T stepMotor2(void);       //output one step depending on pendingSteps value
STATUS_T stepMotorFixed2(int16_t steps); //output a fixed number of steps, loop internally
STATUS_T stepMotorSM2(void);     //stepper state machine, set the output pins based on the stepState value
STATUS_T updateStepState2(void); //increment or decrement stepState based on previous state and desired step direction
#endif

#ifdef __STEPPER_I2C__
IOEXP_PCA9539_T ioexp1;
STATUS_T outputUpdate(void);
#endif
#ifdef __PIC32M
uint32_t stepper_global_time;
uint32_t stepper0_off_time;
uint32_t stepper1_off_time;
uint32_t stepper2_off_time;
#endif
//struct STEPPER {
//    volatile uint8_t * STEPPER_0_OUT;
//    volatile uint8_t * STEPPER_0_TRIS;
//    uint8_t  stepper_0_bitval;
//    volatile uint8_t * STEPPER_1_OUT;
//    volatile uint8_t * STEPPER_1_TRIS;
//    uint8_t  stepper_1_bitval;
//    volatile uint8_t * STEPPER_2_OUT;
//    volatile uint8_t * STEPPER_2_TRIS;
//    uint8_t  stepper_2_bitval;
//    volatile uint8_t * STEPPER_3_OUT;
//    volatile uint8_t * STEPPER_3_TRIS;
//    uint8_t  stepper_3_bitval;
//    int8_t stepState;   //state machine step selection, range [0:7], indicates which pin/pair of pins will be active for the current step
//    bool stepDirection; //state machine next step determination, if true increment step, if false decrement step
//    int32_t totalSteps; //track total number of steps output to motor, signed to record steps in each direction, provide method to zero and this can track total rotation of motor
//    bool allowStep;     //lockout steps for 800us after a new step is output
//    int16_t pendingSteps;   //count of pending steps to complete, add or subtract from here to rotate one way or the other and the interrupt system will allow steps to be applied until this value equals zero
////    uint8_t ioSetNum;
//    uint8_t timerNum;
//    uint8_t timerIntBitVal;
//};
//
//STATUS_T setupStepper(struct STEPPER Mod, 
//        uint8_t tmrNum, uint8_t tmrBitVal, 
//        uint8_t * out0_lat, uint8_t * out0_tris, uint8_t out0_bit, 
//        uint8_t * out1_lat, uint8_t * out1_tris, uint8_t out1_bit, 
//        uint8_t * out2_lat, uint8_t * out2_tris, uint8_t out2_bit, 
//        uint8_t * out3_lat, uint8_t * out3_tris, uint8_t out3_bit
//);    //initialization run on startup
//STATUS_T stepMotor(struct STEPPER Mod);       //output one step depending on pendingSteps value
//STATUS_T stepMotorFixed(struct STEPPER Mod, int16_t steps); //output a fixed number of steps, loop internally
//STATUS_T stepMotorSM(struct STEPPER Mod);     //stepper state machine, set the output pins based on the stepState value
//STATUS_T updateStepState(struct STEPPER Mod); //increment or decrement stepState based on previous state and desired step direction

#endif

#ifdef	__cplusplus
}
#endif

#endif	/* STEPPER_H */

