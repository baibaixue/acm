#include<cstdio>
#include<cmath>
#include<string.h>
#define maxn 100005
int A[maxn];
//int low_bit(int a){
//	int x=a,r=a%2;
//	int k=0;
//	while(r!=1){
//		r=x%2;
//		x=x/2;
//		k++;
//	}
//	return (int)power(2.0,(double)k);
//}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d%d",&n,&m);
		memset(A,0,sizeof(A));
		for(int i=1;i<=n;i++){
			scanf("%d",&A[i]);
			A[i]=A[i]+A[i-1];
		}
		while(m--){
			int t,l,r;
			scanf("%d%d%d",&t,&l,&r);
			if(t==2){
				printf("%d\n",A[r]-A[l-1]);
			}
		}
	}
	return 0;
} 
