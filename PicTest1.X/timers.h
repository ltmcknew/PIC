/* 
 * File:   timers.h
 * Author: dev-user
 *
 * Created on September 11, 2020, 9:39 PM
 */

#ifndef TIMERS_H
#define	TIMERS_H

#include "PICDEFS.h"
#include "StatEnum.h"

#ifdef	__cplusplus
extern "C" {
#endif

//The following enable the Timer0 type module, setup to operate like Timer2/4/6, free running repetitive timer. Must expand if other op mode is desired
//#define __USE_TIMER0__
#ifdef __USE_TIMER0__
uint16_t TMR0Val;
STATUS_T Tmr0Setup(uint16_t tmr_freq, bool use_int);
void Tmr0Enable(void);
void Tmr0Disable(void);
#endif
    
//The following enable the Timer1/3/5 type modules, setup to operate like Timer2/4/6, free running repetitive timer. Must expand if other op mode is desired
//#define __USE_TIMER1__
#ifdef __USE_TIMER1__
uint16_t TMR1Val;
STATUS_T Tmr1Setup(uint16_t tmr_freq, bool use_int);
void Tmr1Enable(void);
void Tmr1Disable(void);
#endif

//#define __USE_TIMER3__
#ifdef __USE_TIMER3__
uint16_t TMR3Val;
STATUS_T Tmr3Setup(uint16_t tmr_freq, bool use_int);
void Tmr3Enable(void);
void Tmr3Disable(void);
#endif

//#define __USE_TIMER5__
#ifdef __USE_TIMER5__
uint16_t TMR5Val;
STATUS_T Tmr5Setup(uint16_t tmr_freq, bool use_int);
void Tmr5Enable(void);
void Tmr5Disable(void);
#endif

//The following enable the Timer2/4/6 type modules to operate in free running software control mode
//#define __USE_TIMER2__
#ifdef __USE_TIMER2__
STATUS_T Tmr2Setup(uint16_t tmr_freq, bool use_int);
void Tmr2Enable(void);
void Tmr2Disable(void);
#endif

//#define __USE_TIMER4__
#ifdef __USE_TIMER4__
STATUS_T Tmr4Setup(uint16_t tmr_freq, bool use_int);
void Tmr4Enable(void);
void Tmr4Disable(void);
#endif

//#define __USE_TIMER6__
#ifdef __USE_TIMER6__
STATUS_T Tmr6Setup(uint16_t tmr_freq, bool use_int);
void Tmr6Enable(void);
void Tmr6Disable(void);
#endif


//Generic, instantiation of even timers
typedef struct TimerEven {
    uint8_t * CON;
    uint8_t * CLKCON;
    uint8_t * HLT;
    uint8_t * PREG;
    uint8_t   intBitPos;
    uint16_t  setFreq;
    bool      isEnabled;
    bool      intEnabled;
} TmrEven_T;

STATUS_T TmrSetup(TmrEven_T Mod, uint16_t tmr_freq, bool use_int);
void TmrDisable(TmrEven_T Mod);
void TmrEnable(TmrEven_T Mod);

#ifdef	__cplusplus
}
#endif

#endif	/* TIMERS_H */

