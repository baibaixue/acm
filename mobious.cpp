#include <bits/stdc++.h>
#define LL long long
#define FOR(i,x,y)  for(int i = x;i < y;++ i)
#define IFOR(i,x,y) for(int i = x;i > y;-- i)

using namespace std;

const int maxn = 500050;

int prime[maxn],mu[maxn],cnt[maxn];
int sum[20][maxn];
bool check[maxn];

void Mobius(){
    memset(check,false,sizeof(check));
    mu[1] = 1;
    prime[0] = 0;
    cnt[1] = 0;
    FOR(i,2,maxn){
        if(!check[i]){
            prime[++prime[0]] = i;
            mu[i] = -1;
            cnt[i] = 1;
        }
        FOR(j,1,prime[0]+1){
            if(i*prime[j] >= maxn)  break;
            check[i*prime[j]] = true;
            cnt[i*prime[j]] = cnt[i] + 1;
            if(i % prime[j]){
                mu[i*prime[j]] = -mu[i];
            }
            else{
                mu[i*prime[j]] = 0;
                break;
            }
        }
    }
}

int n,m,p;

void init(){
    Mobius();
    memset(sum,0,sizeof(sum));
    //sum[i][j]表示所有能整除j的质因子个数为i的(x,y)的对数
    FOR(i,1,maxn){
        for(int j = i;j < maxn;j += i){
            sum[cnt[i]][j] += mu[j/i];
        }
    }
    //sum[i][j]表示所有能整除j的质因子个数<=i的(x,y)的对数
    FOR(j,1,maxn){
        FOR(i,1,20){
            sum[i][j] += sum[i-1][j];
        }
    }
    //sum[i][j]表示sum[i][0]+sum[i][1]+...+sum[i][j]的前缀和
    FOR(j,1,maxn){
        FOR(i,0,20){
            sum[i][j] += sum[i][j-1];
        }
    }
}

void work(){
    if(p >= 20) {printf("%I64d\n",(LL)n*(LL)m);return;}
    int mx = min(n,m);
    LL ans = 0;
    for(int i = 1;i <= mx;){
        LL a = n/i,b = m/i;
        LL now = min(n/a,m/b);
        ans += a*b*(sum[p][now]-sum[p][i-1]);
        i = now+1;
    }
    printf("%I64d\n",ans);
}

int main(){
    //freopen("test.in","r",stdin);
    init();
    int T;  scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&m,&p);
        work();
    }
    return 0;
}
