/*
 * options.c
 *
 *  Created on: Aug 5, 2023
 *      Author: memoz
 */

#include "options.h"

//effective data
struct Sdata
{
	int ID;
	char name[40];
	float height;
};

//linked list node
struct SStudent
{
	struct Sdata student;
	struct SStudent* PNextStudent;

};

struct SStudent* gpFirstStudent= NULL ;

void AddStudent()
{
	struct SStudent* pNewStudent;
	struct SStudent* pLastStudent;
	char temp_text[40];
	//check list is empty == yes
	if(gpFirstStudent == NULL)
	{
		//create new record
		pNewStudent =(struct SStudent*) malloc(sizeof(struct SStudent));
		//assign it to gpfirst
		gpFirstStudent = pNewStudent;
	}else //list contains records
	{
		//navigate until reach to the last record
		pLastStudent = gpFirstStudent;
		while(pLastStudent->PNextStudent)
			pLastStudent = pLastStudent->PNextStudent;
		//create new record
		pNewStudent =(struct SStudent*) malloc(sizeof(struct SStudent));
		pLastStudent->PNextStudent = pNewStudent;
	}
	//fill new record
	DPRINTF("\n Enter the ID: ");
	gets (temp_text);
	pNewStudent->student.ID = atoi(temp_text);

	DPRINTF("\n Enter student full name : ");
	gets (pNewStudent->student.name);

	DPRINTF("\n Enter the height: ");
	gets (temp_text);
	pNewStudent->student.height = atof(temp_text);

	//set the next pointer (new_student) null
	pNewStudent->PNextStudent = NULL ;
}

int delete_student()
{
	char temp_text[40];
	unsigned int selected_id;

	//get selected id
	DPRINTF("\n enter the student id to deleted :");
	gets(temp_text);
	selected_id = atoi(temp_text);

	//list is not empty
	if(gpFirstStudent)
	{
		struct SStudent* pSelectedStudent = gpFirstStudent;
		struct SStudent* pPreviousStudent = NULL;
		//Loop on all records
		while(pSelectedStudent)
		{
			if(pSelectedStudent->student.ID == selected_id)
			{
				if(pPreviousStudent)//the first is not selected ID
				{
					pPreviousStudent->PNextStudent = pSelectedStudent->PNextStudent;

				}else //1st student == ID
				{
					gpFirstStudent = pSelectedStudent->PNextStudent;
				}
				free(pSelectedStudent);
				return 1;
			}
			pPreviousStudent = pSelectedStudent;
			pSelectedStudent = pSelectedStudent->PNextStudent;
		}

	}
	DPRINTF("\n cannot find student ID");
	return 0;
}

void view_students()
{
	struct SStudent* pCurrentStudent = gpFirstStudent;
	int count =0;
	if(gpFirstStudent == NULL)
	{
		DPRINTF("\n Empty List");
	}else
	{
		while(pCurrentStudent)
		{
			DPRINTF("\n record number %d ", count+1);
			DPRINTF("\n \t ID: %d",pCurrentStudent->student.ID);
			DPRINTF("\n \t Name: %s",pCurrentStudent->student.name);
			DPRINTF("\n \t height: %.2f",pCurrentStudent->student.height);
			pCurrentStudent = pCurrentStudent->PNextStudent;
			count++;
		}
	}
}

void DeleteAll(){
	struct SStudent* pCurrentStudent = gpFirstStudent;
	if(gpFirstStudent == NULL)
	{
		DPRINTF("\n Empty List");
	}else
	{
		while(pCurrentStudent)
		{
			struct SStudent* pTempStudent = pCurrentStudent;
			pCurrentStudent = pCurrentStudent->PNextStudent;
			free(pTempStudent);
		}
		gpFirstStudent = NULL;
	}
}

int GetNth()
{
	struct SStudent* pCurrentStudent = gpFirstStudent;
	int count=0;
	int selected_index;
	DPRINTF("\n Enter which index you need starts from 0: ")
	scanf("%d",&selected_index);
	while(pCurrentStudent)
	{
		if(count == selected_index)
		{
			DPRINTF("\n index number %d ", selected_index);
			DPRINTF("\n \t ID: %d",pCurrentStudent->student.ID);
			DPRINTF("\n \t Name: %s",pCurrentStudent->student.name);
			DPRINTF("\n \t height: %.2f",pCurrentStudent->student.height);
			return 1;
		}else{
			pCurrentStudent = pCurrentStudent->PNextStudent;
			count++;
		}
	}
	DPRINTF("\n this index not found");
	return 0;
}

void GetCount()
{
	struct SStudent* pCurrentStudent = gpFirstStudent;
	int count=0;
	while(pCurrentStudent){
		++count;
		pCurrentStudent = pCurrentStudent->PNextStudent;
	}
	if(count == 0)
	{
		DPRINTF("\n The list is empty");
	}else{
		DPRINTF("\n The list contains %d students", count);
	}

}

void GetNthFromEnd()
{
	struct SStudent* main_ptr_Student = gpFirstStudent;
	struct SStudent* ref_ptr_Student = gpFirstStudent;
	struct SStudent* pCountStudent = gpFirstStudent;
	int selected_node, count=0,temp_count=0;
	DPRINTF("\n Enter selected node from end do you want to see: ");
	scanf("%d",&selected_node);
	while(pCountStudent)
	{
		pCountStudent=pCountStudent->PNextStudent;
		++temp_count;

	}
	if(selected_node>temp_count){
		DPRINTF("this selected node exceed the number of nodes");
	}else{
		while (selected_node != count)
		{
			ref_ptr_Student = ref_ptr_Student->PNextStudent;
			++count;
		}
		while(ref_ptr_Student)
		{
			main_ptr_Student=main_ptr_Student->PNextStudent;
			ref_ptr_Student=ref_ptr_Student->PNextStudent;
		}
		DPRINTF("\n the selected node from end is: %d ", selected_node);
		DPRINTF("\n \t ID: %d",main_ptr_Student->student.ID);
		DPRINTF("\n \t Name: %s",main_ptr_Student->student.name);
		DPRINTF("\n \t height: %.2f",main_ptr_Student->student.height);
	}

}

void midoflist(){
	struct SStudent* fast_ptr_Student = gpFirstStudent;
	struct SStudent* slow_ptr_Student = gpFirstStudent;
	while(fast_ptr_Student->PNextStudent){
		fast_ptr_Student=fast_ptr_Student->PNextStudent->PNextStudent;
		slow_ptr_Student=slow_ptr_Student->PNextStudent;
	}
	DPRINTF("\n the student data in mid of list is");
	DPRINTF("\n \t ID: %d",slow_ptr_Student->student.ID);
	DPRINTF("\n \t Name: %s",slow_ptr_Student->student.name);
	DPRINTF("\n \t height: %.2f",slow_ptr_Student->student.height);
}
void reverselist()
{
	struct SStudent* pCurrentStudent = gpFirstStudent;
	struct SStudent* pPrevStudent = NULL;
	struct SStudent* pNextStudent = NULL;
	while(pCurrentStudent){
		pNextStudent=pCurrentStudent->PNextStudent;
		pCurrentStudent->PNextStudent = pPrevStudent;
		pPrevStudent = pCurrentStudent;
		pCurrentStudent=pNextStudent;
	}
	gpFirstStudent= pPrevStudent;
}

