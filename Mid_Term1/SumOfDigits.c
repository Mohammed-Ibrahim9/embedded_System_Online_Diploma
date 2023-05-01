# include <stdio.h>

int sumdig(int size);
int main (void) {
	int sum, size;
	printf ("enter how many numbers you want to sum: \n") ;
	fflush(stdout); fflush(stdin);
	scanf( "%d",&size);
	printf ("enter numbers you want to get its sumation: \n") ;
	sum=sumdig(size);
	printf("the sum is :%d" , sum) ;
	return 0;
}
	int sumdig(int size){
		int i,sum,a[100];
		sum=0 ;
		for (i=0;i<size;i++){
			fflush (stdout); fflush (stdin);
			scanf( "%d",&a[i]);
			sum+=a[i];
		}
			return sum;
	}
