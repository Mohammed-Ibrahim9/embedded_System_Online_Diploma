#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct Sstudent
{
	char m_name[50];
	int m_roll;
	float m_marks;
};
int main(){
	struct Sstudent x;
	printf("Enter information of student:\n\n");
	printf("Enter student Name:");
	fflush(stdout); fflush(stdin);
	scanf("%s",x.m_name);
	printf("Enter student Roll number:");
	fflush(stdout); fflush(stdin);
	scanf("%d",&x.m_roll);
	printf("Enter student Marks:");
	fflush(stdout); fflush(stdin);
	scanf("%f",&x.m_marks);
	printf("\nDisplaying Information:\n");
    printf("Name:%s\n",x.m_name);
    printf("Roll:%d\n",x.m_roll);
    printf("Marks:%.2f",x.m_marks);
	return 0;
}
