#include <stdio.h>

int checkprime(int i);
int main(void){
	int n,n1,i,z;
	printf ("enter the intervel you want to check the prime number in it\n");
	fflush(stdout); fflush(stdin);
	scanf ("%d%d",&n,&n1) ;
	for (i=n;i<=n1;i++) {
		z=checkprime(i);
		if(z==1)
			printf ("%d " ,i) ;
	}
	return 0;

}
int checkprime (int i) {
	int x,j;
	j=1;
	for(x=2;x<=i-1;x++){
		if (i%x==0){
			j=0;
			break ;
		}
	}
	return j;
}
