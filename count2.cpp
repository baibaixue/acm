#include <stdio.h>

int main(){
	int x,n=0;
	printf("������x��ֵ��");
	scanf("%d",&x);
	do
	{
		n++;
		x/=10;
	}
	while(x>0);
	printf("%d",n);

	return 0;
	
}