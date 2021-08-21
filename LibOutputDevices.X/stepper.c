#include "stepper.h"

#ifdef __USE_STEPPER__
#ifdef __USE_STEPPER0__
STATUS_T setupStepper0(void)
{
#ifdef __STEPPER_GPIO__
    STEPPER0_OUT0 = 0;
    STEPPER0_TRIS0 = 0;
    STEPPER0_OUT1 = 0;
    STEPPER0_TRIS1 = 0;
    STEPPER0_OUT2 = 0;
    STEPPER0_TRIS2 = 0;
    STEPPER0_OUT3 = 0;
    STEPPER0_TRIS3 = 0;
#endif
    
    stepOutVal0 = 0x00;
    stepOutShift0 = false;
    stepState0 = 0;
    stepDirection0 = true;
    totalSteps0 = 0;
    allowStep0 = true;
//    allowStep0 = false; //allow timer isr to init the pins
    pendingSteps0 = 0;
    
#ifdef __PIC32M
    stepper0_off_time = 0;
    if(!T5CONbits.ON){
        stepper_global_time = 0;
        Tmr5Setup(100000,true,6);   //setup timer 5 to run at 100KHz (10us/interrupt), with interrupts running at prio level 5
        Tmr5Enable();               //start timer 5
    }
#endif
            
    return STAT_SUCCESS;
}

