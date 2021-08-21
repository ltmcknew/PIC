#include "ccppwm.h"


#ifdef __USE_PWM1__
STATUS_T Pwm1Setup(uint8_t timerNum, uint16_t timerFreq, uint16_t initDCVal)
{
    PWM1OUT_PPS = PWM1PPS_VAL;
    Pwm1TmrNum = timerNum;
    
    Pwm1Disable();
    
    Tmr2Setup(timerFreq,false);
    
    if(Pwm1TmrNum == 2){
        Tmr2Setup(timerFreq,false);
        Pwm1DCMaxVal = (T2PR+1)<<2;
    } else if(Pwm1TmrNum == 4){
        Tmr4Setup(timerFreq,false);
        Pwm1DCMaxVal = (T4PR+1)<<2;
    } else if(Pwm1TmrNum == 6){
        Tmr6Setup(timerFreq,false);
        Pwm1DCMaxVal = (T6PR+1)<<2;
    } 
    if(Pwm1DCMaxVal >= 1024)
        Pwm1DCMaxVal = 1023;
    
    CCP1CONbits.CCP1MODE = 0b1111;  //hardcode PWM mode
    CCP1CONbits.CCP1FMT = 0;        //right align the register use
    
    CCPTMRS0bits.C1TSEL = 0b11;     //select Timer6 for clock source
    
    Pwm1UpdateDC(initDCVal);
    
    return STAT_SUCCESS;
}

STATUS_T Pwm1Enable()
{
    PWM1OUT_TRIS = 0;
    CCP1CONbits.CCP1EN = 1;
//    Tmr2Enable();
    if(Pwm1TmrNum == 2){
        Tmr2Enable();
    } else if(Pwm1TmrNum == 4){
        Tmr4Enable();
    } else if(Pwm1TmrNum == 6){
        Tmr6Enable();
    } 
    return STAT_SUCCESS;
}

STATUS_T Pwm1Disable()
{
    PWM1OUT_TRIS = 1;
    CCP1CONbits.CCP1EN = 0;
//    Tmr2Disable();
    if(Pwm1TmrNum == 2){
        Tmr2Disable();
    } else if(Pwm1TmrNum == 4){
        Tmr4Disable();
    } else if(Pwm1TmrNum == 6){
        Tmr6Disable();
    } 
    return STAT_SUCCESS;
}

STATUS_T Pwm1UpdateDC(int16_t newDCPct)
{
    if(newDCPct < 0)
        newDCPct = 0;
    if(newDCPct > PWMMAXPCT)
        newDCPct = PWMMAXPCT;
    
    uint32_t useVal = Pwm1DCMaxVal;
    useVal *= newDCPct;  //this is a 10bit number * a 16bit number so result will be a 26bit number, the newDCVal is a percentage * 100 or 10000 = 100.00%
    useVal /= PWMMAXPCT;                            //must divide by 10000 to apply shift correctly, this will preserve as much precision as possible
    Pwm1DCPct = newDCPct;
    
    if(useVal > Pwm1DCMaxVal){
        useVal = Pwm1DCMaxVal;
        Pwm1DCPct = PWMMAXPCT;
    }
    
    Pwm1DCVal = useVal;
    CCPR1 = Pwm1DCVal;
    
    return STAT_SUCCESS;
}
#endif 

#ifdef __USE_PWM2__
STATUS_T Pwm2Setup(uint8_t timerNum, uint16_t timerFreq, uint16_t initDCVal)
{
    PWM2OUT_PPS = PWM2PPS_VAL;
    Pwm2TmrNum = timerNum;
    
    Pwm2Disable();

    if(Pwm2TmrNum == 2){
        Tmr2Setup(timerFreq,false);
        Pwm2DCMaxVal = (T2PR+1)<<2;
    } else if(Pwm2TmrNum == 4){
        Tmr4Setup(timerFreq,false);
        Pwm2DCMaxVal = (T4PR+1)<<2;
    } else if(Pwm2TmrNum == 6){
        Tmr6Setup(timerFreq,false);
        Pwm2DCMaxVal = (T6PR+1)<<2;
    } 
    if(Pwm2DCMaxVal >= 1024)
        Pwm2DCMaxVal = 1023;
    
    CCP2CONbits.CCP2MODE = 0b1111;  //hardcode PWM mode
    CCP2CONbits.CCP2FMT = 0;        //right align the register use
    
    CCPTMRS0bits.C2TSEL = 0b11;     //select Timer6 for clock source
    
    Pwm2UpdateDC(initDCVal);
    
    return STAT_SUCCESS;
}

