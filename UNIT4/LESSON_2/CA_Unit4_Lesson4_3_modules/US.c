/*
 * US.c
 *
 *  Created on: Aug 7, 2023
 *      Author: memoz
 */
#include "US.h"

int US_Get_Distance_random (int l,int r, int count);
//variables
int US_distance = 0;

//STATE pointer to function
void (*US_state)();

void US_init()
{
	//init US Driver
	printf("US_init\n");
}

STATE_define(US_busy)
{
	//state_Name
	US_state_id = US_busy;

	//state_Action

	//event_Check
	//US_Get_Distance(US_distance)
	US_distance = US_Get_Distance_random(45 , 55 , 1);
	printf("US_waiting State: distance=%d \n",US_distance );
	US_Set_distance(US_distance);
	US_state = STATE(US_busy);
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
