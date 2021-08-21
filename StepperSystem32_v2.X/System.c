
// PIC32MX170F256B Configuration Bit Settings

// 'C' source line config statements

// DEVCFG3
#pragma config USERID = 0xFFFF          // Enter Hexadecimal value (Enter Hexadecimal value)
#pragma config PMDL1WAY = OFF           // Peripheral Module Disable Configuration (Allow multiple reconfigurations)
#pragma config IOL1WAY = OFF            // Peripheral Pin Select Configuration (Allow multiple reconfigurations)

// DEVCFG2
#pragma config FPLLIDIV = DIV_2         // PLL Input Divider (2x Divider)
#pragma config FPLLMUL = MUL_19         // PLL Multiplier (19x Multiplier)
#pragma config FPLLODIV = DIV_2         // System PLL Output Clock Divider (PLL Divide by 2)

// DEVCFG1
#pragma config FNOSC = FRCPLL           // Oscillator Selection Bits (Fast RC Osc with PLL)
#pragma config FSOSCEN = OFF            // Secondary Oscillator Enable (Disabled)
#pragma config IESO = OFF               // Internal/External Switch Over (Disabled)
#pragma config POSCMOD = OFF            // Primary Oscillator Configuration (Primary osc disabled)
#pragma config OSCIOFNC = OFF           // CLKO Output Signal Active on the OSCO Pin (Disabled)
#pragma config FPBDIV = DIV_1           // Peripheral Clock Divisor (Pb_Clk is Sys_Clk/1)
#pragma config FCKSM = CSDCMD           // Clock Switching and Monitor Selection (Clock Switch Disable, FSCM Disabled)
#pragma config WDTPS = PS1048576        // Watchdog Timer Postscaler (1:1048576)
#pragma config WINDIS = OFF             // Watchdog Timer Window Enable (Watchdog Timer is in Non-Window Mode)
#pragma config FWDTEN = ON              // Watchdog Timer Enable (WDT Enabled)
#pragma config FWDTWINSZ = WINSZ_25     // Watchdog Timer Window Size (Window Size is 25%)

// DEVCFG0
#pragma config JTAGEN = OFF             // JTAG Enable (JTAG Disabled)
#pragma config ICESEL = ICS_PGx1        // ICE/ICD Comm Channel Select (Communicate on PGEC1/PGED1)
#pragma config PWP = OFF                // Program Flash Write Protect (Disable)
#pragma config BWP = OFF                // Boot Flash Write Protect bit (Protection Disabled)
#pragma config CP = OFF                 // Code Protect (Protection Disabled)

#include "System.h"

STATUS_T SysInit(void)
{
    CheckClocks();
    AllDigital();
    
    GPIO_RB15_OUT = 0;
    GPIO_RB15_TRIS = 0;
    
    sys_time = 0;
    sys_twoseconds = false;
    running = true;
    
    if(Tmr4Setup(1000,true,7) == STAT_SUCCESS){
        Tmr4Enable();
        sys_stat |= 0x01;
    }
    
    if(UART1Setup(115200,true,true) == STAT_SUCCESS){
        sys_stat |= 0x02;
    }
    
    I2C1_init_done = false;
    if(I2C1Setup(true) == STAT_SUCCESS){    //used for IOExp as well as Oled Display
        sys_stat |= 0x04;
    }
    
    if(IOExpSetup(&ioexp1,0xE8,0x00,0xF0,0x00,0x00,0x00,0x00) == STAT_SUCCESS){
        sys_stat |= 0x08;
    }
    
    if(setupStepper0() == STAT_SUCCESS){
        sys_stat |= 0x10;
    }
    if(setupStepper1() == STAT_SUCCESS){
        sys_stat |= 0x20;
    }
    if(setupStepper2() == STAT_SUCCESS){
        sys_stat |= 0x40;
    }
   
    //Globally Enable Interrupts
    INTCONSET = _INTCON_MVEC_MASK;  //allow multiple interrupt vectors on CPU
    __builtin_enable_interrupts();  //set global interrupt enable bit
    
    if(OledInit(0x78, false) == STAT_SUCCESS){
        sys_stat |= 0x80;
    }
    OledClearDisplay();
        
    return STAT_SUCCESS;
}

STATUS_T AllDigital()
{
    ANSELA = 0;
    ANSELB = 0;
    
    return STAT_SUCCESS;
}

STATUS_T CheckClocks()
{
    while(!OSCCONbits.SLOCK || OSCCONbits.CF) continue;  //wait for PLL to lock, or block in case of clock fail
    
    return STAT_SUCCESS;
}


void interpretRX(void)
{
    char respBuff[256];
    bool valid = false;
    bool gotChar = false;
    
    char loc_msg_buff[UART1_RX_BUFF_SIZE];
    int i;
    for(i = 0; i < UART1_RX_BUFF_SIZE; i++){
        if(i < uart1_rx_buff_load_cnt)
            loc_msg_buff[i] = uart1_rx_buff_use[i];
        else 
            loc_msg_buff[i] = 0x00;
    }
    
    char *p;
    char *fieldStr[2];
    int32_t inputVal = 0;
    for(i = 0, p = strtok(loc_msg_buff,","); p != NULL, i < 2; p = strtok(NULL,","), i++){
        fieldStr[i] = p;
    }
    if(i == 2){
        char cmd[16];
        int j;
        for(j = 0; j < 16; j++){
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
