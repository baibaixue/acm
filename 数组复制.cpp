#include<stdio.h>
#include<string.h>
int main(){
	int a[9]={1,2,3,4,5,6,7,8,9};
	int b[9]={0};
	int k=4;
	memcpy(b,a,sizeof(int)*k);
	for(int i=0;i<10;i++){
		printf("%d ",b[i]);
	}
	printf("\n");
	return 0;
} 
