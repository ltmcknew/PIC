#include "I2C.h"

#ifdef __USE_I2C1__
// I2C_wait_for_idle() waits until the I2C peripheral is no longer doing anything  
void I2C_wait_for_idle(void)
{
    while(I2C1CON & 0x1F); // Acknowledge sequence not in progress
                                // Receive sequence not in progress
                                // Stop condition not in progress
                                // Repeated Start condition not in progress
                                // Start condition not in progress
    while(I2C1STATbits.TRSTAT); // Bit = 0 ? Master transmit is not in progress
}

// I2C_start() sends a start condition  
void I2C_start()
{
    I2C_wait_for_idle();
    I2C1CONbits.SEN = 1;
    while (I2C1CONbits.SEN == 1);
}

// I2C_stop() sends a stop condition  
void I2C_stop()
{
    I2C_wait_for_idle();
    I2C1CONbits.PEN = 1;
}

// I2C_restart() sends a repeated start/restart condition
void I2C_restart()
{
    I2C_wait_for_idle();
    I2C1CONbits.RSEN = 1;
    while (I2C1CONbits.RSEN == 1);
}

// I2C_ack() sends an ACK condition
void I2C_ack(void)
{
    I2C_wait_for_idle();
    I2C1CONbits.ACKDT = 0; // Set hardware to send ACK bit
    I2C1CONbits.ACKEN = 1; // Send ACK bit, will be automatically cleared by hardware when sent  
    while(I2C1CONbits.ACKEN); // Wait until ACKEN bit is cleared, meaning ACK bit has been sent
}

// I2C_nack() sends a NACK condition
void I2C_nack(void) // Acknowledge Data bit
{
    I2C_wait_for_idle();
    I2C1CONbits.ACKDT = 1; // Set hardware to send NACK bit
    I2C1CONbits.ACKEN = 1; // Send NACK bit, will be automatically cleared by hardware when sent  
    while(I2C1CONbits.ACKEN); // Wait until ACKEN bit is cleared, meaning NACK bit has been sent
}

// address is I2C slave address, set wait_ack to 1 to wait for ACK bit or anything else to skip ACK checking  
void I2C_write(unsigned char address, char wait_ack)
{
    I2C1TRN = address | 0;              // Send slave address with Read/Write bit cleared
    while (I2C1STATbits.TBF == 1);      // Wait until transmit buffer is empty
    I2C_wait_for_idle();                // Wait until I2C bus is idle
    if (wait_ack) while (I2C1STATbits.ACKSTAT == 1); // Wait until ACK is received  
}

// value is the value of the data we want to send, set ack_nack to 0 to send an ACK or anything else to send a NACK  
void I2C_read(unsigned char *value, char ack_nack)
{
    I2C1CONbits.RCEN = 1;               // Receive enable
    while (I2C1CONbits.RCEN);           // Wait until RCEN is cleared (automatic)  
    while (!I2C1STATbits.RBF);          // Wait until Receive Buffer is Full (RBF flag)  
    *value = I2C1RCV;                   // Retrieve value from I2C1RCV

    if (!ack_nack)                      // Do we need to send an ACK or a NACK?  
        I2C_ack();                      // Send ACK  
    else
        I2C_nack();                     // Send NACK  
}




STATUS_T I2C1Setup(bool high_speed)
{
//    if(!I2C1_init_done){
        I2C1Disable();    //ensure the MSSP1 module is off to start
    
        //No PPS for this line of Pics, I2Cx pins are only on dedicated pins.
        I2C1_CLK_ODCON = 1;
        I2C1_DAT_ODCON = 1;
        I2C1_CLK_TRIS = 1;
        I2C1_DAT_TRIS = 1;

        //The module is both master and slave at the same time, the control bits activate the master and slave portions respectively as data is read/written
        I2C1CONCLR = 0xFFFFFFFF;    //resetting to default values, implies 7-bit address mode and High Speed slew rate

        I2C1_use_highspeed = high_speed;
        if(high_speed){
            I2C1BRG = (_XTAL_FREQ / (800000)) - 2;  //400KHz
        } else {
            I2C1BRG = (_XTAL_FREQ / (200000)) - 2;  //100KHz
            I2C1CONSET = _I2C1CON_DISSLW_MASK;      //set slew rate for 100KHz operation
        }
        
        I2C1_init_done = true;
//    }
    
    return STAT_SUCCESS;
}

STATUS_T I2C1Enable()
{
//    I2C1STAT1bits.TXWE = 0;
//    I2C1STAT1bits.RXRE = 0;
//    I2C1STAT1bits.CLRBF = 1;    //reset RXBF and TXBE, clear I2C1RXIF and I2C1TXIF

    I2C1CONSET = _I2C1CON_I2CEN_MASK;
//    I2C1CON0bits.EN = 1;
    return STAT_SUCCESS;
}

STATUS_T I2C1Disable()
{
//    I2C1CON0bits.EN = 0;
    I2C1CONCLR = _I2C1CON_I2CEN_MASK;
//    Tmr6Disable();
    return STAT_SUCCESS;
}

uint8_t I2C1Write(uint8_t byteCnt, uint8_t devAddr)
{
    I2C_start();
    I2C_write(devAddr & 0xFE, 1);
    uint8_t i;
    for(i = 0; i < byteCnt; i++){
        I2C_write(I2C1_buff_out[i], 1);
    }
    I2C_stop();
    return byteCnt;
}

uint8_t I2C1Read(uint8_t byteCnt, uint8_t devAddr)
{
    I2C_start();
    I2C_write(devAddr | 0x01, 1);
    uint8_t i;
    uint8_t ack_nack = 0;
    for(i = 0; i < byteCnt; i++){
        if(i == (byteCnt-1)) ack_nack = 1;
        I2C_read(&I2C1_buff_in[i], ack_nack);
    }
    I2C_stop();
    return byteCnt;
}

uint8_t I2C1WrRd(uint8_t wrCnt, uint8_t rdCnt, uint8_t devAddr)
{    
    I2C_start();
    I2C_write(devAddr & 0xFE, 1);
    uint8_t i;
    for(i = 0; i < wrCnt; i++){
        I2C_write(I2C1_buff_out[i], 1);
    }
    I2C_restart();
    I2C_write(devAddr | 0x01, 1);
    
    uint8_t ack_nack = 0;
    for(i = 0; i < rdCnt; i++){
        if(i == (rdCnt-1)) ack_nack = 1;
        I2C_read(&I2C1_buff_in[i], ack_nack);
    }
    I2C_stop();
    return rdCnt;
}
#endif
