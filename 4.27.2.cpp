#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#define inf 0x3f3f3f3f
#define maxn 100005
using namespace std;
int N[maxn];
int mm;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		memset(N,0,sizeof(N));
		scanf("%d",&n);
		mm=0;
		N[0]=0;
		int t=0;
		int cnt=0;
		for(int i=1;i<=n;i++){
			int c;
			scanf("%d",&c);
			if(i==1){
				N[t]=c;
				t++;
			}else{
				if(c>=N[t-1]){
					N[t]=c;
					t++;
				}else{
					cnt++;
					if(mm<c){
						mm=c;
					}
				}
			}
		}
		for(int i=0;i<t;i++){
			if(mm>N[i]){
				cnt++;
			}else{
				break;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
