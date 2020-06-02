#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#define maxn 1005
#define inf 0x3f3f3f3f
using namespace std;
char name[maxn][30];
int edge[maxn][maxn];
int broke[maxn];
int num=0;
int id_road(char* s){
	for(int i=0;i<num;i++){
		if(strcmp(s,name[i])==0){
			return i;
		}
	}
	strcpy(name[num],s);
	num++;
	return num-1;
}
int main(){
	int N,C,R;
	int t=0;
	while(scanf("%d%d%d",&N,&C,&R)!=EOF&&(N+C+R)){
		t++;
		memset(name,0,sizeof(name));
		memset(edge,inf,sizeof(edge));
		memset(broke,0,sizeof(broke));
		for(int i=0;i<maxn;i++){
			edge[i][i]=0;
		}
		scanf("%s",name[0]);
		for(int i=1;i<=C;i++){
			scanf("%s",name[i]);
			broke[i]=id_road(name[i]);
		}
		for(int i=0;i<R;i++){
			char namea[45];
			char road[45];
			char nameb[45];
			cin>>namea>>road>>nameb;
			int a=id_road(namea);
			int b=id_road(nameb);
//			scanf("%s",namea);
//			scanf("%s",road);
//			scanf("%s",nameb);
			int d=0;
			for(int i=0;i<strlen(road);i++){
					if(road[i]>='0'&&road[i]<='9'){
						d=d*10+road[i]-'0';
					}
				}
			if(road[0]=='<'){
				edge[b][a]=min(d,edge[b][a]);
			}if(road[strlen(road)-1]=='>'){
				edge[a][b]=min(d,edge[a][b]);
			}
		}
		int ans=0;
		for(int k=0;k<num;k++){
			for(int i=0;i<num;i++){
				if(edge[i][k]!=inf){
					for(int j=0;j<num;j++){
						edge[i][j]=min(edge[i][j],edge[i][k]+edge[k][j]); 
					}
				}
				
			}
		}
		for(int i=1;i<=C;i++){
			ans+=edge[0][broke[i]];
			ans+=edge[broke[i]][0];
		}
		printf("%d. %d\n",t,ans);
	}
	return 0;
} 
