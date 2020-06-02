#include<cstdio>
#include<iostream>
#include<string.h>
#include<vector>
#include<queue>
#define INF 0x3f3f3f3f
#define maxn 10010
using namespace std;
vector<int> A[maxn];
struct node
{
    int num,step;
};
int visit[maxn];
void bfs(int v){
	queue<node>Q;
    node start;
    start.num=v;
    start.step=0;
    visit[v]=1;
    Q.push(start);
    int max=0,ans=maxn;
    while(!Q.empty()){
        node tmp=Q.front();
        node tmp1;
        Q.pop();
        if(tmp.step>=max){
            if(tmp.step>max){
                max=tmp.step;
                ans=tmp.num;
            }
            else if(tmp.step==max){
                if(tmp.num<ans)
                    ans=tmp.num;
            }
        }
        for(int i=0;i<A[tmp.num].size();i++){
            int j=A[tmp.num][i];
            if(visit[j]==0){
                tmp1.num=j;
                tmp1.step=tmp.step+1;
                Q.push(tmp1);
                visit[j]=1;
            }
        }
    }
    if(v==ans){
    	printf("0\n");
	}   
    else{
    	printf("%d\n",ans);
	}
}
int main(){
    int n,m,k;
    while(scanf("%d%d%d",&n,&m,&k)!=EOF){
	    for(int i=1;i<=m;i++){
	    	int a,b;
	        scanf("%d%d",&a,&b);
	        A[a].push_back(b);
	        A[b].push_back(a);
	    }
	    for(int i=1;i<=k;i++){
	        int t;
	        scanf("%d",&t);
	        memset(visit,0,sizeof(visit));
	        bfs(t);
	    }
	}
    return 0;
}

