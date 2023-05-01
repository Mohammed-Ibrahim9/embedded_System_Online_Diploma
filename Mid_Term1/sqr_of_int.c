#include <stdio.h>

float sqr(int n);
int main(void){
	int n;
	float sq;
	printf ("enter the number you want to get its root\n") ;
	fflush (stdout); fflush (stdin) ;
	scanf ( "%d" , &n) ;
	sq=sqr (n) ;
	printf ("the root of %d----->%.3f",n,sq);
			return 0;
}
	float sqr (int n) {
		float sq;
		sq=pow(n,0.5);
		return sq;
	}
