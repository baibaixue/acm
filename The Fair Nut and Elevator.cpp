#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn 110
int num[maxn];
int x[maxn];
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int sum=0;
		int people=0;
		memset(x,0,sizeof(x));
		memset(num,0,sizeof(num));
		//scanf("%d",&num[1]);
		for(int i=1;i<=n;i++){
			scanf("%d",&num[i]);
			//people+=num[i];
			//sum+=num[i]*i;
		}
		//double a=sum*1.0/people;
		//int x=(int)(a+0.49);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				x[i]+=(abs(i-j)+(i-1)+(j-1))*num[j]*2;
			}
		}
		int ans=x[1]; 
		//int floor=1;
		for(int i=1;i<=n;i++){
			if(x[i]<ans){
				ans=x[i];
				//floor=i;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
