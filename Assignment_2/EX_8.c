#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char x;
	float y , z;
	printf("enter operator either + or - or * or /:");
	fflush(stdin); fflush(stdout);
	scanf("%c",&x);
	printf("\nenter two operands:");
	fflush(stdin); fflush(stdout);
	scanf("%f %f",&y,&z);
	switch (x){
	case '+':
	{
	printf("%.1f + %.1f = %.1f", y, z, y+z);
	}
	break;
	case '-':
	{
		printf("%.1f - %.1f = %.1f", y, z, y-z);
	}
	break;
	case'*':
	{
		printf("%.1f * %.1f = %.1f", y, z, y*z);
	}
	break;
	case '/':
	{
		printf("%.1f / %.1f = %.1f", y, z, y/z);
	}
	break;


	}
	return 0;
}
