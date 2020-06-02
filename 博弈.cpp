/*博弈sg函数 
#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
#define maxn 10000
using namespace std;
//f[N]:可改变当前状态的方式，N为方式的种类，f[N]要在getSG之前先预处理
//SG[]:0~n的SG函数值
//S[]:为x后继状态的集合
int f[N],SG[MAXN],S[MAXN];
void  getSG(int n){
    int i,j;
    memset(SG,0,sizeof(SG));
    //因为SG[0]始终等于0，所以i从1开始
    for(i = 1; i <= n; i++){
        //每一次都要将上一状态 的 后继集合 重置
        memset(S,0,sizeof(S));
        for(j = 0; f[j] <= i && j <= N; j++)
            S[SG[i-f[j]]] = 1;  //将后继状态的SG函数值进行标记
        for(j = 0;; j++) if(!S[j]){   //查询当前后继状态SG值中最小的非零值
            SG[i] = j;
            break;
        }
    }
}
*/
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>G[1005];
int SG[1005];
int getSG(int x)   //获取节点x的sg值
{
	if(SG[x]!=-1)return SG[x];
	bool vis[1005];
	memset(vis,0,sizeof(vis));
	for(int i=0;i<G[x].size();i++)
	{
		vis[getSG(G[x][i])]=1;
	}
	int k=0;
	while(vis[k])k++;
	return SG[x]=k;
}
int main()
{
	int n,m;
	while(~scanf("%d",&n))
	{
		memset(SG,-1,sizeof(SG)); 
		for(int i=0;i<1005;i++)G[i].clear();
		int k,x;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&k);
			for(int j=0;j<k;j++)
			{
				scanf("%d",&x);
				G[i].push_back(x);
			}
		}
		while(~scanf("%d",&m)&&m)
		{
			int sum=0;
			for(int i=0;i<m;i++)
			{
				scanf("%d",&x);
				sum^=getSG(x);
			}
			if(sum)printf("WIN\n");
			else printf("LOSE\n");
		}
	}
}

