#include<stdio.h>
int main(){
	long long c[60]={0,1,2,3,5};//double型 
	int n,a,b;
	while(scanf("%d",&n)!=EOF){
		while(n--){
			scanf("%d%d",&a,&b);
			for(int i=4;i<60;i++){
				c[i]=c[i-1]+c[i-2];
			}
			printf("%lld\n",c[b-a]);//%.0lf型 去除小数点 
		}
	}
	return 0;
}
