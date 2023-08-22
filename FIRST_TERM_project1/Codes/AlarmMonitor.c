/*
 * AlarmMonitor.c
 *
 *  Created on: Aug 13, 2023
 *      Author: memoz
 */

#include"AlarmMonitor.h"
int setalarm;

void (*AlarmMonitor_state)();

STATE_define(AlarmOFF){
	AlarmMonitor_State_ID=AlarmOFF;
	if (HighPressureDetected == 0){

		AlarmMonitor_state= STATE(AlarmOFF);
		setalarm=0;
	}
	if (HighPressureDetected == 1){

			STATE(AlarmON)();
		}
}
STATE_define(AlarmON){
	AlarmMonitor_State_ID = AlarmON;
	setalarm=1;
	AlarmMonitor_state= STATE(Waiting);


}
STATE_define(Waiting){
	AlarmMonitor_State_ID=Waiting;
	Delay(60);
	setalarm=0;
	AlarmMonitor_state= STATE(AlarmOFF);
}

