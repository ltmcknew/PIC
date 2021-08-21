#include "disp_7seg4dig.h"

#ifdef __USE_7SEGDISP__
STATUS_T setupDisp(uint16_t initVal)
{
    
    //give the digits a default state of off    
    DIG0_OUT = 0;
    DIG1_OUT = 0;
    DIG2_OUT = 0;
    DIG3_OUT = 0;

    //make the digit pins outputs
    DIG0_TRIS = 0;
    DIG1_TRIS = 0;
    DIG2_TRIS = 0;
    DIG3_TRIS = 0;

    SEGS_OUT = 0xFF;    //set all segments to off
    SEGS_TRIS = 0x00;   //set all segment pins to outputs
    
    dig_idx = 0;
    update_disp_trigger = false;
    
    updateDispVal(initVal,4);
    
    return STAT_SUCCESS;
}

STATUS_T updateDispVal(uint16_t newVal, uint8_t newDP)
{
    bool dig_0_on = false;
    bool dig_1_on = false;
    bool dig_2_on = false;
    bool dig_3_on = false;
    
    uint16_t tmpVal = newVal / 1000;
    if(tmpVal > 0){
        dig_disp_val[3] = dispChars[tmpVal];
        dig_3_on = true;
    } else if (newDP == 3) {
        dig_disp_val[3] = dispChars[0];
        dig_3_on = true;
    } else {
        dig_disp_val[3] = 0xFF;
    }
    if(dig_3_on && newDP == 3)
        dig_disp_val[3] &= DP;  //and the value with 0xEF to clear the DP bit
    newVal = newVal % 1000;
    
    tmpVal = newVal / 100;
    if(tmpVal > 0){
        dig_disp_val[2] = dispChars[tmpVal];
        dig_2_on = true;
    } else {
        if(dig_3_on){
            dig_disp_val[2] = dispChars[0];
            dig_2_on = true;
        } else if (newDP == 2) {
            dig_disp_val[2] = dispChars[0];
            dig_2_on = true;
        } else {
            dig_disp_val[2] = 0xFF;
        }
    }    
    if(dig_2_on && newDP == 2)
        dig_disp_val[2] &= DP;  //and the value with 0xEF to clear the DP bit
    newVal = newVal % 100;
    
    tmpVal = newVal / 10;
    if(tmpVal > 0){
        dig_disp_val[1] = dispChars[tmpVal];
        dig_1_on = true;
    } else {
        if(dig_2_on){
            dig_disp_val[1] = dispChars[0];
            dig_1_on = true;
        } else if (newDP == 1) {
            dig_disp_val[1] = dispChars[0];
            dig_1_on = true;
        } else {
            dig_disp_val[1] = 0xFF;
        }
    }    
    if(dig_1_on && newDP == 1)
        dig_disp_val[1] &= DP;  //and the value with 0xEF to clear the DP bit
    newVal = newVal % 10;
    
    tmpVal = newVal;
    if(tmpVal > 0){
        dig_disp_val[0] = dispChars[tmpVal];
        dig_0_on = true;
    } else {
        if(dig_1_on){
            dig_disp_val[0] = dispChars[0];
            dig_0_on = true;
        } else if (newDP == 0) {
            dig_disp_val[0] = dispChars[0];
            dig_0_on = true;
        } else if (newVal == 0) {
            dig_disp_val[0] = dispChars[0];
            dig_0_on = true;
        } else {
            dig_disp_val[0] = 0xFF;
        }
    }    
    if(dig_0_on && newDP == 0)
        dig_disp_val[0] &= DP;  //and the value with 0xEF to clear the DP bit
    return STAT_SUCCESS;
}

STATUS_T updateDispValHex(uint16_t newVal, uint8_t newDP)
{
    bool dig_0_on = false;
    bool dig_1_on = false;
    bool dig_2_on = false;
    bool dig_3_on = false;
    
    uint16_t tmpVal = newVal >> 12;
    if(tmpVal > 0){
        dig_disp_val[3] = dispChars[tmpVal];
        dig_3_on = true;
    } else if (newDP == 3) {
        dig_disp_val[3] = dispChars[0];
        dig_3_on = true;
    } else {
        dig_disp_val[3] = 0xFF;
    }
    if(dig_3_on && newDP == 3)
        dig_disp_val[3] &= DP;  //and the value with 0xEF to clear the DP bit
    newVal = newVal - (tmpVal << 12);
    
    tmpVal = newVal >> 8;
    if(tmpVal > 0){
        dig_disp_val[2] = dispChars[tmpVal];
        dig_2_on = true;
    } else {
        if(dig_3_on){
            dig_disp_val[2] = dispChars[0];
            dig_2_on = true;
        } else if (newDP == 2) {
            dig_disp_val[2] = dispChars[0];
            dig_2_on = true;
        } else {
            dig_disp_val[2] = 0xFF;
        }
    }    
    if(dig_2_on && newDP == 2)
        dig_disp_val[2] &= DP;  //and the value with 0xEF to clear the DP bit
    newVal = newVal - (tmpVal << 8);
    
    tmpVal = newVal >> 4;
    if(tmpVal > 0){
        dig_disp_val[1] = dispChars[tmpVal];
        dig_1_on = true;
    } else {
        if(dig_2_on){
            dig_disp_val[1] = dispChars[0];
            dig_1_on = true;
        } else if (newDP == 1) {
            dig_disp_val[1] = dispChars[0];
            dig_1_on = true;
        } else {
            dig_disp_val[1] = 0xFF;
        }
    }    
    if(dig_1_on && newDP == 1)
        dig_disp_val[1] &= DP;  //and the value with 0xEF to clear the DP bit
    newVal = newVal - (tmpVal << 4);
    
    tmpVal = newVal;
    if(tmpVal > 0){
        dig_disp_val[0] = dispChars[tmpVal];
        dig_0_on = true;
    } else {
        if(dig_1_on){
            dig_disp_val[0] = dispChars[0];
            dig_0_on = true;
        } else if (newDP == 0) {
            dig_disp_val[0] = dispChars[0];
            dig_0_on = true;
        } else {
            dig_disp_val[0] = 0xFF;
        }
    }    
    if(dig_0_on && newDP == 0)
        dig_disp_val[0] &= DP;  //and the value with 0xEF to clear the DP bit
    return STAT_SUCCESS;
}

STATUS_T updateDisp(void)
{
    //Use the switch statement if the 4 digits are not aligned with the low 4 bits of the same IO port
//    switch(dig_idx){
//        case 0:
//            DIG3_OUT = 0;
//            DIG2_OUT = 0;
//            DIG1_OUT = 0;
//            DIG0_OUT = 1;
//            break;
//        case 1:
//            DIG3_OUT = 0;
//            DIG2_OUT = 0;
//            DIG0_OUT = 0;
//            DIG1_OUT = 1;
//            break;
//        case 2:
//            DIG3_OUT = 0;
//            DIG0_OUT = 0;
//            DIG1_OUT = 0;
//            DIG2_OUT = 1;
//            break;
//        case 3:
//            DIG0_OUT = 0;
//            DIG2_OUT = 0;
//            DIG1_OUT = 0;
//            DIG3_OUT = 1;
//            break;
//        default:
//            break;
//    }
    DIGS_OUT &= 0xF0;   //leave high 4 bits untouched, clear 4 low bits
    DIGS_OUT |= 1<<dig_idx;   //set the desired bit
    
    SEGS_OUT = dig_disp_val[dig_idx];
    dig_idx++;
    if(dig_idx >= 4)
        dig_idx = 0;
    return STAT_SUCCESS;
}
#endif