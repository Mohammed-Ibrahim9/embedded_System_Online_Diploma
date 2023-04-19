#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int check_prime(int k);

int main(void) {
	int n1,n2,i,flag;
	printf("Enter two numbers(intervals)");
	fflush(stdin);  fflush(stdout);
	scanf("%d %d",&n1,&n2);
	printf("prime number between %d and %d are: ",n1,n2);
	for(i=n1;i<n2;i++){
		flag=check_prime(i);
		if(flag==0)
			printf("%d ",i);
	}

	return 0;
}
int check_prime(int k){
	int j,flag=0;
	for(j=2;j<=k/2;j++){
		if(k%j==0){
			flag=1;
			break;
		}
	}
	return flag;

}
