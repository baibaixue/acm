#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<string.h>
#include<vector>
#define maxn 100005
using namespace std;
struct node{
	bool a;
	char s[10]; 
	int pre;
}N[maxn];
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;i++){
			N[i].a=false;
			memset(N[i].s,0,sizeof(N[i].s));
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			getchar();
			scanf("%s",N[i].s);
			if(N[i].s[0]=='d'){
				N[i].a=!N[i].a;
				if(N[i].a==true){
					ans++;
				}else{
					ans--;
				}
			}
			if(N[i].s[0]=='c'){
				N[i].a=!N[i].a;
				if(N[i].a==true){
					ans++;
				}else{
					ans--;
				}
				int a,b;
				scanf("%d",&a);
				N[i].pre=a;
				b=i;
				while(N[b].s[0]=='c'){
					if(N[N[b].pre].s[0]=='c'&&N[N[b].pre].a==true){
						N[N[b].pre].a=!N[N[b].pre].a;
						if(N[N[b].pre].a==true){
							ans++;
						}else{
							ans--;
						}
					}else if(N[N[b].pre].s[0]=='d'){
						N[N[b].pre].a=!N[N[b].pre].a;
						if(N[N[b].pre].a==true){
							ans++;
						}else{
							ans--;
						}
					}
					b=N[b].pre;
				}
			}
		}
		printf("%d\n",ans);
		for(int i=1;i<=n;i++){
			if(N[i].a==true){
				printf("%d",i);
				ans--;
				if(ans!=0){
					printf(" ");
				}
			}
		}
		printf("\n");
	}
	return 0;
}
