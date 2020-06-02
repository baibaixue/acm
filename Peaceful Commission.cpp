#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#define maxn 16005
using namespace std;
bool unlike[maxn][maxn];
int ans[8005];
int n,m;
int ok=0;
bool bfs(int x,int num){
	if(unlike[x][num*2+1]==true){
		ans[x]=num*2+1;
		if(num+1>=n){
			ok=1;
			return true;
		}
		if(bfs(num*2+1,num+1)==false){
			ans[x]=0;
		}
	}
	if(ok==0){
		if(unlike[x][num*2+2]==true){
			ans[x]=num*2+2;
			if(num+1>=n){
				ok=1;
				return true;
			}
			if(bfs(num*2+2,num+1)==false){
				ans[x]=0;
			}
		}
	}
	
	if(ok==1){
		return true;
	}else{
		return false;
	}
}
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		memset(unlike,true,sizeof(unlike));
		memset(ans,0,sizeof(ans));
		for(int i=0;i<m;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			unlike[a][b]=false;
			unlike[b][a]=false;
		}
		if(bfs(0,0)==false){
			printf("nie\n");
		}else{
			int i=ans[0];
			while(i!=0){
				printf("%d\n",i);
				i=ans[i];
			}
		}
	}
	return 0;
}
 
