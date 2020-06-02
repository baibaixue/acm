#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#define maxn 505
using namespace std;
int A[maxn],B[maxn];
int link[maxn][maxn];
int l[maxn];
int m,n;
int find(int x){
	for(int i=1;i<=n;i++){
		if(link[x][i]!=0&&B[i]==0){
			B[i]=1;
			if(A[i]==0||find(A[i])){
				A[i]=x;
				return 1;
			}
		}
	}
	return 0;
}
int SUM(){
	int sum=0;
	for(int i=1;i<=m;i++){
		memset(B,0,sizeof(B));
		if(find(i)){				
			sum++;
		}
	}
	return sum;
}
int main(){
	int k;
	int T=1; 
	while(scanf("%d%d%d",&n,&m,&k)!=EOF&&n){
		memset(A,0,sizeof(A));
		memset(B,0,sizeof(B));
		memset(link,0,sizeof(link));
		for(int i=0;i<k;i++){
			int c,a,b;
			scanf("%d%d",&a,&b);
			link[a][b]=1;
		}
		int ans=SUM();
		int res=0;
		//printf("\n");
		for(int i=1;i<=ans;i++){
			l[A[i]]=i;
		}
//		for(int i=1;i<=m;i++){
//			printf("%d %d\n",i,l[i]);
//		}
		
		for(int i=1;i<=ans;i++){
			memset(A,0,sizeof(A));
			link[i][l[i]]=0;
			if(ans!=SUM()){
				res++;
			}
			link[i][l[i]]=1;
		}
		printf("Board %d have %d important blanks for %d chessmen.\n",T++,res,ans);
	}
} 
