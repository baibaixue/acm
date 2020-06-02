#include<iostream>

#include<cstdio>
#include<queue>
#include<string.h> 
#define INF 0x7fffffff
#define min(a,b) a<b?a:b
using namespace std;
int N,M;
int level[205];
int Si,Ei,Ci;
struct Dinic
{
	int c;
	int f;
}edge[205][205];
bool dinic_bfs()//构造层次网络
{
	queue<int> Q;
	memset(level,0,sizeof(level));//初始化顶点的层次 为0
	Q.push(1);
	level[1]=1;
	int u,v;
	while(!Q.empty())
	{
		u=Q.front();
		Q.pop();
		for(v=1;v<=M;v++)
		{
			if(!level[v]&&edge[u][v].c>edge[u][v].f)//即顶点未被访问过，顶点u，v,存在边
			{
				level[v]=level[u]+1;//给顶点标记层次
				Q.push(v);
			}
		}
	}
	return level[M]!=0;//若返回false表明 汇点不在层次网络中
}
int dinic_dfs(int u,int cp)//进行增广
{
	int tmp=cp;
	int v,t;
	if(u==M)
		return cp;
	for(v=1;v<=M&&tmp;v++)
	{
		if(level[u]+1==level[v])
		{
			if(edge[u][v].c>edge[u][v].f)
			{
				t=dinic_dfs(v,min(tmp,edge[u][v].c-edge[u][v].f));
				edge[u][v].f+=t;
				edge[v][u].f-=t;
				tmp-=t;
			}
		}
	}
	return cp-tmp;
}
int dinic()//求出最大流
{
	int sum,tf;
	sum=tf=0;
	while(dinic_bfs())
	{
		while(tf=dinic_dfs(1,INF))
		{
			sum+=tf;
		}
	}
	return sum;
}
int main()
{
	while(~scanf("%d%d",&N,&M))
	{
		memset(edge,0,sizeof(edge));
		while(N--)
		{
			scanf("%d%d%d",&Si,&Ei,&Ci);
			edge[Si][Ei].c+=Ci;//防止重边
		}
		int S=dinic();
		printf("%d\n",S);
	}
	return 0;
}

