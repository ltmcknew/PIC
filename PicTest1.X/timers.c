#include "timers.h"


#ifdef __USE_TIMER0__
STATUS_T Tmr0Setup(uint16_t tmr_freq, bool use_int)
{
    TMR0Val = 0;
    
    Tmr0Disable();
    T0CON1 = 0x40;    //Fosc/4 is clock source (8MHz) with Counter Sync'd to system clock
    T0CON0bits.T016BIT = 1;     //Enable 16bit mode by default
    
    //Configure Pre/Post Scalars and the loading value for T2PR to achieve the indicated period    
    uint8_t prescalarVal = 0;
    uint32_t regVal = _XTAL_FREQ/4; //Assume Prescalar of 1:1 on Fosc/4 at start    (32000000/4 = 8000000)
    regVal = regVal / tmr_freq;     //Divide by the input frequency desired         (8000000/1000 = 8000)
    while(regVal > 65535){            //Loop until the result is below 256 to fit in the Period Register T2PR
        regVal = regVal >> 1;       //Divide regVal by 2
        prescalarVal++;             //Increment the prescalar factor
        if(prescalarVal > 15){       //The only valid prescalars are [0:7], they are powers of 2 from [1:128]
            return STAT_FAIL;   //can't set period with just prescalar, TODO: Incorportate the Post Scalar setting
        }
    }
    TMR0Val = 0xFFFF - regVal;                //Assign resulting Period Register Value
    TMR0H = TMR0Val>>8;
    TMR0L = TMR0Val & 0xFF;
//    prescalarVal = prescalarVal << 4;   //Shift the prescalar to the appropriate bit positions
    T0CON1 |= prescalarVal;          //Set the prescalar in the Timer2 Control Register
    
    if(use_int)
        PIE0bits.TMR0IE = 1;
        
    return STAT_SUCCESS;
}

void Tmr0Enable(void)
{
    T0CON0bits.T0EN = 1;
}

void Tmr0Disable(void)
{
    T0CON0bits.T0EN = 0;
}
#endif

//The following enable the Timer1/3/5 type modules
#ifdef __USE_TIMER1__
STATUS_T Tmr1Setup(uint16_t tmr_freq, bool use_int)
{
    TMR1Val = 0;
    
    Tmr1Disable();
    T1CON = 0x02;   //All 16 bits of TMR1 can be read 
    T1GCON = 0x00;  //No gate functionality enabled
    T1CLK = 0x01;   //Select Fosc/4 as clock source
    
    //Configure Pre/Post Scalars and the loading value for TMR1 to achieve the indicated period    
    uint8_t prescalarVal = 0;
    uint32_t regVal = _XTAL_FREQ/4; //Assume Prescalar of 1:1 on Fosc/4 at start    (32000000/4 = 8000000)
    regVal = regVal / tmr_freq;     //Divide by the input frequency desired         (8000000/1000 = 8000)
    while(regVal > 65535){            //Loop until the result is below 65536 to fit in the Period Register TMR1
        regVal = regVal >> 1;       //Divide regVal by 2
        prescalarVal++;             //Increment the prescalar factor
        if(prescalarVal > 3){       //The only valid prescalars are [0:3], they are powers of 2 from [1:8]
            return STAT_FAIL;   //can't set period with just prescalar, TODO: Incorportate the Post Scalar setting
        }
    }
    TMR1Val = 0xFFFF - regVal;                //Assign resulting Period Register Value
    TMR1H = TMR1Val>>8;
    TMR1L = TMR1Val & 0xFF;
    prescalarVal = prescalarVal << 4;   //Shift the prescalar to the appropriate bit positions
    T1CON |= prescalarVal;          //Set the prescalar in the Timer2 Control Register
    
    if(use_int){
        TMR1IF = 0;
        TMR1IE = 1;
    }
    
    return STAT_SUCCESS;
}

void Tmr1Enable(void)
{
    TMR1ON = 1;
}

void Tmr1Disable(void)
{
    TMR1ON = 0;
}
#endif

#ifdef __USE_TIMER3__
STATUS_T Tmr3Setup(uint16_t tmr_freq, bool use_int)
{
    TMR3Val = 0;
    
    Tmr3Disable();
    T3CON = 0x02;   //All 16 bits of TMR1 can be read 
    T3GCON = 0x00;  //No gate functionality enabled
    T3CLK = 0x01;   //Select Fosc/4 as clock source
    
    //Configure Pre/Post Scalars and the loading value for TMR1 to achieve the indicated period    
    uint8_t prescalarVal = 0;
    uint32_t regVal = _XTAL_FREQ/4; //Assume Prescalar of 1:1 on Fosc/4 at start    (32000000/4 = 8000000)
    regVal = regVal / tmr_freq;     //Divide by the input frequency desired         (8000000/1000 = 8000)
    while(regVal > 65535){            //Loop until the result is below 65536 to fit in the Period Register TMR1
        regVal = regVal >> 1;       //Divide regVal by 2
        prescalarVal++;             //Increment the prescalar factor
        if(prescalarVal > 3){       //The only valid prescalars are [0:3], they are powers of 2 from [1:8]
            return STAT_FAIL;   //can't set period with just prescalar, TODO: Incorportate the Post Scalar setting
        }
    }
    TMR3Val = 0xFFFF - regVal;                //Assign resulting Period Register Value
    TMR3H = TMR3Val>>8;
    TMR3L = TMR3Val & 0xFF;
    prescalarVal = prescalarVal << 4;   //Shift the prescalar to the appropriate bit positions
    T3CON |= prescalarVal;          //Set the prescalar in the Timer2 Control Register
    
    if(use_int){
        TMR3IF = 0;
        TMR3IE = 1;
    }
    
    return STAT_SUCCESS;
}

