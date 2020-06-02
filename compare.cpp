#include <stdio.h>

int main()
{
	int a;
	int b;
	int c;
	int max;
	printf("请输入三个整数:");
	scanf("%d %d %d",&a,&b,&c);
	if (a>b){
		if (c>a)
			max=c;
		else
			max=a;
	}
	else{
		if(c>b)
			max=c;
		else
			max=b;
	}
			
	printf("最大的数为%d",max);
	
	return 0;		
	
}