STATUS_T Pwm2Enable()
{
    PWM2OUT_TRIS = 0;
    CCP2CONbits.CCP2EN = 1;
//    Tmr2Enable();
    if(Pwm2TmrNum == 2){
        Tmr2Enable();
    } else if(Pwm2TmrNum == 4){
        Tmr4Enable();
    } else if(Pwm2TmrNum == 6){
        Tmr6Enable();
    } 
    return STAT_SUCCESS;
}

STATUS_T Pwm2Disable()
{
    PWM2OUT_TRIS = 1;
    CCP2CONbits.CCP2EN = 0;
//    Tmr2Disable();
    if(Pwm2TmrNum == 2){
        Tmr2Disable();
    } else if(Pwm2TmrNum == 4){
        Tmr4Disable();
    } else if(Pwm2TmrNum == 6){
        Tmr6Disable();
    } 
    return STAT_SUCCESS;
}

STATUS_T Pwm2UpdateDC(int16_t newDCPct)
{
    if(newDCPct < 0)
        newDCPct = 0;
    if(newDCPct > PWMMAXPCT)
        newDCPct = PWMMAXPCT;
    
    uint32_t useVal = Pwm2DCMaxVal;
    useVal *= newDCPct;  //this is a 10bit number * a 16bit number so result will be a 26bit number, the newDCVal is a percentage * 100 or 10000 = 100.00%
    useVal /= PWMMAXPCT;                            //must divide by 10000 to apply shift correctly, this will preserve as much precision as possible
    Pwm2DCPct = newDCPct;
    
    if(useVal > Pwm2DCMaxVal){
        useVal = Pwm2DCMaxVal;
        Pwm2DCPct = PWMMAXPCT;
    }
    
    Pwm2DCVal = useVal;
    CCPR2 = Pwm2DCVal;
    
    return STAT_SUCCESS;
}
#endif 

#ifdef __USE_PWM3__
STATUS_T Pwm3Setup(uint8_t timerNum, uint16_t timerFreq, uint16_t initDCVal)
{
    PWM3OUT_PPS = PWM3PPS_VAL;
    Pwm3TmrNum = timerNum;
    
    Pwm3Disable();
    
    Tmr2Setup(timerFreq,false);
    
    if(Pwm3TmrNum == 2){
        Tmr2Setup(timerFreq,false);
        Pwm3DCMaxVal = (T2PR+1)<<2;
    } else if(Pwm3TmrNum == 4){
        Tmr4Setup(timerFreq,false);
        Pwm3DCMaxVal = (T4PR+1)<<2;
    } else if(Pwm3TmrNum == 6){
        Tmr6Setup(timerFreq,false);
        Pwm3DCMaxVal = (T6PR+1)<<2;
    } 
    if(Pwm3DCMaxVal >= 1024)
        Pwm3DCMaxVal = 1023;
    
    CCP3CONbits.CCP3MODE = 0b1111;  //hardcode PWM mode
    CCP3CONbits.CCP3FMT = 0;        //right align the register use
    
    CCPTMRS0bits.C3TSEL = 0b11;     //select Timer6 for clock source
    
    Pwm3UpdateDC(initDCVal);
    
    return STAT_SUCCESS;
}

STATUS_T Pwm3Enable()
{
    PWM3OUT_TRIS = 0;
    CCP3CONbits.CCP3EN = 1;
//    Tmr2Enable();
    if(Pwm3TmrNum == 2){
        Tmr2Enable();
    } else if(Pwm3TmrNum == 4){
        Tmr4Enable();
    } else if(Pwm3TmrNum == 6){
        Tmr6Enable();
    } 
    return STAT_SUCCESS;
}

STATUS_T Pwm3Disable()
{
    PWM3OUT_TRIS = 1;
    CCP3CONbits.CCP3EN = 0;
//    Tmr2Disable();
    if(Pwm3TmrNum == 2){
        Tmr2Disable();
    } else if(Pwm3TmrNum == 4){
        Tmr4Disable();
    } else if(Pwm3TmrNum == 6){
        Tmr6Disable();
    } 
    return STAT_SUCCESS;
}

