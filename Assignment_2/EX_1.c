#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int x,y;
	for(y=0;y<2;y++){
		fflush(stdin);
		fflush(stdout);
		printf("Enter an intger you want to check:");
		fflush(stdin);
		fflush(stdout);
		scanf("%d",&x);
		if(x%2==0)
			printf("%d is even\n",x);
		else
			printf("%d is odd\n",x);
	}


	return 0;
}
