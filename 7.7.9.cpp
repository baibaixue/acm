#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath> 
#define maxn 100
#define inf 0x3f3f3f3f
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		int solve=0;
		int wa=0;
		string str;
		for(int i=0;i<n;i++){
			cin>>str;
			if(solve==0){
				if(str=="WA"){
					wa++;
				}else{
					solve=1;
				}
			}
		}
		if(solve==0){
			printf("-");
			if(wa>0){
				printf("%d",wa);
			}
		}else{
			printf("+");
			if(wa>0){
				printf("%d",wa);
			}
		}
		printf("\n");
	}
}
