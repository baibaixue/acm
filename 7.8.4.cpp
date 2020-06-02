#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath> 
#define maxn 100005 
#define inf 0x3f3f3f3f
#define mod 1000000007
using namespace std;
long long modd[maxn];
int main(){
	memset(modd,0,sizeof(modd));
	modd[0]=1;
	modd[1]=1;
	for(int i=2;i<=100000;i++){
		modd[i]=(modd[i-1]*i)%mod;
		printf("%lld\n",modd[i]);
	}
	//printf("%lld",modd[100000]);
}
