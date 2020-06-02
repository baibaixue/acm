#include <stdio.h>

void sum(int a,int b){
	int i;
	int sum=0;
	for (i=a;i<=b;i++){
		sum+=i;
	}
	printf("%d到%d的和是%d\n",a,b,sum);
}
int main()
{
	sum(1,10);
	sum(20,30);
	sum(30,45);
}
	//return sum;
//int main()
//{
	//int a,b;
	//printf("请输入一个整数区间：");
	//scanf("%d %d",&a,&b);
	//printf("累加和为%d",sum(a,b));
	//return 0;
//}

