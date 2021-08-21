#include "Timers.h"

#ifdef __USE_TIMER1__
STATUS_T Tmr1Setup(uint32_t tmr_freq, bool use_int, uint8_t int_prio)
{
    Tmr1UsingInt = use_int;
    Tmr1Disable();
    T1CONbits.SIDL = 0; //enable in idle mode
    T1CONbits.TGATE = 0;    //disable gat acc
    T1CONbits.TCKPS = 0b000;
    T1CONbits.TWDIS = 0;  //legacy mode
    T1CONbits.TCS = 0;  //internal peripheral clock is clock source

    //Configure Pre/Post Scalars and the loading value for T2PR to achieve the indicated period    
    uint8_t prescalarVal = 0;
    uint32_t regVal = _XTAL_FREQ;       //Assume Prescalar of 1:1 on Fosc at start    (38000000)
    regVal = regVal / tmr_freq;         //Divide by the input frequency desired         (38000000/1000 = 38000)
    if(regVal > 65535){                 //test the register value to see if this will fit
        prescalarVal = 1;
        regVal = regVal >> 3;           //use 1:8 prescalar
        if(regVal > 65535){             //test the register value to see if this will fit
            prescalarVal = 2;
            regVal = regVal >> 3;       //use 1:64 prescalar
            if(regVal > 65535){         //test the register value to see if this will fit
                prescalarVal = 3;       //Valid prescalars for this timer are [0:3] for 1:1, 1:8, 1:64 and 1:256 respectively
                regVal = regVal >> 2;   //use 1:256 prescalar (max prescalar value)
                if(regVal > 65535){     //one more test to see if this will work
                    return STAT_FAIL;   //can't set period with just prescalar, TODO: Incorportate the Post Scalar setting
                }
            }
        }
    }
    PR1 = regVal-1;                //Assign resulting Period Register Value
    prescalarVal = prescalarVal << 4;   //Shift the prescalar to the appropriate bit positions
    T1CON |= prescalarVal;          //Set the prescalar in the Timer2 Control Register
    
    if(Tmr1UsingInt){
        IPC1bits.T1IP = int_prio;
//        IFS0bits.T1IF = 0;
//        IEC0bits.T1IE = 1;
    }
    
    return STAT_SUCCESS;
}

void Tmr1Enable(void)
{
    if(Tmr1UsingInt){
        IFS0bits.T1IF = 0;
        IEC0bits.T1IE = 1;
    }
    T1CONbits.ON = 1;
}

void Tmr1Disable(void)
{
    T1CONbits.ON = 0;
    if(Tmr1UsingInt){
        IFS0bits.T1IF = 0;
        IEC0bits.T1IE = 0;
    }
}
#endif

#ifdef __USE_TIMER2__
STATUS_T Tmr2Setup(uint32_t tmr_freq, bool use_int, uint8_t int_prio)
{
    Tmr2UsingInt = use_int;
    Tmr2Disable();
    T2CONbits.SIDL = 0; //enable in idle mode
    T2CONbits.TGATE = 0;    //disable gat acc
    T2CONbits.TCKPS = 0b000;
    T2CONbits.T32 = 0;  //separate 16-bit timers
    T2CONbits.TCS = 0;  //internal peripheral clock is clock source

    //Configure Pre/Post Scalars and the loading value for T2PR to achieve the indicated period    
    uint8_t prescalarVal = 0;
    uint32_t regVal = _XTAL_FREQ; //Assume Prescalar of 1:1 on Fosc at start    (38000000)
    regVal = regVal / tmr_freq;     //Divide by the input frequency desired         (38000000/1000 = 38000)
    while(regVal > 65536){            //Loop until the result is below 65536 to fit in the Period Register T2PR
        regVal = regVal >> 1;       //Divide regVal by 2
        prescalarVal++;             //Increment the prescalar factor
        if(prescalarVal > 7){       //The only valid prescalars are [0:7], they are powers of 2 from [1:128]
            return STAT_FAIL;   //can't set period with just prescalar, TODO: Incorportate the Post Scalar setting
        }
    }
    PR2 = regVal-1;                //Assign resulting Period Register Value
    prescalarVal = prescalarVal << 4;   //Shift the prescalar to the appropriate bit positions
    T2CON |= prescalarVal;          //Set the prescalar in the Timer2 Control Register
    
    if(Tmr2UsingInt){
        IPC2bits.T2IP = int_prio;
//        IFS0bits.T2IF = 0;
//        IEC0bits.T2IE = 1;
    }
    
    return STAT_SUCCESS;
}

