#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int fact(int n);

int main(void) {
	int n;
	printf("enter positive integer number:");
	fflush(stdin); fflush(stdout);
	scanf("%d",&n);
	printf("factorial of %d = %ld ",n,fact(n));
	return 0;
}
int fact(int n){
	if(n!=1)
		return n*fact(n-1);
}
