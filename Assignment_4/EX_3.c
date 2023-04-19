#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void rev(){
	char c[100];
	fflush(stdin); fflush(stdout);
	gets(c);
	strrev(c);
		printf("%s",c);

}

int main(void) {
	printf("Enter the sentence;");
	rev();
	return 0;
}
