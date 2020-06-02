#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn 105
using namespace std;
int num[maxn];
int n[maxn];
int one(int x){
	int a=x;
	int r;
	int cnt=0;
	while(a!=0){
		r=a%2;
		a=a/2;
		if(r==1){
			n[cnt]+=r;
		}
		cnt++;
	}
	return cnt;
}
int main(){
	int m;
	while(scanf("%d",&m)!=EOF&&m){
		int max_1=0;
		int a;
		memset(n,0,sizeof(n));
		int ans=0;
		for(int i=1;i<=m;i++){
			scanf("%d",&a);
			num[i]=a;
			int l=one(a);
			ans=ans^a;
			if(max_1<l){
				max_1=l;
			}
		}
		if(ans==0){
			printf("0\n");
		}else{
			for(int i=max_1-1;i>=0;i--){
				if(n[i]%2!=0){
					printf("%d\n",n[i]);
					break;
				}
			}
		}
	}
	return 0;
} 
