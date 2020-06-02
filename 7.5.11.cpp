#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int a;int b;
		scanf("%d%d",&a,&b);
		printf("%.3lf\n",(a)*1.0/(a+b));
	}
}
