#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	int n,i;
	float num[500], sum,avg;
	printf("enter the numbers of data:");
	fflush(stdout); fflush(stdin);
	scanf("%d",&n);
	while(n>500 || n<=0){
		printf("Error!number should be in range of (1 to 500).\n");
		printf("enter the numbers of data again:");
		fflush(stdout); fflush(stdin);
		scanf("%d",&n);
	}
	for(i=0;i<n;i++){
		printf("%d. Enter number: ",i+1);
		fflush(stdout); fflush(stdin);
		scanf("%f",&num[i]);
		sum+=num[i];
	}
	avg=sum/n;
	printf("Average=%.f",avg);
	return 0;
}
