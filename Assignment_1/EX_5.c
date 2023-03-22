#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char x;
	printf("Enter a character:");
	fflush(stdin);
	fflush(stdout);
	scanf("%c",&x);
	printf("ASCII value of G =%d",x);

	return 0;
}
