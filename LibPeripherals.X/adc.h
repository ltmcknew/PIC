/* 
 * File:   adc.h
 * Author: dev-user
 *
 * Created on September 25, 2020, 2:13 PM
 */

#ifndef ADC_H
#define	ADC_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "../IncSystemDefs/PICDEFS.h"

#ifdef __USE_ADC__
uint8_t ADCBitPos;
uint8_t ADCAcqCnt;
STATUS_T SetupADC();
uint16_t adc_measure(uint8_t adcChannel);
#endif


#ifdef	__cplusplus
}
#endif

#endif	/* ADC_H */

