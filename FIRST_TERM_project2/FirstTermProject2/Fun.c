/*
 * Fun.c
 *
 *  Created on: Aug 14, 2023
 *      Author: memoz
 */
#include "Fun.h"
extern int st_count;
extern int quit;

void add_student_file(){
	FILE *file;
	char filename[] = "StudentData.txt";
	struct sinfo new_student;
	if(st_count==50){
		DPRINTF("\nThe list is full please delete a student");
	}else{

		// Open the file for reading
		file = fopen(filename,"r");
		if (file == NULL) {
			DPRINTF("\n[ERROR] This File Doesn't exist");
		}

		while(!feof(file)) {

			fscanf(file, "%d", &new_student.roll);
			int is_duplicate = 0;

			// Check for duplicate ID within the array
			for (int i = 0; i < st_count; i++) {
				if (st[i].roll == new_student.roll) {
					DPRINTF("\n[ERROR] Duplicate Roll Number %d found. Skipping.\n", new_student.roll);
					is_duplicate = 1;
					break;
				}
			}
			if(is_duplicate){
				fscanf(file, "%*[^\n]");
				continue;
			}else{

				// If not a duplicate, add the student to the array
				fscanf(file, "%s", new_student.fname);
				fscanf(file, "%s", new_student.lname);
				fscanf(file, "%f", &new_student.GPA);


				for (int i = 0; i < 5; ++i)
				{
					fscanf(file, "%d", &new_student.cid[i]);
				}
				st[st_count] = new_student;
				DPRINTF("\n[INFO] Roll Number %d Saved Successfully.\n", new_student.roll);
				st_count++;
			}
		}
		DPRINTF("\n-----------------------");
		DPRINTF("\n[INFO]Total Number of Student is :%d ",st_count);
		DPRINTF("\n[INFO]You can add up to 50 students ");
		DPRINTF("\n[INFO]You can add %d more students ",50-st_count);
	}
}
void add_student_manually(){
	struct sinfo new_student;
	int is_duplicate = 0;
	int c_nm;
	if(st_count==50){
		DPRINTF("\nThe list is full please delete a student");
	}else{
		while(1){
			DPRINTF("\n[INFO]Enter student details");
			DPRINTF("\n-----------------------");
			DPRINTF("\n[INFO] enter roll number of student");
			scanf("%d",&new_student.roll);
			for (int i = 0; i < st_count; i++) {
				if (st[i].roll == new_student.roll) {
					DPRINTF("\n[ERROR] Roll Number %d is already exist Please choose another one.\n", new_student.roll);
					is_duplicate = 1;
					break;
				}
			}
			if(is_duplicate)
				continue;
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
			st[st_count] = new_student;
			st_count++;
			DPRINTF("\n[INFO] Roll Number %d Saved Successfully.\n", new_student.roll);
			DPRINTF("\n-----------------------");
			DPRINTF("\n[INFO]Total Number of Student is :%d ",st_count);
			DPRINTF("\n[INFO]You can add up to 50 students ");
			DPRINTF("\n[INFO]You can add %d more students ",50-st_count);

			break;

		}
	}
}
void find_rl(){
	int rl;
	int i;
	DPRINTF("\nEnter roll number of student you want to find:");
	scanf("%d",&rl);
	for (i = 0; i < st_count; i++) {
		if (st[i].roll == rl) {
			break;
		}
	}
	DPRINTF("\n The student Details");
	DPRINTF("\n-----------------------");
	DPRINTF("\nRoll number:%d",st[i].roll);
	DPRINTF("\nStudent First name:%s",st[i].fname);
	DPRINTF("\nStudent Last name:%s",st[i].lname);
	DPRINTF("\nGPA:%.2f",st[i].GPA);
	DPRINTF("\nRegistered Courses:");
	for(int j=0 ; j<5;j++){
		if (st[i].cid[j] != 0){
			DPRINTF("%d ",st[i].cid[j]);
		}

	}


}

