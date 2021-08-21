#include "IOExp_PCA9539A.h"

//Private function prototypes
STATUS_T IOExpWriteDir(IOEXP_PCA9539_T *ioexp_inst, enum IOEXP_PORTENUM portSel);
STATUS_T IOExpWriteInv(IOEXP_PCA9539_T *ioexp_inst, enum IOEXP_PORTENUM portSel);
STATUS_T IOExpWriteVal(IOEXP_PCA9539_T *ioexp_inst, enum IOEXP_PORTENUM portSel);

STATUS_T IOExpReadDir(IOEXP_PCA9539_T *ioexp_inst, enum IOEXP_PORTENUM portSel);
STATUS_T IOExpReadInv(IOEXP_PCA9539_T *ioexp_inst, enum IOEXP_PORTENUM portSel);
STATUS_T IOExpReadIVal(IOEXP_PCA9539_T *ioexp_inst, enum IOEXP_PORTENUM portSel);
STATUS_T IOExpReadOVal(IOEXP_PCA9539_T *ioexp_inst, enum IOEXP_PORTENUM portSel);

STATUS_T IOExpSetup(IOEXP_PCA9539_T *ioexp_inst, uint8_t set_addr, uint8_t set_dir_p0, uint8_t set_dir_p1, uint8_t set_inv_p0, uint8_t set_inv_p1, uint8_t set_oval_p0, uint8_t set_oval_p1)
{
    /* This chip has 2 8-bit Ports. 
     * These can be configured as Inputs and Outputs and when setup as inputs their polarity can be inverted
     * 
     * To accomplish all this there a command byte must accompany the chip address when reading/writing the device
     * 
     * To set directions, the Configuration Register for the port must be set to 1's to make the pins inputs and cleared to 0's to make them outputs.
     * The pins default to inputs, which may or maynot be useful.
     * 
     * If the pin is an input then the Inversion register can be used to invert the signal. 0's in the inversion register make the pins active high
     * and 1's in the inversion register activate the inverse behavior making the pins active low. Effectively, if the pin is inverted the reading 
     * the input register will indicate a low signal at the pin with a 1 in the register and vice versa.
     * The pins default to active high.
     * 
     * The input port registers are read only and the output port registers can be read or written.
     * The input registers are undefined on reset as they aren't actively driven in this mode so they are controlled by the external circuitry.
     * The output register values default to all 1's coming out of reset/power cycle
     */
    
    //start by initializing the instance
    ioexp_inst->Addr = set_addr;
    
    ioexp_inst->P0Dir.val = set_dir_p0;
    ioexp_inst->P0Inv.val = set_inv_p0;
    ioexp_inst->P0OVal.val = set_oval_p0;
    
    ioexp_inst->P1Dir.val = set_dir_p1;
    ioexp_inst->P1Inv.val = set_inv_p1;
    ioexp_inst->P1OVal.val = set_oval_p1;
    
    //then setup the I2C port
#if defined(__USE_MMSP1__)
    if(MSSP1SetupI2C(true,true,true) != STAT_SUCCESS){
        return STAT_FAIL;
    }
    MSSP1Enable();
#elif defined(__USE_I2C1__)
    if(I2C1Setup(true) != STAT_SUCCESS){
        return STAT_FAIL;
    }
    IOEXP_RST = 0;  //load 0 into the reset bit
    IOEXP_RST_TRIS = 0; //make the pin an output and assert reset
//    __delay_ms(5);  //wait 5ms for the reset to occur
    int i;
    for(i = 0; i < 1000; i++) continue;
    I2C1Enable();
    IOEXP_RST = 1;  //release the reset condition.
#endif    
    
    return IOExpUpdateAll(ioexp_inst);
//    if(IOExpWriteInv(ioexp_inst, BOTH) != STAT_SUCCESS)
//        return STAT_FAIL;
//
//    if(IOExpWriteVal(ioexp_inst, BOTH) != STAT_SUCCESS)
//        return STAT_FAIL;
//
//    if(IOExpWriteDir(ioexp_inst, BOTH) != STAT_SUCCESS)
//        return STAT_FAIL;
//
//    if(IOExpReadIVal(ioexp_inst, BOTH) != STAT_SUCCESS)
//        return STAT_FAIL;
//    
//    return STAT_SUCCESS;
}