void Tmr3Enable(void)
{
    TMR3ON = 1;
}

void Tmr3Disable(void)
{
    TMR3ON = 0;
}
#endif

#ifdef __USE_TIMER5__
STATUS_T Tmr5Setup(uint16_t tmr_freq, bool use_int)
{
    TMR5Val = 0;
    
    Tmr1Disable();
    T5CON = 0x02;   //All 16 bits of TMR1 can be read 
    T5GCON = 0x00;  //No gate functionality enabled
    T5CLK = 0x01;   //Select Fosc/4 as clock source
    
    //Configure Pre/Post Scalars and the loading value for TMR1 to achieve the indicated period    
    uint8_t prescalarVal = 0;
    uint32_t regVal = _XTAL_FREQ/4; //Assume Prescalar of 1:1 on Fosc/4 at start    (32000000/4 = 8000000)
    regVal = regVal / tmr_freq;     //Divide by the input frequency desired         (8000000/1000 = 8000)
    while(regVal > 65535){            //Loop until the result is below 65536 to fit in the Period Register TMR1
        regVal = regVal >> 1;       //Divide regVal by 2
        prescalarVal++;             //Increment the prescalar factor
        if(prescalarVal > 3){       //The only valid prescalars are [0:3], they are powers of 2 from [1:8]
            return STAT_FAIL;   //can't set period with just prescalar, TODO: Incorportate the Post Scalar setting
        }
    }
    TMR5Val = 0xFFFF - regVal;                //Assign resulting Period Register Value
    TMR5H = TMR5Val>>8;
    TMR5L = TMR5Val & 0xFF;
    prescalarVal = prescalarVal << 4;   //Shift the prescalar to the appropriate bit positions
    T5CON |= prescalarVal;          //Set the prescalar in the Timer2 Control Register
    
    if(use_int){
        TMR5IF = 0;
        TMR5IE = 1;
    }
    
    return STAT_SUCCESS;
}

void Tmr5Enable(void)
{
    TMR5ON = 1;
}

void Tmr5Disable(void)
{
    TMR5ON = 0;
}
#endif



//The following enable the Timer2/4/6 type modules
#ifdef __USE_TIMER2__
STATUS_T Tmr2Setup(uint16_t tmr_freq, bool use_int)
{
    Tmr2Disable();
    T2CLKCON = 0x01;    //Fosc/4 is clock source (8MHz)
    T2HLT = 0x00;       //No synchronizations are used, Clock Polarity is Rising Edge of input and Mode is Software Free Running
    
    //Configure Pre/Post Scalars and the loading value for T2PR to achieve the indicated period    
    uint8_t prescalarVal = 0;
    uint32_t regVal = _XTAL_FREQ/4; //Assume Prescalar of 1:1 on Fosc/4 at start    (32000000/4 = 8000000)
    regVal = regVal / tmr_freq;     //Divide by the input frequency desired         (8000000/1000 = 8000)
    while(regVal > 255){            //Loop until the result is below 256 to fit in the Period Register T2PR
        regVal = regVal >> 1;       //Divide regVal by 2
        prescalarVal++;             //Increment the prescalar factor
        if(prescalarVal > 7){       //The only valid prescalars are [0:7], they are powers of 2 from [1:128]
            return STAT_FAIL;   //can't set period with just prescalar, TODO: Incorportate the Post Scalar setting
        }
    }
    T2PR = regVal-1;                //Assign resulting Period Register Value
    prescalarVal = prescalarVal << 4;   //Shift the prescalar to the appropriate bit positions
    T2CON |= prescalarVal;          //Set the prescalar in the Timer2 Control Register
    
    if(use_int){
        TMR2IF = 0;
        PIE4bits.TMR2IE = 1;
    }
        
    return STAT_SUCCESS;
}

void Tmr2Enable(void)
{
    T2CONbits.ON = 1;
}

void Tmr2Disable(void)
{
    T2CONbits.ON = 0;
}
#endif