void Tmr2Enable(void)
{
    if(Tmr2UsingInt){
        IFS0bits.T2IF = 0;
        IEC0bits.T2IE = 1;
    }
    T2CONbits.ON = 1;
}

void Tmr2Disable(void)
{
    T2CONbits.ON = 0;
    if(Tmr2UsingInt){
        IFS0bits.T2IF = 0;
        IEC0bits.T2IE = 0;
    }
}

//Example ISR for Timer2
//void __ISR(_TIMER_2_VECTOR,IPL7AUTO) timer2ISR(void)
//{
//    IFS0CLR = _IFS0_T2IF_MASK;
//    
//    GPIO_RB15_OUT ^= 1;
//}
#endif

#ifdef __USE_TIMER3__
STATUS_T Tmr3Setup(uint32_t tmr_freq, bool use_int, uint8_t int_prio)
{    
    Tmr3UsingInt = use_int;
    Tmr3Disable();
    T3CONbits.SIDL = 0; //enable in idle mode
    T3CONbits.TGATE = 0;    //disable gat acc
    T3CONbits.TCKPS = 0b000;
//    T3CONbits.T32 = 0;  //separate 16-bit timers (NOT IMPLEMENTED IN ODD NUMBER TIMERS)
    T3CONbits.TCS = 0;  //internal peripheral clock is clock source

    //Configure Pre/Post Scalars and the loading value for T2PR to achieve the indicated period    
    uint8_t prescalarVal = 0;
    uint32_t regVal = _XTAL_FREQ; //Assume Prescalar of 1:1 on Fosc at start    (38000000)
    regVal = regVal / tmr_freq;     //Divide by the input frequency desired         (38000000/1000 = 38000)
    while(regVal > 65536){            //Loop until the result is below 65536 to fit in the Period Register T2PR
        regVal = regVal >> 1;       //Divide regVal by 2
        prescalarVal++;             //Increment the prescalar factor
        if(prescalarVal > 7){       //The only valid prescalars are [0:7], they are powers of 2 from [1:128]
            return STAT_FAIL;   //can't set period with just prescalar, TODO: Incorportate the Post Scalar setting
        }
    }
    PR3 = regVal-1;                //Assign resulting Period Register Value
    prescalarVal = prescalarVal << 4;   //Shift the prescalar to the appropriate bit positions
    T3CON |= prescalarVal;          //Set the prescalar in the Timer2 Control Register

    if(Tmr3UsingInt){
        IPC3bits.T3IP = int_prio;
//        IFS0bits.T3IF = 0;
//        IEC0bits.T3IE = 1;
    }
    
    return STAT_SUCCESS;
}

void Tmr3Enable(void)
{
    if(Tmr3UsingInt){
        IFS0bits.T3IF = 0;
        IEC0bits.T3IE = 1;
    }
    T3CONbits.ON = 1;
}

void Tmr3Disable(void)
{
    T3CONbits.ON = 0;
    if(Tmr3UsingInt){
        IFS0bits.T3IF = 0;
        IEC0bits.T3IE = 0;
    }
}
#endif

