#include <stdio.h>

int main()
{
	int a,b,x;
	//int a1=a,b1=b;
	//printf("��������������:");
	scanf("%d %d",&a,&b);
	while(b!=0){
		x=a%b;
		a=b;
		b=x;
	}
	printf("%d\n",a);
	//printf("%d��%d�����Լ��Ϊ%d",a1,b1,a);
	return 0;
}
