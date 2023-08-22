/*
 * main.c
 *
 *  Created on: Aug 4, 2023
 *      Author: memoz
 */

#include "fifo.h"
void main()
{
	FIFO_Buf_t FIFO_UART;
	element_type i , temp=0;
	if(FIFO_init(&FIFO_UART , uart_buffer ,5)== FIFO_no_error)
		printf("fifo init--------->Done\n");

	for(i=0; i<7 ; i++)
	{
		printf("FIFO Enqueue(%x) \n",i);
		if(FIFO_enqueue(&FIFO_UART ,i)== FIFO_no_error)
			printf("fifo enqueue--------->Done\n");
		else
			printf("fifo enqueue--------->failed\n");
	}

	FIFO_print(&FIFO_UART);
	if(FIFO_dequeue(&FIFO_UART ,&temp)== FIFO_no_error)
		printf("fifo dequeue (%x) --------->Done\n",temp);
	if(FIFO_dequeue(&FIFO_UART ,&temp)== FIFO_no_error)
		printf("fifo dequeue (%x) --------->Done\n",temp);
	FIFO_print(&FIFO_UART);
}
