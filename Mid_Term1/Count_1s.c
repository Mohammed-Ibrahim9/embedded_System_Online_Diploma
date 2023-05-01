#include <stdio.h>

void count(int n);
int main(void){
	int n;
	printf ("enter integer nurnbers : ");
	fflush (stdin); fflush (stdout) ;
	scanf ("%d",&n);
	count (n) ;
	return 0;
}
void count (int n) {
	int c;
	c=0;
	while(n>0){
		if (n&1)
			c++;
		n=n>>1;
	}
		printf ("number of 1s:%d" ,c);
}