STATUS_T Pwm3UpdateDC(int16_t newDCPct)
{
    if(newDCPct < 0)
        newDCPct = 0;
    if(newDCPct > PWMMAXPCT)
        newDCPct = PWMMAXPCT;
    
    uint32_t useVal = Pwm3DCMaxVal;
    useVal *= newDCPct;  //this is a 10bit number * a 16bit number so result will be a 26bit number, the newDCVal is a percentage * 100 or 10000 = 100.00%
    useVal /= PWMMAXPCT;                            //must divide by 10000 to apply shift correctly, this will preserve as much precision as possible
    Pwm3DCPct = newDCPct;
    
    if(useVal > Pwm3DCMaxVal){
        useVal = Pwm3DCMaxVal;
        Pwm3DCPct = PWMMAXPCT;
    }
    
    Pwm3DCVal = useVal;
    CCPR3 = Pwm3DCVal;
    
    return STAT_SUCCESS;
}
#endif 

#ifdef __USE_PWM4__
STATUS_T Pwm4Setup(uint8_t timerNum, uint16_t timerFreq, uint16_t initDCVal)
{
    PWM4OUT_PPS = PWM4PPS_VAL;
    Pwm4TmrNum = timerNum;
    
    Pwm4Disable();
    
    Tmr4Setup(timerFreq,false);
    
    if(Pwm4TmrNum == 2){
        Tmr2Setup(timerFreq,false);
        Pwm4DCMaxVal = (T2PR+1)<<2;
    } else if(Pwm4TmrNum == 4){
        Tmr4Setup(timerFreq,false);
        Pwm4DCMaxVal = (T4PR+1)<<2;
    } else if(Pwm4TmrNum == 6){
        Tmr6Setup(timerFreq,false);
        Pwm4DCMaxVal = (T6PR+1)<<2;
    } 
    if(Pwm4DCMaxVal >= 1024)
        Pwm4DCMaxVal = 1023;
    
    CCP4CONbits.CCP4MODE = 0b1111;  //hardcode PWM mode
    CCP4CONbits.CCP4FMT = 0;        //right align the register use
    
    CCPTMRS0bits.C4TSEL = 0b01;     //select Timer2 for clock source
    
    Pwm4UpdateDC(initDCVal);
    
    return STAT_SUCCESS;
}

STATUS_T Pwm4Enable()
{
    PWM4OUT_TRIS = 0;
    CCP4CONbits.CCP4EN = 1;
//    Tmr4Enable();
    if(Pwm4TmrNum == 2){
        Tmr2Enable();
    } else if(Pwm4TmrNum == 4){
        Tmr4Enable();
    } else if(Pwm4TmrNum == 6){
        Tmr6Enable();
    } 
    return STAT_SUCCESS;
}

STATUS_T Pwm4Disable()
{
    PWM4OUT_TRIS = 1;
    CCP4CONbits.CCP4EN = 0;
//    Tmr4Disable();
    if(Pwm4TmrNum == 2){
        Tmr2Disable();
    } else if(Pwm4TmrNum == 4){
        Tmr4Disable();
    } else if(Pwm4TmrNum == 6){
        Tmr6Disable();
    } 
    return STAT_SUCCESS;
}

STATUS_T Pwm4UpdateDC(int16_t newDCPct)
{
    if(newDCPct < 0)
        newDCPct = 0;
    if(newDCPct > PWMMAXPCT)
        newDCPct = PWMMAXPCT;
    
    uint32_t useVal = Pwm4DCMaxVal;
    useVal *= newDCPct;  //this is a 10bit number * a 16bit number so result will be a 26bit number, the newDCVal is a percentage * 100 or 10000 = 100.00%
    useVal /= PWMMAXPCT;                            //must divide by 10000 to apply shift correctly, this will preserve as much precision as possible
    Pwm4DCPct = newDCPct;
    
    if(useVal > Pwm4DCMaxVal){
        useVal = Pwm4DCMaxVal;
        Pwm4DCPct = PWMMAXPCT;
    }
    
    Pwm4DCVal = useVal;
    CCPR4 = Pwm4DCVal;
    
    return STAT_SUCCESS;
}
#endif 

