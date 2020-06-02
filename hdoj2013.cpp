#include<stdio.h>
int main()
{
	int n,a=1,i;
	while(scanf("%d",&n)!=EOF){
		for(i=1;i<n;i++){
			a=(a+1)*2;
		}
		printf("%d\n",a);
		a=1;
	}
	return 0;
}
