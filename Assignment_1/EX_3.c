#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int x,y;
	printf("Enter two integers:");
	fflush(stdin);
	fflush(stdout);
	scanf("%d %d",&x,&y);
	printf("Sum:%d",y+x);

	return 0;
}
