/*
 * fifo.c
 *
 *  Created on: Aug 4, 2023
 *      Author: memoz
 */
#include "fifo.h"
extern int quit;
static st* search_by_roll (FIFO_Buf_t *FIFO_UART, int troll);

FIFO_Buf_Status FIFO_init (FIFO_Buf_t* fifo, st* buf , uint32_t length)
{
	if(buf == NULL)
		return FIFO_null;
	fifo->base = buf ;
	fifo->head = buf ;
	fifo->tail = buf ;
	fifo->length = length ;
	fifo->count = 0 ;

	return FIFO_no_error;

}
FIFO_Buf_Status FIFO_enqueue (FIFO_Buf_t* fifo, element_type item)
{
	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_null;
	if (FIFO_IS_FULL(fifo)== FIFO_full)
		return FIFO_full;
	*(fifo->head) = item ;
	fifo->count++ ;
	//circular fifo
	if(fifo->head == (fifo->base + (fifo->length * sizeof(element_type))))
		fifo->head = fifo->base;
	else
		fifo->head++;
	return FIFO_no_error;

}
FIFO_Buf_Status FIFO_dequeue (FIFO_Buf_t* fifo, element_type* item)
{
	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_null;
	if(fifo->count == 0)
		return FIFO_empty;
	*item = *(fifo->tail);
	fifo->count-- ;
	if(fifo->tail == (fifo->base + (fifo->length * sizeof(element_type))))
		fifo->tail = fifo->base;
	else
		fifo->tail++;
	return FIFO_no_error;
}
FIFO_Buf_Status FIFO_IS_FULL (FIFO_Buf_t* fifo)
{
	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_null;
	if(fifo->count == fifo->length)
		return FIFO_full;
	return FIFO_no_error;
}
/*void FIFO_print (FIFO_Buf_t* fifo)
{
	element_type* temp;
	int i;
	if(fifo->count == 0)
	{
		DPRINTF("fifo is empty\n");
	}else{
		temp= fifo->tail;
		DPRINTF("\n =========fifo_print===========\n");
		for(i=0 ; i<fifo->count ; i++)
		{
			DPRINTF("\t %X \n",*temp);
			temp++;
		}
		DPRINTF("=========\n");
	}

}*/
void Add_Student_From_File(FIFO_Buf_t *FIFO_UART)
{
	FILE *Student_Data;
	int i;
	st New_Student;

	Student_Data = fopen("Student_Data.txt","r");

	if(Student_Data == NULL)
	{
		DPRINTF("\nAdding Data from file failed. ");
		return;
	}

	while(!feof(Student_Data))
	{
		fscanf(Student_Data, "%d", &New_Student.roll);


		if(search_by_roll (FIFO_UART, New_Student.roll)!=NULL)
		{
			DPRINTF("\nThe Roll number %d is already exist ",New_Student.roll);

			fscanf(Student_Data, "%*[^\n]");
			continue;
		}

		fscanf(Student_Data, "%s", New_Student.fname);
		fscanf(Student_Data, "%s", New_Student.lname);
		fscanf(Student_Data, "%f", &New_Student.GPA);


		for (i = 0; i < course_num; ++i)
		{
			fscanf(Student_Data, "%d", &New_Student.cid[i]);
		}

		if((FIFO_enqueue(FIFO_UART, New_Student))== FIFO_no_error)
		{
			DPRINTF("\n[INFO] Roll Number %d Saved Successfully.\n", New_Student.roll);
			DPRINTF("\n-----------------------");
			DPRINTF("\n[INFO]Total Number of Student is :%d ",FIFO_UART->count);
			DPRINTF("\n[INFO]You can add up to %d students ",student_num);
			DPRINTF("\n[INFO]You can add %d more students ",(student_num-FIFO_UART->count));
		}
		else
		{
			DPRINTF("\nFailed");
			return;
		}
	}

	fclose(Student_Data);
}
void add_student_manually(FIFO_Buf_t *FIFO_UART){
	st new_student;

	int c_nm;
	if(FIFO_UART->count==student_num){
		DPRINTF("\nThe list is full please delete a student");
	}else{

		DPRINTF("\n[INFO]Enter student details");
		DPRINTF("\n-----------------------");
		DPRINTF("\n[INFO] enter roll number of student");
		scanf("%d",&new_student.roll);
		if(search_by_roll (FIFO_UART, new_student.roll)!=NULL)
		{
			DPRINTF("\nThe Roll number %d is already exist ",new_student.roll);
		}else{
			DPRINTF("\nEnter first name");
			scanf("%s",new_student.fname);
			DPRINTF("\nEnter last name");
			scanf("%s",new_student.lname);
			DPRINTF("\nEnter GPA");
			scanf("%f",&new_student.GPA);\
			DPRINTF("\nEnter number of courses you want to Reg.[NOTE]Max:5  ");
			scanf("%d",&c_nm);
			DPRINTF("\nEnter courses IDs. ");
			for(int i=0;i<c_nm;i++){
				DPRINTF("\nCourse ID:");
				scanf(" %d",&new_student.cid[i]);
			}
			if (FIFO_enqueue(FIFO_UART ,new_student)== FIFO_no_error)
			{
				DPRINTF("\n[INFO] Roll Number %d Saved Successfully.\n", new_student.roll);
				DPRINTF("\n-----------------------");
				DPRINTF("\n[INFO]Total Number of Student is :%d ",FIFO_UART->count);
				DPRINTF("\n[INFO]You can add up to %d students ",student_num);
				DPRINTF("\n[INFO]You can add %d more students ",(student_num-FIFO_UART->count));
			}
			else
			{
				DPRINTF("\nFailed ");
			}


		}
	}
}
void find_rl(FIFO_Buf_t *FIFO_UART){

	if (FIFO_UART->count == 0)
	{
		DPRINTF("\nThe List is empty ");
		return;
	}

	st *Student_Temp ;
	int Roll_Temp , j;

	DPRINTF("\nEnter the Roll number You want to search about : ");
	scanf("%d",&Roll_Temp);

	Student_Temp = search_by_roll (FIFO_UART,Roll_Temp);



	if (Student_Temp == NULL)
	{
		DPRINTF("\nThe student with roll number %d is not found ",Roll_Temp);
		return;
	}

	else
	{
		DPRINTF("\nThe student with roll number %d is found :",Roll_Temp);
		DPRINTF("\nFirst Name: %s",Student_Temp->fname);
		DPRINTF("\nLast Name: %s",Student_Temp->lname);
		DPRINTF("\nGPA: %0.2f",Student_Temp->GPA);
		for (j=0 ; j<course_num ; j++)
		{
			DPRINTF("\nCourse ID number %d : %d",j+1,Student_Temp->cid[j]);
		}

	}


}

