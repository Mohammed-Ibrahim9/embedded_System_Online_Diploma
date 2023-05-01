#include <stdio.h>
#include <string.h>

void rev (void);
int main(void){
	rev() ;
	return 0;
}
void rev (void) {
	char a[500];
	int i,j,x;
	printf ("enter a string you want to reverse: ");
	fflush (stdin); fflush (stdout) ;
	gets(a);
	for (i=0; i<strlen(a);i++){
		if(a[i]==' '){
			for (j=i+1;j<strlen(a);j++){
				printf ("%c" ,a[j]);
			}
			break;
		}
	}
	printf(" ");
	for (x=0;x<strlen(a);x++){
		if (a[x]==' ')
			break;
		printf ("%c",a [x]);
	}
}