STATUS_T IOExpUpdateAll(IOEXP_PCA9539_T *ioexp_inst)
{
     if(IOExpWriteInv(ioexp_inst, BOTH) != STAT_SUCCESS)
        return STAT_FAIL;

    if(IOExpWriteVal(ioexp_inst, BOTH) != STAT_SUCCESS)
        return STAT_FAIL;

    if(IOExpWriteDir(ioexp_inst, BOTH) != STAT_SUCCESS)
        return STAT_FAIL;

    if(IOExpReadIVal(ioexp_inst, BOTH) != STAT_SUCCESS)
        return STAT_FAIL;
    
    return STAT_SUCCESS;
}

STATUS_T IOExpUpdateOut(IOEXP_PCA9539_T *ioexp_inst, uint16_t set_oval)
{
    ioexp_inst->P0OVal.val = set_oval & 0x00FF;
    ioexp_inst->P1OVal.val = set_oval >> 8;
        
    return IOExpWriteVal(ioexp_inst, BOTH);
}

STATUS_T IOExpUpdateOutPart(IOEXP_PCA9539_T *ioexp_inst, uint8_t set_oval, uint8_t port_num)
{
    if(port_num == 0){
        ioexp_inst->P0OVal.val = set_oval;
        return IOExpWriteVal(ioexp_inst, P0);
    } else if(port_num == 1){
        ioexp_inst->P1OVal.val = set_oval;
        return IOExpWriteVal(ioexp_inst, P1);
    }
    return STAT_ERR;
}

STATUS_T IOExpUpdateIn(IOEXP_PCA9539_T *ioexp_inst)
{
    return IOExpReadIVal(ioexp_inst, BOTH);
}

STATUS_T IOExpWriteDir(IOEXP_PCA9539_T *ioexp_inst, enum IOEXP_PORTENUM portSel)
{
    uint8_t wrtCnt = 2;
    uint8_t intAddr = 0x06;
    uint8_t datVals[2];
    datVals[0] = ioexp_inst->P0Dir.val;
    datVals[1] = ioexp_inst->P1Dir.val;
    
    if(portSel == P1){
        intAddr = 0x07;
        datVals[0] = ioexp_inst->P1Dir.val;
    } else if(portSel == BOTH){
        wrtCnt = 3;
    }
    
#if defined(__USE_MSSP1__)
    MSSP1_buff_out[0] = intAddr;
    MSSP1_buff_out[1] = datVals[0];
    if(wrtCnt == 3){
        MSSP1_buff_out[2] = datVals[1];
    }
    if(MSSP1Write(wrtCnt, ioexp_inst.Addr) == wrtCnt)
        return STAT_SUCCESS;
#elif defined(__USE_I2C1__)
    I2C1_buff_out[0] = intAddr;
    I2C1_buff_out[1] = datVals[0];
    if(wrtCnt == 3){
        I2C1_buff_out[2] = datVals[1];
    }
    if(I2C1Write(wrtCnt, ioexp_inst->Addr) == wrtCnt)
        return STAT_SUCCESS;
#endif
    
    return STAT_FAIL;
}

STATUS_T IOExpWriteInv(IOEXP_PCA9539_T *ioexp_inst, enum IOEXP_PORTENUM portSel)
{
    uint8_t wrtCnt = 2;
    uint8_t intAddr = 0x04;
    uint8_t datVals[2];
    datVals[0] = ioexp_inst->P0Inv.val;
    datVals[1] = ioexp_inst->P1Inv.val;
    
    if(portSel == P1){
        intAddr = 0x05;
        datVals[0] = ioexp_inst->P1Inv.val;
    } else if(portSel == BOTH){
        wrtCnt = 3;
    }
    
#if defined(__USE_MSSP1__)
    MSSP1_buff_out[0] = intAddr;
    MSSP1_buff_out[1] = datVals[0];
    if(wrtCnt == 3){
        MSSP1_buff_out[2] = datVals[1];
    }
    if(MSSP1Write(wrtCnt, ioexp_inst.Addr) == wrtCnt)
        return STAT_SUCCESS;
#elif defined(__USE_I2C1__)
    I2C1_buff_out[0] = intAddr;
    I2C1_buff_out[1] = datVals[0];
    if(wrtCnt == 3){
        I2C1_buff_out[2] = datVals[1];
    }
    if(I2C1Write(wrtCnt, ioexp_inst->Addr) == wrtCnt)
        return STAT_SUCCESS;
#endif
    
    return STAT_FAIL;
}

