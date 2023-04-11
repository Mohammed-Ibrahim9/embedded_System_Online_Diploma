#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
char c[1000],ch;
int i,count=0;
printf("Enter a string: ");
fflush(stdout); fflush(stdin);
gets(c);
printf("Enter chracter to find frequency:");
fflush(stdout); fflush(stdin);
scanf("%c",&ch);
for(i=0;c[i]!='\0';++i){
	if(ch==c[i])
		++count;
}
printf("Frequency of %c = %d",ch,count);
	return 0;
}
