#include "System.h"

void SetupClk(void)
{
    OSCCON1 = 0x60; //select HFIntOsc with Divider of 1
    if(_XTAL_FREQ == 32000000)
        OSCFRQ = 0x06;  //select 32MHz as HFIntOsc frequency
    else if(_XTAL_FREQ == 64000000)
        OSCFRQ = 0x08;
    else
        OSCFRQ = 0x05;  //select 16MHz by default
    
    while(! OSCSTATbits.HFOR && !OSCSTATbits.PLLR) continue;   //wait for frequency stability and lock
}


STATUS_T SysInit(void)
{
    //Default all pins to digital
    make_all_digital();
    
    //Make Programming Pins Inputs
    PGD_TRIS = 1;
    PGC_TRIS = 1;
    
    //Set GPIO RB5 to output with initial value (Pin 38)
//    GPIO_RB5_OUT = 0;
//    GPIO_RB5_TRIS = 0;    
//    GPIO_RB4_OUT = 0;
//    GPIO_RB4_TRIS = 0;    
    
//    //Setup MAX232 Reset Line
//    UART1_RST = 1;
//    UART1_RST_TRIS = 0;
    
    sys_time = 0;
    sys_stat = 0;
    halfSecondTrigger = false;
    twoSecondTrigger = false;
        
    if(Tmr4Setup(1000,true) == STAT_SUCCESS){
        sys_stat |= 1;
        TMR4IP = 1;
        Tmr4Enable();
    }
    
    if(setupDisp(1010) == STAT_SUCCESS){
        sys_stat |= 2;
    }
    
    if(UART1Setup(115200,true,true) == STAT_SUCCESS){
        sys_stat |= 4;
    }
    
    if(IOExpSetup(&ioexp1,0xE8,0x0000,0x0000,0x0000) == STAT_SUCCESS){
        sys_stat |= 8;
    }
    
    if(setupStepper0() == STAT_SUCCESS){
        sys_stat |= 16;
    }
    if(setupStepper1() == STAT_SUCCESS){
        sys_stat |= 32;
    }
    if(setupStepper2() == STAT_SUCCESS){
        sys_stat |= 64;
    }
        
    INTCON0bits.IPEN = 1;
    GIE = 1;
    
    return STAT_SUCCESS;
}

STATUS_T make_all_digital(void)
{
    ANSELA = 0;
    ANSELB = 0;
    ANSELC = 0;
    ANSELD = 0;
    ANSELE = 0;
    
    return STAT_SUCCESS;
}

void interpretRX(void)
{
    char respBuff[256];
    bool valid = false;
    bool gotChar = false;
    
    char loc_msg_buff[UART1_RX_BUFF_SIZE];
    for(int i = 0; i < UART1_RX_BUFF_SIZE; i++){
        if(i < uart1_rx_buff_load_cnt)
            loc_msg_buff[i] = uart1_rx_buff_use[i];
        else 
            loc_msg_buff[i] = 0x00;
    }
    
    char *p;
    char *fieldStr[2];
    int i;
    int32_t inputVal = 0;
    for(i = 0, p = strtok(loc_msg_buff,","); p != NULL, i < 2; p = strtok(NULL,","), i++){
        fieldStr[i] = p;
    }
    if(i == 2){
        char cmd[16];
        for(int j = 0; j < 16; j++){
            if(j < strlen(fieldStr[0]))
                cmd[j] = tolower(fieldStr[0][j]);
            else
                cmd[j] = 0;
        }
        inputVal = atol(fieldStr[1]);
        if(strcmp(cmd,"x") == 0){
            gotChar = true;
            pendingSteps0 += inputVal;
            valid = true;
            sprintf(respBuff,"Applying step to X: %ld",inputVal);
            uart1_tx_str_crlf(respBuff);
        } else if(strcmp(cmd,"y") == 0){
            gotChar = true;
            pendingSteps1 += inputVal;
            valid = true;
            sprintf(respBuff,"Applying step to Y: %ld",inputVal);
            uart1_tx_str_crlf(respBuff);
        } else if(strcmp(cmd,"z") == 0){
            gotChar = true;
            pendingSteps2 += inputVal;
            valid = true;
            sprintf(respBuff,"Applying step to Z: %ld",inputVal);
            uart1_tx_str_crlf(respBuff);
        } else if(strcmp(cmd,"r") == 0){
            gotChar = true;
            valid = true;
            sprintf(respBuff,"Applying reload of IOEXP Params");
            uart1_tx_str_crlf(respBuff);
            IOExpUpdateAll(&ioexp1);
        }
        //for debugging command interpretation:
//        sprintf(respBuff,"Rec'd CMD: '%s', (cmd: '%s'), Val: %ld",fieldStr[0],cmd,inputVal);
//        uart1_tx_str_crlf(respBuff);
    }
    if(!valid){
        sprintf(respBuff,"Invalid command, use 'X,Num', 'Y,Num' or 'Z,Num', Char: %d, Num: %ld\n\r",gotChar,inputVal);
        uart1_tx_str_crlf(respBuff);        
    }
}