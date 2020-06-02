#include <iostream>
#include <math.h>
using namespace std;

#define base 10
#define REP(i,n) for(int i=0;i<(n);i++)
int F[1<<base],G[1<<base];
// �����ö����Ʊ�ʾ base��ʾ�������10��Ԫ��

int Cal(int x){ // ���� |x|
    int sum=0;
    while(x) sum+=(x&1),x/=2;
    return sum;
}

int main(){
    REP(S,1<<base) F[S]=Cal(S); // ������ʼ��F(S)
    REP(S,1<<base){   // ����G(S)
        G[S]=0;
        for(int X=S;X;X=(X-1)&S) G[S]+=F[X]; //��X����S����
    }
    REP(S,1<<base){     // ���㷴�ݵ� F(S)
        F[S]=0;
        for(int X=S;X;X=(X-1)&S)
            F[S]+=(int)pow(-1,Cal(S)-Cal(X))*G[X];
    }
    bool flag=1;    // ��֤һ��
    REP(S,1<<base)
        if(F[S]!=Cal(S)) flag=0;
    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
