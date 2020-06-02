#include <stdio.h>

int main()
{
	int i;
	printf("请输入一系列数。\n");
	int count[10];//定义数组 
	for (i=0;i<10;i++){
		count[i]=0;          //初始化数组 ** 
	}
	scanf("%d",&i);
	
	while(i>=0&&i<=9){
		count[i]++;
		scanf("%d",&i);
	}
	if(i=-1){
		for(i=0;i<10;i++){
			printf("%d:%d\n",i,count[i]);
		}
		return 0;
	}
}