STATUS_T IOExpWriteVal(IOEXP_PCA9539_T *ioexp_inst, enum IOEXP_PORTENUM portSel)
{
    uint8_t wrtCnt = 2;
    uint8_t intAddr = 0x02;
    uint8_t datVals[2];
    datVals[0] = ioexp_inst->P0OVal.val;
    datVals[1] = ioexp_inst->P1OVal.val;
    
    if(portSel == P1){
        intAddr = 0x03;
        datVals[0] = ioexp_inst->P1OVal.val;
    } else if(portSel == BOTH){
        wrtCnt = 3;
    }
    
#if defined(__USE_MSSP1__)
    MSSP1_buff_out[0] = intAddr;
    MSSP1_buff_out[1] = datVals[0];
    if(wrtCnt == 3){
        MSSP1_buff_out[2] = datVals[1];
    }
    if(MSSP1Write(wrtCnt, ioexp_inst.Addr) == wrtCnt)
        return STAT_SUCCESS;
#elif defined(__USE_I2C1__)
    I2C1_buff_out[0] = intAddr;
    I2C1_buff_out[1] = datVals[0];
    if(wrtCnt == 3){
        I2C1_buff_out[2] = datVals[1];
    }
    
    if(I2C1Write(wrtCnt, ioexp_inst->Addr) == wrtCnt)
        return STAT_SUCCESS;
#endif
    
    return STAT_FAIL;
}


STATUS_T IOExpReadDir(IOEXP_PCA9539_T *ioexp_inst, enum IOEXP_PORTENUM portSel)
{
    uint8_t rdCnt = 1;
    uint8_t intAddr = 0x06;
    uint8_t outVals[2];
    if(portSel == P1) intAddr = 0x07;
    else if (portSel == BOTH) rdCnt = 2;
    
#ifdef __USE_MSSP1__
    MSSP1_buff_out[0] = intAddr;
    if(MSSP1WrRd(1,rdCnt,ioexp_inst.Addr) != rdCnt)
        return STAT_FAIL;
    outVals[0] = MSSP1_buff_in[0];
    outVals[1] = MSSP1_buff_in[1];
#elif defined(__USE_I2C1__)
    I2C1_buff_out[0] = intAddr;
    if(I2C1WrRd(1,rdCnt,ioexp_inst->Addr) != rdCnt)
        return STAT_FAIL;
    outVals[0] = I2C1_buff_in[0];
    outVals[1] = I2C1_buff_in[1];
#endif
    
    if(portSel == P0) ioexp_inst->P0Dir.val = outVals[0];      //assign P0OVal after read
    else if(portSel == P1) ioexp_inst->P1Dir.val = outVals[0]; //assign P1OVal after read
    else if(portSel == BOTH){
        ioexp_inst->P0Dir.val = outVals[0];                    //assign P0OVal after read
        ioexp_inst->P1Dir.val = outVals[1];                    //assign P1OVal after read
    }
    
    return STAT_SUCCESS;
}

