/*
 * AlarmActuator.h
 *
 *  Created on: Aug 13, 2023
 *      Author: memoz
 */

#ifndef ALARMACTUATOR_H_
#define ALARMACTUATOR_H_
#include "state.h"

enum{
	Wait,
	ON,
	OFF
}AlarmActuator_State_ID;

STATE_define(Wait);
STATE_define(Alarm_ON);
STATE_define(Alarm_OFF);
void AlarmActuator_init();
extern void (*AlarmActuator_state)();

#endif /* ALARMACTUATOR_H_ */
