#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int x,z;
	int i;
	z=0;
	printf("Enter an intger:");
			fflush(stdin);
			fflush(stdout);
			scanf("%d",&x);
	for(i=x;i>0;i--){
		z=z+i;

	}
	printf("sum = %d",z);


	return 0;
}
