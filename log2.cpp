#include <stdio.h>

int main()
{
	int x,result=0,a;
	printf("������һ������x:");
	scanf("%d",&x);
	a=x;
	while (x>1){
		x/=2;
		result++;
	}
	printf("log2 of %d is %d",a,result);
	return 0;
	
}
