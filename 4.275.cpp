#include <iostream>
#include <math.h>
using namespace std;

#define base 10
#define REP(i,n) for(int i=0;i<(n);i++)
int F[1<<base],G[1<<base];
// 集合用二进制表示 base表示集合最多10个元素

int Cal(int x){ // 计算 |x|
    int sum=0;
    while(x) sum+=(x&1),x/=2;
    return sum;
}

int main(){
    REP(S,1<<base) F[S]=Cal(S); // 计算出最开始的F(S)
    REP(S,1<<base){   // 计算G(S)
        G[S]=0;
        for(int X=S;X;X=(X-1)&S) G[S]+=F[X]; //用X遍历S集合
    }
    REP(S,1<<base){     // 计算反演的 F(S)
        F[S]=0;
        for(int X=S;X;X=(X-1)&S)
            F[S]+=(int)pow(-1,Cal(S)-Cal(X))*G[X];
    }
    bool flag=1;    // 验证一下
    REP(S,1<<base)
        if(F[S]!=Cal(S)) flag=0;
    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
