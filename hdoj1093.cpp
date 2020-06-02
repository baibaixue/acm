#include<stdio.h>
int main()
{
	int a,n,i1,i2,m,sum;
	while(scanf("%d",&a)!=EOF){
		for(i1=0;i1<a;i1++){
			sum=0;
			scanf("%d",&n);
			if(n!=0){
				for(i2=0;i2<n;i2++){
					scanf("%d",&m);
					sum+=m;
				}
				printf("%d\n",sum);
			}	
			}
	}
	return 0;
}
