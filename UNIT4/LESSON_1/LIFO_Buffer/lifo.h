/*
 * LIFO.h
 *
 *  Created on: Aug 3, 2023
 *      Author: memoz
 */

#ifndef LIFO_H_
#define LIFO_H_
#include "stdio.h"
#include "stdlib.h"

//type definitions
typedef struct LIFO_Buf{
	unsigned int length;
	unsigned int count;
	unsigned int* base;
	unsigned int* head;
}LIFO_Buf_t;

typedef enum{
	LIFO_no_error,
	LIFO_full,
	LIFO_empty,
	LIFO_Null
}LIFO_status;

//APIs
LIFO_status LIFO_Add_item(LIFO_Buf_t* lifo_buf , unsigned int item);
LIFO_status LIFO_get_item(LIFO_Buf_t* lifo_buf , unsigned int* item);
LIFO_status LIFO_init(LIFO_Buf_t* lifo_buf , unsigned int* buf , unsigned int length);


#endif /* LIFO_H_ */
