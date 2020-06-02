#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
long long num[4];
	long long judge(long long n){
    memset(num,0,sizeof(num));
    while(n%2==0){
        num[0]++;
        n=n/2;
    }
    while(n%3==0){
        num[1]++;
        n=n/3;
    }
    while(n%5==0){
        num[2]++;
        n=n/5;
    }
    while(n%7==0){
        num[3]++;
        n=n/7;
    }
    long long ans=1;
    for(int i=0;i<4;i++){
        ans=ans*(num[i]+1);
    }
    return ans;
}
int main(){
	long long n;
	while(scanf("%lld",&n)!=EOF&&n){
        printf("%lld\n",judge(n));
	}
}
