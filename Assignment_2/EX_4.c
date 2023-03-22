#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float x;
	int i;
	for(i=0;i<3;i++){
		printf("Enter a number:");
		fflush(stdin);
		fflush(stdout);
		scanf("%f",&x);
		if(x>0)
				printf("%.2f is positive\n",x);
		else if(x==0)
			printf("you entered zero\n");
		else
			printf("%.2f is negative\n",x);
	}


	return 0;
}
