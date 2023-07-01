#include<stdio.h>
#include<stdlib.h>


int main(){
	char alph[27];
	int i;
	char* p;
	printf("Pointer to print all alphabets\n");
	p=alph;
	for(i=0;i<26;i++){
		*(p+i)=i+'A';
	}
	printf("The alphabets \n");

	for(i=0;i<26;i++){
		printf(" %c  ",*(p+i));
	}
	return 0;
}
