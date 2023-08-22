/*
 * US.h
 *
 *  Created on: Aug 7, 2023
 *      Author: memoz
 */

#ifndef US_H_
#define US_H_
#include "state.h"

//Define States
enum{
	US_busy
}US_state_id;

//declare states fuctions US
STATE_define(US_busy);

void US_init();
//STATE pointer to function
extern void (*US_state)();

#endif /* US_H_ */
