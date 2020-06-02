#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
const int T = 22;
char g[T][T];
int vis[T][T][1030],n,m,t,ans;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

struct point
{
    int x;
    int y;
    int step;
    int key;
};
point s;

void inset()
{
    for(int i=0;i<n;i++)
    {
        cin>>g[i];//输入一行字符
        for(int j=0;j<m;j++)
        {
            if(g[i][j]=='@')
            {
                s.x=i;
                s.y=j;
                s.key=0;
                s.step=0;
            }
        }
    }
}

int cheak(int x,int y)
{
    if(s.x>=0 && s.x<n && s.y>=0 && s.y<m )//没有越界
        return 1;
    return 0;
}
void bfs()
{
    queue<point>  Q;
    point tp;
    ans=-1;
    memset(vis,0,sizeof(vis));
    vis[s.x][s.y][s.key]=1;//可以走回头路但是必须拿到钥匙，改变[s.key]的值，这就是技巧
    Q.push(s);
    while(!Q.empty())
    {
         tp=Q.front();
         Q.pop();
         for(int k=0;k<4;k++)
         {
             s=tp;
             s.x=tp.x+dir[k][0];
             s.y=tp.y+dir[k][1];
             if(cheak(s.x,s.y) && g[s.x][s.y]!='*' && !vis[s.x][s.y][s.key])//注意，这里vis[s.x][s.y][s.key]是0的时候才能进
             {
                 if(g[s.x][s.y]=='.' || g[s.x][s.y]=='@')
                 {
                       vis[s.x][s.y][s.key]=1;
                       s.step+=1;
                       Q.push(s);
                       cout<<s.x<<" "<<s.y<<"key:"<<s.key<<endl;
                 }
                 if(g[s.x][s.y]=='^')
                 {
                     if(s.step+1<t) 
                         ans=s.step+1;
                     return ;
                 }
                 if(g[s.x][s.y]>='A' && g[s.x][s.y]<='J')
                 {    //eg:a<<2表示将a是二进制左移2位（相当于*4），这里用来表示钥匙eg:A-A=0;1<<0,就是0000 0001就是第一把钥匙了。
                      int key=1<<(g[s.x][s.y]-'A');//同理当g[s.x][s.y]='B'时，就是1<<2,就是0000 0010,表示第二把钥匙；
                      if(s.key & key)//按位于运算，当有对应的钥匙时，等式成立；才能打开门
                      {
                           vis[s.x][s.y][s.key]=1;
                           s.step+=1;
                           Q.push(s);
                          cout<<s.x<<" "<<s.y<<"key:"<<s.key<<endl;
                      }
                 }
                 if(g[s.x][s.y]>='a' && g[s.x][s.y]<='j')
                 {
                       int key=1<<(g[s.x][s.y]-'a');
                       if(!vis[s.x][s.y][s.key|key])//按位或运算，吸收钥匙；
                       {
                            vis[s.x][s.y][s.key|key]=1;
                            s.step+=1;
                            s.key=s.key|key;
                            Q.push(s);
                            cout<<s.x<<" "<<s.y<<"key:"<<s.key<<endl;
                       }
                 }
             }
         }
    }
}


int main()
{
    while(cin>>n>>m>>t)
    {
        inset();
        bfs();
        cout<<ans<<endl;
    }
    return 0;
}
