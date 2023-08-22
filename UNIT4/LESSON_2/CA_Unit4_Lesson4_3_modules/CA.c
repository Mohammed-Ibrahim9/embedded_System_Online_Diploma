/*
 * CA.c
 *
 *  Created on: Aug 7, 2023
 *      Author: memoz
 */
#include "CA.h"

//variables
int CA_speed = 0;
int CA_distance = 0;
int CA_threshold = 50;

//STATE pointer to function
void (*CA_state)();
void US_Set_distance (int d)
{
	CA_distance = d;
	(CA_distance <= CA_threshold)?(CA_state = STATE(CA_waiting)):(CA_state = STATE(CA_driving));
	printf("US-------distance=%d------->CA\n",CA_distance);
}


STATE_define(CA_waiting)
{
	//state_Name
	CA_state_id = CA_waiting;
	printf("CA_waiting State: distance=%d Speed=%d \n",CA_distance , CA_speed);


	//state_Action
	CA_speed=0;
	DC_motor(CA_speed);
	//DC_motor(CA_speed)

}
STATE_define(CA_driving)
{
	//state_Name
	CA_state_id = CA_driving;
	printf("CA_driving State: distance=%d Speed=%d \n",CA_distance , CA_speed);

	//state_Action
	CA_speed=30;
	DC_motor(CA_speed);
	//DC_motor(CA_speed)

	//event_Check
	//US_Get_Distance(CA_distance)
}
