#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#define maxn 500005
using namespace std;
int f[105];
int s[maxn];
int n[maxn];
int haxi(int x){
	int t=x%maxn;
	if(t<0){
		t=t+maxn;
	}
	while(n[t]!=0&&s[t]!=x){
		t=(t+1)%maxn;
	}
	return t;
}
int main(){
	int a,b,c,d;
	for(int i=1;i<=100;i++){
		f[i]=i*i;
	}
	while(scanf("%d%d%d%d",&a,&b,&c,&d)!=EOF){
		if((a>0&&b>0&&c>0&&d>0)||(a<0&&b<0&&c<0&&d<0)){
			printf("0\n");
		}
		else{
			int ans=0;
			int p;
			memset(n,0,sizeof(n));
			for(int i=1;i<=100;i++){
				for(int j=1;j<=100;j++){
					int x=a*f[i]+b*f[j];
					p=haxi(x);
					s[p]=x;
					n[p]++;
				}
			}
			for(int i=1;i<=100;i++){
				for(int j=1;j<=100;j++){
					int x=-1*(c*f[i]+d*f[j]);
					p=haxi(x);
					ans+=n[p];
				}
			}
			printf("%d\n",ans*16);
		}
	}
	return 0;
}
