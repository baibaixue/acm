//10��29�գ���ѩ���ֱ����i,i++,++i,--i,i--��-i++,-i--
#include<stdio.h>
int main(){
	int i=8;
	printf("i=%d,i++=%d,i--=%d,--i=%d,++i=%d,-i++=%d,-i--=%d\n",i,i++,i--,--i,++i,-i++,-i--);//ͬһ��i
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
	printf("-i--=%d\n",-i--); //��ͬi�ֱ��� 
	return 0;
} 
