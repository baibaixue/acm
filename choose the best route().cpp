#include <iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#define N 1100
#define INF 0x7ffffff
 
using namespace std;
 
int d[N],v[N],mp[N][N],n;
 
int spfa(int s,int t)
{
    for(int i=0;i<=n;i++)   d[i]=INF,v[i]=0;
    queue<int> q;
    q.push(0);
    d[0]=0;
    v[0]=1;
    while(!q.empty())
    {
        int c=q.front();
        q.pop();
        v[c]=0;
        for(int i=0;i<=n;i++)
        {
            if(d[i]>d[c]+mp[c][i])
            {
                d[i]=d[c]+mp[c][i];
                if(!v[i])   v[i]=1,q.push(i);
            }
        }
    }
    if(d[t]>=INF)   return -1;
    return d[t];
}
 
int main()
{
    int m,t,nn,s;
    while(~scanf("%d%d%d",&n,&m,&t))
    {
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                mp[i][j]=INF;
        for(int i=0;i<m;i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            mp[u][v]=min(mp[u][v],w);
        }
        scanf("%d",&nn);
        for(int i=0;i<nn;i++)
        {
            scanf("%d",&s);
            mp[0][s]=0;
        }
        cout<<spfa(0,t)<<endl;
    }
}

