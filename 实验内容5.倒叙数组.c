#include<stdio.h>//交换数组 11月19日 白雪 
int main(){
	int c[]={1,3,5,7,9};//定义数组 
	int i;
	int t;
	for(i=0;i<2;i++){//交换对应元素位置 
		t=c[i];
		c[i]=c[4-i];
		c[4-i]=t;
	}
	for(i=0;i<5;i++){
		printf("%d ",c[i]);//输出 
	}
	printf("\n");
	return 0;
} 
