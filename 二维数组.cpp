#include <stdio.h>

int main(){
	int a[4][5]={
	{0,1,2,3,4},
	{1,2,3,4,5},
	{2,3,4,5,6},
	{3,4,5,6,7},
	};
	int i,j;
	for (i=0;i<4;i++){
		printf("\n");
		for (j=0;j<5;j++){
			printf("%d\t",a[i][j]);
		}
	}
	printf("\n");
	return 0;
}
