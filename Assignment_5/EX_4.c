#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct Sstudent
{
	char name[50];
	int marks;
};
int main(){
	struct Sstudent x[10];
	int i;
	printf("Enter information of students\n\n");
	for(i=0;i<10;i++){
		printf("For roll number %d\n",i+1);
		printf("Enter name:");
		fflush(stdin); fflush(stdout);
		scanf("%s",x[i].name);
		printf("Enter marks:");
		fflush(stdin); fflush(stdout);
		scanf("%d",&x[i].marks);
		printf("\n");
	}
	printf("Displaying information of students\n\n");
	for(i=0;i<10;i++){
		printf("information For roll number %d\n",i+1);
		printf("Name:%s\n",x[i].name);
		printf("Marks:%d\n",x[i].marks);
		printf("\n");
	}
	return 0;
}
