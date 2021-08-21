#include "stepper.h"


STATUS_T setupStepper(void)
{
    
    STEPPER_OUT0 = 0;
    STEPPER_TRIS0 = 0;
    STEPPER_OUT1 = 0;
    STEPPER_TRIS1 = 0;
    STEPPER_OUT2 = 0;
    STEPPER_TRIS2 = 0;
    STEPPER_OUT3 = 0;
    STEPPER_TRIS3 = 0;
    
    Steps = 0;
    Direction = true;
    totalSteps = 0;
            
    return STAT_SUCCESS;
}

//STATUS_T stepMotor(int16_t steps)
//{
//    bool dir = true;
//    if(steps < 0)
//        dir = false;
//    for(int step = 0; step < abs(steps); step++){
//        
//    }
//    return STAT_SUCCESS;
//}




void stepper(int xw) {
    GPIO_RB5_OUT ^= 1;
    for (int x = 0; x < xw; x++) {
        switch (Steps) {
            case 0:
                STEPPER_OUT0 = 0;
                STEPPER_OUT1 = 0;
                STEPPER_OUT2 = 0;
                STEPPER_OUT3 = 1;
                break;
            case 1:
                STEPPER_OUT0 = 0;
                STEPPER_OUT1 = 0;
                STEPPER_OUT2 = 1;
                STEPPER_OUT3 = 1;
                break;
            case 2:
                STEPPER_OUT0 = 0;
                STEPPER_OUT1 = 0;
                STEPPER_OUT2 = 1;
                STEPPER_OUT3 = 0;
                break;
            case 3:
                STEPPER_OUT0 = 0;
                STEPPER_OUT1 = 1;
                STEPPER_OUT2 = 1;
                STEPPER_OUT3 = 0;
                break;
            case 4:
                STEPPER_OUT0 = 0;
                STEPPER_OUT1 = 1;
                STEPPER_OUT2 = 0;
                STEPPER_OUT3 = 0;
                break;
            case 5:
                STEPPER_OUT0 = 1;
                STEPPER_OUT1 = 1;
                STEPPER_OUT2 = 0;
                STEPPER_OUT3 = 0;
                break;
            case 6:
                STEPPER_OUT0 = 1;
                STEPPER_OUT1 = 0;
                STEPPER_OUT2 = 0;
                STEPPER_OUT3 = 0;
                break;
            case 7:
                STEPPER_OUT0 = 1;
                STEPPER_OUT1 = 0;
                STEPPER_OUT2 = 0;
                STEPPER_OUT3 = 1;
                break;
            default:
                STEPPER_OUT0 = 0;
                STEPPER_OUT1 = 0;
                STEPPER_OUT2 = 0;
                STEPPER_OUT3 = 0;
                break;
        }
        if(x < (xw-1))
            __delay_us(800);
        SetDirection();
    }
}

void SetDirection(void) {
    if (Direction == 1) {
        Steps++;
        totalSteps++;
    }
    if (Direction == 0) {
        Steps--;
        totalSteps--;
    }
    if (Steps > 7) {
        Steps = 0;
    }
    if (Steps < 0) {
        Steps = 7;
    }
} 