#include <stdio.h>

int main()
{
	int a;
	int b;
	int c;
	int max;
	printf("��������������:");
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
			
	printf("������Ϊ%d",max);
	
	return 0;		
	
}
