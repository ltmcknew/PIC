/* 
 * File:   ccp.h
 * Author: dev-user
 *
 * Created on September 21, 2020, 3:23 PM
 */

#ifndef CCP_H
#define	CCP_H

#include "../SystemDefs/PICDEFS.h"
#include "../SystemDefs/StatEnum.h"
#include "../Peripherals/timers.h"

#ifdef	__cplusplus
extern "C" {
#endif
    
#define PWMMAXPCT 10000

/*
 *  The following CCP and PWM Module Blocks require minimal settings in other files. Specifically:
 * 
 *  In the PICDEFS.h file:
 *      Define a block of 3 signals similar to the following example for each module that will be active
        #define PWMXOUT         GPIO_RXY_OUT    definition of pin for PWM Output
        #define PWMXOUT_TRIS    GPIO_RXY_TRIS   definition of pin direction control for pwm output pin
        #define PWMXOUT_PPS     RXYPPS          definition of pps register for pwm mode selection
        #define PWMXPPS_VAL     0xZZ            definition of value to load into pps registor for PWMX mode (already set to required value)
 * 
 *  There are no requirements in system.h
 * 
 *  Initialize the block as in the following example from system.c
        if(PwmXSetup(10000,6666) == STAT_SUCCESS){
            PwmXEnable();
        }
 * 
 *  Implementation Note:
 *      The Timer modules used by each CCP are fixed in the code. For PWM mode any of the even modules (Timer2/4/6) can
 *      be used so verify that the selected one is the desired one.
 */
    
#ifdef __USE_PWM1__
uint16_t Pwm1DCVal;
uint16_t Pwm1DCMaxVal;
int16_t  Pwm1DCPct;
uint8_t  Pwm1TmrNum;
STATUS_T Pwm1Setup(uint8_t timerNum, uint16_t timerFreq, uint16_t initDCVal); //timerFreq will be passed to the Tmr2Setup routine, initDCVal takes the 100*% format for DC, see Pwm5UpdateDC for unit details
STATUS_T Pwm1Enable();
STATUS_T Pwm1Disable();
STATUS_T Pwm1UpdateDC(int16_t newDCPct);   //newDCVal is in %*100 or 100% = 10000, 50% = 5000 etc   
#endif

#ifdef __USE_PWM2__
uint16_t Pwm2DCVal;
uint16_t Pwm2DCMaxVal;
int16_t  Pwm2DCPct;
uint8_t  Pwm2TmrNum;
STATUS_T Pwm2Setup(uint8_t timerNum, uint16_t timerFreq, uint16_t initDCVal); //timerFreq will be passed to the Tmr2Setup routine, initDCVal takes the 100*% format for DC, see Pwm5UpdateDC for unit details
STATUS_T Pwm2Enable();
STATUS_T Pwm2Disable();
STATUS_T Pwm2UpdateDC(int16_t newDCPct);   //newDCVal is in %*100 or 100% = 10000, 50% = 5000 etc   
#endif 

#ifdef __USE_PWM3__
uint16_t Pwm3DCVal;
uint16_t Pwm3DCMaxVal;
int16_t  Pwm3DCPct;
uint8_t  Pwm3TmrNum;
STATUS_T Pwm3Setup(uint8_t timerNum, uint16_t timerFreq, uint16_t initDCVal); //timerFreq will be passed to the Tmr2Setup routine, initDCVal takes the 100*% format for DC, see Pwm5UpdateDC for unit details
STATUS_T Pwm3Enable();
STATUS_T Pwm3Disable();
STATUS_T Pwm3UpdateDC(int16_t newDCPct);   //newDCVal is in %*100 or 100% = 10000, 50% = 5000 etc   
#endif 

#ifdef __USE_PWM4__
uint16_t Pwm4DCVal;
uint16_t Pwm4DCMaxVal;
int16_t  Pwm4DCPct;
uint8_t  Pwm4TmrNum;
STATUS_T Pwm4Setup(uint8_t timerNum, uint16_t timerFreq, uint16_t initDCVal); //timerFreq will be passed to the Tmr2Setup routine, initDCVal takes the 100*% format for DC, see Pwm5UpdateDC for unit details
STATUS_T Pwm4Enable();
STATUS_T Pwm4Disable();
STATUS_T Pwm4UpdateDC(int16_t newDCPct);   //newDCVal is in %*100 or 100% = 10000, 50% = 5000 etc   
#endif 

#ifdef __USE_PWM5__
uint16_t Pwm5DCVal;
uint16_t Pwm5DCMaxVal;
int16_t  Pwm5DCPct;
uint8_t  Pwm5TmrNum;
STATUS_T Pwm5Setup(uint8_t timerNum, uint16_t timerFreq, uint16_t initDCVal); //timerFreq will be passed to the Tmr2Setup routine, initDCVal takes the 100*% format for DC, see Pwm5UpdateDC for unit details
STATUS_T Pwm5Enable();
STATUS_T Pwm5Disable();
STATUS_T Pwm5UpdateDC(int16_t newDCPct);   //newDCVal is in %*100 or 100% = 10000, 50% = 5000 etc
#endif 

#ifdef __USE_PWM6__
uint16_t Pwm6DCVal;
uint16_t Pwm6DCMaxVal;
int16_t  Pwm6DCPct;
uint8_t  Pwm6TmrNum;
STATUS_T Pwm6Setup(uint8_t timerNum, uint16_t timerFreq, uint16_t initDCVal); //timerFreq will be passed to the Tmr2Setup routine, initDCVal takes the 100*% format for DC, see Pwm5UpdateDC for unit details
STATUS_T Pwm6Enable();
STATUS_T Pwm6Disable();
STATUS_T Pwm6UpdateDC(int16_t newDCPct);   //newDCVal is in %*100 or 100% = 10000, 50% = 5000 etc
#endif 

#ifdef __USE_PWM7__
uint16_t Pwm7DCVal;
uint16_t Pwm7DCMaxVal;
int16_t  Pwm7DCPct;
uint8_t  Pwm7TmrNum;
STATUS_T Pwm7Setup(uint8_t timerNum, uint16_t timerFreq, uint16_t initDCVal); //timerFreq will be passed to the Tmr2Setup routine, initDCVal takes the 100*% format for DC, see Pwm5UpdateDC for unit details
STATUS_T Pwm7Enable();
STATUS_T Pwm7Disable();
STATUS_T Pwm7UpdateDC(int16_t newDCPct);   //newDCVal is in %*100 or 100% = 10000, 50% = 5000 etc
#endif








/*  The routines below are an attempt to make a generic PWM class that can take a struct with some
 *      data members as well as some pointers to HW registers. The system seemed to function after
 *      initialization but once PwmUpdateDC was called in the main the DC value was stuck at zero.
 *      It appears the DCMaxVal wasn't persistent, so the last thing I tried was to replace it with
 *      a pointer to the selected timer's PR register and calculate max dc val in line but this was
 *      also very unreliable. This bears further investigation but for now (9/22/2020) I'm going to 
 *      stick with the independent definitions above here.
 * 
 * 
 *  These routines require the following to be defined in the PICDEFS.h file:
 * 
        #define PWM2OUT         GPIO_RC0_OUT
        #define PWM2OUT_TRIS    GPIO_RC0_TRIS
        #define PWM2OUT_TRISR   TRISC;//GPIO_RC0_TRIS
        #define PWM2OUT_TRIS_BIT 0x01;//GPIO_RC0_TRIS
        #define PWM2OUT_PPS     RC0PPS
 * 
 *  Declare an instance of the module in system.h similar to:
 * 
        CCPModule_t Pwm2;
 * 
 *  An Example Initialization in sys_init() could be similiar to:
 * 
        //Configure PWM2 to use Tmr2 and RC0, To run with Freq=10KHz and start at 66.66%DC
        Pwm2.OUT_PPS = &PWM2OUT_PPS;
        Pwm2.OUT_TRIS = &PWM2OUT_TRISR;
        Pwm2.OutBit = PWM2OUT_TRIS_BIT;
        Pwm2.CON = &CCP2CON;
        Pwm2.CLKSEL = &CCPTMRS0;
        Pwm2.REG = &CCPR2;
        Pwm2.REGH = &CCPR2H;
        Pwm2.REGL = &CCPR2L;
        Pwm2.TmrNum = 2;
        Pwm2.ClkShft = 2;
        Pwm2.PPSVal = 0x0A;
        if(PwmSetup(Pwm2, 10000,6666) == STAT_SUCCESS){
            PwmEnable(Pwm2);
            sys_stat |= 4;
        }
 */

//typedef struct CCPModule {
//    uint16_t DCVal;
////    uint16_t DCMaxVal;
//    uint16_t DCPct;
//    uint8_t  ClkShft;
//    uint16_t TmrNum;
//    uint8_t  OutBit;
//    uint8_t  PPSVal;
//    volatile uint8_t* TMRPRREG;
//    volatile uint8_t* OUT_PPS;
//    volatile uint8_t* OUT_TRIS;
//    volatile uint8_t* CON;
//    volatile uint8_t* CLKSEL;
//    volatile uint16_t* REG;
//    volatile uint8_t* REGH;
//    volatile uint8_t* REGL;
//} CCPModule_t;
//
//STATUS_T PwmSetup(CCPModule_t Mod, uint16_t timerFreq, uint16_t initDCPct);
//STATUS_T PwmEnable(CCPModule_t Mod);
//STATUS_T PwmDisable(CCPModule_t Mod);
//STATUS_T PwmUpdateDC(CCPModule_t Mod, int16_t newDCPct);

#ifdef	__cplusplus
}
#endif

#endif	/* CCP_H */

