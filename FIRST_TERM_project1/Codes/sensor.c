/*
 * sensor.c
 *
 *  Created on: Aug 13, 2023
 *      Author: memoz
 */
#include "sensor.h"
#include "driver.h"

void (*Sensor_state)();
int pVal;

void Sensor_init()
{

}

STATE_define(Sensor_Reading){

	Sesnor_State_ID = Sensor_Reading;
	pVal = getPressureVal();


	Sensor_state = STATE(Sensor_Waiting);
}

STATE_define(Sensor_Waiting){

	Sesnor_State_ID = Sensor_Waiting;
	
	Delay(100);

	Sensor_state = STATE(Sensor_Reading);

}


