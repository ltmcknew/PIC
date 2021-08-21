/* 
 * File:   System.h
 * Author: dev-user
 *
 * Created on September 11, 2020, 2:26 PM
 */

#ifndef SYSTEM_H
#define	SYSTEM_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "config_bits.h"
#include "PICDEFS.h"
#include "StatEnum.h"
    
#include "eusart.h"
#include "timers.h"
//#include "ccppwm.h"
    
#include "dht11.h"
#include "ir_dist.h"
    
void SetupClk(void);

STATUS_T SysInit(void);

STATUS_T make_all_digital(void);

volatile uint32_t sys_time;
volatile uint8_t sys_stat;

TmrEven_T tmr4;

//bool do_pwm_updates;

#ifdef	__cplusplus
}
#endif

#endif	/* SYSTEM_H */

