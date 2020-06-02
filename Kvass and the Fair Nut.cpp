#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#define maxn 1005 
using namespace std;
long long n[maxn];
int main(){
	int N;
	long long s;
	while(scanf("%d",&N)!=EOF){
		cin>>s;
		for(int i=0;i<N;i++){
			cin>>n[i];
		}
		sort(n,n+N);
		long long ans=n[0];
		long long sum=0;
		for(int i=1;i<N;i++){
			sum+=n[i]-n[0];
		}
		if(sum>=s){
			cout<<ans<<endl;
		}else if(sum+n[0]*N<s){
			cout<<-1<<endl;
		}else{
			if((s-sum)%N!=0){
				ans-=(s-sum)/N+1;
			}else{
				ans-=(s-sum)/N;	
				}
			cout<<ans<<endl;
		}
	}
	return 0;
}