void find_fn(FIFO_Buf_t *FIFO_UART){
	if (FIFO_UART->count == 0)
	{
		DPRINTF("\nList is empty ");
		return;
	}

	int i ,j ,x, flag=0;
	char Temp_Name[50] ;
	st *student = FIFO_UART->tail;

	DPRINTF("\nEnter the name you want to search about : ");
	scanf("%s",Temp_Name);

	for (i = 0; i< FIFO_UART->count; i++)
	{
		x= stricmp(Temp_Name,student->fname);
		if (x == 0)
		{
			DPRINTF("\nRoll Number: %d",student->roll);
			DPRINTF("\nFirst Name: %s",student->fname);
			DPRINTF("\nLast Name: %s",student->lname);
			DPRINTF("\nGPA: %.2f",student->GPA);
			for (j=0 ; j<course_num ; j++)
			{
				DPRINTF("\nCourse ID number %d : %d",j+1,student->cid[j]);
			}
		}

		else
		{
			flag++;
		}


		if((student + 1) == (FIFO_UART->base + FIFO_UART->length))
		{
			student = FIFO_UART->base;

		}
		else
		{
			student++;
		}
	}

	if (flag == FIFO_UART->count )
	{
		DPRINTF("\nthe name is not found ");
	}
}
void find_c(FIFO_Buf_t *FIFO_UART){
	if (FIFO_UART->count == 0)
	{
		DPRINTF("\nList is empty ");
		return;
	}

	int i ,k, flag=0;
	int Temp_Course ;
	st *student = FIFO_UART->tail;

	DPRINTF("\nEnter the Course ID you want to search about : ");
	scanf("%d",&Temp_Course);

	for (i = 0; i< FIFO_UART->count; i++)
	{
		for(k = 0; k< course_num; k++)
		{
			if (Temp_Course == student->cid[k])
			{
				DPRINTF("\nRoll Number: %d",student->roll);
				DPRINTF("\nFirst Name: %s",student->fname);
				DPRINTF("\nLast Name: %s",student->lname);
				DPRINTF("\nGPA: %0.2f",student->GPA);

			}

			else
			{
				flag++;
			}
		}


		if((student + 1) == (FIFO_UART->base + FIFO_UART->length))
		{
			student = FIFO_UART->base;

		}
		else
		{
			student++;
		}
	}

	if (flag == FIFO_UART->count * course_num  )
	{
		DPRINTF("\nThere is no student in this course ");
	}
}
void tot_s(FIFO_Buf_t *FIFO_UART){
	if (FIFO_UART->count == 0)
	{
		DPRINTF("\nList is empty ");
		return;
	}

	DPRINTF("\n[INFO]Total Number of Student is :%d ",FIFO_UART->count);
	DPRINTF("\n[INFO]You can add up to %d students ",student_num);
	DPRINTF("\n[INFO]You can add %d more students ",(student_num-FIFO_UART->count));
}
void quit_(){
	DPRINTF("\n[INFO]Program has been exit Successfully");
	quit=1;
}
void del_s(FIFO_Buf_t *FIFO_UART){
	st *Temp_Student ;
		int  Temp_Roll;

		DPRINTF("\n=====================");
		DPRINTF("\nDelete student details");
		DPRINTF("\n=====================");

		DPRINTF("\nEnter Roll Number : ");
		scanf("%d",&Temp_Roll);

		Temp_Student = search_by_roll (FIFO_UART,Temp_Roll) ;

		if(Temp_Student==NULL)
		{
			DPRINTF("\nThe Roll number %d is not exist ",Temp_Roll);
			return;
		}


		if (FIFO_dequeue(FIFO_UART ,Temp_Student)== FIFO_no_error)
		{
			DPRINTF("\nDeleted successfully ");
		}
		else
		{
			DPRINTF("\nFailed ");
		}
	}
