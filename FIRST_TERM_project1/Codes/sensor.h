/*
 * sensor.h
 *
 *  Created on: Aug 13, 2023
 *      Author: memoz
 */

#ifndef SENSOR_H_
#define SENSOR_H_
#include "state.h"

enum{
	Sensor_Reading,
	Sensor_Waiting
}Sesnor_State_ID;

STATE_define(Sensor_Reading);
STATE_define(Sensor_Waiting);

void Sensor_init();
extern void (*Sensor_state)();

#endif /* SENSOR_H_ */
