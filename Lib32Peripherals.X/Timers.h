/* 
 * File:   Timers.h
 * Author: dev-user
 *
 * Created on October 23, 2020, 1:28 PM
 */

#ifndef TIMERS_H
#define	TIMERS_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include "../IncSystemDefs/PICDEFS32.h"
#include <sys/attribs.h>

#ifdef __USE_TIMER1__
bool Tmr1UsingInt;
STATUS_T Tmr1Setup(uint32_t tmr_freq, bool use_int, uint8_t int_prio);
void Tmr1Enable(void);
void Tmr1Disable(void);
#endif

#ifdef __USE_TIMER2__
bool Tmr2UsingInt;
STATUS_T Tmr2Setup(uint32_t tmr_freq, bool use_int, uint8_t int_prio);
void Tmr2Enable(void);
void Tmr2Disable(void);
#endif

#ifdef __USE_TIMER3__
bool Tmr3UsingInt;
STATUS_T Tmr3Setup(uint32_t tmr_freq, bool use_int, uint8_t int_prio);
void Tmr3Enable(void);
void Tmr3Disable(void);
#endif

#ifdef __USE_TIMER4__
bool Tmr4UsingInt;
STATUS_T Tmr4Setup(uint32_t tmr_freq, bool use_int, uint8_t int_prio);
void Tmr4Enable(void);
void Tmr4Disable(void);
#endif

#ifdef __USE_TIMER5__
bool Tmr5UsingInt;
STATUS_T Tmr5Setup(uint32_t tmr_freq, bool use_int, uint8_t int_prio);
void Tmr5Enable(void);
void Tmr5Disable(void);
#endif

#ifdef	__cplusplus
}
#endif

#endif	/* TIMERS_H */

