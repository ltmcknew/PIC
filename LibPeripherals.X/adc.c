#include "adc.h"

#ifdef __USE_ADC__
STATUS_T SetupADC()
{
    //Config the Port, set the TRIS bit, and make pin analog)
    ADCTRIS |= ADCBitPos;
    ADCANSEL |= ADCBitPos;
    
    //Config ADC Module, select clock, config vrefs, 
    ADCON0bits.ADON = 0;    //disable the module for configuration
    
    ADCON0bits.ADCONT = 0;  //one-shot mode (not continuously triggering)
    ADCON0bits.ADCS = 0;    //Fosc/ADCLK supplies clock
    ADCON0bits.ADFRM = 1;   //Right align the result register
    
    ADCON1bits.ADDSEN = 0;  //One conversion per trigger
    ADCON1bits.ADGPOL = 0;  //pulls pin low during precharge
    ADCON1bits.ADPPOL = 0;  //ignored when ADPRE == 0x00
    ADPRE = 0;
    
    ADCON2bits.ADPSIS = 0;  //load ADRES to ADPREV at start of conversion
    ADCON2bits.ADMD = 0b000;    //Basic mode, one shot, no calculations
    ADCON2bits.ADACLR = 1;  //Clear ADACC, ADAOV and sample counter
    
    ADCON3bits.ADTMD = 0b000;   //Disable Threshold Input Mode
    
    ADCLK = 0b111111;       //ADCLK is Fosc/128, recommended for 32MHz system clock
    
    ADREFbits.ADPREF = 0b00;    //Vref Plus is VDD
    ADREFbits.ADNREF = 0b00;    //Vref Minus is VSS
    
    ADCAP = 0;              //No additional capacitance on the sample line
    
    ADACT = 0x00;           //External trigger for ADC conversion disabled
    
    return STAT_SUCCESS;
}

uint16_t adc_measure(uint8_t adcChannel)
{
    
    //set adc input channel, turn on adc module
    ADPCH = adcChannel;
    ADON = 1;
        
    //wait acquisition time
    __delay_us(5);  //should be enough for an input resistance of 10K up to 50C
    
    //Start Conversion by setting ADGO
    ADACQ = ADCAcqCnt;
    ADGO = 1;
    
    //wait for conv to complete
    while(!ADGO) continue;   //this should take 11.5x the Acquisition Clock (Set to Fosc/128 above, results in ~46us)
    
    //Read Result    
    uint16_t res = ADRES;
    
    ADON = 0;
    
    return res;
}
#endif