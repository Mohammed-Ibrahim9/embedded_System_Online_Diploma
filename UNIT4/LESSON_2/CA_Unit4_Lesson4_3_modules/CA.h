/*
 * CA.h
 *
 *  Created on: Aug 7, 2023
 *      Author: memoz
 */

#ifndef CA_H_
#define CA_H_
#include "state.h"

//Define States
enum{
	CA_waiting,
	CA_driving
}CA_state_id;

//declare states fuctions CA
STATE_define(CA_waiting);
STATE_define(CA_driving);

//STATE pointer to function
extern void (*CA_state)();

#endif /* CA_H_ */
