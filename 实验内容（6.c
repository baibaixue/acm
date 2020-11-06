//10月29日，白雪，分别计算i,i++,++i,--i,i--，-i++,-i--
#include<stdio.h>
int main(){
	int i=8;
	printf("i=%d,i++=%d,i--=%d,--i=%d,++i=%d,-i++=%d,-i--=%d\n",i,i++,i--,--i,++i,-i++,-i--);//同一个i
	i=8;
	printf("i=%d\n",i);
	printf("i++=%d\n",i++);
	i=8;
	printf("i--=%d\n",i--);
	i=8;
	printf("--i=%d\n",--i);
	i=8;
	printf("++i=%d\n",++i);
	i=8;
	printf("-i++=%d\n",-i++);
	i=8;
	printf("-i--=%d\n",-i--); //不同i分别求 
	return 0;
} 
