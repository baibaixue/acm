#include<stdio.h>
int main()
{
	int a;
	int i=1;
	while(scanf("%d",&a)!=EOF){
		int sum=0;
		for(i=1;i<=a;i++){
		sum+=i;
	}
	printf("%d\n\n",sum);
	}
	return 0;
 } 
