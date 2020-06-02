#include<cstdio>
#include<iostream>
#include<string.h>
#include<algorithm>
#define maxn 100005
using namespace std;
int N[maxn];
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		memset(N,0,sizeof(N));
		getchar();
		int l=0;
		for(int i=1;i<=n;i++){
			char w[15];
			int k;
			scanf("%s",w);
			if(strcmp(w,"Pop")==0){
				if(l>0){
					printf("%d\n",N[l]);
					
					N[l]=0;
					l--;
				}else{
					printf("Invalid\n");
				}
			}
			if(strcmp(w,"PeekMedian")==0){
				int mid;
				if(l%2==0){
					mid=l/2;
				}else{
					mid=(l+1)/2;
				}
				if(l<=0){
					printf("Invalid\n");
				}else{
					printf("%d\n",N[l-mid+1]);
				}
			}
			if(strcmp(w,"Push")==0){
				scanf("%d",&k);
				l++;
				N[l]=k;
					
			}
		}
	}
	return 0;
}