#ifdef __USE_PWM5__
STATUS_T Pwm5Setup(uint8_t timerNum, uint16_t timerFreq, uint16_t initDCVal)
{
    PWM5OUT_PPS = PWM5PPS_VAL;
    Pwm5TmrNum = timerNum;
    
    Pwm5Disable();
    
    Tmr4Setup(timerFreq,false);
    
    if(Pwm5TmrNum == 2){
        Tmr2Setup(timerFreq,false);
        Pwm5DCMaxVal = (T2PR+1)<<2;
    } else if(Pwm5TmrNum == 4){
        Tmr4Setup(timerFreq,false);
        Pwm5DCMaxVal = (T4PR+1)<<2;
    } else if(Pwm5TmrNum == 6){
        Tmr6Setup(timerFreq,false);
        Pwm5DCMaxVal = (T6PR+1)<<2;
    } 
    if(Pwm5DCMaxVal >= 1024)
        Pwm5DCMaxVal = 1023;
    
    CCP5CONbits.CCP5MODE = 0b1111;  //hardcode PWM mode
    CCP5CONbits.CCP5FMT = 0;        //right align the register use
    
    CCPTMRS1bits.C5TSEL = 0b01;     //select Timer2 for clock source
    
    Pwm5UpdateDC(initDCVal);
    
    return STAT_SUCCESS;
}

STATUS_T Pwm5Enable()
{
    PWM5OUT_TRIS = 0;
    CCP5CONbits.CCP5EN = 1;
//    Tmr4Enable();
    if(Pwm5TmrNum == 2){
        Tmr2Enable();
    } else if(Pwm5TmrNum == 4){
        Tmr4Enable();
    } else if(Pwm5TmrNum == 6){
        Tmr6Enable();
    } 
    return STAT_SUCCESS;
}

STATUS_T Pwm5Disable()
{
    PWM5OUT_TRIS = 1;
    CCP5CONbits.CCP5EN = 0;
//    Tmr4Disable();
    if(Pwm5TmrNum == 2){
        Tmr2Disable();
    } else if(Pwm5TmrNum == 4){
        Tmr4Disable();
    } else if(Pwm5TmrNum == 6){
        Tmr6Disable();
    } 
    return STAT_SUCCESS;
}

STATUS_T Pwm5UpdateDC(int16_t newDCPct)
{
    if(newDCPct < 0)
        newDCPct = 0;
    if(newDCPct > PWMMAXPCT)
        newDCPct = PWMMAXPCT;
    
    uint32_t useVal = Pwm5DCMaxVal;
    useVal *= newDCPct;  //this is a 10bit number * a 16bit number so result will be a 26bit number, the newDCVal is a percentage * 100 or 10000 = 100.00%
    useVal /= PWMMAXPCT;                            //must divide by 10000 to apply shift correctly, this will preserve as much precision as possible
    Pwm5DCPct = newDCPct;
    
    if(useVal > Pwm5DCMaxVal){
        useVal = Pwm5DCMaxVal;
        Pwm5DCPct = PWMMAXPCT;
    }
    
    Pwm5DCVal = useVal;
    CCPR5 = Pwm5DCVal;
    
    return STAT_SUCCESS;
}
#endif 

#ifdef __USE_PWM6__
STATUS_T Pwm6Setup(uint8_t timerNum, uint16_t timerFreq, uint16_t initDCVal)
{
    PWM6OUT_PPS = PWM6PPS_VAL;
    Pwm6TmrNum = timerNum;
    
    Pwm6Disable();
    
    Tmr6Setup(timerFreq,false);
    
    if(Pwm6TmrNum == 2){
        Tmr2Setup(timerFreq,false);
        Pwm6DCMaxVal = (T2PR+1)<<2;
    } else if(Pwm6TmrNum == 4){
        Tmr4Setup(timerFreq,false);
        Pwm6DCMaxVal = (T4PR+1)<<2;
    } else if(Pwm6TmrNum == 6){
        Tmr6Setup(timerFreq,false);
        Pwm6DCMaxVal = (T6PR+1)<<2;
    } 
    if(Pwm6DCMaxVal >= 1024)
        Pwm6DCMaxVal = 1023;
    
    PWM6CONbits.PWM6POL = 0;        //active state is high
    
    CCPTMRS1bits.P6TSEL = 0b10;     //select Timer4 for clock source (shared with system clock)
    
    Pwm6UpdateDC(initDCVal);
    
    return STAT_SUCCESS;
}

STATUS_T Pwm6Enable()
{
    PWM6OUT_TRIS = 0;
    PWM6CONbits.EN = 1;
//    Tmr6Enable();
    if(Pwm6TmrNum == 2){
        Tmr2Enable();
    } else if(Pwm6TmrNum == 4){
        Tmr4Enable();
    } else if(Pwm6TmrNum == 6){
        Tmr6Enable();
    } 
    return STAT_SUCCESS;
}

