
#include<iostream>
#include<string.h>
using namespace std;
char map[5][5];
int aa[5][5] , bb[5][5] , cc[5][5];
int pp[20], vis[20];
int n;
int find_match(int u , int b)
{
    for(int i=1;i<=b;i++)
    {
        if(cc[u][i]==1 && vis[i]==0)
        {
            vis[i]=1;
            if(pp[20+i]==0 || find_match(pp[20+i] , b))
            {
                pp[20+i] = u; pp[u]=i;  
                return 1;
            }
        }
    }
    return 0;
}
int find_path(int a  , int b)
{
    int match = 0;
    memset(pp,0 ,sizeof(pp));
    for(int i=1;i<=a;i++)
    {
        if(pp[i]==0)
        {
             memset(vis,0,sizeof(vis));
             match+= find_match(i,b);  
        }
    }
    return match;
}
int main()
{
    while(scanf("%d",&n)!=EOF && n)
    {
         memset(aa,0,sizeof(aa));
         memset(bb,0,sizeof(bb));
         memset(cc,0,sizeof(cc));
         for(int i=1;i<=n;i++)   scanf("%s",map[i]);
        
         //以“行”建图 
         int a=1 , flag = 0;
         for(int i=1;i<=n;i++)
         {
              for(int j=0;j<n;j++)
              {
                  while(map[i][j]=='.'&&j<n)  flag=1 , aa[i][j+1]=a , j++;
                  if(flag==1) a++ , j--; flag=0; 
                 /* while(map[i][j]=='X'&&j<n)
                  {
                      if(flag==0) a++ , flag=1;  j++;
                  }
                  if(map[i][j]=='\0') 
                  {if(flag==0) flag=1 ,a++;  j++;}*/
              }
         }/* cout<<"a== "<<a<<endl;
         for(int i=1;i<=n;i++)
         {
                 for(int j=1;j<=n;j++) cout<<aa[i][j]<<"  "; cout<<endl;
         }*/
         //以”列“建图 
         int b=1;
         for(int i=1;i<=n;i++)
         {
              for(int j=0;j<n;j++)
              {
                   int t=i;
                   while(map[t][j]=='.'&&t<=n&&bb[t][j+1]==0) { flag=1 , bb[t][j+1]=b , t++;}
                   if(flag==1) b++ ; flag = 0;
              }
         }//cout<<"b= "<<b<<endl;
         // 建”边 “ 
         for(int i=1;i<=n;i++)
         {
             for(int j=1;j<=n;j++)
             {
                  if(map[i][j-1]=='.')  cc[aa[i][j]][bb[i][j]] = cc[bb[i][j]][aa[i][j]] = 1;
             }
         }
         /*for(int i=1;i<=n;i++)
         {
                 for(int j=1;j<=n;j++) cout<<bb[i][j]<<"  "; cout<<endl;
         }*/
         printf("%d\n",find_path(a-1 ,b-1));
    }
    return 0;
}

