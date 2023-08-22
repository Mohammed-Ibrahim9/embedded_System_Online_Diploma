/*
 * main.c
 *
 *  Created on: Aug 4, 2023
 *      Author: memoz
 */

#include "fifo.h"
int quit;

void main()
{
	FIFO_Buf_t FIFO_UART;
	element_type student[student_num];

	FIFO_init(&FIFO_UART,student, student_num);

	int choice;

	DPRINTF("\nWelcome to Student Management System");
	while(!quit){
		DPRINTF("\n-----------------------");
		DPRINTF("\nChoose The Task that you want to perform");
		DPRINTF("\n1. Add The Student Details Manually");
		DPRINTF("\n2. Add The Student Details From Text File");
		DPRINTF("\n3. Find The Student Details by Roll Number");
		DPRINTF("\n4. Find The Student Details by First Name");
		DPRINTF("\n5. Find The Student Details by Course ID");
		DPRINTF("\n6. Find Total number of Students");
		DPRINTF("\n7. Delete The Student Details by Roll Number");
		DPRINTF("\n8. Update The Student Details by Roll Number");
		DPRINTF("\n9. Show all information");
		DPRINTF("\n10. To Exit");
		DPRINTF("\nEnter your choice to perform a task ")
		scanf("%d",&choice);
		DPRINTF("\n-----------------------");
		switch(choice){
		case 1:
			add_student_manually(&FIFO_UART);
			break;
		case 2:
			Add_Student_From_File(&FIFO_UART);
			break;
		case 3:
			find_rl(&FIFO_UART);
			break;
		case 4:
			find_fn(&FIFO_UART);
			break;
		case 5:
			find_c(&FIFO_UART);
			break;
		case 6:
			tot_s(&FIFO_UART);
			break;
		case 7:
			del_s(&FIFO_UART);
			break;
		case 8:
			up_s(&FIFO_UART);
			break;
		case 9:
			show_s(&FIFO_UART);
			break;
		case 10:
			quit_();
			break;
		default:
			DPRINTF("\n[ERROR]You entered invalid choice please try again ");
		}
	}
}
