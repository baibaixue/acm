#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<string.h>
#include<vector>
#include<cmath>
#define maxn 55
using namespace std;
char s1[maxn];
char s2[maxn];
int dis[maxn];
int cmp(int a,int b){
	return a>b;
}
int main(){
	while(scanf("%s",&s1)!=EOF){
		scanf("%s",&s2);
		int k;
		scanf("%d",&k);
		int len=strlen(s1);
		for(int i=0;i<len;i++){
			dis[i]=fabs((int)(s1[i]-s2[i]));
		}
		sort(dis,dis+len,cmp);
			int ans=0;
			for(int i=0;i<len;i++){
				if(i<k){
					if(dis[i]==0){
						ans+=1;
					}
				}else{
					ans+=dis[i];
				}
			}
			printf("%d\n",ans);
		memset(s1,0,sizeof(s1));
		memset(s2,0,sizeof(s2));
		memset(dis,0,sizeof(dis)); 
	}
	return 0;
}
