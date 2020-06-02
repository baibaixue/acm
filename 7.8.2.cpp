#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath> 
#define maxn 205
#define inf 0x3f3f3f3f
using namespace std;
char m[maxn][maxn];
//int c[30];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
	//	memset(c,0,sizeof(c));
		int w,h;
		scanf("%d%d",&w,&h);
		getchar();
		for(int i=0;i<w;i++){
			for(int j=0;j<h;j++){
				scanf("%c",&m[i][j]);
				//c[m[i][j]-'a']++;
			}
			getchar();
		}
	//	int t=0;
		//for(int i=0;i<26;i++){
	//		if(c[i]==1){
	//			t=1;
		//		printf("%d\n",max(w,h));
	//			break;
	//		}
	//	}
	//	if(t!=1){
			int ans=0;
			for(int i=1;i<=max(w,h);i++){
				int temp=1;
				for(int j=0;j<w;j++){
					for(int k=0;k<h;k++){
						if(m[j%i][k%i]!=m[j][k]){
							temp=0;
							break;
						}
					}
					if(temp==0){
						break;
					}
				}
				if(temp==1){
					ans=i;
					break;
				}
			}
		//	if(ans==0){
		//		ans=max(w,h);
		//	}
			printf("%d\n",ans);
	//	}
	}
}

