#include<stdio.h>

int main()
{
	int n,i,a;
	int res=1;
	while(scanf("%d",&n)!=EOF){
		for(i=0;i<n;i++){
			scanf("%d",&a);
			if(a%2!=0){
				res*=a;
			}
		}
		printf("%d\n",res);
		res=1;
	}
	return 0;
} 
