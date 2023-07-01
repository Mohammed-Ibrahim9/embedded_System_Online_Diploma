#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	int a[30],ele,num,i;
	printf("\nEnter no of elements:");
	fflush(stdout); fflush(stdin);
	scanf("%d",&num);
	printf("\nEnter Values:");
	for(i=0;i<num;i++){
		fflush(stdout); fflush(stdin);
		scanf("%d",&a[i]);
	}
	printf("\nEnter element to be searched :");
	fflush(stdout); fflush(stdin);
	scanf("%d",&ele);
	i=0;
	while(i<num && ele!=a[i]){
		i++;
	}
	if(i<num){
		printf("Number found at the location = %d",i+1);
	}else{
		printf("Number Not found");
	}
	return 0;
}
