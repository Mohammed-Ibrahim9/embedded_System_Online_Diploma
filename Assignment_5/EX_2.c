#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct Sdistance
{
	int feet;
	float inch;
};
int main(){
	struct Sdistance x[2];
	printf("Enter information for 1st distance\n");
	printf("Enter feet:");
	fflush(stdout); fflush(stdin);
	scanf("%d",&x[0].feet);
	printf("Enter inch:");
	fflush(stdout); fflush(stdin);
	scanf("%f",&x[0].inch);
	printf("Enter information for 2nd distance\n");
		printf("Enter feet:");
		fflush(stdout); fflush(stdin);
		scanf("%d",&x[1].feet);
		printf("Enter inch:");
		fflush(stdout); fflush(stdin);
		scanf("%f",&x[1].inch);
		if(x[0].inch+x[1].inch>12){

			printf("Sum of distances=%d'%.1f\"",x[0].feet+x[1].feet+1,x[1].inch+x[0].inch-12);
		}
		else
		printf("Sum of distances=%d'%.1f\"",x[0].feet+x[1].feet,x[1].inch+x[0].inch);
	return 0;
}
