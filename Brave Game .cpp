#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn 1005
using namespace std;
int s[maxn];
int main(){
	int c;
	scanf("%d",&c);
	while(c--){
		int n,m;
		scanf("%d%d",&n,&m);
		int k=m;
		s[0]=0;
		for(int i=1;i<=n;i++){
			if(k!=0){
				s[i]=1;
				k--;	
			}else{
				s[i]=0;
				k=m;
			}
		}
		if(s[n]==1){
			printf("first\n");
		}else{
			printf("second\n");
		}
	}
	return 0;
} 
