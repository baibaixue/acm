#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#define maxn 
#define inf 0x3f3f3f3f
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int sx,sy,ex,ey,px,py;
		scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
		scanf("%d%d",&px,&py);
		if((px==sx&&py==sy)||(px==ex&&py==ey)){
			printf("YES\n");
		}else{
			
			if(((ex-sx)*(py-sy))==((ey-sy)*(px-sx))&&(ex-sx)*(px-sx)>=0&&(ey-sy)*(py-sy)>=0){
				printf("YES\n");
			}else{
				printf("NO\n");
			}
		}
		
	}
}
