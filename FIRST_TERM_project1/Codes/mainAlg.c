/*
 * mainAlg.c
 *
 *  Created on: Aug 13, 2023
 *      Author: memoz
 */

#include "mainAlg.h"

int HighPressureDetected;
void (*MainAlg_state)();

STATE_define(HighPressureDetection){
	MainAlg_State_ID=HighPressureDetection;
	volatile int threshold;
	threshold = 20;

	if(pVal <= threshold){
		HighPressureDetected=0;
		MainAlg_state = STATE(HighPressureDetection);
	}
	if(pVal > threshold){
		HighPressureDetected=1;
		MainAlg_state = STATE(HighPressureDetection);

	}

}
