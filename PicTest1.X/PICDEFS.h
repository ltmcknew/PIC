/* 
 * File:   PICDEFS.h
 * Author: dev-user
 *
 * Created on September 11, 2020, 11:36 AM
 */

#ifndef PICDEFS_H
#define	PICDEFS_H

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#ifdef	__cplusplus
extern "C" {
#endif
    
#ifdef _PIC18F14K50_H_
    
#define _XTAL_FREQ 32000000

//Programming and Reset    
#define PGD PORTAbits.RA0   //RA0 pin 19
#define PGC PORTAbits.RA1   //RA1 pin 18
#define MCLR PORTAbits.RA3  //RA3 pin 4
#define CLKOUT LATAbits.LA4 //RA4 pin 3
    
//USB PINS
#define USB_DM
#define USB_DP
    
//GPIOS
    //PORTA Pins
#define GPIO_RA5_IN     PORTAbits.RA5   //RA5 pin 2
#define GPIO_RA5_OUT    LATAbits.LATA5
#define GPIO_RA5_TRIS   TRISAbits.TRISA5

    //PORTC Pins
#define GPIO_RB4_IN     PORTBbits.RB4   //RB4 pin 13
#define GPIO_RB4_OUT    LATBbits.LATB4
#define GPIO_RB4_TRIS   TRISBbits.TRISB4
#define GPIO_RB5_IN     PORTBbits.RB5   //RB5 pin 12
#define GPIO_RB5_OUT    LATBbits.LATB5
#define GPIO_RB5_TRIS   TRISBbits.TRISB5
#define GPIO_RB6_IN     PORTBbits.RB6   //RB6 pin 11
#define GPIO_RB6_OUT    LATBbits.LATB6
#define GPIO_RB6_TRIS   TRISBbits.TRISB6
#define GPIO_RB7_IN     PORTBbits.RB7   //RB7 pin 10
#define GPIO_RB7_OUT    LATBbits.LATB7
#define GPIO_RB7_TRIS   TRISBbits.TRISB7

    //PORTC Pins
#define GPIO_RC0_IN     PORTCbits.RC0   //RC0 pin 16
#define GPIO_RC0_OUT    LATCbits.LATC0
#define GPIO_RC0_TRIS   TRISCbits.TRISC0
#define GPIO_RC1_IN     PORTCbits.RC1   //RC1 pin 15
#define GPIO_RC1_OUT    LATCbits.LATC1
#define GPIO_RC1_TRIS   TRISCbits.TRISC1
#define GPIO_RC2_IN     PORTCbits.RC2   //RC2 pin 14
#define GPIO_RC2_OUT    LATCbits.LATC2
#define GPIO_RC2_TRIS   TRISCbits.TRISC2
#define GPIO_RC3_IN     PORTCbits.RC3   //RC3 pin 7
#define GPIO_RC3_OUT    LATCbits.LATC3
#define GPIO_RC3_TRIS   TRISCbits.TRISC3
#define GPIO_RC4_IN     PORTCbits.RC4   //RC4 pin 6
#define GPIO_RC4_OUT    LATCbits.LATC4
#define GPIO_RC4_TRIS   TRISCbits.TRISC4
#define GPIO_RC5_IN     PORTCbits.RC5   //RC5 pin 5
#define GPIO_RC5_OUT    LATCbits.LATC5
#define GPIO_RC5_TRIS   TRISCbits.TRISC5
#define GPIO_RC6_IN     PORTCbits.RC6   //RC6 pin 8
#define GPIO_RC6_OUT    LATCbits.LATC6
#define GPIO_RC6_TRIS   TRISCbits.TRISC6
#define GPIO_RC7_IN     PORTCbits.RC7   //RC7 pin 9
#define GPIO_RC7_OUT    LATCbits.LATC7
#define GPIO_RC7_TRIS   TRISCbits.TRISC7

//Power Pins
//VUSB 17
//VDD 1
//VSS 20
    
#elif defined(_PIC16F18875_H_)

#define _XTAL_FREQ 32000000
    
//GPIOS
    //PORTA Pins
#define GPIO_RA0_IN     PORTAbits.RA0   //RA0 pin 2
#define GPIO_RA0_OUT    LATAbits.LATA0
#define GPIO_RA0_TRIS   TRISAbits.TRISA0
#define GPIO_RA1_IN     PORTAbits.RA1   //RA1 pin 3
#define GPIO_RA1_OUT    LATAbits.LATA1
#define GPIO_RA1_TRIS   TRISAbits.TRISA1
#define GPIO_RA2_IN     PORTAbits.RA2   //RA2 pin 4
#define GPIO_RA2_OUT    LATAbits.LATA2
#define GPIO_RA2_TRIS   TRISAbits.TRISA2
#define GPIO_RA3_IN     PORTAbits.RA3   //RA3 pin 5
#define GPIO_RA3_OUT    LATAbits.LATA3
#define GPIO_RA3_TRIS   TRISAbits.TRISA3
#define GPIO_RA4_IN     PORTAbits.RA4   //RA4 pin 6
#define GPIO_RA4_OUT    LATAbits.LATA4
#define GPIO_RA4_TRIS   TRISAbits.TRISA4
#define GPIO_RA5_IN     PORTAbits.RA5   //RA5 pin 7
#define GPIO_RA5_OUT    LATAbits.LATA5
#define GPIO_RA5_TRIS   TRISAbits.TRISA5
#define GPIO_RA6_IN     PORTAbits.RA6   //RA6 pin 14
#define GPIO_RA6_OUT    LATAbits.LATA6
#define GPIO_RA6_TRIS   TRISAbits.TRISA6
#define GPIO_RA7_IN     PORTAbits.RA7   //RA7 pin 13
#define GPIO_RA7_OUT    LATAbits.LATA7
#define GPIO_RA7_TRIS   TRISAbits.TRISA7

    //PORTB Pins
#define GPIO_RB0_IN     PORTBbits.RB0   //RB0 pin 33
#define GPIO_RB0_OUT    LATBbits.LATB0
#define GPIO_RB0_TRIS   TRISBbits.TRISB0
#define GPIO_RB1_IN     PORTBbits.RB1   //RB1 pin 34
#define GPIO_RB1_OUT    LATBbits.LATB1
#define GPIO_RB1_TRIS   TRISBbits.TRISB1
#define GPIO_RB2_IN     PORTBbits.RB2   //RB2 pin 35
#define GPIO_RB2_OUT    LATBbits.LATB2
#define GPIO_RB2_TRIS   TRISBbits.TRISB2
#define GPIO_RB3_IN     PORTBbits.RB3   //RB3 pin 36
#define GPIO_RB3_OUT    LATBbits.LATB3
#define GPIO_RB3_TRIS   TRISBbits.TRISB3
#define GPIO_RB4_IN     PORTBbits.RB4   //RB4 pin 37
#define GPIO_RB4_OUT    LATBbits.LATB4
#define GPIO_RB4_TRIS   TRISBbits.TRISB4
#define GPIO_RB5_IN     PORTBbits.RB5   //RB5 pin 38
#define GPIO_RB5_OUT    LATBbits.LATB5
#define GPIO_RB5_TRIS   TRISBbits.TRISB5
#define GPIO_RB6_IN     PORTBbits.RB6   //RB6 pin 39
#define GPIO_RB6_OUT    LATBbits.LATB6
#define GPIO_RB6_TRIS   TRISBbits.TRISB6
#define GPIO_RB7_IN     PORTBbits.RB7   //RB7 pin 40
#define GPIO_RB7_OUT    LATBbits.LATB7
#define GPIO_RB7_TRIS   TRISBbits.TRISB7

    //PORTC Pins
#define GPIO_RC0_IN     PORTCbits.RC0   //RC0 pin 15
#define GPIO_RC0_OUT    LATCbits.LATC0
#define GPIO_RC0_TRIS   TRISCbits.TRISC0
#define GPIO_RC1_IN     PORTCbits.RC1   //RC1 pin 16
#define GPIO_RC1_OUT    LATCbits.LATC1
#define GPIO_RC1_TRIS   TRISCbits.TRISC1
#define GPIO_RC2_IN     PORTCbits.RC2   //RC2 pin 17
#define GPIO_RC2_OUT    LATCbits.LATC2
#define GPIO_RC2_TRIS   TRISCbits.TRISC2
#define GPIO_RC3_IN     PORTCbits.RC3   //RC3 pin 18
#define GPIO_RC3_OUT    LATCbits.LATC3
#define GPIO_RC3_TRIS   TRISCbits.TRISC3
#define GPIO_RC4_IN     PORTCbits.RC4   //RC4 pin 23
#define GPIO_RC4_OUT    LATCbits.LATC4
#define GPIO_RC4_TRIS   TRISCbits.TRISC4
#define GPIO_RC5_IN     PORTCbits.RC5   //RC5 pin 24
#define GPIO_RC5_OUT    LATCbits.LATC5
#define GPIO_RC5_TRIS   TRISCbits.TRISC5
#define GPIO_RC6_IN     PORTCbits.RC6   //RC6 pin 25
#define GPIO_RC6_OUT    LATCbits.LATC6
#define GPIO_RC6_TRIS   TRISCbits.TRISC6
#define GPIO_RC7_IN     PORTCbits.RC7   //RC7 pin 26
#define GPIO_RC7_OUT    LATCbits.LATC7
#define GPIO_RC7_TRIS   TRISCbits.TRISC7

    //PORTD Pins
#define GPIO_RD0_IN     PORTDbits.RD0   //RD0 pin 19
#define GPIO_RD0_OUT    LATDbits.LATD0
#define GPIO_RD0_TRIS   TRISDbits.TRISD0
#define GPIO_RD1_IN     PORTDbits.RD1   //RD1 pin 20
#define GPIO_RD1_OUT    LATDbits.LATD1
#define GPIO_RD1_TRIS   TRISDbits.TRISD1
#define GPIO_RD2_IN     PORTDbits.RD2   //RD2 pin 21
#define GPIO_RD2_OUT    LATDbits.LATD2
#define GPIO_RD2_TRIS   TRISDbits.TRISD2
#define GPIO_RD3_IN     PORTDbits.RD3   //RD3 pin 22
#define GPIO_RD3_OUT    LATDbits.LATD3
#define GPIO_RD3_TRIS   TRISDbits.TRISD3
#define GPIO_RD4_IN     PORTDbits.RD4   //RD4 pin 27
#define GPIO_RD4_OUT    LATDbits.LATD4
#define GPIO_RD4_TRIS   TRISDbits.TRISD4
#define GPIO_RD5_IN     PORTDbits.RD5   //RD5 pin 28
#define GPIO_RD5_OUT    LATDbits.LATD5
#define GPIO_RD5_TRIS   TRISDbits.TRISD5
#define GPIO_RD6_IN     PORTDbits.RD6   //RD6 pin 29
#define GPIO_RD6_OUT    LATDbits.LATD6
#define GPIO_RD6_TRIS   TRISDbits.TRISD6
#define GPIO_RD7_IN     PORTDbits.RD7   //RD7 pin 30
#define GPIO_RD7_OUT    LATDbits.LATD7
#define GPIO_RD7_TRIS   TRISDbits.TRISD7
    
    //PORTE Pins
#define GPIO_RE0_IN     PORTEbits.RE0   //RE0 pin 8
#define GPIO_RE0_OUT    LATEbits.LATE0
#define GPIO_RE0_TRIS   TRISEbits.TRISE0
#define GPIO_RE1_IN     PORTEbits.RE1   //RE1 pin 9
#define GPIO_RE1_OUT    LATEbits.LATE1
#define GPIO_RE1_TRIS   TRISEbits.TRISE1
#define GPIO_RE2_IN     PORTEbits.RE2   //RE2 pin 10
#define GPIO_RE2_OUT    LATEbits.LATE2
#define GPIO_RE2_TRIS   TRISEbits.TRISE2
#define GPIO_RE3_IN     PORTEbits.RE3   //RE3 pin 1
    
//Power Pins
//VUSB 17
//VDD 11,32
//VSS 12,31
    
//Programming and Reset    
#define PGD_IN GPIO_RB7_IN 
#define PGD_OUT GPIO_RB7_OUT 
#define PGD_TRIS GPIO_RB7_TRIS
#define PGC_IN GPIO_RB6_IN
#define PGC_OUT GPIO_RB6_OUT
#define PGC_TRIS GPIO_RB6_TRIS

#define MCLR GPIO_RE3_IN  //RE3 pin 1
    
//Timers
//#define __USE_TIMER4__    //not necessary with the generic timer/struct 
    
//EUSART
#define EUSART_RX       GPIO_RC7_IN
#define EUSART_RX_TRIS  GPIO_RC7_TRIS
#define EUSART_RX_PPS_VAL   0x17    //hardcoded value for RC7
#define EUSART_TX       GPIO_RC6_OUT
#define EUSART_TX_TRIS  GPIO_RC6_TRIS
#define EUSART_TX_PPS   RC6PPS
#define EUSART_RST      GPIO_RC5_OUT
#define EUSART_RST_TRIS GPIO_RC5_TRIS
    
//T&H Sensor
#define SNSR_TnH_OUT    GPIO_RD6_OUT
#define SNSR_TnH_IN     GPIO_RD6_IN
#define SNSR_TnH_TRIS   GPIO_RD6_TRIS
    
//IR Dist Sensor
#define IRDIST_OUT      GPIO_RB0_OUT
#define IRDIST_IN      GPIO_RB0_IN
#define IRDIST_TRIS      GPIO_RB0_TRIS
#define IRDIST_PPS_VAL  0x08
    
//TriColor LED
#define TRICOLOR_G      GPIO_RA7_OUT //pin13, A7
#define TRICOLOR_G_TRIS GPIO_RA7_TRIS
#define TRICOLOR_R      GPIO_RA6_OUT //pin14, A6
#define TRICOLOR_R_TRIS GPIO_RA6_TRIS
#define TRICOLOR_B      GPIO_RC0_OUT //pin15, C0
#define TRICOLOR_B_TRIS GPIO_RC0_TRIS
    
//PWM Outputs
    
//#define __USE_PWM1__        //UNCOMMENT THIS LINE TO ENABLE THE CCP1 MODULE IN PWM MODE
#ifdef __USE_PWM1__
#define PWM1OUT         GPIO_RC0_OUT
#define PWM1OUT_TRIS    GPIO_RC0_TRIS
#define PWM1OUT_PPS     RC0PPS
#define PWM1PPS_VAL     0x09
#endif
    
//#define __USE_PWM2__        //UNCOMMENT THIS LINE TO ENABLE THE CCP2 MODULE IN PWM MODE
#ifdef __USE_PWM2__
#define PWM2OUT         GPIO_RC0_OUT
#define PWM2OUT_TRIS    GPIO_RC0_TRIS
#define PWM2OUT_PPS     RC0PPS
#define PWM2PPS_VAL     0x0A
#endif
    
//#define __USE_PWM3__        //UNCOMMENT THIS LINE TO ENABLE THE CCP3 MODULE IN PWM MODE
#ifdef __USE_PWM3__
#define PWM3OUT         GPIO_RC0_OUT
#define PWM3OUT_TRIS    GPIO_RC0_TRIS
#define PWM3OUT_PPS     RC0PPS
#define PWM3PPS_VAL     0x0B
#endif
    
//#define __USE_PWM4__        //UNCOMMENT THIS LINE TO ENABLE THE CCP4 MODULE IN PWM MODE
#ifdef __USE_PWM4__    
#define PWM4OUT         GPIO_RC0_OUT
#define PWM4OUT_TRIS    GPIO_RC0_TRIS
#define PWM4OUT_PPS     RC0PPS
#define PWM4PPS_VAL     0x0C
#endif
    
//#define __USE_PWM5__        //UNCOMMENT THIS LINE TO ENABLE THE CCP5 MODULE IN PWM MODE
#ifdef __USE_PWM5__    
#define PWM5OUT         GPIO_RA7_OUT
#define PWM5OUT_TRIS    GPIO_RA7_TRIS
#define PWM5OUT_PPS     RA7PPS
#define PWM5PPS_VAL     0x0D
#endif
    
//#define __USE_PWM6__        //UNCOMMENT THIS LINE TO ENABLE THE PWM6 MODULE
#ifdef __USE_PWM6__    
#define PWM6OUT         GPIO_RA6_OUT
#define PWM6OUT_TRIS    GPIO_RA6_TRIS
#define PWM6OUT_PPS     RA6PPS
#define PWM6PPS_VAL     0x0E
#endif
    
//#define __USE_PWM7__        //UNCOMMENT THIS LINE TO ENABLE THE PWM7 MODULE
#ifdef __USE_PWM7__
#define PWM7OUT         GPIO_RC0_OUT
#define PWM7OUT_TRIS    GPIO_RC0_TRIS
#define PWM7OUT_PPS     RC0PPS
#define PWM7PPS_VAL     0x0F
#endif    
    
#endif //PIC Selection 


#ifdef	__cplusplus
}
#endif

#endif	/* PICDEFS_H */

