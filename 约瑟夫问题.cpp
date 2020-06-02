#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int j2(int n,int m){
	int f=0;
	for(int i=0;i<n;i++){
		f=(f+m)%(i+1);
	}
	return f;
}
int j1(int n,int m){
	if(n>m){
		int res=j1(n-n/m,m);
		if(res<n%m){
			res=res+n-n%m;
		}
		else{
			res=res+(res-n%m)/(m-1)+m*(int)(n/m)-n;
		}
		return res;
	}
	else{
		return j2(n,m);
	}
}

int main(){
	int N;
	while(scanf("%d",&N)!=EOF){
		if(N==1){
			printf("1\n");
		}else
		{
			int ans=j1(N,3);
//			if(ans==0){
//				ans=N;
//			}
			printf("%d\n",ans+1);
		}
		
	}
} 
