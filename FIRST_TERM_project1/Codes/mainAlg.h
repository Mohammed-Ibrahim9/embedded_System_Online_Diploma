/*
 * mainAlg.h
 *
 *  Created on: Aug 13, 2023
 *      Author: memoz
 */

#ifndef MAINALG_H_
#define MAINALG_H_

#include"state.h"

enum{
	HighPressureDetection
}MainAlg_State_ID;

STATE_define(HighPressureDetection);
extern void (*MainAlg_state)();

#endif /* MAINALG_H_ */
