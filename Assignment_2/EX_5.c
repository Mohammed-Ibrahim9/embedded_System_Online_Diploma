#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char x;
	int i;
	for(i=0;i<2;i++){
		printf("Enter a character:");
		fflush(stdin);
		fflush(stdout);
		scanf("%c",&x);
		if((x>=97 && x<=122) || (x>=65 && x<=90) )
				printf("%c is alphabet\n",x);
		else
			printf("%c is not alphabet\n",x);
	}


	return 0;
}
