#include "servo.h"


STATUS_T setupServo(int8_t initAngle)
{
    SERVO_OUT = 0;
    SERVO_TRIS = 0;
    
    servoTimeVal = 0;
    servoCnts = 0;
    
    setServoAngle(initAngle);
    
    if(Tmr2Setup(1000, true) == STAT_SUCCESS){
        Tmr2Enable();
    } else {
        return STAT_FAIL;
    }
    
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
    //90 * A = 0.0005
    // A = 0.000005556 = 1 / 180000
    
    // Angle / 180000 + 0.0015 = period
    // Angle / 9 * 5 / 100000 + 0.0015 = period
    // Angle / 9 / 20000 + 0.0015 = period
    // Angle / 9 + 30 = 20K * period
    // Angle + 270 = 180K * period
    // 1 / (Angle + 270) = 1/180K * Freq
    // 180000 / (Angle + 270) = Freq
    
    PIE4bits.TMR2IE = 0;
    servoCnts = 270 + setAngle;
    servoCnts = 180000 / servoCnts;    
    PIE4bits.TMR2IE = 1;
    
    return STAT_SUCCESS;
}

void servoStartPulseTimer(void)
{
    Tmr1Setup(servoCnts,true);
    Tmr1Enable();
    SERVO_OUT = 1;
}

void servoEndPulse(void)
{
    SERVO_OUT = 0;
    Tmr1Disable();
}