#ifdef __USE_TIMER4__
STATUS_T Tmr4Setup(uint16_t tmr_freq, bool use_int)
{
    Tmr4Disable();
    T4CLKCON = 0x01;    //Fosc/4 is clock source (8MHz)
    T4HLT = 0x00;       //No synchronizations are used, Clock Polarity is Rising Edge of input and Mode is Software Free Running
    
    //Configure Pre/Post Scalars and the loading value for T2PR to achieve the indicated period    
    uint8_t prescalarVal = 0;
    uint32_t regVal = _XTAL_FREQ/4; //Assume Prescalar of 1:1 on Fosc/4 at start    (32000000/4 = 8000000)
    regVal = regVal / tmr_freq;     //Divide by the input frequency desired         (8000000/1000 = 8000)
    while(regVal > 255){            //Loop until the result is below 256 to fit in the Period Register T2PR
        regVal = regVal >> 1;       //Divide regVal by 2
        prescalarVal++;             //Increment the prescalar factor
        if(prescalarVal > 7){       //The only valid prescalars are [0:7], they are powers of 2 from [1:128]
            return STAT_FAIL;   //can't set period with just prescalar, TODO: Incorportate the Post Scalar setting
        }
    }
    T4PR = regVal-1;                //Assign resulting Period Register Value
    prescalarVal = prescalarVal << 4;   //Shift the prescalar to the appropriate bit positions
    T4CON |= prescalarVal;          //Set the prescalar in the Timer2 Control Register
    
    if(use_int){
        TMR4IF = 0;
        PIE4bits.TMR4IE = 1;
    }
    
    return STAT_SUCCESS;
}

void Tmr4Enable(void)
{
    T4CONbits.ON = 1;
}

void Tmr4Disable(void)
{
    T4CONbits.ON = 0;
}
#endif

#ifdef __USE_TIMER6__
STATUS_T Tmr6Setup(uint16_t tmr_freq, bool use_int)
{
    Tmr6Disable();
    T6CLKCON = 0x01;    //Fosc/4 is clock source (8MHz)
    T6HLT = 0x00;       //No synchronizations are used, Clock Polarity is Rising Edge of input and Mode is Software Free Running
    
    //Configure Pre/Post Scalars and the loading value for T2PR to achieve the indicated period    
    uint8_t prescalarVal = 0;
    uint32_t regVal = _XTAL_FREQ/4; //Assume Prescalar of 1:1 on Fosc/4 at start    (32000000/4 = 8000000)
    regVal = regVal / tmr_freq;     //Divide by the input frequency desired         (8000000/1000 = 8000)
    while(regVal > 255){            //Loop until the result is below 256 to fit in the Period Register T2PR
        regVal = regVal >> 1;       //Divide regVal by 2
        prescalarVal++;             //Increment the prescalar factor
        if(prescalarVal > 7){       //The only valid prescalars are [0:7], they are powers of 2 from [1:128]
            return STAT_FAIL;   //can't set period with just prescalar, TODO: Incorportate the Post Scalar setting
        }
    }
    T6PR = regVal-1;                //Assign resulting Period Register Value
    prescalarVal = prescalarVal << 4;   //Shift the prescalar to the appropriate bit positions
    T6CON |= prescalarVal;          //Set the prescalar in the Timer2 Control Register
    
    if(use_int){
        TMR6IF = 0;
        PIE4bits.TMR6IE = 1;
    }
    
    return STAT_SUCCESS;
}

void Tmr6Enable(void)
{
    T6CONbits.ON = 1;
}

void Tmr6Disable(void)
{
    T6CONbits.ON = 0;
}
#endif

STATUS_T TmrSetup(TmrEven_T Mod, uint16_t tmr_freq, bool use_int)
{
    TmrDisable(Mod);
    
    *Mod.CLKCON = 0x01; //Fosc/4 is clock source (8MHz)
    *Mod.HLT = 0x00;    //No synchronizations are used, Clock Polarity is Rising Edge of input and Mode is Software Free Running
    
    Mod.setFreq = tmr_freq;
    Mod.intEnabled = use_int;
    
    //Configure Pre/Post Scalars and the loading value for T2PR to achieve the indicated period    
    uint8_t prescalarVal = 0;
    uint32_t regVal = _XTAL_FREQ/4; //Assume Prescalar of 1:1 on Fosc/4 at start    (32000000/4 = 8000000)
    regVal = regVal / tmr_freq;     //Divide by the input frequency desired         (8000000/1000 = 8000)
    while(regVal > 255){            //Loop until the result is below 256 to fit in the Period Register T2PR
        regVal = regVal >> 1;       //Divide regVal by 2
        prescalarVal++;             //Increment the prescalar factor
        if(prescalarVal > 7){       //The only valid prescalars are [0:7], they are powers of 2 from [1:128]
            return STAT_FAIL;   //can't set period with just prescalar, TODO: Incorportate the Post Scalar setting
        }
    }
    *Mod.PREG = regVal-1;                //Assign resulting Period Register Value
    prescalarVal = prescalarVal << 4;   //Shift the prescalar to the appropriate bit positions
    *Mod.CON |= prescalarVal;          //Set the prescalar in the Timer2 Control Register
    
    if(use_int){
        PIR4 &= ~Mod.intBitPos; //zero the IF
        PIE4 |= Mod.intBitPos;
        Mod.intEnabled = true;
    }
    
    return STAT_SUCCESS;
}

void TmrEnable(TmrEven_T Mod)
{
    *Mod.CON |= 0x80;
    Mod.isEnabled = true;
}

void TmrDisable(TmrEven_T Mod)
{
    *Mod.CON &= 0x7F;
    Mod.isEnabled = false;
}