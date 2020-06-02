#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<cmath>
using namespace std;
char map[10][10];
//int visit[10][10];
int M[10][10];
int steps[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int sx,sy;
int ex,ey;
int t;
int escape;
int n,m;
int cnt;
void print(){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			printf("%c",map[i][j]);
		}
		printf("\n");
	}
}
void dfs(int sa,int sb,int cnt){
	if(cnt==t&&sa==ex&&sb==ey){
		escape=1;
	}
	if(escape==1){
		return ;
	}
	if(sa<0||sb<0||sa>=n||sb>=m){
		return ;
		}
	for(int i=0;i<4;i++){
		int n_sa=sa+steps[i][0];
		int n_sb=sb+steps[i][1];
		if(map[n_sa][n_sb]!='X'){
			map[n_sa][n_sb]='X';
			//print();
			//cout<<"\n";
			dfs(n_sa,n_sb,cnt+1);
			map[n_sa][n_sb]='.';
		}
	}
	return ;
}
int main(){
	while(scanf("%d%d%d",&n,&m,&t)!=EOF&&(n||m||t)){
		getchar();
	//	memset(visit,0,sizeof(visit));
		memset(M,0,sizeof(M));
		int r=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				scanf("%c",&map[i][j]);
				if(map[i][j]=='S'){
					sx=i;sy=j;
				}if(map[i][j]=='D'){
					ex=i;ey=j;
				}
				if(map[i][j]=='.'){
					r++;
				}
				if((i%2==0&&j%2==0)||(i%2==1&&j%2==1)){
					M[i][j]=1;
				}else{
					M[i][j]=0;
				}
				//cout<<map[i][j]<<" ";
				//cout<<M[i][j]<<" ";
			}
			getchar();
			//cout<<"\n"; 
		}
		//print();
		//cout<<"\n";
		if((abs(sx+sy-ex-ey)-t)%2!=0&&t<=r+1){
			printf("NO\n");
		}else{
			cnt=0;escape=0;
			map[sx][sy]='X';
			dfs(sx,sy,cnt);
			if(escape==1){
				printf("YES\n");
			}else{
				printf("NO\n");
			}
		}
	}
	return 0;
}
