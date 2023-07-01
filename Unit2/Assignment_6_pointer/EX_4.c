#include <stdio.h>

int main() {
   int i ,n , a[15];
   int* pt;
   printf("enter the number of elements in array: ");
   fflush(stdin); fflush(stdout);
   scanf("%d",&n);
   pt=&a[0];
   printf("enter the of the array:\n");
   for(i=0;i<n;i++){
	   printf("element - %d: ",i+1);
	   fflush(stdin); fflush(stdout);
	   scanf("%d",pt);
	   pt++;
   }
   pt=&a[n-1];
   for(i=n;i>0;i--){
	   printf("\nelement - %d: %d ",i,*pt);
	   pt--;
   }


    return 0;
}
