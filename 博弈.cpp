/*����sg���� 
#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
#define maxn 10000
using namespace std;
//f[N]:�ɸı䵱ǰ״̬�ķ�ʽ��NΪ��ʽ�����࣬f[N]Ҫ��getSG֮ǰ��Ԥ����
//SG[]:0~n��SG����ֵ
//S[]:Ϊx���״̬�ļ���
int f[N],SG[MAXN],S[MAXN];
void  getSG(int n){
    int i,j;
    memset(SG,0,sizeof(SG));
    //��ΪSG[0]ʼ�յ���0������i��1��ʼ
    for(i = 1; i <= n; i++){
        //ÿһ�ζ�Ҫ����һ״̬ �� ��̼��� ����
        memset(S,0,sizeof(S));
        for(j = 0; f[j] <= i && j <= N; j++)
            S[SG[i-f[j]]] = 1;  //�����״̬��SG����ֵ���б��
        for(j = 0;; j++) if(!S[j]){   //��ѯ��ǰ���״̬SGֵ����С�ķ���ֵ
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
int getSG(int x)   //��ȡ�ڵ�x��sgֵ
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