STATUS_T IOExpReadInv(IOEXP_PCA9539_T *ioexp_inst, enum IOEXP_PORTENUM portSel)
{
    uint8_t rdCnt = 1;
    uint8_t intAddr = 0x04;
    uint8_t outVals[2];
    if(portSel == P1) intAddr = 0x05;
    else if (portSel == BOTH) rdCnt = 2;
    
#ifdef __USE_MSSP1__
    MSSP1_buff_out[0] = intAddr;
    if(MSSP1WrRd(1,rdCnt,ioexp_inst.Addr) != rdCnt)
        return STAT_FAIL;
    outVals[0] = MSSP1_buff_in[0];
    outVals[1] = MSSP1_buff_in[1];
#elif defined(__USE_I2C1__)
    I2C1_buff_out[0] = intAddr;
    if(I2C1WrRd(1,rdCnt,ioexp_inst->Addr) != rdCnt)
        return STAT_FAIL;
    outVals[0] = I2C1_buff_in[0];
    outVals[1] = I2C1_buff_in[1];
#endif
    
    if(portSel == P0) ioexp_inst->P0Inv.val = outVals[0];      //assign P0OVal after read
    else if(portSel == P1) ioexp_inst->P1Inv.val = outVals[0]; //assign P1OVal after read
    else if(portSel == BOTH){
        ioexp_inst->P0Inv.val = outVals[0];                    //assign P0OVal after read
        ioexp_inst->P1Inv.val = outVals[1];                    //assign P1OVal after read
    }
    
    return STAT_SUCCESS;
}

STATUS_T IOExpReadIVal(IOEXP_PCA9539_T *ioexp_inst, enum IOEXP_PORTENUM portSel)
{
    uint8_t rdCnt = 1;
    uint8_t intAddr = 0x00;
    uint8_t outVals[2];
    if(portSel == P1) intAddr = 0x01;
    else if (portSel == BOTH) rdCnt = 2;
    
#ifdef __USE_MSSP1__
    MSSP1_buff_out[0] = intAddr;
    if(MSSP1WrRd(1,rdCnt,ioexp_inst.Addr) != rdCnt)
        return STAT_FAIL;
    outVals[0] = MSSP1_buff_in[0];
    outVals[1] = MSSP1_buff_in[1];
#elif defined(__USE_I2C1__)
    I2C1_buff_out[0] = intAddr;
    if(I2C1WrRd(1,rdCnt,ioexp_inst->Addr) != rdCnt)
        return STAT_FAIL;
    outVals[0] = I2C1_buff_in[0];
    outVals[1] = I2C1_buff_in[1];
#endif
    
    if(portSel == P0) ioexp_inst->P0IVal.val = outVals[0];      //assign P0OVal after read
    else if(portSel == P1) ioexp_inst->P1IVal.val = outVals[0]; //assign P1OVal after read
    else if(portSel == BOTH){
        ioexp_inst->P0IVal.val = outVals[0];                    //assign P0OVal after read
        ioexp_inst->P1IVal.val = outVals[1];                    //assign P1OVal after read
    }
    
    return STAT_SUCCESS;
}

STATUS_T IOExpReadOVal(IOEXP_PCA9539_T *ioexp_inst, enum IOEXP_PORTENUM portSel)
{
    uint8_t rdCnt = 1;
    uint8_t intAddr = 0x02;
    uint8_t outVals[2];
    if(portSel == P1) intAddr = 0x03;
    else if (portSel == BOTH) rdCnt = 2;
    
#ifdef __USE_MSSP1__
    MSSP1_buff_out[0] = intAddr;
    if(MSSP1WrRd(1,rdCnt,ioexp_inst.Addr) != rdCnt)
        return STAT_FAIL;
    outVals[0] = MSSP1_buff_in[0];
    outVals[1] = MSSP1_buff_in[1];
#elif defined(__USE_I2C1__)
    I2C1_buff_out[0] = intAddr;
    if(I2C1WrRd(1,rdCnt,ioexp_inst->Addr) != rdCnt)
        return STAT_FAIL;
    outVals[0] = I2C1_buff_in[0];
    outVals[1] = I2C1_buff_in[1];
#endif
    
    if(portSel == P0) ioexp_inst->P0OVal.val = outVals[0];      //assign P0OVal after read
    else if(portSel == P1) ioexp_inst->P1OVal.val = outVals[0]; //assign P1OVal after read
    else if(portSel == BOTH){
        ioexp_inst->P0OVal.val = outVals[0];                    //assign P0OVal after read
        ioexp_inst->P1OVal.val = outVals[1];                    //assign P1OVal after read
    }
    
    return STAT_SUCCESS;
}