STATUS_T Pwm6Disable()
{
    PWM6OUT_TRIS = 1;
    PWM6CONbits.EN = 0;
//    Tmr6Disable();
    if(Pwm6TmrNum == 2){
        Tmr2Disable();
    } else if(Pwm6TmrNum == 4){
        Tmr4Disable();
    } else if(Pwm6TmrNum == 6){
        Tmr6Disable();
    } 
    return STAT_SUCCESS;
}

STATUS_T Pwm6UpdateDC(int16_t newDCPct)
{
    if(newDCPct < 0)
        newDCPct = 0;
    if(newDCPct > PWMMAXPCT)
        newDCPct = PWMMAXPCT;
    
    uint32_t useVal = Pwm6DCMaxVal;
    useVal *= newDCPct;  //this is a 10bit number * a 16bit number so result will be a 26bit number, the newDCVal is a percentage * 100 or 10000 = 100.00%
    useVal /= PWMMAXPCT;                            //must divide by 10000 to apply shift correctly, this will preserve as much precision as possible
    Pwm6DCPct = newDCPct;
    
    if(useVal > Pwm6DCMaxVal){
        useVal = Pwm6DCMaxVal;
        Pwm6DCPct = PWMMAXPCT;
    }
    
    Pwm6DCVal = useVal;
    PWM6DCH = Pwm6DCVal>>2;
    PWM6DCL = (Pwm6DCVal<<6) & 0xC0;
//    PWM6DC = Pwm6DCVal<<6;
    
    return STAT_SUCCESS;
}
#endif 

#ifdef __USE_PWM7__
STATUS_T Pwm7Setup(uint8_t timerNum, uint16_t timerFreq, uint16_t initDCVal)
{
    PWM7OUT_PPS = PWM7PPS_VAL;
    Pwm7TmrNum = timerNum;
    
    Pwm7Disable();
    
    Tmr6Setup(timerFreq,false);
    
    if(Pwm7TmrNum == 2){
        Tmr2Setup(timerFreq,false);
        Pwm7DCMaxVal = (T2PR+1)<<2;
    } else if(Pwm7TmrNum == 4){
        Tmr4Setup(timerFreq,false);
        Pwm7DCMaxVal = (T4PR+1)<<2;
    } else if(Pwm7TmrNum == 6){
        Tmr6Setup(timerFreq,false);
        Pwm7DCMaxVal = (T6PR+1)<<2;
    } 
    if(Pwm7DCMaxVal >= 1024)
        Pwm7DCMaxVal = 1023;
    
    PWM7CONbits.PWM7POL = 0;        //active state is high
    
    CCPTMRS1bits.P7TSEL = 0b10;     //select Timer4 for clock source (shared with system clock)
    
    Pwm7UpdateDC(initDCVal);
    
    return STAT_SUCCESS;
}

STATUS_T Pwm7Enable()
{
    PWM7OUT_TRIS = 0;
    PWM7CONbits.EN = 1;
//    Tmr6Enable();
    if(Pwm7TmrNum == 2){
        Tmr2Enable();
    } else if(Pwm7TmrNum == 4){
        Tmr4Enable();
    } else if(Pwm7TmrNum == 6){
        Tmr6Enable();
    } 
    return STAT_SUCCESS;
}

STATUS_T Pwm7Disable()
{
    PWM7OUT_TRIS = 1;
    PWM7CONbits.EN = 0;
//    Tmr6Disable();
    if(Pwm7TmrNum == 2){
        Tmr2Disable();
    } else if(Pwm7TmrNum == 4){
        Tmr4Disable();
    } else if(Pwm7TmrNum == 6){
        Tmr6Disable();
    } 
    return STAT_SUCCESS;
}

STATUS_T Pwm7UpdateDC(int16_t newDCPct)
{
    if(newDCPct < 0)
        newDCPct = 0;
    if(newDCPct > PWMMAXPCT)
        newDCPct = PWMMAXPCT;
    
    uint32_t useVal = Pwm7DCMaxVal;
    useVal *= newDCPct;  //this is a 10bit number * a 16bit number so result will be a 26bit number, the newDCVal is a percentage * 100 or 10000 = 100.00%
    useVal /= PWMMAXPCT;                            //must divide by 10000 to apply shift correctly, this will preserve as much precision as possible
    Pwm7DCPct = newDCPct;
    
    if(useVal > Pwm7DCMaxVal){
        useVal = Pwm7DCMaxVal;
        Pwm7DCPct = PWMMAXPCT;
    }
    
    Pwm7DCVal = useVal;
    PWM7DCH = Pwm7DCVal>>2;
    PWM7DCL = (Pwm7DCVal<<6) & 0xC0;
//    PWM7DC = Pwm7DCVal<<6;
    
    return STAT_SUCCESS;
}
#endif


