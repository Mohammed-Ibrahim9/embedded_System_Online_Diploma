/*
 * main.c
 *
 *  Created on: Aug 7, 2023
 *      Author: memoz
 */

#include "CA.h"

void setup()
{
	//init all the drivers
	//init IRQ...
	//init HAL US_Driver DC_Driver
	//init BLOCK
	//Set States pointers for each block
	CA_state = STATE(CA_waiting);

}
void main()
{
	volatile int d;

	setup();

	while(1)
	{
		//call state for each block
		CA_state();
		//delay
		for(d=0 ; d<=1000;d++);
	}
}
