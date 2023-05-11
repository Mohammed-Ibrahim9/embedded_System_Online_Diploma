#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct Sstudent
{
	float real;
	float img;
};
int main(){
	struct Sstudent x[2];
	printf("for 1st complex\n") ;
	printf("Enter real and imaginary respectively:");
	fflush(stdout); fflush(stdin);
	scanf("%f%f",&x[0].real,&x[0].img);
	printf("for 2nd complex\n") ;
		printf("Enter real and imaginary respectively:");
		fflush(stdout); fflush(stdin);
		scanf("%f%f",&x[1].real,&x[1].img);
		printf("Sum=%.1f+%.1fi",x[0].real+x[1].real,x[0].img+x[1].img);

	return 0;
}
