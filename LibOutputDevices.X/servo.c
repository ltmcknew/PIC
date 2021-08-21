#include "servo.h"

#ifdef __USE_SERVO__
STATUS_T setupServo(int8_t initAngle)
{
    SERVO_OUT = 0;
    SERVO_TRIS = 0;
    
    servoTimeVal = 0;
    servoCnts = 0;
    servoAngleUse = initAngle;
    
    setServoAngle(initAngle);
    
#ifndef PIC32M
    if(Tmr2Setup(1000, true) == STAT_SUCCESS){
        Tmr2Enable();
    } else {
        return STAT_FAIL;
    }
#else
    Tmr2Setup(50,true,6);
    Tmr2Enable();
#endif
    
    return STAT_SUCCESS;
}

STATUS_T setServoAngle(int8_t setAngle)
{
    //convert desired angle to a corresponding period for Timer1
    //Timer1 will take a period value as if it were going to repeat the pulse but it will not be restarted when the interrupt fires
    //1.5ms is 0deg, 1ms is -90 and 2ms is +90
    // angle * period/angle + period offset = period
    // 0 * A + B = 0.0015
    // -90 * A + B = 0.001
    // 90 * A + B = 0.002
    // 2B = 0.003, B = 0.0015
    // 90 * A = 0.0005
    // A = 0.000005556 = 1 / 180000
    
    // (Angle + 270) / 180000 = period
    // 180000 / (Angle + 270) = Freq
    
#ifndef PIC32M
    PIE4bits.TMR2IE = 0;
#endif
    servoCnts = 270 + setAngle;
    servoCnts = 180000 / servoCnts;  
#ifndef PIC32M  
    PIE4bits.TMR2IE = 1;
#endif
//    servoStartPulseTimer();
    
    return STAT_SUCCESS;
}

void servoStartPulseTimer(void)
{
#ifndef PIC32M
    Tmr1Setup(servoCnts,true);
    Tmr1Enable();
#else
    Tmr3Setup(servoCnts,true,6);
    Tmr3Enable();
#endif
    SERVO_OUT = 1;
//    SERVO_OUT = 0;
}

void servoEndPulse(void)
{
    SERVO_OUT = 0;
//    SERVO_OUT = 1;
#ifndef PIC32M
    Tmr1Disable();
#else
    Tmr3Disable();
#endif
}
#endif