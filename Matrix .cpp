#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn 1010 
using namespace std;
int a[maxn][maxn],c[maxn][maxn];
int n;
int lowbit(int x){
	return x&(-x);
}
int sum(int x,int y){
	int sum=0;
	for(int i=x;i>0;i-=lowbit(i)){
		for(int j=y;j>0;j-=lowbit(j)){
			sum+=c[i][j];
		}
	}
	return sum;
}
void insert(int x,int y,int z){
	for(int i=x;i<=n;i+=lowbit(i)){
		for(int j=y;j<=n;j+=lowbit(j)){
			c[i][j]+=z;
		}
	}
}
int main(){
	int t,T=0;
	scanf("%d",&t);
	while(t--){
		memset(a,0,sizeof(a));
		memset(c,0,sizeof(c));
		int q;
		scanf("%d%d",&n,&q);
		for(int i=0;i<q;i++){
			char cc;
			getchar();
			scanf("%c",&cc);
			if(cc=='C'){
				int x1,y1,x2,y2;
				scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
				insert(x1,y1,1);
				insert(x1,y2+1,1);
				insert(x2+1,y1,1);
				insert(x2+1,y2+1,1);
			}
			if(cc=='Q'){
				int x,y;
				scanf("%d%d",&x,&y);
				int ans=sum(x,y);
				if(ans%2==0){
					printf("0\n");
				}else{
					printf("1\n");
				}
			}
//			for(int i=1;i<=n;i++){
//				for(int j=1;j<=n;j++){
//					printf("%d ",sum(i,j)-sum(i-1,j-1));
//				}
//				printf("\n");
//			}
		}
		if(t!=0){
			printf("\n");
		}
	}
	return 0;
}
