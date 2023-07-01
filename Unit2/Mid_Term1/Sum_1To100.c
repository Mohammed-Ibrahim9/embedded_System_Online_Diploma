#include <stdio.h>
#include <string.h>

int sum(int i);
int main(void){
	int i,s;
	i=100;
	s=sum(i) ;
	printf ("%d",s);
	return 0;
}
int sum (int i){
	int s;
	s=i*(i+1)/ 2;
	return s;
}
