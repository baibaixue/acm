#include<cstdio>
#include<iostream>
#include<string.h>
#include<algorithm>
int main(){
		int n;
		int k;
		while(scanf("%d",&n)!=EOF){
			int ans=0;//存胜利者的下标 
			int k=2;
			for(int i=1;i<=n;i++){
				ans=(ans+k-1)%i+1;
			}
			printf("%d\n",ans);
		}
	return 0;
}