//STATUS_T PwmSetup(CCPModule_t Mod, uint16_t timerFreq, uint16_t initDCPct)
//{
//    *(Mod.OUT_PPS) = Mod.PPSVal;
//    
//    PwmDisable(Mod);
//    
//    uint8_t clkSelVal = 0;
//    if(Mod.TmrNum == 2){
//        Tmr2Setup(timerFreq,false);
//        Mod.TMRPRREG = &T2PR;
////        Mod.DCMaxVal = (PR2+1)<<2;
//        clkSelVal = 0b01;
//    } else if(Mod.TmrNum == 4){
//        Tmr4Setup(timerFreq,false);
//        Mod.TMRPRREG = &T4PR;
////        Mod.DCMaxVal = (T4PR+1)<<2;
//        clkSelVal = 0b10;
//    } else if(Mod.TmrNum == 6){
//        Tmr6Setup(timerFreq,false);
//        Mod.TMRPRREG = &T6PR;
////        Mod.DCMaxVal = (T6PR+1)<<2;
//        clkSelVal = 0b11;
//    }
////    
////    if(Mod.DCMaxVal >= 1024)
////        Mod.DCMaxVal = 1023;
//    
//    *(Mod.CON) = 0x0F;  //hardcode PWM mode and right align the register use
//    
//    *(Mod.CLKSEL) = clkSelVal << Mod.ClkShft;  //select TimerX for clock source
//    
//    PwmUpdateDC(Mod,initDCPct);
//    
//    return STAT_SUCCESS;
//}
//
//STATUS_T PwmEnable(CCPModule_t Mod)
//{
//    *(Mod.OUT_TRIS) &= ~Mod.OutBit;
//    *(Mod.CON) |= 0x80;
//    if(Mod.TmrNum == 2){
//        Tmr2Enable();
//    } else if(Mod.TmrNum == 4){
//        Tmr4Enable();
//    } else if(Mod.TmrNum == 6){
//        Tmr6Enable();
//    } 
//    return STAT_SUCCESS;
//}
//
//STATUS_T PwmDisable(CCPModule_t Mod)
//{
//    *(Mod.OUT_TRIS) |= Mod.OutBit;
//    *(Mod.CON) &= 0x7F;
//    if(Mod.TmrNum == 2){
//        Tmr2Disable();
//    } else if(Mod.TmrNum == 4){
//        Tmr4Disable();
//    } else if(Mod.TmrNum == 6){
//        Tmr6Disable();
//    } 
//    return STAT_SUCCESS;
//}
//
//STATUS_T PwmUpdateDC(CCPModule_t Mod, int16_t newDCPct)
//{
////    char msg_buff[64];
//    
//    if(newDCPct < 0)
//        newDCPct = 0;
//    if(newDCPct > PWMMAXPCT)
//        newDCPct = PWMMAXPCT;
//    
////    Mod.DCMaxVal = (T2PR+1)<<2;
////    uint32_t useVal = Mod.DCMaxVal;
//    uint32_t useVal = (*Mod.TMRPRREG+1)<<2;
//    if(useVal >= 1024)
//        useVal = 1023;
//    
////    sprintf(msg_buff,"DCVal: 0x%08X, DCMax: 0x%04X",useVal,(*Mod.TMRPRREG+1)<<2);
////    load_tx_msg_str_crlf(msg_buff);
//    
//    useVal = useVal * newDCPct;  //this is a 10bit number * a 16bit number so result will be a 26bit number, the newDCVal is a percentage * 100 or 10000 = 100.00%
//    useVal /= PWMMAXPCT;                            //must divide by 10000 to apply shift correctly, this will preserve as much precision as possible
//    Mod.DCPct = newDCPct;
//    
//    if(useVal > (*Mod.TMRPRREG+1)<<2){
//        useVal = (*Mod.TMRPRREG+1)<<2;
//        Mod.DCPct = PWMMAXPCT;
//    }
//    
////    sprintf(msg_buff,"New Pwm2 DCVal: 0x%08X",useVal);
////    load_tx_msg_str_crlf(msg_buff);
//    
//    Mod.DCVal = useVal;
//    *(Mod.REGH) = Mod.DCVal >> 2;
//    *(Mod.REGL) = Mod.DCVal & 0xFF;
//    
//    return STAT_SUCCESS;
//}