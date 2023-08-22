/*
 * main.c
 *
 *  Created on: Aug 13, 2023
 *      Author: memoz
 */
#include "AlarmMonitor.h"
#include "mainAlg.h"
#include "sensor.h"
#include "AlarmActuator.h"


void setup(){

	GPIO_INITIALIZATION(); 
	AlarmActuator_init();
	Sensor_init();

	Sensor_state = STATE(Sensor_Reading);
	MainAlg_state = STATE(HighPressureDetection);
	AlarmMonitor_state= STATE(AlarmOFF);
	AlarmActuator_state=STATE(Wait);

}

void main()
{
	setup();
	GPIO_INITIALIZATION();
	while(1){
	Sensor_state();
	MainAlg_state();
	AlarmMonitor_state();
	AlarmActuator_state();
	}

}
