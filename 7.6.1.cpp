#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#define inf 0f3x3x3x3x
#define maxn 
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int A,B;
		scanf("%d%d",&A,&B);
		int a=min(A,B);
		int b=max(A,B);
		int x;
		while(b!=0){
			x=a%b;
			a=b;
			b=x;
		}
		printf("%d\n",a);
	}
}
