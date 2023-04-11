#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	int a[30],ele,num,i,loc;
	printf("Enter no of elments:");
	fflush(stdout); fflush(stdin);
	scanf("%d",&num);
	for(i=0;i<num;i++){
		fflush(stdout); fflush(stdin);
		scanf("%d",&a[i]);
	}
	printf("\nEnter the elment to be inserted:");
	fflush(stdout); fflush(stdin);
	scanf("%d",&ele);
	printf("\nEnter the location");
	fflush(stdout); fflush(stdin);
	scanf("%d",&loc);
for(i=num;i>=loc;i--){
	a[i]=a[i-1];
}
num++;
a[loc-1]=ele;
for(i=0;i<num;i++){
	printf(" %d",a[i]);
}

	return 0;
}
