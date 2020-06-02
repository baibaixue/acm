#include<stdio.h>
int main()
{	
	int n,i,a;
	int sum;
	while(scanf("%d ",&n)!=EOF){
		sum=0;
		if(n!=0){
			for(i=0;i<n;i++){
				scanf("%d",&a);
				sum+=a;
			}
			printf("%d\n",sum);
		}
	else
	break;
	}
	return 0;
}
