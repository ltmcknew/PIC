#include "i2c.h"

#ifdef __USE_I2C1__
STATUS_T I2C1Setup(bool high_speed)
{
    I2C1Disable();    //ensure the MSSP1 module is off to start
    
    I2C1_CLK_PPS_OUT = 0x21;
    I2C1_DAT_PPS_OUT = 0x22;
    I2C1SCLPPS = I2C1_CLK_PPS_VAL;
    I2C1SDAPPS = I2C1_DAT_PPS_VAL;
    I2C1_CLK_ODCON = 1;
    I2C1_DAT_ODCON = 1;
    I2C1_CLK_TRIS = 0;
    I2C1_DAT_TRIS = 0;
    
    I2C1CON0 = 0x04;    //7-bit address master mode
    I2C1CON1 = 0x80;
    I2C1CON2 = 0x08;    //Fscl = Fi2c1clk/5, Disable Address Data Buffers
    I2C1CLK = 0x08;     //select Timer6 for Fi2c1clk
    
    I2C1_use_highspeed = high_speed;
    if(high_speed){
        if(Tmr6Setup(2000000,false) == STAT_SUCCESS){
            Tmr6Enable();
        } else return STAT_FAIL;
    } else {
        if(Tmr6Setup(500000,false) == STAT_SUCCESS){
            Tmr6Enable();
        } else return STAT_FAIL;
    }
    
    return STAT_SUCCESS;
}

STATUS_T I2C1Enable()
{
//    I2C1STAT1bits.TXWE = 0;
//    I2C1STAT1bits.RXRE = 0;
//    I2C1STAT1bits.CLRBF = 1;    //reset RXBF and TXBE, clear I2C1RXIF and I2C1TXIF
            
    I2C1CON0bits.EN = 1;
    return STAT_SUCCESS;
}

STATUS_T I2C1Disable()
{
    I2C1CON0bits.EN = 0;
    Tmr6Disable();
    return STAT_SUCCESS;
}

uint8_t I2C1Write(uint8_t byteCnt, uint8_t devAddr)
{
    while(!I2C1STAT0bits.BFRE);   //wait for module to not be busy
    //Sequence from DS 33.5.9 MASTER TRANSMISSION IN 7-BIT ADDRESSING MODE, page 568
    uint8_t write_count = 0;
    
    // 1: With ABD == 1, load I2CxCNT with number of bytes to transmit in this sequence and load the slave address into I2C1TXB
    //      Writing to I2C1TXB sets the start bit S and begins the start sequence in the HW
    // 2-11: Check for I2C1TXIF and MDR being set, indicates able to load next byte, check ACK/NACK status after shifting the byte out
    I2C1ADB1 = devAddr & 0xFE;
    I2C1CNT = byteCnt;  //number of data bytes plus the address byte
    I2C1CON0bits.S = 1;
    for(write_count = 0; write_count < byteCnt; write_count++){
        I2C1TXB = I2C1_buff_out[write_count];   //requires the Address byte to be loaded correctly into the first location in the buffer
        while(!I2C1STAT1bits.TXBE);  //on 8th falling SCL edge these become set
//        if(I2C1CON1bits.ACKSTAT && I2C1CNT > 0) return write_count;
    }
    //Stop condition is automatically begun when I2C1CNT == 0 after transmission
    
    return write_count;
}

uint8_t I2C1Read(uint8_t byteCnt, uint8_t devAddr)
{
    while(I2C1STAT0bits.MMA && !I2C1STAT0bits.BFRE);   //wait for module to not be busy
    uint8_t read_count = 0; 
    I2C1ADB1 = devAddr | 0x01;
    I2C1CNT = byteCnt;
    I2C1CON0bits.S = 1;
    
    for(read_count = 0; read_count < byteCnt; read_count++){
        while(!I2C1STAT1bits.RXBF);
        I2C1_buff_in[read_count] = I2C1RXB;
    }
    
    return read_count;
}

uint8_t I2C1WrRd(uint8_t wrCnt, uint8_t rdCnt, uint8_t devAddr)
{    
    while(I2C1STAT0bits.MMA && !I2C1STAT0bits.BFRE);   //wait for module to not be busy
    //Sequence from DS 33.5.9 MASTER TRANSMISSION IN 7-BIT ADDRESSING MODE, page 568
    uint8_t write_count = 0;
    I2C1ADB1 = devAddr & 0xFE;
    I2C1CNT = wrCnt;  //number of data bytes plus the address byte
    I2C1CON0bits.S = 1;
    for(write_count = 0; write_count < wrCnt; write_count++){
        I2C1TXB = I2C1_buff_out[write_count];   //requires the Address byte to be loaded correctly into the first location in the buffer
        while(!I2C1STAT1bits.TXBE);  //on 8th falling SCL edge these become set
    }

    while(I2C1STAT0bits.MMA);
    uint8_t read_count = 0; 
    I2C1ADB1 = devAddr | 0x01;
    I2C1CNT = rdCnt;
//    I2C1CON0bits.RSEN = 1;
    I2C1CON0bits.S = 1;
    
    for(read_count = 0; read_count < rdCnt; read_count++){
        while(!I2C1STAT1bits.RXBF);
        I2C1_buff_in[read_count] = I2C1RXB;
    }

//    I2C1CON0bits.RSEN = 0;  
    
    return read_count;
}
#endif