/*
 * CA.c
 *
 *  Created on: Aug 7, 2023
 *      Author: memoz
 */
#include "CA.h"

int US_Get_Distance_random (int l,int r, int count);
//variables
int CA_speed = 0;
int CA_distance = 0;
int CA_threshold = 50;

//STATE pointer to function
void (*CA_state)();

STATE_define(CA_waiting)
{
	//state_Name
	CA_state_id = CA_waiting;

	//state_Action
	CA_speed=0;
	//DC_motor(CA_speed)

	//event_Check
	//US_Get_Distance(CA_distance)
	CA_distance = US_Get_Distance_random(45 , 55 , 1);
	(CA_distance <= CA_threshold)?(CA_state = STATE(CA_waiting)):(CA_state = STATE(CA_driving));
	printf("CA_waiting State: distance=%d Speed=%d \n",CA_distance , CA_speed);
}
STATE_define(CA_driving)
{
	//state_Name
		CA_state_id = CA_driving;

		//state_Action
		CA_speed=30;
		//DC_motor(CA_speed)

		//event_Check
		//US_Get_Distance(CA_distance)
		CA_distance = US_Get_Distance_random(45 , 55 , 1);
		(CA_distance <= CA_threshold)?(CA_state = STATE(CA_waiting)):(CA_state = STATE(CA_driving));
		printf("CA_driving State: distance=%d Speed=%d \n",CA_distance , CA_speed);
}


int US_Get_Distance_random (int l,int r, int count)
{
	//Generate random numbers
	int i ;
	int rand_num;
	for (i = 0; i < count; i++){
		rand_num = (rand() % (r-1+1)) + 1;

	}
	return rand_num;
}
