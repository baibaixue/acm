#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <cstring>
#include <cmath>
#define INF 0x3f3f3f
#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;

int bing[1010];

int find(int x){
    while(x!=bing[x])
        x=bing[x];
    return x;
}

void Merge(int x,int y){
    int fx=find(x);
    int fy=find(y);
    if(fx!=fy){
        bing[max(fx,fy)]=min(fx,fy);
    }
}


int num[1010];

int main(){
    int n,m;
    int a,b;
    while(scanf("%d%d",&n,&m)!=EOF){
        int amount=0,cnt=0;
        for(int i=0;i<=n;i++) bing[i]=i;
        for(int i=1;i<=m;i++){
            scanf("%d%d",&a,&b);
            Merge(a,b);
        }
        for(int i=1;i<=n;i++){
            if(bing[i]!=bing[0]){
                num[amount++]=i;
                cnt++;
            }
        }
        printf("%d\n",cnt);
        for(int i=0;i<amount;i++){
            if(i!=0) printf(" ");
            printf("%d",num[i]);
        }
        if(cnt!=0) printf("\n");
    }
}



