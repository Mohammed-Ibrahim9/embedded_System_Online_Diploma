/*
 * fifo.h
 *
 *  Created on: Aug 4, 2023
 *      Author: memoz
 */

#ifndef FIFO_H_
#define FIFO_H_

#include "stdio.h"
#include "stdint.h"
#include "string.h"
#define DPRINTF(...) {fflush(stdout);\
		fflush(stdin);\
		printf(__VA_ARGS__);\
		fflush(stdout);\
		fflush(stdin);}


//USER Configuration
//select element type (uint8_t, uint26_t, uint32_t, ......)
#define element_type st
#define student_num 50
#define course_num 5
//create buffer 1
//#define width1 5
//element_type uart_buffer[width1];
typedef struct{
	char fname[50];
	char lname[50];
	int roll;
	float GPA;
	int cid[course_num];
}st;

//FIFO data types
typedef struct{
	unsigned int length;
	unsigned int count;
	element_type* base;
	element_type* head;
	element_type* tail;
}FIFO_Buf_t;

typedef enum{
	FIFO_no_error,
	FIFO_full,
	FIFO_empty,
	FIFO_null
}FIFO_Buf_Status;


//APIs
FIFO_Buf_Status FIFO_init (FIFO_Buf_t* fifo, st* buf , uint32_t length);
FIFO_Buf_Status FIFO_enqueue (FIFO_Buf_t* fifo, element_type item);
FIFO_Buf_Status FIFO_dequeue (FIFO_Buf_t* fifo, element_type* item);
FIFO_Buf_Status FIFO_IS_FULL (FIFO_Buf_t* fifo);
//void FIFO_print (FIFO_Buf_t* fifo);
void Add_Student_From_File(FIFO_Buf_t *FIFO_UART); //add student by file
void add_student_manually(FIFO_Buf_t *FIFO_UART); //add student manually
void find_rl(FIFO_Buf_t *FIFO_UART); //find student by roll number
void find_fn(FIFO_Buf_t *FIFO_UART); //find student by first name
void find_c(FIFO_Buf_t *FIFO_UART); //find students by course id
void tot_s(FIFO_Buf_t *FIFO_UART); // find total number of student
void del_s(FIFO_Buf_t *FIFO_UART); // to delete student
void up_s(FIFO_Buf_t *FIFO_UART); //to update student data
void show_s(FIFO_Buf_t *FIFO_UART); // show all information
void quit_();

#endif /* FIFO_H_ */
