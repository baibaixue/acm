#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int num[105];
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%d",&num[i]);
		}
		sort(num,num+n);
		int ans=0;
		for(int i=1;i<n;i+=2){
			ans+=num[i]-num[i-1];
		}
		printf("%d\n",ans);
	}
	return 0;
}
