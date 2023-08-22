/*
 * AlarmMonitor.h
 *
 *  Created on: Aug 13, 2023
 *      Author: memoz
 */

#ifndef ALARMMONITOR_H_
#define ALARMMONITOR_H_

#include"state.h"
extern void (*AlarmMonitor_state)();

enum {
	AlarmON,
	AlarmOFF,
	Waiting
}AlarmMonitor_State_ID;

STATE_define(AlarmOFF);
STATE_define(AlarmON);
STATE_define(Waiting);
#endif /* ALARMMONITOR_H_ */
