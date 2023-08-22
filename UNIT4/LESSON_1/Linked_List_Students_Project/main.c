/*
 * main.c
 *
 *  Created on: Aug 5, 2023
 *      Author: memoz
 */


/*
 * main.c
 *
 *  Created on: Aug 4, 2023
 *      Author: memoz
 */
#include "options.h"

void main()
{
	int temp_text;
	while(1)
	{
		DPRINTF("\n ===============");
		DPRINTF("\n\t Choose on of the following Options \n");
		DPRINTF("\n 1: Add Student ");
		DPRINTF("\n 2: Delete_Student ");
		DPRINTF("\n 3: view_students ");
		DPRINTF("\n 4: DeleteAll ");
		DPRINTF("\n 5: Find specific index ");
		DPRINTF("\n 6: Find the length of list ");
		DPRINTF("\n 7: Find a node from end ");
		DPRINTF("\n 8: Find data in mid of list ");
		DPRINTF("\n 9: To reverse student list ");
		DPRINTF("\n Enter Option Number: ");

		scanf("%d",&temp_text);
		DPRINTF("\n ===============");

		switch(temp_text)
		{
		case 1:
			AddStudent();
			break;
		case 2:
			delete_student();
			break;
		case 3:
			view_students();
			break;
		case 4:
			DeleteAll();
			break;
		case 5:
			GetNth();
			break;
		case 6:
			GetCount();
			break;
		case 7:
			GetNthFromEnd();
			break;
		case 8:
			midoflist();
			break;
		case 9:
			reverselist();
			break;
		default:
			DPRINTF("\n wrong option");
			break;
		}


	}
}