void find_fn(){
	if(st_count==0){
		DPRINTF("\nList is empty");
		return;

	}
	char tempfn[50];
	int res;
	int i,alert=1;

	DPRINTF("\n enter first name of student you want to found:");
	gets(tempfn);

	for(i=0 ; i<st_count ;i++){
		res = stricmp(tempfn,st[i].fname);
		if(res == 0){
			alert=0;

			DPRINTF("\n The student Details");
			DPRINTF("\n-----------------------");
			DPRINTF("\nRoll number:%d",st[i].roll);
			DPRINTF("\nStudent First name:%s",st[i].fname);
			DPRINTF("\nStudent Last name:%s",st[i].lname);
			DPRINTF("\nGPA:%.2f",st[i].GPA);
			DPRINTF("\nRegistered Courses:");
			for(int x=0 ; x<5;x++){
				if (st[i].cid[x] != 0){
					DPRINTF("%d ",st[i].cid[x]);
				}
			}

		}
	}
	if(alert){
		DPRINTF("\n There is no student with this name")
	}
}
void find_c(){
	if(st_count==0){
		DPRINTF("\nList is empty");
		return;

	}
	DPRINTF("\nEnter Course ID: ");
	int id;
	scanf("%d",&id);
	for(int i=0;i<st_count;i++){
		for(int j=0 ; j<5;j++){
			if(id== st[i].cid[j]){
				DPRINTF("\n The student Details");
				DPRINTF("\n-----------------------");
				DPRINTF("\nRoll number:%d",st[i].roll);
				DPRINTF("\nStudent First name:%s",st[i].fname);
				DPRINTF("\nStudent Last name:%s",st[i].lname);
				DPRINTF("\nGPA:%.2f",st[i].GPA);

			}
		}
	}


}
void tot_s(){
	DPRINTF("\n-----------------------");
	DPRINTF("\n[INFO]Total Number of Student is :%d ",st_count);
	DPRINTF("\n[INFO]You can add up to 50 students ");
	DPRINTF("\n[INFO]You can add %d more students ",50-st_count);

}
void quit_(){
	DPRINTF("\n[INFO]Program has been exit Successfully")
											quit=1;
}
void del_s(){
	if(st_count==0){
		DPRINTF("\nList is empty");
		return;

	}
	int d_roll;
	int ref,i,alert;
	ref=0;
	alert=1;
	DPRINTF("\n enter Roll Student Number You want to delete");
	scanf("%d",&d_roll);
	for(i=0;i<st_count;i++){
		if(d_roll == st[i].roll){
			ref=i;
			st_count--;
			alert =0;
			break;
		}

	}
	if(alert){
		DPRINTF("\n[INFO]This roll number doesn't exist");
		return;
	}
	for(i=ref;i<st_count;i++){
		st[i]=st[i+1];

	}
	DPRINTF("\n[INFO] DELETED SUCCESSFULLY");



}
void up_s(){
	if(st_count==0){
		DPRINTF("\nList is empty");
		return;

	}
	int t_roll,i,ref,c_nm;
	DPRINTF("\nEnter roll number to update entry:");
	scanf("%d",&t_roll);
	for(i=0 ; i<st_count;i++){
		if(t_roll== st[i].roll){
			break;
		}
	}
	DPRINTF("\n1. first name");
	DPRINTF("\n2. last name")
	DPRINTF("\n3. roll no.");
	DPRINTF("\n4. GPA");
	DPRINTF("\n5. Courses");
	scanf("%d",&ref);
	switch(ref){
	case 1:
		DPRINTF("\nEnter new first name ");
		gets(st[i].fname);
		break;
	case 2:
		DPRINTF("\nEnter new last name ");
		gets(st[i].lname);
		break;
	case 3:
		DPRINTF("\nEnter new roll number ");
		scanf("%d",&st[i].roll);
		break;
	case 4:
		DPRINTF("\nEnter new GPA ");
		scanf("%f",&st[i].GPA);
		break;
	case 5:
		DPRINTF("\nEnter number new of courses you want to Reg. [NOTE]Max:5 ");
		scanf("%d",&c_nm);
		DPRINTF("\nEnter new courses IDs. ");
		for(int j=0;j<c_nm;j++){
			DPRINTF("\nCourse ID:");
			scanf(" %d",&st[i].cid[j]);
		}

	}
	DPRINTF("\n[INFO] UPDTAED SUCCESSFULLY.")
}
void show_s(){
	if(st_count==0){
		DPRINTF("\nList is empty");
		return;

	}
	int i,j;
	DPRINTF("\n All Student Details");
	for(i=0;i<st_count;i++){
		DPRINTF("\n-----------------------");
		DPRINTF("\nRoll number:%d",st[i].roll);
		DPRINTF("\nStudent First name:%s",st[i].fname);
		DPRINTF("\nStudent Last name:%s",st[i].lname);
		DPRINTF("\nGPA:%.2f",st[i].GPA);
		DPRINTF("\nRegistered Courses: ");
		for(j=0 ; j<5;j++){
			if(st[i].cid[j]!=0){

				DPRINTF("%d ",st[i].cid[j]);
			}

		}

	}
}
