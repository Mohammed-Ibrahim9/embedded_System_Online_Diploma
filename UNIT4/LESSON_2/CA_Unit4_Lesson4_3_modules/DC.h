/*
 * DC.h
 *
 *  Created on: Aug 7, 2023
 *      Author: memoz
 */

#ifndef DC_H_
#define DC_H_
#include "state.h"

//Define States
enum{
	DC_idle,
	DC_busy
}DC_state_id;

//declare states fuctions DC
STATE_define(DC_idle);
STATE_define(DC_busy);

void DC_init();

//STATE pointer to function
extern void (*DC_state)();

#endif /* DC_H_ */
