#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
char c[1000];
int i;
printf("Enter a String:");
fflush(stdout); fflush(stdin);
gets(c);
for(i=0;c[i]!='\0';++i);
printf("Length of string: %d",i);
	return 0;
}
