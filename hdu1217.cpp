#include<iostream>
#include<cstdio>
#include<string.h>
#include<algorithm>
#define maxn 35
using namespace std;
double dis[maxn][maxn];
char s[maxn][110],s1[110],s2[110];
int n,m;
int comp(char *s1){
	for(int i=0;i<n;i++){
		if(strcmp(s[i],s1)==0){
			return i;
		}
	}
}
int main(){
	int t=1;
	while(scanf("%d",&n)!=EOF&&n!=0){
		memset(dis,0,sizeof(dis));
		for(int i=0;i<n;i++){
			cin>>s[i];
		}
		scanf("%d",&m);
		double x;
		for(int i=0;i<m;i++){
			cin>>s1>>x>>s2;
			int a=comp(s1);
			int b=comp(s2);
			dis[a][b]=x;
//			dis[a][a]=1;
//			dis[b][b]=1;
		}
		for(int k=0;k<n;k++){
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					dis[i][j]=max(dis[i][k]*dis[k][j],dis[i][j]);
				}
			}
		}
		int ok=0;
		for(int i=0;i<n;i++){
			if(dis[i][i]>1){
				ok=1;
				printf("Case %d: Yes\n",t);
				break;
			}
		}
		if(ok==0){
			printf("Case %d: No\n",t);
		}
		t++;
	}
	return 0;
}
