#include "ir_dist.h"

#ifdef __USE_IRDIST__
STATUS_T setup_irdist_snsr(bool use_extint)
{
    IRDIST_TRIS = 1;    //make the sensor pin an input, it's connected to RB0 which can support the EXTINT mode
    
    do_irdist_snsr_read = false;
    
    if(use_extint){ //setup external interrupt on gpio input signal
        INTPPS = IRDIST_PPS_VAL;    //configure the pin for external interrupt mode
        INTCONbits.INTEDG = 0;      //falling edge of pin triggers interrupt
        PIE0bits.INTE = 1;
    }
    
    return STAT_SUCCESS;
}

STATUS_T read_irdist_dat(void)
{
    irdist_result = !IRDIST_IN; //Low in = Detection, High in = nothing
    
    return STAT_SUCCESS;
}
#endif