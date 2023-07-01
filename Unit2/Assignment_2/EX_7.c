#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int x,z;
	int i,j;
	z=0;
	for(j=0;z<2;z++){
	printf("Enter an intger:");
			fflush(stdin);
			fflush(stdout);
			scanf("%d",&x);
			if(x>0){
	for(i=x;i>0;i--){
		z=z*i;
	}
	printf("Factorial = %d\n",z);
			}
			else
				printf("Error!!! Factorial of negative number dosen't exist.\n");
	}



	return 0;
}
