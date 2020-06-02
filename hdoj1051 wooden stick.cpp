#include<cstdio>
#include<algorithm>
#include<iostream>
#define maxn 5000+50
using namespace std;
struct stick{
	int l,w;
}n[maxn],m[maxn];
//int cmp1(stick a,stick b){
//	return a.l<=b.l;
//}
int cmp2(stick a,stick b){
	if(a.l!=b.l){
		return a.l<b.l;
	}
	return a.w<b.w;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int N;
		scanf("%d",&N);
		for(int i=0;i<N;i++){
			scanf("%d%d",&n[i].l,&n[i].w);
		}
		sort(n,n+N,cmp2);
//		for(int i=0;i<N;i++){
//			sort(n,n+i,cmp2);
//		}
		m[0].l=n[0].l;m[0].w=n[0].w;
		int count=0;
		for(;;){
			for(int i=count+1;i<N;i++){
				if(n[i].l>=m[count].l&&n[i].w>=m[count].w){
					count++;
					m[count].l=n[i].l;
					m[count].w=n[i].w;
					n[i].l=0;n[i].w=0;
				}
			}
			sort(n,n+N,cmp2);
			count++;
			if(count!=N){
				m[count].l=n[count].l;
				m[count].w=n[count].w;
			}
			else{
				break;
			}
		}
//		for(int i=0;i<N;i++){
//			printf("m[%d].l=%d m[%d].w=%d\n",i,m[i].l,i,m[i].w);
//		}
		int ans=1;
		for(int i=1;i<N;i++){
			if(m[i].l<m[i-1].l||m[i].w<m[i-1].w){
				ans++; 
			}
		}
		cout<<ans<<"\n";
	}
} 
