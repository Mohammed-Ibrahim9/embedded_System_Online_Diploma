#include <stdio.h>

void revers(void);
int main (void) {
	printf ("enter 4 integer numbers to be reversed:");
			revers ( ) ;
	return 0;
}
	void revers (void) {
		int i, x[4];
		for (i=0; i<4;i++){
			fflush (stdin) ; fflush (stdout) ;
			scanf ("%d",&x[i]);
		}
			printf ("The reversed numbers is;\n") ;
			for (i=3;i>=0;i--){
					printf ("%d",x[i]);
}
	}
