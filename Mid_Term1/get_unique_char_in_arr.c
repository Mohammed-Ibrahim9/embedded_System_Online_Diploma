#include <stdio.h>

void count(void);
int main(void) {
	count();
	return 0;
}

void count(void){
	int x,c,i,j,a[7]= {4,2,5,2,5,7,4};
	j=0;
	i=0;
	for(x=0;x<42;x++){
		i++;
		c=0;
		if(i==j)
			i++;
		if(a[j]==a[i]){
			c++;
		}
		if(i==6){
			if(c==0){
				printf("%d",a[j]);
			}
			j++;
			i=0;

		}
		if(c==1 && i!=0){
			j++;
			i=0;
		}
		if(j==7)
			break;
	}

}
