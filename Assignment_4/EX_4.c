#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int power(int base, int exp){
	if(exp!=0)
		return(base*power(base,exp-1));
		else
			return 1;
}
void main(void){
int base,exp;
printf("enter base number; ");
fflush(stdin); fflush(stdout);
scanf("%d",&base);
printf("enter power number(postive integer)");
fflush(stdin); fflush(stdout);
scanf("%d",&exp);
printf("%d^%d=%d",base,exp,power(base,exp));
	return 0;
}
