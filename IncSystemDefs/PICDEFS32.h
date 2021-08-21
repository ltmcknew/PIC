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

#include "StatEnum.h"

#ifdef	__cplusplus
extern "C" {
#endif
    
#if defined(__32MX170F256B__)
    
#define _XTAL_FREQ 38000000
    
//GPIOS
    //PORTA Pins
#define GPIO_RA0_IN     PORTAbits.RA0   //RA0 pin 2
#define GPIO_RA0_OUT    LATAbits.LATA0
#define GPIO_RA0_TRIS   TRISAbits.TRISA0
#define GPIO_RA1_IN     PORTAbits.RA1   //RA1 pin 3
#define GPIO_RA1_OUT    LATAbits.LATA1
#define GPIO_RA1_TRIS   TRISAbits.TRISA1
#define GPIO_RA2_IN     PORTAbits.RA2   //RA2 pin 9
#define GPIO_RA2_OUT    LATAbits.LATA2
#define GPIO_RA2_TRIS   TRISAbits.TRISA2
#define GPIO_RA3_IN     PORTAbits.RA3   //RA3 pin 10
#define GPIO_RA3_OUT    LATAbits.LATA3
#define GPIO_RA3_TRIS   TRISAbits.TRISA3
#define GPIO_RA4_IN     PORTAbits.RA4   //RA4 pin 12
#define GPIO_RA4_OUT    LATAbits.LATA4
#define GPIO_RA4_TRIS   TRISAbits.TRISA4

    //PORTB Pins
#define GPIO_RB0_IN     PORTBbits.RB0   //RB0 pin 4
#define GPIO_RB0_OUT    LATBbits.LATB0
#define GPIO_RB0_TRIS   TRISBbits.TRISB0
#define GPIO_RB1_IN     PORTBbits.RB1   //RB1 pin 5
#define GPIO_RB1_OUT    LATBbits.LATB1
#define GPIO_RB1_TRIS   TRISBbits.TRISB1
#define GPIO_RB2_IN     PORTBbits.RB2   //RB2 pin 6
#define GPIO_RB2_OUT    LATBbits.LATB2
#define GPIO_RB2_TRIS   TRISBbits.TRISB2
#define GPIO_RB3_IN     PORTBbits.RB3   //RB3 pin 7
#define GPIO_RB3_OUT    LATBbits.LATB3
#define GPIO_RB3_TRIS   TRISBbits.TRISB3
#define GPIO_RB4_IN     PORTBbits.RB4   //RB4 pin 11
#define GPIO_RB4_OUT    LATBbits.LATB4
#define GPIO_RB4_TRIS   TRISBbits.TRISB4
#define GPIO_RB5_IN     PORTBbits.RB5   //RB5 pin 14
#define GPIO_RB5_OUT    LATBbits.LATB5
#define GPIO_RB5_TRIS   TRISBbits.TRISB5
#define GPIO_RB6_IN     PORTBbits.RB6   //RB6 pin 15
#define GPIO_RB6_OUT    LATBbits.LATB6
#define GPIO_RB6_TRIS   TRISBbits.TRISB6
#define GPIO_RB7_IN     PORTBbits.RB7   //RB7 pin 16
#define GPIO_RB7_OUT    LATBbits.LATB7
#define GPIO_RB7_TRIS   TRISBbits.TRISB7
#define GPIO_RB8_IN     PORTBbits.RB8   //RB8 pin 17
#define GPIO_RB8_OUT    LATBbits.LATB8
#define GPIO_RB8_TRIS   TRISBbits.TRISB8
#define GPIO_RB9_IN     PORTBbits.RB9   //RB9 pin 19
#define GPIO_RB9_OUT    LATBbits.LATB9
#define GPIO_RB9_TRIS   TRISBbits.TRISB9
#define GPIO_RB10_IN     PORTBbits.RB10   //RB10 pin 21
#define GPIO_RB10_OUT    LATBbits.LATB10
#define GPIO_RB10_TRIS   TRISBbits.TRISB10
#define GPIO_RB11_IN     PORTBbits.RB11   //RB11 pin 22
#define GPIO_RB11_OUT    LATBbits.LATB11
#define GPIO_RB11_TRIS   TRISBbits.TRISB11
#define GPIO_RB12_IN     PORTBbits.RB12   //RB12 pin 23
#define GPIO_RB12_OUT    LATBbits.LATB12
#define GPIO_RB12_TRIS   TRISBbits.TRISB12
#define GPIO_RB13_IN     PORTBbits.RB13   //RB13 pin 24
#define GPIO_RB13_OUT    LATBbits.LATB13
#define GPIO_RB13_TRIS   TRISBbits.TRISB13
#define GPIO_RB14_IN     PORTBbits.RB14   //RB14 pin 25
#define GPIO_RB14_OUT    LATBbits.LATB14
#define GPIO_RB14_TRIS   TRISBbits.TRISB14
#define GPIO_RB15_IN     PORTBbits.RB15   //RB15 pin 26
#define GPIO_RB15_OUT    LATBbits.LATB15
#define GPIO_RB15_TRIS   TRISBbits.TRISB15

//Power Pins
//VDD 13
//VSS 8,19
//MCLR 1 (not mapped to a port pin in this device)

//Programming and Reset    
#define PGED1_IN GPIO_RB0_IN 
#define PGED1_OUT GPIO_RB0_OUT 
#define PGED1_TRIS GPIO_RB0_TRIS
#define PGEC1_IN GPIO_RB1_IN
#define PGEC1_OUT GPIO_RB1_OUT
#define PGEC1_TRIS GPIO_RB1_TRIS

    
#endif //PIC Selection 
    
/*
 *  BEGIN Peripherals/Sensors/OutputDevices Assignments for specific projects
 * 
 */
 
#define __PENPLOTTER_V1__
#ifdef __PENPLOTTER_V1__
    
// SENSORS
    
// OUTPUT DEVICES
    
//ULN2003 Stepper Driver
#define __USE_STEPPER__
#ifdef __USE_STEPPER__
#define __USE_STEPPER0__
#define __USE_STEPPER1__
//#define __USE_STEPPER2__
#define __STEPPER_I2C__
#define __USE_TIMER5__    
#endif 
    
//SSD1306 OLED LCD Display
#define __USE_OLEDDISP__
#ifdef __USE_OLEDDISP__    
#define __USE_I2C1__
#endif
    
//SG90 Servo Pins
#define __USE_SERVO__
#ifdef __USE_SERVO__
#define SERVO_OUT   GPIO_RB14_OUT
#define SERVO_TRIS  GPIO_RB14_TRIS
#define __USE_TIMER2__
#define __USE_TIMER3__
#endif
    
// PERIPHERALS
    
//Timers
#define __USE_TIMER4__    //not necessary with the generic timer/struct 
    
//UART
#define __USE_UART1__
#ifdef __USE_UART1__
#define UART1_RX        GPIO_RB2_IN
#define UART1_RX_TRIS   GPIO_RB2_TRIS
#define UART1_RX_PPS_VAL    0b0100    //hardcoded value for RB2
#define UART1_TX        GPIO_RB3_OUT
#define UART1_TX_TRIS   GPIO_RB3_TRIS
#define UART1_TX_PPS    RPB3R          //set to 0b0001 for U1TX assignment
#define UART1_RST       GPIO_RB1_OUT
#define UART1_RST_TRIS  GPIO_RB1_TRIS
#endif 

//I2C    
#define __USE_I2C1__
#ifdef __USE_I2C1__
#define I2C1_CLK_TRIS       GPIO_RB8_TRIS
#define I2C1_CLK_ODCON      ODCBbits.ODCB8
#define I2C1_CLK_LVLSEL     INLVLBbits.INLVLB8
#define I2C1_DAT_TRIS       GPIO_RB9_TRIS
#define I2C1_DAT_ODCON      ODCBbits.ODCB9
#define I2C1_DAT_LVLSEL     INLVLBbits.INLVLB9
#define IOEXP_RST           GPIO_RB7_OUT
#define IOEXP_RST_TRIS      GPIO_RB7_TRIS
#endif  
    
#elif defined(__STEPPERSYSTEM_V2__)
    
// SENSORS
    
// OUTPUT DEVICES
    
//4 digit 7-segment
//#define __USE_7SEGDISP__
#ifdef __USE_7SEGDISP__
#define DIG3_OUT GPIO_RC3_OUT
#define DIG3_TRIS GPIO_RC3_TRIS
#define DIG2_OUT GPIO_RC2_OUT
#define DIG2_TRIS GPIO_RC2_TRIS
#define DIG1_OUT GPIO_RC1_OUT
#define DIG1_TRIS GPIO_RC1_TRIS
#define DIG0_OUT GPIO_RC0_OUT
#define DIG0_TRIS GPIO_RC0_TRIS
#define DIGS_OUT LATC
#define SEGS_OUT LATD
#define SEGS_TRIS TRISD
#endif
    
//ULN2003 Stepper Driver
#define __USE_STEPPER__
#ifdef __USE_STEPPER__
#define __USE_STEPPER0__
#define __USE_STEPPER1__
#define __USE_STEPPER2__
#define __STEPPER_I2C__
#define __USE_TIMER5__    
#endif 
    
//SSD1306 OLED LCD Display
#define __USE_OLEDDISP__
#ifdef __USE_OLEDDISP__    
#define __USE_I2C1__
#endif
    
    
// PERIPHERALS
    
//Timers
#define __USE_TIMER4__    //not necessary with the generic timer/struct 
    
//UART
#define __USE_UART1__
#ifdef __USE_UART1__
#define UART1_RX        GPIO_RB2_IN
#define UART1_RX_TRIS   GPIO_RB2_TRIS
#define UART1_RX_PPS_VAL    0b0100    //hardcoded value for RB2
#define UART1_TX        GPIO_RB3_OUT
#define UART1_TX_TRIS   GPIO_RB3_TRIS
#define UART1_TX_PPS    RPB3R          //set to 0b0001 for U1TX assignment
#define UART1_RST       GPIO_RB1_OUT
#define UART1_RST_TRIS  GPIO_RB1_TRIS
#endif 

//I2C    
#define __USE_I2C1__
#ifdef __USE_I2C1__
#define I2C1_CLK_TRIS       GPIO_RB8_TRIS
#define I2C1_CLK_ODCON      ODCBbits.ODCB8
#define I2C1_CLK_LVLSEL     INLVLBbits.INLVLB8
#define I2C1_DAT_TRIS       GPIO_RB9_TRIS
#define I2C1_DAT_ODCON      ODCBbits.ODCB9
#define I2C1_DAT_LVLSEL     INLVLBbits.INLVLB9
#define IOEXP_RST           GPIO_RB7_OUT
#define IOEXP_RST_TRIS      GPIO_RB7_TRIS
#endif  
    
#elif defined(__STEPPERSYSTEM_V1__)
    
// SENSORS
    
// OUTPUT DEVICES
    
//4 digit 7-segment
#define __USE_7SEGDISP__
#ifdef __USE_7SEGDISP__
#define DIG3_OUT GPIO_RC3_OUT
#define DIG3_TRIS GPIO_RC3_TRIS
#define DIG2_OUT GPIO_RC2_OUT
#define DIG2_TRIS GPIO_RC2_TRIS
#define DIG1_OUT GPIO_RC1_OUT
#define DIG1_TRIS GPIO_RC1_TRIS
#define DIG0_OUT GPIO_RC0_OUT
#define DIG0_TRIS GPIO_RC0_TRIS
#define DIGS_OUT LATC
#define SEGS_OUT LATD
#define SEGS_TRIS TRISD
#endif
    
//ULN2003 Stepper Driver
#define __USE_STEPPER__
#ifdef __USE_STEPPER__
#define __USE_TIMER1__
#define STEPPER0_OUT0    GPIO_RA0_OUT
#define STEPPER0_TRIS0   GPIO_RA0_TRIS
#define STEPPER0_OUT1    GPIO_RA1_OUT
#define STEPPER0_TRIS1   GPIO_RA1_TRIS
#define STEPPER0_OUT2    GPIO_RA2_OUT
#define STEPPER0_TRIS2   GPIO_RA2_TRIS
#define STEPPER0_OUT3    GPIO_RA3_OUT
#define STEPPER0_TRIS3   GPIO_RA3_TRIS
    
#define __USE_TIMER3__
#define STEPPER1_OUT0    GPIO_RA4_OUT
#define STEPPER1_TRIS0   GPIO_RA4_TRIS
#define STEPPER1_OUT1    GPIO_RA5_OUT
#define STEPPER1_TRIS1   GPIO_RA5_TRIS
#define STEPPER1_OUT2    GPIO_RA6_OUT
#define STEPPER1_TRIS2   GPIO_RA6_TRIS
#define STEPPER1_OUT3    GPIO_RA7_OUT
#define STEPPER1_TRIS3   GPIO_RA7_TRIS
    
#define __USE_TIMER5__
#define STEPPER2_OUT0    GPIO_RB0_OUT
#define STEPPER2_TRIS0   GPIO_RB0_TRIS
#define STEPPER2_OUT1    GPIO_RB1_OUT
#define STEPPER2_TRIS1   GPIO_RB1_TRIS
#define STEPPER2_OUT2    GPIO_RB2_OUT
#define STEPPER2_TRIS2   GPIO_RB2_TRIS
#define STEPPER2_OUT3    GPIO_RB3_OUT
#define STEPPER2_TRIS3   GPIO_RB3_TRIS
#endif 
    
    
// PERIPHERALS
    
//Timers
#define __USE_TIMER4__    //not necessary with the generic timer/struct 
    
#else
    
// SENSORS
    
//T&H Sensor
//#define __USE_THSENSOR__
#ifdef __USE_THSENSOR__
#define SNSR_TnH_OUT    GPIO_RC4_OUT
#define SNSR_TnH_IN     GPIO_RC4_IN
#define SNSR_TnH_TRIS   GPIO_RC4_TRIS
#endif
    
//IR Dist Sensor
//#define __USE_IRDIST__
#ifdef __USE_IRDIST__
#define IRDIST_OUT      GPIO_RB0_OUT
#define IRDIST_IN      GPIO_RB0_IN
#define IRDIST_TRIS      GPIO_RB0_TRIS
#define IRDIST_PPS_VAL  0x08
#endif
    

// OUTPUT DEVICES
    
//4 digit 7-segment
//#define __USE_7SEGDISP__
#ifdef __USE_7SEGDISP__
#define DIG3_OUT GPIO_RC3_OUT
#define DIG3_TRIS GPIO_RC3_TRIS
#define DIG2_OUT GPIO_RC2_OUT
#define DIG2_TRIS GPIO_RC2_TRIS
#define DIG1_OUT GPIO_RC1_OUT
#define DIG1_TRIS GPIO_RC1_TRIS
#define DIG0_OUT GPIO_RC0_OUT
#define DIG0_TRIS GPIO_RC0_TRIS
#define DIGS_OUT LATC
#define SEGS_OUT LATD
#define SEGS_TRIS TRISD
#endif
    
//SG90 Servo Pins
//#define __USE_SERVO__
#ifdef __USE_SERVO__
#define SERVO_OUT   GPIO_RB4_OUT
#define SERVO_TRIS  GPIO_RB4_TRIS
#define __USE_TIMER1__
#define __USE_TIMER2__
#endif
    
//ULN2003 Stepper Driver
//#define __USE_STEPPER__
#ifdef __USE_STEPPER__
#define STEPPER_OUT0    GPIO_RA0_OUT
#define STEPPER_TRIS0   GPIO_RA0_TRIS
#define STEPPER_OUT1    GPIO_RA1_OUT
#define STEPPER_TRIS1   GPIO_RA1_TRIS
#define STEPPER_OUT2    GPIO_RA2_OUT
#define STEPPER_TRIS2   GPIO_RA2_TRIS
#define STEPPER_OUT3    GPIO_RA3_OUT
#define STEPPER_TRIS3   GPIO_RA3_TRIS
#endif 
    
//SSD1306 OLED LCD Display
#define __USE_OLEDDISP__
#ifdef __USE_OLEDDISP__    
#define __USE_I2C1__
#endif
    
// PERIPHERALS
    
//Timers
#define __USE_TIMER4__    //not necessary with the generic timer/struct 
    
//UART
#define __USE_UART1__
#ifdef __USE_UART1__
#define UART1_RX        GPIO_RB2_IN
#define UART1_RX_TRIS   GPIO_RB2_TRIS
#define UART1_RX_PPS_VAL    0b0100    //hardcoded value for RB2
#define UART1_TX        GPIO_RB3_OUT
#define UART1_TX_TRIS   GPIO_RB3_TRIS
#define UART1_TX_PPS    RPB3R          //set to 0b0001 for U1TX assignment
#define UART1_RST       GPIO_RB1_OUT
#define UART1_RST_TRIS  GPIO_RB1_TRIS
#endif 
    
#define __USE_I2C1__
#ifdef __USE_I2C1__
#define I2C1_CLK_TRIS       GPIO_RB8_TRIS
#define I2C1_CLK_ODCON      ODCBbits.ODCB8
#define I2C1_CLK_LVLSEL     INLVLBbits.INLVLB8
#define I2C1_DAT_TRIS       GPIO_RB9_TRIS
#define I2C1_DAT_ODCON      ODCBbits.ODCB9
#define I2C1_DAT_LVLSEL     INLVLBbits.INLVLB9
#define IOEXP_RST           GPIO_RB7_OUT
#define IOEXP_RST_TRIS      GPIO_RB7_TRIS
#endif
    
//#define __USE_ADC__        //UNCOMMENT THIS LINE TO ENABLE THE ADC MODULE
#ifdef __USE_ADC__
#define ADCTRIS     TRISA
#define ADCANSEL    ANSELA
#endif
    
#endif  /* Project Else */
    
#ifdef	__cplusplus
}
#endif

#endif	/* PICDEFS_H */

