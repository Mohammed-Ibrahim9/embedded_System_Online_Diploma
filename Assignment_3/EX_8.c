#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	char c[100],temp;
	int i,j=0;
	printf("Enter the string:");
	gets(c);
	i=0;
	j=strlen(c)-1;
	while(i<j){
		temp=c[i];
		c[i]=c[j];
		c[j]=temp;
		i++;
		j--;
	}
	printf("\nReverse string is: %s",c);
	return 0;
}