#ifdef __USE_TIMER4__
STATUS_T Tmr4Setup(uint32_t tmr_freq, bool use_int, uint8_t int_prio)
{
    Tmr4UsingInt = use_int;
    Tmr4Disable();
    T4CONbits.SIDL = 0; //enable in idle mode
    T4CONbits.TGATE = 0;    //disable gat acc
    T4CONbits.TCKPS = 0b000;
    T4CONbits.T32 = 0;  //separate 16-bit timers
    T4CONbits.TCS = 0;  //internal peripheral clock is clock source

    //Configure Pre/Post Scalars and the loading value for PRx to achieve the indicated period    
    uint8_t prescalarVal = 0;
    uint32_t regVal = _XTAL_FREQ; //Assume Prescalar of 1:1 on Fosc at start    (38000000)
    regVal = regVal / tmr_freq;     //Divide by the input frequency desired         (38000000/1000 = 38000)
    while(regVal > 65536){            //Loop until the result is below 65536 to fit in the Period Register T2PR
        regVal = regVal >> 1;       //Divide regVal by 2
        prescalarVal++;             //Increment the prescalar factor
        if(prescalarVal > 7){       //The only valid prescalars are [0:7], they are powers of 2 from [1:128]
            return STAT_FAIL;   //can't set period with just prescalar, TODO: Incorportate the Post Scalar setting
        }
    }
    PR4 = regVal-1;                //Assign resulting Period Register Value
    prescalarVal = prescalarVal << 4;   //Shift the prescalar to the appropriate bit positions
    T4CON |= prescalarVal;          //Set the prescalar in the Timer2 Control Register
    
    if(Tmr4UsingInt){
        IPC4bits.T4IP = int_prio;
//        IFS0bits.T4IF = 0;
//        IEC0bits.T4IE = 1;
    }
    
    return STAT_SUCCESS;
}

void Tmr4Enable(void)
{
    if(Tmr4UsingInt){
        IFS0bits.T4IF = 0;
        IEC0bits.T4IE = 1;
    }
    T4CONbits.ON = 1;
}

void Tmr4Disable(void)
{
    T4CONbits.ON = 0;
    if(Tmr4UsingInt){
        IFS0bits.T4IF = 0;
        IEC0bits.T4IE = 0;
    }
}
#endif

#ifdef __USE_TIMER5__
STATUS_T Tmr5Setup(uint32_t tmr_freq, bool use_int, uint8_t int_prio)
{
    Tmr5UsingInt = use_int;
    Tmr5Disable();
    T5CONbits.SIDL = 0; //enable in idle mode
    T5CONbits.TGATE = 0;    //disable gat acc
    T5CONbits.TCKPS = 0b000;
//    T5CONbits.T32 = 0;  //separate 16-bit timers
    T5CONbits.TCS = 0;  //internal peripheral clock is clock source

    //Configure Pre/Post Scalars and the loading value for T2PR to achieve the indicated period    
    uint8_t prescalarVal = 0;
    uint32_t regVal = _XTAL_FREQ; //Assume Prescalar of 1:1 on Fosc at start    (38000000)
    regVal = regVal / tmr_freq;     //Divide by the input frequency desired         (38000000/1000 = 38000)
    while(regVal > 65536){            //Loop until the result is below 65536 to fit in the Period Register T2PR
        regVal = regVal >> 1;       //Divide regVal by 2
        prescalarVal++;             //Increment the prescalar factor
        if(prescalarVal > 7){       //The only valid prescalars are [0:7], they are powers of 2 from [1:128]
            return STAT_FAIL;   //can't set period with just prescalar, TODO: Incorportate the Post Scalar setting
        }
    }
    PR5 = regVal-1;                //Assign resulting Period Register Value
    prescalarVal = prescalarVal << 4;   //Shift the prescalar to the appropriate bit positions
    T5CON |= prescalarVal;          //Set the prescalar in the Timer2 Control Register
    
    if(Tmr5UsingInt){
        IPC5bits.T5IP = int_prio;
//        IFS0bits.T5IF = 0;
//        IEC0bits.T5IE = 1;
    }
    
    return STAT_SUCCESS;
}

void Tmr5Enable(void)
{
    if(Tmr5UsingInt){
        IFS0bits.T5IF = 0;
        IEC0bits.T5IE = 1;
    }
    T5CONbits.ON = 1;
}

void Tmr5Disable(void)
{
    T5CONbits.ON = 0;
    if(Tmr5UsingInt){
        IFS0bits.T5IF = 0;
        IEC0bits.T5IE = 0;
    }
}
#endif