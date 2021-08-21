/* 
 * File:   ir_dist.h
 * Author: dev-user
 *
 * Created on September 15, 2020, 3:47 PM
 */

#ifndef IR_DIST_H
#define	IR_DIST_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "../IncSystemDefs/PICDEFS.h"

#ifdef __USE_IRDIST__    
bool do_irdist_snsr_read;
bool irdist_result;
STATUS_T setup_irdist_snsr(bool use_extint);
STATUS_T read_irdist_dat(void);
#endif


#ifdef	__cplusplus
}
#endif

#endif	/* IR_DIST_H */

