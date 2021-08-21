#include "dht11.h"

STATUS_T setup_dht11_snsr(void)
{
    //SNSR_TnH_X Maps to GPIO RD6, Init as output with initial value (Pin 29)
    //This will be the data connection to the DHT11 Temp & Humidity Sensor
    SNSR_TnH_OUT = 1;
    SNSR_TnH_TRIS = 0;
    
    do_dht11_snsr_read = false;
    dht11_dat_arr[0] = dht11_dat_arr[1] = dht11_dat_arr[2] = dht11_dat_arr[3] = dht11_dat_arr[4] = 0;
    
    return STAT_SUCCESS;
}

STATUS_T read_dht11_dat(void)
{
    uint8_t laststate = 1;  //HIGH
    uint8_t counter = 0;
    uint8_t j = 0, i;
    STATUS_T run_stat = STAT_FAIL;
    
    for(i = 0; i < 5; i++)
        dht11_dat_arr[i] = 0;
    
    //Make it an output and drive low for 18(ms)
    SNSR_TnH_OUT = 0;
    SNSR_TnH_TRIS = 0;
    __delay_ms(18);
    //Then drive high
    SNSR_TnH_OUT = 1;
    //After another 40us make it an input
    __delay_us(40);
    
    GIE = 0;
    SNSR_TnH_TRIS = 1;    
    //The sensor will hold the line high longer for 1's and shorter for 0's. Ignore the first 4 edges then begin clocking in every other edge as a 1 or 0 depending on the high time of the pin
    for(i = 0; i < MAXTIMINGS; i++){
        counter = 0;
        while(SNSR_TnH_IN == laststate){    //wait for change in bit state
            counter++;
//            __delay_us(1);                //since the pic is so slow this loop is taking much more than 1us for each iteration
            if(counter == 255){             //timeout if state doesn't change in 255us
                break;
            }
        }
        laststate = SNSR_TnH_IN;            //record current state for next loop
        
        if(counter == 255){                 //if timed out then this acq is done
            break;   
        }

        if((i>=4) && (i%2 == 0)){           //wait until the 5th edge and only capture on every other edge from here on out
            dht11_dat_arr[j>>3] <<= 1;      //shift the lowest bit up one to maintain previously captured bits, since data initialized to 0 this can be done on the first one 
            if(counter > 14){                //empirically determined to work, ideally the on time for a 1 should be >16us and for a 0 <=16us
                dht11_dat_arr[j>>3] |= 1;   //if the state took >16us then the next bit is a 1 other wise it's a zero
            }
            j++;
        }
    }
    GIE = 1;
    
    if((j>=40) && 
            dht11_dat_arr[4] == ( (dht11_dat_arr[0] + dht11_dat_arr[1] + dht11_dat_arr[2] + dht11_dat_arr[3]) & 0xFF ) )
    {        
        run_stat = STAT_SUCCESS;
    }
    
    SNSR_TnH_OUT = 1;
    SNSR_TnH_TRIS = 0;
    
    return run_stat;
}