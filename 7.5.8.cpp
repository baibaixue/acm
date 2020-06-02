#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#define maxn  200005
using namespace std;
struct node{
	long long x,y;
};
node dot[maxn];
bool cmp(node a,node b){
	return a.x<b.x;
}
node ans[maxn];
int main(){
	int T;
	scanf("%d",&T);
	
	while(T--){
		int n;
		scanf("%d",&n);
		long long m_x=0;
		long long m_y=0;
		node X,Y; 
		for(int i=0;i<n;i++){
			scanf("%lld%lld",&dot[i].x,&dot[i].y);
			if(dot[i].x>m_x){
				m_x=dot[i].x;
				X=dot[i];
			}else if(dot[i].x==m_x){
				if(dot[i].y>X.y){
					X=dot[i];
				}
			}
			if(dot[i].y>m_y){
				m_y=dot[i].y;
				Y=dot[i];
			}else if(dot[i].y==m_y){
				if(dot[i].x>Y.x){
					Y=dot[i];
				}
			}
		}
		sort(dot,dot+n,cmp);
		int count=0;
		for(int i=n-1;i>=0;i--){
			if(dot[i].y>=X.y){
				ans[count++]=dot[i];
				X=dot[i];
			}
		}
		for(int i=count-1;i>=0;i--){
			printf("%lld %lld\n",ans[i].x,ans[i].y);
		}
	}
}
