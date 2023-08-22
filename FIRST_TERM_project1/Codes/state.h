/*
 * state.h
 *
 *  Created on: Aug 8, 2023
 *      Author: memoz
 */

#ifndef STATE_H_
#define STATE_H_
#include "stdlib.h"
#include "stdio.h"
#include "driver.h"
/*Automatic State Function genrated*/
#define STATE_define(_statFUN_) void ST_##_statFUN_()
#define STATE(_statFUN_) ST_##_statFUN_


/*States Connection*/
extern int pVal;
extern int HighPressureDetected;
extern int setalarm;
#endif /* STATE_H_ */
