#include<cstdio>
#include<algorithm>
#include<iostream>
#include<string.h>
#define maxn 1005
using namespace std; 
int s[maxn];
int e[maxn];
int main(){
	int N;
	scanf("%d",&N);
	while(N--){
		int h,m;
		int a;
		char c;
		for(int i=0;i<maxn;i++){
			s[i]=-1;
			e[i]=-1;
		}
		int all_time=0;
		int book=0;
		while(1){	
			scanf("%d",&a);
			getchar();
			scanf("%c",&c);
			scanf("%2d:%2d",&h,&m);
			if(a==0){
				break;
			}else{
				if(s[a]!=-1&&e[a]!=-1){
					book++;
					all_time+=e[a]-s[a];
					e[a]=-1;
					s[a]=-1;
				}
				if(c=='S'){
					s[a]=h*60+m;
				}else if(c=='E'&&s[a]!=-1){
					e[a]=h*60+m;
				}
			}
		}
		for(int i=0;i<maxn;i++){
			if(s[i]!=-1&&e[i]!=-1){
				all_time+=e[i]-s[i];
				book++;
			}
		}
		int ans=0;
		if(book!=0){
			ans=(all_time*1.0/book+0.5);
		}
		printf("%d %d\n",book,ans);
	}
	return 0;
}
