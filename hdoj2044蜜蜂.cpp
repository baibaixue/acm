#include<stdio.h>
int main(){
	long long c[60]={0,1,2,3,5};//double�� 
	int n,a,b;
	while(scanf("%d",&n)!=EOF){
		while(n--){
			scanf("%d%d",&a,&b);
			for(int i=4;i<60;i++){
				c[i]=c[i-1]+c[i-2];
			}
			printf("%lld\n",c[b-a]);//%.0lf�� ȥ��С���� 
		}
	}
	return 0;
}
