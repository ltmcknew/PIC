
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
    
    path[0].x = 0.0;
    path[0].y = 0.0;
    path[0].z = -90.0;
    path[1].x = 0.0;
    path[1].y = 0.0;
    path[1].z = -90.0;
    path[2].x = 0.0;
    path[2].y = 0.0;
    path[2].z = -90.0;
    path[3].x = 0.0;
    path[3].y = 0.0;
    path[3].z = -90.0;
    
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
    
    if(setupServo(0) == STAT_SUCCESS){
        sys_stat |= 0x40;
    }
    if(setupStepper0() == STAT_SUCCESS){
        sys_stat |= 0x10;
    }
    if(setupStepper1() == STAT_SUCCESS){
        sys_stat |= 0x20;
    }
    stepper_dist_to_steps = 3.125 / 8192.0; //0.00038146972656 inches / step
    
   
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
    
    ODCA = 0;
    ODCB = 0;
    
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
    char *p;
    char *fieldStr[MAX_INPUT_FIELDS];
    float inputVals[MAX_INPUT_FIELDS - 1];
    int fullFieldCnt = 0;
    char cmd[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int valFieldCnt = 0;
    char loc_msg_buff[UART1_RX_BUFF_SIZE];
    int i;
    
    //copy the rx buffer into a local buffer for processing
    for(i = 0; i < UART1_RX_BUFF_SIZE; i++){
        if(i < uart1_rx_buff_load_cnt)
            loc_msg_buff[i] = uart1_rx_buff_use[i];
        else 
            loc_msg_buff[i] = 0x00;
    }
    
    //split the local rx buffer into fields
    p = strtok(loc_msg_buff,",");
    for(i = 0; i < MAX_INPUT_FIELDS*2; i++){
        if(p != NULL){
            fieldStr[fullFieldCnt] = p;
            fullFieldCnt++;
            p = strtok(NULL,",");
        } else {
            break;
        }
    }

    //check if the field count is within range
    if(fullFieldCnt <= MAX_INPUT_FIELDS){
        int j;
        for(j = 0; j < strlen(fieldStr[0]); j++){
            cmd[j] = tolower(fieldStr[0][j]);
        }
        for(j = 0; j < fullFieldCnt-1; j++){
            inputVals[j] = atof(fieldStr[j+1]);
            valFieldCnt++;
        }
        
        if((strcmp(cmd,"x") == 0) && (valFieldCnt > 0)){
            gotChar = true;
            int16_t step_count = inputVals[0] / stepper_dist_to_steps;
            pendingSteps0 += step_count;
            valid = true;
            sprintf(respBuff,"Applying step to X: %ld, %fin",step_count,inputVals[0]);
            uart1_tx_str_crlf(respBuff);
        } else if((strcmp(cmd,"y") == 0) && (valFieldCnt > 0)){
            gotChar = true;
            int16_t step_count = inputVals[0] / stepper_dist_to_steps;
            pendingSteps1 += step_count;
            valid = true;
            sprintf(respBuff,"Applying step to Y: %ld, %fin",step_count,inputVals[0]);
            uart1_tx_str_crlf(respBuff);
        } else if((strcmp(cmd,"z") == 0) && (valFieldCnt > 0)){
            gotChar = true;
            if(inputVals[0] >= -180.0 && inputVals[0] <= 180.0) {
                servoAngleUse = (int16_t)inputVals[0];
                valid = true;
                setServoAngle(servoAngleUse);
                sprintf(respBuff,"Applying Angle to Servo: %d",servoAngleUse);
            } else {
                sprintf(respBuff,"Invalid Input Angle: %d, Must be in [-180:180]",inputVals[0]);
                valid = false;
            }
            uart1_tx_str_crlf(respBuff);
        } else if((strcmp(cmd,"l") == 0) && (valFieldCnt > 1)){
            gotChar = true;
            sprintf(respBuff,"Line Input Detected, X0: %f, X1: %f",inputVals[0],inputVals[1]);
            valid = true;
            uart1_tx_str_crlf(respBuff);
        } else if((strcmp(cmd,"p") == 0) && (valFieldCnt > 3)){
            if(inputVals[0] >= 0.0 && inputVals[0] <= 3.0){
                int idx = inputVals[0];
                path[idx].x = inputVals[1];
                path[idx].y = inputVals[2];
                path[idx].z = inputVals[3];
                sprintf(respBuff,"Updating path element %d, (%f,%f,%f)",idx,inputVals[1],inputVals[2],inputVals[3]);
                gotChar = true;
                valid = true; 
            } else {
                sprintf(respBuff,"Invalid path index %f, (%f,%f,%f)",inputVals[0],inputVals[1],inputVals[2],inputVals[3]);
            }
            uart1_tx_str_crlf(respBuff);
        } else if(strcmp(cmd,"o") == 0){
            gotChar = true;
            valid = true;
            sprintf(respBuff,"Zeroing X axis at current location");
            uart1_tx_str_crlf(respBuff);
            totalSteps0 = 0;
        } else if(strcmp(cmd,"r") == 0){
            gotChar = true;
            valid = true;
            sprintf(respBuff,"Run Path");
            uart1_tx_str_crlf(respBuff);
        }
    }
    if(!valid){
        sprintf(respBuff,"Invalid command, use 'X,Num', 'Y,Num', 'Z,Num', 'l,Num,Num' or 'o'\n\r");
        uart1_tx_str_crlf(respBuff);
        uart1_wait();
        sprintf(respBuff,"Received %d fields, %d values\n\r",fullFieldCnt,valFieldCnt);
        uart1_tx_str_crlf(respBuff);
        uart1_wait();
    }
//    sprintf(respBuff,"Received %d fields, %d values\n\r",fullFieldCnt,valFieldCnt);
//    uart1_tx_str_crlf(respBuff);
//    uart1_wait();
//    for(i = 0; i < fullFieldCnt; i++){
//        sprintf(respBuff,"Field[%d]: %s",i,fieldStr[i]);
//        uart1_tx_str_crlf(respBuff);
//        uart1_wait();
//    }
}
