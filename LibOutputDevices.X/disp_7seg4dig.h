/* 
 * File:   disp_7seg4dig.h
 * Author: dev-user
 *
 * Created on September 28, 2020, 12:11 PM
 */

#ifndef DISP_7SEG4DIG_H
#define	DISP_7SEG4DIG_H

#ifdef	__cplusplus
extern "C" {
#endif

#ifdef __PIC32M
#include "../IncSystemDefs/PICDEFS32.h"
#else
#include "../IncSystemDefs/PICDEFS.h"
#endif
    
#ifdef __USE_7SEGDISP__
    /*
Digit  	(dp)gfedcba    	dp 	g 	f 	e 	d 	c 	b 	a
0           0xC0        1 	1 	0 	0 	0 	0 	0 	0
1           0xF9        1 	1 	1 	1 	1 	0 	0 	1
2           0xA4        1 	0 	1 	0 	0 	1 	0 	0
3           0xB0        1 	0 	1 	1 	0 	0 	0 	0
4           0x99        1 	0 	0 	1 	1 	0 	0 	1
5           0x92        1 	0 	0 	1 	0 	0 	1 	0
6           0x82        1 	0 	0 	0 	0 	0 	1 	0
7           0xF8        1 	1 	1 	1 	1 	0 	0 	0
8           0x80        1 	0 	0 	0 	0 	0 	0 	0
9           0x90        1 	0 	0 	1 	0 	0 	0 	0
A           0x88        1 	0 	0 	0 	1 	0 	0 	0
b           0x83        1 	0 	0 	0 	0 	0 	1 	1
C           0xC6        1 	1 	0 	0 	0 	1 	1 	0
d           0xA1        1 	0 	1 	0 	0 	0 	0 	1
E           0x86        1 	0 	0 	0 	0 	1 	1 	0
F           0x8E        1 	0 	0 	0 	1 	1 	1 	0
-           0xDF        1   0   1   1   1   1   1   1
*/
    
uint8_t dispChars[17] = {
    0xC0, 0xF9, 0xA4, 0xB0, 
    0x99, 0x92, 0x82, 0xF8, 
    0x80, 0x90, 0x88, 0x83,
    0xC6, 0xA1, 0x86, 0x8E,
    0xDF
};

#define DP 0x7F;

uint8_t dig_disp_val[4];
uint8_t dig_idx;
bool update_disp_trigger;

STATUS_T setupDisp(uint16_t initVal);
STATUS_T updateDispVal(uint16_t newVal, uint8_t newDP);
STATUS_T updateDispValHex(uint16_t newVal, uint8_t newDP);
STATUS_T updateDisp(void);
#endif  /* __USE_7SEGDISP__ */

#ifdef	__cplusplus
}
#endif

#endif	/* DISP_7SEG4DIG_H */

