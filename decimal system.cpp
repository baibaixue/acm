#include<stdio.h>
#include<math.h>
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		long long int sum=0;
		while(n--){
			int x,y;
			scanf("%d(%d)",&x,&y);
			int a=0;
			int k=0; 
			for(;;){
				a+=x%10*pow((double)y,(double)k++);
				x=x/10;
				if(x==0){
					break;
				}
			}
			sum+=a;
		}
		printf("%lld\n",sum);
	}
	return 0;
} 
