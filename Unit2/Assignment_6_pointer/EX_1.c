#include<stdio.h>
#include<stdlib.h>


int main(){
	int m;
	int* ab;
	m=29;
	ab=&m;
	printf("address of m: %p\n",&m);
	printf("value of m: %d\n\n",m);

	printf("address of pointer ab  : %p\n",ab);
	printf("value of pointer ab: %d\n\n",*ab);

	printf("The value of m assigned to 34 now.\n");
	m=34;

	printf("address of pointer ab  : %p\n",ab);
	printf("value of pointer ab: %d\n\n",*ab);

	printf("The value of m assigned to 7 now.\n");
	m=7;

	printf("address of pointer ab  : %p\n",ab);
	printf("value of pointer ab: %d\n\n",*ab);



	return 0;
}