#ifndef __PIC32M
#ifdef __STEPPER_I2C__
void __interrupt(__irq(TMR1),high_priority) stepper0ISR(void){
#elif defined(__STEPPER_GPIO)
void stepper0ISR(void){
    if(TMR1IF){
#endif
#ifdef __PIC32M
        IFS0bits.T2IF = 0;
        Tmr2Disable();
#else
        TMR1IF = 0;
#endif
        if(pendingSteps0 == 0){
            stepOutVal0 = 0x00;
            if(!allowStep0) outputUpdate();
#ifdef __STEPPER_GPIO__
            STEPPER0_OUT0 = 0;
            STEPPER0_OUT1 = 0;
            STEPPER0_OUT2 = 0;
            STEPPER0_OUT3 = 0;
#endif
        }
        allowStep0 = true;
//    }
}
#endif

STATUS_T stepSMachine0(void)
{
    if(pendingSteps0 != 0 && allowStep0){
        return stepMotor0();
    }
    return STAT_IDLE;
}

STATUS_T stepMotorSM0(void)
{
    switch (stepState0) {
        case 0:
            stepOutVal0 = 0x08;
#ifdef __STEPPER_GPIO__
            STEPPER0_OUT0 = 0;
            STEPPER0_OUT1 = 0;
            STEPPER0_OUT2 = 0;
            STEPPER0_OUT3 = 1;
#endif
            break;
        case 1:
            stepOutVal0 = 0x0C;
#ifdef __STEPPER_GPIO__
            STEPPER0_OUT0 = 0;
            STEPPER0_OUT1 = 0;
            STEPPER0_OUT2 = 1;
            STEPPER0_OUT3 = 1;
#endif
            break;
        case 2:
            stepOutVal0 = 0x04;
#ifdef __STEPPER_GPIO__
            STEPPER0_OUT0 = 0;
            STEPPER0_OUT1 = 0;
            STEPPER0_OUT2 = 1;
            STEPPER0_OUT3 = 0;
#endif
            break;
        case 3:
            stepOutVal0 = 0x06;
#ifdef __STEPPER_GPIO__
            STEPPER0_OUT0 = 0;
            STEPPER0_OUT1 = 1;
            STEPPER0_OUT2 = 1;
            STEPPER0_OUT3 = 0;
#endif
            break;
        case 4:
            stepOutVal0 = 0x02;
#ifdef __STEPPER_GPIO__
            STEPPER0_OUT0 = 0;
            STEPPER0_OUT1 = 1;
            STEPPER0_OUT2 = 0;
            STEPPER0_OUT3 = 0;
#endif
            break;
        case 5:
            stepOutVal0 = 0x03;
#ifdef __STEPPER_GPIO__
            STEPPER0_OUT0 = 1;
            STEPPER0_OUT1 = 1;
            STEPPER0_OUT2 = 0;
            STEPPER0_OUT3 = 0;
#endif
            break;
        case 6:
            stepOutVal0 = 0x01;
#ifdef __STEPPER_GPIO__
            STEPPER0_OUT0 = 1;
            STEPPER0_OUT1 = 0;
            STEPPER0_OUT2 = 0;
            STEPPER0_OUT3 = 0;
#endif
            break;
        case 7:
            stepOutVal0 = 0x09;
#ifdef __STEPPER_GPIO__
            STEPPER0_OUT0 = 1;
            STEPPER0_OUT1 = 0;
            STEPPER0_OUT2 = 0;
            STEPPER0_OUT3 = 1;
#endif
            break;
        default:
            stepOutVal0 = 0x00;
#ifdef __STEPPER_GPIO__
            STEPPER0_OUT0 = 0;
            STEPPER0_OUT1 = 0;
            STEPPER0_OUT2 = 0;
            STEPPER0_OUT3 = 0;
#endif
            break;
    }
#ifdef __STEPPER_I2C__
    outputUpdate();
#endif
    updateStepState0();        
    
    return STAT_SUCCESS;
}

STATUS_T updateStepState0(void) {
    if (stepDirection0 == true) {
        stepState0++;
        totalSteps0++;
    }
    if (stepDirection0 == false) {
        stepState0--;
        totalSteps0--;
    }
    if (stepState0 > 7) {
        stepState0 = 0;
    }
    if (stepState0 < 0) {
        stepState0 = 7;
    }
#ifdef __PIC32M
    stepper0_off_time = stepper_global_time + 80;   //take current stepper timer value and add 80 to it to wait 800us before allowing next step
#else
    Tmr2Setup(1250,true);
    Tmr2Enable();
#endif
    allowStep0 = false;
    
    return STAT_SUCCESS;
} 

STATUS_T stepMotor0(void)
{
    if(pendingSteps0 < 0)
        stepDirection0 = false;
    else
        stepDirection0 = true;
    
    stepMotorSM0();
    
    if(pendingSteps0 < 0)
        pendingSteps0++; //increment pending steps to move negative toward zero
    else
        pendingSteps0--; //decrement pending steps to move positive toward zero

    return STAT_SUCCESS;
}

STATUS_T stepMotorFixed0(int16_t steps)
{
    if(steps < 0)
        stepDirection0 = false;
    else
        stepDirection0 = true;
    
    int step;
    for(step = 0; step < abs(steps); step++){
        stepMotorSM0();
#ifdef __PIC32M
        WDTCONCLR = _WDTCON_WDTCLR_MASK;
#else
        CLRWDT();
        __delay_us(800);
#endif
    }
    return STAT_SUCCESS;
}
#endif












#ifdef __USE_STEPPER1__
STATUS_T setupStepper1(void)
{
#ifdef __STEPPER_GPIO__
    STEPPER1_OUT0 = 0;
    STEPPER1_TRIS0 = 0;
    STEPPER1_OUT1 = 0;
    STEPPER1_TRIS1 = 0;
    STEPPER1_OUT2 = 0;
    STEPPER1_TRIS2 = 0;
    STEPPER1_OUT3 = 0;
    STEPPER1_TRIS3 = 0;
#endif
    
    stepOutVal1 = 0x00;
    stepOutShift0 = true;
    stepState1 = 0;
    stepDirection1 = true;
    totalSteps1 = 0;
    allowStep1 = true;
//    allowStep1 = false; //allow timer isr to init the pins
    pendingSteps1 = 0;
    
#ifdef __PIC32M
    stepper1_off_time = 0;
    if(!T5CONbits.ON){
        stepper_global_time = 0;
        Tmr5Setup(100000,true,6);   //setup timer 5 to run at 100KHz (10us/interrupt), with interrupts running at prio level 5
        Tmr5Enable();               //start timer 5
    }
#endif
            
    return STAT_SUCCESS;
}

#ifndef __PIC32M
#ifdef __STEPPER_I2C__
void __interrupt(__irq(TMR3),high_priority) stepper1ISR(void){
#elif defined(__STEPPER_GPIO)
void stepper1ISR(void){
    if(TMR3IF){
#endif
        TMR3IF = 0;
        if(pendingSteps1 == 0){
            stepOutVal1 = 0x00;
            if(!allowStep1) outputUpdate();
#ifdef __STEPPER_GPIO__
            STEPPER1_OUT0 = 0;
            STEPPER1_OUT1 = 0;
            STEPPER1_OUT2 = 0;
            STEPPER1_OUT3 = 0;
#endif
        }
        allowStep1 = true;
//    }
}
#endif

STATUS_T stepSMachine1(void)
{
    if(pendingSteps1 != 0 && allowStep1){
        return stepMotor1();
    }
    return STAT_IDLE;
}

STATUS_T stepMotorSM1(void)
{
    switch (stepState1) {
        case 0:
            stepOutVal1 = 0x08;
#ifdef __STEPPER_GPIO__
            STEPPER1_OUT0 = 0;
            STEPPER1_OUT1 = 0;
            STEPPER1_OUT2 = 0;
            STEPPER1_OUT3 = 1;
#endif
            break;
        case 1:
            stepOutVal1 = 0x0C;
#ifdef __STEPPER_GPIO__
            STEPPER1_OUT0 = 0;
            STEPPER1_OUT1 = 0;
            STEPPER1_OUT2 = 1;
            STEPPER1_OUT3 = 1;
#endif
            break;
        case 2:
            stepOutVal1 = 0x04;
#ifdef __STEPPER_GPIO__
            STEPPER1_OUT0 = 0;
            STEPPER1_OUT1 = 0;
            STEPPER1_OUT2 = 1;
            STEPPER1_OUT3 = 0;
#endif
            break;
        case 3:
            stepOutVal1 = 0x06;
#ifdef __STEPPER_GPIO__
            STEPPER1_OUT0 = 0;
            STEPPER1_OUT1 = 1;
            STEPPER1_OUT2 = 1;
            STEPPER1_OUT3 = 0;
#endif
            break;
        case 4:
            stepOutVal1 = 0x02;
#ifdef __STEPPER_GPIO__
            STEPPER1_OUT0 = 0;
            STEPPER1_OUT1 = 1;
            STEPPER1_OUT2 = 0;
            STEPPER1_OUT3 = 0;
#endif
            break;
        case 5:
            stepOutVal1 = 0x03;
#ifdef __STEPPER_GPIO__
            STEPPER1_OUT0 = 1;
            STEPPER1_OUT1 = 1;
            STEPPER1_OUT2 = 0;
            STEPPER1_OUT3 = 0;
#endif
            break;
        case 6:
            stepOutVal1 = 0x01;
#ifdef __STEPPER_GPIO__
            STEPPER1_OUT0 = 1;
            STEPPER1_OUT1 = 0;
            STEPPER1_OUT2 = 0;
            STEPPER1_OUT3 = 0;
#endif
            break;
        case 7:
            stepOutVal1 = 0x09;
#ifdef __STEPPER_GPIO__
            STEPPER1_OUT0 = 1;
            STEPPER1_OUT1 = 0;
            STEPPER1_OUT2 = 0;
            STEPPER1_OUT3 = 1;
#endif
            break;
        default:
            stepOutVal1 = 0x00;
#ifdef __STEPPER_GPIO__
            STEPPER1_OUT0 = 0;
            STEPPER1_OUT1 = 0;
            STEPPER1_OUT2 = 0;
            STEPPER1_OUT3 = 0;
#endif
            break;
    }
#ifdef __STEPPER_I2C__
    outputUpdate();
#endif
    
    updateStepState1();        
    
    return STAT_SUCCESS;
}

STATUS_T updateStepState1(void) {
    if (stepDirection1 == true) {
        stepState1++;
        totalSteps1++;
    }
    if (stepDirection1 == false) {
        stepState1--;
        totalSteps1--;
    }
    if (stepState1 > 7) {
        stepState1 = 0;
    }
    if (stepState1 < 0) {
        stepState1 = 7;
    }
#ifdef __PIC32M
    stepper1_off_time = stepper_global_time + 80;   //take current stepper timer value and add 80 to it to wait 800us before allowing next step
#else
    Tmr3Setup(1250,true,5);
    Tmr3Enable();
#endif
    allowStep1 = false;
    
    return STAT_SUCCESS;
} 

STATUS_T stepMotor1(void)
{
    if(pendingSteps1 < 0)
        stepDirection1 = false;
    else
        stepDirection1 = true;
    
    stepMotorSM1();
    
    if(pendingSteps1 < 0)
        pendingSteps1++; //increment pending steps to move negative toward zero
    else
        pendingSteps1--; //decrement pending steps to move positive toward zero

    return STAT_SUCCESS;
}

STATUS_T stepMotorFixed1(int16_t steps)
{
    if(steps < 0)
        stepDirection1 = false;
    else
        stepDirection1 = true;
    
    int step;
    for(step = 0; step < abs(steps); step++){
        stepMotorSM1();
#ifdef __PIC32M
        WDTCONCLR = _WDTCON_WDTCLR_MASK;
#else
        CLRWDT();
        __delay_us(800);
#endif
    }
    return STAT_SUCCESS;
}
#endif









#ifdef __USE_STEPPER2__
STATUS_T setupStepper2(void)
{
#ifdef __STEPPER_GPIO__
    STEPPER2_OUT0 = 0;
    STEPPER2_TRIS0 = 0;
    STEPPER2_OUT1 = 0;
    STEPPER2_TRIS1 = 0;
    STEPPER2_OUT2 = 0;
    STEPPER2_TRIS2 = 0;
    STEPPER2_OUT3 = 0;
    STEPPER2_TRIS3 = 0;
#endif
    
    stepOutVal2 = 0x00;
    stepOutShift2 = false;
    stepState2 = 0;
    stepDirection2 = true;
    totalSteps2 = 0;
    allowStep2 = true;
//    allowStep2 = false; //allow timer isr to init the pins
    pendingSteps2 = 0;
    
#ifdef __PIC32M
    stepper2_off_time = 0;
    if(!T5CONbits.ON){
        stepper_global_time = 0;
        Tmr5Setup(100000,true,6);   //setup timer 5 to run at 100KHz (10us/interrupt), with interrupts running at prio level 5
        Tmr5Enable();               //start timer 5
    }
#endif
            
    return STAT_SUCCESS;
}

#ifndef __PIC32M
#ifdef __STEPPER_I2C__
void __interrupt(__irq(TMR5),high_priority) stepper2ISR(void){
#elif defined(__STEPPER_GPIO)
void stepper1ISR(void){
    if(TMR5IF){
#endif
        TMR5IF = 0;
        if(pendingSteps2 == 0){
            stepOutVal2 = 0x00;
            if(!allowStep2) outputUpdate();
#ifdef __STEPPER_GPIO__
            STEPPER2_OUT0 = 0;
            STEPPER2_OUT1 = 0;
            STEPPER2_OUT2 = 0;
            STEPPER2_OUT3 = 0;
#endif
        }
        allowStep2 = true;
#if defined(__STEPPER_GPIO)
    }
#endif
} 
#endif

STATUS_T stepSMachine2(void)
{
    if(pendingSteps2 != 0 && allowStep2){
        return stepMotor2();
    }
    return STAT_IDLE;
}

STATUS_T stepMotorSM2(void)
{
    switch (stepState2) {
        case 0:
            stepOutVal2 = 0x08;
#ifdef __STEPPER_GPIO__
            STEPPER2_OUT0 = 0;
            STEPPER2_OUT1 = 0;
            STEPPER2_OUT2 = 0;
            STEPPER2_OUT3 = 1;
#endif
            break;
        case 1:
            stepOutVal2 = 0x0C;
#ifdef __STEPPER_GPIO__
            STEPPER2_OUT0 = 0;
            STEPPER2_OUT1 = 0;
            STEPPER2_OUT2 = 1;
            STEPPER2_OUT3 = 1;
#endif
            break;
        case 2:
            stepOutVal2 = 0x04;
#ifdef __STEPPER_GPIO__
            STEPPER2_OUT0 = 0;
            STEPPER2_OUT1 = 0;
            STEPPER2_OUT2 = 1;
            STEPPER2_OUT3 = 0;
#endif
            break;
        case 3:
            stepOutVal2 = 0x06;
#ifdef __STEPPER_GPIO__
            STEPPER2_OUT0 = 0;
            STEPPER2_OUT1 = 1;
            STEPPER2_OUT2 = 1;
            STEPPER2_OUT3 = 0;
#endif
            break;
        case 4:
            stepOutVal2 = 0x02;
#ifdef __STEPPER_GPIO__
            STEPPER2_OUT0 = 0;
            STEPPER2_OUT1 = 1;
            STEPPER2_OUT2 = 0;
            STEPPER2_OUT3 = 0;
#endif
            break;
        case 5:
            stepOutVal2 = 0x03;
#ifdef __STEPPER_GPIO__
            STEPPER2_OUT0 = 1;
            STEPPER2_OUT1 = 1;
            STEPPER2_OUT2 = 0;
            STEPPER2_OUT3 = 0;
#endif
            break;
        case 6:
            stepOutVal2 = 0x01;
#ifdef __STEPPER_GPIO__
            STEPPER2_OUT0 = 1;
            STEPPER2_OUT1 = 0;
            STEPPER2_OUT2 = 0;
            STEPPER2_OUT3 = 0;
#endif
            break;
        case 7:
            stepOutVal2 = 0x09;
#ifdef __STEPPER_GPIO__
            STEPPER2_OUT0 = 1;
            STEPPER2_OUT1 = 0;
            STEPPER2_OUT2 = 0;
            STEPPER2_OUT3 = 1;
#endif
            break;
        default:
            stepOutVal2 = 0x00;
#ifdef __STEPPER_GPIO__
            STEPPER2_OUT0 = 0;
            STEPPER2_OUT1 = 0;
            STEPPER2_OUT2 = 0;
            STEPPER2_OUT3 = 0;
#endif
            break;
    }
#ifdef __STEPPER_I2C__
    outputUpdate();
#endif
    updateStepState2();        
    
    return STAT_SUCCESS;
}

STATUS_T updateStepState2(void) {
    if (stepDirection2 == true) {
        stepState2++;
        totalSteps2++;
    }
    if (stepDirection2 == false) {
        stepState2--;
        totalSteps2--;
    }
    if (stepState2 > 7) {
        stepState2 = 0;
    }
    if (stepState2 < 0) {
        stepState2 = 7;
    }
#ifdef __PIC32M
    stepper2_off_time = stepper_global_time + 80;   //take current stepper timer value and add 80 to it to wait 800us before allowing next step
#else
    Tmr5Setup(1250,true,5);
    Tmr5Enable();
#endif
    allowStep2 = false;
    
    return STAT_SUCCESS;
} 

STATUS_T stepMotor2(void)
{
    if(pendingSteps2 < 0)
        stepDirection2 = false;
    else
        stepDirection2 = true;
    
    stepMotorSM2();
    
    if(pendingSteps2 < 0)
        pendingSteps2++; //increment pending steps to move negative toward zero
    else
        pendingSteps2--; //decrement pending steps to move positive toward zero

    return STAT_SUCCESS;
}

STATUS_T stepMotorFixed2(int16_t steps)
{
    if(steps < 0)
        stepDirection2 = false;
    else
        stepDirection2 = true;
    
    int step;
    for(step = 0; step < abs(steps); step++){
        stepMotorSM2();
#ifdef __PIC32M
        WDTCONCLR = _WDTCON_WDTCLR_MASK;
#else
        CLRWDT();
        __delay_us(800);
#endif
    }
    return STAT_SUCCESS;
}
#endif

#ifdef __STEPPER_I2C__
STATUS_T outputUpdate(void)
{
#ifdef __USE_STEPPER0__
    ioexp1.P0OVal.nibbleL = stepOutVal0;
#endif
#ifdef __USE_STEPPER1__
    ioexp1.P0OVal.nibbleH = stepOutVal1;
#endif
#ifdef __USE_STEPPER2__
    ioexp1.P1OVal.nibbleL = stepOutVal2;
#endif
////    uint16_t newIOVal = ((ioexp1.P1OVal.val) << 8) + (ioexp1.P0OVal.val);
    uint16_t newIOVal = ioexp1.P1OVal.val;
    newIOVal <<= 8;
    newIOVal  += ioexp1.P0OVal.val;
    
    IOExpUpdateOut(&ioexp1,newIOVal);
//    IOExpUpdateOutPart(&ioexp1,ioexp1.P0OVal.val, 0);
//    IOExpUpdateOutPart(&ioexp1,ioexp1.P1OVal.val, 1);
    
    return STAT_SUCCESS;
}
#ifdef __PIC32M
void __ISR(_TIMER_5_VECTOR,IPL6AUTO) stepperISR(void){
//        IFS0bits.T5IF = 0;
    IFS0CLR = _IFS0_T5IF_MASK;

#ifdef __USE_STEPPER0__
        if(stepper0_off_time == stepper_global_time){   //on the interrupt where 0 == global, allow the next step and if done, output 0s to pins
            if(pendingSteps0 == 0){
                stepOutVal0 = 0x00;
                if(!allowStep0) outputUpdate();
            }
            allowStep0 = true;
        }
#endif
#ifdef __USE_STEPPER1__
        if(stepper1_off_time == stepper_global_time){   //on the interrupt where 1 == global, allow the next step and if done, output 0s to pins
            if(pendingSteps1 == 0){
                stepOutVal1 = 0x00;
                if(!allowStep1) outputUpdate();
            }
            allowStep1 = true;
        }
#endif
#ifdef __USE_STEPPER2__
        if(stepper2_off_time == stepper_global_time){   //on the interrupt where 2 == global, allow the next step and if done, output 0s to pins
            if(pendingSteps2 == 0){
                stepOutVal2 = 0x00;
                if(!allowStep2) outputUpdate();
            }
            allowStep2 = true;
        }
#endif
        
        stepper_global_time++;
}
#endif
#endif
   





//STATUS_T setupStepper(struct STEPPER Mod, 
//        uint8_t tmrNum, uint8_t tmrBitVal, 
//        uint8_t * out0_lat, uint8_t * out0_tris, uint8_t out0_bit, 
//        uint8_t * out1_lat, uint8_t * out1_tris, uint8_t out1_bit, 
//        uint8_t * out2_lat, uint8_t * out2_tris, uint8_t out2_bit, 
//        uint8_t * out3_lat, uint8_t * out3_tris, uint8_t out3_bit
//)
//{
//    Mod.STEPPER_0_OUT = out0_lat;
//    Mod.STEPPER_0_TRIS = out0_tris;
//    Mod.stepper_0_bitval = out0_bit;
//    Mod.STEPPER_1_OUT = out1_lat;
//    Mod.STEPPER_1_TRIS = out1_tris;
//    Mod.stepper_1_bitval = out1_bit;
//    Mod.STEPPER_2_OUT = out2_lat;
//    Mod.STEPPER_2_TRIS = out2_tris;
//    Mod.stepper_2_bitval = out2_bit;
//    Mod.STEPPER_3_OUT = out3_lat;
//    Mod.STEPPER_3_TRIS = out3_tris;
//    Mod.stepper_3_bitval = out3_bit;
//    *(Mod.STEPPER_0_OUT) &= ~Mod.stepper_0_bitval;
//    *(Mod.STEPPER_0_TRIS) &= ~Mod.stepper_0_bitval;
//    *(Mod.STEPPER_1_OUT) &= ~Mod.stepper_1_bitval;
//    *(Mod.STEPPER_1_TRIS) &= ~Mod.stepper_1_bitval;
//    *(Mod.STEPPER_2_OUT) &= ~Mod.stepper_2_bitval;
//    *(Mod.STEPPER_2_TRIS) &= ~Mod.stepper_2_bitval;
//    *(Mod.STEPPER_3_OUT) &= ~Mod.stepper_3_bitval;
//    *(Mod.STEPPER_3_TRIS) &= ~Mod.stepper_3_bitval;
//    
//    Mod.stepState = 0;
//    Mod.stepDirection = true;
//    Mod.totalSteps = 0;
//    Mod.allowStep = true;
//    Mod.pendingSteps = 0;
//    Mod.timerNum = tmrNum;
//    Mod.timerIntBitVal = tmrBitVal;
//            
//    return STAT_SUCCESS;
//}
//
//STATUS_T stepMotorSM(struct STEPPER Mod)
//{
//    switch (Mod.stepState) {
//        case 0:
////            if(Mod.ioSetNum == 0){
////                STEPPER0_OUT0 = 0;
////                STEPPER0_OUT1 = 0;
////                STEPPER0_OUT2 = 0;
////                STEPPER0_OUT3 = 1;
////            } else if(Mod.ioSetNum == 1){
////                STEPPER1_OUT0 = 0;
////                STEPPER1_OUT1 = 0;
////                STEPPER1_OUT2 = 0;
////                STEPPER1_OUT3 = 1;                
////            }
//            *(Mod.STEPPER_0_OUT) &= ~Mod.stepper_0_bitval;
//            *(Mod.STEPPER_1_OUT) &= ~Mod.stepper_1_bitval;
//            *(Mod.STEPPER_2_OUT) &= ~Mod.stepper_2_bitval;
//            *(Mod.STEPPER_3_OUT) |= Mod.stepper_3_bitval;
//            break;
//        case 1:
////            if(Mod.ioSetNum == 0){
////                STEPPER0_OUT0 = 0;
////                STEPPER0_OUT1 = 0;
////                STEPPER0_OUT2 = 1;
////                STEPPER0_OUT3 = 1;
////            } else if(Mod.ioSetNum == 1){
////                STEPPER1_OUT0 = 0;
////                STEPPER1_OUT1 = 0;
////                STEPPER1_OUT2 = 1;
////                STEPPER1_OUT3 = 1;                
////            }
//            *(Mod.STEPPER_0_OUT) &= ~Mod.stepper_0_bitval;
//            *(Mod.STEPPER_1_OUT) &= ~Mod.stepper_1_bitval;
//            *(Mod.STEPPER_2_OUT) |= Mod.stepper_2_bitval;
//            *(Mod.STEPPER_3_OUT) |= Mod.stepper_3_bitval;
//            break;
//        case 2:
////            if(Mod.ioSetNum == 0){
////                STEPPER0_OUT0 = 0;
////                STEPPER0_OUT1 = 0;
////                STEPPER0_OUT2 = 1;
////                STEPPER0_OUT3 = 0;
////            } else if(Mod.ioSetNum == 1){
////                STEPPER1_OUT0 = 0;
////                STEPPER1_OUT1 = 0;
////                STEPPER1_OUT2 = 1;
////                STEPPER1_OUT3 = 0;                
////            }
//            *(Mod.STEPPER_0_OUT) &= ~Mod.stepper_0_bitval;
//            *(Mod.STEPPER_1_OUT) &= ~Mod.stepper_1_bitval;
//            *(Mod.STEPPER_2_OUT) |= Mod.stepper_2_bitval;
//            *(Mod.STEPPER_3_OUT) &= ~Mod.stepper_3_bitval;
//            break;
//        case 3:
////            if(Mod.ioSetNum == 0){
////                STEPPER0_OUT0 = 0;
////                STEPPER0_OUT1 = 1;
////                STEPPER0_OUT2 = 1;
////                STEPPER0_OUT3 = 0;
////            } else if(Mod.ioSetNum == 1){
////                STEPPER1_OUT0 = 0;
////                STEPPER1_OUT1 = 1;
////                STEPPER1_OUT2 = 1;
////                STEPPER1_OUT3 = 0;                
////            }
//            *(Mod.STEPPER_0_OUT) &= ~Mod.stepper_0_bitval;
//            *(Mod.STEPPER_1_OUT) |= Mod.stepper_1_bitval;
//            *(Mod.STEPPER_2_OUT) |= Mod.stepper_2_bitval;
//            *(Mod.STEPPER_3_OUT) &= ~Mod.stepper_3_bitval;
//            break;
//        case 4:
////            if(Mod.ioSetNum == 0){
////                STEPPER0_OUT0 = 0;
////                STEPPER0_OUT1 = 1;
////                STEPPER0_OUT2 = 0;
////                STEPPER0_OUT3 = 0;
////            } else if(Mod.ioSetNum == 1){
////                STEPPER1_OUT0 = 0;
////                STEPPER1_OUT1 = 1;
////                STEPPER1_OUT2 = 0;
////                STEPPER1_OUT3 = 0;                
////            }
//            *(Mod.STEPPER_0_OUT) &= ~Mod.stepper_0_bitval;
//            *(Mod.STEPPER_1_OUT) |= Mod.stepper_1_bitval;
//            *(Mod.STEPPER_2_OUT) &= ~Mod.stepper_2_bitval;
//            *(Mod.STEPPER_3_OUT) &= ~Mod.stepper_3_bitval;
//            break;
//        case 5:
////            if(Mod.ioSetNum == 0){
////                STEPPER0_OUT0 = 1;
////                STEPPER0_OUT1 = 1;
////                STEPPER0_OUT2 = 0;
////                STEPPER0_OUT3 = 0;
////            } else if(Mod.ioSetNum == 1){
////                STEPPER1_OUT0 = 1;
////                STEPPER1_OUT1 = 1;
////                STEPPER1_OUT2 = 0;
////                STEPPER1_OUT3 = 0;                
////            }
//            *(Mod.STEPPER_0_OUT) |= Mod.stepper_0_bitval;
//            *(Mod.STEPPER_1_OUT) |= Mod.stepper_1_bitval;
//            *(Mod.STEPPER_2_OUT) &= ~Mod.stepper_2_bitval;
//            *(Mod.STEPPER_3_OUT) &= ~Mod.stepper_3_bitval;
//            break;
//        case 6:
////            if(Mod.ioSetNum == 0){
////                STEPPER0_OUT0 = 1;
////                STEPPER0_OUT1 = 0;
////                STEPPER0_OUT2 = 0;
////                STEPPER0_OUT3 = 0;
////            } else if(Mod.ioSetNum == 1){
////                STEPPER1_OUT0 = 1;
////                STEPPER1_OUT1 = 0;
////                STEPPER1_OUT2 = 0;
////                STEPPER1_OUT3 = 0;                
////            }
//            *(Mod.STEPPER_0_OUT) |= Mod.stepper_0_bitval;
//            *(Mod.STEPPER_1_OUT) &= ~Mod.stepper_1_bitval;
//            *(Mod.STEPPER_2_OUT) &= ~Mod.stepper_2_bitval;
//            *(Mod.STEPPER_3_OUT) &= ~Mod.stepper_3_bitval;
//            break;
//        case 7:
////            if(Mod.ioSetNum == 0){
////                STEPPER0_OUT0 = 1;
////                STEPPER0_OUT1 = 0;
////                STEPPER0_OUT2 = 0;
////                STEPPER0_OUT3 = 1;
////            } else if(Mod.ioSetNum == 1){
////                STEPPER1_OUT0 = 1;
////                STEPPER1_OUT1 = 0;
////                STEPPER1_OUT2 = 0;
////                STEPPER1_OUT3 = 1;                
////            }
//            *(Mod.STEPPER_0_OUT) |= Mod.stepper_0_bitval;
//            *(Mod.STEPPER_1_OUT) &= ~Mod.stepper_1_bitval;
//            *(Mod.STEPPER_2_OUT) &= ~Mod.stepper_2_bitval;
//            *(Mod.STEPPER_3_OUT) |= Mod.stepper_3_bitval;
//            break;
//        default:
////            if(Mod.ioSetNum == 0){
////                STEPPER0_OUT0 = 0;
////                STEPPER0_OUT1 = 0;
////                STEPPER0_OUT2 = 0;
////                STEPPER0_OUT3 = 0;
////            } else if(Mod.ioSetNum == 1){
////                STEPPER1_OUT0 = 0;
////                STEPPER1_OUT1 = 0;
////                STEPPER1_OUT2 = 0;
////                STEPPER1_OUT3 = 0;                
////            }
//            *(Mod.STEPPER_0_OUT) &= ~Mod.stepper_0_bitval;
//            *(Mod.STEPPER_1_OUT) &= ~Mod.stepper_1_bitval;
//            *(Mod.STEPPER_2_OUT) &= ~Mod.stepper_2_bitval;
//            *(Mod.STEPPER_3_OUT) &= ~Mod.stepper_3_bitval;
//            break;
//    }
//    updateStepState(Mod);        
//    
//    return STAT_SUCCESS;
//}
//
//STATUS_T updateStepState(struct STEPPER Mod)
//{
//    if (Mod.stepDirection == true) {
//        Mod.stepState++;
//        Mod.totalSteps++;
//    }
//    if (Mod.stepDirection == false) {
//        Mod.stepState--;
//        Mod.totalSteps--;
//    }
//    if (Mod.stepState > 7) {
//        Mod.stepState = 0;
//    }
//    if (Mod.stepState < 0) {
//        Mod.stepState = 7;
//    }
//    if(Mod.timerNum == 1){
//        GPIO_RB5_OUT ^= 1;
//        Tmr1Setup(1250,true);
//        Tmr1Enable();
//    } else if(Mod.timerNum == 3){
//        Tmr3Setup(1250,true);
//        Tmr3Enable();
//    } else if(Mod.timerNum == 5){
//        Tmr5Setup(1250,true);
//        Tmr5Enable();
//    }
//    Mod.allowStep = false;
//    
//    return STAT_SUCCESS;
//}
//
//STATUS_T stepMotor(struct STEPPER Mod)
//{
//    GPIO_RB5_OUT ^= 1;
//    if(Mod.pendingSteps < 0)
//        Mod.stepDirection = false;
//    else
//        Mod.stepDirection = true;
//    
//    stepMotorSM(Mod);
//    
//    if(Mod.pendingSteps < 0)
//        Mod.pendingSteps++; //increment pending steps to move negative toward zero
//    else
//        Mod.pendingSteps--; //decrement pending steps to move positive toward zero
//
//    return STAT_SUCCESS;
//}
//
//STATUS_T stepMotorFixed(struct STEPPER Mod,int16_t steps)
//{
//    if(steps < 0)
//        Mod.stepDirection = false;
//    else
//        Mod.stepDirection = true;
//    
//    for(int step = 0; step < abs(steps); step++){
//        stepMotorSM(Mod);
//        CLRWDT();
//        __delay_us(800);
//    }
//    return STAT_SUCCESS;
//}



#endif