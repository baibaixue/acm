#include <stdio.h>

int main()
{
	int x,count=0;
	int sum=0;
	scanf("%d",&x);
	while(x!=-1){
		sum+=x;
		count++;
		scanf("%d",&x);
	}
	printf("ƽ����Ϊ%f",1.0*sum/count);
	return 0;
}
