#include<algorithm>
#include<cstdio>
#include<iostream>
#include<string.h>
#include<queue>
#include<stack>
#define maxn 1005
using namespace std;
int tree[maxn];
int visit[maxn];
int post(int n){
	stack<int> Q;
	int k=1;
	Q.push(k);
	int a=n;
	while(!Q.empty()){
		k=Q.top();
		if(visit[2*k]==1&&visit[2*k+1]==1){
			printf("%d",tree[k]);
			visit[k]=1;
			n--;
			if(n!=0){
				printf(" ");
			}else{
				printf("\n");
			}
			Q.pop();
		}
		else if(2*k<a){
			Q.push(2*k+1);
			Q.push(2*k);
		}else if(2*k>n){
			printf("%d",tree[k]);
			visit[k]=1;
			n--;
			if(n!=0){
				printf(" ");
			}else{
				printf("\n");
			}
			Q.pop();
		}
	}
	return 0;
}
int main(){
	int n;
	scanf("%d",&n);
	memset(visit,0,sizeof(visit));
	stack<int> s;
	int k=1;
	s.push(k);
	scanf("%d",&tree[k]);
	visit[k]=1;
	while(!s.empty()){
		k=s.top();
		if(visit[2*k]==1&&visit[2*k+1]==1){
			s.pop();
			continue;
		}
		if(visit[2*k]==1&&visit[2*k+1]==0){
			visit[2*k+1]=1;
			scanf("%d",&tree[2*k+1]);
			s.push(2*k+1);
			continue;
		}
		if(k*2<n){
			scanf("%d",&tree[2*k]);
			visit[2*k]=1;
			s.push(2*k);
		}else{
			s.pop();
		}
	}
//	for(int i=1;i<=n;i++){
//		printf("%d ",tree[i]);
//	}
	int is_search=1;
	for(int i=1;i<=n/2;i++){
		if(!(tree[2*i]<=tree[i]&&tree[i*2+1]>=tree[i])){
			is_search=0;
			break;
		}
	}
	int is_mirror=1;
	for(int i=1;i<n/2;i++){
		if(!(tree[2*i]>=tree[i]&&tree[i*2+1]<=tree[i])){
			is_mirror=0;
			break;
		}
	}
	if(is_search||is_mirror){
		printf("YES\n");
		memset(visit,0,sizeof(visit));
		post(n);
	}else{
		printf("N0\n");
	}
} 
