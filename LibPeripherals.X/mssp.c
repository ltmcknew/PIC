#include "mssp.h"

#ifdef __USE_MSSP1__
STATUS_T MSSP1SetupI2C(bool high_speed, bool use_tx, bool use_rx)
{
    MSSP1Disable();    //ensure the MSSP1 module is off to start
    
    MSSP1_CLK_TRIS = 1;
    MSSP1_DAT_TRIS = 1;
    MSSP1_CLK_PPS_OUT = 0x14;
    MSSP1_DAT_PPS_OUT = 0x15;
    SSP1CLKPPS = MSSP1_CLK_PPS_VAL;
    SSP1DATPPS = MSSP1_DAT_PPS_VAL;
    
    SSP1CON1bits.SSPM = 0b1000;
    SSP1CON2 = 0x00;
    SSP1CON3 = 0x00;    //Mostly I2C Slave Mode Only
    
    if(high_speed){
        uint8_t tmp = (_XTAL_FREQ / 1600000) - 1;    //Fosc / (400KHz * 4)  - 1  = SSP1ADD
        SSP1ADD = tmp;
        SSP1STATbits.SMP = 0;   //enable fast slew rate
    } else {
        uint8_t tmp = (_XTAL_FREQ / 400000) - 1;    //Fosc / (100KHz * 4)  - 1  = SSP1ADD
        SSP1ADD = tmp;
        SSP1STATbits.SMP = 1;   //disable fast slew rate
    }
    
    return STAT_SUCCESS;
}

STATUS_T MSSP1Enable()
{
    SSP1CON1bits.SSPEN = 1;
    return STAT_SUCCESS;
}

STATUS_T MSSP1Disable()
{
    SSP1CON1bits.SSPEN = 0;
    return STAT_SUCCESS;
}

void I2C_Master_Wait()
{
  while ((SSP1STAT & 0x04) || (SSP1CON2 & 0x1F));
}

void I2C_Master_Start()
{
  I2C_Master_Wait();
  SEN1 = 1;
}

void I2C_Master_RepeatedStart()
{
  I2C_Master_Wait();
  RSEN1 = 1;
}

void I2C_Master_Stop()
{
  I2C_Master_Wait();
  PEN1 = 1;
}

void I2C_Master_Write(unsigned d)
{
  I2C_Master_Wait();
  SSP1BUF = d;
}

uint8_t MSSP1Write(uint8_t byteCnt, uint8_t devAddr)
{
    uint8_t write_count = 0;
    
    I2C_Master_Start();         //Start condition
    I2C_Master_Write(devAddr & 0xFE);     //7 bit address + Write
    
    for(write_count = 0; write_count < byteCnt; write_count++){
        I2C_Master_Write(MSSP1_buff_out[write_count]);    //Write data
    }
    
    I2C_Master_Stop();          //Stop condition
    
    return write_count;
}

uint8_t MSSP1Read(uint8_t byteCnt, uint8_t devAddr)
{
    uint8_t read_count = 0;
    
    I2C_Master_Start();         //Start condition
    I2C_Master_Write(devAddr | 0x01);     //7 bit address + Read

    for(read_count = 0; read_count < byteCnt; read_count++){
        I2C_Master_Wait();
        RCEN1 = 1;
        I2C_Master_Wait();
        MSSP1_buff_in[read_count] = SSP1BUF; //Read + Acknowledge
        I2C_Master_Wait();
        ACKDT1 = (byteCnt - read_count > 1)?0:1; //Acknowledge until read_count == byteCnt-1, or on last byte send a 1 for NACK
        ACKEN1 = 1;
    }
    
    I2C_Master_Stop();          //Stop condition    
    
    return read_count;
}

uint8_t MSSP1WrRd(uint8_t wrCnt, uint8_t rdCnt, uint8_t devAddr)
{    
    I2C_Master_Start(); //start condition
    I2C_Master_Write(devAddr & 0xFE);   //First write the indicated number of bytes to the chip, usually to set a register or issue command before reading
    
    for(uint8_t write_count = 0; write_count < wrCnt; write_count++){
        I2C_Master_Write(MSSP1_buff_out[write_count]);    //Write data
    }
  
    uint8_t read_count = 0;  
    I2C_Master_RepeatedStart(); //issue repeated start condition
    I2C_Master_Write(devAddr | 0x01);     //7 bit address + Read

    for(read_count = 0; read_count < rdCnt; read_count++){
        I2C_Master_Wait();
        RCEN1 = 1;
        I2C_Master_Wait();
        MSSP1_buff_in[read_count] = SSP1BUF; //Read + Acknowledge
        I2C_Master_Wait();
        ACKDT1 = (rdCnt - read_count > 1)?0:1; //Acknowledge until read_count == byteCnt-1, or on last byte send a 1 for NACK
        ACKEN1 = 1;
    }
    
    I2C_Master_Stop();          //Stop condition    
    
    return read_count;
}
#endif





