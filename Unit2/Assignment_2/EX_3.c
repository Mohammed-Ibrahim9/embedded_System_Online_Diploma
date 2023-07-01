#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float y,x,z;
		printf("Enter three numbers:");
		fflush(stdin);
		fflush(stdout);
		scanf("%f %f %f",&x,&y,&z);
		if(x>=y){
			if(x>=z)
				printf("Largest number is %.2f",x);
		}
		else if(z>=y)
			printf("Largest number is %.2f",z);
		else
			printf("Largest number is %.2f",y);


	return 0;
}
