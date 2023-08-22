/*
 * options.h
 *
 *  Created on: Aug 5, 2023
 *      Author: memoz
 */

#ifndef OPTIONS_H_
#define OPTIONS_H_
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"

#define DPRINTF(...) {fflush(stdout);\
		fflush(stdin);\
		printf(__VA_ARGS__);\
		fflush(stdout);\
		fflush(stdin);}

void AddStudent();
int delete_student();
void view_students();
void DeleteAll();
int GetNth();
void GetCount();
void GetNthFromEnd();
void midoflist();
void reverselist();

#endif /* OPTIONS_H_ */