void up_s(FIFO_Buf_t *FIFO_UART){
	if (FIFO_UART->count == 0)
		{
			DPRINTF("\nList is empty ");
			return;
		}

		st *Student_Temp ;
		int Roll_Temp , i , choice;

		DPRINTF("\nEnter the Roll number You want to Update : ");
		scanf("%d",&Roll_Temp);

		Student_Temp = search_by_roll (FIFO_UART,Roll_Temp);

		if (Student_Temp == NULL)
		{
			DPRINTF("\nThe student with roll number %d is not found ",Roll_Temp);
			return;
		}

		DPRINTF("\nChoose the Data number You want to Update : ");
		DPRINTF("\n\t1- First Name");
		DPRINTF("\n\t2- Last Name");
		DPRINTF("\n\t3- GPA");
		DPRINTF("\n\t4- Courses IDs");
		scanf("%d",&choice);

		switch(choice)
		{
		case 1:
			DPRINTF("\nEnter The new First Name : ");
			scanf("%s",Student_Temp->fname);
			DPRINTF("\nUpdated .. ");
			break;

		case 2:
			DPRINTF("\nEnter The new Last Name : ");
			scanf("%s",Student_Temp->lname);
			DPRINTF("\nUpdated .. ");
			break;

		case 3:
			DPRINTF("\nEnter The new GPA : ");
			scanf("%f",&Student_Temp->GPA);
			DPRINTF("\nUpdated .. ");
			break;

		case 4:
			DPRINTF("\nEnter The new Course IDs : ");
			for (i = 0 ; i<course_num ; i++)
			{
				DPRINTF("\nEnter Course ID number %d : ",i+1);
				scanf("%d",&Student_Temp->cid	[i]);
			}

			DPRINTF("\nUpdated .. ");
			break;

		default:
			DPRINTF("\nWrong Choice");
			break;

		}
	}
void show_s(FIFO_Buf_t *FIFO_UART){
	int i ,j ;


		if (FIFO_UART->count == 0)
		{
			DPRINTF("\nList is empty ");
			return;
		}



		st *student = FIFO_UART->tail;

		for (i = 0; i< FIFO_UART->count; i++)
		{
			DPRINTF("\nRoll Number: %d",student->roll);
			DPRINTF("\nFirst Name: %s",student->fname);
			DPRINTF("\nLast Name: %s",student->lname);
			DPRINTF("\nGPA: %0.2f",student->GPA);
			for (j=0 ; j<course_num ; j++)
			{
				DPRINTF("\nCourse ID number %d : %d",j+1,student->cid[j]);
			}

			if((student + 1) == (FIFO_UART->base + FIFO_UART->length))
			{
				student = FIFO_UART->base;
			}
			else
			{
				student++;
			}
		}

	}
static st* search_by_roll (FIFO_Buf_t *FIFO_UART, int troll)
{
	int i ;

	st *student = FIFO_UART->tail;

	for (i = 0; i< FIFO_UART->count; i++)
	{
		if (student->roll == troll)
		{
			break;
		}

		if((student + 1) == (FIFO_UART->base + FIFO_UART->length))
		{
			student = FIFO_UART->base;
		}
		else
		{
			student++;
		}
	}

	if(i == FIFO_UART->count)
	{
		student = NULL;
	}

	return student;
}
