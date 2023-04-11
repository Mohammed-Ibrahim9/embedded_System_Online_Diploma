#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  int a[10][10],b[10][10],r,c,i,j;
  printf("Enter rows and columns of matrix:");
  fflush(stdout); fflush(stdin);
  scanf("%d %d",&r,&c);
  printf("\nEnter elements of matrix:\n");
  for(i=0; i<r;++i){
	  for(j=0;j<c;++j){
		  printf("Enter elements a%d%d",i+1,j+1);
		  fflush(stdout); fflush(stdin);
		  scanf("%d",&a[i][j]);
	  }
  }
  printf("\nEntered Matrix: \n");
  for(i=0;i<r;++i){
	  for(j=0;j<c;++j){
		  printf("%d  ",a[i][j]);
			if(j==c-1)
				printf("\n\n");
	  }
  }
  for(i=0; i<r;++i)
  	  for(j=0;j<c;++j){
  		  b[j][i]=a[i][j];
  	  }
  printf("\nTranspoe of Matrix: \n");
    for(i=0;i<c;++i){
  	  for(j=0;j<r;++j){
  		  printf("%d  ",b[i][j]);
  			if(j==r-1)
  				printf("\n\n");
  	  }
    }

	return 0;
}
