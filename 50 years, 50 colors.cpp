#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#define maxn 505
using namespace std;
int Map[105][105];
int k,n;
int match[505],vis[505];
int a[105][105],ans[55];
int col[55];
int find(int s){
    for(int i=1;i<=n;i++){
        if(!vis[i]&&Map[s][i]){
            vis[i]=1;
            if(match[i]==-1||find(match[i])){
                match[i]=s;
                return 1;
            }
        }
    }
    return 0;
}
int max_match(){
    int res=0;
    memset(match,-1,sizeof(match)) ;
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof(vis)) ;
        res+=find(i);
    }
    return res;
}
int main(){
    while(scanf("%d%d",&n,&k)!=EOF&&n&&k){
        memset(col,0,sizeof(col));
		memset(Map,0,sizeof(Map));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                scanf("%d",&a[i][j]);
                col[a[i][j]]=1;
            }
        }
        int st=0;
        for(int i=1;i<=50;i++){
            if(col[i]!=0){
                for(int j=1;j<=n;j++){
                    for(int h=1;h<=n;h++){
                        if(a[j][h]==i){
							Map[j][h]=1;
						} 
                        else{
                        	Map[j][h]=0;
						}
                    }
                }
                int res=max_match();
                if(res>k){
					ans[st++]=i;
				} 
            }
        }
        if(!st){
        	printf("-1");
		}
        else{
            for(int i=0;i<st;i++){
                if(i){
                	printf(" %d",ans[i]) ;
				} 
                else{
                	printf("%d",ans[i]) ;
				}
			
            }
        }
		printf("\n");
    }
    return 0;
}
