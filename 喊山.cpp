#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn 10005
using namespace std;
int N[maxn];
int M[maxn];
int cnt;
int finda(int a){
	int r=N[a];
	while(r!=N[r]){
		r=N[r];
		cnt++;
	}
	return r;
}
int findb(int a){
	int r=M[a];
	while(r!=M[r]){
		r=M[r];
		cnt++; 
	}
	return r;
}
void hebing (int a,int b){
	int xa=finda(a);
	int ya=finda(b);
	if(xa!=ya){
		N[b]=a;
	}
	int xb=findb(a);
	int yb=findb(b);
	if(xb!=yb){
		M[a]=b;
	}
}
int main(){
	int n,m,k;
	while(scanf("%d%d%d",&n,&m,&k)!=EOF){
		cnt=0;
		for(int i=0;i<=n;i++){
			N[i]=i;
			M[i]=i;
		}
		for(int i=1;i<=m;i++){
			int a,b;
			scanf("%d%d",&a,&b);
//			if(a>b){
//				swap(a,b);
//			}
			hebing(a,b);
		}
		for(int i=1;i<=k;i++){
			int x;
			cnt=0;
			scanf("%d",&x);
			int ca,cb;
			int A=finda(x);
			ca=cnt;
			cnt=0;
			int B=findb(x);
			cb=cnt;
			cnt=0;
			if(A==x&&B==x){
				printf("0\n");
			}
			else{
				if(ca<cb){
					printf("%d\n",B);
				}
				if(ca>cb){
					printf("%d\n",A);
				}else if(ca==cb){
					printf("%d\n",A);
				}
			}
		}
	}
	return 0;
}
