#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int hurt[100005];
int main(){
	int t,v;
	while(scanf("%d%d",&t,&v)!=EOF){
		memset(hurt,0,sizeof(hurt));
		for(int i=1;i<=t;i++){
			if(i%v==0){
				hurt[i]++;
				hurt[i+8]--;
			}
		}
		int ans=0;
		for(int i=0;i<=t;i++){
			ans+=hurt[i]*5;
		}
		printf("%d\n",ans);
	}
	return 0;
} 
