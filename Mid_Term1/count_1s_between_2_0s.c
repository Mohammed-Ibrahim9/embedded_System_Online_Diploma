#include <stdio.h>
#include <string.h>
void count(int n);
int main(void) {
	int n;
	printf("enter integer number ;");
	fflush(stdin); fflush(stdout);
	scanf("%d",&n);
	count(n);
	return 0;
}

void count(int n){
	int c,c0;
	c=0; c0=0; //c0 is a counter to detect zeros
	while(n>0){
		if(n&1)
			c++;
		else
			c0++;
		n=n>>1;
		if(c0==2)
			break;
	}
	printf("%d",c);



}
