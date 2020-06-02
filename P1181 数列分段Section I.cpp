#include<cstdio>
#include<string.h>
#include<iostream>
#include<algorithm>
#define maxn 100005
using namespace std;
int n[maxn];
int main(){
	int N;
	scanf("%d",&N);
	int M;
	scanf("%d",&M);
	for(int i=0;i<N;i++){
		scanf("%d",&n[i]); 
	}
	sort(n,n+N);
	int i=0,j=N-1;
	int sum=0;
	int pre=0;
	while(i!=j){
		if(n[i]+n[j]<=M){
			int pre=n[i]+n[j];
			for(int a=i+1;i<N;i++){
				if(pre+n[a]<=M){
					continue;
				}else{
					sum++;
					i=a-1;
					j--;
					break;
				}
			}
		}else{
			pre=0;
			sum++;
			j--;
		}
	}
	if(n[i]!=0){
		sum++;
	}
	printf("%d\n",sum);
	return 0;
}
