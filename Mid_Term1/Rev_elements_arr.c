#include <stdio.h>
#include <string.h>

void rev(void);
int main(void){
	rev( );
	return 0;
}
void rev (void) {
	int a[5]={1,2,3,4,5};
	int s,i;
	s=5;
	for (i=0;i<s;i++) {
		printf ("%d ",a[s-i-1]);
	}
}
