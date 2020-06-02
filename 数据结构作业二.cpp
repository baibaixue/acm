//马踏棋盘 超时 
#include<cstdio>
#include<queue>
#include<stack>
#include<iostream>
#include<cstring>
using namespace std;
int step[8][2]={{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
struct node{
	int curx;
	int cury;
	int steps[8][8];
	int curstep;
};
int N=8;
node ans;
void print_broad(node T)
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			printf("%3d ",T.steps[i][j]);
		}
		printf("\n");
	} 
	printf("\n");
	return ;
}
bool bfs(int x,int y){
	node now;
	now.curx=x;
	now.cury=y;
	now.curstep=1;
	memset(now.steps,0,sizeof(now.steps));
	now.steps[now.curx][now.cury]=now.curstep;
	stack<node> S;
	S.push(now);
	while(!S.empty())
	{
		now=S.top();
		//print_broad(now);
		S.pop();
		if(now.curstep==N*N){
			ans=now;
			return true;
		}
		node next;
		for(int k=0;k<8;k++){
			next.curx=now.curx+step[k][0];
			next.cury=now.cury+step[k][1];
			next.curstep=now.curstep+1;
			if(next.curx>=0&&next.cury>=0&&next.curx<N&&next.cury<N)
			{
				if(now.steps[next.curx][next.cury]==0)
				{
					for (int i=0;i<N;i++)
					{
						for(int j=0;j<N;j++)
						{
							next.steps[i][j]=now.steps[i][j];
						}
					}
					next.steps[next.curx][next.cury]=next.curstep; 
					//print_broad(next);
					S.push(next);
				}
			}
		}
	}
	return false;
}
int main(){
	int x,y;
	while(scanf("%d%d",&x,&y)!=EOF){//初始坐标
		bool result = bfs(x,y);
		if(result==true){
			for(int i=0;i<N;i++){
				for(int j=0;j<N;j++){
					printf("%d ",ans.steps[i][j]);
				}
				printf("\n");
			} 
		}
		else printf("false\n");
	}
	return 0;
}
