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

//Automatic State Function genrated
#define STATE_define(_statFUN_) void ST_##_statFUN_()
#define STATE(_statFUN_) ST_##_statFUN_


//States Connection
void US_Set_distance (int d);
void DC_motor(int s);
#endif /* STATE_H_ */
