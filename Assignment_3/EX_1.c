	#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	float x[2][2];
	float y[2][2];
	float z[2][2];
	int j,i;
	printf("enter elment of 1st matrix\n");
	for(i=0;i<2;++i){
		for(j=0;j<2;++j){
			printf("Enter a%d%d",i+1,j+1);
			fflush(stdout); fflush(stdin);
			scanf("%f",&x[i][j]);
		}
	}
	printf("enter elment of 2nd matrix\n");
	for(i=0;i<2;++i){
			for(j=0;j<2;++j){
				printf("Enter b%d%d",i+1,j+1);
				fflush(stdout); fflush(stdin);
				scanf("%f",&y[i][j]);
			}
		}
	for (i = 0; i < 2; i++)
	    for (j = 0; j < 2; j++) {
	      z[i][j] = x[i][j] + y[i][j];
	    }
	printf("\nSum of two matrices: \n");
	  for (i = 0; i < 2; i++)
	    for (j = 0; j < 2; j++) {
	      printf("%.1f   ", z[i][j]);
	      if (j == 1) {
	        printf("\n\n");
	      }
	    }
	return 0;
}
