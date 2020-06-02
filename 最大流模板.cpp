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
bool dinic_bfs()//����������
{
	queue<int> Q;
	memset(level,0,sizeof(level));//��ʼ������Ĳ�� Ϊ0
	Q.push(1);
	level[1]=1;
	int u,v;
	while(!Q.empty())
	{
		u=Q.front();
		Q.pop();
		for(v=1;v<=M;v++)
		{
			if(!level[v]&&edge[u][v].c>edge[u][v].f)//������δ�����ʹ�������u��v,���ڱ�
			{
				level[v]=level[u]+1;//�������ǲ��
				Q.push(v);
			}
		}
	}
	return level[M]!=0;//������false���� ��㲻�ڲ��������
}
int dinic_dfs(int u,int cp)//��������
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
int dinic()//��������
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
			edge[Si][Ei].c+=Ci;//��ֹ�ر�
		}
		int S=dinic();
		printf("%d\n",S);
	}
	return 0;
}

