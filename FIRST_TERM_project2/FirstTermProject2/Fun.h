/*
 * Fun.h
 *
 *  Created on: Aug 14, 2023
 *      Author: memoz
 */

#ifndef FUN_H_
#define FUN_H_
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define DPRINTF(...) {fflush(stdout);\
		fflush(stdin);\
		printf(__VA_ARGS__);\
		fflush(stdout);\
		fflush(stdin);}

struct sinfo{
	char fname[50];
	char lname[50];
	int roll;
	float GPA;
	int cid[5];
}st[55];



void add_student_file(); //add student by file
void add_student_manually(); //add student manually
void find_rl(); //find student by roll number
void find_fn(); //find student by first name
void find_c(); //find students by course id
void tot_s(); // find total number of student
void del_s(); // to delete student
void up_s(); //to update student data
void show_s(); // show all information
void quit_();

#endif /* FUN_H_ */
