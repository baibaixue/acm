#include<cstdio>
#include<queue>
#include<stack>
#include<iostream>
#include<cstring>
using namespace std;
int step[8][2]={{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
int steps[8][8];
int ans[8][8];
int N=5;
bool is_ok(int x,int y)
{
	if(x<0||y<0||x>=N||y>=N){
		return false;
	}else if(steps[x][y]!=0){
		return false;
	}else{
		return true;
	} 	
}
void print_broad()
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			printf("%3d ",steps[i][j]);
		}
		printf("\n");
	} 
	printf("\n");
	return ;
}
int k=0;
void dfs(int count,int x,int y)
{
	print_broad();
	if(count>=N*N){
		k=1;
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				ans[i][j]=steps[i][j];
			}
		}
	}
	if(k==1){
		return ;
	}
	 
	for(int i=0;i<8;i++){
		steps[x][y]=count;
		
		if(is_ok(x+step[i][0],y+step[i][1]))
		{
			dfs(count+1,x+step[i][0],y+step[i][1]);
			
		}
		steps[x][y]=0;
	}
}

int main()
{
	int x,y;
	while(scanf("%d%d",&x,&y)!=EOF){//³õÊ¼×ø±ê
		k=0;
		dfs(1,x,y);
		memset(ans,0,sizeof(ans));
		memset(steps,0,sizeof(steps));
		if(k==0)
		{
			printf("no route.\n");
		}else{
			for(int i=0;i<N;i++){
				for(int j=0;j<N;j++){
					printf("%3d ",ans[i][j]);
				}
				printf("\n");
			}
		}
		
	}
	return 0;
}



