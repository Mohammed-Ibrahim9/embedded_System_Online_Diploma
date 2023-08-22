/*
 * AlarmActuator.c
 *
 *  Created on: Aug 13, 2023
 *      Author: memoz
 */
#include "AlarmActuator.h"

void (*AlarmActuator_state)();

void AlarmActuator_init(){

}

STATE_define(Wait){
	if(setalarm==0){
		STATE(Alarm_OFF)();
	}
	if(setalarm==1){
		STATE(Alarm_ON)();
	}
}

STATE_define(Alarm_ON){
	Set_Alarm_actuator(0);
	AlarmActuator_state=STATE(Wait);
}
STATE_define(Alarm_OFF){
	Set_Alarm_actuator(1);
	AlarmActuator_state=STATE(Wait);
}
