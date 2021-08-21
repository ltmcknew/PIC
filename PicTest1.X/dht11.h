/* 
 * File:   dht11.h
 * Author: dev-user
 *
 * Created on September 15, 2020, 3:20 PM
 * 
 * Reference project:
 * https://www.circuitbasics.com/how-to-set-up-the-dht11-humidity-sensor-on-the-raspberry-pi/
 */

#ifndef DHT11_H
#define	DHT11_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "StatEnum.h"
#include "PICDEFS.h"
    
#define MAXTIMINGS 85
bool do_dht11_snsr_read;
uint8_t dht11_dat_arr[5];
STATUS_T setup_dht11_snsr(void);
STATUS_T read_dht11_dat(void);



#ifdef	__cplusplus
}
#endif

#endif	/* DHT11_H */

